/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIPrintSettings.idl
 */

#ifndef __gen_nsIPrintSettings_h__
#define __gen_nsIPrintSettings_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsMargin.h"
class nsIPrintSession; /* forward declaration */


/* starting interface:    nsIPrintSettings */
#define NS_IPRINTSETTINGS_IID_STR "5af07661-6477-4235-8814-4a45215855b8"

#define NS_IPRINTSETTINGS_IID \
  {0x5af07661, 0x6477, 0x4235, \
    { 0x88, 0x14, 0x4a, 0x45, 0x21, 0x58, 0x55, 0xb8 }}

/**
 * Simplified graphics interface for JS rendering.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPrintSettings : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTSETTINGS_IID)

  /**
   * PrintSettings to be Saved Navigation Constants
   */
  enum { kInitSaveOddEvenPages = 1U };

  enum { kInitSaveHeaderLeft = 2U };

  enum { kInitSaveHeaderCenter = 4U };

  enum { kInitSaveHeaderRight = 8U };

  enum { kInitSaveFooterLeft = 16U };

  enum { kInitSaveFooterCenter = 32U };

  enum { kInitSaveFooterRight = 64U };

  enum { kInitSaveBGColors = 128U };

  enum { kInitSaveBGImages = 256U };

  enum { kInitSavePaperSize = 512U };

  enum { kInitSavePaperData = 8192U };

  enum { kInitSaveUnwriteableMargins = 16384U };

  enum { kInitSaveEdges = 32768U };

  enum { kInitSaveReversed = 65536U };

  enum { kInitSaveInColor = 131072U };

  enum { kInitSaveOrientation = 262144U };

  enum { kInitSavePrintCommand = 524288U };

  enum { kInitSavePrinterName = 1048576U };

  enum { kInitSavePrintToFile = 2097152U };

  enum { kInitSaveToFileName = 4194304U };

  enum { kInitSavePageDelay = 8388608U };

  enum { kInitSaveMargins = 16777216U };

  enum { kInitSaveNativeData = 33554432U };

  enum { kInitSavePlexName = 67108864U };

  enum { kInitSaveShrinkToFit = 134217728U };

  enum { kInitSaveScaling = 268435456U };

  enum { kInitSaveColorspace = 536870912U };

  enum { kInitSaveResolutionName = 1073741824U };

  enum { kInitSaveDownloadFonts = 2147483648U };

  enum { kInitSaveAll = 4294967295U };

  enum { kPrintOddPages = 1 };

  enum { kPrintEvenPages = 2 };

  enum { kEnableSelectionRB = 4 };

  enum { kRangeAllPages = 0 };

  enum { kRangeSpecifiedPageRange = 1 };

  enum { kRangeSelection = 2 };

  enum { kRangeFocusFrame = 3 };

  enum { kJustLeft = 0 };

  enum { kJustCenter = 1 };

  enum { kJustRight = 2 };

  /**
   * FrameSet Default Type Constants
   */
  enum { kUseInternalDefault = 0 };

  enum { kUseSettingWhenPossible = 1 };

  /**
   * Page Size Type Constants
   */
  enum { kPaperSizeNativeData = 0 };

  enum { kPaperSizeDefined = 1 };

  /**
   * Page Size Unit Constants
   */
  enum { kPaperSizeInches = 0 };

  enum { kPaperSizeMillimeters = 1 };

  /**
   * Orientation Constants
   */
  enum { kPortraitOrientation = 0 };

  enum { kLandscapeOrientation = 1 };

  /**
   * Print Frame Constants
   */
  enum { kNoFrames = 0 };

  enum { kFramesAsIs = 1 };

  enum { kSelectedFrame = 2 };

  enum { kEachFrameSep = 3 };

  /**
   * How to Enable Frame Set Printing Constants
   */
  enum { kFrameEnableNone = 0 };

  enum { kFrameEnableAll = 1 };

  enum { kFrameEnableAsIsAndEach = 2 };

  /**
   * Output file format
   */
  enum { kOutputFormatNative = 0 };

  enum { kOutputFormatPS = 1 };

  enum { kOutputFormatPDF = 2 };

  /**
   * Set PrintOptions 
   */
  /* void SetPrintOptions (in PRInt32 aType, in PRBool aTurnOnOff); */
  NS_SCRIPTABLE NS_IMETHOD SetPrintOptions(PRInt32 aType, PRBool aTurnOnOff) = 0;

  /**
   * Get PrintOptions 
   */
  /* PRBool GetPrintOptions (in PRInt32 aType); */
  NS_SCRIPTABLE NS_IMETHOD GetPrintOptions(PRInt32 aType, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Set PrintOptions Bit field
   */
  /* PRInt32 GetPrintOptionsBits (); */
  NS_SCRIPTABLE NS_IMETHOD GetPrintOptionsBits(PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Get the page size in twips, considering the
   * orientation (portrait or landscape).
   */
  /* void GetEffectivePageSize (out double aWidth, out double aHeight); */
  NS_SCRIPTABLE NS_IMETHOD GetEffectivePageSize(double *aWidth NS_OUTPARAM, double *aHeight NS_OUTPARAM) = 0;

  /**
   * Makes a new copy
   */
  /* nsIPrintSettings clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsIPrintSettings **_retval NS_OUTPARAM) = 0;

  /**
   * Assigns the internal values from the "in" arg to the current object
   */
  /* void assign (in nsIPrintSettings aPS); */
  NS_SCRIPTABLE NS_IMETHOD Assign(nsIPrintSettings *aPS) = 0;

  /**
   * Data Members
   */
  /* [noscript] attribute nsIPrintSession printSession; */
  NS_IMETHOD GetPrintSession(nsIPrintSession * *aPrintSession) = 0;
  NS_IMETHOD SetPrintSession(nsIPrintSession * aPrintSession) = 0;

  /* attribute long startPageRange; */
  NS_SCRIPTABLE NS_IMETHOD GetStartPageRange(PRInt32 *aStartPageRange) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStartPageRange(PRInt32 aStartPageRange) = 0;

  /* attribute long endPageRange; */
  NS_SCRIPTABLE NS_IMETHOD GetEndPageRange(PRInt32 *aEndPageRange) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEndPageRange(PRInt32 aEndPageRange) = 0;

  /**
   * The edge measurements define the positioning of the headers
   * and footers on the page. They're measured as an offset from
   * the "unwriteable margin" (described below).
   */
  /* attribute double edgeTop; */
  NS_SCRIPTABLE NS_IMETHOD GetEdgeTop(double *aEdgeTop) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEdgeTop(double aEdgeTop) = 0;

  /* attribute double edgeLeft; */
  NS_SCRIPTABLE NS_IMETHOD GetEdgeLeft(double *aEdgeLeft) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEdgeLeft(double aEdgeLeft) = 0;

  /* attribute double edgeBottom; */
  NS_SCRIPTABLE NS_IMETHOD GetEdgeBottom(double *aEdgeBottom) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEdgeBottom(double aEdgeBottom) = 0;

  /* attribute double edgeRight; */
  NS_SCRIPTABLE NS_IMETHOD GetEdgeRight(double *aEdgeRight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEdgeRight(double aEdgeRight) = 0;

  /**
   * The margins define the positioning of the content on the page.
   * They're treated as an offset from the "unwriteable margin"
   * (described below).
   */
  /* attribute double marginTop; */
  NS_SCRIPTABLE NS_IMETHOD GetMarginTop(double *aMarginTop) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMarginTop(double aMarginTop) = 0;

  /* attribute double marginLeft; */
  NS_SCRIPTABLE NS_IMETHOD GetMarginLeft(double *aMarginLeft) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMarginLeft(double aMarginLeft) = 0;

  /* attribute double marginBottom; */
  NS_SCRIPTABLE NS_IMETHOD GetMarginBottom(double *aMarginBottom) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMarginBottom(double aMarginBottom) = 0;

  /* attribute double marginRight; */
  NS_SCRIPTABLE NS_IMETHOD GetMarginRight(double *aMarginRight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMarginRight(double aMarginRight) = 0;

  /**
   * The unwriteable margin defines the printable region of the paper, creating
   * an invisible border from which the edge and margin attributes are measured.
   */
  /* attribute double unwriteableMarginTop; */
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginTop(double *aUnwriteableMarginTop) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginTop(double aUnwriteableMarginTop) = 0;

  /* attribute double unwriteableMarginLeft; */
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginLeft(double aUnwriteableMarginLeft) = 0;

  /* attribute double unwriteableMarginBottom; */
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginBottom(double aUnwriteableMarginBottom) = 0;

  /* attribute double unwriteableMarginRight; */
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginRight(double *aUnwriteableMarginRight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginRight(double aUnwriteableMarginRight) = 0;

  /* attribute double scaling; */
  NS_SCRIPTABLE NS_IMETHOD GetScaling(double *aScaling) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetScaling(double aScaling) = 0;

  /* attribute boolean printBGColors; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintBGColors(PRBool *aPrintBGColors) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintBGColors(PRBool aPrintBGColors) = 0;

  /* attribute boolean printBGImages; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintBGImages(PRBool *aPrintBGImages) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintBGImages(PRBool aPrintBGImages) = 0;

  /* attribute short printRange; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintRange(PRInt16 *aPrintRange) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintRange(PRInt16 aPrintRange) = 0;

  /* attribute wstring title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(PRUnichar * *aTitle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const PRUnichar * aTitle) = 0;

  /* attribute wstring docURL; */
  NS_SCRIPTABLE NS_IMETHOD GetDocURL(PRUnichar * *aDocURL) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocURL(const PRUnichar * aDocURL) = 0;

  /* attribute wstring headerStrLeft; */
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrLeft(PRUnichar * *aHeaderStrLeft) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrLeft(const PRUnichar * aHeaderStrLeft) = 0;

  /* attribute wstring headerStrCenter; */
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrCenter(PRUnichar * *aHeaderStrCenter) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrCenter(const PRUnichar * aHeaderStrCenter) = 0;

  /* attribute wstring headerStrRight; */
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrRight(PRUnichar * *aHeaderStrRight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrRight(const PRUnichar * aHeaderStrRight) = 0;

  /* attribute wstring footerStrLeft; */
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrLeft(PRUnichar * *aFooterStrLeft) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrLeft(const PRUnichar * aFooterStrLeft) = 0;

  /* attribute wstring footerStrCenter; */
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrCenter(PRUnichar * *aFooterStrCenter) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrCenter(const PRUnichar * aFooterStrCenter) = 0;

  /* attribute wstring footerStrRight; */
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrRight(PRUnichar * *aFooterStrRight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrRight(const PRUnichar * aFooterStrRight) = 0;

  /* attribute short howToEnableFrameUI; */
  NS_SCRIPTABLE NS_IMETHOD GetHowToEnableFrameUI(PRInt16 *aHowToEnableFrameUI) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHowToEnableFrameUI(PRInt16 aHowToEnableFrameUI) = 0;

  /* attribute boolean isCancelled; */
  NS_SCRIPTABLE NS_IMETHOD GetIsCancelled(PRBool *aIsCancelled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIsCancelled(PRBool aIsCancelled) = 0;

  /* attribute short printFrameTypeUsage; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintFrameTypeUsage(PRInt16 *aPrintFrameTypeUsage) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintFrameTypeUsage(PRInt16 aPrintFrameTypeUsage) = 0;

  /* attribute short printFrameType; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintFrameType(PRInt16 *aPrintFrameType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintFrameType(PRInt16 aPrintFrameType) = 0;

  /* attribute boolean printSilent; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintSilent(PRBool *aPrintSilent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintSilent(PRBool aPrintSilent) = 0;

  /* attribute boolean shrinkToFit; */
  NS_SCRIPTABLE NS_IMETHOD GetShrinkToFit(PRBool *aShrinkToFit) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShrinkToFit(PRBool aShrinkToFit) = 0;

  /* attribute boolean showPrintProgress; */
  NS_SCRIPTABLE NS_IMETHOD GetShowPrintProgress(PRBool *aShowPrintProgress) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShowPrintProgress(PRBool aShowPrintProgress) = 0;

  /* attribute wstring paperName; */
  NS_SCRIPTABLE NS_IMETHOD GetPaperName(PRUnichar * *aPaperName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPaperName(const PRUnichar * aPaperName) = 0;

  /* attribute short paperSizeType; */
  NS_SCRIPTABLE NS_IMETHOD GetPaperSizeType(PRInt16 *aPaperSizeType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPaperSizeType(PRInt16 aPaperSizeType) = 0;

  /* attribute short paperData; */
  NS_SCRIPTABLE NS_IMETHOD GetPaperData(PRInt16 *aPaperData) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPaperData(PRInt16 aPaperData) = 0;

  /* attribute double paperWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetPaperWidth(double *aPaperWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPaperWidth(double aPaperWidth) = 0;

  /* attribute double paperHeight; */
  NS_SCRIPTABLE NS_IMETHOD GetPaperHeight(double *aPaperHeight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPaperHeight(double aPaperHeight) = 0;

  /* attribute short paperSizeUnit; */
  NS_SCRIPTABLE NS_IMETHOD GetPaperSizeUnit(PRInt16 *aPaperSizeUnit) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPaperSizeUnit(PRInt16 aPaperSizeUnit) = 0;

  /* attribute wstring plexName; */
  NS_SCRIPTABLE NS_IMETHOD GetPlexName(PRUnichar * *aPlexName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPlexName(const PRUnichar * aPlexName) = 0;

  /* attribute wstring colorspace; */
  NS_SCRIPTABLE NS_IMETHOD GetColorspace(PRUnichar * *aColorspace) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetColorspace(const PRUnichar * aColorspace) = 0;

  /* attribute wstring resolutionName; */
  NS_SCRIPTABLE NS_IMETHOD GetResolutionName(PRUnichar * *aResolutionName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetResolutionName(const PRUnichar * aResolutionName) = 0;

  /* attribute boolean downloadFonts; */
  NS_SCRIPTABLE NS_IMETHOD GetDownloadFonts(PRBool *aDownloadFonts) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDownloadFonts(PRBool aDownloadFonts) = 0;

  /* attribute boolean printReversed; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintReversed(PRBool *aPrintReversed) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintReversed(PRBool aPrintReversed) = 0;

  /* attribute boolean printInColor; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintInColor(PRBool *aPrintInColor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintInColor(PRBool aPrintInColor) = 0;

  /* attribute long orientation; */
  NS_SCRIPTABLE NS_IMETHOD GetOrientation(PRInt32 *aOrientation) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOrientation(PRInt32 aOrientation) = 0;

  /* attribute wstring printCommand; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintCommand(PRUnichar * *aPrintCommand) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintCommand(const PRUnichar * aPrintCommand) = 0;

  /* attribute long numCopies; */
  NS_SCRIPTABLE NS_IMETHOD GetNumCopies(PRInt32 *aNumCopies) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetNumCopies(PRInt32 aNumCopies) = 0;

  /* attribute wstring printerName; */
  NS_SCRIPTABLE NS_IMETHOD GetPrinterName(PRUnichar * *aPrinterName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrinterName(const PRUnichar * aPrinterName) = 0;

  /* attribute boolean printToFile; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintToFile(PRBool *aPrintToFile) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintToFile(PRBool aPrintToFile) = 0;

  /* attribute wstring toFileName; */
  NS_SCRIPTABLE NS_IMETHOD GetToFileName(PRUnichar * *aToFileName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetToFileName(const PRUnichar * aToFileName) = 0;

  /* attribute short outputFormat; */
  NS_SCRIPTABLE NS_IMETHOD GetOutputFormat(PRInt16 *aOutputFormat) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOutputFormat(PRInt16 aOutputFormat) = 0;

  /* attribute long printPageDelay; */
  NS_SCRIPTABLE NS_IMETHOD GetPrintPageDelay(PRInt32 *aPrintPageDelay) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrintPageDelay(PRInt32 aPrintPageDelay) = 0;

  /**
   * This attribute tracks whether the PS has been initialized 
   * from a printer specified by the "printerName" attr. 
   * If a different name is set into the "printerName" 
   * attribute than the one it was initialized with the PS
   * will then get intialized from that printer.
   */
  /* attribute boolean isInitializedFromPrinter; */
  NS_SCRIPTABLE NS_IMETHOD GetIsInitializedFromPrinter(PRBool *aIsInitializedFromPrinter) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIsInitializedFromPrinter(PRBool aIsInitializedFromPrinter) = 0;

  /**
   * This attribute tracks whether the PS has been initialized 
   * from prefs. If a different name is set into the "printerName" 
   * attribute than the one it was initialized with the PS
   * will then get intialized from prefs again.
   */
  /* attribute boolean isInitializedFromPrefs; */
  NS_SCRIPTABLE NS_IMETHOD GetIsInitializedFromPrefs(PRBool *aIsInitializedFromPrefs) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIsInitializedFromPrefs(PRBool aIsInitializedFromPrefs) = 0;

  /* [noscript] void SetMarginInTwips (in nsNativeMarginRef aMargin); */
  NS_IMETHOD SetMarginInTwips(nsMargin & aMargin) = 0;

  /* [noscript] void SetEdgeInTwips (in nsNativeMarginRef aEdge); */
  NS_IMETHOD SetEdgeInTwips(nsMargin & aEdge) = 0;

  /* [noscript] void GetMarginInTwips (in nsNativeMarginRef aMargin); */
  NS_IMETHOD GetMarginInTwips(nsMargin & aMargin) = 0;

  /* [noscript] void GetEdgeInTwips (in nsNativeMarginRef aEdge); */
  NS_IMETHOD GetEdgeInTwips(nsMargin & aEdge) = 0;

  /**
   * We call this function so that anything that requires a run of the event loop
   * can do so safely. The print dialog runs the event loop but in silent printing
   * that doesn't happen.
   *
   * Either this or ShowPrintDialog (but not both) MUST be called by the print engine
   * before printing, otherwise printing can fail on some platforms.
   */
  /* [noscript] void SetupSilentPrinting (); */
  NS_IMETHOD SetupSilentPrinting(void) = 0;

  /**
   * Sets/Gets the "unwriteable margin" for the page format.  This defines
   * the boundary from which we'll measure the EdgeInTwips and MarginInTwips 
   * attributes, to place the headers and content, respectively.
   *
   * Note: Implementations of SetUnwriteableMarginInTwips should handle
   * negative margin values by falling back on the system default for
   * that margin.
   */
  /* [noscript] void SetUnwriteableMarginInTwips (in nsNativeMarginRef aEdge); */
  NS_IMETHOD SetUnwriteableMarginInTwips(nsMargin & aEdge) = 0;

  /* [noscript] void GetUnwriteableMarginInTwips (in nsNativeMarginRef aEdge); */
  NS_IMETHOD GetUnwriteableMarginInTwips(nsMargin & aEdge) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintSettings, NS_IPRINTSETTINGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTSETTINGS \
  NS_SCRIPTABLE NS_IMETHOD SetPrintOptions(PRInt32 aType, PRBool aTurnOnOff); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintOptions(PRInt32 aType, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintOptionsBits(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEffectivePageSize(double *aWidth NS_OUTPARAM, double *aHeight NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsIPrintSettings **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Assign(nsIPrintSettings *aPS); \
  NS_IMETHOD GetPrintSession(nsIPrintSession * *aPrintSession); \
  NS_IMETHOD SetPrintSession(nsIPrintSession * aPrintSession); \
  NS_SCRIPTABLE NS_IMETHOD GetStartPageRange(PRInt32 *aStartPageRange); \
  NS_SCRIPTABLE NS_IMETHOD SetStartPageRange(PRInt32 aStartPageRange); \
  NS_SCRIPTABLE NS_IMETHOD GetEndPageRange(PRInt32 *aEndPageRange); \
  NS_SCRIPTABLE NS_IMETHOD SetEndPageRange(PRInt32 aEndPageRange); \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeTop(double *aEdgeTop); \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeTop(double aEdgeTop); \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeLeft(double *aEdgeLeft); \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeLeft(double aEdgeLeft); \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeBottom(double *aEdgeBottom); \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeBottom(double aEdgeBottom); \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeRight(double *aEdgeRight); \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeRight(double aEdgeRight); \
  NS_SCRIPTABLE NS_IMETHOD GetMarginTop(double *aMarginTop); \
  NS_SCRIPTABLE NS_IMETHOD SetMarginTop(double aMarginTop); \
  NS_SCRIPTABLE NS_IMETHOD GetMarginLeft(double *aMarginLeft); \
  NS_SCRIPTABLE NS_IMETHOD SetMarginLeft(double aMarginLeft); \
  NS_SCRIPTABLE NS_IMETHOD GetMarginBottom(double *aMarginBottom); \
  NS_SCRIPTABLE NS_IMETHOD SetMarginBottom(double aMarginBottom); \
  NS_SCRIPTABLE NS_IMETHOD GetMarginRight(double *aMarginRight); \
  NS_SCRIPTABLE NS_IMETHOD SetMarginRight(double aMarginRight); \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginTop(double *aUnwriteableMarginTop); \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginTop(double aUnwriteableMarginTop); \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft); \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginLeft(double aUnwriteableMarginLeft); \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom); \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginBottom(double aUnwriteableMarginBottom); \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginRight(double *aUnwriteableMarginRight); \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginRight(double aUnwriteableMarginRight); \
  NS_SCRIPTABLE NS_IMETHOD GetScaling(double *aScaling); \
  NS_SCRIPTABLE NS_IMETHOD SetScaling(double aScaling); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintBGColors(PRBool *aPrintBGColors); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintBGColors(PRBool aPrintBGColors); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintBGImages(PRBool *aPrintBGImages); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintBGImages(PRBool aPrintBGImages); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintRange(PRInt16 *aPrintRange); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintRange(PRInt16 aPrintRange); \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(PRUnichar * *aTitle); \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const PRUnichar * aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetDocURL(PRUnichar * *aDocURL); \
  NS_SCRIPTABLE NS_IMETHOD SetDocURL(const PRUnichar * aDocURL); \
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrLeft(PRUnichar * *aHeaderStrLeft); \
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrLeft(const PRUnichar * aHeaderStrLeft); \
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrCenter(PRUnichar * *aHeaderStrCenter); \
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrCenter(const PRUnichar * aHeaderStrCenter); \
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrRight(PRUnichar * *aHeaderStrRight); \
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrRight(const PRUnichar * aHeaderStrRight); \
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrLeft(PRUnichar * *aFooterStrLeft); \
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrLeft(const PRUnichar * aFooterStrLeft); \
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrCenter(PRUnichar * *aFooterStrCenter); \
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrCenter(const PRUnichar * aFooterStrCenter); \
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrRight(PRUnichar * *aFooterStrRight); \
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrRight(const PRUnichar * aFooterStrRight); \
  NS_SCRIPTABLE NS_IMETHOD GetHowToEnableFrameUI(PRInt16 *aHowToEnableFrameUI); \
  NS_SCRIPTABLE NS_IMETHOD SetHowToEnableFrameUI(PRInt16 aHowToEnableFrameUI); \
  NS_SCRIPTABLE NS_IMETHOD GetIsCancelled(PRBool *aIsCancelled); \
  NS_SCRIPTABLE NS_IMETHOD SetIsCancelled(PRBool aIsCancelled); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintFrameTypeUsage(PRInt16 *aPrintFrameTypeUsage); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintFrameTypeUsage(PRInt16 aPrintFrameTypeUsage); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintFrameType(PRInt16 *aPrintFrameType); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintFrameType(PRInt16 aPrintFrameType); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintSilent(PRBool *aPrintSilent); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintSilent(PRBool aPrintSilent); \
  NS_SCRIPTABLE NS_IMETHOD GetShrinkToFit(PRBool *aShrinkToFit); \
  NS_SCRIPTABLE NS_IMETHOD SetShrinkToFit(PRBool aShrinkToFit); \
  NS_SCRIPTABLE NS_IMETHOD GetShowPrintProgress(PRBool *aShowPrintProgress); \
  NS_SCRIPTABLE NS_IMETHOD SetShowPrintProgress(PRBool aShowPrintProgress); \
  NS_SCRIPTABLE NS_IMETHOD GetPaperName(PRUnichar * *aPaperName); \
  NS_SCRIPTABLE NS_IMETHOD SetPaperName(const PRUnichar * aPaperName); \
  NS_SCRIPTABLE NS_IMETHOD GetPaperSizeType(PRInt16 *aPaperSizeType); \
  NS_SCRIPTABLE NS_IMETHOD SetPaperSizeType(PRInt16 aPaperSizeType); \
  NS_SCRIPTABLE NS_IMETHOD GetPaperData(PRInt16 *aPaperData); \
  NS_SCRIPTABLE NS_IMETHOD SetPaperData(PRInt16 aPaperData); \
  NS_SCRIPTABLE NS_IMETHOD GetPaperWidth(double *aPaperWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetPaperWidth(double aPaperWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetPaperHeight(double *aPaperHeight); \
  NS_SCRIPTABLE NS_IMETHOD SetPaperHeight(double aPaperHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetPaperSizeUnit(PRInt16 *aPaperSizeUnit); \
  NS_SCRIPTABLE NS_IMETHOD SetPaperSizeUnit(PRInt16 aPaperSizeUnit); \
  NS_SCRIPTABLE NS_IMETHOD GetPlexName(PRUnichar * *aPlexName); \
  NS_SCRIPTABLE NS_IMETHOD SetPlexName(const PRUnichar * aPlexName); \
  NS_SCRIPTABLE NS_IMETHOD GetColorspace(PRUnichar * *aColorspace); \
  NS_SCRIPTABLE NS_IMETHOD SetColorspace(const PRUnichar * aColorspace); \
  NS_SCRIPTABLE NS_IMETHOD GetResolutionName(PRUnichar * *aResolutionName); \
  NS_SCRIPTABLE NS_IMETHOD SetResolutionName(const PRUnichar * aResolutionName); \
  NS_SCRIPTABLE NS_IMETHOD GetDownloadFonts(PRBool *aDownloadFonts); \
  NS_SCRIPTABLE NS_IMETHOD SetDownloadFonts(PRBool aDownloadFonts); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintReversed(PRBool *aPrintReversed); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintReversed(PRBool aPrintReversed); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintInColor(PRBool *aPrintInColor); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintInColor(PRBool aPrintInColor); \
  NS_SCRIPTABLE NS_IMETHOD GetOrientation(PRInt32 *aOrientation); \
  NS_SCRIPTABLE NS_IMETHOD SetOrientation(PRInt32 aOrientation); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintCommand(PRUnichar * *aPrintCommand); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintCommand(const PRUnichar * aPrintCommand); \
  NS_SCRIPTABLE NS_IMETHOD GetNumCopies(PRInt32 *aNumCopies); \
  NS_SCRIPTABLE NS_IMETHOD SetNumCopies(PRInt32 aNumCopies); \
  NS_SCRIPTABLE NS_IMETHOD GetPrinterName(PRUnichar * *aPrinterName); \
  NS_SCRIPTABLE NS_IMETHOD SetPrinterName(const PRUnichar * aPrinterName); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintToFile(PRBool *aPrintToFile); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintToFile(PRBool aPrintToFile); \
  NS_SCRIPTABLE NS_IMETHOD GetToFileName(PRUnichar * *aToFileName); \
  NS_SCRIPTABLE NS_IMETHOD SetToFileName(const PRUnichar * aToFileName); \
  NS_SCRIPTABLE NS_IMETHOD GetOutputFormat(PRInt16 *aOutputFormat); \
  NS_SCRIPTABLE NS_IMETHOD SetOutputFormat(PRInt16 aOutputFormat); \
  NS_SCRIPTABLE NS_IMETHOD GetPrintPageDelay(PRInt32 *aPrintPageDelay); \
  NS_SCRIPTABLE NS_IMETHOD SetPrintPageDelay(PRInt32 aPrintPageDelay); \
  NS_SCRIPTABLE NS_IMETHOD GetIsInitializedFromPrinter(PRBool *aIsInitializedFromPrinter); \
  NS_SCRIPTABLE NS_IMETHOD SetIsInitializedFromPrinter(PRBool aIsInitializedFromPrinter); \
  NS_SCRIPTABLE NS_IMETHOD GetIsInitializedFromPrefs(PRBool *aIsInitializedFromPrefs); \
  NS_SCRIPTABLE NS_IMETHOD SetIsInitializedFromPrefs(PRBool aIsInitializedFromPrefs); \
  NS_IMETHOD SetMarginInTwips(nsMargin & aMargin); \
  NS_IMETHOD SetEdgeInTwips(nsMargin & aEdge); \
  NS_IMETHOD GetMarginInTwips(nsMargin & aMargin); \
  NS_IMETHOD GetEdgeInTwips(nsMargin & aEdge); \
  NS_IMETHOD SetupSilentPrinting(void); \
  NS_IMETHOD SetUnwriteableMarginInTwips(nsMargin & aEdge); \
  NS_IMETHOD GetUnwriteableMarginInTwips(nsMargin & aEdge); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTSETTINGS(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetPrintOptions(PRInt32 aType, PRBool aTurnOnOff) { return _to SetPrintOptions(aType, aTurnOnOff); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintOptions(PRInt32 aType, PRBool *_retval NS_OUTPARAM) { return _to GetPrintOptions(aType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintOptionsBits(PRInt32 *_retval NS_OUTPARAM) { return _to GetPrintOptionsBits(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEffectivePageSize(double *aWidth NS_OUTPARAM, double *aHeight NS_OUTPARAM) { return _to GetEffectivePageSize(aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsIPrintSettings **_retval NS_OUTPARAM) { return _to Clone(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Assign(nsIPrintSettings *aPS) { return _to Assign(aPS); } \
  NS_IMETHOD GetPrintSession(nsIPrintSession * *aPrintSession) { return _to GetPrintSession(aPrintSession); } \
  NS_IMETHOD SetPrintSession(nsIPrintSession * aPrintSession) { return _to SetPrintSession(aPrintSession); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartPageRange(PRInt32 *aStartPageRange) { return _to GetStartPageRange(aStartPageRange); } \
  NS_SCRIPTABLE NS_IMETHOD SetStartPageRange(PRInt32 aStartPageRange) { return _to SetStartPageRange(aStartPageRange); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndPageRange(PRInt32 *aEndPageRange) { return _to GetEndPageRange(aEndPageRange); } \
  NS_SCRIPTABLE NS_IMETHOD SetEndPageRange(PRInt32 aEndPageRange) { return _to SetEndPageRange(aEndPageRange); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeTop(double *aEdgeTop) { return _to GetEdgeTop(aEdgeTop); } \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeTop(double aEdgeTop) { return _to SetEdgeTop(aEdgeTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeLeft(double *aEdgeLeft) { return _to GetEdgeLeft(aEdgeLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeLeft(double aEdgeLeft) { return _to SetEdgeLeft(aEdgeLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeBottom(double *aEdgeBottom) { return _to GetEdgeBottom(aEdgeBottom); } \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeBottom(double aEdgeBottom) { return _to SetEdgeBottom(aEdgeBottom); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeRight(double *aEdgeRight) { return _to GetEdgeRight(aEdgeRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeRight(double aEdgeRight) { return _to SetEdgeRight(aEdgeRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginTop(double *aMarginTop) { return _to GetMarginTop(aMarginTop); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginTop(double aMarginTop) { return _to SetMarginTop(aMarginTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginLeft(double *aMarginLeft) { return _to GetMarginLeft(aMarginLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginLeft(double aMarginLeft) { return _to SetMarginLeft(aMarginLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginBottom(double *aMarginBottom) { return _to GetMarginBottom(aMarginBottom); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginBottom(double aMarginBottom) { return _to SetMarginBottom(aMarginBottom); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginRight(double *aMarginRight) { return _to GetMarginRight(aMarginRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginRight(double aMarginRight) { return _to SetMarginRight(aMarginRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginTop(double *aUnwriteableMarginTop) { return _to GetUnwriteableMarginTop(aUnwriteableMarginTop); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginTop(double aUnwriteableMarginTop) { return _to SetUnwriteableMarginTop(aUnwriteableMarginTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft) { return _to GetUnwriteableMarginLeft(aUnwriteableMarginLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginLeft(double aUnwriteableMarginLeft) { return _to SetUnwriteableMarginLeft(aUnwriteableMarginLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom) { return _to GetUnwriteableMarginBottom(aUnwriteableMarginBottom); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginBottom(double aUnwriteableMarginBottom) { return _to SetUnwriteableMarginBottom(aUnwriteableMarginBottom); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginRight(double *aUnwriteableMarginRight) { return _to GetUnwriteableMarginRight(aUnwriteableMarginRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginRight(double aUnwriteableMarginRight) { return _to SetUnwriteableMarginRight(aUnwriteableMarginRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetScaling(double *aScaling) { return _to GetScaling(aScaling); } \
  NS_SCRIPTABLE NS_IMETHOD SetScaling(double aScaling) { return _to SetScaling(aScaling); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintBGColors(PRBool *aPrintBGColors) { return _to GetPrintBGColors(aPrintBGColors); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintBGColors(PRBool aPrintBGColors) { return _to SetPrintBGColors(aPrintBGColors); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintBGImages(PRBool *aPrintBGImages) { return _to GetPrintBGImages(aPrintBGImages); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintBGImages(PRBool aPrintBGImages) { return _to SetPrintBGImages(aPrintBGImages); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintRange(PRInt16 *aPrintRange) { return _to GetPrintRange(aPrintRange); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintRange(PRInt16 aPrintRange) { return _to SetPrintRange(aPrintRange); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(PRUnichar * *aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const PRUnichar * aTitle) { return _to SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocURL(PRUnichar * *aDocURL) { return _to GetDocURL(aDocURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocURL(const PRUnichar * aDocURL) { return _to SetDocURL(aDocURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrLeft(PRUnichar * *aHeaderStrLeft) { return _to GetHeaderStrLeft(aHeaderStrLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrLeft(const PRUnichar * aHeaderStrLeft) { return _to SetHeaderStrLeft(aHeaderStrLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrCenter(PRUnichar * *aHeaderStrCenter) { return _to GetHeaderStrCenter(aHeaderStrCenter); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrCenter(const PRUnichar * aHeaderStrCenter) { return _to SetHeaderStrCenter(aHeaderStrCenter); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrRight(PRUnichar * *aHeaderStrRight) { return _to GetHeaderStrRight(aHeaderStrRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrRight(const PRUnichar * aHeaderStrRight) { return _to SetHeaderStrRight(aHeaderStrRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrLeft(PRUnichar * *aFooterStrLeft) { return _to GetFooterStrLeft(aFooterStrLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrLeft(const PRUnichar * aFooterStrLeft) { return _to SetFooterStrLeft(aFooterStrLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrCenter(PRUnichar * *aFooterStrCenter) { return _to GetFooterStrCenter(aFooterStrCenter); } \
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrCenter(const PRUnichar * aFooterStrCenter) { return _to SetFooterStrCenter(aFooterStrCenter); } \
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrRight(PRUnichar * *aFooterStrRight) { return _to GetFooterStrRight(aFooterStrRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrRight(const PRUnichar * aFooterStrRight) { return _to SetFooterStrRight(aFooterStrRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetHowToEnableFrameUI(PRInt16 *aHowToEnableFrameUI) { return _to GetHowToEnableFrameUI(aHowToEnableFrameUI); } \
  NS_SCRIPTABLE NS_IMETHOD SetHowToEnableFrameUI(PRInt16 aHowToEnableFrameUI) { return _to SetHowToEnableFrameUI(aHowToEnableFrameUI); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsCancelled(PRBool *aIsCancelled) { return _to GetIsCancelled(aIsCancelled); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsCancelled(PRBool aIsCancelled) { return _to SetIsCancelled(aIsCancelled); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintFrameTypeUsage(PRInt16 *aPrintFrameTypeUsage) { return _to GetPrintFrameTypeUsage(aPrintFrameTypeUsage); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintFrameTypeUsage(PRInt16 aPrintFrameTypeUsage) { return _to SetPrintFrameTypeUsage(aPrintFrameTypeUsage); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintFrameType(PRInt16 *aPrintFrameType) { return _to GetPrintFrameType(aPrintFrameType); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintFrameType(PRInt16 aPrintFrameType) { return _to SetPrintFrameType(aPrintFrameType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintSilent(PRBool *aPrintSilent) { return _to GetPrintSilent(aPrintSilent); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintSilent(PRBool aPrintSilent) { return _to SetPrintSilent(aPrintSilent); } \
  NS_SCRIPTABLE NS_IMETHOD GetShrinkToFit(PRBool *aShrinkToFit) { return _to GetShrinkToFit(aShrinkToFit); } \
  NS_SCRIPTABLE NS_IMETHOD SetShrinkToFit(PRBool aShrinkToFit) { return _to SetShrinkToFit(aShrinkToFit); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowPrintProgress(PRBool *aShowPrintProgress) { return _to GetShowPrintProgress(aShowPrintProgress); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowPrintProgress(PRBool aShowPrintProgress) { return _to SetShowPrintProgress(aShowPrintProgress); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperName(PRUnichar * *aPaperName) { return _to GetPaperName(aPaperName); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperName(const PRUnichar * aPaperName) { return _to SetPaperName(aPaperName); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperSizeType(PRInt16 *aPaperSizeType) { return _to GetPaperSizeType(aPaperSizeType); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperSizeType(PRInt16 aPaperSizeType) { return _to SetPaperSizeType(aPaperSizeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperData(PRInt16 *aPaperData) { return _to GetPaperData(aPaperData); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperData(PRInt16 aPaperData) { return _to SetPaperData(aPaperData); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperWidth(double *aPaperWidth) { return _to GetPaperWidth(aPaperWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperWidth(double aPaperWidth) { return _to SetPaperWidth(aPaperWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperHeight(double *aPaperHeight) { return _to GetPaperHeight(aPaperHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperHeight(double aPaperHeight) { return _to SetPaperHeight(aPaperHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperSizeUnit(PRInt16 *aPaperSizeUnit) { return _to GetPaperSizeUnit(aPaperSizeUnit); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperSizeUnit(PRInt16 aPaperSizeUnit) { return _to SetPaperSizeUnit(aPaperSizeUnit); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlexName(PRUnichar * *aPlexName) { return _to GetPlexName(aPlexName); } \
  NS_SCRIPTABLE NS_IMETHOD SetPlexName(const PRUnichar * aPlexName) { return _to SetPlexName(aPlexName); } \
  NS_SCRIPTABLE NS_IMETHOD GetColorspace(PRUnichar * *aColorspace) { return _to GetColorspace(aColorspace); } \
  NS_SCRIPTABLE NS_IMETHOD SetColorspace(const PRUnichar * aColorspace) { return _to SetColorspace(aColorspace); } \
  NS_SCRIPTABLE NS_IMETHOD GetResolutionName(PRUnichar * *aResolutionName) { return _to GetResolutionName(aResolutionName); } \
  NS_SCRIPTABLE NS_IMETHOD SetResolutionName(const PRUnichar * aResolutionName) { return _to SetResolutionName(aResolutionName); } \
  NS_SCRIPTABLE NS_IMETHOD GetDownloadFonts(PRBool *aDownloadFonts) { return _to GetDownloadFonts(aDownloadFonts); } \
  NS_SCRIPTABLE NS_IMETHOD SetDownloadFonts(PRBool aDownloadFonts) { return _to SetDownloadFonts(aDownloadFonts); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintReversed(PRBool *aPrintReversed) { return _to GetPrintReversed(aPrintReversed); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintReversed(PRBool aPrintReversed) { return _to SetPrintReversed(aPrintReversed); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintInColor(PRBool *aPrintInColor) { return _to GetPrintInColor(aPrintInColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintInColor(PRBool aPrintInColor) { return _to SetPrintInColor(aPrintInColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrientation(PRInt32 *aOrientation) { return _to GetOrientation(aOrientation); } \
  NS_SCRIPTABLE NS_IMETHOD SetOrientation(PRInt32 aOrientation) { return _to SetOrientation(aOrientation); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintCommand(PRUnichar * *aPrintCommand) { return _to GetPrintCommand(aPrintCommand); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintCommand(const PRUnichar * aPrintCommand) { return _to SetPrintCommand(aPrintCommand); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumCopies(PRInt32 *aNumCopies) { return _to GetNumCopies(aNumCopies); } \
  NS_SCRIPTABLE NS_IMETHOD SetNumCopies(PRInt32 aNumCopies) { return _to SetNumCopies(aNumCopies); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrinterName(PRUnichar * *aPrinterName) { return _to GetPrinterName(aPrinterName); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrinterName(const PRUnichar * aPrinterName) { return _to SetPrinterName(aPrinterName); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintToFile(PRBool *aPrintToFile) { return _to GetPrintToFile(aPrintToFile); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintToFile(PRBool aPrintToFile) { return _to SetPrintToFile(aPrintToFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetToFileName(PRUnichar * *aToFileName) { return _to GetToFileName(aToFileName); } \
  NS_SCRIPTABLE NS_IMETHOD SetToFileName(const PRUnichar * aToFileName) { return _to SetToFileName(aToFileName); } \
  NS_SCRIPTABLE NS_IMETHOD GetOutputFormat(PRInt16 *aOutputFormat) { return _to GetOutputFormat(aOutputFormat); } \
  NS_SCRIPTABLE NS_IMETHOD SetOutputFormat(PRInt16 aOutputFormat) { return _to SetOutputFormat(aOutputFormat); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintPageDelay(PRInt32 *aPrintPageDelay) { return _to GetPrintPageDelay(aPrintPageDelay); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintPageDelay(PRInt32 aPrintPageDelay) { return _to SetPrintPageDelay(aPrintPageDelay); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsInitializedFromPrinter(PRBool *aIsInitializedFromPrinter) { return _to GetIsInitializedFromPrinter(aIsInitializedFromPrinter); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsInitializedFromPrinter(PRBool aIsInitializedFromPrinter) { return _to SetIsInitializedFromPrinter(aIsInitializedFromPrinter); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsInitializedFromPrefs(PRBool *aIsInitializedFromPrefs) { return _to GetIsInitializedFromPrefs(aIsInitializedFromPrefs); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsInitializedFromPrefs(PRBool aIsInitializedFromPrefs) { return _to SetIsInitializedFromPrefs(aIsInitializedFromPrefs); } \
  NS_IMETHOD SetMarginInTwips(nsMargin & aMargin) { return _to SetMarginInTwips(aMargin); } \
  NS_IMETHOD SetEdgeInTwips(nsMargin & aEdge) { return _to SetEdgeInTwips(aEdge); } \
  NS_IMETHOD GetMarginInTwips(nsMargin & aMargin) { return _to GetMarginInTwips(aMargin); } \
  NS_IMETHOD GetEdgeInTwips(nsMargin & aEdge) { return _to GetEdgeInTwips(aEdge); } \
  NS_IMETHOD SetupSilentPrinting(void) { return _to SetupSilentPrinting(); } \
  NS_IMETHOD SetUnwriteableMarginInTwips(nsMargin & aEdge) { return _to SetUnwriteableMarginInTwips(aEdge); } \
  NS_IMETHOD GetUnwriteableMarginInTwips(nsMargin & aEdge) { return _to GetUnwriteableMarginInTwips(aEdge); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTSETTINGS(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetPrintOptions(PRInt32 aType, PRBool aTurnOnOff) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintOptions(aType, aTurnOnOff); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintOptions(PRInt32 aType, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintOptions(aType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintOptionsBits(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintOptionsBits(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEffectivePageSize(double *aWidth NS_OUTPARAM, double *aHeight NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEffectivePageSize(aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsIPrintSettings **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Assign(nsIPrintSettings *aPS) { return !_to ? NS_ERROR_NULL_POINTER : _to->Assign(aPS); } \
  NS_IMETHOD GetPrintSession(nsIPrintSession * *aPrintSession) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintSession(aPrintSession); } \
  NS_IMETHOD SetPrintSession(nsIPrintSession * aPrintSession) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintSession(aPrintSession); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartPageRange(PRInt32 *aStartPageRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartPageRange(aStartPageRange); } \
  NS_SCRIPTABLE NS_IMETHOD SetStartPageRange(PRInt32 aStartPageRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartPageRange(aStartPageRange); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndPageRange(PRInt32 *aEndPageRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndPageRange(aEndPageRange); } \
  NS_SCRIPTABLE NS_IMETHOD SetEndPageRange(PRInt32 aEndPageRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndPageRange(aEndPageRange); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeTop(double *aEdgeTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeTop(aEdgeTop); } \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeTop(double aEdgeTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeTop(aEdgeTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeLeft(double *aEdgeLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeLeft(aEdgeLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeLeft(double aEdgeLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeLeft(aEdgeLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeBottom(double *aEdgeBottom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeBottom(aEdgeBottom); } \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeBottom(double aEdgeBottom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeBottom(aEdgeBottom); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeRight(double *aEdgeRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeRight(aEdgeRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetEdgeRight(double aEdgeRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeRight(aEdgeRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginTop(double *aMarginTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginTop(aMarginTop); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginTop(double aMarginTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginTop(aMarginTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginLeft(double *aMarginLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginLeft(aMarginLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginLeft(double aMarginLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginLeft(aMarginLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginBottom(double *aMarginBottom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginBottom(aMarginBottom); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginBottom(double aMarginBottom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginBottom(aMarginBottom); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginRight(double *aMarginRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginRight(aMarginRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginRight(double aMarginRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginRight(aMarginRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginTop(double *aUnwriteableMarginTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginTop(aUnwriteableMarginTop); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginTop(double aUnwriteableMarginTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginTop(aUnwriteableMarginTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginLeft(aUnwriteableMarginLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginLeft(double aUnwriteableMarginLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginLeft(aUnwriteableMarginLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginBottom(aUnwriteableMarginBottom); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginBottom(double aUnwriteableMarginBottom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginBottom(aUnwriteableMarginBottom); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnwriteableMarginRight(double *aUnwriteableMarginRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginRight(aUnwriteableMarginRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetUnwriteableMarginRight(double aUnwriteableMarginRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginRight(aUnwriteableMarginRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetScaling(double *aScaling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScaling(aScaling); } \
  NS_SCRIPTABLE NS_IMETHOD SetScaling(double aScaling) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScaling(aScaling); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintBGColors(PRBool *aPrintBGColors) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintBGColors(aPrintBGColors); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintBGColors(PRBool aPrintBGColors) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintBGColors(aPrintBGColors); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintBGImages(PRBool *aPrintBGImages) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintBGImages(aPrintBGImages); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintBGImages(PRBool aPrintBGImages) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintBGImages(aPrintBGImages); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintRange(PRInt16 *aPrintRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintRange(aPrintRange); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintRange(PRInt16 aPrintRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintRange(aPrintRange); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(PRUnichar * *aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const PRUnichar * aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocURL(PRUnichar * *aDocURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocURL(aDocURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocURL(const PRUnichar * aDocURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocURL(aDocURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrLeft(PRUnichar * *aHeaderStrLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeaderStrLeft(aHeaderStrLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrLeft(const PRUnichar * aHeaderStrLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeaderStrLeft(aHeaderStrLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrCenter(PRUnichar * *aHeaderStrCenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeaderStrCenter(aHeaderStrCenter); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrCenter(const PRUnichar * aHeaderStrCenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeaderStrCenter(aHeaderStrCenter); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeaderStrRight(PRUnichar * *aHeaderStrRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeaderStrRight(aHeaderStrRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeaderStrRight(const PRUnichar * aHeaderStrRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeaderStrRight(aHeaderStrRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrLeft(PRUnichar * *aFooterStrLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFooterStrLeft(aFooterStrLeft); } \
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrLeft(const PRUnichar * aFooterStrLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFooterStrLeft(aFooterStrLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrCenter(PRUnichar * *aFooterStrCenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFooterStrCenter(aFooterStrCenter); } \
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrCenter(const PRUnichar * aFooterStrCenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFooterStrCenter(aFooterStrCenter); } \
  NS_SCRIPTABLE NS_IMETHOD GetFooterStrRight(PRUnichar * *aFooterStrRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFooterStrRight(aFooterStrRight); } \
  NS_SCRIPTABLE NS_IMETHOD SetFooterStrRight(const PRUnichar * aFooterStrRight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFooterStrRight(aFooterStrRight); } \
  NS_SCRIPTABLE NS_IMETHOD GetHowToEnableFrameUI(PRInt16 *aHowToEnableFrameUI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHowToEnableFrameUI(aHowToEnableFrameUI); } \
  NS_SCRIPTABLE NS_IMETHOD SetHowToEnableFrameUI(PRInt16 aHowToEnableFrameUI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHowToEnableFrameUI(aHowToEnableFrameUI); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsCancelled(PRBool *aIsCancelled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsCancelled(aIsCancelled); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsCancelled(PRBool aIsCancelled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsCancelled(aIsCancelled); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintFrameTypeUsage(PRInt16 *aPrintFrameTypeUsage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintFrameTypeUsage(aPrintFrameTypeUsage); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintFrameTypeUsage(PRInt16 aPrintFrameTypeUsage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintFrameTypeUsage(aPrintFrameTypeUsage); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintFrameType(PRInt16 *aPrintFrameType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintFrameType(aPrintFrameType); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintFrameType(PRInt16 aPrintFrameType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintFrameType(aPrintFrameType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintSilent(PRBool *aPrintSilent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintSilent(aPrintSilent); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintSilent(PRBool aPrintSilent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintSilent(aPrintSilent); } \
  NS_SCRIPTABLE NS_IMETHOD GetShrinkToFit(PRBool *aShrinkToFit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShrinkToFit(aShrinkToFit); } \
  NS_SCRIPTABLE NS_IMETHOD SetShrinkToFit(PRBool aShrinkToFit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShrinkToFit(aShrinkToFit); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowPrintProgress(PRBool *aShowPrintProgress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowPrintProgress(aShowPrintProgress); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowPrintProgress(PRBool aShowPrintProgress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowPrintProgress(aShowPrintProgress); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperName(PRUnichar * *aPaperName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperName(aPaperName); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperName(const PRUnichar * aPaperName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperName(aPaperName); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperSizeType(PRInt16 *aPaperSizeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperSizeType(aPaperSizeType); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperSizeType(PRInt16 aPaperSizeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperSizeType(aPaperSizeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperData(PRInt16 *aPaperData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperData(aPaperData); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperData(PRInt16 aPaperData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperData(aPaperData); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperWidth(double *aPaperWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperWidth(aPaperWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperWidth(double aPaperWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperWidth(aPaperWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperHeight(double *aPaperHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperHeight(aPaperHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperHeight(double aPaperHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperHeight(aPaperHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaperSizeUnit(PRInt16 *aPaperSizeUnit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperSizeUnit(aPaperSizeUnit); } \
  NS_SCRIPTABLE NS_IMETHOD SetPaperSizeUnit(PRInt16 aPaperSizeUnit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperSizeUnit(aPaperSizeUnit); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlexName(PRUnichar * *aPlexName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlexName(aPlexName); } \
  NS_SCRIPTABLE NS_IMETHOD SetPlexName(const PRUnichar * aPlexName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPlexName(aPlexName); } \
  NS_SCRIPTABLE NS_IMETHOD GetColorspace(PRUnichar * *aColorspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColorspace(aColorspace); } \
  NS_SCRIPTABLE NS_IMETHOD SetColorspace(const PRUnichar * aColorspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetColorspace(aColorspace); } \
  NS_SCRIPTABLE NS_IMETHOD GetResolutionName(PRUnichar * *aResolutionName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResolutionName(aResolutionName); } \
  NS_SCRIPTABLE NS_IMETHOD SetResolutionName(const PRUnichar * aResolutionName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResolutionName(aResolutionName); } \
  NS_SCRIPTABLE NS_IMETHOD GetDownloadFonts(PRBool *aDownloadFonts) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownloadFonts(aDownloadFonts); } \
  NS_SCRIPTABLE NS_IMETHOD SetDownloadFonts(PRBool aDownloadFonts) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDownloadFonts(aDownloadFonts); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintReversed(PRBool *aPrintReversed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintReversed(aPrintReversed); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintReversed(PRBool aPrintReversed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintReversed(aPrintReversed); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintInColor(PRBool *aPrintInColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintInColor(aPrintInColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintInColor(PRBool aPrintInColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintInColor(aPrintInColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrientation(PRInt32 *aOrientation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrientation(aOrientation); } \
  NS_SCRIPTABLE NS_IMETHOD SetOrientation(PRInt32 aOrientation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOrientation(aOrientation); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintCommand(PRUnichar * *aPrintCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintCommand(aPrintCommand); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintCommand(const PRUnichar * aPrintCommand) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintCommand(aPrintCommand); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumCopies(PRInt32 *aNumCopies) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumCopies(aNumCopies); } \
  NS_SCRIPTABLE NS_IMETHOD SetNumCopies(PRInt32 aNumCopies) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNumCopies(aNumCopies); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrinterName(PRUnichar * *aPrinterName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrinterName(aPrinterName); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrinterName(const PRUnichar * aPrinterName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrinterName(aPrinterName); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintToFile(PRBool *aPrintToFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintToFile(aPrintToFile); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintToFile(PRBool aPrintToFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintToFile(aPrintToFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetToFileName(PRUnichar * *aToFileName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetToFileName(aToFileName); } \
  NS_SCRIPTABLE NS_IMETHOD SetToFileName(const PRUnichar * aToFileName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetToFileName(aToFileName); } \
  NS_SCRIPTABLE NS_IMETHOD GetOutputFormat(PRInt16 *aOutputFormat) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOutputFormat(aOutputFormat); } \
  NS_SCRIPTABLE NS_IMETHOD SetOutputFormat(PRInt16 aOutputFormat) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOutputFormat(aOutputFormat); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrintPageDelay(PRInt32 *aPrintPageDelay) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintPageDelay(aPrintPageDelay); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrintPageDelay(PRInt32 aPrintPageDelay) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintPageDelay(aPrintPageDelay); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsInitializedFromPrinter(PRBool *aIsInitializedFromPrinter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInitializedFromPrinter(aIsInitializedFromPrinter); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsInitializedFromPrinter(PRBool aIsInitializedFromPrinter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsInitializedFromPrinter(aIsInitializedFromPrinter); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsInitializedFromPrefs(PRBool *aIsInitializedFromPrefs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInitializedFromPrefs(aIsInitializedFromPrefs); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsInitializedFromPrefs(PRBool aIsInitializedFromPrefs) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsInitializedFromPrefs(aIsInitializedFromPrefs); } \
  NS_IMETHOD SetMarginInTwips(nsMargin & aMargin) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginInTwips(aMargin); } \
  NS_IMETHOD SetEdgeInTwips(nsMargin & aEdge) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeInTwips(aEdge); } \
  NS_IMETHOD GetMarginInTwips(nsMargin & aMargin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginInTwips(aMargin); } \
  NS_IMETHOD GetEdgeInTwips(nsMargin & aEdge) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeInTwips(aEdge); } \
  NS_IMETHOD SetupSilentPrinting(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetupSilentPrinting(); } \
  NS_IMETHOD SetUnwriteableMarginInTwips(nsMargin & aEdge) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginInTwips(aEdge); } \
  NS_IMETHOD GetUnwriteableMarginInTwips(nsMargin & aEdge) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginInTwips(aEdge); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintSettings : public nsIPrintSettings
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTSETTINGS

  nsPrintSettings();

private:
  ~nsPrintSettings();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintSettings, nsIPrintSettings)

nsPrintSettings::nsPrintSettings()
{
  /* member initializers and constructor code */
}

nsPrintSettings::~nsPrintSettings()
{
  /* destructor code */
}

/* void SetPrintOptions (in PRInt32 aType, in PRBool aTurnOnOff); */
NS_IMETHODIMP nsPrintSettings::SetPrintOptions(PRInt32 aType, PRBool aTurnOnOff)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool GetPrintOptions (in PRInt32 aType); */
NS_IMETHODIMP nsPrintSettings::GetPrintOptions(PRInt32 aType, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRInt32 GetPrintOptionsBits (); */
NS_IMETHODIMP nsPrintSettings::GetPrintOptionsBits(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetEffectivePageSize (out double aWidth, out double aHeight); */
NS_IMETHODIMP nsPrintSettings::GetEffectivePageSize(double *aWidth NS_OUTPARAM, double *aHeight NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrintSettings clone (); */
NS_IMETHODIMP nsPrintSettings::Clone(nsIPrintSettings **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void assign (in nsIPrintSettings aPS); */
NS_IMETHODIMP nsPrintSettings::Assign(nsIPrintSettings *aPS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIPrintSession printSession; */
NS_IMETHODIMP nsPrintSettings::GetPrintSession(nsIPrintSession * *aPrintSession)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintSession(nsIPrintSession * aPrintSession)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long startPageRange; */
NS_IMETHODIMP nsPrintSettings::GetStartPageRange(PRInt32 *aStartPageRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetStartPageRange(PRInt32 aStartPageRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long endPageRange; */
NS_IMETHODIMP nsPrintSettings::GetEndPageRange(PRInt32 *aEndPageRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEndPageRange(PRInt32 aEndPageRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double edgeTop; */
NS_IMETHODIMP nsPrintSettings::GetEdgeTop(double *aEdgeTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEdgeTop(double aEdgeTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double edgeLeft; */
NS_IMETHODIMP nsPrintSettings::GetEdgeLeft(double *aEdgeLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEdgeLeft(double aEdgeLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double edgeBottom; */
NS_IMETHODIMP nsPrintSettings::GetEdgeBottom(double *aEdgeBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEdgeBottom(double aEdgeBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double edgeRight; */
NS_IMETHODIMP nsPrintSettings::GetEdgeRight(double *aEdgeRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEdgeRight(double aEdgeRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double marginTop; */
NS_IMETHODIMP nsPrintSettings::GetMarginTop(double *aMarginTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetMarginTop(double aMarginTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double marginLeft; */
NS_IMETHODIMP nsPrintSettings::GetMarginLeft(double *aMarginLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetMarginLeft(double aMarginLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double marginBottom; */
NS_IMETHODIMP nsPrintSettings::GetMarginBottom(double *aMarginBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetMarginBottom(double aMarginBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double marginRight; */
NS_IMETHODIMP nsPrintSettings::GetMarginRight(double *aMarginRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetMarginRight(double aMarginRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double unwriteableMarginTop; */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginTop(double *aUnwriteableMarginTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginTop(double aUnwriteableMarginTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double unwriteableMarginLeft; */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginLeft(double aUnwriteableMarginLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double unwriteableMarginBottom; */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginBottom(double aUnwriteableMarginBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double unwriteableMarginRight; */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginRight(double *aUnwriteableMarginRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginRight(double aUnwriteableMarginRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double scaling; */
NS_IMETHODIMP nsPrintSettings::GetScaling(double *aScaling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetScaling(double aScaling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printBGColors; */
NS_IMETHODIMP nsPrintSettings::GetPrintBGColors(PRBool *aPrintBGColors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintBGColors(PRBool aPrintBGColors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printBGImages; */
NS_IMETHODIMP nsPrintSettings::GetPrintBGImages(PRBool *aPrintBGImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintBGImages(PRBool aPrintBGImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short printRange; */
NS_IMETHODIMP nsPrintSettings::GetPrintRange(PRInt16 *aPrintRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintRange(PRInt16 aPrintRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring title; */
NS_IMETHODIMP nsPrintSettings::GetTitle(PRUnichar * *aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetTitle(const PRUnichar * aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring docURL; */
NS_IMETHODIMP nsPrintSettings::GetDocURL(PRUnichar * *aDocURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetDocURL(const PRUnichar * aDocURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring headerStrLeft; */
NS_IMETHODIMP nsPrintSettings::GetHeaderStrLeft(PRUnichar * *aHeaderStrLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetHeaderStrLeft(const PRUnichar * aHeaderStrLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring headerStrCenter; */
NS_IMETHODIMP nsPrintSettings::GetHeaderStrCenter(PRUnichar * *aHeaderStrCenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetHeaderStrCenter(const PRUnichar * aHeaderStrCenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring headerStrRight; */
NS_IMETHODIMP nsPrintSettings::GetHeaderStrRight(PRUnichar * *aHeaderStrRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetHeaderStrRight(const PRUnichar * aHeaderStrRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring footerStrLeft; */
NS_IMETHODIMP nsPrintSettings::GetFooterStrLeft(PRUnichar * *aFooterStrLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetFooterStrLeft(const PRUnichar * aFooterStrLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring footerStrCenter; */
NS_IMETHODIMP nsPrintSettings::GetFooterStrCenter(PRUnichar * *aFooterStrCenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetFooterStrCenter(const PRUnichar * aFooterStrCenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring footerStrRight; */
NS_IMETHODIMP nsPrintSettings::GetFooterStrRight(PRUnichar * *aFooterStrRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetFooterStrRight(const PRUnichar * aFooterStrRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short howToEnableFrameUI; */
NS_IMETHODIMP nsPrintSettings::GetHowToEnableFrameUI(PRInt16 *aHowToEnableFrameUI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetHowToEnableFrameUI(PRInt16 aHowToEnableFrameUI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isCancelled; */
NS_IMETHODIMP nsPrintSettings::GetIsCancelled(PRBool *aIsCancelled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetIsCancelled(PRBool aIsCancelled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short printFrameTypeUsage; */
NS_IMETHODIMP nsPrintSettings::GetPrintFrameTypeUsage(PRInt16 *aPrintFrameTypeUsage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintFrameTypeUsage(PRInt16 aPrintFrameTypeUsage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short printFrameType; */
NS_IMETHODIMP nsPrintSettings::GetPrintFrameType(PRInt16 *aPrintFrameType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintFrameType(PRInt16 aPrintFrameType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printSilent; */
NS_IMETHODIMP nsPrintSettings::GetPrintSilent(PRBool *aPrintSilent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintSilent(PRBool aPrintSilent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean shrinkToFit; */
NS_IMETHODIMP nsPrintSettings::GetShrinkToFit(PRBool *aShrinkToFit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetShrinkToFit(PRBool aShrinkToFit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showPrintProgress; */
NS_IMETHODIMP nsPrintSettings::GetShowPrintProgress(PRBool *aShowPrintProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetShowPrintProgress(PRBool aShowPrintProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring paperName; */
NS_IMETHODIMP nsPrintSettings::GetPaperName(PRUnichar * *aPaperName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperName(const PRUnichar * aPaperName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short paperSizeType; */
NS_IMETHODIMP nsPrintSettings::GetPaperSizeType(PRInt16 *aPaperSizeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperSizeType(PRInt16 aPaperSizeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short paperData; */
NS_IMETHODIMP nsPrintSettings::GetPaperData(PRInt16 *aPaperData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperData(PRInt16 aPaperData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double paperWidth; */
NS_IMETHODIMP nsPrintSettings::GetPaperWidth(double *aPaperWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperWidth(double aPaperWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double paperHeight; */
NS_IMETHODIMP nsPrintSettings::GetPaperHeight(double *aPaperHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperHeight(double aPaperHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short paperSizeUnit; */
NS_IMETHODIMP nsPrintSettings::GetPaperSizeUnit(PRInt16 *aPaperSizeUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperSizeUnit(PRInt16 aPaperSizeUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring plexName; */
NS_IMETHODIMP nsPrintSettings::GetPlexName(PRUnichar * *aPlexName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPlexName(const PRUnichar * aPlexName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring colorspace; */
NS_IMETHODIMP nsPrintSettings::GetColorspace(PRUnichar * *aColorspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetColorspace(const PRUnichar * aColorspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring resolutionName; */
NS_IMETHODIMP nsPrintSettings::GetResolutionName(PRUnichar * *aResolutionName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetResolutionName(const PRUnichar * aResolutionName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean downloadFonts; */
NS_IMETHODIMP nsPrintSettings::GetDownloadFonts(PRBool *aDownloadFonts)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetDownloadFonts(PRBool aDownloadFonts)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printReversed; */
NS_IMETHODIMP nsPrintSettings::GetPrintReversed(PRBool *aPrintReversed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintReversed(PRBool aPrintReversed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printInColor; */
NS_IMETHODIMP nsPrintSettings::GetPrintInColor(PRBool *aPrintInColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintInColor(PRBool aPrintInColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long orientation; */
NS_IMETHODIMP nsPrintSettings::GetOrientation(PRInt32 *aOrientation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetOrientation(PRInt32 aOrientation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring printCommand; */
NS_IMETHODIMP nsPrintSettings::GetPrintCommand(PRUnichar * *aPrintCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintCommand(const PRUnichar * aPrintCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long numCopies; */
NS_IMETHODIMP nsPrintSettings::GetNumCopies(PRInt32 *aNumCopies)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetNumCopies(PRInt32 aNumCopies)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring printerName; */
NS_IMETHODIMP nsPrintSettings::GetPrinterName(PRUnichar * *aPrinterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrinterName(const PRUnichar * aPrinterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printToFile; */
NS_IMETHODIMP nsPrintSettings::GetPrintToFile(PRBool *aPrintToFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintToFile(PRBool aPrintToFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring toFileName; */
NS_IMETHODIMP nsPrintSettings::GetToFileName(PRUnichar * *aToFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetToFileName(const PRUnichar * aToFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short outputFormat; */
NS_IMETHODIMP nsPrintSettings::GetOutputFormat(PRInt16 *aOutputFormat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetOutputFormat(PRInt16 aOutputFormat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long printPageDelay; */
NS_IMETHODIMP nsPrintSettings::GetPrintPageDelay(PRInt32 *aPrintPageDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintPageDelay(PRInt32 aPrintPageDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isInitializedFromPrinter; */
NS_IMETHODIMP nsPrintSettings::GetIsInitializedFromPrinter(PRBool *aIsInitializedFromPrinter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetIsInitializedFromPrinter(PRBool aIsInitializedFromPrinter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isInitializedFromPrefs; */
NS_IMETHODIMP nsPrintSettings::GetIsInitializedFromPrefs(PRBool *aIsInitializedFromPrefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetIsInitializedFromPrefs(PRBool aIsInitializedFromPrefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetMarginInTwips (in nsNativeMarginRef aMargin); */
NS_IMETHODIMP nsPrintSettings::SetMarginInTwips(nsMargin & aMargin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetEdgeInTwips (in nsNativeMarginRef aEdge); */
NS_IMETHODIMP nsPrintSettings::SetEdgeInTwips(nsMargin & aEdge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetMarginInTwips (in nsNativeMarginRef aMargin); */
NS_IMETHODIMP nsPrintSettings::GetMarginInTwips(nsMargin & aMargin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetEdgeInTwips (in nsNativeMarginRef aEdge); */
NS_IMETHODIMP nsPrintSettings::GetEdgeInTwips(nsMargin & aEdge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetupSilentPrinting (); */
NS_IMETHODIMP nsPrintSettings::SetupSilentPrinting()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetUnwriteableMarginInTwips (in nsNativeMarginRef aEdge); */
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginInTwips(nsMargin & aEdge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetUnwriteableMarginInTwips (in nsNativeMarginRef aEdge); */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginInTwips(nsMargin & aEdge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintSettings_h__ */
