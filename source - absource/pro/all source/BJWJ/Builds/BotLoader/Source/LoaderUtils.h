#ifndef LoaderUtilsH
#define LoaderUtilsH
//----------------------------------------------------------------------------------------------------
#include <windows.h>

LPVOID MemAlloc(DWORD dwSize);
LPVOID MemRealloc(LPVOID lpAddr, DWORD dwSize );
VOID   MemFree(LPVOID lpAddr);

void *m_memset(void *szBuffer, DWORD dwSym, DWORD dwLen);
void *m_memcpy(void *szBuf, const void *szStr, int nLen);


#define CreateStruct(T) (T*)MemAlloc(sizeof(T))
#define FreeStruct(S) MemFree(S)
#define ClearStruct(S) m_memset(&S, 0, sizeof(S))



DWORD CalcHash(const char* Str, DWORD Len = 0);

DWORD XORCrypt(PCHAR Password, LPBYTE Buffer, DWORD Size, BYTE Delta = 0);



HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param );


//----------------------------------------------------------------------------------------------------
#endif