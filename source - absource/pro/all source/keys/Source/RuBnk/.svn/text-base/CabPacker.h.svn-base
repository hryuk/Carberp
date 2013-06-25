#ifndef CabPackerH
#define CabPackerH
//----------------------------------------------------------------------------

#include <windows.h>
#include <fci.h>
#include <io.h>
#include <fcntl.h>

typedef void* HCAB;



HCAB CreateCab(const char *szCabName );
void CloseCab(HCAB handle );

bool AddFileToCab( HCAB handle, const char *szFileName, const char *szInternalName );
bool AddDirToCab( HCAB handle, const char *szDirName, const char *szInternalName );

// Функция добавляет данные из памяти в каб архив
bool AddBlobToCab( HCAB Handle, LPVOID Data, DWORD DataSize, PCHAR InternalName);

//void Test();


//----------------------------------------------------------------------------
#endif