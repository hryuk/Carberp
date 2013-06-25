
#ifndef StringsH
	#error Исключите файл из проекта
#endif

#include <windows.h>
#include "Strings.h"



/*
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

*/

// Структура обеспечения сравнения строк
typedef struct WILD_CMP_REC
{
	PCHAR Mask;            // Маска
	PCHAR Buffer;          // Сравниваемая строка
	PCHAR Start;           // Начало совпадения маски
	PCHAR End;             // Окончание совпадения маски
	bool  LastCharIsMask;  // Предыдущий символ был маской
	int   Result;          // результат сравнения
} TWCR;



//----------------------------------------------------
bool inline WC_IsMask(const char* Mask)
{
	// Функция возвращает истину если текущий символ является
	// специфическим символом
	return *Mask == '*';
}
//----------------------------------------------------

void WC_ProcessMask(TWCR &WCR)
{
	// Функция обрабатывает символ маски
	WCR.LastCharIsMask = true;

	// Сохраняем позицию старта маски
	if (!WCR.Start) WCR.Start = WCR.Buffer;

	// Обнуляем позицию окончания маски, тем самым
	// обрабатывая все маски, которые могут идти после
	// "осмысленного" контента
	// Например: "test_test*"
	WCR.End = NULL;

	// Если это последний символ маски, то помечаем строку как
	// успешно сравнённую
	if (*(WCR.Mask + 1) == 0)
		WCR.Result = 1;

	WCR.Mask++;
}
//----------------------------------------------------


bool WC_IsLB(PCHAR S, BYTE &Size)
{
	Size = 0;
	bool r = false;
	bool n = false;

	for (; *S != 0; S++)
	{
		if (*S == '\r')
		{
			if (r) break;
			r = true;
            Size++;
		}
		else
		if (*S == '\n')
		{
			if (n) break;
			n = true;
			Size++;
        }
		else
			break;
	}

	return Size != 0;
}

//--------------------------------------------
//  Функция сравнивает символы строки
//--------------------------------------------
bool WC_CompareChars(PCHAR &S1, PCHAR &S2)
{
	// При сравнении символов нюансом является то,
	// что символы перевода строк должны корректно
	// обрабатываться как для Windows так и для
	// Linux формата
	// т.е. \r\n и \n должны восприниматься идентично в
	// независимости от их положения и последовательности

	bool Result = false;
	BYTE CS1 = 0;
	BYTE CS2 = 0;

	if (WC_IsLB(S1, CS1))
		Result = WC_IsLB(S2, CS2); // Сравниваются переводы строк
	else
		Result = *S1 == *S2;       // Сравниваем другие символы

	if (Result)
	{
		S1 += (CS1) ? CS1 : 1;
		S2 += (CS2) ? CS2 : 1;
    }

	return Result;
}
//----------------------------------------------------


void WC_CompareLine(TWCR &WCR)
{
	// Функция сравнивает текущую строку маски с буфером

	// Устанавливаем режим сравнения строки.
	// Если предыдущий символ был маской то переключаем
	// сравнение в режим поиска строки, в противном случае сравниваем
	// строку в текущей позиции
	bool SM = true;//WCR.LastCharIsMask;

	WCR.LastCharIsMask = false;

	bool EOL  = false;

	while(*WCR.Buffer)
	{
		// Сравниваем текущую маску
		PCHAR M = WCR.Mask;
		PCHAR B = WCR.Buffer;

		while (1)
		{
			// Определяем конец сравниваемой строки
			EOL = (*M == 0 || WC_IsMask(M));

			// Проверку конца строки в этой части сделали потому, что
			// возможна ситуация когда конец строки совпадёт с концом
			// маски
			if (*B == 0 || EOL || !WC_CompareChars(B, M))
				break;
		}

		// Успешное сравнение считаем только в том случае есл
		// дошли до конца текущей строки в маске
		if (EOL)
		{
			// Сохраняем конец буфера и маски
			if(!WCR.Start) WCR.Start = WCR.Buffer;
			WCR.Buffer = B;
			WCR.End    = B;
			WCR.Mask   = M;
			break;
        }

		// Вслучае окончания строки или в режиме сравнения с текущей
		// позиции, прекращаем работу
		if (!SM || *B == 0) break;

		// Переходим к следующей позиции буфера
		WCR.Buffer++;
    }

	// Проверяем резудьтат. нас удовлет только итуация
	// когда мы дошли до конца текущей строки в маске
	if (!EOL)
		WCR.Result = -1;
}
//----------------------------------------------------



bool WildCmp( const char *Buffer, const char *Mask, LPDWORD StartPos, LPDWORD EndPos, LPDWORD SubStrLen)
{
	// Проверем переданные параметры
	if (StartPos)  *StartPos  = 0;
	if (EndPos)    *EndPos    = 0;
	if (SubStrLen) *SubStrLen = 0;

	if(STRA::IsEmpty(Mask))
		return STRA::IsEmpty(Buffer);

	if(STRA::IsEmpty(Buffer))
		return false;


	// Инициализируем структуру
	TWCR WCR;
	ClearStruct(WCR);

	WCR.Mask   = (PCHAR)Mask;
    WCR.Buffer = (PCHAR)Buffer;


	// Перебираем всю маску
	while (*WCR.Mask != 0 && WCR.Result == 0)
	{
		// Сравниваем текущий символ
		if (WC_IsMask(WCR.Mask))
			WC_ProcessMask(WCR);
		else
			WC_CompareLine(WCR);
	}

	// Если дошли до конца маски, то
	// завершаем поиск удачей
	if (*WCR.Mask == 0)
		WCR.Result = 1;

	// сравнение успешно завершено
	if (WCR.Result == 1)
	{
		if (!WCR.End && (EndPos || SubStrLen))
			WCR.End = STRA::End(Buffer);

		if (StartPos)  *StartPos  = WCR.Start - Buffer;
		if (EndPos)    *EndPos    = WCR.End - Buffer;
		if (SubStrLen) *SubStrLen = WCR.End - WCR.Start;
	}

	return WCR.Result == 1;
}
//----------------------------------------------------------------------------


bool WildCmp(const char* Buffer, const char* Mask)
{
	DWORD S;
	DWORD E;
	DWORD L;
	return WildCmp(Buffer, Mask, &S, &E, &L);
}
//-----------------------------------------------------------------------------
