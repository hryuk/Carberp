/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsISocketTransportService.idl
 */

#ifndef __gen_nsISocketTransportService_h__
#define __gen_nsISocketTransportService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISocketTransport; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsIRunnable; /* forward declaration */

class nsASocketHandler;
struct PRFileDesc;

/* starting interface:    nsISocketTransportService */
#define NS_ISOCKETTRANSPORTSERVICE_IID_STR "185b3a5d-8729-436d-9693-7bdccb9c2216"

#define NS_ISOCKETTRANSPORTSERVICE_IID \
  {0x185b3a5d, 0x8729, 0x436d, \
    { 0x96, 0x93, 0x7b, 0xdc, 0xcb, 0x9c, 0x22, 0x16 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISocketTransportService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOCKETTRANSPORTSERVICE_IID)

  /**
     * Creates a transport for a specified host and port.
     *
     * @param aSocketTypes
     *        array of socket type strings.  null if using default socket type.
     * @param aTypeCount
     *        specifies length of aSocketTypes.
     * @param aHost
     *        specifies the target hostname or IP address literal of the peer
     *        for this socket.
     * @param aPort
     *        specifies the target port of the peer for this socket.
     * @param aProxyInfo
     *        specifies the transport-layer proxy type to use.  null if no
     *        proxy.  used for communicating information about proxies like
     *        SOCKS (which are transparent to upper protocols).
     * 
     * @see nsIProxiedProtocolHandler
     * @see nsIProtocolProxyService::GetProxyInfo
     *
     * NOTE: this function can be called from any thread
     */
  /* nsISocketTransport createTransport ([array, size_is (aTypeCount)] in string aSocketTypes, in unsigned long aTypeCount, in AUTF8String aHost, in long aPort, in nsIProxyInfo aProxyInfo); */
  NS_SCRIPTABLE NS_IMETHOD CreateTransport(const char **aSocketTypes, PRUint32 aTypeCount, const nsACString & aHost, PRInt32 aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport **_retval NS_OUTPARAM) = 0;

  /**
     * Adds a new socket to the list of controlled sockets.
     *
     * This will fail with the error code NS_ERROR_NOT_AVAILABLE if the maximum
     * number of sockets is already reached.
     * In this case, the notifyWhenCanAttachSocket method should be used.
     *
     * @param aFd
     *        Open file descriptor of the socket to control.
     * @param aHandler
     *        Socket handler that will receive notifications when the socket is
     *        ready or detached.
     *
     * NOTE: this function may only be called from an event dispatch on the
     *       socket thread.
     */
  /* [noscript] void attachSocket (in PRFileDescPtr aFd, in nsASocketHandlerPtr aHandler); */
  NS_IMETHOD AttachSocket(PRFileDesc * aFd, nsASocketHandler * aHandler) = 0;

  /**
     * if the number of sockets reaches the limit, then consumers can be
     * notified when the number of sockets becomes less than the limit.  the
     * notification is asynchronous, delivered via the given nsIRunnable
     * instance on the socket transport thread.
     *
     * @param aEvent
     *        Event that will receive the notification when a new socket can
     *        be attached
     *
     * NOTE: this function may only be called from an event dispatch on the
     *       socket thread.
     */
  /* [noscript] void notifyWhenCanAttachSocket (in nsIRunnable aEvent); */
  NS_IMETHOD NotifyWhenCanAttachSocket(nsIRunnable *aEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISocketTransportService, NS_ISOCKETTRANSPORTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOCKETTRANSPORTSERVICE \
  NS_SCRIPTABLE NS_IMETHOD CreateTransport(const char **aSocketTypes, PRUint32 aTypeCount, const nsACString & aHost, PRInt32 aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport **_retval NS_OUTPARAM); \
  NS_IMETHOD AttachSocket(PRFileDesc * aFd, nsASocketHandler * aHandler); \
  NS_IMETHOD NotifyWhenCanAttachSocket(nsIRunnable *aEvent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOCKETTRANSPORTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateTransport(const char **aSocketTypes, PRUint32 aTypeCount, const nsACString & aHost, PRInt32 aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport **_retval NS_OUTPARAM) { return _to CreateTransport(aSocketTypes, aTypeCount, aHost, aPort, aProxyInfo, _retval); } \
  NS_IMETHOD AttachSocket(PRFileDesc * aFd, nsASocketHandler * aHandler) { return _to AttachSocket(aFd, aHandler); } \
  NS_IMETHOD NotifyWhenCanAttachSocket(nsIRunnable *aEvent) { return _to NotifyWhenCanAttachSocket(aEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOCKETTRANSPORTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateTransport(const char **aSocketTypes, PRUint32 aTypeCount, const nsACString & aHost, PRInt32 aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTransport(aSocketTypes, aTypeCount, aHost, aPort, aProxyInfo, _retval); } \
  NS_IMETHOD AttachSocket(PRFileDesc * aFd, nsASocketHandler * aHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->AttachSocket(aFd, aHandler); } \
  NS_IMETHOD NotifyWhenCanAttachSocket(nsIRunnable *aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyWhenCanAttachSocket(aEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSocketTransportService : public nsISocketTransportService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOCKETTRANSPORTSERVICE

  nsSocketTransportService();

private:
  ~nsSocketTransportService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSocketTransportService, nsISocketTransportService)

nsSocketTransportService::nsSocketTransportService()
{
  /* member initializers and constructor code */
}

nsSocketTransportService::~nsSocketTransportService()
{
  /* destructor code */
}

/* nsISocketTransport createTransport ([array, size_is (aTypeCount)] in string aSocketTypes, in unsigned long aTypeCount, in AUTF8String aHost, in long aPort, in nsIProxyInfo aProxyInfo); */
NS_IMETHODIMP nsSocketTransportService::CreateTransport(const char **aSocketTypes, PRUint32 aTypeCount, const nsACString & aHost, PRInt32 aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void attachSocket (in PRFileDescPtr aFd, in nsASocketHandlerPtr aHandler); */
NS_IMETHODIMP nsSocketTransportService::AttachSocket(PRFileDesc * aFd, nsASocketHandler * aHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void notifyWhenCanAttachSocket (in nsIRunnable aEvent); */
NS_IMETHODIMP nsSocketTransportService::NotifyWhenCanAttachSocket(nsIRunnable *aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISocketTransportService_h__ */
