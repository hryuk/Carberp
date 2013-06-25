/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedBoolean.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedBoolean_h__
#define __gen_nsIDOMSVGAnimatedBoolean_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAnimatedBoolean */
#define NS_IDOMSVGANIMATEDBOOLEAN_IID_STR "7e325385-cc82-4763-bd14-e2c92edd5462"

#define NS_IDOMSVGANIMATEDBOOLEAN_IID \
  {0x7e325385, 0xcc82, 0x4763, \
    { 0xbd, 0x14, 0xe2, 0xc9, 0x2e, 0xdd, 0x54, 0x62 }}

/**
 * The nsIDOMSVGAnimatedBoolean interface is the interface to an SVG
 * animated boolean.
 *
 * For more information on this interface please see
 * http://www.w3.org/TR/SVG11/types.html
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedBoolean : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDBOOLEAN_IID)

  /* attribute boolean baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRBool *aBaseVal) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRBool aBaseVal) = 0;

  /* readonly attribute boolean animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRBool *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedBoolean, NS_IDOMSVGANIMATEDBOOLEAN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDBOOLEAN \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRBool *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRBool aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRBool *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDBOOLEAN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRBool *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRBool aBaseVal) { return _to SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRBool *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDBOOLEAN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRBool *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRBool aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRBool *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedBoolean : public nsIDOMSVGAnimatedBoolean
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDBOOLEAN

  nsDOMSVGAnimatedBoolean();

private:
  ~nsDOMSVGAnimatedBoolean();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedBoolean, nsIDOMSVGAnimatedBoolean)

nsDOMSVGAnimatedBoolean::nsDOMSVGAnimatedBoolean()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedBoolean::~nsDOMSVGAnimatedBoolean()
{
  /* destructor code */
}

/* attribute boolean baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedBoolean::GetBaseVal(PRBool *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAnimatedBoolean::SetBaseVal(PRBool aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedBoolean::GetAnimVal(PRBool *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedBoolean_h__ */
