/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/uconv/idl/nsITextToSubURI.idl
 */

#ifndef __gen_nsITextToSubURI_h__
#define __gen_nsITextToSubURI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// {8B042E22-6F87-11d3-B3C8-00805F8A6670}
#define NS_TEXTTOSUBURI_CID { 0x8b042e22, 0x6f87, 0x11d3, { 0xb3, 0xc8, 0x0, 0x80, 0x5f, 0x8a, 0x66, 0x70 } }
#define NS_ITEXTTOSUBURI_CONTRACTID "@mozilla.org/intl/texttosuburi;1"

/* starting interface:    nsITextToSubURI */
#define NS_ITEXTTOSUBURI_IID_STR "8b042e24-6f87-11d3-b3c8-00805f8a6670"

#define NS_ITEXTTOSUBURI_IID \
  {0x8b042e24, 0x6f87, 0x11d3, \
    { 0xb3, 0xc8, 0x00, 0x80, 0x5f, 0x8a, 0x66, 0x70 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITextToSubURI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITEXTTOSUBURI_IID)

  /* string ConvertAndEscape (in string charset, in wstring text); */
  NS_SCRIPTABLE NS_IMETHOD ConvertAndEscape(const char *charset, const PRUnichar *text, char **_retval NS_OUTPARAM) = 0;

  /* wstring UnEscapeAndConvert (in string charset, in string text); */
  NS_SCRIPTABLE NS_IMETHOD UnEscapeAndConvert(const char *charset, const char *text, PRUnichar **_retval NS_OUTPARAM) = 0;

  /**
   * Unescapes the given URI fragment (for UI purpose only)
   * Note: 
   * <ul>
   *  <li> escaping back the result (unescaped string) is not guaranteed to 
   *       give the original escaped string
   *  <li> In case of a conversion error, the URI fragment (escaped) is 
   *       assumed to be in UTF-8 and converted to AString (UTF-16)
   *  <li> Always succeeeds (callers don't need to do error checking)
   * </ul>
   *
   * @param aCharset the charset to convert from
   * @param aURIFragment the URI (or URI fragment) to unescape
   * @return Unescaped aURIFragment  converted to unicode
   */
  /* AString unEscapeURIForUI (in ACString aCharset, in AUTF8String aURIFragment); */
  NS_SCRIPTABLE NS_IMETHOD UnEscapeURIForUI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Unescapes only non ASCII characters in the given URI fragment 
   * note: this method assumes the URI as UTF-8 and fallbacks to the given charset
   * in case the data is not UTF-8
   *
   * @param aCharset the charset to convert from
   * @param aURIFragment the URI (or URI fragment) to unescape
   * @return Unescaped aURIFragment  converted to unicode
   * @throws NS_ERROR_UCONV_NOCONV when there is no decoder for aCharset
   *         or error code of nsIUnicodeDecoder in case of conversion failure
   */
  /* AString unEscapeNonAsciiURI (in ACString aCharset, in AUTF8String aURIFragment); */
  NS_SCRIPTABLE NS_IMETHOD UnEscapeNonAsciiURI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITextToSubURI, NS_ITEXTTOSUBURI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITEXTTOSUBURI \
  NS_SCRIPTABLE NS_IMETHOD ConvertAndEscape(const char *charset, const PRUnichar *text, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD UnEscapeAndConvert(const char *charset, const char *text, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD UnEscapeURIForUI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD UnEscapeNonAsciiURI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITEXTTOSUBURI(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertAndEscape(const char *charset, const PRUnichar *text, char **_retval NS_OUTPARAM) { return _to ConvertAndEscape(charset, text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnEscapeAndConvert(const char *charset, const char *text, PRUnichar **_retval NS_OUTPARAM) { return _to UnEscapeAndConvert(charset, text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnEscapeURIForUI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM) { return _to UnEscapeURIForUI(aCharset, aURIFragment, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnEscapeNonAsciiURI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM) { return _to UnEscapeNonAsciiURI(aCharset, aURIFragment, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITEXTTOSUBURI(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertAndEscape(const char *charset, const PRUnichar *text, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertAndEscape(charset, text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnEscapeAndConvert(const char *charset, const char *text, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnEscapeAndConvert(charset, text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnEscapeURIForUI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnEscapeURIForUI(aCharset, aURIFragment, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnEscapeNonAsciiURI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnEscapeNonAsciiURI(aCharset, aURIFragment, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTextToSubURI : public nsITextToSubURI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITEXTTOSUBURI

  nsTextToSubURI();

private:
  ~nsTextToSubURI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTextToSubURI, nsITextToSubURI)

nsTextToSubURI::nsTextToSubURI()
{
  /* member initializers and constructor code */
}

nsTextToSubURI::~nsTextToSubURI()
{
  /* destructor code */
}

/* string ConvertAndEscape (in string charset, in wstring text); */
NS_IMETHODIMP nsTextToSubURI::ConvertAndEscape(const char *charset, const PRUnichar *text, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring UnEscapeAndConvert (in string charset, in string text); */
NS_IMETHODIMP nsTextToSubURI::UnEscapeAndConvert(const char *charset, const char *text, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString unEscapeURIForUI (in ACString aCharset, in AUTF8String aURIFragment); */
NS_IMETHODIMP nsTextToSubURI::UnEscapeURIForUI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString unEscapeNonAsciiURI (in ACString aCharset, in AUTF8String aURIFragment); */
NS_IMETHODIMP nsTextToSubURI::UnEscapeNonAsciiURI(const nsACString & aCharset, const nsACString & aURIFragment, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITextToSubURI_h__ */
