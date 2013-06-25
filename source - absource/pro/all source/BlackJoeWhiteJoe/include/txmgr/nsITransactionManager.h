/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/txmgr/idl/nsITransactionManager.idl
 */

#ifndef __gen_nsITransactionManager_h__
#define __gen_nsITransactionManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsITransaction_h__
#include "nsITransaction.h"
#endif

#ifndef __gen_nsITransactionList_h__
#include "nsITransactionList.h"
#endif

#ifndef __gen_nsITransactionListener_h__
#include "nsITransactionListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_TRANSACTIONMANAGER_CONTRACTID "@mozilla.org/transactionmanager;1"

/* starting interface:    nsITransactionManager */
#define NS_ITRANSACTIONMANAGER_IID_STR "58e330c2-7b48-11d2-98b9-00805f297d89"

#define NS_ITRANSACTIONMANAGER_IID \
  {0x58e330c2, 0x7b48, 0x11d2, \
    { 0x98, 0xb9, 0x00, 0x80, 0x5f, 0x29, 0x7d, 0x89 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITransactionManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSACTIONMANAGER_IID)

  /**
 * The nsITransactionManager interface.
 * <P>
 * This interface is implemented by an object that wants to
 * manage/track transactions.
 */
/**
   * Calls a transaction's doTransaction() method, then pushes it on the
   * undo stack.
   * <P>
   * This method calls the transaction's AddRef() method.
   * The transaction's Release() method will be called when the undo or redo
   * stack is pruned or when the transaction manager is destroyed.
   * @param aTransaction the transaction to do.
   */
  /* void doTransaction (in nsITransaction aTransaction); */
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(nsITransaction *aTransaction) = 0;

  /**
   * Pops the topmost transaction on the undo stack, calls it's
   * undoTransaction() method, then pushes it on the redo stack.
   */
  /* void undoTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD UndoTransaction(void) = 0;

  /**
   * Pops the topmost transaction on the redo stack, calls it's
   * redoTransaction() method, then pushes it on the undo stack.
   */
  /* void redoTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD RedoTransaction(void) = 0;

  /**
   * Clears the undo and redo stacks.
   */
  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

  /**
   * Turns on the transaction manager's batch mode, forcing all transactions
   * executed by the transaction manager's doTransaction() method to be
   * aggregated together until EndBatch() is called.  This mode allows an
   * application to execute and group together several independent transactions
   * so they can be undone with a single call to undoTransaction().
   */
  /* void beginBatch (); */
  NS_SCRIPTABLE NS_IMETHOD BeginBatch(void) = 0;

  /**
   * Turns off the transaction manager's batch mode.
   */
  /* void endBatch (); */
  NS_SCRIPTABLE NS_IMETHOD EndBatch(void) = 0;

  /**
   * The number of items on the undo stack.
   */
  /* readonly attribute long numberOfUndoItems; */
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfUndoItems(PRInt32 *aNumberOfUndoItems) = 0;

  /**
   * The number of items on the redo stack.
   */
  /* readonly attribute long numberOfRedoItems; */
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfRedoItems(PRInt32 *aNumberOfRedoItems) = 0;

  /**
   * Sets the maximum number of transaction items the transaction manager will
   * maintain at any time. This is commonly referred to as the number of levels
   * of undo.
   * @param aMaxCount A value of -1 means no limit. A value of zero means the
   * transaction manager will execute each transaction, then immediately release
   * all references it has to the transaction without pushing it on the undo
   * stack. A value greater than zero indicates the max number of transactions
   * that can exist at any time on both the undo and redo stacks. This method
   * will prune the necessary number of transactions on the undo and redo
   * stacks if the value specified is less than the number of items that exist
   * on both the undo and redo stacks.
   */
  /* attribute long maxTransactionCount; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxTransactionCount(PRInt32 *aMaxTransactionCount) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMaxTransactionCount(PRInt32 aMaxTransactionCount) = 0;

  /**
   * Returns an AddRef'd pointer to the transaction at the top of the
   * undo stack. Callers should be aware that this method could return
   * return a null in some implementations if there is a batch at the top
   * of the undo stack.
   */
  /* nsITransaction peekUndoStack (); */
  NS_SCRIPTABLE NS_IMETHOD PeekUndoStack(nsITransaction **_retval NS_OUTPARAM) = 0;

  /**
   * Returns an AddRef'd pointer to the transaction at the top of the
   * redo stack. Callers should be aware that this method could return
   * return a null in some implementations if there is a batch at the top
   * of the redo stack.
   */
  /* nsITransaction peekRedoStack (); */
  NS_SCRIPTABLE NS_IMETHOD PeekRedoStack(nsITransaction **_retval NS_OUTPARAM) = 0;

  /**
   * Returns the list of transactions on the undo stack. Note that the
   * transaction at the top of the undo stack will actually be at the
   * index 'n-1' in the list, where 'n' is the number of items in the list.
   */
  /* nsITransactionList getUndoList (); */
  NS_SCRIPTABLE NS_IMETHOD GetUndoList(nsITransactionList **_retval NS_OUTPARAM) = 0;

  /**
   * Returns the list of transactions on the redo stack. Note that the
   * transaction at the top of the redo stack will actually be at the
   * index 'n-1' in the list, where 'n' is the number of items in the list.
   */
  /* nsITransactionList getRedoList (); */
  NS_SCRIPTABLE NS_IMETHOD GetRedoList(nsITransactionList **_retval NS_OUTPARAM) = 0;

  /**
   * Adds a listener to the transaction manager's notification list. Listeners
   * are notified whenever a transaction is done, undone, or redone.
   * <P>
   * The listener's AddRef() method is called.
   * @param aListener the lister to add.
   */
  /* void AddListener (in nsITransactionListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsITransactionListener *aListener) = 0;

  /**
   * Removes a listener from the transaction manager's notification list.
   * <P>
   * The listener's Release() method is called.
   * @param aListener the lister to remove.
   */
  /* void RemoveListener (in nsITransactionListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsITransactionListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransactionManager, NS_ITRANSACTIONMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSACTIONMANAGER \
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(nsITransaction *aTransaction); \
  NS_SCRIPTABLE NS_IMETHOD UndoTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD RedoTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); \
  NS_SCRIPTABLE NS_IMETHOD BeginBatch(void); \
  NS_SCRIPTABLE NS_IMETHOD EndBatch(void); \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfUndoItems(PRInt32 *aNumberOfUndoItems); \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfRedoItems(PRInt32 *aNumberOfRedoItems); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxTransactionCount(PRInt32 *aMaxTransactionCount); \
  NS_SCRIPTABLE NS_IMETHOD SetMaxTransactionCount(PRInt32 aMaxTransactionCount); \
  NS_SCRIPTABLE NS_IMETHOD PeekUndoStack(nsITransaction **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PeekRedoStack(nsITransaction **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUndoList(nsITransactionList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRedoList(nsITransactionList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsITransactionListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsITransactionListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSACTIONMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(nsITransaction *aTransaction) { return _to DoTransaction(aTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD UndoTransaction(void) { return _to UndoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD RedoTransaction(void) { return _to RedoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginBatch(void) { return _to BeginBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD EndBatch(void) { return _to EndBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfUndoItems(PRInt32 *aNumberOfUndoItems) { return _to GetNumberOfUndoItems(aNumberOfUndoItems); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfRedoItems(PRInt32 *aNumberOfRedoItems) { return _to GetNumberOfRedoItems(aNumberOfRedoItems); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxTransactionCount(PRInt32 *aMaxTransactionCount) { return _to GetMaxTransactionCount(aMaxTransactionCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxTransactionCount(PRInt32 aMaxTransactionCount) { return _to SetMaxTransactionCount(aMaxTransactionCount); } \
  NS_SCRIPTABLE NS_IMETHOD PeekUndoStack(nsITransaction **_retval NS_OUTPARAM) { return _to PeekUndoStack(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PeekRedoStack(nsITransaction **_retval NS_OUTPARAM) { return _to PeekRedoStack(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUndoList(nsITransactionList **_retval NS_OUTPARAM) { return _to GetUndoList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRedoList(nsITransactionList **_retval NS_OUTPARAM) { return _to GetRedoList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsITransactionListener *aListener) { return _to AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsITransactionListener *aListener) { return _to RemoveListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSACTIONMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(nsITransaction *aTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoTransaction(aTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD UndoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UndoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD RedoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RedoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD EndBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfUndoItems(PRInt32 *aNumberOfUndoItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfUndoItems(aNumberOfUndoItems); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfRedoItems(PRInt32 *aNumberOfRedoItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfRedoItems(aNumberOfRedoItems); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxTransactionCount(PRInt32 *aMaxTransactionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxTransactionCount(aMaxTransactionCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxTransactionCount(PRInt32 aMaxTransactionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxTransactionCount(aMaxTransactionCount); } \
  NS_SCRIPTABLE NS_IMETHOD PeekUndoStack(nsITransaction **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PeekUndoStack(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PeekRedoStack(nsITransaction **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PeekRedoStack(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUndoList(nsITransactionList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUndoList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRedoList(nsITransactionList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedoList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsITransactionListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsITransactionListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransactionManager : public nsITransactionManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSACTIONMANAGER

  nsTransactionManager();

private:
  ~nsTransactionManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransactionManager, nsITransactionManager)

nsTransactionManager::nsTransactionManager()
{
  /* member initializers and constructor code */
}

