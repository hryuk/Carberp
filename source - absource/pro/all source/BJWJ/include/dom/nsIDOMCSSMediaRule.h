/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMCSSMediaRule.idl
 */

#ifndef __gen_nsIDOMCSSMediaRule_h__
#define __gen_nsIDOMCSSMediaRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSMediaRule */
#define NS_IDOMCSSMEDIARULE_IID_STR "a6cf90bc-15b3-11d2-932e-00805f8add32"

#define NS_IDOMCSSMEDIARULE_IID \
  {0xa6cf90bc, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCSSMediaRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSMEDIARULE_IID)

  /* readonly attribute nsIDOMMediaList media; */
  NS_SCRIPTABLE NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) = 0;

  /* readonly attribute nsIDOMCSSRuleList cssRules; */
  NS_SCRIPTABLE NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) = 0;

  /* unsigned long insertRule (in DOMString rule, in unsigned long index)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD InsertRule(const nsAString & rule, PRUint32 index, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* void deleteRule (in unsigned long index)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD DeleteRule(PRUint32 index) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSMediaRule, NS_IDOMCSSMEDIARULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSMEDIARULE \
  NS_SCRIPTABLE NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia); \
  NS_SCRIPTABLE NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules); \
  NS_SCRIPTABLE NS_IMETHOD InsertRule(const nsAString & rule, PRUint32 index, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DeleteRule(PRUint32 index); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSMEDIARULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) { return _to GetMedia(aMedia); } \
  NS_SCRIPTABLE NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) { return _to GetCssRules(aCssRules); } \
  NS_SCRIPTABLE NS_IMETHOD InsertRule(const nsAString & rule, PRUint32 index, PRUint32 *_retval NS_OUTPARAM) { return _to InsertRule(rule, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteRule(PRUint32 index) { return _to DeleteRule(index); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSMEDIARULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_SCRIPTABLE NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCssRules(aCssRules); } \
  NS_SCRIPTABLE NS_IMETHOD InsertRule(const nsAString & rule, PRUint32 index, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertRule(rule, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteRule(PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteRule(index); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSMediaRule : public nsIDOMCSSMediaRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSMEDIARULE

  nsDOMCSSMediaRule();

private:
  ~nsDOMCSSMediaRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSMediaRule, nsIDOMCSSMediaRule)

nsDOMCSSMediaRule::nsDOMCSSMediaRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSMediaRule::~nsDOMCSSMediaRule()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMediaList media; */
NS_IMETHODIMP nsDOMCSSMediaRule::GetMedia(nsIDOMMediaList * *aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSRuleList cssRules; */
NS_IMETHODIMP nsDOMCSSMediaRule::GetCssRules(nsIDOMCSSRuleList * *aCssRules)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long insertRule (in DOMString rule, in unsigned long index)  raises (DOMException); */
NS_IMETHODIMP nsDOMCSSMediaRule::InsertRule(const nsAString & rule, PRUint32 index, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteRule (in unsigned long index)  raises (DOMException); */
NS_IMETHODIMP nsDOMCSSMediaRule::DeleteRule(PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSMediaRule_h__ */
