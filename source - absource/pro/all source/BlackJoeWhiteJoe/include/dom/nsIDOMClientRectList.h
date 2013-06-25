/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMClientRectList.idl
 */

#ifndef __gen_nsIDOMClientRectList_h__
#define __gen_nsIDOMClientRectList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMClientRectList */
#define NS_IDOMCLIENTRECTLIST_IID_STR "917da19d-62f5-441d-b47e-9e35f05639c9"

#define NS_IDOMCLIENTRECTLIST_IID \
  {0x917da19d, 0x62f5, 0x441d, \
    { 0xb4, 0x7e, 0x9e, 0x35, 0xf0, 0x56, 0x39, 0xc9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMClientRectList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCLIENTRECTLIST_IID)

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* nsIDOMClientRect item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMClientRect **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMClientRectList, NS_IDOMCLIENTRECTLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCLIENTRECTLIST \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMClientRect **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCLIENTRECTLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMClientRect **_retval NS_OUTPARAM) { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCLIENTRECTLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMClientRect **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMClientRectList : public nsIDOMClientRectList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCLIENTRECTLIST

  nsDOMClientRectList();

private:
  ~nsDOMClientRectList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMClientRectList, nsIDOMClientRectList)

nsDOMClientRectList::nsDOMClientRectList()
{
  /* member initializers and constructor code */
}

nsDOMClientRectList::~nsDOMClientRectList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMClientRectList::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect item (in unsigned long index); */
NS_IMETHODIMP nsDOMClientRectList::Item(PRUint32 index, nsIDOMClientRect **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMClientRectList_h__ */
