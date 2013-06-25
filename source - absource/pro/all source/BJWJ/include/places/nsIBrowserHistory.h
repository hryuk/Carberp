/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/places/public/nsIBrowserHistory.idl
 */

#ifndef __gen_nsIBrowserHistory_h__
#define __gen_nsIBrowserHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIGlobalHistory2_h__
#include "nsIGlobalHistory2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBrowserHistory */
#define NS_IBROWSERHISTORY_IID_STR "96602bf3-de2a-42ed-812f-a83b130e6299"

#define NS_IBROWSERHISTORY_IID \
  {0x96602bf3, 0xde2a, 0x42ed, \
    { 0x81, 0x2f, 0xa8, 0x3b, 0x13, 0x0e, 0x62, 0x99 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIBrowserHistory : public nsIGlobalHistory2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERHISTORY_IID)

  /**
     * addPageWithDetails
     *
     * Adds a page to history with specific time stamp information. This is used in
     * the History migrator. 
     */
  /* void addPageWithDetails (in nsIURI aURI, in wstring aTitle, in long long aLastVisited); */
  NS_SCRIPTABLE NS_IMETHOD AddPageWithDetails(nsIURI *aURI, const PRUnichar *aTitle, PRInt64 aLastVisited) = 0;

  /**
     * lastPageVisited
     *
     * The last page that was visited in a top-level window.
     */
  /* readonly attribute AUTF8String lastPageVisited; */
  NS_SCRIPTABLE NS_IMETHOD GetLastPageVisited(nsACString & aLastPageVisited) = 0;

  /**
     * count
     *
     * Indicate if there are entries in global history
     * For performance reasons this does not return the real number of entries
     */
  /* readonly attribute PRUint32 count; */
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRUint32 *aCount) = 0;

  /**
     * removePage
     *
     * Remove a page from history
     */
  /* void removePage (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD RemovePage(nsIURI *aURI) = 0;

  /**
     * removePages
     *
     * Remove a bunch of pages from history
     * Notice that this does not call observers for performance reasons,
     * instead setting aDoBatchNotify true will send Begin/EndUpdateBatch
     */
  /* void removePages ([array, size_is (aLength)] in nsIURI aURIs, in unsigned long aLength, in boolean aDoBatchNotify); */
  NS_SCRIPTABLE NS_IMETHOD RemovePages(nsIURI **aURIs, PRUint32 aLength, PRBool aDoBatchNotify) = 0;

  /**
     * removePagesFromHost
     *
     * Removes all history information about pages from a given host. If
     * aEntireDomain is set, we will also delete pages from sub hosts (so if
     * we are passed in "microsoft.com" we delete "www.microsoft.com",
     * "msdn.microsoft.com", etc.). An empty host name means local files and
     * anything else with no host name. You can also pass in the localized
     * "(local files)" title given to you from a history query to remove all
     * history information from local files.
     *
     * Note that this does not call observers for single deleted uris,
     * but will send Begin/EndUpdateBatch.
     */
  /* void removePagesFromHost (in AUTF8String aHost, in boolean aEntireDomain); */
  NS_SCRIPTABLE NS_IMETHOD RemovePagesFromHost(const nsACString & aHost, PRBool aEntireDomain) = 0;

  /**
     * removePagesByTimeframe
     *
     * Remove all pages for a given timeframe.
     * Limits are included: aBeginTime <= timeframe <= aEndTime
     * Notice that this does not call observers for single deleted uris,
     * instead it will send Begin/EndUpdateBatch
     */
  /* void removePagesByTimeframe (in long long aBeginTime, in long long aEndTime); */
  NS_SCRIPTABLE NS_IMETHOD RemovePagesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) = 0;

  /**
     * removeAllPages
     *
     * Remove all pages from global history
     */
  /* void removeAllPages (); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAllPages(void) = 0;

  /**
     * hidePage
     *
     * Hide the specified URL from being enumerated (and thus
     * displayed in the UI)
     * If the page hasn't been visited yet, then it will be added
     * as if it was visited, and then marked as hidden
     */
  /* void hidePage (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD HidePage(nsIURI *aURI) = 0;

  /**
     * markPageAsTyped
     *
     * Designate the url as having been explicitly typed in by
     * the user, so it's okay to be an autocomplete result.
     */
  /* void markPageAsTyped (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserHistory, NS_IBROWSERHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERHISTORY \
  NS_SCRIPTABLE NS_IMETHOD AddPageWithDetails(nsIURI *aURI, const PRUnichar *aTitle, PRInt64 aLastVisited); \
  NS_SCRIPTABLE NS_IMETHOD GetLastPageVisited(nsACString & aLastPageVisited); \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRUint32 *aCount); \
  NS_SCRIPTABLE NS_IMETHOD RemovePage(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD RemovePages(nsIURI **aURIs, PRUint32 aLength, PRBool aDoBatchNotify); \
  NS_SCRIPTABLE NS_IMETHOD RemovePagesFromHost(const nsACString & aHost, PRBool aEntireDomain); \
  NS_SCRIPTABLE NS_IMETHOD RemovePagesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllPages(void); \
  NS_SCRIPTABLE NS_IMETHOD HidePage(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD MarkPageAsTyped(nsIURI *aURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddPageWithDetails(nsIURI *aURI, const PRUnichar *aTitle, PRInt64 aLastVisited) { return _to AddPageWithDetails(aURI, aTitle, aLastVisited); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastPageVisited(nsACString & aLastPageVisited) { return _to GetLastPageVisited(aLastPageVisited); } \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRUint32 *aCount) { return _to GetCount(aCount); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePage(nsIURI *aURI) { return _to RemovePage(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePages(nsIURI **aURIs, PRUint32 aLength, PRBool aDoBatchNotify) { return _to RemovePages(aURIs, aLength, aDoBatchNotify); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePagesFromHost(const nsACString & aHost, PRBool aEntireDomain) { return _to RemovePagesFromHost(aHost, aEntireDomain); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePagesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) { return _to RemovePagesByTimeframe(aBeginTime, aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllPages(void) { return _to RemoveAllPages(); } \
  NS_SCRIPTABLE NS_IMETHOD HidePage(nsIURI *aURI) { return _to HidePage(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) { return _to MarkPageAsTyped(aURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddPageWithDetails(nsIURI *aURI, const PRUnichar *aTitle, PRInt64 aLastVisited) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddPageWithDetails(aURI, aTitle, aLastVisited); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastPageVisited(nsACString & aLastPageVisited) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastPageVisited(aLastPageVisited); } \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRUint32 *aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(aCount); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePage(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePage(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePages(nsIURI **aURIs, PRUint32 aLength, PRBool aDoBatchNotify) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePages(aURIs, aLength, aDoBatchNotify); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePagesFromHost(const nsACString & aHost, PRBool aEntireDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePagesFromHost(aHost, aEntireDomain); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePagesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePagesByTimeframe(aBeginTime, aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllPages(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllPages(); } \
  NS_SCRIPTABLE NS_IMETHOD HidePage(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->HidePage(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsTyped(aURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserHistory : public nsIBrowserHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERHISTORY

  nsBrowserHistory();

private:
  ~nsBrowserHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserHistory, nsIBrowserHistory)

nsBrowserHistory::nsBrowserHistory()
{
  /* member initializers and constructor code */
}

