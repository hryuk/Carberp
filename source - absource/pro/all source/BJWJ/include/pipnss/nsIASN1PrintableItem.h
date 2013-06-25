/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIASN1PrintableItem.idl
 */

#ifndef __gen_nsIASN1PrintableItem_h__
#define __gen_nsIASN1PrintableItem_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIASN1Object_h__
#include "nsIASN1Object.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIASN1PrintableItem */
#define NS_IASN1PRINTABLEITEM_IID_STR "114e1142-1dd2-11b2-ac26-b6db19d9184a"

#define NS_IASN1PRINTABLEITEM_IID \
  {0x114e1142, 0x1dd2, 0x11b2, \
    { 0xac, 0x26, 0xb6, 0xdb, 0x19, 0xd9, 0x18, 0x4a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIASN1PrintableItem : public nsIASN1Object {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASN1PRINTABLEITEM_IID)

  /* [noscript] void setData (in charPtr data, in unsigned long len); */
  NS_IMETHOD SetData(char * data, PRUint32 len) = 0;

  /* [noscript] void getData (out charPtr data, out unsigned long len); */
  NS_IMETHOD GetData(char * *data NS_OUTPARAM, PRUint32 *len NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIASN1PrintableItem, NS_IASN1PRINTABLEITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASN1PRINTABLEITEM \
  NS_IMETHOD SetData(char * data, PRUint32 len); \
  NS_IMETHOD GetData(char * *data NS_OUTPARAM, PRUint32 *len NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASN1PRINTABLEITEM(_to) \
  NS_IMETHOD SetData(char * data, PRUint32 len) { return _to SetData(data, len); } \
  NS_IMETHOD GetData(char * *data NS_OUTPARAM, PRUint32 *len NS_OUTPARAM) { return _to GetData(data, len); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASN1PRINTABLEITEM(_to) \
  NS_IMETHOD SetData(char * data, PRUint32 len) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(data, len); } \
  NS_IMETHOD GetData(char * *data NS_OUTPARAM, PRUint32 *len NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(data, len); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsASN1PrintableItem : public nsIASN1PrintableItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASN1PRINTABLEITEM

  nsASN1PrintableItem();

private:
  ~nsASN1PrintableItem();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsASN1PrintableItem, nsIASN1PrintableItem)

nsASN1PrintableItem::nsASN1PrintableItem()
{
  /* member initializers and constructor code */
}

nsASN1PrintableItem::~nsASN1PrintableItem()
{
  /* destructor code */
}

/* [noscript] void setData (in charPtr data, in unsigned long len); */
NS_IMETHODIMP nsASN1PrintableItem::SetData(char * data, PRUint32 len)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getData (out charPtr data, out unsigned long len); */
NS_IMETHODIMP nsASN1PrintableItem::GetData(char * *data NS_OUTPARAM, PRUint32 *len NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIASN1PrintableItem_h__ */
