/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/startup/public/nsIAppStartup.idl
 */

#ifndef __gen_nsIAppStartup_h__
#define __gen_nsIAppStartup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICmdLineService; /* forward declaration */


/* starting interface:    nsIAppStartup */
#define NS_IAPPSTARTUP_IID_STR "6799abed-4721-4f51-9304-d1a2ea1df5d5"

#define NS_IAPPSTARTUP_IID \
  {0x6799abed, 0x4721, 0x4f51, \
    { 0x93, 0x04, 0xd1, 0xa2, 0xea, 0x1d, 0xf5, 0xd5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAppStartup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSTARTUP_IID)

  /**
     * Create the hidden window.
     */
  /* void createHiddenWindow (); */
  NS_SCRIPTABLE NS_IMETHOD CreateHiddenWindow(void) = 0;

  /**
     * Destroys the hidden window. This will have no effect if the hidden window
     * has not yet been created.
     */
  /* void destroyHiddenWindow (); */
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void) = 0;

  /**
     * Runs an application event loop: normally the main event pump which
     * defines the lifetime of the application. If there are no windows open
     * and no outstanding calls to enterLastWindowClosingSurvivalArea this
     * method will exit immediately.
     *
     * @returnCode NS_SUCCESS_RESTART_APP
     *             This return code indicates that the application should be
     *             restarted because quit was called with the eRestart flag.
     */
  /* void run (); */
  NS_SCRIPTABLE NS_IMETHOD Run(void) = 0;

  /**
     * There are situations where all application windows will be
     * closed but we don't want to take this as a signal to quit the
     * app. Bracket the code where the last window could close with
     * these.
     */
  /* void enterLastWindowClosingSurvivalArea (); */
  NS_SCRIPTABLE NS_IMETHOD EnterLastWindowClosingSurvivalArea(void) = 0;

  /* void exitLastWindowClosingSurvivalArea (); */
  NS_SCRIPTABLE NS_IMETHOD ExitLastWindowClosingSurvivalArea(void) = 0;

  /**
     * The following flags may be passed as the aMode parameter to the quit
     * method.  One and only one of the "Quit" flags must be specified.  The
     * eRestart flag may be bit-wise combined with one of the "Quit" flags to
     * cause the application to restart after it quits.
     */
/**
     * Attempt to quit if all windows are closed.
     */
  enum { eConsiderQuit = 1U };

  /**
     * Try to close all windows, then quit if successful.
     */
  enum { eAttemptQuit = 2U };

  /**
     * Quit, damnit!
     */
  enum { eForceQuit = 3U };

  /**
     * Restart the application after quitting.  The application will be
     * restarted with the same profile and an empty command line.
     */
  enum { eRestart = 16U };

  /**
     * Exit the event loop, and shut down the app.
     *
     * @param aMode
     *        This parameter modifies how the app is shutdown, and it is
     *        constructed from the constants defined above.
     */
  /* void quit (in PRUint32 aMode); */
  NS_SCRIPTABLE NS_IMETHOD Quit(PRUint32 aMode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppStartup, NS_IAPPSTARTUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSTARTUP \
  NS_SCRIPTABLE NS_IMETHOD CreateHiddenWindow(void); \
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void); \
  NS_SCRIPTABLE NS_IMETHOD Run(void); \
  NS_SCRIPTABLE NS_IMETHOD EnterLastWindowClosingSurvivalArea(void); \
  NS_SCRIPTABLE NS_IMETHOD ExitLastWindowClosingSurvivalArea(void); \
  NS_SCRIPTABLE NS_IMETHOD Quit(PRUint32 aMode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSTARTUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateHiddenWindow(void) { return _to CreateHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void) { return _to DestroyHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD Run(void) { return _to Run(); } \
  NS_SCRIPTABLE NS_IMETHOD EnterLastWindowClosingSurvivalArea(void) { return _to EnterLastWindowClosingSurvivalArea(); } \
  NS_SCRIPTABLE NS_IMETHOD ExitLastWindowClosingSurvivalArea(void) { return _to ExitLastWindowClosingSurvivalArea(); } \
  NS_SCRIPTABLE NS_IMETHOD Quit(PRUint32 aMode) { return _to Quit(aMode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSTARTUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateHiddenWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DestroyHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD Run(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Run(); } \
  NS_SCRIPTABLE NS_IMETHOD EnterLastWindowClosingSurvivalArea(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnterLastWindowClosingSurvivalArea(); } \
  NS_SCRIPTABLE NS_IMETHOD ExitLastWindowClosingSurvivalArea(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExitLastWindowClosingSurvivalArea(); } \
  NS_SCRIPTABLE NS_IMETHOD Quit(PRUint32 aMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Quit(aMode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppStartup : public nsIAppStartup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSTARTUP

  nsAppStartup();

private:
  ~nsAppStartup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppStartup, nsIAppStartup)

nsAppStartup::nsAppStartup()
{
  /* member initializers and constructor code */
}

nsAppStartup::~nsAppStartup()
{
  /* destructor code */
}

/* void createHiddenWindow (); */
NS_IMETHODIMP nsAppStartup::CreateHiddenWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroyHiddenWindow (); */
NS_IMETHODIMP nsAppStartup::DestroyHiddenWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void run (); */
NS_IMETHODIMP nsAppStartup::Run()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enterLastWindowClosingSurvivalArea (); */
NS_IMETHODIMP nsAppStartup::EnterLastWindowClosingSurvivalArea()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exitLastWindowClosingSurvivalArea (); */
NS_IMETHODIMP nsAppStartup::ExitLastWindowClosingSurvivalArea()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void quit (in PRUint32 aMode); */
NS_IMETHODIMP nsAppStartup::Quit(PRUint32 aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAppStartup2 */
#define NS_IAPPSTARTUP2_IID_STR "3012668f-44b6-49b1-89fb-761a912a78c1"

#define NS_IAPPSTARTUP2_IID \
  {0x3012668f, 0x44b6, 0x49b1, \
    { 0x89, 0xfb, 0x76, 0x1a, 0x91, 0x2a, 0x78, 0xc1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAppStartup2 : public nsIAppStartup {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSTARTUP2_IID)

  /* readonly attribute boolean shuttingDown; */
  NS_SCRIPTABLE NS_IMETHOD GetShuttingDown(PRBool *aShuttingDown) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppStartup2, NS_IAPPSTARTUP2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSTARTUP2 \
  NS_SCRIPTABLE NS_IMETHOD GetShuttingDown(PRBool *aShuttingDown); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSTARTUP2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetShuttingDown(PRBool *aShuttingDown) { return _to GetShuttingDown(aShuttingDown); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSTARTUP2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetShuttingDown(PRBool *aShuttingDown) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShuttingDown(aShuttingDown); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppStartup2 : public nsIAppStartup2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSTARTUP2

  nsAppStartup2();

private:
  ~nsAppStartup2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppStartup2, nsIAppStartup2)

nsAppStartup2::nsAppStartup2()
{
  /* member initializers and constructor code */
}

nsAppStartup2::~nsAppStartup2()
{
  /* destructor code */
}

/* readonly attribute boolean shuttingDown; */
NS_IMETHODIMP nsAppStartup2::GetShuttingDown(PRBool *aShuttingDown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * This success code may be returned by nsIAppStartup::Run to indicate that the
 * application should be restarted.  This condition corresponds to the case in
 * which nsIAppStartup::Quit was called with the eRestart flag.
 */
#define NS_SUCCESS_RESTART_APP \
    NS_ERROR_GENERATE_SUCCESS(NS_ERROR_MODULE_GENERAL, 1)

#endif /* __gen_nsIAppStartup_h__ */
