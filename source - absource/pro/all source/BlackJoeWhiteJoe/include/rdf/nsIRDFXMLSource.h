/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFXMLSource.idl
 */

#ifndef __gen_nsIRDFXMLSource_h__
#define __gen_nsIRDFXMLSource_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIOutputStream_h__
#include "nsIOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFXMLSource */
#define NS_IRDFXMLSOURCE_IID_STR "4da56f10-99fe-11d2-8ebb-00805f29f370"

#define NS_IRDFXMLSOURCE_IID \
  {0x4da56f10, 0x99fe, 0x11d2, \
    { 0x8e, 0xbb, 0x00, 0x80, 0x5f, 0x29, 0xf3, 0x70 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFXMLSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFXMLSOURCE_IID)

  /**
     * Serialize the contents of the datasource to aStream.
     * @param aStream the output stream the will receive the
     *   RDF/XML. Currently, the output stream need only
     *   implement the |write()| method.
     */
  /* void Serialize (in nsIOutputStream aStream); */
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIOutputStream *aStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFXMLSource, NS_IRDFXMLSOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFXMLSOURCE \
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIOutputStream *aStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFXMLSOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIOutputStream *aStream) { return _to Serialize(aStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFXMLSOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Serialize(nsIOutputStream *aStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->Serialize(aStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFXMLSource : public nsIRDFXMLSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFXMLSOURCE

  nsRDFXMLSource();

private:
  ~nsRDFXMLSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFXMLSource, nsIRDFXMLSource)

nsRDFXMLSource::nsRDFXMLSource()
{
  /* member initializers and constructor code */
}

nsRDFXMLSource::~nsRDFXMLSource()
{
  /* destructor code */
}

/* void Serialize (in nsIOutputStream aStream); */
NS_IMETHODIMP nsRDFXMLSource::Serialize(nsIOutputStream *aStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFXMLSource_h__ */
