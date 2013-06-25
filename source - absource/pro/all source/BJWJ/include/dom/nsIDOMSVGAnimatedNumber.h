/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedNumber.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedNumber_h__
#define __gen_nsIDOMSVGAnimatedNumber_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGNumber; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedNumber */
#define NS_IDOMSVGANIMATEDNUMBER_IID_STR "716e3b11-b03b-49f7-b82d-5383922b0ab3"

#define NS_IDOMSVGANIMATEDNUMBER_IID \
  {0x716e3b11, 0xb03b, 0x49f7, \
    { 0xb8, 0x2d, 0x53, 0x83, 0x92, 0x2b, 0x0a, 0xb3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedNumber : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDNUMBER_IID)

  /* attribute float baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(float *aBaseVal) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(float aBaseVal) = 0;

  /* readonly attribute float animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(float *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedNumber, NS_IDOMSVGANIMATEDNUMBER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDNUMBER \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(float *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(float aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(float *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDNUMBER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(float *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(float aBaseVal) { return _to SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(float *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDNUMBER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(float *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(float aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(float *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedNumber : public nsIDOMSVGAnimatedNumber
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDNUMBER

  nsDOMSVGAnimatedNumber();

private:
  ~nsDOMSVGAnimatedNumber();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedNumber, nsIDOMSVGAnimatedNumber)

nsDOMSVGAnimatedNumber::nsDOMSVGAnimatedNumber()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedNumber::~nsDOMSVGAnimatedNumber()
{
  /* destructor code */
}

/* attribute float baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedNumber::GetBaseVal(float *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAnimatedNumber::SetBaseVal(float aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedNumber::GetAnimVal(float *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedNumber_h__ */
