/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIPKCS11ModuleDB.idl
 */

#ifndef __gen_nsIPKCS11ModuleDB_h__
#define __gen_nsIPKCS11ModuleDB_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPKCS11Module; /* forward declaration */

class nsIPKCS11Slot; /* forward declaration */

class nsIEnumerator; /* forward declaration */

#define NS_PKCS11MODULEDB_CONTRACTID "@mozilla.org/security/pkcs11moduledb;1"

/* starting interface:    nsIPKCS11ModuleDB */
#define NS_IPKCS11MODULEDB_IID_STR "ff9fbcd7-9517-4334-b97a-ceed78909974"

#define NS_IPKCS11MODULEDB_IID \
  {0xff9fbcd7, 0x9517, 0x4334, \
    { 0xb9, 0x7a, 0xce, 0xed, 0x78, 0x90, 0x99, 0x74 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPKCS11ModuleDB : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPKCS11MODULEDB_IID)

  /* nsIPKCS11Module getInternal (); */
  NS_SCRIPTABLE NS_IMETHOD GetInternal(nsIPKCS11Module **_retval NS_OUTPARAM) = 0;

  /* nsIPKCS11Module getInternalFIPS (); */
  NS_SCRIPTABLE NS_IMETHOD GetInternalFIPS(nsIPKCS11Module **_retval NS_OUTPARAM) = 0;

  /* nsIPKCS11Module findModuleByName (in wstring name); */
  NS_SCRIPTABLE NS_IMETHOD FindModuleByName(const PRUnichar *name, nsIPKCS11Module **_retval NS_OUTPARAM) = 0;

  /* nsIPKCS11Slot findSlotByName (in wstring name); */
  NS_SCRIPTABLE NS_IMETHOD FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM) = 0;

  /* nsIEnumerator listModules (); */
  NS_SCRIPTABLE NS_IMETHOD ListModules(nsIEnumerator **_retval NS_OUTPARAM) = 0;

  /* readonly attribute boolean canToggleFIPS; */
  NS_SCRIPTABLE NS_IMETHOD GetCanToggleFIPS(PRBool *aCanToggleFIPS) = 0;

  /* void toggleFIPSMode (); */
  NS_SCRIPTABLE NS_IMETHOD ToggleFIPSMode(void) = 0;

  /* readonly attribute boolean isFIPSEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPSEnabled(PRBool *aIsFIPSEnabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPKCS11ModuleDB, NS_IPKCS11MODULEDB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPKCS11MODULEDB \
  NS_SCRIPTABLE NS_IMETHOD GetInternal(nsIPKCS11Module **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInternalFIPS(nsIPKCS11Module **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindModuleByName(const PRUnichar *name, nsIPKCS11Module **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ListModules(nsIEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCanToggleFIPS(PRBool *aCanToggleFIPS); \
  NS_SCRIPTABLE NS_IMETHOD ToggleFIPSMode(void); \
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPSEnabled(PRBool *aIsFIPSEnabled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPKCS11MODULEDB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInternal(nsIPKCS11Module **_retval NS_OUTPARAM) { return _to GetInternal(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInternalFIPS(nsIPKCS11Module **_retval NS_OUTPARAM) { return _to GetInternalFIPS(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindModuleByName(const PRUnichar *name, nsIPKCS11Module **_retval NS_OUTPARAM) { return _to FindModuleByName(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM) { return _to FindSlotByName(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ListModules(nsIEnumerator **_retval NS_OUTPARAM) { return _to ListModules(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanToggleFIPS(PRBool *aCanToggleFIPS) { return _to GetCanToggleFIPS(aCanToggleFIPS); } \
  NS_SCRIPTABLE NS_IMETHOD ToggleFIPSMode(void) { return _to ToggleFIPSMode(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPSEnabled(PRBool *aIsFIPSEnabled) { return _to GetIsFIPSEnabled(aIsFIPSEnabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPKCS11MODULEDB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInternal(nsIPKCS11Module **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternal(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInternalFIPS(nsIPKCS11Module **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalFIPS(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindModuleByName(const PRUnichar *name, nsIPKCS11Module **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindModuleByName(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindSlotByName(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ListModules(nsIEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ListModules(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanToggleFIPS(PRBool *aCanToggleFIPS) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanToggleFIPS(aCanToggleFIPS); } \
  NS_SCRIPTABLE NS_IMETHOD ToggleFIPSMode(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToggleFIPSMode(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsFIPSEnabled(PRBool *aIsFIPSEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFIPSEnabled(aIsFIPSEnabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPKCS11ModuleDB : public nsIPKCS11ModuleDB
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPKCS11MODULEDB

  nsPKCS11ModuleDB();

private:
  ~nsPKCS11ModuleDB();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPKCS11ModuleDB, nsIPKCS11ModuleDB)

nsPKCS11ModuleDB::nsPKCS11ModuleDB()
{
  /* member initializers and constructor code */
}

nsPKCS11ModuleDB::~nsPKCS11ModuleDB()
{
  /* destructor code */
}

/* nsIPKCS11Module getInternal (); */
NS_IMETHODIMP nsPKCS11ModuleDB::GetInternal(nsIPKCS11Module **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPKCS11Module getInternalFIPS (); */
NS_IMETHODIMP nsPKCS11ModuleDB::GetInternalFIPS(nsIPKCS11Module **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPKCS11Module findModuleByName (in wstring name); */
NS_IMETHODIMP nsPKCS11ModuleDB::FindModuleByName(const PRUnichar *name, nsIPKCS11Module **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPKCS11Slot findSlotByName (in wstring name); */
NS_IMETHODIMP nsPKCS11ModuleDB::FindSlotByName(const PRUnichar *name, nsIPKCS11Slot **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIEnumerator listModules (); */
NS_IMETHODIMP nsPKCS11ModuleDB::ListModules(nsIEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canToggleFIPS; */
NS_IMETHODIMP nsPKCS11ModuleDB::GetCanToggleFIPS(PRBool *aCanToggleFIPS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void toggleFIPSMode (); */
NS_IMETHODIMP nsPKCS11ModuleDB::ToggleFIPSMode()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isFIPSEnabled; */
NS_IMETHODIMP nsPKCS11ModuleDB::GetIsFIPSEnabled(PRBool *aIsFIPSEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPKCS11ModuleDB_h__ */
