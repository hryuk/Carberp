#pragma once

#include <windows.h>
#include <fci.h>
#include <io.h>
#include <fcntl.h>

typedef void* HCAB;

typedef struct 
{
	ERF erf;
	CCAB cab;
	HFCI hfci;
} CABDATA, *PCABDATA;

HCAB CreateCab( const char *szCabName );
bool AddFileToCab( HCAB handle, const char *szFileName, const char *szInternalName );
void CloseCab( HCAB handle );
bool AddDirToCab( HCAB handle, const char *szDirName, const char *szInternalName );
void Test();
void CAB_Test2();
char *GetTempNameA();
//int sizeRecurseFolder(char* Absolute, char* Relative, char* ext, HCAB hCab);
