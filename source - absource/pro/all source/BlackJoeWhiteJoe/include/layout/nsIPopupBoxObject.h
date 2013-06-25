/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsIPopupBoxObject.idl
 */

#ifndef __gen_nsIPopupBoxObject_h__
#define __gen_nsIPopupBoxObject_h__


#ifndef __gen_nsIBoxObject_h__
#include "nsIBoxObject.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIPopupBoxObject */
#define NS_IPOPUPBOXOBJECT_IID_STR "a41af368-9f73-4d73-a058-49dd7e41f9ea"

#define NS_IPOPUPBOXOBJECT_IID \
  {0xa41af368, 0x9f73, 0x4d73, \
    { 0xa0, 0x58, 0x49, 0xdd, 0x7e, 0x41, 0xf9, 0xea }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPopupBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPOPUPBOXOBJECT_IID)

  /**
   *  This method is deprecated. Use openPopup or openPopupAtScreen instead.
   */
  /* void showPopup (in nsIDOMElement srcContent, in nsIDOMElement popupContent, in long xpos, in long ypos, in wstring popupType, in wstring anchorAlignment, in wstring popupAlignment); */
  NS_SCRIPTABLE NS_IMETHOD ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, PRInt32 xpos, PRInt32 ypos, const PRUnichar *popupType, const PRUnichar *anchorAlignment, const PRUnichar *popupAlignment) = 0;

  /**
   *  Hide the popup if it is open.
   */
  /* void hidePopup (); */
  NS_SCRIPTABLE NS_IMETHOD HidePopup(void) = 0;

  /** 
   * Allow the popup to automatically position itself.
   */
  /* attribute boolean autoPosition; */
  NS_SCRIPTABLE NS_IMETHOD GetAutoPosition(PRBool *aAutoPosition) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAutoPosition(PRBool aAutoPosition) = 0;

  /**
   * If keyboard navigation is enabled, the keyboard may be used to navigate
   * the menuitems on the popup. Enabling keyboard navigation is the default
   * behaviour and will install capturing key event listeners on the popup
   * that do not propagate key events to the contents. If you wish to place
   * elements in a popup which accept key events, such as textboxes, keyboard
   * navigation should be disabled.
   *
   * Setting ignorekeys="true" on the popup element also disables keyboard
   * navigation, and is recommended over calling this method.
   */
  /* void enableKeyboardNavigator (in boolean enableKeyboardNavigator); */
  NS_SCRIPTABLE NS_IMETHOD EnableKeyboardNavigator(PRBool enableKeyboardNavigator) = 0;

  /** 
   * Enable automatic popup dismissal. This only has effect when called
   * on an open popup.
   */
  /* void enableRollup (in boolean enableRollup); */
  NS_SCRIPTABLE NS_IMETHOD EnableRollup(PRBool enableRollup) = 0;

  /**
   * Control whether the event that caused the popup to be automatically
   * dismissed ("rolled up") should be consumed, or dispatched as a
   * normal event.  This should be set immediately before calling showPopup()
   * if non-default behavior is desired.
   */
  enum { ROLLUP_DEFAULT = 0U };

  enum { ROLLUP_CONSUME = 1U };

  enum { ROLLUP_NO_CONSUME = 2U };

  /* void setConsumeRollupEvent (in PRUint32 consume); */
  NS_SCRIPTABLE NS_IMETHOD SetConsumeRollupEvent(PRUint32 consume) = 0;

  /** 
   * Size the popup to the given dimensions
   */
  /* void sizeTo (in long width, in long height); */
  NS_SCRIPTABLE NS_IMETHOD SizeTo(PRInt32 width, PRInt32 height) = 0;

  /**
   * Move the popup to a point on screen in CSS pixels.
   */
  /* void moveTo (in long left, in long top); */
  NS_SCRIPTABLE NS_IMETHOD MoveTo(PRInt32 left, PRInt32 top) = 0;

  /**
   * Open the popup relative to a specified node at a specific location.
   *
   * The popup may be either anchored to another node or opened freely.
   * To anchor a popup to a node, supply an anchor node and set the position
   * to a string indicating the manner in which the popup should be anchored.
   * Possible values for position are:
   *    before_start, before_end, after_start, after_end,
   *    start_before, start_after, end_before, end_after,
   *    overlap, after_pointer
   *
   * The anchor node does not need to be in the same document as the popup.
   *
   * If the attributesOverride argument is true, the popupanchor, popupalign
   * and position attributes on the popup node override the position value
   * argument. If attributesOverride is false, the attributes are only used
   * if position is empty.
   *
   * For an anchored popup, the x and y arguments may be used to offset the 
   * popup from its anchored position by some distance, measured in CSS pixels.
   * x increases to the right and y increases down. Negative values may also
   * be used to move to the left and upwards respectively.
   *
   * Unanchored popups may be created by supplying null as the anchor node.
   * An unanchored popup appears at the position specified by x and y,
   * relative to the viewport of the document containing the popup node. In
   * this case, position and attributesOverride are ignored.
   *
   * @param anchorElement the node to anchor the popup to, may be null
   * @param position manner is which to anchor the popup to node
   * @param x horizontal offset
   * @param y vertical offset
   * @param isContextMenu true for context menus, false for other popups
   * @param attributesOverride true if popup node attributes override position
   */
  /* void openPopup (in nsIDOMElement anchorElement, in AString position, in long x, in long y, in boolean isContextMenu, in boolean attributesOverride); */
  NS_SCRIPTABLE NS_IMETHOD OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, PRInt32 x, PRInt32 y, PRBool isContextMenu, PRBool attributesOverride) = 0;

  /**
   * Open the popup at a specific screen position specified by x and y. This
   * position may be adjusted if it would cause the popup to be off of the
   * screen. The x and y coordinates are measured in CSS pixels. The monitor
   * selected is determined within the platform specific widget code, but
   * in general, the coordinates are relative to the screen the window
   * containing the popup is on.
   *
   * @param isContextMenu true for context menus, false for other popups
   * @param x horizontal screen position
   * @param y vertical screen position
   */
  /* void openPopupAtScreen (in long x, in long y, in boolean isContextMenu); */
  NS_SCRIPTABLE NS_IMETHOD OpenPopupAtScreen(PRInt32 x, PRInt32 y, PRBool isContextMenu) = 0;

  /**
   * Returns the state of the popup:
   *   closed - the popup is closed
   *   open - the popup is open
   *   showing - the popup is in the process of being shown
   *   hiding - the popup is in the process of being hidden
   */
  /* readonly attribute AString popupState; */
  NS_SCRIPTABLE NS_IMETHOD GetPopupState(nsAString & aPopupState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPopupBoxObject, NS_IPOPUPBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPOPUPBOXOBJECT \
  NS_SCRIPTABLE NS_IMETHOD ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, PRInt32 xpos, PRInt32 ypos, const PRUnichar *popupType, const PRUnichar *anchorAlignment, const PRUnichar *popupAlignment); \
  NS_SCRIPTABLE NS_IMETHOD HidePopup(void); \
  NS_SCRIPTABLE NS_IMETHOD GetAutoPosition(PRBool *aAutoPosition); \
  NS_SCRIPTABLE NS_IMETHOD SetAutoPosition(PRBool aAutoPosition); \
  NS_SCRIPTABLE NS_IMETHOD EnableKeyboardNavigator(PRBool enableKeyboardNavigator); \
  NS_SCRIPTABLE NS_IMETHOD EnableRollup(PRBool enableRollup); \
  NS_SCRIPTABLE NS_IMETHOD SetConsumeRollupEvent(PRUint32 consume); \
  NS_SCRIPTABLE NS_IMETHOD SizeTo(PRInt32 width, PRInt32 height); \
  NS_SCRIPTABLE NS_IMETHOD MoveTo(PRInt32 left, PRInt32 top); \
  NS_SCRIPTABLE NS_IMETHOD OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, PRInt32 x, PRInt32 y, PRBool isContextMenu, PRBool attributesOverride); \
  NS_SCRIPTABLE NS_IMETHOD OpenPopupAtScreen(PRInt32 x, PRInt32 y, PRBool isContextMenu); \
  NS_SCRIPTABLE NS_IMETHOD GetPopupState(nsAString & aPopupState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPOPUPBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, PRInt32 xpos, PRInt32 ypos, const PRUnichar *popupType, const PRUnichar *anchorAlignment, const PRUnichar *popupAlignment) { return _to ShowPopup(srcContent, popupContent, xpos, ypos, popupType, anchorAlignment, popupAlignment); } \
  NS_SCRIPTABLE NS_IMETHOD HidePopup(void) { return _to HidePopup(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoPosition(PRBool *aAutoPosition) { return _to GetAutoPosition(aAutoPosition); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoPosition(PRBool aAutoPosition) { return _to SetAutoPosition(aAutoPosition); } \
  NS_SCRIPTABLE NS_IMETHOD EnableKeyboardNavigator(PRBool enableKeyboardNavigator) { return _to EnableKeyboardNavigator(enableKeyboardNavigator); } \
  NS_SCRIPTABLE NS_IMETHOD EnableRollup(PRBool enableRollup) { return _to EnableRollup(enableRollup); } \
  NS_SCRIPTABLE NS_IMETHOD SetConsumeRollupEvent(PRUint32 consume) { return _to SetConsumeRollupEvent(consume); } \
  NS_SCRIPTABLE NS_IMETHOD SizeTo(PRInt32 width, PRInt32 height) { return _to SizeTo(width, height); } \
  NS_SCRIPTABLE NS_IMETHOD MoveTo(PRInt32 left, PRInt32 top) { return _to MoveTo(left, top); } \
  NS_SCRIPTABLE NS_IMETHOD OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, PRInt32 x, PRInt32 y, PRBool isContextMenu, PRBool attributesOverride) { return _to OpenPopup(anchorElement, position, x, y, isContextMenu, attributesOverride); } \
  NS_SCRIPTABLE NS_IMETHOD OpenPopupAtScreen(PRInt32 x, PRInt32 y, PRBool isContextMenu) { return _to OpenPopupAtScreen(x, y, isContextMenu); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupState(nsAString & aPopupState) { return _to GetPopupState(aPopupState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPOPUPBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, PRInt32 xpos, PRInt32 ypos, const PRUnichar *popupType, const PRUnichar *anchorAlignment, const PRUnichar *popupAlignment) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPopup(srcContent, popupContent, xpos, ypos, popupType, anchorAlignment, popupAlignment); } \
  NS_SCRIPTABLE NS_IMETHOD HidePopup(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HidePopup(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoPosition(PRBool *aAutoPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoPosition(aAutoPosition); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoPosition(PRBool aAutoPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutoPosition(aAutoPosition); } \
  NS_SCRIPTABLE NS_IMETHOD EnableKeyboardNavigator(PRBool enableKeyboardNavigator) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableKeyboardNavigator(enableKeyboardNavigator); } \
  NS_SCRIPTABLE NS_IMETHOD EnableRollup(PRBool enableRollup) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableRollup(enableRollup); } \
  NS_SCRIPTABLE NS_IMETHOD SetConsumeRollupEvent(PRUint32 consume) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConsumeRollupEvent(consume); } \
  NS_SCRIPTABLE NS_IMETHOD SizeTo(PRInt32 width, PRInt32 height) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeTo(width, height); } \
  NS_SCRIPTABLE NS_IMETHOD MoveTo(PRInt32 left, PRInt32 top) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveTo(left, top); } \
  NS_SCRIPTABLE NS_IMETHOD OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, PRInt32 x, PRInt32 y, PRBool isContextMenu, PRBool attributesOverride) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenPopup(anchorElement, position, x, y, isContextMenu, attributesOverride); } \
  NS_SCRIPTABLE NS_IMETHOD OpenPopupAtScreen(PRInt32 x, PRInt32 y, PRBool isContextMenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenPopupAtScreen(x, y, isContextMenu); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupState(nsAString & aPopupState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupState(aPopupState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPopupBoxObject : public nsIPopupBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPOPUPBOXOBJECT

  nsPopupBoxObject();

private:
  ~nsPopupBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPopupBoxObject, nsIPopupBoxObject)

nsPopupBoxObject::nsPopupBoxObject()
{
  /* member initializers and constructor code */
}

nsPopupBoxObject::~nsPopupBoxObject()
{
  /* destructor code */
}

/* void showPopup (in nsIDOMElement srcContent, in nsIDOMElement popupContent, in long xpos, in long ypos, in wstring popupType, in wstring anchorAlignment, in wstring popupAlignment); */
NS_IMETHODIMP nsPopupBoxObject::ShowPopup(nsIDOMElement *srcContent, nsIDOMElement *popupContent, PRInt32 xpos, PRInt32 ypos, const PRUnichar *popupType, const PRUnichar *anchorAlignment, const PRUnichar *popupAlignment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hidePopup (); */
NS_IMETHODIMP nsPopupBoxObject::HidePopup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autoPosition; */
NS_IMETHODIMP nsPopupBoxObject::GetAutoPosition(PRBool *aAutoPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPopupBoxObject::SetAutoPosition(PRBool aAutoPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableKeyboardNavigator (in boolean enableKeyboardNavigator); */
NS_IMETHODIMP nsPopupBoxObject::EnableKeyboardNavigator(PRBool enableKeyboardNavigator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableRollup (in boolean enableRollup); */
NS_IMETHODIMP nsPopupBoxObject::EnableRollup(PRBool enableRollup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setConsumeRollupEvent (in PRUint32 consume); */
NS_IMETHODIMP nsPopupBoxObject::SetConsumeRollupEvent(PRUint32 consume)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeTo (in long width, in long height); */
NS_IMETHODIMP nsPopupBoxObject::SizeTo(PRInt32 width, PRInt32 height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveTo (in long left, in long top); */
NS_IMETHODIMP nsPopupBoxObject::MoveTo(PRInt32 left, PRInt32 top)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openPopup (in nsIDOMElement anchorElement, in AString position, in long x, in long y, in boolean isContextMenu, in boolean attributesOverride); */
NS_IMETHODIMP nsPopupBoxObject::OpenPopup(nsIDOMElement *anchorElement, const nsAString & position, PRInt32 x, PRInt32 y, PRBool isContextMenu, PRBool attributesOverride)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openPopupAtScreen (in long x, in long y, in boolean isContextMenu); */
NS_IMETHODIMP nsPopupBoxObject::OpenPopupAtScreen(PRInt32 x, PRInt32 y, PRBool isContextMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString popupState; */
NS_IMETHODIMP nsPopupBoxObject::GetPopupState(nsAString & aPopupState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewPopupBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIPopupBoxObject_h__ */
