/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/appshell/public/nsIWindowMediatorListener.idl
 */

#ifndef __gen_nsIWindowMediatorListener_h__
#define __gen_nsIWindowMediatorListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXULWindow; /* forward declaration */


/* starting interface:    nsIWindowMediatorListener */
#define NS_IWINDOWMEDIATORLISTENER_IID_STR "2f276982-0d60-4377-a595-d350ba516395"

#define NS_IWINDOWMEDIATORLISTENER_IID \
  {0x2f276982, 0x0d60, 0x4377, \
    { 0xa5, 0x95, 0xd3, 0x50, 0xba, 0x51, 0x63, 0x95 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWindowMediatorListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWMEDIATORLISTENER_IID)

  /* void onWindowTitleChange (in nsIXULWindow window, in wstring newTitle); */
  NS_SCRIPTABLE NS_IMETHOD OnWindowTitleChange(nsIXULWindow *window, const PRUnichar *newTitle) = 0;

  /* void onOpenWindow (in nsIXULWindow window); */
  NS_SCRIPTABLE NS_IMETHOD OnOpenWindow(nsIXULWindow *window) = 0;

  /* void onCloseWindow (in nsIXULWindow window); */
  NS_SCRIPTABLE NS_IMETHOD OnCloseWindow(nsIXULWindow *window) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowMediatorListener, NS_IWINDOWMEDIATORLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWMEDIATORLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnWindowTitleChange(nsIXULWindow *window, const PRUnichar *newTitle); \
  NS_SCRIPTABLE NS_IMETHOD OnOpenWindow(nsIXULWindow *window); \
  NS_SCRIPTABLE NS_IMETHOD OnCloseWindow(nsIXULWindow *window); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWMEDIATORLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnWindowTitleChange(nsIXULWindow *window, const PRUnichar *newTitle) { return _to OnWindowTitleChange(window, newTitle); } \
  NS_SCRIPTABLE NS_IMETHOD OnOpenWindow(nsIXULWindow *window) { return _to OnOpenWindow(window); } \
  NS_SCRIPTABLE NS_IMETHOD OnCloseWindow(nsIXULWindow *window) { return _to OnCloseWindow(window); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWMEDIATORLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnWindowTitleChange(nsIXULWindow *window, const PRUnichar *newTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWindowTitleChange(window, newTitle); } \
  NS_SCRIPTABLE NS_IMETHOD OnOpenWindow(nsIXULWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnOpenWindow(window); } \
  NS_SCRIPTABLE NS_IMETHOD OnCloseWindow(nsIXULWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCloseWindow(window); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowMediatorListener : public nsIWindowMediatorListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWMEDIATORLISTENER

  nsWindowMediatorListener();

private:
  ~nsWindowMediatorListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowMediatorListener, nsIWindowMediatorListener)

nsWindowMediatorListener::nsWindowMediatorListener()
{
  /* member initializers and constructor code */
}

nsWindowMediatorListener::~nsWindowMediatorListener()
{
  /* destructor code */
}

/* void onWindowTitleChange (in nsIXULWindow window, in wstring newTitle); */
NS_IMETHODIMP nsWindowMediatorListener::OnWindowTitleChange(nsIXULWindow *window, const PRUnichar *newTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onOpenWindow (in nsIXULWindow window); */
NS_IMETHODIMP nsWindowMediatorListener::OnOpenWindow(nsIXULWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCloseWindow (in nsIXULWindow window); */
NS_IMETHODIMP nsWindowMediatorListener::OnCloseWindow(nsIXULWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowMediatorListener_h__ */
