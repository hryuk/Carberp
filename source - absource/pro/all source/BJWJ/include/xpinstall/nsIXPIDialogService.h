/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpinstall/public/nsIXPIDialogService.idl
 */

#ifndef __gen_nsIXPIDialogService_h__
#define __gen_nsIXPIDialogService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIXPIProgressDialog; /* forward declaration */

class nsIObserver; /* forward declaration */


/* starting interface:    nsIXPIDialogService */
#define NS_IXPIDIALOGSERVICE_IID_STR "8cdd8baa-1dd2-11b2-909a-f0178da5c5ff"

#define NS_IXPIDIALOGSERVICE_IID \
  {0x8cdd8baa, 0x1dd2, 0x11b2, \
    { 0x90, 0x9a, 0xf0, 0x17, 0x8d, 0xa5, 0xc5, 0xff }}

/**
 * A service provided by embedding applications to override
 * the default XUL implmementation of XPInstall dialogs.
 *
 * Embedding applications which wish to override the default
 * XUL dialogs need to create a component which implements
 * this interface and registers with the Contract ID
 * "@mozilla.org/embedui/xpinstall-dialog-service;1"
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPIDialogService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPIDIALOGSERVICE_IID)

  /**
     * @brief  Ask the user if it's OK to install
     *
     * When called the XPIDialogService implementation should pose an
     * install confirmation dialog and return the user's response
     *
     * @param parent        a window that can be used to parent the modal dialog
     *
     * @param packageList   For each install package there will be three strings,
     *                      a display name, a source URL, and a the name of the
     *                      organization that signed this install.  Note that the
     *                      name of the signer is not verified.  Verification
     *                      happens when the the install has completely downloaded.
     *                      Your user interface should only suggest that the 
     *                      install may be signed by this organization name.
     *                      Note that an unsigned archive is indicated by an 
     *                      empty string.   
     *
     * @param count         The number of strings in the packageList. This
     *                      will always be three times the number of 
     *                      packages.
     *
     * @return true to install, false to cancel
     */
  /* boolean confirmInstall (in nsIDOMWindow parent, [array, size_is (count)] in wstring packageList, in unsigned long count); */
  NS_SCRIPTABLE NS_IMETHOD ConfirmInstall(nsIDOMWindow *parent, const PRUnichar **packageList, PRUint32 count, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * @brief Create and open a download-and-install progress dialog
     *
     * When called the XPIDialogService implementation creates and opens
     * a dialog to display the status of the install. When the dialog
     * is ready to be used then the observer must be called: the subject
     * is an nsIXPIProgressDialog that nsXPInstallManager can use to control
     * the dialog, the topic is "xpinstall-progress"  and the data is "open".
     *
     * If the user wishes to cancel the download, the dialog can call the
     * observe method with the same subject and topic and the data "cancel".
     *
     * @note Unless this routine throws an exception the observer <b>must</b>
     * be called or nsXPInstallManager will wait forever and never clean
     * itself up.
     *
     * @param packageList   three strings per package as in confirmInstall()
     * @param count         the number of strings in the list
     * @param observer      nsIObserver to receive messages from the dialog
     */
  /* void openProgressDialog ([array, size_is (count)] in wstring packageList, in unsigned long count, in nsIObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD OpenProgressDialog(const PRUnichar **packageList, PRUint32 count, nsIObserver *observer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPIDialogService, NS_IXPIDIALOGSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPIDIALOGSERVICE \
  NS_SCRIPTABLE NS_IMETHOD ConfirmInstall(nsIDOMWindow *parent, const PRUnichar **packageList, PRUint32 count, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenProgressDialog(const PRUnichar **packageList, PRUint32 count, nsIObserver *observer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPIDIALOGSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConfirmInstall(nsIDOMWindow *parent, const PRUnichar **packageList, PRUint32 count, PRBool *_retval NS_OUTPARAM) { return _to ConfirmInstall(parent, packageList, count, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenProgressDialog(const PRUnichar **packageList, PRUint32 count, nsIObserver *observer) { return _to OpenProgressDialog(packageList, count, observer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPIDIALOGSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConfirmInstall(nsIDOMWindow *parent, const PRUnichar **packageList, PRUint32 count, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmInstall(parent, packageList, count, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenProgressDialog(const PRUnichar **packageList, PRUint32 count, nsIObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenProgressDialog(packageList, count, observer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPIDialogService : public nsIXPIDialogService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPIDIALOGSERVICE

  nsXPIDialogService();

private:
  ~nsXPIDialogService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPIDialogService, nsIXPIDialogService)

nsXPIDialogService::nsXPIDialogService()
{
  /* member initializers and constructor code */
}

nsXPIDialogService::~nsXPIDialogService()
{
  /* destructor code */
}

/* boolean confirmInstall (in nsIDOMWindow parent, [array, size_is (count)] in wstring packageList, in unsigned long count); */
NS_IMETHODIMP nsXPIDialogService::ConfirmInstall(nsIDOMWindow *parent, const PRUnichar **packageList, PRUint32 count, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openProgressDialog ([array, size_is (count)] in wstring packageList, in unsigned long count, in nsIObserver observer); */
NS_IMETHODIMP nsXPIDialogService::OpenProgressDialog(const PRUnichar **packageList, PRUint32 count, nsIObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPIDialogService_h__ */
