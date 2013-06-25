/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/txmgr/idl/nsITransactionList.idl
 */

#ifndef __gen_nsITransactionList_h__
#define __gen_nsITransactionList_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITransaction; /* forward declaration */


/* starting interface:    nsITransactionList */
#define NS_ITRANSACTIONLIST_IID_STR "97f863f3-f886-11d4-9d39-0060b0f8baff"

#define NS_ITRANSACTIONLIST_IID \
  {0x97f863f3, 0xf886, 0x11d4, \
    { 0x9d, 0x39, 0x00, 0x60, 0xb0, 0xf8, 0xba, 0xff }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITransactionList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSACTIONLIST_IID)

  /**
   * The number of transactions contained in this list.
   */
  /* readonly attribute long numItems; */
  NS_SCRIPTABLE NS_IMETHOD GetNumItems(PRInt32 *aNumItems) = 0;

  /**
   * itemIsBatch() returns true if the item at aIndex is a batch. Note that
   * currently there is no requirement for a TransactionManager implementation
   * to associate a toplevel nsITransaction with a batch so it is possible for
   * itemIsBatch() to return true and getItem() to return null. However, you
   * can still access the transactions contained in the batch with a call to
   * getChildListForItem().
   * @param aIndex The index of the item in the list.
   */
  /* boolean itemIsBatch (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD ItemIsBatch(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * getItem() returns the transaction at the given index in the list. Note that
   * a null can be returned here if the item is a batch. The transaction
   * returned is AddRef'd so it is up to the caller to Release the transaction
   * when it is done.
   * @param aIndex The index of the item in the list.
   */
  /* nsITransaction getItem (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRInt32 aIndex, nsITransaction **_retval NS_OUTPARAM) = 0;

  /**
   * getNumChildrenForItem() returns the number of child (auto-aggreated)
   * transactions the item at aIndex has.
   * @param aIndex The index of the item in the list.
   */
  /* long getNumChildrenForItem (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetNumChildrenForItem(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * getChildListForItem() returns the list of children associated with the
   * item at aIndex. Implementations may return null if there are no children,
   * or an empty list. The list returned is AddRef'd so it is up to the caller
   * to Release the transaction when it is done.
   * @param aIndex The index of the item in the list.
   */
  /* nsITransactionList getChildListForItem (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetChildListForItem(PRInt32 aIndex, nsITransactionList **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransactionList, NS_ITRANSACTIONLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSACTIONLIST \
  NS_SCRIPTABLE NS_IMETHOD GetNumItems(PRInt32 *aNumItems); \
  NS_SCRIPTABLE NS_IMETHOD ItemIsBatch(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRInt32 aIndex, nsITransaction **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNumChildrenForItem(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetChildListForItem(PRInt32 aIndex, nsITransactionList **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSACTIONLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumItems(PRInt32 *aNumItems) { return _to GetNumItems(aNumItems); } \
  NS_SCRIPTABLE NS_IMETHOD ItemIsBatch(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM) { return _to ItemIsBatch(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRInt32 aIndex, nsITransaction **_retval NS_OUTPARAM) { return _to GetItem(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumChildrenForItem(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetNumChildrenForItem(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildListForItem(PRInt32 aIndex, nsITransactionList **_retval NS_OUTPARAM) { return _to GetChildListForItem(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSACTIONLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumItems(PRInt32 *aNumItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumItems(aNumItems); } \
  NS_SCRIPTABLE NS_IMETHOD ItemIsBatch(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ItemIsBatch(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(PRInt32 aIndex, nsITransaction **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumChildrenForItem(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumChildrenForItem(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildListForItem(PRInt32 aIndex, nsITransactionList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildListForItem(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransactionList : public nsITransactionList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSACTIONLIST

  nsTransactionList();

private:
  ~nsTransactionList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransactionList, nsITransactionList)

nsTransactionList::nsTransactionList()
{
  /* member initializers and constructor code */
}

nsTransactionList::~nsTransactionList()
{
  /* destructor code */
}

/* readonly attribute long numItems; */
NS_IMETHODIMP nsTransactionList::GetNumItems(PRInt32 *aNumItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean itemIsBatch (in long aIndex); */
NS_IMETHODIMP nsTransactionList::ItemIsBatch(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransaction getItem (in long aIndex); */
NS_IMETHODIMP nsTransactionList::GetItem(PRInt32 aIndex, nsITransaction **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getNumChildrenForItem (in long aIndex); */
NS_IMETHODIMP nsTransactionList::GetNumChildrenForItem(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransactionList getChildListForItem (in long aIndex); */
NS_IMETHODIMP nsTransactionList::GetChildListForItem(PRInt32 aIndex, nsITransactionList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransactionList_h__ */
