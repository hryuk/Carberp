/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/shistory/public/nsISHistoryInternal.idl
 */

#ifndef __gen_nsISHistoryInternal_h__
#define __gen_nsISHistoryInternal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIFactory_h__
#include "nsIFactory.h"
#endif

#ifndef __gen_nsISHEntry_h__
#include "nsISHEntry.h"
#endif

#ifndef __gen_nsISHTransaction_h__
#include "nsISHTransaction.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISHistoryListener; /* forward declaration */

class nsIDocShell; /* forward declaration */

#define NS_SHISTORY_INTERNAL_CID \
{ 0x9c47c121, 0x1c6e, 0x4d8f, \
  { 0xb9, 0x04, 0x3a, 0xc9, 0x68, 0x11, 0x6e, 0x88 } }
#define NS_SHISTORY_INTERNAL_CONTRACTID "@mozilla.org/browser/shistory-internal;1"

/* starting interface:    nsISHistoryInternal */
#define NS_ISHISTORYINTERNAL_IID_STR "7ca0fd71-437c-48ad-985d-11ce9e2429b4"

#define NS_ISHISTORYINTERNAL_IID \
  {0x7ca0fd71, 0x437c, 0x48ad, \
    { 0x98, 0x5d, 0x11, 0xce, 0x9e, 0x24, 0x29, 0xb4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISHistoryInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHISTORYINTERNAL_IID)

  /**
   * Add a new Entry to the History List
   * @param aEntry - The entry to add
   * @param aPersist - If true this specifies that the entry should persist
   * in the list.  If false, this means that when new entries are added
   * this element will not appear in the session history list.
   */
  /* void addEntry (in nsISHEntry aEntry, in boolean aPersist); */
  NS_SCRIPTABLE NS_IMETHOD AddEntry(nsISHEntry *aEntry, PRBool aPersist) = 0;

  /**
   * Get the root transaction
   */
  /* readonly attribute nsISHTransaction rootTransaction; */
  NS_SCRIPTABLE NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) = 0;

  /**
   * The toplevel docshell object to which this SHistory object belongs to.
   */
  /* attribute nsIDocShell rootDocShell; */
  NS_SCRIPTABLE NS_IMETHOD GetRootDocShell(nsIDocShell * *aRootDocShell) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetRootDocShell(nsIDocShell * aRootDocShell) = 0;

  /** 
   * Update the index maintained by sessionHistory
   */
  /* void updateIndex (); */
  NS_SCRIPTABLE NS_IMETHOD UpdateIndex(void) = 0;

  /**
   * Replace the nsISHEntry at a particular index
   * @param aIndex - The index at which the entry shoud be replaced
   * @param aReplaceEntry - The replacement entry for the index.
   */
  /* void replaceEntry (in long aIndex, in nsISHEntry aReplaceEntry); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceEntry(PRInt32 aIndex, nsISHEntry *aReplaceEntry) = 0;

  /** 
   * Get handle to the history listener
   */
  /* readonly attribute nsISHistoryListener listener; */
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsISHistoryListener * *aListener) = 0;

  /**
   * Evict content viewers until the number of content viewers per tab
   * is no more than gHistoryMaxViewers.  Also, count
   * total number of content viewers globally and evict one if we are over
   * our total max.  This is always called in Show(), after we destroy
   * the previous viewer.
   */
  /* void evictContentViewers (in long previousIndex, in long index); */
  NS_SCRIPTABLE NS_IMETHOD EvictContentViewers(PRInt32 previousIndex, PRInt32 index) = 0;

  /**
    * Evict the content viewer associated with a session history entry
    * that has timed out.
    */
  /* void evictExpiredContentViewerForEntry (in nsISHEntry aEntry); */
  NS_SCRIPTABLE NS_IMETHOD EvictExpiredContentViewerForEntry(nsISHEntry *aEntry) = 0;

  /**
    * Evict all the content viewers in this session history
    */
  /* void evictAllContentViewers (); */
  NS_SCRIPTABLE NS_IMETHOD EvictAllContentViewers(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHistoryInternal, NS_ISHISTORYINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHISTORYINTERNAL \
  NS_SCRIPTABLE NS_IMETHOD AddEntry(nsISHEntry *aEntry, PRBool aPersist); \
  NS_SCRIPTABLE NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction); \
  NS_SCRIPTABLE NS_IMETHOD GetRootDocShell(nsIDocShell * *aRootDocShell); \
  NS_SCRIPTABLE NS_IMETHOD SetRootDocShell(nsIDocShell * aRootDocShell); \
  NS_SCRIPTABLE NS_IMETHOD UpdateIndex(void); \
  NS_SCRIPTABLE NS_IMETHOD ReplaceEntry(PRInt32 aIndex, nsISHEntry *aReplaceEntry); \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsISHistoryListener * *aListener); \
  NS_SCRIPTABLE NS_IMETHOD EvictContentViewers(PRInt32 previousIndex, PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD EvictExpiredContentViewerForEntry(nsISHEntry *aEntry); \
  NS_SCRIPTABLE NS_IMETHOD EvictAllContentViewers(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHISTORYINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddEntry(nsISHEntry *aEntry, PRBool aPersist) { return _to AddEntry(aEntry, aPersist); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) { return _to GetRootTransaction(aRootTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootDocShell(nsIDocShell * *aRootDocShell) { return _to GetRootDocShell(aRootDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD SetRootDocShell(nsIDocShell * aRootDocShell) { return _to SetRootDocShell(aRootDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateIndex(void) { return _to UpdateIndex(); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceEntry(PRInt32 aIndex, nsISHEntry *aReplaceEntry) { return _to ReplaceEntry(aIndex, aReplaceEntry); } \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsISHistoryListener * *aListener) { return _to GetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD EvictContentViewers(PRInt32 previousIndex, PRInt32 index) { return _to EvictContentViewers(previousIndex, index); } \
  NS_SCRIPTABLE NS_IMETHOD EvictExpiredContentViewerForEntry(nsISHEntry *aEntry) { return _to EvictExpiredContentViewerForEntry(aEntry); } \
  NS_SCRIPTABLE NS_IMETHOD EvictAllContentViewers(void) { return _to EvictAllContentViewers(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHISTORYINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddEntry(nsISHEntry *aEntry, PRBool aPersist) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEntry(aEntry, aPersist); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootTransaction(aRootTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootDocShell(nsIDocShell * *aRootDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootDocShell(aRootDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD SetRootDocShell(nsIDocShell * aRootDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRootDocShell(aRootDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateIndex(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateIndex(); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceEntry(PRInt32 aIndex, nsISHEntry *aReplaceEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceEntry(aIndex, aReplaceEntry); } \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsISHistoryListener * *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD EvictContentViewers(PRInt32 previousIndex, PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictContentViewers(previousIndex, index); } \
  NS_SCRIPTABLE NS_IMETHOD EvictExpiredContentViewerForEntry(nsISHEntry *aEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictExpiredContentViewerForEntry(aEntry); } \
  NS_SCRIPTABLE NS_IMETHOD EvictAllContentViewers(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictAllContentViewers(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHistoryInternal : public nsISHistoryInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHISTORYINTERNAL

  nsSHistoryInternal();

private:
  ~nsSHistoryInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSHistoryInternal, nsISHistoryInternal)

nsSHistoryInternal::nsSHistoryInternal()
{
  /* member initializers and constructor code */
}

nsSHistoryInternal::~nsSHistoryInternal()
{
  /* destructor code */
}

/* void addEntry (in nsISHEntry aEntry, in boolean aPersist); */
NS_IMETHODIMP nsSHistoryInternal::AddEntry(nsISHEntry *aEntry, PRBool aPersist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISHTransaction rootTransaction; */
NS_IMETHODIMP nsSHistoryInternal::GetRootTransaction(nsISHTransaction * *aRootTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDocShell rootDocShell; */
NS_IMETHODIMP nsSHistoryInternal::GetRootDocShell(nsIDocShell * *aRootDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHistoryInternal::SetRootDocShell(nsIDocShell * aRootDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateIndex (); */
NS_IMETHODIMP nsSHistoryInternal::UpdateIndex()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceEntry (in long aIndex, in nsISHEntry aReplaceEntry); */
NS_IMETHODIMP nsSHistoryInternal::ReplaceEntry(PRInt32 aIndex, nsISHEntry *aReplaceEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISHistoryListener listener; */
NS_IMETHODIMP nsSHistoryInternal::GetListener(nsISHistoryListener * *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictContentViewers (in long previousIndex, in long index); */
NS_IMETHODIMP nsSHistoryInternal::EvictContentViewers(PRInt32 previousIndex, PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictExpiredContentViewerForEntry (in nsISHEntry aEntry); */
NS_IMETHODIMP nsSHistoryInternal::EvictExpiredContentViewerForEntry(nsISHEntry *aEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictAllContentViewers (); */
NS_IMETHODIMP nsSHistoryInternal::EvictAllContentViewers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISHistoryInternal_h__ */
