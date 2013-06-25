/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/xml/public/nsISAXContentHandler.idl
 */

#ifndef __gen_nsISAXContentHandler_h__
#define __gen_nsISAXContentHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISAXAttributes; /* forward declaration */


/* starting interface:    nsISAXContentHandler */
#define NS_ISAXCONTENTHANDLER_IID_STR "2a99c757-dfee-4806-bff3-f721440412e0"

#define NS_ISAXCONTENTHANDLER_IID \
  {0x2a99c757, 0xdfee, 0x4806, \
    { 0xbf, 0xf3, 0xf7, 0x21, 0x44, 0x04, 0x12, 0xe0 }}

/**
 * Receive notification of the logical content of a document.
 *
 * This is the main interface that most SAX applications implement: if
 * the application needs to be informed of basic parsing events, it
 * implements this interface and registers an instance with the SAX
 * parser.  The parser uses the instance to report basic
 * document-related events like the start and end of elements and
 * character data.
 *
 * The order of events in this interface is very important, and
 * mirrors the order of information in the document itself.  For
 * example, all of an element's content (character data, processing
 * instructions, and/or subelements) will appear, in order, between
 * the startElement event and the corresponding endElement event.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISAXContentHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXCONTENTHANDLER_IID)

  /**
   * Receive notification of the beginning of a document.
   *
   * The SAX parser will invoke this method only once, before any
   * other event callbacks.
   */
  /* void startDocument (); */
  NS_SCRIPTABLE NS_IMETHOD StartDocument(void) = 0;

  /**
   * Receive notification of the end of a document.
   *
   * There is an apparent contradiction between the documentation for
   * this method and the documentation for ErrorHandler.fatalError().
   * Until this ambiguity is resolved in a future major release,
   * clients should make no assumptions about whether endDocument()
   * will or will not be invoked when the parser has reported a
   * fatalError() or thrown an exception.
   *
   * The SAX parser will invoke this method only once, and it will be
   * the last method invoked during the parse.  The parser shall not
   * invoke this method until it has either abandoned parsing (because
   * of an unrecoverable error) or reached the end of input.
   */
  /* void endDocument (); */
  NS_SCRIPTABLE NS_IMETHOD EndDocument(void) = 0;

  /**
   * Receive notification of the beginning of an element.
   *
   * The Parser will invoke this method at the beginning of every
   * element in the XML document; there will be a corresponding
   * endElement event for every startElement event (even when the
   * element is empty). All of the element's content will be reported,
   * in order, before the corresponding endElement event.
   *
   * This event allows up to three name components for each element:
   *
   * 1.) the Namespace URI;
   * 2.) the local name; and
   * 3.) the qualified (prefixed) name.
   *
   * Any or all of these may be provided, depending on the values of
   * the http://xml.org/sax/features/namespaces and the
   * http://xml.org/sax/features/namespace-prefixes properties:
   *
   * The Namespace URI and local name are required when the namespaces
   * property is true (the default), and are optional when the
   * namespaces property is false (if one is specified, both must be);
   *
   * The qualified name is required when the namespace-prefixes
   * property is true, and is optional when the namespace-prefixes
   * property is false (the default).
   *
   * Note that the attribute list provided will contain only
   * attributes with explicit values (specified or defaulted):
   * #IMPLIED attributes will be omitted.  The attribute list will
   * contain attributes used for Namespace declarations (xmlns*
   * attributes) only if the
   * http://xml.org/sax/features/namespace-prefixes property is true
   * (it is false by default, and support for a true value is
   * optional).
   *
   * @param uri the Namespace URI, or the empty string if the
   *        element has no Namespace URI or if Namespace
   *        processing is not being performed
   * @param localName the local name (without prefix), or the
   *        empty string if Namespace processing is not being
   *        performed
   * @param qName the qualified name (with prefix), or the
   *        empty string if qualified names are not available
   * @param atts the attributes attached to the element.  If
   *        there are no attributes, it shall be an empty
   *        SAXAttributes object.  The value of this object after
   *        startElement returns is undefined
   */
  /* void startElement (in AString uri, in AString localName, in AString qName, in nsISAXAttributes attributes); */
  NS_SCRIPTABLE NS_IMETHOD StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes) = 0;

  /**
   * Receive notification of the end of an element.
   *
   * The SAX parser will invoke this method at the end of every
   * element in the XML document; there will be a corresponding
   * startElement event for every endElement event (even when the
   * element is empty).
   *
   * For information on the names, see startElement.
   *
   * @param uri the Namespace URI, or the empty string if the
   *        element has no Namespace URI or if Namespace
   *        processing is not being performed
   * @param localName the local name (without prefix), or the
   *        empty string if Namespace processing is not being
   *        performed
   * @param qName the qualified XML name (with prefix), or the
   *        empty string if qualified names are not available
   */
  /* void endElement (in AString uri, in AString localName, in AString qName); */
  NS_SCRIPTABLE NS_IMETHOD EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName) = 0;

  /**
   * Receive notification of character data.
   *
   * The Parser will call this method to report each chunk of
   * character data.  SAX parsers may return all contiguous character
   * data in a single chunk, or they may split it into several chunks;
   * however, all of the characters in any single event must come from
   * the same external entity so that the Locator provides useful
   * information.
   *
   * Note that some parsers will report whitespace in element
   * content using the ignorableWhitespace method rather than this one
   * (validating parsers must do so).
   *
   * @param value the characters from the XML document
   */
  /* void characters (in AString value); */
  NS_SCRIPTABLE NS_IMETHOD Characters(const nsAString & value) = 0;

  /**
   * Receive notification of a processing instruction.
   *
   * The Parser will invoke this method once for each processing
   * instruction found: note that processing instructions may occur
   * before or after the main document element.
   *
   * A SAX parser must never report an XML declaration (XML 1.0,
   * section 2.8) or a text declaration (XML 1.0, section 4.3.1) using
   * this method.
   *
   * @param target the processing instruction target
   * @param data the processing instruction data, or null if
   *        none was supplied.  The data does not include any
   *        whitespace separating it from the target
   */
  /* void processingInstruction (in AString target, in AString data); */
  NS_SCRIPTABLE NS_IMETHOD ProcessingInstruction(const nsAString & target, const nsAString & data) = 0;

  /**
   * Receive notification of ignorable whitespace in element content.
   *
   * Validating Parsers must use this method to report each chunk of
   * whitespace in element content (see the W3C XML 1.0
   * recommendation, section 2.10): non-validating parsers may also
   * use this method if they are capable of parsing and using content
   * models.
   *
   * SAX parsers may return all contiguous whitespace in a single
   * chunk, or they may split it into several chunks; however, all of
   * the characters in any single event must come from the same
   * external entity, so that the Locator provides useful information.
   *
   * @param whitespace the characters from the XML document
   */
  /* void ignorableWhitespace (in AString whitespace); */
  NS_SCRIPTABLE NS_IMETHOD IgnorableWhitespace(const nsAString & whitespace) = 0;

  /**
   * Begin the scope of a prefix-URI Namespace mapping.
   *
   * The information from this event is not necessary for normal
   * Namespace processing: the SAX XML reader will automatically
   * replace prefixes for element and attribute names when the
   * http://xml.org/sax/features/namespaces feature is
   * true (the default).
   *
   * There are cases, however, when applications need to use prefixes
   * in character data or in attribute values, where they cannot
   * safely be expanded automatically; the start/endPrefixMapping
   * event supplies the information to the application to expand
   * prefixes in those contexts itself, if necessary.
   *
   * Note that start/endPrefixMapping events are not guaranteed to be
   * properly nested relative to each other: all startPrefixMapping
   * events will occur immediately before the corresponding
   * startElement event, and all endPrefixMapping events will occur
   * immediately after the corresponding endElement event, but their
   * order is not otherwise guaranteed.
   *
   * There should never be start/endPrefixMapping events for the
   * "xml" prefix, since it is predeclared and immutable.
   *
   * @param prefix The Namespace prefix being declared. An empty
   *               string is used for the default element namespace,
   *               which has no prefix.
   * @param uri The Namespace URI the prefix is mapped to.
   */
  /* void startPrefixMapping (in AString prefix, in AString uri); */
  NS_SCRIPTABLE NS_IMETHOD StartPrefixMapping(const nsAString & prefix, const nsAString & uri) = 0;

  /**
   * End the scope of a prefix-URI mapping.
   *
   * See startPrefixMapping for details.  These events will always
   * occur immediately after the corresponding endElement event, but
   * the order of endPrefixMapping events is not otherwise guaranteed.
   *
   * @param prefix The prefix that was being mapped. This is the empty
   *               string when a default mapping scope ends.
   */
  /* void endPrefixMapping (in AString prefix); */
  NS_SCRIPTABLE NS_IMETHOD EndPrefixMapping(const nsAString & prefix) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXContentHandler, NS_ISAXCONTENTHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXCONTENTHANDLER \
  NS_SCRIPTABLE NS_IMETHOD StartDocument(void); \
  NS_SCRIPTABLE NS_IMETHOD EndDocument(void); \
  NS_SCRIPTABLE NS_IMETHOD StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes); \
  NS_SCRIPTABLE NS_IMETHOD EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName); \
  NS_SCRIPTABLE NS_IMETHOD Characters(const nsAString & value); \
  NS_SCRIPTABLE NS_IMETHOD ProcessingInstruction(const nsAString & target, const nsAString & data); \
  NS_SCRIPTABLE NS_IMETHOD IgnorableWhitespace(const nsAString & whitespace); \
  NS_SCRIPTABLE NS_IMETHOD StartPrefixMapping(const nsAString & prefix, const nsAString & uri); \
  NS_SCRIPTABLE NS_IMETHOD EndPrefixMapping(const nsAString & prefix); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXCONTENTHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartDocument(void) { return _to StartDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD EndDocument(void) { return _to EndDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes) { return _to StartElement(uri, localName, qName, attributes); } \
  NS_SCRIPTABLE NS_IMETHOD EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName) { return _to EndElement(uri, localName, qName); } \
  NS_SCRIPTABLE NS_IMETHOD Characters(const nsAString & value) { return _to Characters(value); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessingInstruction(const nsAString & target, const nsAString & data) { return _to ProcessingInstruction(target, data); } \
  NS_SCRIPTABLE NS_IMETHOD IgnorableWhitespace(const nsAString & whitespace) { return _to IgnorableWhitespace(whitespace); } \
  NS_SCRIPTABLE NS_IMETHOD StartPrefixMapping(const nsAString & prefix, const nsAString & uri) { return _to StartPrefixMapping(prefix, uri); } \
  NS_SCRIPTABLE NS_IMETHOD EndPrefixMapping(const nsAString & prefix) { return _to EndPrefixMapping(prefix); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXCONTENTHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD EndDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartElement(uri, localName, qName, attributes); } \
  NS_SCRIPTABLE NS_IMETHOD EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndElement(uri, localName, qName); } \
  NS_SCRIPTABLE NS_IMETHOD Characters(const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->Characters(value); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessingInstruction(const nsAString & target, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessingInstruction(target, data); } \
  NS_SCRIPTABLE NS_IMETHOD IgnorableWhitespace(const nsAString & whitespace) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnorableWhitespace(whitespace); } \
  NS_SCRIPTABLE NS_IMETHOD StartPrefixMapping(const nsAString & prefix, const nsAString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartPrefixMapping(prefix, uri); } \
  NS_SCRIPTABLE NS_IMETHOD EndPrefixMapping(const nsAString & prefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndPrefixMapping(prefix); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXContentHandler : public nsISAXContentHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXCONTENTHANDLER

  nsSAXContentHandler();

private:
  ~nsSAXContentHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXContentHandler, nsISAXContentHandler)

