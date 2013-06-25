/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpref/public/nsIPref.idl
 */

#ifndef __gen_nsIPref_h__
#define __gen_nsIPref_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPrefService_h__
#include "nsIPrefService.h"
#endif

#ifndef __gen_nsIPrefBranch_h__
#include "nsIPrefBranch.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILocalFile; /* forward declaration */

class nsIObserver; /* forward declaration */

class nsIFileSpec; /* forward declaration */

#ifndef have_PrefChangedFunc_typedef
typedef int (*PR_CALLBACK PrefChangedFunc)(const char *, void *);
#define have_PrefChangedFunc_typedef
#endif
typedef void (*PrefEnumerationFunc)(const char *, void *);
#define NS_PREF_CID                                    \
  { /* {dc26e0e0-ca94-11d1-a9a4-00805f8a7ac4} */       \
    0xdc26e0e0,                                        \
    0xca94,                                            \
    0x11d1,                                            \
    { 0xa9, 0xa4, 0x00, 0x80, 0x5f, 0x8a, 0x7a, 0xc4 } \
  }
#define NS_PREF_CONTRACTID \
  "@mozilla.org/preferences;1" 
#define NS_PREF_CLASSNAME "Preferences Service"
 
#define NS_PREF_VALUE_CHANGED 1 

/* starting interface:    nsIPref */
#define NS_IPREF_IID_STR "a22ad7b0-ca86-11d1-a9a4-00805f8a7ac4"

#define NS_IPREF_IID \
  {0xa22ad7b0, 0xca86, 0x11d1, \
    { 0xa9, 0xa4, 0x00, 0x80, 0x5f, 0x8a, 0x7a, 0xc4 }}

