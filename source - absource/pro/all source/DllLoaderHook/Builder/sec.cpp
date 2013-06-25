#include "sec.h"

DWORD FreeSpaceInHeader(PVOID pvPEBase)
{
	PIMAGE_NT_HEADERS pNtHeaders = RtlImageNtHeader(pvPEBase);

	if (pNtHeaders)
	{
		PIMAGE_SECTION_HEADER pFirstSection = IMAGE_FIRST_SECTION(pNtHeaders);
	
		return (pFirstSection->PointerToRawData - ((DWORD)pFirstSection - (DWORD)pvPEBase) - (pNtHeaders->FileHeader.NumberOfSections * IMAGE_SIZEOF_SECTION_HEADER));
	}

	return 0;
}

PIMAGE_SECTION_HEADER GetVirtualyLastSectionHeader(PIMAGE_NT_HEADERS pNtHeaders)
{
	PIMAGE_SECTION_HEADER pFirstSection = IMAGE_FIRST_SECTION(pNtHeaders);

	return &pFirstSection[pNtHeaders->FileHeader.NumberOfSections - 1];
}

PIMAGE_SECTION_HEADER GetPhysicalyLastSectionHeader(PIMAGE_NT_HEADERS pNtHeaders)
{
	PIMAGE_SECTION_HEADER pFirstSection = IMAGE_FIRST_SECTION(pNtHeaders);
	PIMAGE_SECTION_HEADER pLastSection = pFirstSection;

	if (1 == pNtHeaders->FileHeader.NumberOfSections) return pLastSection;

	for	(DWORD i = 0; i < pNtHeaders->FileHeader.NumberOfSections; ++i)
	{
		if (pLastSection->PointerToRawData < pFirstSection->PointerToRawData) pLastSection = pFirstSection;

		++pFirstSection;
	}

	return pLastSection;
}

PIMAGE_SECTION_HEADER InsertSectionHeader(PVOID pvPEBase,LPCSTR lpName,DWORD dwVirtualSize,DWORD dwCharacteristics,PDWORD pdwSize)
{
	if (strlen(lpName) > 7) 
	{
		return NULL;
	}

	if (FreeSpaceInHeader(pvPEBase) < IMAGE_SIZEOF_SECTION_HEADER) 
	{
		return NULL;
	}

	PIMAGE_NT_HEADERS pNtHeaders = RtlImageNtHeader(pvPEBase);
	if (!pNtHeaders) 
	{
		return NULL;
	}

	DWORD dwSizeOfRawData = ALIGN_UP(dwVirtualSize,pNtHeaders->OptionalHeader.FileAlignment);
	dwVirtualSize = ALIGN_UP(dwVirtualSize,pNtHeaders->OptionalHeader.SectionAlignment);

	PIMAGE_SECTION_HEADER pNewSection = (PIMAGE_SECTION_HEADER)malloc(IMAGE_SIZEOF_SECTION_HEADER);
	if (!pNewSection) 
	{
		return NULL;
	}

	memset( pNewSection, 0, IMAGE_SIZEOF_SECTION_HEADER );
	memcpy((PVOID)(&pNewSection->Name),(PVOID)lpName,strlen(lpName));
	pNewSection->Characteristics = dwCharacteristics;
	pNewSection->Misc.VirtualSize = dwVirtualSize;
	pNewSection->SizeOfRawData = dwSizeOfRawData;

	PIMAGE_SECTION_HEADER pVirtualLastSection = GetVirtualyLastSectionHeader(pNtHeaders);
	pNewSection->VirtualAddress = pVirtualLastSection->VirtualAddress + ALIGN_UP(pVirtualLastSection->Misc.VirtualSize,pNtHeaders->OptionalHeader.SectionAlignment);	
	
	if (dwSizeOfRawData)
	{ 
		PIMAGE_SECTION_HEADER pLastSection = GetPhysicalyLastSectionHeader(pNtHeaders);

		pNewSection->PointerToRawData = pLastSection->PointerToRawData + ALIGN_UP(pLastSection->SizeOfRawData,pNtHeaders->OptionalHeader.FileAlignment);
	}
	
	*pdwSize = dwVirtualSize;

	return pNewSection;
}

BOOL InsertSectionConfigInPE(PVOID pvPEBase,DWORD dwPESize,PVOID pvData,DWORD dwDataSize,PVOID *ppvNewPE,DWORD *pdwNewPESize)
{
	BOOL bRet = FALSE;
	PIMAGE_SECTION_HEADER pNewSection;
	DWORD dwSize;
	if (pNewSection = InsertSectionHeader( pvPEBase, SECTION_CONFIG_NAME, dwDataSize,IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ,&dwSize))
	{
		PVOID pvNewPE;
		DWORD dwNewPESize = pNewSection->PointerToRawData + pNewSection->SizeOfRawData;

		if (pvNewPE = malloc(dwNewPESize))
		{
			memcpy(pvNewPE,pvPEBase,dwPESize);

			PIMAGE_NT_HEADERS pNtHeaders = RtlImageNtHeader(pvNewPE);

			++(pNtHeaders->FileHeader.NumberOfSections);

			PIMAGE_SECTION_HEADER pVirtualLastSection = GetVirtualyLastSectionHeader(pNtHeaders);
			pVirtualLastSection[0] = *pNewSection;
					
			pNtHeaders->OptionalHeader.SizeOfImage += dwSize;

			memcpy((PVOID)((DWORD)pvNewPE + pNewSection->PointerToRawData),pvData,dwDataSize);

			DWORD dwHeaderSum, dwCheckSum;

			if (CheckSumMappedFile(pvNewPE,dwNewPESize,&dwHeaderSum,&dwCheckSum))
			{
				pNtHeaders->OptionalHeader.CheckSum = dwCheckSum;

				*ppvNewPE = pvNewPE;
				*pdwNewPESize = dwNewPESize;

				bRet = TRUE;
			}

			if (!bRet) free(pvNewPE);
		}

		free(pNewSection);
	}
	return bRet;
}
