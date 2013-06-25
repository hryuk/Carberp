/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/threads/nsIThreadPool.idl
 */

#ifndef __gen_nsIThreadPool_h__
#define __gen_nsIThreadPool_h__


#ifndef __gen_nsIEventTarget_h__
#include "nsIEventTarget.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIThreadPoolListener */
#define NS_ITHREADPOOLLISTENER_IID_STR "ef194cab-3f86-4b61-b132-e5e96a79e5d1"

#define NS_ITHREADPOOLLISTENER_IID \
  {0xef194cab, 0x3f86, 0x4b61, \
    { 0xb1, 0x32, 0xe5, 0xe9, 0x6a, 0x79, 0xe5, 0xd1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIThreadPoolListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADPOOLLISTENER_IID)

  /**
   * Called when a new thread is created by the thread pool. The notification
   * happens on the newly-created thread.
   */
  /* void onThreadCreated (); */
  NS_SCRIPTABLE NS_IMETHOD OnThreadCreated(void) = 0;

  /**
   * Called when a thread is about to be destroyed by the thread pool. The
   * notification happens on the thread that is about to be destroyed.
   */
  /* void onThreadShuttingDown (); */
  NS_SCRIPTABLE NS_IMETHOD OnThreadShuttingDown(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadPoolListener, NS_ITHREADPOOLLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADPOOLLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnThreadCreated(void); \
  NS_SCRIPTABLE NS_IMETHOD OnThreadShuttingDown(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADPOOLLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnThreadCreated(void) { return _to OnThreadCreated(); } \
  NS_SCRIPTABLE NS_IMETHOD OnThreadShuttingDown(void) { return _to OnThreadShuttingDown(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADPOOLLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnThreadCreated(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnThreadCreated(); } \
  NS_SCRIPTABLE NS_IMETHOD OnThreadShuttingDown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnThreadShuttingDown(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadPoolListener : public nsIThreadPoolListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADPOOLLISTENER

  nsThreadPoolListener();

private:
  ~nsThreadPoolListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadPoolListener, nsIThreadPoolListener)

nsThreadPoolListener::nsThreadPoolListener()
{
  /* member initializers and constructor code */
}

nsThreadPoolListener::~nsThreadPoolListener()
{
  /* destructor code */
}

/* void onThreadCreated (); */
NS_IMETHODIMP nsThreadPoolListener::OnThreadCreated()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onThreadShuttingDown (); */
NS_IMETHODIMP nsThreadPoolListener::OnThreadShuttingDown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIThreadPool */
#define NS_ITHREADPOOL_IID_STR "d628159b-1a03-4985-aa77-43122eb23bfc"

#define NS_ITHREADPOOL_IID \
  {0xd628159b, 0x1a03, 0x4985, \
    { 0xaa, 0x77, 0x43, 0x12, 0x2e, 0xb2, 0x3b, 0xfc }}

/**
 * An interface to a thread pool.  A thread pool creates a limited number of
 * anonymous (unnamed) worker threads.  An event dispatched to the thread pool
 * will be run on the next available worker thread.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIThreadPool : public nsIEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADPOOL_IID)

  /**
   * Shutdown the thread pool.  This method may not be executed from any thread
   * in the thread pool.  Instead, it is meant to be executed from another
   * thread (usually the thread that created this thread pool).  When this
   * function returns, the thread pool and all of its threads will be shutdown,
   * and it will no longer be possible to dispatch tasks to the thread pool.
   */
  /* void shutdown (); */
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) = 0;

  /**
   * Get/set the maximum number of threads allowed at one time in this pool.
   */
  /* attribute unsigned long threadLimit; */
  NS_SCRIPTABLE NS_IMETHOD GetThreadLimit(PRUint32 *aThreadLimit) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetThreadLimit(PRUint32 aThreadLimit) = 0;

  /**
   * Get/set the maximum number of idle threads kept alive.
   */
  /* attribute unsigned long idleThreadLimit; */
  NS_SCRIPTABLE NS_IMETHOD GetIdleThreadLimit(PRUint32 *aIdleThreadLimit) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIdleThreadLimit(PRUint32 aIdleThreadLimit) = 0;

  /**
   * Get/set the amount of time in milliseconds before an idle thread is
   * destroyed.
   */
  /* attribute unsigned long idleThreadTimeout; */
  NS_SCRIPTABLE NS_IMETHOD GetIdleThreadTimeout(PRUint32 *aIdleThreadTimeout) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIdleThreadTimeout(PRUint32 aIdleThreadTimeout) = 0;

  /**
   * An optional listener that will be notified when a thread is created or
   * destroyed in the course of the thread pool's operation.
   *
   * A listener will only receive notifications about threads created after the
   * listener is set so it is recommended that the consumer set the listener
   * before dispatching the first event. A listener that receives an
   * onThreadCreated() notification is guaranteed to always receive the
   * corresponding onThreadShuttingDown() notification.
   *
   * The thread pool takes ownership of the listener and releases it when the
   * shutdown() method is called. Threads created after the listener is set will
   * also take ownership of the listener so that the listener will be kept alive
   * long enough to receive the guaranteed onThreadShuttingDown() notification.
   */
  /* attribute nsIThreadPoolListener listener; */
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIThreadPoolListener * *aListener) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIThreadPoolListener * aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadPool, NS_ITHREADPOOL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADPOOL \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void); \
  NS_SCRIPTABLE NS_IMETHOD GetThreadLimit(PRUint32 *aThreadLimit); \
  NS_SCRIPTABLE NS_IMETHOD SetThreadLimit(PRUint32 aThreadLimit); \
  NS_SCRIPTABLE NS_IMETHOD GetIdleThreadLimit(PRUint32 *aIdleThreadLimit); \
  NS_SCRIPTABLE NS_IMETHOD SetIdleThreadLimit(PRUint32 aIdleThreadLimit); \
  NS_SCRIPTABLE NS_IMETHOD GetIdleThreadTimeout(PRUint32 *aIdleThreadTimeout); \
  NS_SCRIPTABLE NS_IMETHOD SetIdleThreadTimeout(PRUint32 aIdleThreadTimeout); \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIThreadPoolListener * *aListener); \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIThreadPoolListener * aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADPOOL(_to) \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_SCRIPTABLE NS_IMETHOD GetThreadLimit(PRUint32 *aThreadLimit) { return _to GetThreadLimit(aThreadLimit); } \
  NS_SCRIPTABLE NS_IMETHOD SetThreadLimit(PRUint32 aThreadLimit) { return _to SetThreadLimit(aThreadLimit); } \
  NS_SCRIPTABLE NS_IMETHOD GetIdleThreadLimit(PRUint32 *aIdleThreadLimit) { return _to GetIdleThreadLimit(aIdleThreadLimit); } \
  NS_SCRIPTABLE NS_IMETHOD SetIdleThreadLimit(PRUint32 aIdleThreadLimit) { return _to SetIdleThreadLimit(aIdleThreadLimit); } \
  NS_SCRIPTABLE NS_IMETHOD GetIdleThreadTimeout(PRUint32 *aIdleThreadTimeout) { return _to GetIdleThreadTimeout(aIdleThreadTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD SetIdleThreadTimeout(PRUint32 aIdleThreadTimeout) { return _to SetIdleThreadTimeout(aIdleThreadTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIThreadPoolListener * *aListener) { return _to GetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIThreadPoolListener * aListener) { return _to SetListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADPOOL(_to) \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_SCRIPTABLE NS_IMETHOD GetThreadLimit(PRUint32 *aThreadLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreadLimit(aThreadLimit); } \
  NS_SCRIPTABLE NS_IMETHOD SetThreadLimit(PRUint32 aThreadLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetThreadLimit(aThreadLimit); } \
  NS_SCRIPTABLE NS_IMETHOD GetIdleThreadLimit(PRUint32 *aIdleThreadLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdleThreadLimit(aIdleThreadLimit); } \
  NS_SCRIPTABLE NS_IMETHOD SetIdleThreadLimit(PRUint32 aIdleThreadLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIdleThreadLimit(aIdleThreadLimit); } \
  NS_SCRIPTABLE NS_IMETHOD GetIdleThreadTimeout(PRUint32 *aIdleThreadTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdleThreadTimeout(aIdleThreadTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD SetIdleThreadTimeout(PRUint32 aIdleThreadTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIdleThreadTimeout(aIdleThreadTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIThreadPoolListener * *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIThreadPoolListener * aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadPool : public nsIThreadPool
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADPOOL

  nsThreadPool();

private:
  ~nsThreadPool();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadPool, nsIThreadPool)

nsThreadPool::nsThreadPool()
{
  /* member initializers and constructor code */
}

nsThreadPool::~nsThreadPool()
{
  /* destructor code */
}

/* void shutdown (); */
NS_IMETHODIMP nsThreadPool::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long threadLimit; */
NS_IMETHODIMP nsThreadPool::GetThreadLimit(PRUint32 *aThreadLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadPool::SetThreadLimit(PRUint32 aThreadLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long idleThreadLimit; */
NS_IMETHODIMP nsThreadPool::GetIdleThreadLimit(PRUint32 *aIdleThreadLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadPool::SetIdleThreadLimit(PRUint32 aIdleThreadLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long idleThreadTimeout; */
NS_IMETHODIMP nsThreadPool::GetIdleThreadTimeout(PRUint32 *aIdleThreadTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadPool::SetIdleThreadTimeout(PRUint32 aIdleThreadTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIThreadPoolListener listener; */
NS_IMETHODIMP nsThreadPool::GetListener(nsIThreadPoolListener * *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadPool::SetListener(nsIThreadPoolListener * aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIThreadPool_h__ */
