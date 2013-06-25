#ifndef _UTILSU_H_
#define _UTILSU_H_

#define RtlOffsetToPointer(B,O) ((PCHAR)(((PCHAR)(B)) + ((ULONG_PTR)(O))))
#define RtlPointerToOffset(B,P) ((ULONG)(((PCHAR)(P)) - ((PCHAR)(B))))
#define FlagOn(x, f) ((x) & (f))
#define MAKE_PTR(B,O,T) ((T)RtlOffsetToPointer(B,O))

#ifdef _DEBUG
VOID  __cdecl UtiDPrint(LPCSTR lpFormat, ...);
#else
#define UtiDPrint(...)
#endif

PVOID UtiMemAlloc(DWORD dwSize);
VOID UtiMemFree(PVOID pvMem);
PVOID UtiMemReAlloc(PVOID pvMem, DWORD dwSize);


BOOL UtiSetFileDllFlag(LPCSTR lpPath);

#endif