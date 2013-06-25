/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsICipherInfo.idl
 */

#ifndef __gen_nsICipherInfo_h__
#define __gen_nsICipherInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICipherInfo */
#define NS_ICIPHERINFO_IID_STR "028e2b2a-1f0b-43a4-a1a7-365d2d7f35d0"

#define NS_ICIPHERINFO_IID \
  {0x028e2b2a, 0x1f0b, 0x43a4, \
    { 0xa1, 0xa7, 0x36, 0x5d, 0x2d, 0x7f, 0x35, 0xd0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICipherInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICIPHERINFO_IID)

  /* readonly attribute ACString longName; */
  NS_SCRIPTABLE NS_IMETHOD GetLongName(nsACString & aLongName) = 0;

  /* readonly attribute PRBool isSSL2; */
  NS_SCRIPTABLE NS_IMETHOD GetIsSSL2(PRBool *aIsSSL2) = 0;

  /* readonly attribute PRBool isFIPS; */
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPS(PRBool *aIsFIPS) = 0;

  /* readonly attribute PRBool isExportable; */
  NS_SCRIPTABLE NS_IMETHOD GetIsExportable(PRBool *aIsExportable) = 0;

  /* readonly attribute PRBool nonStandard; */
  NS_SCRIPTABLE NS_IMETHOD GetNonStandard(PRBool *aNonStandard) = 0;

  /* readonly attribute ACString symCipherName; */
  NS_SCRIPTABLE NS_IMETHOD GetSymCipherName(nsACString & aSymCipherName) = 0;

  /* readonly attribute ACString authAlgorithmName; */
  NS_SCRIPTABLE NS_IMETHOD GetAuthAlgorithmName(nsACString & aAuthAlgorithmName) = 0;

  /* readonly attribute ACString keaTypeName; */
  NS_SCRIPTABLE NS_IMETHOD GetKeaTypeName(nsACString & aKeaTypeName) = 0;

  /* readonly attribute ACString macAlgorithmName; */
  NS_SCRIPTABLE NS_IMETHOD GetMacAlgorithmName(nsACString & aMacAlgorithmName) = 0;

  /* readonly attribute PRInt32 effectiveKeyBits; */
  NS_SCRIPTABLE NS_IMETHOD GetEffectiveKeyBits(PRInt32 *aEffectiveKeyBits) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICipherInfo, NS_ICIPHERINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICIPHERINFO \
  NS_SCRIPTABLE NS_IMETHOD GetLongName(nsACString & aLongName); \
  NS_SCRIPTABLE NS_IMETHOD GetIsSSL2(PRBool *aIsSSL2); \
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPS(PRBool *aIsFIPS); \
  NS_SCRIPTABLE NS_IMETHOD GetIsExportable(PRBool *aIsExportable); \
  NS_SCRIPTABLE NS_IMETHOD GetNonStandard(PRBool *aNonStandard); \
  NS_SCRIPTABLE NS_IMETHOD GetSymCipherName(nsACString & aSymCipherName); \
  NS_SCRIPTABLE NS_IMETHOD GetAuthAlgorithmName(nsACString & aAuthAlgorithmName); \
  NS_SCRIPTABLE NS_IMETHOD GetKeaTypeName(nsACString & aKeaTypeName); \
  NS_SCRIPTABLE NS_IMETHOD GetMacAlgorithmName(nsACString & aMacAlgorithmName); \
  NS_SCRIPTABLE NS_IMETHOD GetEffectiveKeyBits(PRInt32 *aEffectiveKeyBits); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICIPHERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLongName(nsACString & aLongName) { return _to GetLongName(aLongName); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSSL2(PRBool *aIsSSL2) { return _to GetIsSSL2(aIsSSL2); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPS(PRBool *aIsFIPS) { return _to GetIsFIPS(aIsFIPS); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsExportable(PRBool *aIsExportable) { return _to GetIsExportable(aIsExportable); } \
  NS_SCRIPTABLE NS_IMETHOD GetNonStandard(PRBool *aNonStandard) { return _to GetNonStandard(aNonStandard); } \
  NS_SCRIPTABLE NS_IMETHOD GetSymCipherName(nsACString & aSymCipherName) { return _to GetSymCipherName(aSymCipherName); } \
  NS_SCRIPTABLE NS_IMETHOD GetAuthAlgorithmName(nsACString & aAuthAlgorithmName) { return _to GetAuthAlgorithmName(aAuthAlgorithmName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeaTypeName(nsACString & aKeaTypeName) { return _to GetKeaTypeName(aKeaTypeName); } \
  NS_SCRIPTABLE NS_IMETHOD GetMacAlgorithmName(nsACString & aMacAlgorithmName) { return _to GetMacAlgorithmName(aMacAlgorithmName); } \
  NS_SCRIPTABLE NS_IMETHOD GetEffectiveKeyBits(PRInt32 *aEffectiveKeyBits) { return _to GetEffectiveKeyBits(aEffectiveKeyBits); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICIPHERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLongName(nsACString & aLongName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLongName(aLongName); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSSL2(PRBool *aIsSSL2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSSL2(aIsSSL2); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPS(PRBool *aIsFIPS) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFIPS(aIsFIPS); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsExportable(PRBool *aIsExportable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExportable(aIsExportable); } \
  NS_SCRIPTABLE NS_IMETHOD GetNonStandard(PRBool *aNonStandard) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNonStandard(aNonStandard); } \
  NS_SCRIPTABLE NS_IMETHOD GetSymCipherName(nsACString & aSymCipherName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSymCipherName(aSymCipherName); } \
  NS_SCRIPTABLE NS_IMETHOD GetAuthAlgorithmName(nsACString & aAuthAlgorithmName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthAlgorithmName(aAuthAlgorithmName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeaTypeName(nsACString & aKeaTypeName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeaTypeName(aKeaTypeName); } \
  NS_SCRIPTABLE NS_IMETHOD GetMacAlgorithmName(nsACString & aMacAlgorithmName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMacAlgorithmName(aMacAlgorithmName); } \
  NS_SCRIPTABLE NS_IMETHOD GetEffectiveKeyBits(PRInt32 *aEffectiveKeyBits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEffectiveKeyBits(aEffectiveKeyBits); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCipherInfo : public nsICipherInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICIPHERINFO

  nsCipherInfo();

private:
  ~nsCipherInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCipherInfo, nsICipherInfo)

nsCipherInfo::nsCipherInfo()
{
  /* member initializers and constructor code */
}

nsCipherInfo::~nsCipherInfo()
{
  /* destructor code */
}

/* readonly attribute ACString longName; */
NS_IMETHODIMP nsCipherInfo::GetLongName(nsACString & aLongName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRBool isSSL2; */
NS_IMETHODIMP nsCipherInfo::GetIsSSL2(PRBool *aIsSSL2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRBool isFIPS; */
NS_IMETHODIMP nsCipherInfo::GetIsFIPS(PRBool *aIsFIPS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRBool isExportable; */
NS_IMETHODIMP nsCipherInfo::GetIsExportable(PRBool *aIsExportable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRBool nonStandard; */
NS_IMETHODIMP nsCipherInfo::GetNonStandard(PRBool *aNonStandard)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString symCipherName; */
NS_IMETHODIMP nsCipherInfo::GetSymCipherName(nsACString & aSymCipherName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString authAlgorithmName; */
NS_IMETHODIMP nsCipherInfo::GetAuthAlgorithmName(nsACString & aAuthAlgorithmName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString keaTypeName; */
NS_IMETHODIMP nsCipherInfo::GetKeaTypeName(nsACString & aKeaTypeName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString macAlgorithmName; */
NS_IMETHODIMP nsCipherInfo::GetMacAlgorithmName(nsACString & aMacAlgorithmName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 effectiveKeyBits; */
NS_IMETHODIMP nsCipherInfo::GetEffectiveKeyBits(PRInt32 *aEffectiveKeyBits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICipherInfoService */
#define NS_ICIPHERINFOSERVICE_IID_STR "766d47cb-6d8c-4e71-b6b7-336917629a69"

#define NS_ICIPHERINFOSERVICE_IID \
  {0x766d47cb, 0x6d8c, 0x4e71, \
    { 0xb6, 0xb7, 0x33, 0x69, 0x17, 0x62, 0x9a, 0x69 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICipherInfoService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICIPHERINFOSERVICE_IID)

  /* nsICipherInfo getCipherInfoByPrefString (in ACString aPrefString); */
  NS_SCRIPTABLE NS_IMETHOD GetCipherInfoByPrefString(const nsACString & aPrefString, nsICipherInfo **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICipherInfoService, NS_ICIPHERINFOSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICIPHERINFOSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetCipherInfoByPrefString(const nsACString & aPrefString, nsICipherInfo **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICIPHERINFOSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCipherInfoByPrefString(const nsACString & aPrefString, nsICipherInfo **_retval NS_OUTPARAM) { return _to GetCipherInfoByPrefString(aPrefString, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICIPHERINFOSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCipherInfoByPrefString(const nsACString & aPrefString, nsICipherInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCipherInfoByPrefString(aPrefString, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCipherInfoService : public nsICipherInfoService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICIPHERINFOSERVICE

  nsCipherInfoService();

private:
  ~nsCipherInfoService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCipherInfoService, nsICipherInfoService)

nsCipherInfoService::nsCipherInfoService()
{
  /* member initializers and constructor code */
}

nsCipherInfoService::~nsCipherInfoService()
{
  /* destructor code */
}

/* nsICipherInfo getCipherInfoByPrefString (in ACString aPrefString); */
NS_IMETHODIMP nsCipherInfoService::GetCipherInfoByPrefString(const nsACString & aPrefString, nsICipherInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CIPHERINFOSERVICE_CID { /* ec693a6f-0832-49dd-877c-89f6552df5de */ \
    0xec693a6f,                                                        \
    0x0832,                                                            \
    0x49dd,                                                            \
    {0x87, 0x7c, 0x89, 0xf6, 0x55, 0x2d, 0xf5, 0xde}                   \
  }
#define NS_CIPHERINFOSERVICE_CONTRACTID "@mozilla.org/security/cipherinfo;1"

#endif /* __gen_nsICipherInfo_h__ */
