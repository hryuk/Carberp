/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIX509Cert3.idl
 */

#ifndef __gen_nsIX509Cert3_h__
#define __gen_nsIX509Cert3_h__


#ifndef __gen_nsIX509Cert2_h__
#include "nsIX509Cert2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICertVerificationListener; /* forward declaration */


/* starting interface:    nsIX509Cert3 */
#define NS_IX509CERT3_IID_STR "399004d8-b8c7-4eb9-8362-d99f4c0161fd"

#define NS_IX509CERT3_IID \
  {0x399004d8, 0xb8c7, 0x4eb9, \
    { 0x83, 0x62, 0xd9, 0x9f, 0x4c, 0x01, 0x61, 0xfd }}

/**
 * Extending nsIX509Cert
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIX509Cert3 : public nsIX509Cert2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERT3_IID)

  /**
   *  Constants for specifying the chain mode when exporting a certificate
   */
  enum { CMS_CHAIN_MODE_CertOnly = 1U };

  enum { CMS_CHAIN_MODE_CertChain = 2U };

  enum { CMS_CHAIN_MODE_CertChainWithRoot = 3U };

  /**
   *  Async version of nsIX509Cert::getUsagesArray()
   *
   *  Will not block, will request results asynchronously,
   *  availability of results will be notified.
   */
  /* void requestUsagesArrayAsync (in nsICertVerificationListener cvl); */
  NS_SCRIPTABLE NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) = 0;

  /**
   *  Obtain the certificate wrapped in a PKCS#7 SignedData structure,
   *  with or without the certificate chain
   *
   *  @param chainMode Whether to include the chain (with or without the root),
                       see CMS_CHAIN_MODE constants.
   *  @param length The number of bytes of the PKCS#7 data.
   *  @param data The bytes representing the PKCS#7 wrapped certificate.
   */
  /* void exportAsCMS (in unsigned long chainMode, out unsigned long length, [array, size_is (length), retval] out octet data); */
  NS_SCRIPTABLE NS_IMETHOD ExportAsCMS(PRUint32 chainMode, PRUint32 *length NS_OUTPARAM, PRUint8 **data NS_OUTPARAM) = 0;

  /* readonly attribute boolean isSelfSigned; */
  NS_SCRIPTABLE NS_IMETHOD GetIsSelfSigned(PRBool *aIsSelfSigned) = 0;

  /**
   * Human readable names identifying all hardware or
   * software tokens the certificate is stored on.
   *
   * @param length On success, the number of entries in the returned array.
   * @return On success, an array containing the names of all tokens 
   *         the certificate is stored on (may be empty).
   *         On failure the function throws/returns an error.
   */
  /* void getAllTokenNames (out unsigned long length, [array, size_is (length), retval] out wstring tokenNames); */
  NS_SCRIPTABLE NS_IMETHOD GetAllTokenNames(PRUint32 *length NS_OUTPARAM, PRUnichar ***tokenNames NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509Cert3, NS_IX509CERT3_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERT3 \
  NS_SCRIPTABLE NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl); \
  NS_SCRIPTABLE NS_IMETHOD ExportAsCMS(PRUint32 chainMode, PRUint32 *length NS_OUTPARAM, PRUint8 **data NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIsSelfSigned(PRBool *aIsSelfSigned); \
  NS_SCRIPTABLE NS_IMETHOD GetAllTokenNames(PRUint32 *length NS_OUTPARAM, PRUnichar ***tokenNames NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERT3(_to) \
  NS_SCRIPTABLE NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) { return _to RequestUsagesArrayAsync(cvl); } \
  NS_SCRIPTABLE NS_IMETHOD ExportAsCMS(PRUint32 chainMode, PRUint32 *length NS_OUTPARAM, PRUint8 **data NS_OUTPARAM) { return _to ExportAsCMS(chainMode, length, data); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSelfSigned(PRBool *aIsSelfSigned) { return _to GetIsSelfSigned(aIsSelfSigned); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllTokenNames(PRUint32 *length NS_OUTPARAM, PRUnichar ***tokenNames NS_OUTPARAM) { return _to GetAllTokenNames(length, tokenNames); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERT3(_to) \
  NS_SCRIPTABLE NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestUsagesArrayAsync(cvl); } \
  NS_SCRIPTABLE NS_IMETHOD ExportAsCMS(PRUint32 chainMode, PRUint32 *length NS_OUTPARAM, PRUint8 **data NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExportAsCMS(chainMode, length, data); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSelfSigned(PRBool *aIsSelfSigned) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSelfSigned(aIsSelfSigned); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllTokenNames(PRUint32 *length NS_OUTPARAM, PRUnichar ***tokenNames NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllTokenNames(length, tokenNames); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509Cert3 : public nsIX509Cert3
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERT3

  nsX509Cert3();

private:
  ~nsX509Cert3();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsX509Cert3, nsIX509Cert3)

nsX509Cert3::nsX509Cert3()
{
  /* member initializers and constructor code */
}

nsX509Cert3::~nsX509Cert3()
{
  /* destructor code */
}

/* void requestUsagesArrayAsync (in nsICertVerificationListener cvl); */
NS_IMETHODIMP nsX509Cert3::RequestUsagesArrayAsync(nsICertVerificationListener *cvl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exportAsCMS (in unsigned long chainMode, out unsigned long length, [array, size_is (length), retval] out octet data); */
NS_IMETHODIMP nsX509Cert3::ExportAsCMS(PRUint32 chainMode, PRUint32 *length NS_OUTPARAM, PRUint8 **data NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSelfSigned; */
NS_IMETHODIMP nsX509Cert3::GetIsSelfSigned(PRBool *aIsSelfSigned)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllTokenNames (out unsigned long length, [array, size_is (length), retval] out wstring tokenNames); */
NS_IMETHODIMP nsX509Cert3::GetAllTokenNames(PRUint32 *length NS_OUTPARAM, PRUnichar ***tokenNames NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICertVerificationResult */
#define NS_ICERTVERIFICATIONRESULT_IID_STR "2fd0a785-9f2d-4327-8871-8c3e0783891d"

#define NS_ICERTVERIFICATIONRESULT_IID \
  {0x2fd0a785, 0x9f2d, 0x4327, \
    { 0x88, 0x71, 0x8c, 0x3e, 0x07, 0x83, 0x89, 0x1d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICertVerificationResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTVERIFICATIONRESULT_IID)

  /**
   *  This interface reflects a container of
   *  verification results. Call will not block.
   *
   *  Obtain an array of human readable strings describing
   *  the certificate's certified usages.
   *
   *  Mirrors the results produced by 
   *  nsIX509Cert::getUsagesArray()
   *
   *  As of today, this function is a one-shot object,
   *  only the first call will succeed.
   *  This allows an optimization in the implementation, 
   *  ownership of result data will be transfered to caller.
   *
   *  @param cert The certificate that was verified.
   *  @param verified The certificate verification result, 
   *         see constants in nsIX509Cert.
   *  @param count The number of human readable usages returned.
   *  @param usages The array of human readable usages.
   */
  /* void getUsagesArrayResult (out PRUint32 verified, out PRUint32 count, [array, size_is (count)] out wstring usages); */
  NS_SCRIPTABLE NS_IMETHOD GetUsagesArrayResult(PRUint32 *verified NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, PRUnichar ***usages NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertVerificationResult, NS_ICERTVERIFICATIONRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTVERIFICATIONRESULT \
  NS_SCRIPTABLE NS_IMETHOD GetUsagesArrayResult(PRUint32 *verified NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, PRUnichar ***usages NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTVERIFICATIONRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUsagesArrayResult(PRUint32 *verified NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, PRUnichar ***usages NS_OUTPARAM) { return _to GetUsagesArrayResult(verified, count, usages); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTVERIFICATIONRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUsagesArrayResult(PRUint32 *verified NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, PRUnichar ***usages NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsagesArrayResult(verified, count, usages); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertVerificationResult : public nsICertVerificationResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTVERIFICATIONRESULT

  nsCertVerificationResult();

private:
  ~nsCertVerificationResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCertVerificationResult, nsICertVerificationResult)

nsCertVerificationResult::nsCertVerificationResult()
{
  /* member initializers and constructor code */
}

nsCertVerificationResult::~nsCertVerificationResult()
{
  /* destructor code */
}

/* void getUsagesArrayResult (out PRUint32 verified, out PRUint32 count, [array, size_is (count)] out wstring usages); */
NS_IMETHODIMP nsCertVerificationResult::GetUsagesArrayResult(PRUint32 *verified NS_OUTPARAM, PRUint32 *count NS_OUTPARAM, PRUnichar ***usages NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICertVerificationListener */
#define NS_ICERTVERIFICATIONLISTENER_IID_STR "6684bce9-50db-48e1-81b7-98102bf81357"

#define NS_ICERTVERIFICATIONLISTENER_IID \
  {0x6684bce9, 0x50db, 0x48e1, \
    { 0x81, 0xb7, 0x98, 0x10, 0x2b, 0xf8, 0x13, 0x57 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICertVerificationListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTVERIFICATIONLISTENER_IID)

  /**
   *  Notify that results are ready, that have been requested
   *  using nsIX509Cert3::requestUsagesArrayAsync()
   */
  /* void notify (in nsIX509Cert3 verifiedCert, in nsICertVerificationResult result); */
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertVerificationListener, NS_ICERTVERIFICATIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTVERIFICATIONLISTENER \
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTVERIFICATIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result) { return _to Notify(verifiedCert, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTVERIFICATIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->Notify(verifiedCert, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertVerificationListener : public nsICertVerificationListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTVERIFICATIONLISTENER

  nsCertVerificationListener();

private:
  ~nsCertVerificationListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCertVerificationListener, nsICertVerificationListener)

nsCertVerificationListener::nsCertVerificationListener()
{
  /* member initializers and constructor code */
}

nsCertVerificationListener::~nsCertVerificationListener()
{
  /* destructor code */
}

/* void notify (in nsIX509Cert3 verifiedCert, in nsICertVerificationResult result); */
NS_IMETHODIMP nsCertVerificationListener::Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIX509Cert3_h__ */
