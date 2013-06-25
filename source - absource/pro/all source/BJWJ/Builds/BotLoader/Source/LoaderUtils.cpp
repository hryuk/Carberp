#include "LoaderUtils.h"




// Функция расчитывает хэш строки
DWORD CalcHash(const char* Str, DWORD Len)
{
	// Функция расчитывает хэш строки
	// Str - исходная строка
	// Len - Длина строки, если равно 0, то расчитывается до конечного нуля

	if (Str == NULL) return (DWORD)-1; // Наследие Фрека

	DWORD H = 0;

	for (DWORD i = 0; *Str != 0 && (Len == 0 || i < Len); Str++, i++)
	{
		char Ch = *Str;
		H = (( H << 7 ) & (DWORD)( -1 ) ) | ( H >> ( 32 - 7 ));
		H = H ^ Ch;
	}
	return H;
}
//-----------------------------------------------------------------------------------------


DWORD XORCrypt(PCHAR Password, LPBYTE Buffer, DWORD Size, BYTE Delta)
{
	DWORD a, b;
    a = 0;
	while (a < Size)
    {
		b = 0;
		while (Password[b])
		{
			Buffer[a] ^= (Password[b] + (a * b) + Delta);
			b++;
		}
		a++;
    }

	return a;
}
//-----------------------------------------------------------------------------------------


/*
LPVOID MemAlloc( DWORD dwSize )
{
	return VirtualAlloc(0, dwSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE );
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
		VirtualFree( lpAddr, 0, MEM_RELEASE );
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


*/




HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param )
{
    DWORD lpThreadId; 
    return CreateThread( NULL, NULL, (LPTHREAD_START_ROUTINE)lpStartAddress, param, NULL, &lpThreadId );
}




