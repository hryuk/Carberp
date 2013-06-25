#include "stdafx.h"
#include "ws2help.h"


bool WS_Start()
{
	// start sockets...
	WSADATA wsa;
	ZeroMemory(&wsa,sizeof(wsa));
	return (WSAStartup( MAKEWORD( 2, 2 ), &wsa ) == 0);
}

bool WS_Stop()
{
	// close sockets...
	return (WSACleanup()==0);
}

bool WS_ResolveName(
	sockaddr_in *addr,char *res_name,const char *name )
{
	_ASSERTE( name );
	_ASSERTE( addr );
	
	hostent *he = gethostbyname( name );
	if( he == 0 ){
		return false;   }

	if( he->h_addrtype != AF_INET ){
		return false;    }
	
	if( he->h_length != 4 ){
		return false;   }

	if( he->h_addr_list[0] == 0 ){
		return false;       }

	if( res_name )
	{
		res_name[0] = 0;
		if( he->h_name )
			lstrcpyA(res_name,he->h_name);
	}

	ZeroMemory( addr, sizeof(*addr) );
	addr->sin_addr = *(in_addr*)(he->h_addr_list[0]);

	return true;
}


bool WS_CanSend( SOCKET s, TIMEVAL *tmval )
{
	fd_set fds;
	fds.fd_count = 1;
	fds.fd_array[0] = s;
	if( 1==select(1,0,&fds,0,tmval) ){
		return (fds.fd_array[0]==s);
	}
	return false;
}


bool WS_TryReceive( SOCKET s, BYTE *buffer, int max_size, int *pReceived ){

	*pReceived = 0;
	long to_receive = 0;
	if( ioctlsocket( s, FIONREAD, (unsigned long *) &to_receive ) == 0 ){

		if( to_receive > 0 ){

			if( to_receive > max_size ){
				to_receive = max_size;
			}

			if( recv(s,(char*)buffer,to_receive,0) == to_receive ){

				*pReceived = to_receive;
			
			} else {
				return false;
			}
		}
	}

	return true;
}

bool WS_TryReceive2( SOCKET s, vector<BYTE>& buffer, int *pReceived ){

	*pReceived = 0;
	long to_receive = 0;
	if( ioctlsocket( s, FIONREAD, (unsigned long *) &to_receive ) == 0 ){
		if( to_receive > 0 ){
			size_t oldsize = buffer.size();
			buffer.resize( oldsize + to_receive );
			if( recv(s,(char*)&buffer[oldsize],to_receive,0) == to_receive ){
				*pReceived = to_receive;
			} else {
				return false;
			}
		}
	}

	return true;
}
