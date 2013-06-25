/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/cache/public/nsICacheService.idl
 */

#ifndef __gen_nsICacheService_h__
#define __gen_nsICacheService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsICache_h__
#include "nsICache.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsICacheListener; /* forward declaration */

class nsICacheSession; /* forward declaration */

class nsICacheVisitor; /* forward declaration */


/* starting interface:    nsICacheService */
#define NS_ICACHESERVICE_IID_STR "98dd0187-aad4-4cab-82c5-1adddef3629d"

#define NS_ICACHESERVICE_IID \
  {0x98dd0187, 0xaad4, 0x4cab, \
    { 0x82, 0xc5, 0x1a, 0xdd, 0xde, 0xf3, 0x62, 0x9d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICacheService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESERVICE_IID)

  /**
     * Create a cache session
     *
     * A cache session represents a client's access into the cache.  The cache
     * session is not "owned" by the cache service.  Hence, it is possible to
     * create duplicate cache sessions.  Entries created by a cache session
     * are invisible to other cache sessions, unless the cache sessions are
     * equivalent.
     *
     * @param clientID - Specifies the name of the client using the cache.
     * @param storagePolicy - Limits the storage policy for all entries
     *   accessed via the returned session.  As a result, devices excluded
     *   by the storage policy will not be searched when opening entries
     *   from the returned session.
     * @param streamBased - Indicates whether or not the data being cached
     *   can be represented as a stream.  The storagePolicy must be 
     *   consistent with the value of this field.  For example, a non-stream-
     *   based cache entry can only have a storage policy of STORE_IN_MEMORY.
     * @return new cache session.
     */
  /* nsICacheSession createSession (in string clientID, in nsCacheStoragePolicy storagePolicy, in boolean streamBased); */
  NS_SCRIPTABLE NS_IMETHOD CreateSession(const char *clientID, nsCacheStoragePolicy storagePolicy, PRBool streamBased, nsICacheSession **_retval NS_OUTPARAM) = 0;

  /**
     * Visit entries stored in the cache.  Used to implement about:cache.
     */
  /* void visitEntries (in nsICacheVisitor visitor); */
  NS_SCRIPTABLE NS_IMETHOD VisitEntries(nsICacheVisitor *visitor) = 0;

  /**
     * Evicts all entries in all devices implied by the storage policy.
     */
  /* void evictEntries (in nsCacheStoragePolicy storagePolicy); */
  NS_SCRIPTABLE NS_IMETHOD EvictEntries(nsCacheStoragePolicy storagePolicy) = 0;

  /**
     * This method is deprecated and will throw NS_ERROR_NOT_IMPLEMENTED.
     */
  /* ACString createTemporaryClientID (in nsCacheStoragePolicy storagePolicy); */
  NS_SCRIPTABLE NS_IMETHOD CreateTemporaryClientID(nsCacheStoragePolicy storagePolicy, nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheService, NS_ICACHESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESERVICE \
  NS_SCRIPTABLE NS_IMETHOD CreateSession(const char *clientID, nsCacheStoragePolicy storagePolicy, PRBool streamBased, nsICacheSession **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD VisitEntries(nsICacheVisitor *visitor); \
  NS_SCRIPTABLE NS_IMETHOD EvictEntries(nsCacheStoragePolicy storagePolicy); \
  NS_SCRIPTABLE NS_IMETHOD CreateTemporaryClientID(nsCacheStoragePolicy storagePolicy, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateSession(const char *clientID, nsCacheStoragePolicy storagePolicy, PRBool streamBased, nsICacheSession **_retval NS_OUTPARAM) { return _to CreateSession(clientID, storagePolicy, streamBased, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD VisitEntries(nsICacheVisitor *visitor) { return _to VisitEntries(visitor); } \
  NS_SCRIPTABLE NS_IMETHOD EvictEntries(nsCacheStoragePolicy storagePolicy) { return _to EvictEntries(storagePolicy); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTemporaryClientID(nsCacheStoragePolicy storagePolicy, nsACString & _retval NS_OUTPARAM) { return _to CreateTemporaryClientID(storagePolicy, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateSession(const char *clientID, nsCacheStoragePolicy storagePolicy, PRBool streamBased, nsICacheSession **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSession(clientID, storagePolicy, streamBased, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD VisitEntries(nsICacheVisitor *visitor) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitEntries(visitor); } \
  NS_SCRIPTABLE NS_IMETHOD EvictEntries(nsCacheStoragePolicy storagePolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictEntries(storagePolicy); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTemporaryClientID(nsCacheStoragePolicy storagePolicy, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTemporaryClientID(storagePolicy, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheService : public nsICacheService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESERVICE

  nsCacheService();

private:
  ~nsCacheService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheService, nsICacheService)

nsCacheService::nsCacheService()
{
  /* member initializers and constructor code */
}

nsCacheService::~nsCacheService()
{
  /* destructor code */
}

/* nsICacheSession createSession (in string clientID, in nsCacheStoragePolicy storagePolicy, in boolean streamBased); */
NS_IMETHODIMP nsCacheService::CreateSession(const char *clientID, nsCacheStoragePolicy storagePolicy, PRBool streamBased, nsICacheSession **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void visitEntries (in nsICacheVisitor visitor); */
NS_IMETHODIMP nsCacheService::VisitEntries(nsICacheVisitor *visitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictEntries (in nsCacheStoragePolicy storagePolicy); */
NS_IMETHODIMP nsCacheService::EvictEntries(nsCacheStoragePolicy storagePolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString createTemporaryClientID (in nsCacheStoragePolicy storagePolicy); */
NS_IMETHODIMP nsCacheService::CreateTemporaryClientID(nsCacheStoragePolicy storagePolicy, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * Observer service notification that is sent when
 * nsICacheService::evictEntries() or nsICacheSession::evictEntries()
 * is called.
 */
#define NS_CACHESERVICE_EMPTYCACHE_TOPIC_ID "cacheservice:empty-cache"

#endif /* __gen_nsICacheService_h__ */
