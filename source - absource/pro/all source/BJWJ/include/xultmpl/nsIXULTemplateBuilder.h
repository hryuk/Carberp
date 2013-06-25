/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xul/templates/public/nsIXULTemplateBuilder.idl
 */

#ifndef __gen_nsIXULTemplateBuilder_h__
#define __gen_nsIXULTemplateBuilder_h__


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

class nsIContent; /* forward declaration */

class nsIXULBuilderListener; /* forward declaration */

class nsIXULTemplateResult; /* forward declaration */

class nsIXULTemplateRuleFilter; /* forward declaration */

class nsIXULTemplateQueryProcessor; /* forward declaration */

class nsIRDFResource; /* forward declaration */

class nsIRDFCompositeDataSource; /* forward declaration */


/* starting interface:    nsIXULTemplateBuilder */
#define NS_IXULTEMPLATEBUILDER_IID_STR "a583b676-5b02-4f9c-a0c9-cb850cb99818"

#define NS_IXULTEMPLATEBUILDER_IID \
  {0xa583b676, 0x5b02, 0x4f9c, \
    { 0xa0, 0xc9, 0xcb, 0x85, 0x0c, 0xb9, 0x98, 0x18 }}

/**
 * A template builder, given an input source of data, a template, and a
 * reference point, generates a list of results from the input, and copies
 * part of the template for each result. Templates may generate content
 * recursively, using the same template, but with the previous iteration's
 * results as the reference point. As an example, for an XML datasource the
 * initial reference point would be a specific node in the DOM tree and a
 * template might generate a list of all child nodes. For the next iteration,
 * those children would be used to generate output for their child nodes and
 * so forth.
 *
 * A template builder is attached to a single DOM node; this node is called
 * the root node and is expected to contain a XUL template element as a direct
 * child. Different template builders may be specialized in the manner in
 * which they generate and display the resulting content from the template.
 *
 * The structure of a template is as follows:
 *
 * <rootnode datasources="" ref="">
 *   <template>
 *     <queryset>
 *       <query>
 *       </query>
 *       <rule>
 *         <conditions>...</conditions>
 *         <bindings>...</bindings>
 *         <action>...</action>
 *       </rule>
 *     </queryset>
 *   </template>
 * </rootnode>
 *
 * The datasources attribute on the root node is used to identify the source
 * of data to be used. The ref attribute is used to specify the reference
 * point for the query. Currently, the datasource will either be an
 * nsIRDFDataSource or a DOM node. In the future, other datasource types may
 * be used.
 *
 * The <queryset> element contains a single query and one or more <rule>
 * elements. There may be more than one <queryset> if multiple queries are
 * desired, and this element is optional if only one query is needed -- in
 * that case the <query> and <rule>s are allowed to be children of the
 * <template> node
 *
 * The contents of the query are processed by a separate component called a
 * query processor. This query processor is expected to use this query to
 * generate results when asked by the template builder. The template builder
 * then generates output for each result based on the <rule> elements.
 *
 * This allows the query processor to be specific to a particular kind of
 * input data or query syntax, while the template builder remains independent
 * of the kind of data being used. Due to this, the query processor will be
 * supplied with the datasource and query which the template builder handles
 * in an opaque way, while the query processor handles these more
 * specifically.
 *
 * Results implement the nsIXULTemplateResult interface and may be identified
 * by an id which must be unique within a given set of query results.
 *
 * Each query may be accompanied by one or more <rule> elements. These rules
 * are evaluated by the template builder for each result produced by the
 * query. A rule consists of conditions that cause a rule to be either
 * accepted or rejected. The condition syntax allows for common conditional
 * handling; additional filtering may be applied by adding a custom filter
 * to a rule with the builder's addRuleFilter method.
 *
 * If a result passes a rule's conditions, this is considered a match, and the
 * content within the rule's <action> body is inserted as a sibling of the
 * <template>, assuming the template builder creates real DOM content. Only
 * one rule will match a result. For a tree builder, for example, the content
 * within the action body is used to create the tree rows instead. A matching
 * result must have its ruleMatched method called. When a result no longer
 * matches, the result's hasBeenRemoved method must be called.
 *
 * Optionally, the rule may have a <bindings> section which may be used to
 * define additional variables to be used within an action body. Each of these
 * declared bindings must be supplied to the query processor via its
 * addBinding method. The bindings are evaluated after a rule has matched.
 *
 * Templates may generate content recursively, using the previous iteration's
 * results as reference point to invoke the same queries. Since the reference
 * point is different, different output will typically be generated.
 *
 * The reference point nsIXULTemplateResult object for the first iteration is
 * determined by calling the query processor's translateRef method using the
 * value of the root node's ref attribute. This object may be retrieved later
 * via the builder's rootResult property.
 *
 * For convenience, each reference point as well as all results implement the
 * nsIXULTemplateResult interface, allowing the result objects from each
 * iteration to be used directly as the reference points for the next
 * iteration.
 *
 * When using multiple queries, each may generate results with the same id.
 * More than one of these results may match one of the rules in their
 * respective queries, however only the result for the earliest matching query
 * in the template becomes the active match and generates output. The
 * addResult, removeResult, replaceResult and resultBindingChanged methods may
 * be called by the query processor to indicate that the set of valid results
 * has changed, such that a different query may match. If a different match
 * would become active, the content for the existing match is removed and the
 * content for the new match is generated. A query processor is not required
 * to provide any support for updating results after they have been generated.
 *
 * See http://wiki.mozilla.org/XUL:Templates_Plan for details about templates.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXULTemplateBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTEMPLATEBUILDER_IID)

  /**
     * The root node in the DOM to which this builder is attached.
     */
  /* readonly attribute nsIDOMElement root; */
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMElement * *aRoot) = 0;

  /**
     * The opaque datasource object that is used for the template. This object
     * is created by the getDataSource method of the query processor. May be
     * null if the datasource has not been loaded yet. Set this attribute to
     * use a different datasource and rebuild the template.
     *
     * For an RDF datasource, this will be the same as the database. For XML
     * this will be the nsIDOMNode for the datasource document or node for
     * an inline reference (such as #name). Other query processors may use
     * other types for the datasource.
     */
  /* attribute nsISupports datasource; */
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsISupports * *aDatasource) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDatasource(nsISupports * aDatasource) = 0;

  /**
     * The composite datasource that the template builder observes
     * and uses to create content. This is used only for RDF queries and is
     * maintained for backwards compatibility. It will be the same object as
     * the datasource property. For non-RDF queries, it will always be null.
     */
  /* readonly attribute nsIRDFCompositeDataSource database; */
  NS_SCRIPTABLE NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) = 0;

  /**
     * The virtual result representing the starting reference point,
     * determined by calling the query processor's translateRef method
     * with the root node's ref attribute as an argument.
     */
  /* readonly attribute nsIXULTemplateResult rootResult; */
  NS_SCRIPTABLE NS_IMETHOD GetRootResult(nsIXULTemplateResult * *aRootResult) = 0;

  /**
     * The query processor used to generate results.
     */
  /* [noscript] readonly attribute nsIXULTemplateQueryProcessor queryProcessor; */
  NS_IMETHOD GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor) = 0;

  /**
     * Force the template builder to rebuild its content. All existing content
     * will be removed first. The query processor's done() method will be
     * invoked during cleanup, followed by its initializeForBuilding method
     * when the content is to be regenerated.
     * 
     */
  /* void rebuild (); */
  NS_SCRIPTABLE NS_IMETHOD Rebuild(void) = 0;

  /**
     * Reload any of our RDF datasources that support nsIRDFRemoteDatasource. 
     *
     * @note This is a temporary hack so that remote-XUL authors can
     *       reload remote datasources. When RDF becomes remote-scriptable,
     *       this will no longer be necessary.
     */
  /* void refresh (); */
  NS_SCRIPTABLE NS_IMETHOD Refresh(void) = 0;

  /**
     * Inform the template builder that a new result is available. The builder
     * will add this result to the set of results. The query node that the
     * new result applies to must be specified using the aQueryNode parameter.
     *
     * The builder will apply the rules associated with the query to the new
     * result, unless a result with the same id from an earlier query
     * supersedes it, and the result's RuleMatched method will be called if it
     * matches.
     *
     * @param aResult the result to add
     * @param aQueryNode the query that the result applies to
     *
     * @throws NS_ERROR_NULL_POINTER if aResult or aQueryNode are null
     */
  /* void addResult (in nsIXULTemplateResult aResult, in nsIDOMNode aQueryNode); */
  NS_SCRIPTABLE NS_IMETHOD AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode) = 0;

  /**
     * Inform the template builder that a result no longer applies. The builder
     * will call the remove content generated for the result, if any. If a different
     * query would then match instead, it will become the active match. This
     * method will have no effect if the result isn't known to the builder.
     *
     * @param aResult the result to remove
     *
     * @throws NS_ERROR_NULL_POINTER if aResult is null
     */
  /* void removeResult (in nsIXULTemplateResult aResult); */
  NS_SCRIPTABLE NS_IMETHOD RemoveResult(nsIXULTemplateResult *aResult) = 0;

  /**
     * Inform the template builder that one result should be replaced with
     * another. Both the old result (aOldResult) and the new result
     * (aNewResult) must have the same id. The query node that the new result
     * applies to must be specified using the aQueryNode parameter.
     *
     * This method is expected to have the same effect as calling both
     * removeResult for the old result and addResult for the new result.
     *
     * @param aOldResult the old result
     * @param aNewResult the new result
     * @param aQueryNode the query that the new result applies to
     *
     * @throws NS_ERROR_NULL_POINTER if either argument is null, or
     *         NS_ERROR_INVALID_ARG if the ids don't match
     */
  /* void replaceResult (in nsIXULTemplateResult aOldResult, in nsIXULTemplateResult aNewResult, in nsIDOMNode aQueryNode); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode) = 0;

  /**
     * Inform the template builder that one or more of the optional bindings
     * for a result has changed. In this case, the rules are not reapplied as
     * it is expected that the same rule will still apply. The builder will
     * resynchronize any variables that are referenced in the action body.
     *
     * @param aResult the result to change
     *
     * @throws NS_ERROR_NULL_POINTER if aResult is null
     */
  /* void resultBindingChanged (in nsIXULTemplateResult aResult); */
  NS_SCRIPTABLE NS_IMETHOD ResultBindingChanged(nsIXULTemplateResult *aResult) = 0;

  /**
     * Return the result for a given id. Only one such result is returned and
     * is always the result with that id associated with the active match.
     * This method will return null is there is no result for the id.
     *
     * @param aId the id to return the result for
     */
  /* nsIXULTemplateResult getResultForId (in AString aId); */
  NS_SCRIPTABLE NS_IMETHOD GetResultForId(const nsAString & aId, nsIXULTemplateResult **_retval NS_OUTPARAM) = 0;

  /**
     * Retrieve the result corresponding to a generated element, or null is
     * there isn't one.
     *
     * @param aContent element to result the result of
     */
  /* nsIXULTemplateResult getResultForContent (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult **_retval NS_OUTPARAM) = 0;

  /**
     * Returns true if the node has content generated for it. This method is
     * intended to be called only by the RDF query processor. If aTag is set,
     * the content must have a tag name that matches aTag. aTag may be ignored
     * for builders that don't generate real DOM content.
     *
     * @param aNode node to check
     * @param aTag tag that must match
     */
  /* boolean hasGeneratedContent (in nsIRDFResource aNode, in nsIAtom aTag); */
  NS_SCRIPTABLE NS_IMETHOD HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Adds a rule filter for a given rule, which may be used for specialized
     * rule filtering. Any existing filter on the rule is removed. The default
     * conditions specified inside the <rule> tag are applied before the
     * rule filter is applied, meaning that the filter may be used to further
     * filter out results but not reaccept results that have already been
     * rejected.
     *
     * @param aRule the rule to apply the filter to
     * @param aFilter the filter to add
     */
  /* void addRuleFilter (in nsIDOMNode aRule, in nsIXULTemplateRuleFilter aFilter); */
  NS_SCRIPTABLE NS_IMETHOD AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter) = 0;

  /**
     * Called to initialize a XUL content builder on a particular root
     * element. This element presumably has a ``datasources''
     * attribute, which the builder will parse to set up the template
     * builder's datasources.
     */
  /* [noscript] void init (in nsIContent aElement); */
  NS_IMETHOD Init(nsIContent *aElement) = 0;

  /**
     * Invoked lazily by a XUL element that needs its child content built.
     * If aForceCreation is true, then the contents of an element will be
     * generated even if it is closed. If false, the element will only
     * generate its contents if it is open. This behaviour is used with menus.
     */
  /* [noscript] void createContents (in nsIContent aElement, in boolean aForceCreation); */
  NS_IMETHOD CreateContents(nsIContent *aElement, PRBool aForceCreation) = 0;

  /**
     * Add a listener to this template builder. The template builder
     * holds a strong reference to the listener.
     */
  /* void addListener (in nsIXULBuilderListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIXULBuilderListener *aListener) = 0;

  /**
     * Remove a listener from this template builder.
     */
  /* void removeListener (in nsIXULBuilderListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIXULBuilderListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTemplateBuilder, NS_IXULTEMPLATEBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTEMPLATEBUILDER \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMElement * *aRoot); \
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsISupports * *aDatasource); \
  NS_SCRIPTABLE NS_IMETHOD SetDatasource(nsISupports * aDatasource); \
  NS_SCRIPTABLE NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase); \
  NS_SCRIPTABLE NS_IMETHOD GetRootResult(nsIXULTemplateResult * *aRootResult); \
  NS_IMETHOD GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor); \
  NS_SCRIPTABLE NS_IMETHOD Rebuild(void); \
  NS_SCRIPTABLE NS_IMETHOD Refresh(void); \
  NS_SCRIPTABLE NS_IMETHOD AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode); \
  NS_SCRIPTABLE NS_IMETHOD RemoveResult(nsIXULTemplateResult *aResult); \
  NS_SCRIPTABLE NS_IMETHOD ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode); \
  NS_SCRIPTABLE NS_IMETHOD ResultBindingChanged(nsIXULTemplateResult *aResult); \
  NS_SCRIPTABLE NS_IMETHOD GetResultForId(const nsAString & aId, nsIXULTemplateResult **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter); \
  NS_IMETHOD Init(nsIContent *aElement); \
  NS_IMETHOD CreateContents(nsIContent *aElement, PRBool aForceCreation); \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIXULBuilderListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIXULBuilderListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTEMPLATEBUILDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMElement * *aRoot) { return _to GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsISupports * *aDatasource) { return _to GetDatasource(aDatasource); } \
  NS_SCRIPTABLE NS_IMETHOD SetDatasource(nsISupports * aDatasource) { return _to SetDatasource(aDatasource); } \
  NS_SCRIPTABLE NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) { return _to GetDatabase(aDatabase); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootResult(nsIXULTemplateResult * *aRootResult) { return _to GetRootResult(aRootResult); } \
  NS_IMETHOD GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor) { return _to GetQueryProcessor(aQueryProcessor); } \
  NS_SCRIPTABLE NS_IMETHOD Rebuild(void) { return _to Rebuild(); } \
  NS_SCRIPTABLE NS_IMETHOD Refresh(void) { return _to Refresh(); } \
  NS_SCRIPTABLE NS_IMETHOD AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode) { return _to AddResult(aResult, aQueryNode); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveResult(nsIXULTemplateResult *aResult) { return _to RemoveResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode) { return _to ReplaceResult(aOldResult, aNewResult, aQueryNode); } \
  NS_SCRIPTABLE NS_IMETHOD ResultBindingChanged(nsIXULTemplateResult *aResult) { return _to ResultBindingChanged(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetResultForId(const nsAString & aId, nsIXULTemplateResult **_retval NS_OUTPARAM) { return _to GetResultForId(aId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult **_retval NS_OUTPARAM) { return _to GetResultForContent(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, PRBool *_retval NS_OUTPARAM) { return _to HasGeneratedContent(aNode, aTag, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter) { return _to AddRuleFilter(aRule, aFilter); } \
  NS_IMETHOD Init(nsIContent *aElement) { return _to Init(aElement); } \
  NS_IMETHOD CreateContents(nsIContent *aElement, PRBool aForceCreation) { return _to CreateContents(aElement, aForceCreation); } \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIXULBuilderListener *aListener) { return _to AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIXULBuilderListener *aListener) { return _to RemoveListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTEMPLATEBUILDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMElement * *aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsISupports * *aDatasource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatasource(aDatasource); } \
  NS_SCRIPTABLE NS_IMETHOD SetDatasource(nsISupports * aDatasource) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDatasource(aDatasource); } \
  NS_SCRIPTABLE NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabase(aDatabase); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootResult(nsIXULTemplateResult * *aRootResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootResult(aRootResult); } \
  NS_IMETHOD GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueryProcessor(aQueryProcessor); } \
  NS_SCRIPTABLE NS_IMETHOD Rebuild(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Rebuild(); } \
  NS_SCRIPTABLE NS_IMETHOD Refresh(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Refresh(); } \
  NS_SCRIPTABLE NS_IMETHOD AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddResult(aResult, aQueryNode); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveResult(nsIXULTemplateResult *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceResult(aOldResult, aNewResult, aQueryNode); } \
  NS_SCRIPTABLE NS_IMETHOD ResultBindingChanged(nsIXULTemplateResult *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResultBindingChanged(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetResultForId(const nsAString & aId, nsIXULTemplateResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultForId(aId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultForContent(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasGeneratedContent(aNode, aTag, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddRuleFilter(aRule, aFilter); } \
  NS_IMETHOD Init(nsIContent *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aElement); } \
  NS_IMETHOD CreateContents(nsIContent *aElement, PRBool aForceCreation) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateContents(aElement, aForceCreation); } \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIXULBuilderListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIXULBuilderListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTemplateBuilder : public nsIXULTemplateBuilder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTEMPLATEBUILDER

  nsXULTemplateBuilder();

private:
  ~nsXULTemplateBuilder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTemplateBuilder, nsIXULTemplateBuilder)

nsXULTemplateBuilder::nsXULTemplateBuilder()
{
  /* member initializers and constructor code */
}

