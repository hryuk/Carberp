/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIProxiedChannel.idl
 */

#ifndef __gen_nsIProxiedChannel_h__
#define __gen_nsIProxiedChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIProxyInfo; /* forward declaration */


/* starting interface:    nsIProxiedChannel */
#define NS_IPROXIEDCHANNEL_IID_STR "6238f134-8c3f-4354-958f-dfd9d54a4446"

#define NS_IPROXIEDCHANNEL_IID \
  {0x6238f134, 0x8c3f, 0x4354, \
    { 0x95, 0x8f, 0xdf, 0xd9, 0xd5, 0x4a, 0x44, 0x46 }}

/**
 * An interface for accessing the proxy info that a channel was
 * constructed with.
 *
 * @see nsIProxiedProtocolHandler
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIProxiedChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROXIEDCHANNEL_IID)

  /**
   * Gets the proxy info the channel was constructed with. null or a
   * proxyInfo with type "direct" mean no proxy.
   *
   * The returned proxy info must not be modified.
   */
  /* readonly attribute nsIProxyInfo proxyInfo; */
  NS_SCRIPTABLE NS_IMETHOD GetProxyInfo(nsIProxyInfo * *aProxyInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProxiedChannel, NS_IPROXIEDCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROXIEDCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetProxyInfo(nsIProxyInfo * *aProxyInfo); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROXIEDCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetProxyInfo(nsIProxyInfo * *aProxyInfo) { return _to GetProxyInfo(aProxyInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROXIEDCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetProxyInfo(nsIProxyInfo * *aProxyInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProxyInfo(aProxyInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProxiedChannel : public nsIProxiedChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROXIEDCHANNEL

  nsProxiedChannel();

private:
  ~nsProxiedChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProxiedChannel, nsIProxiedChannel)

nsProxiedChannel::nsProxiedChannel()
{
  /* member initializers and constructor code */
}

nsProxiedChannel::~nsProxiedChannel()
{
  /* destructor code */
}

/* readonly attribute nsIProxyInfo proxyInfo; */
NS_IMETHODIMP nsProxiedChannel::GetProxyInfo(nsIProxyInfo * *aProxyInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProxiedChannel_h__ */
