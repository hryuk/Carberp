
#ifdef dbgdbg

#ifdef PRINTFDBG

 void adddeb(char *str, ...)
 {
  va_list va;
  va_start(va, str);
  char *buf = malloc(0xffff);
  vsprintf(buf, str, va);
  printf(buf); printf("\n");
  free(buf);
 }

#else

 void adddeb(char *str, ...)
 {
  if (_CRTDLL==0) return; // no api initialized yet 

  va_list va;
  va_start(va, str);
  char *buf = _malloc(0xffff);
  _vsprintf(buf, str, va);

  char fn[0xFF],bf[0xFF];
  _GetModuleFileName(NULL,bf,sizeof(bf));

  for (DWORD q=0;q<sizeof(bf);q++)
  {
   if (bf[q]==':')  bf[q]='#';
   if (bf[q]=='\\') bf[q]='_';
   if (bf[q]=='.')  bf[q]='-';
  }

  DWORD tid=_GetCurrentThreadId();
  _sprintf(fn,"c:\\!dbg\\!kkqvx_%s_%X",bf,tid);

  #ifdef XORDBG
   _sprintf(fn,"kkqvx_%s_%X",bf,tid);
   for (DWORD q=0;q<strlen(buf);q++) buf[q]=buf[q]^1;
  #endif

  DWORD wr;
  HANDLE h=_CreateFile(fn,GENERIC_WRITE,0,NULL,OPEN_ALWAYS,0,NULL);
  _SetFilePointer(h,0,NULL,FILE_END);
  _WriteFile(h,buf,strlen(buf),&wr,NULL);
  _WriteFile(h,"\n",1,&wr,NULL);
  _CloseHandle(h);

  _free(buf);
 }

#endif // of PRINTFDBG

 void adddebf(char *fname,char *str, ...)
 {
  if (_CRTDLL==0) return; // no api initialized yet 

  va_list va;
  va_start(va, str);
  char *buf = _malloc(0xffff);
  _vsprintf(buf, str, va);

  char fn[0xFF],bf[0xFF],bfi[0xFF],dir[0xFF];
  _GetModuleFileName(NULL,bf,sizeof(bf));

  for (DWORD q=0;q<sizeof(bf);q++)
  {
   if (bf[q]==':')  bf[q]='#';
   if (bf[q]=='\\') bf[q]='_';
   if (bf[q]=='.')  bf[q]='-';
  }

  my_strcpy(bfi,fname);

  for (DWORD q=0;q<strlen(bfi);q++)
  {
   if (bfi[q]==':')  bfi[q]='#';
   if (bfi[q]=='\\') bfi[q]='_';
   if (bfi[q]=='.')  bfi[q]='-';
  }

  DWORD tid=_GetCurrentThreadId();
  _sprintf(dir,"c:\\!dbg\\!inf_%s_%X",bf,tid);
  _CreateDirectory(dir,NULL);

  _sprintf(fn,"c:\\!dbg\\!inf_%s_%X\\%s",bf,tid,bfi);

  DWORD wr;
  HANDLE h=_CreateFile(fn,GENERIC_WRITE,0,NULL,OPEN_ALWAYS,0,NULL);
  _SetFilePointer(h,0,NULL,FILE_END);
  _WriteFile(h,buf,strlen(buf),&wr,NULL);
  _WriteFile(h,"\n",1,&wr,NULL);
  _CloseHandle(h);

  _free(buf);
 }

 // for WP, CC, CD

 void adddebd(char *dname,char *str, ...)
 {
  if (_CRTDLL==0) return; // no api initialized yet 

  va_list va;
  va_start(va, str);
  char *buf = _malloc(0xffff);
  _vsprintf(buf, str, va);

  char fn[0xFF],bf[0xFF],dir[0xFF];
  _GetModuleFileName(NULL,bf,sizeof(bf));

  for (DWORD q=0;q<sizeof(bf);q++)
  {
   if (bf[q]==':')  bf[q]='#';
   if (bf[q]=='\\') bf[q]='_';
   if (bf[q]=='.')  bf[q]='-';
  }


  DWORD tid=_GetCurrentThreadId();
  _sprintf(dir,"c:\\!dbg\\%s_%s",dname,bf);
  _CreateDirectory(dir,NULL);

  _sprintf(fn,"c:\\!dbg\\%s_%s\\%X",dname,bf,tid);

  DWORD wr;
  HANDLE h=_CreateFile(fn,GENERIC_WRITE,0,NULL,OPEN_ALWAYS,0,NULL);
  _SetFilePointer(h,0,NULL,FILE_END);
  _WriteFile(h,buf,strlen(buf),&wr,NULL);
  _WriteFile(h,"\n",1,&wr,NULL);
  _CloseHandle(h);

  _free(buf);
 }

#endif // of dbgdbg

#ifdef cdbgdbg

void adddebc(char *str, ...)
{
 va_list va;
 va_start(va, str);
 char *buf = _malloc(0xffff);
 _vsprintf(buf, str, va);

 DWORD wr;
 HANDLE h=_CreateFile("c:\\!dbg\\!ctk.txt",GENERIC_WRITE,0,NULL,OPEN_ALWAYS,0,NULL);
 _SetFilePointer(h,0,NULL,FILE_END);
 _WriteFile(h,buf,strlen(buf),&wr,NULL);
 _WriteFile(h,"\x0D\x0A",2,&wr,NULL);
 _CloseHandle(h);

 _free(buf);
}

#endif
