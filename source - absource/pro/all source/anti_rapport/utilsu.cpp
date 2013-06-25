#include <stdio.h>
#include <windows.h>
#include <shlwapi.h>
#include <imagehlp.h>
#include "ntdll.h"

#include "utilsu.h"

#ifdef _DEBUG
VOID __cdecl UtiDPrint(LPCSTR lpFormat, ...)
{
	va_list vaList;
	CHAR chFormat[1024];
	CHAR chMsg[1024*4];
	CHAR chPath[MAX_PATH];

	GetModuleFileName(NULL, chPath, RTL_NUMBER_OF(chPath)-1);
	_snprintf(chFormat, RTL_NUMBER_OF(chFormat)-1, "[%x|%x|%s] %s", GetCurrentProcessId(), GetCurrentThreadId(), PathFindFileName(chPath), lpFormat);

	va_start(vaList, lpFormat);
	_vsnprintf(chMsg, RTL_NUMBER_OF(chMsg)-1, chFormat, vaList);
	va_end(vaList);

	OutputDebugString(chMsg);
}
#endif

PVOID UtiMemAlloc(DWORD dwSize)
{
	return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwSize);
}

VOID UtiMemFree(PVOID pvMem)
{
	HeapFree(GetProcessHeap(), 0, pvMem);
}

PVOID UtiMemReAlloc(PVOID pvMem, DWORD dwSize)
{
	return HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, pvMem, dwSize);
}

PVOID UtiMapFile(LPCSTR lpPath, DWORD dwAccess, DWORD dwFileFlags, DWORD dwPageAccess, DWORD dwMapAccess, PDWORD pdwSize)
{
	PVOID pMap = NULL;
	HANDLE hFile;
	HANDLE hMap;

	hFile = CreateFile(lpPath, dwAccess, FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE, NULL, OPEN_EXISTING, dwFileFlags, 0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		hMap = CreateFileMapping(hFile, NULL, dwPageAccess, 0, 0, NULL);
		if (hMap != INVALID_HANDLE_VALUE)
		{
			pMap = MapViewOfFile(hMap, dwMapAccess, 0, 0, 0);
			if (pMap)
			{
				if (pdwSize) *pdwSize = GetFileSize(hFile, NULL);
			}
			else
			{
				UtiDPrint(__FUNCTION__"(): MapViewOfFile fails; last error: %x\n", GetLastError());
			}

			CloseHandle(hMap);
		}
		else
		{
			UtiDPrint(__FUNCTION__"(): CreateFileMapping fails; last error: %x\n", GetLastError());
		}

		CloseHandle(hFile);
	}
	else
	{
		UtiDPrint(__FUNCTION__"(): CreateFile fails; last error: %x\n", GetLastError());
	}

	return pMap;
}

BOOL UtiSetFileDllFlag(LPCSTR lpPath)
{
	BOOL bRet = FALSE;
	DWORD dwSize;
	PVOID pMap;
	PIMAGE_NT_HEADERS pNtHeader;
	DWORD HeaderSum, CheckSum;
	
	pMap = UtiMapFile(lpPath, GENERIC_WRITE|GENERIC_READ, FILE_FLAG_WRITE_THROUGH, PAGE_READWRITE, FILE_MAP_WRITE|FILE_MAP_READ, &dwSize);
	if (pMap)
	{
		pNtHeader = (PIMAGE_NT_HEADERS)RtlImageNtHeader(pMap);
		if (pNtHeader)
		{
			pNtHeader->FileHeader.Characteristics |= IMAGE_FILE_DLL;

			bRet = (BOOL)CheckSumMappedFile(pMap, dwSize, &HeaderSum, &CheckSum);
			if (bRet) pNtHeader->OptionalHeader.CheckSum = CheckSum;
		}

		FlushViewOfFile(pMap, dwSize);
		UnmapViewOfFile(pMap);
	}

	return bRet;
}
