/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/unicharutil/idl/nsIUnicodeNormalizer.idl
 */

#ifndef __gen_nsIUnicodeNormalizer_h__
#define __gen_nsIUnicodeNormalizer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_UNICODE_NORMALIZER_CID { 0xa665e49a, 0xf3e6, 0x4fed, { 0x9f, 0x31, 0xf7, 0xc5, 0x68, 0xa2, 0x98, 0x99 } }
#define NS_UNICODE_NORMALIZER_CONTRACTID "@mozilla.org/intl/unicodenormalizer;1"

/* starting interface:    nsIUnicodeNormalizer */
#define NS_IUNICODENORMALIZER_IID_STR "b43a461f-1bcf-4329-820b-66e48c979e14"

#define NS_IUNICODENORMALIZER_IID \
  {0xb43a461f, 0x1bcf, 0x4329, \
    { 0x82, 0x0b, 0x66, 0xe4, 0x8c, 0x97, 0x9e, 0x14 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIUnicodeNormalizer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUNICODENORMALIZER_IID)

  /**
 * Normalize Unicode (NFD, NFC, NFKD, NFKC).
 *
 * NFD: Canonical Decomposition
 * NFC: Canonical Decomposition, followed by Canonical Composition
 * NFKD: Compatibility Decomposition
 * NFKC: Compatibility Decomposition, followed by Canonical Composition
 * Reference: Unicode Standard, TR15, Unicode Normalization Forms
 *
 * @param aSrc         [IN]  nsAString which contains an input UTF-16 string.
 * @param aDest        [OUT] A pointer to an output buffer provided by a callee.
 * @return             NS_OK for success, 
 */
  /* void NormalizeUnicodeNFD (in AString aSrc, out AString aDest); */
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) = 0;

  /* void NormalizeUnicodeNFC (in AString aSrc, out AString aDest); */
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) = 0;

  /* void NormalizeUnicodeNFKD (in AString aSrc, out AString aDest); */
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFKD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) = 0;

  /* void NormalizeUnicodeNFKC (in AString aSrc, out AString aDest); */
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFKC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUnicodeNormalizer, NS_IUNICODENORMALIZER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUNICODENORMALIZER \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFKD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFKC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUNICODENORMALIZER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) { return _to NormalizeUnicodeNFD(aSrc, aDest); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) { return _to NormalizeUnicodeNFC(aSrc, aDest); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFKD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) { return _to NormalizeUnicodeNFKD(aSrc, aDest); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFKC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) { return _to NormalizeUnicodeNFKC(aSrc, aDest); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUNICODENORMALIZER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NormalizeUnicodeNFD(aSrc, aDest); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NormalizeUnicodeNFC(aSrc, aDest); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFKD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NormalizeUnicodeNFKD(aSrc, aDest); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeUnicodeNFKC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NormalizeUnicodeNFKC(aSrc, aDest); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUnicodeNormalizer : public nsIUnicodeNormalizer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUNICODENORMALIZER

  nsUnicodeNormalizer();

private:
  ~nsUnicodeNormalizer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUnicodeNormalizer, nsIUnicodeNormalizer)

nsUnicodeNormalizer::nsUnicodeNormalizer()
{
  /* member initializers and constructor code */
}

nsUnicodeNormalizer::~nsUnicodeNormalizer()
{
  /* destructor code */
}

/* void NormalizeUnicodeNFD (in AString aSrc, out AString aDest); */
NS_IMETHODIMP nsUnicodeNormalizer::NormalizeUnicodeNFD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void NormalizeUnicodeNFC (in AString aSrc, out AString aDest); */
NS_IMETHODIMP nsUnicodeNormalizer::NormalizeUnicodeNFC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void NormalizeUnicodeNFKD (in AString aSrc, out AString aDest); */
NS_IMETHODIMP nsUnicodeNormalizer::NormalizeUnicodeNFKD(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void NormalizeUnicodeNFKC (in AString aSrc, out AString aDest); */
NS_IMETHODIMP nsUnicodeNormalizer::NormalizeUnicodeNFKC(const nsAString & aSrc, nsAString & aDest NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUnicodeNormalizer_h__ */
