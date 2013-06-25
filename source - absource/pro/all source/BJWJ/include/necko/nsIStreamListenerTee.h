/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIStreamListenerTee.idl
 */

#ifndef __gen_nsIStreamListenerTee_h__
#define __gen_nsIStreamListenerTee_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIStreamListenerTee */
#define NS_ISTREAMLISTENERTEE_IID_STR "fb683e76-d42b-41a4-8ae6-65a6c2b146e5"

#define NS_ISTREAMLISTENERTEE_IID \
  {0xfb683e76, 0xd42b, 0x41a4, \
    { 0x8a, 0xe6, 0x65, 0xa6, 0xc2, 0xb1, 0x46, 0xe5 }}

/**
 * As data "flows" into a stream listener tee, it is copied to the output stream
 * and then forwarded to the real listener.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIStreamListenerTee : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMLISTENERTEE_IID)

  /* void init (in nsIStreamListener listener, in nsIOutputStream sink); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIStreamListener *listener, nsIOutputStream *sink) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamListenerTee, NS_ISTREAMLISTENERTEE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMLISTENERTEE \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIStreamListener *listener, nsIOutputStream *sink); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMLISTENERTEE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIStreamListener *listener, nsIOutputStream *sink) { return _to Init(listener, sink); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMLISTENERTEE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIStreamListener *listener, nsIOutputStream *sink) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(listener, sink); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamListenerTee : public nsIStreamListenerTee
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMLISTENERTEE

  nsStreamListenerTee();

private:
  ~nsStreamListenerTee();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamListenerTee, nsIStreamListenerTee)

nsStreamListenerTee::nsStreamListenerTee()
{
  /* member initializers and constructor code */
}

nsStreamListenerTee::~nsStreamListenerTee()
{
  /* destructor code */
}

/* void init (in nsIStreamListener listener, in nsIOutputStream sink); */
NS_IMETHODIMP nsStreamListenerTee::Init(nsIStreamListener *listener, nsIOutputStream *sink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamListenerTee_h__ */
