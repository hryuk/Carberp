// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../common/ws2help.h"
#include "../common/crypt.h"
#include "../common/keyfile.h"

//===============================================
// helper

class CLock
{
private:
	CRITICAL_SECTION m_Section;
public:
	CLock() { InitializeCriticalSection(&m_Section); }
	~CLock() { DeleteCriticalSection(&m_Section); }
	void Lock() { EnterCriticalSection(&m_Section); }
	void Unlock() { LeaveCriticalSection(&m_Section); }
};

//===============================================

CLock g_LogLock;
wstring g_LogName = L"access_log";

void InitLog( )
{
	TCHAR exename[MAX_PATH]=L"";
	if( GetModuleFileName(0,exename,sizeof(exename)-1) == 0 )
	{
		wcout << L"GetModuleFileName(0) failed." << endl;
		return;
	}

	TCHAR _Drive[MAX_PATH]=L"";
	TCHAR _Dir[MAX_PATH]=L"";
	TCHAR _Filename[MAX_PATH]=L"";
	TCHAR _Ext[MAX_PATH]=L"";
	_tsplitpath_s( exename, _Drive, _Dir, _Filename, _Ext );

	TCHAR _PathToLog[MAX_PATH]=L"";
	_tcscat_s( _PathToLog, _Drive );
	_tcscat_s( _PathToLog, _Dir );
	_tcscat_s( _PathToLog, L"access_log" );

	g_LogName = _PathToLog;
}

