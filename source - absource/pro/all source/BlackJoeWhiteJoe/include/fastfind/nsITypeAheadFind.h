/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/typeaheadfind/public/nsITypeAheadFind.idl
 */

#ifndef __gen_nsITypeAheadFind_h__
#define __gen_nsITypeAheadFind_h__


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
class nsIDocShell; /* forward declaration */


/* starting interface:    nsITypeAheadFind */
#define NS_ITYPEAHEADFIND_IID_STR "0749a445-19d3-4eb9-9d66-78eca8c6f604"

#define NS_ITYPEAHEADFIND_IID \
  {0x0749a445, 0x19d3, 0x4eb9, \
    { 0x9d, 0x66, 0x78, 0xec, 0xa8, 0xc6, 0xf6, 0x04 }}

/****************************** nsTypeAheadFind ******************************/
class NS_NO_VTABLE NS_SCRIPTABLE nsITypeAheadFind : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITYPEAHEADFIND_IID)

  /****************************** Initializer ******************************/
  /* void init (in nsIDocShell aDocShell); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDocShell *aDocShell) = 0;

  /***************************** Core functions ****************************/
  /* unsigned short find (in AString aSearchString, in boolean aLinksOnly); */
  NS_SCRIPTABLE NS_IMETHOD Find(const nsAString & aSearchString, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM) = 0;

  /* unsigned short findAgain (in boolean findBackwards, in boolean aLinksOnly); */
  NS_SCRIPTABLE NS_IMETHOD FindAgain(PRBool findBackwards, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM) = 0;

  /**************************** Helper functions ***************************/
  /* void setDocShell (in nsIDocShell aDocShell); */
  NS_SCRIPTABLE NS_IMETHOD SetDocShell(nsIDocShell *aDocShell) = 0;

  /* void setSelectionModeAndRepaint (in short toggle); */
  NS_SCRIPTABLE NS_IMETHOD SetSelectionModeAndRepaint(PRInt16 toggle) = 0;

  /* void collapseSelection (); */
  NS_SCRIPTABLE NS_IMETHOD CollapseSelection(void) = 0;

  /******************************* Attributes ******************************/
  /* readonly attribute AString searchString; */
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(nsAString & aSearchString) = 0;

  /* attribute boolean caseSensitive; */
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive) = 0;

  /* readonly attribute nsIDOMElement foundLink; */
  NS_SCRIPTABLE NS_IMETHOD GetFoundLink(nsIDOMElement * *aFoundLink) = 0;

  /* readonly attribute nsIDOMElement foundEditable; */
  NS_SCRIPTABLE NS_IMETHOD GetFoundEditable(nsIDOMElement * *aFoundEditable) = 0;

  /* readonly attribute nsIDOMWindow currentWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentWindow(nsIDOMWindow * *aCurrentWindow) = 0;

  /******************************* Constants *******************************/
  enum { FIND_FOUND = 0U };

  enum { FIND_NOTFOUND = 1U };

  enum { FIND_WRAPPED = 2U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITypeAheadFind, NS_ITYPEAHEADFIND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITYPEAHEADFIND \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDocShell *aDocShell); \
  NS_SCRIPTABLE NS_IMETHOD Find(const nsAString & aSearchString, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindAgain(PRBool findBackwards, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetDocShell(nsIDocShell *aDocShell); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionModeAndRepaint(PRInt16 toggle); \
  NS_SCRIPTABLE NS_IMETHOD CollapseSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(nsAString & aSearchString); \
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive); \
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive); \
  NS_SCRIPTABLE NS_IMETHOD GetFoundLink(nsIDOMElement * *aFoundLink); \
  NS_SCRIPTABLE NS_IMETHOD GetFoundEditable(nsIDOMElement * *aFoundEditable); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentWindow(nsIDOMWindow * *aCurrentWindow); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITYPEAHEADFIND(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDocShell *aDocShell) { return _to Init(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD Find(const nsAString & aSearchString, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM) { return _to Find(aSearchString, aLinksOnly, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindAgain(PRBool findBackwards, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM) { return _to FindAgain(findBackwards, aLinksOnly, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocShell(nsIDocShell *aDocShell) { return _to SetDocShell(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionModeAndRepaint(PRInt16 toggle) { return _to SetSelectionModeAndRepaint(toggle); } \
  NS_SCRIPTABLE NS_IMETHOD CollapseSelection(void) { return _to CollapseSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(nsAString & aSearchString) { return _to GetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive) { return _to GetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive) { return _to SetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD GetFoundLink(nsIDOMElement * *aFoundLink) { return _to GetFoundLink(aFoundLink); } \
  NS_SCRIPTABLE NS_IMETHOD GetFoundEditable(nsIDOMElement * *aFoundEditable) { return _to GetFoundEditable(aFoundEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentWindow(nsIDOMWindow * *aCurrentWindow) { return _to GetCurrentWindow(aCurrentWindow); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITYPEAHEADFIND(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDocShell *aDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD Find(const nsAString & aSearchString, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Find(aSearchString, aLinksOnly, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindAgain(PRBool findBackwards, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindAgain(findBackwards, aLinksOnly, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocShell(nsIDocShell *aDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocShell(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionModeAndRepaint(PRInt16 toggle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionModeAndRepaint(toggle); } \
  NS_SCRIPTABLE NS_IMETHOD CollapseSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CollapseSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchString(nsAString & aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchString(aSearchString); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaseSensitive(PRBool *aCaseSensitive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaseSensitive(PRBool aCaseSensitive) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaseSensitive(aCaseSensitive); } \
  NS_SCRIPTABLE NS_IMETHOD GetFoundLink(nsIDOMElement * *aFoundLink) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFoundLink(aFoundLink); } \
  NS_SCRIPTABLE NS_IMETHOD GetFoundEditable(nsIDOMElement * *aFoundEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFoundEditable(aFoundEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentWindow(nsIDOMWindow * *aCurrentWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentWindow(aCurrentWindow); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTypeAheadFind : public nsITypeAheadFind
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITYPEAHEADFIND

  nsTypeAheadFind();

private:
  ~nsTypeAheadFind();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTypeAheadFind, nsITypeAheadFind)

nsTypeAheadFind::nsTypeAheadFind()
{
  /* member initializers and constructor code */
}

nsTypeAheadFind::~nsTypeAheadFind()
{
  /* destructor code */
}

/* void init (in nsIDocShell aDocShell); */
NS_IMETHODIMP nsTypeAheadFind::Init(nsIDocShell *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short find (in AString aSearchString, in boolean aLinksOnly); */
NS_IMETHODIMP nsTypeAheadFind::Find(const nsAString & aSearchString, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short findAgain (in boolean findBackwards, in boolean aLinksOnly); */
NS_IMETHODIMP nsTypeAheadFind::FindAgain(PRBool findBackwards, PRBool aLinksOnly, PRUint16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDocShell (in nsIDocShell aDocShell); */
NS_IMETHODIMP nsTypeAheadFind::SetDocShell(nsIDocShell *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionModeAndRepaint (in short toggle); */
NS_IMETHODIMP nsTypeAheadFind::SetSelectionModeAndRepaint(PRInt16 toggle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void collapseSelection (); */
NS_IMETHODIMP nsTypeAheadFind::CollapseSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString searchString; */
NS_IMETHODIMP nsTypeAheadFind::GetSearchString(nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean caseSensitive; */
NS_IMETHODIMP nsTypeAheadFind::GetCaseSensitive(PRBool *aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTypeAheadFind::SetCaseSensitive(PRBool aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement foundLink; */
NS_IMETHODIMP nsTypeAheadFind::GetFoundLink(nsIDOMElement * *aFoundLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement foundEditable; */
NS_IMETHODIMP nsTypeAheadFind::GetFoundEditable(nsIDOMElement * *aFoundEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow currentWindow; */
NS_IMETHODIMP nsTypeAheadFind::GetCurrentWindow(nsIDOMWindow * *aCurrentWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITypeAheadFind_h__ */
