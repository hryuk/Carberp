// CliStart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


typedef void (WINAPI *PStartClient)( char *Server, int Port, char *Uid, int BrowserType );


int main(int argc, char* argv[])
{
	HMODULE hm = LoadLibraryA( "DrClient.dll" );
	PStartClient proc = (PStartClient)GetProcAddress( hm, "StartClient" );
	DWORD err = GetLastError();
	proc( "127.0.0.1", 711, "dddddd", 0 );
}

