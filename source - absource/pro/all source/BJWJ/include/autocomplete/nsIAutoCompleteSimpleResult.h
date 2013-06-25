/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/autocomplete/public/nsIAutoCompleteSimpleResult.idl
 */

#ifndef __gen_nsIAutoCompleteSimpleResult_h__
#define __gen_nsIAutoCompleteSimpleResult_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIAutoCompleteResult_h__
#include "nsIAutoCompleteResult.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAutoCompleteSimpleResultListener; /* forward declaration */


/* starting interface:    nsIAutoCompleteSimpleResult */
#define NS_IAUTOCOMPLETESIMPLERESULT_IID_STR "f9841787-ad26-49e6-a2dd-ba9020ee1c64"

#define NS_IAUTOCOMPLETESIMPLERESULT_IID \
  {0xf9841787, 0xad26, 0x49e6, \
    { 0xa2, 0xdd, 0xba, 0x90, 0x20, 0xee, 0x1c, 0x64 }}

/**
 * This class implements nsIAutoCompleteResult and provides simple methods
 * for setting the value and result items. It can be used whenever some basic
 * auto complete results are needed that can be pre-generated and filled into
 * an array.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAutoCompleteSimpleResult : public nsIAutoCompleteResult {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETESIMPLERESULT_IID)

  /**
   * A writer for the readonly attribute 'searchString' which should contain
   * the string that the user typed.
   */
  /* void setSearchString (in AString aSearchString); */
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const nsAString & aSearchString) = 0;

  /**
   * A writer for the readonly attribute 'errorDescription'.
   */
  /* void setErrorDescription (in AString aErrorDescription); */
  NS_SCRIPTABLE NS_IMETHOD SetErrorDescription(const nsAString & aErrorDescription) = 0;

  /**
   * A writer for the readonly attribute 'defaultIndex' which should contain
   * the index of the list that will be selected by default (normally 0).
   */
  /* void setDefaultIndex (in long aDefaultIndex); */
  NS_SCRIPTABLE NS_IMETHOD SetDefaultIndex(PRInt32 aDefaultIndex) = 0;

  /**
   * A writer for the readonly attribute 'searchResult' which should contain
   * one of the constants nsIAutoCompleteResult.RESULT_* indicating the success
   * of the search.
   */
  /* void setSearchResult (in unsigned short aSearchResult); */
  NS_SCRIPTABLE NS_IMETHOD SetSearchResult(PRUint16 aSearchResult) = 0;

  /**
   * Appends a result item consisting of the given value, comment, image and style.
   * This is how you add results.  Note:  image and style are optional. 
   */
  /* void appendMatch (in AString aValue, in AString aComment, [optional] in AString aImage, [optional] in AString aStyle); */
  NS_SCRIPTABLE NS_IMETHOD AppendMatch(const nsAString & aValue, const nsAString & aComment, const nsAString & aImage, const nsAString & aStyle) = 0;

  /**
   * Sets a listener for changes in the result.
   */
  /* void setListener (in nsIAutoCompleteSimpleResultListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIAutoCompleteSimpleResultListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteSimpleResult, NS_IAUTOCOMPLETESIMPLERESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETESIMPLERESULT \
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const nsAString & aSearchString); \
  NS_SCRIPTABLE NS_IMETHOD SetErrorDescription(const nsAString & aErrorDescription); \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultIndex(PRInt32 aDefaultIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetSearchResult(PRUint16 aSearchResult); \
  NS_SCRIPTABLE NS_IMETHOD AppendMatch(const nsAString & aValue, const nsAString & aComment, const nsAString & aImage, const nsAString & aStyle); \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIAutoCompleteSimpleResultListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETESIMPLERESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const nsAString & aSearchString) { return _to SetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD SetErrorDescription(const nsAString & aErrorDescription) { return _to SetErrorDescription(aErrorDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultIndex(PRInt32 aDefaultIndex) { return _to SetDefaultIndex(aDefaultIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchResult(PRUint16 aSearchResult) { return _to SetSearchResult(aSearchResult); } \
  NS_SCRIPTABLE NS_IMETHOD AppendMatch(const nsAString & aValue, const nsAString & aComment, const nsAString & aImage, const nsAString & aStyle) { return _to AppendMatch(aValue, aComment, aImage, aStyle); } \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIAutoCompleteSimpleResultListener *aListener) { return _to SetListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETESIMPLERESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const nsAString & aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD SetErrorDescription(const nsAString & aErrorDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetErrorDescription(aErrorDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultIndex(PRInt32 aDefaultIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultIndex(aDefaultIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchResult(PRUint16 aSearchResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchResult(aSearchResult); } \
  NS_SCRIPTABLE NS_IMETHOD AppendMatch(const nsAString & aValue, const nsAString & aComment, const nsAString & aImage, const nsAString & aStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendMatch(aValue, aComment, aImage, aStyle); } \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIAutoCompleteSimpleResultListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteSimpleResult : public nsIAutoCompleteSimpleResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETESIMPLERESULT

  nsAutoCompleteSimpleResult();

private:
  ~nsAutoCompleteSimpleResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoCompleteSimpleResult, nsIAutoCompleteSimpleResult)

nsAutoCompleteSimpleResult::nsAutoCompleteSimpleResult()
{
  /* member initializers and constructor code */
}

