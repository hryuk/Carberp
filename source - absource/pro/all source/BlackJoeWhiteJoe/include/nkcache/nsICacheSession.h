/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/cache/public/nsICacheSession.idl
 */

#ifndef __gen_nsICacheSession_h__
#define __gen_nsICacheSession_h__


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
class nsICacheEntryDescriptor; /* forward declaration */

class nsICacheListener; /* forward declaration */


/* starting interface:    nsICacheSession */
#define NS_ICACHESESSION_IID_STR "ae9e84b5-3e2d-457e-8fcd-5bbd2a8b832e"

#define NS_ICACHESESSION_IID \
  {0xae9e84b5, 0x3e2d, 0x457e, \
    { 0x8f, 0xcd, 0x5b, 0xbd, 0x2a, 0x8b, 0x83, 0x2e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICacheSession : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESESSION_IID)

  /**
     * Expired entries will be doomed or evicted if this attribute is set to
     * true.  If false, expired entries will be returned (useful for offline-
     * mode and clients, such as HTTP, that can update the valid lifetime of
     * cached content).  This attribute defaults to true.
     */
  /* attribute PRBool doomEntriesIfExpired; */
  NS_SCRIPTABLE NS_IMETHOD GetDoomEntriesIfExpired(PRBool *aDoomEntriesIfExpired) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDoomEntriesIfExpired(PRBool aDoomEntriesIfExpired) = 0;

  /**
     * A cache session can only give out one descriptor with WRITE access
     * to a given cache entry at a time.  Until the client calls MarkValid on
     * its descriptor, other attempts to open the same cache entry will block.
     */
/**
     * Synchronous cache access.  This returns a unique descriptor each
     * time it is called, even if the same key is specified.  When
     * called by multiple threads for write access, only one writable
     * descriptor will be granted.  If 'blockingMode' is set to false, it will
     * return NS_ERROR_CACHE_WAIT_FOR_VALIDATION rather than block when another
     * descriptor has been given WRITE access but hasn't validated the entry yet.
     */
  /* nsICacheEntryDescriptor openCacheEntry (in ACString key, in nsCacheAccessMode accessRequested, in boolean blockingMode); */
  NS_SCRIPTABLE NS_IMETHOD OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, PRBool blockingMode, nsICacheEntryDescriptor **_retval NS_OUTPARAM) = 0;

  /**
     * Asynchronous cache access. Does not block the calling thread.
     * Instead, the listener will be notified when the descriptor is
     * available.
     */
  /* void asyncOpenCacheEntry (in ACString key, in nsCacheAccessMode accessRequested, in nsICacheListener listener); */
  NS_SCRIPTABLE NS_IMETHOD AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener) = 0;

  /**
     * Evict all entries for this session's clientID according to its storagePolicy.
     */
  /* void evictEntries (); */
  NS_SCRIPTABLE NS_IMETHOD EvictEntries(void) = 0;

  /**
     * Return whether any of the cache devices implied by the session storage policy
     * are currently enabled for instantiation if they don't already exist.
     */
  /* PRBool isStorageEnabled (); */
  NS_SCRIPTABLE NS_IMETHOD IsStorageEnabled(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheSession, NS_ICACHESESSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESESSION \
  NS_SCRIPTABLE NS_IMETHOD GetDoomEntriesIfExpired(PRBool *aDoomEntriesIfExpired); \
  NS_SCRIPTABLE NS_IMETHOD SetDoomEntriesIfExpired(PRBool aDoomEntriesIfExpired); \
  NS_SCRIPTABLE NS_IMETHOD OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, PRBool blockingMode, nsICacheEntryDescriptor **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener); \
  NS_SCRIPTABLE NS_IMETHOD EvictEntries(void); \
  NS_SCRIPTABLE NS_IMETHOD IsStorageEnabled(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESESSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDoomEntriesIfExpired(PRBool *aDoomEntriesIfExpired) { return _to GetDoomEntriesIfExpired(aDoomEntriesIfExpired); } \
  NS_SCRIPTABLE NS_IMETHOD SetDoomEntriesIfExpired(PRBool aDoomEntriesIfExpired) { return _to SetDoomEntriesIfExpired(aDoomEntriesIfExpired); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, PRBool blockingMode, nsICacheEntryDescriptor **_retval NS_OUTPARAM) { return _to OpenCacheEntry(key, accessRequested, blockingMode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener) { return _to AsyncOpenCacheEntry(key, accessRequested, listener); } \
  NS_SCRIPTABLE NS_IMETHOD EvictEntries(void) { return _to EvictEntries(); } \
  NS_SCRIPTABLE NS_IMETHOD IsStorageEnabled(PRBool *_retval NS_OUTPARAM) { return _to IsStorageEnabled(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESESSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDoomEntriesIfExpired(PRBool *aDoomEntriesIfExpired) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoomEntriesIfExpired(aDoomEntriesIfExpired); } \
  NS_SCRIPTABLE NS_IMETHOD SetDoomEntriesIfExpired(PRBool aDoomEntriesIfExpired) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDoomEntriesIfExpired(aDoomEntriesIfExpired); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, PRBool blockingMode, nsICacheEntryDescriptor **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenCacheEntry(key, accessRequested, blockingMode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncOpenCacheEntry(key, accessRequested, listener); } \
  NS_SCRIPTABLE NS_IMETHOD EvictEntries(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictEntries(); } \
  NS_SCRIPTABLE NS_IMETHOD IsStorageEnabled(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsStorageEnabled(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheSession : public nsICacheSession
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESESSION

  nsCacheSession();

private:
  ~nsCacheSession();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheSession, nsICacheSession)

nsCacheSession::nsCacheSession()
{
  /* member initializers and constructor code */
}

nsCacheSession::~nsCacheSession()
{
  /* destructor code */
}

/* attribute PRBool doomEntriesIfExpired; */
NS_IMETHODIMP nsCacheSession::GetDoomEntriesIfExpired(PRBool *aDoomEntriesIfExpired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheSession::SetDoomEntriesIfExpired(PRBool aDoomEntriesIfExpired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICacheEntryDescriptor openCacheEntry (in ACString key, in nsCacheAccessMode accessRequested, in boolean blockingMode); */
NS_IMETHODIMP nsCacheSession::OpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, PRBool blockingMode, nsICacheEntryDescriptor **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncOpenCacheEntry (in ACString key, in nsCacheAccessMode accessRequested, in nsICacheListener listener); */
NS_IMETHODIMP nsCacheSession::AsyncOpenCacheEntry(const nsACString & key, nsCacheAccessMode accessRequested, nsICacheListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictEntries (); */
NS_IMETHODIMP nsCacheSession::EvictEntries()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool isStorageEnabled (); */
NS_IMETHODIMP nsCacheSession::IsStorageEnabled(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheSession_h__ */
