#include <windows.h>

#include "Strings.h"
#include "Memory.h"
#include "BotClasses.h"
#include "GetApi.h"
#include "Utils.h"
#include "BotHTTP.h"

//#include "BotDebug.h"

//---------------------------------------------------------------------------

PHTTPRequest HTTPCreateRequest(PCHAR URL)
{
	// Создать структуру запроса
	PHTTPRequest R = CreateStruct(THTTPRequest);
	R->Method = hmGET;

	if (URL != NULL)
	{
		PURL UR = CreateStruct(TURL);
		if (ParseURL(URL, UR, false))
		{
			// Переносим параметры
			R->Host = UR->Host;
			R->Path = UR->Path;
			R->Port = UR->Port;
			UR->Path = NULL;
			UR->Host = NULL;
		}

		ClearURL(UR);
		FreeStruct(UR);
    }

	if (R->Port == 0)
		R->Port = PortHTTP;
	return R;
}
//---------------------------------------------------------------------------

void HTTPFreeRequest(PHTTPRequest Request)
{
	// Создать структуру запроса
	if (Request == NULL)
		return;
	HTTPClearRequest(Request);
	FreeStruct(Request);
}
//---------------------------------------------------------------------------

void HTTPClearRequest(PHTTPRequest Request)
{
	// Функция очищает структуру HTTP запроса
	if (Request == NULL)
		return;

	Request->Method = hmUnknown;
	Request->ContentLength = 0;

	STR::Free2(Request->Host);
	STR::Free2(Request->Path);
	STR::Free2(Request->Referer);
	STR::Free2(Request->Accept);
	STR::Free2(Request->AcceptLanguage);
	STR::Free2(Request->ProxyConnection);
	STR::Free2(Request->UserAgent);
	STR::Free2(Request->Cookie);
	STR::Free2(Request->ContentType);
	STR::Free2(Request->Connection);
	if (Request->PostDataType == pdtUrlEncoded && Request->PostData != NULL)
	{
		STR::Free((PCHAR)Request->PostData);
		Request->PostData = NULL;
	}
	ClearStruct(*Request);
}
//----------------------------------------------------------------------------
void SetDefaultPort(PHTTPRequest R)
{
	// Устанавливаем порт по умолчанию, если в запросе не установлен
	if (R->Port == 0)
		R->Port = PortHTTP;
}

void SetParam(PCHAR &Attr, PCHAR Value)
{
	// инициализировать параметр. если он нулевой
	if (Attr == NULL)
		Attr = STR::New(Value);
}

void HTTPInitializeRequest(PHTTPRequest Request)
{
	// Функция заполняет не указанные поля структуры запроса стандартными данными
	if (Request == NULL)
		return;

	if (Request->UserAgent == NULL)
	{
		DWORD BufSize = 1024;
		PCHAR Buf = STR::Alloc(BufSize);
		pObtainUserAgentString( 0, Buf, &BufSize);
		Request->UserAgent = STR::New(Buf);
		STR::Free(Buf);
	}

	SetDefaultPort(Request);

	
//	__asm int 3;
	SetParam(Request->Accept, DefaultAccept);
//	__asm int 3;
	SetParam(Request->AcceptLanguage, DefaultAcceptLanguage);
//	__asm int 3;
	SetParam(Request->Connection, DefaultConnection);

	if (Request->Method == hmPOST)
	{
		// Устанавливаем тип контента

		if (Request->ContentType == NULL)
		{
			if (Request->PostDataType == pdtUrlEncoded)
				Request->ContentType = STR::New(FormDataURLEncoded);
			else
			{
                PMultiPartData D = (PMultiPartData)Request->PostData;
				Request->ContentType = STR::New(2, FormDataMultiPart, D->Boundary);
            }
        }

		// Определяем размер пост данных
		if (Request->ContentLength == 0)
		{

			if (Request->PostDataType == pdtUrlEncoded)
				Request->ContentLength = StrCalcLength((PCHAR)Request->PostData);
			else
				Request->ContentLength = MultiPartData::Read((PMultiPartData)Request->PostData, NULL, NULL);

        }
	}
}

void HTTPSetRequestURL(PHTTPRequest Request, PCHAR URL)
{
	// Заполнить  структуру запроса данными из адреса

}
//---------------------------------------------------------------------------

void AddParam(PStrings S, PCHAR Name, PCHAR Value, bool Valid = true)
{
	// В случае если Valid == true и значение не равно NULL добавляем
	// Значение в список
	if (Valid && !STR::IsEmpty(Value))
		Strings::AddValue(S, Name, Value, ValueDelimeter);
}

PCHAR HTTPRequest::Build(PHTTPRequest Request)
{
	// Вункция собирает строку запроса
	if (Request == NULL || STR::IsEmpty(Request->Host))
		return NULL;

    HTTPInitializeRequest(Request);

	 // Собираем первую строку запроса
	PCHAR Top = GetMethodStr(Request->Method);
	if (Top == NULL)
		return NULL;

	PStrings S = Strings::Create();


	StrConcat(Top, 4, " /", Request->Path, " ", HTTPProtocolVersion_1_1);
	Strings::Add(S, Top);
    STR::Free(Top);

	// Добавляем параметры
	AddParam(S, ParamAccept, Request->Accept);
	AddParam(S, ParamUserAgent, Request->UserAgent);

	if (Request->UseRange)
	{
		// Заполняем заголовок Range
		PCHAR Start = StrLongToString(Request->StartRange);
		PCHAR End = NULL;
		if (Request->EndRange != 0)
			End = StrLongToString(Request->EndRange);

        PCHAR Value = STR::New(4, "bytes=", Start, "-", End);

        AddParam(S, ParamRange, Value);

		STR::Free(Start);
		STR::Free(End);
		STR::Free(Value);
    }

	AddParam(S, ParamReferer, Request->Referer);
	AddParam(S, ParamHost, Request->Host);
	AddParam(S, ParamConnection, Request->Connection);
	if (Request->Method == hmPOST)
	{
		// Добавляем информацию о пост данных
		AddParam(S, ParamContentType, Request->ContentType);
		PCHAR CL = StrLongToString(Request->ContentLength);
		AddParam(S, ParamContentLength, CL);
        STR::Free(CL);
	}

	// Добавляем заверщающие строки
	Strings::Add(S, "\r\n");

	PCHAR Result = Strings::GetText(S);
	Strings::Free(S);
	return Result;
}
//---------------------------------------------------------------------------

