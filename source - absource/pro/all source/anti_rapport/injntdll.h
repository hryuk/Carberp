#ifndef _INJNTDLL_H_
#define _INJNTDLL_H_

BOOL InjnProcDllHook(LPCSTR lpProcessName, LPCSTR lpDllPath, PDWORD pdwInj);
VOID InjnProcDllUnhook();

#endif