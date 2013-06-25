#include "stdafx.h"
#include "../common/ws2help.h"
#include "../common/crypt.h"
#include "../common/keyfile.h"

//===============================================
// params

string g_ParamServer;
int g_ParamPort = 100;
string g_ParamKey;

ClientKey g_Key(L"",true);

//===============================================
// client

HANDLE g_hClient = 0;
DWORD g_dwClient = 0;

DWORD WINAPI ClientThread( LPVOID lpThreadParameter )
{
	DWORD dwExitCode = 0;
	SOCKET s = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if( s != INVALID_SOCKET )
	{
		sockaddr_in rmt;
		ZeroMemory( &rmt, sizeof(rmt) );

		sockaddr_in loc;
		ZeroMemory( &loc, sizeof(loc) );
		if( WS_ResolveName( &loc, 0, "" ) &&
			WS_ResolveName( &rmt, 0, g_ParamServer.c_str() ) )
		{
			loc.sin_family = AF_INET;

			rmt.sin_family = AF_INET;
			rmt.sin_port = htons(g_ParamPort);

			if( bind( s, (sockaddr*)&loc, sizeof(loc) ) == 0 )
			{
				if( connect( s, (sockaddr*)&rmt, sizeof(rmt) ) == 0 )
				{
					vector<BYTE> fullcontent;
					AppendValue( fullcontent, g_Key.backhash );
					AppendValue( fullcontent, g_Key.content );

					vector<BYTE> r;
					if( Encode( fullcontent, g_Key.hash, r ) )
					{
						DWORD sz = r.size();
						send( s, (char*)&sz, 4, 0 );
						send( s, (char*)(r.get_allocator().address(r.front())), r.size(), 0 );

						sz = 0;
						if( recv( s, (char*)&sz, 4, 0 ) == 4 )
						{
							if( sz > 0 )
							{
								vector<BYTE> msg;
								msg.resize(sz);
								recv( s, (char*)(msg.get_allocator().address(msg.front())), msg.size(), 0 );

								vector<BYTE> emsg;
								if( Decode( msg, g_Key.backhash, emsg ) )
								{
									char *s = (char*)(emsg.get_allocator().address(emsg.front()));
									if( strcmp("Key match found, client is valid!",s) == 0 )
									{
										dwExitCode = 1;
									}
								}
							}
						}
					}
				}
			}
		}

		shutdown( s, SD_BOTH );
		closesocket( s );
	}

	return dwExitCode;
}

//===============================================

bool OpenClient()
{
	WS_Start();
	if( !CryptInit() )
	{
		return false;
	}
	if( !g_Key.InitFromString( g_ParamKey.c_str() ) )
	{
		return false;
	}
	g_hClient = CreateThread(0,0,ClientThread,0,0,&g_dwClient);
	return (g_hClient != NULL);
}

bool CloseClient()
{
	WaitForSingleObject( g_hClient, INFINITE );
	CloseHandle( g_hClient );

	CryptCleanup();

	WS_Stop();
	return true;
}

//===============================================

bool Authorize( )
{
	bool bResult = false;

	if( OpenClient() )
	{
		if( WaitForSingleObject( g_hClient, INFINITE ) == WAIT_OBJECT_0 )
		{
			DWORD dwCode = 0;
			//GetExitCodeThread( g_hClient, &dwCode );
			if( GetExitCodeThread( g_hClient, &dwCode ) )
			{
				bResult = (dwCode==1);
			}
		}

		CloseClient();
	}

	return bResult;
}

bool OnlineAccess(
	char *Server, int Port,
	char *Key )
{
	g_ParamServer = Server;
	g_ParamPort = Port;
	g_ParamKey = Key;
	return Authorize();
}
