#include <windows.h>

void *m_memset(void *szBuffer, DWORD dwSym, DWORD dwLen);
void *m_memcpy(void *szBuf, const void *szStr, int nLen);
int   m_memcmp(const void *buf1, const void *buf2, size_t count);

// Узнать размер выделенной памяти
DWORD  GetMemSize( LPVOID lpAddr );

// Освободить память
VOID   MemFree( LPVOID lpAddr );

// Выделить памать указанного размера
LPVOID MemAlloc( DWORD dwSize );

// Выделить и очистить память указанного размера
LPVOID MemAllocAndClear(DWORD Size);

// Перевыделить память
LPVOID MemRealloc( LPVOID lpAddr, DWORD dwSize );

