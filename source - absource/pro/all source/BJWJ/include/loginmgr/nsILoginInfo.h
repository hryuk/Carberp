/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/passwordmgr/public/nsILoginInfo.idl
 */

#ifndef __gen_nsILoginInfo_h__
#define __gen_nsILoginInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILoginInfo */
#define NS_ILOGININFO_IID_STR "c41b7dff-6b9b-42fe-b78d-113051facb05"

#define NS_ILOGININFO_IID \
  {0xc41b7dff, 0x6b9b, 0x42fe, \
    { 0xb7, 0x8d, 0x11, 0x30, 0x51, 0xfa, 0xcb, 0x05 }}

/**
 * An object containing information for a login stored by the
 * password manager.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsILoginInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGININFO_IID)

  /**
     * The hostname the login applies to.
     *
     * The hostname should be formatted as an URL. For example,
     * "https://site.com", "http://site.com:1234", "ftp://ftp.site.com".
     */
  /* attribute AString hostname; */
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname) = 0;

  /**
     * The URL a form-based login was submitted to.
     *
     * For logins obtained from HTML forms, this field is the |action|
     * attribute from the |form| element, with the path removed. For
     * example "http://www.site.com". [Forms with no |action| attribute
     * default to submitting to their origin URL, so we store that.]
     *
     * For logins obtained from a HTTP or FTP protocol authentication,
     * this field is NULL.
     */
  /* attribute AString formSubmitURL; */
  NS_SCRIPTABLE NS_IMETHOD GetFormSubmitURL(nsAString & aFormSubmitURL) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFormSubmitURL(const nsAString & aFormSubmitURL) = 0;

  /**
     * The HTTP Realm a login was requested for.
     *
     * When an HTTP server sends a 401 result, the WWW-Authenticate
     * header includes a realm to identify the "protection space." See
     * RFC2617. If the response sent has a missing or blank realm, the
     * hostname is used instead.
     *
     * For logins obtained from HTML forms, this field is NULL.
     */
  /* attribute AString httpRealm; */
  NS_SCRIPTABLE NS_IMETHOD GetHttpRealm(nsAString & aHttpRealm) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHttpRealm(const nsAString & aHttpRealm) = 0;

  /**
     * The username for the login.
     */
  /* attribute AString username; */
  NS_SCRIPTABLE NS_IMETHOD GetUsername(nsAString & aUsername) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUsername(const nsAString & aUsername) = 0;

  /**
     * The |name| attribute for the username input field.
     *
     * For logins obtained from a HTTP or FTP protocol authentication,
     * this field is an empty string.
     */
  /* attribute AString usernameField; */
  NS_SCRIPTABLE NS_IMETHOD GetUsernameField(nsAString & aUsernameField) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUsernameField(const nsAString & aUsernameField) = 0;

  /**
     * The password for the login.
     */
  /* attribute AString password; */
  NS_SCRIPTABLE NS_IMETHOD GetPassword(nsAString & aPassword) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPassword(const nsAString & aPassword) = 0;

  /**
     * The |name| attribute for the password input field.
     *
     * For logins obtained from a HTTP or FTP protocol authentication,
     * this field is an empty string.
     */
  /* attribute AString passwordField; */
  NS_SCRIPTABLE NS_IMETHOD GetPasswordField(nsAString & aPasswordField) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPasswordField(const nsAString & aPasswordField) = 0;

  /**
     * Initialize a newly created nsLoginInfo object.
     *
     * The arguments are the fields for the new object.
     */
  /* void init (in AString aHostname, in AString aFormSubmitURL, in AString aHttpRealm, in AString aUsername, in AString aPassword, in AString aUsernameField, in AString aPasswordField); */
  NS_SCRIPTABLE NS_IMETHOD Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField) = 0;

  /**
     * Test for strict equality with another nsILoginInfo object.
     *
     * @param aLoginInfo
     *        The other object to test.
     */
  /* boolean equals (in nsILoginInfo aLoginInfo); */
  NS_SCRIPTABLE NS_IMETHOD Equals(nsILoginInfo *aLoginInfo, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Test for loose equivalency with another nsILoginInfo object. The
     * passwordField and usernameField values are ignored, and the password
     * values may be optionally ignored. If one login's formSubmitURL is an
     * empty string (but not null), it will be treated as a wildcard. [The
     * blank value indicates the login was stored before bug 360493 was fixed.]
     *
     * @param aLoginInfo
     *        The other object to test.
     * @param ignorePassword
     *        If true, ignore the password when checking for match.
     */
  /* boolean matches (in nsILoginInfo aLoginInfo, in boolean ignorePassword); */
  NS_SCRIPTABLE NS_IMETHOD Matches(nsILoginInfo *aLoginInfo, PRBool ignorePassword, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Create an identical copy of the login, duplicating all of the login's
     * nsILoginInfo and nsILoginMetaInfo properties.
     *
     * This allows code to be forwards-compatible, when additional properties
     * are added to nsILoginMetaInfo (or nsILoginInfo) in the future.
     */
  /* nsILoginInfo clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsILoginInfo **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginInfo, NS_ILOGININFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGININFO \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname); \
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname); \
  NS_SCRIPTABLE NS_IMETHOD GetFormSubmitURL(nsAString & aFormSubmitURL); \
  NS_SCRIPTABLE NS_IMETHOD SetFormSubmitURL(const nsAString & aFormSubmitURL); \
  NS_SCRIPTABLE NS_IMETHOD GetHttpRealm(nsAString & aHttpRealm); \
  NS_SCRIPTABLE NS_IMETHOD SetHttpRealm(const nsAString & aHttpRealm); \
  NS_SCRIPTABLE NS_IMETHOD GetUsername(nsAString & aUsername); \
  NS_SCRIPTABLE NS_IMETHOD SetUsername(const nsAString & aUsername); \
  NS_SCRIPTABLE NS_IMETHOD GetUsernameField(nsAString & aUsernameField); \
  NS_SCRIPTABLE NS_IMETHOD SetUsernameField(const nsAString & aUsernameField); \
  NS_SCRIPTABLE NS_IMETHOD GetPassword(nsAString & aPassword); \
  NS_SCRIPTABLE NS_IMETHOD SetPassword(const nsAString & aPassword); \
  NS_SCRIPTABLE NS_IMETHOD GetPasswordField(nsAString & aPasswordField); \
  NS_SCRIPTABLE NS_IMETHOD SetPasswordField(const nsAString & aPasswordField); \
  NS_SCRIPTABLE NS_IMETHOD Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField); \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsILoginInfo *aLoginInfo, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Matches(nsILoginInfo *aLoginInfo, PRBool ignorePassword, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsILoginInfo **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGININFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname) { return _to GetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname) { return _to SetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormSubmitURL(nsAString & aFormSubmitURL) { return _to GetFormSubmitURL(aFormSubmitURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormSubmitURL(const nsAString & aFormSubmitURL) { return _to SetFormSubmitURL(aFormSubmitURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetHttpRealm(nsAString & aHttpRealm) { return _to GetHttpRealm(aHttpRealm); } \
  NS_SCRIPTABLE NS_IMETHOD SetHttpRealm(const nsAString & aHttpRealm) { return _to SetHttpRealm(aHttpRealm); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsername(nsAString & aUsername) { return _to GetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD SetUsername(const nsAString & aUsername) { return _to SetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsernameField(nsAString & aUsernameField) { return _to GetUsernameField(aUsernameField); } \
  NS_SCRIPTABLE NS_IMETHOD SetUsernameField(const nsAString & aUsernameField) { return _to SetUsernameField(aUsernameField); } \
  NS_SCRIPTABLE NS_IMETHOD GetPassword(nsAString & aPassword) { return _to GetPassword(aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD SetPassword(const nsAString & aPassword) { return _to SetPassword(aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD GetPasswordField(nsAString & aPasswordField) { return _to GetPasswordField(aPasswordField); } \
  NS_SCRIPTABLE NS_IMETHOD SetPasswordField(const nsAString & aPasswordField) { return _to SetPasswordField(aPasswordField); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField) { return _to Init(aHostname, aFormSubmitURL, aHttpRealm, aUsername, aPassword, aUsernameField, aPasswordField); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsILoginInfo *aLoginInfo, PRBool *_retval NS_OUTPARAM) { return _to Equals(aLoginInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Matches(nsILoginInfo *aLoginInfo, PRBool ignorePassword, PRBool *_retval NS_OUTPARAM) { return _to Matches(aLoginInfo, ignorePassword, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsILoginInfo **_retval NS_OUTPARAM) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGININFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormSubmitURL(nsAString & aFormSubmitURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormSubmitURL(aFormSubmitURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetFormSubmitURL(const nsAString & aFormSubmitURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFormSubmitURL(aFormSubmitURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetHttpRealm(nsAString & aHttpRealm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHttpRealm(aHttpRealm); } \
  NS_SCRIPTABLE NS_IMETHOD SetHttpRealm(const nsAString & aHttpRealm) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHttpRealm(aHttpRealm); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsername(nsAString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD SetUsername(const nsAString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsernameField(nsAString & aUsernameField) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsernameField(aUsernameField); } \
  NS_SCRIPTABLE NS_IMETHOD SetUsernameField(const nsAString & aUsernameField) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUsernameField(aUsernameField); } \
  NS_SCRIPTABLE NS_IMETHOD GetPassword(nsAString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPassword(aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD SetPassword(const nsAString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPassword(aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD GetPasswordField(nsAString & aPasswordField) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPasswordField(aPasswordField); } \
  NS_SCRIPTABLE NS_IMETHOD SetPasswordField(const nsAString & aPasswordField) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPasswordField(aPasswordField); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aHostname, aFormSubmitURL, aHttpRealm, aUsername, aPassword, aUsernameField, aPasswordField); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsILoginInfo *aLoginInfo, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(aLoginInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Matches(nsILoginInfo *aLoginInfo, PRBool ignorePassword, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Matches(aLoginInfo, ignorePassword, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsILoginInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginInfo : public nsILoginInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGININFO

  nsLoginInfo();

private:
  ~nsLoginInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoginInfo, nsILoginInfo)

nsLoginInfo::nsLoginInfo()
{
  /* member initializers and constructor code */
}

nsLoginInfo::~nsLoginInfo()
{
  /* destructor code */
}

/* attribute AString hostname; */
NS_IMETHODIMP nsLoginInfo::GetHostname(nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetHostname(const nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString formSubmitURL; */
NS_IMETHODIMP nsLoginInfo::GetFormSubmitURL(nsAString & aFormSubmitURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetFormSubmitURL(const nsAString & aFormSubmitURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString httpRealm; */
NS_IMETHODIMP nsLoginInfo::GetHttpRealm(nsAString & aHttpRealm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetHttpRealm(const nsAString & aHttpRealm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString username; */
NS_IMETHODIMP nsLoginInfo::GetUsername(nsAString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetUsername(const nsAString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString usernameField; */
NS_IMETHODIMP nsLoginInfo::GetUsernameField(nsAString & aUsernameField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetUsernameField(const nsAString & aUsernameField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString password; */
NS_IMETHODIMP nsLoginInfo::GetPassword(nsAString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetPassword(const nsAString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString passwordField; */
NS_IMETHODIMP nsLoginInfo::GetPasswordField(nsAString & aPasswordField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginInfo::SetPasswordField(const nsAString & aPasswordField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in AString aHostname, in AString aFormSubmitURL, in AString aHttpRealm, in AString aUsername, in AString aPassword, in AString aUsernameField, in AString aPasswordField); */
NS_IMETHODIMP nsLoginInfo::Init(const nsAString & aHostname, const nsAString & aFormSubmitURL, const nsAString & aHttpRealm, const nsAString & aUsername, const nsAString & aPassword, const nsAString & aUsernameField, const nsAString & aPasswordField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsILoginInfo aLoginInfo); */
NS_IMETHODIMP nsLoginInfo::Equals(nsILoginInfo *aLoginInfo, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean matches (in nsILoginInfo aLoginInfo, in boolean ignorePassword); */
NS_IMETHODIMP nsLoginInfo::Matches(nsILoginInfo *aLoginInfo, PRBool ignorePassword, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsILoginInfo clone (); */
NS_IMETHODIMP nsLoginInfo::Clone(nsILoginInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_LOGININFO_CONTRACTID "@mozilla.org/login-manager/loginInfo;1"

#endif /* __gen_nsILoginInfo_h__ */
