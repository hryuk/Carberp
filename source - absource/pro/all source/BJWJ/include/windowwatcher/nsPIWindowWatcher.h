/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/windowwatcher/public/nsPIWindowWatcher.idl
 */

#ifndef __gen_nsPIWindowWatcher_h__
#define __gen_nsPIWindowWatcher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIWebBrowserChrome; /* forward declaration */

class nsIDocShellTreeItem; /* forward declaration */

class nsIArray; /* forward declaration */

#include "jspubtd.h"

/* starting interface:    nsPIWindowWatcher */
#define NS_PIWINDOWWATCHER_IID_STR "8624594a-28d7-4bc3-8d12-b1c2b9eefd90"

#define NS_PIWINDOWWATCHER_IID \
  {0x8624594a, 0x28d7, 0x4bc3, \
    { 0x8d, 0x12, 0xb1, 0xc2, 0xb9, 0xee, 0xfd, 0x90 }}

class NS_NO_VTABLE nsPIWindowWatcher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIWINDOWWATCHER_IID)

  /** A window has been created. Add it to our list.
      @param aWindow the window to add
      @param aChrome the corresponding chrome window. The DOM window
                     and chrome will be mapped together, and the corresponding
                     chrome can be retrieved using the (not private)
                     method getChromeForWindow. If null, any extant mapping
                     will be cleared.
  */
  /* void addWindow (in nsIDOMWindow aWindow, in nsIWebBrowserChrome aChrome); */
  NS_IMETHOD AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome) = 0;

  /** A window has been closed. Remove it from our list.
      @param aWindow the window to remove
  */
  /* void removeWindow (in nsIDOMWindow aWindow); */
  NS_IMETHOD RemoveWindow(nsIDOMWindow *aWindow) = 0;

  /** Like the public interface's open(), but can deal with openDialog
      style arguments.
      @param aParent parent window, if any. Null if no parent.  If it is
             impossible to get to an nsIWebBrowserChrome from aParent, this
             method will effectively act as if aParent were null.
      @param aURL url to which to open the new window. Must already be
             escaped, if applicable. can be null.
      @param aName window name from JS window.open. can be null.  If a window
             with this name already exists, the openWindow call may just load
             aUrl in it (if aUrl is not null) and return it.
      @param aFeatures window features from JS window.open. can be null.
      @param aDialog use dialog defaults (see nsIDOMWindowInternal::openDialog)
      @param aArgs Window argument
      @return the new window

      @note This method may examine the JS context stack for purposes of
            determining the security context to use for the search for a given
            window named aName.
      @note This method should try to set the default charset for the new
            window to the default charset of the document in the calling window
            (which is determined based on the JS stack and the value of
            aParent).  This is not guaranteed, however.
  */
  /* nsIDOMWindow openWindowJS (in nsIDOMWindow aParent, in string aUrl, in string aName, in string aFeatures, in boolean aDialog, in nsIArray aArgs); */
  NS_IMETHOD OpenWindowJS(nsIDOMWindow *aParent, const char *aUrl, const char *aName, const char *aFeatures, PRBool aDialog, nsIArray *aArgs, nsIDOMWindow **_retval NS_OUTPARAM) = 0;

  /**
   * Find a named docshell tree item amongst all windows registered
   * with the window watcher.  This may be a subframe in some window,
   * for example.
   *
   * @param aName the name of the window.  Must not be null.
   * @param aRequestor the tree item immediately making the request.
   *        We should make sure to not recurse down into its findItemWithName
   *        method.
   * @param aOriginalRequestor the original treeitem that made the request.
   *        Used for security checks.
   * @return the tree item with aName as the name, or null if there
   *         isn't one.  "Special" names, like _self, _top, etc, will be
   *         treated specially only if aRequestor is null; in that case they
   *         will be resolved relative to the first window the windowwatcher
   *         knows about.
   * @see findItemWithName methods on nsIDocShellTreeItem and
   *      nsIDocShellTreeOwner
   */
  /* nsIDocShellTreeItem findItemWithName (in wstring aName, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_IMETHOD FindItemWithName(const PRUnichar *aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIWindowWatcher, NS_PIWINDOWWATCHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIWINDOWWATCHER \
  NS_IMETHOD AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome); \
  NS_IMETHOD RemoveWindow(nsIDOMWindow *aWindow); \
  NS_IMETHOD OpenWindowJS(nsIDOMWindow *aParent, const char *aUrl, const char *aName, const char *aFeatures, PRBool aDialog, nsIArray *aArgs, nsIDOMWindow **_retval NS_OUTPARAM); \
  NS_IMETHOD FindItemWithName(const PRUnichar *aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIWINDOWWATCHER(_to) \
  NS_IMETHOD AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome) { return _to AddWindow(aWindow, aChrome); } \
  NS_IMETHOD RemoveWindow(nsIDOMWindow *aWindow) { return _to RemoveWindow(aWindow); } \
  NS_IMETHOD OpenWindowJS(nsIDOMWindow *aParent, const char *aUrl, const char *aName, const char *aFeatures, PRBool aDialog, nsIArray *aArgs, nsIDOMWindow **_retval NS_OUTPARAM) { return _to OpenWindowJS(aParent, aUrl, aName, aFeatures, aDialog, aArgs, _retval); } \
  NS_IMETHOD FindItemWithName(const PRUnichar *aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return _to FindItemWithName(aName, aRequestor, aOriginalRequestor, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIWINDOWWATCHER(_to) \
  NS_IMETHOD AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWindow(aWindow, aChrome); } \
  NS_IMETHOD RemoveWindow(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWindow(aWindow); } \
  NS_IMETHOD OpenWindowJS(nsIDOMWindow *aParent, const char *aUrl, const char *aName, const char *aFeatures, PRBool aDialog, nsIArray *aArgs, nsIDOMWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenWindowJS(aParent, aUrl, aName, aFeatures, aDialog, aArgs, _retval); } \
  NS_IMETHOD FindItemWithName(const PRUnichar *aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindItemWithName(aName, aRequestor, aOriginalRequestor, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIWindowWatcher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIWINDOWWATCHER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIWindowWatcher)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void addWindow (in nsIDOMWindow aWindow, in nsIWebBrowserChrome aChrome); */
NS_IMETHODIMP _MYCLASS_::AddWindow(nsIDOMWindow *aWindow, nsIWebBrowserChrome *aChrome)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP _MYCLASS_::RemoveWindow(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow openWindowJS (in nsIDOMWindow aParent, in string aUrl, in string aName, in string aFeatures, in boolean aDialog, in nsIArray aArgs); */
NS_IMETHODIMP _MYCLASS_::OpenWindowJS(nsIDOMWindow *aParent, const char *aUrl, const char *aName, const char *aFeatures, PRBool aDialog, nsIArray *aArgs, nsIDOMWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem findItemWithName (in wstring aName, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP _MYCLASS_::FindItemWithName(const PRUnichar *aName, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIWindowWatcher_h__ */
