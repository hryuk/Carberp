/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMCSSFontFaceRule.idl
 */

#ifndef __gen_nsIDOMCSSFontFaceRule_h__
#define __gen_nsIDOMCSSFontFaceRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSFontFaceRule */
#define NS_IDOMCSSFONTFACERULE_IID_STR "a6cf90bb-15b3-11d2-932e-00805f8add32"

#define NS_IDOMCSSFONTFACERULE_IID \
  {0xa6cf90bb, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCSSFontFaceRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSFONTFACERULE_IID)

  /* readonly attribute nsIDOMCSSStyleDeclaration style; */
  NS_SCRIPTABLE NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSFontFaceRule, NS_IDOMCSSFONTFACERULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSFONTFACERULE \
  NS_SCRIPTABLE NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSFONTFACERULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) { return _to GetStyle(aStyle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSFONTFACERULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyle(aStyle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSFontFaceRule : public nsIDOMCSSFontFaceRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSFONTFACERULE

  nsDOMCSSFontFaceRule();

private:
  ~nsDOMCSSFontFaceRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSFontFaceRule, nsIDOMCSSFontFaceRule)

nsDOMCSSFontFaceRule::nsDOMCSSFontFaceRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSFontFaceRule::~nsDOMCSSFontFaceRule()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSStyleDeclaration style; */
NS_IMETHODIMP nsDOMCSSFontFaceRule::GetStyle(nsIDOMCSSStyleDeclaration * *aStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSFontFaceRule_h__ */
