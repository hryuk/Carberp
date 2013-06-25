/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIStandardURL.idl
 */

#ifndef __gen_nsIStandardURL_h__
#define __gen_nsIStandardURL_h__


#ifndef __gen_nsIMutable_h__
#include "nsIMutable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIStandardURL */
#define NS_ISTANDARDURL_IID_STR "babd6cca-ebe7-4329-967c-d6b9e33caa81"

#define NS_ISTANDARDURL_IID \
  {0xbabd6cca, 0xebe7, 0x4329, \
    { 0x96, 0x7c, 0xd6, 0xb9, 0xe3, 0x3c, 0xaa, 0x81 }}

/**
 * nsIStandardURL defines the interface to an URL with the standard
 * file path format common to protocols like http, ftp, and file.
 * It supports initialization from a relative path and provides
 * some customization on how URLs are normalized.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIStandardURL : public nsIMutable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTANDARDURL_IID)

  /**
     * blah:foo/bar    => blah://foo/bar
     * blah:/foo/bar   => blah:///foo/bar
     * blah://foo/bar  => blah://foo/bar
     * blah:///foo/bar => blah:///foo/bar
     */
  enum { URLTYPE_STANDARD = 1U };

  /**
     * blah:foo/bar    => blah://foo/bar
     * blah:/foo/bar   => blah://foo/bar
     * blah://foo/bar  => blah://foo/bar
     * blah:///foo/bar => blah://foo/bar
     */
  enum { URLTYPE_AUTHORITY = 2U };

  /**
     * blah:foo/bar    => blah:///foo/bar
     * blah:/foo/bar   => blah:///foo/bar
     * blah://foo/bar  => blah://foo/bar
     * blah:///foo/bar => blah:///foo/bar
     */
  enum { URLTYPE_NO_AUTHORITY = 3U };

  /**
     * Initialize a standard URL.
     *
     * @param aUrlType       - one of the URLTYPE_ flags listed above.
     * @param aDefaultPort   - if the port parsed from the URL string matches
     *                         this port, then the port will be removed from the
     *                         canonical form of the URL.
     * @param aSpec          - URL string.
     * @param aOriginCharset - the charset from which this URI string
     *                         originated.  this corresponds to the charset
     *                         that should be used when communicating this
     *                         URI to an origin server, for example.  if
     *                         null, then provide aBaseURI implements this
     *                         interface, the origin charset of aBaseURI will
     *                         be assumed, otherwise defaulting to UTF-8 (i.e.,
     *                         no charset transformation from aSpec).
     * @param aBaseURI       - if null, aSpec must specify an absolute URI.
     *                         otherwise, aSpec will be resolved relative
     *                         to aBaseURI.
     */
  /* void init (in unsigned long aUrlType, in long aDefaultPort, in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aUrlType, PRInt32 aDefaultPort, const nsACString & aSpec, const char *aOriginCharset, nsIURI *aBaseURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStandardURL, NS_ISTANDARDURL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTANDARDURL \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aUrlType, PRInt32 aDefaultPort, const nsACString & aSpec, const char *aOriginCharset, nsIURI *aBaseURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTANDARDURL(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aUrlType, PRInt32 aDefaultPort, const nsACString & aSpec, const char *aOriginCharset, nsIURI *aBaseURI) { return _to Init(aUrlType, aDefaultPort, aSpec, aOriginCharset, aBaseURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTANDARDURL(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aUrlType, PRInt32 aDefaultPort, const nsACString & aSpec, const char *aOriginCharset, nsIURI *aBaseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aUrlType, aDefaultPort, aSpec, aOriginCharset, aBaseURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStandardURL : public nsIStandardURL
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTANDARDURL

  nsStandardURL();

private:
  ~nsStandardURL();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStandardURL, nsIStandardURL)

nsStandardURL::nsStandardURL()
{
  /* member initializers and constructor code */
}

nsStandardURL::~nsStandardURL()
{
  /* destructor code */
}

/* void init (in unsigned long aUrlType, in long aDefaultPort, in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
NS_IMETHODIMP nsStandardURL::Init(PRUint32 aUrlType, PRInt32 aDefaultPort, const nsACString & aSpec, const char *aOriginCharset, nsIURI *aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStandardURL_h__ */
