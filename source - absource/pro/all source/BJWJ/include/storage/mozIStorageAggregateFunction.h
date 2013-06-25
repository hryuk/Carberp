/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageAggregateFunction.idl
 */

#ifndef __gen_mozIStorageAggregateFunction_h__
#define __gen_mozIStorageAggregateFunction_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */

class mozIStorageValueArray; /* forward declaration */

class nsIArray; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    mozIStorageAggregateFunction */
#define MOZISTORAGEAGGREGATEFUNCTION_IID_STR "763217b7-3123-11da-918d-000347412e16"

#define MOZISTORAGEAGGREGATEFUNCTION_IID \
  {0x763217b7, 0x3123, 0x11da, \
    { 0x91, 0x8d, 0x00, 0x03, 0x47, 0x41, 0x2e, 0x16 }}

/**
 * mozIStorageAggregateFunction represents aggregate SQL function.
 * Common examples of aggregate functions are SUM() and COUNT().
 *
 * An aggregate function calculates one result for a given set of data, where
 * a set of data is a group of tuples. There can be one group
 * per request or many of them, if GROUP BY clause is used or not.
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageAggregateFunction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEAGGREGATEFUNCTION_IID)

  /**
   * onStep is called when next value should be passed to
   * a custom function.
   * 
   * @param aFunctionArguments    The arguments passed in to the function
   */
  /* void onStep (in mozIStorageValueArray aFunctionArguments); */
  NS_SCRIPTABLE NS_IMETHOD OnStep(mozIStorageValueArray *aFunctionArguments) = 0;

  /**
   * Called when all tuples in a group have been processed and the engine
   * needs the aggregate function's value.
   *
   * @returns aggregate result as Variant.
   */
  /* nsIVariant onFinal (); */
  NS_SCRIPTABLE NS_IMETHOD OnFinal(nsIVariant **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageAggregateFunction, MOZISTORAGEAGGREGATEFUNCTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEAGGREGATEFUNCTION \
  NS_SCRIPTABLE NS_IMETHOD OnStep(mozIStorageValueArray *aFunctionArguments); \
  NS_SCRIPTABLE NS_IMETHOD OnFinal(nsIVariant **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEAGGREGATEFUNCTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStep(mozIStorageValueArray *aFunctionArguments) { return _to OnStep(aFunctionArguments); } \
  NS_SCRIPTABLE NS_IMETHOD OnFinal(nsIVariant **_retval NS_OUTPARAM) { return _to OnFinal(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEAGGREGATEFUNCTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStep(mozIStorageValueArray *aFunctionArguments) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStep(aFunctionArguments); } \
  NS_SCRIPTABLE NS_IMETHOD OnFinal(nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnFinal(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageAggregateFunction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEAGGREGATEFUNCTION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageAggregateFunction)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onStep (in mozIStorageValueArray aFunctionArguments); */
NS_IMETHODIMP _MYCLASS_::OnStep(mozIStorageValueArray *aFunctionArguments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant onFinal (); */
NS_IMETHODIMP _MYCLASS_::OnFinal(nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageAggregateFunction_h__ */
