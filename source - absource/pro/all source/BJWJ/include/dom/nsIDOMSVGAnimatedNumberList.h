/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedNumberList.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedNumberList_h__
#define __gen_nsIDOMSVGAnimatedNumberList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGNumberList; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedNumberList */
#define NS_IDOMSVGANIMATEDNUMBERLIST_IID_STR "93ebb030-f82d-4f8e-b133-d1b5abb73cf3"

#define NS_IDOMSVGANIMATEDNUMBERLIST_IID \
  {0x93ebb030, 0xf82d, 0x4f8e, \
    { 0xb1, 0x33, 0xd1, 0xb5, 0xab, 0xb7, 0x3c, 0xf3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedNumberList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDNUMBERLIST_IID)

  /* readonly attribute nsIDOMSVGNumberList baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGNumberList * *aBaseVal) = 0;

  /* readonly attribute nsIDOMSVGNumberList animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGNumberList * *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedNumberList, NS_IDOMSVGANIMATEDNUMBERLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDNUMBERLIST \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGNumberList * *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGNumberList * *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDNUMBERLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGNumberList * *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGNumberList * *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDNUMBERLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGNumberList * *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGNumberList * *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedNumberList : public nsIDOMSVGAnimatedNumberList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDNUMBERLIST

  nsDOMSVGAnimatedNumberList();

private:
  ~nsDOMSVGAnimatedNumberList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedNumberList, nsIDOMSVGAnimatedNumberList)

nsDOMSVGAnimatedNumberList::nsDOMSVGAnimatedNumberList()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedNumberList::~nsDOMSVGAnimatedNumberList()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGNumberList baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedNumberList::GetBaseVal(nsIDOMSVGNumberList * *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGNumberList animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedNumberList::GetAnimVal(nsIDOMSVGNumberList * *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedNumberList_h__ */
