/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpinstall/public/nsPICertNotification.idl
 */

#ifndef __gen_nsPICertNotification_h__
#define __gen_nsPICertNotification_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsPICertNotification */
#define NS_PICERTNOTIFICATION_IID_STR "42cd7162-ea4a-4088-9888-63ea5095869e"

#define NS_PICERTNOTIFICATION_IID \
  {0x42cd7162, 0xea4a, 0x4088, \
    { 0x98, 0x88, 0x63, 0xea, 0x50, 0x95, 0x86, 0x9e }}

class NS_NO_VTABLE nsPICertNotification : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PICERTNOTIFICATION_IID)

  /* void onCertAvailable (in nsIURI aURI, in nsISupports aContext, in PRUint32 aStatus, in nsIPrincipal aPrincipal); */
  NS_IMETHOD OnCertAvailable(nsIURI *aURI, nsISupports *aContext, PRUint32 aStatus, nsIPrincipal *aPrincipal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPICertNotification, NS_PICERTNOTIFICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPICERTNOTIFICATION \
  NS_IMETHOD OnCertAvailable(nsIURI *aURI, nsISupports *aContext, PRUint32 aStatus, nsIPrincipal *aPrincipal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPICERTNOTIFICATION(_to) \
  NS_IMETHOD OnCertAvailable(nsIURI *aURI, nsISupports *aContext, PRUint32 aStatus, nsIPrincipal *aPrincipal) { return _to OnCertAvailable(aURI, aContext, aStatus, aPrincipal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPICERTNOTIFICATION(_to) \
  NS_IMETHOD OnCertAvailable(nsIURI *aURI, nsISupports *aContext, PRUint32 aStatus, nsIPrincipal *aPrincipal) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCertAvailable(aURI, aContext, aStatus, aPrincipal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPICertNotification
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPICERTNOTIFICATION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPICertNotification)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onCertAvailable (in nsIURI aURI, in nsISupports aContext, in PRUint32 aStatus, in nsIPrincipal aPrincipal); */
NS_IMETHODIMP _MYCLASS_::OnCertAvailable(nsIURI *aURI, nsISupports *aContext, PRUint32 aStatus, nsIPrincipal *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPICertNotification_h__ */
