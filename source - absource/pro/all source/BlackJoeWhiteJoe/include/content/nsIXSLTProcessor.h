/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xslt/public/nsIXSLTProcessor.idl
 */

#ifndef __gen_nsIXSLTProcessor_h__
#define __gen_nsIXSLTProcessor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIXSLTProcessor */
#define NS_IXSLTPROCESSOR_IID_STR "4a91aeb3-4100-43ee-a21e-9866268757c5"

#define NS_IXSLTPROCESSOR_IID \
  {0x4a91aeb3, 0x4100, 0x43ee, \
    { 0xa2, 0x1e, 0x98, 0x66, 0x26, 0x87, 0x57, 0xc5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXSLTProcessor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXSLTPROCESSOR_IID)

  /**
     * Import the stylesheet into this XSLTProcessor for transformations.
     *
     * @param style The root-node of a XSLT stylesheet. This can be either
     *              a document node or an element node. If a document node
     *              then the document can contain either a XSLT stylesheet
     *              or a LRE stylesheet.
     *              If the argument is an element node it must be the
     *              xsl:stylesheet (or xsl:transform) element of an XSLT
     *              stylesheet.
     *
     * @exception nsIXSLTException
     */
  /* void importStylesheet (in nsIDOMNode style); */
  NS_SCRIPTABLE NS_IMETHOD ImportStylesheet(nsIDOMNode *style) = 0;

  /**
     * Transforms the node source applying the stylesheet given by
     * the importStylesheet() function. The owner document of the output node
     * owns the returned document fragment.
     *
     * @param source The node to be transformed
     * @param output This document is used to generate the output
     * @return DocumentFragment The result of the transformation
     *
     * @exception nsIXSLTException
     */
  /* nsIDOMDocumentFragment transformToFragment (in nsIDOMNode source, in nsIDOMDocument output); */
  NS_SCRIPTABLE NS_IMETHOD TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment **_retval NS_OUTPARAM) = 0;

  /**
     * Transforms the node source applying the stylesheet given by the
     * importStylesheet() function.
     *
     * @param source The node to be transformed
     * @return Document The result of the transformation
     *
     * @exception nsIXSLTException
     */
  /* nsIDOMDocument transformToDocument (in nsIDOMNode source); */
  NS_SCRIPTABLE NS_IMETHOD TransformToDocument(nsIDOMNode *source, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

  /**
     * Sets a parameter to be used in subsequent transformations with this
     * nsIXSLTProcessor. If the parameter doesn't exist in the stylesheet the
     * parameter will be ignored.
     *
     * @param namespaceURI The namespaceURI of the XSLT parameter
     * @param localName    The local name of the XSLT parameter
     * @param value        The new value of the XSLT parameter
     *
     * @exception NS_ERROR_ILLEGAL_VALUE The datatype of value is
     *                                   not supported
     */
  /* void setParameter (in DOMString namespaceURI, in DOMString localName, in nsIVariant value); */
  NS_SCRIPTABLE NS_IMETHOD SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value) = 0;

  /**
     * Gets a parameter if previously set by setParameter. Returns null
     * otherwise.
     *
     * @param namespaceURI The namespaceURI of the XSLT parameter
     * @param localName    The local name of the XSLT parameter
     * @return nsIVariant  The value of the XSLT parameter
     */
  /* nsIVariant getParameter (in DOMString namespaceURI, in DOMString localName); */
  NS_SCRIPTABLE NS_IMETHOD GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
     * Removes a parameter, if set. This will make the processor use the
     * default-value for the parameter as specified in the stylesheet.
     *
     * @param namespaceURI The namespaceURI of the XSLT parameter
     * @param localName    The local name of the XSLT parameter
     */
  /* void removeParameter (in DOMString namespaceURI, in DOMString localName); */
  NS_SCRIPTABLE NS_IMETHOD RemoveParameter(const nsAString & namespaceURI, const nsAString & localName) = 0;

  /**
     * Removes all set parameters from this nsIXSLTProcessor. This will make
     * the processor use the default-value for all parameters as specified in
     * the stylesheet.
     */
  /* void clearParameters (); */
  NS_SCRIPTABLE NS_IMETHOD ClearParameters(void) = 0;

  /**
     * Remove all parameters and stylesheets from this nsIXSLTProcessor.
     */
  /* void reset (); */
  NS_SCRIPTABLE NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXSLTProcessor, NS_IXSLTPROCESSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXSLTPROCESSOR \
  NS_SCRIPTABLE NS_IMETHOD ImportStylesheet(nsIDOMNode *style); \
  NS_SCRIPTABLE NS_IMETHOD TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD TransformToDocument(nsIDOMNode *source, nsIDOMDocument **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value); \
  NS_SCRIPTABLE NS_IMETHOD GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveParameter(const nsAString & namespaceURI, const nsAString & localName); \
  NS_SCRIPTABLE NS_IMETHOD ClearParameters(void); \
  NS_SCRIPTABLE NS_IMETHOD Reset(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXSLTPROCESSOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD ImportStylesheet(nsIDOMNode *style) { return _to ImportStylesheet(style); } \
  NS_SCRIPTABLE NS_IMETHOD TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return _to TransformToFragment(source, output, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD TransformToDocument(nsIDOMNode *source, nsIDOMDocument **_retval NS_OUTPARAM) { return _to TransformToDocument(source, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value) { return _to SetParameter(namespaceURI, localName, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant **_retval NS_OUTPARAM) { return _to GetParameter(namespaceURI, localName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveParameter(const nsAString & namespaceURI, const nsAString & localName) { return _to RemoveParameter(namespaceURI, localName); } \
  NS_SCRIPTABLE NS_IMETHOD ClearParameters(void) { return _to ClearParameters(); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXSLTPROCESSOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD ImportStylesheet(nsIDOMNode *style) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportStylesheet(style); } \
  NS_SCRIPTABLE NS_IMETHOD TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TransformToFragment(source, output, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD TransformToDocument(nsIDOMNode *source, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TransformToDocument(source, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParameter(namespaceURI, localName, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameter(namespaceURI, localName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveParameter(const nsAString & namespaceURI, const nsAString & localName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveParameter(namespaceURI, localName); } \
  NS_SCRIPTABLE NS_IMETHOD ClearParameters(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearParameters(); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXSLTProcessor : public nsIXSLTProcessor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXSLTPROCESSOR

  nsXSLTProcessor();

private:
  ~nsXSLTProcessor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXSLTProcessor, nsIXSLTProcessor)

nsXSLTProcessor::nsXSLTProcessor()
{
  /* member initializers and constructor code */
}

nsXSLTProcessor::~nsXSLTProcessor()
{
  /* destructor code */
}

/* void importStylesheet (in nsIDOMNode style); */
NS_IMETHODIMP nsXSLTProcessor::ImportStylesheet(nsIDOMNode *style)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment transformToFragment (in nsIDOMNode source, in nsIDOMDocument output); */
NS_IMETHODIMP nsXSLTProcessor::TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument transformToDocument (in nsIDOMNode source); */
NS_IMETHODIMP nsXSLTProcessor::TransformToDocument(nsIDOMNode *source, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setParameter (in DOMString namespaceURI, in DOMString localName, in nsIVariant value); */
NS_IMETHODIMP nsXSLTProcessor::SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getParameter (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsXSLTProcessor::GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeParameter (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsXSLTProcessor::RemoveParameter(const nsAString & namespaceURI, const nsAString & localName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearParameters (); */
NS_IMETHODIMP nsXSLTProcessor::ClearParameters()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsXSLTProcessor::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXSLTProcessor_h__ */
