/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIApplicationCache.idl
 */

#ifndef __gen_nsIApplicationCache_h__
#define __gen_nsIApplicationCache_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */


/* starting interface:    nsIApplicationCacheNamespace */
#define NS_IAPPLICATIONCACHENAMESPACE_IID_STR "96e4c264-2065-4ce9-93bb-43734c62c4eb"

#define NS_IAPPLICATIONCACHENAMESPACE_IID \
  {0x96e4c264, 0x2065, 0x4ce9, \
    { 0x93, 0xbb, 0x43, 0x73, 0x4c, 0x62, 0xc4, 0xeb }}

/**
 * Application caches can store a set of namespace entries that affect
 * loads from the application cache.  If a load from the cache fails
 * to match an exact cache entry, namespaces entries will be searched
 * for a substring match, and should be applied appropriately.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIApplicationCacheNamespace : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONCACHENAMESPACE_IID)

  /**
     * Items matching this namespace can be fetched from the network
     * when loading from this cache.  The "data" attribute is unused.
     */
  enum { NAMESPACE_BYPASS = 1U };

  /**
     * Items matching this namespace can be fetched from the network
     * when loading from this cache.  If the load fails, the cache entry
     * specified by the "data" attribute should be loaded instead.
     */
  enum { NAMESPACE_FALLBACK = 2U };

  /**
     * Items matching this namespace should be cached
     * opportunistically.  Successful toplevel loads of documents
     * in this namespace should be placed in the application cache.
     * Namespaces specifying NAMESPACE_OPPORTUNISTIC may also specify
     * NAMESPACE_FALLBACK to supply a fallback entry.
     */
  enum { NAMESPACE_OPPORTUNISTIC = 4U };

  /**
     * Initialize the namespace.
     */
  /* void init (in unsigned long itemType, in ACString namespaceSpec, in ACString data); */
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 itemType, const nsACString & namespaceSpec, const nsACString & data) = 0;

  /**
     * The namespace type.
     */
  /* readonly attribute unsigned long itemType; */
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRUint32 *aItemType) = 0;

  /**
     * The prefix of this namespace.  This should be the asciiSpec of the
     * URI prefix.
     */
  /* readonly attribute ACString namespaceSpec; */
  NS_SCRIPTABLE NS_IMETHOD GetNamespaceSpec(nsACString & aNamespaceSpec) = 0;

  /**
     * Data associated with this namespace, such as a fallback.  URI data should
     * use the asciiSpec of the URI.
     */
  /* readonly attribute ACString data; */
  NS_SCRIPTABLE NS_IMETHOD GetData(nsACString & aData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationCacheNamespace, NS_IAPPLICATIONCACHENAMESPACE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONCACHENAMESPACE \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 itemType, const nsACString & namespaceSpec, const nsACString & data); \
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRUint32 *aItemType); \
  NS_SCRIPTABLE NS_IMETHOD GetNamespaceSpec(nsACString & aNamespaceSpec); \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsACString & aData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONCACHENAMESPACE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 itemType, const nsACString & namespaceSpec, const nsACString & data) { return _to Init(itemType, namespaceSpec, data); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRUint32 *aItemType) { return _to GetItemType(aItemType); } \
  NS_SCRIPTABLE NS_IMETHOD GetNamespaceSpec(nsACString & aNamespaceSpec) { return _to GetNamespaceSpec(aNamespaceSpec); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsACString & aData) { return _to GetData(aData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONCACHENAMESPACE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 itemType, const nsACString & namespaceSpec, const nsACString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(itemType, namespaceSpec, data); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRUint32 *aItemType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemType(aItemType); } \
  NS_SCRIPTABLE NS_IMETHOD GetNamespaceSpec(nsACString & aNamespaceSpec) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamespaceSpec(aNamespaceSpec); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsACString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationCacheNamespace : public nsIApplicationCacheNamespace
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONCACHENAMESPACE

  nsApplicationCacheNamespace();

private:
  ~nsApplicationCacheNamespace();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationCacheNamespace, nsIApplicationCacheNamespace)

