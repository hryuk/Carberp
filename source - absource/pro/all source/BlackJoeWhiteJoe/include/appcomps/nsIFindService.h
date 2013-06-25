/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/components/find/public/nsIFindService.idl
 */

#ifndef __gen_nsIFindService_h__
#define __gen_nsIFindService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFindService */
#define NS_IFINDSERVICE_IID_STR "5060b801-340e-11d5-be5b-b3e063ec6a3c"

#define NS_IFINDSERVICE_IID \
  {0x5060b801, 0x340e, 0x11d5, \
    { 0xbe, 0x5b, 0xb3, 0xe0, 0x63, 0xec, 0x6a, 0x3c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFindService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFINDSERVICE_IID)

  /* attribute AString searchString; */
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(nsAString & aSearchString) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const nsAString & aSearchString) = 0;

  /* attribute AString replaceString; */
  NS_SCRIPTABLE NS_IMETHOD GetReplaceString(nsAString & aReplaceString) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReplaceString(const nsAString & aReplaceString) = 0;

  /* attribute boolean findBackwards; */
  NS_SCRIPTABLE NS_IMETHOD GetFindBackwards(PRBool *aFindBackwards) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFindBackwards(PRBool aFindBackwards) = 0;

  /* attribute boolean wrapFind; */
  NS_SCRIPTABLE NS_IMETHOD GetWrapFind(PRBool *aWrapFind) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWrapFind(PRBool aWrapFind) = 0;

  /* attribute boolean entireWord; */
  NS_SCRIPTABLE NS_IMETHOD GetEntireWord(PRBool *aEntireWord) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEntireWord(PRBool aEntireWord) = 0;

  /* attribute boolean matchCase; */
  NS_SCRIPTABLE NS_IMETHOD GetMatchCase(PRBool *aMatchCase) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMatchCase(PRBool aMatchCase) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFindService, NS_IFINDSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFINDSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(nsAString & aSearchString); \
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const nsAString & aSearchString); \
  NS_SCRIPTABLE NS_IMETHOD GetReplaceString(nsAString & aReplaceString); \
  NS_SCRIPTABLE NS_IMETHOD SetReplaceString(const nsAString & aReplaceString); \
  NS_SCRIPTABLE NS_IMETHOD GetFindBackwards(PRBool *aFindBackwards); \
  NS_SCRIPTABLE NS_IMETHOD SetFindBackwards(PRBool aFindBackwards); \
  NS_SCRIPTABLE NS_IMETHOD GetWrapFind(PRBool *aWrapFind); \
  NS_SCRIPTABLE NS_IMETHOD SetWrapFind(PRBool aWrapFind); \
  NS_SCRIPTABLE NS_IMETHOD GetEntireWord(PRBool *aEntireWord); \
  NS_SCRIPTABLE NS_IMETHOD SetEntireWord(PRBool aEntireWord); \
  NS_SCRIPTABLE NS_IMETHOD GetMatchCase(PRBool *aMatchCase); \
  NS_SCRIPTABLE NS_IMETHOD SetMatchCase(PRBool aMatchCase); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFINDSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(nsAString & aSearchString) { return _to GetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const nsAString & aSearchString) { return _to SetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD GetReplaceString(nsAString & aReplaceString) { return _to GetReplaceString(aReplaceString); } \
  NS_SCRIPTABLE NS_IMETHOD SetReplaceString(const nsAString & aReplaceString) { return _to SetReplaceString(aReplaceString); } \
  NS_SCRIPTABLE NS_IMETHOD GetFindBackwards(PRBool *aFindBackwards) { return _to GetFindBackwards(aFindBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD SetFindBackwards(PRBool aFindBackwards) { return _to SetFindBackwards(aFindBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrapFind(PRBool *aWrapFind) { return _to GetWrapFind(aWrapFind); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapFind(PRBool aWrapFind) { return _to SetWrapFind(aWrapFind); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntireWord(PRBool *aEntireWord) { return _to GetEntireWord(aEntireWord); } \
  NS_SCRIPTABLE NS_IMETHOD SetEntireWord(PRBool aEntireWord) { return _to SetEntireWord(aEntireWord); } \
  NS_SCRIPTABLE NS_IMETHOD GetMatchCase(PRBool *aMatchCase) { return _to GetMatchCase(aMatchCase); } \
  NS_SCRIPTABLE NS_IMETHOD SetMatchCase(PRBool aMatchCase) { return _to SetMatchCase(aMatchCase); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFINDSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(nsAString & aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const nsAString & aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD GetReplaceString(nsAString & aReplaceString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReplaceString(aReplaceString); } \
  NS_SCRIPTABLE NS_IMETHOD SetReplaceString(const nsAString & aReplaceString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReplaceString(aReplaceString); } \
  NS_SCRIPTABLE NS_IMETHOD GetFindBackwards(PRBool *aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFindBackwards(aFindBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD SetFindBackwards(PRBool aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFindBackwards(aFindBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrapFind(PRBool *aWrapFind) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrapFind(aWrapFind); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapFind(PRBool aWrapFind) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWrapFind(aWrapFind); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntireWord(PRBool *aEntireWord) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntireWord(aEntireWord); } \
  NS_SCRIPTABLE NS_IMETHOD SetEntireWord(PRBool aEntireWord) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEntireWord(aEntireWord); } \
  NS_SCRIPTABLE NS_IMETHOD GetMatchCase(PRBool *aMatchCase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatchCase(aMatchCase); } \
  NS_SCRIPTABLE NS_IMETHOD SetMatchCase(PRBool aMatchCase) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMatchCase(aMatchCase); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFindService : public nsIFindService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFINDSERVICE

  nsFindService();

private:
  ~nsFindService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFindService, nsIFindService)

nsFindService::nsFindService()
{
  /* member initializers and constructor code */
}

nsFindService::~nsFindService()
{
  /* destructor code */
}

/* attribute AString searchString; */
NS_IMETHODIMP nsFindService::GetSearchString(nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetSearchString(const nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString replaceString; */
NS_IMETHODIMP nsFindService::GetReplaceString(nsAString & aReplaceString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetReplaceString(const nsAString & aReplaceString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean findBackwards; */
NS_IMETHODIMP nsFindService::GetFindBackwards(PRBool *aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetFindBackwards(PRBool aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean wrapFind; */
NS_IMETHODIMP nsFindService::GetWrapFind(PRBool *aWrapFind)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetWrapFind(PRBool aWrapFind)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean entireWord; */
NS_IMETHODIMP nsFindService::GetEntireWord(PRBool *aEntireWord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetEntireWord(PRBool aEntireWord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean matchCase; */
NS_IMETHODIMP nsFindService::GetMatchCase(PRBool *aMatchCase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetMatchCase(PRBool aMatchCase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFindService_h__ */
