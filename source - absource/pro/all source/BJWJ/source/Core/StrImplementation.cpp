
#ifndef StringsH
	#error Исключите файл из проекта
#endif


#include "Memory.h"


//*****************************************************************************
//                               STRUTILS
//*****************************************************************************

#define CHARAPI(Result_Type) template<class TChar> Result_Type STRUTILS<TChar>


// Функция возвращает истину если строка пустая
CHARAPI(bool)::IsEmpty(const TChar* Str)
{
	return Str == NULL || *Str == 0;
}
//-----------------------------------------------------------------------------


CHARAPI(DWORD)::Length(const TChar* Str)
{
	// Функция расчитывает длину строки
	DWORD Len = 0;
	if (Str != NULL)
		while (*Str++) Len++;

	return Len;
}
//-----------------------------------------------------------------------------


// Функция ищет вхождение подстроки в строке
CHARAPI(int)::Pos(const TChar* Str, const TChar *SubStr)
{
	if (IsEmpty(Str) || IsEmpty(SubStr))
		return -1;

    const TChar* Temp = Str;
	while (*Temp)
	{
		if (*Temp == *SubStr)
		{
			// Совпадение первого символа, проверяем полное совпадение
			const TChar* S1 = Temp;
			const TChar* S2 = SubStr;
			while (*S1 && *S2 && *S1 == *S2) {S1++; S2++;}
			if (*S2 == 0) return Temp - Str;
		}
		Temp++;
    }
    return -1;
}
//-----------------------------------------------------------------------------


CHARAPI(bool)::Equal(const TChar* Str1, const TChar* Str2)
{
	// Функция возвращает истину если строки идентичны
	if (Str1 == Str2 || (IsEmpty(Str1) && IsEmpty(Str2)))
		return true;
	else
    	return Compare(Str1, Str2) == 0;
}
//-----------------------------------------------------------------------------

CHARAPI(int)::CompareEx(const TChar* Str1, const TChar* Str2, DWORD CmpLen)
{
	// Функция сравнивает две строки

	if (Str1 == NULL || Str2 == NULL)
		return -1;

	const TChar* S1 = Str1;
	const TChar* S2 = Str2;
    DWORD Pos = 0;
	while(1)
	{
		Pos++;



		if (*S1 != *S2)
		{
			int R;
			if (CmpLen)
			{
				// В случае если сравнивается часть строки, возвращаем
				// 0 если дошли до нулевого символа второй строки
				if (*S2 == 0)
					R = 0;
				else
					R = -1;
			}
			else
			if (*S1 > *S2)
				R = 1;
			else
				R = -1;
			return R;
		}

		if (*S2 == 0) return 0;

		S1++;
		S2++;
    }
}


CHARAPI(int)::Compare(const TChar* Str1, const TChar* Str2)
{
	return CompareEx(Str1, Str2, 0);
}

//-----------------------------------------------------------------------------

template<class TChar>
void _Str_MoveChars(const TChar *Str, DWORD StrLen, DWORD Position, int Count)
{
	// Функция сдвигает символы в нжном направлении
	const TChar *StartPtr = Str + Position;
	const TChar *EndPtr   = Str + StrLen;

	if (Count > 0)
	{
    	// Сдвигаем в право
		TChar *ToCopy   = (TChar*)(Str + (StrLen + Count));
		while (EndPtr >= StartPtr)
		{
			*ToCopy = *EndPtr;
			ToCopy--;
			EndPtr--;
		}
	}
	else
	{
    	// Сдвигаем влево
		TChar *ToCopy   = (TChar*)(Str + (Position + Count));
		if (ToCopy < Str) ToCopy = (TChar*)Str;
		while (StartPtr <= EndPtr)
		{
			*ToCopy = *StartPtr;
			ToCopy++;
			StartPtr++;
		}
    }
}
//-----------------------------------------------------------------------------