nsApplicationCacheNamespace::nsApplicationCacheNamespace()
{
  /* member initializers and constructor code */
}

nsApplicationCacheNamespace::~nsApplicationCacheNamespace()
{
  /* destructor code */
}

/* void init (in unsigned long itemType, in ACString namespaceSpec, in ACString data); */
NS_IMETHODIMP nsApplicationCacheNamespace::Init(PRUint32 itemType, const nsACString & namespaceSpec, const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long itemType; */
NS_IMETHODIMP nsApplicationCacheNamespace::GetItemType(PRUint32 *aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString namespaceSpec; */
NS_IMETHODIMP nsApplicationCacheNamespace::GetNamespaceSpec(nsACString & aNamespaceSpec)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString data; */
NS_IMETHODIMP nsApplicationCacheNamespace::GetData(nsACString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIApplicationCache */
#define NS_IAPPLICATIONCACHE_IID_STR "663e2e2e-04a0-47b6-87b3-a122be46cb53"

#define NS_IAPPLICATIONCACHE_IID \
  {0x663e2e2e, 0x04a0, 0x47b6, \
    { 0x87, 0xb3, 0xa1, 0x22, 0xbe, 0x46, 0xcb, 0x53 }}

/**
 * Application caches store resources for offline use.  Each
 * application cache has a unique client ID for use with
 * nsICacheService::openSession() to access the cache's entries.
 *
 * Each entry in the application cache can be marked with a set of
 * types, as discussed in the WHAT-WG offline applications
 * specification.
 *
 * All application caches with the same group ID belong to a cache
 * group.  Each group has one "active" cache that will service future
 * loads.  Inactive caches will be removed from the cache when they are
 * no longer referenced.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIApplicationCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONCACHE_IID)

  /**
     * Entries in an application cache can be marked as one or more of
     * the following types.
     */
  enum { ITEM_MANIFEST = 1U };

  enum { ITEM_EXPLICIT = 2U };

  enum { ITEM_IMPLICIT = 4U };

  enum { ITEM_DYNAMIC = 8U };

  enum { ITEM_FOREIGN = 16U };

  enum { ITEM_FALLBACK = 32U };

  enum { ITEM_OPPORTUNISTIC = 64U };

  /**
     * The group ID for this cache group.  This is the URI of the
     * manifest file.
     **/
  /* readonly attribute ACString groupID; */
  NS_SCRIPTABLE NS_IMETHOD GetGroupID(nsACString & aGroupID) = 0;

  /**
     * The client ID for this application cache.  Clients can open a
     * session with nsICacheService::createSession() using this client
     * ID and a storage policy of STORE_OFFLINE to access this cache.
     */
  /* readonly attribute ACString clientID; */
  NS_SCRIPTABLE NS_IMETHOD GetClientID(nsACString & aClientID) = 0;

  /**
     * TRUE if the cache is the active cache for this group.
     */
  /* readonly attribute boolean active; */
  NS_SCRIPTABLE NS_IMETHOD GetActive(PRBool *aActive) = 0;

  /**
     * The disk usage of the application cache, in bytes.
     */
  /* readonly attribute unsigned long usage; */
  NS_SCRIPTABLE NS_IMETHOD GetUsage(PRUint32 *aUsage) = 0;

  /**
     * Makes this cache the active application cache for this group.
     * Future loads associated with this group will come from this
     * cache.  Other caches from this cache group will be deactivated.
     */
  /* void activate (); */
  NS_SCRIPTABLE NS_IMETHOD Activate(void) = 0;

  /**
     * Discard this application cache.  Removes all cached resources
     * for this cache.  If this is the active application cache for the
     * group, the group will be removed.
     */
  /* void discard (); */
  NS_SCRIPTABLE NS_IMETHOD Discard(void) = 0;

  /**
     * Adds item types to a given entry.
     */
  /* void markEntry (in ACString key, in unsigned long typeBits); */
  NS_SCRIPTABLE NS_IMETHOD MarkEntry(const nsACString & key, PRUint32 typeBits) = 0;

  /**
     * Removes types from a given entry.  If the resulting entry has
     * no types left, the entry is removed.
     */
  /* void unmarkEntry (in ACString key, in unsigned long typeBits); */
  NS_SCRIPTABLE NS_IMETHOD UnmarkEntry(const nsACString & key, PRUint32 typeBits) = 0;

  /**
     * Gets the types for a given entry.
     */
  /* unsigned long getTypes (in ACString key); */
  NS_SCRIPTABLE NS_IMETHOD GetTypes(const nsACString & key, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
     * Returns any entries in the application cache whose type matches
     * one or more of the bits in typeBits.
     */
  /* void gatherEntries (in PRUint32 typeBits, out unsigned long count, [array, size_is (count)] out string keys); */
  NS_SCRIPTABLE NS_IMETHOD GatherEntries(PRUint32 typeBits, PRUint32 *count NS_OUTPARAM, char ***keys NS_OUTPARAM) = 0;

  /**
     * Add a set of namespace entries to the application cache.
     * @param namespaces
     *        An nsIArray of nsIApplicationCacheNamespace entries.
     */
  /* void addNamespaces (in nsIArray namespaces); */
  NS_SCRIPTABLE NS_IMETHOD AddNamespaces(nsIArray *namespaces) = 0;

  /**
     * Get the most specific namespace matching a given key.
     */
  /* nsIApplicationCacheNamespace getMatchingNamespace (in ACString key); */
  NS_SCRIPTABLE NS_IMETHOD GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationCache, NS_IAPPLICATIONCACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONCACHE \
  NS_SCRIPTABLE NS_IMETHOD GetGroupID(nsACString & aGroupID); \
  NS_SCRIPTABLE NS_IMETHOD GetClientID(nsACString & aClientID); \
  NS_SCRIPTABLE NS_IMETHOD GetActive(PRBool *aActive); \
  NS_SCRIPTABLE NS_IMETHOD GetUsage(PRUint32 *aUsage); \
  NS_SCRIPTABLE NS_IMETHOD Activate(void); \
  NS_SCRIPTABLE NS_IMETHOD Discard(void); \
  NS_SCRIPTABLE NS_IMETHOD MarkEntry(const nsACString & key, PRUint32 typeBits); \
  NS_SCRIPTABLE NS_IMETHOD UnmarkEntry(const nsACString & key, PRUint32 typeBits); \
  NS_SCRIPTABLE NS_IMETHOD GetTypes(const nsACString & key, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GatherEntries(PRUint32 typeBits, PRUint32 *count NS_OUTPARAM, char ***keys NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddNamespaces(nsIArray *namespaces); \
  NS_SCRIPTABLE NS_IMETHOD GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONCACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGroupID(nsACString & aGroupID) { return _to GetGroupID(aGroupID); } \
  NS_SCRIPTABLE NS_IMETHOD GetClientID(nsACString & aClientID) { return _to GetClientID(aClientID); } \
  NS_SCRIPTABLE NS_IMETHOD GetActive(PRBool *aActive) { return _to GetActive(aActive); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsage(PRUint32 *aUsage) { return _to GetUsage(aUsage); } \
  NS_SCRIPTABLE NS_IMETHOD Activate(void) { return _to Activate(); } \
  NS_SCRIPTABLE NS_IMETHOD Discard(void) { return _to Discard(); } \
  NS_SCRIPTABLE NS_IMETHOD MarkEntry(const nsACString & key, PRUint32 typeBits) { return _to MarkEntry(key, typeBits); } \
  NS_SCRIPTABLE NS_IMETHOD UnmarkEntry(const nsACString & key, PRUint32 typeBits) { return _to UnmarkEntry(key, typeBits); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypes(const nsACString & key, PRUint32 *_retval NS_OUTPARAM) { return _to GetTypes(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GatherEntries(PRUint32 typeBits, PRUint32 *count NS_OUTPARAM, char ***keys NS_OUTPARAM) { return _to GatherEntries(typeBits, count, keys); } \
  NS_SCRIPTABLE NS_IMETHOD AddNamespaces(nsIArray *namespaces) { return _to AddNamespaces(namespaces); } \
  NS_SCRIPTABLE NS_IMETHOD GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace **_retval NS_OUTPARAM) { return _to GetMatchingNamespace(key, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONCACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGroupID(nsACString & aGroupID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGroupID(aGroupID); } \
  NS_SCRIPTABLE NS_IMETHOD GetClientID(nsACString & aClientID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientID(aClientID); } \
  NS_SCRIPTABLE NS_IMETHOD GetActive(PRBool *aActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActive(aActive); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsage(PRUint32 *aUsage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsage(aUsage); } \
  NS_SCRIPTABLE NS_IMETHOD Activate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Activate(); } \
  NS_SCRIPTABLE NS_IMETHOD Discard(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Discard(); } \
  NS_SCRIPTABLE NS_IMETHOD MarkEntry(const nsACString & key, PRUint32 typeBits) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkEntry(key, typeBits); } \
  NS_SCRIPTABLE NS_IMETHOD UnmarkEntry(const nsACString & key, PRUint32 typeBits) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnmarkEntry(key, typeBits); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypes(const nsACString & key, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypes(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GatherEntries(PRUint32 typeBits, PRUint32 *count NS_OUTPARAM, char ***keys NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GatherEntries(typeBits, count, keys); } \
  NS_SCRIPTABLE NS_IMETHOD AddNamespaces(nsIArray *namespaces) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddNamespaces(namespaces); } \
  NS_SCRIPTABLE NS_IMETHOD GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatchingNamespace(key, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationCache : public nsIApplicationCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONCACHE

  nsApplicationCache();

private:
  ~nsApplicationCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationCache, nsIApplicationCache)

nsApplicationCache::nsApplicationCache()
{
  /* member initializers and constructor code */
}

nsApplicationCache::~nsApplicationCache()
{
  /* destructor code */
}

/* readonly attribute ACString groupID; */
NS_IMETHODIMP nsApplicationCache::GetGroupID(nsACString & aGroupID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString clientID; */
NS_IMETHODIMP nsApplicationCache::GetClientID(nsACString & aClientID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean active; */
NS_IMETHODIMP nsApplicationCache::GetActive(PRBool *aActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long usage; */
NS_IMETHODIMP nsApplicationCache::GetUsage(PRUint32 *aUsage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activate (); */
NS_IMETHODIMP nsApplicationCache::Activate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void discard (); */
NS_IMETHODIMP nsApplicationCache::Discard()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markEntry (in ACString key, in unsigned long typeBits); */
NS_IMETHODIMP nsApplicationCache::MarkEntry(const nsACString & key, PRUint32 typeBits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unmarkEntry (in ACString key, in unsigned long typeBits); */
NS_IMETHODIMP nsApplicationCache::UnmarkEntry(const nsACString & key, PRUint32 typeBits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getTypes (in ACString key); */
NS_IMETHODIMP nsApplicationCache::GetTypes(const nsACString & key, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void gatherEntries (in PRUint32 typeBits, out unsigned long count, [array, size_is (count)] out string keys); */
NS_IMETHODIMP nsApplicationCache::GatherEntries(PRUint32 typeBits, PRUint32 *count NS_OUTPARAM, char ***keys NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addNamespaces (in nsIArray namespaces); */
NS_IMETHODIMP nsApplicationCache::AddNamespaces(nsIArray *namespaces)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCacheNamespace getMatchingNamespace (in ACString key); */
NS_IMETHODIMP nsApplicationCache::GetMatchingNamespace(const nsACString & key, nsIApplicationCacheNamespace **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIApplicationCache_h__ */