nsBrowserHistory::~nsBrowserHistory()
{
  /* destructor code */
}

/* void addPageWithDetails (in nsIURI aURI, in wstring aTitle, in long long aLastVisited); */
NS_IMETHODIMP nsBrowserHistory::AddPageWithDetails(nsIURI *aURI, const PRUnichar *aTitle, PRInt64 aLastVisited)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String lastPageVisited; */
NS_IMETHODIMP nsBrowserHistory::GetLastPageVisited(nsACString & aLastPageVisited)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 count; */
NS_IMETHODIMP nsBrowserHistory::GetCount(PRUint32 *aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePage (in nsIURI aURI); */
NS_IMETHODIMP nsBrowserHistory::RemovePage(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePages ([array, size_is (aLength)] in nsIURI aURIs, in unsigned long aLength, in boolean aDoBatchNotify); */
NS_IMETHODIMP nsBrowserHistory::RemovePages(nsIURI **aURIs, PRUint32 aLength, PRBool aDoBatchNotify)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePagesFromHost (in AUTF8String aHost, in boolean aEntireDomain); */
NS_IMETHODIMP nsBrowserHistory::RemovePagesFromHost(const nsACString & aHost, PRBool aEntireDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePagesByTimeframe (in long long aBeginTime, in long long aEndTime); */
NS_IMETHODIMP nsBrowserHistory::RemovePagesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllPages (); */
NS_IMETHODIMP nsBrowserHistory::RemoveAllPages()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hidePage (in nsIURI aURI); */
NS_IMETHODIMP nsBrowserHistory::HidePage(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsTyped (in nsIURI aURI); */
NS_IMETHODIMP nsBrowserHistory::MarkPageAsTyped(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBrowserHistory_MOZILLA_1_9_1_ADDITIONS */
#define NS_IBROWSERHISTORY_MOZILLA_1_9_1_ADDITIONS_IID_STR "130f2940-6a63-4790-ae8d-89d5a2683090"

#define NS_IBROWSERHISTORY_MOZILLA_1_9_1_ADDITIONS_IID \
  {0x130f2940, 0x6a63, 0x4790, \
    { 0xae, 0x8d, 0x89, 0xd5, 0xa2, 0x68, 0x30, 0x90 }}

/**
 * Additional methods for browser history.  You must QI to this interface to
 * use its methods.
 *
 * This interface was added after the binary compatibility freeze, so it lives
 * in a separate interface for 1.9.1.  In future releases, the methods found in
 * this interface will be in nsIBrowserHistory.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIBrowserHistory_MOZILLA_1_9_1_ADDITIONS : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERHISTORY_MOZILLA_1_9_1_ADDITIONS_IID)

  /**
     * removeVisitsByTimeframe
     *
     * Removes all visits in a given timeframe.  Limits are included:
     * aBeginTime <= timeframe <= aEndTime.  Any place that becomes unvisited
     * as a result will also be deleted.
     *
     * Note that removal is performed in batch, so observers will not be
     * notified of individual places that are deleted.  Instead they will be
     * notified onBeginUpdateBatch and onEndUpdateBatch.
     */
  /* void removeVisitsByTimeframe (in long long aBeginTime, in long long aEndTime); */
  NS_SCRIPTABLE NS_IMETHOD RemoveVisitsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserHistory_MOZILLA_1_9_1_ADDITIONS, NS_IBROWSERHISTORY_MOZILLA_1_9_1_ADDITIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERHISTORY_MOZILLA_1_9_1_ADDITIONS \
  NS_SCRIPTABLE NS_IMETHOD RemoveVisitsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERHISTORY_MOZILLA_1_9_1_ADDITIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD RemoveVisitsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) { return _to RemoveVisitsByTimeframe(aBeginTime, aEndTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERHISTORY_MOZILLA_1_9_1_ADDITIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD RemoveVisitsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveVisitsByTimeframe(aBeginTime, aEndTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserHistory_MOZILLA_1_9_1_ADDITIONS : public nsIBrowserHistory_MOZILLA_1_9_1_ADDITIONS
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERHISTORY_MOZILLA_1_9_1_ADDITIONS

  nsBrowserHistory_MOZILLA_1_9_1_ADDITIONS();

private:
  ~nsBrowserHistory_MOZILLA_1_9_1_ADDITIONS();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserHistory_MOZILLA_1_9_1_ADDITIONS, nsIBrowserHistory_MOZILLA_1_9_1_ADDITIONS)

nsBrowserHistory_MOZILLA_1_9_1_ADDITIONS::nsBrowserHistory_MOZILLA_1_9_1_ADDITIONS()
{
  /* member initializers and constructor code */
}

nsBrowserHistory_MOZILLA_1_9_1_ADDITIONS::~nsBrowserHistory_MOZILLA_1_9_1_ADDITIONS()
{
  /* destructor code */
}

/* void removeVisitsByTimeframe (in long long aBeginTime, in long long aEndTime); */
NS_IMETHODIMP nsBrowserHistory_MOZILLA_1_9_1_ADDITIONS::RemoveVisitsByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserHistory_h__ */
