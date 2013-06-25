// schtasks.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <windows.h>
#include <stdio.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <comdef.h>
#include <taskschd.h>
#include <initguid.h>
#include <ole2.h>
#include <mstask.h>
#include <msterr.h>
#include <objidl.h>

#pragma comment(lib,"taskschd.lib")
#pragma comment(lib,"comsupp.lib")

#define EXPORT_API __declspec(dllexport)

BOOL SchTaskAdd(LPCWSTR pwszFilePath,LPCWSTR pwszTaskName);

#define _DEBUG

#ifdef _DEBUG
VOID DbgPrint(PCHAR pcFormat,...);
#else
#define DbgPrint(...)
#endif

#ifdef _DEBUG
VOID DbgPrint(PCHAR pcFormat, HRESULT hr)
{
	CHAR chMsg[1024*4];
	wsprintfA(chMsg, pcFormat, hr);
	OutputDebugStringA(chMsg);
	return;
	va_list vaList;
	CHAR chFormat[1024];
	CHAR chPath[MAX_PATH];

	OutputDebugStringA("1");
	GetModuleFileNameA(NULL,chPath,RTL_NUMBER_OF(chPath)-1);
	OutputDebugStringA(chPath);
	wsprintfA(chFormat,"[%s] %s", chPath,pcFormat);
	OutputDebugStringA("3");
	va_start(vaList,pcFormat);
	_vsnprintf(chMsg,sizeof(chMsg)-1,chFormat,vaList);
	va_end(vaList);
OutputDebugStringA("4");
	OutputDebugStringA(chFormat);
}
#endif

BOOL TaskAddSrv20SetLogonTrigger(ITrigger *pTrigger,LPCWSTR wszTriggerName)
{
	BOOL bResult = FALSE;
	HRESULT Hr;
	ILogonTrigger *pLogonTrigger = NULL;

    Hr = pTrigger->QueryInterface(IID_ILogonTrigger,(PVOID*)&pLogonTrigger);
	if (SUCCEEDED(Hr))
	{    
		BSTR bTriggerName = SysAllocString(wszTriggerName);
		if (bTriggerName)
		{
			Hr = pLogonTrigger->put_Id(bTriggerName);
			bResult = SUCCEEDED(Hr);
			if (!bResult)
			{
				DbgPrint(__FUNCTION__"(): put_Id failed: %x\n",Hr);
			}

			SysFreeString(bTriggerName);
		}

		pLogonTrigger->Release();
	}
	else
	{
		DbgPrint(__FUNCTION__"(): QueryInterface failed: %x\n",Hr);
	}

	return bResult;
}

BOOL TaskAddSrv20RegisterTask(ITaskDefinition *pTask,ITaskFolder *pRootFolder,BSTR bTaskName,LPCWSTR wszExecutablePath)
{  
	BOOL bResult = FALSE;
	HRESULT Hr;
    IActionCollection *pActionCollection = NULL;

    Hr = pTask->get_Actions(&pActionCollection);
    if (SUCCEEDED(Hr))
    {
		IAction *pAction = NULL;

		Hr = pActionCollection->Create(TASK_ACTION_EXEC,&pAction);
		if (SUCCEEDED(Hr))
		{
			IExecAction *pExecAction = NULL;

			Hr = pAction->QueryInterface(IID_IExecAction,(PVOID*)&pExecAction);
			if (SUCCEEDED(Hr))
			{
				BSTR bExecutablePath = SysAllocString(wszExecutablePath);
				if (bExecutablePath)
				{
					Hr = pExecAction->put_Path(bExecutablePath); 
					if (SUCCEEDED(Hr))
					{
						IRegisteredTask *pRegisteredTask = NULL;
						VARIANT varPassword;
						varPassword.vt = VT_EMPTY;
    
						Hr = pRootFolder->RegisterTaskDefinition(bTaskName,pTask,TASK_CREATE_OR_UPDATE,_variant_t(),varPassword,TASK_LOGON_INTERACTIVE_TOKEN,_variant_t(),&pRegisteredTask);
						bResult = SUCCEEDED(Hr);
						if (bResult)
						{
							pRegisteredTask->Release();
						}
						else
						{
							DbgPrint(__FUNCTION__"(): RegisterTaskDefinition failed: %x\n",Hr);
						}
					}
					else
					{
						DbgPrint(__FUNCTION__"(): put_Path failed: %x\n",Hr);
					}

					SysFreeString(bExecutablePath);
				}

				pExecAction->Release();
			}
			else
			{
				DbgPrint(__FUNCTION__"(): QueryInterface failed: %x\n",Hr);
			}

			pAction->Release();
		}
		else
		{
			DbgPrint(__FUNCTION__"(): Create failed: %x\n",Hr);
		}

		pActionCollection->Release();
    }
	else
	{
		DbgPrint(__FUNCTION__"(): get_Actions failed: %x\n",Hr);
	}

	return bResult;
}

