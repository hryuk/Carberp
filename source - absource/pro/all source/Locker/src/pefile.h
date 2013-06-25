#pragma once
#include "windows.h"
namespace PEFile
{
	PIMAGE_NT_HEADERS			GetNtHeaders(PVOID Image);
	PIMAGE_SECTION_HEADER		GetSectionFromRVA(PVOID Image,DWORD VA,BOOL Align);
	PIMAGE_SECTION_HEADER		GetSectionFromOffset(PVOID Image,DWORD Offset,BOOL Align);
	DWORD						VAToOffset (PVOID Image,DWORD VA,BOOL IsMapped,BOOL Align);
	PIMAGE_SECTION_HEADER		InsertSection (PVOID Image,PIMAGE_SECTION_HEADER psec);
	BOOL						ExeToDll(PVOID Image);
	BOOL						IsDll(PVOID Image);
	DWORD						SetNewEntryPoint(PVOID Image,DWORD RVA);
	DWORD						GetRVAProc(PVOID Image,PCHAR RoutineName,BOOLEAN IsMapped);
  PVOID           VAtoAddr(PVOID ImageBase ,BOOLEAN IsMapped,DWORD VA);
};

