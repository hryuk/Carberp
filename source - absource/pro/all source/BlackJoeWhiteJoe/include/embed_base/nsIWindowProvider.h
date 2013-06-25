/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/base/nsIWindowProvider.idl
 */

#ifndef __gen_nsIWindowProvider_h__
#define __gen_nsIWindowProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIWindowProvider */
#define NS_IWINDOWPROVIDER_IID_STR "5119ac7f-81dd-4061-96a7-71f2cf5efee4"

#define NS_IWINDOWPROVIDER_IID \
  {0x5119ac7f, 0x81dd, 0x4061, \
    { 0x96, 0xa7, 0x71, 0xf2, 0xcf, 0x5e, 0xfe, 0xe4 }}

/**
 * The nsIWindowProvider interface exists so that the window watcher's default
 * behavior of opening a new window can be easly modified.  When the window
 * watcher needs to open a new window, it will first check with the
 * nsIWindowProvider it gets from the parent window.  If there is no provider
 * or the provider does not provide a window, the window watcher will proceed
 * to actually open a new window.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWindowProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWPROVIDER_IID)

  /**
   * A method to request that this provider provide a window.  The window
   * returned need not to have the right name or parent set on it; setting
   * those is the caller's responsibility.  The provider can always return null
   * to have the caller create a brand-new window.
   *
   * @param aParent Must not be null.  This is the window that the caller wants
   *                to use as the parent for the new window.  Generally,
   *                nsIWindowProvider implementors can expect to be somehow
   *                related to aParent; the relationship may depend on the
   *                nsIWindowProvider implementation.
   * @param aChromeFlags The chrome flags the caller will use to create a new
   *                      window if this provider returns null.  See
   *                      nsIWebBrowserChrome for the possible values of this
   *                      field.
   * @param aPositionSpecified Whether the attempt to create a window is trying
   *                           to specify a position for the new window.
   * @param aSizeSpecified Whether the attempt to create a window is trying to
   *                       specify a size for the new window.
   * @param aURI The URI to be loaded in the new window.  The nsIWindowProvider
   *             implementation MUST NOT load this URI in the window it
   *             returns.  This URI is provided solely to help the
   *             nsIWindowProvider implenentation make decisions; the caller
   *             will handle loading the URI in the window returned if
   *             provideWindow returns a window.  Note that the URI may be null
   *             if the load cannot be represented by a single URI (e.g. if
   *             the load has extra load flags, POST data, etc).
   * @param aName The name of the window being opened.  Setting the name on the
   *              return value of provideWindow will be handled by the caller;
   *              aName is provided solely to help the nsIWindowProvider
   *              implementation make decisions.
   * @param aFeatures The feature string for the window being opened.  This may
   *                  be empty.  The nsIWindowProvider implementation is
   *                  allowed to apply the feature string to the window it
   *                  returns in any way it sees fit.  See the nsIWindowWatcher
   *                  interface for details on feature strings.
   * @param aWindowIsNew [out] Whether the window being returned was just
   *                           created by the window provider implementation.
   *                           This can be used by callers to keep track of which
   *                           windows were opened by the user as opposed to
   *                           being opened programmatically.  This should be set
   *                           to false if the window being returned existed
   *                           before the provideWindow() call.  The value of this
   *                           out parameter is meaningless if provideWindow()
   *                           returns null.
   * @return A window the caller should use or null if the caller should just
   *         create a new window.  The returned window may be newly opened by
   *         the nsIWindowProvider implementation or may be a window that
   *         already existed.
   *
   * @see nsIWindowWatcher for more information on aFeatures.
   * @see nsIWebBrowserChrome for more information on aChromeFlags.
   */
  /* nsIDOMWindow provideWindow (in nsIDOMWindow aParent, in unsigned long aChromeFlags, in boolean aPositionSpecified, in boolean aSizeSpecified, in nsIURI aURI, in AString aName, in AUTF8String aFeatures, out boolean aWindowIsNew); */
  NS_SCRIPTABLE NS_IMETHOD ProvideWindow(nsIDOMWindow *aParent, PRUint32 aChromeFlags, PRBool aPositionSpecified, PRBool aSizeSpecified, nsIURI *aURI, const nsAString & aName, const nsACString & aFeatures, PRBool *aWindowIsNew NS_OUTPARAM, nsIDOMWindow **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowProvider, NS_IWINDOWPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWPROVIDER \
  NS_SCRIPTABLE NS_IMETHOD ProvideWindow(nsIDOMWindow *aParent, PRUint32 aChromeFlags, PRBool aPositionSpecified, PRBool aSizeSpecified, nsIURI *aURI, const nsAString & aName, const nsACString & aFeatures, PRBool *aWindowIsNew NS_OUTPARAM, nsIDOMWindow **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ProvideWindow(nsIDOMWindow *aParent, PRUint32 aChromeFlags, PRBool aPositionSpecified, PRBool aSizeSpecified, nsIURI *aURI, const nsAString & aName, const nsACString & aFeatures, PRBool *aWindowIsNew NS_OUTPARAM, nsIDOMWindow **_retval NS_OUTPARAM) { return _to ProvideWindow(aParent, aChromeFlags, aPositionSpecified, aSizeSpecified, aURI, aName, aFeatures, aWindowIsNew, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ProvideWindow(nsIDOMWindow *aParent, PRUint32 aChromeFlags, PRBool aPositionSpecified, PRBool aSizeSpecified, nsIURI *aURI, const nsAString & aName, const nsACString & aFeatures, PRBool *aWindowIsNew NS_OUTPARAM, nsIDOMWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProvideWindow(aParent, aChromeFlags, aPositionSpecified, aSizeSpecified, aURI, aName, aFeatures, aWindowIsNew, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowProvider : public nsIWindowProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWPROVIDER

  nsWindowProvider();

private:
  ~nsWindowProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowProvider, nsIWindowProvider)

nsWindowProvider::nsWindowProvider()
{
  /* member initializers and constructor code */
}

nsWindowProvider::~nsWindowProvider()
{
  /* destructor code */
}

/* nsIDOMWindow provideWindow (in nsIDOMWindow aParent, in unsigned long aChromeFlags, in boolean aPositionSpecified, in boolean aSizeSpecified, in nsIURI aURI, in AString aName, in AUTF8String aFeatures, out boolean aWindowIsNew); */
NS_IMETHODIMP nsWindowProvider::ProvideWindow(nsIDOMWindow *aParent, PRUint32 aChromeFlags, PRBool aPositionSpecified, PRBool aSizeSpecified, nsIURI *aURI, const nsAString & aName, const nsACString & aFeatures, PRBool *aWindowIsNew NS_OUTPARAM, nsIDOMWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowProvider_h__ */
