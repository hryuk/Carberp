/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIX509CertList.idl
 */

#ifndef __gen_nsIX509CertList_h__
#define __gen_nsIX509CertList_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsIX509Cert; /* forward declaration */


/* starting interface:    nsIX509CertList */
#define NS_IX509CERTLIST_IID_STR "a539759b-e22d-462f-94ea-2915b11b33e8"

#define NS_IX509CERTLIST_IID \
  {0xa539759b, 0xe22d, 0x462f, \
    { 0x94, 0xea, 0x29, 0x15, 0xb1, 0x1b, 0x33, 0xe8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIX509CertList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERTLIST_IID)

  /* void addCert (in nsIX509Cert cert); */
  NS_SCRIPTABLE NS_IMETHOD AddCert(nsIX509Cert *cert) = 0;

  /* void deleteCert (in nsIX509Cert cert); */
  NS_SCRIPTABLE NS_IMETHOD DeleteCert(nsIX509Cert *cert) = 0;

  /* nsISimpleEnumerator getEnumerator (); */
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /* [noscript, notxpcom] voidPtr getRawCertList (); */
  NS_IMETHOD_(void *) GetRawCertList(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509CertList, NS_IX509CERTLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERTLIST \
  NS_SCRIPTABLE NS_IMETHOD AddCert(nsIX509Cert *cert); \
  NS_SCRIPTABLE NS_IMETHOD DeleteCert(nsIX509Cert *cert); \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_IMETHOD_(void *) GetRawCertList(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERTLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddCert(nsIX509Cert *cert) { return _to AddCert(cert); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteCert(nsIX509Cert *cert) { return _to DeleteCert(cert); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetEnumerator(_retval); } \
  NS_IMETHOD_(void *) GetRawCertList(void) { return _to GetRawCertList(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERTLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddCert(nsIX509Cert *cert) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCert(cert); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteCert(nsIX509Cert *cert) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteCert(cert); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(_retval); } \
  NS_IMETHOD_(void *) GetRawCertList(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRawCertList(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509CertList : public nsIX509CertList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERTLIST

  nsX509CertList();

private:
  ~nsX509CertList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsX509CertList, nsIX509CertList)

nsX509CertList::nsX509CertList()
{
  /* member initializers and constructor code */
}

nsX509CertList::~nsX509CertList()
{
  /* destructor code */
}

/* void addCert (in nsIX509Cert cert); */
NS_IMETHODIMP nsX509CertList::AddCert(nsIX509Cert *cert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteCert (in nsIX509Cert cert); */
NS_IMETHODIMP nsX509CertList::DeleteCert(nsIX509Cert *cert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getEnumerator (); */
NS_IMETHODIMP nsX509CertList::GetEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] voidPtr getRawCertList (); */
NS_IMETHODIMP_(void *) nsX509CertList::GetRawCertList()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_X509CERRTLIST_CID { /* 959fb165-6517-487f-ab9b-d8913be53197 */ \
    0x959fb165,                                                           \
    0x6517,                                                               \
    0x487f                                                                \
    {0xab, 0x9b, 0xd8, 0x91, 0x3b, 0xe5, 0x31, 0x97}                      \
  }
#define NS_X509CERTLIST_CONTRACTID "@mozilla.org/security/x509certlist;1"

#endif /* __gen_nsIX509CertList_h__ */
