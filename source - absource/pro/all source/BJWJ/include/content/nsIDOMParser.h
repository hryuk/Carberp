/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIDOMParser.idl
 */

#ifndef __gen_nsIDOMParser_h__
#define __gen_nsIDOMParser_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIScriptGlobalObject; /* forward declaration */


/* starting interface:    nsIDOMParser */
#define NS_IDOMPARSER_IID_STR "5677f36e-1842-4c6f-a39c-2e5576ab8b40"

#define NS_IDOMPARSER_IID \
  {0x5677f36e, 0x1842, 0x4c6f, \
    { 0xa3, 0x9c, 0x2e, 0x55, 0x76, 0xab, 0x8b, 0x40 }}

/**
 * The nsIDOMParser interface is a non-SAX interface that can be used
 * to parse a string or byte stream containing XML or HTML content
 * to a DOM document. Parsing is always synchronous - a document is always
 * returned from the parsing methods. This is as opposed to loading and
 * parsing with the XMLHttpRequest interface, which can be used for
 * asynchronous (callback-based) loading.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMParser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPARSER_IID)

  /**
   * The string passed in is parsed into a DOM document.
   *
   * @param str The UTF16 string to be parsed
   * @param contentType The content type of the string (see parseFromStream)
   * @returns The DOM document created as a result of parsing the 
   *          string
   */
  /* nsIDOMDocument parseFromString (in wstring str, in string contentType); */
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const PRUnichar *str, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

  /**
   * The buffer is parsed into a DOM document.
   * The charset is determined from the xml entity decl.
   *
   * @param buf The octet array data to be parsed
   * @param bufLen Length (in bytes) of the data
   * @param contentType The content type of the data (see parseFromStream)
   * @returns The DOM document created as a result of parsing the 
   *          string
   */
  /* nsIDOMDocument parseFromBuffer ([array, size_is (bufLen), const] in octet buf, in PRUint32 bufLen, in string contentType); */
  NS_SCRIPTABLE NS_IMETHOD ParseFromBuffer(const PRUint8 *buf, PRUint32 bufLen, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

  /**
   * The byte stream passed in is parsed into a DOM document.
   *
   * Not accessible from web content.
   *
   * @param stream The byte stream whose contents are parsed
   * @param charset The character set that was used to encode the byte
   *                stream. NULL if not specified.
   * @param contentLength The number of bytes in the input stream.
   * @param contentType The content type of the string - either text/xml,
   *                    application/xml, or application/xhtml+xml.
   *                    Must not be NULL.
   * @returns The DOM document created as a result of parsing the 
   *          stream
   */
  /* nsIDOMDocument parseFromStream (in nsIInputStream stream, in string charset, in long contentLength, in string contentType); */
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char *charset, PRInt32 contentLength, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

  /**
   * Initialize the principal and document and base URIs that the parser should
   * use for documents it creates.  If this is not called, then a null
   * principal and its URI will be used.  When creating a DOMParser via the JS
   * constructor, this will be called automatically.  This method may only be
   * called once.  If this method fails, all following parse attempts will
   * fail.
   *
   * @param principal The principal to use for documents we create.
   *                  If this is null, a codebase principal will be created
   *                  based on documentURI; in that case the documentURI must
   *                  be non-null.
   * @param documentURI The documentURI to use for the documents we create.
   *                    If null, the principal's URI will be used;
   *                    in that case, the principal must be non-null and its
   *                    URI must be non-null.
   * @param baseURI The baseURI to use for the documents we create.
   *                If null, the documentURI will be used.
   * @param scriptObject The object from which the context for event handling
   *                     can be got.
   */
  /* [noscript] void init (in nsIPrincipal principal, in nsIURI documentURI, in nsIURI baseURI, in nsIScriptGlobalObject scriptObject); */
  NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMParser, NS_IDOMPARSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPARSER \
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const PRUnichar *str, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseFromBuffer(const PRUint8 *buf, PRUint32 bufLen, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char *charset, PRInt32 contentLength, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM); \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const PRUnichar *str, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM) { return _to ParseFromString(str, contentType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromBuffer(const PRUint8 *buf, PRUint32 bufLen, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM) { return _to ParseFromBuffer(buf, bufLen, contentType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char *charset, PRInt32 contentLength, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM) { return _to ParseFromStream(stream, charset, contentLength, contentType, _retval); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject) { return _to Init(principal, documentURI, baseURI, scriptObject); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const PRUnichar *str, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromString(str, contentType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromBuffer(const PRUint8 *buf, PRUint32 bufLen, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromBuffer(buf, bufLen, contentType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char *charset, PRInt32 contentLength, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromStream(stream, charset, contentLength, contentType, _retval); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(principal, documentURI, baseURI, scriptObject); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMParser : public nsIDOMParser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPARSER

  nsDOMParser();

private:
  ~nsDOMParser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMParser, nsIDOMParser)

nsDOMParser::nsDOMParser()
{
  /* member initializers and constructor code */
}

nsDOMParser::~nsDOMParser()
{
  /* destructor code */
}

/* nsIDOMDocument parseFromString (in wstring str, in string contentType); */
NS_IMETHODIMP nsDOMParser::ParseFromString(const PRUnichar *str, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument parseFromBuffer ([array, size_is (bufLen), const] in octet buf, in PRUint32 bufLen, in string contentType); */
NS_IMETHODIMP nsDOMParser::ParseFromBuffer(const PRUint8 *buf, PRUint32 bufLen, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument parseFromStream (in nsIInputStream stream, in string charset, in long contentLength, in string contentType); */
NS_IMETHODIMP nsDOMParser::ParseFromStream(nsIInputStream *stream, const char *charset, PRInt32 contentLength, const char *contentType, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIPrincipal principal, in nsIURI documentURI, in nsIURI baseURI, in nsIScriptGlobalObject scriptObject); */
NS_IMETHODIMP nsDOMParser::Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI, nsIScriptGlobalObject *scriptObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMParserJS */
#define NS_IDOMPARSERJS_IID_STR "ba6bcd6c-63d8-49b3-bc8a-1e5e895645bc"

#define NS_IDOMPARSERJS_IID \
  {0xba6bcd6c, 0x63d8, 0x49b3, \
    { 0xbc, 0x8a, 0x1e, 0x5e, 0x89, 0x56, 0x45, 0xbc }}

/**
 * The nsIDOMParserJS interface provides a scriptable way of calling init().
 * Do NOT use this interface from languages other than JavaScript.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMParserJS : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPARSERJS_IID)

  /**
   * Just like nsIDOMParser.init, but callable from JS.
   */
  /* void init (in nsIPrincipal principal, in nsIURI documentURI, in nsIURI baseURI); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMParserJS, NS_IDOMPARSERJS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPARSERJS \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPARSERJS(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI) { return _to Init(principal, documentURI, baseURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPARSERJS(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(principal, documentURI, baseURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMParserJS : public nsIDOMParserJS
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPARSERJS

  nsDOMParserJS();

private:
  ~nsDOMParserJS();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMParserJS, nsIDOMParserJS)

nsDOMParserJS::nsDOMParserJS()
{
  /* member initializers and constructor code */
}

nsDOMParserJS::~nsDOMParserJS()
{
  /* destructor code */
}

/* void init (in nsIPrincipal principal, in nsIURI documentURI, in nsIURI baseURI); */
NS_IMETHODIMP nsDOMParserJS::Init(nsIPrincipal *principal, nsIURI *documentURI, nsIURI *baseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_DOMPARSER_CID                            \
 { /* 3a8a3a50-512c-11d4-9a54-000064657374 */       \
   0x3a8a3a50, 0x512c, 0x11d4,                      \
  {0x9a, 0x54, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74} }
#define NS_DOMPARSER_CONTRACTID \
"@mozilla.org/xmlextras/domparser;1"

#endif /* __gen_nsIDOMParser_h__ */
