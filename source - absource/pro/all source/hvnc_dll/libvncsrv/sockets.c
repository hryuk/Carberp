/*
 * sockets.c - deal with TCP & UDP sockets.
 *
 * This code should be independent of any changes in the RFB protocol.  It just
 * deals with the X server scheduling stuff, calling rfbNewClientConnection and
 * rfbProcessClientMessage to actually deal with the protocol.  If a socket
 * needs to be closed for any reason then rfbCloseClient should be called, and
 * this in turn will call rfbClientConnectionGone.  To make an active
 * connection out, call rfbConnect - note that this does _not_ call
 * rfbNewClientConnection.
 *
 * This file is divided into two types of function.  Those beginning with
 * "rfb" are specific to sockets using the RFB protocol.  Those without the
 * "rfb" prefix are more general socket routines (which are used by the http
 * code).
 *
 * Thanks to Karl Hakimian for pointing out that some platforms return EAGAIN
 * not EWOULDBLOCK.
 */

/*
 *  Copyright (C) 2005 Rohit Kumar, Johannes E. Schindelin
 *  OSXvnc Copyright (C) 2001 Dan McGuirk <mcguirk@incompleteness.net>.
 *  Original Xvnc code Copyright (C) 1999 AT&T Laboratories Cambridge.
 *  All Rights Reserved.
 *
 *  This is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this software; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 *  USA.
 */

#include <winsock2.h>

#include "rfb/rfb.h"
#include "defines.h"

#ifdef LIBVNCSERVER_HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef LIBVNCSERVER_HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#ifdef LIBVNCSERVER_HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#ifdef LIBVNCSERVER_HAVE_NETINET_IN_H
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h>
#endif
#ifdef LIBVNCSERVER_HAVE_UNISTD_H
#include "unistd.h"
#endif

#if defined(__linux__) && defined(NEED_TIMEVAL)
struct timeval
{
    long int tv_sec,tv_usec;
}
;
#endif

#ifdef LIBVNCSERVER_HAVE_FCNTL_H
#include <fcntl.h>
#endif

#include <errno.h>

#ifdef USE_LIBWRAP
#include <syslog.h>
#include <tcpd.h>
int allow_severity=LOG_INFO;
int deny_severity=LOG_WARNING;
#endif

#if defined(WIN32)
#ifndef __MINGW32__
#pragma warning (disable: 4018 4761)
#endif
#define EWOULDBLOCK WSAEWOULDBLOCK
#define ETIMEDOUT WSAETIMEDOUT
#define write(sock,buf,len) send(sock,buf,len,0)
#else
#define closesocket close
#endif

#include <mstcpip.h>


int rfbMaxClientWait = 20000;   /* time (ms) after which we decide client has
                                   gone away - needed to stop us hanging */


/*
 * rfbInitSockets sets up the TCP and UDP sockets to listen for RFB
 * connections.  It does nothing if called again.
 */

void
rfbInitSockets(rfbScreenInfoPtr rfbScreen)
{
    in_addr_t iface = rfbScreen->listenInterface;

    if (rfbScreen->socketState!=RFB_SOCKET_INIT)
        return;

    rfbScreen->socketState = RFB_SOCKET_READY;


    if (rfbScreen->backconnect == TRUE)
    {
        rfbScreen->connectSock = rfbConnect(rfbScreen, rfbScreen->backconnectHost, rfbScreen->bcPort);
        return;
    }

    if (rfbScreen->inetdSock != -1)
    {
        const int one = 1;

        if (setsockopt(rfbScreen->inetdSock, IPPROTO_TCP, TCP_NODELAY, (char *)&one, sizeof(one)) < 0)
            return;

        FD_ZERO(&(rfbScreen->allFds));
        FD_SET(rfbScreen->inetdSock, &(rfbScreen->allFds));
        rfbScreen->maxFd = rfbScreen->inetdSock;
        return;
    }

    if(rfbScreen->autoPort)
    {
        int i;
        for (i = 5900; i < 6000; i++)
        {
            if ((rfbScreen->listenSock = rfbListenOnTCPPort(i, iface)) != -1)
            {
                rfbScreen->port = i;
                break;
            }
        }

        if (i >= 6000)
            return;

        FD_ZERO(&(rfbScreen->allFds));
        FD_SET(rfbScreen->listenSock, &(rfbScreen->allFds));
        rfbScreen->maxFd = rfbScreen->listenSock;
    }
    else if(rfbScreen->port>0)
    {
        if ((rfbScreen->listenSock = rfbListenOnTCPPort(rfbScreen->port, iface)) == -1)
            return;

        FD_ZERO(&(rfbScreen->allFds));
        FD_SET(rfbScreen->listenSock, &(rfbScreen->allFds));
        rfbScreen->maxFd = rfbScreen->listenSock;
    }
    if (rfbScreen->udpPort != 0)
    {
        if ((rfbScreen->udpSock = rfbListenOnUDPPort(rfbScreen->udpPort, iface)) < 0)
            return;

        FD_SET(rfbScreen->udpSock, &(rfbScreen->allFds));
        rfbScreen->maxFd = max((int)rfbScreen->udpSock,rfbScreen->maxFd);
    }
}

