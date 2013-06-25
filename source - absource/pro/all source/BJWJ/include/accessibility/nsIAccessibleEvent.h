/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleEvent.idl
 */

#ifndef __gen_nsIAccessibleEvent_h__
#define __gen_nsIAccessibleEvent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */

class nsIAccessibleDocument; /* forward declaration */

class nsIDOMNode; /* forward declaration */

#define NS_ACCESSIBLE_EVENT_TOPIC "accessible-event"

/* starting interface:    nsIAccessibleEvent */
#define NS_IACCESSIBLEEVENT_IID_STR "ba448f0e-a761-48c8-a0f5-1f25e23d4fe4"

#define NS_IACCESSIBLEEVENT_IID \
  {0xba448f0e, 0xa761, 0x48c8, \
    { 0xa0, 0xf5, 0x1f, 0x25, 0xe2, 0x3d, 0x4f, 0xe4 }}

/**
 * An interface for accessibility events listened to
 * by in-process accessibility clients, which can be used
 * to find out how to get accessibility and DOM interfaces for
 * the event and its target. To listen to in-process accessibility invents,
 * make your object an nsIObserver, and listen for accessible-event by 
 * using code something like this:
 *   nsCOMPtr<nsIObserverService> observerService = 
 *     do_GetService("@mozilla.org/observer-service;1", &rv);
 *   if (NS_SUCCEEDED(rv)) 
 *     rv = observerService->AddObserver(this, "accessible-event", PR_TRUE);
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleEvent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEEVENT_IID)

  /**
   * An object has been created.
   */
  enum { EVENT_DOM_CREATE = 1U };

  /**
   * An object has been destroyed.
   */
  enum { EVENT_DOM_DESTROY = 2U };

  /**
   * An object's properties or content have changed significantly so that the
   * type of object has really changed, and therefore the accessible should be 
   * destroyed or recreated.
   */
  enum { EVENT_DOM_SIGNIFICANT_CHANGE = 3U };

  /**
   * A hidden object is shown -- this is a layout occurance and is thus asynchronous
   */
  enum { EVENT_ASYNCH_SHOW = 4U };

  /**
   * An object is hidden -- this is a layout occurance and is thus asynchronous
   */
  enum { EVENT_ASYNCH_HIDE = 5U };

  /**
   * An object had a significant layout change which could affect
   * the type of accessible object -- this is a layout occurance and is thus asynchronous
   */
  enum { EVENT_ASYNCH_SIGNIFICANT_CHANGE = 6U };

  /**
   * The active descendant of a component has changed. The active descendant
   * is used in objects with transient children.
   */
  enum { EVENT_ACTIVE_DECENDENT_CHANGED = 7U };

  /**
   * An object has received the keyboard focus.
   */
  enum { EVENT_FOCUS = 8U };

  /**
   * An object's state has changed.
   */
  enum { EVENT_STATE_CHANGE = 9U };

  /**
   * An object has changed location, shape, or size.
   */
  enum { EVENT_LOCATION_CHANGE = 10U };

  /**
   * An object's Name property has changed.
   */
  enum { EVENT_NAME_CHANGE = 11U };

  /**
   * An object's Description property has changed.
   */
  enum { EVENT_DESCRIPTION_CHANGE = 12U };

  /**
   * An object's Value property has changed.
   */
  enum { EVENT_VALUE_CHANGE = 13U };

  /**
   * An object's help has changed.
   */
  enum { EVENT_HELP_CHANGE = 14U };

  /**
   * An object's default action has changed.
   */
  enum { EVENT_DEFACTION_CHANGE = 15U };

  /**
   * An object's action has changed.
   */
  enum { EVENT_ACTION_CHANGE = 16U };

  /**
   * An object's keyboard shortcut has changed.
   */
  enum { EVENT_ACCELERATOR_CHANGE = 17U };

  /**
   * The selection within a container object has changed.
   */
  enum { EVENT_SELECTION = 18U };

  /**
   * An item within a container object has been added to the selection.
   */
  enum { EVENT_SELECTION_ADD = 19U };

  /**
   * An item within a container object has been removed from the selection.
   */
  enum { EVENT_SELECTION_REMOVE = 20U };

  /**
   * Numerous selection changes have occurred within a container object.
   */
  enum { EVENT_SELECTION_WITHIN = 21U };

  /**
   * An alert has been generated. Server applications send this event when a
   * user needs to know that a user interface element has changed.
   */
  enum { EVENT_ALERT = 22U };

  /**
   * The foreground window has changed.
   */
  enum { EVENT_FOREGROUND = 23U };

  /**
   * A menu item on the menu bar has been selected.
   */
  enum { EVENT_MENU_START = 24U };

  /**
   * A menu from the menu bar has been closed.
   */
  enum { EVENT_MENU_END = 25U };

  /**
   * A pop-up menu has been displayed.
   */
  enum { EVENT_MENUPOPUP_START = 26U };

  /**
   * A pop-up menu has been closed.
   */
  enum { EVENT_MENUPOPUP_END = 27U };

  /**
   * A window has received mouse capture.
   */
  enum { EVENT_CAPTURE_START = 28U };

  /**
   * A window has lost mouse capture.
   */
  enum { EVENT_CAPTURE_END = 29U };

  /**
   * A window is being moved or resized.
   */
  enum { EVENT_MOVESIZE_START = 30U };

  /**
  * The movement or resizing of a window has finished
  */
  enum { EVENT_MOVESIZE_END = 31U };

  /**
   * A window has entered context-sensitive Help mode
   */
  enum { EVENT_CONTEXTHELP_START = 32U };

  /**
   * A window has exited context-sensitive Help mode
   */
  enum { EVENT_CONTEXTHELP_END = 33U };

  /**
   * An application is about to enter drag-and-drop mode
   */
  enum { EVENT_DRAGDROP_START = 34U };

  /**
   * An application is about to exit drag-and-drop mode
   */
  enum { EVENT_DRAGDROP_END = 35U };

  /**
   * A dialog box has been displayed
   */
  enum { EVENT_DIALOG_START = 36U };

  /**
   * A dialog box has been closed
   */
  enum { EVENT_DIALOG_END = 37U };

  /**
   * Scrolling has started on a scroll bar
   */
  enum { EVENT_SCROLLING_START = 38U };

  /**
   * Scrolling has ended on a scroll bar
   */
  enum { EVENT_SCROLLING_END = 39U };

  /**
   * A window object is about to be minimized or maximized
   */
  enum { EVENT_MINIMIZE_START = 40U };

  /**
   * A window object has been minimized or maximized
   */
  enum { EVENT_MINIMIZE_END = 41U };

  /**
   * XXX:
   */
  enum { EVENT_DOCUMENT_LOAD_START = 42U };

  /**
   * The loading of the document has completed.
   */
  enum { EVENT_DOCUMENT_LOAD_COMPLETE = 43U };

  /**
   * The document contents are being reloaded.
   */
  enum { EVENT_DOCUMENT_RELOAD = 44U };

  /**
   * The loading of the document was interrupted.
   */
  enum { EVENT_DOCUMENT_LOAD_STOPPED = 45U };

  /**
   * The document wide attributes of the document object have changed.
   */
  enum { EVENT_DOCUMENT_ATTRIBUTES_CHANGED = 46U };

  /**
   * The contents of the document have changed.
   */
  enum { EVENT_DOCUMENT_CONTENT_CHANGED = 47U };

  enum { EVENT_PROPERTY_CHANGED = 48U };

  enum { EVENT_SELECTION_CHANGED = 49U };

  /**
   * A text object's attributes changed.
   * Also see EVENT_OBJECT_ATTRIBUTE_CHANGED.
   */
  enum { EVENT_TEXT_ATTRIBUTE_CHANGED = 50U };

  /**
   * The caret has moved to a new position.
   */
  enum { EVENT_TEXT_CARET_MOVED = 51U };

  /**
   * This event indicates general text changes, i.e. changes to text that is
   * exposed through the IAccessibleText and IAccessibleEditableText interfaces.
   */
  enum { EVENT_TEXT_CHANGED = 52U };

  /**
   * Text was inserted.
   */
  enum { EVENT_TEXT_INSERTED = 53U };

  /**
   * Text was removed.
   */
  enum { EVENT_TEXT_REMOVED = 54U };

  /**
   * Text was updated.
   */
  enum { EVENT_TEXT_UPDATED = 55U };

  /**
   * The text selection changed.
   */
  enum { EVENT_TEXT_SELECTION_CHANGED = 56U };

  /**
   * A visibile data event indicates the change of the visual appearance
   * of an accessible object.  This includes for example most of the
   * attributes available via the IAccessibleComponent interface.
   */
  enum { EVENT_VISIBLE_DATA_CHANGED = 57U };

  /**
   * The caret moved from one column to the next.
   */
  enum { EVENT_TEXT_COLUMN_CHANGED = 58U };

  /**
   * The caret moved from one section to the next.
   */
  enum { EVENT_SECTION_CHANGED = 59U };

  /**
   * A table caption changed.
   */
  enum { EVENT_TABLE_CAPTION_CHANGED = 60U };

  /**
   * A table's data changed.
   */
  enum { EVENT_TABLE_MODEL_CHANGED = 61U };

  /**
   * A table's summary changed.
   */
  enum { EVENT_TABLE_SUMMARY_CHANGED = 62U };

  /**
   * A table's row description changed.
   */
  enum { EVENT_TABLE_ROW_DESCRIPTION_CHANGED = 63U };

  /**
   * A table's row header changed.
   */
  enum { EVENT_TABLE_ROW_HEADER_CHANGED = 64U };

  enum { EVENT_TABLE_ROW_INSERT = 65U };

  enum { EVENT_TABLE_ROW_DELETE = 66U };

  enum { EVENT_TABLE_ROW_REORDER = 67U };

  /**
   * A table's column description changed.
   */
  enum { EVENT_TABLE_COLUMN_DESCRIPTION_CHANGED = 68U };

  /**
   * A table's column header changed.
   */
  enum { EVENT_TABLE_COLUMN_HEADER_CHANGED = 69U };

  enum { EVENT_TABLE_COLUMN_INSERT = 70U };

  enum { EVENT_TABLE_COLUMN_DELETE = 71U };

  enum { EVENT_TABLE_COLUMN_REORDER = 72U };

  enum { EVENT_WINDOW_ACTIVATE = 73U };

  enum { EVENT_WINDOW_CREATE = 74U };

  enum { EVENT_WINDOW_DEACTIVATE = 75U };

  enum { EVENT_WINDOW_DESTROY = 76U };

  enum { EVENT_WINDOW_MAXIMIZE = 77U };

  enum { EVENT_WINDOW_MINIMIZE = 78U };

  enum { EVENT_WINDOW_RESIZE = 79U };

  enum { EVENT_WINDOW_RESTORE = 80U };

  /**
   * The ending index of this link within the containing string has changed.
   */
  enum { EVENT_HYPERLINK_END_INDEX_CHANGED = 81U };

  /**
   * The number of anchors assoicated with this hyperlink object has changed.
   */
  enum { EVENT_HYPERLINK_NUMBER_OF_ANCHORS_CHANGED = 82U };

  /**
   * The hyperlink selected state changed from selected to unselected or
   * from unselected to selected.
   */
  enum { EVENT_HYPERLINK_SELECTED_LINK_CHANGED = 83U };

  /**
   * One of the links associated with the hypertext object has been activated.
   */
  enum { EVENT_HYPERTEXT_LINK_ACTIVATED = 84U };

  /**
   * One of the links associated with the hypertext object has been selected.
   */
  enum { EVENT_HYPERTEXT_LINK_SELECTED = 85U };

  /**
   * The starting index of this link within the containing string has changed.
   */
  enum { EVENT_HYPERLINK_START_INDEX_CHANGED = 86U };

  /**
   * Focus has changed from one hypertext object to another, or focus moved
   * from a non-hypertext object to a hypertext object, or focus moved from a
   * hypertext object to a non-hypertext object.
   */
  enum { EVENT_HYPERTEXT_CHANGED = 87U };

  /**
   * The number of hyperlinks associated with a hypertext object changed.
   */
  enum { EVENT_HYPERTEXT_NLINKS_CHANGED = 88U };

  /**
   * An object's attributes changed. Also see EVENT_TEXT_ATTRIBUTE_CHANGED.
   */
  enum { EVENT_OBJECT_ATTRIBUTE_CHANGED = 89U };

  /**
   * A slide changed in a presentation document or a page boundary was
   * crossed in a word processing document.
   */
  enum { EVENT_PAGE_CHANGED = 90U };

  /**
   * Used internally in Gecko.
   */
  enum { EVENT_INTERNAL_LOAD = 91U };

  /**
   * An object's children have changed
   */
  enum { EVENT_REORDER = 92U };

  /**
   * Help make sure event map does not get out-of-line.
   */
  enum { EVENT_LAST_ENTRY = 93U };

  /**
   * The type of event, based on the enumerated event values
   * defined in this interface.
   */
  /* readonly attribute unsigned long eventType; */
  NS_SCRIPTABLE NS_IMETHOD GetEventType(PRUint32 *aEventType) = 0;

  /**
   * The nsIAccessible associated with the event.
   * May return null if no accessible is available
   */
  /* readonly attribute nsIAccessible accessible; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessible(nsIAccessible * *aAccessible) = 0;

  /**
   * The nsIAccessibleDocument that the event target nsIAccessible
   * resides in. This can be used to get the DOM window,
   * the DOM document and the window handler, among other things.
   */
  /* readonly attribute nsIAccessibleDocument accessibleDocument; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument) = 0;

  /**
   * The nsIDOMNode associated with the event
   * May return null if accessible for event has been shut down
   */
  /* readonly attribute nsIDOMNode DOMNode; */
  NS_SCRIPTABLE NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) = 0;

  /**
   * Returns true if the event was caused by explicit user input,
   * as opposed to purely originating from a timer or mouse movement
   */
  /* attribute boolean isFromUserInput; */
  NS_SCRIPTABLE NS_IMETHOD GetIsFromUserInput(PRBool *aIsFromUserInput) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIsFromUserInput(PRBool aIsFromUserInput) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleEvent, NS_IACCESSIBLEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetEventType(PRUint32 *aEventType); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessible(nsIAccessible * *aAccessible); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode); \
  NS_SCRIPTABLE NS_IMETHOD GetIsFromUserInput(PRBool *aIsFromUserInput); \
  NS_SCRIPTABLE NS_IMETHOD SetIsFromUserInput(PRBool aIsFromUserInput); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEventType(PRUint32 *aEventType) { return _to GetEventType(aEventType); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessible(nsIAccessible * *aAccessible) { return _to GetAccessible(aAccessible); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument) { return _to GetAccessibleDocument(aAccessibleDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) { return _to GetDOMNode(aDOMNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsFromUserInput(PRBool *aIsFromUserInput) { return _to GetIsFromUserInput(aIsFromUserInput); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsFromUserInput(PRBool aIsFromUserInput) { return _to SetIsFromUserInput(aIsFromUserInput); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEventType(PRUint32 *aEventType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventType(aEventType); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessible(nsIAccessible * *aAccessible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessible(aAccessible); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleDocument(aAccessibleDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMNode(aDOMNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsFromUserInput(PRBool *aIsFromUserInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFromUserInput(aIsFromUserInput); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsFromUserInput(PRBool aIsFromUserInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsFromUserInput(aIsFromUserInput); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleEvent : public nsIAccessibleEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEEVENT

  nsAccessibleEvent();

private:
  ~nsAccessibleEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleEvent, nsIAccessibleEvent)

nsAccessibleEvent::nsAccessibleEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleEvent::~nsAccessibleEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long eventType; */
NS_IMETHODIMP nsAccessibleEvent::GetEventType(PRUint32 *aEventType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible accessible; */
NS_IMETHODIMP nsAccessibleEvent::GetAccessible(nsIAccessible * *aAccessible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleDocument accessibleDocument; */
NS_IMETHODIMP nsAccessibleEvent::GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode DOMNode; */
NS_IMETHODIMP nsAccessibleEvent::GetDOMNode(nsIDOMNode * *aDOMNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isFromUserInput; */
NS_IMETHODIMP nsAccessibleEvent::GetIsFromUserInput(PRBool *aIsFromUserInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAccessibleEvent::SetIsFromUserInput(PRBool aIsFromUserInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccessibleStateChangeEvent */
#define NS_IACCESSIBLESTATECHANGEEVENT_IID_STR "444db51a-05fd-4576-8a64-32dbb2a83884"

#define NS_IACCESSIBLESTATECHANGEEVENT_IID \
  {0x444db51a, 0x05fd, 0x4576, \
    { 0x8a, 0x64, 0x32, 0xdb, 0xb2, 0xa8, 0x38, 0x84 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleStateChangeEvent : public nsIAccessibleEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLESTATECHANGEEVENT_IID)

  /**
   * Returns the state of accessible (see constants declared
   * in nsIAccessibleStates).
   */
  /* readonly attribute unsigned long state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState) = 0;

  /**
   * Returns true if the state is extra state.
   */
  /* boolean isExtraState (); */
  NS_SCRIPTABLE NS_IMETHOD IsExtraState(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Returns true if the state is turned on.
   */
  /* boolean isEnabled (); */
  NS_SCRIPTABLE NS_IMETHOD IsEnabled(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleStateChangeEvent, NS_IACCESSIBLESTATECHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLESTATECHANGEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState); \
  NS_SCRIPTABLE NS_IMETHOD IsExtraState(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsEnabled(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLESTATECHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState) { return _to GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD IsExtraState(PRBool *_retval NS_OUTPARAM) { return _to IsExtraState(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEnabled(PRBool *_retval NS_OUTPARAM) { return _to IsEnabled(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLESTATECHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD IsExtraState(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsExtraState(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEnabled(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEnabled(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleStateChangeEvent : public nsIAccessibleStateChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLESTATECHANGEEVENT

  nsAccessibleStateChangeEvent();

private:
  ~nsAccessibleStateChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleStateChangeEvent, nsIAccessibleStateChangeEvent)

nsAccessibleStateChangeEvent::nsAccessibleStateChangeEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleStateChangeEvent::~nsAccessibleStateChangeEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long state; */
NS_IMETHODIMP nsAccessibleStateChangeEvent::GetState(PRUint32 *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isExtraState (); */
NS_IMETHODIMP nsAccessibleStateChangeEvent::IsExtraState(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEnabled (); */
NS_IMETHODIMP nsAccessibleStateChangeEvent::IsEnabled(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccessibleTextChangeEvent */
#define NS_IACCESSIBLETEXTCHANGEEVENT_IID_STR "50a1e151-8e5f-4bcc-aaaf-a4bed1190e93"

#define NS_IACCESSIBLETEXTCHANGEEVENT_IID \
  {0x50a1e151, 0x8e5f, 0x4bcc, \
    { 0xaa, 0xaf, 0xa4, 0xbe, 0xd1, 0x19, 0x0e, 0x93 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleTextChangeEvent : public nsIAccessibleEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETEXTCHANGEEVENT_IID)

  /**
   * Returns offset of changed text in accessible.
   */
  /* readonly attribute long start; */
  NS_SCRIPTABLE NS_IMETHOD GetStart(PRInt32 *aStart) = 0;

  /**
   * Returns length of changed text.
   */
  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /**
   * Returns true if text was inserted, otherwise false.
   */
  /* boolean isInserted (); */
  NS_SCRIPTABLE NS_IMETHOD IsInserted(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * The inserted or removed text
   */
  /* readonly attribute DOMString modifiedText; */
  NS_SCRIPTABLE NS_IMETHOD GetModifiedText(nsAString & aModifiedText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTextChangeEvent, NS_IACCESSIBLETEXTCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETEXTCHANGEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetStart(PRInt32 *aStart); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD IsInserted(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetModifiedText(nsAString & aModifiedText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETEXTCHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStart(PRInt32 *aStart) { return _to GetStart(aStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD IsInserted(PRBool *_retval NS_OUTPARAM) { return _to IsInserted(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetModifiedText(nsAString & aModifiedText) { return _to GetModifiedText(aModifiedText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETEXTCHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStart(PRInt32 *aStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStart(aStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD IsInserted(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsInserted(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetModifiedText(nsAString & aModifiedText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModifiedText(aModifiedText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTextChangeEvent : public nsIAccessibleTextChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETEXTCHANGEEVENT

  nsAccessibleTextChangeEvent();

private:
  ~nsAccessibleTextChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleTextChangeEvent, nsIAccessibleTextChangeEvent)

nsAccessibleTextChangeEvent::nsAccessibleTextChangeEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleTextChangeEvent::~nsAccessibleTextChangeEvent()
{
  /* destructor code */
}

/* readonly attribute long start; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetStart(PRInt32 *aStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isInserted (); */
NS_IMETHODIMP nsAccessibleTextChangeEvent::IsInserted(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString modifiedText; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetModifiedText(nsAString & aModifiedText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccessibleCaretMoveEvent */
#define NS_IACCESSIBLECARETMOVEEVENT_IID_STR "b9076dce-4cd3-4e3d-a7f6-7f33a7f40c31"

#define NS_IACCESSIBLECARETMOVEEVENT_IID \
  {0xb9076dce, 0x4cd3, 0x4e3d, \
    { 0xa7, 0xf6, 0x7f, 0x33, 0xa7, 0xf4, 0x0c, 0x31 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleCaretMoveEvent : public nsIAccessibleEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLECARETMOVEEVENT_IID)

  /**
   * Return caret offset.
   */
  /* readonly attribute long caretOffset; */
  NS_SCRIPTABLE NS_IMETHOD GetCaretOffset(PRInt32 *aCaretOffset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleCaretMoveEvent, NS_IACCESSIBLECARETMOVEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLECARETMOVEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetCaretOffset(PRInt32 *aCaretOffset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLECARETMOVEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCaretOffset(PRInt32 *aCaretOffset) { return _to GetCaretOffset(aCaretOffset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLECARETMOVEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCaretOffset(PRInt32 *aCaretOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaretOffset(aCaretOffset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleCaretMoveEvent : public nsIAccessibleCaretMoveEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLECARETMOVEEVENT

  nsAccessibleCaretMoveEvent();

private:
  ~nsAccessibleCaretMoveEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleCaretMoveEvent, nsIAccessibleCaretMoveEvent)

nsAccessibleCaretMoveEvent::nsAccessibleCaretMoveEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleCaretMoveEvent::~nsAccessibleCaretMoveEvent()
{
  /* destructor code */
}

/* readonly attribute long caretOffset; */
NS_IMETHODIMP nsAccessibleCaretMoveEvent::GetCaretOffset(PRInt32 *aCaretOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccessibleTableChangeEvent */
#define NS_IACCESSIBLETABLECHANGEEVENT_IID_STR "a9485c7b-5861-4695-8441-fab0235b205d"

#define NS_IACCESSIBLETABLECHANGEEVENT_IID \
  {0xa9485c7b, 0x5861, 0x4695, \
    { 0x84, 0x41, 0xfa, 0xb0, 0x23, 0x5b, 0x20, 0x5d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleTableChangeEvent : public nsIAccessibleEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETABLECHANGEEVENT_IID)

  /**
   * Return the row or column index.
   */
  /* readonly attribute long rowOrColIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetRowOrColIndex(PRInt32 *aRowOrColIndex) = 0;

  /**
   * Return the number of rows or cols
   */
  /* readonly attribute long numRowsOrCols; */
  NS_SCRIPTABLE NS_IMETHOD GetNumRowsOrCols(PRInt32 *aNumRowsOrCols) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTableChangeEvent, NS_IACCESSIBLETABLECHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETABLECHANGEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetRowOrColIndex(PRInt32 *aRowOrColIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetNumRowsOrCols(PRInt32 *aNumRowsOrCols); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETABLECHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRowOrColIndex(PRInt32 *aRowOrColIndex) { return _to GetRowOrColIndex(aRowOrColIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumRowsOrCols(PRInt32 *aNumRowsOrCols) { return _to GetNumRowsOrCols(aNumRowsOrCols); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETABLECHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRowOrColIndex(PRInt32 *aRowOrColIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowOrColIndex(aRowOrColIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumRowsOrCols(PRInt32 *aNumRowsOrCols) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumRowsOrCols(aNumRowsOrCols); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTableChangeEvent : public nsIAccessibleTableChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETABLECHANGEEVENT

  nsAccessibleTableChangeEvent();

private:
  ~nsAccessibleTableChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleTableChangeEvent, nsIAccessibleTableChangeEvent)

nsAccessibleTableChangeEvent::nsAccessibleTableChangeEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleTableChangeEvent::~nsAccessibleTableChangeEvent()
{
  /* destructor code */
}

/* readonly attribute long rowOrColIndex; */
NS_IMETHODIMP nsAccessibleTableChangeEvent::GetRowOrColIndex(PRInt32 *aRowOrColIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numRowsOrCols; */
NS_IMETHODIMP nsAccessibleTableChangeEvent::GetNumRowsOrCols(PRInt32 *aNumRowsOrCols)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleEvent_h__ */
