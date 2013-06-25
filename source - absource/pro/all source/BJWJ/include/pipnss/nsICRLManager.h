/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsICRLManager.idl
 */

#ifndef __gen_nsICRLManager_h__
#define __gen_nsICRLManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIArray; /* forward declaration */

class nsICRLInfo; /* forward declaration */

#define NS_CRLMANAGER_CID { /* 5b256c10-22d8-4109-af92-1253035e9fcb */ \
    0x5b256c10, \
    0x22d8, \
    0x4109, \
    {0xaf, 0x92, 0x12, 0x53, 0x03, 0x5e, 0x9f, 0xcb} \
  }
#define NS_CRLMANAGER_CONTRACTID "@mozilla.org/security/crlmanager;1"

/* starting interface:    nsICRLManager */
#define NS_ICRLMANAGER_IID_STR "486755db-627a-4678-a21b-f6a63bb9c56a"

#define NS_ICRLMANAGER_IID \
  {0x486755db, 0x627a, 0x4678, \
    { 0xa2, 0x1b, 0xf6, 0xa6, 0x3b, 0xb9, 0xc5, 0x6a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICRLManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRLMANAGER_IID)

  /* void importCrl ([array, size_is (length)] in octet data, in unsigned long length, in nsIURI uri, in unsigned long type, in boolean doSilentDownload, in wstring crlKey); */
  NS_SCRIPTABLE NS_IMETHOD ImportCrl(PRUint8 *data, PRUint32 length, nsIURI *uri, PRUint32 type, PRBool doSilentDownload, const PRUnichar *crlKey) = 0;

  /* boolean updateCRLFromURL (in wstring url, in wstring key); */
  NS_SCRIPTABLE NS_IMETHOD UpdateCRLFromURL(const PRUnichar *url, const PRUnichar *key, PRBool *_retval NS_OUTPARAM) = 0;

  /* nsIArray getCrls (); */
  NS_SCRIPTABLE NS_IMETHOD GetCrls(nsIArray **_retval NS_OUTPARAM) = 0;

  /* void deleteCrl (in unsigned long crlIndex); */
  NS_SCRIPTABLE NS_IMETHOD DeleteCrl(PRUint32 crlIndex) = 0;

  /* void rescheduleCRLAutoUpdate (); */
  NS_SCRIPTABLE NS_IMETHOD RescheduleCRLAutoUpdate(void) = 0;

  enum { TYPE_AUTOUPDATE_TIME_BASED = 1U };

  enum { TYPE_AUTOUPDATE_FREQ_BASED = 2U };

  /* wstring computeNextAutoUpdateTime (in nsICRLInfo info, in unsigned long autoUpdateType, in double noOfDays); */
  NS_SCRIPTABLE NS_IMETHOD ComputeNextAutoUpdateTime(nsICRLInfo *info, PRUint32 autoUpdateType, double noOfDays, PRUnichar **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICRLManager, NS_ICRLMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRLMANAGER \
  NS_SCRIPTABLE NS_IMETHOD ImportCrl(PRUint8 *data, PRUint32 length, nsIURI *uri, PRUint32 type, PRBool doSilentDownload, const PRUnichar *crlKey); \
  NS_SCRIPTABLE NS_IMETHOD UpdateCRLFromURL(const PRUnichar *url, const PRUnichar *key, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCrls(nsIArray **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DeleteCrl(PRUint32 crlIndex); \
  NS_SCRIPTABLE NS_IMETHOD RescheduleCRLAutoUpdate(void); \
  NS_SCRIPTABLE NS_IMETHOD ComputeNextAutoUpdateTime(nsICRLInfo *info, PRUint32 autoUpdateType, double noOfDays, PRUnichar **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRLMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ImportCrl(PRUint8 *data, PRUint32 length, nsIURI *uri, PRUint32 type, PRBool doSilentDownload, const PRUnichar *crlKey) { return _to ImportCrl(data, length, uri, type, doSilentDownload, crlKey); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateCRLFromURL(const PRUnichar *url, const PRUnichar *key, PRBool *_retval NS_OUTPARAM) { return _to UpdateCRLFromURL(url, key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCrls(nsIArray **_retval NS_OUTPARAM) { return _to GetCrls(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteCrl(PRUint32 crlIndex) { return _to DeleteCrl(crlIndex); } \
  NS_SCRIPTABLE NS_IMETHOD RescheduleCRLAutoUpdate(void) { return _to RescheduleCRLAutoUpdate(); } \
  NS_SCRIPTABLE NS_IMETHOD ComputeNextAutoUpdateTime(nsICRLInfo *info, PRUint32 autoUpdateType, double noOfDays, PRUnichar **_retval NS_OUTPARAM) { return _to ComputeNextAutoUpdateTime(info, autoUpdateType, noOfDays, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRLMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ImportCrl(PRUint8 *data, PRUint32 length, nsIURI *uri, PRUint32 type, PRBool doSilentDownload, const PRUnichar *crlKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportCrl(data, length, uri, type, doSilentDownload, crlKey); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateCRLFromURL(const PRUnichar *url, const PRUnichar *key, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCRLFromURL(url, key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCrls(nsIArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrls(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteCrl(PRUint32 crlIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteCrl(crlIndex); } \
  NS_SCRIPTABLE NS_IMETHOD RescheduleCRLAutoUpdate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RescheduleCRLAutoUpdate(); } \
  NS_SCRIPTABLE NS_IMETHOD ComputeNextAutoUpdateTime(nsICRLInfo *info, PRUint32 autoUpdateType, double noOfDays, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ComputeNextAutoUpdateTime(info, autoUpdateType, noOfDays, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCRLManager : public nsICRLManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRLMANAGER

  nsCRLManager();

private:
  ~nsCRLManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCRLManager, nsICRLManager)

nsCRLManager::nsCRLManager()
{
  /* member initializers and constructor code */
}

nsCRLManager::~nsCRLManager()
{
  /* destructor code */
}

/* void importCrl ([array, size_is (length)] in octet data, in unsigned long length, in nsIURI uri, in unsigned long type, in boolean doSilentDownload, in wstring crlKey); */
NS_IMETHODIMP nsCRLManager::ImportCrl(PRUint8 *data, PRUint32 length, nsIURI *uri, PRUint32 type, PRBool doSilentDownload, const PRUnichar *crlKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean updateCRLFromURL (in wstring url, in wstring key); */
NS_IMETHODIMP nsCRLManager::UpdateCRLFromURL(const PRUnichar *url, const PRUnichar *key, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getCrls (); */
NS_IMETHODIMP nsCRLManager::GetCrls(nsIArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteCrl (in unsigned long crlIndex); */
NS_IMETHODIMP nsCRLManager::DeleteCrl(PRUint32 crlIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rescheduleCRLAutoUpdate (); */
NS_IMETHODIMP nsCRLManager::RescheduleCRLAutoUpdate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring computeNextAutoUpdateTime (in nsICRLInfo info, in unsigned long autoUpdateType, in double noOfDays); */
NS_IMETHODIMP nsCRLManager::ComputeNextAutoUpdateTime(nsICRLInfo *info, PRUint32 autoUpdateType, double noOfDays, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICRLManager_h__ */
