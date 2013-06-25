//---------------------------------------------------------------------------

#pragma hdrstop

#include <winsock2.h>
#include "Memory.h"
#include "BotSocket.h"


#include "BotDebug.h"
namespace SOCKETDBGTEMPLATES
{
	#include "DbgTemplates.h"
}

#define SOCKDBG SOCKETDBGTEMPLATES::DBGOutMessage<>


//---------------------------------------------------------------------------



//****************************************************************************
//  								TBotSocket
//****************************************************************************

TBotSocket::~TBotSocket()
{
}


//------------------------------------------------------
//  Connect - Функция сокет и подключается к указанному
//			  серверу
//  HostName - Имя сервера
//  Port     - Порт к которому будем подключаться
//------------------------------------------------------
bool TBotSocket::Connect(const char *HostName, WORD Port)
{
	return DoConnect(HostName, Port, 0);
}

//------------------------------------------------------
//  Connect - Функция сокет и подключается к указанному
//			  серверу
//  HostName - Имя сервера
//  Port     - Порт к которому будем подключаться
//  Timeout  - Интервал времени в течении которого будет
//             производиться попытка подключения
//------------------------------------------------------
bool TBotSocket::Connect(const char *HostName, WORD Port, DWORD Timeout)
{
	return DoConnect(HostName, Port, Timeout);
}



//****************************************************************************
//  								TWinSocket
//****************************************************************************

TBotSocket* CreateSocket()
{
	return new TWinSocket();
}

bool InitWindowsSocketApi()
{
	// Инициализируем библиотеку
	WSADATA wsa;
	ClearStruct(wsa);
	DWORD Code = (DWORD)pWSAStartup(MAKEWORD( 2, 2 ), &wsa);
	return Code == 0;
}

TWinSocket::TWinSocket() : Socket(INVALID_SOCKET)
{
}

TWinSocket::~TWinSocket()
{
	// Закрываем все свои ресурсы в своём деструкторе.
	Close();
}

void TWinSocket::Close()
{
	// Если сокет не был создан - ничего не делаем.
	if (Socket == INVALID_SOCKET) return;

	pshutdown(Socket, SD_BOTH);
	pclosesocket(Socket);

	Socket = INVALID_SOCKET;
}

#define MAKEPORT(x) (((x) << 8) | ((x) >> 8))

