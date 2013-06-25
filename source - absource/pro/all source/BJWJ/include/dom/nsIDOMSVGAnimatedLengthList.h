/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAnimatedLengthList.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedLengthList_h__
#define __gen_nsIDOMSVGAnimatedLengthList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGLengthList; /* forward declaration */


/* starting interface:    nsIDOMSVGAnimatedLengthList */
#define NS_IDOMSVGANIMATEDLENGTHLIST_IID_STR "bfa6e42b-bc9d-404d-8688-729fdbfff801"

#define NS_IDOMSVGANIMATEDLENGTHLIST_IID \
  {0xbfa6e42b, 0xbc9d, 0x404d, \
    { 0x86, 0x88, 0x72, 0x9f, 0xdb, 0xff, 0xf8, 0x01 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimatedLengthList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDLENGTHLIST_IID)

  /* readonly attribute nsIDOMSVGLengthList baseVal; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGLengthList * *aBaseVal) = 0;

  /* readonly attribute nsIDOMSVGLengthList animVal; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGLengthList * *aAnimVal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedLengthList, NS_IDOMSVGANIMATEDLENGTHLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDLENGTHLIST \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGLengthList * *aBaseVal); \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGLengthList * *aAnimVal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDLENGTHLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGLengthList * *aBaseVal) { return _to GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGLengthList * *aAnimVal) { return _to GetAnimVal(aAnimVal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDLENGTHLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseVal(nsIDOMSVGLengthList * *aBaseVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseVal(aBaseVal); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnimVal(nsIDOMSVGLengthList * *aAnimVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimVal(aAnimVal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedLengthList : public nsIDOMSVGAnimatedLengthList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDLENGTHLIST

  nsDOMSVGAnimatedLengthList();

private:
  ~nsDOMSVGAnimatedLengthList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedLengthList, nsIDOMSVGAnimatedLengthList)

nsDOMSVGAnimatedLengthList::nsDOMSVGAnimatedLengthList()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedLengthList::~nsDOMSVGAnimatedLengthList()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGLengthList baseVal; */
NS_IMETHODIMP nsDOMSVGAnimatedLengthList::GetBaseVal(nsIDOMSVGLengthList * *aBaseVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGLengthList animVal; */
NS_IMETHODIMP nsDOMSVGAnimatedLengthList::GetAnimVal(nsIDOMSVGLengthList * *aAnimVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedLengthList_h__ */
