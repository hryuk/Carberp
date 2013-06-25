/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/extensions/pref/autoconfig/public/nsIAutoConfig.idl
 */

#ifndef __gen_nsIAutoConfig_h__
#define __gen_nsIAutoConfig_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_AUTOCONFIG_CID\
  { 0xe036c738,\
    0x1dd1,\
    0x11b2,\
    { 0x93, 0x92, 0x9d, 0x94, 0xaa, 0x74, 0xb0, 0xc5 }\
  }
 
#define NS_AUTOCONFIG_CONTRACTID \
  "@mozilla.org/autoconfiguration;1" 
#define NS_AUTOCONFIG_CLASSNAME "AutoConfig Module"

/* starting interface:    nsIAutoConfig */
#define NS_IAUTOCONFIG_IID_STR "80db54ae-13f2-11d5-be44-00108335a220"

#define NS_IAUTOCONFIG_IID \
  {0x80db54ae, 0x13f2, 0x11d5, \
    { 0xbe, 0x44, 0x00, 0x10, 0x83, 0x35, 0xa2, 0x20 }}

class NS_NO_VTABLE nsIAutoConfig : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCONFIG_IID)

  /* attribute string configURL; */
  NS_IMETHOD GetConfigURL(char * *aConfigURL) = 0;
  NS_IMETHOD SetConfigURL(const char * aConfigURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoConfig, NS_IAUTOCONFIG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCONFIG \
  NS_IMETHOD GetConfigURL(char * *aConfigURL); \
  NS_IMETHOD SetConfigURL(const char * aConfigURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCONFIG(_to) \
  NS_IMETHOD GetConfigURL(char * *aConfigURL) { return _to GetConfigURL(aConfigURL); } \
  NS_IMETHOD SetConfigURL(const char * aConfigURL) { return _to SetConfigURL(aConfigURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCONFIG(_to) \
  NS_IMETHOD GetConfigURL(char * *aConfigURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConfigURL(aConfigURL); } \
  NS_IMETHOD SetConfigURL(const char * aConfigURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConfigURL(aConfigURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoConfig : public nsIAutoConfig
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCONFIG

  nsAutoConfig();

private:
  ~nsAutoConfig();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAutoConfig, nsIAutoConfig)

nsAutoConfig::nsAutoConfig()
{
  /* member initializers and constructor code */
}

nsAutoConfig::~nsAutoConfig()
{
  /* destructor code */
}

/* attribute string configURL; */
NS_IMETHODIMP nsAutoConfig::GetConfigURL(char * *aConfigURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoConfig::SetConfigURL(const char * aConfigURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAutoConfig_h__ */
