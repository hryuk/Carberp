/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIPlaintextEditor.idl
 */

#ifndef __gen_nsIPlaintextEditor_h__
#define __gen_nsIPlaintextEditor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMKeyEvent; /* forward declaration */


/* starting interface:    nsIPlaintextEditor */
#define NS_IPLAINTEXTEDITOR_IID_STR "1480e196-0d5c-40cf-8563-ed8a33eabcf2"

#define NS_IPLAINTEXTEDITOR_IID \
  {0x1480e196, 0x0d5c, 0x40cf, \
    { 0x85, 0x63, 0xed, 0x8a, 0x33, 0xea, 0xbc, 0xf2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPlaintextEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLAINTEXTEDITOR_IID)

  enum { eEditorPlaintextMask = 1 };

  enum { eEditorSingleLineMask = 2 };

  enum { eEditorPasswordMask = 4 };

  enum { eEditorReadonlyMask = 8 };

  enum { eEditorDisabledMask = 16 };

  enum { eEditorFilterInputMask = 32 };

  enum { eEditorMailMask = 64 };

  enum { eEditorUseAsyncUpdatesMask = 128 };

  enum { eEditorEnableWrapHackMask = 256 };

  enum { eEditorWidgetMask = 512 };

  enum { eEditorNoCSSMask = 1024 };

  enum { eEditorAllowInteraction = 2048 };

  enum { eNewlinesPasteIntact = 0 };

  enum { eNewlinesPasteToFirst = 1 };

  enum { eNewlinesReplaceWithSpaces = 2 };

  enum { eNewlinesStrip = 3 };

  enum { eNewlinesReplaceWithCommas = 4 };

  enum { eNewlinesStripSurroundingWhitespace = 5 };

  /**
    * The length of the contents in characters.
    * XXX change this type to 'unsigned long'
    */
  /* readonly attribute long textLength; */
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) = 0;

  /**
    * The maximum number of characters allowed.
    *   default: -1 (unlimited).
    */
  /* attribute long maxTextLength; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxTextLength(PRInt32 *aMaxTextLength) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMaxTextLength(PRInt32 aMaxTextLength) = 0;

  /** Get and set the body wrap width.
    * 
    * Special values:
    *    0 = wrap to window width
    *   -1 = no wrap at all
    */
  /* attribute long wrapWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetWrapWidth(PRInt32 *aWrapWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWrapWidth(PRInt32 aWrapWidth) = 0;

  /**
   * Similar to the setter for wrapWidth, but just sets the editor
   * internal state without actually changing the content being edited
   * to wrap at that column.  This should only be used by callers who
   * are sure that their content is already set up correctly.
   */
  /* void setWrapColumn (in long aWrapColumn); */
  NS_SCRIPTABLE NS_IMETHOD SetWrapColumn(PRInt32 aWrapColumn) = 0;

  /** Get and set newline handling.
   *
   *  Values are the constants defined above.
   */
  /* attribute long newlineHandling; */
  NS_SCRIPTABLE NS_IMETHOD GetNewlineHandling(PRInt32 *aNewlineHandling) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetNewlineHandling(PRInt32 aNewlineHandling) = 0;

  /** 
   * EditorKeyPress consumes a keyevent.
   * @param aKeyEvent    key event to consume
   */
  /* void handleKeyPress (in nsIDOMKeyEvent aKeyEvent); */
  NS_SCRIPTABLE NS_IMETHOD HandleKeyPress(nsIDOMKeyEvent *aKeyEvent) = 0;

  /**
   * Inserts a string at the current location,
   * given by the selection.
   * If the selection is not collapsed, the selection is deleted
   * and the insertion takes place at the resulting collapsed selection.
   *
   * @param aString   the string to be inserted
   */
  /* void insertText (in DOMString aStringToInsert); */
  NS_SCRIPTABLE NS_IMETHOD InsertText(const nsAString & aStringToInsert) = 0;

  /**
   * Insert a line break into the content model.
   * The interpretation of a break is up to the implementation:
   * it may enter a character, split a node in the tree, etc.
   * This may be more efficient than calling InsertText with a newline.
   */
  /* void insertLineBreak (); */
  NS_SCRIPTABLE NS_IMETHOD InsertLineBreak(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPlaintextEditor, NS_IPLAINTEXTEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLAINTEXTEDITOR \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxTextLength(PRInt32 *aMaxTextLength); \
  NS_SCRIPTABLE NS_IMETHOD SetMaxTextLength(PRInt32 aMaxTextLength); \
  NS_SCRIPTABLE NS_IMETHOD GetWrapWidth(PRInt32 *aWrapWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetWrapWidth(PRInt32 aWrapWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetWrapColumn(PRInt32 aWrapColumn); \
  NS_SCRIPTABLE NS_IMETHOD GetNewlineHandling(PRInt32 *aNewlineHandling); \
  NS_SCRIPTABLE NS_IMETHOD SetNewlineHandling(PRInt32 aNewlineHandling); \
  NS_SCRIPTABLE NS_IMETHOD HandleKeyPress(nsIDOMKeyEvent *aKeyEvent); \
  NS_SCRIPTABLE NS_IMETHOD InsertText(const nsAString & aStringToInsert); \
  NS_SCRIPTABLE NS_IMETHOD InsertLineBreak(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLAINTEXTEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return _to GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxTextLength(PRInt32 *aMaxTextLength) { return _to GetMaxTextLength(aMaxTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxTextLength(PRInt32 aMaxTextLength) { return _to SetMaxTextLength(aMaxTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrapWidth(PRInt32 *aWrapWidth) { return _to GetWrapWidth(aWrapWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapWidth(PRInt32 aWrapWidth) { return _to SetWrapWidth(aWrapWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapColumn(PRInt32 aWrapColumn) { return _to SetWrapColumn(aWrapColumn); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewlineHandling(PRInt32 *aNewlineHandling) { return _to GetNewlineHandling(aNewlineHandling); } \
  NS_SCRIPTABLE NS_IMETHOD SetNewlineHandling(PRInt32 aNewlineHandling) { return _to SetNewlineHandling(aNewlineHandling); } \
  NS_SCRIPTABLE NS_IMETHOD HandleKeyPress(nsIDOMKeyEvent *aKeyEvent) { return _to HandleKeyPress(aKeyEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InsertText(const nsAString & aStringToInsert) { return _to InsertText(aStringToInsert); } \
  NS_SCRIPTABLE NS_IMETHOD InsertLineBreak(void) { return _to InsertLineBreak(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLAINTEXTEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxTextLength(PRInt32 *aMaxTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxTextLength(aMaxTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxTextLength(PRInt32 aMaxTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxTextLength(aMaxTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrapWidth(PRInt32 *aWrapWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrapWidth(aWrapWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapWidth(PRInt32 aWrapWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWrapWidth(aWrapWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapColumn(PRInt32 aWrapColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWrapColumn(aWrapColumn); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewlineHandling(PRInt32 *aNewlineHandling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewlineHandling(aNewlineHandling); } \
  NS_SCRIPTABLE NS_IMETHOD SetNewlineHandling(PRInt32 aNewlineHandling) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNewlineHandling(aNewlineHandling); } \
  NS_SCRIPTABLE NS_IMETHOD HandleKeyPress(nsIDOMKeyEvent *aKeyEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleKeyPress(aKeyEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InsertText(const nsAString & aStringToInsert) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertText(aStringToInsert); } \
  NS_SCRIPTABLE NS_IMETHOD InsertLineBreak(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertLineBreak(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPlaintextEditor : public nsIPlaintextEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLAINTEXTEDITOR

  nsPlaintextEditor();

private:
  ~nsPlaintextEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPlaintextEditor, nsIPlaintextEditor)

nsPlaintextEditor::nsPlaintextEditor()
{
  /* member initializers and constructor code */
}

nsPlaintextEditor::~nsPlaintextEditor()
{
  /* destructor code */
}

/* readonly attribute long textLength; */
NS_IMETHODIMP nsPlaintextEditor::GetTextLength(PRInt32 *aTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxTextLength; */
NS_IMETHODIMP nsPlaintextEditor::GetMaxTextLength(PRInt32 *aMaxTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPlaintextEditor::SetMaxTextLength(PRInt32 aMaxTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long wrapWidth; */
NS_IMETHODIMP nsPlaintextEditor::GetWrapWidth(PRInt32 *aWrapWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPlaintextEditor::SetWrapWidth(PRInt32 aWrapWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWrapColumn (in long aWrapColumn); */
NS_IMETHODIMP nsPlaintextEditor::SetWrapColumn(PRInt32 aWrapColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long newlineHandling; */
NS_IMETHODIMP nsPlaintextEditor::GetNewlineHandling(PRInt32 *aNewlineHandling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPlaintextEditor::SetNewlineHandling(PRInt32 aNewlineHandling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleKeyPress (in nsIDOMKeyEvent aKeyEvent); */
NS_IMETHODIMP nsPlaintextEditor::HandleKeyPress(nsIDOMKeyEvent *aKeyEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertText (in DOMString aStringToInsert); */
NS_IMETHODIMP nsPlaintextEditor::InsertText(const nsAString & aStringToInsert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertLineBreak (); */
NS_IMETHODIMP nsPlaintextEditor::InsertLineBreak()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPlaintextEditor_h__ */