nsTransactionManager::~nsTransactionManager()
{
  /* destructor code */
}

/* void doTransaction (in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransactionManager::DoTransaction(nsITransaction *aTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undoTransaction (); */
NS_IMETHODIMP nsTransactionManager::UndoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redoTransaction (); */
NS_IMETHODIMP nsTransactionManager::RedoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsTransactionManager::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginBatch (); */
NS_IMETHODIMP nsTransactionManager::BeginBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endBatch (); */
NS_IMETHODIMP nsTransactionManager::EndBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numberOfUndoItems; */
NS_IMETHODIMP nsTransactionManager::GetNumberOfUndoItems(PRInt32 *aNumberOfUndoItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numberOfRedoItems; */
NS_IMETHODIMP nsTransactionManager::GetNumberOfRedoItems(PRInt32 *aNumberOfRedoItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxTransactionCount; */
NS_IMETHODIMP nsTransactionManager::GetMaxTransactionCount(PRInt32 *aMaxTransactionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTransactionManager::SetMaxTransactionCount(PRInt32 aMaxTransactionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransaction peekUndoStack (); */
NS_IMETHODIMP nsTransactionManager::PeekUndoStack(nsITransaction **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransaction peekRedoStack (); */
NS_IMETHODIMP nsTransactionManager::PeekRedoStack(nsITransaction **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransactionList getUndoList (); */
NS_IMETHODIMP nsTransactionManager::GetUndoList(nsITransactionList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransactionList getRedoList (); */
NS_IMETHODIMP nsTransactionManager::GetRedoList(nsITransactionList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddListener (in nsITransactionListener aListener); */
NS_IMETHODIMP nsTransactionManager::AddListener(nsITransactionListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveListener (in nsITransactionListener aListener); */
NS_IMETHODIMP nsTransactionManager::RemoveListener(nsITransactionListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransactionManager_h__ */
