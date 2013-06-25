/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFResource.idl
 */

#ifndef __gen_nsIRDFResource_h__
#define __gen_nsIRDFResource_h__


#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFResource */
#define NS_IRDFRESOURCE_IID_STR "fb9686a7-719a-49dc-9107-10dea5739341"

#define NS_IRDFRESOURCE_IID \
  {0xfb9686a7, 0x719a, 0x49dc, \
    { 0x91, 0x07, 0x10, 0xde, 0xa5, 0x73, 0x93, 0x41 }}

/**
 * An nsIRDFResource is an object that has unique identity in the 
 * RDF data model. The object's identity is determined by its URI.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFResource : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFRESOURCE_IID)

  /**
     * The single-byte string value of the resource.
     * @note THIS IS OBSOLETE. C++ should use GetValueConst and script
     *       should use .valueUTF8
     */
  /* readonly attribute string Value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue) = 0;

  /**
     * The UTF-8 URI of the resource.
     */
  /* readonly attribute AUTF8String ValueUTF8; */
  NS_SCRIPTABLE NS_IMETHOD GetValueUTF8(nsACString & aValueUTF8) = 0;

  /**
     * An unscriptable version used to avoid a string copy. Meant
     * for use as a performance optimization. The string is encoded
     * in UTF-8.
     */
  /* [noscript] void GetValueConst ([shared] out string aConstValue); */
  NS_IMETHOD GetValueConst(const char **aConstValue NS_OUTPARAM) = 0;

  /**
     * This method is called by the nsIRDFService after constructing
     * a resource object to initialize its URI. You would not normally
     * call this method directly
     */
  /* void Init (in string uri); */
  NS_SCRIPTABLE NS_IMETHOD Init(const char *uri) = 0;

  /**
     * Determine if the resource has the given URI.
     */
  /* boolean EqualsString (in string aURI); */
  NS_SCRIPTABLE NS_IMETHOD EqualsString(const char *aURI, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Retrieve the "delegate" object for this resource. A resource
     * may have several delegate objects, each of whose lifetimes is
     * bound to the life of the resource object.
     *
     * This method will return the delegate for the given key after
     * QueryInterface()-ing it to the requested IID.
     *
     * If no delegate exists for the specified key, this method will
     * attempt to create one using the component manager. Specifically,
     * it will combine aKey with the resource's URI scheme to produce
     * a ContractID as follows:
     *
     *   component:/rdf/delegate-factory/[key]/[scheme]
     *
     * This ContractID will be used to locate a factory using the
     * FindFactory() method of nsIComponentManager. If the nsIFactory
     * exists, it will be used to create a "delegate factory"; that
     * is, an object that supports nsIRDFDelegateFactory. The delegate
     * factory will be used to construct the delegate object.
     */
  /* void GetDelegate (in string aKey, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult aResult); */
  NS_SCRIPTABLE NS_IMETHOD GetDelegate(const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM) = 0;

  /**
     * Force a delegate to be "unbound" from the resource.
     *
     * Normally, a delegate object's lifetime will be identical to
     * that of the resource to which it is bound; this method allows a
     * delegate to unlink itself from an RDF resource prematurely.
     */
  /* void ReleaseDelegate (in string aKey); */
  NS_SCRIPTABLE NS_IMETHOD ReleaseDelegate(const char *aKey) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFResource, NS_IRDFRESOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFRESOURCE \
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetValueUTF8(nsACString & aValueUTF8); \
  NS_IMETHOD GetValueConst(const char **aConstValue NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Init(const char *uri); \
  NS_SCRIPTABLE NS_IMETHOD EqualsString(const char *aURI, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDelegate(const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReleaseDelegate(const char *aKey); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFRESOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueUTF8(nsACString & aValueUTF8) { return _to GetValueUTF8(aValueUTF8); } \
  NS_IMETHOD GetValueConst(const char **aConstValue NS_OUTPARAM) { return _to GetValueConst(aConstValue); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const char *uri) { return _to Init(uri); } \
  NS_SCRIPTABLE NS_IMETHOD EqualsString(const char *aURI, PRBool *_retval NS_OUTPARAM) { return _to EqualsString(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDelegate(const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM) { return _to GetDelegate(aKey, aIID, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD ReleaseDelegate(const char *aKey) { return _to ReleaseDelegate(aKey); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFRESOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueUTF8(nsACString & aValueUTF8) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueUTF8(aValueUTF8); } \
  NS_IMETHOD GetValueConst(const char **aConstValue NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueConst(aConstValue); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const char *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(uri); } \
  NS_SCRIPTABLE NS_IMETHOD EqualsString(const char *aURI, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EqualsString(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDelegate(const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelegate(aKey, aIID, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD ReleaseDelegate(const char *aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseDelegate(aKey); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFResource : public nsIRDFResource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFRESOURCE

  nsRDFResource();

private:
  ~nsRDFResource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFResource, nsIRDFResource)

nsRDFResource::nsRDFResource()
{
  /* member initializers and constructor code */
}

nsRDFResource::~nsRDFResource()
{
  /* destructor code */
}

/* readonly attribute string Value; */
NS_IMETHODIMP nsRDFResource::GetValue(char * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String ValueUTF8; */
NS_IMETHODIMP nsRDFResource::GetValueUTF8(nsACString & aValueUTF8)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetValueConst ([shared] out string aConstValue); */
NS_IMETHODIMP nsRDFResource::GetValueConst(const char **aConstValue NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Init (in string uri); */
NS_IMETHODIMP nsRDFResource::Init(const char *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean EqualsString (in string aURI); */
NS_IMETHODIMP nsRDFResource::EqualsString(const char *aURI, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetDelegate (in string aKey, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult aResult); */
NS_IMETHODIMP nsRDFResource::GetDelegate(const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ReleaseDelegate (in string aKey); */
NS_IMETHODIMP nsRDFResource::ReleaseDelegate(const char *aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFResource_h__ */
