/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/passwordmgr/public/nsILoginManagerStorage.idl
 */

#ifndef __gen_nsILoginManagerStorage_h__
#define __gen_nsILoginManagerStorage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsILoginInfo; /* forward declaration */

class nsIPropertyBag; /* forward declaration */


/* starting interface:    nsILoginManagerStorage */
#define NS_ILOGINMANAGERSTORAGE_IID_STR "e66c97cd-3bcf-4eee-9937-38f650372d77"

#define NS_ILOGINMANAGERSTORAGE_IID \
  {0xe66c97cd, 0x3bcf, 0x4eee, \
    { 0x99, 0x37, 0x38, 0xf6, 0x50, 0x37, 0x2d, 0x77 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsILoginManagerStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMANAGERSTORAGE_IID)

  /**
     * Initialize the component. Not invoked automatically.
     */
  /* void init (); */
  NS_SCRIPTABLE NS_IMETHOD Init(void) = 0;

  /**
     * Initialize the component, but override the default filename
     * locations. This is primarily used to the unit tests and profile
     * migration.
     *
     * @param aInputFile
     *        File to read for stored logins.
     * @param aOutputFile
     *        If non-null, file to output logins to.
     *
     */
  /* void initWithFile (in nsIFile aInputFile, in nsIFile aOutputFile); */
  NS_SCRIPTABLE NS_IMETHOD InitWithFile(nsIFile *aInputFile, nsIFile *aOutputFile) = 0;

  /**
     * Store a new login in the storage module.
     *
     * @param aLogin
     *        The login to be added.
     *
     * Default values for the login's nsILoginMetaInfo properties will be
     * created. However, if the caller specifies non-default values, they will
     * be used instead.
     */
  /* void addLogin (in nsILoginInfo aLogin); */
  NS_SCRIPTABLE NS_IMETHOD AddLogin(nsILoginInfo *aLogin) = 0;

  /**
     * Remove a login from the storage module.
     *
     * @param aLogin
     *        The login to be removed.
     *
     * The specified login must exactly match a stored login. However, the
     * values of any nsILoginMetaInfo properties are ignored.
     */
  /* void removeLogin (in nsILoginInfo aLogin); */
  NS_SCRIPTABLE NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) = 0;

  /**
     * Modify an existing login in the storage module.
     *
     * @param oldLogin
     *        The login to be modified.
     * @param newLoginData
     *        The new login values (either a nsILoginInfo or nsIProperyBag)
     *
     * If newLoginData is a nsILoginInfo, all of the old login's nsILoginInfo
     * properties are changed to the values from newLoginData (but the old
     * login's nsILoginMetaInfo properties are unmodified).
     *
     * If newLoginData is a nsIPropertyBag, only the specified properties
     * will be changed. The nsILoginMetaInfo properties of oldLogin can be
     * changed in this manner.
     */
  /* void modifyLogin (in nsILoginInfo oldLogin, in nsISupports newLoginData); */
  NS_SCRIPTABLE NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) = 0;

  /**
     * Remove all stored logins.
     *
     * The browser sanitization feature allows the user to clear any stored
     * passwords. This interface allows that to be done without getting each
     * login first (which might require knowing the master password).
     *
     */
  /* void removeAllLogins (); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAllLogins(void) = 0;

  /**
     * Fetch all logins in the login manager. An array is always returned;
     * if there are no logins the array is empty.
     *
     * @param count
     *        The number of elements in the array. JS callers can simply use
     *        the array's .length property, and supply an dummy object for
     *        this out param. For example: |getAllLogins({})|
     * @param logins
     *        An array of nsILoginInfo objects. 
     *
     * NOTE: This can be called from JS as:
     *       var logins = pwmgr.getAllLogins({});
     *       (|logins| is an array).
     */
  /* void getAllLogins (out unsigned long count, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_SCRIPTABLE NS_IMETHOD GetAllLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM) = 0;

  /**
    * Fetch all logins in the login manager. An array is always returned;
    * if there are no logins the array is empty. This does not decrypt logins
    * before returning the array
    *
    * @param count
    *        The number of elements in the array. JS callers can simply use
    *        the array's .length property, and supply an dummy object for
    *        this out param. For example: |getAllEncryptedLogins({})|
    * @param logins
    *        An array of nsILoginInfo objects. 
    *
    * NOTE: This can be called from JS as:
    *       var logins = pwmgr.getAllEncryptedLogins({});
    *       (|logins| is an array).
    */
  /* void getAllEncryptedLogins (out unsigned long count, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_SCRIPTABLE NS_IMETHOD GetAllEncryptedLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM) = 0;

  /**
     * Search for logins in the login manager. An array is always returned;
     * if there are no logins the array is empty.
     *
     * @param count
     *        The number of elements in the array. JS callers can simply use
     *        the array's .length property, and supply an dummy object for
     *        this out param. For example: |searchLogins({}, matchData)|
     * @param matchData
     *        The data used to search. This does not follow the same
     *        requirements as findLogins for those fields. Wildcard matches are
     *        simply not specified.
     * @param logins
     *        An array of nsILoginInfo objects.
     *
     * NOTE: This can be called from JS as:
     *       var logins = pwmgr.searchLogins({}, matchData);
     *       (|logins| is an array).
     */
  /* void searchLogins (out unsigned long count, in nsIPropertyBag matchData, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_SCRIPTABLE NS_IMETHOD SearchLogins(PRUint32 *count NS_OUTPARAM, nsIPropertyBag *matchData, nsILoginInfo ***logins NS_OUTPARAM) = 0;

  /**
     * Obtain a list of all hosts for which password saving is disabled.
     *
     * @param count
     *        The number of elements in the array. JS callers can simply use
     *        the array's .length property, and supply an dummy object for
     *        this out param. For example: |getAllDisabledHosts({})|
     * @param hostnames
     *        An array of hostname strings, in origin URL format without a
     *        pathname. For example: "https://www.site.com".
     *
     * NOTE: This can be called from JS as:
     *       var logins = pwmgr.getAllDisabledHosts({});
     */
  /* void getAllDisabledHosts (out unsigned long count, [array, size_is (count), retval] out wstring hostnames); */
  NS_SCRIPTABLE NS_IMETHOD GetAllDisabledHosts(PRUint32 *count NS_OUTPARAM, PRUnichar ***hostnames NS_OUTPARAM) = 0;

  /**
     * Check to see if saving logins has been disabled for a host.
     *
     * @param aHost
     *        The hostname to check. This argument should be in the origin
     *        URL format, without a pathname. For example: "http://foo.com".
     */
  /* boolean getLoginSavingEnabled (in AString aHost); */
  NS_SCRIPTABLE NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Disable (or enable) storing logins for the specified host. When
     * disabled, the login manager will not prompt to store logins for
     * that host. Existing logins are not affected.
     *
     * @param aHost
     *        The hostname to set. This argument should be in the origin
     *        URL format, without a pathname. For example: "http://foo.com".
     * @param isEnabled
     *        Specify if saving logins should be enabled (true) or
     *        disabled (false)
     */
  /* void setLoginSavingEnabled (in AString aHost, in boolean isEnabled); */
  NS_SCRIPTABLE NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, PRBool isEnabled) = 0;

  /**
     * Search for logins matching the specified criteria. Called when looking
     * for logins that might be applicable to a form or authentication request.
     *
     * @param count
     *        The number of elements in the array. JS callers can simply use
     *        the array's .length property, and supply an dummy object for
     *        this out param. For example: |findLogins({}, hostname, ...)|
     * @param aHostname
     *        The hostname to restrict searches to, in URL format. For
     *        example: "http://www.site.com".
     * @param aActionURL
     *        For form logins, this argument should be the URL to which the
     *        form will be submitted. For protocol logins, specify null.
     * @param aHttpRealm
     *        For protocol logins, this argument should be the HTTP Realm
     *        for which the login applies. This is obtained from the
     *        WWW-Authenticate header. See RFC2617. For form logins,
     *        specify null.
     * @param logins
     *        An array of nsILoginInfo objects. 
     *
     * NOTE: This can be called from JS as:
     *       var logins = pwmgr.findLogins({}, hostname, ...);
     *
     */
  /* void findLogins (out unsigned long count, in AString aHostname, in AString aActionURL, in AString aHttpRealm, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_SCRIPTABLE NS_IMETHOD FindLogins(PRUint32 *count NS_OUTPARAM, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo ***logins NS_OUTPARAM) = 0;

  /**
    * Search for logins matching the specified criteria, as with
    * findLogins(). This interface only returns the number of matching
    * logins (and not the logins themselves), which allows a caller to
    * check for logins without causing the user to be prompted for a master
    * password to decrypt the logins.
    *
    * @param aHostname
    *        The hostname to restrict searches to. Specify an empty string
    *        to match all hosts. A null value will not match any logins, and
    *        will thus always return a count of 0.
    * @param aActionURL
    *        The URL to which a form login will be submitted. To match any
    *        form login, specify an empty string. To not match any form
    *        login, specify null.
    * @param aHttpRealm
    *        The HTTP Realm for which the login applies. To match logins for
    *        any realm, specify an empty string. To not match logins for any
    *        realm, specify null.
    */
  /* unsigned long countLogins (in AString aHostname, in AString aActionURL, in AString aHttpRealm); */
  NS_SCRIPTABLE NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginManagerStorage, NS_ILOGINMANAGERSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMANAGERSTORAGE \
  NS_SCRIPTABLE NS_IMETHOD Init(void); \
  NS_SCRIPTABLE NS_IMETHOD InitWithFile(nsIFile *aInputFile, nsIFile *aOutputFile); \
  NS_SCRIPTABLE NS_IMETHOD AddLogin(nsILoginInfo *aLogin); \
  NS_SCRIPTABLE NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin); \
  NS_SCRIPTABLE NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllLogins(void); \
  NS_SCRIPTABLE NS_IMETHOD GetAllLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAllEncryptedLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SearchLogins(PRUint32 *count NS_OUTPARAM, nsIPropertyBag *matchData, nsILoginInfo ***logins NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAllDisabledHosts(PRUint32 *count NS_OUTPARAM, PRUnichar ***hostnames NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, PRBool isEnabled); \
  NS_SCRIPTABLE NS_IMETHOD FindLogins(PRUint32 *count NS_OUTPARAM, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo ***logins NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMANAGERSTORAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return _to Init(); } \
  NS_SCRIPTABLE NS_IMETHOD InitWithFile(nsIFile *aInputFile, nsIFile *aOutputFile) { return _to InitWithFile(aInputFile, aOutputFile); } \
  NS_SCRIPTABLE NS_IMETHOD AddLogin(nsILoginInfo *aLogin) { return _to AddLogin(aLogin); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) { return _to RemoveLogin(aLogin); } \
  NS_SCRIPTABLE NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) { return _to ModifyLogin(oldLogin, newLoginData); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllLogins(void) { return _to RemoveAllLogins(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM) { return _to GetAllLogins(count, logins); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllEncryptedLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM) { return _to GetAllEncryptedLogins(count, logins); } \
  NS_SCRIPTABLE NS_IMETHOD SearchLogins(PRUint32 *count NS_OUTPARAM, nsIPropertyBag *matchData, nsILoginInfo ***logins NS_OUTPARAM) { return _to SearchLogins(count, matchData, logins); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllDisabledHosts(PRUint32 *count NS_OUTPARAM, PRUnichar ***hostnames NS_OUTPARAM) { return _to GetAllDisabledHosts(count, hostnames); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, PRBool *_retval NS_OUTPARAM) { return _to GetLoginSavingEnabled(aHost, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, PRBool isEnabled) { return _to SetLoginSavingEnabled(aHost, isEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD FindLogins(PRUint32 *count NS_OUTPARAM, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo ***logins NS_OUTPARAM) { return _to FindLogins(count, aHostname, aActionURL, aHttpRealm, logins); } \
  NS_SCRIPTABLE NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, PRUint32 *_retval NS_OUTPARAM) { return _to CountLogins(aHostname, aActionURL, aHttpRealm, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMANAGERSTORAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_SCRIPTABLE NS_IMETHOD InitWithFile(nsIFile *aInputFile, nsIFile *aOutputFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithFile(aInputFile, aOutputFile); } \
  NS_SCRIPTABLE NS_IMETHOD AddLogin(nsILoginInfo *aLogin) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddLogin(aLogin); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveLogin(aLogin); } \
  NS_SCRIPTABLE NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) { return !_to ? NS_ERROR_NULL_POINTER : _to->ModifyLogin(oldLogin, newLoginData); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllLogins(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllLogins(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllLogins(count, logins); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllEncryptedLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllEncryptedLogins(count, logins); } \
  NS_SCRIPTABLE NS_IMETHOD SearchLogins(PRUint32 *count NS_OUTPARAM, nsIPropertyBag *matchData, nsILoginInfo ***logins NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchLogins(count, matchData, logins); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllDisabledHosts(PRUint32 *count NS_OUTPARAM, PRUnichar ***hostnames NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllDisabledHosts(count, hostnames); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoginSavingEnabled(aHost, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, PRBool isEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoginSavingEnabled(aHost, isEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD FindLogins(PRUint32 *count NS_OUTPARAM, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo ***logins NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindLogins(count, aHostname, aActionURL, aHttpRealm, logins); } \
  NS_SCRIPTABLE NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CountLogins(aHostname, aActionURL, aHttpRealm, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginManagerStorage : public nsILoginManagerStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMANAGERSTORAGE

  nsLoginManagerStorage();

private:
  ~nsLoginManagerStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoginManagerStorage, nsILoginManagerStorage)

nsLoginManagerStorage::nsLoginManagerStorage()
{
  /* member initializers and constructor code */
}

nsLoginManagerStorage::~nsLoginManagerStorage()
{
  /* destructor code */
}

/* void init (); */
NS_IMETHODIMP nsLoginManagerStorage::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithFile (in nsIFile aInputFile, in nsIFile aOutputFile); */
NS_IMETHODIMP nsLoginManagerStorage::InitWithFile(nsIFile *aInputFile, nsIFile *aOutputFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addLogin (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManagerStorage::AddLogin(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeLogin (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManagerStorage::RemoveLogin(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void modifyLogin (in nsILoginInfo oldLogin, in nsISupports newLoginData); */
NS_IMETHODIMP nsLoginManagerStorage::ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllLogins (); */
NS_IMETHODIMP nsLoginManagerStorage::RemoveAllLogins()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllLogins (out unsigned long count, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManagerStorage::GetAllLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllEncryptedLogins (out unsigned long count, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManagerStorage::GetAllEncryptedLogins(PRUint32 *count NS_OUTPARAM, nsILoginInfo ***logins NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void searchLogins (out unsigned long count, in nsIPropertyBag matchData, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManagerStorage::SearchLogins(PRUint32 *count NS_OUTPARAM, nsIPropertyBag *matchData, nsILoginInfo ***logins NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllDisabledHosts (out unsigned long count, [array, size_is (count), retval] out wstring hostnames); */
NS_IMETHODIMP nsLoginManagerStorage::GetAllDisabledHosts(PRUint32 *count NS_OUTPARAM, PRUnichar ***hostnames NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getLoginSavingEnabled (in AString aHost); */
NS_IMETHODIMP nsLoginManagerStorage::GetLoginSavingEnabled(const nsAString & aHost, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLoginSavingEnabled (in AString aHost, in boolean isEnabled); */
NS_IMETHODIMP nsLoginManagerStorage::SetLoginSavingEnabled(const nsAString & aHost, PRBool isEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findLogins (out unsigned long count, in AString aHostname, in AString aActionURL, in AString aHttpRealm, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManagerStorage::FindLogins(PRUint32 *count NS_OUTPARAM, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo ***logins NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long countLogins (in AString aHostname, in AString aActionURL, in AString aHttpRealm); */
NS_IMETHODIMP nsLoginManagerStorage::CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoginManagerStorage_h__ */
