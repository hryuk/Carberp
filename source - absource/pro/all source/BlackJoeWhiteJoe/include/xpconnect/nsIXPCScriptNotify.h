/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/nsIXPCScriptNotify.idl
 */

#ifndef __gen_nsIXPCScriptNotify_h__
#define __gen_nsIXPCScriptNotify_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXPConnectWrappedNative; /* forward declaration */


/* starting interface:    nsIXPCScriptNotify */
#define NS_IXPCSCRIPTNOTIFY_IID_STR "b804504d-0025-4d6b-8ced-d94e41102a7f"

#define NS_IXPCSCRIPTNOTIFY_IID \
  {0xb804504d, 0x0025, 0x4d6b, \
    { 0x8c, 0xed, 0xd9, 0x4e, 0x41, 0x10, 0x2a, 0x7f }}

class NS_NO_VTABLE nsIXPCScriptNotify : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCSCRIPTNOTIFY_IID)

  /**
     * Method invoked when a script has been executed by XPConnect
     */
  /* void ScriptExecuted (); */
  NS_IMETHOD ScriptExecuted(void) = 0;

  /**
     * Method invoked to preserve an nsIXPConnectWrappedNative as needed
     */
  /* void preserveWrapper (in nsIXPConnectWrappedNative wrapper); */
  NS_IMETHOD PreserveWrapper(nsIXPConnectWrappedNative *wrapper) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCScriptNotify, NS_IXPCSCRIPTNOTIFY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCSCRIPTNOTIFY \
  NS_IMETHOD ScriptExecuted(void); \
  NS_IMETHOD PreserveWrapper(nsIXPConnectWrappedNative *wrapper); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCSCRIPTNOTIFY(_to) \
  NS_IMETHOD ScriptExecuted(void) { return _to ScriptExecuted(); } \
  NS_IMETHOD PreserveWrapper(nsIXPConnectWrappedNative *wrapper) { return _to PreserveWrapper(wrapper); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCSCRIPTNOTIFY(_to) \
  NS_IMETHOD ScriptExecuted(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptExecuted(); } \
  NS_IMETHOD PreserveWrapper(nsIXPConnectWrappedNative *wrapper) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreserveWrapper(wrapper); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCScriptNotify : public nsIXPCScriptNotify
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCSCRIPTNOTIFY

  nsXPCScriptNotify();

private:
  ~nsXPCScriptNotify();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCScriptNotify, nsIXPCScriptNotify)

nsXPCScriptNotify::nsXPCScriptNotify()
{
  /* member initializers and constructor code */
}

nsXPCScriptNotify::~nsXPCScriptNotify()
{
  /* destructor code */
}

/* void ScriptExecuted (); */
NS_IMETHODIMP nsXPCScriptNotify::ScriptExecuted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preserveWrapper (in nsIXPConnectWrappedNative wrapper); */
NS_IMETHODIMP nsXPCScriptNotify::PreserveWrapper(nsIXPConnectWrappedNative *wrapper)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPCScriptNotify_h__ */
