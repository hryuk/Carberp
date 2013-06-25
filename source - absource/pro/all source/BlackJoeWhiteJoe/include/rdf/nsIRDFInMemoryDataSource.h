/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFInMemoryDataSource.idl
 */

#ifndef __gen_nsIRDFInMemoryDataSource_h__
#define __gen_nsIRDFInMemoryDataSource_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRDFResource_h__
#include "nsIRDFResource.h"
#endif

#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFInMemoryDataSource */
#define NS_IRDFINMEMORYDATASOURCE_IID_STR "17c4e0aa-1dd2-11b2-8029-bf6f668de500"

#define NS_IRDFINMEMORYDATASOURCE_IID \
  {0x17c4e0aa, 0x1dd2, 0x11b2, \
    { 0x80, 0x29, 0xbf, 0x6f, 0x66, 0x8d, 0xe5, 0x00 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFInMemoryDataSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFINMEMORYDATASOURCE_IID)

  /* void EnsureFastContainment (in nsIRDFResource aSource); */
  NS_SCRIPTABLE NS_IMETHOD EnsureFastContainment(nsIRDFResource *aSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFInMemoryDataSource, NS_IRDFINMEMORYDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFINMEMORYDATASOURCE \
  NS_SCRIPTABLE NS_IMETHOD EnsureFastContainment(nsIRDFResource *aSource); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFINMEMORYDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnsureFastContainment(nsIRDFResource *aSource) { return _to EnsureFastContainment(aSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFINMEMORYDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnsureFastContainment(nsIRDFResource *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureFastContainment(aSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFInMemoryDataSource : public nsIRDFInMemoryDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFINMEMORYDATASOURCE

  nsRDFInMemoryDataSource();

private:
  ~nsRDFInMemoryDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFInMemoryDataSource, nsIRDFInMemoryDataSource)

nsRDFInMemoryDataSource::nsRDFInMemoryDataSource()
{
  /* member initializers and constructor code */
}

nsRDFInMemoryDataSource::~nsRDFInMemoryDataSource()
{
  /* destructor code */
}

/* void EnsureFastContainment (in nsIRDFResource aSource); */
NS_IMETHODIMP nsRDFInMemoryDataSource::EnsureFastContainment(nsIRDFResource *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFInMemoryDataSource_h__ */
