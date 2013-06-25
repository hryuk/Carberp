/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/appshell/public/nsIAppShellService.idl
 */

#ifndef __gen_nsIAppShellService_h__
#define __gen_nsIAppShellService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXULWindow; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMWindowInternal; /* forward declaration */

class nsIAppShell; /* forward declaration */

struct JSContext;

/* starting interface:    nsIAppShellService */
#define NS_IAPPSHELLSERVICE_IID_STR "361facd0-6e9a-4ff1-a0d4-450744cf0023"

#define NS_IAPPSHELLSERVICE_IID \
  {0x361facd0, 0x6e9a, 0x4ff1, \
    { 0xa0, 0xd4, 0x45, 0x07, 0x44, 0xcf, 0x00, 0x23 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAppShellService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSHELLSERVICE_IID)

  /**
   * Create a window, which will be initially invisible.
   * @param aParent the parent window.  Can be null.
   * @param aUrl the contents of the new window.
   * @param aChromeMask chrome flags affecting the kind of OS border
   *                    given to the window. see nsIBrowserWindow for
   *                    bit/flag definitions.
   * @param aCallbacks interface providing C++ hooks for window initialization
   *                   before the window is made visible.  Can be null.
   *                   Deprecated.
   * @param aInitialWidth width, in pixels, of the window.  Width of window
   *                      at creation.  Can be overridden by the "width"
   *                      tag in the XUL.  Set to NS_SIZETOCONTENT to force
   *                      the window to wrap to its contents.
   * @param aInitialHeight like aInitialWidth, but subtly different.
   * @param aAppShell a widget "appshell" (event processor) to associate
   *        with the new window
   * @param aResult the newly created window is returned here.
   */
  enum { SIZE_TO_CONTENT = -1 };

  /* nsIXULWindow createTopLevelWindow (in nsIXULWindow aParent, in nsIURI aUrl, in PRUint32 aChromeMask, in long aInitialWidth, in long aInitialHeight, in nsIAppShell aAppShell); */
  NS_SCRIPTABLE NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM) = 0;

  /* [noscript] void createHiddenWindow (in nsIAppShell aAppShell); */
  NS_IMETHOD CreateHiddenWindow(nsIAppShell *aAppShell) = 0;

  /* void destroyHiddenWindow (); */
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void) = 0;

  /**
   * Return the (singleton) application hidden window, automatically created
   * and maintained by this AppShellService.
   * @param aResult the hidden window.  Do not unhide hidden window.
   *                Do not taunt hidden window.
   */
  /* readonly attribute nsIXULWindow hiddenWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow) = 0;

  /**
   * Return the (singleton) application hidden window, automatically created
   * and maintained by this AppShellService.
   * @param aResult the hidden window.  Do not unhide hidden window.
   *                Do not taunt hidden window.
   */
  /* readonly attribute nsIDOMWindowInternal hiddenDOMWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindowInternal * *aHiddenDOMWindow) = 0;

  /**
   * Return the (singleton) application hidden window as an nsIDOMWindowInternal,
   * and, the corresponding JavaScript context pointer.  This is useful
   * if you'd like to subsequently call OpenDialog on the hidden window.
   * @aHiddenDOMWindow the hidden window QI'd to type nsIDOMWindowInternal
   * @aJSContext       the corresponding JavaScript context
   */
  /* [noscript] void getHiddenWindowAndJSContext (out nsIDOMWindowInternal aHiddenDOMWindow, out JSContext aJSContext); */
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindowInternal **aHiddenDOMWindow NS_OUTPARAM, JSContext * *aJSContext NS_OUTPARAM) = 0;

  /**
   * Return true if the application hidden window was provided by the
   * application. If it wasn't, the default hidden window was used. This will
   * usually be false on all non-mac platforms.
   */
  /* readonly attribute boolean applicationProvidedHiddenWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetApplicationProvidedHiddenWindow(PRBool *aApplicationProvidedHiddenWindow) = 0;

  /**
   * Add a window to the application's registry of windows.  These windows
   * are generally shown in the Windows taskbar, and the application
   * knows it can't quit until it's out of registered windows.
   * @param aWindow the window to register
   * @note When this method is successful, it fires the global notification
   *       "xul-window-registered"
   */
  /* void registerTopLevelWindow (in nsIXULWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow) = 0;

  /**
   * Remove a window from the application's window registry. Note that
   * this method won't automatically attempt to quit the app when
   * the last window is unregistered. For that, see Quit().
   * @param aWindow you see the pattern
   */
  /* void unregisterTopLevelWindow (in nsIXULWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppShellService, NS_IAPPSHELLSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSHELLSERVICE \
  NS_SCRIPTABLE NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM); \
  NS_IMETHOD CreateHiddenWindow(nsIAppShell *aAppShell); \
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void); \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindowInternal * *aHiddenDOMWindow); \
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindowInternal **aHiddenDOMWindow NS_OUTPARAM, JSContext * *aJSContext NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationProvidedHiddenWindow(PRBool *aApplicationProvidedHiddenWindow); \
  NS_SCRIPTABLE NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSHELLSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM) { return _to CreateTopLevelWindow(aParent, aUrl, aChromeMask, aInitialWidth, aInitialHeight, aAppShell, _retval); } \
  NS_IMETHOD CreateHiddenWindow(nsIAppShell *aAppShell) { return _to CreateHiddenWindow(aAppShell); } \
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void) { return _to DestroyHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow) { return _to GetHiddenWindow(aHiddenWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindowInternal * *aHiddenDOMWindow) { return _to GetHiddenDOMWindow(aHiddenDOMWindow); } \
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindowInternal **aHiddenDOMWindow NS_OUTPARAM, JSContext * *aJSContext NS_OUTPARAM) { return _to GetHiddenWindowAndJSContext(aHiddenDOMWindow, aJSContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationProvidedHiddenWindow(PRBool *aApplicationProvidedHiddenWindow) { return _to GetApplicationProvidedHiddenWindow(aApplicationProvidedHiddenWindow); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow) { return _to RegisterTopLevelWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow) { return _to UnregisterTopLevelWindow(aWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSHELLSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTopLevelWindow(aParent, aUrl, aChromeMask, aInitialWidth, aInitialHeight, aAppShell, _retval); } \
  NS_IMETHOD CreateHiddenWindow(nsIAppShell *aAppShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateHiddenWindow(aAppShell); } \
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DestroyHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenWindow(aHiddenWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindowInternal * *aHiddenDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenDOMWindow(aHiddenDOMWindow); } \
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindowInternal **aHiddenDOMWindow NS_OUTPARAM, JSContext * *aJSContext NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenWindowAndJSContext(aHiddenDOMWindow, aJSContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationProvidedHiddenWindow(PRBool *aApplicationProvidedHiddenWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationProvidedHiddenWindow(aApplicationProvidedHiddenWindow); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterTopLevelWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterTopLevelWindow(aWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppShellService : public nsIAppShellService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSHELLSERVICE

  nsAppShellService();

private:
  ~nsAppShellService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppShellService, nsIAppShellService)

nsAppShellService::nsAppShellService()
{
  /* member initializers and constructor code */
}

