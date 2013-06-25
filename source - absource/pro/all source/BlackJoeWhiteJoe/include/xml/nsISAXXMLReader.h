/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/xml/public/nsISAXXMLReader.idl
 */

#ifndef __gen_nsISAXXMLReader_h__
#define __gen_nsISAXXMLReader_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIRequestObserver; /* forward declaration */

class nsIURI; /* forward declaration */

class nsISAXContentHandler; /* forward declaration */

class nsISAXDTDHandler; /* forward declaration */

class nsISAXEntityResolver; /* forward declaration */

class nsISAXErrorHandler; /* forward declaration */

class nsISAXLexicalHandler; /* forward declaration */


/* starting interface:    nsISAXXMLReader */
#define NS_ISAXXMLREADER_IID_STR "5556997e-d816-4218-8b54-803d4261206e"

#define NS_ISAXXMLREADER_IID \
  {0x5556997e, 0xd816, 0x4218, \
    { 0x8b, 0x54, 0x80, 0x3d, 0x42, 0x61, 0x20, 0x6e }}

/**
 * Interface for reading an XML document using callbacks.
 *
 * nsISAXXMLReader is the interface that an XML parser's SAX2
 * driver must implement.  This interface allows an application to set
 * and query features and properties in the parser, to register event
 * handlers for document processing, and to initiate a document
 * parse.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISAXXMLReader : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXXMLREADER_IID)

  /**
   * The base URI.
   */
  /* attribute nsIURI baseURI; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBaseURI(nsIURI * aBaseURI) = 0;

  /**
   * If the application does not register a content handler, all
   * content events reported by the SAX parser will be silently
   * ignored.
   *
   * Applications may register a new or different handler in the
   * middle of a parse, and the SAX parser must begin using the new
   * handler immediately.
   */
  /* attribute nsISAXContentHandler contentHandler; */
  NS_SCRIPTABLE NS_IMETHOD GetContentHandler(nsISAXContentHandler * *aContentHandler) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContentHandler(nsISAXContentHandler * aContentHandler) = 0;

  /**
   * If the application does not register a DTD handler, all DTD
   * events reported by the SAX parser will be silently ignored.
   *
   * Applications may register a new or different handler in the
   * middle of a parse, and the SAX parser must begin using the new
   * handler immediately.
   */
  /* attribute nsISAXDTDHandler dtdHandler; */
  NS_SCRIPTABLE NS_IMETHOD GetDtdHandler(nsISAXDTDHandler * *aDtdHandler) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDtdHandler(nsISAXDTDHandler * aDtdHandler) = 0;

  /**
   * If the application does not register an error handler, all
   * error events reported by the SAX parser will be silently ignored;
   * however, normal processing may not continue.  It is highly
   * recommended that all SAX applications implement an error handler
   * to avoid unexpected bugs.
   *
   * Applications may register a new or different handler in the
   * middle of a parse, and the SAX parser must begin using the new
   * handler immediately.
   */
  /* attribute nsISAXErrorHandler errorHandler; */
  NS_SCRIPTABLE NS_IMETHOD GetErrorHandler(nsISAXErrorHandler * *aErrorHandler) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetErrorHandler(nsISAXErrorHandler * aErrorHandler) = 0;

  /**
   * If the application does not register a lexical handler, all
   * lexical events (e.g. startDTD) reported by the SAX parser will be
   * silently ignored.
   *
   * Applications may register a new or different handler in the
   * middle of a parse, and the SAX parser must begin using the new
   * handler immediately.
   */
  /* attribute nsISAXLexicalHandler lexicalHandler; */
  NS_SCRIPTABLE NS_IMETHOD GetLexicalHandler(nsISAXLexicalHandler * *aLexicalHandler) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLexicalHandler(nsISAXLexicalHandler * aLexicalHandler) = 0;

  /**
   * Set the value of a feature flag. NOT CURRENTLY IMPLEMENTED.
   *
   * The feature name is any fully-qualified URI.  It is possible
   * for an XMLReader to expose a feature value but to be unable to
   * change the current value.  Some feature values may be immutable
   * or mutable only in specific contexts, such as before, during, or
   * after a parse.
   *
   * All XMLReaders are required to support setting
   * http://xml.org/sax/features/namespaces to true and
   * http://xml.org/sax/features/namespace-prefixes to false.
   *
   * @param name String flag for a parser feature.
   * @param value Turn the feature on/off.
   */
  /* void setFeature (in AString name, in boolean value); */
  NS_SCRIPTABLE NS_IMETHOD SetFeature(const nsAString & name, PRBool value) = 0;

  /**
   * Look up the value of a feature flag. NOT CURRENTLY IMPLEMENTED.
   *
   * The feature name is any fully-qualified URI.  It is
   * possible for an XMLReader to recognize a feature name but
   * temporarily be unable to return its value.
   * Some feature values may be available only in specific
   * contexts, such as before, during, or after a parse.
   *
   * All XMLReaders are required to recognize the
   * http://xml.org/sax/features/namespaces and the
   * http://xml.org/sax/features/namespace-prefixes feature names.
   *
   * @param name String flag for a parser feature.
   */
  /* boolean getFeature (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD GetFeature(const nsAString & name, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Set the value of a property. NOT CURRENTLY IMPLEMENTED.
   *
   * The property name is any fully-qualified URI.  It is possible
   * for an XMLReader to recognize a property name but to be unable to
   * change the current value.  Some property values may be immutable
   * or mutable only in specific contexts, such as before, during, or
   * after a parse.
   *
   * XMLReaders are not required to recognize setting any specific
   * property names, though a core set is defined by SAX2.
   *
   * This method is also the standard mechanism for setting
   * extended handlers.
   *
   * @param name String flag for a parser feature
   * @param value Turn the feature on/off.
   */
  /* void setProperty (in AString name, in nsISupports value); */
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const nsAString & name, nsISupports *value) = 0;

  /**
   * Look up the value of a property. NOT CURRENTLY IMPLEMENTED.
   *
   * The property name is any fully-qualified URI.  It is
   * possible for an XMLReader to recognize a property name but
   * temporarily be unable to return its value.
   * Some property values may be available only in specific
   * contexts, such as before, during, or after a parse.
   *
   * XMLReaders are not required to recognize any specific
   * property names, though an initial core set is documented for
   * SAX2.
   *
   * Implementors are free (and encouraged) to invent their own properties,
   * using names built on their own URIs.
   *
   * @param name The property name, which is a fully-qualified URI.
   * @return The current value of the property.
   */
  /* boolean getProperty (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const nsAString & name, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   *
   * @param str The UTF16 string to be parsed
   * @param contentType The content type of the string (see parseFromStream)
   *
   */
  /* void parseFromString (in AString str, in string contentType); */
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const nsAString & str, const char *contentType) = 0;

  /**
   *
   * @param stream The byte stream whose contents are parsed
   * @param charset The character set that was used to encode the byte
   *                stream. NULL if not specified.
   * @param contentType The content type of the string - either text/xml,
   *                    application/xml, or application/xhtml+xml.
   *                    Must not be NULL.
   *
   */
  /* void parseFromStream (in nsIInputStream stream, in string charset, in string contentType); */
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char *charset, const char *contentType) = 0;

  /**
   * Begin an asynchronous parse. This method initializes the parser,
   * and must be called before any nsIStreamListener methods. It is
   * then the caller's duty to call nsIStreamListener methods to drive
   * the parser. Once this method is called, the caller must not call
   * one of the other parse methods.
   *
   * @param observer The nsIRequestObserver to notify upon start or stop.
   *                 Can be NULL.
   */
  /* void parseAsync (in nsIRequestObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRequestObserver *observer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXXMLReader, NS_ISAXXMLREADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXXMLREADER \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI); \
  NS_SCRIPTABLE NS_IMETHOD SetBaseURI(nsIURI * aBaseURI); \
  NS_SCRIPTABLE NS_IMETHOD GetContentHandler(nsISAXContentHandler * *aContentHandler); \
  NS_SCRIPTABLE NS_IMETHOD SetContentHandler(nsISAXContentHandler * aContentHandler); \
  NS_SCRIPTABLE NS_IMETHOD GetDtdHandler(nsISAXDTDHandler * *aDtdHandler); \
  NS_SCRIPTABLE NS_IMETHOD SetDtdHandler(nsISAXDTDHandler * aDtdHandler); \
  NS_SCRIPTABLE NS_IMETHOD GetErrorHandler(nsISAXErrorHandler * *aErrorHandler); \
  NS_SCRIPTABLE NS_IMETHOD SetErrorHandler(nsISAXErrorHandler * aErrorHandler); \
  NS_SCRIPTABLE NS_IMETHOD GetLexicalHandler(nsISAXLexicalHandler * *aLexicalHandler); \
  NS_SCRIPTABLE NS_IMETHOD SetLexicalHandler(nsISAXLexicalHandler * aLexicalHandler); \
  NS_SCRIPTABLE NS_IMETHOD SetFeature(const nsAString & name, PRBool value); \
  NS_SCRIPTABLE NS_IMETHOD GetFeature(const nsAString & name, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const nsAString & name, nsISupports *value); \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const nsAString & name, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const nsAString & str, const char *contentType); \
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char *charset, const char *contentType); \
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRequestObserver *observer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXXMLREADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) { return _to GetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseURI(nsIURI * aBaseURI) { return _to SetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentHandler(nsISAXContentHandler * *aContentHandler) { return _to GetContentHandler(aContentHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentHandler(nsISAXContentHandler * aContentHandler) { return _to SetContentHandler(aContentHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetDtdHandler(nsISAXDTDHandler * *aDtdHandler) { return _to GetDtdHandler(aDtdHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetDtdHandler(nsISAXDTDHandler * aDtdHandler) { return _to SetDtdHandler(aDtdHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorHandler(nsISAXErrorHandler * *aErrorHandler) { return _to GetErrorHandler(aErrorHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetErrorHandler(nsISAXErrorHandler * aErrorHandler) { return _to SetErrorHandler(aErrorHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetLexicalHandler(nsISAXLexicalHandler * *aLexicalHandler) { return _to GetLexicalHandler(aLexicalHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetLexicalHandler(nsISAXLexicalHandler * aLexicalHandler) { return _to SetLexicalHandler(aLexicalHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetFeature(const nsAString & name, PRBool value) { return _to SetFeature(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeature(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return _to GetFeature(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const nsAString & name, nsISupports *value) { return _to SetProperty(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return _to GetProperty(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const nsAString & str, const char *contentType) { return _to ParseFromString(str, contentType); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char *charset, const char *contentType) { return _to ParseFromStream(stream, charset, contentType); } \
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRequestObserver *observer) { return _to ParseAsync(observer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXXMLREADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseURI(nsIURI * aBaseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentHandler(nsISAXContentHandler * *aContentHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentHandler(aContentHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentHandler(nsISAXContentHandler * aContentHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentHandler(aContentHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetDtdHandler(nsISAXDTDHandler * *aDtdHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDtdHandler(aDtdHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetDtdHandler(nsISAXDTDHandler * aDtdHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDtdHandler(aDtdHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorHandler(nsISAXErrorHandler * *aErrorHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorHandler(aErrorHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetErrorHandler(nsISAXErrorHandler * aErrorHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetErrorHandler(aErrorHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetLexicalHandler(nsISAXLexicalHandler * *aLexicalHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLexicalHandler(aLexicalHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetLexicalHandler(nsISAXLexicalHandler * aLexicalHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLexicalHandler(aLexicalHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetFeature(const nsAString & name, PRBool value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFeature(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeature(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeature(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const nsAString & name, nsISupports *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProperty(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperty(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromString(const nsAString & str, const char *contentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromString(str, contentType); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFromStream(nsIInputStream *stream, const char *charset, const char *contentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFromStream(stream, charset, contentType); } \
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRequestObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseAsync(observer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXXMLReader : public nsISAXXMLReader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXXMLREADER

  nsSAXXMLReader();

private:
  ~nsSAXXMLReader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXXMLReader, nsISAXXMLReader)

nsSAXXMLReader::nsSAXXMLReader()
{
  /* member initializers and constructor code */
}

