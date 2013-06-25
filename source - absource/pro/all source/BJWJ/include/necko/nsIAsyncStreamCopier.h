/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIAsyncStreamCopier.idl
 */

#ifndef __gen_nsIAsyncStreamCopier_h__
#define __gen_nsIAsyncStreamCopier_h__


#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsIRequestObserver; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsIAsyncStreamCopier */
#define NS_IASYNCSTREAMCOPIER_IID_STR "72e515de-a91e-4154-bb78-e5244cbaae74"

#define NS_IASYNCSTREAMCOPIER_IID \
  {0x72e515de, 0xa91e, 0x4154, \
    { 0xbb, 0x78, 0xe5, 0x24, 0x4c, 0xba, 0xae, 0x74 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAsyncStreamCopier : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCSTREAMCOPIER_IID)

  /**
     * Initialize the stream copier.
     *
     * @param aSource
     *        contains the data to be copied.
     * @param aSink
     *        specifies the destination for the data.
     * @param aTarget
     *        specifies the thread on which the copy will occur.  a null value
     *        is permitted and will cause the copy to occur on an unspecified
     *        background thread.
     * @param aSourceBuffered
     *        true if aSource implements ReadSegments.
     * @param aSinkBuffered
     *        true if aSink implements WriteSegments.
     * @param aChunkSize
     *        specifies how many bytes to read/write at a time.  this controls
     *        the granularity of the copying.  it should match the segment size
     *        of the "buffered" streams involved.
     *
     * NOTE: at least one of the streams must be buffered.
     */
  /* void init (in nsIInputStream aSource, in nsIOutputStream aSink, in nsIEventTarget aTarget, in boolean aSourceBuffered, in boolean aSinkBuffered, in unsigned long aChunkSize); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, PRBool aSourceBuffered, PRBool aSinkBuffered, PRUint32 aChunkSize) = 0;

  /**
     * asyncCopy triggers the start of the copy.  The observer will be notified
     * when the copy completes.
     *
     * @param aObserver
     *        receives notifications.
     * @param aObserverContext
     *        passed to observer methods.
     */
  /* void asyncCopy (in nsIRequestObserver aObserver, in nsISupports aObserverContext); */
  NS_SCRIPTABLE NS_IMETHOD AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncStreamCopier, NS_IASYNCSTREAMCOPIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCSTREAMCOPIER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, PRBool aSourceBuffered, PRBool aSinkBuffered, PRUint32 aChunkSize); \
  NS_SCRIPTABLE NS_IMETHOD AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCSTREAMCOPIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, PRBool aSourceBuffered, PRBool aSinkBuffered, PRUint32 aChunkSize) { return _to Init(aSource, aSink, aTarget, aSourceBuffered, aSinkBuffered, aChunkSize); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext) { return _to AsyncCopy(aObserver, aObserverContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCSTREAMCOPIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, PRBool aSourceBuffered, PRBool aSinkBuffered, PRUint32 aChunkSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aSource, aSink, aTarget, aSourceBuffered, aSinkBuffered, aChunkSize); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncCopy(aObserver, aObserverContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncStreamCopier : public nsIAsyncStreamCopier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCSTREAMCOPIER

  nsAsyncStreamCopier();

private:
  ~nsAsyncStreamCopier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAsyncStreamCopier, nsIAsyncStreamCopier)

nsAsyncStreamCopier::nsAsyncStreamCopier()
{
  /* member initializers and constructor code */
}

nsAsyncStreamCopier::~nsAsyncStreamCopier()
{
  /* destructor code */
}

/* void init (in nsIInputStream aSource, in nsIOutputStream aSink, in nsIEventTarget aTarget, in boolean aSourceBuffered, in boolean aSinkBuffered, in unsigned long aChunkSize); */
NS_IMETHODIMP nsAsyncStreamCopier::Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, PRBool aSourceBuffered, PRBool aSinkBuffered, PRUint32 aChunkSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncCopy (in nsIRequestObserver aObserver, in nsISupports aObserverContext); */
NS_IMETHODIMP nsAsyncStreamCopier::AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAsyncStreamCopier_h__ */
