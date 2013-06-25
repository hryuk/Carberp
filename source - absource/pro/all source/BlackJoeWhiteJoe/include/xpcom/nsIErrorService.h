/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/base/nsIErrorService.idl
 */

#ifndef __gen_nsIErrorService_h__
#define __gen_nsIErrorService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIErrorService */
#define NS_IERRORSERVICE_IID_STR "e72f94b2-5f85-11d4-9877-00c04fa0cf4a"

#define NS_IERRORSERVICE_IID \
  {0xe72f94b2, 0x5f85, 0x11d4, \
    { 0x98, 0x77, 0x00, 0xc0, 0x4f, 0xa0, 0xcf, 0x4a }}

/**
 * nsIErrorService: This is an interim service that allows nsresult codes to be mapped to 
 * string bundles that can be used to look up error messages. String bundle keys can also
 * be mapped. 
 *
 * This service will eventually get replaced by extending xpidl to allow errors to be defined.
 * (http://bugzilla.mozilla.org/show_bug.cgi?id=13423).
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIErrorService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IERRORSERVICE_IID)

  /**
     * Registers a string bundle URL for an error module. Error modules are obtained from
     * nsresult code with NS_ERROR_GET_MODULE.
     */
  /* void registerErrorStringBundle (in short errorModule, in string stringBundleURL); */
  NS_SCRIPTABLE NS_IMETHOD RegisterErrorStringBundle(PRInt16 errorModule, const char *stringBundleURL) = 0;

  /**
     * Registers a string bundle URL for an error module.
     */
  /* void unregisterErrorStringBundle (in short errorModule); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterErrorStringBundle(PRInt16 errorModule) = 0;

  /**
     * Retrieves a string bundle URL for an error module.
     */
  /* string getErrorStringBundle (in short errorModule); */
  NS_SCRIPTABLE NS_IMETHOD GetErrorStringBundle(PRInt16 errorModule, char **_retval NS_OUTPARAM) = 0;

  /**
     * Registers a key in a string bundle for an nsresult error code. Only the code portion
     * of the nsresult is used (obtained with NS_ERROR_GET_CODE) in this registration. The
     * string bundle key is used to look up internationalized messages in the string bundle.
     */
  /* void registerErrorStringBundleKey (in nsresult error, in string stringBundleKey); */
  NS_SCRIPTABLE NS_IMETHOD RegisterErrorStringBundleKey(nsresult error, const char *stringBundleKey) = 0;

  /**
     * Unregisters a key in a string bundle for an nsresult error code. 
     */
  /* void unregisterErrorStringBundleKey (in nsresult error); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterErrorStringBundleKey(nsresult error) = 0;

  /**
     * Retrieves a key in a string bundle for an nsresult error code. If no key is registered
     * for the specified nsresult's code (obtained with NS_ERROR_GET_CODE), then the stringified
     * version of the nsresult code is returned.
     */
  /* string getErrorStringBundleKey (in nsresult error); */
  NS_SCRIPTABLE NS_IMETHOD GetErrorStringBundleKey(nsresult error, char **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIErrorService, NS_IERRORSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIERRORSERVICE \
  NS_SCRIPTABLE NS_IMETHOD RegisterErrorStringBundle(PRInt16 errorModule, const char *stringBundleURL); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterErrorStringBundle(PRInt16 errorModule); \
  NS_SCRIPTABLE NS_IMETHOD GetErrorStringBundle(PRInt16 errorModule, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RegisterErrorStringBundleKey(nsresult error, const char *stringBundleKey); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterErrorStringBundleKey(nsresult error); \
  NS_SCRIPTABLE NS_IMETHOD GetErrorStringBundleKey(nsresult error, char **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIERRORSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterErrorStringBundle(PRInt16 errorModule, const char *stringBundleURL) { return _to RegisterErrorStringBundle(errorModule, stringBundleURL); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterErrorStringBundle(PRInt16 errorModule) { return _to UnregisterErrorStringBundle(errorModule); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorStringBundle(PRInt16 errorModule, char **_retval NS_OUTPARAM) { return _to GetErrorStringBundle(errorModule, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterErrorStringBundleKey(nsresult error, const char *stringBundleKey) { return _to RegisterErrorStringBundleKey(error, stringBundleKey); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterErrorStringBundleKey(nsresult error) { return _to UnregisterErrorStringBundleKey(error); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorStringBundleKey(nsresult error, char **_retval NS_OUTPARAM) { return _to GetErrorStringBundleKey(error, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIERRORSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterErrorStringBundle(PRInt16 errorModule, const char *stringBundleURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterErrorStringBundle(errorModule, stringBundleURL); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterErrorStringBundle(PRInt16 errorModule) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterErrorStringBundle(errorModule); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorStringBundle(PRInt16 errorModule, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorStringBundle(errorModule, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterErrorStringBundleKey(nsresult error, const char *stringBundleKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterErrorStringBundleKey(error, stringBundleKey); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterErrorStringBundleKey(nsresult error) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterErrorStringBundleKey(error); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorStringBundleKey(nsresult error, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorStringBundleKey(error, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsErrorService : public nsIErrorService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIERRORSERVICE

  nsErrorService();

private:
  ~nsErrorService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsErrorService, nsIErrorService)

nsErrorService::nsErrorService()
{
  /* member initializers and constructor code */
}

nsErrorService::~nsErrorService()
{
  /* destructor code */
}

/* void registerErrorStringBundle (in short errorModule, in string stringBundleURL); */
NS_IMETHODIMP nsErrorService::RegisterErrorStringBundle(PRInt16 errorModule, const char *stringBundleURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterErrorStringBundle (in short errorModule); */
NS_IMETHODIMP nsErrorService::UnregisterErrorStringBundle(PRInt16 errorModule)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getErrorStringBundle (in short errorModule); */
NS_IMETHODIMP nsErrorService::GetErrorStringBundle(PRInt16 errorModule, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerErrorStringBundleKey (in nsresult error, in string stringBundleKey); */
NS_IMETHODIMP nsErrorService::RegisterErrorStringBundleKey(nsresult error, const char *stringBundleKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterErrorStringBundleKey (in nsresult error); */
NS_IMETHODIMP nsErrorService::UnregisterErrorStringBundleKey(nsresult error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getErrorStringBundleKey (in nsresult error); */
NS_IMETHODIMP nsErrorService::GetErrorStringBundleKey(nsresult error, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// The global nsIErrorService:
#define NS_ERRORSERVICE_NAME   "Error Service" 
#define NS_ERRORSERVICE_CONTRACTID "@mozilla.org/xpcom/error-service;1"
#define NS_ERRORSERVICE_CID                          \
{ /* 744afd5e-5f8c-11d4-9877-00c04fa0cf4a */         \
    0x744afd5e,                                      \
    0x5f8c,                                          \
    0x11d4,                                          \
    {0x98, 0x77, 0x00, 0xc0, 0x4f, 0xa0, 0xcf, 0x4a} \
}

#endif /* __gen_nsIErrorService_h__ */
