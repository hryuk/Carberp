/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLDocument.idl
 */

#ifndef __gen_nsIDOMNSHTMLDocument_h__
#define __gen_nsIDOMNSHTMLDocument_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLDocument */
#define NS_IDOMNSHTMLDOCUMENT_IID_STR "79beb289-3644-4b54-9432-9fb993945629"

#define NS_IDOMNSHTMLDOCUMENT_IID \
  {0x79beb289, 0x3644, 0x4b54, \
    { 0x94, 0x32, 0x9f, 0xb9, 0x93, 0x94, 0x56, 0x29 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLDOCUMENT_IID)

  /* readonly attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;

  /* readonly attribute long height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;

  /* attribute DOMString alinkColor; */
  NS_SCRIPTABLE NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) = 0;

  /* attribute DOMString linkColor; */
  NS_SCRIPTABLE NS_IMETHOD GetLinkColor(nsAString & aLinkColor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) = 0;

  /* attribute DOMString vlinkColor; */
  NS_SCRIPTABLE NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) = 0;

  /* attribute DOMString bgColor; */
  NS_SCRIPTABLE NS_IMETHOD GetBgColor(nsAString & aBgColor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBgColor(const nsAString & aBgColor) = 0;

  /* attribute DOMString fgColor; */
  NS_SCRIPTABLE NS_IMETHOD GetFgColor(nsAString & aFgColor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFgColor(const nsAString & aFgColor) = 0;

  /* attribute DOMString domain; */
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsAString & aDomain) = 0;

  /* readonly attribute nsIDOMHTMLCollection embeds; */
  NS_SCRIPTABLE NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) = 0;

  /* DOMString getSelection (); */
  NS_SCRIPTABLE NS_IMETHOD GetSelection(nsAString & _retval NS_OUTPARAM) = 0;

  /* nsIDOMDocument open (in ACString aContentType, in boolean aReplace); */
  NS_SCRIPTABLE NS_IMETHOD Open(const nsACString & aContentType, PRBool aReplace, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

  /* void write (); */
  NS_SCRIPTABLE NS_IMETHOD Write(void) = 0;

  /* void writeln (); */
  NS_SCRIPTABLE NS_IMETHOD Writeln(void) = 0;

  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

  /**
   * @deprecated These are old Netscape 4 methods. Do not use,
   *             the implementation is no-op.
   */
  /* void captureEvents (in long eventFlags); */
  NS_SCRIPTABLE NS_IMETHOD CaptureEvents(PRInt32 eventFlags) = 0;

  /* void releaseEvents (in long eventFlags); */
  NS_SCRIPTABLE NS_IMETHOD ReleaseEvents(PRInt32 eventFlags) = 0;

  /* void routeEvent (in nsIDOMEvent evt); */
  NS_SCRIPTABLE NS_IMETHOD RouteEvent(nsIDOMEvent *evt) = 0;

  /* readonly attribute DOMString compatMode; */
  NS_SCRIPTABLE NS_IMETHOD GetCompatMode(nsAString & aCompatMode) = 0;

  /* readonly attribute nsIDOMHTMLCollection plugins; */
  NS_SCRIPTABLE NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) = 0;

  /**
    * Midas additions
    */
  /* attribute DOMString designMode; */
  NS_SCRIPTABLE NS_IMETHOD GetDesignMode(nsAString & aDesignMode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) = 0;

  /* boolean execCommand (in DOMString commandID, in boolean doShowUI, in DOMString value); */
  NS_SCRIPTABLE NS_IMETHOD ExecCommand(const nsAString & commandID, PRBool doShowUI, const nsAString & value, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean execCommandShowHelp (in DOMString commandID); */
  NS_SCRIPTABLE NS_IMETHOD ExecCommandShowHelp(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean queryCommandEnabled (in DOMString commandID); */
  NS_SCRIPTABLE NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean queryCommandIndeterm (in DOMString commandID); */
  NS_SCRIPTABLE NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean queryCommandState (in DOMString commandID); */
  NS_SCRIPTABLE NS_IMETHOD QueryCommandState(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean queryCommandSupported (in DOMString commandID); */
  NS_SCRIPTABLE NS_IMETHOD QueryCommandSupported(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) = 0;

  /* DOMString queryCommandText (in DOMString commandID); */
  NS_SCRIPTABLE NS_IMETHOD QueryCommandText(const nsAString & commandID, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString queryCommandValue (in DOMString commandID); */
  NS_SCRIPTABLE NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLDocument, NS_IDOMNSHTMLDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor); \
  NS_SCRIPTABLE NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor); \
  NS_SCRIPTABLE NS_IMETHOD GetLinkColor(nsAString & aLinkColor); \
  NS_SCRIPTABLE NS_IMETHOD SetLinkColor(const nsAString & aLinkColor); \
  NS_SCRIPTABLE NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor); \
  NS_SCRIPTABLE NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor); \
  NS_SCRIPTABLE NS_IMETHOD GetBgColor(nsAString & aBgColor); \
  NS_SCRIPTABLE NS_IMETHOD SetBgColor(const nsAString & aBgColor); \
  NS_SCRIPTABLE NS_IMETHOD GetFgColor(nsAString & aFgColor); \
  NS_SCRIPTABLE NS_IMETHOD SetFgColor(const nsAString & aFgColor); \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain); \
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsAString & aDomain); \
  NS_SCRIPTABLE NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds); \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsACString & aContentType, PRBool aReplace, nsIDOMDocument **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Write(void); \
  NS_SCRIPTABLE NS_IMETHOD Writeln(void); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); \
  NS_SCRIPTABLE NS_IMETHOD CaptureEvents(PRInt32 eventFlags); \
  NS_SCRIPTABLE NS_IMETHOD ReleaseEvents(PRInt32 eventFlags); \
  NS_SCRIPTABLE NS_IMETHOD RouteEvent(nsIDOMEvent *evt); \
  NS_SCRIPTABLE NS_IMETHOD GetCompatMode(nsAString & aCompatMode); \
  NS_SCRIPTABLE NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins); \
  NS_SCRIPTABLE NS_IMETHOD GetDesignMode(nsAString & aDesignMode); \
  NS_SCRIPTABLE NS_IMETHOD SetDesignMode(const nsAString & aDesignMode); \
  NS_SCRIPTABLE NS_IMETHOD ExecCommand(const nsAString & commandID, PRBool doShowUI, const nsAString & value, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ExecCommandShowHelp(const nsAString & commandID, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandState(const nsAString & commandID, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandSupported(const nsAString & commandID, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandText(const nsAString & commandID, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) { return _to GetAlinkColor(aAlinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) { return _to SetAlinkColor(aAlinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkColor(nsAString & aLinkColor) { return _to GetLinkColor(aLinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) { return _to SetLinkColor(aLinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) { return _to GetVlinkColor(aVlinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) { return _to SetVlinkColor(aVlinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetBgColor(nsAString & aBgColor) { return _to GetBgColor(aBgColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetBgColor(const nsAString & aBgColor) { return _to SetBgColor(aBgColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetFgColor(nsAString & aFgColor) { return _to GetFgColor(aFgColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetFgColor(const nsAString & aFgColor) { return _to SetFgColor(aFgColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return _to GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsAString & aDomain) { return _to SetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) { return _to GetEmbeds(aEmbeds); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(nsAString & _retval NS_OUTPARAM) { return _to GetSelection(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsACString & aContentType, PRBool aReplace, nsIDOMDocument **_retval NS_OUTPARAM) { return _to Open(aContentType, aReplace, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Write(void) { return _to Write(); } \
  NS_SCRIPTABLE NS_IMETHOD Writeln(void) { return _to Writeln(); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD CaptureEvents(PRInt32 eventFlags) { return _to CaptureEvents(eventFlags); } \
  NS_SCRIPTABLE NS_IMETHOD ReleaseEvents(PRInt32 eventFlags) { return _to ReleaseEvents(eventFlags); } \
  NS_SCRIPTABLE NS_IMETHOD RouteEvent(nsIDOMEvent *evt) { return _to RouteEvent(evt); } \
  NS_SCRIPTABLE NS_IMETHOD GetCompatMode(nsAString & aCompatMode) { return _to GetCompatMode(aCompatMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) { return _to GetPlugins(aPlugins); } \
  NS_SCRIPTABLE NS_IMETHOD GetDesignMode(nsAString & aDesignMode) { return _to GetDesignMode(aDesignMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) { return _to SetDesignMode(aDesignMode); } \
  NS_SCRIPTABLE NS_IMETHOD ExecCommand(const nsAString & commandID, PRBool doShowUI, const nsAString & value, PRBool *_retval NS_OUTPARAM) { return _to ExecCommand(commandID, doShowUI, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecCommandShowHelp(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return _to ExecCommandShowHelp(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return _to QueryCommandEnabled(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return _to QueryCommandIndeterm(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandState(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return _to QueryCommandState(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandSupported(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return _to QueryCommandSupported(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandText(const nsAString & commandID, nsAString & _retval NS_OUTPARAM) { return _to QueryCommandText(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval NS_OUTPARAM) { return _to QueryCommandValue(commandID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlinkColor(aAlinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlinkColor(aAlinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkColor(nsAString & aLinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkColor(aLinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLinkColor(aLinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVlinkColor(aVlinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVlinkColor(aVlinkColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetBgColor(nsAString & aBgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBgColor(aBgColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetBgColor(const nsAString & aBgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBgColor(aBgColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetFgColor(nsAString & aFgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFgColor(aFgColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetFgColor(const nsAString & aFgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFgColor(aFgColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmbeds(aEmbeds); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsACString & aContentType, PRBool aReplace, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aContentType, aReplace, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Write(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(); } \
  NS_SCRIPTABLE NS_IMETHOD Writeln(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Writeln(); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD CaptureEvents(PRInt32 eventFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CaptureEvents(eventFlags); } \
  NS_SCRIPTABLE NS_IMETHOD ReleaseEvents(PRInt32 eventFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseEvents(eventFlags); } \
  NS_SCRIPTABLE NS_IMETHOD RouteEvent(nsIDOMEvent *evt) { return !_to ? NS_ERROR_NULL_POINTER : _to->RouteEvent(evt); } \
  NS_SCRIPTABLE NS_IMETHOD GetCompatMode(nsAString & aCompatMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompatMode(aCompatMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlugins(aPlugins); } \
  NS_SCRIPTABLE NS_IMETHOD GetDesignMode(nsAString & aDesignMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDesignMode(aDesignMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDesignMode(aDesignMode); } \
  NS_SCRIPTABLE NS_IMETHOD ExecCommand(const nsAString & commandID, PRBool doShowUI, const nsAString & value, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecCommand(commandID, doShowUI, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecCommandShowHelp(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecCommandShowHelp(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandEnabled(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandIndeterm(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandState(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandState(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandSupported(const nsAString & commandID, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandSupported(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandText(const nsAString & commandID, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandText(commandID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandValue(commandID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLDocument : public nsIDOMNSHTMLDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLDOCUMENT

  nsDOMNSHTMLDocument();

private:
  ~nsDOMNSHTMLDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLDocument, nsIDOMNSHTMLDocument)

nsDOMNSHTMLDocument::nsDOMNSHTMLDocument()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLDocument::~nsDOMNSHTMLDocument()
{
  /* destructor code */
}

/* readonly attribute long width; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long height; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString alinkColor; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetAlinkColor(nsAString & aAlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLDocument::SetAlinkColor(const nsAString & aAlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString linkColor; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetLinkColor(nsAString & aLinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLDocument::SetLinkColor(const nsAString & aLinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString vlinkColor; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetVlinkColor(nsAString & aVlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLDocument::SetVlinkColor(const nsAString & aVlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString bgColor; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetBgColor(nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLDocument::SetBgColor(const nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString fgColor; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetFgColor(nsAString & aFgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLDocument::SetFgColor(const nsAString & aFgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString domain; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetDomain(nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLDocument::SetDomain(const nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection embeds; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetEmbeds(nsIDOMHTMLCollection * *aEmbeds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getSelection (); */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetSelection(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument open (in ACString aContentType, in boolean aReplace); */
NS_IMETHODIMP nsDOMNSHTMLDocument::Open(const nsACString & aContentType, PRBool aReplace, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write (); */
NS_IMETHODIMP nsDOMNSHTMLDocument::Write()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeln (); */
NS_IMETHODIMP nsDOMNSHTMLDocument::Writeln()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMNSHTMLDocument::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void captureEvents (in long eventFlags); */
NS_IMETHODIMP nsDOMNSHTMLDocument::CaptureEvents(PRInt32 eventFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseEvents (in long eventFlags); */
NS_IMETHODIMP nsDOMNSHTMLDocument::ReleaseEvents(PRInt32 eventFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void routeEvent (in nsIDOMEvent evt); */
NS_IMETHODIMP nsDOMNSHTMLDocument::RouteEvent(nsIDOMEvent *evt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString compatMode; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetCompatMode(nsAString & aCompatMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection plugins; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetPlugins(nsIDOMHTMLCollection * *aPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString designMode; */
NS_IMETHODIMP nsDOMNSHTMLDocument::GetDesignMode(nsAString & aDesignMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLDocument::SetDesignMode(const nsAString & aDesignMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean execCommand (in DOMString commandID, in boolean doShowUI, in DOMString value); */
NS_IMETHODIMP nsDOMNSHTMLDocument::ExecCommand(const nsAString & commandID, PRBool doShowUI, const nsAString & value, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean execCommandShowHelp (in DOMString commandID); */
NS_IMETHODIMP nsDOMNSHTMLDocument::ExecCommandShowHelp(const nsAString & commandID, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandEnabled (in DOMString commandID); */
NS_IMETHODIMP nsDOMNSHTMLDocument::QueryCommandEnabled(const nsAString & commandID, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandIndeterm (in DOMString commandID); */
NS_IMETHODIMP nsDOMNSHTMLDocument::QueryCommandIndeterm(const nsAString & commandID, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandState (in DOMString commandID); */
NS_IMETHODIMP nsDOMNSHTMLDocument::QueryCommandState(const nsAString & commandID, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandSupported (in DOMString commandID); */
NS_IMETHODIMP nsDOMNSHTMLDocument::QueryCommandSupported(const nsAString & commandID, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString queryCommandText (in DOMString commandID); */
NS_IMETHODIMP nsDOMNSHTMLDocument::QueryCommandText(const nsAString & commandID, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString queryCommandValue (in DOMString commandID); */
NS_IMETHODIMP nsDOMNSHTMLDocument::QueryCommandValue(const nsAString & commandID, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLDocument_h__ */
