/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMDragEvent.idl
 */

#ifndef __gen_nsIDOMDragEvent_h__
#define __gen_nsIDOMDragEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMMouseEvent_h__
#include "nsIDOMMouseEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMAbstractView; /* forward declaration */

class nsIDOMDataTransfer; /* forward declaration */


/* starting interface:    nsIDOMDragEvent */
#define NS_IDOMDRAGEVENT_IID_STR "18feefd7-a461-4865-bcf1-4dc8a2f30584"

#define NS_IDOMDRAGEVENT_IID \
  {0x18feefd7, 0xa461, 0x4865, \
    { 0xbc, 0xf1, 0x4d, 0xc8, 0xa2, 0xf3, 0x05, 0x84 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDragEvent : public nsIDOMMouseEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDRAGEVENT_IID)

  /* readonly attribute nsIDOMDataTransfer dataTransfer; */
  NS_SCRIPTABLE NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) = 0;

  /* void initDragEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView aView, in PRInt32 aDetail, in nsIDOMDataTransfer aDataTransfer); */
  NS_SCRIPTABLE NS_IMETHOD InitDragEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer) = 0;

  /* void initDragEventNS (in DOMString namespaceURIArg, in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView aView, in PRInt32 aDetail, in nsIDOMDataTransfer aDataTransfer); */
  NS_SCRIPTABLE NS_IMETHOD InitDragEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDragEvent, NS_IDOMDRAGEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDRAGEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer); \
  NS_SCRIPTABLE NS_IMETHOD InitDragEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer); \
  NS_SCRIPTABLE NS_IMETHOD InitDragEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDRAGEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) { return _to GetDataTransfer(aDataTransfer); } \
  NS_SCRIPTABLE NS_IMETHOD InitDragEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer) { return _to InitDragEvent(typeArg, canBubbleArg, cancelableArg, aView, aDetail, aDataTransfer); } \
  NS_SCRIPTABLE NS_IMETHOD InitDragEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer) { return _to InitDragEventNS(namespaceURIArg, typeArg, canBubbleArg, cancelableArg, aView, aDetail, aDataTransfer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDRAGEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataTransfer(aDataTransfer); } \
  NS_SCRIPTABLE NS_IMETHOD InitDragEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDragEvent(typeArg, canBubbleArg, cancelableArg, aView, aDetail, aDataTransfer); } \
  NS_SCRIPTABLE NS_IMETHOD InitDragEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDragEventNS(namespaceURIArg, typeArg, canBubbleArg, cancelableArg, aView, aDetail, aDataTransfer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDragEvent : public nsIDOMDragEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDRAGEVENT

  nsDOMDragEvent();

private:
  ~nsDOMDragEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDragEvent, nsIDOMDragEvent)

nsDOMDragEvent::nsDOMDragEvent()
{
  /* member initializers and constructor code */
}

nsDOMDragEvent::~nsDOMDragEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDataTransfer dataTransfer; */
NS_IMETHODIMP nsDOMDragEvent::GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initDragEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView aView, in PRInt32 aDetail, in nsIDOMDataTransfer aDataTransfer); */
NS_IMETHODIMP nsDOMDragEvent::InitDragEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initDragEventNS (in DOMString namespaceURIArg, in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView aView, in PRInt32 aDetail, in nsIDOMDataTransfer aDataTransfer); */
NS_IMETHODIMP nsDOMDragEvent::InitDragEventNS(const nsAString & namespaceURIArg, const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *aView, PRInt32 aDetail, nsIDOMDataTransfer *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDragEvent_h__ */
