/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGForeignObjectElem.idl
 */

#ifndef __gen_nsIDOMSVGForeignObjectElem_h__
#define __gen_nsIDOMSVGForeignObjectElem_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGForeignObjectElement */
#define NS_IDOMSVGFOREIGNOBJECTELEMENT_IID_STR "fd9c9871-23fd-48eb-a65b-3842e9b0acbd"

#define NS_IDOMSVGFOREIGNOBJECTELEMENT_IID \
  {0xfd9c9871, 0x23fd, 0x48eb, \
    { 0xa6, 0x5b, 0x38, 0x42, 0xe9, 0xb0, 0xac, 0xbd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGForeignObjectElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFOREIGNOBJECTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGForeignObjectElement, NS_IDOMSVGFOREIGNOBJECTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFOREIGNOBJECTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFOREIGNOBJECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFOREIGNOBJECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGForeignObjectElement : public nsIDOMSVGForeignObjectElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFOREIGNOBJECTELEMENT

  nsDOMSVGForeignObjectElement();

private:
  ~nsDOMSVGForeignObjectElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGForeignObjectElement, nsIDOMSVGForeignObjectElement)

nsDOMSVGForeignObjectElement::nsDOMSVGForeignObjectElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGForeignObjectElement::~nsDOMSVGForeignObjectElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGForeignObjectElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGForeignObjectElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGForeignObjectElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGForeignObjectElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGForeignObjectElem_h__ */
