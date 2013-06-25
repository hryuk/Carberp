/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/txmgr/idl/nsITransactionListener.idl
 */

#ifndef __gen_nsITransactionListener_h__
#define __gen_nsITransactionListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITransaction; /* forward declaration */

class nsITransactionManager; /* forward declaration */


/* starting interface:    nsITransactionListener */
#define NS_ITRANSACTIONLISTENER_IID_STR "58e330c4-7b48-11d2-98b9-00805f297d89"

#define NS_ITRANSACTIONLISTENER_IID \
  {0x58e330c4, 0x7b48, 0x11d2, \
    { 0x98, 0xb9, 0x00, 0x80, 0x5f, 0x29, 0x7d, 0x89 }}

/**
 * The nsITransactionListener interface.
 * <P>
 * This interface is implemented by an object that tracks transactions.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsITransactionListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSACTIONLISTENER_IID)

  /**
   * Called before a transaction manager calls a transaction's
   * doTransaction() method.
   * @param aManager the transaction manager doing the transaction.
   * @param aTransaction the transaction being executed.
   * @result boolean value returned by listener which indicates
   * it's desire to interrupt normal control flow. Listeners should
   * return true if they want to interrupt normal control flow, without
   * throwing an error.
   */
  /* boolean willDo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
  NS_SCRIPTABLE NS_IMETHOD WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Called after a transaction manager calls the doTransaction() method of
   * a transaction.
   * @param aManager the transaction manager that did the transaction.
   * @param aTransaction the transaction that was executed.
   * @param aDoResult the nsresult returned after executing
   * the transaction.
   */
  /* void didDo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aDoResult); */
  NS_SCRIPTABLE NS_IMETHOD DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult) = 0;

  /**
   * Called before a transaction manager calls the Undo() method of
   * a transaction.
   * @param aManager the transaction manager undoing the transaction.
   * @param aTransaction the transaction being undone.
   * @result boolean value returned by listener which indicates
   * it's desire to interrupt normal control flow. Listeners should
   * return true if they want to interrupt normal control flow, without
   * throwing an error. Note that listeners can also interrupt normal
   * control flow by throwing an nsresult that indicates an error.
   */
  /* boolean willUndo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
  NS_SCRIPTABLE NS_IMETHOD WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Called after a transaction manager calls the Undo() method of
   * a transaction.
   * @param aManager the transaction manager undoing the transaction.
   * @param aTransaction the transaction being undone.
   * @param aUndoResult the nsresult returned after undoing the transaction.
   */
  /* void didUndo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aUndoResult); */
  NS_SCRIPTABLE NS_IMETHOD DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult) = 0;

  /**
   * Called before a transaction manager calls the Redo() method of
   * a transaction.
   * @param aManager the transaction manager redoing the transaction.
   * @param aTransaction the transaction being redone.
   * @result boolean value returned by listener which indicates
   * it's desire to interrupt normal control flow. Listeners should
   * return true if they want to interrupt normal control flow, without
   * throwing an error. Note that listeners can also interrupt normal
   * control flow by throwing an nsresult that indicates an error.
   */
  /* boolean willRedo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
  NS_SCRIPTABLE NS_IMETHOD WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Called after a transaction manager calls the Redo() method of
   * a transaction.
   * @param aManager the transaction manager redoing the transaction.
   * @param aTransaction the transaction being redone.
   * @param aRedoResult the nsresult returned after redoing the transaction.
   */
  /* void didRedo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aRedoResult); */
  NS_SCRIPTABLE NS_IMETHOD DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult) = 0;

  /**
   * Called before a transaction manager begins a batch.
   * @param aManager the transaction manager beginning a batch.
   * @result boolean value returned by listener which indicates
   * it's desire to interrupt normal control flow. Listeners should
   * return true if they want to interrupt normal control flow, without
   * throwing an error. Note that listeners can also interrupt normal
   * control flow by throwing an nsresult that indicates an error.
   */
  /* boolean willBeginBatch (in nsITransactionManager aManager); */
  NS_SCRIPTABLE NS_IMETHOD WillBeginBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Called after a transaction manager begins a batch.
   * @param aManager the transaction manager that began a batch.
   * @param aResult the nsresult returned after beginning a batch.
   */
  /* void didBeginBatch (in nsITransactionManager aManager, in nsresult aResult); */
  NS_SCRIPTABLE NS_IMETHOD DidBeginBatch(nsITransactionManager *aManager, nsresult aResult) = 0;

  /**
   * Called before a transaction manager ends a batch.
   * @param aManager the transaction manager ending a batch.
   * @result boolean value returned by listener which indicates
   * it's desire to interrupt normal control flow. Listeners should
   * return true if they want to interrupt normal control flow, without
   * throwing an error. Note that listeners can also interrupt normal
   * control flow by throwing an nsresult that indicates an error.
   */
  /* boolean willEndBatch (in nsITransactionManager aManager); */
  NS_SCRIPTABLE NS_IMETHOD WillEndBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Called after a transaction manager ends a batch.
   * @param aManager the transaction manager ending a batch.
   * @param aResult the nsresult returned after ending a batch.
   */
  /* void didEndBatch (in nsITransactionManager aManager, in nsresult aResult); */
  NS_SCRIPTABLE NS_IMETHOD DidEndBatch(nsITransactionManager *aManager, nsresult aResult) = 0;

  /**
   * Called before a transaction manager tries to merge
   * a transaction, that was just executed, with the
   * transaction at the top of the undo stack.
   * @param aManager the transaction manager ending a batch.
   * @param aTopTransaction the transaction at the top of the undo stack.
   * @param aTransactionToMerge the transaction to merge.
   * @result boolean value returned by listener which indicates
   * it's desire to interrupt normal control flow. Listeners should
   * return true if they want to interrupt normal control flow, without
   * throwing an error. Note that listeners can also interrupt normal
   * control flow by throwing an nsresult that indicates an error.
   */
  /* boolean willMerge (in nsITransactionManager aManager, in nsITransaction aTopTransaction, in nsITransaction aTransactionToMerge); */
  NS_SCRIPTABLE NS_IMETHOD WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Called after a transaction manager tries to merge
   * a transaction, that was just executed, with the
   * transaction at the top of the undo stack.
   * @param aManager the transaction manager ending a batch.
   * @param aTopTransaction the transaction at the top of the undo stack.
   * @param aTransactionToMerge the transaction to merge.
   * @param aDidMerge true if transaction was merged, else false.
   * @param aMergeResult the nsresult returned after the merge attempt.
   * @param aInterrupt listeners should set this to PR_TRUE if they
   * want to interrupt normal control flow, without throwing an error.
   */
  /* void didMerge (in nsITransactionManager aManager, in nsITransaction aTopTransaction, in nsITransaction aTransactionToMerge, in boolean aDidMerge, in nsresult aMergeResult); */
  NS_SCRIPTABLE NS_IMETHOD DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool aDidMerge, nsresult aMergeResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransactionListener, NS_ITRANSACTIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSACTIONLISTENER \
  NS_SCRIPTABLE NS_IMETHOD WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult); \
  NS_SCRIPTABLE NS_IMETHOD WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult); \
  NS_SCRIPTABLE NS_IMETHOD WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult); \
  NS_SCRIPTABLE NS_IMETHOD WillBeginBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DidBeginBatch(nsITransactionManager *aManager, nsresult aResult); \
  NS_SCRIPTABLE NS_IMETHOD WillEndBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DidEndBatch(nsITransactionManager *aManager, nsresult aResult); \
  NS_SCRIPTABLE NS_IMETHOD WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool aDidMerge, nsresult aMergeResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSACTIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) { return _to WillDo(aManager, aTransaction, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult) { return _to DidDo(aManager, aTransaction, aDoResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) { return _to WillUndo(aManager, aTransaction, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult) { return _to DidUndo(aManager, aTransaction, aUndoResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) { return _to WillRedo(aManager, aTransaction, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult) { return _to DidRedo(aManager, aTransaction, aRedoResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillBeginBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM) { return _to WillBeginBatch(aManager, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidBeginBatch(nsITransactionManager *aManager, nsresult aResult) { return _to DidBeginBatch(aManager, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillEndBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM) { return _to WillEndBatch(aManager, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidEndBatch(nsITransactionManager *aManager, nsresult aResult) { return _to DidEndBatch(aManager, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool *_retval NS_OUTPARAM) { return _to WillMerge(aManager, aTopTransaction, aTransactionToMerge, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool aDidMerge, nsresult aMergeResult) { return _to DidMerge(aManager, aTopTransaction, aTransactionToMerge, aDidMerge, aMergeResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSACTIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillDo(aManager, aTransaction, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidDo(aManager, aTransaction, aDoResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillUndo(aManager, aTransaction, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidUndo(aManager, aTransaction, aUndoResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillRedo(aManager, aTransaction, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidRedo(aManager, aTransaction, aRedoResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillBeginBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillBeginBatch(aManager, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidBeginBatch(nsITransactionManager *aManager, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidBeginBatch(aManager, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillEndBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillEndBatch(aManager, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidEndBatch(nsITransactionManager *aManager, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidEndBatch(aManager, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillMerge(aManager, aTopTransaction, aTransactionToMerge, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool aDidMerge, nsresult aMergeResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidMerge(aManager, aTopTransaction, aTransactionToMerge, aDidMerge, aMergeResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransactionListener : public nsITransactionListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSACTIONLISTENER

  nsTransactionListener();

private:
  ~nsTransactionListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransactionListener, nsITransactionListener)

nsTransactionListener::nsTransactionListener()
{
  /* member initializers and constructor code */
}

nsTransactionListener::~nsTransactionListener()
{
  /* destructor code */
}

/* boolean willDo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransactionListener::WillDo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didDo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aDoResult); */
NS_IMETHODIMP nsTransactionListener::DidDo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aDoResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willUndo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransactionListener::WillUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didUndo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aUndoResult); */
NS_IMETHODIMP nsTransactionListener::DidUndo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aUndoResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willRedo (in nsITransactionManager aManager, in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransactionListener::WillRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didRedo (in nsITransactionManager aManager, in nsITransaction aTransaction, in nsresult aRedoResult); */
NS_IMETHODIMP nsTransactionListener::DidRedo(nsITransactionManager *aManager, nsITransaction *aTransaction, nsresult aRedoResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willBeginBatch (in nsITransactionManager aManager); */
NS_IMETHODIMP nsTransactionListener::WillBeginBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didBeginBatch (in nsITransactionManager aManager, in nsresult aResult); */
NS_IMETHODIMP nsTransactionListener::DidBeginBatch(nsITransactionManager *aManager, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willEndBatch (in nsITransactionManager aManager); */
NS_IMETHODIMP nsTransactionListener::WillEndBatch(nsITransactionManager *aManager, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didEndBatch (in nsITransactionManager aManager, in nsresult aResult); */
NS_IMETHODIMP nsTransactionListener::DidEndBatch(nsITransactionManager *aManager, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean willMerge (in nsITransactionManager aManager, in nsITransaction aTopTransaction, in nsITransaction aTransactionToMerge); */
NS_IMETHODIMP nsTransactionListener::WillMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didMerge (in nsITransactionManager aManager, in nsITransaction aTopTransaction, in nsITransaction aTransactionToMerge, in boolean aDidMerge, in nsresult aMergeResult); */
NS_IMETHODIMP nsTransactionListener::DidMerge(nsITransactionManager *aManager, nsITransaction *aTopTransaction, nsITransaction *aTransactionToMerge, PRBool aDidMerge, nsresult aMergeResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransactionListener_h__ */
