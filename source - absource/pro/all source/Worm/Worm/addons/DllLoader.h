#ifndef _DLLLOADER_H_
#define _DLLLOADER_H_

#include <windows.h>

typedef void *HMEMORYMODULE;

HMEMORYMODULE MemoryLoadLibrary(const void *);
FARPROC MemoryGetProcAddress(HMEMORYMODULE, const char *);
void MemoryFreeLibrary(HMEMORYMODULE);

#endif //_DLLLOADER_H_
