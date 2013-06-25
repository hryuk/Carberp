/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGTransformList.idl
 */

#ifndef __gen_nsIDOMSVGTransformList_h__
#define __gen_nsIDOMSVGTransformList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGTransform; /* forward declaration */

class nsIDOMSVGMatrix; /* forward declaration */


/* starting interface:    nsIDOMSVGTransformList */
#define NS_IDOMSVGTRANSFORMLIST_IID_STR "cee0a9d4-8554-4bf6-bf9b-7d0cebb4269d"

#define NS_IDOMSVGTRANSFORMLIST_IID \
  {0xcee0a9d4, 0x8554, 0x4bf6, \
    { 0xbf, 0x9b, 0x7d, 0x0c, 0xeb, 0xb4, 0x26, 0x9d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGTransformList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTRANSFORMLIST_IID)

  /* readonly attribute unsigned long numberOfItems; */
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) = 0;

  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

  /* nsIDOMSVGTransform initialize (in nsIDOMSVGTransform newItem); */
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGTransform getItem (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGTransform insertItemBefore (in nsIDOMSVGTransform newItem, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGTransform replaceItem (in nsIDOMSVGTransform newItem, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGTransform removeItem (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGTransform appendItem (in nsIDOMSVGTransform newItem); */
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGTransform createSVGTransformFromMatrix (in nsIDOMSVGMatrix matrix); */
  NS_SCRIPTABLE NS_IMETHOD CreateSVGTransformFromMatrix(nsIDOMSVGMatrix *matrix, nsIDOMSVGTransform **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGTransform consolidate (); */
  NS_SCRIPTABLE NS_IMETHOD Consolidate(nsIDOMSVGTransform **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTransformList, NS_IDOMSVGTRANSFORMLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTRANSFORMLIST \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateSVGTransformFromMatrix(nsIDOMSVGMatrix *matrix, nsIDOMSVGTransform **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Consolidate(nsIDOMSVGTransform **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTRANSFORMLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) { return _to GetNumberOfItems(aNumberOfItems); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return _to Initialize(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return _to GetItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return _to InsertItemBefore(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return _to ReplaceItem(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return _to RemoveItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return _to AppendItem(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateSVGTransformFromMatrix(nsIDOMSVGMatrix *matrix, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return _to CreateSVGTransformFromMatrix(matrix, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Consolidate(nsIDOMSVGTransform **_retval NS_OUTPARAM) { return _to Consolidate(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTRANSFORMLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfItems(PRUint32 *aNumberOfItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfItems(aNumberOfItems); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemBefore(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemBefore(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceItem(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceItem(newItem, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(newItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateSVGTransformFromMatrix(nsIDOMSVGMatrix *matrix, nsIDOMSVGTransform **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGTransformFromMatrix(matrix, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Consolidate(nsIDOMSVGTransform **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Consolidate(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTransformList : public nsIDOMSVGTransformList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTRANSFORMLIST

  nsDOMSVGTransformList();

private:
  ~nsDOMSVGTransformList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTransformList, nsIDOMSVGTransformList)

nsDOMSVGTransformList::nsDOMSVGTransformList()
{
  /* member initializers and constructor code */
}

nsDOMSVGTransformList::~nsDOMSVGTransformList()
{
  /* destructor code */
}

/* readonly attribute unsigned long numberOfItems; */
NS_IMETHODIMP nsDOMSVGTransformList::GetNumberOfItems(PRUint32 *aNumberOfItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMSVGTransformList::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGTransform initialize (in nsIDOMSVGTransform newItem); */
NS_IMETHODIMP nsDOMSVGTransformList::Initialize(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGTransform getItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGTransformList::GetItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGTransform insertItemBefore (in nsIDOMSVGTransform newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGTransformList::InsertItemBefore(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGTransform replaceItem (in nsIDOMSVGTransform newItem, in unsigned long index); */
NS_IMETHODIMP nsDOMSVGTransformList::ReplaceItem(nsIDOMSVGTransform *newItem, PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGTransform removeItem (in unsigned long index); */
NS_IMETHODIMP nsDOMSVGTransformList::RemoveItem(PRUint32 index, nsIDOMSVGTransform **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGTransform appendItem (in nsIDOMSVGTransform newItem); */
NS_IMETHODIMP nsDOMSVGTransformList::AppendItem(nsIDOMSVGTransform *newItem, nsIDOMSVGTransform **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGTransform createSVGTransformFromMatrix (in nsIDOMSVGMatrix matrix); */
NS_IMETHODIMP nsDOMSVGTransformList::CreateSVGTransformFromMatrix(nsIDOMSVGMatrix *matrix, nsIDOMSVGTransform **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGTransform consolidate (); */
NS_IMETHODIMP nsDOMSVGTransformList::Consolidate(nsIDOMSVGTransform **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTransformList_h__ */