PCHAR GetMethodStr(THTTPMethod Kind)
{
 // получить строку метода по номеру
	 switch (Kind) {
		case hmGET:
			return STR::New(HTTPMethodGET);
		case hmPOST:
			return STR::New(HTTPMethodPOST);
		case hmHEAD:
			return STR::New(HTTPMethodHEAD);
	 default:
	 	return NULL;
		 ;
	 }
}

PCHAR URLEncode(PCHAR URL, DWORD URLSize)
{
	// Функция кодирует URL строку
    DWORD Len;
	if (URLSize == 0)
		Len = StrCalcLength(URL);
	else
        Len = URLSize;

	if (Len == 0)
		return NULL;

	char Hex[] = "0123456789ABCDEF";

    // Резервируем временный буфер
	PCHAR Buf = STR::Alloc(Len*3);
	if ( Buf == NULL )
		return NULL;


	PCHAR p = URL;
	PCHAR r = Buf;
	DWORD Pos = 0;
	DWORD ResLen = 0;
//	char Code;

	typedef int ( WINAPI *fwsprintfA )( PCHAR lpOut, PCHAR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );


    // Кодируем строку
	while (Pos < Len)
	{
		if (*p == 0)
		{
			*(r++) = 0;
			ResLen++;
            continue;
        }
		if ( ( *p >= 'A' && *p <= 'Z' ) ||
			 ( *p >= 'a' && *p <= 'z' ) ||
			 ( *p >= '0' && *p <= '9' ) )
		{
			*(r++) = *p;
			ResLen++;
		}
		else
		{
			*(r++) = '%';
			_pwsprintfA(r++, "%02X", (BYTE)*p);
			r++;
			ResLen += 3;
//			Code = (*p >> 4);
//			Code = Code  & 0x0F;
//			*(r++) = Hex[Code];
//			Code = *p & 0xF;
//			*(r++) = Hex[Code];
		}

		p ++;
		Pos++;
    }

	// Возвращаем строку по фактическому размеру буфера
	PCHAR Res = STR::New(Buf, ResLen);
    STR::Free(Buf);
	return Res;
}

// Функция ставит ноль на текущую позицию и смещает указатель за него
#define IncStrEx(S) if(S != NULL){*S = 0; S++;}


bool ParseURL(PCHAR URL, PURL Rec, bool FullPars)
{
	if (URL == NULL || Rec == NULL)
		return false;

	PCHAR Buf;

	// Определяем протокол
	Rec->Protocol = STR::GetLeftStr(URL, "://");

	// Создаём временный буфер
	if (Rec->Protocol != NULL)
	{
		Buf = STR::GetRightStr(URL, "://");
		if (Buf == NULL)
			return false;
    }
	else
		Buf = STR::New(URL);

	// Определяем указатели на вадные блоки
	PCHAR PathPtr = STR::Scan(Buf, '/');
	IncStrEx(PathPtr);

	// Строка параметров
	PCHAR ArgsPtr = NULL;
	PCHAR DocPtr = NULL;
	if (FullPars)
	{
		ArgsPtr = STR::Scan(PathPtr, '?');
		IncStrEx(ArgsPtr);

		// Определяем документ
		DocPtr = STR::ScanEnd(PathPtr, '/'); // Ищем последний слеш
		if (DocPtr == NULL)
		{
			// Путь является документом
			DocPtr = PathPtr;
            PathPtr = NULL;
		}
		else
        	IncStrEx(DocPtr);
	}

	// Строка хоста и порта
	PCHAR HostPtr = Buf;
	PCHAR PortPtr = STR::Scan(HostPtr, ':');
	IncStrEx(PortPtr);

	// Копируем строки
	Rec->Host      = STR::New(HostPtr);
	Rec->Path      = STR::New(PathPtr);
	Rec->Document  = STR::New(DocPtr);
	Rec->Port      = StrToInt(PortPtr);
	Rec->Arguments = STR::New(ArgsPtr);


	STR::Free(Buf);
	return true;
}

void ClearURL(PURL URL)
{
	if (URL == NULL)
		return;

	STR::Free2(URL->Protocol);
	STR::Free2(URL->Host);
	STR::Free2(URL->Path);
	STR::Free2(URL->Document);
	STR::Free2(URL->Arguments);
	STR::Free2(URL->UserName);
	STR::Free2(URL->Password);
	URL->Port = 0;
}

void AddURLParam(PStrings S, PCHAR Name, PCHAR Value, DWORD ValueSize)
{
	if (S == NULL || Name == NULL)
		return;

	PCHAR NewValue = URLEncode(Value, ValueSize);
	Strings::AddValue(S, Name, NewValue);
	STR::Free(NewValue);
}

//----------------------------------------------------------------------------
//  Функции для загрузки страниц
//----------------------------------------------------------------------------

#define HTONS(x) (((x) << 8) | ((x) >> 8))

