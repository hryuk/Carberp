/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/appshell/public/nsIPopupWindowManager.idl
 */

#ifndef __gen_nsIPopupWindowManager_h__
#define __gen_nsIPopupWindowManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIPopupWindowManager */
#define NS_IPOPUPWINDOWMANAGER_IID_STR "3210a6aa-b464-4f57-9335-b22815567cf1"

#define NS_IPOPUPWINDOWMANAGER_IID \
  {0x3210a6aa, 0xb464, 0x4f57, \
    { 0x93, 0x35, 0xb2, 0x28, 0x15, 0x56, 0x7c, 0xf1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPopupWindowManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPOPUPWINDOWMANAGER_IID)

  /**
   * These values are returned by the testPermission method
   */
  enum { ALLOW_POPUP = 1U };

  enum { DENY_POPUP = 2U };

  enum { ALLOW_POPUP_WITH_PREJUDICE = 3U };

  /**
   * Test whether a website has permission to show a popup window.
   * @param   uri is the URI to be tested
   * @return  one of the enumerated permission actions defined above
   */
  /* PRUint32 testPermission (in nsIURI uri); */
  NS_SCRIPTABLE NS_IMETHOD TestPermission(nsIURI *uri, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPopupWindowManager, NS_IPOPUPWINDOWMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPOPUPWINDOWMANAGER \
  NS_SCRIPTABLE NS_IMETHOD TestPermission(nsIURI *uri, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPOPUPWINDOWMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD TestPermission(nsIURI *uri, PRUint32 *_retval NS_OUTPARAM) { return _to TestPermission(uri, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPOPUPWINDOWMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD TestPermission(nsIURI *uri, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestPermission(uri, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPopupWindowManager : public nsIPopupWindowManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPOPUPWINDOWMANAGER

  nsPopupWindowManager();

private:
  ~nsPopupWindowManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPopupWindowManager, nsIPopupWindowManager)

nsPopupWindowManager::nsPopupWindowManager()
{
  /* member initializers and constructor code */
}

nsPopupWindowManager::~nsPopupWindowManager()
{
  /* destructor code */
}

/* PRUint32 testPermission (in nsIURI uri); */
NS_IMETHODIMP nsPopupWindowManager::TestPermission(nsIURI *uri, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_POPUPWINDOWMANAGER_CONTRACTID "@mozilla.org/PopupWindowManager;1"

#endif /* __gen_nsIPopupWindowManager_h__ */
