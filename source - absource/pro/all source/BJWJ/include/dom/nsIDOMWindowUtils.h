/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMWindowUtils.idl
 */

#ifndef __gen_nsIDOMWindowUtils_h__
#define __gen_nsIDOMWindowUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIDOMHTMLCanvasElement; /* forward declaration */


/* starting interface:    nsIDOMWindowUtils */
#define NS_IDOMWINDOWUTILS_IID_STR "a2d8d4f8-6082-4653-b91d-f958518b6ada"

#define NS_IDOMWINDOWUTILS_IID \
  {0xa2d8d4f8, 0x6082, 0x4653, \
    { 0xb9, 0x1d, 0xf9, 0x58, 0x51, 0x8b, 0x6a, 0xda }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMWindowUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOWUTILS_IID)

  /**
   * Image animation mode of the window. When this attribute's value
   * is changed, the implementation should set all images in the window
   * to the given value. That is, when set to kDontAnimMode, all images
   * will stop animating. The attribute's value must be one of the
   * animationMode values from imgIContainer.
   * @note Images may individually override the window's setting after
   *       the window's mode is set. Therefore images given different modes
   *       since the last setting of the window's mode may behave
   *       out of line with the window's overall mode.
   * @note The attribute's value is the window's overall mode. It may
   *       for example continue to report kDontAnimMode after all images
   *       have subsequently been individually animated.
   * @note Only images immediately in this window are affected;
   *       this is not recursive to subwindows.
   * @see imgIContainer
   */
  /* attribute unsigned short imageAnimationMode; */
  NS_SCRIPTABLE NS_IMETHOD GetImageAnimationMode(PRUint16 *aImageAnimationMode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetImageAnimationMode(PRUint16 aImageAnimationMode) = 0;

  /**
   * Whether the charset of the window's current document has been forced by
   * the user.
   * Cannot be accessed from unprivileged context (not content-accessible)
   */
  /* readonly attribute boolean docCharsetIsForced; */
  NS_SCRIPTABLE NS_IMETHOD GetDocCharsetIsForced(PRBool *aDocCharsetIsForced) = 0;

  /**
   * Function to get metadata associated with the window's current document
   * @param aName the name of the metadata.  This should be all lowercase.
   * @return the value of the metadata, or the empty string if it's not set
   *
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   */
  /* AString getDocumentMetadata (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Force an immediate redraw of this window.  The parameter specifies
   * the number of times to redraw, and the return value is the length,
   * in milliseconds, that the redraws took.  If aCount is not specified
   * or is 0, it is taken to be 1.
   */
  /* unsigned long redraw ([optional] in unsigned long aCount); */
  NS_SCRIPTABLE NS_IMETHOD Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) = 0;

  /** Synthesize a mouse event for a window. The event types supported
   *  are: 
   *    mousedown, mouseup, mousemove, mouseover, mouseout, contextmenu
   *
   * Events are sent in coordinates offset by aX and aY from the window.
   *
   * Note that additional events may be fired as a result of this call. For
   * instance, typically a click event will be fired as a result of a
   * mousedown and mouseup in sequence.
   *
   * Normally at this level of events, the mouseover and mouseout events are
   * only fired when the window is entered or exited. For inter-element
   * mouseover and mouseout events, a movemove event fired on the new element
   * should be sufficient to generate the correct over and out events as well.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aType event type
   * @param aX x offset in CSS pixels
   * @param aY y offset in CSS pixels
   * @param aButton button to synthesize
   * @param aClickCount number of clicks that have been performed
   * @param aModifiers modifiers pressed, using constants defined in nsIDOMNSEvent
   * @param aIgnoreRootScrollFrame whether the event should ignore viewport bounds
   *                           during dispatch
   */
  /* void sendMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
  NS_SCRIPTABLE NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame) = 0;

  /** Synthesize a mouse scroll event for a window. The event types supported
   *  are: 
   *    DOMMouseScroll
   *    MozMousePixelScroll
   *
   * Events are sent in coordinates offset by aX and aY from the window.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aType event type
   * @param aX x offset in CSS pixels
   * @param aY y offset in CSS pixels
   * @param aButton button to synthesize
   * @param aScrollFlags flag bits --- see nsMouseScrollFlags in nsGUIEvent.h
   * @param aDelta the direction and amount to scroll (in lines or pixels,
   * depending on the event type)
   * @param aModifiers modifiers pressed, using constants defined in nsIDOMNSEvent
   */
  /* void sendMouseScrollEvent (in AString aType, in float aX, in float aY, in long aButton, in long aScrollFlags, in long aDelta, in long aModifiers); */
  NS_SCRIPTABLE NS_IMETHOD SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers) = 0;

  /**
   * Synthesize a key event to the window. The event types supported are:
   *   keydown, keyup, keypress
   *
   * Key events generally end up being sent to the focused node.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aType event type
   * @param aKeyCode key code
   * @param aCharCode character code
   * @param aModifiers modifiers pressed, using constants defined in nsIDOMNSEvent
   * @param aPreventDefault if true, preventDefault() the event before dispatch
   *
   * @return false if the event had preventDefault() called on it,
   *               true otherwise.  In other words, true if and only if the
   *               default action was taken.
   */
  /* boolean sendKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in boolean aPreventDefault); */
  NS_SCRIPTABLE NS_IMETHOD SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * See nsIWidget::SynthesizeNativeKeyEvent
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   */
  /* void sendNativeKeyEvent (in long aNativeKeyboardLayout, in long aNativeKeyCode, in long aModifierFlags, in AString aCharacters, in AString aUnmodifiedCharacters); */
  NS_SCRIPTABLE NS_IMETHOD SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters) = 0;

  /**
   * See nsIWidget::ActivateNativeMenuItemAt
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   */
  /* void activateNativeMenuItemAt (in AString indexString); */
  NS_SCRIPTABLE NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) = 0;

  /**
   * See nsIWidget::ForceUpdateNativeMenuAt
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   */
  /* void forceUpdateNativeMenuAt (in AString indexString); */
  NS_SCRIPTABLE NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) = 0;

  /**
   * Focus the element aElement. The element should be in the same document
   * that the window is displaying. Pass null to blur the element, if any,
   * that currently has focus, and focus the document.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aElement the element to focus
   */
  /* void focus (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD Focus(nsIDOMElement *aElement) = 0;

  /**
   * Force a garbage collection. This will run the cycle-collector twice to
   * make sure all garbage is collected.
   *
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges in non-debug builds. Available to all callers in debug builds.
   */
  /* void garbageCollect (); */
  NS_SCRIPTABLE NS_IMETHOD GarbageCollect(void) = 0;

  /**
   * Force processing of any queued paints
   */
  /* void processUpdates (); */
  NS_SCRIPTABLE NS_IMETHOD ProcessUpdates(void) = 0;

  /** Synthesize a simple gesture event for a window. The event types
   *  supported are: MozSwipeGesture, MozMagnifyGestureStart,
   *  MozMagnifyGestureUpdate, MozMagnifyGesture, MozRotateGestureStart,
   *  MozRotateGestureUpdate, MozRotateGesture, MozPressTapGesture, and
   *  MozTapGesture.
   *
   * Cannot be accessed from unprivileged context (not
   * content-accessible) Will throw a DOM security error if called
   * without UniversalXPConnect privileges.
   *
   * @param aType event type
   * @param aX x offset in CSS pixels
   * @param aY y offset in CSS pixels
   * @param aDirection direction, using constants defined in nsIDOMSimpleGestureEvent
   * @param aDelta  amount of magnification or rotation for magnify and rotation events
   * @param aModifiers modifiers pressed, using constants defined in nsIDOMNSEvent
   */
  /* void sendSimpleGestureEvent (in AString aType, in float aX, in float aY, in unsigned long aDirection, in double aDelta, in long aModifiers); */
  NS_SCRIPTABLE NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers) = 0;

  /**
   * Retrieve the element at point aX, aY in the window's document.
   *
   * @param aIgnoreRootScrollFrame whether or not to ignore the root scroll
   *        frame when retrieving the element. If false, this method returns
   *        null for coordinates outside of the viewport.
   * @param aFlushLayout flushes layout if true. Otherwise, no flush occurs.
   */
  /* nsIDOMElement elementFromPoint (in long aX, in long aY, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(PRInt32 aX, PRInt32 aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /**
   * Compare the two canvases, returning the number of differing pixels and
   * the maximum difference in a channel.  This will throw an error if
   * the dimensions of the two canvases are different.
   *
   * This method requires UniversalXPConnect privileges.
   */
  /* PRUint32 compareCanvases (in nsIDOMHTMLCanvasElement aCanvas1, in nsIDOMHTMLCanvasElement aCanvas2, out unsigned long aMaxDifference); */
  NS_SCRIPTABLE NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* void clearMozAfterPaintEvents (); */
  NS_SCRIPTABLE NS_IMETHOD ClearMozAfterPaintEvents(void) = 0;

  /**
   * Suppresses/unsuppresses user initiated event handling in window's document
   * and subdocuments.
   *
   * @throw NS_ERROR_DOM_SECURITY_ERR if called without UniversalXPConnect
   *        privileges and NS_ERROR_FAILURE if window doesn't have a document.
   */
  /* void suppressEventHandling (in boolean aSuppress); */
  NS_SCRIPTABLE NS_IMETHOD SuppressEventHandling(PRBool aSuppress) = 0;

  /**
   * Returns the scroll position of the window's currently loaded document.
   *
   * @param aFlushLayout flushes layout if true. Otherwise, no flush occurs.
   * @see nsIDOMWindow::scrollX/Y
   */
  /* void getScrollXY (in boolean aFlushLayout, out long aScrollX, out long aScrollY); */
  NS_SCRIPTABLE NS_IMETHOD GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindowUtils, NS_IDOMWINDOWUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOWUTILS \
  NS_SCRIPTABLE NS_IMETHOD GetImageAnimationMode(PRUint16 *aImageAnimationMode); \
  NS_SCRIPTABLE NS_IMETHOD SetImageAnimationMode(PRUint16 aImageAnimationMode); \
  NS_SCRIPTABLE NS_IMETHOD GetDocCharsetIsForced(PRBool *aDocCharsetIsForced); \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame); \
  NS_SCRIPTABLE NS_IMETHOD SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers); \
  NS_SCRIPTABLE NS_IMETHOD SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters); \
  NS_SCRIPTABLE NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString); \
  NS_SCRIPTABLE NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString); \
  NS_SCRIPTABLE NS_IMETHOD Focus(nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD GarbageCollect(void); \
  NS_SCRIPTABLE NS_IMETHOD ProcessUpdates(void); \
  NS_SCRIPTABLE NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers); \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(PRInt32 aX, PRInt32 aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ClearMozAfterPaintEvents(void); \
  NS_SCRIPTABLE NS_IMETHOD SuppressEventHandling(PRBool aSuppress); \
  NS_SCRIPTABLE NS_IMETHOD GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOWUTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImageAnimationMode(PRUint16 *aImageAnimationMode) { return _to GetImageAnimationMode(aImageAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetImageAnimationMode(PRUint16 aImageAnimationMode) { return _to SetImageAnimationMode(aImageAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocCharsetIsForced(PRBool *aDocCharsetIsForced) { return _to GetDocCharsetIsForced(aDocCharsetIsForced); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM) { return _to GetDocumentMetadata(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) { return _to Redraw(aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame) { return _to SendMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers) { return _to SendMouseScrollEvent(aType, aX, aY, aButton, aScrollFlags, aDelta, aModifiers); } \
  NS_SCRIPTABLE NS_IMETHOD SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM) { return _to SendKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aPreventDefault, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters) { return _to SendNativeKeyEvent(aNativeKeyboardLayout, aNativeKeyCode, aModifierFlags, aCharacters, aUnmodifiedCharacters); } \
  NS_SCRIPTABLE NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) { return _to ActivateNativeMenuItemAt(indexString); } \
  NS_SCRIPTABLE NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) { return _to ForceUpdateNativeMenuAt(indexString); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(nsIDOMElement *aElement) { return _to Focus(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GarbageCollect(void) { return _to GarbageCollect(); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessUpdates(void) { return _to ProcessUpdates(); } \
  NS_SCRIPTABLE NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers) { return _to SendSimpleGestureEvent(aType, aX, aY, aDirection, aDelta, aModifiers); } \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(PRInt32 aX, PRInt32 aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM) { return _to ElementFromPoint(aX, aY, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return _to CompareCanvases(aCanvas1, aCanvas2, aMaxDifference, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearMozAfterPaintEvents(void) { return _to ClearMozAfterPaintEvents(); } \
  NS_SCRIPTABLE NS_IMETHOD SuppressEventHandling(PRBool aSuppress) { return _to SuppressEventHandling(aSuppress); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM) { return _to GetScrollXY(aFlushLayout, aScrollX, aScrollY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOWUTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImageAnimationMode(PRUint16 *aImageAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageAnimationMode(aImageAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetImageAnimationMode(PRUint16 aImageAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImageAnimationMode(aImageAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocCharsetIsForced(PRBool *aDocCharsetIsForced) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocCharsetIsForced(aDocCharsetIsForced); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentMetadata(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Redraw(aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseScrollEvent(aType, aX, aY, aButton, aScrollFlags, aDelta, aModifiers); } \
  NS_SCRIPTABLE NS_IMETHOD SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aPreventDefault, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeKeyEvent(aNativeKeyboardLayout, aNativeKeyCode, aModifierFlags, aCharacters, aUnmodifiedCharacters); } \
  NS_SCRIPTABLE NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateNativeMenuItemAt(indexString); } \
  NS_SCRIPTABLE NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceUpdateNativeMenuAt(indexString); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GarbageCollect(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GarbageCollect(); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessUpdates(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessUpdates(); } \
  NS_SCRIPTABLE NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSimpleGestureEvent(aType, aX, aY, aDirection, aDelta, aModifiers); } \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(PRInt32 aX, PRInt32 aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ElementFromPoint(aX, aY, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareCanvases(aCanvas1, aCanvas2, aMaxDifference, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearMozAfterPaintEvents(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearMozAfterPaintEvents(); } \
  NS_SCRIPTABLE NS_IMETHOD SuppressEventHandling(PRBool aSuppress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SuppressEventHandling(aSuppress); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollXY(aFlushLayout, aScrollX, aScrollY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindowUtils : public nsIDOMWindowUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOWUTILS

  nsDOMWindowUtils();

private:
  ~nsDOMWindowUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWindowUtils, nsIDOMWindowUtils)

nsDOMWindowUtils::nsDOMWindowUtils()
{
  /* member initializers and constructor code */
}

nsDOMWindowUtils::~nsDOMWindowUtils()
{
  /* destructor code */
}

/* attribute unsigned short imageAnimationMode; */
NS_IMETHODIMP nsDOMWindowUtils::GetImageAnimationMode(PRUint16 *aImageAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetImageAnimationMode(PRUint16 aImageAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean docCharsetIsForced; */
NS_IMETHODIMP nsDOMWindowUtils::GetDocCharsetIsForced(PRBool *aDocCharsetIsForced)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getDocumentMetadata (in AString aName); */
NS_IMETHODIMP nsDOMWindowUtils::GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long redraw ([optional] in unsigned long aCount); */
NS_IMETHODIMP nsDOMWindowUtils::Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
NS_IMETHODIMP nsDOMWindowUtils::SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendMouseScrollEvent (in AString aType, in float aX, in float aY, in long aButton, in long aScrollFlags, in long aDelta, in long aModifiers); */
NS_IMETHODIMP nsDOMWindowUtils::SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in boolean aPreventDefault); */
NS_IMETHODIMP nsDOMWindowUtils::SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeKeyEvent (in long aNativeKeyboardLayout, in long aNativeKeyCode, in long aModifierFlags, in AString aCharacters, in AString aUnmodifiedCharacters); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activateNativeMenuItemAt (in AString indexString); */
NS_IMETHODIMP nsDOMWindowUtils::ActivateNativeMenuItemAt(const nsAString & indexString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceUpdateNativeMenuAt (in AString indexString); */
NS_IMETHODIMP nsDOMWindowUtils::ForceUpdateNativeMenuAt(const nsAString & indexString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::Focus(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void garbageCollect (); */
NS_IMETHODIMP nsDOMWindowUtils::GarbageCollect()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void processUpdates (); */
NS_IMETHODIMP nsDOMWindowUtils::ProcessUpdates()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendSimpleGestureEvent (in AString aType, in float aX, in float aY, in unsigned long aDirection, in double aDelta, in long aModifiers); */
NS_IMETHODIMP nsDOMWindowUtils::SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement elementFromPoint (in long aX, in long aY, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
NS_IMETHODIMP nsDOMWindowUtils::ElementFromPoint(PRInt32 aX, PRInt32 aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 compareCanvases (in nsIDOMHTMLCanvasElement aCanvas1, in nsIDOMHTMLCanvasElement aCanvas2, out unsigned long aMaxDifference); */
NS_IMETHODIMP nsDOMWindowUtils::CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearMozAfterPaintEvents (); */
NS_IMETHODIMP nsDOMWindowUtils::ClearMozAfterPaintEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suppressEventHandling (in boolean aSuppress); */
NS_IMETHODIMP nsDOMWindowUtils::SuppressEventHandling(PRBool aSuppress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollXY (in boolean aFlushLayout, out long aScrollX, out long aScrollY); */
NS_IMETHODIMP nsDOMWindowUtils::GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWindowUtils_h__ */