SOCKET ConnectToHost(PCHAR Host, int Port)
{
	// Подключаемся к хосту

	// Получаем  адрес по имени хоста
	LPHOSTENT lpHost = (LPHOSTENT)pgethostbyname((const char*)Host);

	if ( lpHost == NULL )
		return SOCKET_ERROR;

	// Открываем хост
	SOCKET Socket = (SOCKET)psocket( AF_INET, SOCK_STREAM, 0 );

	if( Socket == SOCKET_ERROR )
		return Socket;

	struct sockaddr_in SockAddr;

	SockAddr.sin_family		 = AF_INET;
	SockAddr.sin_addr.s_addr = **(unsigned long**)lpHost->h_addr_list;
	SockAddr.sin_port		 = HTONS((unsigned short)Port );

	// подключаемся к сокету
	if ( (int)pconnect( Socket, (const struct sockaddr*)&SockAddr, sizeof( SockAddr ) ) == SOCKET_ERROR )
	{
		pclosesocket( Socket );
		return SOCKET_ERROR;
	}
	return Socket;
}
//----------------------------------------------------------------------------

bool ReceiveData(SOCKET Sock, PCHAR &Header, PCHAR *Buf, DWORD &Len)
{
    // Прочитать данные из сокета
	PMemBlockList HeaderBuf = MEMBLOCK::CreateList();

	if (HeaderBuf == NULL)
		return false;

	DWORD DataSize = 4096;
	LPBYTE Data = (LPBYTE)HEAP::Alloc(DataSize);
	int Size = 9;

	bool Completed = false;
    int DelPos;
	// Получаем заголовок ответа
	LPBYTE PartBuf = NULL;
	int PartSize = 0;

 	while (!Completed)
	{
		//
		Size = (int)precv(Sock, Data, DataSize, 0);
		if (Size == 0)
			break;

		// Определяем позицию разделителя
		DelPos = STR::Pos((PCHAR)Data, LineBreak2);
		if (DelPos >= 0)
		{
		   // Разделитель заголовка найден
		   Completed = true;
		   PartBuf = Data;
		   DWORD L = StrCalcLength(LineBreak2);
		   PartBuf = (LPBYTE)((DWORD)PartBuf+ DelPos + L);
		   PartSize = Size - DelPos - L;

		   Size = DelPos;
		}

		MEMBLOCK::AddBlock(HeaderBuf, Data, Size);
	}

	Header = MEMBLOCK::BuildAsStr(HeaderBuf, &Len);

	MEMBLOCK::FreeList(HeaderBuf);

	if (Buf == NULL)
	{
		HEAP::Free(Data);
		return true;
    }


	// Обрабатываем заголовки

    PChunks Chunks = Chunks::Initialize(Header);

    //----------------------------------------

	PMemBlockList RecBuf = MEMBLOCK::CreateList();

	if (RecBuf == NULL)
		return false;

	// Записываем остаток кадра

	if (PartSize > 0)
		MEMBLOCK::AddBlock(RecBuf, PartBuf, PartSize);

	// Получаем документ
	do
	{
		Size = (int)precv(Sock, Data, DataSize, 0);
		if (Size == 0)
			break;

		MEMBLOCK::AddBlock(RecBuf, Data, Size);
	}
	while (1);

	*Buf = MEMBLOCK::BuildAsStr(RecBuf, &Len);
	MEMBLOCK::FreeList(RecBuf);
	HEAP::Free(Data);

    bool Result = true;

    // проверяем кодировку передачи
	if (Chunks != NULL)
	{
		Chunks::HandleDataBlock(Chunks, (LPBYTE)*Buf, Len);
        STR::UpdateLength(*Buf, Len);
		Result = Chunks->Completed;
		Chunks::Free(Chunks);
    }

	return Result;
}


void HTTPSendPostData(PHTTPRequest Request, SOCKET Socket)
{
	// Отправить пост данные в сокет
	if (Request->PostData == NULL)
		return;

	if (Request->PostDataType == pdtUrlEncoded)
	{
		// Отправляем URL Encoded данные
		psend(Socket, Request->PostData, Request->ContentLength, 0);
        return;
	}

	// Отправляем MultiPartData
	PMultiPartData D = (PMultiPartData)Request->PostData;
	DWORD BufSize = 4096;
	DWORD Readed;
	LPBYTE Buffer = (LPBYTE)MemAlloc(BufSize);
	if (Buffer == NULL)
		return;

	do
	{
		Readed = MultiPartData::Read(D, Buffer, BufSize);
		if (Readed != 0)
        	psend(Socket, Buffer, Readed, 0);
	}
	while (Readed != 0);

	MemFree(Buffer);
}

bool HTTP::ExecuteMethod(PHTTPRequest Request, HTTP::PResponseData Response)
{
	// Функция выполняет HTTP метод указанный в настройках запроса
	if (Request == NULL || Request->Host == NULL)
		return false;

	// Очищаем данные ответа
	if (Response != NULL)
	{
		if (Response->Buffer != NULL) *Response->Buffer = NULL;
		if (Response->Size != NULL) *Response->Size = 0;
		if (Response->Headers != NULL) *Response->Headers = NULL;
	}


	
	// Ини               иализируем библиотеку
	WSADATA wsa;
	if ( (int)pWSAStartup(MAKEWORD( 2, 2 ), &wsa ) != 0 )
		return false;


	SetDefaultPort(Request);

	// Подключаемся к хосту
	SOCKET Sock = ConnectToHost(Request->Host, Request->Port);
	if (Sock == SOCKET_ERROR){
#ifdef _DEBUG
		pOutputDebugStringA("*");
		pOutputDebugStringA(Request->Host);
		pOutputDebugStringA("*\nConnect fail");
#endif
		return false;
	}
	// Отправлям данные
	PCHAR SendBuf = HTTPRequest::Build(Request);
	if (SendBuf == NULL)
	{
		pclosesocket(Sock);
		return false;
	}

	DWORD BufSize = STR::Length(SendBuf);

	if ((int)psend(Sock, SendBuf, BufSize, 0) != SOCKET_ERROR)
	{
        // Отправляем пост данные
		if (Request->Method == hmPOST)
		{
			// Добавляем POST данные
			HTTPSendPostData(Request, Sock);
		}

		// Данные отправлены, читаем ответ
		if (Response != NULL && (Response->Buffer != NULL || Response->Response!= NULL))
		{
			DWORD Size = 0;
			PCHAR Headers = NULL;
			if (Response->Response != NULL)
				HTTPResponse::Clear(Response->Response);

			ReceiveData(Sock, Headers, Response->Buffer, Size);

			if (Response->Response != NULL)
				HTTPResponse::Parse(Headers, Response->Response);

			if (Response->Headers != NULL)
				*Response->Headers = Headers;
			else
				STR::Free(Headers);

			if (Response->Size != NULL)
				*Response->Size = Size;
}
    }

	// Закрываем хост
	pclosesocket(Sock);

	return true;

}

