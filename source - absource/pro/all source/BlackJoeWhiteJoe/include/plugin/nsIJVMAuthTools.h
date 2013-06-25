/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIJVMAuthTools.idl
 */

#ifndef __gen_nsIJVMAuthTools_h__
#define __gen_nsIJVMAuthTools_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_JVMAUTHTOOLS_CID                          \
{ /* d8e716f9-c96e-4e84-ab12-980f5567e2a4 */         \
    0xd8e716f9,                                      \
    0xc96e,                                          \
    0x4e84,                                          \
    {0xab, 0x12, 0x98, 0x0f, 0x55, 0x67, 0xe2, 0xa4} \
}

/* starting interface:    nsIAuthenticationInfo */
#define NS_IAUTHENTICATIONINFO_IID_STR "078a1b99-6be2-4a57-a749-378f4a506097"

#define NS_IAUTHENTICATIONINFO_IID \
  {0x078a1b99, 0x6be2, 0x4a57, \
    { 0xa7, 0x49, 0x37, 0x8f, 0x4a, 0x50, 0x60, 0x97 }}

class NS_NO_VTABLE nsIAuthenticationInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHENTICATIONINFO_IID)

  /** 
    * AuthenticationInfo (username/password pair)
    */
  /* readonly attribute const_char_ptr username; */
  NS_IMETHOD GetUsername(const char * *aUsername) = 0;

  /* readonly attribute const_char_ptr password; */
  NS_IMETHOD GetPassword(const char * *aPassword) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthenticationInfo, NS_IAUTHENTICATIONINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHENTICATIONINFO \
  NS_IMETHOD GetUsername(const char * *aUsername); \
  NS_IMETHOD GetPassword(const char * *aPassword); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHENTICATIONINFO(_to) \
  NS_IMETHOD GetUsername(const char * *aUsername) { return _to GetUsername(aUsername); } \
  NS_IMETHOD GetPassword(const char * *aPassword) { return _to GetPassword(aPassword); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHENTICATIONINFO(_to) \
  NS_IMETHOD GetUsername(const char * *aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsername(aUsername); } \
  NS_IMETHOD GetPassword(const char * *aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPassword(aPassword); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthenticationInfo : public nsIAuthenticationInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHENTICATIONINFO

  nsAuthenticationInfo();

private:
  ~nsAuthenticationInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthenticationInfo, nsIAuthenticationInfo)

nsAuthenticationInfo::nsAuthenticationInfo()
{
  /* member initializers and constructor code */
}

nsAuthenticationInfo::~nsAuthenticationInfo()
{
  /* destructor code */
}

/* readonly attribute const_char_ptr username; */
NS_IMETHODIMP nsAuthenticationInfo::GetUsername(const char * *aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute const_char_ptr password; */
NS_IMETHODIMP nsAuthenticationInfo::GetPassword(const char * *aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJVMAuthTools */
#define NS_IJVMAUTHTOOLS_IID_STR "82274a32-a196-42ee-8e3b-fcb73e339518"

#define NS_IJVMAUTHTOOLS_IID \
  {0x82274a32, 0xa196, 0x42ee, \
    { 0x8e, 0x3b, 0xfc, 0xb7, 0x3e, 0x33, 0x95, 0x18 }}

class NS_NO_VTABLE nsIJVMAuthTools : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJVMAUTHTOOLS_IID)

  /**
     * Export AuthenticationInfo interface to JPI.
     *
     * @param protocol               the protocol that support (http/https)
     * @param host                   host name
     * @param port                   port number
     * @param scheme                 scheme
     * @param realm                  realm
     * @param nsIAuthenticationInfo  the AuthenticationInfo interface
     *                               that export
     *
     * @return  	             NS_OK if success, other if fail
     */
  /* nsIAuthenticationInfo GetAuthenticationInfo (in string protocol, in string host, in PRInt32 port, in string scheme, in string realm); */
  NS_IMETHOD GetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, nsIAuthenticationInfo **_retval NS_OUTPARAM) = 0;

  /**
     * Import username/password pair from JPI.
     *
     * @param protocol  the protocol that support (http/https)
     * @param host      host name
     * @param port      port number
     * @param scheme    scheme
     * @param realm     realm
     * @param username  user name
     * @param password  password
     *
     * @return          NS_OK if success, other if fail
     */
  /* void SetAuthenticationInfo (in string protocol, in string host, in PRInt32 port, in string scheme, in string realm, in string username, in string password); */
  NS_IMETHOD SetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, const char *username, const char *password) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJVMAuthTools, NS_IJVMAUTHTOOLS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJVMAUTHTOOLS \
  NS_IMETHOD GetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, nsIAuthenticationInfo **_retval NS_OUTPARAM); \
  NS_IMETHOD SetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, const char *username, const char *password); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJVMAUTHTOOLS(_to) \
  NS_IMETHOD GetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, nsIAuthenticationInfo **_retval NS_OUTPARAM) { return _to GetAuthenticationInfo(protocol, host, port, scheme, realm, _retval); } \
  NS_IMETHOD SetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, const char *username, const char *password) { return _to SetAuthenticationInfo(protocol, host, port, scheme, realm, username, password); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJVMAUTHTOOLS(_to) \
  NS_IMETHOD GetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, nsIAuthenticationInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthenticationInfo(protocol, host, port, scheme, realm, _retval); } \
  NS_IMETHOD SetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, const char *username, const char *password) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAuthenticationInfo(protocol, host, port, scheme, realm, username, password); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJVMAuthTools : public nsIJVMAuthTools
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJVMAUTHTOOLS

  nsJVMAuthTools();

private:
  ~nsJVMAuthTools();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJVMAuthTools, nsIJVMAuthTools)

nsJVMAuthTools::nsJVMAuthTools()
{
  /* member initializers and constructor code */
}

nsJVMAuthTools::~nsJVMAuthTools()
{
  /* destructor code */
}

/* nsIAuthenticationInfo GetAuthenticationInfo (in string protocol, in string host, in PRInt32 port, in string scheme, in string realm); */
NS_IMETHODIMP nsJVMAuthTools::GetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, nsIAuthenticationInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetAuthenticationInfo (in string protocol, in string host, in PRInt32 port, in string scheme, in string realm, in string username, in string password); */
NS_IMETHODIMP nsJVMAuthTools::SetAuthenticationInfo(const char *protocol, const char *host, PRInt32 port, const char *scheme, const char *realm, const char *username, const char *password)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJVMAuthTools_h__ */
