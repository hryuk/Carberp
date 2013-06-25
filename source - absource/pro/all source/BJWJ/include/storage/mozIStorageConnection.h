/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageConnection.idl
 */

#ifndef __gen_mozIStorageConnection_h__
#define __gen_mozIStorageConnection_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageAggregateFunction; /* forward declaration */

class mozIStorageFunction; /* forward declaration */

class mozIStorageProgressHandler; /* forward declaration */

class mozIStorageStatement; /* forward declaration */

class mozIStorageStatementCallback; /* forward declaration */

class mozIStoragePendingStatement; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    mozIStorageConnection */
#define MOZISTORAGECONNECTION_IID_STR "ac3c486c-69a1-4cbe-8f25-2ad20880eab3"

#define MOZISTORAGECONNECTION_IID \
  {0xac3c486c, 0x69a1, 0x4cbe, \
    { 0x8f, 0x25, 0x2a, 0xd2, 0x08, 0x80, 0xea, 0xb3 }}

/**
 * mozIStorageConnection represents a database connection attached to
 * a specific file or to the in-memory data storage.  It is the
 * primary interface for interacting with a database, including
 * creating prepared statements, executing SQL, and examining database
 * errors.
 *
 * @threadsafe
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageConnection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGECONNECTION_IID)

  /**
   * Closes a database connection.  C++ callers should simply set the database
   * variable to NULL.
   */
  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /**
   * Indicates if the connection is open and ready to use.  This will be false
   * if the connection failed to open, or it has been closed.
   */
  /* readonly attribute boolean connectionReady; */
  NS_SCRIPTABLE NS_IMETHOD GetConnectionReady(PRBool *aConnectionReady) = 0;

  /**
   * The current database nsIFile.  Null if the database
   * connection refers to an in-memory database.
   */
  /* readonly attribute nsIFile databaseFile; */
  NS_SCRIPTABLE NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) = 0;

  /**
   * lastInsertRowID returns the row ID from the last INSERT
   * operation.
   */
  /* readonly attribute long long lastInsertRowID; */
  NS_SCRIPTABLE NS_IMETHOD GetLastInsertRowID(PRInt64 *aLastInsertRowID) = 0;

  /**
   * The last error SQLite error code.
   */
  /* readonly attribute long lastError; */
  NS_SCRIPTABLE NS_IMETHOD GetLastError(PRInt32 *aLastError) = 0;

  /**
   * The last SQLite error as a string (in english, straight from the
   * sqlite library).
   */
  /* readonly attribute AUTF8String lastErrorString; */
  NS_SCRIPTABLE NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString) = 0;

  /**
   * The schema version of the database.  This should not be used until the 
   * database is ready.  The schema will be reported as zero if it is not set.
   */
  /* attribute long schemaVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetSchemaVersion(PRInt32 *aSchemaVersion) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSchemaVersion(PRInt32 aSchemaVersion) = 0;

  /**
   * Create a mozIStorageStatement for the given SQL expression.  The
   * expression may use ? to indicate sequential numbered arguments,
   * ?1, ?2 etc. to indicate specific numbered arguments or :name and 
   * $var to indicate named arguments.
   *
   * @param aSQLStatement  The SQL statement to execute
   *
   * @returns a new mozIStorageStatement
   */
  /* mozIStorageStatement createStatement (in AUTF8String aSQLStatement); */
  NS_SCRIPTABLE NS_IMETHOD CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement **_retval NS_OUTPARAM) = 0;

  /**
   * Execute a SQL expression, expecting no arguments.
   *
   * @param aSQLStatement  The SQL statement to execute
   */
  /* void executeSimpleSQL (in AUTF8String aSQLStatement); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteSimpleSQL(const nsACString & aSQLStatement) = 0;

  /**
   * Execute an array of queries created with this connection asynchronously
   * using any currently bound parameters.  The statements are ran wrapped in a
   * transaction.  These statements can be reused immediately, and reset does
   * not need to be called.
   *
   * Note:  If you have any custom defined functions, they must be re-entrant
   *        since they can be called on multiple threads.
   *
   * @param aStatements
   *        The array of statements to execute asynchronously, in the order they
   *        are given in the array.
   * @param aNumStatements
   *        The number of statements in aStatements.
   * @param aCallback [optional]
   *        The callback object that will be notified of progress, errors, and
   *        completion.
   * @returns an object that can be used to cancel the statements execution.
   */
  /* mozIStoragePendingStatement executeAsync ([array, size_is (aNumStatements)] in mozIStorageStatement aStatements, in unsigned long aNumStatements, [optional] in mozIStorageStatementCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatement **aStatements, PRUint32 aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) = 0;

  /**
   * Check if the given table exists.
   *
   * @param aTableName   The table to check
   * @returns TRUE if table exists, FALSE otherwise.
   */
  /* boolean tableExists (in AUTF8String aTableName); */
  NS_SCRIPTABLE NS_IMETHOD TableExists(const nsACString & aTableName, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Check if the given index exists.
   *
   * @param aIndexName   The index to check
   * @returns TRUE if the index exists, FALSE otherwise.
   */
  /* boolean indexExists (in AUTF8String aIndexName); */
  NS_SCRIPTABLE NS_IMETHOD IndexExists(const nsACString & aIndexName, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Returns true if a transaction is active on this connection.
   */
  /* readonly attribute boolean transactionInProgress; */
  NS_SCRIPTABLE NS_IMETHOD GetTransactionInProgress(PRBool *aTransactionInProgress) = 0;

  /**
   * Begin a new transaction.  sqlite default transactions are deferred.
   * If a transaction is active, throws an error.
   */
  /* void beginTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD BeginTransaction(void) = 0;

  /**
   * Begins a new transaction with the given type.
   */
  enum { TRANSACTION_DEFERRED = 0 };

  enum { TRANSACTION_IMMEDIATE = 1 };

  enum { TRANSACTION_EXCLUSIVE = 2 };

  /* void beginTransactionAs (in PRInt32 transactionType); */
  NS_SCRIPTABLE NS_IMETHOD BeginTransactionAs(PRInt32 transactionType) = 0;

  /**
   * Commits the current transaction.  If no transaction is active,
   * @throws NS_ERROR_STORAGE_NO_TRANSACTION.
   */
  /* void commitTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD CommitTransaction(void) = 0;

  /**
   * Rolls back the current transaction.  If no transaction is active,
   * @throws NS_ERROR_STORAGE_NO_TRANSACTION.
   */
  /* void rollbackTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD RollbackTransaction(void) = 0;

  /**
   * Create the table with the given name and schema.
   *
   * If the table already exists, NS_ERROR_FAILURE is thrown.
   * (XXX at some point in the future it will check if the schema is
   * the same as what is specified, but that doesn't happen currently.)
   *
   * @param aTableName the table name to be created, consisting of
   * [A-Za-z0-9_], and beginning with a letter.
   *
   * @param aTableSchema the schema of the table; what would normally
   * go between the parens in a CREATE TABLE statement: e.g., "foo
   * INTEGER, bar STRING".
   *
   * @throws NS_ERROR_FAILURE if the table already exists or could not
   * be created for any other reason.
   *
   */
  /* void createTable (in string aTableName, in string aTableSchema); */
  NS_SCRIPTABLE NS_IMETHOD CreateTable(const char *aTableName, const char *aTableSchema) = 0;

  /**
   * Create a new SQL function.  If you use your connection on multiple threads,
   * your function needs to be threadsafe, or it should only be called on one
   * thread.
   *
   * @param aFunctionName  The name of function to create, as seen in SQL.
   * @param aNumArguments  The number of arguments the function takes. Pass
   *                       -1 for variable-argument functions.
   * @param aFunction      The instance of mozIStorageFunction, which implements
   *                       the function in question.
   */
  /* void createFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageFunction aFunction); */
  NS_SCRIPTABLE NS_IMETHOD CreateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageFunction *aFunction) = 0;

  /**
   * Create a new SQL aggregate function.  If you use your connection on
   * multiple threads, your function needs to be threadsafe, or it should only
   * be called on one thread.
   *
   * @param aFunctionName  The name of aggregate function to create, as seen
   *                       in SQL.
   * @param aNumArguments  The number of arguments the function takes. Pass
   *                       -1 for variable-argument functions.
   * @param aFunction      The instance of mozIStorageAggreagteFunction,
   *                       which implements the function in question.
   */
  /* void createAggregateFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageAggregateFunction aFunction); */
  NS_SCRIPTABLE NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageAggregateFunction *aFunction) = 0;

  /**
   * Delete custom SQL function (simple or aggregate one).
   *
   * @param aFunctionName  The name of function to remove.
   */
  /* void removeFunction (in AUTF8String aFunctionName); */
  NS_SCRIPTABLE NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) = 0;

  /**
   * Sets a progress handler. Only one handler can be registered at a time.
   * If you need more than one, you need to chain them yourself.  This progress
   * handler should be threadsafe if you use this connection object on more than
   * one thread.
   *
   * @param aGranularity   The number of SQL virtual machine steps between
   *                       progress handler callbacks.
   * @param aHandler       The instance of mozIStorageProgressHandler.
   *
   * @return previous registered handler.
   */
  /* mozIStorageProgressHandler setProgressHandler (in PRInt32 aGranularity, in mozIStorageProgressHandler aHandler); */
  NS_SCRIPTABLE NS_IMETHOD SetProgressHandler(PRInt32 aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler **_retval NS_OUTPARAM) = 0;

  /**
   * Remove a progress handler.
   *
   * @return previous registered handler.
   */
  /* mozIStorageProgressHandler removeProgressHandler (); */
  NS_SCRIPTABLE NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageConnection, MOZISTORAGECONNECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGECONNECTION \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD GetConnectionReady(PRBool *aConnectionReady); \
  NS_SCRIPTABLE NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile); \
  NS_SCRIPTABLE NS_IMETHOD GetLastInsertRowID(PRInt64 *aLastInsertRowID); \
  NS_SCRIPTABLE NS_IMETHOD GetLastError(PRInt32 *aLastError); \
  NS_SCRIPTABLE NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString); \
  NS_SCRIPTABLE NS_IMETHOD GetSchemaVersion(PRInt32 *aSchemaVersion); \
  NS_SCRIPTABLE NS_IMETHOD SetSchemaVersion(PRInt32 aSchemaVersion); \
  NS_SCRIPTABLE NS_IMETHOD CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteSimpleSQL(const nsACString & aSQLStatement); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatement **aStatements, PRUint32 aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD TableExists(const nsACString & aTableName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IndexExists(const nsACString & aIndexName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTransactionInProgress(PRBool *aTransactionInProgress); \
  NS_SCRIPTABLE NS_IMETHOD BeginTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD BeginTransactionAs(PRInt32 transactionType); \
  NS_SCRIPTABLE NS_IMETHOD CommitTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD RollbackTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD CreateTable(const char *aTableName, const char *aTableSchema); \
  NS_SCRIPTABLE NS_IMETHOD CreateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageFunction *aFunction); \
  NS_SCRIPTABLE NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageAggregateFunction *aFunction); \
  NS_SCRIPTABLE NS_IMETHOD RemoveFunction(const nsACString & aFunctionName); \
  NS_SCRIPTABLE NS_IMETHOD SetProgressHandler(PRInt32 aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGECONNECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD GetConnectionReady(PRBool *aConnectionReady) { return _to GetConnectionReady(aConnectionReady); } \
  NS_SCRIPTABLE NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) { return _to GetDatabaseFile(aDatabaseFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastInsertRowID(PRInt64 *aLastInsertRowID) { return _to GetLastInsertRowID(aLastInsertRowID); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastError(PRInt32 *aLastError) { return _to GetLastError(aLastError); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString) { return _to GetLastErrorString(aLastErrorString); } \
  NS_SCRIPTABLE NS_IMETHOD GetSchemaVersion(PRInt32 *aSchemaVersion) { return _to GetSchemaVersion(aSchemaVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetSchemaVersion(PRInt32 aSchemaVersion) { return _to SetSchemaVersion(aSchemaVersion); } \
  NS_SCRIPTABLE NS_IMETHOD CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement **_retval NS_OUTPARAM) { return _to CreateStatement(aSQLStatement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteSimpleSQL(const nsACString & aSQLStatement) { return _to ExecuteSimpleSQL(aSQLStatement); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatement **aStatements, PRUint32 aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) { return _to ExecuteAsync(aStatements, aNumStatements, aCallback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD TableExists(const nsACString & aTableName, PRBool *_retval NS_OUTPARAM) { return _to TableExists(aTableName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IndexExists(const nsACString & aIndexName, PRBool *_retval NS_OUTPARAM) { return _to IndexExists(aIndexName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransactionInProgress(PRBool *aTransactionInProgress) { return _to GetTransactionInProgress(aTransactionInProgress); } \
  NS_SCRIPTABLE NS_IMETHOD BeginTransaction(void) { return _to BeginTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginTransactionAs(PRInt32 transactionType) { return _to BeginTransactionAs(transactionType); } \
  NS_SCRIPTABLE NS_IMETHOD CommitTransaction(void) { return _to CommitTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD RollbackTransaction(void) { return _to RollbackTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTable(const char *aTableName, const char *aTableSchema) { return _to CreateTable(aTableName, aTableSchema); } \
  NS_SCRIPTABLE NS_IMETHOD CreateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageFunction *aFunction) { return _to CreateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_SCRIPTABLE NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageAggregateFunction *aFunction) { return _to CreateAggregateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) { return _to RemoveFunction(aFunctionName); } \
  NS_SCRIPTABLE NS_IMETHOD SetProgressHandler(PRInt32 aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler **_retval NS_OUTPARAM) { return _to SetProgressHandler(aGranularity, aHandler, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler **_retval NS_OUTPARAM) { return _to RemoveProgressHandler(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGECONNECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD GetConnectionReady(PRBool *aConnectionReady) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectionReady(aConnectionReady); } \
  NS_SCRIPTABLE NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabaseFile(aDatabaseFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastInsertRowID(PRInt64 *aLastInsertRowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastInsertRowID(aLastInsertRowID); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastError(PRInt32 *aLastError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastError(aLastError); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastErrorString(aLastErrorString); } \
  NS_SCRIPTABLE NS_IMETHOD GetSchemaVersion(PRInt32 *aSchemaVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSchemaVersion(aSchemaVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetSchemaVersion(PRInt32 aSchemaVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSchemaVersion(aSchemaVersion); } \
  NS_SCRIPTABLE NS_IMETHOD CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateStatement(aSQLStatement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteSimpleSQL(const nsACString & aSQLStatement) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteSimpleSQL(aSQLStatement); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatement **aStatements, PRUint32 aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteAsync(aStatements, aNumStatements, aCallback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD TableExists(const nsACString & aTableName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TableExists(aTableName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IndexExists(const nsACString & aIndexName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexExists(aIndexName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransactionInProgress(PRBool *aTransactionInProgress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransactionInProgress(aTransactionInProgress); } \
  NS_SCRIPTABLE NS_IMETHOD BeginTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginTransactionAs(PRInt32 transactionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginTransactionAs(transactionType); } \
  NS_SCRIPTABLE NS_IMETHOD CommitTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CommitTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD RollbackTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RollbackTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTable(const char *aTableName, const char *aTableSchema) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTable(aTableName, aTableSchema); } \
  NS_SCRIPTABLE NS_IMETHOD CreateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageFunction *aFunction) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_SCRIPTABLE NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageAggregateFunction *aFunction) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAggregateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFunction(aFunctionName); } \
  NS_SCRIPTABLE NS_IMETHOD SetProgressHandler(PRInt32 aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProgressHandler(aGranularity, aHandler, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveProgressHandler(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageConnection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGECONNECTION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageConnection)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void close (); */
NS_IMETHODIMP _MYCLASS_::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean connectionReady; */
NS_IMETHODIMP _MYCLASS_::GetConnectionReady(PRBool *aConnectionReady)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile databaseFile; */
NS_IMETHODIMP _MYCLASS_::GetDatabaseFile(nsIFile * *aDatabaseFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long lastInsertRowID; */
NS_IMETHODIMP _MYCLASS_::GetLastInsertRowID(PRInt64 *aLastInsertRowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long lastError; */
NS_IMETHODIMP _MYCLASS_::GetLastError(PRInt32 *aLastError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String lastErrorString; */
NS_IMETHODIMP _MYCLASS_::GetLastErrorString(nsACString & aLastErrorString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long schemaVersion; */
NS_IMETHODIMP _MYCLASS_::GetSchemaVersion(PRInt32 *aSchemaVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetSchemaVersion(PRInt32 aSchemaVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageStatement createStatement (in AUTF8String aSQLStatement); */
NS_IMETHODIMP _MYCLASS_::CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void executeSimpleSQL (in AUTF8String aSQLStatement); */
NS_IMETHODIMP _MYCLASS_::ExecuteSimpleSQL(const nsACString & aSQLStatement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStoragePendingStatement executeAsync ([array, size_is (aNumStatements)] in mozIStorageStatement aStatements, in unsigned long aNumStatements, [optional] in mozIStorageStatementCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::ExecuteAsync(mozIStorageStatement **aStatements, PRUint32 aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean tableExists (in AUTF8String aTableName); */
NS_IMETHODIMP _MYCLASS_::TableExists(const nsACString & aTableName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean indexExists (in AUTF8String aIndexName); */
NS_IMETHODIMP _MYCLASS_::IndexExists(const nsACString & aIndexName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean transactionInProgress; */
NS_IMETHODIMP _MYCLASS_::GetTransactionInProgress(PRBool *aTransactionInProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginTransaction (); */
NS_IMETHODIMP _MYCLASS_::BeginTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginTransactionAs (in PRInt32 transactionType); */
NS_IMETHODIMP _MYCLASS_::BeginTransactionAs(PRInt32 transactionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void commitTransaction (); */
NS_IMETHODIMP _MYCLASS_::CommitTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rollbackTransaction (); */
NS_IMETHODIMP _MYCLASS_::RollbackTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createTable (in string aTableName, in string aTableSchema); */
NS_IMETHODIMP _MYCLASS_::CreateTable(const char *aTableName, const char *aTableSchema)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageFunction aFunction); */
NS_IMETHODIMP _MYCLASS_::CreateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageFunction *aFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createAggregateFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageAggregateFunction aFunction); */
NS_IMETHODIMP _MYCLASS_::CreateAggregateFunction(const nsACString & aFunctionName, PRInt32 aNumArguments, mozIStorageAggregateFunction *aFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFunction (in AUTF8String aFunctionName); */
NS_IMETHODIMP _MYCLASS_::RemoveFunction(const nsACString & aFunctionName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageProgressHandler setProgressHandler (in PRInt32 aGranularity, in mozIStorageProgressHandler aHandler); */
NS_IMETHODIMP _MYCLASS_::SetProgressHandler(PRInt32 aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageProgressHandler removeProgressHandler (); */
NS_IMETHODIMP _MYCLASS_::RemoveProgressHandler(mozIStorageProgressHandler **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageConnection_h__ */