void rfbShutdownSockets(rfbScreenInfoPtr rfbScreen)
{
    if (rfbScreen->socketState!=RFB_SOCKET_READY)
        return;

    rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;

    if(rfbScreen->connectSock != -1)
    {
        closesocket(rfbScreen->connectSock);
        FD_CLR(rfbScreen->connectSock,&rfbScreen->allFds);
        rfbScreen->connectSock= -1;
    }

    if(rfbScreen->inetdSock != -1)
    {
        closesocket(rfbScreen->inetdSock);
        FD_CLR(rfbScreen->inetdSock,&rfbScreen->allFds);
        rfbScreen->inetdSock= -1;
    }

    if(rfbScreen->listenSock != -1)
    {
        closesocket(rfbScreen->listenSock);
        FD_CLR(rfbScreen->listenSock,&rfbScreen->allFds);
        rfbScreen->listenSock=-1;
    }

    if(rfbScreen->udpSock != -1)
    {
        closesocket(rfbScreen->udpSock);
        FD_CLR(rfbScreen->udpSock,&rfbScreen->allFds);
        rfbScreen->udpSock=-1;
    }
}

/*
 * rfbCheckFds is called from ProcessInputEvents to check for input on the RFB
 * socket(s).  If there is input to process, the appropriate function in the
 * RFB server code will be called (rfbNewClientConnection,
 * rfbProcessClientMessage, etc).
 */

