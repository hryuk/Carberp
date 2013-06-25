/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/mime/public/nsIMIMEInfo.idl
 */

#ifndef __gen_nsIMIMEInfo_h__
#define __gen_nsIMIMEInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIUTF8StringEnumerator; /* forward declaration */

class nsIHandlerApp; /* forward declaration */

class nsIArray; /* forward declaration */

class nsIMutableArray; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

typedef PRInt32 nsHandlerInfoAction;


/* starting interface:    nsIHandlerInfo */
#define NS_IHANDLERINFO_IID_STR "325e56a7-3762-4312-aec7-f1fcf84b4145"

#define NS_IHANDLERINFO_IID \
  {0x325e56a7, 0x3762, 0x4312, \
    { 0xae, 0xc7, 0xf1, 0xfc, 0xf8, 0x4b, 0x41, 0x45 }}

/**
 * nsIHandlerInfo gives access to the information about how a given protocol
 * scheme or MIME-type is handled.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIHandlerInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHANDLERINFO_IID)

  /**
     * The type of this handler info.  For MIME handlers, this is the MIME type.
     * For protocol handlers, it's the scheme.
     * 
     * @return String representing the type.
     */
  /* readonly attribute ACString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType) = 0;

  /**
     * A human readable description of the handler type
     */
  /* attribute AString description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription) = 0;

  /**
     * The application the user has said they want associated with this content
     * type. This is not always guaranteed to be set!!
     */
  /* attribute nsIHandlerApp preferredApplicationHandler; */
  NS_SCRIPTABLE NS_IMETHOD GetPreferredApplicationHandler(nsIHandlerApp * *aPreferredApplicationHandler) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPreferredApplicationHandler(nsIHandlerApp * aPreferredApplicationHandler) = 0;

  /**
     * Applications that can handle this content type.
     *
     * The list will include the preferred handler, if any.  Elements of this
     * array are nsIHandlerApp objects, and this attribute will always reference
     * an array, whether or not there are any possible handlers.  If there are
     * no possible handlers, the array will contain no elements, so just check
     * its length (nsIArray::length) to see if there are any possible handlers.
     */
  /* readonly attribute nsIMutableArray possibleApplicationHandlers; */
  NS_SCRIPTABLE NS_IMETHOD GetPossibleApplicationHandlers(nsIMutableArray * *aPossibleApplicationHandlers) = 0;

  /**
     * Indicates whether a default application handler exists,
     * i.e. whether launchWithFile with action = useSystemDefault is possible
     * and defaultDescription will contain usable information.
     */
  /* readonly attribute boolean hasDefaultHandler; */
  NS_SCRIPTABLE NS_IMETHOD GetHasDefaultHandler(PRBool *aHasDefaultHandler) = 0;

  /**
     * A pretty name description of the associated default application. Only
     * usable if hasDefaultHandler is true.
     */
  /* readonly attribute AString defaultDescription; */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultDescription(nsAString & aDefaultDescription) = 0;

  /**
     * Launches the application with the specified URI, in a way that
     * depends on the value of preferredAction. preferredAction must be
     * useHelperApp or useSystemDefault.
     *  
     * @note Only the URI scheme is used to determine how to launch.  This is
     * essentially a pass-by-value operation.  This means that in the case of
     * a file: URI, the handler that is registered for file: will be launched
     * and our code will not make any decision based on the content-type or
     * extension, though the invoked file: handler is free to do so. 
     *
     * @param aURI
     *        The URI to launch this application with
     *
     * @param aWindowContext 
     *        The window to parent the dialog against, and, if a web handler
     *        is chosen, it is loaded in this window as well.  See 
     *        nsIHandlerApp.launchWithURI for more details.
     *
     * @throw NS_ERROR_INVALID_ARG if preferredAction is not valid for this
     * call. Other exceptions may be thrown.
     */
  /* void launchWithURI (in nsIURI aURI, [optional] in nsIInterfaceRequestor aWindowContext); */
  NS_SCRIPTABLE NS_IMETHOD LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) = 0;

  /**
     * preferredAction is how the user specified they would like to handle
     * this content type: save to disk, use specified helper app, use OS
     * default handler or handle using navigator; possible value constants
     * listed below
     */
  /* attribute nsHandlerInfoAction preferredAction; */
  NS_SCRIPTABLE NS_IMETHOD GetPreferredAction(nsHandlerInfoAction *aPreferredAction) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPreferredAction(nsHandlerInfoAction aPreferredAction) = 0;

  enum { saveToDisk = 0 };

  /**
     * Used to indicate that we know nothing about what to do with this.  You
     * could consider this to be not initialized.
     */
  enum { alwaysAsk = 1 };

  enum { useHelperApp = 2 };

  enum { handleInternally = 3 };

  enum { useSystemDefault = 4 };

  /**
     * alwaysAskBeforeHandling: if true, we should always give the user a
     * dialog asking how to dispose of this content.
     */
  /* attribute boolean alwaysAskBeforeHandling; */
  NS_SCRIPTABLE NS_IMETHOD GetAlwaysAskBeforeHandling(PRBool *aAlwaysAskBeforeHandling) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAlwaysAskBeforeHandling(PRBool aAlwaysAskBeforeHandling) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHandlerInfo, NS_IHANDLERINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHANDLERINFO \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetPreferredApplicationHandler(nsIHandlerApp * *aPreferredApplicationHandler); \
  NS_SCRIPTABLE NS_IMETHOD SetPreferredApplicationHandler(nsIHandlerApp * aPreferredApplicationHandler); \
  NS_SCRIPTABLE NS_IMETHOD GetPossibleApplicationHandlers(nsIMutableArray * *aPossibleApplicationHandlers); \
  NS_SCRIPTABLE NS_IMETHOD GetHasDefaultHandler(PRBool *aHasDefaultHandler); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultDescription(nsAString & aDefaultDescription); \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext); \
  NS_SCRIPTABLE NS_IMETHOD GetPreferredAction(nsHandlerInfoAction *aPreferredAction); \
  NS_SCRIPTABLE NS_IMETHOD SetPreferredAction(nsHandlerInfoAction aPreferredAction); \
  NS_SCRIPTABLE NS_IMETHOD GetAlwaysAskBeforeHandling(PRBool *aAlwaysAskBeforeHandling); \
  NS_SCRIPTABLE NS_IMETHOD SetAlwaysAskBeforeHandling(PRBool aAlwaysAskBeforeHandling); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHANDLERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription) { return _to SetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreferredApplicationHandler(nsIHandlerApp * *aPreferredApplicationHandler) { return _to GetPreferredApplicationHandler(aPreferredApplicationHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetPreferredApplicationHandler(nsIHandlerApp * aPreferredApplicationHandler) { return _to SetPreferredApplicationHandler(aPreferredApplicationHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetPossibleApplicationHandlers(nsIMutableArray * *aPossibleApplicationHandlers) { return _to GetPossibleApplicationHandlers(aPossibleApplicationHandlers); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasDefaultHandler(PRBool *aHasDefaultHandler) { return _to GetHasDefaultHandler(aHasDefaultHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultDescription(nsAString & aDefaultDescription) { return _to GetDefaultDescription(aDefaultDescription); } \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) { return _to LaunchWithURI(aURI, aWindowContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreferredAction(nsHandlerInfoAction *aPreferredAction) { return _to GetPreferredAction(aPreferredAction); } \
  NS_SCRIPTABLE NS_IMETHOD SetPreferredAction(nsHandlerInfoAction aPreferredAction) { return _to SetPreferredAction(aPreferredAction); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlwaysAskBeforeHandling(PRBool *aAlwaysAskBeforeHandling) { return _to GetAlwaysAskBeforeHandling(aAlwaysAskBeforeHandling); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlwaysAskBeforeHandling(PRBool aAlwaysAskBeforeHandling) { return _to SetAlwaysAskBeforeHandling(aAlwaysAskBeforeHandling); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHANDLERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsACString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreferredApplicationHandler(nsIHandlerApp * *aPreferredApplicationHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferredApplicationHandler(aPreferredApplicationHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetPreferredApplicationHandler(nsIHandlerApp * aPreferredApplicationHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreferredApplicationHandler(aPreferredApplicationHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetPossibleApplicationHandlers(nsIMutableArray * *aPossibleApplicationHandlers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPossibleApplicationHandlers(aPossibleApplicationHandlers); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasDefaultHandler(PRBool *aHasDefaultHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasDefaultHandler(aHasDefaultHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultDescription(nsAString & aDefaultDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultDescription(aDefaultDescription); } \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->LaunchWithURI(aURI, aWindowContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreferredAction(nsHandlerInfoAction *aPreferredAction) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferredAction(aPreferredAction); } \
  NS_SCRIPTABLE NS_IMETHOD SetPreferredAction(nsHandlerInfoAction aPreferredAction) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreferredAction(aPreferredAction); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlwaysAskBeforeHandling(PRBool *aAlwaysAskBeforeHandling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlwaysAskBeforeHandling(aAlwaysAskBeforeHandling); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlwaysAskBeforeHandling(PRBool aAlwaysAskBeforeHandling) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlwaysAskBeforeHandling(aAlwaysAskBeforeHandling); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHandlerInfo : public nsIHandlerInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHANDLERINFO

  nsHandlerInfo();

private:
  ~nsHandlerInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHandlerInfo, nsIHandlerInfo)

nsHandlerInfo::nsHandlerInfo()
{
  /* member initializers and constructor code */
}

nsHandlerInfo::~nsHandlerInfo()
{
  /* destructor code */
}

/* readonly attribute ACString type; */
NS_IMETHODIMP nsHandlerInfo::GetType(nsACString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString description; */
NS_IMETHODIMP nsHandlerInfo::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHandlerInfo::SetDescription(const nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIHandlerApp preferredApplicationHandler; */
NS_IMETHODIMP nsHandlerInfo::GetPreferredApplicationHandler(nsIHandlerApp * *aPreferredApplicationHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHandlerInfo::SetPreferredApplicationHandler(nsIHandlerApp * aPreferredApplicationHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMutableArray possibleApplicationHandlers; */
NS_IMETHODIMP nsHandlerInfo::GetPossibleApplicationHandlers(nsIMutableArray * *aPossibleApplicationHandlers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasDefaultHandler; */
NS_IMETHODIMP nsHandlerInfo::GetHasDefaultHandler(PRBool *aHasDefaultHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString defaultDescription; */
NS_IMETHODIMP nsHandlerInfo::GetDefaultDescription(nsAString & aDefaultDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void launchWithURI (in nsIURI aURI, [optional] in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsHandlerInfo::LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsHandlerInfoAction preferredAction; */
NS_IMETHODIMP nsHandlerInfo::GetPreferredAction(nsHandlerInfoAction *aPreferredAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHandlerInfo::SetPreferredAction(nsHandlerInfoAction aPreferredAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean alwaysAskBeforeHandling; */
NS_IMETHODIMP nsHandlerInfo::GetAlwaysAskBeforeHandling(PRBool *aAlwaysAskBeforeHandling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHandlerInfo::SetAlwaysAskBeforeHandling(PRBool aAlwaysAskBeforeHandling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMIMEInfo */
#define NS_IMIMEINFO_IID_STR "cd7083f8-5fe9-4248-bb09-0b0e2982fde8"

#define NS_IMIMEINFO_IID \
  {0xcd7083f8, 0x5fe9, 0x4248, \
    { 0xbb, 0x09, 0x0b, 0x0e, 0x29, 0x82, 0xfd, 0xe8 }}

/**
 * nsIMIMEInfo extends nsIHandlerInfo with a bunch of information specific to
 * MIME content-types. There is a one-to-many relationship between MIME types
 * and file extensions. This means that a MIMEInfo object may have multiple
 * file extensions associated with it.  However, the reverse is not true.
 *
 * MIMEInfo objects are generally retrieved from the MIME Service
 * @see nsIMIMEService
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIMIMEInfo : public nsIHandlerInfo {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMIMEINFO_IID)

  /**
     * Gives you an array of file types associated with this type.
     *
     * @return Number of elements in the array.
     * @return Array of extensions.
     */
  /* nsIUTF8StringEnumerator getFileExtensions (); */
  NS_SCRIPTABLE NS_IMETHOD GetFileExtensions(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Set File Extensions. Input is a comma delimited list of extensions.
     */
  /* void setFileExtensions (in AUTF8String aExtensions); */
  NS_SCRIPTABLE NS_IMETHOD SetFileExtensions(const nsACString & aExtensions) = 0;

  /**
     * Returns whether or not the given extension is
     * associated with this MIME info.
     *
     * @return TRUE if the association exists. 
     */
  /* boolean extensionExists (in AUTF8String aExtension); */
  NS_SCRIPTABLE NS_IMETHOD ExtensionExists(const nsACString & aExtension, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Append a given extension to the set of extensions
     */
  /* void appendExtension (in AUTF8String aExtension); */
  NS_SCRIPTABLE NS_IMETHOD AppendExtension(const nsACString & aExtension) = 0;

  /**
     * Returns the first extension association in
     * the internal set of extensions.
     *
     * @return The first extension.
     */
  /* attribute AUTF8String primaryExtension; */
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryExtension(nsACString & aPrimaryExtension) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrimaryExtension(const nsACString & aPrimaryExtension) = 0;

  /**
     * The MIME type of this MIMEInfo.
     * 
     * @return String representing the MIME type.
     * 
     * @deprecated  use nsIHandlerInfo::type instead.
     */
  /* readonly attribute ACString MIMEType; */
  NS_SCRIPTABLE NS_IMETHOD GetMIMEType(nsACString & aMIMEType) = 0;

  /**
     * Mac Type and creator types
     */
  /* attribute PRUint32 macType; */
  NS_SCRIPTABLE NS_IMETHOD GetMacType(PRUint32 *aMacType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMacType(PRUint32 aMacType) = 0;

  /* attribute PRUint32 macCreator; */
  NS_SCRIPTABLE NS_IMETHOD GetMacCreator(PRUint32 *aMacCreator) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMacCreator(PRUint32 aMacCreator) = 0;

  /**
     * Returns whether or not these two nsIMIMEInfos are logically
     * equivalent.
     *
     * @returns PR_TRUE if the two are considered equal
     */
  /* boolean equals (in nsIMIMEInfo aMIMEInfo); */
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMIMEInfo *aMIMEInfo, PRBool *_retval NS_OUTPARAM) = 0;

  /** 
     * Returns a list of nsILocalHandlerApp objects containing
     * handlers associated with this mimeinfo. Implemented per 
     * platform using information in this object to generate the
     * best list. Typically used for an "open with" style user 
     * option.
     * 
     * @return nsIArray of nsILocalHandlerApp
     */
  /* readonly attribute nsIArray possibleLocalHandlers; */
  NS_SCRIPTABLE NS_IMETHOD GetPossibleLocalHandlers(nsIArray * *aPossibleLocalHandlers) = 0;

  /**
     * Launches the application with the specified file, in a way that
     * depends on the value of preferredAction. preferredAction must be
     * useHelperApp or useSystemDefault.
     *
     * @param aFile The file to launch this application with.
     *
     * @throw NS_ERROR_INVALID_ARG if action is not valid for this function.
     * Other exceptions may be thrown.
     */
  /* void launchWithFile (in nsIFile aFile); */
  NS_SCRIPTABLE NS_IMETHOD LaunchWithFile(nsIFile *aFile) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMIMEInfo, NS_IMIMEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMIMEINFO \
  NS_SCRIPTABLE NS_IMETHOD GetFileExtensions(nsIUTF8StringEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetFileExtensions(const nsACString & aExtensions); \
  NS_SCRIPTABLE NS_IMETHOD ExtensionExists(const nsACString & aExtension, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AppendExtension(const nsACString & aExtension); \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryExtension(nsACString & aPrimaryExtension); \
  NS_SCRIPTABLE NS_IMETHOD SetPrimaryExtension(const nsACString & aPrimaryExtension); \
  NS_SCRIPTABLE NS_IMETHOD GetMIMEType(nsACString & aMIMEType); \
  NS_SCRIPTABLE NS_IMETHOD GetMacType(PRUint32 *aMacType); \
  NS_SCRIPTABLE NS_IMETHOD SetMacType(PRUint32 aMacType); \
  NS_SCRIPTABLE NS_IMETHOD GetMacCreator(PRUint32 *aMacCreator); \
  NS_SCRIPTABLE NS_IMETHOD SetMacCreator(PRUint32 aMacCreator); \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMIMEInfo *aMIMEInfo, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPossibleLocalHandlers(nsIArray * *aPossibleLocalHandlers); \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithFile(nsIFile *aFile); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMIMEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFileExtensions(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return _to GetFileExtensions(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFileExtensions(const nsACString & aExtensions) { return _to SetFileExtensions(aExtensions); } \
  NS_SCRIPTABLE NS_IMETHOD ExtensionExists(const nsACString & aExtension, PRBool *_retval NS_OUTPARAM) { return _to ExtensionExists(aExtension, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendExtension(const nsACString & aExtension) { return _to AppendExtension(aExtension); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryExtension(nsACString & aPrimaryExtension) { return _to GetPrimaryExtension(aPrimaryExtension); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrimaryExtension(const nsACString & aPrimaryExtension) { return _to SetPrimaryExtension(aPrimaryExtension); } \
  NS_SCRIPTABLE NS_IMETHOD GetMIMEType(nsACString & aMIMEType) { return _to GetMIMEType(aMIMEType); } \
  NS_SCRIPTABLE NS_IMETHOD GetMacType(PRUint32 *aMacType) { return _to GetMacType(aMacType); } \
  NS_SCRIPTABLE NS_IMETHOD SetMacType(PRUint32 aMacType) { return _to SetMacType(aMacType); } \
  NS_SCRIPTABLE NS_IMETHOD GetMacCreator(PRUint32 *aMacCreator) { return _to GetMacCreator(aMacCreator); } \
  NS_SCRIPTABLE NS_IMETHOD SetMacCreator(PRUint32 aMacCreator) { return _to SetMacCreator(aMacCreator); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMIMEInfo *aMIMEInfo, PRBool *_retval NS_OUTPARAM) { return _to Equals(aMIMEInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPossibleLocalHandlers(nsIArray * *aPossibleLocalHandlers) { return _to GetPossibleLocalHandlers(aPossibleLocalHandlers); } \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithFile(nsIFile *aFile) { return _to LaunchWithFile(aFile); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMIMEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFileExtensions(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileExtensions(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFileExtensions(const nsACString & aExtensions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFileExtensions(aExtensions); } \
  NS_SCRIPTABLE NS_IMETHOD ExtensionExists(const nsACString & aExtension, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtensionExists(aExtension, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendExtension(const nsACString & aExtension) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendExtension(aExtension); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryExtension(nsACString & aPrimaryExtension) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryExtension(aPrimaryExtension); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrimaryExtension(const nsACString & aPrimaryExtension) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrimaryExtension(aPrimaryExtension); } \
  NS_SCRIPTABLE NS_IMETHOD GetMIMEType(nsACString & aMIMEType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMEType(aMIMEType); } \
  NS_SCRIPTABLE NS_IMETHOD GetMacType(PRUint32 *aMacType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMacType(aMacType); } \
  NS_SCRIPTABLE NS_IMETHOD SetMacType(PRUint32 aMacType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMacType(aMacType); } \
  NS_SCRIPTABLE NS_IMETHOD GetMacCreator(PRUint32 *aMacCreator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMacCreator(aMacCreator); } \
  NS_SCRIPTABLE NS_IMETHOD SetMacCreator(PRUint32 aMacCreator) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMacCreator(aMacCreator); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMIMEInfo *aMIMEInfo, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(aMIMEInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPossibleLocalHandlers(nsIArray * *aPossibleLocalHandlers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPossibleLocalHandlers(aPossibleLocalHandlers); } \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithFile(nsIFile *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->LaunchWithFile(aFile); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMIMEInfo : public nsIMIMEInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMIMEINFO

  nsMIMEInfo();

private:
  ~nsMIMEInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMIMEInfo, nsIMIMEInfo)

nsMIMEInfo::nsMIMEInfo()
{
  /* member initializers and constructor code */
}

nsMIMEInfo::~nsMIMEInfo()
{
  /* destructor code */
}

/* nsIUTF8StringEnumerator getFileExtensions (); */
NS_IMETHODIMP nsMIMEInfo::GetFileExtensions(nsIUTF8StringEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFileExtensions (in AUTF8String aExtensions); */
NS_IMETHODIMP nsMIMEInfo::SetFileExtensions(const nsACString & aExtensions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean extensionExists (in AUTF8String aExtension); */
NS_IMETHODIMP nsMIMEInfo::ExtensionExists(const nsACString & aExtension, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendExtension (in AUTF8String aExtension); */
NS_IMETHODIMP nsMIMEInfo::AppendExtension(const nsACString & aExtension)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String primaryExtension; */
NS_IMETHODIMP nsMIMEInfo::GetPrimaryExtension(nsACString & aPrimaryExtension)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMIMEInfo::SetPrimaryExtension(const nsACString & aPrimaryExtension)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString MIMEType; */
NS_IMETHODIMP nsMIMEInfo::GetMIMEType(nsACString & aMIMEType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRUint32 macType; */
NS_IMETHODIMP nsMIMEInfo::GetMacType(PRUint32 *aMacType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMIMEInfo::SetMacType(PRUint32 aMacType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRUint32 macCreator; */
NS_IMETHODIMP nsMIMEInfo::GetMacCreator(PRUint32 *aMacCreator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMIMEInfo::SetMacCreator(PRUint32 aMacCreator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIMIMEInfo aMIMEInfo); */
NS_IMETHODIMP nsMIMEInfo::Equals(nsIMIMEInfo *aMIMEInfo, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray possibleLocalHandlers; */
NS_IMETHODIMP nsMIMEInfo::GetPossibleLocalHandlers(nsIArray * *aPossibleLocalHandlers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void launchWithFile (in nsIFile aFile); */
NS_IMETHODIMP nsMIMEInfo::LaunchWithFile(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHandlerApp */
#define NS_IHANDLERAPP_IID_STR "8d298761-0963-4c90-99e2-6ea498825e82"

#define NS_IHANDLERAPP_IID \
  {0x8d298761, 0x0963, 0x4c90, \
    { 0x99, 0xe2, 0x6e, 0xa4, 0x98, 0x82, 0x5e, 0x82 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIHandlerApp : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHANDLERAPP_IID)

  /**
 * nsIHandlerApp represents an external application that can handle content
 * of some sort (either a MIME type or a protocol).
 *
 * FIXME: now that we've made nsIWebHandlerApp inherit from nsIHandlerApp,
 * we should also try to make nsIWebContentHandlerInfo inherit from or possibly
 * be replaced by nsIWebHandlerApp (bug 394710).
 */
/**
     * Human readable name for the handler
     */
  /* attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) = 0;

  /**
     * Whether or not the given handler app is logically equivalent to the
     * invokant (i.e. they represent the same app).
     * 
     * Two apps are the same if they are both either local or web handlers
     * and their executables/URI templates are the same in a string comparison.
     *
     * @param aHandlerApp the handler app to compare to the invokant
     *
     * @returns true if the two are logically equivalent, false otherwise
     */
  /* boolean equals (in nsIHandlerApp aHandlerApp); */
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIHandlerApp *aHandlerApp, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Launches the application with the specified URI.
     *
     * @param aURI
     *        The URI to launch this application with
     *
     * @param aWindowContext 
     *
     *        Currently only relevant to web-handler apps.  If given, this
     *        represents the docshell to load the handler in and is passed
     *        through to nsIURILoader.openURI.  If this parameter is null or
     *        not present, the web handler app implementation will attempt to 
     *        find/create a place to load the handler and do so.  As of this
     *        writing, it tries to load the web handler in a new window using
     *        nsIBrowserDOMWindow.openURI.  In the future, it may attempt to 
     *        have a more comprehensive strategy which could include handing
     *        off to the system default browser (bug 394479).
     */
  /* void launchWithURI (in nsIURI aURI, [optional] in nsIInterfaceRequestor aWindowContext); */
  NS_SCRIPTABLE NS_IMETHOD LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHandlerApp, NS_IHANDLERAPP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHANDLERAPP \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIHandlerApp *aHandlerApp, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIHandlerApp *aHandlerApp, PRBool *_retval NS_OUTPARAM) { return _to Equals(aHandlerApp, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) { return _to LaunchWithURI(aURI, aWindowContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIHandlerApp *aHandlerApp, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(aHandlerApp, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->LaunchWithURI(aURI, aWindowContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHandlerApp : public nsIHandlerApp
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHANDLERAPP

  nsHandlerApp();

private:
  ~nsHandlerApp();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHandlerApp, nsIHandlerApp)

nsHandlerApp::nsHandlerApp()
{
  /* member initializers and constructor code */
}

nsHandlerApp::~nsHandlerApp()
{
  /* destructor code */
}

/* attribute AString name; */
NS_IMETHODIMP nsHandlerApp::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHandlerApp::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIHandlerApp aHandlerApp); */
NS_IMETHODIMP nsHandlerApp::Equals(nsIHandlerApp *aHandlerApp, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void launchWithURI (in nsIURI aURI, [optional] in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsHandlerApp::LaunchWithURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsILocalHandlerApp */
#define NS_ILOCALHANDLERAPP_IID_STR "9812be73-273c-478c-8170-c3e0db08ae7c"

#define NS_ILOCALHANDLERAPP_IID \
  {0x9812be73, 0x273c, 0x478c, \
    { 0x81, 0x70, 0xc3, 0xe0, 0xdb, 0x08, 0xae, 0x7c }}

/**
 * nsILocalHandlerApp is a local OS-level executable
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsILocalHandlerApp : public nsIHandlerApp {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALHANDLERAPP_IID)

  /**
     * Pointer to the executable file used to handle content
     */
  /* attribute nsIFile executable; */
  NS_SCRIPTABLE NS_IMETHOD GetExecutable(nsIFile * *aExecutable) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExecutable(nsIFile * aExecutable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalHandlerApp, NS_ILOCALHANDLERAPP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALHANDLERAPP \
  NS_SCRIPTABLE NS_IMETHOD GetExecutable(nsIFile * *aExecutable); \
  NS_SCRIPTABLE NS_IMETHOD SetExecutable(nsIFile * aExecutable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetExecutable(nsIFile * *aExecutable) { return _to GetExecutable(aExecutable); } \
  NS_SCRIPTABLE NS_IMETHOD SetExecutable(nsIFile * aExecutable) { return _to SetExecutable(aExecutable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetExecutable(nsIFile * *aExecutable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExecutable(aExecutable); } \
  NS_SCRIPTABLE NS_IMETHOD SetExecutable(nsIFile * aExecutable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExecutable(aExecutable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalHandlerApp : public nsILocalHandlerApp
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALHANDLERAPP

  nsLocalHandlerApp();

private:
  ~nsLocalHandlerApp();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLocalHandlerApp, nsILocalHandlerApp)

nsLocalHandlerApp::nsLocalHandlerApp()
{
  /* member initializers and constructor code */
}

nsLocalHandlerApp::~nsLocalHandlerApp()
{
  /* destructor code */
}

/* attribute nsIFile executable; */
NS_IMETHODIMP nsLocalHandlerApp::GetExecutable(nsIFile * *aExecutable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLocalHandlerApp::SetExecutable(nsIFile * aExecutable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebHandlerApp */
#define NS_IWEBHANDLERAPP_IID_STR "7521a093-c498-45ce-b462-df7ba0d882f6"

#define NS_IWEBHANDLERAPP_IID \
  {0x7521a093, 0xc498, 0x45ce, \
    { 0xb4, 0x62, 0xdf, 0x7b, 0xa0, 0xd8, 0x82, 0xf6 }}

/**
 * nsIWebHandlerApp is a web-based handler, as speced by the WhatWG HTML5
 * draft.  Currently, only GET-based handlers are supported.  At some point, 
 * we probably want to work with WhatWG to spec out and implement POST-based
 * handlers as well.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWebHandlerApp : public nsIHandlerApp {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBHANDLERAPP_IID)

  /**
     * Template used to construct the URI to GET.  Template is expected to have
     * a %s in it, and the escaped URI to be handled is inserted in place of 
     * that %s, as per the HTML5 spec.
     */
  /* attribute AUTF8String uriTemplate; */
  NS_SCRIPTABLE NS_IMETHOD GetUriTemplate(nsACString & aUriTemplate) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUriTemplate(const nsACString & aUriTemplate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebHandlerApp, NS_IWEBHANDLERAPP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBHANDLERAPP \
  NS_SCRIPTABLE NS_IMETHOD GetUriTemplate(nsACString & aUriTemplate); \
  NS_SCRIPTABLE NS_IMETHOD SetUriTemplate(const nsACString & aUriTemplate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUriTemplate(nsACString & aUriTemplate) { return _to GetUriTemplate(aUriTemplate); } \
  NS_SCRIPTABLE NS_IMETHOD SetUriTemplate(const nsACString & aUriTemplate) { return _to SetUriTemplate(aUriTemplate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUriTemplate(nsACString & aUriTemplate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUriTemplate(aUriTemplate); } \
  NS_SCRIPTABLE NS_IMETHOD SetUriTemplate(const nsACString & aUriTemplate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUriTemplate(aUriTemplate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebHandlerApp : public nsIWebHandlerApp
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBHANDLERAPP

  nsWebHandlerApp();

private:
  ~nsWebHandlerApp();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebHandlerApp, nsIWebHandlerApp)

nsWebHandlerApp::nsWebHandlerApp()
{
  /* member initializers and constructor code */
}

nsWebHandlerApp::~nsWebHandlerApp()
{
  /* destructor code */
}

/* attribute AUTF8String uriTemplate; */
NS_IMETHODIMP nsWebHandlerApp::GetUriTemplate(nsACString & aUriTemplate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebHandlerApp::SetUriTemplate(const nsACString & aUriTemplate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDBusHandlerApp */
#define NS_IDBUSHANDLERAPP_IID_STR "1ffc274b-4cbf-4bb5-a635-05ad2cbb6534"

#define NS_IDBUSHANDLERAPP_IID \
  {0x1ffc274b, 0x4cbf, 0x4bb5, \
    { 0xa6, 0x35, 0x05, 0xad, 0x2c, 0xbb, 0x65, 0x34 }}

/**
 * nsIDBusHandlerApp represents local applications launched by DBus a message
 * invoking a method taking a single string argument descibing a URI
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDBusHandlerApp : public nsIHandlerApp {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDBUSHANDLERAPP_IID)

  /**
     * Service defines the dbus service that should handle this protocol.
     * If its not set,  NS_ERROR_FAILURE will be returned by LaunchWithURI
     */
  /* attribute AUTF8String service; */
  NS_SCRIPTABLE NS_IMETHOD GetService(nsACString & aService) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetService(const nsACString & aService) = 0;

  /**
     * Objpath defines the object path of the dbus service that should handle 
     * this protocol. If its not set,  NS_ERROR_FAILURE will be returned 
     * by LaunchWithURI
     */
  /* attribute AUTF8String objectPath; */
  NS_SCRIPTABLE NS_IMETHOD GetObjectPath(nsACString & aObjectPath) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetObjectPath(const nsACString & aObjectPath) = 0;

  /**
     * DBusInterface defines the interface of the dbus service that should 
     * handle this protocol. If its not set,  NS_ERROR_FAILURE will be  
     * returned by LaunchWithURI
     */
  /* attribute AUTF8String dBusInterface; */
  NS_SCRIPTABLE NS_IMETHOD GetDBusInterface(nsACString & aDBusInterface) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDBusInterface(const nsACString & aDBusInterface) = 0;

  /**
     * Method defines the dbus method that should be invoked to handle this 
     * protocol. If its not set,  NS_ERROR_FAILURE will be returned by 
     * LaunchWithURI
     */
  /* attribute AUTF8String method; */
  NS_SCRIPTABLE NS_IMETHOD GetMethod(nsACString & aMethod) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMethod(const nsACString & aMethod) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDBusHandlerApp, NS_IDBUSHANDLERAPP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDBUSHANDLERAPP \
  NS_SCRIPTABLE NS_IMETHOD GetService(nsACString & aService); \
  NS_SCRIPTABLE NS_IMETHOD SetService(const nsACString & aService); \
  NS_SCRIPTABLE NS_IMETHOD GetObjectPath(nsACString & aObjectPath); \
  NS_SCRIPTABLE NS_IMETHOD SetObjectPath(const nsACString & aObjectPath); \
  NS_SCRIPTABLE NS_IMETHOD GetDBusInterface(nsACString & aDBusInterface); \
  NS_SCRIPTABLE NS_IMETHOD SetDBusInterface(const nsACString & aDBusInterface); \
  NS_SCRIPTABLE NS_IMETHOD GetMethod(nsACString & aMethod); \
  NS_SCRIPTABLE NS_IMETHOD SetMethod(const nsACString & aMethod); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDBUSHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetService(nsACString & aService) { return _to GetService(aService); } \
  NS_SCRIPTABLE NS_IMETHOD SetService(const nsACString & aService) { return _to SetService(aService); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectPath(nsACString & aObjectPath) { return _to GetObjectPath(aObjectPath); } \
  NS_SCRIPTABLE NS_IMETHOD SetObjectPath(const nsACString & aObjectPath) { return _to SetObjectPath(aObjectPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBusInterface(nsACString & aDBusInterface) { return _to GetDBusInterface(aDBusInterface); } \
  NS_SCRIPTABLE NS_IMETHOD SetDBusInterface(const nsACString & aDBusInterface) { return _to SetDBusInterface(aDBusInterface); } \
  NS_SCRIPTABLE NS_IMETHOD GetMethod(nsACString & aMethod) { return _to GetMethod(aMethod); } \
  NS_SCRIPTABLE NS_IMETHOD SetMethod(const nsACString & aMethod) { return _to SetMethod(aMethod); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDBUSHANDLERAPP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetService(nsACString & aService) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetService(aService); } \
  NS_SCRIPTABLE NS_IMETHOD SetService(const nsACString & aService) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetService(aService); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectPath(nsACString & aObjectPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectPath(aObjectPath); } \
  NS_SCRIPTABLE NS_IMETHOD SetObjectPath(const nsACString & aObjectPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObjectPath(aObjectPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBusInterface(nsACString & aDBusInterface) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBusInterface(aDBusInterface); } \
  NS_SCRIPTABLE NS_IMETHOD SetDBusInterface(const nsACString & aDBusInterface) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDBusInterface(aDBusInterface); } \
  NS_SCRIPTABLE NS_IMETHOD GetMethod(nsACString & aMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMethod(aMethod); } \
  NS_SCRIPTABLE NS_IMETHOD SetMethod(const nsACString & aMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMethod(aMethod); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDBusHandlerApp : public nsIDBusHandlerApp
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDBUSHANDLERAPP

  nsDBusHandlerApp();

private:
  ~nsDBusHandlerApp();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDBusHandlerApp, nsIDBusHandlerApp)

nsDBusHandlerApp::nsDBusHandlerApp()
{
  /* member initializers and constructor code */
}

nsDBusHandlerApp::~nsDBusHandlerApp()
{
  /* destructor code */
}

/* attribute AUTF8String service; */
NS_IMETHODIMP nsDBusHandlerApp::GetService(nsACString & aService)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDBusHandlerApp::SetService(const nsACString & aService)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String objectPath; */
NS_IMETHODIMP nsDBusHandlerApp::GetObjectPath(nsACString & aObjectPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDBusHandlerApp::SetObjectPath(const nsACString & aObjectPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String dBusInterface; */
NS_IMETHODIMP nsDBusHandlerApp::GetDBusInterface(nsACString & aDBusInterface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDBusHandlerApp::SetDBusInterface(const nsACString & aDBusInterface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String method; */
NS_IMETHODIMP nsDBusHandlerApp::GetMethod(nsACString & aMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDBusHandlerApp::SetMethod(const nsACString & aMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMIMEInfo_h__ */