bool TWinSocket::DoConnect(const char *HostName, WORD Port, DWORD Timeout)
{
	if (Timeout == 0) Timeout = 60 * 60;// 1 hour
	
	// Если сокет соединён - запрещаем повторное соединение
	if (Socket != INVALID_SOCKET) return false;

	// Инициализируем библиотеку
	if (!InitWindowsSocketApi()) return false;

	LPHOSTENT lpHost = (LPHOSTENT)pgethostbyname(HostName);

	if (!lpHost)
		return false;

	// Открываем хост
	Socket = (SOCKET)psocket( AF_INET, SOCK_STREAM, 0 );

	if(Socket == SOCKET_ERROR)
		return false;

	struct sockaddr_in SockAddr;

	SockAddr.sin_family		 = AF_INET;
	SockAddr.sin_addr.s_addr = **(unsigned long**)lpHost->h_addr_list;
	SockAddr.sin_port		 = MAKEPORT((unsigned short)Port );

	// подключаемся к сокету
	if ( (int)pconnect( Socket, (const struct sockaddr*)&SockAddr, sizeof( SockAddr ) ) == SOCKET_ERROR )
	{
		pclosesocket( Socket );
		Socket = INVALID_SOCKET;
	}

	return Socket != INVALID_SOCKET;

/*	do
	{
		// Инициализируем библиотеку
		if (!InitWindowsSocketApi()) break;

		// Получаем  адрес по имени хоста
		LPHOSTENT lpHost = (LPHOSTENT)pgethostbyname(HostName);

		// Не нашли имя
		if ( lpHost == NULL ) break;

		Socket = (SOCKET)psocket( AF_INET, SOCK_STREAM, IPPROTO_TCP);

		// Сокет не создался
		if( Socket == INVALID_SOCKET ) break;

		// Включаем неблокирующий режим
		u_long nonblocking_enabled = 1;
		int ioct_result = (int)pioctlsocket(Socket, FIONBIO, &nonblocking_enabled);

		// Не получилось включит неблокирующий режим
		if (ioct_result != NO_ERROR) break;

		struct sockaddr_in SockAddr;

		SockAddr.sin_family      = AF_INET;
		SockAddr.sin_addr.s_addr = **(unsigned long**)lpHost->h_addr_list;
		SockAddr.sin_port        = MAKEPORT((unsigned short)Port );

		// подключаемся к хосту
		int   connect_result = (int)pconnect( Socket, (const struct sockaddr*)&SockAddr, sizeof( SockAddr ) );
		DWORD last_error = (DWORD)pWSAGetLastError();

		// Ф-ция обязана завершатся ошибкой в неблокирующем режиме
		if (connect_result != SOCKET_ERROR) break;

		// Ошибка не связана с неблокирующим режимом
		if (last_error !=  WSAEWOULDBLOCK) break;

		fd_set writefds;
		fd_set readfds;
		fd_set excptfds;

		TIMEVAL tv;

		tv.tv_sec  = Timeout;
		tv.tv_usec = 0;

		FD_ZERO(&writefds);
		FD_ZERO(&readfds);
		FD_ZERO(&excptfds);

		FD_SET(Socket, &writefds);
		FD_SET(Socket, &readfds);
		FD_SET(Socket, &excptfds);

		int select_result = (int)pselect(0, &readfds, &writefds, &excptfds, &tv);

		// Ошибка при вызове select
		if (select_result == SOCKET_ERROR) break;

		// Ошибка при соединении.
		if (pWSAFDIsSet(Socket, &excptfds) != 0) break;

		// Ошибок не было, но и подключится не успел.
		if (pWSAFDIsSet(Socket, &writefds) == 0) break;

		// Тут получается что успел подключится.
		// Отключаем неблокирующий режим
		nonblocking_enabled = 0;
		ioct_result = (int)pioctlsocket(Socket, FIONBIO, &nonblocking_enabled);

		// Не получилось отключить неблокирующий режим
		if (ioct_result != NO_ERROR) break;

		return true;
	}
	while (0);

	Close();
	return false; */
}

int TWinSocket::Write(const void* Buf, DWORD BufSize)
{
	return (int)psend(Socket, (const char*)Buf, BufSize, 0);
}

int TWinSocket::Read(void* Buf, DWORD BufSize)
{
	return (int)precv(Socket, (char*)Buf, BufSize, 0);
}

//***************************************************************
//  TBkSocket - Класс для работы с сокетом комплекса Bootkit
//
//***************************************************************
TBotSocket* CreateBootkitSocket()
{
	return new TBkSocket();
}

bool TBkSocket::DoConnect(const char *HostName, WORD Port, DWORD Timeout)
{
	if (Timeout == 0) Timeout = 60 * 60;// 1 hour
	
	// Если сокет соединён - запрещаем повторное соединение
	if (Socket != INVALID_SOCKET) return false;

	Close();
	return false;
}

TBkSocket::TBkSocket()
{
	Socket = INVALID_SOCKET;
}

TBkSocket::~TBkSocket()
{
	Close();
}

void TBkSocket::Close()
{
	// Если сокет не был создан - ничего не делаем.
	if (Socket == INVALID_SOCKET) return;

	Socket = INVALID_SOCKET;
}

int TBkSocket::Write(const void* Buf, DWORD BufSize)
{
	return SOCKET_ERROR;
}

int TBkSocket::Read(void* Buf, DWORD BufSize)
{
	return SOCKET_ERROR;
}
