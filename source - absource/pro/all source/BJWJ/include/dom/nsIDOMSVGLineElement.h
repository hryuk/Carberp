/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGLineElement.idl
 */

#ifndef __gen_nsIDOMSVGLineElement_h__
#define __gen_nsIDOMSVGLineElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGLineElement */
#define NS_IDOMSVGLINEELEMENT_IID_STR "4ea07ef3-ed66-4b41-8119-4afc6d0ed5af"

#define NS_IDOMSVGLINEELEMENT_IID \
  {0x4ea07ef3, 0xed66, 0x4b41, \
    { 0x81, 0x19, 0x4a, 0xfc, 0x6d, 0x0e, 0xd5, 0xaf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGLineElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGLINEELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x1; */
  NS_SCRIPTABLE NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y1; */
  NS_SCRIPTABLE NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength x2; */
  NS_SCRIPTABLE NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y2; */
  NS_SCRIPTABLE NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGLineElement, NS_IDOMSVGLINEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGLINEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1); \
  NS_SCRIPTABLE NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1); \
  NS_SCRIPTABLE NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2); \
  NS_SCRIPTABLE NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGLINEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1) { return _to GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1) { return _to GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2) { return _to GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2) { return _to GetY2(aY2); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGLINEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY2(aY2); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGLineElement : public nsIDOMSVGLineElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGLINEELEMENT

  nsDOMSVGLineElement();

private:
  ~nsDOMSVGLineElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGLineElement, nsIDOMSVGLineElement)

nsDOMSVGLineElement::nsDOMSVGLineElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGLineElement::~nsDOMSVGLineElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x1; */
NS_IMETHODIMP nsDOMSVGLineElement::GetX1(nsIDOMSVGAnimatedLength * *aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y1; */
NS_IMETHODIMP nsDOMSVGLineElement::GetY1(nsIDOMSVGAnimatedLength * *aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength x2; */
NS_IMETHODIMP nsDOMSVGLineElement::GetX2(nsIDOMSVGAnimatedLength * *aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y2; */
NS_IMETHODIMP nsDOMSVGLineElement::GetY2(nsIDOMSVGAnimatedLength * *aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGLineElement_h__ */
