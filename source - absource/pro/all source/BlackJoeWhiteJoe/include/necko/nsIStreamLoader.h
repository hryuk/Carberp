/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIStreamLoader.idl
 */

#ifndef __gen_nsIStreamLoader_h__
#define __gen_nsIStreamLoader_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */

class nsIStreamLoader; /* forward declaration */


/* starting interface:    nsIStreamLoaderObserver */
#define NS_ISTREAMLOADEROBSERVER_IID_STR "359f7990-d4e9-11d3-a1a5-0050041caf44"

#define NS_ISTREAMLOADEROBSERVER_IID \
  {0x359f7990, 0xd4e9, 0x11d3, \
    { 0xa1, 0xa5, 0x00, 0x50, 0x04, 0x1c, 0xaf, 0x44 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIStreamLoaderObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMLOADEROBSERVER_IID)

  /**
     * Called when the entire stream has been loaded.
     *
     * @param loader the stream loader that loaded the stream.
     * @param ctxt the context parameter of the underlying channel
     * @param status the status of the underlying channel
     * @param resultLength the length of the data loaded
     * @param result the data
     *
     * This method will always be called asynchronously by the
     * nsIStreamLoader involved, on the thread that called the
     * loader's init() method.
     */
  /* void onStreamComplete (in nsIStreamLoader loader, in nsISupports ctxt, in nsresult status, in unsigned long resultLength, [array, size_is (resultLength), const] in octet result); */
  NS_SCRIPTABLE NS_IMETHOD OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, PRUint32 resultLength, const PRUint8 *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamLoaderObserver, NS_ISTREAMLOADEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMLOADEROBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, PRUint32 resultLength, const PRUint8 *result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMLOADEROBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, PRUint32 resultLength, const PRUint8 *result) { return _to OnStreamComplete(loader, ctxt, status, resultLength, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMLOADEROBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, PRUint32 resultLength, const PRUint8 *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStreamComplete(loader, ctxt, status, resultLength, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamLoaderObserver : public nsIStreamLoaderObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMLOADEROBSERVER

  nsStreamLoaderObserver();

private:
  ~nsStreamLoaderObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamLoaderObserver, nsIStreamLoaderObserver)

nsStreamLoaderObserver::nsStreamLoaderObserver()
{
  /* member initializers and constructor code */
}

nsStreamLoaderObserver::~nsStreamLoaderObserver()
{
  /* destructor code */
}

/* void onStreamComplete (in nsIStreamLoader loader, in nsISupports ctxt, in nsresult status, in unsigned long resultLength, [array, size_is (resultLength), const] in octet result); */
NS_IMETHODIMP nsStreamLoaderObserver::OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, PRUint32 resultLength, const PRUint8 *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStreamLoader */
#define NS_ISTREAMLOADER_IID_STR "8ea7e890-8211-11d9-8bde-f66bad1e3f3a"

#define NS_ISTREAMLOADER_IID \
  {0x8ea7e890, 0x8211, 0x11d9, \
    { 0x8b, 0xde, 0xf6, 0x6b, 0xad, 0x1e, 0x3f, 0x3a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIStreamLoader : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMLOADER_IID)

  /**
 * Asynchronously loads a channel into a memory buffer.
 *
 * To use this interface, first call init() with a nsIStreamLoaderObserver
 * that will be notified when the data has been loaded. Then call asyncOpen()
 * on the channel with the nsIStreamLoader as the listener. The context
 * argument in the asyncOpen() call will be passed to the onStreamComplete()
 * callback.
 *
 * XXX define behaviour for sizes >4 GB
 */
/**
     * Initialize this stream loader, and start loading the data.
     *
     * @param aObserver
     *        An observer that will be notified when the data is complete.
     */
  /* void init (in nsIStreamLoaderObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIStreamLoaderObserver *aObserver) = 0;

  /**
     * Gets the number of bytes read so far.
     */
  /* readonly attribute unsigned long numBytesRead; */
  NS_SCRIPTABLE NS_IMETHOD GetNumBytesRead(PRUint32 *aNumBytesRead) = 0;

  /**
     * Gets the request that loaded this file.
     * null after the request has finished loading.
     */
  /* readonly attribute nsIRequest request; */
  NS_SCRIPTABLE NS_IMETHOD GetRequest(nsIRequest * *aRequest) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamLoader, NS_ISTREAMLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMLOADER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIStreamLoaderObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD GetNumBytesRead(PRUint32 *aNumBytesRead); \
  NS_SCRIPTABLE NS_IMETHOD GetRequest(nsIRequest * *aRequest); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMLOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIStreamLoaderObserver *aObserver) { return _to Init(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumBytesRead(PRUint32 *aNumBytesRead) { return _to GetNumBytesRead(aNumBytesRead); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequest(nsIRequest * *aRequest) { return _to GetRequest(aRequest); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMLOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIStreamLoaderObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumBytesRead(PRUint32 *aNumBytesRead) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumBytesRead(aNumBytesRead); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequest(nsIRequest * *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequest(aRequest); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamLoader : public nsIStreamLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMLOADER

  nsStreamLoader();

private:
  ~nsStreamLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamLoader, nsIStreamLoader)

nsStreamLoader::nsStreamLoader()
{
  /* member initializers and constructor code */
}

nsStreamLoader::~nsStreamLoader()
{
  /* destructor code */
}

/* void init (in nsIStreamLoaderObserver aObserver); */
NS_IMETHODIMP nsStreamLoader::Init(nsIStreamLoaderObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long numBytesRead; */
NS_IMETHODIMP nsStreamLoader::GetNumBytesRead(PRUint32 *aNumBytesRead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRequest request; */
NS_IMETHODIMP nsStreamLoader::GetRequest(nsIRequest * *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamLoader_h__ */
