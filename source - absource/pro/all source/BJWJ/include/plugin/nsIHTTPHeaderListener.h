/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIHTTPHeaderListener.idl
 */

#ifndef __gen_nsIHTTPHeaderListener_h__
#define __gen_nsIHTTPHeaderListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHTTPHeaderListener */
#define NS_IHTTPHEADERLISTENER_IID_STR "ea51e0b8-871c-4b85-92da-6f400394c5ec"

#define NS_IHTTPHEADERLISTENER_IID \
  {0xea51e0b8, 0x871c, 0x4b85, \
    { 0x92, 0xda, 0x6f, 0x40, 0x03, 0x94, 0xc5, 0xec }}

/**
 * The nsIHTTPHeaderListener interface allows plugin authors to
 * access HTTP Response headers after issuing an
 * nsIPluginManager::{GetURL,PostURL}() call. <P>

 * IMPORTANT NOTE: The plugin author must provide an instance to
 * {GetURL,PostURL}() that implements both nsIPluginStreamListener and
 * nsIHTTPHeaderListener.  This instance is passed in through
 * {GetURL,PostURL}()'s streamListener parameter.  The browser will then
 * QI thi streamListener to see if it implements
 * nsIHTTPHeaderListener.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIHTTPHeaderListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPHEADERLISTENER_IID)

  /**
   * Called for each HTTP Response header.
   * NOTE: You must copy the values of the params.  
   */
  /* void newResponseHeader (in string headerName, in string headerValue); */
  NS_SCRIPTABLE NS_IMETHOD NewResponseHeader(const char *headerName, const char *headerValue) = 0;

  /**
   * Called once for the HTTP Response status line.
   * Value does NOT include a terminating newline.
   * NOTE: You must copy this value.
   */
  /* void statusLine (in string line); */
  NS_SCRIPTABLE NS_IMETHOD StatusLine(const char *line) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTTPHeaderListener, NS_IHTTPHEADERLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPHEADERLISTENER \
  NS_SCRIPTABLE NS_IMETHOD NewResponseHeader(const char *headerName, const char *headerValue); \
  NS_SCRIPTABLE NS_IMETHOD StatusLine(const char *line); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPHEADERLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewResponseHeader(const char *headerName, const char *headerValue) { return _to NewResponseHeader(headerName, headerValue); } \
  NS_SCRIPTABLE NS_IMETHOD StatusLine(const char *line) { return _to StatusLine(line); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPHEADERLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewResponseHeader(const char *headerName, const char *headerValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewResponseHeader(headerName, headerValue); } \
  NS_SCRIPTABLE NS_IMETHOD StatusLine(const char *line) { return !_to ? NS_ERROR_NULL_POINTER : _to->StatusLine(line); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTTPHeaderListener : public nsIHTTPHeaderListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPHEADERLISTENER

  nsHTTPHeaderListener();

private:
  ~nsHTTPHeaderListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTTPHeaderListener, nsIHTTPHeaderListener)

nsHTTPHeaderListener::nsHTTPHeaderListener()
{
  /* member initializers and constructor code */
}

nsHTTPHeaderListener::~nsHTTPHeaderListener()
{
  /* destructor code */
}

/* void newResponseHeader (in string headerName, in string headerValue); */
NS_IMETHODIMP nsHTTPHeaderListener::NewResponseHeader(const char *headerName, const char *headerValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void statusLine (in string line); */
NS_IMETHODIMP nsHTTPHeaderListener::StatusLine(const char *line)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTTPHeaderListener_h__ */
