/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/components/find/public/nsISearchContext.idl
 */

#ifndef __gen_nsISearchContext_h__
#define __gen_nsISearchContext_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindowInternal; /* forward declaration */


/* starting interface:    nsISearchContext */
#define NS_ISEARCHCONTEXT_IID_STR "31aba0f0-2d93-11d3-8069-00600811a9c3"

#define NS_ISEARCHCONTEXT_IID \
  {0x31aba0f0, 0x2d93, 0x11d3, \
    { 0x80, 0x69, 0x00, 0x60, 0x08, 0x11, 0xa9, 0xc3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISearchContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEARCHCONTEXT_IID)

  /* attribute wstring searchString; */
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(PRUnichar * *aSearchString) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const PRUnichar * aSearchString) = 0;

  /* attribute wstring replaceString; */
  NS_SCRIPTABLE NS_IMETHOD GetReplaceString(PRUnichar * *aReplaceString) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReplaceString(const PRUnichar * aReplaceString) = 0;

  /* attribute boolean searchBackwards; */
  NS_SCRIPTABLE NS_IMETHOD GetSearchBackwards(PRBool *aSearchBackwards) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSearchBackwards(PRBool aSearchBackwards) = 0;

  /* attribute boolean caseSensitive; */
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive) = 0;

  /* attribute boolean wrapSearch; */
  NS_SCRIPTABLE NS_IMETHOD GetWrapSearch(PRBool *aWrapSearch) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWrapSearch(PRBool aWrapSearch) = 0;

  /* readonly attribute nsIDOMWindowInternal targetWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetWindow(nsIDOMWindowInternal * *aTargetWindow) = 0;

  /* attribute nsIDOMWindowInternal findDialog; */
  NS_SCRIPTABLE NS_IMETHOD GetFindDialog(nsIDOMWindowInternal * *aFindDialog) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFindDialog(nsIDOMWindowInternal * aFindDialog) = 0;

  /* attribute nsIDOMWindowInternal replaceDialog; */
  NS_SCRIPTABLE NS_IMETHOD GetReplaceDialog(nsIDOMWindowInternal * *aReplaceDialog) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReplaceDialog(nsIDOMWindowInternal * aReplaceDialog) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISearchContext, NS_ISEARCHCONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEARCHCONTEXT \
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(PRUnichar * *aSearchString); \
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const PRUnichar * aSearchString); \
  NS_SCRIPTABLE NS_IMETHOD GetReplaceString(PRUnichar * *aReplaceString); \
  NS_SCRIPTABLE NS_IMETHOD SetReplaceString(const PRUnichar * aReplaceString); \
  NS_SCRIPTABLE NS_IMETHOD GetSearchBackwards(PRBool *aSearchBackwards); \
  NS_SCRIPTABLE NS_IMETHOD SetSearchBackwards(PRBool aSearchBackwards); \
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive); \
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive); \
  NS_SCRIPTABLE NS_IMETHOD GetWrapSearch(PRBool *aWrapSearch); \
  NS_SCRIPTABLE NS_IMETHOD SetWrapSearch(PRBool aWrapSearch); \
  NS_SCRIPTABLE NS_IMETHOD GetTargetWindow(nsIDOMWindowInternal * *aTargetWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetFindDialog(nsIDOMWindowInternal * *aFindDialog); \
  NS_SCRIPTABLE NS_IMETHOD SetFindDialog(nsIDOMWindowInternal * aFindDialog); \
  NS_SCRIPTABLE NS_IMETHOD GetReplaceDialog(nsIDOMWindowInternal * *aReplaceDialog); \
  NS_SCRIPTABLE NS_IMETHOD SetReplaceDialog(nsIDOMWindowInternal * aReplaceDialog); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEARCHCONTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(PRUnichar * *aSearchString) { return _to GetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const PRUnichar * aSearchString) { return _to SetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD GetReplaceString(PRUnichar * *aReplaceString) { return _to GetReplaceString(aReplaceString); } \
  NS_SCRIPTABLE NS_IMETHOD SetReplaceString(const PRUnichar * aReplaceString) { return _to SetReplaceString(aReplaceString); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchBackwards(PRBool *aSearchBackwards) { return _to GetSearchBackwards(aSearchBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchBackwards(PRBool aSearchBackwards) { return _to SetSearchBackwards(aSearchBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive) { return _to GetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive) { return _to SetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrapSearch(PRBool *aWrapSearch) { return _to GetWrapSearch(aWrapSearch); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapSearch(PRBool aWrapSearch) { return _to SetWrapSearch(aWrapSearch); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetWindow(nsIDOMWindowInternal * *aTargetWindow) { return _to GetTargetWindow(aTargetWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFindDialog(nsIDOMWindowInternal * *aFindDialog) { return _to GetFindDialog(aFindDialog); } \
  NS_SCRIPTABLE NS_IMETHOD SetFindDialog(nsIDOMWindowInternal * aFindDialog) { return _to SetFindDialog(aFindDialog); } \
  NS_SCRIPTABLE NS_IMETHOD GetReplaceDialog(nsIDOMWindowInternal * *aReplaceDialog) { return _to GetReplaceDialog(aReplaceDialog); } \
  NS_SCRIPTABLE NS_IMETHOD SetReplaceDialog(nsIDOMWindowInternal * aReplaceDialog) { return _to SetReplaceDialog(aReplaceDialog); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEARCHCONTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(PRUnichar * *aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchString(const PRUnichar * aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD GetReplaceString(PRUnichar * *aReplaceString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReplaceString(aReplaceString); } \
  NS_SCRIPTABLE NS_IMETHOD SetReplaceString(const PRUnichar * aReplaceString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReplaceString(aReplaceString); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchBackwards(PRBool *aSearchBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchBackwards(aSearchBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchBackwards(PRBool aSearchBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchBackwards(aSearchBackwards); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrapSearch(PRBool *aWrapSearch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrapSearch(aWrapSearch); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapSearch(PRBool aWrapSearch) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWrapSearch(aWrapSearch); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetWindow(nsIDOMWindowInternal * *aTargetWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetWindow(aTargetWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFindDialog(nsIDOMWindowInternal * *aFindDialog) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFindDialog(aFindDialog); } \
  NS_SCRIPTABLE NS_IMETHOD SetFindDialog(nsIDOMWindowInternal * aFindDialog) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFindDialog(aFindDialog); } \
  NS_SCRIPTABLE NS_IMETHOD GetReplaceDialog(nsIDOMWindowInternal * *aReplaceDialog) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReplaceDialog(aReplaceDialog); } \
  NS_SCRIPTABLE NS_IMETHOD SetReplaceDialog(nsIDOMWindowInternal * aReplaceDialog) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReplaceDialog(aReplaceDialog); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSearchContext : public nsISearchContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEARCHCONTEXT

  nsSearchContext();

private:
  ~nsSearchContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSearchContext, nsISearchContext)

nsSearchContext::nsSearchContext()
{
  /* member initializers and constructor code */
}

nsSearchContext::~nsSearchContext()
{
  /* destructor code */
}

/* attribute wstring searchString; */
NS_IMETHODIMP nsSearchContext::GetSearchString(PRUnichar * *aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchContext::SetSearchString(const PRUnichar * aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring replaceString; */
NS_IMETHODIMP nsSearchContext::GetReplaceString(PRUnichar * *aReplaceString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchContext::SetReplaceString(const PRUnichar * aReplaceString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean searchBackwards; */
NS_IMETHODIMP nsSearchContext::GetSearchBackwards(PRBool *aSearchBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchContext::SetSearchBackwards(PRBool aSearchBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean caseSensitive; */
NS_IMETHODIMP nsSearchContext::GetCaseSensitive(PRBool *aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchContext::SetCaseSensitive(PRBool aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean wrapSearch; */
NS_IMETHODIMP nsSearchContext::GetWrapSearch(PRBool *aWrapSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchContext::SetWrapSearch(PRBool aWrapSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindowInternal targetWindow; */
NS_IMETHODIMP nsSearchContext::GetTargetWindow(nsIDOMWindowInternal * *aTargetWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindowInternal findDialog; */
NS_IMETHODIMP nsSearchContext::GetFindDialog(nsIDOMWindowInternal * *aFindDialog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchContext::SetFindDialog(nsIDOMWindowInternal * aFindDialog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindowInternal replaceDialog; */
NS_IMETHODIMP nsSearchContext::GetReplaceDialog(nsIDOMWindowInternal * *aReplaceDialog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchContext::SetReplaceDialog(nsIDOMWindowInternal * aReplaceDialog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISearchContext_h__ */
