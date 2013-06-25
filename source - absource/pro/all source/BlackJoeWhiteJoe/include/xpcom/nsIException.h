/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/base/nsIException.idl
 */

#ifndef __gen_nsIException_h__
#define __gen_nsIException_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIProgrammingLanguage_h__
#include "nsIProgrammingLanguage.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStackFrame */
#define NS_ISTACKFRAME_IID_STR "91d82105-7c62-4f8b-9779-154277c0ee90"

#define NS_ISTACKFRAME_IID \
  {0x91d82105, 0x7c62, 0x4f8b, \
    { 0x97, 0x79, 0x15, 0x42, 0x77, 0xc0, 0xee, 0x90 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIStackFrame : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTACKFRAME_IID)

  /* readonly attribute PRUint32 language; */
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(PRUint32 *aLanguage) = 0;

  /* readonly attribute string languageName; */
  NS_SCRIPTABLE NS_IMETHOD GetLanguageName(char * *aLanguageName) = 0;

  /* readonly attribute string filename; */
  NS_SCRIPTABLE NS_IMETHOD GetFilename(char * *aFilename) = 0;

  /* readonly attribute string name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) = 0;

  /* readonly attribute PRInt32 lineNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRInt32 *aLineNumber) = 0;

  /* readonly attribute string sourceLine; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceLine(char * *aSourceLine) = 0;

  /* readonly attribute nsIStackFrame caller; */
  NS_SCRIPTABLE NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) = 0;

  /* string toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStackFrame, NS_ISTACKFRAME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTACKFRAME \
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(PRUint32 *aLanguage); \
  NS_SCRIPTABLE NS_IMETHOD GetLanguageName(char * *aLanguageName); \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(char * *aFilename); \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName); \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRInt32 *aLineNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceLine(char * *aSourceLine); \
  NS_SCRIPTABLE NS_IMETHOD GetCaller(nsIStackFrame * *aCaller); \
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTACKFRAME(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(PRUint32 *aLanguage) { return _to GetLanguage(aLanguage); } \
  NS_SCRIPTABLE NS_IMETHOD GetLanguageName(char * *aLanguageName) { return _to GetLanguageName(aLanguageName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(char * *aFilename) { return _to GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRInt32 *aLineNumber) { return _to GetLineNumber(aLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceLine(char * *aSourceLine) { return _to GetSourceLine(aSourceLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) { return _to GetCaller(aCaller); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTACKFRAME(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(PRUint32 *aLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } \
  NS_SCRIPTABLE NS_IMETHOD GetLanguageName(char * *aLanguageName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguageName(aLanguageName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(char * *aFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRInt32 *aLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceLine(char * *aSourceLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceLine(aSourceLine); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaller(aCaller); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStackFrame : public nsIStackFrame
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTACKFRAME

  nsStackFrame();

private:
  ~nsStackFrame();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStackFrame, nsIStackFrame)

nsStackFrame::nsStackFrame()
{
  /* member initializers and constructor code */
}

nsStackFrame::~nsStackFrame()
{
  /* destructor code */
}

/* readonly attribute PRUint32 language; */
NS_IMETHODIMP nsStackFrame::GetLanguage(PRUint32 *aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string languageName; */
NS_IMETHODIMP nsStackFrame::GetLanguageName(char * *aLanguageName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string filename; */
NS_IMETHODIMP nsStackFrame::GetFilename(char * *aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string name; */
NS_IMETHODIMP nsStackFrame::GetName(char * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 lineNumber; */
NS_IMETHODIMP nsStackFrame::GetLineNumber(PRInt32 *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string sourceLine; */
NS_IMETHODIMP nsStackFrame::GetSourceLine(char * *aSourceLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame caller; */
NS_IMETHODIMP nsStackFrame::GetCaller(nsIStackFrame * *aCaller)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string toString (); */
NS_IMETHODIMP nsStackFrame::ToString(char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIException */
#define NS_IEXCEPTION_IID_STR "f3a8d3b4-c424-4edc-8bf6-8974c983ba78"

#define NS_IEXCEPTION_IID \
  {0xf3a8d3b4, 0xc424, 0x4edc, \
    { 0x8b, 0xf6, 0x89, 0x74, 0xc9, 0x83, 0xba, 0x78 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXCEPTION_IID)

  /* [binaryname (MessageMoz)] readonly attribute string message; */
  NS_SCRIPTABLE NS_IMETHOD GetMessageMoz(char * *aMessage) = 0;

  /* readonly attribute nsresult result; */
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsresult *aResult) = 0;

  /* readonly attribute string name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) = 0;

  /* readonly attribute string filename; */
  NS_SCRIPTABLE NS_IMETHOD GetFilename(char * *aFilename) = 0;

  /* readonly attribute PRUint32 lineNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRUint32 *aLineNumber) = 0;

  /* readonly attribute PRUint32 columnNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRUint32 *aColumnNumber) = 0;

  /* readonly attribute nsIStackFrame location; */
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) = 0;

  /* readonly attribute nsIException inner; */
  NS_SCRIPTABLE NS_IMETHOD GetInner(nsIException * *aInner) = 0;

  /* readonly attribute nsISupports data; */
  NS_SCRIPTABLE NS_IMETHOD GetData(nsISupports * *aData) = 0;

  /* string toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIException, NS_IEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXCEPTION \
  NS_SCRIPTABLE NS_IMETHOD GetMessageMoz(char * *aMessage); \
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsresult *aResult); \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName); \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(char * *aFilename); \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRUint32 *aLineNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRUint32 *aColumnNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIStackFrame * *aLocation); \
  NS_SCRIPTABLE NS_IMETHOD GetInner(nsIException * *aInner); \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsISupports * *aData); \
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMessageMoz(char * *aMessage) { return _to GetMessageMoz(aMessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsresult *aResult) { return _to GetResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(char * *aFilename) { return _to GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRUint32 *aLineNumber) { return _to GetLineNumber(aLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRUint32 *aColumnNumber) { return _to GetColumnNumber(aColumnNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) { return _to GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetInner(nsIException * *aInner) { return _to GetInner(aInner); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsISupports * *aData) { return _to GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMessageMoz(char * *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(aMessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsresult *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(char * *aFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineNumber(PRUint32 *aLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnNumber(PRUint32 *aColumnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnNumber(aColumnNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetInner(nsIException * *aInner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInner(aInner); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsISupports * *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsException : public nsIException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXCEPTION

  nsException();

private:
  ~nsException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsException, nsIException)

nsException::nsException()
{
  /* member initializers and constructor code */
}

nsException::~nsException()
{
  /* destructor code */
}

/* [binaryname (MessageMoz)] readonly attribute string message; */
NS_IMETHODIMP nsException::GetMessageMoz(char * *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsresult result; */
NS_IMETHODIMP nsException::GetResult(nsresult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string name; */
NS_IMETHODIMP nsException::GetName(char * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string filename; */
NS_IMETHODIMP nsException::GetFilename(char * *aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 lineNumber; */
NS_IMETHODIMP nsException::GetLineNumber(PRUint32 *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 columnNumber; */
NS_IMETHODIMP nsException::GetColumnNumber(PRUint32 *aColumnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame location; */
NS_IMETHODIMP nsException::GetLocation(nsIStackFrame * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIException inner; */
NS_IMETHODIMP nsException::GetInner(nsIException * *aInner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports data; */
NS_IMETHODIMP nsException::GetData(nsISupports * *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string toString (); */
NS_IMETHODIMP nsException::ToString(char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIException_h__ */
