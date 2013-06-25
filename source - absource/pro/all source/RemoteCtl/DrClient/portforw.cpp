#include "stdafx.h"
#include "../common/protocol.h"
#include "ClientOps.h"

const char* IP_PORTFORW = "127.0.0.1";

struct TUNNEL_INFO
{
	SOCKET s1, s2;
};

SOCKET ConnectWithIP(const char* ip, int port)
{
	SOCKET s = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if( s != INVALID_SOCKET )
	{
		sockaddr_in laddr;
		ZeroMemory( &laddr, sizeof(laddr) );
		laddr.sin_family = AF_INET;
		if( bind( s, (sockaddr*)&laddr, sizeof(laddr) ) == 0 )
		{
			sockaddr_in raddr;
			ZeroMemory( &raddr, sizeof(raddr) );
			raddr.sin_family = AF_INET;
			raddr.sin_port = htons(port);
			raddr.sin_addr.S_un.S_addr = inet_addr(ip);
			if( connect( s, (sockaddr*)&raddr, sizeof(raddr) ) == 0 )
			{
				return s;
			}
		}
	}
	return 0;
}

void WINAPI Tunnel(TUNNEL_INFO *tunnelInfo)
{
    while (true)
    {
        fd_set fdsr;
        fdsr.fd_count=2;
        fdsr.fd_array[0]=tunnelInfo->s1;
        fdsr.fd_array[1]=tunnelInfo->s2;

        if (select(0,&fdsr,NULL,NULL,NULL) < 1)
		{
            break;
		}

        for (u_int i=0; i < fdsr.fd_count; i++)
        {
            char buf[1024];
            int dw;
            SOCKET hRead=fdsr.fd_array[i],
                   hWrite=((hRead == tunnelInfo->s1) ? tunnelInfo->s2 : tunnelInfo->s1);
            if (((dw=recv(hRead,buf,sizeof(buf), 0)) < 1) || (send(hWrite,buf,dw, 0) != dw))
                goto end;
        }
    }
end:
	closesocket(tunnelInfo->s1);
    closesocket(tunnelInfo->s2);
    free(tunnelInfo);
    return;
}

void ProcessPORTFORW( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(PORT_FORW) )
	{
		PORT_FORW* pf = (PORT_FORW*)p->data;
		int portForw = pf->portForw ? pf->portForw : defaultPortForward;
		int portConnect = pf->portConnect ? pf->portConnect : pContext->m_iPort;
		SOCKET s1 = ConnectWithIP( IP_PORTFORW, portForw ); //коннектимся к пробрасываемому порту
		if( s1 != 0 )
		{
			SOCKET s2 = ConnectWithIP( pContext->m_sServer, portConnect ); //коннектимся снова к клиенту
			if( s2 != 0 )
			{
				//сообщаем что соединились для проброса
				//PacketBuffer pb;
				//pb.Create( PK_CS_PORTFORW, p->timestamp, 0, 0 );
				//pb.Send(s2);
				//создаем туннель
				TUNNEL_INFO* tunnelInfo = (TUNNEL_INFO*) malloc(sizeof(TUNNEL_INFO));
				tunnelInfo->s1 = s1;
				tunnelInfo->s2 = s2;
				CloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Tunnel,(LPVOID)tunnelInfo,0,NULL));
			}
		}
	}
}
