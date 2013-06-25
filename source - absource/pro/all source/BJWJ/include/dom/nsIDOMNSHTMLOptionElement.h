/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLOptionElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLOptionElement_h__
#define __gen_nsIDOMNSHTMLOptionElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLOptionElement */
#define NS_IDOMNSHTMLOPTIONELEMENT_IID_STR "e2dfc89c-7ae0-4651-8aee-7f5edc2aa626"

#define NS_IDOMNSHTMLOPTIONELEMENT_IID \
  {0xe2dfc89c, 0x7ae0, 0x4651, \
    { 0x8a, 0xee, 0x7f, 0x5e, 0xdc, 0x2a, 0xa6, 0x26 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLOptionElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLOPTIONELEMENT_IID)

  /* attribute DOMString text; */
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetText(const nsAString & aText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLOptionElement, NS_IDOMNSHTMLOPTIONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLOPTIONELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText); \
  NS_SCRIPTABLE NS_IMETHOD SetText(const nsAString & aText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLOPTIONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD SetText(const nsAString & aText) { return _to SetText(aText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLOPTIONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD SetText(const nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetText(aText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLOptionElement : public nsIDOMNSHTMLOptionElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLOPTIONELEMENT

  nsDOMNSHTMLOptionElement();

private:
  ~nsDOMNSHTMLOptionElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLOptionElement, nsIDOMNSHTMLOptionElement)

nsDOMNSHTMLOptionElement::nsDOMNSHTMLOptionElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLOptionElement::~nsDOMNSHTMLOptionElement()
{
  /* destructor code */
}

/* attribute DOMString text; */
NS_IMETHODIMP nsDOMNSHTMLOptionElement::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLOptionElement::SetText(const nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLOptionElement_h__ */
