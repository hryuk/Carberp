/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/dns/public/nsIDNSService.idl
 */

#ifndef __gen_nsIDNSService_h__
#define __gen_nsIDNSService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICancelable; /* forward declaration */

class nsIEventTarget; /* forward declaration */

class nsIDNSRecord; /* forward declaration */

class nsIDNSListener; /* forward declaration */


/* starting interface:    nsIDNSService */
#define NS_IDNSSERVICE_IID_STR "c1a56a45-8fa3-44e6-9f01-38c91c858cf9"

#define NS_IDNSSERVICE_IID \
  {0xc1a56a45, 0x8fa3, 0x44e6, \
    { 0x9f, 0x01, 0x38, 0xc9, 0x1c, 0x85, 0x8c, 0xf9 }}

/**
 * nsIDNSService
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDNSService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSSERVICE_IID)

  /**
     * kicks off an asynchronous host lookup.
     *
     * @param aHostName
     *        the hostname or IP-address-literal to resolve.
     * @param aFlags
     *        a bitwise OR of the RESOLVE_ prefixed constants defined below.
     * @param aListener
     *        the listener to be notified when the result is available.
     * @param aListenerTarget
     *        optional parameter (may be null).  if non-null, this parameter
     *        specifies the nsIEventTarget of the thread on which the
     *        listener's onLookupComplete should be called.  however, if this
     *        parameter is null, then onLookupComplete will be called on an
     *        unspecified thread (possibly recursively).
     *
     * @return An object that can be used to cancel the host lookup.
     */
  /* nsICancelable asyncResolve (in AUTF8String aHostName, in unsigned long aFlags, in nsIDNSListener aListener, in nsIEventTarget aListenerTarget); */
  NS_SCRIPTABLE NS_IMETHOD AsyncResolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable **_retval NS_OUTPARAM) = 0;

  /**
     * called to synchronously resolve a hostname.  warning this method may
     * block the calling thread for a long period of time.  it is extremely
     * unwise to call this function on the UI thread of an application.
     *
     * @param aHostName
     *        the hostname or IP-address-literal to resolve.
     * @param aFlags
     *        a bitwise OR of the RESOLVE_ prefixed constants defined below.
     *
     * @return DNS record corresponding to the given hostname.
     * @throws NS_ERROR_UNKNOWN_HOST if host could not be resolved.
     */
  /* nsIDNSRecord resolve (in AUTF8String aHostName, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD Resolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSRecord **_retval NS_OUTPARAM) = 0;

  /**
     * @return the hostname of the operating system.
     */
  /* readonly attribute AUTF8String myHostName; */
  NS_SCRIPTABLE NS_IMETHOD GetMyHostName(nsACString & aMyHostName) = 0;

  /*************************************************************************
     * Listed below are the various flags that may be OR'd together to form
     * the aFlags parameter passed to asyncResolve() and resolve().
     */
/**
     * if set, this flag suppresses the internal DNS lookup cache.
     */
  enum { RESOLVE_BYPASS_CACHE = 1U };

  /**
     * if set, the canonical name of the specified host will be queried.
     */
  enum { RESOLVE_CANONICAL_NAME = 2U };

  /**
     * if set, the query is given lower priority. Medium takes precedence
     * if both are used.
     */
  enum { RESOLVE_PRIORITY_MEDIUM = 4U };

  enum { RESOLVE_PRIORITY_LOW = 8U };

  /**
     * if set, indicates request is speculative. Speculative requests 
     * return errors if prefetching is disabled by configuration.
     */
  enum { RESOLVE_SPECULATE = 16U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSService, NS_IDNSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSSERVICE \
  NS_SCRIPTABLE NS_IMETHOD AsyncResolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Resolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSRecord **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMyHostName(nsACString & aMyHostName); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD AsyncResolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable **_retval NS_OUTPARAM) { return _to AsyncResolve(aHostName, aFlags, aListener, aListenerTarget, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Resolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSRecord **_retval NS_OUTPARAM) { return _to Resolve(aHostName, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMyHostName(nsACString & aMyHostName) { return _to GetMyHostName(aMyHostName); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD AsyncResolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncResolve(aHostName, aFlags, aListener, aListenerTarget, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Resolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSRecord **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Resolve(aHostName, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMyHostName(nsACString & aMyHostName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMyHostName(aMyHostName); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSService : public nsIDNSService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSSERVICE

  nsDNSService();

private:
  ~nsDNSService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDNSService, nsIDNSService)

nsDNSService::nsDNSService()
{
  /* member initializers and constructor code */
}

nsDNSService::~nsDNSService()
{
  /* destructor code */
}

/* nsICancelable asyncResolve (in AUTF8String aHostName, in unsigned long aFlags, in nsIDNSListener aListener, in nsIEventTarget aListenerTarget); */
NS_IMETHODIMP nsDNSService::AsyncResolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDNSRecord resolve (in AUTF8String aHostName, in unsigned long aFlags); */
NS_IMETHODIMP nsDNSService::Resolve(const nsACString & aHostName, PRUint32 aFlags, nsIDNSRecord **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String myHostName; */
NS_IMETHODIMP nsDNSService::GetMyHostName(nsACString & aMyHostName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDNSService_h__ */
