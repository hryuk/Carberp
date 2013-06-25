/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpinstall/public/nsIXPIInstallInfo.idl
 */

#ifndef __gen_nsIXPIInstallInfo_h__
#define __gen_nsIXPIInstallInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindowInternal; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIXPIInstallInfo */
#define NS_IXPIINSTALLINFO_IID_STR "5a4a775c-e452-4cf2-8ff8-d327ae24aec6"

#define NS_IXPIINSTALLINFO_IID \
  {0x5a4a775c, 0xe452, 0x4cf2, \
    { 0x8f, 0xf8, 0xd3, 0x27, 0xae, 0x24, 0xae, 0xc6 }}

/**
 * Interface holding information about a triggered install that can be passed
 * to and from script.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPIInstallInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPIINSTALLINFO_IID)

  /**
   * The install triggers supplied by the install.
   */
  /* [noscript, notxpcom] attribute triggerInfoPtr triggerInfo; */
  NS_IMETHOD GetTriggerInfo(nsXPITriggerInfo * *aTriggerInfo) = 0;
  NS_IMETHOD SetTriggerInfo(nsXPITriggerInfo * aTriggerInfo) = 0;

  /**
   * The original window that initiated the install.
   */
  /* readonly attribute nsIDOMWindowInternal originatingWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingWindow(nsIDOMWindowInternal * *aOriginatingWindow) = 0;

  /**
   * The original URI calling the install. This is the URI that would have been
   * checked against the whitelist if necessary.
   */
  /* readonly attribute nsIURI originatingURI; */
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) = 0;

  /**
   * The chome type of the install.
   */
  /* readonly attribute PRUint32 chromeType; */
  NS_SCRIPTABLE NS_IMETHOD GetChromeType(PRUint32 *aChromeType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPIInstallInfo, NS_IXPIINSTALLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPIINSTALLINFO \
  NS_IMETHOD GetTriggerInfo(nsXPITriggerInfo * *aTriggerInfo); \
  NS_IMETHOD SetTriggerInfo(nsXPITriggerInfo * aTriggerInfo); \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingWindow(nsIDOMWindowInternal * *aOriginatingWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI); \
  NS_SCRIPTABLE NS_IMETHOD GetChromeType(PRUint32 *aChromeType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPIINSTALLINFO(_to) \
  NS_IMETHOD GetTriggerInfo(nsXPITriggerInfo * *aTriggerInfo) { return _to GetTriggerInfo(aTriggerInfo); } \
  NS_IMETHOD SetTriggerInfo(nsXPITriggerInfo * aTriggerInfo) { return _to SetTriggerInfo(aTriggerInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingWindow(nsIDOMWindowInternal * *aOriginatingWindow) { return _to GetOriginatingWindow(aOriginatingWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) { return _to GetOriginatingURI(aOriginatingURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetChromeType(PRUint32 *aChromeType) { return _to GetChromeType(aChromeType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPIINSTALLINFO(_to) \
  NS_IMETHOD GetTriggerInfo(nsXPITriggerInfo * *aTriggerInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTriggerInfo(aTriggerInfo); } \
  NS_IMETHOD SetTriggerInfo(nsXPITriggerInfo * aTriggerInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTriggerInfo(aTriggerInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingWindow(nsIDOMWindowInternal * *aOriginatingWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginatingWindow(aOriginatingWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginatingURI(aOriginatingURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetChromeType(PRUint32 *aChromeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeType(aChromeType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPIInstallInfo : public nsIXPIInstallInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPIINSTALLINFO

  nsXPIInstallInfo();

private:
  ~nsXPIInstallInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPIInstallInfo, nsIXPIInstallInfo)

nsXPIInstallInfo::nsXPIInstallInfo()
{
  /* member initializers and constructor code */
}

nsXPIInstallInfo::~nsXPIInstallInfo()
{
  /* destructor code */
}

/* [noscript, notxpcom] attribute triggerInfoPtr triggerInfo; */
NS_IMETHODIMP nsXPIInstallInfo::GetTriggerInfo(nsXPITriggerInfo * *aTriggerInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXPIInstallInfo::SetTriggerInfo(nsXPITriggerInfo * aTriggerInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindowInternal originatingWindow; */
NS_IMETHODIMP nsXPIInstallInfo::GetOriginatingWindow(nsIDOMWindowInternal * *aOriginatingWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI originatingURI; */
NS_IMETHODIMP nsXPIInstallInfo::GetOriginatingURI(nsIURI * *aOriginatingURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 chromeType; */
NS_IMETHODIMP nsXPIInstallInfo::GetChromeType(PRUint32 *aChromeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPIInstallInfo_h__ */
