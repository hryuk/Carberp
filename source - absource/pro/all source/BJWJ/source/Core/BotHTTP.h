//---------------------------------------------------------------------------
//  Модуль организации работы с HTTP протоколом
//
//  Версия 1.0
//  Модифицирован: март 2012
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


#ifndef BotHTTPH
#define BotHTTPH

#include <windows.h>
#include <WinSock.h>

#include "GetApi.h"
#include "Strings.h"
#include "BotClasses.h"
#include "BotSocket.h"

// Названия основных методов HTTP запроса
const PCHAR HTTPMethodGET = "GET";
const PCHAR HTTPMethodPOST = "POST";
const PCHAR HTTPMethodHEAD = "HEAD";
const PCHAR HTTPMethodPUT = "PUT";
const PCHAR HTTPMethodDELETE = "DELETE";
const PCHAR HTTPMethodLINK = "LINK";
const PCHAR HTTPMethodUNLINK = "UNLINK";
const PCHAR HTTPMethodCONNECT = "CONNECT";
const PCHAR HTTPMethodOPTIONS = "OPTIONS";
const PCHAR HTTPMethodPATCH = "PATCH";
const PCHAR HTTPMethodTRACE = "TRACE";


// Основные версии HTTP протокола
const PCHAR HTTPProtocolVersion_1_0 = "HTTP/1.0";
const PCHAR HTTPProtocolVersion_1_1 = "HTTP/1.1";

const PCHAR HTTPNoCache = "no-cashe";

// Основные параметры HTTP заголовков
const PCHAR ParamHost = "Host";
const PCHAR ParamReferer = "Referer";
const PCHAR ParamAccept = "Accept";
const PCHAR ParamUserAgent = "User-Agent";
const PCHAR ParamAcceptLanguage = "Accept-Language";
const PCHAR ParamAcceptEncoding = "Accept-Encoding";
const PCHAR ParamContentType = "Content-Type";
const PCHAR ParamContentLength = "Content-Length";
const PCHAR ParamCookie = "Cookie";
const PCHAR ParamProxyConnection = "Proxy-Connection";
const PCHAR ParamPragma = "Pragma";
const PCHAR ParamRange = "Range";
const PCHAR ParamTransferEncoding = "Transfer-Encoding";
const PCHAR ParamConnection = "Connection";
const PCHAR ParamLocation = "Location";
const PCHAR ParamAcceptRanges = "Accept-Ranges";
const PCHAR ParamContentRange = "Content-Range";
const PCHAR ParamLastModified = "Last-Modified";
const PCHAR ParamIfModifiedSince = "If-Modified-Since";
const PCHAR ParamIfNoneMatch = "If-None-Match";
const PCHAR ParamCacheControl = "Cache-Control";
const PCHAR ParamContentMD5   = "Content-MD5";



// Разделители строк
const PCHAR HTTPSpace = " ";
const PCHAR LineBreak = "\r\n";
const PCHAR LineBreak2 = "\r\n\r\n";
const PCHAR ValueDelimeter = ": ";
const PCHAR ValueChunked = "chunked";
const PCHAR ValueNoCacheDocument = "no-store, no-cache, must-revalidate";
const PCHAR URLValueDelimeter = "&";

const PCHAR FormDataURLEncoded = "application/x-www-form-urlencoded";
const PCHAR FormDataMultiPart = "multipart/form-data; boundary=";

const static PCHAR ContentDispositionName = "Content-Disposition: form-data; name=\"";
const static PCHAR FileNameHeader = "; filename=\"";

#define HTTP_CODE_OK 200


// Базовые значения параметров
const PCHAR DefaultPath = "/";
const PCHAR DefaultAccept = "*/*";
const PCHAR DefaultAcceptLanguage = "ru";


const PCHAR HTTPConnectionClose     = "close";
const PCHAR HTTPConnectionKeepAlive = "Keep-Alive";

// Типы HTTP запросов
enum THTTPMethod {hmUnknown, hmGET, hmPOST, hmHEAD};

// Версия HTTP протокола
enum THTTPProtocol {HTTP_1_0, HTTP_1_1};

// Значения заголовка Connection
enum THTTPConnection {hcKeepAlive, hcClose};

enum TPostDataType {pdtUrlEncoded, pdtMultipartFormData};




