/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIPropertyBag2.idl
 */

#ifndef __gen_nsIPropertyBag2_h__
#define __gen_nsIPropertyBag2_h__


#ifndef __gen_nsIPropertyBag_h__
#include "nsIPropertyBag.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPropertyBag2 */
#define NS_IPROPERTYBAG2_IID_STR "625cfd1e-da1e-4417-9ee9-dbc8e0b3fd79"

#define NS_IPROPERTYBAG2_IID \
  {0x625cfd1e, 0xda1e, 0x4417, \
    { 0x9e, 0xe9, 0xdb, 0xc8, 0xe0, 0xb3, 0xfd, 0x79 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPropertyBag2 : public nsIPropertyBag {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROPERTYBAG2_IID)

  /* PRInt32 getPropertyAsInt32 (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInt32(const nsAString & prop, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* PRUint32 getPropertyAsUint32 (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsUint32(const nsAString & prop, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* PRInt64 getPropertyAsInt64 (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInt64(const nsAString & prop, PRInt64 *_retval NS_OUTPARAM) = 0;

  /* PRUint64 getPropertyAsUint64 (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsUint64(const nsAString & prop, PRUint64 *_retval NS_OUTPARAM) = 0;

  /* double getPropertyAsDouble (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsDouble(const nsAString & prop, double *_retval NS_OUTPARAM) = 0;

  /* AString getPropertyAsAString (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsAString(const nsAString & prop, nsAString & _retval NS_OUTPARAM) = 0;

  /* ACString getPropertyAsACString (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsACString(const nsAString & prop, nsACString & _retval NS_OUTPARAM) = 0;

  /* AUTF8String getPropertyAsAUTF8String (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsAUTF8String(const nsAString & prop, nsACString & _retval NS_OUTPARAM) = 0;

  /* boolean getPropertyAsBool (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsBool(const nsAString & prop, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * This method returns null if the value exists, but is null.
   */
  /* void getPropertyAsInterface (in AString prop, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInterface(const nsAString & prop, const nsIID & iid, void * *result NS_OUTPARAM) = 0;

  /**
   * This method returns null if the value does not exist,
   * or exists but is null.
   */
  /* nsIVariant get (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & prop, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
   * Check for the existence of a key.
   */
  /* PRBool hasKey (in AString prop); */
  NS_SCRIPTABLE NS_IMETHOD HasKey(const nsAString & prop, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPropertyBag2, NS_IPROPERTYBAG2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROPERTYBAG2 \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInt32(const nsAString & prop, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsUint32(const nsAString & prop, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInt64(const nsAString & prop, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsUint64(const nsAString & prop, PRUint64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsDouble(const nsAString & prop, double *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsAString(const nsAString & prop, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsACString(const nsAString & prop, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsAUTF8String(const nsAString & prop, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsBool(const nsAString & prop, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInterface(const nsAString & prop, const nsIID & iid, void * *result NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & prop, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasKey(const nsAString & prop, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROPERTYBAG2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInt32(const nsAString & prop, PRInt32 *_retval NS_OUTPARAM) { return _to GetPropertyAsInt32(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsUint32(const nsAString & prop, PRUint32 *_retval NS_OUTPARAM) { return _to GetPropertyAsUint32(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInt64(const nsAString & prop, PRInt64 *_retval NS_OUTPARAM) { return _to GetPropertyAsInt64(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsUint64(const nsAString & prop, PRUint64 *_retval NS_OUTPARAM) { return _to GetPropertyAsUint64(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsDouble(const nsAString & prop, double *_retval NS_OUTPARAM) { return _to GetPropertyAsDouble(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsAString(const nsAString & prop, nsAString & _retval NS_OUTPARAM) { return _to GetPropertyAsAString(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsACString(const nsAString & prop, nsACString & _retval NS_OUTPARAM) { return _to GetPropertyAsACString(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsAUTF8String(const nsAString & prop, nsACString & _retval NS_OUTPARAM) { return _to GetPropertyAsAUTF8String(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsBool(const nsAString & prop, PRBool *_retval NS_OUTPARAM) { return _to GetPropertyAsBool(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInterface(const nsAString & prop, const nsIID & iid, void * *result NS_OUTPARAM) { return _to GetPropertyAsInterface(prop, iid, result); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & prop, nsIVariant **_retval NS_OUTPARAM) { return _to Get(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasKey(const nsAString & prop, PRBool *_retval NS_OUTPARAM) { return _to HasKey(prop, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROPERTYBAG2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInt32(const nsAString & prop, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsInt32(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsUint32(const nsAString & prop, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsUint32(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInt64(const nsAString & prop, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsInt64(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsUint64(const nsAString & prop, PRUint64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsUint64(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsDouble(const nsAString & prop, double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsDouble(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsAString(const nsAString & prop, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsAString(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsACString(const nsAString & prop, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsACString(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsAUTF8String(const nsAString & prop, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsAUTF8String(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsBool(const nsAString & prop, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsBool(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsInterface(const nsAString & prop, const nsIID & iid, void * *result NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsInterface(prop, iid, result); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & prop, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(prop, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasKey(const nsAString & prop, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasKey(prop, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPropertyBag2 : public nsIPropertyBag2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROPERTYBAG2

  nsPropertyBag2();

private:
  ~nsPropertyBag2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPropertyBag2, nsIPropertyBag2)

nsPropertyBag2::nsPropertyBag2()
{
  /* member initializers and constructor code */
}

nsPropertyBag2::~nsPropertyBag2()
{
  /* destructor code */
}

/* PRInt32 getPropertyAsInt32 (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsInt32(const nsAString & prop, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 getPropertyAsUint32 (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsUint32(const nsAString & prop, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRInt64 getPropertyAsInt64 (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsInt64(const nsAString & prop, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint64 getPropertyAsUint64 (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsUint64(const nsAString & prop, PRUint64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double getPropertyAsDouble (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsDouble(const nsAString & prop, double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getPropertyAsAString (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsAString(const nsAString & prop, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getPropertyAsACString (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsACString(const nsAString & prop, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getPropertyAsAUTF8String (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsAUTF8String(const nsAString & prop, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getPropertyAsBool (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsBool(const nsAString & prop, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPropertyAsInterface (in AString prop, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
NS_IMETHODIMP nsPropertyBag2::GetPropertyAsInterface(const nsAString & prop, const nsIID & iid, void * *result NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant get (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::Get(const nsAString & prop, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool hasKey (in AString prop); */
NS_IMETHODIMP nsPropertyBag2::HasKey(const nsAString & prop, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPropertyBag2_h__ */
