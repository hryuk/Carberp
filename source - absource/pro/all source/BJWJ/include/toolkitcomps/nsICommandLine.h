/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/commandlines/public/nsICommandLine.idl
 */

#ifndef __gen_nsICommandLine_h__
#define __gen_nsICommandLine_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsICommandLine */
#define NS_ICOMMANDLINE_IID_STR "bc3173bd-aa46-46a0-9d25-d9867a9659b6"

#define NS_ICOMMANDLINE_IID \
  {0xbc3173bd, 0xaa46, 0x46a0, \
    { 0x9d, 0x25, 0xd9, 0x86, 0x7a, 0x96, 0x59, 0xb6 }}

/**
 * Represents the command line used to invoke a XUL application. This may be the
 * original command-line of this instance, or a command line remoted from another
 * instance of the application.
 *
 * DEFINITIONS:
 * "arguments" are any values found on the command line.
 * "flags" are switches. In normalized form they are preceded by a single dash.
 * Some flags may take "parameters", e.g. "-url <param>" or "-install-xpi <param>"
 *
 * @status UNDER_REVIEW This interface is intended to be frozen, but isn't frozen
 *                      yet. Please use with care.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICommandLine : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDLINE_IID)

  /**
   * Number of arguments in the command line. The application name is not
   * part of the command line.
   */
  /* readonly attribute long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) = 0;

  /**
   * Get an argument from the array of command-line arguments.
   *
   * On windows, flags of the form /flag are normalized to -flag. /flag:param
   * are normalized to -flag param.
   *
   * On *nix and mac flags of the form --flag are normalized to -flag. --flag=param
   * are normalized to the form -flag param.
   *
   * @param aIndex The argument to retrieve. This index is 0-based, and does
   *               not include the application name.
   * @return       The indexth argument.
   * @throws       NS_ERROR_INVALID_ARG if aIndex is out of bounds.
   */
  /* AString getArgument (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetArgument(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Find a command-line flag.
   *
   * @param aFlag          The flag name to locate. Do not include the initial
   *                       hyphen.
   * @param aCaseSensitive Whether to do case-sensitive comparisons.
   * @return               The position of the flag in the command line.
   */
  /* long findFlag (in AString aFlag, in boolean aCaseSensitive); */
  NS_SCRIPTABLE NS_IMETHOD FindFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Remove arguments from the command line. This normally occurs after
   * a handler has processed the arguments.
   *
   * @param aStart  Index to begin removing.
   * @param aEnd    Index to end removing, inclusive.
   */
  /* void removeArguments (in long aStart, in long aEnd); */
  NS_SCRIPTABLE NS_IMETHOD RemoveArguments(PRInt32 aStart, PRInt32 aEnd) = 0;

  /**
   * A helper method which will find a flag and remove it in one step.
   *
   * @param aFlag  The flag name to find and remove.
   * @param aCaseSensitive Whether to do case-sensitive comparisons.
   * @return       Whether the flag was found.
   */
  /* boolean handleFlag (in AString aFlag, in boolean aCaseSensitive); */
  NS_SCRIPTABLE NS_IMETHOD HandleFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Find a flag with a parameter and remove both. This is a helper
   * method that combines "findFlag" and "removeArguments" in one step.
   *
   * @return   null (a void astring) if the flag is not found. The parameter value
   *           if found. Note that null and the empty string are not the same.
   * @throws   NS_ERROR_INVALID_ARG if the flag exists without a parameter
   *
   * @param aFlag The flag name to find and remove.
   * @param aCaseSensitive Whether to do case-sensitive flag search.
   */
  /* AString handleFlagWithParam (in AString aFlag, in boolean aCaseSensitive); */
  NS_SCRIPTABLE NS_IMETHOD HandleFlagWithParam(const nsAString & aFlag, PRBool aCaseSensitive, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * The type of command line being processed.
   *
   * STATE_INITIAL_LAUNCH  is the first launch of the application instance.
   * STATE_REMOTE_AUTO     is a remote command line automatically redirected to
   *                       this instance.
   * STATE_REMOTE_EXPLICIT is a remote command line explicitly redirected to
   *                       this instance using xremote/windde/appleevents.
   */
  /* readonly attribute unsigned long state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState) = 0;

  enum { STATE_INITIAL_LAUNCH = 0U };

  enum { STATE_REMOTE_AUTO = 1U };

  enum { STATE_REMOTE_EXPLICIT = 2U };

  /**
   * There may be a command-line handler which performs a default action if
   * there was no explicit action on the command line (open a default browser
   * window, for example). This flag allows the default action to be prevented.
   */
  /* attribute boolean preventDefault; */
  NS_SCRIPTABLE NS_IMETHOD GetPreventDefault(PRBool *aPreventDefault) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPreventDefault(PRBool aPreventDefault) = 0;

  /**
   * The working directory for this command line. Use this property instead
   * of the working directory for the current process, since a redirected
   * command line may have had a different working directory.
   */
  /* readonly attribute nsIFile workingDirectory; */
  NS_SCRIPTABLE NS_IMETHOD GetWorkingDirectory(nsIFile * *aWorkingDirectory) = 0;

  /**
   * A window to be targeted by this command line. In most cases, this will
   * be null (xremote will sometimes set this attribute).
   */
  /* readonly attribute nsIDOMWindow windowContext; */
  NS_SCRIPTABLE NS_IMETHOD GetWindowContext(nsIDOMWindow * *aWindowContext) = 0;

  /**
   * Resolve a file-path argument into an nsIFile. This method gracefully
   * handles relative or absolute file paths, according to the working
   * directory of this command line.
   *
   * @param aArgument  The command-line argument to resolve.
   */
  /* nsIFile resolveFile (in AString aArgument); */
  NS_SCRIPTABLE NS_IMETHOD ResolveFile(const nsAString & aArgument, nsIFile **_retval NS_OUTPARAM) = 0;

  /**
   * Resolves a URI argument into a URI. This method has platform-specific
   * logic for converting an absolute URI or a relative file-path into the
   * appropriate URI object; it gracefully handles win32 C:\ paths which would
   * confuse the ioservice if passed directly.
   *
   * @param aArgument  The command-line argument to resolve.
   */
  /* nsIURI resolveURI (in AString aArgument); */
  NS_SCRIPTABLE NS_IMETHOD ResolveURI(const nsAString & aArgument, nsIURI **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandLine, NS_ICOMMANDLINE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDLINE \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD GetArgument(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveArguments(PRInt32 aStart, PRInt32 aEnd); \
  NS_SCRIPTABLE NS_IMETHOD HandleFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HandleFlagWithParam(const nsAString & aFlag, PRBool aCaseSensitive, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState); \
  NS_SCRIPTABLE NS_IMETHOD GetPreventDefault(PRBool *aPreventDefault); \
  NS_SCRIPTABLE NS_IMETHOD SetPreventDefault(PRBool aPreventDefault); \
  NS_SCRIPTABLE NS_IMETHOD GetWorkingDirectory(nsIFile * *aWorkingDirectory); \
  NS_SCRIPTABLE NS_IMETHOD GetWindowContext(nsIDOMWindow * *aWindowContext); \
  NS_SCRIPTABLE NS_IMETHOD ResolveFile(const nsAString & aArgument, nsIFile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ResolveURI(const nsAString & aArgument, nsIURI **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDLINE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetArgument(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM) { return _to GetArgument(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRInt32 *_retval NS_OUTPARAM) { return _to FindFlag(aFlag, aCaseSensitive, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveArguments(PRInt32 aStart, PRInt32 aEnd) { return _to RemoveArguments(aStart, aEnd); } \
  NS_SCRIPTABLE NS_IMETHOD HandleFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRBool *_retval NS_OUTPARAM) { return _to HandleFlag(aFlag, aCaseSensitive, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HandleFlagWithParam(const nsAString & aFlag, PRBool aCaseSensitive, nsAString & _retval NS_OUTPARAM) { return _to HandleFlagWithParam(aFlag, aCaseSensitive, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState) { return _to GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreventDefault(PRBool *aPreventDefault) { return _to GetPreventDefault(aPreventDefault); } \
  NS_SCRIPTABLE NS_IMETHOD SetPreventDefault(PRBool aPreventDefault) { return _to SetPreventDefault(aPreventDefault); } \
  NS_SCRIPTABLE NS_IMETHOD GetWorkingDirectory(nsIFile * *aWorkingDirectory) { return _to GetWorkingDirectory(aWorkingDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindowContext(nsIDOMWindow * *aWindowContext) { return _to GetWindowContext(aWindowContext); } \
  NS_SCRIPTABLE NS_IMETHOD ResolveFile(const nsAString & aArgument, nsIFile **_retval NS_OUTPARAM) { return _to ResolveFile(aArgument, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ResolveURI(const nsAString & aArgument, nsIURI **_retval NS_OUTPARAM) { return _to ResolveURI(aArgument, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDLINE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetArgument(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetArgument(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindFlag(aFlag, aCaseSensitive, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveArguments(PRInt32 aStart, PRInt32 aEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveArguments(aStart, aEnd); } \
  NS_SCRIPTABLE NS_IMETHOD HandleFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleFlag(aFlag, aCaseSensitive, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HandleFlagWithParam(const nsAString & aFlag, PRBool aCaseSensitive, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleFlagWithParam(aFlag, aCaseSensitive, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreventDefault(PRBool *aPreventDefault) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreventDefault(aPreventDefault); } \
  NS_SCRIPTABLE NS_IMETHOD SetPreventDefault(PRBool aPreventDefault) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreventDefault(aPreventDefault); } \
  NS_SCRIPTABLE NS_IMETHOD GetWorkingDirectory(nsIFile * *aWorkingDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWorkingDirectory(aWorkingDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindowContext(nsIDOMWindow * *aWindowContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowContext(aWindowContext); } \
  NS_SCRIPTABLE NS_IMETHOD ResolveFile(const nsAString & aArgument, nsIFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResolveFile(aArgument, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ResolveURI(const nsAString & aArgument, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResolveURI(aArgument, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandLine : public nsICommandLine
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDLINE

  nsCommandLine();

private:
  ~nsCommandLine();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandLine, nsICommandLine)

nsCommandLine::nsCommandLine()
{
  /* member initializers and constructor code */
}

nsCommandLine::~nsCommandLine()
{
  /* destructor code */
}

/* readonly attribute long length; */
NS_IMETHODIMP nsCommandLine::GetLength(PRInt32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getArgument (in long aIndex); */
NS_IMETHODIMP nsCommandLine::GetArgument(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long findFlag (in AString aFlag, in boolean aCaseSensitive); */
NS_IMETHODIMP nsCommandLine::FindFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeArguments (in long aStart, in long aEnd); */
NS_IMETHODIMP nsCommandLine::RemoveArguments(PRInt32 aStart, PRInt32 aEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handleFlag (in AString aFlag, in boolean aCaseSensitive); */
NS_IMETHODIMP nsCommandLine::HandleFlag(const nsAString & aFlag, PRBool aCaseSensitive, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString handleFlagWithParam (in AString aFlag, in boolean aCaseSensitive); */
NS_IMETHODIMP nsCommandLine::HandleFlagWithParam(const nsAString & aFlag, PRBool aCaseSensitive, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long state; */
NS_IMETHODIMP nsCommandLine::GetState(PRUint32 *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean preventDefault; */
NS_IMETHODIMP nsCommandLine::GetPreventDefault(PRBool *aPreventDefault)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCommandLine::SetPreventDefault(PRBool aPreventDefault)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile workingDirectory; */
NS_IMETHODIMP nsCommandLine::GetWorkingDirectory(nsIFile * *aWorkingDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow windowContext; */
NS_IMETHODIMP nsCommandLine::GetWindowContext(nsIDOMWindow * *aWindowContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile resolveFile (in AString aArgument); */
NS_IMETHODIMP nsCommandLine::ResolveFile(const nsAString & aArgument, nsIFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI resolveURI (in AString aArgument); */
NS_IMETHODIMP nsCommandLine::ResolveURI(const nsAString & aArgument, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICommandLine_h__ */
