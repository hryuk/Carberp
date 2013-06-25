/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMDocumentCSS.idl
 */

#ifndef __gen_nsIDOMDocumentCSS_h__
#define __gen_nsIDOMDocumentCSS_h__


#ifndef __gen_nsIDOMDocumentStyle_h__
#include "nsIDOMDocumentStyle.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDocumentCSS */
#define NS_IDOMDOCUMENTCSS_IID_STR "39f76c23-45b2-428a-9240-a981e5abf148"

#define NS_IDOMDOCUMENTCSS_IID \
  {0x39f76c23, 0x45b2, 0x428a, \
    { 0x92, 0x40, 0xa9, 0x81, 0xe5, 0xab, 0xf1, 0x48 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDocumentCSS : public nsIDOMDocumentStyle {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTCSS_IID)

  /* nsIDOMCSSStyleDeclaration getOverrideStyle (in nsIDOMElement elt, in DOMString pseudoElt); */
  NS_SCRIPTABLE NS_IMETHOD GetOverrideStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentCSS, NS_IDOMDOCUMENTCSS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTCSS \
  NS_SCRIPTABLE NS_IMETHOD GetOverrideStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTCSS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOverrideStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration **_retval NS_OUTPARAM) { return _to GetOverrideStyle(elt, pseudoElt, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTCSS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOverrideStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOverrideStyle(elt, pseudoElt, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentCSS : public nsIDOMDocumentCSS
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTCSS

  nsDOMDocumentCSS();

private:
  ~nsDOMDocumentCSS();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDocumentCSS, nsIDOMDocumentCSS)

nsDOMDocumentCSS::nsDOMDocumentCSS()
{
  /* member initializers and constructor code */
}

nsDOMDocumentCSS::~nsDOMDocumentCSS()
{
  /* destructor code */
}

/* nsIDOMCSSStyleDeclaration getOverrideStyle (in nsIDOMElement elt, in DOMString pseudoElt); */
NS_IMETHODIMP nsDOMDocumentCSS::GetOverrideStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentCSS_h__ */
