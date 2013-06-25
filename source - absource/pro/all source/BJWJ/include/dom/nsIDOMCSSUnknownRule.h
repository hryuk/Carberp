/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMCSSUnknownRule.idl
 */

#ifndef __gen_nsIDOMCSSUnknownRule_h__
#define __gen_nsIDOMCSSUnknownRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSUnknownRule */
#define NS_IDOMCSSUNKNOWNRULE_IID_STR "a6cf90d0-15b3-11d2-932e-00805f8add32"

#define NS_IDOMCSSUNKNOWNRULE_IID \
  {0xa6cf90d0, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCSSUnknownRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSUNKNOWNRULE_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSUnknownRule, NS_IDOMCSSUNKNOWNRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSUNKNOWNRULE \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSUNKNOWNRULE(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSUNKNOWNRULE(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSUnknownRule : public nsIDOMCSSUnknownRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSUNKNOWNRULE

  nsDOMCSSUnknownRule();

private:
  ~nsDOMCSSUnknownRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSUnknownRule, nsIDOMCSSUnknownRule)

nsDOMCSSUnknownRule::nsDOMCSSUnknownRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSUnknownRule::~nsDOMCSSUnknownRule()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSUnknownRule_h__ */
