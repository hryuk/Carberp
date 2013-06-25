/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIApplicationCacheChannel.idl
 */

#ifndef __gen_nsIApplicationCacheChannel_h__
#define __gen_nsIApplicationCacheChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIApplicationCacheContainer_h__
#include "nsIApplicationCacheContainer.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIApplicationCacheChannel */
#define NS_IAPPLICATIONCACHECHANNEL_IID_STR "9acfd21c-9c07-459f-8dae-ed2ffba23ddc"

#define NS_IAPPLICATIONCACHECHANNEL_IID \
  {0x9acfd21c, 0x9c07, 0x459f, \
    { 0x8d, 0xae, 0xed, 0x2f, 0xfb, 0xa2, 0x3d, 0xdc }}

/**
 * Interface implemented by channels that support application caches.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIApplicationCacheChannel : public nsIApplicationCacheContainer {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONCACHECHANNEL_IID)

  /**
     * TRUE when the resource came from the application cache. This
     * might be false even there is assigned an application cache
     * e.g. in case of fallback of load of an entry matching bypass
     * namespace.
     */
  /* readonly attribute PRBool loadedFromApplicationCache; */
  NS_SCRIPTABLE NS_IMETHOD GetLoadedFromApplicationCache(PRBool *aLoadedFromApplicationCache) = 0;

  /**
     * When true, the channel will ask its notification callbacks for
     * an application cache if one is not explicitly provided.  Default
     * value is true.
     *
     * NS_ERROR_ALREADY_OPENED will be thrown if set after AsyncOpen()
     * is called.
     */
  /* attribute boolean inheritApplicationCache; */
  NS_SCRIPTABLE NS_IMETHOD GetInheritApplicationCache(PRBool *aInheritApplicationCache) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInheritApplicationCache(PRBool aInheritApplicationCache) = 0;

  /**
     * When true, the channel will choose an application cache if one
     * was not explicitly provided and none is available from the
     * notification callbacks.  Default value is false.
     *
     * This attribute will not be transferred through a redirect.
     *
     * NS_ERROR_ALREADY_OPENED will be thrown if set after AsyncOpen()
     * is called.
     */
  /* attribute boolean chooseApplicationCache; */
  NS_SCRIPTABLE NS_IMETHOD GetChooseApplicationCache(PRBool *aChooseApplicationCache) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetChooseApplicationCache(PRBool aChooseApplicationCache) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationCacheChannel, NS_IAPPLICATIONCACHECHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONCACHECHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetLoadedFromApplicationCache(PRBool *aLoadedFromApplicationCache); \
  NS_SCRIPTABLE NS_IMETHOD GetInheritApplicationCache(PRBool *aInheritApplicationCache); \
  NS_SCRIPTABLE NS_IMETHOD SetInheritApplicationCache(PRBool aInheritApplicationCache); \
  NS_SCRIPTABLE NS_IMETHOD GetChooseApplicationCache(PRBool *aChooseApplicationCache); \
  NS_SCRIPTABLE NS_IMETHOD SetChooseApplicationCache(PRBool aChooseApplicationCache); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONCACHECHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLoadedFromApplicationCache(PRBool *aLoadedFromApplicationCache) { return _to GetLoadedFromApplicationCache(aLoadedFromApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD GetInheritApplicationCache(PRBool *aInheritApplicationCache) { return _to GetInheritApplicationCache(aInheritApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD SetInheritApplicationCache(PRBool aInheritApplicationCache) { return _to SetInheritApplicationCache(aInheritApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD GetChooseApplicationCache(PRBool *aChooseApplicationCache) { return _to GetChooseApplicationCache(aChooseApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD SetChooseApplicationCache(PRBool aChooseApplicationCache) { return _to SetChooseApplicationCache(aChooseApplicationCache); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONCACHECHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLoadedFromApplicationCache(PRBool *aLoadedFromApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadedFromApplicationCache(aLoadedFromApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD GetInheritApplicationCache(PRBool *aInheritApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInheritApplicationCache(aInheritApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD SetInheritApplicationCache(PRBool aInheritApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInheritApplicationCache(aInheritApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD GetChooseApplicationCache(PRBool *aChooseApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChooseApplicationCache(aChooseApplicationCache); } \
  NS_SCRIPTABLE NS_IMETHOD SetChooseApplicationCache(PRBool aChooseApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChooseApplicationCache(aChooseApplicationCache); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationCacheChannel : public nsIApplicationCacheChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONCACHECHANNEL

  nsApplicationCacheChannel();

private:
  ~nsApplicationCacheChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationCacheChannel, nsIApplicationCacheChannel)

nsApplicationCacheChannel::nsApplicationCacheChannel()
{
  /* member initializers and constructor code */
}

nsApplicationCacheChannel::~nsApplicationCacheChannel()
{
  /* destructor code */
}

/* readonly attribute PRBool loadedFromApplicationCache; */
NS_IMETHODIMP nsApplicationCacheChannel::GetLoadedFromApplicationCache(PRBool *aLoadedFromApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean inheritApplicationCache; */
NS_IMETHODIMP nsApplicationCacheChannel::GetInheritApplicationCache(PRBool *aInheritApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationCacheChannel::SetInheritApplicationCache(PRBool aInheritApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean chooseApplicationCache; */
NS_IMETHODIMP nsApplicationCacheChannel::GetChooseApplicationCache(PRBool *aChooseApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationCacheChannel::SetChooseApplicationCache(PRBool aChooseApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIApplicationCacheChannel_h__ */
