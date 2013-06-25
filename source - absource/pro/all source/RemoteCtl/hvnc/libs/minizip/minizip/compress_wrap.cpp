#include "common.h"

extern "C" HZIP CreateArchiveW(WCHAR *lpstrZipFile,char *lpPassword,int dwPasswordLen,int dwCompLevel)
{
    void *r=NULL;
    if (lpstrZipFile)
    {
        ZIPCOMPRESSION *p=(ZIPCOMPRESSION *)_alloc(sizeof(ZIPCOMPRESSION));
        if (p)
        {
            p->bHandleType=HT_COMPRESSOR;

            bool bPassword=((lpPassword) && (dwPasswordLen > 0));
            if (bPassword)
            {
                memcpy(p->szPassword,lpPassword,dwPasswordLen);
                p->bEncrypted=true;
            }

            p->dwCompLevel=dwCompLevel;

            zlib_filefunc64_def ffunc;
            fill_fopen64_filefunc(&ffunc);
            p->hZip=zipOpen2_64(lpstrZipFile,0,NULL,&ffunc);
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

extern "C" HZIP CreateArchiveA(char *lpstrZipFile,char *lpPassword,int dwPasswordLen,int dwCompLevel)
{
    HZIP hZip=0;
    if (lpstrZipFile)
    {
        LPWSTR pwstrPath=AnsiToUnicodeEx(lpstrZipFile,-1);
        hZip=CreateArchiveW(pwstrPath,lpPassword,dwPasswordLen,dwCompLevel);
        MemFree(pwstrPath);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return hZip;
}

extern "C" bool ArchAddFileW(HZIP hZip,WCHAR *pstrSourceFile,WCHAR *pstrDestFile)
{
    bool r=false;
    if ((hZip) && (((ZIPCOMPRESSION *)hZip)->bHandleType == HT_COMPRESSOR) && (pstrSourceFile) && (pstrDestFile))
    {
        int lDest,lSrc;

        if (((lDest=lstrlenW(pstrDestFile)) < MAX_PATH-1) && ((lSrc=lstrlenW(pstrSourceFile)) < MAX_PATH-1))
        {
            ZIPCOMPRESSION *p=(ZIPCOMPRESSION *)hZip;
            char *file=UnicodeToOemEx(pstrDestFile,lDest);

            if (file)
            {
                void *buf=_alloc(INT_BUF_SIZE);
                if (buf)
                {
                    p->bInMem=false;
                    zip_fileinfo zi={0};
                    filetime(pstrSourceFile,&zi.tmz_date,&zi.dosDate);
                    char *lpPassword=NULL;
                    unsigned long crcFile=0;
                    if (p->bEncrypted)
                    {
                        getFileCrc(pstrSourceFile,buf,INT_BUF_SIZE,&crcFile);
                        lpPassword=p->szPassword;
                    }
                    int err=zipOpenNewFileInZip3_64(p->hZip,file,&zi,NULL,0,NULL,0,NULL,(p->dwCompLevel>0) ? Z_DEFLATED:0,p->dwCompLevel,0,-MAX_WBITS,DEF_MEM_LEVEL,Z_DEFAULT_STRATEGY,lpPassword,crcFile,0);
                    if (err == ZIP_OK)
                    {
                        HANDLE fin=CreateFileW(pstrSourceFile,GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);
                        if (fin != INVALID_HANDLE_VALUE)
                        {
                            unsigned long size_read = 0;
                            do
                            {
                                err=ZIP_OK;
                                ReadFile(fin,buf,INT_BUF_SIZE,&size_read,0);

                                if (size_read < INT_BUF_SIZE)
                                {
                                    if (!_feof(fin))
                                        err=ZIP_ERRNO;
                                }

                                if (size_read>0)
                                    err=zipWriteInFileInZip(p->hZip,buf,size_read);
                            }
                            while ((err == ZIP_OK) && (size_read>0));
                            SysCloseHandle(fin);

                            if (err<0)
                                err=ZIP_ERRNO;
                            else
                            {
                                err=zipCloseFileInZip(p->hZip);
                                r=true;
                            }
                        }
                    }
                    MemFree(buf);
                }
            }

            MemFree(file);
        }
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

extern "C" bool ArchAddFileA(HZIP hZip,char *pstrSourceFile,char *pstrDestFile)
{
    bool bRet=false;
    if ((hZip) && (((ZIPCOMPRESSION *)hZip)->bHandleType == HT_COMPRESSOR) && (pstrSourceFile) && (pstrDestFile))
    {
        LPWSTR pwstrSourceFile=AnsiToUnicodeEx(pstrSourceFile,-1),
               pwstrDestFile=AnsiToUnicodeEx(pstrDestFile,-1);
        bRet=ArchAddFileW(hZip,pwstrSourceFile,pwstrDestFile);
        MemFree(pwstrSourceFile);
        MemFree(pwstrDestFile);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return bRet;
}

extern "C" void ArchClose(HZIP hZip)
{
    if (!hZip)
    {
        ArchSetLastError(ARCH_INVALID_PARAMETER);
        return;
    }

    ZIPCOMPRESSION *p=(ZIPCOMPRESSION *)hZip;
    if (p->bHandleType == HT_COMPRESSOR)
        zipClose(p->hZip,NULL);
    else
        unzClose(p->hZip);

    MemFree(p);
    return;
}

extern "C" bool ArchCompressMemoryW(HZIP hZip,void *lpMem,int dwSize,WCHAR *pstrFile)
{
    bool r=false;
    if ((hZip) && (((ZIPCOMPRESSION *)hZip)->bHandleType == HT_COMPRESSOR) && (lpMem) && (dwSize) && (pstrFile))
    {
        ZIPCOMPRESSION *p=(ZIPCOMPRESSION *)hZip;
        char *file=UnicodeToOemEx(pstrFile,-1);
        if (file)
        {
            p->bInMem=true;
            p->lpMem=(byte*)lpMem;
            p->dwSize=dwSize;
            zip_fileinfo zi={0};
            ///filetime(pstrSourceFile,&zi.tmz_date,&zi.dosDate);
            char *lpPassword=NULL;
            unsigned long crcFile=0;
            if (p->bEncrypted)
            {
                crcFile=crc32(0,(byte*)lpMem,dwSize);
                lpPassword=p->szPassword;
            }
            int err=zipOpenNewFileInZip3_64(p->hZip,file,&zi,NULL,0,NULL,0,NULL,(p->dwCompLevel>0) ? Z_DEFLATED:0,p->dwCompLevel,0,-MAX_WBITS,DEF_MEM_LEVEL,Z_DEFAULT_STRATEGY,lpPassword,crcFile,0);
            if (err == ZIP_OK)
            {
                if (zipWriteInFileInZip(p->hZip,lpMem,dwSize) == ZIP_OK)
                    r=true;
                err=zipCloseFileInZip(p->hZip);
            }
        }
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

extern "C" bool ArchCompressMemoryA(HZIP hZip,void *lpMem,int dwSize,char *pstrFile)
{
    bool bRet=false;
    if ((hZip) && (((ZIPCOMPRESSION *)hZip)->bHandleType == HT_COMPRESSOR) && (lpMem) && (dwSize) && (pstrFile))
    {
        LPWSTR pwstrFile=AnsiToUnicodeEx(pstrFile,-1);

        bRet=ArchCompressMemoryW(hZip,lpMem,dwSize,pwstrFile);
        MemFree(pwstrFile);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return bRet;
}

bool CreateFromFolderProc(const LPWSTR path,const WIN32_FIND_DATAW *fileInfo,void *data)
{
    WCHAR filePath[MAX_PATH];
    if (_PathCombine(filePath,path,(LPWSTR)fileInfo->cFileName))
    {
        HANDLE hFile=CreateFileW(filePath,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            SysCloseHandle(hFile);
            CFFSTRUCT *cs=(CFFSTRUCT *)data;
            if (ArchAddFileW(cs->lpZipData,filePath,filePath+cs->cabPathOffset))
                cs->filesCount++;
        }
    }
    return true;
}

extern "C" bool ArchiveFolderW(HZIP hZip,WCHAR *sourceFolder,LPWSTR *fileMask,DWORD fileMaskCount,DWORD flags)
{
    bool r=false;
    if ((hZip) && (((ZIPCOMPRESSION *)hZip)->bHandleType == HT_COMPRESSOR) && (sourceFolder) && (fileMask) && (fileMaskCount))
    {
        CFFSTRUCT cs;
        cs.lpZipData=(ZIPCOMPRESSION *)hZip;
        cs.zip=((ZIPCOMPRESSION *)hZip)->hZip;
        if (cs.zip)
        {
            cs.filesCount=0;
            cs.cabPathOffset=lstrlenW(sourceFolder);

            if ((cs.cabPathOffset > 0) && (sourceFolder[cs.cabPathOffset-1] != '\\'))
                cs.cabPathOffset++;

            FindFiles(sourceFolder,fileMask,fileMaskCount,(flags & CFF_DELETE ? FFFLAG_DELETE : 0) | (flags & CFF_RECURSE ? FFFLAG_RECURSIVE : 0) | FFFLAG_SEARCH_FILES,CreateFromFolderProc,&cs,NULL,0,0);

            if ((cs.filesCount > 0))
                r=true;
        }
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return r;
}

extern "C" bool ArchiveFolderA(HZIP hZip,char *sourceFolder,LPSTR *fileMask,DWORD fileMaskCount,DWORD flags)
{
    bool bRet=false;
    if ((hZip) && (((ZIPCOMPRESSION *)hZip)->bHandleType == HT_COMPRESSOR) && (sourceFolder) && (fileMask) && (fileMaskCount))
    {
        LPWSTR wsourceFolder=AnsiToUnicodeEx(sourceFolder,-1),
               *wfileMask=(LPWSTR*)_alloc(fileMaskCount*sizeof(LPWSTR));

        for (DWORD i=0; i<fileMaskCount; i++)
            wfileMask[i]=AnsiToUnicodeEx(fileMask[i],-1);

        bool bRet=ArchiveFolderW(hZip,wsourceFolder,wfileMask,fileMaskCount,flags);

        MemFree(wsourceFolder);
        for (DWORD i=0; i<fileMaskCount; i++)
            MemFree(wfileMask[i]);
        MemFree (wfileMask);
    }
    else
        ArchSetLastError(ARCH_INVALID_PARAMETER);
    return bRet;
}

extern "C" bool ArchCreateFromFolderW(WCHAR *lpstrZipFile,WCHAR *sourceFolder,LPWSTR *fileMask,DWORD fileMaskCount,DWORD flags,char *lpPassword,int dwPasswordLen,int dwCompLevel)
{
    HZIP hZip=CreateArchiveW(lpstrZipFile,lpPassword,dwPasswordLen,dwCompLevel);
    bool r=false;
    if (hZip)
    {
        r=ArchiveFolderW(hZip,sourceFolder,fileMask,fileMaskCount,flags);
        ArchClose(hZip);
    }
    return r;
}

extern "C" bool ArchCreateFromFolderA(char *lpstrZipFile,char *sourceFolder,LPSTR *fileMask,DWORD fileMaskCount,DWORD flags,char *lpPassword,int dwPasswordLen,int dwCompLevel)
{
    HZIP hZip=CreateArchiveA(lpstrZipFile,lpPassword,dwPasswordLen,dwCompLevel);
    bool r=false;
    if (hZip)
    {
        r=ArchiveFolderA(hZip,sourceFolder,fileMask,fileMaskCount,flags);
        ArchClose(hZip);
    }
    return r;
}

