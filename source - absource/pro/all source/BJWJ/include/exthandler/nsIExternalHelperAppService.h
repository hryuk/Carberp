/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/uriloader/exthandler/nsIExternalHelperAppService.idl
 */

#ifndef __gen_nsIExternalHelperAppService_h__
#define __gen_nsIExternalHelperAppService_h__


#ifndef __gen_nsICancelable_h__
#include "nsICancelable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIMIMEInfo; /* forward declaration */

class nsIWebProgressListener2; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIExternalHelperAppService */
#define NS_IEXTERNALHELPERAPPSERVICE_IID_STR "9e456297-ba3e-42b1-92bd-b7db014268cb"

#define NS_IEXTERNALHELPERAPPSERVICE_IID \
  {0x9e456297, 0xba3e, 0x42b1, \
    { 0x92, 0xbd, 0xb7, 0xdb, 0x01, 0x42, 0x68, 0xcb }}

/**
 * The external helper app service is used for finding and launching
 * platform specific external applications for a given mime content type.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIExternalHelperAppService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXTERNALHELPERAPPSERVICE_IID)

  /**
   * Binds an external helper application to a stream listener. The caller
   * should pump data into the returned stream listener. When the OnStopRequest
   * is issued, the stream listener implementation will launch the helper app
   * with this data.
   * @param aMimeContentType The content type of the incoming data
   * @param aRequest The request corresponding to the incoming data
   * @param aWindowContext Use GetInterface to retrieve properties like the
   *                       dom window or parent window...
   *                       The service might need this in order to bring up dialogs.
   * @param aForceSave True to always save this content to disk, regardless of
   *                   nsIMIMEInfo and other such influences.
   * @return A nsIStreamListener which the caller should pump the data into.
   */
  /* nsIStreamListener doContent (in ACString aMimeContentType, in nsIRequest aRequest, in nsIInterfaceRequestor aWindowContext, in boolean aForceSave); */
  NS_SCRIPTABLE NS_IMETHOD DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aWindowContext, PRBool aForceSave, nsIStreamListener **_retval NS_OUTPARAM) = 0;

  /**
   * Returns true if data from a URL with this extension combination
   * is to be decoded from aEncodingType prior to saving or passing
   * off to helper apps, false otherwise.
   */
  /* boolean applyDecodingForExtension (in AUTF8String aExtension, in ACString aEncodingType); */
  NS_SCRIPTABLE NS_IMETHOD ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExternalHelperAppService, NS_IEXTERNALHELPERAPPSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXTERNALHELPERAPPSERVICE \
  NS_SCRIPTABLE NS_IMETHOD DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aWindowContext, PRBool aForceSave, nsIStreamListener **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXTERNALHELPERAPPSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aWindowContext, PRBool aForceSave, nsIStreamListener **_retval NS_OUTPARAM) { return _to DoContent(aMimeContentType, aRequest, aWindowContext, aForceSave, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, PRBool *_retval NS_OUTPARAM) { return _to ApplyDecodingForExtension(aExtension, aEncodingType, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXTERNALHELPERAPPSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aWindowContext, PRBool aForceSave, nsIStreamListener **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoContent(aMimeContentType, aRequest, aWindowContext, aForceSave, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplyDecodingForExtension(aExtension, aEncodingType, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExternalHelperAppService : public nsIExternalHelperAppService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXTERNALHELPERAPPSERVICE

  nsExternalHelperAppService();

private:
  ~nsExternalHelperAppService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExternalHelperAppService, nsIExternalHelperAppService)

nsExternalHelperAppService::nsExternalHelperAppService()
{
  /* member initializers and constructor code */
}

nsExternalHelperAppService::~nsExternalHelperAppService()
{
  /* destructor code */
}

/* nsIStreamListener doContent (in ACString aMimeContentType, in nsIRequest aRequest, in nsIInterfaceRequestor aWindowContext, in boolean aForceSave); */
NS_IMETHODIMP nsExternalHelperAppService::DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aWindowContext, PRBool aForceSave, nsIStreamListener **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean applyDecodingForExtension (in AUTF8String aExtension, in ACString aEncodingType); */
NS_IMETHODIMP nsExternalHelperAppService::ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsPIExternalAppLauncher */
#define NS_PIEXTERNALAPPLAUNCHER_IID_STR "d0b5d7d3-9565-403d-9fb5-e5089c4567c6"

#define NS_PIEXTERNALAPPLAUNCHER_IID \
  {0xd0b5d7d3, 0x9565, 0x403d, \
    { 0x9f, 0xb5, 0xe5, 0x08, 0x9c, 0x45, 0x67, 0xc6 }}

/**
 * This is a private interface shared between external app handlers and the platform specific
 * external helper app service
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsPIExternalAppLauncher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIEXTERNALAPPLAUNCHER_IID)

  /**
   * mscott --> eventually I should move this into a new service so other
   * consumers can add temporary files they want deleted on exit.
   * @param aTemporaryFile A temporary file we should delete on exit.
   */
  /* void deleteTemporaryFileOnExit (in nsIFile aTemporaryFile); */
  NS_SCRIPTABLE NS_IMETHOD DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIExternalAppLauncher, NS_PIEXTERNALAPPLAUNCHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIEXTERNALAPPLAUNCHER \
  NS_SCRIPTABLE NS_IMETHOD DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIEXTERNALAPPLAUNCHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile) { return _to DeleteTemporaryFileOnExit(aTemporaryFile); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIEXTERNALAPPLAUNCHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTemporaryFileOnExit(aTemporaryFile); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIExternalAppLauncher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIEXTERNALAPPLAUNCHER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIExternalAppLauncher)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void deleteTemporaryFileOnExit (in nsIFile aTemporaryFile); */
NS_IMETHODIMP _MYCLASS_::DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHelperAppLauncher */
#define NS_IHELPERAPPLAUNCHER_IID_STR "d9a19faf-497b-408c-b995-777d956b72c0"

#define NS_IHELPERAPPLAUNCHER_IID \
  {0xd9a19faf, 0x497b, 0x408c, \
    { 0xb9, 0x95, 0x77, 0x7d, 0x95, 0x6b, 0x72, 0xc0 }}

/**
 * A helper app launcher is a small object created to handle the launching
 * of an external application.
 *
 * Note that cancelling the load via the nsICancelable interface will release
 * the reference to the launcher dialog.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIHelperAppLauncher : public nsICancelable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHELPERAPPLAUNCHER_IID)

  /**
   * The mime info object associated with the content type this helper app
   * launcher is currently attempting to load
   */
  /* readonly attribute nsIMIMEInfo MIMEInfo; */
  NS_SCRIPTABLE NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) = 0;

  /**
   * The source uri
   */
  /* readonly attribute nsIURI source; */
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIURI * *aSource) = 0;

  /**
   * The suggested name for this file
   */
  /* readonly attribute AString suggestedFileName; */
  NS_SCRIPTABLE NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) = 0;

  /**
   * Called when we want to just save the content to a particular file.
   * NOTE: This will release the reference to the nsIHelperAppLauncherDialog.
   * @param aNewFileLocation Location where the content should be saved
   */
  /* void saveToDisk (in nsIFile aNewFileLocation, in boolean aRememberThisPreference); */
  NS_SCRIPTABLE NS_IMETHOD SaveToDisk(nsIFile *aNewFileLocation, PRBool aRememberThisPreference) = 0;

  /**
   * Use aApplication to launch with this content.
   * NOTE: This will release the reference to the nsIHelperAppLauncherDialog.
   * @param aApplication nsIFile corresponding to the location of the application to use.
   * @param aRememberThisPreference TRUE if we should remember this choice.
   */
  /* void launchWithApplication (in nsIFile aApplication, in boolean aRememberThisPreference); */
  NS_SCRIPTABLE NS_IMETHOD LaunchWithApplication(nsIFile *aApplication, PRBool aRememberThisPreference) = 0;

  /**
   * The following methods are used by the progress dialog to get or set
   * information on the current helper app launcher download.
   * This reference will be released when the download is finished (after the
   * listener receives the STATE_STOP notification).
   */
  /* void setWebProgressListener (in nsIWebProgressListener2 aWebProgressListener); */
  NS_SCRIPTABLE NS_IMETHOD SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener) = 0;

  /**
   * when the stand alone progress window actually closes, it calls this method
   * so we can release any local state...
   */
  /* void closeProgressWindow (); */
  NS_SCRIPTABLE NS_IMETHOD CloseProgressWindow(void) = 0;

  /**
   * The file we are saving to
   */
  /* readonly attribute nsIFile targetFile; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) = 0;

  /**
   * The executable-ness of the target file
   */
  /* readonly attribute boolean targetFileIsExecutable; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetFileIsExecutable(PRBool *aTargetFileIsExecutable) = 0;

  /**
   * Time when the download started
   */
  /* readonly attribute PRTime timeDownloadStarted; */
  NS_SCRIPTABLE NS_IMETHOD GetTimeDownloadStarted(PRTime *aTimeDownloadStarted) = 0;

  /**
   * The download content length, or -1 if the length is not available.
   */
  /* readonly attribute PRInt64 contentLength; */
  NS_SCRIPTABLE NS_IMETHOD GetContentLength(PRInt64 *aContentLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHelperAppLauncher, NS_IHELPERAPPLAUNCHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHELPERAPPLAUNCHER \
  NS_SCRIPTABLE NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo); \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIURI * *aSource); \
  NS_SCRIPTABLE NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName); \
  NS_SCRIPTABLE NS_IMETHOD SaveToDisk(nsIFile *aNewFileLocation, PRBool aRememberThisPreference); \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithApplication(nsIFile *aApplication, PRBool aRememberThisPreference); \
  NS_SCRIPTABLE NS_IMETHOD SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener); \
  NS_SCRIPTABLE NS_IMETHOD CloseProgressWindow(void); \
  NS_SCRIPTABLE NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile); \
  NS_SCRIPTABLE NS_IMETHOD GetTargetFileIsExecutable(PRBool *aTargetFileIsExecutable); \
  NS_SCRIPTABLE NS_IMETHOD GetTimeDownloadStarted(PRTime *aTimeDownloadStarted); \
  NS_SCRIPTABLE NS_IMETHOD GetContentLength(PRInt64 *aContentLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHELPERAPPLAUNCHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) { return _to GetMIMEInfo(aMIMEInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIURI * *aSource) { return _to GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) { return _to GetSuggestedFileName(aSuggestedFileName); } \
  NS_SCRIPTABLE NS_IMETHOD SaveToDisk(nsIFile *aNewFileLocation, PRBool aRememberThisPreference) { return _to SaveToDisk(aNewFileLocation, aRememberThisPreference); } \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithApplication(nsIFile *aApplication, PRBool aRememberThisPreference) { return _to LaunchWithApplication(aApplication, aRememberThisPreference); } \
  NS_SCRIPTABLE NS_IMETHOD SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener) { return _to SetWebProgressListener(aWebProgressListener); } \
  NS_SCRIPTABLE NS_IMETHOD CloseProgressWindow(void) { return _to CloseProgressWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) { return _to GetTargetFile(aTargetFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetFileIsExecutable(PRBool *aTargetFileIsExecutable) { return _to GetTargetFileIsExecutable(aTargetFileIsExecutable); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeDownloadStarted(PRTime *aTimeDownloadStarted) { return _to GetTimeDownloadStarted(aTimeDownloadStarted); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentLength(PRInt64 *aContentLength) { return _to GetContentLength(aContentLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHELPERAPPLAUNCHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMEInfo(aMIMEInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIURI * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuggestedFileName(aSuggestedFileName); } \
  NS_SCRIPTABLE NS_IMETHOD SaveToDisk(nsIFile *aNewFileLocation, PRBool aRememberThisPreference) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveToDisk(aNewFileLocation, aRememberThisPreference); } \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithApplication(nsIFile *aApplication, PRBool aRememberThisPreference) { return !_to ? NS_ERROR_NULL_POINTER : _to->LaunchWithApplication(aApplication, aRememberThisPreference); } \
  NS_SCRIPTABLE NS_IMETHOD SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWebProgressListener(aWebProgressListener); } \
  NS_SCRIPTABLE NS_IMETHOD CloseProgressWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseProgressWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetFile(aTargetFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetFileIsExecutable(PRBool *aTargetFileIsExecutable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetFileIsExecutable(aTargetFileIsExecutable); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeDownloadStarted(PRTime *aTimeDownloadStarted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeDownloadStarted(aTimeDownloadStarted); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentLength(PRInt64 *aContentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentLength(aContentLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHelperAppLauncher : public nsIHelperAppLauncher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHELPERAPPLAUNCHER

  nsHelperAppLauncher();

private:
  ~nsHelperAppLauncher();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHelperAppLauncher, nsIHelperAppLauncher)

nsHelperAppLauncher::nsHelperAppLauncher()
{
  /* member initializers and constructor code */
}

nsHelperAppLauncher::~nsHelperAppLauncher()
{
  /* destructor code */
}

/* readonly attribute nsIMIMEInfo MIMEInfo; */
NS_IMETHODIMP nsHelperAppLauncher::GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI source; */
NS_IMETHODIMP nsHelperAppLauncher::GetSource(nsIURI * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString suggestedFileName; */
NS_IMETHODIMP nsHelperAppLauncher::GetSuggestedFileName(nsAString & aSuggestedFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveToDisk (in nsIFile aNewFileLocation, in boolean aRememberThisPreference); */
NS_IMETHODIMP nsHelperAppLauncher::SaveToDisk(nsIFile *aNewFileLocation, PRBool aRememberThisPreference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void launchWithApplication (in nsIFile aApplication, in boolean aRememberThisPreference); */
NS_IMETHODIMP nsHelperAppLauncher::LaunchWithApplication(nsIFile *aApplication, PRBool aRememberThisPreference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWebProgressListener (in nsIWebProgressListener2 aWebProgressListener); */
NS_IMETHODIMP nsHelperAppLauncher::SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeProgressWindow (); */
NS_IMETHODIMP nsHelperAppLauncher::CloseProgressWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile targetFile; */
NS_IMETHODIMP nsHelperAppLauncher::GetTargetFile(nsIFile * *aTargetFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean targetFileIsExecutable; */
NS_IMETHODIMP nsHelperAppLauncher::GetTargetFileIsExecutable(PRBool *aTargetFileIsExecutable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime timeDownloadStarted; */
NS_IMETHODIMP nsHelperAppLauncher::GetTimeDownloadStarted(PRTime *aTimeDownloadStarted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt64 contentLength; */
NS_IMETHODIMP nsHelperAppLauncher::GetContentLength(PRInt64 *aContentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExternalHelperAppService_h__ */
