#ifndef _SECCONFIG_H_
#define _SECCONFIG_H_

#define	SECTION_CONFIG_RC4KEY_SIZE	33
#define	SECTION_CONFIG_NAME	".fpbcfg"

typedef struct _SECTION_CONFIG_HEADER
{
	BYTE bRc4Key[SECTION_CONFIG_RC4KEY_SIZE];
	DWORD dwCompressedSize;
	DWORD dwDecompressedSize;
} SECTION_CONFIG_HEADER,*PSECTION_CONFIG_HEADER;

BOOL InsertSectionConfigInPE(PVOID pvPEBase,DWORD dwPESize,PVOID pvData,DWORD dwDataSize,PVOID *ppvNewPE,DWORD *pdwNewPESize);
BOOL GetSectionConfigData(PVOID pvPEBase,PVOID *ppvData,DWORD *pdwDataSize);

#endif