#include <windows.h>

#include "Getapi.h"
#include "ntdll.h"
#include "Utils.h"
#include "dllloader.h"


PVOID ImageNtdll;		// База нтдлл

//
//	CallBack для перечесления модулей.
//
VOID NTAPI LdrEnumCallBack ( IN PLDR_DATA_TABLE_ENTRY DataTableEntry,IN PVOID Context, IN OUT BOOLEAN *StopEnumeration )
{
	struct CONTEXT_LDR_ENUM
	{
		DWORD DllHash;
		BOOL  IsValid;
		LDR_DATA_TABLE_ENTRY LdrEntry;
	};

	WCHAR wcDllName[MAX_PATH];
	CONTEXT_LDR_ENUM	*pctxldr_enum = (CONTEXT_LDR_ENUM*)Context;

	if ( pctxldr_enum == NULL )
	{
		*StopEnumeration = TRUE;
		return ;
	}

	wcDllName[ DataTableEntry->BaseDllName.Length / sizeof( WCHAR )] = 0;

    m_wcsncpy( wcDllName, DataTableEntry->BaseDllName.Buffer,  MAX_PATH - 1 );

    if ( CalcHashW( m_wcslwr( wcDllName ) ) == pctxldr_enum->DllHash )
	{
		m_memcpy(&pctxldr_enum->LdrEntry,DataTableEntry,sizeof(LDR_DATA_TABLE_ENTRY));
		pctxldr_enum->IsValid = TRUE;
		*StopEnumeration = TRUE;
    }
}

HMODULE GetDllBase( DWORD dwDllHash )
{   
	struct CONTEXT_LDR_ENUM
	{
		DWORD DllHash;
		BOOL  IsValid;
		LDR_DATA_TABLE_ENTRY LdrEntry;
	};

	CONTEXT_LDR_ENUM	ctxldr_enum;
	ctxldr_enum.DllHash = dwDllHash;

	NTSTATUS (NTAPI*LdrEnumerateLoadedModules)(ULONG,PVOID/*CallBack*/,PVOID/*Context*/) = (NTSTATUS (NTAPI*)(ULONG,PVOID,PVOID))GetApiAddr((HMODULE)ImageNtdll,0xBF639C5E);
	
	if ( LdrEnumerateLoadedModules )
	{
		ctxldr_enum.IsValid = FALSE;
		LdrEnumerateLoadedModules(0,LdrEnumCallBack,&ctxldr_enum);
		if ( ctxldr_enum.IsValid )
			return (HMODULE)ctxldr_enum.LdrEntry.DllBase;
	}
	return NULL;
}

HMODULE GetDllBaseByPEB( DWORD dwDllHash )
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

        m_wcsncpy( wcDllName, LdrData->BaseDllName.Buffer, MAX_PATH - 1 );

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

	PCHAR NameStr = FindChar(Name, '.');
	if (NameStr == NULL)
		return NULL;

	// Собираем имя библиотеки
	m_memcpy(DLLName, Name, NameStr - Name);

	lstrcatA( DLLName, ".dll" );

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

BOOL InitializeImportCurrentModule();

BOOL IsImagePE(PVOID Image)
{
	PIMAGE_NT_HEADERS   pNtHeader =(PIMAGE_NT_HEADERS)((PCHAR)Image +((PIMAGE_DOS_HEADER)Image)->e_lfanew);

	if ( ((PIMAGE_DOS_HEADER)Image)->e_magic != IMAGE_DOS_SIGNATURE )
		return FALSE;

	if ( pNtHeader->Signature != IMAGE_NT_SIGNATURE )
		return FALSE;

	if (  pNtHeader->FileHeader.Characteristics & IMAGE_FILE_32BIT_MACHINE )
		return TRUE;

	return FALSE;
}


VOID InitializeNTDLL()
{
	ImageNtdll = GetDllBaseByPEB(0xab30a50a);
	return ;
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

LPVOID GetProcAddressEx(PCHAR Dll, DWORD dwModule, DWORD dwProcNameHash )
{

	HMODULE Module = NULL;


	PCHAR DllName = Dll;

	// Адрес библиотеки ядра, получаем отдельно
	if (Dll == NULL) return 0;

	Module = (HMODULE)GetModuleHandleA(Dll);
	if( Module == NULL )
		Module = (HMODULE)LoadLibraryA(Dll);

	if (dwProcNameHash == 0)
		return Module;

	LPVOID ret = GetApiAddr(Module, dwProcNameHash);

	if ( ret == NULL )
		return (LPVOID)0x00000000;

	return ret;
}
