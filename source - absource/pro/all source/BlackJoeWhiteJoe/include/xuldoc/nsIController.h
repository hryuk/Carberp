/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xul/document/public/nsIController.idl
 */

#ifndef __gen_nsIController_h__
#define __gen_nsIController_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIController */
#define NS_ICONTROLLER_IID_STR "d5b61b82-1da4-11d3-bf87-00105a1b0627"

#define NS_ICONTROLLER_IID \
  {0xd5b61b82, 0x1da4, 0x11d3, \
    { 0xbf, 0x87, 0x00, 0x10, 0x5a, 0x1b, 0x06, 0x27 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIController : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTROLLER_IID)

  /* boolean isCommandEnabled (in string command); */
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *command, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean supportsCommand (in string command); */
  NS_SCRIPTABLE NS_IMETHOD SupportsCommand(const char *command, PRBool *_retval NS_OUTPARAM) = 0;

  /* void doCommand (in string command); */
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *command) = 0;

  /* void onEvent (in string eventName); */
  NS_SCRIPTABLE NS_IMETHOD OnEvent(const char *eventName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIController, NS_ICONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTROLLER \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *command, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SupportsCommand(const char *command, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *command); \
  NS_SCRIPTABLE NS_IMETHOD OnEvent(const char *eventName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *command, PRBool *_retval NS_OUTPARAM) { return _to IsCommandEnabled(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SupportsCommand(const char *command, PRBool *_retval NS_OUTPARAM) { return _to SupportsCommand(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *command) { return _to DoCommand(command); } \
  NS_SCRIPTABLE NS_IMETHOD OnEvent(const char *eventName) { return _to OnEvent(eventName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *command, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandEnabled(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SupportsCommand(const char *command, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SupportsCommand(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *command) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(command); } \
  NS_SCRIPTABLE NS_IMETHOD OnEvent(const char *eventName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEvent(eventName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsController : public nsIController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTROLLER

  nsController();

private:
  ~nsController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsController, nsIController)

nsController::nsController()
{
  /* member initializers and constructor code */
}

nsController::~nsController()
{
  /* destructor code */
}

/* boolean isCommandEnabled (in string command); */
NS_IMETHODIMP nsController::IsCommandEnabled(const char *command, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean supportsCommand (in string command); */
NS_IMETHODIMP nsController::SupportsCommand(const char *command, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommand (in string command); */
NS_IMETHODIMP nsController::DoCommand(const char *command)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEvent (in string eventName); */
NS_IMETHODIMP nsController::OnEvent(const char *eventName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsICommandParams; /* forward declaration */


/* starting interface:    nsICommandController */
#define NS_ICOMMANDCONTROLLER_IID_STR "ebe55080-c8a9-11d5-a73c-dd620d6e04bc"

#define NS_ICOMMANDCONTROLLER_IID \
  {0xebe55080, 0xc8a9, 0x11d5, \
    { 0xa7, 0x3c, 0xdd, 0x62, 0x0d, 0x6e, 0x04, 0xbc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICommandController : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDCONTROLLER_IID)

  /* void getCommandStateWithParams (in string command, in nsICommandParams aCommandParams); */
  NS_SCRIPTABLE NS_IMETHOD GetCommandStateWithParams(const char *command, nsICommandParams *aCommandParams) = 0;

  /* void doCommandWithParams (in string command, in nsICommandParams aCommandParams); */
  NS_SCRIPTABLE NS_IMETHOD DoCommandWithParams(const char *command, nsICommandParams *aCommandParams) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandController, NS_ICOMMANDCONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDCONTROLLER \
  NS_SCRIPTABLE NS_IMETHOD GetCommandStateWithParams(const char *command, nsICommandParams *aCommandParams); \
  NS_SCRIPTABLE NS_IMETHOD DoCommandWithParams(const char *command, nsICommandParams *aCommandParams); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDCONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCommandStateWithParams(const char *command, nsICommandParams *aCommandParams) { return _to GetCommandStateWithParams(command, aCommandParams); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommandWithParams(const char *command, nsICommandParams *aCommandParams) { return _to DoCommandWithParams(command, aCommandParams); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDCONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCommandStateWithParams(const char *command, nsICommandParams *aCommandParams) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommandStateWithParams(command, aCommandParams); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommandWithParams(const char *command, nsICommandParams *aCommandParams) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommandWithParams(command, aCommandParams); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandController : public nsICommandController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDCONTROLLER

  nsCommandController();

private:
  ~nsCommandController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandController, nsICommandController)

nsCommandController::nsCommandController()
{
  /* member initializers and constructor code */
}

nsCommandController::~nsCommandController()
{
  /* destructor code */
}

/* void getCommandStateWithParams (in string command, in nsICommandParams aCommandParams); */
NS_IMETHODIMP nsCommandController::GetCommandStateWithParams(const char *command, nsICommandParams *aCommandParams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommandWithParams (in string command, in nsICommandParams aCommandParams); */
NS_IMETHODIMP nsCommandController::DoCommandWithParams(const char *command, nsICommandParams *aCommandParams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIControllerCommandGroup */
#define NS_ICONTROLLERCOMMANDGROUP_IID_STR "9f82c404-1c7b-11d5-a73c-eca43ca836fc"

#define NS_ICONTROLLERCOMMANDGROUP_IID \
  {0x9f82c404, 0x1c7b, 0x11d5, \
    { 0xa7, 0x3c, 0xec, 0xa4, 0x3c, 0xa8, 0x36, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIControllerCommandGroup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTROLLERCOMMANDGROUP_IID)

  /* void addCommandToGroup (in string aCommand, in string aGroup); */
  NS_SCRIPTABLE NS_IMETHOD AddCommandToGroup(const char *aCommand, const char *aGroup) = 0;

  /* void removeCommandFromGroup (in string aCommand, in string aGroup); */
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandFromGroup(const char *aCommand, const char *aGroup) = 0;

  /* boolean isCommandInGroup (in string aCommand, in string aGroup); */
  NS_SCRIPTABLE NS_IMETHOD IsCommandInGroup(const char *aCommand, const char *aGroup, PRBool *_retval NS_OUTPARAM) = 0;

  /* nsISimpleEnumerator getGroupsEnumerator (); */
  NS_SCRIPTABLE NS_IMETHOD GetGroupsEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /* nsISimpleEnumerator getEnumeratorForGroup (in string aGroup); */
  NS_SCRIPTABLE NS_IMETHOD GetEnumeratorForGroup(const char *aGroup, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIControllerCommandGroup, NS_ICONTROLLERCOMMANDGROUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTROLLERCOMMANDGROUP \
  NS_SCRIPTABLE NS_IMETHOD AddCommandToGroup(const char *aCommand, const char *aGroup); \
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandFromGroup(const char *aCommand, const char *aGroup); \
  NS_SCRIPTABLE NS_IMETHOD IsCommandInGroup(const char *aCommand, const char *aGroup, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetGroupsEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEnumeratorForGroup(const char *aGroup, nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTROLLERCOMMANDGROUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddCommandToGroup(const char *aCommand, const char *aGroup) { return _to AddCommandToGroup(aCommand, aGroup); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandFromGroup(const char *aCommand, const char *aGroup) { return _to RemoveCommandFromGroup(aCommand, aGroup); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandInGroup(const char *aCommand, const char *aGroup, PRBool *_retval NS_OUTPARAM) { return _to IsCommandInGroup(aCommand, aGroup, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetGroupsEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetGroupsEnumerator(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnumeratorForGroup(const char *aGroup, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetEnumeratorForGroup(aGroup, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTROLLERCOMMANDGROUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddCommandToGroup(const char *aCommand, const char *aGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCommandToGroup(aCommand, aGroup); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandFromGroup(const char *aCommand, const char *aGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveCommandFromGroup(aCommand, aGroup); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandInGroup(const char *aCommand, const char *aGroup, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandInGroup(aCommand, aGroup, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetGroupsEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGroupsEnumerator(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnumeratorForGroup(const char *aGroup, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumeratorForGroup(aGroup, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsControllerCommandGroup : public nsIControllerCommandGroup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTROLLERCOMMANDGROUP

  nsControllerCommandGroup();

private:
  ~nsControllerCommandGroup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsControllerCommandGroup, nsIControllerCommandGroup)

nsControllerCommandGroup::nsControllerCommandGroup()
{
  /* member initializers and constructor code */
}

nsControllerCommandGroup::~nsControllerCommandGroup()
{
  /* destructor code */
}

/* void addCommandToGroup (in string aCommand, in string aGroup); */
NS_IMETHODIMP nsControllerCommandGroup::AddCommandToGroup(const char *aCommand, const char *aGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeCommandFromGroup (in string aCommand, in string aGroup); */
NS_IMETHODIMP nsControllerCommandGroup::RemoveCommandFromGroup(const char *aCommand, const char *aGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCommandInGroup (in string aCommand, in string aGroup); */
NS_IMETHODIMP nsControllerCommandGroup::IsCommandInGroup(const char *aCommand, const char *aGroup, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getGroupsEnumerator (); */
NS_IMETHODIMP nsControllerCommandGroup::GetGroupsEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getEnumeratorForGroup (in string aGroup); */
NS_IMETHODIMP nsControllerCommandGroup::GetEnumeratorForGroup(const char *aGroup, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIController_h__ */
