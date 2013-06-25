/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIProtocolProxyCallback.idl
 */

#ifndef __gen_nsIProtocolProxyCallback_h__
#define __gen_nsIProtocolProxyCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsICancelable; /* forward declaration */


/* starting interface:    nsIProtocolProxyCallback */
#define NS_IPROTOCOLPROXYCALLBACK_IID_STR "a9967200-f95e-45c2-beb3-9b060d874bfd"

#define NS_IPROTOCOLPROXYCALLBACK_IID \
  {0xa9967200, 0xf95e, 0x45c2, \
    { 0xbe, 0xb3, 0x9b, 0x06, 0x0d, 0x87, 0x4b, 0xfd }}

/**
 * This interface serves as a closure for nsIProtocolProxyService's
 * asyncResolve method.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIProtocolProxyCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLPROXYCALLBACK_IID)

  /**
   * This method is called when proxy info is available or when an error
   * in the proxy resolution occurs.
   *
   * @param aRequest
   *        The value returned from asyncResolve.
   * @param aURI
   *        The URI passed to asyncResolve.
   * @param aProxyInfo
   *        The resulting proxy info or null if there is no associated proxy
   *        info for aURI.  As with the result of nsIProtocolProxyService's
   *        resolve method, a null result implies that a direct connection
   *        should be used.
   * @param aStatus
   *        The status of the callback.  This is a failure code if the request
   *        could not be satisfied, in which case the value of aStatus
   *        indicates the reason for the failure and aProxyInfo will be null.
   */
  /* void onProxyAvailable (in nsICancelable aRequest, in nsIURI aURI, in nsIProxyInfo aProxyInfo, in nsresult aStatus); */
  NS_SCRIPTABLE NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolProxyCallback, NS_IPROTOCOLPROXYCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLPROXYCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLPROXYCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus) { return _to OnProxyAvailable(aRequest, aURI, aProxyInfo, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLPROXYCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProxyAvailable(aRequest, aURI, aProxyInfo, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolProxyCallback : public nsIProtocolProxyCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLPROXYCALLBACK

  nsProtocolProxyCallback();

private:
  ~nsProtocolProxyCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProtocolProxyCallback, nsIProtocolProxyCallback)

nsProtocolProxyCallback::nsProtocolProxyCallback()
{
  /* member initializers and constructor code */
}

nsProtocolProxyCallback::~nsProtocolProxyCallback()
{
  /* destructor code */
}

/* void onProxyAvailable (in nsICancelable aRequest, in nsIURI aURI, in nsIProxyInfo aProxyInfo, in nsresult aStatus); */
NS_IMETHODIMP nsProtocolProxyCallback::OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProtocolProxyCallback_h__ */
