/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xpath/nsIDOMNSXPathExpression.idl
 */

#ifndef __gen_nsIDOMNSXPathExpression_h__
#define __gen_nsIDOMNSXPathExpression_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXPathResult; /* forward declaration */

class XPathException; /* forward declaration */


/* starting interface:    nsIDOMNSXPathExpression */
#define NS_IDOMNSXPATHEXPRESSION_IID_STR "ce600ca8-e98a-4419-ad61-2f6d0cb0ecc8"

#define NS_IDOMNSXPATHEXPRESSION_IID \
  {0xce600ca8, 0xe98a, 0x4419, \
    { 0xad, 0x61, 0x2f, 0x6d, 0x0c, 0xb0, 0xec, 0xc8 }}

/**
 * Interface for Mozilla specific XPathExpression functions.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSXPathExpression : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSXPATHEXPRESSION_IID)

  /**
   * Evaluate the expression with the given context. Similar to
   * nsIDOMXPathExpression::evaluate(), except that this takes the context
   * position and size too.
   *
   * @param contextNode       The context node
   * @param contextPosition   The context position
   * @param contextSize       The context size
   * @param type              The needed result type
   * @param result            The result
   */
  /* nsISupports evaluateWithContext (in nsIDOMNode contextNode, in unsigned long contextPosition, in unsigned long contextSize, in unsigned short type, in nsISupports result)  raises (XPathException, DOMException); */
  NS_SCRIPTABLE NS_IMETHOD EvaluateWithContext(nsIDOMNode *contextNode, PRUint32 contextPosition, PRUint32 contextSize, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSXPathExpression, NS_IDOMNSXPATHEXPRESSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSXPATHEXPRESSION \
  NS_SCRIPTABLE NS_IMETHOD EvaluateWithContext(nsIDOMNode *contextNode, PRUint32 contextPosition, PRUint32 contextSize, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSXPATHEXPRESSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD EvaluateWithContext(nsIDOMNode *contextNode, PRUint32 contextPosition, PRUint32 contextSize, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM) { return _to EvaluateWithContext(contextNode, contextPosition, contextSize, type, result, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSXPATHEXPRESSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD EvaluateWithContext(nsIDOMNode *contextNode, PRUint32 contextPosition, PRUint32 contextSize, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvaluateWithContext(contextNode, contextPosition, contextSize, type, result, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSXPathExpression : public nsIDOMNSXPathExpression
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSXPATHEXPRESSION

  nsDOMNSXPathExpression();

private:
  ~nsDOMNSXPathExpression();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSXPathExpression, nsIDOMNSXPathExpression)

nsDOMNSXPathExpression::nsDOMNSXPathExpression()
{
  /* member initializers and constructor code */
}

nsDOMNSXPathExpression::~nsDOMNSXPathExpression()
{
  /* destructor code */
}

/* nsISupports evaluateWithContext (in nsIDOMNode contextNode, in unsigned long contextPosition, in unsigned long contextSize, in unsigned short type, in nsISupports result)  raises (XPathException, DOMException); */
NS_IMETHODIMP nsDOMNSXPathExpression::EvaluateWithContext(nsIDOMNode *contextNode, PRUint32 contextPosition, PRUint32 contextSize, PRUint16 type, nsISupports *result, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSXPathExpression_h__ */
