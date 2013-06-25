/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMProgressEvent.idl
 */

#ifndef __gen_nsIDOMProgressEvent_h__
#define __gen_nsIDOMProgressEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMProgressEvent */
#define NS_IDOMPROGRESSEVENT_IID_STR "6af7022c-d7f8-414c-a11f-a7918f14052b"

#define NS_IDOMPROGRESSEVENT_IID \
  {0x6af7022c, 0xd7f8, 0x414c, \
    { 0xa1, 0x1f, 0xa7, 0x91, 0x8f, 0x14, 0x05, 0x2b }}

/**
 * The nsIDOMProgressEvent is used in the media elements (<video> and <audio>
 * to inform of the progress of the media download. It is currently undefined
 * in the HTML5 specification. This implementation is a placeholder until
 * the specification is complete and is compatible with the WebKit ProgressEvent.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMProgressEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPROGRESSEVENT_IID)

  /* readonly attribute boolean lengthComputable; */
  NS_SCRIPTABLE NS_IMETHOD GetLengthComputable(PRBool *aLengthComputable) = 0;

  /* readonly attribute unsigned long long loaded; */
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRUint64 *aLoaded) = 0;

  /* readonly attribute unsigned long long total; */
  NS_SCRIPTABLE NS_IMETHOD GetTotal(PRUint64 *aTotal) = 0;

  /* void initProgressEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in boolean lengthComputableArg, in unsigned long long loadedArg, in unsigned long long totalArg); */
  NS_SCRIPTABLE NS_IMETHOD InitProgressEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, PRBool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMProgressEvent, NS_IDOMPROGRESSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPROGRESSEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetLengthComputable(PRBool *aLengthComputable); \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRUint64 *aLoaded); \
  NS_SCRIPTABLE NS_IMETHOD GetTotal(PRUint64 *aTotal); \
  NS_SCRIPTABLE NS_IMETHOD InitProgressEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, PRBool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPROGRESSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLengthComputable(PRBool *aLengthComputable) { return _to GetLengthComputable(aLengthComputable); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRUint64 *aLoaded) { return _to GetLoaded(aLoaded); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotal(PRUint64 *aTotal) { return _to GetTotal(aTotal); } \
  NS_SCRIPTABLE NS_IMETHOD InitProgressEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, PRBool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg) { return _to InitProgressEvent(typeArg, canBubbleArg, cancelableArg, lengthComputableArg, loadedArg, totalArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPROGRESSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLengthComputable(PRBool *aLengthComputable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLengthComputable(aLengthComputable); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRUint64 *aLoaded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoaded(aLoaded); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotal(PRUint64 *aTotal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotal(aTotal); } \
  NS_SCRIPTABLE NS_IMETHOD InitProgressEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, PRBool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitProgressEvent(typeArg, canBubbleArg, cancelableArg, lengthComputableArg, loadedArg, totalArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMProgressEvent : public nsIDOMProgressEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPROGRESSEVENT

  nsDOMProgressEvent();

private:
  ~nsDOMProgressEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMProgressEvent, nsIDOMProgressEvent)

nsDOMProgressEvent::nsDOMProgressEvent()
{
  /* member initializers and constructor code */
}

nsDOMProgressEvent::~nsDOMProgressEvent()
{
  /* destructor code */
}

/* readonly attribute boolean lengthComputable; */
NS_IMETHODIMP nsDOMProgressEvent::GetLengthComputable(PRBool *aLengthComputable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long loaded; */
NS_IMETHODIMP nsDOMProgressEvent::GetLoaded(PRUint64 *aLoaded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long total; */
NS_IMETHODIMP nsDOMProgressEvent::GetTotal(PRUint64 *aTotal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initProgressEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in boolean lengthComputableArg, in unsigned long long loadedArg, in unsigned long long totalArg); */
NS_IMETHODIMP nsDOMProgressEvent::InitProgressEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, PRBool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMProgressEvent_h__ */
