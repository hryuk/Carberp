#include <windows.h>
#include <stdio.h>
#include <io.h>

#include "minizip.h"

void *malloc(size_t dwSize)
{
    return HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,dwSize);
}

void free(void *lpMem)
{
    if (lpMem)
    {
        if (HeapValidate(GetProcessHeap(),0,lpMem))
            HeapFree(GetProcessHeap(),0,lpMem);
    }
    return;
}

void strip_path(char *filename, char *stripped_name)
{
	char	*p;

	p = strrchr(filename, '\\');

	if (p == NULL)
		strcpy(stripped_name, filename);
	else
		strcpy(stripped_name, p+1);
}

void main(int argc, char* argv[])
{
    if (argc < 4)
    {
        printf("usage: zip_store.exe zipfile password file1 [<file2> .. <fileN>]\n");
        return;
    }

    if (GetFileAttributes(argv[1]) != INVALID_FILE_ATTRIBUTES)
        DeleteFile(argv[1]);

    char szPath[MAX_PATH],szCabFile[MAX_PATH];
    GetCurrentDirectory(MAX_PATH,szPath);
    wsprintf(szCabFile,"%s\\%s",szPath,argv[1]);

    HZIP hZip=CreateArchive(szCabFile,argv[2],lstrlen(argv[2]),9);
    for (int i=0; i < argc-3; i++)
	{
		char stripped_name[256];

		strip_path(argv[i+3], stripped_name);

        ArchAddFile(hZip,argv[i+3],stripped_name);
	}
    ArchClose(hZip);

    return;
}

