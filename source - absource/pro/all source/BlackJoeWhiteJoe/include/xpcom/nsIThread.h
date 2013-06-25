/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/threads/nsIThread.idl
 */

#ifndef __gen_nsIThread_h__
#define __gen_nsIThread_h__


#ifndef __gen_nsIEventTarget_h__
#include "nsIEventTarget.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIThread */
#define NS_ITHREAD_IID_STR "9c889946-a73a-4af3-ae9a-ea64f7d4e3ca"

#define NS_ITHREAD_IID \
  {0x9c889946, 0xa73a, 0x4af3, \
    { 0xae, 0x9a, 0xea, 0x64, 0xf7, 0xd4, 0xe3, 0xca }}

/**
 * This interface provides a high-level abstraction for an operating system
 * thread.
 *
 * Threads have a built-in event queue, and a thread is an event target that
 * can receive nsIRunnable objects (events) to be processed on the thread.
 *
 * See nsIThreadManager for the API used to create and locate threads.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIThread : public nsIEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREAD_IID)

  /**
   * @returns
   *   The NSPR thread object corresponding to this nsIThread.
   */
  /* [noscript] readonly attribute PRThread PRThread; */
  NS_IMETHOD GetPRThread(PRThread * *aPRThread) = 0;

  /**
   * Shutdown the thread.  This method prevents further dispatch of events to
   * the thread, and it causes any pending events to run to completion before
   * the thread joins (see PR_JoinThread) with the current thread.  During this
   * method call, events for the current thread may be processed.
   *
   * This method MAY NOT be executed from the thread itself.  Instead, it is
   * meant to be executed from another thread (usually the thread that created
   * this thread or the main application thread).  When this function returns,
   * the thread will be shutdown, and it will no longer be possible to dispatch
   * events to the thread.
   *
   * @throws NS_ERROR_UNEXPECTED
   *   Indicates that this method was erroneously called when this thread was
   *   the current thread, that this thread was not created with a call to
   *   nsIThreadManager::NewThread, or if this method was called more than once
   *   on the thread object.
   */
  /* void shutdown (); */
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) = 0;

  /**
   * This method may be called to determine if there are any events ready to be
   * processed.  It may only be called when this thread is the current thread.
   *
   * Because events may be added to this thread by another thread, a "false"
   * result does not mean that this thread has no pending events.  It only
   * means that there were no pending events when this method was called.
   *
   * @returns
   *   A boolean value that if "true" indicates that this thread has one or
   *   more pending events.
   *
   * @throws NS_ERROR_UNEXPECTED
   *   Indicates that this method was erroneously called when this thread was
   *   not the current thread.
   */
  /* boolean hasPendingEvents (); */
  NS_SCRIPTABLE NS_IMETHOD HasPendingEvents(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Process the next event.  If there are no pending events, then this method
   * may wait -- depending on the value of the mayWait parameter -- until an
   * event is dispatched to this thread.  This method is re-entrant but may
   * only be called if this thread is the current thread.
   *
   * @param mayWait
   *   A boolean parameter that if "true" indicates that the method may block
   *   the calling thread to wait for a pending event.
   *
   * @returns
   *   A boolean value that if "true" indicates that an event was processed.
   *
   * @throws NS_ERROR_UNEXPECTED
   *   Indicates that this method was erroneously called when this thread was
   *   not the current thread.
   */
  /* boolean processNextEvent (in boolean mayWait); */
  NS_SCRIPTABLE NS_IMETHOD ProcessNextEvent(PRBool mayWait, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThread, NS_ITHREAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREAD \
  NS_IMETHOD GetPRThread(PRThread * *aPRThread); \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void); \
  NS_SCRIPTABLE NS_IMETHOD HasPendingEvents(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ProcessNextEvent(PRBool mayWait, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREAD(_to) \
  NS_IMETHOD GetPRThread(PRThread * *aPRThread) { return _to GetPRThread(aPRThread); } \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_SCRIPTABLE NS_IMETHOD HasPendingEvents(PRBool *_retval NS_OUTPARAM) { return _to HasPendingEvents(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessNextEvent(PRBool mayWait, PRBool *_retval NS_OUTPARAM) { return _to ProcessNextEvent(mayWait, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREAD(_to) \
  NS_IMETHOD GetPRThread(PRThread * *aPRThread) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPRThread(aPRThread); } \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_SCRIPTABLE NS_IMETHOD HasPendingEvents(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPendingEvents(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessNextEvent(PRBool mayWait, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessNextEvent(mayWait, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThread : public nsIThread
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREAD

  nsThread();

private:
  ~nsThread();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThread, nsIThread)

nsThread::nsThread()
{
  /* member initializers and constructor code */
}

nsThread::~nsThread()
{
  /* destructor code */
}

/* [noscript] readonly attribute PRThread PRThread; */
NS_IMETHODIMP nsThread::GetPRThread(PRThread * *aPRThread)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP nsThread::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasPendingEvents (); */
NS_IMETHODIMP nsThread::HasPendingEvents(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean processNextEvent (in boolean mayWait); */
NS_IMETHODIMP nsThread::ProcessNextEvent(PRBool mayWait, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIThread_h__ */
