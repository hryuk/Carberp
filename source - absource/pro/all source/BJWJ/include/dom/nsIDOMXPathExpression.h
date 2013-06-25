/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xpath/nsIDOMXPathExpression.idl
 */

#ifndef __gen_nsIDOMXPathExpression_h__
#define __gen_nsIDOMXPathExpression_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXPathResult; /* forward declaration */

class XPathException; /* forward declaration */


/* starting interface:    nsIDOMXPathExpression */
#define NS_IDOMXPATHEXPRESSION_IID_STR "75506f82-b504-11d5-a7f2-ca108ab8b6fc"

#define NS_IDOMXPATHEXPRESSION_IID \
  {0x75506f82, 0xb504, 0x11d5, \
    { 0xa7, 0xf2, 0xca, 0x10, 0x8a, 0xb8, 0xb6, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXPathExpression : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXPATHEXPRESSION_IID)

  /* nsISupports evaluate (in nsIDOMNode contextNode, in unsigned short type, in nsISupports result)  raises (XPathException, DOMException); */
  NS_SCRIPTABLE NS_IMETHOD Evaluate(nsIDOMNode *contextNode, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXPathExpression, NS_IDOMXPATHEXPRESSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXPATHEXPRESSION \
  NS_SCRIPTABLE NS_IMETHOD Evaluate(nsIDOMNode *contextNode, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXPATHEXPRESSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Evaluate(nsIDOMNode *contextNode, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM) { return _to Evaluate(contextNode, type, result, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXPATHEXPRESSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Evaluate(nsIDOMNode *contextNode, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Evaluate(contextNode, type, result, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXPathExpression : public nsIDOMXPathExpression
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXPATHEXPRESSION

  nsDOMXPathExpression();

private:
  ~nsDOMXPathExpression();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXPathExpression, nsIDOMXPathExpression)

nsDOMXPathExpression::nsDOMXPathExpression()
{
  /* member initializers and constructor code */
}

nsDOMXPathExpression::~nsDOMXPathExpression()
{
  /* destructor code */
}

/* nsISupports evaluate (in nsIDOMNode contextNode, in unsigned short type, in nsISupports result)  raises (XPathException, DOMException); */
NS_IMETHODIMP nsDOMXPathExpression::Evaluate(nsIDOMNode *contextNode, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXPathExpression_h__ */
