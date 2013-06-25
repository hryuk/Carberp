/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGURIReference.idl
 */

#ifndef __gen_nsIDOMSVGURIReference_h__
#define __gen_nsIDOMSVGURIReference_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedString; /* forward declaration */


/* starting interface:    nsIDOMSVGURIReference */
#define NS_IDOMSVGURIREFERENCE_IID_STR "8092b5f3-dc8a-459c-94f1-92f8011f2438"

#define NS_IDOMSVGURIREFERENCE_IID \
  {0x8092b5f3, 0xdc8a, 0x459c, \
    { 0x94, 0xf1, 0x92, 0xf8, 0x01, 0x1f, 0x24, 0x38 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGURIReference : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGURIREFERENCE_IID)

  /* readonly attribute nsIDOMSVGAnimatedString href; */
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsIDOMSVGAnimatedString * *aHref) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGURIReference, NS_IDOMSVGURIREFERENCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGURIREFERENCE \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsIDOMSVGAnimatedString * *aHref); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGURIREFERENCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsIDOMSVGAnimatedString * *aHref) { return _to GetHref(aHref); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGURIREFERENCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsIDOMSVGAnimatedString * *aHref) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGURIReference : public nsIDOMSVGURIReference
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGURIREFERENCE

  nsDOMSVGURIReference();

private:
  ~nsDOMSVGURIReference();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGURIReference, nsIDOMSVGURIReference)

nsDOMSVGURIReference::nsDOMSVGURIReference()
{
  /* member initializers and constructor code */
}

nsDOMSVGURIReference::~nsDOMSVGURIReference()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString href; */
NS_IMETHODIMP nsDOMSVGURIReference::GetHref(nsIDOMSVGAnimatedString * *aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGURIReference_h__ */
