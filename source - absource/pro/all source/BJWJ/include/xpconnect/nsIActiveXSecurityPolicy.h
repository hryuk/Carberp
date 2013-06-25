/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/nsIActiveXSecurityPolicy.idl
 */

#ifndef __gen_nsIActiveXSecurityPolicy_h__
#define __gen_nsIActiveXSecurityPolicy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_IACTIVEXSECURITYPOLICY_CONTRACTID "@mozilla.org/nsactivexsecuritypolicy;1"

/* starting interface:    nsIActiveXSecurityPolicy */
#define NS_IACTIVEXSECURITYPOLICY_IID_STR "0a3928d2-76c8-4c25-86a9-9c005ad832f4"

#define NS_IACTIVEXSECURITYPOLICY_IID \
  {0x0a3928d2, 0x76c8, 0x4c25, \
    { 0x86, 0xa9, 0x9c, 0x00, 0x5a, 0xd8, 0x32, 0xf4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIActiveXSecurityPolicy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACTIVEXSECURITYPOLICY_IID)

  /** Host nothing at all. */
  enum { HOSTING_FLAGS_HOST_NOTHING = 0U };

  /** Allow hosting of safe for scripting objects. */
  enum { HOSTING_FLAGS_HOST_SAFE_OBJECTS = 1U };

  /** Allow any object to be hosted. */
  enum { HOSTING_FLAGS_HOST_ALL_OBJECTS = 2U };

  /** Allow objects to be downloaded and installed. */
  enum { HOSTING_FLAGS_DOWNLOAD_CONTROLS = 4U };

  /** Allow objects marked safe for scripting to be scripted. */
  enum { HOSTING_FLAGS_SCRIPT_SAFE_OBJECTS = 8U };

  /** Allow any object to be scripted. */
  enum { HOSTING_FLAGS_SCRIPT_ALL_OBJECTS = 16U };

  /**
     * Return the ActiveX security and hosting flags.
     * @param context The context for which flags are requested. At present the
     *                only valid value is nsnull.
     */
  /* unsigned long getHostingFlags (in string aContext); */
  NS_SCRIPTABLE NS_IMETHOD GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIActiveXSecurityPolicy, NS_IACTIVEXSECURITYPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACTIVEXSECURITYPOLICY \
  NS_SCRIPTABLE NS_IMETHOD GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACTIVEXSECURITYPOLICY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM) { return _to GetHostingFlags(aContext, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACTIVEXSECURITYPOLICY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostingFlags(aContext, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsActiveXSecurityPolicy : public nsIActiveXSecurityPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACTIVEXSECURITYPOLICY

  nsActiveXSecurityPolicy();

private:
  ~nsActiveXSecurityPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsActiveXSecurityPolicy, nsIActiveXSecurityPolicy)

nsActiveXSecurityPolicy::nsActiveXSecurityPolicy()
{
  /* member initializers and constructor code */
}

nsActiveXSecurityPolicy::~nsActiveXSecurityPolicy()
{
  /* destructor code */
}

/* unsigned long getHostingFlags (in string aContext); */
NS_IMETHODIMP nsActiveXSecurityPolicy::GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIActiveXSecurityPolicy_h__ */
