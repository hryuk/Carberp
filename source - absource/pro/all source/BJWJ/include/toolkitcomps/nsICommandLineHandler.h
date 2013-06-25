/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/commandlines/public/nsICommandLineHandler.idl
 */

#ifndef __gen_nsICommandLineHandler_h__
#define __gen_nsICommandLineHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICommandLine; /* forward declaration */


/* starting interface:    nsICommandLineHandler */
#define NS_ICOMMANDLINEHANDLER_IID_STR "d4b123df-51ee-48b1-a663-002180e60d3b"

#define NS_ICOMMANDLINEHANDLER_IID \
  {0xd4b123df, 0x51ee, 0x48b1, \
    { 0xa6, 0x63, 0x00, 0x21, 0x80, 0xe6, 0x0d, 0x3b }}

/**
 * Handles arguments on the command line of an XUL application.
 *
 * Each handler is registered in the category "command-line-handler".
 * The entries in this category are read in alphabetical order, and each
 * category value is treated as a service contractid implementing this
 * interface.
 *
 * By convention, handler with ordinary priority should begin with "m".
 *
 * Example:
 * Category             Entry          Value
 * command-line-handler b-jsdebug      @mozilla.org/venkman/clh;1
 * command-line-handler c-extensions   @mozilla.org/extension-manager/clh;1
 * command-line-handler m-edit         @mozilla.org/composer/clh;1
 * command-line-handler m-irc          @mozilla.org/chatzilla/clh;1
 * command-line-handler y-final        @mozilla.org/browser/clh-final;1
 *
 * @status UNDER_REVIEW This interface is intended to be frozen, but it isn't
 *                      frozen yet. Be careful!
 * @note What do we do about localizing helpInfo? Do we make each handler do it,
 *       or provide a generic solution of some sort? Don't freeze this interface
 *       without thinking about this!
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICommandLineHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDLINEHANDLER_IID)

  /**
   * Process a command line. If this handler finds arguments that it
   * understands, it should perform the appropriate actions (such as opening
   * a window), and remove the arguments from the command-line array.
   *
   * @throw NS_ERROR_ABORT to immediately cease command-line handling
   *        (if this is STATE_INITIAL_LAUNCH, quits the app).
   *        All other exceptions are silently ignored.
   */
  /* void handle (in nsICommandLine aCommandLine); */
  NS_SCRIPTABLE NS_IMETHOD Handle(nsICommandLine *aCommandLine) = 0;

  /**
   * When the app is launched with the -help argument, this attribute
   * is retrieved and displayed to the user (on stdout). The text should
   * have embedded newlines which wrap at 76 columns, and should include
   * a newline at the end. By convention, the right column which contains flag
   * descriptions begins at the 24th character.
   */
  /* readonly attribute AUTF8String helpInfo; */
  NS_SCRIPTABLE NS_IMETHOD GetHelpInfo(nsACString & aHelpInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandLineHandler, NS_ICOMMANDLINEHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDLINEHANDLER \
  NS_SCRIPTABLE NS_IMETHOD Handle(nsICommandLine *aCommandLine); \
  NS_SCRIPTABLE NS_IMETHOD GetHelpInfo(nsACString & aHelpInfo); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDLINEHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Handle(nsICommandLine *aCommandLine) { return _to Handle(aCommandLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetHelpInfo(nsACString & aHelpInfo) { return _to GetHelpInfo(aHelpInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDLINEHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Handle(nsICommandLine *aCommandLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->Handle(aCommandLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetHelpInfo(nsACString & aHelpInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHelpInfo(aHelpInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandLineHandler : public nsICommandLineHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDLINEHANDLER

  nsCommandLineHandler();

private:
  ~nsCommandLineHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandLineHandler, nsICommandLineHandler)

nsCommandLineHandler::nsCommandLineHandler()
{
  /* member initializers and constructor code */
}

nsCommandLineHandler::~nsCommandLineHandler()
{
  /* destructor code */
}

/* void handle (in nsICommandLine aCommandLine); */
NS_IMETHODIMP nsCommandLineHandler::Handle(nsICommandLine *aCommandLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String helpInfo; */
NS_IMETHODIMP nsCommandLineHandler::GetHelpInfo(nsACString & aHelpInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICommandLineHandler_h__ */
