/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/wifi/public/nsIWifiListener.idl
 */

#ifndef __gen_nsIWifiListener_h__
#define __gen_nsIWifiListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIArray_h__
#include "nsIArray.h"
#endif

#ifndef __gen_nsIWifiAccessPoint_h__
#include "nsIWifiAccessPoint.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWifiListener */
#define NS_IWIFILISTENER_IID_STR "bcd4bede-f4a5-4a62-9071-d7a60174e376"

#define NS_IWIFILISTENER_IID \
  {0xbcd4bede, 0xf4a5, 0x4a62, \
    { 0x90, 0x71, 0xd7, 0xa6, 0x01, 0x74, 0xe3, 0x76 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWifiListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWIFILISTENER_IID)

  /* void onChange ([array, size_is (aLen)] in nsIWifiAccessPoint accessPoints, in unsigned long aLen); */
  NS_SCRIPTABLE NS_IMETHOD OnChange(nsIWifiAccessPoint **accessPoints, PRUint32 aLen) = 0;

  /* void onError (in long error); */
  NS_SCRIPTABLE NS_IMETHOD OnError(PRInt32 error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWifiListener, NS_IWIFILISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWIFILISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnChange(nsIWifiAccessPoint **accessPoints, PRUint32 aLen); \
  NS_SCRIPTABLE NS_IMETHOD OnError(PRInt32 error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWIFILISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnChange(nsIWifiAccessPoint **accessPoints, PRUint32 aLen) { return _to OnChange(accessPoints, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD OnError(PRInt32 error) { return _to OnError(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWIFILISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnChange(nsIWifiAccessPoint **accessPoints, PRUint32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnChange(accessPoints, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD OnError(PRInt32 error) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWifiListener : public nsIWifiListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWIFILISTENER

  nsWifiListener();

private:
  ~nsWifiListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWifiListener, nsIWifiListener)

nsWifiListener::nsWifiListener()
{
  /* member initializers and constructor code */
}

nsWifiListener::~nsWifiListener()
{
  /* destructor code */
}

/* void onChange ([array, size_is (aLen)] in nsIWifiAccessPoint accessPoints, in unsigned long aLen); */
NS_IMETHODIMP nsWifiListener::OnChange(nsIWifiAccessPoint **accessPoints, PRUint32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onError (in long error); */
NS_IMETHODIMP nsWifiListener::OnError(PRInt32 error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWifiListener_h__ */
