/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/threads/nsIProcess.idl
 */

#ifndef __gen_nsIProcess_h__
#define __gen_nsIProcess_h__


#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIObserver; /* forward declaration */


/* starting interface:    nsIProcess */
#define NS_IPROCESS_IID_STR "d573f1f3-fcdd-4dbe-980b-4ba79e6718dc"

#define NS_IPROCESS_IID \
  {0xd573f1f3, 0xfcdd, 0x4dbe, \
    { 0x98, 0x0b, 0x4b, 0xa7, 0x9e, 0x67, 0x18, 0xdc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIProcess : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROCESS_IID)

  /**
   * Initialises the process with an executable to be run. Call the run method
   * to run the executable.
   * @param executable The executable to run.
   */
  /* void init (in nsIFile executable); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIFile *executable) = 0;

  /**
   * Not implemented. Will be removed in a future version of this interface.
   */
  /* void initWithPid (in unsigned long pid); */
  NS_SCRIPTABLE NS_IMETHOD InitWithPid(PRUint32 pid) = 0;

  /**
   * Kills the running process. After exiting the process will either have
   * been killed or a failure will have been returned.
   */
  /* void kill (); */
  NS_SCRIPTABLE NS_IMETHOD Kill(void) = 0;

  /**
   * Executes the file this object was initialized with
   * @param blocking   Whether to wait until the process terminates before
                       returning or not.
   * @param args       An array of arguments to pass to the process in the
   *                   native character set.
   * @param count      The length of the args array.
   */
  /* void run (in boolean blocking, [array, size_is (count)] in string args, in unsigned long count); */
  NS_SCRIPTABLE NS_IMETHOD Run(PRBool blocking, const char **args, PRUint32 count) = 0;

  /**
   * Not implemented. Will be removed in a future version of this interface.
   */
  /* readonly attribute nsIFile location; */
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIFile * *aLocation) = 0;

  /**
   * The process identifier of the currently running process. This will only
   * be available after the process has started and may not be available on
   * some platforms.
   */
  /* readonly attribute unsigned long pid; */
  NS_SCRIPTABLE NS_IMETHOD GetPid(PRUint32 *aPid) = 0;

  /**
   * Not implemented. Will be removed in a future version of this interface.
   */
  /* readonly attribute string processName; */
  NS_SCRIPTABLE NS_IMETHOD GetProcessName(char * *aProcessName) = 0;

  /**
   * Not implemented. Will be removed in a future version of this interface.
   */
  /* readonly attribute unsigned long processSignature; */
  NS_SCRIPTABLE NS_IMETHOD GetProcessSignature(PRUint32 *aProcessSignature) = 0;

  /**
   * The exit value of the process. This is only valid after the process has
   * exited.
   */
  /* readonly attribute long exitValue; */
  NS_SCRIPTABLE NS_IMETHOD GetExitValue(PRInt32 *aExitValue) = 0;

  /**
   * Returns whether the process is currently running or not.
   */
  /* readonly attribute boolean isRunning; */
  NS_SCRIPTABLE NS_IMETHOD GetIsRunning(PRBool *aIsRunning) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProcess, NS_IPROCESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROCESS \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIFile *executable); \
  NS_SCRIPTABLE NS_IMETHOD InitWithPid(PRUint32 pid); \
  NS_SCRIPTABLE NS_IMETHOD Kill(void); \
  NS_SCRIPTABLE NS_IMETHOD Run(PRBool blocking, const char **args, PRUint32 count); \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIFile * *aLocation); \
  NS_SCRIPTABLE NS_IMETHOD GetPid(PRUint32 *aPid); \
  NS_SCRIPTABLE NS_IMETHOD GetProcessName(char * *aProcessName); \
  NS_SCRIPTABLE NS_IMETHOD GetProcessSignature(PRUint32 *aProcessSignature); \
  NS_SCRIPTABLE NS_IMETHOD GetExitValue(PRInt32 *aExitValue); \
  NS_SCRIPTABLE NS_IMETHOD GetIsRunning(PRBool *aIsRunning); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROCESS(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIFile *executable) { return _to Init(executable); } \
  NS_SCRIPTABLE NS_IMETHOD InitWithPid(PRUint32 pid) { return _to InitWithPid(pid); } \
  NS_SCRIPTABLE NS_IMETHOD Kill(void) { return _to Kill(); } \
  NS_SCRIPTABLE NS_IMETHOD Run(PRBool blocking, const char **args, PRUint32 count) { return _to Run(blocking, args, count); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIFile * *aLocation) { return _to GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetPid(PRUint32 *aPid) { return _to GetPid(aPid); } \
  NS_SCRIPTABLE NS_IMETHOD GetProcessName(char * *aProcessName) { return _to GetProcessName(aProcessName); } \
  NS_SCRIPTABLE NS_IMETHOD GetProcessSignature(PRUint32 *aProcessSignature) { return _to GetProcessSignature(aProcessSignature); } \
  NS_SCRIPTABLE NS_IMETHOD GetExitValue(PRInt32 *aExitValue) { return _to GetExitValue(aExitValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsRunning(PRBool *aIsRunning) { return _to GetIsRunning(aIsRunning); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROCESS(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIFile *executable) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(executable); } \
  NS_SCRIPTABLE NS_IMETHOD InitWithPid(PRUint32 pid) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithPid(pid); } \
  NS_SCRIPTABLE NS_IMETHOD Kill(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Kill(); } \
  NS_SCRIPTABLE NS_IMETHOD Run(PRBool blocking, const char **args, PRUint32 count) { return !_to ? NS_ERROR_NULL_POINTER : _to->Run(blocking, args, count); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIFile * *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetPid(PRUint32 *aPid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPid(aPid); } \
  NS_SCRIPTABLE NS_IMETHOD GetProcessName(char * *aProcessName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProcessName(aProcessName); } \
  NS_SCRIPTABLE NS_IMETHOD GetProcessSignature(PRUint32 *aProcessSignature) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProcessSignature(aProcessSignature); } \
  NS_SCRIPTABLE NS_IMETHOD GetExitValue(PRInt32 *aExitValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExitValue(aExitValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsRunning(PRBool *aIsRunning) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsRunning(aIsRunning); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProcess : public nsIProcess
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROCESS

  nsProcess();

private:
  ~nsProcess();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProcess, nsIProcess)

nsProcess::nsProcess()
{
  /* member initializers and constructor code */
}

nsProcess::~nsProcess()
{
  /* destructor code */
}

/* void init (in nsIFile executable); */
NS_IMETHODIMP nsProcess::Init(nsIFile *executable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithPid (in unsigned long pid); */
NS_IMETHODIMP nsProcess::InitWithPid(PRUint32 pid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void kill (); */
NS_IMETHODIMP nsProcess::Kill()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void run (in boolean blocking, [array, size_is (count)] in string args, in unsigned long count); */
NS_IMETHODIMP nsProcess::Run(PRBool blocking, const char **args, PRUint32 count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile location; */
NS_IMETHODIMP nsProcess::GetLocation(nsIFile * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long pid; */
NS_IMETHODIMP nsProcess::GetPid(PRUint32 *aPid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string processName; */
NS_IMETHODIMP nsProcess::GetProcessName(char * *aProcessName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long processSignature; */
NS_IMETHODIMP nsProcess::GetProcessSignature(PRUint32 *aProcessSignature)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long exitValue; */
NS_IMETHODIMP nsProcess::GetExitValue(PRInt32 *aExitValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isRunning; */
NS_IMETHODIMP nsProcess::GetIsRunning(PRBool *aIsRunning)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIProcess2 */
#define NS_IPROCESS2_IID_STR "7d362c71-308e-4724-b1eb-8451fe133026"

#define NS_IPROCESS2_IID \
  {0x7d362c71, 0x308e, 0x4724, \
    { 0xb1, 0xeb, 0x84, 0x51, 0xfe, 0x13, 0x30, 0x26 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIProcess2 : public nsIProcess {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROCESS2_IID)

  /**
   * Executes the file this object was initialized with optionally calling
   * an observer after the process has finished running.
   * @param args       An array of arguments to pass to the process in the
   *                   native character set.
   * @param count      The length of the args array.
   * @param observer   An observer to notify when the process has completed. It
   *                   will receive this process instance as the subject and
   *                   "process-finished" or "process-failed" as the topic. The
   *                   observer will be notified on the main thread.
   * @param holdWeak   Whether to use a weak reference to hold the observer.
   */
  /* void runAsync ([array, size_is (count)] in string args, in unsigned long count, [optional] in nsIObserver observer, [optional] in boolean holdWeak); */
  NS_SCRIPTABLE NS_IMETHOD RunAsync(const char **args, PRUint32 count, nsIObserver *observer, PRBool holdWeak) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProcess2, NS_IPROCESS2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROCESS2 \
  NS_SCRIPTABLE NS_IMETHOD RunAsync(const char **args, PRUint32 count, nsIObserver *observer, PRBool holdWeak); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROCESS2(_to) \
  NS_SCRIPTABLE NS_IMETHOD RunAsync(const char **args, PRUint32 count, nsIObserver *observer, PRBool holdWeak) { return _to RunAsync(args, count, observer, holdWeak); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROCESS2(_to) \
  NS_SCRIPTABLE NS_IMETHOD RunAsync(const char **args, PRUint32 count, nsIObserver *observer, PRBool holdWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunAsync(args, count, observer, holdWeak); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProcess2 : public nsIProcess2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROCESS2

  nsProcess2();

private:
  ~nsProcess2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProcess2, nsIProcess2)

nsProcess2::nsProcess2()
{
  /* member initializers and constructor code */
}

nsProcess2::~nsProcess2()
{
  /* destructor code */
}

/* void runAsync ([array, size_is (count)] in string args, in unsigned long count, [optional] in nsIObserver observer, [optional] in boolean holdWeak); */
NS_IMETHODIMP nsProcess2::RunAsync(const char **args, PRUint32 count, nsIObserver *observer, PRBool holdWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_PROCESS_CONTRACTID "@mozilla.org/process/util;1"
#define NS_PROCESS_CLASSNAME "Process Specification"

#endif /* __gen_nsIProcess_h__ */
