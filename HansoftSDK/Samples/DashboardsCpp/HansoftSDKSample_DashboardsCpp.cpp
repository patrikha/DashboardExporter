
/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	File:																						|
|																								|
|	Author:			Erik Olofsson																|
|																								|
|	Copyright:		Hansoft AB, 2007															|
|																								|
|	Contents:		Hansoft Project Manager SDK "Simple sample"									|
|																								|
|	Comments:		This sample shows the basics of connecting to a server with the SDK.		|
|					The sample will create a task in all projects and update the task date		|
|					so that it always stays on todays date.										|
|																								|
|	History:																					|
|		070312:		Created sample																|
\*_____________________________________________________________________________________________*/

#include "../../HPMSdkCpp.h"

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
#endif
#endif
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;
using namespace HPMSdk;

#ifndef _MSC_VER
int _kbhit()
{
    static const int STDIN = 0;
    static bool bInitialized = false;
	
    if (!bInitialized)
	{
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        bInitialized = true;
    }
	
    timeval timeout;
    fd_set rdset;
	
    FD_ZERO(&rdset);
    FD_SET(STDIN, &rdset);
    timeout.tv_sec  = 0;
    timeout.tv_usec = 0;
	
    return select(STDIN + 1, &rdset, NULL, NULL, &timeout);
}
#endif

#ifdef __GNUC__

struct CProcessSemaphore
{
	pthread_cond_t m_Cond;
    pthread_mutex_t m_Mutex;
    int m_Counter;
};


#endif

class CHansoftSDKSample_Simple : public HPMSdkCallbacks
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

	HPMUInt64 m_NextUpdate;
	HPMUInt64 m_NextConnectionAttempt;
#ifdef _MSC_VER
	HANDLE m_ProcessSemaphore;
#elif __GNUC__
	CProcessSemaphore m_ProcessSemaphore;
