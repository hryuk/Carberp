/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGRect.idl
 */

#ifndef __gen_nsIDOMSVGRect_h__
#define __gen_nsIDOMSVGRect_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGRect */
#define NS_IDOMSVGRECT_IID_STR "5b912111-c10e-498f-a44c-c713c1843007"

#define NS_IDOMSVGRECT_IID \
  {0x5b912111, 0xc10e, 0x498f, \
    { 0xa4, 0x4c, 0xc7, 0x13, 0xc1, 0x84, 0x30, 0x07 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGRect : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGRECT_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* attribute float width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWidth(float aWidth) = 0;

  /* attribute float height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(float *aHeight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHeight(float aHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGRect, NS_IDOMSVGRECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGRECT \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(float aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(float *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(float aHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGRECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(float aWidth) { return _to SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(float *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(float aHeight) { return _to SetHeight(aHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGRECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(float aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(float *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(float aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGRect : public nsIDOMSVGRect
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGRECT

  nsDOMSVGRect();

private:
  ~nsDOMSVGRect();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGRect, nsIDOMSVGRect)

nsDOMSVGRect::nsDOMSVGRect()
{
  /* member initializers and constructor code */
}

nsDOMSVGRect::~nsDOMSVGRect()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGRect::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGRect::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGRect::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGRect::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float width; */
NS_IMETHODIMP nsDOMSVGRect::GetWidth(float *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGRect::SetWidth(float aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float height; */
NS_IMETHODIMP nsDOMSVGRect::GetHeight(float *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGRect::SetHeight(float aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGRect_h__ */
