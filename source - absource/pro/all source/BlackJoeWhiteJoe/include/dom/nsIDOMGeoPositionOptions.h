/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/geolocation/nsIDOMGeoPositionOptions.idl
 */

#ifndef __gen_nsIDOMGeoPositionOptions_h__
#define __gen_nsIDOMGeoPositionOptions_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGeoPositionOptions */
#define NS_IDOMGEOPOSITIONOPTIONS_IID_STR "453b72de-ea90-4f09-ae16-c2e7ee0dddc4"

#define NS_IDOMGEOPOSITIONOPTIONS_IID \
  {0x453b72de, 0xea90, 0x4f09, \
    { 0xae, 0x16, 0xc2, 0xe7, 0xee, 0x0d, 0xdd, 0xc4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMGeoPositionOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOPOSITIONOPTIONS_IID)

  /* attribute boolean enableHighAccuracy; */
  NS_SCRIPTABLE NS_IMETHOD GetEnableHighAccuracy(PRBool *aEnableHighAccuracy) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEnableHighAccuracy(PRBool aEnableHighAccuracy) = 0;

  /* attribute long timeout; */
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRInt32 *aTimeout) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 aTimeout) = 0;

  /* attribute long maximumAge; */
  NS_SCRIPTABLE NS_IMETHOD GetMaximumAge(PRInt32 *aMaximumAge) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMaximumAge(PRInt32 aMaximumAge) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoPositionOptions, NS_IDOMGEOPOSITIONOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOPOSITIONOPTIONS \
  NS_SCRIPTABLE NS_IMETHOD GetEnableHighAccuracy(PRBool *aEnableHighAccuracy); \
  NS_SCRIPTABLE NS_IMETHOD SetEnableHighAccuracy(PRBool aEnableHighAccuracy); \
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRInt32 *aTimeout); \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 aTimeout); \
  NS_SCRIPTABLE NS_IMETHOD GetMaximumAge(PRInt32 *aMaximumAge); \
  NS_SCRIPTABLE NS_IMETHOD SetMaximumAge(PRInt32 aMaximumAge); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOPOSITIONOPTIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEnableHighAccuracy(PRBool *aEnableHighAccuracy) { return _to GetEnableHighAccuracy(aEnableHighAccuracy); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnableHighAccuracy(PRBool aEnableHighAccuracy) { return _to SetEnableHighAccuracy(aEnableHighAccuracy); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRInt32 *aTimeout) { return _to GetTimeout(aTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 aTimeout) { return _to SetTimeout(aTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaximumAge(PRInt32 *aMaximumAge) { return _to GetMaximumAge(aMaximumAge); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaximumAge(PRInt32 aMaximumAge) { return _to SetMaximumAge(aMaximumAge); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOPOSITIONOPTIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEnableHighAccuracy(PRBool *aEnableHighAccuracy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnableHighAccuracy(aEnableHighAccuracy); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnableHighAccuracy(PRBool aEnableHighAccuracy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnableHighAccuracy(aEnableHighAccuracy); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRInt32 *aTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeout(aTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 aTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeout(aTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaximumAge(PRInt32 *aMaximumAge) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaximumAge(aMaximumAge); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaximumAge(PRInt32 aMaximumAge) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaximumAge(aMaximumAge); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoPositionOptions : public nsIDOMGeoPositionOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOPOSITIONOPTIONS

  nsDOMGeoPositionOptions();

private:
  ~nsDOMGeoPositionOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoPositionOptions, nsIDOMGeoPositionOptions)

nsDOMGeoPositionOptions::nsDOMGeoPositionOptions()
{
  /* member initializers and constructor code */
}

nsDOMGeoPositionOptions::~nsDOMGeoPositionOptions()
{
  /* destructor code */
}

/* attribute boolean enableHighAccuracy; */
NS_IMETHODIMP nsDOMGeoPositionOptions::GetEnableHighAccuracy(PRBool *aEnableHighAccuracy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMGeoPositionOptions::SetEnableHighAccuracy(PRBool aEnableHighAccuracy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long timeout; */
NS_IMETHODIMP nsDOMGeoPositionOptions::GetTimeout(PRInt32 *aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMGeoPositionOptions::SetTimeout(PRInt32 aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maximumAge; */
NS_IMETHODIMP nsDOMGeoPositionOptions::GetMaximumAge(PRInt32 *aMaximumAge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMGeoPositionOptions::SetMaximumAge(PRInt32 aMaximumAge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoPositionOptions_h__ */
