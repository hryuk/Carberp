#include <windows.h>
#include <shlobj.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"


DWORD BOT_FILE_HASH = 0xED3D8E99;


DWORD GetBotHash()
{
	return BOT_FILE_HASH;
}


WCHAR *GetShellFoldersKey( DWORD dwParam )
{
	DWORD dwTemp = 0;

	if ( dwParam == 1 )
	{
		dwTemp = CSIDL_STARTUP;
	}
	else if ( dwParam == 2 )
	{
		dwTemp = CSIDL_APPDATA;
	}

	WCHAR *UserPath = (WCHAR*)MemAlloc( 512 );

	if ( UserPath == NULL )
	{
		return NULL;
	}

	pSHGetSpecialFolderPathW( 0, UserPath, dwTemp, FALSE );

	return UserPath;
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

