/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/commandhandler/public/nsIControllerCommand.idl
 */

#ifndef __gen_nsIControllerCommand_h__
#define __gen_nsIControllerCommand_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsICommandParams_h__
#include "nsICommandParams.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIControllerCommand */
#define NS_ICONTROLLERCOMMAND_IID_STR "0eae9a46-1dd2-11b2-aca0-9176f05fe9db"

#define NS_ICONTROLLERCOMMAND_IID \
  {0x0eae9a46, 0x1dd2, 0x11b2, \
    { 0xac, 0xa0, 0x91, 0x76, 0xf0, 0x5f, 0xe9, 0xdb }}

/**
 * nsIControllerCommand
 *
 * A generic command interface. You can register an nsIControllerCommand
 * with the nsIControllerCommandTable.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIControllerCommand : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTROLLERCOMMAND_IID)

  /**
   * Returns true if the command is currently enabled. An nsIControllerCommand
   * can implement more than one commands; say, a group of related commands
   * (e.g. delete left/delete right). Because of this, the command name is
   * passed to each method.
   *
   * @param aCommandName  the name of the command for which we want the enabled
   *                      state.
   * @param aCommandContext    a cookie held by the nsIControllerCommandTable,
   *                  allowing the command to get some context information.
   *                  The contents of this cookie are implementation-defined.
   */
  /* boolean isCommandEnabled (in string aCommandName, in nsISupports aCommandContext); */
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsISupports *aCommandContext, PRBool *_retval NS_OUTPARAM) = 0;

  /* void getCommandStateParams (in string aCommandName, in nsICommandParams aParams, in nsISupports aCommandContext); */
  NS_SCRIPTABLE NS_IMETHOD GetCommandStateParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) = 0;

  /**
   * Execute the name command.
   *
   * @param aCommandName  the name of the command to execute.
   * 
   * @param aCommandContext    a cookie held by the nsIControllerCommandTable,
   *                  allowing the command to get some context information.
   *                  The contents of this cookie are implementation-defined.
   */
  /* void doCommand (in string aCommandName, in nsISupports aCommandContext); */
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsISupports *aCommandContext) = 0;

  /* void doCommandParams (in string aCommandName, in nsICommandParams aParams, in nsISupports aCommandContext); */
  NS_SCRIPTABLE NS_IMETHOD DoCommandParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIControllerCommand, NS_ICONTROLLERCOMMAND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTROLLERCOMMAND \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsISupports *aCommandContext, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCommandStateParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext); \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsISupports *aCommandContext); \
  NS_SCRIPTABLE NS_IMETHOD DoCommandParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTROLLERCOMMAND(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsISupports *aCommandContext, PRBool *_retval NS_OUTPARAM) { return _to IsCommandEnabled(aCommandName, aCommandContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommandStateParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) { return _to GetCommandStateParams(aCommandName, aParams, aCommandContext); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsISupports *aCommandContext) { return _to DoCommand(aCommandName, aCommandContext); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommandParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) { return _to DoCommandParams(aCommandName, aParams, aCommandContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTROLLERCOMMAND(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsCommandEnabled(const char *aCommandName, nsISupports *aCommandContext, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandEnabled(aCommandName, aCommandContext, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCommandStateParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommandStateParams(aCommandName, aParams, aCommandContext); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommand(const char *aCommandName, nsISupports *aCommandContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(aCommandName, aCommandContext); } \
  NS_SCRIPTABLE NS_IMETHOD DoCommandParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommandParams(aCommandName, aParams, aCommandContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsControllerCommand : public nsIControllerCommand
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTROLLERCOMMAND

  nsControllerCommand();

private:
  ~nsControllerCommand();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsControllerCommand, nsIControllerCommand)

nsControllerCommand::nsControllerCommand()
{
  /* member initializers and constructor code */
}

nsControllerCommand::~nsControllerCommand()
{
  /* destructor code */
}

/* boolean isCommandEnabled (in string aCommandName, in nsISupports aCommandContext); */
NS_IMETHODIMP nsControllerCommand::IsCommandEnabled(const char *aCommandName, nsISupports *aCommandContext, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCommandStateParams (in string aCommandName, in nsICommandParams aParams, in nsISupports aCommandContext); */
NS_IMETHODIMP nsControllerCommand::GetCommandStateParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommand (in string aCommandName, in nsISupports aCommandContext); */
NS_IMETHODIMP nsControllerCommand::DoCommand(const char *aCommandName, nsISupports *aCommandContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommandParams (in string aCommandName, in nsICommandParams aParams, in nsISupports aCommandContext); */
NS_IMETHODIMP nsControllerCommand::DoCommandParams(const char *aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIControllerCommand_h__ */
