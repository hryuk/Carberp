#include <windows.h>

#include "Memory.h"
#include "Strings.h"

char szTempBuf[ 100 ];

char * WINAPI Decrypt( char *string )
{
	
	m_memset( szTempBuf, 0, 100 );

	__asm
	{
		pushad
		mov		esi,[string]
		mov		edi,offset szTempBuf
	__again:
			lodsb
			test	al,al
			jz		__to_exit
			sub		al, 10h
			xor		al, 5h
			add		al, 10h
			stosb
			jmp		__again

	__to_exit:
		stosb
		popad
	} 

	char *Ret = szTempBuf;

	return Ret;
} 