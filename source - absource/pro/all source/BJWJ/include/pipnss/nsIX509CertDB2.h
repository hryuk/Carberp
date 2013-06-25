/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIX509CertDB2.idl
 */

#ifndef __gen_nsIX509CertDB2_h__
#define __gen_nsIX509CertDB2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509CertList; /* forward declaration */


/* starting interface:    nsIX509CertDB2 */
#define NS_IX509CERTDB2_IID_STR "e0df4784-6560-45bf-b1b7-86076a0e8381"

#define NS_IX509CERTDB2_IID \
  {0xe0df4784, 0x6560, 0x45bf, \
    { 0xb1, 0xb7, 0x86, 0x07, 0x6a, 0x0e, 0x83, 0x81 }}

/**
 * This represents a service to access and manipulate 
 * X.509 certificates stored in a database through methods
 * not in nsIX509CertDB, which is frozen
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIX509CertDB2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERTDB2_IID)

  /* void addCertFromBase64 (in string base64, in string aTrust, in string aName); */
  NS_SCRIPTABLE NS_IMETHOD AddCertFromBase64(const char *base64, const char *aTrust, const char *aName) = 0;

  /* nsIX509CertList getCerts (); */
  NS_SCRIPTABLE NS_IMETHOD GetCerts(nsIX509CertList **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509CertDB2, NS_IX509CERTDB2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERTDB2 \
  NS_SCRIPTABLE NS_IMETHOD AddCertFromBase64(const char *base64, const char *aTrust, const char *aName); \
  NS_SCRIPTABLE NS_IMETHOD GetCerts(nsIX509CertList **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERTDB2(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddCertFromBase64(const char *base64, const char *aTrust, const char *aName) { return _to AddCertFromBase64(base64, aTrust, aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetCerts(nsIX509CertList **_retval NS_OUTPARAM) { return _to GetCerts(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERTDB2(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddCertFromBase64(const char *base64, const char *aTrust, const char *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCertFromBase64(base64, aTrust, aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetCerts(nsIX509CertList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCerts(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509CertDB2 : public nsIX509CertDB2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERTDB2

  nsX509CertDB2();

private:
  ~nsX509CertDB2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsX509CertDB2, nsIX509CertDB2)

nsX509CertDB2::nsX509CertDB2()
{
  /* member initializers and constructor code */
}

nsX509CertDB2::~nsX509CertDB2()
{
  /* destructor code */
}

/* void addCertFromBase64 (in string base64, in string aTrust, in string aName); */
NS_IMETHODIMP nsX509CertDB2::AddCertFromBase64(const char *base64, const char *aTrust, const char *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509CertList getCerts (); */
NS_IMETHODIMP nsX509CertDB2::GetCerts(nsIX509CertList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIX509CertDB2_h__ */
