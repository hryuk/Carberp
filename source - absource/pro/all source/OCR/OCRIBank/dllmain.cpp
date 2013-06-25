// dllmain.cpp : Defines the entry point for the DLL application.
#include "windows.h"
#include "OCRIBank.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

void EXPORT_API Test( HWND hwnd, HINSTANCE hinst, LPCSTR lpszCmdLine, int nCmdShow )
{
#ifdef TEST
	ParseImage(lpszCmdLine);
#endif //TEST
}
