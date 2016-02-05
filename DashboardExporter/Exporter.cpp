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
    
    HPMSdkSession *session_;
    bool broken_connection_;
    
    virtual void On_ProcessError(EHPMError _error) override
    {
        HPMString SdkError = HPMSdkSession::ErrorToStr(_error);
        wstring Error(SdkError.begin(), SdkError.end());
        
        wcout << "On_ProcessError: " << Error << "\r\n";
        broken_connection_ = true;
    }
    
    HPMUInt64 next_connection_attempt_;
#ifdef _MSC_VER
    HANDLE process_semaphore_;
#elif __GNUC__
    CProcessSemaphore process_semaphore_;
#endif
    HPMNeedSessionProcessCallbackInfo process_callback_info_;
   
    HPMString server_;
    int port_;
    HPMString database_;
    HPMString username_;
    HPMString password_;
    HPMString resource_;
    vector<int> charts_;
    HPMString resolution_;
    bool json_;
    
    HansoftSDKDashboardExporter(string server, int port, string database, string username, string password, string resource, vector<int> charts, string resolution, bool json) :
    server_(server), port_(port), database_(database), username_(username), password_(password), resource_(resource), charts_(charts), resolution_(resolution), json_(json)
    {
        session_ = NULL;
        next_connection_attempt_ = 0;
        broken_connection_ = false;
        // Create the event that will be signaled when the SDK needs processing.
#ifdef _MSC_VER
        process_semaphore_ = CreateSemaphore(NULL, 0, 1, NULL); // Behaves like an auto reset event.
#elif __GNUC__
        pthread_cond_init(&process_semaphore_.m_Cond, NULL);
        pthread_mutex_init(&process_semaphore_.m_Mutex, NULL);
        process_semaphore_.m_Counter = 1;
#endif
    }
    
    ~HansoftSDKDashboardExporter()
    {
#ifdef _MSC_VER
        if (process_semaphore_)
            CloseHandle(process_semaphore_);
#elif __GNUC__
        pthread_mutex_destroy(&process_semaphore_.m_Mutex);
        pthread_cond_destroy(&process_semaphore_.m_Cond);
#endif
        
        if (session_)
        {
            DestroyConnection();
        }
    }
    
#ifdef __GNUC__
    bool SemWait(int _timeout)
    {
        time_t Now;
        time(&Now);
        
        timespec Ts;
        Ts.tv_sec = Now;
        Ts.tv_nsec = _timeout * 1000000;
        
        pthread_mutex_lock(&process_semaphore_.m_Mutex);
        while (process_semaphore_.m_Counter == 0)
        {
            if (pthread_cond_timedwait(&process_semaphore_.m_Cond, &process_semaphore_.m_Mutex, &Ts) == ETIMEDOUT)
            {
                pthread_mutex_unlock(&process_semaphore_.m_Mutex);
                return true;
            }
        }
        --process_semaphore_.m_Counter;
        pthread_mutex_unlock(&process_semaphore_.m_Mutex);
        return true;
    }
