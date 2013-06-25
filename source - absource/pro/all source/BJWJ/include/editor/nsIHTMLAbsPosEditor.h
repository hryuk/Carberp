/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIHTMLAbsPosEditor.idl
 */

#ifndef __gen_nsIHTMLAbsPosEditor_h__
#define __gen_nsIHTMLAbsPosEditor_h__


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

/* starting interface:    nsIHTMLAbsPosEditor */
#define NS_IHTMLABSPOSEDITOR_IID_STR "91375f52-20e6-4757-9835-eb04fabe5498"

#define NS_IHTMLABSPOSEDITOR_IID \
  {0x91375f52, 0x20e6, 0x4757, \
    { 0x98, 0x35, 0xeb, 0x04, 0xfa, 0xbe, 0x54, 0x98 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIHTMLAbsPosEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLABSPOSEDITOR_IID)

  /**
   * true if the selection container is absolutely positioned
   */
  /* readonly attribute boolean selectionContainerAbsolutelyPositioned; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionContainerAbsolutelyPositioned(PRBool *aSelectionContainerAbsolutelyPositioned) = 0;

  /**
   * this contains the absolutely positioned element currently edited
   * or null
   */
  /* readonly attribute nsIDOMElement positionedElement; */
  NS_SCRIPTABLE NS_IMETHOD GetPositionedElement(nsIDOMElement * *aPositionedElement) = 0;

  /**
   * true if Absolute Positioning handling is enabled in the editor
   */
  /* attribute boolean absolutePositioningEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetAbsolutePositioningEnabled(PRBool *aAbsolutePositioningEnabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAbsolutePositioningEnabled(PRBool aAbsolutePositioningEnabled) = 0;

  /**
   * true if Snap To Grid is enabled in the editor.
   */
  /* attribute boolean snapToGridEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetSnapToGridEnabled(PRBool *aSnapToGridEnabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSnapToGridEnabled(PRBool aSnapToGridEnabled) = 0;

  /**
   * sets the grid size in pixels.
   * @param aSizeInPixels [IN] the size of the grid in pixels
   */
  /* attribute unsigned long gridSize; */
  NS_SCRIPTABLE NS_IMETHOD GetGridSize(PRUint32 *aGridSize) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetGridSize(PRUint32 aGridSize) = 0;

  /**
   * returns the deepest absolutely positioned container of the selection
   * if it exists or null.
   */
  /* readonly attribute nsIDOMElement absolutelyPositionedSelectionContainer; */
  NS_SCRIPTABLE NS_IMETHOD GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer) = 0;

  /**
   * extracts the selection from the normal flow of the document and
   * positions it.
   * @param aEnabled [IN] true to absolutely position the selection,
   *                      false to put it back in the normal flow
   */
  /* void absolutePositionSelection (in boolean aEnabled); */
  NS_SCRIPTABLE NS_IMETHOD AbsolutePositionSelection(PRBool aEnabled) = 0;

  /**
   * adds aChange to the z-index of the currently positioned element.
   * @param aChange [IN] relative change to apply to current z-index
   */
  /* void relativeChangeZIndex (in long aChange); */
  NS_SCRIPTABLE NS_IMETHOD RelativeChangeZIndex(PRInt32 aChange) = 0;

  /**
   * extracts an element from the normal flow of the document and
   * positions it, and puts it back in the normal flow.
   * @param aElement [IN] the element
   * @param aEnabled [IN] true to absolutely position the element,
   *                      false to put it back in the normal flow
   */
  /* void absolutelyPositionElement (in nsIDOMElement aElement, in boolean aEnabled); */
  NS_SCRIPTABLE NS_IMETHOD AbsolutelyPositionElement(nsIDOMElement *aElement, PRBool aEnabled) = 0;

  /**
   * sets the position of an element; warning it does NOT check if the
   * element is already positioned or not and that's on purpose.
   * @param aElement [IN] the element
   * @param aX       [IN] the x position in pixels.
   * @param aY       [IN] the y position in pixels.
   */
  /* void setElementPosition (in nsIDOMElement aElement, in long aX, in long aY); */
  NS_SCRIPTABLE NS_IMETHOD SetElementPosition(nsIDOMElement *aElement, PRInt32 aX, PRInt32 aY) = 0;

  /**
   * returns the absolute z-index of a positioned element. Never returns 'auto'.
   * @return         the z-index of the element
   * @param aElement [IN] the element.
   */
  /* long getElementZIndex (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD GetElementZIndex(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * sets the z-index of an element.
   * @param aElement [IN] the element
   * @param aZorder  [IN] the z-index
   */
  /* void setElementZIndex (in nsIDOMElement aElement, in long aZorder); */
  NS_SCRIPTABLE NS_IMETHOD SetElementZIndex(nsIDOMElement *aElement, PRInt32 aZorder) = 0;

  /**
   * adds aChange to the z-index of an arbitrary element.
   * @return         the new z-index of the element
   * @param aElement [IN] the element
   * @param aChange  [IN] relative change to apply to current z-index of
   *                      the element
   */
  /* long relativeChangeElementZIndex (in nsIDOMElement aElement, in long aChange); */
  NS_SCRIPTABLE NS_IMETHOD RelativeChangeElementZIndex(nsIDOMElement *aElement, PRInt32 aChange, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * shows a grabber attached to an arbitrary element. The grabber is an image
   * positioned on the left hand side of the top border of the element. Dragging
   * and dropping it allows to change the element's absolute position in the
   * document. See chrome://editor/content/images/grabber.gif
   * @param aElement [IN] the element
   */
  /* void showGrabberOnElement (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD ShowGrabberOnElement(nsIDOMElement *aElement) = 0;

  /**
   * hide the grabber if it shown.
   */
  /* void hideGrabber (); */
  NS_SCRIPTABLE NS_IMETHOD HideGrabber(void) = 0;

  /**
   * refreshes the grabber if it shown, possibly updating its position or
   * even hiding it.
   */
  /* void refreshGrabber (); */
  NS_SCRIPTABLE NS_IMETHOD RefreshGrabber(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLAbsPosEditor, NS_IHTMLABSPOSEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLABSPOSEDITOR \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionContainerAbsolutelyPositioned(PRBool *aSelectionContainerAbsolutelyPositioned); \
  NS_SCRIPTABLE NS_IMETHOD GetPositionedElement(nsIDOMElement * *aPositionedElement); \
  NS_SCRIPTABLE NS_IMETHOD GetAbsolutePositioningEnabled(PRBool *aAbsolutePositioningEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetAbsolutePositioningEnabled(PRBool aAbsolutePositioningEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetSnapToGridEnabled(PRBool *aSnapToGridEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetSnapToGridEnabled(PRBool aSnapToGridEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetGridSize(PRUint32 *aGridSize); \
  NS_SCRIPTABLE NS_IMETHOD SetGridSize(PRUint32 aGridSize); \
  NS_SCRIPTABLE NS_IMETHOD GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer); \
  NS_SCRIPTABLE NS_IMETHOD AbsolutePositionSelection(PRBool aEnabled); \
  NS_SCRIPTABLE NS_IMETHOD RelativeChangeZIndex(PRInt32 aChange); \
  NS_SCRIPTABLE NS_IMETHOD AbsolutelyPositionElement(nsIDOMElement *aElement, PRBool aEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetElementPosition(nsIDOMElement *aElement, PRInt32 aX, PRInt32 aY); \
  NS_SCRIPTABLE NS_IMETHOD GetElementZIndex(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetElementZIndex(nsIDOMElement *aElement, PRInt32 aZorder); \
  NS_SCRIPTABLE NS_IMETHOD RelativeChangeElementZIndex(nsIDOMElement *aElement, PRInt32 aChange, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ShowGrabberOnElement(nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD HideGrabber(void); \
  NS_SCRIPTABLE NS_IMETHOD RefreshGrabber(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLABSPOSEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionContainerAbsolutelyPositioned(PRBool *aSelectionContainerAbsolutelyPositioned) { return _to GetSelectionContainerAbsolutelyPositioned(aSelectionContainerAbsolutelyPositioned); } \
  NS_SCRIPTABLE NS_IMETHOD GetPositionedElement(nsIDOMElement * *aPositionedElement) { return _to GetPositionedElement(aPositionedElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetAbsolutePositioningEnabled(PRBool *aAbsolutePositioningEnabled) { return _to GetAbsolutePositioningEnabled(aAbsolutePositioningEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetAbsolutePositioningEnabled(PRBool aAbsolutePositioningEnabled) { return _to SetAbsolutePositioningEnabled(aAbsolutePositioningEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetSnapToGridEnabled(PRBool *aSnapToGridEnabled) { return _to GetSnapToGridEnabled(aSnapToGridEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetSnapToGridEnabled(PRBool aSnapToGridEnabled) { return _to SetSnapToGridEnabled(aSnapToGridEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetGridSize(PRUint32 *aGridSize) { return _to GetGridSize(aGridSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetGridSize(PRUint32 aGridSize) { return _to SetGridSize(aGridSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer) { return _to GetAbsolutelyPositionedSelectionContainer(aAbsolutelyPositionedSelectionContainer); } \
  NS_SCRIPTABLE NS_IMETHOD AbsolutePositionSelection(PRBool aEnabled) { return _to AbsolutePositionSelection(aEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD RelativeChangeZIndex(PRInt32 aChange) { return _to RelativeChangeZIndex(aChange); } \
  NS_SCRIPTABLE NS_IMETHOD AbsolutelyPositionElement(nsIDOMElement *aElement, PRBool aEnabled) { return _to AbsolutelyPositionElement(aElement, aEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetElementPosition(nsIDOMElement *aElement, PRInt32 aX, PRInt32 aY) { return _to SetElementPosition(aElement, aX, aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementZIndex(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM) { return _to GetElementZIndex(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetElementZIndex(nsIDOMElement *aElement, PRInt32 aZorder) { return _to SetElementZIndex(aElement, aZorder); } \
  NS_SCRIPTABLE NS_IMETHOD RelativeChangeElementZIndex(nsIDOMElement *aElement, PRInt32 aChange, PRInt32 *_retval NS_OUTPARAM) { return _to RelativeChangeElementZIndex(aElement, aChange, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShowGrabberOnElement(nsIDOMElement *aElement) { return _to ShowGrabberOnElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD HideGrabber(void) { return _to HideGrabber(); } \
  NS_SCRIPTABLE NS_IMETHOD RefreshGrabber(void) { return _to RefreshGrabber(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLABSPOSEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionContainerAbsolutelyPositioned(PRBool *aSelectionContainerAbsolutelyPositioned) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionContainerAbsolutelyPositioned(aSelectionContainerAbsolutelyPositioned); } \
  NS_SCRIPTABLE NS_IMETHOD GetPositionedElement(nsIDOMElement * *aPositionedElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPositionedElement(aPositionedElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetAbsolutePositioningEnabled(PRBool *aAbsolutePositioningEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsolutePositioningEnabled(aAbsolutePositioningEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetAbsolutePositioningEnabled(PRBool aAbsolutePositioningEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAbsolutePositioningEnabled(aAbsolutePositioningEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetSnapToGridEnabled(PRBool *aSnapToGridEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSnapToGridEnabled(aSnapToGridEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetSnapToGridEnabled(PRBool aSnapToGridEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSnapToGridEnabled(aSnapToGridEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetGridSize(PRUint32 *aGridSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGridSize(aGridSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetGridSize(PRUint32 aGridSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGridSize(aGridSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsolutelyPositionedSelectionContainer(aAbsolutelyPositionedSelectionContainer); } \
  NS_SCRIPTABLE NS_IMETHOD AbsolutePositionSelection(PRBool aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->AbsolutePositionSelection(aEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD RelativeChangeZIndex(PRInt32 aChange) { return !_to ? NS_ERROR_NULL_POINTER : _to->RelativeChangeZIndex(aChange); } \
  NS_SCRIPTABLE NS_IMETHOD AbsolutelyPositionElement(nsIDOMElement *aElement, PRBool aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->AbsolutelyPositionElement(aElement, aEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetElementPosition(nsIDOMElement *aElement, PRInt32 aX, PRInt32 aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetElementPosition(aElement, aX, aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementZIndex(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementZIndex(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetElementZIndex(nsIDOMElement *aElement, PRInt32 aZorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetElementZIndex(aElement, aZorder); } \
  NS_SCRIPTABLE NS_IMETHOD RelativeChangeElementZIndex(nsIDOMElement *aElement, PRInt32 aChange, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RelativeChangeElementZIndex(aElement, aChange, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShowGrabberOnElement(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowGrabberOnElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD HideGrabber(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HideGrabber(); } \
  NS_SCRIPTABLE NS_IMETHOD RefreshGrabber(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshGrabber(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLAbsPosEditor : public nsIHTMLAbsPosEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLABSPOSEDITOR

  nsHTMLAbsPosEditor();

private:
  ~nsHTMLAbsPosEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTMLAbsPosEditor, nsIHTMLAbsPosEditor)

nsHTMLAbsPosEditor::nsHTMLAbsPosEditor()
{
  /* member initializers and constructor code */
}

nsHTMLAbsPosEditor::~nsHTMLAbsPosEditor()
{
  /* destructor code */
}

/* readonly attribute boolean selectionContainerAbsolutelyPositioned; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetSelectionContainerAbsolutelyPositioned(PRBool *aSelectionContainerAbsolutelyPositioned)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement positionedElement; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetPositionedElement(nsIDOMElement * *aPositionedElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean absolutePositioningEnabled; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetAbsolutePositioningEnabled(PRBool *aAbsolutePositioningEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLAbsPosEditor::SetAbsolutePositioningEnabled(PRBool aAbsolutePositioningEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean snapToGridEnabled; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetSnapToGridEnabled(PRBool *aSnapToGridEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLAbsPosEditor::SetSnapToGridEnabled(PRBool aSnapToGridEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long gridSize; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetGridSize(PRUint32 *aGridSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLAbsPosEditor::SetGridSize(PRUint32 aGridSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement absolutelyPositionedSelectionContainer; */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetAbsolutelyPositionedSelectionContainer(nsIDOMElement * *aAbsolutelyPositionedSelectionContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void absolutePositionSelection (in boolean aEnabled); */
NS_IMETHODIMP nsHTMLAbsPosEditor::AbsolutePositionSelection(PRBool aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void relativeChangeZIndex (in long aChange); */
NS_IMETHODIMP nsHTMLAbsPosEditor::RelativeChangeZIndex(PRInt32 aChange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void absolutelyPositionElement (in nsIDOMElement aElement, in boolean aEnabled); */
NS_IMETHODIMP nsHTMLAbsPosEditor::AbsolutelyPositionElement(nsIDOMElement *aElement, PRBool aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setElementPosition (in nsIDOMElement aElement, in long aX, in long aY); */
NS_IMETHODIMP nsHTMLAbsPosEditor::SetElementPosition(nsIDOMElement *aElement, PRInt32 aX, PRInt32 aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getElementZIndex (in nsIDOMElement aElement); */
NS_IMETHODIMP nsHTMLAbsPosEditor::GetElementZIndex(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setElementZIndex (in nsIDOMElement aElement, in long aZorder); */
NS_IMETHODIMP nsHTMLAbsPosEditor::SetElementZIndex(nsIDOMElement *aElement, PRInt32 aZorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long relativeChangeElementZIndex (in nsIDOMElement aElement, in long aChange); */
NS_IMETHODIMP nsHTMLAbsPosEditor::RelativeChangeElementZIndex(nsIDOMElement *aElement, PRInt32 aChange, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showGrabberOnElement (in nsIDOMElement aElement); */
NS_IMETHODIMP nsHTMLAbsPosEditor::ShowGrabberOnElement(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hideGrabber (); */
NS_IMETHODIMP nsHTMLAbsPosEditor::HideGrabber()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshGrabber (); */
NS_IMETHODIMP nsHTMLAbsPosEditor::RefreshGrabber()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLAbsPosEditor_h__ */
