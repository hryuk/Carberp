/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/geolocation/nsIDOMGeoGeolocation.idl
 */

#ifndef __gen_nsIDOMGeoGeolocation_h__
#define __gen_nsIDOMGeoGeolocation_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMGeoPosition; /* forward declaration */

class nsIDOMGeoPositionOptions; /* forward declaration */

class nsIDOMGeoPositionCallback; /* forward declaration */

class nsIDOMGeoPositionErrorCallback; /* forward declaration */


/* starting interface:    nsIDOMGeoGeolocation */
#define NS_IDOMGEOGEOLOCATION_IID_STR "37687daf-b85f-4e4d-8881-85a0ad24cf78"

#define NS_IDOMGEOGEOLOCATION_IID \
  {0x37687daf, 0xb85f, 0x4e4d, \
    { 0x88, 0x81, 0x85, 0xa0, 0xad, 0x24, 0xcf, 0x78 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMGeoGeolocation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOGEOLOCATION_IID)

  /* void getCurrentPosition (in nsIDOMGeoPositionCallback successCallback, [optional] in nsIDOMGeoPositionErrorCallback errorCallback, [optional] in nsIDOMGeoPositionOptions options); */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options) = 0;

  /* long watchPosition (in nsIDOMGeoPositionCallback successCallback, [optional] in nsIDOMGeoPositionErrorCallback errorCallback, [optional] in nsIDOMGeoPositionOptions options); */
  NS_SCRIPTABLE NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void clearWatch (in long watchId); */
  NS_SCRIPTABLE NS_IMETHOD ClearWatch(PRInt32 watchId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoGeolocation, NS_IDOMGEOGEOLOCATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOGEOLOCATION \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options); \
  NS_SCRIPTABLE NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ClearWatch(PRInt32 watchId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOGEOLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options) { return _to GetCurrentPosition(successCallback, errorCallback, options); } \
  NS_SCRIPTABLE NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options, PRInt32 *_retval NS_OUTPARAM) { return _to WatchPosition(successCallback, errorCallback, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearWatch(PRInt32 watchId) { return _to ClearWatch(watchId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOGEOLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentPosition(successCallback, errorCallback, options); } \
  NS_SCRIPTABLE NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WatchPosition(successCallback, errorCallback, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearWatch(PRInt32 watchId) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearWatch(watchId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoGeolocation : public nsIDOMGeoGeolocation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOGEOLOCATION

  nsDOMGeoGeolocation();

private:
  ~nsDOMGeoGeolocation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoGeolocation, nsIDOMGeoGeolocation)

nsDOMGeoGeolocation::nsDOMGeoGeolocation()
{
  /* member initializers and constructor code */
}

nsDOMGeoGeolocation::~nsDOMGeoGeolocation()
{
  /* destructor code */
}

/* void getCurrentPosition (in nsIDOMGeoPositionCallback successCallback, [optional] in nsIDOMGeoPositionErrorCallback errorCallback, [optional] in nsIDOMGeoPositionOptions options); */
NS_IMETHODIMP nsDOMGeoGeolocation::GetCurrentPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long watchPosition (in nsIDOMGeoPositionCallback successCallback, [optional] in nsIDOMGeoPositionErrorCallback errorCallback, [optional] in nsIDOMGeoPositionOptions options); */
NS_IMETHODIMP nsDOMGeoGeolocation::WatchPosition(nsIDOMGeoPositionCallback *successCallback, nsIDOMGeoPositionErrorCallback *errorCallback, nsIDOMGeoPositionOptions *options, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearWatch (in long watchId); */
NS_IMETHODIMP nsDOMGeoGeolocation::ClearWatch(PRInt32 watchId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoGeolocation_h__ */
