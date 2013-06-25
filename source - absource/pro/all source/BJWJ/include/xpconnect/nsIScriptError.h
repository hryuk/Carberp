/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/nsIScriptError.idl
 */

#ifndef __gen_nsIScriptError_h__
#define __gen_nsIScriptError_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIConsoleMessage_h__
#include "nsIConsoleMessage.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScriptError */
#define NS_ISCRIPTERROR_IID_STR "b0196fc7-1913-441a-882a-453c0d8b89b8"

#define NS_ISCRIPTERROR_IID \
  {0xb0196fc7, 0x1913, 0x441a, \
    { 0x88, 0x2a, 0x45, 0x3c, 0x0d, 0x8b, 0x89, 0xb8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptError : public nsIConsoleMessage {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTERROR_IID)

  /** pseudo-flag for default case */
  enum { errorFlag = 0U };

  /** message is warning */
  enum { warningFlag = 1U };

  /** exception was thrown for this case - exception-aware hosts can ignore */
  enum { exceptionFlag = 2U };

  /** error or warning is due to strict option */
  enum { strictFlag = 4U };

  /**
     * The error message without any context/line number information.
     *
     * @note nsIConsoleMessage.message will return the error formatted
     *       with file/line information.
     */
  /* readonly attribute AString errorMessage; */
  NS_SCRIPTABLE NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) = 0;

  /* readonly attribute AString sourceName; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceName(nsAString & aSourceName) = 0;

  /* readonly attribute AString sourceLine; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceLine(nsAString & aSourceLine) = 0;

  /* readonly attribute PRUint32 lineNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRUint32 *aLineNumber) = 0;

  /* readonly attribute PRUint32 columnNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRUint32 *aColumnNumber) = 0;

  /* readonly attribute PRUint32 flags; */
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) = 0;

  /**
     * Categories I know about -
     * XUL javascript
     * content javascript (both of these from nsDocShell, currently)
     * component javascript (errors in JS components)
     */
  /* readonly attribute string category; */
  NS_SCRIPTABLE NS_IMETHOD GetCategory(char * *aCategory) = 0;

  /* void init (in wstring message, in wstring sourceName, in wstring sourceLine, in PRUint32 lineNumber, in PRUint32 columnNumber, in PRUint32 flags, in string category); */
  NS_SCRIPTABLE NS_IMETHOD Init(const PRUnichar *message, const PRUnichar *sourceName, const PRUnichar *sourceLine, PRUint32 lineNumber, PRUint32 columnNumber, PRUint32 flags, const char *category) = 0;

  /* AUTF8String toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptError, NS_ISCRIPTERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTERROR \
  NS_SCRIPTABLE NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceName(nsAString & aSourceName); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceLine(nsAString & aSourceLine); \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRUint32 *aLineNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRUint32 *aColumnNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetCategory(char * *aCategory); \
  NS_SCRIPTABLE NS_IMETHOD Init(const PRUnichar *message, const PRUnichar *sourceName, const PRUnichar *sourceLine, PRUint32 lineNumber, PRUint32 columnNumber, PRUint32 flags, const char *category); \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) { return _to GetErrorMessage(aErrorMessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceName(nsAString & aSourceName) { return _to GetSourceName(aSourceName); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceLine(nsAString & aSourceLine) { return _to GetSourceLine(aSourceLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRUint32 *aLineNumber) { return _to GetLineNumber(aLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRUint32 *aColumnNumber) { return _to GetColumnNumber(aColumnNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return _to GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetCategory(char * *aCategory) { return _to GetCategory(aCategory); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const PRUnichar *message, const PRUnichar *sourceName, const PRUnichar *sourceLine, PRUint32 lineNumber, PRUint32 columnNumber, PRUint32 flags, const char *category) { return _to Init(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsACString & _retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorMessage(aErrorMessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceName(nsAString & aSourceName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceName(aSourceName); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceLine(nsAString & aSourceLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceLine(aSourceLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRUint32 *aLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRUint32 *aColumnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnNumber(aColumnNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetCategory(char * *aCategory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCategory(aCategory); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const PRUnichar *message, const PRUnichar *sourceName, const PRUnichar *sourceLine, PRUint32 lineNumber, PRUint32 columnNumber, PRUint32 flags, const char *category) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptError : public nsIScriptError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTERROR

  nsScriptError();

private:
  ~nsScriptError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptError, nsIScriptError)

nsScriptError::nsScriptError()
{
  /* member initializers and constructor code */
}

nsScriptError::~nsScriptError()
{
  /* destructor code */
}

/* readonly attribute AString errorMessage; */
NS_IMETHODIMP nsScriptError::GetErrorMessage(nsAString & aErrorMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString sourceName; */
NS_IMETHODIMP nsScriptError::GetSourceName(nsAString & aSourceName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString sourceLine; */
NS_IMETHODIMP nsScriptError::GetSourceLine(nsAString & aSourceLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 lineNumber; */
NS_IMETHODIMP nsScriptError::GetLineNumber(PRUint32 *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 columnNumber; */
NS_IMETHODIMP nsScriptError::GetColumnNumber(PRUint32 *aColumnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 flags; */
NS_IMETHODIMP nsScriptError::GetFlags(PRUint32 *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string category; */
NS_IMETHODIMP nsScriptError::GetCategory(char * *aCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in wstring message, in wstring sourceName, in wstring sourceLine, in PRUint32 lineNumber, in PRUint32 columnNumber, in PRUint32 flags, in string category); */
NS_IMETHODIMP nsScriptError::Init(const PRUnichar *message, const PRUnichar *sourceName, const PRUnichar *sourceLine, PRUint32 lineNumber, PRUint32 columnNumber, PRUint32 flags, const char *category)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String toString (); */
NS_IMETHODIMP nsScriptError::ToString(nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SCRIPTERROR_CLASSNAME "Script Error"
#define NS_SCRIPTERROR_CID \
{ 0xe38e53b9, 0x5bb0, 0x456a, { 0xb5, 0x53, 0x57, 0x93, 0x70, 0xcb, 0x15, 0x67 }}
#define NS_SCRIPTERROR_CONTRACTID "@mozilla.org/scripterror;1"

#endif /* __gen_nsIScriptError_h__ */
