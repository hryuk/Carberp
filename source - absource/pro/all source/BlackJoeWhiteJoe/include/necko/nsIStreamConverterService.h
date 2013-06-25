/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/streamconv/public/nsIStreamConverterService.idl
 */

#ifndef __gen_nsIStreamConverterService_h__
#define __gen_nsIStreamConverterService_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_ISTREAMCONVERTER_KEY         "@mozilla.org/streamconv;1"

/* starting interface:    nsIStreamConverterService */
#define NS_ISTREAMCONVERTERSERVICE_IID_STR "f2b1ab53-f0bd-4adb-9365-e59b1701a258"

#define NS_ISTREAMCONVERTERSERVICE_IID \
  {0xf2b1ab53, 0xf0bd, 0x4adb, \
    { 0x93, 0x65, 0xe5, 0x9b, 0x17, 0x01, 0xa2, 0x58 }}

/**
 * The nsIStreamConverterService is a higher level stream converter factory
 * responsible for locating and creating stream converters
 * (nsIStreamConverter).
 *
 * This service retrieves an interface that can convert data from a particular
 * MIME type, to a particular MIME type. It is responsible for any intermediary
 * conversion required in order to get from X to Z, assuming direct conversion
 * is not possible.
 *
 * @author Jud Valeski
 * @see nsIStreamConverter
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIStreamConverterService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMCONVERTERSERVICE_IID)

  /**
     * Tests whether conversion between the two specified types is possible.
     * This is cheaper than calling convert()/asyncConvertData(); it is not
     * necessary to call this function before calling one of those, though.
     */
  /* boolean canConvert (in string aFromType, in string aToType); */
  NS_SCRIPTABLE NS_IMETHOD CanConvert(const char *aFromType, const char *aToType, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * <b>SYNCHRONOUS VERSION</b>
     * Converts a stream of one type, to a stream of another type.
     *
     * Use this method when you have a stream you want to convert.
     *
     * @param aFromStream   The stream representing the original/raw data.
     * @param aFromType     The MIME type of aFromStream.
     * @param aToType       The MIME type of the returned stream.
     * @param aContext      Either an opaque context, or a converter specific
     *                      context (implementation specific).
     * @return              The converted stream. NOTE: The returned stream
     *                      may not already be converted. An efficient stream
     *                      converter implementation will convert data on
     *                      demand rather than buffering the converted data
     *                      until it is used.
     */
  /* nsIInputStream convert (in nsIInputStream aFromStream, in string aFromType, in string aToType, in nsISupports aContext); */
  NS_SCRIPTABLE NS_IMETHOD Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aContext, nsIInputStream **_retval NS_OUTPARAM) = 0;

  /**
     * <b>ASYNCHRONOUS VERSION</b>
     * Retrieves a nsIStreamListener that receives the original/raw data via its
     * nsIStreamListener::OnDataAvailable() callback, then converts and pushes 
     * the data to aListener.
     *
     * Use this method when you want to proxy (and convert) nsIStreamListener
     * callbacks asynchronously.
     *
     * @param aFromType     The MIME type of the original/raw data.
     * @param aToType       The MIME type of the converted data.
     * @param aListener     The listener that receives the converted data.
     * @param aCtxt         Either an opaque context, or a converter specific
     *                      context (implementation specific).
     * @return              A nsIStreamListener that receives data via its
     *                      OnDataAvailable() method.
     */
  /* nsIStreamListener asyncConvertData (in string aFromType, in string aToType, in nsIStreamListener aListener, in nsISupports aContext); */
  NS_SCRIPTABLE NS_IMETHOD AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamConverterService, NS_ISTREAMCONVERTERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMCONVERTERSERVICE \
  NS_SCRIPTABLE NS_IMETHOD CanConvert(const char *aFromType, const char *aToType, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aContext, nsIInputStream **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMCONVERTERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CanConvert(const char *aFromType, const char *aToType, PRBool *_retval NS_OUTPARAM) { return _to CanConvert(aFromType, aToType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aContext, nsIInputStream **_retval NS_OUTPARAM) { return _to Convert(aFromStream, aFromType, aToType, aContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener **_retval NS_OUTPARAM) { return _to AsyncConvertData(aFromType, aToType, aListener, aContext, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMCONVERTERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CanConvert(const char *aFromType, const char *aToType, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanConvert(aFromType, aToType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aContext, nsIInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Convert(aFromStream, aFromType, aToType, aContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncConvertData(aFromType, aToType, aListener, aContext, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamConverterService : public nsIStreamConverterService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMCONVERTERSERVICE

  nsStreamConverterService();

private:
  ~nsStreamConverterService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamConverterService, nsIStreamConverterService)

nsStreamConverterService::nsStreamConverterService()
{
  /* member initializers and constructor code */
}

nsStreamConverterService::~nsStreamConverterService()
{
  /* destructor code */
}

/* boolean canConvert (in string aFromType, in string aToType); */
NS_IMETHODIMP nsStreamConverterService::CanConvert(const char *aFromType, const char *aToType, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream convert (in nsIInputStream aFromStream, in string aFromType, in string aToType, in nsISupports aContext); */
NS_IMETHODIMP nsStreamConverterService::Convert(nsIInputStream *aFromStream, const char *aFromType, const char *aToType, nsISupports *aContext, nsIInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStreamListener asyncConvertData (in string aFromType, in string aToType, in nsIStreamListener aListener, in nsISupports aContext); */
NS_IMETHODIMP nsStreamConverterService::AsyncConvertData(const char *aFromType, const char *aToType, nsIStreamListener *aListener, nsISupports *aContext, nsIStreamListener **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamConverterService_h__ */
