/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/system/nsIXULAppInfo.idl
 */

#ifndef __gen_nsIXULAppInfo_h__
#define __gen_nsIXULAppInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXULAppInfo */
#define NS_IXULAPPINFO_IID_STR "a61ede2a-ef09-11d9-a5ce-001124787b2e"

#define NS_IXULAPPINFO_IID \
  {0xa61ede2a, 0xef09, 0x11d9, \
    { 0xa5, 0xce, 0x00, 0x11, 0x24, 0x78, 0x7b, 0x2e }}

/**
 * A scriptable interface to the nsXULAppAPI structure. See nsXULAppAPI.h for
 * a detailed description of each attribute.
 *
 * @status FROZEN - This interface is frozen for use by embedders and will
 *                  not change in the future.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXULAppInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULAPPINFO_IID)

  /**
   * @see nsXREAppData.vendor
   * @returns an empty string if nsXREAppData.vendor is not set.
   */
  /* readonly attribute ACString vendor; */
  NS_SCRIPTABLE NS_IMETHOD GetVendor(nsACString & aVendor) = 0;

  /**
   * @see nsXREAppData.name
   */
  /* readonly attribute ACString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) = 0;

  /**
   * @see nsXREAppData.ID
   * @returns an empty string if nsXREAppData.ID is not set.
   */
  /* readonly attribute ACString ID; */
  NS_SCRIPTABLE NS_IMETHOD GetID(nsACString & aID) = 0;

  /**
   * The version of the XUL application. It is different than the
   * version of the XULRunner platform. Be careful about which one you want.
   *
   * @see nsXREAppData.version
   * @returns an empty string if nsXREAppData.version is not set.
   */
  /* readonly attribute ACString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsACString & aVersion) = 0;

  /**
   * The build ID/date of the application. For xulrunner applications,
   * this will be different than the build ID of the platform. Be careful
   * about which one you want.
   */
  /* readonly attribute ACString appBuildID; */
  NS_SCRIPTABLE NS_IMETHOD GetAppBuildID(nsACString & aAppBuildID) = 0;

  /**
   * The version of the XULRunner platform.
   */
  /* readonly attribute ACString platformVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetPlatformVersion(nsACString & aPlatformVersion) = 0;

  /**
   * The build ID/date of gecko and the XULRunner platform.
   */
  /* readonly attribute ACString platformBuildID; */
  NS_SCRIPTABLE NS_IMETHOD GetPlatformBuildID(nsACString & aPlatformBuildID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULAppInfo, NS_IXULAPPINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULAPPINFO \
  NS_SCRIPTABLE NS_IMETHOD GetVendor(nsACString & aVendor); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetID(nsACString & aID); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsACString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetAppBuildID(nsACString & aAppBuildID); \
  NS_SCRIPTABLE NS_IMETHOD GetPlatformVersion(nsACString & aPlatformVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetPlatformBuildID(nsACString & aPlatformBuildID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULAPPINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVendor(nsACString & aVendor) { return _to GetVendor(aVendor); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetID(nsACString & aID) { return _to GetID(aID); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsACString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetAppBuildID(nsACString & aAppBuildID) { return _to GetAppBuildID(aAppBuildID); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlatformVersion(nsACString & aPlatformVersion) { return _to GetPlatformVersion(aPlatformVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlatformBuildID(nsACString & aPlatformBuildID) { return _to GetPlatformBuildID(aPlatformBuildID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULAPPINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVendor(nsACString & aVendor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVendor(aVendor); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetID(nsACString & aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetID(aID); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsACString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetAppBuildID(nsACString & aAppBuildID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppBuildID(aAppBuildID); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlatformVersion(nsACString & aPlatformVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatformVersion(aPlatformVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlatformBuildID(nsACString & aPlatformBuildID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatformBuildID(aPlatformBuildID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULAppInfo : public nsIXULAppInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULAPPINFO

  nsXULAppInfo();

private:
  ~nsXULAppInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULAppInfo, nsIXULAppInfo)

nsXULAppInfo::nsXULAppInfo()
{
  /* member initializers and constructor code */
}

nsXULAppInfo::~nsXULAppInfo()
{
  /* destructor code */
}

/* readonly attribute ACString vendor; */
NS_IMETHODIMP nsXULAppInfo::GetVendor(nsACString & aVendor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString name; */
NS_IMETHODIMP nsXULAppInfo::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString ID; */
NS_IMETHODIMP nsXULAppInfo::GetID(nsACString & aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString version; */
NS_IMETHODIMP nsXULAppInfo::GetVersion(nsACString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString appBuildID; */
NS_IMETHODIMP nsXULAppInfo::GetAppBuildID(nsACString & aAppBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString platformVersion; */
NS_IMETHODIMP nsXULAppInfo::GetPlatformVersion(nsACString & aPlatformVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString platformBuildID; */
NS_IMETHODIMP nsXULAppInfo::GetPlatformBuildID(nsACString & aPlatformBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULAppInfo_h__ */
