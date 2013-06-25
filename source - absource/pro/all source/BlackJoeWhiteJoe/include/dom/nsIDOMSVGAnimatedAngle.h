/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedAngle.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedAngle_h__
#define __gen_nsIDOMSVGAnimatedAngle_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAngle; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedAngle */
#define NS_IDOMSVGANIMATEDANGLE_IID_STR "c6ab8b9e-32db-464a-ae33-8691d44bc60a"

#define NS_IDOMSVGANIMATEDANGLE_IID \
  {0xc6ab8b9e, 0x32db, 0x464a, \
    { 0xae, 0x33, 0x86, 0x91, 0xd4, 0x4b, 0xc6, 0x0a }}

/**
 * The nsIDOMSVGAnimatedAngle interface is the interface to an SVG
 * animated angle.
 *
 * For more information on this interface please see
 * http://www.w3.org/TR/SVG11/types.html#InterfaceSVGAnimatedAngle
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedAngle : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDANGLE_IID)

  /* readonly attribute nsIDOMSVGAngle baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGAngle * *aBaseVal) = 0;

  /* readonly attribute nsIDOMSVGAngle animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGAngle * *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedAngle, NS_IDOMSVGANIMATEDANGLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDANGLE \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGAngle * *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGAngle * *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDANGLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGAngle * *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGAngle * *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDANGLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGAngle * *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGAngle * *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedAngle : public nsIDOMSVGAnimatedAngle
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDANGLE

  nsDOMSVGAnimatedAngle();

private:
  ~nsDOMSVGAnimatedAngle();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedAngle, nsIDOMSVGAnimatedAngle)

nsDOMSVGAnimatedAngle::nsDOMSVGAnimatedAngle()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedAngle::~nsDOMSVGAnimatedAngle()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAngle baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedAngle::GetBaseVal(nsIDOMSVGAngle * *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAngle animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedAngle::GetAnimVal(nsIDOMSVGAngle * *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedAngle_h__ */
