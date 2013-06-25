/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIXMLHttpRequest.idl
 */

#ifndef __gen_nsIXMLHttpRequest_h__
#define __gen_nsIXMLHttpRequest_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIScriptContext; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsPIDOMWindow; /* forward declaration */


/* starting interface:    nsIXMLHttpRequestEventTarget */
#define NS_IXMLHTTPREQUESTEVENTTARGET_IID_STR "6ce0a193-b033-4c3d-b748-f851b09261f5"

#define NS_IXMLHTTPREQUESTEVENTTARGET_IID \
  {0x6ce0a193, 0xb033, 0x4c3d, \
    { 0xb7, 0x48, 0xf8, 0x51, 0xb0, 0x92, 0x61, 0xf5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXMLHttpRequestEventTarget : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXMLHTTPREQUESTEVENTTARGET_IID)

  /* attribute nsIDOMEventListener onabort; */
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener * *aOnabort) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener * aOnabort) = 0;

  /* attribute nsIDOMEventListener onerror; */
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener * aOnerror) = 0;

  /* attribute nsIDOMEventListener onload; */
  NS_SCRIPTABLE NS_IMETHOD GetOnload(nsIDOMEventListener * *aOnload) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnload(nsIDOMEventListener * aOnload) = 0;

  /* attribute nsIDOMEventListener onloadstart; */
  NS_SCRIPTABLE NS_IMETHOD GetOnloadstart(nsIDOMEventListener * *aOnloadstart) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnloadstart(nsIDOMEventListener * aOnloadstart) = 0;

  /* attribute nsIDOMEventListener onprogress; */
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener * aOnprogress) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXMLHttpRequestEventTarget, NS_IXMLHTTPREQUESTEVENTTARGET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXMLHTTPREQUESTEVENTTARGET \
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener * *aOnabort); \
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener * aOnabort); \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener * aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD GetOnload(nsIDOMEventListener * *aOnload); \
  NS_SCRIPTABLE NS_IMETHOD SetOnload(nsIDOMEventListener * aOnload); \
  NS_SCRIPTABLE NS_IMETHOD GetOnloadstart(nsIDOMEventListener * *aOnloadstart); \
  NS_SCRIPTABLE NS_IMETHOD SetOnloadstart(nsIDOMEventListener * aOnloadstart); \
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress); \
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener * aOnprogress); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXMLHTTPREQUESTEVENTTARGET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener * *aOnabort) { return _to GetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener * aOnabort) { return _to SetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener * aOnerror) { return _to SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnload(nsIDOMEventListener * *aOnload) { return _to GetOnload(aOnload); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnload(nsIDOMEventListener * aOnload) { return _to SetOnload(aOnload); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnloadstart(nsIDOMEventListener * *aOnloadstart) { return _to GetOnloadstart(aOnloadstart); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnloadstart(nsIDOMEventListener * aOnloadstart) { return _to SetOnloadstart(aOnloadstart); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) { return _to GetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener * aOnprogress) { return _to SetOnprogress(aOnprogress); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXMLHTTPREQUESTEVENTTARGET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener * *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener * aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener * aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnload(nsIDOMEventListener * *aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnload(aOnload); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnload(nsIDOMEventListener * aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnload(aOnload); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnloadstart(nsIDOMEventListener * *aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadstart(aOnloadstart); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnloadstart(nsIDOMEventListener * aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadstart(aOnloadstart); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener * aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnprogress(aOnprogress); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXMLHttpRequestEventTarget : public nsIXMLHttpRequestEventTarget
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXMLHTTPREQUESTEVENTTARGET

  nsXMLHttpRequestEventTarget();

private:
  ~nsXMLHttpRequestEventTarget();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXMLHttpRequestEventTarget, nsIXMLHttpRequestEventTarget)

nsXMLHttpRequestEventTarget::nsXMLHttpRequestEventTarget()
{
  /* member initializers and constructor code */
}

nsXMLHttpRequestEventTarget::~nsXMLHttpRequestEventTarget()
{
  /* destructor code */
}

/* attribute nsIDOMEventListener onabort; */
NS_IMETHODIMP nsXMLHttpRequestEventTarget::GetOnabort(nsIDOMEventListener * *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequestEventTarget::SetOnabort(nsIDOMEventListener * aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onerror; */
NS_IMETHODIMP nsXMLHttpRequestEventTarget::GetOnerror(nsIDOMEventListener * *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequestEventTarget::SetOnerror(nsIDOMEventListener * aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onload; */
NS_IMETHODIMP nsXMLHttpRequestEventTarget::GetOnload(nsIDOMEventListener * *aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequestEventTarget::SetOnload(nsIDOMEventListener * aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onloadstart; */
NS_IMETHODIMP nsXMLHttpRequestEventTarget::GetOnloadstart(nsIDOMEventListener * *aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequestEventTarget::SetOnloadstart(nsIDOMEventListener * aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onprogress; */
NS_IMETHODIMP nsXMLHttpRequestEventTarget::GetOnprogress(nsIDOMEventListener * *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequestEventTarget::SetOnprogress(nsIDOMEventListener * aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXMLHttpRequestUpload */
#define NS_IXMLHTTPREQUESTUPLOAD_IID_STR "09ff3682-7759-4441-a765-f70e1a1fabcf"

#define NS_IXMLHTTPREQUESTUPLOAD_IID \
  {0x09ff3682, 0x7759, 0x4441, \
    { 0xa7, 0x65, 0xf7, 0x0e, 0x1a, 0x1f, 0xab, 0xcf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXMLHttpRequestUpload : public nsIXMLHttpRequestEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXMLHTTPREQUESTUPLOAD_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXMLHttpRequestUpload, NS_IXMLHTTPREQUESTUPLOAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXMLHTTPREQUESTUPLOAD \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXMLHTTPREQUESTUPLOAD(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXMLHTTPREQUESTUPLOAD(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXMLHttpRequestUpload : public nsIXMLHttpRequestUpload
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXMLHTTPREQUESTUPLOAD

  nsXMLHttpRequestUpload();

private:
  ~nsXMLHttpRequestUpload();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXMLHttpRequestUpload, nsIXMLHttpRequestUpload)

nsXMLHttpRequestUpload::nsXMLHttpRequestUpload()
{
  /* member initializers and constructor code */
}

nsXMLHttpRequestUpload::~nsXMLHttpRequestUpload()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXMLHttpRequest */
#define NS_IXMLHTTPREQUEST_IID_STR "ad78bf21-2227-447e-8ed5-824a017c265f"

#define NS_IXMLHTTPREQUEST_IID \
  {0xad78bf21, 0x2227, 0x447e, \
    { 0x8e, 0xd5, 0x82, 0x4a, 0x01, 0x7c, 0x26, 0x5f }}

/**
 * Mozilla's XMLHttpRequest is modelled after Microsoft's IXMLHttpRequest
 * object. The goal has been to make Mozilla's version match Microsoft's
 * version as closely as possible, but there are bound to be some differences.
 *
 * In general, Microsoft's documentation for IXMLHttpRequest can be used.
 * Mozilla's interface definitions provide some additional documentation. The
 * web page to look at is http://www.mozilla.org/xmlextras/
 *
 * Mozilla's XMLHttpRequest object can be created in JavaScript like this:
 *   new XMLHttpRequest()
 * compare to Internet Explorer:
 *   new ActiveXObject("Msxml2.XMLHTTP")
 *
 * From JavaScript, the methods and properties visible in the XMLHttpRequest
 * object are a combination of nsIXMLHttpRequest and nsIJSXMLHttpRequest;
 * there is no need to differentiate between those interfaces.
 *
 * From native code, the way to set up onload and onerror handlers is a bit
 * different. Here is a comment from Johnny Stenback <jst@netscape.com>:
 *
 *   The mozilla implementation of nsIXMLHttpRequest implements the interface
 *   nsIDOMEventTarget and that's how you're supported to add event listeners.
 *   Try something like this:
 *
 *   nsCOMPtr<nsIDOMEventTarget> target(do_QueryInterface(myxmlhttpreq));
 *
 *   target->AddEventListener(NS_LITERAL_STRING("load"), mylistener,
 *                            PR_FALSE)
 *
 *   where mylistener is your event listener object that implements the
 *   interface nsIDOMEventListener.
 *
 *   The 'onload', 'onerror', and 'onreadystatechange' attributes moved to
 *   nsIJSXMLHttpRequest, but if you're coding in C++ you should avoid using
 *   those.
 *
 * Conclusion: Do not use event listeners on XMLHttpRequest from C++, unless
 * you're aware of all the security implications.  And then think twice about
 * it.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXMLHttpRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXMLHTTPREQUEST_IID)

  /**
   * The request uses a channel in order to perform the
   * request.  This attribute represents the channel used
   * for the request.  NULL if the channel has not yet been
   * created.
   *
   * In a multipart request case, this is the initial channel, not the
   * different parts in the multipart request.
   *
   * Mozilla only. Requires elevated privileges to access.
   */
  /* readonly attribute nsIChannel channel; */
  NS_SCRIPTABLE NS_IMETHOD GetChannel(nsIChannel * *aChannel) = 0;

  /**
   * The response to the request is parsed as if it were a
   * text/xml stream. This attributes represents the response as
   * a DOM Document object. NULL if the request is unsuccessful or
   * has not yet been sent.
   */
  /* readonly attribute nsIDOMDocument responseXML; */
  NS_SCRIPTABLE NS_IMETHOD GetResponseXML(nsIDOMDocument * *aResponseXML) = 0;

  /**
   * The response to the request as text.
   * NULL if the request is unsuccessful or
   * has not yet been sent.
   */
  /* readonly attribute AString responseText; */
  NS_SCRIPTABLE NS_IMETHOD GetResponseText(nsAString & aResponseText) = 0;

  /**
   * The status of the response to the request for HTTP requests.
   */
  /* readonly attribute unsigned long status; */
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint32 *aStatus) = 0;

  /**
   * The string representing the status of the response for
   * HTTP requests.
   */
  /* readonly attribute AUTF8String statusText; */
  NS_SCRIPTABLE NS_IMETHOD GetStatusText(nsACString & aStatusText) = 0;

  /**
   * If the request has been sent already, this method will
   * abort the request.
   */
  /* void abort (); */
  NS_SCRIPTABLE NS_IMETHOD Abort(void) = 0;

  /**
   * Returns all of the response headers as a string for HTTP
   * requests.
   *
   * Note that this will return all the headers from the *current*
   * part of a multipart request, not from the original channel.
   *
   * @returns A string containing all of the response headers.
   *          NULL if the response has not yet been received.
   */
  /* string getAllResponseHeaders (); */
  NS_SCRIPTABLE NS_IMETHOD GetAllResponseHeaders(char **_retval NS_OUTPARAM) = 0;

  /**
   * Returns the text of the header with the specified name for
   * HTTP requests.
   *
   * @param header The name of the header to retrieve
   * @returns A string containing the text of the header specified.
   *          NULL if the response has not yet been received or the
   *          header does not exist in the response.
   */
  /* ACString getResponseHeader (in AUTF8String header); */
  NS_SCRIPTABLE NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Native (non-script) method to initialize a request. Note that
   * the request is not sent until the <code>send</code> method
   * is invoked.
   *
   * If there is an "active" request (that is, if open() or openRequest() has
   * been called already), this is equivalent to calling abort().
   *
   * @param method The HTTP method, for example "POST" or "GET". Ignored
   *               if the URL is not a HTTP(S) URL.
   * @param url The URL to which to send the request.
   * @param async Whether the request is synchronous or asynchronous
   *              i.e. whether send returns only after the response
   *              is received or if it returns immediately after
   *              sending the request. In the latter case, notification
   *              of completion is sent through the event listeners.
   *              This argument must be true if the multipart
   *              attribute has been set to true, or an exception will
   *              be thrown.
   * @param user A username for authentication if necessary.
   * @param password A password for authentication if necessary.
   */
  /* [noscript] void openRequest (in AUTF8String method, in AUTF8String url, in boolean async, in AString user, in AString password); */
  NS_IMETHOD OpenRequest(const nsACString & method, const nsACString & url, PRBool async, const nsAString & user, const nsAString & password) = 0;

  /**
   * Meant to be a script-only method for initializing a request.
   * The parameters are similar to the ones detailed in the
   * description of <code>openRequest</code>, but the last
   * 3 are optional.
   *
   * If there is an "active" request (that is, if open() or openRequest() has
   * been called already), this is equivalent to calling abort().
   *
   * @param method The HTTP method - either "POST" or "GET". Ignored
   *               if the URL is not a HTTP URL.
   * @param url The URL to which to send the request.
   * @param async (optional) Whether the request is synchronous or
   *              asynchronous i.e. whether send returns only after
   *              the response is received or if it returns immediately after
   *              sending the request. In the latter case, notification
   *              of completion is sent through the event listeners.
   *              The default value is true.
   *              This argument must be true if the multipart
   *              attribute has been set to true, or an exception will
   *              be thrown.
   * @param user (optional) A username for authentication if necessary.
   *             The default value is the empty string
   * @param password (optional) A password for authentication if necessary.
   *                 The default value is the empty string
   */
  /* void open (in AUTF8String method, in AUTF8String url); */
  NS_SCRIPTABLE NS_IMETHOD Open(const nsACString & method, const nsACString & url) = 0;

  /**
   * Sends the request. If the request is asynchronous, returns
   * immediately after sending the request. If it is synchronous
   * returns only after the response has been received.
   *
   * All event listeners must be set before calling send().
   *
   * After the initial response, all event listeners will be cleared.
   * // XXXbz what does that mean, exactly?   
   *
   * @param body Either an instance of nsIDOMDocument, nsIInputStream
   *             or a string (nsISupportsString in the native calling
   *             case). This is used to populate the body of the
   *             HTTP request if the HTTP request method is "POST".
   *             If the parameter is a nsIDOMDocument, it is serialized.
   *             If the parameter is a nsIInputStream, then it must be
   *             compatible with nsIUploadChannel.setUploadStream, and a
   *             Content-Length header will be added to the HTTP request
   *             with a value given by nsIInputStream.available.  Any
   *             headers included at the top of the stream will be
   *             treated as part of the message body.  The MIME type of
   *             the stream should be specified by setting the Content-
   *             Type header via the setRequestHeader method before
   *             calling send.
   */
  /* void send ([optional] in nsIVariant body); */
  NS_SCRIPTABLE NS_IMETHOD Send(nsIVariant *body) = 0;

  /**
   * A variant of the send() method used to send binary data.
   *
   * @param body The request body as a DOM string.  The string data will be
   *             converted to a single-byte string by truncation (i.e., the
   *             high-order byte of each character will be discarded).
   */
  /* void sendAsBinary (in DOMString body); */
  NS_SCRIPTABLE NS_IMETHOD SendAsBinary(const nsAString & body) = 0;

  /**
   * Sets a HTTP request header for HTTP requests. You must call open
   * before setting the request headers.
   *
   * @param header The name of the header to set in the request.
   * @param value The body of the header.
   */
  /* void setRequestHeader (in AUTF8String header, in AUTF8String value); */
  NS_SCRIPTABLE NS_IMETHOD SetRequestHeader(const nsACString & header, const nsACString & value) = 0;

  /**
   * The state of the request.
   *
   * Possible values:
   *   0 UNINITIALIZED open() has not been called yet.
   *   1 LOADING       send() has not been called yet.
   *   2 LOADED        send() has been called, headers and status are available.
   *   3 INTERACTIVE   Downloading, responseText holds the partial data.
   *   4 COMPLETED     Finished with all operations.
   */
  /* readonly attribute long readyState; */
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRInt32 *aReadyState) = 0;

  /**
   * Override the mime type returned by the server (if any). This may
   * be used, for example, to force a stream to be treated and parsed
   * as text/xml, even if the server does not report it as such. This
   * must be done before the <code>send</code> method is invoked.
   *
   * @param mimetype The type used to override that returned by the server
   *                 (if any).
   */
  /* void overrideMimeType (in AUTF8String mimetype); */
  NS_SCRIPTABLE NS_IMETHOD OverrideMimeType(const nsACString & mimetype) = 0;

  /**
   * Set to true if the response is expected to be a stream of
   * possibly multiple (XML) documents. If set to true, the content
   * type of the initial response must be multipart/x-mixed-replace or
   * an error will be triggerd. All requests must be asynchronous.
   *
   * This enables server push. For each XML document that's written to
   * this request, a new XML DOM document is created and the onload
   * handler is called inbetween documents. Note that when this is
   * set, the onload handler and other event handlers are not reset
   * after the first XML document is loaded, and the onload handler
   * will be called as each part of the response is received.
   */
  /* attribute boolean multipart; */
  NS_SCRIPTABLE NS_IMETHOD GetMultipart(PRBool *aMultipart) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMultipart(PRBool aMultipart) = 0;

  /**
   * Set to true if this is a background service request. This will
   * prevent a load group being associated with the request, and
   * suppress any security dialogs from being shown * to the user.
   * In the cases where one of those dialogs would be shown, the request
   * will simply fail instead.
   */
  /* attribute boolean mozBackgroundRequest; */
  NS_SCRIPTABLE NS_IMETHOD GetMozBackgroundRequest(PRBool *aMozBackgroundRequest) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMozBackgroundRequest(PRBool aMozBackgroundRequest) = 0;

  /**
   * When set to true attempts to make cross-site Access-Control requests
   * with credentials such as cookies and authorization headers.
   *
   * Never affects same-site requests.
   *
   * Defaults to false.
   */
  /* attribute boolean withCredentials; */
  NS_SCRIPTABLE NS_IMETHOD GetWithCredentials(PRBool *aWithCredentials) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWithCredentials(PRBool aWithCredentials) = 0;

  /**
   * Initialize the object for use from C++ code with the principal, script
   * context, and owner window that should be used.
   *
   * @param principal The principal to use for the request. This must not be
   *                  null.
   * @param scriptContext The script context to use for the request. May be
   *                      null.
   * @param ownerWindow The associated window for the request. May be null.
   * @param baseURI The base URI to use when resolving relative URIs. May be
   *                null.
   */
  /* [noscript] void init (in nsIPrincipal principal, in nsIScriptContext scriptContext, in nsPIDOMWindow ownerWindow, in nsIURI baseURI); */
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, nsIURI *baseURI) = 0;

  /**
   * Upload process can be tracked by adding event listener to |upload|.
   */
  /* readonly attribute nsIXMLHttpRequestUpload upload; */
  NS_SCRIPTABLE NS_IMETHOD GetUpload(nsIXMLHttpRequestUpload * *aUpload) = 0;

  /**
   * Meant to be a script-only mechanism for setting a callback function.
   * The attribute is expected to be JavaScript function object. When the
   * readyState changes, the callback function will be called.
   * This attribute should not be used from native code!!
   *
   * After the initial response, all event listeners will be cleared.
   * // XXXbz what does that mean, exactly?   
   *
   * Call open() before setting an onreadystatechange listener.
   */
  /* attribute nsIDOMEventListener onreadystatechange; */
  NS_SCRIPTABLE NS_IMETHOD GetOnreadystatechange(nsIDOMEventListener * *aOnreadystatechange) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnreadystatechange(nsIDOMEventListener * aOnreadystatechange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXMLHttpRequest, NS_IXMLHTTPREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXMLHTTPREQUEST \
  NS_SCRIPTABLE NS_IMETHOD GetChannel(nsIChannel * *aChannel); \
  NS_SCRIPTABLE NS_IMETHOD GetResponseXML(nsIDOMDocument * *aResponseXML); \
  NS_SCRIPTABLE NS_IMETHOD GetResponseText(nsAString & aResponseText); \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint32 *aStatus); \
  NS_SCRIPTABLE NS_IMETHOD GetStatusText(nsACString & aStatusText); \
  NS_SCRIPTABLE NS_IMETHOD Abort(void); \
  NS_SCRIPTABLE NS_IMETHOD GetAllResponseHeaders(char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval NS_OUTPARAM); \
  NS_IMETHOD OpenRequest(const nsACString & method, const nsACString & url, PRBool async, const nsAString & user, const nsAString & password); \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsACString & method, const nsACString & url); \
  NS_SCRIPTABLE NS_IMETHOD Send(nsIVariant *body); \
  NS_SCRIPTABLE NS_IMETHOD SendAsBinary(const nsAString & body); \
  NS_SCRIPTABLE NS_IMETHOD SetRequestHeader(const nsACString & header, const nsACString & value); \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRInt32 *aReadyState); \
  NS_SCRIPTABLE NS_IMETHOD OverrideMimeType(const nsACString & mimetype); \
  NS_SCRIPTABLE NS_IMETHOD GetMultipart(PRBool *aMultipart); \
  NS_SCRIPTABLE NS_IMETHOD SetMultipart(PRBool aMultipart); \
  NS_SCRIPTABLE NS_IMETHOD GetMozBackgroundRequest(PRBool *aMozBackgroundRequest); \
  NS_SCRIPTABLE NS_IMETHOD SetMozBackgroundRequest(PRBool aMozBackgroundRequest); \
  NS_SCRIPTABLE NS_IMETHOD GetWithCredentials(PRBool *aWithCredentials); \
  NS_SCRIPTABLE NS_IMETHOD SetWithCredentials(PRBool aWithCredentials); \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, nsIURI *baseURI); \
  NS_SCRIPTABLE NS_IMETHOD GetUpload(nsIXMLHttpRequestUpload * *aUpload); \
  NS_SCRIPTABLE NS_IMETHOD GetOnreadystatechange(nsIDOMEventListener * *aOnreadystatechange); \
  NS_SCRIPTABLE NS_IMETHOD SetOnreadystatechange(nsIDOMEventListener * aOnreadystatechange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXMLHTTPREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChannel(nsIChannel * *aChannel) { return _to GetChannel(aChannel); } \
  NS_SCRIPTABLE NS_IMETHOD GetResponseXML(nsIDOMDocument * *aResponseXML) { return _to GetResponseXML(aResponseXML); } \
  NS_SCRIPTABLE NS_IMETHOD GetResponseText(nsAString & aResponseText) { return _to GetResponseText(aResponseText); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint32 *aStatus) { return _to GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatusText(nsACString & aStatusText) { return _to GetStatusText(aStatusText); } \
  NS_SCRIPTABLE NS_IMETHOD Abort(void) { return _to Abort(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllResponseHeaders(char **_retval NS_OUTPARAM) { return _to GetAllResponseHeaders(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval NS_OUTPARAM) { return _to GetResponseHeader(header, _retval); } \
  NS_IMETHOD OpenRequest(const nsACString & method, const nsACString & url, PRBool async, const nsAString & user, const nsAString & password) { return _to OpenRequest(method, url, async, user, password); } \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsACString & method, const nsACString & url) { return _to Open(method, url); } \
  NS_SCRIPTABLE NS_IMETHOD Send(nsIVariant *body) { return _to Send(body); } \
  NS_SCRIPTABLE NS_IMETHOD SendAsBinary(const nsAString & body) { return _to SendAsBinary(body); } \
  NS_SCRIPTABLE NS_IMETHOD SetRequestHeader(const nsACString & header, const nsACString & value) { return _to SetRequestHeader(header, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRInt32 *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD OverrideMimeType(const nsACString & mimetype) { return _to OverrideMimeType(mimetype); } \
  NS_SCRIPTABLE NS_IMETHOD GetMultipart(PRBool *aMultipart) { return _to GetMultipart(aMultipart); } \
  NS_SCRIPTABLE NS_IMETHOD SetMultipart(PRBool aMultipart) { return _to SetMultipart(aMultipart); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozBackgroundRequest(PRBool *aMozBackgroundRequest) { return _to GetMozBackgroundRequest(aMozBackgroundRequest); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozBackgroundRequest(PRBool aMozBackgroundRequest) { return _to SetMozBackgroundRequest(aMozBackgroundRequest); } \
  NS_SCRIPTABLE NS_IMETHOD GetWithCredentials(PRBool *aWithCredentials) { return _to GetWithCredentials(aWithCredentials); } \
  NS_SCRIPTABLE NS_IMETHOD SetWithCredentials(PRBool aWithCredentials) { return _to SetWithCredentials(aWithCredentials); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, nsIURI *baseURI) { return _to Init(principal, scriptContext, ownerWindow, baseURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpload(nsIXMLHttpRequestUpload * *aUpload) { return _to GetUpload(aUpload); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnreadystatechange(nsIDOMEventListener * *aOnreadystatechange) { return _to GetOnreadystatechange(aOnreadystatechange); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnreadystatechange(nsIDOMEventListener * aOnreadystatechange) { return _to SetOnreadystatechange(aOnreadystatechange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXMLHTTPREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChannel(nsIChannel * *aChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannel(aChannel); } \
  NS_SCRIPTABLE NS_IMETHOD GetResponseXML(nsIDOMDocument * *aResponseXML) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseXML(aResponseXML); } \
  NS_SCRIPTABLE NS_IMETHOD GetResponseText(nsAString & aResponseText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseText(aResponseText); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint32 *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatusText(nsACString & aStatusText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatusText(aStatusText); } \
  NS_SCRIPTABLE NS_IMETHOD Abort(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Abort(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllResponseHeaders(char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllResponseHeaders(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetResponseHeader(const nsACString & header, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseHeader(header, _retval); } \
  NS_IMETHOD OpenRequest(const nsACString & method, const nsACString & url, PRBool async, const nsAString & user, const nsAString & password) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenRequest(method, url, async, user, password); } \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsACString & method, const nsACString & url) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(method, url); } \
  NS_SCRIPTABLE NS_IMETHOD Send(nsIVariant *body) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(body); } \
  NS_SCRIPTABLE NS_IMETHOD SendAsBinary(const nsAString & body) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendAsBinary(body); } \
  NS_SCRIPTABLE NS_IMETHOD SetRequestHeader(const nsACString & header, const nsACString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRequestHeader(header, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRInt32 *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD OverrideMimeType(const nsACString & mimetype) { return !_to ? NS_ERROR_NULL_POINTER : _to->OverrideMimeType(mimetype); } \
  NS_SCRIPTABLE NS_IMETHOD GetMultipart(PRBool *aMultipart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMultipart(aMultipart); } \
  NS_SCRIPTABLE NS_IMETHOD SetMultipart(PRBool aMultipart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMultipart(aMultipart); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozBackgroundRequest(PRBool *aMozBackgroundRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozBackgroundRequest(aMozBackgroundRequest); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozBackgroundRequest(PRBool aMozBackgroundRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozBackgroundRequest(aMozBackgroundRequest); } \
  NS_SCRIPTABLE NS_IMETHOD GetWithCredentials(PRBool *aWithCredentials) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWithCredentials(aWithCredentials); } \
  NS_SCRIPTABLE NS_IMETHOD SetWithCredentials(PRBool aWithCredentials) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWithCredentials(aWithCredentials); } \
  NS_IMETHOD Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, nsIURI *baseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(principal, scriptContext, ownerWindow, baseURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpload(nsIXMLHttpRequestUpload * *aUpload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpload(aUpload); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnreadystatechange(nsIDOMEventListener * *aOnreadystatechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnreadystatechange(aOnreadystatechange); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnreadystatechange(nsIDOMEventListener * aOnreadystatechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnreadystatechange(aOnreadystatechange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXMLHttpRequest : public nsIXMLHttpRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXMLHTTPREQUEST

  nsXMLHttpRequest();

private:
  ~nsXMLHttpRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXMLHttpRequest, nsIXMLHttpRequest)

nsXMLHttpRequest::nsXMLHttpRequest()
{
  /* member initializers and constructor code */
}

nsXMLHttpRequest::~nsXMLHttpRequest()
{
  /* destructor code */
}

/* readonly attribute nsIChannel channel; */
NS_IMETHODIMP nsXMLHttpRequest::GetChannel(nsIChannel * *aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument responseXML; */
NS_IMETHODIMP nsXMLHttpRequest::GetResponseXML(nsIDOMDocument * *aResponseXML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString responseText; */
NS_IMETHODIMP nsXMLHttpRequest::GetResponseText(nsAString & aResponseText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long status; */
NS_IMETHODIMP nsXMLHttpRequest::GetStatus(PRUint32 *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String statusText; */
NS_IMETHODIMP nsXMLHttpRequest::GetStatusText(nsACString & aStatusText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (); */
NS_IMETHODIMP nsXMLHttpRequest::Abort()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getAllResponseHeaders (); */
NS_IMETHODIMP nsXMLHttpRequest::GetAllResponseHeaders(char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getResponseHeader (in AUTF8String header); */
NS_IMETHODIMP nsXMLHttpRequest::GetResponseHeader(const nsACString & header, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void openRequest (in AUTF8String method, in AUTF8String url, in boolean async, in AString user, in AString password); */
NS_IMETHODIMP nsXMLHttpRequest::OpenRequest(const nsACString & method, const nsACString & url, PRBool async, const nsAString & user, const nsAString & password)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (in AUTF8String method, in AUTF8String url); */
NS_IMETHODIMP nsXMLHttpRequest::Open(const nsACString & method, const nsACString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send ([optional] in nsIVariant body); */
NS_IMETHODIMP nsXMLHttpRequest::Send(nsIVariant *body)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendAsBinary (in DOMString body); */
NS_IMETHODIMP nsXMLHttpRequest::SendAsBinary(const nsAString & body)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRequestHeader (in AUTF8String header, in AUTF8String value); */
NS_IMETHODIMP nsXMLHttpRequest::SetRequestHeader(const nsACString & header, const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long readyState; */
NS_IMETHODIMP nsXMLHttpRequest::GetReadyState(PRInt32 *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void overrideMimeType (in AUTF8String mimetype); */
NS_IMETHODIMP nsXMLHttpRequest::OverrideMimeType(const nsACString & mimetype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean multipart; */
NS_IMETHODIMP nsXMLHttpRequest::GetMultipart(PRBool *aMultipart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequest::SetMultipart(PRBool aMultipart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean mozBackgroundRequest; */
NS_IMETHODIMP nsXMLHttpRequest::GetMozBackgroundRequest(PRBool *aMozBackgroundRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequest::SetMozBackgroundRequest(PRBool aMozBackgroundRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean withCredentials; */
NS_IMETHODIMP nsXMLHttpRequest::GetWithCredentials(PRBool *aWithCredentials)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequest::SetWithCredentials(PRBool aWithCredentials)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIPrincipal principal, in nsIScriptContext scriptContext, in nsPIDOMWindow ownerWindow, in nsIURI baseURI); */
NS_IMETHODIMP nsXMLHttpRequest::Init(nsIPrincipal *principal, nsIScriptContext *scriptContext, nsPIDOMWindow *ownerWindow, nsIURI *baseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXMLHttpRequestUpload upload; */
NS_IMETHODIMP nsXMLHttpRequest::GetUpload(nsIXMLHttpRequestUpload * *aUpload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onreadystatechange; */
NS_IMETHODIMP nsXMLHttpRequest::GetOnreadystatechange(nsIDOMEventListener * *aOnreadystatechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXMLHttpRequest::SetOnreadystatechange(nsIDOMEventListener * aOnreadystatechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJSXMLHttpRequest */
#define NS_IJSXMLHTTPREQUEST_IID_STR "423fdd3d-41c9-4149-8fe5-b14a1d3912a0"

#define NS_IJSXMLHTTPREQUEST_IID \
  {0x423fdd3d, 0x41c9, 0x4149, \
    { 0x8f, 0xe5, 0xb1, 0x4a, 0x1d, 0x39, 0x12, 0xa0 }}

/**
 * DEPRECATED.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIJSXMLHttpRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSXMLHTTPREQUEST_IID)

  /**
   * Meant to be a script-only mechanism for setting an upload progress event
   * listener.
   * This attribute should not be used from native code!!
   * This event listener may be called multiple times during the upload..
   *
   * After the initial response, all event listeners will be cleared.
   * // XXXbz what does that mean, exactly?
   *
   * This event listener must be set BEFORE calling open().
   *
   * Mozilla only.
   */
  /* attribute nsIDOMEventListener onuploadprogress; */
  NS_SCRIPTABLE NS_IMETHOD GetOnuploadprogress(nsIDOMEventListener * *aOnuploadprogress) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnuploadprogress(nsIDOMEventListener * aOnuploadprogress) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSXMLHttpRequest, NS_IJSXMLHTTPREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSXMLHTTPREQUEST \
  NS_SCRIPTABLE NS_IMETHOD GetOnuploadprogress(nsIDOMEventListener * *aOnuploadprogress); \
  NS_SCRIPTABLE NS_IMETHOD SetOnuploadprogress(nsIDOMEventListener * aOnuploadprogress); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSXMLHTTPREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnuploadprogress(nsIDOMEventListener * *aOnuploadprogress) { return _to GetOnuploadprogress(aOnuploadprogress); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnuploadprogress(nsIDOMEventListener * aOnuploadprogress) { return _to SetOnuploadprogress(aOnuploadprogress); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSXMLHTTPREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnuploadprogress(nsIDOMEventListener * *aOnuploadprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnuploadprogress(aOnuploadprogress); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnuploadprogress(nsIDOMEventListener * aOnuploadprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnuploadprogress(aOnuploadprogress); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSXMLHttpRequest : public nsIJSXMLHttpRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSXMLHTTPREQUEST

  nsJSXMLHttpRequest();

private:
  ~nsJSXMLHttpRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSXMLHttpRequest, nsIJSXMLHttpRequest)

nsJSXMLHttpRequest::nsJSXMLHttpRequest()
{
  /* member initializers and constructor code */
}

nsJSXMLHttpRequest::~nsJSXMLHttpRequest()
{
  /* destructor code */
}

/* attribute nsIDOMEventListener onuploadprogress; */
NS_IMETHODIMP nsJSXMLHttpRequest::GetOnuploadprogress(nsIDOMEventListener * *aOnuploadprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJSXMLHttpRequest::SetOnuploadprogress(nsIDOMEventListener * aOnuploadprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_XMLHTTPREQUEST_CID                       \
 { /* d164e770-4157-11d4-9a42-000064657374 */       \
  0xd164e770, 0x4157, 0x11d4,                       \
 {0x9a, 0x42, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74} }
#define NS_XMLHTTPREQUEST_CONTRACTID \
"@mozilla.org/xmlextras/xmlhttprequest;1"

#endif /* __gen_nsIXMLHttpRequest_h__ */
