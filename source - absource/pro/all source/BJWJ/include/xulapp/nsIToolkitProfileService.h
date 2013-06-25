/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/profile/public/nsIToolkitProfileService.idl
 */

#ifndef __gen_nsIToolkitProfileService_h__
#define __gen_nsIToolkitProfileService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsILocalFile; /* forward declaration */

class nsIToolkitProfile; /* forward declaration */

class nsIProfileLock; /* forward declaration */


/* starting interface:    nsIToolkitProfileService */
#define NS_ITOOLKITPROFILESERVICE_IID_STR "9b434f48-438c-4f85-89de-b7f321a45341"

#define NS_ITOOLKITPROFILESERVICE_IID \
  {0x9b434f48, 0x438c, 0x4f85, \
    { 0x89, 0xde, 0xb7, 0xf3, 0x21, 0xa4, 0x53, 0x41 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIToolkitProfileService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOOLKITPROFILESERVICE_IID)

  /* attribute boolean startWithLastProfile; */
  NS_SCRIPTABLE NS_IMETHOD GetStartWithLastProfile(PRBool *aStartWithLastProfile) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStartWithLastProfile(PRBool aStartWithLastProfile) = 0;

  /* attribute boolean startOffline; */
  NS_SCRIPTABLE NS_IMETHOD GetStartOffline(PRBool *aStartOffline) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStartOffline(PRBool aStartOffline) = 0;

  /* readonly attribute nsISimpleEnumerator profiles; */
  NS_SCRIPTABLE NS_IMETHOD GetProfiles(nsISimpleEnumerator * *aProfiles) = 0;

  /* attribute nsIToolkitProfile selectedProfile; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectedProfile(nsIToolkitProfile * aSelectedProfile) = 0;

  /**
     * Get a profile by name. This is mainly for use by the -P
     * commandline flag.
     *
     * @param aName The profile name to find.
     */
  /* nsIToolkitProfile getProfileByName (in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetProfileByName(const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM) = 0;

  /**
     * Lock an arbitrary path as a profile. If the path does not exist, it
     * will be created and the defaults copied from the application directory.
     */
  /* nsIProfileLock lockProfilePath (in nsILocalFile aDirectory, in nsILocalFile aTempDirectory); */
  NS_SCRIPTABLE NS_IMETHOD LockProfilePath(nsILocalFile *aDirectory, nsILocalFile *aTempDirectory, nsIProfileLock **_retval NS_OUTPARAM) = 0;

  /**
     * Create a new profile.
     * 
     * @param aRootDir
     *        The profile directory. May be null, in which case a suitable
     *        default will be chosen based on the profile name.
     * @param aTempDir
     *        The profile temporary directory. May be null, in which case a
     *        suitable default will be chosen based either on the profile name
     *        if aRootDir is null or aRootDir itself.
     * @param aName
     *        The profile name.
     */
  /* nsIToolkitProfile createProfile (in nsILocalFile aRootDir, in nsILocalFile aTempDir, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD CreateProfile(nsILocalFile *aRootDir, nsILocalFile *aTempDir, const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM) = 0;

  /**
     * Returns the number of profiles.
     * @return 0, 1, or 2. More than 2 profiles will always return 2.
     */
  /* readonly attribute unsigned long profileCount; */
  NS_SCRIPTABLE NS_IMETHOD GetProfileCount(PRUint32 *aProfileCount) = 0;

  /**
     * Flush the profiles list file.
     */
  /* void flush (); */
  NS_SCRIPTABLE NS_IMETHOD Flush(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIToolkitProfileService, NS_ITOOLKITPROFILESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOOLKITPROFILESERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetStartWithLastProfile(PRBool *aStartWithLastProfile); \
  NS_SCRIPTABLE NS_IMETHOD SetStartWithLastProfile(PRBool aStartWithLastProfile); \
  NS_SCRIPTABLE NS_IMETHOD GetStartOffline(PRBool *aStartOffline); \
  NS_SCRIPTABLE NS_IMETHOD SetStartOffline(PRBool aStartOffline); \
  NS_SCRIPTABLE NS_IMETHOD GetProfiles(nsISimpleEnumerator * *aProfiles); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedProfile(nsIToolkitProfile * aSelectedProfile); \
  NS_SCRIPTABLE NS_IMETHOD GetProfileByName(const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LockProfilePath(nsILocalFile *aDirectory, nsILocalFile *aTempDirectory, nsIProfileLock **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateProfile(nsILocalFile *aRootDir, nsILocalFile *aTempDir, const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetProfileCount(PRUint32 *aProfileCount); \
  NS_SCRIPTABLE NS_IMETHOD Flush(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOOLKITPROFILESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStartWithLastProfile(PRBool *aStartWithLastProfile) { return _to GetStartWithLastProfile(aStartWithLastProfile); } \
  NS_SCRIPTABLE NS_IMETHOD SetStartWithLastProfile(PRBool aStartWithLastProfile) { return _to SetStartWithLastProfile(aStartWithLastProfile); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartOffline(PRBool *aStartOffline) { return _to GetStartOffline(aStartOffline); } \
  NS_SCRIPTABLE NS_IMETHOD SetStartOffline(PRBool aStartOffline) { return _to SetStartOffline(aStartOffline); } \
  NS_SCRIPTABLE NS_IMETHOD GetProfiles(nsISimpleEnumerator * *aProfiles) { return _to GetProfiles(aProfiles); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile) { return _to GetSelectedProfile(aSelectedProfile); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedProfile(nsIToolkitProfile * aSelectedProfile) { return _to SetSelectedProfile(aSelectedProfile); } \
  NS_SCRIPTABLE NS_IMETHOD GetProfileByName(const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM) { return _to GetProfileByName(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LockProfilePath(nsILocalFile *aDirectory, nsILocalFile *aTempDirectory, nsIProfileLock **_retval NS_OUTPARAM) { return _to LockProfilePath(aDirectory, aTempDirectory, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateProfile(nsILocalFile *aRootDir, nsILocalFile *aTempDir, const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM) { return _to CreateProfile(aRootDir, aTempDir, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProfileCount(PRUint32 *aProfileCount) { return _to GetProfileCount(aProfileCount); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return _to Flush(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOOLKITPROFILESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStartWithLastProfile(PRBool *aStartWithLastProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartWithLastProfile(aStartWithLastProfile); } \
  NS_SCRIPTABLE NS_IMETHOD SetStartWithLastProfile(PRBool aStartWithLastProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartWithLastProfile(aStartWithLastProfile); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartOffline(PRBool *aStartOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartOffline(aStartOffline); } \
  NS_SCRIPTABLE NS_IMETHOD SetStartOffline(PRBool aStartOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartOffline(aStartOffline); } \
  NS_SCRIPTABLE NS_IMETHOD GetProfiles(nsISimpleEnumerator * *aProfiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfiles(aProfiles); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedProfile(aSelectedProfile); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedProfile(nsIToolkitProfile * aSelectedProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedProfile(aSelectedProfile); } \
  NS_SCRIPTABLE NS_IMETHOD GetProfileByName(const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileByName(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LockProfilePath(nsILocalFile *aDirectory, nsILocalFile *aTempDirectory, nsIProfileLock **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockProfilePath(aDirectory, aTempDirectory, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateProfile(nsILocalFile *aRootDir, nsILocalFile *aTempDir, const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateProfile(aRootDir, aTempDir, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProfileCount(PRUint32 *aProfileCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileCount(aProfileCount); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Flush(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsToolkitProfileService : public nsIToolkitProfileService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOOLKITPROFILESERVICE

  nsToolkitProfileService();

private:
  ~nsToolkitProfileService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsToolkitProfileService, nsIToolkitProfileService)

nsToolkitProfileService::nsToolkitProfileService()
{
  /* member initializers and constructor code */
}

nsToolkitProfileService::~nsToolkitProfileService()
{
  /* destructor code */
}

/* attribute boolean startWithLastProfile; */
NS_IMETHODIMP nsToolkitProfileService::GetStartWithLastProfile(PRBool *aStartWithLastProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsToolkitProfileService::SetStartWithLastProfile(PRBool aStartWithLastProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean startOffline; */
NS_IMETHODIMP nsToolkitProfileService::GetStartOffline(PRBool *aStartOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsToolkitProfileService::SetStartOffline(PRBool aStartOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator profiles; */
NS_IMETHODIMP nsToolkitProfileService::GetProfiles(nsISimpleEnumerator * *aProfiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIToolkitProfile selectedProfile; */
NS_IMETHODIMP nsToolkitProfileService::GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsToolkitProfileService::SetSelectedProfile(nsIToolkitProfile * aSelectedProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIToolkitProfile getProfileByName (in AUTF8String aName); */
NS_IMETHODIMP nsToolkitProfileService::GetProfileByName(const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIProfileLock lockProfilePath (in nsILocalFile aDirectory, in nsILocalFile aTempDirectory); */
NS_IMETHODIMP nsToolkitProfileService::LockProfilePath(nsILocalFile *aDirectory, nsILocalFile *aTempDirectory, nsIProfileLock **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIToolkitProfile createProfile (in nsILocalFile aRootDir, in nsILocalFile aTempDir, in AUTF8String aName); */
NS_IMETHODIMP nsToolkitProfileService::CreateProfile(nsILocalFile *aRootDir, nsILocalFile *aTempDir, const nsACString & aName, nsIToolkitProfile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long profileCount; */
NS_IMETHODIMP nsToolkitProfileService::GetProfileCount(PRUint32 *aProfileCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flush (); */
NS_IMETHODIMP nsToolkitProfileService::Flush()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_PROFILESERVICE_CONTRACTID "@mozilla.org/toolkit/profile-service;1"

#endif /* __gen_nsIToolkitProfileService_h__ */
