/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/dns/public/nsIIDNService.idl
 */

#ifndef __gen_nsIIDNService_h__
#define __gen_nsIIDNService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIDNService */
#define NS_IIDNSERVICE_IID_STR "a592a60e-3621-4f19-a318-2bf233cfad3e"

#define NS_IIDNSERVICE_IID \
  {0xa592a60e, 0x3621, 0x4f19, \
    { 0xa3, 0x18, 0x2b, 0xf2, 0x33, 0xcf, 0xad, 0x3e }}

/**
 * nsIIDNService interface.
 *
 * IDN (Internationalized Domain Name) support. Provides facilities
 * for manipulating IDN hostnames according to the specification set
 * forth by the IETF.
 *
 * IDN effort:
 * http://www.ietf.org/html.characters/idn-charter.html
 * http://www.i-dns.net
 *
 * IDNA specification:
 * http://search.ietf.org/internet-drafts/draft-ietf-idn-idna-06.txt
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIDNService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDNSERVICE_IID)

  /**
     * Prepares the input hostname according to IDNA ToASCII operation,
     * the input hostname is assumed to be UTF8-encoded.
     */
  /* ACString convertUTF8toACE (in AUTF8String input); */
  NS_SCRIPTABLE NS_IMETHOD ConvertUTF8toACE(const nsACString & input, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * This is the ToUnicode operation as specified in the IDNA proposal,
     * with an additional step to encode the result in UTF-8.
     * It takes an ACE-encoded hostname and performs ToUnicode to it, then
     * encodes the resulting string into UTF8.
     */
  /* AUTF8String convertACEtoUTF8 (in ACString input); */
  NS_SCRIPTABLE NS_IMETHOD ConvertACEtoUTF8(const nsACString & input, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Checks if the input string is ACE encoded or not.
     */
  /* boolean isACE (in ACString input); */
  NS_SCRIPTABLE NS_IMETHOD IsACE(const nsACString & input, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Performs the unicode normalization needed for hostnames in IDN,
     * for callers that want early normalization.
     */
  /* AUTF8String normalize (in AUTF8String input); */
  NS_SCRIPTABLE NS_IMETHOD Normalize(const nsACString & input, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Normalizes and converts a host to UTF-8 if the host is in the IDN
     * whitelist, otherwise converts it to ACE. This is useful for display
     * purposes and to ensure an encoding consistent with nsIURI::GetHost().
     * If the result is ASCII or ACE encoded, |isASCII| will be true.
     */
  /* AUTF8String convertToDisplayIDN (in AUTF8String input, out boolean isASCII); */
  NS_SCRIPTABLE NS_IMETHOD ConvertToDisplayIDN(const nsACString & input, PRBool *isASCII NS_OUTPARAM, nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDNService, NS_IIDNSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDNSERVICE \
  NS_SCRIPTABLE NS_IMETHOD ConvertUTF8toACE(const nsACString & input, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ConvertACEtoUTF8(const nsACString & input, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsACE(const nsACString & input, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Normalize(const nsACString & input, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ConvertToDisplayIDN(const nsACString & input, PRBool *isASCII NS_OUTPARAM, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDNSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertUTF8toACE(const nsACString & input, nsACString & _retval NS_OUTPARAM) { return _to ConvertUTF8toACE(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertACEtoUTF8(const nsACString & input, nsACString & _retval NS_OUTPARAM) { return _to ConvertACEtoUTF8(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsACE(const nsACString & input, PRBool *_retval NS_OUTPARAM) { return _to IsACE(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Normalize(const nsACString & input, nsACString & _retval NS_OUTPARAM) { return _to Normalize(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToDisplayIDN(const nsACString & input, PRBool *isASCII NS_OUTPARAM, nsACString & _retval NS_OUTPARAM) { return _to ConvertToDisplayIDN(input, isASCII, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDNSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertUTF8toACE(const nsACString & input, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertUTF8toACE(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertACEtoUTF8(const nsACString & input, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertACEtoUTF8(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsACE(const nsACString & input, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsACE(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Normalize(const nsACString & input, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Normalize(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToDisplayIDN(const nsACString & input, PRBool *isASCII NS_OUTPARAM, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToDisplayIDN(input, isASCII, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDNService : public nsIIDNService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDNSERVICE

  nsIDNService();

private:
  ~nsIDNService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDNService, nsIIDNService)

nsIDNService::nsIDNService()
{
  /* member initializers and constructor code */
}

nsIDNService::~nsIDNService()
{
  /* destructor code */
}

/* ACString convertUTF8toACE (in AUTF8String input); */
NS_IMETHODIMP nsIDNService::ConvertUTF8toACE(const nsACString & input, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String convertACEtoUTF8 (in ACString input); */
NS_IMETHODIMP nsIDNService::ConvertACEtoUTF8(const nsACString & input, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isACE (in ACString input); */
NS_IMETHODIMP nsIDNService::IsACE(const nsACString & input, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String normalize (in AUTF8String input); */
NS_IMETHODIMP nsIDNService::Normalize(const nsACString & input, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String convertToDisplayIDN (in AUTF8String input, out boolean isASCII); */
NS_IMETHODIMP nsIDNService::ConvertToDisplayIDN(const nsACString & input, PRBool *isASCII NS_OUTPARAM, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDNService_h__ */
