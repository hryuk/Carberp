#include "stdafx.h"
#include "../common/ws2help.h"


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
// client

void ParsePacket( BYTE *p, DWORD size ,sockaddr_in from)
{
	BYTE *pEnd = p + size;
	p += 4;

	wstring name = (WCHAR*)p;
	p += (name.length() + 1) * 2;

	name += L"_";

	time_t t0 = time(0);
	name += _wasctime( localtime(&t0) );

	name += L".jpg";

	for( size_t i=0; i<name.length(); )
	{
		if( name[i] == L':' ||
			name[i] == L' ' )
		{
			name[i] = L'_';
			i++;
		}
		else if( name[i] == L'\n' ||
			name[i] == L'\r' )
		{
			name.erase( i, 1 );
		}
		else
		{
			i++;
		}
	}
	WCHAR DataIp[30];
	ZeroMemory(DataIp,30);
	wsprintfW(DataIp,L"%d.%d.%d.%d\\",
			from.sin_addr.S_un.S_un_b.s_b1,
			from.sin_addr.S_un.S_un_b.s_b2,
			from.sin_addr.S_un.S_un_b.s_b3,
			from.sin_addr.S_un.S_un_b.s_b4);
	

	WCHAR Cur[MAX_PATH];
	ZeroMemory(Cur,MAX_PATH);
	lstrcpy(Cur,name.c_str());
	int i=lstrlen(Cur);
	for (int i=name.size();i>=0 ;i--)
	{
		if (Cur[i]=='[')
		{
			Cur[i]='\\';
			break;
		}
		Cur[i]='\0';
	}

	WCHAR CurD[MAX_PATH];
	GetCurrentDirectoryW(MAX_PATH,CurD);
	lstrcat(CurD,L"\\");
	lstrcat(CurD,DataIp);
	CreateDirectoryW(CurD,NULL);
	lstrcat(CurD,Cur);
	CreateDirectoryW(CurD,NULL);
	
	name = Cur+name;
	name = DataIp+name;
	


	DWORD dwWr = 0;
	HANDLE hf = CreateFile( name.c_str(), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
	DWORD err=GetLastError();
	WriteFile( hf, p+9, (pEnd-p)-9, &dwWr, 0 );
	CloseHandle( hf );
}

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
			if( blockSize <= 0x7FFFF )
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

				ParsePacket( p, buffer.size(), from );
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
			cl.sin_port = htons(199);
			listen_addr.push_back( cl );
		}

		sockaddr_in cl;
		ZeroMemory( &cl, sizeof(cl) );
		cl.sin_addr.S_un.S_un_b.s_b1 = 127;
		cl.sin_addr.S_un.S_un_b.s_b2 = 0;
		cl.sin_addr.S_un.S_un_b.s_b3 = 0;
		cl.sin_addr.S_un.S_un_b.s_b4 = 1;
		cl.sin_family = AF_INET;
		cl.sin_port = htons(199);
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
	g_hListener = CreateThread(0,0,ListenerThread,0,0,&g_dwListener);
	return (g_hListener != NULL);
}

bool CloseServer()
{
	TerminateThread( g_hListener, 0 );
	CloseHandle( g_hListener );
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

