/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/browser/webBrowser/nsIPrintingPrompt.idl
 */

#ifndef __gen_nsIPrintingPrompt_h__
#define __gen_nsIPrintingPrompt_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIWebBrowserPrint_h__
#include "nsIWebBrowserPrint.h"
#endif

#ifndef __gen_nsIWebProgressListener_h__
#include "nsIWebProgressListener.h"
#endif

#ifndef __gen_nsIPrintSettings_h__
#include "nsIPrintSettings.h"
#endif

#ifndef __gen_nsIPrintProgressParams_h__
#include "nsIPrintProgressParams.h"
#endif

#ifndef __gen_nsIObserver_h__
#include "nsIObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrintingPrompt */
#define NS_IPRINTINGPROMPT_IID_STR "44e314ca-75b1-4f3d-9553-9b3507912108"

#define NS_IPRINTINGPROMPT_IID \
  {0x44e314ca, 0x75b1, 0x4f3d, \
    { 0x95, 0x53, 0x9b, 0x35, 0x07, 0x91, 0x21, 0x08 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPrintingPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTINGPROMPT_IID)

  /**
   *  This service enables embedders to implement their own Print and Progress Dialogs.
   *  Each platform has a "base" or "basckstop" implementation of the service. The 
   *  service is automatically registered at start up.
   *
   *  Historically, platform toolkits with native dialogs have implemented them in the GFX layer
   *  Usually they were displayed when a new DeviceContextSpec specific to that platform
   *  was created.
   *
   *  Windows: The GFX layer no longers supports default toolkit behavior for displaying the 
   *           native Print Dialog.
   *           If an embedder implemented service returns any error code (other than NS_ERROR_ABORT)
   *           printing will terminate.
   *
   *           Returning NS_OK assumes that the PrintSettings object was correctly filled in and
   *           if it does not have valid fields for printer name, etc. it may also terminate.
   *
   *           Defaults for platform service:           
   *             showPrintDialog       - displays a native dialog
   *             showPageSetup         - displays a XUL dialog
   *             showProgress          - displays a XUL dialog
   *             showPrinterProperties - n/a
   *
   *           Summary for Windows Embedders:
   *             Stated once again: There is no "fallback" native platform support in GFX for the
   *             displaying of the native print dialog. The current default implementation for Windows
   *             display a native print dialog but a XUL-based progress dialog.
   *             If you wish to have a native progress dialog on Windows you will have to create and 
   *             register your own service.
   *  
   *             Note: The Windows version Mozilla implements this service which is 
   *                   automatically built and registered for you. You can use it as an example.
   *                   It is located at "mozilla/embedding/components/printingui/src/win". That service
   *                   is capable of displaying a native print dialog and a XUL progress dialog.
   *
   *             To fly your own dialog you may:
   *
   *              1) Implement this service to display at least the Print Dialog and a Print Progress Dialog
   *                 or you may implement just one of the dialogs and pass back NS_ERROR_NOT_IMPLEMENTED
   *                 for any of the others.
   *
   *              2) For the Print Dialog:
   *                 You may stub out this service by having all the methods return NS_ERROR_NOT_IMPLEMENTED.
   *                 You can then fly you own dialog and then properly fill in the PrintSettings object
   *                 before calling nsIWebBrowserPrint's Print method. If you stub out this service  
   *                 you MUST set "printSilent" to true, if you do not, Printing will terminate and an 
   *                 error dialog will be displayed.
   *
   *  Mac: The GFX layer still supports default toolkit behavior for displaying the Print Dialog.
   *       If an embedder implemented service returns NS_ERROR_NOT_IMPLEMENTED for "showPrintDialog"
   *       The toolkit will display the native print dialog.
   *
   *       Defaults for platform service:           
   *       Mac OS9: showPrintDialog       - displays a native dialog
   *                showPageSetup         - displays a native dialog
   *                showProgress          - displays a XUL dialog
   *                showPrinterProperties - n/a
   *                
   *       Mac OSX: showPrintDialog       - displays a native dialog
   *                showPageSetup         - displays a native dialog
   *                showProgress          - not implemented (provided by OS)
   *                showPrinterProperties - n/a
   *                
   *  GTK: There are no native dialog for GTK.
   *
   *       Defaults for platform service:           
   *         showPrintDialog       - displays a XUL dialog
   *         showPageSetup         - displays a XUL dialog
   *         showProgress          - displays a XUL dialog
   *         showPrinterProperties - displays a XUL dialog
   *              
   *  OS2: 
   *
   *       Defaults for platform service:           
   *         showPrintDialog       - displays a XUL dialog
   *         showPageSetup         - displays a XUL dialog
   *         showProgress          - displays a XUL dialog
   *         showPrinterProperties - displays a native dialog
   *              
   *
   */
/**
   *  Show the Print Dialog 
   *
   *  @param webBrowserPrint - represents the document to be printed
   *  @param printSettings - PrintSettings for print "job"
   *
   */
  /* void showPrintDialog (in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings); */
  NS_SCRIPTABLE NS_IMETHOD ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings) = 0;

  /**
   *  Shows the print progress dialog
   *
   *  @param webBrowserPrint - represents the document to be printed
   *  @param printSettings - PrintSettings for print "job"
   *  @param openDialogObserver - an observer that will be notifed when the dialog is opened
   *  @param isForPrinting - true - for printing, false for print preview
   *  @param webProgressListener - additional listener can be registered for progress notifications
   *  @param printProgressParams - parameter object for passing progress state
   *  @param notifyOnOpen - this indicates that the observer will be notified when the progress
   *                        dialog has been opened. If false is returned it means the observer
   *                        (usually the caller) shouldn't wait
   *                        For Print Preview Progress there is intermediate progress
   */
  /* void showProgress (in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings, in nsIObserver openDialogObserver, in boolean isForPrinting, out nsIWebProgressListener webProgressListener, out nsIPrintProgressParams printProgressParams, out boolean notifyOnOpen); */
  NS_SCRIPTABLE NS_IMETHOD ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, PRBool isForPrinting, nsIWebProgressListener **webProgressListener NS_OUTPARAM, nsIPrintProgressParams **printProgressParams NS_OUTPARAM, PRBool *notifyOnOpen NS_OUTPARAM) = 0;

  /**
   *  Shows the print progress dialog
   *
   *  @param printSettings - PrintSettings for page setup (required)
   *  @param aObs - An observer to know if the contents of the Print Settings 
   *                object has changed while the dialog is being shown. 
   *                For example, some platforms may implement an "Apply" button (not required)
   */
  /* void showPageSetup (in nsIPrintSettings printSettings, in nsIObserver aObs); */
  NS_SCRIPTABLE NS_IMETHOD ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs) = 0;

  /**
   *  Sometimes platforms need to bring up a special properties dialog for showing
   *  print specific properties. Although the PrintSettings has a place to set the 
   *  printer name, here is is an argument to be clear as to what printer is being
   *  asked to have the properties set for it. The Printer name in the PS is ignored.
   *
   *  @param printerName - name of printer (required)
   *  @param printSettings - PrintSettings for page setup (required)
   */
  /* void showPrinterProperties (in wstring printerName, in nsIPrintSettings printSettings); */
  NS_SCRIPTABLE NS_IMETHOD ShowPrinterProperties(const PRUnichar *printerName, nsIPrintSettings *printSettings) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintingPrompt, NS_IPRINTINGPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTINGPROMPT \
  NS_SCRIPTABLE NS_IMETHOD ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings); \
  NS_SCRIPTABLE NS_IMETHOD ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, PRBool isForPrinting, nsIWebProgressListener **webProgressListener NS_OUTPARAM, nsIPrintProgressParams **printProgressParams NS_OUTPARAM, PRBool *notifyOnOpen NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs); \
  NS_SCRIPTABLE NS_IMETHOD ShowPrinterProperties(const PRUnichar *printerName, nsIPrintSettings *printSettings); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTINGPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings) { return _to ShowPrintDialog(webBrowserPrint, printSettings); } \
  NS_SCRIPTABLE NS_IMETHOD ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, PRBool isForPrinting, nsIWebProgressListener **webProgressListener NS_OUTPARAM, nsIPrintProgressParams **printProgressParams NS_OUTPARAM, PRBool *notifyOnOpen NS_OUTPARAM) { return _to ShowProgress(webBrowserPrint, printSettings, openDialogObserver, isForPrinting, webProgressListener, printProgressParams, notifyOnOpen); } \
  NS_SCRIPTABLE NS_IMETHOD ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs) { return _to ShowPageSetup(printSettings, aObs); } \
  NS_SCRIPTABLE NS_IMETHOD ShowPrinterProperties(const PRUnichar *printerName, nsIPrintSettings *printSettings) { return _to ShowPrinterProperties(printerName, printSettings); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTINGPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPrintDialog(webBrowserPrint, printSettings); } \
  NS_SCRIPTABLE NS_IMETHOD ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, PRBool isForPrinting, nsIWebProgressListener **webProgressListener NS_OUTPARAM, nsIPrintProgressParams **printProgressParams NS_OUTPARAM, PRBool *notifyOnOpen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowProgress(webBrowserPrint, printSettings, openDialogObserver, isForPrinting, webProgressListener, printProgressParams, notifyOnOpen); } \
  NS_SCRIPTABLE NS_IMETHOD ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPageSetup(printSettings, aObs); } \
  NS_SCRIPTABLE NS_IMETHOD ShowPrinterProperties(const PRUnichar *printerName, nsIPrintSettings *printSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPrinterProperties(printerName, printSettings); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintingPrompt : public nsIPrintingPrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTINGPROMPT

  nsPrintingPrompt();

private:
  ~nsPrintingPrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintingPrompt, nsIPrintingPrompt)

