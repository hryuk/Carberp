/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIX509Cert2.idl
 */

#ifndef __gen_nsIX509Cert2_h__
#define __gen_nsIX509Cert2_h__


#ifndef __gen_nsIX509Cert_h__
#include "nsIX509Cert.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIASN1Object; /* forward declaration */

 /* forward declaration */
 typedef struct CERTCertificateStr CERTCertificate;

/* starting interface:    nsIX509Cert2 */
#define NS_IX509CERT2_IID_STR "5b62c61c-f898-4dab-8ace-51109bb459b4"

#define NS_IX509CERT2_IID \
  {0x5b62c61c, 0xf898, 0x4dab, \
    { 0x8a, 0xce, 0x51, 0x10, 0x9b, 0xb4, 0x59, 0xb4 }}

/**
 * This represents additional interfaces to X.509 certificates
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIX509Cert2 : public nsIX509Cert {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERT2_IID)

  /**
   *  Additional constants to classify the type of a certificate.
   */
  enum { ANY_CERT = 65535U };

  /* readonly attribute unsigned long certType; */
  NS_SCRIPTABLE NS_IMETHOD GetCertType(PRUint32 *aCertType) = 0;

  /* void markForPermDeletion (); */
  NS_SCRIPTABLE NS_IMETHOD MarkForPermDeletion(void) = 0;

  /* [noscript, notxpcom] CERTCertificatePtr getCert (); */
  NS_IMETHOD_(CERTCertificate *) GetCert(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509Cert2, NS_IX509CERT2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERT2 \
  NS_SCRIPTABLE NS_IMETHOD GetCertType(PRUint32 *aCertType); \
  NS_SCRIPTABLE NS_IMETHOD MarkForPermDeletion(void); \
  NS_IMETHOD_(CERTCertificate *) GetCert(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERT2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCertType(PRUint32 *aCertType) { return _to GetCertType(aCertType); } \
  NS_SCRIPTABLE NS_IMETHOD MarkForPermDeletion(void) { return _to MarkForPermDeletion(); } \
  NS_IMETHOD_(CERTCertificate *) GetCert(void) { return _to GetCert(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERT2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCertType(PRUint32 *aCertType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertType(aCertType); } \
  NS_SCRIPTABLE NS_IMETHOD MarkForPermDeletion(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkForPermDeletion(); } \
  NS_IMETHOD_(CERTCertificate *) GetCert(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCert(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509Cert2 : public nsIX509Cert2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERT2

  nsX509Cert2();

private:
  ~nsX509Cert2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsX509Cert2, nsIX509Cert2)

nsX509Cert2::nsX509Cert2()
{
  /* member initializers and constructor code */
}

nsX509Cert2::~nsX509Cert2()
{
  /* destructor code */
}

/* readonly attribute unsigned long certType; */
NS_IMETHODIMP nsX509Cert2::GetCertType(PRUint32 *aCertType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markForPermDeletion (); */
NS_IMETHODIMP nsX509Cert2::MarkForPermDeletion()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] CERTCertificatePtr getCert (); */
NS_IMETHODIMP_(CERTCertificate *) nsX509Cert2::GetCert()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIX509Cert2_h__ */
