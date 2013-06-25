/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/shistory/public/nsISHTransaction.idl
 */

#ifndef __gen_nsISHTransaction_h__
#define __gen_nsISHTransaction_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISHEntry_h__
#include "nsISHEntry.h"
#endif

#ifndef __gen_nsIEnumerator_h__
#include "nsIEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISHTransaction */
#define NS_ISHTRANSACTION_IID_STR "2edf705f-d252-4971-9f09-71dd0f760dc6"

#define NS_ISHTRANSACTION_IID \
  {0x2edf705f, 0xd252, 0x4971, \
    { 0x9f, 0x09, 0x71, 0xdd, 0x0f, 0x76, 0x0d, 0xc6 }}

/**
 * The nsISHTransaction.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISHTransaction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHTRANSACTION_IID)

  /**
     * The nsISHEntry for the current transaction
     */
  /* attribute nsISHEntry sHEntry; */
  NS_SCRIPTABLE NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSHEntry(nsISHEntry * aSHEntry) = 0;

  /**
	 * The parent of this transaction
	 */
  /* attribute nsISHTransaction prev; */
  NS_SCRIPTABLE NS_IMETHOD GetPrev(nsISHTransaction * *aPrev) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrev(nsISHTransaction * aPrev) = 0;

  /**
	 * The legitimate child of this transaction 
	 */
  /* attribute nsISHTransaction next; */
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsISHTransaction * *aNext) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetNext(nsISHTransaction * aNext) = 0;

  /**
	 *	Specifies if this transaction should persist.  If not it will be replaced
	 * by new additions to the list.
	 */
  /* attribute boolean persist; */
  NS_SCRIPTABLE NS_IMETHOD GetPersist(PRBool *aPersist) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPersist(PRBool aPersist) = 0;

  /**
	 * Create a transaction with parent and History Entry 
	 */
  /* void create (in nsISHEntry aSHEntry, in nsISHTransaction aPrev); */
  NS_SCRIPTABLE NS_IMETHOD Create(nsISHEntry *aSHEntry, nsISHTransaction *aPrev) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHTransaction, NS_ISHTRANSACTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHTRANSACTION \
  NS_SCRIPTABLE NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry); \
  NS_SCRIPTABLE NS_IMETHOD SetSHEntry(nsISHEntry * aSHEntry); \
  NS_SCRIPTABLE NS_IMETHOD GetPrev(nsISHTransaction * *aPrev); \
  NS_SCRIPTABLE NS_IMETHOD SetPrev(nsISHTransaction * aPrev); \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsISHTransaction * *aNext); \
  NS_SCRIPTABLE NS_IMETHOD SetNext(nsISHTransaction * aNext); \
  NS_SCRIPTABLE NS_IMETHOD GetPersist(PRBool *aPersist); \
  NS_SCRIPTABLE NS_IMETHOD SetPersist(PRBool aPersist); \
  NS_SCRIPTABLE NS_IMETHOD Create(nsISHEntry *aSHEntry, nsISHTransaction *aPrev); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHTRANSACTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) { return _to GetSHEntry(aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD SetSHEntry(nsISHEntry * aSHEntry) { return _to SetSHEntry(aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrev(nsISHTransaction * *aPrev) { return _to GetPrev(aPrev); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrev(nsISHTransaction * aPrev) { return _to SetPrev(aPrev); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsISHTransaction * *aNext) { return _to GetNext(aNext); } \
  NS_SCRIPTABLE NS_IMETHOD SetNext(nsISHTransaction * aNext) { return _to SetNext(aNext); } \
  NS_SCRIPTABLE NS_IMETHOD GetPersist(PRBool *aPersist) { return _to GetPersist(aPersist); } \
  NS_SCRIPTABLE NS_IMETHOD SetPersist(PRBool aPersist) { return _to SetPersist(aPersist); } \
  NS_SCRIPTABLE NS_IMETHOD Create(nsISHEntry *aSHEntry, nsISHTransaction *aPrev) { return _to Create(aSHEntry, aPrev); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHTRANSACTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSHEntry(aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD SetSHEntry(nsISHEntry * aSHEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSHEntry(aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrev(nsISHTransaction * *aPrev) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrev(aPrev); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrev(nsISHTransaction * aPrev) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrev(aPrev); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsISHTransaction * *aNext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNext(aNext); } \
  NS_SCRIPTABLE NS_IMETHOD SetNext(nsISHTransaction * aNext) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNext(aNext); } \
  NS_SCRIPTABLE NS_IMETHOD GetPersist(PRBool *aPersist) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersist(aPersist); } \
  NS_SCRIPTABLE NS_IMETHOD SetPersist(PRBool aPersist) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPersist(aPersist); } \
  NS_SCRIPTABLE NS_IMETHOD Create(nsISHEntry *aSHEntry, nsISHTransaction *aPrev) { return !_to ? NS_ERROR_NULL_POINTER : _to->Create(aSHEntry, aPrev); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHTransaction : public nsISHTransaction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHTRANSACTION

  nsSHTransaction();

private:
  ~nsSHTransaction();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSHTransaction, nsISHTransaction)

nsSHTransaction::nsSHTransaction()
{
  /* member initializers and constructor code */
}

nsSHTransaction::~nsSHTransaction()
{
  /* destructor code */
}

/* attribute nsISHEntry sHEntry; */
NS_IMETHODIMP nsSHTransaction::GetSHEntry(nsISHEntry * *aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHTransaction::SetSHEntry(nsISHEntry * aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISHTransaction prev; */
NS_IMETHODIMP nsSHTransaction::GetPrev(nsISHTransaction * *aPrev)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHTransaction::SetPrev(nsISHTransaction * aPrev)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISHTransaction next; */
NS_IMETHODIMP nsSHTransaction::GetNext(nsISHTransaction * *aNext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHTransaction::SetNext(nsISHTransaction * aNext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean persist; */
NS_IMETHODIMP nsSHTransaction::GetPersist(PRBool *aPersist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHTransaction::SetPersist(PRBool aPersist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void create (in nsISHEntry aSHEntry, in nsISHTransaction aPrev); */
NS_IMETHODIMP nsSHTransaction::Create(nsISHEntry *aSHEntry, nsISHTransaction *aPrev)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {BFD1A792-AD9F-11d3-BDC7-0050040A9B44}
#define NS_SHTRANSACTION_CID \
{0xbfd1a792, 0xad9f, 0x11d3, {0xbd, 0xc7, 0x0, 0x50, 0x4, 0xa, 0x9b, 0x44}}
#define NS_SHTRANSACTION_CONTRACTID \
    "@mozilla.org/browser/session-history-transaction;1"

#endif /* __gen_nsISHTransaction_h__ */
