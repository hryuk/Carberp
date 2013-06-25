/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIKeygenThread.idl
 */

#ifndef __gen_nsIKeygenThread_h__
#define __gen_nsIKeygenThread_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIObserver; /* forward declaration */


/* starting interface:    nsIKeygenThread */
#define NS_IKEYGENTHREAD_IID_STR "8712a243-5539-447c-9f47-8653f40c3a09"

#define NS_IKEYGENTHREAD_IID \
  {0x8712a243, 0x5539, 0x447c, \
    { 0x9f, 0x47, 0x86, 0x53, 0xf4, 0x0c, 0x3a, 0x09 }}

/**
 * nsIKeygenThread
 *  This is used to communicate with the thread generating a key pair,
 *  to be used by the dialog displaying status information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIKeygenThread : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IKEYGENTHREAD_IID)

  /**
   * startKeyGeneration - run the thread
   *   A user interface using this interface needs to
   *   call this method as soon as the status information
   *   is displaying. This will trigger key generation.
   *   To allow the closure of the status information,
   *   the thread needs a handle to an observer.
   *
   *   observer will be called on the UI thread.
   *   When the key generation is done, the observe method will
   *   be called with a topic of "keygen-finished" and null data
   *   and subject.
   */
  /* void startKeyGeneration (in nsIObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD StartKeyGeneration(nsIObserver *observer) = 0;

  /**
   * userCanceled - notify the thread
   *   If the user canceled, the thread is no longer allowed to
   *   close the dialog. However, if the thread already closed
   *   it, we are not allowed to close it.
   */
  /* void userCanceled (out boolean threadAlreadyClosedDialog); */
  NS_SCRIPTABLE NS_IMETHOD UserCanceled(PRBool *threadAlreadyClosedDialog NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIKeygenThread, NS_IKEYGENTHREAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIKEYGENTHREAD \
  NS_SCRIPTABLE NS_IMETHOD StartKeyGeneration(nsIObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD UserCanceled(PRBool *threadAlreadyClosedDialog NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIKEYGENTHREAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartKeyGeneration(nsIObserver *observer) { return _to StartKeyGeneration(observer); } \
  NS_SCRIPTABLE NS_IMETHOD UserCanceled(PRBool *threadAlreadyClosedDialog NS_OUTPARAM) { return _to UserCanceled(threadAlreadyClosedDialog); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIKEYGENTHREAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartKeyGeneration(nsIObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartKeyGeneration(observer); } \
  NS_SCRIPTABLE NS_IMETHOD UserCanceled(PRBool *threadAlreadyClosedDialog NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UserCanceled(threadAlreadyClosedDialog); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsKeygenThread : public nsIKeygenThread
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIKEYGENTHREAD

  nsKeygenThread();

private:
  ~nsKeygenThread();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsKeygenThread, nsIKeygenThread)

nsKeygenThread::nsKeygenThread()
{
  /* member initializers and constructor code */
}

nsKeygenThread::~nsKeygenThread()
{
  /* destructor code */
}

/* void startKeyGeneration (in nsIObserver observer); */
NS_IMETHODIMP nsKeygenThread::StartKeyGeneration(nsIObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void userCanceled (out boolean threadAlreadyClosedDialog); */
NS_IMETHODIMP nsKeygenThread::UserCanceled(PRBool *threadAlreadyClosedDialog NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {195763b8-1dd2-11b2-a843-eb44e44aaa37}
#define NS_KEYGENTHREAD_CID \
{ 0x195763b8, 0x1dd2, 0x11b2, { 0xa8, 0x43, 0xeb, 0x44, 0xe4, 0x4a, 0xaa, 0x37 } }
#define NS_KEYGENTHREAD_CONTRACTID "@mozilla.org/security/keygenthread;1"

#endif /* __gen_nsIKeygenThread_h__ */
