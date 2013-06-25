/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIPluginInstance.idl
 */

#ifndef __gen_nsIPluginInstance_h__
#define __gen_nsIPluginInstance_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPluginStreamListener_h__
#include "nsIPluginStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsplugindefs.h"
class nsIPluginInstancePeer; /* forward declaration */


/* starting interface:    nsIPluginInstance */
#define NS_IPLUGININSTANCE_IID_STR "ebe00f40-0199-11d2-815b-006008119d7a"

#define NS_IPLUGININSTANCE_IID \
  {0xebe00f40, 0x0199, 0x11d2, \
    { 0x81, 0x5b, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

/**
 * The nsIPluginInstance interface is the minimum interface plugin developers
 * need to support in order to implement a plugin instance. The plugin manager
 * may QueryInterface for more specific types, e.g. nsILiveConnectPluginInstance. 
 *
 * (Corresponds to NPP object.)
 *
 * The old NPP_Destroy call has been factored into two plugin instance 
 * methods:
 *
 * Stop -- called when the plugin instance is to be stopped (e.g. by 
 * displaying another plugin manager window, causing the page containing 
 * the plugin to become removed from the display).
 *
 * Destroy -- called once, before the plugin instance peer is to be 
 * destroyed. This method is used to destroy the plugin instance.
 */
class NS_NO_VTABLE nsIPluginInstance : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGININSTANCE_IID)

  /**
     * Initializes a newly created plugin instance, passing to it the
     * plugin instance peer which it should use for all communication
     * back to the browser.
     * 
     * @param aPeer - the corresponding plugin instance peer
     * @result      - NS_OK if this operation was successful
     */
  /* void initialize (in nsIPluginInstancePeer aPeer); */
  NS_IMETHOD Initialize(nsIPluginInstancePeer *aPeer) = 0;

  /**
     * Returns a reference back to the plugin instance peer. This method is
     * used whenever the browser needs to obtain the peer back from a plugin
     * instance. The implementation of this method should be sure to increment
     * the reference count on the peer by calling AddRef.
     *
     * @param aPeer - the resulting plugin instance peer
     * @result      - NS_OK if this operation was successful
     */
  /* readonly attribute nsIPluginInstancePeer peer; */
  NS_IMETHOD GetPeer(nsIPluginInstancePeer * *aPeer) = 0;

  /**
     * Called to instruct the plugin instance to start. This will be
     * called after the plugin is first created and initialized, and
     * may be called after the plugin is stopped (via the Stop method)
     * if the plugin instance is returned to in the browser window's
     * history.
     *
     * @result - NS_OK if this operation was successful
     */
  /* void start (); */
  NS_IMETHOD Start(void) = 0;

  /**
     * Called to instruct the plugin instance to stop, thereby
     * suspending its state.  This method will be called whenever the
     * browser window goes on to display another page and the page
     * containing the plugin goes into the window's history list.
     *
     * @result - NS_OK if this operation was successful
     */
  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

  /**
     * Called to instruct the plugin instance to destroy itself. This
     * is called when it become no longer possible to return to the
     * plugin instance, either because the browser window's history
     * list of pages is being trimmed, or because the window
     * containing this page in the history is being closed.
     *
     * @result - NS_OK if this operation was successful
     */
  /* void destroy (); */
  NS_IMETHOD Destroy(void) = 0;

  /**
     * Called when the window containing the plugin instance changes.
     *
     * (Corresponds to NPP_SetWindow.)
     *
     * @param aWindow - the plugin window structure
     * @result        - NS_OK if this operation was successful
     */
  /* void setWindow (in nsPluginWindowPtr aWindow); */
  NS_IMETHOD SetWindow(nsPluginWindow * aWindow) = 0;

  /**
     * Called to tell the plugin that the initial src/data stream is
	 * ready.  Expects the plugin to return a nsIPluginStreamListener.
     *
     * (Corresponds to NPP_NewStream.)
     *
     * @param aListener - listener the browser will use to give the plugin the data
     * @result          - NS_OK if this operation was successful
     */
  /* void newStream (out nsIPluginStreamListener aListener); */
  NS_IMETHOD NewStream(nsIPluginStreamListener **aListener NS_OUTPARAM) = 0;

  /**
     * Called to instruct the plugin instance to print itself to a printer.
     *
     * (Corresponds to NPP_Print.)
     *
     * @param aPlatformPrint - platform-specific printing information
     * @result               - NS_OK if this operation was successful
     */
  /* void print (in nsPluginPrintPtr aPlatformPrint); */
  NS_IMETHOD Print(nsPluginPrint * aPlatformPrint) = 0;

  /**
     * Returns the value of a variable associated with the plugin instance.
     *
     * @param aVariable - the plugin instance variable to get
     * @param aValue    - the address of where to store the resulting value
     * @result          - NS_OK if this operation was successful
     */
  /* void getValue (in nsPluginInstanceVariable aVariable, in voidPtr aValue); */
  NS_IMETHOD GetValue(nsPluginInstanceVariable aVariable, void * aValue) = 0;

  /**
     * Handles an event. An nsIEventHandler can also get registered with with
     * nsIPluginManager2::RegisterWindow and will be called whenever an event
     * comes in for that window.
     *
     * Note that for Unix and Mac the nsPluginEvent structure is different
     * from the old NPEvent structure -- it's no longer the native event
     * record, but is instead a struct. This was done for future extensibility,
     * and so that the Mac could receive the window argument too. For Windows
     * and OS2, it's always been a struct, so there's no change for them.
     *
     * (Corresponds to NPP_HandleEvent.)
     *
     * @param aEvent   - the event to be handled
     * @param aHandled - set to PR_TRUE if event was handled
     * @result - NS_OK if this operation was successful
     */
  /* void handleEvent (in nsPluginEventPtr aEvent, out boolean aHandled); */
  NS_IMETHOD HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginInstance, NS_IPLUGININSTANCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGININSTANCE \
  NS_IMETHOD Initialize(nsIPluginInstancePeer *aPeer); \
  NS_IMETHOD GetPeer(nsIPluginInstancePeer * *aPeer); \
  NS_IMETHOD Start(void); \
  NS_IMETHOD Stop(void); \
  NS_IMETHOD Destroy(void); \
  NS_IMETHOD SetWindow(nsPluginWindow * aWindow); \
  NS_IMETHOD NewStream(nsIPluginStreamListener **aListener NS_OUTPARAM); \
  NS_IMETHOD Print(nsPluginPrint * aPlatformPrint); \
  NS_IMETHOD GetValue(nsPluginInstanceVariable aVariable, void * aValue); \
  NS_IMETHOD HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGININSTANCE(_to) \
  NS_IMETHOD Initialize(nsIPluginInstancePeer *aPeer) { return _to Initialize(aPeer); } \
  NS_IMETHOD GetPeer(nsIPluginInstancePeer * *aPeer) { return _to GetPeer(aPeer); } \
  NS_IMETHOD Start(void) { return _to Start(); } \
  NS_IMETHOD Stop(void) { return _to Stop(); } \
  NS_IMETHOD Destroy(void) { return _to Destroy(); } \
  NS_IMETHOD SetWindow(nsPluginWindow * aWindow) { return _to SetWindow(aWindow); } \
  NS_IMETHOD NewStream(nsIPluginStreamListener **aListener NS_OUTPARAM) { return _to NewStream(aListener); } \
  NS_IMETHOD Print(nsPluginPrint * aPlatformPrint) { return _to Print(aPlatformPrint); } \
  NS_IMETHOD GetValue(nsPluginInstanceVariable aVariable, void * aValue) { return _to GetValue(aVariable, aValue); } \
  NS_IMETHOD HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM) { return _to HandleEvent(aEvent, aHandled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGININSTANCE(_to) \
  NS_IMETHOD Initialize(nsIPluginInstancePeer *aPeer) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(aPeer); } \
  NS_IMETHOD GetPeer(nsIPluginInstancePeer * *aPeer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPeer(aPeer); } \
  NS_IMETHOD Start(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(); } \
  NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_IMETHOD Destroy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_IMETHOD SetWindow(nsPluginWindow * aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindow(aWindow); } \
  NS_IMETHOD NewStream(nsIPluginStreamListener **aListener NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewStream(aListener); } \
  NS_IMETHOD Print(nsPluginPrint * aPlatformPrint) { return !_to ? NS_ERROR_NULL_POINTER : _to->Print(aPlatformPrint); } \
  NS_IMETHOD GetValue(nsPluginInstanceVariable aVariable, void * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aVariable, aValue); } \
  NS_IMETHOD HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(aEvent, aHandled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginInstance : public nsIPluginInstance
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGININSTANCE

  nsPluginInstance();

private:
  ~nsPluginInstance();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginInstance, nsIPluginInstance)

