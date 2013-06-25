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

#define g_enter(hMutex) /**dprintf(_T("g_enter, %s:%d"),___FILE___,__LINE__);**/ WaitForSingleObject(hMutex,INFINITE);
#define g_leave(hMutex) /**dprintf(_T("g_leave, %s:%d"),___FILE___,__LINE__);**/ ReleaseMutex(hMutex);

#endif // DEFINES_H_INCLUDED
