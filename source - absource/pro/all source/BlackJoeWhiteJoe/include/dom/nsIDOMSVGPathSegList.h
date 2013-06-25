/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGPathSegList.idl
 */

#ifndef __gen_nsIDOMSVGPathSegList_h__
#define __gen_nsIDOMSVGPathSegList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGPathSeg; /* forward declaration */


/* starting interface:    nsIDOMSVGPathSegList */
#define NS_IDOMSVGPATHSEGLIST_IID_STR "94a6db98-3f34-4529-a35f-89ef49713795"

#define NS_IDOMSVGPATHSEGLIST_IID \
  {0x94a6db98, 0x3f34, 0x4529, \
    { 0xa3, 0x5f, 0x89, 0xef, 0x49, 0x71, 0x37, 0x95 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGLIST_IID)

  /* readonly attribute unsigned long numberOfItems; */
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) = 0;

  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

  /* nsIDOMSVGPathSeg initialize (in nsIDOMSVGPathSeg newItem); */
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGPathSeg getItem (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGPathSeg insertItemBefore (in nsIDOMSVGPathSeg newItem, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGPathSeg replaceItem (in nsIDOMSVGPathSeg newItem, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGPathSeg removeItem (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGPathSeg appendItem (in nsIDOMSVGPathSeg newItem); */
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegList, NS_IDOMSVGPATHSEGLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGLIST \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) { return _to GetNumberOfItems(aNumberOfItems); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return _to Initialize(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return _to GetItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return _to InsertItemBefore(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return _to ReplaceItem(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return _to RemoveItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return _to AppendItem(newItem, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfItems(aNumberOfItems); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemBefore(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceItem(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(newItem, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegList : public nsIDOMSVGPathSegList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGLIST

  nsDOMSVGPathSegList();

private:
  ~nsDOMSVGPathSegList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegList, nsIDOMSVGPathSegList)

nsDOMSVGPathSegList::nsDOMSVGPathSegList()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegList::~nsDOMSVGPathSegList()
{
  /* destructor code */
}

/* readonly attribute unsigned long numberOfItems; */
NS_IMETHODIMP nsDOMSVGPathSegList::GetNumberOfItems(PRUint32 *aNumberOfItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMSVGPathSegList::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGPathSeg initialize (in nsIDOMSVGPathSeg newItem); */
NS_IMETHODIMP nsDOMSVGPathSegList::Initialize(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGPathSeg getItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGPathSegList::GetItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGPathSeg insertItemBefore (in nsIDOMSVGPathSeg newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGPathSegList::InsertItemBefore(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGPathSeg replaceItem (in nsIDOMSVGPathSeg newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGPathSegList::ReplaceItem(nsIDOMSVGPathSeg *newItem, PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGPathSeg removeItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGPathSegList::RemoveItem(PRUint32 index, nsIDOMSVGPathSeg **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGPathSeg appendItem (in nsIDOMSVGPathSeg newItem); */
NS_IMETHODIMP nsDOMSVGPathSegList::AppendItem(nsIDOMSVGPathSeg *newItem, nsIDOMSVGPathSeg **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGPathSegList_h__ */
