/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFService.idl
 */

#ifndef __gen_nsIRDFService_h__
#define __gen_nsIRDFService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRDFResource_h__
#include "nsIRDFResource.h"
#endif

#ifndef __gen_nsIRDFLiteral_h__
#include "nsIRDFLiteral.h"
#endif

#ifndef __gen_nsIRDFDataSource_h__
#include "nsIRDFDataSource.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFService */
#define NS_IRDFSERVICE_IID_STR "bfd05261-834c-11d2-8eac-00805f29f370"

#define NS_IRDFSERVICE_IID \
  {0xbfd05261, 0x834c, 0x11d2, \
    { 0x8e, 0xac, 0x00, 0x80, 0x5f, 0x29, 0xf3, 0x70 }}

/**
 * The RDF service interface. This is a singleton object which should be
 * obtained from the <code>nsServiceManager</code>.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFSERVICE_IID)

  /**
     * Construct an RDF resource from a single-byte URI. <code>nsIRDFService</code>
     * caches resources that are in-use, so multiple calls to <code>GetResource()</code>
     * for the same <code>uri</code> will return identical pointers. FindResource
     * is used to find out whether there already exists a resource corresponding to that url.
     */
  /* nsIRDFResource GetResource (in AUTF8String aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetResource(const nsACString & aURI, nsIRDFResource **_retval NS_OUTPARAM) = 0;

  /**
     * Construct an RDF resource from a Unicode URI. This is provided
     * as a convenience method, allowing automatic, in-line C++
     * conversion from <code>nsString</code> objects. The <code>uri</code> will
     * be converted to a single-byte representation internally.
     */
  /* nsIRDFResource GetUnicodeResource (in AString aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeResource(const nsAString & aURI, nsIRDFResource **_retval NS_OUTPARAM) = 0;

  /* nsIRDFResource GetAnonymousResource (); */
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousResource(nsIRDFResource **_retval NS_OUTPARAM) = 0;

  /**
     * Construct an RDF literal from a Unicode string.
     */
  /* nsIRDFLiteral GetLiteral (in wstring aValue); */
  NS_SCRIPTABLE NS_IMETHOD GetLiteral(const PRUnichar *aValue, nsIRDFLiteral **_retval NS_OUTPARAM) = 0;

  /**
     * Construct an RDF literal from a PRTime.
     */
  /* nsIRDFDate GetDateLiteral (in long long aValue); */
  NS_SCRIPTABLE NS_IMETHOD GetDateLiteral(PRInt64 aValue, nsIRDFDate **_retval NS_OUTPARAM) = 0;

  /**
     * Construct an RDF literal from an int.
     */
  /* nsIRDFInt GetIntLiteral (in long aValue); */
  NS_SCRIPTABLE NS_IMETHOD GetIntLiteral(PRInt32 aValue, nsIRDFInt **_retval NS_OUTPARAM) = 0;

  /**
     * Construct an RDF literal from a data blob
     */
  /* [noscript] nsIRDFBlob getBlobLiteral (in const_octet_ptr aValue, in long aLength); */
  NS_IMETHOD GetBlobLiteral(const PRUint8 * aValue, PRInt32 aLength, nsIRDFBlob **_retval NS_OUTPARAM) = 0;

  /* boolean IsAnonymousResource (in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD IsAnonymousResource(nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Registers a resource with the RDF system, making it unique w.r.t.
     * GetResource.
     *
     * An implementation of nsIRDFResource should call this in its
     * Init() method if it wishes the resource to be globally unique
     * (which is usually the case).
     *
     * @note that the resource will <i>not</i> be ref-counted by the
     * RDF service: the assumption is that the resource implementation
     * will call nsIRDFService::UnregisterResource() when the last
     * reference to the resource is released.
     *
     * @note that the nsIRDFService implementation may choose to
     * maintain a reference to the resource's URI; therefore, the
     * resource implementation should ensure that the resource's URI
     * (accessible via nsIRDFResource::GetValue(const char* *aURI)) is
     * valid before calling RegisterResource(). Furthermore, the
     * resource implementation should ensure that this pointer
     * <i>remains</i> valid for the lifetime of the resource. (The
     * implementation of the resource cache in nsIRDFService uses the
     * URI maintained "internally" in the resource as a key into the
     * cache rather than copying the resource URI itself.)
     */
  /* void RegisterResource (in nsIRDFResource aResource, in boolean aReplace); */
  NS_SCRIPTABLE NS_IMETHOD RegisterResource(nsIRDFResource *aResource, PRBool aReplace) = 0;

  /**
     * Called to notify the resource manager that a resource is no
     * longer in use. This method should only be called from the
     * destructor of a "custom" resource implementation to notify the
     * RDF service that the last reference to the resource has been
     * released, so the resource is no longer valid.
     *
     * @note As mentioned in nsIRDFResourceFactory::CreateResource(),
     * the RDF service will use the result of
     * nsIRDFResource::GetValue() as a key into its cache. For this
     * reason, you must always un-cache the resource <b>before</b>
     * releasing the storage for the <code>const char*</code> URI.
     */
  /* void UnregisterResource (in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterResource(nsIRDFResource *aResource) = 0;

  /**
     * Register a <i>named data source</i>. The RDF service will call
     * <code>nsIRDFDataSource::GetURI()</code> to determine the URI under
     * which to register the data source.
     *
     * @note that the data source will <i>not</i> be refcounted by the
     * RDF service! The assumption is that an RDF data source
     * registers with the service once it is initialized (via
     * <code>nsIRDFDataSource::Init()</code>), and unregisters when the
     * last reference to the data source is released.
     */
  /* void RegisterDataSource (in nsIRDFDataSource aDataSource, in boolean aReplace); */
  NS_SCRIPTABLE NS_IMETHOD RegisterDataSource(nsIRDFDataSource *aDataSource, PRBool aReplace) = 0;

  /**
     * Unregister a <i>named data source</i>. The RDF service will call
     * <code>nsIRDFDataSource::GetURI()</code> to determine the URI under which the
     * data source was registered.
     */
  /* void UnregisterDataSource (in nsIRDFDataSource aDataSource); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterDataSource(nsIRDFDataSource *aDataSource) = 0;

  /**
     * Get the <i>named data source</i> corresponding to the URI. If a data
     * source has been registered via <code>RegisterDataSource()</code>, that
     * data source will be returned.
     *
     * If no data source is currently
     * registered for the specified URI, and a data source <i>constructor</i>
     * function has been registered via <code>RegisterDatasourceConstructor()</code>,
     * the RDF service will call the constructor to attempt to construct a
     * new data source. If construction is successful, the data source will
     * be initialized via <code>nsIRDFDataSource::Init()</code>.
     */
  /* nsIRDFDataSource GetDataSource (in string aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM) = 0;

  /**
     * Same as GetDataSource, but if a remote/XML data source needs to be
     * constructed, then this method will issue a <b>blocking</b> Refresh
     * call on that data source.
     */
  /* nsIRDFDataSource GetDataSourceBlocking (in string aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetDataSourceBlocking(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFService, NS_IRDFSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetResource(const nsACString & aURI, nsIRDFResource **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeResource(const nsAString & aURI, nsIRDFResource **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousResource(nsIRDFResource **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLiteral(const PRUnichar *aValue, nsIRDFLiteral **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDateLiteral(PRInt64 aValue, nsIRDFDate **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIntLiteral(PRInt32 aValue, nsIRDFInt **_retval NS_OUTPARAM); \
  NS_IMETHOD GetBlobLiteral(const PRUint8 * aValue, PRInt32 aLength, nsIRDFBlob **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsAnonymousResource(nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RegisterResource(nsIRDFResource *aResource, PRBool aReplace); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterResource(nsIRDFResource *aResource); \
  NS_SCRIPTABLE NS_IMETHOD RegisterDataSource(nsIRDFDataSource *aDataSource, PRBool aReplace); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterDataSource(nsIRDFDataSource *aDataSource); \
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDataSourceBlocking(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResource(const nsACString & aURI, nsIRDFResource **_retval NS_OUTPARAM) { return _to GetResource(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeResource(const nsAString & aURI, nsIRDFResource **_retval NS_OUTPARAM) { return _to GetUnicodeResource(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousResource(nsIRDFResource **_retval NS_OUTPARAM) { return _to GetAnonymousResource(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLiteral(const PRUnichar *aValue, nsIRDFLiteral **_retval NS_OUTPARAM) { return _to GetLiteral(aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDateLiteral(PRInt64 aValue, nsIRDFDate **_retval NS_OUTPARAM) { return _to GetDateLiteral(aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntLiteral(PRInt32 aValue, nsIRDFInt **_retval NS_OUTPARAM) { return _to GetIntLiteral(aValue, _retval); } \
  NS_IMETHOD GetBlobLiteral(const PRUint8 * aValue, PRInt32 aLength, nsIRDFBlob **_retval NS_OUTPARAM) { return _to GetBlobLiteral(aValue, aLength, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsAnonymousResource(nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return _to IsAnonymousResource(aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterResource(nsIRDFResource *aResource, PRBool aReplace) { return _to RegisterResource(aResource, aReplace); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterResource(nsIRDFResource *aResource) { return _to UnregisterResource(aResource); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterDataSource(nsIRDFDataSource *aDataSource, PRBool aReplace) { return _to RegisterDataSource(aDataSource, aReplace); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterDataSource(nsIRDFDataSource *aDataSource) { return _to UnregisterDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM) { return _to GetDataSource(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSourceBlocking(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM) { return _to GetDataSourceBlocking(aURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResource(const nsACString & aURI, nsIRDFResource **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResource(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnicodeResource(const nsAString & aURI, nsIRDFResource **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnicodeResource(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnonymousResource(nsIRDFResource **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnonymousResource(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLiteral(const PRUnichar *aValue, nsIRDFLiteral **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLiteral(aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDateLiteral(PRInt64 aValue, nsIRDFDate **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDateLiteral(aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntLiteral(PRInt32 aValue, nsIRDFInt **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntLiteral(aValue, _retval); } \
  NS_IMETHOD GetBlobLiteral(const PRUint8 * aValue, PRInt32 aLength, nsIRDFBlob **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlobLiteral(aValue, aLength, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsAnonymousResource(nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAnonymousResource(aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterResource(nsIRDFResource *aResource, PRBool aReplace) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterResource(aResource, aReplace); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterResource(nsIRDFResource *aResource) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterResource(aResource); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterDataSource(nsIRDFDataSource *aDataSource, PRBool aReplace) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterDataSource(aDataSource, aReplace); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterDataSource(nsIRDFDataSource *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSource(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSourceBlocking(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSourceBlocking(aURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFService : public nsIRDFService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFSERVICE

  nsRDFService();

private:
  ~nsRDFService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFService, nsIRDFService)

nsRDFService::nsRDFService()
{
  /* member initializers and constructor code */
}

