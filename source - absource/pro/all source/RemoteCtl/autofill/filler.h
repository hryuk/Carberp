#ifndef FILLER_H_INCLUDED
#define FILLER_H_INCLUDED

#define IID_TEXT 1
#define IID_TEXTAREA 2
#define IID_FILE 3
#define IID_HIDDEN 4
#define IID_RADIO 5
#define IID_CHECKBOX 6
#define IID_SELECT 7

struct FORM_ELEMENT
{
    WCHAR *szName;
    int dwType;
    WCHAR *szValue;
    VARIANT_BOOL bState;

    FORM_ELEMENT *lpNext;
};

struct FORM_FILL
{
    WCHAR szUrl[260];
    WCHAR szFormID[30];
    FORM_ELEMENT *lpElements;

    FORM_FILL *lpNextForm;
};

bool FillerInit(char *lpConfig,int dwConfigSize);
void FillerCleanup();

void FillForm(IHTMLDocument2 *pHTMLDocument,FORM_FILL *lpForm);
void FillFormElement(IHTMLElementCollection *pAll,int elType,WCHAR *szName,WCHAR *szVal,VARIANT_BOOL bState=FALSE);
void WaitTillLoaded(SHDocVw::IWebBrowser2Ptr spBrowser);
FORM_FILL *IsFormPresent(WCHAR *lpUrl);

#endif // FILLER_H_INCLUDED
