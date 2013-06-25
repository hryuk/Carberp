/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/socket/base/nsISocketProvider.idl
 */

#ifndef __gen_nsISocketProvider_h__
#define __gen_nsISocketProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISocketProvider */
#define NS_ISOCKETPROVIDER_IID_STR "00b3df92-e830-11d8-d48e-0004e22243f8"

#define NS_ISOCKETPROVIDER_IID \
  {0x00b3df92, 0xe830, 0x11d8, \
    { 0xd4, 0x8e, 0x00, 0x04, 0xe2, 0x22, 0x43, 0xf8 }}

/**
 * nsISocketProvider
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISocketProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOCKETPROVIDER_IID)

  /**
     * newSocket
     *
     * @param aFamily
     *        The address family for this socket (PR_AF_INET or PR_AF_INET6).
     * @param aHost
     *        The hostname for this connection.
     * @param aPort
     *        The port for this connection.
     * @param aProxyHost
     *        If non-null, the proxy hostname for this connection.
     * @param aProxyPort
     *        The proxy port for this connection.
     * @param aFlags
     *        Control flags that govern this connection (see below.)
     * @param aFileDesc
     *        The resulting PRFileDesc.
     * @param aSecurityInfo
     *        Any security info that should be associated with aFileDesc.  This
     *        object typically implements nsITransportSecurityInfo.
     */
  /* [noscript] void newSocket (in long aFamily, in string aHost, in long aPort, in string aProxyHost, in long aProxyPort, in unsigned long aFlags, out PRFileDescStar aFileDesc, out nsISupports aSecurityInfo); */
  NS_IMETHOD NewSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * *aFileDesc NS_OUTPARAM, nsISupports **aSecurityInfo NS_OUTPARAM) = 0;

  /**
     * addToSocket
     *
     * This function is called to allow the socket provider to layer a
     * PRFileDesc on top of another PRFileDesc.  For example, SSL via a SOCKS
     * proxy.
     *
     * Parameters are the same as newSocket with the exception of aFileDesc,
     * which is an in-param instead.
     */
  /* [noscript] void addToSocket (in long aFamily, in string aHost, in long aPort, in string aProxyHost, in long aProxyPort, in unsigned long aFlags, in PRFileDescStar aFileDesc, out nsISupports aSecurityInfo); */
  NS_IMETHOD AddToSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * aFileDesc, nsISupports **aSecurityInfo NS_OUTPARAM) = 0;

  /**
     * PROXY_RESOLVES_HOST
     *
     * This flag is set if the proxy is to perform hostname resolution instead
     * of the client.  When set, the hostname parameter passed when in this
     * interface will be used instead of the address structure passed for a
     * later connect et al. request.
     */
  enum { PROXY_RESOLVES_HOST = 1 };

  /**
     * When setting this flag, the socket will not apply any
     * credentials when establishing a connection. For example,
     * an SSL connection would not send any client-certificates
     * if this flag is set.
     */
  enum { ANONYMOUS_CONNECT = 2 };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISocketProvider, NS_ISOCKETPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOCKETPROVIDER \
  NS_IMETHOD NewSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * *aFileDesc NS_OUTPARAM, nsISupports **aSecurityInfo NS_OUTPARAM); \
  NS_IMETHOD AddToSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * aFileDesc, nsISupports **aSecurityInfo NS_OUTPARAM); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOCKETPROVIDER(_to) \
  NS_IMETHOD NewSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * *aFileDesc NS_OUTPARAM, nsISupports **aSecurityInfo NS_OUTPARAM) { return _to NewSocket(aFamily, aHost, aPort, aProxyHost, aProxyPort, aFlags, aFileDesc, aSecurityInfo); } \
  NS_IMETHOD AddToSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * aFileDesc, nsISupports **aSecurityInfo NS_OUTPARAM) { return _to AddToSocket(aFamily, aHost, aPort, aProxyHost, aProxyPort, aFlags, aFileDesc, aSecurityInfo); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOCKETPROVIDER(_to) \
  NS_IMETHOD NewSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * *aFileDesc NS_OUTPARAM, nsISupports **aSecurityInfo NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewSocket(aFamily, aHost, aPort, aProxyHost, aProxyPort, aFlags, aFileDesc, aSecurityInfo); } \
  NS_IMETHOD AddToSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * aFileDesc, nsISupports **aSecurityInfo NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddToSocket(aFamily, aHost, aPort, aProxyHost, aProxyPort, aFlags, aFileDesc, aSecurityInfo); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSocketProvider : public nsISocketProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOCKETPROVIDER

  nsSocketProvider();

private:
  ~nsSocketProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSocketProvider, nsISocketProvider)

nsSocketProvider::nsSocketProvider()
{
  /* member initializers and constructor code */
}

nsSocketProvider::~nsSocketProvider()
{
  /* destructor code */
}

/* [noscript] void newSocket (in long aFamily, in string aHost, in long aPort, in string aProxyHost, in long aProxyPort, in unsigned long aFlags, out PRFileDescStar aFileDesc, out nsISupports aSecurityInfo); */
NS_IMETHODIMP nsSocketProvider::NewSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * *aFileDesc NS_OUTPARAM, nsISupports **aSecurityInfo NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void addToSocket (in long aFamily, in string aHost, in long aPort, in string aProxyHost, in long aProxyPort, in unsigned long aFlags, in PRFileDescStar aFileDesc, out nsISupports aSecurityInfo); */
NS_IMETHODIMP nsSocketProvider::AddToSocket(PRInt32 aFamily, const char *aHost, PRInt32 aPort, const char *aProxyHost, PRInt32 aProxyPort, PRUint32 aFlags, struct PRFileDesc * aFileDesc, nsISupports **aSecurityInfo NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * nsISocketProvider implementations should be registered with XPCOM under a
 * contract ID of the form: "@mozilla.org/network/socket;2?type=foo"
 */
#define NS_NETWORK_SOCKET_CONTRACTID_PREFIX \
    "@mozilla.org/network/socket;2?type="

#endif /* __gen_nsISocketProvider_h__ */
