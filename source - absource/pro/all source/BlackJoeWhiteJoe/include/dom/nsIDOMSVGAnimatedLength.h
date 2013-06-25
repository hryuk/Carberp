/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedLength.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedLength_h__
#define __gen_nsIDOMSVGAnimatedLength_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGLength; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedLength */
#define NS_IDOMSVGANIMATEDLENGTH_IID_STR "a52f0322-7f4d-418d-af6d-a7b14abd5cdf"

#define NS_IDOMSVGANIMATEDLENGTH_IID \
  {0xa52f0322, 0x7f4d, 0x418d, \
    { 0xaf, 0x6d, 0xa7, 0xb1, 0x4a, 0xbd, 0x5c, 0xdf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedLength : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDLENGTH_IID)

  /* readonly attribute nsIDOMSVGLength baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGLength * *aBaseVal) = 0;

  /* readonly attribute nsIDOMSVGLength animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGLength * *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedLength, NS_IDOMSVGANIMATEDLENGTH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDLENGTH \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGLength * *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGLength * *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDLENGTH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGLength * *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGLength * *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDLENGTH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGLength * *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGLength * *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedLength : public nsIDOMSVGAnimatedLength
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDLENGTH

  nsDOMSVGAnimatedLength();

private:
  ~nsDOMSVGAnimatedLength();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedLength, nsIDOMSVGAnimatedLength)

nsDOMSVGAnimatedLength::nsDOMSVGAnimatedLength()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedLength::~nsDOMSVGAnimatedLength()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGLength baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedLength::GetBaseVal(nsIDOMSVGLength * *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGLength animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedLength::GetAnimVal(nsIDOMSVGLength * *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedLength_h__ */
