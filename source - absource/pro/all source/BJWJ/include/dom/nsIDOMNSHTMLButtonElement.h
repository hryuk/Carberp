/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLButtonElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLButtonElement_h__
#define __gen_nsIDOMNSHTMLButtonElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLButtonElement */
#define NS_IDOMNSHTMLBUTTONELEMENT_IID_STR "c914d7a4-63b3-4d40-943f-91a3c7ab0d4d"

#define NS_IDOMNSHTMLBUTTONELEMENT_IID \
  {0xc914d7a4, 0x63b3, 0x4d40, \
    { 0x94, 0x3f, 0x91, 0xa3, 0xc7, 0xab, 0x0d, 0x4d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLButtonElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLBUTTONELEMENT_IID)

  /* void blur (); */
  NS_SCRIPTABLE NS_IMETHOD Blur(void) = 0;

  /* void focus (); */
  NS_SCRIPTABLE NS_IMETHOD Focus(void) = 0;

  /* void click (); */
  NS_SCRIPTABLE NS_IMETHOD Click(void) = 0;

  /* attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLButtonElement, NS_IDOMNSHTMLBUTTONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLBUTTONELEMENT \
  NS_SCRIPTABLE NS_IMETHOD Blur(void); \
  NS_SCRIPTABLE NS_IMETHOD Focus(void); \
  NS_SCRIPTABLE NS_IMETHOD Click(void); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLBUTTONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return _to Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return _to Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Click(void) { return _to Click(); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLBUTTONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Click(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Click(); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLButtonElement : public nsIDOMNSHTMLButtonElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLBUTTONELEMENT

  nsDOMNSHTMLButtonElement();

private:
  ~nsDOMNSHTMLButtonElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLButtonElement, nsIDOMNSHTMLButtonElement)

nsDOMNSHTMLButtonElement::nsDOMNSHTMLButtonElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLButtonElement::~nsDOMNSHTMLButtonElement()
{
  /* destructor code */
}

/* void blur (); */
NS_IMETHODIMP nsDOMNSHTMLButtonElement::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMNSHTMLButtonElement::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void click (); */
NS_IMETHODIMP nsDOMNSHTMLButtonElement::Click()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMNSHTMLButtonElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLButtonElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLButtonElement_h__ */
