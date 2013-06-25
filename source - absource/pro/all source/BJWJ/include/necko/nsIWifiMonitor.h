/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/wifi/public/nsIWifiMonitor.idl
 */

#ifndef __gen_nsIWifiMonitor_h__
#define __gen_nsIWifiMonitor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIWifiListener_h__
#include "nsIWifiListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWifiMonitor */
#define NS_IWIFIMONITOR_IID_STR "f289701e-d9af-4685-bc2f-e4226ff7c018"

#define NS_IWIFIMONITOR_IID \
  {0xf289701e, 0xd9af, 0x4685, \
    { 0xbc, 0x2f, 0xe4, 0x22, 0x6f, 0xf7, 0xc0, 0x18 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWifiMonitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWIFIMONITOR_IID)

  /* void startWatching (in nsIWifiListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD StartWatching(nsIWifiListener *aListener) = 0;

  /* void stopWatching (in nsIWifiListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD StopWatching(nsIWifiListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWifiMonitor, NS_IWIFIMONITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWIFIMONITOR \
  NS_SCRIPTABLE NS_IMETHOD StartWatching(nsIWifiListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD StopWatching(nsIWifiListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWIFIMONITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartWatching(nsIWifiListener *aListener) { return _to StartWatching(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD StopWatching(nsIWifiListener *aListener) { return _to StopWatching(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWIFIMONITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD StartWatching(nsIWifiListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartWatching(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD StopWatching(nsIWifiListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopWatching(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWifiMonitor : public nsIWifiMonitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWIFIMONITOR

  nsWifiMonitor();

private:
  ~nsWifiMonitor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWifiMonitor, nsIWifiMonitor)

nsWifiMonitor::nsWifiMonitor()
{
  /* member initializers and constructor code */
}

nsWifiMonitor::~nsWifiMonitor()
{
  /* destructor code */
}

/* void startWatching (in nsIWifiListener aListener); */
NS_IMETHODIMP nsWifiMonitor::StartWatching(nsIWifiListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopWatching (in nsIWifiListener aListener); */
NS_IMETHODIMP nsWifiMonitor::StopWatching(nsIWifiListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWifiMonitor_h__ */
