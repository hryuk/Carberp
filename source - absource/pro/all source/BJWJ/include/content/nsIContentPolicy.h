/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIContentPolicy.idl
 */

#ifndef __gen_nsIContentPolicy_h__
#define __gen_nsIContentPolicy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMNode; /* forward declaration */


/* starting interface:    nsIContentPolicy */
#define NS_ICONTENTPOLICY_IID_STR "344f9cb0-9a17-44c5-ab96-ee707884266c"

#define NS_ICONTENTPOLICY_IID \
  {0x344f9cb0, 0x9a17, 0x44c5, \
    { 0xab, 0x96, 0xee, 0x70, 0x78, 0x84, 0x26, 0x6c }}

/**
 * Interface for content policy mechanism.  Implementations of this
 * interface can be used to control loading of various types of out-of-line
 * content, or processing of certain types of in-line content.
 *
 * WARNING: do not block the caller from shouldLoad or shouldProcess (e.g.,
 * by launching a dialog to prompt the user for something).
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIContentPolicy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPOLICY_IID)

  enum { TYPE_OTHER = 1U };

  /**
   * Indicates an executable script (such as JavaScript).
   */
  enum { TYPE_SCRIPT = 2U };

  /**
   * Indicates an image (e.g., IMG elements).
   */
  enum { TYPE_IMAGE = 3U };

  /**
   * Indicates a stylesheet (e.g., STYLE elements).
   */
  enum { TYPE_STYLESHEET = 4U };

  /**
   * Indicates a generic object (plugin-handled content typically falls under
   * this category).
   */
  enum { TYPE_OBJECT = 5U };

  /**
   * Indicates a document at the top-level (i.e., in a browser).
   */
  enum { TYPE_DOCUMENT = 6U };

  /**
   * Indicates a document contained within another document (e.g., IFRAMEs,
   * FRAMES, and OBJECTs).
   */
  enum { TYPE_SUBDOCUMENT = 7U };

  /**
   * Indicates a timed refresh.
   *
   * shouldLoad will never get this, because it does not represent content
   * to be loaded (the actual load triggered by the refresh will go through
   * shouldLoad as expected).
   *
   * shouldProcess will get this for, e.g., META Refresh elements and HTTP
   * Refresh headers.
   */
  enum { TYPE_REFRESH = 8U };

  /**
   * Indicates an XBL binding request, triggered either by -moz-binding CSS
   * property or Document.addBinding method.
   */
  enum { TYPE_XBL = 9U };

  /**
   * Indicates a ping triggered by a click on <A PING="..."> element.
   */
  enum { TYPE_PING = 10U };

  /**
   * Indicates an XMLHttpRequest.
   */
  enum { TYPE_XMLHTTPREQUEST = 11U };

  /**
   * Indicates a request by a plugin.
   */
  enum { TYPE_OBJECT_SUBREQUEST = 12U };

  /**
   * Indicates a DTD loaded by an XML document.
   */
  enum { TYPE_DTD = 13U };

  /**
   * Indicates a font loaded via @font-face rule.
   */
  enum { TYPE_FONT = 14U };

  /**
   * Indicates a video or audio load.
   */
  enum { TYPE_MEDIA = 15U };

  /**
   * Returned from shouldLoad or shouldProcess if the load or process request
   * is rejected based on details of the request.
   */
  enum { REJECT_REQUEST = -1 };

  /**
   * Returned from shouldLoad or shouldProcess if the load/process is rejected
   * based solely on its type (of the above flags).
   *
   * NOTE that it is not meant to stop future requests for this type--only the
   * current request.
   */
  enum { REJECT_TYPE = -2 };

  /**
   * Returned from shouldLoad or shouldProcess if the load/process is rejected
   * based on the server it is hosted on or requested from (aContentLocation or
   * aRequestOrigin), e.g., if you block an IMAGE because it is served from
   * goatse.cx (even if you don't necessarily block other types from that
   * server/domain).
   * 
   * NOTE that it is not meant to stop future requests for this server--only the
   * current request.
   */
  enum { REJECT_SERVER = -3 };

  /**
   * Returned from shouldLoad or shouldProcess if the load/process is rejected
   * based on some other criteria. Mozilla callers will handle this like
   * REJECT_REQUEST; third-party implementors may, for example, use this to
   * direct their own callers to consult the extra parameter for additional
   * details.
   */
  enum { REJECT_OTHER = -4 };

  /**
   * Returned from shouldLoad or shouldProcess if the load or process request
   * is not rejected.
   */
  enum { ACCEPT = 1 };

  /**
   * Should the resource at this location be loaded?
   * ShouldLoad will be called before loading the resource at aContentLocation
   * to determine whether to start the load at all.
   *
   * @param aContentType      the type of content being tested. This will be one
   *                          one of the TYPE_* constants.
   *
   * @param aContentLocation  the location of the content being checked; must
   *                          not be null
   *
   * @param aRequestOrigin    OPTIONAL. the location of the resource that
   *                          initiated this load request; can be null if
   *                          inapplicable
   *
   * @param aContext          OPTIONAL. the nsIDOMNode or nsIDOMWindow that
   *                          initiated the request, or something that can QI
   *                          to one of those; can be null if inapplicable.
   *
   * @param aMimeTypeGuess    OPTIONAL. a guess for the requested content's
   *                          MIME type, based on information available to
   *                          the request initiator (e.g., an OBJECT's type
   *                          attribute); does not reliably reflect the
   *                          actual MIME type of the requested content
   *
   * @param aExtra            an OPTIONAL argument, pass-through for non-Gecko
   *                          callers to pass extra data to callees.
   *
   * @return ACCEPT or REJECT_*
   *
   * @note shouldLoad can be called while the DOM and layout of the document
   * involved is in an inconsistent state.  This means that implementors of
   * this method MUST NOT do any of the following:
   * 1)  Modify the DOM in any way (e.g. setting attributes is a no-no).
   * 2)  Query any DOM properties that depend on layout (e.g. offset*
   *     properties).
   * 3)  Query any DOM properties that depend on style (e.g. computed style).
   * 4)  Query any DOM properties that depend on the current state of the DOM
   *     outside the "context" node (e.g. lengths of node lists).
   * 5)  [JavaScript implementations only] Access properties of any sort on any
   *     object without using XPCNativeWrapper (either explicitly or
   *     implicitly).  Due to various DOM0 things, this leads to item 4.
   * If you do any of these things in your shouldLoad implementation, expect
   * unpredictable behavior, possibly including crashes, content not showing
   * up, content showing up doubled, etc.  If you need to do any of the things
   * above, do them off timeout or event.
   */
  /* short shouldLoad (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra); */
  NS_SCRIPTABLE NS_IMETHOD ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) = 0;

  /**
   * Should the resource be processed?
   * ShouldProcess will be called once all the information passed to it has
   * been determined about the resource, typically after part of the resource
   * has been loaded.
   *
   * @param aContentType      the type of content being tested. This will be one
   *                          one of the TYPE_* constants.
   *
   * @param aContentLocation  OPTIONAL; the location of the resource being
   *                          requested: MAY be, e.g., a post-redirection URI
   *                          for the resource.
   *
   * @param aRequestOrigin    OPTIONAL. the location of the resource that
   *                          initiated this load request; can be null if
   *                          inapplicable
   *
   * @param aContext          OPTIONAL. the nsIDOMNode or nsIDOMWindow that
   *                          initiated the request, or something that can QI
   *                          to one of those; can be null if inapplicable.
   *
   * @param aMimeType         the MIME type of the requested resource (e.g.,
   *                          image/png), as reported by the networking library,
   *                          if available (may be empty if inappropriate for
   *                          the type, e.g., TYPE_REFRESH).
   *
   * @param aExtra            an OPTIONAL argument, pass-through for non-Gecko
   *                          callers to pass extra data to callees.
   *
   * @return ACCEPT or REJECT_*
   *
   * @note shouldProcess can be called while the DOM and layout of the document
   * involved is in an inconsistent state.  See the note on shouldLoad to see
   * what this means for implementors of this method.
   */
  /* short shouldProcess (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra); */
  NS_SCRIPTABLE NS_IMETHOD ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPolicy, NS_ICONTENTPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPOLICY \
  NS_SCRIPTABLE NS_IMETHOD ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPOLICY(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) { return _to ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) { return _to ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPOLICY(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPolicy : public nsIContentPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPOLICY

  nsContentPolicy();

private:
  ~nsContentPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPolicy, nsIContentPolicy)

nsContentPolicy::nsContentPolicy()
{
  /* member initializers and constructor code */
}

nsContentPolicy::~nsContentPolicy()
{
  /* destructor code */
}

/* short shouldLoad (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra); */
NS_IMETHODIMP nsContentPolicy::ShouldLoad(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short shouldProcess (in unsigned long aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra); */
NS_IMETHODIMP nsContentPolicy::ShouldProcess(PRUint32 aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentPolicy_h__ */
