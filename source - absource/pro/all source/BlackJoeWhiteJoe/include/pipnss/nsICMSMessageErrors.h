/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsICMSMessageErrors.idl
 */

#ifndef __gen_nsICMSMessageErrors_h__
#define __gen_nsICMSMessageErrors_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICMSMessageErrors */
#define NS_ICMSMESSAGEERRORS_IID_STR "f2aec680-60a0-49f0-afe5-6cf1d3f15e0d"

#define NS_ICMSMESSAGEERRORS_IID \
  {0xf2aec680, 0x60a0, 0x49f0, \
    { 0xaf, 0xe5, 0x6c, 0xf1, 0xd3, 0xf1, 0x5e, 0x0d }}

/**
 * nsICMSMessageErrors
 *  Scriptable error constants for nsICMSMessage
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICMSMessageErrors : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICMSMESSAGEERRORS_IID)

  enum { SUCCESS = 0 };

  enum { GENERAL_ERROR = 1 };

  enum { VERIFY_NOT_SIGNED = 1024 };

  enum { VERIFY_NO_CONTENT_INFO = 1025 };

  enum { VERIFY_BAD_DIGEST = 1026 };

  enum { VERIFY_NOCERT = 1028 };

  enum { VERIFY_UNTRUSTED = 1029 };

  enum { VERIFY_ERROR_UNVERIFIED = 1031 };

  enum { VERIFY_ERROR_PROCESSING = 1032 };

  enum { VERIFY_BAD_SIGNATURE = 1033 };

  enum { VERIFY_DIGEST_MISMATCH = 1034 };

  enum { VERIFY_UNKNOWN_ALGO = 1035 };

  enum { VERIFY_UNSUPPORTED_ALGO = 1036 };

  enum { VERIFY_MALFORMED_SIGNATURE = 1037 };

  enum { VERIFY_HEADER_MISMATCH = 1038 };

  enum { VERIFY_NOT_YET_ATTEMPTED = 1039 };

  enum { VERIFY_CERT_WITHOUT_ADDRESS = 1040 };

  enum { ENCRYPT_NO_BULK_ALG = 1056 };

  enum { ENCRYPT_INCOMPLETE = 1057 };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICMSMessageErrors, NS_ICMSMESSAGEERRORS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICMSMESSAGEERRORS \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICMSMESSAGEERRORS(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICMSMESSAGEERRORS(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCMSMessageErrors : public nsICMSMessageErrors
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICMSMESSAGEERRORS

  nsCMSMessageErrors();

private:
  ~nsCMSMessageErrors();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCMSMessageErrors, nsICMSMessageErrors)

nsCMSMessageErrors::nsCMSMessageErrors()
{
  /* member initializers and constructor code */
}

nsCMSMessageErrors::~nsCMSMessageErrors()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif

/**
 * CMS specific nsresult error codes
 */
#define NS_ERROR_CMS_VERIFY_NOT_SIGNED \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_NOT_SIGNED)
#define NS_ERROR_CMS_VERIFY_NO_CONTENT_INFO \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_NO_CONTENT_INFO)
#define NS_ERROR_CMS_VERIFY_BAD_DIGEST \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_BAD_DIGEST)
#define NS_ERROR_CMS_VERIFY_NOCERT \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_NOCERT)
#define NS_ERROR_CMS_VERIFY_UNTRUSTED \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_UNTRUSTED)
#define NS_ERROR_CMS_VERIFY_ERROR_UNVERIFIED \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_ERROR_UNVERIFIED)
#define NS_ERROR_CMS_VERIFY_ERROR_PROCESSING \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_ERROR_PROCESSING)
#define NS_ERROR_CMS_VERIFY_BAD_SIGNATURE \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_BAD_SIGNATURE)
#define NS_ERROR_CMS_VERIFY_DIGEST_MISMATCH \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_DIGEST_MISMATCH)
#define NS_ERROR_CMS_VERIFY_UNKNOWN_ALGO \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_UNKNOWN_ALGO)
#define NS_ERROR_CMS_VERIFY_UNSUPPORTED_ALGO \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_UNSUPPORTED_ALGO)
#define NS_ERROR_CMS_VERIFY_MALFORMED_SIGNATURE \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_MALFORMED_SIGNATURE)
#define NS_ERROR_CMS_VERIFY_HEADER_MISMATCH \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_HEADER_MISMATCH)
#define NS_ERROR_CMS_VERIFY_NOT_YET_ATTEMPTED \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_NOT_YET_ATTEMPTED)
#define NS_ERROR_CMS_VERIFY_CERT_WITHOUT_ADDRESS \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::VERIFY_CERT_WITHOUT_ADDRESS)
#define NS_ERROR_CMS_ENCRYPT_NO_BULK_ALG \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::ENCRYPT_NO_BULK_ALG)
#define NS_ERROR_CMS_ENCRYPT_INCOMPLETE \
  NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_SECURITY, \
                            nsICMSMessageErrors::ENCRYPT_INCOMPLETE)

#endif /* __gen_nsICMSMessageErrors_h__ */
