/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIWritablePropertyBag.idl
 */

#ifndef __gen_nsIWritablePropertyBag_h__
#define __gen_nsIWritablePropertyBag_h__


#ifndef __gen_nsIPropertyBag_h__
#include "nsIPropertyBag.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWritablePropertyBag */
#define NS_IWRITABLEPROPERTYBAG_IID_STR "96fc4671-eeb4-4823-9421-e50fb70ad353"

#define NS_IWRITABLEPROPERTYBAG_IID \
  {0x96fc4671, 0xeeb4, 0x4823, \
    { 0x94, 0x21, 0xe5, 0x0f, 0xb7, 0x0a, 0xd3, 0x53 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWritablePropertyBag : public nsIPropertyBag {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWRITABLEPROPERTYBAG_IID)

  /**
     * Set a property with the given name to the given value.  If
     * a property already exists with the given name, it is
     * overwritten.
     */
  /* void setProperty (in AString name, in nsIVariant value); */
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const nsAString & name, nsIVariant *value) = 0;

  /**
     * Delete a property with the given name.
     * @throws NS_ERROR_FAILURE if a property with that name doesn't
     * exist.
     */
  /* void deleteProperty (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD DeleteProperty(const nsAString & name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWritablePropertyBag, NS_IWRITABLEPROPERTYBAG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWRITABLEPROPERTYBAG \
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const nsAString & name, nsIVariant *value); \
  NS_SCRIPTABLE NS_IMETHOD DeleteProperty(const nsAString & name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWRITABLEPROPERTYBAG(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const nsAString & name, nsIVariant *value) { return _to SetProperty(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteProperty(const nsAString & name) { return _to DeleteProperty(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWRITABLEPROPERTYBAG(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const nsAString & name, nsIVariant *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProperty(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteProperty(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteProperty(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWritablePropertyBag : public nsIWritablePropertyBag
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWRITABLEPROPERTYBAG

  nsWritablePropertyBag();

private:
  ~nsWritablePropertyBag();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWritablePropertyBag, nsIWritablePropertyBag)

nsWritablePropertyBag::nsWritablePropertyBag()
{
  /* member initializers and constructor code */
}

nsWritablePropertyBag::~nsWritablePropertyBag()
{
  /* destructor code */
}

/* void setProperty (in AString name, in nsIVariant value); */
NS_IMETHODIMP nsWritablePropertyBag::SetProperty(const nsAString & name, nsIVariant *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteProperty (in AString name); */
NS_IMETHODIMP nsWritablePropertyBag::DeleteProperty(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWritablePropertyBag_h__ */
