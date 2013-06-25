/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/commandhandler/public/nsICommandManager.idl
 */

#ifndef __gen_nsICommandManager_h__
#define __gen_nsICommandManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIObserver_h__
#include "nsIObserver.h"
#endif

#ifndef __gen_nsICommandParams_h__
#include "nsICommandParams.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsICommandManager */
#define NS_ICOMMANDMANAGER_IID_STR "080d2001-f91e-11d4-a73c-f9242928207c"

#define NS_ICOMMANDMANAGER_IID \
  {0x080d2001, 0xf91e, 0x11d4, \
    { 0xa7, 0x3c, 0xf9, 0x24, 0x29, 0x28, 0x20, 0x7c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICommandManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDMANAGER_IID)

  /* void addCommandObserver (in nsIObserver aCommandObserver, in string aCommandToObserve); */
  NS_SCRIPTABLE NS_IMETHOD AddCommandObserver(nsIObserver *aCommandObserver, const char *aCommandToObserve) = 0;

  /* void removeCommandObserver (in nsIObserver aCommandObserver, in string aCommandObserved); */
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandObserver(nsIObserver *aCommandObserver, const char *aCommandObserved) = 0;

  /* boolean isCommandSupported (in string aCommandName, in nsIDOMWindow aTargetWindow); */
  NS_SCRIPTABLE NS_IMETHOD IsCommandSupported(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean isCommandEnabled (in string aCommandName, in nsIDOMWindow aTargetWindow); */
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM) = 0;

  /* void getCommandState (in string aCommandName, in nsIDOMWindow aTargetWindow, in nsICommandParams aCommandParams); */
  NS_SCRIPTABLE NS_IMETHOD GetCommandState(const char *aCommandName, nsIDOMWindow *aTargetWindow, nsICommandParams *aCommandParams) = 0;

  /* void doCommand (in string aCommandName, in nsICommandParams aCommandParams, in nsIDOMWindow aTargetWindow); */
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsICommandParams *aCommandParams, nsIDOMWindow *aTargetWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandManager, NS_ICOMMANDMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDMANAGER \
  NS_SCRIPTABLE NS_IMETHOD AddCommandObserver(nsIObserver *aCommandObserver, const char *aCommandToObserve); \
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandObserver(nsIObserver *aCommandObserver, const char *aCommandObserved); \
  NS_SCRIPTABLE NS_IMETHOD IsCommandSupported(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCommandState(const char *aCommandName, nsIDOMWindow *aTargetWindow, nsICommandParams *aCommandParams); \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsICommandParams *aCommandParams, nsIDOMWindow *aTargetWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddCommandObserver(nsIObserver *aCommandObserver, const char *aCommandToObserve) { return _to AddCommandObserver(aCommandObserver, aCommandToObserve); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandObserver(nsIObserver *aCommandObserver, const char *aCommandObserved) { return _to RemoveCommandObserver(aCommandObserver, aCommandObserved); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandSupported(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM) { return _to IsCommandSupported(aCommandName, aTargetWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM) { return _to IsCommandEnabled(aCommandName, aTargetWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommandState(const char *aCommandName, nsIDOMWindow *aTargetWindow, nsICommandParams *aCommandParams) { return _to GetCommandState(aCommandName, aTargetWindow, aCommandParams); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsICommandParams *aCommandParams, nsIDOMWindow *aTargetWindow) { return _to DoCommand(aCommandName, aCommandParams, aTargetWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddCommandObserver(nsIObserver *aCommandObserver, const char *aCommandToObserve) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCommandObserver(aCommandObserver, aCommandToObserve); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandObserver(nsIObserver *aCommandObserver, const char *aCommandObserved) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveCommandObserver(aCommandObserver, aCommandObserved); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandSupported(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandSupported(aCommandName, aTargetWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandEnabled(aCommandName, aTargetWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommandState(const char *aCommandName, nsIDOMWindow *aTargetWindow, nsICommandParams *aCommandParams) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommandState(aCommandName, aTargetWindow, aCommandParams); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsICommandParams *aCommandParams, nsIDOMWindow *aTargetWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(aCommandName, aCommandParams, aTargetWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandManager : public nsICommandManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDMANAGER

  nsCommandManager();

private:
  ~nsCommandManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandManager, nsICommandManager)

nsCommandManager::nsCommandManager()
{
  /* member initializers and constructor code */
}

nsCommandManager::~nsCommandManager()
{
  /* destructor code */
}

/* void addCommandObserver (in nsIObserver aCommandObserver, in string aCommandToObserve); */
NS_IMETHODIMP nsCommandManager::AddCommandObserver(nsIObserver *aCommandObserver, const char *aCommandToObserve)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeCommandObserver (in nsIObserver aCommandObserver, in string aCommandObserved); */
NS_IMETHODIMP nsCommandManager::RemoveCommandObserver(nsIObserver *aCommandObserver, const char *aCommandObserved)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCommandSupported (in string aCommandName, in nsIDOMWindow aTargetWindow); */
NS_IMETHODIMP nsCommandManager::IsCommandSupported(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCommandEnabled (in string aCommandName, in nsIDOMWindow aTargetWindow); */
NS_IMETHODIMP nsCommandManager::IsCommandEnabled(const char *aCommandName, nsIDOMWindow *aTargetWindow, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCommandState (in string aCommandName, in nsIDOMWindow aTargetWindow, in nsICommandParams aCommandParams); */
NS_IMETHODIMP nsCommandManager::GetCommandState(const char *aCommandName, nsIDOMWindow *aTargetWindow, nsICommandParams *aCommandParams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommand (in string aCommandName, in nsICommandParams aCommandParams, in nsIDOMWindow aTargetWindow); */
NS_IMETHODIMP nsCommandManager::DoCommand(const char *aCommandName, nsICommandParams *aCommandParams, nsIDOMWindow *aTargetWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_COMMAND_MANAGER_CID \
{ 0x64edb481, 0x0c04, 0x11d5, { 0xa7, 0x3c, 0xe9, 0x64, 0xb9, 0x68, 0xb0, 0xbc } }
#define NS_COMMAND_MANAGER_CONTRACTID \
 "@mozilla.org/embedcomp/command-manager;1"

#endif /* __gen_nsICommandManager_h__ */
