/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIScriptEventHandler.idl
 */

#ifndef __gen_nsIScriptEventHandler_h__
#define __gen_nsIScriptEventHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScriptEventHandler */
#define NS_ISCRIPTEVENTHANDLER_IID_STR "375f787f-8d3a-4344-b540-293d5645c22c"

#define NS_ISCRIPTEVENTHANDLER_IID \
  {0x375f787f, 0x8d3a, 0x4344, \
    { 0xb5, 0x40, 0x29, 0x3d, 0x56, 0x45, 0xc2, 0x2c }}

class NS_NO_VTABLE nsIScriptEventHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTEVENTHANDLER_IID)

  /**
  * IsSameEvent:
  *
  * Determines if this script event handler is bound to the given
  * object and event name.
  *
  * @param aObjectName  Name of the object raising the event.
  *
  * @param aEventName   Name of the event being raised.
  *
  * @param aArgCount    Number of arguments expected by the event handler.
  *
  */
  /* boolean IsSameEvent (in AString aObjectName, in AString aEventName, in unsigned long aArgCount); */
  NS_IMETHOD IsSameEvent(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, PRBool *_retval NS_OUTPARAM) = 0;

  /**
  * Invoke:
  *
  * Executes this script handler.
  *
  * @param aTargetObject  Object to which the script handler is bound.
  *
  * @param aArgs          Array of arguments passed to the script handler.
  *                       This is an array of jsvals.
  *
  * @param aArgCount      Number of elements in the aArgs array.
  *
  */
  /* void Invoke (in nsISupports aTargetObject, in voidPtr aArgs, in unsigned long aArgCount); */
  NS_IMETHOD Invoke(nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptEventHandler, NS_ISCRIPTEVENTHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTEVENTHANDLER \
  NS_IMETHOD IsSameEvent(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD Invoke(nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTEVENTHANDLER(_to) \
  NS_IMETHOD IsSameEvent(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, PRBool *_retval NS_OUTPARAM) { return _to IsSameEvent(aObjectName, aEventName, aArgCount, _retval); } \
  NS_IMETHOD Invoke(nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount) { return _to Invoke(aTargetObject, aArgs, aArgCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTEVENTHANDLER(_to) \
  NS_IMETHOD IsSameEvent(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSameEvent(aObjectName, aEventName, aArgCount, _retval); } \
  NS_IMETHOD Invoke(nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->Invoke(aTargetObject, aArgs, aArgCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptEventHandler : public nsIScriptEventHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTEVENTHANDLER

  nsScriptEventHandler();

private:
  ~nsScriptEventHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptEventHandler, nsIScriptEventHandler)

nsScriptEventHandler::nsScriptEventHandler()
{
  /* member initializers and constructor code */
}

nsScriptEventHandler::~nsScriptEventHandler()
{
  /* destructor code */
}

/* boolean IsSameEvent (in AString aObjectName, in AString aEventName, in unsigned long aArgCount); */
NS_IMETHODIMP nsScriptEventHandler::IsSameEvent(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Invoke (in nsISupports aTargetObject, in voidPtr aArgs, in unsigned long aArgCount); */
NS_IMETHODIMP nsScriptEventHandler::Invoke(nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptEventHandler_h__ */
