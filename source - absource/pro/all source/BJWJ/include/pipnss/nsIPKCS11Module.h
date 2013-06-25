/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIPKCS11Module.idl
 */

#ifndef __gen_nsIPKCS11Module_h__
#define __gen_nsIPKCS11Module_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPKCS11Slot; /* forward declaration */

class nsIEnumerator; /* forward declaration */


/* starting interface:    nsIPKCS11Module */
#define NS_IPKCS11MODULE_IID_STR "8a44bdf9-d1a5-4734-bd5a-34ed7fe564c2"

#define NS_IPKCS11MODULE_IID \
  {0x8a44bdf9, 0xd1a5, 0x4734, \
    { 0xbd, 0x5a, 0x34, 0xed, 0x7f, 0xe5, 0x64, 0xc2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPKCS11Module : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPKCS11MODULE_IID)

  /* readonly attribute wstring name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName) = 0;

  /* readonly attribute wstring libName; */
  NS_SCRIPTABLE NS_IMETHOD GetLibName(PRUnichar * *aLibName) = 0;

  /* nsIPKCS11Slot findSlotByName (in wstring name); */
  NS_SCRIPTABLE NS_IMETHOD FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM) = 0;

  /* nsIEnumerator listSlots (); */
  NS_SCRIPTABLE NS_IMETHOD ListSlots(nsIEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPKCS11Module, NS_IPKCS11MODULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPKCS11MODULE \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName); \
  NS_SCRIPTABLE NS_IMETHOD GetLibName(PRUnichar * *aLibName); \
  NS_SCRIPTABLE NS_IMETHOD FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ListSlots(nsIEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPKCS11MODULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetLibName(PRUnichar * *aLibName) { return _to GetLibName(aLibName); } \
  NS_SCRIPTABLE NS_IMETHOD FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM) { return _to FindSlotByName(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ListSlots(nsIEnumerator **_retval NS_OUTPARAM) { return _to ListSlots(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPKCS11MODULE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetLibName(PRUnichar * *aLibName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLibName(aLibName); } \
  NS_SCRIPTABLE NS_IMETHOD FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindSlotByName(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ListSlots(nsIEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ListSlots(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPKCS11Module : public nsIPKCS11Module
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPKCS11MODULE

  nsPKCS11Module();

private:
  ~nsPKCS11Module();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPKCS11Module, nsIPKCS11Module)

nsPKCS11Module::nsPKCS11Module()
{
  /* member initializers and constructor code */
}

nsPKCS11Module::~nsPKCS11Module()
{
  /* destructor code */
}

/* readonly attribute wstring name; */
NS_IMETHODIMP nsPKCS11Module::GetName(PRUnichar * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring libName; */
NS_IMETHODIMP nsPKCS11Module::GetLibName(PRUnichar * *aLibName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPKCS11Slot findSlotByName (in wstring name); */
NS_IMETHODIMP nsPKCS11Module::FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIEnumerator listSlots (); */
NS_IMETHODIMP nsPKCS11Module::ListSlots(nsIEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPKCS11Module_h__ */
