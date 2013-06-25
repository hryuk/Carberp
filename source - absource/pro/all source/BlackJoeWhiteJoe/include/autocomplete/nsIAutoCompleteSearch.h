/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/autocomplete/public/nsIAutoCompleteSearch.idl
 */

#ifndef __gen_nsIAutoCompleteSearch_h__
#define __gen_nsIAutoCompleteSearch_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAutoCompleteResult; /* forward declaration */

class nsIAutoCompleteObserver; /* forward declaration */


/* starting interface:    nsIAutoCompleteSearch */
#define NS_IAUTOCOMPLETESEARCH_IID_STR "de8db85f-c1de-4d87-94ba-7844890f91fe"

#define NS_IAUTOCOMPLETESEARCH_IID \
  {0xde8db85f, 0xc1de, 0x4d87, \
    { 0x94, 0xba, 0x78, 0x44, 0x89, 0x0f, 0x91, 0xfe }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAutoCompleteSearch : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETESEARCH_IID)

  /* void startSearch (in AString searchString, in AString searchParam, in nsIAutoCompleteResult previousResult, in nsIAutoCompleteObserver listener); */
  NS_SCRIPTABLE NS_IMETHOD StartSearch(const nsAString & searchString, const nsAString & searchParam, nsIAutoCompleteResult *previousResult, nsIAutoCompleteObserver *listener) = 0;

  /* void stopSearch (); */
  NS_SCRIPTABLE NS_IMETHOD StopSearch(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteSearch, NS_IAUTOCOMPLETESEARCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETESEARCH \
  NS_SCRIPTABLE NS_IMETHOD StartSearch(const nsAString & searchString, const nsAString & searchParam, nsIAutoCompleteResult *previousResult, nsIAutoCompleteObserver *listener); \
  NS_SCRIPTABLE NS_IMETHOD StopSearch(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETESEARCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartSearch(const nsAString & searchString, const nsAString & searchParam, nsIAutoCompleteResult *previousResult, nsIAutoCompleteObserver *listener) { return _to StartSearch(searchString, searchParam, previousResult, listener); } \
  NS_SCRIPTABLE NS_IMETHOD StopSearch(void) { return _to StopSearch(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETESEARCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartSearch(const nsAString & searchString, const nsAString & searchParam, nsIAutoCompleteResult *previousResult, nsIAutoCompleteObserver *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartSearch(searchString, searchParam, previousResult, listener); } \
  NS_SCRIPTABLE NS_IMETHOD StopSearch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopSearch(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteSearch : public nsIAutoCompleteSearch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETESEARCH

  nsAutoCompleteSearch();

private:
  ~nsAutoCompleteSearch();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoCompleteSearch, nsIAutoCompleteSearch)

nsAutoCompleteSearch::nsAutoCompleteSearch()
{
  /* member initializers and constructor code */
}

nsAutoCompleteSearch::~nsAutoCompleteSearch()
{
  /* destructor code */
}

/* void startSearch (in AString searchString, in AString searchParam, in nsIAutoCompleteResult previousResult, in nsIAutoCompleteObserver listener); */
NS_IMETHODIMP nsAutoCompleteSearch::StartSearch(const nsAString & searchString, const nsAString & searchParam, nsIAutoCompleteResult *previousResult, nsIAutoCompleteObserver *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopSearch (); */
NS_IMETHODIMP nsAutoCompleteSearch::StopSearch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAutoCompleteObserver */
#define NS_IAUTOCOMPLETEOBSERVER_IID_STR "18c36504-9a4c-4ac3-8494-bd05e00ae27f"

#define NS_IAUTOCOMPLETEOBSERVER_IID \
  {0x18c36504, 0x9a4c, 0x4ac3, \
    { 0x84, 0x94, 0xbd, 0x05, 0xe0, 0x0a, 0xe2, 0x7f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAutoCompleteObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETEOBSERVER_IID)

  /* void onSearchResult (in nsIAutoCompleteSearch search, in nsIAutoCompleteResult result); */
  NS_SCRIPTABLE NS_IMETHOD OnSearchResult(nsIAutoCompleteSearch *search, nsIAutoCompleteResult *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteObserver, NS_IAUTOCOMPLETEOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETEOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnSearchResult(nsIAutoCompleteSearch *search, nsIAutoCompleteResult *result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETEOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnSearchResult(nsIAutoCompleteSearch *search, nsIAutoCompleteResult *result) { return _to OnSearchResult(search, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETEOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnSearchResult(nsIAutoCompleteSearch *search, nsIAutoCompleteResult *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchResult(search, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteObserver : public nsIAutoCompleteObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETEOBSERVER

  nsAutoCompleteObserver();

private:
  ~nsAutoCompleteObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoCompleteObserver, nsIAutoCompleteObserver)

nsAutoCompleteObserver::nsAutoCompleteObserver()
{
  /* member initializers and constructor code */
}

nsAutoCompleteObserver::~nsAutoCompleteObserver()
{
  /* destructor code */
}

/* void onSearchResult (in nsIAutoCompleteSearch search, in nsIAutoCompleteResult result); */
NS_IMETHODIMP nsAutoCompleteObserver::OnSearchResult(nsIAutoCompleteSearch *search, nsIAutoCompleteResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAutoCompleteSearch_h__ */