BOOL TaskAddSrv20(LPCWSTR wszTaskName,LPCWSTR wszExecutablePath,LPCWSTR wszTriggerName)
{
	BOOL bResult = FALSE;
	HRESULT Hr;
		
	Hr = CoInitializeEx(NULL,COINIT_MULTITHREADED);
    if (SUCCEEDED(Hr))
	{
		Hr = CoInitializeSecurity(NULL,-1,NULL,NULL,RPC_C_AUTHN_LEVEL_PKT_PRIVACY,RPC_C_IMP_LEVEL_IMPERSONATE,NULL,0,NULL);
		if (SUCCEEDED(Hr))
		{
			ITaskService *pService = NULL;

			Hr = CoCreateInstance(CLSID_TaskScheduler,NULL,CLSCTX_INPROC_SERVER,IID_ITaskService,(PVOID*)&pService);  
			if (SUCCEEDED(Hr))
			{
				Hr = pService->Connect(_variant_t(),_variant_t(),_variant_t(),_variant_t());
				if (SUCCEEDED(Hr))
				{
					BSTR bFolderName = SysAllocString(L"\\");
					if (bFolderName)
					{
						ITaskFolder *pRootFolder = NULL;

						Hr = pService->GetFolder(bFolderName,&pRootFolder);
						if (SUCCEEDED(Hr))
						{
							BSTR bTaskName = SysAllocString(wszTaskName);
							if (bTaskName)
							{
								pRootFolder->DeleteTask(bTaskName,0);

								ITaskDefinition *pTask = NULL;

								Hr = pService->NewTask(0,&pTask);
								if (SUCCEEDED(Hr))
								{
									ITriggerCollection *pTriggerCollection = NULL;

									Hr = pTask->get_Triggers(&pTriggerCollection);
									if (SUCCEEDED(Hr))
									{
										ITrigger *pTrigger = NULL;

										Hr = pTriggerCollection->Create(TASK_TRIGGER_LOGON,&pTrigger); 
										if (SUCCEEDED(Hr))
										{
											if (TaskAddSrv20SetLogonTrigger(pTrigger,wszTriggerName))
											{
												bResult = TaskAddSrv20RegisterTask(pTask,pRootFolder,bTaskName,wszExecutablePath);
											}

											pTrigger->Release();
										}
										else
										{
											DbgPrint(__FUNCTION__"(): Create failed: %x\n",Hr);		
										}

										pTriggerCollection->Release();
									}
									else
									{
										DbgPrint(__FUNCTION__"(): get_Triggers failed: %x\n",Hr);	
									}
								
									pTask->Release();
								}
								else
								{
									DbgPrint(__FUNCTION__"(): NewTask failed: %x\n",Hr);
								}
							
								SysFreeString(bTaskName);
							}

							pRootFolder->Release();
						}
						else
						{
							DbgPrint(__FUNCTION__"(): GetFolder failed: %x\n",Hr);
						}

						SysFreeString(bFolderName);
					}
				}
				else
				{
					DbgPrint(__FUNCTION__"(): Connect failed: %x\n",Hr);
				}

				pService->Release();
			}
			else
			{
				DbgPrint(__FUNCTION__"(): CoCreateInstance failed: %x\n",Hr);
			}
		}
		else
		{
			DbgPrint(__FUNCTION__"(): CoInitializeSecurity failed: %x\n",Hr);
		}

        CoUninitialize();
    }
	else
	{
		DbgPrint(__FUNCTION__"(): CoInitializeEx failed: %x\n",Hr);
	}

	return bResult;
}

