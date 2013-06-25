/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMRGBColor.idl
 */

#ifndef __gen_nsIDOMRGBColor_h__
#define __gen_nsIDOMRGBColor_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMRGBColor */
#define NS_IDOMRGBCOLOR_IID_STR "6aff3102-320d-4986-9790-12316bb87cf9"

#define NS_IDOMRGBCOLOR_IID \
  {0x6aff3102, 0x320d, 0x4986, \
    { 0x97, 0x90, 0x12, 0x31, 0x6b, 0xb8, 0x7c, 0xf9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMRGBColor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMRGBCOLOR_IID)

  /* readonly attribute nsIDOMCSSPrimitiveValue red; */
  NS_SCRIPTABLE NS_IMETHOD GetRed(nsIDOMCSSPrimitiveValue * *aRed) = 0;

  /* readonly attribute nsIDOMCSSPrimitiveValue green; */
  NS_SCRIPTABLE NS_IMETHOD GetGreen(nsIDOMCSSPrimitiveValue * *aGreen) = 0;

  /* readonly attribute nsIDOMCSSPrimitiveValue blue; */
  NS_SCRIPTABLE NS_IMETHOD GetBlue(nsIDOMCSSPrimitiveValue * *aBlue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRGBColor, NS_IDOMRGBCOLOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMRGBCOLOR \
  NS_SCRIPTABLE NS_IMETHOD GetRed(nsIDOMCSSPrimitiveValue * *aRed); \
  NS_SCRIPTABLE NS_IMETHOD GetGreen(nsIDOMCSSPrimitiveValue * *aGreen); \
  NS_SCRIPTABLE NS_IMETHOD GetBlue(nsIDOMCSSPrimitiveValue * *aBlue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMRGBCOLOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRed(nsIDOMCSSPrimitiveValue * *aRed) { return _to GetRed(aRed); } \
  NS_SCRIPTABLE NS_IMETHOD GetGreen(nsIDOMCSSPrimitiveValue * *aGreen) { return _to GetGreen(aGreen); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlue(nsIDOMCSSPrimitiveValue * *aBlue) { return _to GetBlue(aBlue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMRGBCOLOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRed(nsIDOMCSSPrimitiveValue * *aRed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRed(aRed); } \
  NS_SCRIPTABLE NS_IMETHOD GetGreen(nsIDOMCSSPrimitiveValue * *aGreen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGreen(aGreen); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlue(nsIDOMCSSPrimitiveValue * *aBlue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlue(aBlue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRGBColor : public nsIDOMRGBColor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMRGBCOLOR

  nsDOMRGBColor();

private:
  ~nsDOMRGBColor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRGBColor, nsIDOMRGBColor)

nsDOMRGBColor::nsDOMRGBColor()
{
  /* member initializers and constructor code */
}

nsDOMRGBColor::~nsDOMRGBColor()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSPrimitiveValue red; */
NS_IMETHODIMP nsDOMRGBColor::GetRed(nsIDOMCSSPrimitiveValue * *aRed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSPrimitiveValue green; */
NS_IMETHODIMP nsDOMRGBColor::GetGreen(nsIDOMCSSPrimitiveValue * *aGreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSPrimitiveValue blue; */
NS_IMETHODIMP nsDOMRGBColor::GetBlue(nsIDOMCSSPrimitiveValue * *aBlue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMRGBColor_h__ */
