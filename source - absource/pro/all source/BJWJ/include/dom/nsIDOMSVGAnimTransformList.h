/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimTransformList.idl
 */

#ifndef __gen_nsIDOMSVGAnimTransformList_h__
#define __gen_nsIDOMSVGAnimTransformList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGTransformList; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedTransformList */
#define NS_IDOMSVGANIMATEDTRANSFORMLIST_IID_STR "fd54c8c4-2eb4-4849-8df6-79985c2491da"

#define NS_IDOMSVGANIMATEDTRANSFORMLIST_IID \
  {0xfd54c8c4, 0x2eb4, 0x4849, \
    { 0x8d, 0xf6, 0x79, 0x98, 0x5c, 0x24, 0x91, 0xda }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedTransformList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDTRANSFORMLIST_IID)

  /* readonly attribute nsIDOMSVGTransformList baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGTransformList * *aBaseVal) = 0;

  /* readonly attribute nsIDOMSVGTransformList animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGTransformList * *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedTransformList, NS_IDOMSVGANIMATEDTRANSFORMLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDTRANSFORMLIST \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGTransformList * *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGTransformList * *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDTRANSFORMLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGTransformList * *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGTransformList * *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDTRANSFORMLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGTransformList * *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGTransformList * *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedTransformList : public nsIDOMSVGAnimatedTransformList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDTRANSFORMLIST

  nsDOMSVGAnimatedTransformList();

private:
  ~nsDOMSVGAnimatedTransformList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedTransformList, nsIDOMSVGAnimatedTransformList)

nsDOMSVGAnimatedTransformList::nsDOMSVGAnimatedTransformList()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedTransformList::~nsDOMSVGAnimatedTransformList()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGTransformList baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedTransformList::GetBaseVal(nsIDOMSVGTransformList * *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGTransformList animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedTransformList::GetAnimVal(nsIDOMSVGTransformList * *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimTransformList_h__ */
