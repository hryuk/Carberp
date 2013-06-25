/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFXMLParser.idl
 */

#ifndef __gen_nsIRDFXMLParser_h__
#define __gen_nsIRDFXMLParser_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRDFDataSource_h__
#include "nsIRDFDataSource.h"
#endif

#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

#ifndef __gen_nsIURI_h__
#include "nsIURI.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFXMLParser */
#define NS_IRDFXMLPARSER_IID_STR "1831dd2e-1dd2-11b2-bdb3-86b7b50b70b5"

#define NS_IRDFXMLPARSER_IID \
  {0x1831dd2e, 0x1dd2, 0x11b2, \
    { 0xbd, 0xb3, 0x86, 0xb7, 0xb5, 0x0b, 0x70, 0xb5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFXMLParser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFXMLPARSER_IID)

  /**
     * Create a stream listener that can be used to asynchronously
     * parse RDF/XML.
     * @param aSink the RDF datasource the will receive the data
     * @param aBaseURI the base URI used to resolve relative
     *   references in the RDF/XML
     * @return an nsIStreamListener object to handle the data
     */
  /* nsIStreamListener parseAsync (in nsIRDFDataSource aSink, in nsIURI aBaseURI); */
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRDFDataSource *aSink, nsIURI *aBaseURI, nsIStreamListener **_retval NS_OUTPARAM) = 0;

  /**
     * Parse a string of RDF/XML
     * @param aSink the RDF datasource that will receive the data
     * @param aBaseURI the base URI used to resolve relative
     *   references in the RDF/XML
     * @param aSource a UTF8 string containing RDF/XML data.
     */
  /* void parseString (in nsIRDFDataSource aSink, in nsIURI aBaseURI, in AUTF8String aSource); */
  NS_SCRIPTABLE NS_IMETHOD ParseString(nsIRDFDataSource *aSink, nsIURI *aBaseURI, const nsACString & aSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFXMLParser, NS_IRDFXMLPARSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFXMLPARSER \
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRDFDataSource *aSink, nsIURI *aBaseURI, nsIStreamListener **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseString(nsIRDFDataSource *aSink, nsIURI *aBaseURI, const nsACString & aSource); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFXMLPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRDFDataSource *aSink, nsIURI *aBaseURI, nsIStreamListener **_retval NS_OUTPARAM) { return _to ParseAsync(aSink, aBaseURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseString(nsIRDFDataSource *aSink, nsIURI *aBaseURI, const nsACString & aSource) { return _to ParseString(aSink, aBaseURI, aSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFXMLPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ParseAsync(nsIRDFDataSource *aSink, nsIURI *aBaseURI, nsIStreamListener **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseAsync(aSink, aBaseURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseString(nsIRDFDataSource *aSink, nsIURI *aBaseURI, const nsACString & aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseString(aSink, aBaseURI, aSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFXMLParser : public nsIRDFXMLParser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFXMLPARSER

  nsRDFXMLParser();

private:
  ~nsRDFXMLParser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFXMLParser, nsIRDFXMLParser)

nsRDFXMLParser::nsRDFXMLParser()
{
  /* member initializers and constructor code */
}

nsRDFXMLParser::~nsRDFXMLParser()
{
  /* destructor code */
}

/* nsIStreamListener parseAsync (in nsIRDFDataSource aSink, in nsIURI aBaseURI); */
NS_IMETHODIMP nsRDFXMLParser::ParseAsync(nsIRDFDataSource *aSink, nsIURI *aBaseURI, nsIStreamListener **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseString (in nsIRDFDataSource aSink, in nsIURI aBaseURI, in AUTF8String aSource); */
NS_IMETHODIMP nsRDFXMLParser::ParseString(nsIRDFDataSource *aSink, nsIURI *aBaseURI, const nsACString & aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFXMLParser_h__ */
