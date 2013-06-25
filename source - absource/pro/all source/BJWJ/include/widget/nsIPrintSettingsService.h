/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIPrintSettingsService.idl
 */

#ifndef __gen_nsIPrintSettingsService_h__
#define __gen_nsIPrintSettingsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrintSettings; /* forward declaration */


/* starting interface:    nsIPrintSettingsService */
#define NS_IPRINTSETTINGSSERVICE_IID_STR "841387c8-72e6-484b-9296-bf6eea80d58a"

#define NS_IPRINTSETTINGSSERVICE_IID \
  {0x841387c8, 0x72e6, 0x484b, \
    { 0x92, 0x96, 0xbf, 0x6e, 0xea, 0x80, 0xd5, 0x8a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPrintSettingsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTSETTINGSSERVICE_IID)

  /**
   * Returns a "global" PrintSettings object 
   * Creates a new the first time, if one doesn't exist.
   *
   * Then returns the same object each time after that.
   *
   * Initializes the globalPrintSettings from the default printer
   */
  /* readonly attribute nsIPrintSettings globalPrintSettings; */
  NS_SCRIPTABLE NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings) = 0;

  /**
   * Returns a new, unique PrintSettings object each time.
   *
   * For example, if each browser was to have its own unique
   * PrintSettings, then each browser window would call this to
   * create its own unique PrintSettings object.
   *
   * If each browse window was to use the same PrintSettings object
   * then it should use "globalPrintSettings"
   *
   * Initializes the newPrintSettings from the default printer
   *
   */
  /* readonly attribute nsIPrintSettings newPrintSettings; */
  NS_SCRIPTABLE NS_IMETHOD GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings) = 0;

  /**
   * The name of the last printer used, or else the system default printer.
   */
  /* readonly attribute wstring defaultPrinterName; */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName) = 0;

  /**
   * Initializes certain settings from the native printer into the PrintSettings
   * if aPrinterName is null then it uses the default printer name if it can
   * These settings include, but are not limited to:
   *   Page Orientation
   *   Page Size
   *   Number of Copies
   */
  /* void initPrintSettingsFromPrinter (in wstring aPrinterName, in nsIPrintSettings aPrintSettings); */
  NS_SCRIPTABLE NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar *aPrinterName, nsIPrintSettings *aPrintSettings) = 0;

  /**
   * Reads PrintSettings values from Prefs,
   * the values to be read are indicated by the "flags" arg.
   *
   * aPrintSettings should be initialized with the name of a printer. First
   * it reads in the PrintSettings from the last print job. Then it uses the
   * PrinterName in the PrinterSettings to read any settings that were saved
   * just for that printer.
   *
   * aPS - PrintSettings to have its settings read
   * aUsePrinterNamePrefix - indicates whether to use the printer name as a prefix
   * aFlags - indicates which prefs to read, see nsIPrintSettings.idl for the
   *          const values.
   *
   * Items not read:
   *   startPageRange, endPageRange, scaling, printRange, title
   *   docURL, howToEnableFrameUI, isCancelled, printFrameTypeUsage
   *   printFrameType, printSilent, shrinkToFit, numCopies,
   *   printerName
   *
   */
  /* void initPrintSettingsFromPrefs (in nsIPrintSettings aPrintSettings, in boolean aUsePrinterNamePrefix, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags) = 0;

  /**
   * Writes PrintSettings values to Prefs, 
   * the values to be written are indicated by the "flags" arg.
   *
   * If there is no PrinterName in the PrinterSettings 
   * the values are saved as the "generic" values not associated with any printer.
   * If a PrinterName is there, then it saves the items qualified for that Printer
   *
   * aPS - PrintSettings to have its settings saved
   * aUsePrinterNamePrefix - indicates whether to use the printer name as a prefix
   * aFlags - indicates which prefs to save, see nsIPrintSettings.idl for the const values.
   *
   * Items not written:
   *   startPageRange, endPageRange, scaling, printRange, title
   *   docURL, howToEnableFrameUI, isCancelled, printFrameTypeUsage
   *   printFrameType, printSilent, shrinkToFit, numCopies
   *
   */
  /* void savePrintSettingsToPrefs (in nsIPrintSettings aPrintSettings, in boolean aUsePrinterNamePrefix, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintSettingsService, NS_IPRINTSETTINGSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTSETTINGSSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings); \
  NS_SCRIPTABLE NS_IMETHOD GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName); \
  NS_SCRIPTABLE NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar *aPrinterName, nsIPrintSettings *aPrintSettings); \
  NS_SCRIPTABLE NS_IMETHOD InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags); \
  NS_SCRIPTABLE NS_IMETHOD SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTSETTINGSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings) { return _to GetGlobalPrintSettings(aGlobalPrintSettings); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings) { return _to GetNewPrintSettings(aNewPrintSettings); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName) { return _to GetDefaultPrinterName(aDefaultPrinterName); } \
  NS_SCRIPTABLE NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar *aPrinterName, nsIPrintSettings *aPrintSettings) { return _to InitPrintSettingsFromPrinter(aPrinterName, aPrintSettings); } \
  NS_SCRIPTABLE NS_IMETHOD InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags) { return _to InitPrintSettingsFromPrefs(aPrintSettings, aUsePrinterNamePrefix, aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags) { return _to SavePrintSettingsToPrefs(aPrintSettings, aUsePrinterNamePrefix, aFlags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTSETTINGSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalPrintSettings(aGlobalPrintSettings); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewPrintSettings(aNewPrintSettings); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultPrinterName(aDefaultPrinterName); } \
  NS_SCRIPTABLE NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar *aPrinterName, nsIPrintSettings *aPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPrintSettingsFromPrinter(aPrinterName, aPrintSettings); } \
  NS_SCRIPTABLE NS_IMETHOD InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPrintSettingsFromPrefs(aPrintSettings, aUsePrinterNamePrefix, aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SavePrintSettingsToPrefs(aPrintSettings, aUsePrinterNamePrefix, aFlags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintSettingsService : public nsIPrintSettingsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTSETTINGSSERVICE

  nsPrintSettingsService();

private:
  ~nsPrintSettingsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintSettingsService, nsIPrintSettingsService)

nsPrintSettingsService::nsPrintSettingsService()
{
  /* member initializers and constructor code */
}

