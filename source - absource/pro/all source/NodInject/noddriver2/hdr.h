#define DWORD ULONG
#define PDWORD ULONG*
#define PWORD USHORT*
#define MAKE_PTR(Base, Offset, Type) ((Type)(DWORD(Base) + (DWORD)(Offset)))

typedef enum _SYSTEM_INFORMATION_CLASS {

	SystemBasicInformation, 
	SystemProcessorInformation, 
	SystemPerformanceInformation, 
	SystemTimeOfDayInformation, 
	SystemPathInformation, 
	SystemProcessInformation, 
	SystemCallCountInformation, 
	SystemDeviceInformation, 
	SystemProcessorPerformanceInformation, 
	SystemFlagsInformation, 
	SystemCallTimeInformation, 
	SystemModuleInformation, 
	SystemLocksInformation, 
	SystemStackTraceInformation, 
	SystemPagedPoolInformation, 
	SystemNonPagedPoolInformation, 
	SystemHandleInformation, SystemObjectInformation, SystemPageFileInformation, SystemVdmInstemulInformation, SystemVdmBopInformation, SystemFileCacheInformation, 
	SystemPoolTagInformation, SystemInterruptInformation, SystemDpcBehaviorInformation, SystemFullMemoryInformation, SystemLoadGdiDriverInformation, 
	SystemUnloadGdiDriverInformation, SystemTimeAdjustmentInformation, SystemSummaryMemoryInformation, SystemNextEventIdInformation, SystemEventIdsInformation, 
	SystemCrashDumpInformation, SystemExceptionInformation, SystemCrashDumpStateInformation, SystemKernelDebuggerInformation, SystemContextSwitchInformation, 
	SystemRegistryQuotaInformation, SystemExtendServiceTableInformation, SystemPrioritySeperation, SystemPlugPlayBusInformation, SystemDockInformation, 
	SystemPowerInformation1, SystemProcessorSpeedInformation, SystemCurrentTimeZoneInformation, SystemLookasideInformation

} SYSTEM_INFORMATION_CLASS, *PSYSTEM_INFORMATION_CLASS;


typedef struct _SYSTEM_THREAD {

	LARGE_INTEGER KernelTime; LARGE_INTEGER UserTime; LARGE_INTEGER CreateTime; 
	ULONG WaitTime; PVOID StartAddress; CLIENT_ID ClientId; KPRIORITY Priority; 
	LONG BasePriority; ULONG ContextSwitchCount; ULONG State; KWAIT_REASON WaitReason;

} SYSTEM_THREAD, *PSYSTEM_THREAD;

typedef struct _SYSTEM_PROCESS_INFORMATION {

	ULONG NextEntryOffset; ULONG NumberOfThreads; LARGE_INTEGER Reserved[3]; 
	LARGE_INTEGER CreateTime; LARGE_INTEGER UserTime; LARGE_INTEGER KernelTime; 
	UNICODE_STRING ImageName; KPRIORITY BasePriority; HANDLE ProcessId; 
	HANDLE InheritedFromProcessId; ULONG HandleCount; ULONG Reserved2[2]; 
	ULONG PrivatePageCount; VM_COUNTERS VirtualMemoryCounters; IO_COUNTERS IoCounters; SYSTEM_THREAD Threads[1];

} SYSTEM_PROCESS_INFORMATION, *PSYSTEM_PROCESS_INFORMATION;

extern "C" NTSTATUS NTAPI ZwQuerySystemInformation(
	  SYSTEM_INFORMATION_CLASS SystemInformationClass,
	  PVOID SystemInformation,
	   ULONG SystemInformationLength,
	 PULONG ReturnLength
	);

extern "C" NTSTATUS NTAPI KeInitializeApc(struct _KAPC *Apc, PKTHREAD thread,
	unsigned char state_index,
	PKKERNEL_ROUTINE ker_routine,
	PKRUNDOWN_ROUTINE rd_routine,
	PKNORMAL_ROUTINE nor_routine,
	unsigned char mode,
	void *context);

extern "C" NTSTATUS NTAPI KeInsertQueueApc(struct _KAPC *APC,
	void *SysArg1,
	void *SysArg2,
	unsigned char arg4);


extern "C" NTSTATUS NTAPI ZwQueryInformationProcess(
	 HANDLE ProcessHandle,
	 PROCESSINFOCLASS ProcessInformationClass,
	 PVOID ProcessInformation,
	 ULONG ProcessInformationLength,
	 PULONG ReturnLength
	);

#define WORD USHORT

