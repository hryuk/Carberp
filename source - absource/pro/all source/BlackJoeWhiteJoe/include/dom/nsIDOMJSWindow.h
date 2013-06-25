/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMJSWindow.idl
 */

#ifndef __gen_nsIDOMJSWindow_h__
#define __gen_nsIDOMJSWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMJSWindow */
#define NS_IDOMJSWINDOW_IID_STR "14efb76c-5bd6-449e-b36f-0cbd22981f20"

#define NS_IDOMJSWINDOW_IID \
  {0x14efb76c, 0x5bd6, 0x449e, \
    { 0xb3, 0x6f, 0x0c, 0xbd, 0x22, 0x98, 0x1f, 0x20 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMJSWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMJSWINDOW_IID)

  /* void dump (in DOMString str); */
  NS_SCRIPTABLE NS_IMETHOD Dump(const nsAString & str) = 0;

  /**
   * These methods take typeless arguments and optional arguments, the
   * first argument is either a function or a string, the second
   * argument must be a number (ms) and the rest of the arguments (2
   * ... n) are passed to the callback function
   */
  /* long setTimeout (); */
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long setInterval (); */
  NS_SCRIPTABLE NS_IMETHOD SetInterval(PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * These methods take one optional argument that's the timer ID to
   * clear. Often in existing code these methods are passed undefined,
   * which is a nop so we need to support that as well.
   */
  /* void clearTimeout (); */
  NS_SCRIPTABLE NS_IMETHOD ClearTimeout(void) = 0;

  /* void clearInterval (); */
  NS_SCRIPTABLE NS_IMETHOD ClearInterval(void) = 0;

  /**
   * This method is here for backwards compatibility with 4.x only,
   * its implementation is a no-op
   */
  /* void setResizable (in boolean resizable); */
  NS_SCRIPTABLE NS_IMETHOD SetResizable(PRBool resizable) = 0;

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

  /* void enableExternalCapture (); */
  NS_SCRIPTABLE NS_IMETHOD EnableExternalCapture(void) = 0;

  /* void disableExternalCapture (); */
  NS_SCRIPTABLE NS_IMETHOD DisableExternalCapture(void) = 0;

  /**
   * This is the scriptable version of nsIDOMWindowInternal::open()
   * that takes 3 optional arguments. Its binary name is OpenJS to
   * avoid colliding with nsIDOMWindowInternal::open(), which has the
   * same signature. The reason we can't have that collision is that
   * the implementation needs to know whether it was called from JS or
   * not.
   *
   * IOW, DO NOT CALL THIS FROM C++
   */
  /* [binaryname (OpenJS)] nsIDOMWindow open ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
  NS_SCRIPTABLE NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM) = 0;

  /**
   * This is the scriptable version of
   * nsIDOMWindowInternal::openDialog() that takes 3 optional
   * arguments, plus any additional arguments are passed on as
   * arguments on the dialog's window object (window.arguments).
   */
  /* nsIDOMWindow openDialog ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
  NS_SCRIPTABLE NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM) = 0;

  /**
   * window.frames in Netscape 4.x and IE is just a reference to the
   * window itself (i.e. window.frames === window), but this doesn't
   * make sense from a generic API point of view so that's why this is
   * JS specific.
   *
   * This property is "replaceable" in JavaScript.
   */
  /* readonly attribute nsIDOMWindow frames; */
  NS_SCRIPTABLE NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMJSWindow, NS_IDOMJSWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMJSWINDOW \
  NS_SCRIPTABLE NS_IMETHOD Dump(const nsAString & str); \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetInterval(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ClearTimeout(void); \
  NS_SCRIPTABLE NS_IMETHOD ClearInterval(void); \
  NS_SCRIPTABLE NS_IMETHOD SetResizable(PRBool resizable); \
  NS_SCRIPTABLE NS_IMETHOD CaptureEvents(PRInt32 eventFlags); \
  NS_SCRIPTABLE NS_IMETHOD ReleaseEvents(PRInt32 eventFlags); \
  NS_SCRIPTABLE NS_IMETHOD RouteEvent(nsIDOMEvent *evt); \
  NS_SCRIPTABLE NS_IMETHOD EnableExternalCapture(void); \
  NS_SCRIPTABLE NS_IMETHOD DisableExternalCapture(void); \
  NS_SCRIPTABLE NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMJSWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD Dump(const nsAString & str) { return _to Dump(str); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 *_retval NS_OUTPARAM) { return _to SetTimeout(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetInterval(PRInt32 *_retval NS_OUTPARAM) { return _to SetInterval(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearTimeout(void) { return _to ClearTimeout(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearInterval(void) { return _to ClearInterval(); } \
  NS_SCRIPTABLE NS_IMETHOD SetResizable(PRBool resizable) { return _to SetResizable(resizable); } \
  NS_SCRIPTABLE NS_IMETHOD CaptureEvents(PRInt32 eventFlags) { return _to CaptureEvents(eventFlags); } \
  NS_SCRIPTABLE NS_IMETHOD ReleaseEvents(PRInt32 eventFlags) { return _to ReleaseEvents(eventFlags); } \
  NS_SCRIPTABLE NS_IMETHOD RouteEvent(nsIDOMEvent *evt) { return _to RouteEvent(evt); } \
  NS_SCRIPTABLE NS_IMETHOD EnableExternalCapture(void) { return _to EnableExternalCapture(); } \
  NS_SCRIPTABLE NS_IMETHOD DisableExternalCapture(void) { return _to DisableExternalCapture(); } \
  NS_SCRIPTABLE NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM) { return _to OpenJS(url, name, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM) { return _to OpenDialog(url, name, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) { return _to GetFrames(aFrames); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMJSWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD Dump(const nsAString & str) { return !_to ? NS_ERROR_NULL_POINTER : _to->Dump(str); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeout(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetInterval(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInterval(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearTimeout(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearTimeout(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearInterval(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearInterval(); } \
  NS_SCRIPTABLE NS_IMETHOD SetResizable(PRBool resizable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResizable(resizable); } \
  NS_SCRIPTABLE NS_IMETHOD CaptureEvents(PRInt32 eventFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CaptureEvents(eventFlags); } \
  NS_SCRIPTABLE NS_IMETHOD ReleaseEvents(PRInt32 eventFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseEvents(eventFlags); } \
  NS_SCRIPTABLE NS_IMETHOD RouteEvent(nsIDOMEvent *evt) { return !_to ? NS_ERROR_NULL_POINTER : _to->RouteEvent(evt); } \
  NS_SCRIPTABLE NS_IMETHOD EnableExternalCapture(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableExternalCapture(); } \
  NS_SCRIPTABLE NS_IMETHOD DisableExternalCapture(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableExternalCapture(); } \
  NS_SCRIPTABLE NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenJS(url, name, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDialog(url, name, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrames(aFrames); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMJSWindow : public nsIDOMJSWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMJSWINDOW

  nsDOMJSWindow();

private:
  ~nsDOMJSWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMJSWindow, nsIDOMJSWindow)

nsDOMJSWindow::nsDOMJSWindow()
{
  /* member initializers and constructor code */
}

nsDOMJSWindow::~nsDOMJSWindow()
{
  /* destructor code */
}

/* void dump (in DOMString str); */
NS_IMETHODIMP nsDOMJSWindow::Dump(const nsAString & str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long setTimeout (); */
NS_IMETHODIMP nsDOMJSWindow::SetTimeout(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long setInterval (); */
NS_IMETHODIMP nsDOMJSWindow::SetInterval(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearTimeout (); */
NS_IMETHODIMP nsDOMJSWindow::ClearTimeout()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearInterval (); */
NS_IMETHODIMP nsDOMJSWindow::ClearInterval()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setResizable (in boolean resizable); */
NS_IMETHODIMP nsDOMJSWindow::SetResizable(PRBool resizable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void captureEvents (in long eventFlags); */
NS_IMETHODIMP nsDOMJSWindow::CaptureEvents(PRInt32 eventFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseEvents (in long eventFlags); */
NS_IMETHODIMP nsDOMJSWindow::ReleaseEvents(PRInt32 eventFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void routeEvent (in nsIDOMEvent evt); */
NS_IMETHODIMP nsDOMJSWindow::RouteEvent(nsIDOMEvent *evt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableExternalCapture (); */
NS_IMETHODIMP nsDOMJSWindow::EnableExternalCapture()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableExternalCapture (); */
NS_IMETHODIMP nsDOMJSWindow::DisableExternalCapture()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname (OpenJS)] nsIDOMWindow open ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
NS_IMETHODIMP nsDOMJSWindow::OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow openDialog ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
NS_IMETHODIMP nsDOMJSWindow::OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow frames; */
NS_IMETHODIMP nsDOMJSWindow::GetFrames(nsIDOMWindow * *aFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMJSWindow_h__ */
