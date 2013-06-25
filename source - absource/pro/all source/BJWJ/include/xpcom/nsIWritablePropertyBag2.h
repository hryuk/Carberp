/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIWritablePropertyBag2.idl
 */

#ifndef __gen_nsIWritablePropertyBag2_h__
#define __gen_nsIWritablePropertyBag2_h__


#ifndef __gen_nsIPropertyBag2_h__
#include "nsIPropertyBag2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWritablePropertyBag2 */
#define NS_IWRITABLEPROPERTYBAG2_IID_STR "9cfd1587-360e-4957-a58f-4c2b1c5e7ed9"

#define NS_IWRITABLEPROPERTYBAG2_IID \
  {0x9cfd1587, 0x360e, 0x4957, \
    { 0xa5, 0x8f, 0x4c, 0x2b, 0x1c, 0x5e, 0x7e, 0xd9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWritablePropertyBag2 : public nsIPropertyBag2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWRITABLEPROPERTYBAG2_IID)

  /* void setPropertyAsInt32 (in AString prop, in PRInt32 value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInt32(const nsAString & prop, PRInt32 value) = 0;

  /* void setPropertyAsUint32 (in AString prop, in PRUint32 value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsUint32(const nsAString & prop, PRUint32 value) = 0;

  /* void setPropertyAsInt64 (in AString prop, in PRInt64 value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInt64(const nsAString & prop, PRInt64 value) = 0;

  /* void setPropertyAsUint64 (in AString prop, in PRUint64 value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsUint64(const nsAString & prop, PRUint64 value) = 0;

  /* void setPropertyAsDouble (in AString prop, in double value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsDouble(const nsAString & prop, double value) = 0;

  /* void setPropertyAsAString (in AString prop, in AString value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsAString(const nsAString & prop, const nsAString & value) = 0;

  /* void setPropertyAsACString (in AString prop, in ACString value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsACString(const nsAString & prop, const nsACString & value) = 0;

  /* void setPropertyAsAUTF8String (in AString prop, in AUTF8String value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsAUTF8String(const nsAString & prop, const nsACString & value) = 0;

  /* void setPropertyAsBool (in AString prop, in boolean value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsBool(const nsAString & prop, PRBool value) = 0;

  /* void setPropertyAsInterface (in AString prop, in nsISupports value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInterface(const nsAString & prop, nsISupports *value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWritablePropertyBag2, NS_IWRITABLEPROPERTYBAG2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWRITABLEPROPERTYBAG2 \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInt32(const nsAString & prop, PRInt32 value); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsUint32(const nsAString & prop, PRUint32 value); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInt64(const nsAString & prop, PRInt64 value); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsUint64(const nsAString & prop, PRUint64 value); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsDouble(const nsAString & prop, double value); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsAString(const nsAString & prop, const nsAString & value); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsACString(const nsAString & prop, const nsACString & value); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsAUTF8String(const nsAString & prop, const nsACString & value); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsBool(const nsAString & prop, PRBool value); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInterface(const nsAString & prop, nsISupports *value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWRITABLEPROPERTYBAG2(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInt32(const nsAString & prop, PRInt32 value) { return _to SetPropertyAsInt32(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsUint32(const nsAString & prop, PRUint32 value) { return _to SetPropertyAsUint32(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInt64(const nsAString & prop, PRInt64 value) { return _to SetPropertyAsInt64(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsUint64(const nsAString & prop, PRUint64 value) { return _to SetPropertyAsUint64(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsDouble(const nsAString & prop, double value) { return _to SetPropertyAsDouble(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsAString(const nsAString & prop, const nsAString & value) { return _to SetPropertyAsAString(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsACString(const nsAString & prop, const nsACString & value) { return _to SetPropertyAsACString(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsAUTF8String(const nsAString & prop, const nsACString & value) { return _to SetPropertyAsAUTF8String(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsBool(const nsAString & prop, PRBool value) { return _to SetPropertyAsBool(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInterface(const nsAString & prop, nsISupports *value) { return _to SetPropertyAsInterface(prop, value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWRITABLEPROPERTYBAG2(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInt32(const nsAString & prop, PRInt32 value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsInt32(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsUint32(const nsAString & prop, PRUint32 value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsUint32(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInt64(const nsAString & prop, PRInt64 value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsInt64(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsUint64(const nsAString & prop, PRUint64 value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsUint64(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsDouble(const nsAString & prop, double value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsDouble(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsAString(const nsAString & prop, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsAString(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsACString(const nsAString & prop, const nsACString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsACString(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsAUTF8String(const nsAString & prop, const nsACString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsAUTF8String(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsBool(const nsAString & prop, PRBool value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsBool(prop, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsInterface(const nsAString & prop, nsISupports *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsInterface(prop, value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWritablePropertyBag2 : public nsIWritablePropertyBag2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWRITABLEPROPERTYBAG2

  nsWritablePropertyBag2();

private:
  ~nsWritablePropertyBag2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWritablePropertyBag2, nsIWritablePropertyBag2)

nsWritablePropertyBag2::nsWritablePropertyBag2()
{
  /* member initializers and constructor code */
}

nsWritablePropertyBag2::~nsWritablePropertyBag2()
{
  /* destructor code */
}

/* void setPropertyAsInt32 (in AString prop, in PRInt32 value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsInt32(const nsAString & prop, PRInt32 value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsUint32 (in AString prop, in PRUint32 value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsUint32(const nsAString & prop, PRUint32 value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsInt64 (in AString prop, in PRInt64 value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsInt64(const nsAString & prop, PRInt64 value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsUint64 (in AString prop, in PRUint64 value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsUint64(const nsAString & prop, PRUint64 value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsDouble (in AString prop, in double value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsDouble(const nsAString & prop, double value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsAString (in AString prop, in AString value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsAString(const nsAString & prop, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsACString (in AString prop, in ACString value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsACString(const nsAString & prop, const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsAUTF8String (in AString prop, in AUTF8String value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsAUTF8String(const nsAString & prop, const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsBool (in AString prop, in boolean value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsBool(const nsAString & prop, PRBool value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsInterface (in AString prop, in nsISupports value); */
NS_IMETHODIMP nsWritablePropertyBag2::SetPropertyAsInterface(const nsAString & prop, nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWritablePropertyBag2_h__ */
