// InjectDLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

extern bool InjectDLL( const char* nameProcess, const char* pathDll, const char* func );

int _tmain(int argc, _TCHAR* argv[])
{
	if( argc != 4 )
	{
		printf( "Format command:\n\tInjectDLL.exe 'Name process' 'Path Dll' 'Name func dll'");
		return 0;
	}
	if( InjectDLL( argv[1], argv[2], argv[3] ) )
		return 0; 
	return 1;
}

