/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFRemoteDataSource.idl
 */

#ifndef __gen_nsIRDFRemoteDataSource_h__
#define __gen_nsIRDFRemoteDataSource_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFRemoteDataSource */
#define NS_IRDFREMOTEDATASOURCE_IID_STR "1d297320-27f7-11d3-be01-000064657374"

#define NS_IRDFREMOTEDATASOURCE_IID \
  {0x1d297320, 0x27f7, 0x11d3, \
    { 0xbe, 0x01, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

/**
 * A datasource that may load asynchronously
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFRemoteDataSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFREMOTEDATASOURCE_IID)

  /**
     * This value is <code>true</code> when the datasource has
     * fully loaded itself.
     */
  /* readonly attribute boolean loaded; */
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRBool *aLoaded) = 0;

  /**
     * Specify the URI for the data source: this is the prefix
     * that will be used to register the data source in the
     * data source registry.
     * @param aURI the URI to load
     */
  /* void Init (in string aURI); */
  NS_SCRIPTABLE NS_IMETHOD Init(const char *aURI) = 0;

  /**
     * Refresh the remote datasource, re-loading its contents
     * from the URI.
     *
     * @param aBlocking If <code>true</code>, the call will block
     * until the datasource has completely reloaded.
     */
  /* void Refresh (in boolean aBlocking); */
  NS_SCRIPTABLE NS_IMETHOD Refresh(PRBool aBlocking) = 0;

  /**
     * Request that a data source write its contents out to 
     * permanent storage, if applicable.
     */
  /* void Flush (); */
  NS_SCRIPTABLE NS_IMETHOD Flush(void) = 0;

  /* void FlushTo (in string aURI); */
  NS_SCRIPTABLE NS_IMETHOD FlushTo(const char *aURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFRemoteDataSource, NS_IRDFREMOTEDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFREMOTEDATASOURCE \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRBool *aLoaded); \
  NS_SCRIPTABLE NS_IMETHOD Init(const char *aURI); \
  NS_SCRIPTABLE NS_IMETHOD Refresh(PRBool aBlocking); \
  NS_SCRIPTABLE NS_IMETHOD Flush(void); \
  NS_SCRIPTABLE NS_IMETHOD FlushTo(const char *aURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFREMOTEDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRBool *aLoaded) { return _to GetLoaded(aLoaded); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const char *aURI) { return _to Init(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD Refresh(PRBool aBlocking) { return _to Refresh(aBlocking); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return _to Flush(); } \
  NS_SCRIPTABLE NS_IMETHOD FlushTo(const char *aURI) { return _to FlushTo(aURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFREMOTEDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRBool *aLoaded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoaded(aLoaded); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const char *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD Refresh(PRBool aBlocking) { return !_to ? NS_ERROR_NULL_POINTER : _to->Refresh(aBlocking); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Flush(); } \
  NS_SCRIPTABLE NS_IMETHOD FlushTo(const char *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlushTo(aURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFRemoteDataSource : public nsIRDFRemoteDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFREMOTEDATASOURCE

  nsRDFRemoteDataSource();

private:
  ~nsRDFRemoteDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFRemoteDataSource, nsIRDFRemoteDataSource)

nsRDFRemoteDataSource::nsRDFRemoteDataSource()
{
  /* member initializers and constructor code */
}

nsRDFRemoteDataSource::~nsRDFRemoteDataSource()
{
  /* destructor code */
}

/* readonly attribute boolean loaded; */
NS_IMETHODIMP nsRDFRemoteDataSource::GetLoaded(PRBool *aLoaded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Init (in string aURI); */
NS_IMETHODIMP nsRDFRemoteDataSource::Init(const char *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Refresh (in boolean aBlocking); */
NS_IMETHODIMP nsRDFRemoteDataSource::Refresh(PRBool aBlocking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Flush (); */
NS_IMETHODIMP nsRDFRemoteDataSource::Flush()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void FlushTo (in string aURI); */
NS_IMETHODIMP nsRDFRemoteDataSource::FlushTo(const char *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFRemoteDataSource_h__ */
