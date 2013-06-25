/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageStatementCallback.idl
 */

#ifndef __gen_mozIStorageStatementCallback_h__
#define __gen_mozIStorageStatementCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageResultSet; /* forward declaration */

class mozIStorageError; /* forward declaration */


/* starting interface:    mozIStorageStatementCallback */
#define MOZISTORAGESTATEMENTCALLBACK_IID_STR "29383d00-d8c4-4ddd-9f8b-c2feb0f2fcfa"

#define MOZISTORAGESTATEMENTCALLBACK_IID \
  {0x29383d00, 0xd8c4, 0x4ddd, \
    { 0x9f, 0x8b, 0xc2, 0xfe, 0xb0, 0xf2, 0xfc, 0xfa }}

class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageStatementCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENTCALLBACK_IID)

  /**
   * Called when some result is obtained from the database.  This function can
   * be called more than once with a different storageIResultSet each time for
   * any given asynchronous statement.
   *
   * @param aResultSet
   *        The result set containing the data from the database.
   */
  /* void handleResult (in mozIStorageResultSet aResultSet); */
  NS_SCRIPTABLE NS_IMETHOD HandleResult(mozIStorageResultSet *aResultSet) = 0;

  /**
   * Called when some error occurs while executing the statement.  This function
   * may be called more than once with a different storageIError each time for
   * any given asynchronous statement.
   *
   * @param aError
   *        An object containing information about the error.
   */
  /* void handleError (in mozIStorageError aError); */
  NS_SCRIPTABLE NS_IMETHOD HandleError(mozIStorageError *aError) = 0;

  /**
   * Called when the statement has finished executing.  This function will only
   * be called once for any given asynchronous statement.
   *
   * @param aReason
   *        Indicates if the statement is no longer executing because it either
   *        finished (REASON_FINISHED), was canceled (REASON_CANCELED), or
   *        a fatal error occurred (REASON_ERROR).
   */
  enum { REASON_FINISHED = 0U };

  enum { REASON_CANCELED = 1U };

  enum { REASON_ERROR = 2U };

  /* void handleCompletion (in unsigned short aReason); */
  NS_SCRIPTABLE NS_IMETHOD HandleCompletion(PRUint16 aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatementCallback, MOZISTORAGESTATEMENTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENTCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD HandleResult(mozIStorageResultSet *aResultSet); \
  NS_SCRIPTABLE NS_IMETHOD HandleError(mozIStorageError *aError); \
  NS_SCRIPTABLE NS_IMETHOD HandleCompletion(PRUint16 aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENTCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleResult(mozIStorageResultSet *aResultSet) { return _to HandleResult(aResultSet); } \
  NS_SCRIPTABLE NS_IMETHOD HandleError(mozIStorageError *aError) { return _to HandleError(aError); } \
  NS_SCRIPTABLE NS_IMETHOD HandleCompletion(PRUint16 aReason) { return _to HandleCompletion(aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENTCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleResult(mozIStorageResultSet *aResultSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleResult(aResultSet); } \
  NS_SCRIPTABLE NS_IMETHOD HandleError(mozIStorageError *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleError(aError); } \
  NS_SCRIPTABLE NS_IMETHOD HandleCompletion(PRUint16 aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCompletion(aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatementCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENTCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatementCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void handleResult (in mozIStorageResultSet aResultSet); */
NS_IMETHODIMP _MYCLASS_::HandleResult(mozIStorageResultSet *aResultSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleError (in mozIStorageError aError); */
NS_IMETHODIMP _MYCLASS_::HandleError(mozIStorageError *aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleCompletion (in unsigned short aReason); */
NS_IMETHODIMP _MYCLASS_::HandleCompletion(PRUint16 aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageStatementCallback_h__ */
