//
//  Exporter.cpp
//  DashboardExporter
//
//  Created by Patrik Hartlén on 2015-04-26.
//  Copyright (c) 2015 Patrik Hartlén. All rights reserved.
//  License BSD-style license
//
//  This file is based on sample code from Hansoft AB
//  See https://github.com/Hansoft/DashboardImageExtractor for more information.
//

#include "HPMSdkCpp.h"

#ifdef _MSC_VER
#include <tchar.h>
#include <conio.h>
#include <windows.h>
#else
#include <sys/time.h>
#include <sys/select.h>
#include <termios.h>
#if defined(__GNUC__)
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <sys/stat.h>
#endif
#endif
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
using namespace HPMSdk;

#ifdef __GNUC__

struct CProcessSemaphore
{
    pthread_cond_t m_Cond;
    pthread_mutex_t m_Mutex;
    int m_Counter;
};

#endif

class HansoftSDKDashboardExporter : public HPMSdkCallbacks
{
public:
    
    HPMSdkSession *m_pSession;
    bool m_bBrokenConnection;
    
    virtual void On_ProcessError(EHPMError _Error)
    {
        HPMString SdkError = HPMSdkSession::ErrorToStr(_Error);
        wstring Error(SdkError.begin(), SdkError.end());
        
        wcout << "On_ProcessError: " << Error << "\r\n";
        m_bBrokenConnection = true;
    }
    
    HPMUInt64 m_NextConnectionAttempt;
#ifdef _MSC_VER
    HANDLE m_ProcessSemaphore;
#elif __GNUC__
    CProcessSemaphore m_ProcessSemaphore;
#endif
    HPMNeedSessionProcessCallbackInfo m_ProcessCallbackInfo;
   
    HPMString m_Server;
    int m_Port;
    HPMString m_Database;
    HPMString m_Username;
    HPMString m_Password;
    HPMString m_Resource;
    vector<int> m_Charts;
    HPMString m_Resolution;
    bool m_json;
    
    HansoftSDKDashboardExporter(string server, int port, string database, string username, string password, string resource, vector<int> charts, string resolution, bool json) :
    m_Server(server), m_Port(port), m_Database(database), m_Username(username), m_Password(password), m_Resource(resource), m_Charts(charts), m_Resolution(resolution), m_json(json)
    {
        m_pSession = NULL;
        m_NextConnectionAttempt = 0;
        m_bBrokenConnection = false;
        // Create the event that will be signaled when the SDK needs processing.
#ifdef _MSC_VER
        m_ProcessSemaphore = CreateSemaphore(NULL, 0, 1, NULL); // Behaves like an auto reset event.
#elif __GNUC__
        pthread_cond_init(&m_ProcessSemaphore.m_Cond, NULL);
        pthread_mutex_init(&m_ProcessSemaphore.m_Mutex, NULL);
        m_ProcessSemaphore.m_Counter = 1;
#endif
    }
    
    ~HansoftSDKDashboardExporter()
    {
#ifdef _MSC_VER
        if (m_ProcessSemaphore)
            CloseHandle(m_ProcessSemaphore);
#elif __GNUC__
        pthread_mutex_destroy(&m_ProcessSemaphore.m_Mutex);
        pthread_cond_destroy(&m_ProcessSemaphore.m_Cond);
#endif
        
        if (m_pSession)
        {
            DestroyConnection();
        }
    }
    
#ifdef __GNUC__
    bool SemWait(int _Timeout)
    {
        time_t Now;
        time(&Now);
        
        timespec Ts;
        Ts.tv_sec = Now;
        Ts.tv_nsec = _Timeout * 1000000;
        
        pthread_mutex_lock(&m_ProcessSemaphore.m_Mutex);
        while (m_ProcessSemaphore.m_Counter == 0)
        {
            if (pthread_cond_timedwait(&m_ProcessSemaphore.m_Cond, &m_ProcessSemaphore.m_Mutex, &Ts) == ETIMEDOUT)
            {
                pthread_mutex_unlock(&m_ProcessSemaphore.m_Mutex);
                return true;
            }
        }
        --m_ProcessSemaphore.m_Counter;
        pthread_mutex_unlock(&m_ProcessSemaphore.m_Mutex);
        return true;
    }
#endif
    
