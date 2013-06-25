/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMChromeWindow.idl
 */

#ifndef __gen_nsIDOMChromeWindow_h__
#define __gen_nsIDOMChromeWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBrowserDOMWindow; /* forward declaration */


/* starting interface:    nsIDOMChromeWindow */
#define NS_IDOMCHROMEWINDOW_IID_STR "77a20f5a-68ad-41d3-97ac-6ff721512908"

#define NS_IDOMCHROMEWINDOW_IID \
  {0x77a20f5a, 0x68ad, 0x41d3, \
    { 0x97, 0xac, 0x6f, 0xf7, 0x21, 0x51, 0x29, 0x08 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMChromeWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCHROMEWINDOW_IID)

  enum { STATE_MAXIMIZED = 1U };

  enum { STATE_MINIMIZED = 2U };

  enum { STATE_NORMAL = 3U };

  /* readonly attribute unsigned short windowState; */
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(PRUint16 *aWindowState) = 0;

  /**
   * browserDOMWindow provides access to yet another layer of
   * utility functions implemented by chrome script. It will be null
   * for DOMWindows not corresponding to browsers.
   */
  /* attribute nsIBrowserDOMWindow browserDOMWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow * aBrowserDOMWindow) = 0;

  /* void getAttention (); */
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void) = 0;

  /* void getAttentionWithCycleCount (in long aCycleCount); */
  NS_SCRIPTABLE NS_IMETHOD GetAttentionWithCycleCount(PRInt32 aCycleCount) = 0;

  /* void setCursor (in DOMString cursor); */
  NS_SCRIPTABLE NS_IMETHOD SetCursor(const nsAString & cursor) = 0;

  /* void maximize (); */
  NS_SCRIPTABLE NS_IMETHOD Maximize(void) = 0;

  /* void minimize (); */
  NS_SCRIPTABLE NS_IMETHOD Minimize(void) = 0;

  /* void restore (); */
  NS_SCRIPTABLE NS_IMETHOD Restore(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMChromeWindow, NS_IDOMCHROMEWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCHROMEWINDOW \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(PRUint16 *aWindowState); \
  NS_SCRIPTABLE NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow); \
  NS_SCRIPTABLE NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow * aBrowserDOMWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void); \
  NS_SCRIPTABLE NS_IMETHOD GetAttentionWithCycleCount(PRInt32 aCycleCount); \
  NS_SCRIPTABLE NS_IMETHOD SetCursor(const nsAString & cursor); \
  NS_SCRIPTABLE NS_IMETHOD Maximize(void); \
  NS_SCRIPTABLE NS_IMETHOD Minimize(void); \
  NS_SCRIPTABLE NS_IMETHOD Restore(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCHROMEWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(PRUint16 *aWindowState) { return _to GetWindowState(aWindowState); } \
  NS_SCRIPTABLE NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow) { return _to GetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow * aBrowserDOMWindow) { return _to SetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void) { return _to GetAttention(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttentionWithCycleCount(PRInt32 aCycleCount) { return _to GetAttentionWithCycleCount(aCycleCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetCursor(const nsAString & cursor) { return _to SetCursor(cursor); } \
  NS_SCRIPTABLE NS_IMETHOD Maximize(void) { return _to Maximize(); } \
  NS_SCRIPTABLE NS_IMETHOD Minimize(void) { return _to Minimize(); } \
  NS_SCRIPTABLE NS_IMETHOD Restore(void) { return _to Restore(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCHROMEWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(PRUint16 *aWindowState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowState(aWindowState); } \
  NS_SCRIPTABLE NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow * aBrowserDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttention(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttentionWithCycleCount(PRInt32 aCycleCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttentionWithCycleCount(aCycleCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetCursor(const nsAString & cursor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCursor(cursor); } \
  NS_SCRIPTABLE NS_IMETHOD Maximize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Maximize(); } \
  NS_SCRIPTABLE NS_IMETHOD Minimize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Minimize(); } \
  NS_SCRIPTABLE NS_IMETHOD Restore(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Restore(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMChromeWindow : public nsIDOMChromeWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCHROMEWINDOW

  nsDOMChromeWindow();

private:
  ~nsDOMChromeWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMChromeWindow, nsIDOMChromeWindow)

nsDOMChromeWindow::nsDOMChromeWindow()
{
  /* member initializers and constructor code */
}

nsDOMChromeWindow::~nsDOMChromeWindow()
{
  /* destructor code */
}

/* readonly attribute unsigned short windowState; */
NS_IMETHODIMP nsDOMChromeWindow::GetWindowState(PRUint16 *aWindowState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIBrowserDOMWindow browserDOMWindow; */
NS_IMETHODIMP nsDOMChromeWindow::GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMChromeWindow::SetBrowserDOMWindow(nsIBrowserDOMWindow * aBrowserDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttention (); */
NS_IMETHODIMP nsDOMChromeWindow::GetAttention()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttentionWithCycleCount (in long aCycleCount); */
NS_IMETHODIMP nsDOMChromeWindow::GetAttentionWithCycleCount(PRInt32 aCycleCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCursor (in DOMString cursor); */
NS_IMETHODIMP nsDOMChromeWindow::SetCursor(const nsAString & cursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void maximize (); */
NS_IMETHODIMP nsDOMChromeWindow::Maximize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void minimize (); */
NS_IMETHODIMP nsDOMChromeWindow::Minimize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restore (); */
NS_IMETHODIMP nsDOMChromeWindow::Restore()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMChromeWindow_h__ */
