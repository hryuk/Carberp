/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsISocketTransport.idl
 */

#ifndef __gen_nsISocketTransport_h__
#define __gen_nsISocketTransport_h__


#ifndef __gen_nsITransport_h__
#include "nsITransport.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsISocketTransport */
#define NS_ISOCKETTRANSPORT_IID_STR "ef3f4993-cfbc-4e5a-9509-16deafe16549"

#define NS_ISOCKETTRANSPORT_IID \
  {0xef3f4993, 0xcfbc, 0x4e5a, \
    { 0x95, 0x09, 0x16, 0xde, 0xaf, 0xe1, 0x65, 0x49 }}

/**
 * nsISocketTransport
 *
 * NOTE: Connection setup is triggered by opening an input or output stream,
 * it does not start on its own. Completion of the connection setup is
 * indicated by a STATUS_CONNECTED_TO notification to the event sink (if set).
 *
 * NOTE: This is a free-threaded interface, meaning that the methods on
 * this interface may be called from any thread.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISocketTransport : public nsITransport {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOCKETTRANSPORT_IID)

  /**
     * Get the host for the underlying socket connection.
     */
  /* readonly attribute AUTF8String host; */
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost) = 0;

  /**
     * Get the port for the underlying socket connection.
     */
  /* readonly attribute long port; */
  NS_SCRIPTABLE NS_IMETHOD GetPort(PRInt32 *aPort) = 0;

  /** 
     * Returns the IP address of the socket connection peer. This
     * attribute is defined only once a connection has been established.
     */
  /* [noscript] PRNetAddr getPeerAddr (); */
  NS_IMETHOD GetPeerAddr(union PRNetAddr *_retval NS_OUTPARAM) = 0;

  /** 
     * Returns the IP address of the initiating end. This attribute
     * is defined only once a connection has been established.
     */
  /* [noscript] PRNetAddr getSelfAddr (); */
  NS_IMETHOD GetSelfAddr(union PRNetAddr *_retval NS_OUTPARAM) = 0;

  /**
     * Security info object returned from the secure socket provider.  This
     * object supports nsISSLSocketControl, nsITransportSecurityInfo, and
     * possibly other interfaces.
     *
     * This attribute is only available once the socket is connected.
     */
  /* readonly attribute nsISupports securityInfo; */
  NS_SCRIPTABLE NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) = 0;

  /**
     * Security notification callbacks passed to the secure socket provider
     * via nsISSLSocketControl at socket creation time.
     *
     * NOTE: this attribute cannot be changed once a stream has been opened.
     */
  /* attribute nsIInterfaceRequestor securityCallbacks; */
  NS_SCRIPTABLE NS_IMETHOD GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSecurityCallbacks(nsIInterfaceRequestor * aSecurityCallbacks) = 0;

  /**
     * Test if this socket transport is (still) connected.
     */
  /* boolean isAlive (); */
  NS_SCRIPTABLE NS_IMETHOD IsAlive(PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Socket timeouts in seconds.  To specify no timeout, pass PR_UINT32_MAX
     * as aValue to setTimeout.  The implementation may truncate timeout values
     * to a smaller range of values (e.g., 0 to 0xFFFF).
     */
  /* unsigned long getTimeout (in unsigned long aType); */
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRUint32 aType, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* void setTimeout (in unsigned long aType, in unsigned long aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRUint32 aType, PRUint32 aValue) = 0;

  /**
     * Values for the aType parameter passed to get/setTimeout.
     */
  enum { TIMEOUT_CONNECT = 0U };

  enum { TIMEOUT_READ_WRITE = 1U };

  /**
     * nsITransportEventSink status codes.
     *
     * Although these look like XPCOM error codes and are passed in an nsresult
     * variable, they are *not* error codes.  Note that while they *do* overlap
     * with existing error codes in Necko, these status codes are confined
     * within a very limited context where no error codes may appear, so there
     * is no ambiguity.
     *
     * The values of these status codes must never change.
     *
     * The status codes appear in near-chronological order (not in numeric
     * order).  STATUS_RESOLVING may be skipped if the host does not need to be
     * resolved.  STATUS_WAITING_FOR is an optional status code, which the impl
     * of this interface may choose not to generate.
     */
  enum { STATUS_RESOLVING = 2152398851U };

  enum { STATUS_CONNECTING_TO = 2152398855U };

  enum { STATUS_CONNECTED_TO = 2152398852U };

  enum { STATUS_SENDING_TO = 2152398853U };

  enum { STATUS_WAITING_FOR = 2152398858U };

  enum { STATUS_RECEIVING_FROM = 2152398854U };

  /**
     * connectionFlags is a bitmask that can be used to modify underlying 
     * behavior of the socket connection.
     */
  /* attribute unsigned long connectionFlags; */
  NS_SCRIPTABLE NS_IMETHOD GetConnectionFlags(PRUint32 *aConnectionFlags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetConnectionFlags(PRUint32 aConnectionFlags) = 0;

  /**
     * Values for the connectionFlags
     *
     * When making a new connection BYPASS_CACHE will force the Necko DNS 
     * cache entry to be refreshed with a new call to NSPR if it is set before
     * opening the new stream.
     */
  enum { BYPASS_CACHE = 1U };

  /**
     * When setting this flag, the socket will not apply any
     * credentials when establishing a connection. For example,
     * an SSL connection would not send any client-certificates
     * if this flag is set.
     */
  enum { ANONYMOUS_CONNECT = 2U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISocketTransport, NS_ISOCKETTRANSPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOCKETTRANSPORT \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost); \
  NS_SCRIPTABLE NS_IMETHOD GetPort(PRInt32 *aPort); \
  NS_IMETHOD GetPeerAddr(union PRNetAddr *_retval NS_OUTPARAM); \
  NS_IMETHOD GetSelfAddr(union PRNetAddr *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo); \
  NS_SCRIPTABLE NS_IMETHOD GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks); \
  NS_SCRIPTABLE NS_IMETHOD SetSecurityCallbacks(nsIInterfaceRequestor * aSecurityCallbacks); \
  NS_SCRIPTABLE NS_IMETHOD IsAlive(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRUint32 aType, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRUint32 aType, PRUint32 aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetConnectionFlags(PRUint32 *aConnectionFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetConnectionFlags(PRUint32 aConnectionFlags); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOCKETTRANSPORT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost) { return _to GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(PRInt32 *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD GetPeerAddr(union PRNetAddr *_retval NS_OUTPARAM) { return _to GetPeerAddr(_retval); } \
  NS_IMETHOD GetSelfAddr(union PRNetAddr *_retval NS_OUTPARAM) { return _to GetSelfAddr(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return _to GetSecurityInfo(aSecurityInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks) { return _to GetSecurityCallbacks(aSecurityCallbacks); } \
  NS_SCRIPTABLE NS_IMETHOD SetSecurityCallbacks(nsIInterfaceRequestor * aSecurityCallbacks) { return _to SetSecurityCallbacks(aSecurityCallbacks); } \
  NS_SCRIPTABLE NS_IMETHOD IsAlive(PRBool *_retval NS_OUTPARAM) { return _to IsAlive(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRUint32 aType, PRUint32 *_retval NS_OUTPARAM) { return _to GetTimeout(aType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRUint32 aType, PRUint32 aValue) { return _to SetTimeout(aType, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetConnectionFlags(PRUint32 *aConnectionFlags) { return _to GetConnectionFlags(aConnectionFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetConnectionFlags(PRUint32 aConnectionFlags) { return _to SetConnectionFlags(aConnectionFlags); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOCKETTRANSPORT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(PRInt32 *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetPeerAddr(union PRNetAddr *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPeerAddr(_retval); } \
  NS_IMETHOD GetSelfAddr(union PRNetAddr *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelfAddr(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityInfo(aSecurityInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityCallbacks(aSecurityCallbacks); } \
  NS_SCRIPTABLE NS_IMETHOD SetSecurityCallbacks(nsIInterfaceRequestor * aSecurityCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityCallbacks(aSecurityCallbacks); } \
  NS_SCRIPTABLE NS_IMETHOD IsAlive(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAlive(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRUint32 aType, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeout(aType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRUint32 aType, PRUint32 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeout(aType, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetConnectionFlags(PRUint32 *aConnectionFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectionFlags(aConnectionFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetConnectionFlags(PRUint32 aConnectionFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConnectionFlags(aConnectionFlags); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSocketTransport : public nsISocketTransport
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOCKETTRANSPORT

  nsSocketTransport();

private:
  ~nsSocketTransport();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSocketTransport, nsISocketTransport)

nsSocketTransport::nsSocketTransport()
{
  /* member initializers and constructor code */
}

nsSocketTransport::~nsSocketTransport()
{
  /* destructor code */
}

/* readonly attribute AUTF8String host; */
NS_IMETHODIMP nsSocketTransport::GetHost(nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long port; */
NS_IMETHODIMP nsSocketTransport::GetPort(PRInt32 *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRNetAddr getPeerAddr (); */
NS_IMETHODIMP nsSocketTransport::GetPeerAddr(union PRNetAddr *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRNetAddr getSelfAddr (); */
NS_IMETHODIMP nsSocketTransport::GetSelfAddr(union PRNetAddr *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports securityInfo; */
NS_IMETHODIMP nsSocketTransport::GetSecurityInfo(nsISupports * *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInterfaceRequestor securityCallbacks; */
NS_IMETHODIMP nsSocketTransport::GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSocketTransport::SetSecurityCallbacks(nsIInterfaceRequestor * aSecurityCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isAlive (); */
NS_IMETHODIMP nsSocketTransport::IsAlive(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getTimeout (in unsigned long aType); */
NS_IMETHODIMP nsSocketTransport::GetTimeout(PRUint32 aType, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTimeout (in unsigned long aType, in unsigned long aValue); */
NS_IMETHODIMP nsSocketTransport::SetTimeout(PRUint32 aType, PRUint32 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long connectionFlags; */
NS_IMETHODIMP nsSocketTransport::GetConnectionFlags(PRUint32 *aConnectionFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSocketTransport::SetConnectionFlags(PRUint32 aConnectionFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * #define's for compatibility
 */
#define NS_NET_STATUS_RESOLVING_HOST nsISocketTransport::STATUS_RESOLVING
#define NS_NET_STATUS_CONNECTED_TO   nsISocketTransport::STATUS_CONNECTED_TO
#define NS_NET_STATUS_SENDING_TO     nsISocketTransport::STATUS_SENDING_TO
#define NS_NET_STATUS_RECEIVING_FROM nsISocketTransport::STATUS_RECEIVING_FROM
#define NS_NET_STATUS_CONNECTING_TO  nsISocketTransport::STATUS_CONNECTING_TO
#define NS_NET_STATUS_WAITING_FOR    nsISocketTransport::STATUS_WAITING_FOR

#endif /* __gen_nsISocketTransport_h__ */
