/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/alerts/public/nsIAlertsService.idl
 */

#ifndef __gen_nsIAlertsService_h__
#define __gen_nsIAlertsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIObserver_h__
#include "nsIObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAlertsService */
#define NS_IALERTSSERVICE_IID_STR "e177399e-2e31-4019-aed3-cba63ce9fa99"

#define NS_IALERTSSERVICE_IID \
  {0xe177399e, 0x2e31, 0x4019, \
    { 0xae, 0xd3, 0xcb, 0xa6, 0x3c, 0xe9, 0xfa, 0x99 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAlertsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IALERTSSERVICE_IID)

  /**
    * Displays a sliding notification window.
    *    
    * @param imageUrl       A URL identifying the image to put in the alert.
    * @param title          The title for the alert.
    * @param text           The contents of the alert.
    * @param textClickable  If true, causes the alert text to look like a link
    *                       and notifies the listener when user attempts to 
    *                       click the alert text.
    * @param cookie         A blind cookie the alert will pass back to the 
    *                       consumer during the alert listener callbacks.
    * @param alertListener  Used for callbacks. May be null if the caller 
    *                       doesn't care about callbacks.
    * @param name           The name of the notification.  This is currently
    *                       only used on OS X with Growl.  On OS X with Growl,
    *                       users can disable notifications with a given name.
    *
    * @throws NS_ERROR_NOT_AVAILABLE If the notification cannot be displayed.
    *
    * The following arguments will be passed to the alertListener's observe() 
    * method:
    *   subject - null
    *   topic   - "alertfinished" when the alert goes away
    *             "alertclickcallback" when the text is clicked
    *   data    - the value of the cookie parameter passed to showAlertNotification.
    */
  /* void showAlertNotification (in AString imageUrl, in AString title, in AString text, [optional] in boolean textClickable, [optional] in AString cookie, [optional] in nsIObserver alertListener, [optional] in AString name); */
  NS_SCRIPTABLE NS_IMETHOD ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, PRBool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAlertsService, NS_IALERTSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIALERTSSERVICE \
  NS_SCRIPTABLE NS_IMETHOD ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, PRBool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIALERTSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, PRBool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name) { return _to ShowAlertNotification(imageUrl, title, text, textClickable, cookie, alertListener, name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIALERTSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, PRBool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowAlertNotification(imageUrl, title, text, textClickable, cookie, alertListener, name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAlertsService : public nsIAlertsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIALERTSSERVICE

  nsAlertsService();

private:
  ~nsAlertsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAlertsService, nsIAlertsService)

nsAlertsService::nsAlertsService()
{
  /* member initializers and constructor code */
}

nsAlertsService::~nsAlertsService()
{
  /* destructor code */
}

/* void showAlertNotification (in AString imageUrl, in AString title, in AString text, [optional] in boolean textClickable, [optional] in AString cookie, [optional] in nsIObserver alertListener, [optional] in AString name); */
NS_IMETHODIMP nsAlertsService::ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, PRBool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAlertsService_h__ */
