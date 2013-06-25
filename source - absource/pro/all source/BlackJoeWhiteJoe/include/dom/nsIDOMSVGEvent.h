/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGEvent.idl
 */

#ifndef __gen_nsIDOMSVGEvent_h__
#define __gen_nsIDOMSVGEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGEvent */
#define NS_IDOMSVGEVENT_IID_STR "13aed1cc-a505-45d5-bbc2-0052c6bf200f"

#define NS_IDOMSVGEVENT_IID \
  {0x13aed1cc, 0xa505, 0x45d5, \
    { 0xbb, 0xc2, 0x00, 0x52, 0xc6, 0xbf, 0x20, 0x0f }}

/**
 * For more information on this interface please see
 * http://www.w3.org/TR/SVG11/script.html#InterfaceSVGEvent
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGEVENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGEvent, NS_IDOMSVGEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGEVENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGEVENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGEVENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGEvent : public nsIDOMSVGEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGEVENT

  nsDOMSVGEvent();

private:
  ~nsDOMSVGEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGEvent, nsIDOMSVGEvent)

nsDOMSVGEvent::nsDOMSVGEvent()
{
  /* member initializers and constructor code */
}

nsDOMSVGEvent::~nsDOMSVGEvent()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGEvent_h__ */
