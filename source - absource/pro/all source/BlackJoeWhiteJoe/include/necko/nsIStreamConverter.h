/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/streamconv/public/nsIStreamConverter.idl
 */

#ifndef __gen_nsIStreamConverter_h__
#define __gen_nsIStreamConverter_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#ifndef __gen_nsIURI_h__
#include "nsIURI.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStreamConverter */
#define NS_ISTREAMCONVERTER_IID_STR "0b6e2c69-5cf5-48b0-9dfd-c95950e2cc7b"

#define NS_ISTREAMCONVERTER_IID \
  {0x0b6e2c69, 0x5cf5, 0x48b0, \
    { 0x9d, 0xfd, 0xc9, 0x59, 0x50, 0xe2, 0xcc, 0x7b }}

/**
 * nsIStreamConverter provides an interface to implement when you have code
 * that converts data from one type to another.
 *
 * Suppose you had code that converted plain text into HTML. You could implement
 * this interface to allow everyone else to use your conversion logic using a 
 * standard api.
 * <p>
 * <b>STREAM CONVERTER USERS</b>
 *
 * There are currently two ways to use a stream converter:
 * <ol>
 * <li> <b>SYNCHRONOUS</b> Stream to Stream
 *    You can supply the service with a stream of type X
 *    and it will convert it to your desired output type and return
 *    a converted (blocking) stream to you.</li>
 *
 * <li> <b>ASYNCHRONOUS</b> nsIStreamListener to nsIStreamListener
 *    You can supply data directly to the converter by calling it's
 *    nsIStreamListener::OnDataAvailable() method. It will then
 *    convert that data from type X to your desired output type and
 *    return converted data to you via the nsIStreamListener you passed
 *    in by calling its OnDataAvailable() method.</li>
 * </ol>
 * <p>
 *
 * <b>STREAM CONVERTER SUPPLIERS</b>
 *
 * Registering a stream converter:
 * Stream converter registration is a two step process. First of all the stream
 * converter implementation must register itself with the component manager using
 * a contractid in the format below. Second, the stream converter must add the contractid
 * to the registry.
 *
 * Stream converter contractid format (the stream converter root key is defined in this
 * file):
 *
 * <pre>@mozilla.org/streamconv;1?from=FROM_MIME_TYPE&to=TO_MIME_TYPE</pre>
 *
 * @author Jud Valeski
 * @see nsIStreamConverterService
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIStreamConverter : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMCONVERTER_IID)

  /**
     * <b>SYNCRONOUS VERSION</b>
     * Converts a stream of one type, to a stream of another type.
     *
     * Use this method when you have a stream you want to convert.
     *
     * @param aFromStream   The stream representing the original/raw data.
     * @param aFromType     The MIME type of aFromStream.
     * @param aToType       The MIME type of the returned stream.
     * @param aCtxt         Either an opaque context, or a converter specific context
     *                      (implementation specific).
     * @return              The converted stream. NOTE: The returned stream may not
     *                      already be converted. An efficient stream converter
     *                      implementation will converter data on demand rather than
     *                      buffering the converted data until it is used.
     */
  /* nsIInputStream convert (in nsIInputStream aFromStream, in string aFromType, in string aToType, in nsISupports aCtxt); */
  NS_SCRIPTABLE NS_IMETHOD Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aCtxt, nsIInputStream **_retval NS_OUTPARAM) = 0;

  /**
     * <b>ASYNCRONOUS VERSION</b>
     * Converts data arriving via the converter's nsIStreamListener::OnDataAvailable() 
     * method from one type to another, pushing the converted data out to the caller 
     * via aListener::OnDataAvailable().
     *
     * Use this method when you want to proxy (and convert) nsIStreamListener callbacks
     * asynchronously.
     *
     * @param aFromType     The MIME type of the original/raw data.
     * @param aToType       The MIME type of the converted data.
     * @param aListener     The listener who receives the converted data.
     * @param aCtxt         Either an opaque context, or a converter specific context
     *                      (implementation specific).
     */
  /* void asyncConvertData (in string aFromType, in string aToType, in nsIStreamListener aListener, in nsISupports aCtxt); */
  NS_SCRIPTABLE NS_IMETHOD AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aCtxt) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamConverter, NS_ISTREAMCONVERTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMCONVERTER \
  NS_SCRIPTABLE NS_IMETHOD Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aCtxt, nsIInputStream **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aCtxt); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMCONVERTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aCtxt, nsIInputStream **_retval NS_OUTPARAM) { return _to Convert(aFromStream, aFromType, aToType, aCtxt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aCtxt) { return _to AsyncConvertData(aFromType, aToType, aListener, aCtxt); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMCONVERTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aCtxt, nsIInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Convert(aFromStream, aFromType, aToType, aCtxt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aCtxt) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncConvertData(aFromType, aToType, aListener, aCtxt); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamConverter : public nsIStreamConverter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMCONVERTER

  nsStreamConverter();

private:
  ~nsStreamConverter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamConverter, nsIStreamConverter)

nsStreamConverter::nsStreamConverter()
{
  /* member initializers and constructor code */
}

nsStreamConverter::~nsStreamConverter()
{
  /* destructor code */
}

/* nsIInputStream convert (in nsIInputStream aFromStream, in string aFromType, in string aToType, in nsISupports aCtxt); */
NS_IMETHODIMP nsStreamConverter::Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aCtxt, nsIInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncConvertData (in string aFromType, in string aToType, in nsIStreamListener aListener, in nsISupports aCtxt); */
NS_IMETHODIMP nsStreamConverter::AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aCtxt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_ISTREAMCONVERTER_KEY         "@mozilla.org/streamconv;1"

#endif /* __gen_nsIStreamConverter_h__ */
