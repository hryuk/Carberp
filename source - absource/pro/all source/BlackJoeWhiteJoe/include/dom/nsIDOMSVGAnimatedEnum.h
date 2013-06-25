/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedEnum.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedEnum_h__
#define __gen_nsIDOMSVGAnimatedEnum_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAnimatedEnumeration */
#define NS_IDOMSVGANIMATEDENUMERATION_IID_STR "73b101bd-797b-470f-9308-c24c64278bcd"

#define NS_IDOMSVGANIMATEDENUMERATION_IID \
  {0x73b101bd, 0x797b, 0x470f, \
    { 0x93, 0x08, 0xc2, 0x4c, 0x64, 0x27, 0x8b, 0xcd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedEnumeration : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDENUMERATION_IID)

  /* attribute unsigned short baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRUint16 *aBaseVal) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRUint16 aBaseVal) = 0;

  /* readonly attribute unsigned short animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRUint16 *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedEnumeration, NS_IDOMSVGANIMATEDENUMERATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDENUMERATION \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRUint16 *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRUint16 aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRUint16 *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDENUMERATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRUint16 *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRUint16 aBaseVal) { return _to SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRUint16 *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDENUMERATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(PRUint16 *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(PRUint16 aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(PRUint16 *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedEnumeration : public nsIDOMSVGAnimatedEnumeration
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDENUMERATION

  nsDOMSVGAnimatedEnumeration();

private:
  ~nsDOMSVGAnimatedEnumeration();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedEnumeration, nsIDOMSVGAnimatedEnumeration)

nsDOMSVGAnimatedEnumeration::nsDOMSVGAnimatedEnumeration()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedEnumeration::~nsDOMSVGAnimatedEnumeration()
{
  /* destructor code */
}

/* attribute unsigned short baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedEnumeration::GetBaseVal(PRUint16 *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAnimatedEnumeration::SetBaseVal(PRUint16 aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedEnumeration::GetAnimVal(PRUint16 *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedEnum_h__ */
