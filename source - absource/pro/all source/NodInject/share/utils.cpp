#include <intrin.h>
#include <stdio.h>
#include <windows.h>
#include <psapi.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <tlhelp32.h>
#include <Winspool.h>

#include "utils.h"
#include "ntdll.h"

VOID SetFileDllFlag(PWCHAR FileName)
{
	HANDLE hFile = CreateFile(FileName, FILE_ALL_ACCESS, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0);
	HANDLE hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);
	PVOID pMap = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	PIMAGE_NT_HEADERS ImageNtHeader = RtlImageNtHeader(pMap);

	ImageNtHeader->FileHeader.Characteristics |= IMAGE_FILE_DLL;

	FlushFileBuffers(hFile);

	UnmapViewOfFile(pMap);
	CloseHandle(hMap);
	CloseHandle(hFile);
}

BOOL FileRead(PWCHAR Name, PVOID *Buffer, DWORD *Size)
{
	BOOLEAN Ret = FALSE;
	HANDLE hFile = CreateFile(Name, FILE_ALL_ACCESS, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		*Size = GetFileSize(hFile, NULL);
		if (*Buffer = LocalAlloc(LPTR, *Size))
		{
			DWORD t;

			if (ReadFile(hFile, *Buffer, *Size, &t, NULL))
			{
				Ret = TRUE;
			}
		}

		CloseHandle(hFile);
	}

	return Ret;
}

BOOL FileWrite(PWCHAR Name, PVOID Buffer, DWORD Size)
{
	BOOLEAN Ret = FALSE;
	HANDLE hFile = CreateFile(Name, FILE_ALL_ACCESS, FILE_SHARE_READ, NULL, CREATE_ALWAYS, 0, 0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD t;

		if (WriteFile(hFile, Buffer, Size, &t, NULL))
		{
			Ret = TRUE;
		}

		CloseHandle(hFile);
	}

	return Ret;
}

PVOID __cdecl malloc(DWORD Size)
{
	return LocalAlloc(LPTR, Size);
}

void __cdecl free(void * Mem)
{
	LocalFree(Mem);
}

