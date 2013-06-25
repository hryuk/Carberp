/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/locale/idl/nsICollation.idl
 */

#ifndef __gen_nsICollation_h__
#define __gen_nsICollation_h__


#ifndef __gen_nsILocale_h__
#include "nsILocale.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICollation; /* forward declaration */


/* starting interface:    nsICollationFactory */
#define NS_ICOLLATIONFACTORY_IID_STR "04971e14-d6b3-4ada-8cbb-c3a13842b349"

#define NS_ICOLLATIONFACTORY_IID \
  {0x04971e14, 0xd6b3, 0x4ada, \
    { 0x8c, 0xbb, 0xc3, 0xa1, 0x38, 0x42, 0xb3, 0x49 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICollationFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOLLATIONFACTORY_IID)

  /* nsICollation CreateCollation (in nsILocale locale); */
  NS_SCRIPTABLE NS_IMETHOD CreateCollation(nsILocale *locale, nsICollation **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICollationFactory, NS_ICOLLATIONFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOLLATIONFACTORY \
  NS_SCRIPTABLE NS_IMETHOD CreateCollation(nsILocale *locale, nsICollation **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOLLATIONFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateCollation(nsILocale *locale, nsICollation **_retval NS_OUTPARAM) { return _to CreateCollation(locale, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOLLATIONFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateCollation(nsILocale *locale, nsICollation **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateCollation(locale, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCollationFactory : public nsICollationFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOLLATIONFACTORY

  nsCollationFactory();

private:
  ~nsCollationFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCollationFactory, nsICollationFactory)

nsCollationFactory::nsCollationFactory()
{
  /* member initializers and constructor code */
}

nsCollationFactory::~nsCollationFactory()
{
  /* destructor code */
}

/* nsICollation CreateCollation (in nsILocale locale); */
NS_IMETHODIMP nsCollationFactory::CreateCollation(nsILocale *locale, nsICollation **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICollation */
#define NS_ICOLLATION_IID_STR "b0132cc0-3786-4557-9874-910d7def5f93"

#define NS_ICOLLATION_IID \
  {0xb0132cc0, 0x3786, 0x4557, \
    { 0x98, 0x74, 0x91, 0x0d, 0x7d, 0xef, 0x5f, 0x93 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICollation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOLLATION_IID)

  enum { kCollationStrengthDefault = 0 };

  enum { kCollationCaseInsensitiveAscii = 1 };

  enum { kCollationAccentInsenstive = 2 };

  enum { kCollationCaseSensitive = 0 };

  enum { kCollationCaseInSensitive = 3 };

  /* void initialize (in nsILocale locale); */
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsILocale *locale) = 0;

  /* long compareString (in long strength, in AString string1, in AString string2); */
  NS_SCRIPTABLE NS_IMETHOD CompareString(PRInt32 strength, const nsAString & string1, const nsAString & string2, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* [noscript] void allocateRawSortKey (in long strength, in AString stringIn, [array, size_is (outLen)] out octet key, out unsigned long outLen); */
  NS_IMETHOD AllocateRawSortKey(PRInt32 strength, const nsAString & stringIn, PRUint8 **key NS_OUTPARAM, PRUint32 *outLen NS_OUTPARAM) = 0;

  /* [noscript] long compareRawSortKey ([array, size_is (len1), const] in octet key1, in unsigned long len1, [array, size_is (len2), const] in octet key2, in unsigned long len2); */
  NS_IMETHOD CompareRawSortKey(const PRUint8 *key1, PRUint32 len1, const PRUint8 *key2, PRUint32 len2, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICollation, NS_ICOLLATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOLLATION \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsILocale *locale); \
  NS_SCRIPTABLE NS_IMETHOD CompareString(PRInt32 strength, const nsAString & string1, const nsAString & string2, PRInt32 *_retval NS_OUTPARAM); \
  NS_IMETHOD AllocateRawSortKey(PRInt32 strength, const nsAString & stringIn, PRUint8 **key NS_OUTPARAM, PRUint32 *outLen NS_OUTPARAM); \
  NS_IMETHOD CompareRawSortKey(const PRUint8 *key1, PRUint32 len1, const PRUint8 *key2, PRUint32 len2, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOLLATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsILocale *locale) { return _to Initialize(locale); } \
  NS_SCRIPTABLE NS_IMETHOD CompareString(PRInt32 strength, const nsAString & string1, const nsAString & string2, PRInt32 *_retval NS_OUTPARAM) { return _to CompareString(strength, string1, string2, _retval); } \
  NS_IMETHOD AllocateRawSortKey(PRInt32 strength, const nsAString & stringIn, PRUint8 **key NS_OUTPARAM, PRUint32 *outLen NS_OUTPARAM) { return _to AllocateRawSortKey(strength, stringIn, key, outLen); } \
  NS_IMETHOD CompareRawSortKey(const PRUint8 *key1, PRUint32 len1, const PRUint8 *key2, PRUint32 len2, PRInt32 *_retval NS_OUTPARAM) { return _to CompareRawSortKey(key1, len1, key2, len2, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOLLATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Initialize(nsILocale *locale) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(locale); } \
  NS_SCRIPTABLE NS_IMETHOD CompareString(PRInt32 strength, const nsAString & string1, const nsAString & string2, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareString(strength, string1, string2, _retval); } \
  NS_IMETHOD AllocateRawSortKey(PRInt32 strength, const nsAString & stringIn, PRUint8 **key NS_OUTPARAM, PRUint32 *outLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AllocateRawSortKey(strength, stringIn, key, outLen); } \
  NS_IMETHOD CompareRawSortKey(const PRUint8 *key1, PRUint32 len1, const PRUint8 *key2, PRUint32 len2, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareRawSortKey(key1, len1, key2, len2, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCollation : public nsICollation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOLLATION

  nsCollation();

private:
  ~nsCollation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCollation, nsICollation)

nsCollation::nsCollation()
{
  /* member initializers and constructor code */
}

nsCollation::~nsCollation()
{
  /* destructor code */
}

/* void initialize (in nsILocale locale); */
NS_IMETHODIMP nsCollation::Initialize(nsILocale *locale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long compareString (in long strength, in AString string1, in AString string2); */
NS_IMETHODIMP nsCollation::CompareString(PRInt32 strength, const nsAString & string1, const nsAString & string2, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void allocateRawSortKey (in long strength, in AString stringIn, [array, size_is (outLen)] out octet key, out unsigned long outLen); */
NS_IMETHODIMP nsCollation::AllocateRawSortKey(PRInt32 strength, const nsAString & stringIn, PRUint8 **key NS_OUTPARAM, PRUint32 *outLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long compareRawSortKey ([array, size_is (len1), const] in octet key1, in unsigned long len1, [array, size_is (len2), const] in octet key2, in unsigned long len2); */
NS_IMETHODIMP nsCollation::CompareRawSortKey(const PRUint8 *key1, PRUint32 len1, const PRUint8 *key2, PRUint32 len2, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICollation_h__ */
