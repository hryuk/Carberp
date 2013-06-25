/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/boot/public/nsISSLStatusProvider.idl
 */

#ifndef __gen_nsISSLStatusProvider_h__
#define __gen_nsISSLStatusProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISSLStatusProvider */
#define NS_ISSLSTATUSPROVIDER_IID_STR "8de811f0-1dd2-11b2-8bf1-e9aa324984b2"

#define NS_ISSLSTATUSPROVIDER_IID \
  {0x8de811f0, 0x1dd2, 0x11b2, \
    { 0x8b, 0xf1, 0xe9, 0xaa, 0x32, 0x49, 0x84, 0xb2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISSLStatusProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISSLSTATUSPROVIDER_IID)

  /* readonly attribute nsISupports SSLStatus; */
  NS_SCRIPTABLE NS_IMETHOD GetSSLStatus(nsISupports * *aSSLStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISSLStatusProvider, NS_ISSLSTATUSPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISSLSTATUSPROVIDER \
  NS_SCRIPTABLE NS_IMETHOD GetSSLStatus(nsISupports * *aSSLStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISSLSTATUSPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSSLStatus(nsISupports * *aSSLStatus) { return _to GetSSLStatus(aSSLStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISSLSTATUSPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSSLStatus(nsISupports * *aSSLStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSSLStatus(aSSLStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSSLStatusProvider : public nsISSLStatusProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISSLSTATUSPROVIDER

  nsSSLStatusProvider();

private:
  ~nsSSLStatusProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSSLStatusProvider, nsISSLStatusProvider)

nsSSLStatusProvider::nsSSLStatusProvider()
{
  /* member initializers and constructor code */
}

nsSSLStatusProvider::~nsSSLStatusProvider()
{
  /* destructor code */
}

/* readonly attribute nsISupports SSLStatus; */
NS_IMETHODIMP nsSSLStatusProvider::GetSSLStatus(nsISupports * *aSSLStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISSLStatusProvider_h__ */
