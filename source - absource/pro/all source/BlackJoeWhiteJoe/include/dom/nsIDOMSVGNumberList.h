/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGNumberList.idl
 */

#ifndef __gen_nsIDOMSVGNumberList_h__
#define __gen_nsIDOMSVGNumberList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGNumber; /* forward declaration */


/* starting interface:    nsIDOMSVGNumberList */
#define NS_IDOMSVGNUMBERLIST_IID_STR "59364ec4-faf1-460f-bf58-e6a6a2769a3a"

#define NS_IDOMSVGNUMBERLIST_IID \
  {0x59364ec4, 0xfaf1, 0x460f, \
    { 0xbf, 0x58, 0xe6, 0xa6, 0xa2, 0x76, 0x9a, 0x3a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGNumberList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGNUMBERLIST_IID)

  /* readonly attribute unsigned long numberOfItems; */
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) = 0;

  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

  /* nsIDOMSVGNumber initialize (in nsIDOMSVGNumber newItem); */
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGNumber getItem (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGNumber insertItemBefore (in nsIDOMSVGNumber newItem, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGNumber replaceItem (in nsIDOMSVGNumber newItem, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGNumber removeItem (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGNumber appendItem (in nsIDOMSVGNumber newItem); */
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGNumberList, NS_IDOMSVGNUMBERLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGNUMBERLIST \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGNUMBERLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) { return _to GetNumberOfItems(aNumberOfItems); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return _to Initialize(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return _to GetItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return _to InsertItemBefore(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return _to ReplaceItem(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return _to RemoveItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return _to AppendItem(newItem, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGNUMBERLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfItems(aNumberOfItems); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemBefore(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceItem(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(newItem, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGNumberList : public nsIDOMSVGNumberList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGNUMBERLIST

  nsDOMSVGNumberList();

private:
  ~nsDOMSVGNumberList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGNumberList, nsIDOMSVGNumberList)

nsDOMSVGNumberList::nsDOMSVGNumberList()
{
  /* member initializers and constructor code */
}

nsDOMSVGNumberList::~nsDOMSVGNumberList()
{
  /* destructor code */
}

/* readonly attribute unsigned long numberOfItems; */
NS_IMETHODIMP nsDOMSVGNumberList::GetNumberOfItems(PRUint32 *aNumberOfItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMSVGNumberList::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGNumber initialize (in nsIDOMSVGNumber newItem); */
NS_IMETHODIMP nsDOMSVGNumberList::Initialize(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGNumber getItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGNumberList::GetItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGNumber insertItemBefore (in nsIDOMSVGNumber newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGNumberList::InsertItemBefore(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGNumber replaceItem (in nsIDOMSVGNumber newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem, PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGNumber removeItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGNumberList::RemoveItem(PRUint32 index, nsIDOMSVGNumber **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGNumber appendItem (in nsIDOMSVGNumber newItem); */
NS_IMETHODIMP nsDOMSVGNumberList::AppendItem(nsIDOMSVGNumber *newItem, nsIDOMSVGNumber **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGNumberList_h__ */
