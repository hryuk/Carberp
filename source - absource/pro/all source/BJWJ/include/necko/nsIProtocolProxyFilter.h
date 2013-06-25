/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIProtocolProxyFilter.idl
 */

#ifndef __gen_nsIProtocolProxyFilter_h__
#define __gen_nsIProtocolProxyFilter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIProtocolProxyService; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIProtocolProxyFilter */
#define NS_IPROTOCOLPROXYFILTER_IID_STR "f424abd3-32b4-456c-9f45-b7e3376cb0d1"

#define NS_IPROTOCOLPROXYFILTER_IID \
  {0xf424abd3, 0x32b4, 0x456c, \
    { 0x9f, 0x45, 0xb7, 0xe3, 0x37, 0x6c, 0xb0, 0xd1 }}

/**
 * This interface is used to apply filters to the proxies selected for a given
 * URI.  Use nsIProtocolProxyService::registerFilter to hook up instances of
 * this interface.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIProtocolProxyFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLPROXYFILTER_IID)

  /**
   * This method is called to apply proxy filter rules for the given URI
   * and proxy object (or list of proxy objects).
   *
   * @param aProxyService
   *        A reference to the Protocol Proxy Service.  This is passed so that
   *        implementations may easily access methods such as newProxyInfo.
   * @param aURI
   *        The URI for which these proxy settings apply.
   * @param aProxy
   *        The proxy (or list of proxies) that would be used by default for
   *        the given URI.  This may be null.
   *
   * @return The proxy (or list of proxies) that should be used in place of
   *         aProxy.  This can be just be aProxy if the filter chooses not to
   *         modify the proxy.  It can also be null to indicate that a direct
   *         connection should be used.  Use aProxyService.newProxyInfo to
   *         construct nsIProxyInfo objects.
   */
  /* nsIProxyInfo applyFilter (in nsIProtocolProxyService aProxyService, in nsIURI aURI, in nsIProxyInfo aProxy); */
  NS_SCRIPTABLE NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolProxyFilter, NS_IPROTOCOLPROXYFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLPROXYFILTER \
  NS_SCRIPTABLE NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLPROXYFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo **_retval NS_OUTPARAM) { return _to ApplyFilter(aProxyService, aURI, aProxy, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLPROXYFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplyFilter(aProxyService, aURI, aProxy, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolProxyFilter : public nsIProtocolProxyFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLPROXYFILTER

  nsProtocolProxyFilter();

private:
  ~nsProtocolProxyFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProtocolProxyFilter, nsIProtocolProxyFilter)

nsProtocolProxyFilter::nsProtocolProxyFilter()
{
  /* member initializers and constructor code */
}

nsProtocolProxyFilter::~nsProtocolProxyFilter()
{
  /* destructor code */
}

/* nsIProxyInfo applyFilter (in nsIProtocolProxyService aProxyService, in nsIURI aURI, in nsIProxyInfo aProxy); */
NS_IMETHODIMP nsProtocolProxyFilter::ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProtocolProxyFilter_h__ */
