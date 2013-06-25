/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMNotifyPaintEvent.idl
 */

#ifndef __gen_nsIDOMNotifyPaintEvent_h__
#define __gen_nsIDOMNotifyPaintEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNotifyPaintEvent */
#define NS_IDOMNOTIFYPAINTEVENT_IID_STR "dec5582e-5cea-412f-bf98-6b27480fb46a"

#define NS_IDOMNOTIFYPAINTEVENT_IID \
  {0xdec5582e, 0x5cea, 0x412f, \
    { 0xbf, 0x98, 0x6b, 0x27, 0x48, 0x0f, 0xb4, 0x6a }}

/**
 * The nsIDOMNotifyPaintEvent interface is used for the MozDOMAfterPaint
 * event, which fires at a window when painting has happened in
 * that window.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNotifyPaintEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNOTIFYPAINTEVENT_IID)

  /**
   * Get a list of rectangles which are affected. The rectangles are in CSS pixels
   * relative to the viewport origin.
   * If the caller is not trusted (e.g., regular Web content) then only painting
   * caused by the current document is reported; in particular, painting in subdocuments
   * is not reported.
   */
  /* readonly attribute nsIDOMClientRectList clientRects; */
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList * *aClientRects) = 0;

  /**
   * Get the bounding box of the rectangles which are affected. The rectangle
   * is in CSS pixels relative to the viewport origin.
   * If the caller is not trusted (e.g., regular Web content) then only painting
   * caused by the current document is reported; in particular, painting in subdocuments
   * is not reported.
   */
  /* readonly attribute nsIDOMClientRect boundingClientRect; */
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNotifyPaintEvent, NS_IDOMNOTIFYPAINTEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNOTIFYPAINTEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList * *aClientRects); \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNOTIFYPAINTEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList * *aClientRects) { return _to GetClientRects(aClientRects); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect) { return _to GetBoundingClientRect(aBoundingClientRect); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNOTIFYPAINTEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList * *aClientRects) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientRects(aClientRects); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundingClientRect(aBoundingClientRect); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNotifyPaintEvent : public nsIDOMNotifyPaintEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNOTIFYPAINTEVENT

  nsDOMNotifyPaintEvent();

private:
  ~nsDOMNotifyPaintEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNotifyPaintEvent, nsIDOMNotifyPaintEvent)

nsDOMNotifyPaintEvent::nsDOMNotifyPaintEvent()
{
  /* member initializers and constructor code */
}

nsDOMNotifyPaintEvent::~nsDOMNotifyPaintEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMClientRectList clientRects; */
NS_IMETHODIMP nsDOMNotifyPaintEvent::GetClientRects(nsIDOMClientRectList * *aClientRects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMClientRect boundingClientRect; */
NS_IMETHODIMP nsDOMNotifyPaintEvent::GetBoundingClientRect(nsIDOMClientRect * *aBoundingClientRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNotifyPaintEvent_h__ */
