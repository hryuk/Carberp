/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIDownloader.idl
 */

#ifndef __gen_nsIDownloader_h__
#define __gen_nsIDownloader_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIDownloadObserver; /* forward declaration */


/* starting interface:    nsIDownloader */
#define NS_IDOWNLOADER_IID_STR "fafe41a9-a531-4d6d-89bc-588a6522fb4e"

#define NS_IDOWNLOADER_IID \
  {0xfafe41a9, 0xa531, 0x4d6d, \
    { 0x89, 0xbc, 0x58, 0x8a, 0x65, 0x22, 0xfb, 0x4e }}

/**
 * nsIDownloader
 *
 * A downloader is a special implementation of a nsIStreamListener that will
 * make the contents of the stream available as a file.  This may utilize the
 * disk cache as an optimization to avoid an extra copy of the data on disk.
 * The resulting file is valid from the time the downloader completes until
 * the last reference to the downloader is released.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDownloader : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADER_IID)

  /**
     * Initialize this downloader
     *
     * @param observer
     *        the observer to be notified when the download completes.
     * @param downloadLocation
     *        the location where the stream contents should be written.
     *        if null, the downloader will select a location and the
     *        resulting file will be deleted (or otherwise made invalid)
     *        when the downloader object is destroyed.  if an explicit
     *        download location is specified then the resulting file will
     *        not be deleted, and it will be the callers responsibility
     *        to keep track of the file, etc.
     */
  /* void init (in nsIDownloadObserver observer, in nsIFile downloadLocation); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDownloadObserver *observer, nsIFile *downloadLocation) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloader, NS_IDOWNLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDownloadObserver *observer, nsIFile *downloadLocation); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDownloadObserver *observer, nsIFile *downloadLocation) { return _to Init(observer, downloadLocation); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDownloadObserver *observer, nsIFile *downloadLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(observer, downloadLocation); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloader : public nsIDownloader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADER

  nsDownloader();

private:
  ~nsDownloader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownloader, nsIDownloader)

nsDownloader::nsDownloader()
{
  /* member initializers and constructor code */
}

nsDownloader::~nsDownloader()
{
  /* destructor code */
}

/* void init (in nsIDownloadObserver observer, in nsIFile downloadLocation); */
NS_IMETHODIMP nsDownloader::Init(nsIDownloadObserver *observer, nsIFile *downloadLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDownloadObserver */
#define NS_IDOWNLOADOBSERVER_IID_STR "44b3153e-a54e-4077-a527-b0325e40924e"

#define NS_IDOWNLOADOBSERVER_IID \
  {0x44b3153e, 0xa54e, 0x4077, \
    { 0xa5, 0x27, 0xb0, 0x32, 0x5e, 0x40, 0x92, 0x4e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDownloadObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADOBSERVER_IID)

  /**
     * Called to signal a download that has completed.
     */
  /* void onDownloadComplete (in nsIDownloader downloader, in nsIRequest request, in nsISupports ctxt, in nsresult status, in nsIFile result); */
  NS_SCRIPTABLE NS_IMETHOD OnDownloadComplete(nsIDownloader *downloader, nsIRequest *request, nsISupports *ctxt, nsresult status, nsIFile *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloadObserver, NS_IDOWNLOADOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadComplete(nsIDownloader *downloader, nsIRequest *request, nsISupports *ctxt, nsresult status, nsIFile *result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadComplete(nsIDownloader *downloader, nsIRequest *request, nsISupports *ctxt, nsresult status, nsIFile *result) { return _to OnDownloadComplete(downloader, request, ctxt, status, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadComplete(nsIDownloader *downloader, nsIRequest *request, nsISupports *ctxt, nsresult status, nsIFile *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDownloadComplete(downloader, request, ctxt, status, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloadObserver : public nsIDownloadObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADOBSERVER

  nsDownloadObserver();

private:
  ~nsDownloadObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownloadObserver, nsIDownloadObserver)

nsDownloadObserver::nsDownloadObserver()
{
  /* member initializers and constructor code */
}

nsDownloadObserver::~nsDownloadObserver()
{
  /* destructor code */
}

/* void onDownloadComplete (in nsIDownloader downloader, in nsIRequest request, in nsISupports ctxt, in nsresult status, in nsIFile result); */
NS_IMETHODIMP nsDownloadObserver::OnDownloadComplete(nsIDownloader *downloader, nsIRequest *request, nsISupports *ctxt, nsresult status, nsIFile *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDownloader_h__ */
