/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIWebNavigation.idl
 */

#ifndef __gen_nsIWebNavigation_h__
#define __gen_nsIWebNavigation_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsISHistory; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIWebNavigation */
#define NS_IWEBNAVIGATION_IID_STR "f5d9e7b0-d930-11d3-b057-00a024ffc08c"

#define NS_IWEBNAVIGATION_IID \
  {0xf5d9e7b0, 0xd930, 0x11d3, \
    { 0xb0, 0x57, 0x00, 0xa0, 0x24, 0xff, 0xc0, 0x8c }}

/**
 * The nsIWebNavigation interface defines an interface for navigating the web.
 * It provides methods and attributes to direct an object to navigate to a new
 * location, stop or restart an in process load, or determine where the object
 * has previously gone.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWebNavigation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBNAVIGATION_IID)

  /**
   * Indicates if the object can go back.  If true this indicates that
   * there is back session history available for navigation.
   */
  /* readonly attribute boolean canGoBack; */
  NS_SCRIPTABLE NS_IMETHOD GetCanGoBack(PRBool *aCanGoBack) = 0;

  /**
   * Indicates if the object can go forward.  If true this indicates that
   * there is forward session history available for navigation
   */
  /* readonly attribute boolean canGoForward; */
  NS_SCRIPTABLE NS_IMETHOD GetCanGoForward(PRBool *aCanGoForward) = 0;

  /**
   * Tells the object to navigate to the previous session history item.  When a
   * page is loaded from session history, all content is loaded from the cache
   * (if available) and page state (such as form values and scroll position) is
   * restored.
   *
   * @throw NS_ERROR_UNEXPECTED
   *        Indicates that the call was unexpected at this time, which implies
   *        that canGoBack is false.
   */
  /* void goBack (); */
  NS_SCRIPTABLE NS_IMETHOD GoBack(void) = 0;

  /**
   * Tells the object to navigate to the next session history item.  When a
   * page is loaded from session history, all content is loaded from the cache
   * (if available) and page state (such as form values and scroll position) is
   * restored.
   *
   * @throw NS_ERROR_UNEXPECTED
   *        Indicates that the call was unexpected at this time, which implies
   *        that canGoForward is false.
   */
  /* void goForward (); */
  NS_SCRIPTABLE NS_IMETHOD GoForward(void) = 0;

  /**
   * Tells the object to navigate to the session history item at a given index.
   *
   * @throw NS_ERROR_UNEXPECTED
   *        Indicates that the call was unexpected at this time, which implies
   *        that session history entry at the given index does not exist.
   */
  /* void gotoIndex (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GotoIndex(PRInt32 index) = 0;

  /****************************************************************************
   * The following flags may be bitwise combined to form the load flags
   * parameter passed to either the loadURI or reload method.  Some of these
   * flags are only applicable to loadURI.
   */
/**
   * This flags defines the range of bits that may be specified.  Flags
   * outside this range may be used, but may not be passed to Reload().
   */
  enum { LOAD_FLAGS_MASK = 65535U };

  /**
   * This is the default value for the load flags parameter.
   */
  enum { LOAD_FLAGS_NONE = 0U };

  /**
   * Flags 0x1, 0x2, 0x4, 0x8 are reserved for internal use by
   * nsIWebNavigation implementations for now.
   */
