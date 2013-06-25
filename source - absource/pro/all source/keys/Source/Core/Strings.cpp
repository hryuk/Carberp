#include <windows.h>

#include "Memory.h"
#include "GetApi.h"
#include "Strings.h"
#include "BotClasses.h"

void DbgMsg(char *file, int line, char *msg, ...)
{
	char *buff  = (char*)MemAlloc( 1024 );
	char *obuff = (char*)MemAlloc( 1024 );
	va_list mylist;

	va_start(mylist, msg);
	pwvsprintfA(buff, msg, mylist);
	va_end(mylist);

	wsprintfA(obuff, "%s(%d) : %s", file, line, buff);

	pOutputDebugStringA(obuff);
}

void DbgMsgW(WCHAR *file, int line, WCHAR *msg, ...)
{
	WCHAR *buff  = (WCHAR*)MemAlloc( 1024 );
	WCHAR *obuff = (WCHAR*)MemAlloc( 1024 );
	va_list mylist;

	va_start(mylist, msg);
	wvsprintfW(buff, msg, mylist);	
	va_end(mylist);

	wsprintfW(obuff, L"%s(%d) : %s", file, line, buff);

	pOutputDebugStringW(obuff);
}

void AlertError( LPTSTR lpszFunction ) 
{ 
/*	LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
	DWORD dw = pGetLastError();

    FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
        0, NULL );

	// Display the error message and exit the process

	lpDisplayBuf = (LPVOID)pLocalAlloc(LMEM_ZEROINIT,
        (lstrlen((LPCTSTR)lpMsgBuf)+lstrlen((LPCTSTR)lpszFunction)+40)*sizeof(TCHAR));
    wsprintfA((LPTSTR)lpDisplayBuf, "%s failed with error %d: %s", lpszFunction, dw, lpMsgBuf); 
    OutputDebugStringA( (char*)lpDisplayBuf ); 

	pLocalFree(lpMsgBuf);
	pLocalFree(lpDisplayBuf);*/
}


DWORD WINAPI m_lstrncmp( const char *szstr1, const char *szstr2, int nlen )
{
	if ( !szstr1 || !szstr2 )
		return -1;

	DWORD dwReturn;

	__asm
	{
		pushad
		mov		esi,[szstr1]
		mov		edi,[szstr2]
		mov		ecx,[nlen]
		repe	cmpsb
		jz		__true
	__false:
		xor		eax,eax
		inc		eax
		jmp		__to_exit
	__true:
		cmp byte ptr [edi],0
		jnz		__false	
		xor		eax,eax
	__to_exit:
		mov		[dwReturn],eax
		popad
	} 	
	
	return dwReturn;
} 

DWORD WINAPI m_lstrlen( char *szPointer )
{
	if ( !szPointer )
	{
		return 0;
	}

	DWORD iCounter;

	__asm
	{
		pushad
		xor		ecx,ecx
		mov		esi,[szPointer]
	__again:
		lodsb
		test	al,al
		jz		__to_exit
		inc		ecx
		jmp		__again
	__to_exit:
		mov		[iCounter], ecx
		popad
	}

	return iCounter;
} 


void WINAPI m_lstrcat( char *szBuf, const char *szStr )
{
	if ( !szBuf || !szStr )
	{
		return;
	}

	__asm
	{
		pushad
		mov		esi,[szBuf]
	__again:
		lodsb
		test	al,al
		jnz		__again

		dec		esi
		xchg	esi,edi
		mov		esi,[szStr]
	__copy:
		lodsb
		test	al,al
		stosb
		jnz		__copy
		popad
	} 
} 

void WINAPI m_lwcscat( WCHAR *szBuf, const WCHAR *szStr )
{
	if ( !szBuf || !szStr )
	{
		return;
	}

	__asm
	{
		pushad
		mov		esi,[szBuf]
	__again:
		lodsb
		test	al,al
		jnz		__again

		dec		esi
		xchg	esi,edi
		mov		esi,[szStr]
	__copy:
		lodsb
		test	al,al
		stosb
		jnz		__copy
		popad
	} 
} 


DWORD WINAPI m_lstrcmp( const char *szStr1, const char *szStr2 )
{
	if (szStr1 == NULL || szStr2 == NULL)
	{
		return -1;
	}

	DWORD dwReturn;

	__asm
	{
		pushad
		mov		esi,[szStr1]
		mov		edi,[szStr2]
	__copy:
		cmp byte ptr [esi],0
		jz		__true
		cmpsb
		jz		__copy
	__false:
		xor		eax,eax
		inc		eax
		jmp		__to_exit
	__true:
		cmp byte ptr [edi],0
		jnz		__false	
		xor		eax,eax
	__to_exit:
		mov		[dwReturn],eax
		popad
	} 
	
	return dwReturn;
} 


void WINAPI m_lstrcpy( char *szBuf, const char *szStr )
{
	if ( !szBuf || !szStr )
	{
		return;
	}

	__asm
	{
		pushad
		mov		esi,[szStr]
		mov		edi,[szBuf]
	__copy:
		lodsb
		test	al,al
		stosb
		jnz		__copy
		popad
	} 
} 


void WINAPI m_lstrlwr( char *str )
{
	if ( !str )
	{
		return;
	}

	int n = m_lstrlen( str );
	
	for(int i = 0; i < n; i++ )
	{
		if ( str[i] >= 65 && str[i] <= 90 )
		{
			str[i] += 32;
		}
	}
}


bool WINAPI m_lstrncpy( char *pString_src, const char *pString_dst, DWORD len )
{
	if ( !pString_dst || !pString_src )
	{
		return false;
	}

	if ( m_lstrlen( (char*)pString_dst ) < len )
	{
		len = m_lstrlen( (char*)pString_dst );
	}

	for ( DWORD i = 0; i < len; i++ )
	{
		pString_src[i] = pString_dst[i];
	}

	return true;
}


