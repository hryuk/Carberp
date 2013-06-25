#ifndef _GETAPI_H_
#define _GETAPI_H_

#include <windows.h>

#define RVATOVA( base, offset ) ( (DWORD)base + (DWORD)offset )

VOID InitializeNTDLL();

LPVOID GetApiAddr( HMODULE hModule, DWORD dwProcNameHash );
LPVOID GetProcAddressEx(PCHAR Dll, DWORD dwModule, DWORD dwProcNameHash );
//HMODULE GetDllBase( DWORD dwDllHash );
//HMODULE GetKernel32();

#endif //_GETAPI_H_