/**
 * This entire interface is deprecated and should not be used.
 * See nsIPrefService and nsIPrefBranch for the new implementations.
 *
 * @status DEPRECATED  Replaced by nsIPrefService and nsIPrefBranch
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPref : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREF_IID)

  /* void readUserPrefs (in nsIFile aFile); */
  NS_SCRIPTABLE NS_IMETHOD ReadUserPrefs(nsIFile *aFile) = 0;

  /* void ResetPrefs (); */
  NS_SCRIPTABLE NS_IMETHOD ResetPrefs(void) = 0;

  /* void ResetUserPrefs (); */
  NS_SCRIPTABLE NS_IMETHOD ResetUserPrefs(void) = 0;

  /* void savePrefFile (in nsIFile aFile); */
  NS_SCRIPTABLE NS_IMETHOD SavePrefFile(nsIFile *aFile) = 0;

  /* nsIPrefBranch getBranch (in string aPrefRoot); */
  NS_SCRIPTABLE NS_IMETHOD GetBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM) = 0;

  /* nsIPrefBranch getDefaultBranch (in string aPrefRoot); */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM) = 0;

  enum { ePrefInvalid = 0 };

  enum { ePrefLocked = 1 };

  enum { ePrefUserset = 2 };

  enum { ePrefConfig = 4 };

  enum { ePrefRemote = 8 };

  enum { ePrefLilocal = 16 };

  enum { ePrefString = 32 };

  enum { ePrefInt = 64 };

  enum { ePrefBool = 128 };

  enum { ePrefValuetypeMask = 224 };

  /* readonly attribute string root; */
  NS_SCRIPTABLE NS_IMETHOD GetRoot(char * *aRoot) = 0;

  /* long GetPrefType (in string aPrefName); */
  NS_SCRIPTABLE NS_IMETHOD GetPrefType(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* boolean GetBoolPref (in string aPrefName); */
  NS_SCRIPTABLE NS_IMETHOD GetBoolPref(const char *aPrefName, PRBool *_retval NS_OUTPARAM) = 0;

  /* void SetBoolPref (in string aPrefName, in long aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetBoolPref(const char *aPrefName, PRInt32 aValue) = 0;

  /* string GetCharPref (in string aPrefName); */
  NS_SCRIPTABLE NS_IMETHOD GetCharPref(const char *aPrefName, char **_retval NS_OUTPARAM) = 0;

  /* void SetCharPref (in string aPrefName, in string aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetCharPref(const char *aPrefName, const char *aValue) = 0;

  /* long GetIntPref (in string aPrefName); */
  NS_SCRIPTABLE NS_IMETHOD GetIntPref(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void SetIntPref (in string aPrefName, in long aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetIntPref(const char *aPrefName, PRInt32 aValue) = 0;

  /* void getComplexValue (in string aPrefName, in nsIIDRef aType, [iid_is (aType), retval] out nsQIResult aValue); */
  NS_SCRIPTABLE NS_IMETHOD GetComplexValue(const char *aPrefName, const nsIID & aType, void * *aValue NS_OUTPARAM) = 0;

  /* void setComplexValue (in string aPrefName, in nsIIDRef aType, in nsISupports aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetComplexValue(const char *aPrefName, const nsIID & aType, nsISupports *aValue) = 0;

  /* void ClearUserPref (in string aPrefName); */
  NS_SCRIPTABLE NS_IMETHOD ClearUserPref(const char *aPrefName) = 0;

  /* boolean PrefIsLocked (in string aPrefName); */
  NS_SCRIPTABLE NS_IMETHOD PrefIsLocked(const char *aPrefName, PRBool *_retval NS_OUTPARAM) = 0;

  /* void lockPref (in string aPrefName); */
  NS_SCRIPTABLE NS_IMETHOD LockPref(const char *aPrefName) = 0;

  /* void unlockPref (in string aPrefName); */
  NS_SCRIPTABLE NS_IMETHOD UnlockPref(const char *aPrefName) = 0;

  /* void resetBranch (in string aStartingAt); */
  NS_SCRIPTABLE NS_IMETHOD ResetBranch(const char *aStartingAt) = 0;

  /* void DeleteBranch (in string aStartingAt); */
  NS_SCRIPTABLE NS_IMETHOD DeleteBranch(const char *aStartingAt) = 0;

  /* void getChildList (in string aStartingAt, out unsigned long aCount, [array, size_is (aCount), retval] out string aChildArray); */
  NS_SCRIPTABLE NS_IMETHOD GetChildList(const char *aStartingAt, PRUint32 *aCount NS_OUTPARAM, char ***aChildArray NS_OUTPARAM) = 0;

  /* void addObserver (in string aDomain, in nsIObserver aObserver, in boolean aHoldWeak); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const char *aDomain, nsIObserver *aObserver, PRBool aHoldWeak) = 0;

  /* void removeObserver (in string aDomain, in nsIObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const char *aDomain, nsIObserver *aObserver) = 0;

  /* string CopyCharPref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD CopyCharPref(const char *pref, char **_retval NS_OUTPARAM) = 0;

  /* string CopyDefaultCharPref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD CopyDefaultCharPref(const char *pref, char **_retval NS_OUTPARAM) = 0;

  /* boolean GetDefaultBoolPref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM) = 0;

  /* long GetDefaultIntPref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void SetDefaultBoolPref (in string pref, in boolean value); */
  NS_SCRIPTABLE NS_IMETHOD SetDefaultBoolPref(const char *pref, PRBool value) = 0;

  /* void SetDefaultCharPref (in string pref, in string value); */
  NS_SCRIPTABLE NS_IMETHOD SetDefaultCharPref(const char *pref, const char *value) = 0;

  /* void SetDefaultIntPref (in string pref, in long value); */
  NS_SCRIPTABLE NS_IMETHOD SetDefaultIntPref(const char *pref, PRInt32 value) = 0;

  /* wstring CopyUnicharPref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD CopyUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* wstring CopyDefaultUnicharPref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD CopyDefaultUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* void SetUnicharPref (in string pref, in wstring value); */
  NS_SCRIPTABLE NS_IMETHOD SetUnicharPref(const char *pref, const PRUnichar *value) = 0;

  /* void SetDefaultUnicharPref (in string pref, in wstring value); */
  NS_SCRIPTABLE NS_IMETHOD SetDefaultUnicharPref(const char *pref, const PRUnichar *value) = 0;

  /* wstring getLocalizedUnicharPref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD GetLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* wstring getDefaultLocalizedUnicharPref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* nsIFileSpec GetFilePref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD GetFilePref(const char *pref, nsIFileSpec **_retval NS_OUTPARAM) = 0;

  /* void SetFilePref (in string pref, in nsIFileSpec value, in boolean setDefault); */
  NS_SCRIPTABLE NS_IMETHOD SetFilePref(const char *pref, nsIFileSpec *value, PRBool setDefault) = 0;

  /* nsILocalFile getFileXPref (in string pref); */
  NS_SCRIPTABLE NS_IMETHOD GetFileXPref(const char *pref, nsILocalFile **_retval NS_OUTPARAM) = 0;

  /* void setFileXPref (in string pref, in nsILocalFile value); */
  NS_SCRIPTABLE NS_IMETHOD SetFileXPref(const char *pref, nsILocalFile *value) = 0;

  /* [noscript] void RegisterCallback (in string domain, in PrefChangedFunc callback, in voidPtr closure); */
  NS_IMETHOD RegisterCallback(const char *domain, PrefChangedFunc callback, void * closure) = 0;

  /* [noscript] void UnregisterCallback (in string domain, in PrefChangedFunc callback, in voidPtr closure); */
  NS_IMETHOD UnregisterCallback(const char *domain, PrefChangedFunc callback, void * closure) = 0;

  /**
   * EnumerateChildren
   *
   * Call back function "callback" with every preference string
   * having prefix "parent". Pass "data" to "callback" when calling.
   * 
   * @param parent A string representation of a prefix of preferences
   * @param callback A function to call back for each matching preference
   * @param data A piece of data to pass on to the callback
   */
  /* [noscript] void EnumerateChildren (in string parent, in PrefEnumerationFunc callback, in voidPtr data); */
  NS_IMETHOD EnumerateChildren(const char *parent, PrefEnumerationFunc callback, void * data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPref, NS_IPREF_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREF \
  NS_SCRIPTABLE NS_IMETHOD ReadUserPrefs(nsIFile *aFile); \
  NS_SCRIPTABLE NS_IMETHOD ResetPrefs(void); \
  NS_SCRIPTABLE NS_IMETHOD ResetUserPrefs(void); \
  NS_SCRIPTABLE NS_IMETHOD SavePrefFile(nsIFile *aFile); \
  NS_SCRIPTABLE NS_IMETHOD GetBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(char * *aRoot); \
  NS_SCRIPTABLE NS_IMETHOD GetPrefType(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBoolPref(const char *aPrefName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetBoolPref(const char *aPrefName, PRInt32 aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetCharPref(const char *aPrefName, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCharPref(const char *aPrefName, const char *aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetIntPref(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetIntPref(const char *aPrefName, PRInt32 aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetComplexValue(const char *aPrefName, const nsIID & aType, void * *aValue NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetComplexValue(const char *aPrefName, const nsIID & aType, nsISupports *aValue); \
  NS_SCRIPTABLE NS_IMETHOD ClearUserPref(const char *aPrefName); \
  NS_SCRIPTABLE NS_IMETHOD PrefIsLocked(const char *aPrefName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LockPref(const char *aPrefName); \
  NS_SCRIPTABLE NS_IMETHOD UnlockPref(const char *aPrefName); \
  NS_SCRIPTABLE NS_IMETHOD ResetBranch(const char *aStartingAt); \
  NS_SCRIPTABLE NS_IMETHOD DeleteBranch(const char *aStartingAt); \
  NS_SCRIPTABLE NS_IMETHOD GetChildList(const char *aStartingAt, PRUint32 *aCount NS_OUTPARAM, char ***aChildArray NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const char *aDomain, nsIObserver *aObserver, PRBool aHoldWeak); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const char *aDomain, nsIObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD CopyCharPref(const char *pref, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CopyDefaultCharPref(const char *pref, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultBoolPref(const char *pref, PRBool value); \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultCharPref(const char *pref, const char *value); \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultIntPref(const char *pref, PRInt32 value); \
  NS_SCRIPTABLE NS_IMETHOD CopyUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CopyDefaultUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetUnicharPref(const char *pref, const PRUnichar *value); \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultUnicharPref(const char *pref, const PRUnichar *value); \
  NS_SCRIPTABLE NS_IMETHOD GetLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFilePref(const char *pref, nsIFileSpec **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetFilePref(const char *pref, nsIFileSpec *value, PRBool setDefault); \
  NS_SCRIPTABLE NS_IMETHOD GetFileXPref(const char *pref, nsILocalFile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetFileXPref(const char *pref, nsILocalFile *value); \
  NS_IMETHOD RegisterCallback(const char *domain, PrefChangedFunc callback, void * closure); \
  NS_IMETHOD UnregisterCallback(const char *domain, PrefChangedFunc callback, void * closure); \
  NS_IMETHOD EnumerateChildren(const char *parent, PrefEnumerationFunc callback, void * data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREF(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReadUserPrefs(nsIFile *aFile) { return _to ReadUserPrefs(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD ResetPrefs(void) { return _to ResetPrefs(); } \
  NS_SCRIPTABLE NS_IMETHOD ResetUserPrefs(void) { return _to ResetUserPrefs(); } \
  NS_SCRIPTABLE NS_IMETHOD SavePrefFile(nsIFile *aFile) { return _to SavePrefFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM) { return _to GetBranch(aPrefRoot, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM) { return _to GetDefaultBranch(aPrefRoot, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(char * *aRoot) { return _to GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefType(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM) { return _to GetPrefType(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoolPref(const char *aPrefName, PRBool *_retval NS_OUTPARAM) { return _to GetBoolPref(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetBoolPref(const char *aPrefName, PRInt32 aValue) { return _to SetBoolPref(aPrefName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharPref(const char *aPrefName, char **_retval NS_OUTPARAM) { return _to GetCharPref(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharPref(const char *aPrefName, const char *aValue) { return _to SetCharPref(aPrefName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntPref(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM) { return _to GetIntPref(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetIntPref(const char *aPrefName, PRInt32 aValue) { return _to SetIntPref(aPrefName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetComplexValue(const char *aPrefName, const nsIID & aType, void * *aValue NS_OUTPARAM) { return _to GetComplexValue(aPrefName, aType, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetComplexValue(const char *aPrefName, const nsIID & aType, nsISupports *aValue) { return _to SetComplexValue(aPrefName, aType, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD ClearUserPref(const char *aPrefName) { return _to ClearUserPref(aPrefName); } \
  NS_SCRIPTABLE NS_IMETHOD PrefIsLocked(const char *aPrefName, PRBool *_retval NS_OUTPARAM) { return _to PrefIsLocked(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LockPref(const char *aPrefName) { return _to LockPref(aPrefName); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockPref(const char *aPrefName) { return _to UnlockPref(aPrefName); } \
  NS_SCRIPTABLE NS_IMETHOD ResetBranch(const char *aStartingAt) { return _to ResetBranch(aStartingAt); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteBranch(const char *aStartingAt) { return _to DeleteBranch(aStartingAt); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildList(const char *aStartingAt, PRUint32 *aCount NS_OUTPARAM, char ***aChildArray NS_OUTPARAM) { return _to GetChildList(aStartingAt, aCount, aChildArray); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const char *aDomain, nsIObserver *aObserver, PRBool aHoldWeak) { return _to AddObserver(aDomain, aObserver, aHoldWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const char *aDomain, nsIObserver *aObserver) { return _to RemoveObserver(aDomain, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD CopyCharPref(const char *pref, char **_retval NS_OUTPARAM) { return _to CopyCharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CopyDefaultCharPref(const char *pref, char **_retval NS_OUTPARAM) { return _to CopyDefaultCharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM) { return _to GetDefaultBoolPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM) { return _to GetDefaultIntPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultBoolPref(const char *pref, PRBool value) { return _to SetDefaultBoolPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultCharPref(const char *pref, const char *value) { return _to SetDefaultCharPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultIntPref(const char *pref, PRInt32 value) { return _to SetDefaultIntPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD CopyUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) { return _to CopyUnicharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CopyDefaultUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) { return _to CopyDefaultUnicharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnicharPref(const char *pref, const PRUnichar *value) { return _to SetUnicharPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultUnicharPref(const char *pref, const PRUnichar *value) { return _to SetDefaultUnicharPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) { return _to GetLocalizedUnicharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) { return _to GetDefaultLocalizedUnicharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilePref(const char *pref, nsIFileSpec **_retval NS_OUTPARAM) { return _to GetFilePref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFilePref(const char *pref, nsIFileSpec *value, PRBool setDefault) { return _to SetFilePref(pref, value, setDefault); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileXPref(const char *pref, nsILocalFile **_retval NS_OUTPARAM) { return _to GetFileXPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFileXPref(const char *pref, nsILocalFile *value) { return _to SetFileXPref(pref, value); } \
  NS_IMETHOD RegisterCallback(const char *domain, PrefChangedFunc callback, void * closure) { return _to RegisterCallback(domain, callback, closure); } \
  NS_IMETHOD UnregisterCallback(const char *domain, PrefChangedFunc callback, void * closure) { return _to UnregisterCallback(domain, callback, closure); } \
  NS_IMETHOD EnumerateChildren(const char *parent, PrefEnumerationFunc callback, void * data) { return _to EnumerateChildren(parent, callback, data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREF(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReadUserPrefs(nsIFile *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadUserPrefs(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD ResetPrefs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetPrefs(); } \
  NS_SCRIPTABLE NS_IMETHOD ResetUserPrefs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetUserPrefs(); } \
  NS_SCRIPTABLE NS_IMETHOD SavePrefFile(nsIFile *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SavePrefFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBranch(aPrefRoot, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultBranch(aPrefRoot, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(char * *aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefType(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefType(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoolPref(const char *aPrefName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoolPref(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetBoolPref(const char *aPrefName, PRInt32 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBoolPref(aPrefName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharPref(const char *aPrefName, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharPref(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharPref(const char *aPrefName, const char *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharPref(aPrefName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntPref(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntPref(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetIntPref(const char *aPrefName, PRInt32 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIntPref(aPrefName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetComplexValue(const char *aPrefName, const nsIID & aType, void * *aValue NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComplexValue(aPrefName, aType, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetComplexValue(const char *aPrefName, const nsIID & aType, nsISupports *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetComplexValue(aPrefName, aType, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD ClearUserPref(const char *aPrefName) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearUserPref(aPrefName); } \
  NS_SCRIPTABLE NS_IMETHOD PrefIsLocked(const char *aPrefName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrefIsLocked(aPrefName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LockPref(const char *aPrefName) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockPref(aPrefName); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockPref(const char *aPrefName) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockPref(aPrefName); } \
  NS_SCRIPTABLE NS_IMETHOD ResetBranch(const char *aStartingAt) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetBranch(aStartingAt); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteBranch(const char *aStartingAt) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteBranch(aStartingAt); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildList(const char *aStartingAt, PRUint32 *aCount NS_OUTPARAM, char ***aChildArray NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildList(aStartingAt, aCount, aChildArray); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const char *aDomain, nsIObserver *aObserver, PRBool aHoldWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aDomain, aObserver, aHoldWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const char *aDomain, nsIObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aDomain, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD CopyCharPref(const char *pref, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyCharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CopyDefaultCharPref(const char *pref, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyDefaultCharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultBoolPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultIntPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultBoolPref(const char *pref, PRBool value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultBoolPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultCharPref(const char *pref, const char *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultCharPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultIntPref(const char *pref, PRInt32 value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultIntPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD CopyUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyUnicharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CopyDefaultUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyDefaultUnicharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnicharPref(const char *pref, const PRUnichar *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnicharPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultUnicharPref(const char *pref, const PRUnichar *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultUnicharPref(pref, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalizedUnicharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultLocalizedUnicharPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilePref(const char *pref, nsIFileSpec **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilePref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFilePref(const char *pref, nsIFileSpec *value, PRBool setDefault) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilePref(pref, value, setDefault); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileXPref(const char *pref, nsILocalFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileXPref(pref, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFileXPref(const char *pref, nsILocalFile *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFileXPref(pref, value); } \
  NS_IMETHOD RegisterCallback(const char *domain, PrefChangedFunc callback, void * closure) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterCallback(domain, callback, closure); } \
  NS_IMETHOD UnregisterCallback(const char *domain, PrefChangedFunc callback, void * closure) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterCallback(domain, callback, closure); } \
  NS_IMETHOD EnumerateChildren(const char *parent, PrefEnumerationFunc callback, void * data) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateChildren(parent, callback, data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPref : public nsIPref
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREF

  nsPref();

private:
  ~nsPref();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPref, nsIPref)

nsPref::nsPref()
{
  /* member initializers and constructor code */
}

nsPref::~nsPref()
{
  /* destructor code */
}

/* void readUserPrefs (in nsIFile aFile); */
NS_IMETHODIMP nsPref::ReadUserPrefs(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ResetPrefs (); */
NS_IMETHODIMP nsPref::ResetPrefs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ResetUserPrefs (); */
NS_IMETHODIMP nsPref::ResetUserPrefs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void savePrefFile (in nsIFile aFile); */
NS_IMETHODIMP nsPref::SavePrefFile(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrefBranch getBranch (in string aPrefRoot); */
NS_IMETHODIMP nsPref::GetBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrefBranch getDefaultBranch (in string aPrefRoot); */
NS_IMETHODIMP nsPref::GetDefaultBranch(const char *aPrefRoot, nsIPrefBranch **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string root; */
NS_IMETHODIMP nsPref::GetRoot(char * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetPrefType (in string aPrefName); */
NS_IMETHODIMP nsPref::GetPrefType(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean GetBoolPref (in string aPrefName); */
NS_IMETHODIMP nsPref::GetBoolPref(const char *aPrefName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetBoolPref (in string aPrefName, in long aValue); */
NS_IMETHODIMP nsPref::SetBoolPref(const char *aPrefName, PRInt32 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string GetCharPref (in string aPrefName); */
NS_IMETHODIMP nsPref::GetCharPref(const char *aPrefName, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetCharPref (in string aPrefName, in string aValue); */
NS_IMETHODIMP nsPref::SetCharPref(const char *aPrefName, const char *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetIntPref (in string aPrefName); */
NS_IMETHODIMP nsPref::GetIntPref(const char *aPrefName, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetIntPref (in string aPrefName, in long aValue); */
NS_IMETHODIMP nsPref::SetIntPref(const char *aPrefName, PRInt32 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getComplexValue (in string aPrefName, in nsIIDRef aType, [iid_is (aType), retval] out nsQIResult aValue); */
NS_IMETHODIMP nsPref::GetComplexValue(const char *aPrefName, const nsIID & aType, void * *aValue NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setComplexValue (in string aPrefName, in nsIIDRef aType, in nsISupports aValue); */
NS_IMETHODIMP nsPref::SetComplexValue(const char *aPrefName, const nsIID & aType, nsISupports *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ClearUserPref (in string aPrefName); */
NS_IMETHODIMP nsPref::ClearUserPref(const char *aPrefName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean PrefIsLocked (in string aPrefName); */
NS_IMETHODIMP nsPref::PrefIsLocked(const char *aPrefName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lockPref (in string aPrefName); */
NS_IMETHODIMP nsPref::LockPref(const char *aPrefName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlockPref (in string aPrefName); */
NS_IMETHODIMP nsPref::UnlockPref(const char *aPrefName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetBranch (in string aStartingAt); */
NS_IMETHODIMP nsPref::ResetBranch(const char *aStartingAt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DeleteBranch (in string aStartingAt); */
NS_IMETHODIMP nsPref::DeleteBranch(const char *aStartingAt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getChildList (in string aStartingAt, out unsigned long aCount, [array, size_is (aCount), retval] out string aChildArray); */
NS_IMETHODIMP nsPref::GetChildList(const char *aStartingAt, PRUint32 *aCount NS_OUTPARAM, char ***aChildArray NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in string aDomain, in nsIObserver aObserver, in boolean aHoldWeak); */
NS_IMETHODIMP nsPref::AddObserver(const char *aDomain, nsIObserver *aObserver, PRBool aHoldWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in string aDomain, in nsIObserver aObserver); */
NS_IMETHODIMP nsPref::RemoveObserver(const char *aDomain, nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string CopyCharPref (in string pref); */
NS_IMETHODIMP nsPref::CopyCharPref(const char *pref, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string CopyDefaultCharPref (in string pref); */
NS_IMETHODIMP nsPref::CopyDefaultCharPref(const char *pref, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean GetDefaultBoolPref (in string pref); */
NS_IMETHODIMP nsPref::GetDefaultBoolPref(const char *pref, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetDefaultIntPref (in string pref); */
NS_IMETHODIMP nsPref::GetDefaultIntPref(const char *pref, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetDefaultBoolPref (in string pref, in boolean value); */
NS_IMETHODIMP nsPref::SetDefaultBoolPref(const char *pref, PRBool value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetDefaultCharPref (in string pref, in string value); */
NS_IMETHODIMP nsPref::SetDefaultCharPref(const char *pref, const char *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetDefaultIntPref (in string pref, in long value); */
NS_IMETHODIMP nsPref::SetDefaultIntPref(const char *pref, PRInt32 value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring CopyUnicharPref (in string pref); */
NS_IMETHODIMP nsPref::CopyUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring CopyDefaultUnicharPref (in string pref); */
NS_IMETHODIMP nsPref::CopyDefaultUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetUnicharPref (in string pref, in wstring value); */
NS_IMETHODIMP nsPref::SetUnicharPref(const char *pref, const PRUnichar *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetDefaultUnicharPref (in string pref, in wstring value); */
NS_IMETHODIMP nsPref::SetDefaultUnicharPref(const char *pref, const PRUnichar *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring getLocalizedUnicharPref (in string pref); */
NS_IMETHODIMP nsPref::GetLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring getDefaultLocalizedUnicharPref (in string pref); */
NS_IMETHODIMP nsPref::GetDefaultLocalizedUnicharPref(const char *pref, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFileSpec GetFilePref (in string pref); */
NS_IMETHODIMP nsPref::GetFilePref(const char *pref, nsIFileSpec **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetFilePref (in string pref, in nsIFileSpec value, in boolean setDefault); */
NS_IMETHODIMP nsPref::SetFilePref(const char *pref, nsIFileSpec *value, PRBool setDefault)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsILocalFile getFileXPref (in string pref); */
NS_IMETHODIMP nsPref::GetFileXPref(const char *pref, nsILocalFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFileXPref (in string pref, in nsILocalFile value); */
NS_IMETHODIMP nsPref::SetFileXPref(const char *pref, nsILocalFile *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void RegisterCallback (in string domain, in PrefChangedFunc callback, in voidPtr closure); */
NS_IMETHODIMP nsPref::RegisterCallback(const char *domain, PrefChangedFunc callback, void * closure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void UnregisterCallback (in string domain, in PrefChangedFunc callback, in voidPtr closure); */
NS_IMETHODIMP nsPref::UnregisterCallback(const char *domain, PrefChangedFunc callback, void * closure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void EnumerateChildren (in string parent, in PrefEnumerationFunc callback, in voidPtr data); */
NS_IMETHODIMP nsPref::EnumerateChildren(const char *parent, PrefEnumerationFunc callback, void * data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPref_h__ */
