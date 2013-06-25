/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsINSSCertCache.idl
 */

#ifndef __gen_nsINSSCertCache_h__
#define __gen_nsINSSCertCache_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509CertList; /* forward declaration */


/* starting interface:    nsINSSCertCache */
#define NS_INSSCERTCACHE_IID_STR "1b75bdae-1757-4322-9d1e-cfcaa18cb710"

#define NS_INSSCERTCACHE_IID \
  {0x1b75bdae, 0x1757, 0x4322, \
    { 0x9d, 0x1e, 0xcf, 0xca, 0xa1, 0x8c, 0xb7, 0x10 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINSSCertCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INSSCERTCACHE_IID)

  /* void cacheAllCerts (); */
  NS_SCRIPTABLE NS_IMETHOD CacheAllCerts(void) = 0;

  /* void cacheCertList (in nsIX509CertList list); */
  NS_SCRIPTABLE NS_IMETHOD CacheCertList(nsIX509CertList *list) = 0;

  /* nsIX509CertList getX509CachedCerts (); */
  NS_SCRIPTABLE NS_IMETHOD GetX509CachedCerts(nsIX509CertList **_retval NS_OUTPARAM) = 0;

  /* [noscript, notxpcom] voidPtr getCachedCerts (); */
  NS_IMETHOD_(void *) GetCachedCerts(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINSSCertCache, NS_INSSCERTCACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINSSCERTCACHE \
  NS_SCRIPTABLE NS_IMETHOD CacheAllCerts(void); \
  NS_SCRIPTABLE NS_IMETHOD CacheCertList(nsIX509CertList *list); \
  NS_SCRIPTABLE NS_IMETHOD GetX509CachedCerts(nsIX509CertList **_retval NS_OUTPARAM); \
  NS_IMETHOD_(void *) GetCachedCerts(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINSSCERTCACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CacheAllCerts(void) { return _to CacheAllCerts(); } \
  NS_SCRIPTABLE NS_IMETHOD CacheCertList(nsIX509CertList *list) { return _to CacheCertList(list); } \
  NS_SCRIPTABLE NS_IMETHOD GetX509CachedCerts(nsIX509CertList **_retval NS_OUTPARAM) { return _to GetX509CachedCerts(_retval); } \
  NS_IMETHOD_(void *) GetCachedCerts(void) { return _to GetCachedCerts(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINSSCERTCACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CacheAllCerts(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CacheAllCerts(); } \
  NS_SCRIPTABLE NS_IMETHOD CacheCertList(nsIX509CertList *list) { return !_to ? NS_ERROR_NULL_POINTER : _to->CacheCertList(list); } \
  NS_SCRIPTABLE NS_IMETHOD GetX509CachedCerts(nsIX509CertList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX509CachedCerts(_retval); } \
  NS_IMETHOD_(void *) GetCachedCerts(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedCerts(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNSSCertCache : public nsINSSCertCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINSSCERTCACHE

  nsNSSCertCache();

private:
  ~nsNSSCertCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNSSCertCache, nsINSSCertCache)

nsNSSCertCache::nsNSSCertCache()
{
  /* member initializers and constructor code */
}

nsNSSCertCache::~nsNSSCertCache()
{
  /* destructor code */
}

/* void cacheAllCerts (); */
NS_IMETHODIMP nsNSSCertCache::CacheAllCerts()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cacheCertList (in nsIX509CertList list); */
NS_IMETHODIMP nsNSSCertCache::CacheCertList(nsIX509CertList *list)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509CertList getX509CachedCerts (); */
NS_IMETHODIMP nsNSSCertCache::GetX509CachedCerts(nsIX509CertList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] voidPtr getCachedCerts (); */
NS_IMETHODIMP_(void *) nsNSSCertCache::GetCachedCerts()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_NSSCERTCACHE_CID { /* 3f429a14-dffe-417d-8cb8-fdf09bacd09e */ \
    0x3f429a14,                                                          \
    0xdffe,                                                              \
    0x417d,                                                              \
    {0x8c, 0xb8, 0xfd, 0xf0, 0x9b, 0xac, 0xd0, 0x9e}                     \
  }
#define NS_NSSCERTCACHE_CONTRACTID "@mozilla.org/security/nsscertcache;1"

#endif /* __gen_nsINSSCertCache_h__ */
