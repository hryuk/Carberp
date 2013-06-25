/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMMessageEvent.idl
 */

#ifndef __gen_nsIDOMMessageEvent_h__
#define __gen_nsIDOMMessageEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMessageEvent */
#define NS_IDOMMESSAGEEVENT_IID_STR "98150805-6a15-4667-815a-1a8c87cb4bbc"

#define NS_IDOMMESSAGEEVENT_IID \
  {0x98150805, 0x6a15, 0x4667, \
    { 0x81, 0x5a, 0x1a, 0x8c, 0x87, 0xcb, 0x4b, 0xbc }}

/**
 * The nsIDOMMessageEvent interface is used for server-sent events and for
 * cross-domain messaging.
 *
 * For more information on this interface, please see
 * http://www.whatwg.org/specs/web-apps/current-work/#messageevent
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMMessageEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMESSAGEEVENT_IID)

  /**
   * Custom string data associated with this event.
   */
  /* readonly attribute DOMString data; */
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) = 0;

  /**
   * The origin of the site from which this event originated, which is the
   * scheme, ":", and if the URI has a host, "//" followed by the
   * host, and if the port is not the default for the given scheme,
   * ":" followed by that port.  This value does not have a trailing slash.
   */
  /* readonly attribute DOMString origin; */
  NS_SCRIPTABLE NS_IMETHOD GetOrigin(nsAString & aOrigin) = 0;

  /**
   * The last event ID string of the event source, for server-sent DOM events; this
   * value is the empty string for cross-origin messaging.
   */
  /* readonly attribute DOMString lastEventId; */
  NS_SCRIPTABLE NS_IMETHOD GetLastEventId(nsAString & aLastEventId) = 0;

  /**
   * The window which originated this event.
   */
  /* readonly attribute nsIDOMWindow source; */
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIDOMWindow * *aSource) = 0;

  /**
   * Initializes this event with the given data, in a manner analogous to
   * the similarly-named method on the nsIDOMEvent interface, also setting the
   * data, origin, source, and lastEventId attributes of this appropriately.
   */
  /* void initMessageEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aData, in DOMString aOrigin, in DOMString aLastEventId, in nsIDOMWindow aSource); */
  NS_SCRIPTABLE NS_IMETHOD InitMessageEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource) = 0;

  /**
   * Initializes this event with the given data, in a manner analogous to
   * the similarly-named method on the Event interface, also setting the data,
   * origin, source, and lastEventId attributes of this appropriately.
   */
  /* void initMessageEventNS (in DOMString aNamespaceURI, in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aData, in DOMString aOrigin, in DOMString aLastEventId, in nsIDOMWindow aSource); */
  NS_SCRIPTABLE NS_IMETHOD InitMessageEventNS(const nsAString & aNamespaceURI, const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMessageEvent, NS_IDOMMESSAGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMESSAGEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData); \
  NS_SCRIPTABLE NS_IMETHOD GetOrigin(nsAString & aOrigin); \
  NS_SCRIPTABLE NS_IMETHOD GetLastEventId(nsAString & aLastEventId); \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIDOMWindow * *aSource); \
  NS_SCRIPTABLE NS_IMETHOD InitMessageEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource); \
  NS_SCRIPTABLE NS_IMETHOD InitMessageEventNS(const nsAString & aNamespaceURI, const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMESSAGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) { return _to GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrigin(nsAString & aOrigin) { return _to GetOrigin(aOrigin); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastEventId(nsAString & aLastEventId) { return _to GetLastEventId(aLastEventId); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIDOMWindow * *aSource) { return _to GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitMessageEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource) { return _to InitMessageEvent(aType, aCanBubble, aCancelable, aData, aOrigin, aLastEventId, aSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitMessageEventNS(const nsAString & aNamespaceURI, const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource) { return _to InitMessageEventNS(aNamespaceURI, aType, aCanBubble, aCancelable, aData, aOrigin, aLastEventId, aSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMESSAGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrigin(nsAString & aOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrigin(aOrigin); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastEventId(nsAString & aLastEventId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastEventId(aLastEventId); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIDOMWindow * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitMessageEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMessageEvent(aType, aCanBubble, aCancelable, aData, aOrigin, aLastEventId, aSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitMessageEventNS(const nsAString & aNamespaceURI, const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMessageEventNS(aNamespaceURI, aType, aCanBubble, aCancelable, aData, aOrigin, aLastEventId, aSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMessageEvent : public nsIDOMMessageEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMESSAGEEVENT

  nsDOMMessageEvent();

private:
  ~nsDOMMessageEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMessageEvent, nsIDOMMessageEvent)

nsDOMMessageEvent::nsDOMMessageEvent()
{
  /* member initializers and constructor code */
}

nsDOMMessageEvent::~nsDOMMessageEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString data; */
NS_IMETHODIMP nsDOMMessageEvent::GetData(nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString origin; */
NS_IMETHODIMP nsDOMMessageEvent::GetOrigin(nsAString & aOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastEventId; */
NS_IMETHODIMP nsDOMMessageEvent::GetLastEventId(nsAString & aLastEventId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow source; */
NS_IMETHODIMP nsDOMMessageEvent::GetSource(nsIDOMWindow * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initMessageEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aData, in DOMString aOrigin, in DOMString aLastEventId, in nsIDOMWindow aSource); */
NS_IMETHODIMP nsDOMMessageEvent::InitMessageEvent(const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initMessageEventNS (in DOMString aNamespaceURI, in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aData, in DOMString aOrigin, in DOMString aLastEventId, in nsIDOMWindow aSource); */
NS_IMETHODIMP nsDOMMessageEvent::InitMessageEventNS(const nsAString & aNamespaceURI, const nsAString & aType, PRBool aCanBubble, PRBool aCancelable, const nsAString & aData, const nsAString & aOrigin, const nsAString & aLastEventId, nsIDOMWindow *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMessageEvent_h__ */
