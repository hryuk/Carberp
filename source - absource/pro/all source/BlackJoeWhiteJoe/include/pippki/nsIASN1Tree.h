/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/pki/public/nsIASN1Tree.idl
 */

#ifndef __gen_nsIASN1Tree_h__
#define __gen_nsIASN1Tree_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsITreeView_h__
#include "nsITreeView.h"
#endif

#ifndef __gen_nsIX509Cert_h__
#include "nsIX509Cert.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIASN1Tree */
#define NS_IASN1TREE_IID_STR "c727b2f2-1dd1-11b2-95df-f63c15b4cd35"

#define NS_IASN1TREE_IID \
  {0xc727b2f2, 0x1dd1, 0x11b2, \
    { 0x95, 0xdf, 0xf6, 0x3c, 0x15, 0xb4, 0xcd, 0x35 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIASN1Tree : public nsITreeView {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASN1TREE_IID)

  /* void loadASN1Structure (in nsIASN1Object asn1Object); */
  NS_SCRIPTABLE NS_IMETHOD LoadASN1Structure(nsIASN1Object *asn1Object) = 0;

  /* AString getDisplayData (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetDisplayData(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIASN1Tree, NS_IASN1TREE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASN1TREE \
  NS_SCRIPTABLE NS_IMETHOD LoadASN1Structure(nsIASN1Object *asn1Object); \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayData(PRUint32 index, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASN1TREE(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadASN1Structure(nsIASN1Object *asn1Object) { return _to LoadASN1Structure(asn1Object); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayData(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetDisplayData(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASN1TREE(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadASN1Structure(nsIASN1Object *asn1Object) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadASN1Structure(asn1Object); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayData(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayData(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsASN1Tree : public nsIASN1Tree
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASN1TREE

  nsASN1Tree();

private:
  ~nsASN1Tree();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsASN1Tree, nsIASN1Tree)

nsASN1Tree::nsASN1Tree()
{
  /* member initializers and constructor code */
}

nsASN1Tree::~nsASN1Tree()
{
  /* destructor code */
}

/* void loadASN1Structure (in nsIASN1Object asn1Object); */
NS_IMETHODIMP nsASN1Tree::LoadASN1Structure(nsIASN1Object *asn1Object)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getDisplayData (in unsigned long index); */
NS_IMETHODIMP nsASN1Tree::GetDisplayData(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_ASN1TREE_CONTRACTID "@mozilla.org/security/nsASN1Tree;1"

#endif /* __gen_nsIASN1Tree_h__ */
