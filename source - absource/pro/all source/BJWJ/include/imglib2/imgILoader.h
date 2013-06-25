/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpr0n/public/imgILoader.idl
 */

#ifndef __gen_imgILoader_h__
#define __gen_imgILoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIDecoderObserver; /* forward declaration */

class imgIRequest; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsILoadGroup; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIURI; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    imgILoader */
#define IMGILOADER_IID_STR "d2f50c69-1064-4ce3-a92d-01dc5f5b4842"

#define IMGILOADER_IID \
  {0xd2f50c69, 0x1064, 0x4ce3, \
    { 0xa9, 0x2d, 0x01, 0xdc, 0x5f, 0x5b, 0x48, 0x42 }}

/**
 * imgILoader interface
 *
 * @author Stuart Parmenter <pavlov@netscape.com>
 * @version 0.3
 * @see imagelib2
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgILoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGILOADER_IID)

  /**
   * Start the load and decode of an image.
   * @param aURI the URI to load
   * @param aInitialDocumentURI the URI that 'initiated' the load -- used for 3rd party cookie blocking
   * @param aReferrerURI the 'referring' URI
   * @param aLoadGroup Loadgroup to put the image load into
   * @param aObserver the observer
   * @param aCX some random data
   * @param aLoadFlags Load flags for the request
   * @param aCacheKey cache key to use for a load if the original
   *                  image came from a request that had post data
   * @param aRequest A newly created, unused imgIRequest object or NULL for one to
                     be created for you.


   * libpr0n does NOT keep a strong ref to the observer; this prevents
   * reference cycles.  This means that callers of loadImage should
   * make sure to Cancel() the resulting request before the observer
   * goes away.
   */
  /* [noscript] imgIRequest loadImage (in nsIURI aURI, in nsIURI aInitialDocumentURL, in nsIURI aReferrerURI, in nsILoadGroup aLoadGroup, in imgIDecoderObserver aObserver, in nsISupports aCX, in nsLoadFlags aLoadFlags, in nsISupports cacheKey, in imgIRequest aRequest); */
  NS_IMETHOD LoadImage(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsILoadGroup *aLoadGroup, imgIDecoderObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, imgIRequest *aRequest, imgIRequest **_retval NS_OUTPARAM) = 0;

  /**
   * Start the load and decode of an image.
   * @param aChannel the channel to load the image from.  This must
   *                 already be opened before ths method is called, and there
   *                 must have been no OnDataAvailable calls for it yet.   
   * @param aObserver the observer
   * @param cx some random data
   * @param aListener [out]
   *        A listener that should receive the data. Can be null, in which
   *        case imagelib has found a cached image and is not interested in
   *        the data. The caller needs not cancel the channel in this case.
   *
   * libpr0n does NOT keep a strong ref to the observer; this prevents
   * reference cycles.  This means that callers of loadImageWithChannel should
   * make sure to Cancel() the resulting request before the observer goes away.
   */
  /* [noscript] imgIRequest loadImageWithChannel (in nsIChannel aChannel, in imgIDecoderObserver aObserver, in nsISupports cx, out nsIStreamListener aListener); */
  NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, imgIDecoderObserver *aObserver, nsISupports *cx, nsIStreamListener **aListener NS_OUTPARAM, imgIRequest **_retval NS_OUTPARAM) = 0;

  /**
   * Checks if a decoder for the an image with the given mime type is available
   * @param mimeType The type to find a decoder for
   * @return true if a decoder is available, false otherwise
   */
  /* boolean supportImageWithMimeType (in string mimeType); */
  NS_SCRIPTABLE NS_IMETHOD SupportImageWithMimeType(const char *mimeType, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgILoader, IMGILOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGILOADER \
  NS_IMETHOD LoadImage(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsILoadGroup *aLoadGroup, imgIDecoderObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, imgIRequest *aRequest, imgIRequest **_retval NS_OUTPARAM); \
  NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, imgIDecoderObserver *aObserver, nsISupports *cx, nsIStreamListener **aListener NS_OUTPARAM, imgIRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SupportImageWithMimeType(const char *mimeType, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGILOADER(_to) \
  NS_IMETHOD LoadImage(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsILoadGroup *aLoadGroup, imgIDecoderObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, imgIRequest *aRequest, imgIRequest **_retval NS_OUTPARAM) { return _to LoadImage(aURI, aInitialDocumentURL, aReferrerURI, aLoadGroup, aObserver, aCX, aLoadFlags, cacheKey, aRequest, _retval); } \
  NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, imgIDecoderObserver *aObserver, nsISupports *cx, nsIStreamListener **aListener NS_OUTPARAM, imgIRequest **_retval NS_OUTPARAM) { return _to LoadImageWithChannel(aChannel, aObserver, cx, aListener, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SupportImageWithMimeType(const char *mimeType, PRBool *_retval NS_OUTPARAM) { return _to SupportImageWithMimeType(mimeType, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGILOADER(_to) \
  NS_IMETHOD LoadImage(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsILoadGroup *aLoadGroup, imgIDecoderObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, imgIRequest *aRequest, imgIRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadImage(aURI, aInitialDocumentURL, aReferrerURI, aLoadGroup, aObserver, aCX, aLoadFlags, cacheKey, aRequest, _retval); } \
  NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, imgIDecoderObserver *aObserver, nsISupports *cx, nsIStreamListener **aListener NS_OUTPARAM, imgIRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadImageWithChannel(aChannel, aObserver, cx, aListener, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SupportImageWithMimeType(const char *mimeType, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SupportImageWithMimeType(mimeType, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgILoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGILOADER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgILoader)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] imgIRequest loadImage (in nsIURI aURI, in nsIURI aInitialDocumentURL, in nsIURI aReferrerURI, in nsILoadGroup aLoadGroup, in imgIDecoderObserver aObserver, in nsISupports aCX, in nsLoadFlags aLoadFlags, in nsISupports cacheKey, in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::LoadImage(nsIURI *aURI, nsIURI *aInitialDocumentURL, nsIURI *aReferrerURI, nsILoadGroup *aLoadGroup, imgIDecoderObserver *aObserver, nsISupports *aCX, nsLoadFlags aLoadFlags, nsISupports *cacheKey, imgIRequest *aRequest, imgIRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] imgIRequest loadImageWithChannel (in nsIChannel aChannel, in imgIDecoderObserver aObserver, in nsISupports cx, out nsIStreamListener aListener); */
NS_IMETHODIMP _MYCLASS_::LoadImageWithChannel(nsIChannel *aChannel, imgIDecoderObserver *aObserver, nsISupports *cx, nsIStreamListener **aListener NS_OUTPARAM, imgIRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean supportImageWithMimeType (in string mimeType); */
NS_IMETHODIMP _MYCLASS_::SupportImageWithMimeType(const char *mimeType, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgILoader_h__ */
