/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFXMLSerializer.idl
 */

#ifndef __gen_nsIRDFXMLSerializer_h__
#define __gen_nsIRDFXMLSerializer_h__


#ifndef __gen_nsIAtom_h__
#include "nsIAtom.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRDFDataSource_h__
#include "nsIRDFDataSource.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFXMLSerializer */
#define NS_IRDFXMLSERIALIZER_IID_STR "8ae1fbf8-1dd2-11b2-bd21-d728069cca92"

#define NS_IRDFXMLSERIALIZER_IID \
  {0x8ae1fbf8, 0x1dd2, 0x11b2, \
    { 0xbd, 0x21, 0xd7, 0x28, 0x06, 0x9c, 0xca, 0x92 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFXMLSerializer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFXMLSERIALIZER_IID)

  /**
     * Initialize the serializer with the specified datasource.
     * @param aDataSource the datasource from which data will be
     *   serialized
     */
  /* void init (in nsIRDFDataSource aDataSource); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIRDFDataSource *aDataSource) = 0;

  /**
     * Add the specified namespace to the serializer.
     * @param aPrefix the attribute namespace prefix
     * @param aURI the namespace URI
     */
  /* void addNameSpace (in nsIAtom aPrefix, in DOMString aURI); */
  NS_SCRIPTABLE NS_IMETHOD AddNameSpace(nsIAtom *aPrefix, const nsAString & aURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFXMLSerializer, NS_IRDFXMLSERIALIZER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFXMLSERIALIZER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIRDFDataSource *aDataSource); \
  NS_SCRIPTABLE NS_IMETHOD AddNameSpace(nsIAtom *aPrefix, const nsAString & aURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFXMLSERIALIZER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIRDFDataSource *aDataSource) { return _to Init(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD AddNameSpace(nsIAtom *aPrefix, const nsAString & aURI) { return _to AddNameSpace(aPrefix, aURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFXMLSERIALIZER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIRDFDataSource *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD AddNameSpace(nsIAtom *aPrefix, const nsAString & aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddNameSpace(aPrefix, aURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFXMLSerializer : public nsIRDFXMLSerializer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFXMLSERIALIZER

  nsRDFXMLSerializer();

private:
  ~nsRDFXMLSerializer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFXMLSerializer, nsIRDFXMLSerializer)

nsRDFXMLSerializer::nsRDFXMLSerializer()
{
  /* member initializers and constructor code */
}

nsRDFXMLSerializer::~nsRDFXMLSerializer()
{
  /* destructor code */
}

/* void init (in nsIRDFDataSource aDataSource); */
NS_IMETHODIMP nsRDFXMLSerializer::Init(nsIRDFDataSource *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addNameSpace (in nsIAtom aPrefix, in DOMString aURI); */
NS_IMETHODIMP nsRDFXMLSerializer::AddNameSpace(nsIAtom *aPrefix, const nsAString & aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFXMLSerializer_h__ */