template<class TChar>
void _Str_Insert(const TChar *Str, DWORD StrLen, DWORD Position, const TChar *SubStr, DWORD SubStrLen)
{
	_Str_MoveChars<TChar>(Str, StrLen, Position, SubStrLen);
	m_memcpy((void*)(Str + Position), (void*)SubStr, SubStrLen * sizeof(TChar));
}
//-----------------------------------------------------------------------------

template<class TChar>
struct TStrReplaceData
{
	DWORD  StartPosition;
	TChar* Str;
	DWORD  StrLen;
	TChar* SubStr;
	DWORD  SubStrLen;
	TChar* NewStr;
	DWORD  NewStrLen;
	DWORD  Count;
	PDWORD Positions;
};

// Функция инициализирует данные для замена подстрок
template<class TChar>
bool _Str_Replace_Initialize(TStrReplaceData<TChar> *Data)
{

	// Определяем поозицию подстроки
	int P = STRUTILS<TChar>::Pos(Data->Str + Data->StartPosition, Data->SubStr);
	if (P  < 0) return false;

	Data->Count++;
	Data->StartPosition += P + Data->SubStrLen;
	DWORD Index = Data->Count - 1;
	// Продолжаем поиск
	_Str_Replace_Initialize<TChar>(Data);

	// Заисываем позицию в массив
	if (Data->Positions == NULL)
		Data->Positions = (PDWORD)HEAP::Alloc(Data->Count * sizeof(DWORD));

	Data->Positions[Index] = P;

	return Data->Count > 0;
}

template<class TChar>
void _Str_Replace(TStrReplaceData<TChar> *Data)
{
	// Вункция выполняет подмену строк исходя из полученных данных
	// функцией иниуиализации замен
	int Delta = Data->NewStrLen - Data->SubStrLen;

	TChar *Str = Data->Str;
	DWORD StrLen = Data->StrLen;

	for (DWORD i = 0; i < Data->Count; i++)
	{
    	// Определяем позицию блока
		int P = Data->Positions[i];
		Str += P;
		StrLen -= P;

		// Смещаем строку
		_Str_MoveChars(Str, StrLen, Data->SubStrLen, Delta);

		// Копируем строку
		m_memcpy(Str, Data->NewStr, Data->NewStrLen * sizeof(TChar));

		Str += Data->NewStrLen;
		StrLen -= (Data->NewStrLen - Delta);
	}
}

//-----------------------------------------------------------------------------
CHARAPI(void)::Expand(const TChar *Str, DWORD Position, int Count)
{
	// Функция расширяет строку Str с позиции Position на
	// Count символов
	if (IsEmpty(Str) || Count == 0)
		return;

	DWORD StrLen = Length(Str);
    _Str_MoveChars<TChar>(Str, StrLen, Position, Count);
}
//-----------------------------------------------------------------------------

//  Функция вставляет подстроку в строку
CHARAPI(void)::Insert(const TChar *Str, const TChar *SubStr, DWORD Position)
{
	if (IsEmpty(Str) || IsEmpty(SubStr))
		return;
	DWORD StrLen    = Length(Str);
	DWORD SubStrLen = Length(SubStr);

	if (Position <= StrLen)
        _Str_Insert(Str, StrLen, Position, SubStr, SubStrLen);
}
//-----------------------------------------------------------------------------

// Вункция заменяет все строки SubStr в строке Str на строку NewStr
CHARAPI(void)::Replace(const TChar *Str, const TChar *SubStr, const TChar *NewStr)
{
	if (IsEmpty(Str) || IsEmpty(SubStr))
		return;

	// Определяем позиции
	TStrReplaceData<TChar> Data;
	ClearStruct(Data);

	Data.Str       = (TChar*)Str;
	Data.StrLen    = Length(Str);
	Data.SubStr    = (TChar*)SubStr;
	Data.SubStrLen = Length(SubStr);
	Data.NewStr    = (TChar*)NewStr;
	Data.NewStrLen = Length(NewStr);

	_Str_Replace_Initialize(&Data);
	if (Data.Count == 0) return;

	// Заменяем строки
    _Str_Replace<TChar>(&Data);

	//Закрываем данные
    HEAP::Free(Data.Positions);

}
//-----------------------------------------------------------------------------

