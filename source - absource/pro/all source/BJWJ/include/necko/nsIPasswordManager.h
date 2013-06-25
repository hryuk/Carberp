/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIPasswordManager.idl
 */

#ifndef __gen_nsIPasswordManager_h__
#define __gen_nsIPasswordManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPasswordManager */
#define NS_IPASSWORDMANAGER_IID_STR "173562f0-2173-11d5-a54c-0010a401eb10"

#define NS_IPASSWORDMANAGER_IID \
  {0x173562f0, 0x2173, 0x11d5, \
    { 0xa5, 0x4c, 0x00, 0x10, 0xa4, 0x01, 0xeb, 0x10 }}

/** 
 * An optional interface for clients accessing or removing
 * logins that were collected by the password manager
 * 
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPasswordManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPASSWORDMANAGER_IID)

  /**
   * Called to add an individual login to the list of saved logins
   *
   * @param aHost The host for which the login is being remembered
   * @param aUser The username portion of the login
   * @param aPassword The password portion of the login
   *
   */
  /* void addUser (in AUTF8String aHost, in AString aUser, in AString aPassword); */
  NS_SCRIPTABLE NS_IMETHOD AddUser(const nsACString & aHost, const nsAString & aUser, const nsAString & aPassword) = 0;

  /**
   * Called to remove an individual login from the list of save logins
   *
   * @param aHost The host for which the login is being remembered
   * @param aUser The username portion of the login
   *
   */
  /* void removeUser (in AUTF8String aHost, in AString aUser); */
  NS_SCRIPTABLE NS_IMETHOD RemoveUser(const nsACString & aHost, const nsAString & aUser) = 0;

  /**
   * Called to add a host to the list of rejected hosts -- i.e., hosts for which
   * the do-you-want-to-save dialog does appear
   *
   * @param aHost The host for which the dialog is to not appear
   *
   */
  /* void addReject (in AUTF8String aHost); */
  NS_SCRIPTABLE NS_IMETHOD AddReject(const nsACString & aHost) = 0;

  /**
   * Called to remove a host from the list of rejected hosts -- i.e., hosts for which
   * the do-you-want-to-save dialog does not appear
   *
   * @param aHost The host for which the dialog is to not appear
   *
   */
  /* void removeReject (in AUTF8String aHost); */
  NS_SCRIPTABLE NS_IMETHOD RemoveReject(const nsACString & aHost) = 0;

  /**
   * Called to enumerate through each login in the password-manager list
   * The objects enumerated over are of type nsIPassword
   */
  /* readonly attribute nsISimpleEnumerator enumerator; */
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) = 0;

  /**
   * Called to enumerate through each rejected site in the password-manager list
   * These are sites for which the user has indicated that he doesn't want passwords saved.
   * The objects enumerated over are of type nsIPassword, although the only member of
   * that object that is relevent is the host (the user and password members are ignored).
   */
  /* readonly attribute nsISimpleEnumerator rejectEnumerator; */
  NS_SCRIPTABLE NS_IMETHOD GetRejectEnumerator(nsISimpleEnumerator * *aRejectEnumerator) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPasswordManager, NS_IPASSWORDMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPASSWORDMANAGER \
  NS_SCRIPTABLE NS_IMETHOD AddUser(const nsACString & aHost, const nsAString & aUser, const nsAString & aPassword); \
  NS_SCRIPTABLE NS_IMETHOD RemoveUser(const nsACString & aHost, const nsAString & aUser); \
  NS_SCRIPTABLE NS_IMETHOD AddReject(const nsACString & aHost); \
  NS_SCRIPTABLE NS_IMETHOD RemoveReject(const nsACString & aHost); \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator); \
  NS_SCRIPTABLE NS_IMETHOD GetRejectEnumerator(nsISimpleEnumerator * *aRejectEnumerator); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPASSWORDMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddUser(const nsACString & aHost, const nsAString & aUser, const nsAString & aPassword) { return _to AddUser(aHost, aUser, aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveUser(const nsACString & aHost, const nsAString & aUser) { return _to RemoveUser(aHost, aUser); } \
  NS_SCRIPTABLE NS_IMETHOD AddReject(const nsACString & aHost) { return _to AddReject(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveReject(const nsACString & aHost) { return _to RemoveReject(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return _to GetEnumerator(aEnumerator); } \
  NS_SCRIPTABLE NS_IMETHOD GetRejectEnumerator(nsISimpleEnumerator * *aRejectEnumerator) { return _to GetRejectEnumerator(aRejectEnumerator); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPASSWORDMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddUser(const nsACString & aHost, const nsAString & aUser, const nsAString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddUser(aHost, aUser, aPassword); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveUser(const nsACString & aHost, const nsAString & aUser) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveUser(aHost, aUser); } \
  NS_SCRIPTABLE NS_IMETHOD AddReject(const nsACString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddReject(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveReject(const nsACString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveReject(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(aEnumerator); } \
  NS_SCRIPTABLE NS_IMETHOD GetRejectEnumerator(nsISimpleEnumerator * *aRejectEnumerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRejectEnumerator(aRejectEnumerator); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPasswordManager : public nsIPasswordManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPASSWORDMANAGER

  nsPasswordManager();

private:
  ~nsPasswordManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPasswordManager, nsIPasswordManager)

nsPasswordManager::nsPasswordManager()
{
  /* member initializers and constructor code */
}

nsPasswordManager::~nsPasswordManager()
{
  /* destructor code */
}

/* void addUser (in AUTF8String aHost, in AString aUser, in AString aPassword); */
NS_IMETHODIMP nsPasswordManager::AddUser(const nsACString & aHost, const nsAString & aUser, const nsAString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeUser (in AUTF8String aHost, in AString aUser); */
NS_IMETHODIMP nsPasswordManager::RemoveUser(const nsACString & aHost, const nsAString & aUser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addReject (in AUTF8String aHost); */
NS_IMETHODIMP nsPasswordManager::AddReject(const nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeReject (in AUTF8String aHost); */
NS_IMETHODIMP nsPasswordManager::RemoveReject(const nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator enumerator; */
NS_IMETHODIMP nsPasswordManager::GetEnumerator(nsISimpleEnumerator * *aEnumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator rejectEnumerator; */
NS_IMETHODIMP nsPasswordManager::GetRejectEnumerator(nsISimpleEnumerator * *aRejectEnumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPasswordManager_h__ */