/**
   * This flag specifies that the load should have the semantics of an HTML
   * Meta-refresh tag (i.e., that the cache should be bypassed).  This flag
   * is only applicable to loadURI.
   * XXX the meaning of this flag is poorly defined.
   * XXX no one uses this, so we should probably deprecate and remove it.
   */
  enum { LOAD_FLAGS_IS_REFRESH = 16U };

  /**
   * This flag specifies that the load should have the semantics of a link
   * click.  This flag is only applicable to loadURI.
   * XXX the meaning of this flag is poorly defined.
   */
  enum { LOAD_FLAGS_IS_LINK = 32U };

  /**
   * This flag specifies that history should not be updated.  This flag is only
   * applicable to loadURI.
   */
  enum { LOAD_FLAGS_BYPASS_HISTORY = 64U };

  /**
   * This flag specifies that any existing history entry should be replaced.
   * This flag is only applicable to loadURI.
   */
  enum { LOAD_FLAGS_REPLACE_HISTORY = 128U };

  /**
   * This flag specifies that the local web cache should be bypassed, but an
   * intermediate proxy cache could still be used to satisfy the load.
   */
  enum { LOAD_FLAGS_BYPASS_CACHE = 256U };

  /**
   * This flag specifies that any intermediate proxy caches should be bypassed
   * (i.e., that the content should be loaded from the origin server).
   */
  enum { LOAD_FLAGS_BYPASS_PROXY = 512U };

  /**
   * This flag specifies that a reload was triggered as a result of detecting
   * an incorrect character encoding while parsing a previously loaded
   * document.
   */
  enum { LOAD_FLAGS_CHARSET_CHANGE = 1024U };

  /**
   * If this flag is set, Stop() will be called before the load starts
   * and will stop both content and network activity (the default is to
   * only stop network activity).  Effectively, this passes the
   * STOP_CONTENT flag to Stop(), in addition to the STOP_NETWORK flag.
   */
  enum { LOAD_FLAGS_STOP_CONTENT = 2048U };

  /**
   * A hint this load was prompted by an external program: take care!
   */
  enum { LOAD_FLAGS_FROM_EXTERNAL = 4096U };

  /**
   * This flag specifies that the URI may be submitted to a third-party
   * server for correction. This should only be applied to non-sensitive
   * URIs entered by users.  This flag must not be passed to Reload.
   */
  enum { LOAD_FLAGS_ALLOW_THIRD_PARTY_FIXUP = 8192U };

  /**
   * This flag specifies that this is the first load in this object.
   * Set with care, since setting incorrectly can cause us to assume that
   * nothing was actually loaded in this object if the load ends up being 
   * handled by an external application.  This flag must not be passed to
   * Reload.
   */
  enum { LOAD_FLAGS_FIRST_LOAD = 16384U };

  /**
   * This flag specifies that the load should not be subject to popup
   * blocking checks.  This flag must not be passed to Reload.
   */
  enum { LOAD_FLAGS_ALLOW_POPUPS = 32768U };

  /**
   * This flag specifies that the URI classifier should not be checked for
   * this load.  This flag must not be passed to Reload.
   */
  enum { LOAD_FLAGS_BYPASS_CLASSIFIER = 65536U };

  /**
   * Loads a given URI.  This will give priority to loading the requested URI
   * in the object implementing	this interface.  If it can't be loaded here
   * however, the URI dispatcher will go through its normal process of content
   * loading.
   *
   * @param aURI
   *        The URI string to load.  For HTTP and FTP URLs and possibly others,
   *        characters above U+007F will be converted to UTF-8 and then URL-
   *        escaped per the rules of RFC 2396.
   * @param aLoadFlags
   *        Flags modifying load behaviour.  This parameter is a bitwise
   *        combination of the load flags defined above.  (Undefined bits are
   *        reserved for future use.)  Generally you will pass LOAD_FLAGS_NONE
   *        for this parameter.
   * @param aReferrer
   *        The referring URI.  If this argument is null, then the referring
   *        URI will be inferred internally.
   * @param aPostData
   *        If the URI corresponds to a HTTP request, then this stream is
   *        appended directly to the HTTP request headers.  It may be prefixed
   *        with additional HTTP headers.  This stream must contain a "\r\n"
   *        sequence separating any HTTP headers from the HTTP request body.
   *        This parameter is optional and may be null.
   * @param aHeaders
   *        If the URI corresponds to a HTTP request, then any HTTP headers
   *        contained in this stream are set on the HTTP request.  The HTTP
   *        header stream is formatted as:
   *            ( HEADER "\r\n" )*
   *        This parameter is optional and may be null.
   */
  /* void loadURI (in wstring aURI, in unsigned long aLoadFlags, in nsIURI aReferrer, in nsIInputStream aPostData, in nsIInputStream aHeaders); */
  NS_SCRIPTABLE NS_IMETHOD LoadURI(const PRUnichar *aURI, PRUint32 aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders) = 0;

  /**
   * Tells the Object to reload the current page.  There may be cases where the
   * user will be asked to confirm the reload (for example, when it is
   * determined that the request is non-idempotent).
   *
   * @param aReloadFlags
   *        Flags modifying load behaviour.  This parameter is a bitwise
   *        combination of the Load Flags defined above.  (Undefined bits are
   *        reserved for future use.)  Generally you will pass LOAD_FLAGS_NONE
   *        for this parameter.
   *
   * @throw NS_BINDING_ABORTED
   *        Indicating that the user canceled the reload.
   */
  /* void reload (in unsigned long aReloadFlags); */
  NS_SCRIPTABLE NS_IMETHOD Reload(PRUint32 aReloadFlags) = 0;

  /****************************************************************************
   * The following flags may be passed as the stop flags parameter to the stop
   * method defined on this interface.
   */
