/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/cache/public/nsICacheListener.idl
 */

#ifndef __gen_nsICacheListener_h__
#define __gen_nsICacheListener_h__


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


/* starting interface:    nsICacheListener */
#define NS_ICACHELISTENER_IID_STR "638c3848-778b-4851-8ff3-9400f65b8773"

#define NS_ICACHELISTENER_IID \
  {0x638c3848, 0x778b, 0x4851, \
    { 0x8f, 0xf3, 0x94, 0x00, 0xf6, 0x5b, 0x87, 0x73 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICacheListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHELISTENER_IID)

  /**
     * Called when the requested access (or appropriate subset) is
     * acquired.  The status parameter equals NS_OK on success.
     * See nsICacheService.idl for accessGranted values.
     */
  /* void onCacheEntryAvailable (in nsICacheEntryDescriptor descriptor, in nsCacheAccessMode accessGranted, in nsresult status); */
  NS_SCRIPTABLE NS_IMETHOD OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheListener, NS_ICACHELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHELISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status) { return _to OnCacheEntryAvailable(descriptor, accessGranted, status); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryAvailable(descriptor, accessGranted, status); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheListener : public nsICacheListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHELISTENER

  nsCacheListener();

private:
  ~nsCacheListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheListener, nsICacheListener)

nsCacheListener::nsCacheListener()
{
  /* member initializers and constructor code */
}

nsCacheListener::~nsCacheListener()
{
  /* destructor code */
}

/* void onCacheEntryAvailable (in nsICacheEntryDescriptor descriptor, in nsCacheAccessMode accessGranted, in nsresult status); */
NS_IMETHODIMP nsCacheListener::OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheListener_h__ */
