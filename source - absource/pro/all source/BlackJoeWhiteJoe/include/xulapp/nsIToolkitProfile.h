/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/profile/public/nsIToolkitProfile.idl
 */

#ifndef __gen_nsIToolkitProfile_h__
#define __gen_nsIToolkitProfile_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILocalFile; /* forward declaration */

class nsIToolkitProfile; /* forward declaration */

class nsIProfileUnlocker; /* forward declaration */


/* starting interface:    nsIProfileLock */
#define NS_IPROFILELOCK_IID_STR "50e07b0a-f338-4da3-bcdb-f4bb0db94dbe"

#define NS_IPROFILELOCK_IID \
  {0x50e07b0a, 0xf338, 0x4da3, \
    { 0xbc, 0xdb, 0xf4, 0xbb, 0x0d, 0xb9, 0x4d, 0xbe }}

/**
 * Hold on to a profile lock. Once you release the last reference to this
 * interface, the profile lock is released.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIProfileLock : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILELOCK_IID)

  /**
     * The main profile directory.
     */
  /* readonly attribute nsILocalFile directory; */
  NS_SCRIPTABLE NS_IMETHOD GetDirectory(nsILocalFile * *aDirectory) = 0;

  /**
     * A directory corresponding to the main profile directory that exists for
     * the purpose of storing data on the local filesystem, including cache
     * files or other data files that may not represent critical user data.
     * (e.g., this directory may not be included as part of a backup scheme.)
     *
     * In some cases, this directory may just be the main profile directory.
     */
  /* readonly attribute nsILocalFile localDirectory; */
  NS_SCRIPTABLE NS_IMETHOD GetLocalDirectory(nsILocalFile * *aLocalDirectory) = 0;

  /**
     * Unlock the profile.
     */
  /* void unlock (); */
  NS_SCRIPTABLE NS_IMETHOD Unlock(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfileLock, NS_IPROFILELOCK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILELOCK \
  NS_SCRIPTABLE NS_IMETHOD GetDirectory(nsILocalFile * *aDirectory); \
  NS_SCRIPTABLE NS_IMETHOD GetLocalDirectory(nsILocalFile * *aLocalDirectory); \
  NS_SCRIPTABLE NS_IMETHOD Unlock(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILELOCK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDirectory(nsILocalFile * *aDirectory) { return _to GetDirectory(aDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalDirectory(nsILocalFile * *aLocalDirectory) { return _to GetLocalDirectory(aLocalDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD Unlock(void) { return _to Unlock(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILELOCK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDirectory(nsILocalFile * *aDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirectory(aDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalDirectory(nsILocalFile * *aLocalDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalDirectory(aLocalDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD Unlock(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unlock(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfileLock : public nsIProfileLock
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILELOCK

  nsProfileLock();

private:
  ~nsProfileLock();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProfileLock, nsIProfileLock)

nsProfileLock::nsProfileLock()
{
  /* member initializers and constructor code */
}

nsProfileLock::~nsProfileLock()
{
  /* destructor code */
}

/* readonly attribute nsILocalFile directory; */
NS_IMETHODIMP nsProfileLock::GetDirectory(nsILocalFile * *aDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILocalFile localDirectory; */
NS_IMETHODIMP nsProfileLock::GetLocalDirectory(nsILocalFile * *aLocalDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlock (); */
NS_IMETHODIMP nsProfileLock::Unlock()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIToolkitProfile */
#define NS_ITOOLKITPROFILE_IID_STR "7422b090-4a86-4407-972e-75468a625388"

#define NS_ITOOLKITPROFILE_IID \
  {0x7422b090, 0x4a86, 0x4407, \
    { 0x97, 0x2e, 0x75, 0x46, 0x8a, 0x62, 0x53, 0x88 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIToolkitProfile : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOOLKITPROFILE_IID)

  /**
 * A interface representing a profile.
 * @note THIS INTERFACE SHOULD BE IMPLEMENTED BY THE TOOLKIT CODE ONLY! DON'T
 *       EVEN THINK ABOUT IMPLEMENTING THIS IN JAVASCRIPT!
 */
/**
     * The location of the profile directory.
     */
  /* readonly attribute nsILocalFile rootDir; */
  NS_SCRIPTABLE NS_IMETHOD GetRootDir(nsILocalFile * *aRootDir) = 0;

  /**
     * The location of the profile local directory, which may be the same as
     * the root directory.  See nsIProfileLock::localDirectory.
     */
  /* readonly attribute nsILocalFile localDir; */
  NS_SCRIPTABLE NS_IMETHOD GetLocalDir(nsILocalFile * *aLocalDir) = 0;

  /**
     * The name of the profile.
     */
  /* attribute AUTF8String name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsACString & aName) = 0;

  /**
     * Removes the profile from the registry of profiles.
     *
     * @param removeFiles
     *        Indicates whether or not the profile directory should be
     *        removed in addition.
     */
  /* void remove (in boolean removeFiles); */
  NS_SCRIPTABLE NS_IMETHOD Remove(PRBool removeFiles) = 0;

  /**
     * Lock this profile using platform-specific locking methods.
     *
     * @param lockFile If locking fails, this may return a lockFile object
     *                 which can be used in platform-specific ways to
     *                 determine which process has the file locked. Null
     *                 may be passed.
     * @return An interface which holds a profile lock as long as you reference
     *         it.
     * @throws NS_ERROR_FILE_ACCESS_DENIED if the profile was already locked.
     */
  /* nsIProfileLock lock (out nsIProfileUnlocker aUnlocker); */
  NS_SCRIPTABLE NS_IMETHOD Lock(nsIProfileUnlocker **aUnlocker NS_OUTPARAM, nsIProfileLock **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIToolkitProfile, NS_ITOOLKITPROFILE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOOLKITPROFILE \
  NS_SCRIPTABLE NS_IMETHOD GetRootDir(nsILocalFile * *aRootDir); \
  NS_SCRIPTABLE NS_IMETHOD GetLocalDir(nsILocalFile * *aLocalDir); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD Remove(PRBool removeFiles); \
  NS_SCRIPTABLE NS_IMETHOD Lock(nsIProfileUnlocker **aUnlocker NS_OUTPARAM, nsIProfileLock **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOOLKITPROFILE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRootDir(nsILocalFile * *aRootDir) { return _to GetRootDir(aRootDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalDir(nsILocalFile * *aLocalDir) { return _to GetLocalDir(aLocalDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsACString & aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(PRBool removeFiles) { return _to Remove(removeFiles); } \
  NS_SCRIPTABLE NS_IMETHOD Lock(nsIProfileUnlocker **aUnlocker NS_OUTPARAM, nsIProfileLock **_retval NS_OUTPARAM) { return _to Lock(aUnlocker, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOOLKITPROFILE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRootDir(nsILocalFile * *aRootDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootDir(aRootDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalDir(nsILocalFile * *aLocalDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalDir(aLocalDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(PRBool removeFiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(removeFiles); } \
  NS_SCRIPTABLE NS_IMETHOD Lock(nsIProfileUnlocker **aUnlocker NS_OUTPARAM, nsIProfileLock **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Lock(aUnlocker, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsToolkitProfile : public nsIToolkitProfile
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOOLKITPROFILE

  nsToolkitProfile();

private:
  ~nsToolkitProfile();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsToolkitProfile, nsIToolkitProfile)

nsToolkitProfile::nsToolkitProfile()
{
  /* member initializers and constructor code */
}

nsToolkitProfile::~nsToolkitProfile()
{
  /* destructor code */
}

/* readonly attribute nsILocalFile rootDir; */
NS_IMETHODIMP nsToolkitProfile::GetRootDir(nsILocalFile * *aRootDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILocalFile localDir; */
NS_IMETHODIMP nsToolkitProfile::GetLocalDir(nsILocalFile * *aLocalDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String name; */
NS_IMETHODIMP nsToolkitProfile::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsToolkitProfile::SetName(const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in boolean removeFiles); */
NS_IMETHODIMP nsToolkitProfile::Remove(PRBool removeFiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIProfileLock lock (out nsIProfileUnlocker aUnlocker); */
NS_IMETHODIMP nsToolkitProfile::Lock(nsIProfileUnlocker **aUnlocker NS_OUTPARAM, nsIProfileLock **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIToolkitProfile_h__ */
