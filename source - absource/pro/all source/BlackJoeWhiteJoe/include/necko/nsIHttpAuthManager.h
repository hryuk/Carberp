/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/protocol/http/public/nsIHttpAuthManager.idl
 */

#ifndef __gen_nsIHttpAuthManager_h__
#define __gen_nsIHttpAuthManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHttpAuthManager */
#define NS_IHTTPAUTHMANAGER_IID_STR "7ce8e9d1-8b4b-4883-a307-66fe12a50153"

#define NS_IHTTPAUTHMANAGER_IID \
  {0x7ce8e9d1, 0x8b4b, 0x4883, \
    { 0xa3, 0x07, 0x66, 0xfe, 0x12, 0xa5, 0x01, 0x53 }}

/**
 * nsIHttpAuthManager
 *
 * This service provides access to cached HTTP authentication 
 * user credentials (domain, username, password) for sites
 * visited during the current browser session.
 *
 * This interface exists to provide other HTTP stacks with the
 * ability to share HTTP authentication credentials with Necko.
 * This is currently used by the Java plugin (version 1.5 and
 * higher) to avoid duplicate authentication prompts when the
 * Java client fetches content from a HTTP site that the user
 * has already logged into.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIHttpAuthManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPAUTHMANAGER_IID)

  /**
     * Lookup auth identity.
     *
     * @param aScheme
     *        the URL scheme (e.g., "http").  NOTE: for proxy authentication,
     *        this should be "http" (this includes authentication for SSL
     *        tunneling).
     * @param aHost
     *        the host of the server issuing a challenge (ASCII only).
     * @param aPort
     *        the port of the server issuing a challenge.
     * @param aAuthType
     *        optional string identifying auth type used (e.g., "basic")
     * @param aRealm
     *        optional string identifying auth realm.
     * @param aPath
     *        optional string identifying auth path. empty for proxy auth.
     * @param aUserDomain
     *        return value containing user domain.
     * @param aUserName
     *        return value containing user name.
     * @param aUserPassword
     *        return value containing user password.
     */
  /* void getAuthIdentity (in ACString aScheme, in ACString aHost, in PRInt32 aPort, in ACString aAuthType, in ACString aRealm, in ACString aPath, out AString aUserDomain, out AString aUserName, out AString aUserPassword); */
  NS_SCRIPTABLE NS_IMETHOD GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain NS_OUTPARAM, nsAString & aUserName NS_OUTPARAM, nsAString & aUserPassword NS_OUTPARAM) = 0;

  /**
     * Store auth identity.
     *
     * @param aScheme
     *        the URL scheme (e.g., "http").  NOTE: for proxy authentication,
     *        this should be "http" (this includes authentication for SSL
     *        tunneling).
     * @param aHost
     *        the host of the server issuing a challenge (ASCII only).
     * @param aPort
     *        the port of the server issuing a challenge.
     * @param aAuthType
     *        optional string identifying auth type used (e.g., "basic")
     * @param aRealm
     *        optional string identifying auth realm.
     * @param aPath
     *        optional string identifying auth path. empty for proxy auth.
     * @param aUserDomain
     *        optional string containing user domain.
     * @param aUserName
     *        optional string containing user name.
     * @param aUserPassword
     *        optional string containing user password.
     */
  /* void setAuthIdentity (in ACString aScheme, in ACString aHost, in PRInt32 aPort, in ACString aAuthType, in ACString aRealm, in ACString aPath, in AString aUserDomain, in AString aUserName, in AString aUserPassword); */
  NS_SCRIPTABLE NS_IMETHOD SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword) = 0;

  /**
     * Clear all auth cache.
     */
  /* void clearAll (); */
  NS_SCRIPTABLE NS_IMETHOD ClearAll(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpAuthManager, NS_IHTTPAUTHMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPAUTHMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain NS_OUTPARAM, nsAString & aUserName NS_OUTPARAM, nsAString & aUserPassword NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword); \
  NS_SCRIPTABLE NS_IMETHOD ClearAll(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPAUTHMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain NS_OUTPARAM, nsAString & aUserName NS_OUTPARAM, nsAString & aUserPassword NS_OUTPARAM) { return _to GetAuthIdentity(aScheme, aHost, aPort, aAuthType, aRealm, aPath, aUserDomain, aUserName, aUserPassword); } \
  NS_SCRIPTABLE NS_IMETHOD SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword) { return _to SetAuthIdentity(aScheme, aHost, aPort, aAuthType, aRealm, aPath, aUserDomain, aUserName, aUserPassword); } \
  NS_SCRIPTABLE NS_IMETHOD ClearAll(void) { return _to ClearAll(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPAUTHMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain NS_OUTPARAM, nsAString & aUserName NS_OUTPARAM, nsAString & aUserPassword NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthIdentity(aScheme, aHost, aPort, aAuthType, aRealm, aPath, aUserDomain, aUserName, aUserPassword); } \
  NS_SCRIPTABLE NS_IMETHOD SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAuthIdentity(aScheme, aHost, aPort, aAuthType, aRealm, aPath, aUserDomain, aUserName, aUserPassword); } \
  NS_SCRIPTABLE NS_IMETHOD ClearAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearAll(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpAuthManager : public nsIHttpAuthManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPAUTHMANAGER

  nsHttpAuthManager();

private:
  ~nsHttpAuthManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpAuthManager, nsIHttpAuthManager)

nsHttpAuthManager::nsHttpAuthManager()
{
  /* member initializers and constructor code */
}

nsHttpAuthManager::~nsHttpAuthManager()
{
  /* destructor code */
}

/* void getAuthIdentity (in ACString aScheme, in ACString aHost, in PRInt32 aPort, in ACString aAuthType, in ACString aRealm, in ACString aPath, out AString aUserDomain, out AString aUserName, out AString aUserPassword); */
NS_IMETHODIMP nsHttpAuthManager::GetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, nsAString & aUserDomain NS_OUTPARAM, nsAString & aUserName NS_OUTPARAM, nsAString & aUserPassword NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAuthIdentity (in ACString aScheme, in ACString aHost, in PRInt32 aPort, in ACString aAuthType, in ACString aRealm, in ACString aPath, in AString aUserDomain, in AString aUserName, in AString aUserPassword); */
NS_IMETHODIMP nsHttpAuthManager::SetAuthIdentity(const nsACString & aScheme, const nsACString & aHost, PRInt32 aPort, const nsACString & aAuthType, const nsACString & aRealm, const nsACString & aPath, const nsAString & aUserDomain, const nsAString & aUserName, const nsAString & aUserPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearAll (); */
NS_IMETHODIMP nsHttpAuthManager::ClearAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpAuthManager_h__ */
