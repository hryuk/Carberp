/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIImageLoadingContent.idl
 */

#ifndef __gen_nsIImageLoadingContent_h__
#define __gen_nsIImageLoadingContent_h__


#ifndef __gen_imgIDecoderObserver_h__
#include "imgIDecoderObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIRequest; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIImageLoadingContent */
#define NS_IIMAGELOADINGCONTENT_IID_STR "7744c6d3-5c60-4b7b-a526-4fe9d5ac7e97"

#define NS_IIMAGELOADINGCONTENT_IID \
  {0x7744c6d3, 0x5c60, 0x4b7b, \
    { 0xa5, 0x26, 0x4f, 0xe9, 0xd5, 0xac, 0x7e, 0x97 }}

/**
 * This interface represents a content node that loads images.  The interface
 * exists to allow getting information on the images that the content node
 * loads and to allow registration of observers for the image loads.
 *
 * Implementors of this interface should handle all the mechanics of actually
 * loading an image -- getting the URI, checking with content policies and
 * the security manager to see whether loading the URI is allowed, performing
 * the load, firing any DOM events as needed.
 *
 * An implementation of this interface may support the concepts of a
 * "current" image and a "pending" image.  If it does, a request to change
 * the currently loaded image will start a "pending" request which will
 * become current only when the image is loaded.  It is the responsibility of
 * observers to check which request they are getting notifications for.
 *
 * Observers added in mid-load will not get any notifications they
 * missed.  We should NOT freeze this interface without considering
 * this issue.  (It could be that the image status on imgIRequest is
 * sufficient, when combined with the imageBlockingStatus information.)
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIImageLoadingContent : public imgIDecoderObserver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIMAGELOADINGCONTENT_IID)

  /**
   * Request types.  Image loading content nodes attempt to do atomic
   * image changes when the image url is changed.  This means that
   * when the url changes the new image load will start, but the old
   * image will remain the "current" request until the new image is
   * fully loaded.  At that point, the old "current" request will be
   * discarded and the "pending" request will become "current".
   */
  enum { UNKNOWN_REQUEST = -1 };

  enum { CURRENT_REQUEST = 0 };

  enum { PENDING_REQUEST = 1 };

  /**
   * loadingEnabled is used to enable and disable loading in
   * situations where loading images is unwanted.  Note that enabling
   * loading will *not* automatically trigger an image load.
   */
  /* attribute boolean loadingEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetLoadingEnabled(PRBool *aLoadingEnabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLoadingEnabled(PRBool aLoadingEnabled) = 0;

  /**
   * Returns the image blocking status (@see nsIContentPolicy).  This
   * will always be an nsIContentPolicy REJECT_* status for cases when
   * the image was blocked.  This status always refers to the
   * CURRENT_REQUEST load.
   */
  /* readonly attribute short imageBlockingStatus; */
  NS_SCRIPTABLE NS_IMETHOD GetImageBlockingStatus(PRInt16 *aImageBlockingStatus) = 0;

  /**
   * Used to register an image decoder observer.  Typically, this will
   * be a proxy for a frame that wants to paint the image.
   * Notifications from ongoing image loads will be passed to all
   * registered observers.  Notifications for all request types,
   * current and pending, will be passed through.
   *
   * @param aObserver the observer to register
   *
   * @throws NS_ERROR_OUT_OF_MEMORY
   */
  /* void addObserver (in imgIDecoderObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(imgIDecoderObserver *aObserver) = 0;

  /**
   * Used to unregister an image decoder observer.
   *
   * @param aObserver the observer to unregister
   */
  /* void removeObserver (in imgIDecoderObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(imgIDecoderObserver *aObserver) = 0;

  /**
   * Accessor to get the image requests
   *
   * @param aRequestType a value saying which request is wanted
   *
   * @return the imgIRequest object (may be null, even when no error
   * is thrown)
   *
   * @throws NS_ERROR_UNEXPECTED if the request type requested is not
   * known
   */
  /* imgIRequest getRequest (in long aRequestType); */
  NS_SCRIPTABLE NS_IMETHOD GetRequest(PRInt32 aRequestType, imgIRequest **_retval NS_OUTPARAM) = 0;

  /**
   * Used to find out what type of request one is dealing with (eg
   * which request got passed through to the imgIDecoderObserver
   * interface of an observer)
   *
   * @param aRequest the request whose type we want to know
   *
   * @return an enum value saying what type this request is
   *
   * @throws NS_ERROR_UNEXPECTED if aRequest is not known
   */
  /* long getRequestType (in imgIRequest aRequest); */
  NS_SCRIPTABLE NS_IMETHOD GetRequestType(imgIRequest *aRequest, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Gets the URI of the current request, if available.
   * Otherwise, returns the last URI that this content tried to load, or
   * null if there haven't been any such attempts.
   */
  /* readonly attribute nsIURI currentURI; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) = 0;

  /**
   * loadImageWithChannel allows data from an existing channel to be
   * used as the image data for this content node.
   *
   * @param aChannel the channel that will deliver the data
   *
   * @return a stream listener to pump the image data into
   *
   * @see imgILoader::loadImageWithChannel
   *
   * @throws NS_ERROR_NULL_POINTER if aChannel is null
   */
  /* nsIStreamListener loadImageWithChannel (in nsIChannel aChannel); */
  NS_SCRIPTABLE NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener **_retval NS_OUTPARAM) = 0;

  /**
   * forceReload forces reloading of the image pointed to by currentURI
   *
   * @throws NS_ERROR_NOT_AVAILABLE if there is no current URI to reload
   */
  /* void forceReload (); */
  NS_SCRIPTABLE NS_IMETHOD ForceReload(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIImageLoadingContent, NS_IIMAGELOADINGCONTENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIMAGELOADINGCONTENT \
  NS_SCRIPTABLE NS_IMETHOD GetLoadingEnabled(PRBool *aLoadingEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetLoadingEnabled(PRBool aLoadingEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetImageBlockingStatus(PRInt16 *aImageBlockingStatus); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(imgIDecoderObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(imgIDecoderObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD GetRequest(PRInt32 aRequestType, imgIRequest **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRequestType(imgIRequest *aRequest, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI); \
  NS_SCRIPTABLE NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ForceReload(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIMAGELOADINGCONTENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLoadingEnabled(PRBool *aLoadingEnabled) { return _to GetLoadingEnabled(aLoadingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoadingEnabled(PRBool aLoadingEnabled) { return _to SetLoadingEnabled(aLoadingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageBlockingStatus(PRInt16 *aImageBlockingStatus) { return _to GetImageBlockingStatus(aImageBlockingStatus); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(imgIDecoderObserver *aObserver) { return _to AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(imgIDecoderObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequest(PRInt32 aRequestType, imgIRequest **_retval NS_OUTPARAM) { return _to GetRequest(aRequestType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequestType(imgIRequest *aRequest, PRInt32 *_retval NS_OUTPARAM) { return _to GetRequestType(aRequest, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) { return _to GetCurrentURI(aCurrentURI); } \
  NS_SCRIPTABLE NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener **_retval NS_OUTPARAM) { return _to LoadImageWithChannel(aChannel, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ForceReload(void) { return _to ForceReload(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIMAGELOADINGCONTENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLoadingEnabled(PRBool *aLoadingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadingEnabled(aLoadingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoadingEnabled(PRBool aLoadingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadingEnabled(aLoadingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageBlockingStatus(PRInt16 *aImageBlockingStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageBlockingStatus(aImageBlockingStatus); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(imgIDecoderObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(imgIDecoderObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequest(PRInt32 aRequestType, imgIRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequest(aRequestType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequestType(imgIRequest *aRequest, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestType(aRequest, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentURI(aCurrentURI); } \
  NS_SCRIPTABLE NS_IMETHOD LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadImageWithChannel(aChannel, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ForceReload(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceReload(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsImageLoadingContent : public nsIImageLoadingContent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIMAGELOADINGCONTENT

  nsImageLoadingContent();

private:
  ~nsImageLoadingContent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsImageLoadingContent, nsIImageLoadingContent)

nsImageLoadingContent::nsImageLoadingContent()
{
  /* member initializers and constructor code */
}

nsImageLoadingContent::~nsImageLoadingContent()
{
  /* destructor code */
}

/* attribute boolean loadingEnabled; */
NS_IMETHODIMP nsImageLoadingContent::GetLoadingEnabled(PRBool *aLoadingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsImageLoadingContent::SetLoadingEnabled(PRBool aLoadingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short imageBlockingStatus; */
NS_IMETHODIMP nsImageLoadingContent::GetImageBlockingStatus(PRInt16 *aImageBlockingStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in imgIDecoderObserver aObserver); */
NS_IMETHODIMP nsImageLoadingContent::AddObserver(imgIDecoderObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in imgIDecoderObserver aObserver); */
NS_IMETHODIMP nsImageLoadingContent::RemoveObserver(imgIDecoderObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgIRequest getRequest (in long aRequestType); */
NS_IMETHODIMP nsImageLoadingContent::GetRequest(PRInt32 aRequestType, imgIRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRequestType (in imgIRequest aRequest); */
NS_IMETHODIMP nsImageLoadingContent::GetRequestType(imgIRequest *aRequest, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI currentURI; */
NS_IMETHODIMP nsImageLoadingContent::GetCurrentURI(nsIURI * *aCurrentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStreamListener loadImageWithChannel (in nsIChannel aChannel); */
NS_IMETHODIMP nsImageLoadingContent::LoadImageWithChannel(nsIChannel *aChannel, nsIStreamListener **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceReload (); */
NS_IMETHODIMP nsImageLoadingContent::ForceReload()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIImageLoadingContent_h__ */
