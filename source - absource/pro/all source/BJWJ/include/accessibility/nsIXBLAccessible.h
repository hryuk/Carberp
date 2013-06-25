/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIXBLAccessible.idl
 */

#ifndef __gen_nsIXBLAccessible_h__
#define __gen_nsIXBLAccessible_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXBLAccessible */
#define NS_IXBLACCESSIBLE_IID_STR "3716eb86-166b-445b-a94a-9b522fee96e6"

#define NS_IXBLACCESSIBLE_IID \
  {0x3716eb86, 0x166b, 0x445b, \
    { 0xa9, 0x4a, 0x9b, 0x52, 0x2f, 0xee, 0x96, 0xe6 }}

/**
 * XBL controls can implement this interface to provide own implementation of
 * accessible properties.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXBLAccessible : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXBLACCESSIBLE_IID)

  /**
   * Return accessible name.
   */
  /* readonly attribute DOMString accessibleName; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleName(nsAString & aAccessibleName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXBLAccessible, NS_IXBLACCESSIBLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXBLACCESSIBLE \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleName(nsAString & aAccessibleName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXBLACCESSIBLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleName(nsAString & aAccessibleName) { return _to GetAccessibleName(aAccessibleName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXBLACCESSIBLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleName(nsAString & aAccessibleName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleName(aAccessibleName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXBLAccessible : public nsIXBLAccessible
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXBLACCESSIBLE

  nsXBLAccessible();

private:
  ~nsXBLAccessible();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXBLAccessible, nsIXBLAccessible)

nsXBLAccessible::nsXBLAccessible()
{
  /* member initializers and constructor code */
}

nsXBLAccessible::~nsXBLAccessible()
{
  /* destructor code */
}

/* readonly attribute DOMString accessibleName; */
NS_IMETHODIMP nsXBLAccessible::GetAccessibleName(nsAString & aAccessibleName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXBLAccessible_h__ */
