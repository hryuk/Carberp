/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIMarkupDocumentViewer.idl
 */

#ifndef __gen_nsIMarkupDocumentViewer_h__
#define __gen_nsIMarkupDocumentViewer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    nsIMarkupDocumentViewer */
#define NS_IMARKUPDOCUMENTVIEWER_IID_STR "40b2282a-a882-4483-a634-dec468d88377"

#define NS_IMARKUPDOCUMENTVIEWER_IID \
  {0x40b2282a, 0xa882, 0x4483, \
    { 0xa6, 0x34, 0xde, 0xc4, 0x68, 0xd8, 0x83, 0x77 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMarkupDocumentViewer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMARKUPDOCUMENTVIEWER_IID)

  /* void scrollToNode (in nsIDOMNode node); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToNode(nsIDOMNode *node) = 0;

  /** The amount by which to scale all text. Default is 1.0. */
  /* attribute float textZoom; */
  NS_SCRIPTABLE NS_IMETHOD GetTextZoom(float *aTextZoom) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTextZoom(float aTextZoom) = 0;

  /** The amount by which to scale all lengths. Default is 1.0. */
  /* attribute float fullZoom; */
  NS_SCRIPTABLE NS_IMETHOD GetFullZoom(float *aFullZoom) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFullZoom(float aFullZoom) = 0;

  /** Disable entire author style level (including HTML presentation hints) */
  /* attribute boolean authorStyleDisabled; */
  NS_SCRIPTABLE NS_IMETHOD GetAuthorStyleDisabled(PRBool *aAuthorStyleDisabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAuthorStyleDisabled(PRBool aAuthorStyleDisabled) = 0;

  /* attribute ACString defaultCharacterSet; */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultCharacterSet(nsACString & aDefaultCharacterSet) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet) = 0;

  /* attribute ACString forceCharacterSet; */
  NS_SCRIPTABLE NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) = 0;

  /* attribute ACString hintCharacterSet; */
  NS_SCRIPTABLE NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) = 0;

  /* attribute PRInt32 hintCharacterSetSource; */
  NS_SCRIPTABLE NS_IMETHOD GetHintCharacterSetSource(PRInt32 *aHintCharacterSetSource) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHintCharacterSetSource(PRInt32 aHintCharacterSetSource) = 0;

  /* attribute ACString prevDocCharacterSet; */
  NS_SCRIPTABLE NS_IMETHOD GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet) = 0;

  /**
	* Tell the container to shrink-to-fit or grow-to-fit its contents
	*/
  /* void sizeToContent (); */
  NS_SCRIPTABLE NS_IMETHOD SizeToContent(void) = 0;

  /**
   * Options for Bidi presentation.
   *
   * Use these attributes to access the individual Bidi options.
   */
