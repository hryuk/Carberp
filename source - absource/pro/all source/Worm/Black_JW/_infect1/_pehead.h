
 // PE Header: see MSDN info in !doc\optional_header.txt

typedef struct PE_STRUCT
{
DWORD   id;                  // 00 01 02 03
WORD    cputype;             // 04 05
WORD    numofobjects;        // 06 07
DWORD   datetime;            // 08 09 0A 0B
DWORD   coffptr;             // 0C 0D 0E 0F
DWORD   coffsize;            // 10 11 12 13
WORD    ntheadersize;        // 14 15
WORD    flags;               // 16 17
        // OPTIONAL_HEADER (aka NT_Header)
WORD    magic;               // 18 19
BYTE    linkmajor;           // 1A
BYTE    linkminor;           // 1B
DWORD   sizeofcode;          // 1C 1D 1E 1F
DWORD   sizeofidata;         // 20 21 22 23
DWORD   sizeofudata;         // 24 25 26 27
DWORD   entrypointrva;       // 28 29 2A 2B
DWORD   baseofcode;          // 2C 2D 2E 2F
DWORD   baseofdata;          // 30 31 32 33
DWORD   imagebase;           // 34 35 36 37
DWORD   objectalign;         // 38 39 3A 3B
DWORD   filealign;           // 3C 3D 3E 3F
WORD    osmajor;             // 40 41
WORD    osminor;             // 42 43
WORD    usermajor;           // 44 45
WORD    userminor;           // 46 47
WORD    subsysmajor;         // 48 49
WORD    subsysminor;         // 4A 4B
DWORD   reserved;            // 4C 4D 4E 4F
DWORD   imagesize;           // 50 51 52 53
DWORD   headersize;          // 54 55 56 56
DWORD   checksum;            // 58 59 5A 5B
WORD    subsystem;           // 5C 5D
WORD    dllflags;            // 5E 5F
DWORD   stackreserve;        // 60 61 62 63
DWORD   stackcommit;         // 64 65 66 67
DWORD   heapreserve;         // 68 69 6A 6B
DWORD   heapcommit;          // 6C 6D 6E 6F
DWORD   loaderflags;         // 70 71 72 73
DWORD   numofrvaandsizes;    // 74 75 76 77
        // rva and sizes
DWORD   exportrva;           // 78 79 7A 7B
DWORD   exportsize;          // 7C 7D 7E 7F
DWORD   importrva;           // 80 81 82 83
DWORD   importsize;          // 84 85 86 87
DWORD   resourcerva;         // 88 89 8A 8B
DWORD   resourcesize;        // 8C 8D 8E 8F
DWORD   exceptionrva;        // 90 91 92 93
DWORD   exceptionsize;       // 94 95 96 97
DWORD   securityrva;         // 98 99 9A 9B
DWORD   securitysize;        // 9C 9D 9E 9F
DWORD   fixuprva;            // A0 A1 A2 A3
DWORD   fixupsize;           // A4 A5 A6 A7
DWORD   debugrva;            // A8 A9 AA AB
DWORD   debugsize;           // AC AD AE AF
DWORD   descriptionrva;      // B0 B1 B2 B3
DWORD   descriptionsize;     // B4 B5 B6 B7
DWORD   machinerva;          // B8 B9 BA BB
DWORD   machinesize;         // BC BD BE BF
DWORD   tlsrva;              // C0 C1 C2 C3
DWORD   tlssize;             // C4 C5 C6 C7
DWORD   loadconfigrva;       // C8 C9 CA CB
DWORD   loadconfigsize;      // CC CD CE CF
DWORD   boundimprva;         // D0 D1 D2 D3  
DWORD   boundimpsize;        // D4 D5 D6 D7
DWORD   iatrva;              // D8 D9 DA DB
DWORD   iatsize;             // DC DD DE DF
DWORD   delayimprva;         // E0 E1 E2 E3
DWORD   delayimpsize;        // E4 E5 E6 E7
DWORD   netmetadatarva;      // E8 E9 EA EB
DWORD   netmetadatasize;     // EC ED EE EF
BYTE    reserved_4[8];       // F0 F1 F2 F3  F4 F5 F6 F7
// ---- total size == 0xF8 ---------
} PE_HEADER;

typedef struct PE_OBJENTRY_STRUCT
{
 BYTE    name[8];             // 00 01 02 03  04 05 06 07
 DWORD   virtsize;            // 08 09 0A 0B
 DWORD   virtrva;             // 0C 0D 0E 0F
 DWORD   physsize;            // 10 11 12 13
 DWORD   physoffs;            // 14 15 16 17
 BYTE    reserved[0x0C];      // 18 19 1A 1B   1C 1D 1E 1F  20 21 22 23
 DWORD   objectflags;         // 24 25 26 27
// ---- total size == 0x28 ---------
} PE_OBJENTRY;


typedef struct PE_DEBUG_STRUCT
{
 DWORD flags;           // 00 01 02 03  
 DWORD TimeStamp;       // 04 05 06 07
 DWORD version;         // 08 09 0A 0B
 DWORD DbgFlg;          // 0C 0D 0E 0F
 DWORD DataSize;        // 10 11 12 13
 DWORD DataRVA;         // 14 15 16 17
 DWORD DataSeek;        // 18 19 1A 1B
// ---- total size == 0x1C ---------
} PE_DEBUG;

#define SZOBJE 0x28 //sizeof(PE_OBJENTRY)
#define SZPE   0xF8 //sizeof(PE_HEADER)
#define SZDBG  0x1C //sizeof(PE_DEBUG)
#define SZIDTE 0x14 //sizeof(IMPORT_DIRECTORY_TABLE_ENTRY)

typedef struct FIXUP_BLOCK_STRUCT
{
 DWORD PageRVA;           // 00 01 02 03  
 DWORD BlockSize;         // 04 05 06 07
} FIXUP_BLOCK;

typedef struct EXPORT_DIRECTORY_TABLE_STRUCT
{
 DWORD  Flags;           // 00 01 02 03
 DWORD  TimeStamp;       // 04 05 06 07
 WORD   MajorVersion;    // 08 09
 WORD   MinorVersion;    // 0A 0B
 DWORD  NameRVA;         // 0C 0D 0E 0F
 DWORD  OrdinalBase;    
 DWORD  NumOfFunctions;
 DWORD  NumOfNamePointers; 
 DWORD  AddressTableRVA;    
 DWORD  NamePointersRVA;    
 DWORD  OrdinalTableRVA;
} EXPORT_DIRECTORY_TABLE;


typedef struct IMPORT_DIRECTORY_TABLE_ENTRY_STRUCT
{
 DWORD ImportLookUp;
 DWORD TimeStamp;
 DWORD ForwardChain;
 DWORD NameRVA;
 DWORD AddressTableRVA;
} IMPORT_DIRECTORY_TABLE_ENTRY;

