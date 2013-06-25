/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFInferDataSource.idl
 */

#ifndef __gen_nsIRDFInferDataSource_h__
#define __gen_nsIRDFInferDataSource_h__


#ifndef __gen_nsIRDFDataSource_h__
#include "nsIRDFDataSource.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFInferDataSource */
#define NS_IRDFINFERDATASOURCE_IID_STR "2b04860f-4017-40f6-8a57-784a1e35077a"

#define NS_IRDFINFERDATASOURCE_IID \
  {0x2b04860f, 0x4017, 0x40f6, \
    { 0x8a, 0x57, 0x78, 0x4a, 0x1e, 0x35, 0x07, 0x7a }}

/**
 * An nsIRDFInferDataSource is implemented by a infer engine. This
 * engine mimics assertions in addition to those in the baseDataSource
 * according to a particular vocabulary.
 * Infer engines have contract IDs in the form of
 * "@mozilla.org/rdf/infer-datasource;1?engine="
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFInferDataSource : public nsIRDFDataSource {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFINFERDATASOURCE_IID)

  /**
     *
     * The wrapped datasource.
     *
     * The InferDataSource contains all arcs from the wrapped
     * datasource plus those infered by the vocabulary implemented
     * by the InferDataSource.
     */
  /* attribute nsIRDFDataSource baseDataSource; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBaseDataSource(nsIRDFDataSource * aBaseDataSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFInferDataSource, NS_IRDFINFERDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFINFERDATASOURCE \
  NS_SCRIPTABLE NS_IMETHOD GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource); \
  NS_SCRIPTABLE NS_IMETHOD SetBaseDataSource(nsIRDFDataSource * aBaseDataSource); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFINFERDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource) { return _to GetBaseDataSource(aBaseDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseDataSource(nsIRDFDataSource * aBaseDataSource) { return _to SetBaseDataSource(aBaseDataSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFINFERDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseDataSource(aBaseDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseDataSource(nsIRDFDataSource * aBaseDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseDataSource(aBaseDataSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFInferDataSource : public nsIRDFInferDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFINFERDATASOURCE

  nsRDFInferDataSource();

private:
  ~nsRDFInferDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFInferDataSource, nsIRDFInferDataSource)

nsRDFInferDataSource::nsRDFInferDataSource()
{
  /* member initializers and constructor code */
}

nsRDFInferDataSource::~nsRDFInferDataSource()
{
  /* destructor code */
}

/* attribute nsIRDFDataSource baseDataSource; */
NS_IMETHODIMP nsRDFInferDataSource::GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRDFInferDataSource::SetBaseDataSource(nsIRDFDataSource * aBaseDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFInferDataSource_h__ */
