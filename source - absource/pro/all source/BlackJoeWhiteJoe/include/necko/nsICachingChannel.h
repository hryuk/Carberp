/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsICachingChannel.idl
 */

#ifndef __gen_nsICachingChannel_h__
#define __gen_nsICachingChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsICachingChannel */
#define NS_ICACHINGCHANNEL_IID_STR "830d4bcb-3e46-4011-9bda-51a5d1af891f"

#define NS_ICACHINGCHANNEL_IID \
  {0x830d4bcb, 0x3e46, 0x4011, \
    { 0x9b, 0xda, 0x51, 0xa5, 0xd1, 0xaf, 0x89, 0x1f }}

/**
 * A channel may optionally implement this interface to allow clients
 * to affect its behavior with respect to how it uses the cache service.
 *
 * This interface provides:
 *   1) Support for "stream as file" semantics (for JAR and plugins).
 *   2) Support for "pinning" cached data in the cache (for printing and save-as).
 *   3) Support for uniquely identifying cached data in cases when the URL
 *      is insufficient (e.g., HTTP form submission).
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICachingChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHINGCHANNEL_IID)

  /**
     * Set/get the cache token... uniquely identifies the data in the cache.
     * Holding a reference to this token prevents the cached data from being
     * removed.
     * 
     * A cache token retrieved from a particular instance of nsICachingChannel
     * could be set on another instance of nsICachingChannel provided the
     * underlying implementations are compatible.  The implementation of
     * nsICachingChannel would be expected to only read from the cache entry
     * identified by the cache token and not try to validate it.
     *
     * The cache token can be QI'd to a nsICacheEntryInfo if more detail
     * about the cache entry is needed (e.g., expiration time).
     */
  /* attribute nsISupports cacheToken; */
  NS_SCRIPTABLE NS_IMETHOD GetCacheToken(nsISupports * *aCacheToken) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCacheToken(nsISupports * aCacheToken) = 0;

  /**
     * The same as above but accessing the offline app cache token if there
     * is any.
     *
     * @throws
     *      NS_ERROR_NOT_AVAILABLE when there is not offline cache token
     */
  /* attribute nsISupports offlineCacheToken; */
  NS_SCRIPTABLE NS_IMETHOD GetOfflineCacheToken(nsISupports * *aOfflineCacheToken) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOfflineCacheToken(nsISupports * aOfflineCacheToken) = 0;

  /**
     * Set/get the cache key... uniquely identifies the data in the cache
     * for this channel.  Holding a reference to this key does NOT prevent
     * the cached data from being removed.
     * 
     * A cache key retrieved from a particular instance of nsICachingChannel
     * could be set on another instance of nsICachingChannel provided the
     * underlying implementations are compatible and provided the new 
     * channel instance was created with the same URI.  The implementation of
     * nsICachingChannel would be expected to use the cache entry identified
     * by the cache token.  Depending on the value of nsIRequest::loadFlags,
     * the cache entry may be validated, overwritten, or simply read.
     *
     * The cache key may be NULL indicating that the URI of the channel is
     * sufficient to locate the same cache entry.  Setting a NULL cache key
     * is likewise valid.
     */
  /* attribute nsISupports cacheKey; */
  NS_SCRIPTABLE NS_IMETHOD GetCacheKey(nsISupports * *aCacheKey) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCacheKey(nsISupports * aCacheKey) = 0;

  /**
     * Specifies whether or not the data should be cached to a file.  This
     * may fail if the disk cache is not present.  The value of this attribute
     * is usually only settable during the processing of a channel's
     * OnStartRequest.  The default value of this attribute depends on the
     * particular implementation of nsICachingChannel.
     */
  /* attribute boolean cacheAsFile; */
  NS_SCRIPTABLE NS_IMETHOD GetCacheAsFile(PRBool *aCacheAsFile) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCacheAsFile(PRBool aCacheAsFile) = 0;

  /**
     * Specifies whether or not the data should be placed in the offline cache,
     * in addition to normal memory/disk caching.  This may fail if the offline
     * cache is not present.  The value of this attribute should be set before
     * opening the channel.
     */
  /* attribute boolean cacheForOfflineUse; */
  NS_SCRIPTABLE NS_IMETHOD GetCacheForOfflineUse(PRBool *aCacheForOfflineUse) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCacheForOfflineUse(PRBool aCacheForOfflineUse) = 0;

  /**
     * The session into which to cache offline data.  If not specified,
     * data will be placed in "HTTP-offline"
     */
  /* attribute ACString offlineCacheClientID; */
  NS_SCRIPTABLE NS_IMETHOD GetOfflineCacheClientID(nsACString & aOfflineCacheClientID) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOfflineCacheClientID(const nsACString & aOfflineCacheClientID) = 0;

  /**
     * Get the "file" where the cached data can be found.  This is valid for
     * as long as a reference to the cache token is held.  This may return
     * an error if cacheAsFile is false.
     */
  /* readonly attribute nsIFile cacheFile; */
  NS_SCRIPTABLE NS_IMETHOD GetCacheFile(nsIFile * *aCacheFile) = 0;

  /**
     * TRUE if this channel's data is being loaded from the cache.  This value
     * is undefined before the channel fires its OnStartRequest notification
     * and after the channel fires its OnStopRequest notification.
     */
  /* boolean isFromCache (); */
  NS_SCRIPTABLE NS_IMETHOD IsFromCache(PRBool *_retval NS_OUTPARAM) = 0;

  /**************************************************************************
     * Caching channel specific load flags:
     */
