/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageService.idl
 */

#ifndef __gen_mozIStorageService_h__
#define __gen_mozIStorageService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    mozIStorageService */
#define MOZISTORAGESERVICE_IID_STR "fe8e95cb-b377-4c8d-bccb-d9198c67542b"

#define MOZISTORAGESERVICE_IID \
  {0xfe8e95cb, 0xb377, 0x4c8d, \
    { 0xbc, 0xcb, 0xd9, 0x19, 0x8c, 0x67, 0x54, 0x2b }}

/**
 * The mozIStorageService interface is intended to be implemented by
 * a service that can create storage connections (mozIStorageConnection)
 * to either a well-known profile database or to a specific database file.
 *
 * This is the only way to open a database connection.
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESERVICE_IID)

  /**
   * Get a connection to a named special database storage.
   *
   * @param aStorageKey a string key identifying the type of storage
   * requested.  Valid values include: "profile", "memory".
   *
   * @see openDatabase for restrictions on how database connections may be
   * used. For the profile database, you should only access it from the main
   * thread since other callers may also have connections.
   *
   * @returns a new mozIStorageConnection for the requested
   * storage database.
   *
   * @throws NS_ERROR_INVALID_ARG if aStorageKey is invalid.
   */
  /* mozIStorageConnection openSpecialDatabase (in string aStorageKey); */
  NS_SCRIPTABLE NS_IMETHOD OpenSpecialDatabase(const char *aStorageKey, mozIStorageConnection **_retval NS_OUTPARAM) = 0;

  /**
   * Open a connection to the specified file.
   *
   * Consumers should check mozIStorageConnection::connectionReady to ensure
   * that they can use the database.  If this value is false, it is strongly
   * recommended that the database be backed up with
   * mozIStorageConnection::backupDB so user data is not lost.
   *
   * ==========
   *   DANGER
   * ==========
   *
   * If you have more than one connection to a file, you MUST use the EXACT
   * SAME NAME for the file each time, including case. The sqlite code uses
   * a simple string compare to see if there is already a connection. Opening
   * a connection to "Foo.sqlite" and "foo.sqlite" will CORRUPT YOUR DATABASE.
   *
   * The connection object returned by this function is not threadsafe. You must
   * use it only from the thread you created it from.
   *
   * If your database contains virtual tables (f.e. for full-text indexes), you
   * must open it with openUnsharedDatabase, as those tables are incompatible
   * with a shared cache.  If you attempt to use this method to open a database
   * containing virtual tables, it will think the database is corrupted and
   * throw NS_ERROR_FILE_CORRUPTED.
   *
   * @param aDatabaseFile
   *        A nsIFile that represents the database that is to be opened..
   *
   * @returns a mozIStorageConnection for the requested database file.
   *
   * @throws NS_ERROR_OUT_OF_MEMORY
   *         If allocating a new storage object fails.
   * @throws NS_ERROR_FILE_CORRUPTED
   *         If the database file is corrupted.
   */
  /* mozIStorageConnection openDatabase (in nsIFile aDatabaseFile); */
  NS_SCRIPTABLE NS_IMETHOD OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM) = 0;

  /**
   * Open a connection to the specified file that doesn't share a sqlite cache.
   *
   * Each connection uses its own sqlite cache, which is inefficient, so you
   * should use openDatabase instead of this method unless you need a feature
   * of SQLite that is incompatible with a shared cache, like virtual table
   * and full text indexing support.
   *
   * Consumers should check mozIStorageConnection::connectionReady to ensure
   * that they can use the database.  If this value is false, it is strongly
   * recommended that the database be backed up with
   * mozIStorageConnection::backupDB so user data is not lost.
   *
   * ==========
   *   DANGER
   * ==========
   *
   * If you have more than one connection to a file, you MUST use the EXACT
   * SAME NAME for the file each time, including case. The sqlite code uses
   * a simple string compare to see if there is already a connection. Opening
   * a connection to "Foo.sqlite" and "foo.sqlite" will CORRUPT YOUR DATABASE.
   *
   * The connection object returned by this function is not threadsafe. You must
   * use it only from the thread you created it from.
   *
   * @param aDatabaseFile
   *        A nsIFile that represents the database that is to be opened..
   *
   * @returns a mozIStorageConnection for the requested database file.
   *
   * @throws NS_ERROR_OUT_OF_MEMORY
   *         If allocating a new storage object fails.
   * @throws NS_ERROR_FILE_CORRUPTED
   *         If the database file is corrupted.
   */
  /* mozIStorageConnection openUnsharedDatabase (in nsIFile aDatabaseFile); */
  NS_SCRIPTABLE NS_IMETHOD OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM) = 0;

  /**
   * Copies the specified database file to the specified parent directory with
   * the specified file name.  If the parent directory is not specified, it
   * places the backup in the same directory as the current file.  This function
   * ensures that the file being created is unique.
   *
   * @param aDBFile
   *        The database file that will be backed up.
   * @param aBackupFileName
   *        The name of the new backup file to create.
   * @param [optional] aBackupParentDirectory
   *        The directory you'd like the backup file to be placed.
   * @return The nsIFile representing the backup file.
   */
  /* nsIFile backupDatabaseFile (in nsIFile aDBFile, in AString aBackupFileName, [optional] in nsIFile aBackupParentDirectory); */
  NS_SCRIPTABLE NS_IMETHOD BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageService, MOZISTORAGESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESERVICE \
  NS_SCRIPTABLE NS_IMETHOD OpenSpecialDatabase(const char *aStorageKey, mozIStorageConnection **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD OpenSpecialDatabase(const char *aStorageKey, mozIStorageConnection **_retval NS_OUTPARAM) { return _to OpenSpecialDatabase(aStorageKey, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM) { return _to OpenDatabase(aDatabaseFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM) { return _to OpenUnsharedDatabase(aDatabaseFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile **_retval NS_OUTPARAM) { return _to BackupDatabaseFile(aDBFile, aBackupFileName, aBackupParentDirectory, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD OpenSpecialDatabase(const char *aStorageKey, mozIStorageConnection **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenSpecialDatabase(aStorageKey, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDatabase(aDatabaseFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenUnsharedDatabase(aDatabaseFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->BackupDatabaseFile(aDBFile, aBackupFileName, aBackupParentDirectory, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* mozIStorageConnection openSpecialDatabase (in string aStorageKey); */
NS_IMETHODIMP _MYCLASS_::OpenSpecialDatabase(const char *aStorageKey, mozIStorageConnection **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageConnection openDatabase (in nsIFile aDatabaseFile); */
NS_IMETHODIMP _MYCLASS_::OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageConnection openUnsharedDatabase (in nsIFile aDatabaseFile); */
NS_IMETHODIMP _MYCLASS_::OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile backupDatabaseFile (in nsIFile aDBFile, in AString aBackupFileName, [optional] in nsIFile aBackupParentDirectory); */
NS_IMETHODIMP _MYCLASS_::BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define MOZ_STORAGE_MEMORY_STORAGE_KEY    "memory"
#define MOZ_STORAGE_PROFILE_STORAGE_KEY   "profile"

#endif /* __gen_mozIStorageService_h__ */
