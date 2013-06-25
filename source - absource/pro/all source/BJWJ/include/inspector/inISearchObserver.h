/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/inspector/public/inISearchObserver.idl
 */

#ifndef __gen_inISearchObserver_h__
#define __gen_inISearchObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class inISearchProcess; /* forward declaration */


/* starting interface:    inISearchObserver */
#define INISEARCHOBSERVER_IID_STR "46226d9b-e398-4106-8d9b-225d4d0589f5"

#define INISEARCHOBSERVER_IID \
  {0x46226d9b, 0xe398, 0x4106, \
    { 0x8d, 0x9b, 0x22, 0x5d, 0x4d, 0x05, 0x89, 0xf5 }}

class NS_NO_VTABLE NS_SCRIPTABLE inISearchObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INISEARCHOBSERVER_IID)

  enum { IN_SUCCESS = 1 };

  enum { IN_INTERRUPTED = 2 };

  enum { IN_ERROR = 3 };

  /* void onSearchStart (in inISearchProcess aModule); */
  NS_SCRIPTABLE NS_IMETHOD OnSearchStart(inISearchProcess *aModule) = 0;

  /* void onSearchResult (in inISearchProcess aModule); */
  NS_SCRIPTABLE NS_IMETHOD OnSearchResult(inISearchProcess *aModule) = 0;

  /* void onSearchEnd (in inISearchProcess aModule, in short aResult); */
  NS_SCRIPTABLE NS_IMETHOD OnSearchEnd(inISearchProcess *aModule, PRInt16 aResult) = 0;

  /* void onSearchError (in inISearchProcess aModule, in AString aMessage); */
  NS_SCRIPTABLE NS_IMETHOD OnSearchError(inISearchProcess *aModule, const nsAString & aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inISearchObserver, INISEARCHOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INISEARCHOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnSearchStart(inISearchProcess *aModule); \
  NS_SCRIPTABLE NS_IMETHOD OnSearchResult(inISearchProcess *aModule); \
  NS_SCRIPTABLE NS_IMETHOD OnSearchEnd(inISearchProcess *aModule, PRInt16 aResult); \
  NS_SCRIPTABLE NS_IMETHOD OnSearchError(inISearchProcess *aModule, const nsAString & aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INISEARCHOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnSearchStart(inISearchProcess *aModule) { return _to OnSearchStart(aModule); } \
  NS_SCRIPTABLE NS_IMETHOD OnSearchResult(inISearchProcess *aModule) { return _to OnSearchResult(aModule); } \
  NS_SCRIPTABLE NS_IMETHOD OnSearchEnd(inISearchProcess *aModule, PRInt16 aResult) { return _to OnSearchEnd(aModule, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD OnSearchError(inISearchProcess *aModule, const nsAString & aMessage) { return _to OnSearchError(aModule, aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INISEARCHOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnSearchStart(inISearchProcess *aModule) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchStart(aModule); } \
  NS_SCRIPTABLE NS_IMETHOD OnSearchResult(inISearchProcess *aModule) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchResult(aModule); } \
  NS_SCRIPTABLE NS_IMETHOD OnSearchEnd(inISearchProcess *aModule, PRInt16 aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchEnd(aModule, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD OnSearchError(inISearchProcess *aModule, const nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchError(aModule, aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inSearchObserver : public inISearchObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INISEARCHOBSERVER

  inSearchObserver();

private:
  ~inSearchObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inSearchObserver, inISearchObserver)

inSearchObserver::inSearchObserver()
{
  /* member initializers and constructor code */
}

inSearchObserver::~inSearchObserver()
{
  /* destructor code */
}

/* void onSearchStart (in inISearchProcess aModule); */
NS_IMETHODIMP inSearchObserver::OnSearchStart(inISearchProcess *aModule)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSearchResult (in inISearchProcess aModule); */
NS_IMETHODIMP inSearchObserver::OnSearchResult(inISearchProcess *aModule)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSearchEnd (in inISearchProcess aModule, in short aResult); */
NS_IMETHODIMP inSearchObserver::OnSearchEnd(inISearchProcess *aModule, PRInt16 aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSearchError (in inISearchProcess aModule, in AString aMessage); */
NS_IMETHODIMP inSearchObserver::OnSearchError(inISearchProcess *aModule, const nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inISearchObserver_h__ */
