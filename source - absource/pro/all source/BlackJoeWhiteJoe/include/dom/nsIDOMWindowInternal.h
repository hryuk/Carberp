/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMWindowInternal.idl
 */

#ifndef __gen_nsIDOMWindowInternal_h__
#define __gen_nsIDOMWindowInternal_h__


#ifndef __gen_nsIDOMWindow2_h__
#include "nsIDOMWindow2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrompt; /* forward declaration */

class nsIControllers; /* forward declaration */

class nsIDOMLocation; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMWindowInternal */
#define NS_IDOMWINDOWINTERNAL_IID_STR "3414ebc7-731f-4697-9f43-aca6f5050875"

#define NS_IDOMWINDOWINTERNAL_IID \
  {0x3414ebc7, 0x731f, 0x4697, \
    { 0x9f, 0x43, 0xac, 0xa6, 0xf5, 0x05, 0x08, 0x75 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMWindowInternal : public nsIDOMWindow2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOWINTERNAL_IID)

  /* readonly attribute nsIDOMWindowInternal window; */
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindowInternal * *aWindow) = 0;

  /* readonly attribute nsIDOMWindowInternal self; */
  NS_SCRIPTABLE NS_IMETHOD GetSelf(nsIDOMWindowInternal * *aSelf) = 0;

  /* readonly attribute nsIDOMNavigator navigator; */
  NS_SCRIPTABLE NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) = 0;

  /* readonly attribute nsIDOMScreen screen; */
  NS_SCRIPTABLE NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) = 0;

  /* readonly attribute nsIDOMHistory history; */
  NS_SCRIPTABLE NS_IMETHOD GetHistory(nsIDOMHistory * *aHistory) = 0;

  /* readonly attribute nsIDOMWindow content; */
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIDOMWindow * *aContent) = 0;

  /* [noscript] readonly attribute nsIPrompt prompter; */
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) = 0;

  /* readonly attribute nsIDOMBarProp menubar; */
  NS_SCRIPTABLE NS_IMETHOD GetMenubar(nsIDOMBarProp * *aMenubar) = 0;

  /* readonly attribute nsIDOMBarProp toolbar; */
  NS_SCRIPTABLE NS_IMETHOD GetToolbar(nsIDOMBarProp * *aToolbar) = 0;

  /* readonly attribute nsIDOMBarProp locationbar; */
  NS_SCRIPTABLE NS_IMETHOD GetLocationbar(nsIDOMBarProp * *aLocationbar) = 0;

  /* readonly attribute nsIDOMBarProp personalbar; */
  NS_SCRIPTABLE NS_IMETHOD GetPersonalbar(nsIDOMBarProp * *aPersonalbar) = 0;

  /* readonly attribute nsIDOMBarProp statusbar; */
  NS_SCRIPTABLE NS_IMETHOD GetStatusbar(nsIDOMBarProp * *aStatusbar) = 0;

  /* readonly attribute nsIDOMBarProp directories; */
  NS_SCRIPTABLE NS_IMETHOD GetDirectories(nsIDOMBarProp * *aDirectories) = 0;

  /* readonly attribute boolean closed; */
  NS_SCRIPTABLE NS_IMETHOD GetClosed(PRBool *aClosed) = 0;

  /* readonly attribute nsIDOMCrypto crypto; */
  NS_SCRIPTABLE NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) = 0;

  /* readonly attribute nsIDOMPkcs11 pkcs11; */
  NS_SCRIPTABLE NS_IMETHOD GetPkcs11(nsIDOMPkcs11 * *aPkcs11) = 0;

  /* readonly attribute nsIControllers controllers; */
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers) = 0;

  /* attribute nsIDOMWindowInternal opener; */
  NS_SCRIPTABLE NS_IMETHOD GetOpener(nsIDOMWindowInternal * *aOpener) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOpener(nsIDOMWindowInternal * aOpener) = 0;

  /* attribute DOMString status; */
  NS_SCRIPTABLE NS_IMETHOD GetStatus(nsAString & aStatus) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStatus(const nsAString & aStatus) = 0;

  /* attribute DOMString defaultStatus; */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultStatus(nsAString & aDefaultStatus) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDefaultStatus(const nsAString & aDefaultStatus) = 0;

  /* readonly attribute nsIDOMLocation location; */
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) = 0;

  /* attribute long innerWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetInnerWidth(PRInt32 *aInnerWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInnerWidth(PRInt32 aInnerWidth) = 0;

  /* attribute long innerHeight; */
  NS_SCRIPTABLE NS_IMETHOD GetInnerHeight(PRInt32 *aInnerHeight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInnerHeight(PRInt32 aInnerHeight) = 0;

  /* attribute long outerWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetOuterWidth(PRInt32 *aOuterWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOuterWidth(PRInt32 aOuterWidth) = 0;

  /* attribute long outerHeight; */
  NS_SCRIPTABLE NS_IMETHOD GetOuterHeight(PRInt32 *aOuterHeight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOuterHeight(PRInt32 aOuterHeight) = 0;

  /* attribute long screenX; */
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetScreenX(PRInt32 aScreenX) = 0;

  /* attribute long screenY; */
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetScreenY(PRInt32 aScreenY) = 0;

  /* readonly attribute long pageXOffset; */
  NS_SCRIPTABLE NS_IMETHOD GetPageXOffset(PRInt32 *aPageXOffset) = 0;

  /* readonly attribute long pageYOffset; */
  NS_SCRIPTABLE NS_IMETHOD GetPageYOffset(PRInt32 *aPageYOffset) = 0;

  /* readonly attribute long scrollMaxX; */
  NS_SCRIPTABLE NS_IMETHOD GetScrollMaxX(PRInt32 *aScrollMaxX) = 0;

  /* readonly attribute long scrollMaxY; */
  NS_SCRIPTABLE NS_IMETHOD GetScrollMaxY(PRInt32 *aScrollMaxY) = 0;

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* attribute boolean fullScreen; */
  NS_SCRIPTABLE NS_IMETHOD GetFullScreen(PRBool *aFullScreen) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFullScreen(PRBool aFullScreen) = 0;

  /* void alert (in DOMString text); */
  NS_SCRIPTABLE NS_IMETHOD Alert(const nsAString & text) = 0;

  /* boolean confirm (in DOMString text); */
  NS_SCRIPTABLE NS_IMETHOD Confirm(const nsAString & text, PRBool *_retval NS_OUTPARAM) = 0;

  /* DOMString prompt ([optional] in DOMString aMessage, [optional] in DOMString aInitial, [optional] in DOMString aTitle, [optional] in unsigned long aSavePassword); */
  NS_SCRIPTABLE NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, const nsAString & aTitle, PRUint32 aSavePassword, nsAString & _retval NS_OUTPARAM) = 0;

  /* void focus (); */
  NS_SCRIPTABLE NS_IMETHOD Focus(void) = 0;

  /* void blur (); */
  NS_SCRIPTABLE NS_IMETHOD Blur(void) = 0;

  /* void back (); */
  NS_SCRIPTABLE NS_IMETHOD Back(void) = 0;

  /* void forward (); */
  NS_SCRIPTABLE NS_IMETHOD Forward(void) = 0;

  /* void home (); */
  NS_SCRIPTABLE NS_IMETHOD Home(void) = 0;

  /* void stop (); */
  NS_SCRIPTABLE NS_IMETHOD Stop(void) = 0;

  /* void print (); */
  NS_SCRIPTABLE NS_IMETHOD Print(void) = 0;

  /* void moveTo (in long xPos, in long yPos); */
  NS_SCRIPTABLE NS_IMETHOD MoveTo(PRInt32 xPos, PRInt32 yPos) = 0;

  /* void moveBy (in long xDif, in long yDif); */
  NS_SCRIPTABLE NS_IMETHOD MoveBy(PRInt32 xDif, PRInt32 yDif) = 0;

  /* void resizeTo (in long width, in long height); */
  NS_SCRIPTABLE NS_IMETHOD ResizeTo(PRInt32 width, PRInt32 height) = 0;

  /* void resizeBy (in long widthDif, in long heightDif); */
  NS_SCRIPTABLE NS_IMETHOD ResizeBy(PRInt32 widthDif, PRInt32 heightDif) = 0;

  /* void scroll (in long xScroll, in long yScroll); */
  NS_SCRIPTABLE NS_IMETHOD Scroll(PRInt32 xScroll, PRInt32 yScroll) = 0;

  /**
   * Open a new window with this one as the parent.  This method will
   * NOT examine the JS stack for purposes of determining a caller.
   * This window will be used for security checks during the search by
   * name and the default character set on the newly opened window
   * will just be the default character set of this window.
   */
  /* [noscript] nsIDOMWindow open (in DOMString url, in DOMString name, in DOMString options); */
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM) = 0;

  /**
   * This method works like open except that aExtraArgument gets
   * converted into the array window.arguments in JS, if
   * aExtraArgument is a nsISupportsArray then the individual items in
   * the array are inserted into window.arguments, and primitive
   * nsISupports (nsISupportsPrimitives) types are converted to native
   * JS types when possible.
   */
  /* [noscript] nsIDOMWindow openDialog (in DOMString url, in DOMString name, in DOMString options, in nsISupports aExtraArgument); */
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow **_retval NS_OUTPARAM) = 0;

  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /* void updateCommands (in DOMString action); */
  NS_SCRIPTABLE NS_IMETHOD UpdateCommands(const nsAString & action) = 0;

  /* boolean find ([optional] in DOMString str, [optional] in boolean caseSensitive, [optional] in boolean backwards, [optional] in boolean wrapAround, [optional] in boolean wholeWord, [optional] in boolean searchInFrames, [optional] in boolean showDialog); */
  NS_SCRIPTABLE NS_IMETHOD Find(const nsAString & str, PRBool caseSensitive, PRBool backwards, PRBool wrapAround, PRBool wholeWord, PRBool searchInFrames, PRBool showDialog, PRBool *_retval NS_OUTPARAM) = 0;

  /* DOMString atob (in DOMString aAsciiString); */
  NS_SCRIPTABLE NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString btoa (in DOMString aBase64Data); */
  NS_SCRIPTABLE NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM) = 0;

  /* readonly attribute nsIDOMElement frameElement; */
  NS_SCRIPTABLE NS_IMETHOD GetFrameElement(nsIDOMElement * *aFrameElement) = 0;

  /* nsIVariant showModalDialog (in DOMString aURI, [optional] in nsIVariant aArgs, [optional] in DOMString aOptions); */
  NS_SCRIPTABLE NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
   * Implements a safe message-passing system which can cross same-origin
   * boundaries.
   *
   * This method, when called, causes a MessageEvent to be asynchronously
   * dispatched at the primary document for the window upon which this method is
   * called.  (Note that the postMessage property on windows is allAccess and
   * thus is readable cross-origin.)  The dispatched event will have message as
   * its data, the calling context's window as its source, and an origin
   * determined by the calling context's main document URI.  The targetOrigin
   * argument specifies a URI and is used to restrict the message to be sent
   * only when the target window has the same origin as targetOrigin (since,
   * when the sender and the target have different origins, neither can read the
   * location of the other).
   * 
   * See the WHATWG HTML5 specification, section 6.4, for more details.
   */
  /* [binaryname (PostMessageMoz)] void postMessage (in DOMString message, in DOMString targetOrigin); */
  NS_SCRIPTABLE NS_IMETHOD PostMessageMoz(const nsAString & message, const nsAString & targetOrigin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindowInternal, NS_IDOMWINDOWINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOWINTERNAL \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindowInternal * *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetSelf(nsIDOMWindowInternal * *aSelf); \
  NS_SCRIPTABLE NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator); \
  NS_SCRIPTABLE NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen); \
  NS_SCRIPTABLE NS_IMETHOD GetHistory(nsIDOMHistory * *aHistory); \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIDOMWindow * *aContent); \
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter); \
  NS_SCRIPTABLE NS_IMETHOD GetMenubar(nsIDOMBarProp * *aMenubar); \
  NS_SCRIPTABLE NS_IMETHOD GetToolbar(nsIDOMBarProp * *aToolbar); \
  NS_SCRIPTABLE NS_IMETHOD GetLocationbar(nsIDOMBarProp * *aLocationbar); \
  NS_SCRIPTABLE NS_IMETHOD GetPersonalbar(nsIDOMBarProp * *aPersonalbar); \
  NS_SCRIPTABLE NS_IMETHOD GetStatusbar(nsIDOMBarProp * *aStatusbar); \
  NS_SCRIPTABLE NS_IMETHOD GetDirectories(nsIDOMBarProp * *aDirectories); \
  NS_SCRIPTABLE NS_IMETHOD GetClosed(PRBool *aClosed); \
  NS_SCRIPTABLE NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto); \
  NS_SCRIPTABLE NS_IMETHOD GetPkcs11(nsIDOMPkcs11 * *aPkcs11); \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers); \
  NS_SCRIPTABLE NS_IMETHOD GetOpener(nsIDOMWindowInternal * *aOpener); \
  NS_SCRIPTABLE NS_IMETHOD SetOpener(nsIDOMWindowInternal * aOpener); \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(nsAString & aStatus); \
  NS_SCRIPTABLE NS_IMETHOD SetStatus(const nsAString & aStatus); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultStatus(nsAString & aDefaultStatus); \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultStatus(const nsAString & aDefaultStatus); \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation); \
  NS_SCRIPTABLE NS_IMETHOD GetInnerWidth(PRInt32 *aInnerWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetInnerWidth(PRInt32 aInnerWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetInnerHeight(PRInt32 *aInnerHeight); \
  NS_SCRIPTABLE NS_IMETHOD SetInnerHeight(PRInt32 aInnerHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetOuterWidth(PRInt32 *aOuterWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetOuterWidth(PRInt32 aOuterWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetOuterHeight(PRInt32 *aOuterHeight); \
  NS_SCRIPTABLE NS_IMETHOD SetOuterHeight(PRInt32 aOuterHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX); \
  NS_SCRIPTABLE NS_IMETHOD SetScreenX(PRInt32 aScreenX); \
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY); \
  NS_SCRIPTABLE NS_IMETHOD SetScreenY(PRInt32 aScreenY); \
  NS_SCRIPTABLE NS_IMETHOD GetPageXOffset(PRInt32 *aPageXOffset); \
  NS_SCRIPTABLE NS_IMETHOD GetPageYOffset(PRInt32 *aPageYOffset); \
  NS_SCRIPTABLE NS_IMETHOD GetScrollMaxX(PRInt32 *aScrollMaxX); \
  NS_SCRIPTABLE NS_IMETHOD GetScrollMaxY(PRInt32 *aScrollMaxY); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD GetFullScreen(PRBool *aFullScreen); \
  NS_SCRIPTABLE NS_IMETHOD SetFullScreen(PRBool aFullScreen); \
  NS_SCRIPTABLE NS_IMETHOD Alert(const nsAString & text); \
  NS_SCRIPTABLE NS_IMETHOD Confirm(const nsAString & text, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, const nsAString & aTitle, PRUint32 aSavePassword, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Focus(void); \
  NS_SCRIPTABLE NS_IMETHOD Blur(void); \
  NS_SCRIPTABLE NS_IMETHOD Back(void); \
  NS_SCRIPTABLE NS_IMETHOD Forward(void); \
  NS_SCRIPTABLE NS_IMETHOD Home(void); \
  NS_SCRIPTABLE NS_IMETHOD Stop(void); \
  NS_SCRIPTABLE NS_IMETHOD Print(void); \
  NS_SCRIPTABLE NS_IMETHOD MoveTo(PRInt32 xPos, PRInt32 yPos); \
  NS_SCRIPTABLE NS_IMETHOD MoveBy(PRInt32 xDif, PRInt32 yDif); \
  NS_SCRIPTABLE NS_IMETHOD ResizeTo(PRInt32 width, PRInt32 height); \
  NS_SCRIPTABLE NS_IMETHOD ResizeBy(PRInt32 widthDif, PRInt32 heightDif); \
  NS_SCRIPTABLE NS_IMETHOD Scroll(PRInt32 xScroll, PRInt32 yScroll); \
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM); \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD UpdateCommands(const nsAString & action); \
  NS_SCRIPTABLE NS_IMETHOD Find(const nsAString & str, PRBool caseSensitive, PRBool backwards, PRBool wrapAround, PRBool wholeWord, PRBool searchInFrames, PRBool showDialog, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFrameElement(nsIDOMElement * *aFrameElement); \
  NS_SCRIPTABLE NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PostMessageMoz(const nsAString & message, const nsAString & targetOrigin); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOWINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindowInternal * *aWindow) { return _to GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelf(nsIDOMWindowInternal * *aSelf) { return _to GetSelf(aSelf); } \
  NS_SCRIPTABLE NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) { return _to GetNavigator(aNavigator); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) { return _to GetScreen(aScreen); } \
  NS_SCRIPTABLE NS_IMETHOD GetHistory(nsIDOMHistory * *aHistory) { return _to GetHistory(aHistory); } \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIDOMWindow * *aContent) { return _to GetContent(aContent); } \
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) { return _to GetPrompter(aPrompter); } \
  NS_SCRIPTABLE NS_IMETHOD GetMenubar(nsIDOMBarProp * *aMenubar) { return _to GetMenubar(aMenubar); } \
  NS_SCRIPTABLE NS_IMETHOD GetToolbar(nsIDOMBarProp * *aToolbar) { return _to GetToolbar(aToolbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocationbar(nsIDOMBarProp * *aLocationbar) { return _to GetLocationbar(aLocationbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetPersonalbar(nsIDOMBarProp * *aPersonalbar) { return _to GetPersonalbar(aPersonalbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatusbar(nsIDOMBarProp * *aStatusbar) { return _to GetStatusbar(aStatusbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetDirectories(nsIDOMBarProp * *aDirectories) { return _to GetDirectories(aDirectories); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosed(PRBool *aClosed) { return _to GetClosed(aClosed); } \
  NS_SCRIPTABLE NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) { return _to GetCrypto(aCrypto); } \
  NS_SCRIPTABLE NS_IMETHOD GetPkcs11(nsIDOMPkcs11 * *aPkcs11) { return _to GetPkcs11(aPkcs11); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers) { return _to GetControllers(aControllers); } \
  NS_SCRIPTABLE NS_IMETHOD GetOpener(nsIDOMWindowInternal * *aOpener) { return _to GetOpener(aOpener); } \
  NS_SCRIPTABLE NS_IMETHOD SetOpener(nsIDOMWindowInternal * aOpener) { return _to SetOpener(aOpener); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(nsAString & aStatus) { return _to GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD SetStatus(const nsAString & aStatus) { return _to SetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultStatus(nsAString & aDefaultStatus) { return _to GetDefaultStatus(aDefaultStatus); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultStatus(const nsAString & aDefaultStatus) { return _to SetDefaultStatus(aDefaultStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) { return _to GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerWidth(PRInt32 *aInnerWidth) { return _to GetInnerWidth(aInnerWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetInnerWidth(PRInt32 aInnerWidth) { return _to SetInnerWidth(aInnerWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerHeight(PRInt32 *aInnerHeight) { return _to GetInnerHeight(aInnerHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetInnerHeight(PRInt32 aInnerHeight) { return _to SetInnerHeight(aInnerHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetOuterWidth(PRInt32 *aOuterWidth) { return _to GetOuterWidth(aOuterWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetOuterWidth(PRInt32 aOuterWidth) { return _to SetOuterWidth(aOuterWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetOuterHeight(PRInt32 *aOuterHeight) { return _to GetOuterHeight(aOuterHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetOuterHeight(PRInt32 aOuterHeight) { return _to SetOuterHeight(aOuterHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX) { return _to GetScreenX(aScreenX); } \
  NS_SCRIPTABLE NS_IMETHOD SetScreenX(PRInt32 aScreenX) { return _to SetScreenX(aScreenX); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY) { return _to GetScreenY(aScreenY); } \
  NS_SCRIPTABLE NS_IMETHOD SetScreenY(PRInt32 aScreenY) { return _to SetScreenY(aScreenY); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageXOffset(PRInt32 *aPageXOffset) { return _to GetPageXOffset(aPageXOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageYOffset(PRInt32 *aPageYOffset) { return _to GetPageYOffset(aPageYOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollMaxX(PRInt32 *aScrollMaxX) { return _to GetScrollMaxX(aScrollMaxX); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollMaxY(PRInt32 *aScrollMaxY) { return _to GetScrollMaxY(aScrollMaxY); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetFullScreen(PRBool *aFullScreen) { return _to GetFullScreen(aFullScreen); } \
  NS_SCRIPTABLE NS_IMETHOD SetFullScreen(PRBool aFullScreen) { return _to SetFullScreen(aFullScreen); } \
  NS_SCRIPTABLE NS_IMETHOD Alert(const nsAString & text) { return _to Alert(text); } \
  NS_SCRIPTABLE NS_IMETHOD Confirm(const nsAString & text, PRBool *_retval NS_OUTPARAM) { return _to Confirm(text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, const nsAString & aTitle, PRUint32 aSavePassword, nsAString & _retval NS_OUTPARAM) { return _to Prompt(aMessage, aInitial, aTitle, aSavePassword, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return _to Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return _to Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD Back(void) { return _to Back(); } \
  NS_SCRIPTABLE NS_IMETHOD Forward(void) { return _to Forward(); } \
  NS_SCRIPTABLE NS_IMETHOD Home(void) { return _to Home(); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(void) { return _to Stop(); } \
  NS_SCRIPTABLE NS_IMETHOD Print(void) { return _to Print(); } \
  NS_SCRIPTABLE NS_IMETHOD MoveTo(PRInt32 xPos, PRInt32 yPos) { return _to MoveTo(xPos, yPos); } \
  NS_SCRIPTABLE NS_IMETHOD MoveBy(PRInt32 xDif, PRInt32 yDif) { return _to MoveBy(xDif, yDif); } \
  NS_SCRIPTABLE NS_IMETHOD ResizeTo(PRInt32 width, PRInt32 height) { return _to ResizeTo(width, height); } \
  NS_SCRIPTABLE NS_IMETHOD ResizeBy(PRInt32 widthDif, PRInt32 heightDif) { return _to ResizeBy(widthDif, heightDif); } \
  NS_SCRIPTABLE NS_IMETHOD Scroll(PRInt32 xScroll, PRInt32 yScroll) { return _to Scroll(xScroll, yScroll); } \
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM) { return _to Open(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow **_retval NS_OUTPARAM) { return _to OpenDialog(url, name, options, aExtraArgument, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateCommands(const nsAString & action) { return _to UpdateCommands(action); } \
  NS_SCRIPTABLE NS_IMETHOD Find(const nsAString & str, PRBool caseSensitive, PRBool backwards, PRBool wrapAround, PRBool wholeWord, PRBool searchInFrames, PRBool showDialog, PRBool *_retval NS_OUTPARAM) { return _to Find(str, caseSensitive, backwards, wrapAround, wholeWord, searchInFrames, showDialog, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM) { return _to Atob(aAsciiString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM) { return _to Btoa(aBase64Data, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFrameElement(nsIDOMElement * *aFrameElement) { return _to GetFrameElement(aFrameElement); } \
  NS_SCRIPTABLE NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant **_retval NS_OUTPARAM) { return _to ShowModalDialog(aURI, aArgs, aOptions, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD PostMessageMoz(const nsAString & message, const nsAString & targetOrigin) { return _to PostMessageMoz(message, targetOrigin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOWINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindowInternal * *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelf(nsIDOMWindowInternal * *aSelf) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelf(aSelf); } \
  NS_SCRIPTABLE NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNavigator(aNavigator); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreen(aScreen); } \
  NS_SCRIPTABLE NS_IMETHOD GetHistory(nsIDOMHistory * *aHistory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistory(aHistory); } \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIDOMWindow * *aContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContent(aContent); } \
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrompter(aPrompter); } \
  NS_SCRIPTABLE NS_IMETHOD GetMenubar(nsIDOMBarProp * *aMenubar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMenubar(aMenubar); } \
  NS_SCRIPTABLE NS_IMETHOD GetToolbar(nsIDOMBarProp * *aToolbar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetToolbar(aToolbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocationbar(nsIDOMBarProp * *aLocationbar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocationbar(aLocationbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetPersonalbar(nsIDOMBarProp * *aPersonalbar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersonalbar(aPersonalbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatusbar(nsIDOMBarProp * *aStatusbar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatusbar(aStatusbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetDirectories(nsIDOMBarProp * *aDirectories) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirectories(aDirectories); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosed(PRBool *aClosed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClosed(aClosed); } \
  NS_SCRIPTABLE NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrypto(aCrypto); } \
  NS_SCRIPTABLE NS_IMETHOD GetPkcs11(nsIDOMPkcs11 * *aPkcs11) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPkcs11(aPkcs11); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllers(aControllers); } \
  NS_SCRIPTABLE NS_IMETHOD GetOpener(nsIDOMWindowInternal * *aOpener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOpener(aOpener); } \
  NS_SCRIPTABLE NS_IMETHOD SetOpener(nsIDOMWindowInternal * aOpener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOpener(aOpener); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(nsAString & aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD SetStatus(const nsAString & aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultStatus(nsAString & aDefaultStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultStatus(aDefaultStatus); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultStatus(const nsAString & aDefaultStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultStatus(aDefaultStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerWidth(PRInt32 *aInnerWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerWidth(aInnerWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetInnerWidth(PRInt32 aInnerWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInnerWidth(aInnerWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerHeight(PRInt32 *aInnerHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerHeight(aInnerHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetInnerHeight(PRInt32 aInnerHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInnerHeight(aInnerHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetOuterWidth(PRInt32 *aOuterWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWidth(aOuterWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetOuterWidth(PRInt32 aOuterWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOuterWidth(aOuterWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetOuterHeight(PRInt32 *aOuterHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterHeight(aOuterHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetOuterHeight(PRInt32 aOuterHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOuterHeight(aOuterHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenX(aScreenX); } \
  NS_SCRIPTABLE NS_IMETHOD SetScreenX(PRInt32 aScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScreenX(aScreenX); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenY(aScreenY); } \
  NS_SCRIPTABLE NS_IMETHOD SetScreenY(PRInt32 aScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScreenY(aScreenY); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageXOffset(PRInt32 *aPageXOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageXOffset(aPageXOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageYOffset(PRInt32 *aPageYOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageYOffset(aPageYOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollMaxX(PRInt32 *aScrollMaxX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollMaxX(aScrollMaxX); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollMaxY(PRInt32 *aScrollMaxY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollMaxY(aScrollMaxY); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetFullScreen(PRBool *aFullScreen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullScreen(aFullScreen); } \
  NS_SCRIPTABLE NS_IMETHOD SetFullScreen(PRBool aFullScreen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFullScreen(aFullScreen); } \
  NS_SCRIPTABLE NS_IMETHOD Alert(const nsAString & text) { return !_to ? NS_ERROR_NULL_POINTER : _to->Alert(text); } \
  NS_SCRIPTABLE NS_IMETHOD Confirm(const nsAString & text, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Confirm(text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, const nsAString & aTitle, PRUint32 aSavePassword, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Prompt(aMessage, aInitial, aTitle, aSavePassword, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD Back(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Back(); } \
  NS_SCRIPTABLE NS_IMETHOD Forward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Forward(); } \
  NS_SCRIPTABLE NS_IMETHOD Home(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Home(); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_SCRIPTABLE NS_IMETHOD Print(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Print(); } \
  NS_SCRIPTABLE NS_IMETHOD MoveTo(PRInt32 xPos, PRInt32 yPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveTo(xPos, yPos); } \
  NS_SCRIPTABLE NS_IMETHOD MoveBy(PRInt32 xDif, PRInt32 yDif) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveBy(xDif, yDif); } \
  NS_SCRIPTABLE NS_IMETHOD ResizeTo(PRInt32 width, PRInt32 height) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResizeTo(width, height); } \
  NS_SCRIPTABLE NS_IMETHOD ResizeBy(PRInt32 widthDif, PRInt32 heightDif) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResizeBy(widthDif, heightDif); } \
  NS_SCRIPTABLE NS_IMETHOD Scroll(PRInt32 xScroll, PRInt32 yScroll) { return !_to ? NS_ERROR_NULL_POINTER : _to->Scroll(xScroll, yScroll); } \
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDialog(url, name, options, aExtraArgument, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateCommands(const nsAString & action) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCommands(action); } \
  NS_SCRIPTABLE NS_IMETHOD Find(const nsAString & str, PRBool caseSensitive, PRBool backwards, PRBool wrapAround, PRBool wholeWord, PRBool searchInFrames, PRBool showDialog, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Find(str, caseSensitive, backwards, wrapAround, wholeWord, searchInFrames, showDialog, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Atob(aAsciiString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Btoa(aBase64Data, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFrameElement(nsIDOMElement * *aFrameElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameElement(aFrameElement); } \
  NS_SCRIPTABLE NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowModalDialog(aURI, aArgs, aOptions, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD PostMessageMoz(const nsAString & message, const nsAString & targetOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostMessageMoz(message, targetOrigin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindowInternal : public nsIDOMWindowInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOWINTERNAL

  nsDOMWindowInternal();

private:
  ~nsDOMWindowInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWindowInternal, nsIDOMWindowInternal)

nsDOMWindowInternal::nsDOMWindowInternal()
{
  /* member initializers and constructor code */
}

nsDOMWindowInternal::~nsDOMWindowInternal()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindowInternal window; */
NS_IMETHODIMP nsDOMWindowInternal::GetWindow(nsIDOMWindowInternal * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindowInternal self; */
NS_IMETHODIMP nsDOMWindowInternal::GetSelf(nsIDOMWindowInternal * *aSelf)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNavigator navigator; */
NS_IMETHODIMP nsDOMWindowInternal::GetNavigator(nsIDOMNavigator * *aNavigator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMScreen screen; */
NS_IMETHODIMP nsDOMWindowInternal::GetScreen(nsIDOMScreen * *aScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHistory history; */
NS_IMETHODIMP nsDOMWindowInternal::GetHistory(nsIDOMHistory * *aHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow content; */
NS_IMETHODIMP nsDOMWindowInternal::GetContent(nsIDOMWindow * *aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIPrompt prompter; */
NS_IMETHODIMP nsDOMWindowInternal::GetPrompter(nsIPrompt * *aPrompter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp menubar; */
NS_IMETHODIMP nsDOMWindowInternal::GetMenubar(nsIDOMBarProp * *aMenubar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp toolbar; */
NS_IMETHODIMP nsDOMWindowInternal::GetToolbar(nsIDOMBarProp * *aToolbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp locationbar; */
NS_IMETHODIMP nsDOMWindowInternal::GetLocationbar(nsIDOMBarProp * *aLocationbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp personalbar; */
NS_IMETHODIMP nsDOMWindowInternal::GetPersonalbar(nsIDOMBarProp * *aPersonalbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp statusbar; */
NS_IMETHODIMP nsDOMWindowInternal::GetStatusbar(nsIDOMBarProp * *aStatusbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp directories; */
NS_IMETHODIMP nsDOMWindowInternal::GetDirectories(nsIDOMBarProp * *aDirectories)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean closed; */
NS_IMETHODIMP nsDOMWindowInternal::GetClosed(PRBool *aClosed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCrypto crypto; */
NS_IMETHODIMP nsDOMWindowInternal::GetCrypto(nsIDOMCrypto * *aCrypto)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMPkcs11 pkcs11; */
NS_IMETHODIMP nsDOMWindowInternal::GetPkcs11(nsIDOMPkcs11 * *aPkcs11)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIControllers controllers; */
NS_IMETHODIMP nsDOMWindowInternal::GetControllers(nsIControllers * *aControllers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindowInternal opener; */
NS_IMETHODIMP nsDOMWindowInternal::GetOpener(nsIDOMWindowInternal * *aOpener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetOpener(nsIDOMWindowInternal * aOpener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString status; */
NS_IMETHODIMP nsDOMWindowInternal::GetStatus(nsAString & aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetStatus(const nsAString & aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString defaultStatus; */
NS_IMETHODIMP nsDOMWindowInternal::GetDefaultStatus(nsAString & aDefaultStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetDefaultStatus(const nsAString & aDefaultStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMLocation location; */
NS_IMETHODIMP nsDOMWindowInternal::GetLocation(nsIDOMLocation * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long innerWidth; */
NS_IMETHODIMP nsDOMWindowInternal::GetInnerWidth(PRInt32 *aInnerWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetInnerWidth(PRInt32 aInnerWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long innerHeight; */
NS_IMETHODIMP nsDOMWindowInternal::GetInnerHeight(PRInt32 *aInnerHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetInnerHeight(PRInt32 aInnerHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long outerWidth; */
NS_IMETHODIMP nsDOMWindowInternal::GetOuterWidth(PRInt32 *aOuterWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetOuterWidth(PRInt32 aOuterWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long outerHeight; */
NS_IMETHODIMP nsDOMWindowInternal::GetOuterHeight(PRInt32 *aOuterHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetOuterHeight(PRInt32 aOuterHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long screenX; */
NS_IMETHODIMP nsDOMWindowInternal::GetScreenX(PRInt32 *aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetScreenX(PRInt32 aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long screenY; */
NS_IMETHODIMP nsDOMWindowInternal::GetScreenY(PRInt32 *aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetScreenY(PRInt32 aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageXOffset; */
NS_IMETHODIMP nsDOMWindowInternal::GetPageXOffset(PRInt32 *aPageXOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageYOffset; */
NS_IMETHODIMP nsDOMWindowInternal::GetPageYOffset(PRInt32 *aPageYOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollMaxX; */
NS_IMETHODIMP nsDOMWindowInternal::GetScrollMaxX(PRInt32 *aScrollMaxX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollMaxY; */
NS_IMETHODIMP nsDOMWindowInternal::GetScrollMaxY(PRInt32 *aScrollMaxY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMWindowInternal::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean fullScreen; */
NS_IMETHODIMP nsDOMWindowInternal::GetFullScreen(PRBool *aFullScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowInternal::SetFullScreen(PRBool aFullScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void alert (in DOMString text); */
NS_IMETHODIMP nsDOMWindowInternal::Alert(const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean confirm (in DOMString text); */
NS_IMETHODIMP nsDOMWindowInternal::Confirm(const nsAString & text, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString prompt ([optional] in DOMString aMessage, [optional] in DOMString aInitial, [optional] in DOMString aTitle, [optional] in unsigned long aSavePassword); */
NS_IMETHODIMP nsDOMWindowInternal::Prompt(const nsAString & aMessage, const nsAString & aInitial, const nsAString & aTitle, PRUint32 aSavePassword, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMWindowInternal::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blur (); */
NS_IMETHODIMP nsDOMWindowInternal::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void back (); */
NS_IMETHODIMP nsDOMWindowInternal::Back()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forward (); */
NS_IMETHODIMP nsDOMWindowInternal::Forward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void home (); */
NS_IMETHODIMP nsDOMWindowInternal::Home()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsDOMWindowInternal::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void print (); */
NS_IMETHODIMP nsDOMWindowInternal::Print()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveTo (in long xPos, in long yPos); */
NS_IMETHODIMP nsDOMWindowInternal::MoveTo(PRInt32 xPos, PRInt32 yPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveBy (in long xDif, in long yDif); */
NS_IMETHODIMP nsDOMWindowInternal::MoveBy(PRInt32 xDif, PRInt32 yDif)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resizeTo (in long width, in long height); */
NS_IMETHODIMP nsDOMWindowInternal::ResizeTo(PRInt32 width, PRInt32 height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resizeBy (in long widthDif, in long heightDif); */
NS_IMETHODIMP nsDOMWindowInternal::ResizeBy(PRInt32 widthDif, PRInt32 heightDif)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scroll (in long xScroll, in long yScroll); */
NS_IMETHODIMP nsDOMWindowInternal::Scroll(PRInt32 xScroll, PRInt32 yScroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMWindow open (in DOMString url, in DOMString name, in DOMString options); */
NS_IMETHODIMP nsDOMWindowInternal::Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMWindow openDialog (in DOMString url, in DOMString name, in DOMString options, in nsISupports aExtraArgument); */
NS_IMETHODIMP nsDOMWindowInternal::OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDOMWindowInternal::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateCommands (in DOMString action); */
NS_IMETHODIMP nsDOMWindowInternal::UpdateCommands(const nsAString & action)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean find ([optional] in DOMString str, [optional] in boolean caseSensitive, [optional] in boolean backwards, [optional] in boolean wrapAround, [optional] in boolean wholeWord, [optional] in boolean searchInFrames, [optional] in boolean showDialog); */
NS_IMETHODIMP nsDOMWindowInternal::Find(const nsAString & str, PRBool caseSensitive, PRBool backwards, PRBool wrapAround, PRBool wholeWord, PRBool searchInFrames, PRBool showDialog, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString atob (in DOMString aAsciiString); */
NS_IMETHODIMP nsDOMWindowInternal::Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString btoa (in DOMString aBase64Data); */
NS_IMETHODIMP nsDOMWindowInternal::Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement frameElement; */
NS_IMETHODIMP nsDOMWindowInternal::GetFrameElement(nsIDOMElement * *aFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant showModalDialog (in DOMString aURI, [optional] in nsIVariant aArgs, [optional] in DOMString aOptions); */
NS_IMETHODIMP nsDOMWindowInternal::ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname (PostMessageMoz)] void postMessage (in DOMString message, in DOMString targetOrigin); */
NS_IMETHODIMP nsDOMWindowInternal::PostMessageMoz(const nsAString & message, const nsAString & targetOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWindowInternal_h__ */
