#include <windows.h>
#include <tlhelp32.h>

#include "memory.h"
#include "Strings.h"
#include "inject.h"
#include "Exception.h"

#include "ExceptionDump.h"

#define MAX_COUNT_CALL_STASK_ADDR		0x10
#define MINIDUMP_SIZE					0x80
#define EXCEPTION_INFO_SIGNATURE		'ecif'

//
//	Бектрейс стека, по фреймам.
//	
VOID StackBackTrace(DWORD MaxCount,DWORD CallStack[])
{
	typedef struct _STACK_FRAME
	{
		_STACK_FRAME *Next;
		DWORD		 EIP;
	}STACK_FRAME,*PSTACK_FRAME;

	PNT_TIB	ptib;
	PSTACK_FRAME	pFrame;

	__asm push FS:[0x18];
	__asm pop [ptib];
	__asm mov pFrame,ebp;

	m_memset(CallStack,0,sizeof(DWORD)*MaxCount);
	for (DWORD i=0; i < MaxCount; ++i)
	{
		if (! (((DWORD)ptib->StackLimit <= (DWORD)pFrame) && ((DWORD)ptib->StackBase>(DWORD)pFrame)))
				return ;
		CallStack[i] = pFrame->EIP;
		pFrame = pFrame->Next;
	}
}

void AddProcessListToDump(DUMP::Writer* NtlvWriter)
{
	HANDLE SnapshotHandle = NULL;
	PROCESSENTRY32W ppe;

	m_memset(&ppe, 0, sizeof(ppe));
	ppe.dwSize=sizeof(PROCESSENTRY32W);

	SnapshotHandle = pCreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (SnapshotHandle == INVALID_HANDLE_VALUE) return;

	BOOL success_enum = (BOOL)pProcess32FirstW(SnapshotHandle,&ppe);
	while (success_enum)
	{
		DUMP::WriteList(NtlvWriter, "Process", 2);
		DUMP::WriteUint32(NtlvWriter, "ProcessId", ppe.th32ProcessID);
		DUMP::WriteStringW(NtlvWriter, "ProcessExeFile", ppe.szExeFile);
		
		success_enum = (BOOL)pProcess32NextW(SnapshotHandle, &ppe);
	}
	pCloseHandle(SnapshotHandle);
}

HMODULE GetDllHandleByExceptionAddress(const void* ExceptionAddress)
{
	BYTE* Addr = (BYTE*)ExceptionAddress;
	
	Addr = (BYTE*)((DWORD)Addr & 0xFFFF0000);
	while (true)
	{
		if (m_memcmp(Addr, "MZ", 2) == 0) return (HMODULE)Addr;
		Addr -= 0x00010000;
	}

	return (HMODULE)NULL;
}

LONG CALLBACK ExceptionHandler(PEXCEPTION_POINTERS ExceptionInfo)
{
	// Организуем поток для вывода дампа в файл.
	DUMP::WriteStream s;
	if (!File_InitDumpWriteStream(&s, L"c:\\dump.bin"))
	{
		// Если не получилось открыть поток - просто закрываем приложение.
		pExitProcess(0);
		return EXCEPTION_CONTINUE_EXECUTION;
	}

	// Организуем форматированный вывод в дамп параметров дампа.
	DUMP::Writer NtlvWriter;
	DUMP::InitWriter(&NtlvWriter, &s);

	// Получаем параметры текущего процесса.
	WCHAR ProcessFileName[MAX_PATH];
	m_memset(ProcessFileName, 0, sizeof(ProcessFileName));
	pGetModuleFileNameW(NULL, ProcessFileName, ARRAYSIZE(ProcessFileName) - 1);

	DUMP::WriteStringW(&NtlvWriter, "ProcessFileName", ProcessFileName);
	DUMP::WriteUint32(&NtlvWriter, "ProcessId", GetCurrentProcessId());
	DUMP::WriteUint32(&NtlvWriter, "ThreadId", GetCurrentThreadId());

	// Получаем параметры нашего модуля, который установил обработчик VEH.
	LPVOID BootBase = GetImageBase();
	DWORD SizeOfBoot = ((PIMAGE_NT_HEADERS)(((PIMAGE_DOS_HEADER)BootBase)->e_lfanew + (LPBYTE)BootBase))->OptionalHeader.SizeOfImage;

	DUMP::WriteUint32(&NtlvWriter, "BootBase", (DWORD)BootBase);
	DUMP::WriteUint32(&NtlvWriter, "SizeOfBoot", SizeOfBoot);

	WCHAR   ModulePath[MAX_PATH];
	HMODULE ModuleHandle = NULL;

	// Получаем базу модуля, в котором произошло падение.
	ModuleHandle = GetDllHandleByExceptionAddress(ExceptionInfo->ExceptionRecord->ExceptionAddress);
	
	// Получаем путь к падучему модулю
	m_memset(ModulePath, 0, sizeof(ModulePath));
	pGetModuleFileNameW(ModuleHandle, ModulePath, ARRAYSIZE(ModulePath) - 1);

	// Пишем базу и имя падучего модуля в дамп.
	DUMP::WriteUint32(&NtlvWriter,  "ExceptionModuleBase", (DWORD)ModuleHandle);
	DUMP::WriteStringW(&NtlvWriter, "ExceptionModulePath", ModulePath);

	// Пишем ExceptionRecord исключения
	DUMP::WriteByteArray(&NtlvWriter, "ExceptionRecord", ExceptionInfo->ExceptionRecord, 
		sizeof(EXCEPTION_RECORD));

	// Пишем Context Frame исключения
	DUMP::WriteByteArray(&NtlvWriter, "ContextRecord", &ExceptionInfo->ContextRecord,
		sizeof(CONTEXT));

	// Получаем стек вызовов.
	DWORD CallStack[MAX_COUNT_CALL_STASK_ADDR];
	StackBackTrace(MAX_COUNT_CALL_STASK_ADDR, CallStack);

	DUMP::WriteByteArray(&NtlvWriter, "CallStack", CallStack, sizeof(CallStack));

	// Получаем минидамп исполняемого кода в окружности точки падения.
	DUMP::WriteByteArray(&NtlvWriter, "MiniDump", 
		(PVOID)((PCHAR)ExceptionInfo->ExceptionRecord->ExceptionAddress - MINIDUMP_SIZE/2),
		MINIDUMP_SIZE);

	// Записываем список текущих процессов.
	AddProcessListToDump(&NtlvWriter);

	// Закрываем поток для вывода дампа.
	s.Finish(&s);
	
	// WARNING: 
	// Надо обязательно закрыть процесс, иначе он может войти в бесконечный 
	// цикл.
	pExitProcess(0);

	return EXCEPTION_CONTINUE_EXECUTION;
}

BOOLEAN InitialializeGlogalExceptionLogger(BOOLEAN IsLogAllException)
{
	LONG id = IsLogAllException?1:0;
	
	if ( AddVectoredExceptionHandler(id,ExceptionHandler) )	
			return TRUE;
	return FALSE;
}