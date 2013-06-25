/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIOCSPResponder.idl
 */

#ifndef __gen_nsIOCSPResponder_h__
#define __gen_nsIOCSPResponder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIOCSPResponder */
#define NS_IOCSPRESPONDER_IID_STR "96b2f5ae-4334-11d5-ba27-00108303b117"

#define NS_IOCSPRESPONDER_IID \
  {0x96b2f5ae, 0x4334, 0x11d5, \
    { 0xba, 0x27, 0x00, 0x10, 0x83, 0x03, 0xb1, 0x17 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIOCSPResponder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOCSPRESPONDER_IID)

  /* readonly attribute wstring responseSigner; */
  NS_SCRIPTABLE NS_IMETHOD GetResponseSigner(PRUnichar * *aResponseSigner) = 0;

  /* readonly attribute wstring serviceURL; */
  NS_SCRIPTABLE NS_IMETHOD GetServiceURL(PRUnichar * *aServiceURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOCSPResponder, NS_IOCSPRESPONDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOCSPRESPONDER \
  NS_SCRIPTABLE NS_IMETHOD GetResponseSigner(PRUnichar * *aResponseSigner); \
  NS_SCRIPTABLE NS_IMETHOD GetServiceURL(PRUnichar * *aServiceURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOCSPRESPONDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResponseSigner(PRUnichar * *aResponseSigner) { return _to GetResponseSigner(aResponseSigner); } \
  NS_SCRIPTABLE NS_IMETHOD GetServiceURL(PRUnichar * *aServiceURL) { return _to GetServiceURL(aServiceURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOCSPRESPONDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResponseSigner(PRUnichar * *aResponseSigner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseSigner(aResponseSigner); } \
  NS_SCRIPTABLE NS_IMETHOD GetServiceURL(PRUnichar * *aServiceURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceURL(aServiceURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOCSPResponder : public nsIOCSPResponder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOCSPRESPONDER

  nsOCSPResponder();

private:
  ~nsOCSPResponder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOCSPResponder, nsIOCSPResponder)

nsOCSPResponder::nsOCSPResponder()
{
  /* member initializers and constructor code */
}

nsOCSPResponder::~nsOCSPResponder()
{
  /* destructor code */
}

/* readonly attribute wstring responseSigner; */
NS_IMETHODIMP nsOCSPResponder::GetResponseSigner(PRUnichar * *aResponseSigner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring serviceURL; */
NS_IMETHODIMP nsOCSPResponder::GetServiceURL(PRUnichar * *aServiceURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIOCSPResponder_h__ */
