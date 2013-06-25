#include "common.h"

extern "C" HZIP OpenArchiveW(WCHAR *lpstrZipFile,char *lpPassword,int dwPasswordLen,bool bZipInMem,int dwFileSize)
{
    void *r=NULL;
    if (lpstrZipFile)
    {
        ZIPDECOMPRESSION *p=(ZIPDECOMPRESSION*)_alloc(sizeof(ZIPDECOMPRESSION));
        p->bHandleType=HT_DECOMPRESSOR;
        if (p)
        {
            zlib_filefunc64_def ffunc;

            p->bInMem=bZipInMem;
            if (!bZipInMem)
                fill_fopen64_filefunc(&ffunc);
            else
            {
                fill_memory_filefunc(&ffunc);

                char filePath[30];
                wsprintfA(filePath,"%x+%x",(int)lpstrZipFile,dwFileSize);
                lpstrZipFile=(WCHAR*)filePath;
            }

            if (((lpPassword) && (dwPasswordLen > 0)))
            {
                p->bEncrypted=true;
                memcpy(p->szPassword,lpPassword,dwPasswordLen);
            }

            p->hZip=unzOpen2_64(lpstrZipFile,&ffunc);
            if (p->hZip)
                r=p;
        }
        if (!r)
            MemFree(p);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

extern "C" HZIP OpenArchiveA(char *lpstrZipFile,char *lpPassword,int dwPasswordLen,bool bZipInMem,int dwFileSize)
{
    HZIP hZip=0;
    if (lpstrZipFile)
    {
        LPWSTR pwstrPath;
        if (!bZipInMem)
            pwstrPath=AnsiToUnicodeEx(lpstrZipFile,-1);
        else
            pwstrPath=(LPWSTR)lpstrZipFile;

        hZip=OpenArchiveW(pwstrPath,lpPassword,dwPasswordLen,bZipInMem,dwFileSize);

        if (!bZipInMem)
            MemFree(pwstrPath);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return hZip;
}

int ExtractCurrentFile(HZIP hZip,bool bSkipPath)
{
    int r=-1;
    char filename_inzip[256];
    unz_file_info64 file_info;
    ZIPDECOMPRESSION *p=(ZIPDECOMPRESSION*)hZip;
    int err=unzGetCurrentFileInfo64(p->hZip,&file_info,filename_inzip,sizeof(filename_inzip),NULL,0,NULL,0);
    if (err == UNZ_OK)
    {
        bool bEncrypted=((file_info.flag & 1) != 0);
        if ((bEncrypted) && (!p->bEncrypted))
        {
            ArchSetLastError(ARCH_ZIP_IS_ENCRYPTED);
            return -1;
        }

        char *lpPassword=((bEncrypted) && (p->bEncrypted)) ? p->szPassword : 0;
        int err=unzOpenCurrentFilePassword(p->hZip,lpPassword);
        if (err == UNZ_OK)
        {
            void *buf=_alloc(INT_BUF_SIZE);
            if (buf)
            {
                if (p->bExctractToMem)
                {
                    p->lpMem=VirtualAlloc(NULL,file_info.uncompressed_size,MEM_COMMIT,PAGE_READWRITE);
                    p->dwSize=file_info.uncompressed_size;
                    byte *pMem=(byte*)p->lpMem;
                    if (p->lpMem)
                    {
                        do
                        {
                            err=unzReadCurrentFile(p->hZip,pMem,INT_BUF_SIZE);
                            if (err < 0)
                            {
                                VirtualFree(p->lpMem,file_info.uncompressed_size,MEM_DECOMMIT);
                                break;
                            }
                            pMem+=err;
                        }
                        while (err > 0);
                    }
                    else
                        ArchSetLastError(ARCH_NO_MEM);

                    if (!err)
                        r=1;
                }
                else
                {
                    WCHAR *unicode_filename_inzip=OemToUnicodeEx(filename_inzip,-1),
                          file_to_store[MAX_PATH],
                          destPath[MAX_PATH],
                          *filename=unicode_filename_inzip;
                    if (bSkipPath)
                    {
                        WCHAR *p,*filename_withoutpath;
                        p=filename_withoutpath=unicode_filename_inzip;
                        while ((*p) != '\0')
                        {
                            if ((*p == '/') || (*p == '\\'))
                                filename_withoutpath=p+1;
                            p++;
                        }
                        filename=filename_withoutpath;
                    }

                    int dwLen=wsprintfW(destPath,L"%s\\%s",p->strOutputDir,filename);
                    for (int i=0; i < dwLen; i++)
                    {
                        if (destPath[i] == '/')
                            destPath[i]='\\';
                    }
                    lstrcpyW(file_to_store,destPath);
                    if (PathRemoveFileSpecW(destPath) != FALSE)
                        CreateDirectoryTree(destPath);
                    MemFree(unicode_filename_inzip);

                    HANDLE fout=CreateFileW(file_to_store,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,NULL);
                    do
                    {
                        DWORD dwSize;
                        err=unzReadCurrentFile(p->hZip,buf,INT_BUF_SIZE);
                        if (err < 0)
                            break;
                        if (!WriteFile(fout,buf,err,&dwSize,0))
                        {
                            err=-1;
                            break;
                        }
                    }
                    while (err > 0);
                    SysCloseHandle(fout);
                    if (!err)
                    {
                        change_file_date(file_to_store,file_info.dosDate,file_info.tmu_date);
                        r=1;
                    }
                    else
                        DeleteFileW(file_to_store);
                }
                MemFree(buf);
            }
            unzCloseCurrentFile(p->hZip);
        }
    }
    return r;
}

int InternalEnumFiles(HZIP hZip)
{
    int r=-1;
    unz_global_info64 gi;
    ZIPDECOMPRESSION *p=(ZIPDECOMPRESSION*)hZip;
    int err=unzGetGlobalInfo64(p->hZip,&gi);
    if (err == UNZ_OK)
    {
        for (uLong i=0; i<gi.number_entry; i++)
        {
            char filename_inzip[256];
            unz_file_info64 file_info;
            err=unzGetCurrentFileInfo64(p->hZip,&file_info,filename_inzip,sizeof(filename_inzip),NULL,0,NULL,0);
            if (err == UNZ_OK)
            {
                LPWSTR sourceFile=OemToUnicodeEx(filename_inzip,-1);

                if (p->bOnlyEnum)
                {
                    if (!p->bEnumAnsi)
                        r=(p->lpEnumProc(sourceFile)) ? 0 : -1;
                    else
                    {
                        char ansi_filename_inzip[256];
                        OemToAnsi(filename_inzip,ansi_filename_inzip);
                        r=(p->lpEnumProc((LPWSTR)ansi_filename_inzip)) ? 0 : -1;
                    }
                }
                else
                    r=ExtractCurrentFile(hZip,false);

                MemFree(sourceFile);
            }
            unzGoToNextFile(p->hZip);
        }
    }
    return r;
}

extern "C" bool ArchExtractFilesW(HZIP hZip,WCHAR *pstrPath)
{
    bool r=false;
    ZIPDECOMPRESSION *p=(ZIPDECOMPRESSION*)hZip;
    if ((hZip) && (pstrPath) && (p->bHandleType == HT_DECOMPRESSOR))
    {
        lstrcpyW(p->strOutputDir,pstrPath);

        unzGoToFirstFile(p->hZip);

        if (!p->bInMem)
        {
            WCHAR filePath[MAX_PATH],fileName[MAX_PATH],*pstrFile;

            lstrcpyW(filePath,p->strZipFile);
            pstrFile=PathFindFileNameW(filePath);
            PathRemoveFileSpecW(filePath);

            lstrcpyW(fileName,pstrFile);
            PathAddBackslashW(filePath);
        }
        r=(InternalEnumFiles(hZip) < 0) ? false : true;
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

extern "C" bool ArchExtractFilesA(HZIP hZip,char *pstrPath)
{
    bool r=false;
    if ((hZip) && (((ZIPDECOMPRESSION *)hZip)->bHandleType == HT_DECOMPRESSOR) && (pstrPath))
    {
        LPWSTR pwstrPath=AnsiToUnicodeEx(pstrPath,-1);
        r=ArchExtractFilesW(hZip,pwstrPath);
        MemFree(pwstrPath);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

extern "C" bool ArchGetFileW(HZIP hZip,WCHAR *pstrFile,byte **lpMem,int *dwSize)
{
    bool r=false;
    ZIPDECOMPRESSION *p=(ZIPDECOMPRESSION *)hZip;
    if ((hZip) && (p->bHandleType == HT_DECOMPRESSOR) && (pstrFile) && (lpMem) && (dwSize))
    {
        LPCSTR pFileName=UnicodeToOemEx(pstrFile,-1);
        unzGoToFirstFile(p->hZip);
        p->bExctractToMem=true;

        if (unzLocateFile(p->hZip,pFileName,CASESENSITIVITY) == UNZ_OK)
            r=(ExtractCurrentFile(hZip,true) > -1) ? true : false;
        else
        {
            ArchSetLastError(ARCH_FILE_NOT_FOUND);
            r=false;
        }
        MemFree((void*)pFileName);

        if (r)
        {
            *lpMem=(byte*)p->lpMem;
            *dwSize=p->dwSize;
        }
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;

}

extern "C" bool ArchGetFileA(HZIP hZip,char *pstrFile,byte **lpMem,int *dwSize)
{
    bool r=false;
    if ((hZip) && (((ZIPDECOMPRESSION *)hZip)->bHandleType == HT_DECOMPRESSOR) && (lpMem) && (dwSize))
    {
        LPWSTR pwstrFile=AnsiToUnicodeEx(pstrFile,-1);
        r=ArchGetFileW(hZip,pwstrFile,lpMem,dwSize);
        MemFree(pwstrFile);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

extern "C" bool ArchExtractFileW(HZIP hZip,WCHAR *pstrPath,WCHAR *lpstrFile)
{
    bool r=false;
    ZIPDECOMPRESSION *p=(ZIPDECOMPRESSION*)hZip;
    if ((hZip) && (p->bHandleType == HT_DECOMPRESSOR) && (pstrPath) && (lpstrFile))
    {
        LPCSTR pFileName=UnicodeToAnsiEx(lpstrFile,-1);
        lstrcpyW(p->strOutputDir,pstrPath);
        unzGoToFirstFile(p->hZip);
        if (unzLocateFile(p->hZip,pFileName,CASESENSITIVITY) == UNZ_OK)
            r=(ExtractCurrentFile(hZip,true) > -1) ? true : false;
        else
        {
            ArchSetLastError(ARCH_FILE_NOT_FOUND);
            r=false;
        }
        MemFree(lpstrFile);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

extern "C" bool ArchExtractFileA(HZIP hZip,char *pstrPath,char *lpstrFile)
{
    bool r=false;
    if ((hZip) && (((ZIPDECOMPRESSION *)hZip)->bHandleType == HT_DECOMPRESSOR) && (pstrPath) && (lpstrFile))
    {
        LPWSTR pwstrPath=AnsiToUnicodeEx(pstrPath,-1),
               pwstrFile=AnsiToUnicodeEx(lpstrFile,-1);
        r=ArchExtractFileW(hZip,pwstrPath,pwstrFile);
        MemFree(pwstrPath);
        MemFree(pwstrFile);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

bool ArchInternalEnumFiles(HZIP hZip,ARCHENUMNAMESCALLBACKW *lpCallback,bool bAnsi)
{
    bool r=false;
    ZIPDECOMPRESSION *p=(ZIPDECOMPRESSION *)hZip;
    if ((hZip) && (((ZIPDECOMPRESSION *)hZip)->bHandleType == HT_DECOMPRESSOR) && (lpCallback))
    {
        ZIPDECOMPRESSION *p=(ZIPDECOMPRESSION*)_alloc(sizeof(ZIPDECOMPRESSION));
        if (p)
        {
            memcpy(p,hZip,sizeof(ZIPDECOMPRESSION));
            p->bOnlyEnum=true;
            p->bEnumAnsi=bAnsi;
            p->lpEnumProc=lpCallback;
            r=ArchExtractFilesW(p,L"0");
            MemFree(p);
        }
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

bool ArchEnumFilesW(HZIP hZip,ARCHENUMNAMESCALLBACKW *lpCallback)
{
    return ArchInternalEnumFiles(hZip,lpCallback,false);
}

bool ArchEnumFilesA(HZIP hZip,ARCHENUMNAMESCALLBACKA *lpCallback)
{
    return ArchInternalEnumFiles(hZip,(ARCHENUMNAMESCALLBACKW*)lpCallback,true);
}

