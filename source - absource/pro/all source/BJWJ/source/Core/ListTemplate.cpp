
//*****************************************************************************
//
//     Для облегчения чтения заголовочного модуля с описанием шаблона списка
//     реализацию шаблона выведем в отдельный файл
//
//*****************************************************************************


#ifndef BotClassesH
	#error Exclude module from project
#endif


#define LISTFUNC(Result_Type) template<class TItem> Result_Type TListTemplate<TItem>
#define LISTCONSTRUCT() template<class TItem> TListTemplate<TItem>


LISTCONSTRUCT()::TListTemplate()
{
	// Конструктор списка
	FCount    = 0;
	FCapacity = 0;
	FItems    = NULL;

	// из-за того, что тип элементов заранее не известен
	// и в функциях получения элементов мы не можум отреагировать
	// исключением на ошибочные параметры, зарезервирем пустой
	// элемент, который будем возвращать в случае ошибок
	// Необходимость под вопросом.
	m_memset(&FEmptyItem, 0, sizeof(TItem));
}
//-------------------------------------------------------------------

LISTCONSTRUCT()::~TListTemplate()
{
	// Деструктор списка
	Clear();
}

//-------------------------------------------------------------------

LISTFUNC(int)::Add(TItem Item)
{
	// Добавляем элемент в список

	if (FCount == FCapacity)
	{
		if (!UpdateCapacity())
			return -1;
    }

	int Index = FCount;
	FItems[FCount] = Item;
	FCount++;

	return Index;
}
//-------------------------------------------------------------------

LISTFUNC(int)::Count()
{
    return FCount;
}
//-------------------------------------------------------------------

LISTFUNC(void)::Clear()
{
	// Функция очищает список

	if (!FItems) return;

	// Возможно для удаления элемента из списка необходимо произвести
	// дополнительные действия, по этоий элементы извлекаем поочерёдно
	// начиная с конца
	while (FCount)
	{
		FCount--;
		if (FItems[FCount])
			DoDelete(FItems[FCount]);
    }

    // Обнуляем поля
	FCapacity = 0;

	HEAP::Free(FItems);
	FItems = NULL;
}
//-------------------------------------------------------------------

LISTFUNC(void)::Delete(int Index)
{
	// Удаляем элемент из списка
	if (!CheckIndex(Index)) return;

	TItem Temp = FItems[Index];

	FCount--;
	if (Index < FCount)
	{
		// Переносим блок памяти находящийся за удалённым элементом
		TItem* Dest = FItems;
		Dest += Index;
		TItem* Source = Dest;
		Source++;
        m_memcpy(Dest, Source, (FCount - Index) * sizeof(TItem));
	}

	// При необходимости уничтожаем элемент
	DoDelete(Temp);
}
//-------------------------------------------------------------------

LISTFUNC(void)::DoDelete(TItem Item)
{
	// Зарезервировано для дополнительных действий над элементами
	// при их удалении из списка
}
//-------------------------------------------------------------------

LISTFUNC(int)::IndexOf(TItem Item)
{
	// Функция возвращает позицию элемента в списке

	for (int i = 0; i < FCount; i++)
	{
		if (FItems[i] == Item) return i;
	}

	return -1;
}
//-------------------------------------------------------------------

LISTFUNC(int)::Remove(TItem Item)
{
	// Функция удаляет указанный элемент из списка
	int Index = IndexOf(Item);

	if (Index >= 0)
        Delete(Index);

	return Index;
}
//-------------------------------------------------------------------

LISTFUNC(bool)::SetCapacity(int Value)
{
	// Функия резервирует память
	if (Value > FCount && Value != FCapacity)
	{
        // Создаём новый буфер
		if (HEAP::ReAlloc2((LPVOID &)FItems, Value * sizeof(TItem)))
		{
			FCapacity = Value;
			return true;
        }
	}
	return false;
}
//-------------------------------------------------------------------

LISTFUNC(bool)::UpdateCapacity()
{
	// Функция добавляет блок памяти
	DWORD Delta;
	if (FCapacity > 64)
		Delta = FCapacity / 4;
	else
	if (FCapacity > 8)
		Delta = 16;
	else
		Delta = 4;

	return SetCapacity(FCapacity + Delta);
}
//-------------------------------------------------------------------

LISTFUNC(bool)::CheckIndex(int Index)
{
	// Функция проверяет правильность индекса
	return Index >= 0 && Index < FCount;
}
//-------------------------------------------------------------------

LISTFUNC(TItem)::GetItem(int Index)
{
	// Функция возвращает элемент с указанным инжексом
    return (CheckIndex(Index)) ? FItems[Index] : FEmptyItem;
}
//-------------------------------------------------------------------

LISTFUNC(void)::SetItem(int Index, TItem Item)
{
	// Функция устанавливает элемент с указанным индексом
	if (CheckIndex(Index))
		FItems[Index] = Item;
}
//-------------------------------------------------------------------

LISTFUNC(TItem)::operator[](int Index)
{
    return GetItem(Index);
}
//-------------------------------------------------------------------
