/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIApplicationCacheService.idl
 */

#ifndef __gen_nsIApplicationCacheService_h__
#define __gen_nsIApplicationCacheService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIApplicationCache; /* forward declaration */


/* starting interface:    nsIApplicationCacheService */
#define NS_IAPPLICATIONCACHESERVICE_IID_STR "611161c8-37d0-450f-a4fe-457c47bbaf64"

#define NS_IAPPLICATIONCACHESERVICE_IID \
  {0x611161c8, 0x37d0, 0x450f, \
    { 0xa4, 0xfe, 0x45, 0x7c, 0x47, 0xbb, 0xaf, 0x64 }}

/**
 * The application cache service manages the set of application cache
 * groups.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIApplicationCacheService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONCACHESERVICE_IID)

  /**
     * Create a new, empty application cache for the given cache
     * group.
     */
  /* nsIApplicationCache createApplicationCache (in ACString group); */
  NS_SCRIPTABLE NS_IMETHOD CreateApplicationCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM) = 0;

  /**
     * Get an application cache object for the given client ID.
     */
  /* nsIApplicationCache getApplicationCache (in ACString clientID); */
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(const nsACString & clientID, nsIApplicationCache **_retval NS_OUTPARAM) = 0;

  /**
     * Get the currently active cache object for a cache group.
     */
  /* nsIApplicationCache getActiveCache (in ACString group); */
  NS_SCRIPTABLE NS_IMETHOD GetActiveCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM) = 0;

  /**
     * Deactivate the currently-active cache object for a cache group.
     */
  /* void deactivateGroup (in ACString group); */
  NS_SCRIPTABLE NS_IMETHOD DeactivateGroup(const nsACString & group) = 0;

  /**
     * Try to find the best application cache to serve a resource.
     */
  /* nsIApplicationCache chooseApplicationCache (in ACString key); */
  NS_SCRIPTABLE NS_IMETHOD ChooseApplicationCache(const nsACString & key, nsIApplicationCache **_retval NS_OUTPARAM) = 0;

  /**
     * Flags the key as being opportunistically cached.
     *
     * This method should also propagate the entry to other
     * application caches with the same opportunistic namespace, but
     * this is not currently implemented.
     *
     * @param cache
     *        The cache in which the entry is cached now.
     * @param key
     *        The cache entry key.
     */
  /* void cacheOpportunistically (in nsIApplicationCache cache, in ACString key); */
  NS_SCRIPTABLE NS_IMETHOD CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key) = 0;

  /**
     * Get the list of application cache groups.
     */
  /* void getGroups (out unsigned long count, [array, size_is (count), retval] out string groupIDs); */
  NS_SCRIPTABLE NS_IMETHOD GetGroups(PRUint32 *count NS_OUTPARAM, char ***groupIDs NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationCacheService, NS_IAPPLICATIONCACHESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONCACHESERVICE \
  NS_SCRIPTABLE NS_IMETHOD CreateApplicationCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(const nsACString & clientID, nsIApplicationCache **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DeactivateGroup(const nsACString & group); \
  NS_SCRIPTABLE NS_IMETHOD ChooseApplicationCache(const nsACString & key, nsIApplicationCache **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key); \
  NS_SCRIPTABLE NS_IMETHOD GetGroups(PRUint32 *count NS_OUTPARAM, char ***groupIDs NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONCACHESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateApplicationCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM) { return _to CreateApplicationCache(group, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(const nsACString & clientID, nsIApplicationCache **_retval NS_OUTPARAM) { return _to GetApplicationCache(clientID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM) { return _to GetActiveCache(group, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeactivateGroup(const nsACString & group) { return _to DeactivateGroup(group); } \
  NS_SCRIPTABLE NS_IMETHOD ChooseApplicationCache(const nsACString & key, nsIApplicationCache **_retval NS_OUTPARAM) { return _to ChooseApplicationCache(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key) { return _to CacheOpportunistically(cache, key); } \
  NS_SCRIPTABLE NS_IMETHOD GetGroups(PRUint32 *count NS_OUTPARAM, char ***groupIDs NS_OUTPARAM) { return _to GetGroups(count, groupIDs); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONCACHESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateApplicationCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateApplicationCache(group, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(const nsACString & clientID, nsIApplicationCache **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationCache(clientID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveCache(group, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeactivateGroup(const nsACString & group) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeactivateGroup(group); } \
  NS_SCRIPTABLE NS_IMETHOD ChooseApplicationCache(const nsACString & key, nsIApplicationCache **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChooseApplicationCache(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key) { return !_to ? NS_ERROR_NULL_POINTER : _to->CacheOpportunistically(cache, key); } \
  NS_SCRIPTABLE NS_IMETHOD GetGroups(PRUint32 *count NS_OUTPARAM, char ***groupIDs NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGroups(count, groupIDs); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationCacheService : public nsIApplicationCacheService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONCACHESERVICE

  nsApplicationCacheService();

private:
  ~nsApplicationCacheService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationCacheService, nsIApplicationCacheService)

nsApplicationCacheService::nsApplicationCacheService()
{
  /* member initializers and constructor code */
}

nsApplicationCacheService::~nsApplicationCacheService()
{
  /* destructor code */
}

/* nsIApplicationCache createApplicationCache (in ACString group); */
NS_IMETHODIMP nsApplicationCacheService::CreateApplicationCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCache getApplicationCache (in ACString clientID); */
NS_IMETHODIMP nsApplicationCacheService::GetApplicationCache(const nsACString & clientID, nsIApplicationCache **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCache getActiveCache (in ACString group); */
NS_IMETHODIMP nsApplicationCacheService::GetActiveCache(const nsACString & group, nsIApplicationCache **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deactivateGroup (in ACString group); */
NS_IMETHODIMP nsApplicationCacheService::DeactivateGroup(const nsACString & group)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIApplicationCache chooseApplicationCache (in ACString key); */
NS_IMETHODIMP nsApplicationCacheService::ChooseApplicationCache(const nsACString & key, nsIApplicationCache **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cacheOpportunistically (in nsIApplicationCache cache, in ACString key); */
NS_IMETHODIMP nsApplicationCacheService::CacheOpportunistically(nsIApplicationCache *cache, const nsACString & key)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getGroups (out unsigned long count, [array, size_is (count), retval] out string groupIDs); */
NS_IMETHODIMP nsApplicationCacheService::GetGroups(PRUint32 *count NS_OUTPARAM, char ***groupIDs NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIApplicationCacheService_h__ */
