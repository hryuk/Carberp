/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageError.idl
 */

#ifndef __gen_mozIStorageError_h__
#define __gen_mozIStorageError_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef ERROR
#undef ERROR
#endif

/* starting interface:    mozIStorageError */
#define MOZISTORAGEERROR_IID_STR "1f350f96-7023-434a-8864-40a1c493aac1"

#define MOZISTORAGEERROR_IID \
  {0x1f350f96, 0x7023, 0x434a, \
    { 0x88, 0x64, 0x40, 0xa1, 0xc4, 0x93, 0xaa, 0xc1 }}

class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageError : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEERROR_IID)

  /**
   * General SQL error or missing database.
   */
  enum { ERROR = 1 };

  /**
   * Internal logic error.
   */
  enum { INTERNAL = 2 };

  /**
   * Access permission denied.
   */
  enum { PERM = 3 };

  /**
   * A callback routine requested an abort.
   */
  enum { ABORT = 4 };

  /**
   * The database file is locked.
   */
  enum { BUSY = 5 };

  /**
   * A table in the database is locked.
   */
  enum { LOCKED = 6 };

  /**
   * An allocation failed.
   */
  enum { NOMEM = 7 };

  /**
   * Attempt to write to a readonly database.
   */
  enum { READONLY = 8 };

  /**
   * Operation was terminated by an interrupt.
   */
  enum { INTERRUPT = 9 };

  /**
   * Some kind of disk I/O error occurred.
   */
  enum { IOERR = 10 };

  /**
   * The database disk image is malformed.
   */
  enum { CORRUPT = 11 };

  /**
   * An insertion failed because the database is full.
   */
  enum { FULL = 13 };

  /**
   * Unable to open the database file.
   */
  enum { CANTOPEN = 14 };

  /**
   * The database is empty.
   */
  enum { EMPTY = 16 };

  /**
   * The database scheme changed.
   */
  enum { SCHEMA = 17 };

  /**
   * A string or blob exceeds the size limit.
   */
  enum { TOOBIG = 18 };

  /**
   * Abort due to a constraint violation.
   */
  enum { CONSTRAINT = 19 };

  /**
   * Data type mismatch.
   */
  enum { MISMATCH = 20 };

  /**
   * Library used incorrectly.
   */
  enum { MISUSE = 21 };

  /**
   * Uses OS features not supported on the host system.
   */
  enum { NOLFS = 22 };

  /**
   * Authorization denied.
   */
  enum { AUTH = 23 };

  /**
   * Auxiliary database format error.
   */
  enum { FORMAT = 24 };

  /**
   * File opened that is not a database file.
   */
  enum { NOTADB = 26 };

  /**
   * Indicates what type of error occurred.
   */
  /* readonly attribute long result; */
  NS_SCRIPTABLE NS_IMETHOD GetResult(PRInt32 *aResult) = 0;

  /**
   * An error string the gives more details, if available.
   */
  /* readonly attribute AUTF8String message; */
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsACString & aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageError, MOZISTORAGEERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEERROR \
  NS_SCRIPTABLE NS_IMETHOD GetResult(PRInt32 *aResult); \
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsACString & aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResult(PRInt32 *aResult) { return _to GetResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsACString & aMessage) { return _to GetMessage(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResult(PRInt32 *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsACString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEERROR

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageError)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute long result; */
NS_IMETHODIMP _MYCLASS_::GetResult(PRInt32 *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String message; */
NS_IMETHODIMP _MYCLASS_::GetMessage(nsACString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageError_h__ */
