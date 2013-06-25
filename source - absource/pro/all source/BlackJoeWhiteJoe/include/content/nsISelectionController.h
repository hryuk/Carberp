/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsISelectionController.idl
 */

#ifndef __gen_nsISelectionController_h__
#define __gen_nsISelectionController_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISelection_h__
#include "nsISelection.h"
#endif

#ifndef __gen_nsISelectionDisplay_h__
#include "nsISelectionDisplay.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef short SelectionType;
typedef short SelectionRegion;
class nsIDOMNode; /* forward declaration */

class nsISelection; /* forward declaration */

class nsISelectionDisplay; /* forward declaration */


/* starting interface:    nsISelectionController */
#define NS_ISELECTIONCONTROLLER_IID_STR "b5c3ffc4-f48a-4f25-86e1-4cf79db1bcbb"

#define NS_ISELECTIONCONTROLLER_IID \
  {0xb5c3ffc4, 0xf48a, 0x4f25, \
    { 0x86, 0xe1, 0x4c, 0xf7, 0x9d, 0xb1, 0xbc, 0xbb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISelectionController : public nsISelectionDisplay {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTIONCONTROLLER_IID)

  enum { SELECTION_NONE = 0 };

  enum { SELECTION_NORMAL = 1 };

  enum { SELECTION_SPELLCHECK = 2 };

  enum { SELECTION_IME_RAWINPUT = 4 };

  enum { SELECTION_IME_SELECTEDRAWTEXT = 8 };

  enum { SELECTION_IME_CONVERTEDTEXT = 16 };

  enum { SELECTION_IME_SELECTEDCONVERTEDTEXT = 32 };

  enum { SELECTION_ACCESSIBILITY = 64 };

  enum { SELECTION_FIND = 128 };

  enum { NUM_SELECTIONTYPES = 9 };

  enum { SELECTION_ANCHOR_REGION = 0 };

  enum { SELECTION_FOCUS_REGION = 1 };

  enum { NUM_SELECTION_REGIONS = 2 };

  enum { SELECTION_OFF = 0 };

  enum { SELECTION_HIDDEN = 1 };

  enum { SELECTION_ON = 2 };

  enum { SELECTION_DISABLED = 3 };

  enum { SELECTION_ATTENTION = 4 };

  /**
   * SetDisplaySelection will set the display mode for the selection. OFF,ON,DISABLED
   */
  /* void setDisplaySelection (in short toggle); */
  NS_SCRIPTABLE NS_IMETHOD SetDisplaySelection(PRInt16 toggle) = 0;

  /**
   * GetDisplaySelection will get the display mode for the selection. OFF,ON,DISABLED
   */
  /* short getDisplaySelection (); */
  NS_SCRIPTABLE NS_IMETHOD GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM) = 0;

  /**
   * GetSelection will return the selection that the presentation
   *  shell may implement.
   *
   * @param aType will hold the type of selection //SelectionType
   * @param _return will hold the return value
   */
  /* nsISelection getSelection (in short type); */
  NS_SCRIPTABLE NS_IMETHOD GetSelection(PRInt16 type, nsISelection **_retval NS_OUTPARAM) = 0;

  /**
   * ScrollSelectionIntoView scrolls a region of the selection,
   * so that it is visible in the scrolled view.
   *
   * @param aType the selection to scroll into view. //SelectionType
   * @param aRegion the region inside the selection to scroll into view. //SelectionRegion
   * @param aIsSynchronous when true, scrolls the selection into view
   * before returning. If false, posts a request which is processed
   * at some point after the method returns.
   *
   * Note that if isSynchronous is true, then this might flush the pending
   * reflow. It's dangerous for some objects. See bug 418470 comment 12.
   */
  /* void scrollSelectionIntoView (in short type, in short region, in boolean isSynchronous); */
  NS_SCRIPTABLE NS_IMETHOD ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRBool isSynchronous) = 0;

  /**
   * RepaintSelection repaints the selection specified by aType.
   *
   * @param aType specifies the selection to repaint.
   */
  /* void repaintSelection (in short type); */
  NS_SCRIPTABLE NS_IMETHOD RepaintSelection(PRInt16 type) = 0;

  /**
   * Set the caret as enabled or disabled. An enabled caret will
   * draw or blink when made visible. A disabled caret will never show up.
   * Can be called any time.
   * @param aEnable PR_TRUE to enable caret.  PR_FALSE to disable.
   * @return always NS_OK
   */
  /* void setCaretEnabled (in boolean enabled); */
  NS_SCRIPTABLE NS_IMETHOD SetCaretEnabled(PRBool enabled) = 0;

  /**
   * Set the caret readonly or not. An readonly caret will
   * draw but not blink when made visible. 
   * @param aReadOnly PR_TRUE to enable caret.  PR_FALSE to disable.
   * @return always NS_OK
   */
  /* void setCaretReadOnly (in boolean readOnly); */
  NS_SCRIPTABLE NS_IMETHOD SetCaretReadOnly(PRBool readOnly) = 0;

  /**
   * Gets the current state of the caret.
   * @param aEnabled  [OUT] set to the current caret state, as set by SetCaretEnabled
   * @return   if aOutEnabled==null, returns NS_ERROR_INVALID_ARG
   *           else NS_OK
   */
  /* boolean getCaretEnabled (); */
  NS_SCRIPTABLE NS_IMETHOD GetCaretEnabled(PRBool *_retval NS_OUTPARAM) = 0;

  /**
    * This is true if the caret is enabled, visible, and currently blinking.
    * This is still true when the caret is enabled, visible, but in its "off"
    * blink cycle.
    */
  /* readonly attribute boolean caretVisible; */
  NS_SCRIPTABLE NS_IMETHOD GetCaretVisible(PRBool *aCaretVisible) = 0;

  /**
   * Show the caret even in selections. By default the caret is hidden unless the
   * selection is collapsed. Use this function to show the caret even in selections.
   * @param aVisibility PR_TRUE to show the caret in selections.  PR_FALSE to hide.
   * @return always NS_OK
   */
  /* void setCaretVisibilityDuringSelection (in boolean visibility); */
  NS_SCRIPTABLE NS_IMETHOD SetCaretVisibilityDuringSelection(PRBool visibility) = 0;

  /** CharacterMove will move the selection one character forward/backward in the document.
   *  this will also have the effect of collapsing the selection if the aExtend = PR_FALSE
   *  the "point" of selection that is extended is considered the "focus" point. 
   *  or the last point adjusted by the selection.
   *  @param aForward forward or backward if PR_FALSE
   *  @param aExtend  should it collapse the selection of extend it?
   */
  /* void characterMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD CharacterMove(PRBool forward, PRBool extend) = 0;

  /**
    * CharacterExtendForDelete will extend the selection one character cell
    * forward in the document.
    * this method is used internally for handling del key.
    */
  /* [noscript] void characterExtendForDelete (); */
  NS_IMETHOD CharacterExtendForDelete(void) = 0;

  /** WordMove will move the selection one word forward/backward in the document.
   *  this will also have the effect of collapsing the selection if the aExtend = PR_FALSE
   *  the "point" of selection that is extended is considered the "focus" point. 
   *  or the last point adjusted by the selection.
   *  @param aForward forward or backward if PR_FALSE
   *  @param aExtend  should it collapse the selection of extend it?
   */
  /* void wordMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD WordMove(PRBool forward, PRBool extend) = 0;

  /** wordExtendForDelete will extend the selection one word forward/backward in the document.
   *  this method is used internally for handling ctrl[option]-backspace and ctrl[option]-del.
   *  @param aForward forward or backward if PR_FALSE
   */
  /* [noscript] void wordExtendForDelete (in boolean forward); */
  NS_IMETHOD WordExtendForDelete(PRBool forward) = 0;

  /** LineMove will move the selection one line forward/backward in the document.
   *  this will also have the effect of collapsing the selection if the aExtend = PR_FALSE
   *  the "point" of selection that is extended is considered the "focus" point. 
   *  or the last point adjusted by the selection.
   *  @param aForward forward or backward if PR_FALSE
   *  @param aExtend  should it collapse the selection of extend it?
   */
  /* void lineMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD LineMove(PRBool forward, PRBool extend) = 0;

  /** IntraLineMove will move the selection to the front of the line or end of the line
   *  in the document.
   *  this will also have the effect of collapsing the selection if the aExtend = PR_FALSE
   *  the "point" of selection that is extended is considered the "focus" point. 
   *  or the last point adjusted by the selection.
   *  @param aForward forward or backward if PR_FALSE
   *  @param aExtend  should it collapse the selection of extend it?
   */
  /* void intraLineMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD IntraLineMove(PRBool forward, PRBool extend) = 0;

  /** PageMove will move the selection one page forward/backward in the document.
   *  this will also have the effect of collapsing the selection if the aExtend = PR_FALSE
   *  the "point" of selection that is extended is considered the "focus" point. 
   *  or the last point adjusted by the selection.
   *  @param aForward forward or backward if PR_FALSE
   *  @param aExtend  should it collapse the selection of extend it?
   */
  /* void pageMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD PageMove(PRBool forward, PRBool extend) = 0;

  /** CompleteScroll will move page view to the top or bottom of the document
   *  @param aForward forward or backward if PR_FALSE
   */
  /* void completeScroll (in boolean forward); */
  NS_SCRIPTABLE NS_IMETHOD CompleteScroll(PRBool forward) = 0;

  /** CompleteMove will move page view to the top or bottom of the document
   *  this will also have the effect of collapsing the selection if the aExtend = PR_FALSE
   *  the "point" of selection that is extended is considered the "focus" point. 
   *  or the last point adjusted by the selection.
   *  @param aForward forward or backward if PR_FALSE
   *  @param aExtend  should it collapse the selection of extend it?
   */
  /* void completeMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD CompleteMove(PRBool forward, PRBool extend) = 0;

  /** ScrollPage will scroll the page without affecting the selection.
   *  @param aForward scroll forward or backwards in selection
   */
  /* void scrollPage (in boolean forward); */
  NS_SCRIPTABLE NS_IMETHOD ScrollPage(PRBool forward) = 0;

  /** ScrolLine will scroll line up or down dependent on the boolean
   *  @param aForward scroll forward or backwards in selection
   */
  /* void scrollLine (in boolean forward); */
  NS_SCRIPTABLE NS_IMETHOD ScrollLine(PRBool forward) = 0;

  /** ScrolHorizontal will scroll left or right dependent on the boolean
   *  @param aLeft if true will scroll left. if not will scroll right.
   */
  /* void scrollHorizontal (in boolean left); */
  NS_SCRIPTABLE NS_IMETHOD ScrollHorizontal(PRBool left) = 0;

  /** SelectAll will select the whole page
   */
  /* void selectAll (); */
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) = 0;

  /** CheckVisibility will return true if textnode and offsets are actually rendered 
   *  in the current precontext.
   *  @param aNode textNode to test
   *  @param aStartOffset  offset in dom to first char of textnode to test
   *  @param aEndOffset    offset in dom to last char of textnode to test
   *  @param aReturnBool   boolean returned TRUE if visible FALSE if not
   */
  /* boolean checkVisibility (in nsIDOMNode node, in short startOffset, in short endOffset); */
  NS_SCRIPTABLE NS_IMETHOD CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelectionController, NS_ISELECTIONCONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTIONCONTROLLER \
  NS_SCRIPTABLE NS_IMETHOD SetDisplaySelection(PRInt16 toggle); \
  NS_SCRIPTABLE NS_IMETHOD GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(PRInt16 type, nsISelection **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRBool isSynchronous); \
  NS_SCRIPTABLE NS_IMETHOD RepaintSelection(PRInt16 type); \
  NS_SCRIPTABLE NS_IMETHOD SetCaretEnabled(PRBool enabled); \
  NS_SCRIPTABLE NS_IMETHOD SetCaretReadOnly(PRBool readOnly); \
  NS_SCRIPTABLE NS_IMETHOD GetCaretEnabled(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCaretVisible(PRBool *aCaretVisible); \
  NS_SCRIPTABLE NS_IMETHOD SetCaretVisibilityDuringSelection(PRBool visibility); \
  NS_SCRIPTABLE NS_IMETHOD CharacterMove(PRBool forward, PRBool extend); \
  NS_IMETHOD CharacterExtendForDelete(void); \
  NS_SCRIPTABLE NS_IMETHOD WordMove(PRBool forward, PRBool extend); \
  NS_IMETHOD WordExtendForDelete(PRBool forward); \
  NS_SCRIPTABLE NS_IMETHOD LineMove(PRBool forward, PRBool extend); \
  NS_SCRIPTABLE NS_IMETHOD IntraLineMove(PRBool forward, PRBool extend); \
  NS_SCRIPTABLE NS_IMETHOD PageMove(PRBool forward, PRBool extend); \
  NS_SCRIPTABLE NS_IMETHOD CompleteScroll(PRBool forward); \
  NS_SCRIPTABLE NS_IMETHOD CompleteMove(PRBool forward, PRBool extend); \
  NS_SCRIPTABLE NS_IMETHOD ScrollPage(PRBool forward); \
  NS_SCRIPTABLE NS_IMETHOD ScrollLine(PRBool forward); \
  NS_SCRIPTABLE NS_IMETHOD ScrollHorizontal(PRBool left); \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void); \
  NS_SCRIPTABLE NS_IMETHOD CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTIONCONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetDisplaySelection(PRInt16 toggle) { return _to SetDisplaySelection(toggle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM) { return _to GetDisplaySelection(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(PRInt16 type, nsISelection **_retval NS_OUTPARAM) { return _to GetSelection(type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRBool isSynchronous) { return _to ScrollSelectionIntoView(type, region, isSynchronous); } \
  NS_SCRIPTABLE NS_IMETHOD RepaintSelection(PRInt16 type) { return _to RepaintSelection(type); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretEnabled(PRBool enabled) { return _to SetCaretEnabled(enabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretReadOnly(PRBool readOnly) { return _to SetCaretReadOnly(readOnly); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaretEnabled(PRBool *_retval NS_OUTPARAM) { return _to GetCaretEnabled(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaretVisible(PRBool *aCaretVisible) { return _to GetCaretVisible(aCaretVisible); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretVisibilityDuringSelection(PRBool visibility) { return _to SetCaretVisibilityDuringSelection(visibility); } \
  NS_SCRIPTABLE NS_IMETHOD CharacterMove(PRBool forward, PRBool extend) { return _to CharacterMove(forward, extend); } \
  NS_IMETHOD CharacterExtendForDelete(void) { return _to CharacterExtendForDelete(); } \
  NS_SCRIPTABLE NS_IMETHOD WordMove(PRBool forward, PRBool extend) { return _to WordMove(forward, extend); } \
  NS_IMETHOD WordExtendForDelete(PRBool forward) { return _to WordExtendForDelete(forward); } \
  NS_SCRIPTABLE NS_IMETHOD LineMove(PRBool forward, PRBool extend) { return _to LineMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD IntraLineMove(PRBool forward, PRBool extend) { return _to IntraLineMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD PageMove(PRBool forward, PRBool extend) { return _to PageMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteScroll(PRBool forward) { return _to CompleteScroll(forward); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteMove(PRBool forward, PRBool extend) { return _to CompleteMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollPage(PRBool forward) { return _to ScrollPage(forward); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollLine(PRBool forward) { return _to ScrollLine(forward); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollHorizontal(PRBool left) { return _to ScrollHorizontal(left); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return _to SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, PRBool *_retval NS_OUTPARAM) { return _to CheckVisibility(node, startOffset, endOffset, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTIONCONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetDisplaySelection(PRInt16 toggle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplaySelection(toggle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplaySelection(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(PRInt16 type, nsISelection **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRBool isSynchronous) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollSelectionIntoView(type, region, isSynchronous); } \
  NS_SCRIPTABLE NS_IMETHOD RepaintSelection(PRInt16 type) { return !_to ? NS_ERROR_NULL_POINTER : _to->RepaintSelection(type); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretEnabled(PRBool enabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretEnabled(enabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretReadOnly(PRBool readOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretReadOnly(readOnly); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaretEnabled(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaretEnabled(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaretVisible(PRBool *aCaretVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaretVisible(aCaretVisible); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretVisibilityDuringSelection(PRBool visibility) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretVisibilityDuringSelection(visibility); } \
  NS_SCRIPTABLE NS_IMETHOD CharacterMove(PRBool forward, PRBool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->CharacterMove(forward, extend); } \
  NS_IMETHOD CharacterExtendForDelete(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CharacterExtendForDelete(); } \
  NS_SCRIPTABLE NS_IMETHOD WordMove(PRBool forward, PRBool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->WordMove(forward, extend); } \
  NS_IMETHOD WordExtendForDelete(PRBool forward) { return !_to ? NS_ERROR_NULL_POINTER : _to->WordExtendForDelete(forward); } \
  NS_SCRIPTABLE NS_IMETHOD LineMove(PRBool forward, PRBool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->LineMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD IntraLineMove(PRBool forward, PRBool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->IntraLineMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD PageMove(PRBool forward, PRBool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->PageMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteScroll(PRBool forward) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompleteScroll(forward); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteMove(PRBool forward, PRBool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompleteMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollPage(PRBool forward) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollPage(forward); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollLine(PRBool forward) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollLine(forward); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollHorizontal(PRBool left) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollHorizontal(left); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckVisibility(node, startOffset, endOffset, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelectionController : public nsISelectionController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTIONCONTROLLER

  nsSelectionController();

private:
  ~nsSelectionController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSelectionController, nsISelectionController)

nsSelectionController::nsSelectionController()
{
  /* member initializers and constructor code */
}

nsSelectionController::~nsSelectionController()
{
  /* destructor code */
}

/* void setDisplaySelection (in short toggle); */
NS_IMETHODIMP nsSelectionController::SetDisplaySelection(PRInt16 toggle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short getDisplaySelection (); */
NS_IMETHODIMP nsSelectionController::GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISelection getSelection (in short type); */
NS_IMETHODIMP nsSelectionController::GetSelection(PRInt16 type, nsISelection **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollSelectionIntoView (in short type, in short region, in boolean isSynchronous); */
NS_IMETHODIMP nsSelectionController::ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRBool isSynchronous)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void repaintSelection (in short type); */
NS_IMETHODIMP nsSelectionController::RepaintSelection(PRInt16 type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretEnabled (in boolean enabled); */
NS_IMETHODIMP nsSelectionController::SetCaretEnabled(PRBool enabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretReadOnly (in boolean readOnly); */
NS_IMETHODIMP nsSelectionController::SetCaretReadOnly(PRBool readOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getCaretEnabled (); */
NS_IMETHODIMP nsSelectionController::GetCaretEnabled(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean caretVisible; */
NS_IMETHODIMP nsSelectionController::GetCaretVisible(PRBool *aCaretVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretVisibilityDuringSelection (in boolean visibility); */
NS_IMETHODIMP nsSelectionController::SetCaretVisibilityDuringSelection(PRBool visibility)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void characterMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::CharacterMove(PRBool forward, PRBool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void characterExtendForDelete (); */
NS_IMETHODIMP nsSelectionController::CharacterExtendForDelete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wordMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::WordMove(PRBool forward, PRBool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void wordExtendForDelete (in boolean forward); */
NS_IMETHODIMP nsSelectionController::WordExtendForDelete(PRBool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lineMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::LineMove(PRBool forward, PRBool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void intraLineMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::IntraLineMove(PRBool forward, PRBool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pageMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::PageMove(PRBool forward, PRBool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completeScroll (in boolean forward); */
NS_IMETHODIMP nsSelectionController::CompleteScroll(PRBool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completeMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::CompleteMove(PRBool forward, PRBool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollPage (in boolean forward); */
NS_IMETHODIMP nsSelectionController::ScrollPage(PRBool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollLine (in boolean forward); */
NS_IMETHODIMP nsSelectionController::ScrollLine(PRBool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollHorizontal (in boolean left); */
NS_IMETHODIMP nsSelectionController::ScrollHorizontal(PRBool left)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsSelectionController::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkVisibility (in nsIDOMNode node, in short startOffset, in short endOffset); */
NS_IMETHODIMP nsSelectionController::CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

   #define NS_ISELECTIONCONTROLLER_CID \
   { 0x513b9460, 0xd56a, 0x4c4e, \
   { 0xb6, 0xf9, 0x0b, 0x8a, 0xe4, 0x37, 0x2a, 0x3b }}

#endif /* __gen_nsISelectionController_h__ */
