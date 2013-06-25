#include "Memory.h"
#include "GetApi.h"



void m_memset(const void* Buffer, BYTE Sym, size_t Len)
{
	if (Buffer)
	{
		volatile char *Tmp = (volatile char *)Buffer;
		while (Len)
		{
			*Tmp = Sym;
			Len--;
			Tmp++;
		}
	}

} 

void *m_memcpy( void *szBuf, const void *szStr, int nLen )
{
	if (szBuf && szStr)
	{
		volatile char *Buf = (volatile char *)szBuf;
		volatile char *Str = (volatile char *)szStr;
		while (nLen)
		{
			nLen--;
			*Buf = *Str;
			Buf++;
			Str++;
		}
	}
	return szBuf;
}


int m_memcmp( const void *buf1, const void *buf2, size_t count )
{
	if ( !buf1 || !buf2 )
	{
		return -1;
	}

	unsigned char *p1 = (unsigned char *)buf1;
	unsigned char *p2 = (unsigned char *)buf2;

	int   rc = 0;

	for ( size_t i = 0; i < count; i++ )
	{
		if( *p1 < *p2 )
		{
			rc = -1;
			break;
		}

		if( *p1 > *p2 )
		{
			rc = 1;
			break;
		}

		p1++;
		p2++;
	}

	return rc;
}

void* m_memmem( const void* mem1, int szMem1, const void* mem2, int szMem2 )
{
	const char* p1 = (const char*)mem1;
	const char* p2 = (const char*)mem2;
	while( szMem1 >= szMem2 )
	{
		if( *p1 == *p2 )
		{
			int i = 1;
			while( i < szMem2 )
				if( p1[i] != p2[i] )
					break;
				else
					i++;
			if( i >= szMem2 ) //совпало
				return (void*)p1;
		}
		p1++;
		szMem1--;
	}
	return 0;
}

DWORD GetMemSize( LPVOID lpAddr )
{
	if (!lpAddr) return 0;
		
	MEMORY_BASIC_INFORMATION MemInfo;

	pVirtualQuery( lpAddr, &MemInfo, sizeof( MEMORY_BASIC_INFORMATION ) );

	return MemInfo.RegionSize;
}


VOID MemFree( LPVOID lpAddr )
{
	if (lpAddr)
		pVirtualFree( lpAddr, 0, MEM_RELEASE );
}


LPVOID MemAlloc( DWORD dwSize )
{
	return pVirtualAlloc(0, dwSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE );
}

LPVOID MemAllocAndClear(size_t Size)
{
	// Выделить и очистить память указанного размера
	if (Size == 0) return NULL;
	LPVOID Memory = pVirtualAlloc(0, Size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	m_memset(Memory, 0, Size);

	return Memory;
}



LPVOID MemRealloc( LPVOID lpAddr, DWORD dwSize )
{
    // Изменяем размер выделенного буфера памяти
	DWORD PrevLen = 0;

	// Определяем размер предыдущего блока
	if ( lpAddr )
		PrevLen = GetMemSize(lpAddr);

	//  Создаём новый буфер
	LPVOID NewAddr = NULL;
	if (dwSize > 0)
	{
		NewAddr = MemAlloc(dwSize);
		if (lpAddr && NewAddr && PrevLen)
		{
            // Копируем старую память
			if (dwSize < PrevLen)
            	PrevLen = dwSize;
			m_memcpy(NewAddr, lpAddr, PrevLen);
		}
	}

	if (lpAddr != NULL)
		MemFree(lpAddr);

	return NewAddr;
}

//-----------------------------------------------------------------------------

LPVOID HEAP::Alloc(DWORD Size)
{
	if (Size == 0) return NULL;

	LPVOID Buf = pHeapAlloc((HANDLE)pGetProcessHeap(), 0, Size);
    m_memset(Buf, 0, Size);
	return Buf;
}

LPVOID HEAP::ReAlloc(LPVOID Buf, DWORD Size)
{
	// Переопределяем блок памяти

	if (Buf == NULL)
		return HEAP::Alloc(Size);

    LPVOID Res = NULL;
	HANDLE Heap = pGetProcessHeap();
	if (Heap != NULL)
	{
		Res = pHeapReAlloc(Heap, 0, Buf, Size);
	}
	return Res;
}

bool HEAP::ReAlloc2(LPVOID &Buf, DWORD Size)
{
	LPVOID NewBuf = HEAP::ReAlloc(Buf, Size);
	if (NewBuf != NULL)
	{
		Buf = NewBuf;
		return true;
	}
	else
		return false;
}


void HEAP::Free(LPVOID Buf)
{
	// Освобождаем выделенную память

	if (Buf == NULL) return;

	HANDLE Heap = pGetProcessHeap();
	if (Heap)
		pHeapFree(Heap, 0, Buf);
}

void HEAP::Free2(LPVOID &Buf)
{
	// Освободить память и обнулить переменную
	if (Buf != NULL)
	{
		HEAP::Free(Buf);
		Buf = NULL;
	}
}

DWORD HEAP::Size(LPVOID Buf)
{
	if (!Buf) return 0;

	return (int)pHeapSize((HANDLE)pGetProcessHeap(), 0, Buf);
}

