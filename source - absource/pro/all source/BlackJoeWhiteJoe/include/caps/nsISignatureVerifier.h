/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/caps/idl/nsISignatureVerifier.idl
 */

#ifndef __gen_nsISignatureVerifier_h__
#define __gen_nsISignatureVerifier_h__


#ifndef __gen_nsIPrincipal_h__
#include "nsIPrincipal.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISignatureVerifier */
#define NS_ISIGNATUREVERIFIER_IID_STR "dea87f65-e91e-4119-aa13-aaa2be80cac2"

#define NS_ISIGNATUREVERIFIER_IID \
  {0xdea87f65, 0xe91e, 0x4119, \
    { 0xaa, 0x13, 0xaa, 0xa2, 0xbe, 0x80, 0xca, 0xc2 }}

class NS_NO_VTABLE nsISignatureVerifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIGNATUREVERIFIER_IID)

  enum { VERIFY_OK = 0 };

  enum { VERIFY_ERROR_UNKNOWN_CA = -8172 };

  /* nsIPrincipal verifySignature (in string aSignature, in unsigned long aSignatureLen, in string plaintext, in unsigned long plaintextLen, out long errorCode); */
  NS_IMETHOD VerifySignature(const char *aSignature, PRUint32 aSignatureLen, const char *plaintext, PRUint32 plaintextLen, PRInt32 *errorCode NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISignatureVerifier, NS_ISIGNATUREVERIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIGNATUREVERIFIER \
  NS_IMETHOD VerifySignature(const char *aSignature, PRUint32 aSignatureLen, const char *plaintext, PRUint32 plaintextLen, PRInt32 *errorCode NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIGNATUREVERIFIER(_to) \
  NS_IMETHOD VerifySignature(const char *aSignature, PRUint32 aSignatureLen, const char *plaintext, PRUint32 plaintextLen, PRInt32 *errorCode NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM) { return _to VerifySignature(aSignature, aSignatureLen, plaintext, plaintextLen, errorCode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIGNATUREVERIFIER(_to) \
  NS_IMETHOD VerifySignature(const char *aSignature, PRUint32 aSignatureLen, const char *plaintext, PRUint32 plaintextLen, PRInt32 *errorCode NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifySignature(aSignature, aSignatureLen, plaintext, plaintextLen, errorCode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSignatureVerifier : public nsISignatureVerifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIGNATUREVERIFIER

  nsSignatureVerifier();

private:
  ~nsSignatureVerifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSignatureVerifier, nsISignatureVerifier)

nsSignatureVerifier::nsSignatureVerifier()
{
  /* member initializers and constructor code */
}

nsSignatureVerifier::~nsSignatureVerifier()
{
  /* destructor code */
}

/* nsIPrincipal verifySignature (in string aSignature, in unsigned long aSignatureLen, in string plaintext, in unsigned long plaintextLen, out long errorCode); */
NS_IMETHODIMP nsSignatureVerifier::VerifySignature(const char *aSignature, PRUint32 aSignatureLen, const char *plaintext, PRUint32 plaintextLen, PRInt32 *errorCode NS_OUTPARAM, nsIPrincipal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define SIGNATURE_VERIFIER_CONTRACTID "@mozilla.org/psm;1"

#endif /* __gen_nsISignatureVerifier_h__ */
