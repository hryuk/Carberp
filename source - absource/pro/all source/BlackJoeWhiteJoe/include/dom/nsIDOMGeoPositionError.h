/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/geolocation/nsIDOMGeoPositionError.idl
 */

#ifndef __gen_nsIDOMGeoPositionError_h__
#define __gen_nsIDOMGeoPositionError_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGeoPositionError */
#define NS_IDOMGEOPOSITIONERROR_IID_STR "1b493214-4e58-4a40-aa4c-1ab70c6ddbec"

#define NS_IDOMGEOPOSITIONERROR_IID \
  {0x1b493214, 0x4e58, 0x4a40, \
    { 0xaa, 0x4c, 0x1a, 0xb7, 0x0c, 0x6d, 0xdb, 0xec }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMGeoPositionError : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOPOSITIONERROR_IID)

  enum { UNKNOWN_ERROR = 0U };

  enum { PERMISSION_DENIED = 1U };

  enum { POSITION_UNAVAILABLE = 2U };

  enum { TIMEOUT = 3U };

  /* readonly attribute short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRInt16 *aCode) = 0;

  /* readonly attribute DOMString message; */
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsAString & aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoPositionError, NS_IDOMGEOPOSITIONERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOPOSITIONERROR \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRInt16 *aCode); \
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsAString & aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOPOSITIONERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRInt16 *aCode) { return _to GetCode(aCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsAString & aMessage) { return _to GetMessage(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOPOSITIONERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRInt16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoPositionError : public nsIDOMGeoPositionError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOPOSITIONERROR

  nsDOMGeoPositionError();

private:
  ~nsDOMGeoPositionError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoPositionError, nsIDOMGeoPositionError)

nsDOMGeoPositionError::nsDOMGeoPositionError()
{
  /* member initializers and constructor code */
}

nsDOMGeoPositionError::~nsDOMGeoPositionError()
{
  /* destructor code */
}

/* readonly attribute short code; */
NS_IMETHODIMP nsDOMGeoPositionError::GetCode(PRInt16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString message; */
NS_IMETHODIMP nsDOMGeoPositionError::GetMessage(nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoPositionError_h__ */
