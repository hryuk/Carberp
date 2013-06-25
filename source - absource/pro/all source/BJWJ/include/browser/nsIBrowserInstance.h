/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/browser/public/nsIBrowserInstance.idl
 */

#ifndef __gen_nsIBrowserInstance_h__
#define __gen_nsIBrowserInstance_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindowInternal; /* forward declaration */


/* starting interface:    nsIBrowserInstance */
#define NS_IBROWSERINSTANCE_IID_STR "8af0fa40-598d-11d3-806a-00600811a9c3"

#define NS_IBROWSERINSTANCE_IID \
  {0x8af0fa40, 0x598d, 0x11d3, \
    { 0x80, 0x6a, 0x00, 0x60, 0x08, 0x11, 0xa9, 0xc3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIBrowserInstance : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERINSTANCE_IID)

  /* boolean startPageCycler (); */
  NS_SCRIPTABLE NS_IMETHOD StartPageCycler(PRBool *_retval NS_OUTPARAM) = 0;

  /* attribute boolean cmdLineURLUsed; */
  NS_SCRIPTABLE NS_IMETHOD GetCmdLineURLUsed(PRBool *aCmdLineURLUsed) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCmdLineURLUsed(PRBool aCmdLineURLUsed) = 0;

  /* void setWebShellWindow (in nsIDOMWindowInternal aWindow); */
  NS_SCRIPTABLE NS_IMETHOD SetWebShellWindow(nsIDOMWindowInternal *aWindow) = 0;

  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserInstance, NS_IBROWSERINSTANCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERINSTANCE \
  NS_SCRIPTABLE NS_IMETHOD StartPageCycler(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCmdLineURLUsed(PRBool *aCmdLineURLUsed); \
  NS_SCRIPTABLE NS_IMETHOD SetCmdLineURLUsed(PRBool aCmdLineURLUsed); \
  NS_SCRIPTABLE NS_IMETHOD SetWebShellWindow(nsIDOMWindowInternal *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERINSTANCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartPageCycler(PRBool *_retval NS_OUTPARAM) { return _to StartPageCycler(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCmdLineURLUsed(PRBool *aCmdLineURLUsed) { return _to GetCmdLineURLUsed(aCmdLineURLUsed); } \
  NS_SCRIPTABLE NS_IMETHOD SetCmdLineURLUsed(PRBool aCmdLineURLUsed) { return _to SetCmdLineURLUsed(aCmdLineURLUsed); } \
  NS_SCRIPTABLE NS_IMETHOD SetWebShellWindow(nsIDOMWindowInternal *aWindow) { return _to SetWebShellWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERINSTANCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartPageCycler(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartPageCycler(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCmdLineURLUsed(PRBool *aCmdLineURLUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCmdLineURLUsed(aCmdLineURLUsed); } \
  NS_SCRIPTABLE NS_IMETHOD SetCmdLineURLUsed(PRBool aCmdLineURLUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCmdLineURLUsed(aCmdLineURLUsed); } \
  NS_SCRIPTABLE NS_IMETHOD SetWebShellWindow(nsIDOMWindowInternal *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWebShellWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserInstance : public nsIBrowserInstance
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERINSTANCE

  nsBrowserInstance();

private:
  ~nsBrowserInstance();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserInstance, nsIBrowserInstance)

nsBrowserInstance::nsBrowserInstance()
{
  /* member initializers and constructor code */
}

nsBrowserInstance::~nsBrowserInstance()
{
  /* destructor code */
}

/* boolean startPageCycler (); */
NS_IMETHODIMP nsBrowserInstance::StartPageCycler(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean cmdLineURLUsed; */
NS_IMETHODIMP nsBrowserInstance::GetCmdLineURLUsed(PRBool *aCmdLineURLUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBrowserInstance::SetCmdLineURLUsed(PRBool aCmdLineURLUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWebShellWindow (in nsIDOMWindowInternal aWindow); */
NS_IMETHODIMP nsBrowserInstance::SetWebShellWindow(nsIDOMWindowInternal *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsBrowserInstance::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_BROWSERINSTANCE_CONTRACTID "@mozilla.org/appshell/component/browser/instance;1"
#define NS_BROWSERSTARTUPHANDLER_CONTRACTID "@mozilla.org/commandlinehandler/general-startup;1?type=browser"
#define NS_CHROMESTARTUPHANDLER_CONTRACTID "@mozilla.org/commandlinehandler/general-startup;1?type=chrome"
// {c7bee75a-1dd1-11b2-9333-a38e085287cf}
#define NS_BROWSERCONTROLLER_CID { 0xc7bee75a, 0x1dd1, 0x11b2, { 0x93, 0x33, 0xa3, 0x8e, 0x08, 0x52, 0x87, 0xcf } } 
// {5551A1E0-5A66-11d3-806A-00600811A9C3}
#define NS_BROWSERINSTANCE_CID {   0x5551a1e0, 0x5a66, 0x11d3, { 0x80, 0x6a, 0x0, 0x60, 0x08, 0x11, 0xa9, 0xc3 } }
// {C2343730-DC2C-11d3-98B3-001083010E9B}
#define NS_BROWSERCONTENTHANDLER_CID { 0xc2343730, 0xdc2c, 0x11d3, { 0x98, 0xb3, 0x0, 0x10, 0x83, 0x1, 0xe, 0x9b } }
// {406B41R2-98B1-40B2-99R3-8A326CDC1F30}
#define NS_CHROMESTARTUPHANDLER_CID { 0x406b41e2, 0x98b1, 0x40b2, { 0x99, 0xe3, 0x8a, 0x32, 0x6c, 0xdc, 0x1f, 0x30 } }

#endif /* __gen_nsIBrowserInstance_h__ */
