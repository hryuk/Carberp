/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIServerSocket.idl
 */

#ifndef __gen_nsIServerSocket_h__
#define __gen_nsIServerSocket_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIServerSocketListener; /* forward declaration */

class nsISocketTransport; /* forward declaration */


/* starting interface:    nsIServerSocket */
#define NS_ISERVERSOCKET_IID_STR "a5b64be0-d563-46bb-ae95-132e46fcd42f"

#define NS_ISERVERSOCKET_IID \
  {0xa5b64be0, 0xd563, 0x46bb, \
    { 0xae, 0x95, 0x13, 0x2e, 0x46, 0xfc, 0xd4, 0x2f }}

/**
 * nsIServerSocket
 *
 * An interface to a server socket that can accept incoming connections.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIServerSocket : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISERVERSOCKET_IID)

  /**
     * init
     *
     * This method initializes a server socket.
     *
     * @param aPort
     *        The port of the server socket.  Pass -1 to indicate no preference,
     *        and a port will be selected automatically.
     * @param aLoopbackOnly
     *        If true, the server socket will only respond to connections on the
     *        local loopback interface.  Otherwise, it will accept connections
     *        from any interface.  To specify a particular network interface,
     *        use initWithAddress.
     * @param aBackLog
     *        The maximum length the queue of pending connections may grow to.
     *        This parameter may be silently limited by the operating system.
     *        Pass -1 to use the default value.
     */
  /* void init (in long aPort, in boolean aLoopbackOnly, in long aBackLog); */
  NS_SCRIPTABLE NS_IMETHOD Init(PRInt32 aPort, PRBool aLoopbackOnly, PRInt32 aBackLog) = 0;

  /**
     * initWithAddress
     *
     * This method initializes a server socket, and binds it to a particular
     * local address (and hence a particular local network interface).
     *
     * @param aAddr
     *        The address to which this server socket should be bound.
     * @param aBackLog
     *        The maximum length the queue of pending connections may grow to.
     *        This parameter may be silently limited by the operating system.
     *        Pass -1 to use the default value.
     */
  /* [noscript] void initWithAddress ([const] in PRNetAddrPtr aAddr, in long aBackLog); */
  NS_IMETHOD InitWithAddress(const union PRNetAddr * aAddr, PRInt32 aBackLog) = 0;

  /**
     * close
     *
     * This method closes a server socket.  This does not affect already
     * connected client sockets (i.e., the nsISocketTransport instances
     * created from this server socket).  This will cause the onStopListening
     * event to asynchronously fire with a status of NS_BINDING_ABORTED.
     */
  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /**
     * asyncListen
     *
     * This method puts the server socket in the listening state.  It will
     * asynchronously listen for and accept client connections.  The listener
     * will be notified once for each client connection that is accepted.  The
     * listener's onSocketAccepted method will be called on the same thread
     * that called asyncListen (the calling thread must have a nsIEventTarget).
     *
     * The listener will be passed a reference to an already connected socket
     * transport (nsISocketTransport).  See below for more details.
     *
     * @param aListener
     *        The listener to be notified when client connections are accepted.
     */
  /* void asyncListen (in nsIServerSocketListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD AsyncListen(nsIServerSocketListener *aListener) = 0;

  /**
     * Returns the port of this server socket.
     */
  /* readonly attribute long port; */
  NS_SCRIPTABLE NS_IMETHOD GetPort(PRInt32 *aPort) = 0;

  /**
     * Returns the address to which this server socket is bound.  Since a
     * server socket may be bound to multiple network devices, this address
     * may not necessarily be specific to a single network device.  In the
     * case of an IP socket, the IP address field would be zerod out to
     * indicate a server socket bound to all network devices.  Therefore,
     * this method cannot be used to determine the IP address of the local
     * system.  See nsIDNSService::myHostName if this is what you need.
     */
  /* [noscript] PRNetAddr getAddress (); */
  NS_IMETHOD GetAddress(union PRNetAddr *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIServerSocket, NS_ISERVERSOCKET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISERVERSOCKET \
  NS_SCRIPTABLE NS_IMETHOD Init(PRInt32 aPort, PRBool aLoopbackOnly, PRInt32 aBackLog); \
  NS_IMETHOD InitWithAddress(const union PRNetAddr * aAddr, PRInt32 aBackLog); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD AsyncListen(nsIServerSocketListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD GetPort(PRInt32 *aPort); \
  NS_IMETHOD GetAddress(union PRNetAddr *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISERVERSOCKET(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRInt32 aPort, PRBool aLoopbackOnly, PRInt32 aBackLog) { return _to Init(aPort, aLoopbackOnly, aBackLog); } \
  NS_IMETHOD InitWithAddress(const union PRNetAddr * aAddr, PRInt32 aBackLog) { return _to InitWithAddress(aAddr, aBackLog); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncListen(nsIServerSocketListener *aListener) { return _to AsyncListen(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(PRInt32 *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD GetAddress(union PRNetAddr *_retval NS_OUTPARAM) { return _to GetAddress(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISERVERSOCKET(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRInt32 aPort, PRBool aLoopbackOnly, PRInt32 aBackLog) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aPort, aLoopbackOnly, aBackLog); } \
  NS_IMETHOD InitWithAddress(const union PRNetAddr * aAddr, PRInt32 aBackLog) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithAddress(aAddr, aBackLog); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncListen(nsIServerSocketListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncListen(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(PRInt32 *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetAddress(union PRNetAddr *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddress(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsServerSocket : public nsIServerSocket
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISERVERSOCKET

  nsServerSocket();

private:
  ~nsServerSocket();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsServerSocket, nsIServerSocket)

nsServerSocket::nsServerSocket()
{
  /* member initializers and constructor code */
}

nsServerSocket::~nsServerSocket()
{
  /* destructor code */
}

/* void init (in long aPort, in boolean aLoopbackOnly, in long aBackLog); */
NS_IMETHODIMP nsServerSocket::Init(PRInt32 aPort, PRBool aLoopbackOnly, PRInt32 aBackLog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initWithAddress ([const] in PRNetAddrPtr aAddr, in long aBackLog); */
NS_IMETHODIMP nsServerSocket::InitWithAddress(const union PRNetAddr * aAddr, PRInt32 aBackLog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsServerSocket::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncListen (in nsIServerSocketListener aListener); */
NS_IMETHODIMP nsServerSocket::AsyncListen(nsIServerSocketListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long port; */
NS_IMETHODIMP nsServerSocket::GetPort(PRInt32 *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRNetAddr getAddress (); */
NS_IMETHODIMP nsServerSocket::GetAddress(union PRNetAddr *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIServerSocketListener */
#define NS_ISERVERSOCKETLISTENER_IID_STR "836d98ec-fee2-4bde-b609-abd5e966eabd"

#define NS_ISERVERSOCKETLISTENER_IID \
  {0x836d98ec, 0xfee2, 0x4bde, \
    { 0xb6, 0x09, 0xab, 0xd5, 0xe9, 0x66, 0xea, 0xbd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIServerSocketListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISERVERSOCKETLISTENER_IID)

  /**
 * nsIServerSocketListener
 *
 * This interface is notified whenever a server socket accepts a new connection.
 * The transport is in the connected state, and read/write streams can be opened
 * using the normal nsITransport API.  The address of the client can be found by
 * calling the nsISocketTransport::GetAddress method or by inspecting
 * nsISocketTransport::GetHost, which returns a string representation of the
 * client's IP address (NOTE: this may be an IPv4 or IPv6 string literal).
 */
/**
     * onSocketAccepted
     *
     * This method is called when a client connection is accepted.
     *
     * @param aServ
     *        The server socket.
     * @param aTransport
     *        The connected socket transport.
     */
  /* void onSocketAccepted (in nsIServerSocket aServ, in nsISocketTransport aTransport); */
  NS_SCRIPTABLE NS_IMETHOD OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport) = 0;

  /**
     * onStopListening
     *
     * This method is called when the listening socket stops for some reason.
     * The server socket is effectively dead after this notification.
     *
     * @param aServ
     *        The server socket.
     * @param aStatus
     *        The reason why the server socket stopped listening.  If the
     *        server socket was manually closed, then this value will be
     *        NS_BINDING_ABORTED.
     */
  /* void onStopListening (in nsIServerSocket aServ, in nsresult aStatus); */
  NS_SCRIPTABLE NS_IMETHOD OnStopListening(nsIServerSocket *aServ, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIServerSocketListener, NS_ISERVERSOCKETLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISERVERSOCKETLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport); \
  NS_SCRIPTABLE NS_IMETHOD OnStopListening(nsIServerSocket *aServ, nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISERVERSOCKETLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport) { return _to OnSocketAccepted(aServ, aTransport); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopListening(nsIServerSocket *aServ, nsresult aStatus) { return _to OnStopListening(aServ, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISERVERSOCKETLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSocketAccepted(aServ, aTransport); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopListening(nsIServerSocket *aServ, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopListening(aServ, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsServerSocketListener : public nsIServerSocketListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISERVERSOCKETLISTENER

  nsServerSocketListener();

private:
  ~nsServerSocketListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsServerSocketListener, nsIServerSocketListener)

nsServerSocketListener::nsServerSocketListener()
{
  /* member initializers and constructor code */
}

nsServerSocketListener::~nsServerSocketListener()
{
  /* destructor code */
}

/* void onSocketAccepted (in nsIServerSocket aServ, in nsISocketTransport aTransport); */
NS_IMETHODIMP nsServerSocketListener::OnSocketAccepted(nsIServerSocket *aServ, nsISocketTransport *aTransport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopListening (in nsIServerSocket aServ, in nsresult aStatus); */
NS_IMETHODIMP nsServerSocketListener::OnStopListening(nsIServerSocket *aServ, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIServerSocket_h__ */
