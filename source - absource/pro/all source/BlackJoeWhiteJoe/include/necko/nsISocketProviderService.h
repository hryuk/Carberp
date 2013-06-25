/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/socket/base/nsISocketProviderService.idl
 */

#ifndef __gen_nsISocketProviderService_h__
#define __gen_nsISocketProviderService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISocketProvider; /* forward declaration */


/* starting interface:    nsISocketProviderService */
#define NS_ISOCKETPROVIDERSERVICE_IID_STR "8f8a23d0-5472-11d3-bbc8-0000861d1237"

#define NS_ISOCKETPROVIDERSERVICE_IID \
  {0x8f8a23d0, 0x5472, 0x11d3, \
    { 0xbb, 0xc8, 0x00, 0x00, 0x86, 0x1d, 0x12, 0x37 }}

/**
 * nsISocketProviderService
 *
 * Provides a mapping between a socket type and its associated socket provider
 * instance.  One could also use the service manager directly.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISocketProviderService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOCKETPROVIDERSERVICE_IID)

  /* nsISocketProvider getSocketProvider (in string socketType); */
  NS_SCRIPTABLE NS_IMETHOD GetSocketProvider(const char *socketType, nsISocketProvider **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISocketProviderService, NS_ISOCKETPROVIDERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOCKETPROVIDERSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetSocketProvider(const char *socketType, nsISocketProvider **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOCKETPROVIDERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSocketProvider(const char *socketType, nsISocketProvider **_retval NS_OUTPARAM) { return _to GetSocketProvider(socketType, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOCKETPROVIDERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSocketProvider(const char *socketType, nsISocketProvider **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSocketProvider(socketType, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSocketProviderService : public nsISocketProviderService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOCKETPROVIDERSERVICE

  nsSocketProviderService();

private:
  ~nsSocketProviderService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSocketProviderService, nsISocketProviderService)

nsSocketProviderService::nsSocketProviderService()
{
  /* member initializers and constructor code */
}

nsSocketProviderService::~nsSocketProviderService()
{
  /* destructor code */
}

/* nsISocketProvider getSocketProvider (in string socketType); */
NS_IMETHODIMP nsSocketProviderService::GetSocketProvider(const char *socketType, nsISocketProvider **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISocketProviderService_h__ */
