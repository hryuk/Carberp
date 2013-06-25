/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/strres/public/nsIStringBundleOverride.idl
 */

#ifndef __gen_nsIStringBundleOverride_h__
#define __gen_nsIStringBundleOverride_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIStringBundleOverride */
#define NS_ISTRINGBUNDLEOVERRIDE_IID_STR "965eb278-5678-456b-82a7-20a0c86a803c"

#define NS_ISTRINGBUNDLEOVERRIDE_IID \
  {0x965eb278, 0x5678, 0x456b, \
    { 0x82, 0xa7, 0x20, 0xa0, 0xc8, 0x6a, 0x80, 0x3c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIStringBundleOverride : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTRINGBUNDLEOVERRIDE_IID)

  /**
   * get the override value for a particular key in a particular
   * string bundle
   */
  /* AString getStringFromName (in AUTF8String url, in ACString key); */
  NS_SCRIPTABLE NS_IMETHOD GetStringFromName(const nsACString & url, const nsACString & key, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * get all override keys for a given string bundle
   */
  /* nsISimpleEnumerator enumerateKeysInBundle (in AUTF8String url); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateKeysInBundle(const nsACString & url, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStringBundleOverride, NS_ISTRINGBUNDLEOVERRIDE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTRINGBUNDLEOVERRIDE \
  NS_SCRIPTABLE NS_IMETHOD GetStringFromName(const nsACString & url, const nsACString & key, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EnumerateKeysInBundle(const nsACString & url, nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTRINGBUNDLEOVERRIDE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStringFromName(const nsACString & url, const nsACString & key, nsAString & _retval NS_OUTPARAM) { return _to GetStringFromName(url, key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateKeysInBundle(const nsACString & url, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to EnumerateKeysInBundle(url, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTRINGBUNDLEOVERRIDE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStringFromName(const nsACString & url, const nsACString & key, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringFromName(url, key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnumerateKeysInBundle(const nsACString & url, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateKeysInBundle(url, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStringBundleOverride : public nsIStringBundleOverride
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTRINGBUNDLEOVERRIDE

  nsStringBundleOverride();

private:
  ~nsStringBundleOverride();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStringBundleOverride, nsIStringBundleOverride)

nsStringBundleOverride::nsStringBundleOverride()
{
  /* member initializers and constructor code */
}

nsStringBundleOverride::~nsStringBundleOverride()
{
  /* destructor code */
}

/* AString getStringFromName (in AUTF8String url, in ACString key); */
NS_IMETHODIMP nsStringBundleOverride::GetStringFromName(const nsACString & url, const nsACString & key, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateKeysInBundle (in AUTF8String url); */
NS_IMETHODIMP nsStringBundleOverride::EnumerateKeysInBundle(const nsACString & url, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStringBundleOverride_h__ */