nsSAXContentHandler::nsSAXContentHandler()
{
  /* member initializers and constructor code */
}

nsSAXContentHandler::~nsSAXContentHandler()
{
  /* destructor code */
}

/* void startDocument (); */
NS_IMETHODIMP nsSAXContentHandler::StartDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endDocument (); */
NS_IMETHODIMP nsSAXContentHandler::EndDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startElement (in AString uri, in AString localName, in AString qName, in nsISAXAttributes attributes); */
NS_IMETHODIMP nsSAXContentHandler::StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endElement (in AString uri, in AString localName, in AString qName); */
NS_IMETHODIMP nsSAXContentHandler::EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void characters (in AString value); */
NS_IMETHODIMP nsSAXContentHandler::Characters(const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void processingInstruction (in AString target, in AString data); */
NS_IMETHODIMP nsSAXContentHandler::ProcessingInstruction(const nsAString & target, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ignorableWhitespace (in AString whitespace); */
NS_IMETHODIMP nsSAXContentHandler::IgnorableWhitespace(const nsAString & whitespace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startPrefixMapping (in AString prefix, in AString uri); */
NS_IMETHODIMP nsSAXContentHandler::StartPrefixMapping(const nsAString & prefix, const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endPrefixMapping (in AString prefix); */
NS_IMETHODIMP nsSAXContentHandler::EndPrefixMapping(const nsAString & prefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXContentHandler_h__ */
