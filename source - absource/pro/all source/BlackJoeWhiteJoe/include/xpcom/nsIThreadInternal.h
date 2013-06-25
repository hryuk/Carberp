/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/threads/nsIThreadInternal.idl
 */

#ifndef __gen_nsIThreadInternal_h__
#define __gen_nsIThreadInternal_h__


#ifndef __gen_nsIThread_h__
#include "nsIThread.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIThreadObserver; /* forward declaration */

class nsIThreadEventFilter; /* forward declaration */


/* starting interface:    nsIThreadInternal */
#define NS_ITHREADINTERNAL_IID_STR "f89b5063-b06d-42f8-bf23-4dfcf2d80d6a"

#define NS_ITHREADINTERNAL_IID \
  {0xf89b5063, 0xb06d, 0x42f8, \
    { 0xbf, 0x23, 0x4d, 0xfc, 0xf2, 0xd8, 0x0d, 0x6a }}

/**
 * The XPCOM thread object implements this interface, which allows a consumer
 * to observe dispatch activity on the thread.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIThreadInternal : public nsIThread {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADINTERNAL_IID)

  /**
   * Get/set the current thread observer (may be null).  This attribute may be
   * read from any thread, but must only be set on the thread corresponding to
   * this thread object.
   */
  /* attribute nsIThreadObserver observer; */
  NS_SCRIPTABLE NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetObserver(nsIThreadObserver * aObserver) = 0;

  /**
   * This method causes any events currently enqueued on the thread to be
   * suppressed until PopEventQueue is called.  Additionally, any new events
   * dispatched to the thread will only be processed if they are accepted by
   * the given filter.  If the filter is null, then new events are accepted.
   * Calls to PushEventQueue may be nested and must each be paired with a call
   * to PopEventQueue in order to restore the original state of the thread.
   *
   * @param filter
   *   The thread event filter to apply to dispatched events, or null to accept
   *   all dispatched events.
   */
  /* void pushEventQueue (in nsIThreadEventFilter filter); */
  NS_SCRIPTABLE NS_IMETHOD PushEventQueue(nsIThreadEventFilter *filter) = 0;

  /**
   * Revert a call to PushEventQueue.  When an event queue is popped, any
   * events remaining in the queue are appended to the elder queue.
   */
  /* void popEventQueue (); */
  NS_SCRIPTABLE NS_IMETHOD PopEventQueue(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadInternal, NS_ITHREADINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADINTERNAL \
  NS_SCRIPTABLE NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD SetObserver(nsIThreadObserver * aObserver); \
  NS_SCRIPTABLE NS_IMETHOD PushEventQueue(nsIThreadEventFilter *filter); \
  NS_SCRIPTABLE NS_IMETHOD PopEventQueue(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver) { return _to GetObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD SetObserver(nsIThreadObserver * aObserver) { return _to SetObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD PushEventQueue(nsIThreadEventFilter *filter) { return _to PushEventQueue(filter); } \
  NS_SCRIPTABLE NS_IMETHOD PopEventQueue(void) { return _to PopEventQueue(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD SetObserver(nsIThreadObserver * aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD PushEventQueue(nsIThreadEventFilter *filter) { return !_to ? NS_ERROR_NULL_POINTER : _to->PushEventQueue(filter); } \
  NS_SCRIPTABLE NS_IMETHOD PopEventQueue(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PopEventQueue(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadInternal : public nsIThreadInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADINTERNAL

  nsThreadInternal();

private:
  ~nsThreadInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadInternal, nsIThreadInternal)

nsThreadInternal::nsThreadInternal()
{
  /* member initializers and constructor code */
}

nsThreadInternal::~nsThreadInternal()
{
  /* destructor code */
}

/* attribute nsIThreadObserver observer; */
NS_IMETHODIMP nsThreadInternal::GetObserver(nsIThreadObserver * *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadInternal::SetObserver(nsIThreadObserver * aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pushEventQueue (in nsIThreadEventFilter filter); */
NS_IMETHODIMP nsThreadInternal::PushEventQueue(nsIThreadEventFilter *filter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void popEventQueue (); */
NS_IMETHODIMP nsThreadInternal::PopEventQueue()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIThreadObserver */
#define NS_ITHREADOBSERVER_IID_STR "81d0b509-f198-4417-8020-08eb4271491f"

#define NS_ITHREADOBSERVER_IID \
  {0x81d0b509, 0xf198, 0x4417, \
    { 0x80, 0x20, 0x08, 0xeb, 0x42, 0x71, 0x49, 0x1f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIThreadObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADOBSERVER_IID)

  /**
 * This interface provides the observer with hooks to implement a layered
 * event queue.  For example, it is possible to overlay processing events
 * for a GUI toolkit on top of the events for a thread:
 *
 *   var NativeQueue;
 *   Observer = {
 *     onDispatchedEvent(thread) {
 *       NativeQueue.signal();
 *     }
 *     onProcessNextEvent(thread, mayWait, recursionDepth) {
 *       if (NativeQueue.hasNextEvent())
 *         NativeQueue.processNextEvent();
 *       while (mayWait && !thread.hasPendingEvent()) {
 *         NativeQueue.wait();
 *         NativeQueue.processNextEvent();
 *       }
 *     }
 *   };
 *
 * NOTE: The implementation of this interface must be threadsafe.
 * 
 * NOTE: It is valid to change the thread's observer during a call to an
 *       observer method.
 */
/**
   * This method is called after an event has been dispatched to the thread.
   * This method may be called from any thread. 
   *
   * @param thread
   *   The thread where the event is being dispatched.
   */
  /* void onDispatchedEvent (in nsIThreadInternal thread); */
  NS_SCRIPTABLE NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread) = 0;

  /**
   * This method is called (from nsIThread::ProcessNextEvent) before an event
   * is processed.  This method is only called on the target thread.
   *
   * @param thread
   *   The thread being asked to process another event.
   * @param mayWait
   *   Indicates whether or not the method is allowed to block the calling
   *   thread.  For example, this parameter is false during thread shutdown.
   * @param recursionDepth
   *   Indicates the number of calls to ProcessNextEvent on the call stack in
   *   addition to the current call.
   */
  /* void onProcessNextEvent (in nsIThreadInternal thread, in boolean mayWait, in unsigned long recursionDepth); */
  NS_SCRIPTABLE NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, PRBool mayWait, PRUint32 recursionDepth) = 0;

  /**
   * This method is called (from nsIThread::ProcessNextEvent) after an event
   * is processed.  This method is only called on the target thread.
   *
   * @param thread
   *   The thread that processed another event.
   * @param recursionDepth
   *   Indicates the number of calls to ProcessNextEvent on the call stack in
   *   addition to the current call.
   */
  /* void afterProcessNextEvent (in nsIThreadInternal thread, in unsigned long recursionDepth); */
  NS_SCRIPTABLE NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, PRUint32 recursionDepth) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadObserver, NS_ITHREADOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread); \
  NS_SCRIPTABLE NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, PRBool mayWait, PRUint32 recursionDepth); \
  NS_SCRIPTABLE NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, PRUint32 recursionDepth); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread) { return _to OnDispatchedEvent(thread); } \
  NS_SCRIPTABLE NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, PRBool mayWait, PRUint32 recursionDepth) { return _to OnProcessNextEvent(thread, mayWait, recursionDepth); } \
  NS_SCRIPTABLE NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, PRUint32 recursionDepth) { return _to AfterProcessNextEvent(thread, recursionDepth); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDispatchedEvent(thread); } \
  NS_SCRIPTABLE NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, PRBool mayWait, PRUint32 recursionDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProcessNextEvent(thread, mayWait, recursionDepth); } \
  NS_SCRIPTABLE NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, PRUint32 recursionDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->AfterProcessNextEvent(thread, recursionDepth); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadObserver : public nsIThreadObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADOBSERVER

  nsThreadObserver();

private:
  ~nsThreadObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadObserver, nsIThreadObserver)

