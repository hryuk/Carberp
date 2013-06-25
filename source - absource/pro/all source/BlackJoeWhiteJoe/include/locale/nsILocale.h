/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/locale/idl/nsILocale.idl
 */

#ifndef __gen_nsILocale_h__
#define __gen_nsILocale_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NSILOCALE_COLLATE "NSILOCALE_COLLATE"
#define NSILOCALE_CTYPE  "NSILOCALE_CTYPE"
#define NSILOCALE_MONETARY "NSILOCALE_MONETARY"
#define NSILOCALE_NUMERIC "NSILOCALE_NUMERIC"
#define NSILOCALE_TIME "NSILOCALE_TIME"
#define NSILOCALE_MESSAGE "NSILOCALE_MESSAGES"
#define NS_LOCALE_CONTRACTID "@mozilla.org/intl/nslocale;1"

/* starting interface:    nsILocale */
#define NS_ILOCALE_IID_STR "21035ee0-4556-11d3-91cd-00105aa3f7dc"

#define NS_ILOCALE_IID \
  {0x21035ee0, 0x4556, 0x11d3, \
    { 0x91, 0xcd, 0x00, 0x10, 0x5a, 0xa3, 0xf7, 0xdc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsILocale : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALE_IID)

  /* AString getCategory (in AString category); */
  NS_SCRIPTABLE NS_IMETHOD GetCategory(const nsAString & category, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocale, NS_ILOCALE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALE \
  NS_SCRIPTABLE NS_IMETHOD GetCategory(const nsAString & category, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCategory(const nsAString & category, nsAString & _retval NS_OUTPARAM) { return _to GetCategory(category, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCategory(const nsAString & category, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCategory(category, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocale : public nsILocale
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALE

  nsLocale();

private:
  ~nsLocale();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLocale, nsILocale)

nsLocale::nsLocale()
{
  /* member initializers and constructor code */
}

nsLocale::~nsLocale()
{
  /* destructor code */
}

/* AString getCategory (in AString category); */
NS_IMETHODIMP nsLocale::GetCategory(const nsAString & category, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILocale_h__ */
