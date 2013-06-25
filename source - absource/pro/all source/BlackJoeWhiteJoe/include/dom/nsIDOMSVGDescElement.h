/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGDescElement.idl
 */

#ifndef __gen_nsIDOMSVGDescElement_h__
#define __gen_nsIDOMSVGDescElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGDescElement */
#define NS_IDOMSVGDESCELEMENT_IID_STR "56f539b7-0b3d-4bac-b60d-9efe220216ea"

#define NS_IDOMSVGDESCELEMENT_IID \
  {0x56f539b7, 0x0b3d, 0x4bac, \
    { 0xb6, 0x0d, 0x9e, 0xfe, 0x22, 0x02, 0x16, 0xea }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGDescElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGDESCELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGDescElement, NS_IDOMSVGDESCELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGDESCELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGDESCELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGDESCELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGDescElement : public nsIDOMSVGDescElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGDESCELEMENT

  nsDOMSVGDescElement();

private:
  ~nsDOMSVGDescElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGDescElement, nsIDOMSVGDescElement)

nsDOMSVGDescElement::nsDOMSVGDescElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGDescElement::~nsDOMSVGDescElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGDescElement_h__ */