typedef struct _IMAGE_DOS_HEADER
{
	WORD e_magic;
	WORD e_cblp;
	WORD e_cp;
	WORD e_crlc;
	WORD e_cparhdr;
	WORD e_minalloc;
	WORD e_maxalloc;
	WORD e_ss;
	WORD e_sp;
	WORD e_csum;
	WORD e_ip;
	WORD e_cs;
	WORD e_lfarlc;
	WORD e_ovno;
	WORD e_res[4];
	WORD e_oemid;
	WORD e_oeminfo;
	WORD e_res2[10];
	LONG e_lfanew;
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY {
	ULONG VirtualAddress;
	ULONG Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

#define DWORD ULONG

typedef struct _IMAGE_EXPORT_DIRECTORY 
{
	DWORD   Characteristics;
	DWORD   TimeDateStamp;
	WORD    MajorVersion;
	WORD    MinorVersion;
	DWORD   Name;
	DWORD   Base;
	DWORD   NumberOfFunctions;
	DWORD   NumberOfNames;
	DWORD   AddressOfFunctions;     
	DWORD   AddressOfNames;         
	DWORD   AddressOfNameOrdinals;  
} IMAGE_EXPORT_DIRECTORY, *PIMAGE_EXPORT_DIRECTORY;

#define IMAGE_DIRECTORY_ENTRY_EXPORT 0 

typedef struct _IMAGE_FILE_HEADER {
	WORD  Machine;
	WORD  NumberOfSections;
	DWORD TimeDateStamp;
	DWORD PointerToSymbolTable;
	DWORD NumberOfSymbols;
	WORD  SizeOfOptionalHeader;
	WORD  Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

#define BYTE	CHAR

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

typedef struct _IMAGE_OPTIONAL_HEADER {
	WORD                 Magic;
	BYTE                 MajorLinkerVersion;
	BYTE                 MinorLinkerVersion;
	DWORD                SizeOfCode;
	DWORD                SizeOfInitializedData;
	DWORD                SizeOfUninitializedData;
	DWORD                AddressOfEntryPoint;
	DWORD                BaseOfCode;
	DWORD                BaseOfData;
	DWORD                ImageBase;
	DWORD                SectionAlignment;
	DWORD                FileAlignment;
	WORD                 MajorOperatingSystemVersion;
	WORD                 MinorOperatingSystemVersion;
	WORD                 MajorImageVersion;
	WORD                 MinorImageVersion;
	WORD                 MajorSubsystemVersion;
	WORD                 MinorSubsystemVersion;
	DWORD                Win32VersionValue;
	DWORD                SizeOfImage;
	DWORD                SizeOfHeaders;
	DWORD                CheckSum;
	WORD                 Subsystem;
	WORD                 DllCharacteristics;
	DWORD                SizeOfStackReserve;
	DWORD                SizeOfStackCommit;
	DWORD                SizeOfHeapReserve;
	DWORD                SizeOfHeapCommit;
	DWORD                LoaderFlags;
	DWORD                NumberOfRvaAndSizes;
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER, *PIMAGE_OPTIONAL_HEADER;

typedef struct _IMAGE_NT_HEADERS {
	DWORD                 Signature;
	IMAGE_FILE_HEADER     FileHeader;
	IMAGE_OPTIONAL_HEADER OptionalHeader;
} IMAGE_NT_HEADERS, *PIMAGE_NT_HEADERS;

typedef struct _LDR_DATA_TABLE_ENTRY
{
	LIST_ENTRY InLoadOrderLinks;
	LIST_ENTRY InMemoryOrderLinks;
	LIST_ENTRY InInitializationOrderLinks;
	PVOID DllBase;
	PVOID EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	ULONG Flags;
	WORD LoadCount;
	WORD TlsIndex;
	union
	{
		LIST_ENTRY HashLinks;
		struct
		{
			PVOID SectionPointer;
			ULONG CheckSum;
		};
	};
	union
	{
		ULONG TimeDateStamp;
		PVOID LoadedImports;
	};
	PVOID * EntryPointActivationContext;
	PVOID PatchInformation;
	LIST_ENTRY ForwarderLinks;
	LIST_ENTRY ServiceTagLinks;
	LIST_ENTRY StaticLinks;
} LDR_DATA_TABLE_ENTRY, *PLDR_DATA_TABLE_ENTRY;

typedef struct _PEB_LDR_DATA {

	ULONG Length; BOOLEAN Initialized; PVOID SsHandle; 
	LIST_ENTRY InLoadOrderModuleList; 
	LIST_ENTRY InMemoryOrderModuleList; 
	LIST_ENTRY InInitializationOrderModuleList;

} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct _PEB {

	BOOLEAN InheritedAddressSpace; BOOLEAN ReadImageFileExecOptions; BOOLEAN BeingDebugged; BOOLEAN Spare; HANDLE Mutant; PVOID ImageBaseAddress; 
	PPEB_LDR_DATA LoaderData; 
	PVOID ProcessParameters; PVOID SubSystemData; PVOID ProcessHeap; PVOID FastPebLock; 
	PVOID FastPebLockRoutine; PVOID FastPebUnlockRoutine; ULONG EnvironmentUpdateCount; 
	PVOID *KernelCallbackTable; PVOID EventLogSection; PVOID EventLog; PVOID FreeList; ULONG TlsExpansionCounter; PVOID TlsBitmap; 
	ULONG TlsBitmapBits[0x2]; PVOID ReadOnlySharedMemoryBase; PVOID ReadOnlySharedMemoryHeap; PVOID* ReadOnlyStaticServerData; PVOID AnsiCodePageData; 
	PVOID OemCodePageData; PVOID UnicodeCaseTableData; ULONG NumberOfProcessors; ULONG NtGlobalFlag; BYTE Spare2[0x4]; LARGE_INTEGER CriticalSectionTimeout;
	ULONG HeapSegmentReserve; ULONG HeapSegmentCommit; ULONG HeapDeCommitTotalFreeThreshold; ULONG HeapDeCommitFreeBlockThreshold; ULONG NumberOfHeaps; 
	ULONG MaximumNumberOfHeaps; PVOID **ProcessHeaps; PVOID GdiSharedHandleTable; PVOID ProcessStarterHelper; PVOID GdiDCAttributeList; PVOID LoaderLock; 
	ULONG OSMajorVersion; ULONG OSMinorVersion; ULONG OSBuildNumber; ULONG OSPlatformId; ULONG ImageSubSystem; ULONG ImageSubSystemMajorVersion; 
	ULONG ImageSubSystemMinorVersion; ULONG GdiHandleBuffer[0x22]; ULONG PostProcessInitRoutine; ULONG TlsExpansionBitmap; BYTE TlsExpansionBitmapBits[0x80]; ULONG SessionId;

} PEB, *PPEB;
