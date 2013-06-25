/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIBadCertListener2.idl
 */

#ifndef __gen_nsIBadCertListener2_h__
#define __gen_nsIBadCertListener2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISSLStatus; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIBadCertListener2 */
#define NS_IBADCERTLISTENER2_IID_STR "2c3d268c-ad82-49f3-99aa-e9ffddd7a0dc"

#define NS_IBADCERTLISTENER2_IID \
  {0x2c3d268c, 0xad82, 0x49f3, \
    { 0x99, 0xaa, 0xe9, 0xff, 0xdd, 0xd7, 0xa0, 0xdc }}

/**
 * A mechanism to report a broken SSL status. The recipient should NOT block.
 * Can be used to obtain the SSL handshake status of a connection
 * that will be canceled because of improper cert status.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIBadCertListener2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBADCERTLISTENER2_IID)

  /**
   *  @param socketInfo A network communication context that can be used to obtain more information
   *                    about the active connection.
   *  @param status The SSL status object that describes the problem(s).
   *  @param targetSite The Site name that was used to open the current connection.
   *
   *  @return The consumer shall return true if it wants to suppress the error message
   *          related to the bad cert (the connection will still get canceled).
   */
  /* boolean notifyCertProblem (in nsIInterfaceRequestor socketInfo, in nsISSLStatus status, in AUTF8String targetSite); */
  NS_SCRIPTABLE NS_IMETHOD NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBadCertListener2, NS_IBADCERTLISTENER2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBADCERTLISTENER2 \
  NS_SCRIPTABLE NS_IMETHOD NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBADCERTLISTENER2(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM) { return _to NotifyCertProblem(socketInfo, status, targetSite, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBADCERTLISTENER2(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCertProblem(socketInfo, status, targetSite, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBadCertListener2 : public nsIBadCertListener2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBADCERTLISTENER2

  nsBadCertListener2();

private:
  ~nsBadCertListener2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBadCertListener2, nsIBadCertListener2)

nsBadCertListener2::nsBadCertListener2()
{
  /* member initializers and constructor code */
}

nsBadCertListener2::~nsBadCertListener2()
{
  /* destructor code */
}

/* boolean notifyCertProblem (in nsIInterfaceRequestor socketInfo, in nsISSLStatus status, in AUTF8String targetSite); */
NS_IMETHODIMP nsBadCertListener2::NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBadCertListener2_h__ */
