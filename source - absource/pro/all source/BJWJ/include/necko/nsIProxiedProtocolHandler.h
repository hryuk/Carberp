/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIProxiedProtocolHandler.idl
 */

#ifndef __gen_nsIProxiedProtocolHandler_h__
#define __gen_nsIProxiedProtocolHandler_h__


#ifndef __gen_nsIProtocolHandler_h__
#include "nsIProtocolHandler.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIProxyInfo; /* forward declaration */


/* starting interface:    nsIProxiedProtocolHandler */
#define NS_IPROXIEDPROTOCOLHANDLER_IID_STR "0a24fed4-1dd2-11b2-a75c-9f8b9a8f9ba7"

#define NS_IPROXIEDPROTOCOLHANDLER_IID \
  {0x0a24fed4, 0x1dd2, 0x11b2, \
    { 0xa7, 0x5c, 0x9f, 0x8b, 0x9a, 0x8f, 0x9b, 0xa7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIProxiedProtocolHandler : public nsIProtocolHandler {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROXIEDPROTOCOLHANDLER_IID)

  /** Create a new channel with the given proxyInfo
     *
     */
  /* nsIChannel newProxiedChannel (in nsIURI uri, in nsIProxyInfo proxyInfo); */
  NS_SCRIPTABLE NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, nsIChannel **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProxiedProtocolHandler, NS_IPROXIEDPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROXIEDPROTOCOLHANDLER \
  NS_SCRIPTABLE NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, nsIChannel **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROXIEDPROTOCOLHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, nsIChannel **_retval NS_OUTPARAM) { return _to NewProxiedChannel(uri, proxyInfo, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROXIEDPROTOCOLHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, nsIChannel **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewProxiedChannel(uri, proxyInfo, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProxiedProtocolHandler : public nsIProxiedProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROXIEDPROTOCOLHANDLER

  nsProxiedProtocolHandler();

private:
  ~nsProxiedProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProxiedProtocolHandler, nsIProxiedProtocolHandler)

nsProxiedProtocolHandler::nsProxiedProtocolHandler()
{
  /* member initializers and constructor code */
}

nsProxiedProtocolHandler::~nsProxiedProtocolHandler()
{
  /* destructor code */
}

/* nsIChannel newProxiedChannel (in nsIURI uri, in nsIProxyInfo proxyInfo); */
NS_IMETHODIMP nsProxiedProtocolHandler::NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, nsIChannel **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProxiedProtocolHandler_h__ */
