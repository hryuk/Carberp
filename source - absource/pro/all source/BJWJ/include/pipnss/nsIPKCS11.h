/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIPKCS11.idl
 */

#ifndef __gen_nsIPKCS11_h__
#define __gen_nsIPKCS11_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPKCS11 */
#define NS_IPKCS11_IID_STR "5743f870-958e-4f02-aef2-c0afeef67f05"

#define NS_IPKCS11_IID \
  {0x5743f870, 0x958e, 0x4f02, \
    { 0xae, 0xf2, 0xc0, 0xaf, 0xee, 0xf6, 0x7f, 0x05 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPKCS11 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPKCS11_IID)

  /* void deleteModule (in AString moduleName); */
  NS_SCRIPTABLE NS_IMETHOD DeleteModule(const nsAString & moduleName) = 0;

  /* void addModule (in AString moduleName, in AString libraryFullPath, in long cryptoMechanismFlags, in long cipherFlags); */
  NS_SCRIPTABLE NS_IMETHOD AddModule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPKCS11, NS_IPKCS11_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPKCS11 \
  NS_SCRIPTABLE NS_IMETHOD DeleteModule(const nsAString & moduleName); \
  NS_SCRIPTABLE NS_IMETHOD AddModule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPKCS11(_to) \
  NS_SCRIPTABLE NS_IMETHOD DeleteModule(const nsAString & moduleName) { return _to DeleteModule(moduleName); } \
  NS_SCRIPTABLE NS_IMETHOD AddModule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags) { return _to AddModule(moduleName, libraryFullPath, cryptoMechanismFlags, cipherFlags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPKCS11(_to) \
  NS_SCRIPTABLE NS_IMETHOD DeleteModule(const nsAString & moduleName) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteModule(moduleName); } \
  NS_SCRIPTABLE NS_IMETHOD AddModule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddModule(moduleName, libraryFullPath, cryptoMechanismFlags, cipherFlags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPKCS11 : public nsIPKCS11
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPKCS11

  nsPKCS11();

private:
  ~nsPKCS11();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPKCS11, nsIPKCS11)

nsPKCS11::nsPKCS11()
{
  /* member initializers and constructor code */
}

nsPKCS11::~nsPKCS11()
{
  /* destructor code */
}

/* void deleteModule (in AString moduleName); */
NS_IMETHODIMP nsPKCS11::DeleteModule(const nsAString & moduleName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addModule (in AString moduleName, in AString libraryFullPath, in long cryptoMechanismFlags, in long cipherFlags); */
NS_IMETHODIMP nsPKCS11::AddModule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPKCS11_h__ */
