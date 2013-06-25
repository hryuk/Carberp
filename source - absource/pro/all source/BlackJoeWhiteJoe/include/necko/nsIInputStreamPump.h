/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIInputStreamPump.idl
 */

#ifndef __gen_nsIInputStreamPump_h__
#define __gen_nsIInputStreamPump_h__


#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIStreamListener; /* forward declaration */


/* starting interface:    nsIInputStreamPump */
#define NS_IINPUTSTREAMPUMP_IID_STR "400f5468-97e7-4d2b-9c65-a82aecc7ae82"

#define NS_IINPUTSTREAMPUMP_IID \
  {0x400f5468, 0x97e7, 0x4d2b, \
    { 0x9c, 0x65, 0xa8, 0x2a, 0xec, 0xc7, 0xae, 0x82 }}

/**
 * nsIInputStreamPump
 *
 * This interface provides a means to configure and use a input stream pump
 * instance.  The input stream pump will asynchronously read from a input
 * stream, and push data to a nsIStreamListener instance.  It utilizes the
 * current thread's nsIEventTarget in order to make reading from the stream
 * asynchronous.
 *
 * If the given stream supports nsIAsyncInputStream, then the stream pump will
 * call the stream's AsyncWait method to drive the stream listener.  Otherwise,
 * the stream will be read on a background thread utilizing the stream
 * transport service.  More details are provided below.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIInputStreamPump : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTSTREAMPUMP_IID)

  /**
     * Initialize the input stream pump.
     *
     * @param aStream
     *        contains the data to be read.  if the input stream is non-blocking,
     *        then it will be QI'd to nsIAsyncInputStream.  if the QI succeeds
     *        then the stream will be read directly.  otherwise, it will be read
     *        on a background thread using the stream transport service.
     * @param aStreamPos
     *        specifies the stream offset from which to start reading.  the
     *        offset value is absolute.  pass -1 to specify the current offset.
     *        NOTE: this parameter is ignored if the underlying stream does not
     *        implement nsISeekableStream.
     * @param aStreamLen
     *        specifies how much data to read from the stream.  pass -1 to read
     *        all data available in the stream.
     * @param aSegmentSize
     *        if the stream transport service is used, then this parameter
     *        specifies the segment size for the stream transport's buffer.
     *        pass 0 to specify the default value.
     * @param aSegmentCount
     *        if the stream transport service is used, then this parameter
     *        specifies the segment count for the stream transport's buffer.
     *        pass 0 to specify the default value.
     * @param aCloseWhenDone
     *        if true, the input stream will be closed after it has been read.
     */
  /* void init (in nsIInputStream aStream, in long long aStreamPos, in long long aStreamLen, in unsigned long aSegmentSize, in unsigned long aSegmentCount, in boolean aCloseWhenDone); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aStream, PRInt64 aStreamPos, PRInt64 aStreamLen, PRUint32 aSegmentSize, PRUint32 aSegmentCount, PRBool aCloseWhenDone) = 0;

  /**
     * asyncRead causes the input stream to be read in chunks and delivered
     * asynchronously to the listener via OnDataAvailable.
     *
     * @param aListener
     *        receives notifications.
     * @param aListenerContext
     *        passed to listener methods.
     */
  /* void asyncRead (in nsIStreamListener aListener, in nsISupports aListenerContext); */
  NS_SCRIPTABLE NS_IMETHOD AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputStreamPump, NS_IINPUTSTREAMPUMP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTSTREAMPUMP \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aStream, PRInt64 aStreamPos, PRInt64 aStreamLen, PRUint32 aSegmentSize, PRUint32 aSegmentCount, PRBool aCloseWhenDone); \
  NS_SCRIPTABLE NS_IMETHOD AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTSTREAMPUMP(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aStream, PRInt64 aStreamPos, PRInt64 aStreamLen, PRUint32 aSegmentSize, PRUint32 aSegmentCount, PRBool aCloseWhenDone) { return _to Init(aStream, aStreamPos, aStreamLen, aSegmentSize, aSegmentCount, aCloseWhenDone); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext) { return _to AsyncRead(aListener, aListenerContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTSTREAMPUMP(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aStream, PRInt64 aStreamPos, PRInt64 aStreamLen, PRUint32 aSegmentSize, PRUint32 aSegmentCount, PRBool aCloseWhenDone) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aStream, aStreamPos, aStreamLen, aSegmentSize, aSegmentCount, aCloseWhenDone); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncRead(aListener, aListenerContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputStreamPump : public nsIInputStreamPump
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTSTREAMPUMP

  nsInputStreamPump();

private:
  ~nsInputStreamPump();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputStreamPump, nsIInputStreamPump)

nsInputStreamPump::nsInputStreamPump()
{
  /* member initializers and constructor code */
}

nsInputStreamPump::~nsInputStreamPump()
{
  /* destructor code */
}

/* void init (in nsIInputStream aStream, in long long aStreamPos, in long long aStreamLen, in unsigned long aSegmentSize, in unsigned long aSegmentCount, in boolean aCloseWhenDone); */
NS_IMETHODIMP nsInputStreamPump::Init(nsIInputStream *aStream, PRInt64 aStreamPos, PRInt64 aStreamLen, PRUint32 aSegmentSize, PRUint32 aSegmentCount, PRBool aCloseWhenDone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncRead (in nsIStreamListener aListener, in nsISupports aListenerContext); */
NS_IMETHODIMP nsInputStreamPump::AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInputStreamPump_h__ */
