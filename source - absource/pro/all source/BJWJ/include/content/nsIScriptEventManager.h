/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIScriptEventManager.idl
 */

#ifndef __gen_nsIScriptEventManager_h__
#define __gen_nsIScriptEventManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScriptEventManager */
#define NS_ISCRIPTEVENTMANAGER_IID_STR "b6427ace-dc77-495b-ab21-43baeb52bc27"

#define NS_ISCRIPTEVENTMANAGER_IID \
  {0xb6427ace, 0xdc77, 0x495b, \
    { 0xab, 0x21, 0x43, 0xba, 0xeb, 0x52, 0xbc, 0x27 }}

class NS_NO_VTABLE nsIScriptEventManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTEVENTMANAGER_IID)

  /* nsISupports FindEventHandler (in AString aObjectName, in AString aEventName, in unsigned long aArgCount); */
  NS_IMETHOD FindEventHandler(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, nsISupports **_retval NS_OUTPARAM) = 0;

  /* void InvokeEventHandler (in nsISupports aHandler, in nsISupports aTargetObject, in voidPtr aArgs, in unsigned long aArgCount); */
  NS_IMETHOD InvokeEventHandler(nsISupports *aHandler, nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptEventManager, NS_ISCRIPTEVENTMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTEVENTMANAGER \
  NS_IMETHOD FindEventHandler(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, nsISupports **_retval NS_OUTPARAM); \
  NS_IMETHOD InvokeEventHandler(nsISupports *aHandler, nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTEVENTMANAGER(_to) \
  NS_IMETHOD FindEventHandler(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, nsISupports **_retval NS_OUTPARAM) { return _to FindEventHandler(aObjectName, aEventName, aArgCount, _retval); } \
  NS_IMETHOD InvokeEventHandler(nsISupports *aHandler, nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount) { return _to InvokeEventHandler(aHandler, aTargetObject, aArgs, aArgCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTEVENTMANAGER(_to) \
  NS_IMETHOD FindEventHandler(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEventHandler(aObjectName, aEventName, aArgCount, _retval); } \
  NS_IMETHOD InvokeEventHandler(nsISupports *aHandler, nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvokeEventHandler(aHandler, aTargetObject, aArgs, aArgCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptEventManager : public nsIScriptEventManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTEVENTMANAGER

  nsScriptEventManager();

private:
  ~nsScriptEventManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptEventManager, nsIScriptEventManager)

nsScriptEventManager::nsScriptEventManager()
{
  /* member initializers and constructor code */
}

nsScriptEventManager::~nsScriptEventManager()
{
  /* destructor code */
}

/* nsISupports FindEventHandler (in AString aObjectName, in AString aEventName, in unsigned long aArgCount); */
NS_IMETHODIMP nsScriptEventManager::FindEventHandler(const nsAString & aObjectName, const nsAString & aEventName, PRUint32 aArgCount, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void InvokeEventHandler (in nsISupports aHandler, in nsISupports aTargetObject, in voidPtr aArgs, in unsigned long aArgCount); */
NS_IMETHODIMP nsScriptEventManager::InvokeEventHandler(nsISupports *aHandler, nsISupports *aTargetObject, void * aArgs, PRUint32 aArgCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptEventManager_h__ */
