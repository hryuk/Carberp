#include "std.h"

FORM_FILL *lpFillerInfo=NULL;

FORM_FILL *IsFormPresent(WCHAR *lpUrl)
{
    FORM_FILL *p=lpFillerInfo;
    while (p)
    {
        int dwSize=lstrlenW(lpUrl);
        if (WildCmp(p->szUrl,lpUrl,&dwSize))
            return p;
        p=p->lpNextForm;
    }
    return NULL;
}

/**
void __fastcall TFMain::bUploadClick(TObject *Sender)
{
    AnsiString slHtmlFormName = "UploadForm"; // <form name="UploadForm"...

    IHTMLDocument2 *pHTMLDocument = NULL;
    if(SUCCEEDED(CppWebBrowser->Document->QueryInterface(
                     IID_IHTMLDocument2, (LPVOID*)&pHTMLDocument)))
    {
        // click SUBMIT()
        IHTMLElementCollection *HTMLForms = NULL;
        if(SUCCEEDED(pHTMLDocument->get_forms(&HTMLForms)) && HTMLForms)
        {
            //  slHtmlFormName <form name="UploadForm"...>
            TVariant vName3 = slHtmlFormName;
            TVariant vIndex3 = 0;
            IDispatch *pDisp3 = NULL;
            if(SUCCEEDED(HTMLForms->item(vName3, vIndex3, &pDisp3)) && pDisp3)
            {
                IHTMLFormElement *HTMLForm = NULL;
                if(SUCCEEDED(pDisp3->QueryInterface(IID_IHTMLFormElement,
                                                    (LPVOID*)&HTMLForm)) && HTMLForm)
                {
                    HTMLForm->submit(); // нажимаем кнопку submit
                    HTMLForm->Release();
                }
                pDisp3->Release();
            }
            HTMLForms->Release();
        }

        pHTMLDocument->Release();
    }
}*/

void FillForm(IHTMLDocument2 *pHTMLDocument,FORM_FILL *lpForm)
{
    IHTMLElementCollection *pAll=NULL;
    pHTMLDocument->get_all(&pAll);
    if (pAll)
    {
        FORM_ELEMENT *lpEl=lpForm->lpElements;
        while (lpEl)
        {
            FillFormElement(pAll,lpEl->dwType,lpEl->szName,lpEl->szValue,lpEl->bState);
            lpEl=lpEl->lpNext;
        }
        pAll->Release();
    }
    pHTMLDocument->Release();
    return;
}

