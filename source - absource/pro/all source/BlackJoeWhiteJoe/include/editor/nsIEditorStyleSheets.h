/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIEditorStyleSheets.idl
 */

#ifndef __gen_nsIEditorStyleSheets_h__
#define __gen_nsIEditorStyleSheets_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICSSStyleSheet;

/* starting interface:    nsIEditorStyleSheets */
#define NS_IEDITORSTYLESHEETS_IID_STR "4805e682-49b9-11d3-9ce4-ed60bd6cb5bc"

#define NS_IEDITORSTYLESHEETS_IID \
  {0x4805e682, 0x49b9, 0x11d3, \
    { 0x9c, 0xe4, 0xed, 0x60, 0xbd, 0x6c, 0xb5, 0xbc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIEditorStyleSheets : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORSTYLESHEETS_IID)

  /** load and apply the style sheet, specified by aURL, to the
    * editor's document, replacing the last style sheet added (if any).
    * This can involve asynchronous network I/O.
    * 
    * @param aURL         The style sheet to be loaded and applied.
    */
  /* void replaceStyleSheet (in AString aURL); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceStyleSheet(const nsAString & aURL) = 0;

  /** Add the given Style Sheet to the editor's document,
    * on top of any that are already there.
    * This is always synchronous.
    *
    * @param aURL  The style sheet to be  applied.
    */
  /* void addStyleSheet (in AString aURL); */
  NS_SCRIPTABLE NS_IMETHOD AddStyleSheet(const nsAString & aURL) = 0;

  /** load and apply the style sheet, specified by aURL, to the
    * editor's document, replacing the last style sheet added (if any).
    * This is always synchronous.
    * 
    * @param aURL         The style sheet to be loaded and applied.
    */
  /* void replaceOverrideStyleSheet (in AString aURL); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceOverrideStyleSheet(const nsAString & aURL) = 0;

  /** load and apply an Override style sheet, specified by aURL, to
    * the editor's document, on top of any that are already there.
    * IMPORTANT: This is assumed to be synchronous:
    *            URL is a local file with no @import used
    * This action is not undoable.
    * It is not intended for use by "user", only editor developers
    *   to change display behavior for editing (like showing special cursors)
    *   that will not be affected by loading other "document" style sheets
    *   loaded using addStyleSheet or replaceStyleSheet.
    *
    * @param aURL         The style sheet to be loaded and applied.
    */
  /* void addOverrideStyleSheet (in AString aURL); */
  NS_SCRIPTABLE NS_IMETHOD AddOverrideStyleSheet(const nsAString & aURL) = 0;

  /** Remove the given Style Sheet from the editor's document
    * This is always synchronous
    *
    * @param aURL  The style sheet to be removed
    */
  /* void removeStyleSheet (in AString aURL); */
  NS_SCRIPTABLE NS_IMETHOD RemoveStyleSheet(const nsAString & aURL) = 0;

  /** Remove the given Override Style Sheet from the editor's document
    * This is always synchronous
    *
    * @param aURL  The style sheet to be removed.
    */
  /* void removeOverrideStyleSheet (in AString aURL); */
  NS_SCRIPTABLE NS_IMETHOD RemoveOverrideStyleSheet(const nsAString & aURL) = 0;

  /** Enable or disable the given Style Sheet from the editor's document
    * This is always synchronous
    *
    * @param aURL  The style sheet to be removed
    */
  /* void enableStyleSheet (in AString aURL, in PRBool aEnable); */
  NS_SCRIPTABLE NS_IMETHOD EnableStyleSheet(const nsAString & aURL, PRBool aEnable) = 0;

  /** Get the nsICSSStyleSheet associated with the given URL.
    *
    * @param aURL         The style sheet's URL
    * @return             the style sheet
    */
  /* [noscript] nsICSSStyleSheet getStyleSheetForURL (in AString aURL); */
  NS_IMETHOD GetStyleSheetForURL(const nsAString & aURL, nsICSSStyleSheet * *_retval NS_OUTPARAM) = 0;

  /** Get the URL associated with the given nsICSSStyleSheet.
    *
    * @param aStyleSheet  The style sheet
    * @return             the style sheet's URL
    */
  /* [noscript] AString getURLForStyleSheet (in nsICSSStyleSheet aStyleSheet); */
  NS_IMETHOD GetURLForStyleSheet(nsICSSStyleSheet * aStyleSheet, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorStyleSheets, NS_IEDITORSTYLESHEETS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORSTYLESHEETS \
  NS_SCRIPTABLE NS_IMETHOD ReplaceStyleSheet(const nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD AddStyleSheet(const nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD ReplaceOverrideStyleSheet(const nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD AddOverrideStyleSheet(const nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD RemoveStyleSheet(const nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD RemoveOverrideStyleSheet(const nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD EnableStyleSheet(const nsAString & aURL, PRBool aEnable); \
  NS_IMETHOD GetStyleSheetForURL(const nsAString & aURL, nsICSSStyleSheet * *_retval NS_OUTPARAM); \
  NS_IMETHOD GetURLForStyleSheet(nsICSSStyleSheet * aStyleSheet, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORSTYLESHEETS(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReplaceStyleSheet(const nsAString & aURL) { return _to ReplaceStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD AddStyleSheet(const nsAString & aURL) { return _to AddStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceOverrideStyleSheet(const nsAString & aURL) { return _to ReplaceOverrideStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD AddOverrideStyleSheet(const nsAString & aURL) { return _to AddOverrideStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveStyleSheet(const nsAString & aURL) { return _to RemoveStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveOverrideStyleSheet(const nsAString & aURL) { return _to RemoveOverrideStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD EnableStyleSheet(const nsAString & aURL, PRBool aEnable) { return _to EnableStyleSheet(aURL, aEnable); } \
  NS_IMETHOD GetStyleSheetForURL(const nsAString & aURL, nsICSSStyleSheet * *_retval NS_OUTPARAM) { return _to GetStyleSheetForURL(aURL, _retval); } \
  NS_IMETHOD GetURLForStyleSheet(nsICSSStyleSheet * aStyleSheet, nsAString & _retval NS_OUTPARAM) { return _to GetURLForStyleSheet(aStyleSheet, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORSTYLESHEETS(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReplaceStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD AddStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceOverrideStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceOverrideStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD AddOverrideStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddOverrideStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveOverrideStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveOverrideStyleSheet(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD EnableStyleSheet(const nsAString & aURL, PRBool aEnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableStyleSheet(aURL, aEnable); } \
  NS_IMETHOD GetStyleSheetForURL(const nsAString & aURL, nsICSSStyleSheet * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleSheetForURL(aURL, _retval); } \
  NS_IMETHOD GetURLForStyleSheet(nsICSSStyleSheet * aStyleSheet, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURLForStyleSheet(aStyleSheet, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorStyleSheets : public nsIEditorStyleSheets
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITORSTYLESHEETS

  nsEditorStyleSheets();

private:
  ~nsEditorStyleSheets();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorStyleSheets, nsIEditorStyleSheets)

nsEditorStyleSheets::nsEditorStyleSheets()
{
  /* member initializers and constructor code */
}

nsEditorStyleSheets::~nsEditorStyleSheets()
{
  /* destructor code */
}

/* void replaceStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::ReplaceStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::AddStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceOverrideStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::ReplaceOverrideStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addOverrideStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::AddOverrideStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::RemoveStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeOverrideStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::RemoveOverrideStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableStyleSheet (in AString aURL, in PRBool aEnable); */
NS_IMETHODIMP nsEditorStyleSheets::EnableStyleSheet(const nsAString & aURL, PRBool aEnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsICSSStyleSheet getStyleSheetForURL (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::GetStyleSheetForURL(const nsAString & aURL, nsICSSStyleSheet * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString getURLForStyleSheet (in nsICSSStyleSheet aStyleSheet); */
NS_IMETHODIMP nsEditorStyleSheets::GetURLForStyleSheet(nsICSSStyleSheet * aStyleSheet, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorStyleSheets_h__ */