nsPrintSettingsService::~nsPrintSettingsService()
{
  /* destructor code */
}

/* readonly attribute nsIPrintSettings globalPrintSettings; */
NS_IMETHODIMP nsPrintSettingsService::GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrintSettings newPrintSettings; */
NS_IMETHODIMP nsPrintSettingsService::GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring defaultPrinterName; */
NS_IMETHODIMP nsPrintSettingsService::GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPrintSettingsFromPrinter (in wstring aPrinterName, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsPrintSettingsService::InitPrintSettingsFromPrinter(const PRUnichar *aPrinterName, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPrintSettingsFromPrefs (in nsIPrintSettings aPrintSettings, in boolean aUsePrinterNamePrefix, in unsigned long aFlags); */
NS_IMETHODIMP nsPrintSettingsService::InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void savePrintSettingsToPrefs (in nsIPrintSettings aPrintSettings, in boolean aUsePrinterNamePrefix, in unsigned long aFlags); */
NS_IMETHODIMP nsPrintSettingsService::SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, PRBool aUsePrinterNamePrefix, PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {841387C8-72E6-484b-9296-BF6EEA80D58A}
#define NS_PRINTSETTINGSSERVICE_IID \
 {0x841387c8, 0x72e6, 0x484b, { 0x92, 0x96, 0xbf, 0x6e, 0xea, 0x80, 0xd5, 0x8a}}

#endif /* __gen_nsIPrintSettingsService_h__ */
