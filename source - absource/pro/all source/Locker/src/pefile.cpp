// fakepe.cpp : Defines the entry point for the console application.
//

#include "windows.h"
#include "imagehlp.h"

#include "GetApi.h"
#include "PEFile.h"
#include "InjectUtils.h"

DWORD  ALIGN_UP (DWORD value , DWORD align )
{
	return  (value % align)?  (1+(value / align ))*align: value ;
};


PIMAGE_NT_HEADERS PEFile::GetNtHeaders(PVOID Image)
{
  PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(  ((PIMAGE_DOS_HEADER)Image)->e_lfanew +  (PCHAR)Image );
  if ( 	((PIMAGE_DOS_HEADER)Image)->e_magic != IMAGE_DOS_SIGNATURE )
	  return NULL;
  if ( pNtHeader->Signature != IMAGE_NT_SIGNATURE )
	  return NULL;
  return pNtHeader;
};


PIMAGE_SECTION_HEADER  PEFile::GetSectionFromOffset(PVOID Image,DWORD Offset,BOOL Align)
{
	PIMAGE_NT_HEADERS pHeaders = GetNtHeaders(Image);

	for ( DWORD i = 0; i < pHeaders->FileHeader.NumberOfSections; ++i)
	{
		PIMAGE_SECTION_HEADER pSec = &IMAGE_FIRST_SECTION(pHeaders)[i];
		DWORD Size =  (Align)?ALIGN_UP(pSec->Misc.VirtualSize,pHeaders->OptionalHeader.SectionAlignment)		\
											: pSec->Misc.VirtualSize ;
		if ( ( pSec->PointerToRawData<= Offset) &&  ( Offset < pSec->PointerToRawData + Size) )
		{
			return pSec;
		};
	};
	return NULL;
};


PIMAGE_SECTION_HEADER  PEFile::GetSectionFromRVA(PVOID Image,DWORD VA,BOOL Align)
{
	PIMAGE_NT_HEADERS pHeaders = GetNtHeaders(Image);

	for ( DWORD i = 0; i < pHeaders->FileHeader.NumberOfSections; ++i)
	{
		PIMAGE_SECTION_HEADER pSec = &IMAGE_FIRST_SECTION(pHeaders)[i];
		DWORD Size =  (Align)?ALIGN_UP(pSec->Misc.VirtualSize,pHeaders->OptionalHeader.SectionAlignment)		\
											: pSec->Misc.VirtualSize ;
		if ( ( pSec->VirtualAddress<= VA) &&  ( VA < pSec->VirtualAddress + Size) )
		{
			return pSec;
		};
	};
	return NULL;
};

DWORD PEFile::VAToOffset (PVOID Image,DWORD VA,BOOL IsMapped,BOOL Align)
{
	PIMAGE_SECTION_HEADER pSec = GetSectionFromRVA(Image,VA,Align);
	if (  pSec )
		return  (IsMapped)? VA - pSec->VirtualAddress : VA - pSec->VirtualAddress - pSec->PointerToRawData ; 
	return 0;
};

//
//	Добавляет секцию в РЕ заголовок.
//
PIMAGE_SECTION_HEADER PEFile::InsertSection (PVOID Image,PIMAGE_SECTION_HEADER psec)
{
	
	PIMAGE_NT_HEADERS pHeader = GetNtHeaders(Image);
	PIMAGE_SECTION_HEADER pNewSection ; 
	DWORD  BeginAreaNewSec;
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
	DWORD DataInHeader;

	m_memcpy(DataDirectory,pHeader->OptionalHeader.DataDirectory,sizeof(DataDirectory));
	
	pNewSection	 = &IMAGE_FIRST_SECTION(pHeader)[pHeader->FileHeader.NumberOfSections];  
	DataInHeader = BeginAreaNewSec = (DWORD)pNewSection  - (DWORD)Image;  

//
//		Поиск ссылок в 	DataDirectory которые ссылаются на данные в заголовке.
//
	for ( DWORD i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; ++i)
		if (   ( ( BeginAreaNewSec <= DataDirectory[i].VirtualAddress ) &			\
			     (DataDirectory[i].VirtualAddress < (BeginAreaNewSec + sizeof(IMAGE_SECTION_HEADER)) ) 
			   )
		)	
	{
		DataInHeader += DataDirectory[i].Size;
		DataDirectory[i].Size = DataDirectory[i].VirtualAddress = (DWORD)-1;
	};

//
//		Проверка хватит ли местa в заголовке для новой секции.
//
	if ( (pHeader->OptionalHeader.SizeOfHeaders - DataInHeader) < sizeof(IMAGE_SECTION_HEADER) )
		return NULL;

//
//		фикс ссылок в  DataDirectory.    
//		
	if ( DataInHeader != BeginAreaNewSec )
	{
		const DWORD dwDelta = sizeof(IMAGE_SECTION_HEADER);
		PVOID tmp  = MemAlloc((pHeader->OptionalHeader.SizeOfHeaders - BeginAreaNewSec));

		m_memcpy(tmp,pNewSection,(pHeader->OptionalHeader.SizeOfHeaders - BeginAreaNewSec));
		m_memcpy((PCHAR)pNewSection + dwDelta,tmp,(pHeader->OptionalHeader.SizeOfHeaders - BeginAreaNewSec));

		for ( DWORD i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; ++i)
			if (  (DataDirectory[i].Size == (DWORD) -1) & (DataDirectory[i].VirtualAddress == (DWORD)-1))
				{
					pHeader->OptionalHeader.DataDirectory[i].VirtualAddress += dwDelta;
				};

		MemFree(tmp);
	};

//
//     Запись секции в РЕ заголовок, правка количества секций в образе.
//
	 m_memcpy(pNewSection,psec,sizeof(IMAGE_SECTION_HEADER));
	 pHeader->OptionalHeader.SizeOfImage += ALIGN_UP(psec->Misc.VirtualSize,pHeader->OptionalHeader.SectionAlignment);
	 pHeader->FileHeader.NumberOfSections++;
	return pNewSection;
};



