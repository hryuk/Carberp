/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedString.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedString_h__
#define __gen_nsIDOMSVGAnimatedString_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAnimatedString */
#define NS_IDOMSVGANIMATEDSTRING_IID_STR "36f18f12-61a9-4529-8fa9-30050bd6ac00"

#define NS_IDOMSVGANIMATEDSTRING_IID \
  {0x36f18f12, 0x61a9, 0x4529, \
    { 0x8f, 0xa9, 0x30, 0x05, 0x0b, 0xd6, 0xac, 0x00 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedString : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDSTRING_IID)

  /* attribute DOMString baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsAString & aBaseVal) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(const nsAString & aBaseVal) = 0;

  /* readonly attribute DOMString animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsAString & aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedString, NS_IDOMSVGANIMATEDSTRING_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDSTRING \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsAString & aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(const nsAString & aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsAString & aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDSTRING(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsAString & aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(const nsAString & aBaseVal) { return _to SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsAString & aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDSTRING(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsAString & aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseVal(const nsAString & aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsAString & aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedString : public nsIDOMSVGAnimatedString
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDSTRING

  nsDOMSVGAnimatedString();

private:
  ~nsDOMSVGAnimatedString();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedString, nsIDOMSVGAnimatedString)

nsDOMSVGAnimatedString::nsDOMSVGAnimatedString()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedString::~nsDOMSVGAnimatedString()
{
  /* destructor code */
}

/* attribute DOMString baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedString::GetBaseVal(nsAString & aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAnimatedString::SetBaseVal(const nsAString & aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedString::GetAnimVal(nsAString & aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedString_h__ */
