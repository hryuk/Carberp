/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGException.idl
 */

#ifndef __gen_nsIDOMSVGException_h__
#define __gen_nsIDOMSVGException_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGException */
#define NS_IDOMSVGEXCEPTION_IID_STR "64e6f0e1-af99-4bb9-ab25-7e56012f0021"

#define NS_IDOMSVGEXCEPTION_IID \
  {0x64e6f0e1, 0xaf99, 0x4bb9, \
    { 0xab, 0x25, 0x7e, 0x56, 0x01, 0x2f, 0x00, 0x21 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGEXCEPTION_IID)

  enum { SVG_WRONG_TYPE_ERR = 0U };

  enum { SVG_INVALID_VALUE_ERR = 1U };

  enum { SVG_MATRIX_NOT_INVERTABLE = 2U };

  /* readonly attribute unsigned short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGException, NS_IDOMSVGEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGEXCEPTION \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGException : public nsIDOMSVGException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGEXCEPTION

  nsDOMSVGException();

private:
  ~nsDOMSVGException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGException, nsIDOMSVGException)

nsDOMSVGException::nsDOMSVGException()
{
  /* member initializers and constructor code */
}

nsDOMSVGException::~nsDOMSVGException()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMSVGException::GetCode(PRUint16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGException_h__ */
