/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/search/nsIBrowserSearchService.idl
 */

#ifndef __gen_nsIBrowserSearchService_h__
#define __gen_nsIBrowserSearchService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */


/* starting interface:    nsISearchSubmission */
#define NS_ISEARCHSUBMISSION_IID_STR "58e4f602-a7c8-4cd1-9dca-716705e826ef"

#define NS_ISEARCHSUBMISSION_IID \
  {0x58e4f602, 0xa7c8, 0x4cd1, \
    { 0x9d, 0xca, 0x71, 0x67, 0x05, 0xe8, 0x26, 0xef }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISearchSubmission : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEARCHSUBMISSION_IID)

  /**
   * The POST data associated with a search submission, wrapped in a MIME
   * input stream. May be null.
   */
  /* readonly attribute nsIInputStream postData; */
  NS_SCRIPTABLE NS_IMETHOD GetPostData(nsIInputStream * *aPostData) = 0;

  /**
   * The URI to submit a search to.
   */
  /* readonly attribute nsIURI uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISearchSubmission, NS_ISEARCHSUBMISSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEARCHSUBMISSION \
  NS_SCRIPTABLE NS_IMETHOD GetPostData(nsIInputStream * *aPostData); \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEARCHSUBMISSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPostData(nsIInputStream * *aPostData) { return _to GetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEARCHSUBMISSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPostData(nsIInputStream * *aPostData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSearchSubmission : public nsISearchSubmission
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEARCHSUBMISSION

  nsSearchSubmission();

private:
  ~nsSearchSubmission();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSearchSubmission, nsISearchSubmission)

nsSearchSubmission::nsSearchSubmission()
{
  /* member initializers and constructor code */
}

nsSearchSubmission::~nsSearchSubmission()
{
  /* destructor code */
}

/* readonly attribute nsIInputStream postData; */
NS_IMETHODIMP nsSearchSubmission::GetPostData(nsIInputStream * *aPostData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI uri; */
NS_IMETHODIMP nsSearchSubmission::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISearchEngine */
#define NS_ISEARCHENGINE_IID_STR "803e510b-4b27-4ba2-a16d-bb5fa953c166"

#define NS_ISEARCHENGINE_IID \
  {0x803e510b, 0x4b27, 0x4ba2, \
    { 0xa1, 0x6d, 0xbb, 0x5f, 0xa9, 0x53, 0xc1, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISearchEngine : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEARCHENGINE_IID)

  /**
   * Gets a nsISearchSubmission object that contains information about what to
   * send to the search engine, including the URI and postData, if applicable.
   *
   * @param  data
   *         Data to add to the submission object.
   *         i.e. the search terms.
   *
   * @param  responseType
   *         The MIME type that we'd like to receive in response
   *         to this submission.  If null, will default to "text/html".
   *
   * @returns A nsISearchSubmission object that contains information about what
   *          to send to the search engine.  If no submission can be
   *          obtained for the given responseType, returns null.
   */
  /* nsISearchSubmission getSubmission (in AString data, in AString responseType); */
  NS_SCRIPTABLE NS_IMETHOD GetSubmission(const nsAString & data, const nsAString & responseType, nsISearchSubmission **_retval NS_OUTPARAM) = 0;

  /**
   * Adds a parameter to the search engine's submission data. This should only
   * be called on engines created via addEngineWithDetails.
   *
   * @param name
   *        The parameter's name. Must not be null.
   *
   * @param value
   *        The value to pass. If value is "{searchTerms}", it will be
   *        substituted with the user-entered data when retrieving the
   *        submission. Must not be null.
   *
   * @param responseType
   *        Since an engine can have several different request URLs,
   *        differentiated by response types, this parameter selects
   *        a request to add parameters to.  If null, will default
   *        to "text/html"
   *
   * @throws NS_ERROR_FAILURE if the search engine is read-only.
   * @throws NS_ERROR_INVALID_ARG if name or value are null.
   */
  /* void addParam (in AString name, in AString value, in AString responseType); */
  NS_SCRIPTABLE NS_IMETHOD AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType) = 0;

  /**
   * Determines whether the engine can return responses in the given
   * MIME type.  Returns true if the engine spec has a URL with the
   * given responseType, false otherwise.
   *
   * @param responseType
   *        The MIME type to check for
   */
  /* boolean supportsResponseType (in AString responseType); */
  NS_SCRIPTABLE NS_IMETHOD SupportsResponseType(const nsAString & responseType, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Supported search engine types.
   */
  enum { TYPE_MOZSEARCH = 1U };

  enum { TYPE_SHERLOCK = 2U };

  enum { TYPE_OPENSEARCH = 3U };

  /**
   * Supported search engine data types.
   */
  enum { DATA_XML = 1U };

  enum { DATA_TEXT = 2U };

  /**
   * The shortcut alias of the engine. This is a unique identifier.
   */
  /* attribute AString alias; */
  NS_SCRIPTABLE NS_IMETHOD GetAlias(nsAString & aAlias) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAlias(const nsAString & aAlias) = 0;

  /**
   * A text description describing the engine.
   */
  /* readonly attribute AString description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) = 0;

  /**
   * Whether the engine should be hidden from the user.
   */
  /* attribute boolean hidden; */
  NS_SCRIPTABLE NS_IMETHOD GetHidden(PRBool *aHidden) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHidden(PRBool aHidden) = 0;

  /**
   * A nsIURI corresponding to the engine's icon, stored locally. May be null.
   */
  /* readonly attribute nsIURI iconURI; */
  NS_SCRIPTABLE NS_IMETHOD GetIconURI(nsIURI * *aIconURI) = 0;

  /**
   * The display name of the search engine. This is a unique identifier.
   */
  /* readonly attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /**
   * A URL string pointing to the engine's search form.
   */
  /* readonly attribute AString searchForm; */
  NS_SCRIPTABLE NS_IMETHOD GetSearchForm(nsAString & aSearchForm) = 0;

  /**
   * The search engine type.
   */
  /* readonly attribute long type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt32 *aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISearchEngine, NS_ISEARCHENGINE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEARCHENGINE \
  NS_SCRIPTABLE NS_IMETHOD GetSubmission(const nsAString & data, const nsAString & responseType, nsISearchSubmission **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType); \
  NS_SCRIPTABLE NS_IMETHOD SupportsResponseType(const nsAString & responseType, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAlias(nsAString & aAlias); \
  NS_SCRIPTABLE NS_IMETHOD SetAlias(const nsAString & aAlias); \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetHidden(PRBool *aHidden); \
  NS_SCRIPTABLE NS_IMETHOD SetHidden(PRBool aHidden); \
  NS_SCRIPTABLE NS_IMETHOD GetIconURI(nsIURI * *aIconURI); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetSearchForm(nsAString & aSearchForm); \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt32 *aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEARCHENGINE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSubmission(const nsAString & data, const nsAString & responseType, nsISearchSubmission **_retval NS_OUTPARAM) { return _to GetSubmission(data, responseType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType) { return _to AddParam(name, value, responseType); } \
  NS_SCRIPTABLE NS_IMETHOD SupportsResponseType(const nsAString & responseType, PRBool *_retval NS_OUTPARAM) { return _to SupportsResponseType(responseType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlias(nsAString & aAlias) { return _to GetAlias(aAlias); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlias(const nsAString & aAlias) { return _to SetAlias(aAlias); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetHidden(PRBool *aHidden) { return _to GetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD SetHidden(PRBool aHidden) { return _to SetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconURI(nsIURI * *aIconURI) { return _to GetIconURI(aIconURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchForm(nsAString & aSearchForm) { return _to GetSearchForm(aSearchForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt32 *aType) { return _to GetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEARCHENGINE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSubmission(const nsAString & data, const nsAString & responseType, nsISearchSubmission **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubmission(data, responseType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddParam(name, value, responseType); } \
  NS_SCRIPTABLE NS_IMETHOD SupportsResponseType(const nsAString & responseType, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SupportsResponseType(responseType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlias(nsAString & aAlias) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlias(aAlias); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlias(const nsAString & aAlias) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlias(aAlias); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetHidden(PRBool *aHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD SetHidden(PRBool aHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconURI(nsIURI * *aIconURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconURI(aIconURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchForm(nsAString & aSearchForm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchForm(aSearchForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt32 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSearchEngine : public nsISearchEngine
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEARCHENGINE

  nsSearchEngine();

private:
  ~nsSearchEngine();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSearchEngine, nsISearchEngine)

nsSearchEngine::nsSearchEngine()
{
  /* member initializers and constructor code */
}

nsSearchEngine::~nsSearchEngine()
{
  /* destructor code */
}

/* nsISearchSubmission getSubmission (in AString data, in AString responseType); */
NS_IMETHODIMP nsSearchEngine::GetSubmission(const nsAString & data, const nsAString & responseType, nsISearchSubmission **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addParam (in AString name, in AString value, in AString responseType); */
NS_IMETHODIMP nsSearchEngine::AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean supportsResponseType (in AString responseType); */
NS_IMETHODIMP nsSearchEngine::SupportsResponseType(const nsAString & responseType, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString alias; */
NS_IMETHODIMP nsSearchEngine::GetAlias(nsAString & aAlias)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchEngine::SetAlias(const nsAString & aAlias)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString description; */
NS_IMETHODIMP nsSearchEngine::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hidden; */
NS_IMETHODIMP nsSearchEngine::GetHidden(PRBool *aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchEngine::SetHidden(PRBool aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI iconURI; */
NS_IMETHODIMP nsSearchEngine::GetIconURI(nsIURI * *aIconURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsSearchEngine::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString searchForm; */
NS_IMETHODIMP nsSearchEngine::GetSearchForm(nsAString & aSearchForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long type; */
NS_IMETHODIMP nsSearchEngine::GetType(PRInt32 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBrowserSearchService */
#define NS_IBROWSERSEARCHSERVICE_IID_STR "8307b8f2-08ea-45b8-96bf-b1dc7688fe3b"

#define NS_IBROWSERSEARCHSERVICE_IID \
  {0x8307b8f2, 0x08ea, 0x45b8, \
    { 0x96, 0xbf, 0xb1, 0xdc, 0x76, 0x88, 0xfe, 0x3b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIBrowserSearchService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERSEARCHSERVICE_IID)

  /**
   * Adds a new search engine from the file at the supplied URI, optionally
   * asking the user for confirmation first.  If a confirmation dialog is
   * shown, it will offer the option to begin using the newly added engine
   * right away; if no confirmation dialog is shown, the new engine will be
   * used right away automatically.
   *
   * @param engineURL
   *        The URL to the search engine's description file.
   *
   * @param dataType
   *        An integer representing the plugin file format. Must be one
   *        of the supported search engine data types defined above.
   *
   * @param iconURL
   *        A URL string to an icon file to be used as the search engine's
   *        icon. This value may be overridden by an icon specified in the
   *        engine description file.
   *
   * @param confirm
   *        A boolean value indicating whether the user should be asked for
   *        confirmation before this engine is added to the list.  If this
   *        value is false, the engine will be added to the list upon successful
   *        load, but it will not be selected as the current engine.
   *
   * @throws NS_ERROR_FAILURE if the type is invalid, or if the description
   *         file cannot be successfully loaded.
   */
  /* void addEngine (in AString engineURL, in long dataType, in AString iconURL, in boolean confirm); */
  NS_SCRIPTABLE NS_IMETHOD AddEngine(const nsAString & engineURL, PRInt32 dataType, const nsAString & iconURL, PRBool confirm) = 0;

  /**
   * Adds a new search engine, without asking the user for confirmation and
   * without starting to use it right away.
   *
   * @param name
   *        The search engine's name. Must be unique. Must not be null.
   *
   * @param iconURL
   *        Optional: A URL string pointing to the icon to be used to represent
   *        the engine.
   *
   * @param alias
   *        Optional: A unique shortcut that can be used to retrieve the
   *        search engine.
   *
   * @param description
   *        Optional: a description of the search engine.
   *
   * @param method
   *        The HTTP request method used when submitting a search query.
   *        Must be a case insensitive value of either "get" or "post".
   *
   * @param url
   *        The URL to which search queries should be sent.
   *        Must not be null.
   */
  /* void addEngineWithDetails (in AString name, in AString iconURL, in AString alias, in AString description, in AString method, in AString url); */
  NS_SCRIPTABLE NS_IMETHOD AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url) = 0;

  /**
   * Un-hides all engines installed in the directory corresponding to
   * the directory service's NS_APP_SEARCH_DIR key. (i.e. the set of
   * engines returned by getDefaultEngines)
   */
  /* void restoreDefaultEngines (); */
  NS_SCRIPTABLE NS_IMETHOD RestoreDefaultEngines(void) = 0;

  /**
   * Returns an engine with the specified alias.
   *
   * @param   alias
   *          The search engine's alias.
   * @returns The corresponding nsISearchEngine object, or null if it doesn't
   *          exist.
   */
  /* nsISearchEngine getEngineByAlias (in AString alias); */
  NS_SCRIPTABLE NS_IMETHOD GetEngineByAlias(const nsAString & alias, nsISearchEngine **_retval NS_OUTPARAM) = 0;

  /**
   * Returns an engine with the specified name.
   *
   * @param   aEngineName
   *          The name of the engine.
   * @returns The corresponding nsISearchEngine object, or null if it doesn't
   *          exist.
   */
  /* nsISearchEngine getEngineByName (in AString aEngineName); */
  NS_SCRIPTABLE NS_IMETHOD GetEngineByName(const nsAString & aEngineName, nsISearchEngine **_retval NS_OUTPARAM) = 0;

  /**
   * Returns an array of all installed search engines.
   *
   * @returns an array of nsISearchEngine objects.
   */
  /* void getEngines (out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
  NS_SCRIPTABLE NS_IMETHOD GetEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM) = 0;

  /**
   * Returns an array of all installed search engines whose hidden attribute is
   * false.
   *
   * @returns an array of nsISearchEngine objects.
   */
  /* void getVisibleEngines (out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
  NS_SCRIPTABLE NS_IMETHOD GetVisibleEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM) = 0;

  /**
   * Returns an array of all default search engines. This includes all loaded
   * engines that aren't in the user's profile directory
   * (NS_APP_USER_SEARCH_DIR).
   *
   * @returns an array of nsISearchEngine objects.
   */
  /* void getDefaultEngines (out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM) = 0;

  /**
   * Moves a visible search engine.
   *
   * @param  engine
   *         The engine to move.
   * @param  newIndex
   *         The engine's new index in the set of visible engines.
   *
   * @throws NS_ERROR_FAILURE if newIndex is out of bounds, or if engine is
   *         hidden.
   */
  /* void moveEngine (in nsISearchEngine engine, in long newIndex); */
  NS_SCRIPTABLE NS_IMETHOD MoveEngine(nsISearchEngine *engine, PRInt32 newIndex) = 0;

  /**
   * Removes the search engine. If the search engine is installed in a global
   * location, this will just hide the engine. If the engine is in the user's
   * profile directory, it will be removed from disk.
   *
   * @param  engine
   *         The engine to remove.
   */
  /* void removeEngine (in nsISearchEngine engine); */
  NS_SCRIPTABLE NS_IMETHOD RemoveEngine(nsISearchEngine *engine) = 0;

  /**
   * The default search engine. May be null if there are no visible
   * search engines installed.
   */
  /* readonly attribute nsISearchEngine defaultEngine; */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultEngine(nsISearchEngine * *aDefaultEngine) = 0;

  /**
   * The currently active search engine. May be null if there are no visible
   * search engines installed.
   */
  /* attribute nsISearchEngine currentEngine; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentEngine(nsISearchEngine * *aCurrentEngine) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCurrentEngine(nsISearchEngine * aCurrentEngine) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserSearchService, NS_IBROWSERSEARCHSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERSEARCHSERVICE \
  NS_SCRIPTABLE NS_IMETHOD AddEngine(const nsAString & engineURL, PRInt32 dataType, const nsAString & iconURL, PRBool confirm); \
  NS_SCRIPTABLE NS_IMETHOD AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url); \
  NS_SCRIPTABLE NS_IMETHOD RestoreDefaultEngines(void); \
  NS_SCRIPTABLE NS_IMETHOD GetEngineByAlias(const nsAString & alias, nsISearchEngine **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEngineByName(const nsAString & aEngineName, nsISearchEngine **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetVisibleEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MoveEngine(nsISearchEngine *engine, PRInt32 newIndex); \
  NS_SCRIPTABLE NS_IMETHOD RemoveEngine(nsISearchEngine *engine); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultEngine(nsISearchEngine * *aDefaultEngine); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentEngine(nsISearchEngine * *aCurrentEngine); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentEngine(nsISearchEngine * aCurrentEngine); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERSEARCHSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddEngine(const nsAString & engineURL, PRInt32 dataType, const nsAString & iconURL, PRBool confirm) { return _to AddEngine(engineURL, dataType, iconURL, confirm); } \
  NS_SCRIPTABLE NS_IMETHOD AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url) { return _to AddEngineWithDetails(name, iconURL, alias, description, method, url); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreDefaultEngines(void) { return _to RestoreDefaultEngines(); } \
  NS_SCRIPTABLE NS_IMETHOD GetEngineByAlias(const nsAString & alias, nsISearchEngine **_retval NS_OUTPARAM) { return _to GetEngineByAlias(alias, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEngineByName(const nsAString & aEngineName, nsISearchEngine **_retval NS_OUTPARAM) { return _to GetEngineByName(aEngineName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM) { return _to GetEngines(engineCount, engines); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisibleEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM) { return _to GetVisibleEngines(engineCount, engines); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM) { return _to GetDefaultEngines(engineCount, engines); } \
  NS_SCRIPTABLE NS_IMETHOD MoveEngine(nsISearchEngine *engine, PRInt32 newIndex) { return _to MoveEngine(engine, newIndex); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEngine(nsISearchEngine *engine) { return _to RemoveEngine(engine); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultEngine(nsISearchEngine * *aDefaultEngine) { return _to GetDefaultEngine(aDefaultEngine); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentEngine(nsISearchEngine * *aCurrentEngine) { return _to GetCurrentEngine(aCurrentEngine); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentEngine(nsISearchEngine * aCurrentEngine) { return _to SetCurrentEngine(aCurrentEngine); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERSEARCHSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddEngine(const nsAString & engineURL, PRInt32 dataType, const nsAString & iconURL, PRBool confirm) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEngine(engineURL, dataType, iconURL, confirm); } \
  NS_SCRIPTABLE NS_IMETHOD AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEngineWithDetails(name, iconURL, alias, description, method, url); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreDefaultEngines(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreDefaultEngines(); } \
  NS_SCRIPTABLE NS_IMETHOD GetEngineByAlias(const nsAString & alias, nsISearchEngine **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEngineByAlias(alias, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEngineByName(const nsAString & aEngineName, nsISearchEngine **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEngineByName(aEngineName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEngines(engineCount, engines); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisibleEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisibleEngines(engineCount, engines); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultEngines(engineCount, engines); } \
  NS_SCRIPTABLE NS_IMETHOD MoveEngine(nsISearchEngine *engine, PRInt32 newIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveEngine(engine, newIndex); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEngine(nsISearchEngine *engine) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEngine(engine); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultEngine(nsISearchEngine * *aDefaultEngine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultEngine(aDefaultEngine); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentEngine(nsISearchEngine * *aCurrentEngine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentEngine(aCurrentEngine); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentEngine(nsISearchEngine * aCurrentEngine) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentEngine(aCurrentEngine); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserSearchService : public nsIBrowserSearchService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERSEARCHSERVICE

  nsBrowserSearchService();

private:
  ~nsBrowserSearchService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserSearchService, nsIBrowserSearchService)

nsBrowserSearchService::nsBrowserSearchService()
{
  /* member initializers and constructor code */
}

nsBrowserSearchService::~nsBrowserSearchService()
{
  /* destructor code */
}

/* void addEngine (in AString engineURL, in long dataType, in AString iconURL, in boolean confirm); */
NS_IMETHODIMP nsBrowserSearchService::AddEngine(const nsAString & engineURL, PRInt32 dataType, const nsAString & iconURL, PRBool confirm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEngineWithDetails (in AString name, in AString iconURL, in AString alias, in AString description, in AString method, in AString url); */
NS_IMETHODIMP nsBrowserSearchService::AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreDefaultEngines (); */
NS_IMETHODIMP nsBrowserSearchService::RestoreDefaultEngines()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISearchEngine getEngineByAlias (in AString alias); */
NS_IMETHODIMP nsBrowserSearchService::GetEngineByAlias(const nsAString & alias, nsISearchEngine **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISearchEngine getEngineByName (in AString aEngineName); */
NS_IMETHODIMP nsBrowserSearchService::GetEngineByName(const nsAString & aEngineName, nsISearchEngine **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getEngines (out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
NS_IMETHODIMP nsBrowserSearchService::GetEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getVisibleEngines (out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
NS_IMETHODIMP nsBrowserSearchService::GetVisibleEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDefaultEngines (out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
NS_IMETHODIMP nsBrowserSearchService::GetDefaultEngines(PRUint32 *engineCount NS_OUTPARAM, nsISearchEngine ***engines NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveEngine (in nsISearchEngine engine, in long newIndex); */
NS_IMETHODIMP nsBrowserSearchService::MoveEngine(nsISearchEngine *engine, PRInt32 newIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEngine (in nsISearchEngine engine); */
NS_IMETHODIMP nsBrowserSearchService::RemoveEngine(nsISearchEngine *engine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISearchEngine defaultEngine; */
NS_IMETHODIMP nsBrowserSearchService::GetDefaultEngine(nsISearchEngine * *aDefaultEngine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISearchEngine currentEngine; */
NS_IMETHODIMP nsBrowserSearchService::GetCurrentEngine(nsISearchEngine * *aCurrentEngine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBrowserSearchService::SetCurrentEngine(nsISearchEngine * aCurrentEngine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * The observer topic to listen to for actions performed on installed
 * search engines.
 */
#define SEARCH_ENGINE_TOPIC "browser-search-engine-modified"
/**
 * Sent when an engine is removed from the data store.
 */
#define SEARCH_ENGINE_REMOVED      "engine-removed"
/**
 * Sent when an engine is changed. This includes when the engine's "hidden"
 * property is changed.
 */
#define SEARCH_ENGINE_CHANGED      "engine-changed"
/**
 * Sent when an engine is added to the list of available engines.
 */
#define SEARCH_ENGINE_ADDED        "engine-added"
/**
 * Sent when a search engine being installed from a remote plugin description
 * file is completely loaded. This is used internally by the search service as
 * an indication of when the engine can be added to the internal store, and
 * therefore should not be used to detect engine availability. It is always
 * followed by an "added" notification.
 */
#define SEARCH_ENGINE_LOADED       "engine-loaded"
/**
 * Sent when the "current" engine is changed.
 */
#define SEARCH_ENGINE_CURRENT      "engine-current";

#endif /* __gen_nsIBrowserSearchService_h__ */
