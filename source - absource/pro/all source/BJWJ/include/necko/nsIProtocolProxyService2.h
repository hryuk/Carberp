/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIProtocolProxyService2.idl
 */

#ifndef __gen_nsIProtocolProxyService2_h__
#define __gen_nsIProtocolProxyService2_h__


#ifndef __gen_nsIProtocolProxyService_h__
#include "nsIProtocolProxyService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIProtocolProxyService2 */
#define NS_IPROTOCOLPROXYSERVICE2_IID_STR "dbd9565d-29b1-437a-bff5-2fc339e2c5df"

#define NS_IPROTOCOLPROXYSERVICE2_IID \
  {0xdbd9565d, 0x29b1, 0x437a, \
    { 0xbf, 0xf5, 0x2f, 0xc3, 0x39, 0xe2, 0xc5, 0xdf }}

/**
 * An extension of nsIProtocolProxyService
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIProtocolProxyService2 : public nsIProtocolProxyService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLPROXYSERVICE2_IID)

  /**
   * Call this method to cause the PAC file (if any is configured) to be
   * reloaded.  The PAC file is loaded asynchronously.
   */
  /* void reloadPAC (); */
  NS_SCRIPTABLE NS_IMETHOD ReloadPAC(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolProxyService2, NS_IPROTOCOLPROXYSERVICE2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLPROXYSERVICE2 \
  NS_SCRIPTABLE NS_IMETHOD ReloadPAC(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLPROXYSERVICE2(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReloadPAC(void) { return _to ReloadPAC(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLPROXYSERVICE2(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReloadPAC(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadPAC(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolProxyService2 : public nsIProtocolProxyService2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLPROXYSERVICE2

  nsProtocolProxyService2();

private:
  ~nsProtocolProxyService2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProtocolProxyService2, nsIProtocolProxyService2)

nsProtocolProxyService2::nsProtocolProxyService2()
{
  /* member initializers and constructor code */
}

nsProtocolProxyService2::~nsProtocolProxyService2()
{
  /* destructor code */
}

/* void reloadPAC (); */
NS_IMETHODIMP nsProtocolProxyService2::ReloadPAC()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProtocolProxyService2_h__ */
