/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/dns/public/nsIEffectiveTLDService.idl
 */

#ifndef __gen_nsIEffectiveTLDService_h__
#define __gen_nsIEffectiveTLDService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIEffectiveTLDService */
#define NS_IEFFECTIVETLDSERVICE_IID_STR "6852369e-baa9-4c9a-bbcd-5123fc54a297"

#define NS_IEFFECTIVETLDSERVICE_IID \
  {0x6852369e, 0xbaa9, 0x4c9a, \
    { 0xbb, 0xcd, 0x51, 0x23, 0xfc, 0x54, 0xa2, 0x97 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIEffectiveTLDService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEFFECTIVETLDSERVICE_IID)

  /**
     * Returns the public suffix of a URI. A public suffix is the highest-level domain
     * under which individual domains may be registered; it may therefore contain one
     * or more dots. For example, the public suffix for "www.bbc.co.uk" is "co.uk",
     * because the .uk TLD does not allow the registration of domains at the
     * second level ("bbc.uk" is forbidden).
     *
     * The public suffix will be returned encoded in ASCII/ACE and will be normalized
     * according to RFC 3454, i.e. the same encoding returned by nsIURI::GetAsciiHost().
     * If consumers wish to compare the result of this method against the host from
     * another nsIURI, the host should be obtained using nsIURI::GetAsciiHost().
     * In the case of nested URIs, the innermost URI will be used.
     *
     * @param   aURI   The URI to be analyzed
     *
     * @returns the public suffix
     *
     * @throws NS_ERROR_UNEXPECTED 
     *         or other error returned by nsIIDNService::normalize when 
     *         the hostname contains characters disallowed in URIs
     * @throws NS_ERROR_HOST_IS_IP_ADDRESS
     *         if the host is a numeric IPv4 or IPv6 address (as determined by
     *         the success of a call to PR_StringToNetAddr()).
     */
  /* ACString getPublicSuffix (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetPublicSuffix(nsIURI *aURI, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Returns the base domain of a URI; that is, the public suffix with a given
     * number of additional domain name parts. For example, the result of this method
     * for "www.bbc.co.uk", depending on the value of aAdditionalParts parameter, will
     * be:
     *
     *    0 (default) -> bbc.co.uk
     *    1           -> www.bbc.co.uk
     *
     * Similarly, the public suffix for "www.developer.mozilla.org" is "org", and the base
     * domain will be:
     *
     *    0 (default) -> mozilla.org
     *    1           -> developer.mozilla.org
     *    2           -> www.developer.mozilla.org
     *
     * The base domain will be returned encoded in ASCII/ACE and will be normalized
     * according to RFC 3454, i.e. the same encoding returned by nsIURI::GetAsciiHost().
     * If consumers wish to compare the result of this method against the host from
     * another nsIURI, the host should be obtained using nsIURI::GetAsciiHost().
     * In the case of nested URIs, the innermost URI will be used.
     *
     * @param   aURI               The URI to be analyzed
     * @param   aAdditionalParts   Number of domain name parts to be
     *                             returned in addition to the public suffix
     *
     * @returns the base domain (public suffix plus the requested number of additional parts)
     *
     * @throws NS_ERROR_UNEXPECTED 
     *         or other error returned by nsIIDNService::normalize when 
     *         the hostname contains characters disallowed in URIs
     * @throws NS_ERROR_INSUFFICIENT_DOMAIN_LEVELS
     *         when there are insufficient subdomain levels in the hostname to satisfy the
     *         requested aAdditionalParts value.
     * @throws NS_ERROR_HOST_IS_IP_ADDRESS
     *         if aHost is a numeric IPv4 or IPv6 address (as determined by
     *         the success of a call to PR_StringToNetAddr()).
     *
     * @see    getPublicSuffix()
     */
  /* ACString getBaseDomain (in nsIURI aURI, [optional] in PRUint32 aAdditionalParts); */
  NS_SCRIPTABLE NS_IMETHOD GetBaseDomain(nsIURI *aURI, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * NOTE: It is strongly recommended to use getPublicSuffix() above if a suitable
     * nsIURI is available. Only use this method if this is not the case.
     *
     * Returns the public suffix of a host string. Otherwise identical to getPublicSuffix().
     *
     * @param   aHost   The host to be analyzed. Any additional parts (e.g. scheme,
     *                  port, or path) will cause this method to throw. ASCII/ACE and
     *                  UTF8 encodings are acceptable as input; normalization will
     *                  be performed as specified in getBaseDomain().
     *
     * @see     getPublicSuffix()
     */
  /* ACString getPublicSuffixFromHost (in AUTF8String aHost); */
  NS_SCRIPTABLE NS_IMETHOD GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * NOTE: It is strongly recommended to use getBaseDomain() above if a suitable
     * nsIURI is available. Only use this method if this is not the case.
     *
     * Returns the base domain of a host string. Otherwise identical to getBaseDomain().
     *
     * @param   aHost   The host to be analyzed. Any additional parts (e.g. scheme,
     *                  port, or path) will cause this method to throw. ASCII/ACE and
     *                  UTF8 encodings are acceptable as input; normalization will
     *                  be performed as specified in getBaseDomain().
     *
     * @see     getBaseDomain()
     */
  /* ACString getBaseDomainFromHost (in AUTF8String aHost, [optional] in PRUint32 aAdditionalParts); */
  NS_SCRIPTABLE NS_IMETHOD GetBaseDomainFromHost(const nsACString & aHost, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEffectiveTLDService, NS_IEFFECTIVETLDSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEFFECTIVETLDSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetPublicSuffix(nsIURI *aURI, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBaseDomain(nsIURI *aURI, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBaseDomainFromHost(const nsACString & aHost, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEFFECTIVETLDSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPublicSuffix(nsIURI *aURI, nsACString & _retval NS_OUTPARAM) { return _to GetPublicSuffix(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseDomain(nsIURI *aURI, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM) { return _to GetBaseDomain(aURI, aAdditionalParts, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval NS_OUTPARAM) { return _to GetPublicSuffixFromHost(aHost, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseDomainFromHost(const nsACString & aHost, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM) { return _to GetBaseDomainFromHost(aHost, aAdditionalParts, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEFFECTIVETLDSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPublicSuffix(nsIURI *aURI, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublicSuffix(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseDomain(nsIURI *aURI, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseDomain(aURI, aAdditionalParts, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublicSuffixFromHost(aHost, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseDomainFromHost(const nsACString & aHost, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseDomainFromHost(aHost, aAdditionalParts, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEffectiveTLDService : public nsIEffectiveTLDService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEFFECTIVETLDSERVICE

  nsEffectiveTLDService();

private:
  ~nsEffectiveTLDService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEffectiveTLDService, nsIEffectiveTLDService)

nsEffectiveTLDService::nsEffectiveTLDService()
{
  /* member initializers and constructor code */
}

nsEffectiveTLDService::~nsEffectiveTLDService()
{
  /* destructor code */
}

/* ACString getPublicSuffix (in nsIURI aURI); */
NS_IMETHODIMP nsEffectiveTLDService::GetPublicSuffix(nsIURI *aURI, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getBaseDomain (in nsIURI aURI, [optional] in PRUint32 aAdditionalParts); */
NS_IMETHODIMP nsEffectiveTLDService::GetBaseDomain(nsIURI *aURI, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getPublicSuffixFromHost (in AUTF8String aHost); */
NS_IMETHODIMP nsEffectiveTLDService::GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getBaseDomainFromHost (in AUTF8String aHost, [optional] in PRUint32 aAdditionalParts); */
NS_IMETHODIMP nsEffectiveTLDService::GetBaseDomainFromHost(const nsACString & aHost, PRUint32 aAdditionalParts, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEffectiveTLDService_h__ */
