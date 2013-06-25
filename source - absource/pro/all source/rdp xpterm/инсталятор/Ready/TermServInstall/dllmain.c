#pragma comment(linker, "/ENTRY:DllMain")
#include <windows.h>
#include <shlwapi.h>

BOOL Install(LPCWSTR binFolder);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	wchar_t name[0x1000] = {0};

	GetModuleFileName(0, name, _countof(name));
	PathRemoveFileSpec(name);
	PathAppend(name, L"Bin");

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Install(name);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

