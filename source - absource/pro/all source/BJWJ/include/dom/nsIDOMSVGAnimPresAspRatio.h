/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimPresAspRatio.idl
 */

#ifndef __gen_nsIDOMSVGAnimPresAspRatio_h__
#define __gen_nsIDOMSVGAnimPresAspRatio_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGPreserveAspectRatio; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedPreserveAspectRatio */
#define NS_IDOMSVGANIMATEDPRESERVEASPECTRATIO_IID_STR "afcd7cd4-d74d-492f-b3b1-d71bfa36874f"

#define NS_IDOMSVGANIMATEDPRESERVEASPECTRATIO_IID \
  {0xafcd7cd4, 0xd74d, 0x492f, \
    { 0xb3, 0xb1, 0xd7, 0x1b, 0xfa, 0x36, 0x87, 0x4f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedPreserveAspectRatio : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDPRESERVEASPECTRATIO_IID)

  /* readonly attribute nsIDOMSVGPreserveAspectRatio baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGPreserveAspectRatio * *aBaseVal) = 0;

  /* readonly attribute nsIDOMSVGPreserveAspectRatio animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGPreserveAspectRatio * *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedPreserveAspectRatio, NS_IDOMSVGANIMATEDPRESERVEASPECTRATIO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDPRESERVEASPECTRATIO \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGPreserveAspectRatio * *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGPreserveAspectRatio * *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDPRESERVEASPECTRATIO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGPreserveAspectRatio * *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGPreserveAspectRatio * *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDPRESERVEASPECTRATIO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGPreserveAspectRatio * *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGPreserveAspectRatio * *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedPreserveAspectRatio : public nsIDOMSVGAnimatedPreserveAspectRatio
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDPRESERVEASPECTRATIO

  nsDOMSVGAnimatedPreserveAspectRatio();

private:
  ~nsDOMSVGAnimatedPreserveAspectRatio();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedPreserveAspectRatio, nsIDOMSVGAnimatedPreserveAspectRatio)

nsDOMSVGAnimatedPreserveAspectRatio::nsDOMSVGAnimatedPreserveAspectRatio()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedPreserveAspectRatio::~nsDOMSVGAnimatedPreserveAspectRatio()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGPreserveAspectRatio baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedPreserveAspectRatio::GetBaseVal(nsIDOMSVGPreserveAspectRatio * *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGPreserveAspectRatio animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedPreserveAspectRatio::GetAnimVal(nsIDOMSVGPreserveAspectRatio * *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimPresAspRatio_h__ */