/**
     * This load flag inhibits fetching from the net.  An error of
     * NS_ERROR_DOCUMENT_NOT_CACHED will be sent to the listener's
     * onStopRequest if network IO is necessary to complete the request.
     *
     * This flag can be used to find out whether fetching this URL would
     * cause validation of the cache entry via the network.
     *
     * Combining this flag with LOAD_BYPASS_LOCAL_CACHE will cause all
     * loads to fail. This flag differs from LOAD_ONLY_FROM_CACHE in that
     * this flag fails the load if validation is required while
     * LOAD_ONLY_FROM_CACHE skips validation where possible.
     */
  enum { LOAD_NO_NETWORK_IO = 67108864U };

  /**
     * This load flag causes the offline cache to be checked when fetching
     * a request.  It will be set automatically if the browser is offline.
     *
     * This flag will not be transferred through a redirect.
     */
  enum { LOAD_CHECK_OFFLINE_CACHE = 134217728U };

  /**
     * This load flag causes the local cache to be skipped when fetching a
     * request.  Unlike LOAD_BYPASS_CACHE, it does not force an end-to-end load
     * (i.e., it does not affect proxy caches).
     */
  enum { LOAD_BYPASS_LOCAL_CACHE = 268435456U };

  /**
     * This load flag causes the local cache to be skipped if the request
     * would otherwise block waiting to access the cache.
     */
  enum { LOAD_BYPASS_LOCAL_CACHE_IF_BUSY = 536870912U };

  /**
     * This load flag inhibits fetching from the net if the data in the cache
     * has been evicted.  An error of NS_ERROR_DOCUMENT_NOT_CACHED will be sent
     * to the listener's onStopRequest in this case.  This flag is set
     * automatically when the application is offline.
     */
  enum { LOAD_ONLY_FROM_CACHE = 1073741824U };

  /**
     * This load flag controls what happens when a document would be loaded
     * from the cache to satisfy a call to AsyncOpen.  If this attribute is
     * set to TRUE, then the document will not be loaded from the cache.  A
     * stream listener can check nsICachingChannel::isFromCache to determine
     * if the AsyncOpen will actually result in data being streamed.
     *
     * If this flag has been set, and the request can be satisfied via the
     * cache, then the OnDataAvailable events will be skipped.  The listener
     * will only see OnStartRequest followed by OnStopRequest.
     */
  enum { LOAD_ONLY_IF_MODIFIED = 2147483648U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICachingChannel, NS_ICACHINGCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHINGCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetCacheToken(nsISupports * *aCacheToken); \
  NS_SCRIPTABLE NS_IMETHOD SetCacheToken(nsISupports * aCacheToken); \
  NS_SCRIPTABLE NS_IMETHOD GetOfflineCacheToken(nsISupports * *aOfflineCacheToken); \
  NS_SCRIPTABLE NS_IMETHOD SetOfflineCacheToken(nsISupports * aOfflineCacheToken); \
  NS_SCRIPTABLE NS_IMETHOD GetCacheKey(nsISupports * *aCacheKey); \
  NS_SCRIPTABLE NS_IMETHOD SetCacheKey(nsISupports * aCacheKey); \
  NS_SCRIPTABLE NS_IMETHOD GetCacheAsFile(PRBool *aCacheAsFile); \
  NS_SCRIPTABLE NS_IMETHOD SetCacheAsFile(PRBool aCacheAsFile); \
  NS_SCRIPTABLE NS_IMETHOD GetCacheForOfflineUse(PRBool *aCacheForOfflineUse); \
  NS_SCRIPTABLE NS_IMETHOD SetCacheForOfflineUse(PRBool aCacheForOfflineUse); \
  NS_SCRIPTABLE NS_IMETHOD GetOfflineCacheClientID(nsACString & aOfflineCacheClientID); \
  NS_SCRIPTABLE NS_IMETHOD SetOfflineCacheClientID(const nsACString & aOfflineCacheClientID); \
  NS_SCRIPTABLE NS_IMETHOD GetCacheFile(nsIFile * *aCacheFile); \
  NS_SCRIPTABLE NS_IMETHOD IsFromCache(PRBool *_retval NS_OUTPARAM); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHINGCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCacheToken(nsISupports * *aCacheToken) { return _to GetCacheToken(aCacheToken); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheToken(nsISupports * aCacheToken) { return _to SetCacheToken(aCacheToken); } \
  NS_SCRIPTABLE NS_IMETHOD GetOfflineCacheToken(nsISupports * *aOfflineCacheToken) { return _to GetOfflineCacheToken(aOfflineCacheToken); } \
  NS_SCRIPTABLE NS_IMETHOD SetOfflineCacheToken(nsISupports * aOfflineCacheToken) { return _to SetOfflineCacheToken(aOfflineCacheToken); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheKey(nsISupports * *aCacheKey) { return _to GetCacheKey(aCacheKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheKey(nsISupports * aCacheKey) { return _to SetCacheKey(aCacheKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheAsFile(PRBool *aCacheAsFile) { return _to GetCacheAsFile(aCacheAsFile); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheAsFile(PRBool aCacheAsFile) { return _to SetCacheAsFile(aCacheAsFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheForOfflineUse(PRBool *aCacheForOfflineUse) { return _to GetCacheForOfflineUse(aCacheForOfflineUse); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheForOfflineUse(PRBool aCacheForOfflineUse) { return _to SetCacheForOfflineUse(aCacheForOfflineUse); } \
  NS_SCRIPTABLE NS_IMETHOD GetOfflineCacheClientID(nsACString & aOfflineCacheClientID) { return _to GetOfflineCacheClientID(aOfflineCacheClientID); } \
  NS_SCRIPTABLE NS_IMETHOD SetOfflineCacheClientID(const nsACString & aOfflineCacheClientID) { return _to SetOfflineCacheClientID(aOfflineCacheClientID); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheFile(nsIFile * *aCacheFile) { return _to GetCacheFile(aCacheFile); } \
  NS_SCRIPTABLE NS_IMETHOD IsFromCache(PRBool *_retval NS_OUTPARAM) { return _to IsFromCache(_retval); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHINGCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCacheToken(nsISupports * *aCacheToken) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheToken(aCacheToken); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheToken(nsISupports * aCacheToken) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheToken(aCacheToken); } \
  NS_SCRIPTABLE NS_IMETHOD GetOfflineCacheToken(nsISupports * *aOfflineCacheToken) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOfflineCacheToken(aOfflineCacheToken); } \
  NS_SCRIPTABLE NS_IMETHOD SetOfflineCacheToken(nsISupports * aOfflineCacheToken) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOfflineCacheToken(aOfflineCacheToken); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheKey(nsISupports * *aCacheKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheKey(aCacheKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheKey(nsISupports * aCacheKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheKey(aCacheKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheAsFile(PRBool *aCacheAsFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheAsFile(aCacheAsFile); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheAsFile(PRBool aCacheAsFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheAsFile(aCacheAsFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheForOfflineUse(PRBool *aCacheForOfflineUse) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheForOfflineUse(aCacheForOfflineUse); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheForOfflineUse(PRBool aCacheForOfflineUse) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheForOfflineUse(aCacheForOfflineUse); } \
  NS_SCRIPTABLE NS_IMETHOD GetOfflineCacheClientID(nsACString & aOfflineCacheClientID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOfflineCacheClientID(aOfflineCacheClientID); } \
  NS_SCRIPTABLE NS_IMETHOD SetOfflineCacheClientID(const nsACString & aOfflineCacheClientID) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOfflineCacheClientID(aOfflineCacheClientID); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheFile(nsIFile * *aCacheFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheFile(aCacheFile); } \
  NS_SCRIPTABLE NS_IMETHOD IsFromCache(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsFromCache(_retval); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCachingChannel : public nsICachingChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHINGCHANNEL

  nsCachingChannel();

private:
  ~nsCachingChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCachingChannel, nsICachingChannel)

nsCachingChannel::nsCachingChannel()
{
  /* member initializers and constructor code */
}

nsCachingChannel::~nsCachingChannel()
{
  /* destructor code */
}

/* attribute nsISupports cacheToken; */
NS_IMETHODIMP nsCachingChannel::GetCacheToken(nsISupports * *aCacheToken)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCachingChannel::SetCacheToken(nsISupports * aCacheToken)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports offlineCacheToken; */
NS_IMETHODIMP nsCachingChannel::GetOfflineCacheToken(nsISupports * *aOfflineCacheToken)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCachingChannel::SetOfflineCacheToken(nsISupports * aOfflineCacheToken)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports cacheKey; */
NS_IMETHODIMP nsCachingChannel::GetCacheKey(nsISupports * *aCacheKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCachingChannel::SetCacheKey(nsISupports * aCacheKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean cacheAsFile; */
NS_IMETHODIMP nsCachingChannel::GetCacheAsFile(PRBool *aCacheAsFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCachingChannel::SetCacheAsFile(PRBool aCacheAsFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean cacheForOfflineUse; */
NS_IMETHODIMP nsCachingChannel::GetCacheForOfflineUse(PRBool *aCacheForOfflineUse)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCachingChannel::SetCacheForOfflineUse(PRBool aCacheForOfflineUse)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString offlineCacheClientID; */
NS_IMETHODIMP nsCachingChannel::GetOfflineCacheClientID(nsACString & aOfflineCacheClientID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCachingChannel::SetOfflineCacheClientID(const nsACString & aOfflineCacheClientID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile cacheFile; */
NS_IMETHODIMP nsCachingChannel::GetCacheFile(nsIFile * *aCacheFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isFromCache (); */
NS_IMETHODIMP nsCachingChannel::IsFromCache(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICachingChannel_h__ */
