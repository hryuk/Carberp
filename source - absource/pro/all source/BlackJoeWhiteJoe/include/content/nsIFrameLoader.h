/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIFrameLoader.idl
 */

#ifndef __gen_nsIFrameLoader_h__
#define __gen_nsIFrameLoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIFrameLoader */
#define NS_IFRAMELOADER_IID_STR "d675c531-6bdc-417c-b176-635060105f07"

#define NS_IFRAMELOADER_IID \
  {0xd675c531, 0x6bdc, 0x417c, \
    { 0xb1, 0x76, 0x63, 0x50, 0x60, 0x10, 0x5f, 0x07 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFrameLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMELOADER_IID)

  /**
   * Get the docshell from the frame loader.
   */
  /* readonly attribute nsIDocShell docShell; */
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) = 0;

  /**
   * Start loading the frame. This method figures out what to load
   * from the owner content in the frame loader.
   */
  /* void loadFrame (); */
  NS_SCRIPTABLE NS_IMETHOD LoadFrame(void) = 0;

  /**
   * Loads the specified URI in this frame. Behaves identically to loadFrame,
   * except that this method allows specifying the URI to load.
   */
  /* void loadURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD LoadURI(nsIURI *aURI) = 0;

  /**
   * Destroy the frame loader and everything inside it. This will
   * clear the weak owner content reference.
   */
  /* void destroy (); */
  NS_SCRIPTABLE NS_IMETHOD Destroy(void) = 0;

  /**
   * Find out whether the loader's frame is at too great a depth in
   * the frame tree.  This can be used to decide what operations may
   * or may not be allowed on the loader's docshell.
   */
  /* readonly attribute boolean depthTooGreat; */
  NS_SCRIPTABLE NS_IMETHOD GetDepthTooGreat(PRBool *aDepthTooGreat) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameLoader, NS_IFRAMELOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMELOADER \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell); \
  NS_SCRIPTABLE NS_IMETHOD LoadFrame(void); \
  NS_SCRIPTABLE NS_IMETHOD LoadURI(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD Destroy(void); \
  NS_SCRIPTABLE NS_IMETHOD GetDepthTooGreat(PRBool *aDepthTooGreat); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMELOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return _to GetDocShell(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD LoadFrame(void) { return _to LoadFrame(); } \
  NS_SCRIPTABLE NS_IMETHOD LoadURI(nsIURI *aURI) { return _to LoadURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD Destroy(void) { return _to Destroy(); } \
  NS_SCRIPTABLE NS_IMETHOD GetDepthTooGreat(PRBool *aDepthTooGreat) { return _to GetDepthTooGreat(aDepthTooGreat); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMELOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShell(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD LoadFrame(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadFrame(); } \
  NS_SCRIPTABLE NS_IMETHOD LoadURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD Destroy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_SCRIPTABLE NS_IMETHOD GetDepthTooGreat(PRBool *aDepthTooGreat) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDepthTooGreat(aDepthTooGreat); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameLoader : public nsIFrameLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMELOADER

  nsFrameLoader();

private:
  ~nsFrameLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFrameLoader, nsIFrameLoader)

nsFrameLoader::nsFrameLoader()
{
  /* member initializers and constructor code */
}

nsFrameLoader::~nsFrameLoader()
{
  /* destructor code */
}

/* readonly attribute nsIDocShell docShell; */
NS_IMETHODIMP nsFrameLoader::GetDocShell(nsIDocShell * *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadFrame (); */
NS_IMETHODIMP nsFrameLoader::LoadFrame()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadURI (in nsIURI aURI); */
NS_IMETHODIMP nsFrameLoader::LoadURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroy (); */
NS_IMETHODIMP nsFrameLoader::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean depthTooGreat; */
NS_IMETHODIMP nsFrameLoader::GetDepthTooGreat(PRBool *aDepthTooGreat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFrameLoaderOwner */
#define NS_IFRAMELOADEROWNER_IID_STR "641c2d90-4ada-4367-bdb1-80831614161d"

#define NS_IFRAMELOADEROWNER_IID \
  {0x641c2d90, 0x4ada, 0x4367, \
    { 0xbd, 0xb1, 0x80, 0x83, 0x16, 0x14, 0x16, 0x1d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFrameLoaderOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMELOADEROWNER_IID)

  /**
   * The frame loader owned by this nsIFrameLoaderOwner
   */
  /* readonly attribute nsIFrameLoader frameLoader; */
  NS_SCRIPTABLE NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) = 0;

  /**
   * Swap frame loaders with the given nsIFrameLoaderOwner.  This may
   * only be posible in a very limited range of circumstances, or
   * never, depending on the object implementing this interface.
   *
   * @throws NS_ERROR_NOT_IMPLEMENTED if the swapping logic is not
   *   implemented for the two given frame loader owners.
   * @throws NS_ERROR_DOM_SECURITY_ERR if the swap is not allowed on
   *   security grounds.
   */
  /* void swapFrameLoaders (in nsIFrameLoaderOwner aOtherOwner); */
  NS_SCRIPTABLE NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameLoaderOwner, NS_IFRAMELOADEROWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMELOADEROWNER \
  NS_SCRIPTABLE NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader); \
  NS_SCRIPTABLE NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMELOADEROWNER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) { return _to GetFrameLoader(aFrameLoader); } \
  NS_SCRIPTABLE NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) { return _to SwapFrameLoaders(aOtherOwner); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMELOADEROWNER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameLoader(aFrameLoader); } \
  NS_SCRIPTABLE NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SwapFrameLoaders(aOtherOwner); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameLoaderOwner : public nsIFrameLoaderOwner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMELOADEROWNER

  nsFrameLoaderOwner();

private:
  ~nsFrameLoaderOwner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFrameLoaderOwner, nsIFrameLoaderOwner)

nsFrameLoaderOwner::nsFrameLoaderOwner()
{
  /* member initializers and constructor code */
}

nsFrameLoaderOwner::~nsFrameLoaderOwner()
{
  /* destructor code */
}

/* readonly attribute nsIFrameLoader frameLoader; */
NS_IMETHODIMP nsFrameLoaderOwner::GetFrameLoader(nsIFrameLoader * *aFrameLoader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void swapFrameLoaders (in nsIFrameLoaderOwner aOtherOwner); */
NS_IMETHODIMP nsFrameLoaderOwner::SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFrameLoader_h__ */
