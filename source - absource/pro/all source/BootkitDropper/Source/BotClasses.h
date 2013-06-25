#ifndef BotClassesH
#define BotClassesH


//---------------------------------------------------------------------------

#include <windows.h>
#include "Crypt.h"



/*----------------  Методы для работы со списками элементов -----------------*/

typedef LPVOID PList;

typedef void (*TFreeItemMethod)(LPVOID);

namespace List
{
	// Функция создания списка
	PList Create();

	// Функция уничтожения списка
	void Free(PList List);

	// Функция очистки списка
	void Clear(PList List);

	// Функция возвращает количество элементов списка
	DWORD Count(PList List);

	// Функция добавляет новый элемент
	int Add(PList List, LPVOID Item);

	// Функция удаляет элемент из списка
	void Delete(PList List, DWORD Index);

	// Удалить из списка элемент
	int Remove(PList List, LPVOID Item);

	// Извлечь элемент
	 LPVOID Extract(PList List, DWORD Index);

	// Функция возвращает позицию элемента в списке
	int IndexOf(PList List, LPVOID Item);

	// Функция устанавливает значение элементу ы указанной позиции Index
	void SetItem(PList List, DWORD Index, LPVOID Item);

	// Функция возвращает значение элемента из позиции Index
	LPVOID GetItem(PList List, DWORD Index);

	// Изменить размер зарегистрированных элементов
	bool SetCapacity(PList List, DWORD Value);

	// Установить метод автоматического удаления элементов
	void SetFreeItemMehod(PList List, TFreeItemMethod Method);

	// функция возвращает последний элемент списка
	LPVOID Last(PList List);
}


//---------------------------------------------------------------------------
//  MEMBLOCKS - Функции для работы с блоками памяти, списками блоков
//---------------------------------------------------------------------------
typedef struct TMemBlock
{
	DWORD ID;    // Идентификатор блока, зарезервировано для записи в файл
	DWORD Size;
	LPVOID Data;
}*PMemBlock;

typedef LPVOID PMemBlockList;

namespace MEMBLOCK
{
	// Создать список блоков
	PMemBlockList CreateList();

	// Уничтожить список блоков
	void FreeList(PMemBlockList List);

	// добавить новый блок в список
    PMemBlock AddBlock(PMemBlockList List, LPVOID Data, DWORD DataSize, bool Copy = true);

	// уничтожить блок памяти. ВАЖНО!!!! Мтодот оссвобождает память блока, но не
	// удаляет блок из списка (если он в нём находится);
	void FreeBlock(PMemBlock Block);

	// Функция подсчитывает общий размер данных всех блоков списка
	DWORD Size(PMemBlockList List);

	// Функция копирует данные всех блоков в буфер Buf.
	// Подразумевается, что Buf может уместить в себе все блоки
    void BuildToBuf(PMemBlockList List, LPVOID Buf);

	// Функция собирает все блоки в строку
	PCHAR BuildAsStr(PMemBlockList List, DWORD *TotalSize);

	// Функция собирает все блоки в строку
	LPVOID BuildAsMem(PMemBlockList List, DWORD *TotalSize);

	// Функция объеденяет блоки в один
	PMemBlock Pack(PMemBlockList List);

	// Получить блок по идентификатору
	PMemBlock GetBlockByID(PMemBlockList List, DWORD ID);
	PCHAR GetBlockByAsStr(PMemBlockList List, DWORD ID);
}


//---------------------------------------------------------------------------
//  DataFile - методы для работы с файлами данными
//---------------------------------------------------------------------------

#pragma pack(push, 1)
typedef struct TDataFileHead
{
	DWORD Signature;  // Сигнатура файла
	DWORD Version;    // Версия файла
	DWORD FileID;     // Идентификатор файла
	DWORD Flags;      // Флаги файла
	DWORD FlagsEx;    // Дополнительные флаги
} *PDataFileHead;     // Имя файла
#pragma pack(pop)


enum TFileCryptMode {fcNone, fcBlock, fcFile};

typedef struct TDataFile
{
	HANDLE Handle;              // Идентификатор файла
	TDataFileHead Head;         // Заголовок файла
	TFileCryptMode CryptMode;   // Режим шифрования данных файла
	TCryptMethod CryptMethod;   // Метод криптования
	TCryptMethod DecryptMethod; // Метод расшифровки данных
	LPVOID CryptKey;            // ключ шифрования
	PMemBlockList Blocks;       // Список блоков
	PCHAR FileName;
} *PDataFile;


#define DATA_FILE_VERSION 1

// Максрос возвращает DWORD из данных указателя
#define SIGNATURE(Pointer) (*(DWORD*)Pointer)

namespace DataFile
{
	// Функция создаёт файл с именем FileName, создаёт структуру описания
	// файла но при этом ничего в файл не записывает
    PDataFile CreateFile(PCHAR FileName, DWORD Signature);

	// Функция открывает файл для чтения и читает из него заголовок
	PDataFile OpenFile(PCHAR FileName, DWORD Signature);

	// Записывает данные из структуры File в физический файл
	bool WriteFile(PDataFile File);

	// Читает данные из физического файла в структуру File
	bool ReadFile(PDataFile File);

	// Функция закрывает файл и уничтожает структуру File
    void CloseFile(PDataFile File);

	// Добавить блок данных
	void AddDataBlock(PDataFile File, DWORD BlockID, LPVOID Data, DWORD DataSize, bool Copy = true);
	void AddDataBlock(PDataFile File, DWORD BlockID, PCHAR StrData);

	// Записать блоки данных ф файл
	bool WriteBlocksToFile(PDataFile File);

	// Записать блоки данных ф файл
	bool ReadBlocksFromFile(PDataFile File);

	// Зашифровать блоки данных
    bool CryptBlocks(PMemBlockList Blocks, LPVOID Key, TCryptMethod Method);
}


//---------------------------------------------------------------------------
#endif
