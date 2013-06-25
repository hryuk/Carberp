/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIDownloadHistory.idl
 */

#ifndef __gen_nsIDownloadHistory_h__
#define __gen_nsIDownloadHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIDownloadHistory */
#define NS_IDOWNLOADHISTORY_IID_STR "202533cd-a8f1-4ee4-8d20-3a6a0d2c6c51"

#define NS_IDOWNLOADHISTORY_IID \
  {0x202533cd, 0xa8f1, 0x4ee4, \
    { 0x8d, 0x20, 0x3a, 0x6a, 0x0d, 0x2c, 0x6c, 0x51 }}

/**
 * This interface can be used to add a download to history.  There is a separate
 * interface specifically for downloads in case embedders choose to track
 * downloads differently from other types of history.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDownloadHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADHISTORY_IID)

  /**
   * Adds a download to history.  This will also notify observers that the
   * URI aSource is visited with the topic NS_LINK_VISITED_EVENT_TOPIC if
   * aSource has not yet been visited.
   *
   * @param aSource
   *        The source of the download we are adding to history.  This cannot be
   *        null.
   * @param aReferrer
   *        [optional] The referrer of source URI.
   * @param aStartTime
   *        [optional] The time the download was started.  If the start time
   *        is not given, the current time is used.
   * @throws NS_ERROR_NOT_AVAILABLE
   *         In a situation where a history implementation is not available,
   *         where 'history implementation' refers to something like
   *         nsIGlobalHistory and friends.
   */
  /* void addDownload (in nsIURI aSource, [optional] in nsIURI aReferrer, [optional] in PRTime aStartTime); */
  NS_SCRIPTABLE NS_IMETHOD AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloadHistory, NS_IDOWNLOADHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADHISTORY \
  NS_SCRIPTABLE NS_IMETHOD AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime) { return _to AddDownload(aSource, aReferrer, aStartTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDownload(aSource, aReferrer, aStartTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloadHistory : public nsIDownloadHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADHISTORY

  nsDownloadHistory();

private:
  ~nsDownloadHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownloadHistory, nsIDownloadHistory)

nsDownloadHistory::nsDownloadHistory()
{
  /* member initializers and constructor code */
}

nsDownloadHistory::~nsDownloadHistory()
{
  /* destructor code */
}

/* void addDownload (in nsIURI aSource, [optional] in nsIURI aReferrer, [optional] in PRTime aStartTime); */
NS_IMETHODIMP nsDownloadHistory::AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDownloadHistory_h__ */
