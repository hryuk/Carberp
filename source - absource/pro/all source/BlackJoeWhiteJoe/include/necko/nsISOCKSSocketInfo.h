/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/socket/base/nsISOCKSSocketInfo.idl
 */

#ifndef __gen_nsISOCKSSocketInfo_h__
#define __gen_nsISOCKSSocketInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISOCKSSocketInfo */
#define NS_ISOCKSSOCKETINFO_IID_STR "8f755c44-1dd2-11b2-a613-91117453fa95"

#define NS_ISOCKSSOCKETINFO_IID \
  {0x8f755c44, 0x1dd2, 0x11b2, \
    { 0xa6, 0x13, 0x91, 0x11, 0x74, 0x53, 0xfa, 0x95 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISOCKSSocketInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOCKSSOCKETINFO_IID)

  /* [noscript] attribute PRNetAddrPtr destinationAddr; */
  NS_IMETHOD GetDestinationAddr(union PRNetAddr * *aDestinationAddr) = 0;
  NS_IMETHOD SetDestinationAddr(union PRNetAddr * aDestinationAddr) = 0;

  /* [noscript] attribute PRNetAddrPtr externalProxyAddr; */
  NS_IMETHOD GetExternalProxyAddr(union PRNetAddr * *aExternalProxyAddr) = 0;
  NS_IMETHOD SetExternalProxyAddr(union PRNetAddr * aExternalProxyAddr) = 0;

  /* [noscript] attribute PRNetAddrPtr internalProxyAddr; */
  NS_IMETHOD GetInternalProxyAddr(union PRNetAddr * *aInternalProxyAddr) = 0;
  NS_IMETHOD SetInternalProxyAddr(union PRNetAddr * aInternalProxyAddr) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISOCKSSocketInfo, NS_ISOCKSSOCKETINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOCKSSOCKETINFO \
  NS_IMETHOD GetDestinationAddr(union PRNetAddr * *aDestinationAddr); \
  NS_IMETHOD SetDestinationAddr(union PRNetAddr * aDestinationAddr); \
  NS_IMETHOD GetExternalProxyAddr(union PRNetAddr * *aExternalProxyAddr); \
  NS_IMETHOD SetExternalProxyAddr(union PRNetAddr * aExternalProxyAddr); \
  NS_IMETHOD GetInternalProxyAddr(union PRNetAddr * *aInternalProxyAddr); \
  NS_IMETHOD SetInternalProxyAddr(union PRNetAddr * aInternalProxyAddr); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOCKSSOCKETINFO(_to) \
  NS_IMETHOD GetDestinationAddr(union PRNetAddr * *aDestinationAddr) { return _to GetDestinationAddr(aDestinationAddr); } \
  NS_IMETHOD SetDestinationAddr(union PRNetAddr * aDestinationAddr) { return _to SetDestinationAddr(aDestinationAddr); } \
  NS_IMETHOD GetExternalProxyAddr(union PRNetAddr * *aExternalProxyAddr) { return _to GetExternalProxyAddr(aExternalProxyAddr); } \
  NS_IMETHOD SetExternalProxyAddr(union PRNetAddr * aExternalProxyAddr) { return _to SetExternalProxyAddr(aExternalProxyAddr); } \
  NS_IMETHOD GetInternalProxyAddr(union PRNetAddr * *aInternalProxyAddr) { return _to GetInternalProxyAddr(aInternalProxyAddr); } \
  NS_IMETHOD SetInternalProxyAddr(union PRNetAddr * aInternalProxyAddr) { return _to SetInternalProxyAddr(aInternalProxyAddr); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOCKSSOCKETINFO(_to) \
  NS_IMETHOD GetDestinationAddr(union PRNetAddr * *aDestinationAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDestinationAddr(aDestinationAddr); } \
  NS_IMETHOD SetDestinationAddr(union PRNetAddr * aDestinationAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDestinationAddr(aDestinationAddr); } \
  NS_IMETHOD GetExternalProxyAddr(union PRNetAddr * *aExternalProxyAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExternalProxyAddr(aExternalProxyAddr); } \
  NS_IMETHOD SetExternalProxyAddr(union PRNetAddr * aExternalProxyAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExternalProxyAddr(aExternalProxyAddr); } \
  NS_IMETHOD GetInternalProxyAddr(union PRNetAddr * *aInternalProxyAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalProxyAddr(aInternalProxyAddr); } \
  NS_IMETHOD SetInternalProxyAddr(union PRNetAddr * aInternalProxyAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInternalProxyAddr(aInternalProxyAddr); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSOCKSSocketInfo : public nsISOCKSSocketInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOCKSSOCKETINFO

  nsSOCKSSocketInfo();

private:
  ~nsSOCKSSocketInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSOCKSSocketInfo, nsISOCKSSocketInfo)

nsSOCKSSocketInfo::nsSOCKSSocketInfo()
{
  /* member initializers and constructor code */
}

nsSOCKSSocketInfo::~nsSOCKSSocketInfo()
{
  /* destructor code */
}

/* [noscript] attribute PRNetAddrPtr destinationAddr; */
NS_IMETHODIMP nsSOCKSSocketInfo::GetDestinationAddr(union PRNetAddr * *aDestinationAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSOCKSSocketInfo::SetDestinationAddr(union PRNetAddr * aDestinationAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute PRNetAddrPtr externalProxyAddr; */
NS_IMETHODIMP nsSOCKSSocketInfo::GetExternalProxyAddr(union PRNetAddr * *aExternalProxyAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSOCKSSocketInfo::SetExternalProxyAddr(union PRNetAddr * aExternalProxyAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute PRNetAddrPtr internalProxyAddr; */
NS_IMETHODIMP nsSOCKSSocketInfo::GetInternalProxyAddr(union PRNetAddr * *aInternalProxyAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSOCKSSocketInfo::SetInternalProxyAddr(union PRNetAddr * aInternalProxyAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISOCKSSocketInfo_h__ */
