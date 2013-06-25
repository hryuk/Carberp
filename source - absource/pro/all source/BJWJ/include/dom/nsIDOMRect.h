/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMRect.idl
 */

#ifndef __gen_nsIDOMRect_h__
#define __gen_nsIDOMRect_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMRect */
#define NS_IDOMRECT_IID_STR "71735f62-ac5c-4236-9a1f-5ffb280d531c"

#define NS_IDOMRECT_IID \
  {0x71735f62, 0xac5c, 0x4236, \
    { 0x9a, 0x1f, 0x5f, 0xfb, 0x28, 0x0d, 0x53, 0x1c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMRect : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMRECT_IID)

  /* readonly attribute nsIDOMCSSPrimitiveValue top; */
  NS_SCRIPTABLE NS_IMETHOD GetTop(nsIDOMCSSPrimitiveValue * *aTop) = 0;

  /* readonly attribute nsIDOMCSSPrimitiveValue right; */
  NS_SCRIPTABLE NS_IMETHOD GetRight(nsIDOMCSSPrimitiveValue * *aRight) = 0;

  /* readonly attribute nsIDOMCSSPrimitiveValue bottom; */
  NS_SCRIPTABLE NS_IMETHOD GetBottom(nsIDOMCSSPrimitiveValue * *aBottom) = 0;

  /* readonly attribute nsIDOMCSSPrimitiveValue left; */
  NS_SCRIPTABLE NS_IMETHOD GetLeft(nsIDOMCSSPrimitiveValue * *aLeft) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRect, NS_IDOMRECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMRECT \
  NS_SCRIPTABLE NS_IMETHOD GetTop(nsIDOMCSSPrimitiveValue * *aTop); \
  NS_SCRIPTABLE NS_IMETHOD GetRight(nsIDOMCSSPrimitiveValue * *aRight); \
  NS_SCRIPTABLE NS_IMETHOD GetBottom(nsIDOMCSSPrimitiveValue * *aBottom); \
  NS_SCRIPTABLE NS_IMETHOD GetLeft(nsIDOMCSSPrimitiveValue * *aLeft); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMRECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTop(nsIDOMCSSPrimitiveValue * *aTop) { return _to GetTop(aTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetRight(nsIDOMCSSPrimitiveValue * *aRight) { return _to GetRight(aRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetBottom(nsIDOMCSSPrimitiveValue * *aBottom) { return _to GetBottom(aBottom); } \
  NS_SCRIPTABLE NS_IMETHOD GetLeft(nsIDOMCSSPrimitiveValue * *aLeft) { return _to GetLeft(aLeft); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMRECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTop(nsIDOMCSSPrimitiveValue * *aTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTop(aTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetRight(nsIDOMCSSPrimitiveValue * *aRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRight(aRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetBottom(nsIDOMCSSPrimitiveValue * *aBottom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBottom(aBottom); } \
  NS_SCRIPTABLE NS_IMETHOD GetLeft(nsIDOMCSSPrimitiveValue * *aLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLeft(aLeft); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRect : public nsIDOMRect
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMRECT

  nsDOMRect();

private:
  ~nsDOMRect();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRect, nsIDOMRect)

nsDOMRect::nsDOMRect()
{
  /* member initializers and constructor code */
}

nsDOMRect::~nsDOMRect()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSPrimitiveValue top; */
NS_IMETHODIMP nsDOMRect::GetTop(nsIDOMCSSPrimitiveValue * *aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSPrimitiveValue right; */
NS_IMETHODIMP nsDOMRect::GetRight(nsIDOMCSSPrimitiveValue * *aRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSPrimitiveValue bottom; */
NS_IMETHODIMP nsDOMRect::GetBottom(nsIDOMCSSPrimitiveValue * *aBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSPrimitiveValue left; */
NS_IMETHODIMP nsDOMRect::GetLeft(nsIDOMCSSPrimitiveValue * *aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMRect_h__ */
