
#ifdef dbgdbg

#ifdef PRINTFDBG

 #define adddeb(...) printf(__VA_ARGS__); printf("\n");

#else

 void adddeb(char *str, ...)
 {
  va_list va;
  va_start(va, str);
  char *buf = _malloc(0xffff);
  _vsprintf(buf, str, va);

  DWORD wr;
  HANDLE h=_CreateFile("peinf.log",GENERIC_WRITE,0,NULL,OPEN_ALWAYS,0,NULL);
  _SetFilePointer(h,0,NULL,FILE_END);
  _WriteFile(h,buf,strlen(buf),&wr,NULL);
  _WriteFile(h,"\n",1,&wr,NULL);
  _CloseHandle(h);

  _free(buf);
 }

 void adddebf(char *fname,char *str, ...)
 {
  va_list va;
  va_start(va, str);
  char *buf = _malloc(0xffff);
  _vsprintf(buf, str, va);

  DWORD wr;
  HANDLE h=_CreateFile("peinf.log",GENERIC_WRITE,0,NULL,OPEN_ALWAYS,0,NULL);
  _SetFilePointer(h,0,NULL,FILE_END);
  _WriteFile(h,buf,strlen(buf),&wr,NULL);
  _WriteFile(h,"\n",1,&wr,NULL);
  _CloseHandle(h);

  _free(buf);
 }

#endif // of PRINTFDBG

#endif // of dbgdbg

