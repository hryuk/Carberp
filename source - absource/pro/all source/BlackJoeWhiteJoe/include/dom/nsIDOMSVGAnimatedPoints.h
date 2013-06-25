/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedPoints.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedPoints_h__
#define __gen_nsIDOMSVGAnimatedPoints_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGPointList; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedPoints */
#define NS_IDOMSVGANIMATEDPOINTS_IID_STR "ebf334b3-86ef-4bf3-8a92-d775c72defa4"

#define NS_IDOMSVGANIMATEDPOINTS_IID \
  {0xebf334b3, 0x86ef, 0x4bf3, \
    { 0x8a, 0x92, 0xd7, 0x75, 0xc7, 0x2d, 0xef, 0xa4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedPoints : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDPOINTS_IID)

  /* readonly attribute nsIDOMSVGPointList points; */
  NS_SCRIPTABLE NS_IMETHOD GetPoints(nsIDOMSVGPointList * *aPoints) = 0;

  /* readonly attribute nsIDOMSVGPointList animatedPoints; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedPoints(nsIDOMSVGPointList * *aAnimatedPoints) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedPoints, NS_IDOMSVGANIMATEDPOINTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDPOINTS \
  NS_SCRIPTABLE NS_IMETHOD GetPoints(nsIDOMSVGPointList * *aPoints); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedPoints(nsIDOMSVGPointList * *aAnimatedPoints); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDPOINTS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPoints(nsIDOMSVGPointList * *aPoints) { return _to GetPoints(aPoints); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedPoints(nsIDOMSVGPointList * *aAnimatedPoints) { return _to GetAnimatedPoints(aAnimatedPoints); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDPOINTS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPoints(nsIDOMSVGPointList * *aPoints) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPoints(aPoints); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedPoints(nsIDOMSVGPointList * *aAnimatedPoints) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimatedPoints(aAnimatedPoints); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedPoints : public nsIDOMSVGAnimatedPoints
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDPOINTS

  nsDOMSVGAnimatedPoints();

private:
  ~nsDOMSVGAnimatedPoints();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedPoints, nsIDOMSVGAnimatedPoints)

nsDOMSVGAnimatedPoints::nsDOMSVGAnimatedPoints()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedPoints::~nsDOMSVGAnimatedPoints()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGPointList points; */
NS_IMETHODIMP nsDOMSVGAnimatedPoints::GetPoints(nsIDOMSVGPointList * *aPoints)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGPointList animatedPoints; */
NS_IMETHODIMP nsDOMSVGAnimatedPoints::GetAnimatedPoints(nsIDOMSVGPointList * *aAnimatedPoints)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedPoints_h__ */
