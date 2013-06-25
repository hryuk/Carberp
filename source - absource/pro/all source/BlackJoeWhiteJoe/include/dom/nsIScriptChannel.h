/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/nsIScriptChannel.idl
 */

#ifndef __gen_nsIScriptChannel_h__
#define __gen_nsIScriptChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScriptChannel */
#define NS_ISCRIPTCHANNEL_IID_STR "33234b99-9588-4c7d-9da6-86b8b7cba565"

#define NS_ISCRIPTCHANNEL_IID \
  {0x33234b99, 0x9588, 0x4c7d, \
    { 0x9d, 0xa6, 0x86, 0xb8, 0xb7, 0xcb, 0xa5, 0x65 }}

/**
 * An interface representing a channel which will have to execute some sort of
 * program provided via its URI to compute the data it should return.
 *
 * If a channel implements this interface, the execution of the program in
 * question will be restricted in the following ways:
 *
 * - If the channel does not have an owner principal, the program will not be
 *   executed at all, no matter what.  This is necessary because in this
 *   circumstance we have no way to tell whether script execution is allowed at
 *   all for the originating security context of this channel. 
 * - If the channel has an owner principal, how it is executed is controlled by
 *   this interface.  However if the owner principal does not subsume the
 *   principal of the environment in which the program is to be executed the
 *   execution will be forced to happen in a sandbox.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTCHANNEL_IID)

  /**
   * Possible ways of executing the program.
   */
/**
   * Don't execute at all.
   */
  enum { NO_EXECUTION = 0U };

  /**
   * Execute in a sandbox, no matter how the various principals involved are
   * related to each other.
   */
  enum { EXECUTE_IN_SANDBOX = 1U };

  /**
   * Execute against the target environment if the principals allow it.
   */
  enum { EXECUTE_NORMAL = 2U };

  /**
   * Whether and how the program represented by this channel is to be executed.
   * The default value if this property has never been set on this channel MUST
   * be either EXECUTE_IN_SANDBOX or NO_EXECUTION.
   *
   * @throws NS_ERROR_INVALID_ARG when set to an unrecognized value.
   */
  /* attribute unsigned long executionPolicy; */
  NS_SCRIPTABLE NS_IMETHOD GetExecutionPolicy(PRUint32 *aExecutionPolicy) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExecutionPolicy(PRUint32 aExecutionPolicy) = 0;

  /**
   * Control whether the program should be executed synchronosly when
   * the channel's AsyncOpen method is called or whether it should be
   * executed asynchronously.  In both cases, any data that the
   * channel returns will be returned asynchronously; the only thing
   * this property affects is when the program executes.
   *
   * The default value of this property is TRUE.
   *
   * Setting this property after asyncOpen has been called on the
   * channel has no effect.
   */
  /* attribute boolean executeAsync; */
  NS_SCRIPTABLE NS_IMETHOD GetExecuteAsync(PRBool *aExecuteAsync) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExecuteAsync(PRBool aExecuteAsync) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptChannel, NS_ISCRIPTCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetExecutionPolicy(PRUint32 *aExecutionPolicy); \
  NS_SCRIPTABLE NS_IMETHOD SetExecutionPolicy(PRUint32 aExecutionPolicy); \
  NS_SCRIPTABLE NS_IMETHOD GetExecuteAsync(PRBool *aExecuteAsync); \
  NS_SCRIPTABLE NS_IMETHOD SetExecuteAsync(PRBool aExecuteAsync); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetExecutionPolicy(PRUint32 *aExecutionPolicy) { return _to GetExecutionPolicy(aExecutionPolicy); } \
  NS_SCRIPTABLE NS_IMETHOD SetExecutionPolicy(PRUint32 aExecutionPolicy) { return _to SetExecutionPolicy(aExecutionPolicy); } \
  NS_SCRIPTABLE NS_IMETHOD GetExecuteAsync(PRBool *aExecuteAsync) { return _to GetExecuteAsync(aExecuteAsync); } \
  NS_SCRIPTABLE NS_IMETHOD SetExecuteAsync(PRBool aExecuteAsync) { return _to SetExecuteAsync(aExecuteAsync); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetExecutionPolicy(PRUint32 *aExecutionPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExecutionPolicy(aExecutionPolicy); } \
  NS_SCRIPTABLE NS_IMETHOD SetExecutionPolicy(PRUint32 aExecutionPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExecutionPolicy(aExecutionPolicy); } \
  NS_SCRIPTABLE NS_IMETHOD GetExecuteAsync(PRBool *aExecuteAsync) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExecuteAsync(aExecuteAsync); } \
  NS_SCRIPTABLE NS_IMETHOD SetExecuteAsync(PRBool aExecuteAsync) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExecuteAsync(aExecuteAsync); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptChannel : public nsIScriptChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTCHANNEL

  nsScriptChannel();

private:
  ~nsScriptChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptChannel, nsIScriptChannel)

nsScriptChannel::nsScriptChannel()
{
  /* member initializers and constructor code */
}

nsScriptChannel::~nsScriptChannel()
{
  /* destructor code */
}

/* attribute unsigned long executionPolicy; */
NS_IMETHODIMP nsScriptChannel::GetExecutionPolicy(PRUint32 *aExecutionPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsScriptChannel::SetExecutionPolicy(PRUint32 aExecutionPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean executeAsync; */
NS_IMETHODIMP nsScriptChannel::GetExecuteAsync(PRBool *aExecuteAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsScriptChannel::SetExecuteAsync(PRBool aExecuteAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptChannel_h__ */
