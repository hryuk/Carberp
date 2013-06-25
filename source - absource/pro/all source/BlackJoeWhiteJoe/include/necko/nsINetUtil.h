/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsINetUtil.idl
 */

#ifndef __gen_nsINetUtil_h__
#define __gen_nsINetUtil_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIPrefBranch; /* forward declaration */


/* starting interface:    nsINetUtil */
#define NS_INETUTIL_IID_STR "57322c6f-f4ec-4e46-8253-b74be220de16"

#define NS_INETUTIL_IID \
  {0x57322c6f, 0xf4ec, 0x4e46, \
    { 0x82, 0x53, 0xb7, 0x4b, 0xe2, 0x20, 0xde, 0x16 }}

/**
 * nsINetUtil provides various network-related utility methods.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINetUtil : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETUTIL_IID)

  /**
   * Parse a content-type header and return the content type and
   * charset (if any).
   *
   * @param aTypeHeader the header string to parse
   * @param [out] aCharset the charset parameter specified in the
   *              header, if any.
   * @param [out] aHadCharset whether a charset was explicitly specified.
   * @return the MIME type specified in the header, in lower-case.
   */
  /* AUTF8String parseContentType (in AUTF8String aTypeHeader, out AUTF8String aCharset, out boolean aHadCharset); */
  NS_SCRIPTABLE NS_IMETHOD ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRBool *aHadCharset NS_OUTPARAM, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Test whether the given URI's handler has the given protocol flags.
   *
   * @param aURI the URI in question
   * @param aFlags the flags we're testing for.
   *
   * @return whether the protocol handler for aURI has all the flags
   *         in aFlags.
   */
  /* boolean protocolHasFlags (in nsIURI aURI, in unsigned long aFlag); */
  NS_SCRIPTABLE NS_IMETHOD ProtocolHasFlags(nsIURI *aURI, PRUint32 aFlag, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Test whether the protocol handler for this URI or that for any of
   * its inner URIs has the given protocol flags.  This will QI aURI to
   * nsINestedURI and walk the nested URI chain.
   *
   * @param aURI the URI in question
   * @param aFlags the flags we're testing for.
   *
   * @return whether any of the protocol handlers involved have all the flags
   *         in aFlags.
   */
  /* boolean URIChainHasFlags (in nsIURI aURI, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD URIChainHasFlags(nsIURI *aURI, PRUint32 aFlags, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Take aURI and produce an immutable version of it for the caller.  If aURI
   * is immutable this will be aURI itself; otherwise this will be a clone,
   * marked immutable if possible.  Passing null to this method is allowed; in
   * that case it will return null.
   */
  /* nsIURI toImmutableURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD ToImmutableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM) = 0;

  /** Escape every character with its %XX-escaped equivalent */
  enum { ESCAPE_ALL = 0U };

  /** Leave alphanumeric characters intact and %XX-escape all others */
  enum { ESCAPE_XALPHAS = 1U };

  /** Leave alphanumeric characters intact, convert spaces to '+',
      %XX-escape all others */
  enum { ESCAPE_XPALPHAS = 2U };

  /** Leave alphanumeric characters and forward slashes intact,
      %XX-escape all others */
  enum { ESCAPE_URL_PATH = 4U };

  /**
   * escape a string with %00-style escaping
   */
  /* ACString escapeString (in ACString aString, in unsigned long aEscapeType); */
  NS_SCRIPTABLE NS_IMETHOD EscapeString(const nsACString & aString, PRUint32 aEscapeType, nsACString & _retval NS_OUTPARAM) = 0;

  /** %XX-escape URL scheme */
  enum { ESCAPE_URL_SCHEME = 1U };

  /** %XX-escape username in the URL */
  enum { ESCAPE_URL_USERNAME = 2U };

  /** %XX-escape password in the URL */
  enum { ESCAPE_URL_PASSWORD = 4U };

  /** %XX-escape URL host */
  enum { ESCAPE_URL_HOST = 8U };

  /** %XX-escape URL directory */
  enum { ESCAPE_URL_DIRECTORY = 16U };

  /** %XX-escape file basename in the URL */
  enum { ESCAPE_URL_FILE_BASENAME = 32U };

  /** %XX-escape file extension in the URL */
  enum { ESCAPE_URL_FILE_EXTENSION = 64U };

  /** %XX-escape URL parameters */
  enum { ESCAPE_URL_PARAM = 128U };

  /** %XX-escape URL query */
  enum { ESCAPE_URL_QUERY = 256U };

  /** %XX-escape URL ref */
  enum { ESCAPE_URL_REF = 512U };

  /** %XX-escape URL path - same as escaping directory, basename and extension */
  enum { ESCAPE_URL_FILEPATH = 112U };

  /** %XX-escape scheme, username, password, host, path, params, query and ref */
  enum { ESCAPE_URL_MINIMAL = 1023U };

  /** Force %XX-escaping of already escaped sequences */
  enum { ESCAPE_URL_FORCED = 1024U };

  /** Skip non-ascii octets, %XX-escape all others */
  enum { ESCAPE_URL_ONLY_ASCII = 2048U };

  /** 
   * Skip graphic octets (0x20-0x7E) when escaping
   * Skips all ASCII octets (0x00-0x7F) when unescaping 
   */
  enum { ESCAPE_URL_ONLY_NONASCII = 4096U };

  /** Force %XX-escape of colon */
  enum { ESCAPE_URL_COLON = 16384U };

  /** Skip C0 and DEL from unescaping */
  enum { ESCAPE_URL_SKIP_CONTROL = 32768U };

  /**
   * %XX-Escape invalid chars in a URL segment. 
   *
   * @param aStr the URL to be escaped
   * @param aFlags the URL segment type flags
   *
   * @return the escaped string (the string itself if escaping did not happen)
   *
   */
  /* ACString escapeURL (in ACString aStr, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD EscapeURL(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Expands URL escape sequences
   *
   * @param aStr the URL to be unescaped
   * @param aFlags only ESCAPE_URL_ONLY_NONASCII and ESCAPE_URL_SKIP_CONTROL
   *               are recognized.  If |aFlags| is 0 all escape sequences are 
   *               unescaped
   * @return unescaped string
   */
  /* ACString unescapeString (in ACString aStr, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD UnescapeString(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Extract the charset parameter location and value from a content-type
   * header.
   *
   * @param aTypeHeader the header string to parse
   * @param [out] aCharset the charset parameter specified in the
   *              header, if any.
   * @param [out] aCharsetStart index of the start of the charset parameter
   *              (the ';' separating it from what came before) in aTypeHeader.
   *              If this function returns false, this argument will still be
   *              set, to the index of the location where a new charset should
   *              be inserted.
   * @param [out] aCharsetEnd index of the end of the charset parameter (the
   *              ';' separating it from what comes after, or the end
   *              of the string) in aTypeHeader.  If this function returns
   *              false, this argument will still be set, to the index of the
   *              location where a new charset should be inserted.
   *
   * @return whether a charset parameter was found.  This can be false even in
   * cases when parseContentType would claim to have a charset, if the type
   * that won out does not have a charset parameter specified.
   */
  /* boolean extractCharsetFromContentType (in AUTF8String aTypeHeader, out AUTF8String aCharset, out long aCharsetStart, out long aCharsetEnd); */
  NS_SCRIPTABLE NS_IMETHOD ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRInt32 *aCharsetStart NS_OUTPARAM, PRInt32 *aCharsetEnd NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetUtil, NS_INETUTIL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETUTIL \
  NS_SCRIPTABLE NS_IMETHOD ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRBool *aHadCharset NS_OUTPARAM, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ProtocolHasFlags(nsIURI *aURI, PRUint32 aFlag, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD URIChainHasFlags(nsIURI *aURI, PRUint32 aFlags, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ToImmutableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EscapeString(const nsACString & aString, PRUint32 aEscapeType, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EscapeURL(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD UnescapeString(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRInt32 *aCharsetStart NS_OUTPARAM, PRInt32 *aCharsetEnd NS_OUTPARAM, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETUTIL(_to) \
  NS_SCRIPTABLE NS_IMETHOD ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRBool *aHadCharset NS_OUTPARAM, nsACString & _retval NS_OUTPARAM) { return _to ParseContentType(aTypeHeader, aCharset, aHadCharset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ProtocolHasFlags(nsIURI *aURI, PRUint32 aFlag, PRBool *_retval NS_OUTPARAM) { return _to ProtocolHasFlags(aURI, aFlag, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD URIChainHasFlags(nsIURI *aURI, PRUint32 aFlags, PRBool *_retval NS_OUTPARAM) { return _to URIChainHasFlags(aURI, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToImmutableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM) { return _to ToImmutableURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EscapeString(const nsACString & aString, PRUint32 aEscapeType, nsACString & _retval NS_OUTPARAM) { return _to EscapeString(aString, aEscapeType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EscapeURL(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM) { return _to EscapeURL(aStr, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnescapeString(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM) { return _to UnescapeString(aStr, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRInt32 *aCharsetStart NS_OUTPARAM, PRInt32 *aCharsetEnd NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to ExtractCharsetFromContentType(aTypeHeader, aCharset, aCharsetStart, aCharsetEnd, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETUTIL(_to) \
  NS_SCRIPTABLE NS_IMETHOD ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRBool *aHadCharset NS_OUTPARAM, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseContentType(aTypeHeader, aCharset, aHadCharset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ProtocolHasFlags(nsIURI *aURI, PRUint32 aFlag, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProtocolHasFlags(aURI, aFlag, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD URIChainHasFlags(nsIURI *aURI, PRUint32 aFlags, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->URIChainHasFlags(aURI, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToImmutableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToImmutableURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EscapeString(const nsACString & aString, PRUint32 aEscapeType, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EscapeString(aString, aEscapeType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EscapeURL(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EscapeURL(aStr, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnescapeString(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnescapeString(aStr, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRInt32 *aCharsetStart NS_OUTPARAM, PRInt32 *aCharsetEnd NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtractCharsetFromContentType(aTypeHeader, aCharset, aCharsetStart, aCharsetEnd, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetUtil : public nsINetUtil
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETUTIL

  nsNetUtil();

private:
  ~nsNetUtil();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNetUtil, nsINetUtil)

nsNetUtil::nsNetUtil()
{
  /* member initializers and constructor code */
}

nsNetUtil::~nsNetUtil()
{
  /* destructor code */
}

/* AUTF8String parseContentType (in AUTF8String aTypeHeader, out AUTF8String aCharset, out boolean aHadCharset); */
NS_IMETHODIMP nsNetUtil::ParseContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRBool *aHadCharset NS_OUTPARAM, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean protocolHasFlags (in nsIURI aURI, in unsigned long aFlag); */
NS_IMETHODIMP nsNetUtil::ProtocolHasFlags(nsIURI *aURI, PRUint32 aFlag, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean URIChainHasFlags (in nsIURI aURI, in unsigned long aFlags); */
NS_IMETHODIMP nsNetUtil::URIChainHasFlags(nsIURI *aURI, PRUint32 aFlags, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI toImmutableURI (in nsIURI aURI); */
NS_IMETHODIMP nsNetUtil::ToImmutableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString escapeString (in ACString aString, in unsigned long aEscapeType); */
NS_IMETHODIMP nsNetUtil::EscapeString(const nsACString & aString, PRUint32 aEscapeType, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString escapeURL (in ACString aStr, in unsigned long aFlags); */
NS_IMETHODIMP nsNetUtil::EscapeURL(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString unescapeString (in ACString aStr, in unsigned long aFlags); */
NS_IMETHODIMP nsNetUtil::UnescapeString(const nsACString & aStr, PRUint32 aFlags, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean extractCharsetFromContentType (in AUTF8String aTypeHeader, out AUTF8String aCharset, out long aCharsetStart, out long aCharsetEnd); */
NS_IMETHODIMP nsNetUtil::ExtractCharsetFromContentType(const nsACString & aTypeHeader, nsACString & aCharset NS_OUTPARAM, PRInt32 *aCharsetStart NS_OUTPARAM, PRInt32 *aCharsetEnd NS_OUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINetUtil_h__ */
