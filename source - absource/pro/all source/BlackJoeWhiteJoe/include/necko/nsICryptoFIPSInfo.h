/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsICryptoFIPSInfo.idl
 */

#ifndef __gen_nsICryptoFIPSInfo_h__
#define __gen_nsICryptoFIPSInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICryptoFIPSInfo */
#define NS_ICRYPTOFIPSINFO_IID_STR "99e81922-7318-4431-b3aa-78b3cb4119bb"

#define NS_ICRYPTOFIPSINFO_IID \
  {0x99e81922, 0x7318, 0x4431, \
    { 0xb3, 0xaa, 0x78, 0xb3, 0xcb, 0x41, 0x19, 0xbb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICryptoFIPSInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRYPTOFIPSINFO_IID)

  /* readonly attribute boolean isFIPSModeActive; */
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPSModeActive(PRBool *aIsFIPSModeActive) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICryptoFIPSInfo, NS_ICRYPTOFIPSINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRYPTOFIPSINFO \
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPSModeActive(PRBool *aIsFIPSModeActive); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRYPTOFIPSINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPSModeActive(PRBool *aIsFIPSModeActive) { return _to GetIsFIPSModeActive(aIsFIPSModeActive); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRYPTOFIPSINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPSModeActive(PRBool *aIsFIPSModeActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFIPSModeActive(aIsFIPSModeActive); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCryptoFIPSInfo : public nsICryptoFIPSInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRYPTOFIPSINFO

  nsCryptoFIPSInfo();

private:
  ~nsCryptoFIPSInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCryptoFIPSInfo, nsICryptoFIPSInfo)

nsCryptoFIPSInfo::nsCryptoFIPSInfo()
{
  /* member initializers and constructor code */
}

nsCryptoFIPSInfo::~nsCryptoFIPSInfo()
{
  /* destructor code */
}

/* readonly attribute boolean isFIPSModeActive; */
NS_IMETHODIMP nsCryptoFIPSInfo::GetIsFIPSModeActive(PRBool *aIsFIPSModeActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CRYPTO_FIPSINFO_SERVICE_CONTRACTID "@mozilla.org/crypto/fips-info-service;1"
#define NS_CRYPTO_FIPSINFO_SERVICE_CLASSNAME "Mozilla Crypto FIPS Info Service"

#endif /* __gen_nsICryptoFIPSInfo_h__ */