    HPMUInt64 GetTimeSince1970()
    {
#ifdef _MSC_VER
        FILETIME Time;
        GetSystemTimeAsFileTime(&Time);
        
        return (HPMUInt64)((((ULARGE_INTEGER &)Time).QuadPart / 10) - 11644473600000000);
#else
        timeval Time;
        gettimeofday(&Time, NULL);
        return (HPMUInt64)Time.tv_sec * 1000000;
#endif
    }
    
    static void NeedSessionProcessCallback(void *_pSemaphore)
    {
#ifdef _MSC_VER
        ReleaseSemaphore(_pSemaphore, 1, NULL);
#elif __GNUC__
        CProcessSemaphore *pProcessSemaphore = (CProcessSemaphore *)_pSemaphore;
        pthread_mutex_lock(&pProcessSemaphore->m_Mutex);
        ++pProcessSemaphore->m_Counter;
        pthread_cond_signal(&pProcessSemaphore->m_Cond);
        pthread_mutex_unlock(&pProcessSemaphore->m_Mutex);
#endif
    }
    
    bool InitConnection()
    {
        if (m_pSession)
            return true;
        
        HPMUInt64 CurrentTime = GetTimeSince1970();
        if (CurrentTime > m_NextConnectionAttempt)
        {
            m_NextConnectionAttempt = 0;
            
            EHPMSdkDebugMode DebugMode = EHPMSdkDebugMode_Off;
            
#ifdef _MSC_VER
            m_ProcessCallbackInfo.m_pContext = m_ProcessSemaphore;
#elif __GNUC__
            m_ProcessCallbackInfo.m_pContext = &m_ProcessSemaphore;
#endif
            m_ProcessCallbackInfo.m_pCallback = &HansoftSDKDashboardExporter::NeedSessionProcessCallback;
            
            try
            {
                m_pSession = HPMSdkSession::SessionOpen(m_Server, m_Port, m_Database, m_Username, m_Password, this, &m_ProcessCallbackInfo, true, DebugMode, NULL, 0, hpm_str(""), HPMSystemString(), NULL);
            }
            catch (const HPMSdkException &_Error)
            {
                HPMString SdkError = _Error.GetAsString();
                wstring Error(SdkError.begin(), SdkError.end());
                wcout << hpm_str("SessionOpen failed with error:") << Error << hpm_str("\r\n");
                return false;
            }
            catch (const HPMSdkCppException &_Error)
            {
                wcout << hpm_str("SessionOpen failed with error:") << _Error.what() << hpm_str("\r\n");
                return false;
            }
            
            wcout << "Successfully opened session.\r\n";
            m_bBrokenConnection = false;
            
            return true;
        }
        
        return false;
    }
    
    void DestroyConnection()
    {
        m_ChartSubscriptions.clear();
        
        if (m_pSession)
        {
            HPMSdkSession::SessionDestroy(m_pSession);
            m_pSession = NULL;
        }
    }
    
    using HPMSdkCallbacks::On_Callback;
    
    map<HPMUniqueID, HPMDashboardChartSubscription> m_ChartSubscriptions;
    set<HPMUniqueID> m_UpdatedCharts;
    
    template<typename Integer>
    HPMString ToHPMString(Integer Value)
    {
        HPMString ReturnValue;
        
#if HPMCharSize == 1
        ReturnValue = std::to_string(Value);
#else
        ReturnValue = std::to_wstring(Value);
#endif
        
        return ReturnValue;
    }
    
    void On_Callback(const HPMChangeCallbackData_DashboardChartReceive &_Data) override
    {
        m_UpdatedCharts.insert(_Data.m_ChartID);
        wcout << "Chart " << _Data.m_ChartID << " was updated.\r\n";
    }
    
    HPMString GenerateFilename(HPMUniqueID ChartID, HPMString Folder, HPMString Suffix)
    {
        HPMString FileName =
#ifdef _WIN32
        hpm_str(".\\" + Folder + "\\Chart")
#elif __GNUC__
        hpm_str("./" + Folder + "/Chart")
#endif
        + ToHPMString(ChartID.m_ID) + Suffix;
        
        return FileName;
    }
    
