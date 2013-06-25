/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMPkcs11.idl
 */

#ifndef __gen_nsIDOMPkcs11_h__
#define __gen_nsIDOMPkcs11_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMPkcs11 */
#define NS_IDOMPKCS11_IID_STR "9fd42950-25e7-11d4-8a7d-006008c844c3"

#define NS_IDOMPKCS11_IID \
  {0x9fd42950, 0x25e7, 0x11d4, \
    { 0x8a, 0x7d, 0x00, 0x60, 0x08, 0xc8, 0x44, 0xc3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMPkcs11 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPKCS11_IID)

  /* long deletemodule (in DOMString moduleName); */
  NS_SCRIPTABLE NS_IMETHOD Deletemodule(const nsAString & moduleName, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long addmodule (in DOMString moduleName, in DOMString libraryFullPath, in long cryptoMechanismFlags, in long cipherFlags); */
  NS_SCRIPTABLE NS_IMETHOD Addmodule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPkcs11, NS_IDOMPKCS11_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPKCS11 \
  NS_SCRIPTABLE NS_IMETHOD Deletemodule(const nsAString & moduleName, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Addmodule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPKCS11(_to) \
  NS_SCRIPTABLE NS_IMETHOD Deletemodule(const nsAString & moduleName, PRInt32 *_retval NS_OUTPARAM) { return _to Deletemodule(moduleName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Addmodule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags, PRInt32 *_retval NS_OUTPARAM) { return _to Addmodule(moduleName, libraryFullPath, cryptoMechanismFlags, cipherFlags, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPKCS11(_to) \
  NS_SCRIPTABLE NS_IMETHOD Deletemodule(const nsAString & moduleName, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Deletemodule(moduleName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Addmodule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Addmodule(moduleName, libraryFullPath, cryptoMechanismFlags, cipherFlags, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPkcs11 : public nsIDOMPkcs11
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPKCS11

  nsDOMPkcs11();

private:
  ~nsDOMPkcs11();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPkcs11, nsIDOMPkcs11)

nsDOMPkcs11::nsDOMPkcs11()
{
  /* member initializers and constructor code */
}

nsDOMPkcs11::~nsDOMPkcs11()
{
  /* destructor code */
}

/* long deletemodule (in DOMString moduleName); */
NS_IMETHODIMP nsDOMPkcs11::Deletemodule(const nsAString & moduleName, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long addmodule (in DOMString moduleName, in DOMString libraryFullPath, in long cryptoMechanismFlags, in long cipherFlags); */
NS_IMETHODIMP nsDOMPkcs11::Addmodule(const nsAString & moduleName, const nsAString & libraryFullPath, PRInt32 cryptoMechanismFlags, PRInt32 cipherFlags, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPkcs11_h__ */
