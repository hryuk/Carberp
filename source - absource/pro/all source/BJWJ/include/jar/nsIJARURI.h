/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libjar/nsIJARURI.idl
 */

#ifndef __gen_nsIJARURI_h__
#define __gen_nsIJARURI_h__


#ifndef __gen_nsIURL_h__
#include "nsIURL.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIJARURI */
#define NS_IJARURI_IID_STR "b0922a89-f87b-4cb5-8612-305a285fcca7"

#define NS_IJARURI_IID \
  {0xb0922a89, 0xf87b, 0x4cb5, \
    { 0x86, 0x12, 0x30, 0x5a, 0x28, 0x5f, 0xcc, 0xa7 }}

/**
 * JAR URLs have the following syntax
 *
 * jar:<jar-file-uri>!/<jar-entry>
 *
 * EXAMPLE: jar:http://www.big.com/blue.jar!/ocean.html
 *
 * The nsIURL methods operate on the <jar-entry> part of the spec.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIJARURI : public nsIURL {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJARURI_IID)

  /**
     * Returns the root URI (the one for the actual JAR file) for this JAR
     * (e.g., http://www.big.com/blue.jar).
     */
  /* readonly attribute nsIURI JARFile; */
  NS_SCRIPTABLE NS_IMETHOD GetJARFile(nsIURI * *aJARFile) = 0;

  /**
     * Returns the entry specified for this JAR URI (e.g., "ocean.html").  This
     * value may contain %-escaped byte sequences.
     */
  /* attribute AUTF8String JAREntry; */
  NS_SCRIPTABLE NS_IMETHOD GetJAREntry(nsACString & aJAREntry) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetJAREntry(const nsACString & aJAREntry) = 0;

  /**
     * Create a clone of the JAR URI with a new root URI (the URI for the
     * actual JAR file).
     */
  /* nsIJARURI cloneWithJARFile (in nsIURI jarFile); */
  NS_SCRIPTABLE NS_IMETHOD CloneWithJARFile(nsIURI *jarFile, nsIJARURI **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJARURI, NS_IJARURI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJARURI \
  NS_SCRIPTABLE NS_IMETHOD GetJARFile(nsIURI * *aJARFile); \
  NS_SCRIPTABLE NS_IMETHOD GetJAREntry(nsACString & aJAREntry); \
  NS_SCRIPTABLE NS_IMETHOD SetJAREntry(const nsACString & aJAREntry); \
  NS_SCRIPTABLE NS_IMETHOD CloneWithJARFile(nsIURI *jarFile, nsIJARURI **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJARURI(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetJARFile(nsIURI * *aJARFile) { return _to GetJARFile(aJARFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetJAREntry(nsACString & aJAREntry) { return _to GetJAREntry(aJAREntry); } \
  NS_SCRIPTABLE NS_IMETHOD SetJAREntry(const nsACString & aJAREntry) { return _to SetJAREntry(aJAREntry); } \
  NS_SCRIPTABLE NS_IMETHOD CloneWithJARFile(nsIURI *jarFile, nsIJARURI **_retval NS_OUTPARAM) { return _to CloneWithJARFile(jarFile, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJARURI(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetJARFile(nsIURI * *aJARFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJARFile(aJARFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetJAREntry(nsACString & aJAREntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJAREntry(aJAREntry); } \
  NS_SCRIPTABLE NS_IMETHOD SetJAREntry(const nsACString & aJAREntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetJAREntry(aJAREntry); } \
  NS_SCRIPTABLE NS_IMETHOD CloneWithJARFile(nsIURI *jarFile, nsIJARURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneWithJARFile(jarFile, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJARURI : public nsIJARURI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJARURI

  nsJARURI();

private:
  ~nsJARURI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJARURI, nsIJARURI)

nsJARURI::nsJARURI()
{
  /* member initializers and constructor code */
}

nsJARURI::~nsJARURI()
{
  /* destructor code */
}

/* readonly attribute nsIURI JARFile; */
NS_IMETHODIMP nsJARURI::GetJARFile(nsIURI * *aJARFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String JAREntry; */
NS_IMETHODIMP nsJARURI::GetJAREntry(nsACString & aJAREntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJARURI::SetJAREntry(const nsACString & aJAREntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIJARURI cloneWithJARFile (in nsIURI jarFile); */
NS_IMETHODIMP nsJARURI::CloneWithJARFile(nsIURI *jarFile, nsIJARURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJARURI_h__ */