PIMAGE_NT_HEADERS PeLdr::PeImageNtHeader(PVOID ImageBase)
{
	PIMAGE_DOS_HEADER ImageDosHeaders = (PIMAGE_DOS_HEADER)ImageBase;
	PIMAGE_NT_HEADERS ImageNtHeaders = NULL;

	if (ImageDosHeaders->e_magic == IMAGE_DOS_SIGNATURE)
	{
		ImageNtHeaders = MAKE_PTR(ImageBase, ImageDosHeaders->e_lfanew, PIMAGE_NT_HEADERS);
		if (ImageNtHeaders->Signature == IMAGE_NT_SIGNATURE)
		{
			return ImageNtHeaders;
		}
	}

	return NULL;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

PIMAGE_SECTION_HEADER PeLdr::PeSearchSection(PVOID ImageBase, PCHAR SectionName)
{
	PIMAGE_SECTION_HEADER ImageSectionHeader;
	PIMAGE_NT_HEADERS ImageNtHeaders;

	ImageNtHeaders = PeImageNtHeader(ImageBase);
	if (ImageNtHeaders)
	{
		ImageSectionHeader = IMAGE_FIRST_SECTION(ImageNtHeaders);

		for (WORD i = 0; i < ImageNtHeaders->FileHeader.NumberOfSections; i++)
		{
			if (!strcmp(SectionName, (PCHAR)&ImageSectionHeader->Name))
			{
				return ImageSectionHeader;
			}

			ImageSectionHeader++;
		}
	}

	return NULL;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

BOOLEAN SecCfg::InsertSectionConfig(PSECTION_CONFIG SectionConfig, PVOID Image, DWORD ImageSize, PVOID *ResultImage, DWORD *ResultImageSize, BOOLEAN VA)
{
	BOOLEAN Result = FALSE;
	DWORD DataSize;
	PVOID Data;

	DataSize = sizeof(SECTION_CONFIG_RAW) + SectionConfig->Raw.ConfigSize + SectionConfig->Raw.ImageSize;
	Data = malloc(DataSize);
	if (Data)
	{
		CopyMemory(Data, &SectionConfig->Raw, sizeof(SECTION_CONFIG_RAW));

		CopyMemory(RtlOffsetToPointer(Data, sizeof(SECTION_CONFIG_RAW)), SectionConfig->Config, SectionConfig->Raw.ConfigSize);
		CopyMemory(RtlOffsetToPointer(Data, sizeof(SECTION_CONFIG_RAW) + SectionConfig->Raw.ConfigSize), SectionConfig->Image, SectionConfig->Raw.ImageSize);

		Result = PeLdr::InsertSection(SectionConfig->Name, Data, DataSize, Image, ImageSize, ResultImage, ResultImageSize, VA);

		free(Data);
	}

	return Result;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

BOOLEAN SecCfg::GetSectionConfig(PSECTION_CONFIG SectionConfig, PVOID Image)
{
	BOOLEAN Result = FALSE;
	PIMAGE_SECTION_HEADER SectionHeader;
	PSECTION_CONFIG_RAW ConfigHeader;

	SectionHeader = PeLdr::PeSearchSection(Image, SectionConfig->Name);
	if (SectionHeader)
	{
		ConfigHeader = MAKE_PTR(Image, SectionHeader->VirtualAddress, PSECTION_CONFIG_RAW);

		// Копируем рав конфиг там размер имейджа и конфига
		CopyMemory(&SectionConfig->Raw, ConfigHeader, sizeof(SECTION_CONFIG_RAW));

		// Указатели на имейдж и конфиг
		SectionConfig->Config = RtlOffsetToPointer(ConfigHeader, sizeof(SECTION_CONFIG_RAW));
		SectionConfig->Image = RtlOffsetToPointer(ConfigHeader, sizeof(SECTION_CONFIG_RAW) + ConfigHeader->ConfigSize);

		Result = TRUE;
	}

	return Result;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

DWORD_PTR PeLdr::FreeSpaceInHeader(PVOID ImageBase, PIMAGE_NT_HEADERS NtHeaders)
{
	PIMAGE_SECTION_HEADER FirstSection = IMAGE_FIRST_SECTION(NtHeaders);

	return (FirstSection->PointerToRawData - ((DWORD_PTR)FirstSection - (DWORD_PTR)ImageBase) - (NtHeaders->FileHeader.NumberOfSections * IMAGE_SIZEOF_SECTION_HEADER));
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

PIMAGE_SECTION_HEADER PeLdr::GetVirtualyLastSectionHeader(PIMAGE_NT_HEADERS NtHeaders)
{
	PIMAGE_SECTION_HEADER pFirstSection = IMAGE_FIRST_SECTION(NtHeaders);

	return &pFirstSection[NtHeaders->FileHeader.NumberOfSections - 1];
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

PIMAGE_SECTION_HEADER PeLdr::GetPhysicalyLastSectionHeader(PIMAGE_NT_HEADERS NtHeaders)
{
	PIMAGE_SECTION_HEADER FirstSection = IMAGE_FIRST_SECTION(NtHeaders);
	PIMAGE_SECTION_HEADER LastSection = FirstSection;

	if (1 == NtHeaders->FileHeader.NumberOfSections) return LastSection;

	for	(WORD i = 0; i < NtHeaders->FileHeader.NumberOfSections; ++i)
	{
		if (LastSection->PointerToRawData < FirstSection->PointerToRawData) 
		{
			LastSection = FirstSection;
		}

		++FirstSection;
	}

	return LastSection;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

BOOLEAN PeLdr::InsertSection(PCHAR SectionName, PVOID Data, DWORD DataSize, PVOID Image, DWORD ImageSize, PVOID *ResultImage, DWORD *ResultImageSize, BOOLEAN VA)
{
	BOOLEAN Result = FALSE;

	do 
	{
		if (strlen(SectionName) >= IMAGE_SIZEOF_SHORT_NAME) break;

		PIMAGE_NT_HEADERS NtHeaders = PeImageNtHeader(Image);
		if (!NtHeaders) break;

		DWORD FileAlignment;
		if (NtHeaders->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64) FileAlignment = ((PIMAGE_NT_HEADERS64)NtHeaders)->OptionalHeader.FileAlignment;
		if (NtHeaders->FileHeader.Machine == IMAGE_FILE_MACHINE_I386) FileAlignment = ((PIMAGE_NT_HEADERS32)NtHeaders)->OptionalHeader.FileAlignment;

		DWORD SectionAlignment;
		if (NtHeaders->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64) SectionAlignment = ((PIMAGE_NT_HEADERS64)NtHeaders)->OptionalHeader.SectionAlignment;
		if (NtHeaders->FileHeader.Machine == IMAGE_FILE_MACHINE_I386) SectionAlignment = ((PIMAGE_NT_HEADERS32)NtHeaders)->OptionalHeader.SectionAlignment;

		if (FreeSpaceInHeader(Image, NtHeaders) < IMAGE_SIZEOF_SECTION_HEADER) break;

		IMAGE_SECTION_HEADER NewSectionHeader = {0}; 

		strcpy((PCHAR)NewSectionHeader.Name, SectionName);
		NewSectionHeader.Characteristics = IMAGE_SCN_CNT_CODE|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_EXECUTE|IMAGE_SCN_MEM_WRITE;

		NewSectionHeader.SizeOfRawData = ALIGN_UP(DataSize, FileAlignment);
		NewSectionHeader.Misc.VirtualSize = ALIGN_UP(DataSize, SectionAlignment);

		PIMAGE_SECTION_HEADER SectionHeader;

		SectionHeader = GetPhysicalyLastSectionHeader(NtHeaders);
		NewSectionHeader.PointerToRawData = SectionHeader->PointerToRawData + ALIGN_UP(SectionHeader->SizeOfRawData, FileAlignment);

		SectionHeader = GetVirtualyLastSectionHeader(NtHeaders);
		NewSectionHeader.VirtualAddress = SectionHeader->VirtualAddress + ALIGN_UP(SectionHeader->Misc.VirtualSize, SectionAlignment);

		if (VA)
		{
			*ResultImageSize = NewSectionHeader.VirtualAddress + NewSectionHeader.Misc.VirtualSize;
		}
		else
		{
			*ResultImageSize = NewSectionHeader.PointerToRawData + NewSectionHeader.SizeOfRawData;
		}

		*ResultImage = VirtualAlloc(NULL, *ResultImageSize, MEM_RESERVE|MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (!*ResultImage) break;

		CopyMemory(*ResultImage, Image, ImageSize);

		NtHeaders = PeImageNtHeader(*ResultImage);
		SectionHeader = GetVirtualyLastSectionHeader(NtHeaders);
		*(&SectionHeader[1]) = NewSectionHeader;
		++(NtHeaders->FileHeader.NumberOfSections);

		if (NtHeaders->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64) ((PIMAGE_NT_HEADERS64)NtHeaders)->OptionalHeader.SizeOfImage += NewSectionHeader.Misc.VirtualSize;
		if (NtHeaders->FileHeader.Machine == IMAGE_FILE_MACHINE_I386) ((PIMAGE_NT_HEADERS32)NtHeaders)->OptionalHeader.SizeOfImage += NewSectionHeader.Misc.VirtualSize;

		if (VA)
		{
			CopyMemory(RtlOffsetToPointer(*ResultImage, NewSectionHeader.VirtualAddress), Data, DataSize);
		}
		else
		{
			CopyMemory(RtlOffsetToPointer(*ResultImage, NewSectionHeader.PointerToRawData), Data, DataSize);
		}

		if (NtHeaders->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64) ((PIMAGE_NT_HEADERS64)NtHeaders)->OptionalHeader.CheckSum = 0;
		if (NtHeaders->FileHeader.Machine == IMAGE_FILE_MACHINE_I386) ((PIMAGE_NT_HEADERS32)NtHeaders)->OptionalHeader.CheckSum = 0;

		Result = TRUE;
	}
	while (FALSE);

	return Result;
}
