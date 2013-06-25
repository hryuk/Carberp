/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMCSSCharsetRule.idl
 */

#ifndef __gen_nsIDOMCSSCharsetRule_h__
#define __gen_nsIDOMCSSCharsetRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSCharsetRule */
#define NS_IDOMCSSCHARSETRULE_IID_STR "19fe78cc-65ff-4b1d-a5d7-9ea89692cec6"

#define NS_IDOMCSSCHARSETRULE_IID \
  {0x19fe78cc, 0x65ff, 0x4b1d, \
    { 0xa5, 0xd7, 0x9e, 0xa8, 0x96, 0x92, 0xce, 0xc6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCSSCharsetRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSCHARSETRULE_IID)

  /* attribute DOMString encoding; */
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSCharsetRule, NS_IDOMCSSCHARSETRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSCHARSETRULE \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding); \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSCHARSETRULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return _to GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return _to SetEncoding(aEncoding); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSCHARSETRULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEncoding(aEncoding); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSCharsetRule : public nsIDOMCSSCharsetRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSCHARSETRULE

  nsDOMCSSCharsetRule();

private:
  ~nsDOMCSSCharsetRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSCharsetRule, nsIDOMCSSCharsetRule)

nsDOMCSSCharsetRule::nsDOMCSSCharsetRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSCharsetRule::~nsDOMCSSCharsetRule()
{
  /* destructor code */
}

/* attribute DOMString encoding; */
NS_IMETHODIMP nsDOMCSSCharsetRule::GetEncoding(nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCharsetRule::SetEncoding(const nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSCharsetRule_h__ */