// Описание HTTP запроса
typedef struct THTTPRequestRec
{
	THTTPMethod Method;         // Метод затпроса
	PCHAR Host;                 // Имя запрашиваемого хоста
	PCHAR Path;                 // Путь к документу
    WORD  Port;                 // Порт удалённого сервера
	PCHAR Referer;              // Адрес с которого идёт запрос
	PCHAR Accept;               // Поддерживаемые типы файлов
	PCHAR AcceptLanguage;       // Поддерживаемый язык
	PCHAR ProxyConnection;      // Тип соединения
	PCHAR UserAgent;            // Имя агента который делает запрос
	PCHAR Cookie;               // Отправляемые куки
	PCHAR ContentType;          // Тип отправляемых данных
	DWORD ContentLength;        // Длина отправляемых данных
	LPVOID PostData;	     	// Отправляемые данные
    TPostDataType PostDataType; // Тип пост данных
	PCHAR Connection;           // Описание соединения
	bool UseRange;              // Использовать пакетную загрузку
	DWORD StartRange;           // Для докачки файлов - Стартовый байт
	DWORD EndRange;             // Конечный байт закачки
} *PHTTPRequestRec;


// Описание ответа HTTP сервера
typedef struct THTTPResponseRec
{
    PCHAR Protocol;        // Протокол ответа
	DWORD Code;            // Код ответа сервера
    PCHAR ResponseLine;    // Описание кода ответа
	PCHAR ContentType;     // Тип загружаемых данных
	DWORD ContentLength;   // Размер загружаемых данных
	PCHAR AcceptRanges;    // Ответ на порционную закачку
    PCHAR Connection;      // Информация о соединении
	PCHAR Location;        // Адрес переадресации
	DWORD StartRange;      // Начало блока в файле
	DWORD EndRange;        // Конец блока в файле
	DWORD FullSize;        // Полный размер файла
	PStrings Headers;      // Список всех заголовков
	PCHAR ResponseText;    // Текст ответа сервера
} *PHTTPResponseRec;


// Описание URL фдреса
typedef struct TURLREC
{
    PCHAR Protocol;
	PCHAR Host;
	PCHAR Path;
	PCHAR Document;
	PCHAR Arguments;
	PCHAR UserName;
	PCHAR Password;
	WORD Port;
} *PURLREC;



#define HTONS(x) (((x) << 8) | ((x) >> 8))


//--------------------------------------------------------------
//  InitializeWSA - Функция инициализирут библиотеку WinSocket
//--------------------------------------------------------------
bool InitializeWSA();




//----------------------------------------------------------------------------
//  Функции для работы с запросами
//----------------------------------------------------------------------------

// Создать структуру запроса
PHTTPRequestRec HTTPCreateRequest(PCHAR URL);

// Создать структуру запроса
void HTTPFreeRequest(PHTTPRequestRec Request);

// Функция очищает структуру HTTP запроса
void HTTPClearRequest(PHTTPRequestRec Request);

// Функция заполняет не указанные поля структуры запроса стандартными данными
void HTTPInitializeRequest(PHTTPRequestRec Request);

// Функция разбирает HTTP запрос в структуру
bool ParseHTTPRequest(PCHAR Buf, PHTTPRequestRec Request);

// Заполнить  структуру запроса данными из адреса
void HTTPSetRequestURL(PHTTPRequestRec Request, PCHAR URL);

namespace HTTPRequest
{

	// Вункция собирает строку запроса
	PCHAR Build(PHTTPRequestRec Request);
};


//*****************************************************************************
//  HTTPResponse - Функции для работы с ответами HTTP сервера
//*****************************************************************************
namespace HTTPResponse
{
	//  Create - создать структуру ответа
	PHTTPResponseRec Create();

	//  Clear - очистить структуру ответа
	void Clear(PHTTPResponseRec Response);

	//  Free - уничтожить структуру ответа
	void Free(PHTTPResponseRec Response);

	//  Parse - парсить ответ сервера
	bool Parse(PCHAR Buf, PHTTPResponseRec Response);
}


//*****************************************************************************
//  Chunks - Методы для работы с передачей данных частями
//*****************************************************************************
typedef struct TChunks
{
	DWORD Size;      // Размер блока
	DWORD Readed;    // Размер прочитанных данных
    bool Completed;  // Признак того, что документ полностью загружен
} *PChunks;

namespace Chunks
{
	// Функция проверяет заголовок ответа и в случае если
	// если значение заголовка Transfer-Encoding = chunked
	// создаёт структуру для работы с загружаемыми данными
	PChunks Initialize(PCHAR HTTPResponse);

