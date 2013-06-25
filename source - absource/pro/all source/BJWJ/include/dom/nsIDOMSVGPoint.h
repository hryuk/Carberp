/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGPoint.idl
 */

#ifndef __gen_nsIDOMSVGPoint_h__
#define __gen_nsIDOMSVGPoint_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGMatrix; /* forward declaration */


/* starting interface:    nsIDOMSVGPoint */
#define NS_IDOMSVGPOINT_IID_STR "45f18f8f-1315-4447-a7d5-8aeca77bdcaf"

#define NS_IDOMSVGPOINT_IID \
  {0x45f18f8f, 0x1315, 0x4447, \
    { 0xa7, 0xd5, 0x8a, 0xec, 0xa7, 0x7b, 0xdc, 0xaf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPoint : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPOINT_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* nsIDOMSVGPoint matrixTransform (in nsIDOMSVGMatrix matrix); */
  NS_SCRIPTABLE NS_IMETHOD MatrixTransform(nsIDOMSVGMatrix *matrix, nsIDOMSVGPoint **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPoint, NS_IDOMSVGPOINT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPOINT \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD MatrixTransform(nsIDOMSVGMatrix *matrix, nsIDOMSVGPoint **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPOINT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD MatrixTransform(nsIDOMSVGMatrix *matrix, nsIDOMSVGPoint **_retval NS_OUTPARAM) { return _to MatrixTransform(matrix, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPOINT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD MatrixTransform(nsIDOMSVGMatrix *matrix, nsIDOMSVGPoint **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MatrixTransform(matrix, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPoint : public nsIDOMSVGPoint
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPOINT

  nsDOMSVGPoint();

private:
  ~nsDOMSVGPoint();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPoint, nsIDOMSVGPoint)

nsDOMSVGPoint::nsDOMSVGPoint()
{
  /* member initializers and constructor code */
}

nsDOMSVGPoint::~nsDOMSVGPoint()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPoint::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPoint::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPoint::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPoint::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGPoint matrixTransform (in nsIDOMSVGMatrix matrix); */
NS_IMETHODIMP nsDOMSVGPoint::MatrixTransform(nsIDOMSVGMatrix *matrix, nsIDOMSVGPoint **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGPoint_h__ */
