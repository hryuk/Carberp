/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/caps/idl/nsIScriptSecurityManager.idl
 */

#ifndef __gen_nsIScriptSecurityManager_h__
#define __gen_nsIScriptSecurityManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPrincipal_h__
#include "nsIPrincipal.h"
#endif

#ifndef __gen_nsIXPCSecurityManager_h__
#include "nsIXPCSecurityManager.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    nsIScriptSecurityManager */
#define NS_ISCRIPTSECURITYMANAGER_IID_STR "f8e350b9-9f31-451a-8c8f-d10fea26b780"

#define NS_ISCRIPTSECURITYMANAGER_IID \
  {0xf8e350b9, 0x9f31, 0x451a, \
    { 0x8c, 0x8f, 0xd1, 0x0f, 0xea, 0x26, 0xb7, 0x80 }}

/**
 * WARNING!! The JEP needs to call GetSubjectPrincipal()
 * to support JavaScript-to-Java LiveConnect.  So every change to the
 * nsIScriptSecurityManager interface (big enough to change its IID) also
 * breaks JavaScript-to-Java LiveConnect on mac.
 *
 * If you REALLY have to change this interface, please mark your bug as
 * blocking bug 293973.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptSecurityManager : public nsIXPCSecurityManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTSECURITYMANAGER_IID)

  /**
     * Checks whether the running script is allowed to access aProperty.
     */
  /* [noscript] void checkPropertyAccess (in JSContextPtr aJSContext, in JSObjectPtr aJSObject, in string aClassName, in JSVal aProperty, in PRUint32 aAction); */
  NS_IMETHOD CheckPropertyAccess(JSContext * aJSContext, JSObject * aJSObject, const char *aClassName, jsval aProperty, PRUint32 aAction) = 0;

  /**
     * Checks whether the running script is allowed to connect to aTargetURI
     */
  /* [noscript] void checkConnect (in JSContextPtr aJSContext, in nsIURI aTargetURI, in string aClassName, in string aProperty); */
  NS_IMETHOD CheckConnect(JSContext * aJSContext, nsIURI *aTargetURI, const char *aClassName, const char *aProperty) = 0;

  /**
     * Check that the script currently running in context "cx" can load "uri".
     *
     * Will return error code NS_ERROR_DOM_BAD_URI if the load request 
     * should be denied.
     *
     * @param cx the JSContext of the script causing the load
     * @param uri the URI that is being loaded
     */
  /* [noscript] void checkLoadURIFromScript (in JSContextPtr cx, in nsIURI uri); */
  NS_IMETHOD CheckLoadURIFromScript(JSContext * cx, nsIURI *uri) = 0;

  /**
     * Default CheckLoadURI permissions
     */
  enum { STANDARD = 0U };

  enum { LOAD_IS_AUTOMATIC_DOCUMENT_REPLACEMENT = 1U };

  enum { ALLOW_CHROME = 2U };

  enum { DISALLOW_INHERIT_PRINCIPAL = 4U };

  enum { DISALLOW_SCRIPT_OR_DATA = 4U };

  enum { DISALLOW_SCRIPT = 8U };

  /**
     * Check that content with principal aPrincipal can load "uri".
     *
     * Will return error code NS_ERROR_DOM_BAD_URI if the load request 
     * should be denied.
     *
     * @param aPrincipal the principal identifying the actor causing the load
     * @param uri the URI that is being loaded
     * @param flags the permission set, see above
     */
  /* void checkLoadURIWithPrincipal (in nsIPrincipal aPrincipal, in nsIURI uri, in unsigned long flags); */
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, PRUint32 flags) = 0;

  /**
     * Check that content from "from" can load "uri".
     *
     * Will return error code NS_ERROR_DOM_BAD_URI if the load request 
     * should be denied.
     *
     * @param from the URI causing the load
     * @param uri the URI that is being loaded
     * @param flags the permission set, see above
     *
     * @deprecated Use checkLoadURIWithPrincipal instead of this function.
     */
  /* void checkLoadURI (in nsIURI from, in nsIURI uri, in unsigned long flags); */
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURI(nsIURI *from, nsIURI *uri, PRUint32 flags) = 0;

  /**
     * Similar to checkLoadURIWithPrincipal but there are two differences:
     *
     * 1) The URI is a string, not a URI object.
     * 2) This function assumes that the URI may still be subject to fixup (and
     * hence will check whether fixed-up versions of the URI are allowed to
     * load as well); if any of the versions of this URI is not allowed, this
     * function will return error code NS_ERROR_DOM_BAD_URI.
     */
  /* void checkLoadURIStrWithPrincipal (in nsIPrincipal aPrincipal, in AUTF8String uri, in unsigned long flags); */
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, PRUint32 flags) = 0;

  /**
     * Same as CheckLoadURI but takes string arguments for ease of use
     * by scripts
     *
     * @deprecated Use checkLoadURIStrWithPrincipal instead of this function.
     */
  /* void checkLoadURIStr (in AUTF8String from, in AUTF8String uri, in unsigned long flags); */
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIStr(const nsACString & from, const nsACString & uri, PRUint32 flags) = 0;

  /**
     * Check that the function 'funObj' is allowed to run on 'targetObj'
     *
     * Will return error code NS_ERROR_DOM_SECURITY_ERR if the function
     * should not run
     *
     * @param cx The current active JavaScript context.
     * @param funObj The function trying to run..
     * @param targetObj The object the function will run on.
     */
  /* [noscript] void checkFunctionAccess (in JSContextPtr cx, in voidPtr funObj, in voidPtr targetObj); */
  NS_IMETHOD CheckFunctionAccess(JSContext * cx, void * funObj, void * targetObj) = 0;

  /**
     * Return true if content from the given principal is allowed to
     * execute scripts.
     */
  /* [noscript] boolean canExecuteScripts (in JSContextPtr cx, in nsIPrincipal principal); */
  NS_IMETHOD CanExecuteScripts(JSContext * cx, nsIPrincipal *principal, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Return the principal of the innermost frame of the currently 
     * executing script. Will return null if there is no script 
     * currently executing.
     */
  /* [noscript] nsIPrincipal getSubjectPrincipal (); */
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal **_retval NS_OUTPARAM) = 0;

  /**
     * Return the all-powerful system principal.
     */
  /* [noscript] nsIPrincipal getSystemPrincipal (); */
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal **_retval NS_OUTPARAM) = 0;

  /**
     * Return a principal with the specified certificate fingerprint, subject
     * name (the full name or concatenated set of names of the entity
     * represented by the certificate), pretty name, certificate, and
     * codebase URI.  The certificate fingerprint and subject name MUST be
     * nonempty; otherwise an error will be thrown.  Similarly, aCert must
     * not be null.
     */
  /* [noscript] nsIPrincipal getCertificatePrincipal (in AUTF8String aCertFingerprint, in AUTF8String aSubjectName, in AUTF8String aPrettyName, in nsISupports aCert, in nsIURI aURI); */
  NS_IMETHOD GetCertificatePrincipal(const nsACString & aCertFingerprint, const nsACString & aSubjectName, const nsACString & aPrettyName, nsISupports *aCert, nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM) = 0;

  /**
     * Return a principal that has the same origin as aURI.
     */
  /* nsIPrincipal getCodebasePrincipal (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetCodebasePrincipal(nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM) = 0;

  /**
     * Request that 'capability' can be enabled by scripts or applets
     * running with 'principal'. Will prompt user if
     * necessary. Returns nsIPrincipal::ENABLE_GRANTED or
     * nsIPrincipal::ENABLE_DENIED based on user's choice.
     */
  /* [noscript] short requestCapability (in nsIPrincipal principal, in string capability); */
  NS_IMETHOD RequestCapability(nsIPrincipal *principal, const char *capability, PRInt16 *_retval NS_OUTPARAM) = 0;

  /**
     * Return true if the currently executing script has 'capability' enabled.
     */
  /* boolean isCapabilityEnabled (in string capability); */
  NS_SCRIPTABLE NS_IMETHOD IsCapabilityEnabled(const char *capability, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Enable 'capability' in the innermost frame of the currently executing
     * script.
     */
  /* void enableCapability (in string capability); */
  NS_SCRIPTABLE NS_IMETHOD EnableCapability(const char *capability) = 0;

  /**
     * Remove 'capability' from the innermost frame of the currently
     * executing script. Any setting of 'capability' from enclosing
     * frames thus comes into effect.
     */
  /* void revertCapability (in string capability); */
  NS_SCRIPTABLE NS_IMETHOD RevertCapability(const char *capability) = 0;

  /**
     * Disable 'capability' in the innermost frame of the currently executing
     * script.
     */
  /* void disableCapability (in string capability); */
  NS_SCRIPTABLE NS_IMETHOD DisableCapability(const char *capability) = 0;

  /**
     * Allow 'certificateID' to enable 'capability.' Can only be performed
     * by code signed by the system certificate.
     */
  /* void setCanEnableCapability (in AUTF8String certificateFingerprint, in string capability, in short canEnable); */
  NS_SCRIPTABLE NS_IMETHOD SetCanEnableCapability(const nsACString & certificateFingerprint, const char *capability, PRInt16 canEnable) = 0;

  /**
     * Return the principal of the specified object in the specified context.
     */
  /* [noscript] nsIPrincipal getObjectPrincipal (in JSContextPtr cx, in JSObjectPtr obj); */
  NS_IMETHOD GetObjectPrincipal(JSContext * cx, JSObject * obj, nsIPrincipal **_retval NS_OUTPARAM) = 0;

  /**
     * Returns true if the principal of the currently running script is the
     * system principal, false otherwise.
     */
  /* [noscript] boolean subjectPrincipalIsSystem (); */
  NS_IMETHOD SubjectPrincipalIsSystem(PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Returns OK if aJSContext and target have the same "origin"
     * (scheme, host, and port).
     */
  /* [noscript] void checkSameOrigin (in JSContextPtr aJSContext, in nsIURI aTargetURI); */
  NS_IMETHOD CheckSameOrigin(JSContext * aJSContext, nsIURI *aTargetURI) = 0;

  /**
     * Returns OK if aSourceURI and target have the same "origin"
     * (scheme, host, and port).
     * ReportError flag suppresses error reports for functions that
     * don't need reporting.
     */
  /* void checkSameOriginURI (in nsIURI aSourceURI, in nsIURI aTargetURI, in boolean reportError); */
  NS_SCRIPTABLE NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, PRBool reportError) = 0;

  /**
     * Returns the principal of the global object of the given context, or null
     * if no global or no principal.
     */
  /* [noscript] nsIPrincipal getPrincipalFromContext (in JSContextPtr cx); */
  NS_IMETHOD GetPrincipalFromContext(JSContext * cx, nsIPrincipal **_retval NS_OUTPARAM) = 0;

  /**
     * Get the principal for the given channel.  This will typically be the
     * channel owner if there is one, and the codebase principal for the
     * channel's URI otherwise.  aChannel must not be null.
     */
  /* nsIPrincipal getChannelPrincipal (in nsIChannel aChannel); */
  NS_SCRIPTABLE NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal **_retval NS_OUTPARAM) = 0;

  /**
     * Check whether a given principal is a system principal.  This allows us
     * to avoid handing back the system principal to script while allowing
     * script to check whether a given principal is system.
     */
  /* boolean isSystemPrincipal (in nsIPrincipal aPrincipal); */
  NS_SCRIPTABLE NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Same as getSubjectPrincipal(), only faster. cx must *never* be
     * passed null, and it must be the context on the top of the
     * context stack. Does *not* reference count the returned
     * principal.
     */
  /* [noscript, notxpcom] nsIPrincipal getCxSubjectPrincipal (in JSContextPtr cx); */
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext * cx) = 0;

  /* [noscript, notxpcom] nsIPrincipal getCxSubjectPrincipalAndFrame (in JSContextPtr cx, out JSStackFramePtr fp); */
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipalAndFrame(JSContext * cx, JSStackFrame * *fp NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptSecurityManager, NS_ISCRIPTSECURITYMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTSECURITYMANAGER \
  NS_IMETHOD CheckPropertyAccess(JSContext * aJSContext, JSObject * aJSObject, const char *aClassName, jsval aProperty, PRUint32 aAction); \
  NS_IMETHOD CheckConnect(JSContext * aJSContext, nsIURI *aTargetURI, const char *aClassName, const char *aProperty); \
  NS_IMETHOD CheckLoadURIFromScript(JSContext * cx, nsIURI *uri); \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, PRUint32 flags); \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURI(nsIURI *from, nsIURI *uri, PRUint32 flags); \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, PRUint32 flags); \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIStr(const nsACString & from, const nsACString & uri, PRUint32 flags); \
  NS_IMETHOD CheckFunctionAccess(JSContext * cx, void * funObj, void * targetObj); \
  NS_IMETHOD CanExecuteScripts(JSContext * cx, nsIPrincipal *principal, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal **_retval NS_OUTPARAM); \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal **_retval NS_OUTPARAM); \
  NS_IMETHOD GetCertificatePrincipal(const nsACString & aCertFingerprint, const nsACString & aSubjectName, const nsACString & aPrettyName, nsISupports *aCert, nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCodebasePrincipal(nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM); \
  NS_IMETHOD RequestCapability(nsIPrincipal *principal, const char *capability, PRInt16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsCapabilityEnabled(const char *capability, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EnableCapability(const char *capability); \
  NS_SCRIPTABLE NS_IMETHOD RevertCapability(const char *capability); \
  NS_SCRIPTABLE NS_IMETHOD DisableCapability(const char *capability); \
  NS_SCRIPTABLE NS_IMETHOD SetCanEnableCapability(const nsACString & certificateFingerprint, const char *capability, PRInt16 canEnable); \
  NS_IMETHOD GetObjectPrincipal(JSContext * cx, JSObject * obj, nsIPrincipal **_retval NS_OUTPARAM); \
  NS_IMETHOD SubjectPrincipalIsSystem(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD CheckSameOrigin(JSContext * aJSContext, nsIURI *aTargetURI); \
  NS_SCRIPTABLE NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, PRBool reportError); \
  NS_IMETHOD GetPrincipalFromContext(JSContext * cx, nsIPrincipal **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext * cx); \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipalAndFrame(JSContext * cx, JSStackFrame * *fp NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTSECURITYMANAGER(_to) \
  NS_IMETHOD CheckPropertyAccess(JSContext * aJSContext, JSObject * aJSObject, const char *aClassName, jsval aProperty, PRUint32 aAction) { return _to CheckPropertyAccess(aJSContext, aJSObject, aClassName, aProperty, aAction); } \
  NS_IMETHOD CheckConnect(JSContext * aJSContext, nsIURI *aTargetURI, const char *aClassName, const char *aProperty) { return _to CheckConnect(aJSContext, aTargetURI, aClassName, aProperty); } \
  NS_IMETHOD CheckLoadURIFromScript(JSContext * cx, nsIURI *uri) { return _to CheckLoadURIFromScript(cx, uri); } \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, PRUint32 flags) { return _to CheckLoadURIWithPrincipal(aPrincipal, uri, flags); } \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURI(nsIURI *from, nsIURI *uri, PRUint32 flags) { return _to CheckLoadURI(from, uri, flags); } \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, PRUint32 flags) { return _to CheckLoadURIStrWithPrincipal(aPrincipal, uri, flags); } \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIStr(const nsACString & from, const nsACString & uri, PRUint32 flags) { return _to CheckLoadURIStr(from, uri, flags); } \
  NS_IMETHOD CheckFunctionAccess(JSContext * cx, void * funObj, void * targetObj) { return _to CheckFunctionAccess(cx, funObj, targetObj); } \
  NS_IMETHOD CanExecuteScripts(JSContext * cx, nsIPrincipal *principal, PRBool *_retval NS_OUTPARAM) { return _to CanExecuteScripts(cx, principal, _retval); } \
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal **_retval NS_OUTPARAM) { return _to GetSubjectPrincipal(_retval); } \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal **_retval NS_OUTPARAM) { return _to GetSystemPrincipal(_retval); } \
  NS_IMETHOD GetCertificatePrincipal(const nsACString & aCertFingerprint, const nsACString & aSubjectName, const nsACString & aPrettyName, nsISupports *aCert, nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM) { return _to GetCertificatePrincipal(aCertFingerprint, aSubjectName, aPrettyName, aCert, aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCodebasePrincipal(nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM) { return _to GetCodebasePrincipal(aURI, _retval); } \
  NS_IMETHOD RequestCapability(nsIPrincipal *principal, const char *capability, PRInt16 *_retval NS_OUTPARAM) { return _to RequestCapability(principal, capability, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCapabilityEnabled(const char *capability, PRBool *_retval NS_OUTPARAM) { return _to IsCapabilityEnabled(capability, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnableCapability(const char *capability) { return _to EnableCapability(capability); } \
  NS_SCRIPTABLE NS_IMETHOD RevertCapability(const char *capability) { return _to RevertCapability(capability); } \
  NS_SCRIPTABLE NS_IMETHOD DisableCapability(const char *capability) { return _to DisableCapability(capability); } \
  NS_SCRIPTABLE NS_IMETHOD SetCanEnableCapability(const nsACString & certificateFingerprint, const char *capability, PRInt16 canEnable) { return _to SetCanEnableCapability(certificateFingerprint, capability, canEnable); } \
  NS_IMETHOD GetObjectPrincipal(JSContext * cx, JSObject * obj, nsIPrincipal **_retval NS_OUTPARAM) { return _to GetObjectPrincipal(cx, obj, _retval); } \
  NS_IMETHOD SubjectPrincipalIsSystem(PRBool *_retval NS_OUTPARAM) { return _to SubjectPrincipalIsSystem(_retval); } \
  NS_IMETHOD CheckSameOrigin(JSContext * aJSContext, nsIURI *aTargetURI) { return _to CheckSameOrigin(aJSContext, aTargetURI); } \
  NS_SCRIPTABLE NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, PRBool reportError) { return _to CheckSameOriginURI(aSourceURI, aTargetURI, reportError); } \
  NS_IMETHOD GetPrincipalFromContext(JSContext * cx, nsIPrincipal **_retval NS_OUTPARAM) { return _to GetPrincipalFromContext(cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal **_retval NS_OUTPARAM) { return _to GetChannelPrincipal(aChannel, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, PRBool *_retval NS_OUTPARAM) { return _to IsSystemPrincipal(aPrincipal, _retval); } \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext * cx) { return _to GetCxSubjectPrincipal(cx); } \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipalAndFrame(JSContext * cx, JSStackFrame * *fp NS_OUTPARAM) { return _to GetCxSubjectPrincipalAndFrame(cx, fp); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTSECURITYMANAGER(_to) \
  NS_IMETHOD CheckPropertyAccess(JSContext * aJSContext, JSObject * aJSObject, const char *aClassName, jsval aProperty, PRUint32 aAction) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckPropertyAccess(aJSContext, aJSObject, aClassName, aProperty, aAction); } \
  NS_IMETHOD CheckConnect(JSContext * aJSContext, nsIURI *aTargetURI, const char *aClassName, const char *aProperty) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckConnect(aJSContext, aTargetURI, aClassName, aProperty); } \
  NS_IMETHOD CheckLoadURIFromScript(JSContext * cx, nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIFromScript(cx, uri); } \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, PRUint32 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIWithPrincipal(aPrincipal, uri, flags); } \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURI(nsIURI *from, nsIURI *uri, PRUint32 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURI(from, uri, flags); } \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, PRUint32 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIStrWithPrincipal(aPrincipal, uri, flags); } \
  NS_SCRIPTABLE NS_IMETHOD CheckLoadURIStr(const nsACString & from, const nsACString & uri, PRUint32 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIStr(from, uri, flags); } \
  NS_IMETHOD CheckFunctionAccess(JSContext * cx, void * funObj, void * targetObj) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckFunctionAccess(cx, funObj, targetObj); } \
  NS_IMETHOD CanExecuteScripts(JSContext * cx, nsIPrincipal *principal, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanExecuteScripts(cx, principal, _retval); } \
  NS_IMETHOD GetSubjectPrincipal(nsIPrincipal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubjectPrincipal(_retval); } \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemPrincipal(_retval); } \
  NS_IMETHOD GetCertificatePrincipal(const nsACString & aCertFingerprint, const nsACString & aSubjectName, const nsACString & aPrettyName, nsISupports *aCert, nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertificatePrincipal(aCertFingerprint, aSubjectName, aPrettyName, aCert, aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCodebasePrincipal(nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCodebasePrincipal(aURI, _retval); } \
  NS_IMETHOD RequestCapability(nsIPrincipal *principal, const char *capability, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestCapability(principal, capability, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCapabilityEnabled(const char *capability, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCapabilityEnabled(capability, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnableCapability(const char *capability) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableCapability(capability); } \
  NS_SCRIPTABLE NS_IMETHOD RevertCapability(const char *capability) { return !_to ? NS_ERROR_NULL_POINTER : _to->RevertCapability(capability); } \
  NS_SCRIPTABLE NS_IMETHOD DisableCapability(const char *capability) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableCapability(capability); } \
  NS_SCRIPTABLE NS_IMETHOD SetCanEnableCapability(const nsACString & certificateFingerprint, const char *capability, PRInt16 canEnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCanEnableCapability(certificateFingerprint, capability, canEnable); } \
  NS_IMETHOD GetObjectPrincipal(JSContext * cx, JSObject * obj, nsIPrincipal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectPrincipal(cx, obj, _retval); } \
  NS_IMETHOD SubjectPrincipalIsSystem(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SubjectPrincipalIsSystem(_retval); } \
  NS_IMETHOD CheckSameOrigin(JSContext * aJSContext, nsIURI *aTargetURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckSameOrigin(aJSContext, aTargetURI); } \
  NS_SCRIPTABLE NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, PRBool reportError) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckSameOriginURI(aSourceURI, aTargetURI, reportError); } \
  NS_IMETHOD GetPrincipalFromContext(JSContext * cx, nsIPrincipal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrincipalFromContext(cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelPrincipal(aChannel, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSystemPrincipal(aPrincipal, _retval); } \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipal(JSContext * cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCxSubjectPrincipal(cx); } \
  NS_IMETHOD_(nsIPrincipal *) GetCxSubjectPrincipalAndFrame(JSContext * cx, JSStackFrame * *fp NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCxSubjectPrincipalAndFrame(cx, fp); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptSecurityManager : public nsIScriptSecurityManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTSECURITYMANAGER

  nsScriptSecurityManager();

private:
  ~nsScriptSecurityManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptSecurityManager, nsIScriptSecurityManager)

nsScriptSecurityManager::nsScriptSecurityManager()
{
  /* member initializers and constructor code */
}

nsScriptSecurityManager::~nsScriptSecurityManager()
{
  /* destructor code */
}

/* [noscript] void checkPropertyAccess (in JSContextPtr aJSContext, in JSObjectPtr aJSObject, in string aClassName, in JSVal aProperty, in PRUint32 aAction); */
NS_IMETHODIMP nsScriptSecurityManager::CheckPropertyAccess(JSContext * aJSContext, JSObject * aJSObject, const char *aClassName, jsval aProperty, PRUint32 aAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void checkConnect (in JSContextPtr aJSContext, in nsIURI aTargetURI, in string aClassName, in string aProperty); */
NS_IMETHODIMP nsScriptSecurityManager::CheckConnect(JSContext * aJSContext, nsIURI *aTargetURI, const char *aClassName, const char *aProperty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void checkLoadURIFromScript (in JSContextPtr cx, in nsIURI uri); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIFromScript(JSContext * cx, nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkLoadURIWithPrincipal (in nsIPrincipal aPrincipal, in nsIURI uri, in unsigned long flags); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, PRUint32 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkLoadURI (in nsIURI from, in nsIURI uri, in unsigned long flags); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURI(nsIURI *from, nsIURI *uri, PRUint32 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkLoadURIStrWithPrincipal (in nsIPrincipal aPrincipal, in AUTF8String uri, in unsigned long flags); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, PRUint32 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkLoadURIStr (in AUTF8String from, in AUTF8String uri, in unsigned long flags); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIStr(const nsACString & from, const nsACString & uri, PRUint32 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void checkFunctionAccess (in JSContextPtr cx, in voidPtr funObj, in voidPtr targetObj); */
NS_IMETHODIMP nsScriptSecurityManager::CheckFunctionAccess(JSContext * cx, void * funObj, void * targetObj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean canExecuteScripts (in JSContextPtr cx, in nsIPrincipal principal); */
NS_IMETHODIMP nsScriptSecurityManager::CanExecuteScripts(JSContext * cx, nsIPrincipal *principal, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPrincipal getSubjectPrincipal (); */
NS_IMETHODIMP nsScriptSecurityManager::GetSubjectPrincipal(nsIPrincipal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPrincipal getSystemPrincipal (); */
NS_IMETHODIMP nsScriptSecurityManager::GetSystemPrincipal(nsIPrincipal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPrincipal getCertificatePrincipal (in AUTF8String aCertFingerprint, in AUTF8String aSubjectName, in AUTF8String aPrettyName, in nsISupports aCert, in nsIURI aURI); */
NS_IMETHODIMP nsScriptSecurityManager::GetCertificatePrincipal(const nsACString & aCertFingerprint, const nsACString & aSubjectName, const nsACString & aPrettyName, nsISupports *aCert, nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getCodebasePrincipal (in nsIURI aURI); */
NS_IMETHODIMP nsScriptSecurityManager::GetCodebasePrincipal(nsIURI *aURI, nsIPrincipal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] short requestCapability (in nsIPrincipal principal, in string capability); */
NS_IMETHODIMP nsScriptSecurityManager::RequestCapability(nsIPrincipal *principal, const char *capability, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCapabilityEnabled (in string capability); */
NS_IMETHODIMP nsScriptSecurityManager::IsCapabilityEnabled(const char *capability, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableCapability (in string capability); */
NS_IMETHODIMP nsScriptSecurityManager::EnableCapability(const char *capability)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void revertCapability (in string capability); */
NS_IMETHODIMP nsScriptSecurityManager::RevertCapability(const char *capability)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableCapability (in string capability); */
NS_IMETHODIMP nsScriptSecurityManager::DisableCapability(const char *capability)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCanEnableCapability (in AUTF8String certificateFingerprint, in string capability, in short canEnable); */
NS_IMETHODIMP nsScriptSecurityManager::SetCanEnableCapability(const nsACString & certificateFingerprint, const char *capability, PRInt16 canEnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPrincipal getObjectPrincipal (in JSContextPtr cx, in JSObjectPtr obj); */
NS_IMETHODIMP nsScriptSecurityManager::GetObjectPrincipal(JSContext * cx, JSObject * obj, nsIPrincipal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean subjectPrincipalIsSystem (); */
NS_IMETHODIMP nsScriptSecurityManager::SubjectPrincipalIsSystem(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void checkSameOrigin (in JSContextPtr aJSContext, in nsIURI aTargetURI); */
NS_IMETHODIMP nsScriptSecurityManager::CheckSameOrigin(JSContext * aJSContext, nsIURI *aTargetURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkSameOriginURI (in nsIURI aSourceURI, in nsIURI aTargetURI, in boolean reportError); */
NS_IMETHODIMP nsScriptSecurityManager::CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, PRBool reportError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPrincipal getPrincipalFromContext (in JSContextPtr cx); */
NS_IMETHODIMP nsScriptSecurityManager::GetPrincipalFromContext(JSContext * cx, nsIPrincipal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getChannelPrincipal (in nsIChannel aChannel); */
NS_IMETHODIMP nsScriptSecurityManager::GetChannelPrincipal(nsIChannel *aChannel, nsIPrincipal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSystemPrincipal (in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsScriptSecurityManager::IsSystemPrincipal(nsIPrincipal *aPrincipal, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] nsIPrincipal getCxSubjectPrincipal (in JSContextPtr cx); */
NS_IMETHODIMP_(nsIPrincipal *) nsScriptSecurityManager::GetCxSubjectPrincipal(JSContext * cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] nsIPrincipal getCxSubjectPrincipalAndFrame (in JSContextPtr cx, out JSStackFramePtr fp); */
NS_IMETHODIMP_(nsIPrincipal *) nsScriptSecurityManager::GetCxSubjectPrincipalAndFrame(JSContext * cx, JSStackFrame * *fp NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SCRIPTSECURITYMANAGER_CONTRACTID "@mozilla.org/scriptsecuritymanager;1"
#define NS_SCRIPTSECURITYMANAGER_CLASSNAME "scriptsecuritymanager"

#endif /* __gen_nsIScriptSecurityManager_h__ */
