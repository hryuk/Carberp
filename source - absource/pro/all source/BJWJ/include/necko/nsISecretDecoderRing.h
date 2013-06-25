/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsISecretDecoderRing.idl
 */

#ifndef __gen_nsISecretDecoderRing_h__
#define __gen_nsISecretDecoderRing_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISecretDecoderRing */
#define NS_ISECRETDECODERRING_IID_STR "0ec80360-075c-11d4-9fd4-00c04f1b83d8"

#define NS_ISECRETDECODERRING_IID \
  {0x0ec80360, 0x075c, 0x11d4, \
    { 0x9f, 0xd4, 0x00, 0xc0, 0x4f, 0x1b, 0x83, 0xd8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISecretDecoderRing : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECRETDECODERRING_IID)

  /**
   * Encrypt a buffer - callable only from C++.
   *
   * @return The length of the data in the output buffer.
   */
  /* [noscript] long encrypt (in buffer data, in long dataLen, out buffer result); */
  NS_IMETHOD Encrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Decrypt a buffer - callable only from C++.
   *
   * @return The length of the data in the output buffer.
   */
  /* [noscript] long decrypt (in buffer data, in long dataLen, out buffer result); */
  NS_IMETHOD Decrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Encrypt nul-terminated string to BASE64 output.
   */
  /* string encryptString (in string text); */
  NS_SCRIPTABLE NS_IMETHOD EncryptString(const char *text, char **_retval NS_OUTPARAM) = 0;

  /**
   * Decrypt BASE64 input to nul-terminated string output.  There is
   * no check for embedded nul values in the decrypted output.
   */
  /* string decryptString (in string crypt); */
  NS_SCRIPTABLE NS_IMETHOD DecryptString(const char *crypt, char **_retval NS_OUTPARAM) = 0;

  /**
   * Prompt the user to change the password on the SDR key.
   */
  /* void changePassword (); */
  NS_SCRIPTABLE NS_IMETHOD ChangePassword(void) = 0;

  /**
   * Logout of the security device that protects the SDR key.
   */
  /* void logout (); */
  NS_SCRIPTABLE NS_IMETHOD Logout(void) = 0;

  /**
   * Logout of the security device that protects the SDR key and tear
   * down authenticated objects.
   */
  /* void logoutAndTeardown (); */
  NS_SCRIPTABLE NS_IMETHOD LogoutAndTeardown(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecretDecoderRing, NS_ISECRETDECODERRING_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECRETDECODERRING \
  NS_IMETHOD Encrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM); \
  NS_IMETHOD Decrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EncryptString(const char *text, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DecryptString(const char *crypt, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ChangePassword(void); \
  NS_SCRIPTABLE NS_IMETHOD Logout(void); \
  NS_SCRIPTABLE NS_IMETHOD LogoutAndTeardown(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECRETDECODERRING(_to) \
  NS_IMETHOD Encrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM) { return _to Encrypt(data, dataLen, result, _retval); } \
  NS_IMETHOD Decrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM) { return _to Decrypt(data, dataLen, result, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EncryptString(const char *text, char **_retval NS_OUTPARAM) { return _to EncryptString(text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DecryptString(const char *crypt, char **_retval NS_OUTPARAM) { return _to DecryptString(crypt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ChangePassword(void) { return _to ChangePassword(); } \
  NS_SCRIPTABLE NS_IMETHOD Logout(void) { return _to Logout(); } \
  NS_SCRIPTABLE NS_IMETHOD LogoutAndTeardown(void) { return _to LogoutAndTeardown(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECRETDECODERRING(_to) \
  NS_IMETHOD Encrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Encrypt(data, dataLen, result, _retval); } \
  NS_IMETHOD Decrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Decrypt(data, dataLen, result, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EncryptString(const char *text, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncryptString(text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DecryptString(const char *crypt, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecryptString(crypt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ChangePassword(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChangePassword(); } \
  NS_SCRIPTABLE NS_IMETHOD Logout(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Logout(); } \
  NS_SCRIPTABLE NS_IMETHOD LogoutAndTeardown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogoutAndTeardown(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecretDecoderRing : public nsISecretDecoderRing
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECRETDECODERRING

  nsSecretDecoderRing();

private:
  ~nsSecretDecoderRing();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSecretDecoderRing, nsISecretDecoderRing)

nsSecretDecoderRing::nsSecretDecoderRing()
{
  /* member initializers and constructor code */
}

nsSecretDecoderRing::~nsSecretDecoderRing()
{
  /* destructor code */
}

/* [noscript] long encrypt (in buffer data, in long dataLen, out buffer result); */
NS_IMETHODIMP nsSecretDecoderRing::Encrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long decrypt (in buffer data, in long dataLen, out buffer result); */
NS_IMETHODIMP nsSecretDecoderRing::Decrypt(unsigned char * data, PRInt32 dataLen, unsigned char * *result NS_OUTPARAM, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string encryptString (in string text); */
NS_IMETHODIMP nsSecretDecoderRing::EncryptString(const char *text, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string decryptString (in string crypt); */
NS_IMETHODIMP nsSecretDecoderRing::DecryptString(const char *crypt, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void changePassword (); */
NS_IMETHODIMP nsSecretDecoderRing::ChangePassword()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logout (); */
NS_IMETHODIMP nsSecretDecoderRing::Logout()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logoutAndTeardown (); */
NS_IMETHODIMP nsSecretDecoderRing::LogoutAndTeardown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISecretDecoderRingConfig */
#define NS_ISECRETDECODERRINGCONFIG_IID_STR "01d8c0f0-0ccc-11d4-9fdd-000064657374"

#define NS_ISECRETDECODERRINGCONFIG_IID \
  {0x01d8c0f0, 0x0ccc, 0x11d4, \
    { 0x9f, 0xdd, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

/**
 * Configuration interface for the Secret Decoder Ring
 *  - this interface allows setting the window that will be
 *    used as parent for dialog windows (such as password prompts)
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISecretDecoderRingConfig : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECRETDECODERRINGCONFIG_IID)

  /* void setWindow (in nsISupports w); */
  NS_SCRIPTABLE NS_IMETHOD SetWindow(nsISupports *w) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecretDecoderRingConfig, NS_ISECRETDECODERRINGCONFIG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECRETDECODERRINGCONFIG \
  NS_SCRIPTABLE NS_IMETHOD SetWindow(nsISupports *w); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECRETDECODERRINGCONFIG(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetWindow(nsISupports *w) { return _to SetWindow(w); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECRETDECODERRINGCONFIG(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetWindow(nsISupports *w) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindow(w); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecretDecoderRingConfig : public nsISecretDecoderRingConfig
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECRETDECODERRINGCONFIG

  nsSecretDecoderRingConfig();

private:
  ~nsSecretDecoderRingConfig();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSecretDecoderRingConfig, nsISecretDecoderRingConfig)

nsSecretDecoderRingConfig::nsSecretDecoderRingConfig()
{
  /* member initializers and constructor code */
}

nsSecretDecoderRingConfig::~nsSecretDecoderRingConfig()
{
  /* destructor code */
}

/* void setWindow (in nsISupports w); */
NS_IMETHODIMP nsSecretDecoderRingConfig::SetWindow(nsISupports *w)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISecretDecoderRing_h__ */
