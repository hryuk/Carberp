/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/xml/public/nsISAXDTDHandler.idl
 */

#ifndef __gen_nsISAXDTDHandler_h__
#define __gen_nsISAXDTDHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXDTDHandler */
#define NS_ISAXDTDHANDLER_IID_STR "4d01f225-6cc5-11da-be43-001422106990"

#define NS_ISAXDTDHANDLER_IID \
  {0x4d01f225, 0x6cc5, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

/**
 * Receive notification of basic DTD-related events.
 *
 * If a SAX application needs information about notations and
 * unparsed entities, then the application implements this interface
 * and registers an instance with the SAX parser using the parser's
 * setDTDHandler method. The parser uses the instance to report
 * notation and unparsed entity declarations to the application.
 *
 * Note that this interface includes only those DTD events that the
 * XML recommendation requires processors to report: notation and
 * unparsed entity declarations.
 *
 * The SAX parser may report these events in any order, regardless
 * of the order in which the notations and unparsed entities were
 * declared; however, all DTD events must be reported after the
 * document handler's startDocument event, and before the first
 * startElement event. (If the LexicalHandler is used, these events
 * must also be reported before the endDTD event.)
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISAXDTDHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXDTDHANDLER_IID)

  /**
   * Receive notification of a notation declaration event.
   *
   * It is up to the application to record the notation for later
   * reference, if necessary; notations may appear as attribute values
   * and in unparsed entity declarations, and are sometime used with
   * processing instruction target names.
   *
   * At least one of publicId and systemId must be non-null. If a
   * system identifier is present, and it is a URL, the SAX parser
   * must resolve it fully before passing it to the application
   * through this event.
   *
   * There is no guarantee that the notation declaration will be
   * reported before any unparsed entities that use it.
   *
   * @param name The notation name.
   * @param publicId The notation's public identifier, or null if none was
   *                  given.
   * @param systemId The notation's system identifier, or null if none was
   *                  given.
   */
  /* void notationDecl (in AString name, in AString publicId, in AString systemId); */
  NS_SCRIPTABLE NS_IMETHOD NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId) = 0;

  /**
   * Receive notification of an unparsed entity declaration event.
   *
   * Note that the notation name corresponds to a notation reported
   * by the notationDecl event. It is up to the application to record
   * the entity for later reference, if necessary; unparsed entities
   * may appear as attribute values.
   *
   * If the system identifier is a URL, the parser must resolve it
   * fully before passing it to the application.
   *
   * @param name The unparsed entity's name.
   * @param publicId The entity's public identifier, or null if none was
   *                  given.
   * @param systemId The entity's system identifier, or null if none was
   *                  given.
   * @param notationName The name of the associated notation.
   */
  /* void unparsedEntityDecl (in AString name, in AString publicId, in AString systemId, in AString notationName); */
  NS_SCRIPTABLE NS_IMETHOD UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXDTDHandler, NS_ISAXDTDHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXDTDHANDLER \
  NS_SCRIPTABLE NS_IMETHOD NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId); \
  NS_SCRIPTABLE NS_IMETHOD UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXDTDHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId) { return _to NotationDecl(name, publicId, systemId); } \
  NS_SCRIPTABLE NS_IMETHOD UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName) { return _to UnparsedEntityDecl(name, publicId, systemId, notationName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXDTDHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotationDecl(name, publicId, systemId); } \
  NS_SCRIPTABLE NS_IMETHOD UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnparsedEntityDecl(name, publicId, systemId, notationName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXDTDHandler : public nsISAXDTDHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXDTDHANDLER

  nsSAXDTDHandler();

private:
  ~nsSAXDTDHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXDTDHandler, nsISAXDTDHandler)

nsSAXDTDHandler::nsSAXDTDHandler()
{
  /* member initializers and constructor code */
}

nsSAXDTDHandler::~nsSAXDTDHandler()
{
  /* destructor code */
}

/* void notationDecl (in AString name, in AString publicId, in AString systemId); */
NS_IMETHODIMP nsSAXDTDHandler::NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unparsedEntityDecl (in AString name, in AString publicId, in AString systemId, in AString notationName); */
NS_IMETHODIMP nsSAXDTDHandler::UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXDTDHandler_h__ */
