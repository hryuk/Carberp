/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGClipPathElement.idl
 */

#ifndef __gen_nsIDOMSVGClipPathElement_h__
#define __gen_nsIDOMSVGClipPathElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedEnumeration; /* forward declaration */


/* starting interface:    nsIDOMSVGClipPathElement */
#define NS_IDOMSVGCLIPPATHELEMENT_IID_STR "0c3f45a4-e6d0-44e7-a2f8-d128ecf1db9b"

#define NS_IDOMSVGCLIPPATHELEMENT_IID \
  {0x0c3f45a4, 0xe6d0, 0x44e7, \
    { 0xa2, 0xf8, 0xd1, 0x28, 0xec, 0xf1, 0xdb, 0x9b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGClipPathElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGCLIPPATHELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedEnumeration clipPathUnits; */
  NS_SCRIPTABLE NS_IMETHOD GetClipPathUnits(nsIDOMSVGAnimatedEnumeration * *aClipPathUnits) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGClipPathElement, NS_IDOMSVGCLIPPATHELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGCLIPPATHELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetClipPathUnits(nsIDOMSVGAnimatedEnumeration * *aClipPathUnits); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGCLIPPATHELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClipPathUnits(nsIDOMSVGAnimatedEnumeration * *aClipPathUnits) { return _to GetClipPathUnits(aClipPathUnits); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGCLIPPATHELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClipPathUnits(nsIDOMSVGAnimatedEnumeration * *aClipPathUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClipPathUnits(aClipPathUnits); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGClipPathElement : public nsIDOMSVGClipPathElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGCLIPPATHELEMENT

  nsDOMSVGClipPathElement();

private:
  ~nsDOMSVGClipPathElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGClipPathElement, nsIDOMSVGClipPathElement)

nsDOMSVGClipPathElement::nsDOMSVGClipPathElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGClipPathElement::~nsDOMSVGClipPathElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration clipPathUnits; */
NS_IMETHODIMP nsDOMSVGClipPathElement::GetClipPathUnits(nsIDOMSVGAnimatedEnumeration * *aClipPathUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGClipPathElement_h__ */
