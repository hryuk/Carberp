/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/places/public/nsPIPlacesDatabase.idl
 */

#ifndef __gen_nsPIPlacesDatabase_h__
#define __gen_nsPIPlacesDatabase_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */


/* starting interface:    nsPIPlacesDatabase */
#define NS_PIPLACESDATABASE_IID_STR "8e6d4f8a-4b8e-4026-9fca-517c4494ddb7"

#define NS_PIPLACESDATABASE_IID \
  {0x8e6d4f8a, 0x4b8e, 0x4026, \
    { 0x9f, 0xca, 0x51, 0x7c, 0x44, 0x94, 0xdd, 0xb7 }}

/**
 * This is a private interface used by Places components to get access to the
 * database.  If outside consumers wish to use this, they should only read from
 * the database so they do not break any internal invariants.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsPIPlacesDatabase : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIPLACESDATABASE_IID)

  /**
   * The database connection used by Places.
   */
  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) = 0;

  /**
   * Finalizes all Places internal statements, allowing to safely close the
   * database connection.
   */
  /* void finalizeInternalStatements (); */
  NS_SCRIPTABLE NS_IMETHOD FinalizeInternalStatements(void) = 0;

  /**
   * Commits all pending history changes, call this before finalizing
   * statements and closing the database connection to ensure safety for all
   * history data.
   */
  /* void commitPendingChanges (); */
  NS_SCRIPTABLE NS_IMETHOD CommitPendingChanges(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIPlacesDatabase, NS_PIPLACESDATABASE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIPLACESDATABASE \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection); \
  NS_SCRIPTABLE NS_IMETHOD FinalizeInternalStatements(void); \
  NS_SCRIPTABLE NS_IMETHOD CommitPendingChanges(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIPLACESDATABASE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return _to GetDBConnection(aDBConnection); } \
  NS_SCRIPTABLE NS_IMETHOD FinalizeInternalStatements(void) { return _to FinalizeInternalStatements(); } \
  NS_SCRIPTABLE NS_IMETHOD CommitPendingChanges(void) { return _to CommitPendingChanges(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIPLACESDATABASE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } \
  NS_SCRIPTABLE NS_IMETHOD FinalizeInternalStatements(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FinalizeInternalStatements(); } \
  NS_SCRIPTABLE NS_IMETHOD CommitPendingChanges(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CommitPendingChanges(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIPlacesDatabase
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIPLACESDATABASE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIPlacesDatabase)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP _MYCLASS_::GetDBConnection(mozIStorageConnection * *aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finalizeInternalStatements (); */
NS_IMETHODIMP _MYCLASS_::FinalizeInternalStatements()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void commitPendingChanges (); */
NS_IMETHODIMP _MYCLASS_::CommitPendingChanges()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIPlacesDatabase_h__ */
