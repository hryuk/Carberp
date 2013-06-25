/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/socket/base/nsISSLSocketControl.idl
 */

#ifndef __gen_nsISSLSocketControl_h__
#define __gen_nsISSLSocketControl_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsISSLSocketControl */
#define NS_ISSLSOCKETCONTROL_IID_STR "a092097c-8386-4f1b-97b1-90eb70008c2d"

#define NS_ISSLSOCKETCONTROL_IID \
  {0xa092097c, 0x8386, 0x4f1b, \
    { 0x97, 0xb1, 0x90, 0xeb, 0x70, 0x00, 0x8c, 0x2d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISSLSocketControl : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISSLSOCKETCONTROL_IID)

  /* attribute nsIInterfaceRequestor notificationCallbacks; */
  NS_SCRIPTABLE NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor * aNotificationCallbacks) = 0;

  /* void proxyStartSSL (); */
  NS_SCRIPTABLE NS_IMETHOD ProxyStartSSL(void) = 0;

  /* void StartTLS (); */
  NS_SCRIPTABLE NS_IMETHOD StartTLS(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISSLSocketControl, NS_ISSLSOCKETCONTROL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISSLSOCKETCONTROL \
  NS_SCRIPTABLE NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks); \
  NS_SCRIPTABLE NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor * aNotificationCallbacks); \
  NS_SCRIPTABLE NS_IMETHOD ProxyStartSSL(void); \
  NS_SCRIPTABLE NS_IMETHOD StartTLS(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISSLSOCKETCONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return _to GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_SCRIPTABLE NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor * aNotificationCallbacks) { return _to SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_SCRIPTABLE NS_IMETHOD ProxyStartSSL(void) { return _to ProxyStartSSL(); } \
  NS_SCRIPTABLE NS_IMETHOD StartTLS(void) { return _to StartTLS(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISSLSOCKETCONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_SCRIPTABLE NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor * aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_SCRIPTABLE NS_IMETHOD ProxyStartSSL(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProxyStartSSL(); } \
  NS_SCRIPTABLE NS_IMETHOD StartTLS(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartTLS(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSSLSocketControl : public nsISSLSocketControl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISSLSOCKETCONTROL

  nsSSLSocketControl();

private:
  ~nsSSLSocketControl();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSSLSocketControl, nsISSLSocketControl)

nsSSLSocketControl::nsSSLSocketControl()
{
  /* member initializers and constructor code */
}

nsSSLSocketControl::~nsSSLSocketControl()
{
  /* destructor code */
}

/* attribute nsIInterfaceRequestor notificationCallbacks; */
NS_IMETHODIMP nsSSLSocketControl::GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSSLSocketControl::SetNotificationCallbacks(nsIInterfaceRequestor * aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void proxyStartSSL (); */
NS_IMETHODIMP nsSSLSocketControl::ProxyStartSSL()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void StartTLS (); */
NS_IMETHODIMP nsSSLSocketControl::StartTLS()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISSLSocketControl_h__ */
