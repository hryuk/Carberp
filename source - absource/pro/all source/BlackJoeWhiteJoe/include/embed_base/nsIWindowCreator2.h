/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/base/nsIWindowCreator2.idl
 */

#ifndef __gen_nsIWindowCreator2_h__
#define __gen_nsIWindowCreator2_h__


#ifndef __gen_nsIWindowCreator_h__
#include "nsIWindowCreator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIWebBrowserChrome; /* forward declaration */


/* starting interface:    nsIWindowCreator2 */
#define NS_IWINDOWCREATOR2_IID_STR "f673ec81-a4b0-11d6-964b-eb5a2bf216fc"

#define NS_IWINDOWCREATOR2_IID \
  {0xf673ec81, 0xa4b0, 0x11d6, \
    { 0x96, 0x4b, 0xeb, 0x5a, 0x2b, 0xf2, 0x16, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWindowCreator2 : public nsIWindowCreator {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWCREATOR2_IID)

  /**
   * Definitions for contextFlags
   */
  enum { PARENT_IS_LOADING_OR_RUNNING_TIMEOUT = 1U };

  /** Create a new window. Gecko will/may call this method, if made
      available to it, to create new windows.
      @param parent Parent window, if any. Null if not. The newly created
                    window should be made a child/dependent window of
                    the parent, if any (and if the concept applies
                    to the underlying OS).
      @param chromeFlags Chrome features from nsIWebBrowserChrome
      @param contextFlags Flags about the context of the window being created.
      @param uri The URL for which this window is intended. It can be null
                 or zero-length. The implementation of this interface
                 may use the URL to help determine what sort of window
                 to open or whether to cancel window creation. It will not
                 load the URL.
      @param cancel Return |true| to reject window creation. If true the
                    implementation has determined the window should not
                    be created at all. The caller should not default
                    to any possible backup scheme for creating the window.
      @return the new window. Will be null if canceled or an error occurred.
  */
  /* nsIWebBrowserChrome createChromeWindow2 (in nsIWebBrowserChrome parent, in PRUint32 chromeFlags, in PRUint32 contextFlags, in nsIURI uri, out boolean cancel); */
  NS_SCRIPTABLE NS_IMETHOD CreateChromeWindow2(nsIWebBrowserChrome *parent, PRUint32 chromeFlags, PRUint32 contextFlags, nsIURI *uri, PRBool *cancel NS_OUTPARAM, nsIWebBrowserChrome **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowCreator2, NS_IWINDOWCREATOR2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWCREATOR2 \
  NS_SCRIPTABLE NS_IMETHOD CreateChromeWindow2(nsIWebBrowserChrome *parent, PRUint32 chromeFlags, PRUint32 contextFlags, nsIURI *uri, PRBool *cancel NS_OUTPARAM, nsIWebBrowserChrome **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWCREATOR2(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateChromeWindow2(nsIWebBrowserChrome *parent, PRUint32 chromeFlags, PRUint32 contextFlags, nsIURI *uri, PRBool *cancel NS_OUTPARAM, nsIWebBrowserChrome **_retval NS_OUTPARAM) { return _to CreateChromeWindow2(parent, chromeFlags, contextFlags, uri, cancel, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWCREATOR2(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateChromeWindow2(nsIWebBrowserChrome *parent, PRUint32 chromeFlags, PRUint32 contextFlags, nsIURI *uri, PRBool *cancel NS_OUTPARAM, nsIWebBrowserChrome **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateChromeWindow2(parent, chromeFlags, contextFlags, uri, cancel, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowCreator2 : public nsIWindowCreator2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWCREATOR2

  nsWindowCreator2();

private:
  ~nsWindowCreator2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowCreator2, nsIWindowCreator2)

nsWindowCreator2::nsWindowCreator2()
{
  /* member initializers and constructor code */
}

nsWindowCreator2::~nsWindowCreator2()
{
  /* destructor code */
}

/* nsIWebBrowserChrome createChromeWindow2 (in nsIWebBrowserChrome parent, in PRUint32 chromeFlags, in PRUint32 contextFlags, in nsIURI uri, out boolean cancel); */
NS_IMETHODIMP nsWindowCreator2::CreateChromeWindow2(nsIWebBrowserChrome *parent, PRUint32 chromeFlags, PRUint32 contextFlags, nsIURI *uri, PRBool *cancel NS_OUTPARAM, nsIWebBrowserChrome **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowCreator2_h__ */
