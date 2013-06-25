/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/uriloader/base/nsIURILoader.idl
 */

#ifndef __gen_nsIURILoader_h__
#define __gen_nsIURILoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURIContentListener; /* forward declaration */

class nsIURI; /* forward declaration */

class nsILoadGroup; /* forward declaration */

class nsIProgressEventSink; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIURILoader */
#define NS_IURILOADER_IID_STR "2f7e8051-f1c9-4bcc-8584-9cfd5849e343"

#define NS_IURILOADER_IID \
  {0x2f7e8051, 0xf1c9, 0x4bcc, \
    { 0x85, 0x84, 0x9c, 0xfd, 0x58, 0x49, 0xe3, 0x43 }}

/**
 * The uri dispatcher is responsible for taking uri's, determining
 * the content and routing the opened url to the correct content 
 * handler. 
 *
 * When you encounter a url you want to open, you typically call 
 * openURI, passing it the content listener for the window the uri is 
 * originating from. The uri dispatcher opens the url to discover the 
 * content type. It then gives the content listener first crack at 
 * handling the content. If it doesn't want it, the dispatcher tries
 * to hand it off one of the registered content listeners. This allows
 * running applications the chance to jump in and handle the content.
 *
 * If that also fails, then the uri dispatcher goes to the registry
 * looking for the preferred content handler for the content type
 * of the uri. The content handler may create an app instance
 * or it may hand the contents off to a platform specific plugin
 * or helper app. Or it may hand the url off to an OS registered 
 * application. 
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIURILoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURILOADER_IID)

  /**
   * @name Flags for opening URIs.
   */
