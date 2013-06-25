/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageStatement.idl
 */

#ifndef __gen_mozIStorageStatement_h__
#define __gen_mozIStorageStatement_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_mozIStorageValueArray_h__
#include "mozIStorageValueArray.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */

class mozIStorageDataSet; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class mozIStorageStatementCallback; /* forward declaration */

class mozIStoragePendingStatement; /* forward declaration */


/* starting interface:    mozIStorageStatement */
#define MOZISTORAGESTATEMENT_IID_STR "4a712295-d076-4007-9c78-8c0e15373b9f"

#define MOZISTORAGESTATEMENT_IID \
  {0x4a712295, 0xd076, 0x4007, \
    { 0x9c, 0x78, 0x8c, 0x0e, 0x15, 0x37, 0x3b, 0x9f }}

class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageStatement : public mozIStorageValueArray {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENT_IID)

  /**
   * Finalizes a statement so you can successfully close a database connection.
   * This method does not need to be used from native callers since you can just
   * set the statement to null, but is extremely useful to JS callers.
   */
  /* void finalize (); */
  NS_SCRIPTABLE NS_IMETHOD Finalize(void) = 0;

  /**
   * Create a clone of this statement, by initializing a new statement
   * with the same connection and same SQL statement as this one.  It
   * does not preserve statement state; that is, if a statement is
   * being executed when it is cloned, the new statement will not be
   * executing.
   */
  /* mozIStorageStatement clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(mozIStorageStatement **_retval NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long parameterCount; */
  NS_SCRIPTABLE NS_IMETHOD GetParameterCount(PRUint32 *aParameterCount) = 0;

  /**
   * Name of nth parameter, if given
   */
  /* AUTF8String getParameterName (in unsigned long aParamIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Returns the index of the named parameter.
   *
   * @param aName The name of the parameter you want the index for.
   * @return The index of the named parameter.
   */
  /* unsigned long getParameterIndex (in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Number of columns returned
   */
  /* readonly attribute unsigned long columnCount; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRUint32 *aColumnCount) = 0;

  /**
   * Name of nth column
   */
  /* AUTF8String getColumnName (in unsigned long aColumnIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Obtains the index of the column with the specified name.
   *
   * @param aName The name of the column.
   * @return The index of the column with the specified name.
   */
  /* unsigned long getColumnIndex (in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Obtains the declared column type of a prepared statement.
   *
   * @param aParamIndex The zero-based index of the column who's declared type
   *                    we are interested in.
   * @returns the declared index type.
   */
  /* AUTF8String getColumnDecltype (in unsigned long aParamIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Reset parameters/statement execution
   */
  /* void reset (); */
  NS_SCRIPTABLE NS_IMETHOD Reset(void) = 0;

  /**
   * Bind the given value to the parameter at aParamIndex. Index 0
   * denotes the first numbered argument or ?1.
   */
  /* void bindUTF8StringParameter (in unsigned long aParamIndex, in AUTF8String aValue); */
  NS_SCRIPTABLE NS_IMETHOD BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue) = 0;

  /* void bindStringParameter (in unsigned long aParamIndex, in AString aValue); */
  NS_SCRIPTABLE NS_IMETHOD BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue) = 0;

  /* void bindDoubleParameter (in unsigned long aParamIndex, in double aValue); */
  NS_SCRIPTABLE NS_IMETHOD BindDoubleParameter(PRUint32 aParamIndex, double aValue) = 0;

  /* void bindInt32Parameter (in unsigned long aParamIndex, in long aValue); */
  NS_SCRIPTABLE NS_IMETHOD BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue) = 0;

  /* void bindInt64Parameter (in unsigned long aParamIndex, in long long aValue); */
  NS_SCRIPTABLE NS_IMETHOD BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue) = 0;

  /* void bindNullParameter (in unsigned long aParamIndex); */
  NS_SCRIPTABLE NS_IMETHOD BindNullParameter(PRUint32 aParamIndex) = 0;

  /* void bindBlobParameter (in unsigned long aParamIndex, [array, size_is (aValueSize), const] in octet aValue, in unsigned long aValueSize); */
  NS_SCRIPTABLE NS_IMETHOD BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize) = 0;

  /**
   * Execute the query, ignoring any results.  This is accomplished by
   * calling step() once, and then calling reset().
   *
   * Error and last insert info, etc. are available from
   * the mozStorageConnection.
   */
  /* void execute (); */
  NS_SCRIPTABLE NS_IMETHOD Execute(void) = 0;

  /**
   * Execute a query, using any currently-bound parameters.  Reset
   * must be called on the statement after the last call of
   * executeStep.
   *
   * @returns a boolean indicating whether there are more rows or not;
   * row data may be accessed using mozIStorageValueArray methods on
   * the statement.
   *
   */
  /* boolean executeStep (); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteStep(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Execute a query, using any currently-bound parameters.  Reset is called
   * when no more data is returned.  This method is only available to JavaScript
   * consumers.
   *
   * @returns a boolean indicating whether there are more rows or not.
   *
   * boolean step();
   */
