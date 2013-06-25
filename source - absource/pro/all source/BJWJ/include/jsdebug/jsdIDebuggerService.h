/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/jsd/idl/jsdIDebuggerService.idl
 */

#ifndef __gen_jsdIDebuggerService_h__
#define __gen_jsdIDebuggerService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jsdebug.h"
#include "nsAString.h"
class jsdIDebuggerService; /* forward declaration */

class jsdIFilter; /* forward declaration */

class jsdINestCallback; /* forward declaration */

class jsdIFilterEnumerator; /* forward declaration */

class jsdIContextEnumerator; /* forward declaration */

class jsdIScriptEnumerator; /* forward declaration */

class jsdIScriptHook; /* forward declaration */

class jsdIErrorHook; /* forward declaration */

class jsdIExecutionHook; /* forward declaration */

class jsdICallHook; /* forward declaration */

class jsdIEphemeral; /* forward declaration */

class jsdIContext; /* forward declaration */

class jsdIStackFrame; /* forward declaration */

class jsdIScript; /* forward declaration */

class jsdIValue; /* forward declaration */

class jsdIObject; /* forward declaration */

class jsdIProperty; /* forward declaration */


/* starting interface:    jsdIDebuggerService */
#define JSDIDEBUGGERSERVICE_IID_STR "a074fcb4-73d7-4825-a4cd-7cbb1d6800b1"

#define JSDIDEBUGGERSERVICE_IID \
  {0xa074fcb4, 0x73d7, 0x4825, \
    { 0xa4, 0xcd, 0x7c, 0xbb, 0x1d, 0x68, 0x00, 0xb1 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIDebuggerService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDIDEBUGGERSERVICE_IID)

  /**
 * Debugger service.  It's not a good idea to have more than one active client of
 * the debugger service.
 */
/** Internal use only. */
  /* [noscript] readonly attribute JSDContext JSDContext; */
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) = 0;

  /**
     * Called when an error or warning occurs.
     */
  /* attribute jsdIErrorHook errorHook; */
  NS_SCRIPTABLE NS_IMETHOD GetErrorHook(jsdIErrorHook * *aErrorHook) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetErrorHook(jsdIErrorHook * aErrorHook) = 0;

  /**
     * Called when a jsdIScript is created or destroyed.
     */
  /* attribute jsdIScriptHook scriptHook; */
  NS_SCRIPTABLE NS_IMETHOD GetScriptHook(jsdIScriptHook * *aScriptHook) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetScriptHook(jsdIScriptHook * aScriptHook) = 0;

  /**
     * Called when the engine encounters a breakpoint.
     */
  /* attribute jsdIExecutionHook breakpointHook; */
  NS_SCRIPTABLE NS_IMETHOD GetBreakpointHook(jsdIExecutionHook * *aBreakpointHook) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBreakpointHook(jsdIExecutionHook * aBreakpointHook) = 0;

  /**
     * Called when the engine encounters the debugger keyword.
     */
  /* attribute jsdIExecutionHook debuggerHook; */
  NS_SCRIPTABLE NS_IMETHOD GetDebuggerHook(jsdIExecutionHook * *aDebuggerHook) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDebuggerHook(jsdIExecutionHook * aDebuggerHook) = 0;

  /**
     * Called when the errorHook returns false.
     */
  /* attribute jsdIExecutionHook debugHook; */
  NS_SCRIPTABLE NS_IMETHOD GetDebugHook(jsdIExecutionHook * *aDebugHook) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDebugHook(jsdIExecutionHook * aDebugHook) = 0;

  /**
     * Called before the next PC is executed.
     */
  /* attribute jsdIExecutionHook interruptHook; */
  NS_SCRIPTABLE NS_IMETHOD GetInterruptHook(jsdIExecutionHook * *aInterruptHook) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInterruptHook(jsdIExecutionHook * aInterruptHook) = 0;

  /**
     * Called when an exception is thrown (even if it will be caught.)
     */
  /* attribute jsdIExecutionHook throwHook; */
  NS_SCRIPTABLE NS_IMETHOD GetThrowHook(jsdIExecutionHook * *aThrowHook) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetThrowHook(jsdIExecutionHook * aThrowHook) = 0;

  /**
     * Called before and after a toplevel script is evaluated.
     */
  /* attribute jsdICallHook topLevelHook; */
  NS_SCRIPTABLE NS_IMETHOD GetTopLevelHook(jsdICallHook * *aTopLevelHook) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTopLevelHook(jsdICallHook * aTopLevelHook) = 0;

  /**
     * Called before and after a function is called.
     */
  /* attribute jsdICallHook functionHook; */
  NS_SCRIPTABLE NS_IMETHOD GetFunctionHook(jsdICallHook * *aFunctionHook) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFunctionHook(jsdICallHook * aFunctionHook) = 0;

  /**
     * VERSION_* values must be kept in sync with the JSVersion enumeration in
     * jspubtd.h.
     */
/**
     * Possible values for jsdIScript::version and jsdIContext::version.
     */
  enum { VERSION_1_0 = 100 };

  enum { VERSION_1_1 = 110 };

  enum { VERSION_1_2 = 120 };

  enum { VERSION_1_3 = 130 };

  enum { VERSION_1_4 = 140 };

  enum { VERSION_1_5 = 150 };

  enum { VERSION_DEFAULT = 0 };

  enum { VERSION_UNKNOWN = -1 };

  /**
     * These flags need to be kept in sync with the context flags defined in
     * jsdebug.h
     */
