/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/ls/nsIDOMLSException.idl
 */

#ifndef __gen_nsIDOMLSException_h__
#define __gen_nsIDOMLSException_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMLSException */
#define NS_IDOMLSEXCEPTION_IID_STR "1cc8e4b3-1dbb-4adc-a913-1527bf67748c"

#define NS_IDOMLSEXCEPTION_IID \
  {0x1cc8e4b3, 0x1dbb, 0x4adc, \
    { 0xa9, 0x13, 0x15, 0x27, 0xbf, 0x67, 0x74, 0x8c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLSException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLSEXCEPTION_IID)

  enum { PARSE_ERR = 81U };

  enum { SERIALIZE_ERR = 82U };

  /* readonly attribute unsigned short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLSException, NS_IDOMLSEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLSEXCEPTION \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLSEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLSEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLSException : public nsIDOMLSException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLSEXCEPTION

  nsDOMLSException();

private:
  ~nsDOMLSException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLSException, nsIDOMLSException)

nsDOMLSException::nsDOMLSException()
{
  /* member initializers and constructor code */
}

nsDOMLSException::~nsDOMLSException()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMLSException::GetCode(PRUint16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLSException_h__ */
