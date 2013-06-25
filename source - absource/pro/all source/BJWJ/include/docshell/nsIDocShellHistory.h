/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIDocShellHistory.idl
 */

#ifndef __gen_nsIDocShellHistory_h__
#define __gen_nsIDocShellHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISHEntry; /* forward declaration */


/* starting interface:    nsIDocShellHistory */
#define NS_IDOCSHELLHISTORY_IID_STR "89caa9f0-8b1c-47fb-b0d3-f0aef0bff749"

#define NS_IDOCSHELLHISTORY_IID \
  {0x89caa9f0, 0x8b1c, 0x47fb, \
    { 0xb0, 0xd3, 0xf0, 0xae, 0xf0, 0xbf, 0xf7, 0x49 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocShellHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLHISTORY_IID)

  /**
   * Get the SHEntry associated with a child docshell
   */
  /* nsISHEntry getChildSHEntry (in long aChildOffset); */
  NS_SCRIPTABLE NS_IMETHOD GetChildSHEntry(PRInt32 aChildOffset, nsISHEntry **_retval NS_OUTPARAM) = 0;

  /**
   * Add a Child SHEntry for a frameset page
   */
  /* void addChildSHEntry (in nsISHEntry aCloneReference, in nsISHEntry aHistoryEntry, in long aChildOffset); */
  NS_SCRIPTABLE NS_IMETHOD AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, PRInt32 aChildOffset) = 0;

  /* attribute boolean useGlobalHistory; */
  NS_SCRIPTABLE NS_IMETHOD GetUseGlobalHistory(PRBool *aUseGlobalHistory) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUseGlobalHistory(PRBool aUseGlobalHistory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellHistory, NS_IDOCSHELLHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLHISTORY \
  NS_SCRIPTABLE NS_IMETHOD GetChildSHEntry(PRInt32 aChildOffset, nsISHEntry **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, PRInt32 aChildOffset); \
  NS_SCRIPTABLE NS_IMETHOD GetUseGlobalHistory(PRBool *aUseGlobalHistory); \
  NS_SCRIPTABLE NS_IMETHOD SetUseGlobalHistory(PRBool aUseGlobalHistory); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChildSHEntry(PRInt32 aChildOffset, nsISHEntry **_retval NS_OUTPARAM) { return _to GetChildSHEntry(aChildOffset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, PRInt32 aChildOffset) { return _to AddChildSHEntry(aCloneReference, aHistoryEntry, aChildOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetUseGlobalHistory(PRBool *aUseGlobalHistory) { return _to GetUseGlobalHistory(aUseGlobalHistory); } \
  NS_SCRIPTABLE NS_IMETHOD SetUseGlobalHistory(PRBool aUseGlobalHistory) { return _to SetUseGlobalHistory(aUseGlobalHistory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChildSHEntry(PRInt32 aChildOffset, nsISHEntry **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildSHEntry(aChildOffset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, PRInt32 aChildOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddChildSHEntry(aCloneReference, aHistoryEntry, aChildOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetUseGlobalHistory(PRBool *aUseGlobalHistory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseGlobalHistory(aUseGlobalHistory); } \
  NS_SCRIPTABLE NS_IMETHOD SetUseGlobalHistory(PRBool aUseGlobalHistory) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUseGlobalHistory(aUseGlobalHistory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellHistory : public nsIDocShellHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLHISTORY

  nsDocShellHistory();

private:
  ~nsDocShellHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShellHistory, nsIDocShellHistory)

nsDocShellHistory::nsDocShellHistory()
{
  /* member initializers and constructor code */
}

nsDocShellHistory::~nsDocShellHistory()
{
  /* destructor code */
}

/* nsISHEntry getChildSHEntry (in long aChildOffset); */
NS_IMETHODIMP nsDocShellHistory::GetChildSHEntry(PRInt32 aChildOffset, nsISHEntry **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addChildSHEntry (in nsISHEntry aCloneReference, in nsISHEntry aHistoryEntry, in long aChildOffset); */
NS_IMETHODIMP nsDocShellHistory::AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, PRInt32 aChildOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean useGlobalHistory; */
NS_IMETHODIMP nsDocShellHistory::GetUseGlobalHistory(PRBool *aUseGlobalHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellHistory::SetUseGlobalHistory(PRBool aUseGlobalHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellHistory_h__ */
