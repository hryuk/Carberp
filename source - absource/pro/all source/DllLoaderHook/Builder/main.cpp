#include <windows.h>
#include <stdio.h>
#include "sec.h"

void CreatePathFile(const char* path, const char* name, char* res)
{
	if( strchr( name, '\\' ) == 0 && strchr( name, '/' ) == 0 )
		lstrcpy( res, path );
	else
		res[0] = 0;
	lstrcat( res, name );
}

char* LoadFile(const char* nameFile, int& sz)
{
	HANDLE fin = CreateFile( nameFile, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0 );
	if( fin == INVALID_HANDLE_VALUE )
		return 0;
	sz = GetFileSize( fin, 0 );
	char* ret = (char*)LocalAlloc(LMEM_FIXED, sz);
	DWORD rl;
	ReadFile( fin, ret, sz, &rl, 0 );
	CloseHandle(fin);
	return ret;
}

void SaveFile( const char* nameFile, char* data, int sz )
{
	HANDLE fout = CreateFile( nameFile, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0 );
	if( fout == INVALID_HANDLE_VALUE )
		return;
	DWORD rl;
	WriteFile( fout, data, sz, &rl, 0 );
	CloseHandle(fout);
}

int main(int argc, char* argv[])
{
	if( argc != 3 )
	{
		printf( "needed two params" );
		return 0;
	}
	char nameOutput[MAX_PATH], nameDll[MAX_PATH], nameDllLoader[MAX_PATH], nameDllInject[MAX_PATH];
	int l = lstrlen(argv[0]);
	while( argv[0][l] != '\\' && argv[0][l] != '/' ) l--;
	argv[0][l + 1] = 0;
	CreatePathFile( argv[0], argv[1], nameDll );
	CreatePathFile( argv[0], argv[2], nameOutput );
	CreatePathFile( argv[0], "DllLoader.exe", nameDllLoader );
	CreatePathFile( argv[0], "DllInject.dll", nameDllInject );

	int szDll;
	char* dll = LoadFile(nameDll, szDll);
	if( dll == 0 ) printf( "not load %s\n", nameDll );
	int szDllLoader;
	char* dllLoader = LoadFile(nameDllLoader, szDllLoader);
	if( dllLoader == 0 ) printf( "not load %s\n", nameDllLoader );
	int szDllInject;
	char* dllInject = LoadFile(nameDllInject, szDllInject);
	if( dllInject == 0 ) printf( "not load %s\n", nameDllInject );

	if( dll != 0 && dllLoader != 0 && dllInject != 0 )
	{
		//сначала влаживаем dll в dllInject
		char* data = (char*)LocalAlloc( LMEM_FIXED, szDll + sizeof(int) );
		*((int*)data) = szDll;
		memcpy( data + sizeof(int), dll, szDll );
		char* resDll;
		DWORD szResDll;
		if( InsertSectionConfigInPE( dllInject, szDllInject, data, szDll + sizeof(int), (PVOID*)(&resDll), &szResDll ) )
		{
			LocalFree(data);
			data = (char*)LocalAlloc( LMEM_FIXED, szResDll + sizeof(int) );
			*((int*)data) = szResDll;
			memcpy( data + sizeof(int), resDll, szResDll );
			char* resExe;
			DWORD szResExe;
			if( InsertSectionConfigInPE( dllLoader, szDllLoader, data, szResDll + sizeof(int), (PVOID*)(&resExe), &szResExe ) )
			{
				SaveFile( nameOutput, resExe, szResExe );
				free(resExe);
			}
			else
				printf("error put DllInject.dll in DllLoader.exe\n");
			free(resDll);
		}
		else
			printf( "error put you DLL in DllInject.dll\n" );

		LocalFree(data);
	}
	LocalFree(dll);
	LocalFree(dllLoader);
	LocalFree(dllInject);
}