/**
     * Link native frames in call stacks.
     */
  enum { ENABLE_NATIVE_FRAMES = 1U };

  /**
     * Normally, if a script has a 0 in JSD_SCRIPT_PROFILE_BIT it is included in
     * profile data, otherwise it is not profiled.  Setting the
     * PROFILE_WHEN_SET flag reverses this convention.
     */
  enum { PROFILE_WHEN_SET = 2U };

  /**
     * Normally, when the script in the top frame of a thread state has a 1 in
     * JSD_SCRIPT_DEBUG_BIT, the execution hook is ignored.  Setting the
     * DEBUG_WHEN_SET flag reverses this convention.
     */
  enum { DEBUG_WHEN_SET = 4U };

  /**
     * When this flag is set the internal call hook will collect profile data.
     */
  enum { COLLECT_PROFILE_DATA = 8U };

  /**
     * When this flag is set, stack frames that are disabled for debugging
     * will not appear in the call stack chain.
     */
  enum { HIDE_DISABLED_FRAMES = 16U };

  /**
     * When this flag is set, the debugger will only check the
     * JSD_SCRIPT_DEBUG_BIT on the top (most recent) stack frame.  This
     * makes it possible to stop in an enabled frame which was called from
     * a stack that contains a disabled frame.
     *
     * When this flag is *not* set, any stack that contains a disabled frame
     * will not be debugged (the execution hook will not be invoked.)
     *
     * This only applies when the reason for calling the hook would have
     * been TYPE_INTERRUPTED or TYPE_THROW.  TYPE_BREAKPOINT,
     * TYPE_DEBUG_REQUESTED, and TYPE_DEBUGGER_KEYWORD always stop, regardless
     * of this setting, as long as the top frame is not disabled.
     *
     * If HIDE_DISABLED_FRAMES is set, this is effectively set as well.
     */
  enum { MASK_TOP_FRAME_ONLY = 32U };

  /**
     * When this flag is set, object creation will not be tracked.  This will
     * reduce the performance price you pay by enabling the debugger.
     */
  enum { DISABLE_OBJECT_TRACE = 64U };

  /**
     * Debugger service flags.
     */
  /* attribute unsigned long flags; */
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) = 0;

  /**
     * Major version number of implementation.
     */
  /* readonly attribute unsigned long implementationMajor; */
  NS_SCRIPTABLE NS_IMETHOD GetImplementationMajor(PRUint32 *aImplementationMajor) = 0;

  /**
     * Minor version number of implementation.
     */
  /* readonly attribute unsigned long implementationMinor; */
  NS_SCRIPTABLE NS_IMETHOD GetImplementationMinor(PRUint32 *aImplementationMinor) = 0;

  /**
     * Free form string identifier for implementation.
     */
  /* readonly attribute string implementationString; */
  NS_SCRIPTABLE NS_IMETHOD GetImplementationString(char * *aImplementationString) = 0;

  /**
     * |true| if the debugger should register an app-start observer in order
     * to begin collecting debug information when mozilla is launched.
     */
  /* attribute boolean initAtStartup; */
  NS_SCRIPTABLE NS_IMETHOD GetInitAtStartup(PRBool *aInitAtStartup) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInitAtStartup(PRBool aInitAtStartup) = 0;

  /**
     * |true| if the debugger service has been turned on.  This does not
     * necessarily mean another app is actively using the service, as the 
     * autostart pref may have turned the service on.
     */
  /* readonly attribute boolean isOn; */
  NS_SCRIPTABLE NS_IMETHOD GetIsOn(PRBool *aIsOn) = 0;

  /**
     * Turn on the debugger.  This function should only be called from JavaScript
     * code.  The debugger will be enabled on the runtime the call is made on,
     * as determined by nsIXPCNativeCallContext.
     */
  /* void on (); */
  NS_SCRIPTABLE NS_IMETHOD On(void) = 0;

  /**
     * Turn on the debugger for a given runtime.
     *
     * @param rt The runtime you want to debug.  You cannot turn the debugger
     *           on for multiple runtimes.
     */
  /* [noscript] void onForRuntime (in JSRuntime rt); */
  NS_IMETHOD OnForRuntime(JSRuntime * rt) = 0;

  /**
     * Turn the debugger off.  This will invalidate all of your jsdIEphemeral
     * derived objects, and clear all of your breakpoints.  In theory you
     * should be able to turn the debugger back on at some later time without
     * any problems.
     */
  /* void off (); */
  NS_SCRIPTABLE NS_IMETHOD Off(void) = 0;

  /**
     * Peek at the current pause depth of the debugger.
     *
     * @return depth Number of pause() calls still waiting to be unPause()d.
     */
  /* readonly attribute unsigned long pauseDepth; */
  NS_SCRIPTABLE NS_IMETHOD GetPauseDepth(PRUint32 *aPauseDepth) = 0;

  /**
     * Temporarily disable the debugger.  Hooks will not be called while the
     * debugger is paused.  Multiple calls to pause will increase the "pause
     * depth", and equal number of unPause calles must be made to resume
     * normal debugging.
     *
     * @return depth Number of times pause has been called since the debugger
     *               has been unpaused.
     */
  /* unsigned long pause (); */
  NS_SCRIPTABLE NS_IMETHOD Pause(PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
     * Undo a pause.
     *
     * @return depth The number of remaining pending pause calls.
     */
  /* unsigned long unPause (); */
  NS_SCRIPTABLE NS_IMETHOD UnPause(PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
     * Force the engine to perform garbage collection.
     */
  /* void GC (); */
  NS_SCRIPTABLE NS_IMETHOD GC(void) = 0;

  /**
     * Clear profile data for all scripts.
     */
  /* void clearProfileData (); */
  NS_SCRIPTABLE NS_IMETHOD ClearProfileData(void) = 0;

  /**
     * Adds an execution hook filter.  These filters are consulted each time one
     * of the jsdIExecutionHooks is about to be called.  Filters are matched in
     * a first in, first compared fashion.  The first filter to match determines
     * whether or not the hook is called.  Use swapFilter to reorder existing
     * filters, and removeFilter to remove them.
     *
     * If |filter| is already present this method throws NS_ERROR_INVALID_ARG.
     *
     * @param filter Object representing the filter to add.
     * @param after  Insert |filter| after this one.  Pass null to insert at
     *               the beginning.
     */
  /* void insertFilter (in jsdIFilter filter, in jsdIFilter after); */
  NS_SCRIPTABLE NS_IMETHOD InsertFilter(jsdIFilter *filter, jsdIFilter *after) = 0;

  /**
     * Same as insertFilter, except always add to the end of the list.
     */
  /* void appendFilter (in jsdIFilter filter); */
  NS_SCRIPTABLE NS_IMETHOD AppendFilter(jsdIFilter *filter) = 0;

  /**
     * Remove a filter.
     *
     * If |filter| is not present this method throws NS_ERROR_INVALID_ARG.
     *
     * @param filter Object representing the filter to remove.  Must be the exact
     * object passed to addFilter, not just a new object with the same
     * properties.
     */
  /* void removeFilter (in jsdIFilter filter); */
  NS_SCRIPTABLE NS_IMETHOD RemoveFilter(jsdIFilter *filter) = 0;

  /**
     * Swap position of two filters.
     * 
     * If |filter_a| is not present, this method throws NS_ERROR_INVALID_ARG.
     * If |filter_b| is not present, filter_a is replaced by filter_b.
     * If |filter_a| == |filter_b|, then filter is refreshed.
     */
  /* void swapFilters (in jsdIFilter filter_a, in jsdIFilter filter_b); */
  NS_SCRIPTABLE NS_IMETHOD SwapFilters(jsdIFilter *filter_a, jsdIFilter *filter_b) = 0;

  /**
     * Enumerate registered filters.  This routine refreshes each filter before
     * passing them on to the enumeration function.  Calling this with a null
     * |enumerator| is equivalent to jsdIService::refreshFilters.
     *
     * @param enumerator jsdIFilterEnumerator instance to be called back for the
     *                   enumeration.
     */
  /* void enumerateFilters (in jsdIFilterEnumerator enumerator); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateFilters(jsdIFilterEnumerator *enumerator) = 0;

  /**
     * Force the debugger to resync its internal filter cache with the
     * actual values in the jsdIFilter objects.  To refresh a single filter
     * use jsdIService::swapFilters.  This method is equivalent to
     * jsdIService::enumerateFilters with a null enumerator.
     */
  /* void refreshFilters (); */
  NS_SCRIPTABLE NS_IMETHOD RefreshFilters(void) = 0;

  /**
     * Clear the list of filters.
     */
  /* void clearFilters (); */
  NS_SCRIPTABLE NS_IMETHOD ClearFilters(void) = 0;

  /**
     * Enumerate all known contexts.
     */
  /* void enumerateContexts (in jsdIContextEnumerator enumerator); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateContexts(jsdIContextEnumerator *enumerator) = 0;

  /**
     * Enumerate all scripts the debugger knows about.  Any scripts created
     * before you turned the debugger on, or after turning the debugger off
     * will not be available unless the autostart perf is set.
     *
     * @param enumerator jsdIScriptEnumerator instance to be called back for
     *                   the enumeration.
     */
  /* void enumerateScripts (in jsdIScriptEnumerator enumerator); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateScripts(jsdIScriptEnumerator *enumerator) = 0;

  /**
     * Clear all breakpoints in all scripts.
     */
  /* void clearAllBreakpoints (); */
  NS_SCRIPTABLE NS_IMETHOD ClearAllBreakpoints(void) = 0;

  /**
     * When called from JavaScript, this method returns the jsdIValue wrapper
     * for the given value.  If a wrapper does not exist one will be created.
     * When called from another language this method returns an xpconnect
     * defined error code.
     */
  /* jsdIValue wrapValue (); */
  NS_SCRIPTABLE NS_IMETHOD WrapValue(jsdIValue **_retval NS_OUTPARAM) = 0;

  /**
     * Push a new network queue, and enter a new UI event loop.
     * @param callback jsdINestCallback instance to be called back after the
     *                 network queue has been pushed, but before the
     *                 UI loop starts.
     * @return depth returns the current number of times the event loop has been
     *               nested.  your code can use it for sanity checks.
     */
  /* unsigned long enterNestedEventLoop (in jsdINestCallback callback); */
  NS_SCRIPTABLE NS_IMETHOD EnterNestedEventLoop(jsdINestCallback *callback, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
     * Exit the current nested event loop after the current iteration completes,
     * and pop the network event queue.
     *
     * @return depth returns the current number of times the event loop has been
     *               nested.  your code can use it for sanity checks.
     */
  /* unsigned long exitNestedEventLoop (); */
  NS_SCRIPTABLE NS_IMETHOD ExitNestedEventLoop(PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
     * Output dump of JS heap.
     *
     * @param fileName Filename to dump the heap into.
     */
  /* void dumpHeap (in string fileName); */
  NS_SCRIPTABLE NS_IMETHOD DumpHeap(const char *fileName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIDebuggerService, JSDIDEBUGGERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDIDEBUGGERSERVICE \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext); \
  NS_SCRIPTABLE NS_IMETHOD GetErrorHook(jsdIErrorHook * *aErrorHook); \
  NS_SCRIPTABLE NS_IMETHOD SetErrorHook(jsdIErrorHook * aErrorHook); \
  NS_SCRIPTABLE NS_IMETHOD GetScriptHook(jsdIScriptHook * *aScriptHook); \
  NS_SCRIPTABLE NS_IMETHOD SetScriptHook(jsdIScriptHook * aScriptHook); \
  NS_SCRIPTABLE NS_IMETHOD GetBreakpointHook(jsdIExecutionHook * *aBreakpointHook); \
  NS_SCRIPTABLE NS_IMETHOD SetBreakpointHook(jsdIExecutionHook * aBreakpointHook); \
  NS_SCRIPTABLE NS_IMETHOD GetDebuggerHook(jsdIExecutionHook * *aDebuggerHook); \
  NS_SCRIPTABLE NS_IMETHOD SetDebuggerHook(jsdIExecutionHook * aDebuggerHook); \
  NS_SCRIPTABLE NS_IMETHOD GetDebugHook(jsdIExecutionHook * *aDebugHook); \
  NS_SCRIPTABLE NS_IMETHOD SetDebugHook(jsdIExecutionHook * aDebugHook); \
  NS_SCRIPTABLE NS_IMETHOD GetInterruptHook(jsdIExecutionHook * *aInterruptHook); \
  NS_SCRIPTABLE NS_IMETHOD SetInterruptHook(jsdIExecutionHook * aInterruptHook); \
  NS_SCRIPTABLE NS_IMETHOD GetThrowHook(jsdIExecutionHook * *aThrowHook); \
  NS_SCRIPTABLE NS_IMETHOD SetThrowHook(jsdIExecutionHook * aThrowHook); \
  NS_SCRIPTABLE NS_IMETHOD GetTopLevelHook(jsdICallHook * *aTopLevelHook); \
  NS_SCRIPTABLE NS_IMETHOD SetTopLevelHook(jsdICallHook * aTopLevelHook); \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionHook(jsdICallHook * *aFunctionHook); \
  NS_SCRIPTABLE NS_IMETHOD SetFunctionHook(jsdICallHook * aFunctionHook); \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationMajor(PRUint32 *aImplementationMajor); \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationMinor(PRUint32 *aImplementationMinor); \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationString(char * *aImplementationString); \
  NS_SCRIPTABLE NS_IMETHOD GetInitAtStartup(PRBool *aInitAtStartup); \
  NS_SCRIPTABLE NS_IMETHOD SetInitAtStartup(PRBool aInitAtStartup); \
  NS_SCRIPTABLE NS_IMETHOD GetIsOn(PRBool *aIsOn); \
  NS_SCRIPTABLE NS_IMETHOD On(void); \
  NS_IMETHOD OnForRuntime(JSRuntime * rt); \
  NS_SCRIPTABLE NS_IMETHOD Off(void); \
  NS_SCRIPTABLE NS_IMETHOD GetPauseDepth(PRUint32 *aPauseDepth); \
  NS_SCRIPTABLE NS_IMETHOD Pause(PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD UnPause(PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GC(void); \
  NS_SCRIPTABLE NS_IMETHOD ClearProfileData(void); \
  NS_SCRIPTABLE NS_IMETHOD InsertFilter(jsdIFilter *filter, jsdIFilter *after); \
  NS_SCRIPTABLE NS_IMETHOD AppendFilter(jsdIFilter *filter); \
  NS_SCRIPTABLE NS_IMETHOD RemoveFilter(jsdIFilter *filter); \
  NS_SCRIPTABLE NS_IMETHOD SwapFilters(jsdIFilter *filter_a, jsdIFilter *filter_b); \
  NS_SCRIPTABLE NS_IMETHOD EnumerateFilters(jsdIFilterEnumerator *enumerator); \
  NS_SCRIPTABLE NS_IMETHOD RefreshFilters(void); \
  NS_SCRIPTABLE NS_IMETHOD ClearFilters(void); \
  NS_SCRIPTABLE NS_IMETHOD EnumerateContexts(jsdIContextEnumerator *enumerator); \
  NS_SCRIPTABLE NS_IMETHOD EnumerateScripts(jsdIScriptEnumerator *enumerator); \
  NS_SCRIPTABLE NS_IMETHOD ClearAllBreakpoints(void); \
  NS_SCRIPTABLE NS_IMETHOD WrapValue(jsdIValue **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EnterNestedEventLoop(jsdINestCallback *callback, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ExitNestedEventLoop(PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DumpHeap(const char *fileName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDIDEBUGGERSERVICE(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return _to GetJSDContext(aJSDContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorHook(jsdIErrorHook * *aErrorHook) { return _to GetErrorHook(aErrorHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetErrorHook(jsdIErrorHook * aErrorHook) { return _to SetErrorHook(aErrorHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetScriptHook(jsdIScriptHook * *aScriptHook) { return _to GetScriptHook(aScriptHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetScriptHook(jsdIScriptHook * aScriptHook) { return _to SetScriptHook(aScriptHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetBreakpointHook(jsdIExecutionHook * *aBreakpointHook) { return _to GetBreakpointHook(aBreakpointHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetBreakpointHook(jsdIExecutionHook * aBreakpointHook) { return _to SetBreakpointHook(aBreakpointHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetDebuggerHook(jsdIExecutionHook * *aDebuggerHook) { return _to GetDebuggerHook(aDebuggerHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetDebuggerHook(jsdIExecutionHook * aDebuggerHook) { return _to SetDebuggerHook(aDebuggerHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetDebugHook(jsdIExecutionHook * *aDebugHook) { return _to GetDebugHook(aDebugHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetDebugHook(jsdIExecutionHook * aDebugHook) { return _to SetDebugHook(aDebugHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetInterruptHook(jsdIExecutionHook * *aInterruptHook) { return _to GetInterruptHook(aInterruptHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetInterruptHook(jsdIExecutionHook * aInterruptHook) { return _to SetInterruptHook(aInterruptHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetThrowHook(jsdIExecutionHook * *aThrowHook) { return _to GetThrowHook(aThrowHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetThrowHook(jsdIExecutionHook * aThrowHook) { return _to SetThrowHook(aThrowHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetTopLevelHook(jsdICallHook * *aTopLevelHook) { return _to GetTopLevelHook(aTopLevelHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetTopLevelHook(jsdICallHook * aTopLevelHook) { return _to SetTopLevelHook(aTopLevelHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionHook(jsdICallHook * *aFunctionHook) { return _to GetFunctionHook(aFunctionHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetFunctionHook(jsdICallHook * aFunctionHook) { return _to SetFunctionHook(aFunctionHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return _to GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return _to SetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationMajor(PRUint32 *aImplementationMajor) { return _to GetImplementationMajor(aImplementationMajor); } \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationMinor(PRUint32 *aImplementationMinor) { return _to GetImplementationMinor(aImplementationMinor); } \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationString(char * *aImplementationString) { return _to GetImplementationString(aImplementationString); } \
  NS_SCRIPTABLE NS_IMETHOD GetInitAtStartup(PRBool *aInitAtStartup) { return _to GetInitAtStartup(aInitAtStartup); } \
  NS_SCRIPTABLE NS_IMETHOD SetInitAtStartup(PRBool aInitAtStartup) { return _to SetInitAtStartup(aInitAtStartup); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsOn(PRBool *aIsOn) { return _to GetIsOn(aIsOn); } \
  NS_SCRIPTABLE NS_IMETHOD On(void) { return _to On(); } \
  NS_IMETHOD OnForRuntime(JSRuntime * rt) { return _to OnForRuntime(rt); } \
  NS_SCRIPTABLE NS_IMETHOD Off(void) { return _to Off(); } \
  NS_SCRIPTABLE NS_IMETHOD GetPauseDepth(PRUint32 *aPauseDepth) { return _to GetPauseDepth(aPauseDepth); } \
  NS_SCRIPTABLE NS_IMETHOD Pause(PRUint32 *_retval NS_OUTPARAM) { return _to Pause(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnPause(PRUint32 *_retval NS_OUTPARAM) { return _to UnPause(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GC(void) { return _to GC(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearProfileData(void) { return _to ClearProfileData(); } \
  NS_SCRIPTABLE NS_IMETHOD InsertFilter(jsdIFilter *filter, jsdIFilter *after) { return _to InsertFilter(filter, after); } \
  NS_SCRIPTABLE NS_IMETHOD AppendFilter(jsdIFilter *filter) { return _to AppendFilter(filter); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFilter(jsdIFilter *filter) { return _to RemoveFilter(filter); } \
  NS_SCRIPTABLE NS_IMETHOD SwapFilters(jsdIFilter *filter_a, jsdIFilter *filter_b) { return _to SwapFilters(filter_a, filter_b); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateFilters(jsdIFilterEnumerator *enumerator) { return _to EnumerateFilters(enumerator); } \
  NS_SCRIPTABLE NS_IMETHOD RefreshFilters(void) { return _to RefreshFilters(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearFilters(void) { return _to ClearFilters(); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateContexts(jsdIContextEnumerator *enumerator) { return _to EnumerateContexts(enumerator); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateScripts(jsdIScriptEnumerator *enumerator) { return _to EnumerateScripts(enumerator); } \
  NS_SCRIPTABLE NS_IMETHOD ClearAllBreakpoints(void) { return _to ClearAllBreakpoints(); } \
  NS_SCRIPTABLE NS_IMETHOD WrapValue(jsdIValue **_retval NS_OUTPARAM) { return _to WrapValue(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnterNestedEventLoop(jsdINestCallback *callback, PRUint32 *_retval NS_OUTPARAM) { return _to EnterNestedEventLoop(callback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExitNestedEventLoop(PRUint32 *_retval NS_OUTPARAM) { return _to ExitNestedEventLoop(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD DumpHeap(const char *fileName) { return _to DumpHeap(fileName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDIDEBUGGERSERVICE(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDContext(aJSDContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorHook(jsdIErrorHook * *aErrorHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorHook(aErrorHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetErrorHook(jsdIErrorHook * aErrorHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetErrorHook(aErrorHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetScriptHook(jsdIScriptHook * *aScriptHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptHook(aScriptHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetScriptHook(jsdIScriptHook * aScriptHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScriptHook(aScriptHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetBreakpointHook(jsdIExecutionHook * *aBreakpointHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBreakpointHook(aBreakpointHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetBreakpointHook(jsdIExecutionHook * aBreakpointHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBreakpointHook(aBreakpointHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetDebuggerHook(jsdIExecutionHook * *aDebuggerHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDebuggerHook(aDebuggerHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetDebuggerHook(jsdIExecutionHook * aDebuggerHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDebuggerHook(aDebuggerHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetDebugHook(jsdIExecutionHook * *aDebugHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDebugHook(aDebugHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetDebugHook(jsdIExecutionHook * aDebugHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDebugHook(aDebugHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetInterruptHook(jsdIExecutionHook * *aInterruptHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterruptHook(aInterruptHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetInterruptHook(jsdIExecutionHook * aInterruptHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInterruptHook(aInterruptHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetThrowHook(jsdIExecutionHook * *aThrowHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThrowHook(aThrowHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetThrowHook(jsdIExecutionHook * aThrowHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetThrowHook(aThrowHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetTopLevelHook(jsdICallHook * *aTopLevelHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTopLevelHook(aTopLevelHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetTopLevelHook(jsdICallHook * aTopLevelHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTopLevelHook(aTopLevelHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionHook(jsdICallHook * *aFunctionHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFunctionHook(aFunctionHook); } \
  NS_SCRIPTABLE NS_IMETHOD SetFunctionHook(jsdICallHook * aFunctionHook) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFunctionHook(aFunctionHook); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationMajor(PRUint32 *aImplementationMajor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImplementationMajor(aImplementationMajor); } \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationMinor(PRUint32 *aImplementationMinor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImplementationMinor(aImplementationMinor); } \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationString(char * *aImplementationString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImplementationString(aImplementationString); } \
  NS_SCRIPTABLE NS_IMETHOD GetInitAtStartup(PRBool *aInitAtStartup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInitAtStartup(aInitAtStartup); } \
  NS_SCRIPTABLE NS_IMETHOD SetInitAtStartup(PRBool aInitAtStartup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInitAtStartup(aInitAtStartup); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsOn(PRBool *aIsOn) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsOn(aIsOn); } \
  NS_SCRIPTABLE NS_IMETHOD On(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->On(); } \
  NS_IMETHOD OnForRuntime(JSRuntime * rt) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnForRuntime(rt); } \
  NS_SCRIPTABLE NS_IMETHOD Off(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Off(); } \
  NS_SCRIPTABLE NS_IMETHOD GetPauseDepth(PRUint32 *aPauseDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPauseDepth(aPauseDepth); } \
  NS_SCRIPTABLE NS_IMETHOD Pause(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Pause(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD UnPause(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnPause(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GC(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GC(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearProfileData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearProfileData(); } \
  NS_SCRIPTABLE NS_IMETHOD InsertFilter(jsdIFilter *filter, jsdIFilter *after) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertFilter(filter, after); } \
  NS_SCRIPTABLE NS_IMETHOD AppendFilter(jsdIFilter *filter) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendFilter(filter); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFilter(jsdIFilter *filter) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFilter(filter); } \
  NS_SCRIPTABLE NS_IMETHOD SwapFilters(jsdIFilter *filter_a, jsdIFilter *filter_b) { return !_to ? NS_ERROR_NULL_POINTER : _to->SwapFilters(filter_a, filter_b); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateFilters(jsdIFilterEnumerator *enumerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateFilters(enumerator); } \
  NS_SCRIPTABLE NS_IMETHOD RefreshFilters(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshFilters(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearFilters(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearFilters(); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateContexts(jsdIContextEnumerator *enumerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateContexts(enumerator); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateScripts(jsdIScriptEnumerator *enumerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateScripts(enumerator); } \
  NS_SCRIPTABLE NS_IMETHOD ClearAllBreakpoints(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearAllBreakpoints(); } \
  NS_SCRIPTABLE NS_IMETHOD WrapValue(jsdIValue **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapValue(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnterNestedEventLoop(jsdINestCallback *callback, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnterNestedEventLoop(callback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExitNestedEventLoop(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExitNestedEventLoop(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD DumpHeap(const char *fileName) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpHeap(fileName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIDebuggerService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDIDEBUGGERSERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIDebuggerService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] readonly attribute JSDContext JSDContext; */
NS_IMETHODIMP _MYCLASS_::GetJSDContext(JSDContext * *aJSDContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsdIErrorHook errorHook; */
NS_IMETHODIMP _MYCLASS_::GetErrorHook(jsdIErrorHook * *aErrorHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetErrorHook(jsdIErrorHook * aErrorHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsdIScriptHook scriptHook; */
NS_IMETHODIMP _MYCLASS_::GetScriptHook(jsdIScriptHook * *aScriptHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetScriptHook(jsdIScriptHook * aScriptHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsdIExecutionHook breakpointHook; */
NS_IMETHODIMP _MYCLASS_::GetBreakpointHook(jsdIExecutionHook * *aBreakpointHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetBreakpointHook(jsdIExecutionHook * aBreakpointHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsdIExecutionHook debuggerHook; */
NS_IMETHODIMP _MYCLASS_::GetDebuggerHook(jsdIExecutionHook * *aDebuggerHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetDebuggerHook(jsdIExecutionHook * aDebuggerHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsdIExecutionHook debugHook; */
NS_IMETHODIMP _MYCLASS_::GetDebugHook(jsdIExecutionHook * *aDebugHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetDebugHook(jsdIExecutionHook * aDebugHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsdIExecutionHook interruptHook; */
NS_IMETHODIMP _MYCLASS_::GetInterruptHook(jsdIExecutionHook * *aInterruptHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetInterruptHook(jsdIExecutionHook * aInterruptHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsdIExecutionHook throwHook; */
NS_IMETHODIMP _MYCLASS_::GetThrowHook(jsdIExecutionHook * *aThrowHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetThrowHook(jsdIExecutionHook * aThrowHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsdICallHook topLevelHook; */
NS_IMETHODIMP _MYCLASS_::GetTopLevelHook(jsdICallHook * *aTopLevelHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetTopLevelHook(jsdICallHook * aTopLevelHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsdICallHook functionHook; */
NS_IMETHODIMP _MYCLASS_::GetFunctionHook(jsdICallHook * *aFunctionHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetFunctionHook(jsdICallHook * aFunctionHook)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long flags; */
NS_IMETHODIMP _MYCLASS_::GetFlags(PRUint32 *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetFlags(PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long implementationMajor; */
NS_IMETHODIMP _MYCLASS_::GetImplementationMajor(PRUint32 *aImplementationMajor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long implementationMinor; */
NS_IMETHODIMP _MYCLASS_::GetImplementationMinor(PRUint32 *aImplementationMinor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string implementationString; */
NS_IMETHODIMP _MYCLASS_::GetImplementationString(char * *aImplementationString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean initAtStartup; */
NS_IMETHODIMP _MYCLASS_::GetInitAtStartup(PRBool *aInitAtStartup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetInitAtStartup(PRBool aInitAtStartup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isOn; */
NS_IMETHODIMP _MYCLASS_::GetIsOn(PRBool *aIsOn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void on (); */
NS_IMETHODIMP _MYCLASS_::On()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void onForRuntime (in JSRuntime rt); */
NS_IMETHODIMP _MYCLASS_::OnForRuntime(JSRuntime * rt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void off (); */
NS_IMETHODIMP _MYCLASS_::Off()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long pauseDepth; */
NS_IMETHODIMP _MYCLASS_::GetPauseDepth(PRUint32 *aPauseDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long pause (); */
NS_IMETHODIMP _MYCLASS_::Pause(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long unPause (); */
NS_IMETHODIMP _MYCLASS_::UnPause(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GC (); */
NS_IMETHODIMP _MYCLASS_::GC()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearProfileData (); */
NS_IMETHODIMP _MYCLASS_::ClearProfileData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertFilter (in jsdIFilter filter, in jsdIFilter after); */
NS_IMETHODIMP _MYCLASS_::InsertFilter(jsdIFilter *filter, jsdIFilter *after)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendFilter (in jsdIFilter filter); */
NS_IMETHODIMP _MYCLASS_::AppendFilter(jsdIFilter *filter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFilter (in jsdIFilter filter); */
NS_IMETHODIMP _MYCLASS_::RemoveFilter(jsdIFilter *filter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void swapFilters (in jsdIFilter filter_a, in jsdIFilter filter_b); */
NS_IMETHODIMP _MYCLASS_::SwapFilters(jsdIFilter *filter_a, jsdIFilter *filter_b)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enumerateFilters (in jsdIFilterEnumerator enumerator); */
NS_IMETHODIMP _MYCLASS_::EnumerateFilters(jsdIFilterEnumerator *enumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshFilters (); */
NS_IMETHODIMP _MYCLASS_::RefreshFilters()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearFilters (); */
NS_IMETHODIMP _MYCLASS_::ClearFilters()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enumerateContexts (in jsdIContextEnumerator enumerator); */
NS_IMETHODIMP _MYCLASS_::EnumerateContexts(jsdIContextEnumerator *enumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enumerateScripts (in jsdIScriptEnumerator enumerator); */
NS_IMETHODIMP _MYCLASS_::EnumerateScripts(jsdIScriptEnumerator *enumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearAllBreakpoints (); */
NS_IMETHODIMP _MYCLASS_::ClearAllBreakpoints()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsdIValue wrapValue (); */
NS_IMETHODIMP _MYCLASS_::WrapValue(jsdIValue **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long enterNestedEventLoop (in jsdINestCallback callback); */
NS_IMETHODIMP _MYCLASS_::EnterNestedEventLoop(jsdINestCallback *callback, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long exitNestedEventLoop (); */
NS_IMETHODIMP _MYCLASS_::ExitNestedEventLoop(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpHeap (in string fileName); */
NS_IMETHODIMP _MYCLASS_::DumpHeap(const char *fileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIFilter */
#define JSDIFILTER_IID_STR "05593438-1b83-4517-864f-3cea3d37a266"

#define JSDIFILTER_IID \
  {0x05593438, 0x1b83, 0x4517, \
    { 0x86, 0x4f, 0x3c, 0xea, 0x3d, 0x37, 0xa2, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDIFILTER_IID)

  /**
 * Object representing a pattern of global object and/or url the debugger should
 * ignore.  The debugger service itself will not modify properties of these
 * objects.
 */
/**
     * These two bytes of the flags attribute are reserved for interpretation
     * by the jsdService implementation.  You can do what you like with the
     * remaining flags.
     */
  enum { FLAG_RESERVED_MASK = 255U };

  /**
     * Filters without this flag set are ignored.
     */
  enum { FLAG_ENABLED = 1U };

  /**
     * Filters with this flag set are "pass" filters, they allow matching hooks
     * to continue.  Filters without this flag block matching hooks.
     */
  enum { FLAG_PASS = 2U };

  /**
     * FLAG_* values from above, OR'd together.
     */
  /* attribute unsigned long flags; */
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) = 0;

  /**
     * An nsISupports version of the global object to be filtered.  A null glob
     * matches all hooks.  This attribute must be QI'able to the
     * (non-scriptable) nsIScriptGlobalObject interface.
     *
     * The jsdIService caches this value internally, so if it changes you must
     * swap the filter with itself using jsdIService::swapFilters.
     */
  /* attribute nsISupports globalObject; */
  NS_SCRIPTABLE NS_IMETHOD GetGlobalObject(nsISupports * *aGlobalObject) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetGlobalObject(nsISupports * aGlobalObject) = 0;

  /**
     * String representing the url pattern to be filtered.  Supports limited
     * glob matching, at the beginning and end of the pattern only.  For example,
     * "chrome://venkman*" filters all urls that start with chrome/venkman,
     * "*.cgi" filters all cgi's, and "http://myserver/utils.js" filters only
     * the utils.js file on "myserver".   A null urlPattern matches all urls.
     *
     * The jsdIService caches this value internally, to if it changes you must
     * swap the filter with itself using jsdIService::swapFilters.
     */
  /* attribute string urlPattern; */
  NS_SCRIPTABLE NS_IMETHOD GetUrlPattern(char * *aUrlPattern) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUrlPattern(const char * aUrlPattern) = 0;

  /**
     * Line number for the start of this filter.  Line numbers are one based.
     * Assigning a 0 to this attribute will tell the debugger to ignore the
     * entire file.
     */
  /* attribute unsigned long startLine; */
  NS_SCRIPTABLE NS_IMETHOD GetStartLine(PRUint32 *aStartLine) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStartLine(PRUint32 aStartLine) = 0;

  /**
     * Line number for the end of this filter.  Line numbers are one based.
     * Assigning a 0 to this attribute will tell the debugger to ignore from
     * |startLine| to the end of the file.
     */
  /* attribute unsigned long endLine; */
  NS_SCRIPTABLE NS_IMETHOD GetEndLine(PRUint32 *aEndLine) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEndLine(PRUint32 aEndLine) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIFilter, JSDIFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDIFILTER \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalObject(nsISupports * *aGlobalObject); \
  NS_SCRIPTABLE NS_IMETHOD SetGlobalObject(nsISupports * aGlobalObject); \
  NS_SCRIPTABLE NS_IMETHOD GetUrlPattern(char * *aUrlPattern); \
  NS_SCRIPTABLE NS_IMETHOD SetUrlPattern(const char * aUrlPattern); \
  NS_SCRIPTABLE NS_IMETHOD GetStartLine(PRUint32 *aStartLine); \
  NS_SCRIPTABLE NS_IMETHOD SetStartLine(PRUint32 aStartLine); \
  NS_SCRIPTABLE NS_IMETHOD GetEndLine(PRUint32 *aEndLine); \
  NS_SCRIPTABLE NS_IMETHOD SetEndLine(PRUint32 aEndLine); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDIFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return _to GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return _to SetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalObject(nsISupports * *aGlobalObject) { return _to GetGlobalObject(aGlobalObject); } \
  NS_SCRIPTABLE NS_IMETHOD SetGlobalObject(nsISupports * aGlobalObject) { return _to SetGlobalObject(aGlobalObject); } \
  NS_SCRIPTABLE NS_IMETHOD GetUrlPattern(char * *aUrlPattern) { return _to GetUrlPattern(aUrlPattern); } \
  NS_SCRIPTABLE NS_IMETHOD SetUrlPattern(const char * aUrlPattern) { return _to SetUrlPattern(aUrlPattern); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartLine(PRUint32 *aStartLine) { return _to GetStartLine(aStartLine); } \
  NS_SCRIPTABLE NS_IMETHOD SetStartLine(PRUint32 aStartLine) { return _to SetStartLine(aStartLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndLine(PRUint32 *aEndLine) { return _to GetEndLine(aEndLine); } \
  NS_SCRIPTABLE NS_IMETHOD SetEndLine(PRUint32 aEndLine) { return _to SetEndLine(aEndLine); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDIFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalObject(nsISupports * *aGlobalObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalObject(aGlobalObject); } \
  NS_SCRIPTABLE NS_IMETHOD SetGlobalObject(nsISupports * aGlobalObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGlobalObject(aGlobalObject); } \
  NS_SCRIPTABLE NS_IMETHOD GetUrlPattern(char * *aUrlPattern) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrlPattern(aUrlPattern); } \
  NS_SCRIPTABLE NS_IMETHOD SetUrlPattern(const char * aUrlPattern) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUrlPattern(aUrlPattern); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartLine(PRUint32 *aStartLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartLine(aStartLine); } \
  NS_SCRIPTABLE NS_IMETHOD SetStartLine(PRUint32 aStartLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartLine(aStartLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndLine(PRUint32 *aEndLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndLine(aEndLine); } \
  NS_SCRIPTABLE NS_IMETHOD SetEndLine(PRUint32 aEndLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndLine(aEndLine); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDIFILTER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIFilter)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* attribute unsigned long flags; */
NS_IMETHODIMP _MYCLASS_::GetFlags(PRUint32 *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetFlags(PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports globalObject; */
NS_IMETHODIMP _MYCLASS_::GetGlobalObject(nsISupports * *aGlobalObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetGlobalObject(nsISupports * aGlobalObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string urlPattern; */
NS_IMETHODIMP _MYCLASS_::GetUrlPattern(char * *aUrlPattern)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetUrlPattern(const char * aUrlPattern)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long startLine; */
NS_IMETHODIMP _MYCLASS_::GetStartLine(PRUint32 *aStartLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetStartLine(PRUint32 aStartLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long endLine; */
NS_IMETHODIMP _MYCLASS_::GetEndLine(PRUint32 *aEndLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetEndLine(PRUint32 aEndLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdINestCallback */
#define JSDINESTCALLBACK_IID_STR "88bea60f-9b5d-4b39-b08b-1c3a278782c6"

#define JSDINESTCALLBACK_IID \
  {0x88bea60f, 0x9b5d, 0x4b39, \
    { 0xb0, 0x8b, 0x1c, 0x3a, 0x27, 0x87, 0x82, 0xc6 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdINestCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDINESTCALLBACK_IID)

  /**
 * Pass an instance of one of these to jsdIDebuggerService::enterNestedEventLoop.
 */
/**
     * This method will be called after pre-nesting work has completed, such
     * as pushing the js context and network event queue, but before the new
     * event loop starts.
     */
  /* void onNest (); */
  NS_SCRIPTABLE NS_IMETHOD OnNest(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdINestCallback, JSDINESTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDINESTCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD OnNest(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDINESTCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnNest(void) { return _to OnNest(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDINESTCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnNest(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnNest(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdINestCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDINESTCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdINestCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onNest (); */
NS_IMETHODIMP _MYCLASS_::OnNest()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIFilterEnumerator */
#define JSDIFILTERENUMERATOR_IID_STR "54382875-ed12-4f90-9a63-1f0498d0a3f2"

#define JSDIFILTERENUMERATOR_IID \
  {0x54382875, 0xed12, 0x4f90, \
    { 0x9a, 0x63, 0x1f, 0x04, 0x98, 0xd0, 0xa3, 0xf2 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIFilterEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDIFILTERENUMERATOR_IID)

  /**
 * Pass an instance of one of these to jsdIDebuggerService::enumerateFilters.
 */
/**
     * The enumerateFilter method will be called once for every filter the
     * debugger knows about.
     */
  /* void enumerateFilter (in jsdIFilter filter); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateFilter(jsdIFilter *filter) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIFilterEnumerator, JSDIFILTERENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDIFILTERENUMERATOR \
  NS_SCRIPTABLE NS_IMETHOD EnumerateFilter(jsdIFilter *filter); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDIFILTERENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateFilter(jsdIFilter *filter) { return _to EnumerateFilter(filter); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDIFILTERENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateFilter(jsdIFilter *filter) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateFilter(filter); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIFilterEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDIFILTERENUMERATOR

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIFilterEnumerator)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void enumerateFilter (in jsdIFilter filter); */
NS_IMETHODIMP _MYCLASS_::EnumerateFilter(jsdIFilter *filter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIScriptEnumerator */
#define JSDISCRIPTENUMERATOR_IID_STR "4c2f706e-1dd2-11b2-9ebc-85a06e948830"

#define JSDISCRIPTENUMERATOR_IID \
  {0x4c2f706e, 0x1dd2, 0x11b2, \
    { 0x9e, 0xbc, 0x85, 0xa0, 0x6e, 0x94, 0x88, 0x30 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIScriptEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDISCRIPTENUMERATOR_IID)

  /**
 * Pass an instance of one of these to jsdIDebuggerService::enumerateScripts.
 */
/**
     * The enumerateScript method will be called once for every script the
     * debugger knows about.
     */
  /* void enumerateScript (in jsdIScript script); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateScript(jsdIScript *script) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIScriptEnumerator, JSDISCRIPTENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDISCRIPTENUMERATOR \
  NS_SCRIPTABLE NS_IMETHOD EnumerateScript(jsdIScript *script); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDISCRIPTENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateScript(jsdIScript *script) { return _to EnumerateScript(script); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDISCRIPTENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateScript(jsdIScript *script) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateScript(script); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIScriptEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDISCRIPTENUMERATOR

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIScriptEnumerator)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void enumerateScript (in jsdIScript script); */
NS_IMETHODIMP _MYCLASS_::EnumerateScript(jsdIScript *script)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIContextEnumerator */
#define JSDICONTEXTENUMERATOR_IID_STR "912e342a-1dd2-11b2-b09f-cf3af38c15f0"

#define JSDICONTEXTENUMERATOR_IID \
  {0x912e342a, 0x1dd2, 0x11b2, \
    { 0xb0, 0x9f, 0xcf, 0x3a, 0xf3, 0x8c, 0x15, 0xf0 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIContextEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDICONTEXTENUMERATOR_IID)

  /**
 * Pass an instance of one of these to jsdIDebuggerService::enumerateContexts.
 */
/**
     * The enumerateContext method will be called once for every context
     * currently in use.
     */
  /* void enumerateContext (in jsdIContext executionContext); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateContext(jsdIContext *executionContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIContextEnumerator, JSDICONTEXTENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDICONTEXTENUMERATOR \
  NS_SCRIPTABLE NS_IMETHOD EnumerateContext(jsdIContext *executionContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDICONTEXTENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateContext(jsdIContext *executionContext) { return _to EnumerateContext(executionContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDICONTEXTENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateContext(jsdIContext *executionContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateContext(executionContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIContextEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDICONTEXTENUMERATOR

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIContextEnumerator)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void enumerateContext (in jsdIContext executionContext); */
NS_IMETHODIMP _MYCLASS_::EnumerateContext(jsdIContext *executionContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIScriptHook */
#define JSDISCRIPTHOOK_IID_STR "ae89a7e2-1dd1-11b2-8c2f-af82086291a5"

#define JSDISCRIPTHOOK_IID \
  {0xae89a7e2, 0x1dd1, 0x11b2, \
    { 0x8c, 0x2f, 0xaf, 0x82, 0x08, 0x62, 0x91, 0xa5 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIScriptHook : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDISCRIPTHOOK_IID)

  /**
 * Set jsdIDebuggerService::scriptHook to an instance of one of these.
 */
/**
     * Called when scripts are created.
     */
  /* void onScriptCreated (in jsdIScript script); */
  NS_SCRIPTABLE NS_IMETHOD OnScriptCreated(jsdIScript *script) = 0;

  /**
     * Called when the JavaScript engine destroys a script.  The jsdIScript
     * object passed in will already be invalidated.
     */
  /* void onScriptDestroyed (in jsdIScript script); */
  NS_SCRIPTABLE NS_IMETHOD OnScriptDestroyed(jsdIScript *script) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIScriptHook, JSDISCRIPTHOOK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDISCRIPTHOOK \
  NS_SCRIPTABLE NS_IMETHOD OnScriptCreated(jsdIScript *script); \
  NS_SCRIPTABLE NS_IMETHOD OnScriptDestroyed(jsdIScript *script); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDISCRIPTHOOK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnScriptCreated(jsdIScript *script) { return _to OnScriptCreated(script); } \
  NS_SCRIPTABLE NS_IMETHOD OnScriptDestroyed(jsdIScript *script) { return _to OnScriptDestroyed(script); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDISCRIPTHOOK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnScriptCreated(jsdIScript *script) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnScriptCreated(script); } \
  NS_SCRIPTABLE NS_IMETHOD OnScriptDestroyed(jsdIScript *script) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnScriptDestroyed(script); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIScriptHook
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDISCRIPTHOOK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIScriptHook)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onScriptCreated (in jsdIScript script); */
NS_IMETHODIMP _MYCLASS_::OnScriptCreated(jsdIScript *script)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onScriptDestroyed (in jsdIScript script); */
NS_IMETHODIMP _MYCLASS_::OnScriptDestroyed(jsdIScript *script)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdICallHook */
#define JSDICALLHOOK_IID_STR "f102caf6-1dd1-11b2-bd43-c1dbacb95a98"

#define JSDICALLHOOK_IID \
  {0xf102caf6, 0x1dd1, 0x11b2, \
    { 0xbd, 0x43, 0xc1, 0xdb, 0xac, 0xb9, 0x5a, 0x98 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdICallHook : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDICALLHOOK_IID)

  /**
 * Hook instances of this interface up to the
 * jsdIDebuggerService::functionHook and toplevelHook properties.
 */
/**
     * TYPE_* values must be kept in sync with the JSD_HOOK_* #defines
     * in jsdebug.h.
     */
/**
     * Toplevel script is starting.
     */
  enum { TYPE_TOPLEVEL_START = 0U };

  /**
     * Toplevel script has completed.
     */
  enum { TYPE_TOPLEVEL_END = 1U };

  /**
     * Function is being called.
     */
  enum { TYPE_FUNCTION_CALL = 2U };

  /**
     * Function is returning.
     */
  enum { TYPE_FUNCTION_RETURN = 3U };

  /**
     * Called before the JavaScript engine executes a top level script or calls
     * a function.
     */
  /* void onCall (in jsdIStackFrame frame, in unsigned long type); */
  NS_SCRIPTABLE NS_IMETHOD OnCall(jsdIStackFrame *frame, PRUint32 type) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdICallHook, JSDICALLHOOK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDICALLHOOK \
  NS_SCRIPTABLE NS_IMETHOD OnCall(jsdIStackFrame *frame, PRUint32 type); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDICALLHOOK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnCall(jsdIStackFrame *frame, PRUint32 type) { return _to OnCall(frame, type); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDICALLHOOK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnCall(jsdIStackFrame *frame, PRUint32 type) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCall(frame, type); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdICallHook
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDICALLHOOK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdICallHook)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onCall (in jsdIStackFrame frame, in unsigned long type); */
NS_IMETHODIMP _MYCLASS_::OnCall(jsdIStackFrame *frame, PRUint32 type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIErrorHook */
#define JSDIERRORHOOK_IID_STR "b7dd3c1c-1dd1-11b2-83eb-8a857d199e0f"

#define JSDIERRORHOOK_IID \
  {0xb7dd3c1c, 0x1dd1, 0x11b2, \
    { 0x83, 0xeb, 0x8a, 0x85, 0x7d, 0x19, 0x9e, 0x0f }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIErrorHook : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDIERRORHOOK_IID)

  /**
     * REPORT_* values must be kept in sync with JSREPORT_* #defines in
     * jsapi.h
     */
/**
     * Report is an error.
     */
  enum { REPORT_ERROR = 0U };

  /**
     * Report is only a warning.
     */
  enum { REPORT_WARNING = 1U };

  /**
     * Report represents an uncaught exception.
     */
  enum { REPORT_EXCEPTION = 2U };

  /**
     * Report is due to strict mode.
     */
  enum { REPORT_STRICT = 4U };

  /**
     * Called when the JavaScript engine encounters an error.  Return |true|
     * to pass the error along, |false| to invoke the debugHook.
     */
  /* boolean onError (in string message, in string fileName, in unsigned long line, in unsigned long pos, in unsigned long flags, in unsigned long errnum, in jsdIValue exc); */
  NS_SCRIPTABLE NS_IMETHOD OnError(const char *message, const char *fileName, PRUint32 line, PRUint32 pos, PRUint32 flags, PRUint32 errnum, jsdIValue *exc, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIErrorHook, JSDIERRORHOOK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDIERRORHOOK \
  NS_SCRIPTABLE NS_IMETHOD OnError(const char *message, const char *fileName, PRUint32 line, PRUint32 pos, PRUint32 flags, PRUint32 errnum, jsdIValue *exc, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDIERRORHOOK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnError(const char *message, const char *fileName, PRUint32 line, PRUint32 pos, PRUint32 flags, PRUint32 errnum, jsdIValue *exc, PRBool *_retval NS_OUTPARAM) { return _to OnError(message, fileName, line, pos, flags, errnum, exc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDIERRORHOOK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnError(const char *message, const char *fileName, PRUint32 line, PRUint32 pos, PRUint32 flags, PRUint32 errnum, jsdIValue *exc, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(message, fileName, line, pos, flags, errnum, exc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIErrorHook
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDIERRORHOOK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIErrorHook)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean onError (in string message, in string fileName, in unsigned long line, in unsigned long pos, in unsigned long flags, in unsigned long errnum, in jsdIValue exc); */
NS_IMETHODIMP _MYCLASS_::OnError(const char *message, const char *fileName, PRUint32 line, PRUint32 pos, PRUint32 flags, PRUint32 errnum, jsdIValue *exc, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIExecutionHook */
#define JSDIEXECUTIONHOOK_IID_STR "9a7b6ad0-1dd1-11b2-a789-fcfae96356a2"

#define JSDIEXECUTIONHOOK_IID \
  {0x9a7b6ad0, 0x1dd1, 0x11b2, \
    { 0xa7, 0x89, 0xfc, 0xfa, 0xe9, 0x63, 0x56, 0xa2 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIExecutionHook : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDIEXECUTIONHOOK_IID)

  /**
 * Hook instances of this interface up to the
 * jsdIDebuggerService::breakpointHook, debuggerHook, errorHook, interruptHook,
 * and throwHook properties.
 */
/**
     * TYPE_* values must be kept in sync with JSD_HOOK_* #defines in jsdebug.h.
     */
/**
     * Execution stopped because we're in single step mode.
     */
  enum { TYPE_INTERRUPTED = 0U };

  /**
     * Execution stopped by a trap instruction (i.e. breakoint.)
     */
  enum { TYPE_BREAKPOINT = 1U };

  /**
     * Error handler returned an "invoke debugger" value.
     */
  enum { TYPE_DEBUG_REQUESTED = 2U };

  /**
     * Debugger keyword encountered.
     */
  enum { TYPE_DEBUGGER_KEYWORD = 3U };

  /**
     * Exception was thrown.
     */
  enum { TYPE_THROW = 4U };

  /**
     * RETURN_* values must be kept in sync with JSD_HOOK_RETURN_* #defines in
     * jsdebug.h.
     */
/**
     * Indicates unrecoverable error processing the hook.  This will cause
     * the script being executed to be aborted without raising a JavaScript
     * exception.
     */
  enum { RETURN_HOOK_ERROR = 0U };

  /**
     * Continue processing normally.  This is the "do nothing special" return
     * value for all hook types *except* TYPE_THROW.  Returning RETURN_CONTINUE
     * from TYPE_THROW cause the exception to be ignored.  Return
     * RETURN_CONTINUE_THROW to continue exception processing from TYPE_THROW
     * hooks.
     */
  enum { RETURN_CONTINUE = 1U };

  /**
     * Same effect as RETURN_HOOK_ERROR.
     */
  enum { RETURN_ABORT = 2U };

  /**
     * Return the value of the |val| parameter.
     */
  enum { RETURN_RET_WITH_VAL = 3U };

  /**
     * Throw the value of the |val| parameter.
     */
  enum { RETURN_THROW_WITH_VAL = 4U };

  /**
     * Continue the current throw.
     */
  enum { RETURN_CONTINUE_THROW = 5U };

  /**
     * @param frame A jsdIStackFrame object representing the bottom stack frame.
     * @param type  One of the jsdIExecutionHook::TYPE_ constants.
     * @param val   in  - Current exception (if any) when this method is called.
     *              out - If you return RETURN_THROW_WITH_VAL, value to be
     *                    thrown.
     *                    If you return RETURN_RET_WITH_VAL, value to return.
     *                    All other return values, not significant.
     * @retval      One of the jsdIExecutionHook::RETURN_* constants.
     */
  /* unsigned long onExecute (in jsdIStackFrame frame, in unsigned long type, inout jsdIValue val); */
  NS_SCRIPTABLE NS_IMETHOD OnExecute(jsdIStackFrame *frame, PRUint32 type, jsdIValue **val NS_INOUTPARAM, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIExecutionHook, JSDIEXECUTIONHOOK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDIEXECUTIONHOOK \
  NS_SCRIPTABLE NS_IMETHOD OnExecute(jsdIStackFrame *frame, PRUint32 type, jsdIValue **val NS_INOUTPARAM, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDIEXECUTIONHOOK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnExecute(jsdIStackFrame *frame, PRUint32 type, jsdIValue **val NS_INOUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return _to OnExecute(frame, type, val, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDIEXECUTIONHOOK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnExecute(jsdIStackFrame *frame, PRUint32 type, jsdIValue **val NS_INOUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnExecute(frame, type, val, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIExecutionHook
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDIEXECUTIONHOOK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIExecutionHook)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* unsigned long onExecute (in jsdIStackFrame frame, in unsigned long type, inout jsdIValue val); */
NS_IMETHODIMP _MYCLASS_::OnExecute(jsdIStackFrame *frame, PRUint32 type, jsdIValue **val NS_INOUTPARAM, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIEphemeral */
#define JSDIEPHEMERAL_IID_STR "46f1e23e-1dd2-11b2-9ceb-8285f2e95e69"

#define JSDIEPHEMERAL_IID \
  {0x46f1e23e, 0x1dd2, 0x11b2, \
    { 0x9c, 0xeb, 0x82, 0x85, 0xf2, 0xe9, 0x5e, 0x69 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIEphemeral : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDIEPHEMERAL_IID)

  /**
 * Objects which inherit this interface may go away, with (jsdIScript) or
 * without (all others) notification.  These objects are generally wrappers
 * around JSD structures that go away when you call jsdService::Off().
 */
/**
     * |true| if this object is still valid.  If not, many or all of the methods
     * and/or properties of the inheritor may no longer be callable.
     */
  /* readonly attribute boolean isValid; */
  NS_SCRIPTABLE NS_IMETHOD GetIsValid(PRBool *aIsValid) = 0;

  /**
     * Mark this instance as invalid.
     */
  /* [noscript] void invalidate (); */
  NS_IMETHOD Invalidate(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIEphemeral, JSDIEPHEMERAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDIEPHEMERAL \
  NS_SCRIPTABLE NS_IMETHOD GetIsValid(PRBool *aIsValid); \
  NS_IMETHOD Invalidate(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDIEPHEMERAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsValid(PRBool *aIsValid) { return _to GetIsValid(aIsValid); } \
  NS_IMETHOD Invalidate(void) { return _to Invalidate(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDIEPHEMERAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsValid(PRBool *aIsValid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsValid(aIsValid); } \
  NS_IMETHOD Invalidate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Invalidate(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIEphemeral
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDIEPHEMERAL

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIEphemeral)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute boolean isValid; */
NS_IMETHODIMP _MYCLASS_::GetIsValid(PRBool *aIsValid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void invalidate (); */
NS_IMETHODIMP _MYCLASS_::Invalidate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIContext */
#define JSDICONTEXT_IID_STR "a2dd25a4-1dd1-11b2-bda6-ed525acd4c35"

#define JSDICONTEXT_IID \
  {0xa2dd25a4, 0x1dd1, 0x11b2, \
    { 0xbd, 0xa6, 0xed, 0x52, 0x5a, 0xcd, 0x4c, 0x35 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIContext : public jsdIEphemeral {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDICONTEXT_IID)

  /**
 * Context object.  Only context's which are also nsISupports objects can be
 * reflected by this interface.
 */
  /* [noscript] readonly attribute JSContext JSContext; */
  NS_IMETHOD GetJSContext(JSContext * *aJSContext) = 0;

  /**
     * OPT_* values must be kept in sync with JSOPTION_* #defines in jsapi.h.
     */
/**
     * Strict mode is on.
     */
  enum { OPT_STRICT = 1 };

  /**
     * Warnings reported as errors.
     */
  enum { OPT_WERR = 2 };

  /**
     * Makes eval() use the last object on its 'obj' param's scope chain as the
     * ECMA 'variables object'.
     */
  enum { OPT_VAROBJFIX = 4 };

  /**
     * Private data for this object is an nsISupports object.  Attempting to
     * alter this bit will result in an NS_ERROR_ILLEGAL_VALUE.
     */
  enum { OPT_ISUPPORTS = 8 };

  /**
     * OPT_* values above, OR'd together.
     */
  /* attribute unsigned long options; */
  NS_SCRIPTABLE NS_IMETHOD GetOptions(PRUint32 *aOptions) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOptions(PRUint32 aOptions) = 0;

  /**
     * Last version set on this context.
     * Scripts typically select this with the "language" attribute.
     * See the VERSION_* consts on jsdIDebuggerService.
     */
  /* attribute long version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(PRInt32 *aVersion) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetVersion(PRInt32 aVersion) = 0;

  /**
     * Unique tag among all valid jsdIContext objects, useful as a hash key.
     */
  /* readonly attribute unsigned long tag; */
  NS_SCRIPTABLE NS_IMETHOD GetTag(PRUint32 *aTag) = 0;

  /**
     * Private data for this context, if it is an nsISupports, |null| otherwise.
     */
  /* readonly attribute nsISupports privateData; */
  NS_SCRIPTABLE NS_IMETHOD GetPrivateData(nsISupports * *aPrivateData) = 0;

  /**
     * Retrieve the underlying context wrapped by this jsdIContext.
     */
  /* readonly attribute nsISupports wrappedContext; */
  NS_SCRIPTABLE NS_IMETHOD GetWrappedContext(nsISupports * *aWrappedContext) = 0;

  /**
     * Top of the scope chain for this context.
     */
  /* readonly attribute jsdIValue globalObject; */
  NS_SCRIPTABLE NS_IMETHOD GetGlobalObject(jsdIValue * *aGlobalObject) = 0;

  /**
     * |true| if this context should be allowed to run scripts, |false|
     * otherwise.  This attribute is only valid for contexts which implement
     * nsIScriptContext.  Setting or getting this attribute on any other
     * context will throw a NS_ERROR_NO_INTERFACE exception.
     */
  /* attribute boolean scriptsEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetScriptsEnabled(PRBool *aScriptsEnabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetScriptsEnabled(PRBool aScriptsEnabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIContext, JSDICONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDICONTEXT \
  NS_IMETHOD GetJSContext(JSContext * *aJSContext); \
  NS_SCRIPTABLE NS_IMETHOD GetOptions(PRUint32 *aOptions); \
  NS_SCRIPTABLE NS_IMETHOD SetOptions(PRUint32 aOptions); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(PRInt32 *aVersion); \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(PRInt32 aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetTag(PRUint32 *aTag); \
  NS_SCRIPTABLE NS_IMETHOD GetPrivateData(nsISupports * *aPrivateData); \
  NS_SCRIPTABLE NS_IMETHOD GetWrappedContext(nsISupports * *aWrappedContext); \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalObject(jsdIValue * *aGlobalObject); \
  NS_SCRIPTABLE NS_IMETHOD GetScriptsEnabled(PRBool *aScriptsEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetScriptsEnabled(PRBool aScriptsEnabled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDICONTEXT(_to) \
  NS_IMETHOD GetJSContext(JSContext * *aJSContext) { return _to GetJSContext(aJSContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetOptions(PRUint32 *aOptions) { return _to GetOptions(aOptions); } \
  NS_SCRIPTABLE NS_IMETHOD SetOptions(PRUint32 aOptions) { return _to SetOptions(aOptions); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(PRInt32 *aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(PRInt32 aVersion) { return _to SetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetTag(PRUint32 *aTag) { return _to GetTag(aTag); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrivateData(nsISupports * *aPrivateData) { return _to GetPrivateData(aPrivateData); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrappedContext(nsISupports * *aWrappedContext) { return _to GetWrappedContext(aWrappedContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalObject(jsdIValue * *aGlobalObject) { return _to GetGlobalObject(aGlobalObject); } \
  NS_SCRIPTABLE NS_IMETHOD GetScriptsEnabled(PRBool *aScriptsEnabled) { return _to GetScriptsEnabled(aScriptsEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetScriptsEnabled(PRBool aScriptsEnabled) { return _to SetScriptsEnabled(aScriptsEnabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDICONTEXT(_to) \
  NS_IMETHOD GetJSContext(JSContext * *aJSContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSContext(aJSContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetOptions(PRUint32 *aOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOptions(aOptions); } \
  NS_SCRIPTABLE NS_IMETHOD SetOptions(PRUint32 aOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOptions(aOptions); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(PRInt32 *aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(PRInt32 aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetTag(PRUint32 *aTag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTag(aTag); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrivateData(nsISupports * *aPrivateData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrivateData(aPrivateData); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrappedContext(nsISupports * *aWrappedContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedContext(aWrappedContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalObject(jsdIValue * *aGlobalObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalObject(aGlobalObject); } \
  NS_SCRIPTABLE NS_IMETHOD GetScriptsEnabled(PRBool *aScriptsEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptsEnabled(aScriptsEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetScriptsEnabled(PRBool aScriptsEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScriptsEnabled(aScriptsEnabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDICONTEXT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIContext)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] readonly attribute JSContext JSContext; */
NS_IMETHODIMP _MYCLASS_::GetJSContext(JSContext * *aJSContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long options; */
NS_IMETHODIMP _MYCLASS_::GetOptions(PRUint32 *aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOptions(PRUint32 aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long version; */
NS_IMETHODIMP _MYCLASS_::GetVersion(PRInt32 *aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetVersion(PRInt32 aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long tag; */
NS_IMETHODIMP _MYCLASS_::GetTag(PRUint32 *aTag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports privateData; */
NS_IMETHODIMP _MYCLASS_::GetPrivateData(nsISupports * *aPrivateData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports wrappedContext; */
NS_IMETHODIMP _MYCLASS_::GetWrappedContext(nsISupports * *aWrappedContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue globalObject; */
NS_IMETHODIMP _MYCLASS_::GetGlobalObject(jsdIValue * *aGlobalObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean scriptsEnabled; */
NS_IMETHODIMP _MYCLASS_::GetScriptsEnabled(PRBool *aScriptsEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetScriptsEnabled(PRBool aScriptsEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIStackFrame */
#define JSDISTACKFRAME_IID_STR "b6d50784-1dd1-11b2-a932-882246c6fe45"

#define JSDISTACKFRAME_IID \
  {0xb6d50784, 0x1dd1, 0x11b2, \
    { 0xa9, 0x32, 0x88, 0x22, 0x46, 0xc6, 0xfe, 0x45 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIStackFrame : public jsdIEphemeral {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDISTACKFRAME_IID)

  /**
 * Stack frame objects.  These are only valid inside the jsdIExecutionHook which
 * gave it to you.  After you return from that handler the bottom frame, and any
 * frame you found attached through it, are invalidated via the jsdIEphemeral
 * interface.  Once a jsdIStackFrame has been invalidated all method and
 * property accesses will throw a NS_ERROR_NOT_AVAILABLE exception.
 */
/** Internal use only. */
  /* [noscript] readonly attribute JSDContext JSDContext; */
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) = 0;

  /** Internal use only. */
  /* [noscript] readonly attribute JSDThreadState JSDThreadState; */
  NS_IMETHOD GetJSDThreadState(JSDThreadState * *aJSDThreadState) = 0;

  /** Internal use only. */
  /* [noscript] readonly attribute JSDStackFrameInfo JSDStackFrameInfo; */
  NS_IMETHOD GetJSDStackFrameInfo(JSDStackFrameInfo * *aJSDStackFrameInfo) = 0;

  /**
     * True if stack frame represents a native frame.
     */
  /* readonly attribute boolean isNative; */
  NS_SCRIPTABLE NS_IMETHOD GetIsNative(PRBool *aIsNative) = 0;

  /**
     * True if stack frame represents a frame created as a result of a debugger
     * evaluation.
     */
  /* readonly attribute boolean isDebugger; */
  NS_SCRIPTABLE NS_IMETHOD GetIsDebugger(PRBool *aIsDebugger) = 0;

  /**
     * True if stack frame is constructing a new object.
     */
  /* readonly attribute boolean isConstructing; */
  NS_SCRIPTABLE NS_IMETHOD GetIsConstructing(PRBool *aIsConstructing) = 0;

  /**
     * Link to the caller's stack frame.
     */
  /* readonly attribute jsdIStackFrame callingFrame; */
  NS_SCRIPTABLE NS_IMETHOD GetCallingFrame(jsdIStackFrame * *aCallingFrame) = 0;

  /**
     * Executon context.
     */
  /* readonly attribute jsdIContext executionContext; */
  NS_SCRIPTABLE NS_IMETHOD GetExecutionContext(jsdIContext * *aExecutionContext) = 0;

  /**
     * Function name executing in this stack frame.
     */
  /* readonly attribute string functionName; */
  NS_SCRIPTABLE NS_IMETHOD GetFunctionName(char * *aFunctionName) = 0;

  /**
     * Script running in this stack frame, null for native frames.
     */
  /* readonly attribute jsdIScript script; */
  NS_SCRIPTABLE NS_IMETHOD GetScript(jsdIScript * *aScript) = 0;

  /**
     * Current program counter in this stack frame.
     */
  /* readonly attribute unsigned long pc; */
  NS_SCRIPTABLE NS_IMETHOD GetPc(PRUint32 *aPc) = 0;

  /**
     * Current line number (using the script's pc to line map.)
     */
  /* readonly attribute unsigned long line; */
  NS_SCRIPTABLE NS_IMETHOD GetLine(PRUint32 *aLine) = 0;

  /**
     * Function object running in this stack frame.
     */
  /* readonly attribute jsdIValue callee; */
  NS_SCRIPTABLE NS_IMETHOD GetCallee(jsdIValue * *aCallee) = 0;

  /**
     * Top object in the scope chain.
     */
  /* readonly attribute jsdIValue scope; */
  NS_SCRIPTABLE NS_IMETHOD GetScope(jsdIValue * *aScope) = 0;

  /**
     * |this| object for this stack frame.
     */
  /* readonly attribute jsdIValue thisValue; */
  NS_SCRIPTABLE NS_IMETHOD GetThisValue(jsdIValue * *aThisValue) = 0;

  /**
     * Evaluate arbitrary JavaScript in this stack frame.
     * @param bytes    Script to be evaluated.
     * @param fileName Filename to compile this script under.  This is the
     *                 filename you'll see in error messages, etc.
     * @param line     Starting line number for this script.  One based.
     * @retval         Result of evaluating the script.
     */
  /* boolean eval (in AString bytes, in string fileName, in unsigned long line, out jsdIValue result); */
  NS_SCRIPTABLE NS_IMETHOD Eval(const nsAString & bytes, const char *fileName, PRUint32 line, jsdIValue **result NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIStackFrame, JSDISTACKFRAME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDISTACKFRAME \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext); \
  NS_IMETHOD GetJSDThreadState(JSDThreadState * *aJSDThreadState); \
  NS_IMETHOD GetJSDStackFrameInfo(JSDStackFrameInfo * *aJSDStackFrameInfo); \
  NS_SCRIPTABLE NS_IMETHOD GetIsNative(PRBool *aIsNative); \
  NS_SCRIPTABLE NS_IMETHOD GetIsDebugger(PRBool *aIsDebugger); \
  NS_SCRIPTABLE NS_IMETHOD GetIsConstructing(PRBool *aIsConstructing); \
  NS_SCRIPTABLE NS_IMETHOD GetCallingFrame(jsdIStackFrame * *aCallingFrame); \
  NS_SCRIPTABLE NS_IMETHOD GetExecutionContext(jsdIContext * *aExecutionContext); \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionName(char * *aFunctionName); \
  NS_SCRIPTABLE NS_IMETHOD GetScript(jsdIScript * *aScript); \
  NS_SCRIPTABLE NS_IMETHOD GetPc(PRUint32 *aPc); \
  NS_SCRIPTABLE NS_IMETHOD GetLine(PRUint32 *aLine); \
  NS_SCRIPTABLE NS_IMETHOD GetCallee(jsdIValue * *aCallee); \
  NS_SCRIPTABLE NS_IMETHOD GetScope(jsdIValue * *aScope); \
  NS_SCRIPTABLE NS_IMETHOD GetThisValue(jsdIValue * *aThisValue); \
  NS_SCRIPTABLE NS_IMETHOD Eval(const nsAString & bytes, const char *fileName, PRUint32 line, jsdIValue **result NS_OUTPARAM, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDISTACKFRAME(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return _to GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDThreadState(JSDThreadState * *aJSDThreadState) { return _to GetJSDThreadState(aJSDThreadState); } \
  NS_IMETHOD GetJSDStackFrameInfo(JSDStackFrameInfo * *aJSDStackFrameInfo) { return _to GetJSDStackFrameInfo(aJSDStackFrameInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNative(PRBool *aIsNative) { return _to GetIsNative(aIsNative); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDebugger(PRBool *aIsDebugger) { return _to GetIsDebugger(aIsDebugger); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsConstructing(PRBool *aIsConstructing) { return _to GetIsConstructing(aIsConstructing); } \
  NS_SCRIPTABLE NS_IMETHOD GetCallingFrame(jsdIStackFrame * *aCallingFrame) { return _to GetCallingFrame(aCallingFrame); } \
  NS_SCRIPTABLE NS_IMETHOD GetExecutionContext(jsdIContext * *aExecutionContext) { return _to GetExecutionContext(aExecutionContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionName(char * *aFunctionName) { return _to GetFunctionName(aFunctionName); } \
  NS_SCRIPTABLE NS_IMETHOD GetScript(jsdIScript * *aScript) { return _to GetScript(aScript); } \
  NS_SCRIPTABLE NS_IMETHOD GetPc(PRUint32 *aPc) { return _to GetPc(aPc); } \
  NS_SCRIPTABLE NS_IMETHOD GetLine(PRUint32 *aLine) { return _to GetLine(aLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetCallee(jsdIValue * *aCallee) { return _to GetCallee(aCallee); } \
  NS_SCRIPTABLE NS_IMETHOD GetScope(jsdIValue * *aScope) { return _to GetScope(aScope); } \
  NS_SCRIPTABLE NS_IMETHOD GetThisValue(jsdIValue * *aThisValue) { return _to GetThisValue(aThisValue); } \
  NS_SCRIPTABLE NS_IMETHOD Eval(const nsAString & bytes, const char *fileName, PRUint32 line, jsdIValue **result NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to Eval(bytes, fileName, line, result, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDISTACKFRAME(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDThreadState(JSDThreadState * *aJSDThreadState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDThreadState(aJSDThreadState); } \
  NS_IMETHOD GetJSDStackFrameInfo(JSDStackFrameInfo * *aJSDStackFrameInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDStackFrameInfo(aJSDStackFrameInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNative(PRBool *aIsNative) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNative(aIsNative); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDebugger(PRBool *aIsDebugger) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDebugger(aIsDebugger); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsConstructing(PRBool *aIsConstructing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsConstructing(aIsConstructing); } \
  NS_SCRIPTABLE NS_IMETHOD GetCallingFrame(jsdIStackFrame * *aCallingFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallingFrame(aCallingFrame); } \
  NS_SCRIPTABLE NS_IMETHOD GetExecutionContext(jsdIContext * *aExecutionContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExecutionContext(aExecutionContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionName(char * *aFunctionName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFunctionName(aFunctionName); } \
  NS_SCRIPTABLE NS_IMETHOD GetScript(jsdIScript * *aScript) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScript(aScript); } \
  NS_SCRIPTABLE NS_IMETHOD GetPc(PRUint32 *aPc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPc(aPc); } \
  NS_SCRIPTABLE NS_IMETHOD GetLine(PRUint32 *aLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLine(aLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetCallee(jsdIValue * *aCallee) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallee(aCallee); } \
  NS_SCRIPTABLE NS_IMETHOD GetScope(jsdIValue * *aScope) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScope(aScope); } \
  NS_SCRIPTABLE NS_IMETHOD GetThisValue(jsdIValue * *aThisValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThisValue(aThisValue); } \
  NS_SCRIPTABLE NS_IMETHOD Eval(const nsAString & bytes, const char *fileName, PRUint32 line, jsdIValue **result NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Eval(bytes, fileName, line, result, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIStackFrame
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDISTACKFRAME

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIStackFrame)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] readonly attribute JSDContext JSDContext; */
NS_IMETHODIMP _MYCLASS_::GetJSDContext(JSDContext * *aJSDContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute JSDThreadState JSDThreadState; */
NS_IMETHODIMP _MYCLASS_::GetJSDThreadState(JSDThreadState * *aJSDThreadState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute JSDStackFrameInfo JSDStackFrameInfo; */
NS_IMETHODIMP _MYCLASS_::GetJSDStackFrameInfo(JSDStackFrameInfo * *aJSDStackFrameInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isNative; */
NS_IMETHODIMP _MYCLASS_::GetIsNative(PRBool *aIsNative)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDebugger; */
NS_IMETHODIMP _MYCLASS_::GetIsDebugger(PRBool *aIsDebugger)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isConstructing; */
NS_IMETHODIMP _MYCLASS_::GetIsConstructing(PRBool *aIsConstructing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIStackFrame callingFrame; */
NS_IMETHODIMP _MYCLASS_::GetCallingFrame(jsdIStackFrame * *aCallingFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIContext executionContext; */
NS_IMETHODIMP _MYCLASS_::GetExecutionContext(jsdIContext * *aExecutionContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string functionName; */
NS_IMETHODIMP _MYCLASS_::GetFunctionName(char * *aFunctionName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIScript script; */
NS_IMETHODIMP _MYCLASS_::GetScript(jsdIScript * *aScript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long pc; */
NS_IMETHODIMP _MYCLASS_::GetPc(PRUint32 *aPc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long line; */
NS_IMETHODIMP _MYCLASS_::GetLine(PRUint32 *aLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue callee; */
NS_IMETHODIMP _MYCLASS_::GetCallee(jsdIValue * *aCallee)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue scope; */
NS_IMETHODIMP _MYCLASS_::GetScope(jsdIValue * *aScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue thisValue; */
NS_IMETHODIMP _MYCLASS_::GetThisValue(jsdIValue * *aThisValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean eval (in AString bytes, in string fileName, in unsigned long line, out jsdIValue result); */
NS_IMETHODIMP _MYCLASS_::Eval(const nsAString & bytes, const char *fileName, PRUint32 line, jsdIValue **result NS_OUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIScript */
#define JSDISCRIPT_IID_STR "a38f65ca-1dd1-11b2-95d5-ff2947e9c920"

#define JSDISCRIPT_IID \
  {0xa38f65ca, 0x1dd1, 0x11b2, \
    { 0x95, 0xd5, 0xff, 0x29, 0x47, 0xe9, 0xc9, 0x20 }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIScript : public jsdIEphemeral {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDISCRIPT_IID)

  /**
 * Script object.  In JavaScript engine terms, there's a single script for each
 * function, and one for the top level script.
 */
/** Internal use only. */
  /* [noscript] readonly attribute JSDContext JSDContext; */
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) = 0;

  /** Internal use only. */
  /* [noscript] readonly attribute JSDScript JSDScript; */
  NS_IMETHOD GetJSDScript(JSDScript * *aJSDScript) = 0;

  /**
     * Last version set on this context.
     * Scripts typically select this with the "language" attribute.
     * See the VERSION_* consts on jsdIDebuggerService.
     */
  /* readonly attribute long version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(PRInt32 *aVersion) = 0;

  /**
     * Tag value guaranteed unique among jsdIScript objects.  Useful as a
     * hash key in script.
     */
  /* readonly attribute unsigned long tag; */
  NS_SCRIPTABLE NS_IMETHOD GetTag(PRUint32 *aTag) = 0;

  /**
     * FLAG_* values need to be kept in sync with JSD_SCRIPT_* #defines in
     * jsdebug.h.
     */
/**
     * Determines whether or not to collect profile information for this
     * script.  The context flag FLAG_PROFILE_WHEN_SET decides the logic.
     */
  enum { FLAG_PROFILE = 1U };

  /**
     * Determines whether or not to ignore breakpoints, etc. in this script.
     * The context flag JSD_DEBUG_WHEN_SET decides the logic.
     */
  enum { FLAG_DEBUG = 2U };

  /**
     * FLAG_* attributes from above, OR'd together.
     */
  /* attribute unsigned long flags; */
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) = 0;

  /**
     * Filename given for this script when it was compiled.
     * This data is copied from the underlying structure when the jsdIScript
     * instance is created and is therefore available even after the script is
     * invalidated.
     */
  /* readonly attribute string fileName; */
  NS_SCRIPTABLE NS_IMETHOD GetFileName(char * *aFileName) = 0;

  /**
     * Function name for this script.  "anonymous" for unnamed functions (or
     * a function actually named anonymous), empty for top level scripts.
     * This data is copied from the underlying structure when the jsdIScript
     * instance is created and is therefore available even after the script is
     * invalidated.
     */
  /* readonly attribute string functionName; */
  NS_SCRIPTABLE NS_IMETHOD GetFunctionName(char * *aFunctionName) = 0;

  /**
     * Fetch the function object as a jsdIValue.
     */
  /* readonly attribute jsdIValue functionObject; */
  NS_SCRIPTABLE NS_IMETHOD GetFunctionObject(jsdIValue * *aFunctionObject) = 0;

  /**
     * Source code for this script, without function declaration.
     */
  /* readonly attribute AString functionSource; */
  NS_SCRIPTABLE NS_IMETHOD GetFunctionSource(nsAString & aFunctionSource) = 0;

  /**
     * Line number in source file containing the first line of this script.
     * This data is copied from the underlying structure when the jsdIScript
     * instance is created and is therefore available even after the script is
     * invalidated.
     */
  /* readonly attribute unsigned long baseLineNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseLineNumber(PRUint32 *aBaseLineNumber) = 0;

  /**
     * Total number of lines in this script.
     * This data is copied from the underlying structure when the jsdIScript
     * instance is created and is therefore available even after the script is
     * invalidated.
     */
  /* readonly attribute unsigned long lineExtent; */
  NS_SCRIPTABLE NS_IMETHOD GetLineExtent(PRUint32 *aLineExtent) = 0;

  /**
     * Number of times this script has been called.
     */
  /* readonly attribute unsigned long callCount; */
  NS_SCRIPTABLE NS_IMETHOD GetCallCount(PRUint32 *aCallCount) = 0;

  /**
     * Number of times this script called itself, directly or indirectly.
     */
  /* readonly attribute unsigned long maxRecurseDepth; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxRecurseDepth(PRUint32 *aMaxRecurseDepth) = 0;

  /**
     * Shortest execution time recorded, in milliseconds.
     */
  /* readonly attribute double minExecutionTime; */
  NS_SCRIPTABLE NS_IMETHOD GetMinExecutionTime(double *aMinExecutionTime) = 0;

  /**
     * Longest execution time recorded, in milliseconds.
     */
  /* readonly attribute double maxExecutionTime; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxExecutionTime(double *aMaxExecutionTime) = 0;

  /**
     * Total time spent in this function, in milliseconds.
     */
  /* readonly attribute double totalExecutionTime; */
  NS_SCRIPTABLE NS_IMETHOD GetTotalExecutionTime(double *aTotalExecutionTime) = 0;

  /**
     * Shortest execution time recorded, in milliseconds, excluding time spent
     * in other called code.
     */
  /* readonly attribute double minOwnExecutionTime; */
  NS_SCRIPTABLE NS_IMETHOD GetMinOwnExecutionTime(double *aMinOwnExecutionTime) = 0;

  /**
     * Longest execution time recorded, in milliseconds, excluding time spent
     * in other called code.
     */
  /* readonly attribute double maxOwnExecutionTime; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxOwnExecutionTime(double *aMaxOwnExecutionTime) = 0;

  /**
     * Total time spent in this function, in milliseconds, excluding time spent
     * in other called code.
     */
  /* readonly attribute double totalOwnExecutionTime; */
  NS_SCRIPTABLE NS_IMETHOD GetTotalOwnExecutionTime(double *aTotalOwnExecutionTime) = 0;

  /**
     * Clear profile data for this script.
     */
  /* void clearProfileData (); */
  NS_SCRIPTABLE NS_IMETHOD ClearProfileData(void) = 0;

  enum { PCMAP_SOURCETEXT = 1U };

  enum { PCMAP_PRETTYPRINT = 2U };

  /**
     * Get the closest line number to a given PC.
     * The |pcmap| argument specifies which pc to source line map to use.
     */
  /* unsigned long pcToLine (in unsigned long pc, in unsigned long pcmap); */
  NS_SCRIPTABLE NS_IMETHOD PcToLine(PRUint32 pc, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
     * Get the first PC associated with a line.
     * The |pcmap| argument specifies which pc to source line map to use.
     */
  /* unsigned long lineToPc (in unsigned long line, in unsigned long pcmap); */
  NS_SCRIPTABLE NS_IMETHOD LineToPc(PRUint32 line, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
     * Determine is a particular line is executable, like checking that
     * lineToPc == pcToLine, except in one call.
     * The |pcmap| argument specifies which pc to source line map to use.
     */
  /* boolean isLineExecutable (in unsigned long line, in unsigned long pcmap); */
  NS_SCRIPTABLE NS_IMETHOD IsLineExecutable(PRUint32 line, PRUint32 pcmap, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Set a breakpoint at a PC in this script.
     */
  /* void setBreakpoint (in unsigned long pc); */
  NS_SCRIPTABLE NS_IMETHOD SetBreakpoint(PRUint32 pc) = 0;

  /**
     * Clear a breakpoint at a PC in this script.
     */
  /* void clearBreakpoint (in unsigned long pc); */
  NS_SCRIPTABLE NS_IMETHOD ClearBreakpoint(PRUint32 pc) = 0;

  /**
     * Clear all breakpoints set in this script.
     */
  /* void clearAllBreakpoints (); */
  NS_SCRIPTABLE NS_IMETHOD ClearAllBreakpoints(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIScript, JSDISCRIPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDISCRIPT \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext); \
  NS_IMETHOD GetJSDScript(JSDScript * *aJSDScript); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(PRInt32 *aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetTag(PRUint32 *aTag); \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetFileName(char * *aFileName); \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionName(char * *aFunctionName); \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionObject(jsdIValue * *aFunctionObject); \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionSource(nsAString & aFunctionSource); \
  NS_SCRIPTABLE NS_IMETHOD GetBaseLineNumber(PRUint32 *aBaseLineNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetLineExtent(PRUint32 *aLineExtent); \
  NS_SCRIPTABLE NS_IMETHOD GetCallCount(PRUint32 *aCallCount); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxRecurseDepth(PRUint32 *aMaxRecurseDepth); \
  NS_SCRIPTABLE NS_IMETHOD GetMinExecutionTime(double *aMinExecutionTime); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxExecutionTime(double *aMaxExecutionTime); \
  NS_SCRIPTABLE NS_IMETHOD GetTotalExecutionTime(double *aTotalExecutionTime); \
  NS_SCRIPTABLE NS_IMETHOD GetMinOwnExecutionTime(double *aMinOwnExecutionTime); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxOwnExecutionTime(double *aMaxOwnExecutionTime); \
  NS_SCRIPTABLE NS_IMETHOD GetTotalOwnExecutionTime(double *aTotalOwnExecutionTime); \
  NS_SCRIPTABLE NS_IMETHOD ClearProfileData(void); \
  NS_SCRIPTABLE NS_IMETHOD PcToLine(PRUint32 pc, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LineToPc(PRUint32 line, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsLineExecutable(PRUint32 line, PRUint32 pcmap, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetBreakpoint(PRUint32 pc); \
  NS_SCRIPTABLE NS_IMETHOD ClearBreakpoint(PRUint32 pc); \
  NS_SCRIPTABLE NS_IMETHOD ClearAllBreakpoints(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDISCRIPT(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return _to GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDScript(JSDScript * *aJSDScript) { return _to GetJSDScript(aJSDScript); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(PRInt32 *aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetTag(PRUint32 *aTag) { return _to GetTag(aTag); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return _to GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return _to SetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileName(char * *aFileName) { return _to GetFileName(aFileName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionName(char * *aFunctionName) { return _to GetFunctionName(aFunctionName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionObject(jsdIValue * *aFunctionObject) { return _to GetFunctionObject(aFunctionObject); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionSource(nsAString & aFunctionSource) { return _to GetFunctionSource(aFunctionSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseLineNumber(PRUint32 *aBaseLineNumber) { return _to GetBaseLineNumber(aBaseLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineExtent(PRUint32 *aLineExtent) { return _to GetLineExtent(aLineExtent); } \
  NS_SCRIPTABLE NS_IMETHOD GetCallCount(PRUint32 *aCallCount) { return _to GetCallCount(aCallCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxRecurseDepth(PRUint32 *aMaxRecurseDepth) { return _to GetMaxRecurseDepth(aMaxRecurseDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinExecutionTime(double *aMinExecutionTime) { return _to GetMinExecutionTime(aMinExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxExecutionTime(double *aMaxExecutionTime) { return _to GetMaxExecutionTime(aMaxExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalExecutionTime(double *aTotalExecutionTime) { return _to GetTotalExecutionTime(aTotalExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinOwnExecutionTime(double *aMinOwnExecutionTime) { return _to GetMinOwnExecutionTime(aMinOwnExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxOwnExecutionTime(double *aMaxOwnExecutionTime) { return _to GetMaxOwnExecutionTime(aMaxOwnExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalOwnExecutionTime(double *aTotalOwnExecutionTime) { return _to GetTotalOwnExecutionTime(aTotalOwnExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD ClearProfileData(void) { return _to ClearProfileData(); } \
  NS_SCRIPTABLE NS_IMETHOD PcToLine(PRUint32 pc, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM) { return _to PcToLine(pc, pcmap, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LineToPc(PRUint32 line, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM) { return _to LineToPc(line, pcmap, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsLineExecutable(PRUint32 line, PRUint32 pcmap, PRBool *_retval NS_OUTPARAM) { return _to IsLineExecutable(line, pcmap, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetBreakpoint(PRUint32 pc) { return _to SetBreakpoint(pc); } \
  NS_SCRIPTABLE NS_IMETHOD ClearBreakpoint(PRUint32 pc) { return _to ClearBreakpoint(pc); } \
  NS_SCRIPTABLE NS_IMETHOD ClearAllBreakpoints(void) { return _to ClearAllBreakpoints(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDISCRIPT(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDScript(JSDScript * *aJSDScript) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDScript(aJSDScript); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(PRInt32 *aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetTag(PRUint32 *aTag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTag(aTag); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileName(char * *aFileName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileName(aFileName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionName(char * *aFunctionName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFunctionName(aFunctionName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionObject(jsdIValue * *aFunctionObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFunctionObject(aFunctionObject); } \
  NS_SCRIPTABLE NS_IMETHOD GetFunctionSource(nsAString & aFunctionSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFunctionSource(aFunctionSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseLineNumber(PRUint32 *aBaseLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseLineNumber(aBaseLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineExtent(PRUint32 *aLineExtent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineExtent(aLineExtent); } \
  NS_SCRIPTABLE NS_IMETHOD GetCallCount(PRUint32 *aCallCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallCount(aCallCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxRecurseDepth(PRUint32 *aMaxRecurseDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxRecurseDepth(aMaxRecurseDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinExecutionTime(double *aMinExecutionTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinExecutionTime(aMinExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxExecutionTime(double *aMaxExecutionTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxExecutionTime(aMaxExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalExecutionTime(double *aTotalExecutionTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalExecutionTime(aTotalExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinOwnExecutionTime(double *aMinOwnExecutionTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinOwnExecutionTime(aMinOwnExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxOwnExecutionTime(double *aMaxOwnExecutionTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxOwnExecutionTime(aMaxOwnExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalOwnExecutionTime(double *aTotalOwnExecutionTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalOwnExecutionTime(aTotalOwnExecutionTime); } \
  NS_SCRIPTABLE NS_IMETHOD ClearProfileData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearProfileData(); } \
  NS_SCRIPTABLE NS_IMETHOD PcToLine(PRUint32 pc, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PcToLine(pc, pcmap, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LineToPc(PRUint32 line, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LineToPc(line, pcmap, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsLineExecutable(PRUint32 line, PRUint32 pcmap, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLineExecutable(line, pcmap, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetBreakpoint(PRUint32 pc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBreakpoint(pc); } \
  NS_SCRIPTABLE NS_IMETHOD ClearBreakpoint(PRUint32 pc) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearBreakpoint(pc); } \
  NS_SCRIPTABLE NS_IMETHOD ClearAllBreakpoints(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearAllBreakpoints(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIScript
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDISCRIPT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIScript)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] readonly attribute JSDContext JSDContext; */
NS_IMETHODIMP _MYCLASS_::GetJSDContext(JSDContext * *aJSDContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute JSDScript JSDScript; */
NS_IMETHODIMP _MYCLASS_::GetJSDScript(JSDScript * *aJSDScript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long version; */
NS_IMETHODIMP _MYCLASS_::GetVersion(PRInt32 *aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long tag; */
NS_IMETHODIMP _MYCLASS_::GetTag(PRUint32 *aTag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long flags; */
NS_IMETHODIMP _MYCLASS_::GetFlags(PRUint32 *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetFlags(PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string fileName; */
NS_IMETHODIMP _MYCLASS_::GetFileName(char * *aFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string functionName; */
NS_IMETHODIMP _MYCLASS_::GetFunctionName(char * *aFunctionName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue functionObject; */
NS_IMETHODIMP _MYCLASS_::GetFunctionObject(jsdIValue * *aFunctionObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString functionSource; */
NS_IMETHODIMP _MYCLASS_::GetFunctionSource(nsAString & aFunctionSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long baseLineNumber; */
NS_IMETHODIMP _MYCLASS_::GetBaseLineNumber(PRUint32 *aBaseLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long lineExtent; */
NS_IMETHODIMP _MYCLASS_::GetLineExtent(PRUint32 *aLineExtent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long callCount; */
NS_IMETHODIMP _MYCLASS_::GetCallCount(PRUint32 *aCallCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long maxRecurseDepth; */
NS_IMETHODIMP _MYCLASS_::GetMaxRecurseDepth(PRUint32 *aMaxRecurseDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double minExecutionTime; */
NS_IMETHODIMP _MYCLASS_::GetMinExecutionTime(double *aMinExecutionTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double maxExecutionTime; */
NS_IMETHODIMP _MYCLASS_::GetMaxExecutionTime(double *aMaxExecutionTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double totalExecutionTime; */
NS_IMETHODIMP _MYCLASS_::GetTotalExecutionTime(double *aTotalExecutionTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double minOwnExecutionTime; */
NS_IMETHODIMP _MYCLASS_::GetMinOwnExecutionTime(double *aMinOwnExecutionTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double maxOwnExecutionTime; */
NS_IMETHODIMP _MYCLASS_::GetMaxOwnExecutionTime(double *aMaxOwnExecutionTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double totalOwnExecutionTime; */
NS_IMETHODIMP _MYCLASS_::GetTotalOwnExecutionTime(double *aTotalOwnExecutionTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearProfileData (); */
NS_IMETHODIMP _MYCLASS_::ClearProfileData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long pcToLine (in unsigned long pc, in unsigned long pcmap); */
NS_IMETHODIMP _MYCLASS_::PcToLine(PRUint32 pc, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long lineToPc (in unsigned long line, in unsigned long pcmap); */
NS_IMETHODIMP _MYCLASS_::LineToPc(PRUint32 line, PRUint32 pcmap, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLineExecutable (in unsigned long line, in unsigned long pcmap); */
NS_IMETHODIMP _MYCLASS_::IsLineExecutable(PRUint32 line, PRUint32 pcmap, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBreakpoint (in unsigned long pc); */
NS_IMETHODIMP _MYCLASS_::SetBreakpoint(PRUint32 pc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearBreakpoint (in unsigned long pc); */
NS_IMETHODIMP _MYCLASS_::ClearBreakpoint(PRUint32 pc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearAllBreakpoints (); */
NS_IMETHODIMP _MYCLASS_::ClearAllBreakpoints()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIValue */
#define JSDIVALUE_IID_STR "b7964304-1dd1-11b2-ba20-cf4205772e9d"

#define JSDIVALUE_IID \
  {0xb7964304, 0x1dd1, 0x11b2, \
    { 0xba, 0x20, 0xcf, 0x42, 0x05, 0x77, 0x2e, 0x9d }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIValue : public jsdIEphemeral {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDIVALUE_IID)

  /**
 * Value objects.  Represents typeless JavaScript values (jsval in SpiderMonkey
 * terminology.)  These are valid until the debugger is turned off.  Holding a
 * jsdIValue adds a root for the underlying JavaScript value, so don't keep it
 * if you don't need to.
 */
/** Internal use only. */
  /* [noscript] readonly attribute JSDContext JSDContext; */
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) = 0;

  /** Internal use only. */
  /* [noscript] readonly attribute JSDValue JSDValue; */
  NS_IMETHOD GetJSDValue(JSDValue * *aJSDValue) = 0;

  /**
     * |false| unless the value is a function declared in script.
     */
  /* readonly attribute boolean isNative; */
  NS_SCRIPTABLE NS_IMETHOD GetIsNative(PRBool *aIsNative) = 0;

  /**
     * |true| if the value represents a number, either double or integer.
     * |false| for all other values, including numbers assigned as strings
     * (eg. x = "1";)
     */
  /* readonly attribute boolean isNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetIsNumber(PRBool *aIsNumber) = 0;

  /**
     * |true| if the value represents a JavaScript primitive number or string
     */
  /* readonly attribute boolean isPrimitive; */
  NS_SCRIPTABLE NS_IMETHOD GetIsPrimitive(PRBool *aIsPrimitive) = 0;

  /** Value is either |true| or |false|. */
  enum { TYPE_BOOLEAN = 0U };

  /** Value is a primitive number that is too large to fit in an integer. */
  enum { TYPE_DOUBLE = 1U };

  /** Value is a primitive number that fits into an integer. */
  enum { TYPE_INT = 2U };

  /** Value is a function. */
  enum { TYPE_FUNCTION = 3U };

  /** Value is |null|. */
  enum { TYPE_NULL = 4U };

  /** Value is an object. */
  enum { TYPE_OBJECT = 5U };

  /** Value is a primitive string. */
  enum { TYPE_STRING = 6U };

  /** Value is void. */
  enum { TYPE_VOID = 7U };

  /**
     * One of the TYPE_* values above.
     */
  /* readonly attribute unsigned long jsType; */
  NS_SCRIPTABLE NS_IMETHOD GetJsType(PRUint32 *aJsType) = 0;

  /**
     * Prototype value if this value represents an object, null if the value is
     * not an object or the object has no prototype.
     */
  /* readonly attribute jsdIValue jsPrototype; */
  NS_SCRIPTABLE NS_IMETHOD GetJsPrototype(jsdIValue * *aJsPrototype) = 0;

  /**
     * Parent value if this value represents an object, null if the value is not
     * an object or the object has no parent.
     */
  /* readonly attribute jsdIValue jsParent; */
  NS_SCRIPTABLE NS_IMETHOD GetJsParent(jsdIValue * *aJsParent) = 0;

  /**
     * Class name if this value represents an object.  Empty string if the value
     * is not an object.
     */
  /* readonly attribute string jsClassName; */
  NS_SCRIPTABLE NS_IMETHOD GetJsClassName(char * *aJsClassName) = 0;

  /**
     * Constructor name if this value represents an object.  Empty string if the
     * value is not an object.
     */
  /* readonly attribute jsdIValue jsConstructor; */
  NS_SCRIPTABLE NS_IMETHOD GetJsConstructor(jsdIValue * *aJsConstructor) = 0;

  /**
     * Function name if this value represents a function.  Empty string if the
     * value is not a function.
     */
  /* readonly attribute string jsFunctionName; */
  NS_SCRIPTABLE NS_IMETHOD GetJsFunctionName(char * *aJsFunctionName) = 0;

  /**
     * Value if interpreted as a boolean.  Converts if necessary.
     */
  /* readonly attribute boolean booleanValue; */
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(PRBool *aBooleanValue) = 0;

  /**
     * Value if interpreted as a double.  Converts if necessary.
     */
  /* readonly attribute double doubleValue; */
  NS_SCRIPTABLE NS_IMETHOD GetDoubleValue(double *aDoubleValue) = 0;

  /**
     * Value if interpreted as an integer.  Converts if necessary.
     */
  /* readonly attribute long intValue; */
  NS_SCRIPTABLE NS_IMETHOD GetIntValue(PRInt32 *aIntValue) = 0;

  /**
     * Value if interpreted as an object.
     */
  /* readonly attribute jsdIObject objectValue; */
  NS_SCRIPTABLE NS_IMETHOD GetObjectValue(jsdIObject * *aObjectValue) = 0;

  /**
     * Value if interpreted as a string.  Converts if necessary.
     */
  /* readonly attribute string stringValue; */
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(char * *aStringValue) = 0;

  /**
     * Number of properties.  0 if the value is not an object, or the value is
     * an object but has no properties.
     */
  /* readonly attribute long propertyCount; */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyCount(PRInt32 *aPropertyCount) = 0;

  /**
     * Retrieves all properties if this value represents an object.  If this
     * value is not an object a 0 element array is returned.
     * @param propArray Array of jsdIProperty values for this value.
     * @param length    Size of array.
     */
  /* void getProperties ([array, size_is (length)] out jsdIProperty propArray, out unsigned long length); */
  NS_SCRIPTABLE NS_IMETHOD GetProperties(jsdIProperty ***propArray NS_OUTPARAM, PRUint32 *length NS_OUTPARAM) = 0;

  /**
     * Retrieves a single property from the value.  Only valid if the value
     * represents an object.
     * @param name Name of the property to retrieve.
     * @retval     jsdIProperty for the requested property name or null if no
     *             property exists for the requested name.
     */
  /* jsdIProperty getProperty (in string name); */
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const char *name, jsdIProperty **_retval NS_OUTPARAM) = 0;

  /**
     * jsdIValues are wrappers around JavaScript engine structures.  Much of the
     * data is copied instead of shared.  The refresh method is used to resync
     * the jsdIValue with the underlying structure.
     */
  /* void refresh (); */
  NS_SCRIPTABLE NS_IMETHOD Refresh(void) = 0;

  /**
     * When called from JavaScript, this method returns the JavaScript value
     * wrapped by this jsdIValue.  The calling script is free to use the result
     * as it would any other JavaScript value.
     * When called from another language this method returns an xpconnect
     * defined error code.
     */
  /* void getWrappedValue (); */
  NS_SCRIPTABLE NS_IMETHOD GetWrappedValue(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIValue, JSDIVALUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDIVALUE \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext); \
  NS_IMETHOD GetJSDValue(JSDValue * *aJSDValue); \
  NS_SCRIPTABLE NS_IMETHOD GetIsNative(PRBool *aIsNative); \
  NS_SCRIPTABLE NS_IMETHOD GetIsNumber(PRBool *aIsNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetIsPrimitive(PRBool *aIsPrimitive); \
  NS_SCRIPTABLE NS_IMETHOD GetJsType(PRUint32 *aJsType); \
  NS_SCRIPTABLE NS_IMETHOD GetJsPrototype(jsdIValue * *aJsPrototype); \
  NS_SCRIPTABLE NS_IMETHOD GetJsParent(jsdIValue * *aJsParent); \
  NS_SCRIPTABLE NS_IMETHOD GetJsClassName(char * *aJsClassName); \
  NS_SCRIPTABLE NS_IMETHOD GetJsConstructor(jsdIValue * *aJsConstructor); \
  NS_SCRIPTABLE NS_IMETHOD GetJsFunctionName(char * *aJsFunctionName); \
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(PRBool *aBooleanValue); \
  NS_SCRIPTABLE NS_IMETHOD GetDoubleValue(double *aDoubleValue); \
  NS_SCRIPTABLE NS_IMETHOD GetIntValue(PRInt32 *aIntValue); \
  NS_SCRIPTABLE NS_IMETHOD GetObjectValue(jsdIObject * *aObjectValue); \
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(char * *aStringValue); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyCount(PRInt32 *aPropertyCount); \
  NS_SCRIPTABLE NS_IMETHOD GetProperties(jsdIProperty ***propArray NS_OUTPARAM, PRUint32 *length NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const char *name, jsdIProperty **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Refresh(void); \
  NS_SCRIPTABLE NS_IMETHOD GetWrappedValue(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDIVALUE(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return _to GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDValue(JSDValue * *aJSDValue) { return _to GetJSDValue(aJSDValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNative(PRBool *aIsNative) { return _to GetIsNative(aIsNative); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNumber(PRBool *aIsNumber) { return _to GetIsNumber(aIsNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsPrimitive(PRBool *aIsPrimitive) { return _to GetIsPrimitive(aIsPrimitive); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsType(PRUint32 *aJsType) { return _to GetJsType(aJsType); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsPrototype(jsdIValue * *aJsPrototype) { return _to GetJsPrototype(aJsPrototype); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsParent(jsdIValue * *aJsParent) { return _to GetJsParent(aJsParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsClassName(char * *aJsClassName) { return _to GetJsClassName(aJsClassName); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsConstructor(jsdIValue * *aJsConstructor) { return _to GetJsConstructor(aJsConstructor); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsFunctionName(char * *aJsFunctionName) { return _to GetJsFunctionName(aJsFunctionName); } \
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(PRBool *aBooleanValue) { return _to GetBooleanValue(aBooleanValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetDoubleValue(double *aDoubleValue) { return _to GetDoubleValue(aDoubleValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntValue(PRInt32 *aIntValue) { return _to GetIntValue(aIntValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectValue(jsdIObject * *aObjectValue) { return _to GetObjectValue(aObjectValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(char * *aStringValue) { return _to GetStringValue(aStringValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyCount(PRInt32 *aPropertyCount) { return _to GetPropertyCount(aPropertyCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperties(jsdIProperty ***propArray NS_OUTPARAM, PRUint32 *length NS_OUTPARAM) { return _to GetProperties(propArray, length); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const char *name, jsdIProperty **_retval NS_OUTPARAM) { return _to GetProperty(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Refresh(void) { return _to Refresh(); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrappedValue(void) { return _to GetWrappedValue(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDIVALUE(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDValue(JSDValue * *aJSDValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDValue(aJSDValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNative(PRBool *aIsNative) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNative(aIsNative); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNumber(PRBool *aIsNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNumber(aIsNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsPrimitive(PRBool *aIsPrimitive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsPrimitive(aIsPrimitive); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsType(PRUint32 *aJsType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJsType(aJsType); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsPrototype(jsdIValue * *aJsPrototype) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJsPrototype(aJsPrototype); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsParent(jsdIValue * *aJsParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJsParent(aJsParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsClassName(char * *aJsClassName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJsClassName(aJsClassName); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsConstructor(jsdIValue * *aJsConstructor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJsConstructor(aJsConstructor); } \
  NS_SCRIPTABLE NS_IMETHOD GetJsFunctionName(char * *aJsFunctionName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJsFunctionName(aJsFunctionName); } \
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(PRBool *aBooleanValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBooleanValue(aBooleanValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetDoubleValue(double *aDoubleValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoubleValue(aDoubleValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntValue(PRInt32 *aIntValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntValue(aIntValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectValue(jsdIObject * *aObjectValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectValue(aObjectValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(char * *aStringValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringValue(aStringValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyCount(PRInt32 *aPropertyCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyCount(aPropertyCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperties(jsdIProperty ***propArray NS_OUTPARAM, PRUint32 *length NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperties(propArray, length); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const char *name, jsdIProperty **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperty(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Refresh(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Refresh(); } \
  NS_SCRIPTABLE NS_IMETHOD GetWrappedValue(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedValue(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIValue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDIVALUE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIValue)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] readonly attribute JSDContext JSDContext; */
NS_IMETHODIMP _MYCLASS_::GetJSDContext(JSDContext * *aJSDContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute JSDValue JSDValue; */
NS_IMETHODIMP _MYCLASS_::GetJSDValue(JSDValue * *aJSDValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isNative; */
NS_IMETHODIMP _MYCLASS_::GetIsNative(PRBool *aIsNative)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isNumber; */
NS_IMETHODIMP _MYCLASS_::GetIsNumber(PRBool *aIsNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isPrimitive; */
NS_IMETHODIMP _MYCLASS_::GetIsPrimitive(PRBool *aIsPrimitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long jsType; */
NS_IMETHODIMP _MYCLASS_::GetJsType(PRUint32 *aJsType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue jsPrototype; */
NS_IMETHODIMP _MYCLASS_::GetJsPrototype(jsdIValue * *aJsPrototype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue jsParent; */
NS_IMETHODIMP _MYCLASS_::GetJsParent(jsdIValue * *aJsParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string jsClassName; */
NS_IMETHODIMP _MYCLASS_::GetJsClassName(char * *aJsClassName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue jsConstructor; */
NS_IMETHODIMP _MYCLASS_::GetJsConstructor(jsdIValue * *aJsConstructor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string jsFunctionName; */
NS_IMETHODIMP _MYCLASS_::GetJsFunctionName(char * *aJsFunctionName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean booleanValue; */
NS_IMETHODIMP _MYCLASS_::GetBooleanValue(PRBool *aBooleanValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double doubleValue; */
NS_IMETHODIMP _MYCLASS_::GetDoubleValue(double *aDoubleValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long intValue; */
NS_IMETHODIMP _MYCLASS_::GetIntValue(PRInt32 *aIntValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIObject objectValue; */
NS_IMETHODIMP _MYCLASS_::GetObjectValue(jsdIObject * *aObjectValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string stringValue; */
NS_IMETHODIMP _MYCLASS_::GetStringValue(char * *aStringValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long propertyCount; */
NS_IMETHODIMP _MYCLASS_::GetPropertyCount(PRInt32 *aPropertyCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getProperties ([array, size_is (length)] out jsdIProperty propArray, out unsigned long length); */
NS_IMETHODIMP _MYCLASS_::GetProperties(jsdIProperty ***propArray NS_OUTPARAM, PRUint32 *length NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsdIProperty getProperty (in string name); */
NS_IMETHODIMP _MYCLASS_::GetProperty(const char *name, jsdIProperty **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refresh (); */
NS_IMETHODIMP _MYCLASS_::Refresh()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getWrappedValue (); */
NS_IMETHODIMP _MYCLASS_::GetWrappedValue()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIObject */
#define JSDIOBJECT_IID_STR "d500e8b8-1dd1-11b2-89a1-cdf55d91cbbd"

#define JSDIOBJECT_IID \
  {0xd500e8b8, 0x1dd1, 0x11b2, \
    { 0x89, 0xa1, 0xcd, 0xf5, 0x5d, 0x91, 0xcb, 0xbd }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDIOBJECT_IID)

  /**
 * Properties specific to values which are also objects.
 * XXX We don't add roots for these yet, so make sure you hold on to the
 * jsdIValue from whence your jsdIObject instance came for at least as long as
 * you hold the jsdIObject.
 * XXX Maybe the jsClassName, jsConstructorName, and property related attribute/
 * functions from jsdIValue should move to this interface.  We could inherit from
 * jsdIValue or use interface flattening or something.
 */
/** Internal use only. */
  /* [noscript] readonly attribute JSDContext JSDContext; */
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) = 0;

  /** Internal use only. */
  /* [noscript] readonly attribute JSDObject JSDObject; */
  NS_IMETHOD GetJSDObject(JSDObject * *aJSDObject) = 0;

  /**
     * The URL (filename) that contains the script which caused this object
     * to be created.
     */
  /* readonly attribute string creatorURL; */
  NS_SCRIPTABLE NS_IMETHOD GetCreatorURL(char * *aCreatorURL) = 0;

  /**
     * Line number in the creatorURL where this object was created.
     */
  /* readonly attribute unsigned long creatorLine; */
  NS_SCRIPTABLE NS_IMETHOD GetCreatorLine(PRUint32 *aCreatorLine) = 0;

  /**
     * The URL (filename) that contains the script which defined the constructor
     * used to create this object.
     */
  /* readonly attribute string constructorURL; */
  NS_SCRIPTABLE NS_IMETHOD GetConstructorURL(char * *aConstructorURL) = 0;

  /**
     * Line number in the creatorURL where this object was created.
     */
  /* readonly attribute unsigned long constructorLine; */
  NS_SCRIPTABLE NS_IMETHOD GetConstructorLine(PRUint32 *aConstructorLine) = 0;

  /**
     * jsdIValue for this object.
     */
  /* readonly attribute jsdIValue value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(jsdIValue * *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIObject, JSDIOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDIOBJECT \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext); \
  NS_IMETHOD GetJSDObject(JSDObject * *aJSDObject); \
  NS_SCRIPTABLE NS_IMETHOD GetCreatorURL(char * *aCreatorURL); \
  NS_SCRIPTABLE NS_IMETHOD GetCreatorLine(PRUint32 *aCreatorLine); \
  NS_SCRIPTABLE NS_IMETHOD GetConstructorURL(char * *aConstructorURL); \
  NS_SCRIPTABLE NS_IMETHOD GetConstructorLine(PRUint32 *aConstructorLine); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(jsdIValue * *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDIOBJECT(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return _to GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDObject(JSDObject * *aJSDObject) { return _to GetJSDObject(aJSDObject); } \
  NS_SCRIPTABLE NS_IMETHOD GetCreatorURL(char * *aCreatorURL) { return _to GetCreatorURL(aCreatorURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetCreatorLine(PRUint32 *aCreatorLine) { return _to GetCreatorLine(aCreatorLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetConstructorURL(char * *aConstructorURL) { return _to GetConstructorURL(aConstructorURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetConstructorLine(PRUint32 *aConstructorLine) { return _to GetConstructorLine(aConstructorLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(jsdIValue * *aValue) { return _to GetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDIOBJECT(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDObject(JSDObject * *aJSDObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDObject(aJSDObject); } \
  NS_SCRIPTABLE NS_IMETHOD GetCreatorURL(char * *aCreatorURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCreatorURL(aCreatorURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetCreatorLine(PRUint32 *aCreatorLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCreatorLine(aCreatorLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetConstructorURL(char * *aConstructorURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConstructorURL(aConstructorURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetConstructorLine(PRUint32 *aConstructorLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConstructorLine(aConstructorLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(jsdIValue * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDIOBJECT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIObject)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] readonly attribute JSDContext JSDContext; */
NS_IMETHODIMP _MYCLASS_::GetJSDContext(JSDContext * *aJSDContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute JSDObject JSDObject; */
NS_IMETHODIMP _MYCLASS_::GetJSDObject(JSDObject * *aJSDObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string creatorURL; */
NS_IMETHODIMP _MYCLASS_::GetCreatorURL(char * *aCreatorURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long creatorLine; */
NS_IMETHODIMP _MYCLASS_::GetCreatorLine(PRUint32 *aCreatorLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string constructorURL; */
NS_IMETHODIMP _MYCLASS_::GetConstructorURL(char * *aConstructorURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long constructorLine; */
NS_IMETHODIMP _MYCLASS_::GetConstructorLine(PRUint32 *aConstructorLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue value; */
NS_IMETHODIMP _MYCLASS_::GetValue(jsdIValue * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    jsdIProperty */
#define JSDIPROPERTY_IID_STR "b8816e56-1dd1-11b2-81dc-8ba99a833d9e"

#define JSDIPROPERTY_IID \
  {0xb8816e56, 0x1dd1, 0x11b2, \
    { 0x81, 0xdc, 0x8b, 0xa9, 0x9a, 0x83, 0x3d, 0x9e }}

class NS_NO_VTABLE NS_SCRIPTABLE jsdIProperty : public jsdIEphemeral {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(JSDIPROPERTY_IID)

  /**
 * Representation of a property of an object.  When an instance is invalid, all
 * method and property access will result in a NS_UNAVAILABLE error.
 */
/** Internal use only. */
  /* [noscript] readonly attribute JSDContext JSDContext; */
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) = 0;

  /** Internal use only. */
  /* [noscript] readonly attribute JSDProperty JSDProperty; */
  NS_IMETHOD GetJSDProperty(JSDProperty * *aJSDProperty) = 0;

  /**
     * FLAG_* values must be kept in sync with JSDPD_* #defines in jsdebug.h.
     */
/** visible to for/in loop */
  enum { FLAG_ENUMERATE = 1U };

  /** assignment is error */
  enum { FLAG_READONLY = 2U };

  /** property cannot be deleted */
  enum { FLAG_PERMANENT = 4U };

  /** property has an alias id */
  enum { FLAG_ALIAS = 8U };

  /** argument to function */
  enum { FLAG_ARGUMENT = 16U };

  /** local variable in function */
  enum { FLAG_VARIABLE = 32U };

  /** exception occurred looking up property, value is exception */
  enum { FLAG_EXCEPTION = 64U };

  /** native getter returned JS_FALSE without throwing an exception */
  enum { FLAG_ERROR = 128U };

  /** found via explicit lookup (property defined elsewhere.) */
  enum { FLAG_HINTED = 2048U };

  /** FLAG_* values OR'd together, representing the flags for this property. */
  /* readonly attribute unsigned long flags; */
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) = 0;

  /** jsdIValue representing the alias for this property. */
  /* readonly attribute jsdIValue alias; */
  NS_SCRIPTABLE NS_IMETHOD GetAlias(jsdIValue * *aAlias) = 0;

  /** name for this property. */
  /* readonly attribute jsdIValue name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(jsdIValue * *aName) = 0;

  /** value of this property. */
  /* readonly attribute jsdIValue value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(jsdIValue * *aValue) = 0;

  /** slot number if this property is a local variable or parameter. */
  /* readonly attribute unsigned long varArgSlot; */
  NS_SCRIPTABLE NS_IMETHOD GetVarArgSlot(PRUint32 *aVarArgSlot) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(jsdIProperty, JSDIPROPERTY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_JSDIPROPERTY \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext); \
  NS_IMETHOD GetJSDProperty(JSDProperty * *aJSDProperty); \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetAlias(jsdIValue * *aAlias); \
  NS_SCRIPTABLE NS_IMETHOD GetName(jsdIValue * *aName); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(jsdIValue * *aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetVarArgSlot(PRUint32 *aVarArgSlot); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_JSDIPROPERTY(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return _to GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDProperty(JSDProperty * *aJSDProperty) { return _to GetJSDProperty(aJSDProperty); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return _to GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlias(jsdIValue * *aAlias) { return _to GetAlias(aAlias); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(jsdIValue * *aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(jsdIValue * *aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetVarArgSlot(PRUint32 *aVarArgSlot) { return _to GetVarArgSlot(aVarArgSlot); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_JSDIPROPERTY(_to) \
  NS_IMETHOD GetJSDContext(JSDContext * *aJSDContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDContext(aJSDContext); } \
  NS_IMETHOD GetJSDProperty(JSDProperty * *aJSDProperty) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSDProperty(aJSDProperty); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlias(jsdIValue * *aAlias) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlias(aAlias); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(jsdIValue * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(jsdIValue * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetVarArgSlot(PRUint32 *aVarArgSlot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVarArgSlot(aVarArgSlot); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public jsdIProperty
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_JSDIPROPERTY

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, jsdIProperty)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] readonly attribute JSDContext JSDContext; */
NS_IMETHODIMP _MYCLASS_::GetJSDContext(JSDContext * *aJSDContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute JSDProperty JSDProperty; */
NS_IMETHODIMP _MYCLASS_::GetJSDProperty(JSDProperty * *aJSDProperty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long flags; */
NS_IMETHODIMP _MYCLASS_::GetFlags(PRUint32 *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue alias; */
NS_IMETHODIMP _MYCLASS_::GetAlias(jsdIValue * *aAlias)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue name; */
NS_IMETHODIMP _MYCLASS_::GetName(jsdIValue * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsdIValue value; */
NS_IMETHODIMP _MYCLASS_::GetValue(jsdIValue * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long varArgSlot; */
NS_IMETHODIMP _MYCLASS_::GetVarArgSlot(PRUint32 *aVarArgSlot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_jsdIDebuggerService_h__ */
