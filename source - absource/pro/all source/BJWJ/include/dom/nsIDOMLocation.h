/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMLocation.idl
 */

#ifndef __gen_nsIDOMLocation_h__
#define __gen_nsIDOMLocation_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMLocation */
#define NS_IDOMLOCATION_IID_STR "a6cf906d-15b3-11d2-932e-00805f8add32"

#define NS_IDOMLOCATION_IID \
  {0xa6cf906d, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLocation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLOCATION_IID)

  /**
            * These properties refer to the current location of the document.
            * This will correspond to the URI shown in the location bar, which
            * can be different from the documentURI of the document.
            */
  /* attribute DOMString hash; */
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsAString & aHash) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHash(const nsAString & aHash) = 0;

  /* attribute DOMString host; */
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsAString & aHost) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHost(const nsAString & aHost) = 0;

  /* attribute DOMString hostname; */
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname) = 0;

  /* attribute DOMString href; */
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsAString & aHref) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHref(const nsAString & aHref) = 0;

  /* attribute DOMString pathname; */
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsAString & aPathname) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPathname(const nsAString & aPathname) = 0;

  /* attribute DOMString port; */
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsAString & aPort) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPort(const nsAString & aPort) = 0;

  /* attribute DOMString protocol; */
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsAString & aProtocol) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetProtocol(const nsAString & aProtocol) = 0;

  /* attribute DOMString search; */
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsAString & aSearch) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSearch(const nsAString & aSearch) = 0;

  /* void reload ([optional] in boolean forceget); */
  NS_SCRIPTABLE NS_IMETHOD Reload(PRBool forceget) = 0;

  /* void replace (in DOMString url); */
  NS_SCRIPTABLE NS_IMETHOD Replace(const nsAString & url) = 0;

  /* void assign (in DOMString url); */
  NS_SCRIPTABLE NS_IMETHOD Assign(const nsAString & url) = 0;

  /* DOMString toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLocation, NS_IDOMLOCATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLOCATION \
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsAString & aHash); \
  NS_SCRIPTABLE NS_IMETHOD SetHash(const nsAString & aHash); \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsAString & aHost); \
  NS_SCRIPTABLE NS_IMETHOD SetHost(const nsAString & aHost); \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname); \
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname); \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsAString & aHref); \
  NS_SCRIPTABLE NS_IMETHOD SetHref(const nsAString & aHref); \
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsAString & aPathname); \
  NS_SCRIPTABLE NS_IMETHOD SetPathname(const nsAString & aPathname); \
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsAString & aPort); \
  NS_SCRIPTABLE NS_IMETHOD SetPort(const nsAString & aPort); \
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsAString & aProtocol); \
  NS_SCRIPTABLE NS_IMETHOD SetProtocol(const nsAString & aProtocol); \
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsAString & aSearch); \
  NS_SCRIPTABLE NS_IMETHOD SetSearch(const nsAString & aSearch); \
  NS_SCRIPTABLE NS_IMETHOD Reload(PRBool forceget); \
  NS_SCRIPTABLE NS_IMETHOD Replace(const nsAString & url); \
  NS_SCRIPTABLE NS_IMETHOD Assign(const nsAString & url); \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsAString & aHash) { return _to GetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD SetHash(const nsAString & aHash) { return _to SetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsAString & aHost) { return _to GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD SetHost(const nsAString & aHost) { return _to SetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname) { return _to GetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname) { return _to SetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsAString & aHref) { return _to GetHref(aHref); } \
  NS_SCRIPTABLE NS_IMETHOD SetHref(const nsAString & aHref) { return _to SetHref(aHref); } \
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsAString & aPathname) { return _to GetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD SetPathname(const nsAString & aPathname) { return _to SetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsAString & aPort) { return _to GetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD SetPort(const nsAString & aPort) { return _to SetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsAString & aProtocol) { return _to GetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD SetProtocol(const nsAString & aProtocol) { return _to SetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsAString & aSearch) { return _to GetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearch(const nsAString & aSearch) { return _to SetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD Reload(PRBool forceget) { return _to Reload(forceget); } \
  NS_SCRIPTABLE NS_IMETHOD Replace(const nsAString & url) { return _to Replace(url); } \
  NS_SCRIPTABLE NS_IMETHOD Assign(const nsAString & url) { return _to Assign(url); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsAString & aHash) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD SetHash(const nsAString & aHash) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsAString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD SetHost(const nsAString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsAString & aHref) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } \
  NS_SCRIPTABLE NS_IMETHOD SetHref(const nsAString & aHref) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHref(aHref); } \
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsAString & aPathname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD SetPathname(const nsAString & aPathname) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsAString & aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD SetPort(const nsAString & aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsAString & aProtocol) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD SetProtocol(const nsAString & aProtocol) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsAString & aSearch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearch(const nsAString & aSearch) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD Reload(PRBool forceget) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reload(forceget); } \
  NS_SCRIPTABLE NS_IMETHOD Replace(const nsAString & url) { return !_to ? NS_ERROR_NULL_POINTER : _to->Replace(url); } \
  NS_SCRIPTABLE NS_IMETHOD Assign(const nsAString & url) { return !_to ? NS_ERROR_NULL_POINTER : _to->Assign(url); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLocation : public nsIDOMLocation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLOCATION

  nsDOMLocation();

private:
  ~nsDOMLocation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLocation, nsIDOMLocation)

nsDOMLocation::nsDOMLocation()
{
  /* member initializers and constructor code */
}

nsDOMLocation::~nsDOMLocation()
{
  /* destructor code */
}

/* attribute DOMString hash; */
NS_IMETHODIMP nsDOMLocation::GetHash(nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLocation::SetHash(const nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString host; */
NS_IMETHODIMP nsDOMLocation::GetHost(nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLocation::SetHost(const nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hostname; */
NS_IMETHODIMP nsDOMLocation::GetHostname(nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLocation::SetHostname(const nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString href; */
NS_IMETHODIMP nsDOMLocation::GetHref(nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLocation::SetHref(const nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString pathname; */
NS_IMETHODIMP nsDOMLocation::GetPathname(nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLocation::SetPathname(const nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString port; */
NS_IMETHODIMP nsDOMLocation::GetPort(nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLocation::SetPort(const nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString protocol; */
NS_IMETHODIMP nsDOMLocation::GetProtocol(nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLocation::SetProtocol(const nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString search; */
NS_IMETHODIMP nsDOMLocation::GetSearch(nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLocation::SetSearch(const nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reload ([optional] in boolean forceget); */
NS_IMETHODIMP nsDOMLocation::Reload(PRBool forceget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replace (in DOMString url); */
NS_IMETHODIMP nsDOMLocation::Replace(const nsAString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void assign (in DOMString url); */
NS_IMETHODIMP nsDOMLocation::Assign(const nsAString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toString (); */
NS_IMETHODIMP nsDOMLocation::ToString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLocation_h__ */