nsXULTemplateBuilder::~nsXULTemplateBuilder()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement root; */
NS_IMETHODIMP nsXULTemplateBuilder::GetRoot(nsIDOMElement * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports datasource; */
NS_IMETHODIMP nsXULTemplateBuilder::GetDatasource(nsISupports * *aDatasource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULTemplateBuilder::SetDatasource(nsISupports * aDatasource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRDFCompositeDataSource database; */
NS_IMETHODIMP nsXULTemplateBuilder::GetDatabase(nsIRDFCompositeDataSource * *aDatabase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXULTemplateResult rootResult; */
NS_IMETHODIMP nsXULTemplateBuilder::GetRootResult(nsIXULTemplateResult * *aRootResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIXULTemplateQueryProcessor queryProcessor; */
NS_IMETHODIMP nsXULTemplateBuilder::GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rebuild (); */
NS_IMETHODIMP nsXULTemplateBuilder::Rebuild()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refresh (); */
NS_IMETHODIMP nsXULTemplateBuilder::Refresh()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addResult (in nsIXULTemplateResult aResult, in nsIDOMNode aQueryNode); */
NS_IMETHODIMP nsXULTemplateBuilder::AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeResult (in nsIXULTemplateResult aResult); */
NS_IMETHODIMP nsXULTemplateBuilder::RemoveResult(nsIXULTemplateResult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceResult (in nsIXULTemplateResult aOldResult, in nsIXULTemplateResult aNewResult, in nsIDOMNode aQueryNode); */
NS_IMETHODIMP nsXULTemplateBuilder::ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resultBindingChanged (in nsIXULTemplateResult aResult); */
NS_IMETHODIMP nsXULTemplateBuilder::ResultBindingChanged(nsIXULTemplateResult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXULTemplateResult getResultForId (in AString aId); */
NS_IMETHODIMP nsXULTemplateBuilder::GetResultForId(const nsAString & aId, nsIXULTemplateResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXULTemplateResult getResultForContent (in nsIDOMElement aElement); */
NS_IMETHODIMP nsXULTemplateBuilder::GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasGeneratedContent (in nsIRDFResource aNode, in nsIAtom aTag); */
NS_IMETHODIMP nsXULTemplateBuilder::HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addRuleFilter (in nsIDOMNode aRule, in nsIXULTemplateRuleFilter aFilter); */
NS_IMETHODIMP nsXULTemplateBuilder::AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIContent aElement); */
NS_IMETHODIMP nsXULTemplateBuilder::Init(nsIContent *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void createContents (in nsIContent aElement, in boolean aForceCreation); */
NS_IMETHODIMP nsXULTemplateBuilder::CreateContents(nsIContent *aElement, PRBool aForceCreation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addListener (in nsIXULBuilderListener aListener); */
NS_IMETHODIMP nsXULTemplateBuilder::AddListener(nsIXULBuilderListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in nsIXULBuilderListener aListener); */
NS_IMETHODIMP nsXULTemplateBuilder::RemoveListener(nsIXULBuilderListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXULTreeBuilderObserver */
#define NS_IXULTREEBUILDEROBSERVER_IID_STR "a5480e0d-ac7c-42e5-aca5-d7f0bbffa207"

#define NS_IXULTREEBUILDEROBSERVER_IID \
  {0xa5480e0d, 0xac7c, 0x42e5, \
    { 0xac, 0xa5, 0xd7, 0xf0, 0xbb, 0xff, 0xa2, 0x07 }}

/**
 * nsIXULTreeBuilderObserver
 *  This interface allows clients of the XULTreeBuilder to define domain 
 *  specific handling of specific nsITreeView methods that 
 *  XULTreeBuilder does not implement.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXULTreeBuilderObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTREEBUILDEROBSERVER_IID)

  enum { DROP_BEFORE = -1 };

  enum { DROP_ON = 0 };

  enum { DROP_AFTER = 1 };

  /**
     * Methods used by the drag feedback code to determine if a drag is allowable at
     * the current location. To get the behavior where drops are only allowed on
     * items, such as the mailNews folder pane, always return false whe
     * the orientation is not DROP_ON.
     */
  /* boolean canDrop (in long index, in long orientation); */
  NS_SCRIPTABLE NS_IMETHOD CanDrop(PRInt32 index, PRInt32 orientation, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Called when the user drops something on this view. The |orientation| param
     * specifies before/on/after the given |row|.
     */
  /* void onDrop (in long row, in long orientation); */
  NS_SCRIPTABLE NS_IMETHOD OnDrop(PRInt32 row, PRInt32 orientation) = 0;

  /** 
     * Called when an item is opened or closed. 
     */
  /* void onToggleOpenState (in long index); */
  NS_SCRIPTABLE NS_IMETHOD OnToggleOpenState(PRInt32 index) = 0;

  /** 
	 * Called when a header is clicked.
     */
  /* void onCycleHeader (in wstring colID, in nsIDOMElement elt); */
  NS_SCRIPTABLE NS_IMETHOD OnCycleHeader(const PRUnichar *colID, nsIDOMElement *elt) = 0;

  /**
     * Called when a cell in a non-selectable cycling column (e.g. 
     * unread/flag/etc.) is clicked.
     */
  /* void onCycleCell (in long row, in wstring colID); */
  NS_SCRIPTABLE NS_IMETHOD OnCycleCell(PRInt32 row, const PRUnichar *colID) = 0;

  /** 
     * Called when selection in the tree changes
     */
  /* void onSelectionChanged (); */
  NS_SCRIPTABLE NS_IMETHOD OnSelectionChanged(void) = 0;

  /**
     * A command API that can be used to invoke commands on the selection.  
     * The tree will automatically invoke this method when certain keys 
     * are pressed.  For example, when the DEL key is pressed, performAction 
     * will be called with the "delete" string. 
     */
  /* void onPerformAction (in wstring action); */
  NS_SCRIPTABLE NS_IMETHOD OnPerformAction(const PRUnichar *action) = 0;

  /**
     * A command API that can be used to invoke commands on a specific row.
     */
  /* void onPerformActionOnRow (in wstring action, in long row); */
  NS_SCRIPTABLE NS_IMETHOD OnPerformActionOnRow(const PRUnichar *action, PRInt32 row) = 0;

  /**
     * A command API that can be used to invoke commands on a specific cell.
     */
  /* void onPerformActionOnCell (in wstring action, in long row, in wstring colID); */
  NS_SCRIPTABLE NS_IMETHOD OnPerformActionOnCell(const PRUnichar *action, PRInt32 row, const PRUnichar *colID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTreeBuilderObserver, NS_IXULTREEBUILDEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTREEBUILDEROBSERVER \
  NS_SCRIPTABLE NS_IMETHOD CanDrop(PRInt32 index, PRInt32 orientation, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OnDrop(PRInt32 row, PRInt32 orientation); \
  NS_SCRIPTABLE NS_IMETHOD OnToggleOpenState(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD OnCycleHeader(const PRUnichar *colID, nsIDOMElement *elt); \
  NS_SCRIPTABLE NS_IMETHOD OnCycleCell(PRInt32 row, const PRUnichar *colID); \
  NS_SCRIPTABLE NS_IMETHOD OnSelectionChanged(void); \
  NS_SCRIPTABLE NS_IMETHOD OnPerformAction(const PRUnichar *action); \
  NS_SCRIPTABLE NS_IMETHOD OnPerformActionOnRow(const PRUnichar *action, PRInt32 row); \
  NS_SCRIPTABLE NS_IMETHOD OnPerformActionOnCell(const PRUnichar *action, PRInt32 row, const PRUnichar *colID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTREEBUILDEROBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CanDrop(PRInt32 index, PRInt32 orientation, PRBool *_retval NS_OUTPARAM) { return _to CanDrop(index, orientation, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OnDrop(PRInt32 row, PRInt32 orientation) { return _to OnDrop(row, orientation); } \
  NS_SCRIPTABLE NS_IMETHOD OnToggleOpenState(PRInt32 index) { return _to OnToggleOpenState(index); } \
  NS_SCRIPTABLE NS_IMETHOD OnCycleHeader(const PRUnichar *colID, nsIDOMElement *elt) { return _to OnCycleHeader(colID, elt); } \
  NS_SCRIPTABLE NS_IMETHOD OnCycleCell(PRInt32 row, const PRUnichar *colID) { return _to OnCycleCell(row, colID); } \
  NS_SCRIPTABLE NS_IMETHOD OnSelectionChanged(void) { return _to OnSelectionChanged(); } \
  NS_SCRIPTABLE NS_IMETHOD OnPerformAction(const PRUnichar *action) { return _to OnPerformAction(action); } \
  NS_SCRIPTABLE NS_IMETHOD OnPerformActionOnRow(const PRUnichar *action, PRInt32 row) { return _to OnPerformActionOnRow(action, row); } \
  NS_SCRIPTABLE NS_IMETHOD OnPerformActionOnCell(const PRUnichar *action, PRInt32 row, const PRUnichar *colID) { return _to OnPerformActionOnCell(action, row, colID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTREEBUILDEROBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CanDrop(PRInt32 index, PRInt32 orientation, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanDrop(index, orientation, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OnDrop(PRInt32 row, PRInt32 orientation) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDrop(row, orientation); } \
  NS_SCRIPTABLE NS_IMETHOD OnToggleOpenState(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnToggleOpenState(index); } \
  NS_SCRIPTABLE NS_IMETHOD OnCycleHeader(const PRUnichar *colID, nsIDOMElement *elt) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCycleHeader(colID, elt); } \
  NS_SCRIPTABLE NS_IMETHOD OnCycleCell(PRInt32 row, const PRUnichar *colID) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCycleCell(row, colID); } \
  NS_SCRIPTABLE NS_IMETHOD OnSelectionChanged(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSelectionChanged(); } \
  NS_SCRIPTABLE NS_IMETHOD OnPerformAction(const PRUnichar *action) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPerformAction(action); } \
  NS_SCRIPTABLE NS_IMETHOD OnPerformActionOnRow(const PRUnichar *action, PRInt32 row) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPerformActionOnRow(action, row); } \
  NS_SCRIPTABLE NS_IMETHOD OnPerformActionOnCell(const PRUnichar *action, PRInt32 row, const PRUnichar *colID) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPerformActionOnCell(action, row, colID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTreeBuilderObserver : public nsIXULTreeBuilderObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTREEBUILDEROBSERVER

  nsXULTreeBuilderObserver();

private:
  ~nsXULTreeBuilderObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTreeBuilderObserver, nsIXULTreeBuilderObserver)

nsXULTreeBuilderObserver::nsXULTreeBuilderObserver()
{
  /* member initializers and constructor code */
}

nsXULTreeBuilderObserver::~nsXULTreeBuilderObserver()
{
  /* destructor code */
}

/* boolean canDrop (in long index, in long orientation); */
NS_IMETHODIMP nsXULTreeBuilderObserver::CanDrop(PRInt32 index, PRInt32 orientation, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDrop (in long row, in long orientation); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnDrop(PRInt32 row, PRInt32 orientation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onToggleOpenState (in long index); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnToggleOpenState(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCycleHeader (in wstring colID, in nsIDOMElement elt); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnCycleHeader(const PRUnichar *colID, nsIDOMElement *elt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCycleCell (in long row, in wstring colID); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnCycleCell(PRInt32 row, const PRUnichar *colID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSelectionChanged (); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnSelectionChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPerformAction (in wstring action); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnPerformAction(const PRUnichar *action)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPerformActionOnRow (in wstring action, in long row); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnPerformActionOnRow(const PRUnichar *action, PRInt32 row)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPerformActionOnCell (in wstring action, in long row, in wstring colID); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnPerformActionOnCell(const PRUnichar *action, PRInt32 row, const PRUnichar *colID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXULTreeBuilder */
#define NS_IXULTREEBUILDER_IID_STR "06b31b15-ebf5-4e74-a0e2-6bc0a18a3969"

#define NS_IXULTREEBUILDER_IID \
  {0x06b31b15, 0xebf5, 0x4e74, \
    { 0xa0, 0xe2, 0x6b, 0xc0, 0xa1, 0x8a, 0x39, 0x69 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXULTreeBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTREEBUILDER_IID)

  /**
     * Retrieve the RDF resource associated with the specified row.
     */
  /* nsIRDFResource getResourceAtIndex (in long aRowIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetResourceAtIndex(PRInt32 aRowIndex, nsIRDFResource **_retval NS_OUTPARAM) = 0;

  /**
     * Retrieve the index associated with specified RDF resource.
     */
  /* long getIndexOfResource (in nsIRDFResource resource); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfResource(nsIRDFResource *resource, PRInt32 *_retval NS_OUTPARAM) = 0;

  /** 
     * Add a Tree Builder Observer to handle Tree View 
     * methods that the base builder does not implement. 
     */
  /* void addObserver (in nsIXULTreeBuilderObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIXULTreeBuilderObserver *aObserver) = 0;

  /** 
     * Remove an Tree Builder Observer.
     */
  /* void removeObserver (in nsIXULTreeBuilderObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIXULTreeBuilderObserver *aObserver) = 0;

  /** 
     * Sort the contents of the tree using the specified column.
     */
  /* void sort (in nsIDOMElement aColumnElement); */
  NS_SCRIPTABLE NS_IMETHOD Sort(nsIDOMElement *aColumnElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTreeBuilder, NS_IXULTREEBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTREEBUILDER \
  NS_SCRIPTABLE NS_IMETHOD GetResourceAtIndex(PRInt32 aRowIndex, nsIRDFResource **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfResource(nsIRDFResource *resource, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIXULTreeBuilderObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIXULTreeBuilderObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD Sort(nsIDOMElement *aColumnElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTREEBUILDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResourceAtIndex(PRInt32 aRowIndex, nsIRDFResource **_retval NS_OUTPARAM) { return _to GetResourceAtIndex(aRowIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfResource(nsIRDFResource *resource, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexOfResource(resource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIXULTreeBuilderObserver *aObserver) { return _to AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIXULTreeBuilderObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD Sort(nsIDOMElement *aColumnElement) { return _to Sort(aColumnElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTREEBUILDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResourceAtIndex(PRInt32 aRowIndex, nsIRDFResource **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResourceAtIndex(aRowIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfResource(nsIRDFResource *resource, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfResource(resource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIXULTreeBuilderObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIXULTreeBuilderObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD Sort(nsIDOMElement *aColumnElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->Sort(aColumnElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTreeBuilder : public nsIXULTreeBuilder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTREEBUILDER

  nsXULTreeBuilder();

private:
  ~nsXULTreeBuilder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTreeBuilder, nsIXULTreeBuilder)

nsXULTreeBuilder::nsXULTreeBuilder()
{
  /* member initializers and constructor code */
}

nsXULTreeBuilder::~nsXULTreeBuilder()
{
  /* destructor code */
}

/* nsIRDFResource getResourceAtIndex (in long aRowIndex); */
NS_IMETHODIMP nsXULTreeBuilder::GetResourceAtIndex(PRInt32 aRowIndex, nsIRDFResource **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfResource (in nsIRDFResource resource); */
NS_IMETHODIMP nsXULTreeBuilder::GetIndexOfResource(nsIRDFResource *resource, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsIXULTreeBuilderObserver aObserver); */
NS_IMETHODIMP nsXULTreeBuilder::AddObserver(nsIXULTreeBuilderObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIXULTreeBuilderObserver aObserver); */
NS_IMETHODIMP nsXULTreeBuilder::RemoveObserver(nsIXULTreeBuilderObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sort (in nsIDOMElement aColumnElement); */
NS_IMETHODIMP nsXULTreeBuilder::Sort(nsIDOMElement *aColumnElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULTemplateBuilder_h__ */
