/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleValue.idl
 */

#ifndef __gen_nsIAccessibleValue_h__
#define __gen_nsIAccessibleValue_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleValue */
#define NS_IACCESSIBLEVALUE_IID_STR "42a1e1dc-58cf-419d-bff0-ed3314c70016"

#define NS_IACCESSIBLEVALUE_IID \
  {0x42a1e1dc, 0x58cf, 0x419d, \
    { 0xbf, 0xf0, 0xed, 0x33, 0x14, 0xc7, 0x00, 0x16 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleValue : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEVALUE_IID)

  /* readonly attribute double maximumValue; */
  NS_SCRIPTABLE NS_IMETHOD GetMaximumValue(double *aMaximumValue) = 0;

  /* readonly attribute double minimumValue; */
  NS_SCRIPTABLE NS_IMETHOD GetMinimumValue(double *aMinimumValue) = 0;

  /* attribute double currentValue; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentValue(double *aCurrentValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCurrentValue(double aCurrentValue) = 0;

  /* readonly attribute double minimumIncrement; */
  NS_SCRIPTABLE NS_IMETHOD GetMinimumIncrement(double *aMinimumIncrement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleValue, NS_IACCESSIBLEVALUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEVALUE \
  NS_SCRIPTABLE NS_IMETHOD GetMaximumValue(double *aMaximumValue); \
  NS_SCRIPTABLE NS_IMETHOD GetMinimumValue(double *aMinimumValue); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentValue(double *aCurrentValue); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentValue(double aCurrentValue); \
  NS_SCRIPTABLE NS_IMETHOD GetMinimumIncrement(double *aMinimumIncrement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEVALUE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMaximumValue(double *aMaximumValue) { return _to GetMaximumValue(aMaximumValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinimumValue(double *aMinimumValue) { return _to GetMinimumValue(aMinimumValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentValue(double *aCurrentValue) { return _to GetCurrentValue(aCurrentValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentValue(double aCurrentValue) { return _to SetCurrentValue(aCurrentValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinimumIncrement(double *aMinimumIncrement) { return _to GetMinimumIncrement(aMinimumIncrement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEVALUE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMaximumValue(double *aMaximumValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaximumValue(aMaximumValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinimumValue(double *aMinimumValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinimumValue(aMinimumValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentValue(double *aCurrentValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentValue(aCurrentValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentValue(double aCurrentValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentValue(aCurrentValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinimumIncrement(double *aMinimumIncrement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinimumIncrement(aMinimumIncrement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleValue : public nsIAccessibleValue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEVALUE

  nsAccessibleValue();

private:
  ~nsAccessibleValue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleValue, nsIAccessibleValue)

nsAccessibleValue::nsAccessibleValue()
{
  /* member initializers and constructor code */
}

nsAccessibleValue::~nsAccessibleValue()
{
  /* destructor code */
}

/* readonly attribute double maximumValue; */
NS_IMETHODIMP nsAccessibleValue::GetMaximumValue(double *aMaximumValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double minimumValue; */
NS_IMETHODIMP nsAccessibleValue::GetMinimumValue(double *aMinimumValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double currentValue; */
NS_IMETHODIMP nsAccessibleValue::GetCurrentValue(double *aCurrentValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAccessibleValue::SetCurrentValue(double aCurrentValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double minimumIncrement; */
NS_IMETHODIMP nsAccessibleValue::GetMinimumIncrement(double *aMinimumIncrement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleValue_h__ */
