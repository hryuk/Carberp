/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/geolocation/nsIDOMGeoPosition.idl
 */

#ifndef __gen_nsIDOMGeoPosition_h__
#define __gen_nsIDOMGeoPosition_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMGeoPositionCoords_h__
#include "nsIDOMGeoPositionCoords.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGeoPosition */
#define NS_IDOMGEOPOSITION_IID_STR "76888eb0-5eab-4be6-bfe0-489ec4095358"

#define NS_IDOMGEOPOSITION_IID \
  {0x76888eb0, 0x5eab, 0x4be6, \
    { 0xbf, 0xe0, 0x48, 0x9e, 0xc4, 0x09, 0x53, 0x58 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMGeoPosition : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOPOSITION_IID)

  /* readonly attribute nsIDOMGeoPositionCoords coords; */
  NS_SCRIPTABLE NS_IMETHOD GetCoords(nsIDOMGeoPositionCoords * *aCoords) = 0;

  /* readonly attribute DOMTimeStamp timestamp; */
  NS_SCRIPTABLE NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoPosition, NS_IDOMGEOPOSITION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOPOSITION \
  NS_SCRIPTABLE NS_IMETHOD GetCoords(nsIDOMGeoPositionCoords * *aCoords); \
  NS_SCRIPTABLE NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOPOSITION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCoords(nsIDOMGeoPositionCoords * *aCoords) { return _to GetCoords(aCoords); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) { return _to GetTimestamp(aTimestamp); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOPOSITION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCoords(nsIDOMGeoPositionCoords * *aCoords) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoords(aCoords); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimestamp(aTimestamp); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoPosition : public nsIDOMGeoPosition
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOPOSITION

  nsDOMGeoPosition();

private:
  ~nsDOMGeoPosition();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoPosition, nsIDOMGeoPosition)

nsDOMGeoPosition::nsDOMGeoPosition()
{
  /* member initializers and constructor code */
}

nsDOMGeoPosition::~nsDOMGeoPosition()
{
  /* destructor code */
}

/* readonly attribute nsIDOMGeoPositionCoords coords; */
NS_IMETHODIMP nsDOMGeoPosition::GetCoords(nsIDOMGeoPositionCoords * *aCoords)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMTimeStamp timestamp; */
NS_IMETHODIMP nsDOMGeoPosition::GetTimestamp(DOMTimeStamp *aTimestamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoPosition_h__ */
