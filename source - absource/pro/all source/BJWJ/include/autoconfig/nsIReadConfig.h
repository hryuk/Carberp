/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/extensions/pref/autoconfig/public/nsIReadConfig.idl
 */

#ifndef __gen_nsIReadConfig_h__
#define __gen_nsIReadConfig_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_READCONFIG_CID\
  { 0xba5bc4c6,\
    0x1dd1, \
    0x11b2, \
    { 0xbb, 0x89, 0xb8, 0x44, 0xc6, 0xec, 0x03, 0x39 }\
  }
 
#define NS_READCONFIG_CONTRACTID \
  "@mozilla.org/readconfig;1" 
#define NS_READCONFIG_CLASSNAME "ReadConfig Module"

/* starting interface:    nsIReadConfig */
#define NS_IREADCONFIG_IID_STR "ba5bc4c6-1dd1-11b2-bb89-b844c6ec0339"

#define NS_IREADCONFIG_IID \
  {0xba5bc4c6, 0x1dd1, 0x11b2, \
    { 0xbb, 0x89, 0xb8, 0x44, 0xc6, 0xec, 0x03, 0x39 }}

class NS_NO_VTABLE nsIReadConfig : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREADCONFIG_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIReadConfig, NS_IREADCONFIG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREADCONFIG \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREADCONFIG(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREADCONFIG(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsReadConfig : public nsIReadConfig
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREADCONFIG

  nsReadConfig();

private:
  ~nsReadConfig();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsReadConfig, nsIReadConfig)

nsReadConfig::nsReadConfig()
{
  /* member initializers and constructor code */
}

nsReadConfig::~nsReadConfig()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIReadConfig_h__ */