nsRDFService::~nsRDFService()
{
  /* destructor code */
}

/* nsIRDFResource GetResource (in AUTF8String aURI); */
NS_IMETHODIMP nsRDFService::GetResource(const nsACString & aURI, nsIRDFResource **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFResource GetUnicodeResource (in AString aURI); */
NS_IMETHODIMP nsRDFService::GetUnicodeResource(const nsAString & aURI, nsIRDFResource **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFResource GetAnonymousResource (); */
NS_IMETHODIMP nsRDFService::GetAnonymousResource(nsIRDFResource **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFLiteral GetLiteral (in wstring aValue); */
NS_IMETHODIMP nsRDFService::GetLiteral(const PRUnichar *aValue, nsIRDFLiteral **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFDate GetDateLiteral (in long long aValue); */
NS_IMETHODIMP nsRDFService::GetDateLiteral(PRInt64 aValue, nsIRDFDate **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFInt GetIntLiteral (in long aValue); */
NS_IMETHODIMP nsRDFService::GetIntLiteral(PRInt32 aValue, nsIRDFInt **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIRDFBlob getBlobLiteral (in const_octet_ptr aValue, in long aLength); */
NS_IMETHODIMP nsRDFService::GetBlobLiteral(const PRUint8 * aValue, PRInt32 aLength, nsIRDFBlob **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsAnonymousResource (in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFService::IsAnonymousResource(nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RegisterResource (in nsIRDFResource aResource, in boolean aReplace); */
NS_IMETHODIMP nsRDFService::RegisterResource(nsIRDFResource *aResource, PRBool aReplace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void UnregisterResource (in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFService::UnregisterResource(nsIRDFResource *aResource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RegisterDataSource (in nsIRDFDataSource aDataSource, in boolean aReplace); */
NS_IMETHODIMP nsRDFService::RegisterDataSource(nsIRDFDataSource *aDataSource, PRBool aReplace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void UnregisterDataSource (in nsIRDFDataSource aDataSource); */
NS_IMETHODIMP nsRDFService::UnregisterDataSource(nsIRDFDataSource *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFDataSource GetDataSource (in string aURI); */
NS_IMETHODIMP nsRDFService::GetDataSource(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFDataSource GetDataSourceBlocking (in string aURI); */
NS_IMETHODIMP nsRDFService::GetDataSourceBlocking(const char *aURI, nsIRDFDataSource **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

extern nsresult
NS_NewRDFService(nsIRDFService** result);

#endif /* __gen_nsIRDFService_h__ */