bool HTTP::Get(PCHAR URL, PCHAR *Buf,DWORD *Size)
{
	// Функция считаевает файл по адресу URL в буФер Buf
	if (URL == NULL)
		return false;

	PHTTPRequest R = HTTPCreateRequest(URL);

	HTTP::TResponseData Response;
	ClearStruct(Response);
	Response.Buffer = Buf;
	Response.Size = Size;

	bool Res = HTTP::ExecuteMethod(R, &Response);


	HTTPFreeRequest(R);
	
	return Res;
}

bool HTTP::Get(PCHAR URL, PCHAR *Buf, DWORD *Size, PHTTPResponse ResponseRec)
{
	// Функция считаевает файл по адресу URL в буФер Buf
	if (URL == NULL)
		return false;

	PHTTPRequest R = HTTPCreateRequest(URL);

	HTTP::TResponseData Response;
	ClearStruct(Response);
	
	Response.Buffer = Buf;
	Response.Size = Size;
	Response.Response = ResponseRec;

	bool Res = HTTP::ExecuteMethod(R, &Response);

	HTTPFreeRequest(R);
	return Res;
}


bool HTTP::Post(PCHAR URL, PStrings Fields, PCHAR *Buf)
{
	// Отправить пост запрос на сервер
	if (URL == NULL || Fields == NULL)
		return false;

	PHTTPRequest R = HTTPCreateRequest(URL);
	R->Method = hmPOST;
	R->PostData = Strings::GetText(Fields, URLValueDelimeter);

	TResponseData Response;
	ClearStruct(Response);
	Response.Buffer = Buf;

    bool Res = HTTP::ExecuteMethod(R, &Response);
	HTTPFreeRequest(R);
	return Res;
}

bool HTTP::Post(PCHAR URL, PMultiPartData Fields, PCHAR *Buf)
{
	// Отправить пост запрос на сервер
	if (URL == NULL || Fields == NULL)
		return false;

	PHTTPRequest R = HTTPCreateRequest(URL);
	R->Method = hmPOST;
	R->PostData = Fields;
	R->PostDataType = pdtMultipartFormData;

	TResponseData Response;
	ClearStruct(Response);
	Response.Buffer = Buf;

    bool Res = HTTP::ExecuteMethod(R, &Response);
	HTTPFreeRequest(R);
	return Res;
}


//----------------------------------------------------------------------------

PCHAR GetEndLine(PCHAR Str)
{
	// Функция возвращает Указатель на последний символ строки
	if (Str == NULL)
		return NULL;

	PCHAR C = Str;

	while (*C != 0 && *C != 10 && *C != 13) C++;
    return C;
}

PCHAR ScanLN(PCHAR S, char C, bool SetAfter = false)
{
	// Функция ищет символ до конца строки
	if (S == NULL)
		return NULL;
	PCHAR T = S;
	while ((*T != 0) && (*T != 10) && (*T != 13) && (*T != C)) T++;
	if (*T == C)
	{
		if (SetAfter)
            T++;
		return T;
	}
	else
		return NULL;
}

void IgnoreSpaces(PCHAR &S)
{
    // Игнорировать пробелы
	if (S == NULL)
		return;
	while (*S != 0 && *S == ' ') S++;
}

PCHAR GetStrFromPtr(PCHAR Start, PCHAR End)
{
	// Получить строку между указателями
	if (Start == NULL || End == NULL)
		return NULL;
	int Len = End - Start;
	if (Len <= 0)
		return NULL;
	return STR::New(Start, Len);
}

bool IsKnownHTTPMethod(PCHAR Method)
{

	int Index = StrIndexOf(Method, true, 11, HTTPMethodGET,
											HTTPMethodPOST,
											HTTPMethodHEAD,
											HTTPMethodPUT,
											HTTPMethodDELETE,
											HTTPMethodLINK,
											HTTPMethodUNLINK,
											HTTPMethodCONNECT,
											HTTPMethodOPTIONS,
											HTTPMethodPATCH,
                                            HTTPMethodTRACE);
	return Index >= 0;
}


#define ClearStrVar(S) if (S != NULL) *S = NULL


// Методы анализа HTTP заголовков
bool ParseRequestFirstLine(PCHAR Line, PCHAR *Method, PCHAR *Path, PCHAR *ProtVersion)
{
	// Разобрать превую строку запроса
	ClearStrVar(Method);
	ClearStrVar(Path);
	ClearStrVar(ProtVersion);

	if (Line == NULL)
		return false;

	// Определяем указатели на путь и протокол
	PCHAR MethodPtr = ScanLN(Line, ' ');
	PCHAR PathPtr = ScanLN(MethodPtr, '/', true);
	PCHAR ProtPtr = ScanLN(PathPtr, ' ');
	PCHAR EndL = GetEndLine(ProtPtr);

	if (MethodPtr == NULL ||  PathPtr == NULL || ProtPtr == NULL)
		return false;


	PCHAR MethodName = GetStrFromPtr(Line, MethodPtr);
	if (!IsKnownHTTPMethod(MethodName))
	{
		// Неизвестный метод запроса
		STR::Free(MethodName);
		return false;
    }

	// Получаем метод
	if (Method != NULL)
		*Method = MethodName;
	else
		STR::Free(MethodName);

	// Получаем путь
	if (Path != NULL)
		*Path = GetStrFromPtr(PathPtr, ProtPtr);

	// Получаем протокол
	if (ProtVersion != NULL)
	{
		IgnoreSpaces(ProtPtr);
		*ProtVersion = GetStrFromPtr(ProtPtr, EndL);
    }

	// Возвращаем итину если получены указатели на 3 блока
	return true;
}

