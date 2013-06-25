/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/uriloader/exthandler/nsIHelperAppLauncherDialog.idl
 */

#ifndef __gen_nsIHelperAppLauncherDialog_h__
#define __gen_nsIHelperAppLauncherDialog_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHelperAppLauncher; /* forward declaration */

class nsILocalFile; /* forward declaration */


/* starting interface:    nsIHelperAppLauncherDialog */
#define NS_IHELPERAPPLAUNCHERDIALOG_IID_STR "f3704fdc-8ae6-4eba-a3c3-f02958ac0649"

#define NS_IHELPERAPPLAUNCHERDIALOG_IID \
  {0xf3704fdc, 0x8ae6, 0x4eba, \
    { 0xa3, 0xc3, 0xf0, 0x29, 0x58, 0xac, 0x06, 0x49 }}

/**
 * This interface is used to display a confirmatino dialog before
 * launching a "helper app" to handle content not handled by
 * Mozilla.
 *
 * Usage:  Clients (of which there is one: the nsIExternalHelperAppService
 * implementation in mozilla/uriloader/exthandler) create an instance of
 * this interface (using the contract ID) and then call the show() method.
 *
 * The dialog is shown non-modally.  The implementation of the dialog
 * will access methods of the nsIHelperAppLauncher passed in to show()
 * in order to cause a "save to disk" or "open using" action.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIHelperAppLauncherDialog : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHELPERAPPLAUNCHERDIALOG_IID)

  /**
   * This request is passed to the helper app dialog because Gecko can not
   * handle content of this type.
   */
  enum { REASON_CANTHANDLE = 0U };

  /**
   * The server requested external handling.
   */
  enum { REASON_SERVERREQUEST = 1U };

  /**
   * Gecko detected that the type sent by the server (e.g. text/plain) does
   * not match the actual type.
   */
  enum { REASON_TYPESNIFFED = 2U };

  /**
   * Show confirmation dialog for launching application (or "save to
   * disk") for content specified by aLauncher.
   *
   * @param aLauncher
   *        A nsIHelperAppLauncher to be invoked when a file is selected.
   * @param aWindowContext
   *        Window associated with action.
   * @param aReason
   *        One of the constants from above. It indicates why the dialog is
   *        shown. Implementors should treat unknown reasons like
   *        REASON_CANTHANDLE.
   */
  /* void show (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in unsigned long aReason); */
  NS_SCRIPTABLE NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, PRUint32 aReason) = 0;

  /**
   * Invoke a save-to-file dialog instead of the full fledged helper app dialog.
   * Returns the a nsILocalFile for the file name/location selected.
   *
   * @param aLauncher
   *        A nsIHelperAppLauncher to be invoked when a file is selected.
   * @param aWindowContext
   *        Window associated with action.
   * @param aDefaultFileName
   *        Default file name to provide (can be null)
   * @param aSuggestedFileExtension
   *        Sugested file extension
   * @param aForcePrompt
   *        Set to true to force prompting the user for thet file
   *        name/location, otherwise perferences may control if the user is
   *        prompted.
   */
  /* nsILocalFile promptForSaveToFile (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in wstring aDefaultFileName, in wstring aSuggestedFileExtension, in boolean aForcePrompt); */
  NS_SCRIPTABLE NS_IMETHOD PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar *aDefaultFileName, const PRUnichar *aSuggestedFileExtension, PRBool aForcePrompt, nsILocalFile **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHelperAppLauncherDialog, NS_IHELPERAPPLAUNCHERDIALOG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHELPERAPPLAUNCHERDIALOG \
  NS_SCRIPTABLE NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, PRUint32 aReason); \
  NS_SCRIPTABLE NS_IMETHOD PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar *aDefaultFileName, const PRUnichar *aSuggestedFileExtension, PRBool aForcePrompt, nsILocalFile **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHELPERAPPLAUNCHERDIALOG(_to) \
  NS_SCRIPTABLE NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, PRUint32 aReason) { return _to Show(aLauncher, aWindowContext, aReason); } \
  NS_SCRIPTABLE NS_IMETHOD PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar *aDefaultFileName, const PRUnichar *aSuggestedFileExtension, PRBool aForcePrompt, nsILocalFile **_retval NS_OUTPARAM) { return _to PromptForSaveToFile(aLauncher, aWindowContext, aDefaultFileName, aSuggestedFileExtension, aForcePrompt, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHELPERAPPLAUNCHERDIALOG(_to) \
  NS_SCRIPTABLE NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, PRUint32 aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(aLauncher, aWindowContext, aReason); } \
  NS_SCRIPTABLE NS_IMETHOD PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar *aDefaultFileName, const PRUnichar *aSuggestedFileExtension, PRBool aForcePrompt, nsILocalFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptForSaveToFile(aLauncher, aWindowContext, aDefaultFileName, aSuggestedFileExtension, aForcePrompt, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHelperAppLauncherDialog : public nsIHelperAppLauncherDialog
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHELPERAPPLAUNCHERDIALOG

  nsHelperAppLauncherDialog();

private:
  ~nsHelperAppLauncherDialog();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHelperAppLauncherDialog, nsIHelperAppLauncherDialog)

nsHelperAppLauncherDialog::nsHelperAppLauncherDialog()
{
  /* member initializers and constructor code */
}

nsHelperAppLauncherDialog::~nsHelperAppLauncherDialog()
{
  /* destructor code */
}

/* void show (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in unsigned long aReason); */
NS_IMETHODIMP nsHelperAppLauncherDialog::Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, PRUint32 aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsILocalFile promptForSaveToFile (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in wstring aDefaultFileName, in wstring aSuggestedFileExtension, in boolean aForcePrompt); */
NS_IMETHODIMP nsHelperAppLauncherDialog::PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar *aDefaultFileName, const PRUnichar *aSuggestedFileExtension, PRBool aForcePrompt, nsILocalFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_IHELPERAPPLAUNCHERDLG_CONTRACTID    "@mozilla.org/helperapplauncherdialog;1"
#define NS_IHELPERAPPLAUNCHERDLG_CLASSNAME "Mozilla Helper App Launcher Confirmation Dialog"

#endif /* __gen_nsIHelperAppLauncherDialog_h__ */
