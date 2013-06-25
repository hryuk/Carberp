/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIBrowserDOMWindow.idl
 */

#ifndef __gen_nsIBrowserDOMWindow_h__
#define __gen_nsIBrowserDOMWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIBrowserDOMWindow */
#define NS_IBROWSERDOMWINDOW_IID_STR "f9691a49-7fb3-4b54-bb11-a4f2e0b6eddb"

#define NS_IBROWSERDOMWINDOW_IID \
  {0xf9691a49, 0x7fb3, 0x4b54, \
    { 0xbb, 0x11, 0xa4, 0xf2, 0xe0, 0xb6, 0xed, 0xdb }}

/**
 * The C++ source has access to the browser script source through
 * nsIBrowserDOMWindow. It is intended to be attached to the chrome DOMWindow
 * of a toplevel browser window (a XUL window). A DOMWindow that does not
 * happen to be a browser chrome window will simply have no access to any such
 * interface.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIBrowserDOMWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERDOMWINDOW_IID)

  /**
   * Values for openURI's aWhere parameter.
   */
/**
   * Do whatever the default is based on application state, user preferences,
   * and the value of the aContext parameter to openURI.
   */
  enum { OPEN_DEFAULTWINDOW = 0 };

  /**
   * Open in the "current window".  If aOpener is provided, this should be the
   * top window in aOpener's window hierarchy, but exact behavior is
   * application-dependent.  If aOpener is not provided, it's up to the
   * application to decide what constitutes a "current window".
   */
  enum { OPEN_CURRENTWINDOW = 1 };

  /**
   * Open in a new window.
   */
  enum { OPEN_NEWWINDOW = 2 };

  /**
   * Open in a new content tab in the toplevel browser window corresponding to
   * this nsIBrowserDOMWindow.
   */
  enum { OPEN_NEWTAB = 3 };

  /**
   * Values for openURI's aContext parameter.  These affect the behavior of
   * OPEN_DEFAULTWINDOW.
   */
/**
   * external link (load request from another application, xremote, etc).
   */
  enum { OPEN_EXTERNAL = 1 };

  /**
   * internal open new window
   */
  enum { OPEN_NEW = 2 };

  /**
   * Load a URI

   * @param aURI the URI to open. null is allowed.  If null is passed in, no
   *             load will be done, though the window the load would have
   *             happened in will be returned.
   * @param aWhere see possible values described above.
   * @param aOpener window requesting the open (can be null).
   * @param aContext the context in which the URI is being opened. This
   *                 is used only when aWhere == OPEN_DEFAULTWINDOW.
   * @return the window into which the URI was opened.
  */
  /* nsIDOMWindow openURI (in nsIURI aURI, in nsIDOMWindow aOpener, in short aWhere, in short aContext); */
  NS_SCRIPTABLE NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, PRInt16 aWhere, PRInt16 aContext, nsIDOMWindow **_retval NS_OUTPARAM) = 0;

  /**
   * @param  aWindow the window to test.
   * @return whether the window is the main content window for any
   *         currently open tab in this toplevel browser window.
   */
  /* boolean isTabContentWindow (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserDOMWindow, NS_IBROWSERDOMWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERDOMWINDOW \
  NS_SCRIPTABLE NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, PRInt16 aWhere, PRInt16 aContext, nsIDOMWindow **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERDOMWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, PRInt16 aWhere, PRInt16 aContext, nsIDOMWindow **_retval NS_OUTPARAM) { return _to OpenURI(aURI, aOpener, aWhere, aContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, PRBool *_retval NS_OUTPARAM) { return _to IsTabContentWindow(aWindow, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERDOMWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, PRInt16 aWhere, PRInt16 aContext, nsIDOMWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenURI(aURI, aOpener, aWhere, aContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsTabContentWindow(aWindow, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserDOMWindow : public nsIBrowserDOMWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERDOMWINDOW

  nsBrowserDOMWindow();

private:
  ~nsBrowserDOMWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserDOMWindow, nsIBrowserDOMWindow)

nsBrowserDOMWindow::nsBrowserDOMWindow()
{
  /* member initializers and constructor code */
}

nsBrowserDOMWindow::~nsBrowserDOMWindow()
{
  /* destructor code */
}

/* nsIDOMWindow openURI (in nsIURI aURI, in nsIDOMWindow aOpener, in short aWhere, in short aContext); */
NS_IMETHODIMP nsBrowserDOMWindow::OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, PRInt16 aWhere, PRInt16 aContext, nsIDOMWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isTabContentWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsBrowserDOMWindow::IsTabContentWindow(nsIDOMWindow *aWindow, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserDOMWindow_h__ */