THTTPMethod GetMethodFromStr(PCHAR Method)
{
	// Функция возвращает тип метода по его названию
	switch (StrIndexOf(Method, false, 3, HTTPMethodGET, HTTPMethodPOST, HTTPMethodHEAD)) 
	{
		case 0:
			return hmGET;
		case 1:
			return hmPOST;
		case 2:
			return hmHEAD;	
        
    default:
    	return hmUnknown;
	} 
}

PCHAR HTTPParser::GetHeaderValue(PCHAR Buf, PCHAR Name)
{
	// Функция возвращает значение заголовка
	if (Buf == NULL || Name == NULL)
		return NULL;
		
	DWORD Len = StrCalcLength(Name);
	PCHAR Line = Buf; // Указатель на начало строки
	PCHAR EndLN;      // Указатель на конец строки
	PCHAR ValPTR;     // Указатель на разделитель ':'
	
	DWORD LBCount; // Количество символов разделения строк
	
	// Построчно перебираем буфер
	while (*Line != 0)
	{
  		IgnoreSpaces(Line);
		EndLN = GetEndLine(Line);
		// Ишем позицию разделителя
		
		ValPTR = ScanLN(Line, ':', true);
		if (ValPTR != NULL && StrSame(Line, Name, false, Len)) 
		{
			// Нашли совпадение имени
			IgnoreSpaces(ValPTR);
			return GetStrFromPtr(ValPTR, EndLN);
		}

		// Переходим на следующёю позицию
		LBCount = 1;
		Line = EndLN;
		while (*Line != 0 && (*Line == 10 || *Line == 13)) 
		{
			Line++;
			LBCount++;
		}

		// Если встретили 4 и больше разделителя(конец заголовка) то
		// прерываем цикл
		if (LBCount >= 4) break;
			
	}
	return NULL;			
}

PCHAR GetURLEncodedPostData(PCHAR Buf)
{
	// Получить URL кодированные пост данные.

	// Определяем позицию двойного разделителя строк и копируем данные
	// до следующей строки

	int Pos = STR::Pos(Buf, LineBreak2);

	if (Pos < 0)
	   return NULL;

	Pos+=StrCalcLength(LineBreak2);

	PCHAR Start = Buf + Pos;
	PCHAR End = GetEndLine(Start);

	return GetStrFromPtr(Start, End);;
}

//***************************************************************************
//
//   Методы для работы с пост данными формата multy part form data
//
//***************************************************************************

// Методы чтения данных MultiPartData
namespace MPDReader
{

	const static PCHAR BoundaryDelimeter = "--";
	const static PCHAR ContentDispositionName = "Content-Disposition: form-data; name=\"";
	const static PCHAR FileNameHeader = "; filename=\"";
	const static PCHAR ContentTypeHeader = "Content-Type: ";
	const static PCHAR DefaultContentType = "application/octet-stream";
	const static PCHAR TransferEncodingHeader ="Content-Transfer-Encoding: binary";


	void MakeItemHeader(PMultiPartData Data, PMultiPartItem  Item)
	{
		// Собрать заголовок элемента

		PCHAR Prefix = NULL;
		// Перед первым элементом вставляем Boundary
		if (List::GetItem(Data->Items, 0) == Item)
			Prefix = STR::New(3, BoundaryDelimeter, Data->Boundary, LineBreak);

		if (Item->FileName == NULL)
		{
			// Обычный элемент
			Item->Header = STR::New(5, Prefix, ContentDispositionName, Item->Name, "\"", LineBreak2);
            STR::Free(Prefix);
			return;
		}

		PCHAR ShortName = File::ExtractFileName(Item->FileName);
		PCHAR CT = Item->ContentType;
		if (CT == NULL)
			CT = DefaultContentType;

		// Собираем заголовок элемента файла
		Item->Header = STR::New(13,
			Prefix,
			ContentDispositionName, Item->Name, "\"",
			FileNameHeader, ShortName,  "\"", LineBreak,
			ContentTypeHeader, CT, LineBreak,
			TransferEncodingHeader, LineBreak2);


		STR::Free(ShortName);
		STR::Free(Prefix);
    }

	// Копируем данные
	void CopyData(LPVOID Data, DWORD DataSize, LPBYTE &Buffer, DWORD &BufSize)
	{
		m_memcpy(Buffer, Data, DataSize);
		Buffer += DataSize;
		BufSize -= DataSize;
    }

	//-----------------------------------------------------------------------

