/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGPatternElement.idl
 */

#ifndef __gen_nsIDOMSVGPatternElement_h__
#define __gen_nsIDOMSVGPatternElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedEnumeration; /* forward declaration */

class nsIDOMSVGAnimatedTransformList; /* forward declaration */

class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGPatternElement */
#define NS_IDOMSVGPATTERNELEMENT_IID_STR "bc435244-b748-4e14-9e4c-219d5d3cb218"

#define NS_IDOMSVGPATTERNELEMENT_IID \
  {0xbc435244, 0xb748, 0x4e14, \
    { 0x9e, 0x4c, 0x21, 0x9d, 0x5d, 0x3c, 0xb2, 0x18 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPatternElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATTERNELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedEnumeration patternUnits; */
  NS_SCRIPTABLE NS_IMETHOD GetPatternUnits(nsIDOMSVGAnimatedEnumeration * *aPatternUnits) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration patternContentUnits; */
  NS_SCRIPTABLE NS_IMETHOD GetPatternContentUnits(nsIDOMSVGAnimatedEnumeration * *aPatternContentUnits) = 0;

  /* readonly attribute nsIDOMSVGAnimatedTransformList patternTransform; */
  NS_SCRIPTABLE NS_IMETHOD GetPatternTransform(nsIDOMSVGAnimatedTransformList * *aPatternTransform) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPatternElement, NS_IDOMSVGPATTERNELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATTERNELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetPatternUnits(nsIDOMSVGAnimatedEnumeration * *aPatternUnits); \
  NS_SCRIPTABLE NS_IMETHOD GetPatternContentUnits(nsIDOMSVGAnimatedEnumeration * *aPatternContentUnits); \
  NS_SCRIPTABLE NS_IMETHOD GetPatternTransform(nsIDOMSVGAnimatedTransformList * *aPatternTransform); \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATTERNELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPatternUnits(nsIDOMSVGAnimatedEnumeration * *aPatternUnits) { return _to GetPatternUnits(aPatternUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatternContentUnits(nsIDOMSVGAnimatedEnumeration * *aPatternContentUnits) { return _to GetPatternContentUnits(aPatternContentUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatternTransform(nsIDOMSVGAnimatedTransformList * *aPatternTransform) { return _to GetPatternTransform(aPatternTransform); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATTERNELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPatternUnits(nsIDOMSVGAnimatedEnumeration * *aPatternUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPatternUnits(aPatternUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatternContentUnits(nsIDOMSVGAnimatedEnumeration * *aPatternContentUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPatternContentUnits(aPatternContentUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatternTransform(nsIDOMSVGAnimatedTransformList * *aPatternTransform) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPatternTransform(aPatternTransform); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPatternElement : public nsIDOMSVGPatternElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATTERNELEMENT

  nsDOMSVGPatternElement();

private:
  ~nsDOMSVGPatternElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPatternElement, nsIDOMSVGPatternElement)

nsDOMSVGPatternElement::nsDOMSVGPatternElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGPatternElement::~nsDOMSVGPatternElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration patternUnits; */
NS_IMETHODIMP nsDOMSVGPatternElement::GetPatternUnits(nsIDOMSVGAnimatedEnumeration * *aPatternUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration patternContentUnits; */
NS_IMETHODIMP nsDOMSVGPatternElement::GetPatternContentUnits(nsIDOMSVGAnimatedEnumeration * *aPatternContentUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedTransformList patternTransform; */
NS_IMETHODIMP nsDOMSVGPatternElement::GetPatternTransform(nsIDOMSVGAnimatedTransformList * *aPatternTransform)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGPatternElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGPatternElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGPatternElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGPatternElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGPatternElement_h__ */
