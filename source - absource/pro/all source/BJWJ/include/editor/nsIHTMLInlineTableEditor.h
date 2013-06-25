/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIHTMLInlineTableEditor.idl
 */

#ifndef __gen_nsIHTMLInlineTableEditor_h__
#define __gen_nsIHTMLInlineTableEditor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHTMLInlineTableEditor */
#define NS_IHTMLINLINETABLEEDITOR_IID_STR "eda2e65c-a758-451f-9b05-77cb8de74ed2"

#define NS_IHTMLINLINETABLEEDITOR_IID \
  {0xeda2e65c, 0xa758, 0x451f, \
    { 0x9b, 0x05, 0x77, 0xcb, 0x8d, 0xe7, 0x4e, 0xd2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIHTMLInlineTableEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLINLINETABLEEDITOR_IID)

  /**
   * boolean indicating if inline table editing is enabled in the editor.
   * When inline table editing is enabled, and when the selection is
   * contained in a table cell, special buttons allowing to add/remove
   * a line/column are available on the cell's border.
   */
  /* attribute boolean inlineTableEditingEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetInlineTableEditingEnabled(PRBool *aInlineTableEditingEnabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInlineTableEditingEnabled(PRBool aInlineTableEditingEnabled) = 0;

  /**
   * Shows inline table editing UI around a table cell
   * @param aCell [IN] a DOM Element being a table cell, td or th
   */
  /* void showInlineTableEditingUI (in nsIDOMElement aCell); */
  NS_SCRIPTABLE NS_IMETHOD ShowInlineTableEditingUI(nsIDOMElement *aCell) = 0;

  /**
   * Hide all inline table editing UI
   */
  /* void hideInlineTableEditingUI (); */
  NS_SCRIPTABLE NS_IMETHOD HideInlineTableEditingUI(void) = 0;

  /**
   * Modifies the table containing the selection according to the
   * activation of an inline table editing UI element
   * @param aUIAnonymousElement [IN] the inline table editing UI element
   */
  /* void doInlineTableEditingAction (in nsIDOMElement aUIAnonymousElement); */
  NS_SCRIPTABLE NS_IMETHOD DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement) = 0;

  /**
   * Refresh already visible inline table editing UI
   */
  /* void refreshInlineTableEditingUI (); */
  NS_SCRIPTABLE NS_IMETHOD RefreshInlineTableEditingUI(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLInlineTableEditor, NS_IHTMLINLINETABLEEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLINLINETABLEEDITOR \
  NS_SCRIPTABLE NS_IMETHOD GetInlineTableEditingEnabled(PRBool *aInlineTableEditingEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetInlineTableEditingEnabled(PRBool aInlineTableEditingEnabled); \
  NS_SCRIPTABLE NS_IMETHOD ShowInlineTableEditingUI(nsIDOMElement *aCell); \
  NS_SCRIPTABLE NS_IMETHOD HideInlineTableEditingUI(void); \
  NS_SCRIPTABLE NS_IMETHOD DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement); \
  NS_SCRIPTABLE NS_IMETHOD RefreshInlineTableEditingUI(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLINLINETABLEEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInlineTableEditingEnabled(PRBool *aInlineTableEditingEnabled) { return _to GetInlineTableEditingEnabled(aInlineTableEditingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetInlineTableEditingEnabled(PRBool aInlineTableEditingEnabled) { return _to SetInlineTableEditingEnabled(aInlineTableEditingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD ShowInlineTableEditingUI(nsIDOMElement *aCell) { return _to ShowInlineTableEditingUI(aCell); } \
  NS_SCRIPTABLE NS_IMETHOD HideInlineTableEditingUI(void) { return _to HideInlineTableEditingUI(); } \
  NS_SCRIPTABLE NS_IMETHOD DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement) { return _to DoInlineTableEditingAction(aUIAnonymousElement); } \
  NS_SCRIPTABLE NS_IMETHOD RefreshInlineTableEditingUI(void) { return _to RefreshInlineTableEditingUI(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLINLINETABLEEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInlineTableEditingEnabled(PRBool *aInlineTableEditingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInlineTableEditingEnabled(aInlineTableEditingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetInlineTableEditingEnabled(PRBool aInlineTableEditingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInlineTableEditingEnabled(aInlineTableEditingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD ShowInlineTableEditingUI(nsIDOMElement *aCell) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowInlineTableEditingUI(aCell); } \
  NS_SCRIPTABLE NS_IMETHOD HideInlineTableEditingUI(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HideInlineTableEditingUI(); } \
  NS_SCRIPTABLE NS_IMETHOD DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoInlineTableEditingAction(aUIAnonymousElement); } \
  NS_SCRIPTABLE NS_IMETHOD RefreshInlineTableEditingUI(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshInlineTableEditingUI(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLInlineTableEditor : public nsIHTMLInlineTableEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLINLINETABLEEDITOR

  nsHTMLInlineTableEditor();

private:
  ~nsHTMLInlineTableEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTMLInlineTableEditor, nsIHTMLInlineTableEditor)

nsHTMLInlineTableEditor::nsHTMLInlineTableEditor()
{
  /* member initializers and constructor code */
}

nsHTMLInlineTableEditor::~nsHTMLInlineTableEditor()
{
  /* destructor code */
}

/* attribute boolean inlineTableEditingEnabled; */
NS_IMETHODIMP nsHTMLInlineTableEditor::GetInlineTableEditingEnabled(PRBool *aInlineTableEditingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLInlineTableEditor::SetInlineTableEditingEnabled(PRBool aInlineTableEditingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showInlineTableEditingUI (in nsIDOMElement aCell); */
NS_IMETHODIMP nsHTMLInlineTableEditor::ShowInlineTableEditingUI(nsIDOMElement *aCell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hideInlineTableEditingUI (); */
NS_IMETHODIMP nsHTMLInlineTableEditor::HideInlineTableEditingUI()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doInlineTableEditingAction (in nsIDOMElement aUIAnonymousElement); */
NS_IMETHODIMP nsHTMLInlineTableEditor::DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshInlineTableEditingUI (); */
NS_IMETHODIMP nsHTMLInlineTableEditor::RefreshInlineTableEditingUI()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLInlineTableEditor_h__ */
