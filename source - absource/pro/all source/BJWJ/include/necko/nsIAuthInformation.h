/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIAuthInformation.idl
 */

#ifndef __gen_nsIAuthInformation_h__
#define __gen_nsIAuthInformation_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAuthInformation */
#define NS_IAUTHINFORMATION_IID_STR "0d73639c-2a92-4518-9f92-28f71fea5f20"

#define NS_IAUTHINFORMATION_IID \
  {0x0d73639c, 0x2a92, 0x4518, \
    { 0x9f, 0x92, 0x28, 0xf7, 0x1f, 0xea, 0x5f, 0x20 }}

/**
 * A object that hold authentication information. The caller of
 * nsIAuthPrompt2::promptUsernameAndPassword or
 * nsIAuthPrompt2::promptPasswordAsync provides an object implementing this
 * interface; the prompt implementation can then read the values here to prefill
 * the dialog. After the user entered the authentication information, it should
 * set the attributes of this object to indicate to the caller what was entered
 * by the user.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAuthInformation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHINFORMATION_IID)

  /** @name Flags */
/**
   * This dialog belongs to a network host.
   */
  enum { AUTH_HOST = 1U };

  /**
   * This dialog belongs to a proxy.
   */
  enum { AUTH_PROXY = 2U };

  /**
   * This dialog needs domain information. The user interface should show a
   * domain field, prefilled with the domain attribute's value.
   */
  enum { NEED_DOMAIN = 4U };

  /**
   * This dialog only asks for password information. Authentication prompts
   * SHOULD NOT show a username field. Attempts to change the username field
   * will have no effect. nsIAuthPrompt2 implementations should, however, show
   * its initial value to the user in some form. For example, a paragraph in
   * the dialog might say "Please enter your password for user jsmith at
   * server intranet".
   *
   * This flag is mutually exclusive with #NEED_DOMAIN.
   */
  enum { ONLY_PASSWORD = 8U };

  /**
   * Flags describing this dialog. A bitwise OR of the flag values
   * above.
   *
   * It is possible that neither #AUTH_HOST nor #AUTH_PROXY are set.
   *
   * Auth prompts should ignore flags they don't understand; especially, they
   * should not throw an exception because of an unsupported flag.
   */
  /* readonly attribute unsigned long flags; */
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) = 0;

  /**
   * The server-supplied realm of the authentication as defined in RFC 2617.
   * Can be the empty string if the protocol does not support realms.
   * Otherwise, this is a human-readable string like "Secret files".
   */
  /* readonly attribute AString realm; */
  NS_SCRIPTABLE NS_IMETHOD GetRealm(nsAString & aRealm) = 0;

  /**
   * The authentication scheme used for this request, if applicable. If the
   * protocol for this authentication does not support schemes, this will be
   * the empty string. Otherwise, this will be a string such as "basic" or 
   * "digest". This string will always be in lowercase.
   */
  /* readonly attribute AUTF8String authenticationScheme; */
  NS_SCRIPTABLE NS_IMETHOD GetAuthenticationScheme(nsACString & aAuthenticationScheme) = 0;

  /**
   * The initial value should be used to prefill the dialog or be shown
   * in some other way to the user.
   * On return, this parameter should contain the username entered by
   * the user.
   * This field can only be changed if the #ONLY_PASSWORD flag is not set.
   */
  /* attribute AString username; */
  NS_SCRIPTABLE NS_IMETHOD GetUsername(nsAString & aUsername) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUsername(const nsAString & aUsername) = 0;

  /**
   * The initial value should be used to prefill the dialog or be shown
   * in some other way to the user.
   * The password should not be shown in clear.
   * On return, this parameter should contain the password entered by
   * the user.
   */
  /* attribute AString password; */
  NS_SCRIPTABLE NS_IMETHOD GetPassword(nsAString & aPassword) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPassword(const nsAString & aPassword) = 0;

  /**
   * The initial value should be used to prefill the dialog or be shown
   * in some other way to the user.
   * On return, this parameter should contain the domain entered by
   * the user.
   * This attribute is only used if flags include #NEED_DOMAIN.
   */
  /* attribute AString domain; */
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsAString & aDomain) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthInformation, NS_IAUTHINFORMATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHINFORMATION \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetRealm(nsAString & aRealm); \
  NS_SCRIPTABLE NS_IMETHOD GetAuthenticationScheme(nsACString & aAuthenticationScheme); \
  NS_SCRIPTABLE NS_IMETHOD GetUsername(nsAString & aUsername); \
  NS_SCRIPTABLE NS_IMETHOD SetUsername(const nsAString & aUsername); \
  NS_SCRIPTABLE NS_IMETHOD GetPassword(nsAString & aPassword); \
  NS_SCRIPTABLE NS_IMETHOD SetPassword(const nsAString & aPassword); \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain); \
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsAString & aDomain); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHINFORMATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return _to GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetRealm(nsAString & aRealm) { return _to GetRealm(aRealm); } \
  NS_SCRIPTABLE NS_IMETHOD GetAuthenticationScheme(nsACString & aAuthenticationScheme) { return _to GetAuthenticationScheme(aAuthenticationScheme); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsername(nsAString & aUsername) { return _to GetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD SetUsername(const nsAString & aUsername) { return _to SetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD GetPassword(nsAString & aPassword) { return _to GetPassword(aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD SetPassword(const nsAString & aPassword) { return _to SetPassword(aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return _to GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsAString & aDomain) { return _to SetDomain(aDomain); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHINFORMATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetRealm(nsAString & aRealm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealm(aRealm); } \
  NS_SCRIPTABLE NS_IMETHOD GetAuthenticationScheme(nsACString & aAuthenticationScheme) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthenticationScheme(aAuthenticationScheme); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsername(nsAString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD SetUsername(const nsAString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD GetPassword(nsAString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPassword(aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD SetPassword(const nsAString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPassword(aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthInformation : public nsIAuthInformation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHINFORMATION

  nsAuthInformation();

private:
  ~nsAuthInformation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthInformation, nsIAuthInformation)

nsAuthInformation::nsAuthInformation()
{
  /* member initializers and constructor code */
}

nsAuthInformation::~nsAuthInformation()
{
  /* destructor code */
}

/* readonly attribute unsigned long flags; */
NS_IMETHODIMP nsAuthInformation::GetFlags(PRUint32 *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString realm; */
NS_IMETHODIMP nsAuthInformation::GetRealm(nsAString & aRealm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String authenticationScheme; */
NS_IMETHODIMP nsAuthInformation::GetAuthenticationScheme(nsACString & aAuthenticationScheme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString username; */
NS_IMETHODIMP nsAuthInformation::GetUsername(nsAString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAuthInformation::SetUsername(const nsAString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString password; */
NS_IMETHODIMP nsAuthInformation::GetPassword(nsAString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAuthInformation::SetPassword(const nsAString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString domain; */
NS_IMETHODIMP nsAuthInformation::GetDomain(nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAuthInformation::SetDomain(const nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAuthInformation_h__ */
