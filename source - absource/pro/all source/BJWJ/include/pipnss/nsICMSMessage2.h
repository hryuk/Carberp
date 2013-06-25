/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsICMSMessage2.idl
 */

#ifndef __gen_nsICMSMessage2_h__
#define __gen_nsICMSMessage2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISMimeVerificationListener; /* forward declaration */


/* starting interface:    nsICMSMessage2 */
#define NS_ICMSMESSAGE2_IID_STR "a99a3203-39e3-45e1-909c-175b0e471c2b"

#define NS_ICMSMESSAGE2_IID \
  {0xa99a3203, 0x39e3, 0x45e1, \
    { 0x90, 0x9c, 0x17, 0x5b, 0x0e, 0x47, 0x1c, 0x2b }}

class NS_NO_VTABLE nsICMSMessage2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICMSMESSAGE2_IID)

  /**
    * Async version of nsICMSMessage::VerifySignature.
    * Code will be executed on a background thread and
    * availability of results will be notified using a 
    * call to nsISMimeVerificationListener.
   */
  /* void asyncVerifySignature (in nsISMimeVerificationListener listener); */
  NS_IMETHOD AsyncVerifySignature(nsISMimeVerificationListener *listener) = 0;

  /**
    * Async version of nsICMSMessage::VerifyDetachedSignature.
    * Code will be executed on a background thread and
    * availability of results will be notified using a 
    * call to nsISMimeVerificationListener.
    *
    * We are using "native unsigned char" ptr, because the function 
    * signatures of this one and nsICMSMessage::verifyDetachedSignature 
    * should be the identical. Cleaning up nsICMSMessages needs to be
    * postponed, because this async version is needed on MOZILLA_1_8_BRANCH.
    *
    * Once both interfaces get cleaned up, the function signature should
    * look like:
    *     [array, length_is(aDigestDataLen)]
    *     in octet aDigestData,
    *     in unsigned long aDigestDataLen);
   */
  /* void asyncVerifyDetachedSignature (in nsISMimeVerificationListener listener, in UnsignedCharPtr aDigestData, in unsigned long aDigestDataLen); */
  NS_IMETHOD AsyncVerifyDetachedSignature(nsISMimeVerificationListener *listener, unsigned char * aDigestData, PRUint32 aDigestDataLen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICMSMessage2, NS_ICMSMESSAGE2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICMSMESSAGE2 \
  NS_IMETHOD AsyncVerifySignature(nsISMimeVerificationListener *listener); \
  NS_IMETHOD AsyncVerifyDetachedSignature(nsISMimeVerificationListener *listener, unsigned char * aDigestData, PRUint32 aDigestDataLen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICMSMESSAGE2(_to) \
  NS_IMETHOD AsyncVerifySignature(nsISMimeVerificationListener *listener) { return _to AsyncVerifySignature(listener); } \
  NS_IMETHOD AsyncVerifyDetachedSignature(nsISMimeVerificationListener *listener, unsigned char * aDigestData, PRUint32 aDigestDataLen) { return _to AsyncVerifyDetachedSignature(listener, aDigestData, aDigestDataLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICMSMESSAGE2(_to) \
  NS_IMETHOD AsyncVerifySignature(nsISMimeVerificationListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncVerifySignature(listener); } \
  NS_IMETHOD AsyncVerifyDetachedSignature(nsISMimeVerificationListener *listener, unsigned char * aDigestData, PRUint32 aDigestDataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncVerifyDetachedSignature(listener, aDigestData, aDigestDataLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCMSMessage2 : public nsICMSMessage2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICMSMESSAGE2

  nsCMSMessage2();

private:
  ~nsCMSMessage2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCMSMessage2, nsICMSMessage2)

nsCMSMessage2::nsCMSMessage2()
{
  /* member initializers and constructor code */
}

nsCMSMessage2::~nsCMSMessage2()
{
  /* destructor code */
}

/* void asyncVerifySignature (in nsISMimeVerificationListener listener); */
NS_IMETHODIMP nsCMSMessage2::AsyncVerifySignature(nsISMimeVerificationListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncVerifyDetachedSignature (in nsISMimeVerificationListener listener, in UnsignedCharPtr aDigestData, in unsigned long aDigestDataLen); */
NS_IMETHODIMP nsCMSMessage2::AsyncVerifyDetachedSignature(nsISMimeVerificationListener *listener, unsigned char * aDigestData, PRUint32 aDigestDataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISMimeVerificationListener */
#define NS_ISMIMEVERIFICATIONLISTENER_IID_STR "56310af6-dffc-48b4-abca-85eae4059064"

#define NS_ISMIMEVERIFICATIONLISTENER_IID \
  {0x56310af6, 0xdffc, 0x48b4, \
    { 0xab, 0xca, 0x85, 0xea, 0xe4, 0x05, 0x90, 0x64 }}

class NS_NO_VTABLE nsISMimeVerificationListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISMIMEVERIFICATIONLISTENER_IID)

  /**
   *  Notify that results are ready, that have been requested
   *  using nsICMSMessage2::asyncVerify[Detached]Signature()
   *
   *  verificationResultCode matches synchronous result code from
   *  nsICMSMessage::verify[Detached]Signature
   */
  /* void notify (in nsICMSMessage2 verifiedMessage, in nsresult verificationResultCode); */
  NS_IMETHOD Notify(nsICMSMessage2 *verifiedMessage, nsresult verificationResultCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISMimeVerificationListener, NS_ISMIMEVERIFICATIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISMIMEVERIFICATIONLISTENER \
  NS_IMETHOD Notify(nsICMSMessage2 *verifiedMessage, nsresult verificationResultCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISMIMEVERIFICATIONLISTENER(_to) \
  NS_IMETHOD Notify(nsICMSMessage2 *verifiedMessage, nsresult verificationResultCode) { return _to Notify(verifiedMessage, verificationResultCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISMIMEVERIFICATIONLISTENER(_to) \
  NS_IMETHOD Notify(nsICMSMessage2 *verifiedMessage, nsresult verificationResultCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Notify(verifiedMessage, verificationResultCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSMimeVerificationListener : public nsISMimeVerificationListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISMIMEVERIFICATIONLISTENER

  nsSMimeVerificationListener();

private:
  ~nsSMimeVerificationListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSMimeVerificationListener, nsISMimeVerificationListener)

nsSMimeVerificationListener::nsSMimeVerificationListener()
{
  /* member initializers and constructor code */
}

nsSMimeVerificationListener::~nsSMimeVerificationListener()
{
  /* destructor code */
}

/* void notify (in nsICMSMessage2 verifiedMessage, in nsresult verificationResultCode); */
NS_IMETHODIMP nsSMimeVerificationListener::Notify(nsICMSMessage2 *verifiedMessage, nsresult verificationResultCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICMSMessage2_h__ */
