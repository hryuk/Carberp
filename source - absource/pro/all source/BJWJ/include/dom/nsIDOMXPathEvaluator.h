/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xpath/nsIDOMXPathEvaluator.idl
 */

#ifndef __gen_nsIDOMXPathEvaluator_h__
#define __gen_nsIDOMXPathEvaluator_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXPathNSResolver; /* forward declaration */

class nsIDOMXPathResult; /* forward declaration */

class nsIDOMXPathExpression; /* forward declaration */

class XPathException; /* forward declaration */


/* starting interface:    nsIDOMXPathEvaluator */
#define NS_IDOMXPATHEVALUATOR_IID_STR "75506f8a-b504-11d5-a7f2-ca108ab8b6fc"

#define NS_IDOMXPATHEVALUATOR_IID \
  {0x75506f8a, 0xb504, 0x11d5, \
    { 0xa7, 0xf2, 0xca, 0x10, 0x8a, 0xb8, 0xb6, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXPathEvaluator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXPATHEVALUATOR_IID)

  /* nsIDOMXPathExpression createExpression (in DOMString expression, in nsIDOMXPathNSResolver resolver)  raises (XPathException, DOMException); */
  NS_SCRIPTABLE NS_IMETHOD CreateExpression(const nsAString & expression, nsIDOMXPathNSResolver *resolver, nsIDOMXPathExpression **_retval NS_OUTPARAM) = 0;

  /* nsIDOMXPathNSResolver createNSResolver (in nsIDOMNode nodeResolver); */
  NS_SCRIPTABLE NS_IMETHOD CreateNSResolver(nsIDOMNode *nodeResolver, nsIDOMXPathNSResolver **_retval NS_OUTPARAM) = 0;

  /* nsISupports evaluate (in DOMString expression, in nsIDOMNode contextNode, in nsIDOMXPathNSResolver resolver, in unsigned short type, in nsISupports result)  raises (XPathException, DOMException); */
  NS_SCRIPTABLE NS_IMETHOD Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMXPathNSResolver *resolver, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXPathEvaluator, NS_IDOMXPATHEVALUATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXPATHEVALUATOR \
  NS_SCRIPTABLE NS_IMETHOD CreateExpression(const nsAString & expression, nsIDOMXPathNSResolver *resolver, nsIDOMXPathExpression **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateNSResolver(nsIDOMNode *nodeResolver, nsIDOMXPathNSResolver **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMXPathNSResolver *resolver, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXPATHEVALUATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateExpression(const nsAString & expression, nsIDOMXPathNSResolver *resolver, nsIDOMXPathExpression **_retval NS_OUTPARAM) { return _to CreateExpression(expression, resolver, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateNSResolver(nsIDOMNode *nodeResolver, nsIDOMXPathNSResolver **_retval NS_OUTPARAM) { return _to CreateNSResolver(nodeResolver, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMXPathNSResolver *resolver, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM) { return _to Evaluate(expression, contextNode, resolver, type, result, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXPATHEVALUATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateExpression(const nsAString & expression, nsIDOMXPathNSResolver *resolver, nsIDOMXPathExpression **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateExpression(expression, resolver, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateNSResolver(nsIDOMNode *nodeResolver, nsIDOMXPathNSResolver **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNSResolver(nodeResolver, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMXPathNSResolver *resolver, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Evaluate(expression, contextNode, resolver, type, result, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXPathEvaluator : public nsIDOMXPathEvaluator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXPATHEVALUATOR

  nsDOMXPathEvaluator();

private:
  ~nsDOMXPathEvaluator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXPathEvaluator, nsIDOMXPathEvaluator)

nsDOMXPathEvaluator::nsDOMXPathEvaluator()
{
  /* member initializers and constructor code */
}

nsDOMXPathEvaluator::~nsDOMXPathEvaluator()
{
  /* destructor code */
}

/* nsIDOMXPathExpression createExpression (in DOMString expression, in nsIDOMXPathNSResolver resolver)  raises (XPathException, DOMException); */
NS_IMETHODIMP nsDOMXPathEvaluator::CreateExpression(const nsAString & expression, nsIDOMXPathNSResolver *resolver, nsIDOMXPathExpression **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXPathNSResolver createNSResolver (in nsIDOMNode nodeResolver); */
NS_IMETHODIMP nsDOMXPathEvaluator::CreateNSResolver(nsIDOMNode *nodeResolver, nsIDOMXPathNSResolver **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports evaluate (in DOMString expression, in nsIDOMNode contextNode, in nsIDOMXPathNSResolver resolver, in unsigned short type, in nsISupports result)  raises (XPathException, DOMException); */
NS_IMETHODIMP nsDOMXPathEvaluator::Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMXPathNSResolver *resolver, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXPathEvaluator_h__ */