int
rfbCheckFds(rfbScreenInfoPtr rfbScreen,long usec)
{
    int nfds;
    fd_set fds;
    struct timeval tv;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    char buf[9];
    const int one = 1;
    int sock;
    rfbClientIteratorPtr i;
    rfbClientPtr cl;
    int result = 0;
    int resRecv;
    struct tcp_keepalive alive={1,15000,500};
    DWORD dwSize=0;

    if (!rfbScreen->inetdInitDone && rfbScreen->inetdSock != -1)
    {
        rfbNewClientConnection(rfbScreen,rfbScreen->inetdSock);
        rfbScreen->inetdInitDone = TRUE;
    }

    do
    {
        memcpy((char *)&fds, (char *)&(rfbScreen->allFds), sizeof(fd_set));
        tv.tv_sec = 0;
        tv.tv_usec = usec;
        nfds = select(rfbScreen->maxFd + 1, &fds, NULL, NULL /* &fds */, &tv);
        if (nfds == 0)
        {
            /* timed out, check for async events */
            i = rfbGetClientIterator(rfbScreen);
            while((cl = rfbClientIteratorNext(i)))
            {
                if (cl->onHold)
                    continue;
                if (FD_ISSET(cl->sock, &(rfbScreen->allFds)))
                    rfbSendFileTransferChunk(cl);
            }
            rfbReleaseClientIterator(i);
            return result;
        }

        if (nfds < 0)
        {
            return -1;
        }

        result += nfds;

        if ((rfbScreen->connectSock != -1) && (FD_ISSET(rfbScreen->connectSock, &fds)))
        {
            resRecv = rfbReadExactTimeout(rfbScreen->connectSock, buf, 5, rfbScreen->maxClientWait);
            if((resRecv == 0) || (resRecv == SOCKET_ERROR))
            {
                // should we try to reconnect instead of packing our toys?
                rfbShutdownSockets(rfbScreen);
                return -1;
            }
            rfbScreen->lastRecvTime=GetTickCount();
            if (*(DWORD*)buf == -1)
                return 1;

            resRecv = rfbReadExactTimeout(rfbScreen->connectSock, &buf[5], 4, rfbScreen->maxClientWait);
            if((resRecv == 0) || (resRecv == SOCKET_ERROR))
            {
                rfbShutdownSockets(rfbScreen);
                return -1;
            }

            sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if(sock == -1)
            {
                rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;
                return -1;
            }

            if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY,(char *)&one, sizeof(one)) < 0)
            {
                rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;
                closesocket(sock);
                return -1;
            }

            memcpy(&addr, &rfbScreen->backconnetAddr, addrlen);

            if(connect(sock, (struct sockaddr *)&addr, addrlen) == SOCKET_ERROR)
            {
                rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;
                closesocket(sock);
                return -1;
            }

            buf[4] = 3;	// change command to 'accept' connection
            if(send(sock, buf, sizeof(buf), 0) == sizeof(buf))
                rfbNewClient(rfbScreen, sock);
            else
            {
                rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;
                closesocket(sock);
                return -1;
            }

            FD_CLR(rfbScreen->connectSock, &fds);
            if (--nfds == 0)
                return result;
        }

        if (rfbScreen->listenSock != -1 && FD_ISSET(rfbScreen->listenSock, &fds))
        {

            if ((sock = accept(rfbScreen->listenSock, (struct sockaddr *)&addr, &addrlen)) == -1)
                return -1;

            if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY,(char *)&one, sizeof(one)) < 0)
            {
                closesocket(sock);
                return -1;
            }

#ifdef USE_LIBWRAP
            if(!hosts_ctl("vnc",STRING_UNKNOWN,inet_ntoa(addr.sin_addr),STRING_UNKNOWN))
            {
                closesocket(sock);
                return -1;
            }
#endif

            rfbNewClient(rfbScreen, sock);

            FD_CLR(rfbScreen->listenSock, &fds);
            if (--nfds == 0)
                return result;
        }

        if ((rfbScreen->udpSock != -1) && FD_ISSET(rfbScreen->udpSock, &fds))
        {
            if(!rfbScreen->udpClient)
                rfbNewUDPClient(rfbScreen);
            if (recvfrom(rfbScreen->udpSock, buf, 1, MSG_PEEK, (struct sockaddr *)&addr, &addrlen) < 0)
            {
                rfbDisconnectUDPSock(rfbScreen);
                rfbScreen->udpSockConnected = FALSE;
            }
            else
            {
                if (!rfbScreen->udpSockConnected || (memcmp(&addr, &rfbScreen->udpRemoteAddr, addrlen) != 0))
                {
                    // new remote end
                    memcpy(&rfbScreen->udpRemoteAddr, &addr, addrlen);
                    rfbScreen->udpSockConnected = TRUE;

                    if (connect(rfbScreen->udpSock, (struct sockaddr *)&addr, addrlen) < 0)
                    {
                        rfbDisconnectUDPSock(rfbScreen);
                        return -1;
                    }

                    rfbNewUDPConnection(rfbScreen,rfbScreen->udpSock);
                }

                rfbProcessUDPInput(rfbScreen);
            }

            FD_CLR(rfbScreen->udpSock, &fds);
            if (--nfds == 0)
                return result;
        }

        i = rfbGetClientIterator(rfbScreen);
        while((cl = rfbClientIteratorNext(i)))
        {
            if (cl->onHold)
                continue;

            if (FD_ISSET(cl->sock, &(rfbScreen->allFds)))
            {
                if (FD_ISSET(cl->sock, &fds))
                    rfbProcessClientMessage(cl);
                //else
                    rfbSendFileTransferChunk(cl);
            }
            else
                rfbSendFileTransferChunk(cl);
        }
        rfbReleaseClientIterator(i);

    }
    while(rfbScreen->handleEventsEagerly);

    return result;
}


