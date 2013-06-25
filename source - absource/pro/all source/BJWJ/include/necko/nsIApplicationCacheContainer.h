/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIApplicationCacheContainer.idl
 */

#ifndef __gen_nsIApplicationCacheContainer_h__
#define __gen_nsIApplicationCacheContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIApplicationCache; /* forward declaration */


/* starting interface:    nsIApplicationCacheContainer */
#define NS_IAPPLICATIONCACHECONTAINER_IID_STR "bbb80700-1f7f-4258-aff4-1743cc5a7d23"

#define NS_IAPPLICATIONCACHECONTAINER_IID \
  {0xbbb80700, 0x1f7f, 0x4258, \
    { 0xaf, 0xf4, 0x17, 0x43, 0xcc, 0x5a, 0x7d, 0x23 }}

/**
 * Interface used by objects that can be associated with an
 * application cache.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIApplicationCacheContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONCACHECONTAINER_IID)

  /* attribute nsIApplicationCache applicationCache; */
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(nsIApplicationCache * *aApplicationCache) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetApplicationCache(nsIApplicationCache * aApplicationCache) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationCacheContainer, NS_IAPPLICATIONCACHECONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONCACHECONTAINER \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(nsIApplicationCache * *aApplicationCache); \
  NS_SCRIPTABLE NS_IMETHOD SetApplicationCache(nsIApplicationCache * aApplicationCache); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONCACHECONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(nsIApplicationCache * *aApplicationCache) { return _to GetApplicationCache(aApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD SetApplicationCache(nsIApplicationCache * aApplicationCache) { return _to SetApplicationCache(aApplicationCache); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONCACHECONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(nsIApplicationCache * *aApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationCache(aApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD SetApplicationCache(nsIApplicationCache * aApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetApplicationCache(aApplicationCache); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationCacheContainer : public nsIApplicationCacheContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONCACHECONTAINER

  nsApplicationCacheContainer();

private:
  ~nsApplicationCacheContainer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationCacheContainer, nsIApplicationCacheContainer)

nsApplicationCacheContainer::nsApplicationCacheContainer()
{
  /* member initializers and constructor code */
}

nsApplicationCacheContainer::~nsApplicationCacheContainer()
{
  /* destructor code */
}

/* attribute nsIApplicationCache applicationCache; */
NS_IMETHODIMP nsApplicationCacheContainer::GetApplicationCache(nsIApplicationCache * *aApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationCacheContainer::SetApplicationCache(nsIApplicationCache * aApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIApplicationCacheContainer_h__ */
