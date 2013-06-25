/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xbl/nsIDOMDocumentXBL.idl
 */

#ifndef __gen_nsIDOMDocumentXBL_h__
#define __gen_nsIDOMDocumentXBL_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDocumentXBL */
#define NS_IDOMDOCUMENTXBL_IID_STR "1a38762b-4da5-4f61-80fb-9317e198cb92"

#define NS_IDOMDOCUMENTXBL_IID \
  {0x1a38762b, 0x4da5, 0x4f61, \
    { 0x80, 0xfb, 0x93, 0x17, 0xe1, 0x98, 0xcb, 0x92 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDocumentXBL : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTXBL_IID)

  /* nsIDOMNodeList getAnonymousNodes (in nsIDOMElement elt); */
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList **_retval NS_OUTPARAM) = 0;

  /* nsIDOMElement getAnonymousElementByAttribute (in nsIDOMElement elt, in DOMString attrName, in DOMString attrValue); */
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /* void addBinding (in nsIDOMElement elt, in DOMString bindingURL); */
  NS_SCRIPTABLE NS_IMETHOD AddBinding(nsIDOMElement *elt, const nsAString & bindingURL) = 0;

  /* void removeBinding (in nsIDOMElement elt, in DOMString bindingURL); */
  NS_SCRIPTABLE NS_IMETHOD RemoveBinding(nsIDOMElement *elt, const nsAString & bindingURL) = 0;

  /* nsIDOMElement getBindingParent (in nsIDOMNode node); */
  NS_SCRIPTABLE NS_IMETHOD GetBindingParent(nsIDOMNode *node, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /* void loadBindingDocument (in DOMString documentURL); */
  NS_SCRIPTABLE NS_IMETHOD LoadBindingDocument(const nsAString & documentURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentXBL, NS_IDOMDOCUMENTXBL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTXBL \
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddBinding(nsIDOMElement *elt, const nsAString & bindingURL); \
  NS_SCRIPTABLE NS_IMETHOD RemoveBinding(nsIDOMElement *elt, const nsAString & bindingURL); \
  NS_SCRIPTABLE NS_IMETHOD GetBindingParent(nsIDOMNode *node, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LoadBindingDocument(const nsAString & documentURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTXBL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList **_retval NS_OUTPARAM) { return _to GetAnonymousNodes(elt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetAnonymousElementByAttribute(elt, attrName, attrValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddBinding(nsIDOMElement *elt, const nsAString & bindingURL) { return _to AddBinding(elt, bindingURL); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveBinding(nsIDOMElement *elt, const nsAString & bindingURL) { return _to RemoveBinding(elt, bindingURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetBindingParent(nsIDOMNode *node, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetBindingParent(node, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadBindingDocument(const nsAString & documentURL) { return _to LoadBindingDocument(documentURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTXBL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnonymousNodes(elt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnonymousElementByAttribute(elt, attrName, attrValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddBinding(nsIDOMElement *elt, const nsAString & bindingURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddBinding(elt, bindingURL); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveBinding(nsIDOMElement *elt, const nsAString & bindingURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveBinding(elt, bindingURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetBindingParent(nsIDOMNode *node, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBindingParent(node, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadBindingDocument(const nsAString & documentURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadBindingDocument(documentURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentXBL : public nsIDOMDocumentXBL
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTXBL

  nsDOMDocumentXBL();

private:
  ~nsDOMDocumentXBL();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDocumentXBL, nsIDOMDocumentXBL)

nsDOMDocumentXBL::nsDOMDocumentXBL()
{
  /* member initializers and constructor code */
}

nsDOMDocumentXBL::~nsDOMDocumentXBL()
{
  /* destructor code */
}

/* nsIDOMNodeList getAnonymousNodes (in nsIDOMElement elt); */
NS_IMETHODIMP nsDOMDocumentXBL::GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getAnonymousElementByAttribute (in nsIDOMElement elt, in DOMString attrName, in DOMString attrValue); */
NS_IMETHODIMP nsDOMDocumentXBL::GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addBinding (in nsIDOMElement elt, in DOMString bindingURL); */
NS_IMETHODIMP nsDOMDocumentXBL::AddBinding(nsIDOMElement *elt, const nsAString & bindingURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeBinding (in nsIDOMElement elt, in DOMString bindingURL); */
NS_IMETHODIMP nsDOMDocumentXBL::RemoveBinding(nsIDOMElement *elt, const nsAString & bindingURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getBindingParent (in nsIDOMNode node); */
NS_IMETHODIMP nsDOMDocumentXBL::GetBindingParent(nsIDOMNode *node, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadBindingDocument (in DOMString documentURL); */
NS_IMETHODIMP nsDOMDocumentXBL::LoadBindingDocument(const nsAString & documentURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentXBL_h__ */