#endif
	HPMNeedSessionProcessCallbackInfo m_ProcessCallbackInfo;

	CHansoftSDKSample_Simple()
	{
		m_pSession = NULL;
		m_NextUpdate = 0;
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

	~CHansoftSDKSample_Simple()
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
		
		timespec Ts ;
		Ts.tv_sec = Now;
		Ts.tv_nsec = _Timeout * 1000000;
		
		pthread_mutex_lock(&m_ProcessSemaphore.m_Mutex);
		while (m_ProcessSemaphore.m_Counter== 0)
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
			(void)DebugMode;
#ifdef _DEBUG
			DebugMode = EHPMSdkDebugMode_Debug; // Set debug flag so we will get memory leak info.
#endif

			// You should change these parameters to match your development server and the SDK account you have created. For more information see SDK documentation.

#ifdef _MSC_VER
			m_ProcessCallbackInfo.m_pContext = m_ProcessSemaphore;
#elif __GNUC__
			m_ProcessCallbackInfo.m_pContext = &m_ProcessSemaphore;
#endif
			m_ProcessCallbackInfo.m_pCallback = &CHansoftSDKSample_Simple::NeedSessionProcessCallback;

			try
			{
				m_pSession = HPMSdkSession::SessionOpen(hpm_str("localhost"), 50255, hpm_str("Company_Projects"), hpm_str("SDK"), hpm_str("SDK"), this, &m_ProcessCallbackInfo, true, DebugMode, NULL, 0, hpm_str(""), HPMSystemString(), NULL);
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

		m_NextUpdate = 0; // Update when connection is restored
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

	void ExportChart(HPMUniqueID ChartID, HPMString ResultSet)
	{
		HPMString ChartRegistryFileName = hpm_str("Chart") + ToHPMString(ChartID.m_ID) + hpm_str(".irg");
		HPMString ChartImageFileName = hpm_str("Chart") + ToHPMString(ChartID.m_ID) + hpm_str(".png");

		// Write the result set registry to file
		std::filebuf FileBuffer;
		FileBuffer.open(ChartRegistryFileName.c_str(),std::ios::out);
		std::ostream OutStream(&FileBuffer);
		OutStream << string(ResultSet.begin(), ResultSet.end());
		FileBuffer.close();

		// Render the result set as a chart
		HPMString Resolution = hpm_str("400 300 medium");


		HPMString ResultSetToolPath =
#ifdef _MSC_VER
			hpm_str("..\\..\\Win32\\HPMResultSetTool.exe ");
#elif __GNUC__
			hpm_str("../../../../OSX10.6/x64/HPMResultSetTool ");
#endif

		HPMString CommandLine = ResultSetToolPath + ChartRegistryFileName + hpm_str(" ") + ChartImageFileName + hpm_str(" ") + Resolution;

#if HPMCharSize == 1
		system(CommandLine.c_str());
#else
		_wsystem(CommandLine.c_str());
#endif
	}

	void SubscribeToChart(HPMUniqueID ChartID)
	{
		if (m_ChartSubscriptions.find(ChartID) == m_ChartSubscriptions.end())
			m_ChartSubscriptions[ChartID] = m_pSession->DashboardSubscribeToChart(ChartID);
	}

	void SubscribeToPage(HPMUniqueID PageID)
	{
		HPMUniqueEnum ChartIDs = m_pSession->DashboardChartEnum(PageID);
		for (HPMUniqueID ChartID : ChartIDs.m_IDs)
			SubscribeToChart(ChartID);
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

	HPMUniqueID CreateChart(HPMUniqueID PageID, HPMUniqueID UserID, HPMString ChartName, EHPMDashboardChartType Type, vector<HPMDashboardChartDimension> const& Dimensions, vector<HPMDashboardChartMeasure> const& Measures)
	{
		HPMDashboardChartPresentationConfig PresentationConfig;
		PresentationConfig.m_Enabled = EHPMDashboardChartPresentationSettingEnabled_Type;
		PresentationConfig.m_Type = Type;
			
		HPMDashboardChartComputationConfig ComputationConfig;

		ComputationConfig.m_ChartOwner = UserID;
		ComputationConfig.m_Dimensions = Dimensions;
		ComputationConfig.m_Measures = Measures;
		
		ComputationConfig.m_bSupressZeroValues = false;
		ComputationConfig.m_OriginalVersion = 0;
			
		HPMUniqueID ChartID = m_pSession->DashboardChartCreate(PageID, PresentationConfig, ComputationConfig, HPMUniqueID(0), HPMUniqueID());
		
		m_pSession->DashboardChartSetName(ChartID, ChartName);

		SubscribeToChart(ChartID);

		return ChartID;
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
					// Check our stuff
					HPMUInt64 CurrentTime = GetTimeSince1970();
					if (CurrentTime > m_NextUpdate)
					{
						HPMUniqueID UserID = m_pSession->ResourceGetResourceFromName(hpm_str("Example Proj Manager"));

						if (!UserID.IsValid())
						{
							wcout << hpm_str("Could not find user\r\n");
							return;
						}

						// Example: Create page with charts
						HPMString PageName = hpm_str("Bugs");
						HPMUniqueID PageID = FindPageByName(PageName);

						if (!PageID.IsValid())
						{
							// Page will be created for impersonated user
							m_pSession->ResourceImpersonate(UserID, EHPMDataHistoryClientOrigin_None, HPMUntranslatedString());
							PageID = m_pSession->DashboardPageCreateBlock(PageName, HPMUniqueID(0));
							m_pSession->ResourceImpersonate(HPMUniqueID(), EHPMDataHistoryClientOrigin_None, HPMUntranslatedString());
						}

						{
							// Chart: Projects and status as dimension
							HPMString ChartName = hpm_str("Projects / Status");
							HPMUniqueID ChartID = FindChartByName(PageID, ChartName);

							if (ChartID.IsValid())
								SubscribeToChart(ChartID);
							else
							{
								vector<HPMDashboardChartDimension> Dimensions(2);

								HPMDashboardChartDimension& UsersDimension = Dimensions[0];
								UsersDimension.m_Enabled = EHPMDashboardChartDimensionSettingEnabled_Category;
								UsersDimension.m_Category = EHPMDashboardChartDimensionCategory_Projects;

								HPMDashboardChartDimension& StatusDimension = Dimensions[1];
								StatusDimension.m_Enabled = EHPMDashboardChartDimensionSettingEnabled(EHPMDashboardChartDimensionSettingEnabled_Category | EHPMDashboardChartDimensionSettingEnabled_SubCategory);
								StatusDimension.m_Category = EHPMDashboardChartDimensionCategory_ProjectColumnData;

								HPMDashboardChartDataIdentifier StatusColumnIdentifier;
								StatusColumnIdentifier.m_ID = EHPMProjectDefaultColumn_ItemStatus;
								StatusDimension.m_SubCategory = StatusColumnIdentifier;

								vector<HPMDashboardChartMeasure> Measures(1);

								HPMDashboardChartMeasure& CountMeasure = Measures[0];
								CountMeasure.m_Category = EHPMDashboardChartMeasureCategory_NumberOfItems;
								CountMeasure.m_AggregationFunction = EHPMDashboardChartMeasureAggregationFunction_Sum;

								CreateChart(PageID, UserID, ChartName, EHPMDashboardChartType_Bar, Dimensions, Measures);

							}
						}

						// Enumerate projects
						HPMProjectEnum Projects = m_pSession->ProjectEnum();
						// Loop through projects
						for (HPMUInt32 i = 0; i < Projects.m_Projects.size(); ++i)
						{
							HPMUniqueID ProjectID = Projects.m_Projects[i];

							{
								
								{
									// Chart: Custom columns for dimension and measure
									
									HPMUInt32 DimensionColumnHash = 0;
									HPMUInt32 MeasureColumnHash = 0;
									
									HPMProjectCustomColumns CustomColumns;
									HPMProjectCustomColumnsColumn Showing[2];

									Showing[0].m_AccessRights = EHPMProjectCustomColumnsColumnAccessRights_AllProjectMembers;
									Showing[0].m_Type = EHPMProjectCustomColumnsColumnType_FloatNumber;
									Showing[0].m_Name = hpm_str("CustomMeasure");

									CustomColumns.m_ShowingColumns.push_back(Showing[0]);

									Showing[1].m_AccessRights = EHPMProjectCustomColumnsColumnAccessRights_AllProjectMembers;
									Showing[1].m_Type = EHPMProjectCustomColumnsColumnType_DropList;
									Showing[1].m_Name = hpm_str("CustomDimension");
									HPMProjectCustomColumnsColumnDropListItem DropList[4];

									DropList[0].m_Icon = EHPMListIcon_RedDot;
									DropList[0].m_Id = 0;
									DropList[0].m_Name = hpm_str("Type One");

									DropList[1].m_Icon = EHPMListIcon_BlueCircle;
									DropList[1].m_Id = 1;
									DropList[1].m_Name = hpm_str("Type Two");

									Showing[1].m_DropListItems.push_back(DropList[0]);
									Showing[1].m_DropListItems.push_back(DropList[1]);

									CustomColumns.m_ShowingColumns.push_back(Showing[1]);

									m_pSession->ProjectCustomColumnsSet(ProjectID, CustomColumns);

									MeasureColumnHash = m_pSession->UtilGetColumnHash(Showing[0]);
									DimensionColumnHash = m_pSession->UtilGetColumnHash(Showing[1]);

									HPMTaskEnum Tasks = m_pSession->TaskEnum(ProjectID);

									for (HPMUInt32 iTask = 0; iTask < Tasks.m_Tasks.size(); ++iTask)
									{
										HPMUniqueID TaskID = Tasks.m_Tasks[iTask];
										m_pSession->TaskSetCustomColumnData(TaskID, DimensionColumnHash, (iTask % 2) ? hpm_str("0") : hpm_str("1"), false);

										HPMString Value = ToHPMString(iTask+1);
										m_pSession->TaskSetCustomColumnData(TaskID, MeasureColumnHash, Value, false);
									}


									HPMString ChartName = hpm_str("Custom columns");
									HPMUniqueID ChartID = FindChartByName(PageID, ChartName);

									if (ChartID.IsValid())
										SubscribeToChart(ChartID);
									else
									{
										std::vector<HPMDashboardChartDimension> Dimensions(1);

										HPMDashboardChartDimension& CustomDimension = Dimensions[0];
										CustomDimension.m_Enabled = EHPMDashboardChartDimensionSettingEnabled(EHPMDashboardChartDimensionSettingEnabled_Category | EHPMDashboardChartDimensionSettingEnabled_SubCategory);
										CustomDimension.m_Category = EHPMDashboardChartDimensionCategory_ProjectColumnData;

										CustomDimension.m_SubCategory.m_ID = EHPMProjectDefaultColumn_Custom;
										CustomDimension.m_SubCategory.m_IDData = DimensionColumnHash;

										std::vector<HPMDashboardChartMeasure> Measures(1);

										HPMDashboardChartMeasure& CustomMeasure = Measures[0];
										CustomMeasure.m_Category = EHPMDashboardChartMeasureCategory_ProjectColumnData;
										CustomMeasure.m_AggregationFunction = EHPMDashboardChartMeasureAggregationFunction_Sum;

										HPMDashboardChartDataIdentifier CustomMeasureIdentifier;
										CustomMeasureIdentifier.m_ID = EHPMProjectDefaultColumn_Custom;
										CustomMeasureIdentifier.m_IDData = MeasureColumnHash;

										CustomMeasure.m_Identifiers.push_back(CustomMeasureIdentifier);

										CreateChart(PageID, UserID, ChartName, EHPMDashboardChartType_Pie, Dimensions, Measures);
										
									}
								}

							}

						}

#if (DEBUG)
						m_NextUpdate = CurrentTime + 10000000; // Check every 10 seconds
#else
						m_NextUpdate = CurrentTime + 120000000; // Check every 120 seconds
#endif
					}

					
					m_UpdatedCharts.clear();
					m_pSession->SessionProcess();

					if (!m_UpdatedCharts.empty())
					{
						for (HPMUniqueID ChartID : m_UpdatedCharts)
						{
							HPMString ResultSet = m_pSession->DashboardSubscriptionGetLastResultSetAsString(m_ChartSubscriptions[ChartID]);
							ExportChart(ChartID, ResultSet);
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
		// Initialize the SDK
		while (!_kbhit())
		{
			Update();
#ifdef _MSC_VER
			WaitForSingleObjectEx(m_ProcessSemaphore, 100, true);
#elif __GNUC__
			SemWait(100);
#endif
		}

		DestroyConnection();

		return 0;
	}
};

#ifdef _MSC_VER
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, const char * argv[])
#endif
{
	CHansoftSDKSample_Simple Sample;

	return Sample.Run();
}

