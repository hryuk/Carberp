/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/find/public/nsIFind.idl
 */

#ifndef __gen_nsIFind_h__
#define __gen_nsIFind_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMRange; /* forward declaration */

class nsIWordBreaker; /* forward declaration */


/* starting interface:    nsIFind */
#define NS_IFIND_IID_STR "75125d55-37ee-4575-b9b5-f33bfa68c2a1"

#define NS_IFIND_IID \
  {0x75125d55, 0x37ee, 0x4575, \
    { 0xb9, 0xb5, 0xf3, 0x3b, 0xfa, 0x68, 0xc2, 0xa1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFind : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFIND_IID)

  /* attribute boolean findBackwards; */
  NS_SCRIPTABLE NS_IMETHOD GetFindBackwards(PRBool *aFindBackwards) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFindBackwards(PRBool aFindBackwards) = 0;

  /* attribute boolean caseSensitive; */
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive) = 0;

  /**
   * Use "find entire words" mode by setting to a word breaker
   * or null, to disable "entire words" mode.
   */
  /* [noscript] attribute nsIWordBreaker wordBreaker; */
  NS_IMETHOD GetWordBreaker(nsIWordBreaker * *aWordBreaker) = 0;
  NS_IMETHOD SetWordBreaker(nsIWordBreaker * aWordBreaker) = 0;

  /**
   * Find some text in the current context. The implementation is
   * responsible for performing the find and highlighting the text.
   *
   * @param aPatText     The text to search for.
   * @param aSearchRange A Range specifying domain of search.
   * @param aStartPoint  A Range specifying search start point.
   *                     If not collapsed, we'll start from
   *                     end (forward) or start (backward).
   * @param aEndPoint    A Range specifying search end point.
   *                     If not collapsed, we'll end at
   *                     end (forward) or start (backward).
   * @retval             A range spanning the match that was found (or null).
   */
  /* nsIDOMRange Find (in wstring aPatText, in nsIDOMRange aSearchRange, in nsIDOMRange aStartPoint, in nsIDOMRange aEndPoint); */
  NS_SCRIPTABLE NS_IMETHOD Find(const PRUnichar *aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFind, NS_IFIND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFIND \
  NS_SCRIPTABLE NS_IMETHOD GetFindBackwards(PRBool *aFindBackwards); \
  NS_SCRIPTABLE NS_IMETHOD SetFindBackwards(PRBool aFindBackwards); \
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive); \
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive); \
  NS_IMETHOD GetWordBreaker(nsIWordBreaker * *aWordBreaker); \
  NS_IMETHOD SetWordBreaker(nsIWordBreaker * aWordBreaker); \
  NS_SCRIPTABLE NS_IMETHOD Find(const PRUnichar *aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFIND(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFindBackwards(PRBool *aFindBackwards) { return _to GetFindBackwards(aFindBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD SetFindBackwards(PRBool aFindBackwards) { return _to SetFindBackwards(aFindBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive) { return _to GetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive) { return _to SetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD GetWordBreaker(nsIWordBreaker * *aWordBreaker) { return _to GetWordBreaker(aWordBreaker); } \
  NS_IMETHOD SetWordBreaker(nsIWordBreaker * aWordBreaker) { return _to SetWordBreaker(aWordBreaker); } \
  NS_SCRIPTABLE NS_IMETHOD Find(const PRUnichar *aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange **_retval NS_OUTPARAM) { return _to Find(aPatText, aSearchRange, aStartPoint, aEndPoint, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFIND(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFindBackwards(PRBool *aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFindBackwards(aFindBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD SetFindBackwards(PRBool aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFindBackwards(aFindBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD GetWordBreaker(nsIWordBreaker * *aWordBreaker) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWordBreaker(aWordBreaker); } \
  NS_IMETHOD SetWordBreaker(nsIWordBreaker * aWordBreaker) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWordBreaker(aWordBreaker); } \
  NS_SCRIPTABLE NS_IMETHOD Find(const PRUnichar *aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Find(aPatText, aSearchRange, aStartPoint, aEndPoint, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFind : public nsIFind
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFIND

  nsFind();

private:
  ~nsFind();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFind, nsIFind)

nsFind::nsFind()
{
  /* member initializers and constructor code */
}

nsFind::~nsFind()
{
  /* destructor code */
}

/* attribute boolean findBackwards; */
NS_IMETHODIMP nsFind::GetFindBackwards(PRBool *aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFind::SetFindBackwards(PRBool aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean caseSensitive; */
NS_IMETHODIMP nsFind::GetCaseSensitive(PRBool *aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFind::SetCaseSensitive(PRBool aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIWordBreaker wordBreaker; */
NS_IMETHODIMP nsFind::GetWordBreaker(nsIWordBreaker * *aWordBreaker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFind::SetWordBreaker(nsIWordBreaker * aWordBreaker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMRange Find (in wstring aPatText, in nsIDOMRange aSearchRange, in nsIDOMRange aStartPoint, in nsIDOMRange aEndPoint); */
NS_IMETHODIMP nsFind::Find(const PRUnichar *aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFind_h__ */
