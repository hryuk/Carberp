/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLFormElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLFormElement_h__
#define __gen_nsIDOMNSHTMLFormElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLFormElement */
#define NS_IDOMNSHTMLFORMELEMENT_IID_STR "a6cf90c6-15b3-11d2-932e-00805f8add32"

#define NS_IDOMNSHTMLFORMELEMENT_IID \
  {0xa6cf90c6, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLFormElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLFORMELEMENT_IID)

  /* attribute DOMString encoding; */
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLFormElement, NS_IDOMNSHTMLFORMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLFORMELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding); \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLFORMELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return _to GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return _to SetEncoding(aEncoding); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLFORMELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEncoding(aEncoding); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLFormElement : public nsIDOMNSHTMLFormElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLFORMELEMENT

  nsDOMNSHTMLFormElement();

private:
  ~nsDOMNSHTMLFormElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLFormElement, nsIDOMNSHTMLFormElement)

nsDOMNSHTMLFormElement::nsDOMNSHTMLFormElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLFormElement::~nsDOMNSHTMLFormElement()
{
  /* destructor code */
}

/* attribute DOMString encoding; */
NS_IMETHODIMP nsDOMNSHTMLFormElement::GetEncoding(nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLFormElement::SetEncoding(const nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLFormElement_h__ */
