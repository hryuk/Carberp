/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/geolocation/nsIDOMGeoPositionErrorCallback.idl
 */

#ifndef __gen_nsIDOMGeoPositionErrorCallback_h__
#define __gen_nsIDOMGeoPositionErrorCallback_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMGeoPositionError; /* forward declaration */


/* starting interface:    nsIDOMGeoPositionErrorCallback */
#define NS_IDOMGEOPOSITIONERRORCALLBACK_IID_STR "7d9b09d9-4843-43eb-a7a7-67f7dda6b3c4"

#define NS_IDOMGEOPOSITIONERRORCALLBACK_IID \
  {0x7d9b09d9, 0x4843, 0x43eb, \
    { 0xa7, 0xa7, 0x67, 0xf7, 0xdd, 0xa6, 0xb3, 0xc4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMGeoPositionErrorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOPOSITIONERRORCALLBACK_IID)

  /* void handleEvent (in nsIDOMGeoPositionError positionError); */
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(nsIDOMGeoPositionError *positionError) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoPositionErrorCallback, NS_IDOMGEOPOSITIONERRORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOPOSITIONERRORCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(nsIDOMGeoPositionError *positionError); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOPOSITIONERRORCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(nsIDOMGeoPositionError *positionError) { return _to HandleEvent(positionError); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOPOSITIONERRORCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(nsIDOMGeoPositionError *positionError) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(positionError); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoPositionErrorCallback : public nsIDOMGeoPositionErrorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOPOSITIONERRORCALLBACK

  nsDOMGeoPositionErrorCallback();

private:
  ~nsDOMGeoPositionErrorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoPositionErrorCallback, nsIDOMGeoPositionErrorCallback)

nsDOMGeoPositionErrorCallback::nsDOMGeoPositionErrorCallback()
{
  /* member initializers and constructor code */
}

nsDOMGeoPositionErrorCallback::~nsDOMGeoPositionErrorCallback()
{
  /* destructor code */
}

/* void handleEvent (in nsIDOMGeoPositionError positionError); */
NS_IMETHODIMP nsDOMGeoPositionErrorCallback::HandleEvent(nsIDOMGeoPositionError *positionError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoPositionErrorCallback_h__ */
