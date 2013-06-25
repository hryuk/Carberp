
#ifndef StringsH
	Исключите файл из проекта
#endif

#include <windows.h>
#include "Strings.h"



#define WILD_CMP_POS_MAX  0xffffffffUL

// поиск с помощью алгоритма Бойера-Мура-Хорспула

const char* FindStr( const char* strSrc, int lenSrc, const char* strFind, int lenFind, int* skip, const char** end )
{
	int i = lenFind - 1; //сравнение с конца strFind
	while( i < lenSrc )
	{
		int j = lenFind;
		const char* pSrc = *end = strSrc + i;
		const char* pFind = strFind + j - 1; //поиск с конца строки
		for(;;)
		{
			if( *pSrc == *pFind ) 
			{
				if( --j )
					pSrc--, pFind--;
				else
					return pSrc;
			}
			else 
				break;
		}
		i += skip[ (unsigned char)strSrc[i] ]; //перескакиваем
	} 
	return 0;
}

//-----------------------------------------------------------------------------
//инициализирует таблицу переходов для сравнений, skip - массив на 256 элементов
int* InitTblSkip( const char* strFind, int lenFind, int* skip)
{
	for( int i = 0; i < 256; i++ ) skip[i] = lenFind; //значения по умолчанию
	for( int i = 0; i < lenFind - 1; i++ ) skip[ (unsigned char)strFind[i] ] = lenFind - i - 1;
	return skip;
}

//-----------------------------------------------------------------------------
bool WildCmp( const char *Buffer, const char *Mask, LPDWORD Start, LPDWORD End, LPDWORD Len )
{
	int skip[256];
	int lenBuffer = m_lstrlen(Buffer);
	int lenMask = m_lstrlen(Mask);

	if( lenMask == 0 ) //если маска пустая
		if( lenBuffer == 0 )
			return true;
		else
			return false;
	else
		if(lenBuffer == 0)
			return false;

	bool cmp = true; //результат сравнения
	int pBuffer = 0; //позиция начала сравнения 
	int pMask = 0; //позиция начала символов в маске
	*Start = WILD_CMP_POS_MAX;

	while( pBuffer < lenBuffer )
	{
		while( pMask < lenMask && Mask[pMask] == '*' ) pMask++; //игнорируем начальные *
		if( pMask >= lenMask ) break; //закончилась маска
		int begMask = pMask;
		while( pMask < lenMask && Mask[pMask] && Mask[pMask] != '*' ) ////ищем за символами символ * пока не дойдем до конца маски
		{
			pMask++; 
		}
		const char* find;
		int lenMask2 = pMask - begMask;
		const char* end; //последний найденный символ в Buffer, необходим для дальнейшего поиска
		InitTblSkip( Mask + begMask, pMask - begMask, skip );
		find = FindStr( Buffer + pBuffer, lenBuffer - pBuffer, Mask + begMask, lenMask2, skip, &end );
		if( find == 0 )
		{
			cmp = false;
			break;
		}

		pBuffer = find - Buffer; //позиция найденной строки
		if( *Start == WILD_CMP_POS_MAX ) *Start = pBuffer; //если еще ничего не находили, то запоминаем
		pBuffer = end - Buffer + 1; //позиция с которой продолжим поиск
		*End = pBuffer;
		pMask++;
	}
	if( cmp )
	{
		if( *Start == WILD_CMP_POS_MAX ) //такое может быть если маска это одни *
		{
			*Start = 0;
			*End = lenBuffer;
		}
		*Len = *End - *Start + 1;
		return true;
	}
	return false;
}
//-----------------------------------------------------------------------------

bool WildCmp(PCHAR Buffer, PCHAR Mask)
{
	DWORD S;
	DWORD E;
	DWORD L;
	return WildCmp(Buffer, Mask, &S, &E, &L);
}
//-----------------------------------------------------------------------------
