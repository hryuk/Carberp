/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGImageElement.idl
 */

#ifndef __gen_nsIDOMSVGImageElement_h__
#define __gen_nsIDOMSVGImageElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */

class nsIDOMSVGAnimatedPreserveAspectRatio; /* forward declaration */


/* starting interface:    nsIDOMSVGImageElement */
#define NS_IDOMSVGIMAGEELEMENT_IID_STR "43ae4efe-2610-4cce-8242-279e556a78fa"

#define NS_IDOMSVGIMAGEELEMENT_IID \
  {0x43ae4efe, 0x2610, 0x4cce, \
    { 0x82, 0x42, 0x27, 0x9e, 0x55, 0x6a, 0x78, 0xfa }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGImageElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGIMAGEELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

  /* readonly attribute nsIDOMSVGAnimatedPreserveAspectRatio preserveAspectRatio; */
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGImageElement, NS_IDOMSVGIMAGEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGIMAGEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGIMAGEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio) { return _to GetPreserveAspectRatio(aPreserveAspectRatio); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGIMAGEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreserveAspectRatio(aPreserveAspectRatio); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGImageElement : public nsIDOMSVGImageElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGIMAGEELEMENT

  nsDOMSVGImageElement();

private:
  ~nsDOMSVGImageElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGImageElement, nsIDOMSVGImageElement)

nsDOMSVGImageElement::nsDOMSVGImageElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGImageElement::~nsDOMSVGImageElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGImageElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGImageElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGImageElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGImageElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedPreserveAspectRatio preserveAspectRatio; */
NS_IMETHODIMP nsDOMSVGImageElement::GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGImageElement_h__ */
