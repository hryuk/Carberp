#include <windows.h>
#include "ntdll.h"
#include "Imagehlp.h"

#define	SECTION_CONFIG_NAME	".fpbcfg"
#define ALIGN_DOWN(x, align) (x &~ (align - 1))
#define ALIGN_UP(x, align) ((x & (align - 1)) ? ALIGN_DOWN(x, align) + align:x)

BOOL InsertSectionConfigInPE(PVOID pvPEBase,DWORD dwPESize,PVOID pvData,DWORD dwDataSize,PVOID *ppvNewPE,DWORD *pdwNewPESize);
