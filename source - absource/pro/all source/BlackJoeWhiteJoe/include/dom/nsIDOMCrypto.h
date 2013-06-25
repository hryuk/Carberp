/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMCrypto.idl
 */

#ifndef __gen_nsIDOMCrypto_h__
#define __gen_nsIDOMCrypto_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCrypto */
#define NS_IDOMCRYPTO_IID_STR "12b6d899-2aed-4ea9-8c02-2223ab7ab592"

#define NS_IDOMCRYPTO_IID \
  {0x12b6d899, 0x2aed, 0x4ea9, \
    { 0x8c, 0x02, 0x22, 0x23, 0xab, 0x7a, 0xb5, 0x92 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCrypto : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCRYPTO_IID)

  /* readonly attribute DOMString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /* attribute boolean enableSmartCardEvents; */
  NS_SCRIPTABLE NS_IMETHOD GetEnableSmartCardEvents(PRBool *aEnableSmartCardEvents) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEnableSmartCardEvents(PRBool aEnableSmartCardEvents) = 0;

  /* nsIDOMCRMFObject generateCRMFRequest (); */
  NS_SCRIPTABLE NS_IMETHOD GenerateCRMFRequest(nsIDOMCRMFObject **_retval NS_OUTPARAM) = 0;

  /* DOMString importUserCertificates (in DOMString nickname, in DOMString cmmfResponse, in boolean doForcedBackup); */
  NS_SCRIPTABLE NS_IMETHOD ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, PRBool doForcedBackup, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString popChallengeResponse (in DOMString challenge); */
  NS_SCRIPTABLE NS_IMETHOD PopChallengeResponse(const nsAString & challenge, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString random (in long numBytes); */
  NS_SCRIPTABLE NS_IMETHOD Random(PRInt32 numBytes, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString signText (in DOMString stringToSign, in DOMString caOption); */
  NS_SCRIPTABLE NS_IMETHOD SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval NS_OUTPARAM) = 0;

  /* void logout (); */
  NS_SCRIPTABLE NS_IMETHOD Logout(void) = 0;

  /* void disableRightClick (); */
  NS_SCRIPTABLE NS_IMETHOD DisableRightClick(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCrypto, NS_IDOMCRYPTO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCRYPTO \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetEnableSmartCardEvents(PRBool *aEnableSmartCardEvents); \
  NS_SCRIPTABLE NS_IMETHOD SetEnableSmartCardEvents(PRBool aEnableSmartCardEvents); \
  NS_SCRIPTABLE NS_IMETHOD GenerateCRMFRequest(nsIDOMCRMFObject **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, PRBool doForcedBackup, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PopChallengeResponse(const nsAString & challenge, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Random(PRInt32 numBytes, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Logout(void); \
  NS_SCRIPTABLE NS_IMETHOD DisableRightClick(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCRYPTO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnableSmartCardEvents(PRBool *aEnableSmartCardEvents) { return _to GetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnableSmartCardEvents(PRBool aEnableSmartCardEvents) { return _to SetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_SCRIPTABLE NS_IMETHOD GenerateCRMFRequest(nsIDOMCRMFObject **_retval NS_OUTPARAM) { return _to GenerateCRMFRequest(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, PRBool doForcedBackup, nsAString & _retval NS_OUTPARAM) { return _to ImportUserCertificates(nickname, cmmfResponse, doForcedBackup, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD PopChallengeResponse(const nsAString & challenge, nsAString & _retval NS_OUTPARAM) { return _to PopChallengeResponse(challenge, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Random(PRInt32 numBytes, nsAString & _retval NS_OUTPARAM) { return _to Random(numBytes, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval NS_OUTPARAM) { return _to SignText(stringToSign, caOption, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Logout(void) { return _to Logout(); } \
  NS_SCRIPTABLE NS_IMETHOD DisableRightClick(void) { return _to DisableRightClick(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCRYPTO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnableSmartCardEvents(PRBool *aEnableSmartCardEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnableSmartCardEvents(PRBool aEnableSmartCardEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_SCRIPTABLE NS_IMETHOD GenerateCRMFRequest(nsIDOMCRMFObject **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateCRMFRequest(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, PRBool doForcedBackup, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportUserCertificates(nickname, cmmfResponse, doForcedBackup, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD PopChallengeResponse(const nsAString & challenge, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PopChallengeResponse(challenge, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Random(PRInt32 numBytes, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Random(numBytes, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SignText(stringToSign, caOption, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Logout(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Logout(); } \
  NS_SCRIPTABLE NS_IMETHOD DisableRightClick(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableRightClick(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCrypto : public nsIDOMCrypto
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCRYPTO

  nsDOMCrypto();

private:
  ~nsDOMCrypto();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCrypto, nsIDOMCrypto)

nsDOMCrypto::nsDOMCrypto()
{
  /* member initializers and constructor code */
}

nsDOMCrypto::~nsDOMCrypto()
{
  /* destructor code */
}

/* readonly attribute DOMString version; */
NS_IMETHODIMP nsDOMCrypto::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean enableSmartCardEvents; */
NS_IMETHODIMP nsDOMCrypto::GetEnableSmartCardEvents(PRBool *aEnableSmartCardEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCrypto::SetEnableSmartCardEvents(PRBool aEnableSmartCardEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCRMFObject generateCRMFRequest (); */
NS_IMETHODIMP nsDOMCrypto::GenerateCRMFRequest(nsIDOMCRMFObject **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString importUserCertificates (in DOMString nickname, in DOMString cmmfResponse, in boolean doForcedBackup); */
NS_IMETHODIMP nsDOMCrypto::ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, PRBool doForcedBackup, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString popChallengeResponse (in DOMString challenge); */
NS_IMETHODIMP nsDOMCrypto::PopChallengeResponse(const nsAString & challenge, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString random (in long numBytes); */
NS_IMETHODIMP nsDOMCrypto::Random(PRInt32 numBytes, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString signText (in DOMString stringToSign, in DOMString caOption); */
NS_IMETHODIMP nsDOMCrypto::SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logout (); */
NS_IMETHODIMP nsDOMCrypto::Logout()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableRightClick (); */
NS_IMETHODIMP nsDOMCrypto::DisableRightClick()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCrypto_h__ */
