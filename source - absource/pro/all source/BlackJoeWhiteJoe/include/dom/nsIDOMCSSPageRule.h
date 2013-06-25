/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMCSSPageRule.idl
 */

#ifndef __gen_nsIDOMCSSPageRule_h__
#define __gen_nsIDOMCSSPageRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSPageRule */
#define NS_IDOMCSSPAGERULE_IID_STR "a6cf90bd-15b3-11d2-932e-00805f8add32"

#define NS_IDOMCSSPAGERULE_IID \
  {0xa6cf90bd, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCSSPageRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSPAGERULE_IID)

  /* attribute DOMString selectorText; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectorText(nsAString & aSelectorText) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectorText(const nsAString & aSelectorText) = 0;

  /* readonly attribute nsIDOMCSSStyleDeclaration style; */
  NS_SCRIPTABLE NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSPageRule, NS_IDOMCSSPAGERULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSPAGERULE \
  NS_SCRIPTABLE NS_IMETHOD GetSelectorText(nsAString & aSelectorText); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectorText(const nsAString & aSelectorText); \
  NS_SCRIPTABLE NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSPAGERULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelectorText(nsAString & aSelectorText) { return _to GetSelectorText(aSelectorText); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectorText(const nsAString & aSelectorText) { return _to SetSelectorText(aSelectorText); } \
  NS_SCRIPTABLE NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) { return _to GetStyle(aStyle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSPAGERULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelectorText(nsAString & aSelectorText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectorText(aSelectorText); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectorText(const nsAString & aSelectorText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectorText(aSelectorText); } \
  NS_SCRIPTABLE NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyle(aStyle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSPageRule : public nsIDOMCSSPageRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSPAGERULE

  nsDOMCSSPageRule();

private:
  ~nsDOMCSSPageRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSPageRule, nsIDOMCSSPageRule)

nsDOMCSSPageRule::nsDOMCSSPageRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSPageRule::~nsDOMCSSPageRule()
{
  /* destructor code */
}

/* attribute DOMString selectorText; */
NS_IMETHODIMP nsDOMCSSPageRule::GetSelectorText(nsAString & aSelectorText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSPageRule::SetSelectorText(const nsAString & aSelectorText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSStyleDeclaration style; */
NS_IMETHODIMP nsDOMCSSPageRule::GetStyle(nsIDOMCSSStyleDeclaration * *aStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSPageRule_h__ */
