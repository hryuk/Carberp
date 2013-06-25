/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/uconv/idl/nsICharsetConverterManager.idl
 */

#ifndef __gen_nsICharsetConverterManager_h__
#define __gen_nsICharsetConverterManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIAtom_h__
#include "nsIAtom.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsIUnicodeDecoder.h"
#include "nsIUnicodeEncoder.h"
#include "nsStringGlue.h"
// XXX change to NS_CHARSETCONVERTERMANAGER_CID
#define NS_ICHARSETCONVERTERMANAGER_CID \
  {0x3c1c0163, 0x9bd0, 0x11d3, { 0x9d, 0x9, 0x0, 0x50, 0x4, 0x0, 0x7, 0xb2}}
// XXX change to NS_CHARSETCONVERTERMANAGER_PID
#define NS_CHARSETCONVERTERMANAGER_CONTRACTID "@mozilla.org/charset-converter-manager;1"
class nsIUnicodeDecoder; /* forward declaration */

class nsIUnicodeEncoder; /* forward declaration */

class nsIUTF8StringEnumerator; /* forward declaration */


/* starting interface:    nsICharsetConverterManager */
#define NS_ICHARSETCONVERTERMANAGER_IID_STR "f5323a76-c8f7-4c65-8d0c-1250e969c7d5"

#define NS_ICHARSETCONVERTERMANAGER_IID \
  {0xf5323a76, 0xc8f7, 0x4c65, \
    { 0x8d, 0x0c, 0x12, 0x50, 0xe9, 0x69, 0xc7, 0xd5 }}

