/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsICancelable.idl
 */

#ifndef __gen_nsICancelable_h__
#define __gen_nsICancelable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICancelable */
#define NS_ICANCELABLE_IID_STR "d94ac0a0-bb18-46b8-844e-84159064b0bd"

#define NS_ICANCELABLE_IID \
  {0xd94ac0a0, 0xbb18, 0x46b8, \
    { 0x84, 0x4e, 0x84, 0x15, 0x90, 0x64, 0xb0, 0xbd }}

/**
 * This interface provides a means to cancel an operation that is in progress.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICancelable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICANCELABLE_IID)

  /**
   * Call this method to request that this object abort whatever operation it
   * may be performing.
   *
   * @param aReason
   *        Pass a failure code to indicate the reason why this operation is
   *        being canceled.  It is an error to pass a success code.
   */
  /* void cancel (in nsresult aReason); */
  NS_SCRIPTABLE NS_IMETHOD Cancel(nsresult aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICancelable, NS_ICANCELABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICANCELABLE \
  NS_SCRIPTABLE NS_IMETHOD Cancel(nsresult aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICANCELABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Cancel(nsresult aReason) { return _to Cancel(aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICANCELABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Cancel(nsresult aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCancelable : public nsICancelable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICANCELABLE

  nsCancelable();

private:
  ~nsCancelable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCancelable, nsICancelable)

nsCancelable::nsCancelable()
{
  /* member initializers and constructor code */
}

nsCancelable::~nsCancelable()
{
  /* destructor code */
}

/* void cancel (in nsresult aReason); */
NS_IMETHODIMP nsCancelable::Cancel(nsresult aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICancelable_h__ */
