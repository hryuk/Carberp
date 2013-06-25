/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsISMimeCert.idl
 */

#ifndef __gen_nsISMimeCert_h__
#define __gen_nsISMimeCert_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISMimeCert */
#define NS_ISMIMECERT_IID_STR "66710f97-a4dd-49f1-a906-fe0ebc5924c0"

#define NS_ISMIMECERT_IID \
  {0x66710f97, 0xa4dd, 0x49f1, \
    { 0xa9, 0x06, 0xfe, 0x0e, 0xbc, 0x59, 0x24, 0xc0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISMimeCert : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISMIMECERT_IID)

  /* void saveSMimeProfile (); */
  NS_SCRIPTABLE NS_IMETHOD SaveSMimeProfile(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISMimeCert, NS_ISMIMECERT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISMIMECERT \
  NS_SCRIPTABLE NS_IMETHOD SaveSMimeProfile(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISMIMECERT(_to) \
  NS_SCRIPTABLE NS_IMETHOD SaveSMimeProfile(void) { return _to SaveSMimeProfile(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISMIMECERT(_to) \
  NS_SCRIPTABLE NS_IMETHOD SaveSMimeProfile(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveSMimeProfile(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSMimeCert : public nsISMimeCert
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISMIMECERT

  nsSMimeCert();

private:
  ~nsSMimeCert();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSMimeCert, nsISMimeCert)

nsSMimeCert::nsSMimeCert()
{
  /* member initializers and constructor code */
}

nsSMimeCert::~nsSMimeCert()
{
  /* destructor code */
}

/* void saveSMimeProfile (); */
NS_IMETHODIMP nsSMimeCert::SaveSMimeProfile()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISMimeCert_h__ */
