/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGRectElement.idl
 */

#ifndef __gen_nsIDOMSVGRectElement_h__
#define __gen_nsIDOMSVGRectElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGRectElement */
#define NS_IDOMSVGRECTELEMENT_IID_STR "1695ca39-e40d-44dc-81db-a51b6fd234fa"

#define NS_IDOMSVGRECTELEMENT_IID \
  {0x1695ca39, 0xe40d, 0x44dc, \
    { 0x81, 0xdb, 0xa5, 0x1b, 0x6f, 0xd2, 0x34, 0xfa }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGRectElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGRECTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength rx; */
  NS_SCRIPTABLE NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength ry; */
  NS_SCRIPTABLE NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGRectElement, NS_IDOMSVGRECTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGRECTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx); \
  NS_SCRIPTABLE NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGRECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx) { return _to GetRx(aRx); } \
  NS_SCRIPTABLE NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy) { return _to GetRy(aRy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGRECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRx(aRx); } \
  NS_SCRIPTABLE NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRy(aRy); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGRectElement : public nsIDOMSVGRectElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGRECTELEMENT

  nsDOMSVGRectElement();

private:
  ~nsDOMSVGRectElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGRectElement, nsIDOMSVGRectElement)

nsDOMSVGRectElement::nsDOMSVGRectElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGRectElement::~nsDOMSVGRectElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGRectElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGRectElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGRectElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGRectElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength rx; */
NS_IMETHODIMP nsDOMSVGRectElement::GetRx(nsIDOMSVGAnimatedLength * *aRx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength ry; */
NS_IMETHODIMP nsDOMSVGRectElement::GetRy(nsIDOMSVGAnimatedLength * *aRy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGRectElement_h__ */
