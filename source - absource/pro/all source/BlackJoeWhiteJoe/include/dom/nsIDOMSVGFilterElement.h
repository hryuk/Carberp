/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGFilterElement.idl
 */

#ifndef __gen_nsIDOMSVGFilterElement_h__
#define __gen_nsIDOMSVGFilterElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */

class nsIDOMSVGAnimatedEnumeration; /* forward declaration */

class nsIDOMSVGAnimatedInteger; /* forward declaration */


/* starting interface:    nsIDOMSVGFilterElement */
#define NS_IDOMSVGFILTERELEMENT_IID_STR "9e81d4ae-190c-4b9d-a076-ebc52a7bf231"

#define NS_IDOMSVGFILTERELEMENT_IID \
  {0x9e81d4ae, 0x190c, 0x4b9d, \
    { 0xa0, 0x76, 0xeb, 0xc5, 0x2a, 0x7b, 0xf2, 0x31 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFilterElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFILTERELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedEnumeration filterUnits; */
  NS_SCRIPTABLE NS_IMETHOD GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration primitiveUnits; */
  NS_SCRIPTABLE NS_IMETHOD GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

  /* readonly attribute nsIDOMSVGAnimatedInteger filterResX; */
  NS_SCRIPTABLE NS_IMETHOD GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedInteger filterResY; */
  NS_SCRIPTABLE NS_IMETHOD GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY) = 0;

  /* void setFilterRes (in unsigned long filterResX, in unsigned long filterResY); */
  NS_SCRIPTABLE NS_IMETHOD SetFilterRes(PRUint32 filterResX, PRUint32 filterResY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFilterElement, NS_IDOMSVGFILTERELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFILTERELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits); \
  NS_SCRIPTABLE NS_IMETHOD GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits); \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX); \
  NS_SCRIPTABLE NS_IMETHOD GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY); \
  NS_SCRIPTABLE NS_IMETHOD SetFilterRes(PRUint32 filterResX, PRUint32 filterResY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFILTERELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits) { return _to GetFilterUnits(aFilterUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits) { return _to GetPrimitiveUnits(aPrimitiveUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX) { return _to GetFilterResX(aFilterResX); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY) { return _to GetFilterResY(aFilterResY); } \
  NS_SCRIPTABLE NS_IMETHOD SetFilterRes(PRUint32 filterResX, PRUint32 filterResY) { return _to SetFilterRes(filterResX, filterResY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFILTERELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterUnits(aFilterUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimitiveUnits(aPrimitiveUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterResX(aFilterResX); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterResY(aFilterResY); } \
  NS_SCRIPTABLE NS_IMETHOD SetFilterRes(PRUint32 filterResX, PRUint32 filterResY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilterRes(filterResX, filterResY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFilterElement : public nsIDOMSVGFilterElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFILTERELEMENT

  nsDOMSVGFilterElement();

private:
  ~nsDOMSVGFilterElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFilterElement, nsIDOMSVGFilterElement)

nsDOMSVGFilterElement::nsDOMSVGFilterElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFilterElement::~nsDOMSVGFilterElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration filterUnits; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration primitiveUnits; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedInteger filterResX; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedInteger filterResY; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFilterRes (in unsigned long filterResX, in unsigned long filterResY); */
NS_IMETHODIMP nsDOMSVGFilterElement::SetFilterRes(PRUint32 filterResX, PRUint32 filterResY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGFilterElement_h__ */
