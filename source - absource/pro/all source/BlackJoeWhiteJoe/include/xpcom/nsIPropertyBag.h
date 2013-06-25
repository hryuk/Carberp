/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIPropertyBag.idl
 */

#ifndef __gen_nsIPropertyBag_h__
#define __gen_nsIPropertyBag_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIPropertyBag */
#define NS_IPROPERTYBAG_IID_STR "bfcd37b0-a49f-11d5-910d-0010a4e73d9a"

#define NS_IPROPERTYBAG_IID \
  {0xbfcd37b0, 0xa49f, 0x11d5, \
    { 0x91, 0x0d, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPropertyBag : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROPERTYBAG_IID)

  /**
     * Get a nsISimpleEnumerator whose elements are nsIProperty objects.
     */
  /* readonly attribute nsISimpleEnumerator enumerator; */
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) = 0;

  /**
     * Get a property value for the given name.
     * @throws NS_ERROR_FAILURE if a property with that name doesn't
     * exist.
     */
  /* nsIVariant getProperty (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const nsAString & name, nsIVariant **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPropertyBag, NS_IPROPERTYBAG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROPERTYBAG \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator); \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const nsAString & name, nsIVariant **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROPERTYBAG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return _to GetEnumerator(aEnumerator); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const nsAString & name, nsIVariant **_retval NS_OUTPARAM) { return _to GetProperty(name, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROPERTYBAG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(aEnumerator); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const nsAString & name, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperty(name, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPropertyBag : public nsIPropertyBag
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROPERTYBAG

  nsPropertyBag();

private:
  ~nsPropertyBag();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPropertyBag, nsIPropertyBag)

nsPropertyBag::nsPropertyBag()
{
  /* member initializers and constructor code */
}

nsPropertyBag::~nsPropertyBag()
{
  /* destructor code */
}

/* readonly attribute nsISimpleEnumerator enumerator; */
NS_IMETHODIMP nsPropertyBag::GetEnumerator(nsISimpleEnumerator * *aEnumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getProperty (in AString name); */
NS_IMETHODIMP nsPropertyBag::GetProperty(const nsAString & name, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPropertyBag_h__ */
