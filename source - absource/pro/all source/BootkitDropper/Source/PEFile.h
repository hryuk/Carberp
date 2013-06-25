#pragma once
#include "windows.h"
namespace PEFile
{
	PIMAGE_NT_HEADERS			GetNtHeaders(PVOID Image);
	PIMAGE_SECTION_HEADER		GetSectionFromVA(PVOID Image,DWORD VA,BOOL Align);
	DWORD						VAToOffset (PVOID Image,DWORD VA,BOOL IsMapped,BOOL Align);
	PIMAGE_SECTION_HEADER		InsertSection (PVOID Image,PIMAGE_SECTION_HEADER psec);
	BOOL						ExeToDll(PVOID Image);
	BOOL						IsDll(PVOID Image);
	DWORD						SetNewEntryPoint(PVOID Image,DWORD RVA);
	BOOL						BuildImportTable(PVOID CodeBase);
};