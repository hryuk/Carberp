/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/browser/webBrowser/nsIWebBrowserChrome2.idl
 */

#ifndef __gen_nsIWebBrowserChrome2_h__
#define __gen_nsIWebBrowserChrome2_h__


#ifndef __gen_nsIWebBrowserChrome_h__
#include "nsIWebBrowserChrome.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWebBrowserChrome2 */
#define NS_IWEBBROWSERCHROME2_IID_STR "2585a7b1-7b47-43c4-bf17-c6bf84e09b7b"

#define NS_IWEBBROWSERCHROME2_IID \
  {0x2585a7b1, 0x7b47, 0x43c4, \
    { 0xbf, 0x17, 0xc6, 0xbf, 0x84, 0xe0, 0x9b, 0x7b }}

/**
 * nsIWebBrowserChrome2 is an extension to nsIWebBrowserChrome.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWebBrowserChrome2 : public nsIWebBrowserChrome {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERCHROME2_IID)

  /**
   * Called when the status text in the chrome needs to be updated.  This
   * method may be called instead of nsIWebBrowserChrome::SetStatus.  An
   * implementor of this method, should still implement SetStatus.
   *
   * @param statusType
   *        Indicates what is setting the text.
   * @param status
   *        Status string.  Null is an acceptable value meaning no status.
   * @param contextNode 
   *        An object that provides context pertaining to the status type.
   *        If statusType is STATUS_LINK, then statusContext may be a DOM
   *        node corresponding to the source of the link.  This value can
   *        be null if there is no context.
   */
  /* void setStatusWithContext (in unsigned long statusType, in AString statusText, in nsISupports statusContext); */
  NS_SCRIPTABLE NS_IMETHOD SetStatusWithContext(PRUint32 statusType, const nsAString & statusText, nsISupports *statusContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserChrome2, NS_IWEBBROWSERCHROME2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERCHROME2 \
  NS_SCRIPTABLE NS_IMETHOD SetStatusWithContext(PRUint32 statusType, const nsAString & statusText, nsISupports *statusContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERCHROME2(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetStatusWithContext(PRUint32 statusType, const nsAString & statusText, nsISupports *statusContext) { return _to SetStatusWithContext(statusType, statusText, statusContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERCHROME2(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetStatusWithContext(PRUint32 statusType, const nsAString & statusText, nsISupports *statusContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStatusWithContext(statusType, statusText, statusContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserChrome2 : public nsIWebBrowserChrome2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERCHROME2

  nsWebBrowserChrome2();

private:
  ~nsWebBrowserChrome2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserChrome2, nsIWebBrowserChrome2)

nsWebBrowserChrome2::nsWebBrowserChrome2()
{
  /* member initializers and constructor code */
}

nsWebBrowserChrome2::~nsWebBrowserChrome2()
{
  /* destructor code */
}

/* void setStatusWithContext (in unsigned long statusType, in AString statusText, in nsISupports statusContext); */
NS_IMETHODIMP nsWebBrowserChrome2::SetStatusWithContext(PRUint32 statusType, const nsAString & statusText, nsISupports *statusContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserChrome2_h__ */
