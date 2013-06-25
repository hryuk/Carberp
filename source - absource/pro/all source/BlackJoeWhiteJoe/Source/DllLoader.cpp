#include <windows.h>
#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "DllLoader.h"

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
				dest = (unsigned char *)pVirtualAlloc( codeBase + section->VirtualAddress, size, MEM_COMMIT, PAGE_READWRITE );

				section->Misc.PhysicalAddress = (DWORD)dest;
				m_memset( dest, 0, size );
			}

			continue;
		}

		dest = (unsigned char *)pVirtualAlloc( codeBase + section->VirtualAddress,
											  section->SizeOfRawData,
											  MEM_COMMIT,
											  PAGE_READWRITE );

		m_memcpy( dest, data + section->PointerToRawData, section->SizeOfRawData );

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
			pVirtualFree((LPVOID)section->Misc.PhysicalAddress, section->SizeOfRawData, MEM_DECOMMIT);
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
			if ( pVirtualProtect((LPVOID)section->Misc.PhysicalAddress, section->SizeOfRawData, protect, &oldProtect) == 0 )
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

		for ( ; !pIsBadReadPtr(importDesc, sizeof(IMAGE_IMPORT_DESCRIPTOR)) && importDesc->Name; importDesc++ )
		{
			DWORD *thunkRef, *funcRef;
			HMODULE handle = (HMODULE)pLoadLibraryA( (LPCSTR)(codeBase + importDesc->Name) );

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
					*funcRef = (DWORD)pGetProcAddress( handle, (LPCSTR)IMAGE_ORDINAL(*thunkRef) );
				}
				else
				{
					PIMAGE_IMPORT_BY_NAME thunkData = (PIMAGE_IMPORT_BY_NAME)(codeBase + *thunkRef);
					*funcRef = (DWORD)pGetProcAddress( handle, (LPCSTR)&thunkData->Name );
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
					pFreeLibrary(module->modules[i]);

			MemFree(module->modules);
		}

		if (module->codeBase != NULL)
			pVirtualFree(module->codeBase, 0, MEM_RELEASE);

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

	code = (unsigned char *)pVirtualAlloc((LPVOID)(old_header->OptionalHeader.ImageBase),
		old_header->OptionalHeader.SizeOfImage,
		MEM_RESERVE,
		PAGE_READWRITE);

    if (code == NULL)
        code = (unsigned char *)pVirtualAlloc(NULL,
            old_header->OptionalHeader.SizeOfImage,
            MEM_RESERVE,
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

	pVirtualAlloc(code,
		old_header->OptionalHeader.SizeOfImage,
		MEM_COMMIT,
		PAGE_READWRITE);

	headers = (unsigned char *)pVirtualAlloc(code,
		old_header->OptionalHeader.SizeOfHeaders,
		MEM_COMMIT,
		PAGE_READWRITE);
	

	m_memcpy(headers, dos_header, dos_header->e_lfanew + old_header->OptionalHeader.SizeOfHeaders);
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
		if ( plstrcmpiA(name, (const char *)(codeBase + *nameRef)) == 0 )
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

