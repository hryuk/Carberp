/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIChannelEventSink.idl
 */

#ifndef __gen_nsIChannelEventSink_h__
#define __gen_nsIChannelEventSink_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */


/* starting interface:    nsIChannelEventSink */
#define NS_ICHANNELEVENTSINK_IID_STR "6757d790-2916-498e-aaca-6b668a956875"

#define NS_ICHANNELEVENTSINK_IID \
  {0x6757d790, 0x2916, 0x498e, \
    { 0xaa, 0xca, 0x6b, 0x66, 0x8a, 0x95, 0x68, 0x75 }}

/**
 * Implement this interface to receive control over various channel events.
 * Channels will try to get this interface from a channel's
 * notificationCallbacks or, if not available there, from the loadGroup's
 * notificationCallbacks.
 *
 * These methods are called before onStartRequest, and should be handled
 * SYNCHRONOUSLY.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIChannelEventSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHANNELEVENTSINK_IID)

  /**
     * This is a temporary redirect. New requests for this resource should
     * continue to use the URI of the old channel.
     *
     * The new URI may be identical to the old one.
     */
  enum { REDIRECT_TEMPORARY = 1U };

  /**
     * This is a permanent redirect. New requests for this resource should use
     * the URI of the new channel (This might be an HTTP 301 reponse).
     * If this flag is not set, this is a temporary redirect.
     *
     * The new URI may be identical to the old one.
     */
  enum { REDIRECT_PERMANENT = 2U };

  /**
     * This is an internal redirect, i.e. it was not initiated by the remote
     * server, but is specific to the channel implementation.
     *
     * The new URI may be identical to the old one.
     */
  enum { REDIRECT_INTERNAL = 4U };

  /**
     * Called when a redirect occurs. This may happen due to an HTTP 3xx status
     * code.
     *
     * @param oldChannel
     *        The channel that's being redirected.
     * @param newChannel
     *        The new channel. This channel is not opened yet.
     * @param flags
     *        Flags indicating the type of redirect. A bitmask consisting
     *        of flags from above.
     *        One of REDIRECT_TEMPORARY and REDIRECT_PERMANENT will always be
     *        set.
     *
     * @throw <any> Throwing an exception will cancel the load. No network
     * request for the new channel will be made.
     */
  /* void onChannelRedirect (in nsIChannel oldChannel, in nsIChannel newChannel, in unsigned long flags); */
  NS_SCRIPTABLE NS_IMETHOD OnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, PRUint32 flags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIChannelEventSink, NS_ICHANNELEVENTSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHANNELEVENTSINK \
  NS_SCRIPTABLE NS_IMETHOD OnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, PRUint32 flags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHANNELEVENTSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, PRUint32 flags) { return _to OnChannelRedirect(oldChannel, newChannel, flags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHANNELEVENTSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, PRUint32 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnChannelRedirect(oldChannel, newChannel, flags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsChannelEventSink : public nsIChannelEventSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHANNELEVENTSINK

  nsChannelEventSink();

private:
  ~nsChannelEventSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsChannelEventSink, nsIChannelEventSink)

nsChannelEventSink::nsChannelEventSink()
{
  /* member initializers and constructor code */
}

nsChannelEventSink::~nsChannelEventSink()
{
  /* destructor code */
}

/* void onChannelRedirect (in nsIChannel oldChannel, in nsIChannel newChannel, in unsigned long flags); */
NS_IMETHODIMP nsChannelEventSink::OnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, PRUint32 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIChannelEventSink_h__ */
