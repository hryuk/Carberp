/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMCSSImportRule.idl
 */

#ifndef __gen_nsIDOMCSSImportRule_h__
#define __gen_nsIDOMCSSImportRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSImportRule */
#define NS_IDOMCSSIMPORTRULE_IID_STR "a6cf90cf-15b3-11d2-932e-00805f8add32"

#define NS_IDOMCSSIMPORTRULE_IID \
  {0xa6cf90cf, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCSSImportRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSIMPORTRULE_IID)

  /* readonly attribute DOMString href; */
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsAString & aHref) = 0;

  /* readonly attribute nsIDOMMediaList media; */
  NS_SCRIPTABLE NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) = 0;

  /* readonly attribute nsIDOMCSSStyleSheet styleSheet; */
  NS_SCRIPTABLE NS_IMETHOD GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSImportRule, NS_IDOMCSSIMPORTRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSIMPORTRULE \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsAString & aHref); \
  NS_SCRIPTABLE NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia); \
  NS_SCRIPTABLE NS_IMETHOD GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSIMPORTRULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsAString & aHref) { return _to GetHref(aHref); } \
  NS_SCRIPTABLE NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) { return _to GetMedia(aMedia); } \
  NS_SCRIPTABLE NS_IMETHOD GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet) { return _to GetStyleSheet(aStyleSheet); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSIMPORTRULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsAString & aHref) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } \
  NS_SCRIPTABLE NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_SCRIPTABLE NS_IMETHOD GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleSheet(aStyleSheet); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSImportRule : public nsIDOMCSSImportRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSIMPORTRULE

  nsDOMCSSImportRule();

private:
  ~nsDOMCSSImportRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSImportRule, nsIDOMCSSImportRule)

nsDOMCSSImportRule::nsDOMCSSImportRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSImportRule::~nsDOMCSSImportRule()
{
  /* destructor code */
}

/* readonly attribute DOMString href; */
NS_IMETHODIMP nsDOMCSSImportRule::GetHref(nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMMediaList media; */
NS_IMETHODIMP nsDOMCSSImportRule::GetMedia(nsIDOMMediaList * *aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSStyleSheet styleSheet; */
NS_IMETHODIMP nsDOMCSSImportRule::GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSImportRule_h__ */
