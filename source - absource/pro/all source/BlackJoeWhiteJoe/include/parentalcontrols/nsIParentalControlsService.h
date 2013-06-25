/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/parentalcontrols/public/nsIParentalControlsService.idl
 */

#ifndef __gen_nsIParentalControlsService_h__
#define __gen_nsIParentalControlsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIParentalControlsService */
#define NS_IPARENTALCONTROLSSERVICE_IID_STR "871cf229-2b21-4f04-b24d-e08061f14815"

#define NS_IPARENTALCONTROLSSERVICE_IID \
  {0x871cf229, 0x2b21, 0x4f04, \
    { 0xb2, 0x4d, 0xe0, 0x80, 0x61, 0xf1, 0x48, 0x15 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIParentalControlsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPARENTALCONTROLSSERVICE_IID)

  /**
   * @returns true if the current user account has parental controls
   * restrictions enabled.
   */
  /* readonly attribute boolean parentalControlsEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetParentalControlsEnabled(PRBool *aParentalControlsEnabled) = 0;

  /**
   * @returns true if the current user account parental controls
   * restrictions include the blocking of all file downloads.
   */
  /* readonly attribute boolean blockFileDownloadsEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetBlockFileDownloadsEnabled(PRBool *aBlockFileDownloadsEnabled) = 0;

  /**
   * Request that blocked URI(s) be allowed through parental
   * control filters. Returns true if the URI was successfully
   * overriden. Note, may block while native UI is shown.
   *
   * @param aTarget(s)          URI to be overridden. In the case of
   *                            multiple URI, the first URI in the array
   *                            should be the root URI of the site.
   * @param window              Window that generates the event.
   */
  /* boolean requestURIOverride (in nsIURI aTarget, [optional] in nsIInterfaceRequestor aWindowContext); */
  NS_SCRIPTABLE NS_IMETHOD RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean requestURIOverrides (in nsIArray aTargets, [optional] in nsIInterfaceRequestor aWindowContext); */
  NS_SCRIPTABLE NS_IMETHOD RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * @returns true if the current user account has parental controls
   * logging enabled. If true, applications should log relevent events
   * using 'log'.
   */
  /* readonly attribute boolean loggingEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetLoggingEnabled(PRBool *aLoggingEnabled) = 0;

  /**
   * Log entry types. Additional types can be defined and implemented
   * as needed. Other possible event types might include email events,
   * media related events, and IM events. 
   */
  enum { ePCLog_URIVisit = 1 };

  enum { ePCLog_FileDownload = 2 };

  /**
   * Log an application specific parental controls
   * event.
   *
   * @param aEntryType       Constant defining the type of event.
   * @param aFlag            A flag indicating if the subject content
   *                         was blocked.
   * @param aSource          The URI source of the subject content.
   * @param aTarget          The location the content was saved to if
   *                         no blocking occured.
   */
  /* void log (in short aEntryType, in boolean aFlag, in nsIURI aSource, [optional] in nsIFile aTarget); */
  NS_SCRIPTABLE NS_IMETHOD Log(PRInt16 aEntryType, PRBool aFlag, nsIURI *aSource, nsIFile *aTarget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIParentalControlsService, NS_IPARENTALCONTROLSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPARENTALCONTROLSSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetParentalControlsEnabled(PRBool *aParentalControlsEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetBlockFileDownloadsEnabled(PRBool *aBlockFileDownloadsEnabled); \
  NS_SCRIPTABLE NS_IMETHOD RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLoggingEnabled(PRBool *aLoggingEnabled); \
  NS_SCRIPTABLE NS_IMETHOD Log(PRInt16 aEntryType, PRBool aFlag, nsIURI *aSource, nsIFile *aTarget); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPARENTALCONTROLSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParentalControlsEnabled(PRBool *aParentalControlsEnabled) { return _to GetParentalControlsEnabled(aParentalControlsEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlockFileDownloadsEnabled(PRBool *aBlockFileDownloadsEnabled) { return _to GetBlockFileDownloadsEnabled(aBlockFileDownloadsEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM) { return _to RequestURIOverride(aTarget, aWindowContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM) { return _to RequestURIOverrides(aTargets, aWindowContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoggingEnabled(PRBool *aLoggingEnabled) { return _to GetLoggingEnabled(aLoggingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD Log(PRInt16 aEntryType, PRBool aFlag, nsIURI *aSource, nsIFile *aTarget) { return _to Log(aEntryType, aFlag, aSource, aTarget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPARENTALCONTROLSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParentalControlsEnabled(PRBool *aParentalControlsEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentalControlsEnabled(aParentalControlsEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlockFileDownloadsEnabled(PRBool *aBlockFileDownloadsEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlockFileDownloadsEnabled(aBlockFileDownloadsEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestURIOverride(aTarget, aWindowContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestURIOverrides(aTargets, aWindowContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoggingEnabled(PRBool *aLoggingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoggingEnabled(aLoggingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD Log(PRInt16 aEntryType, PRBool aFlag, nsIURI *aSource, nsIFile *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->Log(aEntryType, aFlag, aSource, aTarget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsParentalControlsService : public nsIParentalControlsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPARENTALCONTROLSSERVICE

  nsParentalControlsService();

private:
  ~nsParentalControlsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsParentalControlsService, nsIParentalControlsService)

nsParentalControlsService::nsParentalControlsService()
{
  /* member initializers and constructor code */
}

nsParentalControlsService::~nsParentalControlsService()
{
  /* destructor code */
}

/* readonly attribute boolean parentalControlsEnabled; */
NS_IMETHODIMP nsParentalControlsService::GetParentalControlsEnabled(PRBool *aParentalControlsEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean blockFileDownloadsEnabled; */
NS_IMETHODIMP nsParentalControlsService::GetBlockFileDownloadsEnabled(PRBool *aBlockFileDownloadsEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean requestURIOverride (in nsIURI aTarget, [optional] in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsParentalControlsService::RequestURIOverride(nsIURI *aTarget, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean requestURIOverrides (in nsIArray aTargets, [optional] in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsParentalControlsService::RequestURIOverrides(nsIArray *aTargets, nsIInterfaceRequestor *aWindowContext, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean loggingEnabled; */
NS_IMETHODIMP nsParentalControlsService::GetLoggingEnabled(PRBool *aLoggingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void log (in short aEntryType, in boolean aFlag, in nsIURI aSource, [optional] in nsIFile aTarget); */
NS_IMETHODIMP nsParentalControlsService::Log(PRInt16 aEntryType, PRBool aFlag, nsIURI *aSource, nsIFile *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIParentalControlsService_h__ */