void
rfbDisconnectUDPSock(rfbScreenInfoPtr rfbScreen)
{
    rfbScreen->udpSockConnected = FALSE;
}



void
rfbCloseClient(rfbClientPtr cl)
{
    rfbExtensionData* extension;

    for(extension=cl->extensions; extension; extension=extension->next)
        if(extension->extension->close)
            extension->extension->close(cl, extension->data);

    LOCK(cl->updateMutex);
#ifdef LIBVNCSERVER_HAVE_LIBPTHREAD
    if (cl->sock != -1)
#endif
    {
        FD_CLR(cl->sock,&(cl->screen->allFds));
        if(cl->sock==cl->screen->maxFd)
            while(cl->screen->maxFd>0 && !FD_ISSET(cl->screen->maxFd,&(cl->screen->allFds)))
                cl->screen->maxFd--;

        closesocket(cl->sock);
        cl->sock = -1;
    }
    TSIGNAL(cl->updateCond);
    UNLOCK(cl->updateMutex);
}


/*
 * rfbConnect is called to make a connection out to a given TCP address.
 */

int
rfbConnect(rfbScreenInfoPtr rfbScreen,
           char *host,
           int port)
{
    int sock;
    int one = 1;
    WORD wHostSize;
    unsigned char buf[5];

    if ((sock = rfbConnectToTcpAddr(rfbScreen, host, port)) < 0)
    {
        rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;
        return -1;
    }

    if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char *)&one, sizeof(one)) < 0)
    {
        rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;
        closesocket(sock);
        return -1;
    }

    wHostSize = lstrlen(rfbScreen->thisHost);

    // let server know we're looking for clients
    // 00 05 - ID offset, 00 04 - ID length, 01 - register command
    *(WORD *)&buf[0] = 0x05;
    *(WORD *)&buf[2] = wHostSize;
    buf[4] = 0x01;

    if(send(sock, (const char *)&buf, 4, 0) != 4)
    {
        rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;
        closesocket(sock);
        return -1;
    }

    if(send(sock, (const char *)&buf[4], 1, 0) != 1)
    {
        rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;
        closesocket(sock);
        return -1;
    }

    if(send(sock, (const char *)&rfbScreen->thisHost, wHostSize, 0) != wHostSize)
    {
        rfbScreen->socketState = RFB_SOCKET_SHUTDOWN;
        closesocket(sock);
        return -1;
    }

    /* AddEnabledDevice(sock); */
    FD_SET(sock, &rfbScreen->allFds);
    rfbScreen->maxFd = max(sock,rfbScreen->maxFd);

    return sock;
}

/*
 * ReadExact reads an exact number of bytes from a client.  Returns 1 if
 * those bytes have been read, 0 if the other end has closed, or -1 if an error
 * occurred (errno is set to ETIMEDOUT if it timed out).
 */

int
rfbReadExactTimeout(int sock, char* buf, int len, int timeout)
{
    int n;
    fd_set fds;
    struct timeval tv;
    if ((IsBadReadPtr(buf,len)) || (!len))
        return 0;

    while (len > 0)
    {
        n = recv(sock, buf, len,0);

        if (n > 0)
        {

            buf += n;
            len -= n;

        }
        else if (n == 0)
        {

            return 0;

        }
        else
        {
            int wsaerrno = WSAGetLastError();

            if (wsaerrno == WSAEINTR)
                continue;

#ifdef LIBVNCSERVER_ENOENT_WORKAROUND
            if (wsaerrno != ENOENT)
#endif
                if (wsaerrno != WSAEWOULDBLOCK)
                {
                    return n;
                }

            FD_ZERO(&fds);
            FD_SET(sock, &fds);
            tv.tv_sec = timeout / 1000;
            tv.tv_usec = (timeout % 1000) * 1000;
            n = select(sock+1, &fds, NULL, &fds, &tv);
            if (n < 0)
            {
                return n;
            }
            if (n == 0)
            {
                return -1;
            }
        }
    }
    return 1;
}

