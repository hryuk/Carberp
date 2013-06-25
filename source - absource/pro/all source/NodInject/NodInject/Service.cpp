#include <intrin.h>
#include <stdio.h>
#include <windows.h>
#include <psapi.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <tlhelp32.h>
#include <Winspool.h>

#include "ntdll.h"
#include "Service.h"

CService::CService(void)
{
	lpFilePath = NULL;
	lpServiceName = NULL;
	lpDisplayName = NULL;

	dwStartType = 0;

	hService = NULL;
	
	init = false;
	loaded = false;
	started = false;
}

CService::CService(LPTSTR _lpFilePath,LPTSTR _lpServiceName,LPTSTR _lpDisplayName,DWORD _dwStartType)
{
	lpFilePath = _lpFilePath;
	lpServiceName = _lpServiceName;
	lpDisplayName = _lpDisplayName;

	dwStartType = _dwStartType;

	hService = NULL;
	
	init = true;
	loaded = false;
	started = false;
}

CService::~CService(void)
{
	UnloadSvc();

	lpFilePath = NULL;
	lpServiceName = NULL;
	lpDisplayName = NULL;

	dwStartType = 0;

	hService = NULL;
	
	init = false;
	loaded = false;
	started = false;

}

DWORD CService::InitSvc(LPTSTR _lpFilePath,LPTSTR _lpServiceName,LPTSTR _lpDisplayName,DWORD _dwStartType)
{
	if (IsInit())
		return SVC_OK;		
	
	
	lpFilePath = _lpFilePath;
	lpServiceName = _lpServiceName;
	lpDisplayName = _lpDisplayName;

	dwStartType = _dwStartType;

	hService = NULL;

	init = true;
	loaded = false;
	started = false;

	return SVC_OK;
}


DWORD CService::CreateSvc(void)
{
	if (!IsInit())
		return SVC_NOT_INIT;
	
	if (IsLoaded())
		return SVC_OK;

	SC_HANDLE hSCManager = OpenSCManager(NULL,NULL,SC_MANAGER_CREATE_SERVICE);

	if (hSCManager == NULL)
		return SVC_ERROR_SCMANAGER;

	hService = CreateService(hSCManager,lpServiceName,lpDisplayName,
							 SERVICE_ALL_ACCESS,    
							 SERVICE_KERNEL_DRIVER, 
							 dwStartType,  
							 SERVICE_ERROR_NORMAL,  
							 lpFilePath,	          
							 NULL,                  
							 NULL,                  
							 NULL,                 
							 NULL,                  
							 NULL);

	if (hService == NULL){

		hService = OpenService(hSCManager, lpServiceName, SERVICE_ALL_ACCESS);
		
		if (hService == NULL) {
			CloseServiceHandle(hSCManager);
			return SVC_ERROR_CREATE;
		}
	}
	
	loaded = true;
	CloseServiceHandle(hSCManager);
	
	return SVC_OK;	
}

DWORD CService::StartSvc(void)
{
	if (!IsLoaded())
		return SVC_NOT_CREATE;

	if (IsStarted())
		return SVC_OK;

	SC_HANDLE hSCManager = OpenSCManager(NULL,NULL,SC_MANAGER_CREATE_SERVICE);

	if (hSCManager == NULL)
		return SVC_ERROR_SCMANAGER;

	hService = OpenService(hSCManager, lpServiceName, SERVICE_ALL_ACCESS);
		
	if (hService == NULL) {
		CloseServiceHandle(hSCManager);
		return SVC_ERROR_OPEN;
	}

	if (StartService(hService,0,NULL)== NULL){
		CloseServiceHandle(hSCManager);
		CloseServiceHandle(hService);
		return SVC_ERROR_START;
	}

	CloseServiceHandle(hSCManager);
	started = true;

	return SVC_OK;
}

DWORD CService::StopSvc(void)
{
	SERVICE_STATUS ss;

	if (!IsStarted())
		return SVC_OK;

	SC_HANDLE hSCManager = OpenSCManager(NULL,NULL,SC_MANAGER_CREATE_SERVICE);

	if (hSCManager == NULL)
		return SVC_ERROR_SCMANAGER;

	hService = OpenService(hSCManager, lpServiceName, SERVICE_ALL_ACCESS);
		
	if (hService == NULL) {
		CloseServiceHandle(hSCManager);
		return SVC_ERROR_OPEN;
	}

	if (ControlService(hService,SERVICE_CONTROL_STOP,&ss) == NULL){
		CloseServiceHandle(hSCManager);
		CloseServiceHandle(hService);
		return SVC_ERROR_STOP;
	
	}
	
	started = false;

	CloseServiceHandle(hSCManager);
	CloseServiceHandle(hService);
	return SVC_OK;
}

DWORD CService::UnloadSvc(void)
{
	if (!IsLoaded())
		return SVC_OK;

	if (IsStarted())
		if (StopSvc() != SVC_OK)
			return SVC_ERROR_UNLOAD;

	SC_HANDLE hSCManager = OpenSCManager(NULL,NULL,SC_MANAGER_CREATE_SERVICE);

	if (hSCManager == NULL)
		return SVC_ERROR_SCMANAGER;

	hService = OpenService(hSCManager, lpServiceName, SERVICE_ALL_ACCESS);
		
	if (hService == NULL) {
		CloseServiceHandle(hSCManager);
		return SVC_ERROR_OPEN;
	}

	DeleteService(hService);
	CloseServiceHandle(hSCManager);
	
	loaded = false;

	return SVC_OK;
}

BOOL CService::IsInit(void)
{
	return init;
}

BOOL CService::IsLoaded(void)
{
	return loaded;
}

BOOL CService::IsStarted(void)
{
	return started;
}