/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/uriloader/prefetch/nsIPrefetchService.idl
 */

#ifndef __gen_nsIPrefetchService_h__
#define __gen_nsIPrefetchService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIPrefetchService */
#define NS_IPREFETCHSERVICE_IID_STR "cba513eb-c457-4b93-832c-1a979e66edd1"

#define NS_IPREFETCHSERVICE_IID \
  {0xcba513eb, 0xc457, 0x4b93, \
    { 0x83, 0x2c, 0x1a, 0x97, 0x9e, 0x66, 0xed, 0xd1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPrefetchService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFETCHSERVICE_IID)

  /**
     * Enqueue a request to prefetch the specified URI.
     *
     * @param aURI the URI of the document to prefetch
     * @param aReferrerURI the URI of the referring page
     * @param aSource the DOM node (such as a <link> tag) that requested this
     *        fetch, or null if the prefetch was not requested by a DOM node.
     * @param aExplicit the link element has an explicit prefetch link type
     */
  /* void prefetchURI (in nsIURI aURI, in nsIURI aReferrerURI, in nsIDOMNode aSource, in boolean aExplicit); */
  NS_SCRIPTABLE NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit) = 0;

  /**
     * @status DEPRECATED This method is no longer used, and will throw
     * NS_ERROR_NOT_IMPLEMENTED.
     */
  /* void prefetchURIForOfflineUse (in nsIURI aURI, in nsIURI aReferrerURI, in nsIDOMNode aSource, in boolean aExplicit); */
  NS_SCRIPTABLE NS_IMETHOD PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit) = 0;

  /**
     * Enumerate the items in the prefetch queue.  Each element in the
     * enumeration is an nsIDOMLoadStatus.
     *
     * @param aIncludeNormalItems include normal prefetch items in the
     *        list.  This parameter is deprecated and must be TRUE,
     *        or NS_ERROR_INT_IMPLEMENTED will be thrown.
     * @param aIncludeOfflineItems include items being fetched for offline
     *        use.  This parameter is deprecated and must be FALSE,
     *        or NS_ERROR_NOT_IMPLEMENTED will be thrown.
     */
  /* nsISimpleEnumerator enumerateQueue (in boolean aIncludeNormalItems, in boolean aIncludeOfflineItems); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateQueue(PRBool aIncludeNormalItems, PRBool aIncludeOfflineItems, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefetchService, NS_IPREFETCHSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFETCHSERVICE \
  NS_SCRIPTABLE NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit); \
  NS_SCRIPTABLE NS_IMETHOD PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit); \
  NS_SCRIPTABLE NS_IMETHOD EnumerateQueue(PRBool aIncludeNormalItems, PRBool aIncludeOfflineItems, nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFETCHSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit) { return _to PrefetchURI(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_SCRIPTABLE NS_IMETHOD PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit) { return _to PrefetchURIForOfflineUse(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateQueue(PRBool aIncludeNormalItems, PRBool aIncludeOfflineItems, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to EnumerateQueue(aIncludeNormalItems, aIncludeOfflineItems, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFETCHSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrefetchURI(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_SCRIPTABLE NS_IMETHOD PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrefetchURIForOfflineUse(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateQueue(PRBool aIncludeNormalItems, PRBool aIncludeOfflineItems, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateQueue(aIncludeNormalItems, aIncludeOfflineItems, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrefetchService : public nsIPrefetchService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREFETCHSERVICE

  nsPrefetchService();

private:
  ~nsPrefetchService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrefetchService, nsIPrefetchService)

nsPrefetchService::nsPrefetchService()
{
  /* member initializers and constructor code */
}

nsPrefetchService::~nsPrefetchService()
{
  /* destructor code */
}

/* void prefetchURI (in nsIURI aURI, in nsIURI aReferrerURI, in nsIDOMNode aSource, in boolean aExplicit); */
NS_IMETHODIMP nsPrefetchService::PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void prefetchURIForOfflineUse (in nsIURI aURI, in nsIURI aReferrerURI, in nsIDOMNode aSource, in boolean aExplicit); */
NS_IMETHODIMP nsPrefetchService::PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, PRBool aExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateQueue (in boolean aIncludeNormalItems, in boolean aIncludeOfflineItems); */
NS_IMETHODIMP nsPrefetchService::EnumerateQueue(PRBool aIncludeNormalItems, PRBool aIncludeOfflineItems, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrefetchService_h__ */
