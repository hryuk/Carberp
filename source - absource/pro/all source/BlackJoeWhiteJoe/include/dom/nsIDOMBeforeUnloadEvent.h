/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMBeforeUnloadEvent.idl
 */

#ifndef __gen_nsIDOMBeforeUnloadEvent_h__
#define __gen_nsIDOMBeforeUnloadEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMBeforeUnloadEvent */
#define NS_IDOMBEFOREUNLOADEVENT_IID_STR "da19e9dc-dea2-4a1d-a958-9be375c9799c"

#define NS_IDOMBEFOREUNLOADEVENT_IID \
  {0xda19e9dc, 0xdea2, 0x4a1d, \
    { 0xa9, 0x58, 0x9b, 0xe3, 0x75, 0xc9, 0x79, 0x9c }}

/**
 * The nsIDOMBeforeUnloadEvent interface is the interface for events
 * sent to handlers of the "beforeunload" event. This event is
 * non-standard. Interface derived from Microsoft IE's event
 * implementation.
 *
 * http://msdn.microsoft.com/library/default.asp?url=/workshop/author/dhtml/reference/events.asp
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMBeforeUnloadEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMBEFOREUNLOADEVENT_IID)

  /**
   * Attribute used to pass back a return value from a beforeunload
   * handler
   */
  /* attribute DOMString returnValue; */
  NS_SCRIPTABLE NS_IMETHOD GetReturnValue(nsAString & aReturnValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReturnValue(const nsAString & aReturnValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMBeforeUnloadEvent, NS_IDOMBEFOREUNLOADEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMBEFOREUNLOADEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetReturnValue(nsAString & aReturnValue); \
  NS_SCRIPTABLE NS_IMETHOD SetReturnValue(const nsAString & aReturnValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMBEFOREUNLOADEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetReturnValue(nsAString & aReturnValue) { return _to GetReturnValue(aReturnValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetReturnValue(const nsAString & aReturnValue) { return _to SetReturnValue(aReturnValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMBEFOREUNLOADEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetReturnValue(nsAString & aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnValue(aReturnValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetReturnValue(const nsAString & aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReturnValue(aReturnValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMBeforeUnloadEvent : public nsIDOMBeforeUnloadEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMBEFOREUNLOADEVENT

  nsDOMBeforeUnloadEvent();

private:
  ~nsDOMBeforeUnloadEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMBeforeUnloadEvent, nsIDOMBeforeUnloadEvent)

nsDOMBeforeUnloadEvent::nsDOMBeforeUnloadEvent()
{
  /* member initializers and constructor code */
}

nsDOMBeforeUnloadEvent::~nsDOMBeforeUnloadEvent()
{
  /* destructor code */
}

/* attribute DOMString returnValue; */
NS_IMETHODIMP nsDOMBeforeUnloadEvent::GetReturnValue(nsAString & aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMBeforeUnloadEvent::SetReturnValue(const nsAString & aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMBeforeUnloadEvent_h__ */
