/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIURIFixup.idl
 */

#ifndef __gen_nsIURIFixup_h__
#define __gen_nsIURIFixup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIURIFixup */
#define NS_IURIFIXUP_IID_STR "773081ac-9f81-4bdb-9e7a-5e87b4361f09"

#define NS_IURIFIXUP_IID \
  {0x773081ac, 0x9f81, 0x4bdb, \
    { 0x9e, 0x7a, 0x5e, 0x87, 0xb4, 0x36, 0x1f, 0x09 }}

/**
 * Interface implemented by objects capable of fixing up strings into URIs
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIURIFixup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURIFIXUP_IID)

  /** No fixup flags. */
  enum { FIXUP_FLAG_NONE = 0U };

  /**
     * Allow the fixup to use a keyword lookup service to complete the URI.
     * The fixup object implementer should honour this flag and only perform
     * any lengthy keyword (or search) operation if it is set.
     */
  enum { FIXUP_FLAG_ALLOW_KEYWORD_LOOKUP = 1U };

  /**
     * Tell the fixup to make an alternate URI from the input URI, for example
     * to turn foo into www.foo.com.
     */
  enum { FIXUP_FLAGS_MAKE_ALTERNATE_URI = 2U };

  /**
     * Converts an internal URI (e.g. a wyciwyg URI) into one which we can
     * expose to the user, for example on the URL bar.
     *
     * @param  aURI       The URI to be converted
     * @return nsIURI     The converted, exposable URI
     * @throws NS_ERROR_MALFORMED_URI when the exposable portion of aURI is malformed
     * @throws NS_ERROR_UNKNOWN_PROTOCOL when we can't get a protocol handler service
     *         for the URI scheme.
     */
  /* nsIURI createExposableURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
     * Converts the specified string into a URI, first attempting
     * to correct any errors in the syntax or other vagaries. Returns
     * a wellformed URI or nsnull if it can't.
     *
     * @param aURIText    Candidate URI.
     * @param aFixupFlags Flags that govern ways the URI may be fixed up.
     */
  /* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags); */
  NS_SCRIPTABLE NS_IMETHOD CreateFixupURI(const nsACString & aURIText, PRUint32 aFixupFlags, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
     * Converts the specified keyword string into a URI.  Note that it's the
     * caller's responsibility to check whether keywords are enabled and
     * whether aKeyword is a sensible keyword.
     */
  /* nsIURI keywordToURI (in AUTF8String aKeyword); */
  NS_SCRIPTABLE NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIURI **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIFixup, NS_IURIFIXUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURIFIXUP \
  NS_SCRIPTABLE NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateFixupURI(const nsACString & aURIText, PRUint32 aFixupFlags, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIURI **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURIFIXUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM) { return _to CreateExposableURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateFixupURI(const nsACString & aURIText, PRUint32 aFixupFlags, nsIURI **_retval NS_OUTPARAM) { return _to CreateFixupURI(aURIText, aFixupFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIURI **_retval NS_OUTPARAM) { return _to KeywordToURI(aKeyword, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURIFIXUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateExposableURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateFixupURI(const nsACString & aURIText, PRUint32 aFixupFlags, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFixupURI(aURIText, aFixupFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->KeywordToURI(aKeyword, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIFixup : public nsIURIFixup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURIFIXUP

  nsURIFixup();

private:
  ~nsURIFixup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURIFixup, nsIURIFixup)

nsURIFixup::nsURIFixup()
{
  /* member initializers and constructor code */
}

nsURIFixup::~nsURIFixup()
{
  /* destructor code */
}

/* nsIURI createExposableURI (in nsIURI aURI); */
NS_IMETHODIMP nsURIFixup::CreateExposableURI(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags); */
NS_IMETHODIMP nsURIFixup::CreateFixupURI(const nsACString & aURIText, PRUint32 aFixupFlags, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI keywordToURI (in AUTF8String aKeyword); */
NS_IMETHODIMP nsURIFixup::KeywordToURI(const nsACString & aKeyword, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIFixup_h__ */
