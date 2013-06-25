/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageFunction.idl
 */

#ifndef __gen_mozIStorageFunction_h__
#define __gen_mozIStorageFunction_h__


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


/* starting interface:    mozIStorageFunction */
#define MOZISTORAGEFUNCTION_IID_STR "9ff02465-21cb-49f3-b975-7d5b38ceec73"

#define MOZISTORAGEFUNCTION_IID \
  {0x9ff02465, 0x21cb, 0x49f3, \
    { 0xb9, 0x75, 0x7d, 0x5b, 0x38, 0xce, 0xec, 0x73 }}

/**
 * mozIStorageFunction is to be implemented by storage consumers that
 * wish to receive callbacks during the request execution.
 *
 * SQL can apply functions to values from tables. Examples of
 * such functions are MIN(a1,a2) or SQRT(num). Many functions are
 * implemented in SQL engine.
 *
 * This interface allows consumers to implement their own,
 * problem-specific functions.
 * These functions can be called from triggers, too.
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageFunction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEFUNCTION_IID)

  /**
   * onFunctionCall is called when execution of a custom
   * function should occur.
   * 
   * @param aNumArguments         The number of arguments
   * @param aFunctionArguments    The arguments passed in to the function
   *
   * @returns any value as Variant type.
   */
  /* nsIVariant onFunctionCall (in mozIStorageValueArray aFunctionArguments); */
  NS_SCRIPTABLE NS_IMETHOD OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageFunction, MOZISTORAGEFUNCTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEFUNCTION \
  NS_SCRIPTABLE NS_IMETHOD OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEFUNCTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant **_retval NS_OUTPARAM) { return _to OnFunctionCall(aFunctionArguments, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEFUNCTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnFunctionCall(aFunctionArguments, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageFunction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEFUNCTION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageFunction)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* nsIVariant onFunctionCall (in mozIStorageValueArray aFunctionArguments); */
NS_IMETHODIMP _MYCLASS_::OnFunctionCall(mozIStorageValueArray *aFunctionArguments, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageFunction_h__ */
