/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/contentprefs/public/nsIContentPrefService.idl
 */

#ifndef __gen_nsIContentPrefService_h__
#define __gen_nsIContentPrefService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIPropertyBag2; /* forward declaration */

class nsIContentURIGrouper; /* forward declaration */

class mozIStorageConnection; /* forward declaration */


/* starting interface:    nsIContentPrefObserver */
#define NS_ICONTENTPREFOBSERVER_IID_STR "746c7a02-f6c1-4869-b434-7c8b86e60e61"

#define NS_ICONTENTPREFOBSERVER_IID \
  {0x746c7a02, 0xf6c1, 0x4869, \
    { 0xb4, 0x34, 0x7c, 0x8b, 0x86, 0xe6, 0x0e, 0x61 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentPrefObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFOBSERVER_IID)

  /**
   * Called when a content pref is set to a different value.
   * 
   * @param    aGroup      the group to which the pref belongs, or null
   *                       if it's a global pref (applies to all URIs)
   * @param    aName       the name of the pref that was set
   * @param    aValue      the new value of the pref
   */
  /* void onContentPrefSet (in AString aGroup, in AString aName, in nsIVariant aValue); */
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue) = 0;

  /**
   * Called when a content pref is removed.
   * 
   * @param    aGroup      the group to which the pref belongs, or null
   *                       if it's a global pref (applies to all URIs)
   * @param    aName       the name of the pref that was removed
   */
  /* void onContentPrefRemoved (in AString aGroup, in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefObserver, NS_ICONTENTPREFOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue); \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue) { return _to OnContentPrefSet(aGroup, aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName) { return _to OnContentPrefRemoved(aGroup, aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContentPrefSet(aGroup, aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContentPrefRemoved(aGroup, aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPrefObserver : public nsIContentPrefObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPREFOBSERVER

  nsContentPrefObserver();

private:
  ~nsContentPrefObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPrefObserver, nsIContentPrefObserver)

nsContentPrefObserver::nsContentPrefObserver()
{
  /* member initializers and constructor code */
}

nsContentPrefObserver::~nsContentPrefObserver()
{
  /* destructor code */
}

/* void onContentPrefSet (in AString aGroup, in AString aName, in nsIVariant aValue); */
NS_IMETHODIMP nsContentPrefObserver::OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onContentPrefRemoved (in AString aGroup, in AString aName); */
NS_IMETHODIMP nsContentPrefObserver::OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPrefService */
#define NS_ICONTENTPREFSERVICE_IID_STR "5047e359-dfda-4858-abec-d145c7463250"