	DWORD ReadItem(PMultiPartData Data, PMultiPartItem  Item, LPBYTE Buffer, DWORD Size, bool IsLastItem)
	{
		// Читать данные элемента
		if (Item == NULL)
			return 0;

		if (STR::IsEmpty(Item->Header))
			MakeItemHeader(Data, Item);

		DWORD Result = 0;

		// Раситываем размер данных элемента
		if (Buffer == NULL)
		{
			Result = STR::Length(Item->Header); // Размер заголовка
			Result += 2; // Пустая строка после данных
			Result += Item->Size; // Данные
			Result += 2 + STR::Length(Data->Boundary); // --Boundary
			if (IsLastItem)
				Result += 2; // Символы -- после Boundary
			Result += 2; // Перевод строки после данных
			return Result;
		}

		// Читаем данные элемента

        DWORD Max;

		if (Item->ReadState == mprsUnknown)
			Item->ReadState = mprsHeader;

		// Читаем заголовок
		if (Item->ReadState == mprsHeader)
		{
			Max = STR::Length(Item->Header) - Item->ReadedSize;
			if (Max > Size)
				Max = Size;
			CopyData(Item->Header +  Item->ReadedSize, Max, Buffer, Size);
			Result += Max;
			Item->ReadedSize += Max;
			if (Item->ReadedSize == STR::Length(Item->Header))
			{
                Item->ReadedSize = 0;
				Item->ReadState = mprsData;
			}
			else
				return Result;
		}

		// Читаем данные
		if (Item->ReadState == mprsData)
		{
			bool IsFile = Item->FileHandle != NULL && Item->Data == NULL;


			Max = Item->Size - Item->ReadedSize;
			if (Max > Size)
				Max = Size;

			if (!IsFile)
				CopyData((LPBYTE)Item->Data + Item->ReadedSize, Max, Buffer, Size);
			else
			{
				// Читаем данные из файла
				pReadFile(Item->FileHandle, Buffer, Max, &Max, NULL);
				Buffer += Max;
				Size -= Max;
            }

			Item->ReadedSize += Max;
			Result += Max;
			if (Item->ReadedSize == Item->Size)
			{
				Item->ReadState = mprsBoundary;
				Item->ReadedSize = 0;
            }
			else
				return Result;
        }

		// Читаем Boundary
		if (Item->ReadState == mprsBoundary)
		{
			// Собираем идентификатор границы

			if (Item->Boundary == NULL)
			{
				PCHAR BNDEnd = NULL;

				if (IsLastItem)
					BNDEnd = BoundaryDelimeter;
				Item->Boundary = STR::New(5, LineBreak, BoundaryDelimeter, Data->Boundary, BNDEnd, LineBreak);
            }

			// Читаем данные границы
			Max = STR::Length(Item->Boundary) - Item->ReadedSize;
			if (Max > Size)
				Max = Size;

			CopyData(Item->Boundary + Item->ReadedSize, Max, Buffer, Size);


			Result += Max;
			Item->ReadedSize += Max;
			if (Item->ReadedSize == STR::Length(Item->Boundary))
			{
				Item->ReadedSize = 0;
				STR::Free2(Item->Boundary);
				Item->ReadState = mprsCompleted;
				if (Item->FileHandle != NULL)
				{
					pCloseHandle(Item->FileHandle);
					Item->FileHandle = NULL;
				}
            }
        }

        return Result;
    }

	//-----------------------------------------------------------------------
	DWORD TotalSize(PMultiPartData Data)
	{
		// Функция возвращает общий объём данных
		if (Data == NULL)
			return 0;

		DWORD Size = 0;
		DWORD Count = List::Count(Data->Items);
		// Определяем размер блоков
		for (DWORD i = 0; i < Count; i++)
        {
			PMultiPartItem  Item = (PMultiPartItem)List::GetItem(Data->Items, i);
            Size += ReadItem(Data, Item, NULL, 0, i == Count - 1);
		}

		return Size;

    }
}


void FreeMultipartItem(LPVOID Item)
{
	PMultiPartItem M = (PMultiPartItem)Item;

	STR::Free(M->Name);
	STR::Free(M->FileName);
	MemFree(M->Data);
	MemFree(M->FileName);
	MemFree(M->ContentType);
	STR::Free(M->Boundary);
	if (M->FileHandle != NULL)
		pCloseHandle(M->FileHandle);

	FreeStruct(M);
}

PMultiPartData MultiPartData::Create()
{
	// Создать набор данных
	const static PCHAR Boundary = "---------";
	const BYTE MaxBnd = 16;
	PMultiPartData Data = CreateStruct(TMultiPartData);
	if (Data == NULL)
		return NULL;

	Data->Items = List::Create();
	List::SetFreeItemMehod(Data->Items, FreeMultipartItem);

	PCHAR S  = Random::RandomString(MaxBnd, 'A', 'Z'); 
	Data->Boundary = STR::New(2, Boundary, S);
	STR::Free(S);

	return Data;
}

void MultiPartData::Free(PMultiPartData Data)
{
	// Уничтожить набор данных
	if (Data == NULL)
		return;

	List::Free(Data->Items);
	STR::Free(Data->Boundary);
	FreeStruct(Data);
}


// Добавить бинарные данные
PMultiPartItem MultiPartData::AddBlobField(PMultiPartData Data, PCHAR Name, LPBYTE Value, DWORD ValueSize)
{
	if (Data == NULL || STR::IsEmpty(Name))
		return NULL;

	PMultiPartItem Item = CreateStruct(TMultiPartItem);
	if (Item == NULL)
		return  NULL;

	Item->Name = STR::New(Name);
	Item->Size = ValueSize;
	if (Item->Size != 0 && Value != NULL)
	{
		Item->Data = MemAlloc(Item->Size);
		m_memcpy(Item->Data, Value, Item->Size);
    }

    List::Add(Data->Items, Item);
	return Item;
}

PMultiPartItem MultiPartData::AddStringField(PMultiPartData Data, PCHAR Name, PCHAR Value)
{
    // Добавить строковое значение в список
	return AddBlobField(Data, Name, (LPBYTE)Value, StrCalcLength(Value));
}