/**
   * Should the content be displayed in a container that prefers the
   * content-type, or will any container do.
   */
  enum { IS_CONTENT_PREFERRED = 1U };

  /**
   * If this flag is set, only the listener of the specified window context will
   * be considered for content handling; if it refuses the load, an error will
   * be indicated.
   */
  enum { DONT_RETARGET = 2U };

  /**
   * As applications such as messenger and the browser are instantiated,
   * they register content listener's with the uri dispatcher corresponding
   * to content windows within that application. 
   *
   * Note to self: we may want to optimize things a bit more by requiring
   * the content types the registered content listener cares about.
   *
   * @param aContentListener
   *        The listener to register. This listener must implement
   *        nsISupportsWeakReference.
   *
   * @see the nsIURILoader class description
   */
  /* void registerContentListener (in nsIURIContentListener aContentListener); */
  NS_SCRIPTABLE NS_IMETHOD RegisterContentListener(nsIURIContentListener *aContentListener) = 0;

  /* void unRegisterContentListener (in nsIURIContentListener aContentListener); */
  NS_SCRIPTABLE NS_IMETHOD UnRegisterContentListener(nsIURIContentListener *aContentListener) = 0;

  /**
   * OpenURI requires the following parameters.....
   * @param aChannel
   *        The channel that should be opened. This must not be asyncOpen'd yet!
   *        If a loadgroup is set on the channel, it will get replaced with a
   *        different one.
   * @param aIsContentPreferred
   *        Should the content be displayed in a container that prefers the
   *        content-type, or will any container do.
   * @param aWindowContext
   *        If you are running the url from a doc shell or a web shell, this is
   *        your window context. If you have a content listener you want to
   *        give first crack to, the uri loader needs to be able to get it
   *        from the window context. We will also be using the window context
   *        to get at the progress event sink interface.
   *        <b>Must not be null!</b>
   */
  /* void openURI (in nsIChannel aChannel, in boolean aIsContentPreferred, in nsIInterfaceRequestor aWindowContext); */
  NS_SCRIPTABLE NS_IMETHOD OpenURI(nsIChannel *aChannel, PRBool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext) = 0;

  /**
   * Loads data from a channel. This differs from openURI in that the channel
   * may already be opened, and that it returns a stream listener into which the
   * caller should pump data. The caller is responsible for opening the channel
   * and pumping the channel's data into the returned stream listener.
   *
   * Note: If the channel already has a loadgroup, it will be replaced with the
   * window context's load group, or null if the context doesn't have one.
   *
   * If the window context's nsIURIContentListener refuses the load immediately
   * (e.g. in nsIURIContentListener::onStartURIOpen), this method will return
   * NS_ERROR_WONT_HANDLE_CONTENT. At that point, the caller should probably
   * cancel the channel if it's already open (this method will not cancel the
   * channel).
   *
   * If flags include DONT_RETARGET, and the content listener refuses the load
   * during onStartRequest (e.g. in canHandleContent/isPreferred), then the
   * returned stream listener's onStartRequest method will return
   * NS_ERROR_WONT_HANDLE_CONTENT.
   *
   * @param aChannel
   *        The channel that should be loaded. The channel may already be
   *        opened. It must not be closed (i.e. this must be called before the
   *        channel calls onStopRequest on its stream listener).
   * @param aFlags
   *        Combination (bitwise OR) of the flags specified above. 0 indicates
   *        default handling.
   * @param aWindowContext
   *        If you are running the url from a doc shell or a web shell, this is
   *        your window context. If you have a content listener you want to
   *        give first crack to, the uri loader needs to be able to get it
   *        from the window context. We will also be using the window context
   *        to get at the progress event sink interface.
   *        <b>Must not be null!</b>
   */
  /* nsIStreamListener openChannel (in nsIChannel aChannel, in unsigned long aFlags, in nsIInterfaceRequestor aWindowContext); */
  NS_SCRIPTABLE NS_IMETHOD OpenChannel(nsIChannel *aChannel, PRUint32 aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener **_retval NS_OUTPARAM) = 0;

  /**
   * Stops an in progress load
   */
  /* void stop (in nsISupports aLoadCookie); */
  NS_SCRIPTABLE NS_IMETHOD Stop(nsISupports *aLoadCookie) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURILoader, NS_IURILOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURILOADER \
  NS_SCRIPTABLE NS_IMETHOD RegisterContentListener(nsIURIContentListener *aContentListener); \
  NS_SCRIPTABLE NS_IMETHOD UnRegisterContentListener(nsIURIContentListener *aContentListener); \
  NS_SCRIPTABLE NS_IMETHOD OpenURI(nsIChannel *aChannel, PRBool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext); \
  NS_SCRIPTABLE NS_IMETHOD OpenChannel(nsIChannel *aChannel, PRUint32 aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Stop(nsISupports *aLoadCookie); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURILOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterContentListener(nsIURIContentListener *aContentListener) { return _to RegisterContentListener(aContentListener); } \
  NS_SCRIPTABLE NS_IMETHOD UnRegisterContentListener(nsIURIContentListener *aContentListener) { return _to UnRegisterContentListener(aContentListener); } \
  NS_SCRIPTABLE NS_IMETHOD OpenURI(nsIChannel *aChannel, PRBool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext) { return _to OpenURI(aChannel, aIsContentPreferred, aWindowContext); } \
  NS_SCRIPTABLE NS_IMETHOD OpenChannel(nsIChannel *aChannel, PRUint32 aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener **_retval NS_OUTPARAM) { return _to OpenChannel(aChannel, aFlags, aWindowContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(nsISupports *aLoadCookie) { return _to Stop(aLoadCookie); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURILOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterContentListener(nsIURIContentListener *aContentListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterContentListener(aContentListener); } \
  NS_SCRIPTABLE NS_IMETHOD UnRegisterContentListener(nsIURIContentListener *aContentListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnRegisterContentListener(aContentListener); } \
  NS_SCRIPTABLE NS_IMETHOD OpenURI(nsIChannel *aChannel, PRBool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenURI(aChannel, aIsContentPreferred, aWindowContext); } \
  NS_SCRIPTABLE NS_IMETHOD OpenChannel(nsIChannel *aChannel, PRUint32 aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenChannel(aChannel, aFlags, aWindowContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(nsISupports *aLoadCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(aLoadCookie); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURILoader : public nsIURILoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURILOADER

  nsURILoader();

private:
  ~nsURILoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURILoader, nsIURILoader)

nsURILoader::nsURILoader()
{
  /* member initializers and constructor code */
}

nsURILoader::~nsURILoader()
{
  /* destructor code */
}

/* void registerContentListener (in nsIURIContentListener aContentListener); */
NS_IMETHODIMP nsURILoader::RegisterContentListener(nsIURIContentListener *aContentListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unRegisterContentListener (in nsIURIContentListener aContentListener); */
NS_IMETHODIMP nsURILoader::UnRegisterContentListener(nsIURIContentListener *aContentListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openURI (in nsIChannel aChannel, in boolean aIsContentPreferred, in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsURILoader::OpenURI(nsIChannel *aChannel, PRBool aIsContentPreferred, nsIInterfaceRequestor *aWindowContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStreamListener openChannel (in nsIChannel aChannel, in unsigned long aFlags, in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsURILoader::OpenChannel(nsIChannel *aChannel, PRUint32 aFlags, nsIInterfaceRequestor *aWindowContext, nsIStreamListener **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (in nsISupports aLoadCookie); */
NS_IMETHODIMP nsURILoader::Stop(nsISupports *aLoadCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURILoader_h__ */
