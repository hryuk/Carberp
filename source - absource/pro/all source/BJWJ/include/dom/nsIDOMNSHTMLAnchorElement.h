/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLAnchorElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLAnchorElement_h__
#define __gen_nsIDOMNSHTMLAnchorElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLAnchorElement */
#define NS_IDOMNSHTMLANCHORELEMENT_IID_STR "a6cf911c-15b3-11d2-932e-00805f8add32"

#define NS_IDOMNSHTMLANCHORELEMENT_IID \
  {0xa6cf911c, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLAnchorElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLANCHORELEMENT_IID)

  /* attribute DOMString protocol; */
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsAString & aProtocol) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetProtocol(const nsAString & aProtocol) = 0;

  /* attribute DOMString host; */
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsAString & aHost) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHost(const nsAString & aHost) = 0;

  /* attribute DOMString hostname; */
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname) = 0;

  /* attribute DOMString pathname; */
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsAString & aPathname) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPathname(const nsAString & aPathname) = 0;

  /* attribute DOMString search; */
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsAString & aSearch) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSearch(const nsAString & aSearch) = 0;

  /* attribute DOMString port; */
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsAString & aPort) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPort(const nsAString & aPort) = 0;

  /* attribute DOMString hash; */
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsAString & aHash) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHash(const nsAString & aHash) = 0;

  /* readonly attribute DOMString text; */
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) = 0;

  /* DOMString toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLAnchorElement, NS_IDOMNSHTMLANCHORELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLANCHORELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsAString & aProtocol); \
  NS_SCRIPTABLE NS_IMETHOD SetProtocol(const nsAString & aProtocol); \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsAString & aHost); \
  NS_SCRIPTABLE NS_IMETHOD SetHost(const nsAString & aHost); \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname); \
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname); \
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsAString & aPathname); \
  NS_SCRIPTABLE NS_IMETHOD SetPathname(const nsAString & aPathname); \
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsAString & aSearch); \
  NS_SCRIPTABLE NS_IMETHOD SetSearch(const nsAString & aSearch); \
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsAString & aPort); \
  NS_SCRIPTABLE NS_IMETHOD SetPort(const nsAString & aPort); \
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsAString & aHash); \
  NS_SCRIPTABLE NS_IMETHOD SetHash(const nsAString & aHash); \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText); \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLANCHORELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsAString & aProtocol) { return _to GetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD SetProtocol(const nsAString & aProtocol) { return _to SetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsAString & aHost) { return _to GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD SetHost(const nsAString & aHost) { return _to SetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname) { return _to GetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname) { return _to SetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsAString & aPathname) { return _to GetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD SetPathname(const nsAString & aPathname) { return _to SetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsAString & aSearch) { return _to GetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearch(const nsAString & aSearch) { return _to SetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsAString & aPort) { return _to GetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD SetPort(const nsAString & aPort) { return _to SetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsAString & aHash) { return _to GetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD SetHash(const nsAString & aHash) { return _to SetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLANCHORELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsAString & aProtocol) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD SetProtocol(const nsAString & aProtocol) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsAString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD SetHost(const nsAString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsAString & aHostname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD SetHostname(const nsAString & aHostname) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsAString & aPathname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD SetPathname(const nsAString & aPathname) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsAString & aSearch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearch(const nsAString & aSearch) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsAString & aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD SetPort(const nsAString & aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsAString & aHash) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD SetHash(const nsAString & aHash) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLAnchorElement : public nsIDOMNSHTMLAnchorElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLANCHORELEMENT

  nsDOMNSHTMLAnchorElement();

private:
  ~nsDOMNSHTMLAnchorElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLAnchorElement, nsIDOMNSHTMLAnchorElement)

nsDOMNSHTMLAnchorElement::nsDOMNSHTMLAnchorElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLAnchorElement::~nsDOMNSHTMLAnchorElement()
{
  /* destructor code */
}

/* attribute DOMString protocol; */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::GetProtocol(nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::SetProtocol(const nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString host; */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::GetHost(nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::SetHost(const nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hostname; */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::GetHostname(nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::SetHostname(const nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString pathname; */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::GetPathname(nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::SetPathname(const nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString search; */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::GetSearch(nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::SetSearch(const nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString port; */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::GetPort(nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::SetPort(const nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hash; */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::GetHash(nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::SetHash(const nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString text; */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toString (); */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement::ToString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLAnchorElement_h__ */
