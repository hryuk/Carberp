/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIAsyncInputStream.idl
 */

#ifndef __gen_nsIAsyncInputStream_h__
#define __gen_nsIAsyncInputStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStreamCallback; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsIAsyncInputStream */
#define NS_IASYNCINPUTSTREAM_IID_STR "a5f255ab-4801-4161-8816-277ac92f6ad1"

#define NS_IASYNCINPUTSTREAM_IID \
  {0xa5f255ab, 0x4801, 0x4161, \
    { 0x88, 0x16, 0x27, 0x7a, 0xc9, 0x2f, 0x6a, 0xd1 }}

/**
 * If an input stream is non-blocking, it may return NS_BASE_STREAM_WOULD_BLOCK
 * when read.  The caller must then wait for the stream to have some data to 
 * read.  If the stream implements nsIAsyncInputStream, then the caller can use 
 * this interface to request an asynchronous notification when the stream
 * becomes readable or closed (via the AsyncWait method).
 *
 * While this interface is almost exclusively used with non-blocking streams, it
 * is not necessary that nsIInputStream::isNonBlocking return true.  Nor is it
 * necessary that a non-blocking nsIInputStream implementation also implement
 * nsIAsyncInputStream.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAsyncInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCINPUTSTREAM_IID)

  /**
     * This method closes the stream and sets its internal status.  If the 
     * stream is already closed, then this method is ignored.  Once the stream
     * is closed, the stream's status cannot be changed.  Any successful status
     * code passed to this method is treated as NS_BASE_STREAM_CLOSED, which
     * has an effect equivalent to nsIInputStream::close. 
     *
     * NOTE: this method exists in part to support pipes, which have both an 
     * input end and an output end.  If the input end of a pipe is closed, then
     * writes to the output end of the pipe will fail.  The error code returned 
     * when an attempt is made to write to a "broken" pipe corresponds to the
     * status code passed in when the input end of the pipe was closed, which
     * greatly simplifies working with pipes in some cases.
     *
     * @param aStatus
     *        The error that will be reported if this stream is accessed after
     *        it has been closed.
     */
  /* void closeWithStatus (in nsresult aStatus); */
  NS_SCRIPTABLE NS_IMETHOD CloseWithStatus(nsresult aStatus) = 0;

  /**
     * Asynchronously wait for the stream to be readable or closed.  The
     * notification is one-shot, meaning that each asyncWait call will result
     * in exactly one notification callback.  After the OnInputStreamReady event
     * is dispatched, the stream releases its reference to the 
     * nsIInputStreamCallback object.  It is safe to call asyncWait again from the
     * notification handler.
     *
     * This method may be called at any time (even if read has not been called).
     * In other words, this method may be called when the stream already has
     * data to read.  It may also be called when the stream is closed.  If the
     * stream is already readable or closed when AsyncWait is called, then the
     * OnInputStreamReady event will be dispatched immediately.  Otherwise, the
     * event will be dispatched when the stream becomes readable or closed.
     * 
     * @param aCallback
     *        This object is notified when the stream becomes ready.  This
     *        parameter may be null to clear an existing callback.
     * @param aFlags
     *        This parameter specifies optional flags passed in to configure
     *        the behavior of this method.  Pass zero to specify no flags.
     * @param aRequestedCount
     *        Wait until at least this many bytes can be read.  This is only
     *        a suggestion to the underlying stream; it may be ignored.  The
     *        caller may pass zero to indicate no preference.
     * @param aEventTarget
     *        Specify NULL to receive notification on ANY thread (possibly even
     *        recursively on the calling thread -- i.e., synchronously), or
     *        specify that the notification be delivered to a specific event
     *        target.
     */
  /* void asyncWait (in nsIInputStreamCallback aCallback, in unsigned long aFlags, in unsigned long aRequestedCount, in nsIEventTarget aEventTarget); */
  NS_SCRIPTABLE NS_IMETHOD AsyncWait(nsIInputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget) = 0;

  /**
     * If passed to asyncWait, this flag overrides the default behavior,
     * causing the OnInputStreamReady notification to be suppressed until the
     * stream becomes closed (either as a result of closeWithStatus/close being
     * called on the stream or possibly due to some error in the underlying
     * stream).
     */
  enum { WAIT_CLOSURE_ONLY = 1U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncInputStream, NS_IASYNCINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCINPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD CloseWithStatus(nsresult aStatus); \
  NS_SCRIPTABLE NS_IMETHOD AsyncWait(nsIInputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD CloseWithStatus(nsresult aStatus) { return _to CloseWithStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncWait(nsIInputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget) { return _to AsyncWait(aCallback, aFlags, aRequestedCount, aEventTarget); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD CloseWithStatus(nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseWithStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncWait(nsIInputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncWait(aCallback, aFlags, aRequestedCount, aEventTarget); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncInputStream : public nsIAsyncInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCINPUTSTREAM

  nsAsyncInputStream();

private:
  ~nsAsyncInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAsyncInputStream, nsIAsyncInputStream)

nsAsyncInputStream::nsAsyncInputStream()
{
  /* member initializers and constructor code */
}

nsAsyncInputStream::~nsAsyncInputStream()
{
  /* destructor code */
}

/* void closeWithStatus (in nsresult aStatus); */
NS_IMETHODIMP nsAsyncInputStream::CloseWithStatus(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncWait (in nsIInputStreamCallback aCallback, in unsigned long aFlags, in unsigned long aRequestedCount, in nsIEventTarget aEventTarget); */
NS_IMETHODIMP nsAsyncInputStream::AsyncWait(nsIInputStreamCallback *aCallback, PRUint32 aFlags, PRUint32 aRequestedCount, nsIEventTarget *aEventTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIInputStreamCallback */
#define NS_IINPUTSTREAMCALLBACK_IID_STR "d1f28e94-3a6e-4050-a5f5-2e81b1fc2a43"

#define NS_IINPUTSTREAMCALLBACK_IID \
  {0xd1f28e94, 0x3a6e, 0x4050, \
    { 0xa5, 0xf5, 0x2e, 0x81, 0xb1, 0xfc, 0x2a, 0x43 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIInputStreamCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTSTREAMCALLBACK_IID)

  /**
 * This is a companion interface for nsIAsyncInputStream::asyncWait.
 */
/**
     * Called to indicate that the stream is either readable or closed.
     *
     * @param aStream
     *        The stream whose asyncWait method was called.
     */
  /* void onInputStreamReady (in nsIAsyncInputStream aStream); */
  NS_SCRIPTABLE NS_IMETHOD OnInputStreamReady(nsIAsyncInputStream *aStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputStreamCallback, NS_IINPUTSTREAMCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTSTREAMCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD OnInputStreamReady(nsIAsyncInputStream *aStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTSTREAMCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnInputStreamReady(nsIAsyncInputStream *aStream) { return _to OnInputStreamReady(aStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTSTREAMCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnInputStreamReady(nsIAsyncInputStream *aStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnInputStreamReady(aStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputStreamCallback : public nsIInputStreamCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTSTREAMCALLBACK

  nsInputStreamCallback();

private:
  ~nsInputStreamCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputStreamCallback, nsIInputStreamCallback)

nsInputStreamCallback::nsInputStreamCallback()
{
  /* member initializers and constructor code */
}

nsInputStreamCallback::~nsInputStreamCallback()
{
  /* destructor code */
}

/* void onInputStreamReady (in nsIAsyncInputStream aStream); */
NS_IMETHODIMP nsInputStreamCallback::OnInputStreamReady(nsIAsyncInputStream *aStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAsyncInputStream_h__ */