	// Функция уничтожает структуру
	void Free(PChunks Chunks);

	//  Обработать блок данных
	//  После обработки буфера значение Size будет изменёно
	void HandleDataBlock(PChunks Chunks, LPBYTE Data, DWORD &Size);

	// Функция получает размер блока и возвращает указатель на его начало
	LPBYTE GetChunkSize(LPBYTE Buf, DWORD BufSize, DWORD &Size);
}


//----------------------------------------------------------------------------
//  Дополнительные функции для работы с HTTP
//----------------------------------------------------------------------------

PCHAR GetMethodStr(THTTPMethod Kind); // получить строку метода по номеру
THTTPMethod GetMethodFromStr(PCHAR Method);

void AddURLParam(PStrings S, PCHAR Name, PCHAR Value, DWORD ValueSize = 0); // кодирует значение и добавляет пару в список

bool ParseURL(PCHAR URL, PURLREC Rec, bool FullPars = false); // Распарсить URL
void ClearURL(PURLREC URL);


PCHAR URLEncode(PCHAR URL, DWORD URLSize = 0); // Кодировать URL строку

//------------------------------------------------
//  URLDecode - Функция декодирует URL
//              кодированную строку
//------------------------------------------------
string URLDecode(const char *URL);


bool ParseRequestFirstLine(PCHAR Line, PCHAR *Method, PCHAR *Path, PCHAR *ProtVersion);
PCHAR GetURLEncodedPostData(PCHAR Buf);

//*****************************************************************************
//  HTTPParser - Парсер HTTP данных
//*****************************************************************************
namespace HTTPParser
{
	bool ParseResponseLine(PCHAR Buf, PCHAR &Protocol, DWORD &Code, PCHAR &StatusLine);

	// Функция возвращает значение HTTP заголовка
	PCHAR GetHeaderValue(PCHAR Buf, PCHAR Name);

	// Установить значение заголовка
	bool SetHeaderValue(PCHAR Buf, DWORD BufSize, DWORD MaxBufSize, PCHAR Header, PCHAR Value, DWORD *NewBufSize);

	// Удалить заголовок из HTML документа. Документ должен содержать
	// ответ HTTP сервера
	//	Функция возвращает новый размер буфера
    DWORD DeleteHeader(PCHAR Header, PCHAR HTML, DWORD HTMLSize);
}

//*****************************************************************************
// Методы для работы с HTTP данными
//*****************************************************************************
namespace HTTPUtils
{
    PCHAR DeleteHeaderValue(PCHAR Buf, int &Size, PCHAR Header);
}

//***************************************************************************
//  MultiPartData - Методы для работы с пост данными формата a
//                  multy part form dat
//***************************************************************************


typedef struct TMultiPartDataRec
{
	PList Items;
	PCHAR Boundary;

    DWORD ReadIndex;  // Позиция читаемого элемента
} *PMultiPartData;


enum TMultiItemReadState {mprsUnknown, mprsHeader, mprsData, mprsBoundary, mprsCompleted};

typedef struct TMultiPartItem
{
	PCHAR  Name;        // Имя поля
	PCHAR  FileName;    // Имя файла
	LPVOID Data;        // Буфер данных
	DWORD  Size;        // Размер буфера
	PCHAR  ContentType; // Тип контента файла

	// Следующие поля необходимы только для записи данных в сокет
	PCHAR Header;      // Заголовок элемента (для отправки)
	TMultiItemReadState ReadState; // Состояние чтения элемента
	DWORD ReadedSize;  // Размер прочитанных данных
	HANDLE FileHandle; // Идентификатор открытого файла
	PCHAR Boundary;    // Конечная граница элемента
} *PMultiPartItem;



namespace MultiPartData
{
	// Создать структуру данных
	PMultiPartData Create();

	// Уничтожить структуру данных
	void Free(PMultiPartData Data);

	// Добавить бинарные данные
	PMultiPartItem AddBlobField(PMultiPartData Data, PCHAR Name, LPBYTE Value, DWORD ValueSize);

	// Добавить текстовое поле
	PMultiPartItem AddStringField(PMultiPartData Data, PCHAR Name, PCHAR Value);

	// Добавить файл
	PMultiPartItem AddFileField(PMultiPartData Data, PCHAR Name, PCHAR FileName, PCHAR ContentType);

	// Добавить двоичные данные как файл
	PMultiPartItem AddBlobAsFile(PMultiPartData Data, PCHAR Name, PCHAR FileName,
								 PCHAR ContentType, LPBYTE Value, DWORD ValueSize);

