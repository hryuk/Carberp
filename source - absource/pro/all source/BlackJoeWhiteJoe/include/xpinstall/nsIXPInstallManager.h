/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpinstall/public/nsIXPInstallManager.idl
 */

#ifndef __gen_nsIXPInstallManager_h__
#define __gen_nsIXPInstallManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXPIProgressDialog; /* forward declaration */

class nsIXPIInstallInfo; /* forward declaration */


/* starting interface:    nsIXPInstallManager */
#define NS_IXPINSTALLMANAGER_IID_STR "83fdd52f-2d34-4e22-981d-cf3c4ae76faa"

#define NS_IXPINSTALLMANAGER_IID \
  {0x83fdd52f, 0x2d34, 0x4e22, \
    { 0x98, 0x1d, 0xcf, 0x3c, 0x4a, 0xe7, 0x6f, 0xaa }}

/**
 * Interface to XPInstallManager - manages download and install operations.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPInstallManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPINSTALLMANAGER_IID)

  /** 
     * Initiates a download and install operation of the supplied URLs
     * and sends notifications to the supplied listener.
     * @param aURLs     array of XPI urls to download and install
     * @param aURLCount number of XPI urls in aURLs
     * @param aListener a listener to receive status notifications
     */
  /* void initManagerFromChrome ([array, size_is (aURLCount)] in wstring aURLs, in unsigned long aURLCount, in nsIXPIProgressDialog aListener); */
  NS_SCRIPTABLE NS_IMETHOD InitManagerFromChrome(const PRUnichar **aURLs, PRUint32 aURLCount, nsIXPIProgressDialog *aListener) = 0;

  /**
     * Initiates a set of downloads and checks the supplied hashes after
     * download. Just like initManagerFromChrome() in all other respects
     * @param aURLs     array of XPI urls to download and install
     * @param aHashes   array of hash strings to validate. The entire array
     *                  or individual hashes can be null to indicate no
     *                  checking. If supplied looks like "type:hash", like
     *                  "md5:3232bc5624041c507db0965324188024".
     *                  Supports the types in nsICryptoHash
     * @param aURLCount number of XPI urls in aURLs and aHashes
     * @param aListener a listener to receive status notifications
     */
  /* void initManagerWithHashes ([array, size_is (aURLCount)] in wstring aURLs, [array, size_is (aURLCount)] in string aHashes, in unsigned long aURLCount, in nsIXPIProgressDialog aListener); */
  NS_SCRIPTABLE NS_IMETHOD InitManagerWithHashes(const PRUnichar **aURLs, const char **aHashes, PRUint32 aURLCount, nsIXPIProgressDialog *aListener) = 0;

  /**
     * Initiates a set of downloads based on an install info object. Will
     * display confirmation dialog as if the install info had been supplied
     * by content.
     * @param aInstallInfo The install info object providing install triggers
     *                     and script context for the install.
     */
  /* void initManagerWithInstallInfo (in nsIXPIInstallInfo aInstallInfo); */
  NS_SCRIPTABLE NS_IMETHOD InitManagerWithInstallInfo(nsIXPIInstallInfo *aInstallInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPInstallManager, NS_IXPINSTALLMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPINSTALLMANAGER \
  NS_SCRIPTABLE NS_IMETHOD InitManagerFromChrome(const PRUnichar **aURLs, PRUint32 aURLCount, nsIXPIProgressDialog *aListener); \
  NS_SCRIPTABLE NS_IMETHOD InitManagerWithHashes(const PRUnichar **aURLs, const char **aHashes, PRUint32 aURLCount, nsIXPIProgressDialog *aListener); \
  NS_SCRIPTABLE NS_IMETHOD InitManagerWithInstallInfo(nsIXPIInstallInfo *aInstallInfo); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPINSTALLMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD InitManagerFromChrome(const PRUnichar **aURLs, PRUint32 aURLCount, nsIXPIProgressDialog *aListener) { return _to InitManagerFromChrome(aURLs, aURLCount, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD InitManagerWithHashes(const PRUnichar **aURLs, const char **aHashes, PRUint32 aURLCount, nsIXPIProgressDialog *aListener) { return _to InitManagerWithHashes(aURLs, aHashes, aURLCount, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD InitManagerWithInstallInfo(nsIXPIInstallInfo *aInstallInfo) { return _to InitManagerWithInstallInfo(aInstallInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPINSTALLMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD InitManagerFromChrome(const PRUnichar **aURLs, PRUint32 aURLCount, nsIXPIProgressDialog *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitManagerFromChrome(aURLs, aURLCount, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD InitManagerWithHashes(const PRUnichar **aURLs, const char **aHashes, PRUint32 aURLCount, nsIXPIProgressDialog *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitManagerWithHashes(aURLs, aHashes, aURLCount, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD InitManagerWithInstallInfo(nsIXPIInstallInfo *aInstallInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitManagerWithInstallInfo(aInstallInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPInstallManager : public nsIXPInstallManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPINSTALLMANAGER

  nsXPInstallManager();

private:
  ~nsXPInstallManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPInstallManager, nsIXPInstallManager)

nsXPInstallManager::nsXPInstallManager()
{
  /* member initializers and constructor code */
}

nsXPInstallManager::~nsXPInstallManager()
{
  /* destructor code */
}

/* void initManagerFromChrome ([array, size_is (aURLCount)] in wstring aURLs, in unsigned long aURLCount, in nsIXPIProgressDialog aListener); */
NS_IMETHODIMP nsXPInstallManager::InitManagerFromChrome(const PRUnichar **aURLs, PRUint32 aURLCount, nsIXPIProgressDialog *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initManagerWithHashes ([array, size_is (aURLCount)] in wstring aURLs, [array, size_is (aURLCount)] in string aHashes, in unsigned long aURLCount, in nsIXPIProgressDialog aListener); */
NS_IMETHODIMP nsXPInstallManager::InitManagerWithHashes(const PRUnichar **aURLs, const char **aHashes, PRUint32 aURLCount, nsIXPIProgressDialog *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initManagerWithInstallInfo (in nsIXPIInstallInfo aInstallInfo); */
NS_IMETHODIMP nsXPInstallManager::InitManagerWithInstallInfo(nsIXPIInstallInfo *aInstallInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPInstallManager_h__ */
