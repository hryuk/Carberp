/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/appshell/public/nsIXULBrowserWindow.idl
 */

#ifndef __gen_nsIXULBrowserWindow_h__
#define __gen_nsIXULBrowserWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */

class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIXULBrowserWindow */
#define NS_IXULBROWSERWINDOW_IID_STR "67a601df-f091-4894-a2e2-2e6cfebb35ea"

#define NS_IXULBROWSERWINDOW_IID \
  {0x67a601df, 0xf091, 0x4894, \
    { 0xa2, 0xe2, 0x2e, 0x6c, 0xfe, 0xbb, 0x35, 0xea }}

/**
 * The nsIXULBrowserWindow supplies the methods that may be called from the
 * internals of the browser area to tell the containing xul window to update
 * its ui. 
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXULBrowserWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULBROWSERWINDOW_IID)

  /**
   * Sets the status according to JS' version of status.
   */
  /* void setJSStatus (in AString status); */
  NS_SCRIPTABLE NS_IMETHOD SetJSStatus(const nsAString & status) = 0;

  /**
   * Sets the default status according to JS' version of default status.
   */
  /* void setJSDefaultStatus (in AString status); */
  NS_SCRIPTABLE NS_IMETHOD SetJSDefaultStatus(const nsAString & status) = 0;

  /**
   * Tells the object implementing this function what link we are currently
   * over.
   */
  /* void setOverLink (in AString link, in nsIDOMElement element); */
  NS_SCRIPTABLE NS_IMETHOD SetOverLink(const nsAString & link, nsIDOMElement *element) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULBrowserWindow, NS_IXULBROWSERWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULBROWSERWINDOW \
  NS_SCRIPTABLE NS_IMETHOD SetJSStatus(const nsAString & status); \
  NS_SCRIPTABLE NS_IMETHOD SetJSDefaultStatus(const nsAString & status); \
  NS_SCRIPTABLE NS_IMETHOD SetOverLink(const nsAString & link, nsIDOMElement *element); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULBROWSERWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetJSStatus(const nsAString & status) { return _to SetJSStatus(status); } \
  NS_SCRIPTABLE NS_IMETHOD SetJSDefaultStatus(const nsAString & status) { return _to SetJSDefaultStatus(status); } \
  NS_SCRIPTABLE NS_IMETHOD SetOverLink(const nsAString & link, nsIDOMElement *element) { return _to SetOverLink(link, element); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULBROWSERWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetJSStatus(const nsAString & status) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetJSStatus(status); } \
  NS_SCRIPTABLE NS_IMETHOD SetJSDefaultStatus(const nsAString & status) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetJSDefaultStatus(status); } \
  NS_SCRIPTABLE NS_IMETHOD SetOverLink(const nsAString & link, nsIDOMElement *element) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOverLink(link, element); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULBrowserWindow : public nsIXULBrowserWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULBROWSERWINDOW

  nsXULBrowserWindow();

private:
  ~nsXULBrowserWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULBrowserWindow, nsIXULBrowserWindow)

nsXULBrowserWindow::nsXULBrowserWindow()
{
  /* member initializers and constructor code */
}

nsXULBrowserWindow::~nsXULBrowserWindow()
{
  /* destructor code */
}

/* void setJSStatus (in AString status); */
NS_IMETHODIMP nsXULBrowserWindow::SetJSStatus(const nsAString & status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setJSDefaultStatus (in AString status); */
NS_IMETHODIMP nsXULBrowserWindow::SetJSDefaultStatus(const nsAString & status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setOverLink (in AString link, in nsIDOMElement element); */
NS_IMETHODIMP nsXULBrowserWindow::SetOverLink(const nsAString & link, nsIDOMElement *element)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULBrowserWindow_h__ */
