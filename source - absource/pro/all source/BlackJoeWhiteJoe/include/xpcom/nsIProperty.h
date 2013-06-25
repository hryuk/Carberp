/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIProperty.idl
 */

#ifndef __gen_nsIProperty_h__
#define __gen_nsIProperty_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIProperty */
#define NS_IPROPERTY_IID_STR "6dcf9030-a49f-11d5-910d-0010a4e73d9a"

#define NS_IPROPERTY_IID \
  {0x6dcf9030, 0xa49f, 0x11d5, \
    { 0x91, 0x0d, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIProperty : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROPERTY_IID)

  /**
     * Get the name of the property.
     */
  /* readonly attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /**
     * Get the value of the property.
     */
  /* readonly attribute nsIVariant value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsIVariant * *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProperty, NS_IPROPERTY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROPERTY \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsIVariant * *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROPERTY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsIVariant * *aValue) { return _to GetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROPERTY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsIVariant * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProperty : public nsIProperty
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROPERTY

  nsProperty();

private:
  ~nsProperty();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProperty, nsIProperty)

nsProperty::nsProperty()
{
  /* member initializers and constructor code */
}

nsProperty::~nsProperty()
{
  /* destructor code */
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsProperty::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant value; */
NS_IMETHODIMP nsProperty::GetValue(nsIVariant * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProperty_h__ */