// Функция расчитывает хэш строки
CHARAPI(DWORD)::Hash(const TChar* Str, DWORD Len, bool LowerCase)
{
	// Функция расчитывает хэш строки
	// Str - исходная строка
	// Len - Длина строки, если равно 0, то расчитывается до конечного нуля
	// LowerCase - приводить символы в нижний регистр перед созданием хэша

	if (Str == NULL) return (DWORD)-1; // Наследие Фрека

	DWORD H = 0;

	for (DWORD i = 0; *Str != 0 && (Len == 0 || i < Len); Str++, i++)
	{
		TChar Ch = *Str;
		if (LowerCase) LowerChar(Ch);
		H = (( H << 7 ) & (DWORD)( -1 ) ) | ( H >> ( 32 - 7 ));
		H = H ^ Ch;
	}

	return H;
}


CHARAPI(DWORD)::Hash(const TChar* Str)
{
    return Hash(Str, 0, false);
}
//-----------------------------------------------------------------------------

// Функции ищет первое вхождение символа в строке
CHARAPI(TChar*)::Scan(const TChar *Str, TChar Char)
{
	if (Str != NULL)
		while (*Str != 0)
		{
			if (*Str == Char) return (TChar*)Str;
			Str++;
		}
	return NULL;
}


// Функция вщзвращает указатель на конец строки
CHARAPI(TChar*)::End(const TChar *Str)
{
	if (Str)
		while (*Str) Str++;
	return (TChar*)Str;
}



// Функция преобразует целое число в строку.
// Функция не создаёт строки.
// в переменой n возвращает количество символов
// Если вызвать функцию с нулевым буфером то функция
// расчитает необходимый размер строки
CHARAPI(void)::LongToString(DWORD num, TChar* Str, int &n)
{
	// Расчитываем количетво символов
	// Если n не равен нулю значит идёт второе обращение
	// к функции и длина уже известна
	if (!n)
	{
		if (!num)
			n = 1;
		else
			for (int j = 1; num/j !=0; j *= 10) n++;
    }

    // Если буер нулевой то идёт запрос количества символов
	if (!Str) return;

	// преобразовываем
	int i = 1;
	int d = 0;
	do
	{
		d = num % 10;
		num /= 10;
		Str[n-i]=(char)(d+48);
		i++;
	}
	while(num != 0);
}



//*****************************************************************************
//                               STRBUF
//*****************************************************************************

STRBUFAPI(TChar*) STRBUF::Alloc(DWORD Size)
{
	// Функция создаёт строку размером Size символов
	// Длина строки устанавливается нулевой
	if (Size == 0) return NULL;

	#ifdef USE_BLOCKS_STRINGS
        Size = ((Size / STRING_BLOCK_SIZE) + 1) * STRING_BLOCK_SIZE;
	#endif

	DWORD BufSize = (Size + 1) * sizeof(TChar) + sizeof(TStrRec);
	TStrRec* Buf = (TStrRec*)HEAP::Alloc(BufSize);
	if (Buf == NULL) return NULL;

	Buf->Size     = Size;
	Buf->Length   = 0;
	Buf->RefCount = 1;

	Buf++;
	return (TChar*)Buf;
}
//----------------------------------------------------------------------------

STRBUFAPI(void) STRBUF::Release(TChar* &Str)
{
	// Функция уменьшает счётчик ссылок и, при необходимости, уничтожает строку
	if (Str)
	{
		TStrRec &R = GetRec(Str);
		R.RefCount--;
		if (R.RefCount == 0)
            HEAP::Free(&R);
        Str = NULL;
    }
}

//----------------------------------------------------------------------------

STRBUFAPI(TChar*) STRBUF::AddRef(TChar* Str)
{
	// Функция увеличивает счётчик ссылок строки и возвращает указатель на неё
	if (Str)
		GetRec(Str).RefCount++;
	return Str;
}
//----------------------------------------------------------------------------

