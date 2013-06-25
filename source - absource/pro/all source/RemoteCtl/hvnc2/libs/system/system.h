#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <windows.h>
#include <tlhelp32.h>

#define ALIGN(x,y) (((x)+(y)-1)&(~((y)-1)))
#define RVATOVA(base,offset) (((ULONG_PTR)(base)+(ULONG_PTR)(offset)))

byte *ldr_GetOurAddr();

struct OUR_UNICODE_STRING
{
    USHORT Length;
    USHORT MaximumLength;
    PWSTR  Buffer;
};

struct PEB_LDR_MODULE{
  LIST_ENTRY              InLoadOrderModuleList;
  LIST_ENTRY              InMemoryOrderModuleList;
  LIST_ENTRY              InInitializationOrderModuleList;
  PVOID                   BaseAddress;
  PVOID                   EntryPoint;
  SIZE_T                  SizeOfImage;
  OUR_UNICODE_STRING      FullDllName;
  OUR_UNICODE_STRING      BaseDllName;
  ULONG                   Flags;
  SHORT                   LoadCount;
  SHORT                   TlsIndex;
  LIST_ENTRY              HashTableEntry;
  ULONG                   TimeDateStamp;
};


#define LDR_GET_BY_HASH 1
typedef  HMODULE WINAPI __LoadLibraryExA(LPCSTR lpFileName,HANDLE hFile,DWORD dwFlags);

DWORD ldr_GetImageSize();
byte *ldr_GetImageBase(byte *lpImg);

typedef struct
{
    WORD	Offset:12;
    WORD	Type:4;
} IMAGE_FIXUP_ENTRY, *PIMAGE_FIXUP_ENTRY;

extern int dwSize;
extern byte *lpImage;

extern "C" bool SysCloseHandle(HANDLE hHandle);
DWORD FindProcess(TCHAR *lpFileName);

#endif // SYSTEM_H_INCLUDED
