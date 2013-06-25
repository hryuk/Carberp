/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGTextPositionElem.idl
 */

#ifndef __gen_nsIDOMSVGTextPositionElem_h__
#define __gen_nsIDOMSVGTextPositionElem_h__


#ifndef __gen_nsIDOMSVGTextContentElement_h__
#include "nsIDOMSVGTextContentElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLengthList; /* forward declaration */

class nsIDOMSVGAnimatedNumberList; /* forward declaration */


/* starting interface:    nsIDOMSVGTextPositioningElement */
#define NS_IDOMSVGTEXTPOSITIONINGELEMENT_IID_STR "5d052835-8cb0-442c-9754-a8e616db1f89"

#define NS_IDOMSVGTEXTPOSITIONINGELEMENT_IID \
  {0x5d052835, 0x8cb0, 0x442c, \
    { 0x97, 0x54, 0xa8, 0xe6, 0x16, 0xdb, 0x1f, 0x89 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGTextPositioningElement : public nsIDOMSVGTextContentElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTEXTPOSITIONINGELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLengthList x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLengthList * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLengthList y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLengthList * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLengthList dx; */
  NS_SCRIPTABLE NS_IMETHOD GetDx(nsIDOMSVGAnimatedLengthList * *aDx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLengthList dy; */
  NS_SCRIPTABLE NS_IMETHOD GetDy(nsIDOMSVGAnimatedLengthList * *aDy) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumberList rotate; */
  NS_SCRIPTABLE NS_IMETHOD GetRotate(nsIDOMSVGAnimatedNumberList * *aRotate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTextPositioningElement, NS_IDOMSVGTEXTPOSITIONINGELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTEXTPOSITIONINGELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLengthList * *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLengthList * *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetDx(nsIDOMSVGAnimatedLengthList * *aDx); \
  NS_SCRIPTABLE NS_IMETHOD GetDy(nsIDOMSVGAnimatedLengthList * *aDy); \
  NS_SCRIPTABLE NS_IMETHOD GetRotate(nsIDOMSVGAnimatedNumberList * *aRotate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTEXTPOSITIONINGELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLengthList * *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLengthList * *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetDx(nsIDOMSVGAnimatedLengthList * *aDx) { return _to GetDx(aDx); } \
  NS_SCRIPTABLE NS_IMETHOD GetDy(nsIDOMSVGAnimatedLengthList * *aDy) { return _to GetDy(aDy); } \
  NS_SCRIPTABLE NS_IMETHOD GetRotate(nsIDOMSVGAnimatedNumberList * *aRotate) { return _to GetRotate(aRotate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTEXTPOSITIONINGELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLengthList * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLengthList * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetDx(nsIDOMSVGAnimatedLengthList * *aDx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDx(aDx); } \
  NS_SCRIPTABLE NS_IMETHOD GetDy(nsIDOMSVGAnimatedLengthList * *aDy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDy(aDy); } \
  NS_SCRIPTABLE NS_IMETHOD GetRotate(nsIDOMSVGAnimatedNumberList * *aRotate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRotate(aRotate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTextPositioningElement : public nsIDOMSVGTextPositioningElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTEXTPOSITIONINGELEMENT

  nsDOMSVGTextPositioningElement();

private:
  ~nsDOMSVGTextPositioningElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTextPositioningElement, nsIDOMSVGTextPositioningElement)

nsDOMSVGTextPositioningElement::nsDOMSVGTextPositioningElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGTextPositioningElement::~nsDOMSVGTextPositioningElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLengthList x; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetX(nsIDOMSVGAnimatedLengthList * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLengthList y; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetY(nsIDOMSVGAnimatedLengthList * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLengthList dx; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetDx(nsIDOMSVGAnimatedLengthList * *aDx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLengthList dy; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetDy(nsIDOMSVGAnimatedLengthList * *aDy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumberList rotate; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetRotate(nsIDOMSVGAnimatedNumberList * *aRotate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTextPositionElem_h__ */
