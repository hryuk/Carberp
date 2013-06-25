#include <windows.h>
#include <stdio.h>
#include <imagehlp.h>

#include "ntdll.h"
#include "utils.h"
#include "secconfig.h"
#include "rc4.h"

BOOL CompressBuffer(PVOID pvInputBuffer,DWORD dwInputBufferSize,PVOID *ppvOutputBuffer,PDWORD pdwOutputBufferSize)
{
	BOOL bRet = FALSE;
	DWORD dwCompressBufferWorkSpaceSize;
	DWORD dwCompressFragmentWorkSpaceSize;
	NTSTATUS St;

	St = RtlGetCompressionWorkSpaceSize(COMPRESSION_FORMAT_LZNT1|COMPRESSION_ENGINE_STANDARD,&dwCompressBufferWorkSpaceSize,&dwCompressFragmentWorkSpaceSize);
	if (NT_SUCCESS(St))
	{
		PVOID pvWorkSpace = malloc(dwCompressBufferWorkSpaceSize);
		if (pvWorkSpace)
		{
			PVOID pvCompressedBuffer = malloc(ALIGN_UP(dwInputBufferSize,0x1000));
			if (pvCompressedBuffer)
			{
				St = RtlCompressBuffer(COMPRESSION_FORMAT_LZNT1|COMPRESSION_ENGINE_STANDARD,pvInputBuffer,dwInputBufferSize,pvCompressedBuffer,ALIGN_UP(dwInputBufferSize,0x1000),0x1000,pdwOutputBufferSize,pvWorkSpace);
				if (bRet = NT_SUCCESS(St))
				{
					*ppvOutputBuffer = pvCompressedBuffer;
				}
				else
				{
					DbgPrint(__FUNCTION__"(): RtlCompressBuffer failed with status %lx\n",St);

					free(pvCompressedBuffer);
				}
			}

			free(pvWorkSpace);
		}
	}
	else
	{
		DbgPrint(__FUNCTION__"(): RtlGetCompressionWorkSpaceSize failed with status %lx\n",St);
	}

	return bRet;
}

BOOL DecompressBuffer(PVOID pvInputBuffer,DWORD dwInputBufferSize,PVOID *ppvOutputBuffer,DWORD dwOutputBufferSize)
{
	BOOL bRet = FALSE;
	PVOID pvOutputBuffer;
	DWORD dwDecompressedSize;
	NTSTATUS St;

	if (pvOutputBuffer = malloc(dwOutputBufferSize))
	{
		St = RtlDecompressBuffer(COMPRESSION_FORMAT_LZNT1,pvOutputBuffer,dwOutputBufferSize,pvInputBuffer,dwInputBufferSize,&dwDecompressedSize);
		if (NT_SUCCESS(St))
		{
			bRet = dwDecompressedSize == dwOutputBufferSize;

			if (bRet) *ppvOutputBuffer = pvOutputBuffer;
		}
		else
		{
			DbgPrint(__FUNCTION__"(): RtlDecompressBuffer failed with status %lx\n",St);
		}

		if (!bRet) free(pvOutputBuffer);
	}

	return bRet;
}

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

PIMAGE_SECTION_HEADER GetVirtualyLastSectionHeader(PIMAGE_NT_HEADERS pNtHeaders)
{
	PIMAGE_SECTION_HEADER pFirstSection = IMAGE_FIRST_SECTION(pNtHeaders);

	return &pFirstSection[pNtHeaders->FileHeader.NumberOfSections - 1];
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
	PVOID pvCompressedData;
	DWORD dwCompressedDataSize;
	PVOID pvConfigData;
	DWORD dwConfigDataSize;
	DWORD dwSeed = GetTickCount();
	PIMAGE_SECTION_HEADER pNewSection;
	DWORD dwSize;

	if (CompressBuffer(pvData,dwDataSize,&pvCompressedData,&dwCompressedDataSize))
	{
		dwConfigDataSize = dwCompressedDataSize + sizeof(SECTION_CONFIG_HEADER);

		if (pvConfigData = malloc(dwConfigDataSize))
		{
			PSECTION_CONFIG_HEADER pSecCfgHeader = (PSECTION_CONFIG_HEADER)pvConfigData;

			pSecCfgHeader->dwDecompressedSize = dwDataSize;
			pSecCfgHeader->dwCompressedSize = dwCompressedDataSize;

			for (int i = 0; i < sizeof(pSecCfgHeader->bRc4Key); i++) 
			{
				pSecCfgHeader->bRc4Key[i] = (BYTE)RtlRandom(&dwSeed);
			}

			EncryptRc4(pSecCfgHeader->bRc4Key,sizeof(pSecCfgHeader->bRc4Key),&pSecCfgHeader[1],pvCompressedData,dwCompressedDataSize);

			if (pNewSection = InsertSectionHeader(pvPEBase,SECTION_CONFIG_NAME,dwConfigDataSize,IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ,&dwSize))
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

					memcpy((PVOID)((DWORD)pvNewPE + pNewSection->PointerToRawData),pvConfigData,dwConfigDataSize);

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

			free(pvConfigData);
		}
	
		free(pvCompressedData);
	}

	return bRet;
}

BOOL GetSectionConfigData(PVOID pvPEBase,PVOID *ppvData,DWORD *pdwDataSize)
{
	BOOL bRet = FALSE;
	PIMAGE_SECTION_HEADER pvSection;

	if (pvSection = SearchSection(pvPEBase,SECTION_CONFIG_NAME))
	{
		PSECTION_CONFIG_HEADER pSecCfgHeader = MAKE_PTR(pvPEBase,pvSection->VirtualAddress,PSECTION_CONFIG_HEADER);
		PVOID pvDecryptedData;

		if (pvDecryptedData = malloc(pSecCfgHeader->dwCompressedSize))
		{
			EncryptRc4(pSecCfgHeader->bRc4Key,sizeof(pSecCfgHeader->bRc4Key),pvDecryptedData,&pSecCfgHeader[1],pSecCfgHeader->dwCompressedSize);
		
			if (bRet = DecompressBuffer(pvDecryptedData,pSecCfgHeader->dwCompressedSize,ppvData,pSecCfgHeader->dwDecompressedSize))
			{
				*pdwDataSize = pSecCfgHeader->dwDecompressedSize;
			}

			free(pvDecryptedData);
		}
	}

	return bRet;
}