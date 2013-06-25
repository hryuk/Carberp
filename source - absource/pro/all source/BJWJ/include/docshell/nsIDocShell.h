/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIDocShell.idl
 */

#ifndef __gen_nsIDocShell_h__
#define __gen_nsIDocShell_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsPresContext;
class nsIPresShell;
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIContentViewer; /* forward declaration */

class nsIURIContentListener; /* forward declaration */

class nsIDOMEventTarget; /* forward declaration */

class nsIDocShellLoadInfo; /* forward declaration */

class nsIDocumentCharsetInfo; /* forward declaration */

class nsIWebNavigation; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsISHEntry; /* forward declaration */

class nsILayoutHistoryState; /* forward declaration */

class nsISecureBrowserUI; /* forward declaration */

class nsIDOMStorage; /* forward declaration */

class nsIDOMStorage2; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIDocShell */
#define NS_IDOCSHELL_IID_STR "dc4daea1-b43d-406f-bd62-c2ee879192ad"

#define NS_IDOCSHELL_IID \
  {0xdc4daea1, 0xb43d, 0x406f, \
    { 0xbd, 0x62, 0xc2, 0xee, 0x87, 0x91, 0x92, 0xad }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocShell : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELL_IID)

  /**
   * Loads a given URI.  This will give priority to loading the requested URI
   * in the object implementing	this interface.  If it can't be loaded here
   * however, the URL dispatcher will go through its normal process of content
   * loading.
   *
   * @param uri        - The URI to load.
   * @param loadInfo   - This is the extended load info for this load.  This
   *                     most often will be null, but if you need to do 
   *                     additional setup for this load you can get a loadInfo
   *                     object by calling createLoadInfo.  Once you have this
   *                     object you can set the needed properties on it and
   *                     then pass it to loadURI.
   * @param aLoadFlags - Flags to modify load behaviour. Flags are defined in
   *                     nsIWebNavigation.  Note that using flags outside
   *                     LOAD_FLAGS_MASK is only allowed if passing in a
   *                     non-null loadInfo.  And even some of those might not
   *                     be allowed.  Use at your own risk.
   */
  /* [noscript] void loadURI (in nsIURI uri, in nsIDocShellLoadInfo loadInfo, in unsigned long aLoadFlags, in boolean firstParty); */
  NS_IMETHOD LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, PRUint32 aLoadFlags, PRBool firstParty) = 0;

  /**
   * Loads a given stream. This will give priority to loading the requested
   * stream in the object implementing this interface. If it can't be loaded
   * here however, the URL dispatched will go through its normal process of
   * content loading.
   *
   * @param aStream         - The input stream that provides access to the data
   *                          to be loaded.  This must be a blocking, threadsafe
   *                          stream implementation.
   * @param aURI            - The URI representing the stream, or null.
   * @param aContentType    - The type (MIME) of data being loaded (empty if unknown).
   * @param aContentCharset - The charset of the data being loaded (empty if unknown).
   * @param aLoadInfo       - This is the extended load info for this load.  This
   *                          most often will be null, but if you need to do 
   *                          additional setup for this load you can get a
   *                          loadInfo object by calling createLoadInfo.  Once
   *                          you have this object you can set the needed 
   *                          properties on it and then pass it to loadStream.
   */
  /* [noscript] void loadStream (in nsIInputStream aStream, in nsIURI aURI, in ACString aContentType, in ACString aContentCharset, in nsIDocShellLoadInfo aLoadInfo); */
  NS_IMETHOD LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo) = 0;

  enum { INTERNAL_LOAD_FLAGS_NONE = 0 };

  enum { INTERNAL_LOAD_FLAGS_INHERIT_OWNER = 1 };

  enum { INTERNAL_LOAD_FLAGS_DONT_SEND_REFERRER = 2 };

  enum { INTERNAL_LOAD_FLAGS_ALLOW_THIRD_PARTY_FIXUP = 4 };

  enum { INTERNAL_LOAD_FLAGS_FIRST_LOAD = 8 };

  enum { INTERNAL_LOAD_FLAGS_BYPASS_CLASSIFIER = 16 };

  /**
   * Loads the given URI.  This method is identical to loadURI(...) except
   * that its parameter list is broken out instead of being packaged inside
   * of an nsIDocShellLoadInfo object...
   *
   * @param aURI            - The URI to load.
   * @param aReferrer       - Referring URI
   * @param aOwner          - Owner (security principal) 
   * @param aInheritOwner   - Flag indicating whether the owner of the current
   *                          document should be inherited if aOwner is null.
   * @param aStopActiveDoc  - Flag indicating whether loading the current
   *                          document should be stopped.
   * @param aWindowTarget   - Window target for the load.
   * @param aTypeHint       - A hint as to the content-type of the resulting
   *                          data.  May be null or empty if no hint.
   * @param aPostDataStream - Post data stream (if POSTing)
   * @param aHeadersStream  - Stream containing "extra" request headers...
   * @param aLoadFlags      - Flags to modify load behaviour. Flags are defined
   *                          in nsIWebNavigation.
   * @param aSHEntry        - Active Session History entry (if loading from SH)
   */
  /* [noscript] void internalLoad (in nsIURI aURI, in nsIURI aReferrer, in nsISupports aOwner, in PRUint32 aFlags, in wstring aWindowTarget, in string aTypeHint, in nsIInputStream aPostDataStream, in nsIInputStream aHeadersStream, in unsigned long aLoadFlags, in nsISHEntry aSHEntry, in boolean firstParty, out nsIDocShell aDocShell, out nsIRequest aRequest); */
  NS_IMETHOD InternalLoad(nsIURI *aURI, nsIURI *aReferrer, nsISupports *aOwner, PRUint32 aFlags, const PRUnichar *aWindowTarget, const char *aTypeHint, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, PRUint32 aLoadFlags, nsISHEntry *aSHEntry, PRBool firstParty, nsIDocShell **aDocShell NS_OUTPARAM, nsIRequest **aRequest NS_OUTPARAM) = 0;

  /**
   * Creates a DocShellLoadInfo object that you can manipulate and then pass
   * to loadURI.
   */
  /* void createLoadInfo (out nsIDocShellLoadInfo loadInfo); */
  NS_SCRIPTABLE NS_IMETHOD CreateLoadInfo(nsIDocShellLoadInfo **loadInfo NS_OUTPARAM) = 0;

  /**
   * Reset state to a new content model within the current document and the document
   * viewer.  Called by the document before initiating an out of band document.write().
   */
  /* void prepareForNewContentModel (); */
  NS_SCRIPTABLE NS_IMETHOD PrepareForNewContentModel(void) = 0;

  /**
   * For editors and suchlike who wish to change the URI associated with the
   * document. Note if you want to get the current URI, use the read-only
   * property on nsIWebNavigation.
   */
  /* void setCurrentURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD SetCurrentURI(nsIURI *aURI) = 0;

  /**
   * Notify the associated content viewer and all child docshells that they are
   * about to be hidden.  If |isUnload| is true, then the document is being
   * unloaded as well.
   *
   * @param isUnload if true, fire the unload event in addition to the pagehide
   *                 event.
   */
  /* [noscript] void firePageHideNotification (in boolean isUnload); */
  NS_IMETHOD FirePageHideNotification(PRBool isUnload) = 0;

  /**
   * Presentation context for the currently loaded document.  This may be null.
   */
  /* [noscript] readonly attribute nsPresContext presContext; */
  NS_IMETHOD GetPresContext(nsPresContext * *aPresContext) = 0;

  /**
   * Presentation shell for the currently loaded document.  This may be null.
   */
  /* [noscript] readonly attribute nsIPresShell presShell; */
  NS_IMETHOD GetPresShell(nsIPresShell * *aPresShell) = 0;

  /**
   * Presentation shell for the oldest document, if this docshell is
   * currently transitioning between documents.
   */
  /* [noscript] readonly attribute nsIPresShell eldestPresShell; */
  NS_IMETHOD GetEldestPresShell(nsIPresShell * *aEldestPresShell) = 0;

  /**
   * Content Viewer that is currently loaded for this DocShell.  This may
   * change as the underlying content changes.
   */
  /* readonly attribute nsIContentViewer contentViewer; */
  NS_SCRIPTABLE NS_IMETHOD GetContentViewer(nsIContentViewer * *aContentViewer) = 0;

  /**
   * This attribute allows chrome to tie in to handle DOM events that may
   * be of interest to chrome.
   */
  /* attribute nsIDOMEventTarget chromeEventHandler; */
  NS_SCRIPTABLE NS_IMETHOD GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetChromeEventHandler(nsIDOMEventTarget * aChromeEventHandler) = 0;

  /**
   * The document charset info.  This is used by a load to determine priorities
   * for charset detection etc.
   */
  /* attribute nsIDocumentCharsetInfo documentCharsetInfo; */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentCharsetInfo(nsIDocumentCharsetInfo * *aDocumentCharsetInfo) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocumentCharsetInfo(nsIDocumentCharsetInfo * aDocumentCharsetInfo) = 0;

  /**
   * Whether to allow plugin execution
   */
  /* attribute boolean allowPlugins; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowPlugins(PRBool *aAllowPlugins) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAllowPlugins(PRBool aAllowPlugins) = 0;

  /**
   * Whether to allow Javascript execution
   */
  /* attribute boolean allowJavascript; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowJavascript(PRBool *aAllowJavascript) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAllowJavascript(PRBool aAllowJavascript) = 0;

  /**
   * Attribute stating if refresh based redirects can be allowed
   */
  /* attribute boolean allowMetaRedirects; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowMetaRedirects(PRBool *aAllowMetaRedirects) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAllowMetaRedirects(PRBool aAllowMetaRedirects) = 0;

  /**
   * Attribute stating if it should allow subframes (framesets/iframes) or not
   */
  /* attribute boolean allowSubframes; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowSubframes(PRBool *aAllowSubframes) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAllowSubframes(PRBool aAllowSubframes) = 0;

  /**
   * Attribute stating whether or not images should be loaded.
   */
  /* attribute boolean allowImages; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowImages(PRBool *aAllowImages) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAllowImages(PRBool aAllowImages) = 0;

  /**
   * Get an enumerator over this docShell and its children.
   *
   * @param aItemType  - Only include docShells of this type, or if typeAll,
   *                     include all child shells.
   *                     Uses types from nsIDocShellTreeItem.
   * @param aDirection - Whether to enumerate forwards or backwards.
   */
  enum { ENUMERATE_FORWARDS = 0 };

  enum { ENUMERATE_BACKWARDS = 1 };

  /* nsISimpleEnumerator getDocShellEnumerator (in long aItemType, in long aDirection); */
  NS_SCRIPTABLE NS_IMETHOD GetDocShellEnumerator(PRInt32 aItemType, PRInt32 aDirection, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
   * The type of application that created this window
   */
  enum { APP_TYPE_UNKNOWN = 0U };

  enum { APP_TYPE_MAIL = 1U };

  enum { APP_TYPE_EDITOR = 2U };

  /* attribute unsigned long appType; */
  NS_SCRIPTABLE NS_IMETHOD GetAppType(PRUint32 *aAppType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAppType(PRUint32 aAppType) = 0;

  /**
   * certain dochshells (like the message pane)
   * should not throw up auth dialogs
   * because it can act as a password trojan
   */
  /* attribute boolean allowAuth; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowAuth(PRBool *aAllowAuth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAllowAuth(PRBool aAllowAuth) = 0;

  /**
   * Set/Get the document scale factor.  When setting this attribute, a
   * NS_ERROR_NOT_IMPLEMENTED error may be returned by implementations
   * not supporting zoom.  Implementations not supporting zoom should return
   * 1.0 all the time for the Get operation.  1.0 by the way is the default
   * of zoom.  This means 100% of normal scaling or in other words normal size
   * no zoom. 
   */
  /* attribute float zoom; */
  NS_SCRIPTABLE NS_IMETHOD GetZoom(float *aZoom) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetZoom(float aZoom) = 0;

  /* attribute long marginWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetMarginWidth(PRInt32 *aMarginWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMarginWidth(PRInt32 aMarginWidth) = 0;

  /* attribute long marginHeight; */
  NS_SCRIPTABLE NS_IMETHOD GetMarginHeight(PRInt32 *aMarginHeight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMarginHeight(PRInt32 aMarginHeight) = 0;

  /* attribute boolean hasFocus; */
  NS_SCRIPTABLE NS_IMETHOD GetHasFocus(PRBool *aHasFocus) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHasFocus(PRBool aHasFocus) = 0;

  /* attribute boolean canvasHasFocus; */
  NS_SCRIPTABLE NS_IMETHOD GetCanvasHasFocus(PRBool *aCanvasHasFocus) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCanvasHasFocus(PRBool aCanvasHasFocus) = 0;

  /* void tabToTreeOwner (in boolean forward, out boolean tookFocus); */
  NS_SCRIPTABLE NS_IMETHOD TabToTreeOwner(PRBool forward, PRBool *tookFocus NS_OUTPARAM) = 0;

  /**
   * Current busy state for DocShell
   */
  enum { BUSY_FLAGS_NONE = 0U };

  enum { BUSY_FLAGS_BUSY = 1U };

  enum { BUSY_FLAGS_BEFORE_PAGE_LOAD = 2U };

  enum { BUSY_FLAGS_PAGE_LOADING = 4U };

  /**
   * Load commands for the document 
   */
  enum { LOAD_CMD_NORMAL = 1U };

  enum { LOAD_CMD_RELOAD = 2U };

  enum { LOAD_CMD_HISTORY = 4U };

  /* readonly attribute unsigned long busyFlags; */
  NS_SCRIPTABLE NS_IMETHOD GetBusyFlags(PRUint32 *aBusyFlags) = 0;

  /* attribute unsigned long loadType; */
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(PRUint32 *aLoadType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(PRUint32 aLoadType) = 0;

  /* boolean isBeingDestroyed (); */
  NS_SCRIPTABLE NS_IMETHOD IsBeingDestroyed(PRBool *_retval NS_OUTPARAM) = 0;

  /* readonly attribute boolean isExecutingOnLoadHandler; */
  NS_SCRIPTABLE NS_IMETHOD GetIsExecutingOnLoadHandler(PRBool *aIsExecutingOnLoadHandler) = 0;

  /* attribute nsILayoutHistoryState layoutHistoryState; */
  NS_SCRIPTABLE NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState * aLayoutHistoryState) = 0;

  /* readonly attribute boolean shouldSaveLayoutState; */
  NS_SCRIPTABLE NS_IMETHOD GetShouldSaveLayoutState(PRBool *aShouldSaveLayoutState) = 0;

  /**
   * The SecureBrowserUI object for this docshell.  This is set by XUL
   * <browser> or nsWebBrowser for their root docshell.
   */
  /* attribute nsISecureBrowserUI securityUI; */
  NS_SCRIPTABLE NS_IMETHOD GetSecurityUI(nsISecureBrowserUI * *aSecurityUI) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSecurityUI(nsISecureBrowserUI * aSecurityUI) = 0;

  /**
   * Cancel the XPCOM timers for each meta-refresh URI in this docshell,
   * and this docshell's children, recursively. The meta-refresh timers can be
   * restarted using resumeRefreshURIs().  If the timers are already suspended,
   * this has no effect.
   */
  /* void suspendRefreshURIs (); */
  NS_SCRIPTABLE NS_IMETHOD SuspendRefreshURIs(void) = 0;

  /**
   * Restart the XPCOM timers for each meta-refresh URI in this docshell,
   * and this docshell's children, recursively.  If the timers are already
   * running, this has no effect.
   */
  /* void resumeRefreshURIs (); */
  NS_SCRIPTABLE NS_IMETHOD ResumeRefreshURIs(void) = 0;

  /**
   * Begin firing WebProgressListener notifications for restoring a page
   * presentation. |viewer| is the content viewer whose document we are
   * starting to load.  If null, it defaults to the docshell's current content
   * viewer, creating one if necessary.  |top| should be true for the toplevel
   * docshell that is being restored; it will be set to false when this method
   * is called for child docshells.  This method will post an event to
   * complete the simulated load after returning to the event loop.
   */
  /* void beginRestore (in nsIContentViewer viewer, in boolean top); */
  NS_SCRIPTABLE NS_IMETHOD BeginRestore(nsIContentViewer *viewer, PRBool top) = 0;

  /**
   * Finish firing WebProgressListener notifications and DOM events for
   * restoring a page presentation.  This should only be called via
   * beginRestore().
   */
  /* void finishRestore (); */
  NS_SCRIPTABLE NS_IMETHOD FinishRestore(void) = 0;

  /* readonly attribute boolean restoringDocument; */
  NS_SCRIPTABLE NS_IMETHOD GetRestoringDocument(PRBool *aRestoringDocument) = 0;

  /* attribute boolean useErrorPages; */
  NS_SCRIPTABLE NS_IMETHOD GetUseErrorPages(PRBool *aUseErrorPages) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUseErrorPages(PRBool aUseErrorPages) = 0;

  /**
   * Keeps track of the previous SHTransaction index and the current
   * SHTransaction index at the time that the doc shell begins to load.
   * Used for ContentViewer eviction.
   */
  /* readonly attribute long previousTransIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetPreviousTransIndex(PRInt32 *aPreviousTransIndex) = 0;

  /* readonly attribute long loadedTransIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetLoadedTransIndex(PRInt32 *aLoadedTransIndex) = 0;

  /**
   * Notification that entries have been removed from the beginning of a
   * nsSHistory which has this as its rootDocShell.
   *
   * @param numEntries - The number of entries removed
   */
  /* void historyPurged (in long numEntries); */
  NS_SCRIPTABLE NS_IMETHOD HistoryPurged(PRInt32 numEntries) = 0;

  /* [noscript] nsIDOMStorage getSessionStorageForURI (in nsIURI uri); */
  NS_IMETHOD GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage **_retval NS_OUTPARAM) = 0;

  /* [noscript] void addSessionStorage (in ACString aDomain, in nsIDOMStorage storage); */
  NS_IMETHOD AddSessionStorage(const nsACString & aDomain, nsIDOMStorage *storage) = 0;

  /**
   * Gets the channel for the currently loaded document, if any. 
   * For a new document load, this will be the channel of the previous document
   * until after OnLocationChange fires.
   */
  /* readonly attribute nsIChannel currentDocumentChannel; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel) = 0;

  /**
   * Set the offset of this child in its container.
   */
  /* [noscript] void setChildOffset (in unsigned long offset); */
  NS_IMETHOD SetChildOffset(PRUint32 offset) = 0;

  /**
   * Find out whether the docshell is currently in the middle of a page
   * transition (after the onunload event has fired, but before the new
   * document has been set up)
   */
  /* readonly attribute boolean isInUnload; */
  NS_SCRIPTABLE NS_IMETHOD GetIsInUnload(PRBool *aIsInUnload) = 0;

  /**
   * Find out if the currently loaded document came from a suspicious channel
   * (such as a JAR channel where the server-returned content type isn't a
   * known JAR type).
   */
  /* readonly attribute boolean channelIsUnsafe; */
  NS_SCRIPTABLE NS_IMETHOD GetChannelIsUnsafe(PRBool *aChannelIsUnsafe) = 0;

  /**
   * Disconnects this docshell's editor from its window, and stores the
   * editor data in the open document's session history entry.  This
   * should be called only during page transitions.
   */
  /* [noscript, notxpcom] void DetachEditorFromWindow (); */
  NS_IMETHOD_(void) DetachEditorFromWindow(void) = 0;

  /**
   * If true, this browser is not visible in the traditional sense, but
   * is actively being rendered to the screen (ex. painted on a canvas)
   * and should be treated accordingly.
   **/
  /* attribute boolean isOffScreenBrowser; */
  NS_SCRIPTABLE NS_IMETHOD GetIsOffScreenBrowser(PRBool *aIsOffScreenBrowser) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIsOffScreenBrowser(PRBool aIsOffScreenBrowser) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShell, NS_IDOCSHELL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELL \
  NS_IMETHOD LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, PRUint32 aLoadFlags, PRBool firstParty); \
  NS_IMETHOD LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo); \
  NS_IMETHOD InternalLoad(nsIURI *aURI, nsIURI *aReferrer, nsISupports *aOwner, PRUint32 aFlags, const PRUnichar *aWindowTarget, const char *aTypeHint, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, PRUint32 aLoadFlags, nsISHEntry *aSHEntry, PRBool firstParty, nsIDocShell **aDocShell NS_OUTPARAM, nsIRequest **aRequest NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateLoadInfo(nsIDocShellLoadInfo **loadInfo NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PrepareForNewContentModel(void); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentURI(nsIURI *aURI); \
  NS_IMETHOD FirePageHideNotification(PRBool isUnload); \
  NS_IMETHOD GetPresContext(nsPresContext * *aPresContext); \
  NS_IMETHOD GetPresShell(nsIPresShell * *aPresShell); \
  NS_IMETHOD GetEldestPresShell(nsIPresShell * *aEldestPresShell); \
  NS_SCRIPTABLE NS_IMETHOD GetContentViewer(nsIContentViewer * *aContentViewer); \
  NS_SCRIPTABLE NS_IMETHOD GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler); \
  NS_SCRIPTABLE NS_IMETHOD SetChromeEventHandler(nsIDOMEventTarget * aChromeEventHandler); \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentCharsetInfo(nsIDocumentCharsetInfo * *aDocumentCharsetInfo); \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentCharsetInfo(nsIDocumentCharsetInfo * aDocumentCharsetInfo); \
  NS_SCRIPTABLE NS_IMETHOD GetAllowPlugins(PRBool *aAllowPlugins); \
  NS_SCRIPTABLE NS_IMETHOD SetAllowPlugins(PRBool aAllowPlugins); \
  NS_SCRIPTABLE NS_IMETHOD GetAllowJavascript(PRBool *aAllowJavascript); \
  NS_SCRIPTABLE NS_IMETHOD SetAllowJavascript(PRBool aAllowJavascript); \
  NS_SCRIPTABLE NS_IMETHOD GetAllowMetaRedirects(PRBool *aAllowMetaRedirects); \
  NS_SCRIPTABLE NS_IMETHOD SetAllowMetaRedirects(PRBool aAllowMetaRedirects); \
  NS_SCRIPTABLE NS_IMETHOD GetAllowSubframes(PRBool *aAllowSubframes); \
  NS_SCRIPTABLE NS_IMETHOD SetAllowSubframes(PRBool aAllowSubframes); \
  NS_SCRIPTABLE NS_IMETHOD GetAllowImages(PRBool *aAllowImages); \
  NS_SCRIPTABLE NS_IMETHOD SetAllowImages(PRBool aAllowImages); \
  NS_SCRIPTABLE NS_IMETHOD GetDocShellEnumerator(PRInt32 aItemType, PRInt32 aDirection, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAppType(PRUint32 *aAppType); \
  NS_SCRIPTABLE NS_IMETHOD SetAppType(PRUint32 aAppType); \
  NS_SCRIPTABLE NS_IMETHOD GetAllowAuth(PRBool *aAllowAuth); \
  NS_SCRIPTABLE NS_IMETHOD SetAllowAuth(PRBool aAllowAuth); \
  NS_SCRIPTABLE NS_IMETHOD GetZoom(float *aZoom); \
  NS_SCRIPTABLE NS_IMETHOD SetZoom(float aZoom); \
  NS_SCRIPTABLE NS_IMETHOD GetMarginWidth(PRInt32 *aMarginWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetMarginWidth(PRInt32 aMarginWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetMarginHeight(PRInt32 *aMarginHeight); \
  NS_SCRIPTABLE NS_IMETHOD SetMarginHeight(PRInt32 aMarginHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetHasFocus(PRBool *aHasFocus); \
  NS_SCRIPTABLE NS_IMETHOD SetHasFocus(PRBool aHasFocus); \
  NS_SCRIPTABLE NS_IMETHOD GetCanvasHasFocus(PRBool *aCanvasHasFocus); \
  NS_SCRIPTABLE NS_IMETHOD SetCanvasHasFocus(PRBool aCanvasHasFocus); \
  NS_SCRIPTABLE NS_IMETHOD TabToTreeOwner(PRBool forward, PRBool *tookFocus NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBusyFlags(PRUint32 *aBusyFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(PRUint32 *aLoadType); \
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(PRUint32 aLoadType); \
  NS_SCRIPTABLE NS_IMETHOD IsBeingDestroyed(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIsExecutingOnLoadHandler(PRBool *aIsExecutingOnLoadHandler); \
  NS_SCRIPTABLE NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState); \
  NS_SCRIPTABLE NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState * aLayoutHistoryState); \
  NS_SCRIPTABLE NS_IMETHOD GetShouldSaveLayoutState(PRBool *aShouldSaveLayoutState); \
  NS_SCRIPTABLE NS_IMETHOD GetSecurityUI(nsISecureBrowserUI * *aSecurityUI); \
  NS_SCRIPTABLE NS_IMETHOD SetSecurityUI(nsISecureBrowserUI * aSecurityUI); \
  NS_SCRIPTABLE NS_IMETHOD SuspendRefreshURIs(void); \
  NS_SCRIPTABLE NS_IMETHOD ResumeRefreshURIs(void); \
  NS_SCRIPTABLE NS_IMETHOD BeginRestore(nsIContentViewer *viewer, PRBool top); \
  NS_SCRIPTABLE NS_IMETHOD FinishRestore(void); \
  NS_SCRIPTABLE NS_IMETHOD GetRestoringDocument(PRBool *aRestoringDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetUseErrorPages(PRBool *aUseErrorPages); \
  NS_SCRIPTABLE NS_IMETHOD SetUseErrorPages(PRBool aUseErrorPages); \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousTransIndex(PRInt32 *aPreviousTransIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetLoadedTransIndex(PRInt32 *aLoadedTransIndex); \
  NS_SCRIPTABLE NS_IMETHOD HistoryPurged(PRInt32 numEntries); \
  NS_IMETHOD GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage **_retval NS_OUTPARAM); \
  NS_IMETHOD AddSessionStorage(const nsACString & aDomain, nsIDOMStorage *storage); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel); \
  NS_IMETHOD SetChildOffset(PRUint32 offset); \
  NS_SCRIPTABLE NS_IMETHOD GetIsInUnload(PRBool *aIsInUnload); \
  NS_SCRIPTABLE NS_IMETHOD GetChannelIsUnsafe(PRBool *aChannelIsUnsafe); \
  NS_IMETHOD_(void) DetachEditorFromWindow(void); \
  NS_SCRIPTABLE NS_IMETHOD GetIsOffScreenBrowser(PRBool *aIsOffScreenBrowser); \
  NS_SCRIPTABLE NS_IMETHOD SetIsOffScreenBrowser(PRBool aIsOffScreenBrowser); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELL(_to) \
  NS_IMETHOD LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, PRUint32 aLoadFlags, PRBool firstParty) { return _to LoadURI(uri, loadInfo, aLoadFlags, firstParty); } \
  NS_IMETHOD LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo) { return _to LoadStream(aStream, aURI, aContentType, aContentCharset, aLoadInfo); } \
  NS_IMETHOD InternalLoad(nsIURI *aURI, nsIURI *aReferrer, nsISupports *aOwner, PRUint32 aFlags, const PRUnichar *aWindowTarget, const char *aTypeHint, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, PRUint32 aLoadFlags, nsISHEntry *aSHEntry, PRBool firstParty, nsIDocShell **aDocShell NS_OUTPARAM, nsIRequest **aRequest NS_OUTPARAM) { return _to InternalLoad(aURI, aReferrer, aOwner, aFlags, aWindowTarget, aTypeHint, aPostDataStream, aHeadersStream, aLoadFlags, aSHEntry, firstParty, aDocShell, aRequest); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLoadInfo(nsIDocShellLoadInfo **loadInfo NS_OUTPARAM) { return _to CreateLoadInfo(loadInfo); } \
  NS_SCRIPTABLE NS_IMETHOD PrepareForNewContentModel(void) { return _to PrepareForNewContentModel(); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentURI(nsIURI *aURI) { return _to SetCurrentURI(aURI); } \
  NS_IMETHOD FirePageHideNotification(PRBool isUnload) { return _to FirePageHideNotification(isUnload); } \
  NS_IMETHOD GetPresContext(nsPresContext * *aPresContext) { return _to GetPresContext(aPresContext); } \
  NS_IMETHOD GetPresShell(nsIPresShell * *aPresShell) { return _to GetPresShell(aPresShell); } \
  NS_IMETHOD GetEldestPresShell(nsIPresShell * *aEldestPresShell) { return _to GetEldestPresShell(aEldestPresShell); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentViewer(nsIContentViewer * *aContentViewer) { return _to GetContentViewer(aContentViewer); } \
  NS_SCRIPTABLE NS_IMETHOD GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler) { return _to GetChromeEventHandler(aChromeEventHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetChromeEventHandler(nsIDOMEventTarget * aChromeEventHandler) { return _to SetChromeEventHandler(aChromeEventHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentCharsetInfo(nsIDocumentCharsetInfo * *aDocumentCharsetInfo) { return _to GetDocumentCharsetInfo(aDocumentCharsetInfo); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentCharsetInfo(nsIDocumentCharsetInfo * aDocumentCharsetInfo) { return _to SetDocumentCharsetInfo(aDocumentCharsetInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowPlugins(PRBool *aAllowPlugins) { return _to GetAllowPlugins(aAllowPlugins); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowPlugins(PRBool aAllowPlugins) { return _to SetAllowPlugins(aAllowPlugins); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowJavascript(PRBool *aAllowJavascript) { return _to GetAllowJavascript(aAllowJavascript); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowJavascript(PRBool aAllowJavascript) { return _to SetAllowJavascript(aAllowJavascript); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowMetaRedirects(PRBool *aAllowMetaRedirects) { return _to GetAllowMetaRedirects(aAllowMetaRedirects); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowMetaRedirects(PRBool aAllowMetaRedirects) { return _to SetAllowMetaRedirects(aAllowMetaRedirects); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowSubframes(PRBool *aAllowSubframes) { return _to GetAllowSubframes(aAllowSubframes); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowSubframes(PRBool aAllowSubframes) { return _to SetAllowSubframes(aAllowSubframes); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowImages(PRBool *aAllowImages) { return _to GetAllowImages(aAllowImages); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowImages(PRBool aAllowImages) { return _to SetAllowImages(aAllowImages); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocShellEnumerator(PRInt32 aItemType, PRInt32 aDirection, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetDocShellEnumerator(aItemType, aDirection, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAppType(PRUint32 *aAppType) { return _to GetAppType(aAppType); } \
  NS_SCRIPTABLE NS_IMETHOD SetAppType(PRUint32 aAppType) { return _to SetAppType(aAppType); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowAuth(PRBool *aAllowAuth) { return _to GetAllowAuth(aAllowAuth); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowAuth(PRBool aAllowAuth) { return _to SetAllowAuth(aAllowAuth); } \
  NS_SCRIPTABLE NS_IMETHOD GetZoom(float *aZoom) { return _to GetZoom(aZoom); } \
  NS_SCRIPTABLE NS_IMETHOD SetZoom(float aZoom) { return _to SetZoom(aZoom); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginWidth(PRInt32 *aMarginWidth) { return _to GetMarginWidth(aMarginWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginWidth(PRInt32 aMarginWidth) { return _to SetMarginWidth(aMarginWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginHeight(PRInt32 *aMarginHeight) { return _to GetMarginHeight(aMarginHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginHeight(PRInt32 aMarginHeight) { return _to SetMarginHeight(aMarginHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasFocus(PRBool *aHasFocus) { return _to GetHasFocus(aHasFocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetHasFocus(PRBool aHasFocus) { return _to SetHasFocus(aHasFocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanvasHasFocus(PRBool *aCanvasHasFocus) { return _to GetCanvasHasFocus(aCanvasHasFocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetCanvasHasFocus(PRBool aCanvasHasFocus) { return _to SetCanvasHasFocus(aCanvasHasFocus); } \
  NS_SCRIPTABLE NS_IMETHOD TabToTreeOwner(PRBool forward, PRBool *tookFocus NS_OUTPARAM) { return _to TabToTreeOwner(forward, tookFocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetBusyFlags(PRUint32 *aBusyFlags) { return _to GetBusyFlags(aBusyFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(PRUint32 *aLoadType) { return _to GetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(PRUint32 aLoadType) { return _to SetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD IsBeingDestroyed(PRBool *_retval NS_OUTPARAM) { return _to IsBeingDestroyed(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsExecutingOnLoadHandler(PRBool *aIsExecutingOnLoadHandler) { return _to GetIsExecutingOnLoadHandler(aIsExecutingOnLoadHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState) { return _to GetLayoutHistoryState(aLayoutHistoryState); } \
  NS_SCRIPTABLE NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState * aLayoutHistoryState) { return _to SetLayoutHistoryState(aLayoutHistoryState); } \
  NS_SCRIPTABLE NS_IMETHOD GetShouldSaveLayoutState(PRBool *aShouldSaveLayoutState) { return _to GetShouldSaveLayoutState(aShouldSaveLayoutState); } \
  NS_SCRIPTABLE NS_IMETHOD GetSecurityUI(nsISecureBrowserUI * *aSecurityUI) { return _to GetSecurityUI(aSecurityUI); } \
  NS_SCRIPTABLE NS_IMETHOD SetSecurityUI(nsISecureBrowserUI * aSecurityUI) { return _to SetSecurityUI(aSecurityUI); } \
  NS_SCRIPTABLE NS_IMETHOD SuspendRefreshURIs(void) { return _to SuspendRefreshURIs(); } \
  NS_SCRIPTABLE NS_IMETHOD ResumeRefreshURIs(void) { return _to ResumeRefreshURIs(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginRestore(nsIContentViewer *viewer, PRBool top) { return _to BeginRestore(viewer, top); } \
  NS_SCRIPTABLE NS_IMETHOD FinishRestore(void) { return _to FinishRestore(); } \
  NS_SCRIPTABLE NS_IMETHOD GetRestoringDocument(PRBool *aRestoringDocument) { return _to GetRestoringDocument(aRestoringDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetUseErrorPages(PRBool *aUseErrorPages) { return _to GetUseErrorPages(aUseErrorPages); } \
  NS_SCRIPTABLE NS_IMETHOD SetUseErrorPages(PRBool aUseErrorPages) { return _to SetUseErrorPages(aUseErrorPages); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousTransIndex(PRInt32 *aPreviousTransIndex) { return _to GetPreviousTransIndex(aPreviousTransIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadedTransIndex(PRInt32 *aLoadedTransIndex) { return _to GetLoadedTransIndex(aLoadedTransIndex); } \
  NS_SCRIPTABLE NS_IMETHOD HistoryPurged(PRInt32 numEntries) { return _to HistoryPurged(numEntries); } \
  NS_IMETHOD GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage **_retval NS_OUTPARAM) { return _to GetSessionStorageForURI(uri, _retval); } \
  NS_IMETHOD AddSessionStorage(const nsACString & aDomain, nsIDOMStorage *storage) { return _to AddSessionStorage(aDomain, storage); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel) { return _to GetCurrentDocumentChannel(aCurrentDocumentChannel); } \
  NS_IMETHOD SetChildOffset(PRUint32 offset) { return _to SetChildOffset(offset); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsInUnload(PRBool *aIsInUnload) { return _to GetIsInUnload(aIsInUnload); } \
  NS_SCRIPTABLE NS_IMETHOD GetChannelIsUnsafe(PRBool *aChannelIsUnsafe) { return _to GetChannelIsUnsafe(aChannelIsUnsafe); } \
  NS_IMETHOD_(void) DetachEditorFromWindow(void) { return _to DetachEditorFromWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsOffScreenBrowser(PRBool *aIsOffScreenBrowser) { return _to GetIsOffScreenBrowser(aIsOffScreenBrowser); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsOffScreenBrowser(PRBool aIsOffScreenBrowser) { return _to SetIsOffScreenBrowser(aIsOffScreenBrowser); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELL(_to) \
  NS_IMETHOD LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, PRUint32 aLoadFlags, PRBool firstParty) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURI(uri, loadInfo, aLoadFlags, firstParty); } \
  NS_IMETHOD LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadStream(aStream, aURI, aContentType, aContentCharset, aLoadInfo); } \
  NS_IMETHOD InternalLoad(nsIURI *aURI, nsIURI *aReferrer, nsISupports *aOwner, PRUint32 aFlags, const PRUnichar *aWindowTarget, const char *aTypeHint, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, PRUint32 aLoadFlags, nsISHEntry *aSHEntry, PRBool firstParty, nsIDocShell **aDocShell NS_OUTPARAM, nsIRequest **aRequest NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InternalLoad(aURI, aReferrer, aOwner, aFlags, aWindowTarget, aTypeHint, aPostDataStream, aHeadersStream, aLoadFlags, aSHEntry, firstParty, aDocShell, aRequest); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLoadInfo(nsIDocShellLoadInfo **loadInfo NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLoadInfo(loadInfo); } \
  NS_SCRIPTABLE NS_IMETHOD PrepareForNewContentModel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrepareForNewContentModel(); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentURI(aURI); } \
  NS_IMETHOD FirePageHideNotification(PRBool isUnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->FirePageHideNotification(isUnload); } \
  NS_IMETHOD GetPresContext(nsPresContext * *aPresContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresContext(aPresContext); } \
  NS_IMETHOD GetPresShell(nsIPresShell * *aPresShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresShell(aPresShell); } \
  NS_IMETHOD GetEldestPresShell(nsIPresShell * *aEldestPresShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEldestPresShell(aEldestPresShell); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentViewer(nsIContentViewer * *aContentViewer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentViewer(aContentViewer); } \
  NS_SCRIPTABLE NS_IMETHOD GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeEventHandler(aChromeEventHandler); } \
  NS_SCRIPTABLE NS_IMETHOD SetChromeEventHandler(nsIDOMEventTarget * aChromeEventHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChromeEventHandler(aChromeEventHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentCharsetInfo(nsIDocumentCharsetInfo * *aDocumentCharsetInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentCharsetInfo(aDocumentCharsetInfo); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentCharsetInfo(nsIDocumentCharsetInfo * aDocumentCharsetInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentCharsetInfo(aDocumentCharsetInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowPlugins(PRBool *aAllowPlugins) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowPlugins(aAllowPlugins); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowPlugins(PRBool aAllowPlugins) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowPlugins(aAllowPlugins); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowJavascript(PRBool *aAllowJavascript) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowJavascript(aAllowJavascript); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowJavascript(PRBool aAllowJavascript) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowJavascript(aAllowJavascript); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowMetaRedirects(PRBool *aAllowMetaRedirects) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowMetaRedirects(aAllowMetaRedirects); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowMetaRedirects(PRBool aAllowMetaRedirects) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowMetaRedirects(aAllowMetaRedirects); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowSubframes(PRBool *aAllowSubframes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowSubframes(aAllowSubframes); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowSubframes(PRBool aAllowSubframes) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowSubframes(aAllowSubframes); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowImages(PRBool *aAllowImages) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowImages(aAllowImages); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowImages(PRBool aAllowImages) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowImages(aAllowImages); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocShellEnumerator(PRInt32 aItemType, PRInt32 aDirection, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShellEnumerator(aItemType, aDirection, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAppType(PRUint32 *aAppType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppType(aAppType); } \
  NS_SCRIPTABLE NS_IMETHOD SetAppType(PRUint32 aAppType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAppType(aAppType); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowAuth(PRBool *aAllowAuth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowAuth(aAllowAuth); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowAuth(PRBool aAllowAuth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowAuth(aAllowAuth); } \
  NS_SCRIPTABLE NS_IMETHOD GetZoom(float *aZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZoom(aZoom); } \
  NS_SCRIPTABLE NS_IMETHOD SetZoom(float aZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZoom(aZoom); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginWidth(PRInt32 *aMarginWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginWidth(aMarginWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginWidth(PRInt32 aMarginWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginWidth(aMarginWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetMarginHeight(PRInt32 *aMarginHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginHeight(aMarginHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetMarginHeight(PRInt32 aMarginHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginHeight(aMarginHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasFocus(PRBool *aHasFocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasFocus(aHasFocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetHasFocus(PRBool aHasFocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHasFocus(aHasFocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanvasHasFocus(PRBool *aCanvasHasFocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanvasHasFocus(aCanvasHasFocus); } \
  NS_SCRIPTABLE NS_IMETHOD SetCanvasHasFocus(PRBool aCanvasHasFocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCanvasHasFocus(aCanvasHasFocus); } \
  NS_SCRIPTABLE NS_IMETHOD TabToTreeOwner(PRBool forward, PRBool *tookFocus NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TabToTreeOwner(forward, tookFocus); } \
  NS_SCRIPTABLE NS_IMETHOD GetBusyFlags(PRUint32 *aBusyFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBusyFlags(aBusyFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(PRUint32 *aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(PRUint32 aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD IsBeingDestroyed(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsBeingDestroyed(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsExecutingOnLoadHandler(PRBool *aIsExecutingOnLoadHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExecutingOnLoadHandler(aIsExecutingOnLoadHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayoutHistoryState(aLayoutHistoryState); } \
  NS_SCRIPTABLE NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState * aLayoutHistoryState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLayoutHistoryState(aLayoutHistoryState); } \
  NS_SCRIPTABLE NS_IMETHOD GetShouldSaveLayoutState(PRBool *aShouldSaveLayoutState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShouldSaveLayoutState(aShouldSaveLayoutState); } \
  NS_SCRIPTABLE NS_IMETHOD GetSecurityUI(nsISecureBrowserUI * *aSecurityUI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityUI(aSecurityUI); } \
  NS_SCRIPTABLE NS_IMETHOD SetSecurityUI(nsISecureBrowserUI * aSecurityUI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityUI(aSecurityUI); } \
  NS_SCRIPTABLE NS_IMETHOD SuspendRefreshURIs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SuspendRefreshURIs(); } \
  NS_SCRIPTABLE NS_IMETHOD ResumeRefreshURIs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeRefreshURIs(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginRestore(nsIContentViewer *viewer, PRBool top) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginRestore(viewer, top); } \
  NS_SCRIPTABLE NS_IMETHOD FinishRestore(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FinishRestore(); } \
  NS_SCRIPTABLE NS_IMETHOD GetRestoringDocument(PRBool *aRestoringDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRestoringDocument(aRestoringDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetUseErrorPages(PRBool *aUseErrorPages) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseErrorPages(aUseErrorPages); } \
  NS_SCRIPTABLE NS_IMETHOD SetUseErrorPages(PRBool aUseErrorPages) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUseErrorPages(aUseErrorPages); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousTransIndex(PRInt32 *aPreviousTransIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousTransIndex(aPreviousTransIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadedTransIndex(PRInt32 *aLoadedTransIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadedTransIndex(aLoadedTransIndex); } \
  NS_SCRIPTABLE NS_IMETHOD HistoryPurged(PRInt32 numEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->HistoryPurged(numEntries); } \
  NS_IMETHOD GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorageForURI(uri, _retval); } \
  NS_IMETHOD AddSessionStorage(const nsACString & aDomain, nsIDOMStorage *storage) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSessionStorage(aDomain, storage); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentDocumentChannel(aCurrentDocumentChannel); } \
  NS_IMETHOD SetChildOffset(PRUint32 offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChildOffset(offset); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsInUnload(PRBool *aIsInUnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInUnload(aIsInUnload); } \
  NS_SCRIPTABLE NS_IMETHOD GetChannelIsUnsafe(PRBool *aChannelIsUnsafe) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelIsUnsafe(aChannelIsUnsafe); } \
  NS_IMETHOD_(void) DetachEditorFromWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DetachEditorFromWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsOffScreenBrowser(PRBool *aIsOffScreenBrowser) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsOffScreenBrowser(aIsOffScreenBrowser); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsOffScreenBrowser(PRBool aIsOffScreenBrowser) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsOffScreenBrowser(aIsOffScreenBrowser); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShell : public nsIDocShell
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELL

  nsDocShell();

private:
  ~nsDocShell();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShell, nsIDocShell)

nsDocShell::nsDocShell()
{
  /* member initializers and constructor code */
}

nsDocShell::~nsDocShell()
{
  /* destructor code */
}

/* [noscript] void loadURI (in nsIURI uri, in nsIDocShellLoadInfo loadInfo, in unsigned long aLoadFlags, in boolean firstParty); */
NS_IMETHODIMP nsDocShell::LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, PRUint32 aLoadFlags, PRBool firstParty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void loadStream (in nsIInputStream aStream, in nsIURI aURI, in ACString aContentType, in ACString aContentCharset, in nsIDocShellLoadInfo aLoadInfo); */
NS_IMETHODIMP nsDocShell::LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void internalLoad (in nsIURI aURI, in nsIURI aReferrer, in nsISupports aOwner, in PRUint32 aFlags, in wstring aWindowTarget, in string aTypeHint, in nsIInputStream aPostDataStream, in nsIInputStream aHeadersStream, in unsigned long aLoadFlags, in nsISHEntry aSHEntry, in boolean firstParty, out nsIDocShell aDocShell, out nsIRequest aRequest); */
NS_IMETHODIMP nsDocShell::InternalLoad(nsIURI *aURI, nsIURI *aReferrer, nsISupports *aOwner, PRUint32 aFlags, const PRUnichar *aWindowTarget, const char *aTypeHint, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, PRUint32 aLoadFlags, nsISHEntry *aSHEntry, PRBool firstParty, nsIDocShell **aDocShell NS_OUTPARAM, nsIRequest **aRequest NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createLoadInfo (out nsIDocShellLoadInfo loadInfo); */
NS_IMETHODIMP nsDocShell::CreateLoadInfo(nsIDocShellLoadInfo **loadInfo NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void prepareForNewContentModel (); */
NS_IMETHODIMP nsDocShell::PrepareForNewContentModel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCurrentURI (in nsIURI aURI); */
NS_IMETHODIMP nsDocShell::SetCurrentURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void firePageHideNotification (in boolean isUnload); */
NS_IMETHODIMP nsDocShell::FirePageHideNotification(PRBool isUnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsPresContext presContext; */
NS_IMETHODIMP nsDocShell::GetPresContext(nsPresContext * *aPresContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIPresShell presShell; */
NS_IMETHODIMP nsDocShell::GetPresShell(nsIPresShell * *aPresShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIPresShell eldestPresShell; */
NS_IMETHODIMP nsDocShell::GetEldestPresShell(nsIPresShell * *aEldestPresShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIContentViewer contentViewer; */
NS_IMETHODIMP nsDocShell::GetContentViewer(nsIContentViewer * *aContentViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventTarget chromeEventHandler; */
NS_IMETHODIMP nsDocShell::GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetChromeEventHandler(nsIDOMEventTarget * aChromeEventHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDocumentCharsetInfo documentCharsetInfo; */
NS_IMETHODIMP nsDocShell::GetDocumentCharsetInfo(nsIDocumentCharsetInfo * *aDocumentCharsetInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetDocumentCharsetInfo(nsIDocumentCharsetInfo * aDocumentCharsetInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowPlugins; */
NS_IMETHODIMP nsDocShell::GetAllowPlugins(PRBool *aAllowPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowPlugins(PRBool aAllowPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowJavascript; */
NS_IMETHODIMP nsDocShell::GetAllowJavascript(PRBool *aAllowJavascript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowJavascript(PRBool aAllowJavascript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowMetaRedirects; */
NS_IMETHODIMP nsDocShell::GetAllowMetaRedirects(PRBool *aAllowMetaRedirects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowMetaRedirects(PRBool aAllowMetaRedirects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowSubframes; */
NS_IMETHODIMP nsDocShell::GetAllowSubframes(PRBool *aAllowSubframes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowSubframes(PRBool aAllowSubframes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowImages; */
NS_IMETHODIMP nsDocShell::GetAllowImages(PRBool *aAllowImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowImages(PRBool aAllowImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getDocShellEnumerator (in long aItemType, in long aDirection); */
NS_IMETHODIMP nsDocShell::GetDocShellEnumerator(PRInt32 aItemType, PRInt32 aDirection, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long appType; */
NS_IMETHODIMP nsDocShell::GetAppType(PRUint32 *aAppType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAppType(PRUint32 aAppType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowAuth; */
NS_IMETHODIMP nsDocShell::GetAllowAuth(PRBool *aAllowAuth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowAuth(PRBool aAllowAuth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float zoom; */
NS_IMETHODIMP nsDocShell::GetZoom(float *aZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetZoom(float aZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long marginWidth; */
NS_IMETHODIMP nsDocShell::GetMarginWidth(PRInt32 *aMarginWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetMarginWidth(PRInt32 aMarginWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long marginHeight; */
NS_IMETHODIMP nsDocShell::GetMarginHeight(PRInt32 *aMarginHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetMarginHeight(PRInt32 aMarginHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hasFocus; */
NS_IMETHODIMP nsDocShell::GetHasFocus(PRBool *aHasFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetHasFocus(PRBool aHasFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean canvasHasFocus; */
NS_IMETHODIMP nsDocShell::GetCanvasHasFocus(PRBool *aCanvasHasFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetCanvasHasFocus(PRBool aCanvasHasFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void tabToTreeOwner (in boolean forward, out boolean tookFocus); */
NS_IMETHODIMP nsDocShell::TabToTreeOwner(PRBool forward, PRBool *tookFocus NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long busyFlags; */
NS_IMETHODIMP nsDocShell::GetBusyFlags(PRUint32 *aBusyFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long loadType; */
NS_IMETHODIMP nsDocShell::GetLoadType(PRUint32 *aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetLoadType(PRUint32 aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isBeingDestroyed (); */
NS_IMETHODIMP nsDocShell::IsBeingDestroyed(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isExecutingOnLoadHandler; */
NS_IMETHODIMP nsDocShell::GetIsExecutingOnLoadHandler(PRBool *aIsExecutingOnLoadHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsILayoutHistoryState layoutHistoryState; */
NS_IMETHODIMP nsDocShell::GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetLayoutHistoryState(nsILayoutHistoryState * aLayoutHistoryState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shouldSaveLayoutState; */
NS_IMETHODIMP nsDocShell::GetShouldSaveLayoutState(PRBool *aShouldSaveLayoutState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISecureBrowserUI securityUI; */
NS_IMETHODIMP nsDocShell::GetSecurityUI(nsISecureBrowserUI * *aSecurityUI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetSecurityUI(nsISecureBrowserUI * aSecurityUI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspendRefreshURIs (); */
NS_IMETHODIMP nsDocShell::SuspendRefreshURIs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeRefreshURIs (); */
NS_IMETHODIMP nsDocShell::ResumeRefreshURIs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginRestore (in nsIContentViewer viewer, in boolean top); */
NS_IMETHODIMP nsDocShell::BeginRestore(nsIContentViewer *viewer, PRBool top)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finishRestore (); */
NS_IMETHODIMP nsDocShell::FinishRestore()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean restoringDocument; */
NS_IMETHODIMP nsDocShell::GetRestoringDocument(PRBool *aRestoringDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean useErrorPages; */
NS_IMETHODIMP nsDocShell::GetUseErrorPages(PRBool *aUseErrorPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetUseErrorPages(PRBool aUseErrorPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long previousTransIndex; */
NS_IMETHODIMP nsDocShell::GetPreviousTransIndex(PRInt32 *aPreviousTransIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long loadedTransIndex; */
NS_IMETHODIMP nsDocShell::GetLoadedTransIndex(PRInt32 *aLoadedTransIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void historyPurged (in long numEntries); */
NS_IMETHODIMP nsDocShell::HistoryPurged(PRInt32 numEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMStorage getSessionStorageForURI (in nsIURI uri); */
NS_IMETHODIMP nsDocShell::GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void addSessionStorage (in ACString aDomain, in nsIDOMStorage storage); */
NS_IMETHODIMP nsDocShell::AddSessionStorage(const nsACString & aDomain, nsIDOMStorage *storage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIChannel currentDocumentChannel; */
NS_IMETHODIMP nsDocShell::GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setChildOffset (in unsigned long offset); */
NS_IMETHODIMP nsDocShell::SetChildOffset(PRUint32 offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isInUnload; */
NS_IMETHODIMP nsDocShell::GetIsInUnload(PRBool *aIsInUnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean channelIsUnsafe; */
NS_IMETHODIMP nsDocShell::GetChannelIsUnsafe(PRBool *aChannelIsUnsafe)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] void DetachEditorFromWindow (); */
NS_IMETHODIMP_(void) nsDocShell::DetachEditorFromWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isOffScreenBrowser; */
NS_IMETHODIMP nsDocShell::GetIsOffScreenBrowser(PRBool *aIsOffScreenBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetIsOffScreenBrowser(PRBool aIsOffScreenBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDocShell_MOZILLA_1_9_1 */
#define NS_IDOCSHELL_MOZILLA_1_9_1_IID_STR "460ba822-e664-4c38-9b08-98d2736473d7"

#define NS_IDOCSHELL_MOZILLA_1_9_1_IID \
  {0x460ba822, 0xe664, 0x4c38, \
    { 0x9b, 0x08, 0x98, 0xd2, 0x73, 0x64, 0x73, 0xd7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocShell_MOZILLA_1_9_1 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELL_MOZILLA_1_9_1_IID)

  /* [noscript] nsIDOMStorage getSessionStorageForPrincipal (in nsIPrincipal principal, in boolean create); */
  NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShell_MOZILLA_1_9_1, NS_IDOCSHELL_MOZILLA_1_9_1_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELL_MOZILLA_1_9_1 \
  NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELL_MOZILLA_1_9_1(_to) \
  NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage **_retval NS_OUTPARAM) { return _to GetSessionStorageForPrincipal(principal, create, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELL_MOZILLA_1_9_1(_to) \
  NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorageForPrincipal(principal, create, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShell_MOZILLA_1_9_1 : public nsIDocShell_MOZILLA_1_9_1
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELL_MOZILLA_1_9_1

  nsDocShell_MOZILLA_1_9_1();

private:
  ~nsDocShell_MOZILLA_1_9_1();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShell_MOZILLA_1_9_1, nsIDocShell_MOZILLA_1_9_1)

nsDocShell_MOZILLA_1_9_1::nsDocShell_MOZILLA_1_9_1()
{
  /* member initializers and constructor code */
}

nsDocShell_MOZILLA_1_9_1::~nsDocShell_MOZILLA_1_9_1()
{
  /* destructor code */
}

/* [noscript] nsIDOMStorage getSessionStorageForPrincipal (in nsIPrincipal principal, in boolean create); */
NS_IMETHODIMP nsDocShell_MOZILLA_1_9_1::GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDocShell_MOZILLA_1_9_1_SessionStorage */
#define NS_IDOCSHELL_MOZILLA_1_9_1_SESSIONSTORAGE_IID_STR "b0534fdd-8a6c-4489-8c9e-471d7b2b2596"

#define NS_IDOCSHELL_MOZILLA_1_9_1_SESSIONSTORAGE_IID \
  {0xb0534fdd, 0x8a6c, 0x4489, \
    { 0x8c, 0x9e, 0x47, 0x1d, 0x7b, 0x2b, 0x25, 0x96 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocShell_MOZILLA_1_9_1_SessionStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELL_MOZILLA_1_9_1_SESSIONSTORAGE_IID)

  /* nsIDOMStorage2 getSessionStorageForURI (in nsIURI uri); */
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage2 **_retval NS_OUTPARAM) = 0;

  /* nsIDOMStorage2 getSessionStorageForPrincipal (in nsIPrincipal principal, in boolean create); */
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage2 **_retval NS_OUTPARAM) = 0;

  /* void addSessionStorage (in nsIPrincipal principal, in nsIDOMStorage2 storage); */
  NS_SCRIPTABLE NS_IMETHOD AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage2 *storage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShell_MOZILLA_1_9_1_SessionStorage, NS_IDOCSHELL_MOZILLA_1_9_1_SESSIONSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELL_MOZILLA_1_9_1_SESSIONSTORAGE \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage2 **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage2 **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage2 *storage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELL_MOZILLA_1_9_1_SESSIONSTORAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage2 **_retval NS_OUTPARAM) { return _to GetSessionStorageForURI(uri, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage2 **_retval NS_OUTPARAM) { return _to GetSessionStorageForPrincipal(principal, create, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage2 *storage) { return _to AddSessionStorage(principal, storage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELL_MOZILLA_1_9_1_SESSIONSTORAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage2 **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorageForURI(uri, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage2 **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorageForPrincipal(principal, create, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage2 *storage) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSessionStorage(principal, storage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShell_MOZILLA_1_9_1_SessionStorage : public nsIDocShell_MOZILLA_1_9_1_SessionStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELL_MOZILLA_1_9_1_SESSIONSTORAGE

  nsDocShell_MOZILLA_1_9_1_SessionStorage();

private:
  ~nsDocShell_MOZILLA_1_9_1_SessionStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShell_MOZILLA_1_9_1_SessionStorage, nsIDocShell_MOZILLA_1_9_1_SessionStorage)

nsDocShell_MOZILLA_1_9_1_SessionStorage::nsDocShell_MOZILLA_1_9_1_SessionStorage()
{
  /* member initializers and constructor code */
}

nsDocShell_MOZILLA_1_9_1_SessionStorage::~nsDocShell_MOZILLA_1_9_1_SessionStorage()
{
  /* destructor code */
}

/* nsIDOMStorage2 getSessionStorageForURI (in nsIURI uri); */
NS_IMETHODIMP nsDocShell_MOZILLA_1_9_1_SessionStorage::GetSessionStorageForURI(nsIURI *uri, nsIDOMStorage2 **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMStorage2 getSessionStorageForPrincipal (in nsIPrincipal principal, in boolean create); */
NS_IMETHODIMP nsDocShell_MOZILLA_1_9_1_SessionStorage::GetSessionStorageForPrincipal(nsIPrincipal *principal, PRBool create, nsIDOMStorage2 **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSessionStorage (in nsIPrincipal principal, in nsIDOMStorage2 storage); */
NS_IMETHODIMP nsDocShell_MOZILLA_1_9_1_SessionStorage::AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage2 *storage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDocShell_MOZILLA_1_9_1_dns */
#define NS_IDOCSHELL_MOZILLA_1_9_1_DNS_IID_STR "6cf71a12-c7d6-404d-b0b5-15ceae321337"

#define NS_IDOCSHELL_MOZILLA_1_9_1_DNS_IID \
  {0x6cf71a12, 0xc7d6, 0x404d, \
    { 0xb0, 0xb5, 0x15, 0xce, 0xae, 0x32, 0x13, 0x37 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocShell_MOZILLA_1_9_1_dns : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELL_MOZILLA_1_9_1_DNS_IID)

  /**
   * Attribute that determines whether DNS prefetch is allowed for this subtree
   * of the docshell tree.  Defaults to true.  Setting this will make it take
   * effect starting with the next document loaded in the docshell.
   */
  /* attribute boolean allowDNSPrefetch; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowDNSPrefetch(PRBool *aAllowDNSPrefetch) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAllowDNSPrefetch(PRBool aAllowDNSPrefetch) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShell_MOZILLA_1_9_1_dns, NS_IDOCSHELL_MOZILLA_1_9_1_DNS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELL_MOZILLA_1_9_1_DNS \
  NS_SCRIPTABLE NS_IMETHOD GetAllowDNSPrefetch(PRBool *aAllowDNSPrefetch); \
  NS_SCRIPTABLE NS_IMETHOD SetAllowDNSPrefetch(PRBool aAllowDNSPrefetch); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELL_MOZILLA_1_9_1_DNS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAllowDNSPrefetch(PRBool *aAllowDNSPrefetch) { return _to GetAllowDNSPrefetch(aAllowDNSPrefetch); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowDNSPrefetch(PRBool aAllowDNSPrefetch) { return _to SetAllowDNSPrefetch(aAllowDNSPrefetch); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELL_MOZILLA_1_9_1_DNS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAllowDNSPrefetch(PRBool *aAllowDNSPrefetch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowDNSPrefetch(aAllowDNSPrefetch); } \
  NS_SCRIPTABLE NS_IMETHOD SetAllowDNSPrefetch(PRBool aAllowDNSPrefetch) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowDNSPrefetch(aAllowDNSPrefetch); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShell_MOZILLA_1_9_1_dns : public nsIDocShell_MOZILLA_1_9_1_dns
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELL_MOZILLA_1_9_1_DNS

  nsDocShell_MOZILLA_1_9_1_dns();

private:
  ~nsDocShell_MOZILLA_1_9_1_dns();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShell_MOZILLA_1_9_1_dns, nsIDocShell_MOZILLA_1_9_1_dns)

nsDocShell_MOZILLA_1_9_1_dns::nsDocShell_MOZILLA_1_9_1_dns()
{
  /* member initializers and constructor code */
}

nsDocShell_MOZILLA_1_9_1_dns::~nsDocShell_MOZILLA_1_9_1_dns()
{
  /* destructor code */
}

/* attribute boolean allowDNSPrefetch; */
NS_IMETHODIMP nsDocShell_MOZILLA_1_9_1_dns::GetAllowDNSPrefetch(PRBool *aAllowDNSPrefetch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell_MOZILLA_1_9_1_dns::SetAllowDNSPrefetch(PRBool aAllowDNSPrefetch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShell_h__ */
