/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULCommandEvent.idl
 */

#ifndef __gen_nsIDOMXULCommandEvent_h__
#define __gen_nsIDOMXULCommandEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULCommandEvent */
#define NS_IDOMXULCOMMANDEVENT_IID_STR "f9fa8205-a988-4828-9228-f3332d5475ac"

#define NS_IDOMXULCOMMANDEVENT_IID \
  {0xf9fa8205, 0xa988, 0x4828, \
    { 0x92, 0x28, 0xf3, 0x33, 0x2d, 0x54, 0x75, 0xac }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULCommandEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCOMMANDEVENT_IID)

  /**
   * Command events support the same set of modifier keys as mouse and key
   * events.
   */
  /* readonly attribute boolean ctrlKey; */
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(PRBool *aCtrlKey) = 0;

  /* readonly attribute boolean shiftKey; */
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(PRBool *aShiftKey) = 0;

  /* readonly attribute boolean altKey; */
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(PRBool *aAltKey) = 0;

  /* readonly attribute boolean metaKey; */
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(PRBool *aMetaKey) = 0;

  /**
   * If the command event was redispatched because of a command= attribute
   * on the original target, sourceEvent will be set to the original DOM Event.
   * Otherwise, sourceEvent is null.
   */
  /* readonly attribute nsIDOMEvent sourceEvent; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent) = 0;

  /**
   * Creates a new command event with the given attributes.
   */
  /* void initCommandEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in long detailArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in nsIDOMEvent sourceEvent); */
  NS_SCRIPTABLE NS_IMETHOD InitCommandEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, nsIDOMEvent *sourceEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULCommandEvent, NS_IDOMXULCOMMANDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCOMMANDEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(PRBool *aCtrlKey); \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(PRBool *aShiftKey); \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(PRBool *aAltKey); \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(PRBool *aMetaKey); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent); \
  NS_SCRIPTABLE NS_IMETHOD InitCommandEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, nsIDOMEvent *sourceEvent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCOMMANDEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(PRBool *aCtrlKey) { return _to GetCtrlKey(aCtrlKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(PRBool *aShiftKey) { return _to GetShiftKey(aShiftKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(PRBool *aAltKey) { return _to GetAltKey(aAltKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(PRBool *aMetaKey) { return _to GetMetaKey(aMetaKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent) { return _to GetSourceEvent(aSourceEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InitCommandEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, nsIDOMEvent *sourceEvent) { return _to InitCommandEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, sourceEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCOMMANDEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(PRBool *aCtrlKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCtrlKey(aCtrlKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(PRBool *aShiftKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShiftKey(aShiftKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(PRBool *aAltKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAltKey(aAltKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(PRBool *aMetaKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaKey(aMetaKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceEvent(aSourceEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InitCommandEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, nsIDOMEvent *sourceEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCommandEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, sourceEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULCommandEvent : public nsIDOMXULCommandEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCOMMANDEVENT

  nsDOMXULCommandEvent();

private:
  ~nsDOMXULCommandEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULCommandEvent, nsIDOMXULCommandEvent)

nsDOMXULCommandEvent::nsDOMXULCommandEvent()
{
  /* member initializers and constructor code */
}

nsDOMXULCommandEvent::~nsDOMXULCommandEvent()
{
  /* destructor code */
}

/* readonly attribute boolean ctrlKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetCtrlKey(PRBool *aCtrlKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shiftKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetShiftKey(PRBool *aShiftKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean altKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetAltKey(PRBool *aAltKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean metaKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetMetaKey(PRBool *aMetaKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEvent sourceEvent; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetSourceEvent(nsIDOMEvent * *aSourceEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCommandEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in long detailArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in nsIDOMEvent sourceEvent); */
NS_IMETHODIMP nsDOMXULCommandEvent::InitCommandEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, nsIDOMEvent *sourceEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULCommandEvent_h__ */