#define NS_ICONTENTPREFSERVICE_IID \
  {0x5047e359, 0xdfda, 0x4858, \
    { 0xab, 0xec, 0xd1, 0x45, 0xc7, 0x46, 0x32, 0x50 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentPrefService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFSERVICE_IID)

  /**
   * Get a pref.
   *
   * Besides the regular string, integer, boolean, etc. values, this method
   * may return null (nsIDataType::VTYPE_EMPTY), which means the pref is set
   * to NULL in the database, as well as undefined (nsIDataType::VTYPE_VOID),
   * which means there is no record for this pref in the database.
   *
   * @param    aURI        the URI for which to get the pref, or null to get
   *                       the global pref (applies to all URIs)
   * @param    aName       the name of the pref to get
   *
   * @returns  the value of the pref
   */
  /* nsIVariant getPref (in nsIURI aURI, in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD GetPref(nsIURI *aURI, const nsAString & aName, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
   * Set a pref.
   *
   * @param    aURI        the URI for which to set the pref, or null to set
   *                       the global pref (applies to all URIs)
   * @param    aName       the name of the pref to set
   * @param    aValue      the new value of the pref
   */
  /* void setPref (in nsIURI aURI, in AString aName, in nsIVariant aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetPref(nsIURI *aURI, const nsAString & aName, nsIVariant *aValue) = 0;

  /**
   * Check whether or not a pref exists.
   *
   * @param    aURI        the URI for which to check for the pref
   * @param    aName       the name of the pref to check for
   */
  /* boolean hasPref (in nsIURI aURI, in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD HasPref(nsIURI *aURI, const nsAString & aName, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Remove a pref.
   *
   * @param    aURI        the URI for which to remove the pref
   * @param    aName       the name of the pref to remove
   */
  /* void removePref (in nsIURI aURI, in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD RemovePref(nsIURI *aURI, const nsAString & aName) = 0;

  /**
   * Remove all grouped prefs.  Useful for removing references to the sites
   * the user has visited when the user clears their private data.
   */
  /* void removeGroupedPrefs (); */
  NS_SCRIPTABLE NS_IMETHOD RemoveGroupedPrefs(void) = 0;

  /**
   * Get the prefs that apply to the given URI.
   *
   * @param    aURI        the URI for which to retrieve prefs
   * 
   * @returns  a property bag of prefs
   */
  /* nsIPropertyBag2 getPrefs (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(nsIURI *aURI, nsIPropertyBag2 **_retval NS_OUTPARAM) = 0;

  /**
   * Add an observer.
   * 
   * @param    aName       the setting to observe, or null to add
   *                       a generic observer that observes all settings
   * @param    aObserver   the observer to add
   */
  /* void addObserver (in AString aName, in nsIContentPrefObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) = 0;

  /**
   * Remove an observer.
   *
   * @param    aName       the setting being observed, or null to remove
   *                       a generic observer that observes all settings
   * @param    aObserver   the observer to remove
   */
  /* void removeObserver (in AString aName, in nsIContentPrefObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) = 0;

  /**
   * The component that the service uses to determine the groups to which
   * URIs belong.  By default this is the "hostname grouper", which groups
   * URIs by full hostname (a.k.a. site).
   */
  /* readonly attribute nsIContentURIGrouper grouper; */
  NS_SCRIPTABLE NS_IMETHOD GetGrouper(nsIContentURIGrouper * *aGrouper) = 0;

  /**
   * The database connection to the content preferences database.
   * Useful for accessing and manipulating preferences in ways that are caller-
   * specific or for which there is not yet a generic method, although generic
   * functionality useful to multiple callers should generally be added to this
   * unfrozen interface.  Also useful for testing the database creation
   * and migration code.
   */
  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefService, NS_ICONTENTPREFSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetPref(nsIURI *aURI, const nsAString & aName, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetPref(nsIURI *aURI, const nsAString & aName, nsIVariant *aValue); \
  NS_SCRIPTABLE NS_IMETHOD HasPref(nsIURI *aURI, const nsAString & aName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemovePref(nsIURI *aURI, const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD RemoveGroupedPrefs(void); \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(nsIURI *aURI, nsIPropertyBag2 **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD GetGrouper(nsIContentURIGrouper * *aGrouper); \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPref(nsIURI *aURI, const nsAString & aName, nsIVariant **_retval NS_OUTPARAM) { return _to GetPref(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetPref(nsIURI *aURI, const nsAString & aName, nsIVariant *aValue) { return _to SetPref(aURI, aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD HasPref(nsIURI *aURI, const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return _to HasPref(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePref(nsIURI *aURI, const nsAString & aName) { return _to RemovePref(aURI, aName); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveGroupedPrefs(void) { return _to RemoveGroupedPrefs(); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(nsIURI *aURI, nsIPropertyBag2 **_retval NS_OUTPARAM) { return _to GetPrefs(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return _to AddObserver(aName, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return _to RemoveObserver(aName, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetGrouper(nsIContentURIGrouper * *aGrouper) { return _to GetGrouper(aGrouper); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return _to GetDBConnection(aDBConnection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPref(nsIURI *aURI, const nsAString & aName, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPref(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetPref(nsIURI *aURI, const nsAString & aName, nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPref(aURI, aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD HasPref(nsIURI *aURI, const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPref(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePref(nsIURI *aURI, const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePref(aURI, aName); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveGroupedPrefs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveGroupedPrefs(); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(nsIURI *aURI, nsIPropertyBag2 **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefs(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aName, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aName, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetGrouper(nsIContentURIGrouper * *aGrouper) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGrouper(aGrouper); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPrefService : public nsIContentPrefService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPREFSERVICE

  nsContentPrefService();

private:
  ~nsContentPrefService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPrefService, nsIContentPrefService)

nsContentPrefService::nsContentPrefService()
{
  /* member initializers and constructor code */
}

nsContentPrefService::~nsContentPrefService()
{
  /* destructor code */
}

/* nsIVariant getPref (in nsIURI aURI, in AString aName); */
NS_IMETHODIMP nsContentPrefService::GetPref(nsIURI *aURI, const nsAString & aName, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPref (in nsIURI aURI, in AString aName, in nsIVariant aValue); */
NS_IMETHODIMP nsContentPrefService::SetPref(nsIURI *aURI, const nsAString & aName, nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasPref (in nsIURI aURI, in AString aName); */
NS_IMETHODIMP nsContentPrefService::HasPref(nsIURI *aURI, const nsAString & aName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePref (in nsIURI aURI, in AString aName); */
NS_IMETHODIMP nsContentPrefService::RemovePref(nsIURI *aURI, const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeGroupedPrefs (); */
NS_IMETHODIMP nsContentPrefService::RemoveGroupedPrefs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPropertyBag2 getPrefs (in nsIURI aURI); */
NS_IMETHODIMP nsContentPrefService::GetPrefs(nsIURI *aURI, nsIPropertyBag2 **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in AString aName, in nsIContentPrefObserver aObserver); */
NS_IMETHODIMP nsContentPrefService::AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in AString aName, in nsIContentPrefObserver aObserver); */
NS_IMETHODIMP nsContentPrefService::RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIContentURIGrouper grouper; */
NS_IMETHODIMP nsContentPrefService::GetGrouper(nsIContentURIGrouper * *aGrouper)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP nsContentPrefService::GetDBConnection(mozIStorageConnection * *aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentPrefService_h__ */
