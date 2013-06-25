/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/profile/public/nsIProfileUnlocker.idl
 */

#ifndef __gen_nsIProfileUnlocker_h__
#define __gen_nsIProfileUnlocker_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIProfileUnlocker */
#define NS_IPROFILEUNLOCKER_IID_STR "08923af1-e7a3-4fae-ba02-128502193994"

#define NS_IPROFILEUNLOCKER_IID \
  {0x08923af1, 0xe7a3, 0x4fae, \
    { 0xba, 0x02, 0x12, 0x85, 0x02, 0x19, 0x39, 0x94 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIProfileUnlocker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILEUNLOCKER_IID)

  enum { ATTEMPT_QUIT = 0U };

  enum { FORCE_QUIT = 1U };

  /**
   * Try to unlock the specified profile by attempting or forcing the
   * process that currently holds the lock to quit.
   *
   * @param aSeverity either ATTEMPT_QUIT or FORCE_QUIT
   * @throws NS_ERROR_FAILURE if unlocking failed.
   */
  /* void unlock (in unsigned long aSeverity); */
  NS_SCRIPTABLE NS_IMETHOD Unlock(PRUint32 aSeverity) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfileUnlocker, NS_IPROFILEUNLOCKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILEUNLOCKER \
  NS_SCRIPTABLE NS_IMETHOD Unlock(PRUint32 aSeverity); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILEUNLOCKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Unlock(PRUint32 aSeverity) { return _to Unlock(aSeverity); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILEUNLOCKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Unlock(PRUint32 aSeverity) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unlock(aSeverity); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfileUnlocker : public nsIProfileUnlocker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILEUNLOCKER

  nsProfileUnlocker();

private:
  ~nsProfileUnlocker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProfileUnlocker, nsIProfileUnlocker)

nsProfileUnlocker::nsProfileUnlocker()
{
  /* member initializers and constructor code */
}

nsProfileUnlocker::~nsProfileUnlocker()
{
  /* destructor code */
}

/* void unlock (in unsigned long aSeverity); */
NS_IMETHODIMP nsProfileUnlocker::Unlock(PRUint32 aSeverity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProfileUnlocker_h__ */
