/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/xml/public/nsISAXErrorHandler.idl
 */

#ifndef __gen_nsISAXErrorHandler_h__
#define __gen_nsISAXErrorHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISAXLocator; /* forward declaration */


/* starting interface:    nsISAXErrorHandler */
#define NS_ISAXERRORHANDLER_IID_STR "e02b6693-6cca-11da-be43-001422106990"

#define NS_ISAXERRORHANDLER_IID \
  {0xe02b6693, 0x6cca, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

/**
 * Basic interface for SAX error handlers.
 *
 * If a SAX application needs to implement customized error
 * handling, it must implement this interface and then register an
 * instance with the XML reader.  The parser will then report all
 * errors and warnings through this interface.
 *
 * WARNING: If an application does not register an ErrorHandler,
 * XML parsing errors will go unreported. In order to detect validity
 * errors, an ErrorHandler that does something with error() calls must
 * be registered.
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISAXErrorHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXERRORHANDLER_IID)

  /**
   * Receive notification of a recoverable error.
   *
   * This corresponds to the definition of "error" in section 1.2
   * of the W3C XML 1.0 Recommendation. For example, a validating
   * parser would use this callback to report the violation of a
   * validity constraint. The default behaviour is to take no
   * action.
   *
   * The SAX parser must continue to provide normal parsing events
   * after invoking this method: it should still be possible for the
   * application to process the document through to the end. If the
   * application cannot do so, then the parser should report a fatal
   * error even if the XML recommendation does not require it to do
   * so.
   *
   * Filters may use this method to report other, non-XML errors as
   * well.
   *
   * @param locator The locator object for the error (may be null).
   * @param error The error message.
   */
  /* void error (in nsISAXLocator locator, in AString error); */
  NS_SCRIPTABLE NS_IMETHOD Error(nsISAXLocator *locator, const nsAString & error) = 0;

  /**
   * Receive notification of a non-recoverable error.
   *
   * There is an apparent contradiction between the documentation
   * for this method and the documentation for
   * ContentHandler.endDocument(). Until this ambiguity is resolved in
   * a future major release, clients should make no assumptions about
   * whether endDocument() will or will not be invoked when the parser
   * has reported a fatalError() or thrown an exception.
   *
   * This corresponds to the definition of "fatal error" in section
   * 1.2 of the W3C XML 1.0 Recommendation. For example, a parser
   * would use this callback to report the violation of a
   * well-formedness constraint.
   *
   * The application must assume that the document is unusable
   * after the parser has invoked this method, and should continue (if
   * at all) only for the sake of collecting additional error
   * messages: in fact, SAX parsers are free to stop reporting any
   * other events once this method has been invoked.
   *
   * @param locator The locator object for the error (may be null).
   * @param error The error message.
   */
  /* void fatalError (in nsISAXLocator locator, in AString error); */
  NS_SCRIPTABLE NS_IMETHOD FatalError(nsISAXLocator *locator, const nsAString & error) = 0;

  /**
   * Receive notification of a warning.
   *
   * SAX parsers will use this method to report conditions that are
   * not errors or fatal errors as defined by the XML
   * recommendation. The default behaviour is to take no action.
   *
   * The SAX parser must continue to provide normal parsing events
   * after invoking this method: it should still be possible for the
   * application to process the document through to the end.
   *
   * Filters may use this method to report other, non-XML warnings
   * as well.
   *
   * @param locator The locator object for the warning (may be null).
   * @param error The warning message.
   */
  /* void ignorableWarning (in nsISAXLocator locator, in AString error); */
  NS_SCRIPTABLE NS_IMETHOD IgnorableWarning(nsISAXLocator *locator, const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXErrorHandler, NS_ISAXERRORHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXERRORHANDLER \
  NS_SCRIPTABLE NS_IMETHOD Error(nsISAXLocator *locator, const nsAString & error); \
  NS_SCRIPTABLE NS_IMETHOD FatalError(nsISAXLocator *locator, const nsAString & error); \
  NS_SCRIPTABLE NS_IMETHOD IgnorableWarning(nsISAXLocator *locator, const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXERRORHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Error(nsISAXLocator *locator, const nsAString & error) { return _to Error(locator, error); } \
  NS_SCRIPTABLE NS_IMETHOD FatalError(nsISAXLocator *locator, const nsAString & error) { return _to FatalError(locator, error); } \
  NS_SCRIPTABLE NS_IMETHOD IgnorableWarning(nsISAXLocator *locator, const nsAString & error) { return _to IgnorableWarning(locator, error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXERRORHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Error(nsISAXLocator *locator, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->Error(locator, error); } \
  NS_SCRIPTABLE NS_IMETHOD FatalError(nsISAXLocator *locator, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->FatalError(locator, error); } \
  NS_SCRIPTABLE NS_IMETHOD IgnorableWarning(nsISAXLocator *locator, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnorableWarning(locator, error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXErrorHandler : public nsISAXErrorHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXERRORHANDLER

  nsSAXErrorHandler();

private:
  ~nsSAXErrorHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXErrorHandler, nsISAXErrorHandler)

nsSAXErrorHandler::nsSAXErrorHandler()
{
  /* member initializers and constructor code */
}

nsSAXErrorHandler::~nsSAXErrorHandler()
{
  /* destructor code */
}

/* void error (in nsISAXLocator locator, in AString error); */
NS_IMETHODIMP nsSAXErrorHandler::Error(nsISAXLocator *locator, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fatalError (in nsISAXLocator locator, in AString error); */
NS_IMETHODIMP nsSAXErrorHandler::FatalError(nsISAXLocator *locator, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ignorableWarning (in nsISAXLocator locator, in AString error); */
NS_IMETHODIMP nsSAXErrorHandler::IgnorableWarning(nsISAXLocator *locator, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXErrorHandler_h__ */
