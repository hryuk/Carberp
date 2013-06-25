/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsICMSMessage.idl
 */

#ifndef __gen_nsICMSMessage_h__
#define __gen_nsICMSMessage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_CMSMESSAGE_CONTRACTID "@mozilla.org/nsCMSMessage;1"
class nsIX509Cert; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsICMSMessage */
#define NS_ICMSMESSAGE_IID_STR "a4557478-ae16-11d5-ba4b-00108303b117"

#define NS_ICMSMESSAGE_IID \
  {0xa4557478, 0xae16, 0x11d5, \
    { 0xba, 0x4b, 0x00, 0x10, 0x83, 0x03, 0xb1, 0x17 }}

/**
 * nsICMSMessage
 *  Interface to a CMS Message
 */
class NS_NO_VTABLE nsICMSMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICMSMESSAGE_IID)

  /* void contentIsSigned (out boolean aSigned); */
  NS_IMETHOD ContentIsSigned(PRBool *aSigned NS_OUTPARAM) = 0;

  /* void contentIsEncrypted (out boolean aEncrypted); */
  NS_IMETHOD ContentIsEncrypted(PRBool *aEncrypted NS_OUTPARAM) = 0;

  /* void getSignerCommonName (out string aName); */
  NS_IMETHOD GetSignerCommonName(char **aName NS_OUTPARAM) = 0;

  /* void getSignerEmailAddress (out string aEmail); */
  NS_IMETHOD GetSignerEmailAddress(char **aEmail NS_OUTPARAM) = 0;

  /* void getSignerCert (out nsIX509Cert scert); */
  NS_IMETHOD GetSignerCert(nsIX509Cert **scert NS_OUTPARAM) = 0;

  /* void getEncryptionCert (out nsIX509Cert ecert); */
  NS_IMETHOD GetEncryptionCert(nsIX509Cert **ecert NS_OUTPARAM) = 0;

  /* void verifySignature (); */
  NS_IMETHOD VerifySignature(void) = 0;

  /* void verifyDetachedSignature (in UnsignedCharPtr aDigestData, in unsigned long aDigestDataLen); */
  NS_IMETHOD VerifyDetachedSignature(unsigned char * aDigestData, PRUint32 aDigestDataLen) = 0;

  /* void CreateEncrypted (in nsIArray aRecipientCerts); */
  NS_IMETHOD CreateEncrypted(nsIArray *aRecipientCerts) = 0;

  /* void CreateSigned (in nsIX509Cert scert, in nsIX509Cert ecert, in UnsignedCharPtr aDigestData, in unsigned long aDigestDataLen); */
  NS_IMETHOD CreateSigned(nsIX509Cert *scert, nsIX509Cert *ecert, unsigned char * aDigestData, PRUint32 aDigestDataLen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICMSMessage, NS_ICMSMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICMSMESSAGE \
  NS_IMETHOD ContentIsSigned(PRBool *aSigned NS_OUTPARAM); \
  NS_IMETHOD ContentIsEncrypted(PRBool *aEncrypted NS_OUTPARAM); \
  NS_IMETHOD GetSignerCommonName(char **aName NS_OUTPARAM); \
  NS_IMETHOD GetSignerEmailAddress(char **aEmail NS_OUTPARAM); \
  NS_IMETHOD GetSignerCert(nsIX509Cert **scert NS_OUTPARAM); \
  NS_IMETHOD GetEncryptionCert(nsIX509Cert **ecert NS_OUTPARAM); \
  NS_IMETHOD VerifySignature(void); \
  NS_IMETHOD VerifyDetachedSignature(unsigned char * aDigestData, PRUint32 aDigestDataLen); \
  NS_IMETHOD CreateEncrypted(nsIArray *aRecipientCerts); \
  NS_IMETHOD CreateSigned(nsIX509Cert *scert, nsIX509Cert *ecert, unsigned char * aDigestData, PRUint32 aDigestDataLen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICMSMESSAGE(_to) \
  NS_IMETHOD ContentIsSigned(PRBool *aSigned NS_OUTPARAM) { return _to ContentIsSigned(aSigned); } \
  NS_IMETHOD ContentIsEncrypted(PRBool *aEncrypted NS_OUTPARAM) { return _to ContentIsEncrypted(aEncrypted); } \
  NS_IMETHOD GetSignerCommonName(char **aName NS_OUTPARAM) { return _to GetSignerCommonName(aName); } \
  NS_IMETHOD GetSignerEmailAddress(char **aEmail NS_OUTPARAM) { return _to GetSignerEmailAddress(aEmail); } \
  NS_IMETHOD GetSignerCert(nsIX509Cert **scert NS_OUTPARAM) { return _to GetSignerCert(scert); } \
  NS_IMETHOD GetEncryptionCert(nsIX509Cert **ecert NS_OUTPARAM) { return _to GetEncryptionCert(ecert); } \
  NS_IMETHOD VerifySignature(void) { return _to VerifySignature(); } \
  NS_IMETHOD VerifyDetachedSignature(unsigned char * aDigestData, PRUint32 aDigestDataLen) { return _to VerifyDetachedSignature(aDigestData, aDigestDataLen); } \
  NS_IMETHOD CreateEncrypted(nsIArray *aRecipientCerts) { return _to CreateEncrypted(aRecipientCerts); } \
  NS_IMETHOD CreateSigned(nsIX509Cert *scert, nsIX509Cert *ecert, unsigned char * aDigestData, PRUint32 aDigestDataLen) { return _to CreateSigned(scert, ecert, aDigestData, aDigestDataLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICMSMESSAGE(_to) \
  NS_IMETHOD ContentIsSigned(PRBool *aSigned NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContentIsSigned(aSigned); } \
  NS_IMETHOD ContentIsEncrypted(PRBool *aEncrypted NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContentIsEncrypted(aEncrypted); } \
  NS_IMETHOD GetSignerCommonName(char **aName NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSignerCommonName(aName); } \
  NS_IMETHOD GetSignerEmailAddress(char **aEmail NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSignerEmailAddress(aEmail); } \
  NS_IMETHOD GetSignerCert(nsIX509Cert **scert NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSignerCert(scert); } \
  NS_IMETHOD GetEncryptionCert(nsIX509Cert **ecert NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncryptionCert(ecert); } \
  NS_IMETHOD VerifySignature(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifySignature(); } \
  NS_IMETHOD VerifyDetachedSignature(unsigned char * aDigestData, PRUint32 aDigestDataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifyDetachedSignature(aDigestData, aDigestDataLen); } \
  NS_IMETHOD CreateEncrypted(nsIArray *aRecipientCerts) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateEncrypted(aRecipientCerts); } \
  NS_IMETHOD CreateSigned(nsIX509Cert *scert, nsIX509Cert *ecert, unsigned char * aDigestData, PRUint32 aDigestDataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSigned(scert, ecert, aDigestData, aDigestDataLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCMSMessage : public nsICMSMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICMSMESSAGE

  nsCMSMessage();

private:
  ~nsCMSMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCMSMessage, nsICMSMessage)

nsCMSMessage::nsCMSMessage()
{
  /* member initializers and constructor code */
}

nsCMSMessage::~nsCMSMessage()
{
  /* destructor code */
}

/* void contentIsSigned (out boolean aSigned); */
NS_IMETHODIMP nsCMSMessage::ContentIsSigned(PRBool *aSigned NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void contentIsEncrypted (out boolean aEncrypted); */
NS_IMETHODIMP nsCMSMessage::ContentIsEncrypted(PRBool *aEncrypted NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSignerCommonName (out string aName); */
NS_IMETHODIMP nsCMSMessage::GetSignerCommonName(char **aName NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSignerEmailAddress (out string aEmail); */
NS_IMETHODIMP nsCMSMessage::GetSignerEmailAddress(char **aEmail NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSignerCert (out nsIX509Cert scert); */
NS_IMETHODIMP nsCMSMessage::GetSignerCert(nsIX509Cert **scert NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getEncryptionCert (out nsIX509Cert ecert); */
NS_IMETHODIMP nsCMSMessage::GetEncryptionCert(nsIX509Cert **ecert NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void verifySignature (); */
NS_IMETHODIMP nsCMSMessage::VerifySignature()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void verifyDetachedSignature (in UnsignedCharPtr aDigestData, in unsigned long aDigestDataLen); */
NS_IMETHODIMP nsCMSMessage::VerifyDetachedSignature(unsigned char * aDigestData, PRUint32 aDigestDataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void CreateEncrypted (in nsIArray aRecipientCerts); */
NS_IMETHODIMP nsCMSMessage::CreateEncrypted(nsIArray *aRecipientCerts)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void CreateSigned (in nsIX509Cert scert, in nsIX509Cert ecert, in UnsignedCharPtr aDigestData, in unsigned long aDigestDataLen); */
NS_IMETHODIMP nsCMSMessage::CreateSigned(nsIX509Cert *scert, nsIX509Cert *ecert, unsigned char * aDigestData, PRUint32 aDigestDataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICMSMessage_h__ */
