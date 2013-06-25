/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedInteger.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedInteger_h__
#define __gen_nsIDOMSVGAnimatedInteger_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAnimatedInteger */
#define NS_IDOMSVGANIMATEDINTEGER_IID_STR "7b196db6-955e-4a9f-8f42-645ebc2ce938"

#define NS_IDOMSVGANIMATEDINTEGER_IID \
  {0x7b196db6, 0x955e, 0x4a9f, \
    { 0x8f, 0x42, 0x64, 0x5e, 0xbc, 0x2c, 0xe9, 0x38 }}

/**
 * The nsIDOMSVGAnimatedNumber interface is the interface to an SVG
 * Animated Integer.
 *
 * For more information on this interface please see
 * http://www.w3.org/TR/SVG11/types.html
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedInteger : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDINTEGER_IID)

  /* attribute long baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRInt32 *aBaseVal) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRInt32 aBaseVal) = 0;

  /* readonly attribute long animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRInt32 *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedInteger, NS_IDOMSVGANIMATEDINTEGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDINTEGER \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRInt32 *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRInt32 aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRInt32 *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDINTEGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRInt32 *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRInt32 aBaseVal) { return _to SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRInt32 *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDINTEGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRInt32 *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRInt32 aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRInt32 *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedInteger : public nsIDOMSVGAnimatedInteger
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDINTEGER

  nsDOMSVGAnimatedInteger();

private:
  ~nsDOMSVGAnimatedInteger();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedInteger, nsIDOMSVGAnimatedInteger)

nsDOMSVGAnimatedInteger::nsDOMSVGAnimatedInteger()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedInteger::~nsDOMSVGAnimatedInteger()
{
  /* destructor code */
}

/* attribute long baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedInteger::GetBaseVal(PRInt32 *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAnimatedInteger::SetBaseVal(PRInt32 aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedInteger::GetAnimVal(PRInt32 *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedInteger_h__ */
