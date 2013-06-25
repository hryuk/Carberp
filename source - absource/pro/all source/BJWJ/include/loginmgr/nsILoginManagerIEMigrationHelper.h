/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/passwordmgr/public/nsILoginManagerIEMigrationHelper.idl
 */

#ifndef __gen_nsILoginManagerIEMigrationHelper_h__
#define __gen_nsILoginManagerIEMigrationHelper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILoginInfo; /* forward declaration */


/* starting interface:    nsILoginManagerIEMigrationHelper */
#define NS_ILOGINMANAGERIEMIGRATIONHELPER_IID_STR "8a59ea3d-b8d0-48af-a3e2-63e27a02cde7"

#define NS_ILOGINMANAGERIEMIGRATIONHELPER_IID \
  {0x8a59ea3d, 0xb8d0, 0x48af, \
    { 0xa3, 0xe2, 0x63, 0xe2, 0x7a, 0x02, 0xcd, 0xe7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsILoginManagerIEMigrationHelper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMANAGERIEMIGRATIONHELPER_IID)

  /**
     * Takes a login provided from nsIEProfileMigrator, migrates it to the
     * current login manager format, and adds it to the list of stored logins.
     *
     * @param aLogin
     *        The login to be migrated.
     *
     * Note: In some cases, multiple logins may be created from a single input
     *       when the format is ambigious.
     *
     */
  /* void migrateAndAddLogin (in nsILoginInfo aLogin); */
  NS_SCRIPTABLE NS_IMETHOD MigrateAndAddLogin(nsILoginInfo *aLogin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginManagerIEMigrationHelper, NS_ILOGINMANAGERIEMIGRATIONHELPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMANAGERIEMIGRATIONHELPER \
  NS_SCRIPTABLE NS_IMETHOD MigrateAndAddLogin(nsILoginInfo *aLogin); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMANAGERIEMIGRATIONHELPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD MigrateAndAddLogin(nsILoginInfo *aLogin) { return _to MigrateAndAddLogin(aLogin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMANAGERIEMIGRATIONHELPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD MigrateAndAddLogin(nsILoginInfo *aLogin) { return !_to ? NS_ERROR_NULL_POINTER : _to->MigrateAndAddLogin(aLogin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginManagerIEMigrationHelper : public nsILoginManagerIEMigrationHelper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMANAGERIEMIGRATIONHELPER

  nsLoginManagerIEMigrationHelper();

private:
  ~nsLoginManagerIEMigrationHelper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoginManagerIEMigrationHelper, nsILoginManagerIEMigrationHelper)

nsLoginManagerIEMigrationHelper::nsLoginManagerIEMigrationHelper()
{
  /* member initializers and constructor code */
}

nsLoginManagerIEMigrationHelper::~nsLoginManagerIEMigrationHelper()
{
  /* destructor code */
}

/* void migrateAndAddLogin (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManagerIEMigrationHelper::MigrateAndAddLogin(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoginManagerIEMigrationHelper_h__ */
