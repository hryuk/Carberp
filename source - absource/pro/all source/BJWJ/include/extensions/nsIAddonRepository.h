/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/mozapps/extensions/public/nsIAddonRepository.idl
 */

#ifndef __gen_nsIAddonRepository_h__
#define __gen_nsIAddonRepository_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAddonSearchResult */
#define NS_IADDONSEARCHRESULT_IID_STR "a549a714-2ada-4bb9-8a47-be26e73d49a5"

#define NS_IADDONSEARCHRESULT_IID \
  {0xa549a714, 0x2ada, 0x4bb9, \
    { 0x8a, 0x47, 0xbe, 0x26, 0xe7, 0x3d, 0x49, 0xa5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAddonSearchResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IADDONSEARCHRESULT_IID)

  /**
   * The ID of the add-on
   */
  /* readonly attribute AString id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) = 0;

  /**
   * The name of the add-on
   */
  /* readonly attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /**
   * The version of the add-on
   */
  /* readonly attribute AString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /**
   * A short summary of the add-on
   */
  /* readonly attribute AString summary; */
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary) = 0;

  /**
   * The full description of the add-on
   */
  /* readonly attribute AString description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) = 0;

  /**
   * The rating of the add-on, 0-5 or -1 if unrated.
   */
  /* readonly attribute long rating; */
  NS_SCRIPTABLE NS_IMETHOD GetRating(PRInt32 *aRating) = 0;

  /**
   * The url of the add-ons icon or empty if there is no icon.
   */
  /* readonly attribute AString iconURL; */
  NS_SCRIPTABLE NS_IMETHOD GetIconURL(nsAString & aIconURL) = 0;

  /**
   * The url of a thumbnail for the add-on
   */
  /* readonly attribute AString thumbnailURL; */
  NS_SCRIPTABLE NS_IMETHOD GetThumbnailURL(nsAString & aThumbnailURL) = 0;

  /**
   * The homepage for the add-on
   */
  /* readonly attribute AString homepageURL; */
  NS_SCRIPTABLE NS_IMETHOD GetHomepageURL(nsAString & aHomepageURL) = 0;

  /**
   * A EULA that must be accepted before install.
   */
  /* readonly attribute AString eula; */
  NS_SCRIPTABLE NS_IMETHOD GetEula(nsAString & aEula) = 0;

  /**
   * The add-on type (see nsIUpdateItem).
   */
  /* readonly attribute unsigned long type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) = 0;

  /**
   * The url of the xpi for this add-on
   */
  /* readonly attribute AString xpiURL; */
  NS_SCRIPTABLE NS_IMETHOD GetXpiURL(nsAString & aXpiURL) = 0;

  /**
   * The hash for the xpi.
   */
  /* readonly attribute AString xpiHash; */
  NS_SCRIPTABLE NS_IMETHOD GetXpiHash(nsAString & aXpiHash) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAddonSearchResult, NS_IADDONSEARCHRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIADDONSEARCHRESULT \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary); \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetRating(PRInt32 *aRating); \
  NS_SCRIPTABLE NS_IMETHOD GetIconURL(nsAString & aIconURL); \
  NS_SCRIPTABLE NS_IMETHOD GetThumbnailURL(nsAString & aThumbnailURL); \
  NS_SCRIPTABLE NS_IMETHOD GetHomepageURL(nsAString & aHomepageURL); \
  NS_SCRIPTABLE NS_IMETHOD GetEula(nsAString & aEula); \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetXpiURL(nsAString & aXpiURL); \
  NS_SCRIPTABLE NS_IMETHOD GetXpiHash(nsAString & aXpiHash); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIADDONSEARCHRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary) { return _to GetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetRating(PRInt32 *aRating) { return _to GetRating(aRating); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconURL(nsAString & aIconURL) { return _to GetIconURL(aIconURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetThumbnailURL(nsAString & aThumbnailURL) { return _to GetThumbnailURL(aThumbnailURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetHomepageURL(nsAString & aHomepageURL) { return _to GetHomepageURL(aHomepageURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetEula(nsAString & aEula) { return _to GetEula(aEula); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetXpiURL(nsAString & aXpiURL) { return _to GetXpiURL(aXpiURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetXpiHash(nsAString & aXpiHash) { return _to GetXpiHash(aXpiHash); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIADDONSEARCHRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetRating(PRInt32 *aRating) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRating(aRating); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconURL(nsAString & aIconURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconURL(aIconURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetThumbnailURL(nsAString & aThumbnailURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThumbnailURL(aThumbnailURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetHomepageURL(nsAString & aHomepageURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHomepageURL(aHomepageURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetEula(nsAString & aEula) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEula(aEula); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetXpiURL(nsAString & aXpiURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXpiURL(aXpiURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetXpiHash(nsAString & aXpiHash) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXpiHash(aXpiHash); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAddonSearchResult : public nsIAddonSearchResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIADDONSEARCHRESULT

  nsAddonSearchResult();

private:
  ~nsAddonSearchResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAddonSearchResult, nsIAddonSearchResult)

nsAddonSearchResult::nsAddonSearchResult()
{
  /* member initializers and constructor code */
}

nsAddonSearchResult::~nsAddonSearchResult()
{
  /* destructor code */
}

/* readonly attribute AString id; */
NS_IMETHODIMP nsAddonSearchResult::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsAddonSearchResult::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString version; */
NS_IMETHODIMP nsAddonSearchResult::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString summary; */
NS_IMETHODIMP nsAddonSearchResult::GetSummary(nsAString & aSummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString description; */
NS_IMETHODIMP nsAddonSearchResult::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rating; */
NS_IMETHODIMP nsAddonSearchResult::GetRating(PRInt32 *aRating)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString iconURL; */
NS_IMETHODIMP nsAddonSearchResult::GetIconURL(nsAString & aIconURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString thumbnailURL; */
NS_IMETHODIMP nsAddonSearchResult::GetThumbnailURL(nsAString & aThumbnailURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString homepageURL; */
NS_IMETHODIMP nsAddonSearchResult::GetHomepageURL(nsAString & aHomepageURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString eula; */
NS_IMETHODIMP nsAddonSearchResult::GetEula(nsAString & aEula)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long type; */
NS_IMETHODIMP nsAddonSearchResult::GetType(PRUint32 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString xpiURL; */
NS_IMETHODIMP nsAddonSearchResult::GetXpiURL(nsAString & aXpiURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString xpiHash; */
NS_IMETHODIMP nsAddonSearchResult::GetXpiHash(nsAString & aXpiHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAddonSearchResultsCallback */
#define NS_IADDONSEARCHRESULTSCALLBACK_IID_STR "a6f70917-dd30-4eb6-8b3d-453204f96f33"

#define NS_IADDONSEARCHRESULTSCALLBACK_IID \
  {0xa6f70917, 0xdd30, 0x4eb6, \
    { 0x8b, 0x3d, 0x45, 0x32, 0x04, 0xf9, 0x6f, 0x33 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAddonSearchResultsCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IADDONSEARCHRESULTSCALLBACK_IID)

  /**
   * Called when a search has suceeded.
   *
   * @param  aAddons        an array of the add-on results. In the case of
   *                        searching for specific terms the ordering of results
   *                        may be determined by the search provider.
   * @param  aAddonCount    The length of aAddons
   * @param  aTotalResults  The total results actually available in the
   *                        repository
   */
  /* void searchSucceeded ([array, size_is (aAddonCount)] in nsIAddonSearchResult aAddons, in unsigned long aAddonCount, in unsigned long aTotalResults); */
  NS_SCRIPTABLE NS_IMETHOD SearchSucceeded(nsIAddonSearchResult **aAddons, PRUint32 aAddonCount, PRUint32 aTotalResults) = 0;

  /**
   * Called when an error occured when performing a search.
   */
  /* void searchFailed (); */
  NS_SCRIPTABLE NS_IMETHOD SearchFailed(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAddonSearchResultsCallback, NS_IADDONSEARCHRESULTSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIADDONSEARCHRESULTSCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD SearchSucceeded(nsIAddonSearchResult **aAddons, PRUint32 aAddonCount, PRUint32 aTotalResults); \
  NS_SCRIPTABLE NS_IMETHOD SearchFailed(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIADDONSEARCHRESULTSCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD SearchSucceeded(nsIAddonSearchResult **aAddons, PRUint32 aAddonCount, PRUint32 aTotalResults) { return _to SearchSucceeded(aAddons, aAddonCount, aTotalResults); } \
  NS_SCRIPTABLE NS_IMETHOD SearchFailed(void) { return _to SearchFailed(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIADDONSEARCHRESULTSCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD SearchSucceeded(nsIAddonSearchResult **aAddons, PRUint32 aAddonCount, PRUint32 aTotalResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchSucceeded(aAddons, aAddonCount, aTotalResults); } \
  NS_SCRIPTABLE NS_IMETHOD SearchFailed(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchFailed(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAddonSearchResultsCallback : public nsIAddonSearchResultsCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIADDONSEARCHRESULTSCALLBACK

  nsAddonSearchResultsCallback();

private:
  ~nsAddonSearchResultsCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAddonSearchResultsCallback, nsIAddonSearchResultsCallback)

nsAddonSearchResultsCallback::nsAddonSearchResultsCallback()
{
  /* member initializers and constructor code */
}

nsAddonSearchResultsCallback::~nsAddonSearchResultsCallback()
{
  /* destructor code */
}

/* void searchSucceeded ([array, size_is (aAddonCount)] in nsIAddonSearchResult aAddons, in unsigned long aAddonCount, in unsigned long aTotalResults); */
NS_IMETHODIMP nsAddonSearchResultsCallback::SearchSucceeded(nsIAddonSearchResult **aAddons, PRUint32 aAddonCount, PRUint32 aTotalResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void searchFailed (); */
NS_IMETHODIMP nsAddonSearchResultsCallback::SearchFailed()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAddonRepository */
#define NS_IADDONREPOSITORY_IID_STR "c4d2ac29-6edc-43cd-8dc8-e4cf213aa1be"

#define NS_IADDONREPOSITORY_IID \
  {0xc4d2ac29, 0x6edc, 0x43cd, \
    { 0x8d, 0xc8, 0xe4, 0xcf, 0x21, 0x3a, 0xa1, 0xbe }}

/**
 * The add-on repository is a source of add-ons that can be installed. It can
 * be searched in two ways. One returns a list of add-ons that come highly
 * recommended, this list should change frequently. The other way is to
 * search for specific search terms entered by the user. Searches are
 * asynchronous and results should be passed to the provided callback object
 * when complete. The results passed to the callback should only include add-ons
 * that are compatible with the current application and are not already
 * installed. Searches are always asynchronous and should be passed to the
 * callback object provided.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAddonRepository : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IADDONREPOSITORY_IID)

  /**
   * The homepage for visiting this repository. This may be null or an empty
   * string.
   */
  /* readonly attribute AString homepageURL; */
  NS_SCRIPTABLE NS_IMETHOD GetHomepageURL(nsAString & aHomepageURL) = 0;

  /**
   * Returns whether this instance is currently performing a search. New
   * searches will not be performed while this is the case.
   */
  /* readonly attribute boolean isSearching; */
  NS_SCRIPTABLE NS_IMETHOD GetIsSearching(PRBool *aIsSearching) = 0;

  /**
   * The url that can be visited to see recommended add-ons in this repository.
   */
  /* AString getRecommendedURL (); */
  NS_SCRIPTABLE NS_IMETHOD GetRecommendedURL(nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Retrieves the url that can be visited to see search results for the given
   * terms.
   *
   * @param  aSearchTerms  search terms used to search the repository
   */
  /* AString getSearchURL (in AString aSearchTerms); */
  NS_SCRIPTABLE NS_IMETHOD GetSearchURL(const nsAString & aSearchTerms, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Begins a search for recommended add-ons in this repository. Results will
   * be passed to the given callback.
   *
   * @param  aMaxResults  the maximum number of results to return
   * @param  aCallback    the callback to pass results to
   */
  /* void retrieveRecommendedAddons (in unsigned long aMaxResults, in nsIAddonSearchResultsCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD RetrieveRecommendedAddons(PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback) = 0;

  /**
   * Begins a search for add-ons in this repository. Results will be passed to
   * the given callback.
   *
   * @param  aSearchTerms  the terms to search for
   * @param  aMaxResults   the maximum number of results to return
   * @param  aCallback     the callback to pass results to
   */
  /* void searchAddons (in AString aSearchTerms, in unsigned long aMaxResults, in nsIAddonSearchResultsCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD SearchAddons(const nsAString & aSearchTerms, PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback) = 0;

  /**
   * Cancels the search in progress. If there is no search in progress this
   * does nothing.
   */
  /* void cancelSearch (); */
  NS_SCRIPTABLE NS_IMETHOD CancelSearch(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAddonRepository, NS_IADDONREPOSITORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIADDONREPOSITORY \
  NS_SCRIPTABLE NS_IMETHOD GetHomepageURL(nsAString & aHomepageURL); \
  NS_SCRIPTABLE NS_IMETHOD GetIsSearching(PRBool *aIsSearching); \
  NS_SCRIPTABLE NS_IMETHOD GetRecommendedURL(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSearchURL(const nsAString & aSearchTerms, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RetrieveRecommendedAddons(PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback); \
  NS_SCRIPTABLE NS_IMETHOD SearchAddons(const nsAString & aSearchTerms, PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback); \
  NS_SCRIPTABLE NS_IMETHOD CancelSearch(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIADDONREPOSITORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHomepageURL(nsAString & aHomepageURL) { return _to GetHomepageURL(aHomepageURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSearching(PRBool *aIsSearching) { return _to GetIsSearching(aIsSearching); } \
  NS_SCRIPTABLE NS_IMETHOD GetRecommendedURL(nsAString & _retval NS_OUTPARAM) { return _to GetRecommendedURL(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchURL(const nsAString & aSearchTerms, nsAString & _retval NS_OUTPARAM) { return _to GetSearchURL(aSearchTerms, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RetrieveRecommendedAddons(PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback) { return _to RetrieveRecommendedAddons(aMaxResults, aCallback); } \
  NS_SCRIPTABLE NS_IMETHOD SearchAddons(const nsAString & aSearchTerms, PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback) { return _to SearchAddons(aSearchTerms, aMaxResults, aCallback); } \
  NS_SCRIPTABLE NS_IMETHOD CancelSearch(void) { return _to CancelSearch(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIADDONREPOSITORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHomepageURL(nsAString & aHomepageURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHomepageURL(aHomepageURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSearching(PRBool *aIsSearching) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSearching(aIsSearching); } \
  NS_SCRIPTABLE NS_IMETHOD GetRecommendedURL(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRecommendedURL(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchURL(const nsAString & aSearchTerms, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchURL(aSearchTerms, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RetrieveRecommendedAddons(PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RetrieveRecommendedAddons(aMaxResults, aCallback); } \
  NS_SCRIPTABLE NS_IMETHOD SearchAddons(const nsAString & aSearchTerms, PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchAddons(aSearchTerms, aMaxResults, aCallback); } \
  NS_SCRIPTABLE NS_IMETHOD CancelSearch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelSearch(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAddonRepository : public nsIAddonRepository
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIADDONREPOSITORY

  nsAddonRepository();

private:
  ~nsAddonRepository();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAddonRepository, nsIAddonRepository)

nsAddonRepository::nsAddonRepository()
{
  /* member initializers and constructor code */
}

nsAddonRepository::~nsAddonRepository()
{
  /* destructor code */
}

/* readonly attribute AString homepageURL; */
NS_IMETHODIMP nsAddonRepository::GetHomepageURL(nsAString & aHomepageURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSearching; */
NS_IMETHODIMP nsAddonRepository::GetIsSearching(PRBool *aIsSearching)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getRecommendedURL (); */
NS_IMETHODIMP nsAddonRepository::GetRecommendedURL(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getSearchURL (in AString aSearchTerms); */
NS_IMETHODIMP nsAddonRepository::GetSearchURL(const nsAString & aSearchTerms, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void retrieveRecommendedAddons (in unsigned long aMaxResults, in nsIAddonSearchResultsCallback aCallback); */
NS_IMETHODIMP nsAddonRepository::RetrieveRecommendedAddons(PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void searchAddons (in AString aSearchTerms, in unsigned long aMaxResults, in nsIAddonSearchResultsCallback aCallback); */
NS_IMETHODIMP nsAddonRepository::SearchAddons(const nsAString & aSearchTerms, PRUint32 aMaxResults, nsIAddonSearchResultsCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelSearch (); */
NS_IMETHODIMP nsAddonRepository::CancelSearch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAddonRepository_h__ */
