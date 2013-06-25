/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLAreaElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLAreaElement_h__
#define __gen_nsIDOMNSHTMLAreaElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLAreaElement */
#define NS_IDOMNSHTMLAREAELEMENT_IID_STR "3dce9071-f3b9-4280-a6ee-776cdfe3dd9e"

#define NS_IDOMNSHTMLAREAELEMENT_IID \
  {0x3dce9071, 0xf3b9, 0x4280, \
    { 0xa6, 0xee, 0x77, 0x6c, 0xdf, 0xe3, 0xdd, 0x9e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLAreaElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLAREAELEMENT_IID)

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

  /* DOMString toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLAreaElement, NS_IDOMNSHTMLAREAELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLAREAELEMENT \
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
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLAREAELEMENT(_to) \
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
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLAREAELEMENT(_to) \
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
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLAreaElement : public nsIDOMNSHTMLAreaElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLAREAELEMENT

  nsDOMNSHTMLAreaElement();

private:
  ~nsDOMNSHTMLAreaElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLAreaElement, nsIDOMNSHTMLAreaElement)

nsDOMNSHTMLAreaElement::nsDOMNSHTMLAreaElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLAreaElement::~nsDOMNSHTMLAreaElement()
{
  /* destructor code */
}

/* attribute DOMString protocol; */
NS_IMETHODIMP nsDOMNSHTMLAreaElement::GetProtocol(nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAreaElement::SetProtocol(const nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString host; */
NS_IMETHODIMP nsDOMNSHTMLAreaElement::GetHost(nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAreaElement::SetHost(const nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hostname; */
NS_IMETHODIMP nsDOMNSHTMLAreaElement::GetHostname(nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAreaElement::SetHostname(const nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString pathname; */
NS_IMETHODIMP nsDOMNSHTMLAreaElement::GetPathname(nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAreaElement::SetPathname(const nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString search; */
NS_IMETHODIMP nsDOMNSHTMLAreaElement::GetSearch(nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAreaElement::SetSearch(const nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString port; */
NS_IMETHODIMP nsDOMNSHTMLAreaElement::GetPort(nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAreaElement::SetPort(const nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hash; */
NS_IMETHODIMP nsDOMNSHTMLAreaElement::GetHash(nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAreaElement::SetHash(const nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toString (); */
NS_IMETHODIMP nsDOMNSHTMLAreaElement::ToString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLAreaElement_h__ */
