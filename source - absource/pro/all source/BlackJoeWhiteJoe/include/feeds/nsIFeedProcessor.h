/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/feeds/public/nsIFeedProcessor.idl
 */

#ifndef __gen_nsIFeedProcessor_h__
#define __gen_nsIFeedProcessor_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFeedResultListener; /* forward declaration */

class nsIInputStream; /* forward declaration */


/* starting interface:    nsIFeedProcessor */
#define NS_IFEEDPROCESSOR_IID_STR "8a0b2908-21b0-45d7-b14d-30df0f92afc7"

#define NS_IFEEDPROCESSOR_IID \
  {0x8a0b2908, 0x21b0, 0x45d7, \
    { 0xb1, 0x4d, 0x30, 0xdf, 0x0f, 0x92, 0xaf, 0xc7 }}

/**
 * An nsIFeedProcessor parses feeds, triggering callbacks based on
 * their contents.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFeedProcessor : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDPROCESSOR_IID)

  /**
   * The listener that will respond to feed events. 
   */
  /* attribute nsIFeedResultListener listener; */
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIFeedResultListener * *aListener) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIFeedResultListener * aListener) = 0;

  /**
   * Parse a feed from an nsIInputStream.
   *
   * @param stream The input stream.
   * @param uri The base URI.
   */
  /* void parseFromStream (in nsIInputStream stream, in nsIURI uri); */
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, nsIURI *uri) = 0;

  /**
   * Parse a feed from a string.
   *
   * @param str The string to parse.
   * @param uri The base URI.
   */
  /* void parseFromString (in AString str, in nsIURI uri); */
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const nsAString & str, nsIURI *uri) = 0;

  /**
   * Parse a feed asynchronously. The caller must then call the
   * nsIFeedProcessor's nsIStreamListener methods to drive the
   * parse. Do not call the other parse methods during an asynchronous
   * parse.
   *
   * @param requestObserver The observer to notify on start/stop. This
   *                        argument can be null.
   * @param uri The base URI.
   */
  /* void parseAsync (in nsIRequestObserver requestObserver, in nsIURI uri); */
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRequestObserver *requestObserver, nsIURI *uri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedProcessor, NS_IFEEDPROCESSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDPROCESSOR \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIFeedResultListener * *aListener); \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIFeedResultListener * aListener); \
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, nsIURI *uri); \
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const nsAString & str, nsIURI *uri); \
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRequestObserver *requestObserver, nsIURI *uri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDPROCESSOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIFeedResultListener * *aListener) { return _to GetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIFeedResultListener * aListener) { return _to SetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, nsIURI *uri) { return _to ParseFromStream(stream, uri); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const nsAString & str, nsIURI *uri) { return _to ParseFromString(str, uri); } \
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRequestObserver *requestObserver, nsIURI *uri) { return _to ParseAsync(requestObserver, uri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDPROCESSOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIFeedResultListener * *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIFeedResultListener * aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromStream(stream, uri); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const nsAString & str, nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromString(str, uri); } \
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRequestObserver *requestObserver, nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseAsync(requestObserver, uri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedProcessor : public nsIFeedProcessor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDPROCESSOR

  nsFeedProcessor();

private:
  ~nsFeedProcessor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedProcessor, nsIFeedProcessor)

nsFeedProcessor::nsFeedProcessor()
{
  /* member initializers and constructor code */
}

nsFeedProcessor::~nsFeedProcessor()
{
  /* destructor code */
}

/* attribute nsIFeedResultListener listener; */
NS_IMETHODIMP nsFeedProcessor::GetListener(nsIFeedResultListener * *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedProcessor::SetListener(nsIFeedResultListener * aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseFromStream (in nsIInputStream stream, in nsIURI uri); */
NS_IMETHODIMP nsFeedProcessor::ParseFromStream(nsIInputStream *stream, nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseFromString (in AString str, in nsIURI uri); */
NS_IMETHODIMP nsFeedProcessor::ParseFromString(const nsAString & str, nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseAsync (in nsIRequestObserver requestObserver, in nsIURI uri); */
NS_IMETHODIMP nsFeedProcessor::ParseAsync(nsIRequestObserver *requestObserver, nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedProcessor_h__ */
