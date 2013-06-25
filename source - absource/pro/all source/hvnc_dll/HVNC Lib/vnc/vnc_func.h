#ifndef VNC_FUNC_H_INCLUDED
#define VNC_FUNC_H_INCLUDED

void WaitThreadsDeath(PHVNC lpServer);
void SysCreateThread(PHVNC lpServer,LPTHREAD_START_ROUTINE lpAddress,LPVOID Param,bool bSaveHandle=false,DWORD dwPriori=THREAD_PRIORITY_BELOW_NORMAL,HANDLE *phThread=NULL);
unsigned int MurmurHash2 (char * key, unsigned int len);

#endif // VNC_FUNC_H_INCLUDED
