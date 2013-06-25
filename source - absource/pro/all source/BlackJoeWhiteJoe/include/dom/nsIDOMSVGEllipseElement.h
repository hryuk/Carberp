/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGEllipseElement.idl
 */

#ifndef __gen_nsIDOMSVGEllipseElement_h__
#define __gen_nsIDOMSVGEllipseElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGEllipseElement */
#define NS_IDOMSVGELLIPSEELEMENT_IID_STR "5d1cd1e6-4a14-4056-acc0-2f78c1672898"

#define NS_IDOMSVGELLIPSEELEMENT_IID \
  {0x5d1cd1e6, 0x4a14, 0x4056, \
    { 0xac, 0xc0, 0x2f, 0x78, 0xc1, 0x67, 0x28, 0x98 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGEllipseElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGELLIPSEELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength cx; */
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength cy; */
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength rx; */
  NS_SCRIPTABLE NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength ry; */
  NS_SCRIPTABLE NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGEllipseElement, NS_IDOMSVGELLIPSEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGELLIPSEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx); \
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy); \
  NS_SCRIPTABLE NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx); \
  NS_SCRIPTABLE NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGELLIPSEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) { return _to GetCx(aCx); } \
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) { return _to GetCy(aCy); } \
  NS_SCRIPTABLE NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx) { return _to GetRx(aRx); } \
  NS_SCRIPTABLE NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy) { return _to GetRy(aRy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGELLIPSEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCx(aCx); } \
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCy(aCy); } \
  NS_SCRIPTABLE NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRx(aRx); } \
  NS_SCRIPTABLE NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRy(aRy); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGEllipseElement : public nsIDOMSVGEllipseElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGELLIPSEELEMENT

  nsDOMSVGEllipseElement();

private:
  ~nsDOMSVGEllipseElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGEllipseElement, nsIDOMSVGEllipseElement)

nsDOMSVGEllipseElement::nsDOMSVGEllipseElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGEllipseElement::~nsDOMSVGEllipseElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength cx; */
NS_IMETHODIMP nsDOMSVGEllipseElement::GetCx(nsIDOMSVGAnimatedLength * *aCx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength cy; */
NS_IMETHODIMP nsDOMSVGEllipseElement::GetCy(nsIDOMSVGAnimatedLength * *aCy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength rx; */
NS_IMETHODIMP nsDOMSVGEllipseElement::GetRx(nsIDOMSVGAnimatedLength * *aRx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength ry; */
NS_IMETHODIMP nsDOMSVGEllipseElement::GetRy(nsIDOMSVGAnimatedLength * *aRy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGEllipseElement_h__ */
