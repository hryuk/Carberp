/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMHTMLMediaError.idl
 */

#ifndef __gen_nsIDOMHTMLMediaError_h__
#define __gen_nsIDOMHTMLMediaError_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLMediaError */
#define NS_IDOMHTMLMEDIAERROR_IID_STR "7bd8c29f-8a76-453f-9373-79f820f2dc01"

#define NS_IDOMHTMLMEDIAERROR_IID \
  {0x7bd8c29f, 0x8a76, 0x453f, \
    { 0x93, 0x73, 0x79, 0xf8, 0x20, 0xf2, 0xdc, 0x01 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLMediaError : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLMEDIAERROR_IID)

  enum { MEDIA_ERR_ABORTED = 1U };

  enum { MEDIA_ERR_NETWORK = 2U };

  enum { MEDIA_ERR_DECODE = 3U };

  enum { MEDIA_ERR_NONE_SUPPORTED = 4U };

  /* readonly attribute unsigned short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLMediaError, NS_IDOMHTMLMEDIAERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLMEDIAERROR \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLMEDIAERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLMEDIAERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLMediaError : public nsIDOMHTMLMediaError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLMEDIAERROR

  nsDOMHTMLMediaError();

private:
  ~nsDOMHTMLMediaError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLMediaError, nsIDOMHTMLMediaError)

nsDOMHTMLMediaError::nsDOMHTMLMediaError()
{
  /* member initializers and constructor code */
}

nsDOMHTMLMediaError::~nsDOMHTMLMediaError()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMHTMLMediaError::GetCode(PRUint16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLMediaError_h__ */
