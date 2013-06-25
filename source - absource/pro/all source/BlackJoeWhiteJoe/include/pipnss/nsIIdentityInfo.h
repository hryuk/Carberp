/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIIdentityInfo.idl
 */

#ifndef __gen_nsIIdentityInfo_h__
#define __gen_nsIIdentityInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIdentityInfo */
#define NS_IIDENTITYINFO_IID_STR "e9da87b8-b87c-4bd1-a6bc-5a9a2c7f6d8d"

#define NS_IIDENTITYINFO_IID \
  {0xe9da87b8, 0xb87c, 0x4bd1, \
    { 0xa6, 0xbc, 0x5a, 0x9a, 0x2c, 0x7f, 0x6d, 0x8d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIdentityInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDENTITYINFO_IID)

  /**
   * A "true" value means:
   *   The object that implements this interface uses a certificate that
   *   was successfully verified as an Extended Validation (EV) cert.
   *   The test is bound to SSL Server Cert Usage.
   */
  /* readonly attribute boolean isExtendedValidation; */
  NS_SCRIPTABLE NS_IMETHOD GetIsExtendedValidation(PRBool *aIsExtendedValidation) = 0;

  /**
   * This function uses the same test as attribute
   *   isExtendedValidation
   *
   * If isExtendedValidation is true, this function will return
   * a policy identifier in dotted notation (like 1.2.3.4.5).
   *
   * If isExtendedValidation is false, this function will return
   * an empty (length string) value.
   */
  /* ACString getValidEVPolicyOid (); */
  NS_SCRIPTABLE NS_IMETHOD GetValidEVPolicyOid(nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIdentityInfo, NS_IIDENTITYINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDENTITYINFO \
  NS_SCRIPTABLE NS_IMETHOD GetIsExtendedValidation(PRBool *aIsExtendedValidation); \
  NS_SCRIPTABLE NS_IMETHOD GetValidEVPolicyOid(nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDENTITYINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsExtendedValidation(PRBool *aIsExtendedValidation) { return _to GetIsExtendedValidation(aIsExtendedValidation); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidEVPolicyOid(nsACString & _retval NS_OUTPARAM) { return _to GetValidEVPolicyOid(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDENTITYINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsExtendedValidation(PRBool *aIsExtendedValidation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExtendedValidation(aIsExtendedValidation); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidEVPolicyOid(nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidEVPolicyOid(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIdentityInfo : public nsIIdentityInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDENTITYINFO

  nsIdentityInfo();

private:
  ~nsIdentityInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIdentityInfo, nsIIdentityInfo)

nsIdentityInfo::nsIdentityInfo()
{
  /* member initializers and constructor code */
}

nsIdentityInfo::~nsIdentityInfo()
{
  /* destructor code */
}

/* readonly attribute boolean isExtendedValidation; */
NS_IMETHODIMP nsIdentityInfo::GetIsExtendedValidation(PRBool *aIsExtendedValidation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getValidEVPolicyOid (); */
NS_IMETHODIMP nsIdentityInfo::GetValidEVPolicyOid(nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIdentityInfo_h__ */
