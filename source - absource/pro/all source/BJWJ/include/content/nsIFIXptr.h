/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xml/document/public/nsIFIXptr.idl
 */

#ifndef __gen_nsIFIXptr_h__
#define __gen_nsIFIXptr_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsIDOMRange; /* forward declaration */


/* starting interface:    nsIFIXptrEvaluator */
#define NS_IFIXPTREVALUATOR_IID_STR "50d28211-8fb8-4323-b93d-08a6e80e559e"

#define NS_IFIXPTREVALUATOR_IID \
  {0x50d28211, 0x8fb8, 0x4323, \
    { 0xb9, 0x3d, 0x08, 0xa6, 0xe8, 0x0e, 0x55, 0x9e }}

/**
 * nsIFIXptrEvaluator resolves a FIXptr expression
 */
class NS_NO_VTABLE nsIFIXptrEvaluator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFIXPTREVALUATOR_IID)

  /**
   * Evaluate a FIXptr expression.
   *
   * @param aDocument   The document in which to evaluate.
   * @param aExpression The FIXptr expression string to evaluate.
   * @return            The result.
   */
  /* nsIDOMRange evaluate (in nsIDOMDocument aDocument, in DOMString aExpression); */
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIDOMRange **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFIXptrEvaluator, NS_IFIXPTREVALUATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFIXPTREVALUATOR \
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIDOMRange **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFIXPTREVALUATOR(_to) \
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIDOMRange **_retval NS_OUTPARAM) { return _to Evaluate(aDocument, aExpression, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFIXPTREVALUATOR(_to) \
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIDOMRange **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Evaluate(aDocument, aExpression, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFIXptrEvaluator : public nsIFIXptrEvaluator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFIXPTREVALUATOR

  nsFIXptrEvaluator();

private:
  ~nsFIXptrEvaluator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFIXptrEvaluator, nsIFIXptrEvaluator)

nsFIXptrEvaluator::nsFIXptrEvaluator()
{
  /* member initializers and constructor code */
}

nsFIXptrEvaluator::~nsFIXptrEvaluator()
{
  /* destructor code */
}

/* nsIDOMRange evaluate (in nsIDOMDocument aDocument, in DOMString aExpression); */
NS_IMETHODIMP nsFIXptrEvaluator::Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIDOMRange **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFIXptr_h__ */
