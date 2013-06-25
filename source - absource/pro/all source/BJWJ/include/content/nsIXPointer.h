/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xml/document/public/nsIXPointer.idl
 */

#ifndef __gen_nsIXPointer_h__
#define __gen_nsIXPointer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMRange; /* forward declaration */

class nsIDOMDocument; /* forward declaration */


/* starting interface:    nsIXPointerResult */
#define NS_IXPOINTERRESULT_IID_STR "d3992637-f474-4b65-83ed-323fe69c60d2"

#define NS_IXPOINTERRESULT_IID \
  {0xd3992637, 0xf474, 0x4b65, \
    { 0x83, 0xed, 0x32, 0x3f, 0xe6, 0x9c, 0x60, 0xd2 }}

/**
 * XXX A good XPointerResult would probably mimic XPathresult,
 *     this range list is just the minimum that will be able to represent
 *     all return values, although it would be more user friendly to return
 *     nodes and node lists when they are possible.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPointerResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPOINTERRESULT_IID)

  /* nsIDOMRange item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMRange **_retval NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPointerResult, NS_IXPOINTERRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPOINTERRESULT \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMRange **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPOINTERRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMRange **_retval NS_OUTPARAM) { return _to Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPOINTERRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMRange **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPointerResult : public nsIXPointerResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPOINTERRESULT

  nsXPointerResult();

private:
  ~nsXPointerResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPointerResult, nsIXPointerResult)

nsXPointerResult::nsXPointerResult()
{
  /* member initializers and constructor code */
}

nsXPointerResult::~nsXPointerResult()
{
  /* destructor code */
}

