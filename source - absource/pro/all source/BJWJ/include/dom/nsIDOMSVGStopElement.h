/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGStopElement.idl
 */

#ifndef __gen_nsIDOMSVGStopElement_h__
#define __gen_nsIDOMSVGStopElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedNumber; /* forward declaration */


/* starting interface:    nsIDOMSVGStopElement */
#define NS_IDOMSVGSTOPELEMENT_IID_STR "93169940-7663-4eab-af23-94a8a08c2654"

#define NS_IDOMSVGSTOPELEMENT_IID \
  {0x93169940, 0x7663, 0x4eab, \
    { 0xaf, 0x23, 0x94, 0xa8, 0xa0, 0x8c, 0x26, 0x54 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGStopElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSTOPELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedNumber offset; */
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGStopElement, NS_IDOMSVGSTOPELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSTOPELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSTOPELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) { return _to GetOffset(aOffset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSTOPELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffset(aOffset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGStopElement : public nsIDOMSVGStopElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSTOPELEMENT

  nsDOMSVGStopElement();

private:
  ~nsDOMSVGStopElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGStopElement, nsIDOMSVGStopElement)

nsDOMSVGStopElement::nsDOMSVGStopElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGStopElement::~nsDOMSVGStopElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedNumber offset; */
NS_IMETHODIMP nsDOMSVGStopElement::GetOffset(nsIDOMSVGAnimatedNumber * *aOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGStopElement_h__ */
