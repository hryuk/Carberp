/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xul/templates/public/nsIXULTemplateQueryProcessor.idl
 */

#ifndef __gen_nsIXULTemplateQueryProcessor_h__
#define __gen_nsIXULTemplateQueryProcessor_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom; /* forward declaration */

class nsIArray; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIXULTemplateResult; /* forward declaration */

class nsIXULTemplateRuleFilter; /* forward declaration */

class nsIXULTemplateBuilder; /* forward declaration */


/* starting interface:    nsIXULTemplateQueryProcessor */
#define NS_IXULTEMPLATEQUERYPROCESSOR_IID_STR "970f1c36-5d2e-4cbc-a1cf-e3327b50df71"

#define NS_IXULTEMPLATEQUERYPROCESSOR_IID \
  {0x970f1c36, 0x5d2e, 0x4cbc, \
    { 0xa1, 0xcf, 0xe3, 0x32, 0x7b, 0x50, 0xdf, 0x71 }}

/**
 * A query processor takes a template query and generates results for it given
 * a datasource and a reference point. There is a one-to-one relationship
 * between a template builder and a query processor. The template builder
 * creates the query processor, and there is no other means to retrieve it.
 *
 * A template query is the contents inside a <query> element within the
 * template. The actual syntax is opaque to the template builder and defined
 * by a query processor. The query is expected to consist of either text or
 * DOM nodes that, when executed by a call to the generateResults method, will
 * allow the generation of a list of results.
 *
 * The template builder will supply two variables, the reference variable and
 * the member variable to further indicate what part of the datasource is to
 * be examined in addition to the query itself. The reference is always
 * a placeholder for the starting point and the member is always a placeholder
 * for the end points (the results).
 *
 * The reference point is important when generating output recursively, as
 * the query will be the same for each iteration, however, the reference point
 * will differ.
 *
 * For instance, when examining an XML source, an XML query processor might
 * begin at the node referred by the reference variable and end at a list of
 * that node's children.
 *
 * Some queries may not need the reference variable if the syntax or the form
 * of the data implies the value. For instance, a datasource that holds a
 * table that can only produce one set of results.
 *
 * The reference variable may be specified in a template by setting the
 * "container" attribute on the <template> element to the variable to use. The
 * member variable may be specified in a similar way using the "member"
 * attribute, or it may be specified in the first <action> body in the
 * template as the value of a uri attribute on an element. A breadth-first
 * search of the first action is performed to find this element.
 *
 * If unspecified, the default value of the reference variable is ?uri.
 *
 * For example, a query might have the following syntax:
 *
 * (?id, ?name, ?url) from Bookmarks where parentfolder = ?start
 *
 * This query might generate a result for each bookmark within a given folder.
 * The variable ?start would be the reference variable, while the variable ?id
 * would be the member variable, since it is the unique value that identifies
 * a result. Each result will have the four variables referred to defined for
 * it and the values may be retrieved using the result's getBindingFor and
 * getBindingObjectFor methods.
 *
 * The template builder must call initializeForBuilding before the other
 * methods, except for translateRef. The builder will then call compileQuery
 * for each query in the template to compile the queries. When results need
 * to be generated, the builder will call generateResults. The
 * initializeForBuilding, compileQuery and addBinding methods may not be
 * called after generateResults has been called until the builder indicates
 * that the generated output is being removed by calling the done method.
 *
 * Currently, the datasource supplied to the methods will always be an
 * nsIRDFDataSource or a DOM node, and will always be the same one in between
 * calls to initializeForBuilding and done.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXULTemplateQueryProcessor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTEMPLATEQUERYPROCESSOR_IID)

  /**
   * Retrieve the datasource to use for the query processor. The list of
   * datasources in a template is specified using the datasources attribute as
   * a space separated list of URIs. This list is processed by the builder and
   * supplied to the query processor in the aDataSources array as a list of
   * nsIURI objects or nsIDOMNode objects. This method may return an object
   * corresponding to these URIs and the builder will supply this object to
   * other query processor methods. For example, for an XML source, the
   * datasource might be an nsIDOMNode.
   *
   * All of these URIs are checked by the builder so it is safe to use them,
   * however note that a URI that redirects may still needs to be checked to
   * ensure that the document containing aRootNode may access it. This is the
   * responsibility of the query processor if it needs to load the content of
   * the URI.
   *
   * If the query processor needs to load the datasource asynchronously, it
   * may set the aShouldDelayBuilding returned parameter to true to delay
   * building the template content, and call the builder's Rebuild method when
   * the data is available.
   *
   * @param aDataSources  the list of nsIURI objects and/or nsIDOMNode objects
   * @param aRootNode     the root node the builder is attached to
   * @param aIsTrusted    true if the template is in a trusted document
   * @param aBuilder      the template builder
   * @param aShouldDelayBuilding [out] whether the builder should wait to
   *                                   build the content or not
   * @returns a datasource object
   */
  /* nsISupports getDatasource (in nsIArray aDataSources, in nsIDOMNode aRootNode, in boolean aIsTrusted, in nsIXULTemplateBuilder aBuilder, out boolean aShouldDelayBuilding); */
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, PRBool aIsTrusted, nsIXULTemplateBuilder *aBuilder, PRBool *aShouldDelayBuilding NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM) = 0;

  /**
   * Initialize for query generation. This will be called before the rules are
   * processed and whenever the template is rebuilt. This method must be
   * called once before any of the other query processor methods except for
   * translateRef.
   *
   * @param aDatasource datasource for the data
   * @param aBuilder the template builder
   * @param aRootNode the root node the builder is attached to
   *
   * @throws NS_ERROR_INVALID_ARG if the datasource is not supported or
   *         NS_ERROR_UNEXPECTED if generateResults has already been called.
   */
  /* void initializeForBuilding (in nsISupports aDatasource, in nsIXULTemplateBuilder aBuilder, in nsIDOMNode aRootNode); */
  NS_SCRIPTABLE NS_IMETHOD InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode) = 0;

  /**
   * Called when the template builder is being destroyed so that the query
   * processor can clean up any state. The query processor should remove as
   * much state as possible, such as results or references to the builder.
   * This method will also be called when the template is going to be rebuilt.
   */
  /* void done (); */
  NS_SCRIPTABLE NS_IMETHOD Done(void) = 0;

  /**
   * Compile a query from a node. The result of this function will later be
   * passed to generateResults for result generation. If null is returned,
   * the query will be ignored.
   *
   * The template builder will call this method once for each query within
   * the template, before any results can be generated using generateResults,
   * but after initializeForBuilding has been called. This method should not
   * be called again for the same query unless the template is rebuilt.
   *
   * The reference variable may be used by the query processor as a
   * placeholder for the reference point, or starting point in the query.
   *
   * The member variable is determined from the member attribute on the
   * template, or from the uri in the first action's rule if that attribute is
   * not present. A rule processor may use the member variable as a hint to
   * indicate what variable is expected to contain the results.
   *
   * @param aBuilder the template builder
   * @param aQuery <query> node to compile
   * @param aRefVariable the reference variable
   * @param aMemberVariable the member variable
   *
   * @returns a compiled query object
   */
  /* nsISupports compileQuery (in nsIXULTemplateBuilder aBuilder, in nsIDOMNode aQuery, in nsIAtom aRefVariable, in nsIAtom aMemberVariable); */
  NS_SCRIPTABLE NS_IMETHOD CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports **_retval NS_OUTPARAM) = 0;

  /**
   * Generate the results of a query and return them in an enumerator. The
   * enumerator must contain nsIXULTemplateResult objects. If there are no
   * results, an empty enumerator must be returned.
   *
   * The datasource will be the same as the one passed to the earlier
   * initializeForBuilding method. The context reference (aRef) is a reference
   * point used when calculating results.
   *
   * The value of aQuery must be the result of a previous call to compileQuery
   * from this query processor. This method may be called multiple times,
   * typically with different values for aRef.
   *
   * @param aDatasource datasource for the data
   * @param aRef context reference value used as a starting point
   * @param aQuery the compiled query returned from query compilation
   *
   * @returns an enumerator of nsIXULTemplateResult objects as the results
   *
   * @throws NS_ERROR_INVALID_ARG if aQuery is invalid
   */
  /* nsISimpleEnumerator generateResults (in nsISupports aDatasource, in nsIXULTemplateResult aRef, in nsISupports aQuery); */
  NS_SCRIPTABLE NS_IMETHOD GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
   * Add a variable binding for a particular rule. A binding allows an
   * additional variable to be set for a result, outside of those defined
   * within the query. These bindings are always optional, in that they will
   * never affect the results generated.
   *
   * This function will never be called after generateResults. Any bindings
   * that were added should be applied to each result when the result's
   * ruleMatched method is called, since the bindings are different for each
   * rule.
   *
   * The reference aRef may be used to determine the reference when
   * calculating the value for the binding, for example when a value should
   * depend on the value of another variable.
   *
   * The syntax of the expression aExpr is defined by the query processor. If
   * the syntax is invalid, the binding should be ignored. Only fatal errors
   * should be thrown, or NS_ERROR_UNEXPECTED if generateResults has already
   * been called.
   *
   * As an example, if the reference aRef is the variable '?count' which
   * holds the value 5, and the expression aExpr is the string '+2', the value
   * of the variable aVar would be 7, assuming the query processor considers
   * the syntax '+2' to mean add two to the reference.
   *
   * @param aRuleNode rule to add the binding to
   * @param aVar variable that will be bound
   * @param aRef variable that holds reference value
   * @param aExpr expression used to compute the value to assign
   */
  /* void addBinding (in nsIDOMNode aRuleNode, in nsIAtom aVar, in nsIAtom aRef, in AString aExpr); */
  NS_SCRIPTABLE NS_IMETHOD AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr) = 0;

  /**
   * Translate a ref attribute string into a result. This is used as the
   * reference point by the template builder when generating the first level
   * of content. For recursive generation, the result from the parent
   * generation phase will be used directly as the reference so a translation
   * is not needed. This allows all levels to be generated using objects that
   * all implement the nsIXULTemplateResult interface.
   *
   * This method may be called before initializeForBuilding, so the
   * implementation may use the supplied datasource if it is needed to
   * translate the reference.
   *
   * @param aDatasource datasource for the data
   * @param aRefString the ref attribute string
   *
   * @return the translated ref
   */
  /* nsIXULTemplateResult translateRef (in nsISupports aDatasource, in AString aRefString); */
  NS_SCRIPTABLE NS_IMETHOD TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult **_retval NS_OUTPARAM) = 0;

  /**
   * Compare two results to determine their order, used when sorting results.
   * This method should return -1 when the left result is less than the right,
   * 0 if both are equivalent, and 1 if the left is greater than the right.
   * The comparison should only consider the values for the specified
   * variable.
   *
   * If the comparison variable is null, the results may be
   * sorted in a natural order, for instance, based on the order the data in
   * stored in the datasource.
   *
   * This method must only be called with results that were created by this
   * query processor.
   *
   * @param aLeft the left result to compare
   * @param aRight the right result to compare
   * @param aVar variable to compare
   *
   * @param returns -1 if less, 0 if equal, or 1 if greater
   */
  /* PRInt32 compareResults (in nsIXULTemplateResult aLeft, in nsIXULTemplateResult aRight, in nsIAtom aVar); */
  NS_SCRIPTABLE NS_IMETHOD CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTemplateQueryProcessor, NS_IXULTEMPLATEQUERYPROCESSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTEMPLATEQUERYPROCESSOR \
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, PRBool aIsTrusted, nsIXULTemplateBuilder *aBuilder, PRBool *aShouldDelayBuilding NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode); \
  NS_SCRIPTABLE NS_IMETHOD Done(void); \
  NS_SCRIPTABLE NS_IMETHOD CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr); \
  NS_SCRIPTABLE NS_IMETHOD TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTEMPLATEQUERYPROCESSOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, PRBool aIsTrusted, nsIXULTemplateBuilder *aBuilder, PRBool *aShouldDelayBuilding NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM) { return _to GetDatasource(aDataSources, aRootNode, aIsTrusted, aBuilder, aShouldDelayBuilding, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode) { return _to InitializeForBuilding(aDatasource, aBuilder, aRootNode); } \
  NS_SCRIPTABLE NS_IMETHOD Done(void) { return _to Done(); } \
  NS_SCRIPTABLE NS_IMETHOD CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports **_retval NS_OUTPARAM) { return _to CompileQuery(aBuilder, aQuery, aRefVariable, aMemberVariable, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GenerateResults(aDatasource, aRef, aQuery, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr) { return _to AddBinding(aRuleNode, aVar, aRef, aExpr); } \
  NS_SCRIPTABLE NS_IMETHOD TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult **_retval NS_OUTPARAM) { return _to TranslateRef(aDatasource, aRefString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, PRInt32 *_retval NS_OUTPARAM) { return _to CompareResults(aLeft, aRight, aVar, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTEMPLATEQUERYPROCESSOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, PRBool aIsTrusted, nsIXULTemplateBuilder *aBuilder, PRBool *aShouldDelayBuilding NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatasource(aDataSources, aRootNode, aIsTrusted, aBuilder, aShouldDelayBuilding, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitializeForBuilding(aDatasource, aBuilder, aRootNode); } \
  NS_SCRIPTABLE NS_IMETHOD Done(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Done(); } \
  NS_SCRIPTABLE NS_IMETHOD CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompileQuery(aBuilder, aQuery, aRefVariable, aMemberVariable, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateResults(aDatasource, aRef, aQuery, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddBinding(aRuleNode, aVar, aRef, aExpr); } \
  NS_SCRIPTABLE NS_IMETHOD TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TranslateRef(aDatasource, aRefString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareResults(aLeft, aRight, aVar, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTemplateQueryProcessor : public nsIXULTemplateQueryProcessor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTEMPLATEQUERYPROCESSOR

  nsXULTemplateQueryProcessor();

private:
  ~nsXULTemplateQueryProcessor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTemplateQueryProcessor, nsIXULTemplateQueryProcessor)

nsXULTemplateQueryProcessor::nsXULTemplateQueryProcessor()
{
  /* member initializers and constructor code */
}

nsXULTemplateQueryProcessor::~nsXULTemplateQueryProcessor()
{
  /* destructor code */
}

/* nsISupports getDatasource (in nsIArray aDataSources, in nsIDOMNode aRootNode, in boolean aIsTrusted, in nsIXULTemplateBuilder aBuilder, out boolean aShouldDelayBuilding); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, PRBool aIsTrusted, nsIXULTemplateBuilder *aBuilder, PRBool *aShouldDelayBuilding NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initializeForBuilding (in nsISupports aDatasource, in nsIXULTemplateBuilder aBuilder, in nsIDOMNode aRootNode); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void done (); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::Done()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports compileQuery (in nsIXULTemplateBuilder aBuilder, in nsIDOMNode aQuery, in nsIAtom aRefVariable, in nsIAtom aMemberVariable); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator generateResults (in nsISupports aDatasource, in nsIXULTemplateResult aRef, in nsISupports aQuery); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addBinding (in nsIDOMNode aRuleNode, in nsIAtom aVar, in nsIAtom aRef, in AString aExpr); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXULTemplateResult translateRef (in nsISupports aDatasource, in AString aRefString); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRInt32 compareResults (in nsIXULTemplateResult aLeft, in nsIXULTemplateResult aRight, in nsIAtom aVar); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULTemplateQueryProcessor_h__ */
