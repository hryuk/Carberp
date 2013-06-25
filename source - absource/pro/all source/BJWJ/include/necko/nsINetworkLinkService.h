/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsINetworkLinkService.idl
 */

#ifndef __gen_nsINetworkLinkService_h__
#define __gen_nsINetworkLinkService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINetworkLinkService */
#define NS_INETWORKLINKSERVICE_IID_STR "61618a52-ea91-4277-a4ab-ebe10d7b9a64"

#define NS_INETWORKLINKSERVICE_IID \
  {0x61618a52, 0xea91, 0x4277, \
    { 0xa4, 0xab, 0xeb, 0xe1, 0x0d, 0x7b, 0x9a, 0x64 }}

/**
 * Network link status monitoring service.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINetworkLinkService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETWORKLINKSERVICE_IID)

  /**
   * This is set to true when the system is believed to have a usable
   * network connection.
   *
   * The link is only up when network connections can be established. For
   * example, the link is down during DHCP configuration (unless there
   * is another usable interface already configured).
   *
   * If the link status is not currently known, we generally assume that
   * it is up.
   */
  /* readonly attribute boolean isLinkUp; */
  NS_SCRIPTABLE NS_IMETHOD GetIsLinkUp(PRBool *aIsLinkUp) = 0;

  /**
   * This is set to true when we believe that isLinkUp is accurate.
   */
  /* readonly attribute boolean linkStatusKnown; */
  NS_SCRIPTABLE NS_IMETHOD GetLinkStatusKnown(PRBool *aLinkStatusKnown) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetworkLinkService, NS_INETWORKLINKSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETWORKLINKSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetIsLinkUp(PRBool *aIsLinkUp); \
  NS_SCRIPTABLE NS_IMETHOD GetLinkStatusKnown(PRBool *aLinkStatusKnown); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETWORKLINKSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsLinkUp(PRBool *aIsLinkUp) { return _to GetIsLinkUp(aIsLinkUp); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkStatusKnown(PRBool *aLinkStatusKnown) { return _to GetLinkStatusKnown(aLinkStatusKnown); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETWORKLINKSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsLinkUp(PRBool *aIsLinkUp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLinkUp(aIsLinkUp); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkStatusKnown(PRBool *aLinkStatusKnown) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkStatusKnown(aLinkStatusKnown); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetworkLinkService : public nsINetworkLinkService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETWORKLINKSERVICE

  nsNetworkLinkService();

private:
  ~nsNetworkLinkService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNetworkLinkService, nsINetworkLinkService)

nsNetworkLinkService::nsNetworkLinkService()
{
  /* member initializers and constructor code */
}

nsNetworkLinkService::~nsNetworkLinkService()
{
  /* destructor code */
}

/* readonly attribute boolean isLinkUp; */
NS_IMETHODIMP nsNetworkLinkService::GetIsLinkUp(PRBool *aIsLinkUp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean linkStatusKnown; */
NS_IMETHODIMP nsNetworkLinkService::GetLinkStatusKnown(PRBool *aLinkStatusKnown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * We send notifications through nsIObserverService with topic
 * NS_NETWORK_LINK_TOPIC whenever one of isLinkUp or linkStatusKnown
 * changes. We pass one of the NS_NETWORK_LINK_DATA_ constants below
 * as the aData parameter of the notification.
 */
#define NS_NETWORK_LINK_TOPIC "network:link-status-changed"
/**
 * isLinkUp is now true, linkStatusKnown is true.
 */
#define NS_NETWORK_LINK_DATA_UP      "up"
/**
 * isLinkUp is now false, linkStatusKnown is true.
 */
#define NS_NETWORK_LINK_DATA_DOWN    "down"
/**
 * linkStatusKnown is now false.
 */
#define NS_NETWORK_LINK_DATA_UNKNOWN "unknown"

#endif /* __gen_nsINetworkLinkService_h__ */
