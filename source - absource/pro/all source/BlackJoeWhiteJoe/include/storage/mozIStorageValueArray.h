/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageValueArray.idl
 */

#ifndef __gen_mozIStorageValueArray_h__
#define __gen_mozIStorageValueArray_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIStorageValueArray */
#define MOZISTORAGEVALUEARRAY_IID_STR "07b5b93e-113c-4150-863c-d247b003a55d"

#define MOZISTORAGEVALUEARRAY_IID \
  {0x07b5b93e, 0x113c, 0x4150, \
    { 0x86, 0x3c, 0xd2, 0x47, 0xb0, 0x03, 0xa5, 0x5d }}

/**
 * mozIStorageValueArray wraps an array of SQL values,
 * such as a single database row.
 */
class NS_SCRIPTABLE mozIStorageValueArray : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEVALUEARRAY_IID)

  /**
   * These type values are returned by getTypeOfIndex
   * to indicate what type of value is present at
   * a given column.
   */
  enum { VALUE_TYPE_NULL = 0 };

  enum { VALUE_TYPE_INTEGER = 1 };

  enum { VALUE_TYPE_FLOAT = 2 };

  enum { VALUE_TYPE_TEXT = 3 };

  enum { VALUE_TYPE_BLOB = 4 };

  /**
   * numEntries
   *
   * number of entries in the array (each corresponding to a column
   * in the database row)
   */
  /* readonly attribute unsigned long numEntries; */
  NS_SCRIPTABLE NS_IMETHOD GetNumEntries(PRUint32 *aNumEntries) = 0;

  /**
   * Returns the type of the value at the given column index;
   * one of VALUE_TYPE_NULL, VALUE_TYPE_INTEGER, VALUE_TYPE_FLOAT,
   * VALUE_TYPE_TEXT, VALUE_TYPE_BLOB.
   */
  /* long getTypeOfIndex (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Obtain a value for the given entry (column) index.
   * Due to SQLite's type conversion rules, any of these are valid
   * for any column regardless of the column's data type.  However,
   * if the specific type matters, getTypeOfIndex should be used
   * first to identify the column type, and then the appropriate
   * get method should be called.
   *
   * If you ask for a string value for a NULL column, you will get an empty
   * string with IsVoid set to distinguish it from an explicitly set empty
   * string.
   */
  /* long getInt32 (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long long getInt64 (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM) = 0;

  /* double getDouble (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM) = 0;

  /* AUTF8String getUTF8String (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM) = 0;

  /* AString getString (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM) = 0;

  /* void getBlob (in unsigned long aIndex, out unsigned long aDataSize, [array, size_is (aDataSize)] out octet aData); */
  NS_SCRIPTABLE NS_IMETHOD GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) = 0;

  /* boolean getIsNull (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Returns a shared string pointer
   */
  /* [noscript] void getSharedUTF8String (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out string aResult); */
  NS_IMETHOD GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM) = 0;

  /* [noscript] void getSharedString (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out wstring aResult); */
  NS_IMETHOD GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM) = 0;

  /* [noscript] void getSharedBlob (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out octetPtr aResult); */
  NS_IMETHOD GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 * *aResult NS_OUTPARAM) = 0;

  /**
   * Getters for native code that return their values as
   * the return type, for convenience and sanity.
   *
   * Not virtual; no vtable bloat.
   */
  inline PRInt32 AsInt32(PRUint32 idx) {
    PRInt32 v;
    GetInt32(idx, &v);
    return v;
  }
  inline PRInt64 AsInt64(PRUint32 idx) {
    PRInt64 v;
    GetInt64(idx, &v);
    return v;
  }
  inline double AsDouble(PRUint32 idx) {
    double v;
    GetDouble(idx, &v);
    return v;
  }
  inline const char* AsSharedUTF8String(PRUint32 idx, PRUint32 *len) {
    const char *str = nsnull;
    GetSharedUTF8String(idx, len, &str);
    return str;
  }
  inline const PRUnichar* AsSharedWString(PRUint32 idx, PRUint32 *len) {
    const PRUnichar *str = nsnull;
    GetSharedString(idx, len, &str);
    return str;
  }
  inline const PRUint8* AsSharedBlob(PRUint32 idx, PRUint32 *len) {
    const PRUint8 *blob = nsnull;
    GetSharedBlob(idx, len, &blob);
    return blob;
  }
  inline PRBool IsNull(PRUint32 idx) {
    PRBool b = PR_FALSE;
    GetIsNull(idx, &b);
    return b;
  }
};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageValueArray, MOZISTORAGEVALUEARRAY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEVALUEARRAY \
  NS_SCRIPTABLE NS_IMETHOD GetNumEntries(PRUint32 *aNumEntries); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM); \
  NS_IMETHOD GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM); \
  NS_IMETHOD GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 * *aResult NS_OUTPARAM); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEVALUEARRAY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumEntries(PRUint32 *aNumEntries) { return _to GetNumEntries(aNumEntries); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetTypeOfIndex(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetInt32(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return _to GetInt64(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM) { return _to GetDouble(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM) { return _to GetUTF8String(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM) { return _to GetString(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) { return _to GetBlob(aIndex, aDataSize, aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM) { return _to GetIsNull(aIndex, _retval); } \
  NS_IMETHOD GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM) { return _to GetSharedUTF8String(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM) { return _to GetSharedString(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 * *aResult NS_OUTPARAM) { return _to GetSharedBlob(aIndex, aLength, aResult); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEVALUEARRAY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumEntries(PRUint32 *aNumEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumEntries(aNumEntries); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeOfIndex(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt32(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt64(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDouble(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUTF8String(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetString(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlob(aIndex, aDataSize, aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNull(aIndex, _retval); } \
  NS_IMETHOD GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedUTF8String(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedString(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 * *aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedBlob(aIndex, aLength, aResult); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageValueArray
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEVALUEARRAY

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageValueArray)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute unsigned long numEntries; */
NS_IMETHODIMP _MYCLASS_::GetNumEntries(PRUint32 *aNumEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getTypeOfIndex (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getInt32 (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long getInt64 (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double getDouble (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getUTF8String (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getString (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBlob (in unsigned long aIndex, out unsigned long aDataSize, [array, size_is (aDataSize)] out octet aData); */
NS_IMETHODIMP _MYCLASS_::GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getIsNull (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getSharedUTF8String (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out string aResult); */
NS_IMETHODIMP _MYCLASS_::GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getSharedString (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out wstring aResult); */
NS_IMETHODIMP _MYCLASS_::GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getSharedBlob (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out octetPtr aResult); */
NS_IMETHODIMP _MYCLASS_::GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 * *aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageValueArray_h__ */
