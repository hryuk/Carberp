/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/uconv/idl/nsIUTF8ConverterService.idl
 */

#ifndef __gen_nsIUTF8ConverterService_h__
#define __gen_nsIUTF8ConverterService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUTF8ConverterService */
#define NS_IUTF8CONVERTERSERVICE_IID_STR "249f52a3-2599-4b00-ba40-0481364831a2"

#define NS_IUTF8CONVERTERSERVICE_IID \
  {0x249f52a3, 0x2599, 0x4b00, \
    { 0xba, 0x40, 0x04, 0x81, 0x36, 0x48, 0x31, 0xa2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIUTF8ConverterService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUTF8CONVERTERSERVICE_IID)

  /**
   * Ensure that |aString| is encoded in UTF-8.  If not, 
   * convert to UTF-8 assuming it's encoded in |aCharset|
   * and return the converted string in UTF-8.
   *
   * @param aString a string to  ensure its UTF8ness
   * @param aCharset the charset to convert from if |aString| is not in UTF-8
   * @param aSkipCheck determines whether or not to skip 'ASCIIness' and 
   *        'UTF8ness' check. Set this to PR_TRUE only if you suspect that 
   *        aString can be mistaken for ASCII / UTF-8 but is actually NOT 
   *        in ASCII / UTF-8 so that aString has to go through the conversion.
   *        skipping ASCIIness/UTF8ness check.
   *        The most common case is the input is in 7bit non-ASCII charsets
   *        like ISO-2022-JP, HZ or UTF-7 (in its original form or
   *        a modified form used in IMAP folder names).
   * @return the converted string in UTF-8.
   * @throws NS_ERROR_UCONV_NOCONV when there is no decoder for aCharset
   *         or error code of nsIUnicodeDecoder in case of conversion failure
   */
  /* AUTF8String convertStringToUTF8 (in ACString aString, in string aCharset, in boolean aSkipCheck); */
  NS_SCRIPTABLE NS_IMETHOD ConvertStringToUTF8(const nsACString & aString, const char *aCharset, PRBool aSkipCheck, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Ensure that |aSpec| (after URL-unescaping it) is encoded in UTF-8.  
   * If not,  convert it to UTF-8, assuming it's encoded in |aCharset|,  
   * and return the result.
   *
   * <p>Make sure that all characters outside US-ASCII in your input spec 
   * are url-escaped if  your spec is not in UTF-8 (before url-escaping) 
   * because the presence of non-ASCII characters is <strong>blindly</strong>
   * regarded as an indication that your input spec is in unescaped UTF-8
   * and it will be returned without further processing. No valid spec
   * going around in Mozilla code would break this assumption. 
   *
   * <p>XXX The above may change in the future depending on the usage pattern.
   *
   * @param aSpec an url-escaped URI spec to  ensure its UTF8ness
   * @param aCharset the charset to convert from if |aSpec| is not in UTF-8
   * @return the converted spec in UTF-8.
   * @throws NS_ERROR_UCONV_NOCONV when there is no decoder for aCharset
   *         or error code of nsIUnicodeDecoder in case of conversion failure
   */
  /* AUTF8String convertURISpecToUTF8 (in ACString aSpec, in string aCharset); */
  NS_SCRIPTABLE NS_IMETHOD ConvertURISpecToUTF8(const nsACString & aSpec, const char *aCharset, nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUTF8ConverterService, NS_IUTF8CONVERTERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUTF8CONVERTERSERVICE \
  NS_SCRIPTABLE NS_IMETHOD ConvertStringToUTF8(const nsACString & aString, const char *aCharset, PRBool aSkipCheck, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ConvertURISpecToUTF8(const nsACString & aSpec, const char *aCharset, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUTF8CONVERTERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertStringToUTF8(const nsACString & aString, const char *aCharset, PRBool aSkipCheck, nsACString & _retval NS_OUTPARAM) { return _to ConvertStringToUTF8(aString, aCharset, aSkipCheck, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertURISpecToUTF8(const nsACString & aSpec, const char *aCharset, nsACString & _retval NS_OUTPARAM) { return _to ConvertURISpecToUTF8(aSpec, aCharset, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUTF8CONVERTERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertStringToUTF8(const nsACString & aString, const char *aCharset, PRBool aSkipCheck, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertStringToUTF8(aString, aCharset, aSkipCheck, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertURISpecToUTF8(const nsACString & aSpec, const char *aCharset, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertURISpecToUTF8(aSpec, aCharset, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUTF8ConverterService : public nsIUTF8ConverterService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUTF8CONVERTERSERVICE

  nsUTF8ConverterService();

private:
  ~nsUTF8ConverterService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUTF8ConverterService, nsIUTF8ConverterService)

nsUTF8ConverterService::nsUTF8ConverterService()
{
  /* member initializers and constructor code */
}

nsUTF8ConverterService::~nsUTF8ConverterService()
{
  /* destructor code */
}

/* AUTF8String convertStringToUTF8 (in ACString aString, in string aCharset, in boolean aSkipCheck); */
NS_IMETHODIMP nsUTF8ConverterService::ConvertStringToUTF8(const nsACString & aString, const char *aCharset, PRBool aSkipCheck, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String convertURISpecToUTF8 (in ACString aSpec, in string aCharset); */
NS_IMETHODIMP nsUTF8ConverterService::ConvertURISpecToUTF8(const nsACString & aSpec, const char *aCharset, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUTF8ConverterService_h__ */
