/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/profile/public/nsIProfileMigrator.idl
 */

#ifndef __gen_nsIProfileMigrator_h__
#define __gen_nsIProfileMigrator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIProfileStartup */
#define NS_IPROFILESTARTUP_IID_STR "048e5ca1-0eb7-4bb1-a9a2-a36f7d4e0e3c"

#define NS_IPROFILESTARTUP_IID \
  {0x048e5ca1, 0x0eb7, 0x4bb1, \
    { 0xa9, 0xa2, 0xa3, 0x6f, 0x7d, 0x4e, 0x0e, 0x3c }}

/**
 * Helper interface for nsIProfileMigrator.
 *
 * @provider Toolkit (Startup code)
 * @client   Application (Profile-migration code)
 * @obtainable nsIProfileMigrator.migrate
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIProfileStartup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILESTARTUP_IID)

  /**
   * The root directory of the semi-current profile, during profile migration.
   * After nsIProfileMigrator.migrate has returned, this object will not be
   * useful.
   */
  /* readonly attribute nsIFile directory; */
  NS_SCRIPTABLE NS_IMETHOD GetDirectory(nsIFile * *aDirectory) = 0;

  /**
   * Do profile-startup by setting NS_APP_USER_PROFILE_50_DIR in the directory
   * service and notifying the profile-startup observer topics.
   */
  /* void doStartup (); */
  NS_SCRIPTABLE NS_IMETHOD DoStartup(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfileStartup, NS_IPROFILESTARTUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILESTARTUP \
  NS_SCRIPTABLE NS_IMETHOD GetDirectory(nsIFile * *aDirectory); \
  NS_SCRIPTABLE NS_IMETHOD DoStartup(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILESTARTUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDirectory(nsIFile * *aDirectory) { return _to GetDirectory(aDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD DoStartup(void) { return _to DoStartup(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILESTARTUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDirectory(nsIFile * *aDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirectory(aDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD DoStartup(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoStartup(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfileStartup : public nsIProfileStartup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILESTARTUP

  nsProfileStartup();

private:
  ~nsProfileStartup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProfileStartup, nsIProfileStartup)

nsProfileStartup::nsProfileStartup()
{
  /* member initializers and constructor code */
}

nsProfileStartup::~nsProfileStartup()
{
  /* destructor code */
}

/* readonly attribute nsIFile directory; */
NS_IMETHODIMP nsProfileStartup::GetDirectory(nsIFile * *aDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doStartup (); */
NS_IMETHODIMP nsProfileStartup::DoStartup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIProfileMigrator */
#define NS_IPROFILEMIGRATOR_IID_STR "24ce8b9d-b7ff-4279-aef4-26e158f03e34"

#define NS_IPROFILEMIGRATOR_IID \
  {0x24ce8b9d, 0xb7ff, 0x4279, \
    { 0xae, 0xf4, 0x26, 0xe1, 0x58, 0xf0, 0x3e, 0x34 }}

/**
 * Migrate application settings from an outside source.
 *
 * @provider Application (Profile-migration code)
 * @client   Toolkit (Startup code)
 * @obtainable service, contractid("@mozilla.org/toolkit/profile-migrator;1")
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIProfileMigrator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILEMIGRATOR_IID)

  /**
   * Import existing profile paths.  When the app is started the first
   * time, if there are no INI-style profiles, appstartup will call
   * this method to import any registry- style profiles that may
   * exist. When this method is called, there is no event queue
   * service and this method should not attempt to use the network or
   * show any GUI.
   *
   * @note You don't actually have to move the profile data. Just call
   *       nsIToolkitProfileService.create on the existing profile path(s).
   */
  /* void import (); */
  NS_SCRIPTABLE NS_IMETHOD Import(void) = 0;

  /**
   * Do profile migration.
   *
   * When this method is called, a default profile has been created;
   * XPCOM has been initialized such that compreg.dat is in the
   * profile; the directory service does *not* return a key for
   * NS_APP_USER_PROFILE_50_DIR or any of the keys depending on an active
   * profile. To figure out the directory of the "current" profile, use
   * aStartup.directory.
   *
   * If your migrator needs to access services that use the profile (to
   * set profile prefs or bookmarks, for example), use aStartup.doStartup.
   *
   * The startup code ignores COM exceptions thrown from this method.
   */
  /* void migrate (in nsIProfileStartup aStartup); */
  NS_SCRIPTABLE NS_IMETHOD Migrate(nsIProfileStartup *aStartup) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfileMigrator, NS_IPROFILEMIGRATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILEMIGRATOR \
  NS_SCRIPTABLE NS_IMETHOD Import(void); \
  NS_SCRIPTABLE NS_IMETHOD Migrate(nsIProfileStartup *aStartup); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILEMIGRATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD Import(void) { return _to Import(); } \
  NS_SCRIPTABLE NS_IMETHOD Migrate(nsIProfileStartup *aStartup) { return _to Migrate(aStartup); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILEMIGRATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD Import(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Import(); } \
  NS_SCRIPTABLE NS_IMETHOD Migrate(nsIProfileStartup *aStartup) { return !_to ? NS_ERROR_NULL_POINTER : _to->Migrate(aStartup); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfileMigrator : public nsIProfileMigrator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILEMIGRATOR

  nsProfileMigrator();

private:
  ~nsProfileMigrator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProfileMigrator, nsIProfileMigrator)

nsProfileMigrator::nsProfileMigrator()
{
  /* member initializers and constructor code */
}

nsProfileMigrator::~nsProfileMigrator()
{
  /* destructor code */
}

/* void import (); */
NS_IMETHODIMP nsProfileMigrator::Import()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void migrate (in nsIProfileStartup aStartup); */
NS_IMETHODIMP nsProfileMigrator::Migrate(nsIProfileStartup *aStartup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_PROFILEMIGRATOR_CONTRACTID "@mozilla.org/toolkit/profile-migrator;1"

#endif /* __gen_nsIProfileMigrator_h__ */
