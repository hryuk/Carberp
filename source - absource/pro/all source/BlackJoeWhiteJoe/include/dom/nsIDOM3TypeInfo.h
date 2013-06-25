/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOM3TypeInfo.idl
 */

#ifndef __gen_nsIDOM3TypeInfo_h__
#define __gen_nsIDOM3TypeInfo_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOM3TypeInfo */
#define NS_IDOM3TYPEINFO_IID_STR "2a1088c7-499a-49a7-9d3b-1970d21532ab"

#define NS_IDOM3TYPEINFO_IID \
  {0x2a1088c7, 0x499a, 0x49a7, \
    { 0x9d, 0x3b, 0x19, 0x70, 0xd2, 0x15, 0x32, 0xab }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOM3TypeInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOM3TYPEINFO_IID)

  /* readonly attribute DOMString typeName; */
  NS_SCRIPTABLE NS_IMETHOD GetTypeName(nsAString & aTypeName) = 0;

  /* readonly attribute DOMString typeNamespace; */
  NS_SCRIPTABLE NS_IMETHOD GetTypeNamespace(nsAString & aTypeNamespace) = 0;

  enum { DERIVATION_RESTRICTION = 1U };

  enum { DERIVATION_EXTENSION = 2U };

  enum { DERIVATION_UNION = 4U };

  enum { DERIVATION_LIST = 8U };

  /* boolean isDerivedFrom (in DOMString typeNamespaceArg, in DOMString typeNameArg, in unsigned long derivationMethod); */
  NS_SCRIPTABLE NS_IMETHOD IsDerivedFrom(const nsAString & typeNamespaceArg, const nsAString & typeNameArg, PRUint32 derivationMethod, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOM3TypeInfo, NS_IDOM3TYPEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOM3TYPEINFO \
  NS_SCRIPTABLE NS_IMETHOD GetTypeName(nsAString & aTypeName); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeNamespace(nsAString & aTypeNamespace); \
  NS_SCRIPTABLE NS_IMETHOD IsDerivedFrom(const nsAString & typeNamespaceArg, const nsAString & typeNameArg, PRUint32 derivationMethod, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOM3TYPEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTypeName(nsAString & aTypeName) { return _to GetTypeName(aTypeName); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeNamespace(nsAString & aTypeNamespace) { return _to GetTypeNamespace(aTypeNamespace); } \
  NS_SCRIPTABLE NS_IMETHOD IsDerivedFrom(const nsAString & typeNamespaceArg, const nsAString & typeNameArg, PRUint32 derivationMethod, PRBool *_retval NS_OUTPARAM) { return _to IsDerivedFrom(typeNamespaceArg, typeNameArg, derivationMethod, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOM3TYPEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTypeName(nsAString & aTypeName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeName(aTypeName); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeNamespace(nsAString & aTypeNamespace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeNamespace(aTypeNamespace); } \
  NS_SCRIPTABLE NS_IMETHOD IsDerivedFrom(const nsAString & typeNamespaceArg, const nsAString & typeNameArg, PRUint32 derivationMethod, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDerivedFrom(typeNamespaceArg, typeNameArg, derivationMethod, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOM3TypeInfo : public nsIDOM3TypeInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOM3TYPEINFO

  nsDOM3TypeInfo();

private:
  ~nsDOM3TypeInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOM3TypeInfo, nsIDOM3TypeInfo)

nsDOM3TypeInfo::nsDOM3TypeInfo()
{
  /* member initializers and constructor code */
}

nsDOM3TypeInfo::~nsDOM3TypeInfo()
{
  /* destructor code */
}

/* readonly attribute DOMString typeName; */
NS_IMETHODIMP nsDOM3TypeInfo::GetTypeName(nsAString & aTypeName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString typeNamespace; */
NS_IMETHODIMP nsDOM3TypeInfo::GetTypeNamespace(nsAString & aTypeNamespace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isDerivedFrom (in DOMString typeNamespaceArg, in DOMString typeNameArg, in unsigned long derivationMethod); */
NS_IMETHODIMP nsDOM3TypeInfo::IsDerivedFrom(const nsAString & typeNamespaceArg, const nsAString & typeNameArg, PRUint32 derivationMethod, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOM3TypeInfo_h__ */
