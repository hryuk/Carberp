#include <windows.h>
#include "ntdll.h"
#include "Imagehlp.h"

#define ALIGN_DOWN(x, align) (x &~ (align - 1))
#define ALIGN_UP(x, align) ((x & (align - 1)) ? ALIGN_DOWN(x, align) + align:x)
#define RVA_TO_VA(B,O) ((PCHAR)(((PCHAR)(B)) + ((ULONG_PTR)(O))))
#define VA_TO_RVA(B,P) ((ULONG)(((PCHAR)(P)) - ((PCHAR)(B))))
#define MAKE_PTR(B,O,T) (T)(RVA_TO_VA(B,O))
#define RtlOffsetToPointer(B, O) ((PCHAR)(((PCHAR)(B)) + ((ULONG_PTR)(O))))

#define	SECTION_CONFIG_NAME	".fpbcfg\x00"

BOOL GetSectionConfigData(PVOID pvPEBase,PVOID *ppvData,DWORD *pdwDataSize);



PVOID GetSectionData(PCHAR Name,DWORD *Size);

PCHAR GetSectionAnsiString(PCHAR Name);

PIMAGE_SECTION_HEADER SearchSection(PVOID pvPEBase,PCHAR lpName);
