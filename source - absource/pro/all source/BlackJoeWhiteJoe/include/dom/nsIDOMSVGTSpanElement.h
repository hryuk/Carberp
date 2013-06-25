/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGTSpanElement.idl
 */

#ifndef __gen_nsIDOMSVGTSpanElement_h__
#define __gen_nsIDOMSVGTSpanElement_h__


#ifndef __gen_nsIDOMSVGTextPositionElem_h__
#include "nsIDOMSVGTextPositionElem.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGTSpanElement */
#define NS_IDOMSVGTSPANELEMENT_IID_STR "4a23cb1f-cf1e-437e-9524-8756f7928b2e"

#define NS_IDOMSVGTSPANELEMENT_IID \
  {0x4a23cb1f, 0xcf1e, 0x437e, \
    { 0x95, 0x24, 0x87, 0x56, 0xf7, 0x92, 0x8b, 0x2e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGTSpanElement : public nsIDOMSVGTextPositioningElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTSPANELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTSpanElement, NS_IDOMSVGTSPANELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTSPANELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTSPANELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTSPANELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTSpanElement : public nsIDOMSVGTSpanElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTSPANELEMENT

  nsDOMSVGTSpanElement();

private:
  ~nsDOMSVGTSpanElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTSpanElement, nsIDOMSVGTSpanElement)

nsDOMSVGTSpanElement::nsDOMSVGTSpanElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGTSpanElement::~nsDOMSVGTSpanElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTSpanElement_h__ */
