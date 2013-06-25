/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMNSEvent.idl
 */

#ifndef __gen_nsIDOMNSEvent_h__
#define __gen_nsIDOMNSEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef ERROR
#undef ERROR
#endif

/* starting interface:    nsIDOMNSEvent */
#define NS_IDOMNSEVENT_IID_STR "e565d518-4510-407f-a3d9-3b4107549c6d"

#define NS_IDOMNSEVENT_IID \
  {0xe565d518, 0x4510, 0x407f, \
    { 0xa3, 0xd9, 0x3b, 0x41, 0x07, 0x54, 0x9c, 0x6d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSEvent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSEVENT_IID)

  enum { MOUSEDOWN = 1 };

  enum { MOUSEUP = 2 };

  enum { MOUSEOVER = 4 };

  enum { MOUSEOUT = 8 };

  enum { MOUSEMOVE = 16 };

  enum { MOUSEDRAG = 32 };

  enum { CLICK = 64 };

  enum { DBLCLICK = 128 };

  enum { KEYDOWN = 256 };

  enum { KEYUP = 512 };

  enum { KEYPRESS = 1024 };

  enum { DRAGDROP = 2048 };

  enum { FOCUS = 4096 };

  enum { BLUR = 8192 };

  enum { SELECT = 16384 };

  enum { CHANGE = 32768 };

  enum { RESET = 65536 };

  enum { SUBMIT = 131072 };

  enum { SCROLL = 262144 };

  enum { LOAD = 524288 };

  enum { UNLOAD = 1048576 };

  enum { XFER_DONE = 2097152 };

  enum { ABORT = 4194304 };

  enum { ERROR = 8388608 };

  enum { LOCATE = 16777216 };

  enum { MOVE = 33554432 };

  enum { RESIZE = 67108864 };

  enum { FORWARD = 134217728 };

  enum { HELP = 268435456 };

  enum { BACK = 536870912 };

  enum { TEXT = 1073741824 };

  enum { ALT_MASK = 1 };

  enum { CONTROL_MASK = 2 };

  enum { SHIFT_MASK = 4 };

  enum { META_MASK = 8 };

  /** The original target of the event, before any retargetings. */
  /* readonly attribute nsIDOMEventTarget originalTarget; */
  NS_SCRIPTABLE NS_IMETHOD GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget) = 0;

  /**
   * The explicit original target of the event.  If the event was retargeted
   * for some reason other than an anonymous boundary crossing, this will be set
   * to the target before the retargeting occurs.  For example, mouse events
   * are retargeted to their parent node when they happen over text nodes (bug
   * 185889), and in that case .target will show the parent and
   * .explicitOriginalTarget will show the text node.
   * .explicitOriginalTarget differs from .originalTarget in that it will never
   * contain anonymous content.
   */
  /* readonly attribute nsIDOMEventTarget explicitOriginalTarget; */
  NS_SCRIPTABLE NS_IMETHOD GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget) = 0;

  /* [noscript] readonly attribute nsIDOMEventTarget tmpRealOriginalTarget; */
  NS_IMETHOD GetTmpRealOriginalTarget(nsIDOMEventTarget * *aTmpRealOriginalTarget) = 0;

  /**
   * @deprecated Use nsIDOMEvent::stopPropagation.
   */
  /* void preventBubble (); */
  NS_SCRIPTABLE NS_IMETHOD PreventBubble(void) = 0;

  /**
   * @deprecated Use nsIDOMEvent::stopPropagation.
   */
  /* void preventCapture (); */
  NS_SCRIPTABLE NS_IMETHOD PreventCapture(void) = 0;

  /* readonly attribute boolean isTrusted; */
  NS_SCRIPTABLE NS_IMETHOD GetIsTrusted(PRBool *aIsTrusted) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSEvent, NS_IDOMNSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget); \
  NS_SCRIPTABLE NS_IMETHOD GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget); \
  NS_IMETHOD GetTmpRealOriginalTarget(nsIDOMEventTarget * *aTmpRealOriginalTarget); \
  NS_SCRIPTABLE NS_IMETHOD PreventBubble(void); \
  NS_SCRIPTABLE NS_IMETHOD PreventCapture(void); \
  NS_SCRIPTABLE NS_IMETHOD GetIsTrusted(PRBool *aIsTrusted); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget) { return _to GetOriginalTarget(aOriginalTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget) { return _to GetExplicitOriginalTarget(aExplicitOriginalTarget); } \
  NS_IMETHOD GetTmpRealOriginalTarget(nsIDOMEventTarget * *aTmpRealOriginalTarget) { return _to GetTmpRealOriginalTarget(aTmpRealOriginalTarget); } \
  NS_SCRIPTABLE NS_IMETHOD PreventBubble(void) { return _to PreventBubble(); } \
  NS_SCRIPTABLE NS_IMETHOD PreventCapture(void) { return _to PreventCapture(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsTrusted(PRBool *aIsTrusted) { return _to GetIsTrusted(aIsTrusted); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginalTarget(aOriginalTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExplicitOriginalTarget(aExplicitOriginalTarget); } \
  NS_IMETHOD GetTmpRealOriginalTarget(nsIDOMEventTarget * *aTmpRealOriginalTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTmpRealOriginalTarget(aTmpRealOriginalTarget); } \
  NS_SCRIPTABLE NS_IMETHOD PreventBubble(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreventBubble(); } \
  NS_SCRIPTABLE NS_IMETHOD PreventCapture(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreventCapture(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsTrusted(PRBool *aIsTrusted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTrusted(aIsTrusted); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSEvent : public nsIDOMNSEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSEVENT

  nsDOMNSEvent();

private:
  ~nsDOMNSEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSEvent, nsIDOMNSEvent)

nsDOMNSEvent::nsDOMNSEvent()
{
  /* member initializers and constructor code */
}

nsDOMNSEvent::~nsDOMNSEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMEventTarget originalTarget; */
NS_IMETHODIMP nsDOMNSEvent::GetOriginalTarget(nsIDOMEventTarget * *aOriginalTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEventTarget explicitOriginalTarget; */
NS_IMETHODIMP nsDOMNSEvent::GetExplicitOriginalTarget(nsIDOMEventTarget * *aExplicitOriginalTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMEventTarget tmpRealOriginalTarget; */
NS_IMETHODIMP nsDOMNSEvent::GetTmpRealOriginalTarget(nsIDOMEventTarget * *aTmpRealOriginalTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preventBubble (); */
NS_IMETHODIMP nsDOMNSEvent::PreventBubble()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preventCapture (); */
NS_IMETHODIMP nsDOMNSEvent::PreventCapture()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isTrusted; */
NS_IMETHODIMP nsDOMNSEvent::GetIsTrusted(PRBool *aIsTrusted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSEvent_h__ */