STRBUFAPI(void) STRBUF::Unique(TChar* &Str)
{
	// Функция уникализирует строку
	if (Str)
	{
		TStrRec &R = GetRec<TChar>(Str);
		if (R.RefCount > 1)
		{
			R.RefCount--;
            Str = CreateFromStr(Str, R.Length, 0);
        }
    }
}
//----------------------------------------------------------------------------


STRBUFAPI(STRBUF::TStrRec&) STRBUF::GetRec(TChar* Str)
{
	// Функция возвращает переменную зоголовок строки
	TStrRec* R = (TStrRec*)Str;
    return R[-1];
}
//----------------------------------------------------------------------------

// Функция возвращает длину строки
STRBUFAPI(DWORD) STRBUF::Length(TChar *Str)
{
	return (Str)? GetRec(Str).Length : 0;
}
//----------------------------------------------------------------------------


STRBUFAPI(TChar*) STRBUF::CreateFromStr(const TChar* Str, DWORD StrLen, DWORD ResultStrSize)
{
	// Создаёт строку на основе исходной строки
	if (STRUTILS<TChar>::IsEmpty(Str))
		return NULL;

	if (StrLen == 0)
		StrLen = STRUTILS<TChar>::Length(Str);

    DWORD ResSize = Max(StrLen, ResultStrSize);
	TChar* Result = Alloc<TChar>(ResSize);
	if (Result)
	{
		// Копируем данные строки
		m_memcpy(Result, Str, StrLen * sizeof(TChar));
		GetRec(Result).Length = StrLen;
	}
	return Result;
}
//----------------------------------------------------------------------------


STRBUFAPI(void) STRBUF::Append(TChar* &Dst, const TChar* Src, DWORD SrcLen)
{
	// Функция добавляет к строке Dst строку Src
	if (STRUTILS<TChar>::IsEmpty(Src))
		return;


	if (SrcLen == 0)
		SrcLen = STRUTILS<TChar>::Length(Src);

	if (Dst == NULL)
	{
    	// Создаём строку на основе исходной строки
		Dst = CreateFromStr<TChar>(Src, SrcLen, 0);
	}
	else
	{
		// Объединяем две строки
		TStrRec &R = GetRec(Dst);
		TChar* Tmp = NULL;
		DWORD DstLen = R.Length;
		DWORD TotalLen = SrcLen + DstLen;
		if (R.Size < TotalLen || R.RefCount > 1)
		{
        	Tmp = Dst;
			Dst = CreateFromStr<TChar>(Tmp, DstLen, TotalLen);
        }
		m_memcpy(Dst + DstLen, Src, SrcLen * sizeof(TChar));
		GetRec(Dst).Length = TotalLen;

		if (Tmp)
			Release<TChar>(Tmp);
    }
}
//----------------------------------------------------------------------------

STRBUFAPI(void) STRBUF::Copy(TChar* &Dst, const TChar* Src, DWORD Pos, DWORD Count)
{
	// Функция копирует количество символов Count с позиции Pos
	if (STRUTILS<TChar>::IsEmpty(Src) || Count == 0)
		return;

	if (Dst == NULL)
	{
		// Создаём новую строку
        Dst = CreateFromStr(Src + Pos, Count, 0);
	}
	else
	{
		TStrRec &R = GetRec(Dst);

		// В случае ели трока уже оздана проверяем два момента
		// - Количество сылок. Если больше единицы то создаём новую строку
		// - Длину строки. Если длина нулевая и размер памяти позволяет скопировать
		//                 нужное количество символов то читаем, что память строки
		//				   изначально выделялась с учётом данной операции

		if (R.RefCount == 1 && R.Length == 0 && R.Size >= Count)
		{
			m_memcpy(Dst, Src + Pos, Count * sizeof(TChar));
			R.Length = Count;
            *(Dst + Count) = 0;
		}
		else
		{
			// На случай если копирование происходит из самой себя
			// уничтожим строку после копирования
			TChar* Tmp = Dst;
			Dst = CreateFromStr(Src + Pos, Count, 0);
			Release<TChar>(Tmp);
		}
	}
}
//----------------------------------------------------------------------------

