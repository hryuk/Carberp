/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/txmgr/idl/nsITransaction.idl
 */

#ifndef __gen_nsITransaction_h__
#define __gen_nsITransaction_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITransaction */
#define NS_ITRANSACTION_IID_STR "58e330c1-7b48-11d2-98b9-00805f297d89"

#define NS_ITRANSACTION_IID \
  {0x58e330c1, 0x7b48, 0x11d2, \
    { 0x98, 0xb9, 0x00, 0x80, 0x5f, 0x29, 0x7d, 0x89 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITransaction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSACTION_IID)

  /**
   * Executes the transaction.
   */
  /* void doTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(void) = 0;

  /**
   * Restores the state to what it was before the transaction was executed.
   */
  /* void undoTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD UndoTransaction(void) = 0;

  /**
   * Executes the transaction again. Can only be called on a transaction that
   * was previously undone.
   * <P>
   * In most cases, the redoTransaction() method will actually call the
   * doTransaction() method to execute the transaction again.
   */
  /* void redoTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD RedoTransaction(void) = 0;

  /**
   * The transaction's transient state. This attribute is checked by
   * the transaction manager after the transaction's Execute() method is called.
   * If the transient state is false, a reference to the transaction is
   * held by the transaction manager so that the transactions' undoTransaction()
   * and redoTransaction() methods can be called. If the transient state is
   * true, the transaction manager returns immediately after the transaction's
   * doTransaction() method is called, no references to the transaction are
   * maintained. Transient transactions cannot be undone or redone by the
   * transaction manager.
   */
  /* readonly attribute boolean isTransient; */
  NS_SCRIPTABLE NS_IMETHOD GetIsTransient(PRBool *aIsTransient) = 0;

  /**
   * Attempts to merge a transaction into "this" transaction. Both transactions
   * must be in their undo state, doTransaction() methods already called. The
   * transaction manager calls this method to coalesce a new transaction with
   * the transaction on the top of the undo stack.
   * This method returns a boolean value that indicates the merge result.
   * A true value indicates that the transactions were merged successfully,
   * a false value if the merge was not possible or failed. If true,
   * the transaction manager will Release() the new transacton instead of
   * pushing it on the undo stack.
   * @param aTransaction the previously executed transaction to merge.
   */
  /* boolean merge (in nsITransaction aTransaction); */
  NS_SCRIPTABLE NS_IMETHOD Merge(nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransaction, NS_ITRANSACTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSACTION \
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD UndoTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD RedoTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD GetIsTransient(PRBool *aIsTransient); \
  NS_SCRIPTABLE NS_IMETHOD Merge(nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSACTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(void) { return _to DoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD UndoTransaction(void) { return _to UndoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD RedoTransaction(void) { return _to RedoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsTransient(PRBool *aIsTransient) { return _to GetIsTransient(aIsTransient); } \
  NS_SCRIPTABLE NS_IMETHOD Merge(nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) { return _to Merge(aTransaction, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSACTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD UndoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UndoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD RedoTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RedoTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsTransient(PRBool *aIsTransient) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTransient(aIsTransient); } \
  NS_SCRIPTABLE NS_IMETHOD Merge(nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Merge(aTransaction, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransaction : public nsITransaction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSACTION

  nsTransaction();

private:
  ~nsTransaction();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransaction, nsITransaction)

nsTransaction::nsTransaction()
{
  /* member initializers and constructor code */
}

nsTransaction::~nsTransaction()
{
  /* destructor code */
}

/* void doTransaction (); */
NS_IMETHODIMP nsTransaction::DoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undoTransaction (); */
NS_IMETHODIMP nsTransaction::UndoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redoTransaction (); */
NS_IMETHODIMP nsTransaction::RedoTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isTransient; */
NS_IMETHODIMP nsTransaction::GetIsTransient(PRBool *aIsTransient)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean merge (in nsITransaction aTransaction); */
NS_IMETHODIMP nsTransaction::Merge(nsITransaction *aTransaction, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransaction_h__ */
