/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIVariant.idl
 */

#ifndef __gen_nsIVariant_h__
#define __gen_nsIVariant_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDataType */
#define NS_IDATATYPE_IID_STR "4d12e540-83d7-11d5-90ed-0010a4e73d9a"

#define NS_IDATATYPE_IID \
  {0x4d12e540, 0x83d7, 0x11d5, \
    { 0x90, 0xed, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDataType : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDATATYPE_IID)

  enum { VTYPE_INT8 = 0U };

  enum { VTYPE_INT16 = 1U };

  enum { VTYPE_INT32 = 2U };

  enum { VTYPE_INT64 = 3U };

  enum { VTYPE_UINT8 = 4U };

  enum { VTYPE_UINT16 = 5U };

  enum { VTYPE_UINT32 = 6U };

  enum { VTYPE_UINT64 = 7U };

  enum { VTYPE_FLOAT = 8U };

  enum { VTYPE_DOUBLE = 9U };

  enum { VTYPE_BOOL = 10U };

  enum { VTYPE_CHAR = 11U };

  enum { VTYPE_WCHAR = 12U };

  enum { VTYPE_VOID = 13U };

  enum { VTYPE_ID = 14U };

  enum { VTYPE_DOMSTRING = 15U };

  enum { VTYPE_CHAR_STR = 16U };

  enum { VTYPE_WCHAR_STR = 17U };

  enum { VTYPE_INTERFACE = 18U };

  enum { VTYPE_INTERFACE_IS = 19U };

  enum { VTYPE_ARRAY = 20U };

  enum { VTYPE_STRING_SIZE_IS = 21U };

  enum { VTYPE_WSTRING_SIZE_IS = 22U };

  enum { VTYPE_UTF8STRING = 23U };

  enum { VTYPE_CSTRING = 24U };

  enum { VTYPE_ASTRING = 25U };

  enum { VTYPE_EMPTY_ARRAY = 254U };

  enum { VTYPE_EMPTY = 255U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDataType, NS_IDATATYPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDATATYPE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDATATYPE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDATATYPE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDataType : public nsIDataType
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDATATYPE

  nsDataType();

private:
  ~nsDataType();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDataType, nsIDataType)

nsDataType::nsDataType()
{
  /* member initializers and constructor code */
}

nsDataType::~nsDataType()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIVariant */
#define NS_IVARIANT_IID_STR "6c9eb060-8c6a-11d5-90f3-0010a4e73d9a"

#define NS_IVARIANT_IID \
  {0x6c9eb060, 0x8c6a, 0x11d5, \
    { 0x90, 0xf3, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

/**
 * XPConnect has magic to transparently convert between nsIVariant and JS types.
 * We mark the interface [scriptable] so that JS can use methods
 * that refer to this interface. But we mark all the methods and attributes
 * [noscript] since any nsIVariant object will be automatically converted to a
 * JS type anyway.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIVariant : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVARIANT_IID)

  /* [noscript] readonly attribute PRUint16 dataType; */
  NS_IMETHOD GetDataType(PRUint16 *aDataType) = 0;

  /* [noscript] PRUint8 getAsInt8 (); */
  NS_IMETHOD GetAsInt8(PRUint8 *_retval NS_OUTPARAM) = 0;

  /* [noscript] PRInt16 getAsInt16 (); */
  NS_IMETHOD GetAsInt16(PRInt16 *_retval NS_OUTPARAM) = 0;

  /* [noscript] PRInt32 getAsInt32 (); */
  NS_IMETHOD GetAsInt32(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* [noscript] PRInt64 getAsInt64 (); */
  NS_IMETHOD GetAsInt64(PRInt64 *_retval NS_OUTPARAM) = 0;

  /* [noscript] PRUint8 getAsUint8 (); */
  NS_IMETHOD GetAsUint8(PRUint8 *_retval NS_OUTPARAM) = 0;

  /* [noscript] PRUint16 getAsUint16 (); */
  NS_IMETHOD GetAsUint16(PRUint16 *_retval NS_OUTPARAM) = 0;

  /* [noscript] PRUint32 getAsUint32 (); */
  NS_IMETHOD GetAsUint32(PRUint32 *_retval NS_OUTPARAM) = 0;

  /* [noscript] PRUint64 getAsUint64 (); */
  NS_IMETHOD GetAsUint64(PRUint64 *_retval NS_OUTPARAM) = 0;

  /* [noscript] float getAsFloat (); */
  NS_IMETHOD GetAsFloat(float *_retval NS_OUTPARAM) = 0;

  /* [noscript] double getAsDouble (); */
  NS_IMETHOD GetAsDouble(double *_retval NS_OUTPARAM) = 0;

  /* [noscript] PRBool getAsBool (); */
  NS_IMETHOD GetAsBool(PRBool *_retval NS_OUTPARAM) = 0;

  /* [noscript] char getAsChar (); */
  NS_IMETHOD GetAsChar(char *_retval NS_OUTPARAM) = 0;

  /* [noscript] wchar getAsWChar (); */
  NS_IMETHOD GetAsWChar(PRUnichar *_retval NS_OUTPARAM) = 0;

  /* [notxpcom] nsresult getAsID (out nsID retval); */
  NS_IMETHOD_(nsresult) GetAsID(nsID *retval NS_OUTPARAM) = 0;

  /* [noscript] AString getAsAString (); */
  NS_IMETHOD GetAsAString(nsAString & _retval NS_OUTPARAM) = 0;

  /* [noscript] DOMString getAsDOMString (); */
  NS_IMETHOD GetAsDOMString(nsAString & _retval NS_OUTPARAM) = 0;

  /* [noscript] ACString getAsACString (); */
  NS_IMETHOD GetAsACString(nsACString & _retval NS_OUTPARAM) = 0;

  /* [noscript] AUTF8String getAsAUTF8String (); */
  NS_IMETHOD GetAsAUTF8String(nsACString & _retval NS_OUTPARAM) = 0;

  /* [noscript] string getAsString (); */
  NS_IMETHOD GetAsString(char **_retval NS_OUTPARAM) = 0;

  /* [noscript] wstring getAsWString (); */
  NS_IMETHOD GetAsWString(PRUnichar **_retval NS_OUTPARAM) = 0;

  /* [noscript] nsISupports getAsISupports (); */
  NS_IMETHOD GetAsISupports(nsISupports **_retval NS_OUTPARAM) = 0;

  /* [noscript] void getAsInterface (out nsIIDPtr iid, [iid_is (iid), retval] out nsQIResult iface); */
  NS_IMETHOD GetAsInterface(nsIID * *iid NS_OUTPARAM, void * *iface NS_OUTPARAM) = 0;

  /* [notxpcom] nsresult getAsArray (out PRUint16 type, out nsIID iid, out PRUint32 count, out voidPtr ptr); */
  NS_IMETHOD_(nsresult) GetAsArray(PRUint16 *type NS_OUTPARAM, nsIID *iid NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, void * *ptr NS_OUTPARAM) = 0;

  /* [noscript] void getAsStringWithSize (out PRUint32 size, [size_is (size), retval] out string str); */
  NS_IMETHOD GetAsStringWithSize(PRUint32 *size NS_OUTPARAM, char **str NS_OUTPARAM) = 0;

  /* [noscript] void getAsWStringWithSize (out PRUint32 size, [size_is (size), retval] out wstring str); */
  NS_IMETHOD GetAsWStringWithSize(PRUint32 *size NS_OUTPARAM, PRUnichar **str NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVariant, NS_IVARIANT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVARIANT \
  NS_IMETHOD GetDataType(PRUint16 *aDataType); \
  NS_IMETHOD GetAsInt8(PRUint8 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsInt16(PRInt16 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsInt32(PRInt32 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsInt64(PRInt64 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsUint8(PRUint8 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsUint16(PRUint16 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsUint32(PRUint32 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsUint64(PRUint64 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsFloat(float *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsDouble(double *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsBool(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsChar(char *_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsWChar(PRUnichar *_retval NS_OUTPARAM); \
  NS_IMETHOD_(nsresult) GetAsID(nsID *retval NS_OUTPARAM); \
  NS_IMETHOD GetAsAString(nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetAsDOMString(nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetAsACString(nsACString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetAsAUTF8String(nsACString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetAsString(char **_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsWString(PRUnichar **_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsISupports(nsISupports **_retval NS_OUTPARAM); \
  NS_IMETHOD GetAsInterface(nsIID * *iid NS_OUTPARAM, void * *iface NS_OUTPARAM); \
  NS_IMETHOD_(nsresult) GetAsArray(PRUint16 *type NS_OUTPARAM, nsIID *iid NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, void * *ptr NS_OUTPARAM); \
  NS_IMETHOD GetAsStringWithSize(PRUint32 *size NS_OUTPARAM, char **str NS_OUTPARAM); \
  NS_IMETHOD GetAsWStringWithSize(PRUint32 *size NS_OUTPARAM, PRUnichar **str NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVARIANT(_to) \
  NS_IMETHOD GetDataType(PRUint16 *aDataType) { return _to GetDataType(aDataType); } \
  NS_IMETHOD GetAsInt8(PRUint8 *_retval NS_OUTPARAM) { return _to GetAsInt8(_retval); } \
  NS_IMETHOD GetAsInt16(PRInt16 *_retval NS_OUTPARAM) { return _to GetAsInt16(_retval); } \
  NS_IMETHOD GetAsInt32(PRInt32 *_retval NS_OUTPARAM) { return _to GetAsInt32(_retval); } \
  NS_IMETHOD GetAsInt64(PRInt64 *_retval NS_OUTPARAM) { return _to GetAsInt64(_retval); } \
  NS_IMETHOD GetAsUint8(PRUint8 *_retval NS_OUTPARAM) { return _to GetAsUint8(_retval); } \
  NS_IMETHOD GetAsUint16(PRUint16 *_retval NS_OUTPARAM) { return _to GetAsUint16(_retval); } \
  NS_IMETHOD GetAsUint32(PRUint32 *_retval NS_OUTPARAM) { return _to GetAsUint32(_retval); } \
  NS_IMETHOD GetAsUint64(PRUint64 *_retval NS_OUTPARAM) { return _to GetAsUint64(_retval); } \
  NS_IMETHOD GetAsFloat(float *_retval NS_OUTPARAM) { return _to GetAsFloat(_retval); } \
  NS_IMETHOD GetAsDouble(double *_retval NS_OUTPARAM) { return _to GetAsDouble(_retval); } \
  NS_IMETHOD GetAsBool(PRBool *_retval NS_OUTPARAM) { return _to GetAsBool(_retval); } \
  NS_IMETHOD GetAsChar(char *_retval NS_OUTPARAM) { return _to GetAsChar(_retval); } \
  NS_IMETHOD GetAsWChar(PRUnichar *_retval NS_OUTPARAM) { return _to GetAsWChar(_retval); } \
  NS_IMETHOD_(nsresult) GetAsID(nsID *retval NS_OUTPARAM) { return _to GetAsID(retval); } \
  NS_IMETHOD GetAsAString(nsAString & _retval NS_OUTPARAM) { return _to GetAsAString(_retval); } \
  NS_IMETHOD GetAsDOMString(nsAString & _retval NS_OUTPARAM) { return _to GetAsDOMString(_retval); } \
  NS_IMETHOD GetAsACString(nsACString & _retval NS_OUTPARAM) { return _to GetAsACString(_retval); } \
  NS_IMETHOD GetAsAUTF8String(nsACString & _retval NS_OUTPARAM) { return _to GetAsAUTF8String(_retval); } \
  NS_IMETHOD GetAsString(char **_retval NS_OUTPARAM) { return _to GetAsString(_retval); } \
  NS_IMETHOD GetAsWString(PRUnichar **_retval NS_OUTPARAM) { return _to GetAsWString(_retval); } \
  NS_IMETHOD GetAsISupports(nsISupports **_retval NS_OUTPARAM) { return _to GetAsISupports(_retval); } \
  NS_IMETHOD GetAsInterface(nsIID * *iid NS_OUTPARAM, void * *iface NS_OUTPARAM) { return _to GetAsInterface(iid, iface); } \
  NS_IMETHOD_(nsresult) GetAsArray(PRUint16 *type NS_OUTPARAM, nsIID *iid NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, void * *ptr NS_OUTPARAM) { return _to GetAsArray(type, iid, count, ptr); } \
  NS_IMETHOD GetAsStringWithSize(PRUint32 *size NS_OUTPARAM, char **str NS_OUTPARAM) { return _to GetAsStringWithSize(size, str); } \
  NS_IMETHOD GetAsWStringWithSize(PRUint32 *size NS_OUTPARAM, PRUnichar **str NS_OUTPARAM) { return _to GetAsWStringWithSize(size, str); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVARIANT(_to) \
  NS_IMETHOD GetDataType(PRUint16 *aDataType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataType(aDataType); } \
  NS_IMETHOD GetAsInt8(PRUint8 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInt8(_retval); } \
  NS_IMETHOD GetAsInt16(PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInt16(_retval); } \
  NS_IMETHOD GetAsInt32(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInt32(_retval); } \
  NS_IMETHOD GetAsInt64(PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInt64(_retval); } \
  NS_IMETHOD GetAsUint8(PRUint8 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsUint8(_retval); } \
  NS_IMETHOD GetAsUint16(PRUint16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsUint16(_retval); } \
  NS_IMETHOD GetAsUint32(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsUint32(_retval); } \
  NS_IMETHOD GetAsUint64(PRUint64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsUint64(_retval); } \
  NS_IMETHOD GetAsFloat(float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsFloat(_retval); } \
  NS_IMETHOD GetAsDouble(double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsDouble(_retval); } \
  NS_IMETHOD GetAsBool(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsBool(_retval); } \
  NS_IMETHOD GetAsChar(char *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsChar(_retval); } \
  NS_IMETHOD GetAsWChar(PRUnichar *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsWChar(_retval); } \
  NS_IMETHOD_(nsresult) GetAsID(nsID *retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsID(retval); } \
  NS_IMETHOD GetAsAString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsAString(_retval); } \
  NS_IMETHOD GetAsDOMString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsDOMString(_retval); } \
  NS_IMETHOD GetAsACString(nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsACString(_retval); } \
  NS_IMETHOD GetAsAUTF8String(nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsAUTF8String(_retval); } \
  NS_IMETHOD GetAsString(char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsString(_retval); } \
  NS_IMETHOD GetAsWString(PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsWString(_retval); } \
  NS_IMETHOD GetAsISupports(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsISupports(_retval); } \
  NS_IMETHOD GetAsInterface(nsIID * *iid NS_OUTPARAM, void * *iface NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsInterface(iid, iface); } \
  NS_IMETHOD_(nsresult) GetAsArray(PRUint16 *type NS_OUTPARAM, nsIID *iid NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, void * *ptr NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsArray(type, iid, count, ptr); } \
  NS_IMETHOD GetAsStringWithSize(PRUint32 *size NS_OUTPARAM, char **str NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsStringWithSize(size, str); } \
  NS_IMETHOD GetAsWStringWithSize(PRUint32 *size NS_OUTPARAM, PRUnichar **str NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsWStringWithSize(size, str); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVariant : public nsIVariant
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVARIANT

  nsVariant();

private:
  ~nsVariant();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsVariant, nsIVariant)

nsVariant::nsVariant()
{
  /* member initializers and constructor code */
}

nsVariant::~nsVariant()
{
  /* destructor code */
}

/* [noscript] readonly attribute PRUint16 dataType; */
NS_IMETHODIMP nsVariant::GetDataType(PRUint16 *aDataType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRUint8 getAsInt8 (); */
NS_IMETHODIMP nsVariant::GetAsInt8(PRUint8 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRInt16 getAsInt16 (); */
NS_IMETHODIMP nsVariant::GetAsInt16(PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRInt32 getAsInt32 (); */
NS_IMETHODIMP nsVariant::GetAsInt32(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRInt64 getAsInt64 (); */
NS_IMETHODIMP nsVariant::GetAsInt64(PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRUint8 getAsUint8 (); */
NS_IMETHODIMP nsVariant::GetAsUint8(PRUint8 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRUint16 getAsUint16 (); */
NS_IMETHODIMP nsVariant::GetAsUint16(PRUint16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRUint32 getAsUint32 (); */
NS_IMETHODIMP nsVariant::GetAsUint32(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRUint64 getAsUint64 (); */
NS_IMETHODIMP nsVariant::GetAsUint64(PRUint64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] float getAsFloat (); */
NS_IMETHODIMP nsVariant::GetAsFloat(float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] double getAsDouble (); */
NS_IMETHODIMP nsVariant::GetAsDouble(double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRBool getAsBool (); */
NS_IMETHODIMP nsVariant::GetAsBool(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] char getAsChar (); */
NS_IMETHODIMP nsVariant::GetAsChar(char *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] wchar getAsWChar (); */
NS_IMETHODIMP nsVariant::GetAsWChar(PRUnichar *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsresult getAsID (out nsID retval); */
NS_IMETHODIMP_(nsresult) nsVariant::GetAsID(nsID *retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString getAsAString (); */
NS_IMETHODIMP nsVariant::GetAsAString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] DOMString getAsDOMString (); */
NS_IMETHODIMP nsVariant::GetAsDOMString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] ACString getAsACString (); */
NS_IMETHODIMP nsVariant::GetAsACString(nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AUTF8String getAsAUTF8String (); */
NS_IMETHODIMP nsVariant::GetAsAUTF8String(nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] string getAsString (); */
NS_IMETHODIMP nsVariant::GetAsString(char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] wstring getAsWString (); */
NS_IMETHODIMP nsVariant::GetAsWString(PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsISupports getAsISupports (); */
NS_IMETHODIMP nsVariant::GetAsISupports(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getAsInterface (out nsIIDPtr iid, [iid_is (iid), retval] out nsQIResult iface); */
NS_IMETHODIMP nsVariant::GetAsInterface(nsIID * *iid NS_OUTPARAM, void * *iface NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsresult getAsArray (out PRUint16 type, out nsIID iid, out PRUint32 count, out voidPtr ptr); */
NS_IMETHODIMP_(nsresult) nsVariant::GetAsArray(PRUint16 *type NS_OUTPARAM, nsIID *iid NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, void * *ptr NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getAsStringWithSize (out PRUint32 size, [size_is (size), retval] out string str); */
NS_IMETHODIMP nsVariant::GetAsStringWithSize(PRUint32 *size NS_OUTPARAM, char **str NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getAsWStringWithSize (out PRUint32 size, [size_is (size), retval] out wstring str); */
NS_IMETHODIMP nsVariant::GetAsWStringWithSize(PRUint32 *size NS_OUTPARAM, PRUnichar **str NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWritableVariant */
#define NS_IWRITABLEVARIANT_IID_STR "5586a590-8c82-11d5-90f3-0010a4e73d9a"

#define NS_IWRITABLEVARIANT_IID \
  {0x5586a590, 0x8c82, 0x11d5, \
    { 0x90, 0xf3, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

/**
 * An object that implements nsIVariant may or may NOT also implement this
 * nsIWritableVariant.
 * 
 * If the 'writable' attribute is false then attempts to call any of the 'set'
 * methods can be expected to fail. Setting the 'writable' attribute may or
 * may not succeed.
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWritableVariant : public nsIVariant {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWRITABLEVARIANT_IID)

  /* attribute PRBool writable; */
  NS_SCRIPTABLE NS_IMETHOD GetWritable(PRBool *aWritable) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWritable(PRBool aWritable) = 0;

  /* void setAsInt8 (in PRUint8 aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsInt8(PRUint8 aValue) = 0;

  /* void setAsInt16 (in PRInt16 aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsInt16(PRInt16 aValue) = 0;

  /* void setAsInt32 (in PRInt32 aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsInt32(PRInt32 aValue) = 0;

  /* void setAsInt64 (in PRInt64 aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsInt64(PRInt64 aValue) = 0;

  /* void setAsUint8 (in PRUint8 aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsUint8(PRUint8 aValue) = 0;

  /* void setAsUint16 (in PRUint16 aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsUint16(PRUint16 aValue) = 0;

  /* void setAsUint32 (in PRUint32 aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsUint32(PRUint32 aValue) = 0;

  /* void setAsUint64 (in PRUint64 aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsUint64(PRUint64 aValue) = 0;

  /* void setAsFloat (in float aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsFloat(float aValue) = 0;

  /* void setAsDouble (in double aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsDouble(double aValue) = 0;

  /* void setAsBool (in PRBool aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsBool(PRBool aValue) = 0;

  /* void setAsChar (in char aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsChar(char aValue) = 0;

  /* void setAsWChar (in wchar aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsWChar(PRUnichar aValue) = 0;

  /* void setAsID (in nsIDRef aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsID(const nsID & aValue) = 0;

  /* void setAsAString (in AString aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsAString(const nsAString & aValue) = 0;

  /* void setAsDOMString (in DOMString aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsDOMString(const nsAString & aValue) = 0;

  /* void setAsACString (in ACString aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsACString(const nsACString & aValue) = 0;

  /* void setAsAUTF8String (in AUTF8String aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsAUTF8String(const nsACString & aValue) = 0;

  /* void setAsString (in string aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsString(const char *aValue) = 0;

  /* void setAsWString (in wstring aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsWString(const PRUnichar *aValue) = 0;

  /* void setAsISupports (in nsISupports aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAsISupports(nsISupports *aValue) = 0;

  /* void setAsInterface (in nsIIDRef iid, [iid_is (iid)] in nsQIResult iface); */
  NS_SCRIPTABLE NS_IMETHOD SetAsInterface(const nsIID & iid, void * iface) = 0;

  /* [noscript] void setAsArray (in PRUint16 type, in nsIIDPtr iid, in PRUint32 count, in voidPtr ptr); */
  NS_IMETHOD SetAsArray(PRUint16 type, const nsIID * iid, PRUint32 count, void * ptr) = 0;

  /* void setAsStringWithSize (in PRUint32 size, [size_is (size)] in string str); */
  NS_SCRIPTABLE NS_IMETHOD SetAsStringWithSize(PRUint32 size, const char *str) = 0;

  /* void setAsWStringWithSize (in PRUint32 size, [size_is (size)] in wstring str); */
  NS_SCRIPTABLE NS_IMETHOD SetAsWStringWithSize(PRUint32 size, const PRUnichar *str) = 0;

  /* void setAsVoid (); */
  NS_SCRIPTABLE NS_IMETHOD SetAsVoid(void) = 0;

  /* void setAsEmpty (); */
  NS_SCRIPTABLE NS_IMETHOD SetAsEmpty(void) = 0;

  /* void setAsEmptyArray (); */
  NS_SCRIPTABLE NS_IMETHOD SetAsEmptyArray(void) = 0;

  /* void setFromVariant (in nsIVariant aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetFromVariant(nsIVariant *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWritableVariant, NS_IWRITABLEVARIANT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWRITABLEVARIANT \
  NS_SCRIPTABLE NS_IMETHOD GetWritable(PRBool *aWritable); \
  NS_SCRIPTABLE NS_IMETHOD SetWritable(PRBool aWritable); \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt8(PRUint8 aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt16(PRInt16 aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt32(PRInt32 aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt64(PRInt64 aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint8(PRUint8 aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint16(PRUint16 aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint32(PRUint32 aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint64(PRUint64 aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsFloat(float aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsDouble(double aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsBool(PRBool aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsChar(char aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsWChar(PRUnichar aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsID(const nsID & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsAString(const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsDOMString(const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsACString(const nsACString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsAUTF8String(const nsACString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsString(const char *aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsWString(const PRUnichar *aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsISupports(nsISupports *aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetAsInterface(const nsIID & iid, void * iface); \
  NS_IMETHOD SetAsArray(PRUint16 type, const nsIID * iid, PRUint32 count, void * ptr); \
  NS_SCRIPTABLE NS_IMETHOD SetAsStringWithSize(PRUint32 size, const char *str); \
  NS_SCRIPTABLE NS_IMETHOD SetAsWStringWithSize(PRUint32 size, const PRUnichar *str); \
  NS_SCRIPTABLE NS_IMETHOD SetAsVoid(void); \
  NS_SCRIPTABLE NS_IMETHOD SetAsEmpty(void); \
  NS_SCRIPTABLE NS_IMETHOD SetAsEmptyArray(void); \
  NS_SCRIPTABLE NS_IMETHOD SetFromVariant(nsIVariant *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWRITABLEVARIANT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWritable(PRBool *aWritable) { return _to GetWritable(aWritable); } \
  NS_SCRIPTABLE NS_IMETHOD SetWritable(PRBool aWritable) { return _to SetWritable(aWritable); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt8(PRUint8 aValue) { return _to SetAsInt8(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt16(PRInt16 aValue) { return _to SetAsInt16(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt32(PRInt32 aValue) { return _to SetAsInt32(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt64(PRInt64 aValue) { return _to SetAsInt64(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint8(PRUint8 aValue) { return _to SetAsUint8(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint16(PRUint16 aValue) { return _to SetAsUint16(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint32(PRUint32 aValue) { return _to SetAsUint32(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint64(PRUint64 aValue) { return _to SetAsUint64(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsFloat(float aValue) { return _to SetAsFloat(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsDouble(double aValue) { return _to SetAsDouble(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsBool(PRBool aValue) { return _to SetAsBool(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsChar(char aValue) { return _to SetAsChar(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsWChar(PRUnichar aValue) { return _to SetAsWChar(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsID(const nsID & aValue) { return _to SetAsID(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsAString(const nsAString & aValue) { return _to SetAsAString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsDOMString(const nsAString & aValue) { return _to SetAsDOMString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsACString(const nsACString & aValue) { return _to SetAsACString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsAUTF8String(const nsACString & aValue) { return _to SetAsAUTF8String(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsString(const char *aValue) { return _to SetAsString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsWString(const PRUnichar *aValue) { return _to SetAsWString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsISupports(nsISupports *aValue) { return _to SetAsISupports(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInterface(const nsIID & iid, void * iface) { return _to SetAsInterface(iid, iface); } \
  NS_IMETHOD SetAsArray(PRUint16 type, const nsIID * iid, PRUint32 count, void * ptr) { return _to SetAsArray(type, iid, count, ptr); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsStringWithSize(PRUint32 size, const char *str) { return _to SetAsStringWithSize(size, str); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsWStringWithSize(PRUint32 size, const PRUnichar *str) { return _to SetAsWStringWithSize(size, str); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsVoid(void) { return _to SetAsVoid(); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsEmpty(void) { return _to SetAsEmpty(); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsEmptyArray(void) { return _to SetAsEmptyArray(); } \
  NS_SCRIPTABLE NS_IMETHOD SetFromVariant(nsIVariant *aValue) { return _to SetFromVariant(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWRITABLEVARIANT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWritable(PRBool *aWritable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWritable(aWritable); } \
  NS_SCRIPTABLE NS_IMETHOD SetWritable(PRBool aWritable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWritable(aWritable); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt8(PRUint8 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInt8(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt16(PRInt16 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInt16(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt32(PRInt32 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInt32(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInt64(PRInt64 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInt64(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint8(PRUint8 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsUint8(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint16(PRUint16 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsUint16(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint32(PRUint32 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsUint32(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsUint64(PRUint64 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsUint64(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsFloat(float aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsFloat(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsDouble(double aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsDouble(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsBool(PRBool aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsBool(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsChar(char aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsChar(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsWChar(PRUnichar aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsWChar(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsID(const nsID & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsID(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsAString(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsAString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsDOMString(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsDOMString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsACString(const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsACString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsAUTF8String(const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsAUTF8String(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsString(const char *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsWString(const PRUnichar *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsWString(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsISupports(nsISupports *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsISupports(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsInterface(const nsIID & iid, void * iface) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsInterface(iid, iface); } \
  NS_IMETHOD SetAsArray(PRUint16 type, const nsIID * iid, PRUint32 count, void * ptr) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsArray(type, iid, count, ptr); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsStringWithSize(PRUint32 size, const char *str) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsStringWithSize(size, str); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsWStringWithSize(PRUint32 size, const PRUnichar *str) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsWStringWithSize(size, str); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsVoid(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsVoid(); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsEmpty(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsEmpty(); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsEmptyArray(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsEmptyArray(); } \
  NS_SCRIPTABLE NS_IMETHOD SetFromVariant(nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFromVariant(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWritableVariant : public nsIWritableVariant
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWRITABLEVARIANT

  nsWritableVariant();

private:
  ~nsWritableVariant();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWritableVariant, nsIWritableVariant)

nsWritableVariant::nsWritableVariant()
{
  /* member initializers and constructor code */
}

nsWritableVariant::~nsWritableVariant()
{
  /* destructor code */
}

/* attribute PRBool writable; */
NS_IMETHODIMP nsWritableVariant::GetWritable(PRBool *aWritable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWritableVariant::SetWritable(PRBool aWritable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInt8 (in PRUint8 aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsInt8(PRUint8 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInt16 (in PRInt16 aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsInt16(PRInt16 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInt32 (in PRInt32 aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsInt32(PRInt32 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInt64 (in PRInt64 aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsInt64(PRInt64 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsUint8 (in PRUint8 aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsUint8(PRUint8 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsUint16 (in PRUint16 aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsUint16(PRUint16 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsUint32 (in PRUint32 aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsUint32(PRUint32 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsUint64 (in PRUint64 aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsUint64(PRUint64 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsFloat (in float aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsFloat(float aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsDouble (in double aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsDouble(double aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsBool (in PRBool aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsBool(PRBool aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsChar (in char aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsChar(char aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsWChar (in wchar aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsWChar(PRUnichar aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsID (in nsIDRef aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsID(const nsID & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsAString (in AString aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsAString(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsDOMString (in DOMString aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsDOMString(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsACString (in ACString aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsACString(const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsAUTF8String (in AUTF8String aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsAUTF8String(const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsString (in string aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsString(const char *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsWString (in wstring aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsWString(const PRUnichar *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsISupports (in nsISupports aValue); */
NS_IMETHODIMP nsWritableVariant::SetAsISupports(nsISupports *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsInterface (in nsIIDRef iid, [iid_is (iid)] in nsQIResult iface); */
NS_IMETHODIMP nsWritableVariant::SetAsInterface(const nsIID & iid, void * iface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setAsArray (in PRUint16 type, in nsIIDPtr iid, in PRUint32 count, in voidPtr ptr); */
NS_IMETHODIMP nsWritableVariant::SetAsArray(PRUint16 type, const nsIID * iid, PRUint32 count, void * ptr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsStringWithSize (in PRUint32 size, [size_is (size)] in string str); */
NS_IMETHODIMP nsWritableVariant::SetAsStringWithSize(PRUint32 size, const char *str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsWStringWithSize (in PRUint32 size, [size_is (size)] in wstring str); */
NS_IMETHODIMP nsWritableVariant::SetAsWStringWithSize(PRUint32 size, const PRUnichar *str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsVoid (); */
NS_IMETHODIMP nsWritableVariant::SetAsVoid()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsEmpty (); */
NS_IMETHODIMP nsWritableVariant::SetAsEmpty()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsEmptyArray (); */
NS_IMETHODIMP nsWritableVariant::SetAsEmptyArray()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFromVariant (in nsIVariant aValue); */
NS_IMETHODIMP nsWritableVariant::SetFromVariant(nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// The contractID for the generic implementation built in to xpcom.
#define NS_VARIANT_CONTRACTID "@mozilla.org/variant;1"

#endif /* __gen_nsIVariant_h__ */