nsThreadObserver::nsThreadObserver()
{
  /* member initializers and constructor code */
}

nsThreadObserver::~nsThreadObserver()
{
  /* destructor code */
}

/* void onDispatchedEvent (in nsIThreadInternal thread); */
NS_IMETHODIMP nsThreadObserver::OnDispatchedEvent(nsIThreadInternal *thread)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onProcessNextEvent (in nsIThreadInternal thread, in boolean mayWait, in unsigned long recursionDepth); */
NS_IMETHODIMP nsThreadObserver::OnProcessNextEvent(nsIThreadInternal *thread, PRBool mayWait, PRUint32 recursionDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void afterProcessNextEvent (in nsIThreadInternal thread, in unsigned long recursionDepth); */
NS_IMETHODIMP nsThreadObserver::AfterProcessNextEvent(nsIThreadInternal *thread, PRUint32 recursionDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIThreadEventFilter */
#define NS_ITHREADEVENTFILTER_IID_STR "a0605c0b-17f5-4681-b8cd-a1cd75d42559"

#define NS_ITHREADEVENTFILTER_IID \
  {0xa0605c0b, 0x17f5, 0x4681, \
    { 0xb8, 0xcd, 0xa1, 0xcd, 0x75, 0xd4, 0x25, 0x59 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIThreadEventFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADEVENTFILTER_IID)

  /**
 * Interface passed to the nsIThreadInternal::PushEventQueue method.
 */
/**
   * This method is called to determine whether or not an event may be accepted
   * by a "nested" event queue (see nsIThreadInternal::PushEventQueue).
   *
   * @param event
   *   The event being dispatched.
   *
   * WARNING: This method must not make any calls on the thread object.
   */
  /* [notxpcom] boolean acceptEvent (in nsIRunnable event); */
  NS_IMETHOD_(PRBool) AcceptEvent(nsIRunnable *event) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadEventFilter, NS_ITHREADEVENTFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADEVENTFILTER \
  NS_IMETHOD_(PRBool) AcceptEvent(nsIRunnable *event); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADEVENTFILTER(_to) \
  NS_IMETHOD_(PRBool) AcceptEvent(nsIRunnable *event) { return _to AcceptEvent(event); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADEVENTFILTER(_to) \
  NS_IMETHOD_(PRBool) AcceptEvent(nsIRunnable *event) { return !_to ? NS_ERROR_NULL_POINTER : _to->AcceptEvent(event); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadEventFilter : public nsIThreadEventFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADEVENTFILTER

  nsThreadEventFilter();

private:
  ~nsThreadEventFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadEventFilter, nsIThreadEventFilter)

nsThreadEventFilter::nsThreadEventFilter()
{
  /* member initializers and constructor code */
}

nsThreadEventFilter::~nsThreadEventFilter()
{
  /* destructor code */
}

/* [notxpcom] boolean acceptEvent (in nsIRunnable event); */
NS_IMETHODIMP_(PRBool) nsThreadEventFilter::AcceptEvent(nsIRunnable *event)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIThreadInternal_h__ */
