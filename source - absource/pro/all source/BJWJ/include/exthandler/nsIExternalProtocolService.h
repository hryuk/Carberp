/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/uriloader/exthandler/nsIExternalProtocolService.idl
 */

#ifndef __gen_nsIExternalProtocolService_h__
#define __gen_nsIExternalProtocolService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

class nsIHandlerInfo; /* forward declaration */


/* starting interface:    nsIExternalProtocolService */
#define NS_IEXTERNALPROTOCOLSERVICE_IID_STR "70f93b7a-3ec6-4bcb-b093-92d9984c9f83"

#define NS_IEXTERNALPROTOCOLSERVICE_IID \
  {0x70f93b7a, 0x3ec6, 0x4bcb, \
    { 0xb0, 0x93, 0x92, 0xd9, 0x98, 0x4c, 0x9f, 0x83 }}

/**
 * The external protocol service is used for finding and launching
 * web handlers (a la registerProtocolHandler in the HTML5 draft) or 
 * platform-specific applications for handling particular protocols.
 *
 * You can ask the external protocol service if it has an external
 * handler for a given protocol scheme. And you can ask it to load 
 * the url using the default handler.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIExternalProtocolService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXTERNALPROTOCOLSERVICE_IID)

  /**
   * Check whether a handler for a specific protocol exists.  Specifically,
   * this looks to see whether there are any known possible application handlers
   * in either the nsIHandlerService datastore or registered with the OS.
   *
   * @param aProtocolScheme The scheme from a url: http, ftp, mailto, etc.
   *
   * @return true if we have a handler and false otherwise.
   *
   * XXX shouldn't aProtocolScheme be an ACString like nsIURI::scheme?
   */
  /* boolean externalProtocolHandlerExists (in string aProtocolScheme); */
  NS_SCRIPTABLE NS_IMETHOD ExternalProtocolHandlerExists(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Check whether a handler for a specific protocol is "exposed" as a visible
   * feature of the current application.
   *
   * An exposed protocol handler is one that can be used in all contexts.  A
   * non-exposed protocol handler is one that can only be used internally by the
   * application.  For example, a non-exposed protocol would not be loaded by the
   * application in response to a link click or a X-remote openURL command.
   * Instead, it would be deferred to the system's external protocol handler.
   * XXX shouldn't aProtocolScheme be an ACString like nsIURI::scheme?
   */
  /* boolean isExposedProtocol (in string aProtocolScheme); */
  NS_SCRIPTABLE NS_IMETHOD IsExposedProtocol(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Retrieve the handler for the given protocol.  If neither the application
   * nor the OS knows about a handler for the protocol, the object this method
   * returns will represent a default handler for unknown content.
   * 
   * @param aProtocolScheme the scheme from a URL: http, ftp, mailto, etc.
   * 
   * Note: aProtocolScheme should not include a trailing colon, which is part
   * of the URI syntax, not part of the scheme itself (i.e. pass "mailto" not
   * "mailto:").
   * 
   * @return the handler, if any; otherwise a default handler
   */
  /* nsIHandlerInfo getProtocolHandlerInfo (in ACString aProtocolScheme); */
  NS_SCRIPTABLE NS_IMETHOD GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo **_retval NS_OUTPARAM) = 0;

  /**
   * Given a scheme, looks up the protocol info from the OS.  This should be
   * overridden by each OS's implementation.
   *
   * @param aScheme The protocol scheme we are looking for.
   * @param aFound  Was an OS default handler for this scheme found?
   * @return An nsIHanderInfo for the protocol.
   */
  /* nsIHandlerInfo getProtocolHandlerInfoFromOS (in ACString aProtocolScheme, out boolean aFound); */
  NS_SCRIPTABLE NS_IMETHOD GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, PRBool *aFound NS_OUTPARAM, nsIHandlerInfo **_retval NS_OUTPARAM) = 0;

  /** 
   * Set some sane defaults for a protocol handler object.
   * 
   * @param aHandlerInfo      nsIHandlerInfo object, as returned by 
   *                          getProtocolHandlerInfoFromOS
   * @param aOSHandlerExists  was the object above created for an extant
   *                          OS default handler?  This is generally the
   *                          value of the aFound out param from
   *                          getProtocolHandlerInfoFromOS.
   */
  /* void setProtocolHandlerDefaults (in nsIHandlerInfo aHandlerInfo, in boolean aOSHandlerExists); */
  NS_SCRIPTABLE NS_IMETHOD SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, PRBool aOSHandlerExists) = 0;

  /**
   * Used to load a url via an external protocol handler (if one exists)
   *
   * @param aURL The url to load
   * @deprecated Use LoadURI instead (See Bug 389565 for removal)
   */
  /* void loadUrl (in nsIURI aURL); */
  NS_SCRIPTABLE NS_IMETHOD LoadUrl(nsIURI *aURL) = 0;

  /**
   * Used to load a URI via an external application. Might prompt the user for
   * permission to load the external application.
   *
   * @param aURI
   *        The URI to load
   *
   * @param aWindowContext 
   *        The window to parent the dialog against, and, if a web handler
   *        is chosen, it is loaded in this window as well.  This parameter
   *        may be ultimately passed nsIURILoader.openURI in the case of a
   *        web handler, and aWindowContext is null or not present, web
   *        handlers will fail.  We need to do better than that; bug 394483
   *        filed in order to track.
   * 
   * @note  Embedders that do not expose the http protocol should not currently
   *        use web-based protocol handlers, as handoff won't work correctly
   *        (bug 394479).  
   */
  /* void loadURI (in nsIURI aURI, [optional] in nsIInterfaceRequestor aWindowContext); */
  NS_SCRIPTABLE NS_IMETHOD LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) = 0;

  /**
   * Gets a human-readable description for the application responsible for
   * handling a specific protocol.
   *
   * @param aScheme The scheme to look up. For example, "mms".
   *
   * @throw NS_ERROR_NOT_IMPLEMENTED
   *        If getting descriptions for protocol helpers is not supported
   * @throw NS_ERROR_NOT_AVAILABLE
   *        If no protocol helper exists for this scheme, or if it is not
   *        possible to get a description for it.
   */
  /* AString getApplicationDescription (in AUTF8String aScheme); */
  NS_SCRIPTABLE NS_IMETHOD GetApplicationDescription(const nsACString & aScheme, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExternalProtocolService, NS_IEXTERNALPROTOCOLSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXTERNALPROTOCOLSERVICE \
  NS_SCRIPTABLE NS_IMETHOD ExternalProtocolHandlerExists(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsExposedProtocol(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, PRBool *aFound NS_OUTPARAM, nsIHandlerInfo **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, PRBool aOSHandlerExists); \
  NS_SCRIPTABLE NS_IMETHOD LoadUrl(nsIURI *aURL); \
  NS_SCRIPTABLE NS_IMETHOD LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext); \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationDescription(const nsACString & aScheme, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXTERNALPROTOCOLSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ExternalProtocolHandlerExists(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM) { return _to ExternalProtocolHandlerExists(aProtocolScheme, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsExposedProtocol(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM) { return _to IsExposedProtocol(aProtocolScheme, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo **_retval NS_OUTPARAM) { return _to GetProtocolHandlerInfo(aProtocolScheme, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, PRBool *aFound NS_OUTPARAM, nsIHandlerInfo **_retval NS_OUTPARAM) { return _to GetProtocolHandlerInfoFromOS(aProtocolScheme, aFound, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, PRBool aOSHandlerExists) { return _to SetProtocolHandlerDefaults(aHandlerInfo, aOSHandlerExists); } \
  NS_SCRIPTABLE NS_IMETHOD LoadUrl(nsIURI *aURL) { return _to LoadUrl(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) { return _to LoadURI(aURI, aWindowContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationDescription(const nsACString & aScheme, nsAString & _retval NS_OUTPARAM) { return _to GetApplicationDescription(aScheme, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXTERNALPROTOCOLSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ExternalProtocolHandlerExists(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExternalProtocolHandlerExists(aProtocolScheme, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsExposedProtocol(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsExposedProtocol(aProtocolScheme, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocolHandlerInfo(aProtocolScheme, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, PRBool *aFound NS_OUTPARAM, nsIHandlerInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocolHandlerInfoFromOS(aProtocolScheme, aFound, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, PRBool aOSHandlerExists) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProtocolHandlerDefaults(aHandlerInfo, aOSHandlerExists); } \
  NS_SCRIPTABLE NS_IMETHOD LoadUrl(nsIURI *aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadUrl(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURI(aURI, aWindowContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationDescription(const nsACString & aScheme, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationDescription(aScheme, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExternalProtocolService : public nsIExternalProtocolService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXTERNALPROTOCOLSERVICE

  nsExternalProtocolService();

private:
  ~nsExternalProtocolService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExternalProtocolService, nsIExternalProtocolService)

nsExternalProtocolService::nsExternalProtocolService()
{
  /* member initializers and constructor code */
}

nsExternalProtocolService::~nsExternalProtocolService()
{
  /* destructor code */
}

/* boolean externalProtocolHandlerExists (in string aProtocolScheme); */
NS_IMETHODIMP nsExternalProtocolService::ExternalProtocolHandlerExists(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isExposedProtocol (in string aProtocolScheme); */
NS_IMETHODIMP nsExternalProtocolService::IsExposedProtocol(const char *aProtocolScheme, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIHandlerInfo getProtocolHandlerInfo (in ACString aProtocolScheme); */
NS_IMETHODIMP nsExternalProtocolService::GetProtocolHandlerInfo(const nsACString & aProtocolScheme, nsIHandlerInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIHandlerInfo getProtocolHandlerInfoFromOS (in ACString aProtocolScheme, out boolean aFound); */
NS_IMETHODIMP nsExternalProtocolService::GetProtocolHandlerInfoFromOS(const nsACString & aProtocolScheme, PRBool *aFound NS_OUTPARAM, nsIHandlerInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setProtocolHandlerDefaults (in nsIHandlerInfo aHandlerInfo, in boolean aOSHandlerExists); */
NS_IMETHODIMP nsExternalProtocolService::SetProtocolHandlerDefaults(nsIHandlerInfo *aHandlerInfo, PRBool aOSHandlerExists)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadUrl (in nsIURI aURL); */
NS_IMETHODIMP nsExternalProtocolService::LoadUrl(nsIURI *aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadURI (in nsIURI aURI, [optional] in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsExternalProtocolService::LoadURI(nsIURI *aURI, nsIInterfaceRequestor *aWindowContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getApplicationDescription (in AUTF8String aScheme); */
NS_IMETHODIMP nsExternalProtocolService::GetApplicationDescription(const nsACString & aScheme, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExternalProtocolService_h__ */
