/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/chrome/public/nsIToolkitChromeRegistry.idl
 */

#ifndef __gen_nsIToolkitChromeRegistry_h__
#define __gen_nsIToolkitChromeRegistry_h__


#ifndef __gen_nsIChromeRegistry_h__
#include "nsIChromeRegistry.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIUTF8StringEnumerator; /* forward declaration */


/* starting interface:    nsIToolkitChromeRegistry */
#define NS_ITOOLKITCHROMEREGISTRY_IID_STR "94490b3f-f094-418e-b1b9-73878d29bff3"

#define NS_ITOOLKITCHROMEREGISTRY_IID \
  {0x94490b3f, 0xf094, 0x418e, \
    { 0xb1, 0xb9, 0x73, 0x87, 0x8d, 0x29, 0xbf, 0xf3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIToolkitChromeRegistry : public nsIXULChromeRegistry {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOOLKITCHROMEREGISTRY_IID)

  /**
   * The "canonical" manifest is a plaintext file which sits outside of a
   * JAR file. To provide backwards-compatibility with contents.rdf, we provide
   * this function which reads a contents.rdf manifest and writes it to a file.
   *
   * @param aOldManifestURI  The URI of an old manifest to read, without
   *                         the trailing "contents.rdf", e.g.
   *                         "jar:resource:///chrome/foo.jar!/content/foo/" or
   *                         "file://path/to/contents/rdf/"
   * @param aFile            The URI of a manifest file to write. It's a good
   *                         idea to use a resource: URI if possible.
   * @param aBaseURI         The base URI for relative path creation
   *                         "jar:resource:///chrome/foo.jar!/content/foo/"
   *                         this is a separate param from aOldManifestURI so
   *                         the "contents.rdf" can be read outside of the jar
   *                         to keep the zipreader cache from holding it open.
   * @param aAppend          Whether we should append to an existing manifest
   *                         or truncate and start empty.
   * @param aSkinOnly        Only allow skin packages.
   */
  /* void processContentsManifest (in nsIURI aOldManifestURI, in nsIURI aFile, in nsIURI aBaseURI, in boolean aAppend, in boolean aSkinOnly); */
  NS_SCRIPTABLE NS_IMETHOD ProcessContentsManifest(nsIURI *aOldManifestURI, nsIURI *aFile, nsIURI *aBaseURI, PRBool aAppend, PRBool aSkinOnly) = 0;

  /**
   * If the OS has a "high-visibility" or "disabled-friendly" theme set,
   * we want to force mozilla into the classic theme, which (for the most part
   * obeys the system color/font settings. We cannot do this at initialization,
   * because it depends on the toolkit (GTK2) being initialized, which is
   * not the case in some embedding situations. Embedders have to manually
   * call this method during the startup process.
   */
  /* void checkForOSAccessibility (); */
  NS_SCRIPTABLE NS_IMETHOD CheckForOSAccessibility(void) = 0;

  /**
   * Get a list of locales available for the specified package.
   */
  /* nsIUTF8StringEnumerator getLocalesForPackage (in AUTF8String aPackage); */
  NS_SCRIPTABLE NS_IMETHOD GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIToolkitChromeRegistry, NS_ITOOLKITCHROMEREGISTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOOLKITCHROMEREGISTRY \
  NS_SCRIPTABLE NS_IMETHOD ProcessContentsManifest(nsIURI *aOldManifestURI, nsIURI *aFile, nsIURI *aBaseURI, PRBool aAppend, PRBool aSkinOnly); \
  NS_SCRIPTABLE NS_IMETHOD CheckForOSAccessibility(void); \
  NS_SCRIPTABLE NS_IMETHOD GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOOLKITCHROMEREGISTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD ProcessContentsManifest(nsIURI *aOldManifestURI, nsIURI *aFile, nsIURI *aBaseURI, PRBool aAppend, PRBool aSkinOnly) { return _to ProcessContentsManifest(aOldManifestURI, aFile, aBaseURI, aAppend, aSkinOnly); } \
  NS_SCRIPTABLE NS_IMETHOD CheckForOSAccessibility(void) { return _to CheckForOSAccessibility(); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return _to GetLocalesForPackage(aPackage, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOOLKITCHROMEREGISTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD ProcessContentsManifest(nsIURI *aOldManifestURI, nsIURI *aFile, nsIURI *aBaseURI, PRBool aAppend, PRBool aSkinOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessContentsManifest(aOldManifestURI, aFile, aBaseURI, aAppend, aSkinOnly); } \
  NS_SCRIPTABLE NS_IMETHOD CheckForOSAccessibility(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForOSAccessibility(); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalesForPackage(aPackage, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsToolkitChromeRegistry : public nsIToolkitChromeRegistry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOOLKITCHROMEREGISTRY

  nsToolkitChromeRegistry();

private:
  ~nsToolkitChromeRegistry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsToolkitChromeRegistry, nsIToolkitChromeRegistry)

nsToolkitChromeRegistry::nsToolkitChromeRegistry()
{
  /* member initializers and constructor code */
}

nsToolkitChromeRegistry::~nsToolkitChromeRegistry()
{
  /* destructor code */
}

/* void processContentsManifest (in nsIURI aOldManifestURI, in nsIURI aFile, in nsIURI aBaseURI, in boolean aAppend, in boolean aSkinOnly); */
NS_IMETHODIMP nsToolkitChromeRegistry::ProcessContentsManifest(nsIURI *aOldManifestURI, nsIURI *aFile, nsIURI *aBaseURI, PRBool aAppend, PRBool aSkinOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkForOSAccessibility (); */
NS_IMETHODIMP nsToolkitChromeRegistry::CheckForOSAccessibility()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator getLocalesForPackage (in AUTF8String aPackage); */
NS_IMETHODIMP nsToolkitChromeRegistry::GetLocalesForPackage(const nsACString & aPackage, nsIUTF8StringEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CHROME_MANIFESTS_FILE_LIST "ChromeML"
#define NS_SKIN_MANIFESTS_FILE_LIST "SkinML"

#endif /* __gen_nsIToolkitChromeRegistry_h__ */
