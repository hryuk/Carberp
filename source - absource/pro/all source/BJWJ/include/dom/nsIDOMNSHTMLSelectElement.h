/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLSelectElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLSelectElement_h__
#define __gen_nsIDOMNSHTMLSelectElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLSelectElement */
#define NS_IDOMNSHTMLSELECTELEMENT_IID_STR "a6cf9105-15b3-11d2-932e-00805f8add32"

#define NS_IDOMNSHTMLSELECTELEMENT_IID \
  {0xa6cf9105, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLSelectElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLSELECTELEMENT_IID)

  /* nsIDOMNode item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode namedItem (in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLSelectElement, NS_IDOMNSHTMLSELECTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLSELECTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLSELECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) { return _to Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM) { return _to NamedItem(name, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLSELECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NamedItem(name, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLSelectElement : public nsIDOMNSHTMLSelectElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLSELECTELEMENT

  nsDOMNSHTMLSelectElement();

private:
  ~nsDOMNSHTMLSelectElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLSelectElement, nsIDOMNSHTMLSelectElement)

nsDOMNSHTMLSelectElement::nsDOMNSHTMLSelectElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLSelectElement::~nsDOMNSHTMLSelectElement()
{
  /* destructor code */
}

/* nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP nsDOMNSHTMLSelectElement::Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode namedItem (in DOMString name); */
NS_IMETHODIMP nsDOMNSHTMLSelectElement::NamedItem(const nsAString & name, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLSelectElement_h__ */
