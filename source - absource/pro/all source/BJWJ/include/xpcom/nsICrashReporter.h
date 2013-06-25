/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/system/nsICrashReporter.idl
 */

#ifndef __gen_nsICrashReporter_h__
#define __gen_nsICrashReporter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICrashReporter */
#define NS_ICRASHREPORTER_IID_STR "d9a0f5b2-a7df-4aeb-9775-21b9e01b4c59"

#define NS_ICRASHREPORTER_IID \
  {0xd9a0f5b2, 0xa7df, 0x4aeb, \
    { 0x97, 0x75, 0x21, 0xb9, 0xe0, 0x1b, 0x4c, 0x59 }}

/**
 * Provides access to crash reporting functionality.
 * @status UNSTABLE - This interface is not frozen and will probably change in
 *                    future releases.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICrashReporter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRASHREPORTER_IID)

  /**
   * Add some extra data to be submitted with a crash report.
   * @param key
   *        Name of the data to be added.
   * @param data
   *        Data to be added.
   *
   * @throw NS_ERROR_NOT_INITIALIZED if crash reporting not initialized
   * @throw NS_ERROR_INVALID_ARG if key or data contain invalid characters.
   *                             Invalid characters for key are '=' and
   *                             '\n'.  Invalid character for data is '\0'.
   */
  /* void annotateCrashReport (in ACString key, in ACString data); */
  NS_SCRIPTABLE NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) = 0;

  /**
   * Append some data to the "Notes" field, to be submitted with a crash report.
   * Unlike annotateCrashReport, this method will append to existing data.
   *
   * @param data
   *        Data to be added.
   *
   * @throw NS_ERROR_NOT_INITIALIZED if crash reporting not initialized
   * @throw NS_ERROR_INVALID_ARG if or data contains invalid characters.
   *                             The only invalid character is '\0'.
   */
  /* void appendAppNotesToCrashReport (in ACString data); */
  NS_SCRIPTABLE NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) = 0;

  /**
    * Write a minidump immediately, with the user-supplied exception
    * information. This is implemented on Windows only, because
    * SEH (structured exception handling) exists on Windows only.
    * @param aExceptionInfo  EXCEPTION_INFO* provided by Window's SEH
    */
  /* [noscript] void writeMinidumpForException (in voidPtr aExceptionInfo); */
  NS_IMETHOD WriteMinidumpForException(void * aExceptionInfo) = 0;

  /**
    * Append note containing an Obj-C exception's info.
    * @param aException  NSException object to append note for
    */
  /* [noscript] void appendObjCExceptionInfoToAppNotes (in voidPtr aException); */
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void * aException) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICrashReporter, NS_ICRASHREPORTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRASHREPORTER \
  NS_SCRIPTABLE NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data); \
  NS_SCRIPTABLE NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data); \
  NS_IMETHOD WriteMinidumpForException(void * aExceptionInfo); \
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void * aException); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRASHREPORTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) { return _to AnnotateCrashReport(key, data); } \
  NS_SCRIPTABLE NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) { return _to AppendAppNotesToCrashReport(data); } \
  NS_IMETHOD WriteMinidumpForException(void * aExceptionInfo) { return _to WriteMinidumpForException(aExceptionInfo); } \
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void * aException) { return _to AppendObjCExceptionInfoToAppNotes(aException); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRASHREPORTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->AnnotateCrashReport(key, data); } \
  NS_SCRIPTABLE NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendAppNotesToCrashReport(data); } \
  NS_IMETHOD WriteMinidumpForException(void * aExceptionInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteMinidumpForException(aExceptionInfo); } \
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void * aException) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendObjCExceptionInfoToAppNotes(aException); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCrashReporter : public nsICrashReporter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRASHREPORTER

  nsCrashReporter();

private:
  ~nsCrashReporter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCrashReporter, nsICrashReporter)

nsCrashReporter::nsCrashReporter()
{
  /* member initializers and constructor code */
}

nsCrashReporter::~nsCrashReporter()
{
  /* destructor code */
}

/* void annotateCrashReport (in ACString key, in ACString data); */
NS_IMETHODIMP nsCrashReporter::AnnotateCrashReport(const nsACString & key, const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendAppNotesToCrashReport (in ACString data); */
NS_IMETHODIMP nsCrashReporter::AppendAppNotesToCrashReport(const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void writeMinidumpForException (in voidPtr aExceptionInfo); */
NS_IMETHODIMP nsCrashReporter::WriteMinidumpForException(void * aExceptionInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void appendObjCExceptionInfoToAppNotes (in voidPtr aException); */
NS_IMETHODIMP nsCrashReporter::AppendObjCExceptionInfoToAppNotes(void * aException)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICrashReporter_h__ */