nsPluginInstance::nsPluginInstance()
{
  /* member initializers and constructor code */
}

nsPluginInstance::~nsPluginInstance()
{
  /* destructor code */
}

/* void initialize (in nsIPluginInstancePeer aPeer); */
NS_IMETHODIMP nsPluginInstance::Initialize(nsIPluginInstancePeer *aPeer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPluginInstancePeer peer; */
NS_IMETHODIMP nsPluginInstance::GetPeer(nsIPluginInstancePeer * *aPeer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void start (); */
NS_IMETHODIMP nsPluginInstance::Start()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsPluginInstance::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroy (); */
NS_IMETHODIMP nsPluginInstance::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWindow (in nsPluginWindowPtr aWindow); */
NS_IMETHODIMP nsPluginInstance::SetWindow(nsPluginWindow * aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newStream (out nsIPluginStreamListener aListener); */
NS_IMETHODIMP nsPluginInstance::NewStream(nsIPluginStreamListener **aListener NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void print (in nsPluginPrintPtr aPlatformPrint); */
NS_IMETHODIMP nsPluginInstance::Print(nsPluginPrint * aPlatformPrint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getValue (in nsPluginInstanceVariable aVariable, in voidPtr aValue); */
NS_IMETHODIMP nsPluginInstance::GetValue(nsPluginInstanceVariable aVariable, void * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleEvent (in nsPluginEventPtr aEvent, out boolean aHandled); */
NS_IMETHODIMP nsPluginInstance::HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginInstance_h__ */
