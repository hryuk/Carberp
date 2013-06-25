/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIProgressEventSink.idl
 */

#ifndef __gen_nsIProgressEventSink_h__
#define __gen_nsIProgressEventSink_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIRequest; /* forward declaration */


/* starting interface:    nsIProgressEventSink */
#define NS_IPROGRESSEVENTSINK_IID_STR "d974c99e-4148-4df9-8d98-de834a2f6462"

#define NS_IPROGRESSEVENTSINK_IID \
  {0xd974c99e, 0x4148, 0x4df9, \
    { 0x8d, 0x98, 0xde, 0x83, 0x4a, 0x2f, 0x64, 0x62 }}

/**
 * nsIProgressEventSink
 *
 * This interface is used to asynchronously convey channel status and progress
 * information that is generally not critical to the processing of the channel.
 * The information is intended to be displayed to the user in some meaningful
 * way.
 *
 * An implementation of this interface can be passed to a channel via the
 * channel's notificationCallbacks attribute.  See nsIChannel for more info.
 *
 * The channel will begin passing notifications to the progress event sink
 * after its asyncOpen method has been called.  Notifications will cease once
 * the channel calls its listener's onStopRequest method or once the channel
 * is canceled (via nsIRequest::cancel).
 *
 * NOTE: This interface is actually not specific to channels and may be used
 * with other implementations of nsIRequest.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIProgressEventSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROGRESSEVENTSINK_IID)

  /**
     * Called to notify the event sink that progress has occurred for the
     * given request.
     *
     * @param aRequest
     *        the request being observed (may QI to nsIChannel).
     * @param aContext
     *        if aRequest is a channel, then this parameter is the listener
     *        context passed to nsIChannel::asyncOpen.
     * @param aProgress
     *        numeric value in the range 0 to aProgressMax indicating the
     *        number of bytes transfered thus far.
     * @param aProgressMax
     *        numeric value indicating maximum number of bytes that will be
     *        transfered (or 0xFFFFFFFFFFFFFFFF if total is unknown).
     */
  /* void onProgress (in nsIRequest aRequest, in nsISupports aContext, in unsigned long long aProgress, in unsigned long long aProgressMax); */
  NS_SCRIPTABLE NS_IMETHOD OnProgress(nsIRequest *aRequest, nsISupports *aContext, PRUint64 aProgress, PRUint64 aProgressMax) = 0;

  /**
     * Called to notify the event sink with a status message for the given
     * request.
     *
     * @param aRequest
     *        the request being observed (may QI to nsIChannel).
     * @param aContext
     *        if aRequest is a channel, then this parameter is the listener
     *        context passed to nsIChannel::asyncOpen.
     * @param aStatus
     *        status code (not necessarily an error code) indicating the
     *        state of the channel (usually the state of the underlying
     *        transport).  see nsISocketTransport for socket specific status
     *        codes.
     * @param aStatusArg
     *        status code argument to be used with the string bundle service
     *        to convert the status message into localized, human readable
     *        text.  the meaning of this parameter is specific to the value
     *        of the status code.  for socket status codes, this parameter
     *        indicates the host:port associated with the status code.
     */
  /* void onStatus (in nsIRequest aRequest, in nsISupports aContext, in nsresult aStatus, in wstring aStatusArg); */
  NS_SCRIPTABLE NS_IMETHOD OnStatus(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus, const PRUnichar *aStatusArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProgressEventSink, NS_IPROGRESSEVENTSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROGRESSEVENTSINK \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(nsIRequest *aRequest, nsISupports *aContext, PRUint64 aProgress, PRUint64 aProgressMax); \
  NS_SCRIPTABLE NS_IMETHOD OnStatus(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus, const PRUnichar *aStatusArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROGRESSEVENTSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(nsIRequest *aRequest, nsISupports *aContext, PRUint64 aProgress, PRUint64 aProgressMax) { return _to OnProgress(aRequest, aContext, aProgress, aProgressMax); } \
  NS_SCRIPTABLE NS_IMETHOD OnStatus(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus, const PRUnichar *aStatusArg) { return _to OnStatus(aRequest, aContext, aStatus, aStatusArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROGRESSEVENTSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(nsIRequest *aRequest, nsISupports *aContext, PRUint64 aProgress, PRUint64 aProgressMax) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProgress(aRequest, aContext, aProgress, aProgressMax); } \
  NS_SCRIPTABLE NS_IMETHOD OnStatus(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus, const PRUnichar *aStatusArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStatus(aRequest, aContext, aStatus, aStatusArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProgressEventSink : public nsIProgressEventSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROGRESSEVENTSINK

  nsProgressEventSink();

private:
  ~nsProgressEventSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProgressEventSink, nsIProgressEventSink)

nsProgressEventSink::nsProgressEventSink()
{
  /* member initializers and constructor code */
}

nsProgressEventSink::~nsProgressEventSink()
{
  /* destructor code */
}

/* void onProgress (in nsIRequest aRequest, in nsISupports aContext, in unsigned long long aProgress, in unsigned long long aProgressMax); */
NS_IMETHODIMP nsProgressEventSink::OnProgress(nsIRequest *aRequest, nsISupports *aContext, PRUint64 aProgress, PRUint64 aProgressMax)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStatus (in nsIRequest aRequest, in nsISupports aContext, in nsresult aStatus, in wstring aStatusArg); */
NS_IMETHODIMP nsProgressEventSink::OnStatus(nsIRequest *aRequest, nsISupports *aContext, nsresult aStatus, const PRUnichar *aStatusArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProgressEventSink_h__ */
