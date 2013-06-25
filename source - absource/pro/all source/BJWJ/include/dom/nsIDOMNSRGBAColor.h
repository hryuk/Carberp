/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMNSRGBAColor.idl
 */

#ifndef __gen_nsIDOMNSRGBAColor_h__
#define __gen_nsIDOMNSRGBAColor_h__


#ifndef __gen_nsIDOMRGBColor_h__
#include "nsIDOMRGBColor.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSRGBAColor */
#define NS_IDOMNSRGBACOLOR_IID_STR "742dc816-5134-4214-adfa-cad9dd3377cd"

#define NS_IDOMNSRGBACOLOR_IID \
  {0x742dc816, 0x5134, 0x4214, \
    { 0xad, 0xfa, 0xca, 0xd9, 0xdd, 0x33, 0x77, 0xcd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSRGBAColor : public nsIDOMRGBColor {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSRGBACOLOR_IID)

  /* readonly attribute nsIDOMCSSPrimitiveValue alpha; */
  NS_SCRIPTABLE NS_IMETHOD GetAlpha(nsIDOMCSSPrimitiveValue * *aAlpha) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSRGBAColor, NS_IDOMNSRGBACOLOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSRGBACOLOR \
  NS_SCRIPTABLE NS_IMETHOD GetAlpha(nsIDOMCSSPrimitiveValue * *aAlpha); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSRGBACOLOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAlpha(nsIDOMCSSPrimitiveValue * *aAlpha) { return _to GetAlpha(aAlpha); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSRGBACOLOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAlpha(nsIDOMCSSPrimitiveValue * *aAlpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlpha(aAlpha); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSRGBAColor : public nsIDOMNSRGBAColor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSRGBACOLOR

  nsDOMNSRGBAColor();

private:
  ~nsDOMNSRGBAColor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSRGBAColor, nsIDOMNSRGBAColor)

nsDOMNSRGBAColor::nsDOMNSRGBAColor()
{
  /* member initializers and constructor code */
}

nsDOMNSRGBAColor::~nsDOMNSRGBAColor()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSPrimitiveValue alpha; */
NS_IMETHODIMP nsDOMNSRGBAColor::GetAlpha(nsIDOMCSSPrimitiveValue * *aAlpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSRGBAColor_h__ */
