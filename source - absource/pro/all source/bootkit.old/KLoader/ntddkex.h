#pragma once


#ifndef BOOL
 #define BOOL ULONG
#endif


#define	BYTE	UCHAR
#define	WORD	USHORT
#define	DWORD	ULONG


// timer period macros
#define _RELATIVE(x)		-(x)
#define _SECONDS(x)			(LONGLONG)x*10000000
#define _MILLISECONDS(x)	(LONGLONG)x*10000
#define _MINUTES(x)			(LONGLONG)x*600000000


#define DLL_PROCESS_ATTACH   1    
#define DLL_THREAD_ATTACH    2    
#define DLL_THREAD_DETACH    3    
#define DLL_PROCESS_DETACH   0    
#define DLL_PROCESS_VERIFIER 4   


#define IMAGE_DOS_SIGNATURE                 0x5A4D      // MZ
#define IMAGE_OS2_SIGNATURE                 0x454E      // NE
#define IMAGE_OS2_SIGNATURE_LE              0x454C      // LE
#define IMAGE_VXD_SIGNATURE                 0x454C      // LE
#define IMAGE_NT_SIGNATURE                  0x00004550  // PE00

typedef struct _IMAGE_DOS_HEADER {      // DOS .EXE header
    WORD   e_magic;                     // Magic number
    WORD   e_cblp;                      // Bytes on last page of file
    WORD   e_cp;                        // Pages in file
    WORD   e_crlc;                      // Relocations
    WORD   e_cparhdr;                   // Size of header in paragraphs
    WORD   e_minalloc;                  // Minimum extra paragraphs needed
    WORD   e_maxalloc;                  // Maximum extra paragraphs needed
    WORD   e_ss;                        // Initial (relative) SS value
    WORD   e_sp;                        // Initial SP value
    WORD   e_csum;                      // Checksum
    WORD   e_ip;                        // Initial IP value
    WORD   e_cs;                        // Initial (relative) CS value
    WORD   e_lfarlc;                    // File address of relocation table
    WORD   e_ovno;                      // Overlay number
    WORD   e_res[4];                    // Reserved words
    WORD   e_oemid;                     // OEM identifier (for e_oeminfo)
    WORD   e_oeminfo;                   // OEM information; e_oemid specific
    WORD   e_res2[10];                  // Reserved words
    LONG   e_lfanew;                    // File address of new exe header
  } IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;


//
// File header format.
//

typedef struct _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    NumberOfSections;
    DWORD   TimeDateStamp;
    DWORD   PointerToSymbolTable;
    DWORD   NumberOfSymbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

#define IMAGE_SIZEOF_FILE_HEADER             20


#define IMAGE_FILE_RELOCS_STRIPPED           0x0001  // Relocation info stripped from file.
#define IMAGE_FILE_EXECUTABLE_IMAGE          0x0002  // File is executable  (i.e. no unresolved externel references).
#define IMAGE_FILE_LINE_NUMS_STRIPPED        0x0004  // Line nunbers stripped from file.
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED       0x0008  // Local symbols stripped from file.
#define IMAGE_FILE_AGGRESIVE_WS_TRIM         0x0010  // Agressively trim working set
#define IMAGE_FILE_LARGE_ADDRESS_AWARE       0x0020  // App can handle >2gb addresses
#define IMAGE_FILE_BYTES_REVERSED_LO         0x0080  // Bytes of machine word are reversed.
#define IMAGE_FILE_32BIT_MACHINE             0x0100  // 32 bit word machine.
#define IMAGE_FILE_DEBUG_STRIPPED            0x0200  // Debugging info stripped from file in .DBG file
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP   0x0400  // If Image is on removable media, copy and run from the swap file.
#define IMAGE_FILE_NET_RUN_FROM_SWAP         0x0800  // If Image is on Net, copy and run from the swap file.
#define IMAGE_FILE_SYSTEM                    0x1000  // System File.
#define IMAGE_FILE_DLL                       0x2000  // File is a DLL.
#define IMAGE_FILE_UP_SYSTEM_ONLY            0x4000  // File should only be run on a UP machine
#define IMAGE_FILE_BYTES_REVERSED_HI         0x8000  // Bytes of machine word are reversed.

#define IMAGE_FILE_MACHINE_UNKNOWN           0
#define IMAGE_FILE_MACHINE_I386              0x014c  // Intel 386.
#define IMAGE_FILE_MACHINE_R3000             0x0162  // MIPS little-endian, 0x160 big-endian
#define IMAGE_FILE_MACHINE_R4000             0x0166  // MIPS little-endian
#define IMAGE_FILE_MACHINE_R10000            0x0168  // MIPS little-endian
#define IMAGE_FILE_MACHINE_WCEMIPSV2         0x0169  // MIPS little-endian WCE v2
#define IMAGE_FILE_MACHINE_ALPHA             0x0184  // Alpha_AXP
#define IMAGE_FILE_MACHINE_SH3               0x01a2  // SH3 little-endian
#define IMAGE_FILE_MACHINE_SH3DSP            0x01a3
#define IMAGE_FILE_MACHINE_SH3E              0x01a4  // SH3E little-endian
#define IMAGE_FILE_MACHINE_SH4               0x01a6  // SH4 little-endian
#define IMAGE_FILE_MACHINE_SH5               0x01a8  // SH5
#define IMAGE_FILE_MACHINE_ARM               0x01c0  // ARM Little-Endian
#define IMAGE_FILE_MACHINE_THUMB             0x01c2
#define IMAGE_FILE_MACHINE_AM33              0x01d3
#define IMAGE_FILE_MACHINE_POWERPC           0x01F0  // IBM PowerPC Little-Endian
#define IMAGE_FILE_MACHINE_POWERPCFP         0x01f1
#define IMAGE_FILE_MACHINE_IA64              0x0200  // Intel 64
#define IMAGE_FILE_MACHINE_MIPS16            0x0266  // MIPS
#define IMAGE_FILE_MACHINE_ALPHA64           0x0284  // ALPHA64
#define IMAGE_FILE_MACHINE_MIPSFPU           0x0366  // MIPS
#define IMAGE_FILE_MACHINE_MIPSFPU16         0x0466  // MIPS
#define IMAGE_FILE_MACHINE_AXP64             IMAGE_FILE_MACHINE_ALPHA64
#define IMAGE_FILE_MACHINE_TRICORE           0x0520  // Infineon
#define IMAGE_FILE_MACHINE_CEF               0x0CEF
#define IMAGE_FILE_MACHINE_EBC               0x0EBC  // EFI Byte Code
#define IMAGE_FILE_MACHINE_AMD64             0x8664  // AMD64 (K8)
#define IMAGE_FILE_MACHINE_M32R              0x9041  // M32R little-endian
#define IMAGE_FILE_MACHINE_CEE               0xC0EE