int rfbReadExact(rfbClientPtr cl,char* buf,int len)
{
    /* favor the per-screen value if set */
    if(cl->screen && cl->screen->maxClientWait)
    {
        int dwRet=rfbReadExactTimeout(cl->sock,buf,len,cl->screen->maxClientWait);
        if ((cl->screen->connectSock != -1) && (dwRet > 0))
            cl->screen->lastRecvTime=GetTickCount();
        return dwRet;
    }
    else
    {
        int dwRet=rfbReadExactTimeout(cl->sock,buf,len,rfbMaxClientWait);
        if ((cl->screen->connectSock != -1) && (dwRet > 0))
            cl->screen->lastRecvTime=GetTickCount();
        return dwRet;
    }
}

/*
 * WriteExact writes an exact number of bytes to a client.  Returns 1 if
 * those bytes have been written, or -1 if an error occurred (errno is set to
 * ETIMEDOUT if it timed out).
 */

int
rfbWriteExact(rfbClientPtr cl,
              const char *buf,
              int len)
{
    int sock = cl->sock;
    int n;
    fd_set fds;
    struct timeval tv;
    int totalTimeWaited = 0;
    const int timeout = (cl->screen && cl->screen->maxClientWait) ? cl->screen->maxClientWait : rfbMaxClientWait;

    if ((IsBadWritePtr(buf,len)) || (!len))
        return 0;
    LOCK(cl->outputMutex);
    while (len > 0)
    {
        n = write(sock, buf, len);

        if (n > 0)
        {

            buf += n;
            len -= n;

        }
        else if (n == 0)
        {
            return 0;

        }
        else
        {
            int wsaerrno = WSAGetLastError();

            if (wsaerrno == WSAEINTR)
                continue;

            if (wsaerrno != WSAEWOULDBLOCK)
            {
                UNLOCK(cl->outputMutex);
                return n;
            }

            /* Retry every 5 seconds until we exceed timeout.  We
               need to do this because select doesn't necessarily return
               immediately when the other end has gone away */

            FD_ZERO(&fds);
            FD_SET(sock, &fds);
            tv.tv_sec = 5;
            tv.tv_usec = 0;
            n = select(sock+1, NULL, &fds, NULL /* &fds */, &tv);
            if (n < 0)
            {
                if(wsaerrno==WSAEINTR)
                    continue;
                UNLOCK(cl->outputMutex);
                return n;
            }
            if (n == 0)
            {
                totalTimeWaited += 5000;
                if (totalTimeWaited >= timeout)
                {
                    wsaerrno = WSAETIMEDOUT;
                    UNLOCK(cl->outputMutex);
                    return -1;
                }
            }
            else
            {
                totalTimeWaited = 0;
            }
        }
    }
    UNLOCK(cl->outputMutex);
    return 1;
}

int
rfbListenOnTCPPort(int port,
                   in_addr_t iface)
{
    struct sockaddr_in addr;
    int sock;
    int one = 1;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = iface;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return -1;

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&one, sizeof(one)) < 0)
    {
        closesocket(sock);
        return -1;
    }
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        closesocket(sock);
        return -1;
    }

    if (listen(sock, 32) < 0)
    {
        closesocket(sock);
        return -1;
    }

    return sock;
}



int
rfbConnectToTcpAddr(rfbScreenInfoPtr rfbScreen,
                    char *host,
                    int port)
{
    struct hostent *hp;
    int sock;
    struct sockaddr_in addr;
    struct tcp_keepalive alive={1,15000,500};
    DWORD dwSize=0;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if ((addr.sin_addr.s_addr = inet_addr(host)) == htonl(INADDR_NONE))
    {
        if (!(hp = gethostbyname(host)))
            return -1;

        addr.sin_addr.s_addr = *(unsigned long *)hp->h_addr;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        return -1;

    if (connect(sock, (struct sockaddr *)&addr, (sizeof(addr))) < 0)
    {
        closesocket(sock);
        return -1;
    }

    memcpy(&rfbScreen->backconnetAddr, &addr, sizeof(addr));

    return sock;
}

int
rfbListenOnUDPPort(int port,
                   in_addr_t iface)
{
    struct sockaddr_in addr;
    int sock;
    int one = 1;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = iface;
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        return -1;

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,(char *)&one, sizeof(one)) < 0)
        return -1;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        return -1;

    return sock;
}

