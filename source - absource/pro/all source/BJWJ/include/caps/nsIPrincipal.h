/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/caps/idl/nsIPrincipal.idl
 */

#ifndef __gen_nsIPrincipal_h__
#define __gen_nsIPrincipal_h__


#ifndef __gen_nsISerializable_h__
#include "nsISerializable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
struct JSContext;
struct JSPrincipals;
class nsIURI; /* forward declaration */


/* starting interface:    nsIPrincipal */
#define NS_IPRINCIPAL_IID_STR "b8268b9a-2403-44ed-81e3-614075c92034"

#define NS_IPRINCIPAL_IID \
  {0xb8268b9a, 0x2403, 0x44ed, \
    { 0x81, 0xe3, 0x61, 0x40, 0x75, 0xc9, 0x20, 0x34 }}

/**
 * WARNING!! The JEP needs to call GetOrigin()  to support
 * JavaScript-to-Java LiveConnect.  So every change to the  nsIPrincipal
 * interface (big enough to change its IID) also breaks JavaScript-to-Java
 * LiveConnect on mac.
 *
 * If you REALLY have to change this interface, please mark your bug as
 * blocking bug 293973.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPrincipal : public nsISerializable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINCIPAL_IID)

  /**
     * Values of capabilities for each principal. Order is
     * significant: if an operation is performed on a set
     * of capabilities, the minimum is computed.
     */
  enum { ENABLE_DENIED = 1 };

  enum { ENABLE_UNKNOWN = 2 };

  enum { ENABLE_WITH_USER_PERMISSION = 3 };

  enum { ENABLE_GRANTED = 4 };

  /**
     * Returns the security preferences associated with this principal.
     * prefBranch will be set to the pref branch to which these preferences
     * pertain.  id is a pseudo-unique identifier, pertaining to either the
     * fingerprint or the origin.  subjectName is a name that identifies the
     * entity this principal represents (may be empty).  grantedList and
     * deniedList are space-separated lists of capabilities which were
     * explicitly granted or denied by a pref.  isTrusted is a boolean that
     * indicates whether this is a codebaseTrusted certificate.
     */
  /* [noscript] void getPreferences (out string prefBranch, out string id, out string subjectName, out string grantedList, out string deniedList, out boolean isTrusted); */
  NS_IMETHOD GetPreferences(char **prefBranch NS_OUTPARAM, char **id NS_OUTPARAM, char **subjectName NS_OUTPARAM, char **grantedList NS_OUTPARAM, char **deniedList NS_OUTPARAM, PRBool *isTrusted NS_OUTPARAM) = 0;

  /**
     * Returns whether the other principal is equivalent to this principal.
     * Principals are considered equal if they are the same principal,
     * they have the same origin, or have the same certificate fingerprint ID
     */
  /* boolean equals (in nsIPrincipal other); */
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Returns a hash value for the principal.
     */
  /* [noscript] readonly attribute unsigned long hashValue; */
  NS_IMETHOD GetHashValue(PRUint32 *aHashValue) = 0;

  /**
     * Returns the JS equivalent of the principal.
     * @see JSPrincipals.h
     */
  /* [noscript] JSPrincipals getJSPrincipals (in JSContext cx); */
  NS_IMETHOD GetJSPrincipals(JSContext * cx, JSPrincipals * *_retval NS_OUTPARAM) = 0;

  /**
     * The domain security policy of the principal.
     */
  /* [noscript] attribute voidPtr securityPolicy; */
  NS_IMETHOD GetSecurityPolicy(void * *aSecurityPolicy) = 0;
  NS_IMETHOD SetSecurityPolicy(void * aSecurityPolicy) = 0;

  /* [noscript] short canEnableCapability (in string capability); */
  NS_IMETHOD CanEnableCapability(const char *capability, PRInt16 *_retval NS_OUTPARAM) = 0;

  /* [noscript] void setCanEnableCapability (in string capability, in short canEnable); */
  NS_IMETHOD SetCanEnableCapability(const char *capability, PRInt16 canEnable) = 0;

  /* [noscript] boolean isCapabilityEnabled (in string capability, in voidPtr annotation); */
  NS_IMETHOD IsCapabilityEnabled(const char *capability, void * annotation, PRBool *_retval NS_OUTPARAM) = 0;

  /* [noscript] void enableCapability (in string capability, inout voidPtr annotation); */
  NS_IMETHOD EnableCapability(const char *capability, void * *annotation NS_INOUTPARAM) = 0;

  /* [noscript] void revertCapability (in string capability, inout voidPtr annotation); */
  NS_IMETHOD RevertCapability(const char *capability, void * *annotation NS_INOUTPARAM) = 0;

  /* [noscript] void disableCapability (in string capability, inout voidPtr annotation); */
  NS_IMETHOD DisableCapability(const char *capability, void * *annotation NS_INOUTPARAM) = 0;

  /**
     * The codebase URI to which this principal pertains.  This is
     * generally the document URI.
     */
  /* [noscript] readonly attribute nsIURI URI; */
  NS_IMETHOD GetURI(nsIURI * *aURI) = 0;

  /**
     * The domain URI to which this principal pertains.
     * This is congruent with HTMLDocument.domain, and may be null.
     * Setting this has no effect on the URI.
     */
  /* [noscript] attribute nsIURI domain; */
  NS_IMETHOD GetDomain(nsIURI * *aDomain) = 0;
  NS_IMETHOD SetDomain(nsIURI * aDomain) = 0;

  /**
     * The origin of this principal's codebase URI.
     * An origin is defined as: scheme + host + port.
     */
  /* [noscript] readonly attribute string origin; */
  NS_IMETHOD GetOrigin(char * *aOrigin) = 0;

  /**
     * Whether this principal is associated with a certificate.
     */
  /* readonly attribute boolean hasCertificate; */
  NS_SCRIPTABLE NS_IMETHOD GetHasCertificate(PRBool *aHasCertificate) = 0;

  /**
     * The fingerprint ID of this principal's certificate.
     * Throws if there is no certificate associated with this principal.
     */
  /* readonly attribute AUTF8String fingerprint; */
  NS_SCRIPTABLE NS_IMETHOD GetFingerprint(nsACString & aFingerprint) = 0;

  /**
     * The pretty name for the certificate.  This sort of (but not really)
     * identifies the subject of the certificate (the entity that stands behind
     * the certificate).  Note that this may be empty; prefer to get the
     * certificate itself and get this information from it, since that may
     * provide more information.
     *
     * Throws if there is no certificate associated with this principal.
     */
  /* readonly attribute AUTF8String prettyName; */
  NS_SCRIPTABLE NS_IMETHOD GetPrettyName(nsACString & aPrettyName) = 0;

  /**
     * Returns whether the other principal is equal to or weaker than this
     * principal.  Principals are equal if they are the same object, they
     * have the same origin, or they have the same certificate ID.
     *
     * Thus a principal always subsumes itself.
     *
     * The system principal subsumes itself and all other principals.
     *
     * A null principal (corresponding to an unknown, hence assumed minimally
     * privileged, security context) is not equal to any other principal
     * (including other null principals), and therefore does not subsume
     * anything but itself.
     *
     * Both codebase and certificate principals are subsumed by the system
     * principal, but no codebase or certificate principal yet subsumes any
     * other codebase or certificate principal.  This may change in a future
     * release; note that nsIPrincipal is unfrozen, not slated to be frozen.
     *
     * XXXbz except see bug 147145!
     *
     * Note for the future: Perhaps we should consider a certificate principal
     * for a given URI subsuming a codebase principal for the same URI?  Not
     * sure what the immediate benefit would be, but I think the setup could
     * make some code (e.g. MaybeDowngradeToCodebase) clearer.
     */
  /* [noscript] boolean subsumes (in nsIPrincipal other); */
  NS_IMETHOD Subsumes(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Checks whether this principal is allowed to load the network resource
     * located at the given URI under the same-origin policy. This means that
     * codebase principals are only allowed to load resources from the same
     * domain, the system principal is allowed to load anything, and null
     * principals are not allowed to load anything.
     *
     * If the load is allowed this function does nothing. If the load is not
     * allowed the function throws NS_ERROR_DOM_BAD_URI.
     *
     * NOTE: Other policies might override this, such as the Access-Control
     *       specification.
     * NOTE: The 'domain' attribute has no effect on the behaviour of this
     *       function.
     *
     *
     * @param uri    The URI about to be loaded.
     * @param report If true, will report a warning to the console service
     *               if the load is not allowed.
     * @throws NS_ERROR_DOM_BAD_URI if the load is not allowed.
     */
  /* [noscript] void checkMayLoad (in nsIURI uri, in boolean report); */
  NS_IMETHOD CheckMayLoad(nsIURI *uri, PRBool report) = 0;

  /**
     * The subject name for the certificate.  This actually identifies the
     * subject of the certificate.  This may well not be a string that would
     * mean much to a typical user on its own (e.g. it may have a number of
     * different names all concatenated together with some information on what
     * they mean in between).
     *
     * Throws if there is no certificate associated with this principal.
     */
  /* readonly attribute AUTF8String subjectName; */
  NS_SCRIPTABLE NS_IMETHOD GetSubjectName(nsACString & aSubjectName) = 0;

  /**
     * The certificate associated with this principal, if any.  If there isn't
     * one, this will return null.  Getting this attribute never throws.
     */
  /* readonly attribute nsISupports certificate; */
  NS_SCRIPTABLE NS_IMETHOD GetCertificate(nsISupports * *aCertificate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrincipal, NS_IPRINCIPAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINCIPAL \
  NS_IMETHOD GetPreferences(char **prefBranch NS_OUTPARAM, char **id NS_OUTPARAM, char **subjectName NS_OUTPARAM, char **grantedList NS_OUTPARAM, char **deniedList NS_OUTPARAM, PRBool *isTrusted NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetHashValue(PRUint32 *aHashValue); \
  NS_IMETHOD GetJSPrincipals(JSContext * cx, JSPrincipals * *_retval NS_OUTPARAM); \
  NS_IMETHOD GetSecurityPolicy(void * *aSecurityPolicy); \
  NS_IMETHOD SetSecurityPolicy(void * aSecurityPolicy); \
  NS_IMETHOD CanEnableCapability(const char *capability, PRInt16 *_retval NS_OUTPARAM); \
  NS_IMETHOD SetCanEnableCapability(const char *capability, PRInt16 canEnable); \
  NS_IMETHOD IsCapabilityEnabled(const char *capability, void * annotation, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD EnableCapability(const char *capability, void * *annotation NS_INOUTPARAM); \
  NS_IMETHOD RevertCapability(const char *capability, void * *annotation NS_INOUTPARAM); \
  NS_IMETHOD DisableCapability(const char *capability, void * *annotation NS_INOUTPARAM); \
  NS_IMETHOD GetURI(nsIURI * *aURI); \
  NS_IMETHOD GetDomain(nsIURI * *aDomain); \
  NS_IMETHOD SetDomain(nsIURI * aDomain); \
  NS_IMETHOD GetOrigin(char * *aOrigin); \
  NS_SCRIPTABLE NS_IMETHOD GetHasCertificate(PRBool *aHasCertificate); \
  NS_SCRIPTABLE NS_IMETHOD GetFingerprint(nsACString & aFingerprint); \
  NS_SCRIPTABLE NS_IMETHOD GetPrettyName(nsACString & aPrettyName); \
  NS_IMETHOD Subsumes(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD CheckMayLoad(nsIURI *uri, PRBool report); \
  NS_SCRIPTABLE NS_IMETHOD GetSubjectName(nsACString & aSubjectName); \
  NS_SCRIPTABLE NS_IMETHOD GetCertificate(nsISupports * *aCertificate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINCIPAL(_to) \
  NS_IMETHOD GetPreferences(char **prefBranch NS_OUTPARAM, char **id NS_OUTPARAM, char **subjectName NS_OUTPARAM, char **grantedList NS_OUTPARAM, char **deniedList NS_OUTPARAM, PRBool *isTrusted NS_OUTPARAM) { return _to GetPreferences(prefBranch, id, subjectName, grantedList, deniedList, isTrusted); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM) { return _to Equals(other, _retval); } \
  NS_IMETHOD GetHashValue(PRUint32 *aHashValue) { return _to GetHashValue(aHashValue); } \
  NS_IMETHOD GetJSPrincipals(JSContext * cx, JSPrincipals * *_retval NS_OUTPARAM) { return _to GetJSPrincipals(cx, _retval); } \
  NS_IMETHOD GetSecurityPolicy(void * *aSecurityPolicy) { return _to GetSecurityPolicy(aSecurityPolicy); } \
  NS_IMETHOD SetSecurityPolicy(void * aSecurityPolicy) { return _to SetSecurityPolicy(aSecurityPolicy); } \
  NS_IMETHOD CanEnableCapability(const char *capability, PRInt16 *_retval NS_OUTPARAM) { return _to CanEnableCapability(capability, _retval); } \
  NS_IMETHOD SetCanEnableCapability(const char *capability, PRInt16 canEnable) { return _to SetCanEnableCapability(capability, canEnable); } \
  NS_IMETHOD IsCapabilityEnabled(const char *capability, void * annotation, PRBool *_retval NS_OUTPARAM) { return _to IsCapabilityEnabled(capability, annotation, _retval); } \
  NS_IMETHOD EnableCapability(const char *capability, void * *annotation NS_INOUTPARAM) { return _to EnableCapability(capability, annotation); } \
  NS_IMETHOD RevertCapability(const char *capability, void * *annotation NS_INOUTPARAM) { return _to RevertCapability(capability, annotation); } \
  NS_IMETHOD DisableCapability(const char *capability, void * *annotation NS_INOUTPARAM) { return _to DisableCapability(capability, annotation); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return _to GetURI(aURI); } \
  NS_IMETHOD GetDomain(nsIURI * *aDomain) { return _to GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(nsIURI * aDomain) { return _to SetDomain(aDomain); } \
  NS_IMETHOD GetOrigin(char * *aOrigin) { return _to GetOrigin(aOrigin); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasCertificate(PRBool *aHasCertificate) { return _to GetHasCertificate(aHasCertificate); } \
  NS_SCRIPTABLE NS_IMETHOD GetFingerprint(nsACString & aFingerprint) { return _to GetFingerprint(aFingerprint); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrettyName(nsACString & aPrettyName) { return _to GetPrettyName(aPrettyName); } \
  NS_IMETHOD Subsumes(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM) { return _to Subsumes(other, _retval); } \
  NS_IMETHOD CheckMayLoad(nsIURI *uri, PRBool report) { return _to CheckMayLoad(uri, report); } \
  NS_SCRIPTABLE NS_IMETHOD GetSubjectName(nsACString & aSubjectName) { return _to GetSubjectName(aSubjectName); } \
  NS_SCRIPTABLE NS_IMETHOD GetCertificate(nsISupports * *aCertificate) { return _to GetCertificate(aCertificate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINCIPAL(_to) \
  NS_IMETHOD GetPreferences(char **prefBranch NS_OUTPARAM, char **id NS_OUTPARAM, char **subjectName NS_OUTPARAM, char **grantedList NS_OUTPARAM, char **deniedList NS_OUTPARAM, PRBool *isTrusted NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferences(prefBranch, id, subjectName, grantedList, deniedList, isTrusted); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(other, _retval); } \
  NS_IMETHOD GetHashValue(PRUint32 *aHashValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHashValue(aHashValue); } \
  NS_IMETHOD GetJSPrincipals(JSContext * cx, JSPrincipals * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSPrincipals(cx, _retval); } \
  NS_IMETHOD GetSecurityPolicy(void * *aSecurityPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityPolicy(aSecurityPolicy); } \
  NS_IMETHOD SetSecurityPolicy(void * aSecurityPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityPolicy(aSecurityPolicy); } \
  NS_IMETHOD CanEnableCapability(const char *capability, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanEnableCapability(capability, _retval); } \
  NS_IMETHOD SetCanEnableCapability(const char *capability, PRInt16 canEnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCanEnableCapability(capability, canEnable); } \
  NS_IMETHOD IsCapabilityEnabled(const char *capability, void * annotation, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCapabilityEnabled(capability, annotation, _retval); } \
  NS_IMETHOD EnableCapability(const char *capability, void * *annotation NS_INOUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableCapability(capability, annotation); } \
  NS_IMETHOD RevertCapability(const char *capability, void * *annotation NS_INOUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RevertCapability(capability, annotation); } \
  NS_IMETHOD DisableCapability(const char *capability, void * *annotation NS_INOUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableCapability(capability, annotation); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetDomain(nsIURI * *aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(nsIURI * aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } \
  NS_IMETHOD GetOrigin(char * *aOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrigin(aOrigin); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasCertificate(PRBool *aHasCertificate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasCertificate(aHasCertificate); } \
  NS_SCRIPTABLE NS_IMETHOD GetFingerprint(nsACString & aFingerprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFingerprint(aFingerprint); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrettyName(nsACString & aPrettyName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrettyName(aPrettyName); } \
  NS_IMETHOD Subsumes(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Subsumes(other, _retval); } \
  NS_IMETHOD CheckMayLoad(nsIURI *uri, PRBool report) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckMayLoad(uri, report); } \
  NS_SCRIPTABLE NS_IMETHOD GetSubjectName(nsACString & aSubjectName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubjectName(aSubjectName); } \
  NS_SCRIPTABLE NS_IMETHOD GetCertificate(nsISupports * *aCertificate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertificate(aCertificate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrincipal : public nsIPrincipal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINCIPAL

  nsPrincipal();

private:
  ~nsPrincipal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrincipal, nsIPrincipal)

nsPrincipal::nsPrincipal()
{
  /* member initializers and constructor code */
}

nsPrincipal::~nsPrincipal()
{
  /* destructor code */
}

/* [noscript] void getPreferences (out string prefBranch, out string id, out string subjectName, out string grantedList, out string deniedList, out boolean isTrusted); */
NS_IMETHODIMP nsPrincipal::GetPreferences(char **prefBranch NS_OUTPARAM, char **id NS_OUTPARAM, char **subjectName NS_OUTPARAM, char **grantedList NS_OUTPARAM, char **deniedList NS_OUTPARAM, PRBool *isTrusted NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIPrincipal other); */
NS_IMETHODIMP nsPrincipal::Equals(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute unsigned long hashValue; */
NS_IMETHODIMP nsPrincipal::GetHashValue(PRUint32 *aHashValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSPrincipals getJSPrincipals (in JSContext cx); */
NS_IMETHODIMP nsPrincipal::GetJSPrincipals(JSContext * cx, JSPrincipals * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute voidPtr securityPolicy; */
NS_IMETHODIMP nsPrincipal::GetSecurityPolicy(void * *aSecurityPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrincipal::SetSecurityPolicy(void * aSecurityPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] short canEnableCapability (in string capability); */
NS_IMETHODIMP nsPrincipal::CanEnableCapability(const char *capability, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setCanEnableCapability (in string capability, in short canEnable); */
NS_IMETHODIMP nsPrincipal::SetCanEnableCapability(const char *capability, PRInt16 canEnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean isCapabilityEnabled (in string capability, in voidPtr annotation); */
NS_IMETHODIMP nsPrincipal::IsCapabilityEnabled(const char *capability, void * annotation, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void enableCapability (in string capability, inout voidPtr annotation); */
NS_IMETHODIMP nsPrincipal::EnableCapability(const char *capability, void * *annotation NS_INOUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void revertCapability (in string capability, inout voidPtr annotation); */
NS_IMETHODIMP nsPrincipal::RevertCapability(const char *capability, void * *annotation NS_INOUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void disableCapability (in string capability, inout voidPtr annotation); */
NS_IMETHODIMP nsPrincipal::DisableCapability(const char *capability, void * *annotation NS_INOUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIURI URI; */
NS_IMETHODIMP nsPrincipal::GetURI(nsIURI * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIURI domain; */
NS_IMETHODIMP nsPrincipal::GetDomain(nsIURI * *aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrincipal::SetDomain(nsIURI * aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute string origin; */
NS_IMETHODIMP nsPrincipal::GetOrigin(char * *aOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasCertificate; */
NS_IMETHODIMP nsPrincipal::GetHasCertificate(PRBool *aHasCertificate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String fingerprint; */
NS_IMETHODIMP nsPrincipal::GetFingerprint(nsACString & aFingerprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String prettyName; */
NS_IMETHODIMP nsPrincipal::GetPrettyName(nsACString & aPrettyName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean subsumes (in nsIPrincipal other); */
NS_IMETHODIMP nsPrincipal::Subsumes(nsIPrincipal *other, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void checkMayLoad (in nsIURI uri, in boolean report); */
NS_IMETHODIMP nsPrincipal::CheckMayLoad(nsIURI *uri, PRBool report)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String subjectName; */
NS_IMETHODIMP nsPrincipal::GetSubjectName(nsACString & aSubjectName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports certificate; */
NS_IMETHODIMP nsPrincipal::GetCertificate(nsISupports * *aCertificate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrincipal_h__ */