	// Добавить длинное целое как строку
	PMultiPartItem AddLongAsStr(PMultiPartData Data, PCHAR Name, DWORD Value);

	// Функция читаем следующий блок данных.
	// Результат - количество прочитанных байт
	// Примечание - если на вход передать нулевой буфер, то
	// функция вернёт общий размер пост данных
	DWORD Read(PMultiPartData Data, LPBYTE Buffer, DWORD BufferSize);

	// Записать данные в блок памяти
	LPBYTE BuildToBuf(PMultiPartData Data, DWORD &ResultSize);
}

//---------------------------------------------------------------
//  ConnectToHost - Функция подключается к указанному хосту
//---------------------------------------------------------------
SOCKET ConnectToHost(PCHAR Host, int Port);
SOCKET ConnectToHostEx(const char* Host, int Port, DWORD TimeoutSec);


//*****************************************************************************
//  HTTP - методы выполнения HTTP запросов
//*****************************************************************************
namespace HTTP
{
	// Структура описания принимаемых данных
	typedef struct TResponseData
	{
		PCHAR *Buffer;   // Указатель на переменную буфера приёма
		DWORD *Size;     // Указатель на переменную размера принятых данных
		PCHAR *Headers;  // Указатель на переменную хранения заголовоков ответа сервера
        THTTPResponseRec Response; // Структура ответа
	}*PResponseData;

	//********************************************************
	//  ExecuteMethod - выполнить HTTP запрос к серверу
	//********************************************************
	bool ExecuteMethod(PHTTPRequestRec Request, PResponseData Response);


	//********************************************************
	//  Get - отправить GET запрос
	//
	//  URL - адрес загружаемой страницы
	//  Buf - Указатель на переменную строки. Переменная будет
	//		  инициализирована во время выполнения функции
	//        Если не указать, то метод не будет дожидаться
	//		  ответа сервера.
	//        Уничтожить функцией StrFree
	//
	//  Результат - Вернёт истину если удалось выполнить
	//		запрос. Код ответа не проверяется
	//********************************************************
	bool Get(PCHAR URL, PCHAR *Buf, PHTTPResponseRec Response);


	//********************************************************
	//  Post - отправить GET запрос
	//
	//  URL - адрес загружаемой страницы
	//
	//  Fields - POST данные запроса
	//
	//  Buf - Указатель на переменную строки. Переменная будет
	//		  инициализирована во время выполнения функции
	//        Если не указать, то метод не будет дожидаться
	//		  ответа сервера.
	//        Уничтожить функцией STR::Free
	//
	//  Результат - Вернёт истину если удалось выполнить
	//		запрос. Код ответа не проверяется
	//********************************************************
	bool Post(PCHAR URL, PStrings Fields, PCHAR *Buf, PHTTPResponseRec Response);
	bool Post(PCHAR URL, PMultiPartData Fields, PCHAR *Buf, PHTTPResponseRec Response);
}



//*****************************************************************************
//
//*****************************************************************************


// Типы браузеров
#define BROWSER_TYPE_IE		1  // Internet Explorer
#define BROWSER_TYPE_FF		2  // Mozilla Firefox
#define BROWSER_TYPE_O		3  // Opera


// Описание сессии загрузки HTML документа
typedef struct THTTPSessionInfo{
	DWORD BrowserType;  // Тип браузера
	PCHAR UserAgent;    // Имя браузера
	PCHAR URL;          // Адрес загружаемого ресурса
} *PHTTPSessionInfo;


// ***************************************************************************
// ***************************************************************************


class TURL;
class THTTP;


//----------------------------------------------------------------
//   TURL  - Класс для работы синтернет адресами
//----------------------------------------------------------------
class TURL : public TBotObject
{
private:
	bool DoParse(const char *URL);
    void NormalizePath();
public:
	string Protocol;
	string Host;
	string Path;
	string Document;
	string Params;
	WORD Port;

	TURL(const char *URL = NULL);
	~TURL() {};

	void   Clear();
	bool   Parse(const char *URL);
	string GetPathAndDocument();
	string URL(); // Функция собирает полный адрес
};




//----------------------------------------------------------------
//  THTTPRequest - класс формирования заголовка запроса к HTTP
//  			   серверу
//----------------------------------------------------------------

