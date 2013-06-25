//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BK driver loader project. Version 2.
//	
// module: main.h
// description: 
//	Common includes, constants and predifinitions.

#pragma once

#include <stdio.h>
#include <windows.h>
#include <tchar.h>

#pragma warning(push)
#pragma warning(disable:4005) // macro redefinition
#include "ntdll.h"
#include <ntstatus.h>
#pragma warning(pop)

#define	PAGE_SIZE	0x1000


// DbgPrint() and checked heap allocations
#include "dbg.h"

// Lists support 
#include "listsup.h"

// Usefull types
typedef INT	WINERROR;					// One of the Windows error codes defined within winerror.h
#define ERROR_UNSUCCESSFULL	0xffffffff	// Common unsuccessfull code

// Macros
#define MAX_PATH_BYTES (MAX_PATH*sizeof(_TCHAR))

// constant string length
#define	cstrlenA(str)	(sizeof(str)-1)
#define	cstrlenW(str)	(sizeof(str)-sizeof(WCHAR))/sizeof(WCHAR)

#if _UNICODE
	#define cstrlen(str)	cstrlenW(str)
#else
	#define cstrlen(str)	cstrlenA(str)
#endif

#define APP_VERSION	1


_inline ULONG rand32(VOID)
{
	return(((rand()%0x100) << 24) + ((rand()%0x100) << 16) + ((rand()%0x100) << 8) + (rand()%0x100));
}

