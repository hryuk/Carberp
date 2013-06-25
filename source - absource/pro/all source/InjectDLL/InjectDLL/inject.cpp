#include "stdafx.h"

#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>

typedef HMODULE (WINAPI *typeLoadLibrary)(LPCTSTR);
typedef BOOL (WINAPI *typeFreeLibrary)( HMODULE hLibModule ); 
typedef FARPROC (WINAPI *typeGetProcAddress)( HMODULE, LPCSTR );
typedef int (WINAPI *typeMessageBox)( HWND, LPCTSTR, LPCTSTR, UINT );
typedef void (WINAPI *typeExitThread)( DWORD );
typedef void (WINAPI *type_run)(void);

#define STATUS_SUCCESS                          ((NTSTATUS)0x00000000L) // ntsubauth

typedef struct _UNICODE_STRING 
{
	USHORT  Length;
	USHORT  MaximumLength;
	PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _OBJECT_ATTRIBUTES
{
	ULONG			uLength;
	HANDLE			hRootDirectory;
	PUNICODE_STRING	pObjectName;
	ULONG			uAttributes;
	PVOID			pSecurityDescriptor;
	PVOID			pSecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef struct _CLIENT_ID
{
	HANDLE	UniqueProcess;
	HANDLE	UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

extern "C"
NTSYSAPI
NTSTATUS
NTAPI
ZwOpenProcess (
    OUT PHANDLE             ProcessHandle,
    IN ACCESS_MASK          DesiredAccess,
    IN POBJECT_ATTRIBUTES   ObjectAttributes,
    IN PCLIENT_ID           ClientId OPTIONAL
);


struct FuncInfo 
{ 
	typeLoadLibrary LoadLibrary;
	typeFreeLibrary FreeLibrary;
	typeGetProcAddress GetProcAddress;
	char kernel32[16];
	char user32[16];
	char dll[MAX_PATH];
	char run[16];
	char MessageBox[16];
	char ExitThread[16];
	char text[16];  
	char title[16];
};

void* InjectMemory( HANDLE process, void* address, int size )
{
	void* new_address = VirtualAllocEx( process, 0, size, MEM_COMMIT | MEM_RESERVE,
		                                 PAGE_EXECUTE_READWRITE );
	if( new_address == 0 ) return 0;
	if( WriteProcessMemory( process, new_address, address, size, 0 ) == 0 )
		return 0;
	return new_address;
}

DWORD __stdcall MyFunc( FuncInfo* info )
{
	//typeMessageBox MessageBox = (typeMessageBox) info->GetProcAddress( info->LoadLibrary(info->user32), info->MessageBox );
	//MessageBox( 0, info->user32, info->user32, 0 );
	typeExitThread ExitThread = (typeExitThread) info->GetProcAddress( info->LoadLibrary(info->kernel32), info->ExitThread );
	HMODULE dll = info->LoadLibrary( info->dll );
	if( dll )
	{
		type_run run = (type_run) info->GetProcAddress( dll, info->run );
		if( run )
			run();
	}
	//info->FreeLibrary(dll);
	//ExitThread(0);
	return 0;
}

int __stdcall EndFunc()
{
	return 0;
}



bool InjectDLL( const char* nameProcess, const char* pathDll, const char* func )
{
	bool res = false;
	FuncInfo info;
	lstrcpy( info.kernel32, "kernel32.dll" );
	lstrcpy( info.user32, "user32.dll" );

	lstrcpy( info.dll, pathDll );

	lstrcpy( info.run, func );
	lstrcpy( info.MessageBox, "MessageBoxA" );
	lstrcpy( info.ExitThread, "ExitThread" );
	lstrcpy( info.text, "Hello, world!" );
	lstrcpy( info.title, "Injected func" );

	HMODULE kernel = GetModuleHandle(info.kernel32);
	info.LoadLibrary = (typeLoadLibrary) GetProcAddress( kernel, "LoadLibraryA" );
	info.GetProcAddress = (typeGetProcAddress) GetProcAddress( kernel, "GetProcAddress" );
	info.FreeLibrary = (typeFreeLibrary) GetProcAddress( kernel, "FreeLibrary" );

	bool find = false;
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);
	HANDLE snap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( snap, &pe );
	do
	{
	    if( lstrcmpi( pe.szExeFile, nameProcess ) == 0 )
		{
			find = true;
			break;
		}
	} while( Process32Next( snap, &pe ) );
	CloseHandle(snap); 
 
	if( find )
	{
		HANDLE process = OpenProcess( PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, pe.th32ProcessID );
		/*
		OBJECT_ATTRIBUTES ObjectAttributes = { sizeof(ObjectAttributes) } ;
		CLIENT_ID ClientID;

		ClientID.UniqueProcess = (HANDLE)pe.th32ProcessID;
		ClientID.UniqueThread  = 0;
		
		if( ZwOpenProcess( &process, PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, &ObjectAttributes, &ClientID ) != STATUS_SUCCESS )
		{
			process = 0;
		}
		*/
		if( process )
		{
			void* run_address = InjectMemory( process, &MyFunc, int(EndFunc) - int(MyFunc) );
			void* ptr_info = InjectMemory( process, &info, sizeof(info) );
			HANDLE thread = CreateRemoteThread( process, 0, 0, (LPTHREAD_START_ROUTINE ) run_address, ptr_info, 0, 0 );
			if( thread == 0 )
			{
				int err = GetLastError();
				char msg[128];
				wsprintf( msg, "not run thread (err = %d)", err );
				MessageBox( 0, msg, "InjectDLL", 0 );
			}
			else
			{
				CloseHandle(thread);
				char buf[512];
				wsprintf( buf,  "dll injected in process", nameProcess );
				MessageBox( 0, buf, "InjectDLL", 0 );
				res = true;
			}
		}
		else 
		{
			char buf[512];
			wsprintf( buf,  "not open process %s, err = %d", nameProcess, GetLastError() );
			MessageBox( 0, buf, "InjectDLL", 0 );
		}
	}
	else 
	{
			char buf[512];
			wsprintf( buf,  "not found process %s", nameProcess );
			MessageBox( 0, buf, "InjectDLL", 0 );
	}
	return res;
}