class THTTPRequest : public TBotObject
{
private:
	friend class THTTP;
	string MakeHeaders();
	void   AddHeader(string &Buf, const char *Name, const char *Value, bool CheckValue = true);
	void   AddHeader(string &Buf, const char *Name, const string &Value, bool CheckValue = true);
	string GetUserAgent();
public:
	THTTPProtocol   Protocol;
	THTTPMethod     Method;
	bool   CloseConnection;  // Посде запроса закрыть соединение
	string ProtocolStr;
	string Host;
	string Path;
	WORD   Port;
	string Accept;         // Поддерживаемые типы файлов
	string AcceptEncoding; // Поддерживаемая кодировка данных
	string UserAgent;      // Имя агента
	string Referer;        // Адрес с которого совершается переход
	DWORD  ContentLength;  // Размер пост данных
	string ContentType;    // Тип пост данных

	THTTPRequest();
	~THTTPRequest() {};

	void SetURL(const char* aURL);
	string MakeRequestHeaders();
};


//----------------------------------------------------------------
//  THTTPResponse - класс обработки заголовка ответа HTTP сервера
//----------------------------------------------------------------
class THTTPResponse : public TBotObject
{
private:
	string        FHTTPData;
	THTTPRequest* FRequest;

	void Parse();
	bool ParseFirstLine(const char* Line);

	friend class THTTP;
public:
	// Свойства класса
	WORD   Code;             // Код ответа
	string Protocol;         // информация о протоколе
	string StatusLine;       // Коментарий к коду ответа
	string ContentType;      // Тип контента
	int    ContentLength;    // Размер данных. (-1 означает, что заголовок не передавался)
	string CacheControl;     // Управление кэшированием
	string Location;         // Адрес перехода при редиректе
	string Pragma;           // Особые опции выполнения
	string TransferEncoding; // Механизм передачи данных
	string MD5;              // MD5 хэш содержимого

	bool Chunked;        // Признак того, что данные передаются поблочно. см TransferEncoding
	TBotStrings Headers; // Все заголовки ответа

	// Методы класса
	THTTPResponse();
	~THTTPResponse();

	//---------------------------------------------------
	//	AddData - Функция добавляет порцию полученных
	//  от сервера данных.
	//  Buf - Указатель на буфер с данными. После
	//        обработки будет указывать на данные
	//        после заголовка
	//  BufSize - Размер прочитанных данных. После
	//            обработки бутет содержать размер
	//            Оставшихся в буфере данных
	//
	//  Результат: Функция вернёт истину если заголовок
	//             прочитан полностью
	//---------------------------------------------------
	bool AddData(PCHAR &Buf, int &BufSize);

	void Clear();
};


//----------------------------------------------------------------
//  THTTPChunks - класс обработки блочного механизма передачи
//                данных  HTTP сервером
//----------------------------------------------------------------
class THTTPChunks : public TBotObject
{
private:
    enum TState {Unknown, IgnoreSizeEnd, IgnoreBlockEnd, WriteData};

    THTTP*      FOwner;
	TBotStream* FStream;
	int    FSize;
	TState FState;
	string FSizeBuf;
	int    FIgnoreSize;
	bool   FLastBlock;
	bool   FCompleted;
	bool GetSize(PCHAR &Buf, int &Size);
	bool Ignore(PCHAR &Buf, int &Size);
	void WriteChunk(PCHAR &Buf, int &Size);
public:
    THTTPChunks(THTTP* Owner, TBotStream* Stream);
	void Initialize(TBotStream* Stream);
	void Write(PCHAR Buf, int BufSize);
    bool Completed();
};



//----------------------------------------------------------------
//  TMultiPartDataItem - Кдасс хранения информации о блоке данных
//                       отправляемых на сервер
//----------------------------------------------------------------
class TMultiPartDataItem : public TBotCollectionItem
{
private:
	LPVOID FData;          // Данные поля
	DWORD  FSize;          // Размер данных
	string FName;          // Имя поля
	string FFileName;      // Имя файла
	string FContentType;   // Тип контента, для файлов
	string FBlockHeader;   // Заголовок блока, используется при отправке
	TBotStream *FFile;     // Пото чтения данных файла

	void SetData(LPVOID Data, DWORD DataSize);
	void MakeHeader();
    bool WriteDataToBuf(LPBYTE Buf, DWORD BufSize, DWORD Offset, DWORD &Writen);
	friend class TMultiPartData;
public:
	TMultiPartDataItem(TBotCollection* Owner);
	TMultiPartDataItem(TBotCollection* Owner, LPVOID Data, DWORD DataSize);
	~TMultiPartDataItem();

