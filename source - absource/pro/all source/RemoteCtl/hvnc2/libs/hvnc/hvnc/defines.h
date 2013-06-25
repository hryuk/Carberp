#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

#define _T TEXT
#define countof(array) sizeof(array)/sizeof(array[0])

#ifdef _X86_
#define int3 _asm {int 3}
#else
#define int3
#endif

#ifdef _UNICODE
#define ___FILE___ __FILEW__
#else
#define ___FILE___ __FILE__
#endif

#define g_enter(hMutex) /**dprintf(_T("g_enter, %s:%d"),___FILE___,__LINE__);**/ WaitForSingleObject(lpServer->EventsInfo.##hMutex,10000);
#define g_leave(hMutex) /**dprintf(_T("g_leave, %s:%d"),___FILE___,__LINE__);**/ ReleaseMutex(lpServer->EventsInfo.##hMutex);


#ifdef _DEBUG
void dprintf(TCHAR *msg, ...);
void dprintf_wnd(HWND hWnd,TCHAR *lpStr=NULL);
#else
#define dprintf
#define dprintf_wnd
#endif

extern "C" void *MemAlloc(size_t dwSize);
extern "C" void *MemRealloc(void *lpMem,size_t dwSize);
extern "C" void MemFree(void *lpMem);

#endif // DEFINES_H_INCLUDED