//
// Directory format.
//

typedef struct _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES    16

//
// Optional header format.
//

typedef struct _IMAGE_OPTIONAL_HEADER {
    //
    // Standard fields.
    //

    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
    DWORD   BaseOfData;

    //
    // NT additional fields.
    //

    DWORD   ImageBase;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    WORD    MajorOperatingSystemVersion;
    WORD    MinorOperatingSystemVersion;
    WORD    MajorImageVersion;
    WORD    MinorImageVersion;
    WORD    MajorSubsystemVersion;
    WORD    MinorSubsystemVersion;
    DWORD   Win32VersionValue;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    DWORD   SizeOfStackReserve;
    DWORD   SizeOfStackCommit;
    DWORD   SizeOfHeapReserve;
    DWORD   SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;


typedef struct _IMAGE_OPTIONAL_HEADER64 {
    WORD        Magic;
    BYTE        MajorLinkerVersion;
    BYTE        MinorLinkerVersion;
    DWORD       SizeOfCode;
    DWORD       SizeOfInitializedData;
    DWORD       SizeOfUninitializedData;
    DWORD       AddressOfEntryPoint;
    DWORD       BaseOfCode;
    ULONGLONG   ImageBase;
    DWORD       SectionAlignment;
    DWORD       FileAlignment;
    WORD        MajorOperatingSystemVersion;
    WORD        MinorOperatingSystemVersion;
    WORD        MajorImageVersion;
    WORD        MinorImageVersion;
    WORD        MajorSubsystemVersion;
    WORD        MinorSubsystemVersion;
    DWORD       Win32VersionValue;
    DWORD       SizeOfImage;
    DWORD       SizeOfHeaders;
    DWORD       CheckSum;
    WORD        Subsystem;
    WORD        DllCharacteristics;
    ULONGLONG   SizeOfStackReserve;
    ULONGLONG   SizeOfStackCommit;
    ULONGLONG   SizeOfHeapReserve;
    ULONGLONG   SizeOfHeapCommit;
    DWORD       LoaderFlags;
    DWORD       NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;

#define IMAGE_SIZEOF_ROM_OPTIONAL_HEADER      56
#define IMAGE_SIZEOF_STD_OPTIONAL_HEADER      28
#define IMAGE_SIZEOF_NT_OPTIONAL32_HEADER    224
#define IMAGE_SIZEOF_NT_OPTIONAL64_HEADER    240

#define IMAGE_NT_OPTIONAL_HDR32_MAGIC      0x10b
#define IMAGE_NT_OPTIONAL_HDR64_MAGIC      0x20b
#define IMAGE_ROM_OPTIONAL_HDR_MAGIC       0x107

#ifdef _WIN64
typedef IMAGE_OPTIONAL_HEADER64             IMAGE_OPTIONAL_HEADER;
typedef PIMAGE_OPTIONAL_HEADER64            PIMAGE_OPTIONAL_HEADER;
#define IMAGE_SIZEOF_NT_OPTIONAL_HEADER     IMAGE_SIZEOF_NT_OPTIONAL64_HEADER
#define IMAGE_NT_OPTIONAL_HDR_MAGIC         IMAGE_NT_OPTIONAL_HDR64_MAGIC
#else
typedef IMAGE_OPTIONAL_HEADER32             IMAGE_OPTIONAL_HEADER;
typedef PIMAGE_OPTIONAL_HEADER32            PIMAGE_OPTIONAL_HEADER;
#define IMAGE_SIZEOF_NT_OPTIONAL_HEADER     IMAGE_SIZEOF_NT_OPTIONAL32_HEADER
#define IMAGE_NT_OPTIONAL_HDR_MAGIC         IMAGE_NT_OPTIONAL_HDR32_MAGIC
#endif

typedef struct _IMAGE_NT_HEADERS64 {
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;

typedef struct _IMAGE_NT_HEADERS {
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
} IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

#ifdef _WIN64
typedef IMAGE_NT_HEADERS64                  IMAGE_NT_HEADERS;
typedef PIMAGE_NT_HEADERS64                 PIMAGE_NT_HEADERS;
#else
typedef IMAGE_NT_HEADERS32                  IMAGE_NT_HEADERS;
typedef PIMAGE_NT_HEADERS32                 PIMAGE_NT_HEADERS;
#endif


//
// Section header format.
//

#define IMAGE_SIZEOF_SHORT_NAME              8

typedef struct _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    union {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    NumberOfRelocations;
    WORD    NumberOfLinenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER          40

//
// Section characteristics.
//
//      IMAGE_SCN_TYPE_REG                   0x00000000  // Reserved.
//      IMAGE_SCN_TYPE_DSECT                 0x00000001  // Reserved.
//      IMAGE_SCN_TYPE_NOLOAD                0x00000002  // Reserved.
//      IMAGE_SCN_TYPE_GROUP                 0x00000004  // Reserved.
#define IMAGE_SCN_TYPE_NO_PAD                0x00000008  // Reserved.
//      IMAGE_SCN_TYPE_COPY                  0x00000010  // Reserved.

#define IMAGE_SCN_CNT_CODE                   0x00000020  // Section contains code.
#define IMAGE_SCN_CNT_INITIALIZED_DATA       0x00000040  // Section contains initialized data.
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA     0x00000080  // Section contains uninitialized data.

#define IMAGE_SCN_LNK_OTHER                  0x00000100  // Reserved.
#define IMAGE_SCN_LNK_INFO                   0x00000200  // Section contains comments or some other type of information.
//      IMAGE_SCN_TYPE_OVER                  0x00000400  // Reserved.
#define IMAGE_SCN_LNK_REMOVE                 0x00000800  // Section contents will not become part of image.
#define IMAGE_SCN_LNK_COMDAT                 0x00001000  // Section contents comdat.
//                                           0x00002000  // Reserved.
//      IMAGE_SCN_MEM_PROTECTED - Obsolete   0x00004000
#define IMAGE_SCN_NO_DEFER_SPEC_EXC          0x00004000  // Reset speculative exceptions handling bits in the TLB entries for this section.
#define IMAGE_SCN_GPREL                      0x00008000  // Section content can be accessed relative to GP
#define IMAGE_SCN_MEM_FARDATA                0x00008000
//      IMAGE_SCN_MEM_SYSHEAP  - Obsolete    0x00010000
#define IMAGE_SCN_MEM_PURGEABLE              0x00020000
#define IMAGE_SCN_MEM_16BIT                  0x00020000
#define IMAGE_SCN_MEM_LOCKED                 0x00040000
#define IMAGE_SCN_MEM_PRELOAD                0x00080000

#define IMAGE_SCN_ALIGN_1BYTES               0x00100000  //
#define IMAGE_SCN_ALIGN_2BYTES               0x00200000  //
#define IMAGE_SCN_ALIGN_4BYTES               0x00300000  //
#define IMAGE_SCN_ALIGN_8BYTES               0x00400000  //
#define IMAGE_SCN_ALIGN_16BYTES              0x00500000  // Default alignment if no others are specified.
#define IMAGE_SCN_ALIGN_32BYTES              0x00600000  //
#define IMAGE_SCN_ALIGN_64BYTES              0x00700000  //
#define IMAGE_SCN_ALIGN_128BYTES             0x00800000  //
#define IMAGE_SCN_ALIGN_256BYTES             0x00900000  //
#define IMAGE_SCN_ALIGN_512BYTES             0x00A00000  //
#define IMAGE_SCN_ALIGN_1024BYTES            0x00B00000  //
#define IMAGE_SCN_ALIGN_2048BYTES            0x00C00000  //
#define IMAGE_SCN_ALIGN_4096BYTES            0x00D00000  //
#define IMAGE_SCN_ALIGN_8192BYTES            0x00E00000  //
// Unused                                    0x00F00000
#define IMAGE_SCN_ALIGN_MASK                 0x00F00000

#define IMAGE_SCN_LNK_NRELOC_OVFL            0x01000000  // Section contains extended relocations.
#define IMAGE_SCN_MEM_DISCARDABLE            0x02000000  // Section can be discarded.
#define IMAGE_SCN_MEM_NOT_CACHED             0x04000000  // Section is not cachable.
#define IMAGE_SCN_MEM_NOT_PAGED              0x08000000  // Section is not pageable.
#define IMAGE_SCN_MEM_SHARED                 0x10000000  // Section is shareable.
#define IMAGE_SCN_MEM_EXECUTE                0x20000000  // Section is executable.
#define IMAGE_SCN_MEM_READ                   0x40000000  // Section is readable.
#define IMAGE_SCN_MEM_WRITE                  0x80000000  // Section is writeable.




// IMAGE_FIRST_SECTION doesn't need 32/64 versions since the file header is the same either way.

#define IMAGE_FIRST_SECTION( ntheader ) ((PIMAGE_SECTION_HEADER)        \
    ((ULONG_PTR)ntheader +                                              \
     FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +                 \
     ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.SizeOfOptionalHeader   \
    ))

// Subsystem Values

#define IMAGE_SUBSYSTEM_UNKNOWN              0   // Unknown subsystem.
#define IMAGE_SUBSYSTEM_NATIVE               1   // Image doesn't require a subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_GUI          2   // Image runs in the Windows GUI subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_CUI          3   // Image runs in the Windows character subsystem.
#define IMAGE_SUBSYSTEM_OS2_CUI              5   // image runs in the OS/2 character subsystem.
#define IMAGE_SUBSYSTEM_POSIX_CUI            7   // image runs in the Posix character subsystem.
#define IMAGE_SUBSYSTEM_NATIVE_WINDOWS       8   // image is a native Win9x driver.
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI       9   // Image runs in the Windows CE subsystem.
#define IMAGE_SUBSYSTEM_EFI_APPLICATION      10  //
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  11   //
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER   12  //
#define IMAGE_SUBSYSTEM_EFI_ROM              13
#define IMAGE_SUBSYSTEM_XBOX                 14

// DllCharacteristics Entries

//      IMAGE_LIBRARY_PROCESS_INIT           0x0001     // Reserved.
//      IMAGE_LIBRARY_PROCESS_TERM           0x0002     // Reserved.
//      IMAGE_LIBRARY_THREAD_INIT            0x0004     // Reserved.
//      IMAGE_LIBRARY_THREAD_TERM            0x0008     // Reserved.
#define IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200    // Image understands isolation and doesn't want it
#define IMAGE_DLLCHARACTERISTICS_NO_SEH      0x0400     // Image does not use SEH.  No SE handler may reside in this image
#define IMAGE_DLLCHARACTERISTICS_NO_BIND     0x0800     // Do not bind this image.
//                                           0x1000     // Reserved.
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER  0x2000     // Driver uses WDM model
//                                           0x4000     // Reserved.
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE     0x8000

// Directory Entries

#define IMAGE_DIRECTORY_ENTRY_EXPORT          0   // Export Directory
#define IMAGE_DIRECTORY_ENTRY_IMPORT          1   // Import Directory
#define IMAGE_DIRECTORY_ENTRY_RESOURCE        2   // Resource Directory
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION       3   // Exception Directory
#define IMAGE_DIRECTORY_ENTRY_SECURITY        4   // Security Directory
#define IMAGE_DIRECTORY_ENTRY_BASERELOC       5   // Base Relocation Table
#define IMAGE_DIRECTORY_ENTRY_DEBUG           6   // Debug Directory
//      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7   // (X86 usage)
#define IMAGE_DIRECTORY_ENTRY_ARCHITECTURE    7   // Architecture Specific Data
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR       8   // RVA of GP
#define IMAGE_DIRECTORY_ENTRY_TLS             9   // TLS Directory
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    10   // Load Configuration Directory
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   11   // Bound Import Directory in headers
#define IMAGE_DIRECTORY_ENTRY_IAT            12   // Import Address Table
#define IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   13   // Delay Load Import Descriptors
#define IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14   // COM Runtime descriptor



//
// Based relocation format.
//

typedef struct _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
	WORD    TypeOffset[0];
} IMAGE_BASE_RELOCATION, *PIMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION         8

//
// Based relocation types.
//

#define IMAGE_REL_BASED_ABSOLUTE              0
#define IMAGE_REL_BASED_HIGH                  1
#define IMAGE_REL_BASED_LOW                   2
#define IMAGE_REL_BASED_HIGHLOW               3
#define IMAGE_REL_BASED_HIGHADJ               4
#define IMAGE_REL_BASED_MIPS_JMPADDR          5
#define IMAGE_REL_BASED_MIPS_JMPADDR16        9
#define IMAGE_REL_BASED_IA64_IMM64            9
#define IMAGE_REL_BASED_DIR64                 10

#define	IMAGE_REL_BASED_MASK				0x0fff
#define	IMAGE_REL_BASED_SHIFT				12



typedef struct _IMAGE_IMPORT_DESCRIPTOR {
    union {
        DWORD   Characteristics;            // 0 for terminating null import descriptor
        DWORD   OriginalFirstThunk;         // RVA to original unbound IAT (PIMAGE_THUNK_DATA)
    };
    DWORD   TimeDateStamp;                  // 0 if not bound,
                                            // -1 if bound, and real date\time stamp
                                            //     in IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT (new BIND)
                                            // O.W. date/time stamp of DLL bound to (Old BIND)

    DWORD   ForwarderChain;                 // -1 if no forwarders
    DWORD   Name;
    DWORD   FirstThunk;                     // RVA to IAT (if bound this IAT has actual addresses)
} IMAGE_IMPORT_DESCRIPTOR;
typedef IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

//
// Import Format
//

typedef struct _IMAGE_IMPORT_BY_NAME {
    WORD    Hint;
    BYTE    Name[1];
} IMAGE_IMPORT_BY_NAME, *PIMAGE_IMPORT_BY_NAME;

typedef struct _IMAGE_THUNK_DATA64 {
    union {
        ULONGLONG ForwarderString;  // PBYTE 
        ULONGLONG Function;         // PDWORD
        ULONGLONG Ordinal;
        ULONGLONG AddressOfData;    // PIMAGE_IMPORT_BY_NAME
    } u1;
} IMAGE_THUNK_DATA64;
typedef IMAGE_THUNK_DATA64 * PIMAGE_THUNK_DATA64;


typedef struct _IMAGE_THUNK_DATA32 {
    union {
        DWORD ForwarderString;      // PBYTE 
        DWORD Function;             // PDWORD
        DWORD Ordinal;
        DWORD AddressOfData;        // PIMAGE_IMPORT_BY_NAME
    } u1;
} IMAGE_THUNK_DATA32;
typedef IMAGE_THUNK_DATA32 * PIMAGE_THUNK_DATA32;

#define IMAGE_ORDINAL_FLAG64 0x8000000000000000
#define IMAGE_ORDINAL_FLAG32 0x80000000
#define IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffff)
#define IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#define IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64) != 0)
#define IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32) != 0)


#ifdef _WIN64
#define IMAGE_ORDINAL_FLAG              IMAGE_ORDINAL_FLAG64
#define IMAGE_ORDINAL(Ordinal)          IMAGE_ORDINAL64(Ordinal)
typedef IMAGE_THUNK_DATA64              IMAGE_THUNK_DATA;
typedef PIMAGE_THUNK_DATA64             PIMAGE_THUNK_DATA;
#define IMAGE_SNAP_BY_ORDINAL(Ordinal)  IMAGE_SNAP_BY_ORDINAL64(Ordinal)
//typedef IMAGE_TLS_DIRECTORY64           IMAGE_TLS_DIRECTORY;
//typedef PIMAGE_TLS_DIRECTORY64          PIMAGE_TLS_DIRECTORY;
#else
#define IMAGE_ORDINAL_FLAG              IMAGE_ORDINAL_FLAG32
#define IMAGE_ORDINAL(Ordinal)          IMAGE_ORDINAL32(Ordinal)
typedef IMAGE_THUNK_DATA32              IMAGE_THUNK_DATA;
typedef PIMAGE_THUNK_DATA32             PIMAGE_THUNK_DATA;
#define IMAGE_SNAP_BY_ORDINAL(Ordinal)  IMAGE_SNAP_BY_ORDINAL32(Ordinal)
//typedef IMAGE_TLS_DIRECTORY32           IMAGE_TLS_DIRECTORY;
//typedef PIMAGE_TLS_DIRECTORY32          PIMAGE_TLS_DIRECTORY;
#endif



// Kernel APC environment constants
typedef enum _KAPC_ENVIRONMENT {
    OriginalApcEnvironment,
    AttachedApcEnvironment,
    CurrentApcEnvironment,
    InsertApcEnvironment
} KAPC_ENVIRONMENT;



#define SEC_FILE			0x800000     
#define SEC_IMAGE			0x1000000     
#define SEC_RESERVE			0x4000000     
#define SEC_COMMIT			0x8000000     
#define SEC_NOCACHE			0x10000000     
#define SEC_LARGE_PAGES		0x80000000     



// ---- System information -----------------------------------------------------------------------------------------------

typedef enum _SYSTEM_INFORMATION_CLASS {
    SystemBasicInformation,
    SystemProcessorInformation,
    SystemPerformanceInformation,
    SystemTimeOfDayInformation,
    SystemNotImplemented1,
    SystemProcessesAndThreadsInformation,
    SystemCallCounts,
    SystemConfigurationInformation,
    SystemProcessorPerformanceInformation,
    SystemGlobalFlag,
    SystemNotImplemented2,						// 10
    SystemModuleInformation,
    SystemLockInformation,
    SystemNotImplemented3,
    SystemNotImplemented4,
    SystemNotImplemented5,
    SystemHandleInformation,
    SystemObjectInformation,
    SystemPagefileInformation,
    SystemInstructionEmulationCounts,
    SystemInvalidInfoClass1,					// 20
    SystemCacheInformation,
    SystemPoolTagInformation,
    SystemInterruptInformation,
    SystemDpcInformation,
    SystemNotImplemented6,
    SystemLoadImage,
    SystemUnloadImage,
    SystemTimeAdjustment,
    SystemNotImplemented7,
    SystemNotImplemented8,						// 30
    SystemNotImplemented9,
    SystemCrashDumpInformation,
    SystemExceptionInformation,
    SystemCrashDumpStateInformation,
    SystemKernelDebuggerInformation,
    SystemContextSwitchInformation,
    SystemRegistryQuotaInformation,
    SystemExtendServiceTableInformation,
    SystemPrioritySeparation,
    SystemNotImplemented10,						// 40
    SystemNotImplemented11,
    SystemProcessorIdleInformation,
    SystemInvalidInfoClass3,
    SystemTimeZoneInformation,
    SystemLookasideInformation,
    SystemSetTimeSlipEvent,
    SystemCreateSession,
    SystemDeleteSession,
    SystemInvalidInfoClass4,
    SystemRangeStartInformation,				// 50
    SystemVerifierInformation,
    SystemAddVerifier,
    SystemSessionProcessesInformation,
	SystemLoadImageInSystemSpace,
	SystemNumaProcessorMap,					
    SystemPrefetcherInformation,
    SystemExtendedProcessInformation,
    SystemRecommendedSharedDataAlignment,
    SystemComPlusPackage,
    SystemNumaAvailableMemory,					// 60
    SystemProcessorPowerInformation,
    SystemEmulationBasicInformation,
    SystemEmulationProcessorInformation,
    SystemExtendedHandleInformation,
    SystemLostDelayedWriteInformation,
    SystemBigPoolInformation,
    SystemSessionPoolTagInformation,
    SystemSessionMappedViewInformation,
    SystemHotpatchInformation,
    SystemObjectSecurityMode,					// 70
    SystemWatchdogTimerHandler,
    SystemWatchdogTimerInformation,
    SystemLogicalProcessorInformation,

	//w2k8
	SystemWow64SharedInformation,
	SystemRegisterFirmwareTableInformationHandler,
	SystemFirmwareTableInformation,
	SystemModuleInformationEx,
	SystemVerifierTriageInformation,		
	SystemSuperfetchInformation,
	SystemMemoryListInformation,				// 80
	SystemFileCacheInformationEx,
    SystemNotImplemented19,
    SystemProcessorDebugInformation,
    SystemVerifierInformation2,
    SystemNotImplemented20,
    SystemRefTraceInformation,
    SystemSpecialPoolTag, 
    SystemProcessImageName,
    SystemNotImplemented21,
    SystemBootEnvironmentInformation,			// 90
    SystemEnlightenmentInformation,
    SystemVerifierInformationEx,
	SystemSetTimeZoneInformation,
    SystemNotImplemented23,
    SystemCovInformation,
	SystemNotImplemented24,
    SystemNotImplemented25,
    SystemPartitionInformation,
    SystemSystemDiskInformation,
    SystemPerformanceDistributionInformation,	// 100
    SystemNumaProximityNodeInformation,
    SystemDynamicTimeZoneInformation,
    SystemCodeIntegrityInformation,
    SystemNotImplemented26,
    SystemUnknownInformation,
    SystemVaInformation,
	SystemLogicalProcessorAndGroupInformation,
	SystemLogicalGroupInformation,
	SystemStoreInformation,						// 109

	SystemVhdBootInformation = 112,
	SystemCpuQuotaInformation, 
	
	SystemHardwareCountersInformation = 115,	// Removed in build 7100, uses KeQueryHardwareCounterConfiguration() instead
	SystemLowPriorityInformation,
	SystemTpmBootEntropyInformation,
	SystemVerifierInformation3, 

	// NtQueryEx
	SystemNumaNodesInformation = 121,
	SystemHalInformation,						// 8 bytes size
	SystemCommittedMemoryInformation,
	MaxSystemInfoClass
} SYSTEM_INFORMATION_CLASS;

#define	MAX_SYSTEM_MODULE_NAME_LENGTH	256		// bytes

typedef struct _SYSTEM_MODULE
{
    ULONG_PTR	Reserved[2];
    ULONG_PTR	Base;
    ULONG		Size;
    ULONG		Flags;
    USHORT		Index;
    USHORT		Unknown;
    USHORT		LoadCount;
    USHORT		ModuleNameOffset;
    CHAR		ImageName[MAX_SYSTEM_MODULE_NAME_LENGTH];
} SYSTEM_MODULE, *PSYSTEM_MODULE;

typedef struct _SYSTEM_MODULE_INFORMATION
{
	ULONG			uCount;
	SYSTEM_MODULE	aSM[];
} SYSTEM_MODULE_INFORMATION, *PSYSTEM_MODULE_INFORMATION;

typedef struct _SYSTEM_PROCESS {
    ULONG NextEntryOffset;
    ULONG NumberOfThreads;
    LARGE_INTEGER SpareLi1;
    LARGE_INTEGER SpareLi2;
    LARGE_INTEGER SpareLi3;
    LARGE_INTEGER CreateTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER KernelTime;
    UNICODE_STRING ImageName;
    KPRIORITY BasePriority;
    HANDLE UniqueProcessId;
    HANDLE InheritedFromUniqueProcessId;
    ULONG HandleCount;
    ULONG SessionId;
    ULONG_PTR PageDirectoryBase;
    SIZE_T PeakVirtualSize;
    SIZE_T VirtualSize;
    ULONG PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
    SIZE_T PrivatePageCount;
    LARGE_INTEGER ReadOperationCount;
    LARGE_INTEGER WriteOperationCount;
    LARGE_INTEGER OtherOperationCount;
    LARGE_INTEGER ReadTransferCount;
    LARGE_INTEGER WriteTransferCount;
    LARGE_INTEGER OtherTransferCount;
} SYSTEM_PROCESS, *PSYSTEM_PROCESS;


__declspec(dllimport) 
NTSTATUS _stdcall ZwQuerySystemInformation(
  __in       SYSTEM_INFORMATION_CLASS SystemInformationClass,
  __inout    PVOID SystemInformation,
  __in       ULONG SystemInformationLength,
  __out_opt  PULONG ReturnLength
);



__declspec(dllimport) 
NTSTATUS _stdcall ZwOpenProcess(
  __out     PHANDLE ProcessHandle,
  __in      ACCESS_MASK DesiredAccess,
  __in      POBJECT_ATTRIBUTES ObjectAttributes,
  __in_opt  PCLIENT_ID ClientId
);

__declspec(dllimport)
NTSTATUS _stdcall ZwQueryInformationProcess(
  __in       HANDLE ProcessHandle,
  __in       PROCESSINFOCLASS ProcessInformationClass,
  __out      PVOID ProcessInformation,
  __in       ULONG ProcessInformationLength,
  __out_opt  PULONG ReturnLength
);

__declspec(dllimport)
NTSTATUS _stdcall ZwAllocateVirtualMemory(
  __in     HANDLE ProcessHandle,
  __inout  PVOID *BaseAddress,
  __in     ULONG_PTR ZeroBits,
  __inout  PSIZE_T RegionSize,
  __in     ULONG AllocationType,
  __in     ULONG Protect
);


__declspec(dllimport)
// Not exported by nt kernel
NTSTATUS _stdcall ZwProtectVirtualMemory(
  __in		HANDLE ProcessHandle, 
  __inout	PVOID *BaseAddress, 
  __inout	PULONG NumberOfBytesToProtect, 
  __in		ULONG NewAccessProtection, 
  __out		PULONG OldAccessProtection 
); 

__declspec(dllimport)
VOID _stdcall KeInitializeApc (
    __out PRKAPC Apc,
    __in PRKTHREAD Thread,
    __in KAPC_ENVIRONMENT Environment,
    __in PKKERNEL_ROUTINE KernelRoutine,
    __in_opt PKRUNDOWN_ROUTINE RundownRoutine,
    __in_opt PKNORMAL_ROUTINE NormalRoutine,
    __in_opt KPROCESSOR_MODE ProcessorMode,
    __in_opt PVOID NormalContext
);

__declspec(dllimport)
BOOLEAN	_stdcall KeInsertQueueApc (
    __inout PRKAPC Apc,
    __in_opt PVOID SystemArgument1,
    __in_opt PVOID SystemArgument2,
    __in KPRIORITY Increment
);

__declspec(dllimport)
NTSTATUS _stdcall LdrRelocateImage (
	__in PVOID	NewBase, 
	__in PUCHAR LoaderName, 
	__in NTSTATUS Success, 
	__in NTSTATUS Conflict, 
	__in NTSTATUS Invalid
);


__declspec(dllimport)
NTSTATUS IoQueryFileDosDeviceName(
  __in   PFILE_OBJECT FileObject,
  __out  PUNICODE_STRING *ObjectNameInformation
);

__declspec(dllimport)
PEPROCESS IoThreadToProcess(
  __in  PETHREAD Thread
);


__declspec(dllimport)
NTSTATUS ZwSetSecurityObject(
  __in  HANDLE Handle,
  __in  SECURITY_INFORMATION SecurityInformation,
  __in  PSECURITY_DESCRIPTOR SecurityDescriptor
);


__declspec(dllimport)
NTSTATUS NtSetSecurityObject(
  __in  HANDLE Handle,
  __in  SECURITY_INFORMATION SecurityInformation,
  __in  PSECURITY_DESCRIPTOR SecurityDescriptor
);


__declspec(dllimport)
NTSTATUS ZwDeleteFile(
  __in  POBJECT_ATTRIBUTES ObjectAttributes
);




// ---- File and direcory information -------------------------------------------------------------------------------------------

typedef struct _FILE_DIRECTORY_INFORMATION {
  ULONG         NextEntryOffset;
  ULONG         FileIndex;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  LARGE_INTEGER EndOfFile;
  LARGE_INTEGER AllocationSize;
  ULONG         FileAttributes;
  ULONG         FileNameLength;
  WCHAR         FileName[1];
} FILE_DIRECTORY_INFORMATION, *PFILE_DIRECTORY_INFORMATION;


__declspec(dllimport)
NTSTATUS ZwQueryDirectoryFile(
  __in      HANDLE FileHandle,
  __in_opt  HANDLE Event,
  __in_opt  PIO_APC_ROUTINE ApcRoutine,
  __in_opt  PVOID ApcContext,
  __out     PIO_STATUS_BLOCK IoStatusBlock,
  __out     PVOID FileInformation,
  __in      ULONG Length,
  __in      FILE_INFORMATION_CLASS FileInformationClass,
  __in      BOOLEAN ReturnSingleEntry,
  __in_opt  PUNICODE_STRING FileName,
  __in      BOOLEAN RestartScan
);


// ---- User mode specific -----------------------------------------------------------------------------------------------------

typedef struct _STARTUPINFOW {
    DWORD   cb;
    LPWSTR  lpReserved;
    LPWSTR  lpDesktop;
    LPWSTR  lpTitle;
    DWORD   dwX;
    DWORD   dwY;
    DWORD   dwXSize;
    DWORD   dwYSize;
    DWORD   dwXCountChars;
    DWORD   dwYCountChars;
    DWORD   dwFillAttribute;
    DWORD   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    PCHAR	lpReserved2;
    HANDLE  hStdInput;
    HANDLE  hStdOutput;
    HANDLE  hStdError;
} STARTUPINFOW, *PSTARTUPINFOW;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;


//
// dwCreationFlag values
//

#define DEBUG_PROCESS                     0x00000001
#define DEBUG_ONLY_THIS_PROCESS           0x00000002

#define CREATE_SUSPENDED                  0x00000004

#define DETACHED_PROCESS                  0x00000008

#define CREATE_NEW_CONSOLE                0x00000010

#define NORMAL_PRIORITY_CLASS             0x00000020
#define IDLE_PRIORITY_CLASS               0x00000040
#define HIGH_PRIORITY_CLASS               0x00000080
#define REALTIME_PRIORITY_CLASS           0x00000100

#define CREATE_NEW_PROCESS_GROUP          0x00000200
#define CREATE_UNICODE_ENVIRONMENT        0x00000400

#define CREATE_SEPARATE_WOW_VDM           0x00000800
#define CREATE_SHARED_WOW_VDM             0x00001000
#define CREATE_FORCEDOS                   0x00002000

#define BELOW_NORMAL_PRIORITY_CLASS       0x00004000
#define ABOVE_NORMAL_PRIORITY_CLASS       0x00008000
#define STACK_SIZE_PARAM_IS_A_RESERVATION 0x00010000

#define CREATE_BREAKAWAY_FROM_JOB         0x01000000
#define CREATE_PRESERVE_CODE_AUTHZ_LEVEL  0x02000000

#define CREATE_DEFAULT_ERROR_MODE         0x04000000
#define CREATE_NO_WINDOW                  0x08000000

#define PROFILE_USER                      0x10000000
#define PROFILE_KERNEL                    0x20000000
#define PROFILE_SERVER                    0x40000000

#define CREATE_IGNORE_SYSTEM_DEFAULT      0x80000000



// ---- Service descriptor table and other info -----------------------------------------------------------------------------

typedef struct _KSERVICE_TABLE_DESCRIPTOR {
    PULONG_PTR Base;
    PULONG Count;
    ULONG Limit;

#if defined(_IA64_)
    LONG TableBaseGpOffset;
#endif

    PUCHAR Number;
} KSERVICE_TABLE_DESCRIPTOR, *PKSERVICE_TABLE_DESCRIPTOR;



__declspec(dllimport)	USHORT	NtBuildNumber;

__declspec(dllimport)
KSERVICE_TABLE_DESCRIPTOR KeServiceDescriptorTable;

// ---- Object types and initializers ----------------------------------------------------------------------------------------

typedef	struct _OBJECT_TYPE_CALLBACKS
{
	 PVOID DumpProcedure;
     LONG * OpenProcedure;
     PVOID CloseProcedure;
     PVOID DeleteProcedure;
     LONG * ParseProcedure;
     LONG * SecurityProcedure;
     LONG * QueryNameProcedure;
     UCHAR * OkayToCloseProcedure;
} OBJECT_TYPE_CALLBACKS, *POBJECT_TYPE_CALLBACKS;


typedef struct _OBJECT_TYPE_INITIALIZER5
{
	USHORT	Length;
	UCHAR	UseDefaultObject;
	UCHAR	CaseInsensitive;
	ULONG	InvalidAttributes;
	GENERIC_MAPPING GenericMapping;
	ULONG	ValidAccessMask;
	UCHAR	SecurityRequired;
	UCHAR	MaintainHandleCount;
	UCHAR	MaintainTypeList;
	POOL_TYPE PoolType;
	ULONG	DefaultPagedPoolCharge;
	ULONG	DefaultNonPagedPoolCharge;
	OBJECT_TYPE_CALLBACKS	Callbacks;
} OBJECT_TYPE_INITIALIZER5, *POBJECT_TYPE_INITIALIZER5;


typedef struct _OBJECT_TYPE_INITIALIZER6
{
     WORD Length;
     UCHAR ObjectTypeFlags;
     ULONG CaseInsensitive: 1;
     ULONG UnnamedObjectsOnly: 1;
     ULONG UseDefaultObject: 1;
     ULONG SecurityRequired: 1;
     ULONG MaintainHandleCount: 1;
     ULONG MaintainTypeList: 1;
     ULONG ObjectTypeCode;
     ULONG InvalidAttributes;
     GENERIC_MAPPING GenericMapping;
     ULONG ValidAccessMask;
     POOL_TYPE PoolType;
     ULONG DefaultPagedPoolCharge;
     ULONG DefaultNonPagedPoolCharge;
	 OBJECT_TYPE_CALLBACKS	Callbacks;
} OBJECT_TYPE_INITIALIZER6, *POBJECT_TYPE_INITIALIZER6;


typedef struct _OBJECT_TYPE_INITIALIZER7
{
     WORD Length;
	 union {
		UCHAR ObjectTypeFlags;
		struct {
			USHORT CaseInsensitive: 1;
			USHORT UnnamedObjectsOnly: 1;
			USHORT UseDefaultObject: 1;
			USHORT SecurityRequired: 1;
			USHORT MaintainHandleCount: 1;
			USHORT MaintainTypeList: 1;
		};
	 };
	 ULONG ObjectTypeCode;
     ULONG InvalidAttributes;
     GENERIC_MAPPING GenericMapping;
     ULONG ValidAccessMask;
	 ULONG RetainAccess;
     POOL_TYPE PoolType;
     ULONG DefaultPagedPoolCharge;
     ULONG DefaultNonPagedPoolCharge;
	 OBJECT_TYPE_CALLBACKS	Callbacks;
} OBJECT_TYPE_INITIALIZER7, *POBJECT_TYPE_INITIALIZER7;


// Windows XP, 2003 object type structure
typedef struct _OBJECT_TYPE5
{
    ERESOURCE Mutex;
    LIST_ENTRY TypeList;
    UNICODE_STRING Name;
    PVOID DefaultObject;
    ULONG Index;
    ULONG TotalNumberOfObjects;
    ULONG TotalNumberOfHandles;
    ULONG HighWaterNumberOfObjects;
    ULONG HighWaterNumberOfHandles;
    OBJECT_TYPE_INITIALIZER5 TypeInfo;
} OBJECT_TYPE5, *POBJECT_TYPE5;

// Windows Vista object type structure
typedef struct _OBJECT_TYPE6
{
    LIST_ENTRY TypeList;
    UNICODE_STRING Name;
    PVOID DefaultObject;
    ULONG Index;
    ULONG TotalNumberOfObjects;
    ULONG TotalNumberOfHandles;
    ULONG HighWaterNumberOfObjects;
    ULONG HighWaterNumberOfHandles;
    OBJECT_TYPE_INITIALIZER6 TypeInfo;
} OBJECT_TYPE6, *POBJECT_TYPE6;

// Windows 7 Object type structure
typedef struct _OBJECT_TYPE7
{
    LIST_ENTRY TypeList;
    UNICODE_STRING Name;
    PVOID DefaultObject;
    UCHAR Index;
    ULONG TotalNumberOfObjects;
    ULONG TotalNumberOfHandles;
    ULONG HighWaterNumberOfObjects;
    ULONG HighWaterNumberOfHandles;
    OBJECT_TYPE_INITIALIZER7 TypeInfo;
} OBJECT_TYPE7, *POBJECT_TYPE7;

PULONG	KiServiceTable;

#define		PTR_OBJECT_TYPE_CALLBACKS(x)	(NtBuildNumber < 6000 ? &((POBJECT_TYPE5)x)->TypeInfo.Callbacks : \
	(NtBuildNumber < 7600 ? &((POBJECT_TYPE6)x)->TypeInfo.Callbacks : &((POBJECT_TYPE7)x)->TypeInfo.Callbacks))


_inline PVOID	ZwPtrFromNtPtr32(PVOID Ptr)
{
    if(*((PUCHAR)Ptr) == 0xB8) 	
        return (PVOID)KeServiceDescriptorTable.Base[*(PULONG)((PUCHAR)(Ptr)+1)];
    return NULL;
}

_inline PVOID	ZwPtrFromNtPtr64(PVOID Ptr)
{
    if(*((PUCHAR)Ptr + 3) == 0xB8) 	
	{
		if (NtBuildNumber < 6000)
			return (PVOID)((PCHAR)KiServiceTable + (KiServiceTable[*(PULONG)((PUCHAR)Ptr + 3 + 1)] & 0xfffffffc));
		else
			return (PVOID)((PCHAR)KiServiceTable + (KiServiceTable[*(PULONG)((PUCHAR)Ptr + 3 + 1)] >> 4));
	}
    return NULL;
}


#ifdef _M_AMD64
	#define		ZwPtrFromNtPtr(x)	ZwPtrFromNtPtr64(x)
#else
	#define		ZwPtrFromNtPtr(x)	ZwPtrFromNtPtr32(x)
#endif

_inline PVOID	GetKernelBaseByPtr(PVOID Ptr)
{
	PCHAR	KernelPtr = (PCHAR)((ULONG_PTR)Ptr & (~0xffff));

	while (*(PUSHORT)KernelPtr != IMAGE_DOS_SIGNATURE)
		KernelPtr -= (PAGE_SIZE * 0x10); 

	return((PVOID)KernelPtr);
}

// ---- PEB and used structures -----------------------------------------------------------------------------------------------
#define  PEB_MAX_DLL_NAME	0x80	// bytes

typedef VOID NTSYSAPI (*PPEBLOCKROUTINE)(PVOID);

typedef struct _PEB_LDR_DATA
{
	ULONG		Length;
	BOOLEAN		Initialized;
	PVOID		SsHandle;
	LIST_ENTRY	InLoadOrderModuleList; // ref. to PLDR_DATA_TABLE_ENTRY->InLoadOrderModuleList
	LIST_ENTRY	InMemoryOrderModuleList; // ref. to PLDR_DATA_TABLE_ENTRY->InMemoryOrderModuleList
	LIST_ENTRY	InInitializationOrderModuleList; // ref. to PLDR_DATA_TABLE_ENTRY->InInitializationOrderModuleList
} PEB_LDR_DATA, *PPEB_LDR_DATA;


typedef struct _LDR_DATA_TABLE_ENTRY
{
    LIST_ENTRY		InLoadOrderModuleList;
    LIST_ENTRY		InMemoryOrderModuleList;
    LIST_ENTRY		InInitializationOrderModuleList;
    PVOID			DllBase;
    PVOID			EntryPoint;
    ULONG			SizeOfImage;	// in bytes
    UNICODE_STRING	FullDllName;
    UNICODE_STRING	BaseDllName;
    ULONG			Flags;			// LDR_*
    USHORT			LoadCount;
    USHORT			TlsIndex;
    LIST_ENTRY		HashLinks;
    PVOID			SectionPointer;
    ULONG			CheckSum;
    ULONG			TimeDateStamp;
//    PVOID			LoadedImports;					// seems they are exist only on XP !!!
//    PVOID			EntryPointActivationContext;	// -same-
} LDR_DATA_TABLE_ENTRY, *PLDR_DATA_TABLE_ENTRY;


typedef struct _PEB_FREE_BLOCK
{
   struct _PEB_FREE_BLOCK	*Next;
   ULONG					Size;
} PEB_FREE_BLOCK, *PPEB_FREE_BLOCK;

typedef struct _CURDIR
{
   UNICODE_STRING	DosPath;
   HANDLE			Handle;
} CURDIR, *PCURDIR;

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
	WORD	Flags;
	WORD	Length;
	DWORD	TimeStamp;
	STRING	DosPath;
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR;

typedef struct _SYSTEM_STRINGS
{
	UNICODE_STRING	SystemRoot;       // C:\WINNT
	UNICODE_STRING	System32Root;     // C:\WINNT\System32
	UNICODE_STRING	BaseNamedObjects; // \BaseNamedObjects
}SYSTEM_STRINGS,*PSYSTEM_STRINGS;

typedef struct _TEXT_INFO
{
	PVOID			Reserved;
	PSYSTEM_STRINGS	SystemStrings;
}TEXT_INFO, *PTEXT_INFO;


typedef struct _PROCESS_PARAMETERS
{
    ULONG					MaximumLength;
    ULONG					Length;
    ULONG					Flags;				// PROCESS_PARAMETERS_NORMALIZED
    ULONG					DebugFlags;
    HANDLE					ConsoleHandle;
    ULONG					ConsoleFlags;
    HANDLE					StandardInput;
    HANDLE					StandardOutput;
    HANDLE					StandardError;
    CURDIR					CurrentDirectory;
    UNICODE_STRING			DllPath;
    UNICODE_STRING			ImagePathName;
    UNICODE_STRING			CommandLine;
    PWSTR					Environment;
    ULONG					StartingX;
    ULONG					StartingY;
    ULONG					CountX;
    ULONG					CountY;
    ULONG					CountCharsX;
    ULONG					CountCharsY;
    ULONG					FillAttribute;
    ULONG					WindowFlags;
    ULONG					ShowWindowFlags;
    UNICODE_STRING			WindowTitle;
    UNICODE_STRING			Desktop;
    UNICODE_STRING			ShellInfo;
    UNICODE_STRING			RuntimeInfo;
	RTL_DRIVE_LETTER_CURDIR	CurrentDirectores[32];
} PROCESS_PARAMETERS, *PPROCESS_PARAMETERS;

typedef struct _PEB
{
	UCHAR				InheritedAddressSpace;				// 0
	UCHAR				ReadImageFileExecOptions;			// 1
	UCHAR				BeingDebugged;						// 2
	BYTE				b003;								// 3
	PVOID				Mutant;								// 4
	PVOID				ImageBaseAddress;					// 8
	PPEB_LDR_DATA		Ldr;								// C
	PPROCESS_PARAMETERS	ProcessParameters;					// 10
	PVOID				SubSystemData;						// 14  
	PVOID				ProcessHeap;						// 18
	KSPIN_LOCK			FastPebLock;						// 1C
	PPEBLOCKROUTINE		FastPebLockRoutine;					// 20
	PPEBLOCKROUTINE		FastPebUnlockRoutine;				// 24
	ULONG				EnvironmentUpdateCount;				// 28
	PVOID				*KernelCallbackTable;				// 2C
	PVOID				EventLogSection;					// 30
	PVOID				EventLog;							// 34
	PPEB_FREE_BLOCK		FreeList;							// 38
	ULONG				TlsExpansionCounter;				// 3C
	PRTL_BITMAP			TlsBitmap;							// 40
	ULONG				TlsBitmapData[0x2];					// 44
	PVOID				ReadOnlySharedMemoryBase;			// 4C
	PVOID				ReadOnlySharedMemoryHeap;			// 50
	PTEXT_INFO			ReadOnlyStaticServerData;			// 54
	PVOID				InitAnsiCodePageData;				// 58
	PVOID				InitOemCodePageData;				// 5C
	PVOID				InitUnicodeCaseTableData;			// 60
	ULONG				KeNumberProcessors;					// 64
	ULONG				NtGlobalFlag;						// 68
	DWORD				d6C;								// 6C
	LARGE_INTEGER		MmCriticalSectionTimeout;			// 70
	ULONG				MmHeapSegmentReserve;				// 78
	ULONG				MmHeapSegmentCommit;				// 7C
	ULONG				MmHeapDeCommitTotalFreeThreshold;	// 80
	ULONG				MmHeapDeCommitFreeBlockThreshold;	// 84
	ULONG				NumberOfHeaps;						// 88
	ULONG				AvailableHeaps;						// 8C
	PHANDLE				ProcessHeapsListBuffer;				// 90
	PVOID				GdiSharedHandleTable;				// 94
	PVOID				ProcessStarterHelper;				// 98
	PVOID				GdiDCAttributeList;					// 9C
	KSPIN_LOCK			LoaderLock;							// A0
	ULONG				NtMajorVersion;						// A4
	ULONG				NtMinorVersion;						// A8
	USHORT				NtBuildNumber;						// AC
	USHORT				NtCSDVersion;						// AE
	ULONG				PlatformId;							// B0
	ULONG				Subsystem;							// B4
	ULONG				MajorSubsystemVersion;				// B8
	ULONG				MinorSubsystemVersion;				// BC
	KAFFINITY			AffinityMask;						// C0
	ULONG				GdiHandleBuffer[0x22];				// C4
	ULONG				PostProcessInitRoutine;				// 14C
	ULONG				TlsExpansionBitmap;					// 150
	UCHAR				TlsExpansionBitmapBits[0x80];		// 154
	ULONG				SessionId;							// 1D4
	ULARGE_INTEGER		AppCompatFlags;						// 1D8
	PULONG				CSDVersion;							// 1E0
/*	PVOID				AppCompatInfo;						// 1E4
	UNICODE_STRING		usCSDVersion;
	PVOID				ActivationContextData;
    PVOID				ProcessAssemblyStorageMap;
    PVOID				SystemDefaultActivationContextData;
    PVOID				SystemAssemblyStorageMap;
    ULONG				MinimumStackCommit; */
} PEB, *PPEB;
