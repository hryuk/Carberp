/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFDataSource.idl
 */

#ifndef __gen_nsIRDFDataSource_h__
#define __gen_nsIRDFDataSource_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISupportsArray_h__
#include "nsISupportsArray.h"
#endif

#ifndef __gen_nsIRDFResource_h__
#include "nsIRDFResource.h"
#endif

#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

#ifndef __gen_nsIRDFObserver_h__
#include "nsIRDFObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsISupportsArray.h"

/* starting interface:    nsIRDFDataSource */
#define NS_IRDFDATASOURCE_IID_STR "0f78da58-8321-11d2-8eac-00805f29f370"

#define NS_IRDFDATASOURCE_IID \
  {0x0f78da58, 0x8321, 0x11d2, \
    { 0x8e, 0xac, 0x00, 0x80, 0x5f, 0x29, 0xf3, 0x70 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFDataSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFDATASOURCE_IID)

  /** The "URI" of the data source. This used by the RDF service's
     * |GetDataSource()| method to cache datasources.
     */
  /* readonly attribute string URI; */
  NS_SCRIPTABLE NS_IMETHOD GetURI(char * *aURI) = 0;

  /** Find an RDF resource that points to a given node over the
     * specified arc & truth value
     *
     * @return NS_RDF_NO_VALUE if there is no source that leads
     * to the target with the specified property.
     */
  /* nsIRDFResource GetSource (in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsIRDFResource **_retval NS_OUTPARAM) = 0;

  /**
     * Find all RDF resources that point to a given node over the
     * specified arc & truth value
     *
     * @return NS_OK unless a catastrophic error occurs. If the
     * method returns NS_OK, you may assume that nsISimpleEnumerator points
     * to a valid (but possibly empty) cursor.
     */
  /* nsISimpleEnumerator GetSources (in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
  NS_SCRIPTABLE NS_IMETHOD GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Find a child of that is related to the source by the given arc
     * arc and truth value
     *
     * @return NS_RDF_NO_VALUE if there is no target accessible from the
     * source via the specified property.
     */
  /* nsIRDFNode GetTarget (in nsIRDFResource aSource, in nsIRDFResource aProperty, in boolean aTruthValue); */
  NS_SCRIPTABLE NS_IMETHOD GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsIRDFNode **_retval NS_OUTPARAM) = 0;

  /**
     * Find all children of that are related to the source by the given arc
     * arc and truth value.
     *
     * @return NS_OK unless a catastrophic error occurs. If the
     * method returns NS_OK, you may assume that nsISimpleEnumerator points
     * to a valid (but possibly empty) cursor.
     */
  /* nsISimpleEnumerator GetTargets (in nsIRDFResource aSource, in nsIRDFResource aProperty, in boolean aTruthValue); */
  NS_SCRIPTABLE NS_IMETHOD GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Add an assertion to the graph.
     */
  /* void Assert (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
  NS_SCRIPTABLE NS_IMETHOD Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue) = 0;

  /**
     * Remove an assertion from the graph.
     */
  /* void Unassert (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
  NS_SCRIPTABLE NS_IMETHOD Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) = 0;

  /**
     * Change an assertion from
     *
     *   [aSource]--[aProperty]-->[aOldTarget]
     *
     * to
     * 
     *   [aSource]--[aProperty]-->[aNewTarget]
     */
  /* void Change (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aOldTarget, in nsIRDFNode aNewTarget); */
  NS_SCRIPTABLE NS_IMETHOD Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget) = 0;

  /**
     * 'Move' an assertion from
     *
     *   [aOldSource]--[aProperty]-->[aTarget]
     *
     * to
     * 
     *   [aNewSource]--[aProperty]-->[aTarget]
     */
  /* void Move (in nsIRDFResource aOldSource, in nsIRDFResource aNewSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
  NS_SCRIPTABLE NS_IMETHOD Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) = 0;

  /**
     * Query whether an assertion exists in this graph.
     */
  /* boolean HasAssertion (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
  NS_SCRIPTABLE NS_IMETHOD HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Add an observer to this data source. If the datasource
     * supports observers, the datasource source should hold a strong
     * reference to the observer.
     */
  /* void AddObserver (in nsIRDFObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIRDFObserver *aObserver) = 0;

  /**
     * Remove an observer from this data source.
     */
  /* void RemoveObserver (in nsIRDFObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIRDFObserver *aObserver) = 0;

  /**
     * Get a cursor to iterate over all the arcs that point into a node.
     *
     * @return NS_OK unless a catastrophic error occurs. If the method
     * returns NS_OK, you may assume that labels points to a valid (but
     * possible empty) nsISimpleEnumerator object.
     */
  /* nsISimpleEnumerator ArcLabelsIn (in nsIRDFNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Get a cursor to iterate over all the arcs that originate in
     * a resource.
     *
     * @return NS_OK unless a catastrophic error occurs. If the method
     * returns NS_OK, you may assume that labels points to a valid (but
     * possible empty) nsISimpleEnumerator object.
     */
  /* nsISimpleEnumerator ArcLabelsOut (in nsIRDFResource aSource); */
  NS_SCRIPTABLE NS_IMETHOD ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Retrieve all of the resources that the data source currently
     * refers to.
     */
  /* nsISimpleEnumerator GetAllResources (); */
  NS_SCRIPTABLE NS_IMETHOD GetAllResources(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Returns whether a given command is enabled for a set of sources. 
     */
  /* boolean IsCommandEnabled (in nsISupportsArray aSources, in nsIRDFResource aCommand, in nsISupportsArray aArguments); */
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Perform the specified command on set of sources.
     */
  /* void DoCommand (in nsISupportsArray aSources, in nsIRDFResource aCommand, in nsISupportsArray aArguments); */
  NS_SCRIPTABLE NS_IMETHOD DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments) = 0;

  /**
     * Returns the set of all commands defined for a given source.
     */
  /* nsISimpleEnumerator GetAllCmds (in nsIRDFResource aSource); */
  NS_SCRIPTABLE NS_IMETHOD GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Returns true if the specified node is pointed to by the specified arc.
     * Equivalent to enumerating ArcLabelsIn and comparing for the specified arc.
     */
  /* boolean hasArcIn (in nsIRDFNode aNode, in nsIRDFResource aArc); */
  NS_SCRIPTABLE NS_IMETHOD HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Returns true if the specified node has the specified outward arc.
     * Equivalent to enumerating ArcLabelsOut and comparing for the specified arc.
     */
  /* boolean hasArcOut (in nsIRDFResource aSource, in nsIRDFResource aArc); */
  NS_SCRIPTABLE NS_IMETHOD HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Notify observers that the datasource is about to send several
     * notifications at once.
     * This must be followed by calling endUpdateBatch(), otherwise
     * viewers will get out of sync.
     */
  /* void beginUpdateBatch (); */
  NS_SCRIPTABLE NS_IMETHOD BeginUpdateBatch(void) = 0;

  /**
     * Notify observers that the datasource has completed issuing
     * a notification group.
     */
  /* void endUpdateBatch (); */
  NS_SCRIPTABLE NS_IMETHOD EndUpdateBatch(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFDataSource, NS_IRDFDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFDATASOURCE \
  NS_SCRIPTABLE NS_IMETHOD GetURI(char * *aURI); \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsIRDFResource **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsIRDFNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue); \
  NS_SCRIPTABLE NS_IMETHOD Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget); \
  NS_SCRIPTABLE NS_IMETHOD Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget); \
  NS_SCRIPTABLE NS_IMETHOD Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget); \
  NS_SCRIPTABLE NS_IMETHOD HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIRDFObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIRDFObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAllResources(nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments); \
  NS_SCRIPTABLE NS_IMETHOD GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD BeginUpdateBatch(void); \
  NS_SCRIPTABLE NS_IMETHOD EndUpdateBatch(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetURI(char * *aURI) { return _to GetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsIRDFResource **_retval NS_OUTPARAM) { return _to GetSource(aProperty, aTarget, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetSources(aProperty, aTarget, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsIRDFNode **_retval NS_OUTPARAM) { return _to GetTarget(aSource, aProperty, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetTargets(aSource, aProperty, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue) { return _to Assert(aSource, aProperty, aTarget, aTruthValue); } \
  NS_SCRIPTABLE NS_IMETHOD Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return _to Unassert(aSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget) { return _to Change(aSource, aProperty, aOldTarget, aNewTarget); } \
  NS_SCRIPTABLE NS_IMETHOD Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return _to Move(aOldSource, aNewSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM) { return _to HasAssertion(aSource, aProperty, aTarget, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIRDFObserver *aObserver) { return _to AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIRDFObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to ArcLabelsIn(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to ArcLabelsOut(aSource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllResources(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetAllResources(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, PRBool *_retval NS_OUTPARAM) { return _to IsCommandEnabled(aSources, aCommand, aArguments, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments) { return _to DoCommand(aSources, aCommand, aArguments); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetAllCmds(aSource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM) { return _to HasArcIn(aNode, aArc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM) { return _to HasArcOut(aSource, aArc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD BeginUpdateBatch(void) { return _to BeginUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD EndUpdateBatch(void) { return _to EndUpdateBatch(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetURI(char * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsIRDFResource **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aProperty, aTarget, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSources(aProperty, aTarget, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsIRDFNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aSource, aProperty, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargets(aSource, aProperty, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->Assert(aSource, aProperty, aTarget, aTruthValue); } \
  NS_SCRIPTABLE NS_IMETHOD Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unassert(aSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->Change(aSource, aProperty, aOldTarget, aNewTarget); } \
  NS_SCRIPTABLE NS_IMETHOD Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->Move(aOldSource, aNewSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasAssertion(aSource, aProperty, aTarget, aTruthValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIRDFObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIRDFObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ArcLabelsIn(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ArcLabelsOut(aSource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllResources(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllResources(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandEnabled(aSources, aCommand, aArguments, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(aSources, aCommand, aArguments); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllCmds(aSource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasArcIn(aNode, aArc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasArcOut(aSource, aArc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD BeginUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD EndUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndUpdateBatch(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFDataSource : public nsIRDFDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFDATASOURCE

  nsRDFDataSource();

private:
  ~nsRDFDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFDataSource, nsIRDFDataSource)

nsRDFDataSource::nsRDFDataSource()
{
  /* member initializers and constructor code */
}

nsRDFDataSource::~nsRDFDataSource()
{
  /* destructor code */
}

/* readonly attribute string URI; */
NS_IMETHODIMP nsRDFDataSource::GetURI(char * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFResource GetSource (in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsIRDFResource **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetSources (in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFNode GetTarget (in nsIRDFResource aSource, in nsIRDFResource aProperty, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsIRDFNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetTargets (in nsIRDFResource aSource, in nsIRDFResource aProperty, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, PRBool aTruthValue, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Assert (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Unassert (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
NS_IMETHODIMP nsRDFDataSource::Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Change (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aOldTarget, in nsIRDFNode aNewTarget); */
NS_IMETHODIMP nsRDFDataSource::Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Move (in nsIRDFResource aOldSource, in nsIRDFResource aNewSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
NS_IMETHODIMP nsRDFDataSource::Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean HasAssertion (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, PRBool aTruthValue, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddObserver (in nsIRDFObserver aObserver); */
NS_IMETHODIMP nsRDFDataSource::AddObserver(nsIRDFObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveObserver (in nsIRDFObserver aObserver); */
NS_IMETHODIMP nsRDFDataSource::RemoveObserver(nsIRDFObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator ArcLabelsIn (in nsIRDFNode aNode); */
NS_IMETHODIMP nsRDFDataSource::ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator ArcLabelsOut (in nsIRDFResource aSource); */
NS_IMETHODIMP nsRDFDataSource::ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetAllResources (); */
NS_IMETHODIMP nsRDFDataSource::GetAllResources(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsCommandEnabled (in nsISupportsArray aSources, in nsIRDFResource aCommand, in nsISupportsArray aArguments); */
NS_IMETHODIMP nsRDFDataSource::IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DoCommand (in nsISupportsArray aSources, in nsIRDFResource aCommand, in nsISupportsArray aArguments); */
NS_IMETHODIMP nsRDFDataSource::DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetAllCmds (in nsIRDFResource aSource); */
NS_IMETHODIMP nsRDFDataSource::GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasArcIn (in nsIRDFNode aNode, in nsIRDFResource aArc); */
NS_IMETHODIMP nsRDFDataSource::HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasArcOut (in nsIRDFResource aSource, in nsIRDFResource aArc); */
NS_IMETHODIMP nsRDFDataSource::HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginUpdateBatch (); */
NS_IMETHODIMP nsRDFDataSource::BeginUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endUpdateBatch (); */
NS_IMETHODIMP nsRDFDataSource::EndUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFDataSource_h__ */
