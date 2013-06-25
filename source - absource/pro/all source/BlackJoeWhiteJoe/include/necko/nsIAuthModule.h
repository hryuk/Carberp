/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIAuthModule.idl
 */

#ifndef __gen_nsIAuthModule_h__
#define __gen_nsIAuthModule_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAuthModule */
#define NS_IAUTHMODULE_IID_STR "6e35dbc0-49ef-4e2c-b1ea-b72ec64450a2"

#define NS_IAUTHMODULE_IID \
  {0x6e35dbc0, 0x49ef, 0x4e2c, \
    { 0xb1, 0xea, 0xb7, 0x2e, 0xc6, 0x44, 0x50, 0xa2 }}

class NS_NO_VTABLE nsIAuthModule : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHMODULE_IID)

  /**
     * Default behavior.
     */
  enum { REQ_DEFAULT = 0U };

  /**
     * Client and server will be authenticated.
     */
  enum { REQ_MUTUAL_AUTH = 1U };

  /**
     * The server is allowed to impersonate the client.  The REQ_MUTUAL_AUTH
     * flag may also need to be specified in order for this flag to take
     * effect.
     */
  enum { REQ_DELEGATE = 2U };

  /** Other flags may be defined in the future */
/**
     * Called to initialize an auth module.  The other methods cannot be called
     * unless this method succeeds.
     *
     * @param aServiceName
     *        the service name, which may be null if not applicable (e.g., for
     *        NTLM, this parameter should be null).
     * @param aServiceFlags
     *        a bitwise-or of the REQ_ flags defined above (pass REQ_DEFAULT
     *        for default behavior).
     * @param aDomain
     *        the authentication domain, which may be null if not applicable.
     * @param aUsername
     *        the user's login name
     * @param aPassword
     *        the user's password
     */
  /* void init (in string aServiceName, in unsigned long aServiceFlags, in wstring aDomain, in wstring aUsername, in wstring aPassword); */
  NS_IMETHOD Init(const char *aServiceName, PRUint32 aServiceFlags, const PRUnichar *aDomain, const PRUnichar *aUsername, const PRUnichar *aPassword) = 0;

  /**
     * Called to get the next token in a sequence of authentication steps.
     *
     * @param aInToken
     *        A buffer containing the input token (e.g., a challenge from a
     *        server).  This may be null.
     * @param aInTokenLength
     *        The length of the input token.
     * @param aOutToken
     *        If getNextToken succeeds, then aOutToken will point to a buffer
     *        to be sent in response to the server challenge.  The length of
     *        this buffer is given by aOutTokenLength.  The buffer at aOutToken
     *        must be recycled with a call to nsMemory::Free.
     * @param aOutTokenLength
     *        If getNextToken succeeds, then aOutTokenLength contains the
     *        length of the buffer (number of bytes) pointed to by aOutToken.
     */
  /* void getNextToken ([const] in voidPtr aInToken, in unsigned long aInTokenLength, out voidPtr aOutToken, out unsigned long aOutTokenLength); */
  NS_IMETHOD GetNextToken(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM) = 0;

  /** 
     * Once a security context has been established through calls to GetNextToken()
     * it may be used to protect data exchanged between client and server. Calls
     * to Wrap() are used to protect items of data to be sent to the server.
     * 
     * @param aInToken
     *        A buffer containing the data to be sent to the server
     * @param aInTokenLength
     *        The length of the input token
     * @param confidential
     *        If set to true, Wrap() will encrypt the data, otherwise data will
     *        just be integrity protected (checksummed)
     * @param aOutToken
     *        A buffer containing the resulting data to be sent to the server
     * @param aOutTokenLength
     *        The length of the output token buffer
     *
     * Wrap() may return NS_ERROR_NOT_IMPLEMENTED, if the underlying authentication
     * mechanism does not support security layers.
     */
  /* void wrap ([const] in voidPtr aInToken, in unsigned long aInTokenLength, in boolean confidential, out voidPtr aOutToken, out unsigned long aOutTokenLength); */
  NS_IMETHOD Wrap(const void * aInToken, PRUint32 aInTokenLength, PRBool confidential, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM) = 0;

  /** 
     * Unwrap() is used to unpack, decrypt, and verify the checksums on data
     * returned by a server when security layers are in use.
     * 
     * @param aInToken
     *        A buffer containing the data received from the server
     * @param aInTokenLength
     *        The length of the input token
     * @param aOutToken
     *        A buffer containing the plaintext data from the server
     * @param aOutTokenLength
     *        The length of the output token buffer
     *
     * Unwrap() may return NS_ERROR_NOT_IMPLEMENTED, if the underlying  
     * authentication mechanism does not support security layers.
     */
  /* void unwrap ([const] in voidPtr aInToken, in unsigned long aInTokenLength, out voidPtr aOutToken, out unsigned long aOutTokenLength); */
  NS_IMETHOD Unwrap(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthModule, NS_IAUTHMODULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHMODULE \
  NS_IMETHOD Init(const char *aServiceName, PRUint32 aServiceFlags, const PRUnichar *aDomain, const PRUnichar *aUsername, const PRUnichar *aPassword); \
  NS_IMETHOD GetNextToken(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM); \
  NS_IMETHOD Wrap(const void * aInToken, PRUint32 aInTokenLength, PRBool confidential, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM); \
  NS_IMETHOD Unwrap(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHMODULE(_to) \
  NS_IMETHOD Init(const char *aServiceName, PRUint32 aServiceFlags, const PRUnichar *aDomain, const PRUnichar *aUsername, const PRUnichar *aPassword) { return _to Init(aServiceName, aServiceFlags, aDomain, aUsername, aPassword); } \
  NS_IMETHOD GetNextToken(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM) { return _to GetNextToken(aInToken, aInTokenLength, aOutToken, aOutTokenLength); } \
  NS_IMETHOD Wrap(const void * aInToken, PRUint32 aInTokenLength, PRBool confidential, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM) { return _to Wrap(aInToken, aInTokenLength, confidential, aOutToken, aOutTokenLength); } \
  NS_IMETHOD Unwrap(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM) { return _to Unwrap(aInToken, aInTokenLength, aOutToken, aOutTokenLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHMODULE(_to) \
  NS_IMETHOD Init(const char *aServiceName, PRUint32 aServiceFlags, const PRUnichar *aDomain, const PRUnichar *aUsername, const PRUnichar *aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aServiceName, aServiceFlags, aDomain, aUsername, aPassword); } \
  NS_IMETHOD GetNextToken(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextToken(aInToken, aInTokenLength, aOutToken, aOutTokenLength); } \
  NS_IMETHOD Wrap(const void * aInToken, PRUint32 aInTokenLength, PRBool confidential, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Wrap(aInToken, aInTokenLength, confidential, aOutToken, aOutTokenLength); } \
  NS_IMETHOD Unwrap(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unwrap(aInToken, aInTokenLength, aOutToken, aOutTokenLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthModule : public nsIAuthModule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHMODULE

  nsAuthModule();

private:
  ~nsAuthModule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthModule, nsIAuthModule)

nsAuthModule::nsAuthModule()
{
  /* member initializers and constructor code */
}

nsAuthModule::~nsAuthModule()
{
  /* destructor code */
}

/* void init (in string aServiceName, in unsigned long aServiceFlags, in wstring aDomain, in wstring aUsername, in wstring aPassword); */
NS_IMETHODIMP nsAuthModule::Init(const char *aServiceName, PRUint32 aServiceFlags, const PRUnichar *aDomain, const PRUnichar *aUsername, const PRUnichar *aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNextToken ([const] in voidPtr aInToken, in unsigned long aInTokenLength, out voidPtr aOutToken, out unsigned long aOutTokenLength); */
NS_IMETHODIMP nsAuthModule::GetNextToken(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrap ([const] in voidPtr aInToken, in unsigned long aInTokenLength, in boolean confidential, out voidPtr aOutToken, out unsigned long aOutTokenLength); */
NS_IMETHODIMP nsAuthModule::Wrap(const void * aInToken, PRUint32 aInTokenLength, PRBool confidential, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unwrap ([const] in voidPtr aInToken, in unsigned long aInTokenLength, out voidPtr aOutToken, out unsigned long aOutTokenLength); */
NS_IMETHODIMP nsAuthModule::Unwrap(const void * aInToken, PRUint32 aInTokenLength, void * *aOutToken NS_OUTPARAM, PRUint32 *aOutTokenLength NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * nsIAuthModule implementations are registered under the following contract
 * ID prefix:
 */
#define NS_AUTH_MODULE_CONTRACTID_PREFIX \
    "@mozilla.org/network/auth-module;1?name="
/**
 * This success code may be returned by nsIAuthModule::getNextToken to 
 * indicate that the authentication is finished and thus there's no need 
 * to call getNextToken again.
 */
#define NS_SUCCESS_AUTH_FINISHED \
    NS_ERROR_GENERATE_SUCCESS(NS_ERROR_MODULE_NETWORK, 40)

#endif /* __gen_nsIAuthModule_h__ */