	LPVOID inline Data() { return FData; }
	DWORD  inline Size() { return FSize; }
};


//----------------------------------------------------------------
//  TMultiPartData - класс для работы с данными HTML формы в
//                   формате multipart/form-data
//----------------------------------------------------------------
class TMultiPartData : public TBotStream
{
private:
	TBotCollection FItems;
	string FBoundary;

	DWORD FPosition;
	int   FCurrentItem;
	int   FReadOffset;

	enum TReadPart {rpBoundaryStart, rpBoundary, rpBoundaryLB, rpHeader,
					rpData, rpDataLB, rpBoundaryEnd, rpCompleted};

	TReadPart FCurrentPart;

    friend class THTTP;
public:
	TMultiPartData();

	DWORD Size();
	DWORD Read(void* Buf, DWORD BufSize);

	// Функции добавления данных
	void        Add(const char*   Name, LPVOID Data, DWORD Size);
	void inline Add(const char*   Name, const char* Data)        { Add(Name, (LPVOID)Data, STRA::Length(Data)); }
	void inline Add(const string& Name, LPVOID Data, DWORD Size) { Add(Name.t_str(), Data, Size); };
	void inline Add(const string& Name, const char* Data)        { Add(Name.t_str(), Data); }
	void inline Add(const char*   Name, const string& Data)      { Add(Name, Data.t_str(), Data.Length()); }
	void inline Add(const string& Name, const string& Data)      { Add(Name.t_str(), Data.t_str(), Data.Length()); }

	// Функции добавления файлов
	void AddFile(const char* Name, const char* FileName, const char* CotentType, const char* SendName);
	void AddBlobAsFile(const char* Name, const char* FileName, LPVOID Data, DWORD DataSize, const char* CotentType);

};


//----------------------------------------------------------------
//   THTTP  - Класс для передачи-приёма данных по HTTP протоколу
//----------------------------------------------------------------
class THTTP : public TBotObject
{
private:
	TBotSocket  *FSocket;
	THTTPChunks *FChunks;
	bool FSocketCreated;
	bool FDocumentCompleted;
	int  FDocumentSize;

	void Initialize();
	bool Execute(THTTPMethod Method, const char *URL, TBotStream *PostData, TBotStream *ResponseStream);
	bool SendPostData(TBotStream* Data);
	bool ExecuteToStr(THTTPMethod Method, const char *URL, TBotStream *PostData, string &Document);
	bool ReceiveData(TBotStream *ResponseStream);
	void WriteReceivedData(TBotStream* Stream, PCHAR Buf, int BufLen);
	void WriteStringsToStream(TBotStream* Stream, TBotStrings* Strings);

    friend class THTTPChunks;
protected:
	void virtual DoBeforePostData(TBotStream* PostData);
    void virtual DoDownloadCompleted(TBotStream* ResponseData);
public:
	THTTPRequest  Request;
	THTTPResponse Response;
	bool   CheckOkCode;

	// StatusText - Если CheckOkCode == true то в это полу будет
	// записан ответ в случае кода отличного от 200
	string StatusText;

	// Методы класса
	THTTP();
	THTTP(TBotSocket* Socket);
	virtual ~THTTP();

    int DocumentSize();

	// Следующие методы выполняют запросы к HTTP серверу.
	//
	// ВАЖНО!!!!!
	// Для методов, которые возвращают true если запрос
	// прошёл успешно, следует учесть, что, по умолчанию,
	// true возвращается только в том случае если
	// удалось отправить запрос и получить ответ с кодом 200!!!
	// для того, чтобы получать истину только в случае успешной отправки
	// и получения данных, не обращая внимания на код ответа,
	// следует установить
	// CheckOkCode = false;

	bool   Get(const char *URL, string &Document);
	string Get(const char *URL);
	bool   Get(const char *URL, TBotStream *ResponseData);

	bool   Post(const char *URL, TBotStrings *Fields, string &Document);
	string Post(const char *URL, TBotStrings *Fields);
	bool   Post(const char *URL, TMultiPartData *Fields, string &Document);
	string Post(const char *URL, TMultiPartData *Fields);
};


//-----------------------------------------------
//  DownloadFile - Функция загружает документ в
//                 файл
//-----------------------------------------------
bool DownloadFile(const char* URL, const char* FileName);


//---------------------------------------------------------------------------
#endif
