/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/startup/public/nsIUserInfo.idl
 */

#ifndef __gen_nsIUserInfo_h__
#define __gen_nsIUserInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUserInfo */
#define NS_IUSERINFO_IID_STR "6c1034f0-1dd2-11b2-aa14-e6657ed7bb0b"

#define NS_IUSERINFO_IID \
  {0x6c1034f0, 0x1dd2, 0x11b2, \
    { 0xaa, 0x14, 0xe6, 0x65, 0x7e, 0xd7, 0xbb, 0x0b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIUserInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUSERINFO_IID)

  /* readonly attribute wstring fullname; */
  NS_SCRIPTABLE NS_IMETHOD GetFullname(PRUnichar * *aFullname) = 0;

  /* readonly attribute string emailAddress; */
  NS_SCRIPTABLE NS_IMETHOD GetEmailAddress(char * *aEmailAddress) = 0;

  /* readonly attribute string username; */
  NS_SCRIPTABLE NS_IMETHOD GetUsername(char * *aUsername) = 0;

  /* readonly attribute string domain; */
  NS_SCRIPTABLE NS_IMETHOD GetDomain(char * *aDomain) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUserInfo, NS_IUSERINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUSERINFO \
  NS_SCRIPTABLE NS_IMETHOD GetFullname(PRUnichar * *aFullname); \
  NS_SCRIPTABLE NS_IMETHOD GetEmailAddress(char * *aEmailAddress); \
  NS_SCRIPTABLE NS_IMETHOD GetUsername(char * *aUsername); \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(char * *aDomain); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUSERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFullname(PRUnichar * *aFullname) { return _to GetFullname(aFullname); } \
  NS_SCRIPTABLE NS_IMETHOD GetEmailAddress(char * *aEmailAddress) { return _to GetEmailAddress(aEmailAddress); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsername(char * *aUsername) { return _to GetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(char * *aDomain) { return _to GetDomain(aDomain); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUSERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFullname(PRUnichar * *aFullname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullname(aFullname); } \
  NS_SCRIPTABLE NS_IMETHOD GetEmailAddress(char * *aEmailAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmailAddress(aEmailAddress); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsername(char * *aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsername(aUsername); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(char * *aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUserInfo : public nsIUserInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUSERINFO

  nsUserInfo();

private:
  ~nsUserInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUserInfo, nsIUserInfo)

nsUserInfo::nsUserInfo()
{
  /* member initializers and constructor code */
}

nsUserInfo::~nsUserInfo()
{
  /* destructor code */
}

/* readonly attribute wstring fullname; */
NS_IMETHODIMP nsUserInfo::GetFullname(PRUnichar * *aFullname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string emailAddress; */
NS_IMETHODIMP nsUserInfo::GetEmailAddress(char * *aEmailAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string username; */
NS_IMETHODIMP nsUserInfo::GetUsername(char * *aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string domain; */
NS_IMETHODIMP nsUserInfo::GetDomain(char * *aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// 14c13684-1dd2-11b2-9463-bb10ba742554
#define NS_USERINFO_CID \
{  0x14c13684, 0x1dd2, 0x11b2, \
  {0x94, 0x63, 0xbb, 0x10, 0xba, 0x74, 0x25, 0x54}}
#define NS_USERINFO_CONTRACTID "@mozilla.org/userinfo;1"

#endif /* __gen_nsIUserInfo_h__ */
