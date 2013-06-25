/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsISSLStatus.idl
 */

#ifndef __gen_nsISSLStatus_h__
#define __gen_nsISSLStatus_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */


/* starting interface:    nsISSLStatus */
#define NS_ISSLSTATUS_IID_STR "cfede939-def1-49be-81ed-d401b3a07d1c"

#define NS_ISSLSTATUS_IID \
  {0xcfede939, 0xdef1, 0x49be, \
    { 0x81, 0xed, 0xd4, 0x01, 0xb3, 0xa0, 0x7d, 0x1c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISSLStatus : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISSLSTATUS_IID)

  /* readonly attribute nsIX509Cert serverCert; */
  NS_SCRIPTABLE NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) = 0;

  /* readonly attribute string cipherName; */
  NS_SCRIPTABLE NS_IMETHOD GetCipherName(char * *aCipherName) = 0;

  /* readonly attribute unsigned long keyLength; */
  NS_SCRIPTABLE NS_IMETHOD GetKeyLength(PRUint32 *aKeyLength) = 0;

  /* readonly attribute unsigned long secretKeyLength; */
  NS_SCRIPTABLE NS_IMETHOD GetSecretKeyLength(PRUint32 *aSecretKeyLength) = 0;

  /* readonly attribute boolean isDomainMismatch; */
  NS_SCRIPTABLE NS_IMETHOD GetIsDomainMismatch(PRBool *aIsDomainMismatch) = 0;

  /* readonly attribute boolean isNotValidAtThisTime; */
  NS_SCRIPTABLE NS_IMETHOD GetIsNotValidAtThisTime(PRBool *aIsNotValidAtThisTime) = 0;

  /* readonly attribute boolean isUntrusted; */
  NS_SCRIPTABLE NS_IMETHOD GetIsUntrusted(PRBool *aIsUntrusted) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISSLStatus, NS_ISSLSTATUS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISSLSTATUS \
  NS_SCRIPTABLE NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert); \
  NS_SCRIPTABLE NS_IMETHOD GetCipherName(char * *aCipherName); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyLength(PRUint32 *aKeyLength); \
  NS_SCRIPTABLE NS_IMETHOD GetSecretKeyLength(PRUint32 *aSecretKeyLength); \
  NS_SCRIPTABLE NS_IMETHOD GetIsDomainMismatch(PRBool *aIsDomainMismatch); \
  NS_SCRIPTABLE NS_IMETHOD GetIsNotValidAtThisTime(PRBool *aIsNotValidAtThisTime); \
  NS_SCRIPTABLE NS_IMETHOD GetIsUntrusted(PRBool *aIsUntrusted); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISSLSTATUS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) { return _to GetServerCert(aServerCert); } \
  NS_SCRIPTABLE NS_IMETHOD GetCipherName(char * *aCipherName) { return _to GetCipherName(aCipherName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyLength(PRUint32 *aKeyLength) { return _to GetKeyLength(aKeyLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSecretKeyLength(PRUint32 *aSecretKeyLength) { return _to GetSecretKeyLength(aSecretKeyLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDomainMismatch(PRBool *aIsDomainMismatch) { return _to GetIsDomainMismatch(aIsDomainMismatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNotValidAtThisTime(PRBool *aIsNotValidAtThisTime) { return _to GetIsNotValidAtThisTime(aIsNotValidAtThisTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsUntrusted(PRBool *aIsUntrusted) { return _to GetIsUntrusted(aIsUntrusted); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISSLSTATUS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServerCert(aServerCert); } \
  NS_SCRIPTABLE NS_IMETHOD GetCipherName(char * *aCipherName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCipherName(aCipherName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyLength(PRUint32 *aKeyLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyLength(aKeyLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSecretKeyLength(PRUint32 *aSecretKeyLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecretKeyLength(aSecretKeyLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDomainMismatch(PRBool *aIsDomainMismatch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDomainMismatch(aIsDomainMismatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNotValidAtThisTime(PRBool *aIsNotValidAtThisTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNotValidAtThisTime(aIsNotValidAtThisTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsUntrusted(PRBool *aIsUntrusted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsUntrusted(aIsUntrusted); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSSLStatus : public nsISSLStatus
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISSLSTATUS

  nsSSLStatus();

private:
  ~nsSSLStatus();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSSLStatus, nsISSLStatus)

nsSSLStatus::nsSSLStatus()
{
  /* member initializers and constructor code */
}

nsSSLStatus::~nsSSLStatus()
{
  /* destructor code */
}

/* readonly attribute nsIX509Cert serverCert; */
NS_IMETHODIMP nsSSLStatus::GetServerCert(nsIX509Cert * *aServerCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string cipherName; */
NS_IMETHODIMP nsSSLStatus::GetCipherName(char * *aCipherName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long keyLength; */
NS_IMETHODIMP nsSSLStatus::GetKeyLength(PRUint32 *aKeyLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long secretKeyLength; */
NS_IMETHODIMP nsSSLStatus::GetSecretKeyLength(PRUint32 *aSecretKeyLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDomainMismatch; */
NS_IMETHODIMP nsSSLStatus::GetIsDomainMismatch(PRBool *aIsDomainMismatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isNotValidAtThisTime; */
NS_IMETHODIMP nsSSLStatus::GetIsNotValidAtThisTime(PRBool *aIsNotValidAtThisTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isUntrusted; */
NS_IMETHODIMP nsSSLStatus::GetIsUntrusted(PRBool *aIsUntrusted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISSLStatus_h__ */
