/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/mozapps/update/public/nsIUpdateService.idl
 */

#ifndef __gen_nsIUpdateService_h__
#define __gen_nsIUpdateService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsIRequestObserver; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsITimerCallback; /* forward declaration */

class nsIXMLHttpRequest; /* forward declaration */


/* starting interface:    nsIUpdatePatch */
#define NS_IUPDATEPATCH_IID_STR "56863a67-bd69-42de-9f40-583e625b457d"

#define NS_IUPDATEPATCH_IID \
  {0x56863a67, 0xbd69, 0x42de, \
    { 0x9f, 0x40, 0x58, 0x3e, 0x62, 0x5b, 0x45, 0x7d }}

/**
 * An interface that describes an object representing a patch file that can
 * be downloaded and applied to a version of this application so that it
 * can be updated.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIUpdatePatch : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATEPATCH_IID)

  /**
   * The type of this patch:
   * "partial"      A binary difference between two application versions
   * "complete"     A complete patch containing all of the replacement files
   *                to update to the new version
   */
  /* attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

  /**
   * The URL this patch was being downloaded from
   */
  /* attribute AString URL; */
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetURL(const nsAString & aURL) = 0;

  /**
   * The hash function to use when determining this file's integrity
   */
  /* attribute AString hashFunction; */
  NS_SCRIPTABLE NS_IMETHOD GetHashFunction(nsAString & aHashFunction) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHashFunction(const nsAString & aHashFunction) = 0;

  /**
   * The value of the hash function named above that should be computed if
   * this file is not corrupt.
   */
  /* attribute AString hashValue; */
  NS_SCRIPTABLE NS_IMETHOD GetHashValue(nsAString & aHashValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHashValue(const nsAString & aHashValue) = 0;

  /**
   * The size of this file, in bytes.
   */
  /* attribute unsigned long size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRUint32 aSize) = 0;

  /**
   * The state of this patch
   */
  /* attribute AString state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(nsAString & aState) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetState(const nsAString & aState) = 0;

  /**
   * true if this patch is currently selected as the patch to be downloaded and
   * installed for this update transaction, false if another patch from this
   * update has been selected.
   */
  /* attribute boolean selected; */
  NS_SCRIPTABLE NS_IMETHOD GetSelected(PRBool *aSelected) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelected(PRBool aSelected) = 0;

  /**
   * Serializes this patch object into a DOM Element
   * @param   updates
   *          The document to serialize into
   * @returns The DOM Element created by the serialization process
   */
  /* nsIDOMElement serialize (in nsIDOMDocument updates); */
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdatePatch, NS_IUPDATEPATCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATEPATCH \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD SetURL(const nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD GetHashFunction(nsAString & aHashFunction); \
  NS_SCRIPTABLE NS_IMETHOD SetHashFunction(const nsAString & aHashFunction); \
  NS_SCRIPTABLE NS_IMETHOD GetHashValue(nsAString & aHashValue); \
  NS_SCRIPTABLE NS_IMETHOD SetHashValue(const nsAString & aHashValue); \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize); \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRUint32 aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsAString & aState); \
  NS_SCRIPTABLE NS_IMETHOD SetState(const nsAString & aState); \
  NS_SCRIPTABLE NS_IMETHOD GetSelected(PRBool *aSelected); \
  NS_SCRIPTABLE NS_IMETHOD SetSelected(PRBool aSelected); \
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATEPATCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) { return _to GetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetURL(const nsAString & aURL) { return _to SetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetHashFunction(nsAString & aHashFunction) { return _to GetHashFunction(aHashFunction); } \
  NS_SCRIPTABLE NS_IMETHOD SetHashFunction(const nsAString & aHashFunction) { return _to SetHashFunction(aHashFunction); } \
  NS_SCRIPTABLE NS_IMETHOD GetHashValue(nsAString & aHashValue) { return _to GetHashValue(aHashValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetHashValue(const nsAString & aHashValue) { return _to SetHashValue(aHashValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRUint32 aSize) { return _to SetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsAString & aState) { return _to GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD SetState(const nsAString & aState) { return _to SetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelected(PRBool *aSelected) { return _to GetSelected(aSelected); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelected(PRBool aSelected) { return _to SetSelected(aSelected); } \
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM) { return _to Serialize(updates, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATEPATCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetURL(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetHashFunction(nsAString & aHashFunction) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHashFunction(aHashFunction); } \
  NS_SCRIPTABLE NS_IMETHOD SetHashFunction(const nsAString & aHashFunction) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHashFunction(aHashFunction); } \
  NS_SCRIPTABLE NS_IMETHOD GetHashValue(nsAString & aHashValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHashValue(aHashValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetHashValue(const nsAString & aHashValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHashValue(aHashValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRUint32 aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsAString & aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD SetState(const nsAString & aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelected(PRBool *aSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelected(aSelected); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelected(PRBool aSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelected(aSelected); } \
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Serialize(updates, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdatePatch : public nsIUpdatePatch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATEPATCH

  nsUpdatePatch();

private:
  ~nsUpdatePatch();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdatePatch, nsIUpdatePatch)

nsUpdatePatch::nsUpdatePatch()
{
  /* member initializers and constructor code */
}

nsUpdatePatch::~nsUpdatePatch()
{
  /* destructor code */
}

/* attribute AString type; */
NS_IMETHODIMP nsUpdatePatch::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString URL; */
NS_IMETHODIMP nsUpdatePatch::GetURL(nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetURL(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString hashFunction; */
NS_IMETHODIMP nsUpdatePatch::GetHashFunction(nsAString & aHashFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetHashFunction(const nsAString & aHashFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString hashValue; */
NS_IMETHODIMP nsUpdatePatch::GetHashValue(nsAString & aHashValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetHashValue(const nsAString & aHashValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long size; */
NS_IMETHODIMP nsUpdatePatch::GetSize(PRUint32 *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetSize(PRUint32 aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString state; */
NS_IMETHODIMP nsUpdatePatch::GetState(nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetState(const nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean selected; */
NS_IMETHODIMP nsUpdatePatch::GetSelected(PRBool *aSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetSelected(PRBool aSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement serialize (in nsIDOMDocument updates); */
NS_IMETHODIMP nsUpdatePatch::Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdate */
#define NS_IUPDATE_IID_STR "9d6a388b-2e0c-4d0e-9a60-5c9739a7ada5"

#define NS_IUPDATE_IID \
  {0x9d6a388b, 0x2e0c, 0x4d0e, \
    { 0x9a, 0x60, 0x5c, 0x97, 0x39, 0xa7, 0xad, 0xa5 }}

/**
 * An interface that describes an object representing an available update to
 * the current application - this update may have several available patches
 * from which one must be selected to download and install, for example we
 * might select a binary difference patch first and attempt to apply that,
 * then if the application process fails fall back to downloading a complete
 * file-replace patch. This object also contains information about the update
 * that the front end and other application services can use to learn more
 * about what is going on.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIUpdate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATE_IID)

  /**
   * The type of update:
   *   "major"  A major new version of the Application
   *   "minor"  A minor update to the Application (e.g. security update)
   */
  /* attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

  /**
   * The name of the update, or "<Application Name> <Update Version>"
   */
  /* attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) = 0;

  /**
   * The Application version of this update.
   */
  /* attribute AString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & aVersion) = 0;

  /**
   * The Toolkit version of this update.
   */
  /* attribute AString platformVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPlatformVersion(const nsAString & aPlatformVersion) = 0;

  /**
   * The Addon version of this update. Used by the Extension System to track
   * compatibility of installed addons with this update.
   */
  /* attribute AString extensionVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetExtensionVersion(nsAString & aExtensionVersion) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExtensionVersion(const nsAString & aExtensionVersion) = 0;

  /**
   * The Build ID of this update. Used to determine a particular build, down
   * to the hour, minute and second of its creation. This allows the system
   * to differentiate between several nightly builds with the same |version|
   * for example.
   */
  /* attribute AString buildID; */
  NS_SCRIPTABLE NS_IMETHOD GetBuildID(nsAString & aBuildID) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBuildID(const nsAString & aBuildID) = 0;

  /**
   * The URL to a page which offers details about the content of this
   * update. Ideally, this page is not the release notes but some other page
   * that summarizes the differences between this update and the previous,
   * which also links to the release notes.
   */
  /* attribute AString detailsURL; */
  NS_SCRIPTABLE NS_IMETHOD GetDetailsURL(nsAString & aDetailsURL) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDetailsURL(const nsAString & aDetailsURL) = 0;

  /**
   * The URL to a HTML fragment that contains a license for this update. If
   * this is specified, the user is shown the license file after they choose
   * to install the update and they must agree to it before the download
   * commences.
   */
  /* attribute AString licenseURL; */
  NS_SCRIPTABLE NS_IMETHOD GetLicenseURL(nsAString & aLicenseURL) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLicenseURL(const nsAString & aLicenseURL) = 0;

  /**
   * The URL to the Update Service that supplied this update.
   */
  /* attribute AString serviceURL; */
  NS_SCRIPTABLE NS_IMETHOD GetServiceURL(nsAString & aServiceURL) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetServiceURL(const nsAString & aServiceURL) = 0;

  /**
   * The channel used to retrieve this update from the Update Service.
   */
  /* attribute AString channel; */
  NS_SCRIPTABLE NS_IMETHOD GetChannel(nsAString & aChannel) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetChannel(const nsAString & aChannel) = 0;

  /**
   * Whether or not the update being downloaded is a complete replacement of
   * the user's existing installation or a patch representing the difference
   * between the new version and the previous version.
   */
  /* attribute boolean isCompleteUpdate; */
  NS_SCRIPTABLE NS_IMETHOD GetIsCompleteUpdate(PRBool *aIsCompleteUpdate) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIsCompleteUpdate(PRBool aIsCompleteUpdate) = 0;

  /**
   * Whether or not the update is a security update or not. If this is true,
   * then we present more serious sounding user interface messages to the
   * user.
   */
  /* attribute boolean isSecurityUpdate; */
  NS_SCRIPTABLE NS_IMETHOD GetIsSecurityUpdate(PRBool *aIsSecurityUpdate) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIsSecurityUpdate(PRBool aIsSecurityUpdate) = 0;

  /**
   * When the update was installed.
   */
  /* attribute long long installDate; */
  NS_SCRIPTABLE NS_IMETHOD GetInstallDate(PRInt64 *aInstallDate) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInstallDate(PRInt64 aInstallDate) = 0;

  /**
   * A message associated with this update, if any.
   */
  /* attribute AString statusText; */
  NS_SCRIPTABLE NS_IMETHOD GetStatusText(nsAString & aStatusText) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStatusText(const nsAString & aStatusText) = 0;

  /**
   * The currently selected patch for this update.
   */
  /* readonly attribute nsIUpdatePatch selectedPatch; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch) = 0;

  /**
   * The state of the selected patch:
   *   "downloading"       The update is being downloaded.
   *   "pending"           The update is ready to be applied.
   *   "applying"          The update is being applied.
   *   "succeeded"         The update was successfully applied.
   *   "download-failed"   The update failed to be downloaded.
   *   "failed"            The update failed to be applied.
   */
  /* attribute AString state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(nsAString & aState) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetState(const nsAString & aState) = 0;

  /**
   * A numeric error code that conveys additional information about the state
   * of a failed update.  If the update is not in the "failed" state, then this
   * value is zero.
   *
   * TODO: Define typical error codes (for now, see updater/errors.h)
   */
  /* attribute long errorCode; */
  NS_SCRIPTABLE NS_IMETHOD GetErrorCode(PRInt32 *aErrorCode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetErrorCode(PRInt32 aErrorCode) = 0;

  /**
   * The number of patches supplied by this update.
   */
  /* readonly attribute unsigned long patchCount; */
  NS_SCRIPTABLE NS_IMETHOD GetPatchCount(PRUint32 *aPatchCount) = 0;

  /**
   * Retrieves a patch.
   * @param   index
   *          The index of the patch to retrieve.
   * @returns The nsIUpdatePatch at the specified index.
   */
  /* nsIUpdatePatch getPatchAt (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetPatchAt(PRUint32 index, nsIUpdatePatch **_retval NS_OUTPARAM) = 0;

  /**
   * Serializes this update object into a DOM Element
   * @param   updates
   *          The document to serialize into
   * @returns The DOM Element created by the serialization process
   */
  /* nsIDOMElement serialize (in nsIDOMDocument updates); */
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdate, NS_IUPDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATE \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion); \
  NS_SCRIPTABLE NS_IMETHOD SetPlatformVersion(const nsAString & aPlatformVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetExtensionVersion(nsAString & aExtensionVersion); \
  NS_SCRIPTABLE NS_IMETHOD SetExtensionVersion(const nsAString & aExtensionVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetBuildID(nsAString & aBuildID); \
  NS_SCRIPTABLE NS_IMETHOD SetBuildID(const nsAString & aBuildID); \
  NS_SCRIPTABLE NS_IMETHOD GetDetailsURL(nsAString & aDetailsURL); \
  NS_SCRIPTABLE NS_IMETHOD SetDetailsURL(const nsAString & aDetailsURL); \
  NS_SCRIPTABLE NS_IMETHOD GetLicenseURL(nsAString & aLicenseURL); \
  NS_SCRIPTABLE NS_IMETHOD SetLicenseURL(const nsAString & aLicenseURL); \
  NS_SCRIPTABLE NS_IMETHOD GetServiceURL(nsAString & aServiceURL); \
  NS_SCRIPTABLE NS_IMETHOD SetServiceURL(const nsAString & aServiceURL); \
  NS_SCRIPTABLE NS_IMETHOD GetChannel(nsAString & aChannel); \
  NS_SCRIPTABLE NS_IMETHOD SetChannel(const nsAString & aChannel); \
  NS_SCRIPTABLE NS_IMETHOD GetIsCompleteUpdate(PRBool *aIsCompleteUpdate); \
  NS_SCRIPTABLE NS_IMETHOD SetIsCompleteUpdate(PRBool aIsCompleteUpdate); \
  NS_SCRIPTABLE NS_IMETHOD GetIsSecurityUpdate(PRBool *aIsSecurityUpdate); \
  NS_SCRIPTABLE NS_IMETHOD SetIsSecurityUpdate(PRBool aIsSecurityUpdate); \
  NS_SCRIPTABLE NS_IMETHOD GetInstallDate(PRInt64 *aInstallDate); \
  NS_SCRIPTABLE NS_IMETHOD SetInstallDate(PRInt64 aInstallDate); \
  NS_SCRIPTABLE NS_IMETHOD GetStatusText(nsAString & aStatusText); \
  NS_SCRIPTABLE NS_IMETHOD SetStatusText(const nsAString & aStatusText); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch); \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsAString & aState); \
  NS_SCRIPTABLE NS_IMETHOD SetState(const nsAString & aState); \
  NS_SCRIPTABLE NS_IMETHOD GetErrorCode(PRInt32 *aErrorCode); \
  NS_SCRIPTABLE NS_IMETHOD SetErrorCode(PRInt32 aErrorCode); \
  NS_SCRIPTABLE NS_IMETHOD GetPatchCount(PRUint32 *aPatchCount); \
  NS_SCRIPTABLE NS_IMETHOD GetPatchAt(PRUint32 index, nsIUpdatePatch **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & aVersion) { return _to SetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) { return _to GetPlatformVersion(aPlatformVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetPlatformVersion(const nsAString & aPlatformVersion) { return _to SetPlatformVersion(aPlatformVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetExtensionVersion(nsAString & aExtensionVersion) { return _to GetExtensionVersion(aExtensionVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetExtensionVersion(const nsAString & aExtensionVersion) { return _to SetExtensionVersion(aExtensionVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetBuildID(nsAString & aBuildID) { return _to GetBuildID(aBuildID); } \
  NS_SCRIPTABLE NS_IMETHOD SetBuildID(const nsAString & aBuildID) { return _to SetBuildID(aBuildID); } \
  NS_SCRIPTABLE NS_IMETHOD GetDetailsURL(nsAString & aDetailsURL) { return _to GetDetailsURL(aDetailsURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetDetailsURL(const nsAString & aDetailsURL) { return _to SetDetailsURL(aDetailsURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetLicenseURL(nsAString & aLicenseURL) { return _to GetLicenseURL(aLicenseURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetLicenseURL(const nsAString & aLicenseURL) { return _to SetLicenseURL(aLicenseURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetServiceURL(nsAString & aServiceURL) { return _to GetServiceURL(aServiceURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetServiceURL(const nsAString & aServiceURL) { return _to SetServiceURL(aServiceURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetChannel(nsAString & aChannel) { return _to GetChannel(aChannel); } \
  NS_SCRIPTABLE NS_IMETHOD SetChannel(const nsAString & aChannel) { return _to SetChannel(aChannel); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsCompleteUpdate(PRBool *aIsCompleteUpdate) { return _to GetIsCompleteUpdate(aIsCompleteUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsCompleteUpdate(PRBool aIsCompleteUpdate) { return _to SetIsCompleteUpdate(aIsCompleteUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSecurityUpdate(PRBool *aIsSecurityUpdate) { return _to GetIsSecurityUpdate(aIsSecurityUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsSecurityUpdate(PRBool aIsSecurityUpdate) { return _to SetIsSecurityUpdate(aIsSecurityUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstallDate(PRInt64 *aInstallDate) { return _to GetInstallDate(aInstallDate); } \
  NS_SCRIPTABLE NS_IMETHOD SetInstallDate(PRInt64 aInstallDate) { return _to SetInstallDate(aInstallDate); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatusText(nsAString & aStatusText) { return _to GetStatusText(aStatusText); } \
  NS_SCRIPTABLE NS_IMETHOD SetStatusText(const nsAString & aStatusText) { return _to SetStatusText(aStatusText); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch) { return _to GetSelectedPatch(aSelectedPatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsAString & aState) { return _to GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD SetState(const nsAString & aState) { return _to SetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorCode(PRInt32 *aErrorCode) { return _to GetErrorCode(aErrorCode); } \
  NS_SCRIPTABLE NS_IMETHOD SetErrorCode(PRInt32 aErrorCode) { return _to SetErrorCode(aErrorCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatchCount(PRUint32 *aPatchCount) { return _to GetPatchCount(aPatchCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatchAt(PRUint32 index, nsIUpdatePatch **_retval NS_OUTPARAM) { return _to GetPatchAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM) { return _to Serialize(updates, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatformVersion(aPlatformVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetPlatformVersion(const nsAString & aPlatformVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPlatformVersion(aPlatformVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetExtensionVersion(nsAString & aExtensionVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExtensionVersion(aExtensionVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetExtensionVersion(const nsAString & aExtensionVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExtensionVersion(aExtensionVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetBuildID(nsAString & aBuildID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuildID(aBuildID); } \
  NS_SCRIPTABLE NS_IMETHOD SetBuildID(const nsAString & aBuildID) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBuildID(aBuildID); } \
  NS_SCRIPTABLE NS_IMETHOD GetDetailsURL(nsAString & aDetailsURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDetailsURL(aDetailsURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetDetailsURL(const nsAString & aDetailsURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDetailsURL(aDetailsURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetLicenseURL(nsAString & aLicenseURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLicenseURL(aLicenseURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetLicenseURL(const nsAString & aLicenseURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLicenseURL(aLicenseURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetServiceURL(nsAString & aServiceURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceURL(aServiceURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetServiceURL(const nsAString & aServiceURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetServiceURL(aServiceURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetChannel(nsAString & aChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannel(aChannel); } \
  NS_SCRIPTABLE NS_IMETHOD SetChannel(const nsAString & aChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChannel(aChannel); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsCompleteUpdate(PRBool *aIsCompleteUpdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsCompleteUpdate(aIsCompleteUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsCompleteUpdate(PRBool aIsCompleteUpdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsCompleteUpdate(aIsCompleteUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSecurityUpdate(PRBool *aIsSecurityUpdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSecurityUpdate(aIsSecurityUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsSecurityUpdate(PRBool aIsSecurityUpdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsSecurityUpdate(aIsSecurityUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstallDate(PRInt64 *aInstallDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstallDate(aInstallDate); } \
  NS_SCRIPTABLE NS_IMETHOD SetInstallDate(PRInt64 aInstallDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInstallDate(aInstallDate); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatusText(nsAString & aStatusText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatusText(aStatusText); } \
  NS_SCRIPTABLE NS_IMETHOD SetStatusText(const nsAString & aStatusText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStatusText(aStatusText); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedPatch(aSelectedPatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsAString & aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD SetState(const nsAString & aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorCode(PRInt32 *aErrorCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorCode(aErrorCode); } \
  NS_SCRIPTABLE NS_IMETHOD SetErrorCode(PRInt32 aErrorCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetErrorCode(aErrorCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatchCount(PRUint32 *aPatchCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPatchCount(aPatchCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatchAt(PRUint32 index, nsIUpdatePatch **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPatchAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Serialize(updates, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdate : public nsIUpdate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATE

  nsUpdate();

private:
  ~nsUpdate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdate, nsIUpdate)

nsUpdate::nsUpdate()
{
  /* member initializers and constructor code */
}

nsUpdate::~nsUpdate()
{
  /* destructor code */
}

/* attribute AString type; */
NS_IMETHODIMP nsUpdate::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString name; */
NS_IMETHODIMP nsUpdate::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString version; */
NS_IMETHODIMP nsUpdate::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetVersion(const nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString platformVersion; */
NS_IMETHODIMP nsUpdate::GetPlatformVersion(nsAString & aPlatformVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetPlatformVersion(const nsAString & aPlatformVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString extensionVersion; */
NS_IMETHODIMP nsUpdate::GetExtensionVersion(nsAString & aExtensionVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetExtensionVersion(const nsAString & aExtensionVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString buildID; */
NS_IMETHODIMP nsUpdate::GetBuildID(nsAString & aBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetBuildID(const nsAString & aBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString detailsURL; */
NS_IMETHODIMP nsUpdate::GetDetailsURL(nsAString & aDetailsURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetDetailsURL(const nsAString & aDetailsURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString licenseURL; */
NS_IMETHODIMP nsUpdate::GetLicenseURL(nsAString & aLicenseURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetLicenseURL(const nsAString & aLicenseURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString serviceURL; */
NS_IMETHODIMP nsUpdate::GetServiceURL(nsAString & aServiceURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetServiceURL(const nsAString & aServiceURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString channel; */
NS_IMETHODIMP nsUpdate::GetChannel(nsAString & aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetChannel(const nsAString & aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isCompleteUpdate; */
NS_IMETHODIMP nsUpdate::GetIsCompleteUpdate(PRBool *aIsCompleteUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetIsCompleteUpdate(PRBool aIsCompleteUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isSecurityUpdate; */
NS_IMETHODIMP nsUpdate::GetIsSecurityUpdate(PRBool *aIsSecurityUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetIsSecurityUpdate(PRBool aIsSecurityUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long long installDate; */
NS_IMETHODIMP nsUpdate::GetInstallDate(PRInt64 *aInstallDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetInstallDate(PRInt64 aInstallDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString statusText; */
NS_IMETHODIMP nsUpdate::GetStatusText(nsAString & aStatusText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetStatusText(const nsAString & aStatusText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIUpdatePatch selectedPatch; */
NS_IMETHODIMP nsUpdate::GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString state; */
NS_IMETHODIMP nsUpdate::GetState(nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetState(const nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long errorCode; */
NS_IMETHODIMP nsUpdate::GetErrorCode(PRInt32 *aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetErrorCode(PRInt32 aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long patchCount; */
NS_IMETHODIMP nsUpdate::GetPatchCount(PRUint32 *aPatchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUpdatePatch getPatchAt (in unsigned long index); */
NS_IMETHODIMP nsUpdate::GetPatchAt(PRUint32 index, nsIUpdatePatch **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement serialize (in nsIDOMDocument updates); */
NS_IMETHODIMP nsUpdate::Serialize(nsIDOMDocument *updates, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdateCheckListener */
#define NS_IUPDATECHECKLISTENER_IID_STR "8cbceb6e-8e27-46f2-8808-444c6499f836"

#define NS_IUPDATECHECKLISTENER_IID \
  {0x8cbceb6e, 0x8e27, 0x46f2, \
    { 0x88, 0x08, 0x44, 0x4c, 0x64, 0x99, 0xf8, 0x36 }}

/**
 * An interface describing an object that listens to the progress of an update
 * check operation. This object is notified as the check continues, finishes
 * and if it has an error.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIUpdateCheckListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATECHECKLISTENER_IID)

  /**
   * Called every time there is a progress notification loading the Update
   * Service file.
   * @param   request
   *          The nsIXMLHttpRequest handling the update check.
   * @param   position
   *          The current byte downloaded
   * @param   totalSize
   *          The total number of bytes that have to be downloaded
   */
  /* void onProgress (in nsIXMLHttpRequest request, in unsigned long position, in unsigned long totalSize); */
  NS_SCRIPTABLE NS_IMETHOD OnProgress(nsIXMLHttpRequest *request, PRUint32 position, PRUint32 totalSize) = 0;

  /**
   * The update check was completed.
   * @param   request
   *          The nsIXMLHttpRequest handling the update check.
   * @param   updates
   *          An array of nsIUpdate objects listing available updates.
   * @param   updateCount
   *          The size of the |updates| array.
   */
  /* void onCheckComplete (in nsIXMLHttpRequest request, [array, size_is (updateCount)] in nsIUpdate updates, in unsigned long updateCount); */
  NS_SCRIPTABLE NS_IMETHOD OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, PRUint32 updateCount) = 0;

  /**
   * An error occurred while loading the remote update service file.
   * @param   request
   *          The nsIXMLHttpRequest handling the update check.
   * @param   update
   *          A nsIUpdate object that contains details about the
   *          error in its |statusText| property.
   */
  /* void onError (in nsIXMLHttpRequest request, in nsIUpdate update); */
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIXMLHttpRequest *request, nsIUpdate *update) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateCheckListener, NS_IUPDATECHECKLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATECHECKLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(nsIXMLHttpRequest *request, PRUint32 position, PRUint32 totalSize); \
  NS_SCRIPTABLE NS_IMETHOD OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, PRUint32 updateCount); \
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIXMLHttpRequest *request, nsIUpdate *update); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATECHECKLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(nsIXMLHttpRequest *request, PRUint32 position, PRUint32 totalSize) { return _to OnProgress(request, position, totalSize); } \
  NS_SCRIPTABLE NS_IMETHOD OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, PRUint32 updateCount) { return _to OnCheckComplete(request, updates, updateCount); } \
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIXMLHttpRequest *request, nsIUpdate *update) { return _to OnError(request, update); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATECHECKLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(nsIXMLHttpRequest *request, PRUint32 position, PRUint32 totalSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProgress(request, position, totalSize); } \
  NS_SCRIPTABLE NS_IMETHOD OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, PRUint32 updateCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCheckComplete(request, updates, updateCount); } \
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIXMLHttpRequest *request, nsIUpdate *update) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(request, update); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateCheckListener : public nsIUpdateCheckListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATECHECKLISTENER

  nsUpdateCheckListener();

private:
  ~nsUpdateCheckListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdateCheckListener, nsIUpdateCheckListener)

nsUpdateCheckListener::nsUpdateCheckListener()
{
  /* member initializers and constructor code */
}

nsUpdateCheckListener::~nsUpdateCheckListener()
{
  /* destructor code */
}

/* void onProgress (in nsIXMLHttpRequest request, in unsigned long position, in unsigned long totalSize); */
NS_IMETHODIMP nsUpdateCheckListener::OnProgress(nsIXMLHttpRequest *request, PRUint32 position, PRUint32 totalSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCheckComplete (in nsIXMLHttpRequest request, [array, size_is (updateCount)] in nsIUpdate updates, in unsigned long updateCount); */
NS_IMETHODIMP nsUpdateCheckListener::OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, PRUint32 updateCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onError (in nsIXMLHttpRequest request, in nsIUpdate update); */
NS_IMETHODIMP nsUpdateCheckListener::OnError(nsIXMLHttpRequest *request, nsIUpdate *update)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdateChecker */
#define NS_IUPDATECHECKER_IID_STR "877ace25-8bc5-452a-8586-9c1cf2871994"

#define NS_IUPDATECHECKER_IID \
  {0x877ace25, 0x8bc5, 0x452a, \
    { 0x85, 0x86, 0x9c, 0x1c, 0xf2, 0x87, 0x19, 0x94 }}

/**
 * An interface describing an object that knows how to check for updates.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIUpdateChecker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATECHECKER_IID)

  /**
   * Checks for available updates, notifying a listener of the results.
   * @param   listener
   *          An object implementing nsIUpdateCheckListener which is notified
   *          of the results of an update check.
   * @param   force
   *          Forces the checker to check for updates, regardless of the
   *          current value of the user's update settings. This is used by
   *          any piece of UI that offers the user the imperative option to
   *          check for updates now, regardless of their update settings.
   *          force will not work if the system administrator has locked
   *          the app.update.enabled preference.
   */
  /* void checkForUpdates (in nsIUpdateCheckListener listener, in boolean force); */
  NS_SCRIPTABLE NS_IMETHOD CheckForUpdates(nsIUpdateCheckListener *listener, PRBool force) = 0;

  /**
   * Constants for the |stopChecking| function that tell the Checker how long
   * to stop checking:
   *
   * CURRENT_CHECK:     Stops the current (active) check only
   * CURRENT_SESSION:   Stops all checking for the current session
   * ANY_CHECKS:        Stops all checking, any session from now on
   *                    (disables update checking preferences)
   */
  enum { CURRENT_CHECK = 1U };

  enum { CURRENT_SESSION = 2U };

  enum { ANY_CHECKS = 3U };

  /**
   * Ends any pending update check.
   * @param   duration
   *          A value representing the set of checks to stop doing.
   */
  /* void stopChecking (in unsigned short duration); */
  NS_SCRIPTABLE NS_IMETHOD StopChecking(PRUint16 duration) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateChecker, NS_IUPDATECHECKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATECHECKER \
  NS_SCRIPTABLE NS_IMETHOD CheckForUpdates(nsIUpdateCheckListener *listener, PRBool force); \
  NS_SCRIPTABLE NS_IMETHOD StopChecking(PRUint16 duration); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATECHECKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CheckForUpdates(nsIUpdateCheckListener *listener, PRBool force) { return _to CheckForUpdates(listener, force); } \
  NS_SCRIPTABLE NS_IMETHOD StopChecking(PRUint16 duration) { return _to StopChecking(duration); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATECHECKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CheckForUpdates(nsIUpdateCheckListener *listener, PRBool force) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForUpdates(listener, force); } \
  NS_SCRIPTABLE NS_IMETHOD StopChecking(PRUint16 duration) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopChecking(duration); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateChecker : public nsIUpdateChecker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATECHECKER

  nsUpdateChecker();

private:
  ~nsUpdateChecker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdateChecker, nsIUpdateChecker)

nsUpdateChecker::nsUpdateChecker()
{
  /* member initializers and constructor code */
}

nsUpdateChecker::~nsUpdateChecker()
{
  /* destructor code */
}

/* void checkForUpdates (in nsIUpdateCheckListener listener, in boolean force); */
NS_IMETHODIMP nsUpdateChecker::CheckForUpdates(nsIUpdateCheckListener *listener, PRBool force)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopChecking (in unsigned short duration); */
NS_IMETHODIMP nsUpdateChecker::StopChecking(PRUint16 duration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIApplicationUpdateService */
#define NS_IAPPLICATIONUPDATESERVICE_IID_STR "9849c4bf-5197-4d22-baa8-e3b44a1703d2"

#define NS_IAPPLICATIONUPDATESERVICE_IID \
  {0x9849c4bf, 0x5197, 0x4d22, \
    { 0xba, 0xa8, 0xe3, 0xb4, 0x4a, 0x17, 0x03, 0xd2 }}

/**
 * An interface describing a global application service that handles performing
 * background update checks and provides utilities for selecting and
 * downloading update patches.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIApplicationUpdateService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONUPDATESERVICE_IID)

  /**
   * The Update Checker used for background update checking.
   */
  /* readonly attribute nsIUpdateChecker backgroundChecker; */
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker) = 0;

  /**
   * Selects the best update to install from a list of available updates.
   * @param   updates
   *          An array of updates that are available
   * @param   updateCount
   *          The length of the |updates| array
   */
  /* nsIUpdate selectUpdate ([array, size_is (updateCount)] in nsIUpdate updates, in unsigned long updateCount); */
  NS_SCRIPTABLE NS_IMETHOD SelectUpdate(nsIUpdate **updates, PRUint32 updateCount, nsIUpdate **_retval NS_OUTPARAM) = 0;

  /**
   * Adds a listener that receives progress and state information about the
   * update that is currently being downloaded, e.g. to update a user
   * interface.
   * @param   listener
   *          An object implementing nsIRequestObserver and optionally
   *          nsIProgressEventSink that is to be notified of state and
   *          progress information as the update is downloaded.
   */
  /* void addDownloadListener (in nsIRequestObserver listener); */
  NS_SCRIPTABLE NS_IMETHOD AddDownloadListener(nsIRequestObserver *listener) = 0;

  /**
   * Removes a listener that is receiving progress and state information
   * about the update that is currently being downloaded.
   * @param   listener
   *          The listener object to remove.
   */
  /* void removeDownloadListener (in nsIRequestObserver listener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDownloadListener(nsIRequestObserver *listener) = 0;

  /**
   *
   */
  /* AString downloadUpdate (in nsIUpdate update, in boolean background); */
  NS_SCRIPTABLE NS_IMETHOD DownloadUpdate(nsIUpdate *update, PRBool background, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Pauses the active update download process
   */
  /* void pauseDownload (); */
  NS_SCRIPTABLE NS_IMETHOD PauseDownload(void) = 0;

  /**
   * Whether or not there is an download happening at the moment.
   */
  /* readonly attribute boolean isDownloading; */
  NS_SCRIPTABLE NS_IMETHOD GetIsDownloading(PRBool *aIsDownloading) = 0;

  /**
   * Whether or not the Update Service can download and install updates.
   * This is a function of whether or not the current user has access
   * privileges to the install directory.
   */
  /* readonly attribute boolean canUpdate; */
  NS_SCRIPTABLE NS_IMETHOD GetCanUpdate(PRBool *aCanUpdate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationUpdateService, NS_IAPPLICATIONUPDATESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONUPDATESERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker); \
  NS_SCRIPTABLE NS_IMETHOD SelectUpdate(nsIUpdate **updates, PRUint32 updateCount, nsIUpdate **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddDownloadListener(nsIRequestObserver *listener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownloadListener(nsIRequestObserver *listener); \
  NS_SCRIPTABLE NS_IMETHOD DownloadUpdate(nsIUpdate *update, PRBool background, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PauseDownload(void); \
  NS_SCRIPTABLE NS_IMETHOD GetIsDownloading(PRBool *aIsDownloading); \
  NS_SCRIPTABLE NS_IMETHOD GetCanUpdate(PRBool *aCanUpdate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONUPDATESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker) { return _to GetBackgroundChecker(aBackgroundChecker); } \
  NS_SCRIPTABLE NS_IMETHOD SelectUpdate(nsIUpdate **updates, PRUint32 updateCount, nsIUpdate **_retval NS_OUTPARAM) { return _to SelectUpdate(updates, updateCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddDownloadListener(nsIRequestObserver *listener) { return _to AddDownloadListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownloadListener(nsIRequestObserver *listener) { return _to RemoveDownloadListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD DownloadUpdate(nsIUpdate *update, PRBool background, nsAString & _retval NS_OUTPARAM) { return _to DownloadUpdate(update, background, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD PauseDownload(void) { return _to PauseDownload(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDownloading(PRBool *aIsDownloading) { return _to GetIsDownloading(aIsDownloading); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanUpdate(PRBool *aCanUpdate) { return _to GetCanUpdate(aCanUpdate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONUPDATESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBackgroundChecker(aBackgroundChecker); } \
  NS_SCRIPTABLE NS_IMETHOD SelectUpdate(nsIUpdate **updates, PRUint32 updateCount, nsIUpdate **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectUpdate(updates, updateCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddDownloadListener(nsIRequestObserver *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDownloadListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownloadListener(nsIRequestObserver *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDownloadListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD DownloadUpdate(nsIUpdate *update, PRBool background, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DownloadUpdate(update, background, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD PauseDownload(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PauseDownload(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDownloading(PRBool *aIsDownloading) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDownloading(aIsDownloading); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanUpdate(PRBool *aCanUpdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanUpdate(aCanUpdate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationUpdateService : public nsIApplicationUpdateService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONUPDATESERVICE

  nsApplicationUpdateService();

private:
  ~nsApplicationUpdateService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationUpdateService, nsIApplicationUpdateService)

nsApplicationUpdateService::nsApplicationUpdateService()
{
  /* member initializers and constructor code */
}

nsApplicationUpdateService::~nsApplicationUpdateService()
{
  /* destructor code */
}

/* readonly attribute nsIUpdateChecker backgroundChecker; */
NS_IMETHODIMP nsApplicationUpdateService::GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUpdate selectUpdate ([array, size_is (updateCount)] in nsIUpdate updates, in unsigned long updateCount); */
NS_IMETHODIMP nsApplicationUpdateService::SelectUpdate(nsIUpdate **updates, PRUint32 updateCount, nsIUpdate **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDownloadListener (in nsIRequestObserver listener); */
NS_IMETHODIMP nsApplicationUpdateService::AddDownloadListener(nsIRequestObserver *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDownloadListener (in nsIRequestObserver listener); */
NS_IMETHODIMP nsApplicationUpdateService::RemoveDownloadListener(nsIRequestObserver *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString downloadUpdate (in nsIUpdate update, in boolean background); */
NS_IMETHODIMP nsApplicationUpdateService::DownloadUpdate(nsIUpdate *update, PRBool background, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pauseDownload (); */
NS_IMETHODIMP nsApplicationUpdateService::PauseDownload()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDownloading; */
NS_IMETHODIMP nsApplicationUpdateService::GetIsDownloading(PRBool *aIsDownloading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canUpdate; */
NS_IMETHODIMP nsApplicationUpdateService::GetCanUpdate(PRBool *aCanUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdateManager */
#define NS_IUPDATEMANAGER_IID_STR "fede66a9-9f96-4507-a22a-775ee885577e"

#define NS_IUPDATEMANAGER_IID \
  {0xfede66a9, 0x9f96, 0x4507, \
    { 0xa2, 0x2a, 0x77, 0x5e, 0xe8, 0x85, 0x57, 0x7e }}

/**
 * An interface describing a global application service that maintains a list
 * of updates previously performed as well as the current active update.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIUpdateManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATEMANAGER_IID)

  /**
   * Gets the update at the specified index
   * @param   index
   *          The index within the updates array
   * @returns The nsIUpdate object at the specified index
   */
  /* nsIUpdate getUpdateAt (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetUpdateAt(PRInt32 index, nsIUpdate **_retval NS_OUTPARAM) = 0;

  /**
   * Gets the total number of updates in the history list.
   */
  /* readonly attribute long updateCount; */
  NS_SCRIPTABLE NS_IMETHOD GetUpdateCount(PRInt32 *aUpdateCount) = 0;

  /**
   * The active (current) update. The active update is not in the history list.
   */
  /* attribute nsIUpdate activeUpdate; */
  NS_SCRIPTABLE NS_IMETHOD GetActiveUpdate(nsIUpdate * *aActiveUpdate) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetActiveUpdate(nsIUpdate * aActiveUpdate) = 0;

  /**
   * Saves all updates to disk.
   */
  /* void saveUpdates (); */
  NS_SCRIPTABLE NS_IMETHOD SaveUpdates(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateManager, NS_IUPDATEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATEMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateAt(PRInt32 index, nsIUpdate **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateCount(PRInt32 *aUpdateCount); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveUpdate(nsIUpdate * *aActiveUpdate); \
  NS_SCRIPTABLE NS_IMETHOD SetActiveUpdate(nsIUpdate * aActiveUpdate); \
  NS_SCRIPTABLE NS_IMETHOD SaveUpdates(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateAt(PRInt32 index, nsIUpdate **_retval NS_OUTPARAM) { return _to GetUpdateAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateCount(PRInt32 *aUpdateCount) { return _to GetUpdateCount(aUpdateCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveUpdate(nsIUpdate * *aActiveUpdate) { return _to GetActiveUpdate(aActiveUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD SetActiveUpdate(nsIUpdate * aActiveUpdate) { return _to SetActiveUpdate(aActiveUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD SaveUpdates(void) { return _to SaveUpdates(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateAt(PRInt32 index, nsIUpdate **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateCount(PRInt32 *aUpdateCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateCount(aUpdateCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveUpdate(nsIUpdate * *aActiveUpdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveUpdate(aActiveUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD SetActiveUpdate(nsIUpdate * aActiveUpdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetActiveUpdate(aActiveUpdate); } \
  NS_SCRIPTABLE NS_IMETHOD SaveUpdates(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveUpdates(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateManager : public nsIUpdateManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATEMANAGER

  nsUpdateManager();

private:
  ~nsUpdateManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdateManager, nsIUpdateManager)

nsUpdateManager::nsUpdateManager()
{
  /* member initializers and constructor code */
}

nsUpdateManager::~nsUpdateManager()
{
  /* destructor code */
}

/* nsIUpdate getUpdateAt (in long index); */
NS_IMETHODIMP nsUpdateManager::GetUpdateAt(PRInt32 index, nsIUpdate **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long updateCount; */
NS_IMETHODIMP nsUpdateManager::GetUpdateCount(PRInt32 *aUpdateCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIUpdate activeUpdate; */
NS_IMETHODIMP nsUpdateManager::GetActiveUpdate(nsIUpdate * *aActiveUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdateManager::SetActiveUpdate(nsIUpdate * aActiveUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveUpdates (); */
NS_IMETHODIMP nsUpdateManager::SaveUpdates()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdatePrompt */
#define NS_IUPDATEPROMPT_IID_STR "599fd3c6-ec68-4499-ada5-2997739c97a6"

#define NS_IUPDATEPROMPT_IID \
  {0x599fd3c6, 0xec68, 0x4499, \
    { 0xad, 0xa5, 0x29, 0x97, 0x73, 0x9c, 0x97, 0xa6 }}

/**
 * An interface describing an object that can show various kinds of Update
 * notification UI to the user.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIUpdatePrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATEPROMPT_IID)

  /**
   * Shows a user interface that checks for and then displays the available
   * updates.
   */
  /* void checkForUpdates (); */
  NS_SCRIPTABLE NS_IMETHOD CheckForUpdates(void) = 0;

  /**
   * Show a message advising that an update is available for download and
   * install.
   * @param   update
   *          The update to be downloaded and installed
   */
  /* void showUpdateAvailable (in nsIUpdate update); */
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateAvailable(nsIUpdate *update) = 0;

  /**
   * Show a message advising that an update has now been downloaded and that
   * a restart is necessary to complete the update.
   * @param   update
   *          The update that was downloaded
   * @param   background
   *          Less obtrusive UI, starting with a non-modal notification alert
   */
  /* void showUpdateDownloaded (in nsIUpdate update, [optional] in boolean background); */
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateDownloaded(nsIUpdate *update, PRBool background) = 0;

  /**
   * Shows a message that an update was installed successfully.
   */
  /* void showUpdateInstalled (); */
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateInstalled(void) = 0;

  /**
   * Shows an error message UI telling the user about some kind of update
   * failure, e.g. failure to apply patch.
   * @param   update
   *          The nsIUpdate object which we could not install
   */
  /* void showUpdateError (in nsIUpdate update); */
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateError(nsIUpdate *update) = 0;

  /**
   * Shows a list of all updates installed to date.
   * @param   parent
   *          A parent window to anchor this window to. Can be null.
   */
  /* void showUpdateHistory (in nsIDOMWindow parent); */
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateHistory(nsIDOMWindow *parent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdatePrompt, NS_IUPDATEPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATEPROMPT \
  NS_SCRIPTABLE NS_IMETHOD CheckForUpdates(void); \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateAvailable(nsIUpdate *update); \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateDownloaded(nsIUpdate *update, PRBool background); \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateInstalled(void); \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateError(nsIUpdate *update); \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateHistory(nsIDOMWindow *parent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATEPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD CheckForUpdates(void) { return _to CheckForUpdates(); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateAvailable(nsIUpdate *update) { return _to ShowUpdateAvailable(update); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateDownloaded(nsIUpdate *update, PRBool background) { return _to ShowUpdateDownloaded(update, background); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateInstalled(void) { return _to ShowUpdateInstalled(); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateError(nsIUpdate *update) { return _to ShowUpdateError(update); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateHistory(nsIDOMWindow *parent) { return _to ShowUpdateHistory(parent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATEPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD CheckForUpdates(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForUpdates(); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateAvailable(nsIUpdate *update) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateAvailable(update); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateDownloaded(nsIUpdate *update, PRBool background) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateDownloaded(update, background); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateInstalled(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateInstalled(); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateError(nsIUpdate *update) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateError(update); } \
  NS_SCRIPTABLE NS_IMETHOD ShowUpdateHistory(nsIDOMWindow *parent) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateHistory(parent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdatePrompt : public nsIUpdatePrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATEPROMPT

  nsUpdatePrompt();

private:
  ~nsUpdatePrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdatePrompt, nsIUpdatePrompt)

nsUpdatePrompt::nsUpdatePrompt()
{
  /* member initializers and constructor code */
}

nsUpdatePrompt::~nsUpdatePrompt()
{
  /* destructor code */
}

/* void checkForUpdates (); */
NS_IMETHODIMP nsUpdatePrompt::CheckForUpdates()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateAvailable (in nsIUpdate update); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateAvailable(nsIUpdate *update)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateDownloaded (in nsIUpdate update, [optional] in boolean background); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateDownloaded(nsIUpdate *update, PRBool background)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateInstalled (); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateInstalled()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateError (in nsIUpdate update); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateError(nsIUpdate *update)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateHistory (in nsIDOMWindow parent); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateHistory(nsIDOMWindow *parent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdateTimerManager */
#define NS_IUPDATETIMERMANAGER_IID_STR "0765c92c-6145-4253-9db4-594d8023087e"

#define NS_IUPDATETIMERMANAGER_IID \
  {0x0765c92c, 0x6145, 0x4253, \
    { 0x9d, 0xb4, 0x59, 0x4d, 0x80, 0x23, 0x08, 0x7e }}

/**
 * An interface describing a global application service that allows long
 * duration (e.g. 1-7 or more days, weeks or months) timers to be registered
 * and then fired.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIUpdateTimerManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATETIMERMANAGER_IID)

  /**
   * Register an interval with the timer manager. The timer manager
   * periodically checks to see if the interval has expired and if it has
   * calls the specified callback. This is persistent across application
   * restarts and can handle intervals of long durations.
   * @param   id
   *          An id that identifies the interval, used for persistence
   * @param   callback
   *          A nsITimerCallback object that is notified when the interval
   *          expires
   * @param   interval
   *          The length of time, in seconds, of the interval
   */
  /* void registerTimer (in AString id, in nsITimerCallback callback, in unsigned long interval); */
  NS_SCRIPTABLE NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateTimerManager, NS_IUPDATETIMERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATETIMERMANAGER \
  NS_SCRIPTABLE NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATETIMERMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval) { return _to RegisterTimer(id, callback, interval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATETIMERMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterTimer(id, callback, interval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateTimerManager : public nsIUpdateTimerManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATETIMERMANAGER

  nsUpdateTimerManager();

private:
  ~nsUpdateTimerManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdateTimerManager, nsIUpdateTimerManager)

nsUpdateTimerManager::nsUpdateTimerManager()
{
  /* member initializers and constructor code */
}

nsUpdateTimerManager::~nsUpdateTimerManager()
{
  /* destructor code */
}

/* void registerTimer (in AString id, in nsITimerCallback callback, in unsigned long interval); */
NS_IMETHODIMP nsUpdateTimerManager::RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUpdateService_h__ */
