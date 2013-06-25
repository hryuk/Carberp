/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIAssociatedContentSecurity.idl
 */

#ifndef __gen_nsIAssociatedContentSecurity_h__
#define __gen_nsIAssociatedContentSecurity_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAssociatedContentSecurity */
#define NS_IASSOCIATEDCONTENTSECURITY_IID_STR "8db92dde-799f-4d33-80f7-459cac800dc9"

#define NS_IASSOCIATEDCONTENTSECURITY_IID \
  {0x8db92dde, 0x799f, 0x4d33, \
    { 0x80, 0xf7, 0x45, 0x9c, 0xac, 0x80, 0x0d, 0xc9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAssociatedContentSecurity : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASSOCIATEDCONTENTSECURITY_IID)

  /* attribute long countSubRequestsHighSecurity; */
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsHighSecurity(PRInt32 *aCountSubRequestsHighSecurity) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsHighSecurity(PRInt32 aCountSubRequestsHighSecurity) = 0;

  /* attribute long countSubRequestsLowSecurity; */
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsLowSecurity(PRInt32 *aCountSubRequestsLowSecurity) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsLowSecurity(PRInt32 aCountSubRequestsLowSecurity) = 0;

  /* attribute long countSubRequestsBrokenSecurity; */
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsBrokenSecurity(PRInt32 *aCountSubRequestsBrokenSecurity) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsBrokenSecurity(PRInt32 aCountSubRequestsBrokenSecurity) = 0;

  /* attribute long countSubRequestsNoSecurity; */
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsNoSecurity(PRInt32 *aCountSubRequestsNoSecurity) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsNoSecurity(PRInt32 aCountSubRequestsNoSecurity) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAssociatedContentSecurity, NS_IASSOCIATEDCONTENTSECURITY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASSOCIATEDCONTENTSECURITY \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsHighSecurity(PRInt32 *aCountSubRequestsHighSecurity); \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsHighSecurity(PRInt32 aCountSubRequestsHighSecurity); \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsLowSecurity(PRInt32 *aCountSubRequestsLowSecurity); \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsLowSecurity(PRInt32 aCountSubRequestsLowSecurity); \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsBrokenSecurity(PRInt32 *aCountSubRequestsBrokenSecurity); \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsBrokenSecurity(PRInt32 aCountSubRequestsBrokenSecurity); \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsNoSecurity(PRInt32 *aCountSubRequestsNoSecurity); \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsNoSecurity(PRInt32 aCountSubRequestsNoSecurity); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASSOCIATEDCONTENTSECURITY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsHighSecurity(PRInt32 *aCountSubRequestsHighSecurity) { return _to GetCountSubRequestsHighSecurity(aCountSubRequestsHighSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsHighSecurity(PRInt32 aCountSubRequestsHighSecurity) { return _to SetCountSubRequestsHighSecurity(aCountSubRequestsHighSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsLowSecurity(PRInt32 *aCountSubRequestsLowSecurity) { return _to GetCountSubRequestsLowSecurity(aCountSubRequestsLowSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsLowSecurity(PRInt32 aCountSubRequestsLowSecurity) { return _to SetCountSubRequestsLowSecurity(aCountSubRequestsLowSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsBrokenSecurity(PRInt32 *aCountSubRequestsBrokenSecurity) { return _to GetCountSubRequestsBrokenSecurity(aCountSubRequestsBrokenSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsBrokenSecurity(PRInt32 aCountSubRequestsBrokenSecurity) { return _to SetCountSubRequestsBrokenSecurity(aCountSubRequestsBrokenSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsNoSecurity(PRInt32 *aCountSubRequestsNoSecurity) { return _to GetCountSubRequestsNoSecurity(aCountSubRequestsNoSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsNoSecurity(PRInt32 aCountSubRequestsNoSecurity) { return _to SetCountSubRequestsNoSecurity(aCountSubRequestsNoSecurity); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASSOCIATEDCONTENTSECURITY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsHighSecurity(PRInt32 *aCountSubRequestsHighSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountSubRequestsHighSecurity(aCountSubRequestsHighSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsHighSecurity(PRInt32 aCountSubRequestsHighSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCountSubRequestsHighSecurity(aCountSubRequestsHighSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsLowSecurity(PRInt32 *aCountSubRequestsLowSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountSubRequestsLowSecurity(aCountSubRequestsLowSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsLowSecurity(PRInt32 aCountSubRequestsLowSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCountSubRequestsLowSecurity(aCountSubRequestsLowSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsBrokenSecurity(PRInt32 *aCountSubRequestsBrokenSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountSubRequestsBrokenSecurity(aCountSubRequestsBrokenSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsBrokenSecurity(PRInt32 aCountSubRequestsBrokenSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCountSubRequestsBrokenSecurity(aCountSubRequestsBrokenSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountSubRequestsNoSecurity(PRInt32 *aCountSubRequestsNoSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountSubRequestsNoSecurity(aCountSubRequestsNoSecurity); } \
  NS_SCRIPTABLE NS_IMETHOD SetCountSubRequestsNoSecurity(PRInt32 aCountSubRequestsNoSecurity) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCountSubRequestsNoSecurity(aCountSubRequestsNoSecurity); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAssociatedContentSecurity : public nsIAssociatedContentSecurity
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASSOCIATEDCONTENTSECURITY

  nsAssociatedContentSecurity();

private:
  ~nsAssociatedContentSecurity();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAssociatedContentSecurity, nsIAssociatedContentSecurity)

nsAssociatedContentSecurity::nsAssociatedContentSecurity()
{
  /* member initializers and constructor code */
}

nsAssociatedContentSecurity::~nsAssociatedContentSecurity()
{
  /* destructor code */
}

/* attribute long countSubRequestsHighSecurity; */
NS_IMETHODIMP nsAssociatedContentSecurity::GetCountSubRequestsHighSecurity(PRInt32 *aCountSubRequestsHighSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAssociatedContentSecurity::SetCountSubRequestsHighSecurity(PRInt32 aCountSubRequestsHighSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long countSubRequestsLowSecurity; */
NS_IMETHODIMP nsAssociatedContentSecurity::GetCountSubRequestsLowSecurity(PRInt32 *aCountSubRequestsLowSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAssociatedContentSecurity::SetCountSubRequestsLowSecurity(PRInt32 aCountSubRequestsLowSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long countSubRequestsBrokenSecurity; */
NS_IMETHODIMP nsAssociatedContentSecurity::GetCountSubRequestsBrokenSecurity(PRInt32 *aCountSubRequestsBrokenSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAssociatedContentSecurity::SetCountSubRequestsBrokenSecurity(PRInt32 aCountSubRequestsBrokenSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long countSubRequestsNoSecurity; */
NS_IMETHODIMP nsAssociatedContentSecurity::GetCountSubRequestsNoSecurity(PRInt32 *aCountSubRequestsNoSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAssociatedContentSecurity::SetCountSubRequestsNoSecurity(PRInt32 aCountSubRequestsNoSecurity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAssociatedContentSecurity_h__ */
