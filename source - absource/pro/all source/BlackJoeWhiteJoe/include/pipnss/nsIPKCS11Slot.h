/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIPKCS11Slot.idl
 */

#ifndef __gen_nsIPKCS11Slot_h__
#define __gen_nsIPKCS11Slot_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPK11Token; /* forward declaration */


/* starting interface:    nsIPKCS11Slot */
#define NS_IPKCS11SLOT_IID_STR "c2d4f296-ee60-11d4-998b-00b0d02354a0"

#define NS_IPKCS11SLOT_IID \
  {0xc2d4f296, 0xee60, 0x11d4, \
    { 0x99, 0x8b, 0x00, 0xb0, 0xd0, 0x23, 0x54, 0xa0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPKCS11Slot : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPKCS11SLOT_IID)

  /* readonly attribute wstring name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName) = 0;

  /* readonly attribute wstring desc; */
  NS_SCRIPTABLE NS_IMETHOD GetDesc(PRUnichar * *aDesc) = 0;

  /* readonly attribute wstring manID; */
  NS_SCRIPTABLE NS_IMETHOD GetManID(PRUnichar * *aManID) = 0;

  /* readonly attribute wstring HWVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetHWVersion(PRUnichar * *aHWVersion) = 0;

  /* readonly attribute wstring FWVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetFWVersion(PRUnichar * *aFWVersion) = 0;

  enum { SLOT_DISABLED = 0U };

  enum { SLOT_NOT_PRESENT = 1U };

  enum { SLOT_UNINITIALIZED = 2U };

  enum { SLOT_NOT_LOGGED_IN = 3U };

  enum { SLOT_LOGGED_IN = 4U };

  enum { SLOT_READY = 5U };

  /* readonly attribute unsigned long status; */
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint32 *aStatus) = 0;

  /* nsIPK11Token getToken (); */
  NS_SCRIPTABLE NS_IMETHOD GetToken(nsIPK11Token **_retval NS_OUTPARAM) = 0;

  /* readonly attribute wstring tokenName; */
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(PRUnichar * *aTokenName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPKCS11Slot, NS_IPKCS11SLOT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPKCS11SLOT \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName); \
  NS_SCRIPTABLE NS_IMETHOD GetDesc(PRUnichar * *aDesc); \
  NS_SCRIPTABLE NS_IMETHOD GetManID(PRUnichar * *aManID); \
  NS_SCRIPTABLE NS_IMETHOD GetHWVersion(PRUnichar * *aHWVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetFWVersion(PRUnichar * *aFWVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint32 *aStatus); \
  NS_SCRIPTABLE NS_IMETHOD GetToken(nsIPK11Token **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(PRUnichar * *aTokenName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPKCS11SLOT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetDesc(PRUnichar * *aDesc) { return _to GetDesc(aDesc); } \
  NS_SCRIPTABLE NS_IMETHOD GetManID(PRUnichar * *aManID) { return _to GetManID(aManID); } \
  NS_SCRIPTABLE NS_IMETHOD GetHWVersion(PRUnichar * *aHWVersion) { return _to GetHWVersion(aHWVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetFWVersion(PRUnichar * *aFWVersion) { return _to GetFWVersion(aFWVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint32 *aStatus) { return _to GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetToken(nsIPK11Token **_retval NS_OUTPARAM) { return _to GetToken(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(PRUnichar * *aTokenName) { return _to GetTokenName(aTokenName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPKCS11SLOT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetDesc(PRUnichar * *aDesc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDesc(aDesc); } \
  NS_SCRIPTABLE NS_IMETHOD GetManID(PRUnichar * *aManID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManID(aManID); } \
  NS_SCRIPTABLE NS_IMETHOD GetHWVersion(PRUnichar * *aHWVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHWVersion(aHWVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetFWVersion(PRUnichar * *aFWVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFWVersion(aFWVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint32 *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetToken(nsIPK11Token **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetToken(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(PRUnichar * *aTokenName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenName(aTokenName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPKCS11Slot : public nsIPKCS11Slot
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPKCS11SLOT

  nsPKCS11Slot();

private:
  ~nsPKCS11Slot();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPKCS11Slot, nsIPKCS11Slot)

nsPKCS11Slot::nsPKCS11Slot()
{
  /* member initializers and constructor code */
}

nsPKCS11Slot::~nsPKCS11Slot()
{
  /* destructor code */
}

/* readonly attribute wstring name; */
NS_IMETHODIMP nsPKCS11Slot::GetName(PRUnichar * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring desc; */
NS_IMETHODIMP nsPKCS11Slot::GetDesc(PRUnichar * *aDesc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring manID; */
NS_IMETHODIMP nsPKCS11Slot::GetManID(PRUnichar * *aManID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring HWVersion; */
NS_IMETHODIMP nsPKCS11Slot::GetHWVersion(PRUnichar * *aHWVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring FWVersion; */
NS_IMETHODIMP nsPKCS11Slot::GetFWVersion(PRUnichar * *aFWVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long status; */
NS_IMETHODIMP nsPKCS11Slot::GetStatus(PRUint32 *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPK11Token getToken (); */
NS_IMETHODIMP nsPKCS11Slot::GetToken(nsIPK11Token **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenName; */
NS_IMETHODIMP nsPKCS11Slot::GetTokenName(PRUnichar * *aTokenName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPKCS11Slot_h__ */
