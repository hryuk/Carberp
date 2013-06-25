/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/xml/public/nsISAXLexicalHandler.idl
 */

#ifndef __gen_nsISAXLexicalHandler_h__
#define __gen_nsISAXLexicalHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXLexicalHandler */
#define NS_ISAXLEXICALHANDLER_IID_STR "23c26a56-adff-440c-8caf-95c2dc2e399b"

#define NS_ISAXLEXICALHANDLER_IID \
  {0x23c26a56, 0xadff, 0x440c, \
    { 0x8c, 0xaf, 0x95, 0xc2, 0xdc, 0x2e, 0x39, 0x9b }}

/**
 * SAX2 extension handler for lexical events.
 *
 * This is an extension handler for SAX2 to provide lexical
 * information about an XML document, such as comments and CDATA
 * section boundaries.
 *
 * The events in the lexical handler apply to the entire document,
 * not just to the document element, and all lexical handler events
 * must appear between the content handler's startDocument and
 * endDocument events.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISAXLexicalHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXLEXICALHANDLER_IID)

  /**
   * Report an XML comment anywhere in the document.
   *
   * This callback will be used for comments inside or outside the
   * document element, including comments in the external DTD subset
   * (if read).  Comments in the DTD must be properly nested inside
   * start/endDTD and start/endEntity events (if used).
   *
   * @param chars The characters in the comment.
   */
  /* void comment (in AString chars); */
  NS_SCRIPTABLE NS_IMETHOD Comment(const nsAString & chars) = 0;

  /**
   * Report the start of DTD declarations, if any.
   *
   * This method is intended to report the beginning of the
   * DOCTYPE declaration; if the document has no DOCTYPE declaration,
   * this method will not be invoked.
   *
   * All declarations reported through DTDHandler or DeclHandler
   * events must appear between the startDTD and endDTD events.
   * Declarations are assumed to belong to the internal DTD subset
   * unless they appear between startEntity and endEntity events.
   * Comments and processing instructions from the DTD should also be
   * reported between the startDTD and endDTD events, in their
   * original order of (logical) occurrence; they are not required to
   * appear in their correct locations relative to DTDHandler or
   * DeclHandler events, however.
   *
   * Note that the start/endDTD events will appear within the
   * start/endDocument events from ContentHandler and before the first
   * startElement event.
   *
   * @param name The document type name.
   * @param publicId The declared public identifier for the
   *        external DTD subset, or null if none was declared.
   * @param systemId The declared system identifier for the
   *        external DTD subset, or null if none was declared.
   *        (Note that this is not resolved against the document
   *        base URI.)
   */
  /* void startDTD (in AString name, in AString publicId, in AString systemId); */
  NS_SCRIPTABLE NS_IMETHOD StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId) = 0;

  /**
   * Report the end of DTD declarations.
   *
   * This method is intended to report the end of the
   * DOCTYPE declaration; if the document has no DOCTYPE declaration,
   * this method will not be invoked.
   */
  /* void endDTD (); */
  NS_SCRIPTABLE NS_IMETHOD EndDTD(void) = 0;

  /**
   * Report the start of a CDATA section.
   *
   * The contents of the CDATA section will be reported through the
   * regular characters event; this event is intended only to report
   * the boundary.
   */
  /* void startCDATA (); */
  NS_SCRIPTABLE NS_IMETHOD StartCDATA(void) = 0;

  /**
   * Report the end of a CDATA section.
   */
  /* void endCDATA (); */
  NS_SCRIPTABLE NS_IMETHOD EndCDATA(void) = 0;

  /**
   * Report the beginning of some internal and external XML entities.
   *
   * Because of the streaming event model that SAX uses, some
   * entity boundaries cannot be reported under any circumstances:
   *
   * 1.) general entities within attribute values
   * 2.) parameter entities within declarations
   *
   * These will be silently expanded, with no indication of where
   * the original entity boundaries were.
   *
   * Note also that the boundaries of character references (which
   * are not really entities anyway) are not reported.
   *
   * All start/endEntity events must be properly nested.
   *
   * @param name The name of the entity.  If it is a parameter
   *             entity, the name will begin with '%', and if it is the
   *             external DTD subset, it will be "[dtd]".
   */
  /* void startEntity (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD StartEntity(const nsAString & name) = 0;

  /**
   * Report the end of an entity.
   *
   * @param name The name of the entity that is ending.
   */
  /* void endEntity (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD EndEntity(const nsAString & name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXLexicalHandler, NS_ISAXLEXICALHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXLEXICALHANDLER \
  NS_SCRIPTABLE NS_IMETHOD Comment(const nsAString & chars); \
  NS_SCRIPTABLE NS_IMETHOD StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId); \
  NS_SCRIPTABLE NS_IMETHOD EndDTD(void); \
  NS_SCRIPTABLE NS_IMETHOD StartCDATA(void); \
  NS_SCRIPTABLE NS_IMETHOD EndCDATA(void); \
  NS_SCRIPTABLE NS_IMETHOD StartEntity(const nsAString & name); \
  NS_SCRIPTABLE NS_IMETHOD EndEntity(const nsAString & name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXLEXICALHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Comment(const nsAString & chars) { return _to Comment(chars); } \
  NS_SCRIPTABLE NS_IMETHOD StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId) { return _to StartDTD(name, publicId, systemId); } \
  NS_SCRIPTABLE NS_IMETHOD EndDTD(void) { return _to EndDTD(); } \
  NS_SCRIPTABLE NS_IMETHOD StartCDATA(void) { return _to StartCDATA(); } \
  NS_SCRIPTABLE NS_IMETHOD EndCDATA(void) { return _to EndCDATA(); } \
  NS_SCRIPTABLE NS_IMETHOD StartEntity(const nsAString & name) { return _to StartEntity(name); } \
  NS_SCRIPTABLE NS_IMETHOD EndEntity(const nsAString & name) { return _to EndEntity(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXLEXICALHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Comment(const nsAString & chars) { return !_to ? NS_ERROR_NULL_POINTER : _to->Comment(chars); } \
  NS_SCRIPTABLE NS_IMETHOD StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartDTD(name, publicId, systemId); } \
  NS_SCRIPTABLE NS_IMETHOD EndDTD(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndDTD(); } \
  NS_SCRIPTABLE NS_IMETHOD StartCDATA(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartCDATA(); } \
  NS_SCRIPTABLE NS_IMETHOD EndCDATA(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndCDATA(); } \
  NS_SCRIPTABLE NS_IMETHOD StartEntity(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartEntity(name); } \
  NS_SCRIPTABLE NS_IMETHOD EndEntity(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndEntity(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXLexicalHandler : public nsISAXLexicalHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXLEXICALHANDLER

  nsSAXLexicalHandler();

private:
  ~nsSAXLexicalHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXLexicalHandler, nsISAXLexicalHandler)

nsSAXLexicalHandler::nsSAXLexicalHandler()
{
  /* member initializers and constructor code */
}

nsSAXLexicalHandler::~nsSAXLexicalHandler()
{
  /* destructor code */
}

/* void comment (in AString chars); */
NS_IMETHODIMP nsSAXLexicalHandler::Comment(const nsAString & chars)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startDTD (in AString name, in AString publicId, in AString systemId); */
NS_IMETHODIMP nsSAXLexicalHandler::StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endDTD (); */
NS_IMETHODIMP nsSAXLexicalHandler::EndDTD()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startCDATA (); */
NS_IMETHODIMP nsSAXLexicalHandler::StartCDATA()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endCDATA (); */
NS_IMETHODIMP nsSAXLexicalHandler::EndCDATA()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startEntity (in AString name); */
NS_IMETHODIMP nsSAXLexicalHandler::StartEntity(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endEntity (in AString name); */
NS_IMETHODIMP nsSAXLexicalHandler::EndEntity(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXLexicalHandler_h__ */
