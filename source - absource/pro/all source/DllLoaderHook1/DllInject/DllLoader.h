#include <windows.h>

typedef void *HMEMORYMODULE;

HMEMORYMODULE MemoryLoadLibrary(const void *);
FARPROC MemoryGetProcAddress(HMEMORYMODULE, const char *);
void MemoryFreeLibrary(HMEMORYMODULE);
