/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/uconv/idl/nsIScriptableUConv.idl
 */

#ifndef __gen_nsIScriptableUConv_h__
#define __gen_nsIScriptableUConv_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

// {0A698C44-3BFF-11d4-9649-00C0CA135B4E}
#define NS_ISCRIPTABLEUNICODECONVERTER_CID { 0x0A698C44, 0x3BFF, 0x11d4, { 0x96, 0x49, 0x00, 0xC0, 0xCA, 0x13, 0x5B, 0x4E } }
#define NS_ISCRIPTABLEUNICODECONVERTER_CONTRACTID "@mozilla.org/intl/scriptableunicodeconverter"

/* starting interface:    nsIScriptableUnicodeConverter */
#define NS_ISCRIPTABLEUNICODECONVERTER_IID_STR "1ea19c6c-c59f-4fd7-9fc7-151e946baca0"

#define NS_ISCRIPTABLEUNICODECONVERTER_IID \
  {0x1ea19c6c, 0xc59f, 0x4fd7, \
    { 0x9f, 0xc7, 0x15, 0x1e, 0x94, 0x6b, 0xac, 0xa0 }}

/**
 * This interface is a unicode encoder for use by scripts
 *
 * @created         8/Jun/2000
 * @author          Makoto Kato [m_kato@ga2.so-net.ne.jp]
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptableUnicodeConverter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEUNICODECONVERTER_IID)

  /**
   * Converts the data from Unicode to one Charset.
   * Returns the converted string. After converting, Finish should be called
   * and its return value appended to this return value.
   */
  /* ACString ConvertFromUnicode (in AString aSrc); */
  NS_SCRIPTABLE NS_IMETHOD ConvertFromUnicode(const nsAString & aSrc, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Returns the terminator string.
   * Should be called after ConvertFromUnicode() and appended to that
   * function's return value.
   */
  /* ACString Finish (); */
  NS_SCRIPTABLE NS_IMETHOD Finish(nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Converts the data from one Charset to Unicode.
   */
  /* AString ConvertToUnicode (in ACString aSrc); */
  NS_SCRIPTABLE NS_IMETHOD ConvertToUnicode(const nsACString & aSrc, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Converts an array of bytes to a unicode string.
   */
  /* AString convertFromByteArray ([array, size_is (aCount), const] in octet aData, in unsigned long aCount); */
  NS_SCRIPTABLE NS_IMETHOD ConvertFromByteArray(const PRUint8 *aData, PRUint32 aCount, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Convert a unicode string to an array of bytes. Finish does not need to be
   * called.
   */
  /* void convertToByteArray (in AString aString, out unsigned long aLen, [array, size_is (aLen), retval] out octet aData); */
  NS_SCRIPTABLE NS_IMETHOD ConvertToByteArray(const nsAString & aString, PRUint32 *aLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) = 0;

  /**
   * Converts a unicode string to an input stream. The bytes in the stream are
   * encoded according to the charset attribute.
   * The returned stream will be nonblocking.
   */
  /* nsIInputStream convertToInputStream (in AString aString); */
  NS_SCRIPTABLE NS_IMETHOD ConvertToInputStream(const nsAString & aString, nsIInputStream **_retval NS_OUTPARAM) = 0;

  /**
   * Current character set.
   *
   * @throw NS_ERROR_UCONV_NOCONV
   *        The requested charset is not supported.
   */
  /* attribute string charset; */
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const char * aCharset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableUnicodeConverter, NS_ISCRIPTABLEUNICODECONVERTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEUNICODECONVERTER \
  NS_SCRIPTABLE NS_IMETHOD ConvertFromUnicode(const nsAString & aSrc, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Finish(nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ConvertToUnicode(const nsACString & aSrc, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ConvertFromByteArray(const PRUint8 *aData, PRUint32 aCount, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ConvertToByteArray(const nsAString & aString, PRUint32 *aLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ConvertToInputStream(const nsAString & aString, nsIInputStream **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset); \
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const char * aCharset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEUNICODECONVERTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertFromUnicode(const nsAString & aSrc, nsACString & _retval NS_OUTPARAM) { return _to ConvertFromUnicode(aSrc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(nsACString & _retval NS_OUTPARAM) { return _to Finish(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToUnicode(const nsACString & aSrc, nsAString & _retval NS_OUTPARAM) { return _to ConvertToUnicode(aSrc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertFromByteArray(const PRUint8 *aData, PRUint32 aCount, nsAString & _retval NS_OUTPARAM) { return _to ConvertFromByteArray(aData, aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToByteArray(const nsAString & aString, PRUint32 *aLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) { return _to ConvertToByteArray(aString, aLen, aData); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToInputStream(const nsAString & aString, nsIInputStream **_retval NS_OUTPARAM) { return _to ConvertToInputStream(aString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset) { return _to GetCharset(aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const char * aCharset) { return _to SetCharset(aCharset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEUNICODECONVERTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertFromUnicode(const nsAString & aSrc, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertFromUnicode(aSrc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToUnicode(const nsACString & aSrc, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToUnicode(aSrc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertFromByteArray(const PRUint8 *aData, PRUint32 aCount, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertFromByteArray(aData, aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToByteArray(const nsAString & aString, PRUint32 *aLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToByteArray(aString, aLen, aData); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToInputStream(const nsAString & aString, nsIInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToInputStream(aString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const char * aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableUnicodeConverter : public nsIScriptableUnicodeConverter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEUNICODECONVERTER

  nsScriptableUnicodeConverter();

private:
  ~nsScriptableUnicodeConverter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableUnicodeConverter, nsIScriptableUnicodeConverter)

nsScriptableUnicodeConverter::nsScriptableUnicodeConverter()
{
  /* member initializers and constructor code */
}

nsScriptableUnicodeConverter::~nsScriptableUnicodeConverter()
{
  /* destructor code */
}

/* ACString ConvertFromUnicode (in AString aSrc); */
NS_IMETHODIMP nsScriptableUnicodeConverter::ConvertFromUnicode(const nsAString & aSrc, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString Finish (); */
NS_IMETHODIMP nsScriptableUnicodeConverter::Finish(nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString ConvertToUnicode (in ACString aSrc); */
NS_IMETHODIMP nsScriptableUnicodeConverter::ConvertToUnicode(const nsACString & aSrc, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString convertFromByteArray ([array, size_is (aCount), const] in octet aData, in unsigned long aCount); */
NS_IMETHODIMP nsScriptableUnicodeConverter::ConvertFromByteArray(const PRUint8 *aData, PRUint32 aCount, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void convertToByteArray (in AString aString, out unsigned long aLen, [array, size_is (aLen), retval] out octet aData); */
NS_IMETHODIMP nsScriptableUnicodeConverter::ConvertToByteArray(const nsAString & aString, PRUint32 *aLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream convertToInputStream (in AString aString); */
NS_IMETHODIMP nsScriptableUnicodeConverter::ConvertToInputStream(const nsAString & aString, nsIInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string charset; */
NS_IMETHODIMP nsScriptableUnicodeConverter::GetCharset(char * *aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsScriptableUnicodeConverter::SetCharset(const char * aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableUConv_h__ */