    void ExportImageChart(HPMUniqueID ChartID, HPMString ResultSet)
    {
        HPMString ChartRegistryFileName = GenerateFilename(ChartID, hpm_str("IRG"), hpm_str(".irg"));
        HPMString ChartImageFileName = GenerateFilename(ChartID, hpm_str("CHARTS"), hpm_str(".png"));
        
        // Write the result set registry to file
        std::filebuf FileBuffer;
        FileBuffer.open(ChartRegistryFileName.c_str(), std::ios::out);
        std::ostream OutStream(&FileBuffer);
        OutStream << string(ResultSet.begin(), ResultSet.end());
        FileBuffer.close();
        
        HPMString ResultSetToolPath =
#ifdef _MSC_VER
        hpm_str(".\\HPMResultSetTool.exe");
#elif __GNUC__
        hpm_str("./HPMResultSetTool");
#endif
        
        HPMString CommandLine = ResultSetToolPath + hpm_str(" ") + ChartRegistryFileName + hpm_str(" ") + ChartImageFileName + hpm_str(" ") + m_Resolution;
        
#if HPMCharSize == 1
        system(CommandLine.c_str());
#else
        _wsystem(CommandLine.c_str());
#endif
        wcout << "Chart " << ChartID << " was exported as image.\r\n";
    }
    
    void ExportJsonChart(HPMUniqueID ChartID, HPMDashboardChartResultSet ResultSet)
    {
        HPMString ChartJsonFileName = GenerateFilename(ChartID, hpm_str("JSON"), hpm_str(".json"));

        std::filebuf FileBuffer;
        FileBuffer.open(ChartJsonFileName.c_str(), std::ios::out);
        std::ostream OutStream(&FileBuffer);
        
        std::vector<EHPMDashboardChartResultDataType> DimensionTypes;
        std::vector<std::vector<std::string>> DimensionValues;
        for (HPMDashboardChartResultSetElementInfo DimensionInfo : ResultSet.m_Dimensions.m_DimensionInfos)
        {
            DimensionTypes.push_back(DimensionInfo.m_Type);
            DimensionValues.push_back(std::vector<std::string>());
        }
        for (HPMDashboardChartResultSetRow DimensionRow : ResultSet.m_Dimensions.m_Rows)
        {
            for (HPMDashboardChartResultSetValue Value : DimensionRow.m_Values)
            {
                switch (DimensionTypes[Value.m_Index])
                {
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMString:
                    {
                        DimensionValues[Value.m_Index].push_back(m_pSession->VariantDecode_HPMString(Value.m_VariantData));
                        break;
                    }
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMFP64:
                    {
                        std::ostringstream o;
                        o << m_pSession->VariantDecode_HPMFP64(Value.m_VariantData);
                        DimensionValues[Value.m_Index].push_back(o.str());
                        break;
                    }
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMUInt64:
                    {
                        std::ostringstream o;
                        o << m_pSession->VariantDecode_HPMUInt64(Value.m_VariantData);
                        DimensionValues[Value.m_Index].push_back(o.str());
                        break;
                    }
                    default:
                    {
                        DimensionValues[Value.m_Index].push_back("");
                    }
                }
            }
        }
        OutStream << "{";
        std::vector<EHPMDashboardChartResultDataType> MeasureTypes;
        std::vector<std::string> MeasureNames;
        OutStream << "\"series\": [";
        bool first = true;
        for (HPMDashboardChartResultSetElementInfo MeasureInfo : ResultSet.m_Measures.m_MeasureInfos)
        {
            if (first)
                first = false;
            else
                OutStream << ", ";
            MeasureTypes.push_back(MeasureInfo.m_Type);
            HPMString name = m_pSession->LocalizationTranslateString(m_pSession->LocalizationGetDefaultLanguage(), MeasureInfo.m_Name);
            MeasureNames.push_back(name);
            OutStream << "\"" << name << "\"";
        }
        OutStream << "], \r\n";
        OutStream << "\"measures\": {\r\n";
        int index = 0;
        bool firstrow = true;
        for (HPMDashboardChartResultSetRow MeasureRow : ResultSet.m_Measures.m_Rows)
        {
            if (firstrow)
                firstrow = false;
            else
                OutStream << ",\r\n";
            OutStream << "\"" << DimensionValues[0][index++] << "\": ";
            OutStream << "[";
            bool first = true;
            for (HPMDashboardChartResultSetValue Value : MeasureRow.m_Values)
            {
                if (first)
                    first = false;
                else
                    OutStream << ", ";
                switch (MeasureTypes[Value.m_Index])
                {
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMFP64:
                    {
                        OutStream << m_pSession->VariantDecode_HPMFP64(Value.m_VariantData);
                        break;
                    }
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMUInt64:
                    {
                        OutStream << m_pSession->VariantDecode_HPMUInt64(Value.m_VariantData);
                        break;
                    }
                    default:
                    {
                        OutStream << "0";
                    }
                }
            }
            OutStream << "]";
        }
        OutStream << "}\r\n";
        OutStream << "}\r\n";
        FileBuffer.close();

        wcout << "Chart " << ChartID << " was exported as json.\r\n";
    }

