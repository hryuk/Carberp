#include "includes.h"
#include "func.h"

void *malloc(size_t dwSize)
{
    return MemAlloc(dwSize);
}

void *realloc(void *lpMem,size_t dwSize)
{
    return MemRealloc(lpMem,dwSize);
}

void free(void *lpMem)
{
    MemFree(lpMem);
    return;
}

#pragma function(memcpy)
LPVOID memcpy(void *dst,const void *src,size_t count)
{
    if ((!dst) || (!src) || (!count))
        return NULL;

    while (count--)
    {
        *(char *)dst = *(char *)src;
        dst = (char *)dst + 1;
        src = (char *)src + 1;
    }
    return dst;
}

void RemoveFileA(char *lpFile)
{
    int dwCount=0;
    SetFileAttributesA(lpFile,FILE_ATTRIBUTE_NORMAL);
    do
    {
        Sleep(1);
        DeleteFileA(lpFile);
        if (dwCount++ > 20)
            break;
    }
    while (GetLastError() != ERROR_FILE_NOT_FOUND);
    return;
}

