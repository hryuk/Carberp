/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/oji/public/nsIJVMManager.idl
 */

#ifndef __gen_nsIJVMManager_h__
#define __gen_nsIJVMManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifndef JNI_H
#include "jni.h"
#endif
/*
 Java VM Plugin Manager
 This interface defines additional entry points that are available
 to JVM plugins for browsers that support JVM plugins.
*/
/*
#define NS_IJVMMANAGER_IID                           \
{ / * a1e5ed50-aa4a-11d1-85b2-00805f0e4dfe * /       \
    0xa1e5ed50,                                      \
    0xaa4a,                                          \
    0x11d1,                                          \
    {0x85, 0xb2, 0x00, 0x80, 0x5f, 0x0e, 0x4d, 0xfe} \
}
*/
#define NS_JVMMANAGER_CID                            \
{ /* 38e7ef10-58df-11d2-8164-006008119d7a */         \
    0x38e7ef10,                                      \
    0x58df,                                          \
    0x11d2,                                          \
    {0x81, 0x64, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a} \
}
class nsIJVMPlugin; /* forward declaration */

class nsISecureEnv; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIJVMManager */
#define NS_IJVMMANAGER_IID_STR "a1e5ed50-aa4a-11d1-85b2-00805f0e4dfe"

#define NS_IJVMMANAGER_IID \
  {0xa1e5ed50, 0xaa4a, 0x11d1, \
    { 0x85, 0xb2, 0x00, 0x80, 0x5f, 0x0e, 0x4d, 0xfe }}

