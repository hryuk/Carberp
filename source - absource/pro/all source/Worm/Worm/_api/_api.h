
///////////////////////////////////////////////////////
// Init IP by string

//sample: 
// DWORD  *adr[] = {&_OpenMutex, &_CloseHandle,&_ExitThread,&_CreateFile};
// InitAPIbyStr(adr,KERNEL32,"/*@S|*/00OpenMutexA|01CloseHandle|02ExitThread/*@E*/|");

#ifdef _MSC_VER
	#pragma optimize("", off)
#else
	#pragma optimize(off)
#endif

void InitAPIbyStr(DWORD *adr[], HANDLE h, char *data)
{ 
	DWORD q = 0; //@S
	DWORD f = 0; //@E //func pointer

	if (/*@S==*/data[0]=='/'/*@E*/) 
		{ q=7; f=7; } // skip '/*@S|*/' construction

	loop:;
		if (/*@S==*/data[q]==0/*@E*/) return;                 //@S
		if (/*@S==*/data[q]=='/'/*@E*/) { data[q]=0; q+=6; } //@E // skip '/*@E*/' construction

		if (/*@S==*/data[q]==124/*@E*/)      // end of func name, '|'==124
		{
			 DWORD n = 0; //@E
			 data[q] = 0; //@S    

			 n += (data[f]-48)*10;             //@S  // '0'==48, we split calculation in 2 lines
			 n += (data[/*@S+*/f+1/*@E*/]-48); //@E  // to prevent lcc "long calc result=0" bug
			                                       // bonus: improved mutation  
			 
			 //  printf("%u:'%s' _GetProcAddress:%X\n",n,&data[f+2],_GetProcAddress);
			 *(adr[n]) = (DWORD)_GetProcAddress(h, &data[/*@S+*/ f + 2 /*@E*/]);
	  

			 f = /*@S+*/ q + 1 /*@E*/;
		}

		q++;
	
	goto loop;
}

#ifdef _MSC_VER
	#pragma optimize("", on)
#else
	#pragma optimize(on)
#endif