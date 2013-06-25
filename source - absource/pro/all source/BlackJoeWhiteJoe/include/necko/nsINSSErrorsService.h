/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsINSSErrorsService.idl
 */

#ifndef __gen_nsINSSErrorsService_h__
#define __gen_nsINSSErrorsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINSSErrorsService */
#define NS_INSSERRORSSERVICE_IID_STR "3a5c7a0f-f5da-4a8b-a748-d7c5a528f33b"

#define NS_INSSERRORSSERVICE_IID \
  {0x3a5c7a0f, 0xf5da, 0x4a8b, \
    { 0xa7, 0x48, 0xd7, 0xc5, 0xa5, 0x28, 0xf3, 0x3b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINSSErrorsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INSSERRORSSERVICE_IID)

  /**
     *  @param aNSPRCode An error code obtained using PR_GetError()
     *  @return True if it is error code defined by the NSS library
     */
  /* boolean isNSSErrorCode (in PRInt32 aNSPRCode); */
  NS_SCRIPTABLE NS_IMETHOD IsNSSErrorCode(PRInt32 aNSPRCode, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     *  Function will fail if aNSPRCode is not an NSS error code.
     *  @param aNSPRCode An error code obtained using PR_GetError()
     *  @return The result of the conversion, an XPCOM error code
     */
  /* nsresult getXPCOMFromNSSError (in PRInt32 aNSPRCode); */
  NS_SCRIPTABLE NS_IMETHOD GetXPCOMFromNSSError(PRInt32 aNSPRCode, nsresult *_retval NS_OUTPARAM) = 0;

  /**
     *  Function will fail if aXPCOMErrorCode is not an NSS error code.
     *  @param aXPCOMErrorCode An error code obtain using getXPCOMFromNSSError
     *  return A localized human readable error explanation.
     */
  /* AString getErrorMessage (in nsresult aXPCOMErrorCode); */
  NS_SCRIPTABLE NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval NS_OUTPARAM) = 0;

  /**
     *  Function will fail if aXPCOMErrorCode is not an NSS error code.
     *  @param aXPCOMErrorCode An error code obtain using getXPCOMFromNSSError
     *  return the 
     */
  /* PRUint32 getErrorClass (in nsresult aXPCOMErrorCode); */
  NS_SCRIPTABLE NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, PRUint32 *_retval NS_OUTPARAM) = 0;

  enum { ERROR_CLASS_SSL_PROTOCOL = 1U };

  enum { ERROR_CLASS_BAD_CERT = 2U };

  /**
     *  The following values define the range of NSPR error codes used by NSS.
     *  NSS remains the authorative source for these numbers, as a result,
     *  the values might change in the future.
     *  The security module will perform a runtime check and assertion
     *  to ensure the values are in synch with NSS.
     */
  enum { NSS_SEC_ERROR_BASE = -8192 };

  enum { NSS_SEC_ERROR_LIMIT = -7192 };

  enum { NSS_SSL_ERROR_BASE = -12288 };

  enum { NSS_SSL_ERROR_LIMIT = -11288 };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINSSErrorsService, NS_INSSERRORSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINSSERRORSSERVICE \
  NS_SCRIPTABLE NS_IMETHOD IsNSSErrorCode(PRInt32 aNSPRCode, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetXPCOMFromNSSError(PRInt32 aNSPRCode, nsresult *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, PRUint32 *_retval NS_OUTPARAM); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINSSERRORSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsNSSErrorCode(PRInt32 aNSPRCode, PRBool *_retval NS_OUTPARAM) { return _to IsNSSErrorCode(aNSPRCode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetXPCOMFromNSSError(PRInt32 aNSPRCode, nsresult *_retval NS_OUTPARAM) { return _to GetXPCOMFromNSSError(aNSPRCode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval NS_OUTPARAM) { return _to GetErrorMessage(aXPCOMErrorCode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, PRUint32 *_retval NS_OUTPARAM) { return _to GetErrorClass(aXPCOMErrorCode, _retval); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINSSERRORSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsNSSErrorCode(PRInt32 aNSPRCode, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsNSSErrorCode(aNSPRCode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetXPCOMFromNSSError(PRInt32 aNSPRCode, nsresult *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXPCOMFromNSSError(aNSPRCode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorMessage(aXPCOMErrorCode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorClass(aXPCOMErrorCode, _retval); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNSSErrorsService : public nsINSSErrorsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINSSERRORSSERVICE

  nsNSSErrorsService();

private:
  ~nsNSSErrorsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNSSErrorsService, nsINSSErrorsService)

nsNSSErrorsService::nsNSSErrorsService()
{
  /* member initializers and constructor code */
}

nsNSSErrorsService::~nsNSSErrorsService()
{
  /* destructor code */
}

/* boolean isNSSErrorCode (in PRInt32 aNSPRCode); */
NS_IMETHODIMP nsNSSErrorsService::IsNSSErrorCode(PRInt32 aNSPRCode, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsresult getXPCOMFromNSSError (in PRInt32 aNSPRCode); */
NS_IMETHODIMP nsNSSErrorsService::GetXPCOMFromNSSError(PRInt32 aNSPRCode, nsresult *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getErrorMessage (in nsresult aXPCOMErrorCode); */
NS_IMETHODIMP nsNSSErrorsService::GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 getErrorClass (in nsresult aXPCOMErrorCode); */
NS_IMETHODIMP nsNSSErrorsService::GetErrorClass(nsresult aXPCOMErrorCode, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINSSErrorsService_h__ */
