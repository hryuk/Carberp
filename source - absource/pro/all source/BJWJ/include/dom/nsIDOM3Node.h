/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOM3Node.idl
 */

#ifndef __gen_nsIDOM3Node_h__
#define __gen_nsIDOM3Node_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIDOMUserDataHandler; /* forward declaration */


/* starting interface:    nsIDOM3Node */
#define NS_IDOM3NODE_IID_STR "29fb2a18-1dd2-11b2-8dd9-a6fd5d5ad12f"

#define NS_IDOM3NODE_IID \
  {0x29fb2a18, 0x1dd2, 0x11b2, \
    { 0x8d, 0xd9, 0xa6, 0xfd, 0x5d, 0x5a, 0xd1, 0x2f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOM3Node : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOM3NODE_IID)

  /* readonly attribute DOMString baseURI; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsAString & aBaseURI) = 0;

  enum { DOCUMENT_POSITION_DISCONNECTED = 1U };

  enum { DOCUMENT_POSITION_PRECEDING = 2U };

  enum { DOCUMENT_POSITION_FOLLOWING = 4U };

  enum { DOCUMENT_POSITION_CONTAINS = 8U };

  enum { DOCUMENT_POSITION_CONTAINED_BY = 16U };

  enum { DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 32U };

  /* unsigned short compareDocumentPosition (in nsIDOMNode other)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD CompareDocumentPosition(nsIDOMNode *other, PRUint16 *_retval NS_OUTPARAM) = 0;

  /* attribute DOMString textContent; */
  NS_SCRIPTABLE NS_IMETHOD GetTextContent(nsAString & aTextContent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTextContent(const nsAString & aTextContent) = 0;

  /* boolean isSameNode (in nsIDOMNode other); */
  NS_SCRIPTABLE NS_IMETHOD IsSameNode(nsIDOMNode *other, PRBool *_retval NS_OUTPARAM) = 0;

  /* DOMString lookupPrefix (in DOMString namespaceURI); */
  NS_SCRIPTABLE NS_IMETHOD LookupPrefix(const nsAString & namespaceURI, nsAString & _retval NS_OUTPARAM) = 0;

  /* boolean isDefaultNamespace (in DOMString namespaceURI); */
  NS_SCRIPTABLE NS_IMETHOD IsDefaultNamespace(const nsAString & namespaceURI, PRBool *_retval NS_OUTPARAM) = 0;

  /* DOMString lookupNamespaceURI (in DOMString prefix); */
  NS_SCRIPTABLE NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM) = 0;

  /* boolean isEqualNode (in nsIDOMNode arg); */
  NS_SCRIPTABLE NS_IMETHOD IsEqualNode(nsIDOMNode *arg, PRBool *_retval NS_OUTPARAM) = 0;

  /* nsISupports getFeature (in DOMString feature, in DOMString version); */
  NS_SCRIPTABLE NS_IMETHOD GetFeature(const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM) = 0;

  /* nsIVariant setUserData (in DOMString key, in nsIVariant data, in nsIDOMUserDataHandler handler); */
  NS_SCRIPTABLE NS_IMETHOD SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* nsIVariant getUserData (in DOMString key); */
  NS_SCRIPTABLE NS_IMETHOD GetUserData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOM3Node, NS_IDOM3NODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOM3NODE \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsAString & aBaseURI); \
  NS_SCRIPTABLE NS_IMETHOD CompareDocumentPosition(nsIDOMNode *other, PRUint16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTextContent(nsAString & aTextContent); \
  NS_SCRIPTABLE NS_IMETHOD SetTextContent(const nsAString & aTextContent); \
  NS_SCRIPTABLE NS_IMETHOD IsSameNode(nsIDOMNode *other, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LookupPrefix(const nsAString & namespaceURI, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsDefaultNamespace(const nsAString & namespaceURI, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsEqualNode(nsIDOMNode *arg, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFeature(const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUserData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOM3NODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsAString & aBaseURI) { return _to GetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD CompareDocumentPosition(nsIDOMNode *other, PRUint16 *_retval NS_OUTPARAM) { return _to CompareDocumentPosition(other, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextContent(nsAString & aTextContent) { return _to GetTextContent(aTextContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextContent(const nsAString & aTextContent) { return _to SetTextContent(aTextContent); } \
  NS_SCRIPTABLE NS_IMETHOD IsSameNode(nsIDOMNode *other, PRBool *_retval NS_OUTPARAM) { return _to IsSameNode(other, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LookupPrefix(const nsAString & namespaceURI, nsAString & _retval NS_OUTPARAM) { return _to LookupPrefix(namespaceURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsDefaultNamespace(const nsAString & namespaceURI, PRBool *_retval NS_OUTPARAM) { return _to IsDefaultNamespace(namespaceURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM) { return _to LookupNamespaceURI(prefix, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualNode(nsIDOMNode *arg, PRBool *_retval NS_OUTPARAM) { return _to IsEqualNode(arg, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeature(const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM) { return _to GetFeature(feature, version, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant **_retval NS_OUTPARAM) { return _to SetUserData(key, data, handler, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM) { return _to GetUserData(key, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOM3NODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsAString & aBaseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD CompareDocumentPosition(nsIDOMNode *other, PRUint16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareDocumentPosition(other, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextContent(nsAString & aTextContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextContent(aTextContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextContent(const nsAString & aTextContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextContent(aTextContent); } \
  NS_SCRIPTABLE NS_IMETHOD IsSameNode(nsIDOMNode *other, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSameNode(other, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LookupPrefix(const nsAString & namespaceURI, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LookupPrefix(namespaceURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsDefaultNamespace(const nsAString & namespaceURI, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDefaultNamespace(namespaceURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LookupNamespaceURI(prefix, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualNode(nsIDOMNode *arg, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualNode(arg, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeature(const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeature(feature, version, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUserData(key, data, handler, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserData(key, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOM3Node : public nsIDOM3Node
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOM3NODE

  nsDOM3Node();

private:
  ~nsDOM3Node();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOM3Node, nsIDOM3Node)

nsDOM3Node::nsDOM3Node()
{
  /* member initializers and constructor code */
}

nsDOM3Node::~nsDOM3Node()
{
  /* destructor code */
}

/* readonly attribute DOMString baseURI; */
NS_IMETHODIMP nsDOM3Node::GetBaseURI(nsAString & aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short compareDocumentPosition (in nsIDOMNode other)  raises (DOMException); */
NS_IMETHODIMP nsDOM3Node::CompareDocumentPosition(nsIDOMNode *other, PRUint16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString textContent; */
NS_IMETHODIMP nsDOM3Node::GetTextContent(nsAString & aTextContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOM3Node::SetTextContent(const nsAString & aTextContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSameNode (in nsIDOMNode other); */
NS_IMETHODIMP nsDOM3Node::IsSameNode(nsIDOMNode *other, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString lookupPrefix (in DOMString namespaceURI); */
NS_IMETHODIMP nsDOM3Node::LookupPrefix(const nsAString & namespaceURI, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isDefaultNamespace (in DOMString namespaceURI); */
NS_IMETHODIMP nsDOM3Node::IsDefaultNamespace(const nsAString & namespaceURI, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString lookupNamespaceURI (in DOMString prefix); */
NS_IMETHODIMP nsDOM3Node::LookupNamespaceURI(const nsAString & prefix, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualNode (in nsIDOMNode arg); */
NS_IMETHODIMP nsDOM3Node::IsEqualNode(nsIDOMNode *arg, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getFeature (in DOMString feature, in DOMString version); */
NS_IMETHODIMP nsDOM3Node::GetFeature(const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant setUserData (in DOMString key, in nsIVariant data, in nsIDOMUserDataHandler handler); */
NS_IMETHODIMP nsDOM3Node::SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getUserData (in DOMString key); */
NS_IMETHODIMP nsDOM3Node::GetUserData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOM3Node_h__ */
