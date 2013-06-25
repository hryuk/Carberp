#include "..\includes.h"

void WaitThreadsDeath(PHVNC lpServer)
{
    EnterCriticalSection(&lpServer->ThreadsInfo.csThreads);
    {
        for (int i=0; i < lpServer->ThreadsInfo.dwThreadsCount; i++)
        {
            if (WaitForSingleObject(lpServer->ThreadsInfo.hThreads[i],1000) == WAIT_TIMEOUT)
                TerminateThread(lpServer->ThreadsInfo.hThreads[i],1);
            SysCloseHandle(lpServer->ThreadsInfo.hThreads[i]);
            lpServer->ThreadsInfo.hThreads[i]=NULL;
        }
        lpServer->ThreadsInfo.dwThreadsCount=0;
    }
    LeaveCriticalSection(&lpServer->ThreadsInfo.csThreads);
    return;
}

void SysCreateThread(PHVNC lpServer,LPTHREAD_START_ROUTINE lpAddress,LPVOID Param,bool bSaveHandle,DWORD dwPriori,HANDLE *phThread)
{
    HANDLE hThread=CreateThread(NULL,0,lpAddress,Param,CREATE_SUSPENDED,NULL);
    SetThreadPriority(hThread,dwPriori);
    ResumeThread(hThread);
    if ((!bSaveHandle) && (!phThread))
        SysCloseHandle(hThread);
    else
    {
        if (bSaveHandle)
        {
            EnterCriticalSection(&lpServer->ThreadsInfo.csThreads);
                lpServer->ThreadsInfo.hThreads[lpServer->ThreadsInfo.dwThreadsCount++]=hThread;
            LeaveCriticalSection(&lpServer->ThreadsInfo.csThreads);
        }
        if (phThread)
            *phThread=hThread;
    }
    return;
}

unsigned int MurmurHash2 (char * key, unsigned int len)
{
    const unsigned int m = 0x5bd1e995;
    const unsigned int seed = 0;
    const int r = 24;
    unsigned int h = seed ^ len;
    const unsigned char * data = (const unsigned char *)key;

    while (len >= 4)
    {
        unsigned int k;

        k  = data[0];
        k |= data[1] << 8;
        k |= data[2] << 16;
        k |= data[3] << 24;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len)
    {
    case 3:
        h ^= data[2] << 16;
    case 2:
        h ^= data[1] << 8;
    case 1:
        h ^= data[0];
        h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