// Добавить файл
PMultiPartItem  MultiPartData::AddFileField(PMultiPartData Data, PCHAR Name,
										PCHAR FileName, PCHAR ContentType)
{
	// Добавить файловый элемент
	if (Data == NULL || STR::IsEmpty(Name) || STR::IsEmpty(FileName))
		return NULL;

	// Получаем размер файла
	HANDLE H = (HANDLE)pCreateFileA(FileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (H == INVALID_HANDLE_VALUE)
		return NULL;

	DWORD HS = 0;
    DWORD Size = (DWORD)pGetFileSize(H, &HS);


	// Добавляем элемент
	PMultiPartItem Item = AddBlobField(Data, Name, NULL, Size);
	if (Item == NULL)
	{
        pCloseHandle(H);
		return NULL;
    }

	Item->FileName = STR::New(FileName);
	Item->FileHandle = H;
	Item->ContentType = STR::New(ContentType);
    return Item;
}


// Добавить двоичные данные как файл
PMultiPartItem MultiPartData::AddBlobAsFile(PMultiPartData Data, PCHAR Name, PCHAR FileName,
							 PCHAR ContentType, LPBYTE Value, DWORD ValueSize)
{
	if (Value == NULL || FileName == NULL)
		return NULL;

	PMultiPartItem Item = AddBlobField(Data, Name, Value, ValueSize);
	if (Item != NULL)
	{
		Item->FileName = STR::New(FileName);
		Item->ContentType = STR::New(ContentType);
    }

	return Item;
}




DWORD MultiPartData::Read(PMultiPartData Data, LPBYTE Buffer, DWORD BufferSize)
{
	// Функция читаем следующий блок данных.
	// Результат - количество прочитанных байт
	// Примечание - если на вход передать нулевой буфер, то
	// функция вернёт общий размер пост данных
	if (Buffer == NULL || BufferSize == 0)
		return MPDReader::TotalSize(Data);


	DWORD Result = 0;
	DWORD Count = List::Count(Data->Items);
	while(Data->ReadIndex < Count)
    {
		PMultiPartItem Item = (PMultiPartItem)List::GetItem(Data->Items, Data->ReadIndex);
		if (Item->ReadState == mprsCompleted)
		{
			Data->ReadIndex++;
			continue;
		}

		// Читаем элемент
		bool LastItem = Data->ReadIndex == Count - 1;
		DWORD Readed = MPDReader::ReadItem(Data, Item, Buffer, BufferSize, LastItem);
		if (Readed == 0) break;

		// Меняем размер буфера и указателя на буфер
		Result += Readed;
		BufferSize -= Readed;
		Buffer += Readed;
		if (BufferSize == 0)
            break;
	}

	return Result;
}


LPBYTE MultiPartData::BuildToBuf(PMultiPartData Data, DWORD &ResultSize)
{
	// Записать данные в блок памяти

	// Определяем размер памяти
	ResultSize = Read(Data, NULL, 0);
	if (ResultSize == 0)
		return NULL;

	// Читаем данные
	LPBYTE Buf = (LPBYTE)MemAlloc(ResultSize + 1);
	if (Buf == NULL)
	{
        ResultSize = 0;
		return NULL;
	}
	ResultSize = Read(Data, Buf, ResultSize);
	*(Buf + ResultSize) = 0;
	return Buf;

}

//---------------------------------------------------------------------------
PHTTPResponse HTTPResponse::Create()
{
	// Создать структуру отыета
	return CreateStruct(THTTPResponse);
}
//---------------------------------------------------------------------------

void HTTPResponse::Clear(PHTTPResponse Response)
{
	// Функция очищает структуру HTTP ответа
	STR::Free2(Response->Protocol);
	STR::Free2(Response->ContentType);
	STR::Free2(Response->ResponseLine);
	STR::Free2(Response->Connection);
	STR::Free2(Response->Location);
	STR::Free2(Response->AcceptRanges);
    ClearStruct(*Response);
}
//---------------------------------------------------------------------------

void ParseContentRange(PHTTPResponse Response, PCHAR Value)
{
	//bytes 100-300/69652396
	if (!StrSame(Value, "bytes", false, 5))
		return;
	PCHAR Start = ScanLN(Value, ' ');
	IgnoreSpaces(Start);
	PCHAR End = ScanLN(Start, '-');
	if (End == NULL)
		return;
	*End = 0;
	Response->StartRange = StrToInt(Start);
	End++;
	Start = End;
	End = ScanLN(Start, '/');
	if (End == NULL)
		return;
	*End = 0;
	Response->EndRange = StrToInt(Start);
	End++;
	Start = End;
    Response->FullSize = StrToInt(Start);
}

void AddResponseValue(PHTTPResponse Response, PCHAR Name, PCHAR Value)
{
	switch (StrIndexOf(Name, false, 6, ParamContentType, ParamContentLength,
		ParamAcceptRanges, ParamConnection, ParamContentRange,
		ParamLocation))
	{
		case 0: Response->ContentType = STR::New(Value); break;
		case 1: Response->ContentLength = StrToInt(Value); break;
		case 2: Response->AcceptRanges = STR::New(Value); break;
		case 3: Response->Connection = STR::New(Value); break;
		case 4: ParseContentRange(Response, Value); break;
		case 5: Response->Location = STR::New(Value); break;
    default:
        ;
	}
}

bool HTTPResponse::Parse(PCHAR Buf, PHTTPResponse Response)
{
	// Парсим ответ HTTP сервера
	if (Buf == NULL || Response == NULL)
		return false;
	bool Result  = false;
	HTTPResponse::Clear(Response);

	PStrings S = Strings::Create();

	Strings::SetText(S, Buf);
	DWORD Count = Strings::Count(S);

	DWORD i;
	PCHAR Tmp;
	PCHAR Name;
	PCHAR Value;
    PCHAR Ptr;
	if (Count > 0)
	{
		// Разбираем строку ответа
		if (HTTPParser::ParseResponseLine(Strings::GetItem(S, 0, false), Response->Protocol, Response->Code, Response->ResponseLine))
		{
			Result = true;
			for (i = 1; i < Count; i++)
			{
				Tmp = Strings::GetItem(S, i, false);
				Name = Tmp;
				Ptr = STR::Scan(Tmp, ':');
				if (Ptr == NULL) continue;
				*Ptr = 0;
				Ptr++;
				IgnoreSpaces(Ptr);
				Value = Ptr;
                AddResponseValue(Response, Name, Value);
			}
        }
    }

	Strings::Free(S);
	return Result;
}
//---------------------------------------------------------------------------

void HTTPResponse::Free(PHTTPResponse Response)
{
	// Создать структуру отыета
	if (Response == NULL)
		return;
	HTTPResponse::Clear(Response);
	FreeStruct(Response);
}

//*****************************************************************************
//  Chunks - Методы для работы с передачей данных частями
//*****************************************************************************


PChunks Chunks::Initialize(PCHAR HTTPResponse)
{
	// Функция проверяет заголовок ответа и в случае если
	// если значение заголовка Transfer-Encoding = chunked
	// создаёт структуру для работы с загружаемыми данными
	if (STR::IsEmpty(HTTPResponse))
		return NULL;
	PCHAR Value = HTTPParser::GetHeaderValue(HTTPResponse, ParamTransferEncoding);
	if (Value == NULL || !StrSame(Value, ValueChunked, false))
		return NULL;

    return CreateStruct(TChunks);
}


LPBYTE Chunks::GetChunkSize(LPBYTE Buf, DWORD BufSize, DWORD &Size)
{
	// Функция возвращает размер блока

	const static PCHAR EndChunk = "\r\n0\r\n\r\n";
	const static DWORD EndChunkSize = 7;

	Size = 0;

	// проверяем на окончание данных
	if (StrSame((PCHAR)Buf, EndChunk, true, EndChunkSize))
        return Buf + EndChunkSize;

	// Полуяаем размер
	if (*Buf == 10 || *Buf == 13)
    	Buf = (LPBYTE)STR::GotoNextLine((PCHAR)Buf, BufSize);

	PCHAR LN = STR::GetLine((PCHAR)Buf, BufSize);

	if (LN == NULL) return NULL;
    Size = STR::HexToDWORD(LN);
	STR::Free(LN);

	return (LPBYTE)STR::GotoNextLine((PCHAR)Buf, BufSize);
}

void Chunks::HandleDataBlock(PChunks Chunks, LPBYTE Data, DWORD &Size)
{
	// Обработать блок данных
	if (Chunks == NULL || Data == NULL || Size == 0)
		return;

	DWORD Sz = Size;
	LPBYTE Buf = Data;
	while (Sz > 0 && !Chunks->Completed)
	{
		// Получаем размер блока
		if (Chunks->Size == 0)
		{
            // Получаем размер части
			LPBYTE SzEnd = GetChunkSize(Buf, Sz, Chunks->Size);
			if (SzEnd != NULL)
			{
				DWORD HeadSize = SzEnd - Buf;
				// Удаляем информацию о размере из буфера
                STR::Delete((PCHAR)Buf, 0, HeadSize, Sz);

				Sz -= HeadSize;
				Size -= HeadSize;
            }

			if (SzEnd == NULL || Chunks->Size == 0)
			{
				Chunks->Completed = true;
				break;
            }
		}

		// Пропускаем блок
		DWORD NeedRead = Chunks->Size - Chunks->Readed;
		if ( NeedRead <= Sz)
		{
			Chunks->Readed += NeedRead;
			Sz -= NeedRead;
			Buf += NeedRead;
			// Блок полностью прочитан
			if (Chunks->Readed == Chunks->Size)
			{
				Chunks->Readed = 0;
                Chunks->Size = 0;
            }
		}
		else
		{
			// блок данных содержит не весь передаваймый кусок
			Chunks->Readed += Sz;
			break;
        }

    }

}



void Chunks::Free(PChunks Chunks)
{
	// Функция уничтожает структуру
	if (Chunks != NULL)
    	FreeStruct(Chunks);
}


//---------------------------------------------------------------------------

//*****************************************************************************
//  HTTPParser - Парсер HTTP данных
//*****************************************************************************
bool HTTPParser::ParseResponseLine(PCHAR Buf, PCHAR &Protocol, DWORD &Code, PCHAR &StatusLine)
{
	// парсим строку ответа HTTP сервера
	// Например HTTP/1.1 200 Ok
	Protocol = NULL;
	Code = 0;
	StatusLine = NULL;

	if (Buf == NULL)
		return false;
	if (!StrSame(Buf, "HTTP/1.", false, 7))
		return false;

	PCHAR Start = Buf;
	PCHAR End = Start;

	// Определяем протокол
	End = ScanLN(Buf, ' ');
	if (End == NULL)
		return false;
	Protocol = STR::New(Start, End - Start);

	// Определяем код
	Start = End;
	IgnoreSpaces(Start);
	End = ScanLN(Start, ' ');
	PCHAR Tmp = STR::New(Start, End - Start);
    Code = (DWORD)StrToInt(Tmp);
	STR::Free(Tmp);

	// Определяем строку ответа
	Start = End;
	IgnoreSpaces(Start);
	End = STR::End(Start);
	StatusLine = STR::New(Start, End - Start);

	return Protocol != NULL && Code != 0;

}
//---------------------------------------------------------------------------

//*****************************************************************************
// Методы для работы с HTTP данными
//*****************************************************************************
PCHAR HTTPUtils::DeleteHeaderValue(PCHAR Buf, int &Size, PCHAR Header)
{
	// Функция указанный HTTP заголовок
	if (STR::IsEmpty(Buf) || STR::IsEmpty(Header)) return Buf;
	if (Size == 0)
		Size = StrCalcLength(Buf);

	int Pos = STR::Pos(Buf, Header);
	if (Pos < 0) return Buf;
	PCHAR Start = Buf + Pos;
	while (*Start != 0 && *Start != ':') Start++;
	Start++;
		
	PCHAR End = Start;

	// Переходим на следующую строку
	while (*End != 0 && *End != 10 && *End != 13) End++;

	DWORD Delta = End - Start;
    DWORD CopySize = Size - (End - Buf);
    m_memcpy(Start, End, CopySize);

	Size -= Delta;
	*(Buf + Size) = 0;
    return Buf;

}



