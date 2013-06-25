/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xpath/nsIDOMXPathNSResolver.idl
 */

#ifndef __gen_nsIDOMXPathNSResolver_h__
#define __gen_nsIDOMXPathNSResolver_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXPathNSResolver */
#define NS_IDOMXPATHNSRESOLVER_IID_STR "75506f83-b504-11d5-a7f2-ca108ab8b6fc"

#define NS_IDOMXPATHNSRESOLVER_IID \
  {0x75506f83, 0xb504, 0x11d5, \
    { 0xa7, 0xf2, 0xca, 0x10, 0x8a, 0xb8, 0xb6, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXPathNSResolver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXPATHNSRESOLVER_IID)

  /* DOMString lookupNamespaceURI (in DOMString prefix); */
  NS_SCRIPTABLE NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXPathNSResolver, NS_IDOMXPATHNSRESOLVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXPATHNSRESOLVER \
  NS_SCRIPTABLE NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXPATHNSRESOLVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM) { return _to LookupNamespaceURI(prefix, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXPATHNSRESOLVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LookupNamespaceURI(prefix, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXPathNSResolver : public nsIDOMXPathNSResolver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXPATHNSRESOLVER

  nsDOMXPathNSResolver();

private:
  ~nsDOMXPathNSResolver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXPathNSResolver, nsIDOMXPathNSResolver)

nsDOMXPathNSResolver::nsDOMXPathNSResolver()
{
  /* member initializers and constructor code */
}

nsDOMXPathNSResolver::~nsDOMXPathNSResolver()
{
  /* destructor code */
}

/* DOMString lookupNamespaceURI (in DOMString prefix); */
NS_IMETHODIMP nsDOMXPathNSResolver::LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXPathNSResolver_h__ */