void FillFormElement(IHTMLElementCollection *pAll,int elType,WCHAR *szName,WCHAR *szVal,VARIANT_BOOL bState)
{
    _variant_t vIndex(0L);
    _variant_t name(szName);
    bool bStop=true;

    do
    {
        IDispatch *pDisp=NULL;
        pAll->item(name,vIndex,&pDisp);
        if (pDisp)
        {
            _bstr_t strVal=szVal;
            switch (elType)
            {
                case IID_TEXT:
                {
                    IHTMLInputElement *pText=NULL;
                    pDisp->QueryInterface(IID_IHTMLInputElement,(LPVOID*)&pText);
                    if (pText)
                    {
                        pText->put_value(strVal);
                        pText->Release();
                    }
                    break;
                }
                case IID_TEXTAREA:
                {
                    IHTMLTextAreaElement *pTextArea=NULL;
                    pDisp->QueryInterface(IID_IHTMLTextAreaElement,(LPVOID*)&pTextArea);
                    if (pTextArea)
                    {
                        pTextArea->put_value(strVal);
                        pTextArea->Release();
                    }
                    break;
                }
                case IID_FILE:
                {
                    IHTMLInputFileElement *pFile=NULL;
                    pDisp->QueryInterface(IID_IHTMLInputFileElement,(LPVOID*)&pFile);
                    if (pFile)
                    {
                        /*/ Copy Full FileName To Clipboard
                        Clipboard()->SetTextBuf(sFile.c_str());
                        pFile->select();
                        // Paste from ClipBoard to "userfile"
                        CppWebBrowser->ControlInterface->ExecWB(Shdocvw_tlb::OLECMDID_PASTE,Shdocvw_tlb::OLECMDEXECOPT_DODEFAULT, Variant("userfile"));
                        pFile->Release();*/
                    }
                    break;
                }
                case IID_HIDDEN:
                {
                    IHTMLInputHiddenElement *pHidden=NULL;
                    pDisp->QueryInterface(IID_IHTMLInputHiddenElement,(LPVOID*)&pHidden);
                    if (pHidden)
                    {
                        pHidden->put_value(strVal);
                        pHidden->Release();
                    }
                    break;
                }
                case IID_CHECKBOX:
                case IID_RADIO:
                {
                    IHTMLInputElement *pCheckbox=NULL;
                    pDisp->QueryInterface(IID_IHTMLInputElement,(LPVOID*)&pCheckbox);
                    if (pCheckbox)
                    {
                        BSTR strCurVal;
                        pAll->item(name,vIndex,&pDisp);
                        pCheckbox->get_value(&strCurVal);
                        if (!lstrcmpiW(strCurVal,szVal))
                        {
                            pCheckbox->put_status(bState);
                            pCheckbox->Release();
                            bStop=true;
                        }
                        else
                        {
                            vIndex.intVal++;
                            bStop=false;
                        }
                        SysFreeString(strCurVal);
                    }
                    break;
                }
                case IID_SELECT:
                {
                    IHTMLSelectElement *pSelect=NULL;
                    pDisp->QueryInterface(IID_IHTMLSelectElement,(LPVOID*)&pSelect);
                    if (pSelect)
                    {
                        _variant_t type(L"OPTION");
                        IDispatch *pOptDisp=NULL;
                        pSelect->tags(type,&pOptDisp);
                        if (pOptDisp)
                        {
                            IHTMLElementCollection *pOptColl=NULL;
                            pOptDisp->QueryInterface(IID_IHTMLElementCollection,(LPVOID*)&pOptColl);
                            if (pOptColl)
                            {
                                long dwCount=0;
                                pOptColl->get_length(&dwCount);
                                _variant_t vI=(0L);

                                for (int i=0; i<dwCount; i++)
                                {
                                    vI.intVal=i;
                                    IDispatch *pElDisp=NULL;
                                    pOptColl->item(vI,vIndex,&pElDisp);
                                    if (pElDisp)
                                    {
                                        IHTMLOptionElement *pElement=NULL;
                                        pElDisp->QueryInterface(IID_IHTMLOptionElement,(LPVOID*)&pElement);
                                        if (pElement)
                                        {
                                            BSTR strCurVal;
                                            pElement->get_value(&strCurVal);
                                            pElDisp->Release();
                                            pElement->Release();

                                            if (!lstrcmpiW(strCurVal,szVal))
                                            {
                                                SysFreeString(strCurVal);
                                                pSelect->put_selectedIndex(i);
                                                break;
                                            }
                                            SysFreeString(strCurVal);
                                        }
                                    }
                                }
                                pOptColl->Release();
                            }
                            pOptDisp->Release();
                        }
                        pSelect->Release();
                    }
                    break;
                }
            }
            SysFreeString(strVal);
            pDisp->Release();
        }
        else
            bStop=true;
    }
    while (!bStop);

    name.Clear();
    vIndex.Clear();
    return;
}

void WaitTillLoaded(SHDocVw::IWebBrowser2Ptr spBrowser)
{
    READYSTATE result;
    do
    {
        result=spBrowser->GetReadyState();

        if (result != READYSTATE_COMPLETE)
            Sleep (250);
    }
    while (result != READYSTATE_COMPLETE);

    return;
}