void AddStringToLog( LPCTSTR s )
{
	g_LogLock.Lock();

	HANDLE hf = CreateFile( g_LogName.c_str(), GENERIC_WRITE, FILE_SHARE_READ,
		0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
	if( hf != INVALID_HANDLE_VALUE )
	{
		SetFilePointer( hf, GetFileSize( hf, 0 ), 0, FILE_BEGIN );
		DWORD dwWritten = 0;
		WriteFile( hf, s, _tcslen(s)*sizeof(TCHAR), &dwWritten, 0 );

		CloseHandle( hf );
	}

	g_LogLock.Unlock();
}


//===============================================
// client keys

list<ClientKey> g_Keys;

bool LoadClientKeys()
{
	g_Keys.clear();

	TCHAR exename[MAX_PATH]=L"";
	if( GetModuleFileName(0,exename,sizeof(exename)-1) == 0 )
	{
		wcout << L"GetModuleFileName(0) failed." << endl;
		return false;
	}

	TCHAR _Drive[MAX_PATH]=L"";
	TCHAR _Dir[MAX_PATH]=L"";
	TCHAR _Filename[MAX_PATH]=L"";
	TCHAR _Ext[MAX_PATH]=L"";
	_tsplitpath_s( exename, _Drive, _Dir, _Filename, _Ext );

	TCHAR _PathToKeys[MAX_PATH]=L"";
	_tcscat_s( _PathToKeys, _Drive );
	_tcscat_s( _PathToKeys, _Dir );
	_tcscat_s( _PathToKeys, L"keys\\" );

	TCHAR _KeyMask[MAX_PATH]=L"";
	_tcscat_s( _KeyMask, _PathToKeys );
	_tcscat_s( _KeyMask, L"*.*" );

	WIN32_FIND_DATA fdata;
	ZeroMemory( &fdata, sizeof(fdata) );
	HANDLE hFind = FindFirstFile( _KeyMask, &fdata );
	if( hFind != INVALID_HANDLE_VALUE )
	{
		do
		{
			if( !(fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
			{
				TCHAR _RealName[MAX_PATH]=L"";
				_tcscat_s( _RealName, _PathToKeys );
				_tcscat_s( _RealName, fdata.cFileName );
				g_Keys.push_back( ClientKey(_RealName, false) );
			}
		}
		while( FindNextFile( hFind, &fdata ) );
		FindClose( hFind );
	}

	if( g_Keys.empty() )
	{
		wcout << L"Client keys not found." << endl;
		return false;
	}

	list<ClientKey>::iterator I = g_Keys.begin();
	for( ; I != g_Keys.end(); I++ )
	{
		if( !I->Load() )
		{
			return false;
		}
	}

	wcout << L"Loaded " << g_Keys.size() << " client keys." << endl;
	return true;
}

bool MatchClient(
	vector<BYTE>& auth,
	vector<BYTE>& key,
	vector<BYTE>& backkey,
	wostringstream& log_record )
{
	list<ClientKey>::iterator I = g_Keys.begin();
	for( ; I != g_Keys.end(); I++ )
	{
		vector<BYTE> to_compare;
		if( Decode( auth, I->hash, to_compare ) )
		{
			vector<BYTE> received_backhash;
			vector<BYTE> received_key;

			int curpos = 0;
			if( ExtractValue( to_compare, received_backhash, curpos ) &&
				ExtractValue( to_compare, received_key, curpos ) )
			{
				if( received_key.size() == I->content.size() )
				{
					bool bMatch = true;
					for( size_t i=0; i<I->content.size(); i++ )
					{
						if( received_key[i] != I->content[i] )
						{
							bMatch = false;
							break;
						}
					}
					if( bMatch )
					{
						char ggg[50];
						memset(ggg,0,50);
						memcpy(ggg,(char*)&I->content[0],I->content.size());
						
						key.insert( key.begin(), I->hash.begin(), I->hash.end() );
						backkey.insert( backkey.begin(), received_backhash.begin(), received_backhash.end() );
						
						log_record <<"\t"<< ggg<<"\tMatch";//received_key;//received_key.begin() ;//
						
						return true;
					}
					log_record << L" Does not match";
				}
				else
				{
					log_record << L" Does not match";
				}
			}
		}
	}
	log_record << L" Client not found.";
	return false;
}

//===============================================
// client

DWORD WINAPI ClientThread( LPVOID lpThreadParameter )
{
	SOCKET s = (SOCKET)lpThreadParameter;

	sockaddr_in from;
	int from_len = sizeof(from);
	ZeroMemory( &from, sizeof(from) );
	if( getpeername( s, (sockaddr*)&from, &from_len ) == 0 )
	{
		wcout << L"Session with " << from << L" established." << endl;

		wostringstream log_record;
		log_record << L"[" << from << L"]";

		DWORD blockSize = 0;
		int received = recv( s, (char*)&blockSize, 4, 0 );
		if( received == 4 )
		{
			if( blockSize <= 0x7FFF )
			{
				vector<BYTE> buffer;
				buffer.resize(blockSize);

				received = 0;
				BYTE *p = buffer.get_allocator().address(buffer.front());

				int r = 0;
				do
				{
					if( blockSize-received > 0 )
					{
						r = recv( s, (char*)(p+received), blockSize-received, 0 );
						received += r;
					}
					else
					{
						break;
					}
				}
				while( r > 0 );

				vector<BYTE> key;
				vector<BYTE> backkey;
				if( MatchClient(buffer,key,backkey,log_record) )
				{
					wcout << L"Client " << from << L" is OK, sending positive response." << endl;

					char *resp = "Key match found, client is valid!";
					vector<BYTE> resp1,eresp1;
					resp1.insert( resp1.end(), resp, resp + strlen(resp) + 1 );
					Encode( resp1, backkey, eresp1 );

					blockSize = eresp1.size();
					BYTE *p = eresp1.get_allocator().address(eresp1.front());
					send( s, (char*)&blockSize, 4, 0 );
					send( s, (char*)(p), blockSize, 0 );
				}
				else
				{
					wcout << L"Client " << from << L" not found." << endl;
				}
			}
			else
			{
				log_record << L" Invalid data size";
				wcout << L"Invalid data size from " << from << L"." << endl;
			}
		}
		else
		{
			log_record << L" Not enough data";
		}

		wcout << L"Session with " << from << L" closed." << endl;

		log_record << L"\r\n";
		AddStringToLog( log_record.str().c_str() );
	}

	shutdown( s, SD_BOTH );
	closesocket( s );
	return 0;
}

//===============================================
// listener

HANDLE g_hListener = 0;
DWORD g_dwListener = 0;

struct ThreadInfo
{
	HANDLE m_hClient;
	DWORD m_dwClient;

	ThreadInfo()
		: m_hClient( 0 )
		, m_dwClient( 0 )
	{
	}
};

CLock g_ClientLock;
list<ThreadInfo> g_Clients;

DWORD WINAPI ListenerThread( LPVOID lpThreadParameter )
{
	// enum interfaces

	list<sockaddr_in> listen_addr;

	{
		HOSTENT *he = gethostbyname(0);
		for( size_t i=0; he->h_addr_list[i]; i++ )
		{
			sockaddr_in cl;
			ZeroMemory( &cl, sizeof(cl) );

			CopyMemory( & cl.sin_addr.S_un.S_addr, he->h_addr_list[i], 4 );
			cl.sin_family = AF_INET;
			cl.sin_port = htons(900);
			listen_addr.push_back( cl );
		}

		sockaddr_in cl;
		ZeroMemory( &cl, sizeof(cl) );
		cl.sin_addr.S_un.S_un_b.s_b1 = 127;
		cl.sin_addr.S_un.S_un_b.s_b2 = 0;
		cl.sin_addr.S_un.S_un_b.s_b3 = 0;
		cl.sin_addr.S_un.S_un_b.s_b4 = 1;
		cl.sin_family = AF_INET;
		cl.sin_port = htons(900);
		listen_addr.push_back( cl );
	}

	// create listeners

	list<SOCKET> listeners;

	{
		list<sockaddr_in>::iterator _I = listen_addr.begin();
		for( ; _I != listen_addr.end(); _I++ )
		{
			SOCKET s = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
			if( s != INVALID_SOCKET )
			{
				if( bind( s, (sockaddr*)&(*_I), sizeof((*_I)) ) == 0 )
				{
					if( listen(s,10) == 0 )
					{
						wcout << L"Listening on " << (*_I) << L"." << endl;
						listeners.push_back( s );
					}
					else
					{
						closesocket( s );
					}
				}
				else
				{
					closesocket( s );
				}
			}
		}
	}

	// poll listeners


	while( 1 )
	{
		list<SOCKET>::iterator _I = listeners.begin();
		for( ; _I != listeners.end(); _I++ )
		{
			timeval to;
			to.tv_sec = 0;
			to.tv_usec = 0;

			fd_set fds;
			fds.fd_count = 1;
			fds.fd_array[0] = *_I;

			if( select(1,&fds,0,0,&to) == 1 )
			{
				sockaddr_in from;
				int from_len = sizeof(from);
				ZeroMemory( &from, sizeof(from) );
				SOCKET s1 = accept( *_I, (sockaddr*)&from, &from_len );
				if( s1 != INVALID_SOCKET )
				{
					wcout << L"Incoming call from " << from << L", accepted." << endl;

					ThreadInfo ti;
					ti.m_hClient = CreateThread( 0, 0, ClientThread, (LPVOID)s1, 0, &ti.m_dwClient );
					if( ti.m_hClient == NULL )
					{
						wcout << L"Failed to create client, ignored..." << endl;
						shutdown( s1, SD_BOTH );
						closesocket( s1 );
					}
					else
					{
						g_ClientLock.Lock();
						g_Clients.push_back(ti);
						g_ClientLock.Unlock();
					}
				}
				else
				{
					wcout << L"Incoming call, failed to accept, ignored..." << endl;
				}
			}

		}
		
		Sleep(50);

		// delete disconnected clients
		g_ClientLock.Lock();
		list<ThreadInfo>::iterator I = g_Clients.begin();
		for( ; I != g_Clients.end(); I++ )
		{
			if( WaitForSingleObject( I->m_hClient, 0 ) == WAIT_OBJECT_0 )
			{
				CloseHandle( I->m_hClient );
				g_Clients.erase( I );
				break;
			}
		}
		g_ClientLock.Unlock();
	}

	// close listeners
	{
		list<SOCKET>::iterator _I = listeners.begin();
		for( ; _I != listeners.end(); _I++ )
		{
			shutdown( *_I, SD_BOTH );
			closesocket( *_I );
		}
	}

	return 0;
}


//===============================================

bool OpenServer()
{
	InitLog();
	WS_Start();
	if( !CryptInit() )
	{
		return false;
	}
	if( !LoadClientKeys() )
	{
		return false;
	}
	g_hListener = CreateThread(0,0,ListenerThread,0,0,&g_dwListener);
	return (g_hListener != NULL);
}

bool CloseServer()
{
	// not a good way, but its enough for sample
	TerminateThread( g_hListener, 0 );
	CloseHandle( g_hListener );

	CryptCleanup();
	WS_Stop();
	return true;
}

//===============================================

int _tmain(int argc, _TCHAR* argv[])
{
	wcout << L"Starting server..." << endl;
	if( OpenServer() )
	{
		wcout << L"Server started, waiting for clients..." << endl;

		MSG msg;
		while( 1 )
		{
			if( PeekMessage( &msg, 0, 0, 0, PM_REMOVE ) )
			{
				if( msg.message == WM_QUIT )
				{
					break;
				}
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			}
			else
			{
				Sleep(10);
			}
		}

		CloseServer();
	}

	wcout << L"End." << endl;
	return 0;
}

