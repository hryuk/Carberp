/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xpath/nsIDOMXPathException.idl
 */

#ifndef __gen_nsIDOMXPathException_h__
#define __gen_nsIDOMXPathException_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXPathException */
#define NS_IDOMXPATHEXCEPTION_IID_STR "75506f89-b504-11d5-a7f2-ca108ab8b6fc"

#define NS_IDOMXPATHEXCEPTION_IID \
  {0x75506f89, 0xb504, 0x11d5, \
    { 0xa7, 0xf2, 0xca, 0x10, 0x8a, 0xb8, 0xb6, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXPathException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXPATHEXCEPTION_IID)

  enum { INVALID_EXPRESSION_ERR = 51U };

  enum { TYPE_ERR = 52U };

  /* readonly attribute unsigned short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXPathException, NS_IDOMXPATHEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXPATHEXCEPTION \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXPATHEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXPATHEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXPathException : public nsIDOMXPathException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXPATHEXCEPTION

  nsDOMXPathException();

private:
  ~nsDOMXPathException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXPathException, nsIDOMXPathException)

nsDOMXPathException::nsDOMXPathException()
{
  /* member initializers and constructor code */
}

nsDOMXPathException::~nsDOMXPathException()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMXPathException::GetCode(PRUint16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXPathException_h__ */
