#ifndef CabPackerH
#define CabPackerH
//----------------------------------------------------------------------------

#include <windows.h>
#include <fci.h>
#include <io.h>
#include <fcntl.h>
#include "Strings.h"

typedef void* HCAB;



HCAB CreateCab(const char *szCabName );
void CloseCab(HCAB handle );

bool        AddFileToCab(HCAB handle, const char *szFileName, const char *szInternalName);
bool inline AddFileToCab(HCAB Handle, const char *FileName, const string& InternalName) {return AddFileToCab(Handle, FileName, InternalName.t_str()); }

bool AddDirToCab( HCAB handle, const char *szDirName, const char *szInternalName );

// Функция добавляет данные из памяти в каб архив с именем файла FileName
bool        AddBlobToCab(HCAB Handle, LPVOID Data, DWORD DataSize, PCHAR FileName);
bool inline AddBlobToCab(HCAB Handle, LPVOID Data, DWORD DataSize, const string& FileName) { return AddBlobToCab(Handle, Data, DataSize, FileName.t_str()); }

// Функция добавляет строковые данные в каб архив с именем файла FileName
bool inline AddStringToCab(HCAB Handle, const string& Data, PCHAR FileName)         { return AddBlobToCab(Handle, Data.t_str(), Data.Length(), FileName); }
bool inline AddStringToCab(HCAB Handle, const string& Data, const string& FileName) { return AddBlobToCab(Handle, Data.t_str(), Data.Length(), FileName.t_str()); }

//распаковка каба nameCab в папку path
bool ExtractCab( const char* nameCab, const char* path, const char** renames = 0 );

//----------------------------------------------------------------------------
#endif