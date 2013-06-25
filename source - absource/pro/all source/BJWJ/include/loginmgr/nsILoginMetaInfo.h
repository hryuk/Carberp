/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/passwordmgr/public/nsILoginMetaInfo.idl
 */

#ifndef __gen_nsILoginMetaInfo_h__
#define __gen_nsILoginMetaInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILoginMetaInfo */
#define NS_ILOGINMETAINFO_IID_STR "867407d5-10e0-43a0-bc81-a324740534ca"

#define NS_ILOGINMETAINFO_IID \
  {0x867407d5, 0x10e0, 0x43a0, \
    { 0xbc, 0x81, 0xa3, 0x24, 0x74, 0x05, 0x34, 0xca }}

/**
 * An object containing metainfo for a login stored by the login manager.
 *
 * Code using login manager can generally ignore this interface. When adding
 * logins, default value will be created. When modifying logins, these
 * properties will be unchanged unless a change is explicitly requested [by
 * using modifyLogin() with a nsIPropertyBag]. When deleting a login or
 * comparing logins, these properties are ignored.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsILoginMetaInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMETAINFO_IID)

  /**
     * The GUID to uniquely identify the login. This can be any arbitrary
     * string, but a format as created by nsIUUIDGenerator is recommended.
     * For example, "{d4e1a1f6-5ea0-40ee-bff5-da57982f21cf}"
     *
     * addLogin will generate a random value unless a value is provided.
     *
     * addLogin and modifyLogin will throw if the GUID already exists.
     */
  /* attribute AString guid; */
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsAString & aGuid) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetGuid(const nsAString & aGuid) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginMetaInfo, NS_ILOGINMETAINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMETAINFO \
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsAString & aGuid); \
  NS_SCRIPTABLE NS_IMETHOD SetGuid(const nsAString & aGuid); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMETAINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsAString & aGuid) { return _to GetGuid(aGuid); } \
  NS_SCRIPTABLE NS_IMETHOD SetGuid(const nsAString & aGuid) { return _to SetGuid(aGuid); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMETAINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsAString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGuid(aGuid); } \
  NS_SCRIPTABLE NS_IMETHOD SetGuid(const nsAString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGuid(aGuid); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginMetaInfo : public nsILoginMetaInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMETAINFO

  nsLoginMetaInfo();

private:
  ~nsLoginMetaInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoginMetaInfo, nsILoginMetaInfo)

nsLoginMetaInfo::nsLoginMetaInfo()
{
  /* member initializers and constructor code */
}

nsLoginMetaInfo::~nsLoginMetaInfo()
{
  /* destructor code */
}

/* attribute AString guid; */
NS_IMETHODIMP nsLoginMetaInfo::GetGuid(nsAString & aGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetGuid(const nsAString & aGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoginMetaInfo_h__ */
