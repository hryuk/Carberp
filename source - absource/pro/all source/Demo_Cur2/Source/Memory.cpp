#include <windows.h>

#include "GetApi.h"
#include "ntdll.h"

void *m_memset( void *szBuffer, DWORD dwSym, DWORD dwLen )
{
	if ( !szBuffer )
	{
		return NULL;
	}

	__asm
	{
		pushad
		mov		edi,[szBuffer]
		mov		ecx,[dwLen]
		mov		eax,[dwSym]
		rep		stosb
		popad
	} 

	return NULL;
} 

void *m_memcpy( void *szBuf, const void *szStr, int nLen )
{
	if ( !szBuf || !szStr )
	{
		return NULL;
	}

	__asm
	{
		pushad
		mov		esi,[szStr]
		mov		edi,[szBuf]
		mov		ecx,[nLen]
		rep		movsb
		popad
	}

	return NULL;
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



DWORD GetMemSize( LPVOID lpAddr )
{
	if ( !lpAddr )
	{
		return 0;
	}

	MEMORY_BASIC_INFORMATION MemInfo;

	pVirtualQuery( lpAddr, &MemInfo, sizeof( MEMORY_BASIC_INFORMATION ) );

	return MemInfo.RegionSize;
}


VOID MemFree( LPVOID lpAddr )
{
	if ( lpAddr != NULL )
	{
		pVirtualFree( lpAddr, 0, MEM_RELEASE );
	}
}


LPVOID MemAlloc( DWORD dwSize )
{
	LPVOID lpRet = pVirtualAlloc( 0, dwSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE );
	
	return lpRet;
}

LPVOID MemAllocAndClear(DWORD Size)
{
	// Выделить и очистить память указанного размера
	if (Size == 0)
    	return NULL;

	void* Memory = pVirtualAlloc(0, Size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	m_memset(Memory, 0, Size);

	//if (Memory != NULL)
	//{
 //   	DWORD Symbol = 0;
	//	__asm
	//	{
	//		pushad
	//		mov		edi, [Memory]
	//		mov		ecx, [Size]
	//		mov		eax, [Symbol]
	//		rep		stosb
	//		popad
	//	}
 //   }

	return Memory;
}

LPVOID MemRealloc( LPVOID lpAddr, DWORD dwSize )
{
	DWORD dwPrevLen;

	if ( lpAddr )
	{
		dwPrevLen = GetMemSize( lpAddr );

		if ( dwPrevLen >= dwSize )
		{
			return lpAddr;
		}
	}

	LPVOID NewAddr = MemAlloc(dwSize);
	if ( lpAddr && NewAddr )
	{
		m_memcpy(NewAddr, lpAddr, dwPrevLen);
		MemFree(lpAddr);
	}

	return NewAddr;
}