char * WINAPI m_strtok_s( char *String, const char *Control, char **Context )
{
    char *token;
    const char *ctl;

    if ( !String )
    {
        String = *Context;
    }

    for ( ; *String != 0 ; String++ )
    {
        for ( ctl = Control; *ctl != 0 && *ctl != *String; ctl++ );

        if ( *ctl == 0 )
        {
            break;
        }
    }
    
	token = String;

    for ( ; *String != 0 ; String++)
    {
        for ( ctl = Control; *ctl != 0 && *ctl != *String; ctl++ );

        if ( *ctl != 0 )
        {
            *String++ = 0;
            break;
        }
    }
    
	*Context = String;

    if ( token == String )
    {
        return NULL;
    }
    else
    {
        return token;
    }
}


int WINAPI m_isspace( char x )
{
	return ( x == ' ' );
}


int WINAPI  m_isdigit( char x )
{
	return ( ( x >= '0' ) && ( x <= '9' ) );
}


long WINAPI m_atol( const char *nptr )
{
	if ( !nptr )
		return 0;

	int c;              
	long total;         
	int sign;           
	
	while ( m_isspace( (int)(unsigned char)*nptr ) )
	{
		++nptr;
	}
	
	c = (int)(unsigned char)*nptr++;

	sign = c;

	if ( c == '-' || c == '+' )
	{
		c = (int)(unsigned char)*nptr++;
	}
	
	total = 0;
	
	while ( m_isdigit( c ) )
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


int m_atoi( const char *nptr )
{
	return (int)m_atol(nptr);
}

char * WINAPI m_strstr( const char * _Str, const char * _SubStr )
{
	if( !_Str || !_SubStr )
		return NULL;

	int f = 1;
	int s;

	size_t sslen = m_lstrlen( (char*)_SubStr );

	for ( char* p = (char*)_Str; f;  p++ )
	{
		char* k = (char*)_SubStr;

		if ( *p == 0 )
		{
			break;
		}

		if ( *k == 0 )
		{
			break;
		}

		if ( *p == *k )
		{
			char* p1 = p;
			char* k1 = k;

			s = 0;

			for( ; true;  )
			{
				if( *p1 == *k1 )
				{
					s++;
				}

				if( s == (int)sslen )
				{
					return p;
				}

				if( *p1 != *k1 )
				{
					break;
				}

				p1++;
				k1++;
			}

		}
	}

	return NULL;
}

int WINAPI m_istrstr( const char * _Str, const char * _SubStr )
{
	// Функция ищет подстроку _SubStr в строке _Str
	if( !_Str || !_SubStr )
		return -1;

	DWORD s;
	DWORD j = 0;

   //	size_t slen  = m_lstrlen( (char*)_Str );
	size_t sslen = m_lstrlen( (char*)_SubStr );

	// Проходим циклом до конца строки
	char *p = (char*)_Str;
	while (*p != 0)
	{
		char* k = (char*)_SubStr;

		// сравниваем первые символы
		if ( *p == *k )
		{
			char* p1 = p;
			char* k1 = k;

			s = 0;
            // Определяем количество совпадений
			while(*p1 != 0 && *k1 != 0)
			{
				if (*p1 == *k1)
					s++;
				else
					break;

				if (s == (DWORD)sslen)
					return j;

				p1++;
				k1++;
			}
		}

		// смещаем указатели
		p++;
		j++;
	}
	return -1;
}

//char* WINAPI ToAnsiEx( LPCWSTR String, DWORD dwSize )
//{
//	if ( !String) return NULL;
//
//	int l = (int)pWideCharToMultiByte ( CP_ACP, 0, String, dwSize, 0, 0, NULL, NULL);
//	char *r = (char*)MemAlloc( l + 1 );
//
//	pWideCharToMultiByte(1251, 0, String, dwSize, r, l, NULL, NULL );
//
//	return r;
//}
//
//char* WINAPI ToAnsi(LPCWSTR String)
//{
//	if ( !String) return NULL;
//
//	int l = (int)pWideCharToMultiByte ( CP_ACP, 0, String, -1, 0, 0, NULL, NULL);
//	char *r = (char*)MemAlloc( l + 1 );
//
//	pWideCharToMultiByte(1251, 0, String, -1, r, l, NULL, NULL);
//
//	return r;
//}


WCHAR *AnsiToUnicode( char *AnsiString, DWORD dwStrLen )
{
	if ( !AnsiString )
	{
		return NULL;
	}

	WCHAR *pszwString = (WCHAR *)MemAlloc(  dwStrLen + 1 );

	if ( pszwString == NULL )
	{
		return NULL;
	}

	pMultiByteToWideChar( CP_ACP, 0, AnsiString, dwStrLen, (LPWSTR)pszwString, dwStrLen + 1 );

	return  pszwString;
}


DWORD WINAPI m_wcslen( const wchar_t *String )
{
	if ( !String )
	{
		return 0;
	}

	wchar_t* p = (wchar_t *)String;

	for( ; *p != 0; )
	{
		p++;
	}

	return p - String;
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

bool m_wcsncmp( WCHAR *s1, WCHAR *s2, size_t iMaxLen )
{
	if ( !s1 || !s2 )
	{
		return false;
	}

	for ( size_t i = 0; i < iMaxLen; i++ )
	{
		if ( !s1[i] || !s2[i] )
		{
			return true;
		}

		if ( s1[i] != s2[i] )
		{
			return true;
		}
	}

	return false;
}

wchar_t *m_wcslwr( wchar_t *Str )
{
	if ( !Str )
	{
		return NULL;
	}

    wchar_t *Pos = Str;

    for ( ; Str <= ( Pos + m_wcslen( Pos ) ); Str++ )
    {		
        if ( ( *Str >= 'A' ) && ( *Str <= 'Z' ) ) 
		{
			*Str = *Str + ('a'-'A');
		}
    }

    return Pos;
}

bool WildCmp( char *Buffer, char *Mask, LPDWORD dwStart, LPDWORD dwEnd, LPDWORD dwLen )
{
	// Фуекция ищет в строке подстроку.
	// подстрока может содержать символ, маску *
	if ( !Buffer || !Mask )
		return false;

	char *TempMaskBuf = STR::New(Mask);
	char *TempMask = TempMaskBuf;

	if ( TempMask == NULL )
		return false;


	char **Args = (char**)MemAlloc( sizeof( char* ) * 255 );

	if (Args == NULL)
	{
		return false;
        STR::Free(TempMaskBuf);
	}

	// Разбиваем подстроку на аргументы между *
	DWORD ArgsCount = 0;

	char *Context;

	char *p = m_strtok_s( TempMask, "*", &Context );

	DWORD i = 0;
	
	for ( i = 0; p; p = m_strtok_s( NULL, "*", &Context ), i++ )
	{
		Args[i] = p;
		ArgsCount++;
	}		


	if ( ArgsCount == 1 )
	{
		//  масок нет, просто ищем вхождение подстроки
		DWORD Start = m_istrstr( Buffer, Mask );

		if ( Start != -1 )
		{
			*dwStart = Start;
			*dwEnd   = Start + m_lstrlen( Mask );
			*dwLen	 = m_lstrlen( Mask );

			MemFree(Args);
			STR::Free(TempMaskBuf);
			return true;
		}
	}

    // Сравниваем с учётом масок

	int Start = m_istrstr( Buffer, Args[0] );

	if ( Start != -1 )
	{
		DWORD dwJump = 0;
		DWORD End    = Start;

		i = 1;

		while ( ( dwJump = m_istrstr( Buffer + End, Args[i] ) ) != -1 )
		{
			End += dwJump;
			i++;
		}

		End += m_lstrlen( Args[ i - 1 ] );

		if ( ArgsCount != i )
		{
			STR::Free(TempMaskBuf);
            MemFree(Args);
			return false;
		}

		*dwStart = Start;
		*dwEnd	 = End;
		*dwLen   = End - Start;

		STR::Free(TempMaskBuf);
		MemFree( Args );
		return true;
	}

	STR::Free(TempMaskBuf);
	MemFree(Args);
	return false;
}

bool WildCmp(PCHAR Buffer, PCHAR Mask)
{
	DWORD S;
	DWORD E;
	DWORD L;
	return WildCmp(Buffer, Mask, &S, &E, &L);
}

bool CompareUrl( char *MaskUrl, char *Url )
{
	DWORD dwStart = 0;
	DWORD dwEnd	  = 0;
	DWORD dwLen	  = 0;

	if (WildCmp( Url, MaskUrl, &dwStart, &dwEnd, &dwLen ) )
	{
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
PCHAR GetTextBetween(PCHAR &Buffer, PCHAR Before, PCHAR After )
{
    // метод возвращает кусок HTML кода между блоками Before и After
	if (STR::IsEmpty(Before) || STR::IsEmpty(After))
		return NULL;

	DWORD Start = 0;
	DWORD End   = 0;
	DWORD Len   = 0;

	if (WildCmp(Buffer, Before, &Start, &End, &Len ))
	{
		PCHAR StartPtr = Buffer + End;
		if (WildCmp(StartPtr, After, &Start, &End, &Len ) )
		{
			PCHAR EndPtr = StartPtr + Start;
			// Смещаем указатель буфера на позицию за найденным текстом
			Buffer = EndPtr;

			DWORD Size = EndPtr - StartPtr;
			if (Size > 0)
				return STR::New(StartPtr, Size);
		}
	}
	return NULL;
}

//-----------------------------------------------------------------------------

namespace STRHEAD
{
	#pragma pack(push, 1)
	typedef struct THead
	{
		DWORD Signature;
		DWORD BufSize;
		DWORD Length;
	} *PHead;
	#pragma pack(pop)

	const DWORD HeadSize = sizeof(THead);
	#define StrSignature 0x54534D53 /* "SMST" */

	LPBYTE MakeHead(LPBYTE Buf, DWORD BufSize, DWORD Length, BYTE CharSize = 1)
	{
		// инициализировать заголовок строки
		LPBYTE Res = Buf + HeadSize;
		PHead H = (PHead)Buf;

		H->Signature = StrSignature;
		H->BufSize = BufSize;
		H->Length = Length;

		m_memset((Res + Length*CharSize), 0, CharSize);
		return Res;
	}

	#define StrHead(Str) ( (PHead)((LPBYTE)Str - HeadSize))

	//------------------------------------------------------------------------
	bool CheckSignature(LPVOID Str)
	{
		if (Str == NULL) return false;
		return StrHead(Str)->Signature == StrSignature;
    }
	//------------------------------------------------------------------------
	#define SetBufferSize(Str, Value) (StrHead(Str)->BufSize = Value)

	DWORD inline GetBufferSize(PCHAR Str)
	{
		return StrHead(Str)->BufSize;
	}

	DWORD inline GetLength(PCHAR Str)
	{
    	return StrHead(Str)->Length;
	}

	void inline SetLength(PCHAR Str,DWORD Length)
	{
		StrHead(Str)->Length = Length;
		*(Str + Length) = 0;
    }
	//------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

PCHAR STR::Alloc(DWORD StrLen)
{
	// Выделяет в памяти блок под строку размером StrLen. Блок памяти будет
	// иметь размер StrLen + 1 (плюс размер заголовков)

	if (StrLen == 0) return NULL;

	PCHAR Str = (PCHAR)HEAP::Alloc(StrLen + STRHEAD::HeadSize + 1);
	if (Str == NULL) return NULL;

	return (PCHAR)STRHEAD::MakeHead((LPBYTE)Str, StrLen, StrLen);
}

//------------------------------------------------------------------------------

DWORD StrCalcLength(char *Buf)
{
	// Функция расчитывает длину строки проходя по ней в поисках
	// нулевого символа
	if (Buf == NULL)
		return 0;

	DWORD Counter = 0;

	__asm
	{
		pushad
		xor		ecx, ecx
		mov		esi, [Buf]
	__again:
		lodsb
		test	al,al
		jz		__to_exit
		inc		ecx
		jmp		__again
	__to_exit:
		mov		[Counter], ecx
		popad
	}

	return Counter;
}
//------------------------------------------------------------------------------

PCHAR STR::New(PCHAR Source, DWORD Len)
{
	// Функция создаёт строку, копию Source.
	// Len - Количество копируемых символов
	//       если равно 0, то будет скопирована вся строка

	if (Source == NULL) return NULL;

	if (Len == 0) Len = StrCalcLength(Source);
	if (Len == 0) return NULL;

	PCHAR Str = STR::Alloc(Len);
	if (Str != NULL)
		m_memcpy(Str, Source, Len);

	return Str;
}
//------------------------------------------------------------------------------

void STR::Free(PCHAR Str)
{
    // Уничтожить строку.
	// Важно!!! Строка должна быть создана с помощью функции STR::New
    if (STRHEAD::CheckSignature(Str))
		HEAP::Free(Str - STRHEAD::HeadSize);
}

void STR::Free2(PCHAR &Str)
{
	// Уничтожить строку и обнулить переменную
	STR::Free(Str);
	Str = NULL;
}
//------------------------------------------------------------------------------


DWORD STR::Length(PCHAR Str)
{
	// Функция возвращает длину строки.
	// Если строка создавалась с помощью функции STR::New то размер
	// получается из заголовка строки в противном случае размер расчитывается.

	if (Str == NULL)
		return 0;

	if (STRHEAD::CheckSignature(Str))
		return STRHEAD::GetLength(Str);
	else
		return StrCalcLength(Str);

}
//------------------------------------------------------------------------------

void STR::UpdateLength(PCHAR Str, DWORD RealLength)
{
	// Обновляет значение длины строки в её заголовоке.
	// !!!!Только для строк созданных через STR::Alloc (STR::New)
	// Если значение RealLength не указано то новая длина
	// расчитывается до нулевого символа
	if (!STRHEAD::CheckSignature(Str)) return;
	if (RealLength == 0)
		RealLength = StrCalcLength(Str);
    STRHEAD::SetLength(Str, RealLength);
}

//------------------------------------------------------------------------------

void STR::Delete(PCHAR Str, DWORD Position, DWORD Count, DWORD StrLength)
{
	// Удаляет Count символов с позоции Position строки Str
	if (STR::IsEmpty(Str) || Count == 0)
		return;

	DWORD Len = StrLength;
	if (Len == 0)
		Len = StrCalcLength(Str);
	if (Position > Len) return;
	if (Count > Len - Position)
	{
		Count = Len - Position;
		if (Count == 0) return;
	}

	PCHAR Ptr = Str + Position;
	PCHAR FromPTR = Ptr + Count;
	m_memcpy(Ptr, FromPTR, Len - (Position + Count));
	Ptr = Str + (Len - Count);
	*Ptr = 0;
}
//------------------------------------------------------------------------------

PCHAR STR::Replace(PCHAR Str, PCHAR SrcStr, PCHAR DstStr, DWORD StrLen)
{
	//  Функция заменяет в строке Str строку SrcStr на
	//  строку DstStr.
	//  В случае успеха функция возвращает новую строку

	if (STR::IsEmpty(Str) || STR::IsEmpty(SrcStr)) return NULL;

	int P = Pos(Str, SrcStr, StrLen);
	if (P < 0) return NULL;

	DWORD SrcLen = StrCalcLength(SrcStr);
	DWORD DstLen = StrCalcLength(DstStr);
	if (StrLen == 0)
		StrLen = StrCalcLength(Str);

	DWORD NewLen = StrLen + (DstLen - SrcLen);

	// Создаём новую строку
	PCHAR Result = STR::Alloc(NewLen);
	if (Result == NULL) return NULL;

	Copy(Str, Result, 0, P);
	Copy(DstStr, Result + P, 0, DstLen);
	Copy(Str + P + SrcLen, Result + P + DstLen, 0, StrLen - (P + SrcLen));

	return Result;
}
//------------------------------------------------------------------------------

void StrSetLength(PCHAR &Str, DWORD NewLength)
{
	// Изменить размер буфера строки
	// Важно!!! Функция работает со строками которые созданы функцией STR::New

	// Для переопределения длины строки, мы создадим новую строку с нужным
	// размером и скопируем в неё старую.

	if (!STRHEAD::CheckSignature(Str) || STRHEAD::GetBufferSize(Str) == NewLength)
		return;

	PCHAR New = STR::Alloc(NewLength);
	DWORD Size = STRHEAD::GetLength(Str);
	if (NewLength < Size)
		Size = NewLength;
	m_memcpy(New, Str, Size);
	STRHEAD::SetLength(New, Size);
	STR::Free(Str);
	Str = New;
}
//------------------------------------------------------------------------------

bool STR::IsEmpty(PCHAR Str)
{
	// Функция возвращает истину если на входе нулевой указатель либо
	// пустая строка
	return (Str == NULL || *Str == 0);
}
//------------------------------------------------------------------------------


PCHAR StrLongToString(DWORD num)
{
	if (num == 0)
		return STR::New("0");
	int i = 1;
	int d = 0;
	int n = 0;
	for (int j = 1; num/j!=0; j*=10) { n++; }
	char* Str = STR::Alloc(n);
	do
	{
		d = num % 10;
		num /= 10;
		Str[n-i]=(char)(d+48);
		i++;
	}
	while(num != 0);
	STRHEAD::SetLength(Str, n);
	return Str;
}


void StrConcat(PCHAR &Str1, PCHAR Str2)
{
	// Объеденяем две строки
	DWORD Str2Len = StrCalcLength(Str2);
	if (!STRHEAD::CheckSignature(Str1) || Str2Len == 0)
		return;
	DWORD Str1Len = StrCalcLength(Str1);

	DWORD NewLength = Str1Len + Str2Len;
    if (STRHEAD::GetBufferSize(Str1) < NewLength)
		StrSetLength(Str1, NewLength);

	PCHAR Tmp = Str1 + Str1Len;
	m_memcpy(Tmp, Str2, Str2Len);
	STRHEAD::SetLength(Str1, NewLength);
}

//------------------------------------------------------------------------------
void StrConcatArguments(PCHAR &OutStr, DWORD Count, PCHAR *First)
{
	//  Функция объеденяет две и более строки.

	const DWORD MaxCount = 50;

    if (Count >= MaxCount) return;

	DWORD Lens[MaxCount];
	PCHAR *Current = First;
	DWORD FullLen = StrCalcLength(OutStr);
	Lens[0] = FullLen;

	// Расчитываем общую длину строки
	for (DWORD i = 1; i <= Count; i++)
	{
		DWORD Len = StrCalcLength(*Current);
		Lens[i] = Len;
		FullLen += Len;
		Current++;
	}

	// Добавляемые строки нулевой длины
	if (FullLen == 0) return;

	// Меняем размер буфера
	if (OutStr != NULL)
		StrSetLength(OutStr, FullLen);
	else
        OutStr = STR::Alloc(FullLen);

	// Собираем строку
	Current = First;
	PCHAR Tmp = OutStr + Lens[0];
	Current = First;
	for (DWORD i = 1; i <= Count; i++)
	{
	    m_memcpy(Tmp, *Current, Lens[i]);
        Tmp += Lens[i];
    	Current++;
	}
}

//------------------------------------------------------------------------------

PCHAR STR::New(DWORD Count, PCHAR Str...)
{
	// Функция создаёт строку объеденив несколько строк
	PCHAR Result = NULL;
	PCHAR *First = &Str;

	StrConcatArguments(Result, Count, First);

	return Result;
}

//------------------------------------------------------------------------------

void STR::Copy(PCHAR Source, PCHAR Destination, DWORD Position, DWORD Count)
{
	// Копирует с позиции Position строки Source Count символов в
	// строку Destination
	if (Source == NULL || Destination == NULL)
		return;
	m_memcpy(Destination, Source + Position, Count);
}
//------------------------------------------------------------------------------

void StrConcat(PCHAR &Str1, DWORD Count, PCHAR Str2...)
{
	//  Функция объеденяет две и более строки.
	//  если размер буфера строки Str1 меньше необходимого,
	//  то строка Str1 будет переопределена
	if (Str2 == NULL)
		return;
	if ((Str1 != NULL) && !STRHEAD::CheckSignature(Str1))
    	return;

	PCHAR *Args = &Str2;
	StrConcatArguments(Str1, Count, Args);
}
//------------------------------------------------------------------------------
bool StrCopy(PCHAR Dest, PCHAR Source, bool UpdateLen)
{
	// функция копирует строку Source в строку Dest
	// Флаг UpdateLen использовать только если Dest создана функциями
	// StrAlloc, STR::New
	// Возвращает истину если скопирован хотя-бы один байт

	if (Dest == NULL || Source == NULL)
		return false;

	DWORD Len = StrCalcLength(Source);
	m_memcpy(Dest, Source, Len);
	if (UpdateLen)
		STRHEAD::SetLength(Dest, Len);
	else
		*(Dest + Len) = 0;

 	return Len > 0;
}

//------------------------------------------------------------------------------

int StrCompare(PCHAR Str1, PCHAR Str2)
{
    // Сравнить две строки
	if (Str1 == NULL || Str2 == NULL)
		return -1;


	DWORD dwReturn;

	__asm
	{
		pushad
		mov		esi,[Str1]
		mov		edi,[Str2]
	__copy:
		cmp byte ptr [esi],0
		jz		__true
		cmpsb
		jz		__copy
	__false:
		xor		eax,eax
		inc		eax
		jmp		__to_exit
	__true:
		cmp byte ptr [edi],0
		jnz		__false
		xor		eax,eax
	__to_exit:
		mov		[dwReturn],eax
		popad
	}

	return dwReturn;
}

//------------------------------------------------------------------------------
PCHAR STR::Scan(PCHAR Str, char C)
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
//------------------------------------------------------------------------------

PCHAR STR::ScanEnd(PCHAR Str, char C)
{
	// Функция возвращает указатель на последний символ С
	if (Str == NULL)
		return NULL;

	PCHAR Res = NULL;

	for (PCHAR Tmp = Str; *Tmp != 0; Tmp++)
		if (*Tmp == C) Res = Tmp;

	return Res;
}
//------------------------------------------------------------------------------

PCHAR STR::End(PCHAR Str)
{
	// Функция возвращает указатель на заверщающий ноль строки
	if (Str != NULL)
		for (; *Str != 0; Str++);
	return Str;
}
//------------------------------------------------------------------------------

inline bool IsStrEnd(PCHAR Str, DWORD Len, DWORD Pos)
{
	if (Len != 0)
		return Pos >= Len;
	else
        return *Str == 0;
}

int STR::Pos(PCHAR Str, PCHAR SubStr, DWORD StrLen)
{
	// Функция ищет подстроку _SubStr в строке _Str
	if( !Str || !SubStr )
		return -1;

	DWORD s;
	DWORD j = 0;

   //	DWORD slen  = StrCalcLength(Str);
	DWORD sslen = StrCalcLength(SubStr);
	DWORD Pos = 0;
	DWORD Pos1 = 0;
	// Проходим циклом до конца строки
	PCHAR p = Str;
	while (!IsStrEnd(p, StrLen, Pos))
	{
		PCHAR k = SubStr;

		// сравниваем первые символы
		if ( *p == *k )
		{
			char* p1 = p;
			char* k1 = k;
			Pos1 = Pos;
			s = 0;
			// Определяем количество совпадений
			while(!IsStrEnd(p1, StrLen, Pos1) && *k1 != 0)
			{
				if (*p1 == *k1)
					s++;
				else
					break;

				if (s == (DWORD)sslen)
					return j;

				p1++;
				k1++;
				Pos1++;
			}
		}

		// смещаем указатели
		Pos++;
		p++;
		j++;
	}
	return -1;
}
//------------------------------------------------------------------------------

PCHAR STR::GetLeftStr(PCHAR Str, PCHAR SubStr, bool IncludeSubStr)
{
	// Получить строку слева
	int Pos = STR::Pos(Str, SubStr);
	if (Pos < 0)
		return NULL;
	if (IncludeSubStr)
		Pos += StrCalcLength(SubStr);
	return STR::New(Str, Pos);
}
//------------------------------------------------------------------------------

PCHAR STR::GetRightStr(PCHAR Str, PCHAR SubStr, bool IncludeSubStr)
{
	// Получить строку справа
	int Pos = STR::Pos(Str, SubStr);
	if (Pos < 0)
		return NULL;

	if (!IncludeSubStr)
		Pos += StrCalcLength(SubStr);

	PCHAR Tmp = Str + Pos;

	if (*Tmp == 0)
		return NULL;
	return STR::New(Tmp);
}
//------------------------------------------------------------------------------

int StrToInt(PCHAR Str)
{
	return (int)m_atol(Str);
}
//----------------------------------------------------------------------------

void StrLowerCase(PCHAR Str)
{
	// Функция приводит строку к нижнему регистру
	if (Str == NULL)
		return;

	PCHAR Pos = Str;

	while (*Pos != 0)
	{
        if ((*Pos >= 'A')  &&  (*Pos <= 'Z'))
			*Pos = *Pos + ('a'-'A');
		Pos++;
    }
}


//------------------------------------------------------------------------------

int StrIndexOf(PCHAR Str, bool CaseSensetive, DWORD Count, PCHAR Cmp...)
{
	// Функция ищет позицию строки в массиве строк Сmo
	if (Str == NULL || Count == 0 || Cmp == NULL)
		return -1;
	PCHAR *Cur = &Cmp;
	for (DWORD i = 0; i < Count; i++)
	{
		if (StrSame(Str, *Cur, CaseSensetive))
			return i;
        Cur++;
	}

	return -1;
}
//----------------------------------------------------------------------------


#define LowerChar(C) if (C >= 'A' && C <= 'Z') {C = C + ('a'-'A');}


bool StrSame(PCHAR Str, PCHAR ToSame, bool CaseSensetive, DWORD StrEndPosition)
{
	// Функция сравнивает строку Str со строкой ToSame.
	// CaseSensetive определяет чувствительность к регистру
	// Если StrEndPosrition не равен нулю, то сравнение
	// ограничивается StrEndPosrition символами

	if (Str == NULL || ToSame == NULL)
		return false;

    DWORD Pos = 1;
	PCHAR S1 = Str;
	PCHAR S2 = ToSame;

	char C1;
	char C2;

	while (*S1 != 0 && S2 != 0)
	{
		C1 = *S1;
		C2 = *S2;

		if (!CaseSensetive)
		{
			LowerChar(C1);
			LowerChar(C2);
		}

		if (C1 != C2) return false;

		S1++;
		S2++;
		if (StrEndPosition != 0 && Pos >= StrEndPosition)
			return *S2 == 0;
		Pos++;
	}
    return *S1 == 0 && *S2 == 0;
}
//----------------------------------------------------------------------------

PCHAR STR::IgnoreSpaces(PCHAR Str)
{
	// Функция игнорирует пробелы. Функция НЕ изменяет строку, она лишь
	// возвращает указатель на нужный символ, либо на конец строки
	PCHAR S = Str;
	while ((*S != 0) && (*S == ' ' || *S == 9)) S++;
	return S;
}
//----------------------------------------------------------------------------

PCHAR STR::Format(PCHAR Str, va_list Arguments)
{
	if (STR::IsEmpty(Str)) return NULL;
	PCHAR FullLine = STR::Alloc(StrCalcLength(Str) + 4096);

//	va_list Arguments;
//	va_start(Arguments, Str);
	pwvsprintfA(FullLine, Str, Arguments);
//	va_end(Arguments);
	PCHAR Res = STR::New(FullLine);
	STR::Free(FullLine);
	return Res;
}
//----------------------------------------------------------------------------

PCHAR STR::GetLine(PCHAR Str, DWORD StrSize)
{
	// Функция возвращает текущую линию в строке.
	// Линия ограничивается символами 10, 13 либо концом строки
	// Конец строки ограничивается нулевым символом либо размером StrSize
	if (Str == NULL)
		return NULL;

	DWORD Size;
	PCHAR Tmp = Str;

	for (Size = 0; !IsStrEnd(Tmp, StrSize, Size) && *Tmp != 10 && *Tmp != 13; Size++, Tmp++);


	if (Size != 0)
		return STR::New(Str, Size);
	else
		return NULL;
}
//----------------------------------------------------------------------------

PCHAR STR::GotoNextLine(PCHAR Str, DWORD StrSize)
{
	// Функция возвращает указатель на первый символ следующей линии в строке
	// либо на конец строки
	if (Str == NULL)
		return NULL;
	DWORD Pos;
	PCHAR Tmp = Str;

	for (Pos = 0; !IsStrEnd(Tmp, StrSize, Pos) && *Tmp != 10 && *Tmp != 13; Pos++, Tmp++);

	for (; !IsStrEnd(Tmp, StrSize, Pos) && (*Tmp == 10 || *Tmp == 13); Pos++, Tmp++);

	return Tmp;
}
//----------------------------------------------------------------------------

DWORD STR::HexToDWORD(PCHAR Str)
{
	if (STR::IsEmpty(Str))
		return 0;

	DWORD v = 0;
	if(Str[0] == '0' && Str[1] == 'x') Str += 2;
	for(;;)
	{
		char c = *Str;
		if(c >= '0' && c <= '9')
		{
		  v *= 16;
		  v += c - '0';
		}
		else
		if(c >= 'A' && c <= 'F')
		{
		  v *= 16;
		  v += c - 'A' + 0xA;
		}
		else if(c >= 'a' && c <= 'f')\
		{
		  v *= 16;
		  v += c - 'a' + 0xA;
		}
		else break;
		Str++;
	}
	return v;
}

//------------------------------------------------------------------------------
DWORD STR::GetHash(PCHAR Str, DWORD Len, bool LowerCase)
{
	// Функция расчитывает хэш строки
	// Str - исходная строка
	// Len - Длина строки, если равно 0, то расчитывается до конечного нуля
	// LowerCase - приводить символы в нижний регистр перед созданием хэша

	if (Str == NULL) return (DWORD)-1; // Наследие Фрека

	DWORD Hash = 0;

	for (DWORD i = 0; *Str != 0 && (Len == 0 || i < Len); Str++, i++)
	{
		char Ch = *Str;
		if (LowerCase) LowerChar(Ch);
		Hash = (( Hash << 7 ) & (DWORD)( -1 ) ) | ( Hash >> ( 32 - 7 ));
		Hash = Hash ^ Ch;
	}

	return Hash;
}
//------------------------------------------------------------------------------}

DWORD STR::CalcDoubleZeroStrLength(PCHAR Str)
{
	// Функция расчитывает длину строки состоящей из нескольких строк
	// отделённых друг от другу нулевым символом в конце которых стоит
	// двойной нулевой символ
	// Например: str0str0str00

	if (IsEmpty(Str))
		return 0;

	PCHAR S = Str;
	while (*S != 0)
	{
		S = End(S); // Переходим к концу текущей строки
		S++;        // Пропускаем нулевой символ
	}
	S++; // Пропускаем заверщающий ноль

    return (S - Str);
}
//------------------------------------------------------------------------------}


void STR::AnsiLowerCase(PCHAR Str)
{
	// Функция приводит символы в нижний регистр. Функция не чувствительна
	// к кодировке символов
	if (STR::IsEmpty(Str))
		return;

    DWORD Len = StrCalcLength(Str);
	pCharLowerBuffA(Str, Len);
}


//------------------------------------------------------------------------------
// WSTR - Функции для работы с Wide строками
//------------------------------------------------------------------------------

// Выделить память по строку длиной StrLen
PWCHAR WSTR::Alloc(DWORD StrLen)
{
	if (StrLen == 0) return NULL;

	PWCHAR Str = (PWCHAR)HEAP::Alloc(StrLen*sizeof(WCHAR) + STRHEAD::HeadSize + sizeof(WCHAR));
	if (Str == NULL) return NULL;

	return (PWCHAR)STRHEAD::MakeHead((LPBYTE)Str, StrLen, StrLen, sizeof(WCHAR));
}
// ----------------------------------------------------------------------------

PWCHAR WSTR::New(PWCHAR Source, DWORD Len)
{
	// Функция создаёт строку , копию Source.
	// Len - Количество копируемых символов
	//       если равно 0, то будет скопирована вся строка

	if (Source == NULL) return NULL;

	if (Len == 0) Len = CalcLength(Source);
	if (Len == 0) return NULL;

	PWCHAR Str = Alloc(Len);
	if (Str != NULL)
		m_memcpy(Str, Source, Len * sizeof(WCHAR));

	return Str;

}
// ----------------------------------------------------------------------------


void WSTR::Free(PWCHAR Str)
{
	// Уничтожить строку.
	// Важно!!! Строка должна быть создана с помощью функций Alloc или New
	if (STRHEAD::CheckSignature(Str))
		HEAP::Free((LPBYTE)Str - STRHEAD::HeadSize);
}

// ----------------------------------------------------------------------------

DWORD WSTR::CalcLength(PWCHAR Str)
{
	// Функция расчитывает длину строки
	if (Str == NULL) return 0;

	/* TODO :
	Просмотреть реализацию более быстрого алгоритма расчёта длины строки PWCHAR*/

    DWORD Len = 0;
	for (; *Str != 0; Str++) Len++;

	return Len;
}
// ----------------------------------------------------------------------------

bool WSTR::IsEmpty(PWCHAR Str)
{
	// Функция возвращает истину если строка пустая
	return Str == NULL || *Str == 0;
}

// ----------------------------------------------------------------------------

PCHAR WSTR::ToAnsi(PWCHAR Str, DWORD Len)
{
	// Функция преобразовывает WideString в ANSI String
	if (IsEmpty(Str)) return NULL;

	if (Len == 0) Len = WSTR::CalcLength(Str);
	if (Len == 0) return NULL;

    // Определяем размер результирующей строки
	int ResLen = (int)pWideCharToMultiByte(CP_ACP, 0, Str, Len, 0, 0, NULL, NULL);

	// Преобразовываем строку
	PCHAR Result = STR::Alloc(ResLen);
	pWideCharToMultiByte(1251, 0, Str, Len, Result, ResLen, NULL, NULL);

	return Result;
}

// ----------------------------------------------------------------------------
PWCHAR WSTR::End(PWCHAR Str)
{
	// Возвращает указатель на конец строки
	if (Str != NULL)
		for (; *Str != 0; Str++);
    return Str;
}

// ----------------------------------------------------------------------------

PWCHAR WSTR::ScanEnd(PWCHAR Str, WCHAR C)
{
	// Функция возвращает указатель на последний символ С
	if (Str == NULL) return NULL;

	PWCHAR Res = NULL;

	for (PWCHAR Tmp = Str; *Tmp != 0; Tmp++)
		if (*Tmp == C) Res = Tmp;

	return Res;
}


DWORD WSTR::GetHash(PWCHAR Str, DWORD Len, bool LowerCase)
{
	// Функция расчитывает хэш строки
	// Str - исходная строка
	// Len - Длина строки, если равно 0, то расчитывается до конечного нуля
	// LowerCase - приводить символы в нижний регистр перед созданием хэша

	if (Str == NULL) return (DWORD)-1; // Наследие Фрека

	DWORD Hash = 0;

	for (DWORD i = 0; *Str != 0 && (Len == 0 || i < Len); Str++, i++)
	{
		WCHAR Ch = *Str;
		if (LowerCase) LowerChar(Ch);
		Hash = (( Hash << 7 ) & (DWORD)( -1 ) ) | ( Hash >> ( 32 - 7 ));
		Hash = Hash ^ Ch;
	}

	return Hash;

}

// ----------------------------------------------------------------------------
//
//  Набор функция для работы со списками строк Strings
//
// ----------------------------------------------------------------------------

typedef struct TStringsRec
{
	PList Items;
	PCHAR LineDelimeter;
	PCHAR ValueDelimeter;

} *PStringsRec;


PStrings Strings::Create()
{
	// Создать набор строк
	PStringsRec Rec = CreateStruct(TStringsRec);

	Rec->Items = List::Create();
	List::SetFreeItemMehod(Rec->Items, (TFreeItemMethod)STR::Free);

	Rec->LineDelimeter = STR::New("\r\n");
	Rec->ValueDelimeter = STR::New("=");

	return (PStrings)Rec;
}
// ----------------------------------------------------------------------------

void Strings::Free(PStrings Strings)
{
	// Уничтожить набор строк
	if (Strings == NULL)
		return;

	List::Free(PStringsRec(Strings)->Items);
	STR::Free(PStringsRec(Strings)->LineDelimeter);
	STR::Free(PStringsRec(Strings)->ValueDelimeter);

	FreeStruct(Strings);
}
// ----------------------------------------------------------------------------

void Strings::Clear(PStrings Strings)
{
	// Очистить набор строк
	if (Strings != NULL)
		List::Clear(PStringsRec(Strings)->Items);
}
// ----------------------------------------------------------------------------

DWORD Strings::Count(PStrings Strings)
{
	// Получить количество строк
	if (Strings == NULL)
		return 0;
	return List::Count(PStringsRec(Strings)->Items);
}
// ----------------------------------------------------------------------------

int Strings::Add(PStrings Strings, PCHAR Str, bool Duplicate)
{
	// Добавить новую строку
	if (Strings == NULL)
		return -1;
	PCHAR Tmp;
	if (Duplicate)
		Tmp = STR::New(Str);
	else
		Tmp = Str;
	return List::Add(PStringsRec(Strings)->Items, (LPVOID)Tmp);
}
// ----------------------------------------------------------------------------

void Strings::Delete(PStrings Strings, DWORD Index)
{
	// Удалить строку
	if (Strings == NULL)
		return;

	List::Delete(PStringsRec(Strings)->Items, Index);
}
// ----------------------------------------------------------------------------

int Strings::Remove(PStrings Strings, PCHAR Str)
{
	// Функция удаляет строку Str из списка
	int Index = IndexOf(Strings, Str);
	if (Index >= 0)
		Delete(Strings, Index);
	return Index;
}
// ----------------------------------------------------------------------------

int Strings::IndexOf(PStrings Strings, PCHAR Str)
{
    // Функция возвращает позицию строки Str в списке
	if (Strings == NULL) return -1;
	PStringsRec R = (PStringsRec)Strings;

	int Count = List::Count(R->Items);

	for (int i = 0; i < Count; i++)
	{
		PCHAR S = (PCHAR)List::GetItem(R->Items, i);
		if (StrSame(S, Str, true))
        	return i;
	}
	return -1;
}
// ----------------------------------------------------------------------------

PCHAR Strings::GetItem(PStrings Strings, DWORD Index, bool DuplicateStr)
{
	// Получит строку из позиции

	if (Strings == NULL)
		return NULL;
	PCHAR Str = (PCHAR)List::GetItem(PStringsRec(Strings)->Items, Index);
	if (DuplicateStr)
		return STR::New(Str);
	else
		return Str;
}
// ----------------------------------------------------------------------------

PCHAR Strings::GetText(PStrings Strings, PCHAR LineDelimeter)
{
	// Объеденяет все строки в одну. Если не указан
	// разделитель то использован разделитель заданный в настройках
	if (Strings == NULL)
		return NULL;

	PStringsRec SR = (PStringsRec)Strings;

	DWORD Count = List::Count(SR->Items);
	if (Count == 0)
		return NULL;

	// Инициализируем разделитель строк
	PCHAR Del;
	DWORD DelLen;

	if (LineDelimeter != NULL)
	{
		Del = LineDelimeter;
		DelLen = StrCalcLength(Del);
	}
	else
	{
		Del = SR->LineDelimeter;
		DelLen = STR::Length(Del);
	}

	PCHAR S;
	DWORD TotalLen = 0;
	DWORD i;

	// Рсчитываем длину строки
	for (i = 0; i < Count; i++)
	{
		S = (PCHAR)List::GetItem(SR->Items, i);
		TotalLen += STR::Length(S);
		if (i < (Count - 1))
			TotalLen += DelLen;
	}

	// Собираем строку
	DWORD L;
	PCHAR Result = STR::Alloc(TotalLen);
	STRHEAD::SetLength(Result, TotalLen);

	PCHAR Temp = Result;

	for (i = 0; i < Count; i++)
	{
		S = (PCHAR)List::GetItem(SR->Items, i);
		L = STR::Length(S);

		m_memcpy(Temp, S, L);
		Temp += L;

		if (i < (Count - 1))
		{
			m_memcpy(Temp, Del, DelLen);
			Temp += DelLen;
		}
	}

	return Result;
}

//----------------------------------------------------------------------------

void Strings::SetText(PStrings Strings, PCHAR Text)
{
	// Функция разбирает текст на строки разделённые символами новой
	// строки и перевода каретки

	if (Strings == NULL || Text == NULL)
		return;
	PStringsRec SR = (PStringsRec)Strings;
	// очищаем список
	List::Clear(SR->Items);

	//Парсим текст
	PCHAR Start = Text;
	PCHAR End;
	PCHAR Line;
	BYTE Flag;
	BYTE Ign;
	DWORD StrLen;
	while (*Start != 0)
	{
		// Ищем конец строки
		End = Start;
		while (*End != 0 && *End != 10 && *End != 13) End++;

		// Создаём строку
		StrLen = End - Start;
		if (StrLen != 0)
			Line = STR::New(Start, StrLen);
		else
			Line = NULL;
		List::Add(SR->Items, Line);

		// Переходим на следующую строку
		Flag = 0;
		while (*End != 0)
		{
			if (*End == 10)
				Ign = 1;
			else
			if (*End == 13)
				Ign = 2;
			else
				break;
			if ((Flag & Ign) != 0)
				break;

			Flag = Flag | Ign;

			End++;
		}
		Start = End;
	}
}
//----------------------------------------------------------------------------

int Strings::AddValue(PStrings Strings, PCHAR Name, PCHAR Value, PCHAR Delimeter)
{
	// Добавить в список пару Имя=Значение.
	// Если не указан разделитель то будет взят из настроек списка (по умолчанию =)

	if (Strings == NULL || Name == NULL)
		return NULL;

	PStringsRec SR = (PStringsRec)Strings;

	PCHAR Del = Delimeter;
	if (Del == NULL)
		Del = SR->ValueDelimeter;

	return List::Add(SR->Items, STR::New(3, Name, Del, Value));
}

