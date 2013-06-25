/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsICMSSecureMessage.idl
 */

#ifndef __gen_nsICMSSecureMessage_h__
#define __gen_nsICMSSecureMessage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */


/* starting interface:    nsICMSSecureMessage */
#define NS_ICMSSECUREMESSAGE_IID_STR "14b4394a-1dd2-11b2-b4fd-ba4a194fe97e"

#define NS_ICMSSECUREMESSAGE_IID \
  {0x14b4394a, 0x1dd2, 0x11b2, \
    { 0xb4, 0xfd, 0xba, 0x4a, 0x19, 0x4f, 0xe9, 0x7e }}

/**
 * nsICMSManager (service)
 *  Interface to access users certificate store
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICMSSecureMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICMSSECUREMESSAGE_IID)

  /**
   * getCertByPrefID - a BASE64 string representing a user's
   *   certificate (or NULL if there isn't one)
   */
  /* string getCertByPrefID (in string certID); */
  NS_SCRIPTABLE NS_IMETHOD GetCertByPrefID(const char *certID, char **_retval NS_OUTPARAM) = 0;

  /**
   * decodeCert - decode a BASE64 string into an X509Certificate object
   */
  /* nsIX509Cert decodeCert (in string value); */
  NS_SCRIPTABLE NS_IMETHOD DecodeCert(const char *value, nsIX509Cert **_retval NS_OUTPARAM) = 0;

  /**
   * sendMessage - send a text message to the recipient indicated
   *   by the base64-encoded cert.
   */
  /* string sendMessage (in string msg, in string cert); */
  NS_SCRIPTABLE NS_IMETHOD SendMessage(const char *msg, const char *cert, char **_retval NS_OUTPARAM) = 0;

  /**
   * receiveMessage - recieve an encrypted (enveloped) message
   */
  /* string receiveMessage (in string msg); */
  NS_SCRIPTABLE NS_IMETHOD ReceiveMessage(const char *msg, char **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICMSSecureMessage, NS_ICMSSECUREMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICMSSECUREMESSAGE \
  NS_SCRIPTABLE NS_IMETHOD GetCertByPrefID(const char *certID, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DecodeCert(const char *value, nsIX509Cert **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SendMessage(const char *msg, const char *cert, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReceiveMessage(const char *msg, char **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICMSSECUREMESSAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCertByPrefID(const char *certID, char **_retval NS_OUTPARAM) { return _to GetCertByPrefID(certID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DecodeCert(const char *value, nsIX509Cert **_retval NS_OUTPARAM) { return _to DecodeCert(value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendMessage(const char *msg, const char *cert, char **_retval NS_OUTPARAM) { return _to SendMessage(msg, cert, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReceiveMessage(const char *msg, char **_retval NS_OUTPARAM) { return _to ReceiveMessage(msg, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICMSSECUREMESSAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCertByPrefID(const char *certID, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertByPrefID(certID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DecodeCert(const char *value, nsIX509Cert **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeCert(value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendMessage(const char *msg, const char *cert, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMessage(msg, cert, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReceiveMessage(const char *msg, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReceiveMessage(msg, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCMSSecureMessage : public nsICMSSecureMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICMSSECUREMESSAGE

  nsCMSSecureMessage();

private:
  ~nsCMSSecureMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCMSSecureMessage, nsICMSSecureMessage)

nsCMSSecureMessage::nsCMSSecureMessage()
{
  /* member initializers and constructor code */
}

nsCMSSecureMessage::~nsCMSSecureMessage()
{
  /* destructor code */
}

/* string getCertByPrefID (in string certID); */
NS_IMETHODIMP nsCMSSecureMessage::GetCertByPrefID(const char *certID, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert decodeCert (in string value); */
NS_IMETHODIMP nsCMSSecureMessage::DecodeCert(const char *value, nsIX509Cert **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string sendMessage (in string msg, in string cert); */
NS_IMETHODIMP nsCMSSecureMessage::SendMessage(const char *msg, const char *cert, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string receiveMessage (in string msg); */
NS_IMETHODIMP nsCMSSecureMessage::ReceiveMessage(const char *msg, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CMSSECUREMESSAGE_CONTRACTID "@mozilla.org/nsCMSSecureMessage;1"

#endif /* __gen_nsICMSSecureMessage_h__ */
