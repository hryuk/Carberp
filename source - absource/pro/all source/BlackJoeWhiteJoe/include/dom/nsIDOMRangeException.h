/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/range/nsIDOMRangeException.idl
 */

#ifndef __gen_nsIDOMRangeException_h__
#define __gen_nsIDOMRangeException_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMRangeException */
#define NS_IDOMRANGEEXCEPTION_IID_STR "0f807301-39d2-11d6-a7f2-8f504ff870dc"

#define NS_IDOMRANGEEXCEPTION_IID \
  {0x0f807301, 0x39d2, 0x11d6, \
    { 0xa7, 0xf2, 0x8f, 0x50, 0x4f, 0xf8, 0x70, 0xdc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMRangeException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMRANGEEXCEPTION_IID)

  enum { BAD_BOUNDARYPOINTS_ERR = 1U };

  enum { INVALID_NODE_TYPE_ERR = 2U };

  /* readonly attribute unsigned short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRangeException, NS_IDOMRANGEEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMRANGEEXCEPTION \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMRANGEEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMRANGEEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRangeException : public nsIDOMRangeException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMRANGEEXCEPTION

  nsDOMRangeException();

private:
  ~nsDOMRangeException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRangeException, nsIDOMRangeException)

nsDOMRangeException::nsDOMRangeException()
{
  /* member initializers and constructor code */
}

nsDOMRangeException::~nsDOMRangeException()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMRangeException::GetCode(PRUint16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMRangeException_h__ */
