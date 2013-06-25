/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIIOService2.idl
 */

#ifndef __gen_nsIIOService2_h__
#define __gen_nsIIOService2_h__


#ifndef __gen_nsIIOService_h__
#include "nsIIOService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIOService2 */
#define NS_IIOSERVICE2_IID_STR "d44fe6d4-ee35-4789-886a-eb8f0554d04e"

#define NS_IIOSERVICE2_IID \
  {0xd44fe6d4, 0xee35, 0x4789, \
    { 0x88, 0x6a, 0xeb, 0x8f, 0x05, 0x54, 0xd0, 0x4e }}

/**
 * nsIIOService2 extends nsIIOService with support for automatic
 * online/offline management.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIOService2 : public nsIIOService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIOSERVICE2_IID)

  /**
   * While this is set, IOService will monitor an nsINetworkLinkService
   * (if available) and set its offline status to "true" whenever
   * isLinkUp is false.
   *
   * Applications that want to control changes to the IOService's offline
   * status should set this to false, watch for network:link-status-changed
   * broadcasts, and change nsIIOService::offline as they see fit. Note
   * that this means during application startup, IOService may be offline
   * if there is no link, until application code runs and can turn off
   * this management.
   */
  /* attribute boolean manageOfflineStatus; */
  NS_SCRIPTABLE NS_IMETHOD GetManageOfflineStatus(PRBool *aManageOfflineStatus) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetManageOfflineStatus(PRBool aManageOfflineStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIOService2, NS_IIOSERVICE2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIOSERVICE2 \
  NS_SCRIPTABLE NS_IMETHOD GetManageOfflineStatus(PRBool *aManageOfflineStatus); \
  NS_SCRIPTABLE NS_IMETHOD SetManageOfflineStatus(PRBool aManageOfflineStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIOSERVICE2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetManageOfflineStatus(PRBool *aManageOfflineStatus) { return _to GetManageOfflineStatus(aManageOfflineStatus); } \
  NS_SCRIPTABLE NS_IMETHOD SetManageOfflineStatus(PRBool aManageOfflineStatus) { return _to SetManageOfflineStatus(aManageOfflineStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIOSERVICE2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetManageOfflineStatus(PRBool *aManageOfflineStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManageOfflineStatus(aManageOfflineStatus); } \
  NS_SCRIPTABLE NS_IMETHOD SetManageOfflineStatus(PRBool aManageOfflineStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetManageOfflineStatus(aManageOfflineStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIOService2 : public nsIIOService2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIOSERVICE2

  nsIOService2();

private:
  ~nsIOService2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIOService2, nsIIOService2)

nsIOService2::nsIOService2()
{
  /* member initializers and constructor code */
}

nsIOService2::~nsIOService2()
{
  /* destructor code */
}

/* attribute boolean manageOfflineStatus; */
NS_IMETHODIMP nsIOService2::GetManageOfflineStatus(PRBool *aManageOfflineStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIOService2::SetManageOfflineStatus(PRBool aManageOfflineStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIOService2_h__ */
