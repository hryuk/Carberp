/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/downloads/public/nsIDownloadManagerUI.idl
 */

#ifndef __gen_nsIDownloadManagerUI_h__
#define __gen_nsIDownloadManagerUI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIDownloadManagerUI */
#define NS_IDOWNLOADMANAGERUI_IID_STR "ca7663d5-69e3-4c4a-b754-f462bd36b05f"

#define NS_IDOWNLOADMANAGERUI_IID \
  {0xca7663d5, 0x69e3, 0x4c4a, \
    { 0xb7, 0x54, 0xf4, 0x62, 0xbd, 0x36, 0xb0, 0x5f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDownloadManagerUI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADMANAGERUI_IID)

  /**
   * The reason that should be passed when the user requests to show the
   * download manager's UI.
   */
  enum { REASON_USER_INTERACTED = 0 };

  /**
   * The reason that should be passed to the show method when we are displaying
   * the UI because a new download is being added to it.
   */
  enum { REASON_NEW_DOWNLOAD = 1 };

  /**
  * Shows the Download Manager's UI to the user.
  *
  * @param [optional] aWindowContext
  *        The parent window context to show the UI.
  * @param [optional] aID
  *        The id of the download to be preselected upon opening.
  * @param [optional] aReason
  *        The reason to show the download manager's UI.  This defaults to
  *        REASON_USER_INTERACTED, and should be one of the previously listed
  *        constants.
  */
  /* void show ([optional] in nsIInterfaceRequestor aWindowContext, [optional] in unsigned long aID, [optional] in short aReason); */
  NS_SCRIPTABLE NS_IMETHOD Show(nsIInterfaceRequestor *aWindowContext, PRUint32 aID, PRInt16 aReason) = 0;

  /**
  * Indicates if the UI is visible or not.
  */
  /* readonly attribute boolean visible; */
  NS_SCRIPTABLE NS_IMETHOD GetVisible(PRBool *aVisible) = 0;

  /**
  * Brings attention to the UI if it is already visible
  *
  * @throws NS_ERROR_UNEXPECTED if the UI is not visible.
  */
  /* void getAttention (); */
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloadManagerUI, NS_IDOWNLOADMANAGERUI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADMANAGERUI \
  NS_SCRIPTABLE NS_IMETHOD Show(nsIInterfaceRequestor *aWindowContext, PRUint32 aID, PRInt16 aReason); \
  NS_SCRIPTABLE NS_IMETHOD GetVisible(PRBool *aVisible); \
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADMANAGERUI(_to) \
  NS_SCRIPTABLE NS_IMETHOD Show(nsIInterfaceRequestor *aWindowContext, PRUint32 aID, PRInt16 aReason) { return _to Show(aWindowContext, aID, aReason); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisible(PRBool *aVisible) { return _to GetVisible(aVisible); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void) { return _to GetAttention(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADMANAGERUI(_to) \
  NS_SCRIPTABLE NS_IMETHOD Show(nsIInterfaceRequestor *aWindowContext, PRUint32 aID, PRInt16 aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(aWindowContext, aID, aReason); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisible(PRBool *aVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisible(aVisible); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttention(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloadManagerUI : public nsIDownloadManagerUI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADMANAGERUI

  nsDownloadManagerUI();

private:
  ~nsDownloadManagerUI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownloadManagerUI, nsIDownloadManagerUI)

nsDownloadManagerUI::nsDownloadManagerUI()
{
  /* member initializers and constructor code */
}

nsDownloadManagerUI::~nsDownloadManagerUI()
{
  /* destructor code */
}

/* void show ([optional] in nsIInterfaceRequestor aWindowContext, [optional] in unsigned long aID, [optional] in short aReason); */
NS_IMETHODIMP nsDownloadManagerUI::Show(nsIInterfaceRequestor *aWindowContext, PRUint32 aID, PRInt16 aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean visible; */
NS_IMETHODIMP nsDownloadManagerUI::GetVisible(PRBool *aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttention (); */
NS_IMETHODIMP nsDownloadManagerUI::GetAttention()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDownloadManagerUI_h__ */
