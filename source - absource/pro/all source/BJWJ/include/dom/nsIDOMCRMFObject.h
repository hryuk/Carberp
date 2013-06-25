/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMCRMFObject.idl
 */

#ifndef __gen_nsIDOMCRMFObject_h__
#define __gen_nsIDOMCRMFObject_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCRMFObject */
#define NS_IDOMCRMFOBJECT_IID_STR "16da46c0-208d-11d4-8a7c-006008c844c3"

#define NS_IDOMCRMFOBJECT_IID \
  {0x16da46c0, 0x208d, 0x11d4, \
    { 0x8a, 0x7c, 0x00, 0x60, 0x08, 0xc8, 0x44, 0xc3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCRMFObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCRMFOBJECT_IID)

  /* readonly attribute DOMString request; */
  NS_SCRIPTABLE NS_IMETHOD GetRequest(nsAString & aRequest) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCRMFObject, NS_IDOMCRMFOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCRMFOBJECT \
  NS_SCRIPTABLE NS_IMETHOD GetRequest(nsAString & aRequest); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCRMFOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRequest(nsAString & aRequest) { return _to GetRequest(aRequest); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCRMFOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRequest(nsAString & aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequest(aRequest); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCRMFObject : public nsIDOMCRMFObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCRMFOBJECT

  nsDOMCRMFObject();

private:
  ~nsDOMCRMFObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCRMFObject, nsIDOMCRMFObject)

nsDOMCRMFObject::nsDOMCRMFObject()
{
  /* member initializers and constructor code */
}

nsDOMCRMFObject::~nsDOMCRMFObject()
{
  /* destructor code */
}

/* readonly attribute DOMString request; */
NS_IMETHODIMP nsDOMCRMFObject::GetRequest(nsAString & aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCRMFObject_h__ */
