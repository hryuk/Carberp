#ifndef ComandLoadDLLH
#define ComandLoadDLLH
//----------------------------------------------------------------------------

#include <windows.h>
#include "Strings.h"
#include "Memory.h"
#include "Utils.h"
#include "Config.h"
#include "Loader.h"
#include "GetApi.h"
#include "DllLoader.h"
//loaddll url funcname parametrs до 4х штук
	//char gzip_deflate[] = {'g','z','i','p',',','d','e','f','l','a','t','e',0};
	static char CommandLoadDllConnect[] =  {'l','o','a','d','d','l','l','s',0};
	bool ExecuteAllCommand(LPVOID Manager, PCHAR Command, PCHAR Args);
	
//----------------------------------------------------------------------------
#endif
