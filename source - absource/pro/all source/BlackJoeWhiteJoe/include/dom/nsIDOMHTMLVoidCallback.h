/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMHTMLVoidCallback.idl
 */

#ifndef __gen_nsIDOMHTMLVoidCallback_h__
#define __gen_nsIDOMHTMLVoidCallback_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLVoidCallback */
#define NS_IDOMHTMLVOIDCALLBACK_IID_STR "4a17c0e2-fdd5-4855-a71c-b4c509dffa13"

#define NS_IDOMHTMLVOIDCALLBACK_IID \
  {0x4a17c0e2, 0xfdd5, 0x4855, \
    { 0xa7, 0x1c, 0xb4, 0xc5, 0x09, 0xdf, 0xfa, 0x13 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLVoidCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLVOIDCALLBACK_IID)

  /* void handleEvent (); */
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLVoidCallback, NS_IDOMHTMLVOIDCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLVOIDCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLVOIDCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(void) { return _to HandleEvent(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLVOIDCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLVoidCallback : public nsIDOMHTMLVoidCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLVOIDCALLBACK

  nsDOMHTMLVoidCallback();

private:
  ~nsDOMHTMLVoidCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLVoidCallback, nsIDOMHTMLVoidCallback)

nsDOMHTMLVoidCallback::nsDOMHTMLVoidCallback()
{
  /* member initializers and constructor code */
}

nsDOMHTMLVoidCallback::~nsDOMHTMLVoidCallback()
{
  /* destructor code */
}

/* void handleEvent (); */
NS_IMETHODIMP nsDOMHTMLVoidCallback::HandleEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLVoidCallback_h__ */
