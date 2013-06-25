/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/commandhandler/public/nsIControllerCommandTable.idl
 */

#ifndef __gen_nsIControllerCommandTable_h__
#define __gen_nsIControllerCommandTable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIControllerCommand_h__
#include "nsIControllerCommand.h"
#endif

#ifndef __gen_nsICommandParams_h__
#include "nsICommandParams.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIControllerCommandTable */
#define NS_ICONTROLLERCOMMANDTABLE_IID_STR "d1a47834-6ad4-11d7-bfad-000393636592"

#define NS_ICONTROLLERCOMMANDTABLE_IID \
  {0xd1a47834, 0x6ad4, 0x11d7, \
    { 0xbf, 0xad, 0x00, 0x03, 0x93, 0x63, 0x65, 0x92 }}

/**
 * nsIControllerCommandTable
 * 
 * An interface via which a controller can maintain a series of commands,
 * and efficiently dispatch commands to their respective handlers.
 *
 * Controllers that use an nsIControllerCommandTable should support
 * nsIInterfaceRequestor, and be able to return an interface to their
 * controller command table via getInterface().
 * 
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIControllerCommandTable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTROLLERCOMMANDTABLE_IID)

  /**
   * Make this command table immutable, so that commands cannot
   * be registered or unregistered. Some command tables are made
   * mutable after command registration so that they can be 
   * used as singletons.
   */
  /* void makeImmutable (); */
  NS_SCRIPTABLE NS_IMETHOD MakeImmutable(void) = 0;

  /**
   * Register and unregister commands with the command table.
   *
   * @param aCommandName  the name of the command under which to register or
   *                      unregister the given command handler.
   *
   * @param aCommand      the handler for this command.
   */
  /* void registerCommand (in string aCommandName, in nsIControllerCommand aCommand); */
  NS_SCRIPTABLE NS_IMETHOD RegisterCommand(const char *aCommandName, nsIControllerCommand *aCommand) = 0;

  /* void unregisterCommand (in string aCommandName, in nsIControllerCommand aCommand); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterCommand(const char *aCommandName, nsIControllerCommand *aCommand) = 0;

  /**
   * Find the command handler which has been registered to handle the named command.
   *
   * @param aCommandName  the name of the command to find the handler for.
   */
  /* nsIControllerCommand findCommandHandler (in string aCommandName); */
  NS_SCRIPTABLE NS_IMETHOD FindCommandHandler(const char *aCommandName, nsIControllerCommand **_retval NS_OUTPARAM) = 0;

  /**
   * Get whether the named command is enabled.
   *
   * @param aCommandName    the name of the command to test
   * @param aCommandRefCon  the command context data
   */
  /* boolean isCommandEnabled (in string aCommandName, in nsISupports aCommandRefCon); */
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Tell the command to update its state (if it is a state updating command)
   *
   * @param aCommandName    the name of the command to update
   * @param aCommandRefCon  the command context data
   */
  /* void updateCommandState (in string aCommandName, in nsISupports aCommandRefCon); */
  NS_SCRIPTABLE NS_IMETHOD UpdateCommandState(const char *aCommandName, nsISupports *aCommandRefCon) = 0;

  /**
   * Get whether the named command is supported.
   *
   * @param aCommandName    the name of the command to test
   * @param aCommandRefCon  the command context data
   */
  /* boolean supportsCommand (in string aCommandName, in nsISupports aCommandRefCon); */
  NS_SCRIPTABLE NS_IMETHOD SupportsCommand(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Execute the named command.
   *
   * @param aCommandName    the name of the command to execute
   * @param aCommandRefCon  the command context data
   */
  /* void doCommand (in string aCommandName, in nsISupports aCommandRefCon); */
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsISupports *aCommandRefCon) = 0;

  /* void doCommandParams (in string aCommandName, in nsICommandParams aParam, in nsISupports aCommandRefCon); */
  NS_SCRIPTABLE NS_IMETHOD DoCommandParams(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) = 0;

  /* void getCommandState (in string aCommandName, in nsICommandParams aParam, in nsISupports aCommandRefCon); */
  NS_SCRIPTABLE NS_IMETHOD GetCommandState(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIControllerCommandTable, NS_ICONTROLLERCOMMANDTABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTROLLERCOMMANDTABLE \
  NS_SCRIPTABLE NS_IMETHOD MakeImmutable(void); \
  NS_SCRIPTABLE NS_IMETHOD RegisterCommand(const char *aCommandName, nsIControllerCommand *aCommand); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterCommand(const char *aCommandName, nsIControllerCommand *aCommand); \
  NS_SCRIPTABLE NS_IMETHOD FindCommandHandler(const char *aCommandName, nsIControllerCommand **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD UpdateCommandState(const char *aCommandName, nsISupports *aCommandRefCon); \
  NS_SCRIPTABLE NS_IMETHOD SupportsCommand(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsISupports *aCommandRefCon); \
  NS_SCRIPTABLE NS_IMETHOD DoCommandParams(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon); \
  NS_SCRIPTABLE NS_IMETHOD GetCommandState(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTROLLERCOMMANDTABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD MakeImmutable(void) { return _to MakeImmutable(); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterCommand(const char *aCommandName, nsIControllerCommand *aCommand) { return _to RegisterCommand(aCommandName, aCommand); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterCommand(const char *aCommandName, nsIControllerCommand *aCommand) { return _to UnregisterCommand(aCommandName, aCommand); } \
  NS_SCRIPTABLE NS_IMETHOD FindCommandHandler(const char *aCommandName, nsIControllerCommand **_retval NS_OUTPARAM) { return _to FindCommandHandler(aCommandName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM) { return _to IsCommandEnabled(aCommandName, aCommandRefCon, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateCommandState(const char *aCommandName, nsISupports *aCommandRefCon) { return _to UpdateCommandState(aCommandName, aCommandRefCon); } \
  NS_SCRIPTABLE NS_IMETHOD SupportsCommand(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM) { return _to SupportsCommand(aCommandName, aCommandRefCon, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsISupports *aCommandRefCon) { return _to DoCommand(aCommandName, aCommandRefCon); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommandParams(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) { return _to DoCommandParams(aCommandName, aParam, aCommandRefCon); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommandState(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) { return _to GetCommandState(aCommandName, aParam, aCommandRefCon); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTROLLERCOMMANDTABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD MakeImmutable(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeImmutable(); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterCommand(const char *aCommandName, nsIControllerCommand *aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterCommand(aCommandName, aCommand); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterCommand(const char *aCommandName, nsIControllerCommand *aCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterCommand(aCommandName, aCommand); } \
  NS_SCRIPTABLE NS_IMETHOD FindCommandHandler(const char *aCommandName, nsIControllerCommand **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCommandHandler(aCommandName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandEnabled(aCommandName, aCommandRefCon, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateCommandState(const char *aCommandName, nsISupports *aCommandRefCon) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCommandState(aCommandName, aCommandRefCon); } \
  NS_SCRIPTABLE NS_IMETHOD SupportsCommand(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SupportsCommand(aCommandName, aCommandRefCon, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsISupports *aCommandRefCon) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(aCommandName, aCommandRefCon); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommandParams(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommandParams(aCommandName, aParam, aCommandRefCon); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommandState(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommandState(aCommandName, aParam, aCommandRefCon); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsControllerCommandTable : public nsIControllerCommandTable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTROLLERCOMMANDTABLE

  nsControllerCommandTable();

private:
  ~nsControllerCommandTable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsControllerCommandTable, nsIControllerCommandTable)

nsControllerCommandTable::nsControllerCommandTable()
{
  /* member initializers and constructor code */
}

nsControllerCommandTable::~nsControllerCommandTable()
{
  /* destructor code */
}

/* void makeImmutable (); */
NS_IMETHODIMP nsControllerCommandTable::MakeImmutable()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerCommand (in string aCommandName, in nsIControllerCommand aCommand); */
NS_IMETHODIMP nsControllerCommandTable::RegisterCommand(const char *aCommandName, nsIControllerCommand *aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterCommand (in string aCommandName, in nsIControllerCommand aCommand); */
NS_IMETHODIMP nsControllerCommandTable::UnregisterCommand(const char *aCommandName, nsIControllerCommand *aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIControllerCommand findCommandHandler (in string aCommandName); */
NS_IMETHODIMP nsControllerCommandTable::FindCommandHandler(const char *aCommandName, nsIControllerCommand **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCommandEnabled (in string aCommandName, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::IsCommandEnabled(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateCommandState (in string aCommandName, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::UpdateCommandState(const char *aCommandName, nsISupports *aCommandRefCon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean supportsCommand (in string aCommandName, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::SupportsCommand(const char *aCommandName, nsISupports *aCommandRefCon, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommand (in string aCommandName, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::DoCommand(const char *aCommandName, nsISupports *aCommandRefCon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommandParams (in string aCommandName, in nsICommandParams aParam, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::DoCommandParams(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCommandState (in string aCommandName, in nsICommandParams aParam, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::GetCommandState(const char *aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {670ee5da-6ad5-11d7-9950-000393636592}
#define NS_CONTROLLERCOMMANDTABLE_CID \
  {0x670ee5da, 0x6ad5, 0x11d7, \
    { 0x99, 0x50, 0x00, 0x03, 0x93, 0x63, 0x65, 0x92 }}
#define NS_CONTROLLERCOMMANDTABLE_CONTRACTID \
 "@mozilla.org/embedcomp/controller-command-table;1"

#endif /* __gen_nsIControllerCommandTable_h__ */
