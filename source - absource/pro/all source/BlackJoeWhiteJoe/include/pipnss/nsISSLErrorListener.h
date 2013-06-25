/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsISSLErrorListener.idl
 */

#ifndef __gen_nsISSLErrorListener_h__
#define __gen_nsISSLErrorListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsISSLErrorListener */
#define NS_ISSLERRORLISTENER_IID_STR "99f8d972-bae4-414c-b39b-47587d3ded68"

#define NS_ISSLERRORLISTENER_IID \
  {0x99f8d972, 0xbae4, 0x414c, \
    { 0xb3, 0x9b, 0x47, 0x58, 0x7d, 0x3d, 0xed, 0x68 }}

/**
 * A mechanism to report a broken SSL connection. The recipient should NOT block.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISSLErrorListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISSLERRORLISTENER_IID)

  /**
   *  @param socketInfo A network communication context that can be used to obtain more information
   *                    about the active connection.
   *  @param error The code associated with the error.
   *  @param targetSite The Site name that was used to open the current connection.
   *
   *  @return The consumer shall return true if it wants to suppress the error message
   *          related to the error (the connection will still get canceled).
   */
  /* boolean notifySSLError (in nsIInterfaceRequestor socketInfo, in PRInt32 error, in AUTF8String targetSite); */
  NS_SCRIPTABLE NS_IMETHOD NotifySSLError(nsIInterfaceRequestor *socketInfo, PRInt32 error, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISSLErrorListener, NS_ISSLERRORLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISSLERRORLISTENER \
  NS_SCRIPTABLE NS_IMETHOD NotifySSLError(nsIInterfaceRequestor *socketInfo, PRInt32 error, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISSLERRORLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifySSLError(nsIInterfaceRequestor *socketInfo, PRInt32 error, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM) { return _to NotifySSLError(socketInfo, error, targetSite, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISSLERRORLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifySSLError(nsIInterfaceRequestor *socketInfo, PRInt32 error, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySSLError(socketInfo, error, targetSite, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSSLErrorListener : public nsISSLErrorListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISSLERRORLISTENER

  nsSSLErrorListener();

private:
  ~nsSSLErrorListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSSLErrorListener, nsISSLErrorListener)

nsSSLErrorListener::nsSSLErrorListener()
{
  /* member initializers and constructor code */
}

nsSSLErrorListener::~nsSSLErrorListener()
{
  /* destructor code */
}

/* boolean notifySSLError (in nsIInterfaceRequestor socketInfo, in PRInt32 error, in AUTF8String targetSite); */
NS_IMETHODIMP nsSSLErrorListener::NotifySSLError(nsIInterfaceRequestor *socketInfo, PRInt32 error, const nsACString & targetSite, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISSLErrorListener_h__ */
