#ifndef _UTILS_H_
#define _UTILS_H_

BOOL FileWrite(PWCHAR Name, PVOID Buffer, DWORD Size);
BOOL FileRead(PWCHAR Name, PVOID *Buffer, DWORD *Size);
VOID SetFileDllFlag(PWCHAR FileName);

#define RtlOffsetToPointer(B,O) ((PCHAR)(((PCHAR)(B)) + ((ULONG_PTR)(O))))
#define MAKE_PTR(Base, Offset, Type) ((Type)(DWORD(Base) + (DWORD)(Offset)))
#define ALIGN_DOWN(x, align) (x & ~(align - 1))
#define ALIGN_UP(x, align) ((x & (align - 1)) ? ALIGN_DOWN(x, align) + align : x)

namespace PeLdr
{
	DWORD64 PeGetImageBase(PVOID ImageBase);
	PIMAGE_NT_HEADERS PeImageNtHeader(PVOID ImageBase);
	PVOID PeImageDirectoryEntryToData(PVOID ImageBase, BOOLEAN ImageLoaded, ULONG Directory, PULONG Size, BOOLEAN RVA = FALSE);
	BOOLEAN PeProcessRelocs(PVOID ImageBase, ULONGLONG Diff);
	PVOID PeGetProcAddress(PVOID ModuleBase, PCHAR lpProcName, BOOLEAN RVA = FALSE);
	BOOLEAN PeProcessImport(PVOID pMZ, BOOLEAN Ntdll64 = FALSE);

#ifndef _WIN64
	PIMAGE_BASE_RELOCATION PeProcessRelocationBlock(ULONG_PTR uVA, ULONG uSizeOfBlock, PUSHORT puNextOffset, ULONGLONG lDelta);
#else
	PIMAGE_BASE_RELOCATION PeProcessRelocationBlock(ULONG_PTR VA, ULONG SizeOfBlock, PUSHORT NextOffset, LONGLONG Diff) ;
#endif

	PVOID PeGetNtdllImageBase();
	BOOLEAN InsertSection(PCHAR SectionName, PVOID Data, DWORD DataSize, PVOID Image, DWORD ImageSize, PVOID *ResultImage, DWORD *ResultImageSize, BOOLEAN VA);
	DWORD_PTR FreeSpaceInHeader(PVOID ImageBase, PIMAGE_NT_HEADERS NtHeaders);
	PIMAGE_SECTION_HEADER GetVirtualyLastSectionHeader(PIMAGE_NT_HEADERS NtHeaders);
	PIMAGE_SECTION_HEADER GetPhysicalyLastSectionHeader(PIMAGE_NT_HEADERS NtHeaders);
	PVOID LoadPEImage(PVOID ImageBaseRaw);
	PIMAGE_SECTION_HEADER PeSearchSection(PVOID ImageBase, PCHAR SectionName);
};

namespace SecCfg
{
#define SECCFG_SECTION_NAME	".cfg"

	typedef struct _SECTION_CONFIG_RAW
	{
		DWORD ConfigSize;
		DWORD ImageSize;
	}
	SECTION_CONFIG_RAW, *PSECTION_CONFIG_RAW;

	typedef struct _SECTION_CONFIG
	{
		SECTION_CONFIG_RAW Raw;
		PCHAR Name;
		PVOID Config;
		PVOID Image;
	}
	SECTION_CONFIG, *PSECTION_CONFIG;

	BOOLEAN InsertSectionConfig(PSECTION_CONFIG SectionConfig, PVOID Image, DWORD ImageSize, PVOID *ResultImage, DWORD *ResultImageSize, BOOLEAN VA);
	BOOLEAN GetSectionConfig(PSECTION_CONFIG SectionConfig, PVOID Image);
	BOOLEAN GetImageFromImage(PVOID ImageBase, PVOID *ResultImageBase, DWORD *ResultImageSize, BOOLEAN Load64);
	BOOLEAN ConvertImageToImage(PVOID ImageBase, SecCfg::PSECTION_CONFIG SectionConfig, PVOID *ResultImage, DWORD *ResultImageSize, BOOLEAN Load64);
	PVOID LoadImageSections(PVOID ImageBaseRaw, DWORD *ImageSize);
};

#endif