class NS_SCRIPTABLE nsIJVMManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJVMMANAGER_IID)

	NS_DEFINE_STATIC_CID_ACCESSOR(NS_JVMMANAGER_CID)
  /**
     * Creates a proxy JNI with an optional secure environment (which can be NULL).
     * There is a one-to-one correspondence between proxy JNIs and threads, so
     * calling this method multiple times from the same thread will return
     * the same proxy JNI.
     */
  /* [noscript] void createProxyJNI (in nsISecureEnv secureEnv, out JNIEnv outProxyEnv); */
  NS_IMETHOD CreateProxyJNI(nsISecureEnv *secureEnv, JNIEnv * *outProxyEnv NS_OUTPARAM) = 0;

  /**
	 * Returns the proxy JNI associated with the current thread, or NULL if no
	 * such association exists.
	 */
  /* [noscript] void getProxyJNI (out JNIEnv outProxyEnv); */
  NS_IMETHOD GetProxyJNI(JNIEnv * *outProxyEnv NS_OUTPARAM) = 0;

  /**
	 * Called from Java Console menu item.
	 */
  /* void showJavaConsole (); */
  NS_SCRIPTABLE NS_IMETHOD ShowJavaConsole(void) = 0;

  /**
	 * isAllPermissionGranted [Deprecated Sep-10-2000]
	 */
  /* boolean isAllPermissionGranted (in string lastFingerprint, in string lastCommonName, in string rootFingerprint, in string rootCommonName); */
  NS_SCRIPTABLE NS_IMETHOD IsAllPermissionGranted(const char *lastFingerprint, const char *lastCommonName, const char *rootFingerprint, const char *rootCommonName, PRBool *_retval NS_OUTPARAM) = 0;

  /**
	 * isAppletTrusted
	 */
  /* nsIPrincipal isAppletTrusted (in string aRSABuf, in PRUint32 aRSABufLen, in string aPlaintext, in PRUint32 aPlaintextLen, out boolean isTrusted); */
  NS_SCRIPTABLE NS_IMETHOD IsAppletTrusted(const char *aRSABuf, PRUint32 aRSABufLen, const char *aPlaintext, PRUint32 aPlaintextLen, PRBool *isTrusted NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM) = 0;

  /**
     * The JavaEnabled variable to see if Java is Enabled or not
     */
  /* readonly attribute boolean JavaEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetJavaEnabled(PRBool *aJavaEnabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJVMManager, NS_IJVMMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJVMMANAGER \
  NS_IMETHOD CreateProxyJNI(nsISecureEnv *secureEnv, JNIEnv * *outProxyEnv NS_OUTPARAM); \
  NS_IMETHOD GetProxyJNI(JNIEnv * *outProxyEnv NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ShowJavaConsole(void); \
  NS_SCRIPTABLE NS_IMETHOD IsAllPermissionGranted(const char *lastFingerprint, const char *lastCommonName, const char *rootFingerprint, const char *rootCommonName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsAppletTrusted(const char *aRSABuf, PRUint32 aRSABufLen, const char *aPlaintext, PRUint32 aPlaintextLen, PRBool *isTrusted NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetJavaEnabled(PRBool *aJavaEnabled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJVMMANAGER(_to) \
  NS_IMETHOD CreateProxyJNI(nsISecureEnv *secureEnv, JNIEnv * *outProxyEnv NS_OUTPARAM) { return _to CreateProxyJNI(secureEnv, outProxyEnv); } \
  NS_IMETHOD GetProxyJNI(JNIEnv * *outProxyEnv NS_OUTPARAM) { return _to GetProxyJNI(outProxyEnv); } \
  NS_SCRIPTABLE NS_IMETHOD ShowJavaConsole(void) { return _to ShowJavaConsole(); } \
  NS_SCRIPTABLE NS_IMETHOD IsAllPermissionGranted(const char *lastFingerprint, const char *lastCommonName, const char *rootFingerprint, const char *rootCommonName, PRBool *_retval NS_OUTPARAM) { return _to IsAllPermissionGranted(lastFingerprint, lastCommonName, rootFingerprint, rootCommonName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsAppletTrusted(const char *aRSABuf, PRUint32 aRSABufLen, const char *aPlaintext, PRUint32 aPlaintextLen, PRBool *isTrusted NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM) { return _to IsAppletTrusted(aRSABuf, aRSABufLen, aPlaintext, aPlaintextLen, isTrusted, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetJavaEnabled(PRBool *aJavaEnabled) { return _to GetJavaEnabled(aJavaEnabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJVMMANAGER(_to) \
  NS_IMETHOD CreateProxyJNI(nsISecureEnv *secureEnv, JNIEnv * *outProxyEnv NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateProxyJNI(secureEnv, outProxyEnv); } \
  NS_IMETHOD GetProxyJNI(JNIEnv * *outProxyEnv NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProxyJNI(outProxyEnv); } \
  NS_SCRIPTABLE NS_IMETHOD ShowJavaConsole(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowJavaConsole(); } \
  NS_SCRIPTABLE NS_IMETHOD IsAllPermissionGranted(const char *lastFingerprint, const char *lastCommonName, const char *rootFingerprint, const char *rootCommonName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAllPermissionGranted(lastFingerprint, lastCommonName, rootFingerprint, rootCommonName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsAppletTrusted(const char *aRSABuf, PRUint32 aRSABufLen, const char *aPlaintext, PRUint32 aPlaintextLen, PRBool *isTrusted NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAppletTrusted(aRSABuf, aRSABufLen, aPlaintext, aPlaintextLen, isTrusted, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetJavaEnabled(PRBool *aJavaEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJavaEnabled(aJavaEnabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJVMManager : public nsIJVMManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJVMMANAGER

  nsJVMManager();

private:
  ~nsJVMManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJVMManager, nsIJVMManager)

nsJVMManager::nsJVMManager()
{
  /* member initializers and constructor code */
}

nsJVMManager::~nsJVMManager()
{
  /* destructor code */
}

/* [noscript] void createProxyJNI (in nsISecureEnv secureEnv, out JNIEnv outProxyEnv); */
NS_IMETHODIMP nsJVMManager::CreateProxyJNI(nsISecureEnv *secureEnv, JNIEnv * *outProxyEnv NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getProxyJNI (out JNIEnv outProxyEnv); */
NS_IMETHODIMP nsJVMManager::GetProxyJNI(JNIEnv * *outProxyEnv NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showJavaConsole (); */
NS_IMETHODIMP nsJVMManager::ShowJavaConsole()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isAllPermissionGranted (in string lastFingerprint, in string lastCommonName, in string rootFingerprint, in string rootCommonName); */
NS_IMETHODIMP nsJVMManager::IsAllPermissionGranted(const char *lastFingerprint, const char *lastCommonName, const char *rootFingerprint, const char *rootCommonName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal isAppletTrusted (in string aRSABuf, in PRUint32 aRSABufLen, in string aPlaintext, in PRUint32 aPlaintextLen, out boolean isTrusted); */
NS_IMETHODIMP nsJVMManager::IsAppletTrusted(const char *aRSABuf, PRUint32 aRSABufLen, const char *aPlaintext, PRUint32 aPlaintextLen, PRBool *isTrusted NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean JavaEnabled; */
NS_IMETHODIMP nsJVMManager::GetJavaEnabled(PRBool *aJavaEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJVMManager_h__ */
