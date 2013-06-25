/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/threads/nsIEventTarget.idl
 */

#ifndef __gen_nsIEventTarget_h__
#define __gen_nsIEventTarget_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRunnable; /* forward declaration */


/* starting interface:    nsIEventTarget */
#define NS_IEVENTTARGET_IID_STR "4e8febe4-6631-49dc-8ac9-308c1cb9b09c"

#define NS_IEVENTTARGET_IID \
  {0x4e8febe4, 0x6631, 0x49dc, \
    { 0x8a, 0xc9, 0x30, 0x8c, 0x1c, 0xb9, 0xb0, 0x9c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIEventTarget : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEVENTTARGET_IID)

  /**
   * Dispatch an event to this event target.  This function may be called from
   * any thread, and it may be called re-entrantly.
   *
   * @param event
   *   The event to dispatch.
   * @param flags
   *   The flags modifying event dispatch.  The flags are described in detail
   *   below.
   * 
   * @throws NS_ERROR_INVALID_ARG
   *   Indicates that event is null.
   * @throws NS_ERROR_UNEXPECTED
   *   Indicates that the thread is shutting down and has finished processing
   * events, so this event would never run and has not been dispatched. 
   */
  /* void dispatch (in nsIRunnable event, in unsigned long flags); */
  NS_SCRIPTABLE NS_IMETHOD Dispatch(nsIRunnable *event, PRUint32 flags) = 0;

  /**
   * This flag specifies the default mode of event dispatch, whereby the event
   * is simply queued for later processing.  When this flag is specified,
   * dispatch returns immediately after the event is queued.
   */
  enum { DISPATCH_NORMAL = 0U };

  /**
   * This flag specifies the synchronous mode of event dispatch, in which the
   * dispatch method does not return until the event has been processed.
   *
   * NOTE: passing this flag to dispatch may have the side-effect of causing
   * other events on the current thread to be processed while waiting for the
   * given event to be processed.
   */
  enum { DISPATCH_SYNC = 1U };

  /**
   * Check to see if this event target is associated with the current thread.
   *
   * @returns
   *   A boolean value that if "true" indicates that events dispatched to this
   *   event target will run on the current thread (i.e., the thread calling
   *   this method).
   */
  /* boolean isOnCurrentThread (); */
  NS_SCRIPTABLE NS_IMETHOD IsOnCurrentThread(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEventTarget, NS_IEVENTTARGET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEVENTTARGET \
  NS_SCRIPTABLE NS_IMETHOD Dispatch(nsIRunnable *event, PRUint32 flags); \
  NS_SCRIPTABLE NS_IMETHOD IsOnCurrentThread(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEVENTTARGET(_to) \
  NS_SCRIPTABLE NS_IMETHOD Dispatch(nsIRunnable *event, PRUint32 flags) { return _to Dispatch(event, flags); } \
  NS_SCRIPTABLE NS_IMETHOD IsOnCurrentThread(PRBool *_retval NS_OUTPARAM) { return _to IsOnCurrentThread(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEVENTTARGET(_to) \
  NS_SCRIPTABLE NS_IMETHOD Dispatch(nsIRunnable *event, PRUint32 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Dispatch(event, flags); } \
  NS_SCRIPTABLE NS_IMETHOD IsOnCurrentThread(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsOnCurrentThread(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEventTarget : public nsIEventTarget
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEVENTTARGET

  nsEventTarget();

private:
  ~nsEventTarget();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEventTarget, nsIEventTarget)

nsEventTarget::nsEventTarget()
{
  /* member initializers and constructor code */
}

nsEventTarget::~nsEventTarget()
{
  /* destructor code */
}

/* void dispatch (in nsIRunnable event, in unsigned long flags); */
NS_IMETHODIMP nsEventTarget::Dispatch(nsIRunnable *event, PRUint32 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isOnCurrentThread (); */
NS_IMETHODIMP nsEventTarget::IsOnCurrentThread(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// convenient aliases:
#define NS_DISPATCH_NORMAL nsIEventTarget::DISPATCH_NORMAL
#define NS_DISPATCH_SYNC   nsIEventTarget::DISPATCH_SYNC

#endif /* __gen_nsIEventTarget_h__ */
