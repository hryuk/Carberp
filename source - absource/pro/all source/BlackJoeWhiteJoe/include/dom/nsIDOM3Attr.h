/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOM3Attr.idl
 */

#ifndef __gen_nsIDOM3Attr_h__
#define __gen_nsIDOM3Attr_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOM3Node_h__
#include "nsIDOM3Node.h"
#endif

#ifndef __gen_nsIDOM3TypeInfo_h__
#include "nsIDOM3TypeInfo.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOM3Attr */
#define NS_IDOM3ATTR_IID_STR "a2216ddc-1bcd-4ec2-a292-371e09a6c377"

#define NS_IDOM3ATTR_IID \
  {0xa2216ddc, 0x1bcd, 0x4ec2, \
    { 0xa2, 0x92, 0x37, 0x1e, 0x09, 0xa6, 0xc3, 0x77 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOM3Attr : public nsIDOM3Node {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOM3ATTR_IID)

  /* readonly attribute nsIDOM3TypeInfo schemaTypeInfo; */
  NS_SCRIPTABLE NS_IMETHOD GetSchemaTypeInfo(nsIDOM3TypeInfo * *aSchemaTypeInfo) = 0;

  /* readonly attribute boolean isId; */
  NS_SCRIPTABLE NS_IMETHOD GetIsId(PRBool *aIsId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOM3Attr, NS_IDOM3ATTR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOM3ATTR \
  NS_SCRIPTABLE NS_IMETHOD GetSchemaTypeInfo(nsIDOM3TypeInfo * *aSchemaTypeInfo); \
  NS_SCRIPTABLE NS_IMETHOD GetIsId(PRBool *aIsId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOM3ATTR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSchemaTypeInfo(nsIDOM3TypeInfo * *aSchemaTypeInfo) { return _to GetSchemaTypeInfo(aSchemaTypeInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsId(PRBool *aIsId) { return _to GetIsId(aIsId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOM3ATTR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSchemaTypeInfo(nsIDOM3TypeInfo * *aSchemaTypeInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSchemaTypeInfo(aSchemaTypeInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsId(PRBool *aIsId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsId(aIsId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOM3Attr : public nsIDOM3Attr
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOM3ATTR

  nsDOM3Attr();

private:
  ~nsDOM3Attr();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOM3Attr, nsIDOM3Attr)

nsDOM3Attr::nsDOM3Attr()
{
  /* member initializers and constructor code */
}

nsDOM3Attr::~nsDOM3Attr()
{
  /* destructor code */
}

/* readonly attribute nsIDOM3TypeInfo schemaTypeInfo; */
NS_IMETHODIMP nsDOM3Attr::GetSchemaTypeInfo(nsIDOM3TypeInfo * *aSchemaTypeInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isId; */
NS_IMETHODIMP nsDOM3Attr::GetIsId(PRBool *aIsId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOM3Attr_h__ */