nsAppShellService::~nsAppShellService()
{
  /* destructor code */
}

/* nsIXULWindow createTopLevelWindow (in nsIXULWindow aParent, in nsIURI aUrl, in PRUint32 aChromeMask, in long aInitialWidth, in long aInitialHeight, in nsIAppShell aAppShell); */
NS_IMETHODIMP nsAppShellService::CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIAppShell *aAppShell, nsIXULWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void createHiddenWindow (in nsIAppShell aAppShell); */
NS_IMETHODIMP nsAppShellService::CreateHiddenWindow(nsIAppShell *aAppShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroyHiddenWindow (); */
NS_IMETHODIMP nsAppShellService::DestroyHiddenWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXULWindow hiddenWindow; */
NS_IMETHODIMP nsAppShellService::GetHiddenWindow(nsIXULWindow * *aHiddenWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindowInternal hiddenDOMWindow; */
NS_IMETHODIMP nsAppShellService::GetHiddenDOMWindow(nsIDOMWindowInternal * *aHiddenDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getHiddenWindowAndJSContext (out nsIDOMWindowInternal aHiddenDOMWindow, out JSContext aJSContext); */
NS_IMETHODIMP nsAppShellService::GetHiddenWindowAndJSContext(nsIDOMWindowInternal **aHiddenDOMWindow NS_OUTPARAM, JSContext * *aJSContext NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean applicationProvidedHiddenWindow; */
NS_IMETHODIMP nsAppShellService::GetApplicationProvidedHiddenWindow(PRBool *aApplicationProvidedHiddenWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerTopLevelWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsAppShellService::RegisterTopLevelWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterTopLevelWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsAppShellService::UnregisterTopLevelWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppShellService_h__ */