STRBUFAPI(void) STRBUF::Insert(TChar* &Buf, const TChar* Str, DWORD Position, DWORD StrLen)
{
	// Функция вставляет строку Str в буфер
	if (STRUTILS<TChar>::IsEmpty(Str))
		return;


	if (Buf == NULL)
	{
		// Буфер пустой, если позиция вставки равна нулю, то создаём строку
		// на основе вставляемой строки
		if (Position == 0)
        	Buf = CreateFromStr(Str, 0, 0);
        return;
    }

	// Вставляем строку
	if (StrLen == 0)
		StrLen = STRUTILS<TChar>::Length(Str);

	TStrRec &R = GetRec<TChar>(Buf);

	// Проверяем позицию
	if (Position > R.Length)
		return;

	// Определяем размер буфера
	DWORD Len = R.Length;
	DWORD TotalLen = Len + StrLen;
	if (R.Size < TotalLen || R.RefCount > 1)
	{
		// Создаём новую строку
		TChar *Tmp = Buf;
        Buf = CreateFromStr<TChar>(Tmp, Len, TotalLen);
		Release<TChar>(Tmp);
	}

   	_Str_Insert(Buf, Len, Position, Str, StrLen);

	// Вставляем данные
	GetRec(Buf).Length = TotalLen;
}

//----------------------------------------------------------------------------


// Функция заменяет подстроки в строке
STRBUFAPI(void) STRBUF::Replace(TChar* &Str, const TChar* SubStr, DWORD SBLen, const TChar* NewStr, DWORD NSLen)
{
	if (Str == NULL || STRUTILS<TChar>::IsEmpty(SubStr))
		return;

	TStrRec &R = GetRec<TChar>(Str);


	TStrReplaceData<TChar> D;
	ClearStruct(D);

	D.Str       = Str;
	D.StrLen    = R.Length;
	D.SubStr    = (TChar*)SubStr;
    D.SubStrLen = (SBLen)? SBLen : STRUTILS<TChar>::Length(SubStr);
	D.NewStr    = (TChar*)NewStr;
	D.NewStrLen = (NSLen)? NSLen : STRUTILS<TChar>::Length(NewStr);

	// Инициализируем данные
	if (!_Str_Replace_Initialize<TChar>(&D)) return;

	// Расчитываем новую длину строки
	int Delta = D.NewStrLen - D.SubStrLen;
    DWORD TotalLen = R.Length + (D.Count * Delta);


	// Заменяем строки
	if (R.RefCount > 1 || R.Size < TotalLen)
	{
		TChar *Tmp = Str;
		Str = CreateFromStr(Tmp, R.Length, TotalLen);
		Release<TChar>(Tmp);
		D.Str = Str;
    }


    _Str_Replace<TChar>(&D);

    GetRec<TChar>(Str).Length = TotalLen;

	//Закрываем данные
    HEAP::Free(D.Positions);
}
//----------------------------------------------------------------------------



//*********************************************************************
//   							TString
//*********************************************************************

#define STRFUNC(Result_Type) template<class TChar> Result_Type TString<TChar>
#define STRCONSTRUCTOR() template<class TChar> TString<TChar>

STRCONSTRUCTOR()::TString(unsigned long StrBufSize)
{
	Data = STRBUF::Alloc<TChar>(StrBufSize);
}

STRCONSTRUCTOR()::TString(const TString& src)
{
	Data = STRBUF::AddRef<TChar>(src.Data);
}


STRCONSTRUCTOR()::TString(const TChar* Src)
{
	Data = STRBUF::CreateFromStr<TChar>(Src, 0, 0);
}

STRCONSTRUCTOR()::TString(const TChar* src, DWORD copylen)
{
	Data = STRBUF::CreateFromStr<TChar>(src, copylen, 0);
}

STRCONSTRUCTOR()::~TString()
{
	STRBUF::Release<TChar>(Data);
}