/**
   * bidiTextDirection: the default direction for the layout of bidirectional text.
   *                    1 - left to right
   *                    2 - right to left
   */
  /* attribute octet bidiTextDirection; */
  NS_SCRIPTABLE NS_IMETHOD GetBidiTextDirection(PRUint8 *aBidiTextDirection) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBidiTextDirection(PRUint8 aBidiTextDirection) = 0;

  /**
   * bidiTextType: the ordering of bidirectional text. This may be either "logical"
   * or "visual". Logical text will be reordered for presentation using the Unicode
   * Bidi Algorithm. Visual text will be displayed without reordering. 
   *               1 - the default order for the charset
   *               2 - logical order
   *               3 - visual order
   */
  /* attribute octet bidiTextType; */
  NS_SCRIPTABLE NS_IMETHOD GetBidiTextType(PRUint8 *aBidiTextType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBidiTextType(PRUint8 aBidiTextType) = 0;

  /**
   * bidiControlsTextMode: the order of bidirectional text in form controls.
   *                       1 - logical
   *                       2 - visual
   *                       3 - like the containing document
   */
  /* attribute octet bidiControlsTextMode; */
  NS_SCRIPTABLE NS_IMETHOD GetBidiControlsTextMode(PRUint8 *aBidiControlsTextMode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBidiControlsTextMode(PRUint8 aBidiControlsTextMode) = 0;

  /**
   * bidiNumeral: the type of numerals to display. 
   *              1 - depending on context, default is Arabic numerals
   *              2 - depending on context, default is Hindi numerals
   *              3 - Arabic numerals
   *              4 - Hindi numerals
   */
  /* attribute octet bidiNumeral; */
  NS_SCRIPTABLE NS_IMETHOD GetBidiNumeral(PRUint8 *aBidiNumeral) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBidiNumeral(PRUint8 aBidiNumeral) = 0;

  /**
   * bidiSupport: whether to use platform bidi support or Mozilla's bidi support
   *              1 - Use Mozilla's bidi support
   *              2 - Use the platform bidi support
   *              3 - Disable bidi support
   */
  /* attribute octet bidiSupport; */
  NS_SCRIPTABLE NS_IMETHOD GetBidiSupport(PRUint8 *aBidiSupport) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBidiSupport(PRUint8 aBidiSupport) = 0;

  /**
   * bidiCharacterSet: whether to force the user's character set
   *                   1 - use the document character set
   *                   2 - use the character set chosen by the user
   */
  /* attribute octet bidiCharacterSet; */
  NS_SCRIPTABLE NS_IMETHOD GetBidiCharacterSet(PRUint8 *aBidiCharacterSet) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBidiCharacterSet(PRUint8 aBidiCharacterSet) = 0;

  /**
   * Use this attribute to access all the Bidi options in one operation
   */
  /* attribute PRUint32 bidiOptions; */
  NS_SCRIPTABLE NS_IMETHOD GetBidiOptions(PRUint32 *aBidiOptions) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBidiOptions(PRUint32 aBidiOptions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMarkupDocumentViewer, NS_IMARKUPDOCUMENTVIEWER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMARKUPDOCUMENTVIEWER \
  NS_SCRIPTABLE NS_IMETHOD ScrollToNode(nsIDOMNode *node); \
  NS_SCRIPTABLE NS_IMETHOD GetTextZoom(float *aTextZoom); \
  NS_SCRIPTABLE NS_IMETHOD SetTextZoom(float aTextZoom); \
  NS_SCRIPTABLE NS_IMETHOD GetFullZoom(float *aFullZoom); \
  NS_SCRIPTABLE NS_IMETHOD SetFullZoom(float aFullZoom); \
  NS_SCRIPTABLE NS_IMETHOD GetAuthorStyleDisabled(PRBool *aAuthorStyleDisabled); \
  NS_SCRIPTABLE NS_IMETHOD SetAuthorStyleDisabled(PRBool aAuthorStyleDisabled); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultCharacterSet(nsACString & aDefaultCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD GetHintCharacterSetSource(PRInt32 *aHintCharacterSetSource); \
  NS_SCRIPTABLE NS_IMETHOD SetHintCharacterSetSource(PRInt32 aHintCharacterSetSource); \
  NS_SCRIPTABLE NS_IMETHOD GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD SizeToContent(void); \
  NS_SCRIPTABLE NS_IMETHOD GetBidiTextDirection(PRUint8 *aBidiTextDirection); \
  NS_SCRIPTABLE NS_IMETHOD SetBidiTextDirection(PRUint8 aBidiTextDirection); \
  NS_SCRIPTABLE NS_IMETHOD GetBidiTextType(PRUint8 *aBidiTextType); \
  NS_SCRIPTABLE NS_IMETHOD SetBidiTextType(PRUint8 aBidiTextType); \
  NS_SCRIPTABLE NS_IMETHOD GetBidiControlsTextMode(PRUint8 *aBidiControlsTextMode); \
  NS_SCRIPTABLE NS_IMETHOD SetBidiControlsTextMode(PRUint8 aBidiControlsTextMode); \
  NS_SCRIPTABLE NS_IMETHOD GetBidiNumeral(PRUint8 *aBidiNumeral); \
  NS_SCRIPTABLE NS_IMETHOD SetBidiNumeral(PRUint8 aBidiNumeral); \
  NS_SCRIPTABLE NS_IMETHOD GetBidiSupport(PRUint8 *aBidiSupport); \
  NS_SCRIPTABLE NS_IMETHOD SetBidiSupport(PRUint8 aBidiSupport); \
  NS_SCRIPTABLE NS_IMETHOD GetBidiCharacterSet(PRUint8 *aBidiCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD SetBidiCharacterSet(PRUint8 aBidiCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD GetBidiOptions(PRUint32 *aBidiOptions); \
  NS_SCRIPTABLE NS_IMETHOD SetBidiOptions(PRUint32 aBidiOptions); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMARKUPDOCUMENTVIEWER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ScrollToNode(nsIDOMNode *node) { return _to ScrollToNode(node); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextZoom(float *aTextZoom) { return _to GetTextZoom(aTextZoom); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextZoom(float aTextZoom) { return _to SetTextZoom(aTextZoom); } \
  NS_SCRIPTABLE NS_IMETHOD GetFullZoom(float *aFullZoom) { return _to GetFullZoom(aFullZoom); } \
  NS_SCRIPTABLE NS_IMETHOD SetFullZoom(float aFullZoom) { return _to SetFullZoom(aFullZoom); } \
  NS_SCRIPTABLE NS_IMETHOD GetAuthorStyleDisabled(PRBool *aAuthorStyleDisabled) { return _to GetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetAuthorStyleDisabled(PRBool aAuthorStyleDisabled) { return _to SetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultCharacterSet(nsACString & aDefaultCharacterSet) { return _to GetDefaultCharacterSet(aDefaultCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet) { return _to SetDefaultCharacterSet(aDefaultCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) { return _to GetForceCharacterSet(aForceCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) { return _to SetForceCharacterSet(aForceCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) { return _to GetHintCharacterSet(aHintCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) { return _to SetHintCharacterSet(aHintCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetHintCharacterSetSource(PRInt32 *aHintCharacterSetSource) { return _to GetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_SCRIPTABLE NS_IMETHOD SetHintCharacterSetSource(PRInt32 aHintCharacterSetSource) { return _to SetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet) { return _to GetPrevDocCharacterSet(aPrevDocCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet) { return _to SetPrevDocCharacterSet(aPrevDocCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SizeToContent(void) { return _to SizeToContent(); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiTextDirection(PRUint8 *aBidiTextDirection) { return _to GetBidiTextDirection(aBidiTextDirection); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiTextDirection(PRUint8 aBidiTextDirection) { return _to SetBidiTextDirection(aBidiTextDirection); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiTextType(PRUint8 *aBidiTextType) { return _to GetBidiTextType(aBidiTextType); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiTextType(PRUint8 aBidiTextType) { return _to SetBidiTextType(aBidiTextType); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiControlsTextMode(PRUint8 *aBidiControlsTextMode) { return _to GetBidiControlsTextMode(aBidiControlsTextMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiControlsTextMode(PRUint8 aBidiControlsTextMode) { return _to SetBidiControlsTextMode(aBidiControlsTextMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiNumeral(PRUint8 *aBidiNumeral) { return _to GetBidiNumeral(aBidiNumeral); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiNumeral(PRUint8 aBidiNumeral) { return _to SetBidiNumeral(aBidiNumeral); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiSupport(PRUint8 *aBidiSupport) { return _to GetBidiSupport(aBidiSupport); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiSupport(PRUint8 aBidiSupport) { return _to SetBidiSupport(aBidiSupport); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiCharacterSet(PRUint8 *aBidiCharacterSet) { return _to GetBidiCharacterSet(aBidiCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiCharacterSet(PRUint8 aBidiCharacterSet) { return _to SetBidiCharacterSet(aBidiCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiOptions(PRUint32 *aBidiOptions) { return _to GetBidiOptions(aBidiOptions); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiOptions(PRUint32 aBidiOptions) { return _to SetBidiOptions(aBidiOptions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMARKUPDOCUMENTVIEWER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ScrollToNode(nsIDOMNode *node) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToNode(node); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextZoom(float *aTextZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextZoom(aTextZoom); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextZoom(float aTextZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextZoom(aTextZoom); } \
  NS_SCRIPTABLE NS_IMETHOD GetFullZoom(float *aFullZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullZoom(aFullZoom); } \
  NS_SCRIPTABLE NS_IMETHOD SetFullZoom(float aFullZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFullZoom(aFullZoom); } \
  NS_SCRIPTABLE NS_IMETHOD GetAuthorStyleDisabled(PRBool *aAuthorStyleDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetAuthorStyleDisabled(PRBool aAuthorStyleDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultCharacterSet(nsACString & aDefaultCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultCharacterSet(aDefaultCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultCharacterSet(aDefaultCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceCharacterSet(aForceCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForceCharacterSet(aForceCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHintCharacterSet(aHintCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHintCharacterSet(aHintCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetHintCharacterSetSource(PRInt32 *aHintCharacterSetSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_SCRIPTABLE NS_IMETHOD SetHintCharacterSetSource(PRInt32 aHintCharacterSetSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrevDocCharacterSet(aPrevDocCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrevDocCharacterSet(aPrevDocCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SizeToContent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeToContent(); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiTextDirection(PRUint8 *aBidiTextDirection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiTextDirection(aBidiTextDirection); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiTextDirection(PRUint8 aBidiTextDirection) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiTextDirection(aBidiTextDirection); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiTextType(PRUint8 *aBidiTextType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiTextType(aBidiTextType); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiTextType(PRUint8 aBidiTextType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiTextType(aBidiTextType); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiControlsTextMode(PRUint8 *aBidiControlsTextMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiControlsTextMode(aBidiControlsTextMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiControlsTextMode(PRUint8 aBidiControlsTextMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiControlsTextMode(aBidiControlsTextMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiNumeral(PRUint8 *aBidiNumeral) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiNumeral(aBidiNumeral); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiNumeral(PRUint8 aBidiNumeral) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiNumeral(aBidiNumeral); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiSupport(PRUint8 *aBidiSupport) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiSupport(aBidiSupport); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiSupport(PRUint8 aBidiSupport) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiSupport(aBidiSupport); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiCharacterSet(PRUint8 *aBidiCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiCharacterSet(aBidiCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiCharacterSet(PRUint8 aBidiCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiCharacterSet(aBidiCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetBidiOptions(PRUint32 *aBidiOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBidiOptions(aBidiOptions); } \
  NS_SCRIPTABLE NS_IMETHOD SetBidiOptions(PRUint32 aBidiOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBidiOptions(aBidiOptions); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMarkupDocumentViewer : public nsIMarkupDocumentViewer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMARKUPDOCUMENTVIEWER

  nsMarkupDocumentViewer();

private:
  ~nsMarkupDocumentViewer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMarkupDocumentViewer, nsIMarkupDocumentViewer)

nsMarkupDocumentViewer::nsMarkupDocumentViewer()
{
  /* member initializers and constructor code */
}

nsMarkupDocumentViewer::~nsMarkupDocumentViewer()
{
  /* destructor code */
}

/* void scrollToNode (in nsIDOMNode node); */
NS_IMETHODIMP nsMarkupDocumentViewer::ScrollToNode(nsIDOMNode *node)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float textZoom; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetTextZoom(float *aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetTextZoom(float aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float fullZoom; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetFullZoom(float *aFullZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetFullZoom(float aFullZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean authorStyleDisabled; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetAuthorStyleDisabled(PRBool *aAuthorStyleDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetAuthorStyleDisabled(PRBool aAuthorStyleDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString defaultCharacterSet; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetDefaultCharacterSet(nsACString & aDefaultCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetDefaultCharacterSet(const nsACString & aDefaultCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString forceCharacterSet; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetForceCharacterSet(nsACString & aForceCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetForceCharacterSet(const nsACString & aForceCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString hintCharacterSet; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetHintCharacterSet(nsACString & aHintCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetHintCharacterSet(const nsACString & aHintCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRInt32 hintCharacterSetSource; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetHintCharacterSetSource(PRInt32 *aHintCharacterSetSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetHintCharacterSetSource(PRInt32 aHintCharacterSetSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString prevDocCharacterSet; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetPrevDocCharacterSet(nsACString & aPrevDocCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetPrevDocCharacterSet(const nsACString & aPrevDocCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeToContent (); */
NS_IMETHODIMP nsMarkupDocumentViewer::SizeToContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiTextDirection; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiTextDirection(PRUint8 *aBidiTextDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiTextDirection(PRUint8 aBidiTextDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiTextType; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiTextType(PRUint8 *aBidiTextType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiTextType(PRUint8 aBidiTextType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiControlsTextMode; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiControlsTextMode(PRUint8 *aBidiControlsTextMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiControlsTextMode(PRUint8 aBidiControlsTextMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiNumeral; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiNumeral(PRUint8 *aBidiNumeral)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiNumeral(PRUint8 aBidiNumeral)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiSupport; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiSupport(PRUint8 *aBidiSupport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiSupport(PRUint8 aBidiSupport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet bidiCharacterSet; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiCharacterSet(PRUint8 *aBidiCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiCharacterSet(PRUint8 aBidiCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRUint32 bidiOptions; */
NS_IMETHODIMP nsMarkupDocumentViewer::GetBidiOptions(PRUint32 *aBidiOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMarkupDocumentViewer::SetBidiOptions(PRUint32 aBidiOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMarkupDocumentViewer_h__ */