nsAutoCompleteSimpleResult::~nsAutoCompleteSimpleResult()
{
  /* destructor code */
}

/* void setSearchString (in AString aSearchString); */
NS_IMETHODIMP nsAutoCompleteSimpleResult::SetSearchString(const nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setErrorDescription (in AString aErrorDescription); */
NS_IMETHODIMP nsAutoCompleteSimpleResult::SetErrorDescription(const nsAString & aErrorDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDefaultIndex (in long aDefaultIndex); */
NS_IMETHODIMP nsAutoCompleteSimpleResult::SetDefaultIndex(PRInt32 aDefaultIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSearchResult (in unsigned short aSearchResult); */
NS_IMETHODIMP nsAutoCompleteSimpleResult::SetSearchResult(PRUint16 aSearchResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendMatch (in AString aValue, in AString aComment, [optional] in AString aImage, [optional] in AString aStyle); */
NS_IMETHODIMP nsAutoCompleteSimpleResult::AppendMatch(const nsAString & aValue, const nsAString & aComment, const nsAString & aImage, const nsAString & aStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setListener (in nsIAutoCompleteSimpleResultListener aListener); */
NS_IMETHODIMP nsAutoCompleteSimpleResult::SetListener(nsIAutoCompleteSimpleResultListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAutoCompleteSimpleResultListener */
#define NS_IAUTOCOMPLETESIMPLERESULTLISTENER_IID_STR "004efdc5-1989-4874-8a7a-345bf2fa33af"

#define NS_IAUTOCOMPLETESIMPLERESULTLISTENER_IID \
  {0x004efdc5, 0x1989, 0x4874, \
    { 0x8a, 0x7a, 0x34, 0x5b, 0xf2, 0xfa, 0x33, 0xaf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAutoCompleteSimpleResultListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETESIMPLERESULTLISTENER_IID)

  /**
   * Dispatched after a value is removed from the result.
   * @param aResult
   *        The result from which aValue has been removed.
   * @param aValue
   *        The removed value.
   * @param aRemoveFromDb
   *        Whether the value should be removed from persistent storage as well.
   */
  /* void onValueRemoved (in nsIAutoCompleteSimpleResult aResult, in AString aValue, in boolean aRemoveFromDb); */
  NS_SCRIPTABLE NS_IMETHOD OnValueRemoved(nsIAutoCompleteSimpleResult *aResult, const nsAString & aValue, PRBool aRemoveFromDb) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteSimpleResultListener, NS_IAUTOCOMPLETESIMPLERESULTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETESIMPLERESULTLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnValueRemoved(nsIAutoCompleteSimpleResult *aResult, const nsAString & aValue, PRBool aRemoveFromDb); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETESIMPLERESULTLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnValueRemoved(nsIAutoCompleteSimpleResult *aResult, const nsAString & aValue, PRBool aRemoveFromDb) { return _to OnValueRemoved(aResult, aValue, aRemoveFromDb); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETESIMPLERESULTLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnValueRemoved(nsIAutoCompleteSimpleResult *aResult, const nsAString & aValue, PRBool aRemoveFromDb) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnValueRemoved(aResult, aValue, aRemoveFromDb); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteSimpleResultListener : public nsIAutoCompleteSimpleResultListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETESIMPLERESULTLISTENER

  nsAutoCompleteSimpleResultListener();

private:
  ~nsAutoCompleteSimpleResultListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoCompleteSimpleResultListener, nsIAutoCompleteSimpleResultListener)

nsAutoCompleteSimpleResultListener::nsAutoCompleteSimpleResultListener()
{
  /* member initializers and constructor code */
}

nsAutoCompleteSimpleResultListener::~nsAutoCompleteSimpleResultListener()
{
  /* destructor code */
}

/* void onValueRemoved (in nsIAutoCompleteSimpleResult aResult, in AString aValue, in boolean aRemoveFromDb); */
NS_IMETHODIMP nsAutoCompleteSimpleResultListener::OnValueRemoved(nsIAutoCompleteSimpleResult *aResult, const nsAString & aValue, PRBool aRemoveFromDb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAutoCompleteSimpleResult_h__ */
