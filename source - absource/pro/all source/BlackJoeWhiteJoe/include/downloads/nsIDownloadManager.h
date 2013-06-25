/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/downloads/public/nsIDownloadManager.idl
 */

#ifndef __gen_nsIDownloadManager_h__
#define __gen_nsIDownloadManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsILocalFile; /* forward declaration */

class nsIDownload; /* forward declaration */

class nsICancelable; /* forward declaration */

class nsIMIMEInfo; /* forward declaration */

class nsIDownloadProgressListener; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class mozIStorageConnection; /* forward declaration */


/* starting interface:    nsIDownloadManager */
#define NS_IDOWNLOADMANAGER_IID_STR "bacca1ac-1b01-4a6f-9e91-c2ead1f7d2c0"

#define NS_IDOWNLOADMANAGER_IID \
  {0xbacca1ac, 0x1b01, 0x4a6f, \
    { 0x9e, 0x91, 0xc2, 0xea, 0xd1, 0xf7, 0xd2, 0xc0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDownloadManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADMANAGER_IID)

  /**
   * Download type for generic file download.
   */
  enum { DOWNLOAD_TYPE_DOWNLOAD = 0 };

  /**
   * Download state for uninitialized download object.
   */
  enum { DOWNLOAD_NOTSTARTED = -1 };

  /**
   * Download is currently transferring data.
   */
  enum { DOWNLOAD_DOWNLOADING = 0 };

  /**
   * Download completed including any processing of the target
   * file.  (completed)
   */
  enum { DOWNLOAD_FINISHED = 1 };

  /**
   * Transfer failed due to error. (completed)
   */
  enum { DOWNLOAD_FAILED = 2 };

  /**
   * Download was canceled by the user. (completed)
   */
  enum { DOWNLOAD_CANCELED = 3 };

  /**
   * Transfer was paused by the user.
   */
  enum { DOWNLOAD_PAUSED = 4 };

  /**
   * Download is active but data has not yet been received.
   */
  enum { DOWNLOAD_QUEUED = 5 };

  /**
   * Transfer request was blocked by parental controls proxies. (completed)
   */
  enum { DOWNLOAD_BLOCKED_PARENTAL = 6 };

  /**
   * Transferred download is being scanned by virus scanners.
   */
  enum { DOWNLOAD_SCANNING = 7 };

  /**
   * A virus was detected in the download. The target will most likely
   * no longer exist. (completed)
   */
  enum { DOWNLOAD_DIRTY = 8 };

  /**
   * Win specific: Request was blocked by zone policy settings.
   * (see bug #416683) (completed)
   */
  enum { DOWNLOAD_BLOCKED_POLICY = 9 };

  /**
   * Creates an nsIDownload and adds it to be managed by the download manager.
   *
   * @param aSource The source URI of the transfer. Must not be null.
   *
   * @param aTarget The target URI of the transfer. Must not be null.
   *
   * @param aDisplayName The user-readable description of the transfer.
   *                     Can be empty.
   *
   * @param aMIMEInfo The MIME info associated with the target,
   *                  including MIME type and helper app when appropriate.
   *                  This parameter is optional.
   *
   * @param startTime Time when the download started
   *
   * @param aTempFile The location of a temporary file; i.e. a file in which
   *                  the received data will be stored, but which is not
   *                  equal to the target file. (will be moved to the real
   *                  target by the caller, when the download is finished)
   *                  May be null.
   *
   * @param aCancelable An object that can be used to abort the download.
   *                    Must not be null.
   *
   * @return The newly created download item with the passed-in properties.
   *
   * @note This does not actually start a download.  If you want to add and
   *       start a download, you need to create an nsIWebBrowserPersist, pass it
   *       as the aCancelable object, call this method, set the progressListener
   *       as the returned download object, then call saveURI.
   */
  /* nsIDownload addDownload (in short aDownloadType, in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime aStartTime, in nsILocalFile aTempFile, in nsICancelable aCancelable); */
  NS_SCRIPTABLE NS_IMETHOD AddDownload(PRInt16 aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsILocalFile *aTempFile, nsICancelable *aCancelable, nsIDownload **_retval NS_OUTPARAM) = 0;

  /**
   * Retrieves a download managed by the download manager.  This can be one that
   * is in progress, or one that has completed in the past and is stored in the
   * database.
   *
   * @param aID The unique ID of the download.
   * @return The download with the specified ID.
   * @throws NS_ERROR_NOT_AVAILABLE if the download is not in the database.
   */
  /* nsIDownload getDownload (in unsigned long aID); */
  NS_SCRIPTABLE NS_IMETHOD GetDownload(PRUint32 aID, nsIDownload **_retval NS_OUTPARAM) = 0;

  /**
   * Cancels the download with the specified ID if it's currently in-progress.
   * This calls cancel(NS_BINDING_ABORTED) on the nsICancelable provided by the
   * download.
   *
   * @param aID The unique ID of the download.
   * @throws NS_ERROR_FAILURE if the download is not in-progress.
   */
  /* void cancelDownload (in unsigned long aID); */
  NS_SCRIPTABLE NS_IMETHOD CancelDownload(PRUint32 aID) = 0;

  /**
   * Removes the download with the specified id if it's not currently
   * in-progress.  Whereas cancelDownload simply cancels the transfer, but
   * retains information about it, removeDownload removes all knowledge of it.
   *
   * Also notifies observers of the "download-manager-remove-download" topic
   * with the download id as the subject to allow any DM consumers to react to
   * the removal.
   *
   * @param aID The unique ID of the download.
   * @throws NS_ERROR_FAILURE if the download is active.
   */
  /* void removeDownload (in unsigned long aID); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDownload(PRUint32 aID) = 0;

  /**
   * Removes all inactive downloads that were started inclusively within the
   * specified time frame.
   *
   * @param aBeginTime
   *        The start time to remove downloads by in microseconds.
   * @param aEndTime
   *        The end time to remove downloads by in microseconds.
   */
  /* void removeDownloadsByTimeframe (in long long aBeginTime, in long long aEndTime); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDownloadsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) = 0;

  /**
   * Pause the specified download.
   *
   * @param aID The unique ID of the download.
   * @throws NS_ERROR_FAILURE if the download is not in-progress.
   */
  /* void pauseDownload (in unsigned long aID); */
  NS_SCRIPTABLE NS_IMETHOD PauseDownload(PRUint32 aID) = 0;

  /**
   * Resume the specified download.
   *
   * @param aID The unique ID of the download.
   * @throws NS_ERROR_FAILURE if the download is not in-progress.
   */
  /* void resumeDownload (in unsigned long aID); */
  NS_SCRIPTABLE NS_IMETHOD ResumeDownload(PRUint32 aID) = 0;

  /**
   * Retries a failed download.
   *
   * @param aID The unique ID of the download.
   * @throws NS_ERROR_NOT_AVAILALE if the download id is not known.
   * @throws NS_ERROR_FAILURE if the download is not in the following states:
   *           nsIDownloadManager::DOWNLOAD_CANCELED
   *           nsIDownloadManager::DOWNLOAD_FAILED
   */
  /* void retryDownload (in unsigned long aID); */
  NS_SCRIPTABLE NS_IMETHOD RetryDownload(PRUint32 aID) = 0;

  /**
   * The database connection to the downloads database.
   */
  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) = 0;

  /** 
   * Whether or not there are downloads that can be cleaned up (removed)
   * i.e. downloads that have completed, have failed or have been canceled.
   */
  /* readonly attribute boolean canCleanUp; */
  NS_SCRIPTABLE NS_IMETHOD GetCanCleanUp(PRBool *aCanCleanUp) = 0;

  /** 
   * Removes completed, failed, and canceled downloads from the list.
   *
   * Also notifies observers of the "download-manager-remove-download" topic
   * with a null subject to allow any DM consumers to react to the removals.
   */
  /* void cleanUp (); */
  NS_SCRIPTABLE NS_IMETHOD CleanUp(void) = 0;

  /** 
   * The number of files currently being downloaded.
   */
  /* readonly attribute long activeDownloadCount; */
  NS_SCRIPTABLE NS_IMETHOD GetActiveDownloadCount(PRInt32 *aActiveDownloadCount) = 0;

  /**
   * An enumeration of active nsIDownloads
   */
  /* readonly attribute nsISimpleEnumerator activeDownloads; */
  NS_SCRIPTABLE NS_IMETHOD GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads) = 0;

  /**
   * Adds a listener from the download manager.
   */
  /* void addListener (in nsIDownloadProgressListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIDownloadProgressListener *aListener) = 0;

  /**
   * Removes a listener from the download manager.
   */
  /* void removeListener (in nsIDownloadProgressListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIDownloadProgressListener *aListener) = 0;

  /**
   * Returns the platform default downloads directory.
   */
  /* readonly attribute nsILocalFile defaultDownloadsDirectory; */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultDownloadsDirectory(nsILocalFile * *aDefaultDownloadsDirectory) = 0;

  /**
   * Returns the user configured downloads directory. 
   * The path is dependent on two user configurable prefs
   * set in preferences:
   *
   * browser.download.folderList
   *   Indicates the location users wish to save downloaded 
   *   files too.  
   *   Values: 
   *     0 - The desktop is the default download location. 
   *     1 - The system's downloads folder is the default download location. 
   *     2 - The default download location is elsewhere as specified in  
   *         browser.download.dir. If invalid, userDownloadsDirectory
   *         will fallback on defaultDownloadsDirectory.
   *
   * browser.download.dir - 
   *   A local path the user may have selected at some point 
   *   where downloaded files are saved. The use of which is
   *   enabled when folderList equals 2. 
   */
  /* readonly attribute nsILocalFile userDownloadsDirectory; */
  NS_SCRIPTABLE NS_IMETHOD GetUserDownloadsDirectory(nsILocalFile * *aUserDownloadsDirectory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloadManager, NS_IDOWNLOADMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADMANAGER \
  NS_SCRIPTABLE NS_IMETHOD AddDownload(PRInt16 aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsILocalFile *aTempFile, nsICancelable *aCancelable, nsIDownload **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDownload(PRUint32 aID, nsIDownload **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CancelDownload(PRUint32 aID); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownload(PRUint32 aID); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownloadsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime); \
  NS_SCRIPTABLE NS_IMETHOD PauseDownload(PRUint32 aID); \
  NS_SCRIPTABLE NS_IMETHOD ResumeDownload(PRUint32 aID); \
  NS_SCRIPTABLE NS_IMETHOD RetryDownload(PRUint32 aID); \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection); \
  NS_SCRIPTABLE NS_IMETHOD GetCanCleanUp(PRBool *aCanCleanUp); \
  NS_SCRIPTABLE NS_IMETHOD CleanUp(void); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveDownloadCount(PRInt32 *aActiveDownloadCount); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads); \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIDownloadProgressListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIDownloadProgressListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultDownloadsDirectory(nsILocalFile * *aDefaultDownloadsDirectory); \
  NS_SCRIPTABLE NS_IMETHOD GetUserDownloadsDirectory(nsILocalFile * *aUserDownloadsDirectory); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDownload(PRInt16 aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsILocalFile *aTempFile, nsICancelable *aCancelable, nsIDownload **_retval NS_OUTPARAM) { return _to AddDownload(aDownloadType, aSource, aTarget, aDisplayName, aMIMEInfo, aStartTime, aTempFile, aCancelable, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDownload(PRUint32 aID, nsIDownload **_retval NS_OUTPARAM) { return _to GetDownload(aID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CancelDownload(PRUint32 aID) { return _to CancelDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownload(PRUint32 aID) { return _to RemoveDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownloadsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) { return _to RemoveDownloadsByTimeframe(aBeginTime, aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD PauseDownload(PRUint32 aID) { return _to PauseDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD ResumeDownload(PRUint32 aID) { return _to ResumeDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD RetryDownload(PRUint32 aID) { return _to RetryDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return _to GetDBConnection(aDBConnection); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanCleanUp(PRBool *aCanCleanUp) { return _to GetCanCleanUp(aCanCleanUp); } \
  NS_SCRIPTABLE NS_IMETHOD CleanUp(void) { return _to CleanUp(); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveDownloadCount(PRInt32 *aActiveDownloadCount) { return _to GetActiveDownloadCount(aActiveDownloadCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads) { return _to GetActiveDownloads(aActiveDownloads); } \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIDownloadProgressListener *aListener) { return _to AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIDownloadProgressListener *aListener) { return _to RemoveListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultDownloadsDirectory(nsILocalFile * *aDefaultDownloadsDirectory) { return _to GetDefaultDownloadsDirectory(aDefaultDownloadsDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserDownloadsDirectory(nsILocalFile * *aUserDownloadsDirectory) { return _to GetUserDownloadsDirectory(aUserDownloadsDirectory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDownload(PRInt16 aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsILocalFile *aTempFile, nsICancelable *aCancelable, nsIDownload **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDownload(aDownloadType, aSource, aTarget, aDisplayName, aMIMEInfo, aStartTime, aTempFile, aCancelable, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDownload(PRUint32 aID, nsIDownload **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownload(aID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CancelDownload(PRUint32 aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownload(PRUint32 aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownloadsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDownloadsByTimeframe(aBeginTime, aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD PauseDownload(PRUint32 aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->PauseDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD ResumeDownload(PRUint32 aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD RetryDownload(PRUint32 aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->RetryDownload(aID); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanCleanUp(PRBool *aCanCleanUp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanCleanUp(aCanCleanUp); } \
  NS_SCRIPTABLE NS_IMETHOD CleanUp(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CleanUp(); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveDownloadCount(PRInt32 *aActiveDownloadCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveDownloadCount(aActiveDownloadCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveDownloads(aActiveDownloads); } \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIDownloadProgressListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIDownloadProgressListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultDownloadsDirectory(nsILocalFile * *aDefaultDownloadsDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultDownloadsDirectory(aDefaultDownloadsDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserDownloadsDirectory(nsILocalFile * *aUserDownloadsDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserDownloadsDirectory(aUserDownloadsDirectory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloadManager : public nsIDownloadManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADMANAGER

  nsDownloadManager();

private:
  ~nsDownloadManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownloadManager, nsIDownloadManager)

nsDownloadManager::nsDownloadManager()
{
  /* member initializers and constructor code */
}

nsDownloadManager::~nsDownloadManager()
{
  /* destructor code */
}

/* nsIDownload addDownload (in short aDownloadType, in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime aStartTime, in nsILocalFile aTempFile, in nsICancelable aCancelable); */
NS_IMETHODIMP nsDownloadManager::AddDownload(PRInt16 aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsILocalFile *aTempFile, nsICancelable *aCancelable, nsIDownload **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDownload getDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::GetDownload(PRUint32 aID, nsIDownload **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::CancelDownload(PRUint32 aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::RemoveDownload(PRUint32 aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDownloadsByTimeframe (in long long aBeginTime, in long long aEndTime); */
NS_IMETHODIMP nsDownloadManager::RemoveDownloadsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pauseDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::PauseDownload(PRUint32 aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::ResumeDownload(PRUint32 aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void retryDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::RetryDownload(PRUint32 aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP nsDownloadManager::GetDBConnection(mozIStorageConnection * *aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canCleanUp; */
NS_IMETHODIMP nsDownloadManager::GetCanCleanUp(PRBool *aCanCleanUp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cleanUp (); */
NS_IMETHODIMP nsDownloadManager::CleanUp()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long activeDownloadCount; */
NS_IMETHODIMP nsDownloadManager::GetActiveDownloadCount(PRInt32 *aActiveDownloadCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator activeDownloads; */
NS_IMETHODIMP nsDownloadManager::GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addListener (in nsIDownloadProgressListener aListener); */
NS_IMETHODIMP nsDownloadManager::AddListener(nsIDownloadProgressListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in nsIDownloadProgressListener aListener); */
NS_IMETHODIMP nsDownloadManager::RemoveListener(nsIDownloadProgressListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILocalFile defaultDownloadsDirectory; */
NS_IMETHODIMP nsDownloadManager::GetDefaultDownloadsDirectory(nsILocalFile * *aDefaultDownloadsDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILocalFile userDownloadsDirectory; */
NS_IMETHODIMP nsDownloadManager::GetUserDownloadsDirectory(nsILocalFile * *aUserDownloadsDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDownloadManager_h__ */
