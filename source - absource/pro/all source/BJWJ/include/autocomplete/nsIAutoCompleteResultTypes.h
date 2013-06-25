/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/autocomplete/public/nsIAutoCompleteResultTypes.idl
 */

#ifndef __gen_nsIAutoCompleteResultTypes_h__
#define __gen_nsIAutoCompleteResultTypes_h__


#ifndef __gen_nsIAutoCompleteResult_h__
#include "nsIAutoCompleteResult.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMdbTable; /* forward declaration */

class nsIMdbEnv; /* forward declaration */

class nsIMdbRow; /* forward declaration */

#include "mdb.h"

/* starting interface:    nsIAutoCompleteBaseResult */
#define NS_IAUTOCOMPLETEBASERESULT_IID_STR "e6396544-921d-4776-aa62-8bf2dc1ae058"

#define NS_IAUTOCOMPLETEBASERESULT_IID \
  {0xe6396544, 0x921d, 0x4776, \
    { 0xaa, 0x62, 0x8b, 0xf2, 0xdc, 0x1a, 0xe0, 0x58 }}

class NS_NO_VTABLE nsIAutoCompleteBaseResult : public nsIAutoCompleteResult {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETEBASERESULT_IID)

  /* void setSearchString (in AString searchString); */
  NS_IMETHOD SetSearchString(const nsAString & searchString) = 0;

  /* void setErrorDescription (in AString errorDescription); */
  NS_IMETHOD SetErrorDescription(const nsAString & errorDescription) = 0;

  /* void setDefaultIndex (in long defaultIndex); */
  NS_IMETHOD SetDefaultIndex(PRInt32 defaultIndex) = 0;

  /* void setSearchResult (in unsigned long searchResult); */
  NS_IMETHOD SetSearchResult(PRUint32 searchResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteBaseResult, NS_IAUTOCOMPLETEBASERESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETEBASERESULT \
  NS_IMETHOD SetSearchString(const nsAString & searchString); \
  NS_IMETHOD SetErrorDescription(const nsAString & errorDescription); \
  NS_IMETHOD SetDefaultIndex(PRInt32 defaultIndex); \
  NS_IMETHOD SetSearchResult(PRUint32 searchResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETEBASERESULT(_to) \
  NS_IMETHOD SetSearchString(const nsAString & searchString) { return _to SetSearchString(searchString); } \
  NS_IMETHOD SetErrorDescription(const nsAString & errorDescription) { return _to SetErrorDescription(errorDescription); } \
  NS_IMETHOD SetDefaultIndex(PRInt32 defaultIndex) { return _to SetDefaultIndex(defaultIndex); } \
  NS_IMETHOD SetSearchResult(PRUint32 searchResult) { return _to SetSearchResult(searchResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETEBASERESULT(_to) \
  NS_IMETHOD SetSearchString(const nsAString & searchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchString(searchString); } \
  NS_IMETHOD SetErrorDescription(const nsAString & errorDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetErrorDescription(errorDescription); } \
  NS_IMETHOD SetDefaultIndex(PRInt32 defaultIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultIndex(defaultIndex); } \
  NS_IMETHOD SetSearchResult(PRUint32 searchResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchResult(searchResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteBaseResult : public nsIAutoCompleteBaseResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETEBASERESULT

  nsAutoCompleteBaseResult();

private:
  ~nsAutoCompleteBaseResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoCompleteBaseResult, nsIAutoCompleteBaseResult)

nsAutoCompleteBaseResult::nsAutoCompleteBaseResult()
{
  /* member initializers and constructor code */
}

nsAutoCompleteBaseResult::~nsAutoCompleteBaseResult()
{
  /* destructor code */
}

/* void setSearchString (in AString searchString); */
NS_IMETHODIMP nsAutoCompleteBaseResult::SetSearchString(const nsAString & searchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setErrorDescription (in AString errorDescription); */
NS_IMETHODIMP nsAutoCompleteBaseResult::SetErrorDescription(const nsAString & errorDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDefaultIndex (in long defaultIndex); */
NS_IMETHODIMP nsAutoCompleteBaseResult::SetDefaultIndex(PRInt32 defaultIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSearchResult (in unsigned long searchResult); */
NS_IMETHODIMP nsAutoCompleteBaseResult::SetSearchResult(PRUint32 searchResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAutoCompleteMdbResult */
#define NS_IAUTOCOMPLETEMDBRESULT_IID_STR "f7e7b341-2d5c-4d04-9f51-496cb2ce178c"

#define NS_IAUTOCOMPLETEMDBRESULT_IID \
  {0xf7e7b341, 0x2d5c, 0x4d04, \
    { 0x9f, 0x51, 0x49, 0x6c, 0xb2, 0xce, 0x17, 0x8c }}

class NS_NO_VTABLE nsIAutoCompleteMdbResult : public nsIAutoCompleteBaseResult {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETEMDBRESULT_IID)

  enum { kUnicharType = 0 };

  enum { kCharType = 1 };

  enum { kIntType = 2 };

  /* void init (in nsIMdbEnv env, in nsIMdbTable table); */
  NS_IMETHOD Init(nsIMdbEnv *env, nsIMdbTable *table) = 0;

  /* void setTokens (in mdb_scope valueToken, in short valueType, in mdb_scope commentToken, in short commentType); */
  NS_IMETHOD SetTokens(mdb_scope valueToken, PRInt16 valueType, mdb_scope commentToken, PRInt16 commentType) = 0;

  /* void addRow (in nsIMdbRow row); */
  NS_IMETHOD AddRow(nsIMdbRow *row) = 0;

  /* nsIMdbRow getRowAt (in unsigned long rowIndex); */
  NS_IMETHOD GetRowAt(PRUint32 rowIndex, nsIMdbRow **_retval NS_OUTPARAM) = 0;

  /* AString getRowValue (in nsIMdbRow row, in mdb_column col); */
  NS_IMETHOD GetRowValue(nsIMdbRow *row, mdb_column col, nsAString & _retval NS_OUTPARAM) = 0;

  /* AUTF8String getUTF8RowValue (in nsIMdbRow row, in mdb_column col); */
  NS_IMETHOD GetUTF8RowValue(nsIMdbRow *row, mdb_column col, nsACString & _retval NS_OUTPARAM) = 0;

  /* long getIntRowValue (in nsIMdbRow row, in mdb_column col); */
  NS_IMETHOD GetIntRowValue(nsIMdbRow *row, mdb_column col, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteMdbResult, NS_IAUTOCOMPLETEMDBRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETEMDBRESULT \
  NS_IMETHOD Init(nsIMdbEnv *env, nsIMdbTable *table); \
  NS_IMETHOD SetTokens(mdb_scope valueToken, PRInt16 valueType, mdb_scope commentToken, PRInt16 commentType); \
  NS_IMETHOD AddRow(nsIMdbRow *row); \
  NS_IMETHOD GetRowAt(PRUint32 rowIndex, nsIMdbRow **_retval NS_OUTPARAM); \
  NS_IMETHOD GetRowValue(nsIMdbRow *row, mdb_column col, nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetUTF8RowValue(nsIMdbRow *row, mdb_column col, nsACString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetIntRowValue(nsIMdbRow *row, mdb_column col, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETEMDBRESULT(_to) \
  NS_IMETHOD Init(nsIMdbEnv *env, nsIMdbTable *table) { return _to Init(env, table); } \
  NS_IMETHOD SetTokens(mdb_scope valueToken, PRInt16 valueType, mdb_scope commentToken, PRInt16 commentType) { return _to SetTokens(valueToken, valueType, commentToken, commentType); } \
  NS_IMETHOD AddRow(nsIMdbRow *row) { return _to AddRow(row); } \
  NS_IMETHOD GetRowAt(PRUint32 rowIndex, nsIMdbRow **_retval NS_OUTPARAM) { return _to GetRowAt(rowIndex, _retval); } \
  NS_IMETHOD GetRowValue(nsIMdbRow *row, mdb_column col, nsAString & _retval NS_OUTPARAM) { return _to GetRowValue(row, col, _retval); } \
  NS_IMETHOD GetUTF8RowValue(nsIMdbRow *row, mdb_column col, nsACString & _retval NS_OUTPARAM) { return _to GetUTF8RowValue(row, col, _retval); } \
  NS_IMETHOD GetIntRowValue(nsIMdbRow *row, mdb_column col, PRInt32 *_retval NS_OUTPARAM) { return _to GetIntRowValue(row, col, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETEMDBRESULT(_to) \
  NS_IMETHOD Init(nsIMdbEnv *env, nsIMdbTable *table) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(env, table); } \
  NS_IMETHOD SetTokens(mdb_scope valueToken, PRInt16 valueType, mdb_scope commentToken, PRInt16 commentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTokens(valueToken, valueType, commentToken, commentType); } \
  NS_IMETHOD AddRow(nsIMdbRow *row) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddRow(row); } \
  NS_IMETHOD GetRowAt(PRUint32 rowIndex, nsIMdbRow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowAt(rowIndex, _retval); } \
  NS_IMETHOD GetRowValue(nsIMdbRow *row, mdb_column col, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowValue(row, col, _retval); } \
  NS_IMETHOD GetUTF8RowValue(nsIMdbRow *row, mdb_column col, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUTF8RowValue(row, col, _retval); } \
  NS_IMETHOD GetIntRowValue(nsIMdbRow *row, mdb_column col, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntRowValue(row, col, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteMdbResult : public nsIAutoCompleteMdbResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETEMDBRESULT

  nsAutoCompleteMdbResult();

private:
  ~nsAutoCompleteMdbResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoCompleteMdbResult, nsIAutoCompleteMdbResult)

nsAutoCompleteMdbResult::nsAutoCompleteMdbResult()
{
  /* member initializers and constructor code */
}

nsAutoCompleteMdbResult::~nsAutoCompleteMdbResult()
{
  /* destructor code */
}

/* void init (in nsIMdbEnv env, in nsIMdbTable table); */
NS_IMETHODIMP nsAutoCompleteMdbResult::Init(nsIMdbEnv *env, nsIMdbTable *table)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTokens (in mdb_scope valueToken, in short valueType, in mdb_scope commentToken, in short commentType); */
NS_IMETHODIMP nsAutoCompleteMdbResult::SetTokens(mdb_scope valueToken, PRInt16 valueType, mdb_scope commentToken, PRInt16 commentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addRow (in nsIMdbRow row); */
NS_IMETHODIMP nsAutoCompleteMdbResult::AddRow(nsIMdbRow *row)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMdbRow getRowAt (in unsigned long rowIndex); */
NS_IMETHODIMP nsAutoCompleteMdbResult::GetRowAt(PRUint32 rowIndex, nsIMdbRow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getRowValue (in nsIMdbRow row, in mdb_column col); */
NS_IMETHODIMP nsAutoCompleteMdbResult::GetRowValue(nsIMdbRow *row, mdb_column col, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getUTF8RowValue (in nsIMdbRow row, in mdb_column col); */
NS_IMETHODIMP nsAutoCompleteMdbResult::GetUTF8RowValue(nsIMdbRow *row, mdb_column col, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIntRowValue (in nsIMdbRow row, in mdb_column col); */
NS_IMETHODIMP nsAutoCompleteMdbResult::GetIntRowValue(nsIMdbRow *row, mdb_column col, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAutoCompleteMdbResult2 */
#define NS_IAUTOCOMPLETEMDBRESULT2_IID_STR "148c9dc5-0fbb-408b-80fe-544f6a85b433"

#define NS_IAUTOCOMPLETEMDBRESULT2_IID \
  {0x148c9dc5, 0x0fbb, 0x408b, \
    { 0x80, 0xfe, 0x54, 0x4f, 0x6a, 0x85, 0xb4, 0x33 }}

class NS_NO_VTABLE nsIAutoCompleteMdbResult2 : public nsIAutoCompleteMdbResult {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETEMDBRESULT2_IID)

  /* attribute boolean reverseByteOrder; */
  NS_IMETHOD GetReverseByteOrder(PRBool *aReverseByteOrder) = 0;
  NS_IMETHOD SetReverseByteOrder(PRBool aReverseByteOrder) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteMdbResult2, NS_IAUTOCOMPLETEMDBRESULT2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETEMDBRESULT2 \
  NS_IMETHOD GetReverseByteOrder(PRBool *aReverseByteOrder); \
  NS_IMETHOD SetReverseByteOrder(PRBool aReverseByteOrder); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETEMDBRESULT2(_to) \
  NS_IMETHOD GetReverseByteOrder(PRBool *aReverseByteOrder) { return _to GetReverseByteOrder(aReverseByteOrder); } \
  NS_IMETHOD SetReverseByteOrder(PRBool aReverseByteOrder) { return _to SetReverseByteOrder(aReverseByteOrder); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETEMDBRESULT2(_to) \
  NS_IMETHOD GetReverseByteOrder(PRBool *aReverseByteOrder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReverseByteOrder(aReverseByteOrder); } \
  NS_IMETHOD SetReverseByteOrder(PRBool aReverseByteOrder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReverseByteOrder(aReverseByteOrder); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteMdbResult2 : public nsIAutoCompleteMdbResult2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETEMDBRESULT2

  nsAutoCompleteMdbResult2();

private:
  ~nsAutoCompleteMdbResult2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoCompleteMdbResult2, nsIAutoCompleteMdbResult2)

nsAutoCompleteMdbResult2::nsAutoCompleteMdbResult2()
{
  /* member initializers and constructor code */
}

nsAutoCompleteMdbResult2::~nsAutoCompleteMdbResult2()
{
  /* destructor code */
}

/* attribute boolean reverseByteOrder; */
NS_IMETHODIMP nsAutoCompleteMdbResult2::GetReverseByteOrder(PRBool *aReverseByteOrder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteMdbResult2::SetReverseByteOrder(PRBool aReverseByteOrder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAutoCompleteResultTypes_h__ */
