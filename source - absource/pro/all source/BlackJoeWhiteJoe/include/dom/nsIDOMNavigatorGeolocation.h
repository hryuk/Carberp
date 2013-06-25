/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/geolocation/nsIDOMNavigatorGeolocation.idl
 */

#ifndef __gen_nsIDOMNavigatorGeolocation_h__
#define __gen_nsIDOMNavigatorGeolocation_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMGeoGeolocation; /* forward declaration */


/* starting interface:    nsIDOMNavigatorGeolocation */
#define NS_IDOMNAVIGATORGEOLOCATION_IID_STR "9f218d6a-42ec-4b8a-aee9-e29ca96a4eae"

#define NS_IDOMNAVIGATORGEOLOCATION_IID \
  {0x9f218d6a, 0x42ec, 0x4b8a, \
    { 0xae, 0xe9, 0xe2, 0x9c, 0xa9, 0x6a, 0x4e, 0xae }}

/**
 * Property that extends the navigator object.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNavigatorGeolocation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATORGEOLOCATION_IID)

  /* readonly attribute nsIDOMGeoGeolocation geolocation; */
  NS_SCRIPTABLE NS_IMETHOD GetGeolocation(nsIDOMGeoGeolocation * *aGeolocation) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigatorGeolocation, NS_IDOMNAVIGATORGEOLOCATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATORGEOLOCATION \
  NS_SCRIPTABLE NS_IMETHOD GetGeolocation(nsIDOMGeoGeolocation * *aGeolocation); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATORGEOLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGeolocation(nsIDOMGeoGeolocation * *aGeolocation) { return _to GetGeolocation(aGeolocation); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATORGEOLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGeolocation(nsIDOMGeoGeolocation * *aGeolocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGeolocation(aGeolocation); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigatorGeolocation : public nsIDOMNavigatorGeolocation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATORGEOLOCATION

  nsDOMNavigatorGeolocation();

private:
  ~nsDOMNavigatorGeolocation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNavigatorGeolocation, nsIDOMNavigatorGeolocation)

nsDOMNavigatorGeolocation::nsDOMNavigatorGeolocation()
{
  /* member initializers and constructor code */
}

nsDOMNavigatorGeolocation::~nsDOMNavigatorGeolocation()
{
  /* destructor code */
}

/* readonly attribute nsIDOMGeoGeolocation geolocation; */
NS_IMETHODIMP nsDOMNavigatorGeolocation::GetGeolocation(nsIDOMGeoGeolocation * *aGeolocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorGeolocation_h__ */
