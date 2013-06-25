#ifndef WINVER                          // Specifies that the minimum required platform is Windows Vista.
#define WINVER 0x0501           // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0501     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS          // Specifies that the minimum required platform is Windows 98.
#define _WIN32_WINDOWS 0x0410   // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE               // Specifies that the minimum required platform is Internet Explorer 7.0.
#define _WIN32_IE 0x0600        // Change this to the appropriate value to target other versions of IE.
#endif

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <windows.h>


void WINAPI StartTasksConnection(char* uid, const char* ip1, int port1, const char* ip2, int port2)
{
	OutputDebugString(L"Real StartTasksConnection.\r\n");
}

void WINAPI StartSend( char* uid, char* path, const char* ip1, int port1, const char* ip2, int port2 )
{
	OutputDebugString(L"Real StartSend.\r\n");
}

void WINAPI StartRecPid( char* uid, char* nameVideo, DWORD pid, const char* ip1, int port1, const char* ip2, int port2 )
{
	OutputDebugString(L"Real StartRecPid.\r\n");
}

BOOL APIENTRY DllMain( HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString(L"Real TestLib loaded.\r\n");
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

