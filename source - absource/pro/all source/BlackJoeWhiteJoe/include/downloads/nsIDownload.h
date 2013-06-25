/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/downloads/public/nsIDownload.idl
 */

#ifndef __gen_nsIDownload_h__
#define __gen_nsIDownload_h__


#ifndef __gen_nsITransfer_h__
#include "nsITransfer.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsILocalFile; /* forward declaration */

class nsIObserver; /* forward declaration */

class nsICancelable; /* forward declaration */

class nsIWebProgressListener; /* forward declaration */

class nsIMIMEInfo; /* forward declaration */


/* starting interface:    nsIDownload */
#define NS_IDOWNLOAD_IID_STR "c891111e-92a6-47b8-bc46-874ebb61ac9d"

#define NS_IDOWNLOAD_IID \
  {0xc891111e, 0x92a6, 0x47b8, \
    { 0xbc, 0x46, 0x87, 0x4e, 0xbb, 0x61, 0xac, 0x9d }}

/**
 * Represents a download object.
 *
 * @note This object is no longer updated once it enters a completed state.
 *       Completed states are the following:  
 *       nsIDownloadManager::DOWNLOAD_FINISHED  
 *       nsIDownloadManager::DOWNLOAD_FAILED  
 *       nsIDownloadManager::DOWNLOAD_CANCELED 
 *       nsIDownloadManager::DOWNLOAD_BLOCKED_PARENTAL 
 *       nsIDownloadManager::DOWNLOAD_DIRTY 
 *       nsIDownloadManager::DOWNLOAD_BLOCKED_POLICY 
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDownload : public nsITransfer {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOAD_IID)

  /**
     * The target of a download is always a file on the local file system.
     */
  /* readonly attribute nsILocalFile targetFile; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetFile(nsILocalFile * *aTargetFile) = 0;

  /**
     * The percentage of transfer completed.
     * If the file size is unknown it'll be -1 here.
     */
  /* readonly attribute long percentComplete; */
  NS_SCRIPTABLE NS_IMETHOD GetPercentComplete(PRInt32 *aPercentComplete) = 0;

  /**
     * The amount of bytes downloaded so far.
     */
  /* readonly attribute long long amountTransferred; */
  NS_SCRIPTABLE NS_IMETHOD GetAmountTransferred(PRInt64 *aAmountTransferred) = 0;

  /**
     * The size of file in bytes.
     * Unknown size is represented by -1.
     */
  /* readonly attribute long long size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt64 *aSize) = 0;

  /**
     * The source of the transfer.
     */
  /* readonly attribute nsIURI source; */
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIURI * *aSource) = 0;

  /**
     * The target of the transfer.
     */
  /* readonly attribute nsIURI target; */
  NS_SCRIPTABLE NS_IMETHOD GetTarget(nsIURI * *aTarget) = 0;

  /**
     * Object that can be used to cancel the download.
     * Will be null after the download is finished.
     */
  /* readonly attribute nsICancelable cancelable; */
  NS_SCRIPTABLE NS_IMETHOD GetCancelable(nsICancelable * *aCancelable) = 0;

  /**
     * The user-readable description of the transfer.
     */
  /* readonly attribute AString displayName; */
  NS_SCRIPTABLE NS_IMETHOD GetDisplayName(nsAString & aDisplayName) = 0;

  /**
     * The time a transfer was started.
     */
  /* readonly attribute long long startTime; */
  NS_SCRIPTABLE NS_IMETHOD GetStartTime(PRInt64 *aStartTime) = 0;

  /**
     * The speed of the transfer in bytes/sec.
     */
  /* readonly attribute double speed; */
  NS_SCRIPTABLE NS_IMETHOD GetSpeed(double *aSpeed) = 0;

  /**
     * Optional. If set, it will contain the target's relevant MIME information.
     * This includes its MIME Type, helper app, and whether that helper should be
     * executed.
     */
  /* readonly attribute nsIMIMEInfo MIMEInfo; */
  NS_SCRIPTABLE NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) = 0;

  /**
     * The id of the download that is stored in the database.
     */
  /* readonly attribute unsigned long id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(PRUint32 *aId) = 0;

  /**
     * The state of the download.
     * @see nsIDownloadManager and nsIXPInstallManagerUI
     */
  /* readonly attribute short state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt16 *aState) = 0;

  /**
     * The referrer uri of the download.  This is only valid for HTTP downloads,
     * and can be null.
     */
  /* readonly attribute nsIURI referrer; */
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsIURI * *aReferrer) = 0;

  /**
     * Indicates if the download can be resumed after being paused or not.  This
     * is only the case if the download is over HTTP/1.1 or FTP and if the
     * server supports it.
     */
  /* readonly attribute boolean resumable; */
  NS_SCRIPTABLE NS_IMETHOD GetResumable(PRBool *aResumable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownload, NS_IDOWNLOAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOAD \
  NS_SCRIPTABLE NS_IMETHOD GetTargetFile(nsILocalFile * *aTargetFile); \
  NS_SCRIPTABLE NS_IMETHOD GetPercentComplete(PRInt32 *aPercentComplete); \
  NS_SCRIPTABLE NS_IMETHOD GetAmountTransferred(PRInt64 *aAmountTransferred); \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt64 *aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIURI * *aSource); \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(nsIURI * *aTarget); \
  NS_SCRIPTABLE NS_IMETHOD GetCancelable(nsICancelable * *aCancelable); \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayName(nsAString & aDisplayName); \
  NS_SCRIPTABLE NS_IMETHOD GetStartTime(PRInt64 *aStartTime); \
  NS_SCRIPTABLE NS_IMETHOD GetSpeed(double *aSpeed); \
  NS_SCRIPTABLE NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo); \
  NS_SCRIPTABLE NS_IMETHOD GetId(PRUint32 *aId); \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt16 *aState); \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsIURI * *aReferrer); \
  NS_SCRIPTABLE NS_IMETHOD GetResumable(PRBool *aResumable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTargetFile(nsILocalFile * *aTargetFile) { return _to GetTargetFile(aTargetFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetPercentComplete(PRInt32 *aPercentComplete) { return _to GetPercentComplete(aPercentComplete); } \
  NS_SCRIPTABLE NS_IMETHOD GetAmountTransferred(PRInt64 *aAmountTransferred) { return _to GetAmountTransferred(aAmountTransferred); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt64 *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIURI * *aSource) { return _to GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(nsIURI * *aTarget) { return _to GetTarget(aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetCancelable(nsICancelable * *aCancelable) { return _to GetCancelable(aCancelable); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayName(nsAString & aDisplayName) { return _to GetDisplayName(aDisplayName); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartTime(PRInt64 *aStartTime) { return _to GetStartTime(aStartTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpeed(double *aSpeed) { return _to GetSpeed(aSpeed); } \
  NS_SCRIPTABLE NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) { return _to GetMIMEInfo(aMIMEInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetId(PRUint32 *aId) { return _to GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt16 *aState) { return _to GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return _to GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD GetResumable(PRBool *aResumable) { return _to GetResumable(aResumable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTargetFile(nsILocalFile * *aTargetFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetFile(aTargetFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetPercentComplete(PRInt32 *aPercentComplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPercentComplete(aPercentComplete); } \
  NS_SCRIPTABLE NS_IMETHOD GetAmountTransferred(PRInt64 *aAmountTransferred) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAmountTransferred(aAmountTransferred); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt64 *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIURI * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(nsIURI * *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetCancelable(nsICancelable * *aCancelable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCancelable(aCancelable); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayName(nsAString & aDisplayName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayName(aDisplayName); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartTime(PRInt64 *aStartTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartTime(aStartTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpeed(double *aSpeed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpeed(aSpeed); } \
  NS_SCRIPTABLE NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMEInfo(aMIMEInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetId(PRUint32 *aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt16 *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD GetResumable(PRBool *aResumable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResumable(aResumable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownload : public nsIDownload
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOAD

  nsDownload();

private:
  ~nsDownload();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownload, nsIDownload)

nsDownload::nsDownload()
{
  /* member initializers and constructor code */
}

nsDownload::~nsDownload()
{
  /* destructor code */
}

/* readonly attribute nsILocalFile targetFile; */
NS_IMETHODIMP nsDownload::GetTargetFile(nsILocalFile * *aTargetFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long percentComplete; */
NS_IMETHODIMP nsDownload::GetPercentComplete(PRInt32 *aPercentComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long amountTransferred; */
NS_IMETHODIMP nsDownload::GetAmountTransferred(PRInt64 *aAmountTransferred)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long size; */
NS_IMETHODIMP nsDownload::GetSize(PRInt64 *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI source; */
NS_IMETHODIMP nsDownload::GetSource(nsIURI * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI target; */
NS_IMETHODIMP nsDownload::GetTarget(nsIURI * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsICancelable cancelable; */
NS_IMETHODIMP nsDownload::GetCancelable(nsICancelable * *aCancelable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString displayName; */
NS_IMETHODIMP nsDownload::GetDisplayName(nsAString & aDisplayName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long startTime; */
NS_IMETHODIMP nsDownload::GetStartTime(PRInt64 *aStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double speed; */
NS_IMETHODIMP nsDownload::GetSpeed(double *aSpeed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMIMEInfo MIMEInfo; */
NS_IMETHODIMP nsDownload::GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long id; */
NS_IMETHODIMP nsDownload::GetId(PRUint32 *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short state; */
NS_IMETHODIMP nsDownload::GetState(PRInt16 *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI referrer; */
NS_IMETHODIMP nsDownload::GetReferrer(nsIURI * *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean resumable; */
NS_IMETHODIMP nsDownload::GetResumable(PRBool *aResumable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {E3FA9D0A-1DD1-11B2-BDEF-8C720B597445}
#define NS_DOWNLOAD_CID \
    { 0xe3fa9d0a, 0x1dd1, 0x11b2, { 0xbd, 0xef, 0x8c, 0x72, 0x0b, 0x59, 0x74, 0x45 } }

#endif /* __gen_nsIDownload_h__ */
