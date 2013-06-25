/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIPasswordManagerInternal.idl
 */

#ifndef __gen_nsIPasswordManagerInternal_h__
#define __gen_nsIPasswordManagerInternal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIPasswordManagerInternal */
#define NS_IPASSWORDMANAGERINTERNAL_IID_STR "a448531f-dc92-4dc1-9012-da841febcbe0"

#define NS_IPASSWORDMANAGERINTERNAL_IID \
  {0xa448531f, 0xdc92, 0x4dc1, \
    { 0x90, 0x12, 0xda, 0x84, 0x1f, 0xeb, 0xcb, 0xe0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPasswordManagerInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPASSWORDMANAGERINTERNAL_IID)

  /**
   * A Call to find a login in the password manager list that matches the
   * specified parameters. If any input parameter is null, it is
   * not tested for when looking for the match.
   *
   * @param aHostURI The uri part of a login to search for, or null
   * @param aUsername The username part of a login to search for, or null
   * @param aPassword The password part of a login to search for, or null
   * @param aHostURIFound The uri found in the login
   * @param aUsernameFound The username found in the login
   * @param aPasswordFound The password found in the login
   */
  /* void findPasswordEntry (in AUTF8String aHostURI, in AString aUsername, in AString aPassword, out AUTF8String aHostURIFound, out AString aUsernameFound, out AString aPasswordFound); */
  NS_SCRIPTABLE NS_IMETHOD FindPasswordEntry(const nsACString & aHostURI, const nsAString & aUsername, const nsAString & aPassword, nsACString & aHostURIFound NS_OUTPARAM, nsAString & aUsernameFound NS_OUTPARAM, nsAString & aPasswordFound NS_OUTPARAM) = 0;

  /**
   * Called to add an individual login to the list of saved logins. 
   * All parameters are clear text.
   *
   * @param aKey The key for which the login is being remembered (often the page URI)
   * @param aUser The username portion of the login
   * @param aPassword The password portion of the login
   * @param aUserFieldName The name of the field that contained the username
   * @param aPassFieldName The name of the field that contained the password
   */
  /* void addUserFull (in AUTF8String aKey, in AString aUser, in AString aPassword, in AString aUserFieldName, in AString aPassFieldName); */
  NS_SCRIPTABLE NS_IMETHOD AddUserFull(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName) = 0;

  /* void addUserFull2 (in AUTF8String aKey, in AString aUser, in AString aPassword, in AString aUserFieldName, in AString aPassFieldName, in AUTF8String ActionURL); */
  NS_SCRIPTABLE NS_IMETHOD AddUserFull2(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName, const nsACString & ActionURL) = 0;

  /**
   * Reads logins from a Mozilla Password Manager file, augmenting the current 
   * in-memory set. If a duplicate entry is encountered, the data from the file
   * being read replaces that currently held.
   * 
   * @param aPasswordFile The file to read logins from.
   */
  /* void readPasswords (in nsIFile aPasswordFile); */
  NS_SCRIPTABLE NS_IMETHOD ReadPasswords(nsIFile *aPasswordFile) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPasswordManagerInternal, NS_IPASSWORDMANAGERINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPASSWORDMANAGERINTERNAL \
  NS_SCRIPTABLE NS_IMETHOD FindPasswordEntry(const nsACString & aHostURI, const nsAString & aUsername, const nsAString & aPassword, nsACString & aHostURIFound NS_OUTPARAM, nsAString & aUsernameFound NS_OUTPARAM, nsAString & aPasswordFound NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddUserFull(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName); \
  NS_SCRIPTABLE NS_IMETHOD AddUserFull2(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName, const nsACString & ActionURL); \
  NS_SCRIPTABLE NS_IMETHOD ReadPasswords(nsIFile *aPasswordFile); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPASSWORDMANAGERINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD FindPasswordEntry(const nsACString & aHostURI, const nsAString & aUsername, const nsAString & aPassword, nsACString & aHostURIFound NS_OUTPARAM, nsAString & aUsernameFound NS_OUTPARAM, nsAString & aPasswordFound NS_OUTPARAM) { return _to FindPasswordEntry(aHostURI, aUsername, aPassword, aHostURIFound, aUsernameFound, aPasswordFound); } \
  NS_SCRIPTABLE NS_IMETHOD AddUserFull(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName) { return _to AddUserFull(aKey, aUser, aPassword, aUserFieldName, aPassFieldName); } \
  NS_SCRIPTABLE NS_IMETHOD AddUserFull2(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName, const nsACString & ActionURL) { return _to AddUserFull2(aKey, aUser, aPassword, aUserFieldName, aPassFieldName, ActionURL); } \
  NS_SCRIPTABLE NS_IMETHOD ReadPasswords(nsIFile *aPasswordFile) { return _to ReadPasswords(aPasswordFile); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPASSWORDMANAGERINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD FindPasswordEntry(const nsACString & aHostURI, const nsAString & aUsername, const nsAString & aPassword, nsACString & aHostURIFound NS_OUTPARAM, nsAString & aUsernameFound NS_OUTPARAM, nsAString & aPasswordFound NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindPasswordEntry(aHostURI, aUsername, aPassword, aHostURIFound, aUsernameFound, aPasswordFound); } \
  NS_SCRIPTABLE NS_IMETHOD AddUserFull(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddUserFull(aKey, aUser, aPassword, aUserFieldName, aPassFieldName); } \
  NS_SCRIPTABLE NS_IMETHOD AddUserFull2(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName, const nsACString & ActionURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddUserFull2(aKey, aUser, aPassword, aUserFieldName, aPassFieldName, ActionURL); } \
  NS_SCRIPTABLE NS_IMETHOD ReadPasswords(nsIFile *aPasswordFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadPasswords(aPasswordFile); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPasswordManagerInternal : public nsIPasswordManagerInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPASSWORDMANAGERINTERNAL

  nsPasswordManagerInternal();

private:
  ~nsPasswordManagerInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPasswordManagerInternal, nsIPasswordManagerInternal)

nsPasswordManagerInternal::nsPasswordManagerInternal()
{
  /* member initializers and constructor code */
}

nsPasswordManagerInternal::~nsPasswordManagerInternal()
{
  /* destructor code */
}

/* void findPasswordEntry (in AUTF8String aHostURI, in AString aUsername, in AString aPassword, out AUTF8String aHostURIFound, out AString aUsernameFound, out AString aPasswordFound); */
NS_IMETHODIMP nsPasswordManagerInternal::FindPasswordEntry(const nsACString & aHostURI, const nsAString & aUsername, const nsAString & aPassword, nsACString & aHostURIFound NS_OUTPARAM, nsAString & aUsernameFound NS_OUTPARAM, nsAString & aPasswordFound NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addUserFull (in AUTF8String aKey, in AString aUser, in AString aPassword, in AString aUserFieldName, in AString aPassFieldName); */
NS_IMETHODIMP nsPasswordManagerInternal::AddUserFull(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addUserFull2 (in AUTF8String aKey, in AString aUser, in AString aPassword, in AString aUserFieldName, in AString aPassFieldName, in AUTF8String ActionURL); */
NS_IMETHODIMP nsPasswordManagerInternal::AddUserFull2(const nsACString & aKey, const nsAString & aUser, const nsAString & aPassword, const nsAString & aUserFieldName, const nsAString & aPassFieldName, const nsACString & ActionURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void readPasswords (in nsIFile aPasswordFile); */
NS_IMETHODIMP nsPasswordManagerInternal::ReadPasswords(nsIFile *aPasswordFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPasswordManagerInternal_h__ */