/**
 *
 * Here Charsets are identified by ASCII strings. Charset alias
 * resolution is provided by default in most methods. "Raw"
 * versions that do not need this resolution are also provided.
 *
 * @created         21/Feb/2000
 * @author  Catalin Rotaru [CATA]
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICharsetConverterManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHARSETCONVERTERMANAGER_IID)

  /**
     * Get the Unicode decoder for the given charset.
     * The "Raw" version skips charset alias resolution
     */
  /* nsIUnicodeDecoder getUnicodeDecoder (in string charset); */
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeDecoder(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM) = 0;

  /* nsIUnicodeDecoder getUnicodeDecoderRaw (in string charset); */
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeDecoderRaw(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM) = 0;

  /**
     * Get the Unicode encoder for the given charset.
     * The "Raw" version skips charset alias resolution
     */
  /* nsIUnicodeEncoder getUnicodeEncoder (in string charset); */
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeEncoder(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM) = 0;

  /* nsIUnicodeEncoder getUnicodeEncoderRaw (in string charset); */
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeEncoderRaw(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM) = 0;

  /**
     * A shortcut to calling nsICharsetAlias to do alias resolution
     */
  /* ACString getCharsetAlias (in string charset); */
  NS_SCRIPTABLE NS_IMETHOD GetCharsetAlias(const char *charset, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Get the complete list of available decoders.
     */
  /* nsIUTF8StringEnumerator getDecoderList (); */
  NS_SCRIPTABLE NS_IMETHOD GetDecoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Get the complete list of available encoders.
     */
  /* nsIUTF8StringEnumerator getEncoderList (); */
  NS_SCRIPTABLE NS_IMETHOD GetEncoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Get the complete list of available charset detectors.
     */
  /* nsIUTF8StringEnumerator GetCharsetDetectorList (); */
  NS_SCRIPTABLE NS_IMETHOD GetCharsetDetectorList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Get the human-readable name for the given charset.
     */
  /* AString getCharsetTitle (in string charset); */
  NS_SCRIPTABLE NS_IMETHOD GetCharsetTitle(const char *charset, nsAString & _retval NS_OUTPARAM) = 0;

  /**
     * Get some data about the given charset. This includes whether the 
     * character encoding may be used for certain purposes, if it is 
     * multi-byte, and the language code for it. See charsetData.properties
     * for the source of this data. Some known property names:
     *    notForBrowser  - not to be used in the bowser.
     *    notForOutgoing - not to be used for exporting files.
     *    LangGroup      - language code for charset, e.g. 'he' and 'zh-CN'.
     *    isMultibyte    - is this a multi-byte charset?
     * 
     * @param charset name of the character encoding, e.g. 'iso-8859-15'.
     * @param prop property desired for the character encoding.
     * @return the value of the property, for the character encoding.
     */
  /* AString getCharsetData (in string charset, in wstring prop); */
  NS_SCRIPTABLE NS_IMETHOD GetCharsetData(const char *charset, const PRUnichar *prop, nsAString & _retval NS_OUTPARAM) = 0;

  /**
     * Get the language group for the given charset. This is similar to 
     * calling <tt>getCharsetData</tt> with the <tt>prop</tt> "LangGroup".
     * 
     * @param charset name of the character encoding, e.g. 'iso-8859-15'.
     * @return the language code for the character encoding.
     */
  /* nsIAtom getCharsetLangGroup (in string charset); */
  NS_SCRIPTABLE NS_IMETHOD GetCharsetLangGroup(const char *charset, nsIAtom **_retval NS_OUTPARAM) = 0;

  /* nsIAtom getCharsetLangGroupRaw (in string charset); */
  NS_SCRIPTABLE NS_IMETHOD GetCharsetLangGroupRaw(const char *charset, nsIAtom **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICharsetConverterManager, NS_ICHARSETCONVERTERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHARSETCONVERTERMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeDecoder(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeDecoderRaw(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeEncoder(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeEncoderRaw(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetAlias(const char *charset, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDecoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEncoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetDetectorList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetTitle(const char *charset, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetData(const char *charset, const PRUnichar *prop, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetLangGroup(const char *charset, nsIAtom **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetLangGroupRaw(const char *charset, nsIAtom **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHARSETCONVERTERMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeDecoder(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM) { return _to GetUnicodeDecoder(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeDecoderRaw(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM) { return _to GetUnicodeDecoderRaw(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeEncoder(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM) { return _to GetUnicodeEncoder(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeEncoderRaw(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM) { return _to GetUnicodeEncoderRaw(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetAlias(const char *charset, nsACString & _retval NS_OUTPARAM) { return _to GetCharsetAlias(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDecoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return _to GetDecoderList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return _to GetEncoderList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetDetectorList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return _to GetCharsetDetectorList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetTitle(const char *charset, nsAString & _retval NS_OUTPARAM) { return _to GetCharsetTitle(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetData(const char *charset, const PRUnichar *prop, nsAString & _retval NS_OUTPARAM) { return _to GetCharsetData(charset, prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetLangGroup(const char *charset, nsIAtom **_retval NS_OUTPARAM) { return _to GetCharsetLangGroup(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetLangGroupRaw(const char *charset, nsIAtom **_retval NS_OUTPARAM) { return _to GetCharsetLangGroupRaw(charset, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHARSETCONVERTERMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeDecoder(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeDecoder(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeDecoderRaw(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeDecoderRaw(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeEncoder(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeEncoder(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeEncoderRaw(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeEncoderRaw(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetAlias(const char *charset, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetAlias(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDecoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDecoderList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncoderList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetDetectorList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetDetectorList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetTitle(const char *charset, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetTitle(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetData(const char *charset, const PRUnichar *prop, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetData(charset, prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetLangGroup(const char *charset, nsIAtom **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetLangGroup(charset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetLangGroupRaw(const char *charset, nsIAtom **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetLangGroupRaw(charset, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCharsetConverterManager : public nsICharsetConverterManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHARSETCONVERTERMANAGER

  nsCharsetConverterManager();

private:
  ~nsCharsetConverterManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCharsetConverterManager, nsICharsetConverterManager)

nsCharsetConverterManager::nsCharsetConverterManager()
{
  /* member initializers and constructor code */
}

nsCharsetConverterManager::~nsCharsetConverterManager()
{
  /* destructor code */
}

/* nsIUnicodeDecoder getUnicodeDecoder (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetUnicodeDecoder(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUnicodeDecoder getUnicodeDecoderRaw (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetUnicodeDecoderRaw(const char *charset, nsIUnicodeDecoder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUnicodeEncoder getUnicodeEncoder (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetUnicodeEncoder(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUnicodeEncoder getUnicodeEncoderRaw (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetUnicodeEncoderRaw(const char *charset, nsIUnicodeEncoder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getCharsetAlias (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetAlias(const char *charset, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator getDecoderList (); */
NS_IMETHODIMP nsCharsetConverterManager::GetDecoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator getEncoderList (); */
NS_IMETHODIMP nsCharsetConverterManager::GetEncoderList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator GetCharsetDetectorList (); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetDetectorList(nsIUTF8StringEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCharsetTitle (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetTitle(const char *charset, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCharsetData (in string charset, in wstring prop); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetData(const char *charset, const PRUnichar *prop, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAtom getCharsetLangGroup (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetLangGroup(const char *charset, nsIAtom **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAtom getCharsetLangGroupRaw (in string charset); */
NS_IMETHODIMP nsCharsetConverterManager::GetCharsetLangGroupRaw(const char *charset, nsIAtom **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICharsetConverterManager_h__ */
