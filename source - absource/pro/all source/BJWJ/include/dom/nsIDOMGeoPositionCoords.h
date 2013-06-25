/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/geolocation/nsIDOMGeoPositionCoords.idl
 */

#ifndef __gen_nsIDOMGeoPositionCoords_h__
#define __gen_nsIDOMGeoPositionCoords_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGeoPositionCoords */
#define NS_IDOMGEOPOSITIONCOORDS_IID_STR "b31702d0-6dac-4fa0-b93b-f043e71c8f9a"

#define NS_IDOMGEOPOSITIONCOORDS_IID \
  {0xb31702d0, 0x6dac, 0x4fa0, \
    { 0xb9, 0x3b, 0xf0, 0x43, 0xe7, 0x1c, 0x8f, 0x9a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMGeoPositionCoords : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOPOSITIONCOORDS_IID)

  /* readonly attribute double latitude; */
  NS_SCRIPTABLE NS_IMETHOD GetLatitude(double *aLatitude) = 0;

  /* readonly attribute double longitude; */
  NS_SCRIPTABLE NS_IMETHOD GetLongitude(double *aLongitude) = 0;

  /* readonly attribute double altitude; */
  NS_SCRIPTABLE NS_IMETHOD GetAltitude(double *aAltitude) = 0;

  /* readonly attribute double accuracy; */
  NS_SCRIPTABLE NS_IMETHOD GetAccuracy(double *aAccuracy) = 0;

  /* readonly attribute double altitudeAccuracy; */
  NS_SCRIPTABLE NS_IMETHOD GetAltitudeAccuracy(double *aAltitudeAccuracy) = 0;

  /* readonly attribute double heading; */
  NS_SCRIPTABLE NS_IMETHOD GetHeading(double *aHeading) = 0;

  /* readonly attribute double speed; */
  NS_SCRIPTABLE NS_IMETHOD GetSpeed(double *aSpeed) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoPositionCoords, NS_IDOMGEOPOSITIONCOORDS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOPOSITIONCOORDS \
  NS_SCRIPTABLE NS_IMETHOD GetLatitude(double *aLatitude); \
  NS_SCRIPTABLE NS_IMETHOD GetLongitude(double *aLongitude); \
  NS_SCRIPTABLE NS_IMETHOD GetAltitude(double *aAltitude); \
  NS_SCRIPTABLE NS_IMETHOD GetAccuracy(double *aAccuracy); \
  NS_SCRIPTABLE NS_IMETHOD GetAltitudeAccuracy(double *aAltitudeAccuracy); \
  NS_SCRIPTABLE NS_IMETHOD GetHeading(double *aHeading); \
  NS_SCRIPTABLE NS_IMETHOD GetSpeed(double *aSpeed); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOPOSITIONCOORDS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLatitude(double *aLatitude) { return _to GetLatitude(aLatitude); } \
  NS_SCRIPTABLE NS_IMETHOD GetLongitude(double *aLongitude) { return _to GetLongitude(aLongitude); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltitude(double *aAltitude) { return _to GetAltitude(aAltitude); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccuracy(double *aAccuracy) { return _to GetAccuracy(aAccuracy); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltitudeAccuracy(double *aAltitudeAccuracy) { return _to GetAltitudeAccuracy(aAltitudeAccuracy); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeading(double *aHeading) { return _to GetHeading(aHeading); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpeed(double *aSpeed) { return _to GetSpeed(aSpeed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOPOSITIONCOORDS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLatitude(double *aLatitude) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLatitude(aLatitude); } \
  NS_SCRIPTABLE NS_IMETHOD GetLongitude(double *aLongitude) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLongitude(aLongitude); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltitude(double *aAltitude) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAltitude(aAltitude); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccuracy(double *aAccuracy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccuracy(aAccuracy); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltitudeAccuracy(double *aAltitudeAccuracy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAltitudeAccuracy(aAltitudeAccuracy); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeading(double *aHeading) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeading(aHeading); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpeed(double *aSpeed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpeed(aSpeed); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoPositionCoords : public nsIDOMGeoPositionCoords
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOPOSITIONCOORDS

  nsDOMGeoPositionCoords();

private:
  ~nsDOMGeoPositionCoords();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoPositionCoords, nsIDOMGeoPositionCoords)

nsDOMGeoPositionCoords::nsDOMGeoPositionCoords()
{
  /* member initializers and constructor code */
}

nsDOMGeoPositionCoords::~nsDOMGeoPositionCoords()
{
  /* destructor code */
}

/* readonly attribute double latitude; */
NS_IMETHODIMP nsDOMGeoPositionCoords::GetLatitude(double *aLatitude)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double longitude; */
NS_IMETHODIMP nsDOMGeoPositionCoords::GetLongitude(double *aLongitude)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double altitude; */
NS_IMETHODIMP nsDOMGeoPositionCoords::GetAltitude(double *aAltitude)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double accuracy; */
NS_IMETHODIMP nsDOMGeoPositionCoords::GetAccuracy(double *aAccuracy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double altitudeAccuracy; */
NS_IMETHODIMP nsDOMGeoPositionCoords::GetAltitudeAccuracy(double *aAltitudeAccuracy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double heading; */
NS_IMETHODIMP nsDOMGeoPositionCoords::GetHeading(double *aHeading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double speed; */
NS_IMETHODIMP nsDOMGeoPositionCoords::GetSpeed(double *aSpeed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoPositionCoords_h__ */
