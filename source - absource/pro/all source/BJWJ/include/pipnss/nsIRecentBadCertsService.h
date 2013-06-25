/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIRecentBadCertsService.idl
 */

#ifndef __gen_nsIRecentBadCertsService_h__
#define __gen_nsIRecentBadCertsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIX509Cert; /* forward declaration */

class nsISSLStatus; /* forward declaration */

#define NS_RECENTBADCERTS_CONTRACTID "@mozilla.org/security/recentbadcerts;1"

/* starting interface:    nsIRecentBadCertsService */
#define NS_IRECENTBADCERTSSERVICE_IID_STR "a5ae8b05-a76e-408f-b0ba-02a831265749"

#define NS_IRECENTBADCERTSSERVICE_IID \
  {0xa5ae8b05, 0xa76e, 0x408f, \
    { 0xb0, 0xba, 0x02, 0xa8, 0x31, 0x26, 0x57, 0x49 }}

/**
 * This represents a global list of recently seen bad ssl status
 * including the bad cert.
 * The implementation will decide how many entries it will hold,
 * the number is expected to be small.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRecentBadCertsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRECENTBADCERTSSERVICE_IID)

  /**
   *  Retrieve the recently seen bad ssl status for the given hostname:port.
   *  If no SSL cert was recently seen for the given hostname:port, return null.
   *  If a good cert was seen for the given hostname:port, return null.
   *
   *  @param aHostNameWithPort The host:port whose entry should be tested
   *  @return null or a recently seen bad ssl status with cert
   */
  /* nsISSLStatus getRecentBadCert (in AString aHostNameWithPort); */
  NS_SCRIPTABLE NS_IMETHOD GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus **_retval NS_OUTPARAM) = 0;

  /**
   *  A bad certificate that should be remembered by the service.
   *  Will be added as the most recently seen cert.
   *  The service may forget older entries to make room for the new one.
   *
   *  @param aHostNameWithPort The host:port whose entry should be tested
   *  @param aCert The bad ssl status with certificate
   */
  /* void addBadCert (in AString aHostNameWithPort, in nsISSLStatus aStatus); */
  NS_SCRIPTABLE NS_IMETHOD AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRecentBadCertsService, NS_IRECENTBADCERTSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRECENTBADCERTSSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRECENTBADCERTSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus **_retval NS_OUTPARAM) { return _to GetRecentBadCert(aHostNameWithPort, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus) { return _to AddBadCert(aHostNameWithPort, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRECENTBADCERTSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRecentBadCert(aHostNameWithPort, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddBadCert(aHostNameWithPort, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRecentBadCertsService : public nsIRecentBadCertsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRECENTBADCERTSSERVICE

  nsRecentBadCertsService();

private:
  ~nsRecentBadCertsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRecentBadCertsService, nsIRecentBadCertsService)

nsRecentBadCertsService::nsRecentBadCertsService()
{
  /* member initializers and constructor code */
}

nsRecentBadCertsService::~nsRecentBadCertsService()
{
  /* destructor code */
}

/* nsISSLStatus getRecentBadCert (in AString aHostNameWithPort); */
NS_IMETHODIMP nsRecentBadCertsService::GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addBadCert (in AString aHostNameWithPort, in nsISSLStatus aStatus); */
NS_IMETHODIMP nsRecentBadCertsService::AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRecentBadCertsService_h__ */
