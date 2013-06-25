/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/windowwatcher/public/nsINonBlockingAlertService.idl
 */

#ifndef __gen_nsINonBlockingAlertService_h__
#define __gen_nsINonBlockingAlertService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsINonBlockingAlertService */
#define NS_INONBLOCKINGALERTSERVICE_IID_STR "e800ef97-ae37-46b7-a46c-31fbe79657ea"

#define NS_INONBLOCKINGALERTSERVICE_IID \
  {0xe800ef97, 0xae37, 0x46b7, \
    { 0xa4, 0x6c, 0x31, 0xfb, 0xe7, 0x96, 0x57, 0xea }}

/**
 * This is the interface to the embeddable non-blocking alert
 * service.  A non-blocking alert is a less serious informative alert
 * that does not need to block the program's execution to get the
 * user's response.
 *
 * The way to present the alert is left to the implementations.  It
 * may be a dialog separate from the parent window, or a window-modal
 * sheet (as the ones in Mac OS X) attached to the parent.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINonBlockingAlertService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INONBLOCKINGALERTSERVICE_IID)

  /**
   * This shows a non-blocking alert with the specified title and
   * message text. This function requires a valid parent window with
   * which the alert is associated.
   *
   * @param aParent
   *        The parent window. This must not be null.
   * @param aDialogTitle
   *        Text to appear in the title of the alert.
   * @param aText
   *        Text to appear in the body of the alert.
   */
  /* void showNonBlockingAlert (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText); */
  NS_SCRIPTABLE NS_IMETHOD ShowNonBlockingAlert(nsIDOMWindow *aParent, const PRUnichar *aDialogTitle, const PRUnichar *aText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINonBlockingAlertService, NS_INONBLOCKINGALERTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINONBLOCKINGALERTSERVICE \
  NS_SCRIPTABLE NS_IMETHOD ShowNonBlockingAlert(nsIDOMWindow *aParent, const PRUnichar *aDialogTitle, const PRUnichar *aText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINONBLOCKINGALERTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowNonBlockingAlert(nsIDOMWindow *aParent, const PRUnichar *aDialogTitle, const PRUnichar *aText) { return _to ShowNonBlockingAlert(aParent, aDialogTitle, aText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINONBLOCKINGALERTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowNonBlockingAlert(nsIDOMWindow *aParent, const PRUnichar *aDialogTitle, const PRUnichar *aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowNonBlockingAlert(aParent, aDialogTitle, aText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNonBlockingAlertService : public nsINonBlockingAlertService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINONBLOCKINGALERTSERVICE

  nsNonBlockingAlertService();

private:
  ~nsNonBlockingAlertService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNonBlockingAlertService, nsINonBlockingAlertService)

nsNonBlockingAlertService::nsNonBlockingAlertService()
{
  /* member initializers and constructor code */
}

nsNonBlockingAlertService::~nsNonBlockingAlertService()
{
  /* destructor code */
}

/* void showNonBlockingAlert (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText); */
NS_IMETHODIMP nsNonBlockingAlertService::ShowNonBlockingAlert(nsIDOMWindow *aParent, const PRUnichar *aDialogTitle, const PRUnichar *aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINonBlockingAlertService_h__ */