BOOL	PEFile::ExeToDll(PVOID Image)
{
	PIMAGE_DOS_HEADER pDos;
	PIMAGE_NT_HEADERS	pNt;

	if ( Image )
	{
		pDos = (PIMAGE_DOS_HEADER)Image;

		if ( pDos->e_lfanew < 1024)
		{	
			if ( pDos->e_magic == IMAGE_DOS_SIGNATURE)
			{
				pNt = (PIMAGE_NT_HEADERS)(pDos->e_lfanew + (PCHAR)pDos );
				if ( pNt->Signature == IMAGE_NT_SIGNATURE)
				{
					pNt->FileHeader.Characteristics  |= IMAGE_FILE_DLL;
					return TRUE;
				};
			};
		};
	};
	return FALSE;
};

BOOL PEFile::IsDll(PVOID Image)
{
	PIMAGE_DOS_HEADER pDos;
	PIMAGE_NT_HEADERS	pNt;

	if ( Image )
	{
		pDos = (PIMAGE_DOS_HEADER)Image;
		if ( pDos->e_lfanew > 1024)
			return FALSE;

		if ( pDos->e_magic != IMAGE_DOS_SIGNATURE)
			return FALSE;

		pNt = (PIMAGE_NT_HEADERS)(pDos->e_lfanew + (PCHAR)pDos );
		if ( pNt->Signature != IMAGE_NT_SIGNATURE)
			return FALSE;
		
		return pNt->FileHeader.Characteristics  & IMAGE_FILE_DLL;
	};
	return FALSE;
};


DWORD PEFile::SetNewEntryPoint(PVOID Image,DWORD RVA)
{
	PIMAGE_DOS_HEADER	pDos;
	PIMAGE_NT_HEADERS	pNt;

	if ( Image )
	{
		pDos = (PIMAGE_DOS_HEADER)Image;
		if ( pDos->e_lfanew > 1024)
			return 0;

		if ( pDos->e_magic != IMAGE_DOS_SIGNATURE)
			return FALSE;

		pNt = (PIMAGE_NT_HEADERS)(pDos->e_lfanew + (PCHAR)pDos );
		if ( pNt->Signature != IMAGE_NT_SIGNATURE)
			return 0;

		DWORD old = pNt->OptionalHeader.AddressOfEntryPoint;
		pNt->OptionalHeader.AddressOfEntryPoint = RVA;		
		return old;
	};
	return 0;
};



PVOID PEFile::VAtoAddr(PVOID ImageBase ,BOOLEAN IsMapped,DWORD VA)
{
	if (IsMapped)
		return VA + (PCHAR)ImageBase;
{
	PIMAGE_SECTION_HEADER pSection = PEFile::GetSectionFromRVA(ImageBase,VA,FALSE);
	if ( pSection )
		return  ( VA  - pSection->VirtualAddress + pSection->PointerToRawData ) + (PCHAR)ImageBase;
};
	return NULL;
};

DWORD PEFile::GetRVAProc(PVOID Image,PCHAR RoutineName,BOOLEAN IsMapped)
{
	PIMAGE_DOS_HEADER pDos = (PIMAGE_DOS_HEADER)Image;
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(pDos->e_lfanew + (PCHAR)Image);

	if ( pDos->e_magic != IMAGE_DOS_SIGNATURE)
		return NULL;
	if ( pNtHeader->Signature != IMAGE_NT_SIGNATURE)
		return NULL;
	
	{
		ULONG i;
		PIMAGE_EXPORT_DIRECTORY pExportDir = (PIMAGE_EXPORT_DIRECTORY)( VAtoAddr(Image,IsMapped,pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress));
		DWORD *AddressOfNames		= (DWORD*) VAtoAddr(Image,IsMapped,pExportDir->AddressOfNames);
		DWORD *AddressOfFunctions	= (DWORD*) VAtoAddr(Image,IsMapped,pExportDir->AddressOfFunctions);
		USHORT *AddressOfNameOrdinals	= (USHORT*) VAtoAddr(Image,IsMapped,pExportDir->AddressOfNameOrdinals);

		for (i=0; i< pExportDir->NumberOfNames; ++i)
		if ( m_lstrcmp(RoutineName,(PCHAR)VAtoAddr(Image,IsMapped,AddressOfNames[i])) == 0)
		{
			return AddressOfFunctions[ AddressOfNameOrdinals[i] ] ;
		};
	};
	return NULL;
};