/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpref/public/nsISecurityPref.idl
 */

#ifndef __gen_nsISecurityPref_h__
#define __gen_nsISecurityPref_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISecurityPref */
#define NS_ISECURITYPREF_IID_STR "94afd973-8045-4c6c-89e6-75bdced4209e"

#define NS_ISECURITYPREF_IID \
  {0x94afd973, 0x8045, 0x4c6c, \
    { 0x89, 0xe6, 0x75, 0xbd, 0xce, 0xd4, 0x20, 0x9e }}

/**
 * Interface for accessing preferences, bypassing the usual security check on
 * preferences starting with "capability". This interface is used by
 * nsScriptSecurityManager which needs unchecked access to security prefs. 
 * *PLEASE* do not call this interface from any other file, as this 
 * would be insecure.
 *
 * THIS INTERFACE SHOULD NEVER BE MADE SCRIPTABLE 
 *
 * @see nsIPrefBranch
 */
class NS_NO_VTABLE nsISecurityPref : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECURITYPREF_IID)

  /**
   * Called to get the state of a "capability" boolean preference.
   *
   * @param pref     The boolean preference to get the state of.
   *
   * @return boolean The value of the requested boolean preference.
   *
   * @see securitySetBoolPref
   */
  /* boolean securityGetBoolPref (in string pref); */
  NS_IMETHOD SecurityGetBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Called to set the state of a "capability" boolean preference.
   *
   * @param pref   The boolean preference to set the state of.
   * @param value  The boolean value to set the preference to.
   *
   * @return NS_OK The value was successfully set.
   * @return Other The value was not set or is the wrong type.
   *
   * @see securityGetBoolPref
   */
  /* void securitySetBoolPref (in string pref, in boolean value); */
  NS_IMETHOD SecuritySetBoolPref(const char *pref, PRBool value) = 0;

  /**
   * Called to get the state of a "capability" string preference.
   *
   * @param pref    The string preference to retrieve.
   *
   * @return string The value of the requested string preference.
   *
   * @see securitySetCharPref
   */
  /* string securityGetCharPref (in string pref); */
  NS_IMETHOD SecurityGetCharPref(const char *pref, char **_retval NS_OUTPARAM) = 0;

  /**
   * Called to set the state of a "capability" string preference.
   *
   * @param pref   The string preference to set.
   * @param value  The string value to set the preference to.
   *
   * @return NS_OK The value was successfully set.
   * @return Other The value was not set or is the wrong type.
   *
   * @see securityGetCharPref
   */
  /* void securitySetCharPref (in string pref, in string value); */
  NS_IMETHOD SecuritySetCharPref(const char *pref, const char *value) = 0;

  /**
   * Called to get the state of a "capability" integer preference.
   *
   * @param pref  The integer preference to get the value of.
   *
   * @return long The value of the requested integer preference.
   *
   * @see securitySetIntPref
   */
  /* long securityGetIntPref (in string pref); */
  NS_IMETHOD SecurityGetIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Called to set the state of a "capability" integer preference.
   *
   * @param pref   The integer preference to set the value of.
   * @param value  The integer value to set the preference to.
   *
   * @return NS_OK The value was successfully set.
   * @return Other The value was not set or is the wrong type.
   *
   * @see securityGetIntPref
   */
  /* void securitySetIntPref (in string pref, in long value); */
  NS_IMETHOD SecuritySetIntPref(const char *pref, PRInt32 value) = 0;

  /**
   * Called to clear a user set value from a "capability" preference. This
   * will, in effect, reset the value to the default value. If no default value
   * exists the preference will cease to exist.
   *
   * @param pref_name The preference to be cleared.
   *
   * @note
   * This method does nothing if this object is a default branch.
   *
   * @return NS_OK The user preference was successfully cleared.
   * @return Other The preference does not exist or have a user set value.
   */
  /* void securityClearUserPref (in string pref_name); */
  NS_IMETHOD SecurityClearUserPref(const char *pref_name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecurityPref, NS_ISECURITYPREF_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECURITYPREF \
  NS_IMETHOD SecurityGetBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD SecuritySetBoolPref(const char *pref, PRBool value); \
  NS_IMETHOD SecurityGetCharPref(const char *pref, char **_retval NS_OUTPARAM); \
  NS_IMETHOD SecuritySetCharPref(const char *pref, const char *value); \
  NS_IMETHOD SecurityGetIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM); \
  NS_IMETHOD SecuritySetIntPref(const char *pref, PRInt32 value); \
  NS_IMETHOD SecurityClearUserPref(const char *pref_name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECURITYPREF(_to) \
  NS_IMETHOD SecurityGetBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM) { return _to SecurityGetBoolPref(pref, _retval); } \
  NS_IMETHOD SecuritySetBoolPref(const char *pref, PRBool value) { return _to SecuritySetBoolPref(pref, value); } \
  NS_IMETHOD SecurityGetCharPref(const char *pref, char **_retval NS_OUTPARAM) { return _to SecurityGetCharPref(pref, _retval); } \
  NS_IMETHOD SecuritySetCharPref(const char *pref, const char *value) { return _to SecuritySetCharPref(pref, value); } \
  NS_IMETHOD SecurityGetIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM) { return _to SecurityGetIntPref(pref, _retval); } \
  NS_IMETHOD SecuritySetIntPref(const char *pref, PRInt32 value) { return _to SecuritySetIntPref(pref, value); } \
  NS_IMETHOD SecurityClearUserPref(const char *pref_name) { return _to SecurityClearUserPref(pref_name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECURITYPREF(_to) \
  NS_IMETHOD SecurityGetBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SecurityGetBoolPref(pref, _retval); } \
  NS_IMETHOD SecuritySetBoolPref(const char *pref, PRBool value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SecuritySetBoolPref(pref, value); } \
  NS_IMETHOD SecurityGetCharPref(const char *pref, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SecurityGetCharPref(pref, _retval); } \
  NS_IMETHOD SecuritySetCharPref(const char *pref, const char *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SecuritySetCharPref(pref, value); } \
  NS_IMETHOD SecurityGetIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SecurityGetIntPref(pref, _retval); } \
  NS_IMETHOD SecuritySetIntPref(const char *pref, PRInt32 value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SecuritySetIntPref(pref, value); } \
  NS_IMETHOD SecurityClearUserPref(const char *pref_name) { return !_to ? NS_ERROR_NULL_POINTER : _to->SecurityClearUserPref(pref_name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecurityPref : public nsISecurityPref
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECURITYPREF

  nsSecurityPref();

private:
  ~nsSecurityPref();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSecurityPref, nsISecurityPref)

nsSecurityPref::nsSecurityPref()
{
  /* member initializers and constructor code */
}

nsSecurityPref::~nsSecurityPref()
{
  /* destructor code */
}

/* boolean securityGetBoolPref (in string pref); */
NS_IMETHODIMP nsSecurityPref::SecurityGetBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void securitySetBoolPref (in string pref, in boolean value); */
NS_IMETHODIMP nsSecurityPref::SecuritySetBoolPref(const char *pref, PRBool value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string securityGetCharPref (in string pref); */
NS_IMETHODIMP nsSecurityPref::SecurityGetCharPref(const char *pref, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void securitySetCharPref (in string pref, in string value); */
NS_IMETHODIMP nsSecurityPref::SecuritySetCharPref(const char *pref, const char *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long securityGetIntPref (in string pref); */
NS_IMETHODIMP nsSecurityPref::SecurityGetIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void securitySetIntPref (in string pref, in long value); */
NS_IMETHODIMP nsSecurityPref::SecuritySetIntPref(const char *pref, PRInt32 value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void securityClearUserPref (in string pref_name); */
NS_IMETHODIMP nsSecurityPref::SecurityClearUserPref(const char *pref_name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPrefSecurityCheck */
#define NS_IPREFSECURITYCHECK_IID_STR "c73c9a05-92ce-46e1-8f69-90a2a3a36104"

#define NS_IPREFSECURITYCHECK_IID \
  {0xc73c9a05, 0x92ce, 0x46e1, \
    { 0x8f, 0x69, 0x90, 0xa2, 0xa3, 0xa3, 0x61, 0x04 }}

/**
 * This interface allows checking whether getting capability prefs is allowed.
 */
class NS_NO_VTABLE nsIPrefSecurityCheck : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFSECURITYCHECK_IID)

  /**
   * Checks whether the currently executing script (if any) can access security
   * preferences. Corresponds to CapabilityPreferencesAccess.
   *
   * Exceptions from this method should be treated like a return value of false.
   */
  /* boolean canAccessSecurityPreferences (); */
  NS_IMETHOD CanAccessSecurityPreferences(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefSecurityCheck, NS_IPREFSECURITYCHECK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFSECURITYCHECK \
  NS_IMETHOD CanAccessSecurityPreferences(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFSECURITYCHECK(_to) \
  NS_IMETHOD CanAccessSecurityPreferences(PRBool *_retval NS_OUTPARAM) { return _to CanAccessSecurityPreferences(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFSECURITYCHECK(_to) \
  NS_IMETHOD CanAccessSecurityPreferences(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanAccessSecurityPreferences(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrefSecurityCheck : public nsIPrefSecurityCheck
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREFSECURITYCHECK

  nsPrefSecurityCheck();

private:
  ~nsPrefSecurityCheck();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrefSecurityCheck, nsIPrefSecurityCheck)

nsPrefSecurityCheck::nsPrefSecurityCheck()
{
  /* member initializers and constructor code */
}

nsPrefSecurityCheck::~nsPrefSecurityCheck()
{
  /* destructor code */
}

/* boolean canAccessSecurityPreferences (); */
NS_IMETHODIMP nsPrefSecurityCheck::CanAccessSecurityPreferences(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISecurityPref_h__ */
