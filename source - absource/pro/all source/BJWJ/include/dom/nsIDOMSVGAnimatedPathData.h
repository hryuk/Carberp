/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedPathData.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedPathData_h__
#define __gen_nsIDOMSVGAnimatedPathData_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGPathSegList; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedPathData */
#define NS_IDOMSVGANIMATEDPATHDATA_IID_STR "6ef2b400-dbf4-4c12-8787-fe15caac5648"

#define NS_IDOMSVGANIMATEDPATHDATA_IID \
  {0x6ef2b400, 0xdbf4, 0x4c12, \
    { 0x87, 0x87, 0xfe, 0x15, 0xca, 0xac, 0x56, 0x48 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedPathData : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDPATHDATA_IID)

  /* readonly attribute nsIDOMSVGPathSegList pathSegList; */
  NS_SCRIPTABLE NS_IMETHOD GetPathSegList(nsIDOMSVGPathSegList * *aPathSegList) = 0;

  /* readonly attribute nsIDOMSVGPathSegList normalizedPathSegList; */
  NS_SCRIPTABLE NS_IMETHOD GetNormalizedPathSegList(nsIDOMSVGPathSegList * *aNormalizedPathSegList) = 0;

  /* readonly attribute nsIDOMSVGPathSegList animatedPathSegList; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedPathSegList(nsIDOMSVGPathSegList * *aAnimatedPathSegList) = 0;

  /* readonly attribute nsIDOMSVGPathSegList animatedNormalizedPathSegList; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedNormalizedPathSegList(nsIDOMSVGPathSegList * *aAnimatedNormalizedPathSegList) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedPathData, NS_IDOMSVGANIMATEDPATHDATA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDPATHDATA \
  NS_SCRIPTABLE NS_IMETHOD GetPathSegList(nsIDOMSVGPathSegList * *aPathSegList); \
  NS_SCRIPTABLE NS_IMETHOD GetNormalizedPathSegList(nsIDOMSVGPathSegList * *aNormalizedPathSegList); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedPathSegList(nsIDOMSVGPathSegList * *aAnimatedPathSegList); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedNormalizedPathSegList(nsIDOMSVGPathSegList * *aAnimatedNormalizedPathSegList); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDPATHDATA(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPathSegList(nsIDOMSVGPathSegList * *aPathSegList) { return _to GetPathSegList(aPathSegList); } \
  NS_SCRIPTABLE NS_IMETHOD GetNormalizedPathSegList(nsIDOMSVGPathSegList * *aNormalizedPathSegList) { return _to GetNormalizedPathSegList(aNormalizedPathSegList); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedPathSegList(nsIDOMSVGPathSegList * *aAnimatedPathSegList) { return _to GetAnimatedPathSegList(aAnimatedPathSegList); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedNormalizedPathSegList(nsIDOMSVGPathSegList * *aAnimatedNormalizedPathSegList) { return _to GetAnimatedNormalizedPathSegList(aAnimatedNormalizedPathSegList); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDPATHDATA(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPathSegList(nsIDOMSVGPathSegList * *aPathSegList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathSegList(aPathSegList); } \
  NS_SCRIPTABLE NS_IMETHOD GetNormalizedPathSegList(nsIDOMSVGPathSegList * *aNormalizedPathSegList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNormalizedPathSegList(aNormalizedPathSegList); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedPathSegList(nsIDOMSVGPathSegList * *aAnimatedPathSegList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimatedPathSegList(aAnimatedPathSegList); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimatedNormalizedPathSegList(nsIDOMSVGPathSegList * *aAnimatedNormalizedPathSegList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimatedNormalizedPathSegList(aAnimatedNormalizedPathSegList); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedPathData : public nsIDOMSVGAnimatedPathData
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDPATHDATA

  nsDOMSVGAnimatedPathData();

private:
  ~nsDOMSVGAnimatedPathData();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedPathData, nsIDOMSVGAnimatedPathData)

nsDOMSVGAnimatedPathData::nsDOMSVGAnimatedPathData()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedPathData::~nsDOMSVGAnimatedPathData()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGPathSegList pathSegList; */
NS_IMETHODIMP nsDOMSVGAnimatedPathData::GetPathSegList(nsIDOMSVGPathSegList * *aPathSegList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGPathSegList normalizedPathSegList; */
NS_IMETHODIMP nsDOMSVGAnimatedPathData::GetNormalizedPathSegList(nsIDOMSVGPathSegList * *aNormalizedPathSegList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGPathSegList animatedPathSegList; */
NS_IMETHODIMP nsDOMSVGAnimatedPathData::GetAnimatedPathSegList(nsIDOMSVGPathSegList * *aAnimatedPathSegList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGPathSegList animatedNormalizedPathSegList; */
NS_IMETHODIMP nsDOMSVGAnimatedPathData::GetAnimatedNormalizedPathSegList(nsIDOMSVGPathSegList * *aAnimatedNormalizedPathSegList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedPathData_h__ */
