/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/appshell/public/nsIXULWindow.idl
 */

#ifndef __gen_nsIXULWindow_h__
#define __gen_nsIXULWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsIDocShellTreeItem; /* forward declaration */

class nsIAppShell; /* forward declaration */

class nsIXULBrowserWindow; /* forward declaration */


/* starting interface:    nsIXULWindow */
#define NS_IXULWINDOW_IID_STR "c175a596-ee13-420a-aa74-13ad3a14deb1"

#define NS_IXULWINDOW_IID \
  {0xc175a596, 0xee13, 0x420a, \
    { 0xaa, 0x74, 0x13, 0xad, 0x3a, 0x14, 0xde, 0xb1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXULWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULWINDOW_IID)

  /**
   * The docshell owning the XUL for this window.
   */
  /* readonly attribute nsIDocShell docShell; */
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) = 0;

  /**
   * Indicates if this window is instrinsically sized.	
   */
  /* attribute boolean intrinsicallySized; */
  NS_SCRIPTABLE NS_IMETHOD GetIntrinsicallySized(PRBool *aIntrinsicallySized) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIntrinsicallySized(PRBool aIntrinsicallySized) = 0;

  /**
   * The primary content shell.  
   *
   * Note that this is a docshell tree item and therefore can not be assured of
   * what object it is. It could be an editor, a docshell, or a browser object.
   * Or down the road any other object that supports being a DocShellTreeItem
   * Query accordingly to determine the capabilities.
   */
  /* readonly attribute nsIDocShellTreeItem primaryContentShell; */
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) = 0;

  /**
   * The content shell specified by the supplied id.
   *
   * Note that this is a docshell tree item and therefore can not be assured of
   * what object it is.  It could be an editor, a docshell, or a browser object.
   * Or down the road any other object that supports being a DocShellTreeItem
   * Query accordingly to determine the capabilities.
   */
  /* nsIDocShellTreeItem getContentShellById (in wstring ID); */
  NS_SCRIPTABLE NS_IMETHOD GetContentShellById(const PRUnichar *ID, nsIDocShellTreeItem **_retval NS_OUTPARAM) = 0;

  /**
   * Tell this window that it has picked up a child XUL window
   * @param aChild the child window being added
   */
  /* void addChildWindow (in nsIXULWindow aChild); */
  NS_SCRIPTABLE NS_IMETHOD AddChildWindow(nsIXULWindow *aChild) = 0;

  /**
   * Tell this window that it has lost a child XUL window
   * @param aChild the child window being removed
   */
  /* void removeChildWindow (in nsIXULWindow aChild); */
  NS_SCRIPTABLE NS_IMETHOD RemoveChildWindow(nsIXULWindow *aChild) = 0;

  /**
   * Move the window to a centered position.
   * @param aRelative the window relative to which the window is moved.
   *                  See screen parameter for details. if null, the
   *                  window is centered relative to the main screen.
   * @param aScreen   PR_TRUE to center the window relative to the screen
   *                  containing aRelative. PR_FALSE to center it relative
   *                  to aRelative itself.
   * @param aAlert    PR_TRUE to move the window to an alert position,
   *                  generally centered horizontally and 1/3 down from the top.
   */
  /* void center (in nsIXULWindow aRelative, in boolean aScreen, in boolean aAlert); */
  NS_SCRIPTABLE NS_IMETHOD Center(nsIXULWindow *aRelative, PRBool aScreen, PRBool aAlert) = 0;

  /**
   * Shows the window as a modal window. That is, ensures that it is visible
   * and runs a local event loop, exiting only once the window has been closed.
   */
  /* void showModal (); */
  NS_SCRIPTABLE NS_IMETHOD ShowModal(void) = 0;

  enum { lowestZ = 0U };

  enum { loweredZ = 4U };

  enum { normalZ = 5U };

  enum { raisedZ = 6U };

  enum { highestZ = 9U };

  /* attribute unsigned long zLevel; */
  NS_SCRIPTABLE NS_IMETHOD GetZLevel(PRUint32 *aZLevel) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetZLevel(PRUint32 aZLevel) = 0;

  /**
   * contextFlags are from nsIWindowCreator2
   */
  /* attribute PRUint32 contextFlags; */
  NS_SCRIPTABLE NS_IMETHOD GetContextFlags(PRUint32 *aContextFlags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContextFlags(PRUint32 aContextFlags) = 0;

  /* attribute PRUint32 chromeFlags; */
  NS_SCRIPTABLE NS_IMETHOD GetChromeFlags(PRUint32 *aChromeFlags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetChromeFlags(PRUint32 aChromeFlags) = 0;

  /**
   * Create a new window.
   * @param aChromeFlags see nsIWebBrowserChrome
   * @return the newly minted window
   */
  /* nsIXULWindow createNewWindow (in PRInt32 aChromeFlags, in nsIAppShell aAppShell); */
  NS_SCRIPTABLE NS_IMETHOD CreateNewWindow(PRInt32 aChromeFlags, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM) = 0;

  /* attribute nsIXULBrowserWindow XULBrowserWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetXULBrowserWindow(nsIXULBrowserWindow * aXULBrowserWindow) = 0;

  /**
   * Back-door method to force application of chrome flags at a particular
   * time.  Do NOT call this unless you know what you're doing!  In particular,
   * calling this when this XUL window doesn't yet have a document in its
   * docshell could cause problems.
   */
  /* [noscript] void applyChromeFlags (); */
  NS_IMETHOD ApplyChromeFlags(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULWindow, NS_IXULWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULWINDOW \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell); \
  NS_SCRIPTABLE NS_IMETHOD GetIntrinsicallySized(PRBool *aIntrinsicallySized); \
  NS_SCRIPTABLE NS_IMETHOD SetIntrinsicallySized(PRBool aIntrinsicallySized); \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell); \
  NS_SCRIPTABLE NS_IMETHOD GetContentShellById(const PRUnichar *ID, nsIDocShellTreeItem **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddChildWindow(nsIXULWindow *aChild); \
  NS_SCRIPTABLE NS_IMETHOD RemoveChildWindow(nsIXULWindow *aChild); \
  NS_SCRIPTABLE NS_IMETHOD Center(nsIXULWindow *aRelative, PRBool aScreen, PRBool aAlert); \
  NS_SCRIPTABLE NS_IMETHOD ShowModal(void); \
  NS_SCRIPTABLE NS_IMETHOD GetZLevel(PRUint32 *aZLevel); \
  NS_SCRIPTABLE NS_IMETHOD SetZLevel(PRUint32 aZLevel); \
  NS_SCRIPTABLE NS_IMETHOD GetContextFlags(PRUint32 *aContextFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetContextFlags(PRUint32 aContextFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetChromeFlags(PRUint32 *aChromeFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetChromeFlags(PRUint32 aChromeFlags); \
  NS_SCRIPTABLE NS_IMETHOD CreateNewWindow(PRInt32 aChromeFlags, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow); \
  NS_SCRIPTABLE NS_IMETHOD SetXULBrowserWindow(nsIXULBrowserWindow * aXULBrowserWindow); \
  NS_IMETHOD ApplyChromeFlags(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return _to GetDocShell(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntrinsicallySized(PRBool *aIntrinsicallySized) { return _to GetIntrinsicallySized(aIntrinsicallySized); } \
  NS_SCRIPTABLE NS_IMETHOD SetIntrinsicallySized(PRBool aIntrinsicallySized) { return _to SetIntrinsicallySized(aIntrinsicallySized); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) { return _to GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentShellById(const PRUnichar *ID, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return _to GetContentShellById(ID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddChildWindow(nsIXULWindow *aChild) { return _to AddChildWindow(aChild); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChildWindow(nsIXULWindow *aChild) { return _to RemoveChildWindow(aChild); } \
  NS_SCRIPTABLE NS_IMETHOD Center(nsIXULWindow *aRelative, PRBool aScreen, PRBool aAlert) { return _to Center(aRelative, aScreen, aAlert); } \
  NS_SCRIPTABLE NS_IMETHOD ShowModal(void) { return _to ShowModal(); } \
  NS_SCRIPTABLE NS_IMETHOD GetZLevel(PRUint32 *aZLevel) { return _to GetZLevel(aZLevel); } \
  NS_SCRIPTABLE NS_IMETHOD SetZLevel(PRUint32 aZLevel) { return _to SetZLevel(aZLevel); } \
  NS_SCRIPTABLE NS_IMETHOD GetContextFlags(PRUint32 *aContextFlags) { return _to GetContextFlags(aContextFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetContextFlags(PRUint32 aContextFlags) { return _to SetContextFlags(aContextFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetChromeFlags(PRUint32 *aChromeFlags) { return _to GetChromeFlags(aChromeFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetChromeFlags(PRUint32 aChromeFlags) { return _to SetChromeFlags(aChromeFlags); } \
  NS_SCRIPTABLE NS_IMETHOD CreateNewWindow(PRInt32 aChromeFlags, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM) { return _to CreateNewWindow(aChromeFlags, aAppShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow) { return _to GetXULBrowserWindow(aXULBrowserWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetXULBrowserWindow(nsIXULBrowserWindow * aXULBrowserWindow) { return _to SetXULBrowserWindow(aXULBrowserWindow); } \
  NS_IMETHOD ApplyChromeFlags(void) { return _to ApplyChromeFlags(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShell(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntrinsicallySized(PRBool *aIntrinsicallySized) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntrinsicallySized(aIntrinsicallySized); } \
  NS_SCRIPTABLE NS_IMETHOD SetIntrinsicallySized(PRBool aIntrinsicallySized) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIntrinsicallySized(aIntrinsicallySized); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentShellById(const PRUnichar *ID, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentShellById(ID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddChildWindow(nsIXULWindow *aChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddChildWindow(aChild); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChildWindow(nsIXULWindow *aChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChildWindow(aChild); } \
  NS_SCRIPTABLE NS_IMETHOD Center(nsIXULWindow *aRelative, PRBool aScreen, PRBool aAlert) { return !_to ? NS_ERROR_NULL_POINTER : _to->Center(aRelative, aScreen, aAlert); } \
  NS_SCRIPTABLE NS_IMETHOD ShowModal(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowModal(); } \
  NS_SCRIPTABLE NS_IMETHOD GetZLevel(PRUint32 *aZLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZLevel(aZLevel); } \
  NS_SCRIPTABLE NS_IMETHOD SetZLevel(PRUint32 aZLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZLevel(aZLevel); } \
  NS_SCRIPTABLE NS_IMETHOD GetContextFlags(PRUint32 *aContextFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContextFlags(aContextFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetContextFlags(PRUint32 aContextFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContextFlags(aContextFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetChromeFlags(PRUint32 *aChromeFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeFlags(aChromeFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetChromeFlags(PRUint32 aChromeFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChromeFlags(aChromeFlags); } \
  NS_SCRIPTABLE NS_IMETHOD CreateNewWindow(PRInt32 aChromeFlags, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNewWindow(aChromeFlags, aAppShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXULBrowserWindow(aXULBrowserWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetXULBrowserWindow(nsIXULBrowserWindow * aXULBrowserWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetXULBrowserWindow(aXULBrowserWindow); } \
  NS_IMETHOD ApplyChromeFlags(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplyChromeFlags(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULWindow : public nsIXULWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULWINDOW

  nsXULWindow();

private:
  ~nsXULWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULWindow, nsIXULWindow)

nsXULWindow::nsXULWindow()
{
  /* member initializers and constructor code */
}

nsXULWindow::~nsXULWindow()
{
  /* destructor code */
}

/* readonly attribute nsIDocShell docShell; */
NS_IMETHODIMP nsXULWindow::GetDocShell(nsIDocShell * *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean intrinsicallySized; */
NS_IMETHODIMP nsXULWindow::GetIntrinsicallySized(PRBool *aIntrinsicallySized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetIntrinsicallySized(PRBool aIntrinsicallySized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem primaryContentShell; */
NS_IMETHODIMP nsXULWindow::GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem getContentShellById (in wstring ID); */
NS_IMETHODIMP nsXULWindow::GetContentShellById(const PRUnichar *ID, nsIDocShellTreeItem **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addChildWindow (in nsIXULWindow aChild); */
NS_IMETHODIMP nsXULWindow::AddChildWindow(nsIXULWindow *aChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeChildWindow (in nsIXULWindow aChild); */
NS_IMETHODIMP nsXULWindow::RemoveChildWindow(nsIXULWindow *aChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void center (in nsIXULWindow aRelative, in boolean aScreen, in boolean aAlert); */
NS_IMETHODIMP nsXULWindow::Center(nsIXULWindow *aRelative, PRBool aScreen, PRBool aAlert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showModal (); */
NS_IMETHODIMP nsXULWindow::ShowModal()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long zLevel; */
NS_IMETHODIMP nsXULWindow::GetZLevel(PRUint32 *aZLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetZLevel(PRUint32 aZLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRUint32 contextFlags; */
NS_IMETHODIMP nsXULWindow::GetContextFlags(PRUint32 *aContextFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetContextFlags(PRUint32 aContextFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRUint32 chromeFlags; */
NS_IMETHODIMP nsXULWindow::GetChromeFlags(PRUint32 *aChromeFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetChromeFlags(PRUint32 aChromeFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXULWindow createNewWindow (in PRInt32 aChromeFlags, in nsIAppShell aAppShell); */
NS_IMETHODIMP nsXULWindow::CreateNewWindow(PRInt32 aChromeFlags, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIXULBrowserWindow XULBrowserWindow; */
NS_IMETHODIMP nsXULWindow::GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetXULBrowserWindow(nsIXULBrowserWindow * aXULBrowserWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void applyChromeFlags (); */
NS_IMETHODIMP nsXULWindow::ApplyChromeFlags()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULWindow_h__ */
