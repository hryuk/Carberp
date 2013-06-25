/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIAppShell.idl
 */

#ifndef __gen_nsIAppShell_h__
#define __gen_nsIAppShell_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAppShell */
#define NS_IAPPSHELL_IID_STR "501403e9-a091-4780-ba55-cfd1e21287a1"

#define NS_IAPPSHELL_IID \
  {0x501403e9, 0xa091, 0x4780, \
    { 0xba, 0x55, 0xcf, 0xd1, 0xe2, 0x12, 0x87, 0xa1 }}

/**
 * Interface for the native event system layer.  This interface is designed
 * to be used on the main application thread only.
 */
class NS_NO_VTABLE nsIAppShell : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSHELL_IID)

  /**
   * Enter an event loop.  Don't leave until exit() is called.
   */
  /* void run (); */
  NS_IMETHOD Run(void) = 0;

  /**
   * Exit the handle event loop
   */
  /* void exit (); */
  NS_IMETHOD Exit(void) = 0;

  /**
   * Give hint to native event queue notification mechanism. If the native
   * platform needs to tradeoff performance vs. native event starvation this
   * hint tells the native dispatch code which to favor.  The default is to
   * prevent native event starvation.
   *
   * Calls to this function may be nested. When the number of calls that pass
   * PR_TRUE is subtracted from the number of calls that pass PR_FALSE is
   * greater than 0, performance is given precedence over preventing event
   * starvation.
   *
   * The starvationDelay arg is only used when favorPerfOverStarvation is
   * PR_FALSE. It is the amount of time in milliseconds to wait before the
   * PR_FALSE actually takes effect.
   */
  /* void favorPerformanceHint (in boolean favorPerfOverStarvation, in unsigned long starvationDelay); */
  NS_IMETHOD FavorPerformanceHint(PRBool favorPerfOverStarvation, PRUint32 starvationDelay) = 0;

  /**
   * Suspends the use of additional platform-specific methods (besides the
   * nsIAppShell->run() event loop) to run Gecko events on the main
   * application thread.  Under some circumstances these "additional methods"
   * can cause Gecko event handlers to be re-entered, sometimes leading to
   * hangs and crashes.  Calls to suspendNative() and resumeNative() may be
   * nested.  On some platforms (those that don't use any "additional
   * methods") this will be a no-op.  Does not (in itself) stop Gecko events
   * from being processed on the main application thread.  But if the
   * nsIAppShell->run() event loop is blocked when this call is made, Gecko
   * events will stop being processed until resumeNative() is called (even
   * if a plugin or library is temporarily processing events on a nested
   * event loop).
   */
  /* void suspendNative (); */
  NS_IMETHOD SuspendNative(void) = 0;

  /**
   * Resumes the use of additional platform-specific methods to run Gecko
   * events on the main application thread.  Calls to suspendNative() and
   * resumeNative() may be nested.  On some platforms this will be a no-op.
   */
  /* void resumeNative (); */
  NS_IMETHOD ResumeNative(void) = 0;

  /**
   * The current event loop nesting level.
   */
  /* readonly attribute unsigned long eventloopNestingLevel; */
  NS_IMETHOD GetEventloopNestingLevel(PRUint32 *aEventloopNestingLevel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppShell, NS_IAPPSHELL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSHELL \
  NS_IMETHOD Run(void); \
  NS_IMETHOD Exit(void); \
  NS_IMETHOD FavorPerformanceHint(PRBool favorPerfOverStarvation, PRUint32 starvationDelay); \
  NS_IMETHOD SuspendNative(void); \
  NS_IMETHOD ResumeNative(void); \
  NS_IMETHOD GetEventloopNestingLevel(PRUint32 *aEventloopNestingLevel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSHELL(_to) \
  NS_IMETHOD Run(void) { return _to Run(); } \
  NS_IMETHOD Exit(void) { return _to Exit(); } \
  NS_IMETHOD FavorPerformanceHint(PRBool favorPerfOverStarvation, PRUint32 starvationDelay) { return _to FavorPerformanceHint(favorPerfOverStarvation, starvationDelay); } \
  NS_IMETHOD SuspendNative(void) { return _to SuspendNative(); } \
  NS_IMETHOD ResumeNative(void) { return _to ResumeNative(); } \
  NS_IMETHOD GetEventloopNestingLevel(PRUint32 *aEventloopNestingLevel) { return _to GetEventloopNestingLevel(aEventloopNestingLevel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSHELL(_to) \
  NS_IMETHOD Run(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Run(); } \
  NS_IMETHOD Exit(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Exit(); } \
  NS_IMETHOD FavorPerformanceHint(PRBool favorPerfOverStarvation, PRUint32 starvationDelay) { return !_to ? NS_ERROR_NULL_POINTER : _to->FavorPerformanceHint(favorPerfOverStarvation, starvationDelay); } \
  NS_IMETHOD SuspendNative(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SuspendNative(); } \
  NS_IMETHOD ResumeNative(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeNative(); } \
  NS_IMETHOD GetEventloopNestingLevel(PRUint32 *aEventloopNestingLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventloopNestingLevel(aEventloopNestingLevel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppShell : public nsIAppShell
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSHELL

  nsAppShell();

private:
  ~nsAppShell();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppShell, nsIAppShell)

nsAppShell::nsAppShell()
{
  /* member initializers and constructor code */
}

nsAppShell::~nsAppShell()
{
  /* destructor code */
}

/* void run (); */
NS_IMETHODIMP nsAppShell::Run()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exit (); */
NS_IMETHODIMP nsAppShell::Exit()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void favorPerformanceHint (in boolean favorPerfOverStarvation, in unsigned long starvationDelay); */
NS_IMETHODIMP nsAppShell::FavorPerformanceHint(PRBool favorPerfOverStarvation, PRUint32 starvationDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspendNative (); */
NS_IMETHODIMP nsAppShell::SuspendNative()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeNative (); */
NS_IMETHODIMP nsAppShell::ResumeNative()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long eventloopNestingLevel; */
NS_IMETHODIMP nsAppShell::GetEventloopNestingLevel(PRUint32 *aEventloopNestingLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppShell_h__ */
