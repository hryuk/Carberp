/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIDataSignatureVerifier.idl
 */

#ifndef __gen_nsIDataSignatureVerifier_h__
#define __gen_nsIDataSignatureVerifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDataSignatureVerifier */
#define NS_IDATASIGNATUREVERIFIER_IID_STR "0a84b3d5-6ba9-432d-89da-4fbd0b0f2aec"

#define NS_IDATASIGNATUREVERIFIER_IID \
  {0x0a84b3d5, 0x6ba9, 0x432d, \
    { 0x89, 0xda, 0x4f, 0xbd, 0x0b, 0x0f, 0x2a, 0xec }}

/**
 * An interface for verifying that a given string of data was signed by the
 * private key matching the given public key.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDataSignatureVerifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDATASIGNATUREVERIFIER_IID)

  /**
   * Verifies that the data matches the data that was used to generate the
   * signature.
   *
   * @param aData      The data to be tested.
   * @param aSignature The signature of the data, base64 encoded.
   * @param aPublicKey The public part of the key used for signing, DER encoded
   *                   then base64 encoded.
   * @returns true if the signature matches the data, false if not.
   */
  /* boolean verifyData (in ACString aData, in ACString aSignature, in ACString aPublicKey); */
  NS_SCRIPTABLE NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDataSignatureVerifier, NS_IDATASIGNATUREVERIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDATASIGNATUREVERIFIER \
  NS_SCRIPTABLE NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDATASIGNATUREVERIFIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, PRBool *_retval NS_OUTPARAM) { return _to VerifyData(aData, aSignature, aPublicKey, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDATASIGNATUREVERIFIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifyData(aData, aSignature, aPublicKey, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDataSignatureVerifier : public nsIDataSignatureVerifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDATASIGNATUREVERIFIER

  nsDataSignatureVerifier();

private:
  ~nsDataSignatureVerifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDataSignatureVerifier, nsIDataSignatureVerifier)

nsDataSignatureVerifier::nsDataSignatureVerifier()
{
  /* member initializers and constructor code */
}

nsDataSignatureVerifier::~nsDataSignatureVerifier()
{
  /* destructor code */
}

/* boolean verifyData (in ACString aData, in ACString aSignature, in ACString aPublicKey); */
NS_IMETHODIMP nsDataSignatureVerifier::VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDataSignatureVerifier_h__ */
