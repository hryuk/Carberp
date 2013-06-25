/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIEventHandler.idl
 */

#ifndef __gen_nsIEventHandler_h__
#define __gen_nsIEventHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsplugindefs.h"

/* starting interface:    nsIEventHandler */
#define NS_IEVENTHANDLER_IID_STR "a447ddf0-1a99-11d2-815f-006008119d7a"

#define NS_IEVENTHANDLER_IID \
  {0xa447ddf0, 0x1a99, 0x11d2, \
    { 0x81, 0x5f, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

class NS_NO_VTABLE nsIEventHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEVENTHANDLER_IID)

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
   * @result         - NS_OK if this operation was successful
   */
  /* void handleEvent (in nsPluginEventPtr aEvent, out boolean aHandled); */
  NS_IMETHOD HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEventHandler, NS_IEVENTHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEVENTHANDLER \
  NS_IMETHOD HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEVENTHANDLER(_to) \
  NS_IMETHOD HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM) { return _to HandleEvent(aEvent, aHandled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEVENTHANDLER(_to) \
  NS_IMETHOD HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(aEvent, aHandled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEventHandler : public nsIEventHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEVENTHANDLER

  nsEventHandler();

private:
  ~nsEventHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEventHandler, nsIEventHandler)

nsEventHandler::nsEventHandler()
{
  /* member initializers and constructor code */
}

nsEventHandler::~nsEventHandler()
{
  /* destructor code */
}

/* void handleEvent (in nsPluginEventPtr aEvent, out boolean aHandled); */
NS_IMETHODIMP nsEventHandler::HandleEvent(nsPluginEvent * aEvent, PRBool *aHandled NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEventHandler_h__ */
