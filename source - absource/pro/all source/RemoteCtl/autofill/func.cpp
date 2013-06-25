#include "std.h"

bool ChrCmpI(WCHAR cChr1,WCHAR cChr2,byte *bNewStrFlag)
{
    if (bNewStrFlag)
        *bNewStrFlag=0;

    if (cChr1 != cChr2)
    {
        if (bNewStrFlag)
        {
            if ((cChr1 == 0x0A) && (cChr2 == 0x0D))
            {
                *bNewStrFlag=0x0A;
                return true;
            }
            else if ((cChr1 == 0x0D) && (cChr2 == 0x0A))
            {
                *bNewStrFlag=0x0D;
                return true;
            }
        }

        if (cChr1 < cChr2)
        {
            WCHAR cTmp=cChr1;
            cChr1=cChr2;
            cChr2=cTmp;
        }
        if (cChr1-cChr2 != 0x20)
            return false;
    }
    return true;
}

bool WildCmp(WCHAR *lpMask,WCHAR *lpStr,int *dwDataSize)
{
    WCHAR cStr,cMask,*lpNewMaskPos=lpMask,*lpNewPos=lpStr;
    byte bNewStrFlag;
    int dwBufSize=*dwDataSize;

    if ((!lpStr) || (!lpNewMaskPos) || (!dwBufSize))
        return false;

    if (dwBufSize == -1)
        dwBufSize=PAGE_SIZE;

    for (;; lpNewMaskPos++,lpNewPos++,dwBufSize--)
    {
        cStr=*lpNewPos;
        cMask=*lpNewMaskPos;
        if (!dwBufSize)
        {
            if (cMask == '*')
            {
                while ((*lpNewMaskPos == '*') ||  (*lpNewMaskPos == '#'))
                {
                    if (!*lpNewMaskPos++)
                        goto ret_true;
                }
            }

            goto ret_false;
        }


        if (!cMask)
        {
ret_true:   if (dwDataSize)
                *dwDataSize=lpNewPos-lpStr;
            return true;
        }
        if ((cMask != '#') && (!ChrCmpI(cMask,cStr,&bNewStrFlag)))
            break;
        else if (bNewStrFlag)
        {
            if (bNewStrFlag == 0x0A)
            {
                lpNewPos++;
                if (!--dwBufSize)
                    goto ret_false;
            }
            else
                lpNewMaskPos++;
        }
    }
    if (cMask != '*')
    {
ret_false:
        if (dwDataSize)
            *dwDataSize=0;
        return false;
    }

    for (;; lpNewMaskPos++,lpNewPos++,dwBufSize--)
    {
        WCHAR *lpMaskPos;
        while (*lpNewMaskPos == '*')
        {
            lpMaskPos=lpNewMaskPos++;
            if (!*lpNewMaskPos)
                goto ret_true;
        }

        cMask=*lpNewMaskPos;
        if (!cMask)
            goto ret_true;

        cStr=*lpNewPos;
        if (!cStr)
            goto ret_false;

        if (!dwBufSize)
            goto ret_false;

        if ((cMask != '#') && (!ChrCmpI(cMask,cStr,&bNewStrFlag)))
        {
            int dwTmp=(lpNewMaskPos-lpMaskPos)-1;
            lpNewPos-=dwTmp;
            dwBufSize+=dwTmp;
            lpNewMaskPos=lpMaskPos;
        }
        else if (bNewStrFlag)
        {
            if (bNewStrFlag == 0x0A)
            {
                lpNewPos++;
                if (!--dwBufSize)
                    goto ret_false;
            }
            else
                lpNewMaskPos++;
        }
    }
}

int CalcFuncCRC32i(byte *data)
{
    byte buf[300], *p=buf;
    while (*data)
    {
        byte tmp=*data++;
        if (((tmp > 0xC0) && (tmp < 0xDF)) || ((tmp > 'A') && (tmp < 'Z')))
            tmp+=0x20;
        *p++=tmp;
    }
    *p=0;

    return CalcFuncCRC32(buf);
}

int CalcFuncCRC32(byte *data)
{
    byte *buf = data;
    unsigned int crc32 = -1;
    for (int i=0; buf[i]; i++)
    {
        unsigned int cur_byte = *(byte *)&buf[i] ^ *(byte*)&crc32;
        crc32 >>= 8;
        for (int j = 0; j < 8; j++)
        {
            bool c = ((cur_byte & 1) != 0);
            cur_byte >>= 1;
            if (c) cur_byte ^= 0xEDB88320u;
        }
        crc32 ^= cur_byte;
    }
    return ~crc32;
}