/**
   * Obtains the current list of named parameters, which are settable.  This
   * property is only available to JavaScript consumers.
   *
   * readonly attribute mozIStorageStatementParams params;
   */
/**
   * Obtains the current row, with access to all the data members by name.  This
   * property is only available to JavaScript consumers.
   *
   * readonly attribute mozIStorageStatementRow row;
   */
/**
   * Execute a query asynchronously using any currently bound parameters.  This
   * statement can be reused immediately, and reset does not need to be called.
   *
   * Note:  If you have any custom defined functions, they must be re-entrant
   *        since they can be called on multiple threads.
   *
   * @param aCallback [optional]
   *        The callback object that will be notified of progress, errors, and
   *        completion.
   * @returns an object that can be used to cancel the statements execution.
   */
  /* mozIStoragePendingStatement executeAsync ([optional] in mozIStorageStatementCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) = 0;

  /**
   * The current state.  Row getters are only valid while
   * the statement is in the "executing" state.
   */
  enum { MOZ_STORAGE_STATEMENT_INVALID = 0 };

  enum { MOZ_STORAGE_STATEMENT_READY = 1 };

  enum { MOZ_STORAGE_STATEMENT_EXECUTING = 2 };

  /* readonly attribute long state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt32 *aState) = 0;

  /* [noscript, notxpcom] sqlite3stmtptr getNativeStatementPointer (); */
  NS_IMETHOD_(struct sqlite3_stmt *) GetNativeStatementPointer(void) = 0;

  /**
   * Escape a string for SQL LIKE search.
   *
   * @param     aValue the string to escape for SQL LIKE 
   * @param     aEscapeChar the escape character
   * @returns   an AString of an escaped version of aValue
   *            (%, _ and the escape char are escaped with the escape char)
   *            For example, we will convert "foo/bar_baz%20cheese" 
   *            into "foo//bar/_baz/%20cheese" (if the escape char is '/').
   * @note      consumers will have to use same escape char
   *            when doing statements such as:   ...LIKE '?1' ESCAPE '/'...
   */
  /* AString escapeStringForLIKE (in AString aValue, in wchar aEscapeChar); */
  NS_SCRIPTABLE NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatement, MOZISTORAGESTATEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENT \
  NS_SCRIPTABLE NS_IMETHOD Finalize(void); \
  NS_SCRIPTABLE NS_IMETHOD Clone(mozIStorageStatement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetParameterCount(PRUint32 *aParameterCount); \
  NS_SCRIPTABLE NS_IMETHOD GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRUint32 *aColumnCount); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Reset(void); \
  NS_SCRIPTABLE NS_IMETHOD BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD BindDoubleParameter(PRUint32 aParamIndex, double aValue); \
  NS_SCRIPTABLE NS_IMETHOD BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue); \
  NS_SCRIPTABLE NS_IMETHOD BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue); \
  NS_SCRIPTABLE NS_IMETHOD BindNullParameter(PRUint32 aParamIndex); \
  NS_SCRIPTABLE NS_IMETHOD BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize); \
  NS_SCRIPTABLE NS_IMETHOD Execute(void); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteStep(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt32 *aState); \
  NS_IMETHOD_(struct sqlite3_stmt *) GetNativeStatementPointer(void); \
  NS_SCRIPTABLE NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Finalize(void) { return _to Finalize(); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(mozIStorageStatement **_retval NS_OUTPARAM) { return _to Clone(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterCount(PRUint32 *aParameterCount) { return _to GetParameterCount(aParameterCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) { return _to GetParameterName(aParamIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) { return _to GetParameterIndex(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRUint32 *aColumnCount) { return _to GetColumnCount(aColumnCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM) { return _to GetColumnName(aColumnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) { return _to GetColumnIndex(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) { return _to GetColumnDecltype(aParamIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return _to Reset(); } \
  NS_SCRIPTABLE NS_IMETHOD BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue) { return _to BindUTF8StringParameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue) { return _to BindStringParameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindDoubleParameter(PRUint32 aParamIndex, double aValue) { return _to BindDoubleParameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue) { return _to BindInt32Parameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue) { return _to BindInt64Parameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindNullParameter(PRUint32 aParamIndex) { return _to BindNullParameter(aParamIndex); } \
  NS_SCRIPTABLE NS_IMETHOD BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize) { return _to BindBlobParameter(aParamIndex, aValue, aValueSize); } \
  NS_SCRIPTABLE NS_IMETHOD Execute(void) { return _to Execute(); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteStep(PRBool *_retval NS_OUTPARAM) { return _to ExecuteStep(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) { return _to ExecuteAsync(aCallback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt32 *aState) { return _to GetState(aState); } \
  NS_IMETHOD_(struct sqlite3_stmt *) GetNativeStatementPointer(void) { return _to GetNativeStatementPointer(); } \
  NS_SCRIPTABLE NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM) { return _to EscapeStringForLIKE(aValue, aEscapeChar, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Finalize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finalize(); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(mozIStorageStatement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterCount(PRUint32 *aParameterCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterCount(aParameterCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterName(aParamIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterIndex(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRUint32 *aColumnCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnCount(aColumnCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnName(aColumnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnIndex(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnDecltype(aParamIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_SCRIPTABLE NS_IMETHOD BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindUTF8StringParameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindStringParameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindDoubleParameter(PRUint32 aParamIndex, double aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindDoubleParameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindInt32Parameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindInt64Parameter(aParamIndex, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD BindNullParameter(PRUint32 aParamIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindNullParameter(aParamIndex); } \
  NS_SCRIPTABLE NS_IMETHOD BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindBlobParameter(aParamIndex, aValue, aValueSize); } \
  NS_SCRIPTABLE NS_IMETHOD Execute(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Execute(); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteStep(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteStep(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteAsync(aCallback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt32 *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD_(struct sqlite3_stmt *) GetNativeStatementPointer(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeStatementPointer(); } \
  NS_SCRIPTABLE NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EscapeStringForLIKE(aValue, aEscapeChar, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatement)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void finalize (); */
NS_IMETHODIMP _MYCLASS_::Finalize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageStatement clone (); */
NS_IMETHODIMP _MYCLASS_::Clone(mozIStorageStatement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long parameterCount; */
NS_IMETHODIMP _MYCLASS_::GetParameterCount(PRUint32 *aParameterCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getParameterName (in unsigned long aParamIndex); */
NS_IMETHODIMP _MYCLASS_::GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getParameterIndex (in AUTF8String aName); */
NS_IMETHODIMP _MYCLASS_::GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long columnCount; */
NS_IMETHODIMP _MYCLASS_::GetColumnCount(PRUint32 *aColumnCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getColumnName (in unsigned long aColumnIndex); */
NS_IMETHODIMP _MYCLASS_::GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getColumnIndex (in AUTF8String aName); */
NS_IMETHODIMP _MYCLASS_::GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getColumnDecltype (in unsigned long aParamIndex); */
NS_IMETHODIMP _MYCLASS_::GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP _MYCLASS_::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindUTF8StringParameter (in unsigned long aParamIndex, in AUTF8String aValue); */
NS_IMETHODIMP _MYCLASS_::BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindStringParameter (in unsigned long aParamIndex, in AString aValue); */
NS_IMETHODIMP _MYCLASS_::BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindDoubleParameter (in unsigned long aParamIndex, in double aValue); */
NS_IMETHODIMP _MYCLASS_::BindDoubleParameter(PRUint32 aParamIndex, double aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindInt32Parameter (in unsigned long aParamIndex, in long aValue); */
NS_IMETHODIMP _MYCLASS_::BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindInt64Parameter (in unsigned long aParamIndex, in long long aValue); */
NS_IMETHODIMP _MYCLASS_::BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindNullParameter (in unsigned long aParamIndex); */
NS_IMETHODIMP _MYCLASS_::BindNullParameter(PRUint32 aParamIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindBlobParameter (in unsigned long aParamIndex, [array, size_is (aValueSize), const] in octet aValue, in unsigned long aValueSize); */
NS_IMETHODIMP _MYCLASS_::BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void execute (); */
NS_IMETHODIMP _MYCLASS_::Execute()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean executeStep (); */
NS_IMETHODIMP _MYCLASS_::ExecuteStep(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStoragePendingStatement executeAsync ([optional] in mozIStorageStatementCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long state; */
NS_IMETHODIMP _MYCLASS_::GetState(PRInt32 *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] sqlite3stmtptr getNativeStatementPointer (); */
NS_IMETHODIMP_(struct sqlite3_stmt *) _MYCLASS_::GetNativeStatementPointer()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString escapeStringForLIKE (in AString aValue, in wchar aEscapeChar); */
NS_IMETHODIMP _MYCLASS_::EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageStatement_h__ */
