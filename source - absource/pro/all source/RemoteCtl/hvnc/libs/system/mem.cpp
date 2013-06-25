#include "system.h"
#include "mem.h"

static HANDLE hHeap,hThread;
static bool bInit=false;

static void WINAPI HeapDefragThread(void *)
{
    while (bInit)
    {
        SleepEx((1000*60)*5,true);
        HANDLE hHeaps[256];
        DWORD dwCount=GetProcessHeaps(255,hHeaps);
        if ((dwCount) && (dwCount < 256))
        {
            for (DWORD i=0; i < dwCount; i++)
                HeapCompact(hHeaps[i],0);
        }
    }
    return;
}

static bool CheckBlock(void *lpMem)
{
	bool bRet=FALSE;
	if (lpMem)
    {
        char *p=(char*)lpMem-sizeof(DWORD)*2;

        __try
        {
            DWORD dwSize=*(DWORD*)p,
                  *b=(DWORD*)&p[sizeof(DWORD)],
                  *e=(DWORD*)&p[sizeof(DWORD)*2+dwSize];

            if ((*b == BLOCK_ALLOCED) && (*e == BLOCK_ALLOCED))
                bRet=true;
        }
        __except(EXCEPTION_EXECUTE_HANDLER) {}
    }
	return bRet;
}

static bool IsHeap(HANDLE hHeap)
{
    bool bRet=false;

    HANDLE hHeaps[256];
    DWORD dwCount=GetProcessHeaps(255,hHeaps);
    if ((dwCount) && (dwCount < 256))
    {
        for (DWORD i=0; i < dwCount; i++)
        {
            if (hHeaps[i] == hHeap)
            {
                bRet=true;
                break;
            }
        }
    }
    return bRet;
}

void MemInit()
{
    if ((!bInit) || (!IsHeap(hHeap)))
    {
        hHeap=HeapCreate(0,0,0);
        ///DWORD dwHeapInfo=HEAP_LFH;
        ///HeapSetInformation(hHeap,HeapCompatibilityInformation,&dwHeapInfo,sizeof(dwHeapInfo));
        hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)HeapDefragThread,NULL,0,NULL);
        bInit=true;
    }
    return;
}

static void CALLBACK DummyAPCFunc(ULONG_PTR)
{
	return;
}

void MemCleanup()
{
    bInit=false;
    QueueUserAPC(DummyAPCFunc,hThread,0);
    WaitForSingleObject(hThread,INFINITE);
    SysCloseHandle(hThread);
    ///HeapDestroy(hHeap);
    return;
}

static void *InitMemBlock(char *lpMem,size_t dwSize)
{
    *(DWORD*)lpMem=(DWORD)dwSize;
    *(DWORD*)&lpMem[sizeof(DWORD)]=BLOCK_ALLOCED;
    *(DWORD*)&lpMem[dwSize+sizeof(DWORD)*2]=BLOCK_ALLOCED;
    return (void*)(lpMem+sizeof(DWORD)*2);
}

extern "C" void *MemAlloc(size_t dwSize)
{
    if (!bInit)
        MemInit();

    void *lpMem=NULL;
	if (dwSize)
	{
		char *lpTmp=(char*)HeapAlloc(hHeap,HEAP_ZERO_MEMORY,dwSize+sizeof(DWORD)*3);
		if (lpTmp)
            lpMem=InitMemBlock(lpTmp,dwSize);
    }
    return lpMem;
}

extern "C" void *MemRealloc(void *lpMem,size_t dwSize)
{
    if (!bInit)
        return NULL;

    void *lpNewMem=NULL;
	char *lpTmp;
	if (lpMem)
    {
		if (!CheckBlock(lpMem))
			return NULL;
		lpTmp=(char*)lpMem-sizeof(DWORD)*2;
	}
	else
        lpTmp=NULL;

    if (lpTmp)
        lpTmp=(char*)HeapReAlloc(hHeap,HEAP_ZERO_MEMORY,lpTmp,dwSize+sizeof(DWORD)*3);
    else
        lpTmp=(char*)HeapAlloc(hHeap,HEAP_ZERO_MEMORY,dwSize+sizeof(DWORD)*3);

    if (lpTmp)
        lpNewMem=InitMemBlock(lpTmp,dwSize);
    return lpNewMem;
}

extern "C" void MemFree(void *lpMem)
{
    if (!bInit)
        return;

    if (CheckBlock(lpMem))
    {
        char *lpTmp=(char*)lpMem-sizeof(DWORD)*2;
        DWORD dwSize=*(DWORD*)lpTmp;
        *(DWORD*)&lpTmp[sizeof(DWORD)]=BLOCK_FREED;
        *(DWORD*)&lpTmp[dwSize+sizeof(DWORD)*2]=BLOCK_FREED;
        HeapFree(hHeap,0,lpTmp);
    }
    return;
}
