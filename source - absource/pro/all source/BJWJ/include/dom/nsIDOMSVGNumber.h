/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGNumber.idl
 */

#ifndef __gen_nsIDOMSVGNumber_h__
#define __gen_nsIDOMSVGNumber_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGNumber */
#define NS_IDOMSVGNUMBER_IID_STR "98575762-a936-4ecf-a226-b74c3a2981b4"

#define NS_IDOMSVGNUMBER_IID \
  {0x98575762, 0xa936, 0x4ecf, \
    { 0xa2, 0x26, 0xb7, 0x4c, 0x3a, 0x29, 0x81, 0xb4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGNumber : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGNUMBER_IID)

  /* attribute float value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(float *aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(float aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGNumber, NS_IDOMSVGNUMBER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGNUMBER \
  NS_SCRIPTABLE NS_IMETHOD GetValue(float *aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(float aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGNUMBER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(float *aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(float aValue) { return _to SetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGNUMBER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(float *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(float aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGNumber : public nsIDOMSVGNumber
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGNUMBER

  nsDOMSVGNumber();

private:
  ~nsDOMSVGNumber();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGNumber, nsIDOMSVGNumber)

nsDOMSVGNumber::nsDOMSVGNumber()
{
  /* member initializers and constructor code */
}

nsDOMSVGNumber::~nsDOMSVGNumber()
{
  /* destructor code */
}

/* attribute float value; */
NS_IMETHODIMP nsDOMSVGNumber::GetValue(float *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGNumber::SetValue(float aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGNumber_h__ */
