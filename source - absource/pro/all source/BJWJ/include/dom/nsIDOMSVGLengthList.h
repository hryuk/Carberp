/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGLengthList.idl
 */

#ifndef __gen_nsIDOMSVGLengthList_h__
#define __gen_nsIDOMSVGLengthList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGLength; /* forward declaration */


/* starting interface:    nsIDOMSVGLengthList */
#define NS_IDOMSVGLENGTHLIST_IID_STR "a8760fcd-3de5-446a-a009-5cf877e7a4df"

#define NS_IDOMSVGLENGTHLIST_IID \
  {0xa8760fcd, 0x3de5, 0x446a, \
    { 0xa0, 0x09, 0x5c, 0xf8, 0x77, 0xe7, 0xa4, 0xdf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGLengthList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGLENGTHLIST_IID)

  /* readonly attribute unsigned long numberOfItems; */
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) = 0;

  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

  /* nsIDOMSVGLength initialize (in nsIDOMSVGLength newItem); */
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGLength getItem (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGLength insertItemBefore (in nsIDOMSVGLength newItem, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGLength replaceItem (in nsIDOMSVGLength newItem, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGLength removeItem (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGLength appendItem (in nsIDOMSVGLength newItem); */
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGLengthList, NS_IDOMSVGLENGTHLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGLENGTHLIST \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGLENGTHLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) { return _to GetNumberOfItems(aNumberOfItems); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM) { return _to Initialize(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) { return _to GetItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) { return _to InsertItemBefore(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) { return _to ReplaceItem(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) { return _to RemoveItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM) { return _to AppendItem(newItem, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGLENGTHLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfItems(aNumberOfItems); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemBefore(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceItem(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(newItem, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGLengthList : public nsIDOMSVGLengthList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGLENGTHLIST

  nsDOMSVGLengthList();

private:
  ~nsDOMSVGLengthList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGLengthList, nsIDOMSVGLengthList)

nsDOMSVGLengthList::nsDOMSVGLengthList()
{
  /* member initializers and constructor code */
}

nsDOMSVGLengthList::~nsDOMSVGLengthList()
{
  /* destructor code */
}

/* readonly attribute unsigned long numberOfItems; */
NS_IMETHODIMP nsDOMSVGLengthList::GetNumberOfItems(PRUint32 *aNumberOfItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMSVGLengthList::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGLength initialize (in nsIDOMSVGLength newItem); */
NS_IMETHODIMP nsDOMSVGLengthList::Initialize(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGLength getItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGLengthList::GetItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGLength insertItemBefore (in nsIDOMSVGLength newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGLengthList::InsertItemBefore(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGLength replaceItem (in nsIDOMSVGLength newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGLengthList::ReplaceItem(nsIDOMSVGLength *newItem, PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGLength removeItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGLengthList::RemoveItem(PRUint32 index, nsIDOMSVGLength **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGLength appendItem (in nsIDOMSVGLength newItem); */
NS_IMETHODIMP nsDOMSVGLengthList::AppendItem(nsIDOMSVGLength *newItem, nsIDOMSVGLength **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGLengthList_h__ */
