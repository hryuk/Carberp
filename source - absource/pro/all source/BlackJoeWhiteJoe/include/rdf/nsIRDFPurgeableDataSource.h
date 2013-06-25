/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFPurgeableDataSource.idl
 */

#ifndef __gen_nsIRDFPurgeableDataSource_h__
#define __gen_nsIRDFPurgeableDataSource_h__


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

/* starting interface:    nsIRDFPurgeableDataSource */
#define NS_IRDFPURGEABLEDATASOURCE_IID_STR "951700f0-fed0-11d2-bdd9-00104bde6048"

#define NS_IRDFPURGEABLEDATASOURCE_IID \
  {0x951700f0, 0xfed0, 0x11d2, \
    { 0xbd, 0xd9, 0x00, 0x10, 0x4b, 0xde, 0x60, 0x48 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFPurgeableDataSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFPURGEABLEDATASOURCE_IID)

  /* boolean Mark (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
  NS_SCRIPTABLE NS_IMETHOD Mark(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM) = 0;

  /* void Sweep (); */
  NS_SCRIPTABLE NS_IMETHOD Sweep(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFPurgeableDataSource, NS_IRDFPURGEABLEDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFPURGEABLEDATASOURCE \
  NS_SCRIPTABLE NS_IMETHOD Mark(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Sweep(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFPURGEABLEDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Mark(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM) { return _to Mark(aSource, aProperty, aTarget, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Sweep(void) { return _to Sweep(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFPURGEABLEDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Mark(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Mark(aSource, aProperty, aTarget, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Sweep(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Sweep(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFPurgeableDataSource : public nsIRDFPurgeableDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFPURGEABLEDATASOURCE

  nsRDFPurgeableDataSource();

private:
  ~nsRDFPurgeableDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFPurgeableDataSource, nsIRDFPurgeableDataSource)

nsRDFPurgeableDataSource::nsRDFPurgeableDataSource()
{
  /* member initializers and constructor code */
}

nsRDFPurgeableDataSource::~nsRDFPurgeableDataSource()
{
  /* destructor code */
}

/* boolean Mark (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFPurgeableDataSource::Mark(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Sweep (); */
NS_IMETHODIMP nsRDFPurgeableDataSource::Sweep()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFPurgeableDataSource_h__ */
