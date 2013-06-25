/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMKeyEvent.idl
 */

#ifndef __gen_nsIDOMKeyEvent_h__
#define __gen_nsIDOMKeyEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMKeyEvent */
#define NS_IDOMKEYEVENT_IID_STR "028e0e6e-8b01-11d3-aae7-0010838a3123"

#define NS_IDOMKEYEVENT_IID \
  {0x028e0e6e, 0x8b01, 0x11d3, \
    { 0xaa, 0xe7, 0x00, 0x10, 0x83, 0x8a, 0x31, 0x23 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMKeyEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMKEYEVENT_IID)

  enum { DOM_VK_CANCEL = 3U };

  enum { DOM_VK_HELP = 6U };

  enum { DOM_VK_BACK_SPACE = 8U };

  enum { DOM_VK_TAB = 9U };

  enum { DOM_VK_CLEAR = 12U };

  enum { DOM_VK_RETURN = 13U };

  enum { DOM_VK_ENTER = 14U };

  enum { DOM_VK_SHIFT = 16U };

  enum { DOM_VK_CONTROL = 17U };

  enum { DOM_VK_ALT = 18U };

  enum { DOM_VK_PAUSE = 19U };

  enum { DOM_VK_CAPS_LOCK = 20U };

  enum { DOM_VK_ESCAPE = 27U };

  enum { DOM_VK_SPACE = 32U };

  enum { DOM_VK_PAGE_UP = 33U };

  enum { DOM_VK_PAGE_DOWN = 34U };

  enum { DOM_VK_END = 35U };

  enum { DOM_VK_HOME = 36U };

  enum { DOM_VK_LEFT = 37U };

  enum { DOM_VK_UP = 38U };

  enum { DOM_VK_RIGHT = 39U };

  enum { DOM_VK_DOWN = 40U };

  enum { DOM_VK_PRINTSCREEN = 44U };

  enum { DOM_VK_INSERT = 45U };

  enum { DOM_VK_DELETE = 46U };

  enum { DOM_VK_0 = 48U };

  enum { DOM_VK_1 = 49U };

  enum { DOM_VK_2 = 50U };

  enum { DOM_VK_3 = 51U };

  enum { DOM_VK_4 = 52U };

  enum { DOM_VK_5 = 53U };

  enum { DOM_VK_6 = 54U };

  enum { DOM_VK_7 = 55U };

  enum { DOM_VK_8 = 56U };

  enum { DOM_VK_9 = 57U };

  enum { DOM_VK_SEMICOLON = 59U };

  enum { DOM_VK_EQUALS = 61U };

  enum { DOM_VK_A = 65U };

  enum { DOM_VK_B = 66U };

  enum { DOM_VK_C = 67U };

  enum { DOM_VK_D = 68U };

  enum { DOM_VK_E = 69U };

  enum { DOM_VK_F = 70U };

  enum { DOM_VK_G = 71U };

  enum { DOM_VK_H = 72U };

  enum { DOM_VK_I = 73U };

  enum { DOM_VK_J = 74U };

  enum { DOM_VK_K = 75U };

  enum { DOM_VK_L = 76U };

  enum { DOM_VK_M = 77U };

  enum { DOM_VK_N = 78U };

  enum { DOM_VK_O = 79U };

  enum { DOM_VK_P = 80U };

  enum { DOM_VK_Q = 81U };

  enum { DOM_VK_R = 82U };

  enum { DOM_VK_S = 83U };

  enum { DOM_VK_T = 84U };

  enum { DOM_VK_U = 85U };

  enum { DOM_VK_V = 86U };

  enum { DOM_VK_W = 87U };

  enum { DOM_VK_X = 88U };

  enum { DOM_VK_Y = 89U };

  enum { DOM_VK_Z = 90U };

  enum { DOM_VK_CONTEXT_MENU = 93U };

  enum { DOM_VK_NUMPAD0 = 96U };

  enum { DOM_VK_NUMPAD1 = 97U };

  enum { DOM_VK_NUMPAD2 = 98U };

  enum { DOM_VK_NUMPAD3 = 99U };

  enum { DOM_VK_NUMPAD4 = 100U };

  enum { DOM_VK_NUMPAD5 = 101U };

  enum { DOM_VK_NUMPAD6 = 102U };

  enum { DOM_VK_NUMPAD7 = 103U };

  enum { DOM_VK_NUMPAD8 = 104U };

  enum { DOM_VK_NUMPAD9 = 105U };

  enum { DOM_VK_MULTIPLY = 106U };

  enum { DOM_VK_ADD = 107U };

  enum { DOM_VK_SEPARATOR = 108U };

  enum { DOM_VK_SUBTRACT = 109U };

  enum { DOM_VK_DECIMAL = 110U };

  enum { DOM_VK_DIVIDE = 111U };

  enum { DOM_VK_F1 = 112U };

  enum { DOM_VK_F2 = 113U };

  enum { DOM_VK_F3 = 114U };

  enum { DOM_VK_F4 = 115U };

  enum { DOM_VK_F5 = 116U };

  enum { DOM_VK_F6 = 117U };

  enum { DOM_VK_F7 = 118U };

  enum { DOM_VK_F8 = 119U };

  enum { DOM_VK_F9 = 120U };

  enum { DOM_VK_F10 = 121U };

  enum { DOM_VK_F11 = 122U };

  enum { DOM_VK_F12 = 123U };

  enum { DOM_VK_F13 = 124U };

  enum { DOM_VK_F14 = 125U };

  enum { DOM_VK_F15 = 126U };

  enum { DOM_VK_F16 = 127U };

  enum { DOM_VK_F17 = 128U };

  enum { DOM_VK_F18 = 129U };

  enum { DOM_VK_F19 = 130U };

  enum { DOM_VK_F20 = 131U };

  enum { DOM_VK_F21 = 132U };

  enum { DOM_VK_F22 = 133U };

  enum { DOM_VK_F23 = 134U };

  enum { DOM_VK_F24 = 135U };

  enum { DOM_VK_NUM_LOCK = 144U };

  enum { DOM_VK_SCROLL_LOCK = 145U };

  enum { DOM_VK_COMMA = 188U };

  enum { DOM_VK_PERIOD = 190U };

  enum { DOM_VK_SLASH = 191U };

  enum { DOM_VK_BACK_QUOTE = 192U };

  enum { DOM_VK_OPEN_BRACKET = 219U };

  enum { DOM_VK_BACK_SLASH = 220U };

  enum { DOM_VK_CLOSE_BRACKET = 221U };

  enum { DOM_VK_QUOTE = 222U };

  enum { DOM_VK_META = 224U };

  /* readonly attribute unsigned long charCode; */
  NS_SCRIPTABLE NS_IMETHOD GetCharCode(PRUint32 *aCharCode) = 0;

  /* readonly attribute unsigned long keyCode; */
  NS_SCRIPTABLE NS_IMETHOD GetKeyCode(PRUint32 *aKeyCode) = 0;

  /* readonly attribute boolean altKey; */
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(PRBool *aAltKey) = 0;

  /* readonly attribute boolean ctrlKey; */
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(PRBool *aCtrlKey) = 0;

  /* readonly attribute boolean shiftKey; */
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(PRBool *aShiftKey) = 0;

  /* readonly attribute boolean metaKey; */
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(PRBool *aMetaKey) = 0;

  /* void initKeyEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned long keyCodeArg, in unsigned long charCodeArg); */
  NS_SCRIPTABLE NS_IMETHOD InitKeyEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint32 keyCodeArg, PRUint32 charCodeArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMKeyEvent, NS_IDOMKEYEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMKEYEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetCharCode(PRUint32 *aCharCode); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyCode(PRUint32 *aKeyCode); \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(PRBool *aAltKey); \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(PRBool *aCtrlKey); \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(PRBool *aShiftKey); \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(PRBool *aMetaKey); \
  NS_SCRIPTABLE NS_IMETHOD InitKeyEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint32 keyCodeArg, PRUint32 charCodeArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMKEYEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharCode(PRUint32 *aCharCode) { return _to GetCharCode(aCharCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyCode(PRUint32 *aKeyCode) { return _to GetKeyCode(aKeyCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(PRBool *aAltKey) { return _to GetAltKey(aAltKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(PRBool *aCtrlKey) { return _to GetCtrlKey(aCtrlKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(PRBool *aShiftKey) { return _to GetShiftKey(aShiftKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(PRBool *aMetaKey) { return _to GetMetaKey(aMetaKey); } \
  NS_SCRIPTABLE NS_IMETHOD InitKeyEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint32 keyCodeArg, PRUint32 charCodeArg) { return _to InitKeyEvent(typeArg, canBubbleArg, cancelableArg, viewArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, keyCodeArg, charCodeArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMKEYEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharCode(PRUint32 *aCharCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharCode(aCharCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyCode(PRUint32 *aKeyCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyCode(aKeyCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(PRBool *aAltKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAltKey(aAltKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(PRBool *aCtrlKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCtrlKey(aCtrlKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(PRBool *aShiftKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShiftKey(aShiftKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(PRBool *aMetaKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaKey(aMetaKey); } \
  NS_SCRIPTABLE NS_IMETHOD InitKeyEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint32 keyCodeArg, PRUint32 charCodeArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitKeyEvent(typeArg, canBubbleArg, cancelableArg, viewArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, keyCodeArg, charCodeArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMKeyEvent : public nsIDOMKeyEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMKEYEVENT

  nsDOMKeyEvent();

private:
  ~nsDOMKeyEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMKeyEvent, nsIDOMKeyEvent)

nsDOMKeyEvent::nsDOMKeyEvent()
{
  /* member initializers and constructor code */
}

nsDOMKeyEvent::~nsDOMKeyEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long charCode; */
NS_IMETHODIMP nsDOMKeyEvent::GetCharCode(PRUint32 *aCharCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long keyCode; */
NS_IMETHODIMP nsDOMKeyEvent::GetKeyCode(PRUint32 *aKeyCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean altKey; */
NS_IMETHODIMP nsDOMKeyEvent::GetAltKey(PRBool *aAltKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ctrlKey; */
NS_IMETHODIMP nsDOMKeyEvent::GetCtrlKey(PRBool *aCtrlKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shiftKey; */
NS_IMETHODIMP nsDOMKeyEvent::GetShiftKey(PRBool *aShiftKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean metaKey; */
NS_IMETHODIMP nsDOMKeyEvent::GetMetaKey(PRBool *aMetaKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initKeyEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned long keyCodeArg, in unsigned long charCodeArg); */
NS_IMETHODIMP nsDOMKeyEvent::InitKeyEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint32 keyCodeArg, PRUint32 charCodeArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMKeyEvent_h__ */
