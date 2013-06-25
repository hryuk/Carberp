/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGTransformable.idl
 */

#ifndef __gen_nsIDOMSVGTransformable_h__
#define __gen_nsIDOMSVGTransformable_h__


#ifndef __gen_nsIDOMSVGLocatable_h__
#include "nsIDOMSVGLocatable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedTransformList; /* forward declaration */


/* starting interface:    nsIDOMSVGTransformable */
#define NS_IDOMSVGTRANSFORMABLE_IID_STR "b81f6e37-1842-4534-a546-1ab86e59a3c6"

#define NS_IDOMSVGTRANSFORMABLE_IID \
  {0xb81f6e37, 0x1842, 0x4534, \
    { 0xa5, 0x46, 0x1a, 0xb8, 0x6e, 0x59, 0xa3, 0xc6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGTransformable : public nsIDOMSVGLocatable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTRANSFORMABLE_IID)

  /* readonly attribute nsIDOMSVGAnimatedTransformList transform; */
  NS_SCRIPTABLE NS_IMETHOD GetTransform(nsIDOMSVGAnimatedTransformList * *aTransform) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTransformable, NS_IDOMSVGTRANSFORMABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTRANSFORMABLE \
  NS_SCRIPTABLE NS_IMETHOD GetTransform(nsIDOMSVGAnimatedTransformList * *aTransform); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTRANSFORMABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTransform(nsIDOMSVGAnimatedTransformList * *aTransform) { return _to GetTransform(aTransform); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTRANSFORMABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTransform(nsIDOMSVGAnimatedTransformList * *aTransform) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransform(aTransform); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTransformable : public nsIDOMSVGTransformable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTRANSFORMABLE

  nsDOMSVGTransformable();

private:
  ~nsDOMSVGTransformable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTransformable, nsIDOMSVGTransformable)

nsDOMSVGTransformable::nsDOMSVGTransformable()
{
  /* member initializers and constructor code */
}

nsDOMSVGTransformable::~nsDOMSVGTransformable()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedTransformList transform; */
NS_IMETHODIMP nsDOMSVGTransformable::GetTransform(nsIDOMSVGAnimatedTransformList * *aTransform)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTransformable_h__ */