bool FillerInit(char *lpConfig,int dwConfigSize)
{
    PNODE pNode=NULL;
    bool r=false;

    XmlParse(lpConfig,dwConfigSize,&pNode);
    if (pNode)
    {
        FORM_FILL *lpForm=0,*lpTmpForm;
        PNODE pFormNode=XmlGetSubNodeByName(pNode,"form");
        while (pFormNode)
        {
            lpTmpForm=lpForm;
            lpForm=(FORM_FILL*)xalloc(sizeof(FORM_FILL));
            if (lpTmpForm)
                lpTmpForm->lpNextForm=lpForm;
            else
                lpFillerInfo=lpForm;

            char *id=XmlGetSubNodeValueByName(pFormNode,"id"),
                 *url=XmlGetSubNodeValueByName(pFormNode,"url");

            int dwLen=lstrlen(id);
            if (dwLen++)
                MultiByteToWideChar(1251,0,id,dwLen,lpForm->szFormID,dwLen);
            dwLen=lstrlen(url);
            if (dwLen++)
                MultiByteToWideChar(1251,0,url,dwLen,lpForm->szUrl,dwLen);

            PNODE pElementNode=XmlGetSubNodeByName(pFormNode,"element");

            FORM_ELEMENT *lpElement=0,*lpTmpElement;
            while (pElementNode)
            {
                lpTmpElement=lpElement;
                lpElement=(FORM_ELEMENT*)xalloc(sizeof(FORM_ELEMENT));
                if (lpTmpElement)
                    lpTmpElement->lpNext=lpElement;
                else
                    lpForm->lpElements=lpElement;

                char *szName=XmlGetSubNodeValueByName(pElementNode,"name"),
                     *szType=XmlGetSubNodeValueByName(pElementNode,"type"),
                     *szValue=XmlGetSubNodeValueByName(pElementNode,"value"),
                     *szState=XmlGetSubNodeValueByName(pElementNode,"state");

                int dwState=StrToInt(szState);
                lpElement->bState=(dwState) ? VARIANT_TRUE : VARIANT_FALSE;

                dwLen=lstrlen(szName);
                if (dwLen++)
                {
                    lpElement->szName=(LPWSTR)xalloc(dwLen*sizeof(WCHAR));
                    MultiByteToWideChar(1251,0,szName,dwLen,lpElement->szName,dwLen);
                }

                dwLen=lstrlen(szValue);
                if (dwLen++)
                {
                    lpElement->szValue=(LPWSTR)xalloc(dwLen*sizeof(WCHAR));
                    MultiByteToWideChar(1251,0,szValue,dwLen,lpElement->szValue,dwLen);
                }

                if (!lstrcmpi(szType,"text"))
                    lpElement->dwType=IID_TEXT;
                else if (!lstrcmpi(szType,"select"))
                    lpElement->dwType=IID_SELECT;
                else if (!lstrcmpi(szType,"file"))
                    lpElement->dwType=IID_FILE;
                else if (!lstrcmpi(szType,"radio"))
                    lpElement->dwType=IID_RADIO;
                else if (!lstrcmpi(szType,"checkbox"))
                    lpElement->dwType=IID_CHECKBOX;
                else if (!lstrcmpi(szType,"textarea"))
                    lpElement->dwType=IID_TEXTAREA;
                else if (!lstrcmpi(szType,"hidden"))
                    lpElement->dwType=IID_HIDDEN;

                pElementNode=XmlGetNextSubNodeByName(pElementNode,"element");
            }
            pFormNode=XmlGetNextSubNodeByName(pFormNode,"form");
        }
        XmlFree(&pNode);
        r=true;
    }
    return r;
}

void FillerCleanup()
{
    if (lpFillerInfo)
    {
        FORM_FILL *lpFiller=lpFillerInfo,*lpNext;
        do
        {
            FORM_ELEMENT *lpEl=lpFiller->lpElements;
            while (lpEl)
            {
                FORM_ELEMENT *lpNextEl=lpEl->lpNext;
                if (lpEl->szName)
                    xfree(lpEl->szName);
                if (lpEl->szValue)
                    xfree(lpEl->szValue);
                xfree(lpEl);
                lpEl=lpNextEl;
            }
            lpNext=lpFiller->lpNextForm;
            xfree(lpFiller);
        }
        while (lpFiller->lpNextForm);

        lpFillerInfo=NULL;
    }
    return;
}