/* nsIDOMRange item (in unsigned long index); */
NS_IMETHODIMP nsXPointerResult::Item(PRUint32 index, nsIDOMRange **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsXPointerResult::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPointerSchemeContext */
#define NS_IXPOINTERSCHEMECONTEXT_IID_STR "781f4aa1-ebb3-4667-b1c2-2b35e94c4281"

#define NS_IXPOINTERSCHEMECONTEXT_IID \
  {0x781f4aa1, 0xebb3, 0x4667, \
    { 0xb1, 0xc2, 0x2b, 0x35, 0xe9, 0x4c, 0x42, 0x81 }}

/**
 * Scheme context for nsIXPointerSchemeProcessor. The context consists of
 * all the scheme/data pairs that precede the scheme/data that the
 * nsIXPointerSchemeProcessor is currently evaluating.
 */
class NS_NO_VTABLE nsIXPointerSchemeContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPOINTERSCHEMECONTEXT_IID)

  /* readonly attribute unsigned long count; */
  NS_IMETHOD GetCount(PRUint32 *aCount) = 0;

  /* void getSchemeData (in unsigned long index, out DOMString scheme, out DOMString data); */
  NS_IMETHOD GetSchemeData(PRUint32 index, nsAString & scheme NS_OUTPARAM, nsAString & data NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPointerSchemeContext, NS_IXPOINTERSCHEMECONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPOINTERSCHEMECONTEXT \
  NS_IMETHOD GetCount(PRUint32 *aCount); \
  NS_IMETHOD GetSchemeData(PRUint32 index, nsAString & scheme NS_OUTPARAM, nsAString & data NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPOINTERSCHEMECONTEXT(_to) \
  NS_IMETHOD GetCount(PRUint32 *aCount) { return _to GetCount(aCount); } \
  NS_IMETHOD GetSchemeData(PRUint32 index, nsAString & scheme NS_OUTPARAM, nsAString & data NS_OUTPARAM) { return _to GetSchemeData(index, scheme, data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPOINTERSCHEMECONTEXT(_to) \
  NS_IMETHOD GetCount(PRUint32 *aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(aCount); } \
  NS_IMETHOD GetSchemeData(PRUint32 index, nsAString & scheme NS_OUTPARAM, nsAString & data NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSchemeData(index, scheme, data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPointerSchemeContext : public nsIXPointerSchemeContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPOINTERSCHEMECONTEXT

  nsXPointerSchemeContext();

private:
  ~nsXPointerSchemeContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPointerSchemeContext, nsIXPointerSchemeContext)

nsXPointerSchemeContext::nsXPointerSchemeContext()
{
  /* member initializers and constructor code */
}

nsXPointerSchemeContext::~nsXPointerSchemeContext()
{
  /* destructor code */
}

/* readonly attribute unsigned long count; */
NS_IMETHODIMP nsXPointerSchemeContext::GetCount(PRUint32 *aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSchemeData (in unsigned long index, out DOMString scheme, out DOMString data); */
NS_IMETHODIMP nsXPointerSchemeContext::GetSchemeData(PRUint32 index, nsAString & scheme NS_OUTPARAM, nsAString & data NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * nsIXPointerSchemeProcessor implementations must be registered with the below
 * progid, appended with the scheme name that the processor implements.
 */
#define NS_XPOINTER_SCHEME_PROCESSOR_BASE "@mozilla.org/xml/xpointer;1?scheme="

/* starting interface:    nsIXPointerSchemeProcessor */
#define NS_IXPOINTERSCHEMEPROCESSOR_IID_STR "093d3559-b56b-44d0-8764-c25815715080"

#define NS_IXPOINTERSCHEMEPROCESSOR_IID \
  {0x093d3559, 0xb56b, 0x44d0, \
    { 0x87, 0x64, 0xc2, 0x58, 0x15, 0x71, 0x50, 0x80 }}

/**
 * nsIXPointerSchemeProcessors will be called by the XPointer Processor that
 * implements the XPointer Framework. This is done for each scheme the
 * XPointer Processor finds, in left-to-right order.
 */
class NS_NO_VTABLE nsIXPointerSchemeProcessor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPOINTERSCHEMEPROCESSOR_IID)

  /**
   * Evaluate.
   *
   * @param aDocument The document in which to resolve the XPointer.
   * @param aContext  The XPointer context in which to process aData.
   * @param aData     The data in the scheme that needs to be resolved.
   * @return          The result of the evaluation.
   */
  /* nsIXPointerResult evaluate (in nsIDOMDocument aDocument, in nsIXPointerSchemeContext aContext, in DOMString aData); */
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, nsIXPointerSchemeContext *aContext, const nsAString & aData, nsIXPointerResult **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPointerSchemeProcessor, NS_IXPOINTERSCHEMEPROCESSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPOINTERSCHEMEPROCESSOR \
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, nsIXPointerSchemeContext *aContext, const nsAString & aData, nsIXPointerResult **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPOINTERSCHEMEPROCESSOR(_to) \
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, nsIXPointerSchemeContext *aContext, const nsAString & aData, nsIXPointerResult **_retval NS_OUTPARAM) { return _to Evaluate(aDocument, aContext, aData, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPOINTERSCHEMEPROCESSOR(_to) \
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, nsIXPointerSchemeContext *aContext, const nsAString & aData, nsIXPointerResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Evaluate(aDocument, aContext, aData, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPointerSchemeProcessor : public nsIXPointerSchemeProcessor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPOINTERSCHEMEPROCESSOR

  nsXPointerSchemeProcessor();

private:
  ~nsXPointerSchemeProcessor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPointerSchemeProcessor, nsIXPointerSchemeProcessor)

nsXPointerSchemeProcessor::nsXPointerSchemeProcessor()
{
  /* member initializers and constructor code */
}

nsXPointerSchemeProcessor::~nsXPointerSchemeProcessor()
{
  /* destructor code */
}

/* nsIXPointerResult evaluate (in nsIDOMDocument aDocument, in nsIXPointerSchemeContext aContext, in DOMString aData); */
NS_IMETHODIMP nsXPointerSchemeProcessor::Evaluate(nsIDOMDocument *aDocument, nsIXPointerSchemeContext *aContext, const nsAString & aData, nsIXPointerResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPointerEvaluator */
#define NS_IXPOINTEREVALUATOR_IID_STR "addd0fe5-8555-45b7-b763-97d5898ce268"

#define NS_IXPOINTEREVALUATOR_IID \
  {0xaddd0fe5, 0x8555, 0x45b7, \
    { 0xb7, 0x63, 0x97, 0xd5, 0x89, 0x8c, 0xe2, 0x68 }}

/**
 * nsIXPointerEvaluator resolves an XPointer expression
 */
class NS_NO_VTABLE nsIXPointerEvaluator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPOINTEREVALUATOR_IID)

  /**
   * Evaluate an XPointer expression.
   *
   * @param aDocument   The document in which to evaluate.
   * @param aExpression The XPointer expression string to evaluate.
   * @return            The result.
   */
  /* nsIXPointerResult evaluate (in nsIDOMDocument aDocument, in DOMString aExpression); */
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIXPointerResult **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPointerEvaluator, NS_IXPOINTEREVALUATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPOINTEREVALUATOR \
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIXPointerResult **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPOINTEREVALUATOR(_to) \
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIXPointerResult **_retval NS_OUTPARAM) { return _to Evaluate(aDocument, aExpression, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPOINTEREVALUATOR(_to) \
  NS_IMETHOD Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIXPointerResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Evaluate(aDocument, aExpression, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPointerEvaluator : public nsIXPointerEvaluator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPOINTEREVALUATOR

  nsXPointerEvaluator();

private:
  ~nsXPointerEvaluator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPointerEvaluator, nsIXPointerEvaluator)

nsXPointerEvaluator::nsXPointerEvaluator()
{
  /* member initializers and constructor code */
}

nsXPointerEvaluator::~nsXPointerEvaluator()
{
  /* destructor code */
}

/* nsIXPointerResult evaluate (in nsIDOMDocument aDocument, in DOMString aExpression); */
NS_IMETHODIMP nsXPointerEvaluator::Evaluate(nsIDOMDocument *aDocument, const nsAString & aExpression, nsIXPointerResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPointer_h__ */
