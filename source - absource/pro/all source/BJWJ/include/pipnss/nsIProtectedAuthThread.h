/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIProtectedAuthThread.idl
 */

#ifndef __gen_nsIProtectedAuthThread_h__
#define __gen_nsIProtectedAuthThread_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIObserver_h__
#include "nsIObserver.h"
#endif

#ifndef __gen_nsIPKCS11Slot_h__
#include "nsIPKCS11Slot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIProtectedAuthThread */
#define NS_IPROTECTEDAUTHTHREAD_IID_STR "4bb27cb7-8984-4cee-8ce7-9b014c3d091b"

#define NS_IPROTECTEDAUTHTHREAD_IID \
  {0x4bb27cb7, 0x8984, 0x4cee, \
    { 0x8c, 0xe7, 0x9b, 0x01, 0x4c, 0x3d, 0x09, 0x1b }}

/**
 * nsIProtectedAuthThread
 *  This is used to communicate with the thread login on to 
 *  a token with CKF_PROTECTED_AUTHENTICATION_PATH set.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIProtectedAuthThread : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTECTEDAUTHTHREAD_IID)

  /**
   * login - run the thread
   *   A user interface implementing this interface needs to
   *   call this method as soon as the message to the user is
   *   displayed. This will trigger login operation. No user 
   *   cancellation is possible during login operation.
   *
   *   When the login is done, the observe method of @observer will
   *   be called on the UI thread with a topic of "login-finished"
   *   and null data and subject.
   */
  /* void login (in nsIObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD Login(nsIObserver *observer) = 0;

  /**
   * The PKCS11 slot
   */
  /* readonly attribute nsIPKCS11Slot slot; */
  NS_SCRIPTABLE NS_IMETHOD GetSlot(nsIPKCS11Slot * *aSlot) = 0;

  /**
   * Gets token to be logged in name.
   */
  /* AString getTokenName (); */
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtectedAuthThread, NS_IPROTECTEDAUTHTHREAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTECTEDAUTHTHREAD \
  NS_SCRIPTABLE NS_IMETHOD Login(nsIObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD GetSlot(nsIPKCS11Slot * *aSlot); \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTECTEDAUTHTHREAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD Login(nsIObserver *observer) { return _to Login(observer); } \
  NS_SCRIPTABLE NS_IMETHOD GetSlot(nsIPKCS11Slot * *aSlot) { return _to GetSlot(aSlot); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(nsAString & _retval NS_OUTPARAM) { return _to GetTokenName(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTECTEDAUTHTHREAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD Login(nsIObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->Login(observer); } \
  NS_SCRIPTABLE NS_IMETHOD GetSlot(nsIPKCS11Slot * *aSlot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSlot(aSlot); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenName(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtectedAuthThread : public nsIProtectedAuthThread
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTECTEDAUTHTHREAD

  nsProtectedAuthThread();

private:
  ~nsProtectedAuthThread();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProtectedAuthThread, nsIProtectedAuthThread)

nsProtectedAuthThread::nsProtectedAuthThread()
{
  /* member initializers and constructor code */
}

nsProtectedAuthThread::~nsProtectedAuthThread()
{
  /* destructor code */
}

/* void login (in nsIObserver observer); */
NS_IMETHODIMP nsProtectedAuthThread::Login(nsIObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPKCS11Slot slot; */
NS_IMETHODIMP nsProtectedAuthThread::GetSlot(nsIPKCS11Slot * *aSlot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTokenName (); */
NS_IMETHODIMP nsProtectedAuthThread::GetTokenName(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {45334489-3D30-47c6-920B-0A55A313AEBF}
#define NS_PROTECTEDAUTHTHREAD_CID \
{ 0x45334489, 0x3d30, 0x47c6, { 0x92, 0x0b, 0x0a, 0x55, 0xa3, 0x13, 0xae, 0xbf } }
#define NS_PROTECTEDAUTHTHREAD_CONTRACTID "@mozilla.org/security/protectedauththread;1"

#endif /* __gen_nsIProtectedAuthThread_h__ */