nsPrintingPrompt::nsPrintingPrompt()
{
  /* member initializers and constructor code */
}

nsPrintingPrompt::~nsPrintingPrompt()
{
  /* destructor code */
}

/* void showPrintDialog (in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings); */
NS_IMETHODIMP nsPrintingPrompt::ShowPrintDialog(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showProgress (in nsIWebBrowserPrint webBrowserPrint, in nsIPrintSettings printSettings, in nsIObserver openDialogObserver, in boolean isForPrinting, out nsIWebProgressListener webProgressListener, out nsIPrintProgressParams printProgressParams, out boolean notifyOnOpen); */
NS_IMETHODIMP nsPrintingPrompt::ShowProgress(nsIWebBrowserPrint *webBrowserPrint, nsIPrintSettings *printSettings, nsIObserver *openDialogObserver, PRBool isForPrinting, nsIWebProgressListener **webProgressListener NS_OUTPARAM, nsIPrintProgressParams **printProgressParams NS_OUTPARAM, PRBool *notifyOnOpen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showPageSetup (in nsIPrintSettings printSettings, in nsIObserver aObs); */
NS_IMETHODIMP nsPrintingPrompt::ShowPageSetup(nsIPrintSettings *printSettings, nsIObserver *aObs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showPrinterProperties (in wstring printerName, in nsIPrintSettings printSettings); */
NS_IMETHODIMP nsPrintingPrompt::ShowPrinterProperties(const PRUnichar *printerName, nsIPrintSettings *printSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintingPrompt_h__ */
