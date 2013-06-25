#include <windows.h>
#include <tlhelp32.h>

#include "GetApi.h"
#include "Utils.h"

void *m_memset( void *szBuffer, DWORD dwSym, DWORD dwLen )
{
	if ( !szBuffer )
		return NULL;

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
	if ( !szBuf || !szStr || nLen <= 0 )
		return NULL;

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

DWORD GetMemSize( LPVOID lpAddr )
{
	if ( !lpAddr )
	{
		return 0;
	}

	MEMORY_BASIC_INFORMATION MemInfo;

	VirtualQuery( lpAddr, &MemInfo, sizeof( MEMORY_BASIC_INFORMATION ) );

	return MemInfo.RegionSize;
}


VOID MemFree( LPVOID lpAddr )
{
	if ( lpAddr != NULL )
		LocalFree(lpAddr);
}


LPVOID MemAlloc( DWORD dwSize )
{
	return LocalAlloc( LPTR, dwSize );
}

LPVOID MemAllocAndClear(DWORD Size)
{
	// Выделить и очистить память указанного размера
	if (Size == 0)
    	return NULL;

	void* Memory = LocalAlloc( LPTR, Size );
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

DWORD CalcHash(char *Str )
{
	if (!Str ) return -1;

	DWORD dwHash = 0;
	char *CopyStr = Str;

	while ( *CopyStr != 0)
	{
		dwHash = (( dwHash << 7 ) & (DWORD)( -1 ) ) | ( dwHash >> ( 32 - 7 ));
		dwHash = dwHash ^ ( *CopyStr );
		CopyStr++;
	}

	return dwHash;
}

DWORD CalcHashW( PWSTR str )
{
	if ( !str )
	{
		return 0;
	}

    DWORD hash = 0;
    PWSTR s = str;

    while (*s) 
    {
        hash = ((hash << 7) & (DWORD)-1) | (hash >> (32 - 7));
        hash = hash ^ *s;
        s++;
    }

    return hash;
}

wchar_t *m_wcsncpy( wchar_t *dest, wchar_t *src, unsigned long n )
{
	if ( !dest || !src )
	{
		return NULL;
	}

	for ( ULONG i = 0; i < n; i++ ) 
    {
	   dest[i] = src[i];
    }

    return dest;
}

PCHAR FindChar(PCHAR Str, char C)
{
	// Функция возвращает указатель на символ С;
	if (Str == NULL)
		return NULL;
	PCHAR Tmp = Str;
	while (*Tmp != C && *Tmp != 0) Tmp++;
	if (*Tmp == 0 && C != 0)
		Tmp = NULL;
	return Tmp;
}

wchar_t *m_wcslwr( wchar_t *Str )
{
	if ( !Str )
	{
		return NULL;
	}

    wchar_t *Pos = Str;

    while( *Str )
    {		
        if ( ( *Str >= 'A' ) && ( *Str <= 'Z' ) ) 
		{
			*Str = *Str + ('a'-'A');
		}
		Str++;
    }

    return Pos;
}

int m_atoi( const char *nptr )
{
	if ( !nptr )
		return 0;

	int c;              
	long total;         
	int sign;           
	
	while( *nptr == ' ' ) ++nptr;
	
	c = (int)(unsigned char)*nptr++;

	sign = c;

	if ( c == '-' || c == '+' )
	{
		c = (int)(unsigned char)*nptr++;
	}
	
	total = 0;
	
	while( c >= '0' && c <= '9' )
	{
		total = 10 * total + ( c - '0' );     
		c = (int)(unsigned char)*nptr++;    
	}
	
	if ( sign == '-' )
	{
		return -total;
	}
	else
	{
		return total;   
	}
}
