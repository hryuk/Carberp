/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFCompositeDataSource.idl
 */

#ifndef __gen_nsIRDFCompositeDataSource_h__
#define __gen_nsIRDFCompositeDataSource_h__


#ifndef __gen_nsIRDFDataSource_h__
#include "nsIRDFDataSource.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIRDFCompositeDataSource */
#define NS_IRDFCOMPOSITEDATASOURCE_IID_STR "96343820-307c-11d2-bc15-00805f912fe7"

#define NS_IRDFCOMPOSITEDATASOURCE_IID \
  {0x96343820, 0x307c, 0x11d2, \
    { 0xbc, 0x15, 0x00, 0x80, 0x5f, 0x91, 0x2f, 0xe7 }}

/**
 * An nsIRDFCompositeDataSource composes individual data sources, providing
 * the illusion of a single, coherent RDF graph.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFCompositeDataSource : public nsIRDFDataSource {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFCOMPOSITEDATASOURCE_IID)

  /**
     *
     * Set this value to <code>true</code> if the composite datasource
     * may contains at least one datasource that has <em>negative</em>
     * assertions. (This is the default.)
     *
     * Set this value to <code>false</code> if none of the datasources
     * being composed contains a negative assertion. This allows the
     * composite datasource to perform some query optimizations.
     *
     * By default, this value is <code>true</true>.
     */
  /* attribute boolean allowNegativeAssertions; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowNegativeAssertions(PRBool *aAllowNegativeAssertions) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAllowNegativeAssertions(PRBool aAllowNegativeAssertions) = 0;

  /**
     * Set to <code>true</code> if the composite datasource should
     * take care to coalesce duplicate arcs when returning values from
     * queries. (This is the default.)
     *
     * Set to <code>false</code> if the composite datasource shouldn't
     * bother to check for duplicates. This allows the composite
     * datasource to more efficiently answer queries.
     *
     * By default, this value is <code>true</code>.
     */
  /* attribute boolean coalesceDuplicateArcs; */
  NS_SCRIPTABLE NS_IMETHOD GetCoalesceDuplicateArcs(PRBool *aCoalesceDuplicateArcs) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCoalesceDuplicateArcs(PRBool aCoalesceDuplicateArcs) = 0;

  /**
     * Add a datasource the the composite data source.
     * @param aDataSource the datasource to add to composite
     */
  /* void AddDataSource (in nsIRDFDataSource aDataSource); */
  NS_SCRIPTABLE NS_IMETHOD AddDataSource(nsIRDFDataSource *aDataSource) = 0;

  /**
     * Remove a datasource from the composite data source.
     * @param aDataSource the datasource to remove from the composite
     */
  /* void RemoveDataSource (in nsIRDFDataSource aDataSource); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDataSource(nsIRDFDataSource *aDataSource) = 0;

  /**
     * Retrieve the datasources in the composite data source.
     * @return an nsISimpleEnumerator that will enumerate each
     * of the datasources in the composite
     */
  /* nsISimpleEnumerator GetDataSources (); */
  NS_SCRIPTABLE NS_IMETHOD GetDataSources(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFCompositeDataSource, NS_IRDFCOMPOSITEDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFCOMPOSITEDATASOURCE \
  NS_SCRIPTABLE NS_IMETHOD GetAllowNegativeAssertions(PRBool *aAllowNegativeAssertions); \
  NS_SCRIPTABLE NS_IMETHOD SetAllowNegativeAssertions(PRBool aAllowNegativeAssertions); \
  NS_SCRIPTABLE NS_IMETHOD GetCoalesceDuplicateArcs(PRBool *aCoalesceDuplicateArcs); \
  NS_SCRIPTABLE NS_IMETHOD SetCoalesceDuplicateArcs(PRBool aCoalesceDuplicateArcs); \
  NS_SCRIPTABLE NS_IMETHOD AddDataSource(nsIRDFDataSource *aDataSource); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDataSource(nsIRDFDataSource *aDataSource); \
  NS_SCRIPTABLE NS_IMETHOD GetDataSources(nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFCOMPOSITEDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAllowNegativeAssertions(PRBool *aAllowNegativeAssertions) { return _to GetAllowNegativeAssertions(aAllowNegativeAssertions); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowNegativeAssertions(PRBool aAllowNegativeAssertions) { return _to SetAllowNegativeAssertions(aAllowNegativeAssertions); } \
  NS_SCRIPTABLE NS_IMETHOD GetCoalesceDuplicateArcs(PRBool *aCoalesceDuplicateArcs) { return _to GetCoalesceDuplicateArcs(aCoalesceDuplicateArcs); } \
  NS_SCRIPTABLE NS_IMETHOD SetCoalesceDuplicateArcs(PRBool aCoalesceDuplicateArcs) { return _to SetCoalesceDuplicateArcs(aCoalesceDuplicateArcs); } \
  NS_SCRIPTABLE NS_IMETHOD AddDataSource(nsIRDFDataSource *aDataSource) { return _to AddDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDataSource(nsIRDFDataSource *aDataSource) { return _to RemoveDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSources(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetDataSources(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFCOMPOSITEDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAllowNegativeAssertions(PRBool *aAllowNegativeAssertions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowNegativeAssertions(aAllowNegativeAssertions); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowNegativeAssertions(PRBool aAllowNegativeAssertions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowNegativeAssertions(aAllowNegativeAssertions); } \
  NS_SCRIPTABLE NS_IMETHOD GetCoalesceDuplicateArcs(PRBool *aCoalesceDuplicateArcs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoalesceDuplicateArcs(aCoalesceDuplicateArcs); } \
  NS_SCRIPTABLE NS_IMETHOD SetCoalesceDuplicateArcs(PRBool aCoalesceDuplicateArcs) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCoalesceDuplicateArcs(aCoalesceDuplicateArcs); } \
  NS_SCRIPTABLE NS_IMETHOD AddDataSource(nsIRDFDataSource *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDataSource(nsIRDFDataSource *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSources(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSources(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFCompositeDataSource : public nsIRDFCompositeDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFCOMPOSITEDATASOURCE

  nsRDFCompositeDataSource();

private:
  ~nsRDFCompositeDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFCompositeDataSource, nsIRDFCompositeDataSource)

nsRDFCompositeDataSource::nsRDFCompositeDataSource()
{
  /* member initializers and constructor code */
}

nsRDFCompositeDataSource::~nsRDFCompositeDataSource()
{
  /* destructor code */
}

/* attribute boolean allowNegativeAssertions; */
NS_IMETHODIMP nsRDFCompositeDataSource::GetAllowNegativeAssertions(PRBool *aAllowNegativeAssertions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRDFCompositeDataSource::SetAllowNegativeAssertions(PRBool aAllowNegativeAssertions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean coalesceDuplicateArcs; */
NS_IMETHODIMP nsRDFCompositeDataSource::GetCoalesceDuplicateArcs(PRBool *aCoalesceDuplicateArcs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRDFCompositeDataSource::SetCoalesceDuplicateArcs(PRBool aCoalesceDuplicateArcs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddDataSource (in nsIRDFDataSource aDataSource); */
NS_IMETHODIMP nsRDFCompositeDataSource::AddDataSource(nsIRDFDataSource *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveDataSource (in nsIRDFDataSource aDataSource); */
NS_IMETHODIMP nsRDFCompositeDataSource::RemoveDataSource(nsIRDFDataSource *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetDataSources (); */
NS_IMETHODIMP nsRDFCompositeDataSource::GetDataSources(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

extern nsresult
NS_NewRDFCompositeDataSource(nsIRDFCompositeDataSource** result);

#endif /* __gen_nsIRDFCompositeDataSource_h__ */
