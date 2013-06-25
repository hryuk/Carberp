/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIAsyncOutputStream.idl
 */

#ifndef __gen_nsIAsyncOutputStream_h__
#define __gen_nsIAsyncOutputStream_h__


#ifndef __gen_nsIOutputStream_h__
#include "nsIOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStreamCallback; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsIAsyncOutputStream */
#define NS_IASYNCOUTPUTSTREAM_IID_STR "beb632d3-d77a-4e90-9134-f9ece69e8200"

#define NS_IASYNCOUTPUTSTREAM_IID \
  {0xbeb632d3, 0xd77a, 0x4e90, \
    { 0x91, 0x34, 0xf9, 0xec, 0xe6, 0x9e, 0x82, 0x00 }}

/**
 * If an output stream is non-blocking, it may return NS_BASE_STREAM_WOULD_BLOCK
 * when written to.  The caller must then wait for the stream to become
 * writable.  If the stream implements nsIAsyncOutputStream, then the caller can
 * use this interface to request an asynchronous notification when the stream
 * becomes writable or closed (via the AsyncWait method).
 *
 * While this interface is almost exclusively used with non-blocking streams, it
 * is not necessary that nsIOutputStream::isNonBlocking return true.  Nor is it
 * necessary that a non-blocking nsIOutputStream implementation also implement
 * nsIAsyncOutputStream.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAsyncOutputStream : public nsIOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCOUTPUTSTREAM_IID)

  /**
     * This method closes the stream and sets its internal status.  If the 
     * stream is already closed, then this method is ignored.  Once the stream
     * is closed, the stream's status cannot be changed.  Any successful status
     * code passed to this method is treated as NS_BASE_STREAM_CLOSED, which
     * is equivalent to nsIInputStream::close. 
     *
     * NOTE: this method exists in part to support pipes, which have both an 
     * input end and an output end.  If the output end of a pipe is closed, then
     * reads from the input end of the pipe will fail.  The error code returned 
     * when an attempt is made to read from a "closed" pipe corresponds to the
     * status code passed in when the output end of the pipe is closed, which
     * greatly simplifies working with pipes in some cases.
     *
     * @param aStatus
     *        The error that will be reported if this stream is accessed after
     *        it has been closed.
     */
  /* void closeWithStatus (in nsresult reason); */
  NS_SCRIPTABLE NS_IMETHOD CloseWithStatus(nsresult reason) = 0;

  /**
     * Asynchronously wait for the stream to be writable or closed.  The
     * notification is one-shot, meaning that each asyncWait call will result
     * in exactly one notification callback.  After the OnOutputStreamReady event
     * is dispatched, the stream releases its reference to the 
     * nsIOutputStreamCallback object.  It is safe to call asyncWait again from the
     * notification handler.
     *
     * This method may be called at any time (even if write has not been called).
     * In other words, this method may be called when the stream already has
     * room for more data.  It may also be called when the stream is closed.  If
     * the stream is already writable or closed when AsyncWait is called, then the
     * OnOutputStreamReady event will be dispatched immediately.  Otherwise, the
     * event will be dispatched when the stream becomes writable or closed.
     * 
     * @param aCallback
     *        This object is notified when the stream becomes ready.  This
     *        parameter may be null to clear an existing callback.
     * @param aFlags
     *        This parameter specifies optional flags passed in to configure
     *        the behavior of this method.  Pass zero to specify no flags.
     * @param aRequestedCount
     *        Wait until at least this many bytes can be written.  This is only
     *        a suggestion to the underlying stream; it may be ignored.  The
     *        caller may pass zero to indicate no preference.
     * @param aEventTarget
     *        Specify NULL to receive notification on ANY thread (possibly even
     *        recursively on the calling thread -- i.e., synchronously), or
     *        specify that the notification be delivered to a specific event
     *        target.
     */
  /* void asyncWait (in nsIOutputStreamCallback aCallback, in unsigned long aFlags, in unsigned long aRequestedCount, in nsIEventTarget aEventTarget); */
  NS_SCRIPTABLE NS_IMETHOD AsyncWait(nsIOutputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget) = 0;

  /**
     * If passed to asyncWait, this flag overrides the default behavior,
     * causing the OnOutputStreamReady notification to be suppressed until the
     * stream becomes closed (either as a result of closeWithStatus/close being
     * called on the stream or possibly due to some error in the underlying
     * stream).
     */
  enum { WAIT_CLOSURE_ONLY = 1U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncOutputStream, NS_IASYNCOUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCOUTPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD CloseWithStatus(nsresult reason); \
  NS_SCRIPTABLE NS_IMETHOD AsyncWait(nsIOutputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCOUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD CloseWithStatus(nsresult reason) { return _to CloseWithStatus(reason); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncWait(nsIOutputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget) { return _to AsyncWait(aCallback, aFlags, aRequestedCount, aEventTarget); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCOUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD CloseWithStatus(nsresult reason) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseWithStatus(reason); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncWait(nsIOutputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncWait(aCallback, aFlags, aRequestedCount, aEventTarget); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncOutputStream : public nsIAsyncOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCOUTPUTSTREAM

  nsAsyncOutputStream();

private:
  ~nsAsyncOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAsyncOutputStream, nsIAsyncOutputStream)

nsAsyncOutputStream::nsAsyncOutputStream()
{
  /* member initializers and constructor code */
}

nsAsyncOutputStream::~nsAsyncOutputStream()
{
  /* destructor code */
}

/* void closeWithStatus (in nsresult reason); */
NS_IMETHODIMP nsAsyncOutputStream::CloseWithStatus(nsresult reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncWait (in nsIOutputStreamCallback aCallback, in unsigned long aFlags, in unsigned long aRequestedCount, in nsIEventTarget aEventTarget); */
NS_IMETHODIMP nsAsyncOutputStream::AsyncWait(nsIOutputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIOutputStreamCallback */
#define NS_IOUTPUTSTREAMCALLBACK_IID_STR "40dbcdff-9053-42c5-a57c-3ec910d0f148"

#define NS_IOUTPUTSTREAMCALLBACK_IID \
  {0x40dbcdff, 0x9053, 0x42c5, \
    { 0xa5, 0x7c, 0x3e, 0xc9, 0x10, 0xd0, 0xf1, 0x48 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIOutputStreamCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOUTPUTSTREAMCALLBACK_IID)

  /**
 * This is a companion interface for nsIAsyncOutputStream::asyncWait.
 */
/**
     * Called to indicate that the stream is either writable or closed.
     *
     * @param aStream
     *        The stream whose asyncWait method was called.
     */
  /* void onOutputStreamReady (in nsIAsyncOutputStream aStream); */
  NS_SCRIPTABLE NS_IMETHOD OnOutputStreamReady(nsIAsyncOutputStream *aStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOutputStreamCallback, NS_IOUTPUTSTREAMCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOUTPUTSTREAMCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD OnOutputStreamReady(nsIAsyncOutputStream *aStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOUTPUTSTREAMCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnOutputStreamReady(nsIAsyncOutputStream *aStream) { return _to OnOutputStreamReady(aStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOUTPUTSTREAMCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnOutputStreamReady(nsIAsyncOutputStream *aStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnOutputStreamReady(aStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOutputStreamCallback : public nsIOutputStreamCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOUTPUTSTREAMCALLBACK

  nsOutputStreamCallback();

private:
  ~nsOutputStreamCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOutputStreamCallback, nsIOutputStreamCallback)

nsOutputStreamCallback::nsOutputStreamCallback()
{
  /* member initializers and constructor code */
}

nsOutputStreamCallback::~nsOutputStreamCallback()
{
  /* destructor code */
}

/* void onOutputStreamReady (in nsIAsyncOutputStream aStream); */
NS_IMETHODIMP nsOutputStreamCallback::OnOutputStreamReady(nsIAsyncOutputStream *aStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAsyncOutputStream_h__ */