nsSAXXMLReader::~nsSAXXMLReader()
{
  /* destructor code */
}

/* attribute nsIURI baseURI; */
NS_IMETHODIMP nsSAXXMLReader::GetBaseURI(nsIURI * *aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSAXXMLReader::SetBaseURI(nsIURI * aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISAXContentHandler contentHandler; */
NS_IMETHODIMP nsSAXXMLReader::GetContentHandler(nsISAXContentHandler * *aContentHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSAXXMLReader::SetContentHandler(nsISAXContentHandler * aContentHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISAXDTDHandler dtdHandler; */
NS_IMETHODIMP nsSAXXMLReader::GetDtdHandler(nsISAXDTDHandler * *aDtdHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSAXXMLReader::SetDtdHandler(nsISAXDTDHandler * aDtdHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISAXErrorHandler errorHandler; */
NS_IMETHODIMP nsSAXXMLReader::GetErrorHandler(nsISAXErrorHandler * *aErrorHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSAXXMLReader::SetErrorHandler(nsISAXErrorHandler * aErrorHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISAXLexicalHandler lexicalHandler; */
NS_IMETHODIMP nsSAXXMLReader::GetLexicalHandler(nsISAXLexicalHandler * *aLexicalHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSAXXMLReader::SetLexicalHandler(nsISAXLexicalHandler * aLexicalHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFeature (in AString name, in boolean value); */
NS_IMETHODIMP nsSAXXMLReader::SetFeature(const nsAString & name, PRBool value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getFeature (in AString name); */
NS_IMETHODIMP nsSAXXMLReader::GetFeature(const nsAString & name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setProperty (in AString name, in nsISupports value); */
NS_IMETHODIMP nsSAXXMLReader::SetProperty(const nsAString & name, nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getProperty (in AString name); */
NS_IMETHODIMP nsSAXXMLReader::GetProperty(const nsAString & name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseFromString (in AString str, in string contentType); */
NS_IMETHODIMP nsSAXXMLReader::ParseFromString(const nsAString & str, const char *contentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseFromStream (in nsIInputStream stream, in string charset, in string contentType); */
NS_IMETHODIMP nsSAXXMLReader::ParseFromStream(nsIInputStream *stream, const char *charset, const char *contentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseAsync (in nsIRequestObserver observer); */
NS_IMETHODIMP nsSAXXMLReader::ParseAsync(nsIRequestObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXXMLReader_h__ */
