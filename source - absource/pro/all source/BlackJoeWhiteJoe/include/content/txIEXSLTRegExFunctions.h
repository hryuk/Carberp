/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xslt/public/txIEXSLTRegExFunctions.idl
 */

#ifndef __gen_txIEXSLTRegExFunctions_h__
#define __gen_txIEXSLTRegExFunctions_h__


#ifndef __gen_txIFunctionEvaluationContext_h__
#include "txIFunctionEvaluationContext.h"
#endif

#ifndef __gen_txINodeSet_h__
#include "txINodeSet.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    txIEXSLTRegExFunctions */
#define TXIEXSLTREGEXFUNCTIONS_IID_STR "c180e993-aced-4839-95a0-ecd5ff138be9"

#define TXIEXSLTREGEXFUNCTIONS_IID \
  {0xc180e993, 0xaced, 0x4839, \
    { 0x95, 0xa0, 0xec, 0xd5, 0xff, 0x13, 0x8b, 0xe9 }}

class NS_NO_VTABLE NS_SCRIPTABLE txIEXSLTRegExFunctions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(TXIEXSLTREGEXFUNCTIONS_IID)

  /* txINodeSet match (in txIFunctionEvaluationContext aContext, in DOMString aString, in DOMString aRegEx, in DOMString aFlags); */
  NS_SCRIPTABLE NS_IMETHOD Match(txIFunctionEvaluationContext *aContext, const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, txINodeSet **_retval NS_OUTPARAM) = 0;

  /* DOMString replace (in DOMString aString, in DOMString aRegEx, in DOMString aFlags, in DOMString aReplace); */
  NS_SCRIPTABLE NS_IMETHOD Replace(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, const nsAString & aReplace, nsAString & _retval NS_OUTPARAM) = 0;

  /* boolean test (in DOMString aString, in DOMString aRegEx, in DOMString aFlags); */
  NS_SCRIPTABLE NS_IMETHOD Test(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(txIEXSLTRegExFunctions, TXIEXSLTREGEXFUNCTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_TXIEXSLTREGEXFUNCTIONS \
  NS_SCRIPTABLE NS_IMETHOD Match(txIFunctionEvaluationContext *aContext, const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, txINodeSet **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Replace(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, const nsAString & aReplace, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Test(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_TXIEXSLTREGEXFUNCTIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD Match(txIFunctionEvaluationContext *aContext, const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, txINodeSet **_retval NS_OUTPARAM) { return _to Match(aContext, aString, aRegEx, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Replace(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, const nsAString & aReplace, nsAString & _retval NS_OUTPARAM) { return _to Replace(aString, aRegEx, aFlags, aReplace, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Test(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, PRBool *_retval NS_OUTPARAM) { return _to Test(aString, aRegEx, aFlags, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_TXIEXSLTREGEXFUNCTIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD Match(txIFunctionEvaluationContext *aContext, const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, txINodeSet **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Match(aContext, aString, aRegEx, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Replace(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, const nsAString & aReplace, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Replace(aString, aRegEx, aFlags, aReplace, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Test(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Test(aString, aRegEx, aFlags, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class txEXSLTRegExFunctions : public txIEXSLTRegExFunctions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_TXIEXSLTREGEXFUNCTIONS

  txEXSLTRegExFunctions();

private:
  ~txEXSLTRegExFunctions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(txEXSLTRegExFunctions, txIEXSLTRegExFunctions)

txEXSLTRegExFunctions::txEXSLTRegExFunctions()
{
  /* member initializers and constructor code */
}

txEXSLTRegExFunctions::~txEXSLTRegExFunctions()
{
  /* destructor code */
}

/* txINodeSet match (in txIFunctionEvaluationContext aContext, in DOMString aString, in DOMString aRegEx, in DOMString aFlags); */
NS_IMETHODIMP txEXSLTRegExFunctions::Match(txIFunctionEvaluationContext *aContext, const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, txINodeSet **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString replace (in DOMString aString, in DOMString aRegEx, in DOMString aFlags, in DOMString aReplace); */
NS_IMETHODIMP txEXSLTRegExFunctions::Replace(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, const nsAString & aReplace, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean test (in DOMString aString, in DOMString aRegEx, in DOMString aFlags); */
NS_IMETHODIMP txEXSLTRegExFunctions::Test(const nsAString & aString, const nsAString & aRegEx, const nsAString & aFlags, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_txIEXSLTRegExFunctions_h__ */
