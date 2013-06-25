/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/offline/nsIDOMLoadStatusEvent.idl
 */

#ifndef __gen_nsIDOMLoadStatusEvent_h__
#define __gen_nsIDOMLoadStatusEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMLoadStatus; /* forward declaration */


/* starting interface:    nsIDOMLoadStatusEvent */
#define NS_IDOMLOADSTATUSEVENT_IID_STR "f14431b1-efb6-436c-a272-312f087b1459"

#define NS_IDOMLOADSTATUSEVENT_IID \
  {0xf14431b1, 0xefb6, 0x436c, \
    { 0xa2, 0x72, 0x31, 0x2f, 0x08, 0x7b, 0x14, 0x59 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLoadStatusEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLOADSTATUSEVENT_IID)

  /* readonly attribute nsIDOMLoadStatus status; */
  NS_SCRIPTABLE NS_IMETHOD GetStatus(nsIDOMLoadStatus * *aStatus) = 0;

  /* void initLoadStatusEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancellableArg, in nsIDOMLoadStatus statusArg); */
  NS_SCRIPTABLE NS_IMETHOD InitLoadStatusEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg) = 0;

  /* void initLoadStatusEventNS (in DOMString namespaceURIArg, in DOMString typeArg, in boolean canBubbleArg, in boolean cancellableArg, in nsIDOMLoadStatus statusArg); */
  NS_SCRIPTABLE NS_IMETHOD InitLoadStatusEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLoadStatusEvent, NS_IDOMLOADSTATUSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLOADSTATUSEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(nsIDOMLoadStatus * *aStatus); \
  NS_SCRIPTABLE NS_IMETHOD InitLoadStatusEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg); \
  NS_SCRIPTABLE NS_IMETHOD InitLoadStatusEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLOADSTATUSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(nsIDOMLoadStatus * *aStatus) { return _to GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD InitLoadStatusEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg) { return _to InitLoadStatusEvent(typeArg, canBubbleArg, cancellableArg, statusArg); } \
  NS_SCRIPTABLE NS_IMETHOD InitLoadStatusEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg) { return _to InitLoadStatusEventNS(namespaceURIArg, typeArg, canBubbleArg, cancellableArg, statusArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLOADSTATUSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(nsIDOMLoadStatus * *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD InitLoadStatusEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitLoadStatusEvent(typeArg, canBubbleArg, cancellableArg, statusArg); } \
  NS_SCRIPTABLE NS_IMETHOD InitLoadStatusEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitLoadStatusEventNS(namespaceURIArg, typeArg, canBubbleArg, cancellableArg, statusArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLoadStatusEvent : public nsIDOMLoadStatusEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLOADSTATUSEVENT

  nsDOMLoadStatusEvent();

private:
  ~nsDOMLoadStatusEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLoadStatusEvent, nsIDOMLoadStatusEvent)

nsDOMLoadStatusEvent::nsDOMLoadStatusEvent()
{
  /* member initializers and constructor code */
}

nsDOMLoadStatusEvent::~nsDOMLoadStatusEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMLoadStatus status; */
NS_IMETHODIMP nsDOMLoadStatusEvent::GetStatus(nsIDOMLoadStatus * *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initLoadStatusEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancellableArg, in nsIDOMLoadStatus statusArg); */
NS_IMETHODIMP nsDOMLoadStatusEvent::InitLoadStatusEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initLoadStatusEventNS (in DOMString namespaceURIArg, in DOMString typeArg, in boolean canBubbleArg, in boolean cancellableArg, in nsIDOMLoadStatus statusArg); */
NS_IMETHODIMP nsDOMLoadStatusEvent::InitLoadStatusEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancellableArg, nsIDOMLoadStatus *statusArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLoadStatusEvent_h__ */
