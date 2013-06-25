#include "std.h"

void WINAPI WorkingThread(HWND hIE)
{
    CoInitialize(NULL);
    SHDocVw::IShellWindowsPtr m_spSHWinds;
    m_spSHWinds.CreateInstance(__uuidof(SHDocVw::ShellWindows));

    IDispatchPtr spDisp;
    long nCount=m_spSHWinds->GetCount();

    for (long i=0; i < nCount; i++)
    {
        _variant_t va(i,VT_I4);
        spDisp=m_spSHWinds->Item(va);

        SHDocVw::IWebBrowser2Ptr spBrowser(spDisp);
        if (spBrowser != NULL)
        {
            HWND hWnd;
            spBrowser->get_HWND((long*)(&hWnd));
            if ((IsWindow(hWnd)) && (hWnd == hIE))
            {
                // работать будем пока не закрыто нужное нам окно
                _bstr_t szLocation;
                while (IsWindow(hWnd))
                {
                    szLocation=spBrowser->GetLocationURL();
                    FORM_FILL *lpForm=NULL,*lpLastFrom=NULL;

                    if (lpForm=IsFormPresent(szLocation))
                    {
                        if (lpLastFrom == lpLastFrom)
                        {
                            READYSTATE result=spBrowser->GetReadyState();
                            if (result == READYSTATE_COMPLETE)
                            {
                                Sleep(10);
                                continue;
                            }
                        }
                        WaitTillLoaded(spBrowser); // дожидаемся загрузки страницы

                        IHTMLDocument2 *pHTMLDocument=NULL;
                        spBrowser->Document->QueryInterface(IID_IHTMLDocument2,(LPVOID*)&pHTMLDocument);
                        if (pHTMLDocument)
                            FillForm(pHTMLDocument,lpForm);
                    }
                    Sleep(1);
                }
            }
        }
    }
    m_spSHWinds.Release();
    CoUninitialize();
    return;
}

extern "C" __declspec(dllexport) void HackThisIECopy(HWND hIE)
{
    CreateThread(0,0,(LPTHREAD_START_ROUTINE)WorkingThread,hIE,0,0);
    return;
}

BOOL CALLBACK main(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        HANDLE hFile=CreateFile("config.xml",FILE_READ_ACCESS,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            DWORD dwSize=GetFileSize(hFile,0);

            if (dwSize)
            {
                char *xml=(char*)malloc(dwSize);
                if (xml)
                {
                    if (ReadFile(hFile,xml,dwSize,&dwSize,0))
                        FillerInit(xml,dwSize);
                    free(xml);
                }
                CloseHandle(hFile);
            }
        }
    }
    else if (fdwReason == DLL_PROCESS_DETACH)
        FillerCleanup();
    return TRUE;
}


