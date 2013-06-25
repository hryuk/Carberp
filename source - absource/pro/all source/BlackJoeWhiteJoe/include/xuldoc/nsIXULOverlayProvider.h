/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xul/document/public/nsIXULOverlayProvider.idl
 */

#ifndef __gen_nsIXULOverlayProvider_h__
#define __gen_nsIXULOverlayProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIXULOverlayProvider */
#define NS_IXULOVERLAYPROVIDER_IID_STR "1d5b5b94-dc47-4050-93b7-ac092e383cad"

#define NS_IXULOVERLAYPROVIDER_IID \
  {0x1d5b5b94, 0xdc47, 0x4050, \
    { 0x93, 0xb7, 0xac, 0x09, 0x2e, 0x38, 0x3c, 0xad }}

/**
 * The chrome registry implements this interface to give overlays
 * to the gecko XUL engine.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXULOverlayProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULOVERLAYPROVIDER_IID)

  /**
     * Get the XUL overlays for a particular chrome URI.
     *
     * @param aURI  The URI being loaded
     * @return      An enumerator of nsIURI for the overlays of this URI 
     */
  /* nsISimpleEnumerator getXULOverlays (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetXULOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Get the style overlays for a particular chrome URI.
     *
     * @param aURI  The URI being loaded
     * @return      An enumerator of nsIURI for the overlays of this URI 
     */
  /* nsISimpleEnumerator getStyleOverlays (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetStyleOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULOverlayProvider, NS_IXULOVERLAYPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULOVERLAYPROVIDER \
  NS_SCRIPTABLE NS_IMETHOD GetXULOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStyleOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULOVERLAYPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetXULOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetXULOverlays(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStyleOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetStyleOverlays(aURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULOVERLAYPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetXULOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXULOverlays(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStyleOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleOverlays(aURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULOverlayProvider : public nsIXULOverlayProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULOVERLAYPROVIDER

  nsXULOverlayProvider();

private:
  ~nsXULOverlayProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULOverlayProvider, nsIXULOverlayProvider)

nsXULOverlayProvider::nsXULOverlayProvider()
{
  /* member initializers and constructor code */
}

nsXULOverlayProvider::~nsXULOverlayProvider()
{
  /* destructor code */
}

/* nsISimpleEnumerator getXULOverlays (in nsIURI aURI); */
NS_IMETHODIMP nsXULOverlayProvider::GetXULOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getStyleOverlays (in nsIURI aURI); */
NS_IMETHODIMP nsXULOverlayProvider::GetStyleOverlays(nsIURI *aURI, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULOverlayProvider_h__ */
