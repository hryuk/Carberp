/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/strres/public/nsIStringBundle.idl
 */

#ifndef __gen_nsIStringBundle_h__
#define __gen_nsIStringBundle_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// Define Contractid and CID
// {D85A17C1-AA7C-11d2-9B8C-00805F8A16D9}
#define NS_STRINGBUNDLESERVICE_CID \
{ 0xd85a17c1, 0xaa7c, 0x11d2, \
  { 0x9b, 0x8c, 0x0, 0x80, 0x5f, 0x8a, 0x16, 0xd9 } }
#define NS_STRINGBUNDLE_CONTRACTID "@mozilla.org/intl/stringbundle;1"
/** 
 * observer needs to check if the bundle handle matches
 */
#define NS_STRBUNDLE_LOADED_TOPIC "strbundle-loaded"

/* starting interface:    nsIStringBundle */
#define NS_ISTRINGBUNDLE_IID_STR "d85a17c2-aa7c-11d2-9b8c-00805f8a16d9"

#define NS_ISTRINGBUNDLE_IID \
  {0xd85a17c2, 0xaa7c, 0x11d2, \
    { 0x9b, 0x8c, 0x00, 0x80, 0x5f, 0x8a, 0x16, 0xd9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIStringBundle : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTRINGBUNDLE_IID)

  /* wstring GetStringFromID (in long aID); */
  NS_SCRIPTABLE NS_IMETHOD GetStringFromID(PRInt32 aID, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* wstring GetStringFromName (in wstring aName); */
  NS_SCRIPTABLE NS_IMETHOD GetStringFromName(const PRUnichar *aName, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* wstring formatStringFromID (in long aID, [array, size_is (length)] in wstring params, in unsigned long length); */
  NS_SCRIPTABLE NS_IMETHOD FormatStringFromID(PRInt32 aID, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* wstring formatStringFromName (in wstring aName, [array, size_is (length)] in wstring params, in unsigned long length); */
  NS_SCRIPTABLE NS_IMETHOD FormatStringFromName(const PRUnichar *aName, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* nsISimpleEnumerator getSimpleEnumeration (); */
  NS_SCRIPTABLE NS_IMETHOD GetSimpleEnumeration(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStringBundle, NS_ISTRINGBUNDLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTRINGBUNDLE \
  NS_SCRIPTABLE NS_IMETHOD GetStringFromID(PRInt32 aID, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringFromName(const PRUnichar *aName, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FormatStringFromID(PRInt32 aID, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FormatStringFromName(const PRUnichar *aName, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSimpleEnumeration(nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTRINGBUNDLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStringFromID(PRInt32 aID, PRUnichar **_retval NS_OUTPARAM) { return _to GetStringFromID(aID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringFromName(const PRUnichar *aName, PRUnichar **_retval NS_OUTPARAM) { return _to GetStringFromName(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatStringFromID(PRInt32 aID, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM) { return _to FormatStringFromID(aID, params, length, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatStringFromName(const PRUnichar *aName, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM) { return _to FormatStringFromName(aName, params, length, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSimpleEnumeration(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetSimpleEnumeration(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTRINGBUNDLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStringFromID(PRInt32 aID, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringFromID(aID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringFromName(const PRUnichar *aName, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringFromName(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatStringFromID(PRInt32 aID, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FormatStringFromID(aID, params, length, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatStringFromName(const PRUnichar *aName, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FormatStringFromName(aName, params, length, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSimpleEnumeration(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSimpleEnumeration(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStringBundle : public nsIStringBundle
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTRINGBUNDLE

  nsStringBundle();

private:
  ~nsStringBundle();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStringBundle, nsIStringBundle)

nsStringBundle::nsStringBundle()
{
  /* member initializers and constructor code */
}

nsStringBundle::~nsStringBundle()
{
  /* destructor code */
}

/* wstring GetStringFromID (in long aID); */
NS_IMETHODIMP nsStringBundle::GetStringFromID(PRInt32 aID, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring GetStringFromName (in wstring aName); */
NS_IMETHODIMP nsStringBundle::GetStringFromName(const PRUnichar *aName, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring formatStringFromID (in long aID, [array, size_is (length)] in wstring params, in unsigned long length); */
NS_IMETHODIMP nsStringBundle::FormatStringFromID(PRInt32 aID, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring formatStringFromName (in wstring aName, [array, size_is (length)] in wstring params, in unsigned long length); */
NS_IMETHODIMP nsStringBundle::FormatStringFromName(const PRUnichar *aName, const PRUnichar **params, PRUint32 length, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getSimpleEnumeration (); */
NS_IMETHODIMP nsStringBundle::GetSimpleEnumeration(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStringBundleService */
#define NS_ISTRINGBUNDLESERVICE_IID_STR "d85a17c0-aa7c-11d2-9b8c-00805f8a16d9"

#define NS_ISTRINGBUNDLESERVICE_IID \
  {0xd85a17c0, 0xaa7c, 0x11d2, \
    { 0x9b, 0x8c, 0x00, 0x80, 0x5f, 0x8a, 0x16, 0xd9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIStringBundleService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTRINGBUNDLESERVICE_IID)

  /* nsIStringBundle createBundle (in string aURLSpec); */
  NS_SCRIPTABLE NS_IMETHOD CreateBundle(const char *aURLSpec, nsIStringBundle **_retval NS_OUTPARAM) = 0;

  /* nsIStringBundle createExtensibleBundle (in string aRegistryKey); */
  NS_SCRIPTABLE NS_IMETHOD CreateExtensibleBundle(const char *aRegistryKey, nsIStringBundle **_retval NS_OUTPARAM) = 0;

  /**
   * Formats a message string from a status code and status arguments.
   * @param aStatus - The status code. This is mapped into a string ID and
   *            and used in the string lookup process (see nsIErrorService).
   * @param aStatusArg - The status message argument(s). Multiple arguments
   *            can be separated by newline ('\n') characters.
   * @return the formatted message
   */
  /* wstring formatStatusMessage (in nsresult aStatus, in wstring aStatusArg); */
  NS_SCRIPTABLE NS_IMETHOD FormatStatusMessage(nsresult aStatus, const PRUnichar *aStatusArg, PRUnichar **_retval NS_OUTPARAM) = 0;

  /**
   * flushes the string bundle cache - useful when the locale changes or
   * when we need to get some extra memory back
   * 
   * at some point, we might want to make this flush all the bundles,
   * because any bundles that are floating around when the locale changes
   * will suddenly contain bad data
   *
   */
  /* void flushBundles (); */
  NS_SCRIPTABLE NS_IMETHOD FlushBundles(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStringBundleService, NS_ISTRINGBUNDLESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTRINGBUNDLESERVICE \
  NS_SCRIPTABLE NS_IMETHOD CreateBundle(const char *aURLSpec, nsIStringBundle **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateExtensibleBundle(const char *aRegistryKey, nsIStringBundle **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FormatStatusMessage(nsresult aStatus, const PRUnichar *aStatusArg, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FlushBundles(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTRINGBUNDLESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateBundle(const char *aURLSpec, nsIStringBundle **_retval NS_OUTPARAM) { return _to CreateBundle(aURLSpec, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateExtensibleBundle(const char *aRegistryKey, nsIStringBundle **_retval NS_OUTPARAM) { return _to CreateExtensibleBundle(aRegistryKey, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatStatusMessage(nsresult aStatus, const PRUnichar *aStatusArg, PRUnichar **_retval NS_OUTPARAM) { return _to FormatStatusMessage(aStatus, aStatusArg, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FlushBundles(void) { return _to FlushBundles(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTRINGBUNDLESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateBundle(const char *aURLSpec, nsIStringBundle **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateBundle(aURLSpec, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateExtensibleBundle(const char *aRegistryKey, nsIStringBundle **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateExtensibleBundle(aRegistryKey, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatStatusMessage(nsresult aStatus, const PRUnichar *aStatusArg, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FormatStatusMessage(aStatus, aStatusArg, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FlushBundles(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlushBundles(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStringBundleService : public nsIStringBundleService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTRINGBUNDLESERVICE

  nsStringBundleService();

private:
  ~nsStringBundleService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStringBundleService, nsIStringBundleService)

nsStringBundleService::nsStringBundleService()
{
  /* member initializers and constructor code */
}

nsStringBundleService::~nsStringBundleService()
{
  /* destructor code */
}

/* nsIStringBundle createBundle (in string aURLSpec); */
NS_IMETHODIMP nsStringBundleService::CreateBundle(const char *aURLSpec, nsIStringBundle **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStringBundle createExtensibleBundle (in string aRegistryKey); */
NS_IMETHODIMP nsStringBundleService::CreateExtensibleBundle(const char *aRegistryKey, nsIStringBundle **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring formatStatusMessage (in nsresult aStatus, in wstring aStatusArg); */
NS_IMETHODIMP nsStringBundleService::FormatStatusMessage(nsresult aStatus, const PRUnichar *aStatusArg, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flushBundles (); */
NS_IMETHODIMP nsStringBundleService::FlushBundles()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStringBundle_h__ */