STRFUNC(DWORD)::Length() const
{
	return  STRBUF::Length<TChar>(Data);
}

STRFUNC(DWORD)::CalcLength()
{
	if (Data)
		STRBUF::GetRec<TChar>(Data).Length = STRUTILS<TChar>::Length(Data);
	return Length();
}

STRFUNC(bool)::IsEmpty() const
{
	return STRUTILS<TChar>::IsEmpty(Data);
}


STRFUNC(TChar*)::t_str() const
{
	// Функция возвращает указатель на данные
	// В случае отсутствия данных функция возвращает
	// указатель на пустую строку
	return (Data)? Data : (TChar*)L"";
}

STRFUNC(void)::Clear()
{
	STRBUF::Release<TChar>(Data);
}


STRFUNC(void)::Copy(const TChar* Source, DWORD Position, DWORD Count)
{
	STRBUF::Copy<TChar>(Data, Source, Position, Count);
}


STRFUNC(void)::Copy(const TString &Source, DWORD Position, DWORD Count)
{
	STRBUF::Copy<TChar>(Data, Source.Data, Position, Count);
}

STRFUNC(void)::Insert(const TChar* Str, DWORD Position)
{
    STRBUF::Insert<TChar>(Data, Str, Position, 0);
}


STRFUNC(void)::Insert(const TString &Str, DWORD Position)
{
	STRBUF::Insert<TChar>(Buf, Str.Data, Position, Str.Length());
}


STRFUNC(void)::Replace(const TChar* Str, const TChar* NewStr)
{
	STRBUF::Replace<TChar>(Data, Str, 0, NewStr, 0);
}

STRFUNC(void)::Replace(const TString &Str, const TString &NewStr)
{
	STRBUF::Replace<TChar>(Data, Str, Str.Length(), NewStr, NewStr.Length());
}


STRFUNC(DWORD)::Hash()
{
	return STRUTILS<TChar>::Hash(Data);
}

STRFUNC(DWORD)::Hash(DWORD Len, bool LowerChar)
{
	return STRUTILS<TChar>::Hash(Data, Len, LowerChar);
}

STRFUNC(void)::Unique()
{
    STRBUF::Unique<TChar>(Data);
}


STRFUNC(void)::ConvertToLinuxFormat()
{
	// Функция преобразовывает строку к формату Linux
	if (Data)
	{
		// Проверяем вхождение символа
		TChar *Start = STRUTILS<TChar>::Scan(Data, '\r');
		if (Start)
		{
			// Сохраняем позицию и уникализируем строку
			DWORD Pos = Start - Data;
			Unique();

			// Заменяем все элементы
			TChar *Str   = Data + Pos;
			TChar *ToCopy = Str;
			while (*Str != 0)
			{
				if (*Str != '\r')
				{
					*ToCopy = *Str;
					ToCopy++;
				}
                Str++;
			}

			*ToCopy = 0;
			STRBUF::GetRec<TChar>(Data).Length = ToCopy - Data;
		}

	}


}


STRFUNC(void)::SetLength(DWORD NewLength)
{
	// Функция устанавливает длину строки
	if (NewLength == 0)
		STRBUF::Release<TChar>(Data);
	else
	{
		if (Data)
		{
			STRBUF::TStrRec &Rec = STRBUF::GetRec<TChar>(Data);

			if (Rec.RefCount > 1 || Rec.Size < NewLength)
			{
				TChar* Tmp = Data;
				Data = STRBUF::CreateFromStr<TChar>(Tmp, Rec.Length, NewLength);
				STRBUF::Release<TChar>(Tmp);
			}
			*(Data + NewLength) = 0;
		}
		else
			Data = STRBUF::Alloc<TChar>(NewLength);

        STRBUF::GetRec<TChar>(Data).Length = NewLength;
	}
}


STRFUNC(int)::Pos(const TChar* SubStr) const
{
	return STRUTILS<TChar>::Pos(Data, SubStr);
}

STRFUNC(int)::Pos(const TString &SubStr) const
{
	return STRUTILS<TChar>::Pos(Data, SubStr.Data);
}


