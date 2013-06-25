/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xul/templates/public/nsIXULTemplateRuleFilter.idl
 */

#ifndef __gen_nsIXULTemplateRuleFilter_h__
#define __gen_nsIXULTemplateRuleFilter_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISupports; /* forward declaration */

class nsIXULTemplateResult; /* forward declaration */


/* starting interface:    nsIXULTemplateRuleFilter */
#define NS_IXULTEMPLATERULEFILTER_IID_STR "819cd1ed-8010-42e1-a8b9-778b726a1ff3"

#define NS_IXULTEMPLATERULEFILTER_IID \
  {0x819cd1ed, 0x8010, 0x42e1, \
    { 0xa8, 0xb9, 0x77, 0x8b, 0x72, 0x6a, 0x1f, 0xf3 }}

/**
 * A rule filter may be used to add additional filtering of results to a rule.
 * The filter is used to further reject results from matching the template's
 * rules, beyond what the template syntax can do itself, thus allowing for
 * more complex result filtering. The rule filter is applied after the rule
 * syntax within the template.
 *
 * Only one filter may apply to each rule within the template and may be
 * assigned using the template builder's addRuleFilter method.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXULTemplateRuleFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTEMPLATERULEFILTER_IID)

  /**
   * Evaluate a result and return true if the result is accepted by this
   * filter, or false if it is rejected. Accepted results will have output
   * generated for them for the rule. Rejected results will not, but they
   * may still match another rule.
   *
   * @param aRef the result to examine
   * @param aRule the rule node
   *
   * @return true if the rule matches
   */
  /* boolean match (in nsIXULTemplateResult aRef, in nsIDOMNode aRule); */
  NS_SCRIPTABLE NS_IMETHOD Match(nsIXULTemplateResult *aRef, nsIDOMNode *aRule, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTemplateRuleFilter, NS_IXULTEMPLATERULEFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTEMPLATERULEFILTER \
  NS_SCRIPTABLE NS_IMETHOD Match(nsIXULTemplateResult *aRef, nsIDOMNode *aRule, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTEMPLATERULEFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Match(nsIXULTemplateResult *aRef, nsIDOMNode *aRule, PRBool *_retval NS_OUTPARAM) { return _to Match(aRef, aRule, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTEMPLATERULEFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Match(nsIXULTemplateResult *aRef, nsIDOMNode *aRule, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Match(aRef, aRule, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTemplateRuleFilter : public nsIXULTemplateRuleFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTEMPLATERULEFILTER

  nsXULTemplateRuleFilter();

private:
  ~nsXULTemplateRuleFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTemplateRuleFilter, nsIXULTemplateRuleFilter)

nsXULTemplateRuleFilter::nsXULTemplateRuleFilter()
{
  /* member initializers and constructor code */
}

nsXULTemplateRuleFilter::~nsXULTemplateRuleFilter()
{
  /* destructor code */
}

/* boolean match (in nsIXULTemplateResult aRef, in nsIDOMNode aRule); */
NS_IMETHODIMP nsXULTemplateRuleFilter::Match(nsIXULTemplateResult *aRef, nsIDOMNode *aRule, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULTemplateRuleFilter_h__ */
