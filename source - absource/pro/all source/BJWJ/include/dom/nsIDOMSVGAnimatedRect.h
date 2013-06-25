/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedRect.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedRect_h__
#define __gen_nsIDOMSVGAnimatedRect_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGRect; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedRect */
#define NS_IDOMSVGANIMATEDRECT_IID_STR "ca45959e-f1da-46f6-af19-1ecdc322285a"

#define NS_IDOMSVGANIMATEDRECT_IID \
  {0xca45959e, 0xf1da, 0x46f6, \
    { 0xaf, 0x19, 0x1e, 0xcd, 0xc3, 0x22, 0x28, 0x5a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedRect : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDRECT_IID)

  /* readonly attribute nsIDOMSVGRect baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGRect * *aBaseVal) = 0;

  /* readonly attribute nsIDOMSVGRect animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGRect * *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedRect, NS_IDOMSVGANIMATEDRECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDRECT \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGRect * *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGRect * *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDRECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGRect * *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGRect * *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDRECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGRect * *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGRect * *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedRect : public nsIDOMSVGAnimatedRect
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDRECT

  nsDOMSVGAnimatedRect();

private:
  ~nsDOMSVGAnimatedRect();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedRect, nsIDOMSVGAnimatedRect)

nsDOMSVGAnimatedRect::nsDOMSVGAnimatedRect()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedRect::~nsDOMSVGAnimatedRect()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGRect baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedRect::GetBaseVal(nsIDOMSVGRect * *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGRect animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedRect::GetAnimVal(nsIDOMSVGRect * *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedRect_h__ */