    void SubscribeToChart(HPMUniqueID ChartID)
    {
        try
        {
            if (m_ChartSubscriptions.find(ChartID) == m_ChartSubscriptions.end())
                m_ChartSubscriptions[ChartID] = m_pSession->DashboardSubscribeToChart(ChartID);
        }
        catch (HPMSdkException &_Error)
        {
            cout << _Error.GetError();
        }
    }
    
    HPMUniqueID FindChartByName(HPMUniqueID PageID, HPMString Name)
    {
        HPMUniqueEnum Charts = m_pSession->DashboardChartEnum(PageID);
        for (HPMUniqueID ChartID : Charts.m_IDs)
        {
            HPMString ChartName = m_pSession->DashboardChartGetName(ChartID);
            if (ChartName == Name)
                return ChartID;
        }
        return HPMUniqueID();
    }
    
    HPMUniqueID FindPageByName(HPMString Name)
    {
        HPMUniqueEnum Pages = m_pSession->DashboardPageEnum();
        for (HPMUniqueID PageID : Pages.m_IDs)
        {
            HPMString PageName = m_pSession->DashboardPageGetName(PageID);
            if (PageName == Name)
                return PageID;
        }
        return HPMUniqueID();
    }
    
    void Update()
    {
        if (InitConnection())
        {
            try
            {
                if (m_bBrokenConnection)
                {
                    DestroyConnection();
                }
                else
                {
                    set<HPMUniqueID> ExportCharts;

                    HPMUniqueEnum Pages = m_pSession->DashboardPageEnum();
                    
                    for (HPMUniqueID PageID : Pages.m_IDs)
                    {
                        for (HPMUniqueID ChartID : m_pSession->DashboardChartEnum(PageID).m_IDs)
                        {
                            if (find(m_Charts.begin(), m_Charts.end(), ChartID) != m_Charts.end())
                            {
                                ExportCharts.insert(ChartID);
                                SubscribeToChart(ChartID);
                            }
                        }
                    }
                    
                    // wait max 30 seconds before timeout
                    HPMUInt64 timeout = GetTimeSince1970() + 1000000*30;
                    while (!ExportCharts.empty() && GetTimeSince1970() < timeout)
                    {
                        m_pSession->SessionProcess();
                        for (HPMUniqueID ChartID : m_UpdatedCharts)
                        {
                            set<HPMUniqueID>::iterator it = ExportCharts.find(ChartID);
                            if (it != ExportCharts.end())
                                ExportCharts.erase(it);
                        }
                    }
                    
                    if (!m_UpdatedCharts.empty())
                    {
                        for (HPMUniqueID ChartID : m_UpdatedCharts)
                        {
                            if (m_json)
                            {
                                HPMDashboardChartResultSet ResultSet = m_pSession->DashboardSubscriptionGetLastResultSet(m_ChartSubscriptions[ChartID]);
                                ExportJsonChart(ChartID, ResultSet);
                            }
                            else
                            {
                                HPMString ResultSet = m_pSession->DashboardSubscriptionGetLastResultSetAsString(m_ChartSubscriptions[ChartID]);
                                ExportImageChart(ChartID, ResultSet);
                            }
                        }
                    }
                }
            }
            catch (HPMSdkException &_Error)
            {
                HPMString SdkError = _Error.GetAsString();
                wstring Error(SdkError.begin(), SdkError.end());
                wcout << hpm_str("Exception in processing loop: ") << Error << hpm_str("\r\n");
            }
            catch (HPMSdkCppException _Error)
            {
                wcout << hpm_str("Exception in processing loop: ") << _Error.what() << hpm_str("\r\n");
            }
        }
    }
    
    int Run()
    {
        Update();
#ifdef _MSC_VER
        WaitForSingleObjectEx(m_ProcessSemaphore, 100, true);
#elif __GNUC__
        SemWait(100);
#endif
    
        DestroyConnection();
        
        return 0;
    }
};

void Export(string server, int port, string database, string username, string password, string resource, vector<int> charts, string dimensions, bool json)
{
    HansoftSDKDashboardExporter Exporter(server, port, database, username, password, resource, charts, dimensions, json);
    Exporter.Run();
}
