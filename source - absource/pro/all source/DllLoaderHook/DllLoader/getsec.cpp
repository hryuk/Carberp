#include "getsec.h"

PIMAGE_SECTION_HEADER SearchSection(PVOID pvPEBase,LPCSTR lpName)
{
	PIMAGE_NT_HEADERS pNtHeaders;

	pNtHeaders = RtlImageNtHeader(pvPEBase);
	if (pNtHeaders)
	{
		PIMAGE_SECTION_HEADER pSection = IMAGE_FIRST_SECTION(pNtHeaders);

		for (WORD i = 0; i < pNtHeaders->FileHeader.NumberOfSections; i++)
		{
			if (!strcmp(lpName,(PCHAR)&pSection->Name)) return pSection;

			pSection++;
		}
	}

	return 0;
}

BOOL GetSectionConfigData(PVOID pvPEBase,PVOID *ppvData,DWORD *pdwDataSize)
{
	BOOL bRet = FALSE;
	PIMAGE_SECTION_HEADER pvSection;

	if (pvSection = SearchSection(pvPEBase,SECTION_CONFIG_NAME))
	{
		char* data = MAKE_PTR(pvPEBase,pvSection->VirtualAddress,char*);
		*ppvData = (void*)data;
		*pdwDataSize = *((int*)data) + sizeof(int);
	}

	return bRet;
}
