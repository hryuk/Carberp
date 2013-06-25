/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIIncrementalDownload.idl
 */

#ifndef __gen_nsIIncrementalDownload_h__
#define __gen_nsIIncrementalDownload_h__


#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIRequestObserver; /* forward declaration */


/* starting interface:    nsIIncrementalDownload */
#define NS_IINCREMENTALDOWNLOAD_IID_STR "6687823f-56c4-461d-93a1-7f6cb7dfbfba"

#define NS_IINCREMENTALDOWNLOAD_IID \
  {0x6687823f, 0x56c4, 0x461d, \
    { 0x93, 0xa1, 0x7f, 0x6c, 0xb7, 0xdf, 0xbf, 0xba }}

/**
 * An incremental download object attempts to fetch a file piecemeal over time
 * in an effort to minimize network bandwidth usage.
 *
 * Canceling a background download does not cause the file on disk to be
 * deleted.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIncrementalDownload : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINCREMENTALDOWNLOAD_IID)

  /**
   * Initialize the incremental download object.  If the destination file
   * already exists, then only the remaining portion of the file will be
   * fetched.
   *
   * NOTE: The downloader will create the destination file if it does not
   * already exist.  It will create the file with the permissions 0600 if
   * needed.  To affect the permissions of the file, consumers of this
   * interface may create an empty file at the specified destination prior to
   * starting the incremental download.
   *
   * NOTE: Since this class may create a temporary file at the specified
   * destination, it is advisable for the consumer of this interface to specify
   * a file name for the destination that would not tempt the user into
   * double-clicking it.  For example, it might be wise to append a file
   * extension like ".part" to the end of the destination to protect users from
   * accidentally running "blah.exe" before it is a complete file.
   *
   * @param uri
   *        The URI to fetch.
   * @param destination
   *        The location where the file is to be stored.
   * @param chunkSize
   *        The size of the chunks to fetch.  A non-positive value results in
   *        the default chunk size being used.
   * @param intervalInSeconds
   *        The amount of time to wait between fetching chunks.  Pass a
   *        negative to use the default interval, or 0 to fetch the remaining
   *        part of the file in one chunk.
   */
  /* void init (in nsIURI uri, in nsIFile destination, in long chunkSize, in long intervalInSeconds); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *uri, nsIFile *destination, PRInt32 chunkSize, PRInt32 intervalInSeconds) = 0;

  /**
   * The URI being fetched.
   */
  /* readonly attribute nsIURI URI; */
  NS_SCRIPTABLE NS_IMETHOD GetURI(nsIURI * *aURI) = 0;

  /**
   * The URI being fetched after any redirects have been followed.  This
   * attribute is set just prior to calling OnStartRequest on the observer
   * passed to the start method.
   */
  /* readonly attribute nsIURI finalURI; */
  NS_SCRIPTABLE NS_IMETHOD GetFinalURI(nsIURI * *aFinalURI) = 0;

  /**
   * The file where the download is being written.
   */
  /* readonly attribute nsIFile destination; */
  NS_SCRIPTABLE NS_IMETHOD GetDestination(nsIFile * *aDestination) = 0;

  /**
   * The total number of bytes for the requested file.  This attribute is set
   * just prior to calling OnStartRequest on the observer passed to the start
   * method.
   *
   * This attribute has a value of -1 if the total size is unknown.
   */
  /* readonly attribute long long totalSize; */
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRInt64 *aTotalSize) = 0;

  /**
   * The current number of bytes downloaded so far.  This attribute is set just
   * prior to calling OnStartRequest on the observer passed to the start
   * method.
   *
   * This attribute has a value of -1 if the current size is unknown.
   */
  /* readonly attribute long long currentSize; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentSize(PRInt64 *aCurrentSize) = 0;

  /**
   * Start the incremental download.
   *
   * @param observer
   *        An observer to be notified of various events.  OnStartRequest is
   *        called when finalURI and totalSize have been determined or when an
   *        error occurs.  OnStopRequest is called when the file is completely
   *        downloaded or when an error occurs.  If this object implements
   *        nsIProgressEventSink, then its OnProgress method will be called as
   *        data is written to the destination file.  If this object implements
   *        nsIInterfaceRequestor, then it will be assigned as the underlying
   *        channel's notification callbacks, which allows it to provide a
   *        nsIAuthPrompt implementation if needed by the channel, for example.
   * @param ctxt
   *        User defined object forwarded to the observer's methods.
   */
  /* void start (in nsIRequestObserver observer, in nsISupports ctxt); */
  NS_SCRIPTABLE NS_IMETHOD Start(nsIRequestObserver *observer, nsISupports *ctxt) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIncrementalDownload, NS_IINCREMENTALDOWNLOAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINCREMENTALDOWNLOAD \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *uri, nsIFile *destination, PRInt32 chunkSize, PRInt32 intervalInSeconds); \
  NS_SCRIPTABLE NS_IMETHOD GetURI(nsIURI * *aURI); \
  NS_SCRIPTABLE NS_IMETHOD GetFinalURI(nsIURI * *aFinalURI); \
  NS_SCRIPTABLE NS_IMETHOD GetDestination(nsIFile * *aDestination); \
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRInt64 *aTotalSize); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentSize(PRInt64 *aCurrentSize); \
  NS_SCRIPTABLE NS_IMETHOD Start(nsIRequestObserver *observer, nsISupports *ctxt); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINCREMENTALDOWNLOAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *uri, nsIFile *destination, PRInt32 chunkSize, PRInt32 intervalInSeconds) { return _to Init(uri, destination, chunkSize, intervalInSeconds); } \
  NS_SCRIPTABLE NS_IMETHOD GetURI(nsIURI * *aURI) { return _to GetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetFinalURI(nsIURI * *aFinalURI) { return _to GetFinalURI(aFinalURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetDestination(nsIFile * *aDestination) { return _to GetDestination(aDestination); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRInt64 *aTotalSize) { return _to GetTotalSize(aTotalSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentSize(PRInt64 *aCurrentSize) { return _to GetCurrentSize(aCurrentSize); } \
  NS_SCRIPTABLE NS_IMETHOD Start(nsIRequestObserver *observer, nsISupports *ctxt) { return _to Start(observer, ctxt); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINCREMENTALDOWNLOAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *uri, nsIFile *destination, PRInt32 chunkSize, PRInt32 intervalInSeconds) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(uri, destination, chunkSize, intervalInSeconds); } \
  NS_SCRIPTABLE NS_IMETHOD GetURI(nsIURI * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetFinalURI(nsIURI * *aFinalURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFinalURI(aFinalURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetDestination(nsIFile * *aDestination) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDestination(aDestination); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRInt64 *aTotalSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalSize(aTotalSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentSize(PRInt64 *aCurrentSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentSize(aCurrentSize); } \
  NS_SCRIPTABLE NS_IMETHOD Start(nsIRequestObserver *observer, nsISupports *ctxt) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(observer, ctxt); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIncrementalDownload : public nsIIncrementalDownload
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINCREMENTALDOWNLOAD

  nsIncrementalDownload();

private:
  ~nsIncrementalDownload();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIncrementalDownload, nsIIncrementalDownload)

nsIncrementalDownload::nsIncrementalDownload()
{
  /* member initializers and constructor code */
}

nsIncrementalDownload::~nsIncrementalDownload()
{
  /* destructor code */
}

/* void init (in nsIURI uri, in nsIFile destination, in long chunkSize, in long intervalInSeconds); */
NS_IMETHODIMP nsIncrementalDownload::Init(nsIURI *uri, nsIFile *destination, PRInt32 chunkSize, PRInt32 intervalInSeconds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI URI; */
NS_IMETHODIMP nsIncrementalDownload::GetURI(nsIURI * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI finalURI; */
NS_IMETHODIMP nsIncrementalDownload::GetFinalURI(nsIURI * *aFinalURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile destination; */
NS_IMETHODIMP nsIncrementalDownload::GetDestination(nsIFile * *aDestination)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long totalSize; */
NS_IMETHODIMP nsIncrementalDownload::GetTotalSize(PRInt64 *aTotalSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long currentSize; */
NS_IMETHODIMP nsIncrementalDownload::GetCurrentSize(PRInt64 *aCurrentSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void start (in nsIRequestObserver observer, in nsISupports ctxt); */
NS_IMETHODIMP nsIncrementalDownload::Start(nsIRequestObserver *observer, nsISupports *ctxt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIncrementalDownload_h__ */