STRFUNC(TString<TChar>&)::Format(const TChar *FormatLine, ...)
{
	// Функция форматирует строку
	STRBUF::Release<TChar>(Data);

	// Так как изначально не получается определить
	// результирующий размер буфера форматируем строку
	// в проыежуточный буфер

	// Выделяем максимально поддерживаемый размер памяти
	TString<TChar> Tmp(1024);

	va_list paramList;
	va_start(paramList, FormatLine);

	int Sz = (sizeof(TChar) == 1) ? (int)pwvsprintfA(Tmp.t_str(), FormatLine, paramList) :
                                    (int)pwvsprintfW(Tmp.t_str(), FormatLine, paramList);
	va_end(paramList);

	Data = STRBUF::CreateFromStr<TChar>(Tmp.t_str(), Sz, 0);

	return *this;
}


STRFUNC(TString<TChar>&)::LongToStr(DWORD num)
{
	STRBUF::Release<TChar>(Data);
	int n = 0;
	STRUTILS<TChar>::LongToString(num, NULL, n);
	SetLength(n);
	STRUTILS<TChar>::LongToString(num, Data, n);
	return *this;
}



STRFUNC(TString<TChar>&)::LowerCase()
{
	if (Data)
	{
		Unique();
		if (sizeof(TChar) == 1)
			pCharLowerBuffA(Data, Length());
		else
            pCharLowerBuffW(Data, Length());
	}
	return *this;
}


STRFUNC(TString<TChar>&)::UpperCase()
{
	if (Data)
	{
		Unique();
		if (sizeof(TChar) == 1)
			pCharUpperBuffA(Data, Length());
		else
            pCharUpperBuffW(Data, Length());
	}
	return *this;
}



STRFUNC(TString<TChar>&)::operator=(const TString &Source)
{
	if (Data != Source.Data)
	{
		STRBUF::Release<TChar>(Data);
		Data = STRBUF::AddRef<TChar>(Source.Data);
    }
	return *this;
}

STRFUNC(TString<TChar>&)::operator=(const TChar* Source)
{
	STRBUF::Release<TChar>(Data);
	Data = STRBUF::CreateFromStr<TChar>(Source, 0, 0);
	return *this;
}

STRFUNC(TString<TChar>&)::operator+=(const TString &Source)
{
	if (Source.Data)
		STRBUF::Append<TChar>(Data, Source.Data, Source.Length());
	return *this;
}

STRFUNC(TString<TChar>&)::operator+=(const TChar* Source)
{
	if (Source)
    	STRBUF::Append<TChar>(Data, Source, 0);
	return *this;
}

STRFUNC(TString<TChar>)::operator+(const TString &Source)
{
	TString<TChar> Temp(*this);
	Temp += Source;
	return Temp;
}

STRFUNC(TString<TChar>)::operator+(const TChar* Source)
{
	TString<TChar> Temp(*this);
	Temp += Source;
	return Temp;
}

STRFUNC(bool)::operator ==(const TString &Str)
{
	return STRUTILS<TChar>::Equal(Data, Str.Data);
}

STRFUNC(bool)::operator ==(const TChar* Str)
{
	return STRUTILS<TChar>::Equal(Data, Str);
}

STRFUNC(bool)::operator !=(const TString &Str)
{
	return !STRUTILS<TChar>::Equal(Data, Str.Data);
}

STRFUNC(bool)::operator !=(const TChar* Str)
{
	return !STRUTILS<TChar>::Equal(Data, Str);
}

STRFUNC(TChar)::operator[](const DWORD Index) const
{
	if (Index < Length())
		return Data[Index];
	else
    	return 0;
}

STRFUNC(TChar&)::operator[](const DWORD Index)
{
	// В нормальном варианте  в случае ошибочного индекса
	// нужно сгенерировать исключение, но бот не использует
	// исключения. Есть потенциальная опастность в случае
	// если индекс выйдет за пределы строки

	Unique();
	return Data[Index];
}

