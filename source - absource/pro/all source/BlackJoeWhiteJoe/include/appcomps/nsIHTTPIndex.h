/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/components/directory/nsIHTTPIndex.idl
 */

#ifndef __gen_nsIHTTPIndex_h__
#define __gen_nsIHTTPIndex_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIStreamListener; /* forward declaration */

class nsIRDFDataSource; /* forward declaration */

class nsIRDFNode; /* forward declaration */

class nsIRDFResource; /* forward declaration */


/* starting interface:    nsIHTTPIndex */
#define NS_IHTTPINDEX_IID_STR "6f2bdbd0-58c3-11d3-be36-00104bde6048"

#define NS_IHTTPINDEX_IID \
  {0x6f2bdbd0, 0x58c3, 0x11d3, \
    { 0xbe, 0x36, 0x00, 0x10, 0x4b, 0xde, 0x60, 0x48 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIHTTPIndex : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPINDEX_IID)

  /**
     * The base URL of the HTTP index
     */
  /* readonly attribute string BaseURL; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseURL(char * *aBaseURL) = 0;

  /**
     * The RDF datasource that contains the HTTP index information.
     */
  /* readonly attribute nsIRDFDataSource DataSource; */
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource) = 0;

  /**
     * The charset to use for decoding FTP filenames
     */
  /* attribute string encoding; */
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(char * *aEncoding) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const char * aEncoding) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTTPIndex, NS_IHTTPINDEX_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPINDEX \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURL(char * *aBaseURL); \
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource); \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(char * *aEncoding); \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const char * aEncoding); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPINDEX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURL(char * *aBaseURL) { return _to GetBaseURL(aBaseURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource) { return _to GetDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(char * *aEncoding) { return _to GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const char * aEncoding) { return _to SetEncoding(aEncoding); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPINDEX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURL(char * *aBaseURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseURL(aBaseURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(char * *aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const char * aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEncoding(aEncoding); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTTPIndex : public nsIHTTPIndex
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPINDEX

  nsHTTPIndex();

private:
  ~nsHTTPIndex();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTTPIndex, nsIHTTPIndex)

nsHTTPIndex::nsHTTPIndex()
{
  /* member initializers and constructor code */
}

nsHTTPIndex::~nsHTTPIndex()
{
  /* destructor code */
}

/* readonly attribute string BaseURL; */
NS_IMETHODIMP nsHTTPIndex::GetBaseURL(char * *aBaseURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRDFDataSource DataSource; */
NS_IMETHODIMP nsHTTPIndex::GetDataSource(nsIRDFDataSource * *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string encoding; */
NS_IMETHODIMP nsHTTPIndex::GetEncoding(char * *aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTTPIndex::SetEncoding(const char * aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {{2587e382-1324-11d4-a652-eadbb2be3484}
#define NS_HTTPINDEX_SERVICE_CID \
{ 0x2587e382, 0x1324, 0x11d4, { 0xa6, 0x52, 0xea, 0xdb, 0xb2, 0xbe, 0x34, 0x84 } }
#define NS_HTTPINDEX_SERVICE_CONTRACTID \
    "@mozilla.org/browser/httpindex-service;1"
#define NS_HTTPINDEX_DATASOURCE_CONTRACTID \
    "@mozilla.org/rdf/datasource;1?name=httpindex"

#endif /* __gen_nsIHTTPIndex_h__ */
