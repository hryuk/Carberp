/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIAtomService.idl
 */

#ifndef __gen_nsIAtomService_h__
#define __gen_nsIAtomService_h__


#ifndef __gen_nsIAtom_h__
#include "nsIAtom.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_ATOMSERVICE_CID \
{ /* ed3db3fc-0168-4cab-8818-98f5475a490c */ \
    0xed3db3fc,                              \
    0x0168,                                  \
    0x4cab,                                  \
    {0x88, 0x18, 0x98, 0xf5, 0x47, 0x5a, 0x49, 0x0c} }
#define NS_ATOMSERVICE_CONTRACTID "@mozilla.org/atom-service;1"
#define NS_ATOMSERVICE_CLASSNAME "Atom Service"

/* starting interface:    nsIAtomService */
#define NS_IATOMSERVICE_IID_STR "9c1f50b9-f9eb-42d4-a8cb-2c7600aeb241"

#define NS_IATOMSERVICE_IID \
  {0x9c1f50b9, 0xf9eb, 0x42d4, \
    { 0xa8, 0xcb, 0x2c, 0x76, 0x00, 0xae, 0xb2, 0x41 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAtomService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IATOMSERVICE_IID)

  /**
   * Version of NS_NewAtom that doesn't require linking against the
   * XPCOM library.  See nsIAtom.idl.
   */
  /* nsIAtom getAtom (in AString value); */
  NS_SCRIPTABLE NS_IMETHOD GetAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM) = 0;

  /**
   * Version of NS_NewPermanentAtom that doesn't require linking against
   * the XPCOM library.  See nsIAtom.idl.
   */
  /* nsIAtom getPermanentAtom (in AString value); */
  NS_SCRIPTABLE NS_IMETHOD GetPermanentAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM) = 0;

  /**
   * Get an atom with a utf8 string.
   */
  /* [noscript] nsIAtom getAtomUTF8 (in string value); */
  NS_IMETHOD GetAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM) = 0;

  /* [noscript] nsIAtom getPermanentAtomUTF8 (in string value); */
  NS_IMETHOD GetPermanentAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAtomService, NS_IATOMSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIATOMSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPermanentAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM); \
  NS_IMETHOD GetAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM); \
  NS_IMETHOD GetPermanentAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIATOMSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM) { return _to GetAtom(value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPermanentAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM) { return _to GetPermanentAtom(value, _retval); } \
  NS_IMETHOD GetAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM) { return _to GetAtomUTF8(value, _retval); } \
  NS_IMETHOD GetPermanentAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM) { return _to GetPermanentAtomUTF8(value, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIATOMSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAtom(value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPermanentAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermanentAtom(value, _retval); } \
  NS_IMETHOD GetAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAtomUTF8(value, _retval); } \
  NS_IMETHOD GetPermanentAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermanentAtomUTF8(value, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAtomService : public nsIAtomService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIATOMSERVICE

  nsAtomService();

private:
  ~nsAtomService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAtomService, nsIAtomService)

nsAtomService::nsAtomService()
{
  /* member initializers and constructor code */
}

nsAtomService::~nsAtomService()
{
  /* destructor code */
}

/* nsIAtom getAtom (in AString value); */
NS_IMETHODIMP nsAtomService::GetAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAtom getPermanentAtom (in AString value); */
NS_IMETHODIMP nsAtomService::GetPermanentAtom(const nsAString & value, nsIAtom **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIAtom getAtomUTF8 (in string value); */
NS_IMETHODIMP nsAtomService::GetAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIAtom getPermanentAtomUTF8 (in string value); */
NS_IMETHODIMP nsAtomService::GetPermanentAtomUTF8(const char *value, nsIAtom **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAtomService_h__ */
