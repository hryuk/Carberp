/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xpath/nsIDOMXPathNamespace.idl
 */

#ifndef __gen_nsIDOMXPathNamespace_h__
#define __gen_nsIDOMXPathNamespace_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXPathNamespace */
#define NS_IDOMXPATHNAMESPACE_IID_STR "75506f87-b504-11d5-a7f2-ca108ab8b6fc"

#define NS_IDOMXPATHNAMESPACE_IID \
  {0x75506f87, 0xb504, 0x11d5, \
    { 0xa7, 0xf2, 0xca, 0x10, 0x8a, 0xb8, 0xb6, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXPathNamespace : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXPATHNAMESPACE_IID)

  enum { XPATH_NAMESPACE_NODE = 13U };

  /* readonly attribute nsIDOMElement ownerElement; */
  NS_SCRIPTABLE NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXPathNamespace, NS_IDOMXPATHNAMESPACE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXPATHNAMESPACE \
  NS_SCRIPTABLE NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXPATHNAMESPACE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) { return _to GetOwnerElement(aOwnerElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXPATHNAMESPACE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerElement(aOwnerElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXPathNamespace : public nsIDOMXPathNamespace
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXPATHNAMESPACE

  nsDOMXPathNamespace();

private:
  ~nsDOMXPathNamespace();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXPathNamespace, nsIDOMXPathNamespace)

nsDOMXPathNamespace::nsDOMXPathNamespace()
{
  /* member initializers and constructor code */
}

nsDOMXPathNamespace::~nsDOMXPathNamespace()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement ownerElement; */
NS_IMETHODIMP nsDOMXPathNamespace::GetOwnerElement(nsIDOMElement * *aOwnerElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXPathNamespace_h__ */
