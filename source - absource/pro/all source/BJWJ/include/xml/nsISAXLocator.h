/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/xml/public/nsISAXLocator.idl
 */

#ifndef __gen_nsISAXLocator_h__
#define __gen_nsISAXLocator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXLocator */
#define NS_ISAXLOCATOR_IID_STR "7a307c6c-6cc9-11da-be43-001422106990"

#define NS_ISAXLOCATOR_IID \
  {0x7a307c6c, 0x6cc9, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

/**
 * Interface for associating a SAX event with a document location.
 *
 * Note that the results returned by the object will be valid only
 * during the scope of each callback method: the application will
 * receive unpredictable results if it attempts to use the locator at
 * any other time, or after parsing completes.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISAXLocator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXLOCATOR_IID)

  /**
   * Return the column number where the current document event ends.
   *
   * Warning: The return value from the method is intended only as an
   * approximation for the sake of diagnostics; it is not intended to
   * provide sufficient information to edit the character content of
   * the original XML document.  For example, when lines contain
   * combining character sequences, wide characters, surrogate pairs,
   * or bi-directional text, the value may not correspond to the
   * column in a text editor's display.
   *
   * The return value is an approximation of the column number in the
   * document entity or external parsed entity where the markup
   * triggering the event appears.
   *
   * If possible, the SAX driver should provide the line position of
   * the first character after the text associated with the document
   * event.  The first column in each line is column 1.
   *
   * @return The column number, or -1 if none is available.
   */
  /* readonly attribute long columnNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRInt32 *aColumnNumber) = 0;

  /**
   * Return the line number where the current document event ends.
   * Lines are delimited by line ends, which are defined in the XML
   * specification.
   *
   * Warning: The return value from the method is intended only as an
   * approximation for the sake of diagnostics; it is not intended to
   * provide sufficient information to edit the character content of
   * the original XML document.  In some cases, these "line" numbers
   * match what would be displayed as columns, and in others they may
   * not match the source text due to internal entity expansion.
   *
   * The return value is an approximation of the line number in the
   * document entity or external parsed entity where the markup
   * triggering the event appears.
   *
   * If possible, the SAX driver should provide the line position of
   * the first character after the text associated with the document
   * event.  The first line is line 1.
   *
   * @return The line number, or -1 if none is available.
   */
  /* readonly attribute long lineNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRInt32 *aLineNumber) = 0;

  /**
   * Return the public identifier for the current document event.
   *
   * The return value is the public identifier of the document entity
   * or of the external parsed entity in which the markup triggering
   * the event appears.
   *
   * @return A string containing the public identifier, or
   *         null if none is available.
   */
  /* readonly attribute AString publicId; */
  NS_SCRIPTABLE NS_IMETHOD GetPublicId(nsAString & aPublicId) = 0;

  /**
   * Return the system identifier for the current document event.
   *
   * The return value is the system identifier of the document entity
   * or of the external parsed entity in which the markup triggering
   * the event appears.
   *
   * @return A string containing the system identifier, or null
   *         if none is available.
   */
  /* readonly attribute AString systemId; */
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXLocator, NS_ISAXLOCATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXLOCATOR \
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRInt32 *aColumnNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRInt32 *aLineNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetPublicId(nsAString & aPublicId); \
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXLOCATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRInt32 *aColumnNumber) { return _to GetColumnNumber(aColumnNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRInt32 *aLineNumber) { return _to GetLineNumber(aLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetPublicId(nsAString & aPublicId) { return _to GetPublicId(aPublicId); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId) { return _to GetSystemId(aSystemId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXLOCATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRInt32 *aColumnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnNumber(aColumnNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRInt32 *aLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetPublicId(nsAString & aPublicId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublicId(aPublicId); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemId(aSystemId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXLocator : public nsISAXLocator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXLOCATOR

  nsSAXLocator();

private:
  ~nsSAXLocator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXLocator, nsISAXLocator)

nsSAXLocator::nsSAXLocator()
{
  /* member initializers and constructor code */
}

nsSAXLocator::~nsSAXLocator()
{
  /* destructor code */
}

/* readonly attribute long columnNumber; */
NS_IMETHODIMP nsSAXLocator::GetColumnNumber(PRInt32 *aColumnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long lineNumber; */
NS_IMETHODIMP nsSAXLocator::GetLineNumber(PRInt32 *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString publicId; */
NS_IMETHODIMP nsSAXLocator::GetPublicId(nsAString & aPublicId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString systemId; */
NS_IMETHODIMP nsSAXLocator::GetSystemId(nsAString & aSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXLocator_h__ */