/**
   * This flag specifies that all network activity should be stopped.  This
   * includes both active network loads and pending META-refreshes.
   */
  enum { STOP_NETWORK = 1U };

  /**
   * This flag specifies that all content activity should be stopped.  This
   * includes animated images, plugins and pending Javascript timeouts.
   */
  enum { STOP_CONTENT = 2U };

  /**
   * This flag specifies that all activity should be stopped.
   */
  enum { STOP_ALL = 3U };

  /**
   * Stops a load of a URI.
   *
   * @param aStopFlags
   *        This parameter is one of the stop flags defined above.
   */
  /* void stop (in unsigned long aStopFlags); */
  NS_SCRIPTABLE NS_IMETHOD Stop(PRUint32 aStopFlags) = 0;

  /**
   * Retrieves the current DOM document for the frame, or lazily creates a
   * blank document if there is none.  This attribute never returns null except
   * for unexpected error situations.
   */
  /* readonly attribute nsIDOMDocument document; */
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) = 0;

  /**
   * The currently loaded URI or null.
   */
  /* readonly attribute nsIURI currentURI; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) = 0;

  /**
   * The referring URI for the currently loaded URI or null.
   */
  /* readonly attribute nsIURI referringURI; */
  NS_SCRIPTABLE NS_IMETHOD GetReferringURI(nsIURI * *aReferringURI) = 0;

  /**
   * The session history object used by this web navigation instance.
   */
  /* attribute nsISHistory sessionHistory; */
  NS_SCRIPTABLE NS_IMETHOD GetSessionHistory(nsISHistory * *aSessionHistory) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSessionHistory(nsISHistory * aSessionHistory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebNavigation, NS_IWEBNAVIGATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBNAVIGATION \
  NS_SCRIPTABLE NS_IMETHOD GetCanGoBack(PRBool *aCanGoBack); \
  NS_SCRIPTABLE NS_IMETHOD GetCanGoForward(PRBool *aCanGoForward); \
  NS_SCRIPTABLE NS_IMETHOD GoBack(void); \
  NS_SCRIPTABLE NS_IMETHOD GoForward(void); \
  NS_SCRIPTABLE NS_IMETHOD GotoIndex(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD LoadURI(const PRUnichar *aURI, PRUint32 aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders); \
  NS_SCRIPTABLE NS_IMETHOD Reload(PRUint32 aReloadFlags); \
  NS_SCRIPTABLE NS_IMETHOD Stop(PRUint32 aStopFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI); \
  NS_SCRIPTABLE NS_IMETHOD GetReferringURI(nsIURI * *aReferringURI); \
  NS_SCRIPTABLE NS_IMETHOD GetSessionHistory(nsISHistory * *aSessionHistory); \
  NS_SCRIPTABLE NS_IMETHOD SetSessionHistory(nsISHistory * aSessionHistory); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBNAVIGATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCanGoBack(PRBool *aCanGoBack) { return _to GetCanGoBack(aCanGoBack); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanGoForward(PRBool *aCanGoForward) { return _to GetCanGoForward(aCanGoForward); } \
  NS_SCRIPTABLE NS_IMETHOD GoBack(void) { return _to GoBack(); } \
  NS_SCRIPTABLE NS_IMETHOD GoForward(void) { return _to GoForward(); } \
  NS_SCRIPTABLE NS_IMETHOD GotoIndex(PRInt32 index) { return _to GotoIndex(index); } \
  NS_SCRIPTABLE NS_IMETHOD LoadURI(const PRUnichar *aURI, PRUint32 aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders) { return _to LoadURI(aURI, aLoadFlags, aReferrer, aPostData, aHeaders); } \
  NS_SCRIPTABLE NS_IMETHOD Reload(PRUint32 aReloadFlags) { return _to Reload(aReloadFlags); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(PRUint32 aStopFlags) { return _to Stop(aStopFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return _to GetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) { return _to GetCurrentURI(aCurrentURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferringURI(nsIURI * *aReferringURI) { return _to GetReferringURI(aReferringURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetSessionHistory(nsISHistory * *aSessionHistory) { return _to GetSessionHistory(aSessionHistory); } \
  NS_SCRIPTABLE NS_IMETHOD SetSessionHistory(nsISHistory * aSessionHistory) { return _to SetSessionHistory(aSessionHistory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBNAVIGATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCanGoBack(PRBool *aCanGoBack) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanGoBack(aCanGoBack); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanGoForward(PRBool *aCanGoForward) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanGoForward(aCanGoForward); } \
  NS_SCRIPTABLE NS_IMETHOD GoBack(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GoBack(); } \
  NS_SCRIPTABLE NS_IMETHOD GoForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GoForward(); } \
  NS_SCRIPTABLE NS_IMETHOD GotoIndex(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->GotoIndex(index); } \
  NS_SCRIPTABLE NS_IMETHOD LoadURI(const PRUnichar *aURI, PRUint32 aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURI(aURI, aLoadFlags, aReferrer, aPostData, aHeaders); } \
  NS_SCRIPTABLE NS_IMETHOD Reload(PRUint32 aReloadFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reload(aReloadFlags); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(PRUint32 aStopFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(aStopFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentURI(aCurrentURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferringURI(nsIURI * *aReferringURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferringURI(aReferringURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetSessionHistory(nsISHistory * *aSessionHistory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionHistory(aSessionHistory); } \
  NS_SCRIPTABLE NS_IMETHOD SetSessionHistory(nsISHistory * aSessionHistory) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSessionHistory(aSessionHistory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebNavigation : public nsIWebNavigation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBNAVIGATION

  nsWebNavigation();

private:
  ~nsWebNavigation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebNavigation, nsIWebNavigation)

nsWebNavigation::nsWebNavigation()
{
  /* member initializers and constructor code */
}

nsWebNavigation::~nsWebNavigation()
{
  /* destructor code */
}

/* readonly attribute boolean canGoBack; */
NS_IMETHODIMP nsWebNavigation::GetCanGoBack(PRBool *aCanGoBack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canGoForward; */
NS_IMETHODIMP nsWebNavigation::GetCanGoForward(PRBool *aCanGoForward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void goBack (); */
NS_IMETHODIMP nsWebNavigation::GoBack()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void goForward (); */
NS_IMETHODIMP nsWebNavigation::GoForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void gotoIndex (in long index); */
NS_IMETHODIMP nsWebNavigation::GotoIndex(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadURI (in wstring aURI, in unsigned long aLoadFlags, in nsIURI aReferrer, in nsIInputStream aPostData, in nsIInputStream aHeaders); */
NS_IMETHODIMP nsWebNavigation::LoadURI(const PRUnichar *aURI, PRUint32 aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reload (in unsigned long aReloadFlags); */
NS_IMETHODIMP nsWebNavigation::Reload(PRUint32 aReloadFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (in unsigned long aStopFlags); */
NS_IMETHODIMP nsWebNavigation::Stop(PRUint32 aStopFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument document; */
NS_IMETHODIMP nsWebNavigation::GetDocument(nsIDOMDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI currentURI; */
NS_IMETHODIMP nsWebNavigation::GetCurrentURI(nsIURI * *aCurrentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI referringURI; */
NS_IMETHODIMP nsWebNavigation::GetReferringURI(nsIURI * *aReferringURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISHistory sessionHistory; */
NS_IMETHODIMP nsWebNavigation::GetSessionHistory(nsISHistory * *aSessionHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebNavigation::SetSessionHistory(nsISHistory * aSessionHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebNavigation_h__ */
