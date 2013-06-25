/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMSimpleGestureEvent.idl
 */

#ifndef __gen_nsIDOMSimpleGestureEvent_h__
#define __gen_nsIDOMSimpleGestureEvent_h__


#ifndef __gen_nsIDOMMouseEvent_h__
#include "nsIDOMMouseEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSimpleGestureEvent */
#define NS_IDOMSIMPLEGESTUREEVENT_IID_STR "cb68e879-f710-415d-a871-9a550860df01"

#define NS_IDOMSIMPLEGESTUREEVENT_IID \
  {0xcb68e879, 0xf710, 0x415d, \
    { 0xa8, 0x71, 0x9a, 0x55, 0x08, 0x60, 0xdf, 0x01 }}

/**
 * The nsIDOMSimpleGestureEvent interface is the datatype for all
 * Mozilla-specific simple gesture events in the Document Object Model.
 *
 * The following events are generated:
 *
 * MozSwipeGesture - Generated when the user completes a swipe across
 * across the input device.
 *
 * MozMagnifyGestureStart - Generated when the user begins the magnify
 * ("pinch") gesture.  The "delta" value represents the initial
 * movement.
 *
 * MozMagnifyGestureUpdate - Generated periodically while the user is
 * continuing the magnify ("pinch") gesture.  The "delta" value
 * represents the movement since the last MozMagnifyGestureStart or
 * MozMagnifyGestureUpdate event.
 *
 * MozMagnifyGesture - Generated when the user has completed the
 * magnify ("pinch") gesture.  If you only want to receive a single
 * event when the magnify gesture is complete, you only need to hook
 * this event and can safely ignore the MozMagnifyGestureStart and the
 * MozMagnifyGestureUpdate events. The "delta" value is the cumulative
 * amount represented by the user's gesture.
 *
 * MozRotateGestureStart - Generated when the user begins the rotation
 * gesture.  The "delta" value represents the initial rotation.
 *
 * MozRotateGestureUpdate - Generated periodically while the user is
 * continuing the rotation gesture.  The "delta" value represents the
 * rotation since the last MozRotateGestureStart or
 * MozRotateGestureUpdate event.
 *
 * MozRotateGesture - Generated when the user has completed the
 * rotation gesture.  If you only want to receive a single event when
 * the rotation gesture is complete, you only need to hook this event
 * and can safely ignore the MozRotateGestureStart and the
 * MozRotateGestureUpdate events.  The "delta" value is the cumulative
 * amount of rotation represented by the user's gesture.
 *
 * MozTapGesture - Generated when the user executes a two finger
 * tap gesture on the input device. Client coordinates contain the
 * center point of the tap.
 * (XXX Not implemented on Mac)
 *
 * MozPressTapGesture - Generated when the user executes a press
 * and tap two finger gesture (first finger down, second finger down,
 * second finger up, first finger up) on the input device.
 * Client coordinates contain the center pivot point of the action.
 * (XXX Not implemented on Mac)
 *
 * Default behavior:
 *
 * Some operating systems support default behaviors for gesture events
 * when they are not handled by the application. Consumers should
 * use event.preventDefault() to prevent default behavior when
 * consuming events.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSimpleGestureEvent : public nsIDOMMouseEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSIMPLEGESTUREEVENT_IID)

  enum { DIRECTION_UP = 1U };

  enum { DIRECTION_DOWN = 2U };

  enum { DIRECTION_LEFT = 4U };

  enum { DIRECTION_RIGHT = 8U };

  enum { ROTATION_COUNTERCLOCKWISE = 1U };

  enum { ROTATION_CLOCKWISE = 2U };

  /* readonly attribute unsigned long direction; */
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRUint32 *aDirection) = 0;

  /* readonly attribute double delta; */
  NS_SCRIPTABLE NS_IMETHOD GetDelta(double *aDelta) = 0;

  /* void initSimpleGestureEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in unsigned long directionArg, in double deltaArg); */
  NS_SCRIPTABLE NS_IMETHOD InitSimpleGestureEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRUint32 directionArg, double deltaArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSimpleGestureEvent, NS_IDOMSIMPLEGESTUREEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSIMPLEGESTUREEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRUint32 *aDirection); \
  NS_SCRIPTABLE NS_IMETHOD GetDelta(double *aDelta); \
  NS_SCRIPTABLE NS_IMETHOD InitSimpleGestureEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRUint32 directionArg, double deltaArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSIMPLEGESTUREEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRUint32 *aDirection) { return _to GetDirection(aDirection); } \
  NS_SCRIPTABLE NS_IMETHOD GetDelta(double *aDelta) { return _to GetDelta(aDelta); } \
  NS_SCRIPTABLE NS_IMETHOD InitSimpleGestureEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRUint32 directionArg, double deltaArg) { return _to InitSimpleGestureEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, directionArg, deltaArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSIMPLEGESTUREEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRUint32 *aDirection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirection(aDirection); } \
  NS_SCRIPTABLE NS_IMETHOD GetDelta(double *aDelta) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelta(aDelta); } \
  NS_SCRIPTABLE NS_IMETHOD InitSimpleGestureEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRUint32 directionArg, double deltaArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitSimpleGestureEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, directionArg, deltaArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSimpleGestureEvent : public nsIDOMSimpleGestureEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSIMPLEGESTUREEVENT

  nsDOMSimpleGestureEvent();

private:
  ~nsDOMSimpleGestureEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSimpleGestureEvent, nsIDOMSimpleGestureEvent)

nsDOMSimpleGestureEvent::nsDOMSimpleGestureEvent()
{
  /* member initializers and constructor code */
}

nsDOMSimpleGestureEvent::~nsDOMSimpleGestureEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long direction; */
NS_IMETHODIMP nsDOMSimpleGestureEvent::GetDirection(PRUint32 *aDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double delta; */
NS_IMETHODIMP nsDOMSimpleGestureEvent::GetDelta(double *aDelta)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initSimpleGestureEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in unsigned long directionArg, in double deltaArg); */
NS_IMETHODIMP nsDOMSimpleGestureEvent::InitSimpleGestureEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRUint32 directionArg, double deltaArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSimpleGestureEvent_h__ */
