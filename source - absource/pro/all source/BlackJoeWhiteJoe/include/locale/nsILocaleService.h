/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/locale/idl/nsILocaleService.idl
 */

#ifndef __gen_nsILocaleService_h__
#define __gen_nsILocaleService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsILocale_h__
#include "nsILocale.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILocaleService */
#define NS_ILOCALESERVICE_IID_STR "c2edc848-4219-4440-abbf-98119882c83f"

#define NS_ILOCALESERVICE_IID \
  {0xc2edc848, 0x4219, 0x4440, \
    { 0xab, 0xbf, 0x98, 0x11, 0x98, 0x82, 0xc8, 0x3f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsILocaleService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALESERVICE_IID)

  /* nsILocale newLocale (in AString aLocale); */
  NS_SCRIPTABLE NS_IMETHOD NewLocale(const nsAString & aLocale, nsILocale **_retval NS_OUTPARAM) = 0;

  /* nsILocale getSystemLocale (); */
  NS_SCRIPTABLE NS_IMETHOD GetSystemLocale(nsILocale **_retval NS_OUTPARAM) = 0;

  /* nsILocale getApplicationLocale (); */
  NS_SCRIPTABLE NS_IMETHOD GetApplicationLocale(nsILocale **_retval NS_OUTPARAM) = 0;

  /* nsILocale getLocaleFromAcceptLanguage (in string acceptLanguage); */
  NS_SCRIPTABLE NS_IMETHOD GetLocaleFromAcceptLanguage(const char *acceptLanguage, nsILocale **_retval NS_OUTPARAM) = 0;

  /* AString getLocaleComponentForUserAgent (); */
  NS_SCRIPTABLE NS_IMETHOD GetLocaleComponentForUserAgent(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocaleService, NS_ILOCALESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALESERVICE \
  NS_SCRIPTABLE NS_IMETHOD NewLocale(const nsAString & aLocale, nsILocale **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSystemLocale(nsILocale **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationLocale(nsILocale **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLocaleFromAcceptLanguage(const char *acceptLanguage, nsILocale **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLocaleComponentForUserAgent(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewLocale(const nsAString & aLocale, nsILocale **_retval NS_OUTPARAM) { return _to NewLocale(aLocale, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemLocale(nsILocale **_retval NS_OUTPARAM) { return _to GetSystemLocale(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationLocale(nsILocale **_retval NS_OUTPARAM) { return _to GetApplicationLocale(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocaleFromAcceptLanguage(const char *acceptLanguage, nsILocale **_retval NS_OUTPARAM) { return _to GetLocaleFromAcceptLanguage(acceptLanguage, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocaleComponentForUserAgent(nsAString & _retval NS_OUTPARAM) { return _to GetLocaleComponentForUserAgent(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewLocale(const nsAString & aLocale, nsILocale **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewLocale(aLocale, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemLocale(nsILocale **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemLocale(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationLocale(nsILocale **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationLocale(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocaleFromAcceptLanguage(const char *acceptLanguage, nsILocale **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocaleFromAcceptLanguage(acceptLanguage, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocaleComponentForUserAgent(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocaleComponentForUserAgent(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocaleService : public nsILocaleService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALESERVICE

  nsLocaleService();

private:
  ~nsLocaleService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLocaleService, nsILocaleService)

nsLocaleService::nsLocaleService()
{
  /* member initializers and constructor code */
}

nsLocaleService::~nsLocaleService()
{
  /* destructor code */
}

/* nsILocale newLocale (in AString aLocale); */
NS_IMETHODIMP nsLocaleService::NewLocale(const nsAString & aLocale, nsILocale **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsILocale getSystemLocale (); */
NS_IMETHODIMP nsLocaleService::GetSystemLocale(nsILocale **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsILocale getApplicationLocale (); */
NS_IMETHODIMP nsLocaleService::GetApplicationLocale(nsILocale **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsILocale getLocaleFromAcceptLanguage (in string acceptLanguage); */
NS_IMETHODIMP nsLocaleService::GetLocaleFromAcceptLanguage(const char *acceptLanguage, nsILocale **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getLocaleComponentForUserAgent (); */
NS_IMETHODIMP nsLocaleService::GetLocaleComponentForUserAgent(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {C8E518C1-47AE-11d3-91CD-00105AA3F7DC}
#define NS_LOCALESERVICE_CID {0xc8e518c1,0x47ae,0x11d3,{0x91,0xcd,0x0,0x10,0x5a,0xa3,0xf7,0xdc}}
#define NS_LOCALESERVICE_CONTRACTID "@mozilla.org/intl/nslocaleservice;1"
extern nsresult
NS_NewLocaleService(nsILocaleService** result);

#endif /* __gen_nsILocaleService_h__ */
