

#pragma once

#include <windows.h>

//Error codes

#define SVC_OK (DWORD)0
#define SVC_NOT_CREATE (DWORD)1
#define SVC_NOT_START (DWORD)2
#define SVC_NOT_INIT (DWORD)3
#define SVC_ERROR_SCMANAGER (DWORD)4
#define SVC_ERROR_CREATE (DWORD)5
#define SVC_ERROR_START (DWORD)6
#define SVC_ERROR_OPEN (DWORD) 7
#define SVC_ERROR_STOP (DWORD)8
#define SVC_ERROR_UNLOAD (DWORD) 9


class CService
{
public:
	//Constructor
	CService(void);
	CService(LPTSTR _lpFilePath,LPTSTR _lpServiceName,LPTSTR _lpDisplayName,DWORD _dwStartType);
	//Destructor
	~CService(void);
	
	//init function
	DWORD InitSvc(LPTSTR _lpFilePath,LPTSTR _lpServiceName,LPTSTR _lpDisplayName,DWORD _dwStartType);
	DWORD CreateSvc(void);  //create service
	DWORD UnloadSvc(void);  //unload service
	DWORD StartSvc(void);  //start service
	DWORD StopSvc(void);   //stop service


	BOOL   IsInit(void); //check if service is init
	BOOL   IsLoaded(void); //check if service is loaded
	BOOL   IsStarted(void); //check if service is started

	

private:
	
	LPTSTR lpFilePath; //driver file path
	LPTSTR lpServiceName; //service name
	LPTSTR lpDisplayName; //dos service name

	DWORD dwStartType; //start type

	SC_HANDLE hService; //service's handle
	
	// Status variables
	BOOL init; 
	BOOL loaded;
	BOOL started;	

};