#endif
    
    HPMUInt64 GetTimeSince1970()
    {
#ifdef _MSC_VER
        FILETIME time;
        GetSystemTimeAsFileTime(&time);
        
        return (HPMUInt64)((((ULARGE_INTEGER &)time).QuadPart / 10) - 11644473600000000);
#else
        timeval time;
        gettimeofday(&time, NULL);
        return (HPMUInt64)time.tv_sec * 1000000;
#endif
    }
    
    static void NeedSessionProcessCallback(void *semaphore)
    {
#ifdef _MSC_VER
        ReleaseSemaphore(semaphore, 1, NULL);
#elif __GNUC__
        CProcessSemaphore *pProcessSemaphore = (CProcessSemaphore *)semaphore;
        pthread_mutex_lock(&pProcessSemaphore->m_Mutex);
        ++pProcessSemaphore->m_Counter;
        pthread_cond_signal(&pProcessSemaphore->m_Cond);
        pthread_mutex_unlock(&pProcessSemaphore->m_Mutex);
#endif
    }
    
    bool InitConnection()
    {
        if (session_)
            return true;
        
        HPMUInt64 CurrentTime = GetTimeSince1970();
        if (CurrentTime > next_connection_attempt_)
        {
            next_connection_attempt_ = 0;
            
            EHPMSdkDebugMode debug_mode = EHPMSdkDebugMode_Off;
            
#ifdef _MSC_VER
            process_callback_info_.m_pContext = process_semaphore_;
#elif __GNUC__
            process_callback_info_.m_pContext = &process_semaphore_;
#endif
            process_callback_info_.m_pCallback = &HansoftSDKDashboardExporter::NeedSessionProcessCallback;
            
            try
            {
                session_ = HPMSdkSession::SessionOpen(server_, port_, database_, username_, password_, this, &process_callback_info_, true, debug_mode, NULL, 0, hpm_str(""), HPMSystemString(), NULL);
            }
            catch (const HPMSdkException &_error)
            {
                HPMString SdkError = _error.GetAsString();
                wstring Error(SdkError.begin(), SdkError.end());
                wcout << hpm_str("SessionOpen failed with error:") << Error << hpm_str("\r\n");
                return false;
            }
            catch (const HPMSdkCppException &_error)
            {
                wcout << hpm_str("SessionOpen failed with error:") << _error.what() << hpm_str("\r\n");
                return false;
            }
            
            wcout << "Successfully opened session.\r\n";
            broken_connection_ = false;
            
            return true;
        }
        
        return false;
    }
    
    void DestroyConnection()
    {
        chart_subscriptions_.clear();
        
        if (session_)
        {
            HPMSdkSession::SessionDestroy(session_);
            session_ = NULL;
        }
    }
    
    using HPMSdkCallbacks::On_Callback;
    
    map<HPMUniqueID, HPMDashboardChartSubscription> chart_subscriptions_;
    set<HPMUniqueID> updated_charts_;
    
    template<typename Integer>
    HPMString ToHPMString(Integer value)
    {
        HPMString return_value;
        
#if HPMCharSize == 1
        return_value = std::to_string(value);
#else
        return_value = std::to_wstring(value);
#endif
        
        return return_value;
    }
    
    void On_Callback(const HPMChangeCallbackData_DashboardChartReceive &_data) override
    {
        updated_charts_.insert(_data.m_ChartID);
        wcout << "Chart " << _data.m_ChartID << " was updated.\r\n";
    }
    
    HPMString GenerateFilename(HPMUniqueID chart_id, HPMString folder, HPMString suffix)
    {
        HPMString file_name =
#ifdef _WIN32
        hpm_str(".\\" + folder + "\\Chart")
#elif __GNUC__
        hpm_str("./" + folder + "/Chart")
#endif
        + ToHPMString(chart_id.m_ID) + suffix;
        
        return file_name;
    }
    
    void ExportImageChart(HPMUniqueID chart_id, HPMString result_set)
    {
        HPMString chart_registry_file_name = GenerateFilename(chart_id, hpm_str("IRG"), hpm_str(".irg"));
        HPMString chart_image_file_name = GenerateFilename(chart_id, hpm_str("CHARTS"), hpm_str(".png"));
        
        // Write the result set registry to file
        std::filebuf file_buffer;
        file_buffer.open(chart_registry_file_name.c_str(), std::ios::out);
        std::ostream out_stream(&file_buffer);
        out_stream << string(result_set.begin(), result_set.end());
        file_buffer.close();
        
        HPMString resultsettool_path =
#ifdef _MSC_VER
        hpm_str(".\\HPMResultSetTool.exe");
#elif __GNUC__
        hpm_str("./HPMResultSetTool");
#endif
        
        HPMString command_line = resultsettool_path + hpm_str(" ") + chart_registry_file_name + hpm_str(" ") + chart_image_file_name + hpm_str(" ") + resolution_;
        
#if HPMCharSize == 1
        system(command_line.c_str());
#else
        _wsystem(command_line.c_str());
#endif
        wcout << "Chart " << chart_id << " was exported as image.\r\n";
    }
    
    void ExportJsonChart(HPMUniqueID chart_id, HPMDashboardChartResultSet result_set)
    {
        HPMString chart_json_file_name = GenerateFilename(chart_id, hpm_str("JSON"), hpm_str(".json"));

        std::filebuf file_buffer;
        file_buffer.open(chart_json_file_name.c_str(), std::ios::out);
        std::ostream out_stream(&file_buffer);

        std::vector<HPMString> dimension_names;
        std::vector<EHPMDashboardChartResultDataType> dimension_types;
        std::vector<std::vector<std::string>> dimension_rows;
        for (auto dimension_info : result_set.m_Dimensions.m_DimensionInfos)
        {
            dimension_names.push_back(session_->LocalizationTranslateString(session_->LocalizationGetDefaultLanguage(), dimension_info.m_Name));
            dimension_types.push_back(dimension_info.m_Type);
        }
        for (auto dimension_row : result_set.m_Dimensions.m_Rows)
        {
            std::vector<std::string> row;
            for (auto dimension_value : dimension_row.m_Values)
            {
                switch (dimension_types[dimension_value.m_Index])
                {
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMString:
                    {
                        row.push_back(session_->VariantDecode_HPMString(dimension_value.m_VariantData));
                        break;
                    }
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMFP64:
                    {
                        std::ostringstream o;
                        o << session_->VariantDecode_HPMFP64(dimension_value.m_VariantData);
                        row.push_back(o.str());
                        break;
                    }
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMUInt64:
                    {
                        std::ostringstream o;
                        o << session_->VariantDecode_HPMUInt64(dimension_value.m_VariantData);
                        row.push_back(o.str());
                        break;
                    }
                    case HPMSdk::EHPMDashboardChartResultDataType_Binary:
                    {
                        HPMUntranslatedString u_string = session_->VariantDecode_HPMUntranslatedString(dimension_value.m_VariantData);
                        row.push_back(session_->LocalizationTranslateString(session_->LocalizationGetDefaultLanguage(), u_string));
                        break;
                    }
                    default:
                    {
                        row.push_back("");
                    }
                }
            }
            dimension_rows.push_back(row);
        }
        std::vector<EHPMDashboardChartResultDataType> measure_types;
        std::vector<std::string> measure_names;
        for (auto measure_info : result_set.m_Measures.m_MeasureInfos)
        {
            measure_types.push_back(measure_info.m_Type);
            HPMString name = session_->LocalizationTranslateString(session_->LocalizationGetDefaultLanguage(), measure_info.m_Name);
            measure_names.push_back(name);
        }

        out_stream << "{\"dimensions\": [";
        bool first = true;
        for (auto name : dimension_names)
        {
            if (!first)
                out_stream << ", ";
            out_stream << "\"" << name << "\"";
            first = false;
        }

        out_stream << "], \"measures\": [";
        first = true;
        for (auto name : measure_names)
        {
            if (!first)
                out_stream << ", ";
            out_stream << "\"" << name << "\"";
            first = false;
        }

        out_stream << "], \"rows\": [";
        bool first_row = true;
        int index = 0;
        for (auto measure_row : result_set.m_Measures.m_Rows)
        {
            if (!first_row)
                out_stream << ", ";
            out_stream << "{\"dimensions\": [";
            auto dimension_row = dimension_rows[index++];
            first = true;
            for (auto dimension_value : dimension_row)
            {
                if (!first)
                    out_stream << ", ";
                out_stream << "\"" << dimension_value << "\"";
                first = false;
            }
            out_stream << "], \"measures\": [";
            first = true;
            for (auto measure_value : measure_row.m_Values)
            {
                if (!first)
                    out_stream << ", ";
                switch (measure_types[measure_value.m_Index])
                {
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMFP64:
                    {
                        out_stream << session_->VariantDecode_HPMFP64(measure_value.m_VariantData);
                        break;
                    }
                    case HPMSdk::EHPMDashboardChartResultDataType_HPMUInt64:
                    {
                        out_stream << session_->VariantDecode_HPMUInt64(measure_value.m_VariantData);
                        break;
                    }
                    case HPMSdk::EHPMDashboardChartResultDataType_Binary:
                    {
                        auto data = session_->VariantDecode_HPMUntranslatedString(measure_value.m_VariantData);
                        out_stream << "\"" << session_->LocalizationTranslateString(session_->LocalizationGetDefaultLanguage(), data) << "\"";
                        break;
                    }
                    default:
                    {
                        out_stream << "0";
                    }
                }
                first = false;
            }
            out_stream << "]}";
            first_row = false;
        }
        out_stream << "]}";

        file_buffer.close();

        wcout << "Chart " << chart_id << " was exported as json.\r\n";
    }

    void SubscribeToChart(HPMUniqueID chart_id)
    {
        try
        {
            if (chart_subscriptions_.find(chart_id) == chart_subscriptions_.end())
                chart_subscriptions_[chart_id] = session_->DashboardSubscribeToChart(chart_id);
        }
        catch (HPMSdkException &_error)
        {
            cout << _error.GetError();
        }
    }
    
    HPMUniqueID FindChartByName(HPMUniqueID page_id, HPMString name)
    {
        HPMUniqueEnum charts = session_->DashboardChartEnum(page_id);
        for (HPMUniqueID chart_id : charts.m_IDs)
        {
            HPMString chart_name = session_->DashboardChartGetName(chart_id);
            if (chart_name == name)
                return chart_id;
        }
        return HPMUniqueID();
    }
    
    HPMUniqueID FindPageByName(HPMString name)
    {
        HPMUniqueEnum pages = session_->DashboardPageEnum();
        for (HPMUniqueID page_id : pages.m_IDs)
        {
            HPMString page_name = session_->DashboardPageGetName(page_id);
            if (page_name == name)
                return page_id;
        }
        return HPMUniqueID();
    }
    
    void Update()
    {
        if (InitConnection())
        {
            try
            {
                if (broken_connection_)
                {
                    DestroyConnection();
                }
                else
                {
                    set<HPMUniqueID> export_charts;

                    HPMUniqueEnum pages = session_->DashboardPageEnum();
                    
                    for (HPMUniqueID page_id : pages.m_IDs)
                    {
                        for (HPMUniqueID chart_id : session_->DashboardChartEnum(page_id).m_IDs)
                        {
                            if (find(charts_.begin(), charts_.end(), chart_id) != charts_.end())
                            {
                                export_charts.insert(chart_id);
                                SubscribeToChart(chart_id);
                            }
                        }
                    }
                    
                    // wait max 30 seconds before timeout
                    HPMUInt64 timeout = GetTimeSince1970() + 1000000*30;
                    while (!export_charts.empty() && GetTimeSince1970() < timeout)
                    {
                        session_->SessionProcess();
                        for (HPMUniqueID chart_id : updated_charts_)
                        {
                            set<HPMUniqueID>::iterator it = export_charts.find(chart_id);
                            if (it != export_charts.end())
                                export_charts.erase(it);
                        }
                    }
                    
                    if (!updated_charts_.empty())
                    {
                        for (HPMUniqueID chart_id : updated_charts_)
                        {
                            if (json_)
                            {
                                HPMDashboardChartResultSet result_set = session_->DashboardSubscriptionGetLastResultSet(chart_subscriptions_[chart_id]);
                                ExportJsonChart(chart_id, result_set);
                            }
                            else
                            {
                                HPMString result_set = session_->DashboardSubscriptionGetLastResultSetAsString(chart_subscriptions_[chart_id]);
                                // Write the result set registry to file
                                std::filebuf file_buffer;
                                file_buffer.open("resultset", std::ios::out);
                                std::ostream out_stream(&file_buffer);
                                out_stream << string(result_set.begin(), result_set.end());
                                file_buffer.close();
                                
                                ExportImageChart(chart_id, result_set);
                            }
                        }
                    }
                }
            }
            catch (HPMSdkException &_error)
            {
                HPMString sdk_error = _error.GetAsString();
                wstring Error(sdk_error.begin(), sdk_error.end());
                wcout << hpm_str("Exception in processing loop: ") << Error << hpm_str("\r\n");
            }
            catch (HPMSdkCppException _error)
            {
                wcout << hpm_str("Exception in processing loop: ") << _error.what() << hpm_str("\r\n");
            }
        }
    }
    
    int Run()
    {
        Update();
#ifdef _MSC_VER
        WaitForSingleObjectEx(process_semaphore_, 100, true);
#elif __GNUC__
        SemWait(100);
#endif
    
        DestroyConnection();
        
        return 0;
    }
};

void Export(string server, int port, string database, string username, string password, string resource, vector<int> charts, string dimensions, bool json)
{
    HansoftSDKDashboardExporter exporter(server, port, database, username, password, resource, charts, dimensions, json);
    exporter.Run();
}
