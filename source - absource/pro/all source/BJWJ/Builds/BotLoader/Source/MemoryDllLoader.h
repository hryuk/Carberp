

typedef void* HMEMMODULE;

bool       SaveMemLibrary(LPVOID Dll, PCHAR FileName);
HMEMMODULE LoadMemLibrary(LPVOID Buf);
void       FreeMemLibrary(HMEMMODULE Module);
LPVOID     GetMemProcAddress(HMEMMODULE Module, const char *ProcName);