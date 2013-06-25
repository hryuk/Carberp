
#include <windows.h>

#include "GetApi.h"
#include "BotClasses.h"
#include "Memory.h"
#include "Strings.h"
#include "wincrypt.h"


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

LPVOID List::Last(PList List)
{
	// функция возвращает последний элемент списка
	if (List == NULL) return NULL;
    return List::GetItem(List, List::Count(List) - 1);
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



PDataFile DataFile::CreateFile(PCHAR FileName, DWORD Signature)
{
	// Функция создаёт файл с именем FileName, создаёт структуру описания
	// файла но при этом ничего в файл не записывает
	HANDLE File	= (HANDLE)pCreateFileA(FileName, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (File == INVALID_HANDLE_VALUE)
		return NULL;

	PDataFile Rec = CreateStruct(TDataFile);
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

	PDataFile File = CreateStruct(TDataFile);
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

bool DataFile::WriteFile(PDataFile File)
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
bool DataFile::ReadFile(PDataFile File)
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


