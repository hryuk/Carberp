#ifndef _UTILS_H_
#define _UTILS_H_

#define _DEBUG

#ifdef _DEBUG
VOID DbgPrint(PCHAR pcFormat,...);
#else
#define DbgPrint(...)
#endif

#define ALIGN_DOWN(x, align) (x &~ (align - 1))
#define ALIGN_UP(x, align) ((x & (align - 1)) ? ALIGN_DOWN(x, align) + align:x)
#define RVA_TO_VA(B,O) ((PCHAR)(((PCHAR)(B)) + ((ULONG_PTR)(O))))
#define VA_TO_RVA(B,P) ((ULONG)(((PCHAR)(P)) - ((PCHAR)(B))))
#define MAKE_PTR(B,O,T) (T)(RVA_TO_VA(B,O))
#define RtlOffsetToPointer(B, O) ((PCHAR)(((PCHAR)(B)) + ((ULONG_PTR)(O))))

PVOID GetMyBase();
DWORD RvaToOffset(PIMAGE_NT_HEADERS pPE,DWORD dwRva);
VOID FixDWORD(BYTE *Data,DWORD Size,DWORD Old,DWORD New);
PIMAGE_SECTION_HEADER SearchSection(PVOID pvPEBase,LPCSTR lpName);
PVOID MapBinary(LPCSTR lpPath,DWORD dwFileAccess,DWORD dwFileFlags,DWORD dwPageAccess,DWORD dwMapAccess,PDWORD pdwSize);
BOOL SetFileDllFlag(LPCSTR lpPath);
BOOL FileWrite(LPCSTR lpName,DWORD dwFlags,LPCVOID pvBuffer,DWORD dwSize);
BOOL FileRead(LPCSTR lpFileName, PVOID *ppBuffer, DWORD *pdwSize);
BOOL CheckAdmin();
BOOL CheckUAC();
BOOL CheckWow64();
VOID HideDllPeb(LPCSTR lpDllName);
PVOID GetSystemInformation(SYSTEMINFOCLASS InfoClass);
DWORD CreateThreadAndWait(PVOID pvProc,PVOID pvContext,DWORD dwWait);
LPCSTR GetMachineGuid();
PCHAR GetStrValueStr(PCHAR pcBuffer,DWORD dwBufferLen,PCHAR pcStr,DWORD dwStrLen,PCHAR pcSep);
unsigned long Crc32(const unsigned char * buf, unsigned long len);
LONG DeleteRegKeyRecursive(HKEY RootKey,LPCSTR lpSubKey);
BOOL LoadImageFromMemory(PVOID pBuffer, PVOID *ppImage);
BOOLEAN ProcessImport(PVOID pvImageBase);
BOOL ProcessRelocs(PVOID pvImageBase, DWORD dwDelta);
PVOID GetExportEntry(PVOID ModuleBase, LPCSTR lpProcName);
UINT GetRand(UINT uMin, UINT uMax);

#endif