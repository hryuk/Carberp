/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/cookie/public/nsICookiePermission.idl
 */

#ifndef __gen_nsICookiePermission_h__
#define __gen_nsICookiePermission_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICookie2; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

typedef PRInt32 nsCookieAccess;


/* starting interface:    nsICookiePermission */
#define NS_ICOOKIEPERMISSION_IID_STR "4b1a775d-f6d3-4389-be2e-9dfbaf2ab47b"

#define NS_ICOOKIEPERMISSION_IID \
  {0x4b1a775d, 0xf6d3, 0x4389, \
    { 0xbe, 0x2e, 0x9d, 0xfb, 0xaf, 0x2a, 0xb4, 0x7b }}

/**
 * An interface to test for cookie permissions
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICookiePermission : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOOKIEPERMISSION_IID)

  /**
   * nsCookieAccess values
   */
  enum { ACCESS_DEFAULT = 0 };

  enum { ACCESS_ALLOW = 1 };

  enum { ACCESS_DENY = 2 };

  /**
   * additional values for nsCookieAccess, which are not directly used by
   * any methods on this interface, but are nevertheless convenient to define
   * here. these may be relocated somewhere else if we ever consider freezing
   * this interface.
   */
  enum { ACCESS_SESSION = 8 };

  /**
   * setAccess
   *
   * this method is called to block cookie access for the given URI.  this
   * may result in other URIs being blocked as well (e.g., URIs which share
   * the same host name).
   *
   * @param aURI
   *        the URI to block
   * @param aAccess
   *        the new cookie access for the URI.
   */
  /* void setAccess (in nsIURI aURI, in nsCookieAccess aAccess); */
  NS_SCRIPTABLE NS_IMETHOD SetAccess(nsIURI *aURI, nsCookieAccess aAccess) = 0;

  /**
   * canAccess
   *
   * this method is called to test whether or not the given URI/channel may
   * access the cookie database, either to set or get cookies.
   *
   * @param aURI
   *        the URI trying to access cookies
   * @param aChannel
   *        the channel corresponding to aURI
   *
   * @return one of the following nsCookieAccess values:
   *         ACCESS_DEFAULT, ACCESS_ALLOW, or ACCESS_DENY
   */
  /* nsCookieAccess canAccess (in nsIURI aURI, in nsIChannel aChannel); */
  NS_SCRIPTABLE NS_IMETHOD CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval NS_OUTPARAM) = 0;

  /**
   * canSetCookie
   *
   * this method is called to test whether or not the given URI/channel may
   * set a specific cookie.  this method is always preceded by a call to
   * canAccess. it may modify the isSession and expiry attributes of the
   * cookie via the aIsSession and aExpiry parameters, in order to limit
   * or extend the lifetime of the cookie. this is useful, for instance, to
   * downgrade a cookie to session-only if it fails to meet certain criteria.
   *
   * @param aURI
   *        the URI trying to set the cookie
   * @param aChannel
   *        the channel corresponding to aURI
   * @param aCookie
   *        the cookie being added to the cookie database
   * @param aIsSession
   *        when canSetCookie is invoked, this is the current isSession attribute
   *        of the cookie. canSetCookie may leave this value unchanged to
   *        preserve this attribute of the cookie.
   * @param aExpiry
   *        when canSetCookie is invoked, this is the current expiry time of
   *        the cookie. canSetCookie may leave this value unchanged to
   *        preserve this attribute of the cookie.
   *
   * @return true if the cookie can be set.
   */
  /* boolean canSetCookie (in nsIURI aURI, in nsIChannel aChannel, in nsICookie2 aCookie, inout boolean aIsSession, inout PRInt64 aExpiry); */
  NS_SCRIPTABLE NS_IMETHOD CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, PRBool *aIsSession NS_INOUTPARAM, PRInt64 *aExpiry NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * getOriginatingURI
   *
   * determines the originating URI for a load given a channel, for third-party
   * cookie blocking. this is done by leveraging the loadgroup of the channel to
   * find the root content docshell, and the URI associated with its principal.
   * if the root content docshell or its principal's URI cannot be obtained,
   * this method will throw.
   *
   * @param aChannel
   *        the channel for the load trying to get or set cookies
   *
   * @return the originating URI.
   */
  /* nsIURI getOriginatingURI (in nsIChannel aChannel); */
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIChannel *aChannel, nsIURI **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICookiePermission, NS_ICOOKIEPERMISSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOOKIEPERMISSION \
  NS_SCRIPTABLE NS_IMETHOD SetAccess(nsIURI *aURI, nsCookieAccess aAccess); \
  NS_SCRIPTABLE NS_IMETHOD CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, PRBool *aIsSession NS_INOUTPARAM, PRInt64 *aExpiry NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIChannel *aChannel, nsIURI **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOOKIEPERMISSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetAccess(nsIURI *aURI, nsCookieAccess aAccess) { return _to SetAccess(aURI, aAccess); } \
  NS_SCRIPTABLE NS_IMETHOD CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval NS_OUTPARAM) { return _to CanAccess(aURI, aChannel, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, PRBool *aIsSession NS_INOUTPARAM, PRInt64 *aExpiry NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to CanSetCookie(aURI, aChannel, aCookie, aIsSession, aExpiry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIChannel *aChannel, nsIURI **_retval NS_OUTPARAM) { return _to GetOriginatingURI(aChannel, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOOKIEPERMISSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetAccess(nsIURI *aURI, nsCookieAccess aAccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccess(aURI, aAccess); } \
  NS_SCRIPTABLE NS_IMETHOD CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanAccess(aURI, aChannel, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, PRBool *aIsSession NS_INOUTPARAM, PRInt64 *aExpiry NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanSetCookie(aURI, aChannel, aCookie, aIsSession, aExpiry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIChannel *aChannel, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginatingURI(aChannel, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCookiePermission : public nsICookiePermission
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOOKIEPERMISSION

  nsCookiePermission();

private:
  ~nsCookiePermission();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCookiePermission, nsICookiePermission)

nsCookiePermission::nsCookiePermission()
{
  /* member initializers and constructor code */
}

nsCookiePermission::~nsCookiePermission()
{
  /* destructor code */
}

/* void setAccess (in nsIURI aURI, in nsCookieAccess aAccess); */
NS_IMETHODIMP nsCookiePermission::SetAccess(nsIURI *aURI, nsCookieAccess aAccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsCookieAccess canAccess (in nsIURI aURI, in nsIChannel aChannel); */
NS_IMETHODIMP nsCookiePermission::CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canSetCookie (in nsIURI aURI, in nsIChannel aChannel, in nsICookie2 aCookie, inout boolean aIsSession, inout PRInt64 aExpiry); */
NS_IMETHODIMP nsCookiePermission::CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, PRBool *aIsSession NS_INOUTPARAM, PRInt64 *aExpiry NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getOriginatingURI (in nsIChannel aChannel); */
NS_IMETHODIMP nsCookiePermission::GetOriginatingURI(nsIChannel *aChannel, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * The nsICookiePermission implementation is an XPCOM service registered
 * under the ContractID:
 */
#define NS_COOKIEPERMISSION_CONTRACTID "@mozilla.org/cookie/permission;1"

#endif /* __gen_nsICookiePermission_h__ */
