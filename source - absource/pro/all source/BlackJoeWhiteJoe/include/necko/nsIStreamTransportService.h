/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIStreamTransportService.idl
 */

#ifndef __gen_nsIStreamTransportService_h__
#define __gen_nsIStreamTransportService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITransport; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIStreamTransportService */
#define NS_ISTREAMTRANSPORTSERVICE_IID_STR "8268d474-efbf-494f-a152-e8a8616f4e52"

#define NS_ISTREAMTRANSPORTSERVICE_IID \
  {0x8268d474, 0xefbf, 0x494f, \
    { 0xa1, 0x52, 0xe8, 0xa8, 0x61, 0x6f, 0x4e, 0x52 }}

/**
 * This service read/writes a stream on a background thread.
 *
 * Use this service to transform any blocking stream (e.g., file stream)
 * into a fully asynchronous stream that can be read/written without 
 * blocking the main thread.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIStreamTransportService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMTRANSPORTSERVICE_IID)

  /**
     * CreateInputTransport
     *
     * @param aStream
     *        The input stream that will be read on a background thread.
     *        This stream must implement "blocking" stream semantics.
     * @param aStartOffset
     *        The input stream will be read starting from this offset.  Pass
     *        -1 to read from the current stream offset.  NOTE: this parameter
     *        is ignored if the stream does not support nsISeekableStream.
     * @param aReadLimit
     *        This parameter limits the number of bytes that will be read from
     *        the input stream.  Pass -1 to read everything.
     * @param aCloseWhenDone
     *        Specify this flag to have the input stream closed once its
     *        contents have been completely read.
     *
     * @return nsITransport instance.
     */
  /* nsITransport createInputTransport (in nsIInputStream aStream, in long long aStartOffset, in long long aReadLimit, in boolean aCloseWhenDone); */
  NS_SCRIPTABLE NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, PRInt64 aStartOffset, PRInt64 aReadLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM) = 0;

  /**
     * CreateOutputTransport
     *
     * @param aStream
     *        The output stream that will be written to on a background thread.
     *        This stream must implement "blocking" stream semantics.
     * @param aStartOffset
     *        The output stream will be written starting at this offset.  Pass
     *        -1 to write to the current stream offset.  NOTE: this parameter
     *        is ignored if the stream does not support nsISeekableStream.
     * @param aWriteLimit
     *        This parameter limits the number of bytes that will be written to
     *        the output stream.  Pass -1 for unlimited writing.
     * @param aCloseWhenDone
     *        Specify this flag to have the output stream closed once its
     *        contents have been completely written.
     *
     * @return nsITransport instance.
     */
  /* nsITransport createOutputTransport (in nsIOutputStream aStream, in long long aStartOffset, in long long aWriteLimit, in boolean aCloseWhenDone); */
  NS_SCRIPTABLE NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, PRInt64 aStartOffset, PRInt64 aWriteLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamTransportService, NS_ISTREAMTRANSPORTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMTRANSPORTSERVICE \
  NS_SCRIPTABLE NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, PRInt64 aStartOffset, PRInt64 aReadLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, PRInt64 aStartOffset, PRInt64 aWriteLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMTRANSPORTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, PRInt64 aStartOffset, PRInt64 aReadLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM) { return _to CreateInputTransport(aStream, aStartOffset, aReadLimit, aCloseWhenDone, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, PRInt64 aStartOffset, PRInt64 aWriteLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM) { return _to CreateOutputTransport(aStream, aStartOffset, aWriteLimit, aCloseWhenDone, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMTRANSPORTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, PRInt64 aStartOffset, PRInt64 aReadLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInputTransport(aStream, aStartOffset, aReadLimit, aCloseWhenDone, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, PRInt64 aStartOffset, PRInt64 aWriteLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateOutputTransport(aStream, aStartOffset, aWriteLimit, aCloseWhenDone, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamTransportService : public nsIStreamTransportService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMTRANSPORTSERVICE

  nsStreamTransportService();

private:
  ~nsStreamTransportService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamTransportService, nsIStreamTransportService)

nsStreamTransportService::nsStreamTransportService()
{
  /* member initializers and constructor code */
}

nsStreamTransportService::~nsStreamTransportService()
{
  /* destructor code */
}

/* nsITransport createInputTransport (in nsIInputStream aStream, in long long aStartOffset, in long long aReadLimit, in boolean aCloseWhenDone); */
NS_IMETHODIMP nsStreamTransportService::CreateInputTransport(nsIInputStream *aStream, PRInt64 aStartOffset, PRInt64 aReadLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransport createOutputTransport (in nsIOutputStream aStream, in long long aStartOffset, in long long aWriteLimit, in boolean aCloseWhenDone); */
NS_IMETHODIMP nsStreamTransportService::CreateOutputTransport(nsIOutputStream *aStream, PRInt64 aStartOffset, PRInt64 aWriteLimit, PRBool aCloseWhenDone, nsITransport **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamTransportService_h__ */
