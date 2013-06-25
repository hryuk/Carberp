/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libjar/nsIJAR.idl
 */

#ifndef __gen_nsIJAR_h__
#define __gen_nsIJAR_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_JAR_CID                    \
{ /* 04501DB3-0409-11d3-BCF8-00805F0E1353*/  \
    0x04501DB3,                              \
    0x0409,                                  \
    0x11d3,                                  \
    {0xbc, 0xf8, 0x00, 0x80, 0x5f, 0x0e, 0x13, 0x53} \
}
#define NS_JAR_CONTRACTID \
  "@mozilla.org/libjar;1"
#define NS_IJARFactory_IID                    \
{ /* 04501DB4-0409-11d3-BCF8-00805F0E1353 */         \
    0x04501DB4,                                      \
    0x0409,                                          \
    0x11d3,                                          \
    {0xbc, 0xf8, 0x00, 0x80, 0x5f, 0x0e, 0x13, 0x53} \
}
#define NS_JARFactory_CID                 \
{ /* 04501DB5-0409-11d3-BCF8-00805F0E1353 */         \
    0x04501DB5,                                      \
    0x0409,                                          \
    0x11d3,                                          \
    {0xbc, 0xf8, 0x00, 0x80, 0x5f, 0x0e, 0x13, 0x53} \
}
class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIJAR */
#define NS_IJAR_IID_STR "04501db2-0409-11d3-bcf8-00805f0e1353"

#define NS_IJAR_IID \
  {0x04501db2, 0x0409, 0x11d3, \
    { 0xbc, 0xf8, 0x00, 0x80, 0x5f, 0x0e, 0x13, 0x53 }}

class NS_NO_VTABLE nsIJAR : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJAR_IID)

  /**
     * Returns an object describing the entity which signed 
     * an entry. parseManifest must be called first. If aEntryName is an
     * entry in the jar, getInputStream must be called after parseManifest.
     * If aEntryName is an external file which has meta-information 
     * stored in the jar, verifyExternalFile (not yet implemented) must 
     * be called before getPrincipal.
     */
  /* void getCertificatePrincipal (in string aEntryName, out nsIPrincipal aPrincipal); */
  NS_IMETHOD GetCertificatePrincipal(const char *aEntryName, nsIPrincipal **aPrincipal NS_OUTPARAM) = 0;

  /* readonly attribute PRUint32 manifestEntriesCount; */
  NS_IMETHOD GetManifestEntriesCount(PRUint32 *aManifestEntriesCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJAR, NS_IJAR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJAR \
  NS_IMETHOD GetCertificatePrincipal(const char *aEntryName, nsIPrincipal **aPrincipal NS_OUTPARAM); \
  NS_IMETHOD GetManifestEntriesCount(PRUint32 *aManifestEntriesCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJAR(_to) \
  NS_IMETHOD GetCertificatePrincipal(const char *aEntryName, nsIPrincipal **aPrincipal NS_OUTPARAM) { return _to GetCertificatePrincipal(aEntryName, aPrincipal); } \
  NS_IMETHOD GetManifestEntriesCount(PRUint32 *aManifestEntriesCount) { return _to GetManifestEntriesCount(aManifestEntriesCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJAR(_to) \
  NS_IMETHOD GetCertificatePrincipal(const char *aEntryName, nsIPrincipal **aPrincipal NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertificatePrincipal(aEntryName, aPrincipal); } \
  NS_IMETHOD GetManifestEntriesCount(PRUint32 *aManifestEntriesCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestEntriesCount(aManifestEntriesCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJAR : public nsIJAR
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJAR

  nsJAR();

private:
  ~nsJAR();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJAR, nsIJAR)

nsJAR::nsJAR()
{
  /* member initializers and constructor code */
}

nsJAR::~nsJAR()
{
  /* destructor code */
}

/* void getCertificatePrincipal (in string aEntryName, out nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsJAR::GetCertificatePrincipal(const char *aEntryName, nsIPrincipal **aPrincipal NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 manifestEntriesCount; */
NS_IMETHODIMP nsJAR::GetManifestEntriesCount(PRUint32 *aManifestEntriesCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJAR_h__ */
