/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/rdfISerializer.idl
 */

#ifndef __gen_rdfISerializer_h__
#define __gen_rdfISerializer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class rdfIDataSource; /* forward declaration */

class nsIOutputStream; /* forward declaration */


/* starting interface:    rdfISerializer */
#define RDFISERIALIZER_IID_STR "f0edfcdd-8bca-4d32-9226-7421001396a4"

#define RDFISERIALIZER_IID \
  {0xf0edfcdd, 0x8bca, 0x4d32, \
    { 0x92, 0x26, 0x74, 0x21, 0x00, 0x13, 0x96, 0xa4 }}

/**
 * Interface used to serialize RDF.
 *
 * @status PLASMA
 */
class NS_NO_VTABLE NS_SCRIPTABLE rdfISerializer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(RDFISERIALIZER_IID)

  /**
     * Synchronously serialize the given datasource to the outputstream.
     *
     * Implementations are not required to implement any buffering or
     * other stream-based optimizations.
     *
     * @param aDataSource The RDF data source to be serialized.
     * @param aOut The output stream to use.
     */
  /* void serialize (in rdfIDataSource aDataSource, in nsIOutputStream aOut); */
  NS_SCRIPTABLE NS_IMETHOD Serialize(rdfIDataSource *aDataSource, nsIOutputStream *aOut) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(rdfISerializer, RDFISERIALIZER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_RDFISERIALIZER \
  NS_SCRIPTABLE NS_IMETHOD Serialize(rdfIDataSource *aDataSource, nsIOutputStream *aOut); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_RDFISERIALIZER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Serialize(rdfIDataSource *aDataSource, nsIOutputStream *aOut) { return _to Serialize(aDataSource, aOut); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_RDFISERIALIZER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Serialize(rdfIDataSource *aDataSource, nsIOutputStream *aOut) { return !_to ? NS_ERROR_NULL_POINTER : _to->Serialize(aDataSource, aOut); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public rdfISerializer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_RDFISERIALIZER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, rdfISerializer)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void serialize (in rdfIDataSource aDataSource, in nsIOutputStream aOut); */
NS_IMETHODIMP _MYCLASS_::Serialize(rdfIDataSource *aDataSource, nsIOutputStream *aOut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_rdfISerializer_h__ */
