/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGDefsElement.idl
 */

#ifndef __gen_nsIDOMSVGDefsElement_h__
#define __gen_nsIDOMSVGDefsElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGDefsElement */
#define NS_IDOMSVGDEFSELEMENT_IID_STR "a2e86036-f04c-4013-9f74-e7090a0aac0a"

#define NS_IDOMSVGDEFSELEMENT_IID \
  {0xa2e86036, 0xf04c, 0x4013, \
    { 0x9f, 0x74, 0xe7, 0x09, 0x0a, 0x0a, 0xac, 0x0a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGDefsElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGDEFSELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGDefsElement, NS_IDOMSVGDEFSELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGDEFSELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGDEFSELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGDEFSELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGDefsElement : public nsIDOMSVGDefsElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGDEFSELEMENT

  nsDOMSVGDefsElement();

private:
  ~nsDOMSVGDefsElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGDefsElement, nsIDOMSVGDefsElement)

nsDOMSVGDefsElement::nsDOMSVGDefsElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGDefsElement::~nsDOMSVGDefsElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGDefsElement_h__ */