BOOL TaskAddSch10SetLogonTrigger(ITask *pITask,LPCWSTR pwszApplicationName)
{
	BOOL bResult = FALSE;
	HRESULT Hr;

	Hr = pITask->SetApplicationName(pwszApplicationName);
	if (SUCCEEDED(Hr))
	{
		Hr = pITask->SetFlags(TASK_FLAG_HIDDEN|TASK_FLAG_RUN_ONLY_IF_LOGGED_ON);
		if (SUCCEEDED(Hr))
		{
			Hr = pITask->SetAccountInformation(L"",NULL);
			if (SUCCEEDED(Hr))
			{
				ITaskTrigger *pTrigger;
				WORD iNewTrigger;

				Hr = pITask->CreateTrigger(&iNewTrigger,&pTrigger);
				if (SUCCEEDED(Hr))
				{
					TASK_TRIGGER Trigger = {0};
					
					Trigger.cbTriggerSize = sizeof(TASK_TRIGGER);
					Trigger.wBeginDay = 1;
					Trigger.wBeginMonth = 1;
					Trigger.wBeginYear = 1999;
					Trigger.TriggerType = TASK_EVENT_TRIGGER_AT_LOGON;

					Hr = pTrigger->SetTrigger(&Trigger);
					bResult = SUCCEEDED(Hr);
					if (!bResult)
					{
						DbgPrint(__FUNCTION__"(): SetTrigger failed: %x\n",Hr);
					}
				
					pTrigger->Release();
				}
				else
				{
					DbgPrint(__FUNCTION__"(): CreateTrigger failed: %x\n",Hr);	
				}
			}
			else
			{
				DbgPrint(__FUNCTION__"(): SetAccountInformation failed: %x\n",Hr);	
			}
		}
		else
		{
			DbgPrint(__FUNCTION__"(): SetFlags failed: %x\n",Hr);	
		}
	}
	else
	{
		DbgPrint(__FUNCTION__"(): SetApplicationName failed: %x\n",Hr);
	}

	return bResult;
}

BOOL TaskAddSch10(LPCWSTR pwszTaskName,LPCWSTR pwszApplicationName)
{
	BOOL bResult = FALSE;
	HRESULT Hr;
	
	Hr = CoInitialize(NULL);
	if (SUCCEEDED(Hr))
	{
		ITaskScheduler *pITS;

		Hr = CoCreateInstance(CLSID_CTaskScheduler,NULL,CLSCTX_INPROC_SERVER,IID_ITaskScheduler,(PVOID*)&pITS);
		if (SUCCEEDED(Hr))
		{
			ITask *pITask;

			Hr = pITS->NewWorkItem(pwszTaskName,CLSID_CTask,IID_ITask,(IUnknown**)&pITask);
			if (SUCCEEDED(Hr))
			{
				if (TaskAddSch10SetLogonTrigger(pITask,pwszApplicationName))
				{
					Hr = pITS->AddWorkItem(pwszTaskName,(IScheduledWorkItem *)pITask);
					bResult = SUCCEEDED(Hr);
					if (!bResult)
					{
						DbgPrint(__FUNCTION__"(): AddWorkItem failed: %x\n",Hr);	
					}
				}

				pITask->Release();
			}
			else
			{
				DbgPrint(__FUNCTION__"(): NewWorkItem failed: %x\n",Hr);	
			}

			pITS->Release();
		}
		else
		{
			DbgPrint(__FUNCTION__"(): CoCreateInstance failed: %x\n",Hr);
		}
		CoUninitialize();
	}
	else
	{
		DbgPrint(__FUNCTION__"(): CoInitialize failed: %x\n",Hr);
	}
	return bResult;
}

BOOL SchTaskAdd(LPCWSTR pwszFilePath,LPCWSTR pwszTaskName)
{
	BOOL bResult;

	bResult = TaskAddSch10(pwszTaskName,pwszFilePath);
	if (!bResult) 
	{
		bResult = TaskAddSrv20(pwszTaskName,pwszFilePath,L"Trigger1");	
	}

	return bResult;
}

extern "C"
{
void EXPORT_API start(char* exe)
{
	WCHAR buf[MAX_PATH + MAX_PATH];
	OutputDebugStringA("Enter start");
	//MultiByteToWideChar( CP_ACP, 0, exe, -1, buf, MAX_PATH );
	OutputDebugStringA("Set AutoRun");
	if( SchTaskAdd( L"c:\\test\\dllloader.exe" /*buf*/, L"MyTask" ) )
		OutputDebugStringA("AutoRun TRUE");
	else
		OutputDebugStringA("AutoRun FALSE");
}

BOOL EXPORT_API DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

int main()
{
	return 1;
}
}
